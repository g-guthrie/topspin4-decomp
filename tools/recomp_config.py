#!/usr/bin/env python3
"""Static-recompilation helpers for the Xbox 360 modules (XenonRecomp input and boundary survey).

Subcommands:

  config    write a XenonRecomp TOML (function boundaries from our symbols file, save/restore
            helper addresses found by byte pattern, optional setjmp/longjmp) plus a switch-table
            TOML built from our own jump-table detector, and a JSON report that classifies
            every `bctr` and counts `bctrl` sites;
  boundary  call graph of direct `bl`/`b` edges from functions in one set of address ranges
            (default: game code) into another set (middleware buckets), listing the distinct
            callee entry points per bucket; this is the replacement boundary for Havok, FMOD
            and the XDK graphics/audio layer;
  imports   import thunks (XEX import records, 4-word thunks) and who calls them.

MSVC 16 (XDK 2.0.20209) emits three switch shapes; XenonAnalyse (2025) matches none of them because
its patterns are fixed contiguous sequences, so this detector follows register definitions instead:

  absolute   lis r12,T@ha; slwi r0,rI,2; addi r12,r12,T@l; lwzx r0,r12,r0; mtctr r0; bctr
             (T = the word table placed in .text right after the bctr)
  byte/half  lis r12,T@ha; addi r12,r12,T@l; lbzx|lhzx r0,r12,rI[*2]; [slwi r0,r0,2];
             lis r12,B@ha; addi r12,r12,B@l; add r12,r12,r0; mtctr r12; bctr
             (T in .rdata holds offsets from base B)

The case count comes from the dominating `cmplwi crN,rI,K` (count K+1); if none is found the
absolute table is read until a word is not an address inside the function.

Standard library only. Inputs are the decompressed PE (the `.dll` made from the XEX) and a
`symbols.txt` in our split format. Nothing from the game is written except addresses.

  python3 tools/recomp_config.py config --image orig/54540859/Swing_DLL.dll \
      --symbols config/54540859/symbols.txt --xex ../../orig/54540859/Swing_DLL.xex \
      --name Swing --out-dir work/recomp/swing
  python3 tools/recomp_config.py boundary --image orig/54540859/Swing_DLL.dll \
      --symbols config/54540859/symbols.txt [--json out.json]
"""
import argparse, bisect, collections, json, re, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

BCTR = 0x4E800420
BCTRL = 0x4E800421
NOP = 0x60000000

# XenonRecomp README byte patterns for the register save/restore helpers (first words).
HELPER_PATTERNS = {
    'restgprlr_14_address': [0xE9C1FF68],
    'savegprlr_14_address': [0xF9C1FF68],
    'restfpr_14_address': [0xC9CCFF70],
    'savefpr_14_address': [0xD9CCFF70],
    'restvmx_14_address': [0x3960FEE0, 0x7DCB60CE],
    'savevmx_14_address': [0x3960FEE0, 0x7DCB61CE],
    'restvmx_64_address': [0x3960FC00, 0x100B60CB],
    'savevmx_64_address': [0x3960FC00, 0x100B61CB],
}

# Byte length of each helper block (all entry points), as XenonRecomp lays them out.
HELPER_SIZES = {
    'restgprlr_14_address': 18 * 4 + 12, 'savegprlr_14_address': 18 * 4 + 8,
    'restfpr_14_address': 18 * 4 + 4, 'savefpr_14_address': 18 * 4 + 4,
    'restvmx_14_address': 18 * 8 + 4, 'savevmx_14_address': 18 * 8 + 4,
    'restvmx_64_address': 64 * 8 + 4, 'savevmx_64_address': 64 * 8 + 4,
}


# --------------------------------------------------------------------------- image + symbols

class Image:
    """A PE image as produced by decompressing a XEX (raw offsets may differ from RVAs)."""

    def __init__(self, data):
        self.data = data
        e = struct.unpack_from('<I', data, 0x3C)[0]
        if data[e:e + 4] != b'PE\0\0':
            raise ValueError('not a PE image')
        nsec = struct.unpack_from('<H', data, e + 6)[0]
        opt = struct.unpack_from('<H', data, e + 20)[0]
        self.base = struct.unpack_from('<I', data, e + 24 + 28)[0]
        self.sections = []  # (name, va, vsize, raw_off, raw_size, characteristics)
        off = e + 24 + opt
        for _ in range(nsec):
            name = data[off:off + 8].rstrip(b'\0').decode('latin-1')
            vs, va, rs, ra = struct.unpack_from('<IIII', data, off + 8)
            ch = struct.unpack_from('<I', data, off + 36)[0]
            self.sections.append((name, self.base + va, vs, ra, rs, ch))
            off += 40
        # A memory image (the XEX basefile as mapped, e.g. a 0x180000-byte default.dll) keeps the
        # file-layout headers but holds each section at its RVA: read it at the RVA instead.
        raw_end = max(ra + rs for _, _, _, ra, rs, _ in self.sections)
        rva_end = max(va - self.base + vs for _, va, vs, _, _, _ in self.sections)
        if len(data) > raw_end and len(data) >= rva_end:
            self.sections = [(n, va, vs, va - self.base, max(vs, rs), ch)
                             for n, va, vs, ra, rs, ch in self.sections]

    @classmethod
    def from_sections(cls, sections):
        """Synthetic image for tests: sections = [(name, va, bytes, is_code)]."""
        self = cls.__new__(cls)
        self.base = min(s[1] for s in sections)
        blob = b''
        self.sections = []
        for name, va, data, code in sections:
            self.sections.append((name, va, len(data), len(blob), len(data), 0x20 if code else 0x40))
            blob += data
        self.data = blob
        return self

    def code_sections(self):
        return [s for s in self.sections if s[5] & 0x20]

    def read(self, addr, n=4):
        for name, va, vs, ra, rs, ch in self.sections:
            if va <= addr and addr + n <= va + vs:
                o = addr - va
                chunk = self.data[ra + o:ra + min(o + n, rs)] if o < rs else b''
                return chunk + b'\0' * (n - len(chunk))
        return None

    def word(self, addr):
        b = self.read(addr, 4)
        return None if b is None else struct.unpack('>I', b)[0]

    def section_of(self, addr):
        for s in self.sections:
            if s[1] <= addr < s[1] + s[2]:
                return s
        return None


SYM_RE = re.compile(r'^(\S+) = ([^:]+):0x([0-9A-Fa-f]+); // type:(\w+)(?: size:0x([0-9A-Fa-f]+))?')


def load_symbols(path):
    """Returns (functions {addr: (name, size, section)}, objects {addr: (name, size, section)}).
    Duplicate starts keep the largest size."""
    fns, objs = {}, {}
    for line in Path(path).read_text().splitlines():
        m = SYM_RE.match(line)
        if not m:
            continue
        name, sec, addr, kind, size = m.group(1), m.group(2), int(m.group(3), 16), m.group(4), m.group(5)
        size = int(size, 16) if size else 0
        table = fns if kind == 'function' else objs if kind == 'object' else None
        if table is None:
            continue
        if addr not in table or table[addr][1] < size:
            table[addr] = (name, size, sec)
    return fns, objs


# --------------------------------------------------------------------------- tiny PPC decoder

def s16(x):
    return x - 0x10000 if x & 0x8000 else x


def decode(w):
    """Decode the handful of forms the detector needs. Returns a tuple or None."""
    op = w >> 26
    rd, ra, rb = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op == 15:
        return ('addis', rd, ra, s16(w & 0xFFFF))
    if op == 14:
        return ('addi', rd, ra, s16(w & 0xFFFF))
    if op == 21:
        sh, mb, me = rb, (w >> 6) & 31, (w >> 1) & 31
        return ('rlwinm', ra, rd, sh, mb, me)  # dest rA, source rS
    if op == 10:
        return ('cmplwi', (w >> 23) & 7, ra, w & 0xFFFF, (w >> 21) & 1)
    if op == 16:
        return ('bc', (w >> 21) & 31, (w >> 16) & 31, s16(w & 0xFFFC))
    if op == 31:
        xo = (w >> 1) & 0x3FF
        if xo == 23:
            return ('lwzx', rd, ra, rb)
        if xo == 87:
            return ('lbzx', rd, ra, rb)
        if xo == 279:
            return ('lhzx', rd, ra, rb)
        if xo == 266:
            return ('add', rd, ra, rb)
        if xo == 467 and (((w >> 16) & 31) | (((w >> 11) & 31) << 5)) == 9:
            return ('mtctr', rd)
    return None


# GPR destinations, conservative: used only to check that a register is not redefined inside the
# short window between a switch's compare and its bctr.
_D_FORM_RD = {7, 8, 12, 13, 14, 15, 32, 33, 34, 35, 40, 41, 42, 43, 46, 58}
_D_FORM_RA = {20, 21, 23, 24, 25, 26, 27, 28, 29, 30}
_UPDATE_RA = {33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55}
_X31_NONE = {4, 6, 38, 54, 86, 103, 135, 144, 149, 150, 151, 167, 181, 183, 199, 214, 215, 231, 246, 247,
             278, 407, 439, 467, 487, 519, 535, 551, 567, 583, 599, 631, 647, 662, 663, 679, 695, 711,
             727, 759, 775, 854, 918, 983, 1014, 598}
_X31_RA = {0, 24, 26, 28, 60, 124, 284, 316, 412, 444, 476, 536, 539, 792, 794, 824, 826, 922, 954, 986}


def gpr_writes(w):
    if w is None or w == NOP:
        return set()
    op = w >> 26
    rd, ra = (w >> 21) & 31, (w >> 16) & 31
    out = set()
    if op in _D_FORM_RD:
        out.add(rd)
    if op in _D_FORM_RA:
        out.add(ra)
    if op in _UPDATE_RA and ra:
        out.add(ra)
    if op == 31:
        xo = (w >> 1) & 0x3FF
        if xo in (0, 32):  # cmp/cmpl
            return out
        if xo in _X31_RA or (w >> 1) & 0x1FF in (413,):  # sradi
            out.add(ra)
        elif xo in _X31_NONE:
            pass  # stores, cache ops, FP/VMX indexed loads, mtspr/mtcrf, traps, sync
        else:
            out.add(rd)
    return out


# --------------------------------------------------------------------------- switch detector

class Switch:
    __slots__ = ('bctr', 'kind', 'index_reg', 'labels', 'table', 'count_src')

    def __init__(self, bctr, kind, index_reg, labels, table, count_src):
        self.bctr, self.kind, self.index_reg = bctr, kind, index_reg
        self.labels, self.table, self.count_src = labels, table, count_src


def _const_of(img, start, at, reg):
    """Value of `reg` built by lis/addi between `start` and `at` (exclusive), else None."""
    lo = None
    a = at - 4
    while a >= start and at - a <= 64:
        d = decode(img.word(a))
        if d and d[0] == 'addi' and d[1] == reg and d[2] == reg and lo is None:
            lo = d[3]
        elif d and d[0] == 'addis' and d[1] == reg and d[2] == 0:
            return ((d[3] << 16) + (lo or 0)) & 0xFFFFFFFF
        elif reg in gpr_writes(img.word(a)) and not (d and d[0] == 'addi' and d[1] == reg):
            return None
        a -= 4
    return None


def _find_def(img, start, at, reg, limit=64):
    """Nearest instruction before `at` that writes `reg`: (addr, decoded or None)."""
    a = at - 4
    while a >= start and at - a <= limit:
        w = img.word(a)
        if reg in gpr_writes(w):
            return a, decode(w)
        a -= 4
    return None, None


def _bound(img, start, use_at, reg):
    """Case count from `cmplwi crN,reg,K` before `use_at` with reg unchanged in between.
    A compare on `src` also counts when `mr reg,src` precedes it and src is not rewritten."""
    seen = {}  # register -> count of the nearest compare on it, while it is still unmodified
    dead = set()
    a = use_at - 4
    while a >= start and use_at - a <= 160:
        w = img.word(a)
        d = decode(w)
        if d and d[0] == 'cmplwi' and d[4] == 0:
            if d[2] == reg:
                return d[3] + 1
            if d[2] not in dead:
                seen.setdefault(d[2], d[3] + 1)
        writes = gpr_writes(w)
        if reg in writes:
            if w >> 26 == 31 and (w >> 1) & 0x3FF == 444 and (w >> 21) & 31 == (w >> 11) & 31:
                src = (w >> 21) & 31
                if src in seen:
                    return seen[src]
                reg = src
            else:
                return None
        for r in writes:
            if r != reg:
                dead.add(r)
                seen.pop(r, None)
        a -= 4
    return None


def detect_switch(img, fn_start, fn_end, bctr):
    """Returns (Switch or None, reason)."""
    a_mt, d_mt = None, None
    a = bctr - 4
    while a >= fn_start and bctr - a <= 16:
        d = decode(img.word(a))
        if d and d[0] == 'mtctr':
            a_mt, d_mt = a, d
            break
        a -= 4
    if d_mt is None:
        return None, 'no mtctr'
    target = d_mt[1]
    a_def, d = _find_def(img, fn_start, a_mt, target)
    if d is None:
        return None, 'target not computed'
    if d[0] == 'lwzx':
        _, _, rbase, rscaled = d
        tbl = _const_of(img, fn_start, a_def, rbase)
        a_s, ds = _find_def(img, fn_start, a_def, rscaled)
        if tbl is None or ds is None or ds[0] != 'rlwinm' or ds[3:] != (2, 0, 29):
            return None, 'lwzx not a table load'
        index = ds[2]
        kind = 'absolute'
        width, shift = 4, None
    elif d[0] == 'add':
        _, _, ra, rb = d
        base = None
        for breg, oreg in ((ra, rb), (rb, ra)):
            c = _const_of(img, fn_start, a_def, breg)
            if c is not None:
                base, off_reg = c, oreg
                break
        if base is None:
            return None, 'add without constant base'
        a_o, do = _find_def(img, fn_start, a_def, off_reg)
        shift = 0
        if do and do[0] == 'rlwinm' and do[4] == 0 and do[5] == 31 - do[3] and do[2] == off_reg:
            shift = do[3]
            a_o, do = _find_def(img, fn_start, a_o, off_reg)
        if not do or do[0] not in ('lbzx', 'lhzx'):
            return None, 'offset not a table load'
        _, _, rt, ri = do
        tbl = _const_of(img, fn_start, a_o, rt)
        if tbl is None:
            return None, 'offset table not constant'
        width = 1 if do[0] == 'lbzx' else 2
        if width == 2:
            a_s, ds = _find_def(img, fn_start, a_o, ri)
            if ds is None or ds[0] != 'rlwinm' or ds[3:] != (1, 0, 30):
                return None, 'halfword index not scaled'
            index = ds[2]
        else:
            index, a_s = ri, a_o
        kind = 'byte' if width == 1 else 'half'
    else:
        return None, 'target from %s' % d[0]

    # the index register must survive to the bctr (XenonRecomp switches on it there)
    a = a_s + 4
    while a < bctr:
        if index in gpr_writes(img.word(a)):
            return None, 'index clobbered before bctr'
        a += 4
    count = _bound(img, fn_start, a_s, index)
    src = 'cmplwi'
    if count is None:
        # index masked by clrlwi rI,rS,n (rlwinm sh=0, me=31): 2**(32-n) entries
        a_i, di = _find_def(img, fn_start, a_s, index)
        if di and di[0] == 'rlwinm' and di[3] == 0 and di[5] == 31 and di[4] >= 24:
            count, src = 1 << (32 - di[4]), 'mask'
    labels = []
    if kind == 'absolute':
        n = count if count is not None else 4096
        for i in range(n):
            w = img.word(tbl + 4 * i)
            if w is None or not (fn_start <= w < fn_end) or w & 3:
                if count is not None:
                    return None, 'absolute entry outside function'
                break
            labels.append(w)
        if count is None:
            src = 'scan'
    else:
        if count is None:
            return None, 'no bound for offset table'
        for i in range(count):
            raw = img.read(tbl + width * i, width)
            if raw is None:
                return None, 'offset table unreadable'
            off = raw[0] if width == 1 else struct.unpack('>H', raw)[0]
            lab = (base + (off << shift)) & 0xFFFFFFFF
            if not (fn_start <= lab < fn_end):
                # A table bounded only by an index mask can be shared with another switch (Loader
                # 0x830CF6F0 shares .rdata 0x830847F8 with 0x830CF868's); entries that point past
                # the function are kept and become jumps into the neighbour (XenonRecomp RC2 turns
                # them into alternate entries).
                sec = img.section_of(lab)
                if src != 'mask' or sec is None or not (sec[5] & 0x20):
                    return None, 'offset label outside function'
                if img.word(lab) == 0:
                    lab = 0  # lands on padding: an index this switch never takes; XenonRecomp traps
            labels.append(lab)
    if not labels:
        return None, 'empty table'
    return Switch(bctr, kind, index, labels, tbl, src), 'ok'


def classify_bctr(img, fn_start, bctr):
    """Coarse label for a non-switch bctr."""
    w1, w2 = img.word(bctr - 4), img.word(bctr - 8)
    if w2 is not None and (w2 >> 24) in (0x01, 0x02) and w1 == 0x7D6903A6:
        return 'import thunk'
    a = bctr - 4
    while a >= fn_start and bctr - a <= 16:
        d = decode(img.word(a))
        if d and d[0] == 'mtctr':
            w = img.word(a - 4)
            if w is not None and w >> 26 == 32 and ((w >> 21) & 31) == d[1]:
                return 'indirect jump via loaded pointer (vcall/tail call)'
            return 'indirect jump via register'
        a -= 4
    return 'other'


def find_helpers(img):
    found = {}
    for name, va, vs, ra, rs, ch in img.code_sections():
        blob = img.data[ra:ra + min(vs, rs)]
        for key, pat in HELPER_PATTERNS.items():
            needle = b''.join(struct.pack('>I', x) for x in pat)
            i = blob.find(needle)
            while i >= 0 and i % 4:
                i = blob.find(needle, i + 1)
            if i >= 0 and key not in found:
                found[key] = va + i
    return found


def scan_functions(img, fns):
    switches, unresolved, other = [], collections.Counter(), collections.Counter()
    unresolved_sites = []
    bctrl = 0
    for start in sorted(fns):
        name, size, sec = fns[start]
        if not size:
            continue
        s = img.section_of(start)
        if s is None or not (s[5] & 0x20):
            continue
        code = img.read(start, size)
        if code is None:
            continue
        for off in range(0, size, 4):
            w = struct.unpack_from('>I', code, off)[0]
            if w == BCTRL:
                bctrl += 1
            if w != BCTR:
                continue
            addr = start + off
            sw, why = detect_switch(img, start, start + size, addr)
            if sw:
                switches.append(sw)
                continue
            label = classify_bctr(img, start, addr)
            if why == 'lwzx not a table load':
                label = 'indirect jump via pointer table (not a switch)'
            elif why == 'absolute entry outside function':
                label = 'switch whose cases are other functions (indirect tail call)'
            if why not in ('target from lwz', 'target from rlwinm', 'no mtctr', 'target not computed',
                           'lwzx not a table load', 'absolute entry outside function') \
                    and 'pointer' not in label:
                unresolved[why] += 1
                unresolved_sites.append((addr, why))
            else:
                other[label] += 1
    return switches, unresolved, unresolved_sites, other, bctrl


def toml_main(cfg, functions, helpers, extra):
    lines = ['[main]']
    for k, v in cfg.items():
        lines.append('%s = %s' % (k, json.dumps(v) if isinstance(v, (str, bool)) else v))
    for k in sorted(helpers):
        lines.append('%s = 0x%X' % (k, helpers[k]))
    for k, v in extra.items():
        lines.append('%s = 0x%X' % (k, v))
    lines.append('invalid_instructions = [')
    lines.append('    { data = 0x00000000, size = 4 },')
    lines.append(']')
    lines.append('functions = [')
    for a, sz in functions:
        lines.append('    { address = 0x%X, size = 0x%X },' % (a, sz))
    lines.append(']')
    return '\n'.join(lines) + '\n'


def toml_switches(switches):
    out = ['# Generated by tools/recomp_config.py (MSVC 16 absolute / byte / halfword switch shapes)']
    for sw in switches:
        out.append('[[switch]]')
        out.append('base = 0x%X' % sw.bctr)
        out.append('r = %d' % sw.index_reg)
        out.append('default = 0')
        out.append('labels = [' + ', '.join('0x%X' % x for x in sw.labels) + ']')
        out.append('')
    return '\n'.join(out)


def branch_targets(img, start, size):
    """(site, target, conditional) for relative b/bc without link in [start, start+size)."""
    out = []
    code = img.read(start, size)
    for off in range(0, size, 4):
        w = struct.unpack_from('>I', code, off)[0]
        op = w >> 26
        if w & 1 or w & 2:
            continue
        site = start + off
        if op == 18:
            li = w & 0x03FFFFFC
            if li & 0x02000000:
                li -= 0x04000000
            out.append((site, (site + li) & 0xFFFFFFFF, False))
        elif op == 16:
            out.append((site, (site + s16(w & 0xFFFC)) & 0xFFFFFFFF, True))
    return out


def referenced_starts(img, fns):
    """Function starts reached by a direct bl/b from another function or stored as a data word."""
    refs = set()
    for caller, site, callee, tail in call_edges(img, fns):
        refs.add(callee)
    words = set()
    for name, va, vs, ra, rs, ch in img.sections:
        blob = img.data[ra:ra + min(vs, rs)]
        words.update(struct.unpack('>%dI' % (len(blob) // 4), blob[:len(blob) // 4 * 4]))
    refs.update(a for a in fns if a in words)
    return refs


def extend_for_neighbours(chosen, img, refs, max_span=0x400):
    """Merge a function with an adjacent one when a branch lands inside the other's body.

    Jeff/pdata sometimes split hand-written CRT loops or shared tails into two symbols; XenonRecomp
    then drops the branch (`// ERROR`) or emits a goto to an undeclared label. The earlier function
    grows to cover the later one. The later one keeps its own entry only if something references
    it (direct call, tail call or data word); otherwise it is dropped.
    Returns (new list, merges, dropped entries)."""
    starts = [a for a, _ in chosen]
    size = dict(chosen)
    parent = list(range(len(starts)))  # union of index ranges that must become one function

    def root(k):
        while parent[k] != k:
            parent[k] = parent[parent[k]]
            k = parent[k]
        return k

    merges = 0
    for i, a in enumerate(starts):
        for site, tgt, cond in branch_targets(img, a, size[a]):
            if a <= tgt < a + size[a]:
                continue
            j = bisect.bisect_right(starts, tgt) - 1
            if j < 0 or abs(j - i) > 2 or tgt == starts[j] or tgt >= starts[j] + size[starts[j]]:
                continue
            lo, hi = min(i, j), max(i, j)
            if starts[hi] + size[starts[hi]] - starts[lo] > size[starts[lo]] + max_span:
                continue
            for k in range(lo + 1, hi + 1):
                if root(k) != root(lo):
                    parent[root(k)] = root(lo)
            merges += 1
    groups = collections.defaultdict(list)
    for k in range(len(starts)):
        groups[root(k)].append(k)
    out, dropped = [], 0
    for r, members in groups.items():
        members.sort()
        first = starts[members[0]]
        end = max(starts[k] + size[starts[k]] for k in members)
        out.append((first, end - first))
        for k in members[1:]:
            if starts[k] in refs:
                out.append((starts[k], size[starts[k]]))  # keep a separate (overlapping) entry
            else:
                dropped += 1
    out.sort()
    return out, merges, dropped


# --------------------------------------------------------------------------- .pdata + leaf discovery

def read_pdata(img):
    """{begin: size} from the image's .pdata (IMAGE_CE_RUNTIME_FUNCTION: BeginAddress, then a word
    holding PrologLen:8, FuncLen:22 (instructions), ThirtyTwoBit:1, ExceptionFlag:1)."""
    out = {}
    for name, va, vs, ra, rs, ch in img.sections:
        if name != '.pdata':
            continue
        blob = img.read(va, vs)
        for i in range(0, len(blob) - 7, 8):
            begin, data = struct.unpack_from('>II', blob, i)
            size = ((data >> 8) & 0x3FFFFF) * 4
            if begin and size:
                out[begin] = size
    return out


def _branch(w, a):
    """(kind, target) for b/bc/bclr/bcctr at `a`; kind in b, bl, bc, bcl, ret, ctr, cret, cctr."""
    op = w >> 26
    if op == 18:
        li = w & 0x03FFFFFC
        if li & 0x02000000:
            li -= 0x04000000
        return ('bl' if w & 1 else 'b'), ((li if w & 2 else a + li) & 0xFFFFFFFF)
    if op == 16:
        tgt = (s16(w & 0xFFFC) + (0 if w & 2 else a)) & 0xFFFFFFFF
        always = ((w >> 21) & 0x14) == 0x14
        if w & 1:
            return 'bcl', tgt
        return ('b' if always else 'bc'), tgt
    if op == 19:
        xo = (w >> 1) & 0x3FF
        if xo in (16, 528) and not w & 1:
            always = ((w >> 21) & 0x14) == 0x14
            if xo == 16:
                return ('ret' if always else 'cret'), None
            return ('ctr' if always else 'cctr'), None
    return None, None


def function_extent(img, start, limit):
    """End address of the leaf function at `start`: intra-procedural control flow is followed
    (conditional branches, internal `b`, switch tables found by detect_switch) and stops at blr,
    bctr, zero padding, or `limit` (the next known function). Returns (end, switches)."""
    seen = set()
    work = [start]
    end = start + 4
    switches = []
    while work:
        a = work.pop()
        while start <= a < limit and a not in seen:
            w = img.word(a)
            if w is None or w >> 26 == 0:  # padding or primary opcode 0 (illegal): not code
                break
            seen.add(a)
            end = max(end, a + 4)
            kind, tgt = _branch(w, a)
            if kind == 'b':
                if start <= tgt < limit:
                    work.append(tgt)
                break
            if kind == 'bc':
                if start <= tgt < limit:
                    work.append(tgt)
            elif kind in ('ret',):
                break
            elif kind == 'ctr':
                sw, why = detect_switch(img, start, limit, a)
                if sw:
                    switches.append(sw)
                    work.extend(l for l in sw.labels if start <= l < limit)
                    if sw.kind == 'absolute' and sw.table == a + 4:
                        end = max(end, a + 4 + 4 * len(sw.labels))
                break
            a += 4
    return end, switches


def discover_functions(img, known, data_ranges=()):
    """Leaf functions (no .pdata, not in the symbol file) in the code not covered by `known`
    ({start: size}). Entry candidates: direct bl/b targets, aligned code addresses stored as data
    words or built by lis/addi pairs, and the first non-zero word after each covered range; a final
    sweep then walks every remaining gap function by function. `data_ranges` ((start, size)
    objects in .text, e.g. reviewed seed objects) are never treated as code. Returns {start: size}."""
    code = img.code_sections()

    def in_code(a):
        return any(va <= a < va + vs for _, va, vs, _, _, _ in code)

    ivs = []  # disjoint union of known functions and data objects (objects can sit inside functions)
    for a, e in sorted([(a, a + n) for a, n in known.items() if n] + [(a, a + n) for a, n in data_ranges if n]):
        if ivs and a <= ivs[-1][1]:
            ivs[-1] = (ivs[-1][0], max(ivs[-1][1], e))
        else:
            ivs.append((a, e))
    starts = [a for a, _ in ivs]

    def covered(a):
        i = bisect.bisect_right(starts, a) - 1
        return i >= 0 and a < ivs[i][1]

    cands = set()
    for name, va, vs, ra, rs, ch in code:
        blob = img.read(va, vs)
        for off in range(0, len(blob), 4):
            w = struct.unpack_from('>I', blob, off)[0]
            kind, tgt = _branch(w, va + off)
            if kind in ('bl', 'b') and tgt is not None and in_code(tgt) and not covered(tgt):
                cands.add(tgt)
            d = decode(w)
            if d and d[0] == 'addis' and d[2] == 0:  # lis rX,hi ... addi rY,rX,lo
                for k in range(1, 6):
                    if off + 4 * k >= len(blob):
                        break
                    e = decode(struct.unpack_from('>I', blob, off + 4 * k)[0])
                    if e and e[0] == 'addi' and e[2] == d[1]:
                        t = ((d[3] << 16) + e[3]) & 0xFFFFFFFF
                        if not t & 3 and in_code(t) and not covered(t):
                            cands.add(t)
                        break
    for name, va, vs, ra, rs, ch in img.sections:
        if ch & 0x20:
            continue
        blob = img.read(va, vs)
        for off in range(0, len(blob) - 3, 4):
            w = struct.unpack_from('>I', blob, off)[0]
            if not w & 3 and in_code(w) and not covered(w):
                cands.add(w)
    for a, e in ivs:
        b = e
        while in_code(b) and img.word(b) == 0:
            b += 4
        if in_code(b) and not covered(b):
            cands.add(b)
    for name, va, vs, ra, rs, ch in code:
        b = va
        while b < va + vs and img.word(b) == 0:
            b += 4
        if b < va + vs and not covered(b):
            cands.add(b)

    found = {}
    all_starts = sorted(set(starts) | cands)
    taken = []  # discovered (start, end), kept sorted
    for c in sorted(cands):
        j = bisect.bisect_right(taken, (c, 1 << 33)) - 1
        if j >= 0 and c < taken[j][1]:
            continue  # inside a function discovered from an earlier entry
        k = bisect.bisect_right(starts, c)
        limit = starts[k] if k < len(starts) else max(va + vs for _, va, vs, _, _, _ in code)
        sec = img.section_of(c)
        limit = min(limit, sec[1] + sec[2])
        end, _ = function_extent(img, c, limit)
        found[c] = end - c
        bisect.insort(taken, (c, end))

    # sweep: whatever is still uncovered is walked function by function
    allv = sorted(ivs + taken)
    for name, va, vs, ra, rs, ch in code:
        a, j = va, 0
        while a < va + vs:
            while j < len(allv) and allv[j][1] <= a:
                j += 1
            if j < len(allv) and allv[j][0] <= a:
                a = allv[j][1]
                continue
            if img.word(a) >> 26 == 0:  # padding / data words in .text (e.g. the XEX trailer)
                a += 4
                continue
            limit = allv[j][0] if j < len(allv) else va + vs
            limit = min(limit, va + vs)
            end, _ = function_extent(img, a, limit)
            found[a] = end - a
            a = end
    return found


def select_functions(fns, helpers, img):
    """Non-overlapping code functions, minus the save/restore helpers XenonRecomp emits itself."""
    skip = set()
    for key, addr in helpers.items():
        skip.add(addr)
    chosen, end = [], 0
    for a in sorted(fns):
        name, size, sec = fns[a]
        s = img.section_of(a)
        if not size or s is None or not (s[5] & 0x20):
            continue
        if a in skip or name.startswith(('__savegprlr', '__restgprlr', '__savefpr', '__restfpr',
                                         '__savevmx', '__restvmx')):
            continue
        if a < end:
            continue
        w0 = img.word(a)
        if size == 16 and w0 is not None and w0 >> 24 == 0x01 and img.word(a + 12) == BCTR:
            continue  # XEX import thunk: XenonRecomp names it after the import itself
        chosen.append((a, size))
        end = a + size
    return chosen


def cmd_config(args):
    img = Image(Path(args.image).read_bytes())
    fns, objs = load_symbols(args.symbols) if args.symbols else ({}, {})
    sources = collections.Counter({'symbols': len(fns)})
    if args.pdata:
        for a, n in read_pdata(img).items():
            if a not in fns:
                fns[a] = ('pdata_%X' % a, n, '.text')
                sources['pdata'] += 1
            elif not fns[a][1]:
                fns[a] = (fns[a][0], n, fns[a][2])
    helpers = find_helpers(img)
    if args.discover:
        text_objs = [(a, v[1]) for a, v in objs.items() if img.section_of(a) and img.section_of(a)[5] & 0x20]
        # the register save/restore helpers have one entry per register; keep discovery out of them
        text_objs += [(a, HELPER_SIZES[k]) for k, a in helpers.items()]
        for a, n in discover_functions(img, {a: v[1] for a, v in fns.items()}, text_objs).items():
            fns[a] = ('leaf_%X' % a, n, '.text')
            sources['discovered'] += 1
    for k, a in helpers.items():  # drop .pdata/symbol entries that start inside a helper
        for b in [b for b in fns if a < b < a + HELPER_SIZES[k]]:
            del fns[b]
    extra = {}
    for k in ('setjmp', 'longjmp'):
        v = getattr(args, k)
        if v:
            extra[k + '_address'] = int(v, 0)
    functions = select_functions(fns, helpers, img)
    extended = 0
    if not args.no_extend:
        functions, extended, dropped = extend_for_neighbours(functions, img, referenced_starts(img, fns))
        print('merged %d split functions, dropped %d unreferenced inner entries' % (extended, dropped),
              file=sys.stderr)
    switches, unresolved, sites, other, bctrl = scan_functions(img, fns)
    out = Path(args.out_dir)
    out.mkdir(parents=True, exist_ok=True)
    (out / 'ppc').mkdir(exist_ok=True)
    cfg = {'file_path': args.xex, 'out_directory_path': 'ppc',
           'switch_table_file_path': '%s_switch_tables.toml' % args.name}
    for opt in args.opt or []:
        cfg[opt] = True
    (out / ('%s.toml' % args.name)).write_text(toml_main(cfg, functions, helpers, extra))
    (out / ('%s_switch_tables.toml' % args.name)).write_text(toml_switches(switches))
    kinds = collections.Counter(s.kind for s in switches)
    rep = {
        'function_sources': dict(sources),
        'functions_in_symbols': len(fns),
        'functions_emitted': len(functions),
        'functions_extended_over_neighbour': extended,
        'helpers': {k: '0x%X' % v for k, v in sorted(helpers.items())},
        'switches': len(switches),
        'switch_kinds': dict(kinds),
        'switch_count_source': dict(collections.Counter(s.count_src for s in switches)),
        'switch_labels': sum(len(s.labels) for s in switches),
        'bctr_unresolved': dict(unresolved),
        'bctr_unresolved_sites': ['0x%X %s' % x for x in sites[:200]],
        'bctr_other': dict(other),
        'bctrl_sites': bctrl,
    }
    (out / 'report.json').write_text(json.dumps(rep, indent=1) + '\n')
    print(json.dumps({k: v for k, v in rep.items() if k != 'bctr_unresolved_sites'}, indent=1))


# --------------------------------------------------------------------------- boundary survey

def load_ranges():
    sys.path.insert(0, str(ROOT / 'tools'))
    import decomp_survey  # noqa: E402  (bucket ranges, evidence in docs/decomp-remaining.md)
    return decomp_survey.RANGES


def bucket_of(ranges, starts, addr):
    i = bisect.bisect_right(starts, addr) - 1
    if i >= 0 and addr < ranges[i][1]:
        return ranges[i]
    return None


def call_edges(img, fns):
    """Yield (caller_start, site, callee, is_tail) for direct bl and for b leaving the function."""
    for start in sorted(fns):
        name, size, sec = fns[start]
        if not size:
            continue
        s = img.section_of(start)
        if s is None or not (s[5] & 0x20):
            continue
        code = img.read(start, size)
        for off in range(0, size, 4):
            w = struct.unpack_from('>I', code, off)[0]
            if w >> 26 != 18:
                continue
            li = w & 0x03FFFFFC
            if li & 0x02000000:
                li -= 0x04000000
            site = start + off
            tgt = (li if w & 2 else site + li) & 0xFFFFFFFF
            if w & 1:
                yield start, site, tgt, False
            elif not (start <= tgt < start + size):
                yield start, site, tgt, True


def cmd_boundary(args):
    img = Image(Path(args.image).read_bytes())
    fns, objs = load_symbols(args.symbols)
    ranges = sorted(load_ranges())
    starts = [r[0] for r in ranges]
    src_groups = set(args.from_groups.split(','))
    per = collections.defaultdict(lambda: {'callees': collections.Counter(), 'sites': 0, 'callers': set()})
    for caller, site, callee, tail in call_edges(img, fns):
        cb = bucket_of(ranges, starts, caller)
        tb = bucket_of(ranges, starts, callee)
        if not cb or not tb or cb[3] not in src_groups or tb[3] in src_groups:
            continue
        p = per[tb[2]]
        p['callees'][callee] += 1
        p['sites'] += 1
        p['callers'].add(caller)
    rows = []
    for bucket, p in sorted(per.items(), key=lambda kv: -len(kv[1]['callees'])):
        top = [{'addr': '0x%X' % a, 'name': fns.get(a, ('?',))[0], 'sites': n}
               for a, n in p['callees'].most_common(args.top)]
        rows.append({'bucket': bucket, 'distinct_callees': len(p['callees']), 'call_sites': p['sites'],
                     'distinct_callers': len(p['callers']), 'top': top,
                     'all_callees': ['0x%X' % a for a in sorted(p['callees'])]})
    for r in rows:
        print('%-60s callees %5d  sites %6d  callers %5d' % (r['bucket'], r['distinct_callees'],
                                                             r['call_sites'], r['distinct_callers']))
    if args.json:
        Path(args.json).write_text(json.dumps(rows, indent=1) + '\n')


def cmd_imports(args):
    img = Image(Path(args.image).read_bytes())
    fns, objs = load_symbols(args.symbols)
    thunks = {}
    for a in sorted(fns):
        name, size, sec = fns[a]
        w0 = img.word(a)
        if size == 16 and w0 is not None and w0 >> 24 == 0x01 and img.word(a + 8) == 0x7D6903A6 \
                and img.word(a + 12) == BCTR:
            thunks[a] = name
    callers = collections.Counter()
    for caller, site, callee, tail in call_edges(img, fns):
        if callee in thunks:
            callers[callee] += 1
    rows = sorted(((thunks[a], callers[a]) for a in thunks), key=lambda x: -x[1])
    for n, c in rows:
        print('%6d %s' % (c, n))
    print('thunks', len(thunks), 'called', sum(1 for a in thunks if callers[a]))


def reachable(img, start, size, switch_labels):
    """Instruction addresses reachable from the entry by intra-function control flow."""
    end = start + size
    seen, work = set(), [start]
    while work:
        a = work.pop()
        while start <= a < end and a not in seen:
            seen.add(a)
            w = img.word(a)
            op = w >> 26
            if op == 18:  # b / bl
                li = w & 0x03FFFFFC
                if li & 0x02000000:
                    li -= 0x04000000
                tgt = li if w & 2 else a + li
                if w & 1:
                    a += 4
                    continue
                if start <= tgt < end:
                    work.append(tgt)
                break
            if op == 16:  # bc
                bo = (w >> 21) & 31
                tgt = s16(w & 0xFFFC) + (0 if w & 2 else a)
                if not w & 1 and start <= tgt < end:
                    work.append(tgt)
                if bo & 0x14 == 0x14:  # branch always
                    break
                a += 4
                continue
            if op == 19:
                xo = (w >> 1) & 0x3FF
                bo = (w >> 21) & 31
                if xo in (16, 528) and not w & 1:  # bclr / bcctr without link
                    if xo == 528:
                        work.extend(switch_labels.get(a, ()))
                    if bo & 0x14 == 0x14:
                        break
            a += 4
    return seen


def cmd_triage(args):
    """Classify XenonRecomp 'Unrecognized instruction' lines: reachable code vs data in .text."""
    img = Image(Path(args.image).read_bytes())
    fns, objs = load_symbols(args.symbols)
    sws = {}
    if args.switches:
        cur = None
        for line in Path(args.switches).read_text().splitlines():
            if line.startswith('base = '):
                cur = int(line[7:], 16)
            elif line.startswith('labels = ['):
                sws[cur] = [int(x, 16) for x in re.findall(r'0x[0-9A-Fa-f]+', line)]
    ranges = sorted(load_ranges())
    rstarts = [r[0] for r in ranges]
    starts = sorted(fns)
    rx = re.compile(r'Unrecognized instruction at 0x([0-9A-F]+): (\S+)')
    cache = {}
    tally = collections.Counter()
    by_bucket = collections.Counter()
    fn_hit = set()
    for line in Path(args.log).read_text().splitlines():
        m = rx.search(line)
        if not m:
            continue
        addr, mnem = int(m.group(1), 16), m.group(2)
        i = bisect.bisect_right(starts, addr) - 1
        f = starts[i] if i >= 0 else None
        if f is None or addr >= f + fns[f][1]:
            tally[(mnem, 'outside functions')] += 1
            continue
        if f not in cache:
            cache[f] = reachable(img, f, fns[f][1], sws)
        state = 'reachable' if addr in cache[f] else 'unreachable (data/padding)'
        tally[(mnem, state)] += 1
        if state == 'reachable':
            fn_hit.add(f)
            b = bucket_of(ranges, rstarts, addr)
            by_bucket[b[2] if b else '?'] += 1
    rows = collections.defaultdict(dict)
    for (mn, st), n in tally.items():
        rows[mn][st] = n
    for mn, d in sorted(rows.items(), key=lambda kv: -sum(kv[1].values())):
        print('%-12s %s' % (mn, ', '.join('%s %d' % kv for kv in sorted(d.items()))))
    print('reachable sites', sum(n for (m, s), n in tally.items() if s == 'reachable'),
          'in', len(fn_hit), 'functions')
    for b, n in by_bucket.most_common():
        print('  %5d %s' % (n, b))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)
    c = sub.add_parser('config')
    c.add_argument('--image', required=True)
    c.add_argument('--symbols', help='symbols.txt in our split format (optional with --pdata)')
    c.add_argument('--pdata', action='store_true', help='add every .pdata function not in the symbol file')
    c.add_argument('--discover', action='store_true',
                   help='also find leaf functions (no .pdata) by control flow from bl targets and data words')
    c.add_argument('--xex', required=True, help='XEX path as XenonRecomp should see it (relative to out-dir)')
    c.add_argument('--name', default='Swing')
    c.add_argument('--out-dir', required=True)
    c.add_argument('--setjmp')
    c.add_argument('--longjmp')
    c.add_argument('--no-extend', action='store_true', help='do not grow functions over split neighbours')
    c.add_argument('--opt', action='append', help='XenonRecomp optimisation flag to enable, e.g. skip_lr')
    b = sub.add_parser('boundary')
    b.add_argument('--image', required=True)
    b.add_argument('--symbols', required=True)
    b.add_argument('--from-groups', default='game')
    b.add_argument('--top', type=int, default=15)
    b.add_argument('--json')
    i = sub.add_parser('imports')
    i.add_argument('--image', required=True)
    i.add_argument('--symbols', required=True)
    t = sub.add_parser('triage')
    t.add_argument('--image', required=True)
    t.add_argument('--symbols', required=True)
    t.add_argument('--log', required=True, help='XenonRecomp stdout')
    t.add_argument('--switches', help='switch TOML written by `config`')
    args = ap.parse_args(argv)
    {'config': cmd_config, 'boundary': cmd_boundary, 'imports': cmd_imports,
     'triage': cmd_triage}[args.cmd](args)


if __name__ == '__main__':
    main()
