# Updates, DLC, and community modifications

## Current finding

No credible expanded Xbox 360 ROM or maintained Top Spin 4 content-mod project was found as of 2026-08-14.

Static analysis now confirms that the retail game has a separate downloadable data-patch system. `Swing_DLL.xex` contains a `TitleServer_GetPatch` command, a `CPatchManager`, temporary-patch handling, and names for patch archives and descriptors. None of those downloadable payload files exists in the extracted retail disc. See [title-server-patch.md](title-server-patch.md).

What does exist:

1. **One conventional Xbox title update.** XboxUnity currently lists exactly one update for title `54540859` and media `60819732`: version `1`, base version `00000003`, database ID `21675`, SHA-1 `95FB351098AC7E4E6996CE5EC781ABE0F87BC929`, uploaded 2011-06-08. Its package has not been downloaded or accepted into this project.
2. **Separate in-game data patches.** Historical players distinguish Microsoft's title update from multiple updates fetched from the now-offline 2K server. The executable confirms that delivery path, but the payloads and exact final balance state are not yet recovered or verified. This likely explains claims of three or four "patches."
3. **Agassi preorder content.** Contemporary reports describe an Andre Agassi vintage/third-outfit unlock. This is cosmetic optional content, not a roster or feature expansion.
4. **Save/XP editors.** Old tools advertised as "Top Spin 4 mod tools" edit player progression or save data. They do not contain a reconstructed game or expanded roster.
5. **Emulator patches.** The Xenia Canary game-patches repository currently has no patch file for title ID `54540859`.

The documented May 2011 Xbox patch enabled D-pad movement and fixed career ranking calculations, camera persistence, presentation bugs, crashes, and several online/world-tour problems. It did not add players, courts, or a new game mode.

## Title Update #1 (supplied locally, 2026-11-13)

The user supplied the title update package locally. It is kept under ignored
`orig/54540859/tu1/` and is a separate target from the retail baseline.

- Package: STFS `LIVE`, 2,510,848 bytes, SHA-256
  `892738e0cdad221c8049ba5480ec3616e4f0cf94aca8ca44935f07c4745abce4`, SHA-1
  `47dc3c29c21ea53064a9074f227395d894b0af25` (XboxUnity lists `95FB3510...`, which
  does not hash the same bytes; it may be a content hash).
- Header (`python3 tools/stfs.py info`): title `54540859`, media `60819732`,
  content type `000B0000`, display name "Top Spin 4 Title Update #1".
- Contents (`python3 tools/stfs.py list`), SHA-256 of each extracted file:

| File | Bytes | SHA-256 | Notes |
|---|---:|---|---|
| Boot.bin | 64 | `220bad74...35a7f` | |
| CoreTech_Xenon.bin | 66,352 | `db6471dc...0ec03` | XBin; holds the module scheduler config (see docs/gameplay/gp0.md) |
| default.xexp | 124,928 | `1ba6119f...d3fc7` | XEX2 delta patch for default.xex |
| Layoutall.bin | 761,068 | `d734143d...502a0` | XBin layouts |
| Loader_DLL.xexp | 55,296 | `9666df4d...0f657` | XEX2 delta patch |
| Swing_DLL.xexp | 862,208 | `d5837ef9...726ed` | XEX2 delta patch for the gameplay module |
| TitleUpdate.arc | 555,570 | `729235a9...0ce26` | `.arc` archive, 56 members (`tools/ts4data/arc.py list`) |

The patched Swing module is a different executable from the matching
baseline and must get its own hashes and target directory before any
analysis is counted.

## Compatibility rule

Never apply a title update or optional-content package merely because it says *Top Spin 4*. It must identify title ID `54540859` and be compatible with media ID `60819732` or explicitly document a supported cross-media relationship.

Updates belong under Xbox content type `000B0000`; DLC belongs under `00000002`. These packages remain local and ignored. Record only hashes and original analysis.

## Runtime baseline

The current Xenia Canary compatibility report for `54540859` says default 720p settings can complete a match, while upscaling may crash and frame rates above 60 alter game speed. This project must validate its own exact media ID and executable before using those reports as an oracle.

## Sources

- [Xenia Canary Top Spin 4 compatibility report](https://github.com/xenia-canary/game-compatibility/issues/358)
- [Xenia Canary title-update installation notes](https://github.com/xenia-canary/xenia-canary/wiki/FAQ)
- [Xenia Canary game-patches repository](https://github.com/xenia-canary/game-patches)
- [XboxUnity title-update database](https://www.xboxunity.net/)
- [Historical patch discussion](https://forums.operationsports.com/forums/forum/other-sports/tennis/421154-top-spin-4-patch-available-now-post-your-impressions-here-ps3-360)
- [Historical DLC/update discussion](https://forums.operationsports.com/forums/forum/other-sports/tennis/882481-is-there-a-way-i-can-get-the-top-spin-4-patches-dlcs-and-updates)
