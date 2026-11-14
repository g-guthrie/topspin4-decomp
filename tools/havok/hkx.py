#!/usr/bin/env python3
"""Havok 5.5 packfile tool for Top Spin 4 (standard library only).

Input is either an extracted packfile or an archive entry read in place from the disc:
  hkx.py FILE.hkx --info
  hkx.py --iso ISO --arc Core.arc --entry 6932352f --info
Actions:
  --info                 header, SDK version, sections, fixup counts, objects per class
  --types                class layouts reflected in the file's __types__ section
  --dump-skeleton [N]    bones (index, parent, name, reference pose) of skeleton N (default all)
  --list-clips           every animation object with codec, duration, frames, tracks
  --export-gltf OUT      skeleton (--skeleton N) + clips (--clips 0,5,9 | --clips all,
                         default none) to OUT.gltf/OUT.bin; --unit-scale (default 0.01)
  --save OUT             write the (decompressed) packfile bytes to OUT
"""
import argparse
import collections
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import classes  # noqa: E402
import gltf_export  # noqa: E402
import packfile  # noqa: E402
import skeleton  # noqa: E402


def read_input(a):
    if a.file:
        with open(a.file, "rb") as f:
            return f.read()
    sys.path.insert(0, os.path.dirname(HERE))
    import ts4_arc  # noqa: E402  (disc agent's reader, used read-only)
    import xdvdfs  # noqa: E402
    import scan_arcs  # noqa: E402
    x = xdvdfs.XDVDFS(a.iso)
    h = int(a.entry, 16)
    try:
        arc = ts4_arc.Arc(x.open_slice(a.arc))
    except ValueError:  # uncompressed "PAM-NIL" archives such as CutScenes.arc
        arc = scan_arcs.NilArc(x.open_slice(a.arc))
        for e in arc.entries:
            if e[0] == h:
                arc.f.seek(arc.data_start + e[1])
                return arc.f.read(e[2])
        raise KeyError(a.entry)
    return arc.read(arc.find(h))


def info(pf):
    print("magic ok, file version %d, contents version %s, user tag 0x%X, flags 0x%X"
          % (pf.file_version, pf.version, pf.user_tag, pf.flags))
    print("layout rules: pointer %d, little-endian %d, reuse padding %d, empty base %d"
          % (pf.ptr_size, pf.little_endian, pf.reuse_padding, pf.empty_base))
    s, o, c = pf.contents()
    print("contents: section %d offset 0x%X class %s" % (s, o, c))
    for i, sec in enumerate(pf.sections):
        print("section %d %-15s start 0x%08X data 0x%X local %d global %d virtual %d"
              % (i, sec.name, sec.start, sec.data_size, len(pf.local_fixups[i]),
                 len(pf.global_fixups[i]), len(pf.virtual_fixups[i])))
    print("classnames: %d" % len(pf.classnames()))
    cnt = collections.Counter(pf.obj_class.values())
    for k, v in sorted(cnt.items(), key=lambda kv: (-kv[1], kv[0])):
        print("  %6d %s" % (v, k))


def dump_types(reg):
    for name in sorted(reg.reflected):
        c = reg.classes[name]
        print("%s size 0x%X parent %s" % (name, c.size, c.parent))
        for m in c.members:
            print("   ", m)


def dump_skeleton(skels, which):
    for i, sk in enumerate(skels):
        if which is not None and which != i:
            continue
        print("skeleton %d name %s bones %d float slots %d" % (i, sk.name, len(sk), len(sk.float_slots)))
        for b, name in enumerate(sk.bones):
            t, r, s = sk.ref[b]
            print("  %3d %3d %-28s t(%9.4f %9.4f %9.4f) r(%7.4f %7.4f %7.4f %7.4f) s(%.3f %.3f %.3f)"
                  % ((b, sk.parents[b], name) + tuple(t) + tuple(r) + tuple(s)))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("file", nargs="?")
    ap.add_argument("--iso")
    ap.add_argument("--arc")
    ap.add_argument("--entry", help="archive entry hash (hex)")
    ap.add_argument("--info", action="store_true")
    ap.add_argument("--types", action="store_true")
    ap.add_argument("--dump-skeleton", nargs="?", const=-1, type=int)
    ap.add_argument("--list-clips", action="store_true")
    ap.add_argument("--export-gltf")
    ap.add_argument("--skeleton", type=int, default=0)
    ap.add_argument("--clips", default="")
    ap.add_argument("--unit-scale", type=float, default=0.01)
    ap.add_argument("--raw-additive", action="store_true", help="do not compose additive clips onto the reference pose")
    ap.add_argument("--save")
    a = ap.parse_args()
    if not a.file and not (a.iso and a.arc and a.entry):
        ap.error("give FILE or --iso/--arc/--entry")
    data = read_input(a)
    if a.save:
        with open(a.save, "wb") as f:
            f.write(data)
    pf = packfile.Packfile(data)
    try:
        reg = classes.Registry.from_packfile(pf)
    except classes.MissingClasses as ex:
        sys.exit(str(ex))
    if a.info:
        info(pf)
    if a.types:
        dump_types(reg)
    skels, anims = skeleton.load(pf, reg)
    if a.dump_skeleton is not None:
        dump_skeleton(skels, None if a.dump_skeleton < 0 else a.dump_skeleton)
    if a.list_clips:
        for i, (loc, cls, binding) in enumerate(anims):
            o = reg.read_object(pf, loc[0], loc[1], cls)
            frames = o.get("numFrames", o.get("numberOfPoses"))
            print("%5d %-38s @0x%08X dur %.4f frames %s tracks %d blend %s"
                  % (i, cls, loc[1], o["duration"], frames, o["numberOfTransformTracks"],
                     binding["blendHint"] if binding else "-"))
    if a.export_gltf:
        if a.clips == "all":
            sel = range(len(anims))
        else:
            sel = [int(c) for c in a.clips.split(",") if c]
        clips = [skeleton.load_clip(pf, reg, anims[i], i) for i in sel]
        out = gltf_export.export(a.export_gltf, skels[a.skeleton], clips, a.unit_scale, not a.raw_additive)
        print("wrote", out, "with", len(clips), "clips")


if __name__ == "__main__":
    main()
