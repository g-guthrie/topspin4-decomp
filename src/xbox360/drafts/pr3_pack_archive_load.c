/* PR3 DRAFT: CFileSystemPackArchive::Load, header and FAT into memory (not compiled into the build).
 *
 * 0x886217C0 (0x368) ts4_pack_archive_load_886217C0 - 42 instructions differ: the eight-word XOR block is
 *   scheduled differently (the target re-reads the key word and XORs it with itself), the global heap pointer is
 *   addressed through a full address register instead of the shared `lis`, and a few argument set-ups are
 *   reordered. The synchronous path up to the tag test matches. fn_equiv: UNCHECKED (no mismatch in 726 valid
 *   trials, coverage 50%: the async path spins until a completion byte is set by another thread).
 *
 * What it does (vtable 0x880F8440 slot 23; args: archive, stream, path, async):
 *   heap scope push; +0x9E = 0.
 *   Synchronous: read u32 w0; if w0 == 0xFFFFFFFF it is an extended header and the header size is the 4th u32,
 *     else header size = w0 (+0x30). hdr = alloc(size) (+0x38); read it; data_start (+0x34) = Tell();
 *     FAT table (+0x3C) = hdr (so the FAT {rel, count} is the file's u32s at 4 and 8). If hdr bytes 0x18..0x1A
 *     (file 0x1C) are not "PAM": the header is obfuscated: key = hdr word 6, XOR words 0..7 with key, then write
 *     "PAM-ZLB\0" (lbl_880F6E9C) over the tag. Base stream (+0x2C) = stream, in-memory flag (+0x64) = 0,
 *     Seek(data_start, SET).
 *   Async: ready byte +0x9D = 0; stream->ReadAsync(hdr16, 0x10, 0x800, archive, 0, &ready) (slot 3) and spin with
 *     Sleep(1) until ready; extended header: size = hdr16[3], skip 12, else size = hdr16[0] and Seek(4, SET);
 *     read the rest of the header the same way into a new block; data_start = Tell(); base = stream;
 *     in-memory flag = 1; FAT = hdr; Seek(data_start, SET).
 *   heap scope pop.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-parameter" /* path: kept for the real signature */
#define __forceinline inline
#define __inline inline
#endif
typedef unsigned long long u64;

typedef struct HeapScope HeapScope;
typedef struct HeapScopeVt { void *dtor; void (*enter)(HeapScope *); void (*leave)(HeapScope *); } HeapScopeVt;
struct HeapScope { HeapScopeVt *vt; void *heap; void *arg; };
extern HeapScopeVt lbl_880F7AEC;
extern void *lbl_88D45B38;
extern u64 lbl_880F6E9C;   /* "PAM-ZLB\0" */
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *mgr);
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
void ts4_tailcall_fn_88584548_8857AFE8(u32 ms);

typedef struct Stream Stream;
typedef struct StreamVt {
    void *dtor;
    int (*read)(Stream *, void *, u32);
    void *read_at;
    int (*read_async)(Stream *, void *, u32, u32, void *, u32, volatile u8 *);
    void *write;
    void *size;
    int (*tell)(Stream *);
    int (*seek)(Stream *, int, int);
} StreamVt;
struct Stream { StreamVt *vt; };

typedef struct ArcHeader { u32 w[6]; u8 tag[8]; } ArcHeader;
typedef struct PackArchive {
    void *vt; char pad04[8]; void *heap_arg; char pad10[0x1c];
    Stream *base;       /* 0x2c */
    u32 hdr_size;       /* 0x30 */
    int data_start;     /* 0x34 */
    ArcHeader *hdr;     /* 0x38 */
    ArcHeader *fat;     /* 0x3c */
    char pad40[0x24];
    u8 in_memory;       /* 0x64 */
    char pad65[0x38];
    volatile u8 ready;  /* 0x9d */
    u8 f9e;             /* 0x9e */
} PackArchive;

void ts4_pack_archive_load_886217C0(PackArchive *a, Stream *s, const char *path, u8 async)
{
    HeapScope scope;
    void *harg = a->heap_arg;
    scope.vt = &lbl_880F7AEC;
    scope.heap = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38);
    scope.arg = harg;
    scope.vt->enter(&scope);
    a->f9e = 0;
    if (!async) {
        u32 w0 = 0;
        u32 w1, w2;
        ArcHeader *h;
        s->vt->read(s, &w0, 4);
        if (w0 == 0xFFFFFFFFu) {
            s->vt->read(s, &w1, 4);
            s->vt->read(s, &w2, 4);
            s->vt->read(s, &a->hdr_size, 4);
        } else {
            a->hdr_size = w0;
        }
        a->hdr = (ArcHeader *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, a->hdr_size, 1, 0, 2);
        s->vt->read(s, a->hdr, a->hdr_size);
        a->data_start = s->vt->tell(s);
        h = a->hdr;
        a->fat = h;
        if (h->tag[0] != 'P' || h->tag[1] != 'A' || h->tag[2] != 'M') {
            /* obfuscated header: the tag slot holds the XOR key for the first 8 words */
            u32 *w = (u32 *)h;
            u32 key = w[6];
            int i;
            for (i = 0; i < 8; i++) w[i] ^= key;
            *(u64 *)h->tag = lbl_880F6E9C;
        }
        a->base = s;
        a->in_memory = 0;
        s->vt->seek(s, a->data_start, 2);
    } else {
        u32 hdr16[4];
        int skip;
        a->ready = 0;
        s->vt->read_async(s, hdr16, 0x10, 0x800, a, 0, &a->ready);
        while (!a->ready) ts4_tailcall_fn_88584548_8857AFE8(1);
        skip = 0;
        if (hdr16[0] == 0xFFFFFFFFu) {
            skip = 12;
            a->hdr_size = hdr16[3];
        } else {
            a->hdr_size = hdr16[0];
            s->vt->seek(s, 4, 2);
        }
        a->ready = 0;
        a->hdr = (ArcHeader *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, a->hdr_size - skip, 1, 0, 2);
        s->vt->read_async(s, a->hdr, a->hdr_size - skip, 0x800, a, 0, &a->ready);
        while (!a->ready) ts4_tailcall_fn_88584548_8857AFE8(1);
        a->data_start = s->vt->tell(s);
        a->base = s;
        a->in_memory = 1;
        a->fat = a->hdr;
        s->vt->seek(s, a->data_start, 2);
    }
    scope.vt->leave(&scope);
}
