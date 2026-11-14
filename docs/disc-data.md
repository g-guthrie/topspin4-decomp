# Disc data: containers and records

Agent `disc`. Everything here was measured on the retail disc image
`orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso`
(7,838,695,424 bytes, SHA-256 `93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c`)
with Python 3.14.6 and only the standard library. No game data is stored in the repository; all
extracted output goes to `work/disc/` (git-ignored).

## Status summary

| Priority item | Located? | Decoded? |
| --- | --- | --- |
| 1 shot templates | Yes: `Core.arc` entries `Settings.bin` (286,492 B, 55 rows: kind `0xC1965E5C` x27, `0x5D90675B` x28) and `State.bin` (273,746 B, kind `0x50B89452` x2). Kind `0x2DB3EB6F` occurs in no `.bin` on the disc. | Value pointers decoded (172 constants, 117 curve20 curves, 7 2-D tables in Settings; row grouping is by address window, row field roles per df.md are unconfirmed) |
| 2 analyser graphs/curves | Engine framework identified; `AnalyserFrameworkModule.bin` (Core.arc, 31,250 B stored) exists, not decoded. | no |
| 3 reach / prep / turn tables | The 7 `7A330099` 2-D tables in `Settings.bin` (the df.md 4.4 form used by the movement/reach code) and animation event times in the swing AnimationDB. | tables decoded structurally; meaning not assigned |
| 4 swing-selection weights | Probably in the swing AnimationDB (`AnimationsDB.bin`) and `Settings.bin`; not isolated. | no |
| 5 player stat curves | Stat names are in `CommonCRCDictionnary.bin`; curves not isolated (candidates: the other `Settings.bin` pointers, `PlayerEvolution.bin` 4,920 B). | no |
| 6 ball constants / bounce curves | Probably the `Settings.bin` / `State.bin` constants and curve20 keys (df.md 4.2 bounce slots); not assigned. | no |
| 7 animation records | Yes: `AnimationsDB.bin` in `Core.arc`, 3,184 records of 0x8C bytes, all names resolved. | records decoded (id, slot, annotations, segments) |

Fully decoded: the disc layout (XDVDFS), the `.arc` container including entry names (XDVDFS), the `.arc` container, its LZX compression, the CRC dictionary
records, the XBin header and self-relative array convention, the layout-file root table and field
descriptors, and the swing AnimationDB top-level structure. The schema layer that would let every
XBin instance be decoded generically (the Layoutall type records) is only partly understood, and that
is what blocks items 1 to 6.

## 1. Disc layout

* The image is a video partition followed by an XDVDFS game partition. `tools/xdvdfs.py` probes the
  known partition offsets and accepts the first where sector 32 of the partition begins with the
  20 bytes `MICROSOFT*XBOX*MEDIA`. Here: partition offset `0xFD90000` (XGD2), root directory sector
  1,783,933, root size 6,144 bytes. 265 entries (files and directories).
* Volume descriptor (2048 bytes at partition sector 32): magic (20 B), u32 LE root sector at +0x14, u32 LE
  root size at +0x18.
* Directory entry (little-endian): u16 left, u16 right (offsets in 4-byte units inside the directory
  table, forming a binary search tree by name), u32 sector, u32 size, u8 attributes (0x10 = directory),
  u8 name length, name bytes; entries padded to 4 bytes; padding is `0xFFFF`.
* Files of interest on disc (all at the root): `Core.arc` (36,997,962 B), `Global.arc` (128,858,124 B),
  `GlobalMem.arc` (1,606,759 B), 43 venue archives, `Baked_*.arc` (81), `Layoutall.bin` (760,816 B),
  `CoreTech_Xenon.bin` (65,864 B), `Swing_DLL.xex`, `Loader_DLL.xex`.

SHA-256: `Core.arc` 7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50,
`Global.arc` 4c59cfdb3026101564b3062b11a4ece68f5b58db345b416351e01246f7919965,
`GlobalMem.arc` 996d5eb0062e1acc1fd1baefa8749dc567e64711211eae9921622d9cdb68237f,
`Layoutall.bin` 67793f5b7dc771f8fde298ef07e8976d9362c864ac577a4c9db6b2bf874788c5,
`CoreTech_Xenon.bin` aaa269c428ab21a884dabac5540cc0c064e1b3a2b85a19f3d8f44acd827c2a97.

`CutScenes.arc` (478,857,216 B) has a different header and is not decoded. The patch resources named in
`docs/title-server-patch.md` are not on the disc.

## 2. `.arc` container (`tools/ts4_arc.py`)

All integers big-endian. 144 of 145 `.arc` files parse with this layout.

```
0x00 u32 header_size_minus_4      data area starts at this + 4
0x04 u32 table_offset_minus_4     always 0x20  (entry table at 0x24)
0x08 u32 count, 0x0C u32 count    number of entries
0x10 u32 aux_offset               start of a secondary index, minus 0x10
0x14 u32 nnames, 0x18 u32 nnames  number of names
0x1C 8B  "PAM-LZX\0"               compression tag of the archive
0x24 count x { u32 key, u32 offset, u32 stored_size }   sorted by key; offset is relative to the data area
...  secondary name index, then a NUL-separated name pool (names exist for roughly 60-90% of entries)
```

* The `key` is `zlib.crc32` of the lower-cased, `/`-normalised path with a leading `/` (the branch spec,
  df.md 2.2, is **confirmed**; my earlier tests failed only because they hashed bare file names).
  Verified: 33 literal path strings from the executable hit entry keys. The secondary index at
  `0x10 + aux_off` is the directory table: `nnames` records of 16 bytes `{s32 rel, u32 count, u32 count,
  u32 dir_hash}` (sorted by dir_hash, df.md "directory table" confirmed). Each record points at `count`
  8-byte children `{s32 rel_to_name, u32 ?}` whose NUL-terminated leaf names live in the name pool.
  `dir_hash` is the CRC of the lower-cased directory path **including its trailing `/`**, so the entry key
  of a child is just CRC continuation: `zlib.crc32(leaf_name.lower(), dir_hash)`. This resolved 1,250 of
  1,250 `Core.arc` entries, 708 of 708 `Amsterdam.arc` and 4,174 of 4,174 `Global.arc`; `tools/ts4_arc.py --list`
  prints the leaf name for every entry. Full directory paths are not stored (only their hashes), so two
  files with the same leaf name in different directories (e.g. `Physics.bin`) are told apart by key only.
* Totals: 38,877 distinct keys over 144 archives (Global 4,174; Core 1,250; GlobalMem 255).

### Stored entries (`PAM-LZX`)

```
8B  "PAM-LZX\0"
u32 nchunks, u32 window (1 MiB), u32 last_chunk_usize, u32 total_usize
12B digest (starts 0x139CB3FF for nchunks == 1)
u32 hdr_len                      = 36 + 8 * nchunks, offset of the first frame
(nchunks-1) x u32                start offset of chunks 2..n from the blob start
nchunks x u32                    per-chunk checksum (not verified)
chunks: each is an independent LZX stream (state reset), 1 MiB of output; the last chunk is the remainder.
        Every chunk ends with 5 zero bytes.
frames: 0xFF, u16 usize, u16 csize   (5-byte header, used for a short frame and sometimes for a full one)
        or u16 csize                 (usize = 0x8000)
        followed by csize bytes of LZX data
```

Entries without the tag are raw. Verified by decompressing all of `GlobalMem.arc` (255 entries,
8,005,991 bytes) and all of `Core.arc` (1,250 entries) without error, and by the recovered contents being
well-formed (DDS and XPR2 textures, HLSL text, Lua 5.1 bytecode, XBin images).

### Compression: LZX (the branch spec says zlib: wrong)

The frame payloads are Microsoft LZX (the CAB/XMemCompress bitstream) with a 1 MiB window (20 bits, 42
position slots), 32 KiB frames, 16-bit little-endian bit words, verbatim and aligned-offset blocks. The
Intel E8 header bit was 0 in all samples. A standard decoder (libmspack `lzxd`, or any `xcompress`
tool) can decode the frames once the wrapper above is stripped. `tools/ts4_lzx.py` is a pure-Python
decoder (about 1 MB/s). Function addresses: not recovered; `CCompressorLzx` is registered at
`0x88888338` area (script/class registration only) and the string `PAM-LZX` does not appear in the
executable (the tag check was not found).

## 3. XBin images (`tools/ts4_xbin.py`)

Most data entries are XBin: relocatable memory images, big-endian, signature `a, b` where `b` is
`zlib.crc32` of the root type name (e.g. `Pam::SwingAnimation::AnimationDB::AnimationDB` is
`0xEE710815`). Header: u32 a, u32 b, u32 version (4, or 0x10 for the swing AnimationDB), u32 0,
u32 `0xFFFFFFFF`; the root structure starts at `0x14`. Pointers and arrays are self-relative:
an array descriptor is 12 bytes (u32 rel, u32 count, u32 capacity), elements at descriptor address + rel.

* **CRC dictionary** (root type `Pam::XBinData::CCRCDictionnaryXBinType`): root descriptor at `0x14`,
  `count` entries of (u32 rel-to-string, u32 `zlib.crc32(string)`) at `0x20`, strings after. All 4,793
  and 282 entries in the two dictionaries in `Core.arc` verify. This is how the engine maps field,
  type, animation and enum names to keys (`zlib.crc32` of the C string; the key function is at
  `0x88608590`, a table-driven reflected CRC-32 with initial value `~seed`, final `~`, table at
  `0x880C84C0`).
* **Layoutall.bin** (an XBin, root descriptor at `0x14` -> 403 pairs at `0x34`): pairs of
  (layout id, root type crc), sorted by type crc. 403 root types exist. Names for 33 of them were
  resolved by hashing strings in `Swing_DLL.dll`; the swing AnimationDB is one.
* **Field descriptors** (9 words, 36 bytes): type crc; flags (`0x40000` scalar/pointer, `0x80000`
  nested struct, `0xC0000` list, `0x180000` pair of lists); name crc; ordinal key; kind hash
  (`0xD543463B` in the common case); crc of the previous field name; byte offset inside the parent
  struct; alignment (4); reserved. The offsets are the byte offsets inside the image at
  `0x14 + offset`.
* Not understood: the full type-record grammar (records of 9 words and of 16 words that carry type size,
  alignment and field-array pointers; records with `0xFACE0143`), enum and pointer field kinds, and
  how the element type of a list field is chosen. Without them only structures whose layout can be
  inferred (flat arrays) can be decoded.

### XBin census (`work/disc/gameplay/xbin_census.json`)

Scanning every entry of 144 archives finds 99 distinct root types; 87 are listed in `Layoutall.bin`. Most
instances are per-venue scene data (e.g. 3,326 instances of one type in 45 archives, 1,822 and 1,796
instances of two others in 57 archives). The types that occur in only `Core.arc` or `Global.arc` are
the candidates for global gameplay data; their names are unresolved (the crc dictionaries on disc do not
contain the type names) so the census lists type crc, instance count, largest uncompressed size and
archive count only.

## 4. Swing AnimationDB (priority item 7, partly 3 and 4)

* Entry key `0x70155255` in `Core.arc`: 1,446,284 stored bytes, 3,437,395 uncompressed, 4 LZX chunks
  of 1 MiB, SHA-256 of the uncompressed data
  `3a3a98cf71d1c82479bd5842ac596a599d5e90fa12c22e69e8c65f64aaf7a3dc`. Signature
  `a5c6c542 ee710815`, version 0x10.
* The root struct is 180 bytes at `0x14` with the fields of `Pam::SwingAnimation::AnimationDB::Parameters`
  from `Layoutall.bin`: one 8-byte scalar block (`QualifierTypes`, two big-endian floats) and arrays:

| Field | Count | Stride (derived) |
| --- | --- | --- |
| AnimGroupDescList | 46 | 40 |
| TransitionEventDefinition | 2 | nested |
| TransitionRuleList | 9 | nested |
| TransitionMatrix | 128 | nested |
| Animations | 98,596 | 2 (u16) |
| TakeList | 3,184 | nested (about 330 bytes with sub-arrays) |
| RTTakeList | single pointer | nested |
| HkxList | 7,306 | 28 |
| ExtractPositionList | 1,904 | 16 |
| QualifierEnumRawDataArray | 146,477 | 8 (pairs of floats) |
| PreEventList | 146,464 | 4 |
| HandEvents | 9,828 | 16 (three floats and a zero word) |
| FacialEvents | 1,934 | variable |

Strides are inferred from the distance to the next array; arrays marked nested were not flattened.
Field meanings beyond the names are not established. The swing animation names used as keys are in the
4,793-entry dictionary (`Swing_*` and `Cutscene_*` take names, enum names such as `SwingPreferenceLevel`,
`ServeDropTime`, `LowVivacitySpeedCoef`, `MissType`). The dictionary also names the `ResponseCurveSingle` and
`ResponseSegmentSingle` types, so response curves exist in this database, but no element of them was located.

## 5. Other findings

* Engine key function: `0x88608590` (`zlib.crc32` of a C string, with seed). Used for names in XBin,
  the script command registrations, and layout type names.
* `Core.arc` contains HLSL sources and effect XML (text), 70 Lua 5.1 bytecode files, scene files, and
  the two dictionaries. The Lua files hold UI, unlock and exhibition logic, not gameplay tuning
  (checked by string content).
* `Layoutall.bin` and `CoreTech_Xenon.bin` contain 920 and 370 printable fragments; the latter lists
  the boot configuration (data spool XML paths, `PAM-ZLB`, `Layoutall.bin`).
* The analyser framework classes (`CAnalyserFramework`, `CAnalyserAgent*` expression, count, clock,
  min/max, comparison, sum/product agents) are registered in the executable; their graph data was not
  found. Venue archives hold `Shots.bin`, which belongs to the camera engine (`CShotPad`,
  `CShotSource`), not to tennis shots.
* The scratch directory shared by several agents was written with generically named helper files
  (`pe.py`, `xref.py`, `t1.py`, `t2.py`, `t3.py`, `strs.py`) in the session scratchpad before a private
  subdirectory was used; names may have collided with other agents' files there.

## 6. Reproduction

```
ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
python3 tools/xdvdfs.py "$ISO" --info
python3 tools/xdvdfs.py "$ISO" --list --long
python3 tools/xdvdfs.py "$ISO" --extract Layoutall.bin --out work/disc/files
python3 tools/ts4_arc.py Core.arc --iso "$ISO" --list
python3 tools/ts4_arc.py Core.arc --iso "$ISO" --extract 70155255 --out work/disc/core_big
python3 tools/ts4_xbin.py work/disc/core_big/70155255.bin --info   # AnimationsDB.bin
python3 tools/ts4_extract.py --iso "$ISO" --out work/disc/gameplay --dll orig/54540859/Swing_DLL.dll --census
python3 -m unittest tests.test_disc_formats
```

Outputs in `work/disc/gameplay/` (local only): `crc_dictionaries.json` (two dictionaries),
`layout_pairs.json` (403 root types), `animation_db.json` (header, root field table, rows of the flat
arrays as raw words with float and dictionary-name interpretations, plus `takes`: the 3,184 decoded 0x8C records),
`templates_settings.json` / `templates_state.json` (shot-template rows and decoded value pointers), `xbin_census.json` (99 types).
Peak disk use under `work/disc/` was about 330 MB.

## 7. Open questions

1. Assign roles to the words of the template rows in `Settings.bin` / `State.bin` (section 9) and the
   remaining `Settings.bin` tuning blocks.
2. Decode the Layoutall type records so any XBin can be read generically; then locate the gameplay
   modules (root types present in one archive only) and the analyser project data.
3. Decode `TakeList`, `TransitionMatrix`, `TransitionRuleList` and the `Parameters` blocks.
4. `CutScenes.arc` has a different header; entries of `Baked_*.arc` and the PlayerCreator archives were
   not examined.
5. Havok packfiles (`Physics.hkx`, `TrackSide.hkx`, `SwingMan.hkx` names exist) are not decoded; Havok
   tools handle the open formats, and the animation clips referenced by `HkxList` were not located.

## 8. Reconciliation with the branch spec (`docs/gameplay/df.md`, `tools/ts4data/*`)

Checked against the real disc. Confirmed unless marked WRONG or NEW.

| df.md claim | Result |
| --- | --- |
| 1.3 header: 5 u32 (w0 root/type id, w1 layout hash, w2 alignment, w3 section count, w4 section table) | Confirmed in shape. For disc files w0/w1 are the 8-byte signature; w1 equals the root type crc that keys the sorted second column of `Layoutall.bin` (so "layout hash" is the root type crc). w2 = 4, or 0x10 for `AnimationsDB.bin`, `Settings.bin`, `State.bin`. w3 = 0 and w4 = 0xFFFFFFFF in every file examined (no section table) except dictionaries/FAT-like files. |
| 1.5 relative array `{s32 rel; s32 count}`, 8 bytes | Partly WRONG: on disc the descriptor is 12 bytes `{rel, count, capacity}` (capacity == count). Field offsets in `Layoutall.bin` step by 12. Elements at descriptor address + rel is confirmed. |
| 1.5 typed-struct offsets compiled into C++ | Partly WRONG: field names, types and byte offsets are also stored in `Layoutall.bin` (9-word field descriptors, section 3 above), so a schema-driven reader is possible. |
| 1.6 crc32 = zlib crc32 of the ASCII name | Confirmed (CRC dictionaries verify entry by entry; `0xEE710815` = `Pam::SwingAnimation::AnimationDB::AnimationDB`, `0x5ACBA7E7` = `...::Parameters`). |
| 1.7 `crc.bin` is a name dictionary | Confirmed and decoded: `AnimationsDBcrc.bin` (4,793 names) and `CommonCRCDictionnary.bin` (282 names). |
| 2.2 `.arc` = fat_size, FAT, then data; file entries `{hash, offset, size}` sorted; `fat+0` file table, `fat+0xC` directory table | Confirmed (fat_size at 0x00 equals header_size - 4; offset relative to the byte after the FAT). |
| 2.2 FAT obfuscation / marker `PAM-ZLB` | On disc the FAT is plain and the marker at fat+0x18 is `PAM-LZX` (the loader's `PAM-ZLB` is a different config tag). |
| 2.2 path hash algorithm | Confirmed (see section 2); extra detail: directory hashes include the trailing `/` and chain by CRC continuation. |
| 2.2 compression "likely zlib" | WRONG: members are LZX. Each member has its own wrapper (section 2) with a 20+ byte header, chunked 1 MiB streams and 32 KiB frames. `tools/ts4data/arc.py`'s `zlib.decompress` fallback returns raw LZX bytes. |
| 3.1 root of `Animations.bin` is the animation DB | The 0xEE710815 database is `Core.arc` -> `AnimationsDB.bin` (3,437,395 B). Venue `Animations.bin` files (158 instances, 1,052 B to 1,734,476 B) are a different type (signature `b9554404 c9e69d75`; `{rel,count}` at +0x18). Root offsets +0x50/+0x54 (file 0x64/0x68) = 0x8C-byte records, count 3,184: Confirmed. |
| 3.2 record +0x5C `{rel, 0xA0B2A282}`, +0x64 annotations, +0x70 segments, +0x84 id | Confirmed (2,444 of 3,184 records use type `0xA0B2A282`; others `0x2DB2D90F` 367, `0xC4BAA666` 247, `0x8361F2CA` 126). Annotation and segment arrays are 12-byte descriptors. |
| 3.2 +0x84 id and "AOD file name number" | id is `crc32(animation name)`, e.g. `Swing_Return_FH_Standard_OpenStance_Reach_GoodControl_Waist`; all 3,184 resolve in the 4,793-name dictionary. The number for `Media\Animation\AOD\<n>.hkx` is therefore not this id (unverified). |
| 3.2 +0x14 f32 time_ratio (1.0 = unscaled) | WRONG as written: +0x14 holds values such as 117.0 and 139.0; 1.0 is at +0x18 and +0x1C is about 1e-6. |
| 3.2 annotation names `EventRacket`, `Preparation` | Confirmed: `EventRacket` appears in 1,638 records (times such as 0.388), also `Hand_FH_Pose` 642, `CutScene_EndOfPoint` 365, `Stomp` 266, `Cycle_In/Out` 221 each. |
| 4.1 shot-template source "not determined"; grep every `.bin` for the kinds | Done on all 4,313 `.bin`/`.xbin` entries of the 108 non-baked, non-cutscene archives: only `Core.arc` `Settings.bin` and `State.bin` contain them (counts in section 9). |
| 4.3 value pointer `{rel, type}` with types `0x33799CCE`, `0xF9F12A60`, `0x7A330099` | Confirmed: target of a constant is one f32; of `0xF9F12A60` a 12-byte `{rel=0xC, count, cap}` array of 20-byte keys `{x0, x1, c, m, u32}` (first key seen: x0 500.0, x1 3000.0, c 80.0, m 0); `0x7A330099` rows are 16 bytes. |
| 4.2 row layout (kind at tpl+0x08, slots at +0x18..) | Not verified: in `Settings.bin` the kind hash is preceded by a `{rel, 0xF9F12A60}` pointer and followed by more pointers (e.g. `0x879BA860` is another type hash used between pairs); roles of the words were not reconstructed. |
| 5 Havok / hkx | Not examined (names `Physics.hkx`, `TrackSide.hkx`, `SwingMan.hkx` exist in `Core.arc` and venue archives). |

## 9. Shot-template file (priority 1)

* `Core.arc` entries `Settings.bin` (key `0x334E7E0D`, 286,492 B uncompressed, signature `181aedee d2968089`, version
  0x10) and `State.bin` (key `0x623D0979`, 273,746 B, same type). Local copies for reading:
  `work/disc/core_big/Settings.bin`, `State.bin`.
* `Settings.bin`: 28 occurrences of kind `0x5D90675B` (rows 0x230 bytes apart at 0x1540, 0x1770, 0x19A0, 0x1BD0 ...),
  27 of `0xC1965E5C` (rows 0x8C apart at 0x139C, 0x1428, 0x14B4 ...), none of `0x2DB3EB6F`; 296 decodable value
  pointers: 172 constants, 117 piecewise curves (20-byte keys), 7 two-dimensional tables (16-byte rows `{curve16 header,
  ?, key}`, curve16 keys `{x0, x1, y0, y1}`; one has rows keyed 300.0 and 3000.0). `State.bin`: 2 rows of kind
  `0x50B89452`, 8 pointers (4 constants, 4 curves).
* `tools/ts4_extract.py` writes `work/disc/gameplay/templates_settings.json` and `templates_state.json`: every kind
  occurrence with a 0x90-byte word window and the addresses of the pointers inside it, plus every decoded pointer
  `{addr, value}`. Assigning fields (bounce, spin, drift T, per df.md 4.2) needs the row roles confirmed against the
  solver code; that is the next step for the porting side.
* `Settings.bin` also holds other tuning (it is far larger than the 55 rows span); nothing else was classified.

Counts above were measured with `tools/ts4_extract.py` on the disc image described in the header; the kind-hash search
is the scan in `work/disc/kind_hits.json` (local).
