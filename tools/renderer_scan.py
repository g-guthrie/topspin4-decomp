#!/usr/bin/env python3
"""Renderer / D3D boundary measurements for Swing_DLL (docs/renderer-map.md).

Usage:
  python3 tools/renderer_scan.py boundary   # D3D/D3DX/PIX callees from game code
  python3 tools/renderer_scan.py inline     # game functions writing D3D device shadow state
  python3 tools/renderer_scan.py pm4        # functions holding PM4 type-3 header constants

Reads orig/54540859/Swing_DLL.dll and config/54540859/symbols.txt. Needs capstone
(only for `inline`). Prints text; writes nothing.
"""
import bisect, re, struct, sys

ROOT = __file__.rsplit('/tools/', 1)[0] + '/'
IMG = open(ROOT + 'orig/54540859/Swing_DLL.dll', 'rb').read()
_e = struct.unpack_from('<I', IMG, 0x3c)[0]
_ns = struct.unpack_from('<H', IMG, _e + 6)[0]
_osz = struct.unpack_from('<H', IMG, _e + 20)[0]
BASE = struct.unpack_from('<I', IMG, _e + 24 + 28)[0]
SECS = [struct.unpack_from('<8sIIII', IMG, _e + 24 + _osz + 40 * i) for i in range(_ns)]

D3D = (0x88287D28, 0x882A0000)
PIX = (0x882A0000, 0x882A8000)
D3DX = (0x882A8000, 0x882E25D8)
REND = (0x886E8000, 0x88780000)
CORE = (0x881A2000, 0x88287D28)
GAME = [(0x88150000, 0x8819C000), (0x881A2000, 0x88287D28), (0x885F4E48, 0x886E8000),
        (0x886E8000, 0x88800000), (0x8883C000, 0x88871F08), (0x88878FA0, 0x88891678),
        (0x888AA8D0, 0x889CE000), (0x889D1900, 0x889D3410)]


def off(va):
    rva = va - BASE
    for _, vs, va_, rs, rp in SECS:
        if va_ <= rva < va_ + max(vs, rs):
            return rva - va_ + rp


def words(a, n):
    o = off(a)
    return [struct.unpack_from('>I', IMG, o + k)[0] for k in range(0, n, 4)]


def inr(a, r):
    return r[0] <= a < r[1]


def ingame(a):
    return any(lo <= a < hi for lo, hi in GAME)


def bucket(a):
    for nm, r in (('d3d', D3D), ('pix', PIX), ('d3dx', D3DX), ('renderer', REND), ('core', CORE)):
        if inr(a, r):
            return nm
    return 'game' if ingame(a) else 'lib'


FUNCS = []
for line in open(ROOT + 'config/54540859/symbols.txt'):
    m = re.match(r'(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)', line)
    if m:
        FUNCS.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
FUNCS.sort()


def calls(f):
    a, n, _ = f
    for k, w in enumerate(words(a, n)):
        if (w >> 26) == 18:
            d = w & 0x03FFFFFC
            if d & 0x02000000:
                d -= 0x04000000
            t = d if w & 2 else a + 4 * k + d
            if (w & 1) or not (a <= t < a + n):
                yield a + 4 * k, t


def cmd_boundary():
    for rng, label in ((D3D, 'D3D'), (D3DX, 'D3DX'), (PIX, 'PIX')):
        res = {}
        for f in FUNCS:
            if f[0] < 0x88B20000 and ingame(f[0]):
                for s, t in calls(f):
                    if inr(t, rng):
                        res.setdefault(t, []).append(f[0])
        print(f'# {label}: {len(res)} callees, {sum(map(len, res.values()))} call sites')
        for t in sorted(res):
            cs = sorted(set(res[t]))
            ren = sum(1 for c in cs if inr(c, REND))
            print(f'{t:08X} sites={len(res[t])} callers={len(cs)} renderer={ren} ' + ' '.join(f'{c:08X}' for c in cs))


def cmd_pm4():
    hits = {}
    for f in FUNCS:
        a, n, _ = f
        if a >= 0x88B20000:
            continue
        hi = {}
        for w in words(a, n):
            op, rd, ra, imm = w >> 26, (w >> 21) & 31, (w >> 16) & 31, w & 0xFFFF
            if op == 15 and ra == 0:
                hi[rd] = imm
            elif op == 24 and ra in hi:
                v = (hi[ra] << 16) | imm
                if (v >> 30) == 3 and (v & 0xFF) == 0 and 0x20 <= ((v >> 8) & 0x7F) < 0x7F and ((v >> 16) & 0x3FFF) < 0x400:
                    hits.setdefault(a, []).append(v)
    from collections import Counter
    print(Counter(bucket(a) for a in hits))
    for a in sorted(hits):
        print(f'{a:08X} {bucket(a)} ' + ' '.join(hex(v) for v in hits[a][:6]))


def cmd_inline():
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_PPC, capstone.CS_MODE_32 | capstone.CS_MODE_BIG_ENDIAN)
    mem = re.compile(r'(r\d+|f\d+|v\d+), (-?0x[0-9a-f]+|-?\d+)\((r\d+)\)')
    total = 0
    for f in FUNCS:
        a, n, name = f
        if not ingame(a):
            continue
        o = off(a)
        lds, dirty, st = {}, set(), []
        for k in range(0, n, 4):
            ins = list(md.disasm(IMG[o + k:o + k + 4], a + k))
            if not ins:
                continue
            m = mem.match(ins[0].op_str)
            if not m:
                continue
            mn, rt, d, rb = ins[0].mnemonic, m.group(1), int(m.group(2), 0), m.group(3)
            if rb == 'r1':
                continue
            if mn == 'ld' and d in range(0, 0x40, 8):
                lds[(rb, d)] = rt
            elif mn == 'std' and (rb, d) in lds:
                dirty.add(rb)
            if mn.startswith('st') and mn != 'stwu' and 0x480 <= d < 0x5F00:
                st.append((rb, d))
        state = [(rb, d) for rb, d in st if rb in dirty]
        if state:
            total += n
            offs = sorted(set(d for _, d in state))
            print(f'{a:08X} size={n:#x} {bucket(a)} state_stores={len(state)} offsets=' + ','.join(hex(x) for x in offs[:12]))
    print(f'total bytes {total:#x}')


if __name__ == '__main__':
    {'boundary': cmd_boundary, 'pm4': cmd_pm4, 'inline': cmd_inline}[sys.argv[1] if len(sys.argv) > 1 else 'boundary']()
