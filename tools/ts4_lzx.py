#!/usr/bin/env python3
"""Pure-Python LZX decompressor (Microsoft LZX as used by CAB and XMemCompress).

Own implementation written from the public LZX description; standard library only.
Provides a stateful frame decoder: each 32 KiB output frame is fed its own
byte-aligned compressed bytes while Huffman/window/repeat-offset state carries over.
Supports verbatim, aligned-offset and uncompressed blocks, windows 2^15..2^21 and
the E8 (x86 call) translation.
"""
import struct

FRAME = 32768


class LZXError(Exception):
    pass


def position_slots(window_bits):
    return {20: 42, 21: 50}.get(window_bits, window_bits * 2)


def slot_tables(slots):
    extra, base, pos = [], [], 0
    for i in range(slots):
        e = 0 if i < 4 else (17 if i >= 36 else (i - 2) // 2)
        extra.append(e)
        base.append(pos)
        pos += 1 << e
    return extra, base


class _Bits:
    def __init__(self, data):
        self.d, self.p, self.buf, self.n = data, 0, 0, 0

    def fill(self, need):
        while self.n < need:
            d, p = self.d, self.p
            w = (d[p] | (d[p + 1] << 8)) if p + 1 < len(d) else 0
            self.p += 2
            self.buf = (self.buf << 16) | w
            self.n += 16

    def read(self, k):
        if k == 0:
            return 0
        self.fill(k)
        self.n -= k
        v = (self.buf >> self.n) & ((1 << k) - 1)
        self.buf &= (1 << self.n) - 1
        return v

    def align16(self):
        self.n -= self.n % 16
        self.p -= (self.n // 16) * 2
        self.n = 0
        self.buf = 0


class _Huff:
    """Canonical Huffman decoder (codes assigned by increasing length then symbol).

    A primary lookup table covers codes up to PRIMARY bits; longer codes fall back
    to a dictionary search.
    """

    PRIMARY = 10

    def __init__(self, lengths, maxbits=16):
        self.table = {}
        code = 0
        self.maxlen = 0
        for L in range(1, maxbits + 1):
            for sym, l in enumerate(lengths):
                if l == L:
                    self.table[(L, code)] = sym
                    code += 1
                    self.maxlen = L
            code <<= 1
        self.k = min(self.maxlen, self.PRIMARY)
        k = self.k
        self.fast = [0] * (1 << k) if k else []
        for (L, code), sym in self.table.items():
            if L <= k:
                lo = code << (k - L)
                hi = lo + (1 << (k - L))
                self.fast[lo:hi] = [(sym << 5) | L] * (hi - lo)

    def decode(self, br):
        if not self.table:
            raise LZXError("empty huffman tree")
        k = self.k
        br.fill(self.maxlen)
        n, buf = br.n, br.buf
        v = self.fast[(buf >> (n - k)) & ((1 << k) - 1)]
        if v:
            L = v & 31
            br.n = n - L
            br.buf = buf & ((1 << br.n) - 1)
            return v >> 5
        code = 0
        for L in range(1, self.maxlen + 1):
            code = (code << 1) | ((buf >> (n - L)) & 1)
            s = self.table.get((L, code))
            if s is not None:
                br.n = n - L
                br.buf = buf & ((1 << br.n) - 1)
                return s
        raise LZXError("bad huffman code")


def _read_lengths(br, lengths, first, last):
    pre = _Huff([br.read(4) for _ in range(20)])
    i = first
    while i < last:
        z = pre.decode(br)
        if z == 17:
            run, v = br.read(4) + 4, 0
        elif z == 18:
            run, v = br.read(5) + 20, 0
        elif z == 19:
            run = br.read(1) + 4
            v = (lengths[i] - pre.decode(br)) % 17
        else:
            run, v = 1, (lengths[i] - z) % 17
        for _ in range(run):
            lengths[i] = v
            i += 1


class LZXDecoder:
    def __init__(self, window_bits):
        self.wbits = window_bits
        self.wsize = 1 << window_bits
        self.win = bytearray(self.wsize)
        self.wpos = 0
        self.slots = position_slots(window_bits)
        self.extra, self.base = slot_tables(self.slots)
        self.main_n = 256 + self.slots * 8
        self.main_len = [0] * self.main_n
        self.len_len = [0] * 249
        self.R = [1, 1, 1]
        self.block_type = 0
        self.block_left = 0
        self.header_done = False
        self.e8_size = 0
        self.frame_no = 0
        self.main_h = self.len_h = self.aligned_h = None

    def decode_frame(self, data, out_len, partial=False):
        """Decode one frame of out_len (<=32768) bytes from byte-aligned data.

        partial=True stops as soon as out_len bytes exist (a match may overshoot and is
        truncated); the decoder state is then unusable for further frames.
        """
        br = _Bits(data)
        if not self.header_done:
            self.header_done = True
            if br.read(1):
                self.e8_size = (br.read(16) << 16) | br.read(16)
        out = bytearray()
        win, wmask = self.win, self.wsize - 1
        wpos = self.wpos
        R = self.R
        extra, base = self.extra, self.base
        while len(out) < out_len:
            if self.block_left == 0:
                self.block_type = br.read(3)
                self.block_left = (br.read(8) << 16) | br.read(16)
                bt = self.block_type
                if bt in (1, 2):
                    if bt == 2:
                        self.aligned_h = _Huff([br.read(3) for _ in range(8)], 7)
                    _read_lengths(br, self.main_len, 0, 256)
                    _read_lengths(br, self.main_len, 256, self.main_n)
                    _read_lengths(br, self.len_len, 0, 249)
                    self.main_h = _Huff(self.main_len)
                    self.len_h = _Huff(self.len_len)
                elif bt == 3:
                    br.align16()
                    R[0], R[1], R[2] = struct.unpack_from("<III", data, br.p)
                    br.p += 12
                else:
                    raise LZXError("bad block type %d" % bt)
            todo = min(self.block_left, out_len - len(out))
            if self.block_type == 3:
                chunk = data[br.p:br.p + todo]
                br.p += todo
                for b in chunk:
                    win[wpos] = b
                    wpos = (wpos + 1) & wmask
                out += chunk
                self.block_left -= todo
                if self.block_left == 0 and (br.p & 1):
                    br.p += 1
                continue
            produced = 0
            main_h, len_h, aligned = self.main_h, self.len_h, self.aligned_h
            aligned_blk = self.block_type == 2
            while produced < todo:
                s = main_h.decode(br)
                if s < 256:
                    win[wpos] = s
                    wpos = (wpos + 1) & wmask
                    out.append(s)
                    produced += 1
                    continue
                s -= 256
                mlen = s & 7
                slot = s >> 3
                if mlen == 7:
                    mlen += len_h.decode(br)
                mlen += 2
                if slot == 0:
                    off = R[0]
                elif slot == 1:
                    off = R[1]
                    R[1] = R[0]
                    R[0] = off
                elif slot == 2:
                    off = R[2]
                    R[2] = R[0]
                    R[0] = off
                else:
                    e = extra[slot]
                    if aligned_blk and e >= 3:
                        verb = br.read(e - 3) if e > 3 else 0
                        fo = (verb << 3) | aligned.decode(br)
                    else:
                        fo = br.read(e)
                    off = base[slot] + fo - 2
                    R[2] = R[1]
                    R[1] = R[0]
                    R[0] = off
                src = (wpos - off) & wmask
                if src + mlen <= self.wsize and wpos + mlen <= self.wsize and off >= mlen:
                    seg = win[src:src + mlen]
                    win[wpos:wpos + mlen] = seg
                    out += seg
                    wpos = (wpos + mlen) & wmask
                else:
                    for _ in range(mlen):
                        b = win[(wpos - off) & wmask]
                        win[wpos] = b
                        wpos = (wpos + 1) & wmask
                        out.append(b)
                produced += mlen
            self.block_left -= produced
            if self.block_left < 0 and not partial:
                raise LZXError("match overran block")
        self.wpos = wpos
        if partial:
            return bytes(out[:out_len])
        if len(out) != out_len:
            raise LZXError("frame overrun: %d != %d" % (len(out), out_len))
        if self.e8_size:
            _e8(out, self.frame_no * FRAME, self.e8_size)
        self.frame_no += 1
        return bytes(out)


def _e8(buf, cur0, filesize):
    n = len(buf) - 10
    i = 0
    while i < n:
        if buf[i] == 0xE8:
            cur = cur0 + i
            absv = struct.unpack_from("<i", buf, i + 1)[0]
            if -cur <= absv < filesize:
                rel = absv - cur if absv >= 0 else absv + filesize
                struct.pack_into("<i", buf, i + 1, rel)
            i += 5
        else:
            i += 1
