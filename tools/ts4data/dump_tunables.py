#!/usr/bin/env python3
"""Dump every gameplay tunable of Top Spin 4 (Xbox 360) to editable YAML files (standard library only).

Every scalar member of the gameplay XBin files is found by the generic typed walker
(``tools/ts4_xbin.py`` Layout/Walker, driven by the disc's own ``Layoutall.bin``) and written as one
line, keyed by its byte offset in the decompressed file:

    - {off: 0x00000158, type: float, value: 80.0, path: "<9b4fb082>/3f7bd49d/..."}  # note

``off`` and ``type`` are what ``patch_tunables.py`` uses; ``path`` (member names, ``[i]`` list
indexes, ``<type>`` for polymorphic children; unknown names are 8 hex digits) is checked against a
fresh walk before anything is written.  Edit ``value`` only.  Types: float (IEEE single; NaN/inf
written as ``f32bits`` hex), int/uint/s8/u8/s16/u16/u64, bool (true/false), key (crc32 hash, hex;
the trailing comment names it when known), word/byte (member of unknown primitive type).  Strings,
XBin paths and relative pointers are not listed: changing them changes the file size.

Output: one YAML per source file in OUT (default ``data/gameplay/tunables``) plus ``index.yaml``.
Each file header records the generating command, the source archive/key and the sha256 and size
of the decompressed source file and of Layoutall.bin.

Usage:
  python3 tools/ts4data/dump_tunables.py --iso IMAGE.iso [--out data/gameplay/tunables]
         [--names work/disc/values/names.json] [--xref work/disc/values/xref_settings.json]
         [--cache work/disc/core_all] [--only Settings.bin,State.bin]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import math
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402

# (output name, archive on the disc, member key, note).  Venue archives carry identical copies of
# the venue gameplay files (same key, size and uncompressed size in every venue archive, see
# docs/gameplay/tunables-catalog.md s1); Amsterdam.arc is used as the representative.
SOURCES = [
    ("Settings.bin", "Core.arc", 0x334E7E0D, "shot selection tree, shot templates, gameplay settings root"),
    ("State.bin", "Core.arc", 0x623D0979, "initial gameplay state image (player/ball/match state defaults)"),
    ("Module.bin", "Core.arc", 0x44DC9505, "gameplay module descriptor (match/player/ball limits)"),
    ("Expressions.bin", "Core.arc", 0xFA94F637, "analyser graphs (see analyser-graphs.md)"),
    ("GameplayInterface.bin", "Core.arc", 0xF26CDC20, "gameplay interface (inputs/outputs) defaults"),
    ("PlayerSetup.bin", "Core.arc", 0x798A36DD, "player setup (skeleton/scale setup per body)"),
    ("MenSetup.bin", "Core.arc", 0xF9532D93, "men player setup"),
    ("WomenSetup.bin", "Core.arc", 0x989D8828, "women player setup"),
    ("PlayerAnimData.bin", "Core.arc", 0x9914D191, "per-player animation data"),
    ("InGameModule.bin", "Amsterdam.arc", 0x62C2690A, "in-game module set (venue copy)"),
    ("MatchSimulation.bin", "Amsterdam.arc", 0xFE620B2D, "simulated-match tables (venue copy)"),
    ("PlayerEvolution.bin", "Amsterdam.arc", 0xE38F72F1, "player evolution tables (venue copy)"),
]

EDITABLE = {"float", "int", "uint", "bool", "key", "u8", "s8", "u16", "s16", "u64", "word", "byte"}


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def fmt_value(lf):
    v = lf.value
    if lf.tag == "float":
        if not math.isfinite(v):
            return "f32bits", "0x%08x" % struct.unpack(">I", struct.pack(">f", v))[0]
        return "float", f32_repr(v)
    if lf.tag == "bool":
        return "bool", "true" if v else ("false" if v == 0 else str(v))
    if lf.tag in ("key", "word"):
        return lf.tag, "0x%08x" % v
    return lf.tag, str(v)


def f32_repr(v):
    """Shortest decimal that reads back to the same IEEE single."""
    bits = struct.pack(">f", v)
    for p in range(6, 10):
        t = "%.*g" % (p, v)
        if struct.pack(">f", float(t)) == bits:
            if "e" not in t and "." not in t and "n" not in t:
                t += ".0"
            return t
    return repr(float(v))


def esc(s):
    return s.replace("\\", "\\\\").replace('"', '\\"')


class Source:
    def __init__(self, iso=None, cache=None):
        self.iso, self.cache, self.arcs = iso, cache, {}

    def get(self, arc_name, key):
        if self.cache:
            cands = [os.path.join(self.cache, arc_name, "%08x.bin" % key)]
            if arc_name == "Core.arc":
                cands.append(os.path.join(self.cache, "%08x.bin" % key))
            for p in cands:
                if os.path.exists(p):
                    return open(p, "rb").read()
        if not self.iso:
            raise SystemExit("member %s:%08x not cached and no --iso given" % (arc_name, key))
        import ts4_arc
        if arc_name not in self.arcs:
            self.arcs[arc_name] = ts4_arc.open_arc(arc_name, self.iso)
        arc = self.arcs[arc_name]
        return arc.read(arc.find(key))


def load_xref(path):
    if not path or not os.path.exists(path):
        return {}
    d = json.load(open(path))
    ok = sorted((int(h["addr"], 16), h["off"]) for h in d["hits"] if h["consistent"])
    addrs = [a for a, _o in ok]
    out = {}
    for i, (a, off) in enumerate(ok):
        # confidence M: another consistent read within 0x100 bytes (same routine, same root)
        near = (i > 0 and a - addrs[i - 1] <= 0x100) or (i + 1 < len(addrs) and addrs[i + 1] - a <= 0x100)
        if near:
            out.setdefault(off, []).append("%08X" % a)
    return out


def dump_one(name, arc_name, key, note, data, layout, names, xref, cmd, layout_sha, out_dir):
    w = X.Walker(data, layout, names)
    leaves = w.walk_file()
    root = X.parse_header(data)
    lines = []
    lines.append("# %s - %s" % (name, note))
    lines.append("# generated by: %s" % cmd)
    lines.append("# source: %s member 0x%08x, decompressed %d bytes, sha256 %s" % (arc_name, key, len(data), sha256(data)))
    lines.append("# layout: Layoutall.bin sha256 %s" % layout_sha)
    lines.append("# Edit 'value' only.  patch_tunables.py checks off/type/path against the source file.")
    lines.append("file: %s" % name)
    lines.append("archive: %s" % arc_name)
    lines.append("key: 0x%08x" % key)
    lines.append("size: %d" % len(data))
    lines.append("sha256: %s" % sha256(data))
    lines.append("root_type: 0x%08x" % root["root_type"])
    lines.append("values:")
    n = 0
    settings_base = 0x24 if name == "Settings.bin" else None
    for lf in sorted(leaves, key=lambda l: l.offset):
        if lf.tag not in EDITABLE:
            continue
        t, v = fmt_value(lf)
        comment = []
        if lf.tag == "key" and lf.value in names:
            comment.append(names[lf.value])
        if settings_base is not None and lf.offset - settings_base in xref:
            comment.append("code? " + ",".join(a for a in sorted(set(xref[lf.offset - settings_base]))[:4]))
        line = '  - {off: 0x%08x, type: %s, value: %s, path: "%s"}' % (lf.offset, t, v, esc(lf.path))
        if comment:
            line += "  # " + "; ".join(comment)
        lines.append(line)
        n += 1
    base = os.path.splitext(name)[0]
    with open(os.path.join(out_dir, base + ".yaml"), "w") as o:
        o.write("\n".join(lines) + "\n")
    return dict(file=name, yaml=base + ".yaml", archive=arc_name, key="0x%08x" % key, size=len(data),
                sha256=sha256(data), values=n, objects=len(w.objects),
                unknown_types=sorted("%08x" % u for u in w.unknown_types))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    ap.add_argument("--cache", help="directory with already extracted members (<key>.bin or <Archive>/<key>.bin)")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin",
                    help="Layoutall.bin (read from the ISO root when the file does not exist)")
    ap.add_argument("--names", default="work/disc/values/names.json")
    ap.add_argument("--xref", default="work/disc/values/xref_settings.json")
    ap.add_argument("--out", default="data/gameplay/tunables")
    ap.add_argument("--only", default="")
    a = ap.parse_args(argv)
    cmd = "python3 tools/ts4data/dump_tunables.py " + " ".join(
        x if not x.endswith(".iso") else "<disc image>" for x in (argv if argv is not None else sys.argv[1:]))
    if os.path.exists(a.layout):
        lay_buf = open(a.layout, "rb").read()
    else:
        import xdvdfs
        lay_buf = xdvdfs.XDVDFS(a.iso).open_slice("Layoutall.bin").read()
    layout = X.Layout(lay_buf)
    names = X.load_names(a.names) if a.names and os.path.exists(a.names) else dict(X.TYPE_NAMES)
    xref = load_xref(a.xref)
    os.makedirs(a.out, exist_ok=True)
    src = Source(a.iso, a.cache)
    only = {s for s in a.only.split(",") if s}
    index = []
    for name, arc_name, key, note in SOURCES:
        if only and name not in only:
            continue
        data = src.get(arc_name, key)
        info = dump_one(name, arc_name, key, note, data, layout, names, xref, cmd, sha256(lay_buf), a.out)
        index.append(info)
        print("%-22s %7d values  %s" % (name, info["values"], info["sha256"][:16]), flush=True)
    with open(os.path.join(a.out, "index.yaml"), "w") as o:
        o.write("# Top Spin 4 gameplay tunables index\n# generated by: %s\n" % cmd)
        o.write("# layout: Layoutall.bin %d bytes sha256 %s\nfiles:\n" % (len(lay_buf), sha256(lay_buf)))
        for i in index:
            o.write("  - {file: %s, yaml: %s, archive: %s, key: %s, size: %d, sha256: %s, values: %d, objects: %d}\n" % (
                i["file"], i["yaml"], i["archive"], i["key"], i["size"], i["sha256"], i["values"], i["objects"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
