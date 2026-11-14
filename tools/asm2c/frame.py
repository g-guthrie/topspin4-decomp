"""Stack-frame model: one typed local per stack slot.

translate.py renders stack data as word arrays (`ts4_word loc58[4];`) accessed
through casts.  MSVC 16 lays out a function's locals itself, so declaration order
does not matter; what decides the frame is the set of objects and their sizes.
Measured with tools/asm2c/probe.py (see docs/asm2c-large-functions.md):

  * objects are placed from the bottom of the locals area (0x50 + outgoing
    stack arguments) in order of increasing size, compiler temporaries (8-byte
    int<->float conversion slots, spills) included;
  * among objects of one size the more often used come first; remaining ties
    follow an internal order that neither names nor declaration order change;
  * objects of 16 bytes or more are 16-aligned, smaller ones naturally aligned;
  * the frame is 0x50 + locals + saved registers, rounded up to 16.

So a word array where the original had separate scalars changes the frame twice:
its size moves it in the sort, and every slot counts the uses of the whole array.
`split(body, plan)` rewrites a body so that every slot whose address is never
taken becomes its own scalar of the accessed type, and every address-taken
region becomes one array whose extent is chosen by `plan`:

  plan 'fill'  the region extends to the next object start (translate.py's guess);
  plan 'tight' the region ends after its last accessed byte; later accesses that
               are not reached from the base are separate scalars;
  plan 'word'  like 'tight', but every array of 8 bytes or less becomes scalars too
               (the address was only passed as an out-parameter of one word).

`target_frame(lines)` returns the frame size and the sorted local offsets of the
original, `frame_ok()` compares a compiled candidate with it.
"""
import re

DECL = re.compile(r'^(?P<ind> +)ts4_word (?P<n>locm?[0-9a-f]+)\[(?P<k>\d+)\];$', re.M)
TSIZE = {'ts4_word': 4, 'int': 4, 'float': 4, 'double': 8, 'ts4_u64': 8, 'ts4_s64': 8,
         'unsigned char': 1, 'signed char': 1, 'char': 1, 'unsigned short': 2, 'short': 2}
PFX = {1: 'b', 2: 'h', 4: 's', 8: 'q'}


def _refs(body, n):
    """[(start, end, kind, byte offset, type)] for every reference to array n.
    kind: 'w' word element, 't' typed access, 'a' address."""
    out = []
    for m in re.finditer(r'\*\(((?:volatile )?[\w ]+?) \*\)\(\(char \*\)' + n + r' \+ (\d+)\)', body):
        out.append((m.start(), m.end(), 't', int(m.group(2)), m.group(1).replace('volatile ', '')))
    for m in re.finditer(r'\(\(ts4_word\)' + n + r' \+ (\d+)\)', body):
        out.append((m.start(), m.end(), 'a', int(m.group(1)), None))
    for m in re.finditer(r'(&?)\b' + n + r'\[(\d+)\]', body):
        if body[max(0, m.start() - 9):m.start()] == 'ts4_word ':
            continue      # the declaration
        if any(s <= m.start() < e for s, e, *_ in out):
            continue
        out.append((m.start(), m.end(), 'a' if m.group(1) else 'w', 4 * int(m.group(2)), 'ts4_word'))
    for m in re.finditer(r'(?<![\w\[])' + n + r'\b(?!\[\d+\];)', body):
        if not any(s <= m.start() < e for s, e, *_ in out):
            return None       # an unrecognised use of the bare array name
    return sorted(out)


def _objects(refs, nwords, plan, base):
    """Partition the array's bytes into objects: [(start, size, kind)] with kind 'arr'
    (address taken) or a scalar type."""
    addr = sorted({o for s, e, k, o, t in refs if k == 'a'})
    acc = {}
    for s, e, k, o, t in refs:
        if k != 'a':
            sz = TSIZE.get(t, 4)
            prev = acc.get(o)
            acc[o] = t if prev is None or TSIZE.get(prev, 4) < sz else prev
    objs = []
    starts = sorted(set(addr) | set(acc))
    if plan == 'word':
        # address-taken regions whose only accesses are at the base itself are scalars
        keep = []
        for i, a in enumerate(addr):
            nxt = addr[i + 1] if i + 1 < len(addr) else 4 * nwords
            ins = [o for o in acc if a <= o < nxt]
            if ins in ([], [a]):
                acc.setdefault(a, 'ts4_word')
                continue
            keep.append(a)
        addr = keep
    covered = set()
    for i, a in enumerate(addr):
        nxt_addr = addr[i + 1] if i + 1 < len(addr) else 4 * nwords
        if plan == 'fill':
            end = nxt_addr
        else:
            inside = [o + TSIZE.get(acc[o], 4) for o in acc if a <= o < nxt_addr]
            end = max(inside + [a + 4])
            # accesses right after the base belong to it; stop at the first gap of a word
            cont = a + 4
            for o in sorted(x for x in acc if a <= x < nxt_addr):
                if o > cont:
                    break
                cont = max(cont, o + TSIZE.get(acc[o], 4))
            end = cont if plan in ('tight', 'word') else end
        end = max(end, a + 4)
        objs.append((a, end - a, 'arr'))
        covered |= set(range(a, end))
    for o, t in sorted(acc.items()):
        if o in covered:
            continue
        sz = TSIZE.get(t, 4)
        if o % min(sz, 4) or any(x in covered for x in range(o, o + sz)):
            return None
        objs.append((o, sz, t))
        covered |= set(range(o, o + sz))
    return sorted(objs)


def _name(base, o, kind, size):
    off = base + o
    tag = f'{off:x}' if off >= 0 else f'm{-off:x}'
    if kind == 'arr':
        return f'loc{tag}'
    return f'{PFX[TSIZE.get(kind, 4)]}{tag}'


def _decl(name, kind, size):
    if kind == 'arr':
        return f'ts4_word {name}[{(size + 3) // 4}];'
    t = {'int': 'ts4_word', 'signed char': 'unsigned char', 'char': 'unsigned char', 'short': 'unsigned short',
         'ts4_s64': 'ts4_u64'}.get(kind, kind)
    return f'{t} {name};'


def split(body, plan='tight'):
    """Body with its stack word arrays split into per-slot objects; None when nothing
    changes or a use is not understood."""
    changed = False
    for m in list(DECL.finditer(body)):
        n, k, ind = m.group('n'), int(m.group('k')), m.group('ind')
        base = int(n[3:], 16) if not n.startswith('locm') else -int(n[4:], 16)
        refs = _refs(body, n)
        if refs is None:
            return None
        objs = _objects(refs, k, plan, base)
        if objs is None:
            return None
        if len(objs) == 1 and objs[0][0] == 0 and objs[0][2] == 'arr' and objs[0][1] == 4 * k:
            continue
        names = {o: (_name(base, o, kd, sz), kd, sz) for o, sz, kd in objs}
        if any(re.search(r'\b' + nm + r'\b', body) and nm != n for nm, _, _ in names.values()):
            return None
        def owner(off):
            for o, (nm, kd, sz) in names.items():
                if o <= off < o + sz:
                    return o, nm, kd, sz
            return None
        new, pos = [], 0
        for s, e, kind, off, t in refs:
            ow = owner(off)
            if ow is None:
                return None
            o, nm, kd, sz = ow
            rel = off - o
            amp = body[s:s + 1] == '&'          # `&locX[i]` (else `((ts4_word)locX + k)`)
            if kd == 'arr':
                if kind == 'a':
                    if amp:
                        if rel % 4:
                            return None
                        rep = f'&{nm}[{rel // 4}]'
                    else:
                        rep = f'((ts4_word){nm} + {rel})' if rel else f'((ts4_word){nm})'
                elif kind == 'w' and rel % 4 == 0:
                    rep = f'{nm}[{rel // 4}]'
                else:
                    rep = f'*({t} *)((char *){nm} + {rel})'
            else:
                if kind == 'a':
                    if rel:
                        rep = f'((ts4_word)&{nm} + {rel})' if not amp else None
                        if rep is None:
                            return None
                    else:
                        rep = f'&{nm}' if amp else f'((ts4_word)&{nm})'
                elif rel == 0 and (t == kd or (t in ('ts4_word', 'int') and kd in ('ts4_word', 'int'))
                                   or (t in ('ts4_u64', 'ts4_s64') and kd in ('ts4_u64', 'ts4_s64'))):
                    rep = nm
                else:
                    rep = f'*({t} *)((char *)&{nm} + {rel})'
            new.append(body[pos:s]); new.append(rep); pos = e
        new.append(body[pos:])
        nb = ''.join(new)
        decls = ''.join(f'{ind}{_decl(nm, kd, sz)}\n' for o, (nm, kd, sz) in sorted(names.items()))
        nb = nb.replace(m.group(0) + '\n', decls, 1)
        body = nb; changed = True
    return body if changed else None


# ---- the original's frame ---------------------------------------------------
STWU = re.compile(r'\bstwu\s+r1,\s*-(\w+)\(r1\)')


def target_frame(lines):
    """(frame size, sorted offsets of local accesses and address bases) of a listing."""
    fr = 0
    for ln in lines[:16]:
        m = STWU.search(ln)
        if m:
            fr = int(m.group(1), 0)
            break
    offs = set()
    for ln in lines:
        m = re.search(r'\b(l[bhwfd]\w*|st[bhwf]\w*|std|ld)\s+\w+,\s*(-?\w+)\(r1\)', ln)
        if m and 'stwu' not in ln:
            o = int(m.group(2), 0)
            if 0 <= o < fr:
                offs.add(o)
        m = re.search(r'\baddi\s+r\d+,\s*r1,\s*(-?\w+)', ln)
        if m:
            o = int(m.group(1), 0)
            if 0 <= o < fr:
                offs.add(o)
    return fr, sorted(offs)


def frame_ok(target_lines, cand_lines):
    """True when the candidate has the target's frame size and local offsets."""
    return target_frame(target_lines) == target_frame(cand_lines)


# ---- early frame check --------------------------------------------------------
def compile_frames(res, path, flags=(), cpp=False, tries=6):
    """Compile the results `res` {addr: result} together (one compiler run) and return
    {addr: candidate listing}.  Functions that fail to compile are dropped."""
    import emit, probe
    group = sorted(res)
    for _ in range(tries):
        if not group:
            return {}
        maps, rng = emit.build(res, group, path, cpp)
        text = open(path).read()
        lst, msg = probe.compile_listings(text, flags, 'probe.cpp' if cpp else 'probe.c')
        if lst is not None:
            return {a: lst[n] for n, a in maps if n in lst}
        lines = [int(x) for x in re.findall(r'\((\d+)\) : error', msg)]
        bad = {a for a, (s, e) in rng.items() if any(s <= l <= e for l in lines)}
        if not bad:
            return {}
        group = [a for a in group if a not in bad]
    return {}


def frame_check(res, target_lines, path, flags=()):
    """{addr: (frame matches, candidate (size, offsets), target (size, offsets))} for the
    C results in `res`; `target_lines(addr)` gives the original listing."""
    got = compile_frames(res, path, flags)
    out = {}
    for a, cl in got.items():
        t, c = target_frame(target_lines(a)), target_frame(cl)
        out[a] = (t == c, c, t)
    return out
