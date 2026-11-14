#!/usr/bin/env python3
"""Dump the movement-planner and repositioning values read from code by GE2 (Top Spin 4, Xbox 360).

    python3 -I tools/ts4data/repositioning.py [--dll orig/54540859/Swing_DLL.dll]
        [--settings work/disc/core_all/334e7e0d.bin] [--out data/gameplay/repositioning.yaml]

Two sources:
  * Swing_DLL.dll: constants of the code pool g_ts4_script_constants (0x880D0F70) and the doubles
    repositioning points in .rdata (lbl_880FC9B0..lbl_880FCA20), each with the instruction that reads it;
  * Settings.bin (Core.arc 334e7e0d): RepositioningPointSettings and PlayerTuning words (cfg = file 0x24).
The meaning of every value is in docs/gameplay/repositioning.md and movement-and-ai.md A.4c.
Standard library only.
"""
import argparse
import hashlib
import struct

POOL = 0x880D0F70

# (name, pool offset, reader, meaning)
POOL_VALUES = [
    ("replan_lateral_cm", 0x404, "fn_886A9678 0x886A993C", "|lateral| of the 20-frame predicted position to the stand-point line must be below this"),
    ("replan_along_moving_min_cm", 0x79C, "fn_886A9678 0x886A998C", "along-line window when already moving toward the stand point: (this, 0)"),
    ("replan_along_still_max_cm", 0x42C, "fn_886A9678 0x886A9994", "along-line window otherwise: (replan_along_still_min_cm, this)"),
    ("replan_along_still_min_cm", 0x134, "fn_886A9678 0x886A99B0", "lower end of that window"),
    ("steps_no_volley_radius_sq_cm2", 0x614, "fn_886A32B8 0x886A3318", "nearest volley candidate farther than sqrt(this) on both sides -> Steps MaxSpeed raised"),
    ("steps_raised_max_speed_ms", 0x1D8, "fn_886A32B8 0x886A333C", "temporary PT+0x210 (Steps.Reachability.MaxSpeed) during that search"),
    ("steps_restored_max_speed_ms", 0x4C, "fn_886A32B8 0x886A33A4", "value written back to PT+0x210 afterwards (hard-coded, not the data value)"),
    ("mover_tau_factor", 0x114, "ctor 0x8866CFDC (+0x30, +0x60)", "Mover smoothing: time constant = this x 5 frames; also cm/frame -> m/s factor 0.6"),
    ("mover_tau_scale", 0x1E0, "fn_8866CDC8 0x8866CE60", "x mover_tau_factor = averaging window in frames"),
    ("approach_stick_window_deg", None, "fn_8869B928 0x8869BA78", "read from Settings (RepositioningPointSettings/324f5246), see settings"),
    ("doubles_ai_depth_split_x_cm", 0x77C, "fn_886A40A8 0x886A41A4", "doubles AI with no mode yet: local x below this -> baseline point, else net point"),
    ("deg_to_rad", 0x184, "fn_8869B928 0x8869BA7C", "degrees to radians"),
    ("stick_power_min", 0x2AC, "fn_8869B928 0x8869B9B8", "human approach needs move power S+0x9DC at least this"),
]

# doubles points: team+0x160..+0x190 (fn_886BB0A8 0x886BB3A4..0x886BB46C), world cm (x along the court)
DOUBLES = [
    ("near_side_0x317C51B7", [(0x160, 0x880FCA20), (0x170, 0x880FCA10), (0x180, 0x880FCA00), (0x190, 0x880FC9F0)]),
    ("far_side_0xA2EDA1E7", [(0x160, 0x880FC9E0), (0x170, 0x880FC9D0), (0x180, 0x880FC9C0), (0x190, 0x880FC9B0)]),
]
DOUBLES_MODE = {0x160: "mode 4 (net)", 0x170: "mode 6 (net)", 0x180: "mode 3 (baseline)", 0x190: "mode 5 (baseline)"}

# Settings.bin file offsets (cfg + 0x24); type f = float, u = uint32, b = bool byte
SETTINGS = [
    (0x1A4 + 0x1B8, "b", "PlayerTuning+0x1B8 (#3db13d71)", "fn_88689068 0x88689120",
     "human reach flattening in the selection score: candidates under best + curve PT+0x188(best) get Reachability = best, others 100"),
    (0x1A4 + 0x210, "f", "PlayerTuning+0x210 Steps.Reachability.MaxSpeed", "fn_886A32B8",
     "overwritten with 3.0 by code after a raised-speed search"),
    (0x9E4, "f", "RepositioningPointSettings/bad7533a/TopLeft.x", "fn_8869B928 0x8869B9D4", "baseline box: x < this"),
    (0x9EC, "f", "RepositioningPointSettings/bad7533a/TopLeft.z", "fn_8869B928 0x8869B9F4", "baseline box: z < this"),
    (0x9F4, "f", "RepositioningPointSettings/bad7533a/BottomRight.x", "fn_8869B928 0x8869BA04", "baseline box: x > this"),
    (0x9FC, "f", "RepositioningPointSettings/bad7533a/BottomRight.z", "fn_8869B928 0x8869BA10", "baseline box: z > this"),
    (0xA64, "f", "RepositioningPointSettings/2c987b2e", "fn_8868C090 0x8868C0DC", "baseline point x in play mode 1 (z = 0)"),
    (0xA68, "f", "RepositioningPointSettings/00fb8872", "fn_8868C090 0x8868C0D8", "net point x in play mode 1 (z = 0)"),
    (0xA84, "f", "RepositioningPointSettings/0081913b", "fn_8869B928 0x8869BAA0; fn_886A3DF0 0x886A3FDC",
     "human: net point must be farther than this; AI: arrived when within this (cm)"),
    (0xA8C, "f", "RepositioningPointSettings/7440a9da", "fn_8868C218 0x8868C2D8; fn_8865E490", "frames between two behaviour-flag raises"),
    (0xA94, "f", "RepositioningPointSettings/324f5246", "fn_8869B928 0x8869BA78", "stick within this many degrees of the net point"),
    (0xA98, "f", "RepositioningPointSettings/8154a27b", "fn_8869B928 0x8869B964; fn_8868C218 0x8868C25C",
     "player forward of -this (cm) counts as at the net"),
    (0xAAC, "u", "/98294782", "fn_8869B928 0x8869BB7C", "approach refused when the pending event is fewer than this many frames away"),
]


def pe_reader(data):
    e = struct.unpack_from("<I", data, 0x3C)[0]
    ns = struct.unpack_from("<H", data, e + 6)[0]
    osz = struct.unpack_from("<H", data, e + 20)[0]
    base = struct.unpack_from("<I", data, e + 24 + 28)[0]
    sec = e + 24 + osz
    secs = [struct.unpack_from("<8sIIII", data, sec + 40 * i) for i in range(ns)]

    def off(va):
        rva = va - base
        for _n, vs, va_, rs, rp in secs:
            if va_ <= rva < va_ + max(vs, rs):
                return rva - va_ + rp
        raise ValueError(hex(va))

    return lambda va: struct.unpack_from(">f", data, off(va))[0]


def r6(x):
    return float("%.6g" % x)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dll", default="orig/54540859/Swing_DLL.dll")
    ap.add_argument("--settings", default="work/disc/core_all/334e7e0d.bin")
    ap.add_argument("--out", default="data/gameplay/repositioning.yaml")
    a = ap.parse_args(argv)
    dll = open(a.dll, "rb").read()
    st = open(a.settings, "rb").read()
    f = pe_reader(dll)
    cmd = "python3 -I tools/ts4data/repositioning.py"
    out = ["# Top Spin 4 movement planner and repositioning values (GE2).",
           "# Generated by: " + cmd,
           "# Meanings and code: docs/gameplay/repositioning.md, docs/gameplay/movement-and-ai.md A.4c.",
           "generated_by: " + cmd,
           "sources_sha256:",
           "  Swing_DLL.dll: " + hashlib.sha256(dll).hexdigest(),
           "  Settings.bin (334e7e0d): " + hashlib.sha256(st).hexdigest(),
           "code_constants:  # g_ts4_script_constants 0x880D0F70 + offset"]
    for name, o, reader, meaning in POOL_VALUES:
        if o is None:
            continue
        out.append("  %s: {pool_offset: 0x%X, value: %r, read_by: \"%s\", meaning: \"%s\"}"
                   % (name, o, r6(f(POOL + o)), reader, meaning))
    out.append("doubles_points:  # team+0x160..+0x190, world cm [x, y, z, w]; written by fn_886BB0A8 when team+0x1A3 is clear")
    for side, pts in DOUBLES:
        out.append("  %s:" % side)
        for toff, va in pts:
            v = [r6(f(va + 4 * i)) for i in range(4)]
            out.append("    team+0x%X: {rdata: 0x%08X, value: %s, use: \"%s\"}" % (toff, va, v, DOUBLES_MODE[toff]))
    out.append("settings:  # Settings.bin file offset (cfg = file 0x24)")
    for fo, kind, path, reader, meaning in SETTINGS:
        if kind == "f":
            val = r6(struct.unpack_from(">f", st, fo)[0])
        elif kind == "u":
            val = struct.unpack_from(">I", st, fo)[0]
        else:
            val = st[fo]
        out.append("  - {file_offset: 0x%X, path: \"%s\", value: %r, read_by: \"%s\", meaning: \"%s\"}"
                   % (fo, path, val, reader, meaning))
    out.append("graphs:  # from data/gameplay/graphs.yaml")
    out.append("  RepositioningPointSingle_116: \"baseline point = (1300, -hit_z/12) and net point = (300, hit_z/6) "
               "from the opponent's HitPositionLocal z (curves +-600 -> -+50 and +-100); outputs S+0xA1C..0xA28\"")
    out.append("  repositioning_components_117_137: \"#2ac5965a = 0 and #2b4b4baa = 1 in every graph (AI stop rule inert); "
               "#6e33662f = post-swing stand-still frames (graph 117: 0.8..1.0 x lerp(30..20, 25..20 by vigor, Return))\"")
    open(a.out, "w").write("\n".join(out) + "\n")


if __name__ == "__main__":
    main()
