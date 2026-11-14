#!/usr/bin/env python3
"""Regenerate C for every unmatched function into a scratch directory (no byte check).

    TS4_MATCHING_DIR=work/matching-bNN python3 tools/asm2c/generate.py --out work/gen \
        [--max-size 0x4000] [--variant 10w] [--groups game,lib] [--flags O1] [--jobs 4]

For consumers that do not need byte-identical code (the "equivalent" tier, static
recompilation): every fn_* placeholder in .text that is not in match.json, inside the
survey groups asked for (tools/decomp_survey.py RANGES; default game + open-source libs),
is translated with one variant (default 10: r3 is returned wherever it was written; see run.py translate_all), written in files of --chunk
functions and compiled with the real compiler (/O2 /Oi plus --flags).  Functions that
fail to compile are dropped from their file and recorded.  Nothing is written outside
--out.

Writes
  OUT/gen_NNN.c          compiled-clean C, one definition per function
                         (`ts4_<kind>_<detail>_<ADDR>`, original address in a comment)
  OUT/manifest.json      {addr: {"name", "size", "status", "file"|"reason"}} with status
                         'ok' (in a file, compiles), 'refused' (translator Skip reason),
                         'compile' (translated but rejected by the compiler)
  OUT/summary.txt        counts and bytes per size class and the refusal categories
"""
import argparse, collections, json, re, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
import emit, frame, run, source, translate  # noqa: E402
from decomp_survey import RANGES, load_functions  # noqa: E402

CLASSES = [(0, 128), (128, 256), (256, 512), (512, 1024), (1024, 2048), (2048, 4096), (4096, 1 << 30)]


def cls(sz):
    lo, hi = next(c for c in CLASSES if c[0] <= sz < c[1])
    return f'{lo}-{hi if hi < 1 << 30 else "max"}'


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--max-size', type=lambda x: int(x, 0), default=0x4000)
    ap.add_argument('--variant', default='10', help='run.py variant; the default keeps r3 return values (w would make every function void)')
    ap.add_argument('--groups', default='game,lib', help='survey groups: game, lib, sdk')
    ap.add_argument('--flags', default='', help="'' or a run.py flag set name (O1, Oc, O1Oc)")
    ap.add_argument('--chunk', type=int, default=150)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--asm', type=Path, help='disassembly cache (default OUT/asm.pkl)')
    ap.add_argument('--limit', type=int, default=0)
    a = ap.parse_args()
    a.out.mkdir(parents=True, exist_ok=True)
    groups = set(a.groups.split(','))
    dis = source.Disasm(a.asm or a.out / 'asm.pkl')
    a2n = source.symbol_at()
    env = translate.Env(lambda s: dis.lines(s), a2n.get)
    todo = []
    for f in load_functions():
        if f['matched'] or not f['name'].startswith('fn_') or f['sec'] != '.text' or f['size'] > a.max_size:
            continue
        g = next((g for lo, hi, nm, g in RANGES if lo <= f['addr'] < hi), 'game')
        if g in groups:
            todo.append((f['name'], f['addr'], f['size']))
    if a.limit:
        todo = todo[:a.limit]
    print(f'{len(todo)} functions', flush=True)
    res, fails = run.translate_all(todo, dis, env, a.variant)
    dis.save()
    man = {}
    size = {ad: sz for _, ad, sz in todo}
    for ad, why in fails.items():
        man[ad] = {'name': a2n.get(ad), 'size': size[ad], 'status': 'refused', 'reason': run.categorize(why)}
    flags = run.FLAGSETS[a.flags]
    groups_c = [(False, sorted(ad for ad in res if not run.is_cpp(res[ad])))]
    groups_c.append((True, sorted(ad for ad in res if run.is_cpp(res[ad]))))
    jobs = []
    for cpp, sel in groups_c:
        jobs += [(cpp, sel[i:i + a.chunk]) for i in range(0, len(sel), a.chunk)]

    def one(ix):
        cpp, grp = jobs[ix]
        path = a.out / f'gen_{ix:03d}.{"cpp" if cpp else "c"}'
        got = frame.compile_frames({ad: res[ad] for ad in grp}, str(path), flags, cpp=cpp, tries=12)
        if got and set(got) != set(grp):
            emit.build(res, sorted(got), path, cpp)       # final file holds only clean functions
        if not got:
            Path(path).unlink(missing_ok=True)
        return path, grp, set(got)
    with ThreadPoolExecutor(a.jobs) as ex:
        for path, grp, ok in ex.map(one, range(len(jobs))):
            for ad in grp:
                if ad in ok:
                    man[ad] = {'name': a2n.get(ad), 'size': size[ad], 'status': 'ok', 'file': path.name}
                else:
                    man[ad] = {'name': a2n.get(ad), 'size': size[ad], 'status': 'compile'}
    json.dump({f'{ad:08X}': v for ad, v in sorted(man.items())}, open(a.out / 'manifest.json', 'w'), indent=0)
    tab = collections.defaultdict(lambda: collections.Counter())
    for ad, v in man.items():
        c = cls(v['size'])
        tab[c]['n'] += 1; tab[c]['b'] += v['size']
        tab[c][v['status']] += 1; tab[c][v['status'] + '_b'] += v['size']
    lines = [f'variant {a.variant} flags {a.flags or "base"} groups {a.groups} max-size {a.max_size:#x}',
             f'{"size":>10} {"fns":>6} {"bytes":>9} {"ok":>6} {"ok bytes":>9} {"refused":>8} {"compile":>8}']
    for lo, hi in CLASSES:
        c = cls(lo)
        if c in tab:
            t = tab[c]
            lines.append(f'{c:>10} {t["n"]:6d} {t["b"]:9d} {t["ok"]:6d} {t["ok_b"]:9d} {t["refused"]:8d} {t["compile"]:8d}')
    T = collections.Counter()
    for t in tab.values():
        T.update(t)
    lines.append(f'{"total":>10} {T["n"]:6d} {T["b"]:9d} {T["ok"]:6d} {T["ok_b"]:9d} {T["refused"]:8d} {T["compile"]:8d}')
    lines.append('refusals:')
    for k, n in collections.Counter(v['reason'] for v in man.values() if v['status'] == 'refused').most_common(30):
        lines.append(f'  {n:6d}  {k}')
    (a.out / 'summary.txt').write_text('\n'.join(lines) + '\n')
    print('\n'.join(lines))


if __name__ == '__main__':
    main()
