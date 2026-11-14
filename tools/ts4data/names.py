#!/usr/bin/env python3
"""Recover names for the crc32 hashes used by Top Spin 4 XBin data (standard library only).

Every type, member and key name in the game data is ``zlib.crc32`` of an ASCII string.  This tool
collects candidate strings and keeps those whose crc32 hits a target hash, then uses the structure
of ``Layoutall.bin`` to derive more names.

Targets: every type and member name hash in Layoutall.bin, plus every CKey value found by the
generic walker in the files given with ``--xbin``.

CRC algebra (why some rules are strong and others are not)
  zlib's crc32 is affine: for strings of equal length n, crc32(P + w) ^ crc32(w) depends only on
  crc32(P) and n.  Two hashes of strings that share the unknown part w (``Parent_w`` and ``w``,
  ``NS::w`` and ``w``, ``Isw`` and ``w``) are therefore NOT independent checks: together they give
  crc32(w) plus the length of w.  Conversely the prefix state can be computed backwards
  (``crc_prefix``) from a type hash and a known suffix, which is how namespaces are found without
  knowing their text: every (member name w, member type t) pair votes for the prefix state P with
  crc32(P + w) == t, and a state voted by many types is a namespace (or ``Parent_``).

Rules and confidence (written next to each name)
  dict      the game's own CRC dictionary files (*crc.bin, CommonCRCDictionnary.bin)    certain
  merged    names from other dictionaries (--merge, data/gameplay/names.yaml); confidence kept
  string    a whole printable string of a game file or executable (identifier-like
            for types/members)                                                          high
  token     a word-like token of such a string (and Is/C/Type affixes)                  high
  nsrule    type = <known namespace or type prefix> + <member name> (+C/Type affix).
            The prefix state is voted by several types, so a hit is a 32-bit check of
            the member name plus a check of the namespace                               high
  nested    type = Parent + '_' + member (detected on hashes alone, which also gives
            the member name length)                                                     high
  pattern   a known member name with its digits replaced (0..16) or a word swapped (Min/Max,
            Left/Right, Forehand/Backhand, ...)                                          medium
  sibling   member name built from words of the sibling members, the parent and
            member type names; few candidates per type                                  medium
  guess3    1-3 vocabulary words whose total length equals the length implied by the
            nested / namespace rule (32-bit check + length)                             medium
  combo2    two vocabulary words, no length constraint; expected false hits are
            reported in _meta                                                           low

Usage:
  python3 tools/ts4data/names.py --layout work/disc/root/Layoutall.bin \
      --strings work/disc/core_all orig/54540859/Swing_DLL.dll work/disc/tu1_arc \
      --xbin work/disc/core_all/334e7e0d.bin ... --merge data/gameplay/analyser_names.json \
      --out work/disc/values/names.json --yaml data/gameplay/names.yaml
"""
from __future__ import annotations

import argparse
import json
import os
import re
import sys
import zlib
from collections import Counter, defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_xbin as X  # noqa: E402

CRC_DICT_SIG = bytes.fromhex("8b8c76895e7af2a3")
CONF = {"dict": "certain", "string": "high", "token": "high", "nsrule": "high", "nested": "high",
        "seed": "high", "sibling": "medium", "pattern": "medium", "guess3": "medium", "combo2": "low"}
RANK = {"certain": 4, "high": 3, "medium": 2, "low": 1}

# Namespaces whose text is known.  Each was found as a prefix state voted by several types (see the
# module doc) and then matched by a word search; the comment names the evidence.
KNOWN_NAMESPACES = [
    "Pam::SwingGamePlay::Data::",        # 30+ types (AI, Aiming, Ball, Behavior, Expressions, ...)
    "Pam::Swing::GameplayInterface::",   # GameplayInputs, GameplayOutputs, BallInfo, RulesInfo, ...
    "Pam::Swing::SeasonDB::",            # Event, EventList, Mail, Ranking, ...
    "Pam::Swing::Season::",              # Calendar, Nation, SeasonSave, Unlock, ...
    "Pam::Swing::SystemData::",          # GamePlay, Menu, Physic, PlayerCreator, ...
    "Pam::Swing::MatchSettings::",       # PlayerList, RulesConfig, SetList, TeamList, ...
    "Pam::DisplayAnimation::",           # Animation, AnimationInterface, EventAction, KeyList, ...
    "Pam::PlayerCreator::",              # DNAType, GeometryType, MaterialType, TextureType, ...
    "Pam::Net::Data::",                  # CommandType, MatchmakingType, SessionType, ...
]
# Roots named from the XPath roots in the executable ("GamePlayState:/SwingData/State/...",
# "GamePlayInterface:/SwingGameplayInterface/...") and checked against the root type hashes.
SEED_NAMES = [
    "Pam::SwingGamePlay::Data::SwingData",          # 0xD2968089 generic data tree (Settings/State/...)
    "Pam::SwingGamePlay::Data::SettingsData",       # 0x9B4FB082 Settings.bin root
    "Pam::SwingGamePlay::Data::StateData",          # 0xB77BBB90 State.bin root
    "Pam::SwingGamePlay::Data::ModuleData",         # 0x8070B164 Module.bin root
    "Pam::SwingGamePlay::Data::Expressions",        # 0xD440C339 Expressions.bin root
    "Pam::Swing::GameplayInterface::SwingGameplayInterface",  # 0x5E16CF76
    "Settings", "State",                            # members of SwingData
]
TYPE_AFFIX = ["{}", "C{}", "{}Type", "C{}Type"]

# ---------------------------------------------------------------- crc helpers
_T = []
for _i in range(256):
    _c = _i
    for _ in range(8):
        _c = (_c >> 1) ^ 0xEDB88320 if _c & 1 else _c >> 1
    _T.append(_c)
_RT = {_T[i] >> 24: i for i in range(256)}


def crc_prefix(target, suffix):
    """Return the crc32 state s with zlib.crc32(suffix, s) == target (runs the CRC backwards)."""
    s = target ^ 0xFFFFFFFF
    for b in reversed(suffix):
        i = _RT[s >> 24]
        s = (((s ^ _T[i]) << 8) & 0xFFFFFFFF) | (i ^ b)
    return s ^ 0xFFFFFFFF


_ZERO = {}


def shift(state, n):
    """Linear part F_n with crc32(P + w) == shift(crc32(P), len(w)) ^ crc32(w)."""
    z = _ZERO.get(n)
    if z is None:
        z = _ZERO[n] = (b"\0" * n, zlib.crc32(b"\0" * n))
    return zlib.crc32(z[0], state) ^ z[1]


def implied_length(prefix_state, name_hash, type_hash, maxlen=64):
    """Lengths n for which type_hash == crc32(P + w) and name_hash == crc32(w) can both hold."""
    return [n for n in range(1, maxlen) if shift(prefix_state, n) ^ name_hash == type_hash]


# ---------------------------------------------------------------- strings and words
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
CAMEL_WORD = re.compile(r"[A-Z][a-z]+|[A-Z]+(?![a-z])|[a-z]+|[0-9]+")
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*(::[A-Za-z_][A-Za-z0-9_]*)*")


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


def identlike(name):
    """Plausible type or member name: an identifier (optionally ::-qualified) whose last part,
    split on '_', is made of word-like pieces."""
    if not IDENT.fullmatch(name):
        return False
    last = name.split("::")[-1]
    return all(wordlike(p) or p.isdigit() or len(p) == 1 or p in ("C",) for p in last.split("_") if p)


# ---------------------------------------------------------------- name store
class Names:
    def __init__(self, targets, type_targets, member_targets):
        self.targets, self.types, self.members = targets, type_targets, member_targets
        self.found = {}

    def ok(self, h, name):
        if h in self.types or h in self.members:
            return identlike(name)
        return True

    def add(self, h, name, src, conf=None, note=None):
        if h not in self.targets or h in self.found or X.crc(name) != h:
            return False
        if src not in ("dict", "merged", "seed") and not self.ok(h, name):
            return False
        self.found[h] = (name, src, conf or CONF.get(src, "medium"), note)
        return True

    def name(self, h):
        f = self.found.get(h)
        return f[0] if f else None


def collect_targets(layout, xbins):
    types, members = set(layout.types), set()
    for _tc, (_s, _a, ms) in layout.types.items():
        for m in ms:
            members.add(m.name)
            types.add(m.type)
    keys = set()
    for p in xbins:
        buf = open(p, "rb").read()
        try:
            w = X.Walker(buf, layout)
            for lf in w.walk_file():
                if lf.tag == "key":
                    keys.add(lf.value)
            for _path, _o, tc in w.objects:
                types.add(tc)
        except Exception:  # noqa: BLE001 - not a walkable file
            pass
    for s in (types, members, keys):
        s.discard(0)
    return types | members | keys, types, members


# ---------------------------------------------------------------- structure
class Structure:
    """Hash-level relations of the layout: nested members (type = Parent_member) with the implied
    member-name length, and members whose type is <namespace> + member name."""

    def __init__(self, layout):
        self.layout = layout
        self.nested = {}       # (parent, member name hash) -> (type, length)
        self.pairs = []        # (parent, member) for element members
        for tc, (_s, _a, ms) in layout.types.items():
            for m in ms:
                if m.attr or not m.type:
                    continue
                self.pairs.append((tc, m))
                ls = [n for n in range(1, 64) if shift(zlib.crc32(b"_", tc), n) ^ m.name == m.type]
                if ls:
                    self.nested[(tc, m.name)] = (m.type, ls[0])

    def length_hints(self, prefix_states):
        """{member name hash: set(lengths)} from the nested rule and from namespace prefixes."""
        hints = defaultdict(set)
        for (_p, h), (_t, n) in self.nested.items():
            hints[h].add(n)
        table = {}
        for p in prefix_states:
            for pre in (b"", b"C"):
                ps = zlib.crc32(pre, p)
                for n in range(1, 48):
                    table.setdefault(shift(ps, n), set()).add(n)
        for tc, m in self.pairs:
            if (tc, m.name) not in self.nested:
                hints[m.name].update(table.get(m.name ^ m.type, ()))
        return hints


def vote_prefixes(names, structure, min_votes=3):
    """Prefix states voted by >= min_votes distinct types through (member name, type) pairs."""
    votes = defaultdict(set)
    for _tc, m in structure.pairs:
        w = names.name(m.name)
        if w is None or m.type in names.found:
            continue
        for v in TYPE_AFFIX:
            votes[crc_prefix(m.type, v.format(w).encode())].add(m.type)
    return {p: len(ts) for p, ts in votes.items() if len(ts) >= min_votes}


def prefix_map(names, extra_ns=()):
    pm = {}
    for ns in list(KNOWN_NAMESPACES) + list(extra_ns):
        pm[X.crc(ns)] = ns
    for h, (n, _s, _c, _nt) in names.found.items():
        if "::" in n and h in names.types:
            ns = n[:n.rfind("::") + 2]
            pm.setdefault(X.crc(ns), ns)
    return pm


def propagate(names, structure):
    """Apply the nested and namespace rules until nothing changes.  Returns names added."""
    added = 0
    while True:
        n0 = len(names.found)
        pm = prefix_map(names)
        for tc, m in structure.pairs:
            nl = structure.nested.get((tc, m.name))
            pn = names.name(tc)
            if nl and pn:
                mt, ln = nl
                w = names.name(m.name)
                tn = names.name(mt)
                if w and not tn and len(w) == ln:
                    names.add(mt, pn + "_" + w, "nested", min_conf(names, tc, m.name))
                elif tn and not w and tn.startswith(pn + "_"):
                    names.add(m.name, tn[len(pn) + 1:], "nested", min_conf(names, tc, mt))
            w = names.name(m.name)
            if w and m.type not in names.found:
                for v in TYPE_AFFIX:
                    vv = v.format(w)
                    p = crc_prefix(m.type, vv.encode())
                    if p in pm and names.add(m.type, pm[p] + vv, "nsrule", min_conf(names, m.name)):
                        break
            tn = names.name(m.type)
            if tn and m.name not in names.found and "::" in tn:
                last = tn.rsplit("::", 1)[1]
                for w in {last, last[1:], re.sub("Type$", "", last), re.sub("Type$", "", last[1:])}:
                    if w and names.add(m.name, w, "nsrule", min_conf(names, m.type)):
                        break
        added += len(names.found) - n0
        if len(names.found) == n0:
            return added


def min_conf(names, *hs):
    cs = [names.found[h][2] for h in hs if h in names.found]
    c = min(cs, key=lambda c: RANK.get(c, 0)) if cs else "high"
    return "high" if RANK.get(c, 0) >= 3 else c


# ---------------------------------------------------------------- vocabulary and guessing
ENGLISH = re.compile(r"\b(?:the|and|to|of|you|your|is|with|for|this|are|on|in|be|can|will|not)\b")


FOREIGN = re.compile(r"\b(?:der|die|das|und|nicht|mit|f\u00fcr|ist|ein|eine|les|des|et|pour|avec|vous|est|une|il|di|che|per|con|non|del|della|el|los|las|para|por|una|que|y|w|z|na|nie|si\u0119|jest)\b")


def build_vocab(names, strings, limit):
    """Words ranked: parts of known names, then XML/XPath identifiers, then English text words."""
    known, xml, eng, other, foreign = Counter(), Counter(), Counter(), Counter(), set()
    for n, _s, c, _nt in names.found.values():
        if RANK.get(c, 0) < 2:
            continue
        for part in re.split(r"[:_]+", n):
            for u in CAMEL_WORD.findall(part):
                known[u[:1].upper() + u[1:]] += 1
    for s in strings:
        for t in re.findall(r"<(\w+)|(\w+)=\"|/@?(\w+)", s):
            for x in t:
                if x:
                    for u in CAMEL_WORD.findall(x):
                        xml[u[:1].upper() + u[1:]] += 1
        if " " in s:
            ws = [w[:1].upper() + w[1:] for w in re.findall(r"\b[A-Za-z][a-z]{2,13}\b", s)]
            ne, nf = len(ENGLISH.findall(s)), len(FOREIGN.findall(s))
            if ne >= 2 and ne > nf:
                eng.update(ws)
            elif nf >= 1:
                foreign.update(ws)
            else:
                other.update(ws)
    for w in foreign:
        other.pop(w, None)
    def good(w):
        if len(w) == 1:
            return w.isupper() or w.isdigit()
        return bool(re.fullmatch(r"[A-Z][a-z]+|[A-Z]{2,3}|[0-9]{1,2}", w)) and wordlike(w)
    out, seen = [], set()
    for src, mincount in ((known, 1), (xml, 2), (eng, 3), (other, 3)):
        for w, c in src.most_common():
            if c >= mincount and w not in seen and good(w):
                seen.add(w)
                out.append(w)
    return out[:limit]


def guess_with_length(names, hints, vocab, top3):
    """1-3 word names of exactly the implied length (meet in the middle: suffix table keyed by
    (length, crc))."""
    todo = {h: ls for h, ls in hints.items() if ls and h not in names.found}
    if not todo:
        return 0
    words = [w.encode() for w in vocab]
    small = words[:top3]
    suffix = defaultdict(dict)   # length -> {crc: string}
    for w in words:
        suffix[len(w)].setdefault(zlib.crc32(w), w)
    for a in small:
        ca = zlib.crc32(a)
        for b in small:
            ab = a + b
            suffix[len(ab)].setdefault(zlib.crc32(b, ca), ab)
    hits = 0
    for h, ls in todo.items():
        found = None
        for n in sorted(ls):
            d = suffix.get(n)
            if d and h in d:
                found = d[h]
                break
            for a in words if n <= 24 else small:
                rest = n - len(a)
                d = suffix.get(rest)
                if not d:
                    continue
                q = h ^ shift(zlib.crc32(a), rest)
                s = d.get(q)
                if s is not None:
                    found = a + s
                    break
            if found:
                break
        if found and names.add(h, found.decode(), "guess3"):
            hits += 1
    return hits


def guess_siblings(names, layout, global_words, max_local=40):
    """Members named from words of their siblings, parent and member type names (plus a few global
    words): few candidates per type, so a 32-bit hit is a reasonable name."""
    hits = 0
    gw = global_words
    for tc, (_s, _a, ms) in layout.types.items():
        unk = {m.name for m in ms if m.name not in names.found}
        if not unk:
            continue
        local = Counter()
        src = [names.name(tc) or ""] + [names.name(m.name) or "" for m in ms] + \
              [names.name(m.type) or "" for m in ms]
        for n in src:
            for part in re.split(r"[:_]+", n.split("::")[-1]):
                for u in CAMEL_WORD.findall(part):
                    local[u[:1].upper() + u[1:]] += 1
        lw = [w for w, _c in local.most_common(max_local)]
        if not lw:
            continue
        # sibling-pattern swaps
        lw += [w for w in ("Min", "Max", "Is", "Has", "Use", "Nb", "Count", "Coef", "X", "Y", "Z",
                           "Start", "End", "Left", "Right", "In", "Out", "On", "Off", "Enable",
                           "Time", "Speed", "Distance", "Angle", "Height", "Factor", "Ratio",
                           "Delay", "Duration", "Radius", "Width", "Value", "List", "Index",
                           "1", "2", "3", "4", "0") if w not in lw]
        ws = [w.encode() for w in lw]
        ws3 = set(ws[:12])
        wset = ws + [w.encode() for w in gw if w not in local]
        for a in ws:
            ca = zlib.crc32(a)
            if ca in unk and names.add(ca, a.decode(), "sibling"):
                unk.discard(ca)
                hits += 1
            for b in wset:
                cb = zlib.crc32(b, ca)
                if cb in unk and names.add(cb, (a + b).decode(), "sibling"):
                    unk.discard(cb)
                    hits += 1
                if b in ws3:
                    for c in ws3:
                        cc = zlib.crc32(c, cb)
                        if cc in unk and names.add(cc, (a + b + c).decode(), "sibling"):
                            unk.discard(cc)
                            hits += 1
            if not unk:
                break
    return hits


SWAPS = [("Min", "Max"), ("Left", "Right"), ("Forehand", "Backhand"), ("Start", "End"), ("Begin", "End"),
         ("In", "Out"), ("First", "Second"), ("Volley", "Baseline"), ("Up", "Down"), ("Front", "Back"),
         ("Low", "High"), ("Near", "Far"), ("Short", "Long"), ("Inside", "Outside"), ("Enter", "Exit"),
         ("Men", "Women"), ("Male", "Female"), ("Easy", "Hard"), ("Easy", "Normal"), ("Hard", "VeryHard"),
         ("Good", "Bad"), ("Good", "Medium"), ("Win", "Lose"), ("Winner", "Loser"), ("Server", "Receiver"),
         ("Serve", "Return"), ("Attack", "Defense"), ("Player", "Opponent"), ("Home", "Away"),
         ("Open", "Close"), ("On", "Off"), ("Show", "Hide"), ("Enable", "Disable"), ("Width", "Height"),
         ("Horizontal", "Vertical"), ("Flat", "Slice"), ("Flat", "Topspin"), ("Slice", "Topspin"),
         ("Lob", "DropShot"), ("Smash", "Lob"), ("Finesse", "Powerful"), ("Clay", "Grass"), ("Grass", "Hard"),
         ("AllAround", "BaselineAttacker"), ("VolleyPlayer", "BaselineController"),
         ("AllAround", "VolleyPlayer"), ("X", "Y"), ("Y", "Z"), ("X", "Z")]


def guess_patterns(names):
    """Siblings of known member names: every digit run replaced by 0..16, and word swaps such as
    Min/Max, Left/Right, Forehand/Backhand.  About 50 candidates per known name."""
    tset = {h for h in names.members if h not in names.found}
    pairs = {}
    for a_, b_ in SWAPS:
        pairs.setdefault(a_, set()).add(b_)
        pairs.setdefault(b_, set()).add(a_)
    hits = 0
    for h in list(names.found):
        if h not in names.members:
            continue
        n = names.found[h][0]
        cands = set()
        for m in re.finditer(r"[0-9]+", n):
            for k in range(17):
                cands.add(n[:m.start()] + str(k) + n[m.end():])
        parts = CAMEL_WORD.findall(n)
        if "".join(parts) == n:
            for i, w in enumerate(parts):
                for v in pairs.get(w, ()):
                    cands.add("".join(parts[:i] + [v] + parts[i + 1:]))
        for c in cands:
            hc = X.crc(c)
            if hc in tset and names.add(hc, c, "pattern"):
                tset.discard(hc)
                hits += 1
    return hits


def guess_combo2(names, vocab, top):
    words = [w.encode() for w in vocab[:top]]
    tset = {h for h in names.targets if h not in names.found and (h in names.members or h in names.types)}
    hits = 0
    for a in words:
        ca = zlib.crc32(a)
        for b in words:
            h = zlib.crc32(b, ca)
            if h in tset and names.add(h, (a + b).decode(), "combo2"):
                tset.discard(h)
                hits += 1
    return hits, len(words) ** 2 * len(tset) / 2 ** 32


# ---------------------------------------------------------------- dictionary files
LINE = re.compile(r'^"?([0-9a-fA-F]{8})"?:\s*\{name:\s*"((?:[^"\\]|\\.)*)",\s*src:\s*([\w.-]+)'
                  r'(?:,\s*conf:\s*(\w+))?(?:,\s*note:\s*"((?:[^"\\]|\\.)*)")?\}')


def read_yaml_names(path):
    """Read data/gameplay/names.yaml: one flow mapping per line,
    '<hex>: {name: "...", src: <source>, conf: <confidence>[, note: "..."]}'."""
    out = {}
    with open(path, encoding="utf-8") as f:
        for line in f:
            m = LINE.match(line.strip())
            if m:
                h = int(m.group(1), 16)
                name = json.loads('"%s"' % m.group(2))
                note = json.loads('"%s"' % m.group(5)) if m.group(5) else None
                out[h] = (name, m.group(3), m.group(4) or "medium", note)
    return out


def write_yaml_names(path, entries, meta):
    with open(path, "w", encoding="utf-8") as o:
        o.write("# Top Spin 4 crc32 name dictionary (types, members, keys of the XBin data)\n")
        o.write("# generated by tools/ts4data/names.py; entries whose src is not one of the tool's rules\n")
        o.write("# (dict, string, token, nsrule, nested, seed, sibling, pattern, guess3, combo2) are kept on\n")
        o.write("# regeneration, so other agents can add names by hand with src: <agent or source>.\n")
        o.write("# crc32 is checked on load.  conf: certain > high > medium > low (see names.py).\n")
        for k, v in meta.items():
            o.write("# %s: %s\n" % (k, json.dumps(v, sort_keys=True)))
        o.write("names:\n")
        for h in sorted(entries):
            name, src, conf, note = entries[h]
            line = '  "%08x": {name: %s, src: %s, conf: %s' % (h, json.dumps(name), src, conf)
            if note:
                line += ", note: %s" % json.dumps(note)
            o.write(line + "}\n")


def load_merge(path):
    """{hash: (name, src, conf, note)} from JSON ({hex: name}, {hex: {name, src}},
    {hex: [name, conf]}, names.json) or names.yaml."""
    if path.endswith((".yaml", ".yml")):
        return read_yaml_names(path)
    d = json.load(open(path))
    if "names" in d and isinstance(d["names"], dict):
        d = d["names"]
    out = {}
    tag = os.path.splitext(os.path.basename(path))[0]
    for k, v in d.items():
        try:
            h = int(k, 16)
        except ValueError:
            continue
        if isinstance(v, str):
            out[h] = (v, "merged", "medium", tag)
        elif isinstance(v, list) and v and isinstance(v[0], str):
            out[h] = (v[0], "merged", v[1] if len(v) > 1 else "medium", tag)
        elif isinstance(v, dict) and "name" in v:
            src = v.get("src", "merged")
            out[h] = (v["name"], "merged", v.get("conf", CONF.get(src, "medium")), tag + ":" + src)
    return out


# ---------------------------------------------------------------- main
TOOL_SOURCES = set(CONF) | {"merged"}


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--layout", required=True)
    ap.add_argument("--strings", nargs="+", default=[], help="files or directories to take strings from")
    ap.add_argument("--xbin", nargs="*", default=[], help="XBin files whose CKey values are also targets")
    ap.add_argument("--merge", nargs="*", default=[], help="JSON or names.yaml dictionaries to merge")
    ap.add_argument("--vocab", type=int, default=9000, help="vocabulary size for the length-guided guesser")
    ap.add_argument("--top3", type=int, default=800, help="words used for 2+1 word length-guided guesses")
    ap.add_argument("--top", type=int, default=2500, help="words for unconstrained two-word guesses (0 = off)")
    ap.add_argument("--sibling-words", type=int, default=1200, help="global words combined with sibling words")
    ap.add_argument("--rounds", type=int, default=3)
    ap.add_argument("--out", required=True, help="JSON output (work/, all sources)")
    ap.add_argument("--strings-from", nargs="*", default=[], help="text files of strings (one per line)")
    ap.add_argument("--dump-strings", help="write the harvested strings here (one per line, work/ only)")
    ap.add_argument("--yaml", help="names.yaml to update (hand-added entries are kept)")
    a = ap.parse_args(argv)

    layout = X.Layout(open(a.layout, "rb").read())
    tgt, ttypes, tmembers = collect_targets(layout, a.xbin)
    names = Names(tgt, ttypes, tmembers)
    keep = {}
    if a.yaml and os.path.exists(a.yaml):
        for h, e in read_yaml_names(a.yaml).items():
            if e[1] not in TOOL_SOURCES and X.crc(e[0]) == h:
                keep[h] = e
    for h, e in keep.items():
        names.found[h] = e
    for n in X.TYPE_NAMES.values():
        names.add(X.crc(n), n, "string")
    for n in SEED_NAMES:
        names.add(X.crc(n), n, "seed")
    strs = set()
    for p in iter_files(a.strings):
        data = open(p, "rb").read()
        if len(data) > 0x24 and data[:8] == CRC_DICT_SIG:
            try:
                for h, n in X.read_crc_dictionary(data).items():
                    names.add(h, n, "dict")
            except ValueError:
                pass
        strs.update(strings_of(data))
    for p in a.strings_from:
        with open(p, encoding="utf-8", errors="replace") as f:
            strs.update(line.rstrip("\n") for line in f)
    if a.dump_strings:
        with open(a.dump_strings, "w", encoding="utf-8") as o:
            o.write("\n".join(sorted(x.replace("\n", " ") for x in strs)))
    for p in a.merge:
        for h, (n, src, conf, note) in load_merge(p).items():
            names.add(h, n, "merged", conf, note or src)
    for s in strs:
        names.add(X.crc(s), s, "string")
    toks = set()
    for s in strs:
        toks.update(tokens_of(s))
    good = {t for t in toks if wordlike(t)}
    for t in toks:
        if t in good or not (X.crc(t) in ttypes or X.crc(t) in tmembers):
            names.add(X.crc(t), t, "token")
    for t in good:
        for v in (t[:1].upper() + t[1:], "C" + t, t + "Type", "Is" + t):
            names.add(X.crc(v), v, "token")
    print("strings: %d names" % len(names.found), flush=True)

    st = Structure(layout)
    log = {"strings": len(names.found)}
    log["propagate0"] = propagate(names, st)
    votes = vote_prefixes(names, st)
    pm = prefix_map(names)
    log["prefix_states_voted"] = len(votes)
    log["prefix_states_unknown_text"] = sorted("%08x:%d" % (p, n) for p, n in votes.items() if p not in pm)[:50]
    est_combo = 0.0
    for r in range(a.rounds):
        vocab = build_vocab(names, strs, a.vocab)
        hints = st.length_hints(list(prefix_map(names)))
        g3 = guess_with_length(names, hints, vocab, a.top3)
        p1 = propagate(names, st)
        sb = guess_siblings(names, layout, vocab[:a.sibling_words]) + guess_patterns(names)
        p2 = propagate(names, st)
        log["round%d" % r] = dict(guess3=g3, sibling=sb, propagated=p1 + p2, total=len(names.found))
        print("round %d: %s" % (r, log["round%d" % r]), flush=True)
        if g3 + sb + p1 + p2 == 0:
            break
    if a.top:
        vocab = build_vocab(names, strs, a.top)
        c2, est_combo = guess_combo2(names, vocab, a.top)
        log["combo2"] = c2
        log["propagate_final"] = propagate(names, st)

    by_src = Counter(e[1] for e in names.found.values())
    by_conf = Counter(e[2] for e in names.found.values())
    cov = {"targets": len(tgt), "found": len(names.found),
           "types": [sum(h in names.found for h in ttypes), len(ttypes)],
           "members": [sum(h in names.found for h in tmembers), len(tmembers)]}
    meta = dict(cov, by_source=dict(by_src), by_confidence=dict(by_conf),
                combo2_expected_false_hits=round(est_combo, 1), log=log)
    out = {"_meta": meta,
           "names": {"%08x" % h: {"name": n, "src": s, "conf": c, **({"note": nt} if nt else {})}
                     for h, (n, s, c, nt) in sorted(names.found.items())}}
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w") as o:
        json.dump(out, o, indent=0)
    if a.yaml:
        ymeta = {k: meta[k] for k in ("targets", "found", "types", "members", "by_confidence",
                                      "combo2_expected_false_hits")}
        write_yaml_names(a.yaml, names.found, ymeta)
    print(json.dumps({k: meta[k] for k in ("targets", "found", "types", "members", "by_source",
                                           "by_confidence", "combo2_expected_false_hits")}))
    return 0


if __name__ == "__main__":
    sys.exit(main())
