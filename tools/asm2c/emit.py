"""Group translated functions into C files, verify with fn_check, retry.

`build()` renders a list of results into one .c file (externs, prototypes,
one function per result); `check()` runs tools/fn_check.py on it;
`run_group()` drops functions that fail to *compile* and retries.
"""
import re, subprocess, sys
from pathlib import Path
from source import ROOT

HDR = ['/* Small accessor / thunk / call-sequence functions produced by tools/asm2c',
       '   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,',
       '   MSVC 16.00.10224.00). The original address is in the comment above each',
       '   definition. Parameters are untyped words (a0 = this/first argument); field',
       '   accesses are by byte offset. */',
       '#ifdef _MSC_VER', 'typedef unsigned __int64 ts4_u64;', 'typedef __int64 ts4_s64;', '#else',
       'typedef unsigned long long ts4_u64;', 'typedef long long ts4_s64;', '#endif',
       'typedef unsigned long ts4_word;', '']


HOST_BUILTINS = {'memcpy', 'memset', 'memmove', 'memcmp', 'strlen', 'strcmp', 'strcpy', 'strncpy',
                 'strcat', 'strchr', 'strncmp', 'strstr', 'sprintf', 'printf', 'abs', 'malloc', 'free',
                 'calloc', 'realloc', 'sqrt', 'sqrtf', 'sin', 'cos', 'fabs', 'floor', 'ceil', 'pow', 'atan2'}


def func_name(r, addr):
    """ts4_<kind>_<detail>_<ADDR> from a translation result."""
    d = r['detail']
    det = re.sub(r'[^0-9A-Za-z_]', '_', d[0].replace('@0x', '_off')) if d else ''
    return f"ts4_{r['kind']}_{det}_{addr:08X}".replace('__', '_')


def strip_dead_locals(body):
    """Remove locals that are only ever assigned (host cc: -Wunused-but-set-variable).
    `x = call(...);` keeps the call as a statement; dead loads are deleted."""
    while True:
        changed = False
        for m in re.finditer(r'^    (?:ts4_word|float|double) ((?:[tp]f?)\d+);$', body, re.M):
            n = m.group(1)
            assigns = list(re.finditer(r'^( +)' + n + r' = (.*);$', body, re.M))
            if len(re.findall(r'\b' + n + r'\b', body)) != 1 + len(assigns):
                continue
            body = re.sub(r'^    (?:ts4_word|float|double) ' + n + r';\n', '', body, flags=re.M)
            def sub(a):
                rhs = a.group(2)
                return '' if rhs.startswith('*(') or not re.search(r'\w\(|\(\*\)\(', rhs) else f'{a.group(1)}{rhs};'
            body = re.sub(r'^( +)' + n + r' = (.*);$\n?', lambda a: (sub(a) + '\n') if sub(a) else '', body, flags=re.M)
            changed = True
            break
        if not changed:
            return re.sub(r'\n\n\n+', '\n\n', body)


def vt_class(name, slot):
    """C++ class whose virtual function number `slot` is `s<slot>` (earlier slots are dummies)."""
    o = [f'struct {name} {{']
    o += [f'    virtual void d{i}();' for i in range(slot)]
    o += [f'    virtual ts4_word s{slot}();', '};']
    return o


def mangle_num(n):
    """MSVC number encoding used in `$B` (vcall thunk) names: 1..10 -> digit, else hex nibbles + '@'."""
    if n == 0:
        return 'A@'
    if n <= 10:
        return str(n - 1)
    h = ''
    while n:
        h = chr(ord('A') + (n & 15)) + h
        n >>= 4
    return h + '@'


def vthunk_name(a, off):
    """(class name, symbol of the compiler-generated vcall thunk) for a function at `a`."""
    cls = f'ts4_vcall_slot{off // 4}_{a:08X}'
    return cls, f'??_9{cls}@@$B{mangle_num(off)}AA'


_A2N = None


def _symbol_names():
    global _A2N
    if _A2N is None:
        import source
        _A2N = source.symbol_at()
    return _A2N


def cast_same_file_calls(body, protos, own_names, cpp=False):
    """Calls to a function that is defined in the same file go through an unprototyped
    function-pointer cast.  The call site names the callee's old placeholder (fn_XXXXXXXX);
    once that placeholder is renamed to the name the definition has, a plain call would be
    checked against the definition's prototype (too few arguments)."""
    for p in sorted(own_names & set(protos), key=len, reverse=True):
        pt = ', '.join(['ts4_word'] * protos[p]) if cpp else ''
        body = re.sub(r'(?<![\w.>])' + re.escape(p) + r'\(', f'((ts4_word (*)({pt})){p})(', body)
    return body


def build(res, group, path, cpp=False):
    """Write `group` (addresses into dict `res`) to `path`.
    Returns ([(name, addr)], {addr: (first_line, last_line)}). """
    # Callees are declared unprototyped (`ts4_word f();`) so that call sites with
    # different argument counts never conflict; every argument is a ts4_word.
    protos, kept = {}, list(group)
    for a in group:
        protos.update(res[a]['protos'])
    ext = {e for a in kept for e in res[a]['externs']}
    o = list(HDR)
    for nw in sorted({n for a in kept for n in res[a].get('structs', [])}):
        # a struct parameter passed by value (registers spilled to their home slots)
        o.insert(len(o) - 1, f'typedef struct ts4_args{nw} {{ ts4_word w[{nw}]; }} ts4_args{nw};')
    if any(res[a].get('vec') for a in kept):
        o.insert(len(o) - 1, '#include "ts4_vector.h"')
    ints = {{'xchg': '_InterlockedExchange', 'inc': '_InterlockedIncrement', 'dec': '_InterlockedDecrement',
             'addi': '_InterlockedExchangeAdd', 'add': '_InterlockedExchangeAdd'}[k] for a in kept for k in res[a].get('intrinsics', [])}
    for n in sorted(ints):
        o.insert(len(o) - 1, f'extern long {n}(volatile long *value' + (', long v);' if n in ('_InterlockedExchange', '_InterlockedExchangeAdd') else ');'))
    if ints:
        o.insert(len(o) - 1, '#ifdef _MSC_VER'); o.insert(len(o) - 1, f'#pragma intrinsic({", ".join(sorted(ints))})'); o.insert(len(o) - 1, '#endif')
    if cpp:  # one class per vcall thunk; everything else is extern "C"
        vth = {}
        for a in kept:
            if 'vthunk' in res[a]:
                cls, sym = vthunk_name(a, res[a]['vthunk'])
                start = len('\n'.join(o).split('\n')) + 1
                # taking the address of a virtual member makes the compiler emit its vcall thunk
                o.append(f'/* Swing_DLL.xex 0x{a:08X}: vcall thunk, virtual slot {res[a]["vthunk"] // 4} (symbol {sym}) */')
                o += vt_class(cls, res[a]['vthunk'] // 4)
                o.append(f'ts4_word ({cls}::*ts4_pm_{a:08X})() = &{cls}::s{res[a]["vthunk"] // 4};')
                vth[a] = (sym, start, len(o))
        o.append('extern "C" {')
    rtypes, fprotos = {}, {}
    for a in kept:
        rtypes.update(res[a].get('rtypes', {}))
        fprotos.update(res[a].get('fprotos', {}))
    for e in sorted(ext):
        if e not in protos:
            o.append(f'extern char {e}[];')
    # a name used both as data address and as callee is declared as a function
    for p, n in sorted(protos.items()):
        if p in HOST_BUILTINS and not cpp:  # keep gcc/clang from rejecting the prototype
            o += [f'#ifndef _MSC_VER', f'#define {p} ts4_host_{p}', '#endif']
        rt = rtypes.get(p, 'ts4_word')
        if p in fprotos:     # float arguments: full prototype
            o.append(f'{rt} {p}({", ".join(fprotos[p])});')
        else:
            o.append(f'{rt} {p}({", ".join(["ts4_word"] * n)});' if cpp else f'{rt} {p}();')
    o.append('')
    maps, rng = [], {}
    a2n = _symbol_names()
    own_names = {a2n[a] for a in kept if a in a2n}
    for a in kept:
        r = res[a]
        if 'vthunk' in r:
            maps.append((vth[a][0], a)); rng[a] = vth[a][1:]
            continue
        nm = func_name(r, a)
        o.append(f'/* Swing_DLL.xex 0x{a:08X}: {r["kind"]} {", ".join(r["detail"][:6])} */')
        start = len('\n'.join(o).split('\n')) + 1   # first line of the definition (entries hold several lines)
        body = strip_dead_locals(r['body'])
        body = cast_same_file_calls(body, protos, own_names, cpp)
        unused = [p for p in re.findall(r'\ba\d+\b', r['sig']) if not re.search(r'\b' + p + r'\b', body)]
        if unused:
            bl = body.split('\n'); k = 0
            while k < len(bl) and (bl[k].strip() == '' or re.match(r'^    [A-Za-z0-9_ ]+ \w+(\[\d+\])?;$', bl[k])):
                k += 1
            bl[k:k] = [f'    (void){p};' for p in unused]
            body = '\n'.join(bl)
        o.append(r['sig'].replace('NAME', nm) + '\n{\n' + body + '}\n')
        rng[a] = (start, len('\n'.join(o).split('\n')))
        maps.append((nm, a))
    if cpp:
        o.append('}')
    Path(path).write_text('\n'.join(o))
    return maps, rng


def check(path, maps, flags=()):
    """Run tools/fn_check.py; `flags` are extra compiler flags such as ('/O1',)."""
    args = [f'{n}=0x{a:08X}' for n, a in maps]
    if flags:
        args += ['--flags', *flags]
    p = subprocess.run([sys.executable, str(ROOT / 'tools' / 'fn_check.py'), str(path), *args],
                       capture_output=True, text=True, cwd=ROOT)
    return p.stdout + p.stderr


def cc_ok(path):
    """Host syntax check required by AGENTS/brief (C++ files: c++ -fsyntax-only). C files are
    also checked with clang when it is installed, both with -Wno-deprecated-non-prototype."""
    import shutil
    if str(path).endswith('.cpp'):
        cmds = [['c++', '-std=c++11', '-fsyntax-only']]
    else:
        base = ['-std=c11', '-Wall', '-Wextra', '-Werror', '-Wno-deprecated-non-prototype', '-fsyntax-only']
        cmds = [['cc'] + base] + ([['clang'] + base] if shutil.which('clang') else [])
    for cmd in cmds:
        p = subprocess.run(cmd + [str(path)], capture_output=True, text=True)
        if p.returncode != 0:
            return False, p.stderr
    return True, ''


def run_group(res, group, path, tries=8, flags=(), cpp=False):
    """build + check; on compiler errors drop the offending functions and retry.
    Returns (fn_check output, maps)."""
    group = list(group)
    out, maps = '', []
    for _ in range(tries):
        maps, rng = build(res, group, path, cpp)
        out = check(path, maps, flags)
        if 'compile failed' not in out:
            return out, maps
        lines = [int(x) for x in re.findall(r'\((\d+)\) : error', out)]
        bad = {a for a, (s, e) in rng.items() if any(s <= l <= e for l in lines)}
        if not bad:
            return out, maps
        group = [a for a in group if a not in bad]
    return out, maps


def parse_check(out):
    """-> (matched names, failed names, {old: new} renames)"""
    ok = [l.split()[1] for l in out.splitlines() if l.startswith('MATCH')]
    bad = [l.split()[1].rstrip(':') for l in out.splitlines() if l.startswith('FAIL')]
    ren = {m.group(1): m.group(2) for l in out.splitlines() if (m := re.match(r'RENAME (\S+) -> (\S+)', l))}
    return ok, bad, ren
