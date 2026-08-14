# Target identity

A decompilation must name one exact executable. Region, update version, and platform can change addresses, code generation, imports, and assets.

## Local candidate measured on 2026-08-14

| Field | Value |
| --- | --- |
| Container size | `7,838,695,424` bytes |
| Container SHA-256 | `93f3436310632c59334fd5df0f2e7d7a8350e867ce7e354780c871dfbf8f3e5c` |
| Filesystem | UDF 1.5, label `CD_ROM` |
| Visible roots | `$SystemUpdate`, `AUDIO_TS`, `VIDEO_TS` |
| Classification | Xbox 360-style optical-disc image |
| PS3 markers | No `PS3_GAME` tree found |

The filename is not treated as provenance. The unusually old filesystem timestamp is also not treated as a release date.

## Decision required

- **Xbox 360:** extract and identify `default.xex`; analyze Xenon big-endian PowerPC/VMX code and use Xenia for runtime validation.
- **PlayStation 3:** provide a lawful PS3 disc dump; identify `PS3_GAME/USRDIR/EBOOT.BIN`; analyze Cell PPU big-endian PowerPC code and use RPCS3 for runtime validation.

Do not mix measurements or symbols from the two builds.
