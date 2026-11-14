#!/usr/bin/env python3
"""Export the FMOD event projects and sample banks of Top Spin 4 into playable files for the browser port.

  python3 tools/port/audio_export.py [--iso DISC.iso] [--venue Amsterdam ...|all] [--no-core]
                                     [--out work/port/assets/audio] [--format wav|native] [--events-only]
  python3 tools/port/audio_export.py --summary data/audio      # readable event inventory (no audio)

Reads the user's own disc image in place and writes everything below --out (git-ignored):

  banks/<bank>-<sha8>/<index>_<name>.<ext>   one file per sample a parsed event can reach (deduplicated across
                                             venues by the sha256 of the .fsb)
         .wav  XMA decoded to PCM with ffmpeg (--format wav, default) or Xbox IMA decoded in Python
         .mp3  MPEG samples copied as they are (browsers play them)
         .xma.wav  with --format native, or when ffmpeg is missing: XMA2 RIFF, decodable with ffmpeg only
  <venue>/events.json   event path -> {type, category, volume, pitch, randomisation, max_playbacks, params,
                        layers: [{param, envelopes, sounds: [{start, length, playmode, waves: [{file, loop, weight}]}]}]}
                        (loop = FSB sample mode bit 0x2, FSOUND_LOOP_NORMAL)
  manifest.json         venues, banks, source entries (arc, entry hash, size, sha256), tool versions

Bank lookup for a .fev bank name: `<bank>.fsb` in the same archive, then Media/Sounds/<bank>.fsb on the disc
(streamed crowd/music banks), then Core.arc.  Formats: tools/port/fmod_fev.py and tools/port/fmod_fsb.py;
docs/port/presentation-and-audio.md.  Standard library plus an optional ffmpeg binary (XMA decoder).
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
TOOLS = os.path.join(ROOT, "tools")
for p in (TOOLS, HERE):
    if p not in sys.path:
        sys.path.insert(0, p)

import fmod_fev  # noqa: E402
import fmod_fsb  # noqa: E402

TOOL_VERSION = "audio_export 1"


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def find_iso(explicit=None):
    if explicit:
        return explicit
    for base in ("orig/54540859/disc_archive", "orig/54540859", "orig"):
        d = os.path.join(ROOT, base)
        if os.path.isdir(d):
            for n in sorted(os.listdir(d)):
                if n.lower().endswith(".iso"):
                    return os.path.join(d, n)
    return None


def safe_name(s):
    """File-system safe stem of an FSB sample name (names are cut at 30 bytes, so ".wav" may be truncated)."""
    s = re.sub(r"\.(w|wa|wav|mp3|aif|aiff)$", "", s, flags=re.I)
    return re.sub(r"[^A-Za-z0-9_-]+", "_", s)[:60] or "sample"


def ffmpeg_decode(ffmpeg, src, dst):
    r = subprocess.run([ffmpeg, "-v", "error", "-y", "-i", src, "-c:a", "pcm_s16le", dst],
                       capture_output=True, timeout=120)
    return r.returncode == 0 and os.path.exists(dst)


def event_record(fev, ev, bank_files):
    """JSON record of one event; bank_files maps (bank, index) -> exported relative path (or None)."""
    layers = []
    for layer in ev["layers"]:
        sounds = []
        for inst in layer["instances"]:
            if inst["sounddef"] >= len(fev.sounddefs):
                continue
            sd = fev.sounddefs[inst["sounddef"]]
            tpl = fev.templates[sd["template"]] if sd["template"] < len(fev.templates) else {}
            waves = []
            for w in sd["waves"]:
                if w["type"] != 0:
                    continue
                info = bank_files.get((w["bank"], w["index"])) or {}
                if isinstance(info, str):
                    info = {"file": info}
                waves.append({"file": info.get("file"), "loop": bool(info.get("loop")), "weight": w["weight"],
                              "length_ms": w["length_ms"], "name": os.path.basename(w["file"].replace("\\", "/"))})
            sounds.append({"sounddef": sd["name"], "start": inst["start"], "length": inst["length"],
                           "playmode": fmod_fev.PLAYMODES.get(tpl.get("playmode"), tpl.get("playmode")),
                           "volume": tpl.get("volume"), "waves": waves})
        layers.append({"param": layer["param"], "envelopes": layer["envelopes"], "sounds": sounds})
    b = ev["base"]
    return {"type": ev["type"], "category": ev.get("category"), "volume": b["volume"], "pitch": b["pitch"],
            "pitch_randomization": b["pitch_randomization"], "volume_randomization": b["volume_randomization"],
            "max_playbacks": b["max_playbacks"], "priority": b["priority"], "params": ev["params"],
            "user_properties": ev["user_properties"], "layers": layers}


class Exporter:
    def __init__(self, args):
        self.a = args
        self.iso = find_iso(args.iso)
        self.out = os.path.join(ROOT, args.out) if not os.path.isabs(args.out) else args.out
        self.ffmpeg = None if args.format == "native" else (args.ffmpeg or shutil.which("ffmpeg"))
        self.bank_dirs = {}          # fsb sha256 -> relative dir
        self.bank_index = {}         # fsb sha256 -> {index: relative file}
        self.sources = []
        self.warnings = []
        self.x = None

    def log(self, *m):
        if not self.a.quiet:
            print(*m, flush=True)

    def disc(self):
        if self.x is None:
            import xdvdfs
            if not self.iso or not os.path.exists(self.iso):
                raise SystemExit("no disc image: pass --iso")
            self.x = xdvdfs.XDVDFS(self.iso)
        return self.x

    def arc(self, name):
        import ts4_arc
        return ts4_arc.Arc(self.disc().open_slice(name))

    def arc_audio(self, arc):
        """{leaf name: entry} for the .fev/.fsb members of an archive."""
        out = {}
        for e in arc.entries:
            nm = arc.leaf_names.get(e[0], (0, ""))[1]
            if nm.lower().endswith((".fev", ".fsb")):
                out[nm] = e
        return out

    def find_bank(self, bank, members, arcname, arc):
        key = bank + ".fsb"
        for k, e in members.items():
            if k.lower() == key.lower():
                return arcname, "%08x" % e[0], arc.read(e)
        try:
            f = self.disc().open_slice("Media/Sounds/" + key)
        except Exception:
            f = None
        if f is not None:
            return "Media/Sounds/" + key, None, f.read()
        if arcname != "Core.arc":
            core = self.arc("Core.arc")
            m = self.arc_audio(core)
            for k, e in m.items():
                if k.lower() == key.lower():
                    return "Core.arc", "%08x" % e[0], core.read(e)
        return None, None, None

    def export_bank(self, bank, data, where, entry):
        h = sha256(data)
        if h in self.bank_index:
            return self.bank_index[h]
        rel = "banks/%s-%s" % (bank, h[:8])
        self.bank_dirs[h] = rel
        self.sources.append({"bank": bank, "file": where, "entry": entry, "size": len(data), "sha256": h})
        fsb = fmod_fsb.parse(data)
        files = {}
        d = os.path.join(self.out, rel)
        if not self.a.events_only:
            os.makedirs(d, exist_ok=True)
        for i, s in enumerate(fsb["samples"]):
            base = "%03d_%s" % (i, safe_name(s["name"]))
            ext, blob = fmod_fsb.native_file(data, s)
            if ext == ".xma.wav" and self.ffmpeg:
                target = base + ".wav"
                if not self.a.events_only and not os.path.exists(os.path.join(d, target)):
                    tmp = os.path.join(d, base + ".xma.wav")
                    with open(tmp, "wb") as f:
                        f.write(blob)
                    if ffmpeg_decode(self.ffmpeg, tmp, os.path.join(d, target)):
                        os.remove(tmp)
                    else:
                        self.warnings.append("ffmpeg failed on %s/%s" % (rel, base))
                        target = base + ext
                files[i] = {"file": rel + "/" + target, "loop": bool(s["mode"] & fmod_fsb.MODE_LOOP_NORMAL)}
                continue
            files[i] = {"file": rel + "/" + base + ext, "loop": bool(s["mode"] & fmod_fsb.MODE_LOOP_NORMAL)}
            if not self.a.events_only:
                with open(os.path.join(d, base + ext), "wb") as f:
                    f.write(blob)
        self.bank_index[h] = files
        self.log("  bank %-34s %4d samples  %s" % (bank, len(fsb["samples"]), where))
        return files

    def venue(self, arcname, label):
        arc = self.arc(arcname)
        members = self.arc_audio(arc)
        events = {}
        fevs = sorted(k for k in members if k.lower().endswith(".fev"))
        self.log("%s: %d event projects" % (arcname, len(fevs)))
        for name in fevs:
            raw = arc.read(members[name])
            self.sources.append({"fev": name, "file": arcname, "entry": "%08x" % members[name][0],
                                 "size": len(raw), "sha256": sha256(raw)})
            fev = fmod_fev.FevFile(raw)
            bank_files = {}
            for b in fev.banks:
                where, entry, data = self.find_bank(b["name"], members, arcname, arc)
                if data is None:
                    self.warnings.append("%s: bank %s not found" % (name, b["name"]))
                    continue
                for idx, rel in self.export_bank(b["name"], data, where, entry).items():
                    bank_files[(b["name"], idx)] = rel
            for ev in fev.events:
                rec = event_record(fev, ev, bank_files)
                rec["project"] = name
                events[ev["path"]] = rec
        os.makedirs(os.path.join(self.out, label), exist_ok=True)
        with open(os.path.join(self.out, label, "events.json"), "w") as f:
            json.dump({"venue": label, "source": arcname, "events": events}, f, indent=0, sort_keys=True)
        return len(events)

    def all_venues(self):
        """Root-level archives that carry a Venue_<name>.fev event project."""
        out = []
        for path, _e in self.disc().walk():
            if "/" in path or not path.endswith(".arc") or path.startswith("Baked_"):
                continue
            try:
                arc = self.arc(path)
            except Exception:
                continue
            if any(n.startswith("Venue_") and n.endswith(".fev") for _dh, n in arc.leaf_names.values()):
                out.append(path[:-4])
        return sorted(out)

    def run(self):
        venues = self.a.venue or ["Amsterdam"]
        if venues == ["all"]:
            venues = self.all_venues()
        result = {}
        for v in venues:
            result[v] = self.venue(v + ".arc", v)
        if not self.a.no_core:
            result["Core"] = self.venue("Core.arc", "Core")
        man = {"tool": TOOL_VERSION, "python": sys.version.split()[0], "generated": time.strftime("%Y-%m-%d"),
               "iso": os.path.basename(self.iso or ""), "format": self.a.format,
               "ffmpeg": self.ffmpeg and ffmpeg_version(self.ffmpeg), "venues": result,
               "sources": self.sources, "warnings": self.warnings}
        with open(os.path.join(self.out, "manifest.json"), "w") as f:
            json.dump(man, f, indent=1)
        self.log("wrote %s (%d events, %d banks, %d warnings)" % (self.out, sum(result.values()),
                                                                 len(self.bank_index), len(self.warnings)))
        for w in self.warnings[:20]:
            self.log("warning:", w)


def ffmpeg_version(ffmpeg):
    try:
        r = subprocess.run([ffmpeg, "-version"], capture_output=True, text=True, timeout=20)
        return r.stdout.split("\n")[0]
    except Exception:
        return None


def summary(args):
    """data/audio/fev_inventory.yaml: every event of the chosen venue + Core, with params and wave counts."""
    ex = Exporter(args)
    lines = []
    srcs = []
    for arcname in [v + ".arc" for v in (args.venue or ["Amsterdam"])] + ["Core.arc"]:
        arc = ex.arc(arcname)
        members = ex.arc_audio(arc)
        for name in sorted(k for k in members if k.lower().endswith(".fev")):
            raw = arc.read(members[name])
            srcs.append((arcname, name, len(raw), sha256(raw)))
            fev = fmod_fev.FevFile(raw)
            lines.append("  %s:   # %s, banks %s" % (name, arcname, ", ".join(b["name"] for b in fev.banks)))
            for ev in fev.events:
                waves = fev.event_waves(ev)
                ms = sorted({w["length_ms"] for _n, w in waves})
                params = ", ".join("%s %g..%g" % (p["name"], p["min"], p["max"]) for p in ev["params"])
                lines.append("    %s: {type: %s, category: %s, volume: %g, waves: %d, length_ms: [%s]%s}" % (
                    json.dumps(ev["path"]), ev["type"], ev.get("category"), ev["base"]["volume"], len(waves),
                    ", ".join(str(m) for m in (ms[:1] + ms[-1:] if len(ms) > 1 else ms)),
                    (", params: " + json.dumps(params)) if params else ""))
    cmd = "python3 tools/port/audio_export.py --summary data/audio" + (
        "" if not args.venue else " --venue " + " ".join(args.venue))
    head = ["# FMOD event inventory of Top Spin 4 (Xbox 360): every event of the venue and Core event projects,",
            "# with type, category, base volume, number of reachable waves, shortest/longest wave and parameters.",
            "# Generated by: " + cmd,
            "# Tool: tools/port/audio_export.py + fmod_fev.py (%s, Python %s, standard library)" % (
                TOOL_VERSION, sys.version.split()[0]),
            "# Source disc: %s (sha256 93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c)" %
            os.path.basename(ex.iso or ""),
            "generator: {command: %s, tool: %s}" % (json.dumps(cmd), json.dumps(TOOL_VERSION)),
            "sources:"]
    for a, n, size, h in srcs:
        head.append("  - {file: %s, member: %s, size: %d, sha256: %s}" % (a, n, size, h))
    head.append("projects:")
    os.makedirs(args.summary, exist_ok=True)
    out = os.path.join(args.summary, "fev_inventory.yaml")
    with open(out, "w") as f:
        f.write("\n".join(head + lines) + "\n")
    print("wrote", out)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    ap.add_argument("--venue", nargs="*", help="venue archive names (default Amsterdam); 'all' for every venue")
    ap.add_argument("--no-core", action="store_true", help="skip Core.arc (menu sounds and music)")
    ap.add_argument("--out", default="work/port/assets/audio")
    ap.add_argument("--format", choices=("wav", "native"), default="wav")
    ap.add_argument("--ffmpeg")
    ap.add_argument("--events-only", action="store_true", help="write events.json/manifest without audio files")
    ap.add_argument("--summary", metavar="DIR", help="write DIR/fev_inventory.yaml and exit")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    if a.summary:
        summary(a)
        return 0
    Exporter(a).run()
    return 0


if __name__ == "__main__":
    sys.exit(main())
