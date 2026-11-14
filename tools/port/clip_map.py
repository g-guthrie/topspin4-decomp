#!/usr/bin/env python3
"""Map the swing AnimationsDB records to the Havok clips that play them (Top Spin 4, Xbox 360).

  python3 tools/port/clip_map.py --iso "orig/54540859/Top Spin 4 (...).iso" [--out work/port/assets]
                                 [--cache work/port/cache] [--no-cutscenes]

Writes <out>/clip_map.json. The mechanism (docs/port/clip-map.md) is the game's own lookup, read from
Swing_DLL fn_886C8438 / fn_886C5230 and checked against the data:

  record (TakeList, 0x8C bytes)  +0x5C poly object
    -> HkxList row index (u16 at poly+0x0C), one per variant
    -> HkxList row (0x1C bytes): u16 +0 = ExtractPositionList index k0 (an AOD clip), u16 +2 = Core container clip
       index c, u16 +4 = k1 (AOD clip appended after the Core clip)
    -> ExtractPositionList[k] u32 +0 = AOD clip id, the file `Media\\Animation\\AOD\\<id>.hkx` (CutScenes.arc)

The record's +0x14 float is the clip length in frames; every mapping is checked against it using the Havok clip's
frame count. Only the standard library plus the repository's own readers (tools/xdvdfs.py, ts4_arc.py, ts4_xbin.py,
tools/havok/) are used. Reads the ISO in place; the game data it derives stays under work/ (git-ignored).
"""
import argparse
import json
import os
import struct
import sys
import time
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
TOOLS = os.path.join(ROOT, "tools")

# AnimationDB root struct starts at file offset 0x14; the three arrays below are 12-byte {rel, count, cap}
# descriptors at these offsets from the root (read from fn_886C8438 / fn_886C5230: root+0x50, +0x60, +0x6C).
ROOT_OFF = 0x14
D_TAKES, D_HKX, D_EXT = 0x50, 0x60, 0x6C
TAKE_SIZE, HKX_SIZE, EXT_SIZE = 0x8C, 0x1C, 0x10

POLY_SINGLE = 0xA0B2A282    # take +0x5C points at the clip object itself (2,444 records)
POLY_SET = 0x2DB2D90F       # {rel, count, cap} + u16 row list: one base clip and additive clips (367)
POLY_LIST = 0xC4BAA666      # {rel, count, cap} + {rel, type} elements, each a POLY_SINGLE object (247)
POLY_BLEND = 0x8361F2CA     # same layout as POLY_LIST, two clips blended (126)
POLY_NAMES = {POLY_SINGLE: "single", POLY_SET: "set", POLY_LIST: "list", POLY_BLEND: "blend"}

AOD_DIR = "/media/animation/aod/"
CORE_ANIMDB = 0x70155255
CORE_DICTS = (0x136BF02A, 0xC6D33A45)
CORE_HAVOK = 0x6932352F
CLIP_COUNT = 5850
EVENT_RACKET = 0x3B9AD22E   # annotation name crc32("EventRacket")


# ------------------------------------------------------------------------------------------------ pure helpers

def _desc(buf, off):
    """12-byte self-relative array descriptor at `off` -> (absolute start, count)."""
    rel, count, _cap = struct.unpack_from(">III", buf, off)
    return off + rel, count


class AnimDb:
    """Views on the three arrays the clip lookup walks."""

    def __init__(self, buf):
        self.buf = buf
        self.takes, self.n_takes = _desc(buf, ROOT_OFF + D_TAKES)
        self.hkx, self.n_hkx = _desc(buf, ROOT_OFF + D_HKX)
        self.ext, self.n_ext = _desc(buf, ROOT_OFF + D_EXT)

    def take(self, i):
        b, o = self.buf, self.takes + TAKE_SIZE * i
        poly_rel, poly_type = struct.unpack_from(">II", b, o + 0x5C)
        return {"index": i, "id": struct.unpack_from(">I", b, o + 0x84)[0],
                "tag": struct.unpack_from(">I", b, o + 0x1C)[0],
                "frames": struct.unpack_from(">f", b, o + 0x14)[0],
                "poly_type": poly_type, "poly": o + 0x5C + poly_rel}

    def annotation_time(self, i, name_crc):
        """Time value of the first annotation called `name_crc` on record i (rows {name crc, f32 time, u32, u32} at
        take +0x64), or None."""
        rel, count, _cap = struct.unpack_from(">III", self.buf, self.takes + TAKE_SIZE * i + 0x64)
        base = self.takes + TAKE_SIZE * i + 0x64 + rel
        for j in range(count):
            crc, t = struct.unpack_from(">If", self.buf, base + 0x10 * j)
            if crc == name_crc:
                return t
        return None

    def row(self, r):
        """(k0, core clip c, k1) of HkxList row r."""
        k0, c, k1 = struct.unpack_from(">3H", self.buf, self.hkx + HKX_SIZE * r)
        return k0, c, k1

    def aod_id(self, k):
        return struct.unpack_from(">I", self.buf, self.ext + EXT_SIZE * k)[0]

    def variant_rows(self, t):
        """HkxList row indices a take refers to, in variant order (fn_886C5230 and the 0x2DB2D90F set)."""
        b, p, typ = self.buf, t["poly"], t["poly_type"]
        if typ == POLY_SINGLE:
            return [struct.unpack_from(">H", b, p + 0x0C)[0]]
        rel, count, _cap = struct.unpack_from(">III", b, p)
        if typ == POLY_SET:
            return list(struct.unpack_from(">%dH" % count, b, p + rel))
        if typ in (POLY_LIST, POLY_BLEND):
            rows = []
            for v in range(count):
                e = p + rel + 8 * v
                target = e + struct.unpack_from(">I", b, e)[0]
                rows.append(struct.unpack_from(">H", b, target + 0x0C)[0])
            return rows
        raise ValueError("unknown poly type %08x" % typ)


def aod_entry_key(clip_id):
    """CutScenes.arc entry key of AOD clip `clip_id`: crc32 of the leaf name continued from the directory hash."""
    dir_hash = zlib.crc32(AOD_DIR.encode("latin-1")) & 0xFFFFFFFF
    return zlib.crc32(("%d.hkx" % clip_id).encode("latin-1"), dir_hash) & 0xFFFFFFFF


def row_source(db, r):
    """Describe what HkxList row r plays: {'kind': 'core'|'aod'|'core+aod', ...}."""
    k0, c, k1 = db.row(r)
    if k0:
        return {"kind": "aod", "row": r, "aod_index": k0, "aod_id": db.aod_id(k0)}
    if k1:
        return {"kind": "core+aod", "row": r, "clip": "core:%d" % c, "core_index": c,
                "aod_index": k1, "aod_id": db.aod_id(k1)}
    return {"kind": "core", "row": r, "clip": "core:%d" % c, "core_index": c}


def source_frames(src, core_frames, aod_frames):
    """Frame count of a row source from the Havok clip tables (None when a table entry is unknown)."""
    parts = []
    if src["kind"] in ("core", "core+aod"):
        parts.append(core_frames.get(src["core_index"]))
    if src["kind"] in ("aod", "core+aod"):
        parts.append(aod_frames.get(src["aod_id"]))
    return None if any(p is None for p in parts) else sum(parts)


def classify(poly_name, srcs, frames_hint, core_frames, aod_frames, core_additive=frozenset()):
    """(method, confidence, primary) for one record from its variant sources.

    confidence: 'exact' the record's frame count equals the Havok frame count of the chain,
                'partial' the chain is decoded but the frame count only agrees for some parts,
                'structural' decoded through the lookup chain, frame table unavailable,
                'mismatch' decoded but the frame count disagrees."""
    fh = int(round(frames_hint))
    fr = [source_frames(s, core_frames, aod_frames) for s in srcs]
    if poly_name == "single":
        s, f = srcs[0], fr[0]
        method = {"core": "hkxlist-core", "aod": "hkxlist-aod", "core+aod": "hkxlist-core+aod"}[s["kind"]]
        conf = "structural" if f is None else ("exact" if f == fh else "mismatch")
        return method, conf, s
    if poly_name == "set":
        # first row is the base clip, the rest are additive layers (11-pose delta clips in the retail data)
        f = fr[0]
        extra_ok = all(s["kind"] == "core" and s["core_index"] in core_additive for s in srcs[1:]) if core_additive else None
        conf = "structural" if f is None else ("exact" if f == fh else "mismatch")
        if conf == "exact" and extra_ok is False:
            conf = "partial"
        return "hkxlist-set", conf, srcs[0]
    if poly_name == "list":
        known = [f for f in fr if f is not None]
        conf = "structural" if not known else ("exact" if all(f == fh for f in known) and len(known) == len(fr)
                                              else ("partial" if any(f == fh for f in known) else "mismatch"))
        return "hkxlist-variants", conf, srcs[0]
    if poly_name == "blend":
        known = [f for f in fr if f is not None]
        mean = sum(known) / len(known) if known else None
        conf = "structural" if not known or len(known) != len(fr) else ("exact" if abs(mean - frames_hint) <= 0.5 else "mismatch")
        return "hkxlist-blend", conf, srcs[0]
    raise ValueError(poly_name)


def build_records(db, names, core_frames, aod_frames, core_additive=frozenset(), aod_names=None):
    """The clip_map records: one per TakeList entry."""
    out = []
    for i in range(db.n_takes):
        t = db.take(i)
        poly = POLY_NAMES[t["poly_type"]]
        rows = db.variant_rows(t)
        srcs = [row_source(db, r) for r in rows]
        for s in srcs:
            if "aod_id" in s:
                s["aod_key"] = "%08x" % aod_entry_key(s["aod_id"])
                if aod_names and s["aod_id"] in aod_names:
                    s["aod_name"] = aod_names[s["aod_id"]]
            f = source_frames(s, core_frames, aod_frames)
            if f is not None:
                s["frames"] = f
        method, conf, primary = classify(poly, srcs, t["frames"], core_frames, aod_frames, core_additive)
        out.append({"index": i, "id": "%08x" % t["id"], "name": names.get(t["id"]), "tag": "%08x" % t["tag"],
                    "poly": poly, "frames": t["frames"], "method": method, "confidence": conf,
                    "primary": primary.get("clip") or ("aod:%d" % primary["aod_id"]), "variants": srcs})
    return out


def exporter_map(records):
    """{'#index': 'core:<n>'} for the records one Core clip plays on its own (what export_assets --clip-map takes)."""
    m = {}
    for r in records:
        v = r["variants"][0]
        if r["confidence"] in ("exact", "structural") and v["kind"] == "core" and r["poly"] in ("single", "set"):
            m["#%d" % r["index"]] = v["clip"]
    return m


def summarize(records):
    by = {}
    for r in records:
        key = "%s/%s/%s" % (r["poly"], r["variants"][0]["kind"] if r["poly"] != "list" else "+".join(
            sorted({v["kind"] for v in r["variants"]})), r["confidence"])
        by[key] = by.get(key, 0) + 1
    conf = {}
    for r in records:
        conf[r["confidence"]] = conf.get(r["confidence"], 0) + 1
    return {"records": len(records), "by_confidence": conf, "by_kind": dict(sorted(by.items()))}


# ------------------------------------------------------------------------------------------------ disc access

def _imports():
    if TOOLS not in sys.path:
        sys.path.insert(0, TOOLS)
    hk = os.path.join(TOOLS, "havok")
    if hk not in sys.path:
        sys.path.insert(0, hk)


def find_iso(explicit=None):
    if explicit:
        return explicit
    import glob
    hits = sorted(glob.glob(os.path.join(ROOT, "orig", "*", "*.iso")))
    return hits[0] if hits else None


def load_core_inputs(iso):
    """(AnimationsDB.bin bytes, {crc: name}, ts4_arc.Arc of Core.arc, xdvdfs.XDVDFS)."""
    _imports()
    import ts4_arc
    import ts4_xbin
    import xdvdfs
    x = xdvdfs.XDVDFS(iso)
    core = ts4_arc.Arc(x.open_slice("Core.arc"))
    db = core.read(core.find(CORE_ANIMDB))
    names = {}
    for h in CORE_DICTS:
        names.update(ts4_xbin.read_crc_dictionary(core.read(core.find(h))))
    return db, names, core, x


def core_clip_table(core, cache, assets):
    """{clip index: {'frames', 'additive', 'codec'}} for the 5,850 Core container clips."""
    ap = os.path.join(assets, "animations.json")
    if os.path.exists(ap):
        with open(ap) as fh:
            clips = json.load(fh).get("clips") or []
        if len(clips) == CLIP_COUNT:
            return {c["index"]: {"frames": c["frames"], "additive": c["additive"], "codec": c["codec"]} for c in clips}
    cp = os.path.join(cache, "core_clip_index.json")
    if os.path.exists(cp):
        with open(cp) as fh:
            return {int(k): v for k, v in json.load(fh).items()}
    _imports()
    os.environ.setdefault("HAVOK_CLASSES", os.path.join(ROOT, "work", "havok", "classes.json"))
    import classes
    import packfile
    import skeleton
    hp = os.path.join(cache, "core_%08x.hkx" % CORE_HAVOK)
    if os.path.exists(hp):
        with open(hp, "rb") as fh:
            data = fh.read()
    else:
        data = core.read(core.find(CORE_HAVOK))
        os.makedirs(cache, exist_ok=True)
        with open(hp, "wb") as fh:
            fh.write(data)
    pf = packfile.Packfile(data)
    reg = classes.Registry.from_packfile(pf)
    _skels, anims = skeleton.load(pf, reg)
    short = {"hkaSplineSkeletalAnimation": "spline", "hkaDeltaCompressedSkeletalAnimation": "delta"}
    table = {}
    for i, (loc, cls, binding) in enumerate(anims):
        obj = reg.read_object(pf, loc[0], loc[1], cls)
        table[i] = {"frames": obj.get("numFrames", obj.get("numberOfPoses")), "codec": short.get(cls, cls),
                    "additive": bool(binding and binding["blendHint"] == "ADDITIVE")}
    os.makedirs(cache, exist_ok=True)
    with open(cp, "w") as fh:
        json.dump(table, fh)
    return table


def cutscene_table(x, cache, log=print):
    """{AOD clip entry key: {'frames', 'duration', 'codec', 'tracks'}} for every CutScenes.arc clip (cached)."""
    cp = os.path.join(cache, "cutscene_meta.json")
    if os.path.exists(cp):
        with open(cp) as fh:
            return {int(k): v for k, v in json.load(fh).items()}
    _imports()
    os.environ.setdefault("HAVOK_CLASSES", os.path.join(ROOT, "work", "havok", "classes.json"))
    import classes
    import packfile
    from scan_arcs import NilArc
    f = x.open_slice("CutScenes.arc")
    arc = NilArc(f)
    reg = None
    out = {}
    t0 = time.time()
    for n, e in enumerate(arc.entries):
        f.seek(arc.data_start + e[1])
        pf = packfile.Packfile(f.read(e[2]))
        reg = reg or classes.Registry.from_packfile(pf)
        for cls, codec in (("hkaWaveletSkeletalAnimation", "wavelet"), ("hkaSplineSkeletalAnimation", "spline")):
            objs = pf.objects(cls)
            if objs:
                o = reg.read_object(pf, objs[0][0], objs[0][1], cls)
                out[e[0]] = {"frames": o.get("numberOfPoses", o.get("numFrames")), "duration": float(o["duration"]),
                             "codec": codec, "tracks": o.get("numberOfTransformTracks")}
                break
        if n % 300 == 0:
            log("    cutscene clip headers %d/%d (%.0f s)" % (n, len(arc.entries), time.time() - t0))
    os.makedirs(cache, exist_ok=True)
    with open(cp, "w") as fh:
        json.dump({str(k): v for k, v in out.items()}, fh)
    return out


def median(xs):
    xs = sorted(xs)
    n = len(xs)
    return None if not n else (xs[n // 2] if n % 2 else 0.5 * (xs[n // 2 - 1] + xs[n // 2]))


def peak_phase(positions):
    """Phase (0..1 of the clip) at which a point moving through `positions` (one xyz per frame) is fastest, with the
    speeds smoothed over three steps."""
    n = len(positions)
    if n < 3:
        return None
    sp = [sum((a - b) ** 2 for a, b in zip(positions[i], positions[i + 1])) ** 0.5 for i in range(n - 1)]
    sm = [sum(sp[max(0, i - 1):i + 2]) / len(sp[max(0, i - 1):i + 2]) for i in range(len(sp))]
    k = max(range(len(sm)), key=lambda i: sm[i])
    return (k + 0.5) / (n - 1)


def racket_check(db, records, core, cache, sample, seed=1):
    """Independent check of the mapping: the record's EventRacket value should be the phase at which the racket handle
    is fastest in its clip. Compares the median |difference| for the mapped clips with that of random pairings.
    Needs the Havok class table (work/havok/classes.json) and decodes `sample` spline clips (about 0.6 s each)."""
    import random
    _imports()
    os.environ.setdefault("HAVOK_CLASSES", os.path.join(ROOT, "work", "havok", "classes.json"))
    import classes
    import packfile
    import skeleton
    with open(os.path.join(cache, "core_%08x.hkx" % CORE_HAVOK), "rb") as fh:
        pf = packfile.Packfile(fh.read())
    reg = classes.Registry.from_packfile(pf)
    skels, anims = skeleton.load(pf, reg)
    sk = skels[0]
    rb = sk.bones.index("B_Racket_Handle")
    cands = [r for r in records if r["poly"] == "single" and r["variants"][0]["kind"] == "core"
             and r["confidence"] == "exact" and (r["name"] or "").startswith("Swing")]
    rnd = random.Random(seed)
    rnd.shuffle(cands)
    contact, peak = [], []
    for r in cands:
        if len(contact) >= sample:
            break
        t = db.annotation_time(r["index"], EVENT_RACKET)
        if t is None:
            continue
        ci = r["variants"][0]["core_index"]
        clip = skeleton.load_clip(pf, reg, anims[ci], ci)
        pos = []
        for f in range(len(clip.frames)):
            m = sk.world_matrices(clip.bone_pose(sk, f))[rb]
            pos.append((m[12], m[13], m[14]))
        ph = peak_phase(pos)
        if ph is not None:
            contact.append(t)
            peak.append(ph)
    null = []
    for _ in range(200):
        p = peak[:]
        rnd.shuffle(p)
        null.append(median([abs(a - b) for a, b in zip(contact, p)]))
    return {"records": len(contact), "median_abs_phase_error": median([abs(a - b) for a, b in zip(contact, peak)]),
            "shuffled_median_of_medians": median(null), "shuffled_min": min(null) if null else None}


# ------------------------------------------------------------------------------------------------ driver

def build(iso, assets, cache, cutscenes=True, log=print, racket_sample=0):
    db_bytes, names, core, x = load_core_inputs(iso)
    db = AnimDb(db_bytes)
    log("AnimationsDB: %d records, %d HkxList rows, %d ExtractPositionList entries" % (db.n_takes, db.n_hkx, db.n_ext))
    ctab = core_clip_table(core, cache, assets)
    core_frames = {i: v["frames"] for i, v in ctab.items()}
    core_additive = frozenset(i for i, v in ctab.items() if v["additive"])
    aod_frames, aod_present = {}, set()
    ids = sorted({db.aod_id(k) for k in range(1, db.n_ext)})
    if cutscenes:
        cs = cutscene_table(x, cache, log)
        for cid in ids:
            m = cs.get(aod_entry_key(cid))
            if m:
                aod_frames[cid] = m["frames"]
                aod_present.add(cid)
        cs_keys = set(cs)
    else:
        cs_keys = set()
    aod_names = {cid: names[cid] for cid in ids if cid in names}
    records = build_records(db, names, core_frames, aod_frames, core_additive, aod_names)
    used_core = {v["core_index"] for r in records for v in r["variants"] if "core_index" in v}
    used_aod = {v["aod_id"] for r in records for v in r["variants"] if "aod_id" in v}
    summary = summarize(records)
    summary.update({
        "core_clips": len(ctab), "core_clips_referenced": len(used_core),
        "aod_clips_in_db": len(ids), "aod_clips_referenced": len(used_aod),
        "aod_files_found": len(aod_present) if cutscenes else None,
        "cutscene_files_total": len(cs_keys) if cutscenes else None,
        "cutscene_files_unreferenced": (len(cs_keys - {aod_entry_key(c) for c in ids}) if cutscenes else None),
    })
    if racket_sample:
        summary["racket_check"] = racket_check(db, records, core, cache, racket_sample)
    doc = {"schema": 1, "tool": "tools/port/clip_map.py",
           "notes": {"map": "{'#<record index>': 'core:<n>'}: records one Core container clip plays on its own; use with "
                            "export_assets.py --clip-map auto. Records that play AOD files or a Core clip plus an AOD "
                            "file are in 'records' only.",
                     "aod": "AOD clip ids are CutScenes.arc leaf names '<id>.hkx' ('aod_key' = the archive entry key).",
                     "frames": "record 'frames' is the +0x14 float of the AnimationsDB record, equal to the Havok frame count"},
           "summary": summary, "map": exporter_map(records), "records": records}
    return doc


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", help="disc image (default: first orig/*/*.iso)")
    ap.add_argument("--out", default=os.path.join(ROOT, "work", "port", "assets"), help="assets dir (clip_map.json goes here)")
    ap.add_argument("--cache", default=os.path.join(ROOT, "work", "port", "cache"))
    ap.add_argument("--no-cutscenes", action="store_true",
                    help="skip reading the 2,093 CutScenes clip headers (first run takes minutes; then frame checks of "
                         "AOD parts are 'structural')")
    ap.add_argument("--verify-racket", type=int, default=0, metavar="N",
                    help="also decode N single-clip swings and compare EventRacket with the racket-handle speed peak")
    a = ap.parse_args(argv)
    iso = find_iso(a.iso)
    if not iso or not os.path.exists(iso):
        print("no disc image: pass --iso", file=sys.stderr)
        return 2
    doc = build(iso, os.path.abspath(a.out), os.path.abspath(a.cache), cutscenes=not a.no_cutscenes, racket_sample=a.verify_racket)
    os.makedirs(a.out, exist_ok=True)
    path = os.path.join(a.out, "clip_map.json")
    with open(path, "w") as fh:
        json.dump(doc, fh, separators=(",", ":"))
    print(json.dumps(doc["summary"], indent=1))
    print("wrote %s (%d exporter links)" % (path, len(doc["map"])))
    return 0


if __name__ == "__main__":
    sys.exit(main())
