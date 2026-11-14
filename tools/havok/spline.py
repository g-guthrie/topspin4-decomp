#!/usr/bin/env python3
"""hkaSplineSkeletalAnimation decoder (Havok 5.5 layout as used by Top Spin 4).

Bit layout (confirmed against Swing_DLL; addresses in docs/havok.md):

Block b starts at data[blockOffsets[b]]:
  numberOfTransformTracks x 4 bytes of masks: (quant, posMask, rotMask, scaleMask)
    quant: bits 0-1 position scalar quantisation, bits 2-5 rotation quantisation,
           bits 6-7 scale scalar quantisation
    pos/scale mask: bit i (i=0..2) component i static, bit 4+i component i spline
    rot mask: any of bits 4-7 -> spline, else any of bits 0-3 -> static, else identity
  data proper starts at blockOffsets[b] + maskAndQuantizationSize; for every track:
    position track, align 4, rotation track, align 4, scale track, align 4.
  Vector (position/scale) track:
    if spline: u16 numItems (=control points - 1), u8 degree, u8 knots[numItems+degree+2]
    align 4
    for c in x,y,z: spline -> f32 min, f32 max; static -> f32 value
    if spline: align 2, then (numItems+1) points, each the spline components in order,
      as u8 (BITS8, value/255) or u16 (BITS16, value/65535) mapped into [min, max]
  Rotation track:
    spline: u16 numItems, u8 degree, knots; align(quant); (numItems+1) quaternions
    static: align(quant); one quaternion
  Quaternion encodings (size, alignment): POLAR32 (4,4), THREECOMP40 (5,1),
    THREECOMP48 (6,2), THREECOMP24 (3,1), STRAIGHT16 (2,2), UNCOMPRESSED (16,4)
Sampling: block = clamp(int(t / blockDuration)), local time tl = t - block*blockDuration;
knots are frame indices (u8) scaled by frameDuration; the knot span is located with
the integer local frame and the curve is evaluated with B-spline basis functions.
"""
import math
import struct

POLAR32, THREECOMP40, THREECOMP48, THREECOMP24, STRAIGHT16, UNCOMPRESSED = range(6)
ROT_SIZE = [4, 5, 6, 3, 2, 16]
ROT_ALIGN = [4, 1, 2, 1, 2, 4]
INV_SQRT2 = 0.70710678118654752
THREECOMP40_SCALE = 1.0 / (2047 * math.sqrt(2.0))  # 0x39B51B97 in the game's constants


def align(p, a):
    return (p + a - 1) & ~(a - 1)


# --- quaternion codecs --------------------------------------------------------------
def _complete(vals, idx, neg):
    s = 1.0 - sum(v * v for v in vals)
    w = math.sqrt(s) if s > 0 else 0.0
    if neg:
        w = -w
    q = list(vals)
    q.insert(idx, w)
    return q


def decode_threecomp40(b):
    """5 bytes, read as a little-endian 40-bit integer:
    bits 0-11, 12-23, 24-35: three components (q * scale - 1/sqrt2)
    bits 36-37: index of the dropped (largest) component, bit 38: its sign."""
    v = int.from_bytes(bytes(b[:5]), "little")
    vals = [((v >> (12 * i)) & 0xFFF) * THREECOMP40_SCALE - INV_SQRT2 for i in range(3)]
    return _complete(vals, (v >> 36) & 3, (v >> 38) & 1)


def decode_threecomp48(b, endian=">"):
    """3 x u16; bits 0-14 value (q * 1/(32767*sqrt2) scale around 0x3FFF), bit 15 of
    the first two hold the dropped index, bit 15 of the third the sign."""
    x, y, z = struct.unpack(endian + "3H", bytes(b[:6]))
    idx = ((y >> 14) & 2) | (x >> 15)
    neg = z >> 15
    scale = 1.0 / (32767 * math.sqrt(2.0))
    vals = [((c & 0x7FFF) - 0x3FFF) * scale for c in (x, y, z)]
    return _complete(vals, idx, neg)


def decode_uncompressed(b, endian=">"):
    return list(struct.unpack(endian + "4f", bytes(b[:16])))


ROT_DECODERS = {THREECOMP40: decode_threecomp40, THREECOMP48: decode_threecomp48,
                UNCOMPRESSED: decode_uncompressed}


def decode_quat(qtype, b):
    try:
        return ROT_DECODERS[qtype](b)
    except KeyError:
        raise NotImplementedError("rotation quantisation %d not used by TS4 data" % qtype)


# --- B-spline ---------------------------------------------------------------------
def find_span(n, p, u, knots):
    """Knot span for integer local frame u (matches the game's binary search)."""
    if u >= knots[n + 1]:
        return n
    if u <= knots[p]:
        return p
    low, high = p, n + 1
    mid = (low + high) // 2
    while u < knots[mid] or u >= knots[mid + 1]:
        if u < knots[mid]:
            high = mid
        else:
            low = mid
        mid = (low + high) // 2
    return mid


def basis(span, u, p, knots):
    """Non-zero B-spline basis functions N[span-p..span] at u (Cox-de Boor)."""
    N = [1.0] + [0.0] * p
    left = [0.0] * (p + 1)
    right = [0.0] * (p + 1)
    for j in range(1, p + 1):
        left[j] = u - knots[span + 1 - j]
        right[j] = knots[span + j] - u
        saved = 0.0
        for r in range(j):
            den = right[r + 1] + left[j - r]
            tmp = N[r] / den if den != 0 else 0.0
            N[r] = saved + right[r + 1] * tmp
            saved = left[j - r] * tmp
        N[j] = saved
    return N


def evaluate(knots_frames, degree, points, frame_time, frame_duration):
    """Evaluate a spline at a local time (seconds). points: list of tuples."""
    n = len(points) - 1
    span = find_span(n, degree, int(frame_time), knots_frames)
    knots = [k * frame_duration for k in knots_frames]
    N = basis(span, frame_time * frame_duration, degree, knots)
    dim = len(points[0])
    out = [0.0] * dim
    for i in range(degree + 1):
        cp = points[span - degree + i]
        for c in range(dim):
            out[c] += N[i] * cp[c]
    return out


# --- track parsing ----------------------------------------------------------------
class Reader:
    def __init__(self, data, pos):
        self.d, self.p = data, pos

    def u8(self):
        v = self.d[self.p]
        self.p += 1
        return v

    def u16(self, e):
        v = struct.unpack_from(e + "H", self.d, self.p)[0]
        self.p += 2
        return v

    def f32(self, e):
        v = struct.unpack_from(e + "f", self.d, self.p)[0]
        self.p += 4
        return v

    def align(self, a):
        self.p = align(self.p, a)


def read_spline_header(r, e):
    n = r.u16(e)
    deg = r.u8()
    knots = list(r.d[r.p:r.p + n + deg + 2])
    r.p += n + deg + 2
    return n, deg, knots


class VectorTrack:
    """Constant (static/identity components) or spline position/scale track."""

    def __init__(self, default, static, spline=None):
        self.value = list(default)
        self.static = static
        self.spline = spline  # (degree, knots, points[list of 3-tuples])

    def sample(self, tl, fdur):
        if not self.spline:
            return list(self.value)
        deg, knots, pts = self.spline
        return evaluate(knots, deg, pts, tl / fdur, fdur)


def read_vector_track(r, e, mask, qbits, default):
    spline = mask & 0xF0
    if spline:
        n, deg, knots = read_spline_header(r, e)
    r.align(4)
    value = list(default)
    mins, maxs = [0.0] * 3, [0.0] * 3
    comps = []
    for c in range(3):
        if mask & (1 << c):
            value[c] = r.f32(e)
        elif mask & (0x10 << c):
            mins[c], maxs[c] = r.f32(e), r.f32(e)
            comps.append(c)
    if not spline:
        return VectorTrack(value, True)
    r.align(2)
    pts = []
    for i in range(n + 1):
        pt = list(value)
        for c in comps:
            if qbits == 0:
                q = r.u8() / 255.0
            else:
                q = r.u16(e) / 65535.0
            pt[c] = mins[c] + (maxs[c] - mins[c]) * q
        pts.append(tuple(pt))
    return VectorTrack(value, False, (deg, knots, pts))


class RotationTrack:
    def __init__(self, value, spline=None):
        self.value = value
        self.spline = spline

    def sample(self, tl, fdur):
        if not self.spline:
            return list(self.value)
        deg, knots, pts = self.spline
        q = evaluate(knots, deg, pts, tl / fdur, fdur)
        n = math.sqrt(sum(c * c for c in q)) or 1.0
        return [c / n for c in q]


def read_rotation_track(r, e, mask, qtype):
    size, al = ROT_SIZE[qtype], ROT_ALIGN[qtype]
    if mask & 0xF0:
        n, deg, knots = read_spline_header(r, e)
        r.align(al)
        pts = []
        for i in range(n + 1):
            pts.append(tuple(decode_quat(qtype, r.d[r.p:r.p + size])))
            r.p += size
        return RotationTrack(None, (deg, knots, pts))
    if mask & 0x0F:
        r.align(al)
        q = decode_quat(qtype, r.d[r.p:r.p + size])
        r.p += size
        return RotationTrack(q)
    return RotationTrack([0.0, 0.0, 0.0, 1.0])


def parse_block(data, start, ntracks, mqsize, e=">"):
    """Return a list of (pos_track, rot_track, scale_track) for one block."""
    masks = [tuple(data[start + 4 * t:start + 4 * t + 4]) for t in range(ntracks)]
    r = Reader(data, start + mqsize)
    tracks = []
    for quant, pm, rm, sm in masks:
        pos = read_vector_track(r, e, pm, quant & 3, (0.0, 0.0, 0.0))
        r.align(4)
        rot = read_rotation_track(r, e, rm, (quant >> 2) & 0xF)
        r.align(4)
        scl = read_vector_track(r, e, sm, (quant >> 6) & 3, (1.0, 1.0, 1.0))
        r.align(4)
        tracks.append((pos, rot, scl))
    return tracks, r.p


class SplineAnimation:
    """Decoder for one hkaSplineSkeletalAnimation object read via classes.Registry."""

    def __init__(self, obj, endian=">"):
        self.o = obj
        self.data = bytes(obj["data"])
        self.e = endian
        self.ntracks = obj["numberOfTransformTracks"]
        self.blocks = [parse_block(self.data, off, self.ntracks, obj["maskAndQuantizationSize"], endian)[0]
                       for off in obj["blockOffsets"]]

    def sample(self, t):
        o = self.o
        b = int(t * o["blockInverseDuration"])
        b = max(0, min(b, o["numBlocks"] - 1))
        tl = t - b * o["blockDuration"]
        fdur = o["frameDuration"]
        out = []
        for pos, rot, scl in self.blocks[b]:
            out.append((pos.sample(tl, fdur), rot.sample(tl, fdur), scl.sample(tl, fdur)))
        return out

    def frames(self):
        o = self.o
        n = o["numFrames"]
        return [self.sample(i * o["frameDuration"]) for i in range(n)]
