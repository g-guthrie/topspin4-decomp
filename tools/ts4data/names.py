#!/usr/bin/env python3
"""Recover names for the crc32 hashes used by Top Spin 4 XBin data (standard library only).

Every member, type and key name in the game data is ``zlib.crc32`` of an ASCII string.  This tool
collects candidate strings and keeps those whose crc32 hits a target hash.

Targets: every member name and type name in Layoutall.bin, plus every CKey value found by the
generic walker in the files given with ``--xbin``.

Candidates and confidence (written next to each name):
  dict     the game's own CRC dictionary files (AnimationsDBcrc.bin, CommonCRCDictionnary.bin, any
           *crc.bin) - certain
  string   a whole printable string found in a game file or the executable - high
  token    a token of such a string (split on non-identifier characters, XML paths '/','@',
           '::' and camel-case words), also with '__', 'C' or 'Type' affixes - high
  combo2   two camel-case words joined, both among the --top most frequent words - medium
           (with ~10k targets and N^2 candidates expect about N^2*targets/2^32 false hits; the
           report prints that estimate)
Existing JSON dictionaries can be merged with ``--merge`` (their entries are kept as 'merged').

Usage:
  python3 tools/ts4data/names.py --layout work/disc/root/Layoutall.bin \
      --strings work/disc/core_all orig/54540859/Swing_DLL.dll \
      --xbin work/disc/core_all/334e7e0d.bin ... --out work/disc/values/names.json [--top 2500]
"""
from __future__ import annotations

import argparse
import json
import os
import re
import struct
import sys
import zlib
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402

CRC_DICT_SIG = bytes.fromhex("8b8c76895e7af2a3")


def iter_files(paths):
    for p in paths:
        if os.path.isdir(p):
            for n in sorted(os.listdir(p)):
                q = os.path.join(p, n)
                if os.path.isfile(q):
                    yield q
        elif os.path.isfile(p):
            yield p


def strings_of(data):
    for m in re.finditer(rb"[\x20-\x7e]{2,120}", data):
        yield m.group().decode("latin-1")
    for m in re.finditer(rb"(?:[\x20-\x7e]\x00){3,120}", data):
        yield m.group().decode("utf-16le")


CAMEL = re.compile(r"[A-Z][a-z0-9]+|[A-Z]+(?![a-z])|[a-z0-9]+")


def tokens_of(s):
    out = set()
    for t in re.split(r"[^A-Za-z0-9_]+", s):
        if t:
            out.add(t)
            out.update(t.split("_"))
    for t in re.split(r"[/\\@. :\[\]=,;()\"']+", s):
        if t:
            out.add(t)
    return {t for t in out if 1 <= len(t) <= 80}


def collect_targets(layout, xbins):
    tgt = set(layout.types)
    for _tc, (_s, _a, ms) in layout.types.items():
        for m in ms:
            tgt.add(m.name)
            tgt.add(m.type)
    for p in xbins:
        buf = open(p, "rb").read()
        try:
            w = X.Walker(buf, layout)
            for lf in w.walk_file():
                if lf.tag == "key":
                    tgt.add(lf.value)
            for _path, _o, tc in w.objects:
                tgt.add(tc)
        except Exception:  # noqa: BLE001 - not a walkable file
            pass
    tgt.discard(0)
    return tgt


WORD_PART = re.compile(r"[A-Z][a-z]+|[A-Z]{1,4}(?![a-z])|[a-z]+|[0-9]{1,3}|_")


def wordlike(t):
    """True for identifiers made of plausible words (camel case, short acronyms, digits)."""
    if len(t) < 2 or len(t) > 48 or not t.replace("_", "").isalnum() or not t.isascii():
        return False
    parts = WORD_PART.findall(t)
    if "".join(parts) != t:
        return False
    for p in parts:
        if p.isalpha() and len(p) > 3:
            low = p.lower()
            if sum(c in "aeiouy" for c in low) * 5 < len(low):
                return False
    letters = [c for c in t.lower() if c.isalpha()]
    return bool(letters) and sum(c in "aeiouy" for c in letters) * 6 >= len(letters)


def nested_pass(layout, found, word_by_crc):
    """Nested type names follow '<parent type>_<member name>' (e.g.
    Pam::System::CDataLifeTimeManager_DataZoneList_DataZone).  Two 32-bit checks (member name
    and member type) make every hit here high confidence.  Iterates to a fixed point."""
    by_type = layout.types
    changed = True
    while changed:
        changed = False
        for tc, (_s, _a, ms) in by_type.items():
            if tc not in found:
                continue
            parent = found[tc][0]
            pre = zlib.crc32((parent + "_").encode())
            for m in ms:
                if m.attr or not m.type:
                    continue
                if m.name in found and m.type not in found:
                    v = parent + "_" + found[m.name][0]
                    if X.crc(v) == m.type:
                        found[m.type] = (v, "nested")
                        changed = True
                elif m.type in found and m.name not in found:
                    tn = found[m.type][0]
                    if tn.startswith(parent + "_"):
                        w = tn[len(parent) + 1:]
                        if X.crc(w) == m.name:
                            found[m.name] = (w, "nested")
                            changed = True
                elif m.name not in found and m.type not in found:
                    w = word_by_crc.get(m.name)
                    if w is not None and zlib.crc32(w.encode(), pre) == m.type:
                        found[m.name] = (w, "nested")
                        found[m.type] = (parent + "_" + w, "nested")
                        changed = True


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--layout", required=True)
    ap.add_argument("--strings", nargs="+", default=[], help="files or directories to take strings from")
    ap.add_argument("--xbin", nargs="*", default=[], help="XBin files whose CKey values are also targets")
    ap.add_argument("--merge", nargs="*", default=[], help="JSON {hex: name} dictionaries to merge")
    ap.add_argument("--top", type=int, default=2500, help="words used for two-word combinations (0 = off)")
    ap.add_argument("--out", required=True)
    a = ap.parse_args(argv)

    layout = X.Layout(open(a.layout, "rb").read())
    tgt = collect_targets(layout, a.xbin)
    found = {}

    def hit(h, name, src):
        if h in tgt and h not in found:
            found[h] = (name, src)

    for n in X.TYPE_NAMES.values():
        hit(X.crc(n), n, "string")
    strs = set()
    for p in iter_files(a.strings):
        data = open(p, "rb").read()
        if len(data) > 0x24 and data[:8] == CRC_DICT_SIG:
            try:
                for h, n in X.read_crc_dictionary(data).items():
                    hit(h, n, "dict")
            except ValueError:
                pass
        strs.update(strings_of(data))
    for p in a.merge:
        d = json.load(open(p))
        subs = d.values() if all(isinstance(v, dict) for v in d.values()) else [d]
        for sub in subs:
            for k, v in sub.items():
                if isinstance(v, str):
                    hit(int(k, 16), v, "merged")
    for s in strs:
        hit(X.crc(s), s, "string")
    toks = set()
    words = Counter()
    for s in strs:
        for t in tokens_of(s):
            toks.add(t)
            for u in CAMEL.findall(t):
                words[u[:1].upper() + u[1:]] += 1
    # exact tokens are fine as they are (one candidate each); affixed and namespaced forms only
    # for word-like tokens so that binary junk cannot produce hits
    good = [t for t in toks if wordlike(t)]
    for t in toks:
        hit(X.crc(t), t, "token")
    for t in good:
        for v in (t[:1].upper() + t[1:], "__" + t, "C" + t, t + "Type", "Is" + t, "m_" + t):
            hit(X.crc(v), v, "token")
    # namespace sweep (type names only): every namespace seen in a recovered name x every
    # word-like token, as Name / CName / CNameType
    type_tgt = set(layout.types)
    for _tc, (_s, _a, ms) in layout.types.items():
        type_tgt.update(m.type for m in ms)
    nspaces = {"Pam::"}
    for n, _src in list(found.values()):
        parts = n.split("::")
        for k in range(1, len(parts)):
            nspaces.add("::".join(parts[:k]) + "::")
    for ns in sorted(nspaces):
        pre = zlib.crc32(ns.encode())
        for t in good:
            for v in (t, "C" + t, t + "Type", "C" + t + "Type"):
                h = zlib.crc32(v.encode(), pre)
                if h in type_tgt and h not in found:
                    found[h] = (ns + v, "namespace")
    word_by_crc = {}
    for t in good:
        word_by_crc.setdefault(X.crc(t), t)
    nested_pass(layout, found, word_by_crc)
    combos = 0
    if a.top:
        top = [w.encode() for w, _c in words.most_common(a.top)]
        tset = tgt
        for x in top:
            cx = zlib.crc32(x)
            for y in top:
                h = zlib.crc32(y, cx)
                if h in tset and h not in found:
                    found[h] = ((x + y).decode(), "combo2")
            combos += len(top)
    nested_pass(layout, found, word_by_crc)
    est = combos * len(tgt) / 2 ** 32
    out = {"_meta": {"targets": len(tgt), "found": len(found), "combo2_candidates": combos,
                     "combo2_expected_false_hits": round(est, 1),
                     "by_source": dict(Counter(s for _n, s in found.values()))},
           "names": {"%08x" % h: {"name": n, "src": s} for h, (n, s) in sorted(found.items())}}
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as o:
        json.dump(out, o, indent=0)
    print(json.dumps(out["_meta"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
