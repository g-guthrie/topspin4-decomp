#!/usr/bin/env python3
"""Shot-template decoder for Top Spin 4 (Xbox 360), standard library only.

Reads the shot-template table out of the raw ``Settings.bin`` (and ``State.bin``, which holds
one extra row) of ``Core.arc`` and decodes every row into named fields.  Layout (docs/gameplay/gp4b.md
section 1, docs/gameplay/df.md 4.x, measured on the retail disc in docs/gameplay/shot-templates.md):

All integers/floats are big-endian.  Every ``rel`` is a signed 32-bit offset relative to the address
of the field that holds it.  A row is 0x8C bytes (``row``); ``tpl = row + 0x18``:

  row+0x00 u32 row type 0x85B71A2B   (Settings.bin only) class of the selector object X built from the row
  row+0x04 u32 name hash             crc32 of the template name; X.init (fn_886707C8) looks it up in the aim table
  row+0x08 u32 group hash            (0, or e.g. crc32("FlatReturn")): second aim-table key -> X+0x0C
  row+0x0C u32 base hash             (0 or a name hash): third aim-table key -> X+0x10
  row+0x10 {rel or -1}               serve rows: pointer to a serve parameter sub-record (speed, spin elements)
  row+0x14 {rel or -1}               stroke rows: pointer to 20 (lo, hi) float ranges -> selector entry+0x10
  tpl+0x00 node0 {rel, type, kind}   primary node (curve of the distance), kind = solver kind
  tpl+0x0C node1 {rel, type, kind}   secondary node, kind = secondary kind
  tpl+0x18/+0x24/+0x30 {rel,count=2,cap=2}  -> 2 elements {rel,type} = (lo, hi): spin_a, spin_c, spin_b
  tpl+0x3C f32 T                     drag scale (k = T / a4)
  tpl+0x40/+0x4C/+0x58/+0x64 {rel,count,cap} -> curve16 keys {x0,x1,y0,y1}: bounce speed loss c40(spin_a),
                                     spin decay c4C(spin_a), outgoing elevation c58(theta), yaw kick c64(spin_b)
  row+0x88 u32 name hash repeated

Value types ({rel,type}): 0x33799CCE float, 0xF9F12A60 curve20 (keys {x0,x1,y0,slope,w4}),
0x7A330099 2-D table (rows {curve16 header, ?, a_key}).

Usage:
  templates.py --settings Settings.bin [--state State.bin] [--out templates_decoded.json]
  templates.py --arc Core.arc [--iso DISC.iso] ...    (extracts entries 0x334E7E0D / 0x623D0979 via tools/ts4_arc.py)
  templates.py --settings S --state ST --yaml data/gameplay/ball_templates.yaml \
               --trajectories data/gameplay/ball_trajectories.csv [--curve-mode step|ramp|both]
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import sys
import zlib

TYPE_CONST = 0x33799CCE
TYPE_CURVE20 = 0xF9F12A60
TYPE_TABLE2D = 0x7A330099
VALUE_TYPES = (TYPE_CONST, TYPE_CURVE20, TYPE_TABLE2D)

KIND_NAMES = {
    0x5D90675B: "DropTime",
    0x50B89452: "BounceSpeed",
    0xC1965E5C: "InitialSpeed",
    0x2DB3EB6F: "AverageSpeed",
    0x879BA860: "Apogee",
}
ROW_TYPE = 0x85B71A2B
ROW_SIZE = 0x8C
SETTINGS_KEY = 0x334E7E0D  # Core.arc entry hash of Settings.bin
STATE_KEY = 0x623D0979     # Core.arc entry hash of State.bin

# Template names recovered by crc32 search (each hash is a 32-bit match; see docs/gameplay/shot-templates.md).
TEMPLATE_NAMES = [
    "TopSpinNormal", "TopSpinRisky", "TopSpinFinesse", "SliceNormal", "SliceRisky", "SliceFinesse",
    "FlatNormal", "FlatRisky", "FlatFinesse", "FlatReturn", "LobNormal", "DefensiveShot", "DropShotNormal",
    "SmashNormal", "PowerVolley", "SliceVolley", "DropVolley", "FlatVolley", "ServeNormal", "ServeSlice",
    "ServeAdvanced",
]


def crc(name: str) -> int:
    return zlib.crc32(name.encode("latin1")) & 0xFFFFFFFF


def name_table(extra=()):
    t = {crc(n): n for n in TEMPLATE_NAMES}
    t.update({crc(n): n for n in extra})
    return t


def f32r(x: float) -> float:
    """Round-trip a float32 through a short decimal so JSON stays readable ("0.04" not "0.03999999910593033")."""
    for prec in range(1, 10):
        v = float("%.*g" % (prec, x))
        if struct.pack(">f", v) == struct.pack(">f", x):
            return v
    return x


class Buf:
    """Big-endian accessor over a bytes object (absolute file offsets)."""

    def __init__(self, data: bytes):
        self.d = data

    def u32(self, a):
        return struct.unpack_from(">I", self.d, a)[0]

    def i32(self, a):
        return struct.unpack_from(">i", self.d, a)[0]

    def f32(self, a):
        return struct.unpack_from(">f", self.d, a)[0]

    def inb(self, a, n=4):
        return 0 <= a and a + n <= len(self.d)


# ---------------------------------------------------------------- curves and tables

def read_curve20(b: Buf, hdr: int):
    """Header {rel, count, cap} at hdr, keys of 20 bytes at hdr+rel: {x0, x1, y0, slope, w4}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 20 * count):
        raise ValueError("curve20 out of range at 0x%X" % hdr)
    return [[f32r(b.f32(base + 20 * i + 4 * j)) for j in range(5)] for i in range(count)]


def read_curve16(b: Buf, hdr: int):
    """Header {rel, count[, cap]} at hdr, keys of 16 bytes at hdr+rel: {x0, x1, y0, y1}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 16 * count):
        raise ValueError("curve16 out of range at 0x%X" % hdr)
    return [[f32r(b.f32(base + 16 * i + 4 * j)) for j in range(4)] for i in range(count)]


def read_table2d(b: Buf, hdr: int):
    """Header {rel, count} at hdr; rows of 16 bytes {curve16 header (rel relative to the row), ?, f32 a_key}."""
    rel, count = b.i32(hdr), b.i32(hdr + 4)
    if rel == -1 or count <= 0:
        return []
    base = hdr + rel
    if not b.inb(base, 16 * count):
        raise ValueError("table2d out of range at 0x%X" % hdr)
    rows = []
    for i in range(count):
        r = base + 16 * i
        rows.append({"a": f32r(b.f32(r + 12)), "unk": b.u32(r + 8), "keys": read_curve16(b, r)})
    return rows


def read_value(b: Buf, addr: int):
    """Polymorphic value {rel, type} at addr (8 bytes): float, curve20 or table2d.  Returns a JSON-able dict."""
    rel, typ = b.i32(addr), b.u32(addr + 4)
    tgt = addr + rel
    if typ == TYPE_CONST:
        return {"type": "const", "value": f32r(b.f32(tgt))}
    if typ == TYPE_CURVE20:
        return {"type": "curve20", "keys": read_curve20(b, tgt)}
    if typ == TYPE_TABLE2D:
        return {"type": "table2d", "rows": read_table2d(b, tgt)}
    return {"type": "unknown", "type_hash": "%08x" % typ}


CURVE_MODES = ("step", "ramp")


def eval_curve20(keys, x, mode="step"):
    """fn_8817A688: last key with x0 <= x (first if none); y = y0 + slope * clamp(x - x0, 0, x1 - x0).

    mode "step" uses the stored slope (+0x0C, 0.0 in every retail key: the curve holds y0);
    mode "ramp" is what the game evaluates: at load fn_8867BB78 / fn_88179740 set slope = (y1 - y0) / (x1 - x0)
    from the end value y1 at +0x10 (docs/gameplay/graphs-decoded.md); "step" uses the stored zero slopes."""
    if not keys:
        return 0.0
    sel = keys[0]
    for k in keys:
        if k[0] > x:
            break
        sel = k
    x0, x1, y0, slope = sel[0], sel[1], sel[2], sel[3]
    if mode == "ramp" and x1 != x0:
        slope = (sel[4] - y0) / (x1 - x0)
    t = max(min(x - x0, x1 - x0), 0.0)
    return y0 + t * slope


def eval_curve16(keys, x):
    """fn_881899D8: last key with x0 <= x (first if none); y = y0 + clamp((x-x0)/(x1-x0), 0, 1) * (y1 - y0)."""
    if not keys:
        return 0.0
    sel = keys[0]
    for k in keys:
        if k[0] > x:
            break
        sel = k
    x0, x1, y0, y1 = sel
    span = x1 - x0
    t = min(max(x - x0, 0.0), span)
    return y0 + (t / span if span else 0.0) * (y1 - y0)


def eval_table2d(rows, a, bval):
    """fn_8826D278: linear interpolation in `a` between the curve16 values (at `bval`) of the enclosing rows."""
    if not rows:
        return 0.0
    lo = 0
    for i, r in enumerate(rows):
        if a - r["a"] < 0:
            break
        lo = i
    if lo == len(rows) - 1:
        return eval_curve16(rows[lo]["keys"], bval)
    r0, r1 = rows[lo], rows[lo + 1]
    v0, v1 = eval_curve16(r0["keys"], bval), eval_curve16(r1["keys"], bval)
    d = a - r0["a"]
    span = r1["a"] - r0["a"]
    if d > 0:
        return v1 if d >= span else v0 + d / span * (v1 - v0)
    return v0


def eval_value(val, x, y=0.0, mode="step"):
    """Evaluate a decoded value dict (x = distance in cm for curves/tables, y = hit height in cm for tables)."""
    t = val["type"]
    if t == "const":
        return val["value"]
    if t == "curve20":
        return eval_curve20(val["keys"], x, mode)
    if t == "table2d":
        return eval_table2d(val["rows"], x, y)
    return 0.0


# ---------------------------------------------------------------- rows

def find_rows(b: Buf):
    """Rows are found by their two nodes: tpl+0x04 and +0x10 are value types, tpl+0x08 and +0x14 are kind hashes."""
    out = []
    n = len(b.d)
    for p in range(0, n - 0x70, 4):
        if (b.u32(p + 4) in VALUE_TYPES and b.u32(p + 8) in KIND_NAMES
                and b.u32(p + 0x10) in VALUE_TYPES and b.u32(p + 0x14) in KIND_NAMES):
            out.append(p - 0x18)
    return out


def read_spin_pair(b: Buf, slot: int):
    rel, count = b.i32(slot), b.i32(slot + 4)
    if count != 2:
        raise ValueError("spin slot 0x%X has %d elements" % (slot, count))
    base = slot + rel
    return {"lo": read_value(b, base), "hi": read_value(b, base + 8)}


def read_aux(b: Buf, addr: int, nfloats=16):
    rel = b.i32(addr)
    if rel == -1:
        return None
    tgt = addr + rel
    if not b.inb(tgt, 4 * nfloats):
        return {"addr": tgt}
    return {"addr": tgt, "floats": [f32r(b.f32(tgt + 4 * i)) for i in range(nfloats)]}


def decode_row(b: Buf, row: int, names: dict):
    tpl = row + 0x18

    def nm(h):
        return names.get(h)

    k0, k1 = b.u32(tpl + 8), b.u32(tpl + 0x14)
    hdr = [b.u32(row + 4 * i) for i in range(6)]
    has_type = hdr[0] == ROW_TYPE
    r = {
        "row_offset": row,
        "header_words": ["%08x" % w for w in hdr],
        "kind": KIND_NAMES[k0],
        "kind_hash": "%08x" % k0,
        "secondary_kind": KIND_NAMES[k1],
        "secondary_kind_hash": "%08x" % k1,
        "T": f32r(b.f32(tpl + 0x3C)),
        "primary": read_value(b, tpl),
        "secondary": read_value(b, tpl + 0x0C),
        "spin": {
            "a": read_spin_pair(b, tpl + 0x18),
            "c": read_spin_pair(b, tpl + 0x24),
            "b": read_spin_pair(b, tpl + 0x30),
        },
        "bounce": {
            "speed_loss": read_curve16(b, tpl + 0x40),
            "spin_decay": read_curve16(b, tpl + 0x4C),
            "out_elevation": read_curve16(b, tpl + 0x58),
            "yaw_kick": read_curve16(b, tpl + 0x64),
        },
        "tail_words": ["%08x" % b.u32(row + 0x70 + 4 * i) for i in range(4)] if b.inb(row + 0x80, 0x10) else [],
    }
    if has_type:
        r["name_hash"] = "%08x" % hdr[1]
        r["name"] = nm(hdr[1])
        r["group_hash"] = "%08x" % hdr[2]
        r["group"] = nm(hdr[2]) if hdr[2] else None
        r["base_hash"] = "%08x" % hdr[3]
        r["base"] = nm(hdr[3]) if hdr[3] else None
        r["aux_ptr_10"] = read_aux(b, row + 0x10, 8)
        if r["aux_ptr_10"] and b.inb(r["aux_ptr_10"]["addr"] + 0x20, 16):
            # serve sub-record: 8 scalar floats (+0x18 speed km/h, +0x1C ?) then two {rel, type} elements
            base = r["aux_ptr_10"]["addr"]
            r["aux_ptr_10"]["elements"] = [read_value(b, base + 0x20), read_value(b, base + 0x28)]
        r["aux_ptr_14"] = read_aux(b, row + 0x14, 40)
        r["trailer_name_hash"] = "%08x" % b.u32(row + 0x88)
    return r


def decode_file(data: bytes, label: str, names: dict):
    b = Buf(data)
    rows = [decode_row(b, off, names) for off in find_rows(b)]
    for i, r in enumerate(rows):
        r["index"] = i
        r["file"] = label
    return {"file": label, "size": len(data), "sha256": hashlib.sha256(data).hexdigest(), "rows": rows}


def decode_all(settings: bytes, state: bytes | None = None, extra_names=()):
    names = name_table(extra_names)
    out = {"tool": "tools/ts4data/templates.py", "python": sys.version.split()[0],
           "files": [decode_file(settings, "Settings.bin", names)]}
    if state is not None:
        out["files"].append(decode_file(state, "State.bin", names))
        out["ball_block"] = decode_ball_block(state)
    return out


STATE_BALL_IMAGE = 0x964     # State.bin file offset of the serialised 0x540-byte ball (layout Gp4bBall)


def decode_ball_block(state: bytes, base: int = STATE_BALL_IMAGE):
    """The default ball block in State.bin (ball-physics.md section 2), with the meaning of each field.

    Readers (Swing_DLL.xex): +0x4C0..0x4CC only fn_886AE528 +0xA78..+0xAA4 (Wood frame-shot target, offset
    from the hitter); +0x4D0..0x4DC the flight solver / stepper; +0x4E0 fn_889C2818 (skip the step on the
    launch frame); +0x4E1 fn_889C1C80 / fn_889C1F70 let-cord (zero spin_b and spin_c); +0x494..0x4A0 the
    let-cord branch (copied through the command C+0x30..0x3C, fn_886B5128 +0x7B8..+0x7E8)."""
    f = lambda o: round(struct.unpack_from(">f", state, base + o)[0], 6)
    u = lambda o: struct.unpack_from(">I", state, base + o)[0]
    b = lambda o: state[base + o]
    return {
        "file_offset": "0x%X" % base,
        "tau_s": f(0x00), "bounce_tick": u(0x04), "T": f(0x08),
        "hold_ticks_0x28": u(0x28), "hold_delta_0xA0": [f(0xA0), f(0xA4), f(0xA8)],
        "cord_0x494_elev_deg_yaw_deg_speed_loss_spin_loss": [f(0x494), f(0x498), f(0x49C), f(0x4A0)],
        "wood_dx_cm_0x4C0": [f(0x4C0), f(0x4C4)], "wood_dz_cm_0x4C8": [f(0x4C8), f(0x4CC)],
        "radius_cm_0x4D0": f(0x4D0), "a4_0x4D4": f(0x4D4), "g_0x4D8": f(0x4D8), "max_bounces_0x4DC": u(0x4DC),
        "skip_launch_step_0x4E0": b(0x4E0), "no_sidespin_0x4E1": b(0x4E1),
    }


def summarize(dec):
    lines = []
    for f in dec["files"]:
        lines.append("%s: %d bytes sha256 %s, %d rows" % (f["file"], f["size"], f["sha256"], len(f["rows"])))
        counts = {}
        for r in f["rows"]:
            k = (r["kind"], r["secondary_kind"])
            counts[k] = counts.get(k, 0) + 1
        for k, v in sorted(counts.items()):
            lines.append("  %-13s + %-8s x%d" % (k[0], k[1], v))
    return "\n".join(lines)


# ---------------------------------------------------------------- named view, evaluated tables, YAML / CSV writers

SETTINGS_CFG = 0x24          # Settings.bin root typed struct (cfg); ball+0x360 = row file offset - cfg
DIST_GRID_CM = [500, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500, 2750, 3000]
HEIGHT_GRID_CM = [60, 90, 120, 150, 180, 250]
SPIN_GRID = [-0.8, -0.6, -0.4, -0.2, 0.0, 0.2, 0.4]
BLENDS = [0.0, 0.5, 1.0]
VALUE_UNITS = {"DropTime": "s", "InitialSpeed": "km/h", "BounceSpeed": "km/h", "AverageSpeed": "km/h", "Apogee": "m"}


def _named_value(v):
    t = v["type"]
    if t == "const":
        return {"type": "const", "value": v["value"]}
    if t == "curve20":
        return {"type": "curve20", "keys": [dict(zip(("x0", "x1", "y0", "slope", "y1"), k)) for k in v["keys"]]}
    if t == "table2d":
        return {"type": "table2d", "rows": [{"a_dist_cm": r["a"], "keys_over_height_cm": [dict(zip(("x0", "x1", "y0", "y1"), k))
                                                                                        for k in r["keys"]]} for r in v["rows"]]}
    return dict(v)


def _c16(keys):
    return [dict(zip(("x0", "x1", "y0", "y1"), k)) for k in keys]


def _r(x, n=4):
    return float("%.*g" % (n + 2, x))


def named_row(r, mode_list=CURVE_MODES):
    """One template row with every field named and the speed/time, spin and bounce tables evaluated."""
    out = {
        "index": r["index"], "file": r["file"], "row_offset": "0x%X" % r["row_offset"],
        "ball_0x360": ("0x%X" % (r["row_offset"] - SETTINGS_CFG)) if r["file"] == "Settings.bin" else None,
        "name": r.get("name"), "name_hash": r.get("name_hash"),
        "id": r.get("trailer_name_hash"),
        "header": {
            "row_type": r["header_words"][0],
            "aim_key_group": r.get("group") or r.get("group_hash"),
            "aim_key_base": r.get("base") or r.get("base_hash"),
            "serve_params_rel": r["header_words"][4], "stroke_ranges_rel": r["header_words"][5],
        },
        "serve_params": None if not r.get("aux_ptr_10") else {
            "floats": r["aux_ptr_10"].get("floats"),
            "elements": [_named_value(v) for v in r["aux_ptr_10"].get("elements", [])]},
        "stroke_ranges_lo_hi": None if not (r.get("aux_ptr_14") or {}).get("floats") else
            [r["aux_ptr_14"]["floats"][i:i + 2] for i in range(0, 40, 2)],
        "kind": r["kind"], "secondary_kind": r["secondary_kind"],
        "primary_unit": VALUE_UNITS.get(r["kind"]),
        "secondary_unit": ("km/h delta" if r["secondary_kind"] in ("InitialSpeed", "BounceSpeed")
                           else "s offset" if r["secondary_kind"] == "DropTime" else VALUE_UNITS.get(r["secondary_kind"])),
        "T": r["T"], "k_at_a4_0.06": _r(r["T"] / 0.06),
        "primary": _named_value(r["primary"]), "secondary": _named_value(r["secondary"]),
        "spin": {name: {"lo": _named_value(r["spin"][key]["lo"]), "hi": _named_value(r["spin"][key]["hi"])}
                 for name, key in (("vertical_a", "a"), ("lateral_b", "b"), ("along_c", "c"))},
        "bounce": {"speed_loss_vs_spin_a": _c16(r["bounce"]["speed_loss"]),
                   "spin_decay_vs_spin_a": _c16(r["bounce"]["spin_decay"]),
                   "out_elevation_vs_in_elevation_rad": _c16(r["bounce"]["out_elevation"]),
                   "yaw_kick_vs_spin_b_rad": _c16(r["bounce"]["yaw_kick"])},
    }
    ev = {}
    for mode in mode_list:
        tab = {}
        for which in ("primary", "secondary"):
            v = r[which]
            if v["type"] == "table2d":
                tab[which] = {"h%d" % h: [_r(eval_value(v, d, h, mode)) for d in DIST_GRID_CM] for h in HEIGHT_GRID_CM}
            else:
                tab[which] = [_r(eval_value(v, d, 100.0, mode)) for d in DIST_GRID_CM]
        h_m = 2.7 if (r.get("name") or "").startswith("Serve") else 1.0
        spins = {}
        for name, key in (("a", "a"), ("b", "b"), ("c", "c")):
            lo = eval_value(r["spin"][key]["lo"], h_m, 0.0, mode)
            hi = eval_value(r["spin"][key]["hi"], h_m, 0.0, mode)
            spins[name] = [_r(lo + (hi - lo) * bl) for bl in BLENDS]
        tab["spin_at_blend_0_0.5_1"] = spins
        tab["spin_eval_height_m"] = h_m
        ev[mode] = tab
    out["evaluated"] = {"distance_grid_cm": DIST_GRID_CM, **ev}
    out["bounce_evaluated"] = {
        "spin_a_grid": SPIN_GRID,
        "speed_factor": [_r(1.0 - eval_curve16(r["bounce"]["speed_loss"], s)) for s in SPIN_GRID],
        "spin_retained": [_r(1.0 - eval_curve16(r["bounce"]["spin_decay"], s)) for s in SPIN_GRID],
        "tilt_weight": [_r(abs(5.0 * s)) for s in SPIN_GRID],
    }
    return out


def _yaml_scalar(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return repr(v)
    s = str(v)
    if s == "" or any(c in s for c in ":#{}[],&*!|>'\"%@`") or s.strip() != s or s.lower() in ("null", "true", "false", "yes", "no"):
        return '"%s"' % s.replace("\\", "\\\\").replace('"', '\\"')
    return s


def to_yaml(obj, indent=0):
    """Minimal YAML emitter (block mappings, flow lists of scalars, block lists of mappings)."""
    pad = "  " * indent
    lines = []
    if isinstance(obj, dict):
        for k, v in obj.items():
            if isinstance(v, dict) and v:
                lines.append("%s%s:" % (pad, k))
                lines.append(to_yaml(v, indent + 1))
            elif isinstance(v, list) and v and isinstance(v[0], (dict, list)):
                lines.append("%s%s:" % (pad, k))
                for item in v:
                    if isinstance(item, dict):
                        sub = to_yaml(item, indent + 2).split("\n")
                        sub[0] = "%s- %s" % ("  " * (indent + 1), sub[0].lstrip())
                        lines.extend(sub)
                    else:
                        lines.append("%s- [%s]" % ("  " * (indent + 1), ", ".join(_yaml_scalar(x) for x in item)))
            elif isinstance(v, list):
                lines.append("%s%s: [%s]" % (pad, k, ", ".join(_yaml_scalar(x) for x in v)))
            elif isinstance(v, dict):
                lines.append("%s%s: {}" % (pad, k))
            else:
                lines.append("%s%s: %s" % (pad, k, _yaml_scalar(v)))
    return "\n".join(lines)


def _header(cmd, dec, extra=()):
    out = ["Generated by: %s" % cmd, "Tool: tools/ts4data/templates.py (Python %s, standard library)" % sys.version.split()[0]]
    for f in dec["files"]:
        out.append("Source: %s %d bytes sha256 %s" % (f["file"], f["size"], f["sha256"]))
    out.extend(extra)
    return out


def write_yaml(dec, path, cmd, mode):
    rows = [named_row(r) for f in dec["files"] for r in f["rows"]]
    hdr = _header(cmd, dec, [
        "Shot-template rows of Core.arc Settings.bin (+ State.bin), every field named; spec docs/gameplay/ball-physics.md.",
        "Curve20 keys store slope 0 and the end value y1 at +0x10; 'evaluated.ramp' is what the game uses",
        "(load-time slope fixup fn_8867BB78), 'evaluated.step' holds y0 (stored zero slopes). Trajectory mode: %s." % mode,
    ])
    with open(path, "w") as fh:
        fh.write("".join("# %s\n" % h for h in hdr))
        fh.write(to_yaml({"generator": {"command": cmd, "curve_mode_for_trajectories": mode},
                          "sources": [{"file": f["file"], "size": f["size"], "sha256": f["sha256"]} for f in dec["files"]],
                          "ball_block": dec.get("ball_block"),
                          "rows": rows}))
        fh.write("\n")


TRAJ_COLUMNS = ["file", "index", "id", "name", "kind", "secondary", "T", "curve_mode", "scenario", "f4c", "blend",
                "dist_m", "tau", "bounce_tick", "tau_min", "has_min", "speed_limited", "raised", "net_unreachable",
                "init_kmh", "arrive_kmh", "out_kmh", "launch_deg", "arrive_deg", "out_deg", "apex_m", "net_clear_m",
                "spin_a", "spin_b", "spin_c", "k", "bounce_speed_loss", "bounce_spin_decay"]


def trajectory_rows(dec, modes=("step",), blends=(0.5,), f4cs=(1.0, 0.0)):
    import ball_model  # noqa: E402  (same directory)
    import template_sim  # scenarios
    out = []
    for f in dec["files"]:
        for r in f["rows"]:
            for sc in template_sim.scenarios_for(r.get("name")):
                frm, to = template_sim.SCENARIOS[sc]
                for mode in modes:
                    for f4c in f4cs:
                        for bl in blends:
                            m = ball_model.simulate(r, sys.modules[__name__], frm, to, blend=bl, sec_weight=f4c, mode=mode)
                            rec = {"file": f["file"], "index": r["index"], "id": r.get("trailer_name_hash", ""),
                                   "name": r.get("name") or "", "kind": r["kind"], "secondary": r["secondary_kind"],
                                   "T": r["T"], "curve_mode": mode, "scenario": sc, "f4c": f4c, "blend": bl}
                            rec.update(m)
                            out.append(rec)
    return out


def write_trajectories(dec, path, cmd, modes):
    import csv
    rows = trajectory_rows(dec, modes)
    hdr = _header(cmd, dec, [
        "Per-shot trajectories from tools/ts4data/ball_model.py (port of ref/gameplay/ball.c), a4 0.06, g 9.81,",
        "radius 4 cm, net 91.4 cm (assumed), scenarios in tools/ts4data/template_sim.py; f4c 1 = primary only, 0 = full",
        "secondary; heights are ball-centre heights; net_clear_m = centre height at x = 0 + radius - net.",
    ])
    with open(path, "w", newline="") as fh:
        fh.write("".join("# %s\n" % h for h in hdr))
        w = csv.DictWriter(fh, fieldnames=TRAJ_COLUMNS, extrasaction="ignore")
        w.writeheader()
        w.writerows(rows)
    return len(rows)


def _load_from_arc(arc_path, iso):
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    import ts4_arc  # noqa: E402
    arc = ts4_arc.open_arc(arc_path, iso)
    return arc.read(arc.find(SETTINGS_KEY)), arc.read(arc.find(STATE_KEY))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--settings", help="raw Settings.bin")
    ap.add_argument("--state", help="raw State.bin")
    ap.add_argument("--arc", help="Core.arc (extract both files from it)")
    ap.add_argument("--iso", help="read --arc from this disc image")
    ap.add_argument("--out", default=None, help="JSON output (default: print a summary only)")
    ap.add_argument("--yaml", default=None, help="named YAML dump (e.g. data/gameplay/ball_templates.yaml)")
    ap.add_argument("--trajectories", default=None, help="per-shot trajectory CSV (e.g. data/gameplay/ball_trajectories.csv)")
    ap.add_argument("--curve-mode", choices=CURVE_MODES + ("both",), default="ramp",
                    help="curve20 reading for the trajectory table: ramp (game behaviour, default), step (stored slopes), or both")
    a = ap.parse_args(argv)
    if a.arc:
        s, st = _load_from_arc(a.arc, a.iso)
    elif a.settings:
        s = open(a.settings, "rb").read()
        st = open(a.state, "rb").read() if a.state else None
    else:
        ap.error("need --settings or --arc")
    dec = decode_all(s, st)
    print(summarize(dec))
    if a.out:
        os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
        with open(a.out, "w") as fh:
            json.dump(dec, fh, indent=1)
            fh.write("\n")
        print("wrote", a.out)
    cmd = "python3 tools/ts4data/templates.py " + " ".join(argv if argv is not None else sys.argv[1:])
    modes = CURVE_MODES if a.curve_mode == "both" else (a.curve_mode,)
    if a.yaml:
        os.makedirs(os.path.dirname(os.path.abspath(a.yaml)), exist_ok=True)
        write_yaml(dec, a.yaml, cmd, a.curve_mode)
        print("wrote", a.yaml)
    if a.trajectories:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        os.makedirs(os.path.dirname(os.path.abspath(a.trajectories)), exist_ok=True)
        n = write_trajectories(dec, a.trajectories, cmd, modes)
        print("wrote %s (%d rows)" % (a.trajectories, n))
    return 0


if __name__ == "__main__":
    sys.exit(main())
