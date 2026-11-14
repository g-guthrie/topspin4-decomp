# Loader analysis

The tracked Jeff patch also fixes the complete `Loader_DLL.xex` split. No
Loader executable or generated object is committed.

Jeff originally promoted a relative jump-table label at `0x830CF884` to a new
function even though the address is strictly inside the pdata-bounded function
`0x830CF868-0x830CF8F0`. The shared 64-byte table begins at `.rdata`
`0x830847F8`; byte index `0x23` resolves to the internal label. The patch now
rejects function references that fall inside an existing bounded function in
both CFA insertion paths.

The remaining non-code `.text` trailer must be supplied as a reviewed Loader
seed:

```text
text_metadata_83517E14 = .text:0x83517E14; // type:object size:0x2C scope:local data:byte
```

With that seed, a fresh split produces 17,215 Jeff functions, eight generated
units, 4,685,376 code bytes, and 815,617 data bytes. A reviewed run took 7.15
seconds; the quick rerun took 0.99 seconds. The emitted raw `.text` payload was
byte-identical between them. The remaining diagnostics are warnings for five
unhandled XEX header IDs and unknown `xam.xex` ordinal `0000`, not split
failures.

These counters describe successful binary analysis only. They do not add to
the decomp.dev matching percentage until reconstructed Loader source is
compiled and compared with objdiff.

## Matching target

Loader_DLL.xex is the second matching target. Its pipeline is
`tools/loader_matching.py`, kept separate from Swing's `tools/matching.py`:

```sh
T=$PWD/work/matching-tools
python3 tools/loader_matching.py --fresh-analysis --record \
  --jeff work/jeff/target/release/jeff --compiler-dir $T/compilers/X360/16.00.10224.00 \
  --wrapper $T/work_wibo --objdiff $T/objdiff-cli
```

- Config: `config/54540859/loader/` holds `symbols.seed.txt` (with the
  `.text` trailer seed above), `splits.txt`, `units.json` (source, flags,
  symbol sizes) and the summary `match.json` written by `--record`.
- Sources: `src/loader/`. Use the `ts4l_` name prefix and end names in the
  address.
- Measurement: objdiff over all Jeff split units. The baseline is 4,650,436
  code bytes in 17,215 functions; the first unit matches 3 functions.
- The work directory `work/loader/` has the same layout as `work/matching`,
  so the Swing helpers work unchanged:
  `TS4_MATCHING_DIR=work/loader python3 tools/fn_asm.py fn_830A02A8` and
  `TS4_MATCHING_DIR=work/loader python3 tools/fn_check.py src/loader/x.c name=0x...`.
- To add units: write the source, check it with `fn_check.py`, write a spec
  (`{"source", "flags", "functions": {name: "0x83..."}}`, the same shape as
  Swing specs), then run `python3 tools/loader_integrate.py <specs>` after a
  fresh analysis. It appends seed names, split blocks (with `.pdata` entries)
  and `units.json` entries, and refuses duplicates or overlapping ranges.
  Finish with the command above with `--record`, which refuses to record
  unless every listed symbol is a 100% match.
