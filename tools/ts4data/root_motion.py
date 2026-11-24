#!/usr/bin/env python3
"""Root motion (extracted root displacement) of every Top Spin 4 animation, per frame (agent G9).

    python3 -I tools/ts4data/root_motion.py --core work/disc/core_all [--out data/gameplay/root_motion.yaml]
    python3 -I tools/ts4data/root_motion.py --core work/disc/core_all --clip Sidesteps_Right     # one clip, per frame

Where the game keeps root motion (read from code, Swing_DLL.dll):

  * The Havok clips carry no extracted motion (docs/havok.md s3).  The root track is a separate 2-D table in
    AnimationsDB.bin (Core.arc 70155255, root object at file offset 0x14):
        root+0x50  Animations   (0x8C records)       record+0x5C {rel, poly type}: the clip object(s);
                                                      clip object +0x0C (u16) = RTTake row
        root+0x60  RTTakeList   (0x1C rows)          +0x0C ExtractPosition_IndexBegin (u32),
                                                      +0x10 ExtractPosition_SampleCountMinusOne (f32) N,
                                                      +0x14 XStart, +0x18 ZStart (f32)
        root+0x78  ExtractPositionList (8-byte rows) {X, Z} in cm, clip-local (+X forward, +Z to the left)
    (member names from Layoutall.bin through tools/ts4data/ps_layout.py --type ee710815; docs/port/clip-map.md
    calls RTTakeList "HkxList" and HkxList "ExtractPositionList".)
  * fn_8864A770 stores root+0x78 at animset+0xAC; fn_886455A0 passes RTTake row (animset+0xA8 -> +8 -> +0x60) to
  * fn_88644CE8(table, row, t0, t1): for each phase t (0..1) it takes u = t*N, i = trunc(u), f = u - i and
    P(t) = (1-f) E[begin+i] + f E[begin+i+1]; it returns P(t1) - P(t0) (x and z separately).
  * fn_886457E0 sums those deltas over the active clip list, each rotated by the entry's yaw (+0x10, sin/cos by
    polynomial) and scaled by its blend weight (+0x14) times the set scale (+0x24): the root moves by the blend of
    the playing clips' root tracks.
  * Phase to frame: fn_886D1408 maps a phase to (phase - t0)(FrameCount - 1) frames, so frame k of a clip played at
    rate 1 is phase k / (FrameCount - 1).

Output (data/gameplay/root_motion.yaml, readable summaries only, no raw sample table):
  locomotion clips: per-frame cumulative root position [x, z] (cm, 0.1 cm), plus distance milestones;
  swing clips: contact frame, Out-window frame and the root travel before contact, from contact to the Out window,
  after it, and the root speed at contact and at the window.
Standard library only.
"""
from __future__ import annotations

import argparse
import hashlib
import math
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))

ANIMDB = "70155255"
ANIMDB_CRC = "136bf02a"
ROOT = 0x14
REC_SIZE, RT_SIZE = 0x8C, 0x1C
POLY_SINGLE, POLY_SET, POLY_LIST, POLY_BLEND = 0xA0B2A282, 0x2DB2D90F, 0xC4BAA666, 0x8361F2CA
POLY_NAMES = {POLY_SINGLE: "single", POLY_SET: "set", POLY_LIST: "list", POLY_BLEND: "blend"}
SETUP = {0x3583143C: "Men", 0xDDDB885D: "Women"}
EVENT_RACKET = zlib.crc32(b"EventRacket")
CYCLE_IN, CYCLE_OUT = zlib.crc32(b"Cycle_In"), zlib.crc32(b"Cycle_Out")

LOCOMOTION = re.compile(r"^(Idle|Tr|Sidesteps|Jog|Rush|Steps|Backsteps|Stand|Splitsteps|Walk|Baseline_Wait|"
                        r"Volley_Wait|Smash_(FH|BH)_(Front|Back|Left|Right|Stand|Jump))")
SWING = re.compile(r"^(Swing|Smash)")
MILESTONES = (5.0, 25.0, 100.0)


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def desc(buf, off):
    """Self-relative array descriptor {rel, count, cap} at `off` -> (first element offset, count)."""
    rel, count, _cap = struct.unpack_from(">III", buf, off)
    return off + rel, count


class AnimDb:
    def __init__(self, buf):
        self.buf = buf
        self.recs, self.n_recs = desc(buf, ROOT + 0x50)
        self.rt, self.n_rt = desc(buf, ROOT + 0x60)
        self.ext, self.n_ext = desc(buf, ROOT + 0x78)

    def record(self, i):
        b, o = self.buf, self.recs + REC_SIZE * i
        poly_rel, poly_type = struct.unpack_from(">II", b, o + 0x5C)
        rec = {"index": i, "offset": o, "id": struct.unpack_from(">I", b, o + 0x84)[0],
               "frames": struct.unpack_from(">f", b, o + 0x14)[0],
               "speed_coef": struct.unpack_from(">f", b, o + 0x18)[0],
               "setup": SETUP.get(struct.unpack_from(">I", b, o + 0x1C)[0], "?"),
               "ignore_speed_coef": b[o + 0x2D],
               "poly_type": poly_type, "poly": o + 0x5C + poly_rel}
        rec["rows"] = self.rows(rec)
        rec["events"] = self.anim_events(o)
        rec["transitions"] = self.transition_events(o)
        return rec

    def rows(self, rec):
        """RTTake rows of a record in variant order (same walk as tools/port/clip_map.py)."""
        b, p, typ = self.buf, rec["poly"], rec["poly_type"]
        if typ == POLY_SINGLE:
            return [struct.unpack_from(">H", b, p + 0x0C)[0]]
        rel, count, _cap = struct.unpack_from(">III", b, p)
        if typ == POLY_SET:
            return list(struct.unpack_from(">%dH" % count, b, p + rel))
        rows = []
        for v in range(count):
            e = p + rel + 8 * v
            rows.append(struct.unpack_from(">H", b, e + struct.unpack_from(">I", b, e)[0] + 0x0C)[0])
        return rows

    def anim_events(self, o):
        """AnimEventList (record +0x64): [(id crc, phase, duration)]."""
        base, n = desc(self.buf, o + 0x64)
        return [struct.unpack_from(">Iff", self.buf, base + 0x10 * k) for k in range(n)]

    def transition_events(self, o):
        """TransitionEventList (record +0x70), 0x28-byte rows (movement-and-animation s2.2)."""
        base, n = desc(self.buf, o + 0x70)
        out = []
        for k in range(n):
            e = base + 0x28 * k
            cyc, bcyc, dmask, pmask, pos, dur, dcyc, react, sblend = struct.unpack_from(">ffIIfffff", self.buf, e)
            out.append({"direction": dmask, "pace": pmask, "position": pos, "duration": dur,
                        "in": self.buf[e + 0x24], "out": self.buf[e + 0x25]})
        return out

    def rttake(self, r):
        main_h, main_s, split_h, split_s, split_pos, begin, n, xs, zs = struct.unpack_from(
            ">hhhhfIfff", self.buf, self.rt + RT_SIZE * r)
        return {"row": r, "begin": begin, "n": n, "x_start": xs, "z_start": zs, "split_pos": split_pos}

    def sample(self, take, t):
        """Root position at phase t, exactly as fn_88644CE8 interpolates (index clamped to the take)."""
        n = take["n"]
        u = t * n
        i = int(u)                      # fctidz: truncation toward zero
        f = u - i
        i = max(0, min(i, int(n)))
        j = min(i + 1, int(n))
        x0, z0 = struct.unpack_from(">ff", self.buf, self.ext + 8 * (take["begin"] + i))
        x1, z1 = struct.unpack_from(">ff", self.buf, self.ext + 8 * (take["begin"] + j))
        return (1.0 - f) * x0 + f * x1, (1.0 - f) * z0 + f * z1


def per_frame(db, rec, row=None):
    """Cumulative root position [x, z] at each frame 0..FrameCount-1 at play rate 1 (frame k = phase k/(F-1))."""
    take = db.rttake(rec["rows"][0] if row is None else row)
    frames = int(round(rec["frames"]))
    if take["n"] <= 0 or frames < 2:
        return [(0.0, 0.0)] * max(frames, 1)
    return [db.sample(take, k / (frames - 1)) for k in range(frames)]


def milestones(track, start=0, dist=MILESTONES):
    """Frames after `start` until the root is first >= d cm from its position at `start` (None if never)."""
    x0, z0 = track[start]
    out = []
    for d in dist:
        hit = None
        for k in range(start, len(track)):
            if math.hypot(track[k][0] - x0, track[k][1] - z0) >= d:
                hit = k - start
                break
        out.append(hit)
    return out


def speed(track, k):
    """Root speed at frame k in cm/frame (central difference)."""
    a, b = max(0, k - 1), min(len(track) - 1, k + 1)
    if b == a:
        return 0.0
    return math.hypot(track[b][0] - track[a][0], track[b][1] - track[a][1]) / (b - a)


def entry_frame(rec):
    """Frame of TransitionEvent[0].Position (the In window a rule with DestEventIndex 0 enters), or 0."""
    tr = rec["transitions"]
    if tr and tr[0]["in"]:
        return int(round(tr[0]["position"] * (rec["frames"] - 1)))
    return 0


def out_frame(rec):
    """Frame at which the first Out-only TransitionEvent opens (swing exit window), or None."""
    for e in rec["transitions"]:
        if e["out"] and not e["in"]:
            return e["position"] * (rec["frames"] - 1)
    for e in rec["transitions"][1:]:
        if e["out"]:
            return e["position"] * (rec["frames"] - 1)
    return None


def event_phase(rec, crc):
    for i, p, _d in rec["events"]:
        if i == crc:
            return p
    return None


def load_names(core):
    names = {}
    p = os.path.join(core, ANIMDB_CRC + ".bin")
    if os.path.exists(p):
        import ts4_xbin as X  # noqa: E402 - optional dictionary reader
        names.update(X.read_crc_dictionary(open(p, "rb").read()))
    return names


def fmt(v, nd=1):
    if v is None:
        return "null"
    if isinstance(v, float):
        s = ("%." + str(nd) + "f") % v
        return "0.0" if s in ("-0.0", "-0.00") else s
    return str(v)


def dump(db, names, sources, cmd, out):
    loco, swing = [], []
    for i in range(db.n_recs):
        rec = db.record(i)
        rec["name"] = names.get(rec["id"], "%08x" % rec["id"])
        if rec["setup"] != "Men":   # Women clips repeat the Men clips (same RTTake rows); checked below
            continue
        if LOCOMOTION.match(rec["name"]) and not SWING.match(rec["name"]):
            loco.append(rec)
        elif SWING.match(rec["name"]):
            swing.append(rec)
    w = out.write
    w("# Top Spin 4 root motion per clip (agent G9).  Readable summary: no raw sample table.\n")
    w("# Generated by: %s\n" % cmd)
    w("# Code: fn_88644CE8 (sampling), fn_886455A0 / fn_886457E0 (blend of the playing clips), fn_8864A770 (table).\n")
    w("# Units: cm, frames at 60 Hz, play rate 1 (multiply frame counts by 1/rate).  Axes: clip-local, +x forward,\n")
    w("# +z to the player's left (Jog_Front moves +x, Sidesteps_Right moves -z).  Men setup; the Women records have\n")
    w("# their own rows with nearly the same travel (women_vs_men_locomotion_travel below).\n")
    w("generated_by: %s\n" % cmd)
    w("sources_sha256:\n")
    for k, (size, h) in sources.items():
        w("  %s: {size: %d, sha256: %s}\n" % (k, size, h))
    # Women vs Men: the Women records have their own RTTake rows; compare the root travel of same-name clips
    men = {}
    for i in range(db.n_recs):
        rec = db.record(i)
        if rec["setup"] == "Men":
            men[names.get(rec["id"])] = rec
    ratios = []
    for i in range(db.n_recs):
        rec = db.record(i)
        nm = names.get(rec["id"])
        if rec["setup"] == "Women" and nm in men and LOCOMOTION.match(nm or ""):
            a, b = per_frame(db, men[nm]), per_frame(db, rec)
            da, dw = math.hypot(*a[-1]), math.hypot(*b[-1])
            if len(a) == len(b) and da > 50:
                ratios.append(dw / da)
    if ratios:
        w("women_vs_men_locomotion_travel: {clips: %d, min_ratio: %.3f, max_ratio: %.3f}\n" % (
            len(ratios), min(ratios), max(ratios)))
    w("fields:\n")
    w("  entry: frame of TransitionEvent[0].Position (where an Allow rule with DestEventIndex 0 enters the clip)\n")
    w("  to_cm_from_0: frames from clip frame 0 until the root is 5 / 25 / 100 cm away\n")
    w("  to_cm_from_entry: the same counted from the entry frame\n")
    w("  cycle_speed: mean root speed between Cycle_In and Cycle_Out in cm/frame (x 0.6 = m/s)\n")
    w("  xz: cumulative root position at every frame 0..frames-1\n")
    w("  variant1_*: 'blend' records (Element<Blend>) hold two RTTake rows played on one clock (the record's frame\n")
    w("    count); xz is row 0 (slow variant), variant1_xz row 1 (fast).  The blended root is (1-w) row0 + w row1 (I).\n")
    w("locomotion:\n")
    for rec in loco:
        tr = per_frame(db, rec)
        e = entry_frame(rec)
        ci, co = event_phase(rec, CYCLE_IN), event_phase(rec, CYCLE_OUT)
        cyc = None
        if ci is not None and co is not None and co > ci:
            a, b = int(round(ci * (rec["frames"] - 1))), int(round(co * (rec["frames"] - 1)))
            if b > a:
                d = sum(math.hypot(tr[k + 1][0] - tr[k][0], tr[k + 1][1] - tr[k][1]) for k in range(a, b))
                cyc = d / (b - a)
        take = db.rttake(rec["rows"][0])
        w("  - name: %s\n" % yq(rec["name"]))
        w("    i: %d\n    frames: %d\n    poly: %s\n    rttake: %d\n    samples: %d\n" % (
            rec["index"], int(round(rec["frames"])), POLY_NAMES[rec["poly_type"]], take["row"], int(take["n"]) + 1))
        w("    speed_coef: %s\n    ignore_speed_coef: %d\n" % (fmt(rec["speed_coef"], 3), rec["ignore_speed_coef"]))
        w("    total: [%s, %s]\n" % (fmt(tr[-1][0]), fmt(tr[-1][1])))
        w("    entry: %d\n" % e)
        w("    to_cm_from_0: [%s]\n" % ", ".join(fmt(v) for v in milestones(tr, 0)))
        w("    to_cm_from_entry: [%s]\n" % ", ".join(fmt(v) for v in milestones(tr, min(e, len(tr) - 1))))
        w("    cycle_speed: %s\n" % fmt(cyc, 2))
        w("    xz: [%s]\n" % ", ".join("[%s, %s]" % (fmt(x), fmt(z)) for x, z in tr))
        if rec["poly_type"] == POLY_BLEND and len(rec["rows"]) > 1:
            tf = per_frame(db, rec, rec["rows"][1])
            w("    variant1_rttake: %d\n" % rec["rows"][1])
            w("    variant1_total: [%s, %s]\n" % (fmt(tf[-1][0]), fmt(tf[-1][1])))
            w("    variant1_to_cm_from_entry: [%s]\n" % ", ".join(fmt(v) for v in milestones(tf, min(e, len(tf) - 1))))
            w("    variant1_xz: [%s]\n" % ", ".join("[%s, %s]" % (fmt(x), fmt(z)) for x, z in tf))
    w("# Swing clips: contact = EventRacket frame; out = first Out-only TransitionEvent (exit window) frame.\n")
    w("# travel_*: root distance (cm) from frame 0 to contact, contact to out, out to the last frame;\n")
    w("# v_contact / v_out: root speed (cm/frame) at contact and at the window.\n")
    w("swing:\n")
    for rec in swing:
        tr = per_frame(db, rec)
        cp = event_phase(rec, EVENT_RACKET)
        c = None if cp is None else cp * (rec["frames"] - 1)
        o = out_frame(rec)
        def dist(a, b):
            if a is None or b is None:
                return None
            a, b = int(round(a)), int(round(b))
            a, b = max(0, min(a, len(tr) - 1)), max(0, min(b, len(tr) - 1))
            return math.hypot(tr[b][0] - tr[a][0], tr[b][1] - tr[a][1])
        w("  - {name: %s, i: %d, frames: %d, ignore_speed_coef: %d, contact: %s, out: %s, travel_to_contact: %s, "
          "travel_contact_out: %s, travel_after_out: %s, v_contact: %s, v_out: %s, total: [%s, %s]}\n" % (
              yq(rec["name"]), rec["index"], int(round(rec["frames"])), rec["ignore_speed_coef"], fmt(c), fmt(o),
              fmt(dist(0, c)), fmt(dist(c, o)), fmt(dist(o, len(tr) - 1)),
              fmt(None if c is None else speed(tr, int(round(c))), 2),
              fmt(None if o is None else speed(tr, min(int(round(o)), len(tr) - 1)), 2),
              fmt(tr[-1][0]), fmt(tr[-1][1])))
    return len(loco), len(swing)


def yq(s):
    return '"%s"' % s.replace('"', '\\"') if re.search(r"[:#\[\]{},&*!|>'\"%@`]|^\s|\s$|^-", s) else s


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--core", default="work/disc/core_all")
    ap.add_argument("--out", default="data/gameplay/root_motion.yaml")
    ap.add_argument("--clip", help="print one clip (name) per frame instead of writing the YAML")
    a = ap.parse_args(argv)
    buf = open(os.path.join(a.core, ANIMDB + ".bin"), "rb").read()
    db = AnimDb(buf)
    names = load_names(a.core)
    if a.clip:
        for i in range(db.n_recs):
            rec = db.record(i)
            if names.get(rec["id"]) == a.clip and rec["setup"] == "Men":
                tr = per_frame(db, rec)
                print("# %s  record %d  frames %d  rows %s  events %s" % (a.clip, i, rec["frames"], rec["rows"],
                      [(names.get(k, "%08x" % k), round(p, 4)) for k, p, _ in rec["events"]]))
                for t in rec["transitions"]:
                    print("# transition", t)
                for k, (x, z) in enumerate(tr):
                    print("%4d %8.2f %8.2f %6.2f" % (k, x, z, speed(tr, k)))
                return 0
        print("clip not found", file=sys.stderr)
        return 1
    cmd = "python3 -I tools/ts4data/root_motion.py " + " ".join(argv if argv is not None else sys.argv[1:])
    sources = {"AnimationsDB.bin (Core.arc 70155255)": (len(buf), sha256(buf))}
    crc = os.path.join(a.core, ANIMDB_CRC + ".bin")
    if os.path.exists(crc):
        cb = open(crc, "rb").read()
        sources["AnimationsDBcrc.bin (Core.arc 136bf02a)"] = (len(cb), sha256(cb))
    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    with open(a.out, "w") as o:
        nl, ns = dump(db, names, sources, cmd.strip(), o)
    print("%s: %d locomotion clips, %d swing clips, %d bytes" % (a.out, nl, ns, os.path.getsize(a.out)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
