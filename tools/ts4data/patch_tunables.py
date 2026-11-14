#!/usr/bin/env python3
"""Apply edited tunables YAML (from dump_tunables.py) back to the game's data files (stdlib only).

For every YAML given, the original decompressed member is read (``--cache`` directory or
``--iso``), its sha256 is compared with the YAML header, and the file is walked again with the
same Layoutall.bin.  Each value line whose ``value`` differs from the original is checked:

  * a scalar leaf of the same type must exist at ``off`` in the fresh walk, with the same
    ``path`` (``--no-path-check`` skips only the path comparison);
  * the new value must fit the type (int ranges, bool true/false/0/1, key/word hex or decimal,
    float any decimal or ``f32bits`` hex).

Values are written in place (big-endian, same size; no offset moves).  The patched file is then
re-walked: every changed value must read back, every unchanged leaf must still read as before,
and the byte diff must touch only the edited fields.  Patched members are written to
OUT/<file>.  With ``--rebuild`` each touched archive is rebuilt into OUT/<Archive> with
``tools/ts4_arc_write.py`` (raw members, see docs/data-patching.md) and verified; build a playable
folder afterwards with ``tools/ts4_iso_patch.py IMAGE.iso work/patched/game --arc
Core.arc=OUT/Core.arc``.  Lines you did not edit can stay in the YAML or be deleted.

Usage:
  python3 tools/ts4data/patch_tunables.py data/gameplay/tunables/Settings/*.yaml [more.yaml ...]
         (--iso IMAGE.iso | --cache work/disc/cache) --out work/patched [--rebuild] [--dry-run]
"""
from __future__ import annotations

import argparse
import hashlib
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402
from dump_tunables import EDITABLE, Source  # noqa: E402

LINE = re.compile(r'^\s*-\s*\[\s*(0x[0-9A-Fa-f]+|\d+)\s*,\s*(\w+)\s*,\s*([^,\]]+?)\s*,\s*'
                  r'"((?:[^"\\]|\\.)*)"\s*\]\s*(?:#.*)?$')
HEAD = re.compile(r'^(file|archive|key|size|sha256|root_type|section|part):\s*("(?:[^"\\]|\\.)*"|[^#]*?)\s*(?:#.*)?$')
RANGES = {"int": (">i", -2 ** 31, 2 ** 31 - 1), "uint": (">I", 0, 2 ** 32 - 1), "u8": (">B", 0, 255),
          "s8": (">b", -128, 127), "u16": (">H", 0, 65535), "s16": (">h", -32768, 32767),
          "u64": (">Q", 0, 2 ** 64 - 1), "key": (">I", 0, 2 ** 32 - 1), "word": (">I", 0, 2 ** 32 - 1),
          "byte": (">B", 0, 255), "bool": (">B", 0, 255)}


class PatchError(Exception):
    pass


def unesc(s):
    return re.sub(r"\\(.)", r"\1", s)


def parse_yaml(text):
    """-> (header dict, [(lineno, off, type, value text, path)])"""
    head, rows = {}, []
    for no, line in enumerate(text.splitlines(), 1):
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        m = LINE.match(line)
        if m:
            rows.append((no, int(m.group(1), 0), m.group(2), m.group(3).strip(), m.group(4)))
            continue
        h = HEAD.match(line)
        if h:
            v = h.group(2)
            head[h.group(1)] = unesc(v[1:-1]) if v.startswith('"') else v
        elif line.strip() != "values:":
            raise PatchError("line %d: cannot parse: %s" % (no, line[:120]))
    for k in ("file", "archive", "key"):
        if k not in head:
            raise PatchError("YAML header lacks '%s'" % k)
    prefix = head.get("section", "")
    rows = [(no, off, typ, val, prefix + unesc(rel)) for no, off, typ, val, rel in rows]
    return head, rows


def encode(typ, text, no):
    """Value text -> packed big-endian bytes for the given YAML type."""
    t = text.strip().strip("'\"")
    if typ in ("float", "f32bits"):
        if typ == "f32bits" or t.lower().startswith("0x"):
            return struct.pack(">I", int(t, 16) & 0xFFFFFFFF)
        try:
            v = float(t)
        except ValueError:
            raise PatchError("line %d: %r is not a number" % (no, text))
        try:
            return struct.pack(">f", v)
        except OverflowError:
            raise PatchError("line %d: %r does not fit a 32-bit float" % (no, text))
    if typ not in RANGES:
        raise PatchError("line %d: type %s is not editable" % (no, typ))
    code, lo, hi = RANGES[typ]
    if typ == "bool" and t.lower() in ("true", "false"):
        v = 1 if t.lower() == "true" else 0
    else:
        try:
            v = int(t, 0)
        except ValueError:
            raise PatchError("line %d: %r is not an integer" % (no, text))
    if not lo <= v <= hi:
        raise PatchError("line %d: %d out of range for %s" % (no, v, typ))
    return struct.pack(code, v)


def leaf_type(lf):
    return "float" if lf.tag == "float" else lf.tag


def apply(data, layout, rows, path_check=True):
    """Apply YAML rows to data.  Returns (patched bytes, [(off, path, old bytes, new bytes)])."""
    w = X.Walker(data, layout)
    leaves = {lf.offset: lf for lf in w.walk_file() if lf.tag in EDITABLE}
    out = bytearray(data)
    changes = []
    for no, off, typ, text, path in rows:
        lf = leaves.get(off)
        if lf is None:
            raise PatchError("line %d: no editable value at 0x%x in the source file" % (no, off))
        want = "float" if typ == "f32bits" else typ
        if leaf_type(lf) != want:
            raise PatchError("line %d: type %s does not match the file (%s at 0x%x)" % (no, typ, lf.tag, off))
        if path_check and _strip_names(lf.path) != _strip_names(path):
            raise PatchError("line %d: path mismatch at 0x%x: file has %s" % (no, off, lf.path))
        new = encode(typ, text, no)
        size = struct.calcsize(lf.code)
        old = bytes(data[off:off + size])
        if len(new) != size:
            raise PatchError("line %d: encoded size %d != field size %d" % (no, len(new), size))
        if new != old:
            out[off:off + size] = new
            changes.append((off, lf.path, old, new))
    return bytes(out), changes


def _strip_names(path):
    """Compare paths by structure: names may be resolved differently between dumps, so every
    path component is reduced to its crc32 (8 hex digits stay as they are)."""
    parts = re.split(r"(/|<|>|\[\d+\])", path)
    out = []
    for p in parts:
        if not p or p in "/<>" or p.startswith("["):
            out.append(p)
        elif re.fullmatch(r"[0-9a-f]{8}", p):
            out.append(p)
        else:
            out.append("%08x" % X.crc(p))
    return "".join(out)


def verify(orig, patched, layout, changes):
    """Re-walk the patched image: edited values read back, all other leaves unchanged, and
    the byte diff is limited to the edited fields."""
    a = {lf.offset: lf for lf in X.Walker(orig, layout).walk_file()}
    b = {lf.offset: lf for lf in X.Walker(patched, layout).walk_file()}
    if sorted(a) != sorted(b):
        raise PatchError("structure changed after patching")
    edited = {off: new for off, _p, _o, new in changes}
    allowed = set()
    for off, new in edited.items():
        allowed.update(range(off, off + len(new)))
        lf = b[off]
        if patched[off:off + len(new)] != new:
            raise PatchError("value at 0x%x did not read back" % off)
        if lf.path != a[off].path:
            raise PatchError("path at 0x%x changed" % off)
    diff = [i for i in range(len(orig)) if orig[i] != patched[i]]
    bad = [i for i in diff if i not in allowed]
    if bad or len(orig) != len(patched):
        raise PatchError("unexpected byte changes at %s" % ", ".join("0x%x" % i for i in bad[:8]))
    return len(diff)


def fmt(lf_code_bytes, typ):
    if typ == "float":
        return repr(struct.unpack(">f", lf_code_bytes)[0])
    return "0x" + lf_code_bytes.hex()


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("yaml", nargs="+")
    ap.add_argument("--iso")
    ap.add_argument("--cache")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin")
    ap.add_argument("--out", default="work/patched")
    ap.add_argument("--rebuild", action="store_true", help="also rebuild every touched archive (needs --iso)")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--force", action="store_true", help="accept a source whose sha256 differs from the YAML")
    ap.add_argument("--no-path-check", action="store_true")
    a = ap.parse_args(argv)
    if os.path.exists(a.layout):
        lay_buf = open(a.layout, "rb").read()
    elif a.iso:
        import xdvdfs
        lay_buf = xdvdfs.XDVDFS(a.iso).open_slice("Layoutall.bin").read()
    else:
        raise SystemExit("Layoutall.bin not found; pass --layout or --iso")
    layout = X.Layout(lay_buf)
    src = Source(a.iso, a.cache)
    per_arc = {}
    total = 0
    groups = {}
    for y in a.yaml:
        with open(y) as f:
            head, rows = parse_yaml(f.read())
        g = groups.setdefault((head["archive"], head["key"].lower()), [dict(head), [], []])
        if g[0].get("sha256") != head.get("sha256"):
            raise SystemExit("%s: sha256 differs from another part of %s" % (y, head["file"]))
        g[1].extend(rows)
        g[2].append(y)
    for (_arc, _k), (head, rows, files) in groups.items():
        y = ",".join(files)
        key = int(head["key"], 16)
        data = src.get(head["archive"], key)
        sha = hashlib.sha256(data).hexdigest()
        if head.get("sha256") and head["sha256"] != sha and not a.force:
            raise SystemExit("%s: source sha256 %s differs from the YAML header %s (use --force)"
                             % (head["file"], sha, head["sha256"]))
        try:
            patched, changes = apply(data, layout, rows, not a.no_path_check)
            n = verify(data, patched, layout, changes)
        except PatchError as e:
            raise SystemExit("%s: %s" % (y, e))
        for off, path, old, new in changes:
            typ = "float" if len(old) == 4 and any(r[1] == off and r[2] in ("float", "f32bits") for r in rows) else "raw"
            print("%s 0x%08x %s: %s -> %s" % (head["file"], off, path, fmt(old, typ), fmt(new, typ)))
        print("%s: %d value(s) changed, %d byte(s)" % (head["file"], len(changes), n))
        total += len(changes)
        if changes and not a.dry_run:
            os.makedirs(a.out, exist_ok=True)
            p = os.path.join(a.out, head["file"])
            with open(p, "wb") as o:
                o.write(patched)
            print("wrote %s sha256 %s" % (p, hashlib.sha256(patched).hexdigest()))
            per_arc.setdefault(head["archive"], {})[key] = patched
    if a.rebuild and per_arc and not a.dry_run:
        if not a.iso:
            raise SystemExit("--rebuild needs --iso")
        import ts4_arc
        import ts4_arc_write
        for arc_name, repl in per_arc.items():
            arc = ts4_arc.open_arc(arc_name, a.iso)
            outp = os.path.join(a.out, arc_name)
            with open(outp, "wb") as o:
                st = ts4_arc_write.rebuild(arc, repl, o, "raw")
            new = ts4_arc.Arc(outp)
            for k, v in repl.items():
                if new.read(new.find(k)) != v:
                    raise SystemExit("%s: member %08x does not read back" % (arc_name, k))
            print("rebuilt %s (%d bytes, replaced %s); next: python3 tools/ts4_iso_patch.py <iso> "
                  "work/patched/game --arc %s=%s" % (outp, st["out_size"], ",".join("%08x" % k for k in repl),
                                                     arc_name, outp))
    if total == 0:
        print("no changes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
