#!/usr/bin/env python3
"""Apply an Xbox 360 XEX2 delta patch (``.xexp`` from a title update) to its base XEX, and diff the images.

Pure Python plus the ``cryptography`` package for AES (already used elsewhere in this checkout).
No key is stored in this repository: the retail XEX key is read at run time from a local file
(``--key-file``: 16 raw bytes or 32 hex digits) or, by default, from the RETAIL_KEY table of the
local jeff checkout (``work/jeff/src/util/xex.rs``, see docs/START_HERE.md).

Format, as recovered against Top Spin 4 Title Update #1 (every step is verified by the SHA-1 block
hashes the files carry, so a wrong key or layout fails loudly):

* base image: XEX2 basefile format 0x3FF, encryption 1 (AES-128-CBC, IV 0, session key =
  AES-ECB-decrypt(retail key, security info +0x150)), compression 2 (LZX blocks: u32 next block
  size, 20-byte SHA-1 of the next block, then u16-length-prefixed LZX chunks, 32 KiB frames).
* patch: optional header 0x5FF (delta patch descriptor):
    +0x00 u32 size, +0x04 target version, +0x08 source version, +0x0C digest_source[20],
    +0x20 image_key_source[16], +0x30 size_of_target_headers, +0x34 delta_headers_source_offset,
    +0x38 delta_headers_source_size, +0x3C delta_headers_target_offset, +0x40
    delta_image_source_offset, +0x44 delta_image_source_size, +0x48 delta_image_target_offset,
    +0x4C first delta record (the header patch).
  Delta record: u32 old_addr, u32 new_addr, u16 uncompressed_len, u16 compressed_len, data.
  compressed_len 0: zero-fill new; 1: copy old -> new; otherwise LZX with the window pre-loaded
  with ``uncompressed_len`` bytes of the current image at old_addr (data at +12).
  The header patch, applied to the base XEX header, gives the target header; its security info
  key, decrypted with the retail key, is the target session key.  The patch's own image data is
  encrypted with AES-ECB-decrypt(target session key, patch security info +0x150) and is a chain of
  blocks (basefile compression 3): u32 next block size, 20-byte SHA-1, then delta records up to the
  end of the block, applied in place over a copy of the base image.

Usage:
  python3 tools/xex_patch.py BASE.xex PATCH.xexp --out work/patched/Swing_DLL.tu1.image  [--base-out F]
  python3 tools/xex_patch.py BASE.xex PATCH.xexp --diff [--sections] [--json OUT]
The images written are the loaded memory image (load address = image base); keep them under work/.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_lzx  # noqa: E402

DEFAULT_KEY_SRC = "work/jeff/src/util/xex.rs"


def load_retail_key(path):
    data = open(path, "rb").read()
    if len(data) == 16:
        return data
    txt = data.decode("latin-1")
    m = re.search(r"RETAIL_KEY\s*:\s*\[u8;\s*16\]\s*=\s*\[(.*?)\]", txt, re.S)
    if m:
        return bytes(int(x, 16) for x in re.findall(r"0x[0-9A-Fa-f]{1,2}", m.group(1)))
    hexd = re.sub(r"[^0-9A-Fa-f]", "", txt)
    if len(hexd) == 32:
        return bytes.fromhex(hexd)
    raise SystemExit("no 16-byte key found in %s" % path)


def _aes(key, data, cbc):
    try:
        from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
    except ImportError:  # pragma: no cover
        raise SystemExit("the 'cryptography' package is needed for AES")
    c = Cipher(algorithms.AES(key), modes.CBC(b"\0" * 16) if cbc else modes.ECB()).decryptor()
    return c.update(data) + c.finalize()


def aes_cbc_dec(key, data):
    return _aes(key, data[:len(data) & ~15], True) + data[len(data) & ~15:]


def aes_ecb_dec(key, block16):
    return _aes(key, block16, False)


class Xex:
    def __init__(self, buf):
        if buf[:4] != b"XEX2":
            raise ValueError("not an XEX2 file")
        self.buf = buf
        self.flags, self.data_off, _r, self.sec, n = struct.unpack_from(">IIIII", buf, 4)
        self.opt = {}
        for i in range(n):
            k, v = struct.unpack_from(">II", buf, 0x18 + 8 * i)
            self.opt[k] = v
        self.image_size = struct.unpack_from(">I", buf, self.sec + 4)[0]
        self.load_address = struct.unpack_from(">I", buf, self.sec + 0x110)[0]
        self.file_key = buf[self.sec + 0x150:self.sec + 0x160]

    def header(self, key):
        v = self.opt[key]
        if key & 0xFF == 0xFF:
            n = struct.unpack_from(">I", self.buf, v)[0]
            return self.buf[v:v + n]
        if key & 0xFF < 2:
            return struct.pack(">I", v)
        return self.buf[v:v + (key & 0xFF) * 4]

    def file_format(self):
        f = self.header(0x3FF)
        _size, enc, comp = struct.unpack_from(">IHH", f, 0)
        return enc, comp, f


def lzx_stream(data, out_len, window_bits=15, ref=None):
    """Decode one LZX stream of out_len bytes (32 KiB frames, 16-bit re-alignment per frame)."""
    d = ts4_lzx.LZXDecoder(window_bits)
    if ref:
        if len(ref) > d.wsize:
            ref = ref[-d.wsize:]
        d.win[d.wsize - len(ref):] = ref
    out, pos = [], 0
    while out_len > 0:
        n = min(ts4_lzx.FRAME, out_len)
        out.append(d.decode_frame(data[pos:], n))
        pos += d.consumed
        out_len -= n
    return b"".join(out)


def window_bits(window_size):
    return max(15, (window_size - 1).bit_length())


def base_image(x, retail_key):
    enc, comp, ff = x.file_format()
    session = aes_ecb_dec(retail_key, x.file_key)
    data = x.buf[x.data_off:]
    if enc == 1:
        data = aes_cbc_dec(session, data)
    if comp == 1:                      # raw: {data_size, zero_size} pairs
        out = bytearray()
        pos = 0
        for i in range((len(ff) - 8) // 8):
            ds, zs = struct.unpack_from(">II", ff, 8 + 8 * i)
            out += data[pos:pos + ds] + b"\0" * zs
            pos += ds
        return bytes(out), session
    if comp != 2:
        raise ValueError("base compression %d not supported" % comp)
    wsize, bsize = struct.unpack_from(">II", ff, 8)
    bhash = ff[16:36]
    dec = ts4_lzx.LZXDecoder(window_bits(wsize))
    out = bytearray()
    pos = 0
    while bsize:
        blk = data[pos:pos + bsize]
        if hashlib.sha1(blk).digest() != bhash:
            raise ValueError("base block hash mismatch at 0x%x (wrong key?)" % pos)
        nsize, nhash = struct.unpack_from(">I", blk, 0)[0], blk[4:24]
        o = 24
        while o + 2 <= len(blk):
            cl = struct.unpack_from(">H", blk, o)[0]
            o += 2
            if cl == 0:
                break
            n = min(wsize, x.image_size - len(out))
            out += dec.decode_frame(blk[o:o + cl], n)
            o += cl
        pos += bsize
        bsize, bhash = nsize, nhash
    if len(out) < x.image_size:
        out += b"\0" * (x.image_size - len(out))
    return bytes(out), session


def apply_records(buf, img, pos, end, wbits, log=None):
    """Apply delta records from buf[pos:end] in place to bytearray img; returns records applied."""
    n = 0
    while pos + 12 <= end:
        old, new, ul, cl = struct.unpack_from(">IIHH", buf, pos)
        if old == new == ul == cl == 0:
            break
        if new + ul > len(img):
            img.extend(b"\0" * (new + ul - len(img)))
        if cl == 0:
            img[new:new + ul] = b"\0" * ul
            adv = 12
        elif cl == 1:
            img[new:new + ul] = bytes(img[old:old + ul])
            adv = 12
        else:
            img[new:new + ul] = lzx_stream(buf[pos + 12:pos + 12 + cl], ul, wbits, bytes(img[old:old + ul]))
            adv = 12 + cl
        if log is not None:
            log.append((old, new, ul, cl))
        pos += adv
        n += 1
    return n


def apply_patch(base_buf, patch_buf, retail_key):
    base, patch = Xex(base_buf), Xex(patch_buf)
    if 0x5FF not in patch.opt:
        raise ValueError("patch has no delta patch descriptor (0x5FF)")
    desc = patch.header(0x5FF)
    tgt_hdr_size, hs_off, hs_size, ht_off, is_off, is_size, it_off = struct.unpack_from(">7I", desc, 0x30)
    _p_enc, p_comp, pff = patch.file_format()
    wsize = struct.unpack_from(">I", pff, 8)[0]
    wbits = window_bits(wsize)
    # 1. target header = base header + header delta
    hdr = bytearray(base_buf[hs_off:hs_off + hs_size]) + bytearray(max(0, tgt_hdr_size - hs_size))
    apply_records(desc, hdr, 0x4C, len(desc), wbits)
    target = Xex(bytes(hdr))
    target_session = aes_ecb_dec(retail_key, target.file_key)
    patch_session = aes_ecb_dec(target_session, patch.file_key)
    # 2. image
    img_base, base_session = base_image(base, retail_key)
    img = bytearray(img_base[is_off:is_off + is_size])
    if len(img) < target.image_size:
        img += b"\0" * (target.image_size - len(img))
    data = aes_cbc_dec(patch_session, patch_buf[patch.data_off:])
    if p_comp != 3:
        raise ValueError("patch compression %d is not delta (3)" % p_comp)
    bsize, bhash = struct.unpack_from(">I", pff, 12)[0], pff[16:36]
    pos, log, blocks = 0, [], 0
    while bsize:
        blk = data[pos:pos + bsize]
        if hashlib.sha1(blk).digest() != bhash:
            raise ValueError("patch block hash mismatch at 0x%x" % pos)
        nsize, nhash = struct.unpack_from(">I", blk, 0)[0], blk[4:24]
        apply_records(blk, img, 24, len(blk), wbits, log)
        pos += bsize
        bsize, bhash = nsize, nhash
        blocks += 1
    del img[target.image_size:]
    info = dict(blocks=blocks, records=len(log),
                target_image_size=target.image_size, load_address=target.load_address,
                source_version="0x%08x" % struct.unpack_from(">I", desc, 8)[0],
                target_version="0x%08x" % struct.unpack_from(">I", desc, 4)[0])
    return img_base, bytes(img), bytes(hdr), info, log


def pe_sections(img):
    """Sections of a PE image in memory layout: [(name, rva, vsize)]."""
    if img[:2] != b"MZ":
        return []
    e = struct.unpack_from("<I", img, 0x3C)[0]
    ns = struct.unpack_from("<H", img, e + 6)[0]
    osz = struct.unpack_from("<H", img, e + 20)[0]
    out = []
    for i in range(ns):
        o = e + 24 + osz + 40 * i
        name = img[o:o + 8].rstrip(b"\0").decode("latin-1")
        vs, va = struct.unpack_from("<II", img, o + 8)
        out.append((name, va, vs))
    return out


def diff_ranges(a, b, gap=16):
    """Changed byte ranges [(start, end)] between two equal-length images (merged across small gaps)."""
    out = []
    n = min(len(a), len(b))
    step = 4096
    i = 0
    while i < n:
        j = min(n, i + step)
        if a[i:j] != b[i:j]:
            k = i
            while k < j:
                if a[k] != b[k]:
                    s = k
                    while k < j and (a[k] != b[k] or (k + gap < j and a[k:k + gap] != b[k:k + gap])):
                        k += 1
                    if out and s - out[-1][1] <= gap:
                        out[-1] = (out[-1][0], k)
                    else:
                        out.append((s, k))
                k += 1
        i = j
    if len(a) != len(b):
        out.append((n, max(len(a), len(b))))
    return out


# ------------------------------------------------------------------------------- function-level diff

def pdata_functions(img, load_address):
    """[(address, byte size)] from the PE .pdata table (PowerPC: u32 begin, u32 flags; length in words)."""
    for name, va, vs in pe_sections(img):
        if name == ".pdata":
            out = []
            for k in range(vs // 8):
                b, f = struct.unpack_from(">II", img, va + 8 * k)
                if b:
                    out.append((b, ((f >> 8) & 0x3FFFFF) * 4))
            return out
    return []


def normalize_function(img, load_address, addr, size):
    """Instruction words with link-time-variable fields masked: b/bl displacement, lis immediates and
    the low halves that use a lis-loaded base, and words that are absolute image addresses (jump
    tables).  Two builds of an unchanged function normalize to the same words."""
    o = addr - load_address
    ws = struct.unpack_from(">%dI" % (size // 4), img, o)
    lo, hi_lim = load_address, load_address + len(img)
    hi, res = set(), []
    for w in ws:
        op, rd, ra = w >> 26, (w >> 21) & 31, (w >> 16) & 31
        m = w
        if lo <= w < hi_lim:
            m = 0xFFFFFFFF
        elif op == 18:
            m = w & 0xFC000003
        elif op == 15 and ra == 0:
            m = w & 0xFFFF0000
            hi.add(rd)
        elif ra and ra in hi and (op == 14 or 32 <= op <= 55 or op in (58, 62)):
            m = w & 0xFFFF0000
            if op == 14 and rd != ra:
                hi.discard(rd)
            elif op in (32, 33, 34, 35, 40, 41, 42, 43, 46, 58):
                hi.discard(rd)
        elif op in (31, 21, 24, 25, 28, 29, 7, 8, 10, 11, 12, 13, 14) and rd in hi:
            hi.discard(rd)
        res.append(m)
    return res


def load_function_names(paths):
    names = {}
    for p in paths:
        if not p or not os.path.exists(p):
            continue
        for ln in open(p, encoding="utf-8", errors="replace"):
            m = re.match(r"\s*(\S+)\s*=\s*\.text:0x([0-9A-Fa-f]{8});.*type:function", ln)
            if m:
                if not m.group(1).startswith("fn_"):
                    names.setdefault(int(m.group(2), 16), m.group(1))
                continue
            f = ln.rstrip("\n").split(",")
            if len(f) >= 3 and re.fullmatch(r"[0-9A-Fa-f]{8}", f[1]):
                names[int(f[1], 16)] = f[2]
    return names


def classify_pair(a, b):
    """'offsets' when only 16-bit immediates differ (same opcode and registers), else 'code'."""
    if len(a) != len(b):
        return "code"
    for x, y in zip(a, b):
        if x != y and (x ^ y) & 0xFFFF0000:
            return "code"
    return "offsets"


def function_diff(base_img, img, load_address, names=None):
    import difflib
    names = names or {}
    fa, fb = pdata_functions(base_img, load_address), pdata_functions(img, load_address)
    na = [normalize_function(base_img, load_address, x, s) for x, s in fa]
    nb = [normalize_function(img, load_address, x, s) for x, s in fb]
    ka = [hashlib.sha1(struct.pack(">%dI" % len(n), *n)).digest() for n in na]
    kb = [hashlib.sha1(struct.pack(">%dI" % len(n), *n)).digest() for n in nb]
    sm = difflib.SequenceMatcher(None, ka, kb, autojunk=False)
    out = dict(base_functions=len(fa), patched_functions=len(fb), identical=0, offsets_only=[], changed=[],
               added=[], removed=[])
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            out["identical"] += i2 - i1
            continue
        ia, ib = list(range(i1, i2)), list(range(j1, j2))
        # pair the group's functions in order while sizes allow, the rest are added/removed
        while ia and ib:
            i, j = ia[0], ib[0]
            if fa[i][1] == fb[j][1] or len(ia) == len(ib):
                kind = classify_pair(na[i], nb[j])
                ndiff = sum(1 for x, y in zip(na[i], nb[j]) if x != y) + abs(len(na[i]) - len(nb[j]))
                row = dict(base="0x%08X" % fa[i][0], tu="0x%08X" % fb[j][0], base_size=fa[i][1],
                           tu_size=fb[j][1], words_differing=ndiff)
                if fa[i][0] in names:
                    row["name"] = names[fa[i][0]]
                out["offsets_only" if kind == "offsets" else "changed"].append(row)
                ia.pop(0)
                ib.pop(0)
            elif len(ia) > len(ib):
                i = ia.pop(0)
                out["removed"].append(dict(base="0x%08X" % fa[i][0], base_size=fa[i][1],
                                           **({"name": names[fa[i][0]]} if fa[i][0] in names else {})))
            else:
                j = ib.pop(0)
                out["added"].append(dict(tu="0x%08X" % fb[j][0], tu_size=fb[j][1]))
        for i in ia:
            out["removed"].append(dict(base="0x%08X" % fa[i][0], base_size=fa[i][1],
                                       **({"name": names[fa[i][0]]} if fa[i][0] in names else {})))
        for j in ib:
            out["added"].append(dict(tu="0x%08X" % fb[j][0], tu_size=fb[j][1]))
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("base")
    ap.add_argument("patch")
    ap.add_argument("--key-file", default=DEFAULT_KEY_SRC,
                    help="local file holding the retail XEX key (never committed); default: jeff's xex.rs")
    ap.add_argument("--out", help="write the patched memory image here (keep under work/)")
    ap.add_argument("--base-out", help="write the unpatched memory image here (keep under work/)")
    ap.add_argument("--header-out", help="write the patched XEX header here")
    ap.add_argument("--diff", action="store_true", help="print changed address ranges")
    ap.add_argument("--json", help="write a JSON summary (hashes, ranges) here")
    ap.add_argument("--functions", metavar="OUT", help="write a function-level diff (.pdata, normalized) as JSON")
    ap.add_argument("--names", nargs="*", default=["config/54540859/symbols.txt", "config/symbols.csv",
                    "docs/gameplay/swing-symbols.csv", "docs/gameplay/movement-symbols.csv",
                    "docs/gameplay/rules-symbols.csv"], help="symbol files used to name base functions")
    a = ap.parse_args(argv)
    key = load_retail_key(a.key_file)
    bb, pb = open(a.base, "rb").read(), open(a.patch, "rb").read()
    base_img, img, hdr, info, log = apply_patch(bb, pb, key)
    for path, data in ((a.out, img), (a.base_out, base_img), (a.header_out, hdr)):
        if path:
            os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
            open(path, "wb").write(data)
    info.update(base_sha256=hashlib.sha256(bb).hexdigest(), patch_sha256=hashlib.sha256(pb).hexdigest(),
                base_image_sha256=hashlib.sha256(base_img).hexdigest(),
                patched_image_sha256=hashlib.sha256(img).hexdigest(),
                patched_header_sha256=hashlib.sha256(hdr).hexdigest())
    print(json.dumps(info, indent=1))
    if a.diff or a.json:
        ranges = diff_ranges(base_img, img)
        secs = pe_sections(img)
        la = info["load_address"]
        rows = []
        for s, e in ranges:
            sec = next((n for n, va, vs in secs if va <= s < va + vs), "?")
            rows.append(dict(start="0x%08X" % (la + s), end="0x%08X" % (la + e), bytes=e - s, section=sec))
        if a.diff:
            for r in rows:
                print("%s-%s %7d %s" % (r["start"], r["end"], r["bytes"], r["section"]))
            print("%d ranges, %d bytes changed" % (len(rows), sum(r["bytes"] for r in rows)))
        if a.json:
            json.dump(dict(info, ranges=rows), open(a.json, "w"), indent=1)
    if a.functions:
        fd = function_diff(base_img, img, info["load_address"], load_function_names(a.names))
        fd.update({k: info[k] for k in ("base_sha256", "patch_sha256", "base_image_sha256", "patched_image_sha256")})
        json.dump(fd, open(a.functions, "w"), indent=1)
        print("functions: %d base, %d patched, %d identical, %d offset-only, %d changed, %d added, %d removed" % (
            fd["base_functions"], fd["patched_functions"], fd["identical"], len(fd["offsets_only"]),
            len(fd["changed"]), len(fd["added"]), len(fd["removed"])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
