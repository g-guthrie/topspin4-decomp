#!/usr/bin/env python3
"""Skeletons and decoded clips from a Havok 5.5 packfile (Top Spin 4).

Skeleton: hkaSkeleton {name, parentIndices[], bones[]->{name, lockTranslation},
referencePose[] (hkQsTransform: translation xyz_, rotation xyzw, scale xyz_), floatSlots}.
Clip: one hkaSkeletalAnimation plus the hkaAnimationBinding that maps its tracks to bones.
"""
import math

import spline
import delta

ANIM_CLASSES = ("hkaSplineSkeletalAnimation", "hkaDeltaCompressedSkeletalAnimation",
                "hkaWaveletSkeletalAnimation", "hkaInterleavedSkeletalAnimation")


class Skeleton:
    def __init__(self, obj):
        self.name = obj["name"]
        self.parents = list(obj["parentIndices"])
        self.bones = [b.get()["name"] if hasattr(b, "get") else b["name"] for b in obj["bones"]]
        self.lock_translation = [bool(b.get()["lockTranslation"]) if hasattr(b, "get") else False
                                 for b in obj["bones"]]
        self.ref = [(list(q[0:3]), list(q[4:8]), list(q[8:11])) for q in obj["referencePose"]]
        self.float_slots = list(obj["floatSlots"])

    def __len__(self):
        return len(self.bones)

    def world_matrices(self, pose=None):
        pose = pose or self.ref
        out = []
        for i, (t, r, s) in enumerate(pose):
            m = trs_matrix(t, r, s)
            p = self.parents[i]
            out.append(mat_mul(out[p], m) if p >= 0 else m)
        return out


def quat_mul(a, b):
    ax, ay, az, aw = a
    bx, by, bz, bw = b
    return [aw * bx + ax * bw + ay * bz - az * by,
            aw * by - ax * bz + ay * bw + az * bx,
            aw * bz + ax * by - ay * bx + az * bw,
            aw * bw - ax * bx - ay * by - az * bz]


def quat_normalize(q):
    n = math.sqrt(sum(c * c for c in q)) or 1.0
    return [c / n for c in q]


def trs_matrix(t, q, s):
    """Column-major 4x4 (glTF convention) from translation, quaternion xyzw, scale."""
    x, y, z, w = quat_normalize(q)
    r = [[1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
         [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
         [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]]
    m = [0.0] * 16
    for c in range(3):
        for rr in range(3):
            m[c * 4 + rr] = r[rr][c] * s[c]
    m[12], m[13], m[14], m[15] = t[0], t[1], t[2], 1.0
    return m


def mat_mul(a, b):
    out = [0.0] * 16
    for c in range(4):
        for r in range(4):
            out[c * 4 + r] = sum(a[k * 4 + r] * b[c * 4 + k] for k in range(4))
    return out


def mat_inverse_affine(m):
    """Inverse of a column-major affine matrix (rotation*scale + translation)."""
    a = [[m[c * 4 + r] for c in range(3)] for r in range(3)]
    det = (a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])
           - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])
           + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]))
    inv = [[0.0] * 3 for _ in range(3)]
    for r in range(3):
        for c in range(3):
            r1, r2 = [i for i in range(3) if i != c]
            c1, c2 = [i for i in range(3) if i != r]
            minor = a[r1][c1] * a[r2][c2] - a[r1][c2] * a[r2][c1]
            inv[r][c] = (-1) ** (r + c) * minor / det
    t = [m[12], m[13], m[14]]
    out = [0.0] * 16
    for c in range(3):
        for r in range(3):
            out[c * 4 + r] = inv[r][c]
    for r in range(3):
        out[12 + r] = -sum(inv[r][k] * t[k] for k in range(3))
    out[15] = 1.0
    return out


class Clip:
    """Decoded animation: frames[i][track] = (pos, rot, scale), times[i] in seconds."""

    def __init__(self, anim_obj, binding=None, index=None):
        self.obj = anim_obj
        self.cls = anim_obj["__class__"]
        self.index = index
        self.duration = anim_obj["duration"]
        self.binding = binding
        self.track_to_bone = list(binding["transformTrackToBoneIndices"]) if binding else None
        hint = binding["blendHint"] if binding else "NORMAL"
        self.blend_hint = {0: "NORMAL", 1: "ADDITIVE"}.get(hint, hint)
        self.annotations = []
        for tr in anim_obj["annotationTracks"]:
            t = tr.get() if hasattr(tr, "get") else tr
            self.annotations.append((t["name"], [(a["time"], a["text"]) for a in t["annotations"]]))
        self.frames, self.times = self._decode()
        if self.track_to_bone is None:
            self.track_to_bone = list(range(anim_obj["numberOfTransformTracks"]))

    def _decode(self):
        o = self.obj
        if self.cls == "hkaSplineSkeletalAnimation":
            # The game's mask bytes and spline payload are little endian (endian field 0).
            a = spline.SplineAnimation(o, "<" if o["endian"] == 0 else ">")
            n = o["numFrames"]
            times = [i * o["frameDuration"] for i in range(n)]
            return [a.sample(t) for t in times], times
        if self.cls in ("hkaDeltaCompressedSkeletalAnimation", "hkaWaveletSkeletalAnimation"):
            a = delta.QuantizedAnimation(o)
            n = a.num_frames
            dt = self.duration / (n - 1) if n > 1 else 0.0
            return a.frames(), [i * dt for i in range(n)]
        if self.cls == "hkaInterleavedSkeletalAnimation":
            nt = o["numberOfTransformTracks"]
            tf = o["transforms"]
            n = len(tf) // nt if nt else 0
            dt = self.duration / (n - 1) if n > 1 else 0.0
            frames = [[(q[0:3], q[4:8], q[8:11]) for q in tf[i * nt:(i + 1) * nt]] for i in range(n)]
            return frames, [i * dt for i in range(n)]
        raise NotImplementedError(self.cls)

    def bone_pose(self, skel, frame, additive_base=True):
        """Full local pose (list per bone) for one frame; unbound bones keep the reference pose.
        Additive clips are composed onto the reference pose: t = t_ref + t_add,
        r = r_ref * r_add, s = s_ref * s_add (Havok additive convention, see docs)."""
        pose = [tuple(list(c) for c in p) for p in skel.ref]
        for t, (pos, rot, scl) in enumerate(self.frames[frame]):
            b = self.track_to_bone[t]
            rot = quat_normalize(rot)
            if self.blend_hint == "ADDITIVE" and additive_base:
                rt, rr, rs = skel.ref[b]
                pose[b] = ([rt[i] + pos[i] for i in range(3)], quat_normalize(quat_mul(rr, rot)),
                           [rs[i] * scl[i] for i in range(3)])
            else:
                pose[b] = (list(pos), rot, list(scl))
        return pose


def load(pf, reg):
    """Return (skeletons, clips_index) where clips_index is a list of (anim_loc, binding_obj)."""
    skels = [Skeleton(reg.read_object(pf, s, o, "hkaSkeleton")) for s, o in pf.objects("hkaSkeleton")]
    binds = {}
    for s, o in pf.objects("hkaAnimationBinding"):
        b = reg.read_object(pf, s, o, "hkaAnimationBinding")
        if b["animation"] is not None:
            binds[(b["animation"].sec, b["animation"].off)] = b
    anims = []
    for cls in ANIM_CLASSES:
        for loc in pf.objects(cls):
            anims.append((loc, cls, binds.get(loc)))
    anims.sort()
    return skels, anims


def load_clip(pf, reg, entry, index=None):
    loc, cls, binding = entry
    return Clip(reg.read_object(pf, loc[0], loc[1], cls), binding, index)
