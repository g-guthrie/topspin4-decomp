#!/usr/bin/env python3
"""Export the in-game (TV) camera shots of Top Spin 4 from a venue archive.

  python3 tools/port/camera_export.py [--iso DISC.iso] [--venue Amsterdam] [--out work/port/assets/cameras]
  python3 tools/port/camera_export.py --summary data/camera          # readable tv_cameras.yaml

Source: `<venue>.arc` member Shots.bin in directory 0x53e083e4 (root type 0x5b3a654f, ShotList/Element[] of CAny),
decoded with the disc's type layouts (Layoutall.bin on the disc root) through tools/ts4_xbin.py.  Each element of type
Pam::CameraEngine::CShotSourceInGameType (crc 0xcfad87d0, 224 bytes, big-endian) is read at fixed offsets:

  +0x04 From xyz (cm)   +0x10 At xyz   +0x1C Up xyz   +0x28 fovA  +0x2C fovB (full angles, radians; tan ratio 4:3)
  +0x60 name string     +0x64 Name crc +0x68 CameraKey
  +0x6C From / +0x70 At / +0x74 Up / +0x78 Fov smooth time (s)    +0x7C Loop (byte; selects the fov pair in code)
  +0x80..+0x8C From/At/Up/Fov smooth max   +0x98 AtLimit.Min xyz  +0xA4 AtLimit.Max xyz  +0xB0 AtLimit.Use (byte)
  +0xC0 PlayerCount  +0xC4 PositionPercent  +0xC8 FarLimit  +0xCC FarLimitMax  +0xD0 SideLimit  +0xD4 SideLimitMax
  +0xD8 fovMaxA  +0xDC fovMaxB

The runtime that consumes these fields is fn_888B4900 (CShotSourceInGame compute; see
docs/port/presentation-and-audio.md and port/web/src/camera_tv.js).  Other shot types are listed by name only.
Standard library only.
"""
import argparse
import hashlib
import json
import os
import struct
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

import ts4_xbin as X  # noqa: E402

SHOTS_DIR = 0x53E083E4
SHOT_TYPES = ["Pam::CameraEngine::CShotSourceInGameType", "Pam::CameraEngine::CShotCutSceneDynamicType",
              "Pam::CameraEngine::CShotAnimatedType", "Pam::CameraEngine::CShotPadType",
              "Pam::CameraEngine::CShotSourceType"]
INGAME = X.crc(SHOT_TYPES[0])
TOOL_VERSION = "camera_export 1"


def decode_ingame(buf, o):
    """Fields of one CShotSourceInGameType at offset o (big-endian)."""
    f = lambda off: struct.unpack_from(">f", buf, o + off)[0]          # noqa: E731
    v = lambda off: [round(x, 4) for x in struct.unpack_from(">3f", buf, o + off)]   # noqa: E731
    r = lambda x: round(x, 6)                                           # noqa: E731
    return {
        "from": v(0x04), "at": v(0x10), "up": v(0x1C), "fov": [r(f(0x28)), r(f(0x2C))],
        "fov_max": [r(f(0xD8)), r(f(0xDC))],
        "smooth_time": {"from": r(f(0x6C)), "at": r(f(0x70)), "up": r(f(0x74)), "fov": r(f(0x78))},
        "smooth_max": {"from": r(f(0x80)), "at": r(f(0x84)), "up": r(f(0x88)), "fov": r(f(0x8C))},
        "loop": buf[o + 0x7C],
        "at_limit": {"min": v(0x98), "max": v(0xA4), "use": buf[o + 0xB0]},
        "player_count": struct.unpack_from(">i", buf, o + 0xC0)[0],
        "position_percent": r(f(0xC4)), "far_limit": r(f(0xC8)), "far_limit_max": r(f(0xCC)),
        "side_limit": r(f(0xD0)), "side_limit_max": r(f(0xD4)),
    }


def shots(buf, layout, names):
    w = X.Walker(buf, layout, names)
    w.walk_file()
    strings = {l.offset: l.value[1] for l in w.leaves if l.tag == "string" and isinstance(l.value, tuple)}
    type_names = {X.crc(n): n.split("::")[-1].replace("Type", "") for n in SHOT_TYPES}
    out = []
    for _path, o, tc in w.objects:
        if tc not in type_names:
            continue
        name = strings.get(o + 0x60) or names.get(struct.unpack_from(">I", buf, o + 0x64)[0]) or ""
        rec = {"name": name, "type": type_names[tc]}
        if tc == INGAME:
            rec.update(decode_ingame(buf, o))
        out.append(rec)
    return out


def read_inputs(args):
    import ts4_arc
    import xdvdfs
    iso = args.iso
    if not iso:
        d = os.path.join(ROOT, "orig/54540859/disc_archive")
        iso = next((os.path.join(d, n) for n in sorted(os.listdir(d)) if n.lower().endswith(".iso")), None)
    x = xdvdfs.XDVDFS(iso)
    layout = x.open_slice("Layoutall.bin").read()
    arc = ts4_arc.Arc(x.open_slice(args.venue + ".arc"))
    key = ts4_arc.child_hash(SHOTS_DIR, "Shots.bin")
    buf = arc.read(arc.find(key))
    return iso, layout, buf, key


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    ap.add_argument("--venue", default="Amsterdam")
    ap.add_argument("--out", default="work/port/assets/cameras")
    ap.add_argument("--summary", metavar="DIR")
    a = ap.parse_args(argv)
    iso, layout, buf, key = read_inputs(a)
    names = X.load_names(os.path.join(ROOT, "work/disc/gameplay/crc_dictionaries.json")
                         if os.path.exists(os.path.join(ROOT, "work/disc/gameplay/crc_dictionaries.json")) else None)
    lst = shots(buf, X.Layout(layout), names)
    src = {"file": a.venue + ".arc", "entry": "%08x" % key, "member": "Shots.bin", "size": len(buf),
           "sha256": hashlib.sha256(buf).hexdigest()}
    lay = {"file": "Layoutall.bin", "size": len(layout), "sha256": hashlib.sha256(layout).hexdigest()}
    if a.summary:
        cmd = "python3 tools/port/camera_export.py --summary %s%s" % (
            a.summary, "" if a.venue == "Amsterdam" else " --venue " + a.venue)
        ing = [s for s in lst if s["type"] == "CShotSourceInGame"]
        lines = [
            "# In-game (TV) camera shots of Top Spin 4 (Xbox 360), %s Shots.bin (directory 0x53e083e4)." % a.venue,
            "# Units: centimetres, radians (fov = full angles; pair = [A, B] with tan(A/2):tan(B/2) = 4:3).",
            "# Consumed by fn_888B4900 (CShotSourceInGame compute); selected by name in fn_888F03B0:",
            "#   \"CameraInGame\" + (Widescreen|Normal) + \"Left\" + (Singles|Doubles) + option suffix; the Right",
            "#   variants mirror x.  See docs/port/presentation-and-audio.md section 2.",
            "# Generated by: " + cmd,
            "# Tool: tools/port/camera_export.py (%s, Python %s, standard library + tools/ts4_xbin.py)" % (
                TOOL_VERSION, sys.version.split()[0]),
            "generator: {command: %s, tool: %s}" % (json.dumps(cmd), json.dumps(TOOL_VERSION)),
            "sources:",
            "  - {file: %s, member: Shots.bin, entry: %s, size: %d, sha256: %s}" % (
                src["file"], src["entry"], src["size"], src["sha256"]),
            "  - {file: Layoutall.bin, size: %d, sha256: %s}" % (lay["size"], lay["sha256"]),
            "options:   # CameraInGame option suffix -> crc32 of the option name stored at matchctx+0x6F8",
            "  TV: 0x1d067e6e", "  TVFar: 0x532d75ec", "  TVClose: 0x84c3a0ed", "  TVZoom: 0xa7d3d87f",
            "  TVZoomFar: 0x402d8125", "  TVZoomClose: 0x242be9ef", "  TV3D: 0x88c0f552",
            "ingame_shots:"]
        for s in ing:
            d = dict(s)
            nm = d.pop("name")
            d.pop("type")
            lines.append("  %s: %s" % (nm, json.dumps(d, separators=(", ", ": "))))
        others = {}
        for s in lst:
            if s["type"] != "CShotSourceInGame":
                others.setdefault(s["type"], []).append(s["name"])
        lines.append("other_shots:")
        for t, ns in sorted(others.items()):
            lines.append("  %s: %s" % (t, json.dumps(ns)))
        os.makedirs(a.summary, exist_ok=True)
        out = os.path.join(a.summary, "tv_cameras.yaml")
        with open(out, "w") as f:
            f.write("\n".join(lines) + "\n")
        print("wrote", out, len(ing), "in-game shots,", len(lst) - len(ing), "others")
        return 0
    out = a.out if os.path.isabs(a.out) else os.path.join(ROOT, a.out)
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, "shots.json"), "w") as f:
        json.dump({"tool": TOOL_VERSION, "generated": time.strftime("%Y-%m-%d"), "venue": a.venue,
                   "sources": [src, lay], "shots": lst}, f, indent=1)
    print("wrote", os.path.join(out, "shots.json"), len(lst), "shots")
    return 0


if __name__ == "__main__":
    sys.exit(main())
