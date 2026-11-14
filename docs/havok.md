# Havok animation data (Top Spin 4, Xbox 360)

Status: skeletons and all three compressed animation codecs the game ships (spline,
delta, wavelet) decode, and the decoders were checked against the game's own
decompression routines in `Swing_DLL`. Skeletons and clips export to glTF 2.0.
Tools: `tools/havok/`. Tests: `tests/test_havok.py` (synthetic bytes only).

Everything below was measured on the retail disc
`orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso` with Python 3.14.6 and
capstone 5.0.7 (`work/venv`). `Swing_DLL.dll` SHA-256
`a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`. Function and data
addresses are virtual addresses in that image (base 0x88000000). This document
contains no game data and no reflection tables (section 4 explains how to generate them
locally). No SDK headers or source were used.

Related: `docs/gameplay/df.md` section 5 on the PR branch (Havok version, loader
functions, `Media\Animation\AOD\%u.hkx` naming). The facts here agree with it, with
these differences:

* The animation files are archive members, not loose AOD files. The
  `crc32("/media/animation/aod/<n>.hkx")` path hash in df.md 2.2 matched no entry in
  Core/Global/TopSpinAcademy/Baked_Federer0 for n < 200000 (see open items).
* Spline/delta/wavelet payloads are little endian inside a big-endian packfile.

## 1. Where the Havok files are

Archives are read in place with the disc agent's `tools/xdvdfs.py` + `tools/ts4_arc.py`
(read-only). `tools/havok/scan_arcs.py` decompresses the first LZX chunk of every entry
and looks for the packfile magic `57E0E057 10C0C010`. Every hit is a binary packfile
(no tagfiles), contents version `Havok-5.5.0-r1`, file version 5, layout rules
`04 00 00 01` (4-byte pointers, big endian, no padding reuse, empty-base optimisation).

| Archive (entry hash) | Unpacked size | SHA-256 of unpacked entry | Contents |
|---|---|---|---|
| `Core.arc` `6932352f` | 34,522,976 | `38bc2155cb32553d863424757b2b1ddbe0dd4c0443a22718bb8bbd6e96bd7b71` | "Merged Animation Container": 2 player skeletons (71 bones), 2914 spline + 2936 delta clips, 5850 bindings |
| `CutScenes.arc`: all 2093 entries (an uncompressed "PAM-NIL" archive; `tools/havok/scan_arcs.py` reads it with its own small reader because `ts4_arc.py` accepts only PAM-LZX), e.g. `0026b42b` | 97,792 (`0026b42b`); 17,104-804,256 bytes, 476,676,032 in total | `c2db32a91bcd19fe0141216c99cf3a33ffcc5f69f1d007bee3a729a0d2fcdb1b` (`0026b42b`) | one clip per file: 2092 wavelet clips (67 tracks, NORMAL) and 1 spline clip, each with its own 71-bone player skeleton. These are most likely the per-clip AOD animations (sizes stay under the 0xD2000 staging buffer in df.md 5.2). |
| `TopSpinAcademy.arc` `1539c50b` (same entry in every venue arc scanned so far: Amsterdam, ArthurAshe, Athens, Atlanta, Auckland) | 1,715,248 | `03666fc5ec0073d3be76b2053e7562a0a085f14949034e987c9c4d54c99b6faa` | tennis net rig: 2 skeletons (19 bones `B_Hips`, `Filet_D01..09`, `Filet_G01..09`), 384 wavelet clips |
| `Baked_<Player><n>.arc` (28 of 81 archives), one entry each (e.g. `Baked_Federer0.arc` `de2489a3`, archive name `Physics.hkx`) | 79,296 (Federer0) | `7387f298db38d13e6beff17f8d39c7d5b74459b38e34aadbd1fc42f5c31ff7c9` | ragdoll: hkpPhysicsData + hkaRagdollInstance with a 20-bone `Ragdoll_*` skeleton, carries a `__types__` section |
| `Global.arc`, 44 entries (e.g. `31cab425`) | 38-152 KB | `43be87aa219b13b637cade58266ca6a265ac6979413c98c0524bb3c8f5f484e9` (31cab425) | rigid-body physics props (hkpPhysicsData), with `__types__` |
| `TopSpinAcademy.arc`, 6 more entries | | | physics props, as above |

### Full-disc scan summary
`scan_arcs.py` covered every `.arc` on the disc. Output is in `work/havok/scan_main.txt`,
`scan_rest.txt`, `scan_rest2.txt` and `scan_cutscenes.txt`. Every Havok file found is a
5.5.0-r1 binary packfile; there are no tagfiles.

| Where | Havok files | Kind |
|---|---|---|
| `CutScenes.arc` | 2093 (every entry) | one clip each: 2092 wavelet + 1 spline, each with its own 71-bone skeleton |
| `Core.arc` | 1 | merged container: 2914 spline + 2936 delta clips |
| `TopSpinAcademy.arc`, the 38 venue arcs, `PracticeGroundPart.arc` | 6 each: the net rig `1539c50b` (wavelet) + 5 physics files (entries `db0ddc52`, `762e762e`, `bde8ab04`, `01339b3a` and one more recur across venues) | net animation, venue physics |
| `Global.arc` | 44 | physics props |
| `Baked_<Player><n>.arc` | 1 in each of 28 of the 81 archives (the others name no `Physics.hkx`) | player ragdoll (`Physics.hkx`) |
| `PlayerCreator_Female.arc` / `PlayerCreator_Male.arc` | 37 / 24 | ragdoll + physics |

Unreadable entries: `Core.arc` `3fb95789`, and `1525a0bc` / `f0c715bc` in both
`PlayerCreator_Common.arc` and `PlayerCreator_Male.arc`. All fail in the shared LZX
decoder ("bad block type 7"), so whether they are Havok is unknown.

## 2. Packfile layout (as measured; `tools/havok/packfile.py`)

```
0x00 u32 magic 0x57E0E057, u32 magic 0x10C0C010, u32 userTag (0), u32 fileVersion (5)
0x10 u8 layoutRules[4] = 04 00 00 01
0x14 u32 numSections (3), contentsSectionIndex (2), contentsSectionOffset (0),
     contentsClassNameSectionIndex (0), contentsClassNameSectionOffset
0x28 char[16] "Havok-5.5.0-r1", 0x38 u32 flags (0xFFFFFFFF here), 0x3C pad
0x40 3 section headers of 0x30: char[20] name (NUL padded, last byte 0xFF),
     u32 absoluteDataStart, then section-relative local, global, virtual, exports,
     imports, end offsets
```
* Sections are `__classnames__`, `__types__`, `__data__`. `__classnames__` entries are
  `u32 signature, 0x09, name, NUL`, terminated by 0xFF padding.
* Fixup tables (section relative, rows starting with 0xFFFFFFFF are padding): local
  `(src, dst)`, global `(src, dstSection, dst)`, virtual `(objOffset, classNameSection,
  classNameOffset)`. Pointers on disk are 0 and are resolved only through these tables.
  Every object whose class has a vtable or is a top-level object has a virtual fixup,
  including non-virtual `hkaSkeleton`/`hkaBone`/`hkaAnimationBinding`.
* `__types__` is empty in the animation files. In the physics files it holds the
  reflection objects (`hkClass` 0x30, `hkClassMember` 0x18, `hkClassEnum` 0x14,
  `hkClassEnumItem` 8, record formats in `tools/havok/classes.py`), so `--types`
  prints those files' own class layouts.
* Counts for Core `6932352f`: local 17,684, global 17,695, virtual 11,846 fixups,
  33 class names.

## 3. Object graph

`hkRootLevelContainer.namedVariants[0]` = {"Merged Animation Container",
"hkaAnimationContainer", variant} (Core). The container's `animations[i]` and
`bindings[i]` correspond one-to-one. There is no `originalSkeletonName` in 5.5, so a
binding does not name its skeleton. Both Core skeletons have the same 71 bone names
(different reference poses); the exporter defaults to skeleton 0 (`--skeleton`).
Spline clips have 27 or 67 (rarely 38) transform tracks and NORMAL blend. Every delta
clip is ADDITIVE, 11 poses, 0.166 s. No clip has float tracks, annotation tracks or
extracted motion.

## 4. Class layouts (generated locally, not in the repository)

The animation packfiles have an empty `__types__` section, so the reader needs the
member tables (names, offsets, types) of the Havok classes. Those tables are the Havok
runtime's reflection data compiled into the game executable. Like the branch's
`work/havok55_classes.json` (df.md 5.4/5.5), they are SDK-derived, so they stay local
and are never committed. Regenerate them from your own executable:

```
work/venv/bin/python tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll   # -> work/havok/classes.json
work/venv/bin/python tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll --print hkaSkeleton  # inspect
```
`dll_classes.py` finds every call to the hkClass constructor (0x8841F080, 10,401 call
sites). For each call it replays the initialiser's `lis/addi/li/ori/mr/stw`
instructions to recover the arguments: name, parent, objectSize, enums, and the
members pointer and count stored to the stack. It keeps the 352 classes with a non-zero
objectSize, decodes their member and enum records from `.rdata`, and writes JSON.
`tools/havok/classes.py` loads `work/havok/classes.json` (or `$HAVOK_CLASSES`) at run
time. If the file is missing, `hkx.py` exits with a message naming the command above.
Files that carry their own `__types__` (physics) are decoded from that section.

Notes from generating the table:
* The member records' enum pointers are 0 in the image. When a class declares exactly
  one enum, the generator assigns it to that class's ENUM members. 26 ENUM members of
  classes with several enums stay unnamed and decode as integers.
* The generated sizes match the object spacing measured in Core `6932352f`.
* The reflection *record* formats (hkClass 0x30, hkClassMember 0x18, hkClassEnum 0x14,
  item 8) are described in `classes.py`. They were measured from the physics files'
  `__types__` sections.
* `staticMaskSize`/`staticDOFsSize` in delta clips hold garbage (0xFFFFFFFF or
  uninitialised floats). The runtime does not read them; the sizes come from the masks.
* Vtables (via RTTI type descriptors): spline 0x8803AE14, delta 0x8803A844, wavelet
  0x8803B244.

## 5. Codecs

All index fields are offsets into the clip's own byte buffer. Every multi-byte value
inside `data`/`dataBuffer` is little endian (spline `endian` = 0). The game's routines
byte-swap these values as they read them (e.g. the swap helpers at 0x88516B60..).

### 5.1 Spline (`tools/havok/spline.py`)
Used by 2914 Core clips. Block b starts at `blockOffsets[b]` and has
`floatBlockOffsets[b]` bytes of transform data. Blocks are padded to 16 bytes.

* Masks: 4 bytes per transform track `(quant, pos, rot, scale)`. In `quant`, bits 0-1
  are the position scalar quantisation (0 BITS8, 1 BITS16), bits 2-5 the rotation
  quantisation, bits 6-7 the scale quantisation. In pos/scale, bit i (x, y, z) marks a
  static component and bit 4+i a spline component. Rotation is a spline if any of bits
  4-7 is set, else static if any of bits 0-3 is set, else identity. Every track in the
  game uses quant `0x04`: BITS8 positions, THREECOMP40 rotations.
* Data starts at `blockOffsets[b] + maskAndQuantizationSize`. For each track: position,
  align 4, rotation, align 4, scale, align 4 (block sampler, 0x88412C54-0x88412E00).
* Spline header (0x88411D50): u16 numItems (control points - 1), u8 degree, then
  numItems+degree+2 u8 knots in frames. The game turns knots into seconds with a
  0..255 float table times frameDuration.
* Vector track (0x88412508): optional header, align 4, then for x, y, z: static → f32,
  spline → f32 min, f32 max. Then align 2 and (numItems+1) control points, each holding
  the spline components in order, quantised as u8 × 1/255 (0x8800238C) or
  u16 × 1/65535 (0x88001B00) and mapped into [min, max].
* Rotation track (0x884123E0, 0x88411E28): optional header, align to the quantisation's
  alignment, then (numItems+1) quaternions (or one if static). The alignment and size
  tables are at 0x8803C040 and 0x8803C058: POLAR32 4/4, THREECOMP40 1/5,
  THREECOMP48 2/6, THREECOMP24 1/3, STRAIGHT16 2/2, UNCOMPRESSED 4/16. Decoder table at
  0x88B3BBA0.
* THREECOMP40 (0x885168B8): the 5 bytes are a little-endian 40-bit integer. Bits 0-11,
  12-23 and 24-35 are three components, each `q * 0.00034543566 - 0.70710677`
  (constants 0x8808DE10 / 0x8808DE20 = 1/(2047·√2), −1/√2). Bits 36-37 are the index
  of the dropped component, bit 38 its sign. The dropped component is
  √(1 − a² − b² − c²). The three stored components keep their order: the VMX128
  `vpermwi` immediates 0xC6/0x36/0x1E for index 0/1/2 decode to (·,a,b,c), (a,·,b,c)
  and (a,b,·,c).
* Sampling (0x88413498): `block = clamp(int(t·blockInverseDuration), 0, numBlocks−1)`,
  `tl = t − block·blockDuration`. The knot span is found with the integer local frame
  (binary search 0x88411C40). The curve is the standard B-spline basis sum over
  `degree+1` control points, evaluated by a per-degree function table at 0x88B3BBB8.
  Rotations are normalised after evaluation.

### 5.2 Delta (`tools/havok/delta.py`)
Used by 2936 Core clips (all additive).
* `staticMaskIdx`: one u16 mask per transform track (then per float track). Pose
  assembly 0x884165B0 reads it this way. Position: `(m & 3) == 2` → identity, else x, y,
  z come from the dynamic channels if m bit 8, 7, 6 is set, otherwise from the static
  DOFs. Rotation: `(m>>2 & 3) == 2` → identity, else x, y, z, w are dynamic if m bit 12,
  11, 10, 9 is set. Scale: `(m>>4 & 3) == 2` → (1,1,1), else x, y, z dynamic if m bit
  15, 14, 13 is set. Statics and dynamics are consumed in the order pos xyz, rot xyzw,
  scale xyz, track by track.
* A stored rotation w of exactly ±2.0 is a placeholder. The game replaces it with
  `±sqrt(1 − min(1, x²+y²+z²))` (constant 2.0 at 0x8803C288, `fsqrts` at 0x88416760).
  Every static rotation in the game data uses this form.
* Dynamic channels (block decoder 0x8840B8D8, called from 0x8840C4A8): per channel,
  `preserved` raw f32 values, then bw-bit codes in an LSB-first bit stream read as
  little-endian u16 words (0x88515830). A value is
  `(q + 0.5)·scale·2^-bw + offset`: the 2^-bw table is at 0x8808DCB8, the 0.5 at
  0x88001978, and scale/offset come from `scaleIdx`/`offsetIdx`. The bytes used per
  channel are `4·preserved + ceil((n − preserved)·bw/8)` (0x88515018). A prefix sum
  `v[i] += v[i−1]` follows (0x88515620). The sampler interpolates linearly between
  frames (0x8840C750..).
* In the game data every delta clip has one block, preserved = 1, bw = 10, and all
  scales are 0. The dynamic channels are therefore constant at their preserved values,
  so the prefix-sum path is confirmed only from the code, not by data.

### 5.3 Wavelet (`tools/havok/delta.py`)
Used by 384 net clips. It uses the same mask, static and channel conventions as delta.
`blockIndexIdx` lists blockIndexSize u32 byte offsets (relative to `quantizedDataIdx`),
one per block of `blockSize` poses (32 or 16).
* Per channel and block (0x88413FF8), the zero code is
  `z = int(−offset/scale · 2^bw)`, with 1 subtracted if z = 2^bw. The entropy stage
  (0x885207C8) reads `preserved` f32 values, then an n-bit "zero" mask (LSB first), then
  bw-bit codes for the entries that are not zero. Bytes used:
  `ceil((32·preserved + n + bw·nonzero)/8)`. The codes are then dequantised as in delta.
* Inverse transform (0x8851FDE0): inverse CDF 5/3 lifting, at each level s → 2s:
  `even[i] −= 0.25(odd[i−1]+odd[i])`, `even[0] −= 0.5·odd[0]` (0x885205D8 with −0.25),
  `odd[i] += 0.5(even[i]+even[i+1])`, `odd[s−1] += even[s−1]` (0x885204D8 with 0.5),
  then interleave. The game starts at size 8 with a precomputed 8×8 matrix
  (0x8808DE60..0x8808DF10). The generic recursion reproduces every entry of that
  matrix (checked in `tests/test_havok.py` and by hand).

### 5.4 Not used by the game data
POLAR32, THREECOMP48, THREECOMP24 and STRAIGHT16 rotations, BITS16 positions, float
tracks, interleaved/mirrored clips and extracted motion. The decoders for these are
absent or marked as not verified (`decode_threecomp48` is a guess).

## 6. Verification (reproducible on a local disc image)

| Check | Result |
|---|---|
| Spline: every block parses to exactly `floatBlockOffsets[b]` bytes, and the next block starts at the 16-byte aligned end | 3019/3019 blocks |
| Spline: frame-0 local rotation vs skeleton 0 reference pose, |q·r| (200 clips, 27 tracks each) | median 0.981; position distance median 0.0 |
| Spline: consecutive-frame rotation |dot| | median 0.999992, min 0.986 |
| Spline world-space sanity (`skeleton.world_matrices`) | head ≈150-160 cm, hips ≈90-100 cm, feet ≈11-25 cm, racket handle at the right hand |
| Delta: masks give exactly numD dynamic channels and the static DOF count fills `staticDOFsIdx..offsetIdx` | 2936/2936 |
| Delta: channel bytes sum to `totalBlockSize` and the buffer ends there | 2936/2936 |
| Wavelet: every block's channels consume exactly up to the next block index / `quantizedDataSize` | 852/852 blocks |
| Wavelet: zero code inside [0, 2^bw] for every channel (offset/scale roles) | 25241/25241 |
| Wavelet: consecutive-frame rotation |dot| | median 0.9995, 0.12 % of steps < 0.95 (fast net motion; lossy coding) |
| CutScenes wavelet clips (40 random files): byte consumption per block | 1861/1861 blocks exact; frame-to-frame rotation |dot| median 1.000000, p01 0.9992; head 22-62 cm above hips mid-clip |
| glTF: accessor sizes match buffer views and every output rotation is unit length | all exported clips |

Exports made (local only, `work/havok/export/`): `core_player.gltf` (skeleton 0 +
spline clips 0, 1, 2, 10, 100 + delta 2000, 5000), `core_player_skel1.gltf`,
`academy_net.gltf` (wavelet clips 0, 1, 2, 200), `cutscene_0026b42b.gltf` and
`cutscene_008875f7.gltf` (one 67-track wavelet clip each), and `federer0_ragdoll.gltf`
(skeleton only).

## 7. Reproduction

```
P=work/venv/bin/python; ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
$P tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll      # once: writes work/havok/classes.json
$P tools/havok/scan_arcs.py "$ISO" --arc Core.arc --arc Global.arc --arc TopSpinAcademy.arc
$P tools/havok/hkx.py --iso "$ISO" --arc Core.arc --entry 6932352f --save work/havok/core_6932352f.hkx --info
$P tools/havok/hkx.py work/havok/core_6932352f.hkx --dump-skeleton 0
$P tools/havok/hkx.py work/havok/core_6932352f.hkx --list-clips
$P tools/havok/hkx.py work/havok/core_6932352f.hkx --export-gltf work/havok/export/core_player --clips 0,1,2,10,100,2000,5000
$P tools/havok/hkx.py --iso "$ISO" --arc TopSpinAcademy.arc --entry 1539c50b --export-gltf work/havok/export/academy_net --clips 0,1,2,200
$P tools/havok/scan_arcs.py "$ISO" --arc CutScenes.arc
$P tools/havok/hkx.py --iso "$ISO" --arc CutScenes.arc --entry 0026b42b --export-gltf work/havok/export/cutscene_0026b42b --clips 0
$P tools/havok/hkx.py --iso "$ISO" --arc Baked_Federer0.arc --entry de2489a3 --types   # reflected layouts
$P tools/havok/ppcdis.py 0x885168B8 --count 64                                          # THREECOMP40 decoder
$P -m unittest tests.test_havok
```
`work/havok/classes.json` and `ppcdis.py` output are derived from the executable, so
keep them under `work/` and do not commit them. `ppcdis.py` is a small capstone wrapper
written for this work (it is not the branch's Rust ppcdis). It prints VMX128 opcodes as
raw words; those were decoded by hand where needed (section 5.1).

## 8. Open items

* Clip names and ids: the merged container has no names. Mapping clip index to the
  `Animations.bin` records (df.md 3) and to `Media\Animation\AOD\<id>.hkx` is not done.
  The archive path hash in df.md (crc32 of the lower-cased path) matched none of the
  archive names tried, so the archive's name→hash function is still unknown.
* The Havok additive-blend convention used for export (t_ref + t, r_ref·r, s_ref·s) is
  an assumption. It has not been checked against the game's blender. Use
  `--raw-additive` to export the raw deltas instead.
* Five archive entries cannot be read because of LZX "bad block type 7" errors in the
  shared decoder (section 1).
* The 2093 `CutScenes.arc` clips are probably the AOD clips, but the link to clip ids is
  not established.
* Which of the two Core skeletons (male/female?) goes with which clip is not known.

## 9. Public references

Background on the general Havok packfile and animation-compression vocabulary came from
open-source, openly licensed readers: HavokLib (PredatorCZ, GPL-3.0,
github.com/PredatorCZ/HavokLib) and the modding-community hkx documentation. They were
used for terminology only. Every bit layout above was re-derived from the game's files
and checked against the `Swing_DLL` routines listed. No Havok SDK material was used.
