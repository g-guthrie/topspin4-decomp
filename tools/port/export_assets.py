#!/usr/bin/env python3
"""Export a web-ready asset folder for the Top Spin 4 browser port from the user's own disc image.

  python3 tools/port/export_assets.py --iso "orig/54540859/Top Spin 4 (...).iso" \
      [--dll orig/54540859/Swing_DLL.dll] [--out work/port/assets] [--core-clips 0-31]

Everything is written below --out (default work/port/assets, git-ignored) and nothing from the game is ever
committed or hosted: the viewer in port/web/ loads this folder from a local web server.

Parts (each is optional; a part whose dependency is missing is skipped with a message, the rest still run):

  havok     player skeleton(s) as glTF (skeletons/player_<n>.gltf) and the selected Core.arc animation clips as
            glTF (clips/core_<index>.gltf, one animation each, bone names identical to the skeleton).
            Needs work/havok/classes.json; it is generated from --dll (Swing_DLL.dll) with tools/havok/dll_classes.py
            when missing.
  animdb    animations.json: the clip index (every Core clip: codec, duration, frames, tracks, exported file) and the
            3,184 swing AnimationsDB records (name, slot, EventRacket contact marker, annotations). The link from a
            record to a Havok clip is not established (docs/havok.md section 8); --clip-map FILE supplies one.
  gameplay  gameplay/shots.json (shot-template rows decoded from Settings.bin/State.bin + ball defaults),
            gameplay/analyser.json (analyser graphs from Expressions.bin) and gameplay/ts4core.dat, the data blob
            ts4core loads (docs/port/data-format.md; written by tools/port/blob_writer.py: TPLS, TREE, GRPH, TUNE;
            ROLE and CURV are not written yet).
  meshes    venue/player meshes and textures, delegated to the assets agent's tools/ts4_assets.py when it exists.

manifest.json at the root of --out lists what was produced, with sizes, so the viewer can degrade gracefully.
Standard library only (plus the repository's own tools). Reads the ISO in place; never modifies it.
"""
import argparse
import glob
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
TOOLS = os.path.join(ROOT, "tools")
if TOOLS not in sys.path:
    sys.path.insert(0, TOOLS)

CORE_HAVOK_ENTRY = 0x6932352F          # Core.arc "Merged Animation Container" (docs/havok.md section 1)
KNOWN_CORE_ENTRIES = {                 # Core.arc entry hashes, used when the leaf-name table does not resolve
    "Settings.bin": 0x334E7E0D, "State.bin": 0x623D0979, "Expressions.bin": 0xFA94F637,
    "AnimationsDB.bin": 0x70155255, "AnimationsDBcrc.bin": 0x136BF02A, "CommonCRCDictionnary.bin": 0xC6D33A45,
}
EVENT_RACKET = 0x3B9AD22E              # annotation name hash (docs/gameplay/df.md 3.2)
PREPARATION = 0x7F6C2523
STATE_BALL_BLOCK = 0x964               # State.bin: default ball block (docs/gameplay/shot-templates.md section 2)
BALL_DEFAULTS = {"radius_cm": 4.0, "a4": 0.06, "g": 9.81, "max_bounces": 5, "net_height_cm": 91.4,
                 "net_height_source": "assumed (ITF centre strap 91.4 cm); not read from game data"}
PARTS = ("havok", "animdb", "gameplay", "meshes")


# ------------------------------------------------------------------------------------------------ pure helpers

def parse_clip_spec(spec, n):
    """'all', 'none', or a list such as '0,1,5-9' -> sorted unique indices below n (out of range values are dropped)."""
    spec = (spec or "").strip().lower()
    if spec in ("", "none"):
        return []
    if spec == "all":
        return list(range(n))
    out = set()
    for part in spec.split(","):
        part = part.strip()
        if not part:
            continue
        m = re.fullmatch(r"(\d+)-(\d+)", part)
        if m:
            lo, hi = int(m.group(1)), int(m.group(2))
            if hi < lo:
                raise ValueError("bad range %r" % part)
            out.update(range(lo, hi + 1))
        elif part.isdigit():
            out.add(int(part))
        else:
            raise ValueError("bad clip spec element %r" % part)
    return sorted(i for i in out if 0 <= i < n)


class Budget:
    """Tracks bytes written against a limit so a large export cannot fill the disk."""

    def __init__(self, limit_bytes):
        self.limit = limit_bytes
        self.used = 0

    def add(self, nbytes):
        self.used += nbytes

    @property
    def exhausted(self):
        return self.limit is not None and self.used >= self.limit


def contact_markers(annotations):
    """Pick the racket-contact and preparation times out of an AnimationsDB record's annotations.

    annotations: [{"name": str, "time": float}, ...] where name is the resolved string or the 8 hex digit hash.
    Returns {"contact": float|None, "preparation": float|None, "events": [{"name", "time"}...]} with events sorted
    by time. The time unit is NOT established: in the retail data every EventRacket value lies in 0.06-0.68, which
    reads as a normalised clip phase (docs/port/web.md); the viewer converts using the clip duration."""
    contact = prep = None
    events = []
    for a in annotations or []:
        name = str(a.get("name", ""))
        t = a.get("time")
        if t is None:
            continue
        events.append({"name": name, "time": float(t)})
        key = name.lower()
        if key in ("eventracket", "%08x" % EVENT_RACKET) and contact is None:
            contact = float(t)
        elif key in ("preparation", "%08x" % PREPARATION) and prep is None:
            prep = float(t)
    events.sort(key=lambda e: e["time"])
    return {"contact": contact, "preparation": prep, "events": events}


def swing_tags(name):
    """Searchable tags from a swing animation name such as Swing_FH_Slice_Power_Jog_Right_Medium_GoodPos_Waist."""
    return [t for t in (name or "").split("_") if t]


def build_animation_records(takes):
    """AnimationsDB takes (tools/ts4_extract.decode_animation_db()['takes']) -> compact viewer records."""
    out = []
    for r in takes:
        m = contact_markers(r.get("annotations"))
        segs = r.get("segments") or []
        out.append({
            "index": r["index"], "id": r["id"], "name": r.get("name"), "slot": r.get("slot"),
            "tags": swing_tags(r.get("name")),
            "contact": m["contact"], "preparation": m["preparation"], "events": m["events"],
            "length_hint": r.get("f14"),
            "segment_times": [s.get("f10") for s in segs],
            "clip": None,
        })
    return out


def link_records(records, clip_ids, clip_map):
    """Apply a user supplied {record name | 8-hex id | 'record index' : 'core:<index>'} map. Returns the link count."""
    n = 0
    valid = set(clip_ids)
    for rec in records:
        for key in (rec.get("name"), rec["id"], "#%d" % rec["index"]):
            if key is not None and key in clip_map and clip_map[key] in valid:
                rec["clip"] = clip_map[key]
                n += 1
                break
    return n


def clip_summary(obj, cls, blend_hint, index, exported=None):
    """One animations.json clip row from a decoded hka*Animation object dict."""
    frames = obj.get("numFrames", obj.get("numberOfPoses"))
    short = {"hkaSplineSkeletalAnimation": "spline", "hkaDeltaCompressedSkeletalAnimation": "delta",
             "hkaWaveletSkeletalAnimation": "wavelet", "hkaInterleavedSkeletalAnimation": "interleaved"}
    return {"id": "core:%d" % index, "index": index, "codec": short.get(cls, cls),
            "duration": round(float(obj["duration"]), 6), "frames": frames,
            "tracks": obj.get("numberOfTransformTracks"), "additive": blend_hint == "ADDITIVE",
            "file": exported}


def read_ball_defaults(state_bin):
    """Default ball block of State.bin (radius, a4, g, max bounces); falls back to documented defaults when the
    bytes do not look right. Returns a dict with a 'source' entry saying which."""
    out = dict(BALL_DEFAULTS)
    try:
        base = STATE_BALL_BLOCK
        radius, a4, g = struct.unpack_from(">3f", state_bin, base + 0x4D0)
        maxb = struct.unpack_from(">I", state_bin, base + 0x4DC)[0]
        if 0.5 < radius < 20 and 0.001 < a4 < 1 and 5 < g < 15 and maxb < 100:
            out.update(radius_cm=round(radius, 6), a4=round(a4, 6), g=round(g, 6), max_bounces=maxb)
            out["source"] = "State.bin ball block at 0x%X" % base
            return out
    except struct.error:
        pass
    out["source"] = "documented defaults (State.bin ball block not recognised)"
    return out


def compact_shot_rows(decoded):
    """tools/ts4data/templates.decode_all() output -> the rows the viewer/ts4core fallback needs, without the raw
    word dumps. Keeps every value needed by the launch solve and the bounce response."""
    rows = []
    for f in decoded.get("files", []):
        for r in f["rows"]:
            rows.append({
                "id": "%s#%d" % (f["file"], r["index"]),
                "file": f["file"], "index": r["index"], "row_offset": r["row_offset"],
                "name": r.get("name") or "row_%X" % r["row_offset"],
                "group": r.get("group"), "base": r.get("base"),
                "kind": r["kind"], "secondary_kind": r["secondary_kind"], "T": r["T"],
                "primary": r["primary"], "secondary": r["secondary"],
                "spin": r["spin"], "bounce": r["bounce"],
            })
    return rows


def find_iso(root, explicit=None):
    """--iso value, else the first orig/*/*.iso under root."""
    if explicit:
        return explicit
    hits = sorted(glob.glob(os.path.join(root, "orig", "*", "*.iso")))
    return hits[0] if hits else None


def write_json(path, obj, compact=False):
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w") as fh:
        if compact:
            json.dump(obj, fh, separators=(",", ":"), sort_keys=False)
        else:
            json.dump(obj, fh, indent=1)
            fh.write("\n")
    return os.path.getsize(path)


def file_size(path):
    try:
        return os.path.getsize(path)
    except OSError:
        return 0


def dir_size(path):
    total = 0
    for dp, _dn, fn in os.walk(path):
        total += sum(file_size(os.path.join(dp, f)) for f in fn)
    return total


def status(state, message="", **extra):
    d = {"status": state, "message": message}
    d.update(extra)
    return d


def free_bytes(path):
    p = os.path.abspath(path)
    while not os.path.exists(p) and os.path.dirname(p) != p:
        p = os.path.dirname(p)
    return shutil.disk_usage(p).free


# ------------------------------------------------------------------------------------------------ context

class Ctx:
    """Lazy handles on the disc image so parts only open what they need."""

    def __init__(self, args):
        self.args = args
        self.out = os.path.abspath(args.out)
        self.cache = os.path.abspath(args.cache)
        self.iso = find_iso(ROOT, args.iso)
        self._x = self._core = self._names = None
        self.budget = Budget(int(args.max_gb * (1 << 30)))
        self.extra_clip_indices = ()

    def log(self, msg):
        print(msg, flush=True)

    def need_iso(self):
        if not self.iso or not os.path.exists(self.iso):
            raise Skip("no disc image: pass --iso (looked for orig/*/*.iso)")
        return self.iso

    @property
    def xdvdfs(self):
        if self._x is None:
            sys.path.insert(0, TOOLS)
            import xdvdfs
            self._x = xdvdfs.XDVDFS(self.need_iso())
        return self._x

    @property
    def core(self):
        if self._core is None:
            import ts4_arc
            self._core = ts4_arc.Arc(self.xdvdfs.open_slice("Core.arc"))
        return self._core

    def core_entry(self, leaf):
        """Decompressed bytes of a Core.arc member found by its file name (hash fallback for known names)."""
        want = leaf.lower()
        for h, (_d, n) in self.core.leaf_names.items():
            if n.lower() == want:
                return self.core.read(self.core.find(h))
        if leaf in KNOWN_CORE_ENTRIES:
            return self.core.read(self.core.find(KNOWN_CORE_ENTRIES[leaf]))
        raise Skip("Core.arc has no member %s" % leaf)

    def layout(self):
        off, size = self.xdvdfs.open_file("Layoutall.bin")
        self.xdvdfs.f.seek(off)
        return self.xdvdfs.f.read(size)

    @property
    def names(self):
        """{crc32: string} from the CRC dictionaries in Core.arc."""
        if self._names is None:
            import ts4_xbin
            names = {}
            for leaf in ("AnimationsDBcrc.bin", "CommonCRCDictionnary.bin"):
                try:
                    names.update(ts4_xbin.read_crc_dictionary(self.core_entry(leaf)))
                except (Skip, ValueError, KeyError) as ex:
                    self.log("  note: %s not readable (%s)" % (leaf, ex))
            self._names = names
        return self._names


class Skip(Exception):
    """A part cannot run because a dependency is missing; the message is shown to the user."""


# ------------------------------------------------------------------------------------------------ parts

def ensure_havok_classes(ctx):
    """work/havok/classes.json (generated locally from Swing_DLL, never committed)."""
    path = os.environ.get("HAVOK_CLASSES") or os.path.join(ROOT, "work", "havok", "classes.json")
    if os.path.exists(path):
        return path
    dll = ctx.args.dll or os.path.join(ROOT, "orig", "54540859", "Swing_DLL.dll")
    if not os.path.exists(dll):
        raise Skip("Havok class table %s is missing and Swing_DLL.dll was not found at %s; run "
                   "`python3 tools/havok/dll_classes.py <Swing_DLL.dll>` (see docs/havok.md section 4) or pass --dll"
                   % (os.path.relpath(path, ROOT), dll))
    ctx.log("  generating %s from %s" % (os.path.relpath(path, ROOT), dll))
    r = subprocess.run([sys.executable, os.path.join(TOOLS, "havok", "dll_classes.py"), dll, "--out", path],
                       capture_output=True, text=True)
    if r.returncode != 0 or not os.path.exists(path):
        raise Skip("dll_classes.py failed: %s" % (r.stderr.strip() or r.stdout.strip())[-400:])
    return path


def load_core_hkx(ctx):
    """Bytes of the Core.arc merged animation container, cached under --cache (34 MB)."""
    os.makedirs(ctx.cache, exist_ok=True)
    cpath = os.path.join(ctx.cache, "core_%08x.hkx" % CORE_HAVOK_ENTRY)
    if os.path.exists(cpath) and file_size(cpath) > 1 << 20:
        with open(cpath, "rb") as fh:
            return fh.read()
    ctx.log("  reading Core.arc entry %08x (LZX, about 30 s) ..." % CORE_HAVOK_ENTRY)
    data = ctx.core.read(ctx.core.find(CORE_HAVOK_ENTRY))
    with open(cpath, "wb") as fh:
        fh.write(data)
    return data


def export_havok(ctx):
    classes_path = ensure_havok_classes(ctx)
    os.environ.setdefault("HAVOK_CLASSES", classes_path)
    sys.path.insert(0, os.path.join(TOOLS, "havok"))
    import classes  # noqa: E402
    import gltf_export  # noqa: E402
    import packfile  # noqa: E402
    import skeleton  # noqa: E402
    data = load_core_hkx(ctx)
    pf = packfile.Packfile(data)
    try:
        reg = classes.Registry.from_packfile(pf)
    except classes.MissingClasses as ex:
        raise Skip(str(ex))
    skels, anims = skeleton.load(pf, reg)
    ctx.log("  %d skeleton(s), %d clips in the container" % (len(skels), len(anims)))
    out = ctx.out
    res = {"skeletons": [], "clips": [], "clip_summaries": []}
    for i, sk in enumerate(skels):
        rel = "skeletons/player_%d.gltf" % i
        p = gltf_export.export(os.path.join(out, rel), sk, [], 0.01, True, name="player_%d" % i)
        sz = file_size(p) + file_size(os.path.splitext(p)[0] + ".bin")
        ctx.budget.add(sz)
        res["skeletons"].append({"index": i, "name": sk.name, "bones": len(sk.bones), "file": rel,
                                 "bone_names": list(sk.bones), "parents": list(sk.parents)})
    # clip index: every clip's header (cheap), file only for the selected ones
    want = set(parse_clip_spec(ctx.args.core_clips, len(anims)))
    want |= set(ctx.extra_clip_indices)
    sk_i = min(max(ctx.args.skeleton, 0), len(skels) - 1)
    done = 0
    for i, entry in enumerate(anims):
        loc, cls, binding = entry
        obj = reg.read_object(pf, loc[0], loc[1], cls)
        blend = binding["blendHint"] if binding else None
        rel = None
        existing = "clips/core_%d.gltf" % i
        if os.path.exists(os.path.join(out, existing)) and i not in want:
            rel = existing  # exported by an earlier run
        if i in want and not ctx.budget.exhausted:
            try:
                clip = skeleton.load_clip(pf, reg, entry, i)
                rel = "clips/core_%d.gltf" % i
                p = gltf_export.export(os.path.join(out, rel), skels[sk_i], [clip], 0.01,
                                       not ctx.args.raw_additive, name="player_%d" % sk_i)
                ctx.budget.add(file_size(p) + file_size(os.path.splitext(p)[0] + ".bin"))
                done += 1
                if done % 16 == 0:
                    ctx.log("    exported %d clips" % done)
            except Exception as ex:  # one undecodable clip must not stop the export
                ctx.log("    clip %d (%s): skipped: %s" % (i, cls, ex))
                rel = None
        res["clip_summaries"].append(clip_summary(obj, cls, blend, i, rel))
    if ctx.budget.exhausted:
        ctx.log("  size budget (--max-gb) reached; remaining selected clips were not written")
    res["exported"] = done
    return res


def export_animdb(ctx, clip_rows):
    import ts4_extract
    adb = ctx.core_entry("AnimationsDB.bin")
    d = ts4_extract.decode_animation_db(adb, ctx.layout(), ctx.names)
    takes = d.get("takes")
    if not takes:
        raise Skip("AnimationsDB.bin decoded but has no TakeList")
    records = build_animation_records(takes)
    linked = 0
    if ctx.args.clip_map:
        if ctx.args.clip_map == "auto":  # tools/port/clip_map.py output (docs/port/clip-map.md)
            cm_path = os.path.join(ctx.out, "clip_map.json")
            if not os.path.exists(cm_path):
                subprocess.run([sys.executable, os.path.join(HERE, "clip_map.py"), "--iso", ctx.need_iso(),
                                "--out", ctx.out, "--cache", ctx.cache], check=True)
            with open(cm_path) as fh:
                clip_map = json.load(fh)["map"]
        else:
            with open(ctx.args.clip_map) as fh:
                clip_map = json.load(fh)
        linked = link_records(records, [c["id"] for c in clip_rows], clip_map)
    doc = {
        "schema": 1,
        "notes": {
            "clips": "Core.arc Havok clips (docs/havok.md). Names are unknown; index order is the container order.",
            "records": "AnimationsDB swing records (docs/gameplay/df.md 3.2). 'clip' is null unless --clip-map linked it: "
                       "the record -> Havok clip mapping is not established.",
            "contact_unit": "EventRacket/Preparation 'time' values are unverified; retail values lie in 0.06-0.68 so the "
                            "viewer treats a value <= 1 as a normalised phase of the clip and anything larger as 60 Hz ticks.",
        },
        "clips": clip_rows, "records": records,
    }
    sz = write_json(os.path.join(ctx.out, "animations.json"), doc, compact=True)
    ctx.budget.add(sz)
    return {"records": len(records), "clips": len(clip_rows), "linked": linked, "file": "animations.json"}


def export_gameplay(ctx):
    sys.path.insert(0, os.path.join(TOOLS, "ts4data"))
    import templates  # noqa: E402
    res = {}
    settings = ctx.core_entry("Settings.bin")
    state = ctx.core_entry("State.bin")
    names = [s for s in ctx.names.values()]
    dec = templates.decode_all(settings, state, extra_names=names)
    rows = compact_shot_rows(dec)
    shots = {"schema": 1, "unit_notes": "curve x in cm of horizontal distance, 2-D table second axis in cm of hit height",
             "ball": read_ball_defaults(state), "files": [{"file": f["file"], "size": f["size"], "sha256": f["sha256"]}
                                                          for f in dec["files"]],
             "rows": rows}
    write_json(os.path.join(ctx.out, "gameplay", "shots.json"), shots)
    res["shots"] = {"file": "gameplay/shots.json", "rows": len(rows)}
    ctx.log("  %d shot-template rows" % len(rows))
    try:
        import ts4_analyser
        graphs = ts4_analyser.parse_expressions(ctx.core_entry("Expressions.bin"))
        nm = dict(ctx.names)
        for k, v in ts4_analyser.known_names().items():
            nm.setdefault(k, v)
        doc = {"schema": 1, "graphs": [g.to_json(nm) for g in graphs]}
        write_json(os.path.join(ctx.out, "gameplay", "analyser.json"), doc, compact=True)
        res["analyser"] = {"file": "gameplay/analyser.json", "graphs": len(graphs)}
        ctx.log("  %d analyser graphs" % len(graphs))
    except Exception as ex:  # keep the shot templates even if the analyser decode fails
        res["analyser"] = {"error": str(ex)}
        ctx.log("  analyser graphs skipped: %s" % ex)
    res["blob"] = export_blob(ctx, rows, shots["ball"])
    return res


def export_blob(ctx, rows, ball):
    """The gameplay data blob of docs/port/data-format.md, written by tools/port/blob_writer.py when it exists."""
    spec = os.path.join(ROOT, "docs", "port", "data-format.md")
    writer = os.path.join(HERE, "blob_writer.py")
    if not os.path.exists(spec):
        return {"status": "pending", "message": "docs/port/data-format.md not written yet (portcore agent)"}
    if not os.path.exists(writer):
        return {"status": "pending", "message": "data-format.md exists; tools/port/blob_writer.py is not implemented yet"}
    sys.path.insert(0, HERE)
    import blob_writer  # noqa: E402
    path = os.path.join(ctx.out, "gameplay", "ts4core.dat")
    try:
        side = blob_writer.write_blob(path, ctx, rows, ball)
    except Exception as ex:  # the shot/analyser JSON is still useful without the blob
        return {"status": "error", "message": "%s: %s" % (type(ex).__name__, ex)}
    return {"status": "ok", "file": "gameplay/ts4core.dat", "size": side["size"], "sha256": side["sha256"],
            "sections": side["sections"], "message": "sections " + ",".join(sorted(side["sections"]))}


def export_meshes(ctx):
    tool = os.path.join(TOOLS, "ts4_assets.py")
    if not os.path.exists(tool):
        libs = [n for n in ("ts4_mesh.py", "ts4_texture.py") if os.path.exists(os.path.join(TOOLS, n))]
        raise Skip("tools/ts4_assets.py (the assets agent's exporter) is not present yet%s" % (
            " (parsers exist: " + ", ".join(libs) + ")" if libs else ""))
    h = subprocess.run([sys.executable, tool, "--help"], capture_output=True, text=True)
    text = h.stdout + h.stderr
    if "--iso" not in text or "--out" not in text:
        raise Skip("tools/ts4_assets.py exists but has no --iso/--out interface this exporter knows; run it by hand "
                   "into %s/meshes and add the files to manifest.json" % ctx.out)
    dest = os.path.join(ctx.out, "meshes")
    cmd = [sys.executable, tool, "--iso", ctx.need_iso(), "--out", dest] + list(ctx.args.assets_args or [])
    ctx.log("  running: " + " ".join(cmd))
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode != 0:
        raise Skip("ts4_assets.py failed: " + (r.stderr.strip() or r.stdout.strip())[-400:])
    return {"dir": "meshes", "bytes": dir_size(dest)}


# ------------------------------------------------------------------------------------------------ driver

def run(args):
    ctx = Ctx(args)
    selected = [p for p in PARTS if (not args.only or p in args.only) and p not in (args.skip or [])]
    os.makedirs(ctx.out, exist_ok=True)
    free = free_bytes(ctx.out)
    ctx.log("output %s (free %.1f GB, budget %.1f GB)" % (ctx.out, free / 1e9, args.max_gb))
    if free < 2 * (1 << 30) + ctx.budget.limit // 10:
        ctx.log("refusing to run: less than 2 GB (plus 10%% of the budget) free on the output volume")
        return 2
    manifest_path = os.path.join(ctx.out, "manifest.json")
    manifest = {"schema": 1, "tool": "tools/port/export_assets.py", "unit_scale": 0.01,
                "axes": "glTF y up; court x runs along the court with the net at x = 0, z across; metres",
                "parts": {}, "skeletons": [], "animations": None, "gameplay": {}, "meshes": None}
    if os.path.exists(manifest_path):  # keep results of earlier partial runs for parts not selected now
        try:
            with open(manifest_path) as fh:
                old = json.load(fh)
            if old.get("schema") == 1:
                manifest.update({k: old.get(k, manifest[k]) for k in ("parts", "skeletons", "animations", "gameplay", "meshes")})
        except (OSError, ValueError):
            pass
    manifest["generated"] = time.strftime("%Y-%m-%dT%H:%M:%S%z")
    manifest["iso"] = {"name": os.path.basename(ctx.iso) if ctx.iso else None,
                       "size": file_size(ctx.iso) if ctx.iso else None}

    clip_rows = None
    for part in selected:
        ctx.log("[%s]" % part)
        t0 = time.time()
        try:
            if part == "havok":
                r = export_havok(ctx)
                clip_rows = r["clip_summaries"]
                manifest["skeletons"] = r["skeletons"]
                n_files = sum(1 for c in clip_rows if c["file"])
                manifest["parts"]["havok"] = status("ok", "%d skeleton(s), %d clip file(s) on disk (%d written now)" % (
                    len(r["skeletons"]), n_files, r["exported"]), exported_clips=n_files, total_clips=len(clip_rows))
                if "animdb" not in selected:
                    refresh_clip_rows(ctx, clip_rows)
            elif part == "animdb":
                if clip_rows is None:
                    clip_rows = load_clip_rows_from_manifest(ctx)
                r = export_animdb(ctx, clip_rows or [])
                manifest["animations"] = r["file"]
                manifest["parts"]["animdb"] = status("ok", "%d records, %d clips, %d linked" % (r["records"], r["clips"], r["linked"]))
            elif part == "gameplay":
                r = export_gameplay(ctx)
                manifest["gameplay"] = {k: v for k, v in r.items()}
                manifest["parts"]["gameplay"] = status("ok", "shots%s%s" % (
                    ", analyser" if "file" in r.get("analyser", {}) else "",
                    ", blob" if r["blob"].get("status") == "ok" else " (blob pending)"))
            elif part == "meshes":
                r = export_meshes(ctx)
                manifest["meshes"] = r
                manifest["parts"]["meshes"] = status("ok", "%d bytes" % r["bytes"])
        except Skip as ex:
            ctx.log("  skipped: %s" % ex)
            manifest["parts"][part] = status("skipped", str(ex))
        except Exception as ex:
            ctx.log("  FAILED: %s: %s" % (type(ex).__name__, ex))
            manifest["parts"][part] = status("error", "%s: %s" % (type(ex).__name__, ex))
            if args.strict:
                write_json(manifest_path, manifest)
                raise
        ctx.log("  (%.1f s)" % (time.time() - t0))
    manifest["bytes_written_this_run"] = ctx.budget.used
    write_json(manifest_path, manifest)
    ctx.log("wrote %s" % manifest_path)
    for p in PARTS:
        st = manifest["parts"].get(p)
        ctx.log("  %-9s %s" % (p, ("%s: %s" % (st["status"], st["message"])) if st else "not run"))
    return 0


def refresh_clip_rows(ctx, clip_rows):
    """Keep animations.json in step with the clip files when only the havok part ran."""
    path = os.path.join(ctx.out, "animations.json")
    if not os.path.exists(path):
        return
    with open(path) as fh:
        doc = json.load(fh)
    doc["clips"] = clip_rows
    write_json(path, doc, compact=True)


def load_clip_rows_from_manifest(ctx):
    """When animdb runs without havok in the same invocation, reuse the clip index of an earlier run."""
    path = os.path.join(ctx.out, "animations.json")
    if os.path.exists(path):
        with open(path) as fh:
            return json.load(fh).get("clips", [])
    return []


def build_parser():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso", help="disc image (default: first orig/*/*.iso)")
    ap.add_argument("--dll", help="Swing_DLL.dll, only needed to generate work/havok/classes.json")
    ap.add_argument("--out", default=os.path.join(ROOT, "work", "port", "assets"))
    ap.add_argument("--cache", default=os.path.join(ROOT, "work", "port", "cache"),
                    help="where the decompressed Core.arc Havok container is cached (34 MB)")
    ap.add_argument("--only", nargs="+", choices=PARTS, help="run only these parts")
    ap.add_argument("--skip", nargs="+", choices=PARTS, help="skip these parts")
    ap.add_argument("--core-clips", default="0-31", help="Core clip indices to export as glTF: '0-31', '0,5,9', 'all', 'none'")
    ap.add_argument("--skeleton", type=int, default=0, help="Core skeleton the clips are exported against (default 0)")
    ap.add_argument("--raw-additive", action="store_true", help="export additive clips as raw deltas")
    ap.add_argument("--clip-map", help="JSON {record name | 8-hex id | '#index': 'core:<n>'} linking AnimationsDB records to clips, or "
                    "'auto' to use work/port/assets/clip_map.json from tools/port/clip_map.py (run on demand)")
    ap.add_argument("--max-gb", type=float, default=10.0, help="stop writing clips after this many GB (default 10)")
    ap.add_argument("--assets-args", nargs=argparse.REMAINDER, help="extra arguments passed to tools/ts4_assets.py (must be last)")
    ap.add_argument("--strict", action="store_true", help="stop and re-raise on the first part that fails")
    return ap


def main(argv=None):
    return run(build_parser().parse_args(argv))


if __name__ == "__main__":
    sys.exit(main())
