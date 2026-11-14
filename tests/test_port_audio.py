"""Synthetic-byte tests for the FMOD readers used by the browser port (tools/port/fmod_fev.py, fmod_fsb.py,
audio_export.py).  No game data: every structure is built here from the documented layout."""
import os
import struct
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "port"))
sys.path.insert(0, os.path.join(ROOT, "tools"))

import fmod_fev  # noqa: E402
import fmod_fsb  # noqa: E402
import audio_export  # noqa: E402


def s(text):
    b = text.encode("latin-1") + b"\0"
    return struct.pack("<I", len(b)) + b


def props(d):
    out = struct.pack("<I", len(d))
    for k, v in d.items():
        if isinstance(v, int):
            out += s(k) + struct.pack("<Ii", 0, v)
        elif isinstance(v, float):
            out += s(k) + struct.pack("<If", 1, v)
        else:
            out += s(k) + struct.pack("<I", 2) + s(v)
    return out


def base(volume=1.0, maxpb=4):
    b = bytearray(fmod_fev.BASE_BLOCK)
    struct.pack_into("<5fII", b, 0, volume, 0.0, 0.5, 0.25, 0.0, maxpb, 10000)
    struct.pack_into("<I", b, 0x10, 128)
    struct.pack_into(">I", b, 0x1C, 0x08000000)
    struct.pack_into("<ff", b, 0x20, 1.0, 10000.0)
    return bytes(b)


def instance(sd, start=0.0, length=1.0, simple=True):
    tail = bytearray(48)
    struct.pack_into("<fiiII", tail, 28, 1.0, 0 if simple else -1, 0 if simple else -1, 2, 2)
    return struct.pack("<Hff", sd, start, length) + bytes(tail)


def category(name, children=()):
    out = s(name) + struct.pack("<ffII", 1.0, 0.0, 0, 0) + struct.pack("<I", len(children))
    for c in children:
        out += c
    return out


def build_fev():
    simple = struct.pack("<I", 0x10) + s("Flat") + b"\x11" * 16 + base(0.8) + struct.pack("<I", 1) + \
        instance(0) + struct.pack("<I", 1) + s("fx")
    env = struct.pack("<i", -1) + s("") + struct.pack("<III", 0, 12, 0) + struct.pack("<I", 2) + \
        struct.pack("<ffI", 0.0, 0.0, 0) + struct.pack("<ffI", 1.0, 1.0, 0) + struct.pack("<II", 0, 0)
    layer = struct.pack("<HhhHH", 0, 0, 0, 1, 1) + instance(1, simple=False) + env
    param = s("param00") + struct.pack("<fffIfI", 0.1, 0.0, 1.0, 9, 0.0, 0)
    complex_ = struct.pack("<I", 0x08) + s("Excitement") + b"\x22" * 16 + base(1.0, 2) + \
        struct.pack("<I", 1) + layer + struct.pack("<I", 1) + param + struct.pack("<I", 0) + props({}) + \
        struct.pack("<I", 1) + s("music")
    shot = s("Shot") + props({}) + struct.pack("<II", 0, 1) + simple
    loops = s("Loops") + props({"k": 3}) + struct.pack("<II", 0, 1) + complex_
    root = s("Root") + props({}) + struct.pack("<II", 2, 0) + shot + loops
    tpl = bytearray(fmod_fev.TEMPLATE_SIZE)
    struct.pack_into("<IffIf", tpl, 0, 2, 0.0, 0.0, 1, 0.5)
    sds = struct.pack("<I", 2)
    sds += s("/Ball/Shot/Flat") + struct.pack("<II", 0, 2)
    sds += struct.pack("<II", 0, 100) + s("a.wav") + s("Bank") + struct.pack("<II", 0, 640)
    sds += struct.pack("<II", 0, 50) + s("b.wav") + s("Bank") + struct.pack("<II", 1, 320)
    sds += s("/Crowd/Loop") + struct.pack("<II", 0, 2)
    sds += struct.pack("<II", 0, 100) + s("loop.wav") + s("Bank") + struct.pack("<II", 2, 9000)
    sds += struct.pack("<II", 3, 100) + b"\0" * 8
    data = b"FEV1" + struct.pack("<III", 0x003E0000, 0, 0) + s("proj")
    data += struct.pack("<I", 1) + struct.pack("<II", 0, 0) + b"\0" * 8 + s("Bank")
    data += category("master", [category("fx"), category("music")])
    data += struct.pack("<I", 1) + root
    data += struct.pack("<I", 1) + bytes(tpl) + sds + struct.pack("<I", 0) + b"comp"
    return data


def fsb_sample(name, codec_mode, ch, rate, nsamples, payload):
    h = bytearray(80)
    struct.pack_into("<H", h, 0, 80)
    h[2:2 + len(name)] = name.encode()
    struct.pack_into("<5IiHhHH", h, 32, nsamples, len(payload), 0, nsamples - 1, codec_mode, rate, 255, 128, 128, ch)
    return bytes(h)


def build_fsb(samples):
    hdrs = b"".join(fsb_sample(*x) for x in samples)
    data = b""
    for x in samples:
        p = x[5]
        data += p
        if x[1] & fmod_fsb.MODE_PADDED:
            data += b"\0" * (-len(p) % 32)
    return b"FSB4" + struct.pack("<5I", len(samples), len(hdrs), len(data), 0x40000, 0) + b"\0" * 24 + hdrs + data


class FevTest(unittest.TestCase):
    def test_parse(self):
        fev = fmod_fev.FevFile(build_fev())
        self.assertEqual(fev.version, 0x003E0000)
        self.assertEqual([b["name"] for b in fev.banks], ["Bank"])
        self.assertEqual(fev.categories, ["master", "fx", "music"])
        self.assertEqual([e["path"] for e in fev.events], ["/Root/Shot/Flat", "/Root/Loops/Excitement"])
        flat = fev.event("/Root/Shot/Flat")
        self.assertEqual(flat["type"], "simple")
        self.assertEqual(flat["category"], "fx")
        self.assertAlmostEqual(flat["base"]["volume"], 0.8, places=5)
        self.assertTrue(flat["base"]["is_2d"])
        self.assertEqual(flat["base"]["priority"], 128)
        ex = fev.event("/Root/Loops/Excitement")
        self.assertEqual(ex["category"], "music")
        self.assertEqual(ex["params"][0]["name"], "param00")
        self.assertEqual(ex["layers"][0]["envelopes"][0]["points"], [[0.0, 0.0], [1.0, 1.0]])
        self.assertEqual(fev.templates[0]["playmode"], 2)
        self.assertEqual(len(fev.sounddefs[1]["waves"]), 2)
        self.assertEqual([w["file"] for _n, w in fev.event_waves(flat)], ["a.wav", "b.wav"])
        self.assertEqual(build_fev()[fev.end:fev.end + 4], b"\0\0\0\0")

    def test_bad_magic(self):
        with self.assertRaises(fmod_fev.FevError):
            fmod_fev.FevFile(b"FEV2" + b"\0" * 64)

    def test_truncated(self):
        with self.assertRaises(fmod_fev.FevError):
            fmod_fev.FevFile(build_fev()[:200])

    def test_event_record(self):
        fev = fmod_fev.FevFile(build_fev())
        rec = audio_export.event_record(fev, fev.event("/Root/Shot/Flat"), {("Bank", 0): "banks/x/000_a.wav"})
        waves = rec["layers"][0]["sounds"][0]["waves"]
        self.assertEqual(waves[0]["file"], "banks/x/000_a.wav")
        self.assertFalse(waves[0]["loop"])
        self.assertIsNone(waves[1]["file"])
        self.assertEqual(rec["layers"][0]["sounds"][0]["playmode"], "random_no_repeat")


class FsbTest(unittest.TestCase):
    def test_parse_and_padding(self):
        xma = bytes(range(256)) * 8
        mp3 = b"\xff\xfb" + b"\x01" * 41
        d = build_fsb([("bounce.wav", fmod_fsb.MODE_XMA | fmod_fsb.MODE_MONO, 1, 44100, 1000, xma),
                       ("music.wav", fmod_fsb.MODE_MPEG | fmod_fsb.MODE_PADDED | fmod_fsb.MODE_STEREO, 2, 44100,
                        500, mp3),
                       ("next", fmod_fsb.MODE_MPEG | fmod_fsb.MODE_PADDED, 1, 32000, 10, b"\xff\xfb" * 5)])
        b = fmod_fsb.parse(d)
        self.assertEqual([x["codec"] for x in b["samples"]], ["xma", "mp3", "mp3"])
        self.assertEqual(fmod_fsb.sample_bytes(d, b["samples"][0]), xma)
        self.assertEqual(fmod_fsb.sample_bytes(d, b["samples"][1]), mp3)
        self.assertEqual(b["samples"][2]["offset"] - b["samples"][1]["offset"], 64)
        self.assertEqual(fmod_fsb.sample_bytes(d, b["samples"][2]), b"\xff\xfb" * 5)
        ext, blob = fmod_fsb.native_file(d, b["samples"][1])
        self.assertEqual((ext, blob), (".mp3", mp3))

    def test_xma_riff(self):
        raw = b"\0" * 4096
        r = fmod_fsb.xma_riff(raw, 2, 44100, 12345)
        self.assertEqual(r[:4], b"RIFF")
        self.assertEqual(struct.unpack_from("<I", r, 4)[0], len(r) - 8)
        self.assertEqual(r[8:16], b"WAVEfmt ")
        flen, tag, ch, rate = struct.unpack_from("<IHHI", r, 16)
        self.assertEqual((flen, tag, ch, rate), (52, 0x166, 2, 44100))
        streams, mask, samples, blk = struct.unpack_from("<HIII", r, 38)
        self.assertEqual((streams, mask, samples, blk), (1, 3, 12345, 4096))
        self.assertEqual(r[20 + flen:20 + flen + 4], b"data")

    def test_ima_step(self):
        self.assertEqual(fmod_fsb._ima_step(0, 0, 0), (0, 0))
        self.assertEqual(fmod_fsb._ima_step(7, 0, 0), (11, 8))       # 7>>3 + 7>>2 + 7>>1 + 7 = 0+1+3+7
        self.assertEqual(fmod_fsb._ima_step(15, 0, 0), (-11, 8))
        self.assertEqual(fmod_fsb._ima_step(7, 32767, 88), (32767, 88))

    def test_xbox_ima_mono_and_stereo(self):
        blk = struct.pack("<hBB", 100, 0, 0) + bytes([0x77] * 32)
        pcm = fmod_fsb.decode_xbox_ima(blk, 1)
        self.assertEqual(len(pcm), 64)
        self.assertEqual(pcm[:3], [100, 111, 141])     # step 7 then 16 (index 0 -> 8)
        st = struct.pack("<hBB", 0, 0, 0) + struct.pack("<hBB", 1000, 0, 0)
        for g in range(8):
            st += bytes([0x00] * 4) + bytes([0x88] * 4)
        pcm = fmod_fsb.decode_xbox_ima(st, 2, nsamples=10)
        self.assertEqual(len(pcm), 20)
        self.assertEqual(pcm[0:2], [0, 1000])
        self.assertTrue(all(v == 0 for v in pcm[0::2]))
        self.assertEqual(pcm[3], 1000)                              # nibble 8: diff = -(7>>3) = 0

    def test_wav(self):
        w = fmod_fsb.wav_pcm16([0, 1, -1, 32767], 2, 22050)
        self.assertEqual(w[:4], b"RIFF")
        self.assertEqual(struct.unpack_from("<HHI", w, 20), (1, 2, 22050))
        self.assertEqual(w[-8:], struct.pack("<4h", 0, 1, -1, 32767))

    def test_bad(self):
        with self.assertRaises(fmod_fsb.FsbError):
            fmod_fsb.parse(b"FSB3" + b"\0" * 44)

    def test_safe_name(self):
        self.assertEqual(audio_export.safe_name("HardLargeAngleMediumSpeed_01.w"), "HardLargeAngleMediumSpeed_01")
        self.assertEqual(audio_export.safe_name("02 Da Funk.wav"), "02_Da_Funk")


if __name__ == "__main__":
    unittest.main()
