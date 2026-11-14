"""Core translation: PowerPC disassembly lines -> a C function body.

Input is a list of lines in the `tools/fn_asm.py` format
(``ADDRESS  WORDHEX  mnemonic operands   ; RELOCKIND symbol``).  `gen()` cuts the
function into basic blocks (`cfg.py`), then walks the structure while symbolically
executing it (registers hold C expressions, loads become lazily materialised
locals) and returns a dict ``kind, detail, sig, body, externs, protos`` or raises
`Skip(reason)` when the shape is not supported.  The result is *not* guaranteed to
compile to the same bytes; `emit.py` verifies every candidate with tools/fn_check.py.

Structurizer (class `Gen`)
- a conditional block is folded with following single-use condition blocks into
  `&&` / `||` conditions (`cfg.fold`);
- the join of an if is the immediate post-dominator; arms are emitted in copies
  of the register state and registers they change are merged into phi
  variables (`pN`);  an arm that leaves the function is emitted as an early
  return;
- natural loops become `while` (header tests) or `do ... while` (latch tests);
  registers that are live around the back edge become `lvN` variables.

Variants (all produce the same behaviour, different compiler input): `mode` 1
also counts contiguously-written argument registers after a call setup (callee
arity otherwise comes from `env.arity`), mode 2 counts every argument register
written up to the highest one, `orient` picks which branch arm becomes the `if`
body, `infer_signed` declares values only used in signed compares as `int`,
`vol` makes stores (1), loads and stores (2) or loads (3) volatile to keep their order.
"""
import re

import cfg
from cfg import Skip  # raised when an instruction/shape is unsupported; str() is the category

def parse(ln):
    """Split a fn_asm line into (mnemonic, operands, reloc kind, reloc symbol)."""
    w=ln[20:]
    body=w.split(';')[0].strip(); com=w.split(';',1)[1].strip() if ';' in w else ''
    m=re.match(r'(\S+)\s*(.*)',body)
    mn=m.group(1); ops=[o.strip() for o in m.group(2).split(',')] if m.group(2) else []
    ms=re.search(r'(REFHI|REFLO|REL24|REL14)\s+(\S+)',com)
    return mn,ops,(ms.group(1) if ms else None),(ms.group(2) if ms else None)

UPD={'lwzu': 'lwz', 'lbzu': 'lbz', 'lhzu': 'lhz', 'lhau': 'lha', 'stwu': 'stw', 'stbu': 'stb', 'sthu': 'sth', 'lfsu': 'lfs', 'lfdu': 'lfd', 'stfsu': 'stfs', 'stfdu': 'stfd'}
LD_U={'lwzu', 'lbzu', 'lhzu', 'lhau'}
STORES={'stw','stb','sth','std','stfs','stfd','stwu','sthu','stbu'}

def arity(lines,lookup,written=None,depth=0):
    """Lower bound on the integer argument count of a callee: scan its
    prefix for reads of r3..r10 before they are written. `lookup(sym)` returns
    the callee's lines (for following tail `b` thunks) or None."""
    if written is None: written=set()
    if not lines: return None
    mx=0
    for ln in lines:
        mn,ops,rk,sym=parse(ln)
        if mn in('bl','bctrl','blr','bctr'): break
        if mn=='b':
            if rk=='REL24' and depth<3:
                sub=lookup(sym)
                r=arity(sub,lookup,set(written),depth+1) if sub else None
                if r: mx=max(mx,r)
            break
        regs=[int(r) for o in ops for r in re.findall(r'\br(\d+)\b',o)]
        if mn in STORES or mn.startswith('cmp') or mn in('mtctr','mtlr') or mn.startswith('b'): src=regs; dst=[]
        else: src=regs[1:]; dst=regs[:1]
        for r in src:
            if 3<=r<=10 and r not in written: mx=max(mx,r-2)
        for r in dst: written.add(r)
    return mx

def annotate(lines,env):
    """Add `; REL24 name` to bl/b whose target lies outside the function and
    has no relocation (intra-section calls): the target address is resolved with
    env.sym_at."""
    lo=int(lines[0][:8],16); hi=int(lines[-1][:8],16)
    out=[]
    for ln in lines:
        mn,ops,rk,sym=parse(ln)
        if mn in('bl','b') and rk is None:
            m=re.search(r'->\s*0x([0-9a-f]+)',ln)
            if m:
                tg=int(m.group(1),16)
                if not lo<=tg<=hi:
                    nm=env.sym_at(tg)
                    if nm: ln=f'{ln}   ; REL24 {nm}'
        out.append(ln)
    return out

def farity(lines, lookup=None, depth=0):
    """Number of leading float argument registers f1.. a callee reads before writing them
    (prefix scan up to the first call/branch, following a first call or tail call), 0 when none."""
    if not lines:
        return 0
    written, mx = set(), 0
    for ln in lines:
        mn, ops, rk, sym = parse(ln)
        if mn.startswith('b'):
            if mn in ('bl', 'b') and rk == 'REL24' and lookup and depth < 3 and not sym.startswith('__'):
                sub = farity(lookup(sym), lookup, depth + 1)
                mx = max([mx] + [n for n in range(1, sub + 1) if f'f{n}' not in written])
            if mn == 'bl' and sym and sym.startswith('__savegprlr'):
                continue
            break
        fr = [o for o in ops if re.fullmatch(r'f\d+', o)]
        if not fr:
            continue
        if mn.startswith('stf') or mn.startswith('fcmp'):
            src, dst = fr, []
        else:
            src, dst = fr[1:], fr[:1]
        for f in src:
            n = int(f[1:])
            if 1 <= n <= 8 and f not in written:
                mx = max(mx, n)
        written |= set(dst)
    return mx


class Env:
    """Callee knowledge needed by gen(): arity(sym) -> int | None.
    `lookup(sym)` must return the disassembly lines of a named function or None."""
    def __init__(s,lookup,sym_at=lambda a:None): s.lookup=lookup; s.sym_at=sym_at; s._cache={}
    def farity(s, sym):
        if ('f', sym) not in s._cache:
            s._cache[('f', sym)] = farity(s.lookup(sym), s.lookup)
        return s._cache[('f', sym)]

    def variadic(s, sym):
        """Number of fixed parameters when `sym` homes rK..r10 in its prologue (a `...`
        function), else None."""
        if ('v', sym) not in s._cache:
            L = s.lookup(sym) or []
            regs = set()
            for ln in L[:16]:
                mn, ops, rk, sy = parse(ln)
                if mn == 'stwu':
                    break
                if mn == 'std' and len(ops) == 2:
                    m = re.fullmatch(r'r(\d+)', ops[0]); o = re.fullmatch(r'(0x[0-9a-f]+|\d+)\(r1\)', ops[1])
                    if m and o and 3 <= int(m.group(1)) <= 10 and int(o.group(1), 0) == 0x18 + 8 * (int(m.group(1)) - 3) - 8:
                        regs.add(int(m.group(1)))
            k = min(regs) if regs else None
            s._cache[('v', sym)] = (k - 3) if k is not None and 10 in regs and regs == set(range(k, 11)) else None
        return s._cache[('v', sym)]

    def arity(s,sym):
        if sym not in s._cache:
            L=s.lookup(sym)
            if L: L=annotate(L,s)
            s._cache[sym]=arity(L,lambda x:(annotate(s.lookup(x),s) if s.lookup(x) else None)) if L else None
        return s._cache[sym]

LD = {'ld': ('ts4_u64', 'u64'), 'lwz': ('ts4_word', 'u32'), 'lhz': ('unsigned short', 'u16'), 'lha': ('short', 's16'), 'lbz': ('unsigned char', 'u8')}
ST = {'stw': ('ts4_word', 'u32'), 'sth': ('unsigned short', 'u16'), 'stb': ('unsigned char', 'u8'), 'std': ('ts4_u64', 'u64')}
FLD = {'lfs': ('float', 'f32'), 'lfd': ('double', 'f64')}
FST = {'stfs': ('float', 'f32'), 'stfd': ('double', 'f64')}
IDX_LD = {'lwzx': 'ts4_word', 'lbzx': 'unsigned char', 'lhzx': 'unsigned short', 'lhax': 'short'}
IDX_ST = {'stwx': 'ts4_word', 'stbx': 'unsigned char', 'sthx': 'unsigned short'}
# taken-condition operator per conditional branch mnemonic
BRT = {'beq': '==', 'bne': '!=', 'blt': '<', 'bge': '>=', 'bgt': '>', 'ble': '<='}
# float compares: (operator, negated) so that e.g. `bge` after fcmpu is "!(x < y)"
FBR = {'beq': ('==', False), 'bne': ('==', True), 'blt': ('<', False), 'bge': ('<', True),
       'bgt': ('>', False), 'ble': ('>', True)}
# instructions allowed inside a folded (short-circuit) condition block: no stores, calls or stack traffic
PURE = {'lwz', 'lbz', 'lhz', 'lha', 'lwzx', 'lbzx', 'lhzx', 'li', 'lis', 'mr', 'addi', 'subi', 'add', 'subf',
        'ori', 'slwi', 'srwi', 'clrlwi', 'clrrwi', 'extsb', 'extsh', 'srawi', 'mullw', 'mulli', 'cmpwi', 'cmplwi',
        'cmpw', 'cmplw', 'rlwinm', 'extrwi', 'neg', 'and', 'or', 'xor', 'xori', 'oris', 'addis', 'rotlwi',
        'sraw', 'srw', 'slw', 'cntlzw', 'subfic', 'divw', 'divwu', 'andi.', 'mr.'}
NO_DST = set(STORES) | set(IDX_ST) | {'cmpwi', 'cmplwi', 'cmpw', 'cmplw', 'mtctr', 'mtlr', 'fcmpu', 'fcmpo'}


def unrelocated(lines):
    """True when the original builds an image address from a bare `lis 0x88xx`
    (no REFHI relocation): the split object has no relocations for such code
    (e.g. the 0x88A00000 unit), and tools/fn_check.py compares relocation
    layouts, so no candidate can match it."""
    for l in lines:
        m = re.search(r'\blis\s+r\d+,\s*0x(88[0-9a-f]{2})\s*(;|$)', l[20:])
        if m and 'REFHI' not in l:
            return True
    return False


VBIN = {'vaddfp': '__vaddfp', 'vsubfp': '__vsubfp', 'vmulfp': '__vmulfp', 'vmaxfp': '__vmaxfp', 'vminfp': '__vminfp',
        'vand': '__vand', 'vor': '__vor', 'vxor': '__vxor', 'vmsum3fp': '__vmsum3fp', 'vmsum4fp': '__vmsum4fp',
        'vcmpeqfp': '__vcmpeqfp', 'vcmpgefp': '__vcmpgefp', 'vcmpgtfp': '__vcmpgtfp', 'vmrghw': '__vmrghw',
        'vmrglw': '__vmrglw'}
VUN = {'vrsqrtefp': '__vrsqrtefp', 'vrefp': '__vrefp', 'vrfin': '__vrfin', 'vrfiz': '__vrfiz', 'vrfim': '__vrfim',
       'vrfip': '__vrfip', 'vexptefp': '__vexptefp', 'vlogefp': '__vlogefp'}
VTRI = {'vmaddfp': '__vmaddfp', 'vnmsubfp': '__vnmsubfp', 'vsel': '__vsel', 'vperm': '__vperm'}
VIMM = {'vspltw': '__vspltw', 'vcfsx': '__vcfsx', 'vcfux': '__vcfux', 'vctsxs': '__vctsxs', 'vctuxs': '__vctuxs',
        'vpermwi': '__vpermwi'}


def is_vmx(mn):
    b = mn[:-3] if mn.endswith('128') else mn
    return (b in VBIN or b in VUN or b in VTRI or b in VIMM or b in ('vmr', 'vspltisw', 'vrlimi', 'lvx', 'stvx', 'lvlx', 'lvrx', 'stvlx', 'stvrx')
            or mn in ('lvx128', 'stvx128'))


def vuse_def(ins):
    """(vector registers read, vector registers written) by one instruction."""
    if not is_vmx(ins.mn):
        return [], []
    b = ins.mn[:-3] if ins.mn.endswith('128') else ins.mn
    vs = [o for o in ins.ops if re.fullmatch(r'v\d+', o)]
    if b.startswith('st'):
        return vs, []
    if b == 'vrlimi':
        return vs, vs[:1]
    return vs[1:], vs[:1]


def vec_block_local(blocks, L):
    """True when every vector register written in loop L is, in each block,
    written before it is read: no vector value is carried between iterations."""
    wr = set()
    for b in L:
        for i in blocks[b].insns:
            wr.update(vuse_def(i)[1])
    for b in L:
        seen = set()
        for i in blocks[b].insns:
            u, d = vuse_def(i)
            if any(r in wr and r not in seen for r in u):
                return False
            seen.update(d)
    return True


class V:
    """A lazily materialised local (a load or call result); `used` is set when read."""
    def __init__(s, t, e, n, pure=True):
        s.t = t; s.e = e; s.n = n; s.used = False; s.pure = pure; s.home = None; s.callsym = None


def dst_regs(insns):
    """General registers written by `insns` (calls clobber r3..r12 separately)."""
    out = set()
    for i in insns:
        if i.mn in UPD and not i.ops[1].endswith('(r1)'):
            m = re.search(r'\((r\d+)\)', i.ops[1])
            out.add(m.group(1))
            if i.mn in LD_U:
                out.add(i.ops[0])
            continue
        if i.mn in NO_DST or i.mn.startswith('st') or i.mn.startswith('b') or i.mn.startswith('cmp') or i.mn.startswith('f'):
            if i.mn == 'bl' or i.mn == 'bctrl':
                out.update(f'r{j}' for j in range(3, 13))
            continue
        if i.ops and re.fullmatch(r'r\d+', i.ops[0]):
            out.add(i.ops[0])
    return out


class Gen:
    """One translation: decode, build the CFG, structurize while symbolically
    executing, then render C.  See `gen()`."""

    def __init__(self, lines, env, mode=0, orient=0, word_ret=False, infer_signed=True, vol=0, strict=False):
        self.env, self.mode, self.orient, self.word_ret = env, mode, orient, word_ret
        self.strict = strict; self._live = None
        self.infer_signed = infer_signed
        self.vol = vol
        if unrelocated(lines):
            raise Skip('unrelocated original')
        self.lines = annotate(lines, env)
        self.insns = self.fuse_atomics(cfg.decode(self.lines, parse))
        self.order, self.blocks = cfg.build_blocks(self.insns)
        self.preds = cfg.preds_of(self.blocks)
        self.has_ctr_loop = any(i.mn in ('bdnz', 'bdz') for i in self.insns)
        self.loops = cfg.natural_loops(self.order, self.blocks)
        self.pdom = cfg.post_dominators(self.blocks)
        self.active = []          # loop headers being emitted (innermost last)
        self.exits = []           # exit block of each loop being emitted (None when unknown)
        self.latch = None         # (continue condition, exit block) recorded by a do-while latch
        self.readp = set()
        self._home_structs()
        self._stack_layout()
        self.ntmp = 0
        self.externs = {}; self.protos = {}; self.detail = []; self.kinds = []
        self.ptype = {}; self.fparams = {}; self.phis = []; self.rtypes = {}
        self.fret_func = False; self.fret_pref = False; self.fprotos = {}; self.structs_used = set()
        self.masks = {}       # text of a `subfe r,x,x` mask -> condition under which it is all ones
        self.calls = 0; self.rets = []; self.localnames = []
        self.signed = set(); self.unsigned = set()   # value names compared with signed / unsigned compares
        self.pending = {}
        self.intrinsics = set(); self.nsteps = 0; self.fphis = []
        self.vec = False; self.vparams = set(); self.vdecls = []
        self.has_vmx = any(is_vmx(i.mn) for i in self.insns)

    @staticmethod
    def fuse_atomics(insns):
        """The Xbox 360 interlocked intrinsics
        `mfmsr rA; mtmsrd r13,1; lwarx rO,r0,rP; [addi/subi/add rN,..]; stwcx. rV,r0,rP; mtmsrd rA,1; bne <mfmsr>`
        become one pseudo instruction `ts4atomic kind, rO, rV, rP[, operand]`."""
        out, k = [], 0
        while k < len(insns):
            i = insns[k]
            m = insns[k:k + 8]
            if i.mn == 'mfmsr' and len(m) >= 7 and m[1].mn == 'mtmsrd' and m[2].mn == 'lwarx':
                n = 3 if m[3].mn == 'stwcx.' else 4 if m[4].mn == 'stwcx.' and m[3].mn in ('addi', 'subi', 'add') else 0
                if n and len(m) > n + 2 and m[n + 1].mn == 'mtmsrd' and m[n + 2].mn == 'bne' and m[n + 2].tgt == i.addr:
                    ro, rp = m[2].ops[0], m[2].ops[2]
                    if m[2].ops[1] == 'r0' and m[n].ops[1] == 'r0' and m[n].ops[2] == rp and m[1].ops == ['r13', '1'] \
                            and m[n + 1].ops == [i.ops[0], '1']:
                        rv = m[n].ops[0]
                        if n == 3:
                            ops = ['xchg', ro, rv, rp]
                        else:
                            a = m[3]
                            if a.ops[0] != rv or a.ops[1] != ro:
                                ops = None
                            elif a.mn == 'add':
                                ops = ['add', ro, rv, rp, a.ops[2]]
                            else:
                                d = int(a.ops[2], 0) * (-1 if a.mn == 'subi' else 1)
                                ops = ['inc' if d == 1 else 'dec' if d == -1 else 'addi', ro, rv, rp, str(d)]
                        if ops:
                            out.append(type(i)(i.addr, 'ts4atomic', ops, None, None, None, i.ln))
                            k += n + 3
                            continue
            out.append(i); k += 1
        return out

    # ---- stack locals ------------------------------------------------------
    SZ = {'lwz': 4, 'stw': 4, 'lbz': 1, 'stb': 1, 'lhz': 2, 'lha': 2, 'sth': 2, 'lfs': 4, 'stfs': 4, 'lfd': 8, 'stfd': 8}

    def _home_structs(self):
        """Struct parameters passed by value and address-taken word parameters.

        MSVC spills such argument registers to the caller's parameter area at F+0x10
        (F = frame size, 0 in frameless leaves) and works on the copy in memory.  Layout
        (measured, see docs/agents/codegen-idioms.md): every word parameter takes an 8-byte
        slot; a struct of <= 4 bytes takes a slot (value in the low half, spilled with
        `stw`), an 8-byte struct is 8-aligned, a bigger one 16-aligned.  Registers are
        assigned without gaps: a 12-byte struct after one word is in r4 + the high half of
        r5 but lives at F+0x20.  The parameter list is recovered by enumerating register
        partitions that explain every initial `std`/`stw` of an argument register (fewest
        parameters first; a `lwz`+`rldicr r,x,32,63` re-pass marks a partial last register).
        Sets self.home {K0: (K1, name, nwords)}, self.home_off {stack offset: (name, byte
        offset)}, self.home_reg {reg: (name, index)} and self.home_scalar (names of
        address-taken word parameters)."""
        self.home, self.home_off, self.home_reg, self.home_scalar = {}, {}, {}, set()
        F = 0
        for ln in self.lines[:12]:
            m = re.search(r'\bstwu\s+r1,\s*-(\w+)\(r1\)', ln)
            if m:
                F = int(m.group(1), 0)
        base = F + 0x10
        stores, written = {}, set()          # reg -> (mnemonic, offset)
        for i in self.insns:
            if i.mn in ('std', 'stw') and re.fullmatch(r'r([3-9]|10)', i.ops[0]) and i.ops[0] not in written:
                m = re.fullmatch(r'(\w+)\(r1\)', i.ops[1])
                if m and base <= int(m.group(1), 0) < base + 0x90 and i.ops[0] not in stores:
                    stores[i.ops[0]] = (i.mn, int(m.group(1), 0))
            if i.mn.startswith('b') and not (i.sym or '').startswith('__savegprlr'):
                break
            written |= dst_regs([i])
        if not any(mn == 'std' for mn, o in stores.values()):
            return
        partial = set()      # registers re-passed as a partial last register (lwz + rldicr 32,63)
        for k, i in enumerate(self.insns):
            if i.mn == 'rldicr' and i.ops[2:] == ['32', '63']:
                for j in self.insns[max(0, k - 6):k]:
                    m = re.fullmatch(r'(\w+)\(r1\)', j.ops[1]) if j.mn == 'lwz' and len(j.ops) == 2 else None
                    if m and j.ops[0] == i.ops[1]:
                        partial.add(int(m.group(1), 0))
        maxk = max(int(r[1:]) for r in stores)
        best = []

        cost = lambda items: (sum(it[2] for it in items if it[0] == 's'), len(items))

        def walk(k, off, items):
            if best and cost(items) >= cost(best[0]):
                return
            if k > maxk:
                best[:] = [list(items)]
                return
            r = f'r{k}'
            # a word parameter: its slot is off (8 bytes); only `stw` to the low half
            if r not in stores or stores[r] == ('stw', off + 4):
                walk(k + 1, off + 8, items + [('w', k)])
            for n in range(1, 11 - k + 1):
                for nb in ((4, 8) if n == 1 else (8 * n - 4, 8 * n)):
                    al = 16 if nb > 8 else 8
                    h = (off + al - 1) // al * al
                    ok = True
                    for j in range(k, k + n):
                        st_ = stores.get(f'r{j}')
                        if st_ is None:
                            continue
                        want = ('stw', h + 4) if nb == 4 else ('std', h + 8 * (j - k))
                        if st_ != want:
                            ok = False
                    last = h + 8 * (n - 1)
                    if nb == 8 * n and last in partial or (nb == 8 * n - 4 and n > 1 and False):
                        ok = False
                    if ok and (nb != 4):
                        walk(k + n, h + max(8, (nb + 7) // 8 * 8), items + [('s', k, n, nb, h)])
                if k + n - 1 >= maxk:
                    break
        walk(3, base, [])
        if not best:
            raise Skip('home layout')
        reads = []
        for ln in self.lines:
            m = re.search(r'\b(lwz|lbz|lhz|lha|lfs|lfd|ld)\s+\w+,\s*(\w+)\(r1\)', ln)
            if m:
                reads.append((int(m.group(2), 0), self.SZ.get(m.group(1), 8)))
        for it in best[0]:
            if it[0] == 'w':
                k = it[1]; r = f'r{k}'
                if r in stores:            # an address-taken word parameter
                    nm = f'a{k - 3}'
                    self.home_scalar.add(nm); self.readp.add(k)
                    o = stores[r][1]
                    for x in range(o, o + 4):
                        self.home_off[x] = (nm, x - o)
                continue
            _, k0, n, nb, h = it
            if nb == 8 * n - 4 and any(h + nb <= o < h + 8 * n for o, sz in reads):
                nb = 8 * n           # the low half of the last register is read after all
            name = f'sp{k0 - 3}'
            self.home[k0] = (k0 + n - 1, name, nb // 4)
            for o in range(h, h + nb):
                self.home_off[o] = (name, o - h)
            for k in range(k0, k0 + n):
                self.home_reg[f'r{k}'] = (name, k - k0)

    def home_ref(self, off, t):
        """C lvalue for a `t`-typed access to a struct parameter's home slot, or None."""
        h = self.home_off.get(off)
        if h is None:
            return None
        name, b = h
        if name in self.home_scalar:
            return name if t == 'ts4_word' and b == 0 else f'*({t} *)((char *)&{name} + {b})'
        if t == 'ts4_word' and b % 4 == 0:
            return f'{name}.w[{b // 4}]'
        return f'*({t} *)((char *)&{name} + {b})'

    def _stack_layout(self):
        """Every `addi rX,r1,off` takes the address of a word array starting at
        off and extending to the next such base / last access.  Accesses that are
        not covered by such an array (spills, converted values, scalars) get an
        array of their own, grouped by adjacency."""
        L = self.lines
        self.has_frame = any(re.search(r'\bstwu\s+r1,', l) for l in L[:12])
        bases = sorted({int(m.group(2), 0) * (-1 if m.group(1) == 'subi' else 1) for l in L
                        for m in [re.search(r'\b(addi|subi)\s+r(?!1\b)\d+,\s*r1,\s*(-?\w+)', l)] if m})
        if self.has_frame:
            bases = [b for b in bases if b >= 0]
        accs = [(int(m.group(2), 0), self.SZ[m.group(1)], m.group(1)) for l in L
                for m in [re.search(r'\b(lwz|stw|lbz|stb|lhz|lha|sth|lfs|lfd|stfs|stfd)\s+\w+,\s*(-?\w+)\(r1\)', l)] if m]
        accs = [a for a in accs if (a[0] >= 0 or not self.has_frame) and a[0] not in self.home_off]
        bases = [b for b in bases if b not in self.home_off]
        argshape = lambda a: a[2] == 'stw' and a[0] >= 0x54 and (a[0] - 0x54) % 8 == 0
        def covered(o):
            return any(b <= o for b in bases)
        self.locbase = {}
        extra = []
        if any(not argshape(a) for a in accs if not covered(a[0])) or not bases:
            unc = sorted(a for a in accs if not covered(a[0]) or (bases and a[0] < bases[0]))
            if not any(not argshape(a) for a in unc):
                unc = []
            end = None
            for o, sz, mn in unc:
                if end is None or o >= end + 4:
                    extra.append(o)
                end = o + sz if end is None or o >= end + 4 else max(end, o + sz)
        bases = sorted(set(bases) | set(extra))
        acc = [(o, sz) for o, sz, mn in accs]
        self.bases = bases
        self.local_ext = {}
        for i, b in enumerate(bases):
            nxt = bases[i + 1] if i + 1 < len(bases) else 1 << 30
            top = max([o + sz - 1 for o, sz in acc if b <= o < nxt] + [b])
            self.local_ext[b] = (top - b) // 4 + 1
        # the frame size shows how big the locals are: fill each array up to the next
        # base and the last one up to the register save area at the top of the frame
        frame = self.frame_size()
        for i, b in enumerate(bases):
            if b in extra or b < 0:
                continue
            end = bases[i + 1] if i + 1 < len(bases) else (frame[0] - frame[1] if frame else b)
            fill = (end - b) // 4
            if b % 16:
                fill = min(fill, 3)   # MSVC puts objects of 16 bytes or more at 16-aligned offsets
            self.local_ext[b] = max(self.local_ext[b], fill)

    def frame_size(self):
        """(frame size, bytes of saved registers incl. LR) from the prologue, or None."""
        n = saved = None
        for ln in self.lines[:12]:
            m = re.search(r'\bstwu\s+r1,\s*-(\w+)\(r1\)', ln)
            if m:
                n = int(m.group(1), 0)
            m = re.search(r'REL24\s+__savegprlr_(\d+)', ln)
            if m:
                saved = 8 + 8 * (32 - int(m.group(1)))
        if n is None or any('__savefpr' in ln or '__savevmx' in ln for ln in self.lines[:12]):
            return None
        if saved is None:
            saved = 8 + 8 * sum(1 for ln in self.lines[:12] if re.search(r'\bstd\s+r\d+,\s*-\w+\(r1\)', ln))
        saved += 8 * sum(1 for ln in self.lines[:12] if re.search(r'\bstfd\s+f\d+,\s*-\w+\(r1\)', ln))
        return n, saved

    def local_of(self, off):
        for b in self.bases:
            if b <= off < b + 4 * self.local_ext[b]:
                n = f'loc{b:x}' if b >= 0 else f'locm{-b:x}'
                self.locbase[n] = b
                return n, (off - b) // 4, off - b
        return None

    def local_ref(self, off, t):
        """C lvalue for a `t`-typed access at stack offset off, or None."""
        loc = self.local_of(off)
        if loc is None:
            return None
        if loc[0] not in self.localnames:
            self.localnames.append(loc[0])
        if t == 'ts4_word' and loc[2] % 4 == 0:
            return f'{loc[0]}[{loc[1]}]'
        return f'*({t} *)((char *){loc[0]} + {loc[2]})'

    # ---- state -------------------------------------------------------------
    @staticmethod
    def newst():
        return dict(regs={}, written=set(), clobbered=set(), fregs={}, fwritten=set(), ctr=None,
                    ctr_reg=None, cmps={}, stackargs={}, cnt=None, slots={}, vregs={}, vwritten=set())

    @staticmethod
    def cp(st):
        return {k: (v.copy() if hasattr(v, 'copy') else v) for k, v in st.items()}

    def rd(self, st, r):
        regs = st['regs']
        if r in regs:
            v = regs[r]
            if isinstance(v, V):
                if v.t in ('float', 'double'):
                    raise Skip('fret mixed')
                v.used = True
                return v.n
            return v
        n = int(r[1:])
        if n < 3 or n > 10 or r in st['clobbered']:
            raise Skip('read ' + r)
        self.readp.add(n)
        return f'a{n - 3}'

    def regval(self, st, r):
        """Current value of r in st (params count) or None when unusable."""
        if r in st['regs']:
            v = st['regs'][r]
            if isinstance(v, V):
                v.used = True
                return v.n
            return None if isinstance(v, tuple) else v
        n = int(r[1:]) if r[0] == 'r' else 0
        if r[0] == 'r' and 3 <= n <= 10 and r not in st['clobbered']:
            self.readp.add(n)
            return f'a{n - 3}'
        return None

    def newv(self, out, t, e, pure=True):
        self.ntmp += 1
        v = V(t, e, f't{self.ntmp}', pure)
        out.append(v)
        return v

    def newphi(self, prefix='p'):
        self.ntmp += 1
        n = f'{prefix}{self.ntmp}'
        self.phis.append(n)
        return n

    # ---- phi merging -------------------------------------------------------
    def merge_phi(self, st, arms, pre_out):
        """Registers changed by the branch arms are merged into a phi variable
        (assigned in every arm; for a one-armed if the old value is assigned
        first into pre_out).  Registers without a value in every path become
        unusable (clobbered)."""
        regs0 = st['regs']
        for s, o in arms:
            if s['vregs'] != st['vregs']:
                raise Skip('vec phi')
        for f in sorted(set().union(*(set(s['fregs']) for s, o in arms)) | set(st['fregs'])):
            if all(s['fregs'].get(f) is st['fregs'].get(f) for s, o in arms):
                continue
            tys = {(s['fregs'].get(f) or st['fregs'].get(f) or (None, 'float'))[1] for s, o in arms}
            if tys & {'ctiw', 'i64', 'fret'}:   # a pending conversion / call result: dead after the join
                st['fregs'].pop(f, None); st['fwritten'].discard(f); st['clobbered'].add(f)
                continue
            if len(tys) != 1:
                raise Skip('float phi')
            t = tys.pop()
            if t not in ('float', 'double'):
                raise Skip('float phi')
            if not all(self._fhas(s, f) for s, o in arms) or (pre_out is not None and not self._fhas(st, f)):
                # no value on some path: the register is dead after the join
                st['fregs'].pop(f, None); st['fwritten'].discard(f); st['clobbered'].add(f)
                continue
            self.ntmp += 1
            pn = f'pf{self.ntmp}'
            self.fphis.append((pn, t))
            if pre_out is not None:
                pre_out.append(f'{pn} = {self.fval(st, f, t)};')
            for s, o in arms:
                o.append(f'{pn} = {self.fval(s, f, t)};')
            st['fregs'][f] = (pn, t); st['fwritten'].add(f); st['clobbered'].discard(f)
        names = set()
        for s, o in arms:
            names |= set(s['written']) | set(s['regs']) | set(s['clobbered'])
        for r in sorted(names):
            if r.startswith('__'):
                continue
            changed = any(s['regs'].get(r) is not regs0.get(r) or (r in s['clobbered'] and r not in st['clobbered']) for s, o in arms)
            if not changed:
                continue
            if any(r in s['clobbered'] for s, o in arms) or (pre_out is not None and r in st['clobbered']):
                vals = [None]       # no value on some path (checked first: regval() records parameter reads)
            else:
                vals = [self.regval(s, r) for s, o in arms]
            pre = self.regval(st, r) if pre_out is not None and None not in vals else 0
            if pre_out is not None and pre is None:
                vals = [None]
            if any(v is None for v in vals) or r[0] != 'r' or r == 'r1' or (r == 'r3' and self.fret_pref):
                regs0.pop(r, None); st['written'].discard(r); st['clobbered'].add(r)
                continue
            pn = self.newphi()
            if pre_out is not None:
                pre_out.append(f'{pn} = (ts4_word){pre};')
            for (s, o), v in zip(arms, vals):
                o.append(f'{pn} = (ts4_word){v};')
            regs0[r] = pn; st['written'].add(r); st['clobbered'].discard(r)

    # ---- instruction semantics ---------------------------------------------
    def fval(self, st, f, t='float'):
        """Text of float register f (a parameter when never written)."""
        if f in st['fregs']:
            v, vt = st['fregs'][f]
            if vt == 'fret':
                # the float result of a call: its type is fixed by the first use (frsp -> double)
                if v.used:
                    raise Skip('fret mixed')
                v.t = t; v.used = True
                if v.callsym == '__vcall':
                    v.e = v.e.replace('((ts4_word (*)(', f'(({t} (*)(', 1)
                else:
                    self.rtypes[v.callsym] = t
                st['fregs'][f] = (v, t)
                return v.n
            if isinstance(v, V):
                v.used = True
                return v.n
            return v
        if f not in ('f1', 'f2', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8') or f in st['clobbered']:
            raise Skip('freg')
        self.fparams.setdefault(f, t)
        return f

    @staticmethod
    def _fhas(st, f):
        """True when float register f has a value in st (written, or an untouched parameter)."""
        return f in st['fregs'] or (f in ('f1', 'f2', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8') and f not in st['clobbered'])

    def setf(self, st, f, e, t='float'):
        st['fregs'][f] = (e, t); st['fwritten'].add(f)

    def q(self, kind):
        """`volatile ` qualifier for stores ('s') / loads ('l'): volatile accesses keep the
        original program order (the scheduler may otherwise reorder independent stores)."""
        return 'volatile ' if (self.vol in (1, 2) and kind == 's') or (self.vol in (2, 3) and kind == 'l') else ''

    def step(self, ins, st, out):
        """Execute one non-terminator instruction symbolically."""
        mn, ops, rk, sym = ins.mn, ins.ops, ins.rk, ins.sym
        regs = st['regs']; written = st['written']; clobbered = st['clobbered']
        rd = lambda r: self.rd(st, r)

        def setr(r, e):
            regs[r] = e; written.add(r); clobbered.discard(r)

        def num(x):
            return int(x, 0)

        def nohi(*vs):
            if any(isinstance(v, tuple) for v in vs):
                raise Skip('hi value')
            return vs
        if mn in ('mflr', 'mtlr'):
            return
        if is_vmx(mn):
            self.vmx_step(ins, st, out); return
        if mn == 'ts4atomic':
            kind, ro, rv, rp = ops[:4]
            p = self.rd(st, rp); nohi(p)
            ptr = f'(volatile long *)(ts4_word)({p})'
            self.intrinsics.add(kind)
            self.kinds.append('atomic'); self.detail.append('interlocked_' + kind)
            if kind == 'xchg':
                v = self.rd(st, rv); nohi(v)
                setr(ro, self.newv(out, 'ts4_word', f'_InterlockedExchange({ptr}, (long){v})', pure=False))
            elif kind in ('inc', 'dec'):
                setr(rv, self.newv(out, 'ts4_word', f'_Interlocked{"Increment" if kind == "inc" else "Decrement"}({ptr})', pure=False))
            else:
                x = ops[4] if kind == 'addi' else self.rd(st, ops[4]); nohi(x)
                self.intrinsics.add('addi')
                o = self.newv(out, 'ts4_word', f'_InterlockedExchangeAdd({ptr}, (long){x})', pure=False)
                setr(ro, o); setr(rv, f'({o.n} + {x})'); o.used = True
            return
        if mn == 'bl' and sym and sym.startswith('__savegprlr'):
            return
        if mn == 'stwu' and ops[0] == 'r1':
            return
        if mn == 'addi' and ops[0] == 'r1' and ops[1] == 'r1':
            return
        if mn in ('cmplwi', 'cmpwi', 'cmplw', 'cmpw'):
            o = [x for x in ops if not x.startswith('cr')]
            cr = ops[0] if ops[0].startswith('cr') else 'cr0'
            reg2 = mn in ('cmplw', 'cmpw')
            a = rd(o[0]); b = rd(o[1]) if reg2 else str(num(o[1]))
            nohi(a, b)
            cast = 'ts4_word' if mn in ('cmplwi', 'cmplw') else 'int'
            for x in ([a, b] if reg2 else [a]):
                (self.unsigned if cast == 'ts4_word' else self.signed).add(x)
            st['cmps'][cr] = (f'({cast}){a}', f'({cast}){b}' if reg2 else b, False)
            return
        if mn in ('fcmpu', 'fcmpo'):
            cr = ops[0]
            st['cmps'][cr] = (self.fval(st, ops[1]), self.fval(st, ops[2]), True)
            return
        if mn.endswith('.') and mn not in ('andi.', 'andis.'):
            base = mn[:-1]
            if base in ('stwcx', 'stdcx', 'subfe', 'subfc', 'addze'):
                raise Skip(mn)
            if base in ('subic', 'addic'):   # no carry consumer is modelled: plain add/sub + cr0 compare
                base = 'subi' if base == 'subic' else 'addi'
            ins2 = type(ins)(ins.addr, base, ops, rk, sym, ins.tgt, ins.ln)
            self.step(ins2, st, out)
            v = rd(ops[0])
            nohi(v)
            st['cmps']['cr0'] = (f'(int){v}', '0', False)
            return
        if mn in ('andi.', 'andis.'):
            v = f'({rd(ops[1])} & {num(ops[2]) << (16 if mn == "andis." else 0)})'
            setr(ops[0], v)
            st['cmps']['cr0'] = (f'(int){v}', '0', False)
            return
        if mn in UPD and ops[1].endswith('(r1)') is False:
            mo = re.match(r'(-?\w+)\((r\d+)\)', ops[1]); base = mo.group(2)
            if base == ops[0] and mn in LD_U:
                raise Skip('update base')
            bv = rd(base); nohi(bv)
            setr(base, f'({bv} + {num(mo.group(1))})')
            self.step(type(ins)(ins.addr, UPD[mn], [ops[0], f'0({base})'], rk, sym, ins.tgt, ins.ln), st, out)
            return
        if mn in LD or mn in ST or mn in FLD or mn in FST or mn in ('ld',):
            mo = re.match(r'(-?\w+)\((r\d+)\)', ops[1]); off = num(mo.group(1)); base = mo.group(2)
            if base == 'r1':
                if off < 0 and (self.has_frame or (mn in ('std', 'ld') and int(ops[0][1:]) >= 14)):
                    return      # register save area (also callee-saved registers of frameless leaves)
                if off in self.home_off:
                    self.home_step(ins, st, out, off); return
                sl = st['slots']
                if mn == 'stfd' and isinstance(st['fregs'].get(ops[0], (None, None))[1], str) and st['fregs'][ops[0]][1] == 'ctiw':
                    sl[off + 4] = st['fregs'][ops[0]][0]; return
                if mn == 'lwz' and off in sl and sl[off].startswith('(int)('):
                    setr(ops[0], sl[off]); return
                if mn == 'std' and isinstance(regs.get(ops[0]), str) and regs[ops[0]].startswith('((ts4_s64)'):
                    sl[off] = regs[ops[0]]; return
                if mn == 'std' and isinstance(regs.get(ops[0]), V) and regs[ops[0]].t in ('unsigned short', 'unsigned char'):
                    # a zero-extended small value spilled for an integer -> float conversion (std/lfd/fcfid)
                    v = regs[ops[0]]; v.used = True; sl[off] = f'((ts4_s64){v.n})'; return
                if mn == 'lfd' and off in sl and sl[off].startswith('((ts4_s64)'):
                    self.setf(st, ops[0], sl[off], 'i64'); return
                if mn == 'ld' and off % 4 == 0 and self.local_ref(off, 'ts4_word') is not None:
                    # 8 bytes of a stack struct loaded into an argument register (struct by value)
                    setr(ops[0], ('sloc', off)); return
                if mn == 'ld' or mn == 'std':
                    raise Skip(mn)
                ty_ = (LD.get(mn) or ST.get(mn) or FLD.get(mn) or FST.get(mn))[0]
                el = self.local_ref(off, ty_)
                if el is not None:
                    if mn in LD:
                        setr(ops[0], self.newv(out, ty_, el))
                    elif mn in ST:
                        v = rd(ops[0]); nohi(v)
                        out.append(f'{el} = ({ty_}){v};')
                    elif mn in FLD:
                        v = self.newv(out, ty_, el); self.setf(st, ops[0], v, ty_)
                    else:
                        out.append(f'{el} = {self.fval(st, ops[0], ty_)};')
                    return
                if mn == 'stw' and off >= 0x54 and (off - 0x54) % 8 == 0:
                    v = rd(ops[0]); nohi(v)
                    st['stackargs'][(off - 0x54) // 8] = v
                    return
                raise Skip('stack')
            if rk == 'REFLO' and isinstance(regs.get(base), tuple):
                s = regs[base][1]; self.externs[s] = 1; addr_e = f'{s}'
            else:
                if rk:
                    raise Skip('reloc mem')
                bv = rd(base); nohi(bv)
                addr_e = f'((char *)(ts4_word)({bv}) + {off})'
            if mn in LD:
                t, ty = LD[mn]
                lv_ = self.newv(out, t, f'*({self.q("l")}{t} *){addr_e}')
                if not rk and mn in ('ld', 'lwz'):
                    lv_.maddr = (bv, off, mn)
                setr(ops[0], lv_)
                self.detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); self.kinds.append('get')
            elif mn in ST:
                t, ty = ST[mn]; r = ops[0]
                if mn == 'std':
                    self.ptype[r] = 'ts4_u64'
                v = rd(r); nohi(v)
                out.append(f'*({self.q("s")}{t} *){addr_e} = ({t}){v};')
                self.detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); self.kinds.append('set')
            elif mn in FLD:
                t, ty = FLD[mn]
                v = self.newv(out, t, f'*({t} *){addr_e}'); self.setf(st, ops[0], v, t); self.kinds.append('get')
            else:
                t, ty = FST[mn]; fv = self.fval(st, ops[0], t)
                out.append(f'*({self.q("s")}{t} *){addr_e} = {fv};'); self.kinds.append('set')
            return
        if mn in IDX_LD:
            t = IDX_LD[mn]; a = rd(ops[1]); b = rd(ops[2]); nohi(a, b)
            setr(ops[0], self.newv(out, t, f'*({self.q("l")}{t} *)((char *)(ts4_word)({a}) + {b})')); self.kinds.append('get')
            return
        if mn in IDX_ST:
            t = IDX_ST[mn]; v = rd(ops[0]); a = rd(ops[1]); b = rd(ops[2]); nohi(v, a, b)
            out.append(f'*({self.q("s")}{t} *)((char *)(ts4_word)({a}) + {b}) = ({t}){v};'); self.kinds.append('set')
            return
        if mn == 'li':
            setr(ops[0], str(num(ops[1]))); return
        if mn == 'lis':
            if rk == 'REFHI':
                setr(ops[0], ('hi', sym))
            else:
                setr(ops[0], f'({num(ops[1]) << 16})')
            return
        if mn == 'mr':
            setr(ops[0], rd(ops[1])); return
        if mn in ('addi', 'subi'):
            if ops[1] == 'r1' and rk is None and num(ops[2]) in self.home_off and mn == 'addi':
                name, b = self.home_off[num(ops[2])]
                setr(ops[0], f'(ts4_word)&{name}' if b == 0 else f'((ts4_word)&{name} + {b})')
            elif ops[1] == 'r1' and rk is None:
                loc = self.local_of(num(ops[2]) * (-1 if mn == 'subi' else 1))
                if loc is None:
                    raise Skip('stack addr')
                if loc[0] not in self.localnames:
                    self.localnames.append(loc[0])
                setr(ops[0], f'(ts4_word)&{loc[0]}[{loc[1]}]' if loc[2] % 4 == 0 else f'((ts4_word){loc[0]} + {loc[2]})')
            elif rk == 'REFLO':
                s = regs[ops[1]][1]; self.externs[s] = 1
                setr(ops[0], f'(ts4_word){s}'); self.kinds.append('addr'); self.detail.append(s)
            else:
                v = num(ops[2])
                if mn == 'subi':
                    v = -v
                a = rd(ops[1]); nohi(a)
                setr(ops[0], f'({a} + {v})')
            return
        if mn == 'addis':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'({a} + {num(ops[2]) << 16})'); return
        if mn in ('add', 'subf', 'and', 'or', 'xor', 'andc', 'nor', 'mullw', 'divw', 'divwu', 'slw', 'srw', 'sraw'):
            a = rd(ops[1]); b = rd(ops[2]); nohi(a, b)
            if mn == 'and' and (a in self.masks or b in self.masks):
                m, o = (a, b) if a in self.masks else (b, a)
                setr(ops[0], f'({self.masks[m]} ? {o} : 0)'); return
            if mn == 'subf':
                # x - (x / y) * y: the remainder (the compiler's expansion of `%`)
                for sg in ('(int)', ''):
                    m = re.fullmatch(r'\(\(int\)\(%s(.+) / %s(.+)\) \* \(int\)(.+)\)' % (re.escape(sg), re.escape(sg)), a)
                    if m and m.group(1) == b and m.group(2) == m.group(3):
                        setr(ops[0], f'({sg}{b} % {sg}{m.group(2)})'); return
            e = {'add': f'({a} + {b})', 'subf': f'({b} - {a})', 'and': f'({a} & {b})', 'or': f'({a} | {b})',
                 'xor': f'({a} ^ {b})', 'andc': f'({a} & ~{b})', 'nor': f'(~({a} | {b}))',
                 'mullw': f'((int){a} * (int){b})', 'divw': f'((int){a} / (int){b})', 'divwu': f'({a} / {b})',
                 'slw': f'({a} << {b})', 'srw': f'({a} >> {b})', 'sraw': f'((int){a} >> {b})'}[mn]
            setr(ops[0], e); return
        if mn == 'neg':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'(-(int){a})'); return
        if mn in ('twllei', 'twi', 'tweqi', 'twlgti'):
            return      # compiler-inserted division traps (divide by zero, INT_MIN % -1)
        if mn == 'mulli':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((int){a} * {num(ops[2])})'); return
        if mn == 'subfic':
            a = rd(ops[1]); nohi(a); k = num(ops[2])
            setr(ops[0], f'({k} - {a})')
            regs['__ca'] = ('ca', f'({a} == 0)' if k == 0 else f'((ts4_word){a} <= {k})', a, ops[0]); return
        if mn in ('ori', 'oris', 'xori', 'xoris'):
            a = rd(ops[1]); nohi(a)
            v = num(ops[2]) << (16 if mn.endswith('is') else 0)
            setr(ops[0], f'({a} {"^" if mn.startswith("xor") else "|"} {v})'); return
        if mn in ('slwi', 'srwi', 'srawi'):
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            if mn == 'srawi':
                regs['__ca'] = ('div', a, n, ops[0])
            setr(ops[0], {'slwi': f'({a} << {n})', 'srwi': f'(({a}) >> {n})', 'srawi': f'((int){a} >> {n})'}[mn]); return
        if mn == 'clrlwi' and ops[2] == '31' and isinstance(regs.get(ops[1]), tuple) and regs[ops[1]][0] == 'cbit':
            setr(ops[0], regs[ops[1]][1]); return          # low bit of a carry comparison idiom
        if mn == 'clrlwi' and ops[2] == '31' and isinstance(regs.get(ops[1]), str) and regs[ops[1]] in self.masks:
            setr(ops[0], self.masks[regs[ops[1]]]); return    # low bit of a `subfe` mask: its condition
        if mn in ('clrlwi', 'clrrwi'):
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            m = (1 << (32 - n)) - 1 if mn == 'clrlwi' else (0xFFFFFFFF << n) & 0xFFFFFFFF
            setr(ops[0], f'({a} & {hex(m)})'); return
        if mn == 'clrlslwi':
            a = rd(ops[1]); nohi(a); b, n = num(ops[2]), num(ops[3])
            setr(ops[0], f'(({a} & {hex((1 << (32 - b)) - 1)}) << {n})'); return
        if mn == 'rotlwi':
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            setr(ops[0], f'(({a} << {n}) | ({a} >> {32 - n}))' if n else a); return
        if mn == 'rlwinm':
            a = rd(ops[1]); nohi(a); sh, mb, me = num(ops[2]), num(ops[3]), num(ops[4])
            if mb <= me:
                mask = ((1 << (me - mb + 1)) - 1) << (31 - me)
            else:
                mask = 0xFFFFFFFF ^ (((1 << (mb - me - 1)) - 1) << (31 - mb + 1))
            r = f'(({a} << {sh}) | ({a} >> {32 - sh}))' if sh else a
            if not sh and a in self.masks:
                setr(ops[0], f'({self.masks[a]} ? {hex(mask)} : 0)'); return
            setr(ops[0], f'({r} & {hex(mask)})'); return
        if mn == 'rlwimi':
            a = rd(ops[0]); b = rd(ops[1]); nohi(a, b); sh, mb, me = num(ops[2]), num(ops[3]), num(ops[4])
            mask = ((1 << (me - mb + 1)) - 1) << (31 - me) if mb <= me else 0xFFFFFFFF ^ (((1 << (mb - me - 1)) - 1) << (32 - mb))
            r = f'(({b} << {sh}) | ({b} >> {32 - sh}))' if sh else b
            setr(ops[0], f'(({r} & {hex(mask)}) | ({a} & {hex(~mask & 0xFFFFFFFF)}))'); return
        if mn == 'cntlzw':
            a = rd(ops[1]); nohi(a); setr(ops[0], ('clz', a)); return
        if mn == 'extrwi' and isinstance(regs.get(ops[1]), tuple) and regs[ops[1]][0] == 'clz' and ops[2] == '1' and num(ops[3]) == 26:
            setr(ops[0], f'({regs[ops[1]][1]} == 0)'); return
        if mn == 'extrwi':
            a = rd(ops[1]); nohi(a); n, b = num(ops[2]), num(ops[3])
            setr(ops[0], f'(({a} >> {32 - n - b}) & {hex((1 << n) - 1)})'); return
        if mn == 'rldicr' and ops[2:] == ['32', '31'] and not isinstance(regs.get(ops[1]), tuple):
            # the last word of a struct argument (> 8 bytes) in the high half of its register
            a = rd(ops[1]); nohi(a); setr(ops[0], ('shi', a)); return
        if mn == 'rldicr' and ops[2:] == ['32', '63'] and isinstance(regs.get(ops[1]), V) and getattr(regs[ops[1]], 'home', None):
            v = regs[ops[1]]
            setr(ops[0], ('spart', v.home[0], v.home[1])); return
        if mn == 'rldicr' and ops[2:] == ['32', '63'] and isinstance(regs.get(ops[1]), V) \
                and getattr(regs[ops[1]], 'maddr', (0, 0, ''))[2] == 'lwz':
            setr(ops[0], ('mhi', regs[ops[1]])); return   # last word of a struct passed from memory
        if mn == 'rldicr' and not isinstance(regs.get(ops[1]), tuple):
            sh, me = num(ops[2]), num(ops[3])
            a = rd(ops[1]); nohi(a)
            if sh + me == 63:                                    # sldi
                setr(ops[0], f'((ts4_u64){a} << {sh})'); return
            if me == 63 and re.fullmatch(r'\d+', a) and int(a).bit_length() + sh <= 64:
                setr(ops[0], f'((ts4_u64){a} << {sh})'); return  # rotate of a small constant
            if sh == 0:                                          # clrrdi
                setr(ops[0], f'((ts4_u64){a} & {hex(((1 << 64) - 1) ^ ((1 << (63 - me)) - 1))})'); return
            raise Skip('rldicr')
        if mn == 'rldicl' and not isinstance(regs.get(ops[1]), tuple) and ops[2:] != ['0', '32']:
            sh, mb = num(ops[2]), num(ops[3])
            a = rd(ops[1]); nohi(a)
            if sh + mb == 64:                                    # srdi
                setr(ops[0], f'((ts4_u64){a} >> {mb})'); return
            if sh == 0:                                          # clrldi
                setr(ops[0], f'((ts4_u64){a} & {hex((1 << (64 - mb)) - 1)})'); return
            raise Skip('rldicl')
        if mn in ('sld', 'srd', 'srad'):
            a = rd(ops[1]); b = rd(ops[2]); nohi(a, b)
            setr(ops[0], {'sld': f'((ts4_u64){a} << {b})', 'srd': f'((ts4_u64){a} >> {b})',
                          'srad': f'((ts4_s64){a} >> {b})'}[mn]); return
        if mn == 'rldicl' and ops[2:] == ['0', '32']:
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((ts4_s64)(ts4_word){a})'); return   # clrldi: zero-extend
        if mn == 'extsw':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((ts4_s64)(int){a})'); return
        if mn in ('fctiwz', 'fctiw'):
            a = self.fval(st, ops[1]); st['fregs'][ops[0]] = (f'(int)({a})', 'ctiw'); st['fwritten'].add(ops[0]); return
        if mn == 'fcfid':
            if st['fregs'].get(ops[1], (None, None))[1] != 'i64':
                raise Skip('fcfid')
            self.setf(st, ops[0], f'((double){st["fregs"][ops[1]][0]})', 'double'); return
        if mn == 'frsp':
            a = self.fval(st, ops[1], 'double'); self.setf(st, ops[0], f'((float){a})', 'float'); return
        if mn == 'extsb':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((signed char){a})'); return
        if mn == 'extsh':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((short){a})'); return
        if mn in ('subic', 'addic'):
            # carry-setting add: CA = (a >= k) (unsigned) for a - k
            a = rd(ops[1]); nohi(a); k = num(ops[2]) * (1 if mn == 'subic' else -1)
            if k <= 0:
                raise Skip(mn)
            cond = f'({a} != 0)' if k == 1 else f'((ts4_word){a} >= {k})'
            setr(ops[0], f'({a} - {k})'); regs['__ca'] = ('ca', cond, a, ops[0]); return
        if mn == 'subfc':
            # b - a with CA = (b >= a) unsigned
            a = rd(ops[1]); b = rd(ops[2]); nohi(a, b)
            setr(ops[0], f'({b} - {a})')
            regs['__ca'] = ('ca', f'((ts4_word){b} >= (ts4_word){a})', '__sf', ops[0], a, b,
                            f'((ts4_word){b} < (ts4_word){a})'); return
        if mn == 'eqv':
            a = rd(ops[1]); b = rd(ops[2]); nohi(a, b); setr(ops[0], f'(~({a} ^ {b}))'); return
        if mn in ('adde', 'addze') and isinstance(regs.get('__ca'), tuple) and len(regs['__ca']) > 4:
            # signed comparison idioms built on `subfc b - a`
            A, B = regs['__ca'][4], regs['__ca'][5]
            xs = sorted(rd(o) for o in ops[1:])
            if mn == 'adde' and xs == sorted([f'(({A}) >> 31)', f'((int){B} >> 31)']):
                setr(ops[0], f'((int){B} >= (int){A})'); return
            if mn == 'addze' and xs[0] in (f'(((~({A} ^ {B}))) >> 31)', f'(((~({B} ^ {A}))) >> 31)'):
                setr(ops[0], ('cbit', f'((int){B} < (int){A})')); return
            raise Skip(mn)
        if mn == 'subfe':
            ca = regs.get('__ca')
            if not (isinstance(ca, tuple) and ca[0] == 'ca'):
                raise Skip('subfe')
            if ops[1] == ops[2]:
                # CA - 1: all ones exactly when there was no carry (the `c ? K : 0` mask idiom)
                c0 = ca[1]
                neg = ca[6] if len(ca) > 6 else (c0.replace(' != 0)', ' == 0)') if c0.endswith(' != 0)') else
                       c0.replace(' == 0)', ' != 0)') if c0.endswith(' == 0)') else f'(!{c0})')
                t = f'(-(int){neg})'
                self.masks[t] = neg; setr(ops[0], t); return
            if ops[1] == ca[3] and rd(ops[2]) == ca[2] and ca[1] == f'({ca[2]} != 0)':
                setr(ops[0], ca[1]); return      # ~(a - 1) + a + CA = (a != 0)
            raise Skip('subfe')
        if mn == 'addze':
            ca = regs.get('__ca')
            if isinstance(ca, tuple) and ca[0] == 'div' and ops[1] == ca[3]:
                setr(ops[0], f'((int){ca[1]} / {1 << ca[2]})'); return   # signed division by 2^n
            raise Skip('addze')
        if mn == 'mtctr':
            v = rd(ops[0]); nohi(v)
            if self.has_ctr_loop:
                cn = self.newphi('c')
                out.append(f'{cn} = (ts4_word){v};')
                st['cnt'] = cn; return
            st['ctr'] = v; st['ctr_reg'] = ops[0]; return
        # float basics
        if mn == 'fmr':
            setf_t = st['fregs'].get(ops[1], (None, 'float'))[1]
            self.setf(st, ops[0], self.fval(st, ops[1]), setf_t); return
        if mn in ('fadds', 'fsubs', 'fmuls', 'fdivs', 'fadd', 'fsub', 'fmul', 'fdiv'):
            t = 'float' if mn.endswith('s') else 'double'
            a = self.fval(st, ops[1], t); b = self.fval(st, ops[2], t)
            self.setf(st, ops[0], f'({a} {"+-*/"[["add", "sub", "mul", "div"].index(mn.rstrip("s")[1:])]} {b})', t); return
        if mn in ('fneg', 'fabs'):
            a = self.fval(st, ops[1])
            t = st['fregs'].get(ops[1], (None, 'float'))[1]
            self.setf(st, ops[0], f'(-{a})' if mn == 'fneg' else f'((({a}) < 0) ? -({a}) : ({a}))', t); return
        if mn in ('bl', 'bctrl'):
            self.call(ins, st, out); return
        raise Skip(mn)

    def home_step(self, ins, st, out, off):
        """Access to the home slot of a struct parameter (see _home_structs)."""
        mn, ops = ins.mn, ins.ops
        name, b = self.home_off[off]
        regs = st['regs']
        if mn == 'stw' and name in self.home_scalar and b == 0 and ops[0] == f'r{int(name[1:]) + 3}' \
                and ops[0] not in regs and ops[0] not in st['clobbered']:
            return                           # spill of an address-taken word parameter
        if mn == 'std':
            if self.home_reg.get(ops[0]) == (name, b // 8) and b % 8 == 0 and regs.get(ops[0]) == ('spart', name, b // 8):
                return                       # the spill itself
            raise Skip('home store')
        if mn == 'ld':
            if b % 8:
                raise Skip('home ld')
            regs[ops[0]] = ('spart', name, b // 8); st['written'].add(ops[0]); st['clobbered'].discard(ops[0])
            return
        ty_ = (LD.get(mn) or ST.get(mn) or FLD.get(mn) or FST.get(mn))[0]
        el = self.home_ref(off, ty_)
        if mn in LD:
            v = self.newv(out, ty_, el)
            if mn == 'lwz' and b % 8 == 0:
                v.home = (name, b // 8)
            regs[ops[0]] = v; st['written'].add(ops[0]); st['clobbered'].discard(ops[0])
        elif mn in ST:
            v = self.rd(st, ops[0])
            if isinstance(v, tuple):
                raise Skip('hi value')
            out.append(f'{el} = ({ty_}){v};')
        elif mn in FLD:
            self.setf(st, ops[0], self.newv(out, ty_, el), ty_)
        else:
            out.append(f'{el} = {self.fval(st, ops[0], ty_)};')

    @staticmethod
    def collapse_structs(args, home):
        """Replace runs of ('spart', name, 0..n-1) argument registers by the struct name
        (a struct parameter passed on by value); returns the new list or None."""
        nregs = {nm: k1 - k0 + 1 for k0, (k1, nm, nw) in home.items()}
        out, j = [], 0
        while j < len(args):
            a = args[j]
            if isinstance(a, tuple) and a[0] == 'spart':
                n = nregs[a[1]]
                if a[2] != 0 or args[j:j + n] != [('spart', a[1], i) for i in range(n)]:
                    return None
                out.append(a[1]); j += n
                continue
            out.append(a); j += 1
        return out

    def rdargs(self, st, names, stop_on_skip=False):
        """Read argument registers; a struct copied from memory (`ld` per full register,
        then `lwz` + `rldicr r,x,32,63`) becomes one `*(ts4_argsN *)(base + off)` argument
        without materialising its loads."""
        regs = st['regs']
        raw = [regs.get(r) for r in names]
        res, j = [], 0
        while j < len(names):
            m = 0
            while j + m < len(names) and isinstance(raw[j + m], V) and getattr(raw[j + m], 'maddr', (0, 0, ''))[2] == 'ld':
                m += 1
            if m and j + m < len(names) and isinstance(raw[j + m], tuple) and raw[j + m][0] == 'mhi':
                bv, off, _ = raw[j + m][1].maddr
                if all(raw[j + i].maddr == (bv, off - 8 * (m - i), 'ld') for i in range(m)):
                    n = 2 * m + 1; self.structs_used.add(n)
                    res.append(f'*(ts4_args{n} *)((char *)(ts4_word)({bv}) + {off - 8 * m})')
                    j += m + 1
                    continue
            if isinstance(raw[j], tuple) and raw[j][0] == 'mhi':
                raise Skip('struct arg')
            try:
                res.append(self.rd(st, names[j]))
            except Skip:
                if stop_on_skip:
                    res.append('__gap')    # filled by a float argument or cut off later
                    j += 1
                    continue
                raise
            j += 1
        while res and res[-1] == '__gap':
            res.pop()
        return res

    def stack_structs(self, args, out):
        """Struct arguments built in a stack local: runs of ('sloc', off), ('sloc', off+8), ...
        (`ld` of 8 bytes each) optionally followed by ('shi', value) (the last word,
        `rldicr r,v,32,31`) become `*(ts4_argsN *)&loc[i]`; the last word is stored first."""
        res, j = [], 0
        while j < len(args):
            a = args[j]
            if not (isinstance(a, tuple) and a[0] == 'sloc'):
                if isinstance(a, tuple) and a[0] == 'shi':
                    raise Skip('struct arg')
                res.append(a); j += 1
                continue
            off = a[1]; n = 1
            while j + n < len(args) and args[j + n] == ('sloc', off + 8 * n):
                n += 1
            nw = 2 * n
            loc = self.local_of(off)
            if loc is None or loc[2] % 4:
                raise Skip('struct arg')
            name, idx = loc[0], loc[1]
            if j + n < len(args) and isinstance(args[j + n], tuple) and args[j + n][0] == 'shi':
                out.append(f'{name}[{idx + nw}] = (ts4_word){args[j + n][1]};')
                nw += 1; n += 1
            b = self.locbase[name]
            self.local_ext[b] = max(self.local_ext[b], idx + nw)
            self.structs_used.add(nw)
            res.append(f'*(ts4_args{nw} *)&{name}[{idx}]')
            j += n
        return res

    def argtype(self, a):
        m = re.match(r'\*\((ts4_args\d+) \*\)', a)
        if m:
            return m.group(1)
        if self.home:
            for k1, nm, nw in self.home.values():
                if a == nm:
                    return f'ts4_args{nw}'
        return 'ts4_word'

    def argcast(self, a):
        """Call argument text: words are cast to ts4_word, struct parameters are passed as they are."""
        if isinstance(a, tuple):     # float argument
            return a[1]
        if self.home and a in {nm for k1, nm, nw in self.home.values()}:
            return a
        if a.startswith('*(ts4_args'):
            return a
        return f'(ts4_word){a}'

    def vrd(self, st, r):
        """Name of vector register r (a parameter `vp<N>` when never written, N in 1..13)."""
        if r in st['vregs']:
            if st['vregs'][r] == '__vclob':
                raise Skip('vreg clobbered')
            return st['vregs'][r]
        n = int(r[1:])
        if 1 <= n <= 13:
            self.vparams.add(n)
            return f'vp{n}'
        raise Skip('vreg')

    def vset(self, st, out, r, e):
        self.ntmp += 1
        nm = f'vv{self.ntmp}'
        self.vdecls.append(nm)
        out.append(f'{nm} = {e};')
        st['vregs'][r] = nm; st['vwritten'].add(r)

    def vmx_step(self, ins, st, out):
        mn, ops = ins.mn, ins.ops
        b = mn[:-3] if mn.endswith('128') else mn
        num = lambda x: int(x, 0)
        self.vec = True
        if b in ('lvlx', 'lvrx', 'stvlx', 'stvrx'):
            ra, rb = ops[1], ops[2]
            base = self.rd(st, rb) if ra == 'r0' else self.rd(st, ra)
            off = '0' if ra == 'r0' else self.rd(st, rb)
            if isinstance(base, tuple) or isinstance(off, tuple):
                raise Skip('hi value')
            if b[0] == 'l':
                self.vset(st, out, ops[0], f'__{b}((void *)({base}), {off})')
            else:
                out.append(f'__{b}({self.vrd(st, ops[0])}, (void *)({base}), {off});')
            return
        if b in ('lvx', 'stvx'):
            ra, rb = ops[1], ops[2]
            addr = self.rd(st, rb) if ra == 'r0' else f'{self.rd(st, ra)} + {self.rd(st, rb)}'
            if isinstance(addr, tuple) or any(isinstance(x, tuple) for x in [st['regs'].get(ra), st['regs'].get(rb)]):
                if ra == 'r0' and isinstance(st['regs'].get(rb), tuple):
                    s_ = st['regs'][rb][1]; self.externs[s_] = 1; addr = f'(ts4_word){s_}'
                else:
                    raise Skip('hi value')
            if b == 'lvx':
                self.vset(st, out, ops[0], f'*(__vector4 *)((ts4_word)({addr}))')
            else:
                out.append(f'*(__vector4 *)((ts4_word)({addr})) = {self.vrd(st, ops[0])};')
            return
        if b == 'vmr':
            st['vregs'][ops[0]] = self.vrd(st, ops[1]); st['vwritten'].add(ops[0]); return
        if b == 'vor' and ops[1] == ops[2]:
            st['vregs'][ops[0]] = self.vrd(st, ops[1]); st['vwritten'].add(ops[0]); return
        if b in VBIN:
            self.vset(st, out, ops[0], f'{VBIN[b]}({self.vrd(st, ops[1])}, {self.vrd(st, ops[2])})'); return
        if b in VUN:
            self.vset(st, out, ops[0], f'{VUN[b]}({self.vrd(st, ops[1])})'); return
        if b in VTRI:
            self.vset(st, out, ops[0], f'{VTRI[b]}({self.vrd(st, ops[1])}, {self.vrd(st, ops[2])}, {self.vrd(st, ops[3])})'); return
        if b in VIMM:
            self.vset(st, out, ops[0], f'{VIMM[b]}({self.vrd(st, ops[1])}, {num(ops[2])})'); return
        if b == 'vspltisw':
            self.vset(st, out, ops[0], f'__vspltisw({num(ops[1])})'); return
        if b == 'vrlimi':
            self.vset(st, out, ops[0], f'__vrlimi({self.vrd(st, ops[0])}, {self.vrd(st, ops[1])}, {num(ops[2])}, {num(ops[3])})'); return
        raise Skip(mn)

    def call(self, ins, st, out):
        mn, sym, rk = ins.mn, ins.sym, ins.rk
        if self.has_vmx:
            if any(v != '__vclob' for v in st['vregs'].values()) or self.vparams:
                raise Skip('vmx call')     # a vector value live across the call
            for n in list(range(0, 14)) + list(range(32, 64)):
                st['vregs'][f'v{n}'] = '__vclob'
        regs = st['regs']; written = st['written']; clobbered = st['clobbered']
        self.calls += 1
        if mn == 'bctrl' and st['ctr'] is None:
            raise Skip('ctr lost')     # mtctr happened in a branch arm
        ctr_reg = st['ctr_reg'] if mn == 'bctrl' else None
        wr = [int(r[1:]) for r in written if r[0] == 'r' and 3 <= int(r[1:]) <= 10 and r not in clobbered and r != ctr_reg]
        if mn == 'bl':
            if rk != 'REL24' or sym.startswith('__'):
                raise Skip('call ' + str(sym))
            ar = self.env.arity(sym)
            if ar is None:  # callee not disassemblable (import, thunk): arguments come from the call setup
                if self.mode == 0:
                    raise Skip('noarity')
                ar = 0
            if self.mode == 3:   # variadic callee: only the registers set up here are arguments
                ar = 0
            nfix = self.env.variadic(sym)
            if nfix is not None:
                ar = max([nfix] + [k - 2 for k in wr if not isinstance(regs.get(f'r{k}'), tuple)])
        else:
            ar = 1
        n = ar
        if self.mode in (1, 3) or mn == 'bctrl':
            while f'r{3 + n}' in written and f'r{3 + n}' != ctr_reg and 3 + n <= 10:
                n += 1
            if mn == 'bctrl':
                n = max(n, 1)
        elif self.mode == 2:  # highest argument register written since the last call
            n = max([n] + [k - 2 for k in wr])
        sa = st['stackargs']
        if sa:
            if sorted(sa) != list(range(len(sa))):
                raise Skip('stack args gap')
            n = 8
        args = self.rdargs(st, [f'r{j}' for j in range(3, 3 + n)], stop_on_skip=True)
        if sa:
            if len(args) != 8:
                raise Skip('stack args regs')
            args += [sa[k] for k in range(len(sa))]; st['stackargs'] = {}
        if self.home and any(isinstance(a, tuple) for a in args):
            args = self.collapse_structs(args, self.home) or args
        if any(isinstance(a, tuple) and a[0] in ('sloc', 'shi') for a in args):
            args = self.stack_structs(args, out)
        if any(isinstance(a, tuple) for a in args) and not sa:
            # a variadic callee homes r3..r10, so its arity overstates the arguments: cut the
            # list where only `lis` temporaries / registers not set up for this call remain
            i = next(k for k, a in enumerate(args) if isinstance(a, tuple))
            if all(isinstance(args[k], tuple) or f'r{k + 3}' not in written or f'r{k + 3}' in clobbered
                   for k in range(i, len(args))):
                args = args[:i]
        if any(isinstance(a, tuple) for a in args):
            raise Skip('hi arg')
        # float arguments: f1, f2, ... in order; each also takes the GPR slot of its position,
        # so they fill the argument positions whose GPR was not set up here
        nf = 0
        while f'f{nf + 1}' in st['fwritten'] and nf < 8:
            nf += 1
        if mn == 'bl' and self.mode != 3:
            nf = max(nf, self.env.farity(sym))
        fargs = []
        for j in range(nf):
            fx = self.fval(st, f'f{j + 1}')
            fargs.append(('f', fx, st['fregs'][f'f{j + 1}'][1] if f'f{j + 1}' in st['fregs'] else self.fparams[f'f{j + 1}']))
        if fargs:
            if sa:
                raise Skip('float stack args')
            pos = [j for j in range(1, len(args)) if f'r{3 + j}' not in written or f'r{3 + j}' in clobbered]
            for j in pos:
                if not fargs:
                    break
                args[j] = fargs.pop(0)
            if '__gap' not in args:
                args += fargs
        if '__gap' in args:
            args = args[:args.index('__gap')]
        cav = ', '.join(self.argcast(a) for a in args)
        if mn == 'bl':
            self.protos[sym] = len(args); call = f'{sym}({cav})'; self.detail.append(sym)
            nfix = self.env.variadic(sym)
            if nfix is not None:
                if any(isinstance(a, tuple) for a in args) or len(args) < nfix:
                    raise Skip('variadic args')
                self.fprotos[sym] = [self.argtype(a) for a in args[:nfix]] + ['...']
            elif any(isinstance(a, tuple) for a in args):
                # float arguments need a prototype (unprototyped calls pass them in GPRs)
                self.fprotos[sym] = [a[2] if isinstance(a, tuple) else self.argtype(a) for a in args]
        else:
            pt = ', '.join(a[2] if isinstance(a, tuple) else self.argtype(a) for a in args)
            call = f'((ts4_word (*)({pt}))({st["ctr"]}))({cav})'
            self.detail.append('vcall'); self.kinds.append('vcall')
        v = self.newv(out, 'ts4_word', call, pure=False)
        v.callsym = sym if mn == 'bl' else '__vcall'
        for r in list(regs):
            if r[0] == 'r' and not r.startswith('__') and 3 <= int(r[1:]) <= 12:
                del regs[r]
        for j in range(4, 13):
            clobbered.add(f'r{j}')
        for j in range(3, 13):
            written.discard(f'r{j}')
        regs['r3'] = v; written.add('r3'); clobbered.discard('r3'); st['ctr'] = None
        for f in list(st['fregs']):     # f14..f31 are preserved by the callee
            if int(f[1:]) < 14:
                del st['fregs'][f]
        st['fwritten'] -= {f'f{j}' for j in range(14)}
        for j in range(0, 14):
            st['clobbered'].add(f'f{j}')
        st['fregs']['f1'] = (v, 'fret'); st['clobbered'].discard('f1')

    def exec_insns(self, insns, st, out):
        self.nsteps += len(insns)
        if self.nsteps > 2500:     # arms that never rejoin duplicate the code behind them
            raise Skip('too big')
        for ins in insns:
            self.step(ins, st, out)

    # ---- returns / tails -----------------------------------------------------
    def finish(self, tail, st, out):
        written = st['written']
        if st['stackargs']:
            raise Skip('stack args unused')
        rd = lambda r: self.rd(st, r)
        if tail != 'ret' and self.has_vmx and (any(v != '__vclob' for v in st['vregs'].values()) or self.vparams):
            raise Skip('vmx tail')
        if tail == 'ret' and 'v1' in st['vwritten'] and 'r3' not in written and 'f1' not in st['fwritten']:
            self.rets.append('__vector4'); out.append(f'return {self.vrd(st, "v1")};')
        elif tail == 'ret':
            r3v = st['regs'].get('r3')
            if 'r3' in written and 'f1' in st['fwritten'] and isinstance(r3v, V) and r3v.callsym and (not r3v.used or r3v.t in ('float', 'double')):
                written = written - {'r3'}      # r3 only holds the ignored result of a call
            if 'r3' in written and 'f1' not in st['fwritten']:
                r3v = st['regs'].get('r3')
                rv = rd('r3')
                if isinstance(rv, tuple):
                    raise Skip('ret hi')
                w64 = (isinstance(r3v, V) and r3v.t == 'ts4_u64') or (isinstance(rv, str) and re.match(r'\(\(ts4_[us]64\)', rv)
                                                                     and not rv.startswith('((ts4_s64)(ts4_word)') and not rv.startswith('((ts4_s64)(int)'))
                self.rets.append('ts4_u64' if w64 else 'ts4_word'); out.append(f'return {rv};')
            elif 'f1' in st['fwritten'] and 'r3' not in written:
                fv, ft = st['fregs']['f1']
                if isinstance(fv, V):
                    fv.used = True; fv = fv.n
                self.rets.append(ft); out.append(f'return {fv};')
            elif 'r3' not in written and self.word_ret and not self.fret_func:
                rv = rd('r3'); self.rets.append('ts4_word'); out.append(f'return {rv};')
            elif 'r3' not in written and self.fret_func:
                ft = self.fret_func      # the incoming f1 is returned unchanged on this path
                self.rets.append(ft); out.append(f'return {self.fval(st, "f1", ft)};')
            elif 'r3' not in written:
                self.rets.append('void'); out.append('return;')
            else:
                raise Skip('both ret')
        elif tail[0] == 'call':
            clobbered = st['clobbered']
            cand = [int(r[1:]) for r in written if r[0] == 'r' and not r.startswith('__') and 3 <= int(r[1:]) <= 10 and r not in clobbered]
            if self.mode in (1, 3):   # contiguous registers set up here, then pass-through up to the callee's arity
                run = 3
                while f'r{run + 1}' in written and f'r{run + 1}' not in clobbered and run < 10:
                    run += 1
                k = max(run, 2 + (self.env.arity(tail[1]) or 0))
                for j in range(run + 1, k + 1):      # a temporary written elsewhere is not an argument
                    if f'r{j}' in written:
                        k = j - 1
                        break
            else:
                k = max([3] + cand + list(self.readp))
            nfix = self.env.variadic(tail[1])
            if nfix is not None:   # `...` callee: the registers set up here (not `lis` temporaries)
                k = max([2 + nfix] + [j for j in cand if not isinstance(st['regs'].get(f'r{j}'), tuple)])
            callargs = self.rdargs(st, [f'r{j}' for j in range(3, k + 1)])
            if self.home and any(isinstance(c, tuple) for c in callargs):
                callargs = self.collapse_structs(callargs, self.home) or callargs
            if any(isinstance(c, tuple) for c in callargs):
                raise Skip('ca hi')
            if nfix is not None:
                self.fprotos[tail[1]] = [self.argtype(a) for a in callargs[:nfix]] + ['...']
            self.protos[tail[1]] = len(callargs); self.detail.append(tail[1]); self.kinds.append('tail')
            self.rets.append('ts4_word'); out.append(f'return {tail[1]}({", ".join(self.argcast(c) for c in callargs)});')
        else:
            if st['ctr'] is None:
                raise Skip('ctr lost')
            wr = [int(r[1:]) for r in written if r[0] == 'r' and not r.startswith('__') and 3 <= int(r[1:]) <= 10
                  and r not in st['clobbered'] and r != st['ctr_reg']]
            # temporaries: the vtable / function pointer loads and the source of a struct's last word
            ctext = str(tail[1])
            for _ in range(3):
                ctext += ' ' + ' '.join(v.e for v in st['regs'].values()
                                        if isinstance(v, V) and re.search(r'\b' + v.n + r'\b', ctext))
            srcs = {id(v[1]) for v in st['regs'].values() if isinstance(v, tuple) and v[0] == 'mhi'}
            def temp(j):
                v = st['regs'].get(f'r{j}')
                return isinstance(v, V) and (id(v) in srcs or re.search(r'\b' + v.n + r'\b', ctext))
            wr = [j for j in wr if not temp(j)]
            if self.mode in (1, 3):
                k = max([3] + wr)                         # only registers the function set up itself
            elif self.mode == 2:
                k = max([3] + wr + list(self.readp))      # plus pass-through parameters it reads
            else:
                k = max([3] + [r + 2 for r in self.readp])
            callargs = self.rdargs(st, [f'r{j}' for j in range(3, k + 1)])
            if self.home and any(isinstance(c, tuple) for c in callargs):
                callargs = self.collapse_structs(callargs, self.home) or callargs
            if any(isinstance(c, tuple) for c in callargs) or isinstance(tail[1], tuple):
                raise Skip('ca hi')
            self.rets.append('ts4_word')
            pt = ', '.join(self.argtype(c) for c in callargs); self.kinds.append('vcall')
            out.append(f'return ((ts4_word (*)({pt}))({tail[1]}))({", ".join(self.argcast(c) for c in callargs)});')

    # ---- conditions ------------------------------------------------------------
    def leaf(self, st, mn, cr):
        """Condition tree "branch `mn` is taken" from the compare recorded for `cr`."""
        if mn in ('bdnz', 'bdz'):
            if st['cnt'] is None:
                raise Skip('ctr lost')
            return ('c', f'--{st["cnt"]}', '!=' if mn == 'bdnz' else '==', '0', False)
        c = st['cmps'].get(cr)
        if c is None:
            raise Skip('br nocmp')
        x, y, isf = c
        if isf:
            op, ng = FBR[mn]
            lf = ('c', x, op, y, True)
            return cfg.neg(lf) if ng else lf
        return ('c', x, BRT[mn], y, False)

    def term_tri(self, term, st):
        _, mn, cr, T, F = term
        e = self.leaf(st, mn, cr)
        return (e, T, F)

    @staticmethod
    def _map_leaves(c, fn):
        if c[0] == 'c':
            return ('c', fn(c[1]), c[2], fn(c[3]), c[4])
        if c[0] == 'not':
            return ('not', Gen._map_leaves(c[1], fn))
        return (c[0], Gen._map_leaves(c[1], fn), Gen._map_leaves(c[2], fn))

    def _inline(self, c, so):
        """Replace names of scratch loads by their expressions inside a condition."""
        def fn(t):
            for v in reversed(so):
                if isinstance(v, V):
                    t = re.sub(r'\b' + v.n + r'\b', lambda m: '(' + v.e + ')', t)
            return t
        return self._map_leaves(c, fn)

    def make_next(self, scratch):
        """Callback for cfg.fold: condition block `nid` as a tuple, using and
        advancing the scratch state `scratch` (a one-element list)."""
        def get_next(nid):
            blk = self.blocks.get(nid)
            if blk is None or blk.term[0] != 'cond' or len(self.preds[nid]) != 1 or nid in self.loops:
                return None
            if any(i.mn not in PURE for i in blk.insns):
                return None
            if self.strict and dst_regs(blk.insns) & self.live_after(blk):
                return None
            sc = self.cp(scratch[0]); so = []
            try:
                self.exec_insns(blk.insns, sc, so)
                e, T, F = self.term_tri(blk.term, sc)
            except Skip:
                return None
            if any(not isinstance(v, V) or not v.pure for v in so):
                return None
            self.pending[nid] = sc
            return (self._inline(e, so), T, F)
        return get_next

    def live_after(self, blk):
        """Registers read (before being rewritten) on some path after block `blk`; calls,
        tail calls and returns read r3..r10 / r3."""
        if self._live is None:
            ARGS = {f'r{j}' for j in range(3, 11)}
            use, dfn = {}, {}
            for b, bl in self.blocks.items():
                u, d = set(), set()
                for i in bl.insns:
                    sr = self.src_regs(i)
                    if i.mn in ('bl', 'bctrl'):
                        sr = sr | ARGS
                    u |= sr - d
                    d |= dst_regs([i])
                t = bl.term[0]
                if t == 'ret':
                    u |= {'r3'} - d
                elif t in ('tail', 'ctr'):
                    u |= ARGS - d
                use[b], dfn[b] = u, d
            live = {b: set(use[b]) for b in self.blocks}
            changed = True
            while changed:
                changed = False
                for b, bl in self.blocks.items():
                    out = set()
                    for sx in cfg.succs(bl):
                        out |= live[sx]
                    new = use[b] | (out - dfn[b])
                    if new != live[b]:
                        live[b] = new; changed = True
            self._live = live
        out = set()
        for sx in cfg.succs(blk):
            out |= self._live[sx]
        return out

    def folded_tri(self, blk, st):
        """The head block's condition folded with absorbed single-use condition
        blocks.  Returns ((cond, A, B), absorbed ids); `st` is not changed
        except that registers written by absorbed blocks become unusable."""
        tri0 = self.term_tri(blk.term, st)
        scratch = [self.cp(st)]
        get_next = self.make_next(scratch)

        def commit(nid):
            scratch[0] = self.pending[nid]
        tri, absorbed = cfg.fold(tri0, get_next, commit)
        regs = st['regs']
        for nid in absorbed:
            for r in dst_regs(self.blocks[nid].insns):
                regs.pop(r, None); st['written'].discard(r); st['clobbered'].add(r)
        return tri, absorbed

    # ---- structurizer ----------------------------------------------------------
    def region(self, bid, stop, st, out, entering=False):
        """Emit blocks from `bid` until a block in `stop` is reached (returned),
        the path terminates (None), a loop back edge is taken ('cont') or a
        do-while latch condition is recorded ('latch').  `entering` lets the
        first block be the header of the loop that is being emitted."""
        while True:
            if self.exits and bid == self.exits[-1] and not entering:
                return 'brk'
            if bid in stop:
                return bid
            if bid in self.active and not entering:
                return 'cont'
            entering = False
            blk = self.blocks[bid]
            if bid in self.loops and bid not in self.active:
                bid = self.emit_loop(bid, stop, st, out)
                if bid is None:
                    return None
                continue
            self.exec_insns(blk.insns, st, out)
            t = blk.term
            k = t[0]
            if k in ('fall', 'jmp'):
                bid = t[1]
            elif k == 'ret':
                self.finish('ret', st, out); return None
            elif k == 'tail':
                self.finish(('call', t[1]), st, out); return None
            elif k == 'ctr':
                self.finish(('ctr', st['ctr']), st, out); return None
            else:
                r = self.cond(bid, blk, stop, st, out)
                if r is None or isinstance(r, str):
                    return r
                bid = r

    def arm(self, start, stop, st, J):
        """Emit one branch arm in a copy of `st`; returns (state, out, reached)."""
        s = self.cp(st); o = []
        r = self.region(start, stop | {J}, s, o)
        return s, o, r

    def cond(self, bid, blk, stop, st, out):
        tri, absorbed = self.folded_tri(blk, st)
        e, A, B = tri
        # do-while latch: a conditional back edge to the loop being emitted
        if self.active:
            h = self.active[-1]
            if A == h or B == h:
                self.latch = (e if A == h else cfg.neg(e), B if A == h else A)
                return 'latch'
        J = cfg.ipdom(self.pdom, bid)
        if self.active and J != cfg.EXIT and J not in self.loops[self.active[-1]] \
                and J != (self.exits[-1] if self.exits else None):
            J = cfg.EXIT      # the arms leave the loop for good: no join to merge at
        if J in absorbed:
            raise Skip('fold join')
        X = self.exits[-1] if self.exits else None
        sA, oA, rA = self.arm(A, stop, st, J) if A != J or (J == X and X is not None) else (None, [], J)
        sB, oB, rB = self.arm(B, stop, st, J) if B != J or (J == X and X is not None) else (None, [], J)
        if (rA == 'brk') != (rB == 'brk'):
            # one arm leaves the loop: `if (c) { ...; break; }` then carry on in the other arm
            (e1, o1, sk, ok2, rk) = (e, oA, sB, oB, rB) if rA == 'brk' else (cfg.neg(e), oB, sA, oA, rA)
            if rk is None:
                raise Skip('break/return mix')
            out.append(('if', cfg.cstr(e1), o1 + ['break;'])); out.extend(ok2)
            for k in sk:
                st[k] = sk[k]
            return rk
        if rA == 'brk' and rB == 'brk':
            raise Skip('double break')
        if (rA is None) != (rB is None):
            # one arm leaves the function (early return, also inside loops): emit it as
            # `if (c) { ...; return; }` and carry on in the other arm's state
            (e1, o1, sk, ok2, rk) = (e, oA, sB, oB, rB) if rA is None else (cfg.neg(e), oB, sA, oA, rA)
            if sk is None:       # the continuing arm is empty: the join block itself
                sk, ok2 = self.cp(st), []
            out.append(('if', cfg.cstr(e1), o1)); out.extend(ok2)
            for k in sk:
                st[k] = sk[k]
            return rk
        for r in (rA, rB):
            if isinstance(r, str) or (r is not None and r != J):
                raise Skip('irregular exit')
        if rA is None and rB is None:
            # both arms leave the function: early-return style `if (c) { ...; return; } ...`
            t = self._if(e, A, B, oA, oB)
            out.append(t[:3]); out.extend(t[3])
            return None
        # both arms reach J
        if A == J and B == J:
            return J
        if A == J:
            self.merge_phi(st, [(sB, oB)], out)
            out.extend(self.unrotate(cfg.cstr(cfg.neg(e)), oB) or [('if', cfg.cstr(cfg.neg(e)), oB)])
        elif B == J:
            self.merge_phi(st, [(sA, oA)], out)
            out.extend(self.unrotate(cfg.cstr(e), oA) or [('if', cfg.cstr(e), oA)])
        else:
            self.merge_phi(st, [(sA, oA), (sB, oB)], None)
            out.append(self._if(e, A, B, oA, oB))
        return J

    @staticmethod
    def unrotate(guard, o):
        """`if (G) { lv = init; do { body } while (C); }` is how the compiler lays out
        `while (P) { body }`.  When G is P with the loop variables replaced by their initial
        values (P = C with the new-value temporaries replaced by the loop variables), return
        the initialisations plus the `while` statement (code after the loop moves to the
        end of the body)."""
        d = [i for i, x in enumerate(o) if isinstance(x, tuple)]
        if len(d) != 1 or o[d[0]][0] != 'do':
            return None
        inits, tail = o[:d[0]], o[d[0] + 1:]
        init_of = {}
        for x in inits:
            m = re.fullmatch(r'(lv\d+) = \(ts4_word\)(.*);', x) if isinstance(x, str) else None
            if not m:
                return None
            init_of[m.group(1)] = m.group(2)
        if not all(isinstance(x, str) and re.match(r'p\d+ = ', x) for x in tail):
            return None
        _, cond, body = o[d[0]]
        new_to_lv = {}
        for x in body:
            m = re.fullmatch(r'(lv\d+) = (p\d+);', x) if isinstance(x, str) else None
            if m:
                new_to_lv[m.group(2)] = m.group(1)
        pred = cond
        for tn, lv in new_to_lv.items():
            pred = re.sub(r'\b' + tn + r'\b', lv, pred)
        first = pred
        for lv, init in init_of.items():
            first = re.sub(r'\b' + lv + r'\b', lambda m: init, first)
        if first != guard or pred == cond:
            return None
        return list(inits) + [('while', pred, body + list(tail))]

    def _if(self, e, A, B, oA, oB):
        """if/else with the lower-addressed (fall-through) arm first; orient 1 flips."""
        if (A < B) == (self.orient == 0):
            return ('if', cfg.cstr(e), oA, oB)
        return ('if', cfg.cstr(cfg.neg(e)), oB, oA)

    # ---- loops -----------------------------------------------------------------
    @staticmethod
    def src_regs(i):
        """General registers read by instruction i."""
        if i.mn in ('bl', 'bctrl', 'mflr', 'mtlr') or i.mn.startswith('b'):
            return set()
        ops = i.ops if (i.mn in NO_DST or i.mn.startswith('st')) else i.ops[1:]
        return {r for o in ops for r in re.findall(r'\br\d+\b', o)}

    def live_in(self, L, h):
        """Registers read before being written on some path through loop blocks L from header h."""
        use, dfn = {}, {}
        for b in L:
            u, d = set(), set()
            for i in self.blocks[b].insns:
                u |= self.src_regs(i) - d
                d |= dst_regs([i])
            use[b], dfn[b] = u, d
        live = {b: set(use[b]) for b in L}
        changed = True
        while changed:
            changed = False
            for b in L:
                out = set()
                for sx in cfg.succs(self.blocks[b]):
                    if sx in L:
                        out |= live[sx]
                new = use[b] | (out - dfn[b])
                if new != live[b]:
                    live[b] = new; changed = True
        return live[h]

    def carried(self, L, st, h):
        """Registers that are written inside loop blocks `L` and live around the back
        edge (read before written in an iteration), with a value before the loop."""
        w = set()
        for b in L:
            w |= dst_regs(self.blocks[b].insns)
        w &= self.live_in(L, h)
        res = []
        for r in sorted(w):
            if r == 'r1' or r.startswith('__') or int(r[1:]) in (0, 2, 13):
                continue
            v = st['regs'].get(r)
            if v is not None:
                if isinstance(v, tuple):
                    raise Skip('loop hi reg')
                if isinstance(v, V):
                    v.used = True
                res.append(r)
            elif 3 <= int(r[1:]) <= 10 and r not in st['clobbered'] and r not in st['regs']:
                res.append(r)
        return res

    @staticmethod
    def f_defs_uses(i):
        """(defined, used) float registers of instruction i."""
        fr = [o for o in i.ops if re.fullmatch(r'f\d+', o)]
        if not fr:
            return set(), set()
        if i.mn.startswith('stf') or i.mn.startswith('fcmp'):
            return set(), set(fr)
        return {fr[0]}, set(fr[1:])

    def float_written(self, L):
        w = set()
        for b in L:
            for i in self.blocks[b].insns:
                w |= self.f_defs_uses(i)[0]
        return w

    def float_carried(self, L, h, fw):
        """True when a float register written in the loop is read before being written in an iteration."""
        use, dfn = {}, {}
        for b in L:
            u, d = set(), set()
            for i in self.blocks[b].insns:
                di, ui = self.f_defs_uses(i)
                u |= ui - d; d |= di
            use[b], dfn[b] = u, d
        live = {b: set(use[b]) for b in L}
        changed = True
        while changed:
            changed = False
            for b in L:
                o = set()
                for sx in cfg.succs(self.blocks[b]):
                    if sx in L:
                        o |= live[sx]
                new = use[b] | (o - dfn[b])
                if new != live[b]:
                    live[b] = new; changed = True
        return bool(live[h] & fw)

    def emit_loop(self, h, stop, st, out):
        L = self.loops[h]
        hb = self.blocks[h]
        if self.has_vmx and not vec_block_local(self.blocks, L):
            raise Skip('vec loop')
        vw = {r for b in L for i in self.blocks[b].insns for r in vuse_def(i)[1]}
        fw = self.float_written(L)
        if fw and self.float_carried(L, h, fw):
            raise Skip('float loop')
        # classify: while-form when the header tests and exactly one successor leaves the loop
        inside = [s for s in cfg.succs(hb) if s in L]
        whileform = hb.term[0] == 'cond' and len(inside) == 1 and inside[0] != h and all(i.mn in PURE for i in hb.insns)
        car = self.carried(L, st, h)
        sw = self.cp(st); sw['cmps'] = {}
        lv = {}
        for r in car:
            val = self.regval(st, r)
            if val is None:
                continue
            n = self.newphi('lv'); lv[r] = n
            out.append(f'{n} = (ts4_word){val};')
            sw['regs'][r] = n; sw['written'].add(r); sw['clobbered'].discard(r)
        self.active.append(h)
        def latch_exit():
            for b in L:
                bb = self.blocks[b]
                if h in cfg.succs(bb) and bb.term[0] == 'cond':
                    o = [x for x in cfg.succs(bb) if x not in L]
                    if len(o) == 1 and o[0] > 0:
                        ob = self.blocks[o[0]]
                        if not ob.insns and ob.term[0] == 'jmp' and ob.term[1] > 0:
                            return ob.term[1]   # `b` over the break block: exit is past it
                        return o[0]
                    return None
            return None
        X = None
        if whileform:
            X = [x for x in cfg.succs(hb) if x not in L]
            X = X[0] if len(X) == 1 and X[0] > 0 else None
        else:
            X = latch_exit()
        self.exits.append(X)
        try:
            if whileform:
                n0 = len(out)
                try:
                    res = self._while(h, hb, L, sw, lv, out)
                except Skip as e:
                    if str(e) not in ('loop body exit', 'loop shape', 'irregular exit'):
                        raise
                    del out[n0:]; self.latch = None
                    self.exits[-1] = latch_exit()
                    res = self._dowhile(h, L, sw, lv, out)
            else:
                res = self._dowhile(h, L, sw, lv, out)
        finally:
            self.active.pop(); self.exits.pop()
        # continue from the loop exit with the exit state
        exit_id, exit_st = res
        for f in fw:
            exit_st['fregs'].pop(f, None); exit_st['fwritten'].discard(f); exit_st['clobbered'].add(f)
        for k in ('regs', 'written', 'clobbered', 'fregs', 'fwritten', 'ctr', 'ctr_reg', 'cmps', 'stackargs', 'cnt'):
            st[k] = exit_st[k]
        for r in vw:
            st['vregs'][r] = '__vclob'
        return exit_id

    def _backedge(self, sb, lv, out):
        """Assign the new values of loop-carried registers at the end of an
        iteration; returns {expression: temp} used to rewrite the latch test."""
        subs = []
        for r, n in lv.items():
            v = self.regval(sb, r)
            if v is None or v == n:
                continue
            tn = self.newphi('p')
            out.append(f'{tn} = (ts4_word){v};')
            subs.append((n, tn, v))
        for n, tn, v in subs:
            out.append(f'{n} = {tn};')
        return {v: tn for n, tn, v in subs}

    def _exit_state(self, s, lv):
        """State at a loop exit: only loop variables and plain locals stay usable."""
        s['cmps'] = {}
        for r in list(s['regs']):
            if r.startswith('__'):
                continue
            v = s['regs'][r]
            if r in lv:
                s['regs'][r] = lv[r]
            elif not isinstance(v, V) and self._mentions_lv(v, lv):
                del s['regs'][r]; s['written'].discard(r); s['clobbered'].add(r)
        return s

    @staticmethod
    def _mentions_lv(v, lv):
        return isinstance(v, str) and any(re.search(r'\b' + n + r'\b', v) for n in lv.values())

    def _while(self, h, hb, L, sw, lv, out):
        # header test evaluated in scratch; its loads are re-issued at the top of the body
        sh = self.cp(sw); so = []
        self.exec_insns(hb.insns, sh, so)
        scratch = [self.cp(sh)]
        e0 = self.term_tri(hb.term, sh)
        get_next = self.make_next(scratch)

        def commit(nid):
            scratch[0] = self.pending[nid]
        (e, A, B), absorbed = cfg.fold(e0, get_next, commit)
        e = self._inline(e, so)
        stay, exitb, stay_c = (A, B, e) if A in L else (B, A, cfg.neg(e))
        if exitb in L or stay not in L:
            raise Skip('loop shape')
        body = [v for v in so if isinstance(v, V)]
        sb = self.cp(sh)
        for nid in absorbed:
            for r in dst_regs(self.blocks[nid].insns):
                sb['regs'].pop(r, None); sb['written'].discard(r); sb['clobbered'].add(r)
        r = self.region(stay, set(), sb, body)
        if r == 'latch' and self.latch is not None:
            # the body ends with a conditional back edge: `while (c) { ...; if (!cont) break; }`
            econt, lexit = self.latch; self.latch = None
            bare = lambda b: self.blocks[b].term == ('ret',) and not self.blocks[b].insns
            if lexit != exitb and not (bare(lexit) and bare(exitb)):
                raise Skip('loop body exit')
            subs = self._backedge(sb, lv, body)
            cs = cfg.cstr(cfg.neg(econt))
            for ex in sorted(subs, key=len, reverse=True):
                cs = cs.replace(ex, subs[ex])
            body.append(('if', cs, ['break;']))
        elif r != 'cont':
            raise Skip('loop body exit')
        else:
            self._backedge(sb, lv, body)
        out.append(('while', cfg.cstr(stay_c), body))
        se = self.cp(sh)
        for v in so:
            for rr in [x for x, y in se['regs'].items() if y is v]:
                del se['regs'][rr]; se['written'].discard(rr); se['clobbered'].add(rr)
        for nid in absorbed:
            for rr in dst_regs(self.blocks[nid].insns):
                se['regs'].pop(rr, None); se['written'].discard(rr); se['clobbered'].add(rr)
        return exitb, self._exit_state(se, lv)

    def _dowhile(self, h, L, sw, lv, out):
        sb = self.cp(sw); body = []
        self.latch = None
        r = self.region(h, set(), sb, body, entering=True)
        if r != 'latch' or self.latch is None:
            raise Skip('loop shape')
        econt, exitb = self.latch; self.latch = None
        subs = self._backedge(sb, lv, body)
        cs = cfg.cstr(econt)
        for ex in sorted(subs, key=len, reverse=True):
            cs = cs.replace(ex, subs[ex])
        out.append(('do', cs, body))
        return exitb, self._exit_state(sb, lv)

    # ---- driver ------------------------------------------------------------------
    def run(self):
        top = []
        st0 = self.newst()
        for r, (name, k) in self.home_reg.items():
            st0['regs'][r] = ('spart', name, k)
        r = self.region(self.order[0], set(), st0, top)
        if r is not None:
            raise Skip('noend')
        return top


def vcall_thunk(lines):
    """Byte offset N when `lines` is exactly the compiler-generated thunk of a
    pointer to a virtual member function (`lwz r12,0(r3); lwz r11,N(r12);
    mtctr r11; bctr`, symbol ??_9Class@@$B...), else None.  emit.py reproduces it
    by taking `&Class::slot` of a class with N/4 earlier virtual functions."""
    if len(lines) != 4:
        return None
    p = [parse(l) for l in lines]
    if [x[0] for x in p] != ['lwz', 'lwz', 'mtctr', 'bctr'] or p[2][1] != ['r11']:
        return None
    def mem(ops):
        m = re.fullmatch(r'(\w+)\((r\d+)\)', ops[1]) if len(ops) == 2 else None
        return (int(m.group(1), 0), m.group(2)) if m else None
    a, b = mem(p[0][1]), mem(p[1][1])
    if a == (0, 'r3') and p[0][1][0] == 'r12' and b and b[1] == 'r12' and p[1][1][0] == 'r11' and b[0] % 4 == 0:
        return b[0]
    return None


def gen(lines_all, env, mode=0, orient=0, infer_signed=True, vol=0):
    """Translate one function (fn_asm lines) to C; see the module docstring.
    `vol` 1 makes stores volatile, 2 loads and stores, 3 loads only.  With `infer_signed`, params and loaded values that are only compared with
    signed compares (cmpwi/cmpw) are declared `int` (the compiler emits cmpwi
    only for signed operands; casts alone are optimised away for ==/!=)."""
    off = vcall_thunk(lines_all)
    if off is not None:
        return dict(kind='vthunk', detail=[f'slot{off // 4}'], sig='', body='', externs=[], protos={},
                    vthunk=off)
    strict = False
    try:
        g = Gen(lines_all, env, mode, orient, infer_signed=infer_signed, vol=vol)
        try:
            top = g.run()
        except Skip as e:
            if str(e) != 'both ret':
                raise
            # r3 is only a leftover call result; the function returns f1: do not merge r3
            g = Gen(lines_all, env, mode, orient, infer_signed=infer_signed, vol=vol)
            g.fret_pref = True
            top = g.run()
    except Skip as e:
        if not str(e).startswith('read r'):
            raise
        # a register written by an absorbed condition block is still needed afterwards:
        # keep such blocks as nested ifs
        strict = True
        g = Gen(lines_all, env, mode, orient, infer_signed=infer_signed, vol=vol, strict=True)
        top = g.run()
    rets = set(g.rets)
    if rets == {'ts4_word', 'void'}:
        # some paths return a value, others leave r3 untouched: return the incoming r3 there
        g = Gen(lines_all, env, mode, orient, word_ret=True, infer_signed=infer_signed, vol=vol, strict=strict)
        top = g.run()
        rets = set(g.rets)
    if len(rets) == 2 and 'void' in rets and rets & {'float', 'double'}:
        # some paths return a float, others leave f1 untouched: return the incoming f1 there
        ft = (rets - {'void'}).pop()
        g = Gen(lines_all, env, mode, orient, infer_signed=infer_signed, vol=vol, strict=strict)
        g.fret_func = ft
        top = g.run()
        rets = set(g.rets)
    if len(rets) != 1:
        raise Skip('mixed rets ' + str(rets))
    rt = rets.pop()
    phis, readp = g.phis, g.readp

    # drop phi variables that are only ever assigned (never read afterwards)
    def phi_uses(stmts, pn, acc):
        for x in stmts:
            if isinstance(x, V):
                acc[1] += len(re.findall(r'\b' + pn + r'\b', x.e))
            elif isinstance(x, tuple):
                acc[1] += len(re.findall(r'\b' + pn + r'\b', x[1]))
                for sub in x[2:]:
                    phi_uses(sub, pn, acc)
            elif re.match(r'\s*' + pn + r' = ', x):
                acc[0] += 1; acc[1] += len(re.findall(r'\b' + pn + r'\b', x[x.index('=') + 1:]))
            else:
                acc[1] += len(re.findall(r'\b' + pn + r'\b', x))

    def phi_strip(stmts, pn):
        stmts[:] = [x for x in stmts if not (isinstance(x, str) and re.match(r'\s*' + pn + r' = ', x))]
        for x in stmts:
            if isinstance(x, tuple):
                for sub in x[2:]:
                    phi_strip(sub, pn)
    changed = True
    while changed:
        changed = False
        for pn in list(phis):
            acc = [0, 0]; phi_uses(top, pn, acc)
            if acc[1] == 0:
                phi_strip(top, pn); phis.remove(pn); changed = True
        for fp in list(g.fphis):
            acc = [0, 0]; phi_uses(top, fp[0], acc)
            if acc[1] == 0:
                phi_strip(top, fp[0]); g.fphis.remove(fp); changed = True

    def flat(stmts):
        r = []
        for x in stmts:
            if isinstance(x, V):
                r.append(x.e)
            elif isinstance(x, tuple):
                r.append(x[1])
                for sub in x[2:]:
                    r.append(flat(sub))
            else:
                r.append(x)
        return ' '.join(r)

    def render(stmts, ind):
        o = []; decls = []

        def txt(x):
            return x.e if isinstance(x, V) else (x if isinstance(x, str) else '\n'.join(render([x], 0)[1]))
        j = 0
        while j < len(stmts) - 1:      # inline single-use loads into the next statement
            x = stmts[j]
            if isinstance(x, V) and x.used and x.e.startswith('*(') and x.pure:
                nxt = stmts[j + 1]
                if isinstance(nxt, (V, str)) and re.search(r'\b' + x.n + r'\b', txt(nxt)) and len(re.findall(r'\b' + x.n + r'\b', flat(top))) == 1:
                    t = re.sub(r'\b' + x.n + r'\b', lambda m: '(' + x.e + ')', txt(nxt))
                    if isinstance(nxt, V):
                        nxt.e = t
                    else:
                        stmts[j + 1] = t
                    del stmts[j]; continue
            j += 1
        for x in stmts:
            if isinstance(x, V):
                if x.used:
                    ty = 'int' if g.infer_signed and x.t == 'ts4_word' and x.n in g.signed and x.n not in g.unsigned else x.t
                    decls.append(f'{ty} {x.n};'); o.append(' ' * ind + f'{x.n} = {x.e};')
                elif not x.e.startswith('*('):
                    o.append(' ' * ind + x.e + ';')
            elif isinstance(x, tuple):
                kind = x[0]
                d2, b2 = render(x[2], ind + 4)
                decls += d2
                if kind == 'do':
                    o.append(' ' * ind + 'do {'); o += b2; o.append(' ' * ind + f'}} while ({x[1]});')
                    continue
                o.append(' ' * ind + f'{kind} ({x[1]}) {{'); o += b2
                if len(x) > 3:
                    d3, b3 = render(x[3], ind + 4); decls += d3
                    o.append(' ' * ind + '} else {'); o += b3
                o.append(' ' * ind + '}')
            else:
                o.append(' ' * ind + x)
        return decls, o
    decls, body_l = render(top, 4)
    decls = [f'{t} {n};' for n, t in g.fphis] + [f'__vector4 {n};' for n in g.vdecls] + [f'ts4_word {n};' for n in phis] + [f'ts4_word {n}[{g.local_ext[g.locbase[n]]}];' for n in g.localnames] + decls
    body = ''.join('    ' + d + '\n' for d in decls) + ('\n' if decls else '') + '\n'.join(body_l) + '\n'
    maxp = max(readp) if readp else 2
    def ptype(j):
        n = f'a{j - 3}'
        if g.infer_signed and n in g.signed and n not in g.unsigned and f'r{j}' not in g.ptype:
            return 'int'
        return g.ptype.get(f'r{j}', 'ts4_word')
    inside = {k for k0, (k1, nm, nw) in g.home.items() for k in range(k0 + 1, k1 + 1)}
    fl_this = False
    if g.home:
        maxp = max([maxp] + [k1 for k0, (k1, nm, nw) in g.home.items()])
    # float parameters take FPRs in order but also use up the GPR slot of their position:
    # put each in the next slot whose GPR is never read
    fl = [f for f in sorted(g.fparams, key=lambda x: int(x[1:]))]
    params = []
    for j in range(3, maxp + 1):
        if j in inside:
            continue
        if j in g.home:
            params.append(f'ts4_args{g.home[j][2]} {g.home[j][1]}')
        elif fl and j not in readp and (j > 3 or not fl_this):
            f = fl.pop(0); params.append(f'{g.fparams[f]} {f}')
        else:
            params.append(f'{ptype(j)} a{j - 3}')
    for f in fl:
        params.append(f'{g.fparams[f]} {f}')
    params += [f'__vector4 vp{n}' for n in sorted(g.vparams)]
    def has(stmts, kinds):
        return any(isinstance(x, tuple) and (x[0] in kinds or any(has(s, kinds) for s in x[2:])) for x in stmts)
    kind = ('loop_' if has(top, ('while', 'do')) else 'if_' if has(top, ('if',)) else '')
    ks = g.kinds
    if g.calls and set(ks) <= {'get', 'set', 'addr'}:
        k0 = 'call_seq'
    else:
        k0 = ks[0] if ks else 'fn'
    if 'tail' in ks and len(ks) == 1:
        k0 = 'tailcall'
    kind += k0
    sig = f'{rt} NAME({", ".join(params) if params else "void"})'
    res = dict(kind=kind, detail=g.detail, sig=sig, body=body, externs=list(g.externs), protos=g.protos, vec=g.vec, intrinsics=sorted(g.intrinsics))
    if g.rtypes:
        res['rtypes'] = dict(g.rtypes)
    if g.fprotos:
        res['fprotos'] = dict(g.fprotos)
    if g.home or g.structs_used:
        res['structs'] = sorted({nw for k1, nm, nw in g.home.values()} | g.structs_used)
    return res
