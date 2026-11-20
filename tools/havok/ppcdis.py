#!/usr/bin/env python3
"""Tiny PowerPC disassembler over Swing_DLL.dll (local use; output must stay local).

  work/venv/bin/python tools/havok/ppcdis.py 0x885168B8 [--count N] [--floats ADDR N]

Requires capstone (already in work/venv). Prints raw instructions linearly from an
address; used to read the Havok decompression routines that confirm the bit layouts in
docs/havok.md.
"""
import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from dll_classes import PE  # noqa: E402

DLL = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "orig", "54540859", "Swing_DLL.dll")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("addr")
    ap.add_argument("--count", type=int, default=64)
    ap.add_argument("--dll", default=DLL)
    ap.add_argument("--floats", type=int, help="dump N big-endian floats at addr instead")
    a = ap.parse_args()
    pe = PE(a.dll)
    addr = int(a.addr, 0)
    if a.floats:
        o = pe.off(addr)
        print(struct.unpack(">%df" % a.floats, pe.d[o:o + 4 * a.floats]))
        return
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    md.skipdata = True  # VMX128 opcodes are unknown to capstone; print them as data
    o = pe.off(addr)
    for ins in md.disasm(pe.d[o:o + 4 * a.count], addr):
        print("  %08X: %s  %-8s %s" % (ins.address, ins.bytes.hex(), ins.mnemonic, ins.op_str))


if __name__ == "__main__":
    main()
