#!/usr/bin/env python3
"""Reader for Top Spin 4 (Pam engine) ".arc" archives.

Container layout (all integers big-endian), decoded from the retail disc:

  0x00 u32 hdr_size_minus4   data area starts at hdr_size_minus4 + 4
  0x04 u32 table_off_minus4  entry table starts at this + 4 (always 0x24)
  0x08 u32 count             number of entries
  0x0C u32 count2            repeat of count
  0x10 u32 aux_off           (offset of the secondary name index, minus 0x10)
  0x14 u32 nnames, 0x18 u32 nnames2   number of named entries
  0x1C 8B  b"PAM-LZX\\0"      compression tag (the loader's marker is "PAM-ZLB" in the title strings
                           but the stored members are LZX; the tag is not checked on disc)
  0x24 count * (u32 hash, u32 offset, u32 size)   sorted by hash ascending;
       offset is relative to the data area, size is the stored size.
  ...  secondary name index and a NUL-separated string pool (header tail)

Each stored entry is either raw bytes or a PAM-LZX blob:

  8B  "PAM-LZX\\0", u32 nchunks, u32 window (= chunk size, 1 MiB), u32 last_chunk_usize,
      u32 total_usize
  12B opaque (digest of the data)
  u32 hdr_len                 offset of the first frame from blob start (24+12+4+8*nchunks-... )
  (nchunks-1) u32 start offsets of chunks 2..n, measured from the blob start
  nchunks u32 per-chunk checksums
  each chunk is an independent LZX stream (state reset), 1 MiB of output (last: remainder)
  made of frames: 0xFF,u16 usize,u16 csize (5-byte header, short last frame) or u16 csize
  (usize = 0x8000), followed by csize bytes of LZX data (see tools/ts4_lzx.py)
"""
import argparse
import json
import os
import re
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_lzx  # noqa: E402

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

TAG = b"PAM-LZX\x00"


def parse_header(buf):
    """Parse the fixed header and entry table from the first bytes of an archive."""
    (size_m4, tab_m4, count, count2, aux, nnames, nnames2) = struct.unpack_from(">7I", buf, 0)
    if buf[0x1C:0x24] != TAG:
        raise ValueError("not a PAM archive (tag missing)")
    if count != count2:
        raise ValueError("entry count mismatch")
    entries = [struct.unpack_from(">3I", buf, tab_m4 + 4 + 12 * i) for i in range(count)]
    return dict(data_start=size_m4 + 4, table_start=tab_m4 + 4, count=count, aux_off=aux,
                nnames=nnames, entries=entries)


def header_strings(hdr, table_end):
    """NUL-separated names in the header tail (after the entry table)."""
    return [m.group().decode("latin-1") for m in re.finditer(rb"[A-Za-z0-9_ ./\\-]{3,}(?=\x00)", hdr[table_end:])]


def path_hash(path):
    """Archive key of a path: zlib.crc32 of the '/'-normalised, lower-cased path with a
    leading '/' and no drive prefix (confirmed on disc; matches the loader at 0x886090A0)."""
    p = path.replace("\\", "/")
    if len(p) > 1 and p[1] == ":":
        p = p[2:]
    if not p.startswith("/"):
        p = "/" + p
    return zlib.crc32(p.lower().encode("latin-1")) & 0xFFFFFFFF


def child_hash(dir_hash, name):
    """Key of file `name` inside the directory whose key is dir_hash (the directory path
    hash includes its trailing '/'); CRC-32 is simply continued with the lower-cased name."""
    return zlib.crc32(name.lower().encode("latin-1"), dir_hash) & 0xFFFFFFFF


def parse_directories(hdr):
    """Directory table at 0x10 + aux_off: 16-byte records {rel,count,count,dir_hash}; each
    points at `count` 8-byte {rel_to_name, u32} children.  Returns [(dir_hash, [names])]."""
    aux, ndirs = struct.unpack_from(">II", hdr, 0x10)
    base = 0x10 + aux
    out = []
    for i in range(ndirs):
        p = base + 16 * i
        rel, cnt, _cap, dh = struct.unpack_from(">4I", hdr, p)
        q = p + rel
        names = []
        for j in range(cnt):
            r, _x = struct.unpack_from(">II", hdr, q + 8 * j)
            s = q + 8 * j + r
            names.append(hdr[s:hdr.index(b"\x00", s)].decode("latin-1"))
        out.append((dh, names))
    return out


def split_chunks(blob):
    """Parse a PAM-LZX blob into independent LZX chunks.

    Returns (win, total_usize, [(usize, [(frame_usize, frame_bytes), ...]), ...]).
    """
    nchunks, win, last_us, total = struct.unpack_from(">4I", blob, 8)
    hdr_len = struct.unpack_from(">I", blob, 36)[0]
    ends = list(struct.unpack_from(">%dI" % (nchunks - 1), blob, 40)) if nchunks > 1 else []
    starts = [hdr_len] + ends          # absolute offsets from blob start
    stops = ends + [len(blob)]
    chunks = []
    for i in range(nchunks):
        us = last_us if i == nchunks - 1 else win
        p = starts[i]
        end = stops[i]
        left, frames = us, []
        while left > 0 and p < end:
            if blob[p] == 0xFF:
                u, c = struct.unpack_from(">HH", blob, p + 1)
                p += 5
            else:
                (c,) = struct.unpack_from(">H", blob, p)
                u = min(0x8000, left)
                p += 2
            frames.append((u, blob[p:p + c]))
            p += c
            left -= u
        chunks.append((us, frames))
    return win, total, chunks


def peek_blob(blob, n=64):
    """Return the first n uncompressed bytes of a stored entry without decoding it all.

    Only the first frame is looked at, so a truncated blob (first few KB..200 KB) suffices.
    """
    if blob[:8] != TAG:
        return blob[:n]
    _nch, win, _last, total = struct.unpack_from(">4I", blob, 8)
    p = struct.unpack_from(">I", blob, 36)[0]
    if blob[p] == 0xFF:
        u, c = struct.unpack_from(">HH", blob, p + 1)
        p += 5
    else:
        (c,) = struct.unpack_from(">H", blob, p)
        u = min(0x8000, total)
        p += 2
    dec = ts4_lzx.LZXDecoder(win.bit_length() - 1)
    return dec.decode_frame(blob[p:p + c], min(n, u), partial=True)


def unpack_blob(blob):
    """Return the uncompressed bytes of a stored entry (raw entries pass through)."""
    if blob[:8] != TAG:
        return blob
    win, total, chunks = split_chunks(blob)
    out = []
    for us, frames in chunks:
        dec = ts4_lzx.LZXDecoder(win.bit_length() - 1)  # each chunk restarts the stream
        out.extend(dec.decode_frame(c, u) for u, c in frames)
    return b"".join(out)


class Arc:
    def __init__(self, path):
        """path: a filesystem path, or an open seekable binary file object."""
        self.path = path
        self.f = open(path, "rb") if isinstance(path, (str, bytes, os.PathLike)) else path
        head = self.f.read(0x24)
        size_m4 = struct.unpack_from(">I", head, 0)[0]
        self.f.seek(0)
        self.hdr = self.f.read(size_m4 + 4)
        info = parse_header(self.hdr)
        self.__dict__.update(info)
        self.names = header_strings(self.hdr, self.table_start + 12 * self.count)
        self.directories = parse_directories(self.hdr)
        self.leaf_names = {child_hash(dh, n): (dh, n) for dh, ns in self.directories for n in ns}

    def raw(self, ent):
        h, off, size = ent
        self.f.seek(self.data_start + off)
        return self.f.read(size)

    def read(self, ent):
        return unpack_blob(self.raw(ent))

    def find(self, hash_):
        for e in self.entries:
            if e[0] == hash_:
                return e
        raise KeyError(hex(hash_))


def open_arc(arc_path, iso=None):
    """Open an archive from the filesystem, or from inside a disc image when iso is given."""
    if iso:
        import xdvdfs
        return Arc(xdvdfs.XDVDFS(iso).open_slice(arc_path))
    return Arc(arc_path)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("arc", help="archive path (inside the ISO when --iso is given)")
    ap.add_argument("--iso", help="read the archive directly from this disc image")
    ap.add_argument("--list", action="store_true", help="list entries: hash, offset, stored size, signature")
    ap.add_argument("--extract", metavar="HASH", help="hex entry hash, or 'all'")
    ap.add_argument("--max-stored", type=int, default=0, help="with --extract all: skip entries larger than this stored size")
    ap.add_argument("--out", default="work/disc/arc")
    a = ap.parse_args()
    arc = open_arc(a.arc, a.iso)
    if a.list:
        print("# entries %d  named %d  data_start 0x%X" % (arc.count, arc.nnames, arc.data_start))
        for h, off, size in arc.entries:
            sig = ""
            try:
                arc.f.seek(arc.data_start + off)
                blob = arc.f.read(min(size, 200000))
                us = struct.unpack_from(">I", blob, 20)[0] if blob[:8] == TAG else size
                sig = "%9d %s" % (us, peek_blob(blob, 8).hex())
            except Exception:
                sig = "?"
            ln = arc.leaf_names.get(h)
            print("%08x %10d %9d %s %s" % (h, off, size, sig, ln[1] if ln else ""))
    if a.extract:
        os.makedirs(a.out, exist_ok=True)
        ents = arc.entries if a.extract == "all" else [arc.find(int(a.extract, 16))]
        for e in ents:
            if a.max_stored and e[2] > a.max_stored:
                continue
            with open(os.path.join(a.out, "%08x.bin" % e[0]), "wb") as o:
                o.write(arc.read(e))


if __name__ == "__main__":
    main()
