"""Tests for tools/icf_alias.py and its users (synthetic objects and symbols, no compiler, no game data)."""

import json
import os
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import fn_check  # noqa: E402
import fn_check_ltcg as L  # noqa: E402
import icf_alias as A  # noqa: E402
from xcoff import read_coff  # noqa: E402

SYMBOLS = [("ts4_release_881A2570", ".text", 0x881A2570, 0x74), ("fn_881A2508", ".text", 0x881A2508, 0x64),
           ("lbl_880D6B70", ".rdata", 0x880D6B70, None), ("?Set@W@@QAAXPBGH@Z", ".text", 0x8819C360, 0x8C),
           ("g_ts4_event_value", "BINKCONS", 0x8814B440, 4), ("lbl_880F4460", ".rdata", 0x880F4460, None)]
ENTRIES = [A.Alias("ts4_release_881A2570_icf_b", "ts4_release_881A2570", 0x881A2570, "icf", "two bl"),
           A.Alias("lbl_880D6B70_icf_b", "lbl_880D6B70", 0x880D6B70, "icf", "two lis"),
           A.Alias("ts4_w_set_8819C360", "?Set@W@@QAAXPBGH@Z", 0x8819C360, "cxx", "member")]


def coff(symbols, relocs, strings_last=True):
    """A COFF object with one .text section. symbols: [(name, section number)] (storage class 2);
    relocs: [(offset, symbol index, kind)]."""
    code = bytes(4 * max(1, len(relocs)))
    table, strings = b"", b""
    for name, section in symbols:
        raw = name.encode()
        if len(raw) > 8:
            field = struct.pack("<II", 0, 4 + len(strings))
            strings += raw + b"\0"
        else:
            field = raw.ljust(8, b"\0")
        table += field + struct.pack("<IhHBB", 0, section, 0x20, 2, 0)
    code_at = 20 + 40
    rel_at = code_at + len(code)
    sym_at = rel_at + 10 * len(relocs)
    head = struct.pack("<HHIIIHH", 0x1F2, 1, 0, sym_at, len(symbols), 0, 0)
    section = struct.pack("<8sIIIIIIHHI", b".text", 0, 0, len(code), code_at, rel_at, 0, len(relocs), 0, 0x60000020)
    body = b"".join(struct.pack("<IIH", off, index, kind) for off, index, kind in relocs)
    return head + section + code + body + table + struct.pack("<I", 4 + len(strings)) + strings


def read(data):
    with tempfile.NamedTemporaryFile(suffix=".obj") as handle:
        handle.write(data)
        handle.flush()
        return read_coff(Path(handle.name))


class Validation(unittest.TestCase):
    def test_valid_entries(self):
        self.assertEqual(A.problems(ENTRIES, SYMBOLS), [])

    def test_problems(self):
        bad = [A.Alias("fn_881A2508", "ts4_release_881A2570", 0x881A2570, "icf", "x"),      # a symbols.txt name
               A.Alias("a_b", "ts4_release_881A2570", 0x881A2574, "icf", "x"),              # no symbol there
               A.Alias("a_c", "other", 0x881A2570, "icf", "x"),                             # wrong canonical
               A.Alias("a_d", "ts4_release_881A2570", 0x881A2570, "icf", " "),              # no evidence
               A.Alias("a_e", "ts4_release_881A2570", 0x881A2570, "cxx", "x"),              # not decorated
               A.Alias("?a@@YAXXZ", "ts4_release_881A2570", 0x881A2570, "icf", "x"),        # not a C name
               A.Alias("a_f", "ts4_release_881A2570", 0x881A2570, "guess", "x")]
        text = "\n".join(A.problems(bad, SYMBOLS))
        for needle in ("is a symbols.txt name", "no symbol at 0x881a2574", "canonical other is not the name",
                       "a_d: no evidence", "a_e: kind cxx", "an alias is a C identifier", "kind 'guess'"):
            self.assertIn(needle, text)

    def test_committed_file_is_valid(self):
        from xcoff import load_symbols
        entries = A.load()
        self.assertEqual(A.problems(entries, load_symbols(ROOT / "config" / "54540859" / "symbols.txt")), [])

    def test_map(self):
        m = A.AliasMap(ENTRIES)
        self.assertTrue(m.same("ts4_release_881A2570_icf_b", 0x881A2570))
        self.assertFalse(m.same("ts4_release_881A2570_icf_b", 0x881A2574))   # never another address
        self.assertFalse(m.same("ts4_release_881A2570_icf_b", None))
        self.assertFalse(m.same("ts4_release_881A2570", 0x881A2570))          # only listed aliases
        self.assertEqual(m.c_name("?Set@W@@QAAXPBGH@Z"), "ts4_w_set_8819C360")
        self.assertIsNone(m.c_name("ts4_release_881A2570"))                   # icf aliases are not C spellings
        self.assertEqual(m.names(SYMBOLS)["lbl_880D6B70_icf_b"], "lbl_880D6B70")

    def test_placeholder_address(self):
        self.assertEqual(A.placeholder_address("lbl_8814B440"), 0x8814B440)
        self.assertEqual(A.placeholder_address("fn_881A2508"), 0x881A2508)
        self.assertIsNone(A.placeholder_address("lbl_8814B440_icf_b"))
        self.assertIsNone(A.placeholder_address("g_ts4_event_value"))


class PlainChecker(unittest.TestCase):
    """fn_check.same_target: the three ways two names are one target, and nothing more."""

    def setUp(self):
        self.address = {name: address for name, _s, address, _z in SYMBOLS}
        self.address["lbl_8814B440"] = 0x8814B440           # the b224 split had both names
        self.known = set(self.address)
        self.aliases = A.AliasMap(ENTRIES)

    def verdict(self, c, t, known=None):
        return fn_check.same_target(c, t, self.address, self.known if known is None else known, self.aliases)

    def test_alias_equals_its_canonical(self):
        self.assertEqual(self.verdict("ts4_release_881A2570_icf_b", "ts4_release_881A2570"), "same")
        self.assertEqual(self.verdict("ts4_w_set_8819C360", "?Set@W@@QAAXPBGH@Z"), "same")
        self.assertEqual(self.verdict("lbl_880D6B70_icf_b", "lbl_880D6B70"), "same")

    def test_alias_for_another_symbol_is_a_problem(self):
        self.assertIn("stands for 0x880d6b70", self.verdict("lbl_880D6B70_icf_b", "lbl_880F4460"))
        self.assertIn("stands for", self.verdict("ts4_release_881A2570_icf_b", "fn_881A2508"))

    def test_two_names_of_one_address(self):
        self.assertEqual(self.verdict("g_ts4_event_value", "lbl_8814B440"), "same")
        self.assertEqual(self.verdict("lbl_8814B440", "g_ts4_event_value"), "same")

    def test_stale_placeholder(self):
        del self.address["lbl_8814B440"]                     # after the seed fix only the real name is left
        known = set(self.address)
        self.assertEqual(self.verdict("lbl_8814B440", "g_ts4_event_value", known), "stale")
        self.assertIsNone(self.verdict("lbl_8814B444", "g_ts4_event_value", known))   # another address
        self.assertIsNone(self.verdict("my_zero", "g_ts4_event_value", known))        # not a placeholder

    def test_unrelated_names_are_left_to_the_other_rules(self):
        self.assertIsNone(self.verdict("ts4_new_name", "fn_881A2508"))
        self.assertIsNone(self.verdict("lbl_880D6B70", "lbl_880F4460"))


class LtcgChecker(unittest.TestCase):
    """fn_check_ltcg.compare: `bl a; bl b` in the candidate against two `bl` of one target address."""

    START = 0x82002000

    def run_compare(self, second, aliases=A.AliasMap(ENTRIES), target_second=0x881A2570, known=None):
        c_code = b"".join(w.to_bytes(4, "big") for w in (0x48000101, 0x48000201))   # bl +0x100; bl +0x200
        c_sites = [L.Site(0, L.REL24, self.START + 0x100), L.Site(4, L.REL24, self.START + 0x204)]
        c_index = L.SymbolIndex([("f", self.START), ("ts4_release_881A2570", self.START + 0x100),
                                 (second, self.START + 0x204)])
        t_start = 0x881A2508
        t_code = c_code
        t_sites = [L.Site(0, L.REL24, 0x881A2570), L.Site(4, L.REL24, target_second)]
        t_index = L.SymbolIndex([(n, a) for n, _s, a, _z in SYMBOLS])
        names = {n: a for n, _s, a, _z in SYMBOLS}
        return L.compare(c_code, c_sites, self.START, c_index, None, t_code, t_sites, t_start, t_index, None,
                         known_names=set(names) if known is None else known, aliases=aliases, name_address=names)

    def test_alias_accepted(self):
        res = self.run_compare("ts4_release_881A2570_icf_b")
        self.assertTrue(res.ok, res.problems)
        self.assertEqual(res.renames, {})

    def test_without_the_alias_file_it_fails(self):
        res = self.run_compare("ts4_release_881A2570_icf_b", aliases=A.AliasMap([]))
        self.assertFalse(res.ok)

    def test_alias_at_another_address_fails(self):
        res = self.run_compare("ts4_release_881A2570_icf_b", target_second=0x8819C360)
        self.assertFalse(res.ok)
        self.assertIn("stands for 0x881a2570", " ".join(res.problems))

    def test_unlisted_second_name_fails(self):
        self.assertFalse(self.run_compare("ts4_release_copy").ok)

    def test_cxx_alias(self):
        res = self.run_compare("ts4_w_set_8819C360", target_second=0x8819C360)
        self.assertTrue(res.ok, res.problems)

    def test_stale_placeholder_is_reported(self):
        res = self.run_compare("lbl_8814B440", target_second=0x8814B440)
        self.assertTrue(res.ok, res.problems)
        self.assertEqual(res.stale, {"lbl_8814B440": "g_ts4_event_value"})
        self.assertFalse(self.run_compare("lbl_8814B444", target_second=0x8814B440).ok)

    def test_alias_stub_is_a_function(self):
        text, _names = L.stub_source(["ts4_release_881A2570_icf_b", "lbl_880D6B70_icf_b"],
                                     {"ts4_release_881A2570_icf_b"})
        self.assertIn("void lt1stub_0(void)", text)
        self.assertIn("int lt1stub_1[4]", text)


class ObjectPatch(unittest.TestCase):
    MAP = {"ts4_release_881A2570_icf_b": "ts4_release_881A2570", "al_s": "short_nm",
           "ts4_w_set_8819C360": "?Set@W@@QAAXPBGH@Z"}

    def test_rename_when_the_canonical_is_absent(self):
        data = coff([("caller", 1), ("ts4_w_set_8819C360", 0), ("al_s", 0)], [(0, 1, 6), (4, 2, 6)])
        new, found = A.rename_references(data, self.MAP)
        self.assertEqual(sorted(found), ["al_s", "ts4_w_set_8819C360"])
        obj = read(new)
        self.assertEqual([r.symbol for r in obj.sections[0].relocs], ["?Set@W@@QAAXPBGH@Z", "short_nm"])
        self.assertEqual([s.name for s in obj.symbols], ["caller", "?Set@W@@QAAXPBGH@Z", "short_nm"])
        self.assertEqual(obj.sections[0].data, read(data).sections[0].data)   # code untouched

    def test_relocations_move_to_an_existing_canonical(self):
        data = coff([("caller", 1), ("ts4_release_881A2570", 0), ("ts4_release_881A2570_icf_b", 0)],
                    [(0, 1, 6), (4, 2, 6)])
        new, found = A.rename_references(data, self.MAP)
        self.assertEqual(found, ["ts4_release_881A2570_icf_b"])
        self.assertEqual(len(new), len(data))
        self.assertEqual([r.symbol for r in read(new).sections[0].relocs], ["ts4_release_881A2570"] * 2)

    def test_untouched_without_aliases(self):
        data = coff([("caller", 1), ("ts4_release_881A2570", 0)], [(0, 1, 6)])
        self.assertEqual(A.rename_references(data, self.MAP), (data, []))

    def test_defined_alias_is_refused(self):
        data = coff([("ts4_release_881A2570_icf_b", 1)], [])
        with self.assertRaises(SystemExit):
            A.rename_references(data, self.MAP)

    def test_patch_rebuilt_stops_on_an_invalid_file(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            (tmp / "symbols.txt").write_text("ts4_release_881A2570 = .text:0x881A2570; // type:function size:0x74\n")
            A.save([A.Alias("x_alias", "renamed_since", 0x881A2570, "icf", "e")], tmp / "aliases.json")
            with self.assertRaises(SystemExit):
                A.patch_rebuilt([], tmp / "symbols.txt", tmp / "aliases.json")
            A.save([ENTRIES[0]], tmp / "aliases.json")
            obj = tmp / "u.obj"
            obj.write_bytes(coff([("caller", 1), ("ts4_release_881A2570_icf_b", 0)], [(0, 1, 6)]))
            done = A.patch_rebuilt([obj], tmp / "symbols.txt", tmp / "aliases.json")
            self.assertEqual(done, {str(obj): ["ts4_release_881A2570_icf_b"]})
            self.assertEqual(read(obj.read_bytes()).sections[0].relocs[0].symbol, "ts4_release_881A2570")


class Registry(unittest.TestCase):
    def test_register_and_follow_renames(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / "aliases.json"
            item = {"canonical": "fn_881A2570", "address": "0x881A2570", "kind": "icf", "evidence": "two bl"}
            self.assertEqual(len(A.register({"a_b": item}, path)), 1)
            self.assertEqual(A.register({"a_b": item}, path), [])                      # identical: kept
            with self.assertRaises(SystemExit):
                A.register({"a_b": dict(item, address="0x881A2574")}, path)            # another address
            self.assertEqual(A.follow_renames({"fn_881A2570": "ts4_release_881A2570"}, path), 1)
            self.assertEqual(A.load(path)[0].canonical, "ts4_release_881A2570")


def scratch_tree(tmp: Path, tools=("fix_refs.py", "xcoff.py", "icf_alias.py")) -> None:
    (tmp / "tools").mkdir()
    for name in tools:
        shutil.copy(ROOT / "tools" / name, tmp / "tools" / name)
    (tmp / "config" / "54540859").mkdir(parents=True)
    (tmp / "src" / "xbox360").mkdir(parents=True)


class FixRefs(unittest.TestCase):
    """tools/fix_refs.py end to end in a scratch repository: a member's decorated name never
    lands in a caller; the caller gets the "cxx" alias."""

    def test_callers_get_the_c_alias(self):
        if shutil.which("git") is None:
            self.skipTest("git not available")
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            scratch_tree(tmp)
            symbols = tmp / "config" / "54540859" / "symbols.txt"
            symbols.write_text("fn_8819C360 = .text:0x8819C360; // type:function size:0x8C\n"
                               "fn_881A2508 = .text:0x881A2508; // type:function size:0x64\n")
            caller = tmp / "src" / "xbox360" / "caller.c"
            caller.write_text("void fn_8819C360(void *, void *, int);\nvoid fn_881A2508(void *);\n"
                              "void f(void *a) { fn_8819C360(a, a, 1); fn_881A2508(a); }\n")
            member = tmp / "src" / "xbox360" / "member.cpp"
            member.write_text("/* fn_8819C360 */ struct W { void Set(const unsigned short *, int); };\n")
            spec = tmp / "spec.json"
            spec.write_text(json.dumps({
                "source": "src/xbox360/member.cpp",
                "functions": {"?Set@W@@QAAXPBGH@Z": "0x8819C360", },
                "aliases": {"ts4_w_set_8819C360": {"canonical": "?Set@W@@QAAXPBGH@Z", "address": "0x8819C360",
                                                   "kind": "cxx", "evidence": "member"}}}))
            plain = tmp / "plain.json"
            plain.write_text(json.dumps({"source": "src/xbox360/caller2.c",
                                         "functions": {"ts4_reset_881A2508": "0x881A2508"}}))
            (tmp / "src" / "xbox360" / "caller2.c").write_text("void ts4_reset_881A2508(void *p) { }\n")
            env = {k: v for k, v in os.environ.items() if k != "TS4_MATCHING_DIR"}
            git = ["git", "-c", "user.name=t", "-c", "user.email=t@example.invalid", "-c", "commit.gpgsign=false"]
            for cmd in (["git", "init", "-q"], ["git", "add", "-A"], git + ["commit", "-q", "-m", "base"]):
                subprocess.run(cmd, cwd=tmp, check=True, env=env, capture_output=True)
            run = subprocess.run([sys.executable, "tools/fix_refs.py", "spec.json", "plain.json"], cwd=tmp, env=env,
                                 capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stdout + run.stderr)
            text = caller.read_text()
            self.assertIn("ts4_w_set_8819C360(a, a, 1)", text)
            self.assertIn("ts4_reset_881A2508(a)", text)             # an ordinary rename still works
            self.assertNotIn("?Set", text)
            self.assertNotIn("fn_8819C360", text)
            self.assertIn("/* ts4_w_set_8819C360 */", member.read_text())
            # Without the alias the script stops instead of writing a decorated name into C.
            spec.write_text(json.dumps({"source": "src/xbox360/member.cpp",
                                        "functions": {"?Set@W@@QAAXPBGH@Z": "0x8819C360"}}))
            subprocess.run(["git", "checkout", "-q", "--", "src"], cwd=tmp, check=True, env=env)
            run = subprocess.run([sys.executable, "tools/fix_refs.py", "spec.json"], cwd=tmp, env=env,
                                 capture_output=True, text=True)
            self.assertNotEqual(run.returncode, 0)
            self.assertIn('needs a "cxx" alias', run.stdout + run.stderr)
            self.assertIn("fn_8819C360(a, a, 1)", caller.read_text())


class Integrate(unittest.TestCase):
    """tools/integrate_match.py in a scratch tree: a decorated name is registered for the address,
    the spec's aliases reach icf_aliases.json and follow the batch's renames."""

    def test_spec_with_aliases(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            scratch_tree(tmp, ("integrate_match.py", "xcoff.py", "icf_alias.py", "ltcg_route.py"))
            config = tmp / "config" / "54540859"
            (config / "symbols.txt").write_text(
                "fn_8819C360 = .text:0x8819C360; // type:function size:0x8C\n"
                "fn_881A2508 = .text:0x881A2508; // type:function size:0x64\n"
                "fn_881A2570 = .text:0x881A2570; // type:function size:0x74\n")
            (config / "symbols.seed.txt").write_text("")
            (config / "splits.txt").write_text("Sections:\n")
            (config / "objects.json").write_text(json.dumps({"swing": {"objects": {}}}))
            (tmp / "tools" / "matching.py").write_text("MATCHING_UNITS = (\n)\n\n\ndef sha256(path):\n    pass\n")
            (tmp / "src" / "xbox360" / "member.cpp").write_text("\n")
            (tmp / "src" / "xbox360" / "reset.c").write_text("\n")
            A.save([A.Alias("ts4_release_881A2570_icf_b", "fn_881A2570", 0x881A2570, "icf", "two bl")],
                   config / "icf_aliases.json")
            specs = [{"source": "src/xbox360/member.cpp", "functions": {"?Set@W@@QAAXPBGH@Z": "0x8819C360"},
                      "aliases": {"ts4_w_set_8819C360": {"canonical": "?Set@W@@QAAXPBGH@Z",
                                                         "address": "0x8819C360", "kind": "cxx",
                                                         "evidence": "member"}}},
                     {"source": "src/xbox360/reset.c", "functions": {"ts4_reset_881A2508": "0x881A2508"},
                      "renames": {"fn_881A2570": "ts4_release_881A2570"}}]
            paths = []
            for index, spec in enumerate(specs):
                paths.append(str(tmp / f"s{index}.json"))
                Path(paths[-1]).write_text(json.dumps(spec))
            env = {k: v for k, v in os.environ.items() if k != "TS4_MATCHING_DIR"}
            run = subprocess.run([sys.executable, "tools/integrate_match.py", *paths], cwd=tmp, env=env,
                                 capture_output=True, text=True)
            self.assertEqual(run.returncode, 0, run.stdout + run.stderr)
            self.assertIn("?Set@W@@QAAXPBGH@Z = .text:0x8819C360;", (config / "symbols.txt").read_text())
            self.assertIn('"symbols": {"?Set@W@@QAAXPBGH@Z": 140}', (tmp / "tools" / "matching.py").read_text())
            entries = {e.alias: e for e in A.load(config / "icf_aliases.json")}
            self.assertEqual(entries["ts4_w_set_8819C360"].address, 0x8819C360)
            self.assertEqual(entries["ts4_release_881A2570_icf_b"].canonical, "ts4_release_881A2570")
            from xcoff import load_symbols
            self.assertEqual(A.problems(list(entries.values()), load_symbols(config / "symbols.txt")), [])
            # An alias whose address is not its canonical's is refused before anything is written.
            bad = dict(specs[0], source="src/xbox360/other.cpp", functions={},
                       aliases={"x_alias": {"canonical": "?Set@W@@QAAXPBGH@Z", "address": "0x881A2508",
                                            "kind": "cxx", "evidence": "e"}})
            (tmp / "src" / "xbox360" / "other.cpp").write_text("\n")
            Path(paths[0]).write_text(json.dumps(bad))
            run = subprocess.run([sys.executable, "tools/integrate_match.py", paths[0]], cwd=tmp, env=env,
                                 capture_output=True, text=True)
            self.assertNotEqual(run.returncode, 0)
            self.assertNotIn("x_alias", (config / "icf_aliases.json").read_text())


if __name__ == "__main__":
    unittest.main()
