# DF notes: data formats (XBin, .arc, animation records, shot templates, Havok .hkx)

Family DF, prefix `df_`. Goal: let readers for the game's gameplay data (skeletons, clips, tuning tables, physics) be
written before the disc data exists, by reading the *loader code* in Swing_DLL.xex.

Binary analysed: `orig/54540859/Swing_DLL.xex` sha256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44`
(5,083,136 B) and its PE image `orig/54540859/Swing_DLL.dll` sha256 `a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`
(13,848,064 B; PE32 big-endian PowerPC, base 0x88000000; .text VA 0x88150000, .rdata 0x88000600, .data 0x88b25c00).
Tools: `tools/fn_asm.py` / `tools/sym_info.py`, a raw-address PowerPC disassembler built on `work/ppcdis/target/release/ppcdis`
fed from the PE image, Python 3.13.18 (stdlib only). Hashes: `zlib.crc32(ascii)`. Addresses are VAs.
Confidence: **H** disassembly read directly, **M** consistent structure/inference, **L** guess. Nothing here was
checked against real game data (none available); every reader in `work/df_readers/` is a prototype with a synthetic self-test.

## 0. What is specified and with what confidence

| Item | Result | Conf. |
|---|---|---|
| XBin container (header, section table, runtime link patching, big-endian, in-place body) | section 1.1-1.4 | H (header/table), M (section payload meaning) |
| Typed-struct conventions (`{rel,count}` arrays, 12-byte link fields, type tags, 55-entry type-name hash table) | 1.5-1.6 | H for arrays/type table, M for link fields |
| Layout / crc / path-dictionary companion files | 1.7 | M (existence and roles), L (layout member record fields) |
| `.arc` archive (`CFileSystemPackArchive`): header, XOR-obfuscated FAT, 12-byte file entries, path hash | 2 | H (header, FAT lookup, path hash), M (entry word meaning), L (directory table, member compression) |
| Animations.bin record: id/ratio/slot/annotations/segments/setup scale | 3 | M (offsets measured; names are roles) |
| AOD clip file mapping `Media\Animation\AOD\%u.hkx` -> record | 3.3 | M |
| Shot-template row: where it lives in the data, curve block formats | 4 | H (curve evaluators), L (source file) |
| Havok: packfile container, version, reflection of every `hka*`/`hkp*` class actually linked in | 5 | H (reflection dump), M (packfile version of the shipped files) |
| Not decoded: spline/delta/wavelet animation payload bit formats, Global.bin/Behavior.bin/CoreTech_Xenon.bin field schemas, FAT directory table | 8 | - |

Readers (stdlib Python, not committed): `tools/ts4data/xbin.py`, `tools/ts4data/arc.py`, `tools/ts4data/hkx.py` (+ `havok55_classes.json`, 352 classes
dumped from the executable). Each has a `selftest` against a synthetic file written by the same assumptions, so passing only means the code
is internally consistent. Draft C: `src/xbox360/drafts/df_data_formats.c`.


## 1. XBin (`Pam::XBinData`): the `.bin` container

Used for `Animations.bin`, `AnimationsInterface.bin`, `Global.bin`, `Behavior.bin`, `Physics.bin`, `CoreTech_Xenon.bin`, every
`Media\BinData\...\*.bin` (GameDB, Season, StringTable, CoachList, ...), the PlayerCreator DNA files and the FAT inside `.arc` archives (see 2).
All integers are **big-endian**; no byte swapping exists in the Xbox build, and pointers are never stored (see 1.5).

### 1.1 Classes (registered by `fn_889298D8`; names are crc32 keys of the ASCII string, both short and `Pam::XBinData::` forms)

| Class | crc32 | Object | Ctor / factory | Role |
|---|---|---|---|---|
| `CXBinDataServer` | 0x471E936A | 0x54 B, vtable 0x880D6268 | `fn_8892AFF0` via `ts4_create_container_factory` (fn_88170A58) | loads one `.bin`, exposes `body + offset` views (H) |
| `CLayoutServer` | 0x3212F2E6 | 0x54 B, vtable 0x880D6218 | `fn_889296C0` | loads a `*layout.bin` (itself an XBin) and binds schemas (M) |
| `CLayoutServerComposite` | 0xF76A4FEC | 0x80 B | `fn_8892A0E0` | several layout servers in sequence (L) |
| `CCRCDictionnaryXBin` | 0xAD77D64E | 0x28 B, vtable 0x880D6AC4, singleton `engine+0x238` | `fn_889285A0` | name table for crc32 keys; unknown key prints `CRC_%x` (`fn_88930848`) (H) |
| `CXBinPathDict` | 0x09ED37FF | 0x20 B | `fn_889270C0` | section index -> file path (used by `fn_8892F038` to open child files) (M) |
| node-class tag `Pam::XBinData::CAny` | 0x80E55C7B | - | - | type tag every handle checks before a typed view is returned (`fn_88923530`) (H) |

`CXBinDataServer` vtable (offset: function): +0x10 `fn_8892AB80` Init-from-XData-config; +0x14 `fn_88929E70` Reset (frees body and section vector);
+0x30 `fn_889238F0` IsLoaded (`+0x20 != 0 && +0x24 != 0`); +0x38 `fn_88922710` **Load(path,...)**; +0x3C `fn_8892FE20` LoadFromFile; +0x40 `fn_88925860`
Load(path, layout path); +0x48/+0x4C `fn_889226F0/fn_88922700` **`return body + offset`**; +0x54 `fn_88923740` set layout server; +0x58 `fn_889236D8` release layout;
+0x5C `fn_8892F240` resolve section links; +0x60 `fn_88923648` bind layout by hash; +0x64 `fn_88922680` **section pointer by index**; +0x68 `fn_8892A968` **parse**.

### 1.2 Load sequence (H)
`Load(path)` (fn_88922710): empty path -> false; opens the file through the engine file system object `lbl_88D45B1C + 0x224` (vtbl +0x28, mode 1 = read) -> `LoadFromFile`
(fn_8892FE20): parse (+0x68); if a layout server was passed bind it (+0x54, then +0x60); if requested resolve links (+0x5C); finally notifies the XData server
(`fn_887EEC78`) so the new data appears under its mount name (`AnimationDB:/`, `SbikAnimationDB:/` ...; e.g. `fn_88774300` loads `\Animations\Animations.bin` and pushes the server into the engine's
mount vector at `this+0x88`).

### 1.3 File header and body (`fn_8892A968`, H)
```
+0x00 u32 w0   -> server+0x20  root/type id handed to the schema/tree lookups (M: root class or node hash); a value of 0 makes IsLoaded() false
+0x04 u32 w1   -> server+0x30  layout (schema) hash, looked up in the CLayoutServer (M)
+0x08 u32 w2   -> server+0x2C  body alignment passed to the allocator when the server is in "owned" mode (M)
+0x0C u32 w3   -> server+0x48  number of sections
+0x10 u32 w4   -> server+0x4C  = body_ptr + w4 - 0x14: file OFFSET of the section table (array of w3 u32, each a file offset)
+0x14 ...      body: everything after the header, read as ONE block; body size = file size - 0x14 (server+0x28)
```
The check `file size > 0x14` is the only validation. The body is used **in place**: typed structs are addressed as `body + offset`, where *offset = file offset - 0x14*
(for `AnimationsInterface.bin` the root typed struct is `body + 0`, i.e. file offset 0x14, fetched with `server->vtbl[0x4C](server, 0)` in `fn_88773438`; other files go through the XData tree handle instead).
Section i starts at `file_offset = table[i]` (`fn_88922680`: `body + table[i] - 0x14`). At load time the first 12 bytes of every section are overwritten with
`{server*, table-entry*, 0}` (loop at 0x8892AB20-0x8892AB64), so those bytes are dead on disk. The server keeps a vector of 16-byte entries `{begin,end,cap,section*}` (`server+0x3C..0x44`,
`ts4_compact_owned_span16` frees it); `fn_88923380` reads `entry[0].{+4,+8,+0xC}` as a handle triple `{tree, node id, pool}` (see 1.5).
Sub-sections can be **external files**: `fn_8892F038(section, server, layout, path?, fs?, owner)` opens a child `CXBinDataServer` (registry hash 0x471E936A) whose path comes from the
`CXBinPathDict` embedded at section+0x10 (`fn_8892ED88`), then links it with `fn_88927110` (sets `section+0xC = child`, `child+0x50 = parent`). Whether the shipped gameplay files use this is unknown.

### 1.4 How a reader finds things (M)
1. Parse the 5 header words, read the section table at `w4`, treat `body[0 ..]` as the root typed struct.
2. Every named field of a typed struct is addressed by **fixed offset** (the XData schema is compiled into the C++ readers, which is why GP notes list offsets, not names). Field *names* are crc32 hashes
   living in the schema/layout data, not in the file body: a reader needs offsets, which are in the per-file sections below.
3. `tools/ts4data/xbin.py scan FILE` lists plausible `{rel,count}` headers; compare against the known roots (1.8) to confirm byte order and the 0x14 shift on first contact with real data.

### 1.5 Typed-struct conventions (H unless marked)
* **Relative array** `{s32 rel; s32 count}` (8 bytes, `rel == -1` = null): element i at `header_addr + rel + i * stride`. Used by every table (see `fn_881899D8`, `fn_886D7638`, `fn_88880440`, ...).
  Because `rel` is relative to the *header's own address* the structure can be copied/moved as a block.
* **Typed view**: `fn_88923530(server, handle, type_hash)` -> `server->body + node_offset`, only if (a) the handle's object carries tag 0x80E55C7B (`Pam::XBinData::CAny`) and (b) the node's schema type hash
  (`node_meta->+0x30`) equals `type_hash`. The `type_hash` values are the keys of section 6.
* **Metadata node** (the *runtime* schema tree built by `fn_8860FA68`, Server.cpp): 16 bytes `{u64 packed, u32 name_hash, u32 packed2}`; `packed` bits 63..44 next-sibling id, 43..24 parent id,
  23..4 size, 3..2 node kind (0 element .. 3), 1..0 flags; `packed2` bits 31..5 data offset in the pool, bits 4..0 type/alignment code; 0xFFFFF = null id. M (inferred from bit ops; matters only if
  you want to rebuild the tree).
* **Link/reference field** (12 bytes, e.g. `Physics.bin` root +0x24/+0x30/+0x3C/+0x48; `fn_8817F5E0` accessor): `{s32 rel_to_link_list; u32 resolved_ptr; u8 resolved; u8 relative}`. On first access `fn_8892EE88` resolves the
  link through a list of **0x1C-byte link records** (`{handle triple a, handle triple b, ..., u8 kind at +0x18}`; kind 1 = same container (pointer = body + offset), kind 2 = other server) and caches the pointer in
  the field; the accessor returns `field - rel` for relative links else the cached pointer, 0 when absent. So scalars such as booleans in the root of `Physics.bin` are *indirections*, not inline values. M/L
  (0x1C-byte record fields are only partly decoded).
* **Polymorphic children**: a node inside a typed struct may start with a 4-byte type hash (e.g. record +0x5C -> sub-node whose +0x60 word is 0xA0B2A282 in `fn_886C5230`); a reader dispatches on that hash. M.

### 1.6 Primitive type-name hash table (`fn_88923D98`, H; 55 entries, default 0x14)
The schema refers to primitive types by crc32 of these names; the loader maps them to a storage code. Names recovered by brute force are marked; unnamed hashes are alternates (XML-Schema style spellings).

| code | crc32 keys |
|---|---|
| 1 | 0x8A858868=boolean, 0x5EF24641, 0xF5E3B036 |
| 2 | 0x1451DAB1=int, 0x59354C5C, 0x5A0FAB0B=integer, 0x8E786522, 0x6543E2E6 |
| 3 | 0xC9A55E95=float, 0x3B19A821, 0xC692C255 |
| 4 | 0x9EBEB2A9=string, 0x524079CA, 0x928B57E5, 0xBD6AB343 |
| 5 | 0x9BDF22D1, 0x4FA8ECF8, 0xF7FFB67A, 0xC8655143 |
| 6 | 0xB09878F3 |
| 7 | 0x320468A8=pointer, 0x4D6250F6 |
| 8 | 0x6772FE75, 0xC0B95C77, 0x074696A9 |
| 9 | 0xE5791C94, 0x68BABFBD |
| 10 | 0x994E55AB |
| 11 | 0xAF0E3075, 0x5ACA1D0D, 0x3C261E56, 0x4456F186 |
| 12 | 0x8CFE579F=char, 0x5208ADCC, 0xA10F5B88 |
| 13 | 0x411778D6 |
| 14 | 0x8F2890A2=short, 0x7D946616, 0x5018447D, 0x5018447D |
| 15 | 0x206A4341, 0xD2D6B5F5, 0x03A698B4, 0x1CBD151A, 0x16531297, 0x321D3032 |
| 16 | 0x3B97A968=long, 0xE561533B, 0xF157B396 |
| 17 | 0xA7ED8CE5, 0x4944266B, 0x9352C7D9 |
| 18 | 0x6B8389C4 |
| 19 | 0xB3EA1998 |

Resolved: code 1 bool = `boolean`; 2 int32 = `int`, `integer`; 3 float = `float`; 4 string = `string`, `Pam::XBinData::CString` (0xBD6AB343); 7 pointer = `pointer`; 8 uint32 = `unsignedInt` (0x6772FE75);
9 hash/key = `CKey` (0xE5791C94); 12 int8/char = `char`; 14 int16 = `short`; 15 uint16 = `unsignedShort` (0x1CBD151A); 16 int64 = `long`; 17 uint64 = `unsignedLong` (0xA7ED8CE5). Codes 5, 6, 10, 11, 13, 18, 19
are unresolved (likely double/vector/matrix/quaternion/enum style types). Code assignments above 9 are by name match only (M). The gp0 note "1 bool, 2 int32, 9 u32 hash" is consistent.

### 1.7 Companion files (M)
* `<name>.bin` + `<name>layout.bin` + `<name>crc.bin` triplets (e.g. `Media\PlayerCreator\Xml\DNA\Male\Default.bin`, `Defaultlayout.bin`, `Defaultcrc.bin`): built by `fn_88974E58` (strip extension, append `layout.bin` / `crc.bin`)
  and loaded by `fn_8896B820(server, path, layoutPath, crcPath)`. They exist for user-created data (PlayerCreator); shipped fixed data such as `Animations.bin` is loaded **without** layout (`Load(path,0,0,0,0,0)`).
* A layout file is itself an XBin: after load `CLayoutServer` post-processes its sections (`fn_8892F328`): for each section `s`: `s+0x30` class/layout hash, `s+0x3C` member count (and list at `s+0x18`+rel, `s+0x1C` count),
  member record = 0x1C bytes with `+0x10` = type-name hash resolved through the table in 1.6, `+0x14..` member name/size words (L). Seven built-in layout categories are pre-registered by `fn_8892EA98` (table 0x88C6CF78).
* `CoreTech_Xenon.bin`: opened from the file-system root if present, otherwise `UPDATE:\CoreTech_Xenon.bin` (title update device); `UPDATE:\Layoutall.bin` is the update's layout (`fn_889BD370`). It holds the scheduler config (module list; gp0).
* `crc.bin` = name dictionary only needed for diagnostics; readers can use crc32 directly.

### 1.8 Known roots and records (offsets measured; see also 3 and 4)
* **Animations.bin** (`fn_88774300` mounts it as `AnimationDB:/`; typed root hash 0xEE710815 read by `fn_886E3A00`; `SbikAnimationDB:/` is hash 0x7600225C):
  `root+0x14 {rel,count}` -> 0x1C-byte groups, each with `{rel,count}` at +0 -> 0x28-byte slot defs (`+0x0C` kind hash, `+0x14` int) and `+0x14/+0x18` = first record index / record count in the 0x8C table; the engine sums slot-def `+0x14` of kind 0x959A9407 to size its play-slot array
  (`fn_886E57A8`, H). `root+0x50 {rel,count}` -> **0x8C-byte animation/setup records** (section 3). `root+0x60` 0x1C-byte table and `root+0x6C` 0x10-byte clip-cache entries (`{?, use_count@+4, ...}`; runtime-mutated: `fn_886CE5B0` increments +4, M).
* The Animations.bin root also holds (read by `fn_88773438` from the mounted `AnimationDB` service, H): `+0x00 {rel,count}` stride 0x38 (each entry built into a 0x78-byte interface object by `fn_8876D0F0`/`fn_8876E0B0`, kept in `this+0x40`) and
  `+0x0C {rel,count}` stride 0x10 (16-byte entries wrapped in 0x14-byte objects, kept in `this+0x7C`). Field meaning L.
* **AnimationsInterface.bin** (`fn_88773438`, loaded into a local `CXBinDataServer` from `\Animations\AnimationsInterface.bin`): root `+0x00 {rel,count}` (count read at +4) stride 0x20; each entry: `+0x18` = class hash looked up in the object registry
  (`lbl_88D45B20`; the created object's `vtbl[3]` initialises it from the entry), `+0x10` = value stored into the created object at +0x18; objects are appended to one of two vectors (`this+0x64` / `this+0x70`) depending on a caller argument. L (field meaning unknown).
* **Physics.bin** (`fn_88880440`, typed hash 0x56931990): root `+0x1C {rel,count}` -> 0x30-byte object config records (copied with `memcpy` and handed to a `CPhysic` object `vtbl+4`); gp4 documents the first fields; root `+0x24/+0x30/+0x3C/+0x48` are link fields (booleans: `+0x3C` -> enable flag
  `manager+0x34`, `+0x30` -> when true a 0x10C-byte helper object is created (`fn_8887F040`, stored at `manager+0x20`), `+0x48` -> `manager+0x35`, `+0x24` -> further option).
* **Engine config** typed hash 0x2FEF2019 (`fn_886BC568`), **GameplayInputs** 0x63F5A11F, **PlayerStates** 0x502FE79D (stride 0x1070): gp0.


## 2. Archives and other containers

### 2.1 Strings found (H)
`.arc`: `Core.arc` (FMOD banks/core data, `fn_8862F0B8`), `GameplayEOP.arc` (end-of-point data, loaded by `fn_887E35D0` / `fn_887E5538`), `PlayerCreator_Male.arc`, `PlayerCreator_Female.arc`, `Baked_%s%d.arc`, `DLCArchive%d_%x.arc`,
`Media\Patch\Patch.arc`, `PatchData.arc`, `Media\Patch\MyPatchData.arc`, `Media\Patch\PatchData.arc`, `%s%s.arc`; extension literals `.arc`, `.oarc`, `arc`, folders `Comp\`, `Comp`, `Media`, marker `PAM-ZLB`.
FAT-style indexes: `FAT.bin`, `/FAT.bin`, `DLCFat.bin`, `Media\Patch\PatchesFAT.bin`, `Common\Fat.bin` (the last is a body-type data file, not an archive index). No `.pak`/`.big` strings exist. `.xpr` = Xbox packed resource textures
(`CAtgPackedResource`, error `Invalid Xbox Packed Resource (.xpr) file: Magic = 0x%08lx`; `Textures.xpr`, `Media\UI\PamDisplay\TexturePacks\...\%s.xpr`), standard Microsoft XPR2 (`out_version XPR2` hint in the error string).
`Media\...` paths are ordinary files on the disc/HDD file system. The virtual file system is a composite (`CFileSystemComposite` 0x5DBA6879) of: physical (`CFileSystemPhysic`), `CFileSystemPackArchive` (class
`Pam::System::IO::CFileSystemPackArchive`, crc32 0x9DE0A0F2, 0xA0-byte object, vtable 0x880F8440), `CFileSystemOpenArchive`, `CFileSystemCompress`, `CFileSystemMemory`, `CFileSystemCache`, `CFileSystemLocalization`, `CArchiveLoader/CArchiveUnloader`
(`LoadArchive`/`UnloadArchive` script verbs, `ChangePackage`).

### 2.2 `.arc` layout (`CFileSystemPackArchive::Open = fn_886217C0`, H unless marked)
```
u32 fat_size                       if 0xFFFFFFFF: skip 3 more u32 (+4..+0xF), the real fat_size is the u32 at +0xC
u8  fat[fat_size]                  an XData typed struct image (not a full XBin: no 0x14 header), big-endian
u8  data[...]                      archive+0x34 = file position right after the FAT; entry offsets are relative to it
```
FAT header (first 0x20 bytes, `fn_886217C0` 0x88621910-0x886219A0): if `fat[0x18..0x1A] == "PAM"` the FAT is plain; otherwise it is **obfuscated**: the u32 at +0x18 is a key; the six words at
+0x00..+0x17 are XORed with that key, then +0x18..+0x1F is replaced by the 8 bytes `"PAM-ZLB\0"` (constant at 0x880F6E9C). After de-obfuscation:
`+0x00 {rel,count}` = **file table**, `+0x0C {rel,count}` = **directory table** (`+0x0C` rel, `+0x10` count), `+0x18` marker `"PAM-ZLB\0"`.
* **File entry (12 bytes, sorted ascending by the first word, binary search `fn_8827EC98`)**: `{u32 path_hash, u32 offset, u32 size}`. offset/size confirmed by the stream objects: size = `entry+8` (`fn_8827EE90`), absolute
  read position = `archive+0x34 + entry+4 + cursor` (`fn_8827EE00`). H (offset/size roles), M (nothing else known in the entry).
* **Path hash** (`fn_886090A0` + `fn_886084C8`): copy the path, replace `\` by `/`, drop a 2-character `X:` drive prefix, prepend `/` if missing, then **crc32 of the lower-cased bytes** (`fn_88567730` = A-Z to a-z). Example:
  `tools/ts4data/arc.py hash 'Media\Animation\AOD\1.hkx'` -> 0x1B706FC6 (not a verified key; just the algorithm).
* **Directory table** (`fn_8862FE38`, list directory): 16-byte entries sorted by the u32 at +0x0C (dir path hash); each entry has `{rel,count}` at +0 / +4 -> 8-byte records whose first word is a self-relative offset to a name string
  (children names). L.
* **Compression**: the pack stream layer reads `size` raw bytes (no inflate in `fn_8827EE00`); the marker string `PAM-ZLB` and a separate `CFileSystemCompress` layer (folder names `Comp\`) suggest zlib-compressed members, but how a member is flagged
  is NOT decoded. `tools/ts4data/arc.py` therefore tries `zlib.decompress` and falls back to the raw bytes. Names are not stored in the FAT (only hashes) except implicitly through the directory table; supply a candidate name list with `--names`.
* **Existence/open**: `fn_886216A8` = `lookup(hash(path)) != 0`; `fn_886215A8` creates a 0x20-byte read stream (vtable 0x880F84BC: +4 archive, +8 caller, +0x14 entry, +0x18 cursor).

### 2.3 Other archive-like files
* `Media\Patch\PatchesFAT.bin` / `PatchDesc.bin` / `Patch.arc` / `PatchData.arc`: title-update overlays, see `docs/title-server-patch.md` (not gameplay).
* `GameplayEOP.arc`: opened with the same pack-archive mount; its content (end-of-point cutscene/stat data) is accessed by path through the composite file system, so once the archive is mounted every member is
  an ordinary virtual file (`.bin` = XBin, `.hkx` = Havok). Member names must be recovered by hashing candidate paths against the FAT keys.
* Save/replay blobs (`Input.rec`, `GamePlayHeap*_%d.rec`, `Media\ReplayDemo\%s.bin`): no format recovered (gp0 5).


## 3. Animation records (`Animations.bin`, `AnimationsInterface.bin`) and AOD clips

Context: gp7 (swing animation engine). The engine mounts `\Animations\Animations.bin` as `AnimationDB:/` (typed root 0xEE710815, SbikAnimationDB 0x7600225C) and `\Animations\AnimationsInterface.bin` as the interface objects
(`fn_88773438`). Clip payloads are Havok packfiles, one per clip (section 5).

### 3.1 Root of `Animations.bin` (body offset 0 = file offset 0x14; `{rel,count}` arrays as in 1.5)
| root offset | content | stride | evidence |
|---|---|---|---|
| +0x14 / +0x18 | `{rel,count}` **groups** (0x1C B): `+0x00 {rel,count}` of **0x28-byte slot defs** (kind hash +0x0C, 0x959A9407 = play slot; int +0x14), `+0x14` u32 first index into the 0x8C table, `+0x18` u32 number of records of the group (`fn_886D3310`: records `[g0.+0x14, ...)`, total = g0.+0x18 + g1.+0x18) (M) | 0x1C / 0x28 | `fn_886E57A8` loop at 0x886E5C94-0x886E5D44 (H) |
| +0x50 / +0x54 | **animation + setup records** | 0x8C | `fn_886D7638`, `fn_886D3310`, `fn_886C8438` (H) |
| +0x60 | 0x1C-byte table indexed by a halfword at `record.sub+0xC` (gives the clip-cache index) | 0x1C | `fn_886C5230` (M) |
| +0x6C | 0x10-byte clip-cache entries `{?, use_count, ...}`, mutated at run time | 0x10 | `fn_886CE5B0`, `fn_886E3A00` (M) |
`AnimData root` offsets +0x94 / +0xA0 (16-byte query rows, key at +0x0C), +0x298 (SetupId), +0x29C..+0x2A8 (custom scale vec4), +0x2AC/+0x2AD (dirty flags), +0x1F4 (AOD request queue) belong to the **AnimationData** runtime
tree (hash 0x3A60FEE2), not to the file; see gp7.

### 3.2 The 0x8C-byte record (all offsets H, field names are roles = M)
```
+0x00 ..+0x0B  ?                                      (not read)
+0x0C u16  slot            layer slot, 0xFFFF = none (layer playing check, fn_886C4638)
+0x14 f32  time_ratio      1.0 = unscaled; event time shift = (ratio-1)*elapsed (fn_886D1408 / fn_886CD3C8)
+0x1C u32  variant         second lookup key: a record is found by (id@+0x84, variant@+0x1C) (fn_886C8438) (M)
+0x38 f32[4] custom_scale  setup records only: x,y,z,w (fn_886D7638 copies root+0x29C..0x2A8 <-> here)
+0x5C {s32 rel, u32 type_hash}  polymorphic pointer: type 0xA0B2A282 -> target (self-relative to +0x5C) is a struct whose u16 at +0x0C = index into root+0x60;
                  any other type -> target is an array of 8-byte {rel,..} pointers indexed by the caller's second argument (fn_886C5230) (M)
+0x64 {rel,count} annotations, stride 0x10: {u32 name_hash, f32 time, u32?, u32?}  EventRacket 0x3B9AD22E = racket contact, Preparation 0x7F6C2523
+0x70 {rel,count} segments, stride 0x28: +0x0C u32 kind hash (0x959A9407 seen), +0x10 f32 start/event time, +0x14 f32 (duration or count), others unread
+0x84 u32  id              animation id; AOD file name number (3.3); also the SetupId for setup records (root+0x298)
```
Event time inside a clip: annotation named EventRacket when `record+0x0C != -1` (as 32-bit), else Preparation; a 2-segment record uses `segments[1]+0x10` (= record+0x70 rel + 0x38) as the contact time (gp7 section 4/5/6; `fn_886CD3C8`:
`busy = max(0, (seg[1].f10 - layer.t0)*(ratio-1) + layer.base - now)`). Times are in 60 Hz ticks as floats (M).
The annotation names (`EventRacket`, `Preparation`) are also valid Havok `hkaAnnotationTrack` names; which source the game reads is the record table above (H), the hkx tracks are a duplicate (unverified).

### 3.3 AOD clip mapping (M)
`fn_886CE5B0(manager, request{u32 id, u32 variant, u8* done, ...})` -> `fn_886C8438(db, id, variant)` finds the record with `record.id(+0x84) == id && record.variant(+0x1C) == variant`; `fn_886C5230` maps it to a clip-cache entry;
the clip object's first word (`AodClip.id`) is the number formatted into **`Media\Animation\AOD\%u.hkx`** (`fn_886D2B58`). Practical reader rule: for every 0x8C record take `id@+0x84`, open `Media\Animation\AOD\<id>.hkx`;
if the id is missing on disc, also try the clip-cache entry index (the path number is the clip object id, which gp7 equated with `+0x84`).

### 3.4 Setup records and left-handedness
Setup records carry a custom scale (+0x38..+0x44) selected by SetupId; left-handed mirroring is done gameplay-side (gp7 2), there is no per-record left/right flag found.


## 4. Shot templates (`S+0x3C`), curve and table node formats

### 4.1 What the code establishes (H)
The ball stepper `S` (vtable 0x880DCA74, ctor `fn_889C1690`, update `fn_889C28B0`; gp4) reads the template for a launched ball as
`tpl = S->+0x3C + ball->+0x360 + 0x18` (`ball+0x24`, `fn_889C19F0`). `ball+0x360` (command +0x48) is a **byte offset inside the table block**, not a row number, so the table is an XData block reached through a typed pointer
and rows are variable-sized nodes. `S+0x3C` is zeroed by the ctor and written by neither `fn_889C28F0` (Init: only copies `S+0x3C` into the two generator objects' `+8`) nor any other function in 0x889C0000-0x889D4000; it is filled by the
XData config binding of the node class (the loader that supplies `S+0x3C` was **not located**; no string names it, all names are crc32 in data). Therefore **the source file is not determined**; candidates are the data
files loaded at module start: `Global.bin`, `CoreTech_Xenon.bin`, or a ball/physics config next to `Physics.bin`. The first thing to do with real data is to grep every `.bin` for the template kind hashes below
(0x5D90675B, 0x2DB3EB6F, 0x50B89452, 0xC1965E5C, 4 bytes, big-endian) and for curve type 0xF9F12A60.

### 4.2 Row layout (offsets relative to `tpl = table + index + 0x18`; H for readers, M for roles)
| offset | content | evidence |
|---|---|---|
| +0x08 (u32) | solver kind hash: 0x5D90675B / 0x2DB3EB6F / 0x50B89452 / 0xC1965E5C select `fn_888AB8D0` / `AC748` / `ACDA8` / `ACA68` | gp4_types.h (kind at `table+index+0x20`) |
| +0x18 | three 12-byte slots (+0x18, +0x24, +0x30), each `{s32 rel_to_pair; ...}` -> a 16-byte **pair** `{ptr_lo, ptr_hi}`; spin_a/spin_b/spin_c = `lerp(lo(x), hi(x), blend)`, x = `ball+0x344`, blend = `ball+0x364` | `fn_889C1868` |
| +0x40, +0x4C, +0x58, +0x64 | four 12-byte slots, each an `XRelArray {rel,count}` (+4 bytes unused) of 16-byte curve keys: bounce speed-loss c40(spin_a), spin decay c4C(spin_a), outgoing angle c58(theta), yaw kick c64(spin_b) | `fn_889C1C80` |
| +0x54 | float T (drift time constant) | gp4 |
The meaning of +0x00..+0x17 (node header, probably type tag + links) and of the remaining bytes up to the row end is unknown.

### 4.3 Polymorphic value pointer (`{s32 rel; u32 type_hash}`, 8 bytes, H)
A "value or curve" is stored as `{rel, type}`; the target is at `slot_addr + rel`:
| type hash | target | evaluator |
|---|---|---|
| 0x33799CCE | a 32-bit float (plain constant) | `lfsx` (no call) |
| 0xF9F12A60 | `XRelArray` of **20-byte keys** `{f32 x0, f32 x1, f32 c, f32 m, u32 ?}`: `y = c + clamp(x - x0, 0, x1 - x0) * m`; key = last with `x0 <= x` (first if none) | `fn_8817A688` |
| 0x7A330099 | **2-D table** (below) | `fn_8826D278(table, x, y)` |
Unlike the 16-byte curve, the 20-byte key stores slope `m` and value `c`, so a continuous curve needs `c[i+1] = c[i] + (x1 - x0) * m[i]` by authoring convention; a converter should store keys verbatim and evaluate with the same rule.

### 4.4 Curve and table formats (H)
* **Curve16** (`fn_881899D8(header, x)`): `XRelArray` -> 16-byte keys `{x0, x1, y0, y1}` ascending in `x0`; pick last key with `x0 <= x` (first if none); `t = clamp(x - x0, 0, x1 - x0) / (x1 - x0)`; `y = y0 + t * (y1 - y0)`; flat outside.
* **2-D table** (`fn_8826D278`): `XRelArray` -> 16-byte rows `{curve16 header (rel,count), u32 ?, f32 key}`, ascending key at +0x0C. For `x` find the last row with `x >= key`, interpolate **between that row's curve16(y) and the next row's curve16(y)**
  with `t = (x - key_lo) / (key_hi - key_lo)`; below the first key / above the last key only the nearest row's curve is used (no extrapolation). Called from the gameplay movement/reach code (`fn_88687D70`, `fn_88688678`, `fn_886887C0`,
  `fn_88688948`, `fn_8868B4E8`, `$LN886B88BC`), so reach/timing tuning tables are most likely stored in this form.
* All `x`/`y` units are those of the caller (ticks, cm, km/h; see gp2/gp3/gp4).

### 4.5 Ready-to-use converter plan
Once a real file is available: (1) locate rows by the kind hashes; (2) walk each 12-byte slot with the rules above; (3) emit JSON `{kind, T, spin:[{lo,hi}x3], bounce:{speed_loss, spin_decay, angle_out, yaw}}` with every curve as a list of keys. The evaluators are in
`src/xbox360/drafts/df_data_formats.c` and `src/xbox360/drafts/gp4_ball_flight.c`.


## 5. Havok

### 5.1 Version (H for the SDK, M for the shipped files)
* The engine links **Havok 5.5.0-r1** (Physics + Animation). Evidence: the version registry (`hkVersionRegistry` updater chain, 24 `Havok-x.y.z-*` strings at 0x8804F838 ... 0x8808B910) ends at `Havok-5.5.0-r1` (0x8808B910; the log
  string `Havok version: %s` is at 0x880C1214); the *current* reflection set (352 classes, section 5.5) has the 5.x animation class names (`hkaSkeletalAnimation`, `hkaSplineSkeletalAnimation`, ... renamed to `...CompressedAnimation` only in 6.0) and `hkaAnimationBinding`
  **without** `originalSkeletonName` (added in 6.0). The other 23 version strings (3.3.0-b1 ... 5.5.0-b2) are the chain `hkVersionUtil` uses to upgrade **older** packfiles in memory: each version has its own copy of the class tables (27 copies of the member
  arrays in `.data`, offsets 0 because only the current set carries offsets), so a file written by an older tool still loads.
* So "5.5.0-r1 strings alongside older" = the upgrade chain. The shipped `.hkx` should carry `contentsVersion = "Havok-5.5.0-r1"` (packfile header +0x28); **confirm on the first real file** (`tools/ts4data/hkx.py info`). If it says an older version, the member tables
  in 5.5 below do not apply byte-for-byte: use the matching version's tables (they are in the executable too, `0x88B3xxxx..0x88C1xxxx`, but without offsets).

### 5.2 Which files and which root classes the game reads (H)
| File | Loader | Reader steps |
|---|---|---|
| `Media\Animation\AOD\<id>.hkx` | `fn_886472C0` (called from `fn_886D2B58` async or sync) | memory stream over the file buffer (staging buffer <= 0xD2000 B) -> `fn_884CE818` (binary packfile reader `load`) -> root **hkRootLevelContainer**; `fn_884CCC70(root, hkClass 0x88CACC08 = hkaAnimationContainer)` = findObjectByType -> stored in `clip+0xC` |
| `Physics\Physics.hkx` (`Common\Physics\...`, `Physics\Physics`) | `fn_88880B88` (gp4) | same reader; root hkRootLevelContainer (hkClass 0x88D26F54); `findObjectByType(hkpPhysicsData)` (0x88D25C34) -> `this+0x18`; `findObjectByType(hkaRagdollInstance)` (0x88CACE78) -> `this+0x1C`; every `hkpPhysicsSystem` in `physicsData.systems` is walked, rigid bodies registered by name (`fn_8887B380`, `fn_88880168`) |
So a clip file = **hkRootLevelContainer { namedVariants: [{ name, className:"hkaAnimationContainer", variant -> hkaAnimationContainer }] }**; the container holds `skeletons[]`, `animations[]`, `bindings[]`, `attachments[]`, `skins[]`.

### 5.3 Packfile container (`hkBinaryPackfileReader` = `fn_884C9DD0` & friends; H for the 0x40 header read and magic check, M for the rest = Havok's published format)
```
0x00 u32 magic0 = 0x57E0E057        0x04 u32 magic1 = 0x10C0C010        (checked at 0x884C9E90..0x884C9EBC against the big-endian words; `tools/ts4data/hkx.py` also accepts little-endian files)
0x08 s32 userTag                     0x0C s32 fileVersion  (the reader branches on >= 4; older section headers are re-packed in place by fn_884C9F08)
0x10 u8  layoutRules[4] = bytesInPointer(4), littleEndian(0), reusePadding, emptyBaseClassOptimization
0x14 s32 numSections   0x18 s32 contentsSectionIndex   0x1C s32 contentsSectionOffset
0x20 s32 contentsClassNameSectionIndex   0x24 s32 contentsClassNameSectionOffset   0x28 char contentsVersion[16] ("Havok-5.5.0-r1")
0x38 s32 flags   0x3C s32 pad                                                       (= 0x40 bytes, member list confirmed by hkPackfileHeader reflection)
0x40 section headers, 0x30 bytes each (hkPackfileSectionHeader reflection: sectionTag char[19], nullByte, absoluteDataStart, localFixupsOffset, globalFixupsOffset,
     virtualFixupsOffset, exportsOffset, importsOffset, endOffset; all u32, offsets relative to absoluteDataStart)
section data = [absoluteDataStart, +localFixupsOffset); then local fixups, global fixups, virtual fixups, exports, imports up to endOffset.
  local fixup   {u32 srcOffset, u32 dstOffset}                 same-section pointer, table ends with 0xFFFFFFFF
  global fixup  {u32 srcOffset, u32 dstSection, u32 dstOffset}
  virtual fixup {u32 objOffset, u32 classNameSection, u32 classNameOffset}   object's class name = string at that offset of __classnames__
sections: "__classnames__" (entries: u32 signature, 0x09, name, NUL), "__types__", "__data__"
```
Pointers in the data region are 0 on disk; fixups say where they point. `hkReferencedObject` derived objects start with `{vtable ptr = 0 (virtual fixup), u16 memSizeAndFlags, s16 referenceCount}`. Structs without a reflected parent (hkaSkeleton, hkaBone,
hkaAnimationBinding, hkaAnimationContainer, hkaAnnotationTrack, hkRootLevelContainer, ...) start directly with their first member (offset 0). hkArray = `{ptr, s32 size, s32 capacityAndFlags}` (12 B), SimpleArray = `{ptr, s32 size}` (8 B), hkVector4 = 4 big-endian floats,
hkQsTransform = 48 B `{translation vec4, rotation quaternion xyzw, scale vec4}`, hkTransform = 64 B `{rotation as 3 column vec4, translation vec4}`, hkVariant = `{object*, class*}` (8 B), strings are `char*` fixed up to the string pool.

### 5.4 Reflection tables (H) -- how they were dumped
Static initialisers (one per class, e.g. `fn_88AED038` for `hkPackfileHeader`) call `hkClass::hkClass` (fn_8841F080, about 10,400 call sites: 362 with a non-zero objectSize = the current set, ~10,000 version-copy classes with objectSize 0) with `(this, name, parent, objectSize, interfaces, numInterfaces, enums, numEnums, members*, numMembers, defaults, attributes, flags)`;
the **current** set is the group whose objectSize is non-zero (call sites 0x889D3470..0x88AFEE08). `hkClassMember` = 0x18 bytes `{char* name, hkClass* class, hkClassEnum* enum, u8 type, u8 subtype, u16 cArraySize, u16 flags, u16 offset, void* attributes}`; `hkClassEnum` = 0x14 bytes
`{name, items*, numItems, attributes, flags}`, item = `{s32 value, char* name}`. Type codes (5.5): 1 bool, 2 char, 3 int8, 4 uint8, 5 int16, 6 uint16, 7 int32, 8 uint32, 9 int64, 10 uint64, 11 real(f32), 12 vector4, 13 quaternion, 14 matrix3, 15 rotation,
16 qstransform, 17 matrix4, 18 transform, 19 zero, 20 pointer, 21 functionpointer, 22 array(hkArray), 23 inplacearray, 24 enum, 25 struct, 26 simplearray, 27 homogeneousarray, 28 variant, 29 cstring, 30 ulong(u32 here), 31 flags, 32 half, 33 stringptr.
Member offsets are absolute from the object start (they include the parent's size). The full machine-readable dump is `work/df_readers/havok55_classes.json` (352 classes); the animation, skeleton and rigid-body subsets follow.

### 5.5 Class layouts

The full member tables (352 classes, offsets, types, enums) are derived from the
Havok SDK reflection embedded in the executable, so they are kept only in the
local, ignored `work/havok55_classes.json` and never committed (see AGENTS.md).
Regenerate them from your own `Swing_DLL.xex` with the procedure in 5.4.

### 5.6 What to extract and how
* **Skeleton** (`hkaSkeleton`): `name`, `parentIndices[i]` (-1 root), `bones[i]->name` / `lockTranslation`, `referencePose[i]` = (translation xyz w, rotation x y z w, scale x y z w) in **bone-local space**, `floatSlots[]`. Maps 1:1 to a glTF node tree (rotations are quaternions xyzw, same order as glTF).
* **Binding** (`hkaAnimationBinding`): `animation` pointer; `transformTrackToBoneIndices[t]` maps animation track t -> skeleton bone; `floatTrackToFloatSlotIndices`; `blendHint` 0 NORMAL, 1 ADDITIVE.
* **Annotations** (`hkaSkeletalAnimation.annotationTracks[]`: `hkaAnnotationTrack{name, annotations[{time (seconds), text}]}`): the contact/event markers if the exporter put them in the clip (3.2 shows the record table also has them).
* **Animation type** (`hkaSkeletalAnimation.type`): 1 interleaved (raw `transforms[pose*numberOfTransformTracks + track]`, `numberOfPoses = transforms.size / tracks`, trivial), 2 delta compressed, 3 wavelet, 5 spline (the expected production format).
  `duration` seconds; the engine times in 60 Hz ticks, `frame = round(time * 60)`.
* **Spline/Delta/Wavelet payload decoding is NOT implemented** (`tools/ts4data/hkx.py` returns the raw `data[]` bytes and the offsets arrays). Spline layout hints from the class: `numFrames`, `numBlocks`, `maxFramesPerBlock`, `blockDuration`, `blockInverseDuration`, `frameDuration`;
  per-block data located by `blockOffsets[block]`, per-track data by `transformOffsets[...]`/`floatOffsets[...]`; `maskAndQuantizationSize` is the size of the per-track mask+quantisation header region; `endian` records the byte order the buffer was written in.
  The track compression parameters (`hkaSplineSkeletalAnimationTrackCompressionParams`: rotation/translation/scale degree and `RotationQuantization {POLAR32, THREECOMP40, THREECOMP48, THREECOMP24, STRAIGHT16, UNCOMPRESSED}`, `ScalarQuantization {BITS8, BITS16}`) are the
  vocabulary of the bit stream. Decode it against the first real file (L).
* **Physics** (`Physics.hkx`): `hkpPhysicsData.systems[].rigidBodies[]`. Per body (offsets absolute): name `+0x70`, `collidable +0x10` (shape pointer at `+0x10`, `collisionFilterInfo` at `+0x10+0x14+8 = +0x2C`), material `+0x80` `{responseType i8, friction f32 @+0x84, restitution f32 @+0x88}`,
  motion `+0xD0` (type enum `+0xD8`; `motionState +0xE0`: `transform` 64 B at +0xE0, `linearDamping +0x184`, `angularDamping +0x188`; `inertiaAndMassInv +0x190` (w = 1/mass); `linearVelocity +0x1A0`; `angularVelocity +0x1B0`).
  Shapes: `hkpBoxShape.halfExtents`, `hkpSphereShape` (radius at +0x10), `hkpCapsuleShape`, `hkpCylinderShape`, `hkpConvexVerticesShape` (`rotatedVertices` in 4-wide SoA blocks `{x[4], y[4], z[4]}`), `hkpMoppBvTreeShape -> hkpSingleShapeContainer -> hkpMeshShape / hkpExtendedMeshShape / hkpStorageExtendedMeshShape`
  (triangle subparts with vertex/index base pointers and strides), `hkpListShape`, `hkpPlaneShape`, `hkpTransformShape`. `hkpWorldCinfo` (also embedded: `physicsData.worldCinfo`) holds gravity `+0x10`, solver settings, broad-phase AABB `+0x30`. Ball bounce/net/ground restitution used by gameplay is **not** from here (gp4: template data), only collision events.

### 5.7 Reader status
`tools/ts4data/hkx.py`: header, sections, all three fixup tables, `__classnames__`, object list, generic reflection-driven decode (`json` command) with a synthetic round-trip test. Not implemented: payload decoders (5.6), `variant` class pointer resolution beyond the object's own virtual fixup,
files whose layoutRules differ from 32-bit pointers, versions below file version 4.


## 6. Typed-struct hash catalogue (readers of `fn_88923530`)

`fn_88923530(server, handle, type_hash)` is the single gate to typed views; scanning the 303 call sites gives the type hash each reader function expects (`typed.py`-style backward scan of `r6`; hashes with >= 2 readers shown, reader = enclosing function VA).
Names are not in the binary (schema data), so use this as a **map from file type to loader code**.

| type hash | readers (count) | first reader functions |
|---|---|---|
| 0xf895ecb1 | 19 | 0x8878eb10, 0x8878eb58, 0x88793a78, 0x88798e68 |
| 0xa163c166 | 12 | 0x88632a18, 0x886591f8, 0x887316d0, 0x88755718 |
| 0x44f681fd | 6 | 0x8827ae98, 0x8827afa8, 0x8827b468, 0x8863cf38 |
| 0xd8683084 | 6 | 0x8878fc70, 0x887910f0, 0x887b8ad0, 0x888e7308 |
| 0x2e50c902 | 5 | 0x88795820, 0x8879a038, 0x8879e758, 0x88909988 |
| 0x5820d187 | 5 | 0x88845240, 0x8884fc28, 0x88855170, 0x88855420 |
| 0xbadce812 | 5 | 0x888e7cb8, 0x888ea860, 0x888efd68, 0x888fd530 |
| 0x25fcd125 | 4 | 0x886cc120, 0x886cc318, 0x886e08e8, 0x886e42c8 |
| 0x1e22d37 | 4 | 0x886e96c0, 0x886ea398, 0x888e7de0 |
| 0x4b9173e | 4 | 0x88790248, 0x887906f8, 0x88790750, 0x8879a038 |
| 0xc8071045 | 4 | 0x888e2178, 0x888e23f8 |
| 0x99b1270a | 3 | 0x8817ca20, 0x88855ca0, 0x8895cf28 |
| 0xa4ffc421 | 3 | 0x88662df0, 0x88662f10, 0x886b25b8 |
| 0x1e51c496 | 3 | 0x886e57a8, 0x888e5238, 0x8890b068 |
| 0xc5bbb5e0 | 3 | 0x88724620, 0x8895e320, 0x88967920 |
| 0xd4e409ab | 3 | 0x8873c4d8, 0x8873c6b8, 0x8873cc58 |
| 0xb20b8fea | 3 | 0x887c69c0, 0x8890a1f0, 0x8890c408 |
| 0x502fe79d | 3 | 0x887e0910, 0x888ba888, 0x889117b8 |
| 0xcd5f7823 | 3 | 0x88845240, 0x8884f160 |
| 0x210d0583 | 3 | 0x8893d738, 0x8899b610, 0x889b13b0 |
| 0xe46e8338 | 3 | 0x88942e20, 0x88942f00, 0x88954aa8 |
| 0x938cf8e4 | 2 | 0x881ec6d8, 0x881ec8c8 |
| 0x9cf8f2c6 | 2 | 0x8861e348, 0x8862c830 |
| 0xa9572148 | 2 | 0x8861e348, 0x8862c830 |
| 0x9ae18d8f | 2 | 0x8862c9c8, 0x8862ca80 |
| 0x30a24423 | 2 | 0x8864a1e0, 0x8864a348 |
| 0x5e16cf76 | 2 | 0x886e57a8, 0x88921d18 |
| 0x3a60fee2 | 2 | 0x886e57a8, 0x888eebb0 |
| 0xd3994f67 | 2 | 0x886fda18, 0x8873d1c8 |
| 0x416cb332 | 2 | 0x88777e08, 0x888bd828 |
| 0x3fe036f3 | 2 | 0x887909b8, 0x88798e68 |
| 0x9bd6c66b | 2 | 0x88845240 |
| 0x46467307 | 2 | 0x8884e988, 0x8890b068 |
| 0x5acf2048 | 2 | 0x888e5238, 0x888e7928 |
| 0xf7236dd | 2 | 0x888e7de0 |
| 0xd39f6d85 | 2 | 0x8893faa8, 0x889b8460 |
| 0x921d9ba0 | 2 | 0x889c7fa8, 0x889c8148 |

Single-reader types already tied to gameplay data: 0xEE710815 AnimationDB root (`fn_886E3A00`), 0x7600225C SbikAnimationDB, 0x1E51C496 per-player record array (`fn_886E57A8`, `fn_888E5238`, `fn_8890B068`; stride 0x140, byte +0x120 active),
0x5E16CF76 gameplay frame block (`fn_886E57A8`, `fn_88921D18`), 0x3A60FEE2 AnimationData root (`fn_886E57A8`, `fn_888EEBB0`), 0x1367BD6D, 0x56931990 Physics.bin world/object config (`fn_88880440`), 0x2FEF2019 engine config (`fn_886BC678`),
0x63F5A11F GameplayInputs (`fn_88790DA0`), 0x502FE79D PlayerStates (`fn_887E0910`, `fn_888BA888`, `fn_889117B8`), 0x3BE499EE scene module/object list (`fn_889C78C8`; `{rel,count}` of 4-byte class hashes at root +0x1C), 0x921D9BA0 data-log append (`fn_889C7FA8`).

## 7. Reproducing (commands)
```
python3 -c 'import zlib; print(hex(zlib.crc32(b"EventRacket")))'    # 0x3b9ad22e: every name is zlib.crc32 of the ASCII string
python3 -I tools/ts4data/xbin.py selftest
python3 -I tools/ts4data/arc.py hash 'Media\Animation\AOD\1.hkx'
python3 -I tools/ts4data/hkx.py selftest
python3 tools/fn_asm.py fn_8892A968        # XBin parse; fn_88922710 Load; fn_886217C0 .arc open; fn_8827EC98 FAT lookup; fn_886090A0/fn_886084C8 path hash
python3 tools/fn_asm.py fn_881899D8 fn_8817A688 fn_8826D278 fn_889C1868   # curve / table formats
python3 tools/fn_asm.py fn_886472C0 fn_88880B88                              # hkx loads
```
The class table dump (`havok55_classes.json`) was produced by a register tracker over the `hkClass::hkClass` static initialisers (call to fn_8841F080); member records at `members*`, 0x18 bytes each, enums 0x14 bytes each.
The PE image was read directly (sections: .rdata 0x88000600, .text 0x88150000, .data 0x88B25C00; file offsets from the PE section table). Functions inside matched sources are not in the split objects, so `tools/fn_asm.py` cannot print them;
a raw-address disassembly through `work/ppcdis/target/release/ppcdis` on the PE image was used for those (e.g. fn_8892F468).

## 8. Open items and first steps when data arrives
1. **First file**: run `tools/ts4data/xbin.py info/scan` on `Animations.bin`. Expected: `w4` = file offset of a u32 table whose entries ascend and fall inside the file; `body+0x50` is a plausible `{rel,count}`; the count equals the number of records and `rel` lands inside the file.
   If the root is not at body+0, search with `scan` for the header whose target array has stride 0x8C (all `id@+0x84` values distinct).
2. Record field names for the 0x8C records beyond id/ratio/slot/scale/annotations/segments are unknown (+0x00..+0x0B, +0x10, +0x18..+0x37, +0x48..+0x5B, +0x78..+0x83, +0x88); decode by correlating with clip names/ids from `AnimationsInterface.bin`.
3. `AnimationsInterface.bin`, `Global.bin`, `Behavior.bin`, `CoreTech_Xenon.bin` schemas: only loader entry points are known (fn_88773438, fn_8879A4F8..., fn_887F65B8, fn_889BD370); the typed-hash table in section 6 identifies which reader parses which node.
4. The shot-template table's source file and the XData binding that fills `S+0x3C` were not found (4.1).
5. `.arc`: FAT directory table, member compression flag, how `GameplayEOP.arc` members are named (hash only) - validate `tools/ts4data/arc.py list` on `Core.arc` first.
6. Havok: confirm `contentsVersion`, layoutRules of the Xbox files, animation type of the AOD clips; implement the spline decoder from a real clip. Left-handed clips: no mirrored files are known; mirroring is gameplay-side (gp7).
7. Endianness: all data is big-endian; PS3 data (separate target dir, Cell is also big-endian) must not be assumed to share layout rules or schema hashes.
