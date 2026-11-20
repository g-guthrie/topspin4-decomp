#!/usr/bin/env python3
"""Parser for the FMOD Ex event project files (.fev, "FEV1", version 0x003E0000) used by Top Spin 4 (Xbox 360).

The layout was measured on the retail disc (all 19 Amsterdam .fev files and the other venue/Core banks parse to
the end of the event and sound-definition tables).  All integers are little-endian even though the console is
big-endian; strings are a u32 length (including the terminating NUL) followed by the bytes.

  "FEV1"  u32 version (0x003E0000)  u32 a  u32 b  str project
  u32 nbanks      { u32 flags  u32 maxstreams  u8[8] hash  str bank_name }      bank_name -> <bank>.fsb
  category tree   { str name  f32 volume  f32 pitch  u32 ?  u32 ?  u32 nchildren  children... }   (recursive)
  u32 ngroups     group { str name  props  u32 nsubgroups  u32 nevents  subgroups...  events... } (recursive)
  props           u32 n { str name  u32 type (0 int, 1 float, 2 string)  value }
  event           u32 type (0x10 simple, 0x08 complex)  str name  u8[16] guid  0x84-byte base block
     base block   +0x00 f32 volume  +0x04 f32 pitch  +0x08 f32 pitch_rand  +0x0C f32 volume_rand  +0x10 u32 priority
                  +0x14 u32 max_playbacks  +0x18 u32 (10000)  +0x1C u32 mode (stored big-endian, 0x08 = 2D)
                  +0x20 f32 min_distance  +0x24 f32 max_distance  (rest not interpreted)
     simple       u32 1  instance  u32 1  str category
     complex      u32 nlayers { u16 flags  s16 priority  s16 param_index  u16 ninstances  u16 nenvelopes
                                instances...  envelopes... }
                  envelope { s32 -1  str ""  u32  u32 dsp_type  u32  u32 npoints {f32 x  f32 y  u32 shape}  u32  u32 }
                  u32 nparams { str name  f32 velocity  f32 min  f32 max  u32 flags  f32 seek_speed  u32 k }
                  [0..2 u32 of unknown purpose]  props  u32 1  str category
  instance (58 B) u16 sounddef_index  f32 start  f32 length  48 bytes (tail 1.0,-1,-1,2,2 complex / 1.0,0,0,2,2 simple)
  u32 ntemplates  { 0x44 bytes: +0 u32 playmode  +4 f32 spawn_min  +8 f32 spawn_max  +0xC u32 max_spawned
                    +0x10 f32 volume ... }
  u32 nsounddefs  { str name  u32 template_index  u32 nwaves
                    wave { u32 type  u32 weight  type 0: str wav_name  str bank  u32 index_in_bank  u32 length_ms
                                                 other: 8 bytes (oscillator / don't-play entries) } }
  u32 nreverbs (0 on this disc)  then a "comp"/"sett" trailer (not parsed)

The tail of a complex event has 0, 1 or 2 extra u32 before its property list; the parser tries the observed skips
(1, 0, 2) and accepts the one that ends in "u32 1, <known category>".  This is a heuristic; it is exact on every
.fev of the disc.  Field names follow FMOD Designer vocabulary; meanings marked "?" are not confirmed.

Standard library only.  Reverse-engineered from the disc bytes; the open-source xoreos reader (an older FEV
revision without GUIDs or complex events) was consulted for vocabulary only, no code was taken from it.
"""
import struct
import sys

MAGIC = b"FEV1"
EVENT_SIMPLE = 0x10
EVENT_COMPLEX = 0x08
TEMPLATE_SIZE = 0x44
BASE_BLOCK = 0x84
INSTANCE_TAIL = 48


class FevError(ValueError):
    pass


class _R:
    def __init__(self, data, pos=0):
        self.d = data
        self.p = pos

    def _take(self, fmt, size):
        if self.p + size > len(self.d):
            raise FevError("read past end at 0x%x" % self.p)
        v = struct.unpack_from(fmt, self.d, self.p)[0]
        self.p += size
        return v

    def u32(self):
        return self._take("<I", 4)

    def s32(self):
        return self._take("<i", 4)

    def u16(self):
        return self._take("<H", 2)

    def s16(self):
        return self._take("<h", 2)

    def f32(self):
        return self._take("<f", 4)

    def raw(self, n):
        if self.p + n > len(self.d):
            raise FevError("read past end at 0x%x" % self.p)
        b = self.d[self.p:self.p + n]
        self.p += n
        return b

    def str(self):
        n = self.u32()
        if n > 4096:
            raise FevError("implausible string length %d at 0x%x" % (n, self.p - 4))
        return self.raw(n).rstrip(b"\0").decode("latin-1")


def _props(r):
    out = {}
    for _ in range(r.u32()):
        k = r.str()
        t = r.u32()
        if t == 0:
            out[k] = r.s32()
        elif t == 1:
            out[k] = round(r.f32(), 6)
        elif t == 2:
            out[k] = r.str()
        else:
            raise FevError("unknown property type %d" % t)
    return out


def _instance(r):
    sd = r.u16()
    start = r.f32()
    length = r.f32()
    r.raw(INSTANCE_TAIL)
    return {"sounddef": sd, "start": round(start, 6), "length": round(length, 6)}


def _base(b):
    vol, pitch, prand, vrand, prio, maxpb, _k = struct.unpack_from("<5fII", b, 0)
    prio = struct.unpack_from("<I", b, 0x10)[0]
    mode = struct.unpack_from(">I", b, 0x1C)[0]
    mind, maxd = struct.unpack_from("<ff", b, 0x20)
    return {"volume": round(vol, 6), "pitch": round(pitch, 6), "pitch_randomization": round(prand, 6),
            "volume_randomization": round(vrand, 6), "priority": prio, "max_playbacks": maxpb,
            "mode": mode, "is_2d": bool(mode & 0x08000000) or bool(mode & 0x08),
            "min_distance": round(mind, 4), "max_distance": round(maxd, 4)}


class FevFile:
    """Parsed .fev. Attributes: version, project, banks [{name, flags, maxstreams}], categories [names],
    events [{path, type, guid, base, layers, params, category, user_properties}], templates, sounddefs."""

    def __init__(self, data):
        if data[:4] != MAGIC:
            raise FevError("not an FEV1 file")
        self.categories = []
        r = _R(data, 4)
        self.version = r.u32()
        r.u32()
        r.u32()
        self.project = r.str()
        self.banks = []
        for _ in range(r.u32()):
            flags = r.u32()
            ms = r.u32()
            r.raw(8)
            self.banks.append({"name": r.str(), "flags": flags, "maxstreams": ms})
        self._category(r)
        self.events = []
        for _ in range(r.u32()):
            self._group(r, "")
        self.templates = []
        for _ in range(r.u32()):
            b = r.raw(TEMPLATE_SIZE)
            pm, smin, smax, maxsp, vol = struct.unpack_from("<IffIf", b, 0)
            self.templates.append({"playmode": pm, "spawn_min": round(smin, 6), "spawn_max": round(smax, 6),
                                   "max_spawned": maxsp, "volume": round(vol, 6)})
        self.sounddefs = []
        for _ in range(r.u32()):
            name = r.str()
            ti = r.u32()
            waves = []
            for _ in range(r.u32()):
                t = r.u32()
                w = r.u32()
                if t == 0:
                    waves.append({"type": 0, "weight": w, "file": r.str(), "bank": r.str(), "index": r.u32(),
                                  "length_ms": r.u32()})
                else:
                    waves.append({"type": t, "weight": w, "raw": r.raw(8).hex()})
            self.sounddefs.append({"name": name, "template": ti, "waves": waves})
        self.end = r.p

    def _category(self, r):
        name = r.str()
        r.raw(16)
        self.categories.append(name)
        for _ in range(r.u32()):
            self._category(r)

    def _group(self, r, path):
        name = r.str()
        _props(r)
        ng = r.u32()
        ne = r.u32()
        p = path + "/" + name
        for _ in range(ng):
            self._group(r, p)
        for _ in range(ne):
            self._event(r, p)

    def _event(self, r, path):
        typ = r.u32()
        name = r.str()
        guid = r.raw(16).hex()
        ev = {"path": path + "/" + name, "type": "simple" if typ == EVENT_SIMPLE else "complex", "guid": guid,
              "base": _base(r.raw(BASE_BLOCK)), "layers": [], "params": [], "user_properties": {}}
        if typ == EVENT_SIMPLE:
            r.u32()
            ev["layers"].append({"param": -1, "instances": [_instance(r)], "envelopes": []})
            r.u32()
            ev["category"] = r.str()
        elif typ == EVENT_COMPLEX:
            for _ in range(r.u32()):
                _flags = r.u16()
                prio = r.s16()
                ctrl = r.s16()
                ni = r.u16()
                ne = r.u16()
                layer = {"param": ctrl, "priority": prio, "instances": [_instance(r) for _ in range(ni)],
                         "envelopes": []}
                for _ in range(ne):
                    r.s32()
                    r.str()
                    r.u32()
                    dsp = r.u32()
                    r.u32()
                    pts = [(round(r.f32(), 6), round(r.f32(), 6), r.u32()) for _ in range(r.u32())]
                    r.u32()
                    r.u32()
                    layer["envelopes"].append({"dsp_type": dsp, "points": [[x, y] for x, y, _s in pts]})
                ev["layers"].append(layer)
            for _ in range(r.u32()):
                pname = r.str()
                vel = r.f32()
                mn = r.f32()
                mx = r.f32()
                fl = r.u32()
                seek = r.f32()
                r.u32()
                ev["params"].append({"name": pname, "min": round(mn, 6), "max": round(mx, 6),
                                     "velocity": round(vel, 6), "flags": fl, "seek_speed": round(seek, 6)})
            save = r.p
            for skip in (1, 0, 2):
                r.p = save + 4 * skip
                try:
                    up = _props(r)
                    one = r.u32()
                    cat = r.str()
                except FevError:
                    continue
                if one == 1 and cat in self.categories:
                    ev["user_properties"] = up
                    ev["category"] = cat
                    break
            else:
                raise FevError("unrecognised complex event tail at 0x%x (%s)" % (save, ev["path"]))
        else:
            raise FevError("unknown event type 0x%x at %s" % (typ, ev["path"]))
        self.events.append(ev)

    def event(self, path):
        for e in self.events:
            if e["path"] == path:
                return e
        raise KeyError(path)

    def event_waves(self, ev):
        """Distinct wave entries reachable from an event: [(sounddef name, wave dict)]."""
        out = []
        for layer in ev["layers"]:
            for inst in layer["instances"]:
                if inst["sounddef"] < len(self.sounddefs):
                    sd = self.sounddefs[inst["sounddef"]]
                    out.extend((sd["name"], w) for w in sd["waves"] if w["type"] == 0)
        return out


# Playmode values of a sound-definition template, FMOD Designer order (inferred: 0 dominates one-shot banks).
PLAYMODES = {0: "sequential", 1: "random", 2: "random_no_repeat", 3: "sequential_no_repeat", 4: "shuffle",
             5: "programmer_selected"}


def main(argv=None):
    import json
    argv = sys.argv[1:] if argv is None else argv
    if not argv:
        print("usage: fmod_fev.py FILE.fev [...]  (prints a JSON summary)")
        return 2
    for path in argv:
        with open(path, "rb") as f:
            fev = FevFile(f.read())
        print(json.dumps({"file": path, "project": fev.project, "banks": [b["name"] for b in fev.banks],
                          "events": [e["path"] for e in fev.events], "sounddefs": len(fev.sounddefs)}, indent=1))
    return 0


if __name__ == "__main__":
    sys.exit(main())
