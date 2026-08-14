# Target identity

A decompilation must name one exact executable. Region, update version, and platform can change addresses, code generation, imports, and assets.

## Locked Xbox 360 retail baseline

| Field | Value |
| --- | --- |
| Container size | `7,838,695,424` bytes |
| Container SHA-256 | `93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c` |
| Filesystem | UDF 1.5, label `CD_ROM` |
| Visible roots | `$SystemUpdate`, `AUDIO_TS`, `VIDEO_TS` |
| Classification | Xbox 360-style optical-disc image |
| Title ID | `54540859` (`TT-2137`) |
| Media ID | `60819732` |
| Executable version | `0.0.0.3` |
| Disc / region | 1 of 1 / all regions |
| `default.xex` size | `638,976` bytes |
| `default.xex` SHA-256 | `2d72e84feab9a84ac0e1239785a9af1ed7b6e693cf39041f206a92ac9454ce28` |
| Image load address / size | `0x82000000` / `0x00180000` |
| Additional modules | `Loader_DLL.xex`, `Swing_DLL.xex` |

The filename is not treated as provenance. The unusually old filesystem timestamp is also not treated as a release date.

## Scope decision

This project targets the Xbox 360 build. Analyze Xenon big-endian PowerPC/VMX code and use Xenia Canary for runtime validation. The PS3 build is out of scope.

Title updates are derivative targets, not replacements for this baseline. Record each update's package hash, media compatibility, resulting executable hash, and behavioral changes separately.
