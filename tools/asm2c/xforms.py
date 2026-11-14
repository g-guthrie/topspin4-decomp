"""Source-level transforms for near misses (ported from FAM6's work/fam6_drafts/xf.py).

Each `t_*(body, rng)` returns a new function body or None.  They act on the text
that translate.py emits, so the regular expressions follow its spelling
(`(ts4_word)`, `(char *)(ts4_word)(X) + N`, `pN`/`tN` temporaries, `locXX[N]`).

    t_bool      if (c1) p = 1; else { p = 0; if (c2) p = 1; }  ->  b = (c1) || (c2); p = b;
    t_strlen    inline byte-scan loop + (end - start) - 1     ->  strlen(start)
    t_sv        argument of a call site where the target has `clrrwi rK,rX,0`
                -> `*(ts4_sv *)E`, a one-word struct passed by value
    t_compound, t_nz, t_unvol, t_homecopy, t_locsize, t_locperm, t_earlyinv,
    t_cse, t_hoist, t_ldfirst, t_idx, t_stswap, t_strl_cse   (smaller rewrites)

`clr_sites(asm_lines)` computes the (callee, argument index) pairs for t_sv from
the target disassembly.  emit.build adds the strlen declaration and the ts4_sv
typedef when a body uses them.
"""
import itertools, re

_DECL = re.compile(r'^    \w[\w ]* \w+(\[\d+\])?;$')
LOC = re.compile(r'^    (\w[\w ]*?) (loc[0-9a-f]+)\[(\d+)\];$', re.M)


def _pick(v, rng):
    return (rng.choice(v) if rng else v[0]) if v else None


def _first_stmt(lines):
    return next((k for k, l in enumerate(lines) if l.strip() and not _DECL.match(l)), len(lines))


def _add_decl(body, decl):
    lines = body.split('\n')
    j = next((k for k, l in enumerate(lines) if _DECL.match(l)), 0)
    lines.insert(j, decl)
    return '\n'.join(lines)


def _newname(body, p):
    n = 1
    while re.search(r'\b%s%d\b' % (p, n), body):
        n += 1
    return '%s%d' % (p, n)


def _bal(s, i):
    d = 0
    for j in range(i, len(s)):
        if s[j] == '(':
            d += 1
        elif s[j] == ')':
            d -= 1
            if d == 0:
                return j
    return -1


# ---- bool temporary for || / && --------------------------------------------
PAT3 = re.compile(r'^(?P<i>[ ]+)if \((?P<c1>.*)\) \{\n(?P=i)    (?P<pb>p\d+) = \(ts4_word\)(?P<z>[01]);\n(?P=i)\} else \{\n(?P<pre>(?:(?P=i)    t\d+ = [^\n]*;\n)*)(?P=i)    (?P<pa>p\d+) = \(ts4_word\)(?P<x>[01]);\n(?P=i)    if \((?P<c2>.*)\) \{\n(?P=i)        (?P=pa) = \(ts4_word\)(?P<y>[01]);\n(?P=i)    \}\n(?P=i)    (?P=pb) = \(ts4_word\)(?P=pa);\n(?P=i)\}\n', re.M)
PAT4 = re.compile(r'^(?P<i>[ ]+)if \((?P<c1>.*)\) \{\n(?P<pre>(?:(?P=i)    t\d+ = [^\n]*;\n)*)(?P=i)    (?P<pa>p\d+) = \(ts4_word\)(?P<x>[01]);\n(?P=i)    if \((?P<c2>.*)\) \{\n(?P=i)        (?P=pa) = \(ts4_word\)(?P<y>[01]);\n(?P=i)    \}\n(?P=i)    (?P<pb>p\d+) = \(ts4_word\)(?P=pa);\n(?P=i)\} else \{\n(?P=i)    (?P=pb) = \(ts4_word\)(?P<z>[01]);\n(?P=i)\}\n', re.M)


def _inline_pre(pre, c2, rest):
    for m in re.finditer(r'(t\d+) = ([^\n]*);', pre):
        t, e = m.group(1), m.group(2)
        rest2 = re.sub(r'^    [\w ]+ ' + t + r';\n', '', rest, flags=re.M)
        if re.search(r'\b' + t + r'\b', rest2) or len(re.findall(r'\b' + t + r'\b', c2)) != 1:
            return None
        c2 = re.sub(r'\b' + t + r'\b', lambda _: '(' + e + ')', c2)
    return c2


def boolx(body, typ='unsigned char', form=0):
    n, decls = [0], []

    def mk(m, swapc1):
        if m['x'] == m['y']:
            return None
        c2 = _inline_pre(m['pre'], m['c2'], body.replace(m.group(0), ''))
        if c2 is None:
            return None
        inner = f'({c2})' if m['y'] == '1' else f'!({c2})'
        c1 = m['c1']
        if not swapc1:
            e = f'({c1}) || {inner}' if m['z'] == '1' else f'!({c1}) && {inner}'
        else:
            e = f'!({c1}) || {inner}' if m['z'] == '1' else f'({c1}) && {inner}'
        b = f'b{80 + n[0]}'
        n[0] += 1
        decls.append(f'    {typ} {b};')
        rhs = f'({typ})({e})' if form == 1 else e
        return f'{m["i"]}{b} = {rhs};\n{m["i"]}{m["pb"]} = (ts4_word){b};\n'
    out = body
    for pat, sw in ((PAT3, False), (PAT4, True)):
        out = pat.sub(lambda m: mk(m, sw) or m.group(0), out)
    if out == body:
        return None
    for d in decls:
        out = _add_decl(out, d)
    for v in set(re.findall(r'^    ts4_word ([pt]\d+);$', out, re.M)):
        if len(re.findall(r'\b' + v + r'\b', out)) == 1:
            out = re.sub(r'^    ts4_word ' + v + r';\n', '', out, flags=re.M)
    return out


def t_bool(b, rng=None):
    return boolx(b, rng.choice(['unsigned char', 'int']) if rng else 'unsigned char', rng.choice([0, 1]) if rng else 0)


# ---- strlen ----------------------------------------------------------------
_SL = re.compile(r'(?P<ind>[ \t]*)do \{\n\s*(?P<t>\w+) = \*\((?:volatile )?(?:unsigned |signed )?char \*\)\((?:\(char \*\)\(ts4_word\)\((?P<lv>\w+)\) \+ 0|0 \+ \(char \*\)\(ts4_word\)\((?P<lv2>\w+)\))\);\n\s*(?P<p>\w+) = \(ts4_word\)\((?:(?P<lv3>\w+) \+ 1|1 \+ (?P<lv4>\w+))\);\n\s*(?P<lv5>\w+) = (?P=p);\n\s*\} while \(\((?:ts4_word|int)\)(?P=t) != 0\);\n')


def _rest(nb):
    return nb.split('\n\n', 1)[1] if '\n\n' in nb else nb


def t_strlen(b, rng=None):
    for m in _SL.finditer(b):
        lv = m.group('lv') or m.group('lv2')
        if not (lv == (m.group('lv3') or m.group('lv4')) == m.group('lv5')):
            continue
        pre = b[:m.start()]
        mi = list(re.finditer(r'^[ \t]*' + lv + r' = \(ts4_word\)\(?(\w+)\)?;\n', pre, re.M))
        if not mi:
            continue
        x = mi[-1].group(1)
        post = b[m.end():]
        e = re.compile(r'\(\(\(' + lv + ' - ' + x + r'\) \+ -1\)(?: & 0xffffffff)?\)|\(\(' + lv + ' - ' + x + r'\) \+ -1\)')
        if not e.search(post):
            continue
        nb = pre[:mi[-1].start()] + pre[mi[-1].end():] + e.sub('(ts4_word)strlen((const char *)' + x + ')', post)
        nb = re.sub(r'^    ts4_word ' + lv + r';\n', '', nb, flags=re.M)
        if re.search(r'\b' + lv + r'\b', nb):
            continue
        for v in (m.group('t'), m.group('p')):
            if not re.search(r'\b' + v + r'\b', _rest(nb)):
                nb = re.sub(r'^    [\w ]+ ' + v + r';\n', '', nb, flags=re.M)
        return nb
    return None


def t_strl_cse(b, rng=None):
    m = re.search(r'^([ \t]*)(\w+) = \(ts4_word\)(\(ts4_word\)strlen\(\(const char \*\)\w+\));$', b, re.M)
    if not m:
        return None
    head, tail = b[:m.end()], b[m.end():]
    if m.group(3) not in tail:
        return None
    return head + tail.replace(m.group(3), m.group(2))


# ---- one-word struct argument (clrrwi rK,rX,0 before a call) ---------------
def clr_sites(lines):
    """[(callee symbol, argument index)] for call sites whose argument register is
    produced by `clrrwi rK,rX,0` (directly or through one `mr`) in the target."""
    out = []
    for k, l in enumerate(lines):
        m = re.search(r'\bclrrwi r(\d+), r\d+, 0$', l)
        if not m:
            continue
        regs = {int(m.group(1))}
        for l2 in lines[k + 1:k + 16]:
            mm = re.search(r'\bmr r(\d+), r(\d+)$', l2)
            if mm and int(mm.group(2)) in regs:
                regs.add(int(mm.group(1)))
            if re.search(r'\sbl\s', l2):
                name = l2.split()[-1]
                for r in sorted(regs):
                    if 3 <= r <= 10:
                        out.append((name, r - 3))
                break
            if re.search(r'\s(blr|b|bctr|bctrl)\s', l2 + ' '):
                break
    return list(dict.fromkeys(out))


def _call_args(b, name):
    for m in re.finditer(r'\b' + re.escape(name) + r'\(', b):
        s = m.end() - 1
        e = _bal(b, s)
        if e < 0:
            continue
        spans, d, st = [], 0, s + 1
        for j in range(s + 1, e):
            c = b[j]
            if c == '(':
                d += 1
            elif c == ')':
                d -= 1
            elif c == ',' and d == 0:
                spans.append((st, j))
                st = j + 2
        spans.append((st, e))
        yield s, e, spans


def sv_all(b, sites):
    out = []
    for callee, ix in sites:
        for s, e, spans in _call_args(b, callee):
            if ix >= len(spans):
                continue
            a0, a1 = spans[ix]
            x = re.sub(r'^\(ts4_word\)', '', b[a0:a1])
            x = re.sub(r'^\(0xffffffff & (\w+)\)$', r'\1', x)
            x = re.sub(r'^\(\((.*)\) & 0xffffffff\)$', r'\1', x)
            m = re.fullmatch(r'\(\*\((?:volatile )?ts4_word \*\)(\(.*\))\)', x) or re.fullmatch(r'\*\((?:volatile )?ts4_word \*\)(\(.*\))', x)
            E = m.group(1) if m else None
            if not E and re.fullmatch(r'\w+', x):
                mm = re.search(r'^\s*' + x + r' = \*\((?:volatile )?ts4_word \*\)(\(.*\));$', b, re.M)
                E = mm.group(1) if mm else None
            if E:
                out.append(b[:a0] + f'*(ts4_sv *){E}' + b[a1:])
    return out


# ---- smaller rewrites ------------------------------------------------------
def t_compound(b, rng=None):
    """*(T *)(p + n) = (T)((*(T *)(p + n)) op y)  ->  *(T *)(p + n) op= y"""
    cands = []
    for m in re.finditer(r'^(\s+)(\*\((?:volatile )?[\w ]+ \*\)\(\(char \*\)\(ts4_word\)\(\w+\) \+ \d+\)) = \((?:[\w ]+)\)\((.+)\);$', b, re.M):
        lv, rhs = m.group(2), m.group(3)
        lv0 = lv.replace('volatile ', '')
        for op in '+-|&^':
            for pat in (f'({lv0}) {op} ', f'({lv}) {op} '):
                if rhs.startswith(pat):
                    cands.append((m, op, rhs[len(pat):]))
            for pat in (f' {op} ({lv0})', f' {op} ({lv})'):
                if op in '+|&^' and rhs.endswith(pat):
                    cands.append((m, op, rhs[:-len(pat)]))
    c = _pick(cands, rng)
    if not c:
        return None
    m, op, y = c
    if _bal('(' + y + ')', 0) != len(y) + 1:
        return None
    return b[:m.start()] + f'{m.group(1)}{m.group(2)} {op}= {y};' + b[m.end():]


def t_nz(b, rng=None):
    ms = list(re.finditer(r'if \(\((?:ts4_word|int)\)(\w+) != 0\)', b))
    m = _pick(ms, rng)
    return b[:m.start()] + f'if ({m.group(1)})' + b[m.end():] if m else None


def t_unvol(b, rng=None):
    i = _pick([m.start() for m in re.finditer(r'\*\(volatile ', b)], rng)
    return None if i is None else b[:i + 2] + b[i + 11:]


def t_homecopy(b, rng=None):
    a = _pick(sorted(set(re.findall(r'&(a\d+)\b', b))), rng)
    if not a:
        return None
    n = 'h' + a[1:]
    if re.search(r'\b' + n + r'\b', b):
        return None
    lines = re.sub(r'&' + a + r'\b', '&' + n, b).split('\n')
    lines.insert(_first_stmt(lines), f'    {n} = {a};')
    lines.insert(0, f'    ts4_word {n};')
    return '\n'.join(lines)


def t_locsize(b, rng=None):
    decl = LOC.findall(b)
    d = _pick(decl, rng)
    if not d:
        return None
    t, n, s = d
    ix = [int(x) for x in re.findall(r'\b' + n + r'\[(\d+)\]', b)]
    mn, s = (max(ix) if ix else 0) + 1, int(s)
    z = rng.choice([mn, max(mn, s - 1), max(mn, s - 2), s + 1, s + 2, max(mn, s // 2), s + 4, s + 8, s + 12]) if rng else mn
    if z == s:
        return None
    return re.sub(r'^    ' + re.escape(t) + ' ' + n + r'\[' + str(s) + r'\];$', f'    {t} {n}[{z}];', b, flags=re.M)


def t_locperm(b, rng=None):
    lines = b.split('\n')
    idx = [i for i, l in enumerate(lines) if LOC.match(l)]
    if len(idx) < 2:
        return None
    i, j = rng.sample(idx, 2) if rng else idx[:2]
    lines[i], lines[j] = lines[j], lines[i]
    return '\n'.join(lines)


def t_earlyinv(b, rng=None):
    """if (C) { return R; } REST return Y;  ->  if (!C) { REST return Y; } return R;"""
    lines = b.split('\n')
    sites = [k for k in range(len(lines) - 2) if re.match(r'^    if \((.*)\) \{$', lines[k])
             and re.match(r'^        return [^;]*;$', lines[k + 1]) and lines[k + 2] == '    }']
    k = _pick(sites, rng)
    if k is None:
        return None
    ends = [i for i, l in enumerate(lines) if re.match(r'^    return [^;]*;$', l)]
    if not ends or ends[-1] < k + 3:
        return None
    end = ends[-1]
    c = re.match(r'^    if \((.*)\) \{$', lines[k]).group(1)
    m = re.fullmatch(r'\((ts4_word|int)\)(\w+) == 0', c)
    nc = f'({m.group(1)}){m.group(2)} != 0' if m else f'!({c})'
    inner = ['    ' + l if l else l for l in lines[k + 3:end + 1]]
    return '\n'.join(lines[:k] + [f'    if ({nc}) {{'] + inner + ['    }', lines[k + 1][4:]] + lines[end + 1:])


_ASG = re.compile(r'^(\s+)(\w+) = \((ts4_word|int)\)\((.*)\);$')


def t_cse(b, rng=None):
    """X = f(E); Y = E;  ->  Y = E; X = f(Y);"""
    L = b.split('\n')
    sites = []
    for i in range(len(L) - 1):
        m1, m2 = _ASG.match(L[i]), _ASG.match(L[i + 1])
        if not (m1 and m2) or m1.group(1) != m2.group(1):
            continue
        E = m2.group(4)
        if re.fullmatch(r'\w+', E) or '(' + E + ')' not in m1.group(4) or re.search(r'\b' + m2.group(2) + r'\b', E):
            continue
        if re.search(r'\b' + m1.group(2) + r'\b', E):
            continue
        sites.append(i)
    i = _pick(sites, rng)
    if i is None:
        return None
    m2 = _ASG.match(L[i + 1])
    L[i], L[i + 1] = L[i + 1], L[i].replace('(' + m2.group(4) + ')', '(' + m2.group(2) + ')')
    return '\n'.join(L)


_LD = re.compile(r'\(\*\(ts4_word \*\)\(\(char \*\)\(ts4_word\)\((\w+)\) \+ (\d+)\)\)')
_ST = re.compile(r'^( +)\*\([\w ]+ \*\)\(.*\) = .*;$')


def hoist_all(b):
    """a load common to both arms of an if/else is moved in front of the if"""
    L, res = b.split('\n'), []
    for i, l in enumerate(L):
        m = re.match(r'^( *)if \(.*\) \{$', l)
        if not m:
            continue
        ind = m.group(1)
        j = i + 1
        while j < len(L) and not L[j].startswith(ind + '}'):
            j += 1
        if j >= len(L) or L[j] != ind + '} else {':
            continue
        k = j + 1
        while k < len(L) and L[k] != ind + '}':
            k += 1
        if k >= len(L):
            continue
        A, B = '\n'.join(L[i + 1:j]), '\n'.join(L[j + 1:k])
        cb = {x.group(0) for x in _LD.finditer(B)}
        for e, base in {x.group(0): x.group(1) for x in _LD.finditer(A)}.items():
            if e not in cb or re.search(r'^\s*' + base + r' = ', A + '\n' + B, re.M):
                continue
            if re.search(r'^\s*\*\(.*\) = ', A + '\n' + B, re.M):
                continue     # a store in an arm may alias the load
            h = _newname(b, 'h')
            L2 = list(L)
            for q in range(i + 1, k):
                L2[q] = L2[q].replace(e, h)
            L2.insert(i, ind + f'{h} = {e[1:-1]};')
            res.append(_add_decl('\n'.join(L2), f'    ts4_word {h};'))
    return res


def t_hoist(b, rng=None):
    return _pick(hoist_all(b), rng)


def ldfirst_all(b, cap=12):
    """store S1; S2 reading *(X+n)  ->  h = *(X+n); S1; S2[h]"""
    L, res = b.split('\n'), []
    for i in range(len(L) - 1):
        m = _ST.match(L[i])
        if not m:
            continue
        ind, nx = m.group(1), L[i + 1]
        if not nx.startswith(ind) or nx.startswith(ind + ' '):
            continue
        if nx.strip().startswith(('}', 'if', 'do', 'while', 'return;', 'break', 'continue')):
            continue
        for e in dict.fromkeys(x.group(0) for x in _LD.finditer(nx)):
            if e in L[i]:
                continue
            h = _newname(b, 'h')
            L2 = list(L)
            L2[i + 1] = L2[i + 1].replace(e, h)
            L2.insert(i, ind + f'{h} = {e[1:-1]};')
            res.append(_add_decl('\n'.join(L2), f'    ts4_word {h};'))
            if len(res) >= cap:
                return res
    return res


def t_ldfirst(b, rng=None):
    return _pick(ldfirst_all(b), rng)


def _operand_end(s, i):
    if s[i] == '(':
        return _bal(s, i) + 1
    m = re.match(r'\w+', s[i:])
    return i + m.end() if m else -1


def idx_all(b):
    """swap base and index of `(char *)(ts4_word)(X) + Y` (Y not a constant)"""
    res = []
    for m in re.finditer(r'\(char \*\)\(ts4_word\)\(', b):
        xs = m.end() - 1
        xe = _bal(b, xs)
        X = b[xs + 1:xe]
        if b[xe + 1:xe + 4] == ' + ':
            ys = xe + 4
            ye = _operand_end(b, ys)
            Y = b[ys:ye]
            if ye > ys and not re.fullmatch(r'-?\d+|0x[0-9a-f]+', Y):
                for rep in (f'(char *)(ts4_word)({Y}) + {X}', f'{Y} + (char *)(ts4_word)({X})'):
                    res.append(b[:m.start()] + rep + b[ye:])
    return list(dict.fromkeys(x for x in res if x != b))


def t_idx(b, rng=None):
    return _pick(idx_all(b), rng)


def stswap_all(b):
    L, out = b.split('\n'), []
    for i in range(len(L) - 1):
        m1, m2 = _ST.match(L[i]), _ST.match(L[i + 1])
        if m1 and m2 and m1.group(1) == m2.group(1):
            L2 = list(L)
            L2[i], L2[i + 1] = L2[i + 1], L2[i]
            out.append('\n'.join(L2))
    return out


def t_stswap(b, rng=None):
    return _pick(stswap_all(b), rng)


def ptrtemp_all(b):
    """a parameter offset `(aK + N)` used twice or more becomes a pointer temporary set at
    the start (the compiler then addresses through the temporary: `addi r4,r3,N; lwz 4(r4)`)"""
    out = []
    lines = b.split('\n')
    first = _first_stmt(lines)
    for e in dict.fromkeys(re.findall(r'\((a\d+) \+ (\d+)\)', b)):
        x = f'({e[0]} + {e[1]})'
        if b.count(x) < 2 or re.search(r'^\s*' + e[0] + r' = ', b, re.M):
            continue
        h = _newname(b, 'h')
        L = [l.replace(x, h) for l in lines]
        L.insert(first, f'    {h} = (ts4_word){x};')
        out.append(_add_decl('\n'.join(L), f'    ts4_word {h};'))
    return out


def t_ptrtemp(b, rng=None):
    return _pick(ptrtemp_all(b), rng)


# (transform, weight) for perm.py; t_sv is added there because it needs the target's sites
TRANSFORMS = [(t_bool, 2), (t_strlen, 2), (t_strl_cse, 1), (t_compound, 2), (t_nz, 1), (t_unvol, 2),
              (t_homecopy, 1), (t_locsize, 2), (t_locperm, 2), (t_earlyinv, 2), (t_cse, 2), (t_hoist, 2),
              (t_ldfirst, 3), (t_idx, 3), (t_stswap, 2), (t_ptrtemp, 1)]


def deterministic(b, sites=()):
    """Single-shot rewrites worth trying first on every near miss (one candidate each)."""
    out = []
    for f in (t_strlen, t_strl_cse, t_compound, t_earlyinv, t_cse, t_nz):
        x = f(b)
        if x:
            out.append(x)
    for typ in ('unsigned char', 'int'):
        for form in (0, 1):
            x = boolx(b, typ, form)
            if x:
                out.append(x)
    s = t_strlen(b)
    if s:
        x = t_strl_cse(s)
        out += [x] if x else []
        out += hoist_all(s)[:3] + ldfirst_all(s, 3)
    out += sv_all(b, sites)
    out += ptrtemp_all(b)[:3] + hoist_all(b)[:4] + ldfirst_all(b, 4) + idx_all(b)[:4] + stswap_all(b)[:4]
    return list(dict.fromkeys(x for x in out if x and x != b))
