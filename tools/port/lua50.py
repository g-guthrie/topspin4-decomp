#!/usr/bin/env python3
"""Reader, disassembler and table evaluator for the game's Lua 5.0.2 (LuaPlus) bytecode.

The UI files of Top Spin 4 (``*.scene``, ``*.sceneData``, ``*.package``, ``*Lib.bin``,
``PackageHierarchy.lua``, ``UnlockTrigger.bin``) are precompiled chunks.  The format is the
Lua 5.0 ``ldump.c`` format with the LuaPlus changes confirmed in ``Swing_DLL.xex``:

* header ``1B 'Lua' 50``, endianness byte (0 = big endian on disc), sizes int/size_t/Instruction
  = 4/4/4, field widths OP/A/B/C = 6/8/9/9, sizeof(lua_Number) = 8, then the test number
  (``lua2_lundump.c`` / ``d4b_lua_undump_88810048.c``);
* prototype order: source, linedefined, nups, numparams, is_vararg, maxstacksize, lineinfo,
  locvars, upvalues, constants (+ nested prototypes), code (``lua2_LoadFunction_88810F00``);
* constant tags 0 nil, 3 number, 4 string, 9 wide string (UTF-16 units, LuaPlus;
  ``lua2_LoadWString_888107F0``, constant switch of ``fn_88810948``);
* 39 opcodes; LuaPlus inserted integer bit operators after DIV, so the numbering differs from
  stock 5.0 from opcode 16 on (``luaV_execute`` = ``fn_8880D5E0`` jump table at 0x8880D748):
  14 MUL, 15 DIV, 16 BAND, 17 BOR, 18 SHL, 19 SHR, 20 BXOR (falls back to the POW tag method),
  21 UNM ... 38 CLOSURE (``lua2_lparser.h``).

Instruction layout: op bits 0-5, C bits 6-14, B bits 15-23, A bits 24-31, Bx bits 6-31,
sBx = Bx - 131071, RK(x) is constant ``x - 250`` when ``x >= 250``.

Commands (standard library only):

  python3 tools/port/lua50.py dis FILE          # listing with constants resolved
  python3 tools/port/lua50.py eval FILE         # JSON of the globals the main chunk builds
  python3 tools/port/lua50.py strings FILE      # every string constant
  python3 tools/port/lua50.py lua FILE          # pseudo-Lua of every function (gotos for control flow)
"""
from __future__ import annotations

import json
import struct
import sys

SIGNATURE = b"\x1bLua"
VERSION = 0x50
MAXSTACK = 250
BIAS_SBX = (1 << 17) - 1

OPNAMES = [
    "MOVE", "LOADK", "LOADBOOL", "LOADNIL", "GETUPVAL", "GETGLOBAL", "GETTABLE", "SETGLOBAL",
    "SETUPVAL", "SETTABLE", "NEWTABLE", "SELF", "ADD", "SUB", "MUL", "DIV", "BAND", "BOR", "SHL",
    "SHR", "BXOR", "UNM", "NOT", "CONCAT", "JMP", "EQ", "LT", "LE", "TEST", "CALL", "TAILCALL",
    "RETURN", "FORLOOP", "TFORLOOP", "TFORPREP", "SETLIST", "SETLISTO", "CLOSE", "CLOSURE",
]
OP = {n: i for i, n in enumerate(OPNAMES)}
# operand formats: ABC, ABx, AsBx
FMT_ABX = {OP["LOADK"], OP["GETGLOBAL"], OP["SETGLOBAL"], OP["CLOSURE"]}
FMT_ASBX = {OP["JMP"], OP["FORLOOP"], OP["TFORPREP"]}
ARITH = {OP["ADD"]: "+", OP["SUB"]: "-", OP["MUL"]: "*", OP["DIV"]: "/", OP["BAND"]: "&",
         OP["BOR"]: "|", OP["SHL"]: "<<", OP["SHR"]: ">>", OP["BXOR"]: "^"}
FIELDS_PER_FLUSH = 32  # LFIELDS_PER_FLUSH of Lua 5.0


class LuaFormatError(ValueError):
    pass


class WStr(str):
    """A LuaPlus wide string constant (kept distinct from byte strings)."""


class Proto:
    __slots__ = ("source", "linedefined", "nups", "numparams", "is_vararg", "maxstack",
                 "lineinfo", "locvars", "upvalues", "k", "p", "code")

    def to_dict(self):
        return {
            "source": self.source, "linedefined": self.linedefined, "nups": self.nups,
            "numparams": self.numparams, "is_vararg": self.is_vararg, "maxstack": self.maxstack,
            "constants": [k if not isinstance(k, float) or k != k else None for k in self.k],
            "code": len(self.code), "protos": [p.to_dict() for p in self.p],
        }


class Reader:
    def __init__(self, data: bytes):
        self.d = data
        self.o = 0
        self.e = ">"

    def need(self, n):
        if self.o + n > len(self.d):
            raise LuaFormatError("truncated chunk at 0x%X" % self.o)

    def byte(self):
        self.need(1)
        v = self.d[self.o]
        self.o += 1
        return v

    def int(self):
        self.need(4)
        v = struct.unpack_from(self.e + "i", self.d, self.o)[0]
        self.o += 4
        if v < 0:
            raise LuaFormatError("negative size at 0x%X" % (self.o - 4))
        return v

    def u32s(self, n):
        self.need(4 * n)
        v = struct.unpack_from(self.e + "%dI" % n, self.d, self.o)
        self.o += 4 * n
        return list(v)

    def number(self):
        self.need(8)
        v = struct.unpack_from(self.e + "d", self.d, self.o)[0]
        self.o += 8
        return v

    def string(self):
        n = self.int()
        if n == 0:
            return None
        self.need(n)
        s = self.d[self.o:self.o + n - 1]
        self.o += n
        return s.decode("latin-1")

    def wstring(self):
        n = self.int()
        if n == 0:
            return None
        self.need(2 * n)
        raw = self.d[self.o:self.o + 2 * (n - 1)]
        self.o += 2 * n
        return WStr(raw.decode("utf-16-be" if self.e == ">" else "utf-16-le", "replace"))


def read_header(r: Reader):
    if r.d[:4] != SIGNATURE:
        raise LuaFormatError("not a Lua chunk")
    r.o = 4
    if r.byte() != VERSION:
        raise LuaFormatError("not Lua 5.0 bytecode")
    endian = r.byte()
    r.e = "<" if endian == 1 else ">"
    sizes = [r.byte() for _ in range(8)]
    if sizes != [4, 4, 4, 6, 8, 9, 9, 8]:
        raise LuaFormatError("unexpected size header %r" % sizes)
    tn = r.number()
    if abs(tn - 3.14159265358979323846e7) > 1e-3:
        raise LuaFormatError("bad test number %r" % tn)


def read_function(r: Reader, parent_source=None, depth=0) -> Proto:
    if depth > 200:
        raise LuaFormatError("prototype nesting too deep")
    f = Proto()
    f.source = r.string() or parent_source
    f.linedefined = r.int()
    f.nups, f.numparams, f.is_vararg, f.maxstack = (r.byte() for _ in range(4))
    f.lineinfo = r.u32s(r.int())
    f.locvars = []
    for _ in range(r.int()):
        name = r.string()
        f.locvars.append((name, r.int(), r.int()))
    f.upvalues = [r.string() for _ in range(r.int())]
    f.k = []
    for _ in range(r.int()):
        t = r.byte()
        if t == 0:
            f.k.append(None)
        elif t == 3:
            f.k.append(r.number())
        elif t == 4:
            f.k.append(r.string() or "")
        elif t == 9:
            f.k.append(r.wstring() or WStr(""))
        else:
            raise LuaFormatError("bad constant type %d at 0x%X" % (t, r.o - 1))
    f.p = [read_function(r, f.source, depth + 1) for _ in range(r.int())]
    f.code = r.u32s(r.int())
    return f


def load(data: bytes) -> Proto:
    r = Reader(data)
    read_header(r)
    return read_function(r)


def is_lua(data: bytes) -> bool:
    return data[:5] == SIGNATURE + bytes([VERSION])


def decode(i):
    op = i & 0x3F
    a = (i >> 24) & 0xFF
    b = (i >> 15) & 0x1FF
    c = (i >> 6) & 0x1FF
    bx = (i >> 6) & 0x3FFFF
    return op, a, b, c, bx


def fmt_k(v):
    if isinstance(v, WStr):
        return "L" + json.dumps(str(v), ensure_ascii=False)
    if isinstance(v, str):
        return json.dumps(v, ensure_ascii=False)
    if isinstance(v, float) and v == int(v) and abs(v) < 1e15:
        return str(int(v))
    return repr(v)


def disassemble(f: Proto, out=None, indent="", path="main"):
    out = [] if out is None else out
    out.append("%sfunction %s <%s:%d> params=%d vararg=%d ups=%d stack=%d k=%d code=%d" % (
        indent, path, f.source, f.linedefined, f.numparams, f.is_vararg, f.nups, f.maxstack,
        len(f.k), len(f.code)))

    def rk(x):
        return "K(%s)" % fmt_k(f.k[x - MAXSTACK]) if x >= MAXSTACK and x - MAXSTACK < len(f.k) else "R%d" % x

    for pc, ins in enumerate(f.code):
        op, a, b, c, bx = decode(ins)
        name = OPNAMES[op] if op < len(OPNAMES) else "OP%d" % op
        line = f.lineinfo[pc] if pc < len(f.lineinfo) else 0
        if op in FMT_ABX:
            args = "%d %d" % (a, bx)
        elif op in FMT_ASBX:
            args = "%d %d" % (a, bx - BIAS_SBX)
        else:
            args = "%d %d %d" % (a, b, c)
        note = ""
        if op in (OP["LOADK"], OP["GETGLOBAL"], OP["SETGLOBAL"]) and bx < len(f.k):
            note = fmt_k(f.k[bx])
        elif op in (OP["GETTABLE"], OP["SELF"]):
            note = rk(c)
        elif op == OP["SETTABLE"]:
            note = "%s = %s" % (rk(b), rk(c))
        elif op in ARITH or op in (OP["EQ"], OP["LT"], OP["LE"]):
            note = "%s %s" % (rk(b), rk(c))
        elif op in FMT_ASBX:
            note = "-> %d" % (pc + 1 + bx - BIAS_SBX)
        out.append("%s  %4d [%4d] %-9s %-12s %s" % (indent, pc, line, name, args, note))
    for i, p in enumerate(f.p):
        disassemble(p, out, indent + "  ", "%s.%d" % (path, i))
    return out


def all_strings(f: Proto):
    for k in f.k:
        if isinstance(k, str):
            yield k
    for p in f.p:
        yield from all_strings(p)


# ---------------------------------------------------------------- symbolic table evaluator

class LuaTable:
    __slots__ = ("hash", "array", "name")

    def __init__(self, name=None):
        self.hash = {}
        self.array = []
        self.name = name  # set for environment tables created on first use (e.g. "Scenes")

    def set(self, k, v):
        if isinstance(k, float) and k == int(k) and 1 <= k <= len(self.array) + 1:
            k = int(k)
            if k == len(self.array) + 1:
                self.array.append(v)
            else:
                self.array[k - 1] = v
            return
        self.hash[_key(k)] = v

    def get(self, k):
        if isinstance(k, float) and k == int(k) and 1 <= k <= len(self.array):
            return self.array[int(k) - 1]
        return self.hash.get(_key(k))


def _key(k):
    if isinstance(k, float) and k == int(k):
        return int(k)
    if isinstance(k, (str, int, bool)) or k is None:
        return k
    return repr(k)


class Ref:
    """An unknown value: a global, a field of an unknown value, or a call result."""
    __slots__ = ("expr",)

    def __init__(self, expr):
        self.expr = expr

    def __repr__(self):
        return self.expr


class Closure:
    __slots__ = ("proto", "path")

    def __init__(self, proto, path):
        self.proto = proto
        self.path = path


def to_json(v, depth=0):
    if depth > 64:
        return "<deep>"
    if isinstance(v, LuaTable):
        if not v.hash:
            return [to_json(x, depth + 1) for x in v.array]
        d = {}
        for i, x in enumerate(v.array):
            d[str(i + 1)] = to_json(x, depth + 1)
        for k, x in v.hash.items():
            d[str(k) if not isinstance(k, str) else k] = to_json(x, depth + 1)
        return d
    if isinstance(v, float):
        if v != v or v in (float("inf"), float("-inf")):
            return str(v)
        return int(v) if v == int(v) and abs(v) < 1e15 else v
    if isinstance(v, Ref):
        return {"$ref": v.expr}
    if isinstance(v, Closure):
        return {"$function": v.path, "line": v.proto.linedefined}
    if isinstance(v, WStr):
        return str(v)
    return v


def evaluate(f: Proto, max_steps=2_000_000, env=None, args=(), vivify=False, writes=None):
    """Run the main chunk symbolically (straight-line code, tables, closures as values).

    Calls are not executed: their result is a Ref naming the call, and the call itself is
    recorded in ``calls`` (callee expression and evaluated arguments).  Conditional jumps are
    followed on the fall-through path only; loops are cut after ``max_steps`` instructions.
    Returns ``(globals, calls)``.

    ``env`` pre-seeds the globals (e.g. ``currentScene``), ``args`` the parameters.  With ``vivify``
    a missing field of a named table becomes a new named table (so ``a.b.c = v`` is kept), and every
    store into a named table is appended to ``writes`` as ``(path, value)``.  ``tostring``,
    ``towstring``, ``table.insert`` and ``table.getn`` are evaluated when their arguments are known.
    """
    g = env if env is not None else {}
    calls = []
    R = [None] * (f.maxstack + 8)
    for i, v in enumerate(args[:f.numparams]):
        R[i] = v
    pc = 0
    steps = 0
    code = f.code
    K = f.k

    def rk(x):
        return K[x - MAXSTACK] if x >= MAXSTACK else R[x]

    def name(v):
        if isinstance(v, LuaTable) and v.name:
            return v.name
        if isinstance(v, Ref):
            return v.expr
        if isinstance(v, str):
            return v
        if isinstance(v, float):
            return fmt_k(v)
        return type(v).__name__

    seen_back = set()
    while pc < len(code) and steps < max_steps:
        steps += 1
        op, a, b, c, bx = decode(code[pc])
        pc += 1
        if op == OP["MOVE"]:
            R[a] = R[b]
        elif op == OP["LOADK"]:
            R[a] = K[bx]
        elif op == OP["LOADBOOL"]:
            R[a] = bool(b)
            if c:
                pc += 1
        elif op == OP["LOADNIL"]:
            for i in range(a, b + 1):
                R[i] = None
        elif op == OP["GETUPVAL"]:
            R[a] = Ref("upval%d" % b)
        elif op == OP["GETGLOBAL"]:
            k = K[bx]
            if k not in g:
                g[k] = LuaTable(str(k))  # unknown global: an environment table, filled on use
            R[a] = g[k]
        elif op == OP["GETTABLE"]:
            t, k = R[b], rk(c)
            if isinstance(t, LuaTable):
                v = t.get(k)
                if v is None and t.name is not None:
                    if vivify:
                        v = LuaTable("%s.%s" % (t.name, name(k)) if isinstance(k, str) else "%s[%s]" % (t.name, name(k)))
                        t.set(k, v)
                    else:
                        v = Ref("%s.%s" % (t.name, name(k)))
                R[a] = v
            else:
                R[a] = Ref("%s[%s]" % (name(t), name(k)) if not isinstance(k, str)
                           else "%s.%s" % (name(t), k))
        elif op == OP["SETGLOBAL"]:
            g[K[bx]] = R[a]
        elif op == OP["SETUPVAL"]:
            pass
        elif op == OP["SETTABLE"]:
            t = R[a]
            if isinstance(t, LuaTable):
                t.set(rk(b), rk(c))
                if writes is not None and t.name:
                    writes.append(("%s.%s" % (t.name, name(rk(b))), rk(c)))
        elif op == OP["NEWTABLE"]:
            R[a] = LuaTable()
        elif op == OP["SELF"]:
            t = R[b]
            R[a + 1] = t
            k = rk(c)
            v = t.get(k) if isinstance(t, LuaTable) else None
            R[a] = v if v is not None else Ref("%s:%s" % (name(t), name(k)))
        elif op in ARITH:
            x, y = rk(b), rk(c)
            if isinstance(x, float) and isinstance(y, float):
                try:
                    if op == OP["ADD"]:
                        R[a] = x + y
                    elif op == OP["SUB"]:
                        R[a] = x - y
                    elif op == OP["MUL"]:
                        R[a] = x * y
                    elif op == OP["DIV"]:
                        R[a] = x / y if y else float("nan")
                    else:
                        xi, yi = int(x) & 0xFFFFFFFF, int(y) & 0xFFFFFFFF
                        r = {OP["BAND"]: xi & yi, OP["BOR"]: xi | yi, OP["SHL"]: (xi << (yi & 31)) & 0xFFFFFFFF,
                             OP["SHR"]: xi >> (yi & 31), OP["BXOR"]: xi ^ yi}[op]
                        R[a] = float(r)
                except (OverflowError, ValueError):
                    R[a] = Ref("(%s %s %s)" % (name(x), ARITH[op], name(y)))
            else:
                R[a] = Ref("(%s %s %s)" % (name(x), ARITH[op], name(y)))
        elif op == OP["UNM"]:
            R[a] = -R[b] if isinstance(R[b], float) else Ref("-%s" % name(R[b]))
        elif op == OP["NOT"]:
            R[a] = Ref("not %s" % name(R[b]))
        elif op == OP["CONCAT"]:
            parts = R[b:c + 1]
            if all(isinstance(p, (str, float)) for p in parts):
                R[a] = "".join(p if isinstance(p, str) else fmt_k(p) for p in parts)
            else:
                R[a] = Ref("..".join(name(p) for p in parts))
        elif op == OP["JMP"]:
            tgt = pc + bx - BIAS_SBX
            if tgt <= pc - 1:
                if (pc, tgt) in seen_back:
                    continue
                seen_back.add((pc, tgt))
            pc = tgt
        elif op in (OP["EQ"], OP["LT"], OP["LE"], OP["TEST"]):
            pc += 1  # take the fall-through (no branch)
            if op == OP["TEST"]:
                R[a] = R[b]
        elif op in (OP["CALL"], OP["TAILCALL"]):
            fn = R[a]
            nargs = (b - 1) if b else 0
            args = R[a + 1:a + 1 + nargs]
            fname = name(fn) if not isinstance(fn, Closure) else fn.path
            calls.append({"fn": fname, "args": [to_json(x) for x in args], "pc": pc - 1})
            res = Ref("%s(...)" % fname)
            if fname in ("tostring", "towstring") and args and isinstance(args[0], (str, float)):
                res = args[0] if isinstance(args[0], str) else fmt_k(args[0])
                if fname == "towstring":
                    res = WStr(res)
            elif fname == "table.insert" and len(args) == 2 and isinstance(args[0], LuaTable):
                args[0].array.append(args[1])
                if writes is not None and args[0].name:
                    writes.append(("%s[+]" % args[0].name, args[1]))
            elif fname == "table.getn" and args and isinstance(args[0], LuaTable):
                res = float(len(args[0].array))
            if c != 1:
                R[a] = res
            if op == OP["TAILCALL"]:
                break
        elif op == OP["RETURN"]:
            break
        elif op in (OP["FORLOOP"], OP["TFORLOOP"], OP["TFORPREP"]):
            if op == OP["TFORPREP"]:
                pc += bx - BIAS_SBX
            elif op == OP["TFORLOOP"]:
                pc += 1
        elif op in (OP["SETLIST"], OP["SETLISTO"]):
            t = R[a]
            n = bx % FIELDS_PER_FLUSH + 1
            base = bx - bx % FIELDS_PER_FLUSH
            if isinstance(t, LuaTable):
                for j in range(1, n + 1):
                    t.set(float(base + j), R[a + j])
        elif op == OP["CLOSE"]:
            pass
        elif op == OP["CLOSURE"]:
            R[a] = Closure(f.p[bx], "main.%d" % bx)
            pc += f.p[bx].nups  # skip the upvalue pseudo-instructions
        else:
            raise LuaFormatError("unknown opcode %d" % op)
    return g, calls


# ---------------------------------------------------------------- pseudo-Lua listing

def _lit(v):
    if v is None:
        return "nil"
    if isinstance(v, bool):
        return "true" if v else "false"
    return fmt_k(v)


def decompile(f: Proto, name="function", indent=""):
    """Readable pseudo-Lua for one prototype (expression folding, gotos for control flow).

    Not a full decompiler: conditional jumps become ``if <cond> then goto Lnn end`` and loops stay as
    labels, but calls, table constructors, field accesses and constants are reconstructed, which is
    what is needed to read the UI scripts (which C functions they call and with which arguments)."""
    targets = set()
    for pc, ins in enumerate(f.code):
        op, a, b, c, bx = decode(ins)
        if op in FMT_ASBX:
            targets.add(pc + 1 + bx - BIAS_SBX)
        elif op in (OP["EQ"], OP["LT"], OP["LE"], OP["TEST"]):
            targets.add(pc + 2)
        elif op == OP["LOADBOOL"] and c:
            targets.add(pc + 2)
    params = []
    for i in range(f.numparams):
        params.append(f.locvars[i][0] if i < len(f.locvars) and f.locvars[i][0] else "a%d" % i)
    out = ["%s%s(%s)" % (indent, name, ", ".join(params + (["..."] if f.is_vararg else [])))]
    R = {i: params[i] for i in range(len(params))}
    ind = indent + "  "

    def reg(i):
        return R.get(i, "r%d" % i)

    def rk(x):
        return _lit(f.k[x - MAXSTACK]) if x >= MAXSTACK and x - MAXSTACK < len(f.k) else reg(x)

    def key(t, k):
        if isinstance(k, str) and k.startswith('"') and k[1:-1].replace("_", "a").isalnum() and not k[1].isdigit():
            return "%s.%s" % (t, k[1:-1])
        return "%s[%s]" % (t, k)

    def emit(s):
        out.append(ind + s)

    tables = {}
    pc = 0
    n = len(f.code)
    while pc < n:
        if pc in targets:
            emit("::L%d::" % pc)
            R = {i: params[i] for i in range(len(params))}
            tables = {}
        op, a, b, c, bx = decode(f.code[pc])
        o = OPNAMES[op] if op < len(OPNAMES) else "OP%d" % op
        if op not in (OP["SETTABLE"], OP["SETGLOBAL"], OP["SETUPVAL"], OP["JMP"], OP["EQ"], OP["LT"],
                      OP["LE"], OP["RETURN"], OP["SETLIST"], OP["SETLISTO"], OP["CLOSE"], OP["NEWTABLE"]):
            tables.pop(a, None)          # register overwritten: no longer a table under construction
            if op == OP["SELF"]:
                tables.pop(a + 1, None)
        if op == OP["MOVE"] and b in tables:
            tables[a] = tables[b]
        if op == OP["MOVE"]:
            R[a] = reg(b)
        elif op == OP["LOADK"]:
            R[a] = _lit(f.k[bx])
        elif op == OP["LOADBOOL"]:
            R[a] = "true" if b else "false"
            if c:
                emit("r%d = %s; goto L%d" % (a, R[a], pc + 2))
        elif op == OP["LOADNIL"]:
            for i in range(a, b + 1):
                R[i] = "nil"
        elif op == OP["GETUPVAL"]:
            R[a] = f.upvalues[b] if b < len(f.upvalues) and f.upvalues[b] else "upval%d" % b
        elif op == OP["GETGLOBAL"]:
            R[a] = str(f.k[bx])
        elif op == OP["GETTABLE"]:
            R[a] = key(reg(b), rk(c))
        elif op == OP["SETGLOBAL"]:
            emit("%s = %s" % (f.k[bx], reg(a)))
        elif op == OP["SETUPVAL"]:
            emit("%s = %s" % (f.upvalues[b] if b < len(f.upvalues) and f.upvalues[b] else "upval%d" % b, reg(a)))
        elif op == OP["SETTABLE"]:
            if a in tables:
                tables[a].append("%s = %s" % (rk(b)[1:-1] if rk(b).startswith('"') else "[%s]" % rk(b), rk(c)))
                R[a] = "{" + ", ".join(tables[a]) + "}"
            else:
                emit("%s = %s" % (key(reg(a), rk(b)), rk(c)))
        elif op == OP["NEWTABLE"]:
            R[a] = "{}"
            tables[a] = []
        elif op == OP["SELF"]:
            obj = reg(b)
            R[a + 1] = obj
            m = rk(c)
            R[a] = "%s:%s" % (obj, m[1:-1] if m.startswith('"') else m)
            R[("self", a)] = True
        elif op in ARITH:
            R[a] = "(%s %s %s)" % (rk(b), ARITH[op], rk(c))
        elif op == OP["UNM"]:
            R[a] = "-%s" % reg(b)
        elif op == OP["NOT"]:
            R[a] = "not %s" % reg(b)
        elif op == OP["CONCAT"]:
            R[a] = " .. ".join(reg(i) for i in range(b, c + 1))
        elif op == OP["JMP"]:
            emit("goto L%d" % (pc + 1 + bx - BIAS_SBX))
        elif op in (OP["EQ"], OP["LT"], OP["LE"]):
            sym = {OP["EQ"]: ("==", "~="), OP["LT"]: ("<", ">="), OP["LE"]: ("<=", ">")}[op]
            emit("if %s %s %s then goto L%d end" % (rk(b), sym[1] if a else sym[0], rk(c), pc + 2))
        elif op == OP["TEST"]:
            emit("if %s%s then goto L%d end" % ("" if c else "not ", reg(b), pc + 2))
            R[a] = reg(b)
        elif op in (OP["CALL"], OP["TAILCALL"]):
            fn = reg(a)
            is_self = R.pop(("self", a), False)
            nargs = (b - 1) if b else None
            if nargs is None:
                args = [reg(i) for i in range(a + 1, a + 4) if i in R] + ["..."]
            else:
                args = [reg(i) for i in range(a + 1, a + 1 + nargs)]
            if is_self and args:
                args = args[1:]
            call = "%s(%s)" % (fn, ", ".join(args))
            if op == OP["TAILCALL"]:
                emit("return " + call)
            elif c == 1:
                emit(call)
            else:
                R[a] = call
                if c == 0 or c > 2:
                    for i in range(a + 1, a + (c - 1 if c else 2)):
                        R[i] = "%s[%d]" % (call, i - a + 1)
        elif op == OP["RETURN"]:
            vals = [reg(i) for i in range(a, a + b - 1)] if b else [reg(a) + ", ..."]
            if pc != n - 1 or vals:
                emit("return" + (" " + ", ".join(vals) if vals else ""))
        elif op == OP["FORLOOP"]:
            emit("for r%d += r%d while <= r%d: goto L%d" % (a, a + 2, a + 1, pc + 1 + bx - BIAS_SBX))
        elif op == OP["TFORPREP"]:
            emit("tforprep r%d; goto L%d" % (a, pc + 1 + bx - BIAS_SBX))
        elif op == OP["TFORLOOP"]:
            emit("r%d.. = r%d(r%d, r%d); if r%d == nil then goto L%d end" % (a + 2, a, a + 1, a + 2, a + 2, pc + 2))
        elif op in (OP["SETLIST"], OP["SETLISTO"]):
            cnt = bx % FIELDS_PER_FLUSH + 1
            items = [reg(a + j) for j in range(1, cnt + 1)]
            if a in tables:
                tables[a].extend(items)
                R[a] = "{" + ", ".join(tables[a]) + "}"
        elif op == OP["CLOSE"]:
            pass
        elif op == OP["CLOSURE"]:
            sub = f.p[bx]
            R[a] = "<closure %d>" % bx
            out.extend(decompile(sub, "local function r%d_%d" % (a, bx), ind)[0:])
            pc += sub.nups
        else:
            emit("-- %s %d %d %d" % (o, a, b, c))
        pc += 1
    out.append(indent + "end")
    return out


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["dis", "eval", "strings", "info", "lua"])
    ap.add_argument("file")
    a = ap.parse_args(argv)
    data = open(a.file, "rb").read()
    f = load(data)
    if a.cmd == "dis":
        print("\n".join(disassemble(f)))
    elif a.cmd == "strings":
        for s in all_strings(f):
            print(fmt_k(s))
    elif a.cmd == "lua":
        print("\n".join(decompile(f, "function main")))
    elif a.cmd == "info":
        print(json.dumps(f.to_dict(), indent=1, ensure_ascii=False))
    else:
        g, calls = evaluate(f)
        print(json.dumps({"globals": {k: to_json(v) for k, v in g.items()}, "calls": calls},
                         indent=1, ensure_ascii=False))


if __name__ == "__main__":
    main()
