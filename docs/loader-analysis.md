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
