#!/usr/bin/env python3
"""Apply the retune data patch set (tuning/retune-v0) to the owner's own copy of Top Spin 4 (standard library only).

Reads the disc image (.iso) or an extracted game folder (the one with default.xex and Core.arc), and
optionally Title Update #1 (a folder holding TitleUpdate.arc and Layoutall.bin, or TitleUpdate.arc itself).
Never writes to them: every output goes to a new or empty directory under work/.

Steps (each uses the repository's existing patch tools):
  1. check the sha256 of Core.arc (and TitleUpdate.arc), of the two members and of Layoutall.bin against
     tuning/retune-v0/manifest.json; refuse on any mismatch;
  2. read Settings.bin (0x334E7E0D) and Expressions.bin (0xFA94F637) from each archive;
  3. apply the chosen groups: Settings rows with tools/ts4data/patch_tunables.py (apply + verify), graph edits
     with tools/ts4_analyser_patch.py (patch_expressions); the disc copy gets the 'disc' files, the title
     update copy the 'tu1' files;
  4. rebuild the archive(s) with tools/ts4_arc_write.py (raw members by default) and check the result: every
     untouched member's stored bytes are unchanged, the replaced ones read back, and (unless --quick) the
     writer's own verify, which decodes every member;
  5. optionally (--game-folder) write a complete playable folder: tools/ts4_iso_patch.py for an image, a copy for
     an extracted folder; the patched Core.arc replaces the original there;
  6. write OUT/manifest.json with every input and output hash.

Output layout:
  OUT/Core.arc                     rebuilt disc archive (patch both archives: which copy the game uses when the
  OUT/TitleUpdate.arc              title update is installed is the TU one, see title-update-balance.md)
  OUT/members/{disc,tu1}/<File>    the patched members
  OUT/game/                        with --game-folder
  OUT/manifest.json

Usage:
  python3 tools/apply_retune.py --source GAME.iso|GAME_DIR [--tu TU_DIR] --groups all|ratings,timing,...
                                --out work/retune/NAME [--game-folder] [--mode raw|lzx-stored] [--quick]
  python3 tools/apply_retune.py --list            # the groups and what they change
"""
from __future__ import annotations

import argparse
import hashlib
import io
import json
import os
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.join(HERE, "ts4data"))

import ts4_arc  # noqa: E402
import ts4_arc_write  # noqa: E402
import ts4_analyser_patch  # noqa: E402
import ts4_xbin as X  # noqa: E402
import patch_tunables  # noqa: E402

DEFAULT_PATCHES = os.path.join(ROOT, "tuning", "retune-v0")
MEMBERS = ("Settings.bin", "Expressions.bin")
TU_ARC = "TitleUpdate.arc"


class RetuneError(Exception):
    pass


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def sha256_file(f, size=None):
    h = hashlib.sha256()
    n = 0
    while True:
        blk = f.read(1 << 20)
        if not blk:
            break
        h.update(blk)
        n += len(blk)
    return h.hexdigest(), n


# --------------------------------------------------------------------------- sources

class Source:
    """The disc side: an .iso (read through xdvdfs) or an extracted folder."""

    def __init__(self, path):
        self.path = os.path.realpath(path)
        if os.path.isdir(self.path):
            self.kind = "folder"
            if not os.path.isfile(os.path.join(self.path, "Core.arc")):
                raise RetuneError("%s has no Core.arc: point --source at the extracted game folder (the one with "
                                  "default.xex) or at the disc image" % path)
            if not os.path.isfile(os.path.join(self.path, "Layoutall.bin")):
                raise RetuneError("%s has no Layoutall.bin: the extracted game folder must be complete" % path)
        elif os.path.isfile(self.path):
            self.kind = "iso"
            import xdvdfs
            self.x = xdvdfs.XDVDFS(self.path)
        else:
            raise RetuneError("--source %s does not exist" % path)

    def open(self, name):
        if self.kind == "folder":
            return open(os.path.join(self.path, name), "rb")
        return self.x.open_slice(name)

    def read(self, name):
        f = self.open(name)
        try:
            return f.read()
        finally:
            if self.kind == "folder":
                f.close()


class TuSource:
    def __init__(self, path):
        p = os.path.realpath(path)
        if os.path.isdir(p):
            self.dir, self.arc = p, os.path.join(p, TU_ARC)
        else:
            self.dir, self.arc = os.path.dirname(p), p
        if not os.path.isfile(self.arc):
            raise RetuneError("no %s at %s" % (TU_ARC, path))
        self.layout = os.path.join(self.dir, "Layoutall.bin")
        if not os.path.isfile(self.layout):
            raise RetuneError("the title update's Layoutall.bin must sit next to %s (%s)" % (TU_ARC, self.layout))


# --------------------------------------------------------------------------- patch set

def load_manifest(patch_dir):
    p = os.path.join(patch_dir, "manifest.json")
    if not os.path.isfile(p):
        raise RetuneError("no manifest.json in %s" % patch_dir)
    with open(p) as f:
        return json.load(f)


def choose_groups(manifest, spec):
    names = [g["name"] for g in manifest["groups"]]
    if spec in ("all", ""):
        return names
    want = [s.strip() for s in spec.split(",") if s.strip()]
    skip = [w[1:] for w in want if w.startswith("-")]
    if skip and len(skip) == len(want):
        want = [n for n in names if n not in skip]
    bad = [w for w in want if w not in names]
    if bad:
        raise RetuneError("unknown group(s) %s; groups are: %s" % (", ".join(bad), ", ".join(names)))
    return [n for n in names if n in want]


def merge_expr(dst, src, origin):
    for gk, nodes in src.items():
        for nk, change in nodes.items():
            cur = dst.setdefault(gk, {}).get(nk)
            if cur is not None and cur != change:
                raise RetuneError("groups disagree on graph %s node %s (%s)" % (gk, nk, origin))
            dst[gk][nk] = change


def collect(patch_dir, manifest, groups, variant):
    """-> (list of Settings YAML texts, merged expression patch) for 'disc' or 'tu1'."""
    texts, expr = [], {}
    by = {g["name"]: g for g in manifest["groups"]}
    for name in groups:
        g = by[name]
        for rel in g["settings"].get(variant, []):
            with open(os.path.join(patch_dir, rel)) as f:
                texts.append((rel, f.read()))
        rel = g.get("expressions", {}).get(variant)
        if rel:
            with open(os.path.join(patch_dir, rel)) as f:
                merge_expr(expr, json.load(f), rel)
    return texts, expr


# --------------------------------------------------------------------------- one archive

def patch_members(settings, expressions, layout, texts, expr, want):
    """Apply Settings YAML texts and the expression patch.  Returns (new settings, new expressions, report)."""
    rep = {"settings_values": 0, "expression_words": 0, "settings_rows": []}
    new_s = settings
    if texts:
        rows = []
        for rel, t in texts:
            head, r = patch_tunables.parse_yaml(t)
            if head.get("sha256") != want["settings"]:
                raise RetuneError("%s was made for Settings.bin %s, not %s" % (rel, head.get("sha256"), want["settings"]))
            if int(head["key"], 16) != int(want["settings_key"], 16):
                raise RetuneError("%s: wrong member key %s" % (rel, head["key"]))
            rows += r
        try:
            new_s, changes = patch_tunables.apply(settings, layout, rows)
            patch_tunables.verify(settings, new_s, layout, changes)
        except patch_tunables.PatchError as e:
            raise RetuneError("Settings.bin: %s" % e)
        rep["settings_values"] = len(changes)
        rep["settings_rows"] = ["0x%x %s" % (off, path) for off, path, _o, _n in changes]
    new_e = expressions
    if expr:
        new_e, r = ts4_analyser_patch.patch_expressions(expressions, expr)
        rep["expression_words"] = r["words_changed"]
    return new_s, new_e, rep


def quick_verify(orig, new, repl):
    """Stored bytes of every member other than the replaced ones are unchanged; replaced members read back."""
    if [e[0] for e in orig.entries] != [e[0] for e in new.entries]:
        raise RetuneError("rebuilt archive: key table differs")
    if orig.hdr[:0x24] != new.hdr[:0x24] or len(orig.hdr) != len(new.hdr):
        raise RetuneError("rebuilt archive: header differs")
    for eo, en in zip(orig.entries, new.entries):
        if eo[0] in repl:
            if new.read(en) != repl[eo[0]]:
                raise RetuneError("member %08x does not read back" % eo[0])
        elif orig.raw(eo) != new.raw(en):
            raise RetuneError("member %08x changed although it was not replaced" % eo[0])
    return len(orig.entries)


def rebuild(arc_bytes, repl, out_path, mode, full):
    orig = ts4_arc.Arc(io.BytesIO(arc_bytes))
    with open(out_path, "wb") as o:
        st = ts4_arc_write.rebuild(orig, repl, o, mode)
    new = ts4_arc.Arc(out_path)
    try:
        n = quick_verify(orig, new, repl)
        if full:
            ts4_arc_write.verify(orig, new, repl)
    finally:
        new.f.close()
    with open(out_path, "rb") as f:
        digest, size = sha256_file(f)
    return {"size": size, "sha256": digest, "members": n, "replaced": ["%08x" % k for k in sorted(repl)],
            "mode": mode, "full_verify": bool(full), "in_size": st["in_size"]}


def do_archive(variant, arc_name, arc_bytes, layout_bytes, manifest, texts, expr, out, mode, full, log):
    mem = manifest["members"]
    want = {"settings": mem["Settings.bin"]["%s_sha256" % variant], "settings_key": mem["Settings.bin"]["key"]}
    arc = ts4_arc.Arc(io.BytesIO(arc_bytes))
    data = {}
    for name in MEMBERS:
        key = int(mem[name]["key"], 16)
        try:
            ent = arc.find(key)
        except KeyError:
            raise RetuneError("%s has no member %s (%08x)" % (arc_name, name, key))
        b = arc.read(ent)
        if sha256(b) != mem[name]["%s_sha256" % variant]:
            raise RetuneError("%s in %s has sha256 %s, expected %s: not the version these patches were made for"
                              % (name, arc_name, sha256(b), mem[name]["%s_sha256" % variant]))
        data[name] = b
    layout = X.Layout(layout_bytes)
    new_s, new_e, rep = patch_members(data["Settings.bin"], data["Expressions.bin"], layout, texts, expr, want)
    mdir = os.path.join(out, "members", variant)
    os.makedirs(mdir, exist_ok=True)
    repl = {}
    outputs = {}
    for name, old, new in (("Settings.bin", data["Settings.bin"], new_s), ("Expressions.bin", data["Expressions.bin"], new_e)):
        if new != old:
            p = os.path.join(mdir, name)
            with open(p, "wb") as f:
                f.write(new)
            repl[int(mem[name]["key"], 16)] = new
            outputs[name] = {"path": os.path.relpath(p, out), "size": len(new), "sha256": sha256(new)}
    log("%s: %d Settings value(s), %d Expressions word(s) changed" % (arc_name, rep["settings_values"], rep["expression_words"]))
    res = {"members": outputs, "report": rep}
    if repl:
        log("rebuilding %s (%s mode, %s verify)..." % (arc_name, mode, "full" if full else "quick"))
        res["archive"] = rebuild(arc_bytes, repl, os.path.join(out, arc_name), mode, full)
        log("  %s %d bytes sha256 %s" % (arc_name, res["archive"]["size"], res["archive"]["sha256"]))
    else:
        log("%s: nothing to change for the chosen groups" % arc_name)
    return res


# --------------------------------------------------------------------------- safety

def check_out(out, work_root, sources):
    out = os.path.realpath(out)
    work = os.path.realpath(work_root)
    if os.path.commonpath([out, work]) != work or out == work:
        raise RetuneError("refusing: --out must be a new directory under %s" % work)
    if os.path.exists(out) and os.listdir(out):
        raise RetuneError("refusing: %s exists and is not empty" % out)
    for s in sources:
        s = os.path.realpath(s)
        inside_src = os.path.isdir(s) and os.path.commonpath([out, s]) == s
        holds_src = os.path.commonpath([out, s]) == out
        if inside_src or holds_src:
            raise RetuneError("refusing: --out overlaps the source %s" % s)
    return out


def check_archive(name, b, manifest):
    want = manifest["archives"][name]
    got = sha256(b)
    if got != want["sha256"] or len(b) != want["size"]:
        raise RetuneError("%s: sha256 %s (%d bytes) is not the retail %s (%d bytes); refusing to patch an unknown "
                          "or already modified archive" % (name, got, len(b), want["sha256"], want["size"]))


# --------------------------------------------------------------------------- game folder

def game_folder(src, out, core_path, log):
    dest = os.path.join(out, "game")
    if src.kind == "iso":
        cmd = [sys.executable, os.path.join(HERE, "ts4_iso_patch.py"), src.path, dest, "--arc", "Core.arc=%s" % core_path]
        log("running: %s" % " ".join(cmd))
        subprocess.run(cmd, check=True)
    else:
        log("copying %s -> %s (Core.arc replaced)" % (src.path, dest))
        shutil.copytree(src.path, dest, ignore=lambda d, names: ["Core.arc"] if os.path.realpath(d) == src.path else [])
        shutil.copyfile(core_path, os.path.join(dest, "Core.arc"))
    return dest


# --------------------------------------------------------------------------- main

def run(args, work_root=None, log=print):
    patch_dir = os.path.realpath(args.patches)
    manifest = load_manifest(patch_dir)
    groups = choose_groups(manifest, args.groups)
    src = Source(args.source)
    tu = TuSource(args.tu) if args.tu else None
    out = check_out(args.out, work_root or os.path.join(ROOT, "work"), [args.source] + ([args.tu] if args.tu else []))
    core = src.read("Core.arc")
    check_archive("Core.arc", core, manifest)
    lay = src.read("Layoutall.bin")
    if sha256(lay) != manifest["layouts"]["disc_sha256"]:
        raise RetuneError("disc Layoutall.bin sha256 %s is not the retail one" % sha256(lay))
    tu_arc = tu_lay = None
    if tu:
        with open(tu.arc, "rb") as f:
            tu_arc = f.read()
        check_archive(TU_ARC, tu_arc, manifest)
        with open(tu.layout, "rb") as f:
            tu_lay = f.read()
        if sha256(tu_lay) != manifest["layouts"]["tu1_sha256"]:
            raise RetuneError("title update Layoutall.bin sha256 %s is not the TU1 one" % sha256(tu_lay))
    log("groups: %s" % ", ".join(groups))
    os.makedirs(out, exist_ok=True)
    result = {"tool": "tools/apply_retune.py", "python": sys.version.split()[0], "patch_set": manifest["name"],
              "spec_commit": manifest.get("spec_commit"), "groups": groups, "mode": args.mode,
              "inputs": {"source": {"kind": src.kind, "Core.arc": manifest["archives"]["Core.arc"]}}}
    texts, expr = collect(patch_dir, manifest, groups, "disc")
    result["disc"] = do_archive("disc", "Core.arc", core, lay, manifest, texts, expr, out, args.mode, not args.quick, log)
    if tu:
        result["inputs"]["title_update"] = manifest["archives"][TU_ARC]
        texts, expr = collect(patch_dir, manifest, groups, "tu1")
        result["tu1"] = do_archive("tu1", TU_ARC, tu_arc, tu_lay, manifest, texts, expr, out, args.mode, not args.quick, log)
    if args.game_folder:
        core_path = os.path.join(out, "Core.arc")
        if not os.path.exists(core_path):
            raise RetuneError("no Core.arc was rebuilt (no change for the chosen groups); nothing to put in a folder")
        result["game_folder"] = os.path.relpath(game_folder(src, out, core_path, log), out)
    with open(os.path.join(out, "manifest.json"), "w") as f:
        json.dump(result, f, indent=1, sort_keys=True)
        f.write("\n")
    log("wrote %s" % out)
    return result


def list_groups(patch_dir):
    m = load_manifest(patch_dir)
    for g in m["groups"]:
        c = g.get("counts", {}).get("disc", {})
        readme = os.path.join(patch_dir, g["name"], "README.md")
        feel = ""
        if os.path.exists(readme):
            for line in open(readme):
                if line.startswith("**What the player should feel:**"):
                    feel = line.split("**", 2)[2].strip()
        print("%-14s %3d Settings values, %3d graph words  %s" % (g["name"], c.get("settings_values", 0),
                                                                  c.get("expression_words", 0), feel))


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--source", help="disc image (.iso) or extracted game folder (with Core.arc and Layoutall.bin)")
    ap.add_argument("--tu", help="Title Update #1: folder with TitleUpdate.arc and Layoutall.bin, or TitleUpdate.arc")
    ap.add_argument("--groups", default="all", help="'all', a comma list (ratings,timing,...), or -name,-name to leave out")
    ap.add_argument("--out", help="new directory under work/")
    ap.add_argument("--patches", default=DEFAULT_PATCHES, help="patch set directory (default tuning/retune-v0)")
    ap.add_argument("--mode", choices=("raw", "lzx-stored"), default="raw", help="member storage (docs/data-patching.md)")
    ap.add_argument("--quick", action="store_true", help="skip the writer's full decode of every member")
    ap.add_argument("--game-folder", action="store_true", help="also write OUT/game, a complete playable folder")
    ap.add_argument("--list", action="store_true", help="list the groups and exit")
    a = ap.parse_args(argv)
    if a.list:
        list_groups(a.patches)
        return 0
    if not a.source or not a.out:
        ap.error("--source and --out are required")
    try:
        run(a)
    except RetuneError as e:
        print("error: %s" % e, file=sys.stderr)
        return 2
    return 0


if __name__ == "__main__":
    sys.exit(main())
