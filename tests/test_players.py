"""Synthetic-data tests for tools/ts4_players.py (no game data)."""
import io
import os
import struct
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "tools"))
import ts4_players as P  # noqa: E402


class Node:
    def __init__(self, name, attrs=None, children=None):
        self.name, self.attrs, self.children = name, attrs or {}, children or []


class Grp:
    def __init__(self, name, n):
        self.name, self.indices = name, list(range(n))


class FakeMesh:
    def __init__(self, groups):
        self.groups = groups


class Names(unittest.TestCase):
    def test_part_name(self):
        p = P.parse_part_name("M_TOP_PFEDX_XXXXX_00_100.xbin")
        self.assertEqual((p["cls"], p["part"], p["style"], p["player"], p["num"], p["lod"]),
                         ("M", "TOP", "PFEDX", "XXXXX", "00", "100"))
        p = P.parse_part_name("M_BTM_SHORT_FEDER_NIK_00_DST")
        self.assertEqual((p["player"], p["brand"], p["tail"]), ("FEDER", "NIK", "DST"))
        self.assertIsNone(P.parse_part_name("Hierarchy.xdt"))

    def test_texture_name(self):
        t = P.parse_texture_name("M_TOP_PFEDB_FEDER_NIK_00_2D_DI_F_PASTTIME_SWEAT1_DIRTY1")
        self.assertEqual((t["slot"], t["kind"], t["sweat"], t["dirty"]), ("diffuse", "F", 1, 1))
        t = P.parse_texture_name("M_HUM_HEADX_XXXXX_XXX_00_2D_SP_R_SWEAT2_DIRTY0")
        self.assertEqual((t["slot"], t["kind"], t["sweat"], t["dirty"]), ("specular", "R", 2, 0))
        self.assertIsNone(P.parse_texture_name("WrinkleMap"))

    def test_variant_pack_and_key(self):
        self.assertEqual(P.variant_pack("M_SOC_XXXXX_XXXXX_NIK_00_DST.xpr"), "clay")
        self.assertEqual(P.variant_pack("M_SOC_XXXXX_XXXXX_NIK_00_GRA.xpr"), "grass")
        self.assertEqual(P.variant_pack("M_HUM_LEGSX_XXXXX_XXX_00_2D_SP_R_3_0.xpr"), "sweat3")
        self.assertIsNone(P.variant_pack("SOC_XXXXX_XXXXX_00.xpr"))
        self.assertEqual(P.variant_key({"sweat": 2, "dirty": 1}, "grass"), "sweat2_grass")
        self.assertEqual(P.variant_key({"sweat": 1, "dirty": 0}, None), "sweat1")

    def test_arc_player(self):
        self.assertEqual(P.arc_player("Baked_Federer0.arc"), ("Federer", 0))
        self.assertEqual(P.arc_player("Baked_PlayerAcademy10.arc"), ("PlayerAcademy1", 0))


class Hierarchy(unittest.TestCase):
    def tree(self):
        body = Node("Geometry", {"Name": "M_HUM_BODYX_XXXXX_00_000", "Mesh": "M_HUM_BODYX_XXXXX_00_000_Player00",
                                 "Material": "M_HUM_BODYX_XXXXX_00_Player00", "0x64a3fde0": b"\xff\xff\xff\xff"}, [
            Node("UserProperties", {"Distance1": "1000", "Distance2": "1500", "ShaderLOD": "AUTO"}),
            Node("DMorphList", {}, [Node("DMorph", {"Name": "M_HUM_BODYX_XXXXX_00_001", "Weight": 0.25})]),
            Node(P.HASH_VISIBLE_GROUPS, {}, [Node(P.HASH_GROUP, {"Name": "GRP_HANDS_00"})])])
        lod = Node("Geometry", {"Name": "M_TOP_PFEDX_XXXXX_00_100", "Mesh": "M_TOP_PFEDX_XXXXX_00_100_Player00",
                                "0x64a3fde0": b"\x00\x00\x00\x00"})
        return Node("Hierarchy", {}, [Node("Child", {}, [body, lod])])

    def test_geometries(self):
        g = P.hierarchy_geometries(self.tree())
        self.assertEqual(len(g), 2)
        self.assertTrue(g[0]["shown"])
        self.assertFalse(g[1]["shown"])
        self.assertEqual(g[0]["lod_distance_cm"], [1000.0, 1500.0])
        self.assertEqual(g[0]["morphs"], [{"name": "M_HUM_BODYX_XXXXX_00_001", "weight": 0.25}])
        self.assertEqual(g[0]["visible_groups"], ["GRP_HANDS_00"])

    def test_roster_entry(self):
        g = P.hierarchy_geometries(self.tree())
        members = {"M_HUM_BODYX_XXXXX_00_000.xbin", "M_HUM_BODYX_XXXXX_00_001.xbin",
                   "M_TOP_PFEDB_FEDER_NIK_00_SWE.xpr", "CLTH_TOP.bin"}
        e = P.roster_entry("Baked_Federer0.arc", members, g)
        self.assertEqual(list(e["parts"]), ["M_HUM_BODYX_XXXXX_00_000"])
        self.assertEqual(e["parts"]["M_HUM_BODYX_XXXXX_00_000"]["morphs"], ["M_HUM_BODYX_XXXXX_00_001"])
        self.assertEqual(e["texture_variants"], {"sweat": ["M_TOP_PFEDB_FEDER_NIK_00_SWE"]})
        self.assertEqual(e["cloth"], ["CLTH_TOP.bin"])
        self.assertIn("TOP_PFEDB_FEDER", e["signature_items"])

    def test_body_group_filter(self):
        self.assertTrue(P.body_group_visible("GRP_HANDS_00", ["GRP_HANDS_00"]))
        self.assertFalse(P.body_group_visible("GRP_CHEST_01", ["GRP_HANDS_00"]))
        self.assertTrue(P.body_group_visible("GRP_CHEST_01", None))


class Meshes(unittest.TestCase):
    def test_lod_sets_order(self):
        names = ["A", "B"]
        groups = [Grp(n, c) for n, c in zip(names * 3, [6, 6, 3, 3, 9, 9])]   # mid, low, high
        sets = P.lod_sets(FakeMesh(groups))
        self.assertEqual([[i for i, _ in s] for s in sets], [[4, 5], [0, 1], [2, 3]])

    def test_lod_sets_single(self):
        sets = P.lod_sets(FakeMesh([Grp("KeyNull", 3), Grp("Other", 3)]))
        self.assertEqual(len(sets), 1)

    def test_skin_pairs_reversed_index_bytes(self):
        j, w = P.skin_pairs((0.75, 0.25, 0.0, 0.0), (9, 9, 2, 1), list(range(10)))
        self.assertEqual(j[:2], (1, 2))           # weight 0 pairs with byte 3, weight 1 with byte 2
        self.assertAlmostEqual(sum(w), 1.0)

    def test_parse_morph(self):
        # synthetic morph record: 6 strings, slots position/normal/tangent, 2 vertices
        b = bytearray(0x200)
        b[0:8] = bytes.fromhex("7d72a97da12b5eb9")
        b[0x10:0x14] = b"\xff\xff\xff\xff"
        s = 0x14
        strings = 0x180

        def put_str(off, txt):
            b[off:off + len(txt) + 1] = txt.encode() + b"\0"
            return off + len(txt) + 1
        o = strings
        for i in range(6):
            struct.pack_into(">I", b, s + 4 * i, o - (s + 4 * i))
            o = put_str(o, "x%d" % i)
        fmts = ["Float16_4", "Dec3N", "Dec3N"]
        cells = 0x100
        for i in range(10):
            struct.pack_into(">I", b, s + 0x28 + 4 * i, 0xFFFFFFFF)
        for i, f in enumerate(fmts):
            slot = s + 0x28 + 4 * i
            cell = cells + 4 * i
            struct.pack_into(">I", b, slot, cell - slot)
            struct.pack_into(">I", b, cell, o - cell)
            o = put_str(o, f)
        name_at = o
        o = put_str(o, "M_X_010")
        struct.pack_into(">I", b, s + 0x58, name_at - (s + 0x58))
        desc = 0x120
        struct.pack_into(">I", b, s + 0x50, desc - (s + 0x50))
        vdata = 0x140
        struct.pack_into(">iII", b, desc, vdata - desc, 2, 2)
        struct.pack_into(">4H", b, vdata, 0x3C00, 0, 0, 0x3C00)      # (1, 0, 0, 1)
        struct.pack_into(">4H", b, vdata + 16, 0, 0, 0, 0x3C00)
        name, attrs = P.parse_morph(bytes(b), s)
        self.assertEqual(name, "M_X_010")
        self.assertEqual(attrs["position"][0][:3], (1.0, 0.0, 0.0))
        self.assertEqual(len(attrs["normal"]), 2)


class Creator(unittest.TestCase):
    def test_tree_from_leaves(self):
        t = P.tree_from_leaves([("A/B[1]/C", 5), ("A/B[0]/C", 4), ("A/D<x::y>/E", "e")], "")
        self.assertEqual(t["A"]["B"], [{"C": 4}, {"C": 5}])
        self.assertEqual(t["A"]["D"]["E"], "e")

    def test_summary(self):
        leaves = [
            ("RunTimeDB/CharacterCreator/Data/Geometries/Geometry[0]/Name", "M_HUM_BODYX_XXXXX_00_000"),
            ("RunTimeDB/CharacterCreator/Data/Geometries/Geometry[0]/Lod", 0),
            ("RunTimeDB/CharacterCreator/Data/e88999e3/Morph[0]/Name", "Fat"),
            ("RunTimeDB/CharacterCreator/Data/e88999e3/Morph[0]/Max", 1.0),
            ("RunTimeDB/CharacterCreator/Male/OutfitList/Outfit[0]/Name", "Polo"),
            ("RunTimeDB/CharacterCreator/Male/OutfitList/Outfit[0]/GeometryList/GeometryRef[0]/BrandList/Brand[0]/Name", "NIK"),
        ]
        s = P.creator_summary(P.tree_from_leaves(leaves, ""))
        self.assertEqual(s["geometries"][0]["name"], "M_HUM_BODYX_XXXXX_00_000")
        self.assertEqual(s["morphs"], [{"Name": "Fat", "Max": 1.0}])
        self.assertEqual(s["male"]["outfits"][0]["geometries"][0]["brands"], ["NIK"])


class Yaml(unittest.TestCase):
    def test_writer_parses(self):
        buf = io.StringIO()
        P.ywrite(buf, {"a": [{"x": 1, "y": "two words"}], "b": {"c": [1, 2.5, None, True]}}, 0, flow_depth=3)
        try:
            import yaml
        except ImportError:
            self.skipTest("PyYAML not installed")
        self.assertEqual(yaml.safe_load(buf.getvalue()), {"a": [{"x": 1, "y": "two words"}], "b": {"c": [1, 2.5, None, True]}})

    def test_roster_handedness_reader(self):
        txt = "pros:\n  - arc: Baked_Nadal0.arc\n    player_list: {index: 1, plays: LeftHanded, height_cm: 185, gender: Male}\n"
        self.assertEqual(P.parse_roster_handedness(txt), {"Baked_Nadal0.arc": {"plays": "LeftHanded", "height_cm": 185, "gender": "Male"}})
        blk = "  - arc: Baked_Nadal0.arc\n    player_list:\n      index: 1\n      plays: LeftHanded\n      height_cm: 185\n  - arc: B.arc\n"
        self.assertEqual(P.parse_roster_handedness(blk)["Baked_Nadal0.arc"], {"plays": "LeftHanded", "height_cm": 185})


class Chains(unittest.TestCase):
    def test_record_chains(self):
        cm = {"records": [{"index": 5, "variants": [{"kind": "core+aod", "core_index": 12, "aod_key": "0026b42b"}]},
                          {"index": 6, "variants": [{"kind": "aod", "aod_key": "00000001"}]}],
              "map": {"#7": "core:3"}}
        c = P.record_chains(cm, [5, 6, 7, 8])
        self.assertEqual(c[5], {"core": 12, "aod": "0026b42b", "kind": "core+aod"})
        self.assertEqual(c[6]["core"], None)
        self.assertEqual(c[7], {"core": 3, "aod": None, "kind": "core"})
        self.assertNotIn(8, c)


if __name__ == "__main__":
    unittest.main()
