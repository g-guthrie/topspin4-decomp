#!/usr/bin/env python3
"""Writer for Top Spin 4 (Pam engine) ".arc" archives (inverse of tools/ts4_arc.py).

Rebuilds an archive from an original archive plus replacement members.  The header
(fixed header, FAT, directory index, name pool) is copied verbatim; only the FAT
`offset` and `size` fields of moved or replaced members change.  Members are placed
in the original data order, with the original inter-member gaps and tail preserved,
so a rebuild with no replacements is byte-identical to the input.

Member formats for replaced data (--mode):

  raw         (default) store the new bytes as-is, with no PAM-LZX wrapper.  The game's
              stream-open routine (Swing_DLL fn_88634220) reads the first 8 bytes,
              looks them up as a "PAM-<name>" compressor tag (fn_88626E50) and, if no
              compressor matches, falls back to a plain pass-through stream.  See
              docs/data-patching.md for the evidence and caveats.
  lzx-stored  wrap the bytes in a PAM-LZX blob whose LZX blocks are *uncompressed*
              (block type 3), 1 MiB chunks of 32 KiB frames.  Per-chunk checksums are
              CRC-32 of the chunk's frame bytes (verified against disc members); the
              12-byte digest is NOT understood and is copied from the original member
              when one exists (else zeros).  Experimental fallback.

Usage:
  python3 tools/ts4_arc_write.py ORIG.arc OUT.arc --replace KEY_OR_NAME=FILE [...]
  python3 tools/ts4_arc_write.py Core.arc OUT.arc --iso ISO --replace Settings.bin=my.bin
  python3 tools/ts4_arc_write.py ORIG.arc OUT.arc --verify      # no replacements: identity
Writes OUT.arc only; never modifies the input.  Standard library only.
"""
import argparse
import hashlib
import os
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_arc  # noqa: E402

TAG = ts4_arc.TAG
WINDOW = 1 << 20
FRAME = 0x8000


# ---------------------------------------------------------------- member encoders

def encode_lzx_stored(data, digest=None):
    """Return a PAM-LZX blob for `data` using uncompressed LZX blocks only."""
    total = len(data)
    nchunks = max(1, (total + WINDOW - 1) // WINDOW)
    last_us = total - (nchunks - 1) * WINDOW
    chunks = []
    for ci in range(nchunks):
        piece = data[ci * WINDOW:(ci + 1) * WINDOW]
        us = len(piece)
        out = bytearray()
        # 32-bit prologue: E8 bit (0), block type 3 (3 bits), 24-bit block size, pad to 16
        # bits.  LZX bit words are 16-bit little-endian, MSB-first within the word.
        bits = (3 << 28) | (us << 4)
        prologue = struct.pack("<HH", (bits >> 16) & 0xFFFF, bits & 0xFFFF) + struct.pack("<III", 1, 1, 1)
        pos = 0
        first = True
        while pos < us or first:
            n = min(FRAME, us - pos)
            body = (prologue if first else b"") + piece[pos:pos + n]
            pos += n
            # No pad byte after an odd-length uncompressed block: the game's own encoder does
            # not emit one (a disc member needs the stream to continue at an odd offset).
            if n == FRAME and len(body) <= 0xFFFF:
                out += struct.pack(">H", len(body)) + body
            else:
                out += b"\xff" + struct.pack(">HH", n, len(body)) + body
            first = False
        out += b"\x00" * 5
        chunks.append(bytes(out))
    hdr_len = 36 + 8 * nchunks
    starts = []
    p = hdr_len
    for c in chunks:
        starts.append(p)
        p += len(c)
    blob = bytearray(TAG)
    blob += struct.pack(">4I", nchunks, WINDOW, last_us, total)
    blob += digest if digest and len(digest) == 12 else b"\x00" * 12
    blob += struct.pack(">I", hdr_len)
    if nchunks > 1:
        blob += struct.pack(">%dI" % (nchunks - 1), *starts[1:])
    blob += struct.pack(">%dI" % nchunks, *[zlib.crc32(c) & 0xFFFFFFFF for c in chunks])
    for c in chunks:
        blob += c
    return bytes(blob)


def encode_member(data, mode, orig_blob=None):
    if mode == "raw":
        return bytes(data)
    if mode == "lzx-stored":
        digest = orig_blob[24:36] if orig_blob and orig_blob[:8] == TAG else None
        return encode_lzx_stored(data, digest)
    raise ValueError("unknown mode %r" % mode)


# ---------------------------------------------------------------- key resolution

def resolve_key(arc, spec):
    """Resolve an int key, a hex string ('334e7e0d' / '0x334E7E0D'), a leaf name
    ('Settings.bin') or a full path ('/Media/x.bin') to an entry key of `arc`."""
    keys = {e[0] for e in arc.entries}
    if isinstance(spec, int):
        k = spec
    else:
        s = spec.strip()
        k = None
        try:
            if len(s) <= 10 and (s.lower().startswith("0x") or len(s) == 8):
                k = int(s, 16)
        except ValueError:
            k = None
        if k is None or k not in keys:
            cands = [h for h, (dh, n) in arc.leaf_names.items() if n.lower() == s.lower()]
            if len(cands) > 1:
                raise KeyError("name %r is ambiguous (%s); use a hex key"
                               % (s, ", ".join("%08x" % c for c in cands)))
            if cands:
                k = cands[0]
            elif "/" in s or "\\" in s:
                k = ts4_arc.path_hash(s)
    if k not in keys:
        raise KeyError("no entry for %r" % (spec,))
    return k


# ---------------------------------------------------------------- the writer

def rebuild(arc, replacements, out, mode="raw"):
    """Write a rebuilt archive to binary file object `out`.

    arc: ts4_arc.Arc of the original.  replacements: {key_or_name: bytes} of
    UNCOMPRESSED new member contents.  Returns a dict of statistics.
    """
    repl = {resolve_key(arc, k): bytes(v) for k, v in replacements.items()}
    hdr = bytearray(arc.hdr)
    ents = arc.entries
    groups = {}                                  # (off, size) -> [entry index]
    for i, (h, off, size) in enumerate(ents):
        groups.setdefault((off, size), []).append(i)
    order = sorted(groups)
    prev_end = 0
    for off, size in order:
        if off < prev_end:
            raise ValueError("overlapping members at +0x%X" % off)
        prev_end = off + size
    arc.f.seek(0, 2)
    total_in = arc.f.tell()
    data_len = total_in - arc.data_start

    new_pos = {}                                 # entry index -> (offset, size)
    body = []                                    # byte chunks after the header
    cursor_old = 0                               # position in the original data area
    cursor_new = 0
    for (off, size) in order:
        gap = off - cursor_old
        if gap:
            arc.f.seek(arc.data_start + cursor_old)
            body.append(arc.f.read(gap))
            cursor_new += gap
        idxs = groups[(off, size)]
        rk = [ents[i][0] for i in idxs if ents[i][0] in repl]
        if rk:
            if len({repl[k] for k in rk}) > 1:
                raise ValueError("entries sharing storage were given different data")
            blob = encode_member(repl[rk[0]], mode, arc.raw(ents[idxs[0]]))
        else:
            blob = arc.raw(ents[idxs[0]])
        for i in idxs:
            new_pos[i] = (cursor_new, len(blob))
        body.append(blob)
        cursor_new += len(blob)
        cursor_old = off + size
    if cursor_old < data_len:                    # tail bytes after the last member
        arc.f.seek(arc.data_start + cursor_old)
        body.append(arc.f.read(data_len - cursor_old))

    for i in range(len(ents)):
        o, s = new_pos[i]
        struct.pack_into(">II", hdr, arc.table_start + 12 * i + 4, o, s)
    out.write(bytes(hdr))
    for b in body:
        out.write(b)
    return dict(entries=len(ents), replaced=sorted(repl), mode=mode,
                in_size=total_in, out_size=len(hdr) + sum(len(b) for b in body))


def verify(orig, new, replacements=None):
    """Compare two Arc objects: same keys and header; every member decodes to the same
    bytes except `replacements` ({key: bytes}), which must read back as given.
    Returns the number of members checked."""
    repl = {resolve_key(orig, k): v for k, v in (replacements or {}).items()}
    if [e[0] for e in orig.entries] != [e[0] for e in new.entries]:
        raise AssertionError("entry key tables differ")
    if orig.hdr[:0x24] != new.hdr[:0x24] or len(orig.hdr) != len(new.hdr):
        raise AssertionError("header changed")
    for eo, en in zip(orig.entries, new.entries):
        got = new.read(en)
        want = repl[eo[0]] if eo[0] in repl else orig.read(eo)
        if got != want:
            raise AssertionError("member %08x differs after rebuild" % eo[0])
    return len(orig.entries)


def sha(b):
    return hashlib.sha256(b).hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("arc", help="original archive (path inside the ISO when --iso is given)")
    ap.add_argument("out", help="output archive path (write under work/)")
    ap.add_argument("--iso", help="read the original archive from this disc image")
    ap.add_argument("--replace", action="append", default=[], metavar="KEY=FILE",
                    help="replace member KEY (hex key, leaf name or path) with the contents of FILE")
    ap.add_argument("--mode", choices=("raw", "lzx-stored"), default="raw")
    ap.add_argument("--verify", action="store_true", help="re-read the output and compare every member")
    a = ap.parse_args()
    if os.path.abspath(a.out) == os.path.abspath(a.arc):
        ap.error("refusing to overwrite the input")
    arc = ts4_arc.open_arc(a.arc, a.iso)
    repl = {}
    for spec in a.replace:
        k, _, fn = spec.partition("=")
        with open(fn, "rb") as f:
            repl[k] = f.read()
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "wb") as o:
        st = rebuild(arc, repl, o, a.mode)
    print("wrote %s: %d bytes (input %d), %d entries, replaced %s"
          % (a.out, st["out_size"], st["in_size"], st["entries"], [hex(k) for k in st["replaced"]]))
    with open(a.out, "rb") as f:
        print("sha256", sha(f.read()))
    if a.verify:
        new = ts4_arc.Arc(a.out)
        n = verify(arc, new, {k: v for k, v in repl.items()})
        print("verified %d members" % n)


if __name__ == "__main__":
    main()
