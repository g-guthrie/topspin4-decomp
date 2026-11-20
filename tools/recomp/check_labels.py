#!/usr/bin/env python3
"""Report gotos to labels that are not defined in the same generated function.

    python3 tools/recomp/check_labels.py GENERATED_DIR...

Works on ReXGlue (DEFINE_REX_FUNC) and XenonRecomp (PPC_FUNC_IMPL) output. Prints
"file func target" per bad goto and a count; exit status 1 when any are found.
"""
import re
import sys
from pathlib import Path

FUNC = re.compile(r'^(?:DEFINE_REX_FUNC|PPC_FUNC_IMPL)\((?:__imp__)?(\w+)\)')
LABEL = re.compile(r'^(loc_[0-9A-F]{8}):')
GOTO = re.compile(r'goto (loc_[0-9A-F]{8});')


def check(path):
    bad = []
    func, labels, gotos = None, set(), []

    def flush():
        for g in gotos:
            if g not in labels:
                bad.append((path.name, func, g))

    for line in path.read_text(errors='replace').splitlines():
        m = FUNC.match(line)
        if m:
            flush()
            func, labels, gotos = m.group(1), set(), []
            continue
        m = LABEL.match(line)
        if m:
            labels.add(m.group(1))
        gotos.extend(GOTO.findall(line))
    flush()
    return bad


def main(argv):
    bad = []
    for d in argv[1:]:
        for p in sorted(Path(d).glob('*.cpp')):
            bad += check(p)
    for b in bad:
        print(*b)
    print('undeclared gotos:', len(bad))
    return 1 if bad else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
