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

class Skip(Exception):
    """Raised when an instruction/shape is unsupported; str() is the category."""

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

LD={'lwz':('ts4_word','u32'),'lhz':('unsigned short','u16'),'lha':('short','s16'),'lbz':('unsigned char','u8')}
ST={'stw':('ts4_word','u32'),'sth':('unsigned short','u16'),'stb':('unsigned char','u8'),'std':('ts4_u64','u64')}
FLD={'lfs':('float','f32'),'lfd':('double','f64')}
FST={'stfs':('float','f32'),'stfd':('double','f64')}
class V:  # lazily materialised local
    def __init__(s,t,e,n): s.t=t; s.e=e; s.n=n; s.used=False

BR={'beq':('!=','=='),'bne':('==','!='),'blt':('>=','<'),'bge':('<','>='),'bgt':('<=','>'),'ble':('>','<=')}
def gen(lines_all,env,mode=0,orient=0):
    
    lines_all=annotate(lines_all,env)
    addrs=[int(l[:8],16) for l in lines_all]
    # stack locals: every `addi rX,r1,off` takes the address of a word array
    # starting at off and extending to the next such base / last access.
    bases=sorted({int(m.group(1),0) for l in lines_all for m in [re.search(r'\baddi\s+r(?!1\b)\d+,\s*r1,\s*(-?\w+)',l)] if m})
    accesses=[int(m.group(1),0) for l in lines_all for m in [re.search(r'\b(?:lwz|stw)\s+\w+,\s*(-?\w+)\(r1\)',l)] if m]
    local_ext={}
    for i,b in enumerate(bases):
        nxt=bases[i+1] if i+1<len(bases) else 1<<30
        top=max([a for a in accesses if b<=a<nxt]+[b])
        local_ext[b]=(top-b)//4+1
    localnames=[]
    def local_of(off):
        for b in bases:
            if b<=off<b+4*local_ext[b]:
                if (off-b)%4: raise Skip('stack unaligned')
                return f'loc{b:x}',(off-b)//4
        return None
    ntmp=[0]; externs={}; protos={}; detail=[]; kinds=[]; ptype={}; fparams={}
    readp=set(); counters={'calls':0,'rets':[]}
    def newst():
        return dict(regs={},written=set(),clobbered=set(),fregs={},fwritten=set(),ctr=None,ctr_reg=None,cmp=None,stackargs={})
    def cp(st):
        n={k:(v.copy() if hasattr(v,'copy') else v) for k,v in st.items()}
        return n
    phis=[]
    def regval(s,r):
        """current value of register r in state s (params count), or None"""
        if r in s['regs']:
            v=s['regs'][r]
            if isinstance(v,V): v.used=True; return v.n
            return None if isinstance(v,tuple) else v
        n=int(r[1:]) if r[0]=='r' else 0
        if r[0]=='r' and 3<=n<=10 and r not in s['clobbered']:
            readp.add(n); return f'a{n-3}'
        return None
    def merge_phi(st,arms,pre_out):
        """Registers changed by the branch arms are merged into a phi variable
        (assigned in every arm; for a one-armed if the old value is assigned
        first into pre_out). Registers without a value in every path become
        unusable (clobbered)."""
        regs0=st['regs']
        names=set()
        for s,o in arms: names|=set(s['written'])|set(s['regs'])|set(s['clobbered'])
        for r in sorted(names):
            if r=='__ca': continue
            changed=any(s['regs'].get(r) is not regs0.get(r) or (r in s['clobbered'] and r not in st['clobbered']) for s,o in arms)
            if not changed: continue
            vals=[regval(s,r) for s,o in arms]
            pre=regval(st,r) if pre_out is not None else 0
            if pre_out is not None and pre is None: vals=[None]
            if any(v is None for v in vals) or r[0]!='r' or r=='r1':
                regs0.pop(r,None); st['written'].discard(r); st['clobbered'].add(r); continue
            ntmp[0]+=1; pn=f'p{ntmp[0]}'; phis.append(pn)
            if pre_out is not None: pre_out.append(f'{pn} = (ts4_word){pre};')
            for (s,o),v in zip(arms,vals): o.append(f'{pn} = (ts4_word){v};')
            regs0[r]=pn; st['written'].add(r); st['clobbered'].discard(r)
    def run(lines,st,out):
        regs=st['regs']; written=st['written']; clobbered=st['clobbered']; fregs=st['fregs']; fwritten=st['fwritten']
        def rd(r):
            if r in regs:
                v=regs[r]
                if isinstance(v,V): v.used=True; return v.n
                return v
            n=int(r[1:])
            if n<3 or n>10 or r in clobbered: raise Skip('read '+r)
            readp.add(n); return f'a{n-3}'
        def newv(t,e):
            ntmp[0]+=1; v=V(t,e,f't{ntmp[0]}'); out.append(v); return v
        i=0
        while i<len(lines):
            ln=lines[i]; i+=1
            mn,ops,rk,sym=parse(ln)
            if mn in('mflr','mtlr'): continue
            if mn=='bl' and sym and sym.startswith('__savegprlr'): continue
            if mn=='stwu' and ops[0]=='r1': continue
            if mn=='addi' and ops[0]=='r1' and ops[1]=='r1': continue
            if mn in('cmplwi','cmpwi','cmplw','cmpw'):
                o=[x for x in ops if not x.startswith('cr')]
                a=rd(o[0]); b=rd(o[1]) if mn in('cmplw','cmpw') else str(int(o[1],0))
                if isinstance(a,tuple): raise Skip('hi cmp')
                cast='ts4_word' if mn in('cmplwi','cmplw') else 'int'
                st['cmp']=(f'({cast}){a}',f'({cast}){b}' if mn in('cmplw','cmpw') else b); continue
            if mn[-2:]=='lr' and mn[:-2] in BR and mn!='blr':
                if st['cmp'] is None: raise Skip('lr nocmp')
                x,y=st['cmp']; cond=f'{x} {BR[mn[:-2]][1]} {y}'
                s1=cp(st); o1=[]; finish('ret',s1,o1)
                out.append(('if',cond,o1)); st['cmp']=None; continue
            if mn in BR and (rk is None or True) and mn!='b':
                # conditional forward branch: ops[-1] like "0x18 -> 0x88167cf4"
                if st['cmp'] is None: raise Skip('br nocmp')
                m=re.search(r'->\s*0x([0-9a-f]+)',ln)
                if not m: raise Skip('br target')
                tgt=int(m.group(1),16)
                if tgt not in addrs: raise Skip('br out')
                ti=addrs.index(tgt)
                cur=addrs[len(lines_all)-len(lines)+i-1] if False else None
                rest_idx=i  # then-block = lines[i:k], else = lines at tgt
                ti_rel=[j for j in range(len(lines)) if addrs.index(int(lines[j][:8],16))==ti]
                if not ti_rel: raise Skip('br tgt not forward')
                tj=ti_rel[0]
                if tj<i: raise Skip('backward')
                then_l=lines[i:tj]; else_l=lines[tj:]
                # then block must end in a return
                lastmn=parse(then_l[-1])[0] if then_l else ''
                x,y=st['cmp']
                fall_c=f'{x} {BR[mn][0]} {y}'; br_c=f'{x} {BR[mn][1]} {y}'
                st['cmp']=None
                if lastmn not in('blr','bctr') and not (lastmn=='b' and (parse(then_l[-1])[3] or '').startswith('__restgprlr')):
                    if parse(then_l[-1])[0]=='b' and parse(then_l[-1])[2] is None and not any(parse(l)[0]=='b' for l in then_l[:-1]):
                        m2=re.search(r'->\s*0x([0-9a-f]+)',then_l[-1])
                        t2=int(m2.group(1),16)
                        if t2 not in addrs: raise Skip('else end out')
                        j2=[j for j in range(len(lines)) if int(lines[j][:8],16)==t2]
                        if not j2 or j2[0]<tj: raise Skip('else end')
                        j2=j2[0]
                        else_b=lines[tj:j2]; cont=lines[j2:]
                        s1=cp(st); s2=cp(st); o1=[]; o2=[]
                        run_noend(then_l[:-1],s1,o1); run_noend(else_b,s2,o2)
                        merge_phi(st,[(s1,o1),(s2,o2)],None)
                        out.append(('if',fall_c,o1,o2))
                        lines=cont; i=0; continue
                    if any(parse(l)[0]=='b' for l in then_l): raise Skip('then has b')
                    s1=cp(st); o1=[]
                    ret_before=len(counters['rets'])
                    run_noend(then_l,s1,o1)
                    merge_phi(st,[(s1,o1)],out)
                    out.append(('if',fall_c,o1))
                    lines=lines[tj:]; i=0
                    continue
                s1=cp(st); s2=cp(st)
                o1=[]; o2=[]
                run(then_l,s1,o1); run(else_l,s2,o2)
                if orient==0: out.append(('if',fall_c,o1)); out.extend(o2)
                else: out.append(('if',br_c,o2)); out.extend(o1)
                return
            if mn=='b' and sym and sym.startswith('__restgprlr'):
                finish('ret',st,out); return
            if mn in LD or mn in ST or mn in FLD or mn in FST or mn in('ld','std'):
                mo=re.match(r'(-?\w+)\((r\d+)\)',ops[1]); off=int(mo.group(1),0); base=mo.group(2)
                if base=='r1':
                    if off<0: continue
                    loc=local_of(off)
                    if loc is not None:
                        if mn not in('lwz','stw'): raise Skip('stack local size')
                        el=f'{loc[0]}[{loc[1]}]'
                        if loc[0] not in localnames: localnames.append(loc[0])
                        if mn=='lwz': regs[ops[0]]=newv('ts4_word',el); written.add(ops[0]); clobbered.discard(ops[0])
                        else:
                            v=rd(ops[0])
                            if isinstance(v,tuple): raise Skip('hi store')
                            out.append(f'{el} = (ts4_word){v};')
                        continue
                    if mn=='stw' and off>=0x54 and (off-0x54)%8==0:
                        v=rd(ops[0])
                        if isinstance(v,tuple): raise Skip('hi store')
                        st['stackargs'][(off-0x54)//8]=v; continue
                    raise Skip('stack')
                if mn=='ld': raise Skip('ld')
                if rk=='REFLO' and isinstance(regs.get(base),tuple):
                    s=regs[base][1]; externs[s]=1; addr_e=f'{s}'
                else:
                    if rk: raise Skip('reloc mem')
                    addr_e=f'((char *)(ts4_word)({rd(base)}) + {off})'
                if mn in LD:
                    t,ty=LD[mn]; regs[ops[0]]=newv(t,f'*({t} *){addr_e}'); written.add(ops[0]); clobbered.discard(ops[0]); detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); kinds.append('get')
                elif mn in ST:
                    t,ty=ST[mn]; r=ops[0]
                    if mn=='std': ptype[r]='ts4_u64'
                    v=rd(r)
                    if isinstance(v,tuple): raise Skip('hi store')
                    out.append(f'*({t} *){addr_e} = ({t}){v};'); detail.append(f'{ty}@{off:#x}' if not rk else f'{ty}@{addr_e}'); kinds.append('set')
                elif mn in FLD:
                    t,ty=FLD[mn]; v=newv(t,f'*({t} *){addr_e}'); fregs[ops[0]]=(v,t); fwritten.add(ops[0]); kinds.append('get')
                else:
                    t,ty=FST[mn]; r=ops[0]
                    if r in fregs: fv=fregs[r][0]; fv.used=True; v=fv.n
                    else:
                        if r not in('f1','f2','f3','f4'): raise Skip('freg')
                        fparams[r]=t; v=r
                    out.append(f'*({t} *){addr_e} = {v};'); kinds.append('set')
            elif mn=='li': regs[ops[0]]=str(int(ops[1],0)); written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='lis':
                if rk=='REFHI': regs[ops[0]]=('hi',sym); written.add(ops[0]); clobbered.discard(ops[0])
                else: regs[ops[0]]=f'({int(ops[1],0)<<16})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='mr': regs[ops[0]]=rd(ops[1]); written.add(ops[0]); clobbered.discard(ops[0])
            elif mn in('addi','subi'):
                if ops[1]=='r1' and mn=='addi' and rk is None:
                    loc=local_of(int(ops[2],0))
                    if loc is None: raise Skip('stack addr')
                    if loc[0] not in localnames: localnames.append(loc[0])
                    regs[ops[0]]=f'(ts4_word)&{loc[0]}[{loc[1]}]'; written.add(ops[0]); clobbered.discard(ops[0])
                elif rk=='REFLO':
                    s=regs[ops[1]][1]; externs[s]=1; regs[ops[0]]=f'(ts4_word){s}'; written.add(ops[0]); kinds.append('addr'); detail.append(s); clobbered.discard(ops[0])
                else:
                    v=int(ops[2],0)
                    if mn=='subi': v=-v
                    regs[ops[0]]=f'({rd(ops[1])} + {v})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='add': regs[ops[0]]=f'({rd(ops[1])} + {rd(ops[2])})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='subf': regs[ops[0]]=f'({rd(ops[2])} - {rd(ops[1])})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='ori': regs[ops[0]]=f'({rd(ops[1])} | {int(ops[2],0)})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='slwi': regs[ops[0]]=f'({rd(ops[1])} << {int(ops[2],0)})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='srwi': regs[ops[0]]=f'(({rd(ops[1])}) >> {int(ops[2],0)})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='clrlwi': regs[ops[0]]=f'({rd(ops[1])} & {hex((1<<(32-int(ops[2],0)))-1)})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='cntlzw': regs[ops[0]]=('clz',rd(ops[1])); written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='extrwi' and isinstance(regs.get(ops[1]),tuple) and regs[ops[1]][0]=='clz' and ops[2]=='1' and int(ops[3],0)==26:
                regs[ops[0]]=f'({regs[ops[1]][1]} == 0)'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='extsb': regs[ops[0]]=f'((signed char){rd(ops[1])})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='extsh': regs[ops[0]]=f'((short){rd(ops[1])})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='srawi': regs[ops[0]]=f'((int){rd(ops[1])} >> {int(ops[2],0)})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='mullw': regs[ops[0]]=f'((int){rd(ops[1])} * (int){rd(ops[2])})'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn in('lwzx','lbzx','lhzx'):
                t={'lwzx':'ts4_word','lbzx':'unsigned char','lhzx':'unsigned short'}[mn]
                regs[ops[0]]=newv(t,f'*({t} *)((char *)(ts4_word)({rd(ops[1])}) + {rd(ops[2])})'); written.add(ops[0]); clobbered.discard(ops[0]); kinds.append('get')
            elif mn in('subic','addic'): regs['__ca']=rd(ops[1]); regs[ops[0]]='__x'; written.add(ops[0])
            elif mn=='subfe':
                if '__ca' not in regs: raise Skip('subfe')
                regs[ops[0]]=f'({regs["__ca"]} != 0)'; written.add(ops[0]); clobbered.discard(ops[0])
            elif mn=='mtctr': st['ctr']=rd(ops[0]); st['ctr_reg']=ops[0]
            elif mn in('bl','bctrl'):
                counters['calls']+=1
                ctr_reg=st['ctr_reg'] if mn=='bctrl' else None
                wr=[int(r[1:]) for r in written if r[0]=='r' and 3<=int(r[1:])<=10 and r not in clobbered and r!=ctr_reg]
                k_w=max(wr)-2 if wr else 0
                if mn=='bl':
                    if rk!='REL24' or sym.startswith('__'): raise Skip('call '+str(sym))
                    ar=env.arity(sym)
                    if ar is None: raise Skip('noarity')
                else: ar=1
                n=ar
                if mode==1 or mn=='bctrl':
                    while f'r{3+n}' in written and f'r{3+n}'!=ctr_reg and 3+n<=10: n+=1
                    if mn=='bctrl': n=max(n,1)
                elif mode==2:  # highest argument register written since the last call
                    n=max([n]+[k-2 for k in wr])
                sa=st['stackargs']
                if sa:
                    if sorted(sa)!=list(range(len(sa))): raise Skip('stack args gap')
                    n=8
                args=[]
                for j in range(3,3+n):
                    try: args.append(rd(f'r{j}'))
                    except Skip: break
                if sa:
                    if len(args)!=8: raise Skip('stack args regs')
                    args+=[sa[k] for k in range(len(sa))]; st['stackargs']={}
                if any(isinstance(a,tuple) for a in args): raise Skip('hi arg')
                cav=', '.join(f'(ts4_word){a}' for a in args)
                if mn=='bl':
                    protos[sym]=len(args); call=f'{sym}({cav})'; detail.append(sym)
                else:
                    pt=', '.join(['ts4_word']*len(args)); call=f'((ts4_word (*)({pt}))({st["ctr"]}))({cav})'; detail.append('vcall'); kinds.append('vcall')
                v=newv('ts4_word',call)
                for r in list(regs):
                    if r[0]=='r' and r!='__ca' and 3<=int(r[1:])<=12: del regs[r]
                for j in range(4,13): clobbered.add(f'r{j}')
                for j in range(3,13): written.discard(f'r{j}')
                regs['r3']=v; written.add('r3'); clobbered.discard('r3'); st['ctr']=None
            elif mn=='blr': finish('ret',st,out); return
            elif mn=='bctr': finish(('ctr',st['ctr']),st,out); return
            elif mn=='b' and rk=='REL24': finish(('call',sym),st,out); return
            else: raise Skip(mn)
        raise Skip('noend')
    def run_noend(lines,st,out):
        try: run(lines,st,out)
        except Skip as e:
            if str(e)!='noend': raise
    def finish(tail,st,out):
        regs=st['regs']; written=st['written']; clobbered=st['clobbered']
        if st['stackargs']: raise Skip('stack args unused')
        def rd(r):
            if r in regs:
                v=regs[r]
                if isinstance(v,V): v.used=True; return v.n
                return v
            n=int(r[1:])
            if n<3 or n>10 or r in clobbered: raise Skip('read '+r)
            readp.add(n); return f'a{n-3}'
        if tail=='ret':
            if 'r3' in written and 'f1' not in st['fwritten']:
                rv=rd('r3')
                if isinstance(rv,tuple): raise Skip('ret hi')
                counters['rets'].append('ts4_word'); out.append(f'return {rv};')
            elif 'f1' in st['fwritten'] and 'r3' not in written:
                fv=st['fregs']['f1']; fv[0].used=True; counters['rets'].append(fv[1]); out.append(f'return {fv[0].n};')
            elif 'r3' not in written: counters['rets'].append('void'); out.append('return;')
            else: raise Skip('both ret')
        elif tail[0]=='call':
            cand=[int(r[1:]) for r in written if r[0]=='r' and r!='__ca' and 3<=int(r[1:])<=10 and r not in clobbered]
            k=max([3]+cand+list(readp)); callargs=[rd(f'r{j}') for j in range(3,k+1)]
            if any(isinstance(c,tuple) for c in callargs): raise Skip('ca hi')
            protos[tail[1]]=len(callargs); detail.append(tail[1]); kinds.append('tail')
            counters['rets'].append('ts4_word'); out.append(f'return {tail[1]}({", ".join("(ts4_word)"+c for c in callargs)});')
        else:
            k=max([3]+[r+2 for r in readp]); callargs=[rd(f'r{j}') for j in range(3,k+1)]
            pt=', '.join(['ts4_word']*len(callargs)); kinds.append('vcall')
            counters['rets'].append('ts4_word'); out.append(f'return ((ts4_word (*)({pt}))({tail[1]}))({", ".join("(ts4_word)"+c for c in callargs)});')
    top=[]
    st0=newst()
    run(lines_all,st0,top)
    rets=set(counters['rets'])
    if len(rets)!=1: raise Skip('mixed rets '+str(rets))
    rt=rets.pop()
    # drop phi variables that are only ever assigned (never read afterwards)
    def phi_uses(stmts,pn,acc):
        for x in stmts:
            if isinstance(x,V): acc[1]+=len(re.findall(r'\b'+pn+r'\b',x.e))
            elif isinstance(x,tuple):
                acc[1]+=len(re.findall(r'\b'+pn+r'\b',x[1]))
                for sub in x[2:]: phi_uses(sub,pn,acc)
            elif re.match(r'\s*'+pn+r' = ',x): acc[0]+=1; acc[1]+=len(re.findall(r'\b'+pn+r'\b',x[x.index('=')+1:]))
            else: acc[1]+=len(re.findall(r'\b'+pn+r'\b',x))
    def phi_strip(stmts,pn):
        stmts[:]=[x for x in stmts if not (isinstance(x,str) and re.match(r'\s*'+pn+r' = ',x))]
        for x in stmts:
            if isinstance(x,tuple):
                for sub in x[2:]: phi_strip(sub,pn)
    for pn in list(phis):
        acc=[0,0]; phi_uses(top,pn,acc)
        if acc[1]==0: phi_strip(top,pn); phis.remove(pn)
    # postprocess: inline + render
    def render(stmts,ind):
        o=[]; decls=[]
        # inline single-use loads (flat only)
        def txt(x): return x.e if isinstance(x,V) else (x if isinstance(x,str) else '\n'.join(render([x],0)[1]))
        j=0
        allt=lambda: ' '.join(txt(x) for x in stmts)
        while j<len(stmts)-1:
            x=stmts[j]
            if isinstance(x,V) and x.used and x.e.startswith('*('):
                nxt=stmts[j+1]
                if isinstance(nxt,(V,str)) and re.search(r'\b'+x.n+r'\b',txt(nxt)) and len(re.findall(r'\b'+x.n+r'\b',FULL()))==1:
                    t=re.sub(r'\b'+x.n+r'\b',lambda m:'('+x.e+')',txt(nxt))
                    if isinstance(nxt,V): nxt.e=t
                    else: stmts[j+1]=t
                    del stmts[j]; continue
            j+=1
        for x in stmts:
            if isinstance(x,V):
                if x.used: decls.append(f'{x.t} {x.n};'); o.append(' '*ind+f'{x.n} = {x.e};')
                else:
                    if not x.e.startswith('*('): o.append(' '*ind+x.e+';')
            elif isinstance(x,tuple):
                d2,b2=render(x[2],ind+4)
                decls+=d2
                o.append(' '*ind+f'if ({x[1]}) {{'); o+=b2
                if len(x)>3:
                    d3,b3=render(x[3],ind+4); decls+=d3
                    o.append(' '*ind+'} else {'); o+=b3
                o.append(' '*ind+'}')
            else: o.append(' '*ind+x)
        return decls,o
    def FULL():
        def flat(stmts):
            r=[]
            for x in stmts:
                if isinstance(x,V): r.append(x.e)
                elif isinstance(x,tuple): r.append(x[1]); r.append(flat(x[2])); r.append(flat(x[3]) if len(x)>3 else '')
                else: r.append(x)
            return ' '.join(r)
        return flat(top)
    decls,body_l=render(top,4)
    decls=[f'ts4_word {n};' for n in phis]+[f'ts4_word {n}[{local_ext[int(n[3:],16)]}];' for n in localnames]+decls
    body=''.join('    '+d+'\n' for d in decls)+('\n' if decls else '')+'\n'.join(body_l)+'\n'
    maxp=max(readp) if readp else 2
    params=[f'{ptype.get(f"r{j}","ts4_word")} a{j-3}' for j in range(3,maxp+1)]
    for f in sorted(fparams): params.append(f'{fparams[f]} {f}')
    kind=('if_' if '(' in ''.join(map(str,[x[0] for x in top if isinstance(x,tuple)])) or any(isinstance(x,tuple) for x in top) else '')
    ks=kinds
    if counters['calls'] and set(ks)<= {'get','set','addr'}: k0='call_seq'
    else: k0=ks[0] if ks else 'fn'
    if 'tail' in ks and len(ks)==1: k0='tailcall'
    kind+=k0
    sig=f'{rt} NAME({", ".join(params) if params else "void"})'
    return dict(kind=kind,detail=detail,sig=sig,body=body,externs=list(externs),protos=protos)
