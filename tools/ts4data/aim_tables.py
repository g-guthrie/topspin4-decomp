#!/usr/bin/env python3
"""Extract the Top Spin 4 aiming tables (Settings.bin AimingConfig) and evaluate the aim point.

Code (Swing_DLL, read instruction by instruction, docs/gameplay/aiming.md):
  shot target = selector vtable slot 4 fn_886935A0 (called from fn_886AE528 +0x4D8)
    fn_886706C8   QuadAimingState.AimX/AimY (S+0xD44) = aim stick (Stick_Aiming S+0x430, or the AI
                  StickOverride S+0xD70), negated on the mirrored court side; DirectionSelected
                  (S+0xDAD) = |x| > FLT_EPSILON or |y| > FLT_EPSILON
    fn_88693040   zone quad = bilinear blend of the four zones of the AimingConfig by the hitter's
                  local position (depth between VolleyDistance and BaselineDistance, lateral between
                  CenterDistance and SideDistance); each zone blends its four quads by the
                  efficiency m = S+0xD90 QuadEfficiency (quad k at m = 0, 0.5, 1, 2)
    fn_8867D150   target = the point of the quad edge in the stick DIRECTION (magnitude unused);
                  no direction -> the zone centre
  The AimingConfig is chosen by fn_88660F70 from the template row header keys (name_hash, or
  aim_key_group = FlatReturn when returning a serve, or aim_key_base in doubles).

Settings.bin layout (cfg = root at file 0x24): cfg+0x108 = list {rel, count 25, cap} of 0xA0-byte
AimingConfig records:
  +0x00 / +0x20 / +0x40 / +0x60  zones VolleyCenter (d8fd93ca), VolleySide (1b3c9a19),
                                 BaselineCenter (38ea0650), BaselineSide (b04737a5):
        zone +0x00 {rel, count 4, cap} AimingQuad list; each AimingQuad {rel, count 4, cap} of
                   Coord vec4 (x, y, z, w) cm; +0x10 vec4 centre (546a639e)
  +0x80 Id, +0x84 VolleyDistance, +0x88 BaselineDistance, +0x8C CenterDistance,
  +0x90 SideDistance, +0x94 bool 5ed23100 (true on the four serve configs, no code reader found)

Usage:
  python3 tools/ts4data/aim_tables.py --settings work/disc/core/334e7e0d.bin \
      --out data/gameplay/aim_tables.yaml --tables data/gameplay/aim_tables.txt
  python3 tools/ts4data/aim_tables.py --selftest
Standard library only.
"""
import argparse
import hashlib
import math
import os
import struct
import sys
import zlib

ZONES = ("VolleyCenter", "VolleySide", "BaselineCenter", "BaselineSide")
ZONE_HASH = (0xD8FD93CA, 0x1B3C9A19, 0x38EA0650, 0xB04737A5)
QUAD_EFFICIENCY = (0.0, 0.5, 1.0, 2.0)
FLT_EPSILON = 1.1920929e-07      # lbl_880C960C
DOUBLES_ALLEY = 137.0            # g_ts4_script_constants+0x644 (cm)
DOUBLES_SCALE = 1.4              # g_ts4_script_constants+0x51C
SQRT2 = 1.4142135                # g_ts4_script_constants+0x518

KNOWN = ["ServeNormal", "ServeSlice", "ServeAdvanced", "ServeRisky", "FlatNormal", "FlatReturn",
         "FlatVolley", "FlatFinesse", "FlatRiskyFinesse", "FlatRisky", "TopSpinNormal", "PowerVolley",
         "TopSpinFinesse", "TopSpinRiskyFinesse", "TopSpinRisky", "SliceNormal", "SliceVolley",
         "DropVolley", "SliceFinesse", "SliceRisky", "DropShotNormal", "LobNormal", "DefensiveShot",
         "SmashNormal", "LobRisky", "SliceRiskyFinesse", "LobRiskyFinesse"]
NAMES = {zlib.crc32(n.encode()): n for n in KNOWN}


def parse(data):
    root = 0x24
    rel, count, _cap = struct.unpack_from(">iII", data, root + 0x108)
    first = root + 0x108 + rel
    configs = []
    for i in range(count):
        r = first + 0xA0 * i
        ident, vd, bd, cd, sd = struct.unpack_from(">I4f", data, r + 0x80)
        zones = []
        for z in range(4):
            zo = r + 0x20 * z
            zrel, zcount, _ = struct.unpack_from(">iII", data, zo)
            lst = zo + zrel
            centre = struct.unpack_from(">4f", data, zo + 0x10)
            quads = []
            for q in range(zcount):
                hrel, hcount, _ = struct.unpack_from(">iII", data, lst + 0xC * q)
                qo = lst + 0xC * q + hrel
                quads.append([struct.unpack_from(">4f", data, qo + 16 * k) for k in range(hcount)])
            zones.append({"centre": centre, "quads": quads})
        configs.append({"index": i, "id": ident, "name": NAMES.get(ident), "volley_distance": vd,
                        "baseline_distance": bd, "center_distance": cd, "side_distance": sd,
                        "flag_5ed23100": data[r + 0x94], "zones": zones, "offset": r})
    return configs


# ----------------------------------------------------------------------------- model (mirrors the C)

def _lerp(a, b, t):
    return a + (b - a) * t


def _lerp_quad(qa, qb, t):
    return [(_lerp(a[0], b[0], t), _lerp(a[1], b[1], t)) for a, b in zip(qa, qb)]


def zone_quad(zone, m, widen=0.0):
    """fn_8867D350: the zone's quad at efficiency m (corners (x, z)) plus its centre."""
    q = [[(c[0], c[2]) for c in quad] for quad in zone["quads"]]

    def wid(quad, scale=False):
        out = []
        for k, (x, z) in enumerate(quad):
            if scale:
                out.append((x, z * DOUBLES_SCALE))
            else:
                out.append((x, z + (-widen if k in (0, 2) else widen)))
        return out
    big = widen > 1.0
    if m < 0.5:
        t = min(max(m * 2.0, 0.0), 1.0)
        a, b = q[0], (wid(q[1], True) if big else q[1])
    elif m <= 1.0:
        t = min(max((m - 0.5) * 2.0, 0.0), 1.0)
        a = wid(q[1], True) if big else q[1]
        b = wid(q[2])
    else:
        t = min(max(m - 1.0, 0.0), 1.0)
        a, b = wid(q[2]), q[3]
    c = zone["centre"]
    return _lerp_quad(a, b, t), (c[0], c[2])


def config_quad(cfg, pos_x, pos_z, m, mirror, widen=0.0):
    """fn_88693040: bilinear blend of the four zones by the hitter position (local cm)."""
    az = abs(pos_z)
    f0 = az - cfg["center_distance"]
    span = cfg["side_distance"] - cfg["center_distance"]
    lat = 0.0 if f0 <= 0.0 else (1.0 if f0 >= span else f0 / span)
    f0 = pos_x + cfg["baseline_distance"]
    span = cfg["baseline_distance"] - cfg["volley_distance"]
    dep = 0.0 if f0 <= 0.0 else (1.0 if f0 >= span else f0 / span)
    qs = [zone_quad(z, m, widen) for z in cfg["zones"]]
    (vc, cvc), (vs, cvs), (bc, cbc), (bs, cbs) = qs
    volley = _lerp_quad(vc, vs, lat)
    baseline = _lerp_quad(bc, bs, lat)
    quad = _lerp_quad(baseline, volley, dep)
    cv = (_lerp(cvc[0], cvs[0], lat), _lerp(cvc[1], cvs[1], lat))
    cb = (_lerp(cbc[0], cbs[0], lat), _lerp(cbc[1], cbs[1], lat))
    centre = (_lerp(cb[0], cv[0], dep), _lerp(cb[1], cv[1], dep))
    if mirror:                                   # fn_88661188 + the centre negation
        quad = [(x, -z) for x, z in quad]
        quad = [quad[1], quad[0], quad[3], quad[2]]
        centre = (centre[0], -centre[1])
    return quad, centre


def quad_point(quad, ax, ay):
    """fn_8867D150: point on the quad edge in the stick direction (ax lateral, ay depth)."""
    n = 1.0 / math.sqrt(ax * ax + ay * ay)
    c0, c1, c2, c3 = quad
    if ax * ax > ay * ay:
        s = (ay * n * SQRT2 + 1.0) * 0.5
        a, b = (c1, c3) if ax >= 0.0 else (c0, c2)
    else:
        s = (ax * n * SQRT2 + 1.0) * 0.5
        a, b = (c2, c3) if ay >= 0.0 else (c0, c1)
    return (_lerp(a[0], b[0], s), _lerp(a[1], b[1], s))


def aim_target(cfg, pos_x, pos_z, m, ax, ay, mirror, widen=0.0):
    quad, centre = config_quad(cfg, pos_x, pos_z, m, mirror, widen)
    if abs(ax) <= FLT_EPSILON and abs(ay) <= FLT_EPSILON:
        return centre
    return quad_point(quad, ax, ay)


# ----------------------------------------------------------------------------- output

def write_yaml(configs, out, src_sha, cmd):
    lines = ["# Top Spin 4 aiming tables: Settings.bin cfg+0x108 AimingConfig[25] (docs/gameplay/aiming.md)",
             "# generated by: " + cmd,
             "# source: Settings.bin (Core.arc 334e7e0d) sha256 " + src_sha,
             "# units cm, receiver's half x > 0 (net x = 0), z lateral; corners c0 (short, z-), c1 (short, z+),",
             "# c2 (deep, z-), c3 (deep, z+); quads at QuadEfficiency 0, 0.5, 1, 2 (quad 2 = the court lines)",
             "configs:"]
    for c in configs:
        lines.append("  - index: %d" % c["index"])
        lines.append("    id: %08x" % c["id"])
        lines.append("    name: %s" % (c["name"] or "null"))
        lines.append("    file_offset: 0x%X" % c["offset"])
        lines.append("    volley_distance: %g" % c["volley_distance"])
        lines.append("    baseline_distance: %g" % c["baseline_distance"])
        lines.append("    center_distance: %g" % c["center_distance"])
        lines.append("    side_distance: %g" % c["side_distance"])
        lines.append("    flag_5ed23100: %s" % ("true" if c["flag_5ed23100"] else "false"))
        lines.append("    zones:")
        for zn, z in zip(ZONES, c["zones"]):
            lines.append("      %s:" % zn)
            lines.append("        centre: [%.2f, %.2f]" % (z["centre"][0], z["centre"][2]))
            for k, q in enumerate(z["quads"]):
                pts = ", ".join("[%.2f, %.2f]" % (p[0], p[2]) for p in q)
                lines.append("        quad%d: [%s]" % (k, pts))
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")


def write_tables(configs, out, src_sha, cmd):
    """Flat text for ref/gameplay/aim.c: one line per config."""
    lines = ["# aim tables for ref/gameplay/aim.c, from Settings.bin sha256 " + src_sha,
             "# generated by: " + cmd,
             "# id vd bd cd sd then per zone: centre x z, 4 quads x 4 corners x (x z)"]
    for c in configs:
        vals = ["%08x" % c["id"], "%g" % c["volley_distance"], "%g" % c["baseline_distance"],
                "%g" % c["center_distance"], "%g" % c["side_distance"]]
        for z in c["zones"]:
            vals += ["%.6g" % z["centre"][0], "%.6g" % z["centre"][2]]
            for q in z["quads"]:
                for p in q:
                    vals += ["%.6g" % p[0], "%.6g" % p[2]]
        lines.append(" ".join(vals))
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(lines) + "\n")


def selftest():
    sq = [[(0, 0, -100, 0), (0, 0, 100, 0), (200, 0, -100, 0), (200, 0, 100, 0)]]
    zone = {"centre": (100, 0, 0, 0), "quads": sq * 4}
    cfg = {"center_distance": 0.0, "side_distance": 350.0, "volley_distance": 300.0,
           "baseline_distance": 1300.0, "zones": [zone] * 4}
    assert aim_target(cfg, -1188, -50, 1.0, 0, 0, False) == (100, 0)
    assert aim_target(cfg, -1188, -50, 1.0, 1, 0, False) == (100.0, 100.0)    # right: mid right edge
    assert aim_target(cfg, -1188, -50, 1.0, 0, 1, False) == (200.0, 0.0)      # up: mid deep edge
    p = aim_target(cfg, -1188, -50, 1.0, 1, 1, False)                          # diagonal: deep corner
    assert abs(p[0] - 200) < 1e-3 and abs(p[1] - 100) < 1e-3
    # mirrored half: corners are re-ordered so c1/c3 stay on z+, the stick keeps its sense
    assert aim_target(cfg, -1188, 50, 1.0, 1, 0, True) == (100.0, 100.0)
    assert aim_target(cfg, -1188, 50, 1.0, 0, 0, True) == (100, 0)
    print("aim_tables selftest ok")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--settings")
    ap.add_argument("--out")
    ap.add_argument("--tables")
    ap.add_argument("--selftest", action="store_true")
    a = ap.parse_args(argv)
    if a.selftest:
        return selftest()
    if not a.settings:
        ap.error("--settings is required")
    data = open(a.settings, "rb").read()
    sha = hashlib.sha256(data).hexdigest()
    configs = parse(data)
    cmd = "python3 tools/ts4data/aim_tables.py --settings %s --out %s%s" % (
        a.settings, a.out, (" --tables " + a.tables) if a.tables else "")
    if a.out:
        write_yaml(configs, a.out, sha, cmd)
    if a.tables:
        write_tables(configs, a.tables, sha, cmd)
    if not a.out and not a.tables:
        for c in configs:
            print(c["index"], "%08x" % c["id"], c["name"], c["volley_distance"], c["baseline_distance"],
                  c["side_distance"])
    return 0


if __name__ == "__main__":
    sys.exit(main())
