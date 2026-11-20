/* PR3 DRAFT: CFileSystemCompress::Open, the PAM-LZX / raw member switch (not compiled into the build).
 *
 * 0x88634220 (0x2fc) ts4_fs_compress_open_88634220 - 4 instructions differ: the byte loads of +0x30 and +0x28
 *   use r11/r9 where the target uses r10/r8 (scratch numbering only). Tried: u8/int helpers, explicit != 0,
 *   LTCG route. Everything else (block layout, both inline stream constructors, the null paths) matches.
 *   fn_equiv: EQUIVALENT, 229 valid trials, 100% coverage.
 *
 * What it does: vtable 0x880F81C0 slot 10 (out, self, path, mode, arg).
 *   push a heap scope; open the path on the wrapped file system (+0x24, slot 10) into *out.
 *   If a stream came back and decompression is on (+0x30):
 *     mem = stream->slot11() (memory pointer of in-memory streams);
 *     if mode has a read bit (mode & 0x401) and not the raw bit (0x8000): read the 8-byte tag (copied from mem when
 *       it is a non-empty string, else stream->ReadAt(tag, 8, 0, SET)) and look up a compressor (0x88626E50).
 *     Compressor found: *out = new decompressing stream (0x54 bytes, vtable 0x880F824C: fs, mode, compressor,
 *       inner = the member stream, position 0), initialise it (0x8827D2F8) and decode chunk 0.
 *     Otherwise: seek the stream back to 0 (slot 7, SET); if copy mode (+0x28) close it through its file system
 *       (slot 22), run 0x886308B8 on the path and reopen through our own slot 10; else wrap it in a pass-through
 *       stream (0x18 bytes, vtable 0x880F821C, forwards every slot to +0x14).
 *   pop the heap scope. So raw members (no PAM tag) are read straight through, and mode bit 0x8000 forces raw.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
void *ts4_memset(void *, int, unsigned int);
void ts4_copy_bytes(void *dst, const void *src, u32 n);
void ts4_assign_formatted_text(void *dst, const char *src);
void ts4_destroy_owned_object(void *p);

typedef struct HeapScope HeapScope;
typedef struct HeapScopeVt { void *dtor; void (*enter)(HeapScope *); void (*leave)(HeapScope *); } HeapScopeVt;
struct HeapScope { HeapScopeVt *vt; void *heap; void *arg; };
extern HeapScopeVt lbl_880F7AEC;
extern HeapScopeVt lbl_880F821C;   /* pass-through stream vtable */
extern HeapScopeVt lbl_880F824C;   /* decompressing stream vtable */
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *mgr);
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);

typedef struct Stream Stream;
typedef struct FileSystem FileSystem;
typedef struct StreamVt {
    void *dtor; void *read; int (*read_at)(Stream *, void *, u32, int, int); void *s3; void *write; void *size;
    void *tell; int (*seek)(Stream *, int, int); void *s8; void *s9; void *s10; const char *(*memory)(Stream *);
} StreamVt;
struct Stream { StreamVt *vt; FileSystem *fs; };
typedef struct FsVt { void *s[10]; Stream **(*open)(Stream **, FileSystem *, const char *, u32, u32); void *s11[11]; void (*close)(FileSystem *, Stream **); } FsVt;
struct FileSystem { FsVt *vt; };

typedef struct Compressor Compressor;
Compressor *fn_88626E50(const char *tag);

typedef struct PassStream { void *vt; void *fs; u32 flags; u32 f0c; u8 f10; Stream *inner; } PassStream;
typedef struct DStream {
    void *vt; void *fs; u32 flags; u32 f0c; u8 f10; Stream *inner; Compressor *compressor;
    int nchunks; int chunk_size; int last_chunk_size; int total_size; u8 digest[12];
    u8 *cbuf; u8 *obuf; int *chunk_offs; u32 *chunk_crcs; int f48; int pos; void *owner;
} DStream;
void fn_8827D2F8(DStream *d);
int ts4_if_get_u32_off40_8827D4B0(DStream *d, int chunk);

typedef struct FsCompress {
    FsVt *vt; char pad04[8]; void *heap_arg; char pad10[0x14];
    FileSystem *child;   /* 0x24 */
    u8 copy_mode;        /* 0x28 */
    char pad29[7];
    u8 enabled;          /* 0x30 */
} FsCompress;
typedef struct OwnedText { void *p; u32 w[3]; } OwnedText;
void fn_886308B8(FsCompress *fs, OwnedText *path);


typedef struct StreamBase { void *vt; void *fs; int flags; u32 f0c; u8 f10; Stream *inner; } StreamBase;
static __forceinline void base_init(StreamBase *b, void *fs, int flags, Stream *inner)
{ b->fs = fs; b->flags = flags; b->f0c = 0; b->f10 = 0; b->inner = inner; }
static __forceinline PassStream *pass_ctor(PassStream *p, void *fs, int flags, Stream *inner)
{ base_init((StreamBase *)p, fs, flags, inner); p->vt = &lbl_880F821C; return p; }
static __forceinline PassStream *pass_new(void *fs, int flags, Stream **in)
{
    PassStream *p = (PassStream *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x18, 4, 0, 0);
    if (p != 0) { return pass_ctor(p, fs, flags, *in); }
    return 0;
}
static __forceinline DStream *dstream_ctor(DStream *d, void *fs, int flags, Stream *inner, Compressor *c)
{
    base_init((StreamBase *)d, fs, flags, inner);
    d->compressor = c;
    d->vt = &lbl_880F824C;
    d->pos = 0; d->owner = 0; d->cbuf = 0; d->obuf = 0; d->chunk_offs = 0; d->chunk_crcs = 0;
    fn_8827D2F8(d);
    ts4_if_get_u32_off40_8827D4B0(d, 0);
    return d;
}
Stream **ts4_fs_compress_open_88634220(Stream **out, FsCompress *self, const char *path, int flags, u32 arg)
{
    HeapScope scope;
    char tag[8];
    Stream *tmp;
    OwnedText t;
    void *harg = self->heap_arg;
    scope.vt = &lbl_880F7AEC;
    scope.heap = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38);
    scope.arg = harg;
    scope.vt->enter(&scope);
    self->child->vt->open(out, self->child, path, flags, arg);
    if (*out != 0 && self->enabled) {
        const char *mem = (*out)->vt->memory(*out);
        Compressor *c = 0;
        if ((flags & 0x401) != 0 && (flags & 0x8000) == 0) {
            ts4_memset(tag, 0, 8);
            if (mem != 0 && *mem != 0) {
                u32 n = strlen(mem) + 1;
                ts4_copy_bytes(tag, mem, n < 8 ? n : 8);
            } else {
                (*out)->vt->read_at(*out, tag, 8, 0, 2);
            }
            c = fn_88626E50(tag);
        }
        if (c == 0) {
            (*out)->vt->seek(*out, 0, 2);
            if (self->copy_mode) {
                (*out)->fs->vt->close((*out)->fs, out);
                ts4_assign_formatted_text(&t, path);
                fn_886308B8(self, &t);
                ts4_destroy_owned_object(t.p);
                *out = *self->vt->open(&tmp, (FileSystem *)self, path, flags, arg);
            } else {
                *out = (Stream *)pass_new(self, flags, out);
            }
        } else {
            DStream *d = (DStream *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x54, 4, 0, 0);
            if (d != 0) d = dstream_ctor(d, self, flags, *out, c);
            else d = 0;
            *out = (Stream *)d;
        }
    }
    scope.vt->leave(&scope);
    return out;
}
