#!/usr/bin/env python3
"""Delta-compressed and wavelet-compressed hkaSkeletalAnimation decoders (Havok 5.5,
as used by Top Spin 4). All bit layouts confirmed against Swing_DLL (see docs/havok.md).

Shared layout (offsets into the object's dataBuffer, multi-byte values little endian):
  staticMaskIdx: numberOfTransformTracks x u16 track masks, then numberOfFloatTracks x u16
  staticDOFsIdx: f32 values for every static degree of freedom, in pose-assembly order
  qFormat.offsetIdx / scaleIdx: numD x f32 per dynamic channel; bitWidthIdx: numD x u8
  (if bitWidthIdx is 0 every channel uses qFormat.maxBitWidth)

Track mask m (pose assembly at 0x884165B0):
  position: (m & 3) == 2 -> identity; else x,y,z each dynamic if m bit 8,7,6, else static
  rotation: (m >> 2 & 3) == 2 -> identity; else x,y,z,w dynamic if m bit 12,11,10,9.
            If |w| == 2.0 after filling, w is recomputed as sqrt(1 - min(1, x^2+y^2+z^2))
            with the sign of the stored w (the encoder stores +-2.0 as a placeholder).
  scale:    (m >> 4 & 3) == 2 -> identity (1,1,1); else x,y,z dynamic if m bit 15,14,13
Static values are consumed in that order (pos xyz, rot xyzw, scale xyz) per track, and
dynamic channels are numbered in the same order across all tracks.

Channel quantisation (0x88515830): `preserved` raw f32 values, then (n - preserved)
unsigned bw-bit integers in an LSB-first bit stream assembled from little-endian u16
words; value = (q + 0.5) * scale / 2^bw + offset.
Delta (0x8840B8D8, 0x88515620): one block of every channel back to back, each channel
4*preserved + ceil((n - preserved) * bw / 8) bytes (0x88515018); after dequantisation
the channel is prefix-summed (v[i] += v[i-1]).
Wavelet (0x88413FF8): per block (start = quantizedDataIdx + blockIndex[b]) each channel is
  4*preserved bytes of f32, an n-bit "is zero" mask (LSB first), then the bw-bit codes of
  the non-zero entries; consumed ceil((32*preserved + n + bw*nonzero) / 8) bytes
  (0x885207C8). Zero entries take the code int(-offset/scale * 2^bw) (minus 1 if it
  equals 2^bw). The dequantised block is passed through an inverse CDF 5/3 lifting
  transform (0x8851FDE0): from size s=1 (the game starts at 8 with a precomputed 8x8
  matrix) to blockSize: even = x[:s], odd = x[s:2s];
      even[0] -= 0.5*odd[0]; even[i] -= 0.25*(odd[i-1] + odd[i])        (0x885205D8)
      odd[i] += 0.5*(even[i] + even[i+1]); odd[s-1] += even[s-1]         (0x885204D8)
  then interleave even/odd.
"""
import math
import struct


class BitReader:
    """LSB-first bit stream over little-endian u16 words."""

    def __init__(self, data, pos):
        self.d, self.p = data, pos
        self.acc, self.n = 0, 0

    def bits(self, k):
        while self.n < k:
            w = self.d[self.p] | (self.d[self.p + 1] << 8) if self.p + 1 < len(self.d) else self.d[self.p]
            self.p += 2
            self.acc |= w << self.n
            self.n += 16
        v = self.acc & ((1 << k) - 1)
        self.acc >>= k
        self.n -= k
        return v


def dequantize(q, bw, scale, offset):
    return (q + 0.5) * scale / float(1 << bw) + offset


def unpack_channel(data, pos, n, bw, preserved, scale, offset):
    """Return (values, bytes_used) for one delta-coded channel block (before summing)."""
    out = list(struct.unpack_from("<%df" % preserved, data, pos)) if preserved else []
    br = BitReader(data, pos + 4 * preserved)
    for _ in range(n - preserved):
        out.append(dequantize(br.bits(bw), bw, scale, offset))
    used = 4 * preserved + ((n - preserved) * bw + 7) // 8
    return out, used


def prefix_sum(v):
    for i in range(1, len(v)):
        v[i] += v[i - 1]
    return v


# --- wavelet ------------------------------------------------------------------------
def _undo_update(even, odd, c):
    """0x885205D8 with c = -0.25: even[i] += c*(odd[i-1]+odd[i]), even[0] += 2c*odd[0]."""
    s = len(even)
    for i in range(1, s):
        even[i] += c * (odd[i - 1] + odd[i])
    even[0] += 2.0 * c * odd[0]


def _undo_predict(even, odd, c):
    """0x885204D8 with c = 0.5: odd[i] += c*(even[i]+even[i+1]), odd[-1] += 2c*even[-1]."""
    s = len(even)
    for i in range(s - 1):
        odd[i] += c * (even[i] + even[i + 1])
    odd[s - 1] += 2.0 * c * even[s - 1]


def inverse_wavelet(x):
    x = list(x)
    n = len(x)
    s = 1
    while 2 * s <= n:
        even, odd = x[:s], x[s:2 * s]
        _undo_update(even, odd, -0.25)
        _undo_predict(even, odd, 0.5)
        merged = [0.0] * (2 * s)
        merged[0::2], merged[1::2] = even, odd
        x[:2 * s] = merged
        s *= 2
    return x


def forward_wavelet(x):
    """Encoder counterpart (0x88520120); used by the unit tests."""
    x = list(x)
    n = len(x)
    while n > 1:
        even, odd = x[0:n:2], x[1:n:2]
        s = len(even)
        for i in range(s - 1):
            odd[i] += -0.5 * (even[i] + even[i + 1])
        odd[s - 1] += 2 * -0.5 * even[s - 1]
        for i in range(1, s):
            even[i] += 0.25 * (odd[i - 1] + odd[i])
        even[0] += 2 * 0.25 * odd[0]
        x[:n] = even + odd
        n //= 2
    return x


def wavelet_channel(data, pos, n, bw, preserved, scale, offset):
    """Return (dequantised coefficients, bytes_used) for one wavelet channel block."""
    out = list(struct.unpack_from("<%df" % preserved, data, pos)) if preserved else []
    p = pos + 4 * preserved
    m = n - preserved
    mask_bytes = (m + 7) // 8
    zero = int(-offset / scale * (1 << bw)) if scale else 0
    if zero == (1 << bw):
        zero -= 1
    br = BitReader(data, p + mask_bytes)
    nz = 0
    for i in range(m):
        if data[p + (i >> 3)] >> (i & 7) & 1:
            q = zero
        else:
            q = br.bits(bw)
            nz += 1
        out.append(dequantize(q, bw, scale, offset))
    used = (32 * preserved + m + bw * nz + 7) // 8
    return out, used


# --- pose assembly ------------------------------------------------------------------
def track_layout(mask):
    """List of 10 entries (pos xyz, rot xyzw, scale xyz): 'S' static, 'D' dynamic,
    or a float default for identity components."""
    out = []
    groups = (((mask & 3) == 2, (8, 7, 6), (0.0, 0.0, 0.0)),
              (((mask >> 2) & 3) == 2, (12, 11, 10, 9), (0.0, 0.0, 0.0, 1.0)),
              (((mask >> 4) & 3) == 2, (15, 14, 13), (1.0, 1.0, 1.0)))
    for ident, bits, default in groups:
        for b, dv in zip(bits, default):
            out.append(dv if ident else ("D" if mask >> b & 1 else "S"))
    return out


def assemble(masks, statics, dynamics):
    """Build per-track (pos, rot, scale) from static and dynamic values (0x884165B0)."""
    si = di = 0
    out = []
    for m in masks:
        vals = []
        for slot in track_layout(m):
            if slot == "S":
                vals.append(statics[si])
                si += 1
            elif slot == "D":
                vals.append(dynamics[di])
                di += 1
            else:
                vals.append(slot)
        pos, rot, scl = vals[0:3], vals[3:7], vals[7:10]
        if ((m >> 2) & 3) != 2 and abs(rot[3]) == 2.0:
            s = min(1.0, rot[0] ** 2 + rot[1] ** 2 + rot[2] ** 2)
            w = math.sqrt(1.0 - s)
            rot[3] = w if rot[3] > 0 else -w
        out.append((pos, rot, scl))
    return out


def count_dofs(masks):
    ns = nd = 0
    for m in masks:
        for slot in track_layout(m):
            ns += slot == "S"
            nd += slot == "D"
    return ns, nd


class QuantizedAnimation:
    """Decoder for hkaDeltaCompressedSkeletalAnimation / hkaWaveletSkeletalAnimation objects."""

    def __init__(self, obj):
        self.o = obj
        self.wavelet = obj["__class__"] == "hkaWaveletSkeletalAnimation"
        d = self.d = bytes(obj["dataBuffer"])
        q = obj["qFormat"]
        nt = obj["numberOfTransformTracks"]
        self.masks = list(struct.unpack_from("<%dH" % nt, d, obj["staticMaskIdx"]))
        ns, nd = count_dofs(self.masks)
        if nd != q["numD"]:
            raise ValueError("mask dynamic count %d != numD %d" % (nd, q["numD"]))
        self.statics = list(struct.unpack_from("<%df" % ns, d, obj["staticDOFsIdx"]))
        self.nd = nd
        self.offsets = list(struct.unpack_from("<%df" % nd, d, q["offsetIdx"]))
        self.scales = list(struct.unpack_from("<%df" % nd, d, q["scaleIdx"]))
        if q["bitWidthIdx"]:
            self.bitwidths = list(d[q["bitWidthIdx"]:q["bitWidthIdx"] + nd])
        else:
            self.bitwidths = [q["maxBitWidth"]] * nd
        self.preserved = q["preserved"]
        self.channels = self._decode()

    def _block_starts(self):
        o, d = self.o, self.d
        nblocks = (o["numberOfPoses"] + o["blockSize"] - 1) // o["blockSize"]
        if self.wavelet:
            idx = struct.unpack_from("<%dI" % o["blockIndexSize"], d, o["blockIndexIdx"])
            return [o["quantizedDataIdx"] + i for i in idx[:nblocks]]
        return [o["quantizedDataIdx"] + b * o["totalBlockSize"] for b in range(nblocks)]

    def _decode(self):
        o = self.o
        npose, bs = o["numberOfPoses"], o["blockSize"]
        chans = [[] for _ in range(self.nd)]
        for b, start in enumerate(self._block_starts()):
            n = bs if self.wavelet else min(bs, npose - b * bs)
            p = start
            for c in range(self.nd):
                args = (self.d, p, n, self.bitwidths[c], self.preserved, self.scales[c], self.offsets[c])
                if self.wavelet:
                    vals, used = wavelet_channel(*args)
                    vals = inverse_wavelet(vals)
                else:
                    vals, used = unpack_channel(*args)
                    vals = prefix_sum(vals)
                chans[c].extend(vals[:min(bs, npose - b * bs)])
                p += used
        return chans

    @property
    def num_frames(self):
        return self.o["numberOfPoses"]

    def frame(self, i):
        return assemble(self.masks, self.statics, [ch[i] for ch in self.channels])

    def frames(self):
        return [self.frame(i) for i in range(self.num_frames)]
