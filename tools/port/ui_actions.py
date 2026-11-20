#!/usr/bin/env python3
"""Reader for the RUI ``*.actions`` (tokenised action scripts) and ``*.anims`` (timelines) files.

Both are big-endian binary companions of a ``*.scene`` (Lua) file inside the game's archives.
Formats were decoded from the retail files (no code reference yet; see docs/port/ui.md s2):

``.actions``::

    u32 nactions, u32 record_bytes (the string pool follows the record area)
    nactions x u32 record offset          (relative to the record area)
    u32 nstrings, nstrings x u32 offset   (relative to the string pool)
    record area:  per action
        u32 0, u16 name_len, name, u16 nparams, u8 params_len, params (u8 len + chars each),
        u8 nblocks, nblocks x {u16 cond_len, cond (tokens, first byte 0x01; empty = unconditional),
                               statements..., u8 0}
        statement = u8 len, len token bytes; a byte >= 0x80 starts a 2-byte string reference
        ((b & 0x7F) | next << 7) into the pool, any other byte is a literal character
    string pool: u8 len + chars per string (at the end of the file)

The statements are a small command language: ``SceneOn``, ``Wait(5)``, ``ChangeScene('S4Loading')``,
``$Scene.Method``, ``self.__Action_0()`` (a Lua closure of the scene), ``@Name@`` (an action
parameter), ``SetActiveControl('', 0)`` and so on.

``.anims``: named clips (``SceneOn``, ``SceneOff``, ``OnSelected`` ...) of key-framed curves on node
properties; see ``parse_anims``.

  python3 tools/port/ui_actions.py actions FILE     # pretty listing
  python3 tools/port/ui_actions.py anims FILE
"""
from __future__ import annotations

import json
import re
import struct
import sys


class UiFormatError(ValueError):
    pass


def _u32(d, o):
    if o + 4 > len(d):
        raise UiFormatError("truncated at 0x%X" % o)
    return struct.unpack_from(">I", d, o)[0]


def _u16(d, o):
    if o + 2 > len(d):
        raise UiFormatError("truncated at 0x%X" % o)
    return struct.unpack_from(">H", d, o)[0]


def _pstr(d, o):
    if o >= len(d):
        raise UiFormatError("truncated string at 0x%X" % o)
    n = d[o]
    if o + 1 + n > len(d):
        raise UiFormatError("truncated string at 0x%X" % o)
    return d[o + 1:o + 1 + n].decode("latin-1"), o + 1 + n


def detokenize(tok: bytes, pool):
    out = []
    i = 0
    while i < len(tok):
        b = tok[i]
        if b >= 0x80:
            if i + 1 >= len(tok):
                raise UiFormatError("dangling string reference")
            idx = (b & 0x7F) | (tok[i + 1] << 7)
            if idx >= len(pool):
                raise UiFormatError("string reference %d out of range" % idx)
            out.append(pool[idx])
            i += 2
        else:
            out.append(chr(b))
            i += 1
    return "".join(out)


def parse_actions(d: bytes):
    """Return {"actions": [{"name", "params", "flags", "body": [statement, ...]}], "strings": [...]}."""
    n = _u32(d, 0)
    rec_bytes = _u32(d, 4)
    if n > 100000 or rec_bytes > len(d):
        raise UiFormatError("not an .actions file")
    offs = [_u32(d, 8 + 4 * i) for i in range(n)]
    p = 8 + 4 * n
    ns = _u32(d, p)
    if ns > 100000:
        raise UiFormatError("bad string count")
    soffs = [_u32(d, p + 4 + 4 * i) for i in range(ns)]
    rec_base = p + 4 + 4 * ns
    pool_base = rec_base + rec_bytes
    if pool_base > len(d):
        raise UiFormatError("record area past the end")
    pool = [_pstr(d, pool_base + o)[0] for o in soffs]
    ends = offs[1:] + [pool_base - rec_base]
    actions = []
    for off, end in zip(offs, ends):
        o = rec_base + off
        stop = rec_base + end
        if not (rec_base <= o <= stop <= pool_base):
            raise UiFormatError("bad record bounds")
        o += 4
        nl = _u16(d, o)
        name = d[o + 2:o + 2 + nl].decode("latin-1")
        o += 2 + nl
        npar = _u16(d, o)
        plen = d[o + 2]
        o += 3
        params = []
        q = o
        for _ in range(npar):
            s, q = _pstr(d, q)
            params.append(s)
        o += plen
        blocks = []
        nblocks = d[o] if o < stop else 0
        o += 1
        for _ in range(nblocks):
            if o + 2 > stop:
                raise UiFormatError("truncated block")
            cl = _u16(d, o)
            cond = d[o + 2:o + 2 + cl]
            o += 2 + cl
            stmts = []
            while o < stop:
                ln = d[o]
                o += 1
                if ln == 0:
                    break
                if o + ln > stop:
                    raise UiFormatError("statement past the record end")
                stmts.append(detokenize(d[o:o + ln], pool))
                o += ln
            c = detokenize(cond, pool) if cond else None
            blocks.append({"if": c.lstrip("\x01") if c else None, "do": stmts})
        body = [x for b in blocks for x in b["do"]]
        actions.append({"name": name, "params": params, "blocks": blocks, "body": body})
    return {"actions": actions, "strings": pool}


CALL_RE = re.compile(r"^\$?([A-Za-z_][\w.]*)\s*(?:\((.*)\))?$")


def statement_calls(stmt: str):
    """Split a statement into (command, [args]) when it has the simple call form."""
    m = CALL_RE.match(stmt.strip())
    if not m:
        return None
    args = []
    if m.group(2):
        args = [a.strip().strip("'") for a in re.split(r",(?![^()]*\))", m.group(2))]
    return m.group(1), args


def _name_block(d, o):
    """[u32 len][u32 padded len][u32 0xFFFFFFFF][chars, padded] -> (string, offset after)."""
    n, pad = _u32(d, o), _u32(d, o + 4)
    if _u32(d, o + 8) != 0xFFFFFFFF or n > pad or o + 12 + pad > len(d):
        raise UiFormatError("bad name block at 0x%X" % o)
    return d[o + 12:o + 12 + n].decode("latin-1").rstrip("\0"), o + 12 + pad


def _is_curve(d, o):
    if o + 0x28 > len(d):
        return False
    first, size, no, po, to, ff = struct.unpack_from(">6I", d, o)
    return ff == 0xFFFFFFFF and first in (0, 8) and 0x20 <= no < po < to <= size + 8 and o + size <= len(d)


def parse_anims(d: bytes):
    """Decode an ``.anims`` file: named clips made of key-framed property curves.

    Layout (big endian):
      u32 (often the clip count, not always), f32 duration of the first curve group
      curve groups, one per clip: curves back to back; between groups 2-3 words, the last one the
        group's duration (f32 seconds)
        curve: u32 first (8 for the first curve of a group, else 0), u32 size (from the curve), u32 node_off,
               u32 prop_off, u32 tail_off (these three count from curve - 8),
               u32 0xFFFFFFFF, u32 nkeys, u32 flags (0x00010000 = stepped), u32 0, u32 0,
               nkeys x {f32 time, f32 value, f32 in_dx, in_dy, out_dx, out_dy}   (Maya-style tangents)
               name block at node_off (target node, may contain "|" paths and @Param@), name block at
               prop_off (visibility, translateX, scaleY, rotateZ, globalColorA/R/G/B, imageCenterX, ...)
      2 words, then the clip table: u32 nclips, per clip {u32 0x24, u32 first-curve offset (from file
        offset 8), f32 1.0, f32 1.0, u32 0, u32 0, name block}
    Returns {"clips": {name: {"duration", "curves": [{"node", "prop", "step", "keys": [[t, v, idx, idy,
    odx, ody], ...]}]}}}.
    """
    if len(d) < 8:
        raise UiFormatError("anims too short")
    nclips = _u32(d, 0)
    if nclips > 10000:
        raise UiFormatError("not an .anims file")
    groups = []          # [(start offset rel 8, duration, curves)]
    o = 8
    cur = {"start": 0, "duration": struct.unpack_from(">f", d, 4)[0], "curves": []}
    groups.append(cur)
    if not _is_curve(d, o):          # some files pad the first group header
        nxt = next((o + k for k in range(4, 36, 4) if _is_curve(d, o + k)), None)
        if nxt is not None:
            cur["start"] = nxt - 8
            o = nxt
    guard = 0
    while o < len(d) and guard < 100000:
        guard += 1
        if _is_curve(d, o):
            first, size, no, po, to, _ff = struct.unpack_from(">6I", d, o)
            nk = _u32(d, o + 24)
            flags = _u32(d, o + 28)
            base = o - 8          # name offsets count from 8 bytes before the curve
            if o + 0x28 + 24 * nk > base + no:
                raise UiFormatError("keys overlap the names at 0x%X" % o)
            keys = [list(struct.unpack_from(">6f", d, o + 0x28 + 24 * k)) for k in range(nk)]
            node, _ = _name_block(d, base + no)
            prop, _ = _name_block(d, base + po)
            cur["curves"].append({"node": node, "prop": prop, "step": bool(flags & 0x10000), "keys": keys})
            o += size
            continue
        nxt = next((o + k for k in range(4, 36, 4) if _is_curve(d, o + k)), None)
        if nxt is not None:
            cur = {"start": nxt - 8, "duration": struct.unpack_from(">f", d, nxt - 4)[0], "curves": []}
            groups.append(cur)
            o = nxt
            continue
        break
    # clip table
    clips = {}
    t = None
    for k in range(0, 36, 4):
        if o + k + 8 <= len(d) and _u32(d, o + k) < 10000 and _u32(d, o + k + 4) == 0x24:
            nclips = _u32(d, o + k)
            t = o + k + 4
            break
    by_start = {g["start"]: g for g in groups}
    if t is not None:
        for _ in range(nclips):
            if _u32(d, t) != 0x24:
                break
            start = _u32(d, t + 4)
            name, t2 = _name_block(d, t + 24)
            g = by_start.get(start)
            clips[name] = {"duration": g["duration"] if g else 0.0, "curves": g["curves"] if g else [],
                           "speed": struct.unpack_from(">f", d, t + 8)[0]}
            t = t2
    names = sorted({c["node"] for g in groups for c in g["curves"]})
    return {"clips": clips, "nodes": names}


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("kind", choices=["actions", "anims"])
    ap.add_argument("file")
    a = ap.parse_args(argv)
    d = open(a.file, "rb").read()
    if a.kind == "actions":
        r = parse_actions(d)
        for act in r["actions"]:
            print("action %s(%s)" % (act["name"], ", ".join(act["params"])))
            for b in act["blocks"]:
                ind = "    "
                if b["if"]:
                    print("    if %s then" % b["if"])
                    ind = "        "
                for s in b["do"]:
                    print(ind + s)
    else:
        print(json.dumps(parse_anims(d), indent=1))


if __name__ == "__main__":
    main()
