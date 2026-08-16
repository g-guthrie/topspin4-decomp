# Static-analysis status

## Reproducible baseline

The three retail XEX modules were imported with Ghidra 12.1.2 and XEXLoaderWV 12.1.2 using `PowerPC:BE:64:A2ALT-32addr:default`. Reports and Ghidra project data remain under ignored `work/`; only measurements and original tooling are committed.

| Module | Image base | Entry point | Ghidra functions | Thunks |
| --- | ---: | ---: | ---: | ---: |
| `default.xex` | `0x82000000` | `0x82019F68` | 503 | 5 |
| `Loader_DLL.xex` | `0x83000000` | `0x833E0E80` | 8,786 | 34 |
| `Swing_DLL.xex` | `0x88000000` | `0x88562DB0` | 32,506 | 34 |
| **Total** | | | **41,795** | **73** |

This is a discovery denominator, not a claim that every boundary is correct. It may change when bad disassembly is removed, missed functions are recovered, or thunks are normalized. The current reviewed counts are 149 named functions, one hundred twelve semantic source drafts, one hundred twelve validated reconstructions, and one hundred twelve compiler-matched functions.

The initial import incorrectly marked the shared `_savegprlr_14` through `_savegprlr_29` helpers as non-returning. The reproducible repair script corrected 11,645 call sites and recovered complete bodies for affected callers. This materially improves the decompiler output without changing the current function denominator.

## Import warnings to audit

- XEXLoaderWV reported `out of input bytes (LzxDecompression)` after loading the declared sections of each module. All three programs were still analyzed and saved.
- Ghidra reported unresolved PowerPC/VMX constructors at some addresses. The shared register-save issue is repaired, but remaining VMX warnings still require review.
- The exact retail executable has not yet been run under Xenia Canary in this environment.

Do not call the import validated until representative functions are compared against raw section bytes and the executable reaches gameplay at normal speed.

## Matching toolchain

Jeff `0.3.5` identified Xbox 360 MSVC C1/C2 `16.0.10224.0` and linker `10.0.10224.0` in all three modules. Ninety-one measurement-unit boundaries are verified, producing 12,028 exact code bytes across one hundred twelve functions. Original source-file boundaries remain provisional for the game, as does whole-program LTCG status.
