#!/usr/bin/env python3
"""CLI: translate every small unnamed function, verify, emit sources + specs.

  python3 tools/asm2c/run.py [--max-size 0x100] [--chunk 200] [--jobs 4]
        [--prefix fk] [--family K] [--work DIR] [--limit N] [--variants 10,11,00,01]

Stages
 1. select fn_* .text symbols <= max-size minus work/gen_exclude.txt;
 2. for each variant (mode,orient) translate still-unmatched functions, write
    scratch .c files of `chunk` functions under --work, run tools/fn_check.py
    once per file, keep MATCHes;
 3. write src/xbox360/<prefix>_NNN.c with only matched functions and re-check
    each file (plus `cc -fsyntax-only`), then write work/specs/<family>/<prefix>_NNN.json.
Prints per-category failure counts.  Results are cached in --work/state.pkl so
the run can be resumed or re-run after generator improvements (--fresh to
discard).  Does not touch git, matching.py or any other repo file.
"""
import argparse, collections, json, os, pickle, re, sys, tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import emit, source, translate
from source import ROOT


def categorize(reason):
    return re.sub(r'(0x)?[0-9A-Fa-f]{6,}|\d+$', '', reason).strip() or 'other'


def translate_all(names, dis, env, variant):
    mode, orient = int(variant[0]), int(variant[1])
    res, fails = {}, {}
    for name, addr, size in names:
        lines = dis.lines(name)
        if not lines:
            fails[addr] = 'nolookup'; continue
        try:
            res[addr] = translate.gen(lines, env, mode, orient)
        except translate.Skip as e:
            fails[addr] = str(e)
        except Exception as e:  # generator bug: keep going, report as category
            fails[addr] = 'EXC ' + type(e).__name__
    return res, fails


def check_chunks(res, addrs, work, tag, chunk, jobs):
    """Verify addrs in files of `chunk`; returns set of matched addresses."""
    groups = [addrs[i:i + chunk] for i in range(0, len(addrs), chunk)]
    def one(ix):
        path = work / f'{tag}_{ix:03d}.c'
        out, maps = emit.run_group(res, groups[ix], path)
        ok, _, _ = emit.parse_check(out)
        n2a = {n: a for n, a in maps}
        return {n2a[n] for n in ok if n in n2a}
    with ThreadPoolExecutor(jobs) as ex:
        return set().union(*ex.map(one, range(len(groups)))) if groups else set()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--max-size', type=lambda x: int(x, 0), default=0x100)
    ap.add_argument('--chunk', type=int, default=200)
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--prefix', default='fk')
    ap.add_argument('--family', default='K')
    ap.add_argument('--out-dir', type=Path, default=ROOT / 'src' / 'xbox360')
    ap.add_argument('--spec-dir', type=Path)
    ap.add_argument('--work', type=Path, default=Path(tempfile.gettempdir()) / 'asm2c-work')
    ap.add_argument('--limit', type=int, default=0, help='only the first N candidates (testing)')
    ap.add_argument('--variants', default='10,20,11,21,00,01')
    ap.add_argument('--skip-addrs', default='', help='file of extra addresses (hex per line) to skip, e.g. ones already matched elsewhere')
    ap.add_argument('--fresh', action='store_true')
    ap.add_argument('--no-final', action='store_true', help='only the verification passes')
    a = ap.parse_args()
    spec_dir = a.spec_dir or ROOT / 'work' / 'specs' / a.family
    a.work.mkdir(parents=True, exist_ok=True)
    state_f = a.work / 'state.pkl'
    state = pickle.load(open(state_f, 'rb')) if state_f.is_file() and not a.fresh else {'matched': {}, 'tried': {}}
    dis = source.Disasm(a.work / 'asm.pkl')
    addr2name = source.symbol_at()
    env = translate.Env(lambda s: dis.lines(s), addr2name.get)
    exclude = source.parse_exclude()
    if a.skip_addrs:
        exclude[0].update(int(x, 16) for x in Path(a.skip_addrs).read_text().split())
    cands = source.candidates(a.max_size, exclude=exclude)
    if a.limit: cands = cands[:a.limit]
    print(f'{len(cands)} candidates, {sum(c[2] for c in cands):#x} bytes', flush=True)
    matched = state['matched']  # addr -> result dict
    lastfail = {}
    for v in a.variants.split(','):
        todo = [c for c in cands if c[1] not in matched and v not in state['tried'].get(c[1], ())]
        res, fails = translate_all(todo, dis, env, v)
        for ad in res: state['tried'].setdefault(ad, set()).add(v)
        for ad in fails: state['tried'].setdefault(ad, set()).add(v)
        lastfail.update({ad: ('translate', r) for ad, r in fails.items()})
        for ad in res: lastfail[ad] = ('nomatch', 'generated but != original')
        ok = check_chunks(res, sorted(res), a.work, f'v{v}', a.chunk, a.jobs)
        for ad in ok: matched[ad] = res[ad]; lastfail.pop(ad, None)
        print(f'variant {v}: translated {len(res)}, matched {len(ok)} (total {len(matched)})', flush=True)
        dis.save(); pickle.dump(state, open(state_f, 'wb'))
    if not a.no_final:
        addrs = sorted(matched)
        spec_dir.mkdir(parents=True, exist_ok=True)
        tot = tbytes = 0
        sizes = {c[1]: c[2] for c in cands}
        pending = addrs
        idx = 0
        while pending:
            group, pending = pending[:a.chunk], pending[a.chunk:]
            stem = f'{a.prefix}_{idx:03d}'; path = a.out_dir / f'{stem}.c'
            out, maps = emit.run_group(matched, group, path)
            ok, bad, ren = emit.parse_check(out)
            n2a = dict(maps)
            dropped = [x for x in group if x not in n2a.values()]
            if bad or dropped:
                # keep only verified functions, rebuild and re-verify; functions dropped
                # for prototype conflicts go to the next file
                keep = [n2a[n] for n in ok if n in n2a]
                pending = [x for x in dropped if x not in keep] + pending
                out, maps = emit.run_group(matched, keep, path)
                ok, bad, ren = emit.parse_check(out); n2a = dict(maps)
            if not ok:
                path.unlink(missing_ok=True); continue
            cc, err = emit.cc_ok(path)
            if not cc: print('CC FAIL', path, err[:400])
            funcs = {n: f'0x{n2a[n]:08X}' for n in ok}
            json.dump({'source': f'src/xbox360/{stem}.c', 'flags': [], 'functions': funcs, 'renames': ren},
                      open(spec_dir / f'{stem}.json', 'w'), indent=1)
            tot += len(ok); tbytes += sum(sizes[n2a[n]] for n in ok)
            print(f'{path.name}: {len(ok)}/{len(maps)} MATCH, bad {len(bad)}, cc {"ok" if cc else "FAIL"}', flush=True)
            idx += 1
        print(f'FINAL matched {tot} functions, {tbytes} bytes')
    cat = collections.Counter(categorize(r) if k == 'translate' else 'GENERATED-NOMATCH'
                              for ad, (k, r) in lastfail.items())
    print('failure categories:')
    for k, n in cat.most_common(): print(f'  {n:6d}  {k}')


if __name__ == '__main__':
    main()
