/* PR3 DRAFT: archive directory binary searches (not compiled into the build).
 *
 * 0x8827EC98 (0x7c) ts4_arc_fat_find_8827EC98 - 12 instructions differ, register allocation only: the hoisted key
 *   lands in r5 and the table copy in r6 (target: table r5, lo r6, hi r7, key r8). Tried: loop forms (while/do,
 *   early return vs result variable, re-read *key), compare operand orders, C++ member with const u32 &, inline
 *   accessors, 0..10 operand-order pads, LTCG route. fn_equiv: EQUIVALENT, 88 valid trials, 100% block coverage.
 * 0x8827EBB8 (0x74) ts4_arc_dir_find_8827EBB8 - same shape for 8-byte entries, same 12 instructions.
 *   fn_equiv: EQUIVALENT, 57 valid trials, 100% coverage.
 *
 * What they do: t points at a self-relative table header {int rel; int count;}; entry i is at
 * (char *)t + rel + i * stride. Binary search on the first u32 of each entry (unsigned compare), returning the
 * entry or 0. For an archive t is the loaded .arc header (CFileSystemPackArchive +0x3C): rel = file u32 at 4
 * (0x20), count = file u32 at 8, entries {path_hash, offset, size} (offset relative to data_start =
 * archive +0x34). The key is the crc32 (case-insensitive) of the normalised "/dir/file" path
 * (ts4_hash_normalized_path_886090A0). The 8-byte variant serves the {hash, value} index after the FAT.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif

typedef struct RelTable { int rel; int count; } RelTable;
typedef struct ArcFatEntry { u32 hash; u32 offset; u32 size; } ArcFatEntry;
typedef struct ArcDirEntry { u32 hash; u32 value; } ArcDirEntry;


ArcFatEntry *ts4_arc_fat_find_8827EC98(RelTable *t, const u32 *key)
{
    ArcFatEntry *r = 0;
    int lo = 0;
    int hi = t->count - 1;
    if (hi >= 0) {
        int rel = t->rel;
        u32 k = *key;
        do {
            int mid = (hi + lo) / 2;
            ArcFatEntry *e = (ArcFatEntry *)((char *)t + (mid * 12 + rel));
            if (e->hash == k) { r = e; break; }
            if (e->hash < k) lo = mid + 1; else hi = mid - 1;
        } while (lo <= hi);
    }
    return r;
}


ArcDirEntry *ts4_arc_dir_find_8827EBB8(RelTable *t, const u32 *key)
{
    ArcDirEntry *r = 0;
    int lo = 0;
    int hi = t->count - 1;
    if (hi >= 0) {
        int rel = t->rel;
        u32 k = *key;
        do {
            int mid = (hi + lo) / 2;
            ArcDirEntry *e = (ArcDirEntry *)((char *)t + (mid * 8 + rel));
            if (e->hash == k) { r = e; break; }
            if (e->hash < k) lo = mid + 1; else hi = mid - 1;
        } while (lo <= hi);
    }
    return r;
}
