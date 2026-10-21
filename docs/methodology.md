# Matching methodology for the wave-1 additions

Guide version **3** (2026-10-20). It describes how the 194 functions added in
`src/xbox360/matched/` were found, written, checked and reviewed, and how far
that evidence goes. [reproduction.md](reproduction.md) gives the commands to
re-run the check yourself. Everything here is relative to the repository root.
Game files, SDK files and tool binaries are named by SHA-256 only and are never
committed.

## Versions frozen with this guide

| item | identity |
|---|---|
| repository base | `553f78394f95d28e1ccba43dab50f7c5adafc18e` (131 units, 245 functions, 16,360 code bytes) |
| this guide | `docs/methodology.md` and `docs/reproduction.md`, version 3 (corrected relocation equations, analysis provenance, tested PowerShell commands, scope) |
| target module | `Swing_DLL.xex` SHA-256 `dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44` (`config/target.json`) |
| compiler | Xbox 360 `cl.exe` 16.00.10224.00, SHA-256 `6c27181a805dee13d0c9515efc00812d92f9c504cd1158eaf1f338d9f651f198` (`config/54540859/match.json`) |
| linker (link probe only) | Xbox 360 `link.exe` 10.00.10224.0, SHA-256 `5c970fc53998e620fc70c100ef2729cd59c8714f8b761eeac289cfa2fa3a5acf` |
| splitter | Jeff tag `v0.3.5` (`a7b667e29cce75c4c6329624b398c05c6b163d36`) plus `patches/jeff-v0.3.5-topspin4.patch` (LF SHA-256 `31050b8a6d624adb52676f2add9f9d40763ac48a7e31cd1b974815da76c49ce4`). The Windows build used here reports `0.3.5 1ae97da6…`, SHA-256 `c3bece150b9c88e2a052955646a21a777d2d9dd15689ba05b4ad265c0dec83c4` |
| diff tool | objdiff-cli 3.7.1, Windows x86-64 build SHA-256 `97f906acf83442040e3624688341f821238db367c9dba7585213d301216310d2` |
| Python | 3.12.14 and 3.13.11, standard library only |
| analysis (private exports used for reading) | Ghidra 12.1.2, as the export job logs record. The XEXLoaderWV extension was loaded from the Ghidra 12.1.2 `Extensions` folder; its `extension.properties` there reads `version=13.0.0` (SaveEditors fork, created 2026-03-25; `XEXLoaderWV.jar` SHA-256 `aff95fe850f7f88497155fe33a3dc29e0ee200429aab6eaeb51758dbe80ac7de`), and that folder was installed before the export jobs ran. The job logs do not print the extension version themselves, so 13.0.0 is the installed version, not a version the logs prove. `tools/analyze_xbox360.sh` was not used for these exports. |

The review used further private tools, listed in "Tools not in this
repository" below. They are not needed to reproduce the result.

## What changed against the public baseline

| | baseline 553f783 | this branch | difference |
|---|---|---|---|
| matching units (`MATCHING_UNITS`) | 131 | 205 | +74 |
| functions at 100% | 245 | 439 | +194 |
| matched code bytes | 16,360 | 34,632 | +18,272 |
| share of 10,153,700 Swing code bytes | 0.16112353% | 0.34107763% | +0.17995410 points |
| report units (`total_units`) | 346 | 594 | the new split ranges divide auto units |

The table compares the public baseline with the wave-1 change. This branch also carries the separate leaf supplement described in the next section. The supplement brings the totals to 210 units, 1,056 functions and 39,368 matched code bytes (0.38772073%), with 963 report units. This next-candidate branch adds 1,161 further leaf, slot and constant functions (4,932 B; code identity only; semantic NOT_TESTED; reuse of prior independent verification; `publication_ready` false; zero ledger credit). With it the totals were 211 units, 2,217 functions and 44,300 matched code bytes (0.43629417%), with 2,028 report units. On top of that, two allocation-wrapper units, `allocation_wrappers_88617d88.c` (156 functions) and `allocation_wrappers_fill.c` (24 functions), add 180 functions (21,936 B) that call the `fn_88613268` allocator (code identity only; semantic NOT_TESTED; `publication_ready` false; zero ledger credit). The totals are therefore 213 units, 2,397 functions and 66,236 matched code bytes (0.65233360%), with 2,168 report units.

## Leaf supplement (separate from wave 1)

**What it adds.** 617 functions / 4,736 code bytes in five units, `src/xbox360/matched/leaf_family_s01/s02/s03/s04/s11.c`. There is one unit per closed leaf shape:

| unit | functions | bytes |
|---|---|---|
| S01 | 279 | 2,232 |
| S02 | 145 | 1,160 |
| S11 | 120 | 960 |
| S03 | 50 | 200 (4-byte `blr` returns) |
| S04 | 23 | 184 |

**What these functions are.**
- **Trivial leaves.** Each function is 8 or 4 bytes long: a constant return, a single-word getter or a no-op.
- **Names and prototypes.** Each keeps its existing `fn_XXXXXXXX` name. Its original prototype and role are unknown, and the C body reconstructs the instruction shape only.
- **Distinct patterns.** S01, S02, S04 and S11 contain 122 distinct raw instruction patterns; S03 contains 1.

**Status.**
- **Separate.** The supplement is not part of the 194 wave-1 functions, and it claims no new-match credit beyond the measured counters.
- **Not approved for publication.** Its records are not marked publication-ready.

**How it was checked.**
- **Staging, per function.** The bound source rehashes to its record; the function compiled with exit 0 and no includes; its code bytes are identical to the reviewed rebuilt object, and both sides have no relocations; `symbols.txt` holds its `fn_` name with a matching size; its range does not overlap any existing split.
- **Canonical run.** The repository's own `tools/matching.py --fresh-analysis` verifies all 1,056 functions at 100%. On this next-candidate branch it verifies all 2,397.

The 194 added functions are the **wave-1 cut-off set**, selected from the reviewed records available at about 20:30Z on 2026-10-20.

**What the 194 added functions are**
- **Distinct code shapes.** They have 135 distinct code shapes once relocation fields are masked (two functions share a shape when their instructions are identical apart from the addresses they reference).
- **Trivial functions (8 bytes or less): 101 functions, 752 bytes.** These are constant returns, single-word record getters, one-instruction no-op slots and two-instruction thunks. They are real matches but low in novelty.
- **Substantive functions: 93 functions, 17,520 bytes.** Most of the bytes come from the 77 script-native family functions (16,772 bytes); the rest are runtime helpers.

**Reviewed matches not in this change.**
- **At the wave-1 cut-off,** 205 functions (20,100 bytes; 146 distinct shapes) had passed the full local review described below. 11 of them are held back, with the reasons listed below.
- **Since then,** the local review stands at 223 functions / 25,472 bytes. The functions accepted after the cut-off are not in this change.
- **Six later-accepted functions** had a duplicate name and declaration in their source. That integration hold has been cleared without adding new matches; they are still not in this change.
- **The source-signature hold** on one input function (0x88884C08) still stands.
- **Holding a function back** is not a statement that it fails to match.
- **Signature not settled (1).** One input function's source signature is still on hold.
- **Toolchain dependency (1).** One function needs a C++ compiler component (`/TP`) that is not in the canonical toolchain.
- **SDK header (1).** One function includes an SDK header and depends on a header revision that is still under review.
- **Header closure not established (5).** For four input functions the header closure is not yet settled; a fifth depends on a header revision that is tied with another.
- **Script helper revision (2).** Two natives were reviewed against an older revision of the script helper header.
- **Input-mapper header family (1).** One input-mapper function waits for its own header family.

## How a function gets here

The steps run in order: selection, then source, compile, compare, regression controls and independent review, before a function can be packaged.

### 1. Candidate selection and boundaries
- **Where candidates come from.** They come from the Ghidra analysis of the retail module: function boundaries, callers and callees, and references.
- **Boundaries.** A function's extent is the `symbols.txt` size. Where the module has an exception record, its `.pdata` entry must start at the function's address and agree with that extent. A disputed boundary is kept apart and not truncated to fit.
- **No duplicates.** Candidates already matched upstream are dropped by address before any work.

### 2. Source
- **How the source is written.** Each function is written as plain C from the disassembly listing, with AI assistance.
- **What is reconstructed.** Names, types, structure layouts and field roles are reconstructions. A reconstructed prototype is not a claim about the original source signature.
- **Externals.** They use the names already in `config/54540859/symbols.txt` (`fn_XXXXXXXX`, `lbl_XXXXXXXX` or reviewed `ts4_*` names), so relocations pair by name.
- **Decompiler output** was used as a reading aid only. No decompiler text is committed.

### 3. Compile exactly as the repository does
`cl.exe /nologo /c /O2 /Oi [extra_flags] /Fo<object> <source>`, run from the repository root.
- **No include path.** No `/I` and no SDK headers are used.
- **Per-unit `extra_flags`.** These are recorded in `MATCHING_UNITS`. The wave-1 units need none.
- **One variable at a time.** When a draft does not match, each new attempt changes a single source hypothesis or flag in its own isolated build. Flags are never searched combinatorially.

### 4. Compare
- **Splitter.** Jeff splits the retail module using `splits.txt` and `symbols.txt`.
- **Diff.** objdiff compares each split object with the rebuilt object.
- **A match** is objdiff `fuzzy_match_percent == 100.0` at the exact `symbols.txt` size (`tools/matching.py verify_report`).

objdiff 3.7.1 does not penalise a relocation that points at a differently named symbol. The local review therefore adds checks that objdiff does not make. Every relocation in the function is accounted for, and the effective target and addend must be equal:
In the formulas below, `S` is the referenced symbol's address resolved through `symbols.txt`, and `sext16` is 16-bit sign extension. Branch and ADDR32 relocations are each normalised on their own. The REFHI/REFLO/PAIR rule is separate and applies to the high/low pair.

- **Branches (REL24/REL14).** These must sit on a branch instruction.
  - Target object: the destination is decoded from the instruction (absolute when AA is set, otherwise relative to the site), and target addend = destination - `S`.
  - Rebuilt object: the unresolved PC-relative field is normalised to an addend by adding the site's section offset. An absolute (AA) field is used as is.
  - Equal: the addends, and the AA, LK and other non-field bits.
- **ADDR32.**
  - Target addend = stored word - `S`.
  - Rebuilt addend = the stored, unresolved word.
  - The two must be equal.
- **REFHI/REFLO/PAIR.** Each REFHI must be followed immediately by a PAIR and have at least one REFLO of the same symbol.
  - Target addend at each low site = `((hi_imm << 16) + sext16(lo_imm)) - S`.
  - Rebuilt REFHI addend = `(hi_imm << 16) + sext16(PAIR)`.
  - Rebuilt REFLO addend = `sext16(lo_imm)`, which must equal the rebuilt REFHI addend.
  - The target addend must equal the rebuilt one, and the low-site offsets and their order must be identical.
  - Do not add the PAIR displacement and the REFLO immediate together: that counts the low part twice.
- **PAIR field.**
  - In the target objects, the patched Jeff writes the REFHI's symbol index into the PAIR record. This is accepted only for the pinned Jeff build.
  - In `cl.exe` objects, the REFHI's PAIR carries the displacement.
  - A REFLO may be followed by a PAIR whose raw value is the symbol index in the target and 0 in `cl.exe` objects.
- **Anything else is unresolved.** That covers any other relocation kind and any malformed group (a standalone REFLO, a dangling PAIR, a REFHI without PAIR or REFLO); such a function is never accepted.
- **Checker version.** The wave-1 results come from the local checker `reloc_effective` v2.2, part of runner release R4.2 (SHA-256 `d16cceec960cf3c38eaf5eb34c732d75d08c8f367dc2be6530ed6bc51cfc5407`). A later revision, v2.3 in R4.3 (`49350fcf…`), was not used for wave 1.
- **`.pdata`.** The function's original `.pdata` entry must match where one exists.

### 5. Regression controls
- **Host differential tests** for semantic drafts compare against a reference model of the original instructions. The tests are only as good as their cases.
- **Mutation controls.** These are single-change mutants that the tests must reject.
- **The U-domain control.** Converting a double to a 32-bit value with `fctidz` followed by a low-word read cannot be told apart from `fctiwz` for in-range values. Out-of-range inputs are undefined in C, so such cases are reported as a separate class (HOST_I686_UB_DIVERGENCE) and are never counted as semantic passes.

**Two different strengths of differential evidence**
- **Host-only:** the draft is run against its own reading of the listing.
- **Original-word:** the reference model executes the original instruction words.

The second is stronger.

**Not evidence of behaviour.** Neither kind is part of the code-match claim. A byte-identical function proves the code bytes only, not the semantics of the reconstructed types.

### 6. Independent review and acceptance
A function is accepted only if a second reviewer, working separately from the author, re-derives every point from the preserved files. The reviewer does not rely on the author's summary. A score or a "100%" line alone is never accepted.
- **Identity.** Module, address and extent are correct.
- **Source binding.** The source and header bytes are named by SHA-256.
- **Command and report.** The compile command and flags, and an objdiff report bound to that invocation (tool hash, project hash, report hash), are recorded.
- **Raw comparison.** Defined symbols, code and relocations are compared from the raw COFF.
- **Relocations and `.pdata`.** The effective relocation and `.pdata` checks pass.
- **No duplicate.** The function is not already matched upstream.

Every accepted record names the address, extent, source SHA-256, target and rebuilt object SHA-256 and report SHA-256, plus any caveat. Those hashes keep the record valid if files are later moved.

### 7. Packaging for this repository
For each accepted source file, the unit in `src/xbox360/matched/` is derived as follows:
- the file header is replaced by a neutral provenance note;
- the definitions of functions that are not accepted are removed;
- comments that cited private material or instruction words are removed.

Every remaining function definition is byte-identical to the reviewed source. Accepted compilation groupings are kept: one reviewed file becomes one unit, and single-function files stay single units. The headers in `src/xbox360/matched/` are comment-only revisions of the reviewed headers. After packaging, three checks ran on the package itself:
1. Every unit was compiled exactly as `tools/matching.py` compiles it, from the repository root. Each function's code bytes and relocation records were then compared with the reviewed rebuilt object: 194 of 194 were identical.
2. `/showIncludes` traces of the same compiles were compared with each function's reviewed header closure: 194 of 194 agreed, and no file resolved outside the repository.
3. The repository's own `tools/matching.py --fresh-analysis` run verified all 439 functions at 100%. The effective relocation check above ran again on the canonical split objects: 102 functions were EQUAL and 92 have no relocations.

## Worked examples

**Small: a constant return** (`src/xbox360/matched/constant_returns_s01.c`). The retail function loads a constant into r3 and returns. The C body `return 0x50;` with return type `ts4_u32` compiles to the same two instructions. The only checks that matter are the 8-byte extent and the absence of relocations.

**Substantive: the script-native family** (`src/xbox360/matched/script_family_*.c`, `script_argument_helpers.h`). Script natives take a `struct TS4ScriptContext *` (`src/xbox360/script_context.h`, unchanged) and inline the same argument idioms. These idioms came from earlier exact matches and are written once in the helper header:

| idiom | C form | what it compiles to |
|---|---|---|
| A2 | `ts4_script_argument(ctx, i)`: argument `i` or the default value; for index 0 the count is read once through a plain cast, for index > 0 through a volatile access; unsigned test | count load, unsigned compare, `first_value + i*0x38` or the default-value global |
| N | `ts4_script_number(v)`: double for type 4, converted integer for type 1, otherwise `g_ts4_script_constants[11]` | type tests and a double load or integer-to-double conversion |
| U | `(ts4_u32)number` | 64-bit truncation followed by a low-word read |
| U-ADDR | U value stored to a local and passed by address | the same, followed by a store to the stack and the address as an argument |
| S32 | `(ts4_s32)number` | 32-bit truncation |
| T | `ts4_script_string_equals(arg->payload, g_ts4_true_string)` | a call with the true-string global |
| R | `return K;` | constant result |
| G | globals and callees through their `symbols.txt` names | paired high/low address relocations, branch relocations |
| MULTI-A2 | read several arguments into locals in order, before any call | consecutive A2 blocks before the first call |
| E-OWNER | create an event, read the owner global into a local, store the payload, post | the owner load directly after the create call |
| BCTRL-DISPATCH | `dispatch = *(fn_t **)object; dispatch[slot](object, ...)` | indirect call through the object's table |
| Q-FLOAT3 | by-value float triples built as named locals in argument order | float conversions and struct stores before the call |

Open shapes that are still unmatched, such as a pointer-guarded byte store of the T flag, have no catalogue entry until a matched example exists.

## Parallel work and evidence handling (how the local review was organised)
- **Claims.** Work is split by claims recorded under an atomic lock (create-directory semantics). A function claimed by one lane is skipped by the others.
- **Isolation.** Each lane writes only its own run directories. Inputs are private copies, validated before use.
- **Pinned tools.** Tools run from immutable, hash-pinned releases, and each run records the release and module hashes it used.
- **Immutable evidence.** Once evidence is handed for review it is never edited. Corrections are new revision files with an explicit old-hash to new-hash map.

**Adding a candidate.** Claim it, write the source, compile under the declared flags, compare, run the effective relocation and `.pdata` checks, record hashes and caveats, and hand the files over.

**Accepting a candidate.** The reviewer decides on the re-derived checks in step 6, never on the author's summary.

## Tools not in this repository (not needed to reproduce the result)
These are listed openly here rather than left as hidden dependencies. Publishing any of them would be a separate change.

**Scope.** With your own game copy and compiler, the public `tools/matching.py` reproduces the existing exact matches: 2,397 on this branch, of which 439 come from the baseline and wave 1, 617 from the leaf supplement, 1,161 from the next-candidate addition and 180 from the allocation-wrapper addition. It does **not** reproduce the independent acceptance process, and the repository does not contain the private candidate corpus. The tools below are named by hash only. A hash does not let a third party run them. Continuing the search for new matches needs a separate, reviewed release of that tooling; a separate local packet is under review and is not part of this change.

| tool | identity | role |
|---|---|---|
| local runner release R4.2 | manifest SHA-256 `a733c2d147aa218faa2028c891d8be81d7445504780c7ab50d49aa7961200eb0` | isolated per-candidate compile/split/objdiff runs |
| bound-report helper v3.1 | `aaef54c5ddbcd2bac8149a6d4e9ab407ec09add61de2f816bc1d615bbbdd43b8` | report binding and gate checks |
| effective relocation checker v2.2 (R4.2) | `d16cceec960cf3c38eaf5eb34c732d75d08c8f367dc2be6530ed6bc51cfc5407` | the relocation check in step 4 |
| automated leaf classifier, review 5 | closure SHA-256 `5e7b8e208dfe418314906d710be2216d37a53d3d98617939a1869412c33c3fd0` (a sixth review was pending at the wave-1 cut-off (about 20:30Z on 2026-10-20). Since then, the narrow class-7 leaf rule was accepted at 21:08:57Z, per-member validation of the leaf families S01, S02, S04 and S11 at 21:23:43Z, and the S03 family at 21:18:49Z (all UTC, 2026-10-20)) | screening of trivial leaf candidates |
| Ghidra export (pass 2b) | function index SHA-256 `8629e41b57308daa331ddaf856d2535fa913b2b8cd10331ca630818905a6c997` | private listings and decompiler output used for reading |

**SDK and companion dependencies (wave-1 needs none of them).**
- **SDK headers.** Some held-back drafts include SDK CRT headers. They used a July 2012 XDK include directory plus one CodeAnalysis annotation header taken from a desktop toolchain. Such drafts are not packaged.
- **`/TP` units.** A C++ (`/TP`) unit needs the compiler's `ATL100.DLL` companion, SHA-256 `81bc7479b974658741f7d1b9a321a9d1303b2c95416b5170eee74fef09280875`, loaded only for that process. It is not part of the canonical toolchain, which is why such units are held back.

## Known limitations
- **Scope of a match.** A 100% objdiff score at the recorded size, with effective relocations and `.pdata` equal, proves that the function's code bytes and relocations match. It does not prove the original prototype, types, source language, whole-translation-unit flags or behaviour. Fuzzy scores below 100 are not matches.
- **Shared helper declarations.** Units declare the helpers they call themselves; there is no shared header. The `fn_88613268` allocator is declared with three different result types in the tree: `u32` in `container_factory_wrappers.c`, `create_3ac_object.c`, `create_runtime_object.c` and `create_runtime_object_20.c`; `void *` in `allocate_zeroed_triplets.c` and `create_zeroed_triplet.c`; `ts4_u8 *` in `matched/script_family_d01.c` and `matched/script_family_d01_887926d8.c`. The two allocation-wrapper units follow the `u32` form. Each unit keeps its own declaration; none is a claim about the original return type.
- **Names, types and grouping.** Names, field roles and source groupings are reconstructions. Units are measurement units, not proven original object boundaries.
- **The `validated_functions` counter** follows this repository's existing convention: it moves with `matching_functions` and does not certify a runtime trace. Like `reconstructed_functions`, it is best read as a count of verified exact code matches, not as proof of the original ABI, types or gameplay. `typed_functions` stays 0, because no original type is known.
- **Not a runnable game.** Neither compiling nor matching produces one. The forced link probe in `config/link-status.json` is an inspection artefact only.
- **Lines of work that produced no match.**
  - A pilot on vector-container functions stopped without an exact member (best score 81.73%).
  - Leaf classifier: a sixth review was pending at the wave-1 cut-off (about 20:30Z on 2026-10-20). Since then, the narrow class-7 leaf rule was accepted at 21:08:57Z, per-member validation of the leaf families S01, S02, S04 and S11 at 21:23:43Z, and the S03 family at 21:18:49Z (all UTC, 2026-10-20).
  - Some caller-ABI questions and missing regression controls keep individual functions on hold.
- **Portability.** Only Windows 11 x64 was exercised, where the "wrapper" is a pass-through, and only the commands in reproduction.md. Linux and macOS with wibo are documented upstream but were not exercised for this change.

## Remaining high-value work
- Resolve the held-back header revision conflicts by recompiling the affected functions against one shared header.
- Decide on the `/TP` companion question for C++ units.
- Settle the held source signature with a call-boundary check.
- Publish the effective relocation checker so that reviewers can run it.
- Extend the script idiom catalogue to the open shapes.
