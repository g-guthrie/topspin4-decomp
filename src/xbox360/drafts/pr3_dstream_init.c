/* PR3 DRAFT: decompressing stream initialisation (not compiled into the build).
 *
 * 0x8827D2F8 (0x1b8) ts4_dstream_init_8827D2F8 - 13 instructions differ: argument set-up order of the second and
 *   third ReadAt calls, one add operand order (usize + max chunk), and the vtable load of the heap-scope leave call.
 *   Tried: locals for the inner stream and its vtable, a forceinline leave helper, volatile vtable read, both add
 *   orders. fn_equiv: EQUIVALENT, 106 valid trials, 100% coverage.
 *
 * What it does (called once by CFileSystemCompress::Open after it recognised a PAM-LZX blob):
 *   push a heap scope {vtable 0x880F7AEC, heap of lbl_88D45B38, owner->+0xC};
 *   inner->ReadAt(&s->nchunks, 0x1C, 8, SET): nchunks +0x1C, chunk size +0x20, last chunk size +0x24,
 *     total size +0x28, 12-byte digest +0x2C (the blob header after "PAM-LZX\0");
 *   table = alloc(nchunks * 8): +0x40 chunk start offsets, +0x44 chunk checksums;
 *   read nchunks words at blob offset 0x24 into +0x40 (the first is the header length) and nchunks words after
 *     them into +0x44;
 *   largest compressed chunk = max over i of chunk_csize(i) (0x8827D280);
 *   one buffer of (nchunks == 1 ? last : chunk size) + largest: +0x3C decoded chunk, +0x38 compressed chunk;
 *   compressor->vslot15(compressor, 1, chunk size) = create the LZX decompression context (0x88639A78);
 *   pop the heap scope. The caller then decodes chunk 0 (ts4_if_get_u32_off40_8827D4B0).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif

typedef struct HeapScope HeapScope;
typedef struct HeapScopeVt { void *dtor; void (*enter)(HeapScope *); void (*leave)(HeapScope *); } HeapScopeVt;
struct HeapScope { HeapScopeVt *vt; void *heap; void *arg; };
extern HeapScopeVt lbl_880F7AEC;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *mgr);
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);

typedef struct Stream Stream;
typedef struct StreamVt { void *dtor; void *read; int (*read_at)(Stream *, void *, u32, int, int); } StreamVt;
struct Stream { StreamVt *vt; };
typedef struct Compressor Compressor;
typedef struct CompressorVt { void *s[15]; int (*create_context)(Compressor *, int, u32); } CompressorVt;
struct Compressor { CompressorVt *vt; };
typedef struct Owner04 { char pad[0xc]; void *heap_arg; } Owner04;

typedef struct DStream {
    void *vt;                /* 0x00 */
    Owner04 *owner;          /* 0x04 */
    char pad08[0xc];
    Stream *inner;           /* 0x14 */
    Compressor *compressor;  /* 0x18 */
    int nchunks;             /* 0x1c  first word of the 0x1c bytes read from blob offset 8 */
    int chunk_size;          /* 0x20 */
    int last_chunk_size;     /* 0x24 */
    int total_size;          /* 0x28 */
    u8 digest[12];           /* 0x2c */
    u8 *cbuf;                /* 0x38 */
    u8 *obuf;                /* 0x3c */
    int *chunk_offs;         /* 0x40 */
    u32 *chunk_crcs;         /* 0x44 */
} DStream;

int fn_8827D280(DStream *s, int i);
static __forceinline int chunk_usize(DStream *s, int i) { return (i == s->nchunks - 1) ? s->last_chunk_size : s->chunk_size; }

void ts4_dstream_init_8827D2F8(DStream *s)
{
    HeapScope scope;
    int *hdr;
    int pos;
    int n;
    int usize;
    int maxc;
    int i;
    int *tbl;
    u8 *buf;
    void *arg = s->owner->heap_arg;
    scope.vt = &lbl_880F7AEC;
    scope.heap = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38);
    scope.arg = arg;
    scope.vt->enter(&scope);
    hdr = &s->nchunks;
    pos = s->inner->vt->read_at(s->inner, hdr, 0x1c, 8, 2) + 8;
    tbl = (int *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, s->nchunks * 8, 4, 0, 0);
    s->chunk_offs = tbl;
    s->chunk_crcs = (u32 *)(tbl + s->nchunks);
    n = s->inner->vt->read_at(s->inner, tbl, s->nchunks * 4, pos, 2);
    s->inner->vt->read_at(s->inner, s->chunk_crcs, s->nchunks * 4, n + pos, 2);
    usize = chunk_usize(s, 0);
    maxc = 0;
    for (i = 0; i < s->nchunks; i++) {
        int c = fn_8827D280(s, i);
        if (maxc < c) maxc = c;
    }
    buf = (u8 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, maxc + usize, 1, 0, 0);
    s->obuf = buf;
    s->cbuf = buf + chunk_usize(s, 0);
    s->compressor->vt->create_context(s->compressor, 1, s->chunk_size);
    scope.vt->leave(&scope);
}
