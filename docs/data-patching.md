# Data patching (agent `arcwriter`)

How to change game data (for the retune, `docs/START_HERE.md` goal 2) and run the original game with it in
Xenia. No game data is committed: patches are small JSON files, outputs go under `work/` (git-ignored).

Tools: `tools/ts4_arc_write.py` (archive writer), `tools/ts4_analyser_patch.py` (Expressions.bin patcher),
`tools/ts4_iso_patch.py` (patched folder), tests in `tests/test_arc_write.py` (synthetic data only).
Confidence tags as elsewhere: **V** verified by measurement or code, **I** inferred, **U** untested.

## 1. Pipeline

```sh
ISO="orig/54540859/Top Spin 4 (World) (En,Fr,De,Es,It).iso"
mkdir -p work/patched
# 1. extract the member (writes work/disc/arc/fa94f637.bin)
python3 tools/ts4_arc.py Core.arc --iso "$ISO" --extract fa94f637 --out work/patched/orig
# 2. patch it (JSON: graph name or hash -> node index -> new values; see the tool's docstring)
python3 tools/ts4_analyser_patch.py work/patched/orig/fa94f637.bin patch.json work/patched/Expressions.bin
# 3. rebuild Core.arc with the member replaced (raw mode by default)
python3 tools/ts4_arc_write.py Core.arc work/patched/Core.arc --iso "$ISO" \
    --replace Expressions.bin=work/patched/Expressions.bin --verify
# 4. produce a game folder (about 5.7 GB) or just the arc
python3 tools/ts4_iso_patch.py "$ISO" work/patched/game --arc Core.arc=work/patched/Core.arc
python3 tools/ts4_iso_patch.py "$ISO" work/patched/arcs --arc Core.arc=work/patched/Core.arc --only-arcs
```

`--replace` takes a hex key (`fa94f637`, `0xFA94F637`), a leaf name (`Expressions.bin`; an error if two members
share the leaf name, then use the key) or a full path (`/media/x.bin`, hashed with `ts4_arc.path_hash`).
`--verify` re-reads the output with `ts4_arc.py`, checks the header and every member.
`ts4_iso_patch.py` only reads the ISO, refuses any output directory outside `work/` or non-empty, refuses more
than 10 GB or less free space than needed, and has `--dry-run`. It skips `$SystemUpdate/` (the dashboard update,
not game data) unless `--with-system-update`.

Patch file example (the node indexes are positions in the graph's node list, as printed by
`ts4_analyser.py --json`; numbers here are placeholders, not recommendations):

```json
{
  "FatigueConst":   {"0": {"value": 3000.0}},
  "LetProbability": {"0": {"keys": {"0": {"y0": 0.0}}}}
}
```

CURVE key fields are `x0`, `x1`, `y0`, `slope`; CONST has `value`. The patcher edits floats in place (same
size, no offsets move), then re-parses, checks that only the intended 4-byte words changed, that the graph
structure is identical and that the values read back, and evaluates each touched graph before and after
(inputs 0, 0.5, 1 by default; `--probe` to change). Only CONST and CURVE nodes are patchable.

## 2. Archive format as written (V unless noted)

Layout, as read by `tools/ts4_arc.py` and confirmed by the byte-identical rebuild below:

* Header (`data_start` = u32@0 + 4 bytes: fixed header, FAT of `{key, offset, size}` sorted by key, directory index,
  name pool) is copied verbatim. Only `offset` and `size` of FAT entries change.
* Member data follows, **contiguous in the original data order** (which is not the key order). `Core.arc` has no
  gaps and no alignment (4,834 of the 5,641 members in 60 other archives start on non-16-byte offsets, 2,782 on
  non-4-byte offsets), and the file ends with the last member. The writer nevertheless preserves any gaps and
  tail bytes it finds, so unusual archives still round-trip. Entries that share storage stay shared.
* The archive-level tag at 0x1C is not changed. There is no archive-wide hash or size field to update: the file size
  is implied, and no checksum over the FAT or the data exists in the header.

### Replaced members: raw (chosen) vs LZX-stored (fallback)

**Chosen: `--mode raw`, the new bytes stored as-is with no `PAM-LZX` wrapper.** Evidence that the game accepts it:

1. Stream-open code `fn_88634220` (a virtual method of the compression file-system layer, vtable `0x880F81E8`)
   reads the first 8 bytes of the stream, passes them to `fn_88626E50`, and branches on the result:
   * non-null: builds the decompressing stream object (0x54 bytes, vtable `0x880F824C`);
   * null (`0x88634384`): seeks back to 0 and builds the plain pass-through stream object (0x18 bytes, vtable
     `0x880F821C`). The same pass-through is taken when the open flags have neither read bit (`flags & 0x401`)
     or have `0x8000` set.
2. `fn_88626E50` compares the 8 bytes with `"PAM-LZX"` (string at `0x880F6E54`; the code returns the default
   compressor on an exact match) and then with `"PAM-" + <3-letter name>` of every registered compressor
   (virtual method at +0x34 of each; the table is at `0x88D452A0`, count at `0x88D45B24`). No match returns 0.
   This is the only place in the executable that recognises the tag, so a member whose first 8 bytes are not a
   registered tag is read raw. (`docs/disc-data.md` says `PAM-LZX` is not in the executable; it is, at that address.)
3. The same wrapper is what the disc members hit: all 1,250 `Core.arc` members and 5,641 members of 60 other
   archives begin with `PAM-LZX\0`, so the disc itself never exercises the raw path (**U**: not run in Xenia yet).
4. Size handling: the FAT `size` field is the stored size, and the raw stream's size is the underlying stream's,
   so a raw member reads back at exactly the FAT size. The loader does not need the uncompressed size from
   anywhere else for a raw member (**I**).

Caveat: a raw member must not start with a registered tag (`PAM-LZX`, and any other `PAM-xxx` compressor). Real
data never does.

**Fallback: `--mode lzx-stored`**, a `PAM-LZX` blob whose frames hold LZX *uncompressed blocks* (block type 3),
in 1 MiB chunks of 32 KiB frames, with the chunk checksums as the game's encoder writes them. Facts established
from disc members (V): the per-chunk checksum is `zlib.crc32` of that chunk's bytes (everything from its start
offset to the next chunk or the end, including the 5 trailing zero bytes); it was true for every single-chunk
member tested. Unknown (U): the 12-byte digest at blob offset 24. It is not CRC-32 or Adler-32 of the data or
header and not an MD5/SHA prefix of the obvious inputs; its first word is constant (`0x139CB3FF`) for every
one-chunk member and differs by chunk count. The writer copies it from the member being replaced (any size) and
writes zeros for a new member. The tool's own decoder accepts the result; whether the game verifies the digest
or the chunk CRCs was not determined (the decoder that consumes the wrapper was not traced). Use this only if raw
fails.

### Existing decoder defect found on the way

`tools/ts4_lzx.py` fails on one `Core.arc` member (key `0x3fb95789`, a 1,180,181-byte stored `BIKi` video:
`bad block type 7` at chunk 0, frame 26). After an uncompressed (type 3) block of odd length the decoder skips a
pad byte; the game's encoder does not pad, the next block header starts at the odd offset. Removing the skip
(tested on a scratch copy under `work/agents/arcwriter/lzxexp/`) decodes that member (1,201,164 bytes) and changes
no other member (all 1,250 compared). `ts4_lzx.py` was not edited (not in this agent's scope); the writer emits no pad
either. The member is copied verbatim by the writer, so rebuilds are unaffected.

## 3. Round-trip results (local, `Core.arc` from the disc image)

| Check | Result |
|---|---|
| Original `Core.arc` | 36,997,962 B, sha256 `7df7bfd575150e9ff3b3a171bada368e8bb4d6676ef82505f46961da0aefbf50` |
| Rebuild with no replacements | 36,997,962 B, sha256 identical (**byte-identical**), 1,250 entries |
| Identity rebuild read back | stored bytes of all 1,250 members equal (implied by byte identity); the original decodes with `ts4_arc.py` for 1,249 members (71,232,521 B in total, 52 s), the 1,250th is `0x3fb95789` (defect above) |
| `Settings.bin` (key `0x334E7E0D`) replaced by its own decoded bytes, 286,492 B, sha256 `55cb175dbaf64e30d75f6fe72ae71305a39a39cffca7a2fa3b2e5471431a0167` | raw: archive 37,244,346 B, sha256 `7d534fd03ce13f63fd598f737dfc0fdc3efc56523f026ecbef27f0f3fd5b8f38`; member reads back identical; the other 1,249 members decode identical to the original (`0x3fb95789`: stored bytes identical) |
| Same, `--mode lzx-stored` | archive 37,244,432 B, sha256 `ebba7bc44d9bedde99ed7e73a1f60ef3ffc0d9201162cc7bb8b95eaac6132cd5`; member stored size 286,578 B (the original compressed member is 40,108 B); reads back identical |
| `Settings.bin` + 12,345 zero bytes (growth) in both modes | reads back identical, all later members shifted correctly |
| `Expressions.bin` (key `0xFA94F637`, 581,988 B, sha256 `fd3bc49b44ca4b77deebc58acaefe67763a273538f4901266f949e9ec9dedee9`) patched with the two-edit example in section 1 | patched file 581,988 B, sha256 `c0fb723718c4154668d6b50e00292e89131f6c2a932167ea05463b2a10d686e2`, 2 words changed; rebuilt `Core.arc` (raw) 37,505,524 B, sha256 `cd001c5a5aa322bbdded846dd07dfa52114157fad38807a831d77744a29d3bdf`, member reads back as patched |

The raw archive is larger because the replaced member is no longer compressed (about 246 KB for `Settings.bin`,
about 250 KB for `Expressions.bin`); this is irrelevant to the loader.

`python3 -m unittest tests.test_arc_write` builds synthetic archives (with gaps and a tail), stored blobs
from 0 B to 2.5 MB (one to three chunks), and a synthetic `Expressions.bin`; it covers identity, grow, shrink,
shared storage, overlap rejection, key resolution, both modes, the CLI and the analyser patcher.

## 4. Loading it in Xenia

Not launched in this session. Xenia Edge and Canary are in `/Applications` (`Xenia-edge.app`,
`Xenia-edge-x64.app`).

1. Build the folder: `python3 tools/ts4_iso_patch.py "$ISO" work/patched/game --arc Core.arc=work/patched/Core.arc`.
   About 5.7 GB; the folder has `default.xex`, `Swing_DLL.xex`, `Loader_DLL.xex`, `Core.arc`, etc. at its root, as
   on the disc. (`--only-arcs` gives just the arc if you already have an extracted folder.)
2. Start Xenia and open `work/patched/game/default.xex` (File > Open, or pass the path on the command line). Xenia
   mounts the xex's directory as the game volume. Keep an unmodified copy of the folder or the original ISO to
   compare behaviour with; do not edit the ISO.
3. Alternative if folder loading misbehaves: build an ISO from the folder with an `extract-xiso`-style tool
   (not installed here; **U**).
4. Test one change at a time. A quick check that the data is read: change one `FatigueConst` or `LetProbability`
   value by a large factor and look for the effect (the graphs' wiring is in `docs/gameplay/analyser-graphs.md`).
   The game logs file opens; Xenia's log (`xenia.log`) shows `Core.arc` being opened.
5. If the title crashes on boot or loads the unmodified behaviour, go back one step: rebuild with
   `--mode lzx-stored`, or first test the identity rebuild (no replacements), which must behave exactly like the
   original.

## 5. Risks and unknowns

* **Raw members are untested in the running game** (**U**). The code path is clear in `fn_88634220`, but no disc
  member is raw. If the game or Xenia misbehaves, try `--mode lzx-stored`; its digest is unexplained (section 2).
* **Overlay archives.** The loader names `Media\Patch\Patch.arc`, `PatchData.arc`, `MyPatchData.arc`
  (`docs/gameplay/df.md`). Title Update #1 content (`docs/additional-content.md`) may override or shadow
  `Core.arc` members. If a patch has no effect, check whether the same key exists in a patch archive Xenia
  mounts for the title update, and patch that archive too (same tools; `--iso` takes only disc images, so
  extract the TU archive and pass its path).
* **Integrity checks.** None found: the `.arc` has no hash or size over the whole file, the xex was not examined for
  per-file hashes, and the raw path (`fn_88634220`) does no verification. Per-chunk CRC-32 and the 12-byte digest
  exist only inside `PAM-LZX` blobs; whether the decompressor checks them is unknown (not traced). A different file
  size for `Core.arc` is not recorded anywhere I saw; `Layoutall.bin` is a type layout, not a file table (**I**).
* **Hard-coded sizes.** An XBin image is loaded by its own size and offsets, so the replaced member must be a
  valid XBin of the same type. The analyser patcher keeps the size fixed. Changing the size of `Settings.bin` or
  other XBin files (adding rows) needs offset rewriting that these tools do not do.
* **Memory sizing.** Larger replaced members use more memory while loading; for the small data files here this is
  not a concern, the 1.2 MB video member shows the arcs handle large members.
* **Unmodified decoder gap.** `tools/ts4_lzx.py` cannot read `0x3fb95789` (section 2); irrelevant to patching
  but note it before running a "decode every member" check.
* **Tuning validity.** Editing a curve key changes behaviour everywhere that graph is used (all 341 graphs share
  inputs through `DefaultAttributes`, `analyser-graphs.md` section 6.3); keep a patch file per experiment so changes
  can be reverted by rebuilding from the original.
