"""Core translation: PowerPC disassembly lines -> a C function body.

Input is a list of lines in the `tools/fn_asm.py` format
(``ADDRESS  WORDHEX  mnemonic operands   ; RELOCKIND symbol``).  `gen()`
walks the instructions with a tiny symbolic executor (registers hold C
expressions, loads become lazily materialised locals) and returns a dict
``kind, detail, sig, body, externs, protos`` or raises `Skip(reason)` when the
shape is not supported.  The result is *not* guaranteed to compile to the same
bytes; `emit.py` verifies every candidate with tools/fn_check.py.

Variants: `mode` 1 also counts contiguously-written argument registers after
a call setup (callee arity otherwise comes from `env.arity`), mode 2 counts every argument register written up to the highest one, `orient` picks
which branch arm becomes the `if` body for non-returning diamonds.
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

class Env:
    """Callee knowledge needed by gen(): arity(sym) -> int | None.
    `lookup(sym)` must return the disassembly lines of a named function or None."""
    def __init__(s,lookup,sym_at=lambda a:None): s.lookup=lookup; s.sym_at=sym_at; s._cache={}
    def arity(s,sym):
        if sym not in s._cache:
            L=s.lookup(sym)
            if L: L=annotate(L,s)
            s._cache[sym]=arity(L,lambda x:(annotate(s.lookup(x),s) if s.lookup(x) else None)) if L else None
        return s._cache[sym]

LD = {'lwz': ('ts4_word', 'u32'), 'lhz': ('unsigned short', 'u16'), 'lha': ('short', 's16'), 'lbz': ('unsigned char', 'u8')}
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


class V:
    """A lazily materialised local (a load or call result); `used` is set when read."""
    def __init__(s, t, e, n, pure=True):
        s.t = t; s.e = e; s.n = n; s.used = False; s.pure = pure


def dst_regs(insns):
    """General registers written by `insns` (calls clobber r3..r12 separately)."""
    out = set()
    for i in insns:
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

    def __init__(self, lines, env, mode=0, orient=0):
        self.env, self.mode, self.orient = env, mode, orient
        if unrelocated(lines):
            raise Skip('unrelocated original')
        self.lines = annotate(lines, env)
        self.insns = cfg.decode(self.lines, parse)
        self.order, self.blocks = cfg.build_blocks(self.insns)
        self.preds = cfg.preds_of(self.blocks)
        self.loops = cfg.natural_loops(self.order, self.blocks)
        self.pdom = cfg.post_dominators(self.blocks)
        self.active = []          # loop headers being emitted (innermost last)
        self.latch = None         # (continue condition, exit block) recorded by a do-while latch
        self._stack_layout()
        self.ntmp = 0
        self.externs = {}; self.protos = {}; self.detail = []; self.kinds = []
        self.ptype = {}; self.fparams = {}; self.readp = set(); self.phis = []
        self.calls = 0; self.rets = []; self.localnames = []
        self.pending = {}

    # ---- stack locals ------------------------------------------------------
    def _stack_layout(self):
        """Every `addi rX,r1,off` takes the address of a word array starting at
        off and extending to the next such base / last access."""
        L = self.lines
        bases = sorted({int(m.group(1), 0) for l in L for m in [re.search(r'\baddi\s+r(?!1\b)\d+,\s*r1,\s*(-?\w+)', l)] if m})
        acc = [int(m.group(1), 0) for l in L for m in [re.search(r'\b(?:lwz|stw)\s+\w+,\s*(-?\w+)\(r1\)', l)] if m]
        self.bases = bases
        self.local_ext = {}
        for i, b in enumerate(bases):
            nxt = bases[i + 1] if i + 1 < len(bases) else 1 << 30
            top = max([a for a in acc if b <= a < nxt] + [b])
            self.local_ext[b] = (top - b) // 4 + 1

    def local_of(self, off):
        for b in self.bases:
            if b <= off < b + 4 * self.local_ext[b]:
                if (off - b) % 4:
                    raise Skip('stack unaligned')
                return f'loc{b:x}', (off - b) // 4
        return None

    # ---- state -------------------------------------------------------------
    @staticmethod
    def newst():
        return dict(regs={}, written=set(), clobbered=set(), fregs={}, fwritten=set(), ctr=None,
                    ctr_reg=None, cmps={}, stackargs={})

    @staticmethod
    def cp(st):
        return {k: (v.copy() if hasattr(v, 'copy') else v) for k, v in st.items()}

    def rd(self, st, r):
        regs = st['regs']
        if r in regs:
            v = regs[r]
            if isinstance(v, V):
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
        names = set()
        for s, o in arms:
            names |= set(s['written']) | set(s['regs']) | set(s['clobbered'])
        for r in sorted(names):
            if r.startswith('__'):
                continue
            changed = any(s['regs'].get(r) is not regs0.get(r) or (r in s['clobbered'] and r not in st['clobbered']) for s, o in arms)
            if not changed:
                continue
            vals = [self.regval(s, r) for s, o in arms]
            pre = self.regval(st, r) if pre_out is not None else 0
            if pre_out is not None and pre is None:
                vals = [None]
            if any(v is None for v in vals) or r[0] != 'r' or r == 'r1':
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
            v = st['fregs'][f][0]
            if isinstance(v, V):
                v.used = True
                return v.n
            return v
        if f not in ('f1', 'f2', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8') or f in st['clobbered']:
            raise Skip('freg')
        self.fparams.setdefault(f, t)
        return f

    def setf(self, st, f, e, t='float'):
        st['fregs'][f] = (e, t); st['fwritten'].add(f)

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
            st['cmps'][cr] = (f'({cast}){a}', f'({cast}){b}' if reg2 else b, False)
            return
        if mn in ('fcmpu', 'fcmpo'):
            cr = ops[0]
            st['cmps'][cr] = (self.fval(st, ops[1]), self.fval(st, ops[2]), True)
            return
        if mn.endswith('.') and mn not in ('andi.', 'andis.'):
            base = mn[:-1]
            if base in ('subic', 'addic', 'stwcx', 'stdcx', 'subfe', 'subfc', 'addze'):
                raise Skip(mn)
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
        if mn in LD or mn in ST or mn in FLD or mn in FST or mn in ('ld',):
            mo = re.match(r'(-?\w+)\((r\d+)\)', ops[1]); off = num(mo.group(1)); base = mo.group(2)
            if base == 'r1':
                if off < 0:
                    return
                loc = self.local_of(off)
                if loc is not None:
                    if mn not in ('lwz', 'stw'):
                        raise Skip('stack local size')
                    el = f'{loc[0]}[{loc[1]}]'
                    if loc[0] not in self.localnames:
                        self.localnames.append(loc[0])
                    if mn == 'lwz':
                        setr(ops[0], self.newv(out, 'ts4_word', el))
                    else:
                        v = rd(ops[0]); nohi(v)
                        out.append(f'{el} = (ts4_word){v};')
                    return
                if mn == 'stw' and off >= 0x54 and (off - 0x54) % 8 == 0:
                    v = rd(ops[0]); nohi(v)
                    st['stackargs'][(off - 0x54) // 8] = v
                    return
                raise Skip('stack')
            if mn == 'ld':
                raise Skip('ld')
            if rk == 'REFLO' and isinstance(regs.get(base), tuple):
                s = regs[base][1]; self.externs[s] = 1; addr_e = f'{s}'
            else:
                if rk:
                    raise Skip('reloc mem')
                bv = rd(base); nohi(bv)
                addr_e = f'((char *)(ts4_word)({bv}) + {off})'
            if mn in LD:
                t, ty = LD[mn]
                setr(ops[0], self.newv(out, t, f'*({t} *){addr_e}'))
                self.detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); self.kinds.append('get')
            elif mn in ST:
                t, ty = ST[mn]; r = ops[0]
                if mn == 'std':
                    self.ptype[r] = 'ts4_u64'
                v = rd(r); nohi(v)
                out.append(f'*({t} *){addr_e} = ({t}){v};')
                self.detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); self.kinds.append('set')
            elif mn in FLD:
                t, ty = FLD[mn]
                v = self.newv(out, t, f'*({t} *){addr_e}'); self.setf(st, ops[0], v, t); self.kinds.append('get')
            else:
                t, ty = FST[mn]; fv = self.fval(st, ops[0], t)
                out.append(f'*({t} *){addr_e} = {fv};'); self.kinds.append('set')
            return
        if mn in IDX_LD:
            t = IDX_LD[mn]; a = rd(ops[1]); b = rd(ops[2]); nohi(a, b)
            setr(ops[0], self.newv(out, t, f'*({t} *)((char *)(ts4_word)({a}) + {b})')); self.kinds.append('get')
            return
        if mn in IDX_ST:
            t = IDX_ST[mn]; v = rd(ops[0]); a = rd(ops[1]); b = rd(ops[2]); nohi(v, a, b)
            out.append(f'*({t} *)((char *)(ts4_word)({a}) + {b}) = ({t}){v};'); self.kinds.append('set')
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
            if ops[1] == 'r1' and mn == 'addi' and rk is None:
                loc = self.local_of(num(ops[2]))
                if loc is None:
                    raise Skip('stack addr')
                if loc[0] not in self.localnames:
                    self.localnames.append(loc[0])
                setr(ops[0], f'(ts4_word)&{loc[0]}[{loc[1]}]')
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
            e = {'add': f'({a} + {b})', 'subf': f'({b} - {a})', 'and': f'({a} & {b})', 'or': f'({a} | {b})',
                 'xor': f'({a} ^ {b})', 'andc': f'({a} & ~{b})', 'nor': f'(~({a} | {b}))',
                 'mullw': f'((int){a} * (int){b})', 'divw': f'((int){a} / (int){b})', 'divwu': f'({a} / {b})',
                 'slw': f'({a} << {b})', 'srw': f'({a} >> {b})', 'sraw': f'((int){a} >> {b})'}[mn]
            setr(ops[0], e); return
        if mn == 'neg':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'(-(int){a})'); return
        if mn == 'mulli':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((int){a} * {num(ops[2])})'); return
        if mn == 'subfic':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'({num(ops[2])} - {a})'); return
        if mn in ('ori', 'oris', 'xori', 'xoris'):
            a = rd(ops[1]); nohi(a)
            v = num(ops[2]) << (16 if mn.endswith('is') else 0)
            setr(ops[0], f'({a} {"^" if mn.startswith("xor") else "|"} {v})'); return
        if mn in ('slwi', 'srwi', 'srawi'):
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            setr(ops[0], {'slwi': f'({a} << {n})', 'srwi': f'(({a}) >> {n})', 'srawi': f'((int){a} >> {n})'}[mn]); return
        if mn in ('clrlwi', 'clrrwi'):
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            m = (1 << (32 - n)) - 1 if mn == 'clrlwi' else (0xFFFFFFFF << n) & 0xFFFFFFFF
            setr(ops[0], f'({a} & {hex(m)})'); return
        if mn == 'rotlwi':
            a = rd(ops[1]); nohi(a); n = num(ops[2])
            setr(ops[0], f'(({a} << {n}) | ({a} >> {32 - n}))'); return
        if mn == 'rlwinm':
            a = rd(ops[1]); nohi(a); sh, mb, me = num(ops[2]), num(ops[3]), num(ops[4])
            if mb <= me:
                mask = ((1 << (me - mb + 1)) - 1) << (31 - me)
            else:
                mask = 0xFFFFFFFF ^ (((1 << (mb - me - 1)) - 1) << (31 - mb + 1))
            r = f'(({a} << {sh}) | ({a} >> {32 - sh}))' if sh else a
            setr(ops[0], f'({r} & {hex(mask)})'); return
        if mn == 'cntlzw':
            a = rd(ops[1]); nohi(a); setr(ops[0], ('clz', a)); return
        if mn == 'extrwi' and isinstance(regs.get(ops[1]), tuple) and regs[ops[1]][0] == 'clz' and ops[2] == '1' and num(ops[3]) == 26:
            setr(ops[0], f'({regs[ops[1]][1]} == 0)'); return
        if mn == 'extrwi':
            a = rd(ops[1]); nohi(a); n, b = num(ops[2]), num(ops[3])
            setr(ops[0], f'(({a} >> {32 - n - b}) & {hex((1 << n) - 1)})'); return
        if mn == 'extsb':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((signed char){a})'); return
        if mn == 'extsh':
            a = rd(ops[1]); nohi(a); setr(ops[0], f'((short){a})'); return
        if mn in ('subic', 'addic'):
            regs['__ca'] = rd(ops[1]); regs[ops[0]] = '__x'; written.add(ops[0]); return
        if mn == 'subfe':
            if '__ca' not in regs:
                raise Skip('subfe')
            setr(ops[0], f'({regs["__ca"]} != 0)'); return
        if mn == 'mtctr':
            st['ctr'] = rd(ops[0]); st['ctr_reg'] = ops[0]; return
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

    def call(self, ins, st, out):
        mn, sym, rk = ins.mn, ins.sym, ins.rk
        regs = st['regs']; written = st['written']; clobbered = st['clobbered']
        self.calls += 1
        ctr_reg = st['ctr_reg'] if mn == 'bctrl' else None
        wr = [int(r[1:]) for r in written if r[0] == 'r' and 3 <= int(r[1:]) <= 10 and r not in clobbered and r != ctr_reg]
        if mn == 'bl':
            if rk != 'REL24' or sym.startswith('__'):
                raise Skip('call ' + str(sym))
            ar = self.env.arity(sym)
            if ar is None:
                raise Skip('noarity')
        else:
            ar = 1
        n = ar
        if self.mode == 1 or mn == 'bctrl':
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
        args = []
        for j in range(3, 3 + n):
            try:
                args.append(self.rd(st, f'r{j}'))
            except Skip:
                break
        if sa:
            if len(args) != 8:
                raise Skip('stack args regs')
            args += [sa[k] for k in range(len(sa))]; st['stackargs'] = {}
        if any(isinstance(a, tuple) for a in args):
            raise Skip('hi arg')
        cav = ', '.join(f'(ts4_word){a}' for a in args)
        if mn == 'bl':
            self.protos[sym] = len(args); call = f'{sym}({cav})'; self.detail.append(sym)
        else:
            pt = ', '.join(['ts4_word'] * len(args)); call = f'((ts4_word (*)({pt}))({st["ctr"]}))({cav})'
            self.detail.append('vcall'); self.kinds.append('vcall')
        v = self.newv(out, 'ts4_word', call, pure=False)
        for r in list(regs):
            if r[0] == 'r' and not r.startswith('__') and 3 <= int(r[1:]) <= 12:
                del regs[r]
        for j in range(4, 13):
            clobbered.add(f'r{j}')
        for j in range(3, 13):
            written.discard(f'r{j}')
        regs['r3'] = v; written.add('r3'); clobbered.discard('r3'); st['ctr'] = None
        for f in list(st['fregs']):
            del st['fregs'][f]
        st['fwritten'].clear()

    def exec_insns(self, insns, st, out):
        for ins in insns:
            self.step(ins, st, out)

    # ---- returns / tails -----------------------------------------------------
    def finish(self, tail, st, out):
        written = st['written']
        if st['stackargs']:
            raise Skip('stack args unused')
        rd = lambda r: self.rd(st, r)
        if tail == 'ret':
            if 'r3' in written and 'f1' not in st['fwritten']:
                rv = rd('r3')
                if isinstance(rv, tuple):
                    raise Skip('ret hi')
                self.rets.append('ts4_word'); out.append(f'return {rv};')
            elif 'f1' in st['fwritten'] and 'r3' not in written:
                fv, ft = st['fregs']['f1']
                if isinstance(fv, V):
                    fv.used = True; fv = fv.n
                self.rets.append(ft); out.append(f'return {fv};')
            elif 'r3' not in written:
                self.rets.append('void'); out.append('return;')
            else:
                raise Skip('both ret')
        elif tail[0] == 'call':
            clobbered = st['clobbered']
            cand = [int(r[1:]) for r in written if r[0] == 'r' and not r.startswith('__') and 3 <= int(r[1:]) <= 10 and r not in clobbered]
            k = max([3] + cand + list(self.readp)); callargs = [rd(f'r{j}') for j in range(3, k + 1)]
            if any(isinstance(c, tuple) for c in callargs):
                raise Skip('ca hi')
            self.protos[tail[1]] = len(callargs); self.detail.append(tail[1]); self.kinds.append('tail')
            self.rets.append('ts4_word'); out.append(f'return {tail[1]}({", ".join("(ts4_word)" + c for c in callargs)});')
        else:
            k = max([3] + [r + 2 for r in self.readp]); callargs = [rd(f'r{j}') for j in range(3, k + 1)]
            pt = ', '.join(['ts4_word'] * len(callargs)); self.kinds.append('vcall')
            self.rets.append('ts4_word')
            out.append(f'return ((ts4_word (*)({pt}))({tail[1]}))({", ".join("(ts4_word)" + c for c in callargs)});')

    # ---- conditions ------------------------------------------------------------
    def leaf(self, st, mn, cr):
        """Condition tree "branch `mn` is taken" from the compare recorded for `cr`."""
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
        if J in absorbed:
            raise Skip('fold join')
        sA, oA, rA = self.arm(A, stop, st, J) if A != J else (None, [], J)
        sB, oB, rB = self.arm(B, stop, st, J) if B != J else (None, [], J)
        for r in (rA, rB):
            if isinstance(r, str) or (r is not None and r != J):
                raise Skip('irregular exit')
        if rA is None and rB is None:
            # both arms leave the function: early-return style `if (c) { ...; return; } ...`
            t = self._if(e, A, B, oA, oB)
            out.append(t[:3]); out.extend(t[3])
            return None
        if rA is None or rB is None:
            raise Skip('arm terminates')
        # both arms reach J
        if A == J and B == J:
            return J
        if A == J:
            self.merge_phi(st, [(sB, oB)], out)
            out.append(('if', cfg.cstr(cfg.neg(e)), oB))
        elif B == J:
            self.merge_phi(st, [(sA, oA)], out)
            out.append(('if', cfg.cstr(e), oA))
        else:
            self.merge_phi(st, [(sA, oA), (sB, oB)], None)
            out.append(self._if(e, A, B, oA, oB))
        return J

    def _if(self, e, A, B, oA, oB):
        """if/else with the lower-addressed (fall-through) arm first; orient 1 flips."""
        if (A < B) == (self.orient == 0):
            return ('if', cfg.cstr(e), oA, oB)
        return ('if', cfg.cstr(cfg.neg(e)), oB, oA)

    # ---- loops -----------------------------------------------------------------
    def carried(self, L, st):
        """Registers written inside loop blocks `L` that have a value before the loop."""
        w = set()
        for b in L:
            w |= dst_regs(self.blocks[b].insns)
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

    def emit_loop(self, h, stop, st, out):
        L = self.loops[h]
        hb = self.blocks[h]
        # classify: while-form when the header tests and exactly one successor leaves the loop
        inside = [s for s in cfg.succs(hb) if s in L]
        whileform = hb.term[0] == 'cond' and len(inside) == 1 and inside[0] != h and all(i.mn in PURE for i in hb.insns)
        car = self.carried(L, st)
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
        try:
            if whileform:
                res = self._while(h, hb, L, sw, lv, out)
            else:
                res = self._dowhile(h, L, sw, lv, out)
        finally:
            self.active.pop()
        # continue from the loop exit with the exit state
        exit_id, exit_st = res
        for k in ('regs', 'written', 'clobbered', 'fregs', 'fwritten', 'ctr', 'ctr_reg', 'cmps', 'stackargs'):
            st[k] = exit_st[k]
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
        if r != 'cont':
            raise Skip('loop body exit')
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
        r = self.region(self.order[0], set(), st0, top)
        if r is not None:
            raise Skip('noend')
        return top


def gen(lines_all, env, mode=0, orient=0):
    """Translate one function (fn_asm lines) to C; see the module docstring."""
    g = Gen(lines_all, env, mode, orient)
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
                    decls.append(f'{x.t} {x.n};'); o.append(' ' * ind + f'{x.n} = {x.e};')
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
    decls = [f'ts4_word {n};' for n in phis] + [f'ts4_word {n}[{g.local_ext[int(n[3:], 16)]}];' for n in g.localnames] + decls
    body = ''.join('    ' + d + '\n' for d in decls) + ('\n' if decls else '') + '\n'.join(body_l) + '\n'
    maxp = max(readp) if readp else 2
    params = [f'{g.ptype.get(f"r{j}", "ts4_word")} a{j - 3}' for j in range(3, maxp + 1)]
    for f in sorted(g.fparams):
        params.append(f'{g.fparams[f]} {f}')
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
    return dict(kind=kind, detail=g.detail, sig=sig, body=body, externs=list(g.externs), protos=g.protos)
