#!/usr/bin/env python3
"""Diff the gameplay data of Top Spin 4 Title Update #1 against the retail disc (standard library only).

Inputs are local, never committed: the disc members (extracted ``<key>.bin`` folders, as for
dump_tunables.py), the disc ``Layoutall.bin``, the title update's ``TitleUpdate.arc`` and its own
``Layoutall.bin`` (from the STFS package, ``tools/stfs.py``), and optionally the function-level diff
written by ``tools/xex_patch.py --functions``.

Every XBin file is walked with its own layout (the disc file with the disc Layoutall.bin, the TU file
with the TU Layoutall.bin), so a member that only moved because a type grew is not reported as a
value change.  Analyser graphs (Expressions.bin) are compared node by node; graphs whose topology
changed are given as full formulas, with skill links resolved (``skill[Name]``).

Output (YAML, default data/gameplay/tu_diff.yaml): source hashes, TitleUpdate.arc inventory, layout
changes, scalar value changes per file, graph changes, and the code summary.

Usage:
  python3 tools/ts4data/tu_diff.py [--core work/disc/core_all] [--venue work/disc/venue_amst]
      [--layout work/disc/root/Layoutall.bin] [--tu-dir orig/54540859/tu1/files]
      [--inventory work/disc/inventory] [--functions work/tu1/swing_functions.json]
      [--out data/gameplay/tu_diff.yaml]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, HERE)
import ts4_xbin as X  # noqa: E402
import ts4_analyser as A  # noqa: E402
import ts4_arc  # noqa: E402

# (name, disc folder option, member key)
GAMEPLAY = [
    ("Settings.bin", "core", 0x334E7E0D),
    ("State.bin", "core", 0x623D0979),
    ("Module.bin", "core", 0x44DC9505),
    ("Expressions.bin", "core", 0xFA94F637),
    ("GameplayInterface.bin", "core", 0xF26CDC20),
    ("PlayerEvolution.bin", "venue", 0xE38F72F1),
]
# names recovered while reading the TU (crc32 verified); used only when the name tables lack them
EXTRA_NAMES = {0xF460CAE5: "IsSecondServe",       # ShotContext+112, written by fn_88695640 (TU) on serves
               0x8C2438F6: "AdvancedServe", 0xDE266211: "ServeFlatPowerful", 0x2D9D0B21: "ServeFlatMedium",
               0x06F187FA: "ServeFlatFinesse", 0xC44826EA: "ServeSpinPowerful", 0xB6A528DD: "ServeSpinMedium",
               0xB26101EE: "ServeSpinFinesse"}
EDITABLE = {"float", "int", "uint", "bool", "key", "u8", "s8", "u16", "s16", "u64", "word", "byte"}
SHOT_CLASS_RE = re.compile(r"/00236a48/(?:8c5e64b4|EvaluateList)\[(\d+)\]/(3f9c096b|2c3e6b9c|Element\[(\d+)\]<78db636d>/Name)$")
SHOT_CLASS_ID_RE = re.compile(r"/00236a48/(?:8c5e64b4|EvaluateList)\[(\d+)\]/Id$")


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def f32s(v):
    if isinstance(v, float):
        b = struct.pack(">f", v)
        for p in range(1, 10):
            t = "%.*g" % (p, v)
            if struct.pack(">f", float(t)) == b:
                return float(t)
    return v


def fmt(lf):
    v = lf.value
    if lf.tag == "float":
        return f32s(v)
    if lf.tag in ("key", "word"):
        return "0x%08x" % v
    if lf.tag == "bool":
        return bool(v)
    return v


# ------------------------------------------------------------------------------------------- XBin values

def walk(buf, layout, names):
    w = X.Walker(buf, layout, names)
    w.walk_file()
    return w


def value_diff(da, db, la, lb, names):
    wa, wb = walk(da, la, names), walk(db, lb, names)
    ma = {l.path: l for l in wa.leaves if l.tag in EDITABLE}
    mb = {l.path: l for l in wb.leaves if l.tag in EDITABLE}
    changed = []
    for p, l in ma.items():
        m = mb.get(p)
        if m is not None and m.value != l.value:
            changed.append(dict(path=p, type=l.tag, disc_offset="0x%x" % l.offset, tu_offset="0x%x" % m.offset,
                                disc=fmt(l), tu=fmt(m)))
    added = [dict(path=p, type=m.tag, tu_offset="0x%x" % m.offset, tu=fmt(m)) for p, m in mb.items() if p not in ma]
    removed = [dict(path=p, type=l.tag, disc_offset="0x%x" % l.offset, disc=fmt(l)) for p, l in ma.items()
               if p not in mb]
    return dict(disc_values=len(ma), tu_values=len(mb), changed=changed, added=added, removed=removed,
                signature=dict(disc="0x%08x" % struct.unpack_from(">I", da, 0)[0],
                               tu="0x%08x" % struct.unpack_from(">I", db, 0)[0])), wa, wb


def layout_diff(la, lb, names):
    n = lambda h: names.get(h) or "%08x" % h  # noqa: E731
    out = []
    for tc in sorted(set(la.types) | set(lb.types)):
        a, b = la.types.get(tc), lb.types.get(tc)
        if a is None or b is None:
            out.append(dict(type=n(tc), change="added" if a is None else "removed"))
            continue
        sa = {m.name: m for m in a[2]}
        sb = {m.name: m for m in b[2]}
        new = [dict(member=n(k), type=n(sb[k].type), offset=sb[k].offset) for k in sb if k not in sa]
        gone = [dict(member=n(k), type=n(sa[k].type), offset=sa[k].offset) for k in sa if k not in sb]
        moved = sum(1 for k in sa if k in sb and sa[k].offset != sb[k].offset)
        if new or gone or a[0] != b[0] or moved:
            out.append(dict(type=n(tc), size=[a[0], b[0]], new_members=new, removed_members=gone,
                            members_shifted=moved))
    return out


# ------------------------------------------------------------------------------------------- graphs

def skill_crcs():
    try:
        import career_data
        return career_data.SKILL_CRC, career_data.link_qualifiers
    except Exception:  # pragma: no cover - career_data is optional
        return {}, None


def graph_labels(expr, g, bind, namer, skills, link_q):
    labels = []
    for p in g.inputs:
        if p.index == -1 and link_q is not None:
            lv, q = link_q(expr, p)
            if q and q[0] in skills and zlib.crc32(b"SkillList") in lv:
                labels.append("skill[%s]" % skills[q[0]])
                continue
            labels.append("%s<link %s>" % (".".join(namer(x) for x in lv), "/".join(namer(x) for x in q)))
        else:
            labels.append(A.port_label(p, bind, namer))
    return labels


def graph_text(expr, g, bind, namer, skills, link_q):
    labels = graph_labels(expr, g, bind, namer, skills, link_q)
    lines, outs = A.graph_formula(g, labels)
    out_labels = [A.port_label(p, bind, namer) for p in g.outputs]
    f = ["%s = %s" % (t, v) for t, v in lines]
    f += ["%s = %s" % (out_labels[i] if i < len(out_labels) else "OUT %d" % i, v) for i, v in outs]
    curves = []
    k = 0
    for n in g.nodes:
        if n.kind == "CURVE":
            k += 1
            curves.append(("curve%d" % k, [[f32s(key[0]), f32s(key[1]), f32s(key[2]), f32s(key[4])]
                                           for key in n.fields["keys"]]))
    return f, curves, labels


def topo_sig(g):
    sig = []
    for n in g.nodes:
        f = n.fields
        if n.kind == "CURVE":
            sig.append(("CURVE", f["in"], f["out"], len(f["keys"])))
        elif n.kind == "CONST":
            sig.append(("CONST", f["out"]))
        else:
            sig.append((n.kind, tuple(n.reads()), tuple(n.writes())))
    return (tuple(sig), tuple((p.slot, p.index, tuple(p.path)) for p in g.inputs),
            tuple((p.slot, p.index, tuple(p.path)) for p in g.outputs))


def graph_values(g):
    vals = []
    for n in g.nodes:
        if n.kind == "CURVE":
            vals.append([tuple(f32s(x) for x in (k[0], k[1], k[2], k[4])) for k in n.fields["keys"]])
        elif n.kind == "CONST":
            vals.append(f32s(n.fields["value"]))
        else:
            vals.append(None)
    return vals


def shot_class_users(settings_walker, names):
    """graph hash -> ['ShotClassTable[i] <Id name>.<slot>']"""
    ids = {}
    for lf in settings_walker.leaves:
        m = SHOT_CLASS_ID_RE.search(lf.path)
        if m:
            ids[int(m.group(1))] = names.get(lf.value) or "#%08x" % lf.value
    users = {}
    for lf in settings_walker.leaves:
        m = SHOT_CLASS_RE.search(lf.path)
        if m and lf.tag == "key" and lf.value:
            i = int(m.group(1))
            slot = "Element[%s]" % m.group(3) if m.group(3) else ("#3f9c096b (aiming/efficiency)"
                                                                   if m.group(2) == "3f9c096b" else "#2c3e6b9c")
            users.setdefault(lf.value, []).append("Settings 40dd9ee9/00236a48/EvaluateList[%d] (shot class %s) %s" % (i, ids.get(i, "?"), slot))
    return users


def graph_diff(ea, eb, bind_a, bind_b, namer, users_a, users_b):
    skills, link_q = skill_crcs()
    ga, gb = A.parse_expressions(ea), A.parse_expressions(eb)
    out = []
    for i, (x, y) in enumerate(zip(ga, gb)):
        sx, sy = topo_sig(x), topo_sig(y)
        vx, vy = graph_values(x), graph_values(y)
        if x.name == y.name and sx == sy and vx == vy:
            continue
        row = dict(index=i, hash="0x%08x" % x.name, name=namer(x.name),
                   used_by_disc=users_a.get(x.name, []), used_by_tu=users_b.get(y.name, []),
                   referenced="yes" if (users_a.get(x.name) or users_b.get(y.name)) else
                   ("no (graph hash in tools/ts4_analyser.py UNREFERENCED_GRAPHS)"
                    if x.name in getattr(A, "UNREFERENCED_GRAPHS", ()) else "not by Settings.bin"))
        fx, cx, lx = graph_text(ea, x, bind_a, namer, skills, link_q)
        fy, cy, ly = graph_text(eb, y, bind_b, namer, skills, link_q)
        row["skills"] = sorted(set(re.findall(r"skill\[(\w+)\]", " ".join(lx + ly))))
        if sx == sy:
            row["topology"] = "unchanged"
            ch = []
            for (cid, kx), (_c, ky) in zip(cx, cy):
                if kx != ky:
                    line = next((ln for ln in fx if re.search(r"\b%s\(" % cid, ln)), "")
                    ch.append(dict(curve=cid, formula=line, disc_keys=kx, tu_keys=ky))
            for n, m in zip(x.nodes, y.nodes):
                if n.kind == "CONST" and f32s(n.fields["value"]) != f32s(m.fields["value"]):
                    ch.append(dict(const="r%d" % n.fields["out"], disc=f32s(n.fields["value"]),
                                   tu=f32s(m.fields["value"])))
            row["changes"] = ch
            row["formula"] = fx
        else:
            row["topology"] = "changed"
            row["disc_formula"] = fx
            row["tu_formula"] = fy
            row["disc_curves"] = {c: k for c, k in cx}
            row["tu_curves"] = {c: k for c, k in cy}
        out.append(row)
    return out


# ------------------------------------------------------------------------------------------- main

def inventory_names(inv_dir):
    names = {}
    if inv_dir and os.path.isdir(inv_dir):
        for fn in sorted(os.listdir(inv_dir)):
            if not fn.endswith(".tsv"):
                continue
            arc = fn[:-4]
            for ln in open(os.path.join(inv_dir, fn), encoding="utf-8", errors="replace"):
                f = ln.rstrip("\n").split("\t")
                if len(f) >= 6 and re.fullmatch(r"[0-9a-f]{8}", f[0]):
                    e = names.setdefault(int(f[0], 16), dict(name=f[5], archives=[],
                                                             usize=int(f[2]) if f[2].isdigit() else None))
                    e["archives"].append(arc)
    return names


def find_disc_member(key, dirs):
    for d in dirs:
        if not d:
            continue
        p = os.path.join(d, "%08x.bin" % key)
        if os.path.exists(p):
            return p
    return None


def to_yaml(v, ind=0):
    pad = "  " * ind

    def sc(x):
        if x is None:
            return "null"
        if isinstance(x, bool):
            return "true" if x else "false"
        if isinstance(x, (int, float)):
            return repr(x)
        s = str(x)
        if s == "" or re.search(r"[:#\[\]{},&*!|>'\"%@`]|^\s|\s$|^(true|false|null|yes|no|-?[0-9.]+)$", s):
            return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'
        return s

    def flow(x):
        if isinstance(x, dict):
            return "{" + ", ".join("%s: %s" % (sc(k), flow(y)) for k, y in x.items()) + "}"
        if isinstance(x, (list, tuple)):
            return "[" + ", ".join(flow(y) for y in x) + "]"
        return sc(x)

    def simple(x):
        if isinstance(x, (list, tuple)):
            return all(not isinstance(y, (dict,)) and simple(y) for y in x) and len(flow(x)) < 160
        if isinstance(x, dict):
            return False
        return True
    lines = []
    if isinstance(v, dict):
        for k, x in v.items():
            if simple(x) or (isinstance(x, (dict, list)) and not x):
                lines.append("%s%s: %s" % (pad, sc(k), flow(x)))
            elif isinstance(x, dict) and len(flow(x)) < 140 and all(simple(y) for y in x.values()):
                lines.append("%s%s: %s" % (pad, sc(k), flow(x)))
            else:
                lines.append("%s%s:" % (pad, sc(k)))
                lines.extend(to_yaml(x, ind + 1))
    elif isinstance(v, (list, tuple)):
        for x in v:
            if simple(x) or (isinstance(x, dict) and len(flow(x)) < 160 and all(simple(y) for y in x.values())):
                lines.append("%s- %s" % (pad, flow(x)))
            else:
                sub = to_yaml(x, ind + 1)
                lines.append("%s- %s" % (pad, sub[0].lstrip()))
                lines.extend(sub[1:])
    else:
        lines.append(pad + sc(v))
    return lines


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--core", default="work/disc/core_all", help="disc Core.arc members (<key>.bin)")
    ap.add_argument("--venue", default="work/disc/venue_amst", help="disc venue archive members (<key>.bin)")
    ap.add_argument("--extra", nargs="*", default=["work/disc/global"], help="more disc member folders")
    ap.add_argument("--layout", default="work/disc/root/Layoutall.bin", help="disc Layoutall.bin")
    ap.add_argument("--tu-dir", default="orig/54540859/tu1/files",
                    help="extracted TU package (TitleUpdate.arc, Layoutall.bin, CoreTech_Xenon.bin)")
    ap.add_argument("--names", default="work/disc/values/names.json")
    ap.add_argument("--name-table", default=os.path.join(ROOT, "data", "gameplay", "analyser_names.json"))
    ap.add_argument("--inventory", default="work/disc/inventory", help="disc archive inventories (*.tsv)")
    ap.add_argument("--functions", default=None, help="JSON from tools/xex_patch.py --functions")
    ap.add_argument("--out", default="data/gameplay/tu_diff.yaml")
    a = ap.parse_args(argv)

    lay_a_buf = open(a.layout, "rb").read()
    lay_b_buf = open(os.path.join(a.tu_dir, "Layoutall.bin"), "rb").read()
    la, lb = X.Layout(lay_a_buf), X.Layout(lay_b_buf)
    names = X.load_names(a.names) if a.names and os.path.exists(a.names) else dict(X.TYPE_NAMES)
    table = A.load_name_table(a.name_table) if a.name_table and os.path.exists(a.name_table) else {}
    for k, v in table.items():
        names.setdefault(k, v[0])
    for k, v in EXTRA_NAMES.items():
        names.setdefault(k, v)
        table.setdefault(k, (v, "high"))
    namer = A.Namer(table)
    tu_arc_path = os.path.join(a.tu_dir, "TitleUpdate.arc")
    arc = ts4_arc.Arc(tu_arc_path)
    tu_members = {h: arc.read((h, off, size)) for h, off, size in arc.entries}
    inv = inventory_names(a.inventory)
    dirs = [a.core, a.venue] + list(a.extra or [])

    sources = {"disc Layoutall.bin": sha256(lay_a_buf), "TU Layoutall.bin": sha256(lay_b_buf),
               "TU TitleUpdate.arc": sha256(open(tu_arc_path, "rb").read())}
    for fn in ("CoreTech_Xenon.bin", "Swing_DLL.xexp", "default.xexp", "Loader_DLL.xexp"):
        p = os.path.join(a.tu_dir, fn)
        if os.path.exists(p):
            sources["TU " + fn] = sha256(open(p, "rb").read())

    members = []
    for h in sorted(tu_members):
        b = tu_members[h]
        e = inv.get(h, {})
        dp = find_disc_member(h, dirs)
        row = dict(key="0x%08x" % h, name=e.get("name") or "?", disc_archives=e.get("archives", [])[:3] +
                   (["... %d more" % (len(e["archives"]) - 3)] if len(e.get("archives", [])) > 3 else []),
                   tu_size=len(b), tu_sha256=sha256(b))
        if dp:
            d = open(dp, "rb").read()
            row.update(disc_size=len(d), disc_sha256=sha256(d), status="identical" if d == b else "changed")
        else:
            if not e:
                row["status"] = "new in TU"
            else:
                row["disc_size_inventory"] = e.get("usize")
                row["status"] = "disc member not extracted (%s)" % (
                    "same size" if e.get("usize") == len(b) else "size differs")
        members.append(row)

    values, walkers = {}, {}
    for name, where, key in GAMEPLAY:
        dp = find_disc_member(key, [a.core] if where == "core" else [a.venue])
        if dp is None or key not in tu_members:
            continue
        da, db = open(dp, "rb").read(), tu_members[key]
        sources["disc %s (%08x)" % (name, key)] = sha256(da)
        sources["TU %s (%08x)" % (name, key)] = sha256(db)
        vd, wa, wb = value_diff(da, db, la, lb, names)
        walkers[name] = (wa, wb, da, db)
        if name != "Expressions.bin":      # graph values are reported per graph below
            values[name] = vd
        else:
            values[name] = dict(signature=vd["signature"], scalar_changes=len(vd["changed"]),
                                note="see graph_changes")

    graphs = []
    if "Expressions.bin" in walkers and "State.bin" in walkers and "Settings.bin" in walkers:
        ea, eb = walkers["Expressions.bin"][2], walkers["Expressions.bin"][3]
        bind_a = A.Bindings(walkers["State.bin"][2], lay_a_buf)
        bind_b = A.Bindings(walkers["State.bin"][3], lay_b_buf)
        ua = shot_class_users(walkers["Settings.bin"][0], names)
        ub = shot_class_users(walkers["Settings.bin"][1], names)
        graphs = graph_diff(ea, eb, bind_a, bind_b, namer, ua, ub)

    doc = {
        "title": "Top Spin 4 (Xbox 360) Title Update #1 vs retail disc: gameplay data and code diff",
        "sources_sha256": sources,
        "titleupdate_arc_members": members,
        "layout_changes": layout_diff(la, lb, names),
        "value_changes": values,
        "graph_changes": graphs,
    }
    if a.functions and os.path.exists(a.functions):
        fd = json.load(open(a.functions))
        doc["swing_dll_code"] = {k: fd[k] for k in ("base_sha256", "patch_sha256", "base_image_sha256",
                                                     "patched_image_sha256", "base_functions",
                                                     "patched_functions", "identical", "moved") if k in fd}
        doc["swing_dll_code"].update(offsets_only=len(fd.get("offsets_only", [])), changed=fd.get("changed", []),
                                     added=fd.get("added", []), removed=fd.get("removed", []))
    cmd = "python3 tools/ts4data/tu_diff.py " + " ".join(argv if argv is not None else sys.argv[1:])
    head = ["# Top Spin 4 Title Update #1 vs retail disc (gameplay).  Readable values only; no game files.",
            "# generated by: %s" % cmd.strip(),
            "# tools: tools/ts4data/tu_diff.py, tools/ts4_xbin.py walker, tools/ts4_analyser.py; Python %s"
            % sys.version.split()[0],
            "# graph curve keys are [x0, x1, y0, y1] runtime ramps (slope fixup fn_88179740)",
            "# see docs/gameplay/title-update-balance.md for the reading of each change"]
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as o:
        o.write("\n".join(head + to_yaml(doc)) + "\n")
    print("wrote %s: %d members, %d graph changes" % (a.out, len(members), len(graphs)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
