#!/usr/bin/env python3
"""Dump every gameplay tunable of Top Spin 4 (Xbox 360) to editable YAML files (standard library only).

Every scalar member of the gameplay XBin files is found by the generic typed walker
(``tools/ts4_xbin.py`` Layout/Walker, driven by the disc's own ``Layoutall.bin``) and written as one
line, keyed by its byte offset in the decompressed file:

    - [0x158, float, 80.0, "/50cbc34f/6abf473a"]  # note

i.e. [file offset, type, value, path].  The path is relative to the part's ``section`` header (the
root object's top-level member).  Offset and type are what ``patch_tunables.py`` uses; the path
(member names, ``[i]`` list
indexes, ``<type>`` for polymorphic children; unknown names are 8 hex digits) is checked against a
fresh walk before anything is written.  Edit ``value`` only.  Types: float (IEEE single; NaN/inf
written as ``f32bits`` hex), int/uint/s8/u8/s16/u16/u64, bool (true/false), key (crc32 hash, hex;
the trailing comment names it when known), word/byte (member of unknown primitive type).  Strings,
XBin paths and relative pointers are not listed: changing them changes the file size.

Output: OUT/<File>/NN_<section>[.partK].yaml (default OUT ``data/gameplay/tunables``), one file per
top-level member of the root object, split into parts below 4 MiB, plus OUT/index.yaml.
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
import re
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


PART_LIMIT = 4 * 1024 * 1024      # bytes per YAML part (tools/check_no_game_data.py allows 5 MiB)
SECTION_RE = re.compile(r"^(<[^>]*>/)?([^/\[]*)")


def split_path(path):
    """'<root>/Member[3]/x' -> ('<root>/Member', '[3]/x'): the section is the root object's
    top-level member, the rest is written relative to it."""
    m = SECTION_RE.match(path)
    prefix = m.group(0)
    rel = path[len(prefix):]
    if not rel or re.fullmatch(r"(\[\d+\])+", rel):
        # a scalar (or fixed array) directly on the root object: keep all of those in one section
        head, sep, last = prefix.rpartition("/")
        return head, sep + last + rel
    return prefix, rel


def safe(s):
    return re.sub(r"[^A-Za-z0-9_.-]+", "_", s).strip("_")[:60] or "root"


def dump_one(name, arc_name, key, note, data, layout, names, xref, cmd, layout_sha, out_dir):
    w = X.Walker(data, layout, names)
    leaves = w.walk_file()
    root = X.parse_header(data)
    base = os.path.splitext(name)[0]
    fdir = os.path.join(out_dir, base)
    if os.path.isdir(fdir):
        for old in os.listdir(fdir):
            if old.endswith(".yaml"):
                os.remove(os.path.join(fdir, old))
    old_single = os.path.join(out_dir, base + ".yaml")
    if os.path.exists(old_single):
        os.remove(old_single)
    os.makedirs(fdir, exist_ok=True)
    settings_base = 0x24 if name == "Settings.bin" else None
    sections = {}                     # prefix -> [lines], insertion order = first offset
    for lf in sorted(leaves, key=lambda l: l.offset):
        if lf.tag not in EDITABLE:
            continue
        t, v = fmt_value(lf)
        comment = []
        if lf.tag == "key" and lf.value in names:
            comment.append(names[lf.value])
        if settings_base is not None and lf.offset - settings_base in xref:
            comment.append("code? " + ",".join(sorted(set(xref[lf.offset - settings_base]))[:4]))
        prefix, rel = split_path(lf.path)
        line = '  - [0x%x, %s, %s, "%s"]' % (lf.offset, t, v, esc(rel))
        if comment:
            line += "  # " + "; ".join(comment)
        sections.setdefault(prefix, []).append(line)
    parts_info = []
    n_total = 0
    for si, (prefix, lines) in enumerate(sections.items()):
        chunks, cur, size = [], [], 0
        for ln in lines:
            if cur and size + len(ln) + 1 > PART_LIMIT:
                chunks.append(cur)
                cur, size = [], 0
            cur.append(ln)
            size += len(ln) + 1
        chunks.append(cur)
        sname = names.get(int(prefix[-8:], 16)) if re.search(r"/[0-9a-f]{8}$", prefix) else None
        label = "root" if not prefix or (prefix.startswith("<") and "/" not in prefix) else safe(prefix.split("/")[-1])
        for ci, chunk in enumerate(chunks):
            fn = "%02d_%s%s.yaml" % (si, label, ".part%d" % (ci + 1) if len(chunks) > 1 else "")
            head = [
                "# %s - %s" % (name, note),
                "# generated by: %s" % cmd,
                "# source: %s member 0x%08x, decompressed %d bytes, sha256 %s" % (arc_name, key, len(data), sha256(data)),
                "# layout: Layoutall.bin sha256 %s" % layout_sha,
                "# rows: [file offset, type, value, path relative to 'section'].  Edit the value only;",
                "# tools/ts4data/patch_tunables.py checks offset, type and path against the source file.",
                "file: %s" % name,
                "archive: %s" % arc_name,
                "key: 0x%08x" % key,
                "size: %d" % len(data),
                "sha256: %s" % sha256(data),
                "root_type: 0x%08x" % root["root_type"],
                'section: "%s"' % esc(prefix) + ("  # " + sname if sname else ""),
                "part: %d of %d" % (ci + 1, len(chunks)),
                "values:",
            ]
            with open(os.path.join(fdir, fn), "w") as o:
                o.write("\n".join(head + chunk) + "\n")
            parts_info.append(dict(yaml="%s/%s" % (base, fn), section=prefix, values=len(chunk)))
            n_total += len(chunk)
    return dict(file=name, archive=arc_name, key="0x%08x" % key, size=len(data), sha256=sha256(data),
                values=n_total, objects=len(w.objects), parts=parts_info,
                unknown_types=sorted("%08x" % u for u in w.unknown_types))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    ap.add_argument("--cache", help="directory with already extracted members (<key>.bin or <Archive>/<key>.bin)")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin",
                    help="Layoutall.bin (read from the ISO root when the file does not exist)")
    ap.add_argument("--names", nargs="*", default=["data/gameplay/names.yaml", "work/disc/values/names.json"],
                    help="name dictionaries (names.yaml and/or names.json); missing files are skipped")
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
    names = X.load_names(*[p for p in a.names if os.path.exists(p)])
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
            o.write("  - file: %s\n    archive: %s\n    key: %s\n    size: %d\n    sha256: %s\n    values: %d\n"
                    "    objects: %d\n    parts:\n" % (i["file"], i["archive"], i["key"], i["size"], i["sha256"],
                                                       i["values"], i["objects"]))
            for p in i["parts"]:
                o.write('      - {yaml: %s, section: "%s", values: %d}\n' % (p["yaml"], esc(p["section"]), p["values"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
