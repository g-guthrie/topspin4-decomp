# 3D assets: textures, meshes, materials, scenes (Top Spin 4, Xbox 360)

Agent `assets`. Everything below was measured on the retail disc image
`orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso` (SHA-256
`93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c`) with Python 3.14.6 and only the
standard library. Code confirmations come from `Swing_DLL.dll` (SHA-256
`a7f28b29ef72fcc88c9b7c8208d27367b2e1bcfdafbeaddc49b9e8d32f952ba9`, base `0x88000000`) read with
`tools/fn_asm.py`. No game data or SDK material is stored in the repository; exports go to `work/`
(git-ignored).

Tools: `tools/ts4_texture.py` (XPR2, Xenos untiling, DXT/CTX1/DXN decode, PNG writer),
`tools/ts4_mesh.py` (mesh records, PackedMaterials, PAM-XDT, scene transforms),
`tools/ts4_assets.py` (CLI: list, venue, player, textures, check). Tests: `tests/test_assets.py`
(synthetic data only, 32 tests). Archive access reuses `tools/xdvdfs.py`, `tools/ts4_arc.py` and the
skeleton reader in `tools/havok/`.

## 1. What is decoded

| Item | Status |
| --- | --- |
| XPR2 texture packs (`*.xpr`, `Textures.xpr`) | Decoded and checked visually: header, fetch constants, 2-D tiling, `DXT1`, `DXT4_5`, `CTX1`, `8_8_8_8`, linear and tiled layouts. Base mip only. |
| Mesh records (`PackedMeshes.xbin`, player part `*_000.xbin`) | Decoded: vertex declaration, vertex data, index buffers (`TriStrip`, `IndexedTriList`), groups, bone palette. |
| Skin weights / bone indices | Decoded (weights `UShort4N`, indices `UByte4`, byte order reversed relative to the weights); fit to the 71-bone skeleton verified. |
| `PackedMaterials.bin` (venues) | Decoded: single and multi materials, texture slots. Shader parameters and render states are **not** decoded. |
| Player material trees (`*.xdt`) | Decoded as generic trees; texture slots extracted. Parameters not interpreted. |
| `PAM-XDT` binary XML (`Hierarchy.xml`/`.xdt`, materials) | Decoded: token model and CRC names. |
| Scene graph (venue hierarchy) | Geometry placement decoded (SRP chains, mesh and material names). Yaw-only rotations verified; mixed-axis Euler order is an assumption. |
| glTF export | Venue (court, stands, roof, props) and player (body, head, outfit, racket) with PNG textures; player skinned to the 71-bone Havok skeleton. |
| Not decoded | Vertex/pixel shaders (`*.vso`, `*.pso`), cube maps (`TXCM`), mip chains, lightmap usage, crowd (`CrowdXXX.bin`), cloth (`CLTH_*.bin`, `CLMT_*.bin`), hair-bone physics, light data (`PackedLights.bin`), morph data, LOD distances, render states. |

## 2. Where things live

All archives are PAM-LZX `.arc` files (docs/disc-data.md). Member names are resolved by the directory
hash scheme; `tools/ts4_assets.py list ARC` prints the kind of every member
(`xpr2-textures`, `packed-meshes`, `packed-materials`, `mesh`, `xdt`, `havok`, `shader`, ...).

* **Venue archives** (38: `Amsterdam.arc`, `ArthurAshe.arc`, ...). Members that belong together share an
  archive *directory* (a directory hash, `Archive.dirs` in `ts4_assets.py`). A scene directory holds
  `Hierarchy.xml` (PAM-XDT or plain XML), `PackedMeshes.xbin`, `PackedMaterials.bin` (or `.xml`),
  `Textures.xpr` and sometimes `PackedLights.bin`. Amsterdam has 38 `PackedMeshes.xbin` and 22
  `Textures.xpr`; the stadium itself is the directory with the largest mesh file
  (`4975f0c0`: `PackedMeshes.xbin` entry `9bb3cc0a`, 3,233,915 B unpacked, 150 meshes;
  `Textures.xpr` entry `7cca87d4`, 37,531,660 B, 401 resources; `PackedMaterials.bin` entry `b595b634`,
  324 materials; `Hierarchy.xml` entry `08fe7d03`, 180,424 B, 235 Geometry nodes). The other directories
  are crowd members, cameras, props, UI scenes, each with the same member set.
  Each venue archive also holds shaders (`0x<hash>-0x<hash>.vso/.pso`, magic `102A1100`), FMOD banks,
  Lua, animation files and a `TrackSide.hkx` net rig (docs/havok.md).
* **Player archives** `Baked_<Player><n>.arc` (81): per part `M_<GROUP>_..._00_000.xbin` (mesh, LOD 0 file
  name suffix `_000`; `_100`, `_200` are lower detail files), `M_<GROUP>_..._00.xdt` (material tree),
  `<GROUP>_..._00.xpr` (default textures), outfit variants such as `M_TOP_PFEDB_FEDER_NIK_00_DST.xpr`,
  `CLTH_*.bin` / `CLMT_*.bin` (cloth, signatures `929c8457...`), `Physics.hkx`. `Baked_Federer0.arc`:
  105 entries = 55 `xpr2-textures`, 21 `mesh`, 22 `xdt`, 4 `cloth`, 1 `havok`, 1 hair mesh with
  signature `7d72a97d a12b5eb9` (`..._010.xbin`).
* **Other archives with meshes/textures** (listed with `list`, not exported): `PlayerCreator_Male.arc`
  (1,397 entries), `PlayerCreator_Female.arc`, `PlayerCreator_Common.arc` (1,058), the very large
  `PlayerCreator_*_Texture.arc` (about 0.7 GB each), `Core.arc` (shared textures such as the gradient
  ramps `C_FRS_*`, `C_SHW_ENVIR_*`, `C_ENV_*` cube maps; HLSL sources), `TopSpinAcademy.arc`,
  `LockerRoom.arc`, `PracticeGroundPart.arc`, `Global.arc`. `PlayerCreator_Common.arc` has linear
  (non-tiled) textures; the others are tiled.

## 3. XPR2 textures (`tools/ts4_texture.py`)

```
0x00 'XPR2'  u32 header_size  u32 data_size   (big endian; header_size counts the bytes after offset 12)
0x0C u32 count
0x10 count x { u32 type ('TX2D' or 'TXCM'), u32 offset, u32 size (0x34), u32 name_offset }
     offset and name_offset are relative to file offset 0x0C
...  one 0x34 byte header per TX2D: D3DResource (6 dwords) + 2 flush dwords + GPUTEXTURE_FETCH_CONSTANT (6 dwords at +0x1C)
...  NUL-terminated names, then the data section at file offset 12 + header_size
```

Fetch constant fields used (Xenos register layout, as in the BSD-licensed Xenia `xenos.h`
`xe_gpu_texture_fetch_t`): dword0 bits 22-30 pitch (32-texel units) and bit 31 tiled; dword1 bits 0-5
format, 6-7 endianness, 12-31 base address (offset into the data section); dword2 bits 0-12 width-1 and
13-25 height-1; dword4 bits 6-9 max mip level; dword5 bit 9 packed mips and bits 12-31 mip address.
Texture names are at most 20 characters in venue packs (`Groun_Playa_01_2D_Di`, i.e. the name is
cut by the exporter); player packs keep long names (`M_HUM_CHEST_XXXXX_XXX_00_2D_DI_R`). Suffixes: `_Di`/`_DI`
diffuse, `_Bu`/`_BU` bump (CTX1 normal map), `_Sp`/`_SP` specular, `_Oc` occlusion, `_Sh` shadow, `_LM`
lightmap ramp, `_GR` gradient, `_CU` cube.

**Code confirmation.** `fn_887C8A78` is the engine's XPR loader: it reads 12 bytes and requires
`0x58505232` (`'XPR2'`; `'XPR1'` gets its own error message at `0x880EA474`, anything else the message at
`0x880EA4B4`), reads `header_size` bytes and `data_size` bytes into two buffers, then walks the table
(`count` at the start of the header buffer, 16-byte entries, name pointer = header base + name_offset) and,
for every entry whose type high half is `0x5458` (`'TX'`), calls `fn_882A9868`. That function adds the data
buffer address to the page-aligned part of header `+0x20` (fetch dword1, base address) and, when the mip
count is above 1, to header `+0x30` (fetch dword5, mip address): exactly the fields decoded above.
`fn_886F5280` is the matching writer used by the tools: it stores `0x54583244` (`'TX2D'`), the offset,
the size `0x34` and a copy of the name in a 16-byte entry.

**Formats seen** (TX2D resources; `tools/ts4_assets.py textures` prints them per file). Counts from
`Textures.xpr` of Amsterdam (entry `7cca87d4`): 392 TX2D = 336 `DXT1`, 39 `CTX1`, 15 `DXT4_5`, 2
`8_8_8_8`, plus 9 `TXCM` cube maps (not decoded). A header-only survey of 258 packs in Amsterdam,
`Baked_Federer0`, `Baked_Safina1`, `TopSpinAcademy`, `LockerRoom`, `PracticeGroundPart` and
`PlayerCreator_Common` (`work/agents/assets/scratch/survey.py`): 467 `DXT1`, 347 `DXT4_5`, 259
`8_8_8_8`, 125 `CTX1`; 30 `TXCM`; 4 formats in total. Of those 163+283+251+19 are tiled and 304+64+8+106
are linear (the linear ones all come from `PlayerCreator_Common` and the `*_BAB_*`/`_F` racket
textures). Endianness: `DXT*`/`CTX1` use mode 1 (8-in-16), `8_8_8_8` mode 2 (8-in-32); every file seen is
big endian and needs the byte swap before block decode. `8_8_8_8` is stored `A R G B` after the swap.
`CTX1` is a two-channel (X, Y) normal-map format: `ts4_texture.reconstruct_normal_map` rebuilds Z.
The channel order of CTX1 is taken from the public Xenos description and is not verified against shading.

**Tiling.** `tiled_offset(x, y, width, log_bpp)` is the Xenos 2-D tiling (`XGAddress2DTiledOffset`, public
formula also found in Xenia's `TextureInfo::TiledOffset2D*`): 32x32 block macro tiles, row pitch aligned to 32
blocks, blocks are 4x4 texels for DXT/CTX1/DXN. Verified on real `DXT1` (8 B blocks), `DXT4_5` and
`8_8_8_8` (4 B) data: decoded PNGs are free of tile seams (the spectator atlas, the Federer head and shirt
maps, the court). For 1- and 2-byte formats the formula is not a bijection on a single 32x32 tile and was
not checked; no such texture exists on the disc. Linear textures use a row stride of `pitch * 32 / 4`
blocks.

## 4. Mesh records (`tools/ts4_mesh.py`)

Containers (XBin images, docs/disc-data.md section 3, 20 byte header, self-relative pointers):

| Signature (a, b) | Content |
| --- | --- |
| `7d72a97d 3f65f116` or `6912b1b8 3f65f116` | `PackedMeshes.xbin`: root descriptor at `0x14` -> array of 0x60 byte mesh records from `0x20`. `7d72...` are scene meshes, `6912...` UI meshes. |
| `a4b9371d 330fac24` | one mesh record at `0x14` (player parts, racket) |
| `7d72a97d a12b5eb9` | single hair/cloth mesh (not exported) |
| `ecc4f93b 2e4f521c` | `PackedMaterials.bin` |

Pointer words hold a signed offset relative to their own address (`0xFFFFFFFF` = none); an array descriptor
is `{rel, count, capacity}` with elements at descriptor address + rel.

Mesh record (offsets from the record start):

```
+0x00..0x14 six string pointers: version, date, user, computer, max path, max file
+0x18       -1
+0x1C       -> group array descriptor (0x38 byte groups) or -1
+0x20       -> bone-name array descriptor (array of string pointers) or -1
+0x24       -> bounds data (not decoded)
+0x28..0x4C ten vertex element slots: position, normal, tangent, colour, uv0, uv1, uv2, uv3, blend weights, blend indices
            each slot -> cell -> format name string, or -1
+0x50       -> vertex array descriptor (count = vertices; the raw vertices follow, stride = sum of element sizes)
+0x54       u32 layout tag, +0x58 -> mesh name, +0x5C -> (unused)
Group (0x38): index descriptor {rel,count,cap} of u16, -1/0, 0, 0, ->bounds, 1, ->group name, ->primitive type
              ("TriStrip" / "IndexedTriList"), 1, 0, primitive count, index count
```

Vertex element formats (D3DDECLTYPE names, sizes): `C3DVector` 12 (3 f32), `C2DVector` 8, `C4DVector` 16,
`Float16_2` 4, `Float16_4` 8, `Dec3N` 4 (2_10_10_10 signed normalised, x in the low 10 bits, 511 = 1.0),
`D3DColor` 4 (ARGB), `UShort4N` 8, `UByte4` 4. Elements are packed in slot order with no padding, big endian.
Triangle strips contain degenerate joins and no restart index; `Group.triangles()` drops degenerates and
flips every odd triangle.

**Code confirmation.** `fn_88749920` builds the Xbox 360 `D3DVERTEXELEMENT9` array from the record: it reads the slot
pointers at `+0x28, +0x2C, ...`, compares the format names (`Float16_4`, `C3DVector`, `Dec3N`, `D3DColor`,
`Float16_2`, `C2DVector`, `UShort4N`, `C4DVector`, `UByte4` at `0x880D3890-0x880D3908`) and fills each element
with offset, type word (`0x002A23B9` float3, `0x002A2187` Dec3N, `0x001A2360` float16x4, `0x002C235F` float16x2,
`0x002C23A5` float2, `0x001A23A6` float4, `0x001A205A` ushort4n, `0x001A2286` ubyte4, `0x00182886` color) and usage
(`0` position, `3` normal, `6` tangent, `10` colour, `5` texcoord 0-3, `1` blend weight, `2` blend index).
Offsets advance by 12/4/8/16 as in `FORMAT_SIZES`. `fn_887395A8` walks the groups (`mulli r9, r9, 0x38`,
group array pointer at record `+0x1C`, `-1` test) and tests the names `IndexedTriList` / `TriStrip`
(`0x880D3854`, `0x880D3864`). The file names are used by `fn_8875EDF0` (`PackedMeshes.xbin`, string `0x880F056C`), `fn_887615A8`
(`PackedMaterials.bin`/`.xml`, `0x880F053C`/`0x880F0528`) and `fn_88754DC0` (`Textures.xpr`, `0x880F04F8`);
`fn_88767F98` references all of them (the scene-level load).

**Layouts seen.** Amsterdam `PackedMeshes.xbin` (150 meshes): 76 x position+normal+tangent+uv0+uv1 (28 B),
40 x position+normal+tangent+uv0 (24 B), 27 x with colour (32 B, vertex colour looks like baked ambient
occlusion, not interpreted), 4 skinned (spectators/ballboys, 36 B), 1 x two uv sets skinned, 1 x three uv sets.
Player parts are all 36 B: `C3DVector Dec3N Dec3N Float16_2 UShort4N UByte4`. Venue UV0 is a wrapping tile
UV (values outside [0,1], sampler WRAP); UV1 is a second set (lightmap), range [0,1] except two camera-prop
meshes.

**Skinning (player parts).** The bone palette is the name array at `+0x20` (53 names for the body, 5 for the head,
15 for the shirt, ...) and is mapped to the skeleton by name (`B_Hips`, `B_LeftArm`, ...). The index byte order
is reversed: weight `i` pairs with index byte `3 - i` (fit of the body mesh: median distance to the dominant bone
segment 0.04 m with this pairing, 0.46 m or more with the plain order). The mesh frame is related to the Havok
skeleton frame by `(x, y, z)_skeleton = (z, y, -x)_mesh`, a pure rotation (the skeleton's root carries a
90 degree yaw); the meshes are modelled in the skeleton's reference pose (T pose), so the inverse bind
matrices are the inverse reference-pose world matrices of `tools/havok`. Palette bones missing from the 71-bone
skeleton are hair physics bones (`Bone01..Bone19`); they are skinned to `B_Head`. Racket meshes
(`C_RAC_*`, bone `B_Racket_Handle`) are modelled in the bone's own space and are attached as child nodes of the
bone instead of being skinned.

**LODs.** A player mesh stores N equal sets of groups (body 3 x 11, head 3 x 2, hair 3 x 10) with decreasing
index counts; the order is not fixed (body: mid, low, high). `pick_lod0` takes the set with the most indices.
Group names are `GRP_<PART>_nn` for the body and `KeyNull` for the others; a group maps to sub-material
`i` of its set (body: by the part token CHEST/ARMS/LEGS, PELVIS -> legs, HANDS -> arms, assumption).

## 5. Materials

`PackedMaterials.bin` (venue): root descriptor at `0x14` of 8-byte `{rel, type}` entries. Type `0x44F681FD`: a
single material, 0x70 byte header: `+0x48` descriptor of texture slots (stride 0x5C: 12 byte sampler-state
descriptor, `crc32(sampler name)`, 76 byte NUL padded texture name), `+0x60` pointer to the material name.
Type `0x64621D6E`: multi-material, `{rel,count,cap}` of single headers (stride 0x70) at `+0x00` and the name
pointer at `+0x0C`; mesh group `i` uses sub-material `i`. Sampler names recovered by hashing: `DiffuseMap`
(`c73d1ca5`), `Cloudmap1`, `ShadowDepthMap...`; 586 of 590 diffuse names of Amsterdam resolve in
`Textures.xpr` (the rest are runtime textures `ScoreboardTexture`, `SpeedOMeterTexture`). Other property
arrays (colours `DiffuseColor`/`SpecularColor`, floats, enum hashes for WRAP/CLAMP/LINEAR) exist but are not
interpreted. Material names carry `LOW` variants (`ShaderLOD` lists) that are not exported.

Player materials are `PAM-XDT` trees: `Material` (Name) -> sub-materials (Name) -> shader node -> sampler
nodes (Name = sampler such as `DiffuseMap`, `BumpMap`, `FilterReflectMap`, `ReflectGradientMap`, a
descendant string = texture name, e.g. `M_HUM_CHEST_XXXXX_XXX_00_2D_DI_R_Player00`). The `_Player00` suffix is
replaced by the player's variant at run time; the exporter strips it and falls back to a prefix match, which gives
the neutral default textures (`..._2D_DI_R`). Outfit/skin variants live in the `*_DST/_GRA/_SWE`, `_1_0`, `_2_0`
packs and are not selected by the exporter.

## 6. PAM-XDT (`ts4_mesh.parse_xdt`)

`"PAM-XDT\0"`, u32 1, u32 4, u32 data_size, u32 token_size, then the data section (attribute values in document
order, 4-byte aligned: strings NUL terminated, f32, bytes) and the token section of 12-byte tokens. An element
token is `{crc32(name), n_attributes, n_children}`; it is followed by its `n_attributes` attribute tokens
`{crc32(name), type, size}` (type 4 string, 3 f32, 1 byte) and then its children. Names are CRC-32 of the XML names
(`Hierarchy`, `Geometry`, `Mesh`, `Material`, `SRP`, `Scale`, `Rot`, `Pos`, `X`...); the vocabulary in
`XDT_ELEMENTS`/`XDT_ATTRS` was built from the plain-XML hierarchies of the same archives. Unknown names print
as `0x........`. Plain `Hierarchy.xml` files (crowd members) are ordinary XML and `ts4_assets.parse_hierarchy`
reads both. 10,854 tokens of the Amsterdam hierarchy parse with no leftovers.

Venue transforms: a node's `SRP` holds `Scale` (xyz), `Rot` (Euler radians; only yaw about Y occurs on placed
props) and `Pos` (centimetres). The world matrix is the product down the tree (57 `WorldSRP` blocks present in the
Amsterdam file match the composed positions in 55 cases; the two outliers are lights). The row-vector matrix used
is `S * Rz(roll) * Rx(pitch) * Ry(yaw) * T` (D3DX convention); for pure yaw this reproduces the file, for mixed axes
it is an assumption.

## 7. Coordinate system and glTF conventions

The game uses a left-handed, Y-up system in centimetres (the skeleton's right foot is at +Z with the character
facing -X; triangle strips are clockwise when seen from the front, 11,379 of 11,384 body triangles have a geometric
normal opposite to the stored normal under the right-handed formula). The glTF files are right handed, Y up,
metres: every position and normal has its z negated and is scaled by 0.01; triangle index order is unchanged
(this turns the clockwise fronts into counter-clockwise ones). Node matrices are conjugated with the same z mirror
(`M * W * M`, translation scaled). Players are first rotated into the skeleton frame
`(x, y, z) -> (z, y, -x)` and the skeleton joints are mirrored the same way (translation z negated,
quaternion `(x, y, z, w) -> (-x, -y, z, w)`), so a skin in the exported file bind-poses correctly and Havok
animations exported by `tools/havok/gltf_export.py` need the same mirror before they can drive it.
UVs are used as stored (origin top left, no flip).

## 8. Export commands

```
ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"          # or export TS4_ISO=...
export HAVOK_CLASSES=work/havok/classes.json      # only for players: python3 tools/havok/dll_classes.py orig/54540859/Swing_DLL.dll
python3 tools/ts4_assets.py list    Amsterdam.arc               # members with kinds; scene directories
python3 tools/ts4_assets.py venue   Amsterdam.arc --out work/assets/venue_Amsterdam     # about 1.5 min
python3 tools/ts4_assets.py player  Baked_Federer0.arc --out work/assets/player_Federer0 # about 1.5 min (first run caches Core)
python3 tools/ts4_assets.py textures Baked_Federer0.arc HUM_BODYX_XXXXX_00.xpr --out work/assets/tex
python3 tools/ts4_assets.py check   work/assets/venue_Amsterdam/venue.gltf
python3 -m unittest tests.test_assets
```

`venue` writes `venue.gltf`, `venue.bin`, `textures/*.png`; `--dir HEX` selects another scene directory of the
archive, `--all` includes helper meshes (shadow cards, dummies, UI quads, sun/volumetric billboards) that are
skipped by default. `player` writes `player.gltf` with 71 joint nodes, one skin, one node per part; it decompresses
the 34 MB Core skeleton container once into `work/assets/cache/core_6932352f.hkx`. `--skeleton-index 1` uses the
second Core skeleton, `--skeleton-source cutscene` the one in `CutScenes.arc` entry `0026b42b`, `--skeleton-hkx FILE` any
packfile. Material `extras` list every resolved texture slot (diffuse, bump, specular, ...); only the diffuse map is
wired to `baseColorTexture`. Alpha textures (`DXT4_5` with transparent texels) set `alphaMode: MASK`.

## 9. Structural checks (local exports, Federer0 and Amsterdam)

`tools/ts4_assets.py check` verifies every exported primitive: index range, triangle count, UV range, normal length,
joint range, weight sums, PNG decode and a fit test of the skin. Results (regenerate with the commands above):

| Export | Meshes | Vertices | Triangles | Textures (PNG) | Problems |
| --- | --- | --- | --- | --- | --- |
| `venue_Amsterdam` (court, stands, roof, barriers, props; 192 nodes, 178 material slots resolved) | 122 | 115,388 | 116,641 | 90 | none: indices in range, normals unit length (after renormalising the few unnormalised `RoofCam01` normals) |
| `player_Federer0` (body, head, shirt, shorts, socks, shoes, laces, wristbands, eyes, lashes, mouth, bandana, racket + strings) | 16 | 11,873 | 18,630 | 17 | none: joints < 71, weights sum to 1 |
| `player_Safina1` (female parts, Core skeleton 0) | 15 | 13,006 | 19,870 | 15 | none |
| `venue_ArthurAshe` (auto-selected directory `6b2e7ea5`) | 133 | 137,999 | 114,436 | 60 | none |

* Venue court geometry in metres: `GroundLines` x +-12.03, z +-5.59 (a 23.77 m x 10.97 m court plus lines), net posts at
  x = 0, z +-6.3, `Ground_Playable00/01` x +-25.8, z +-20.9, stands `Tribu_NE01` z -41.5..-12.4, roof out to 91 m.
* UVs: player parts are all inside [0, 1.001]. Venue UV0 wraps (34,506 of 138k vertices of Arthur Ashe are outside
  [0,1], tiling terrains and stairs; Amsterdam has a few helper meshes with extreme values, range -23840..15256),
  UV1 is inside [0,1] except 832 vertices on two camera props.
* Skin fit (distance of each vertex to the segment of its dominant bone, metres): Federer body median 0.04
  (p95 0.2 over all parts), Safina body 0.055 with Core skeleton 0 and 0.053 with skeleton 1 (no clear winner;
  both Core skeletons have the same bone names). A side-view software render of the bound player shows
  correct anatomy facing -X.
* Texture plausibility: all 17 Federer PNGs decode to non-degenerate images (head map mean 94, sd 76 with a clear
  face; shirt map with logo; skin maps are flat neutral tones, sd about 10). Flat images are legitimate solid
  masks (eyelash, laces, ground lines).

## 10. Open items and how a port should consume the output

* Shaders: the retail pixel shaders implement `PamOrenNayarBlinn` lighting with reflection cube maps, projected
  environment light, shadow maps and sweat/wrinkle maps; none of that is decoded, so the glTF carries only diffuse
  colour (bump/specular/occlusion/lightmap names are in `material.extras`). A port needs its own lighting.
* Lightmaps: venue meshes have a second UV set and `_Sh`/`_Oc`/`_LM` textures; their blend is unknown.
* Crowd: `CrowdAmsterdam.bin` (crowd placement) is not decoded; the spectator meshes (`SpectatorW01`, `Vip00`, ...)
  live in their own scene directories and are not part of the stadium export.
* Cloth and hair physics (`CLTH_*`, `CLMT_*`, `Physics.hkx`, `Bone01..`), morph targets (`*_Morph_*.xbin`), facial
  rig, wrinkle maps, player-specific outfit/skin variant selection.
* Cube maps (`TXCM`) and mip chains are not decoded; DXT mips could be added from `mip_address`.
* The mixed-axis Euler order of `SRP.Rot`, the body group -> material mapping for `PELVI`/`HANDS`, the CTX1
  channel order and the `Float16`/`Dec3N` sign conventions on venue vertex colours are assumptions.
* To consume: load `*.gltf` with any glTF 2.0 loader; scale is metres, Y up, right handed. For gameplay, take bone
  names from `skins[0].joints` (identical to the Havok skeleton, same order) and drive them with clips from
  `tools/havok` after applying the z mirror documented above. The court lines are in `Ground_*`/`GroundLines` nodes;
  the net posts, barriers and stands are separate nodes so a port can swap or hide them.
