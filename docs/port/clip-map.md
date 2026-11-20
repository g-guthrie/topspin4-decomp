# Swing record to Havok clip map (`tools/port/clip_map.py`)

Agent `clipmap`. Question: which Havok clip plays each of the 3,184 `AnimationsDB.bin` records? The container in
`Core.arc` (entry `6932352f`: 5,850 clips, no names) and the 2,093 per-clip packfiles in `CutScenes.arc` carry no
record names. Answer: the database itself holds the link, in two arrays that earlier notes had classed as unknown
(`HkxList`, `ExtractPositionList`). All 3,184 records resolve; 3,183 are confirmed by an exact frame count match.

Measured on the retail disc image `orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso` with Python 3.14.6, standard
library only. `Swing_DLL.dll` function addresses are virtual addresses (base 0x88000000). No game data is in this
file beyond the animation names the repository already documents.

## 1. The mechanism

Root struct of `AnimationsDB.bin` (type `0xEE710815`, root at file offset 0x14). Three arrays are used, each a 12-byte
self-relative descriptor `{rel, count, cap}` (element address = descriptor address + rel):

| Root offset | Array | Count | Element | Fields used |
|---|---|---|---|---|
| +0x50 | `TakeList` (the "records") | 3,184 | 0x8C bytes | `+0x14` f32 clip length in frames, `+0x1C` u32 tag, `+0x5C` `{rel, type}` poly object, `+0x84` id = crc32(name) |
| +0x60 | `HkxList` | 7,306 | 0x1C bytes | u16 `+0` k0, u16 `+2` c, u16 `+4` k1 (rest: pre-event window start/count and floats, not needed here) |
| +0x6C | `ExtractPositionList` | 1,904 | 0x10 bytes | u32 `+0` AOD clip id (entry 0 is the null entry, id 0) |

Lookup chain (Swing_DLL):

1. `fn_886C8438(db, id, tag)` scans `TakeList` (stride 0x8C) for the record whose `+0x84 == id` and `+0x1C == tag`.
   `fn_886C84B8` is the wrapper that calls it and then `fn_886C5230`. Of the 3,184 records 17 repeat an (id, tag)
   pair, so the first match wins at run time; the map below is keyed by record **index**, not by name.
2. `fn_886C5230(db, record, variant)` returns the 0x10-byte `ExtractPositionList` entry for a record. If
   `record+0x60 == 0xA0B2A282` the poly object is the clip object itself; otherwise `record+0x5C` points at
   `{rel, count, cap}` and element `variant` (8 bytes `{rel, type}` at poly+rel+8*variant) points at a clip object.
   In both cases it reads the **s16 at clip-object +0x0C = HkxList row index**, then the **u16 at HkxList row +0** (k0)
   and returns `ExtractPositionList + 0x10 * k0`.
3. The 16-byte entry is the "AOD clip": its u32 `+0` is the id formatted by `fn_886D2B58` into
   `Media\Animation\AOD\%u.hkx` (docs/gameplay/gp7.md section 8). The request key built in `fn_886CE5B0` /
   `fn_886D7C28` (0x14-byte rows of the AOD request list at AnimationData root `+0x1F4`) is `{id, tag, done flag,
   -, variant}`. `fn_887DD610` is a caller that builds an animation node from the entry.

For the 2,223 records whose row has k0 = 0 the entry is the null entry (id 0), so no file is streamed: the clip is
resident, and it is the Core container clip number in the same row (u16 `+2`). This half of the chain (row `+2` is the
index into the merged container, row `+4` is a second, appended AOD clip) is **not** read from a function; it was found
in the data and is the content of the verification in section 3. The tool applies these rules:

| Row (k0, c, k1) | Plays | Records |
|---|---|---|
| k0 = 0, k1 = 0 | Core clip `c` (index into the merged container, `anims` order of `tools/havok/skeleton.load`) | 1,776 single + 367 sets + 126 blends (via their rows) |
| k0 != 0 | AOD file `ExtractPositionList[k0].id` in `CutScenes.arc` (`c` unused, 0) | 221 single, 247 list records |
| k0 = 0, k1 != 0 | Core clip `c` (a lead-in, 41-259 frames, spline) **then** AOD file `ExtractPositionList[k1].id` | 447 single |

Poly object types of `record+0x60` (all 3,184 are one of four):

| Type | Count | Layout | Meaning |
|---|---|---|---|
| `0xA0B2A282` | 2,444 | clip object, u16 row at `+0x0C` | one clip |
| `0x2DB2D90F` | 367 | `{rel=0x20, count=9, cap}` then 9 u16 HkxList rows | variant 0 is the full clip (f14 == its frame count); variants 1-8 are the additive 11-pose delta clips. Each of the 2,936 delta clips belongs to exactly one set (367 x 8) |
| `0xC4BAA666` | 247 | `{rel=0xC, count=5}`, elements `{rel, 0xA0B2A282}` | 5 interchangeable variants, all AOD (cut scenes and "Corridor" clips) |
| `0x8361F2CA` | 126 | `{rel=0x14, count=2}`, elements `{rel, 0xA0B2A282}` | two clips to blend; the record's frame count is their mean (half rounds to even); jog/step IK clips |

AOD file name to archive key: `CutScenes.arc` is a `PAM-NIL` archive whose single directory has hash
`0x12ACB5B9 = crc32("/media/animation/aod/")` and 2,093 leaf names `<id>.hkx` (decimal u32). Entry key =
`crc32("<id>.hkx", dir_hash)` (docs/disc-data.md section 2), implemented as `aod_entry_key()`. This also resolves
docs/havok.md's open item: the earlier search failed because it enumerated small numbers `n`, but the ids are crc32 values.

AOD clip ids are `crc32` of the bracketed dictionary strings in `AnimationsDBcrc.bin`, for example
`[19734] Cutscene_Sitting_00:Cutscene_Sitting_00_Scale5 - s08_d01_012_001`: all 1,903 ids in `ExtractPositionList` resolve
to such a name, which therefore names the CutScenes clip (`aod_name` in the output).

## 2. Output and coverage

`work/port/assets/clip_map.json` (2.1 MB, local only):

```
{ "summary": {...}, "map": {"#<record index>": "core:<n>"},
  "records": [ { "index", "id", "name", "tag", "poly", "frames", "method", "confidence", "primary",
                 "variants": [ {"kind": "core" | "aod" | "core+aod", "row", "clip", "core_index",
                                "aod_index", "aod_id", "aod_key", "aod_name", "frames"} ] } ] }
```

`method` is `hkxlist-core`, `-aod`, `-core+aod`, `-set`, `-variants` or `-blend`. `confidence`: `exact` = the record's
frame count equals the Havok frame count of the chain (Core clip, AOD clip, their sum, the mean for blends, the base
clip for sets plus all additive layers being delta clips), `structural` = chain decoded but frame table unavailable
(`--no-cutscenes`), `mismatch` = decoded but disagrees.

| Method / kind | Records | Confidence |
|---|---|---|
| single, one Core clip (`hkxlist-core`) | 1,776 | exact (1,776 / 1,776) |
| single, Core lead-in + AOD (`hkxlist-core+aod`) | 447 | exact: record frames == Core frames + AOD frames, 447 / 447 |
| single, AOD only (`hkxlist-aod`) | 221 | exact, 221 / 221 |
| set of 9 (`hkxlist-set`) | 367 | exact: base clip frames, 8 additive delta clips each |
| 5-variant list, AOD (`hkxlist-variants`) | 246 + 1 | 246 exact; 1 mismatch (index 3025, see below) |
| two-clip blend (`hkxlist-blend`) | 126 | exact, 126 / 126 |
| **total** | **3,184** | **3,183 exact, 1 mismatch** |

All 1,638 `Swing_*` records resolve: 1,253 single Core clips, 367 sets, 18 Core lead-in + AOD (the long miss and
return-to-rally swings). `map` holds the 2,143 records that one Core clip plays on its own (1,776 + 367 sets, variant 0);
`tools/port/export_assets.py --clip-map auto` links exactly these into `animations.json` (`records[].clip`). Core clip
use: 5,778 of 5,850 clips are referenced, none twice among single/set rows; coverage of AOD: 1,903 of the 2,093 files.

### Unresolved
* Record 3025 `Cutscene_Repostionning_PosNeg_Low_NonTired_XXX_00` (a 5-variant list): the record says 241 frames, all
  five AOD variants have 377. The chain is the same as for the other 246, so the record length is probably trimmed in
  the data.
* 72 Core spline clips (indices such as 1, 3, 4, 5, 27, 28, 95, 96) are referenced by no record. Probably used by a
  database this tool does not read (`Animations.bin` / `AnimationsInterface.bin` in venue archives, `SbikAnimationDB`).
* 190 of the 2,093 `CutScenes.arc` clips are not in `ExtractPositionList` (same candidates).
* What the 8 additive clips of a set are (per-direction or per-quality layers) and their blend weights. Which of the two Core
  skeletons a clip belongs to is still open (not part of this link).
* The `+2` / `+4` row fields (Core index, appended AOD clip) are inferred from frame counts and the racket check,
  not from a reader function. A function that reads row `+4` was not located.
* `time` values of annotations are a normalised phase of the clip (see 3); `tag` (`+0x1C`, two values) was not decoded.

## 3. Verification

1. **Frame counts.** Record `+0x14` is the clip length in frames. Counting a record as verified when it equals the Havok
   frame count of its clip chain (Core `numFrames`, wavelet `numberOfPoses`, from `work/port/assets/animations.json` or the
   container, and `work/port/cache/cutscene_meta.json`, filled by reading all 2,093 CutScenes headers, about 7 minutes
   once): 3,183 of 3,184. Each clip is also used once only: no Core clip appears in two single records.
2. **Independent check that does not use the frame counts** (`--verify-racket N`). The `EventRacket` annotation value should
   be the phase of the clip where the racket handle (`B_Racket_Handle`, skeleton 0) moves fastest. For 60 random `Swing_*`
   single-clip records the median |EventRacket - speed-peak phase| is 0.023; pairing the same values with randomly shuffled
   clips gives a median of medians of 0.077 (minimum over 200 shuffles 0.050). An earlier 40 record run gave 0.021 vs 0.074.
   So the mapping is not a coincidence of lengths, and EventRacket values (0.06-0.68) are phases (clip fraction), not
   60 Hz ticks.
3. `python3 -m unittest tests.test_clip_map` (synthetic buffers: array walking, all four poly types, row kinds, frame sums,
   AOD key, annotation reader, speed peak) and `tests.test_port_export` pass.

Reproduce:

```
ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
python3 tools/port/clip_map.py --iso "$ISO" --verify-racket 60      # needs work/havok/classes.json for the racket check
python3 tools/port/export_assets.py --iso "$ISO" --only animdb --clip-map auto
```

## 4. For the port

* Swing records to clips: `records[i].variants[0].clip` (Core) or `aod_key` (CutScenes entry key, read it with
  `tools/havok/scan_arcs.py`'s `NilArc`; the AOD clips are wavelet clips with their own 71-bone skeleton).
* A record with `kind = core+aod` is two clips played back to back: Core clip c, then the AOD clip; time-scale the record
  as a whole over the summed frame count. Sets play variant 0 with the 8 additive clips as layers (weights unknown).
* Contact: the `EventRacket` time is a fraction of the (summed) clip length.
