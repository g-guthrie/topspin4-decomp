#!/usr/bin/env python3
"""Rewrite placeholder references (fn_/lbl_) in candidate sources to current names.

Usage: python3 tools/fix_refs.py work/specs/<FAMILY>/*.json

Run before tools/integrate_match.py. It renames references to functions the
given specs rename, plus every placeholder renamed since the baseline commit
553f783. Same-file callees that become visible definitions can be inlined by
the compiler; see docs/START_HERE.md (pitfalls) and tools/split_selfrefs.py.
"""
import json,re,sys
sys.path.insert(0,'tools')
from xcoff import load_symbols
specs=[json.load(open(p)) for p in sys.argv[1:]]
by_addr={a:n for n,s,a,z in load_symbols() if s=='.text'}
ren={}
for sp in specs:
    for new,addr in sp['functions'].items():
        old=by_addr[int(addr,16)]
        if old!=new: ren[old]=new
    ren.update(sp.get('renames',{}))
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
        open(sp['source'],'w').write(pat.sub(lambda m:ren[m.group(1)],src))
        print(sp['source'],sorted(hits)[:8],len(hits))
