#!/usr/bin/env python3
"""XBin (Pam::XBinData) container reader prototype for Top Spin 4 (Xbox 360), standard library only.

NOTE (G5): the disc-verified reader is tools/ts4_xbin.py.  Its Layout/Walker classes decode the
complete Layoutall.bin type table and walk every typed member of any XBin file (see
docs/gameplay/tunables-catalog.md s2).  The 5-word header model below predates the retail data
and does not match the shipped files; keep it only for the Animations.bin record helpers.

Spec: work/gameplay-notes/df.md section 1.  UNVALIDATED against real data (none was available when
written): header/section table are H (loader fn_8892A968 read directly), body/typed-struct access is M,
field meanings of Animations.bin records are M (offsets measured in code, names are roles).

All integers are big-endian (Xbox 360 native; the loader never byte-swaps).

File = 0x14-byte header (5 x u32) + body. Offsets inside the body are relative to the body start, i.e.
file offset - 0x14. The 'section table' (header word 4 = file offset, word 3 = count) is an array of u32
file offsets of sections.  Typed structs ("nodes") live inside the body; arrays are 8-byte headers
{s32 rel, s32 count}: elements start at (header address + rel) with the struct's stride, rel = -1 = null.

Usage:
  df_xbin.py info FILE.bin
  df_xbin.py scan FILE.bin          heuristic search for {rel,count} array headers (format discovery aid)
  df_xbin.py anim FILE.bin          dump Animations.bin records (0x8c-byte) with the measured offsets
  df_xbin.py hash NAME...           crc32 name hashes (zlib crc32 of the ASCII string)
  df_xbin.py selftest
"""
from __future__ import annotations

import json
import struct
import sys
import zlib

HDR = 0x14


def crc(name: str) -> int:
    """Every name in the data is zlib crc32 (seed 0, standard table) of the exact ASCII string."""
    return zlib.crc32(name.encode("latin1")) & 0xFFFFFFFF


class XBin:
    def __init__(self, data: bytes):
        if len(data) < HDR:
            raise ValueError("too short")
        self.data = data
        # fn_8892A968: five u32 read from file start
        (self.w0_root_hash, self.w1_layout_hash, self.w2_align, self.n_sections, self.sect_table_off) = \
            struct.unpack(">5I", data[:HDR])
        self.body = data[HDR:]
        self.sections = []
        if self.n_sections and self.sect_table_off + 4 * self.n_sections <= len(data):
            offs = struct.unpack_from(">%dI" % self.n_sections, data, self.sect_table_off)
            ends = list(offs[1:]) + [len(data)]
            for o, e in zip(offs, ends):
                self.sections.append((o, e))

    # --- typed struct helpers (offsets are BODY offsets, i.e. file offset - 0x14) ---------------
    def u32(self, off):
        return struct.unpack_from(">I", self.body, off)[0]

    def i32(self, off):
        return struct.unpack_from(">i", self.body, off)[0]

    def f32(self, off):
        return struct.unpack_from(">f", self.body, off)[0]

    def u16(self, off):
        return struct.unpack_from(">H", self.body, off)[0]

    def array(self, hdr_off, stride):
        """Return element offsets of the {s32 rel, s32 count} array whose header is at hdr_off."""
        rel, count = struct.unpack_from(">ii", self.body, hdr_off)
        if rel == -1 or count <= 0:
            return []
        base = hdr_off + rel
        return [base + i * stride for i in range(count)]

    def cstr(self, off):
        b = self.body
        return b[off:b.index(b"\0", off)].decode("latin1")


def scan_array_headers(x: XBin, max_count=100000):
    """Discovery aid: list body offsets where a plausible {rel,count} header sits, with the implied
    stride when the next header target is close.  Candidates only - verify by eye."""
    out = []
    b = x.body
    for off in range(0, len(b) - 8, 4):
        rel, count = struct.unpack_from(">ii", b, off)
        if rel <= 0 or count <= 0 or count > max_count:
            continue
        base = off + rel
        if base + count > len(b):
            continue
        out.append((off, rel, count, base))
    return out


# ---- Animations.bin (AnimationDB root, hash 0xEE710815) -------------------------------------------
REC = 0x8C          # animation / setup record, array header at root+0x50 (count at root+0x54)
ANNOT = 0x10        # annotation row {u32 name hash, f32 time, ...}  header at rec+0x64
SEG = 0x28          # segment, header at rec+0x70 ; type hash at +0x0c, floats at +0x10/+0x14
H_EVENT_RACKET = 0x3B9AD22E   # crc32("EventRacket")
H_PREPARATION = 0x7F6C2523    # crc32("Preparation")


def read_animation_records(x: XBin, root=0):
    recs = []
    for r in x.array(root + 0x50, REC):
        d = {
            "id": x.u32(r + 0x84),                    # == AOD\%u.hkx file name (M)
            "slot": x.u16(r + 0x0C),                  # layer slot, 0xFFFF = unassigned (H role)
            "time_ratio": x.f32(r + 0x14),            # (ratio-1.0) scales event time (H formula)
            "setup_scale": [x.f32(r + 0x38 + 4 * i) for i in range(4)],  # setup records only (M)
            "annotations": [],
            "segments": [],
            "raw_hex": x.body[r:r + REC].hex(),
        }
        for a in x.array(r + 0x64, ANNOT):
            h = x.u32(a)
            d["annotations"].append({"name_hash": "0x%08X" % h,
                                     "name": {H_EVENT_RACKET: "EventRacket", H_PREPARATION: "Preparation"}.get(h),
                                     "time": x.f32(a + 4), "raw_hex": x.body[a:a + ANNOT].hex()})
        for s in x.array(r + 0x70, SEG):
            d["segments"].append({"type_hash": "0x%08X" % x.u32(s + 0x0C), "f10": x.f32(s + 0x10),
                                  "f14": x.f32(s + 0x14), "raw_hex": x.body[s:s + SEG].hex()})
        recs.append(d)
    return recs


def selftest():
    # synthetic body: root with a 1-record array at +0x50
    body = bytearray(0x400)
    struct.pack_into(">ii", body, 0x50, 0x100 - 0x50, 1)       # rec @0x100
    rec = 0x100
    struct.pack_into(">I", body, rec + 0x84, 4242)
    struct.pack_into(">f", body, rec + 0x14, 1.25)
    struct.pack_into(">ii", body, rec + 0x64, 0x200 - (rec + 0x64), 1)
    struct.pack_into(">If", body, 0x200, H_EVENT_RACKET, 37.5)
    struct.pack_into(">ii", body, rec + 0x70, 0x300 - (rec + 0x70), 2)
    struct.pack_into(">I", body, 0x30C, 0x959A9407)
    sect_off = HDR + len(body)
    data = struct.pack(">5I", crc("Root"), 0, len(body), 1, sect_off) + bytes(body) + struct.pack(">I", HDR)
    x = XBin(data)
    r = read_animation_records(x)
    assert r[0]["id"] == 4242 and abs(r[0]["time_ratio"] - 1.25) < 1e-6
    assert r[0]["annotations"][0]["name"] == "EventRacket" and r[0]["annotations"][0]["time"] == 37.5
    assert len(r[0]["segments"]) == 2 and r[0]["segments"][0]["type_hash"] == "0x959A9407"
    print("selftest OK")


def main(argv):
    if len(argv) < 2:
        print(__doc__)
        return 2
    cmd = argv[1]
    if cmd == "selftest":
        selftest()
        return 0
    if cmd == "hash":
        for n in argv[2:]:
            print("0x%08X %s" % (crc(n), n))
        return 0
    x = XBin(open(argv[2], "rb").read())
    if cmd == "info":
        print("root/type hash 0x%08X layout hash 0x%08X align 0x%X sections %d table@0x%X body 0x%X bytes" % (
            x.w0_root_hash, x.w1_layout_hash, x.w2_align, x.n_sections, x.sect_table_off, len(x.body)))
        for i, (o, e) in enumerate(x.sections):
            print("  section %d file 0x%X..0x%X" % (i, o, e))
        return 0
    if cmd == "scan":
        for off, rel, count, base in scan_array_headers(x):
            print("body+0x%X rel=0x%X count=%d -> body+0x%X" % (off, rel, count, base))
        return 0
    if cmd == "anim":
        print(json.dumps(read_animation_records(x), indent=1))
        return 0
    print(__doc__)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv))
