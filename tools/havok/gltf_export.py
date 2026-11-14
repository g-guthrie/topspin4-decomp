#!/usr/bin/env python3
"""Minimal glTF 2.0 writer for a Havok skeleton plus animation clips (standard library).

Output: NAME.gltf (JSON) + NAME.bin (little-endian float buffer).
  * one node per bone, local TRS = reference pose, hierarchy from parentIndices
  * a skin listing every bone with inverse bind matrices from the reference pose
  * one glTF animation per clip, LINEAR samplers for translation/rotation/scale of each
    bone the clip's binding drives (additive clips composed onto the reference pose)
Translations are multiplied by `unit_scale` (Havok data is in centimetres; 0.01 -> m).
"""
import json
import os
import struct

from skeleton import mat_inverse_affine, quat_normalize

FLOAT = 5126


class Builder:
    def __init__(self):
        self.buf = bytearray()
        self.views, self.accessors = [], []

    def add(self, values, type_, count, minmax=False):
        while len(self.buf) % 4:
            self.buf.append(0)
        off = len(self.buf)
        self.buf += struct.pack("<%df" % len(values), *values)
        self.views.append({"buffer": 0, "byteOffset": off, "byteLength": 4 * len(values)})
        acc = {"bufferView": len(self.views) - 1, "componentType": FLOAT, "count": count, "type": type_}
        if minmax:
            n = len(values) // count
            acc["min"] = [min(values[i::n]) for i in range(n)]
            acc["max"] = [max(values[i::n]) for i in range(n)]
        self.accessors.append(acc)
        return len(self.accessors) - 1


def _round(v):
    return [float("%.7g" % x) for x in v]


def export(path, skel, clips, unit_scale=0.01, additive_base=True, name=None):
    b = Builder()
    nodes = []
    for i, bone in enumerate(skel.bones):
        t, r, s = skel.ref[i]
        node = {"name": bone,
                "translation": _round([c * unit_scale for c in t]),
                "rotation": _round(quat_normalize(r)),
                "scale": _round(s)}
        kids = [j for j, p in enumerate(skel.parents) if p == i]
        if kids:
            node["children"] = kids
        nodes.append(node)
    roots = [i for i, p in enumerate(skel.parents) if p < 0]
    worlds = skel.world_matrices([( [c * unit_scale for c in t], r, s) for t, r, s in skel.ref])
    ibm = []
    for m in worlds:
        ibm += mat_inverse_affine(m)
    ibm_acc = b.add(ibm, "MAT4", len(worlds))
    gltf = {
        "asset": {"version": "2.0", "generator": "topspin4-decomp tools/havok/gltf_export.py"},
        "scene": 0,
        "scenes": [{"name": name or skel.name, "nodes": roots}],
        "nodes": nodes,
        "skins": [{"name": skel.name, "joints": list(range(len(nodes))), "skeleton": roots[0],
                   "inverseBindMatrices": ibm_acc}],
        "animations": [],
    }
    for clip in clips:
        if not clip.times:
            continue
        times = clip.times if len(clip.times) > 1 else [0.0]
        t_acc = b.add(times, "SCALAR", len(times), minmax=True)
        poses = [clip.bone_pose(skel, f, additive_base) for f in range(len(times))]
        samplers, channels = [], []
        for bone in sorted(set(clip.track_to_bone)):
            if bone < 0 or bone >= len(skel):
                continue
            tr, ro, sc = [], [], []
            prev = None
            for p in poses:
                q = list(p[bone][1])
                if prev is not None and sum(x * y for x, y in zip(prev, q)) < 0:
                    q = [-c for c in q]  # keep the shortest path for LINEAR slerp
                prev = q
                tr += [c * unit_scale for c in p[bone][0]]
                ro += q
                sc += list(p[bone][2])
            for path_, vals, typ in (("translation", tr, "VEC3"), ("rotation", ro, "VEC4"), ("scale", sc, "VEC3")):
                out = b.add(vals, typ, len(times))
                samplers.append({"input": t_acc, "output": out, "interpolation": "LINEAR"})
                channels.append({"sampler": len(samplers) - 1, "target": {"node": bone, "path": path_}})
        anim = {"name": "%s_%d" % (clip.cls.replace("SkeletalAnimation", "").replace("hka", ""), clip.index),
                "samplers": samplers, "channels": channels,
                "extras": {"havokClass": clip.cls, "blendHint": clip.blend_hint, "duration": clip.duration,
                           "annotations": clip.annotations,
                           "composedOntoReferencePose": clip.blend_hint == "ADDITIVE" and additive_base}}
        gltf["animations"].append(anim)
    if not gltf["animations"]:
        del gltf["animations"]
    base = os.path.splitext(path)[0]
    os.makedirs(os.path.dirname(os.path.abspath(base)), exist_ok=True)
    binname = os.path.basename(base) + ".bin"
    gltf["buffers"] = [{"uri": binname, "byteLength": len(b.buf)}]
    gltf["bufferViews"] = b.views
    gltf["accessors"] = b.accessors
    with open(base + ".bin", "wb") as f:
        f.write(b.buf)
    with open(base + ".gltf", "w") as f:
        json.dump(gltf, f, indent=1)
    return base + ".gltf"
