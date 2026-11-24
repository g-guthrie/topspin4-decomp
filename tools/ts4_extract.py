#!/usr/bin/env python3
"""Extract locally readable JSON from the Top Spin 4 disc image (never commit the output).

  python3 tools/ts4_extract.py --iso "orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso" \
      --out work/disc/gameplay [--census] [--dll orig/54540859/Swing_DLL.dll]

Writes:
  crc_dictionaries.json   every CRC dictionary found in Core.arc ({crc hex: string})
  layout_pairs.json       Layoutall.bin root-type table (layout id, root type crc, name if known)
  animation_db.json       swing AnimationDB (type Pam::SwingAnimation::AnimationDB::AnimationDB):
                          header, root field table, array locations/counts/strides and the rows
                          of every flat fixed-stride array as raw words (hex, float, name)
  xbin_census.json        (--census) root-type census of all XBin entries in all archives
"""
import argparse
import collections
import json
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ts4_arc  # noqa: E402
import ts4_xbin  # noqa: E402
import xdvdfs  # noqa: E402

ANIMDB_TYPE = ts4_xbin.crc("Pam::SwingAnimation::AnimationDB::AnimationDB")
ANIMDB_PARAMS = ts4_xbin.crc("Pam::SwingAnimation::AnimationDB::Parameters")
DICT_TYPE_SECOND = 0x5E7AF2A3  # second signature word of CRC dictionary files seen on disc


def dll_strings(path):
    data = open(path, "rb").read()
    return {ts4_xbin.crc(m.group()): m.group().decode("latin-1")
            for m in re.finditer(rb"[\x20-\x7e]{3,}", data)}


def core_entries(core):
    """Yield (entry, first bytes) for every Core.arc entry."""
    for e in core.entries:
        try:
            yield e, ts4_arc.peek_blob(core.raw(e) if e[2] < 200000 else _head(core, e), 32)
        except Exception:
            continue


def _head(arc, e):
    arc.f.seek(arc.data_start + e[1])
    return arc.f.read(200000)


def flat_rows(buf, abs_, count, stride, names):
    rows = []
    for i in range(count):
        p = abs_ + i * stride
        words = struct.unpack_from(">%dI" % (stride // 4), buf, p)
        row = []
        for w in words:
            f = struct.unpack(">f", struct.pack(">I", w))[0]
            cell = {"u32": w}
            if 1e-6 < abs(f) < 1e7:
                cell["f32"] = round(f, 6)
            if w in names:
                cell["name"] = names[w]
            row.append(cell)
        rows.append(row)
    return rows


def decode_takes(buf, take_field, names):
    """TakeList = array of 0x8C-byte records (layout from docs/gameplay/df.md 3.2, confirmed on disc):
    +0x0C u16 slot, +0x14 f32 (length-like), +0x18 f32 1.0, +0x1C f32 epsilon, +0x5C {rel,type 0xA0B2A282},
    +0x64 annotations {rel,count,cap} stride 0x10 {name crc, f32 time, u32, u32},
    +0x70 segments {rel,count,cap} stride 0x28, +0x84 u32 id = crc32 of the animation name."""
    base = take_field["abs"]
    out = []
    for i in range(take_field["count"]):
        r = base + 0x8C * i
        f = lambda o: struct.unpack_from(">f", buf, r + o)[0]
        u = lambda o: struct.unpack_from(">I", buf, r + o)[0]
        rec = {"index": i, "id": "%08x" % u(0x84), "name": names.get(u(0x84)),
               "slot": struct.unpack_from(">H", buf, r + 0x0C)[0], "f14": f(0x14), "f18": f(0x18), "f1c": f(0x1C),
               "poly_type": "%08x" % u(0x60), "annotations": [], "segments": []}
        rel, n, _c = struct.unpack_from(">III", buf, r + 0x64)
        for j in range(n):
            a = r + 0x64 + rel + 0x10 * j
            nh, t, w2, w3 = struct.unpack_from(">IfII", buf, a)
            rec["annotations"].append({"name": names.get(nh, "%08x" % nh), "time": t, "w2": w2, "w3": w3})
        rel, n, _c = struct.unpack_from(">III", buf, r + 0x70)
        for j in range(n):
            a = r + 0x70 + rel + 0x28 * j
            w = struct.unpack_from(">10I", buf, a)
            rec["segments"].append({"words": ["%08x" % x for x in w], "f10": struct.unpack_from(">f", buf, a + 0x10)[0],
                                    "f14": struct.unpack_from(">f", buf, a + 0x14)[0]})
        out.append(rec)
    return out


SHOT_KINDS = (0x5D90675B, 0x2DB3EB6F, 0x50B89452, 0xC1965E5C)
T_CONST, T_CURVE20, T_TABLE = 0x33799CCE, 0xF9F12A60, 0x7A330099


def _curve16(buf, hdr):
    rel, n = struct.unpack_from(">ii", buf, hdr)
    return [list(struct.unpack_from(">4f", buf, hdr + rel + 16 * i)) for i in range(n)]


def decode_value_pointer(buf, a):
    """{s32 rel, u32 type} at address a (docs/gameplay/df.md 4.3) -> decoded value or None."""
    rel, t = struct.unpack_from(">iI", buf, a)
    tgt = a + rel
    if not 0 <= tgt < len(buf) - 8:
        return None
    if t == T_CONST:
        return {"type": "const", "value": struct.unpack_from(">f", buf, tgt)[0]}
    if t == T_CURVE20:
        r, n = struct.unpack_from(">ii", buf, tgt)
        if not 0 <= n < 4096:
            return None
        return {"type": "curve20", "keys": [list(struct.unpack_from(">4f", buf, tgt + r + 20 * i))
                                            + [struct.unpack_from(">I", buf, tgt + r + 20 * i + 16)[0]] for i in range(n)]}
    if t == T_TABLE:
        r, n = struct.unpack_from(">ii", buf, tgt)
        if not 0 <= n < 4096:
            return None
        rows = []
        for i in range(n):
            ra = tgt + r + 16 * i
            rows.append({"key": struct.unpack_from(">f", buf, ra + 12)[0], "curve16": _curve16(buf, ra)})
        return {"type": "table2d", "rows": rows}
    return None


def decode_template_file(buf):
    """Scan an XBin for the polymorphic value pointers and shot-kind hashes."""
    words = struct.unpack(">%dI" % (len(buf) // 4), buf[:len(buf) // 4 * 4])
    pointers, kinds = [], collections.defaultdict(list)
    for i, w in enumerate(words):
        a = 4 * i
        if w in (T_CONST, T_CURVE20, T_TABLE) and i > 0:
            try:
                v = decode_value_pointer(buf, a - 4)
            except struct.error:
                v = None
            if v:
                pointers.append({"addr": a - 4, "value": v})
        elif w in SHOT_KINDS:
            kinds["%08x" % w].append(a)
    rows = []
    for k, offs in kinds.items():
        for o in offs:
            near = [p["addr"] for p in pointers if o - 0x20 <= p["addr"] < o + 0x80]
            rows.append({"kind": k, "addr": o, "words": ["%08x" % x for x in words[(o - 0x20) // 4:(o + 0x70) // 4]],
                         "pointers_near": near})
    rows.sort(key=lambda r: r["addr"])
    return {"size": len(buf), "kind_counts": {k: len(v) for k, v in kinds.items()}, "rows": rows, "pointers": pointers}


def decode_animation_db(buf, layout, names):
    hdr = ts4_xbin.parse_header(buf)
    fields = ts4_xbin.describe_root(buf, layout, ANIMDB_PARAMS, names)
    arrays = sorted((f for f in fields if "abs" in f), key=lambda f: f["abs"])
    # stride = distance to the next array start / count, when it divides exactly
    ends = [f["abs"] for f in arrays[1:]] + [len(buf)]
    for f, nxt in zip(arrays, ends):
        span = nxt - f["abs"]
        f["span_to_next"] = span
        stride = span // f["count"] if f["count"] else 0
        # flat arrays tile the span exactly, or leave less than 16 bytes of padding
        f["stride"] = stride if 2 <= stride <= 64 and 0 <= span - stride * f["count"] < 16 else None
    out = {"header": {k: "%08x" % v for k, v in hdr.items()}, "size": len(buf), "fields": fields, "arrays": {}}
    for f in fields:
        if "abs" in f and f["stride"] == 2:
            out["arrays"][f["name"]] = list(struct.unpack_from(">%dH" % f["count"], buf, f["abs"]))
        elif "abs" in f and f["stride"] and f["stride"] % 4 == 0:
            out["arrays"][f["name"]] = flat_rows(buf, f["abs"], f["count"], f["stride"], names)
    tl = next((f for f in fields if f["name"] == "TakeList"), None)
    if tl:
        out["takes"] = decode_takes(buf, tl, names)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", required=True)
    ap.add_argument("--out", default="work/disc/gameplay")
    ap.add_argument("--dll", help="Swing_DLL.dll (read only) to resolve class-name CRCs")
    ap.add_argument("--census", action="store_true", help="scan every archive for XBin root types (slow)")
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    x = xdvdfs.XDVDFS(a.iso)
    off, size = x.open_file("Layoutall.bin")
    x.f.seek(off)
    layout = x.f.read(size)
    core = ts4_arc.Arc(x.open_slice("Core.arc"))

    names = {}
    dicts = {}
    animdb = None
    for e in core.entries:
        try:
            head = ts4_arc.peek_blob(_head(core, e) if e[2] > 200000 else core.raw(e), 16)
        except Exception:
            continue
        if len(head) < 16 or head[8:12] not in (b"\0\0\0\4", b"\0\0\0\x10"):
            continue
        t = struct.unpack_from(">I", head, 4)[0]
        if t == DICT_TYPE_SECOND:
            d = core.read(e)
            try:
                dicts["%08x" % e[0]] = ts4_xbin.read_crc_dictionary(d)
            except ValueError:
                pass
        elif t == ANIMDB_TYPE:
            animdb = core.read(e)
    for d in dicts.values():
        names.update(d)
    if a.dll:
        names.update({k: v for k, v in dll_strings(a.dll).items() if k not in names})
    json.dump({k: {"%08x" % c: s for c, s in v.items()} for k, v in dicts.items()},
              open(os.path.join(a.out, "crc_dictionaries.json"), "w"))
    pairs = ts4_xbin.read_layout_pairs(layout)
    json.dump([{"layout_id": "%08x" % l, "root_type": "%08x" % t, "name": names.get(t)} for l, t in pairs],
              open(os.path.join(a.out, "layout_pairs.json"), "w"), indent=0)
    for nm in ("Settings.bin", "State.bin"):
        for h, (_d, n) in core.leaf_names.items():
            if n == nm:
                data = core.read(core.find(h))
                json.dump(decode_template_file(data), open(os.path.join(a.out, "templates_%s.json" % nm[:-4].lower()), "w"))
    if animdb:
        json.dump(decode_animation_db(animdb, layout, names), open(os.path.join(a.out, "animation_db.json"), "w"))
    print("dictionaries:", {k: len(v) for k, v in dicts.items()}, "animdb:", len(animdb or b""))

    if a.census:
        census = collections.defaultdict(lambda: {"count": 0, "max_usize": 0, "archives": set()})
        for p, _ in x.walk():
            if not p.lower().endswith(".arc") or p == "CutScenes.arc" or p.startswith("Baked_"):
                continue
            arc = ts4_arc.Arc(x.open_slice(p))
            for h, off_, sz in arc.entries:
                try:
                    arc.f.seek(arc.data_start + off_)
                    blob = arc.f.read(min(sz, 200000))
                    head = ts4_arc.peek_blob(blob, 20)
                    us = struct.unpack_from(">I", blob, 20)[0] if blob[:8] == ts4_arc.TAG else sz
                except Exception:
                    continue
                if len(head) >= 20 and head[16:20] == b"\xff\xff\xff\xff" and head[8:12] in (b"\0\0\0\4", b"\0\0\0\x10"):
                    t = struct.unpack_from(">I", head, 4)[0]
                    c = census[t]
                    c["count"] += 1
                    c["max_usize"] = max(c["max_usize"], us)
                    c["archives"].add(p)
        out = [{"root_type": "%08x" % t, "name": names.get(t), "count": c["count"], "max_usize": c["max_usize"],
                "archives": len(c["archives"])} for t, c in sorted(census.items(), key=lambda kv: -kv[1]["count"])]
        json.dump(out, open(os.path.join(a.out, "xbin_census.json"), "w"), indent=0)
        print("census types:", len(out))


if __name__ == "__main__":
    main()
