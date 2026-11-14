#!/usr/bin/env python3
"""Classify why translated candidates do not match (measurement aid).

    python3 tools/asm2c/diag.py WORKDIR [--flags O1] [--json out.json]

Re-runs tools/fn_check.py over every scratch file `WORKDIR/v*.c` written by
run.py (one flag set at a time: files named v<variant><flagset>_NNN.c) and, for
each failing function, records: candidate / target size, `stwu` frame size of
both, whether the relocation layout agrees, the differing-instruction count and
the first differing offset.  Prints a summary table of
  frame-equal / frame-diff / size-equal (near miss) counts per variant.
For each address the best candidate (same frame first, then smallest size
difference, then fewest differing instructions) is kept in --json.
"""
import argparse, json, re, subprocess, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from source import ROOT

FAIL = re.compile(r'^FAIL (\S+) vs (\S+) @ ([0-9A-F]{8}): (.*)$')
MATCH = re.compile(r'^MATCH (\S+)')


def parse_listing(block):
    """Split a fn_check side-by-side listing into (target lines, candidate lines)."""
    t, c = [], []
    hdr = block[0] if block else ''
    cut = hdr.find('CANDIDATE')
    for ln in block[1:]:
        if cut < 0:
            break
        t.append(ln[:cut].rstrip()); c.append(ln[cut:].rstrip())
    return [x for x in t if x.strip()], [x for x in c if x.strip()]


def frame(lines):
    for ln in lines[:16]:
        m = re.search(r'\bstwu\s+r1,\s*-(\w+)\(r1\)', ln)
        if m:
            return int(m.group(1), 0)
    return 0


def check_file(path, flags):
    text = path.read_text()
    maps = sorted({(n, a) for n, a in re.findall(r'^\w[^\n;]*?\b(ts4_\w+_([0-9A-F]{8}))\([^\n;]*$', text, re.M)})
    if not maps:
        return []
    args = [f'{n}=0x{a}' for n, a in maps]
    if flags:
        args += ['--flags', *flags]
    p = subprocess.run([sys.executable, str(ROOT / 'tools' / 'fn_check.py'), str(path), *args],
                       capture_output=True, text=True, cwd=ROOT)
    out = p.stdout.splitlines()
    res, k = [], 0
    while k < len(out):
        m = FAIL.match(out[k]); mm = MATCH.match(out[k])
        if mm:
            res.append({'addr': int(mm.group(1)[-8:], 16), 'match': True}); k += 1; continue
        if not m:
            k += 1; continue
        j = k + 1
        while j < len(out) and out[j].startswith('  '):
            j += 1
        t, c = parse_listing([l[2:] for l in out[k + 1:j]])
        prob = m.group(4)
        d = re.search(r'(\d+) differing instruction\(s\), first at \+(0x[0-9a-f]+)', prob)
        res.append({'addr': int(m.group(3), 16), 'match': False, 'tsize': 4 * len(t), 'csize': 4 * len(c),
                    'tframe': frame(t), 'cframe': frame(c), 'reloc': 'relocation layout' not in prob,
                    'ndiff': int(d.group(1)) if d else 0, 'first': int(d.group(2), 16) if d else -1,
                    'file': path.name})
        k = j
    return res


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('work', type=Path)
    ap.add_argument('--flags', default='', help="'' or O1")
    ap.add_argument('--json', type=Path)
    ap.add_argument('--jobs', type=int, default=4)
    a = ap.parse_args()
    fl = ['/O1'] if a.flags == 'O1' else []
    files = sorted(p for p in a.work.glob('v*.c') if re.fullmatch(r'v\w+?' + a.flags + r'_\d+\.c', p.name)
                   and (a.flags or not re.fullmatch(r'v\w+?O1_\d+\.c', p.name)))
    with ThreadPoolExecutor(a.jobs) as ex:
        allres = [r for rs in ex.map(lambda p: check_file(p, fl), files) for r in rs]
    best = {}
    key = lambda r: (r['tframe'] != r['cframe'], abs(r['csize'] - r['tsize']), not r['reloc'], r['ndiff'])
    for r in allres:
        if r['match']:
            best[r['addr']] = r; continue
        b = best.get(r['addr'])
        if b is None or (not b['match'] and key(r) < key(b)):
            best[r['addr']] = r
    n = len(best)
    fe = [r for r in best.values() if not r['match'] and r['tframe'] == r['cframe']]
    se = [r for r in fe if r['tsize'] == r['csize'] and r['reloc']]
    print(f'functions with a candidate: {n}; matched {sum(r["match"] for r in best.values())}; '
          f'same frame {len(fe)}; same frame+size+relocs {len(se)} '
          f'(<=10 diffs {sum(r["ndiff"] <= 10 for r in se)})')
    if a.json:
        a.json.write_text(json.dumps({f'{k:08x}': v for k, v in sorted(best.items())}, indent=0))


if __name__ == '__main__':
    main()
