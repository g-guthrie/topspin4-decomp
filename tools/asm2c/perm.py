#!/usr/bin/env python3
"""Batched permutation search for near misses of the generator.

    python3 tools/asm2c/perm.py --work work/k5 [--max-diff 4] [--rounds 30] [--chunk 150] [--jobs 3]

Takes the near misses that `run.py` recorded in --work/state.pkl (translations that
compile to the target's size and relocation layout but differ in a few instructions)
and mutates each function's C text: statement swaps, commutative operand swaps,
signed/unsigned types of temporaries and parameters, `volatile` on one access,
if/else inversion, inlining a single-use temporary or introducing one for a load,
and declaration order.  Unlike tools/permute.py (one compile per candidate, markup
in a hand-written file) every round puts one candidate of *every* active function
into shared files, so one fn_check run scores ~150 functions.  A function keeps the
best variant so far (equal scores are accepted, so the search can walk plateaus)
and is dropped after --patience rounds without improvement.

State (--work/perm.pkl): per address the best (result, score) and the digests
tried; matches go to state['perm_matched'] {addr: (result, flagset)} and are merged
into state.pkl's 'matched' by `--merge` (run it while no run.py is active).
"""
import argparse, hashlib, pickle, random, re, sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import emit, run  # noqa: E402

OPS = [' + ', ' * ', ' & ', ' | ', ' ^ ', ' == ', ' != ']
REL = {' < ': ' > ', ' > ': ' < ', ' <= ': ' >= ', ' >= ': ' <= '}


def enclosing(s, i):
    """(open, close) indices of the innermost parentheses around position i, or None."""
    d = 0
    for o in range(i - 1, -1, -1):
        if s[o] == ')':
            d += 1
        elif s[o] == '(':
            if d == 0:
                break
            d -= 1
    else:
        return None
    d = 0
    for c in range(i, len(s)):
        if s[c] == '(':
            d += 1
        elif s[c] == ')':
            if d == 0:
                return o, c
            d -= 1
    return None


def top_level(s, a, b, i):
    """True when position i of s[a+1:b] is at parenthesis depth 0 (relative to a)."""
    d = 0
    for k in range(a + 1, i):
        if s[k] == '(':
            d += 1
        elif s[k] == ')':
            d -= 1
    return d == 0


def binop_sites(s):
    """[(open, op index, op, close)] of parenthesised binary expressions `(X op Y)`
    whose operator is the only depth-0 operator inside the parentheses."""
    out = []
    for op in OPS + list(REL):
        st = 0
        while True:
            i = s.find(op, st)
            if i < 0:
                break
            st = i + 1
            e = enclosing(s, i)
            if not e:
                continue
            o, c = e
            if not top_level(s, o, c, i):
                continue
            inner = s[o + 1:c]
            if sum(1 for q in OPS + list(REL) + [' - ', ' && ', ' || ', ' ? ', ' / ', ' << ', ' >> ']
                   for m in re.finditer(re.escape(q), inner) if top_level(s, o, c, o + 1 + m.start())) != 1:
                continue
            # a cast directly before "(X op Y)" applies to the whole: fine; a cast inside X is part of X
            out.append((o, i, op, c))
    return out


def m_commute(body, sig, rng):
    lines = body.split('\n')
    sites = [(k, x) for k, l in enumerate(lines) for x in binop_sites(l)]
    if not sites:
        return None
    k, (o, i, op, c) = rng.choice(sites)
    s = lines[k]
    a, b = s[o + 1:i], s[i + len(op):c]
    lines[k] = s[:o + 1] + b + REL.get(op, op) + a + s[c:]
    return '\n'.join(lines), sig


DECL = re.compile(r'^    ((?:unsigned |signed )?\w+) (\w+)(\[\d+\])?;$')


def m_retype(body, sig, rng):
    lines = body.split('\n')
    cands = [k for k, l in enumerate(lines) if (m := DECL.match(l)) and not m.group(3)
             and m.group(1) in ('ts4_word', 'int', 'unsigned char', 'signed char', 'unsigned short', 'short')]
    pm = [m for m in re.finditer(r'\b(ts4_word|int) (a\d+)\b', sig)]
    total = len(cands) + len(pm)
    if not total:
        return None
    j = rng.randrange(total)
    alt = {'ts4_word': ['int', 'short', 'unsigned short', 'unsigned char', 'signed char'], 'int': ['ts4_word'],
           'unsigned char': ['signed char', 'ts4_word', 'int'], 'signed char': ['unsigned char', 'int'],
           'unsigned short': ['short', 'ts4_word', 'int'], 'short': ['unsigned short', 'int']}
    if j < len(cands):
        k = cands[j]
        m = DECL.match(lines[k])
        t = rng.choice(alt[m.group(1)][:2] if m.group(1) == 'ts4_word' else alt[m.group(1)])
        lines[k] = f'    {t} {m.group(2)};'
        return '\n'.join(lines), sig
    m = pm[j - len(cands)]
    t = 'int' if m.group(1) == 'ts4_word' else 'ts4_word'
    return body, sig[:m.start()] + f'{t} {m.group(2)}' + sig[m.end():]


def m_volatile(body, sig, rng):
    sites = [m.start() for m in re.finditer(r'\*\((?!volatile)(?:unsigned |signed )?\w+ \*\)', body)]
    if not sites:
        return None
    i = rng.choice(sites)
    return body[:i + 2] + 'volatile ' + body[i + 2:], sig


def stmt_lines(lines):
    """Indices of simple statements (no declarations, braces, returns, blank lines)."""
    first = next((k for k, l in enumerate(lines) if l.strip() and not DECL.match(l)), len(lines))
    return [k for k in range(first, len(lines)) if lines[k].rstrip().endswith(';')
            and not lines[k].strip().startswith(('return', 'break', 'continue', '}'))
            and '{' not in lines[k] and '}' not in lines[k]]


def m_swap(body, sig, rng):
    lines = body.split('\n')
    sl = set(stmt_lines(lines))
    pairs = [k for k in sl if k + 1 in sl and len(lines[k]) - len(lines[k].lstrip()) ==
             len(lines[k + 1]) - len(lines[k + 1].lstrip())]
    if not pairs:
        return None
    k = rng.choice(pairs)
    a, b = lines[k], lines[k + 1]
    # do not move a statement across one that assigns a name it uses
    ma, mb = re.match(r'\s*(\w+) = ', a), re.match(r'\s*(\w+) = ', b)
    if ma and re.search(r'\b' + ma.group(1) + r'\b', b) or mb and re.search(r'\b' + mb.group(1) + r'\b', a):
        return None
    lines[k], lines[k + 1] = b, a
    return '\n'.join(lines), sig


def m_declswap(body, sig, rng):
    lines = body.split('\n')
    ds = [k for k, l in enumerate(lines) if DECL.match(l)]
    pairs = [k for k in ds if k + 1 in ds]
    if not pairs:
        return None
    k = rng.choice(pairs)
    lines[k], lines[k + 1] = lines[k + 1], lines[k]
    return '\n'.join(lines), sig


def block_end(lines, k):
    """Index of the line closing the block opened at line k (same indentation `}`...)."""
    ind = len(lines[k]) - len(lines[k].lstrip())
    for j in range(k + 1, len(lines)):
        l = lines[j]
        if len(l) - len(l.lstrip()) == ind and l.strip().startswith('}'):
            return j
    return None


def m_ifinvert(body, sig, rng):
    lines = body.split('\n')
    cands = []
    for k, l in enumerate(lines):
        m = re.match(r'^(\s*)if \((.*)\) \{$', l)
        if m:
            e = block_end(lines, k)
            if e is not None and lines[e].strip() == '} else {':
                e2 = block_end(lines, e)
                if e2 is not None and lines[e2].strip() == '}':
                    cands.append((k, e, e2, m.group(1), m.group(2)))
    if not cands:
        return None
    k, e, e2, ind, c = rng.choice(cands)
    nc = c[2:-1] if c.startswith('!(') and c.endswith(')') and enclosing(c, 2) == (1, len(c) - 1) else f'!({c})'
    new = lines[:k] + [f'{ind}if ({nc}) {{'] + lines[e + 1:e2] + [f'{ind}}} else {{'] + lines[k + 1:e] + [f'{ind}}}'] + lines[e2 + 1:]
    return '\n'.join(new), sig


def m_inline(body, sig, rng):
    """Inline a temporary that is assigned once (simple statement) and used once."""
    lines = body.split('\n')
    cands = []
    for k, l in enumerate(lines):
        m = DECL.match(l)
        if not m or m.group(3) or not re.fullmatch(r't\d+', m.group(2)):
            continue
        n = m.group(2)
        uses = [j for j, x in enumerate(lines) if j != k and re.search(r'\b' + n + r'\b', x)]
        if len(uses) != 2:
            continue
        a = [j for j in uses if re.match(r'^\s*' + n + r' = ', lines[j])]
        if len(a) != 1:
            continue
        u = [j for j in uses if j != a[0]][0]
        if u <= a[0] or len(re.findall(r'\b' + n + r'\b', lines[u])) != 1:
            continue
        rhs = re.match(r'^\s*' + n + r' = (.*);$', lines[a[0]]).group(1)
        if '(' in rhs and re.search(r'\w\(', rhs) and u != a[0] + 1:
            continue        # a call: only into the next statement
        cands.append((k, a[0], u, n, rhs))
    if not cands:
        return None
    k, a, u, n, rhs = rng.choice(cands)
    lines[u] = re.sub(r'\b' + n + r'\b', lambda _: f'({rhs})', lines[u])
    del lines[a]
    del lines[k]
    return '\n'.join(lines), sig


def m_temp(body, sig, rng):
    """Load an inlined memory access into a new temporary before its statement."""
    lines = body.split('\n')
    sl = stmt_lines(lines)
    sites = []
    for k in sl:
        for m in re.finditer(r'\(\*\((?:volatile )?((?:unsigned |signed )?\w+) \*\)', lines[k]):
            o = m.start()
            d = 0
            for c in range(o, len(lines[k])):
                d += lines[k][c] == '('
                d -= lines[k][c] == ')'
                if d == 0:
                    break
            sites.append((k, o, c, m.group(1)))
    if not sites:
        return None
    k, o, c, t = rng.choice(sites)
    used = {int(x) for x in re.findall(r'\bt(\d+)\b', body)}
    n = f't{max(used | {0}) + 100}'
    ind = lines[k][:len(lines[k]) - len(lines[k].lstrip())]
    expr = lines[k][o:c + 1]
    lines[k] = lines[k][:o] + n + lines[k][c + 1:]
    lines.insert(k, f'{ind}{n} = {expr};')
    first = next((j for j, l in enumerate(lines) if DECL.match(l)), 0)
    lines.insert(first, f'    {t if t != "volatile" else "ts4_word"} {n};')
    return '\n'.join(lines), sig


MUTATIONS = [(m_commute, 3), (m_retype, 3), (m_volatile, 2), (m_swap, 3), (m_ifinvert, 1),
             (m_inline, 2), (m_temp, 2), (m_declswap, 1)]


def mutate(r, rng, steps=1):
    """A copy of result r with 1..steps random mutations of its body/signature (or None)."""
    body, sig = r['body'], r['sig']
    done = 0
    for _ in range(steps * 4):
        f = rng.choices([m for m, w in MUTATIONS], [w for m, w in MUTATIONS])[0]
        x = f(body, sig, rng)
        if x is None:
            continue
        body, sig = x
        done += 1
        if done >= steps:
            break
    if not done:
        return None
    r2 = dict(r)
    r2['body'], r2['sig'] = body, sig
    return r2


def score_of(out, n2a):
    """{addr: score} from fn_check output: 0 = MATCH, differing instructions, 1000 = worse."""
    sc = {}
    for l in out.splitlines():
        m = re.match(r'(MATCH|FAIL) (\S+?):? ', l)
        if not m or m.group(2) not in n2a:
            continue
        a = n2a[m.group(2)]
        if m.group(1) == 'MATCH':
            sc[a] = 0
            continue
        d = re.search(r'(\d+) differing instruction', l)
        sc[a] = int(d.group(1)) if d and 'size' not in l and 'relocation layout' not in l else 1000
    return sc


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--work', type=Path, required=True)
    ap.add_argument('--max-diff', type=int, default=4)
    ap.add_argument('--rounds', type=int, default=30)
    ap.add_argument('--patience', type=int, default=12)
    ap.add_argument('--chunk', type=int, default=150)
    ap.add_argument('--jobs', type=int, default=3)
    ap.add_argument('--seed', type=int, default=1)
    ap.add_argument('--skip-addrs', default='')
    ap.add_argument('--merge', action='store_true', help='copy perm matches into state.pkl and exit')
    a = ap.parse_args()
    pf = a.work / 'perm.pkl'
    ps = pickle.load(open(pf, 'rb')) if pf.is_file() else {}
    ps.setdefault('best', {}); ps.setdefault('tried', {}); ps.setdefault('perm_matched', {}); ps.setdefault('stale', {})
    state = pickle.load(open(a.work / 'state.pkl', 'rb'))
    if a.merge:
        state['matched'].update(ps['perm_matched'])
        pickle.dump(state, open(a.work / 'state.pkl', 'wb'))
        print(f'merged {len(ps["perm_matched"])} permutation matches')
        return
    skip = set()
    if a.skip_addrs:
        skip = {int(x, 16) for x in Path(a.skip_addrs).read_text().split()}
    for ad, (nd, fs, r) in state.get('near', {}).items():
        if nd <= a.max_diff and ad not in state['matched'] and ad not in ps['perm_matched'] and ad not in skip:
            if ad not in ps['best'] or ps['best'][ad][1] > nd:
                ps['best'][ad] = (r, nd, fs)
    rng = random.Random(a.seed)
    active = [ad for ad in ps['best'] if ad not in ps['perm_matched'] and ps['stale'].get(ad, 0) < a.patience]
    print(f'{len(active)} active near misses', flush=True)
    for rnd in range(a.rounds):
        active = [ad for ad in active if ad not in ps['perm_matched'] and ps['stale'].get(ad, 0) < a.patience]
        if not active:
            break
        cand = {}
        for ad in active:
            r, sc, fs = ps['best'][ad]
            for _ in range(6):
                r2 = mutate(r, rng, steps=1 if rng.random() < 0.7 else 2)
                if r2 is None:
                    continue
                d = run.digest(r2)
                if d in ps['tried'].setdefault(ad, set()):
                    continue
                ps['tried'][ad].add(d); cand[ad] = (r2, fs)
                break
            else:
                ps['stale'][ad] = ps['stale'].get(ad, 0) + 1
        groups = []
        for fs in sorted({fs for r2, fs in cand.values()}):
            sel = sorted(ad for ad, (r2, f) in cand.items() if f == fs)
            groups += [(fs, sel[i:i + a.chunk]) for i in range(0, len(sel), a.chunk)]

        def one(ix):
            fs, grp = groups[ix]
            res = {ad: cand[ad][0] for ad in grp}
            path = a.work / f'perm_{ix:03d}.c'
            out, maps = emit.run_group(res, grp, path, flags=run.FLAGSETS[fs])
            return score_of(out, {n: ad for n, ad in maps})
        with ThreadPoolExecutor(a.jobs) as ex:
            scores = {}
            for sc in ex.map(one, range(len(groups))):
                scores.update(sc)
        nm = imp = 0
        for ad, (r2, fs) in cand.items():
            sc = scores.get(ad, 1000)
            old = ps['best'][ad][1]
            if sc == 0:
                ps['perm_matched'][ad] = (r2, fs); nm += 1
            elif sc < old:
                ps['best'][ad] = (r2, sc, fs); ps['stale'][ad] = 0; imp += 1
            else:
                if sc == old and rng.random() < 0.5:
                    ps['best'][ad] = (r2, sc, fs)       # plateau move
                ps['stale'][ad] = ps['stale'].get(ad, 0) + 1
        pickle.dump(ps, open(pf, 'wb'))
        print(f'round {rnd}: {len(cand)} candidates, {nm} matched, {imp} improved, '
              f'total perm matches {len(ps["perm_matched"])}', flush=True)


if __name__ == '__main__':
    main()
