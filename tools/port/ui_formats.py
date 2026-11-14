#!/usr/bin/env python3
"""Pure decoders for the Top Spin 4 front-end data (no disc access; synthetic-byte tests in
tests/test_port_ui.py).  See docs/port/ui.md for the format notes.

* ``parse_string_table``  StringTable.bin (XBin, root type 0x6668075D): one per language.
* ``parse_abc_font``      ``*.abc`` bitmap fonts (little-endian ATG-style glyph table, version 6).
* ``scene_to_json``       evaluated ``*.sceneData`` / ``*.scene`` Lua tables -> plain JSON nodes,
                          with ``PositioningInfo`` decoded.
* ``guess_language``      which of the five string tables is which language.
"""
from __future__ import annotations

import struct
import zlib

STRING_TABLE_SIG = bytes.fromhex("c88433e76668075d")
STRING_CLASS_INDIRECT = 0x92A82712
STRING_CLASS_INLINE = 0x9EDE2887
FONT_VERSION = 6


class UiDataError(ValueError):
    pass


def crc32(s: str) -> int:
    return zlib.crc32(s.encode("latin-1", "replace")) & 0xFFFFFFFF


# ------------------------------------------------------------------------------------------- strings

def _arr(d, o):
    if o + 12 > len(d):
        raise UiDataError("truncated array descriptor at 0x%X" % o)
    rel, n, _cap = struct.unpack_from(">3I", d, o)
    return o + rel, n


def _wstr(d, q, limit=1 << 16):
    if q < 0 or q >= len(d):
        raise UiDataError("string pointer out of range")
    e = q
    stop = min(len(d) - 1, q + 2 * limit)
    while e < stop and d[e:e + 2] != b"\0\0":
        e += 2
    return d[q:e].decode("utf-16-be", "replace")


def _cstr(d, q):
    if q < 0 or q >= len(d):
        raise UiDataError("string pointer out of range")
    e = d.find(b"\0", q)
    if e < 0:
        e = len(d)
    return d[q:e].decode("latin-1")


def parse_string_table(d: bytes):
    """Return {"entries": [{"key": crc, "type": crc, "font": str, "scale": f, "text": str}], "case_map": [...]}.

    Layout (XBin image, offsets self-relative):
      0x14 array A  (8 B each): u32 rel -> font name (C string, "" = default), f32 scale
      0x20 array B (12 B each): u32 rel, u32 string-class crc, u32 key crc; class 0x92A82712: rel -> u32 rel ->
                                UTF-16BE text, class 0x9EDE2887: rel -> UTF-16BE text
                                (sorted by key; key = zlib.crc32 of the TextID, e.g. "CommonDisclaimerTextWorkInProgress")
      0x2C u32 rel -> font-name pool, 0x30 array C (4 B each): u16 lower, u16 upper case pairs
    A and B are parallel (same index = same string).
    """
    if d[:8] != STRING_TABLE_SIG:
        raise UiDataError("not a StringTable.bin")
    a0, na = _arr(d, 0x14)
    b0, nb = _arr(d, 0x20)
    if na != nb or b0 + 12 * nb > len(d) or a0 + 8 * na > len(d):
        raise UiDataError("inconsistent string table arrays")
    out = []
    for i in range(nb):
        o = b0 + 12 * i
        rel, typ, key = struct.unpack_from(">3I", d, o)
        p = o + rel
        if p + 4 > len(d):
            raise UiDataError("text pointer out of range")
        # class 0x92A82712: pointer to a pointer to the text; class 0x9EDE2887: pointer to the text
        q = p + struct.unpack_from(">I", d, p)[0] if typ == STRING_CLASS_INDIRECT else p
        oa = a0 + 8 * i
        ra, scale = struct.unpack_from(">If", d, oa)
        out.append({"key": key, "type": typ, "font": _cstr(d, oa + ra), "scale": scale, "text": _wstr(d, q)})
    case = []
    try:
        c0, nc = _arr(d, 0x30)
        for i in range(nc):
            lo, up = struct.unpack_from(">2H", d, c0 + 4 * i)
            case.append([lo, up])
    except (UiDataError, struct.error):
        pass
    return {"entries": out, "case_map": case}


LANG_HINTS = {
    "en": (" the ", " and ", " you ", " your "),
    "fr": (" le ", " les ", " des ", " vous "),
    "de": (" der ", " die ", " und ", " Sie "),
    "es": (" el ", " los ", " para ", " del "),
    "it": (" il ", " di ", " per ", " sono "),
}


def guess_language(texts):
    blob = " " + " ".join(texts) + " "
    scores = {k: sum(blob.count(w) for w in ws) for k, ws in LANG_HINTS.items()}
    return max(scores, key=scores.get), scores


# ------------------------------------------------------------------------------------------- fonts

def parse_abc_font(d: bytes):
    """Return {"height", "tex_w", "tex_h", "ranges": [[first,last]...], "glyphs": [...], "map": {code: glyph}}.

    Little-endian (the format of the XDK ATG font tool):
      u32 version (6), u32 line height (px), u32 texture width, u32 texture height,
      u32 ascent-ish value (unverified), u32 nranges, nranges x (u16 first, u16 last),
      u32 nglyphs, nglyphs x 28 B {f32 u0, v0, u1, v1, i16 offset, i16 width, i16 advance, u16 pad, u32 mask}
    Glyphs are assigned to the codes of the ranges in order.  The texture is the XPR2 entry with the
    font's name (Main_White / Main_Gray / Main_Big in Core.arc).
    """
    if len(d) < 0x1C:
        raise UiDataError("font too short")
    ver, height, tw, th, base, nr = struct.unpack_from("<6I", d, 0)
    if ver != FONT_VERSION or nr > 4096:
        raise UiDataError("not a version-6 .abc font")
    ranges = [list(struct.unpack_from("<2H", d, 0x18 + 4 * i)) for i in range(nr)]
    p = 0x18 + 4 * nr
    if p + 4 > len(d):
        raise UiDataError("truncated font")
    ng = struct.unpack_from("<I", d, p)[0]
    p += 4
    if p + 28 * ng > len(d):
        raise UiDataError("truncated glyph table")
    glyphs = []
    for i in range(ng):
        u0, v0, u1, v1, off, w, adv, _pad, mask = struct.unpack_from("<4f3hHI", d, p + 28 * i)
        glyphs.append({"uv": [u0, v0, u1, v1], "offset": off, "width": w, "advance": adv, "mask": mask})
    cmap = {}
    gi = 0
    for first, last in ranges:
        for c in range(first, last + 1):
            if gi < ng:
                cmap[c] = gi
            gi += 1
    return {"version": ver, "height": height, "tex_w": tw, "tex_h": th, "base": base,
            "ranges": ranges, "glyphs": glyphs, "map": cmap}


# ------------------------------------------------------------------------------------------- scenes

def decode_positioning(raw: str):
    """PositioningInfo: 48 bytes, 12 big-endian floats (translation xyz, scale xyz, rotation xyz,
    pivot xyz; the meaning of the last two triples is unverified)."""
    b = raw.encode("latin-1") if isinstance(raw, str) else bytes(raw)
    if len(b) < 48:
        b = b + b"\0" * (48 - len(b))
    v = struct.unpack_from(">12f", b, 0)
    return {"t": list(v[0:3]), "s": list(v[3:6]), "r": list(v[6:9]), "p": list(v[9:12])}


def decode_control_data(raw: str):
    """SceneData.ControlData: u32 n, u32 n, then n records {u32 len, name, u32 id, u32 ?, i32 parent, u32 ?}.

    Returns [{"name", "id"}].  Only the names and ids are interpreted (best effort)."""
    b = raw.encode("latin-1") if isinstance(raw, str) else bytes(raw)
    out = []
    if len(b) < 8:
        return out
    n = struct.unpack_from(">I", b, 0)[0]
    o = 8
    for _ in range(min(n, 4096)):
        if o + 4 > len(b):
            break
        ln = struct.unpack_from(">I", b, o)[0]
        if ln > 256 or o + 4 + ln > len(b):
            break
        name = b[o + 4:o + 4 + ln].decode("latin-1")
        o += 4 + ln
        rest = list(struct.unpack_from(">4i", b, o)) if o + 16 <= len(b) else []
        o += 16
        out.append({"name": name, "fields": rest})
    return out


BINARY_FIELDS = {"PositioningInfo", "ControlData"}


def scene_to_json(v, to_json):
    """Post-process a ``lua50.to_json`` tree: decode binary blobs, keep everything else."""
    if isinstance(v, dict):
        out = {}
        for k, x in v.items():
            if k == "PositioningInfo" and isinstance(x, str):
                out[k] = decode_positioning(x)
            elif k == "ControlData" and isinstance(x, str):
                out[k] = decode_control_data(x)
            else:
                out[k] = scene_to_json(x, to_json)
        return out
    if isinstance(v, list):
        return [scene_to_json(x, to_json) for x in v]
    return v
