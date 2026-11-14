#!/usr/bin/env python3
"""Extract every player / movement / AI / animation tunable of Top Spin 4 (Xbox 360) to one YAML file.

    python3 -I tools/ts4data/player_data.py --core work/disc/core_all [--out data/gameplay/player.yaml]

Inputs are Core.arc members already extracted by name hash (tools/ts4_arc.py --extract ...):
    334e7e0d  Settings.bin         gameplay settings tree; cfg = file 0x24 (shot-to-template.md s1)
    fa94f637  Expressions.bin      analyser graphs (analyser-graphs.md)
    70155255  AnimationsDB.bin     swing animation records (TakeList, 3,184 x 0x8C)
    136bf02a  AnimationsDBcrc.bin  CRC dictionary for the animation names
    c6d33a45  CommonCRCDictionnary.bin (optional, more names)
    85ff436e  swinganimation.bin   AnimationData root (type 0x3A60FEE2)
    798a36dd  PlayerSetup.bin      skeleton setup (bone hierarchy by name hash)
Only the Python standard library and tools/ts4_analyser.py (also stdlib) are used.

What is written (docs/gameplay/player-and-movement.md explains each block and gives code addresses):
  player_tuning     the PlayerTuning block PlayerCtx+0x2C = cfg+0x180 = Settings.bin file 0x1A4 (V: fn_886BE4E0),
                    named fields where code reads them, plus every word of the block decoded generically
  reach_tuning      the same block seen from the ReachEvaluator (E+8 = PlayerTuning+0xA0, I)
  ai_levels         cfg+0xF0: 9 play-style groups x 6 AI levels (VeryEasy..Expert), 0x5C-byte records (fn_886A0EC8)
  settings_blocks   other Settings sub-blocks used by player code (crowd, fatigue, rewards), generic decode
  graphs            the analyser graphs that turn stats/fatigue into movement and swing values (curve keys)
  animation_clips   the clip catalogue: name, frames, slot, tag, poly kind, EventRacket / Preparation phase and frame
  swing_animation   AnimationData root scalars and named lists
  player_setup      skeleton bones (name, parent)
Every block carries its source file sha256.
"""
import argparse
import hashlib
import json
import os
import re
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import ts4_analyser  # noqa: E402

SETTINGS, EXPRESSIONS, ANIMDB, ANIMDB_CRC, COMMON_CRC = "334e7e0d", "fa94f637", "70155255", "136bf02a", "c6d33a45"
SWINGANIM, PLAYERSETUP = "85ff436e", "798a36dd"
CFG = 0x24            # Settings.bin root typed struct (file offset)
PT = CFG + 0x180      # PlayerTuning = cfg+0x180 (fn_886BE4E0: addi r9,r11,0x180; stw r9,0x2C(ctx))
RT = PT + 0xA0        # ReachTuning view (fn_8869B178 reads four per-level arrays at T+0/0xC/0x18/0x24 == PT+0xA0..)
EVENT_RACKET, PREPARATION = 0x3B9AD22E, 0x7F6C2523

# Words worth naming that are not in the disc dictionaries (all verified crc32 preimages).
EXTRA_NAMES = [
    "VeryEasy", "Easy", "Normal", "Hard", "VeryHard", "Expert", "Human", "Left", "Right", "Both",
    "Baseline", "Volley", "Smash", "Unreachable", "Rush", "Jog", "Idle", "Good", "Medium", "Bad",
    "EventRacket", "Preparation", "EOP", "Timing", "Power", "Control", "MoveToNet", "PositionOnCourt",
    "SwingEffect", "SwingType", "Qualifier", "Flat", "TopSpin", "Slice", "Lob", "DropShot",
    "B_Head", "B_LeftHand", "B_RightHand", "B_Racket_Handle", "Serve", "Return", "Forehand", "Backhand",
    "Speed", "Stamina", "Reflex", "Mental", "Overall",
] + ts4_analyser.GRAPH_NAMES + ts4_analyser.PATH_NAMES

# ------------------------------------------------------------------------------------------- PlayerTuning map
# offset (relative to PlayerTuning) -> (name, kind, evidence). Kinds: f32, i32, u8x4, vec{n}, arr (12-byte {rel,count,cap}),
# zone {a,b,radius}, style (16 B), mode (2-D table + f32 +0xC + min distance +0x10).
PT_FIELDS = [
    (0x0A0, "racket_offset_lateral_a", "arr_f32", "fn_886A26E0 / fn_8869B178: per stroke level (AnimIface+0x460, -1 -> 2)"),
    (0x0AC, "racket_offset_lateral_b", "arr_f32", "fn_886A26E0: swapped and negated for left-handers"),
    (0x0B8, "racket_offset_c", "arr_f32", "fn_8869B178 T+0x18 (per stroke level)"),
    (0x0C4, "racket_offset_d", "arr_f32", "fn_8869B178 T+0x24 (per stroke level)"),
    (0x0E0, "low_split_height_out_zone_cm", "f32", "gp2 s5 T+0x40: y below -> low (Baseline)"),
    (0x0E4, "low_split_height_in_zone_cm", "f32", "gp2 s5 T+0x44: y below -> Volley"),
    (0x0E8, "smash_band_lo_in_zone_cm", "f32", "gp2 s5 T+0x48"),
    (0x0EC, "smash_band_hi_in_zone_cm", "f32", "gp2 s5 T+0x4C"),
    (0x0F0, "smash_band_lo_out_zone_cm", "f32", "gp2 s5 T+0x50"),
    (0x0F4, "smash_band_hi_out_zone_cm", "f32", "gp2 s5 T+0x54"),
    (0x158, "side_offset_threshold_cm", "f32", "fn_8868BD80 T+0xB8"),
    (0x160, "volley_lookahead_table", "arr", "fn_8869B178 T+0xC0"),
    (0x16C, "volley_cap_table", "arr", "fn_8868B4E8 post pass T+0xCC"),
    (0x178, "volley_zone_abs_x_cm", "f32", "fn_8869B178 T+0xD8"),
    (0x14C, "side_select_curve", "arr", "fn_8869AB70 (+0x14C)"),
    (0x17C, "preparation_table", "table2d", "fn_8868B4E8 / fn_886887C0: (|angle|, ball value) -> turn/prep ticks"),
    (0x188, "side_offset_weight_curve", "arr", "fn_88689508 query (curve +0x188)"),
    (0x194, "reach_radius_cm", "f32", "fn_8868B4E8 T+0xF4 (PlayerState+0xBD2 clear)"),
    (0x198, "volley_box_dead_zone_x_cm", "f32", "fn_8868B4E8 T+0xF8"),
    (0x19C, "volley_box_dead_zone_z_cm", "f32", "fn_8868B4E8 T+0xFC"),
    (0x1A0, "reach_radius_alt_cm", "f32", "fn_8868B4E8 T+0x100 (PlayerState+0xBD2 set)"),
    (0x1A4, "prep_ticks", "f32", "fn_8868B4E8 T+0x104"),
    (0x1A8, "prep_ticks_volley", "f32", "fn_8868B4E8 T+0x108"),
    (0x1AC, "prep_ticks_alt_and_anim_lead", "f32", "fn_8868B4E8 T+0x10C; fn_88688948 adds it to the clip busy time"),
    (0x1BC, "selection_curve_1bc", "arr", "gp2 PlayerTuning curve list"),
    (0x1C8, "selection_curve_1c8", "arr", "gp2 PlayerTuning curve list"),
    (0x1D4, "selection_curve_1d4", "arr", "gp2 PlayerTuning curve list"),
    (0x1E0, "input_notation_angle_curve", "arr", "fn_8868ADC0: w = curve(|angle error|)"),
    (0x1F8, "style_default", "style", "fn_886A3440 / AI commit profile; fn_88699FC0 -> state 3"),
    (0x208, "style_208", "style", "fn_886A9E48 tried second (volley allowed)"),
    (0x218, "style_218", "style", "fn_886A9E48 first when PlayerState+0xBD5"),
    (0x228, "style_fallback", "style", "fallback; +8 (=+0x230) replaced by the AI level skill float (fn_8869AEF8)"),
    (0x238, "style_alt_a", "style", "states 10/11 (fn_886A9DF0); fn_88699FC0 -> 0xB"),
    (0x248, "style_alt_b", "style", "states 10/11 (fn_886A9DF0); fn_88699FC0 -> 0xB"),
    (0x26C, "float_26c", "f32", "gp2 PlayerTuning float"),
    (0x270, "mode_rush", "mode", "fn_88688948 [Rush] -> state 20"),
    (0x284, "mode_jogjog_prepared", "mode", "fn_88688948 [JogJogPrepared] -> state 21"),
    (0x298, "mode_jog_prepared", "mode", "fn_88688948 [JogPrepared] -> state 22"),
    (0x2AC, "zone_swing_ready", "zone", "state 3 -> 4 (fn_88687AC0)"),
    (0x2B8, "zone_approach", "zone", "state 5 -> 6 (interrupt)"),
    (0x2F4, "zone_regime", "zone", "states 20-22 (fn_88678708)"),
    (0x300, "zone_alt", "zone", "states 10/11 -> 12"),
    (0x31C, "speed_table_31c", "speed", "fn_886A2330 (record {table2d, f32 +0xC}); same evaluator as mode tables (I)"),
    (0x32C, "speed_table_32c", "speed", "no direct reader found (I)"),
    (0x33C, "speed_table_33c", "speed", "fn_88676718 (I)"),
    (0x34C, "speed_table_approach_near", "speed", "state 6 enter fn_886AA420: override = fn_886887C0(+0x34C, busy + prep_ticks)"),
    (0x35C, "speed_table_35c", "speed", "8 readers incl. fn_886A9BF0 (I)"),
    (0x36C, "speed_table_36c", "speed", "16 readers incl. fn_88698638 (I)"),
    (0x37C, "speed_table_37c", "speed", "fn_8867A5B4.. (I)"),
    (0x3B0, "jog_ramp_step_table", "table2d", "fn_88688678: step = table2d(distance, fn_8866BFE8 slack), recomputed every period"),
    (0x3BC, "reach_anim_height_min_cm", "f32", "fn_886A26E0 gate"),
    (0x3C0, "reach_anim_height_max_cm", "f32", "fn_886A26E0 gate"),
    (0x3C4, "contact_window_lo_ticks_bd2", "f32", "fn_886A26E0 AnimIface+0x3D0 when PlayerState+0xBD2"),
    (0x3C8, "contact_window_hi_ticks_bd2", "f32", "fn_886A26E0 AnimIface+0x3D4 when PlayerState+0xBD2"),
    (0x3CC, "contact_window_lo_ticks", "f32", "fn_886A26E0 AnimIface+0x3D0"),
    (0x3D0, "contact_window_hi_ticks", "f32", "fn_886A26E0 AnimIface+0x3D4"),
    (0x3DC, "contact_position_tolerance_a_cm", "f32", "fn_886A26E0 AnimIface+0x3D8"),
    (0x3E0, "contact_position_tolerance_b_cm", "f32", "fn_886A26E0 AnimIface+0x3DC"),
    (0x3EC, "jog_ramp_period_ticks", "i32", "fn_88688678 period"),
    (0x3F4, "reach_anim_min_distance_cm", "f32", "fn_886A26E0 squared xz compare"),
    (0x630, "rush_guard", "f32", "fn_88699FC0: Rush tried only if (ctx+0x6C)->+0x158 > this"),
]
PT_SIZE = 0x660


class Bin:
    def __init__(self, data):
        self.b = data

    def u32(self, o):
        return struct.unpack_from(">I", self.b, o)[0]

    def s32(self, o):
        return struct.unpack_from(">i", self.b, o)[0]

    def f32(self, o):
        return struct.unpack_from(">f", self.b, o)[0]

    def u16(self, o):
        return struct.unpack_from(">H", self.b, o)[0]

    def desc(self, o, stride=4, maxn=4096):
        """12-byte {rel,count,cap} descriptor -> (abs, count) or None."""
        if o < 0 or o + 12 > len(self.b):
            return None
        rel, n, cap = struct.unpack_from(">iII", self.b, o)
        if rel == -1 or n == 0 or n != cap or n > maxn:
            return None
        a = o + rel
        if a < 0 or a + n * stride > len(self.b):
            return None
        return a, n


def r6(x):
    return float("%.6g" % x)


def sha256(data):
    return hashlib.sha256(data).hexdigest()


# ------------------------------------------------------------------------------------------- names

def build_names(core_dir, dll=None):
    names = {}
    for key in (ANIMDB_CRC, COMMON_CRC):
        p = os.path.join(core_dir, key + ".bin")
        if os.path.exists(p):
            names.update(read_crc_dictionary(open(p, "rb").read()))
    for s in EXTRA_NAMES:
        names.setdefault(zlib.crc32(s.encode()), s)
    if dll and os.path.exists(dll):
        # Only whole identifier strings from the executable; short ones collide too easily.
        for m in re.finditer(rb"[A-Za-z_][A-Za-z0-9_]{5,60}", open(dll, "rb").read()):
            names.setdefault(zlib.crc32(m.group()), m.group().decode())
    return names


def read_crc_dictionary(data):
    b = Bin(data)
    a, n = b.desc(0x14, 8, 1 << 20) or (0, 0)
    out = {}
    for i in range(n):
        p = a + 8 * i
        rel, key = struct.unpack_from(">iI", data, p)
        end = data.index(b"\0", p + rel)
        s = data[p + rel:end]
        if zlib.crc32(s) == key:
            out[key] = s.decode("latin-1")
    return out


def nm(names, h):
    return names.get(h, "%08x" % h)


# ------------------------------------------------------------------------------------------- generic values

def read_curve16(b, a, n):
    return [[r6(b.f32(a + 16 * i + k)) for k in (0, 4, 8, 12)] for i in range(n)]


def looks_table2d(b, a, n):
    prev = -1e30
    for i in range(n):
        r = a + 16 * i
        if not b.desc(r, 16, 64):
            return False
        k = b.f32(r + 12)
        if not (k >= prev) or abs(k) > 1e7:
            return False
        prev = k
    return True


def looks_curve16(b, a, n):
    for i in range(n):
        x0, x1 = b.f32(a + 16 * i), b.f32(a + 16 * i + 4)
        if not (x0 <= x1) or abs(x0) > 1e7 or abs(x1) > 1e7:
            return False
        if i and b.f32(a + 16 * (i - 1)) > x0:
            return False
    return True


def decode_array(b, o, names, raw=False):
    """Generic decode of the array a {rel,count,cap} descriptor at o points to."""
    d = b.desc(o, 4)
    if not d:
        return None
    a, n = d
    if raw:
        return {"count": n, "first_words": ["%08x" % b.u32(a + 4 * i) for i in range(min(n * 2, 24))]}
    if b.desc(o, 16) and looks_table2d(b, a, n):
        rows = []
        for i in range(n):
            r = a + 16 * i
            ca, cn = b.desc(r, 16, 64)
            rows.append({"key": r6(b.f32(r + 12)), "curve16": read_curve16(b, ca, cn)})
        return {"table2d": rows}
    if b.desc(o, 16) and looks_curve16(b, a, n):
        return {"curve16": read_curve16(b, a, n)}
    vals = [b.f32(a + 4 * i) for i in range(n)]
    if all(v == v and abs(v) < 1e7 and (v == 0 or abs(v) > 1e-6) for v in vals):
        return {"f32": [r6(v) for v in vals]}
    return {"u32": ["%08x" % b.u32(a + 4 * i) for i in range(n)], "names": [names.get(b.u32(a + 4 * i)) for i in range(n)]}


def word_view(b, o, names):
    w = b.u32(o)
    f = b.f32(o)
    if w in names:
        return names[w]
    if w == 0:
        return 0
    if w < 0x10000 or w >= 0xFFFF0000:
        return b.s32(o)
    if f == f and 1e-6 < abs(f) < 1e7:
        return r6(f)
    return "0x%08x" % w


def generic_block(b, base, size, names):
    """Decode every word of a block: arrays at their descriptor offset, otherwise int/float/name by value."""
    out = {}
    o = 0
    while o < size:
        if b.desc(base + o, 4):
            out["+0x%03x" % o] = decode_array(b, base + o, names)
            o += 12
            continue
        out["+0x%03x" % o] = word_view(b, base + o, names)
        o += 4
    return out


# ------------------------------------------------------------------------------------------- PlayerTuning

def decode_field(b, a, kind, names):
    if kind == "f32":
        return r6(b.f32(a))
    if kind == "i32":
        return b.s32(a)
    if kind in ("arr", "arr_f32", "table2d"):
        return decode_array(b, a, names)
    if kind == "zone":
        return {"a": r6(b.f32(a)), "b": r6(b.f32(a + 4)), "radius_cm": r6(b.f32(a + 8))}
    if kind == "style":
        return {"flags": list(b.b[a:a + 4]), "volley_allowed": b.b[a + 1], "must_equal_is_smash": b.b[a + 2],
                "speed_limit_mps": r6(b.f32(a + 8)), "volley_speed_limit_mps": r6(b.f32(a + 12))}
    if kind == "speed":
        return {"speed_table": decode_array(b, a, names), "f0c": r6(b.f32(a + 12))}
    if kind == "mode":
        return {"validity_table": decode_array(b, a, names), "f0c": r6(b.f32(a + 12)),
                "min_distance_cm": r6(b.f32(a + 16))}
    raise ValueError(kind)


def player_tuning(sb, names):
    named = {}
    for off, name, kind, ev in sorted(PT_FIELDS):
        named[name] = {"offset": "+0x%03x" % off, "value": decode_field(sb, PT + off, kind, names), "read_by": ev}
    return {
        "source": "Settings.bin file 0x%X (cfg+0x180); PlayerCtx+0x2C" % PT,
        "named": named,
        "all_words": generic_block(sb, PT, PT_SIZE, names),
    }


def ai_levels(sb, names, graph_names):
    """cfg+0xF0: groups {rel,count,cap,key}; records 0x5C: 5 arrays, +0x3C level, +0x40..+0x54 graphs, +0x58 skill."""
    d = sb.desc(CFG + 0xF0, 16)
    out = []
    if not d:
        return out
    a, n = d
    for i in range(n):
        g = a + 16 * i
        ra, rn = sb.desc(g, 0x5C)
        recs = []
        for j in range(rn):
            r = ra + 0x5C * j
            arrays = {}
            for k, o in enumerate((0x00, 0x0C, 0x18, 0x24, 0x30)):
                arrays["list_%02x" % o] = decode_array(sb, r + o, names, raw=True)  # element layout U
            graphs = {}
            for o, role in ((0x40, "graph_40"), (0x44, "reaction_graph(brain+0x1E0)"), (0x48, "ground_score_graph(brain+0x158)"),
                            (0x4C, "volley_score_graph(brain+0x19C)"), (0x50, "graph_50(brain+0x224)"), (0x54, "graph_54")):
                h = sb.u32(r + o)
                graphs[role] = {"hash": "%08x" % h, "name": graph_names.get(h) or names.get(h),
                                "in_expressions": h in graph_names or h in GRAPH_HASHES}
            recs.append({"level": nm(names, sb.u32(r + 0x3C)), "skill_speed_limit_mps": r6(sb.f32(r + 0x58)),
                         "graphs": graphs, "lists": arrays})
        out.append({"style_key": nm(names, sb.u32(g + 12)), "records": recs})
    return out


GRAPH_HASHES = set()

SETTINGS_BLOCKS = [
    (0x824, 0x0C, "crowd_a", "fn_8868E968 (crowd reaction, gp1 s6)"),
    (0x830, 0x0C, "crowd_b", "fn_8868EAFC"),
    (0x83C, 0x80, "crowd_c", "fn_8868E3C0"),
    (0x8F8, 0x34, "fatigue", "fn_886BC0CC (fatigue object init)"),
    (0x92C, 0x84, "block_92c", "fn_8865AEE4, fn_88663080"),
    (0xAB0, 0x20, "block_ab0", "fn_8865E66C"),
    (0xAD0, 0x40, "block_ad0", "fn_8869D5F0"),
    (0xB10, 0x0C, "rewards_a", "fn_88673554, fn_886866CC (reward rules, gp1 s4)"),
    (0xB1C, 0x118, "rewards_b", "fn_88686784"),
    (0xC34, 0x40, "reward_points", "fn_8865B770, fn_886BC1C8"),
]


def settings_blocks(sb, names):
    out = {}
    for off, size, name, ev in SETTINGS_BLOCKS:
        out[name] = {"cfg_offset": "+0x%03x" % off, "file_offset": "0x%X" % (CFG + off), "read_by": ev,
                     "words": generic_block(sb, CFG + off, size, names)}
    return out


# ------------------------------------------------------------------------------------------- graphs

PLAYER_GRAPHS = ["DefaultAttributes", 0x075A2137, "RushSpeedCoef", "SwingSpeedCoef", "VolleySpeedCoef",
                 "FatigueIngame", "FatigueConst", 0x80CE1A10, 0x8ADD300F, "Vivacity", "BaselineTimingAbility",
                 "VolleyTimingAbility", 0x39CFDEBA, "ShotDifficulty", "InputFiltering"]


def graphs_block(expr, names, extra_hashes):
    graphs = ts4_analyser.parse_expressions(expr)
    for g in graphs:
        GRAPH_HASHES.add(g.name)
    gn = dict(ts4_analyser.known_names())
    gn.update({0x8C9B26E0: "DefaultAttributes"})
    want = []
    for w in PLAYER_GRAPHS + sorted(extra_hashes):
        want.append(zlib.crc32(w.encode()) if isinstance(w, str) else w)
    out = []
    seen = set()
    for h in want:
        for idx, g in enumerate(graphs):
            if g.name == h and (h, idx) not in seen:
                seen.add((h, idx))
                j = g.to_json(gn)
                for node in j.get("nodes", []):
                    if "keys" in node:  # {x0, x1, y0, slope, +0x10 word = y1 as f32 bits} (analyser-graphs.md s4)
                        node["keys"] = [[r6(k[0]), r6(k[1]), r6(k[2]), r6(k[3]),
                                         r6(ts4_analyser.bits_to_f32(k[4]))] for k in node["keys"]]
                        node["key_format"] = "x0, x1, y0, slope(+0xC), y1(+0x10)"
                out.append({"index": idx, "name_hash": "%08x" % h, "name": gn.get(h), "graph": j})
    return out, gn


# ------------------------------------------------------------------------------------------- animation

POLY = {0xA0B2A282: "clip", 0x2DB2D90F: "set9_additive", 0xC4BAA666: "variants5", 0x8361F2CA: "blend2"}


def animation_clips(db, names):
    b = Bin(db)
    a, n = b.desc(0x14 + 0x50, 0x8C, 100000)
    out = []
    for i in range(n):
        r = a + 0x8C * i
        frames = b.f32(r + 0x14)
        anns = []
        d = b.desc(r + 0x64, 0x10)
        if d:
            for j in range(d[1]):
                p = d[0] + 0x10 * j
                anns.append([nm(names, b.u32(p)), r6(b.f32(p + 4))])
        segs = []
        d = b.desc(r + 0x70, 0x28)
        if d:
            for j in range(d[1]):
                p = d[0] + 0x28 * j
                segs.append([nm(names, b.u32(p + 0x0C)), r6(b.f32(p + 0x10)), r6(b.f32(p + 0x14))])
        slot = b.u16(r + 0x0C)
        contact = next((t for k, t in anns if k == "EventRacket"), None)
        prep = next((t for k, t in anns if k == "Preparation"), None)
        rid = b.u32(r + 0x84)
        out.append({
            "i": i, "name": names.get(rid, "%08x" % rid), "id": "%08x" % rid, "frames": r6(frames),
            "seconds": r6(frames / 60.0), "slot": None if slot == 0xFFFF else slot, "tag": "%08x" % b.u32(r + 0x1C),
            "f18": r6(b.f32(r + 0x18)), "kind": POLY.get(b.u32(r + 0x60), "%08x" % b.u32(r + 0x60)),
            "contact_phase": contact, "contact_frame": None if contact is None else r6(contact * frames),
            "preparation_phase": prep, "preparation_frame": None if prep is None else r6(prep * frames),
            "annotations": anns, "segments": segs,
        })
    return out


def clip_summary(clips):
    fam = {}
    for c in clips:
        parts = c["name"].split("_")
        key = "_".join(parts[:2]) if parts and parts[0] == "Swing" else parts[0]
        fam.setdefault(key, 0)
        fam[key] += 1
    with_contact = sum(1 for c in clips if c["contact_phase"] is not None)
    return {"records": len(clips), "with_event_racket": with_contact,
            "families": dict(sorted(fam.items(), key=lambda kv: -kv[1]))}


def swing_animation(data, names):
    b = Bin(data)
    out = {"root_words": generic_block(b, 0x14, 0x2E0, names)}
    return out


def player_setup(data, names):
    """PlayerSetup.bin root: {rel,count,cap} of 0x10-byte bones {name, parent name, index, -1}."""
    b = Bin(data)
    d = b.desc(0x14, 0x10)
    bones = []
    if d:
        a, n = d
        for i in range(n):
            p = a + 0x10 * i
            bones.append([nm(names, b.u32(p)), nm(names, b.u32(p + 4)), b.s32(p + 8)])
    return {"bones": bones}


# ------------------------------------------------------------------------------------------- YAML

def _scalar(v):
    if v is None:
        return "null"
    if isinstance(v, bool):
        return "true" if v else "false"
    if isinstance(v, (int, float)):
        return repr(v) if isinstance(v, float) and v != int(v) or isinstance(v, int) else repr(float(v))
    s = str(v)
    if s == "" or re.search(r"[:#\[\]{},&*!|>'\"%@`]|^[-?\s]|\s$", s) or s.lower() in ("null", "true", "false", "yes", "no"):
        return json.dumps(s)
    return s


def _flow(v):
    if isinstance(v, list):
        return "[" + ", ".join(_flow(x) for x in v) + "]"
    if isinstance(v, dict):
        return "{" + ", ".join("%s: %s" % (_scalar(k), _flow(x)) for k, x in v.items()) + "}"
    return _scalar(v)


def _simple(v):
    return not isinstance(v, (list, dict)) or (isinstance(v, list) and all(not isinstance(x, dict) for x in v)
                                               and len(_flow(v)) < 160)


def to_yaml(v, ind=0):
    pad = "  " * ind
    lines = []
    if isinstance(v, dict):
        for k, x in v.items():
            if _simple(x) or (isinstance(x, dict) and not x) or (isinstance(x, dict) and len(_flow(x)) < 120
                                                                  and all(_simple(y) for y in x.values())):
                lines.append("%s%s: %s" % (pad, _scalar(k), _flow(x)))
            else:
                lines.append("%s%s:" % (pad, _scalar(k)))
                lines.extend(to_yaml(x, ind + 1))
    elif isinstance(v, list):
        for x in v:
            if _simple(x) or (isinstance(x, dict) and len(_flow(x)) < 160 and all(_simple(y) for y in x.values())):
                lines.append("%s- %s" % (pad, _flow(x)))
            else:
                sub = to_yaml(x, ind + 1)
                lines.append("%s- %s" % (pad, sub[0].lstrip()))
                lines.extend(sub[1:])
    else:
        lines.append(pad + _scalar(v))
    return lines


# ------------------------------------------------------------------------------------------- main

def load(core, key, required=True):
    p = os.path.join(core, key + ".bin")
    if not os.path.exists(p):
        if required:
            sys.exit("missing %s (extract Core.arc member %s first)" % (p, key))
        return None
    return open(p, "rb").read()


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--core", default="work/disc/core_all", help="folder with extracted Core.arc members (<hash>.bin)")
    ap.add_argument("--dll", default="orig/54540859/Swing_DLL.dll", help="optional, adds identifier names")
    ap.add_argument("--out", default="data/gameplay/player.yaml")
    ap.add_argument("--clips-out", default="data/gameplay/animation_clips.yaml",
                    help="the clip catalogue is large; written to its own file")
    a = ap.parse_args(argv)

    settings = load(a.core, SETTINGS)
    expr = load(a.core, EXPRESSIONS)
    db = load(a.core, ANIMDB)
    swing = load(a.core, SWINGANIM, False)
    setup = load(a.core, PLAYERSETUP, False)
    names = build_names(a.core, a.dll)
    sb = Bin(settings)

    sources = {"Settings.bin (334e7e0d)": sha256(settings), "Expressions.bin (fa94f637)": sha256(expr),
               "AnimationsDB.bin (70155255)": sha256(db)}
    for key, label in ((ANIMDB_CRC, "AnimationsDBcrc.bin (136bf02a)"), (COMMON_CRC, "CommonCRCDictionnary.bin (c6d33a45)")):
        d = load(a.core, key, False)
        if d:
            sources[label] = sha256(d)
    if swing:
        sources["swinganimation.bin (85ff436e)"] = sha256(swing)
    if setup:
        sources["PlayerSetup.bin (798a36dd)"] = sha256(setup)

    # graphs first: fills GRAPH_HASHES used by ai_levels
    graph_list = ts4_analyser.parse_expressions(expr)
    for g in graph_list:
        GRAPH_HASHES.add(g.name)
    gnames = dict(ts4_analyser.known_names())
    gnames[0x8C9B26E0] = "DefaultAttributes"
    levels = ai_levels(sb, names, gnames)
    ai_graph_hashes = set()
    for grp in levels:
        for rec in grp["records"]:
            for gr in rec["graphs"].values():
                if gr["in_expressions"]:
                    ai_graph_hashes.add(int(gr["hash"], 16))
    graphs, _ = graphs_block(expr, names, ai_graph_hashes)

    doc = {
        "generated_by": "python3 -I tools/ts4data/player_data.py --core %s" % a.core,
        "sources_sha256": sources,
        "notes": "Field roles and code addresses: docs/gameplay/player-and-movement.md. Units: cm, 60 Hz ticks, m/s.",
        "player_tuning": player_tuning(sb, names),
        "ai_levels": levels,
        "settings_blocks": settings_blocks(sb, names),
        "graphs": graphs,
    }
    clips = animation_clips(db, names)
    doc["animation_clip_summary"] = clip_summary(clips)
    if swing:
        doc["swing_animation"] = swing_animation(swing, names)
    if setup:
        doc["player_setup"] = player_setup(setup, names)

    os.makedirs(os.path.dirname(a.out) or ".", exist_ok=True)
    hdr = "# Top Spin 4 player / movement / AI tunables.\n# Generated by: %s\n# Sources (sha256): %s\n" % (
        doc["generated_by"], ", ".join("%s %s" % kv for kv in sources.items()))
    with open(a.out, "w") as f:
        f.write(hdr + "\n".join(to_yaml(doc)) + "\n")
    chdr = "# Top Spin 4 swing animation clip catalogue (AnimationsDB.bin TakeList).\n# Generated by: %s\n" \
           "# Sources (sha256): AnimationsDB.bin %s, AnimationsDBcrc.bin %s\n" \
           "# contact_phase = EventRacket annotation (normalised clip phase), contact_frame = phase * frames.\n" % (
               doc["generated_by"], sources["AnimationsDB.bin (70155255)"], sources.get("AnimationsDBcrc.bin (136bf02a)"))
    with open(a.clips_out, "w") as f:
        f.write(chdr + "\n".join(to_yaml({"clips": clips})) + "\n")
    print("wrote", a.out, os.path.getsize(a.out), "bytes;", a.clips_out, os.path.getsize(a.clips_out), "bytes;",
          len(clips), "clips;", len(graphs), "graphs;", sum(len(g["records"]) for g in levels), "AI records")
    return 0


if __name__ == "__main__":
    sys.exit(main())
