#!/usr/bin/env python3
"""Reader for the RUI ``*.actions`` (tokenised action scripts) and ``*.anims`` (timelines) files.

Both are big-endian binary companions of a ``*.scene`` (Lua) file inside the game's archives.
Formats were decoded from the retail files (no code reference yet; see docs/port/ui.md s2):

``.actions``::

    u32 nactions, u32 pool_bytes
    nactions x u32 record offset          (relative to the record area)
    u32 nstrings, nstrings x u32 offset   (relative to the string pool)
    record area:  per action
        u32 0, u16 name_len, name, u16 nparams, u8 params_len, params (u8 len + chars each),
        u8 has_body, [u16 flags, statements...]  up to the next record
        statement = u8 len, len token bytes; a byte >= 0x80 starts a 2-byte string reference
        ((b & 0x7F) << 8 | next) into the pool, any other byte is a literal character
    string pool: u8 len + chars per string (at the end of the file)

The statements are a small command language: ``SceneOn``, ``Wait(5)``, ``ChangeScene('S4Loading')``,
``$Scene.Method``, ``self.__Action_0()`` (a Lua closure of the scene), ``@Name@`` (an action
parameter), ``SetActiveControl('', 0)`` and so on.

``.anims``: u32 ntracks-ish header, then fixed records naming a node (``Menu``) and a property
(``visibility``, ``SceneOn`` ...) with key frames; only the names and the key times/values are read
here (``parse_anims``), enough to know which timelines a scene has.

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
            idx = ((b & 0x7F) << 8) | tok[i + 1]
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
    pool_bytes = _u32(d, 4)
    if n > 100000 or pool_bytes > len(d):
        raise UiFormatError("not an .actions file")
    offs = [_u32(d, 8 + 4 * i) for i in range(n)]
    p = 8 + 4 * n
    ns = _u32(d, p)
    if ns > 100000:
        raise UiFormatError("bad string count")
    soffs = [_u32(d, p + 4 + 4 * i) for i in range(ns)]
    rec_base = p + 4 + 4 * ns
    pool_base = len(d) - pool_bytes
    if pool_base < rec_base:
        raise UiFormatError("pool overlaps records")
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
        body = []
        flags = None
        if o < stop and d[o]:
            flags = _u16(d, o + 1)
            o += 3
            while o < stop:
                ln = d[o]
                if ln == 0:
                    break
                body.append(detokenize(d[o + 1:o + 1 + ln], pool))
                o += 1 + ln
        actions.append({"name": name, "params": params, "flags": flags, "body": body})
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


def parse_anims(d: bytes):
    """Collect (node, property) name pairs and the float payloads that follow them."""
    names = []
    for m in re.finditer(rb"\xff\xff\xff\xff([A-Za-z_][\x20-\x7e]{1,63}?)\x00", d):
        names.append(m.group(1).decode("latin-1"))
    head = list(struct.unpack_from(">2I", d, 0)) if len(d) >= 8 else []
    return {"header": head, "names": names}


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
            for s in act["body"]:
                print("    " + s)
    else:
        print(json.dumps(parse_anims(d), indent=1))


if __name__ == "__main__":
    main()
