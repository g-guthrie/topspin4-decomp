#!/usr/bin/env python3
"""CLI: translate every small unnamed function, verify, emit sources + specs.

  python3 tools/asm2c/run.py [--max-size 0x100] [--chunk 200] [--jobs 4]
        [--prefix fk] [--family K] [--work DIR] [--limit N]
        [--variants 10,20,11,21,00,01] [--flagsets ,O1]

Stages
 1. select fn_* .text symbols <= max-size minus work/gen_exclude.txt;
 2. for each compiler flag set (--flagsets: '' = base flags, O1 = /O1; many
    original modules were built with /O1) and each variant (mode,orient)
    translate still-unmatched functions, write scratch .c files of `chunk`
    functions under --work, run tools/fn_check.py once per file, keep MATCHes.
    A variant whose C text equals one already tried for that flag set is skipped;
 3. write src/xbox360/<prefix>[_<flagset>]_NNN.c with only matched functions and
    re-check each file (plus `cc -fsyntax-only`), then write
    work/specs/<family>/<stem>.json ("flags" lists the compiler flags).  Functions
    that call each other are never put in the same file (the compiler would
    inline the callee, and the integrated build would no longer match).
Prints per-category failure counts.  Results are cached in --work/state.pkl so
the run can be resumed or re-run after generator improvements (--fresh to
discard).  Does not touch git, matching.py or any other repo file.
"""
import argparse, collections, hashlib, json, os, pickle, re, sys, tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import emit, source, translate
from source import ROOT


FLAGSETS = {'': [], 'O1': ['/O1']}


def categorize(reason):
    return re.sub(r'(0x)?[0-9A-Fa-f]{6,}|\d+$', '', reason).strip() or 'other'


def translate_all(names, dis, env, variant):
    """variant = mode digit, orient digit, then optional letters: u = no signed-type
    inference, v = volatile stores, V = volatile loads and stores, L = volatile loads,
    R = a loop break whose exit only returns is written as that return, J = arms that return
    early still join at their shared tail block, w = void returns and tail calls as statements,
    z = zero word stores (and the store after each) volatile."""
    mode, orient, signed = int(variant[0]), int(variant[1]), 'u' not in variant
    vol = 2 if 'V' in variant else 1 if 'v' in variant else 3 if 'L' in variant else 0
    res, fails = {}, {}
    for name, addr, size in names:
        lines = dis.lines(name)
        if not lines:
            fails[addr] = 'nolookup'; continue
        try:
            res[addr] = translate.gen(lines, env, mode, orient, signed, vol, rbrk='R' in variant, cjoin='J' in variant,
                                       vret='w' in variant, volz='z' in variant)
        except translate.Skip as e:
            fails[addr] = str(e)
        except Exception as e:  # generator bug: keep going, report as category
            fails[addr] = 'EXC ' + type(e).__name__
    return res, fails


def digest(r):
    """Identity of a translation result (variants that render identically are not re-checked).
    Stable across processes (it is stored in the state file), so not `hash()`."""
    key = repr((r['sig'], r['body'], sorted(r['protos'].items()), r.get('vthunk')))
    return hashlib.md5(key.encode()).hexdigest()


def is_cpp(r):
    """vcall thunks are reproduced from C++ (pointer to virtual member), so they go to .cpp files."""
    return 'vthunk' in r


def near_misses(out, n2a):
    """{addr: differing-instruction count} for FAIL lines of a fn_check run whose
    candidate has the target's size and relocation layout (permutation candidates)."""
    res = {}
    for l in out.splitlines():
        m = re.match(r'FAIL (\S+) vs .*?: (.*)$', l)
        if m and m.group(1) in n2a and 'size' not in m.group(2) and 'relocation layout' not in m.group(2):
            d = re.search(r'(\d+) differing instruction', m.group(2))
            if d:
                res[n2a[m.group(1)]] = int(d.group(1))
    return res


def check_chunks(res, addrs, work, tag, chunk, jobs, flags=(), near=None):
    """Verify addrs in files of `chunk` (C and C++ results in separate files);
    returns the set of matched addresses.  `near` (a dict) collects near misses
    {addr: differing-instruction count}."""
    groups = []
    for cpp in (False, True):
        sel = [a for a in addrs if is_cpp(res[a]) == cpp]
        groups += [(cpp, sel[i:i + chunk]) for i in range(0, len(sel), chunk)]
    def one(ix):
        cpp, grp = groups[ix]
        path = work / f'{tag}_{ix:03d}.{"cpp" if cpp else "c"}'
        out, maps = emit.run_group(res, grp, path, flags=flags, cpp=cpp)
        ok, _, _ = emit.parse_check(out)
        n2a = {n: a for n, a in maps}
        if near is not None:
            near.update(near_misses(out, n2a))
        return {n2a[n] for n in ok if n in n2a}
    with ThreadPoolExecutor(jobs) as ex:
        return set().union(*ex.map(one, range(len(groups)))) if groups else set()


def split_files(addrs, matched, a2name, chunk):
    """Distribute functions over files of at most `chunk` functions such that no
    function calls (or is called by) another function of the same file."""
    files = []  # [(members, own names, called names)]
    for a in addrs:
        r = matched[a]
        own = a2name.get(a)
        calls = set(r['protos'])
        for f in files:
            if len(f[0]) < chunk and not (own in f[2]) and not (f[1] & calls):
                f[0].append(a); f[2].update(calls)
                if own: f[1].add(own)
                break
        else:
            files.append(([a], {own} if own else set(), set(calls)))
    return [f[0] for f in files]


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
    ap.add_argument('--variants', default='10,10v,10V,10L,20,20v,20V,11,10u', help='mode+orient digits; u = no signed-type inference, v/V/L = volatile stores / loads+stores / loads')
    ap.add_argument('--flagsets', default=',O1', help='comma list of compiler flag sets: "" (base), O1')
    ap.add_argument('--skip-addrs', default='', help='file of extra addresses (hex per line) to skip, e.g. ones already matched elsewhere')
    ap.add_argument('--only-addrs', default='', help='file of addresses (hex per line): verification passes try only these')
    ap.add_argument('--fresh', action='store_true')
    ap.add_argument('--no-final', action='store_true', help='only the verification passes')
    ap.add_argument('--final-only', action='store_true', help='skip the verification passes, only write files for the cached matches')
    a = ap.parse_args()
    spec_dir = a.spec_dir or ROOT / 'work' / 'specs' / a.family
    a.work.mkdir(parents=True, exist_ok=True)
    state_f = a.work / 'state.pkl'
    state = pickle.load(open(state_f, 'rb')) if state_f.is_file() and not a.fresh else {}
    state.setdefault('matched', {}); state.setdefault('tried', {})  # addr -> (result, flagset) / {(flagset, digest)}
    dis = source.Disasm(a.work / 'asm.pkl')
    addr2name = source.symbol_at()
    env = translate.Env(lambda s: dis.lines(s), addr2name.get)
    exclude = source.parse_exclude()
    if a.skip_addrs:
        exclude[0].update(int(x, 16) for x in Path(a.skip_addrs).read_text().split())
    cands = source.candidates(a.max_size, exclude=exclude)
    if a.limit: cands = cands[:a.limit]
    only = {int(x, 16) for x in Path(a.only_addrs).read_text().split()} if a.only_addrs else None
    print(f'{len(cands)} candidates, {sum(c[2] for c in cands):#x} bytes', flush=True)
    matched = state['matched']
    lastfail = {}
    for fs in ([] if a.final_only else a.flagsets.split(',')):
        flags = FLAGSETS[fs]
        for v in a.variants.split(','):
            todo = [c for c in cands if c[1] not in matched and (only is None or c[1] in only)]
            res, fails = translate_all(todo, dis, env, v)
            lastfail.update({ad: ('translate', r) for ad, r in fails.items() if lastfail.get(ad, ('translate',))[0] == 'translate'})
            fresh = {}
            for ad, r in res.items():
                lastfail[ad] = ('nomatch', 'generated but != original')
                key = (fs, digest(r))
                if key not in state['tried'].setdefault(ad, set()):
                    state['tried'][ad].add(key); fresh[ad] = r
            near = {}
            ok = check_chunks(fresh, sorted(fresh), a.work, f'v{v}{fs}', a.chunk, a.jobs, flags, near)
            nm = state.setdefault('near', {})   # addr -> (differing instructions, flag set, result)
            for ad, nd in near.items():
                if ad not in nm or nd < nm[ad][0]:
                    nm[ad] = (nd, fs, fresh[ad])
            for ad in ok: matched[ad] = (fresh[ad], fs); lastfail.pop(ad, None)
            print(f'flags {fs or "base"} variant {v}: translated {len(res)}, new texts {len(fresh)}, '
                  f'matched {len(ok)} (total {len(matched)})', flush=True)
            dis.save(); pickle.dump(state, open(state_f, 'wb'))
    if not a.no_final:
        sizes = {c[1]: c[2] for c in cands}
        # functions renamed since they were matched (by other families) cannot be looked up any more
        gone = [ad for ad in matched if ad not in sizes]
        for ad in gone: del matched[ad]
        if gone: print(f'dropped {len(gone)} matches that are no longer fn_ placeholders')
        spec_dir.mkdir(parents=True, exist_ok=True)
        tot = tbytes = 0
        for fs, cpp in sorted({(f, is_cpp(r)) for r, f in matched.values()}):
            res = {ad: r for ad, (r, f) in matched.items() if f == fs and is_cpp(r) == cpp}
            pending = split_files(sorted(res), res, addr2name, a.chunk)
            for idx, group in enumerate(pending):
                tag = ('cpp_' if cpp else '') + (fs.lower() + '_' if fs else '')
                stem = f'{a.prefix}_{tag}{idx:03d}'; ext = 'cpp' if cpp else 'c'
                path = a.out_dir / f'{stem}.{ext}'
                out, maps = emit.run_group(res, group, path, flags=FLAGSETS[fs], cpp=cpp)
                ok, bad, ren = emit.parse_check(out)
                n2a = dict(maps)
                if bad or len(maps) != len(group):
                    # keep only verified functions, rebuild and re-verify
                    keep = [n2a[n] for n in ok if n in n2a]
                    out, maps = emit.run_group(res, keep, path, flags=FLAGSETS[fs], cpp=cpp)
                    ok, bad, ren = emit.parse_check(out); n2a = dict(maps)
                if not ok:
                    path.unlink(missing_ok=True); continue
                cc, err = emit.cc_ok(path)
                if not cc: print('CC FAIL', path, err[:400])
                funcs = {n: f'0x{n2a[n]:08X}' for n in ok}
                json.dump({'source': f'src/xbox360/{stem}.{ext}', 'flags': FLAGSETS[fs], 'functions': funcs, 'renames': ren},
                          open(spec_dir / f'{stem}.json', 'w'), indent=1)
                tot += len(ok); tbytes += sum(sizes[n2a[n]] for n in ok)
                print(f'{path.name}: {len(ok)}/{len(maps)} MATCH, bad {len(bad)}, cc {"ok" if cc else "FAIL"}', flush=True)
        print(f'FINAL matched {tot} functions, {tbytes} bytes')
    cat = collections.Counter(categorize(r) if k == 'translate' else 'GENERATED-NOMATCH'
                              for ad, (k, r) in lastfail.items())
    print('failure categories:')
    for k, n in cat.most_common(): print(f'  {n:6d}  {k}')


if __name__ == '__main__':
    main()
