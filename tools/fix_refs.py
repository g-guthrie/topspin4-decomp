#!/usr/bin/env python3
"""Rewrite placeholder references (fn_/lbl_) in candidate sources to current names.

Usage: python3 tools/fix_refs.py work/specs/<FAMILY>/*.json

Run before tools/integrate_match.py. It renames references to functions the
given specs rename, plus every placeholder renamed since the baseline commit
553f783. Same-file callees that become visible definitions can be inlined by
the compiler; see docs/START_HERE.md (pitfalls) and tools/split_selfrefs.py.

A new name that is a decorated C++ name (`?SetString@Ts4WStr@@QAAXPBGH@Z`) cannot be
written where the old placeholder stood (`fn_8819C360(...)` in a C source, or under
extern "C"). Such a reference gets the function's "cxx" alias instead, from the specs'
"aliases" or config/54540859/icf_aliases.json (tools/icf_alias.py): the checkers and the
build treat the alias as the decorated symbol. Without an alias the script stops.
"""
import json,re,sys
sys.path.insert(0,'tools')
from xcoff import load_symbols
specs=[json.load(open(p)) for p in sys.argv[1:]]
import icf_alias
c_alias={e.canonical:e.alias for e in icf_alias.load() if e.kind=='cxx'}
for sp in specs:
    for alias,item in sp.get('aliases',{}).items():
        if item.get('kind')=='cxx': c_alias[item['canonical']]=alias
def spell(old,new):
    """The text that replaces `old`: `new`, or its C alias when `new` is a decorated name."""
    if icf_alias.C_IDENTIFIER.match(new): return new
    if new in c_alias: return c_alias[new]
    if old not in spec_driven:
        print(f'kept {old}: its name is now {new}, which has no "cxx" alias'); return old
    raise SystemExit(f'{old} -> {new}: a decorated name needs a "cxx" alias (spec "aliases" or icf_aliases.json)')
spec_driven=set()
by_addr={a:n for n,s,a,z in load_symbols() if s=='.text'}
ren={}
for sp in specs:
    for new,addr in sp['functions'].items():
        old=by_addr[int(addr,16)]
        if old!=new: ren[old]=new
    ren.update(sp.get('renames',{}))
spec_driven.update(ren)
import subprocess
old=subprocess.run(['git','show','553f783:config/54540859/symbols.txt'],capture_output=True,text=True).stdout
cur={a:n for n,s,a,z in load_symbols()}
for line in old.splitlines():
    m=re.match(r'^(fn_[0-9A-F]+|lbl_[0-9A-F]+) = \S+:0x([0-9A-Fa-f]+);',line)
    if m:
        a=int(m.group(2),16)
        if cur.get(a,m.group(1))!=m.group(1): ren.setdefault(m.group(1),cur[a])
pat=re.compile(r'\b('+'|'.join(map(re.escape,ren))+r')\b')
for sp in specs:
    src=open(sp['source']).read()
    hits=set(pat.findall(src))
    if hits:
        # Build the new text before opening for write: spell() can raise SystemExit,
        # and open(..., 'w') would already have truncated the source (b227 lost
        # q5s_glue_obj_ctor.cpp this way).
        new_src=pat.sub(lambda m:spell(m.group(1),ren[m.group(1)]),src)
        open(sp['source'],'w').write(new_src)
        print(sp['source'],sorted(hits)[:8],len(hits))

# Existing sources that call a function these specs rename must follow the
# rename too: the LTCG route compares callee names, not addresses (b207 broke on
# cx41_l1.c calling fn_888FBB40 after it became ts4_school_play_power_up_888FBB40).
# Old names come from the committed symbols.txt, so this also works after
# integrate_match.py has already renamed the symbols.
head=subprocess.run(['git','show','HEAD:config/54540859/symbols.txt'],capture_output=True,text=True).stdout
head_by={}
for line in head.splitlines():
    m=re.match(r'^(\S+) = \.text:0x([0-9A-Fa-f]+);',line)
    if m: head_by[int(m.group(2),16)]=m.group(1)
spec_ren={}
for sp in specs:
    for new,addr in sp['functions'].items():
        old=head_by.get(int(addr,16),new)
        if old!=new: spec_ren[old]=new
spec_driven.update(spec_ren)
if spec_ren:
    import pathlib
    p2=re.compile(r'\b('+'|'.join(map(re.escape,spec_ren))+r')\b')
    own={sp['source'] for sp in specs}
    for f in sorted(pathlib.Path('src/xbox360').glob('*.c*')):
        if str(f) in own: continue
        t=f.read_text()
        if p2.search(t):
            new_t=p2.sub(lambda m:spell(m.group(1),spec_ren[m.group(1)]),t)
            f.write_text(new_t)
            print('updated caller',f)
