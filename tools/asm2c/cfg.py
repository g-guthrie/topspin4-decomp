"""Control-flow helpers for asm2c: basic blocks, dominators, post-dominators,
loop detection and boolean condition trees.  Pure logic, no compiler needed.

A function is a list of `Insn`.  `build_blocks()` cuts it into `Block`s whose
terminator `term` is one of

    ('fall', next)            falls into the next block
    ('jmp', target)           unconditional branch inside the function
    ('cond', mn, cr, T, F)    conditional branch: taken -> T, fall -> F
    ('ret',)                  blr / branch to __restgprlr
    ('tail', sym)             branch to another function
    ('ctr',)                  bctr

Conditional returns (`beqlr`) become `cond` blocks whose taken target is a
synthetic block holding a `ret` (negative id).  Block ids are start addresses.
"""
import re

EXIT = -1  # virtual exit node used by the post-dominator computation

COND_BR = {'beq', 'bne', 'blt', 'bge', 'bgt', 'ble'}


class Skip(Exception):
    """Raised when an instruction/shape is unsupported; str() is the category."""


class Insn:
    """One decoded instruction line from tools/fn_asm.py."""
    __slots__ = ('addr', 'mn', 'ops', 'rk', 'sym', 'tgt', 'ln')

    def __init__(self, addr, mn, ops, rk, sym, tgt, ln):
        self.addr, self.mn, self.ops, self.rk, self.sym, self.tgt, self.ln = addr, mn, ops, rk, sym, tgt, ln


class Block:
    __slots__ = ('id', 'insns', 'term')

    def __init__(self, bid, insns, term):
        self.id, self.insns, self.term = bid, insns, term


def decode(lines, parse):
    """fn_asm lines -> [Insn]; `parse` is translate.parse."""
    out = []
    for ln in lines:
        mn, ops, rk, sym = parse(ln)
        m = re.search(r'->\s*0x([0-9a-f]+)', ln)
        out.append(Insn(int(ln[:8], 16), mn, ops, rk, sym, int(m.group(1), 16) if m else None, ln))
    return out


def _is_condret(mn):
    return mn.endswith('lr') and mn[:-2] in COND_BR


def build_blocks(insns):
    """Cut `insns` into blocks; returns (order, {id: Block}).  Raises Skip on
    branch forms that are not modelled (bdnz, bc, ...)."""
    addrs = {i.addr for i in insns}
    leaders = {insns[0].addr}
    for k, i in enumerate(insns):
        mn = i.mn
        ends = mn in COND_BR or mn in ('b', 'blr', 'bctr') or _is_condret(mn)
        if mn.startswith('b') and not ends and mn not in ('bl', 'bctrl'):
            raise Skip(mn)
        if ends:
            if k + 1 < len(insns):
                leaders.add(insns[k + 1].addr)
            if i.tgt in addrs and mn != 'bl':
                leaders.add(i.tgt)
        if mn in COND_BR or (mn == 'b' and i.rk != 'REL24'):
            if i.tgt is None:
                raise Skip('br target')
    order, blocks = [], {}
    cur = []
    for k, i in enumerate(insns):
        if i.addr in leaders and cur:
            blocks[cur[0].addr] = Block(cur[0].addr, cur, ('fall', i.addr))
            order.append(cur[0].addr)
            cur = []
        cur.append(i)
        mn = i.mn
        term = None
        nxt = insns[k + 1].addr if k + 1 < len(insns) else None
        if mn in COND_BR:
            if i.tgt not in addrs:
                raise Skip('br out')
            if nxt is None:
                raise Skip('noend')
            cr = i.ops[0] if i.ops and i.ops[0].startswith('cr') else 'cr0'
            term = ('cond', mn, cr, i.tgt, nxt)
        elif _is_condret(mn):
            if nxt is None:
                raise Skip('noend')
            cr = i.ops[0] if i.ops and i.ops[0].startswith('cr') else 'cr0'
            term = ('cond', mn[:-2], cr, -i.addr, nxt)
        elif mn == 'b':
            if i.sym and i.sym.startswith('__restgprlr'):
                term = ('ret',)
            elif i.rk == 'REL24' or i.tgt not in addrs:
                if not i.sym:
                    raise Skip('b out')
                term = ('tail', i.sym)
            else:
                term = ('jmp', i.tgt)
        elif mn == 'blr':
            term = ('ret',)
        elif mn == 'bctr':
            term = ('ctr',)
        if term:
            body = cur[:-1]
            blocks[cur[0].addr] = Block(cur[0].addr, body, term)
            order.append(cur[0].addr)
            if term[0] == 'cond' and term[3] < 0:
                blocks[term[3]] = Block(term[3], [], ('ret',))
            cur = []
    if cur:
        raise Skip('noend')
    return order, blocks


def succs(b):
    t = b.term
    if t[0] == 'fall' or t[0] == 'jmp':
        return [t[1]]
    if t[0] == 'cond':
        return [t[3], t[4]]
    return []


def preds_of(blocks):
    p = {b: [] for b in blocks}
    for b, blk in blocks.items():
        for s in succs(blk):
            p[s].append(b)
    return p


def dominators(order, blocks):
    """dom[b] = set of blocks dominating b (entry = order[0])."""
    pr = preds_of(blocks)
    entry = order[0]
    allb = set(blocks)
    dom = {b: set(allb) for b in blocks}
    dom[entry] = {entry}
    changed = True
    while changed:
        changed = False
        for b in blocks:
            if b == entry:
                continue
            ps = [p for p in pr[b] if p in dom]
            if not ps:
                continue
            new = set.intersection(*(dom[p] for p in ps)) | {b}
            if new != dom[b]:
                dom[b] = new
                changed = True
    return dom


def post_dominators(blocks):
    """pdom[b] = set of blocks post-dominating b (EXIT included).  Raises
    Skip('no exit') when a block cannot reach the exit (infinite loop)."""
    allb = set(blocks) | {EXIT}
    pdom = {b: set(allb) for b in blocks}
    pdom[EXIT] = {EXIT}
    changed = True
    while changed:
        changed = False
        for b, blk in blocks.items():
            ss = succs(blk) or [EXIT]
            new = set.intersection(*(pdom[s] for s in ss)) | {b}
            if new != pdom[b]:
                pdom[b] = new
                changed = True
    return pdom


def ipdom(pdom, b):
    """Immediate post-dominator of b (EXIT when only the exit follows)."""
    strict = pdom[b] - {b}
    for p in strict:
        if pdom[p] == strict:
            return p
    return EXIT


def natural_loops(order, blocks):
    """{header: set(blocks in loop)} for every back edge u->h with h dom u."""
    dom = dominators(order, blocks)
    pr = preds_of(blocks)
    loops = {}
    for u, blk in blocks.items():
        for h in succs(blk):
            if h in dom[u]:
                body = loops.setdefault(h, {h})
                stack = [u]
                while stack:
                    x = stack.pop()
                    if x in body:
                        continue
                    body.add(x)
                    stack.extend(pr[x])
    return loops


# ---- condition trees -------------------------------------------------------
# ('c', x, op, y, isfloat) | ('and', a, b) | ('or', a, b) | ('not', a)
NEGOP = {'==': '!=', '!=': '==', '<': '>=', '>=': '<', '>': '<=', '<=': '>'}


def neg(c):
    """Logical negation (De Morgan; float compares keep an explicit `!`)."""
    k = c[0]
    if k == 'c':
        return ('c', c[1], NEGOP[c[2]], c[3], False) if not c[4] else ('not', c)
    if k == 'not':
        return c[1]
    if k == 'and':
        return ('or', neg(c[1]), neg(c[2]))
    return ('and', neg(c[1]), neg(c[2]))


def cstr(c, top=True):
    """Render a condition tree as C."""
    k = c[0]
    if k == 'c':
        return f'{c[1]} {c[2]} {c[3]}'
    if k == 'not':
        return f'!({cstr(c[1])})'
    s = (' && ' if k == 'and' else ' || ').join(cstr(x, False) for x in (c[1], c[2]))
    return s if top else f'({s})'


def fold(tri, get_next, commit=None):
    """Fold short-circuit chains.  `tri` = (cond, A, B) meaning "if cond goto A
    else B".  `get_next(block_id)` returns (cond2, A2, B2) when that block is
    a single-predecessor, side-effect free condition block, else None;
    `commit(block_id)` is called when a block is absorbed.
    Returns (tri, [absorbed block ids])."""
    absorbed = []
    while True:
        e, A, B = tri
        done = True
        for side in ('B', 'A'):
            nid = B if side == 'B' else A
            nx = get_next(nid)
            if nx is None or nid in absorbed:
                continue
            e2, A2, B2 = nx
            if side == 'B':                      # reached when e is false
                if A2 == A:
                    tri = (('or', e, e2), A, B2)
                elif B2 == A:
                    tri = (('or', e, neg(e2)), A, A2)
                else:
                    continue
            else:                                # reached when e is true
                if B2 == B:
                    tri = (('and', e, e2), A2, B)
                elif A2 == B:
                    tri = (('and', e, neg(e2)), B2, B)
                else:
                    continue
            absorbed.append(nid)
            if commit:
                commit(nid)
            done = False
            break
        if done:
            return tri, absorbed
