# Static-analysis status

## Reproducible baseline

The three retail XEX modules were imported with Ghidra 12.1.2 and XEXLoaderWV 12.1.2 using `PowerPC:BE:64:A2ALT-32addr:default`. Reports and Ghidra project data remain under ignored `work/`; only measurements and original tooling are committed.

| Module | Image base | Entry point | Ghidra functions | Thunks |
| --- | ---: | ---: | ---: | ---: |
| `default.xex` | `0x82000000` | `0x82019F68` | 503 | 5 |
| `Loader_DLL.xex` | `0x83000000` | `0x833E0E80` | 8,786 | 34 |
| `Swing_DLL.xex` | `0x88000000` | `0x88562DB0` | 32,506 | 34 |
| **Total** | | | **41,795** | **73** |

This is a discovery denominator, not a claim that every boundary is correct. It may change when bad disassembly is removed, missed functions are recovered, or thunks are normalized. Human-named and reconstructed counts remain zero.

## Import warnings to audit

- XEXLoaderWV reported `out of input bytes (LzxDecompression)` after loading the declared sections of each module. All three programs were still analyzed and saved.
- Ghidra reported unresolved PowerPC/VMX constructors at some addresses.
- The exact retail executable has not yet been run under Xenia Canary in this environment.

Do not call the import validated until representative functions are compared against raw section bytes and the executable reaches gameplay at normal speed.
