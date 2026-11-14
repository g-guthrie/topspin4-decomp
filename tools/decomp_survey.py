#!/usr/bin/env python3
"""Survey of what is left to match in Swing_DLL, by subsystem.

Reads config/54540859/symbols.txt (functions and sizes), config/54540859/match.json
(matched text ranges) and the decompressed PE image orig/54540859/Swing_DLL.dll,
and prints:

  buckets   per-subsystem function and byte counts, matched vs unmatched, and the
            unmatched bytes split by size class (<128, 128-256, 256-1024, >1024);
  dups      how many unmatched functions have the same normalised instruction
            sequence as an already matched function (tier 1: identical words once
            relocated immediates and call targets are masked; tier 2: identical
            opcode sequence, registers and immediates ignored), plus clusters of
            unmatched functions that share a sequence with each other;
  sample    a deterministic stratified sample of unmatched functions in a size
            window (for translator experiments), one hex address per line.

Standard library only; no disassembler is needed (instructions are decoded from
raw words).  The bucket ranges below were set by hand from string references,
RTTI type names, import calls and matched-source neighbourhoods; the evidence is
in docs/decomp-remaining.md.  Ranges are [lo, hi).

  python3 tools/decomp_survey.py buckets [--json out.json]
  python3 tools/decomp_survey.py dups [--min-size 128]
  python3 tools/decomp_survey.py sample --lo 256 --hi 2048 -n 32 [--seed 1]
"""
import argparse, collections, hashlib, json, random, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# (lo, hi, bucket, group). group: game | lib (public source exists) | sdk (middleware/XDK, no public source)
RANGES = [
    (0x88150000, 0x8819C000, 'game: core (XData, containers, UI node classes)', 'game'),
    (0x8819C000, 0x881A2000, 'lib: trio 1.x (printf)', 'lib'),
    (0x881A2000, 0x88287D28, 'game: core (loaders, resources, render support)', 'game'),
    (0x88287D28, 0x882A0000, 'xdk: D3D9 runtime (inferred)', 'sdk'),
    (0x882A0000, 0x882A8000, 'xdk: PIX / D3D debug', 'sdk'),
    (0x882A8000, 0x882E25D8, 'xdk: D3DX9 texture/image loaders', 'sdk'),
    (0x882E25D8, 0x883089E0, 'lib: libpng 1.0.5 + libjpeg 6b + zlib 1.1.x', 'lib'),
    (0x883089E0, 0x884014E0, 'fmod: FMOD Ex 4.32.02 + Event + codecs', 'sdk'),
    (0x884014E0, 0x88562AB8, 'havok: 5.5.0 Animation + Physics + Base', 'sdk'),
    (0x88562AB8, 0x88590000, 'xdk: C runtime + xapi', 'sdk'),
    (0x88590000, 0x885D8328, 'xdk: XAudio2 / XMA', 'sdk'),
    (0x885D8328, 0x885DC838, 'xdk: voice (XHV, Mic/Rmc)', 'sdk'),
    (0x885DC838, 0x885E78C8, 'xdk: xgraphics shader ucode compiler', 'sdk'),
    (0x885E78C8, 0x885F4E48, 'havok: 5.5.0 Base/Serialize/Utilities tail', 'sdk'),
    (0x885F4E48, 0x88640000, 'game: Pam core (XData server, heaps, modules)', 'game'),
    (0x88640000, 0x886E8000, 'game: Swing gameplay + animation glue', 'game'),
    (0x886E8000, 0x88780000, 'game: Pam Display renderer', 'game'),
    (0x88780000, 0x88800000, 'game: PlayerCreator, UI, script bindings', 'game'),
    (0x88800000, 0x8883C000, 'lib: Lua 5.0.2 (+ script engine glue)', 'lib'),
    (0x8883C000, 0x88871F08, 'game: game flow DB (season, profiles)', 'game'),
    (0x88871F08, 0x88878FA0, 'lib: zlib 1.2.3', 'lib'),
    (0x88878FA0, 0x88891678, 'game: physics wrapper, IO, sound events', 'game'),
    (0x88891678, 0x888AA8D0, 'lib: expat', 'lib'),
    (0x888AA8D0, 0x88900000, 'game: ball, camera, minigames, publishers', 'game'),
    (0x88900000, 0x889CE000, 'game: net/lobby, scheduler, front end', 'game'),
    (0x889CE000, 0x889D02D8, 'lib: Lua 5.0.2 libs (tab/math/loadlib)', 'lib'),
    (0x889D02D8, 0x889D1900, 'xdk: OpenMP runtime', 'sdk'),
    (0x889D1900, 0x889D3410, 'game: static initialisers', 'game'),
    (0x889D3410, 0x88B00000, 'havok: reflection/class tables + static init', 'sdk'),
    (0x88B00000, 0x88B20000, 'bink: Bink (BINK/RADCODE sections)', 'sdk'),
]
SIZE_CLASSES = [(0, 128), (128, 256), (256, 1024), (1024, 1 << 30)]


def bucket_of(addr):
    for lo, hi, name, grp in RANGES:
        if lo <= addr < hi:
            return name, grp
    return 'unassigned', 'game'


def load_functions(symbols=ROOT / 'config/54540859/symbols.txt', match=ROOT / 'config/54540859/match.json'):
    """-> list of dicts {name, sec, addr, size, matched, source} (one per function start)."""
    pat = re.compile(r'(\S+) = (\S+):0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)')
    fns, seen = [], set()
    for line in open(symbols):
        m = pat.match(line)
        if m and int(m[3], 16) not in seen:
            seen.add(int(m[3], 16))
            fns.append(dict(name=m[1], sec=m[2], addr=int(m[3], 16), size=int(m[4], 16), matched=False, source=None))
    ms = {}
    for x in json.load(open(match))['matches']:
        ms[int(x['text_range'].split('-')[0], 16)] = x['source']
    for f in fns:
        if f['addr'] in ms:
            f['matched'], f['source'] = True, ms[f['addr']]
    return sorted(fns, key=lambda f: f['addr'])


class Image:
    """Big-endian code words from the decompressed PE (Swing_DLL.dll)."""

    def __init__(self, path=ROOT / 'orig/54540859/Swing_DLL.dll'):
        b = self.b = open(path, 'rb').read()
        e = struct.unpack_from('<I', b, 0x3C)[0]
        ns, osz = struct.unpack_from('<H', b, e + 6)[0], struct.unpack_from('<H', b, e + 20)[0]
        base = struct.unpack_from('<I', b, e + 24 + 28)[0]
        sec = e + 24 + osz
        self.secs = []
        for i in range(ns):
            n, vs, va, rs, rp = struct.unpack_from('<8sIIII', b, sec + 40 * i)
            self.secs.append((n.rstrip(b'\0').decode(), base + va, vs, rs, rp))

    def words(self, addr, size):
        for _, va, vs, rs, rp in self.secs:
            if va <= addr < va + min(vs, rs):
                o = addr - va + rp
                return struct.unpack_from('>%dI' % (size // 4), self.b, o)
        return ()


XO_OPS = {19, 31, 59, 63}
DFORM = set(range(32, 56)) | {14, 24}


def normalise(words):
    """-> (tier1 key, tier2 key).  Tier 1 keeps registers but masks call targets
    (b/bl), lis immediates and the low halves that pair with a lis.  Tier 2 keeps
    only the opcode (plus extended opcode) of each instruction."""
    t1, t2, lis = [], [], set()
    for w in words:
        op = w >> 26
        rd, ra = (w >> 21) & 31, (w >> 16) & 31
        if op == 18:
            t1.append(w & 0xFC000003)
        elif op == 15 and ra == 0:
            t1.append(w & 0xFFFF0000); lis.add(rd); t2.append(op); continue
        elif op in DFORM and ra in lis:
            t1.append(w & 0xFFFF0000)
        else:
            t1.append(w)
        if op in (14, 15, 24, 25) or (32 <= op <= 43):
            lis.discard(rd)  # rD overwritten (approximation: GPR destinations only)
        if op in XO_OPS:
            t2.append((op << 16) | ((w >> 1) & 0x3FF))
        elif op in (4, 5, 6):
            t2.append((op << 16) | (w & 0x7F0))
        else:
            t2.append(op)
    h = lambda seq: hashlib.blake2b(struct.pack('>%dI' % len(seq), *seq), digest_size=12).digest()
    return h(t1), h(t2), t2


def minhash(ops, perms):
    """MinHash signature of the opcode 4-gram set."""
    sh = {hash(tuple(ops[i:i + 4])) & 0xFFFFFFFF for i in range(max(1, len(ops) - 3))}
    return tuple(min(((a * x + b) % 4294967311) for x in sh) for a, b in perms)


def fuzzy(un, matched, keys, threshold, bands=8, rows=3):
    """Tier 3: for each unmatched function, the best difflib ratio of its opcode sequence
    against matched functions that share a MinHash LSH band and whose length is within 15%.
    Returns {addr: (ratio, matched addr)} for ratio >= threshold."""
    import difflib
    rng = random.Random(7)
    perms = [(rng.randrange(1, 1 << 32), rng.randrange(0, 1 << 32)) for _ in range(bands * rows)]
    index = collections.defaultdict(list)
    for f in matched:
        sig = minhash(keys[f['addr']][2], perms)
        for bnd in range(bands):
            index[(bnd, sig[bnd * rows:(bnd + 1) * rows])].append(f)
    out = {}
    for f in un:
        ops = keys[f['addr']][2]
        sig = minhash(ops, perms)
        cands = {}
        for bnd in range(bands):
            for g in index.get((bnd, sig[bnd * rows:(bnd + 1) * rows]), ()):
                if abs(g['size'] - f['size']) <= 0.15 * f['size']:
                    cands[g['addr']] = g
        best = (0.0, None)
        for g in cands.values():
            sm = difflib.SequenceMatcher(None, ops, keys[g['addr']][2], autojunk=False)
            if sm.real_quick_ratio() < max(threshold, best[0]) or sm.quick_ratio() < max(threshold, best[0]):
                continue
            r = sm.ratio()
            if r > best[0]:
                best = (r, g['addr'])
        if best[0] >= threshold:
            out[f['addr']] = best
    return out


def cmd_buckets(fns, args):
    agg = collections.OrderedDict()
    for lo, hi, name, grp in RANGES + [(0, 0, 'unassigned', 'game')]:
        agg[name] = dict(group=grp, lo=lo, hi=hi, fns=0, bytes=0, mfns=0, mbytes=0, un=[0] * len(SIZE_CLASSES), unn=[0] * len(SIZE_CLASSES))
    for f in fns:
        name, _ = bucket_of(f['addr'])
        a = agg[name]
        a['fns'] += 1; a['bytes'] += f['size']
        if f['matched']:
            a['mfns'] += 1; a['mbytes'] += f['size']
        else:
            for i, (lo, hi) in enumerate(SIZE_CLASSES):
                if lo <= f['size'] < hi:
                    a['un'][i] += f['size']; a['unn'][i] += 1
    agg = {k: v for k, v in agg.items() if v['fns']}
    tot = collections.Counter()
    print('| Bucket | Range | Fns | Bytes | Matched fns | Matched bytes | Unmatched bytes | %done | unm <128 | 128-256 | 256-1K | >1K |')
    print('|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|')
    for k, v in agg.items():
        u = v['bytes'] - v['mbytes']
        print(f"| {k} | {v['lo']:08X}-{v['hi']:08X} | {v['fns']} | {v['bytes']} | {v['mfns']} | {v['mbytes']} | {u} | "
              f"{100 * v['mbytes'] / max(1, v['bytes']):.1f} | " + ' | '.join(str(x) for x in v['un']) + ' |')
        for key in ('fns', 'bytes', 'mfns', 'mbytes'):
            tot[key] += v[key]
            tot[v['group'] + key] += v[key]
    print(f"| **total** | | {tot['fns']} | {tot['bytes']} | {tot['mfns']} | {tot['mbytes']} | {tot['bytes'] - tot['mbytes']} | "
          f"{100 * tot['mbytes'] / tot['bytes']:.1f} | | | | |")
    print()
    print('| Group | Fns | Bytes | Matched bytes | Unmatched bytes |')
    print('|---|---:|---:|---:|---:|')
    for g in ('game', 'lib', 'sdk'):
        print(f"| {g} | {tot[g + 'fns']} | {tot[g + 'bytes']} | {tot[g + 'mbytes']} | {tot[g + 'bytes'] - tot[g + 'mbytes']} |")
    if args.json:
        json.dump(agg, open(args.json, 'w'), indent=1)


def cmd_dups(fns, args):
    img = Image(args.image)
    keys = {}
    for f in fns:
        if f['size'] >= 8 and f['sec'] == '.text':
            keys[f['addr']] = normalise(img.words(f['addr'], f['size']))
    m1 = {keys[f['addr']][0] for f in fns if f['matched'] and f['addr'] in keys}
    m2 = {keys[f['addr']][1] for f in fns if f['matched'] and f['addr'] in keys}
    un = [f for f in fns if not f['matched'] and f['addr'] in keys and f['size'] >= args.min_size]
    rows = collections.defaultdict(lambda: [0, 0, 0, 0, 0, 0])  # bucket -> n,b unm; n,b tier1; n,b tier2-only
    for f in un:
        r = rows[bucket_of(f['addr'])[0]]
        r[0] += 1; r[1] += f['size']
        k1, k2 = keys[f['addr']][:2]
        if k1 in m1:
            r[2] += 1; r[3] += f['size']
        elif k2 in m2:
            r[4] += 1; r[5] += f['size']
    print(f'unmatched functions >= {args.min_size} bytes that repeat an already matched function')
    print('| Bucket | Unmatched fns | Unmatched bytes | Tier-1 fns | Tier-1 bytes | Tier-2-only fns | Tier-2-only bytes |')
    print('|---|---:|---:|---:|---:|---:|---:|')
    tot = [0] * 6
    for k, r in sorted(rows.items(), key=lambda kv: -kv[1][3] - kv[1][5]):
        print(f'| {k} | ' + ' | '.join(str(x) for x in r) + ' |')
        tot = [a + b for a, b in zip(tot, r)]
    print('| **total** | ' + ' | '.join(str(x) for x in tot) + ' |')
    if args.fuzzy:
        mfs = [f for f in fns if f['matched'] and f['addr'] in keys and f['size'] >= args.min_size]
        rest = [f for f in un if keys[f['addr']][0] not in m1 and keys[f['addr']][1] not in m2]
        fz = fuzzy(rest, mfs, keys, args.fuzzy)
        rows3 = collections.defaultdict(lambda: [0, 0])
        for f in rest:
            if f['addr'] in fz:
                r = rows3[bucket_of(f['addr'])[0]]; r[0] += 1; r[1] += f['size']
        print(f'\ntier 3 (opcode-sequence difflib ratio >= {args.fuzzy} against a matched function within 15% size, '
              f'not already tier 1/2): {len(fz)} functions, {sum(r[1] for r in rows3.values())} bytes')
        for k, r in sorted(rows3.items(), key=lambda kv: -kv[1][1]):
            print(f'  {r[0]:5d} fns {r[1]:8d} B  {k}')
        for ad, (r, g) in sorted(fz.items(), key=lambda kv: -kv[1][0])[:args.top]:
            print(f'  {ad:08X} ~ {g:08X} ratio {r:.3f}')
    # clusters among the unmatched (one match would cover the rest)
    for tier in (0, 1):
        cl = collections.defaultdict(list)
        for f in un:
            cl[keys[f['addr']][tier]].append(f)
        big = [v for v in cl.values() if len(v) > 1]
        extra_n = sum(len(v) - 1 for v in big)
        extra_b = sum(sum(f['size'] for f in v[1:]) for v in big)
        print(f'\ntier {tier + 1} clusters among unmatched: {len(big)} clusters, {sum(len(v) for v in big)} functions; '
              f'matching one per cluster covers {extra_n} more functions, {extra_b} bytes')
        for v in sorted(big, key=lambda v: -sum(f['size'] for f in v))[:args.top]:
            print(f"  {len(v):4d} x {v[0]['size']:5d} B  {v[0]['addr']:08X} {bucket_of(v[0]['addr'])[0]}")


def cmd_sample(fns, args):
    rng = random.Random(args.seed)
    pool = [f for f in fns if not f['matched'] and f['name'].startswith('fn_') and f['sec'] == '.text'
            and args.lo <= f['size'] < args.hi]
    by = collections.defaultdict(list)
    for f in pool:
        by[bucket_of(f['addr'])[0]].append(f)
    # proportional to unmatched bytes per bucket, at least one per bucket with >= 50 KB unmatched
    tot = sum(f['size'] for f in pool)
    picks = []
    for k, v in sorted(by.items()):
        share = sum(f['size'] for f in v) / tot
        n = max(1 if sum(f['size'] for f in v) >= 50000 else 0, round(args.n * share))
        picks += rng.sample(v, min(n, len(v)))
    for f in sorted(picks, key=lambda f: f['addr']):
        print(f"{f['addr']:08x}" + ('' if args.bare else f"  {f['size']:5d}  {bucket_of(f['addr'])[0]}"))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--symbols', default=ROOT / 'config/54540859/symbols.txt')
    ap.add_argument('--match', default=ROOT / 'config/54540859/match.json')
    ap.add_argument('--image', default=ROOT / 'orig/54540859/Swing_DLL.dll')
    sub = ap.add_subparsers(dest='cmd', required=True)
    b = sub.add_parser('buckets'); b.add_argument('--json')
    d = sub.add_parser('dups'); d.add_argument('--min-size', type=int, default=128); d.add_argument('--top', type=int, default=15)
    d.add_argument('--fuzzy', type=float, default=0.0, help='also report tier 3 near duplicates at this difflib ratio (e.g. 0.9)')
    s = sub.add_parser('sample')
    s.add_argument('--lo', type=int, default=256); s.add_argument('--hi', type=int, default=2048)
    s.add_argument('-n', type=int, default=32); s.add_argument('--seed', type=int, default=1)
    s.add_argument('--bare', action='store_true', help='addresses only (for asm2c --only-addrs)')
    a = ap.parse_args(argv)
    fns = load_functions(a.symbols, a.match)
    {'buckets': cmd_buckets, 'dups': cmd_dups, 'sample': cmd_sample}[a.cmd](fns, a)


if __name__ == '__main__':
    main()
