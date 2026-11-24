#!/usr/bin/env python3
"""Export the Top Spin 4 front end (menus and in-match HUD) to a web-renderable folder.

  python3 tools/port/ui_export.py --iso "orig/54540859/disc_archive/Top Spin 4 (World) (En,Fr,De,Es,It).iso" \
      [--out work/port/assets/ui] [--archives Core,OnlineExhibition,...] [--no-textures] [--raw work/ui/raw]

Reads the user's own disc image in place and writes only below --out (git-ignored). Nothing produced
here may be committed (AGENTS.md); the committed, game-free summaries live in data/gameplay/ui/ and are made with
``--summary data/gameplay/ui`` (names, counts, flow edges and hashes only, no text, no images).

Output (docs/port/ui.md section 6):

  manifest.json                  archives read (sha256 of each), counts, per-part status
  scenes/<Name>.json             one per RUI scene: {"name", "archives", "scene" (Scenes.<Name> table:
                                 Controls, LayerList, TexturePackList, ...), "data" (SceneData: node graph
                                 with decoded PositioningInfo, NodeTypes, Templates), "actions" (decoded
                                 .actions scripts), "anims" (timeline names), "lua" (pseudo-Lua of the
                                 scene's closures), "action_closures" (__Action_N -> closure),
                                 "closure_writes" (static stores into currentScene/currentControl, e.g. list
                                 Items), "geometry" (expanded node path -> 2-D triangles + uv from PackedMeshes.xbin,
                                 matched through the scene's Hierarchy.xdt)}
  packages/<Name>.json           GUI packages (Boot, Common, InGame, OnlineExhib, ...): scenes, templates, fonts
  libs/<Name>.json               Lua libraries (CommonLib, MatchSettingsLib, ExhibitionLib, ...): globals + listing
  strings/<lang>.json            {key hex: text} for en/fr/de/es/it, plus strings/keys.json {key hex: name or null}
  fonts/<Name>.json (+ .png)     glyph tables of the .abc fonts and their texture pages
  textures/<Name>.png, textures.json   every texture of the UI texture packs (Core + menu archives)
  flow.json                      scene graph of ChangeScene / PushScene / package edges found in actions

Standard library only, plus the repository's own tools (ts4_arc, xdvdfs, ts4_texture).
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
TOOLS = os.path.join(ROOT, "tools")
for p in (HERE, TOOLS):
    if p not in sys.path:
        sys.path.insert(0, p)

from struct import error as struct_error  # noqa: E402

import lua50  # noqa: E402
import ui_actions  # noqa: E402
import ui_formats  # noqa: E402

# Archives holding RUI scenes. PracticeGroundPart.arc holds the boot flow and the main menu (start screen,
# attract mode, main menu and its sub menus, offline exhibition setup, options); PlayerBackGround.arc holds
# the InGame package (in-match HUD, pause, statistics; every venue archive carries the same package).
UI_ARCHIVES = [
    "Core", "PracticeGroundPart", "PlayerBackGround", "OnlineExhibition", "CareerMain", "CareerTournament", "PlayerAreaMenus",
    "PlayerCreator", "LockerRoom", "TopSpinAcademy", "KingOfTheCourtMenus", "KingOfTheCourt",
    "OnlineProChallenge", "OnlineWorldTour",
]
UI_MESH_SIG = bytes.fromhex("6912b1b83f65f116")   # PackedMeshes.xbin of UI meshes (docs/assets.md 4)
LUA_EXT = (".scene", ".sceneData", ".package", ".lua")
LUA_BIN = ("Lib.bin", "UnlockTrigger.bin")
LANG_ORDER = ("en", "fr", "de", "es", "it")
FLOW_CMDS = ("ChangeScene", "PushScene", "PopScene", "SwitchScene", "LoadPackage", "UnloadPackage",
             "ChangePackage", "PushPopup", "ShowPopup", "OpenPopup")


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def write_json(path, obj, compact=False):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8") as f:
        if compact:
            json.dump(obj, f, ensure_ascii=False, separators=(",", ":"))
        else:
            json.dump(obj, f, ensure_ascii=False, indent=1)


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


# ------------------------------------------------------------------------------------------ pure helpers

def eval_lua(data):
    """Evaluate a chunk: (globals as JSON, {closure path: pseudo-Lua lines}, calls, proto)."""
    f = lua50.load(data)
    g, calls = lua50.evaluate(f)
    glob = {k: ui_formats.scene_to_json(lua50.to_json(v), lua50.to_json) for k, v in g.items()}
    closures = {}
    for i, p in enumerate(f.p):
        closures["main.%d" % i] = lua50.decompile(p, "function main_%d" % i)
    return glob, calls, closures, f


def closure_writes(f):
    """Run every top-level closure symbolically with a fresh ``currentScene``/``currentControl`` and keep
    the stores into them (static list contents such as ``Controls["|MainMenu"].Items``, ItemMapping,
    text ids).  Returns {closure path: [[path, value], ...]} for closures that store something."""
    out = {}
    for i, p in enumerate(f.p):
        w = []
        env = {"currentScene": lua50.LuaTable("currentScene"), "currentControl": lua50.LuaTable("currentControl")}
        try:
            lua50.evaluate(p, max_steps=20000, env=env, args=[lua50.Ref("self")], vivify=True, writes=w)
        except (lua50.LuaFormatError, IndexError, TypeError, RecursionError):
            continue
        keep = [[k, lua50.to_json(v)] for k, v in w if k.startswith(("currentScene", "currentControl"))]
        if keep:
            out["main.%d" % i] = keep
    return out


def action_closures(scene_table):
    """{"__Action_N": "main.M"} from the Scenes.<Name> table."""
    out = {}
    if isinstance(scene_table, dict):
        for k, v in scene_table.items():
            if k.startswith("__Action_") and isinstance(v, dict) and "$function" in v:
                out[k] = v["$function"]
    return out


def mesh_to_2d(m):
    """UI mesh record (ts4_mesh.Mesh) -> {"pos": [[x, y]...], "uv": [[u, v]...], "tris": [[a, b, c]...]}.

    UI meshes lie in the x/z plane (y = 0); z is the screen's up axis (uv v = 0 at +z)."""
    pos = [[round(p[0], 3), round(p[2], 3)] for p in m.attrs.get("position", [])]
    uvk = next((k for k in m.attrs if k.startswith("uv")), None)
    uv = [[round(t[0], 5), round(t[1], 5)] for t in m.attrs[uvk]] if uvk else []
    tris = []
    for g in m.groups:
        tris.extend(list(t) for t in g.triangles())
    return {"pos": pos, "uv": uv, "tris": tris}


GEOMETRY_TYPES = ("Mesh", "UntexturedMesh", "Text", "ScrollText", "PamVideoPlayer", "PamWorldPosNode")
DRAWN_TYPES = ("Mesh", "UntexturedMesh", "PamVideoPlayer", "PamWorldPosNode")


def expanded_geometry_nodes(graph, load_template):
    """Depth-first walk of a scene graph with Template nodes expanded in place (the template's Graph
    children are visited where the Template node stands).  Yields (path, node) for every node whose type
    carries geometry; ``path`` is the child-index path, e.g. "1/0/2/t0/1" ("t" = inside a template).

    This order equals the order of the Geometry elements of the scene's Hierarchy.xdt (verified on all
    76 UI hierarchies of Core, PracticeGroundPart, PlayerBackGround and OnlineExhibition: same count)."""
    out = []

    def walk(n, path, depth):
        if not isinstance(n, dict) or depth > 64:
            return
        if "NodeNumber" in n:
            if n.get("Type") in GEOMETRY_TYPES:
                out.append((path, n))
            if n.get("Type") == "Template":
                t = load_template(n.get("TemplateName"))
                if t:
                    for i, c in enumerate(((t.get("data") or {}).get("Graph") or {}).get("Children") or []):
                        walk(c, "%s/t%d" % (path, i) if path else "t%d" % i, depth + 1)
        for i, c in enumerate(n.get("Children") or []):
            walk(c, "%s/%d" % (path, i) if path else str(i), depth + 1)

    walk(graph or {}, "", 0)
    return out


def closure_summary(listing):
    """Short form of a closure: the quoted names and globals it touches."""
    names = []
    for line in listing:
        names.extend(re.findall(r'"([A-Za-z_][\w|.]*)"', line))
    return sorted(set(names))


def flow_edges(scene, actions):
    """(command, target, action) for every scene/package transition in an actions script."""
    edges = []
    for act in actions:
        for blk in act.get("blocks", []):
            for st in blk["do"]:
                for cmd in FLOW_CMDS:
                    for m in re.finditer(r"\b%s\(([^)]*)\)" % cmd, st):
                        args = [a.strip().strip("'\"") for a in m.group(1).split(",")] if m.group(1) else []
                        edges.append({"from": scene, "cmd": cmd, "to": args[0] if args else None,
                                      "args": args[1:], "action": act["name"], "if": blk.get("if")})
    return edges


def collect_text_ids(obj, out):
    """Every TextID-like string field in a scene tree (localisation keys)."""
    if isinstance(obj, dict):
        for k, v in obj.items():
            if isinstance(v, str) and ("TextID" in k or k in ("StringID", "textID", "Key")):
                out.add(v)
            else:
                collect_text_ids(v, out)
    elif isinstance(obj, list):
        for v in obj:
            collect_text_ids(v, out)


def node_types(obj, out):
    if isinstance(obj, dict):
        t = obj.get("Type")
        if isinstance(t, str) and "NodeNumber" in obj:
            out[t] = out.get(t, 0) + 1
        for v in obj.values():
            node_types(v, out)
    elif isinstance(obj, list):
        for v in obj:
            node_types(v, out)


def _action_index(actions):
    return {a["name"]: a for a in actions}


def reachable_transitions(actions, start, depth=6, seen=None):
    """Scene transitions (ChangeScene / PushScene / PushLayer) reachable from one action by following
    ``$Scene.Action(...)`` and ``$Action`` calls of the same script (both branches of every condition)."""
    idx = _action_index(actions)
    seen = set() if seen is None else seen
    out = []
    if start in seen or depth < 0 or start not in idx:
        return out
    seen.add(start)
    for blk in idx[start].get("blocks", []):
        for st in blk["do"]:
            for m in re.finditer(r"\b(ChangeScene|PushScene|PushLayer)\('([^']+)'", st):
                out.append([m.group(1), m.group(2)])
            m = re.match(r"^\$(?:[A-Za-z0-9_]+\.)?([A-Za-z_][A-Za-z0-9_]*)", st.strip())
            if m:
                out.extend(reachable_transitions(actions, m.group(1), depth - 1, seen))
    return out


ID_TEST = re.compile(r"\.Id (~=|==) (-?\d+)")


def menu_targets(rec):
    """For list menus: {item Id: [[command, scene], ...]} from the scene's conditional actions.

    A Switch/If action has one block per case whose condition calls a closure testing
    ``currentControl.Items[curSel + 1].Id`` against a constant; the case action's transitions are
    collected with ``reachable_transitions``."""
    acts = rec.get("actions") or []
    lua = rec.get("lua") or {}
    clos = rec.get("action_closures") or {}
    out = {}
    for a in acts:
        for blk in a.get("blocks", []):
            cond = blk.get("if") or ""
            m = re.search(r"self\.(__Action_\d+)\(", cond)
            if not m or m.group(1) not in clos:
                continue
            body = "\n".join(lua.get(clos[m.group(1)], []))
            t = ID_TEST.search(body)
            if not t:
                continue
            item = int(t.group(2)) & 0xFFFFFFFF
            for st in blk["do"]:
                c = re.match(r"^\$(?:[A-Za-z0-9_]+\.)?([A-Za-z_][A-Za-z0-9_]*)", st.strip())
                if c:
                    tr = reachable_transitions(acts, c.group(1))
                    if tr:
                        out.setdefault("%08x" % item, []).extend(tr)
    return out


def static_lists(rec):
    """{control: {"items": [...], "mapping": [...]}} from the closure writes (last write wins)."""
    out = {}
    for _clo, writes in (rec.get("closure_writes") or {}).items():
        for path, val in writes:
            m = re.match(r"^currentScene\.Controls\.(.+)\.(Items|ItemMapping)$", path)
            if m and isinstance(val, list) and val:
                out.setdefault(m.group(1), {})["items" if m.group(2) == "Items" else "mapping"] = val
    return out


# ------------------------------------------------------------------------------------------ export

class Exporter:
    def __init__(self, args):
        self.a = args
        self.out = os.path.abspath(args.out)
        self.iso = find_iso(args.iso)
        self.manifest = {"tool": "tools/port/ui_export.py", "time": time.strftime("%Y-%m-%dT%H:%M:%S"),
                         "archives": {}, "parts": {}}
        self.scenes = {}      # name -> dict
        self.members = {}     # (name) -> [(archive, sha)]
        self.packages = {}
        self.libs = {}
        self.fonts = {}
        self.string_tables = []
        self.textures = {}
        self.text_ids = set()
        self.lua_strings = set()
        self.raw = {}
        self.ui_meshes = {}   # "Crc%X" -> 2-D mesh
        self.hierarchies = {}  # scene name -> [mesh name per Geometry element, in order]

    def log(self, *m):
        print(*m, flush=True)

    def open_archives(self):
        import ts4_arc
        import xdvdfs
        if not self.iso or not os.path.exists(self.iso):
            raise SystemExit("no disc image: pass --iso")
        x = xdvdfs.XDVDFS(self.iso)
        names = [n.strip() for n in self.a.archives.split(",")] if self.a.archives else UI_ARCHIVES
        for n in names:
            path = n if n.endswith(".arc") else n + ".arc"
            try:
                sl = x.open_slice(path)
            except FileNotFoundError:
                self.log("  skip %s (not on this disc)" % path)
                continue
            yield n, ts4_arc.Arc(sl), sl

    def run(self):
        for name, arc, sl in self.open_archives():
            self.read_archive(name, arc, sl)
        self.finish()

    def read_archive(self, aname, arc, sl):
        self.log("archive", aname)
        info = {"entries": arc.count, "ui_members": 0}
        h = hashlib.sha256()
        sl.seek(0)
        while True:
            b = sl.read(1 << 22)
            if not b:
                break
            h.update(b)
        info["sha256"] = h.hexdigest()
        groups = {}
        dirs = {}
        for dh, ns in arc.directories:
            for n in ns:
                dirs.setdefault(dh, []).append(n)
        for e in arc.entries:
            ln = arc.leaf_names.get(e[0])
            if not ln:
                continue
            dh, leaf = ln
            stem, ext = os.path.splitext(leaf)
            want = ext in LUA_EXT or ext in (".actions", ".anims", ".abc") or leaf.endswith(LUA_BIN) \
                or leaf in ("StringTable.bin", "PackedMeshes.xbin", "Hierarchy.xdt")
            is_pack = leaf == "Textures.xpr" and len(dirs.get(dh, [])) == 1
            if not (want or (is_pack and not self.a.no_textures)):
                continue
            data = arc.read(e)
            info["ui_members"] += 1
            if self.a.raw:
                rd = os.path.join(self.a.raw, aname)
                os.makedirs(rd, exist_ok=True)
                fn = leaf if leaf != "Textures.xpr" else "Textures_%08x.xpr" % dh
                with open(os.path.join(rd, fn), "wb") as f:
                    f.write(data)
            self.members.setdefault(leaf if not is_pack else "Textures_%08x.xpr" % dh, []).append(
                {"archive": aname, "entry": "%08x" % e[0], "sha256": sha256(data), "bytes": len(data)})
            try:
                if ext in (".scene", ".sceneData", ".actions", ".anims"):
                    groups.setdefault(stem, {})[ext] = data
                elif ext in (".package", ".lua") or leaf.endswith(LUA_BIN):
                    self.read_lua_lib(aname, stem, ext, data)
                elif ext == ".abc":
                    self.fonts.setdefault(stem, ui_formats.parse_abc_font(data))
                elif leaf == "StringTable.bin":
                    self.string_tables.append((aname, "%08x" % e[0], ui_formats.parse_string_table(data)))
                elif is_pack:
                    self.read_textures(aname, dh, data)
                elif leaf == "PackedMeshes.xbin" and data[:8] == UI_MESH_SIG:
                    self.read_ui_meshes(data)
                elif leaf == "Hierarchy.xdt" and data[:8] == b"PAM-XDT\0":
                    self.read_hierarchy(data)
            except (lua50.LuaFormatError, ui_formats.UiDataError, ui_actions.UiFormatError, ValueError) as ex:
                self.log("  warn %s/%s: %s" % (aname, leaf, ex))
        for stem, parts in groups.items():
            self.read_scene(aname, stem, parts)
        self.manifest["archives"][aname] = info

    def read_lua_lib(self, aname, stem, ext, data):
        if not lua50.is_lua(data):
            return
        glob, calls, closures, f = eval_lua(data)
        self.lua_strings.update(lua50.all_strings(f))
        rec = {"name": stem, "archive": aname, "globals": glob, "calls": calls,
               "functions": {k: closure_summary(v) for k, v in closures.items()}}
        if ext == ".package" or stem == "PackageHierarchy":
            self.packages.setdefault(stem, rec)
        else:
            rec["listing"] = lua50.disassemble(f)
            self.libs.setdefault(stem, rec)

    def read_scene(self, aname, stem, parts):
        digest = sha256(b"".join(parts.get(k, b"") for k in (".scene", ".sceneData", ".actions", ".anims")))
        if stem in self.scenes:
            first = self.scenes[stem]
            first["archives"].append(aname)
            if digest == first["sha256"]:
                return
            first.setdefault("variants", []).append(aname)
            stem_v = "%s@%s" % (stem, aname)        # a different build of the same scene in this archive
            if stem_v in self.scenes:
                return
            self._scene(aname, stem, stem_v, parts, digest)
            return
        self._scene(aname, stem, stem, parts, digest)

    def _scene(self, aname, stem, key, parts, digest):
        rec = {"name": stem, "archives": [aname], "sha256": digest}
        if ".scene" in parts and lua50.is_lua(parts[".scene"]):
            glob, calls, closures, f = eval_lua(parts[".scene"])
            self.lua_strings.update(lua50.all_strings(f))
            sc = glob.get("Scenes", {})
            rec["scene"] = sc.get(stem, sc) if isinstance(sc, dict) else sc
            rec["lua"] = closures
            rec["action_closures"] = action_closures(rec["scene"])
            rec["closure_writes"] = closure_writes(f)
        if ".sceneData" in parts and lua50.is_lua(parts[".sceneData"]):
            glob, _c, _cl, f = eval_lua(parts[".sceneData"])
            rec["data"] = glob.get("SceneData", glob)
            collect_text_ids(rec["data"], self.text_ids)
        if ".actions" in parts:
            acts = ui_actions.parse_actions(parts[".actions"])
            rec["actions"] = acts["actions"]
            self.lua_strings.update(acts["strings"])
        if ".anims" in parts:
            rec["anims"] = ui_actions.parse_anims(parts[".anims"])
        rec["menu_targets"] = menu_targets(rec)
        rec["lists"] = static_lists(rec)
        self.scenes[key] = rec

    def read_ui_meshes(self, data):
        import ts4_mesh
        for off in ts4_mesh.mesh_records(data):
            try:
                m = ts4_mesh.parse_mesh(data, off)
            except (KeyError, ValueError, IndexError, struct_error):
                continue
            self.ui_meshes.setdefault(m.name, mesh_to_2d(m))

    def read_hierarchy(self, data):
        import ts4_mesh
        try:
            root = ts4_mesh.parse_xdt(data)
        except (KeyError, ValueError, IndexError, struct_error):
            return
        name = root.attrs.get("Name")
        if isinstance(name, str):
            self.hierarchies.setdefault(name, [g.attrs.get("Mesh") for g in root.walk() if g.name == "Geometry"])

    def attach_geometry(self):
        """Give every drawn node of every top-level scene its UI mesh (by Hierarchy.xdt order)."""
        found = missing = mismatched = 0
        load = lambda n: self.scenes.get(n)  # noqa: E731
        for key, rec in self.scenes.items():
            order = self.hierarchies.get(rec["name"])
            if not order or "@" in key:
                continue
            nodes = expanded_geometry_nodes((rec.get("data") or {}).get("Graph"), load)
            if len(nodes) != len(order):
                mismatched += 1
                continue
            geo = {}
            for (path, node), mesh in zip(nodes, order):
                if node.get("Type") not in DRAWN_TYPES:
                    continue
                m = self.ui_meshes.get(mesh)
                if m:
                    geo[path] = m
                    found += 1
                else:
                    missing += 1
            rec["geometry"] = geo
        return {"resolved": found, "missing": missing, "scenes_count_mismatch": mismatched,
                "hierarchies": len(self.hierarchies)}

    def read_textures(self, aname, dh, data):
        import ts4_texture
        texs, _others = ts4_texture.parse_xpr2(data)
        for t in texs:
            if t.name in self.textures:
                continue
            ent = {"pack": "%s/%08x" % (aname, dh), "w": t.width, "h": t.height, "format": t.format_name}
            if not self.a.no_textures:
                try:
                    rgba = ts4_texture.decode_texture(t, data)
                    path = os.path.join(self.out, "textures", t.name + ".png")
                    os.makedirs(os.path.dirname(path), exist_ok=True)
                    ts4_texture.write_png(path, rgba, t.width, t.height)
                    ent["png"] = "textures/%s.png" % t.name
                except Exception as ex:  # unsupported formats are listed, not fatal
                    ent["error"] = str(ex)
            self.textures[t.name] = ent

    # -------------------------------------------------------------------------------------- outputs

    def finish(self):
        out = self.out
        os.makedirs(out, exist_ok=True)
        self.manifest["geometry"] = dict(self.attach_geometry(), ui_meshes=len(self.ui_meshes))
        flow = []
        for name, rec in sorted(self.scenes.items()):
            write_json(os.path.join(out, "scenes", name + ".json"), rec, compact=True)
            flow.extend(flow_edges(name, rec.get("actions", [])))
        for name, rec in self.packages.items():
            write_json(os.path.join(out, "packages", name + ".json"), rec)
        for name, rec in self.libs.items():
            write_json(os.path.join(out, "libs", name + ".json"), rec)
        write_json(os.path.join(out, "flow.json"), flow)
        # fonts: glyph table + the texture page of the same name
        for name, fnt in self.fonts.items():
            fj = dict(fnt)
            fj["map"] = {str(k): v for k, v in fnt["map"].items()}
            if name in self.textures:
                fj["texture"] = self.textures[name].get("png")
            write_json(os.path.join(out, "fonts", name + ".json"), fj, compact=True)
        write_json(os.path.join(out, "textures.json"), self.textures)
        # strings
        keys = {}
        names = {ui_formats.crc32(s): s for s in (self.text_ids | self.lua_strings)}
        langs = {}
        for aname, entry, tab in self.string_tables:
            texts = [e["text"] for e in tab["entries"]]
            lang, scores = ui_formats.guess_language(texts)
            if lang in langs:
                lang = "%s_%s" % (lang, entry)
            langs[lang] = {"entry": entry, "archive": aname, "count": len(texts), "scores": scores}
            write_json(os.path.join(out, "strings", lang + ".json"),
                       {"%08x" % e["key"]: e["text"] for e in tab["entries"]}, compact=True)
            write_json(os.path.join(out, "strings", lang + ".fonts.json"),
                       {"%08x" % e["key"]: [e["font"], e["scale"]] for e in tab["entries"] if e["font"]},
                       compact=True)
            for e in tab["entries"]:
                keys.setdefault("%08x" % e["key"], names.get(e["key"]))
        write_json(os.path.join(out, "strings", "keys.json"), keys, compact=True)
        self.manifest["parts"] = {
            "scenes": len(self.scenes), "packages": sorted(self.packages), "libs": sorted(self.libs),
            "fonts": sorted(self.fonts), "textures": len(self.textures), "languages": langs,
            "string_keys": len(keys), "named_keys": sum(1 for v in keys.values() if v),
            "flow_edges": len(flow),
        }
        self.manifest["members"] = self.members
        write_json(os.path.join(out, "manifest.json"), self.manifest)
        self.log("wrote", out, json.dumps({k: v for k, v in self.manifest["parts"].items()
                                          if k != "languages"}))
        if self.a.summary:
            write_summary(self, self.a.summary)


def write_summary(ex, outdir):
    """Game-free readable summaries for data/gameplay/ui/: names, counts, edges, hashes. No text, no images."""
    os.makedirs(outdir, exist_ok=True)
    src = {a: i["sha256"] for a, i in ex.manifest["archives"].items()}
    cmd = "python3 tools/port/ui_export.py --iso <disc> --summary data/gameplay/ui (python %s)" % sys.version.split()[0]
    screens = []
    for name, rec in sorted(ex.scenes.items()):
        nt = {}
        node_types(rec.get("data", {}), nt)
        sc = rec.get("scene") or {}
        screens.append({
            "name": name, "archives": rec["archives"],
            "layers": sc.get("LayerList") if isinstance(sc, dict) else None,
            "texture_packs": sc.get("TexturePackList") if isinstance(sc, dict) else None,
            "nodes": (rec.get("data") or {}).get("NodeCount"), "node_types": nt,
            "actions": [a["name"] for a in rec.get("actions", [])],
            "exports": [a["name"] for a in rec.get("actions", []) if a["name"].startswith("EXPORT_")],
            "menu_targets": rec.get("menu_targets") or None,
        })
    flow = []
    for name, rec in sorted(ex.scenes.items()):
        flow.extend(flow_edges(name, rec.get("actions", [])))
    pk = {n: {"scenes": (r["globals"].get("Package") or {}).get("Scenes"),
              "templates": (r["globals"].get("Package") or {}).get("Templates"),
              "fonts": (r["globals"].get("Package") or {}).get("Fonts"), "archive": r["archive"]}
          for n, r in ex.packages.items()}
    write_json(os.path.join(outdir, "screens.json"), {
        "command": cmd, "source_sha256": src, "screens": screens, "packages": pk})
    write_json(os.path.join(outdir, "flow.json"), {"command": cmd, "source_sha256": src, "edges": flow})
    keys = {}
    names = {ui_formats.crc32(s): s for s in (ex.text_ids | ex.lua_strings)}
    langs = {}
    for aname, entry, tab in ex.string_tables:
        lang, _ = ui_formats.guess_language([e["text"] for e in tab["entries"]])
        langs[lang] = entry
        for e in tab["entries"]:
            k = "%08x" % e["key"]
            keys.setdefault(k, {"name": names.get(e["key"]), "langs": []})["langs"].append(lang)
    write_json(os.path.join(outdir, "loc_keys.json"), {
        "command": cmd, "source_sha256": src, "string_tables": langs,
        "note": "key = zlib.crc32(TextID); names recovered from scene TextIDs and Lua/action strings; no text",
        "keys": dict(sorted(keys.items()))})


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--iso")
    ap.add_argument("--out", default=os.path.join(ROOT, "work", "port", "assets", "ui"))
    ap.add_argument("--archives", help="comma separated archive names (default: the UI set)")
    ap.add_argument("--no-textures", action="store_true", help="skip texture decoding (fast)")
    ap.add_argument("--raw", help="also dump the raw members here (git-ignored work/ folder)")
    ap.add_argument("--summary", help="write the committed, game-free summaries (data/gameplay/ui)")
    a = ap.parse_args(argv)
    Exporter(a).run()


if __name__ == "__main__":
    main()
