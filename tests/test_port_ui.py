"""Synthetic-byte tests for the front-end readers of the browser port (tools/port/lua50.py, ui_actions.py,
ui_formats.py, ui_export.py helpers).  No game data: every structure is built here from the layouts
documented in docs/port/ui.md."""
import os
import struct
import sys
import unittest
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "port"))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import lua50  # noqa: E402
import ui_actions  # noqa: E402
import ui_formats  # noqa: E402


# ------------------------------------------------------------------ Lua 5.0 chunk builder (big endian)

def lstr(s):
    if s is None:
        return struct.pack(">i", 0)
    b = s.encode("latin-1") + b"\0"
    return struct.pack(">i", len(b)) + b


def abc(op, a=0, b=0, c=0):
    return lua50.OP[op] | (c << 6) | (b << 15) | (a << 24)


def abx(op, a, bx):
    return lua50.OP[op] | (bx << 6) | (a << 24)


def chunk(consts, code, maxstack=4):
    out = b"\x1bLua" + bytes([0x50, 0x00, 4, 4, 4, 6, 8, 9, 9, 8])
    out += struct.pack(">d", 3.14159265358979323846e7)
    out += lstr("@synthetic") + struct.pack(">i", 0) + bytes([0, 0, 0, maxstack])
    out += struct.pack(">i", 0)                       # lineinfo
    out += struct.pack(">i", 0) + struct.pack(">i", 0)  # locvars, upvalues
    out += struct.pack(">i", len(consts))
    for k in consts:
        if isinstance(k, float):
            out += b"\x03" + struct.pack(">d", k)
        elif isinstance(k, lua50.WStr):
            w = k.encode("utf-16-be") + b"\0\0"
            out += b"\x09" + struct.pack(">i", len(w) // 2) + w
        else:
            out += b"\x04" + lstr(k)
    out += struct.pack(">i", 0)                       # protos
    out += struct.pack(">i", len(code)) + struct.pack(">%dI" % len(code), *code)
    return out


RK = 250


class Lua50Tests(unittest.TestCase):
    def build(self):
        # Foo = "bar";  T = {x = 3, name = L"Wide"}
        k = ["bar", "Foo", 3.0, "x", "T", "name", lua50.WStr("Wide")]
        code = [
            abx("LOADK", 0, 0), abx("SETGLOBAL", 0, 1),
            abc("NEWTABLE", 0, 0, 0),
            abc("SETTABLE", 0, RK + 3, RK + 2),
            abc("SETTABLE", 0, RK + 5, RK + 6),
            abx("SETGLOBAL", 0, 4),
            abc("RETURN", 0, 1),
        ]
        return chunk(k, code)

    def test_header_and_decode(self):
        d = self.build()
        self.assertTrue(lua50.is_lua(d))
        f = lua50.load(d)
        self.assertEqual(f.k[0], "bar")
        self.assertIsInstance(f.k[6], lua50.WStr)
        op, a, b, c, bx = lua50.decode(abx("LOADK", 7, 0x3FFFF))
        self.assertEqual((lua50.OPNAMES[op], a, bx), ("LOADK", 7, 0x3FFFF))  # Bx is 18 bits

    def test_opcode_numbering(self):
        # numbering confirmed from the luaV_execute jump table (fn_8880D5E0)
        self.assertEqual(lua50.OP["BXOR"], 20)
        self.assertEqual(lua50.OP["CLOSURE"], 38)
        self.assertEqual(len(lua50.OPNAMES), 39)

    def test_bad_chunks(self):
        with self.assertRaises(lua50.LuaFormatError):
            lua50.load(b"\x1bLua\x51" + b"\0" * 20)
        with self.assertRaises(lua50.LuaFormatError):
            lua50.load(self.build()[:40])

    def test_evaluate(self):
        g, _calls = lua50.evaluate(lua50.load(self.build()))
        self.assertEqual(g["Foo"], "bar")
        t = lua50.to_json(g["T"])
        self.assertEqual(t["x"], 3)
        self.assertEqual(t["name"], "Wide")

    def test_disassemble_and_decompile(self):
        f = lua50.load(self.build())
        dis = "\n".join(lua50.disassemble(f))
        self.assertIn("SETGLOBAL", dis)
        src = lua50.decompile(f, "main")
        src = src if isinstance(src, str) else "\n".join(src)
        self.assertIn("Foo", src)


# ------------------------------------------------------------------ .actions / .anims builders

def build_actions(actions, pool):
    """actions: [(name, params, [(cond_tokens or b'', [stmt_tokens...])])]"""
    recs = []
    for name, params, blocks in actions:
        p = b"".join(bytes([len(x)]) + x.encode() for x in params)
        r = struct.pack(">IH", 0, len(name)) + name.encode() + struct.pack(">HB", len(params), len(p)) + p
        r += bytes([len(blocks)])
        for cond, stmts in blocks:
            r += struct.pack(">H", len(cond)) + cond
            for s in stmts:
                r += bytes([len(s)]) + s
            r += b"\0"
        recs.append(r)
    offs, o = [], 0
    for r in recs:
        offs.append(o)
        o += len(r)
    area = b"".join(recs)
    poolb, soffs = b"", []
    for s in pool:
        soffs.append(len(poolb))
        poolb += bytes([len(s)]) + s.encode()
    head = struct.pack(">II", len(recs), len(area)) + struct.pack(">%dI" % len(offs), *offs)
    head += struct.pack(">I", len(pool)) + struct.pack(">%dI" % len(soffs), *soffs)
    return head + area + poolb


def ref(i):
    return bytes([0x80 | (i & 0x7F), i >> 7])


def name_block(s):
    b = s.encode()
    pad = (len(b) + 4) & ~3
    return struct.pack(">III", len(b), pad, 0xFFFFFFFF) + b.ljust(pad, b"\0")


def build_curve(first, node, prop, keys, step=False):
    keyb = b"".join(struct.pack(">6f", *k) for k in keys)
    nb, pb = name_block(node), name_block(prop)
    no = 8 + 0x28 + len(keyb)
    po = no + len(nb)
    to = po + len(pb)
    size = to - 8
    hdr = struct.pack(">6I", first, size, no, po, to, 0xFFFFFFFF)
    hdr += struct.pack(">4I", len(keys), 0x10000 if step else 0, 0, 0)
    return hdr + keyb + nb + pb


class ActionsTests(unittest.TestCase):
    def test_parse(self):
        pool = ["ChangeScene", "S4Loading"]
        d = build_actions([
            ("SceneOn", [], [(b"", [b"Wait(5)", ref(0) + b"('" + ref(1) + b"')"])]),
            ("Select", ["Id"], [(b"\x01a==1", [b"PushScene"]), (b"", [b"SceneOff"])]),
        ], pool)
        r = ui_actions.parse_actions(d)
        a = r["actions"]
        self.assertEqual(a[0]["name"], "SceneOn")
        self.assertEqual(a[0]["body"], ["Wait(5)", "ChangeScene('S4Loading')"])
        self.assertEqual(a[1]["params"], ["Id"])
        self.assertEqual(a[1]["blocks"][0]["if"], "a==1")
        self.assertIsNone(a[1]["blocks"][1]["if"])
        self.assertEqual(ui_actions.statement_calls("ChangeScene('S4Loading')"), ("ChangeScene", ["S4Loading"]))

    def test_wide_token_index(self):
        pool = ["s%d" % i for i in range(200)]
        d = build_actions([("A", [], [(b"", [ref(150)])])], pool)
        self.assertEqual(ui_actions.parse_actions(d)["actions"][0]["body"], ["s150"])

    def test_bad(self):
        with self.assertRaises(ui_actions.UiFormatError):
            ui_actions.parse_actions(struct.pack(">II", 1, 1 << 30))


class AnimsTests(unittest.TestCase):
    def test_parse(self):
        c1 = build_curve(8, "Color_Text", "globalColorA", [[0, 0, 1, 0, 1, 0], [1.25, 0.7, 1, 0, 1, 0]])
        c2 = build_curve(0, "Color_Text", "visibility", [[0, 1, 1, 0, 1, 0]], step=True)
        body = c1 + c2
        clip_tab = struct.pack(">I", 1) + struct.pack(">IIffII", 0x24, 0, 1.0, 1.0, 0, 0) + name_block("Fade")
        d = struct.pack(">If", 1, 1.25) + body + struct.pack(">II", 0, 0) + clip_tab
        r = ui_actions.parse_anims(d)
        clip = r["clips"]["Fade"]
        self.assertAlmostEqual(clip["duration"], 1.25)
        self.assertEqual([c["prop"] for c in clip["curves"]], ["globalColorA", "visibility"])
        self.assertTrue(clip["curves"][1]["step"])
        self.assertAlmostEqual(clip["curves"][0]["keys"][1][1], 0.7, places=5)
        self.assertEqual(r["nodes"], ["Color_Text"])


# ------------------------------------------------------------------ string table / font / scene

def build_string_table(entries):
    """entries: [(text_id, font, scale, text, indirect)] -> StringTable.bin image."""
    entries = sorted(entries, key=lambda e: zlib.crc32(e[0].encode()))
    n = len(entries)
    a0 = 0x40
    b0 = a0 + 8 * n
    heap = b0 + 12 * n
    blob = bytearray()
    a_recs, b_recs = [], []
    for i, (tid, font, scale, text, indirect) in enumerate(entries):
        fpos = heap + len(blob)
        blob += font.encode() + b"\0"
        while len(blob) % 4:
            blob += b"\0"
        a_recs.append(struct.pack(">If", fpos - (a0 + 8 * i), scale))
        tpos = heap + len(blob)
        if indirect:
            blob += struct.pack(">I", 4)
        blob += text.encode("utf-16-be") + b"\0\0"
        while len(blob) % 4:
            blob += b"\0"
        cls = ui_formats.STRING_CLASS_INDIRECT if indirect else ui_formats.STRING_CLASS_INLINE
        b_recs.append(struct.pack(">3I", tpos - (b0 + 12 * i), cls, zlib.crc32(tid.encode())))
    d = bytearray(ui_formats.STRING_TABLE_SIG + b"\0" * (a0 - 8))
    struct.pack_into(">3I", d, 0x14, a0 - 0x14, n, n)
    struct.pack_into(">3I", d, 0x20, b0 - 0x20, n, n)
    struct.pack_into(">3I", d, 0x30, 0, 0, 0)
    return bytes(d) + b"".join(a_recs) + b"".join(b_recs) + bytes(blob)


class StringTableTests(unittest.TestCase):
    def test_parse(self):
        d = build_string_table([("MenuPlay", "Main_White", 1.0, "PLAY", True),
                                ("MenuQuit", "", 0.5, "Quit the game", False)])
        r = ui_formats.parse_string_table(d)
        by = {e["key"]: e for e in r["entries"]}
        e = by[ui_formats.crc32("MenuPlay")]
        self.assertEqual((e["text"], e["font"], e["scale"]), ("PLAY", "Main_White", 1.0))
        self.assertEqual(by[ui_formats.crc32("MenuQuit")]["text"], "Quit the game")

    def test_bad(self):
        with self.assertRaises(ui_formats.UiDataError):
            ui_formats.parse_string_table(b"\0" * 64)

    def test_language(self):
        self.assertEqual(ui_formats.guess_language(["Press the button and you win your match"])[0], "en")
        self.assertEqual(ui_formats.guess_language(["Drücken Sie die Taste und der Ball"])[0], "de")


class FontTests(unittest.TestCase):
    def test_parse(self):
        d = struct.pack("<6I", 6, 39, 512, 512, 30, 2)
        d += struct.pack("<2H", 0x41, 0x42) + struct.pack("<2H", 0x61, 0x61)
        d += struct.pack("<I", 3)
        for i in range(3):
            d += struct.pack("<4f3hHI", 0.1 * i, 0, 0.1 * i + 0.05, 0.07, 1, 20 + i, 22 + i, 0, 0xFF)
        f = ui_formats.parse_abc_font(d)
        self.assertEqual(f["height"], 39)
        self.assertEqual(f["map"], {0x41: 0, 0x42: 1, 0x61: 2})
        self.assertEqual(f["glyphs"][2]["advance"], 24)
        with self.assertRaises(ui_formats.UiDataError):
            ui_formats.parse_abc_font(struct.pack("<6I", 5, 0, 0, 0, 0, 0))


class SceneTests(unittest.TestCase):
    def test_positioning(self):
        p48 = ui_formats.decode_positioning(struct.pack(">12f", *range(12)))
        self.assertEqual(p48["t"], [0, 1, 2])
        self.assertEqual(p48["p"], [9, 10, 11])
        self.assertNotIn("sp", p48)
        p96 = ui_formats.decode_positioning(struct.pack(">24f", *range(24)).decode("latin-1"))
        self.assertEqual(p96["spt"], [21, 22, 23])

    def test_scene_to_json(self):
        raw = struct.pack(">12f", 1, 2, 3, 1, 1, 1, 0, 0, 0, 0, 0, 0).decode("latin-1")
        out = ui_formats.scene_to_json({"Children": [{"PositioningInfo": raw, "Name": "a"}]}, None)
        self.assertEqual(out["Children"][0]["PositioningInfo"]["t"], [1, 2, 3])


class ExportHelperTests(unittest.TestCase):
    def test_geometry_order(self):
        import ui_export
        tmpl = {"data": {"Graph": {"Children": [{"NodeNumber": 1, "Type": "Mesh"},
                                                {"NodeNumber": 2, "Type": "Text"}]}}}
        graph = {"Children": [
            {"NodeNumber": 1, "Type": "Camera"},
            {"NodeNumber": 2, "Type": "Node", "Children": [
                {"NodeNumber": 3, "Type": "Mesh"},
                {"NodeNumber": 4, "Type": "Template", "TemplateName": "T"},
                {"NodeNumber": 5, "Type": "UntexturedMesh"}]}]}
        paths = [p for p, _n in ui_export.expanded_geometry_nodes(graph, lambda n: tmpl if n == "T" else None)]
        self.assertEqual(paths, ["1/0", "1/1/t0", "1/1/t1", "1/2"])


if __name__ == "__main__":
    unittest.main()
