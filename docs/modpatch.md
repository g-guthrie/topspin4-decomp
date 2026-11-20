# Modded Swing_DLL.xex (tools/modpatch.py)

Build a modified copy of the game's code module `Swing_DLL.xex` so gameplay code changes can be played in
the original game under Xenia. Everything produced lives under `work/modpatch/` (git-ignored); the tools
refuse other output paths. Nothing here has been run in an emulator (see "Not verified").

Files: `tools/xex_write.py` (XEX container), `tools/modpatch.py` (patching, compile, relocation, hooks,
data), `tests/test_modpatch.py` (synthetic data only; `python3 -m unittest tests.test_modpatch`).

## 1. Quick start

```sh
# the retail key is read from the local jeff checkout at run time (tools/xex_patch.py); needs `cryptography`
work/venv/bin/python tools/modpatch.py build MANIFEST.json [MORE.json ...] --out work/modpatch/NAME/Swing_DLL.xex
work/venv/bin/python tools/modpatch.py build --identity --out work/modpatch/NAME/Swing_DLL.xex
python3 tools/modpatch.py disasm work/modpatch/NAME/Swing_DLL.xex 0x88170DC0 8 --report work/modpatch/NAME/Swing_DLL.xex.report.json
python3 tools/modpatch.py relink-check src/xbox360/foo.c ts4_name=0x88170DC0      # proves relocation math
python3 tools/modpatch.py setdata work/modpatch/NAME/Swing_DLL.xex --out work/modpatch/NAME2/Swing_DLL.xex flag=01
```

Place the result in a patched game folder (see docs/data-patching.md section 4, `tools/ts4_iso_patch.py`)
as `Swing_DLL.xex` next to `default.xex`, replacing the original. Run the game with the title update
DISABLED: the update's delta patch for Swing_DLL (a `.xexp` that is applied to the base module's image)
cannot apply to a modified module, so a game started with the update would load the patched-over original
code or fail.

Several manifests may be given; their lists are concatenated in order (data entries merge by name).

## 2. Manifest format (JSON)

All addresses are virtual addresses (`"0x88170DC0"` strings or integers). `note` fields are free text.
Paths are relative to the working directory, else to the repository root.
Order of application: `data`, `patches`, `functions`, `hooks`, `data_set` (data is allocated first so
C code can reference it; `data_set` overwrites last).

```json
{
  "patches": [
    {"address": "0x88170DC0", "old": "7d8802a6", "new": "60000000", "note": "constant patch"}
  ],
  "functions": [
    {"source": "src/xbox360/foo.c", "function": "ts4_foo", "address": "0x88170DC0",
     "expect_old": "7d8802a6", "flags": ["/O1"], "note": "replace a whole function"}
  ],
  "hooks": [
    {"hook": "0x88171234", "expect": "c0230010",
     "stub": {"source": "work/modpatch/stubs/h1.c", "function": "h1", "vmx": 2, "redzone": 512},
     "note": "C stub called with a pointer to the saved register context"},
    {"hook": "0x88171300", "expect": "3860ffff",
     "stub": {"words": ["0x38600001"]},
     "note": "raw words run first, then the displaced instruction, then b hook+4"}
  ],
  "data": [
    {"name": "mp_flags", "offset": 0,  "init": {"u32": [1, 0, 0, 0]}},
    {"name": "mp_tune",  "offset": 16, "init": {"f32": [1.5, 0.25]}},
    {"name": "mp_buf",   "size": 64}
  ],
  "data_set": [
    {"name": "mp_flags", "value": {"u32": [0]}, "index": 0, "note": "switch off without recompiling"}
  ]
}
```

### patches
Overwrite `len(new)` bytes at `address`; refused unless the image bytes equal `old`. `old` and `new` are
hex byte strings of equal length. Patches may not overlap each other or any other write.

### functions
`source` is compiled with the original compiler (wibo + `cl.exe` 16.00.10224.00, `/O2 /Oi` plus the
per-file exceptions of `config/54540859/match.json`, plus `flags`). `function` (C name, or the undecorated
name of a C++ symbol) is placed in free space, its relocations are resolved (section 4), and the first
instruction at `address` becomes `b new_code`. `address` must be a function start in
`config/54540859/symbols.txt` (set `"force": true` otherwise). `expect_old` (optional) is the hex of the
first bytes there. The remainder of the old function stays as dead code.

### hooks
Patch ONE instruction in the middle of a function. `hook` is the address of the instruction, `expect` the
hex of the original instruction word (several words allowed; they are all compared, only the first is
overwritten). The instruction at `hook` becomes `b stub`. The displaced original instruction is executed
after the stub (re-encoded when it is PC-relative; `b`/`bl`/`bc` forms are supported, a conditional
branch whose new displacement does not fit 16 bits is refused), then `b hook+4`.

* `"stub": {"words": [...]}`: raw PPC words placed in free space, then the displaced instruction, then
  `b hook+4`. No registers are saved: the words must preserve what the hooked function needs. Words are
  not relocated.
* `"stub": {"source": "...", "function": "name", "vmx": 0|1|2, "redzone": N}`: a C function
  `void name(HookCtx *ctx)` (convention in section 3).

### data
New initialised read/write data in the patch data area (section 5). `name` is the symbol C code (and
`data_set`) uses; `offset` is the byte offset inside the area (optional; omitted offsets are allocated
sequentially, 4-byte aligned, in order of first appearance, so give explicit offsets when several manifests
share data); `size` (bytes, default from `init`); `init` is a hex string or an object with one of `u8`,
`u16`, `u32`, `s32`, `f32` (big endian) lists. The same name in several manifests must agree on offset and
size; a later `init` replaces an earlier one.

### data_set
`{"name", "value", "index"}` overwrites the initial contents of an existing data symbol (`value` as for
`init`; `index` is the element offset in units of the value's type, default 0). This is how switches and
tuning constants are turned on/off from a small separate JSON without recompiling anything C: put the
`data` declarations and C stubs in the main manifest and the `data_set` lines in a tweak file passed last.
A built XEX can also be edited directly with `setdata` (below).

## 3. C stub convention for hooks

Chosen: a plain C function called from a generated wrapper (the Xbox 360 compiler has no usable inline
assembler for naked stubs). The wrapper saves EVERY register of the hooked function into a context
structure on the stack, calls the stub with `r3 = &ctx`, restores every register from the structure
(so the stub may change them), executes the displaced instruction and branches to `hook+4`. The stub
therefore needs no register discipline, and sees and can change the hooked function's live values.

The compile directory gets a generated header, so a stub starts with `#include "modpatch_hook.h"`:

```c
typedef struct HookCtx {
    unsigned int gpr[32];        /* 0x000 r0..r31; gpr[1] is the original sp (read only) */
    double       fpr[32];        /* 0x080 f0..f31 (lfd/stfd; singles are held as doubles) */
    unsigned int lr, cr, ctr, xer;   /* 0x180 */
    unsigned int skip_original;  /* 0x190 write nonzero to NOT execute the displaced instruction */
    unsigned int hook_address;   /* 0x194 */
    unsigned int reserved[2];    /* 0x198 */
    unsigned int vr[128][4];     /* 0x1A0 vector registers, only present when "vmx" > 0 */
} HookCtx;
```
`"vmx": 0` saves no vector registers, `1` saves v0..v31 (`stvx`), `2` (default) saves v0..v127
(`stvx128` for v32..v127). Vector state is always preserved across the stub when vmx > 0, even if the stub
does not touch it. FPSCR, VSCR and the reservation are not saved. `"redzone"` (default 512) is the number
of bytes below the hooked function's `r1` that the wrapper leaves untouched (leaf functions keep
spills there); the wrapper frame starts below it.

Stub example (reads a float register, changes a result):

```c
#include "modpatch_hook.h"
extern float mp_tune[];                       /* a `data` symbol, section 5 */
void h1(HookCtx *ctx)
{
    ctx->fpr[1] = ctx->fpr[1] * mp_tune[0];
}
```
Stubs may call game functions (declare them `extern`, name from symbols.txt or `fn_XXXXXXXX`).

## 4. How a replaced function / stub is linked

The source is compiled exactly as `tools/fn_check.py` does (wibo, `cl.exe` 16.00.10224.00, `/O2 /Oi` plus
the per-file flags in `config/54540859/match.json`, include path = the source's directory and
`src/xbox360`). The COFF object is read directly (`Coff` in modpatch.py).

* The code of the function (its COMDAT `.text` section, or its extent in a shared section) is copied to
  free space. Whatever it references inside the object is copied too, transitively: static helper
  functions, `$LN` jump-table labels, and read-only constants such as `__real@40200000` (separate `.rdata`
  sections). Each copy is 16-byte aligned. A writable or uninitialised object section (`.data`, `.bss`)
  is refused: use a `data` symbol instead.
* Symbols are resolved in this order: a symbol defined in the object as static (helpers, labels,
  constants) is the copy; a defined external or undefined symbol is looked up by name in
  `config/54540859/symbols.txt`, then in the manifest `data` names, then the `fn_XXXXXXXX` / `lbl_XXXXXXXX`
  placeholder pattern (the address is the name); anything else is an error. (So a call to a function that
  the same source also defines goes to the ORIGINAL game function, not to a second copy; list it under
  `functions` to replace it too.)
* Relocations: `REL24`/`REL14`: displacement = `S + field - section_base` (MSVC stores `-offset` in the
  field); `ADDR32`: `S + field`; `REFHI`/`REFLO` (+`PAIR`): `full = S + signext16(REFLO field)`,
  low half = `full & 0xFFFF`, high half = `(full + 0x8000) >> 16` (carry adjusted).
* The function is entered by `b new_code` written over its first instruction. `bl` is not used, so LR is
  untouched and the new code returns straight to the caller. The old body remains as dead code, and
  `.pdata` is not edited: the new code has no unwind/function-table entry (Xenia does not use it to
  execute; a real console would).

## 5. Where new code and data go

**Code: 0x88B15400..0x88B20000 (44,032 bytes).** The XEX page descriptors mark pages 21..177
(0x88150000..0x88B20000) as CODE; the PE sections end at RADCODE `0x88B15346`, and the rest of the last CODE
page up to 0x88B20000 is zero. This is the only executable space with no change to the image: inter-function
padding is a few bytes, and `.text` has only 0x48 bytes of tail slack before `BINK`. Using it keeps
`image_size`, the page descriptors and the PE headers unchanged, and Xenia's executable range
(`CommitExecutableRange` over the CODE descriptors) covers it, which would not be true of a region appended
after the image. The start is computed (`max(last non-zero byte, last section end)` rounded to 0x200),
the allocator checks every byte is zero before use and refuses when exhausted. The PE section table is
not edited (the new bytes sit in the tail of the RADCODE raw size / after it); Xenia does not read it for
execution.

**Patch data area: 0x88DCE000..0x88DD0000 (8 KiB), fixed.** It is in the DATA page range (read/write),
all zero in the original, in the padding after the last non-zero byte (0x88DCC3B5) of the discardable
`.reloc` section (base relocations, unused when loading at the preferred base). Offsets in the `data`
entries are relative to 0x88DCE000. In the built XEX the area is at file offset `0x3000 + 0xDCE000`
(`0xDD1000`), so a hex editor works too, but `setdata` is easier:

```sh
python3 tools/modpatch.py setdata work/modpatch/NAME/Swing_DLL.xex --out work/modpatch/NAME_on/Swing_DLL.xex \
        mp_flags=u32:1 'mp_tune[1]=f32:0.5'
```
(uses `Swing_DLL.xex.report.json`, written by `build`, which lists every data symbol with its address).
Code placed in the CODE range is read-only at run time, so mutable state must live in the data area.

## 6. xex_write.py: what is rewritten

The original is encrypted (AES-128-CBC) and LZX compressed (`0x3FF` block: size 0x24, encryption 1,
compression 2, window 0x8000, first block size and SHA-1). The output keeps every header byte of the
original except that block:

| field | original | written |
|---|---|---|
| optional header 0x3FF `size` | 0x24 | 0x10 (`basic`; `none` gives 0x08) |
| `encryption_type` | 1 | 0 |
| `compression_type` | 2 | 1 (basic) or 0 (none) |
| block table | window/size/SHA-1 | one `{data_size = 0xDD0000, zero_size = 0}` |
| bytes after the new block, up to old 0x24 | n/a | zeroed |

The payload after the (unchanged, 0x3000-byte) header is the raw memory image of 0xDD0000 bytes.
Unchanged but now stale, never recomputed: the SHA-1 page-descriptor hashes, the header hash, the RSA
signature, the (now unused) encrypted file key. Xenia's loader (`xex_module.cc`, `ReadImageBasicCompressed`)
sums the block sizes, allocates `sum(page_count) * 64 KiB`, copies the blocks and checks the MZ/PE headers; it
verifies none of those hashes. A console would reject the file.
`verify()` re-reads the output with the repo's own reader (`xex_patch.base_image`) and compares byte for
byte; `modpatch build` does this on every build and also checks that the modified image differs from the
original only inside recorded writes.

## 7. What was verified (and how)

All on this Mac; nothing was run in an emulator.

* XEX round trip: original XEX decoded with `xex_patch` (hash chain verified by that tool) -> written ->
  decoded again: identical image, identical SHA-256 (`work/modpatch/demo/identity.xex`). Headers outside
  0x3FF are byte-identical.
* Relocation arithmetic: `modpatch.py relink-check` relinks already matched functions at their original
  address and compares them with the original image bytes. 300 randomly chosen source files from
  `config/54540859/match.json` (6,046 functions, the relocation forms that occur in them, REL24/REFHI/REFLO
  with and without addends, ADDR32 jump tables; REL14 and ADDR16 are implemented but not separately
  exercised): all identical, except two functions of
  `ga6_ltcg_b.c` that only match through the LTCG route (`fn_check_ltcg.py`), which this plain compile does
  not reproduce. Words that point at copied local constants are excluded from the comparison (they
  legitimately move).
* Demo (b), `work/modpatch/demo/replace_triplet.xex`: `ts4_create_zeroed_triplet` (0x88170DC0, matched source
  `src/xbox360/create_zeroed_triplet.c`) is replaced. Disassembly (`modpatch.py disasm`, tools/ppcdis):
  `88170DC0: b 0x88b15400`; at `88B15400` the code is word for word the original except the `bl`, which targets
  `0x88613268` (`fn_88613268`) in both; the `lis/lwz` pair loads `lbl_88D45B38` (0x88D45B38) in both.
  Outputs `replace_triplet.dis` and `original_triplet.dis` are in that folder.
* Hooks: the generated wrapper is run in an instruction-level interpreter in the unit tests (synthetic
  registers): all 32 GPR, 32 FPR, 128 vector registers, LR, CTR, XER, CR are restored, the stub sees the
  right context and may change r14 through it, the red zone is untouched, the displaced instruction runs
  (or is skipped when `skip_original` is set), and control returns to `hook+4`. The vector-register
  encodings (`stvx`, `stvx128`, `lvx`, `lvx128`) were checked by decoding with ppcdis.
  `work/modpatch/demo/hook_counter.xex` and `float_probe.xex` are builds with a C stub that touches a data
  symbol and `.rdata` float constants.
* `python3 -m unittest tests.test_modpatch`: 27 tests, synthetic data only.

## 8. NOT verified

* Nothing here was loaded in Xenia or on hardware. That Xenia accepts the container is derived from
  reading `xex_module.cc` (retrieved from the Xenia repository), not from running it.
* Xenia discovering functions in the new code: it follows branches/calls at run time and does not need
  `.pdata`, as far as I know from its source; this is untested.
* Whether the game or Loader_DLL checks the module's size, hash or signature before running it. Xenia
  does not, and a console would reject any modified file.
* Hooks and replacements change behaviour only as written; behaviour-preserving replacement was shown by
  comparing code, not by running the game. A function replaced by a branch assumes nothing jumps into the
  middle of the old body.
* Code compiled by the plain route is not byte-identical to code matched through the LTCG route.
* The `vmx: 2` wrapper is about 3.9 KB of stores/loads per hook activation; hooks in per-frame hot paths
  may want `vmx: 0` or `1` if the hooked function does not use vector registers.
* `FPSCR`, `VSCR`, the reservation and the CR/XER state the stub changes inside called functions beyond
  what the wrapper saves are not preserved.

## 9. Commands used for the demos

```sh
P=work/venv/bin/python
$P tools/modpatch.py build --identity --out work/modpatch/demo/identity.xex
$P tools/modpatch.py build work/modpatch/demo/spec_replace.json --out work/modpatch/demo/replace_triplet.xex
$P tools/modpatch.py build work/modpatch/demo/spec_hook.json    --out work/modpatch/demo/hook_counter.xex
$P tools/modpatch.py build work/modpatch/demo/spec_float.json   --out work/modpatch/demo/float_probe.xex
$P tools/modpatch.py disasm work/modpatch/demo/replace_triplet.xex 0x88B15400 25 \
      --report work/modpatch/demo/replace_triplet.xex.report.json
$P tools/modpatch.py relink-check src/xbox360/create_zeroed_triplet.c ts4_create_zeroed_triplet=0x88170DC0
```
Requirements: the original `orig/54540859/Swing_DLL.xex`, the retail key in the local jeff checkout
(read at run time, never stored), the `cryptography` package (only to read the original XEX; the decoded
image is cached under `work/modpatch/cache/`), the matching toolchain under `work/matching-tools`
(only for `functions`/`hooks` with C), and `work/ppcdis/target/release/ppcdis` for `disasm`.
