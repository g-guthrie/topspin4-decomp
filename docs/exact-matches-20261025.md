# Exact-code publication update, 25 October 2026

This update collects the independently reviewed local matches that were not in
the previous public branch, `94748f2946b876c0629ca3f628f74fd296adcf75`.
The measured totals and receipt hashes are in
[`publication-20261025.json`](../reports/54540859/publication-20261025.json).
Earlier sections of [methodology.md](methodology.md) describe the previous
waves; their counters are historical, rather than the counters of this update.

## What a match establishes

The proof concerns a distinct address and its complete recorded code extent,
effective relocation targets and addends, and the retail exception-directory
(`.pdata`) entry or checked absence. A compiler result or a fuzzy score alone
does not establish this proof. Cache hits reuse objects, never acceptance.

These are **code-identity matches**, produced from disassembly with AI-assisted
source proposals and deterministic compilation/comparison. They are not a
separately established clean-room result. Most original function signatures,
types, object layouts and behavior remain unknown. Names such as `fn_XXXXXXXX`
identify addresses; an inferred 32-bit guest type is not an original ABI proof.
The old `reconstructed_functions`/`validated_functions` progress convention
does not change that boundary; `typed_functions` remains zero.

The explicitly unresolved signature at `0x88884C08` and the unreproduced source context at `0x8826B640` are excluded. Existing
public matches, duplicate variants, held candidates and fuzzy improvements do
not add new-function credit. The failed vector/STL pilot is not an exact STL
reconstruction. No runnable XEX or Windows port follows from these results.

## Sources, tools and provenance

The two source manifests are executable build metadata, not acceptance ledgers:

* `config/54540859/local_20261025_units.json`: retained local candidates and
  deterministic family templates, one C source per address, with original and
  publication source hashes. One-function units preserve compiler context and
  make their comparison independent of guessed original translation units.
* `config/54540859/remaining_20261025_units.json`: the smaller older-source
  group. Its sources preserve required static helpers and original declarations,
  with canonical address names. Already-public external function bodies were
  removed. This transformation required a fresh compile and per-address review;
  old object receipts did not transfer automatically.

Neither manifest contains original code bytes. Source groupings, prototypes
and helpers remain provisional. `.gitattributes` preserves the exact mixed
LF/CRLF source and header bytes so Windows checkout conversion cannot silently
invalidate the pins. Minimal `guest_std.h` files are original declarations for
this PPC32 matching experiment, not copied SDK headers or general SDK replacements.

Tool pins are in [reproduction.md](reproduction.md) and
`config/54540859/match.json`: Xbox compiler 16.00.10224.00, patched Jeff 0.3.5,
objdiff-cli 3.7.1, and Python's standard library. The single `/TP` source also
needs the original compiler's private ATL100 runtime companion; its SHA-256 is
`81bc7479b974658741f7d1b9a321a9d1303b2c95416b5170eee74fef09280875`.
Supply that dependency locally on `PATH`; do not commit or redistribute it.
The `/O1` and `/TP` exceptions are recorded per unit. No global flag changes or
new SDK headers are required by this update.

## Reproduce and continue

Start with the complete matching command in [reproduction.md](reproduction.md),
using a fresh private work directory. Supply your own pinned retail XEX and
compiler; the build splits the target, compiles every configured source and
checks every expected objdiff function at its exact size. No local language
model, original author workspace or retained compiler cache is needed for that
source-to-object reproduction. Raw verification is a separate gate, not the
objdiff command's fuzzy-score gate.

For a new candidate, retain its address, full extent, source/header closure,
compiler profile and immutable tool hashes before compiling. Compare full
retail bytes, resolve relocations (including addends), and check `.pdata`
directly. Reject an interior fragment or missing expected exception entry.
Deduplicate against public and private accepted extents and address claims.
Have an independent reviewer inspect the exact resulting inputs and objects.
Report distinct addresses, code bytes and raw patterns separately from type
constraints, behavior evidence and publication readiness.

The 756-function deterministic cohort supplies small leaf/load/store examples;
the five published older shot-request functions share a header and illustrate a substantive
family where source extraction can change inlining. In both cases each address
needs its own mechanical proof. One representative match cannot approve a family.

Concurrent workers need separate mutable source/output directories, atomic
address/resource claims, bounded processes and owner-only cleanup. Use immutable
evidence snapshots, preserve first failures and move past a recorded mismatch.
Do not share a compiler's temporary directory or count CPU saturation as progress.

Candidate-production and lifecycle experiments are not shipped as a production
service here. The private runner's lifecycle audit remains a separate hold.
Future work includes original signatures and layouts, controlled family
extensions, behavior/oracle tests with valid negative controls, and eventual
complete linking and runtime validation. This publication does not resume those
experiments or turn host semantic tests into PowerPC ABI proof.
