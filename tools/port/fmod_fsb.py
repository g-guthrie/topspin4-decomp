#!/usr/bin/env python3
"""Reader for the FMOD sample banks (.fsb, "FSB4") of Top Spin 4 (Xbox 360), plus the small codec helpers the
audio exporter needs.  Little-endian throughout (as measured on the disc).

  header (48 B)   "FSB4"  u32 nsamples  u32 shdr_size  u32 data_size  u32 version  u32 mode  u8[24] (hash, zero)
  sample header   u16 size  char name[30]  u32 length (samples)  u32 compressed_size  u32 loop_start  u32 loop_end
                  u32 mode  s32 frequency  u16 volume  s16 pan  u16 priority  u16 channels  f32 min_distance
                  f32 max_distance  s32 var_freq  u16 var_vol  s16 var_pan            (80 bytes, then `size-80` extra)
  data            at 48 + shdr_size; each sample's compressed_size bytes follow the previous one, rounded up to
                  32 bytes when mode bit 0x10000000 (padded MPEG) is set (verified: 48 + shdr_size + data_size ==
                  file size and the last sample ends there on every Amsterdam bank)

Sample mode bits seen on the disc (FMOD Ex FSOUND_* values):
  0x01000000 XMA        raw XMA2 packets (2048-byte packets); 32 bytes of extra header (seek/loop info)
  0x00000200 MPEG       plain MPEG-1 layer III frames (streamed music, Ball_Shot, Stadium, Crowd_*_Full)
  0x10000000 padded     each sample's data is padded to a 32-byte boundary (seen together with MPEG)
  0x00400000 IMA ADPCM  with 0x20000000: Xbox IMA layout (36-byte blocks per channel, stereo interleaved by 4 bytes)
  0x00000020 mono, 0x00000040 stereo, 0x00000002 loop normal

XMA is not decodable with the standard library; xma_riff() wraps the packets in a RIFF/WAVE with an XMA2WAVEFORMATEX
'fmt ' chunk (format tag 0x166) that ffmpeg decodes (`ffmpeg -i x.xma.wav out.wav`; verified with ffmpeg 7.x: decoded
durations equal the header sample counts).  MPEG data is written as .mp3 directly.  Xbox IMA is decoded here.
"""
import struct
import sys

MAGIC = b"FSB4"
MODE_LOOP_NORMAL = 0x00000002
MODE_MONO = 0x00000020
MODE_STEREO = 0x00000040
MODE_MPEG = 0x00000200
MODE_IMAADPCM = 0x00400000
MODE_XMA = 0x01000000
MODE_XBOX_IMA = 0x20000000
MODE_PADDED = 0x10000000
SAMPLE_HEADER_MIN = 80


class FsbError(ValueError):
    pass


def codec_of(mode):
    if mode & MODE_XMA:
        return "xma"
    if mode & MODE_MPEG:
        return "mp3"
    if mode & MODE_IMAADPCM:
        return "xbox_ima" if mode & MODE_XBOX_IMA else "ima"
    return "pcm16"


def parse(data):
    """Return {nsamples, version, mode, samples: [{name, length, size, offset, loop_start, loop_end, mode, codec,
    frequency, channels, volume, pan, priority, extra}]}."""
    if data[:4] != MAGIC:
        raise FsbError("not an FSB4 bank")
    ns, shs, ds, ver, mode = struct.unpack_from("<5I", data, 4)
    p = 48
    data_off = 48 + shs
    off = data_off
    out = []
    for _ in range(ns):
        if p + SAMPLE_HEADER_MIN > len(data):
            raise FsbError("sample header past end")
        size = struct.unpack_from("<H", data, p)[0]
        if size < SAMPLE_HEADER_MIN:
            raise FsbError("short sample header %d" % size)
        name = data[p + 2:p + 32].split(b"\0")[0].decode("latin-1")
        ln, cs, ls, le, m, fr, vol, pan, pri, ch = struct.unpack_from("<5IiHhHH", data, p + 32)
        out.append({"name": name, "length": ln, "size": cs, "offset": off, "loop_start": ls, "loop_end": le,
                    "mode": m, "codec": codec_of(m), "frequency": fr, "channels": ch, "volume": vol, "pan": pan,
                    "priority": pri, "extra": bytes(data[p + 80:p + size])})
        off += (cs + 31) & ~31 if m & MODE_PADDED else cs
        p += size
    if off > len(data):
        raise FsbError("sample data past end of bank")
    return {"nsamples": ns, "version": ver, "mode": mode, "data_offset": data_off, "data_size": ds, "samples": out}


def sample_bytes(data, s):
    return bytes(data[s["offset"]:s["offset"] + s["size"]])


# ------------------------------------------------------------------------------------------------------- XMA

XMA_PACKET = 2048
XMA_BLOCK = 0x10000


def xma_riff(raw, channels, rate, nsamples):
    """RIFF/WAVE container with an XMA2WAVEFORMATEX header around raw XMA2 packets (decodable by ffmpeg)."""
    blk = XMA_BLOCK if len(raw) > XMA_BLOCK else max(len(raw), XMA_PACKET)
    nblk = (len(raw) + blk - 1) // blk
    streams = (channels + 1) // 2
    mask = 3 if channels == 2 else (4 if channels == 1 else 0)
    fmt = struct.pack("<HHIIHHH", 0x166, channels, rate, rate * channels * 2, XMA_PACKET, 16, 34)
    fmt += struct.pack("<HIIIIIIIBBH", streams, mask, nsamples, blk, 0, nsamples, 0, 0, 0, 4, nblk)
    body = b"WAVE" + b"fmt " + struct.pack("<I", len(fmt)) + fmt + b"data" + struct.pack("<I", len(raw)) + raw
    if len(raw) & 1:
        body += b"\0"
    return b"RIFF" + struct.pack("<I", len(body)) + body


# ------------------------------------------------------------------------------------------------ IMA ADPCM

IMA_STEPS = [
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97,
    107, 118, 130, 143, 157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658, 724, 796,
    876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024, 3327, 3660, 4026, 4428, 4871,
    5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623,
    27086, 29794, 32767]
IMA_INDEX = [-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8]
XBOX_BLOCK = 36            # bytes per channel per block: 4-byte header + 32 bytes of nibbles
XBOX_SAMPLES = 64          # samples per channel per block (header sample + 63 nibbles; the last nibble is unused)


def _ima_step(nib, pred, idx):
    step = IMA_STEPS[idx]
    diff = step >> 3
    if nib & 1:
        diff += step >> 2
    if nib & 2:
        diff += step >> 1
    if nib & 4:
        diff += step
    if nib & 8:
        diff = -diff
    pred = max(-32768, min(32767, pred + diff))
    idx = max(0, min(88, idx + IMA_INDEX[nib]))
    return pred, idx


def decode_xbox_ima(raw, channels, nsamples=None):
    """Decode Xbox IMA ADPCM to interleaved signed 16-bit samples (list of ints, channel-interleaved).

    Per block and channel: s16 predictor, u8 step index, u8 reserved, then 32 bytes of nibbles (low nibble first).
    Stereo blocks are 72 bytes: header L, header R, then 4-byte nibble groups alternating L, R."""
    if channels not in (1, 2):
        raise FsbError("xbox ima: %d channels" % channels)
    bsz = XBOX_BLOCK * channels
    out = []
    for b0 in range(0, len(raw) - bsz + 1, bsz):
        chans = []
        for c in range(channels):
            pred, idx = struct.unpack_from("<hB", raw, b0 + 4 * c)
            idx = min(idx, 88)
            nibs = []
            for g in range(8):                       # 8 groups of 4 bytes per channel
                q = b0 + 4 * channels + (g * channels + c) * 4
                for byte in raw[q:q + 4]:
                    nibs.append(byte & 15)
                    nibs.append(byte >> 4)
            pcm = [pred]
            for nib in nibs[:XBOX_SAMPLES - 1]:
                pred, idx = _ima_step(nib, pred, idx)
                pcm.append(pred)
            chans.append(pcm)
        for i in range(XBOX_SAMPLES):
            for c in range(channels):
                out.append(chans[c][i])
    if nsamples is not None:
        out = out[:nsamples * channels]
    return out


def wav_pcm16(samples, channels, rate):
    """RIFF/WAVE (PCM, 16-bit little-endian) from interleaved ints."""
    pcm = struct.pack("<%dh" % len(samples), *samples)
    fmt = struct.pack("<HHIIHH", 1, channels, rate, rate * channels * 2, channels * 2, 16)
    body = b"WAVE" + b"fmt " + struct.pack("<I", len(fmt)) + fmt + b"data" + struct.pack("<I", len(pcm)) + pcm
    return b"RIFF" + struct.pack("<I", len(body)) + body


def native_file(data, s):
    """(extension, bytes) of one sample in a container a browser or ffmpeg can open without loss:
    .xma.wav (XMA2 RIFF, needs ffmpeg to become PCM), .mp3, or .wav (decoded IMA / raw PCM16)."""
    raw = sample_bytes(data, s)
    codec = s["codec"]
    if codec == "xma":
        return ".xma.wav", xma_riff(raw, s["channels"], s["frequency"], s["length"])
    if codec == "mp3":
        return ".mp3", raw
    if codec == "xbox_ima":
        return ".wav", wav_pcm16(decode_xbox_ima(raw, s["channels"], s["length"]), s["channels"], s["frequency"])
    if codec == "pcm16":
        n = len(raw) // 2
        return ".wav", wav_pcm16(list(struct.unpack("<%dh" % n, raw[:2 * n])), s["channels"], s["frequency"])
    raise FsbError("unsupported codec %s" % codec)


def main(argv=None):
    argv = sys.argv[1:] if argv is None else argv
    for path in argv:
        with open(path, "rb") as f:
            d = f.read()
        b = parse(d)
        print("%s: %d samples" % (path, b["nsamples"]))
        for s in b["samples"]:
            print("  %-30s %-8s %6d Hz %d ch %9d samples %8d bytes" % (s["name"], s["codec"], s["frequency"],
                                                                       s["channels"], s["length"], s["size"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
