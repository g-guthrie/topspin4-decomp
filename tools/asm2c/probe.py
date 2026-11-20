"""Compile a C source with the real compiler and return each function's listing.

`compile_listings(text, flags)` -> {function name: [disassembly lines]} using the
same compiler invocation as tools/fn_check.py (base flags /O2 /Oi).  Used by the
frame-size check (`frame_of`) and for experiments:

    python3 tools/asm2c/probe.py file.c [--flags /O1] [name ...]
"""
import os, re, shutil, subprocess, sys, tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from fn_asm import disassemble          # noqa: E402
from xcoff import ROOT, read_coff       # noqa: E402

TOOLS = ROOT / 'work' / 'matching-tools'
WIBO = TOOLS / 'work_wibo'
CL = TOOLS / 'compilers' / 'X360' / '16.00.10224.00' / 'cl.exe'
BASE_FLAGS = ['/nologo', '/c', '/O2', '/Oi']


def compile_obj(text, flags=(), name='probe.c'):
    """Compile `text`; returns (coff object or None, compiler output)."""
    wd = Path(tempfile.mkdtemp(prefix='a2cprobe-', dir=ROOT / 'work'))
    try:
        (wd / name).write_text(text)
        inc = '/I' + os.path.relpath(ROOT / 'src' / 'xbox360', wd)
        env = dict(os.environ, TMP=str(wd), TEMP=str(wd))
        r = subprocess.run([str(WIBO), str(CL), *BASE_FLAGS, *flags, inc, name], cwd=wd, env=env,
                           capture_output=True, text=True)
        obj = wd / (Path(name).stem + '.obj')
        if r.returncode or not obj.is_file():
            return None, r.stdout + r.stderr
        return read_coff(obj), r.stdout + r.stderr
    finally:
        shutil.rmtree(wd, ignore_errors=True)


def compile_listings(text, flags=(), name='probe.c'):
    obj, msg = compile_obj(text, flags, name)
    if obj is None:
        return None, msg
    out = {}
    for fn in obj.function_names():
        code, rel = obj.function(fn)
        out[fn] = disassemble(code, 0, rel)
    return out, msg


FRAME_RE = re.compile(r'\bstwu\s+r1,\s*-(\w+)\(r1\)')


def frame_of(lines):
    """Frame size from the `stwu r1,-N(r1)` of a listing (0 when frameless)."""
    for ln in lines[:16]:
        m = FRAME_RE.search(ln)
        if m:
            return int(m.group(1), 0)
    return 0


def stack_offsets(lines):
    """Sorted set of r1-relative offsets accessed / addressed in a listing (body only)."""
    offs = set()
    for ln in lines:
        m = re.search(r'\b(?:l|st)\w*\s+\w+,\s*(-?\w+)\(r1\)', ln)
        if m and not re.search(r'\bst(wu|d)\b', ln):
            offs.add(int(m.group(1), 0))
        m = re.search(r'\baddi\s+r\d+,\s*r1,\s*(-?\w+)', ln)
        if m:
            offs.add(int(m.group(1), 0))
    return sorted(offs)


if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument('src', type=Path)
    ap.add_argument('names', nargs='*')
    ap.add_argument('--flags', nargs='*', default=[])
    a = ap.parse_args()
    res, msg = compile_listings(a.src.read_text(), a.flags, a.src.name)
    if res is None:
        print(msg); sys.exit(1)
    for fn, ls in res.items():
        if a.names and fn not in a.names:
            continue
        print(f'== {fn} frame {frame_of(ls):#x}')
        print('\n'.join(ls))
