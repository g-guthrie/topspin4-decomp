/*
 * DF draft: data-format primitives of Swing_DLL.xex (Top Spin 4, Xbox 360), readable C.
 * Not compiled into the matching build.  Evidence and confidence: work/gameplay-notes/df.md.
 * Addresses are Swing_DLL.xex virtual addresses.  `/ * ? * /` marks guesses.
 *
 * Covers:
 *   - XBin container header (fn_8892A968, CXBinDataServer load)
 *   - self-relative array header {rel,count} used by every typed XData struct (fn_881899D8 & co)
 *   - the two curve evaluators used by the shot templates (fn_881899D8, fn_8817A688)
 *   - archive path hash (fn_886090A0 -> fn_886084C8) and FAT lookup (fn_8827EC98, fn_886217C0)
 *   - the hkx load flow (fn_886472C0 for AOD\%u.hkx, fn_88880B88 for Physics\Physics.hkx)
 * Everything is big endian (Xbox 360): a port must byte-swap on little-endian hosts.
 */

#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;

/* ---- XBin file header: five u32 read from file offset 0 (fn_8892A968, size check "> 0x14") ---- */
struct XBinHeader {
    u32 root_hash;     /* +0x00 -> server+0x20; passed to the XData tree as the root type/node id (M)   */
    u32 layout_hash;   /* +0x04 -> server+0x30; looked up in the layout server (CLayoutServer) (M)      */
    u32 mem_size;      /* +0x08 -> server+0x2c; allocation size when the pool allocator is not used (M) */
    u32 section_count; /* +0x0C -> server+0x48 (H)                                                       */
    u32 section_table; /* +0x10 -> server+0x4c = body + this - 0x14: u32 file offsets of the sections (H) */
};
/* body = file bytes after the header, loaded as one block (server+0x24, size = file size - 0x14).
 * Typed structs are addressed as body + offset (vtable slots 0x48/0x4c of CXBinDataServer return
 * `server->body + arg`).  The first 12 bytes of every section are overwritten at load time with
 * {server*, table-entry*, 0} (runtime links), so they are dead bytes on disk (H). */

/* ---- self-relative array: header {rel, count}; element i is at (header_addr + rel + i*stride) ---- */
struct XRelArray {
    s32 rel;   /* -1 = null (checked as `cmpwi r10,-1` everywhere) */
    s32 count;
};

static inline const void *xrel_begin(const struct XRelArray *h)
{
    return h->rel == -1 ? NULL : (const u8 *)h + h->rel;
}

static inline const void *xrel_end(const struct XRelArray *h, size_t stride)
{
    return h->rel == -1 ? NULL : (const u8 *)h + h->rel + (size_t)h->count * stride;
}

/* ---- curve type A: 16-byte keys, header {rel,count}; fn_881899D8(header, x) (H) ------------------
 * Segment i spans x in [x0, x1] and interpolates y0 -> y1 linearly; x is clamped to the segment, so
 * values outside the key range are flat.  The scan picks the LAST key whose x0 <= x, starting from the
 * first key (so x below the first key uses key 0 clamped to its start).  Division by (x1 - x0)
 * is unguarded (a zero-length segment gives 0/0).  The original uses a select-table idiom for min/max. */
struct CurveKey16 { float x0, x1, y0, y1; };

float ts4_curve16_eval_881899D8(const struct XRelArray *h, float x)
{
    const struct CurveKey16 *k = (const struct CurveKey16 *)xrel_begin(h);
    const struct CurveKey16 *end = k ? k + h->count : NULL;
    const struct CurveKey16 *pick = k;
    const struct CurveKey16 *it;
    float t;

    for (it = k; it != end && it->x0 <= x; ++it) {
        pick = it;
    }
    t = x - pick->x0;
    if (t < 0.0f) t = 0.0f;
    if (t > pick->x1 - pick->x0) t = pick->x1 - pick->x0;
    return t / (pick->x1 - pick->x0) * (pick->y1 - pick->y0) + pick->y0;
}

/* ---- curve type B: 20-byte keys, node type 0xF9F12A60; fn_8817A688(header, x) (H) -----------------
 * y = c + clamp(x - x0, 0, x1 - x0) * m  (affine in x inside the segment; the 5th word is not read). */
struct CurveKey20 { float x0, x1, c, m; u32 unused; };

float ts4_curve20_eval_8817A688(const struct XRelArray *h, float x)
{
    const struct CurveKey20 *k = (const struct CurveKey20 *)xrel_begin(h);
    const struct CurveKey20 *end = k ? k + h->count : NULL;
    const struct CurveKey20 *pick = k;
    const struct CurveKey20 *it;
    float t;

    for (it = k; it != end && it->x0 <= x; ++it) {
        pick = it;
    }
    t = x - pick->x0;
    if (t > pick->x1 - pick->x0) t = pick->x1 - pick->x0;
    if (t < 0.0f) t = 0.0f;
    return t * pick->m + pick->c;
}

/* ---- name hashes: zlib crc32, seed 0, of the exact ASCII string (fn_88608590, table lbl_880C84C0) ---- */
u32 ts4_name_hash_88608590(const char *s)
{
    u32 c = 0xFFFFFFFFu;
    int k;
    for (; *s; ++s) {
        c ^= (u8)*s;
        for (k = 0; k < 8; ++k) c = (c >> 1) ^ (0xEDB88320u & (0u - (c & 1u)));
    }
    return ~c;
}

/* ---- archive path hash: fn_886090A0 (normalise) + fn_886084C8 (crc32 of tolower) (H) ------------- */
u32 ts4_archive_path_hash(const char *path)
{
    char tmp[0x200];
    size_t n = 0;
    u32 c = 0xFFFFFFFFu;
    int k;

    for (; path[n] && n < sizeof(tmp) - 2; ++n) tmp[n] = path[n] == '\\' ? '/' : path[n];
    tmp[n] = 0;
    {
        const char *p = tmp;
        char buf[0x202];
        size_t i = 0;
        if (p[0] && p[1] == ':') p += 2;
        if (*p != '/') buf[i++] = '/';
        while (*p) buf[i++] = *p++;
        buf[i] = 0;
        for (p = buf; *p; ++p) {
            u8 ch = (u8)*p;
            if (ch >= 'A' && ch <= 'Z') ch = (u8)(ch + 0x20); /* fn_88567730 */
            c ^= ch;
            for (k = 0; k < 8; ++k) c = (c >> 1) ^ (0xEDB88320u & (0u - (c & 1u)));
        }
    }
    return ~c;
}

/* ---- .arc FAT: file table = binary search on the first u32 of 12-byte entries (fn_8827EC98) ---- */
struct ArcFatEntry { u32 path_hash; u32 offset; u32 size; };  /* offset/size: stream code fn_8827EE00/EEA0 (H) */
/* absolute file position of a member = fat_end_pos + entry->offset (+ cursor): archive+0x34 + entry+4 */

const struct ArcFatEntry *ts4_arc_find_8827EC98(const struct XRelArray *files, u32 hash)
{
    const struct ArcFatEntry *base = (const struct ArcFatEntry *)xrel_begin(files);
    int lo = 0, hi = files->count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (base[mid].path_hash == hash) return &base[mid];
        if (base[mid].path_hash < hash) lo = mid + 1; else hi = mid - 1;
    }
    return NULL;
}

/* ---- Havok loads (H for the call structure, see df.md section 5) ------------------------------------
 * AOD clip (fn_886472C0): memory stream over the file buffer -> hkBinaryPackfileReader load (fn_884CE818)
 *   -> root = hkRootLevelContainer; clip->animation = findObjectByType(root, hkaAnimationContainer)
 *   (fn_884CCC70 with the hkClass at 0x88CACC08).
 * Physics (fn_88880B88): same reader; root hkRootLevelContainer (hkClass 0x88D26F54); then
 *   physicsData = findObjectByType(root, hkpPhysicsData  @0x88D25C34)   -> this+0x18
 *   ragdolls    = findObjectByType(root, hkaRagdollInstance @0x88CACE78) -> this+0x1C
 *   every system in physicsData->systems (array at +0x0C) is registered body by body (fn_8887B380, fn_88880168).
 */
