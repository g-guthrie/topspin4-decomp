#!/usr/bin/env python3
"""Build a modified Swing_DLL.xex that Xenia can load: constant patches and recompiled functions.

Everything produced (images, XEX files, reports, compile directories) lives under work/modpatch/
(git-ignored); other output paths are refused.  Nothing game-derived is ever written elsewhere.

  python3 tools/modpatch.py build SPEC.json --out work/modpatch/NAME/Swing_DLL.xex
  python3 tools/modpatch.py build --identity --out work/modpatch/demo/identity.xex
  python3 tools/modpatch.py relink-check src/xbox360/foo.c ts4_name=0x88170DC0 [...]
  python3 tools/modpatch.py disasm work/modpatch/NAME/Swing_DLL.xex 0x88170DC0 [COUNT]

Reading the original XEX needs the retail key (read at run time from the local jeff checkout, see
tools/xex_patch.py) and the `cryptography` package; use work/venv/bin/python.  The decoded original
image is cached in work/modpatch/cache/ so later runs (and the unit tests) need neither.

SPEC.json (addresses are Xbox 360 virtual addresses, hex strings; "old"/"new" are hex byte strings):
  {
    "patches":   [{"address": "0x88170DC0", "old": "3d6088d4", "new": "60000000", "note": "why"}],
    "functions": [{"source": "src/xbox360/foo.c", "function": "ts4_foo", "address": "0x88170DC0",
                   "flags": ["/O1"], "note": "why"}]
  }
Constant patches refuse to apply when the image bytes at `address` differ from `old`.

Function replacement: `source` is compiled with the original compiler exactly as tools/fn_check.py does
(wibo + cl.exe 16.00.10224.00, /O2 /Oi plus the per-file flags of config/54540859/match.json, plus
"flags"; the include path is the source's directory and src/xbox360).  The named function is taken from the
COFF object, its code is placed in free space of the image, its relocations are resolved and its first
instruction at `address` is overwritten with `b new_code`.  The rest of the old function is left in place
as dead code (nothing returns into it), so `address` must be the entry point of a function.

Relocation resolution
  * a symbol the object defines as external (storage 2) whose name is in config/54540859/symbols.txt
    resolves to that game address (calls to existing functions, existing data);
  * an undefined symbol resolves through symbols.txt by name; an unknown name is an error;
  * everything else the code reaches inside the object (static helpers, `$LN` labels, `__real@...`
    float constants and other .rdata) is copied into free space too.  Writable data (.data/.bss) is
    refused: the code region is mapped read-only by Xenia.
  * REL24/REL14: displacement = S + field - section_base (MSVC stores -offset in the field);
    ADDR32: S + field;  REFHI/REFLO(+PAIR): full = S + signext16(REFLO field), hi is carry adjusted.
`relink-check` proves this arithmetic: it relinks an already-matched function at its ORIGINAL address and
compares with the original image bytes; they must be identical.

Free space: see FREE_SPACE below / docs/modpatch.md.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xex_patch  # noqa: E402
import xex_write  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT_ROOT = xex_write.OUT_ROOT
CACHE_DIR = os.path.join(OUT_ROOT, "cache")
SYMBOLS_TXT = os.path.join(ROOT, "config", "54540859", "symbols.txt")
MATCH_JSON = os.path.join(ROOT, "config", "54540859", "match.json")
DEFAULT_XEX = os.path.join(ROOT, "orig", "54540859", "Swing_DLL.xex")
TOOLS = os.path.join(ROOT, "work", "matching-tools")
WIBO = os.path.join(TOOLS, "work_wibo")
CL = os.path.join(TOOLS, "compilers", "X360", "16.00.10224.00", "cl.exe")
PPCDIS = os.path.join(ROOT, "work", "ppcdis", "target", "release", "ppcdis")
BASE_FLAGS = ["/nologo", "/c", "/O2", "/Oi"]

# Page descriptor info values (Xenia: XEX_SECTION_*).  Descriptors count 64 KiB pages for this module.
SECTION_CODE, SECTION_DATA, SECTION_READONLY = 1, 2, 3
PAGE = 0x10000

IMAGE_SCN_CNT_CODE = 0x20
IMAGE_SCN_CNT_UNINIT = 0x80
IMAGE_SCN_MEM_WRITE = 0x80000000
IMAGE_SCN_LNK_COMDAT = 0x1000

FREE_LO, FREE_HI = 0x88B15400, 0x88B20000   # for disassembly labels only; the real range comes from the XEX
PLACEHOLDER_RE = re.compile(r"^(fn|lbl|jumptable|sub|loc)_([0-9A-Fa-f]{8})(?:_\w+)?$")

REL_ADDR32, REL_ADDR16, REL_REL24, REL_REL14 = 0x2, 0x4, 0x6, 0x7
REL_REFHI, REL_REFLO, REL_PAIR = 0x10, 0x11, 0x12


class PatchError(Exception):
    pass


def check_out(path):
    return xex_write.check_out_path(path)


def parse_addr(v):
    return int(v, 16) if isinstance(v, str) else int(v)


# ----------------------------------------------------------------------------- symbols.txt

SYMBOL_RE = re.compile(r"^(\S+) = (\.?\w+):0x([0-9A-Fa-f]+);(.*)$")


class GameSymbols:
    """name -> address and function starts from config/54540859/symbols.txt."""

    def __init__(self, path=SYMBOLS_TXT):
        self.by_name = {}
        self.functions = {}  # address -> (name, size|None)
        self.sorted_addrs = None
        self.dups = set()
        if not os.path.exists(path):
            return
        for ln in open(path, encoding="utf-8", errors="replace"):
            m = SYMBOL_RE.match(ln)
            if not m:
                continue
            name, _sec, addr, rest = m.group(1), m.group(2), int(m.group(3), 16), m.group(4)
            if name in self.by_name and self.by_name[name] != addr:
                self.dups.add(name)
            self.by_name.setdefault(name, addr)
            if "type:function" in rest:
                sz = re.search(r"size:0x([0-9A-Fa-f]+)", rest)
                self.functions.setdefault(addr, (name, int(sz.group(1), 16) if sz else None))

    def name_at(self, addr):
        """'name+off' for the nearest symbol at or below addr (any type), or None."""
        if self.sorted_addrs is None:
            import bisect  # noqa: F401
            self._rev = {}
            for n, a in self.by_name.items():
                self._rev.setdefault(a, n)
            self.sorted_addrs = sorted(self._rev)
        import bisect
        i = bisect.bisect_right(self.sorted_addrs, addr) - 1
        if i < 0:
            return None
        a = self.sorted_addrs[i]
        if addr - a > 0x10000:
            return None
        return self._rev[a] + ("+0x%X" % (addr - a) if addr != a else "")


# ----------------------------------------------------------------------------- COFF reader

class CSym:
    __slots__ = ("name", "value", "section", "storage", "index")

    def __init__(self, name, value, section, storage, index):
        self.name, self.value, self.section, self.storage, self.index = name, value, section, storage, index


class CSec:
    def __init__(self, index, name, data, chars, relocs):
        self.index, self.name, self.data, self.chars, self.relocs = index, name, data, chars, relocs

    @property
    def is_code(self):
        return bool(self.chars & IMAGE_SCN_CNT_CODE)

    @property
    def align(self):
        a = (self.chars >> 20) & 0xF
        return 1 << (a - 1) if a else 4


class Coff:
    """PowerPC COFF object; relocations keep the raw symbol index (needed for PAIR)."""

    def __init__(self, path_or_bytes):
        data = path_or_bytes if isinstance(path_or_bytes, bytes) else open(path_or_bytes, "rb").read()
        _m, nsec, _ts, symoff, nsym, optsz, _ch = struct.unpack_from("<HHIIIHH", data, 0)
        strtab = symoff + nsym * 18

        def nm(raw):
            if raw[:4] == b"\0\0\0\0":
                o = struct.unpack_from("<I", raw, 4)[0]
                return data[strtab + o:data.index(b"\0", strtab + o)].decode("latin-1")
            return raw.rstrip(b"\0").decode("latin-1")

        self.symbols = {}
        i = 0
        while i < nsym:
            raw = data[symoff + 18 * i:symoff + 18 * i + 18]
            value, section, _t, storage, aux = struct.unpack_from("<IhHBB", raw, 8)
            self.symbols[i] = CSym(nm(raw[:8]), value, section, storage, i)
            i += 1 + aux
        self.sections = []
        base = 20 + optsz
        for k in range(nsec):
            rn, _vs, _va, size, ptr, relptr, _ln, nrel, _nl, ch = struct.unpack_from("<8sIIIIIIHHI", data, base + 40 * k)
            if rn.startswith(b"/"):
                o = int(rn[1:].rstrip(b"\0"))
                name = data[strtab + o:data.index(b"\0", strtab + o)].decode("latin-1")
            else:
                name = rn.rstrip(b"\0").decode("latin-1")
            payload = data[ptr:ptr + size] if ptr else bytes(size)
            first = 0
            if ch & 0x01000000 and nrel == 0xFFFF:
                nrel = struct.unpack_from("<I", data, relptr)[0]
                first = 1
            rel = [struct.unpack_from("<IIH", data, relptr + 10 * r) for r in range(first, nrel)]
            self.sections.append(CSec(k + 1, name, payload, ch, rel))

    def defined(self, name):
        return [s for s in self.symbols.values() if s.name == name and s.section > 0]

    def functions_in(self, sec):
        """[(value, name)] of function-like symbols defined in a code section, sorted."""
        out = [(s.value, s.name) for s in self.symbols.values()
               if s.section == sec.index and s.storage in (2, 3) and not s.name.startswith((".", "$"))]
        return sorted(out)

    def find_function(self, name):
        base = lambda n: n[1:].split("@", 1)[0] if n.startswith("?") else n  # noqa: E731
        for s in self.symbols.values():
            if s.section > 0 and s.storage in (2, 3) and self.sections[s.section - 1].is_code \
                    and not s.name.startswith((".", "$")) and (s.name == name or base(s.name) == name):
                return s
        raise PatchError("function %s is not defined in the compiled object (have: %s)" % (
            name, ", ".join(s.name for s in self.symbols.values()
                            if s.section > 0 and s.storage == 2 and self.sections[s.section - 1].is_code)))


# ----------------------------------------------------------------------------- compile

def source_flags(source):
    """compiler flags config/54540859/match.json records for this source (repo-relative path)."""
    flags = list(BASE_FLAGS)
    try:
        m = json.load(open(MATCH_JSON))
        rel = os.path.relpath(os.path.realpath(source), ROOT).replace(os.sep, "/")
        extra = m.get("compiler_flag_exceptions", {}).get(rel)
        if extra is not None:
            flags = flags + [f for f in extra if f not in flags]
    except (OSError, ValueError):
        pass
    return flags


HOOK_HEADER = """/* generated by tools/modpatch.py: register context passed to hook stubs */
#ifndef MODPATCH_HOOK_H
#define MODPATCH_HOOK_H
typedef struct HookCtx {
    unsigned int gpr[32];        /* 0x000 r0..r31; gpr[1] is the original sp (read only) */
    double       fpr[32];        /* 0x080 f0..f31 */
    unsigned int lr, cr, ctr, xer;   /* 0x180 */
    unsigned int skip_original;  /* 0x190 write nonzero to NOT execute the displaced instruction */
    unsigned int hook_address;   /* 0x194 */
    unsigned int reserved[2];    /* 0x198 */
    unsigned int vr[128][4];     /* 0x1A0 vector registers; present only when the stub's "vmx" > 0 */
} HookCtx;
#endif
"""

_COMPILED = {}


def compile_cached(source, flags=()):
    key = (os.path.realpath(source), tuple(flags))
    if key not in _COMPILED:
        _COMPILED[key] = compile_source(source, flags)
    return _COMPILED[key]


def compile_source(source, extra_flags=(), keep=False):
    for need in (WIBO, CL):
        if not os.path.exists(need):
            raise PatchError("compiler toolchain missing: %s (see docs/ltcg-route.md section 2)" % need)
    os.makedirs(os.path.join(OUT_ROOT, "build"), exist_ok=True)
    work = tempfile.mkdtemp(prefix="cc-", dir=os.path.join(OUT_ROOT, "build"))
    src = os.path.abspath(source)
    local = os.path.join(work, os.path.basename(src))
    shutil.copyfile(src, local)
    open(os.path.join(work, "modpatch_hook.h"), "w").write(HOOK_HEADER)
    inc = ["/I" + os.path.relpath(d, work) for d in sorted({os.path.dirname(src), os.path.join(ROOT, "src", "xbox360")})]
    env = dict(os.environ, TMP=work, TEMP=work)
    cmd = [WIBO, CL, *source_flags(src), *extra_flags, *inc, os.path.basename(local)]
    r = subprocess.run(cmd, cwd=work, env=env, capture_output=True, text=True)
    obj = os.path.join(work, os.path.splitext(os.path.basename(src))[0] + ".obj")
    if r.returncode != 0 or not os.path.isfile(obj):
        raise PatchError("compile failed:\n" + r.stdout + r.stderr)
    coff = Coff(obj)
    if not keep:
        shutil.rmtree(work, ignore_errors=True)
    return coff, [l.strip() for l in (r.stdout + r.stderr).splitlines() if "warning" in l]


# ----------------------------------------------------------------------------- relocation / placement

def sext(v, bits):
    v &= (1 << bits) - 1
    return v - (1 << bits) if v >> (bits - 1) else v


def align_up(v, a):
    return (v + a - 1) & ~(a - 1)


class Placer:
    """Places the code/constants a function needs and resolves its relocations.

    `alloc(size, align)` returns the address for a new unit; `fixed` maps (section, start) to a
    forced address (used by relink-check).  Result: self.blobs [(addr, bytes, label)] and self.bindings.
    """

    def __init__(self, obj, syms, alloc, fixed=None):
        self.obj, self.syms, self.alloc, self.fixed = obj, syms, alloc, fixed or {}
        self.units = {}      # (sec, start) -> dict(end, base, addr, data)
        self.order = []
        self.queue = []
        self.bindings = []   # (unit label, offset, kind, symbol name, resolved address)

    # -- units
    def unit_for(self, sec_index, value):
        sec = self.obj.sections[sec_index - 1]
        if sec.chars & IMAGE_SCN_MEM_WRITE or sec.chars & IMAGE_SCN_CNT_UNINIT:
            raise PatchError("object section %s (%s) is writable/uninitialised data; new writable data is not "
                             "supported (the code region is read-only)" % (sec.index, sec.name))
        start, end = 0, len(sec.data)
        if sec.is_code:
            funcs = [f for f in self.obj.functions_in(sec)]
            starts = sorted({v for v, _n in funcs} | {0}) if funcs else [0]
            cands = [v for v in starts if v <= value]
            start = cands[-1] if cands else 0
            nxt = [v for v in starts if v > start]
            end = nxt[0] if nxt else len(sec.data)
        key = (sec_index, start)
        if key not in self.units:
            u = dict(sec=sec, start=start, end=end, label="%s+0x%X" % (sec.name, start))
            u["size"] = end - start
            fixed = self.fixed.get(key)
            u["addr"] = fixed if fixed is not None else self.alloc(max(u["size"], 4), max(16, sec.align))
            u["base"] = u["addr"] - start
            self.units[key] = u
            self.order.append(key)
            self.queue.append(key)
        return self.units[key]

    def symbol_address(self, sym):
        if sym.section > 0 and not (sym.storage == 2 and sym.name in self.syms.by_name):
            u = self.unit_for(sym.section, sym.value)
            return u["base"] + sym.value
        if sym.section in (0, -1) or (sym.section > 0 and sym.storage == 2):
            if sym.name in self.syms.by_name:
                return self.syms.by_name[sym.name]
            m = PLACEHOLDER_RE.match(sym.name)   # fn_88613268 / lbl_88D45B38: the address is the name
            if m:
                return int(m.group(2), 16)
        raise PatchError("unresolved symbol %r: not defined in the object and not in config/54540859/symbols.txt"
                         % sym.name)

    def place(self, entry_sym):
        u0 = self.unit_for(entry_sym.section, entry_sym.value)
        self.entry = u0["base"] + entry_sym.value
        while self.queue:
            self._resolve(self.units[self.queue.pop(0)])
        self.blobs = [(self.units[k]["addr"], self.units[k]["data"], self.units[k]["label"]) for k in self.order]
        return self.entry

    def _resolve(self, u):
        sec, start, end = u["sec"], u["start"], u["end"]
        data = bytearray(sec.data[start:end])
        rel = [r for r in sec.relocs if start <= r[0] < end]
        for idx, (off, symidx, kind) in enumerate(rel):
            if kind == REL_PAIR:
                continue
            sym = self.obj.symbols.get(symidx)
            if sym is None:
                raise PatchError("relocation at %s+0x%X names missing symbol #%d" % (sec.name, off, symidx))
            S = self.symbol_address(sym)
            o = off - start
            word = struct.unpack_from(">I", data, o)[0]
            if kind == REL_REL24:
                disp = S + sext(word & 0x03FFFFFC, 26) - u["base"]
                if disp % 4 or not -0x2000000 <= disp < 0x2000000:
                    raise PatchError("REL24 at %s+0x%X out of range (%#x)" % (sec.name, off, disp))
                word = (word & ~0x03FFFFFC & 0xFFFFFFFF) | (disp & 0x03FFFFFC)
            elif kind == REL_REL14:
                disp = S + sext(word & 0xFFFC, 16) - u["base"]
                if disp % 4 or not -0x8000 <= disp < 0x8000:
                    raise PatchError("REL14 at %s+0x%X out of range" % (sec.name, off))
                word = (word & ~0xFFFC & 0xFFFFFFFF) | (disp & 0xFFFC)
            elif kind == REL_ADDR32:
                word = (S + word) & 0xFFFFFFFF
            elif kind == REL_ADDR16:
                word = (word & 0xFFFF0000) | ((S + sext(word, 16)) & 0xFFFF)
            elif kind == REL_REFLO:
                word = (word & 0xFFFF0000) | ((S + sext(word, 16)) & 0xFFFF)
            elif kind == REL_REFHI:
                # the displacement lives in the matching REFLO instruction (next REFLO on this symbol)
                lo_off = next((r[0] for r in rel[idx + 1:] if r[2] == REL_REFLO and r[1] == symidx), None)
                if lo_off is not None:
                    lo = sext(struct.unpack_from(">I", data, lo_off - start)[0], 16)
                else:
                    pair = rel[idx + 1] if idx + 1 < len(rel) and rel[idx + 1][2] == REL_PAIR else None
                    lo = sext(pair[1], 16) if pair else 0
                full = (S + lo) & 0xFFFFFFFF
                word = (word & 0xFFFF0000) | (((full + 0x8000) >> 16) & 0xFFFF)
            else:
                raise PatchError("unsupported relocation type %#x at %s+0x%X (%s)" % (kind, sec.name, off, sym.name))
            struct.pack_into(">I", data, o, word)
            self.bindings.append(dict(unit=u["label"], offset=o, kind=kind, symbol=sym.name, address=S))
        u["data"] = bytes(data)


# ----------------------------------------------------------------------------- image + free space

class Image:
    def __init__(self, data, load_address, code_range, sections):
        self.data = bytearray(data)
        self.base = load_address
        self.code_range = code_range     # (lo, hi) virtual addresses of CODE page descriptors
        self.sections = sections         # [(name, va, vsize)] from the PE header
        self.writes = []                 # [(addr, length, note)]
        self.data_range = []
        self.free_next, self.free_end = self._free_space()
        self.free_start = self.free_next

    def _free_space(self):
        lo, hi = self.code_range
        end_sec = max([self.base + va + vs for _n, va, vs in self.sections if self.base + va < hi] + [lo])
        last = hi - self.base
        while last > 0 and self.data[last - 1] == 0:
            last -= 1
        start = align_up(max(self.base + last, end_sec), 0x200)
        return start, hi

    def read(self, addr, n):
        o = addr - self.base
        if o < 0 or o + n > len(self.data):
            raise PatchError("address %#x outside the image" % addr)
        return bytes(self.data[o:o + n])

    def write(self, addr, data, note=""):
        for a, n, _ in self.writes:
            if addr < a + n and a < addr + len(data):
                raise PatchError("write at %#x overlaps an earlier patch at %#x" % (addr, a))
        o = addr - self.base
        self.read(addr, len(data))
        self.data[o:o + len(data)] = data
        self.writes.append((addr, len(data), note))

    def alloc(self, size, align=16):
        a = align_up(self.free_next, align)
        if a + size > self.free_end:
            raise PatchError("free space exhausted (%#x..%#x)" % (self.free_start, self.free_end))
        if any(self.data[a - self.base:a - self.base + size]):
            raise PatchError("free space at %#x is not zero" % a)
        self.free_next = a + size
        return a


def load_original(xex_path=DEFAULT_XEX, image_cache=True):
    """(xex bytes, decoded image bytes); the decode is cached under work/modpatch/cache/."""
    xb = open(xex_path, "rb").read()
    tag = hashlib.sha256(xb).hexdigest()[:16]
    cache = os.path.join(CACHE_DIR, tag + ".image")
    if image_cache and os.path.exists(cache):
        return xb, open(cache, "rb").read()
    img = xex_write.decode_image(xb)
    if image_cache:
        os.makedirs(CACHE_DIR, exist_ok=True)
        open(cache, "wb").write(img)
    return xb, img


def image_from(xex_bytes, img):
    x = xex_patch.Xex(xex_bytes)
    sec = x.sec
    count = struct.unpack_from(">I", xex_bytes, sec + 0x180)[0]
    page, lo, hi = 0, None, None
    for i in range(count):
        v = struct.unpack_from(">I", xex_bytes, sec + 0x184 + 24 * i)[0]
        info, n = v & 0xF, v >> 4
        if info == SECTION_CODE:
            lo = page * PAGE if lo is None else lo
            hi = (page + n) * PAGE
        page += n
    if lo is None:
        raise PatchError("XEX has no CODE page descriptors")
    im = Image(img, x.load_address, (x.load_address + lo, x.load_address + hi), xex_patch.pe_sections(img))
    im.data_range, page = [], 0
    for i in range(count):
        v = struct.unpack_from(">I", xex_bytes, sec + 0x184 + 24 * i)[0]
        if v & 0xF == SECTION_DATA:
            im.data_range.append((x.load_address + page * PAGE, x.load_address + (page + (v >> 4)) * PAGE))
        page += v >> 4
    return im


# ----------------------------------------------------------------------------- operations

def apply_constant_patches(image, patches):
    out = []
    for p in patches:
        addr = parse_addr(p["address"])
        old, new = bytes.fromhex(p["old"]), bytes.fromhex(p["new"])
        if len(old) != len(new):
            raise PatchError("patch at %#x: old and new differ in length" % addr)
        have = image.read(addr, len(old))
        if have != old:
            raise PatchError("patch at %#x refused: image has %s, patch expects %s" % (addr, have.hex(), old.hex()))
        image.write(addr, new, p.get("note", ""))
        out.append(dict(address="0x%08X" % addr, length=len(new), note=p.get("note", "")))
    return out


def replace_function(image, syms, fn, source=None):
    """Compile fn['source'], place fn['function'] in free space and branch fn['address'] to it."""
    addr = parse_addr(fn["address"])
    if addr % 4:
        raise PatchError("address %#x is not word aligned" % addr)
    src = fn["source"]
    if not os.path.isabs(src):
        src = src if os.path.exists(src) else os.path.join(ROOT, src)
    obj, warnings = compile_cached(src, fn.get("flags", []))
    entry = obj.find_function(fn["function"])
    if "expect_old" in fn:
        eo = bytes.fromhex(fn["expect_old"])
        if image.read(addr, len(eo)) != eo:
            raise PatchError("function at %#x does not start with %s" % (addr, fn["expect_old"]))
    known = syms.functions.get(addr)
    if known is None and not fn.get("force"):
        raise PatchError("%#x is not a function start in symbols.txt (set \"force\": true to override)" % addr)
    placer = Placer(obj, syms, image.alloc)
    new_entry = placer.place(entry)
    for a, data, label in placer.blobs:
        image.write(a, data, "%s %s" % (fn["function"], label))
    disp = new_entry - addr
    if not -0x2000000 <= disp < 0x2000000:
        raise PatchError("branch from %#x to %#x is out of range" % (addr, new_entry))
    old_word = image.read(addr, 4)
    image.write(addr, struct.pack(">I", 0x48000000 | (disp & 0x03FFFFFC)), "b to %s" % fn["function"])
    return dict(function=fn["function"], source=fn["source"], address="0x%08X" % addr,
                original_name=known[0] if known else None, old_first_word=old_word.hex(),
                new_code="0x%08X" % new_entry, new_code_size=sum(len(b) for _a, b, _l in placer.blobs),
                blobs=[dict(address="0x%08X" % a, size=len(d), what=l) for a, d, l in placer.blobs],
                relocations=[dict(unit=b["unit"], offset=b["offset"], kind=b["kind"], symbol=b["symbol"],
                                  address="0x%08X" % b["address"],
                                  game_symbol=syms.name_at(b["address"])) for b in placer.bindings],
                warnings=warnings)


# ----------------------------------------------------------------------------- tiny PPC assembler

def _d(op, rt, ra, imm):
    return (op << 26) | (rt << 21) | (ra << 16) | (imm & 0xFFFF)


def a_addi(rt, ra, imm): return _d(14, rt, ra, imm)
def a_li(rt, imm): return _d(14, rt, 0, imm)
def a_lis(rt, imm): return _d(15, rt, 0, imm)
def a_ori(ra, rs, imm): return _d(24, rs, ra, imm)
def a_lwz(rt, off, ra): return _d(32, rt, ra, off)
def a_stw(rs, off, ra): return _d(36, rs, ra, off)
def a_stwu(rs, off, ra): return _d(37, rs, ra, off)
def a_lfs(fr, off, ra): return _d(48, fr, ra, off)
def a_lfd(fr, off, ra): return _d(50, fr, ra, off)
def a_stfs(fr, off, ra): return _d(52, fr, ra, off)
def a_stfd(fr, off, ra): return _d(54, fr, ra, off)
def a_cmpwi(ra, imm): return _d(11, 0, ra, imm)
def a_blr(): return 0x4E800020


def a_mfspr(rt, spr): return (31 << 26) | (rt << 21) | ((spr & 31) << 16) | ((spr >> 5) << 11) | (339 << 1)
def a_mtspr(rs, spr): return (31 << 26) | (rs << 21) | ((spr & 31) << 16) | ((spr >> 5) << 11) | (467 << 1)
def a_mflr(rt): return a_mfspr(rt, 8)
def a_mtlr(rs): return a_mtspr(rs, 8)
def a_mfctr(rt): return a_mfspr(rt, 9)
def a_mtctr(rs): return a_mtspr(rs, 9)
def a_mfxer(rt): return a_mfspr(rt, 1)
def a_mtxer(rs): return a_mtspr(rs, 1)
def a_mfcr(rt): return (31 << 26) | (rt << 21) | (19 << 1)
def a_mtcr(rs): return (31 << 26) | (rs << 21) | (0xFF << 12) | (144 << 1)   # mtcrf 0xFF


def a_b(disp, link=False):
    if disp % 4 or not -0x2000000 <= disp < 0x2000000:
        raise PatchError("branch displacement %#x does not fit" % disp)
    return 0x48000000 | (disp & 0x03FFFFFC) | (1 if link else 0)


def a_bne(disp):   # bc 4,2 (branch if cr0.eq clear)
    if disp % 4 or not -0x8000 <= disp < 0x8000:
        raise PatchError("conditional branch displacement %#x does not fit" % disp)
    return (16 << 26) | (4 << 21) | (2 << 16) | (disp & 0xFFFC)


def a_stvx(v, ra, rb):
    if v < 32:
        return (31 << 26) | (v << 21) | (ra << 16) | (rb << 11) | (231 << 1)
    return 0x100001C3 | ((v & 31) << 21) | (((v >> 5) & 3) << 2) | (ra << 16) | (rb << 11)   # stvx128


def a_lvx(v, ra, rb):
    if v < 32:
        return (31 << 26) | (v << 21) | (ra << 16) | (rb << 11) | (103 << 1)
    return 0x100000C3 | ((v & 31) << 21) | (((v >> 5) & 3) << 2) | (ra << 16) | (rb << 11)   # lvx128


def relocate_displaced(word, old_addr, new_addr):
    """Re-encode one instruction moved from old_addr to new_addr; refuse if it cannot be."""
    op = word >> 26
    if op == 18 and not word & 2:               # b / bl (relative)
        target = old_addr + sext(word & 0x03FFFFFC, 26)
        disp = target - new_addr
        if not -0x2000000 <= disp < 0x2000000:
            raise PatchError("displaced branch at %#x cannot reach its target from %#x" % (old_addr, new_addr))
        return (word & ~0x03FFFFFC & 0xFFFFFFFF) | (disp & 0x03FFFFFC)
    if op == 16 and not word & 2:               # bc (relative)
        target = old_addr + sext(word & 0xFFFC, 16)
        disp = target - new_addr
        if not -0x8000 <= disp < 0x8000:
            raise PatchError("displaced conditional branch at %#x does not reach its target (%#x) from %#x; "
                             "hook a different instruction" % (old_addr, target, new_addr))
        return (word & ~0xFFFC & 0xFFFFFFFF) | (disp & 0xFFFC)
    return word


# ----------------------------------------------------------------------------- hooks

CTX_OFF = 0x50                 # the wrapper frame keeps 0x50 bytes for the callee's argument/home area
CTX_GPR, CTX_FPR, CTX_LR, CTX_CR, CTX_CTR, CTX_XER, CTX_SKIP, CTX_HOOK, CTX_VR = 0, 0x80, 0x180, 0x184, 0x188, \
    0x18C, 0x190, 0x194, 0x1A0


def hook_wrapper(hook_addr, wrapper_addr, stub_addr, ret_addr, displaced, vmx, redzone):
    """Words of the register-saving wrapper for a C stub (see docs/modpatch.md section 3)."""
    nvec = {0: 0, 1: 32, 2: 128}[vmx]
    ctx_size = CTX_VR + 16 * nvec
    frame = align_up(CTX_OFF + ctx_size, 16)
    total = align_up(redzone, 16) + frame
    if total >= 0x8000:
        raise PatchError("hook frame too large")
    C = CTX_OFF
    w = []
    w.append(a_stwu(1, -total, 1))
    w.append(a_stw(0, C + CTX_GPR, 1))
    for i in range(2, 32):
        w.append(a_stw(i, C + CTX_GPR + 4 * i, 1))
    w += [a_addi(0, 1, total), a_stw(0, C + CTX_GPR + 4, 1)]
    for rd, off in ((a_mflr, CTX_LR), (a_mfcr, CTX_CR), (a_mfctr, CTX_CTR), (a_mfxer, CTX_XER)):
        w += [rd(0), a_stw(0, C + off, 1)]
    w += [a_lis(0, (hook_addr >> 16) & 0xFFFF), a_ori(0, 0, hook_addr & 0xFFFF), a_stw(0, C + CTX_HOOK, 1),
          a_li(0, 0), a_stw(0, C + CTX_SKIP, 1)]
    for i in range(32):
        w.append(a_stfd(i, C + CTX_FPR + 8 * i, 1))
    for v in range(nvec):
        w += [a_li(0, C + CTX_VR + 16 * v), a_stvx(v, 1, 0)]
    w.append(a_addi(3, 1, C))
    w.append(a_b(stub_addr - (wrapper_addr + 4 * len(w)), link=True))
    w += [a_lwz(0, C + CTX_SKIP, 1), a_cmpwi(0, 0)]
    bne_at = len(w)
    w.append(0)   # patched below

    def restore():
        r = []
        for v in range(nvec):
            r += [a_li(0, C + CTX_VR + 16 * v), a_lvx(v, 1, 0)]
        for i in range(32):
            r.append(a_lfd(i, C + CTX_FPR + 8 * i, 1))
        for wr, off in ((a_mtlr, CTX_LR), (a_mtcr, CTX_CR), (a_mtctr, CTX_CTR), (a_mtxer, CTX_XER)):
            r += [a_lwz(0, C + off, 1), wr(0)]
        for i in range(2, 32):
            r.append(a_lwz(i, C + CTX_GPR + 4 * i, 1))
        r += [a_lwz(0, C + CTX_GPR, 1), a_addi(1, 1, total)]
        return r
    w += restore()
    w.append(relocate_displaced(displaced, hook_addr, wrapper_addr + 4 * len(w)))
    w.append(a_b(ret_addr - (wrapper_addr + 4 * len(w))))
    skip_at = len(w)
    w[bne_at] = a_bne(4 * (skip_at - bne_at))
    w += restore()
    w.append(a_b(ret_addr - (wrapper_addr + 4 * len(w))))
    return w


def place_hook(image, syms, hk):
    addr = parse_addr(hk["hook"])
    if addr % 4:
        raise PatchError("hook address %#x is not word aligned" % addr)
    expect = bytes.fromhex(hk.get("expect", ""))
    if len(expect) < 4 or len(expect) % 4:
        raise PatchError("hook %#x: \"expect\" must give the original instruction word(s) as hex" % addr)
    old = image.read(addr, len(expect))
    if old != expect:
        raise PatchError("hook %#x refused: image has %s, manifest expects %s" % (addr, old.hex(), expect.hex()))
    displaced = struct.unpack_from(">I", old, 0)[0]
    stub = hk["stub"]
    ret = addr + 4
    info = dict(hook="0x%08X" % addr, displaced="%08x" % displaced, note=hk.get("note", ""))
    if "words" in stub:
        words = [parse_addr(x) & 0xFFFFFFFF for x in stub["words"]]
        n = len(words) + 2
        base = image.alloc(4 * n, 16)
        body = words + [relocate_displaced(displaced, addr, base + 4 * len(words))]
        body.append(a_b(ret - (base + 4 * len(body))))
        image.write(base, b"".join(struct.pack(">I", x) for x in body), "hook words stub for %#x" % addr)
        entry = base
        info.update(kind="words", stub="0x%08X" % base, size=4 * n)
    else:
        vmx = int(stub.get("vmx", 2))
        redzone = int(stub.get("redzone", 512))
        if vmx not in (0, 1, 2):
            raise PatchError("stub vmx must be 0, 1 or 2")
        src = stub["source"]
        if not os.path.isabs(src):
            src = src if os.path.exists(src) else os.path.join(ROOT, src)
        obj, warnings = compile_cached(src, stub.get("flags", []))
        entry_sym = obj.find_function(stub["function"])
        size = 4 * len(hook_wrapper(addr, 0x88000000, 0x88000000, 0x88000004, 0x60000000, vmx, redzone))
        wbase = image.alloc(size, 16)
        placer = Placer(obj, syms, image.alloc)
        stub_entry = placer.place(entry_sym)
        for a, data, label in placer.blobs:
            image.write(a, data, "%s %s" % (stub["function"], label))
        words = hook_wrapper(addr, wbase, stub_entry, ret, displaced, vmx, redzone)
        assert 4 * len(words) == size
        image.write(wbase, b"".join(struct.pack(">I", x) for x in words), "hook wrapper for %#x" % addr)
        entry = wbase
        info.update(kind="c", function=stub["function"], source=stub["source"], vmx=vmx, redzone=redzone,
                    wrapper="0x%08X" % wbase, wrapper_size=size, stub_code="0x%08X" % stub_entry,
                    stub_size=sum(len(b) for _a, b, _l in placer.blobs), warnings=warnings,
                    relocations=[dict(symbol=b["symbol"], address="0x%08X" % b["address"], kind=b["kind"])
                                 for b in placer.bindings])
    disp = entry - addr
    image.write(addr, struct.pack(">I", a_b(disp)), "hook branch at %#x" % addr)
    info["entry"] = "0x%08X" % entry
    return info


# ----------------------------------------------------------------------------- patch data area

DATA_BASE = 0x88DCE000
DATA_SIZE = 0x2000
_ELEM = {"u8": (1, "B"), "u16": (2, ">H"), "u32": (4, ">I"), "s32": (4, ">i"), "f32": (4, ">f")}


def encode_value(v):
    """hex string, bytes list, or {"u8"|"u16"|"u32"|"s32"|"f32": [...]} -> (bytes, element size)."""
    if isinstance(v, str):
        b = bytes.fromhex(v[2:] if v.startswith("0x") else v)
        return b, 1
    if isinstance(v, dict) and len(v) == 1:
        (k, vals), = v.items()
        if k not in _ELEM:
            raise PatchError("unknown value type %r" % k)
        size, fmt = _ELEM[k]
        if not isinstance(vals, list):
            vals = [vals]
        out = b"".join(struct.pack(">B" if k == "u8" else fmt, x) for x in vals)
        return out, size
    raise PatchError("cannot encode value %r" % (v,))


def merge_specs(specs):
    out = dict(patches=[], functions=[], hooks=[], data=[], data_set=[])
    seen = {}
    for sp in specs:
        for k in ("patches", "functions", "hooks", "data_set"):
            out[k] += sp.get(k, [])
        for d in sp.get("data", []):
            n = d["name"]
            if n in seen:
                prev = seen[n]
                for f in ("offset", "size"):
                    if f in d and f in prev and d[f] != prev[f]:
                        raise PatchError("data %s declared with different %s in two manifests" % (n, f))
                prev.update({k: v for k, v in d.items()})
            else:
                seen[n] = dict(d)
                out["data"].append(seen[n])
    return out


def layout_data(entries, sets):
    """-> {name: (offset, bytearray)} for the patch data area."""
    table, nxt = {}, 0
    for d in entries:
        init = encode_value(d["init"])[0] if "init" in d else b""
        size = int(d.get("size", len(init)))
        if len(init) > size:
            raise PatchError("data %s: init is longer than size" % d["name"])
        if "offset" in d:
            off = parse_addr(d["offset"])
        else:
            off = align_up(nxt, int(d.get("align", 4)))
        if off + size > DATA_SIZE:
            raise PatchError("data %s does not fit in the %#x-byte patch data area" % (d["name"], DATA_SIZE))
        for n, (o, b) in table.items():
            if off < o + len(b) and o < off + size:
                raise PatchError("data %s overlaps data %s" % (d["name"], n))
        table[d["name"]] = (off, bytearray(init + bytes(size - len(init))))
        nxt = max(nxt, off + size)
    for st in sets:
        n = st["name"]
        if n not in table:
            raise PatchError("data_set names unknown data %r" % n)
        val, esize = encode_value(st["value"])
        at = int(st.get("index", 0)) * esize
        off, buf = table[n]
        if at + len(val) > len(buf):
            raise PatchError("data_set %s: value does not fit" % n)
        buf[at:at + len(val)] = val
    return table


def setup_data(image, syms, spec):
    table = layout_data(spec.get("data", []), spec.get("data_set", []))
    lo = image.data_range
    if not (lo and any(a <= DATA_BASE and DATA_BASE + DATA_SIZE <= b for a, b in lo)):
        raise PatchError("patch data area %#x+%#x is not inside a DATA page range" % (DATA_BASE, DATA_SIZE))
    if any(image.read(DATA_BASE, DATA_SIZE)):
        raise PatchError("patch data area at %#x is not zero in the image" % DATA_BASE)
    rep = []
    for n, (off, buf) in table.items():
        if n in syms.by_name:
            raise PatchError("data name %r collides with a game symbol" % n)
        syms.by_name[n] = DATA_BASE + off
        if any(buf):
            image.write(DATA_BASE + off, bytes(buf), "data " + n)
        rep.append(dict(name=n, address="0x%08X" % (DATA_BASE + off), offset=off, size=len(buf), hex=bytes(buf).hex()))
    return rep


def self_check(orig_xex, orig_img, image, out_xex_bytes):
    """Round trip + diff accounting; returns facts or raises."""
    final = bytes(image.data)
    got = xex_write.decode_image(out_xex_bytes)
    if got != final:
        raise AssertionError("XEX round trip differs from the modified image")
    expect = bytearray(orig_img)
    for addr, n, _ in image.writes:
        o = addr - image.base
        expect[o:o + n] = final[o:o + n]
    if bytes(expect) != final:
        raise AssertionError("image differs from the original outside the recorded writes")
    return dict(round_trip="identical", recorded_writes=len(image.writes),
                bytes_written=sum(n for _a, n, _ in image.writes), image_sha256=hashlib.sha256(final).hexdigest())


def build(spec, out_xex, xex_path=DEFAULT_XEX, compression="basic"):
    """`spec` is one manifest dict or a list of them (merged, see docs/modpatch.md)."""
    out_xex = check_out(out_xex)
    if isinstance(spec, list):
        spec = merge_specs(spec)
    else:
        spec = merge_specs([spec])
    orig_xex, orig_img = load_original(xex_path)
    image = image_from(orig_xex, orig_img)
    syms = GameSymbols()
    report = dict(free_space=dict(start="0x%08X" % image.free_start, end="0x%08X" % image.free_end,
                                  size=image.free_end - image.free_start),
                  patch_data_area=dict(address="0x%08X" % DATA_BASE, size=DATA_SIZE), data=[], patches=[],
                  functions=[], hooks=[])
    report["data"] = setup_data(image, syms, spec)
    report["patches"] = apply_constant_patches(image, spec.get("patches", []))
    for fn in spec.get("functions", []):
        report["functions"].append(replace_function(image, syms, fn))
    for hk in spec.get("hooks", []):
        report["hooks"].append(place_hook(image, syms, hk))
    data = xex_write.write_xex(orig_xex, bytes(image.data), compression)
    report["check"] = self_check(orig_xex, orig_img, image, data) if compression == "basic" else {}
    report["free_space"]["used"] = image.free_next - image.free_start
    report["output"] = dict(xex_sha256=hashlib.sha256(data).hexdigest(), size=len(data))
    os.makedirs(os.path.dirname(out_xex), exist_ok=True)
    open(out_xex, "wb").write(data)
    open(out_xex + ".image", "wb").write(bytes(image.data))
    json.dump(report, open(out_xex + ".report.json", "w"), indent=1)
    return report


def parse_cli_value(txt):
    """'01', 'u32:1,2', 'f32:1.5' -> bytes"""
    if ":" in txt:
        k, _, rest = txt.partition(":")
        vals = [float(x) if k == "f32" else int(x, 0) for x in rest.split(",")]
        return encode_value({k: vals})[0]
    return encode_value(txt)[0]


def setdata(xex_in, xex_out, assignments):
    """Edit named patch-data values of an already built XEX (uses its .report.json); no recompilation."""
    out = check_out(xex_out)
    rep = json.load(open(xex_in + ".report.json"))
    names = {d["name"]: d for d in rep["data"]}
    data = bytearray(open(xex_in, "rb").read())
    x = xex_patch.Xex(bytes(data))
    enc, comp, ff = x.file_format()
    if enc != 0 or comp not in (0, 1):
        raise PatchError("setdata needs an unencrypted, uncompressed XEX (one written by modpatch)")
    base = x.load_address
    for a in assignments:
        name, _, val = a.partition("=")
        idx = 0
        if "[" in name:
            name, _, r = name.partition("[")
            idx = int(r.rstrip("]"), 0)
        if name not in names:
            raise PatchError("no data symbol %r in %s.report.json" % (name, xex_in))
        d = names[name]
        v = parse_cli_value(val)
        esz = 4 if ":" in val else 1
        at = idx * esz
        if at + len(v) > d["size"]:
            raise PatchError("value does not fit in %s" % name)
        pos = x.data_off + (parse_addr(d["address"]) - base) + at
        data[pos:pos + len(v)] = v
    os.makedirs(os.path.dirname(out), exist_ok=True)
    open(out, "wb").write(bytes(data))
    return out


def relink_check(source, mappings, flags=()):
    """Relink functions of an already-matched source at their original address; bytes must equal the image."""
    xb, img = load_original()
    image = image_from(xb, img)
    syms = GameSymbols()
    obj, _w = compile_source(source, flags)
    bad = 0
    for m in mappings:
        name, _, a = m.partition("=")
        addr = parse_addr(a)
        entry = obj.find_function(name)
        key = None
        size = syms.functions.get(addr, (None, None))[1]
        bump = [addr + 0x1000000]

        def alloc(sz, al, bump=bump):
            bump[0] = align_up(bump[0], al) + sz
            return bump[0] - sz
        sec = obj.sections[entry.section - 1]
        p = Placer(obj, syms, alloc)
        # force the entry unit onto the original address
        funcs = obj.functions_in(sec)
        starts = sorted({v for v, _n in funcs} | {0})
        start = max(v for v in starts if v <= entry.value)
        p.fixed[(entry.section, start)] = addr - (entry.value - start)
        p.place(entry)
        u = p.units[(entry.section, start)]
        code = u["data"]
        size = size or len(code)
        want = image.read(u["addr"], min(size, len(code)))
        # words that point at copied local data/helpers cannot equal the original (they live elsewhere)
        moved = set()
        for bd in p.bindings:
            if bd["unit"] == u["label"] and bd["address"] >= addr + 0x1000000 - 0x1000 and bd["kind"] != REL_PAIR:
                moved.add(bd["offset"] & ~3)
        ok = all(code[i:i + 4] == want[i:i + 4] for i in range(0, len(want), 4) if i not in moved)
        if not ok:
            bad += 1
            diff = [i for i in range(0, len(want), 4) if i not in moved and code[i:i + 4] != want[i:i + 4]]
            print("DIFF %s @%08X: %d word(s), first +0x%X: obj %s image %s" % (
                name, addr, len(diff), diff[0], code[diff[0]:diff[0] + 4].hex(), want[diff[0]:diff[0] + 4].hex()))
        else:
            print("OK   %s @%08X: %#x bytes identical (%d relocations resolved%s)" % (
                name, addr, len(want), len(p.bindings), ", %d words point at copied local data" % len(moved) if moved else ""))
    return bad


# ----------------------------------------------------------------------------- disassembly

def disasm(xex_or_image, addr, count=16, report=None):
    data = open(xex_or_image, "rb").read()
    if data[:4] == b"XEX2":
        img = xex_write.decode_image(data)
        base = xex_patch.Xex(data).load_address
    else:
        img, base = data, 0x88000000
    if not os.path.exists(PPCDIS):
        raise PatchError("ppcdis not built: cargo build --release --manifest-path tools/ppcdis/Cargo.toml "
                         "--target-dir work/ppcdis/target")
    o = addr - base
    code = img[o:o + 4 * count]
    out = subprocess.run([PPCDIS, "%x" % addr], input=code, capture_output=True, check=True).stdout.decode()
    syms = GameSymbols()
    names = {}
    if report and os.path.exists(report):
        r = json.load(open(report))
        for f in r.get("functions", []):
            names[parse_addr(f["new_code"])] = "NEW:" + f["function"]
            for b in f["blobs"]:
                names.setdefault(parse_addr(b["address"]), "NEW:" + f["function"] + ":" + b["what"])
        for h in r.get("hooks", []):
            names[parse_addr(h["entry"])] = "NEW:hook %s" % h["hook"]
            if "stub_code" in h:
                names[parse_addr(h["stub_code"])] = "NEW:stub " + h["function"]
    lines = []
    for ln in out.splitlines():
        m = re.search(r"-> 0x([0-9a-f]+)", ln)
        if m:
            t = int(m.group(1), 16)
            nm = names.get(t)
            if nm is None and FREE_LO <= t < FREE_HI:
                nm = "NEW code (free space)"
            nm = nm or syms.name_at(t)
            if nm:
                ln += "   <" + nm + ">"
        lines.append(ln)
    return lines


# ----------------------------------------------------------------------------- CLI

def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    b = sub.add_parser("build")
    b.add_argument("spec", nargs="*", help="one or more manifests, merged in order")
    b.add_argument("--identity", action="store_true", help="no changes (re-encode only)")
    b.add_argument("--out", required=True)
    b.add_argument("--xex", default=DEFAULT_XEX)
    b.add_argument("--compression", choices=["basic", "none"], default="basic")
    sd = sub.add_parser("setdata", help="change patch-data values of a built XEX")
    sd.add_argument("xex")
    sd.add_argument("--out", required=True)
    sd.add_argument("assign", nargs="+", help="name=01 | name=u32:1,2 | name[3]=f32:0.5")
    r = sub.add_parser("relink-check")
    r.add_argument("source")
    r.add_argument("mappings", nargs="+")
    r.add_argument("--flags", nargs="*", default=[])
    d = sub.add_parser("disasm")
    d.add_argument("file")
    d.add_argument("address")
    d.add_argument("count", nargs="?", type=int, default=16)
    d.add_argument("--report")
    a = ap.parse_args(argv)
    try:
        if a.cmd == "build":
            if a.identity == bool(a.spec):
                ap.error("give either manifest(s) or --identity")
            spec = [{}] if a.identity else [json.load(open(x)) for x in a.spec]
            rep = build(spec, a.out, a.xex, a.compression)
            print(json.dumps({k: rep[k] for k in ("free_space", "check", "output")}, indent=1))
            for h in rep["hooks"]:
                print("hook %s -> %s (%s)" % (h["hook"], h["entry"], h["kind"]))
            for f in rep["functions"]:
                print("%s: %s -> new code %s (%d bytes)" % (f["function"], f["address"], f["new_code"], f["new_code_size"]))
            print("wrote", os.path.realpath(a.out))
        elif a.cmd == "setdata":
            print("wrote", setdata(a.xex, a.out, a.assign))
        elif a.cmd == "relink-check":
            return 1 if relink_check(a.source, a.mappings, a.flags) else 0
        else:
            print("\n".join(disasm(a.file, parse_addr(a.address), a.count, a.report)))
    except PatchError as e:
        print("modpatch: " + str(e), file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
