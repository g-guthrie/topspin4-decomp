"""Tests for the playable browser viewer (port/web) and the reference JS binding (port/core/js).

* struct sizes of the JS binding recomputed from include/ts4core.h (the Ts4ShotIn 60 vs 64 question)
* config file sanity (clipmap.config.json, placeholders labelled)
* the pure JS helpers (node --test) and a headless play-path smoke run against a built wasm; both skipped when node,
  the wasm build or the exported blob are missing
"""
import json
import os
import re
import shutil
import subprocess
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
HEADER = os.path.join(ROOT, "port", "core", "include", "ts4core.h")
BINDING = os.path.join(ROOT, "port", "core", "js", "ts4core.mjs")
WEB = os.path.join(ROOT, "port", "web")
WASM = os.path.join(ROOT, "work", "port", "ts4core.wasm")
BLOB = os.path.join(ROOT, "work", "port", "assets", "gameplay", "ts4core.dat")
NODE = shutil.which("node")


def header_struct_sizes(text):
    """sizeof of every typedef struct of the header: all fields are 4 bytes (uint32/int32/float), nested structs and arrays."""
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    structs = {}
    for m in re.finditer(r"typedef struct (\w+)\s*\{(.*?)\}\s*(\w+)\s*;", text, flags=re.S):
        structs[m.group(3)] = m.group(2)
    sizes = {}

    def size(name):
        if name in sizes:
            return sizes[name]
        total = 0
        for decl in structs[name].split(";"):
            decl = decl.strip()
            if not decl:
                continue
            tm = re.match(r"(uint32_t|int32_t|float|Ts4\w+)\s+(.*)$", decl, flags=re.S)
            base, rest = tm.group(1), tm.group(2)
            unit = 4 if base in ("uint32_t", "int32_t", "float") else size(base)
            for var in rest.split(","):          # "float pos[3]" or "a, b, c"
                count = 1
                for n in re.findall(r"\[(\w+)\]", var):
                    count *= int(n) if n.isdigit() else {"TS4_STAT_COUNT": 8}[n]
                total += unit * count
        sizes[name] = total
        return total

    return {n: size(n) for n in structs}


class BindingLayout(unittest.TestCase):
    def test_header_sizes(self):
        s = header_struct_sizes(open(HEADER).read())
        self.assertEqual(s["Ts4ShotIn"], 60)
        self.assertEqual(s["Ts4ShotOut"], 52)
        self.assertEqual(s["Ts4Snapshot"], 256)
        self.assertEqual(s["Ts4Event"], 32)
        self.assertEqual(s["Ts4Input"], 12)
        self.assertEqual(s["Ts4MatchConfig"], 120)

    def test_binding_matches_header(self):
        s = header_struct_sizes(open(HEADER).read())
        src = open(BINDING).read()
        m = re.search(r"export const SIZES = \{([^}]*)\}", src)
        js = {k: int(v) for k, v in re.findall(r"(\w+):\s*(\d+)", m.group(1))}
        self.assertEqual(js, {"snapshot": s["Ts4Snapshot"], "event": s["Ts4Event"], "matchConfig": s["Ts4MatchConfig"],
                              "input": s["Ts4Input"], "shotIn": s["Ts4ShotIn"], "shotOut": s["Ts4ShotOut"]})
        self.assertNotIn("64", re.findall(r"shotIn:\s*(\d+)", src))

    def test_web_adapter_matches_header(self):
        s = header_struct_sizes(open(HEADER).read())
        src = open(os.path.join(WEB, "src", "core.js")).read()
        self.assertEqual(int(re.search(r"SHOT_IN_WORDS = (\d+)", src).group(1)) * 4, s["Ts4ShotIn"])
        self.assertEqual(int(re.search(r"SHOT_OUT_WORDS = (\d+)", src).group(1)) * 4, s["Ts4ShotOut"])


class ClipMapConfig(unittest.TestCase):
    def setUp(self):
        self.cfg = json.load(open(os.path.join(WEB, "clipmap.config.json")))

    def test_labelled_placeholder(self):
        self.assertTrue(self.cfg["placeholder"])
        self.assertIn("PLACEHOLDER", self.cfg["_status"])

    def test_every_class_resolves(self):
        ref = re.compile(r"^core:\d+$")
        for name in ("idle", "jog", "run", "rush"):
            self.assertRegex(self.cfg["locomotion"][name]["clip"], ref)
        for key, e in self.cfg["swing"].items():
            if not key.startswith("_"):
                self.assertRegex(e["clip"], ref, key)
        for need in ("default", "serve", "smash", "volley_fh", "volley_bh", "lob", "drop", "fh_flat", "bh_flat"):
            self.assertIn(need, self.cfg["swing"])


@unittest.skipUnless(NODE, "node not installed")
class NodeTests(unittest.TestCase):
    def test_helpers(self):
        r = subprocess.run([NODE, "--test", os.path.join(WEB, "test", "helpers.test.mjs")], capture_output=True, text=True, timeout=120)
        self.assertEqual(r.returncode, 0, r.stdout[-3000:] + r.stderr[-1000:])

    @unittest.skipUnless(os.path.exists(WASM) and os.path.exists(BLOB), "needs work/port/ts4core.wasm and the exported blob")
    def test_play_path_smoke(self):
        r = subprocess.run([NODE, os.path.join(WEB, "test", "session_smoke.mjs"), WASM, BLOB], capture_output=True, text=True, timeout=120)
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
        self.assertIn("session smoke OK", r.stdout)


if __name__ == "__main__":
    unittest.main()
