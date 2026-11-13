#!/usr/bin/env python3
"""Usage: python3 tools/split_selfrefs.py 'work/specs/<FAMILY>/*.json' [--apply]

Move generated function definitions that are referenced from the same file into separate files.

Generator files: preamble, then blocks '/* Swing_DLL.xex 0xADDR: ... */\n<def>\n{...}\n'.
Prints a plan or applies it (--apply), writing new specs alongside the originals."""
import json, re, sys, glob, os
APPLY = '--apply' in sys.argv
BLOCK = re.compile(r'(/\* Swing_DLL\.xex 0x[0-9A-F]{8}[^\n]*\*/\n(?:[^\n{]*\n)?[^\n]*\n\{\n.*?\n\}\n\n*)', re.S)
total = 0
PATTERN = next((a for a in sys.argv[1:] if not a.startswith('--')), 'work/specs/K/fk_*.json')
for spec_path in sorted(glob.glob(PATTERN)):
    spec = json.load(open(spec_path)); src = spec['source']; text = open(src).read()
    first = text.index('/* Swing_DLL.xex 0x')
    pre, body = text[:first], text[first:]
    blocks = BLOCK.findall(body)
    assert ''.join(blocks) == body, (src, len(''.join(blocks)), len(body))
    def name_of(b):
        m = re.search(r'\n[^\n]*?\b(ts4_\w+)\(', b); return m.group(1)
    names = [name_of(b) for b in blocks]
    defined = set(spec['functions'])
    groups = [[]]  # group 0 stays in the original file
    placed = {}
    for b, n in zip(blocks, names):
        g = 0
        while True:
            if g >= len(groups): groups.append([])
            others = groups[g]
            clash = any(re.search(r'\b%s\b' % re.escape(on), b.split('\n', 1)[1].split('{', 1)[1]) or
                        re.search(r'\b%s\b' % re.escape(n), ob.split('{', 1)[1]) for ob, on in others)
            if not clash: break
            g += 1
        groups[g].append((b, n)); placed[n] = g
    moved = sum(len(x) for x in groups[1:]); total += moved
    if moved: print(src, 'groups', [len(x) for x in groups])
    if not APPLY or not moved: continue
    stem = src[:-2]
    for gi, members in enumerate(groups):
        out_src = src if gi == 0 else f'{stem}_{gi}.c'
        own = {n for _, n in members}
        lines = [l for l in pre.split('\n') if not any(re.match(r'^[^(]*\b%s\b\s*(\(\)|\[\])?\s*;' % re.escape(n), l.strip()) for n in own)]
        open(out_src, 'w').write('\n'.join(lines) + ''.join(b for b, _ in members))
        s = dict(spec); s['source'] = out_src
        s['functions'] = {n: a for n, a in spec['functions'].items() if n in own}
        json.dump(s, open(spec_path if gi == 0 else spec_path[:-5] + f'_{gi}.json', 'w'), indent=1)
print('moved', total)
