"""Build and test the portable simulation core (port/core) with the host compiler. Synthetic data only.

  * host build with `cc -std=c99 -Wall -Wextra -Werror` (all of ts4core + the ref/gameplay modules it reuses)
  * the C self-test (softmath, loader, graphs, ball determinism, rules glue, AI-vs-AI matches, human input)
  * the reference ball model's own golden-vector self-test, built against the ts4core software libm
  * the analyser-graph kernels in C against tools/ts4_analyser.py on random graphs (bit for bit)
  * data blob writer (port/core/tools/ts4d.py) against the C loader, registry vs docs, loader robustness
  * the WebAssembly build + a Node smoke test that must reproduce the host state hash (skipped when the
    wasm-capable clang, wasm-ld or node are missing)
"""
import math
import os
import random
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CORE = ROOT / "port" / "core"
REF = ROOT / "ref" / "gameplay"
sys.path.insert(0, str(CORE / "tools"))
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tests"))

import ts4d  # noqa: E402
from tools import ts4_analyser as A  # noqa: E402
from test_analyser import build_expressions  # noqa: E402

CORE_SRCS = [CORE / "src" / n for n in ("softmath.c", "data.c", "ball.c", "shot.c", "sim.c")]
REF_SRCS = [REF / n for n in ("rules.c", "movement.c", "ai_driver.c", "stats.c", "swing_window.c", "clip_fit.c")]
FLAGS = ["-std=c99", "-Wall", "-Wextra", "-Werror", "-ffp-contract=off", "-fno-fast-math", "-O2"]
INCLUDES = ["-I" + str(p) for p in (CORE / "shim", CORE / "include", CORE / "src", ROOT / "src" / "xbox360", REF)]


def bits(f):
    return struct.unpack("<I", struct.pack("<f", f))[0]


def f32(x):
    try:
        return struct.unpack("<f", struct.pack("<f", x))[0]
    except OverflowError:
        return math.copysign(math.inf, x)


class CoreCase(unittest.TestCase):
    cc = None
    tmp = None
    test_bin = None

    @classmethod
    def setUpClass(cls):
        cls.cc = shutil.which("cc")
        if cls.cc is None:
            raise unittest.SkipTest("no C compiler available")
        cls.tmp = tempfile.TemporaryDirectory()
        t = Path(cls.tmp.name)
        cls.test_bin = t / "ts4core_test"
        subprocess.run([cls.cc, *FLAGS, *INCLUDES, str(CORE / "test" / "test_core.c"), *map(str, CORE_SRCS),
                        *map(str, REF_SRCS), "-lm", "-o", str(cls.test_bin)], check=True)
        cls.blob = t / "synthetic.ts4d"
        cls.blob.write_bytes(ts4d.synthetic().build())
        cls.nograph = t / "nograph.ts4d"
        cls.nograph.write_bytes(ts4d.synthetic(graphs=False).build())
        cls.notpl = t / "notpl.ts4d"
        cls.notpl.write_bytes(ts4d.synthetic(templates_tree=False).build())

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def run_bin(self, *args, **kw):
        return subprocess.run([str(self.test_bin), *map(str, args)], capture_output=True, text=True, **kw)


class HostSuiteTests(CoreCase):
    def test_c_self_test_passes(self):
        r = self.run_bin(self.blob, self.nograph, self.notpl)
        self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
        self.assertIn(" 0 failures", r.stdout)
        self.assertIn("matches 1", r.stdout)       # a full one-set match terminates

    def test_reference_ball_model_golden_vectors_with_soft_libm(self):
        out = Path(self.tmp.name) / "gp4b_selftest"
        subprocess.run([self.cc, *FLAGS, "-DGP4B_SELFTEST", *INCLUDES,
                        str(ROOT / "src" / "xbox360" / "drafts" / "gp4b_ball_model.c"), str(CORE / "src" / "softmath.c"),
                        "-lm", "-o", str(out)], check=True)
        r = subprocess.run([str(out)], capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stdout)
        self.assertIn("SELFTEST PASSED", r.stdout)
        self.assertEqual(r.stdout.count("bit-exact vs original code"), 8)

    def test_determinism_across_optimisation_levels(self):
        results = set()
        for opt in ("-O0", "-O3"):
            exe = Path(self.tmp.name) / ("t" + opt)
            subprocess.run([self.cc, *[f for f in FLAGS if f != "-O2"], opt, *INCLUDES, str(CORE / "test" / "test_core.c"),
                            *map(str, CORE_SRCS), *map(str, REF_SRCS), "-lm", "-o", str(exe)], check=True)
            r = subprocess.run([str(exe), "--match", str(self.blob), "7", "3000"], capture_output=True, text=True)
            self.assertEqual(r.returncode, 0)
            results.add(r.stdout)
        ref = self.run_bin("--match", self.blob, "7", "3000").stdout
        results.add(ref)
        self.assertEqual(len(results), 1, results)

    def test_different_seeds_differ_same_seed_repeats(self):
        a = self.run_bin("--match", self.blob, "1", "2500").stdout
        b = self.run_bin("--match", self.blob, "1", "2500").stdout
        c = self.run_bin("--match", self.blob, "2", "2500").stdout
        self.assertEqual(a, b)
        self.assertNotEqual(a, c)


def random_graph(rng, name):
    n_in = rng.randint(1, 5)
    regs = n_in
    nodes = []
    fl = lambda: round(rng.uniform(-3, 3), 3)
    for _ in range(rng.randint(2, 14)):
        kind = rng.choice(["CONST", "SUM", "PRODUCT", "MIN", "MAX", "CURVE", "RUNSUM", "SUB", "DIV", "LERP", "INVLERP"])
        out = regs
        pick = lambda: rng.randrange(regs)
        if kind == "CONST":
            f = dict(out=out, value=fl())
        elif kind in ("SUM", "PRODUCT", "MIN", "MAX", "RUNSUM"):
            f = dict(slots=[pick() for _ in range(rng.randint(1, 5))], out=out)
        elif kind == "CURVE":
            xs = sorted(rng.uniform(-2, 2) for _ in range(rng.randint(1, 4)))
            keys = [(x, x + rng.uniform(0.0, 2.0), fl(), fl(), 0) for x in xs]
            if rng.random() < 0.2:
                rng.shuffle(keys)
            f = {"in": pick(), "out": out if rng.random() > 0.1 else -1, "keys": keys}
        elif kind in ("SUB", "DIV"):
            f = dict(a=pick(), b=pick(), out=out)
        else:
            f = dict(a=pick(), b=pick(), t=pick(), out=out)
        if f["out"] >= 0:
            regs += 1
        nodes.append((kind, f))
    outs = [(0xAA, max(regs - 1 - k, 0), 100 + k, [1, 2]) for k in range(min(3, regs))]   # (domain, register, cell, path)
    return dict(name=name, nregs=regs, inputs=[(0x1BF15200, i, i, [i + 1]) for i in range(n_in)],
                outputs=outs, nodes=nodes), n_in


class GraphParityTests(CoreCase):
    def test_c_graph_evaluator_matches_python_kernels_bit_for_bit(self):
        rng = random.Random(0x75D)
        specials = [0.0, -0.0, 1.0, -1.0, 0.5, math.inf, -math.inf, math.nan, 1e30, -1e30, 1e-30, 3.0e38, 100.0]
        graphs, specs = [], []
        for gi in range(60):
            spec, n_in = random_graph(rng, 0xC0DE0000 + gi)
            graphs.append(spec)
        img = build_expressions(graphs)
        parsed = A.parse_expressions(img)
        blob = ts4d.Blob()
        blob.graphs = ts4d.graphs_from_expressions(img)
        path = Path(self.tmp.name) / "graphs.ts4d"
        path.write_bytes(blob.build())
        lines, expect = [], []
        for g in parsed:
            for _ in range(40):
                vals = [rng.choice(specials) if rng.random() < 0.25 else f32(rng.uniform(-4, 4)) for _ in g.inputs]
                lines.append("%08x " % g.name + " ".join("%08x" % bits(f32(v)) for v in vals))
                expect.append(A.evaluate(g, vals))
        r = subprocess.run([str(self.test_bin), "--eval-stdin", str(path)], input="\n".join(lines) + "\n",
                           capture_output=True, text=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        got = r.stdout.strip().split("\n")
        self.assertEqual(len(got), len(expect))
        checked = 0
        for line, exp, src in zip(got, expect, lines):
            vals = [int(x, 16) for x in line.split()]
            self.assertEqual(len(vals), len(exp), src)
            for v, e in zip(vals, exp):
                ev = struct.unpack("<f", struct.pack("<I", v))[0]
                if math.isnan(e):
                    self.assertTrue(math.isnan(ev), (src, line))
                else:
                    self.assertEqual(v, bits(f32(e)), (src, line, e))
                checked += 1
        self.assertGreater(checked, 3000)


class DataFormatTests(CoreCase):
    def test_registry_is_documented_and_provisional_file_is_complete(self):
        doc = (ROOT / "docs" / "port" / "data-format.md").read_text(encoding="utf-8")
        reg = ts4d.parse_tunables()
        self.assertGreater(len(reg), 60)
        for e in reg:
            self.assertIn("`%s`" % e["name"], doc, e["name"])
        vars_, roles = ts4d.parse_roles()
        for r in roles:
            self.assertIn("`%s`" % r["name"], doc)
        prov = ts4d.provisional_tunables()
        self.assertEqual({e["name"] for e in reg if e["req"] == "R"} - set(prov), set())
        self.assertEqual(set(prov) - {e["name"] for e in reg}, set())

    def test_blob_roundtrip_and_key_function(self):
        data = ts4d.read_blob(self.blob.read_bytes())
        self.assertEqual(set(data["sections"]), {"TUNE", "TPLS", "TREE", "GRPH", "ROLE", "CURV"})
        keys = sorted(ts4d.crc(e["name"]) for e in ts4d.parse_tunables())
        self.assertEqual(sorted(data["tunables"]), keys)
        self.assertEqual(ts4d.crc("IsTopSpin"), 0xF271F3C8)
        self.assertEqual(data["templates"]["rows"], len(ts4d.SYN_ROWS))
        self.assertEqual(len(data["tree"]["nodes"]), 8)

    def test_synthetic_blob_has_no_game_data_marker(self):
        raw = self.blob.read_bytes()
        self.assertLess(len(raw), 64 * 1024)
        self.assertFalse(any(row["id"] in (0x9CAFB633,) for row in ts4d.SYN_ROWS))   # not the game's Wood id

    def test_loader_survives_corrupted_headers(self):
        raw = bytearray(self.blob.read_bytes())
        info = ts4d.read_blob(bytes(raw))
        rng = random.Random(5)
        # keep the template payload intact: its self-relative pointers are game bytes the loader does not walk
        nsec = struct.unpack_from("<I", raw, 8)[0]
        tpls = None
        for i in range(nsec):
            tag, off, size, _ = struct.unpack_from("<4sIII", raw, 16 + 16 * i)
            if tag == b"TPLS":
                tpls = (off, off + size)
        outcomes = set()
        for n in range(150):
            m = bytearray(raw)
            for _ in range(rng.randint(1, 4)):
                pos = rng.randrange(len(m))
                if tpls and tpls[0] + 16 <= pos < tpls[1]:
                    continue
                m[pos] = rng.randrange(256)
            if n % 10 == 0:
                m = m[:rng.randrange(8, len(m))]
            p = Path(self.tmp.name) / "fuzz.ts4d"
            p.write_bytes(bytes(m))
            r = self.run_bin("--match", p, "1", "50")
            self.assertIn(r.returncode, (0, 2), (n, r.returncode, r.stderr[-200:]))
            outcomes.add(r.returncode)
        self.assertIn(2, outcomes)       # some corruptions are rejected
        self.assertGreaterEqual(info["sections"]["TUNE"], 12)

    def test_graph_conversion_keeps_ports(self):
        spec, n_in = random_graph(random.Random(1), 0x1234)
        img = build_expressions([spec])
        g = ts4d.graphs_from_expressions(img)[0]
        self.assertEqual(g["name_hash"], 0x1234)
        self.assertEqual(len(g["inputs"]), n_in)
        self.assertEqual([p[2] for p in g["inputs"]], list(range(n_in)))


class WasmTests(unittest.TestCase):
    def test_wasm_build_reproduces_host_state_hash(self):
        node = shutil.which("node")
        clang = None
        for c in (os.environ.get("CLANG"), "/opt/homebrew/opt/llvm/bin/clang", "/usr/local/opt/llvm/bin/clang", shutil.which("clang")):
            if c and os.path.exists(c):
                out = subprocess.run([c, "--print-targets"], capture_output=True, text=True).stdout
                if "wasm32" in out:
                    clang = c
                    break
        if not (node and clang and (shutil.which("wasm-ld") or os.path.exists(os.path.join(os.path.dirname(clang), "wasm-ld")))):
            self.skipTest("wasm32-capable clang + wasm-ld + node not all available")
        with tempfile.TemporaryDirectory() as t:
            env = dict(os.environ, CLANG=clang, OUT=t)
            subprocess.run([str(CORE / "build_wasm.sh")], check=True, env=env, capture_output=True)
            wasm = Path(t) / "ts4core.wasm"
            self.assertGreater(wasm.stat().st_size, 10000)
            blob = Path(t) / "synthetic.ts4d"
            blob.write_bytes(ts4d.synthetic().build())
            exe = Path(t) / "host"
            cc = shutil.which("cc")
            subprocess.run([cc, *FLAGS, *INCLUDES, str(CORE / "test" / "test_core.c"), *map(str, CORE_SRCS),
                            *map(str, REF_SRCS), "-lm", "-o", str(exe)], check=True)
            host = subprocess.run([str(exe), "--match", str(blob), "7", "6000"], capture_output=True, text=True, check=True).stdout
            host_hash = host.split()[1]
            r = subprocess.run([node, str(CORE / "test" / "wasm_smoke.mjs"), str(wasm), str(blob), "7", "6000", host_hash],
                               capture_output=True, text=True)
            self.assertEqual(r.returncode, 0, r.stdout + r.stderr)
            self.assertIn("wasm smoke OK", r.stdout)
            # host and wasm agree on a ball trace digest too (software exp/log/fmaf on both)
            trace_host = subprocess.run([str(exe), "--trace", str(blob), "1"], capture_output=True, text=True).stdout
            self.assertIn("digest", trace_host)


if __name__ == "__main__":
    unittest.main()
