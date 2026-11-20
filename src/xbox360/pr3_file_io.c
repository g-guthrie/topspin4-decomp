/* PR3: file and archive loading path, matched functions (Swing_DLL.xex, Pam core 0x885F4E48-0x88640000 and
 * core loaders 0x881A2000-0x88287D28). Default flags (plain route).
 *
 * Path covered here (see work/pr3/checklist.md for the whole chain):
 *   request   ts4_io_open_request_88630F80 / ts4_io_query_request_88630EE8 build a 0x23C IoRequest on the stack;
 *             ts4_io_run_request_88630C90 copies it into a pooled block, queues it on the file-system accessor and
 *             waits on the block's event unless the request is fire-and-forget.
 *   mount     ts4_archive_resolve_path_886232C8 ("<name>", "<name>.arc", "<name>.oarc") and
 *             ts4_archive_create_for_path_88623190 (".arc" -> CFileSystemPackArchive, else CFileSystemOpenArchive).
 *   lookup    ts4_pack_archive_exists_886216A8: crc32 of the normalised path, binary search of the FAT.
 *   read      member stream Seek/Read (vtable 0x880F84BC), the decompressing stream's chunk size helper.
 *   LZX       ts4_lzx_create_context_88639A78 (XMemCreate(De)CompressionContext, codec 1 = LZX).
 *   physical  ts4_file_stream_win32_ctor_881A5508: prefix + path, CreateFile (xapi fn_8857B848).
 * The decompressing stream Read (needs /Oc) is in pr3_file_io_oc.c.
 */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
#define PR3_INL static __forceinline
#define PR3_NOINLINE __declspec(noinline)
extern unsigned int strlen(const char *);
int strcmp(const char *, const char *);
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
#pragma intrinsic(strlen, strcmp, strcpy, strcat, memset)
#pragma function(memcpy)
#else
#include <string.h>
#define PR3_INL static inline
#define PR3_NOINLINE
#endif

/* ---- streams (vtable layout shared by every stream class) ----
 *  0 dtor, 1 Read(buf, n), 2 ReadAt(buf, n, pos, origin), 3 ReadAsync(buf, n, chunk, ctx, 0, done*),
 *  4 Write, 5 Size, 6 Tell, 7 Seek(pos, origin: 0 = current, 1 = from end, 2 = set), 11 memory pointer */
typedef struct Pr3Stream Pr3Stream;

/* ---- archive FAT ---- */
typedef struct Pr3RelTable { int rel; int count; } Pr3RelTable;     /* first 8 bytes of the loaded .arc header */
typedef struct Pr3ArcEntry { u32 hash; int offset; int size; } Pr3ArcEntry;
Pr3ArcEntry *fn_8827EC98(Pr3RelTable *t, const u32 *key);
u32 *ts4_hash_normalized_path_886090A0(u32 *out, const char *path);

typedef struct Pr3PackArchive { char pad[0x3c]; Pr3RelTable *fat; } Pr3PackArchive;

/* CFileSystemPackArchive slot 17: does the archive hold this path? */
u32 ts4_pack_archive_exists_886216A8(Pr3PackArchive *a, const char *path)
{
    Pr3RelTable *f = a->fat;
    u32 h;
    Pr3ArcEntry *e = fn_8827EC98(f, ts4_hash_normalized_path_886090A0(&h, path));
    return 0 != e;
}

/* ---- archive member stream (0x20 bytes, vtable 0x880F84BC, made by CFileSystemPackArchive::Open 0x886215A8) ---- */
typedef struct Pr3Owner1C { char pad[0xc]; void *buf; } Pr3Owner1C;
typedef struct Pr3MemberStream {
    void *vt;
    void *archive;          /* 0x04 */
    u32 flags;              /* 0x08 */
    u32 f0c;
    u8 f10;
    Pr3ArcEntry *entry;     /* 0x14 */
    int pos;                /* 0x18 */
    Pr3Owner1C *owner;      /* 0x1c, default buffer when Read gets buf == 0 */
} Pr3MemberStream;
int fn_88613EB8(void *archive, Pr3ArcEntry *e, int pos, void *buf, int n);

/* member stream slot 7: Seek */
int ts4_arc_member_seek_8827EEA0(Pr3MemberStream *s, int off, u32 origin)
{
    switch (origin) {
    case 0: s->pos += off; break;
    case 1: s->pos = s->entry->size - off; break;
    case 2: s->pos = off; break;
    }
    return s->pos;
}

PR3_INL int pr3_imax(const int *a, const int *b) { return (*a < *b) ? *b : *a; }

/* member stream slot 1: Read(buf, n), clamped to the member size, through the archive's locked reader */
int ts4_arc_member_read_8827ED60(Pr3MemberStream *s, void *buf, int n)
{
    int pos = s->pos;
    int r = 0;
    if (pos >= 0) {
        Pr3ArcEntry *e = s->entry;
        int left = e->size - pos;
        int zero = 0;
        int m;
        void *a;
        if (n >= left) n = left;
        a = s->archive;
        m = pr3_imax(&zero, &n);
        if (buf == 0) buf = s->owner->buf;
        r = fn_88613EB8(a, e, pos, buf, m);
        if (r > 0) s->pos += r;
    }
    return r;
}

/* ---- decompressing stream (0x54 bytes, vtable 0x880F824C) ---- */
typedef struct Pr3StreamVt {
    void *dtor; void *read; void *read_at; void *read_async; void *write;
    int (*size)(Pr3Stream *);
} Pr3StreamVt;
struct Pr3Stream { Pr3StreamVt *vt; };
typedef struct Pr3DStream {
    void *vt; char pad04[0x10];
    Pr3Stream *inner;       /* 0x14 */
    void *compressor;       /* 0x18 */
    int nchunks;            /* 0x1c */
    int chunk_size;         /* 0x20 */
    int last_chunk_size;    /* 0x24 */
    char pad28[0x18];
    int *chunk_offs;        /* 0x40 blob offsets of the chunks */
} Pr3DStream;

/* compressed size of chunk i: next start (or the blob size for the last chunk) minus this start */
int ts4_dstream_chunk_csize_8827D280(Pr3DStream *s, int i)
{
    int *p = s->chunk_offs + i;
    int start = p[0];
    int end;
    if (i == s->nchunks - 1) end = s->inner->vt->size(s->inner);
    else end = p[1];
    return end - start;
}

/* ---- CCompressorLzx (vtable 0x880F62F0) slot 15 ---- */
typedef struct Pr3LzxParams { u32 flags; u32 window; u32 partition; } Pr3LzxParams;
typedef struct Pr3CompressorLzx { char pad[0x20]; int mode; void *cctx; void *dctx; } Pr3CompressorLzx;
int fn_8857A798(int codec, void *p, u32 flags, void **ctx);
int fn_8857A8C8(int codec, void *p, u32 flags, void **ctx);

/* mode 0: XMemCreateCompressionContext into +0x24; otherwise XMemCreateDecompressionContext into +0x28 */
int ts4_lzx_create_context_88639A78(Pr3CompressorLzx *c, int mode, u32 window)
{
    Pr3LzxParams p;
    memset(&p, 0, sizeof p);
    c->mode = mode;
    p.window = window;
    p.partition = window;
    if (mode == 0) return fn_8857A798(1, &p, 0, &c->cctx);
    return fn_8857A8C8(1, &p, 0, &c->dctx);
}

/* ---- IO requests (0x23C bytes) queued on the file-system accessor ---- */
typedef struct Pr3IoRequest {
    int status;          /* 0x000 set to 2 by the runner */
    u8 async;            /* 0x004 nonzero: do not wait for op 1 */
    int op;              /* 0x008 0 = open, 1 = fire-and-forget, 2 = query */
    char path[0x200];    /* 0x00c */
    void *result;        /* 0x20c open: stream */
    void *event;         /* 0x210 completion event of the pooled block */
    u32 f214;
    u32 arg;             /* 0x218 query argument */
    u32 f21c;
    u32 f220;
    u32 f224;
    u32 mode;            /* 0x228 open mode */
    void *fs;            /* 0x22c file system that asked */
    u32 f230;
    u8 bresult;          /* 0x234 query result */
    u32 f238;
} Pr3IoRequest;
Pr3IoRequest *fn_8860EC68(void *q, u8 async);
void fn_8862E858(void *q, Pr3IoRequest *r);
void fn_8862E638(void *q, Pr3IoRequest *r);
void ts4_get_u32_off144c_88614298(void *q);
void ts4_tailcall_fn_88582F30_8857A128(void *h, int ms);

PR3_NOINLINE void ts4_io_run_request_88630C90(void *q, Pr3IoRequest *req)
{
    Pr3IoRequest *r = fn_8860EC68(q, req->async);
    r->status = 2;
    r->fs = req->fs;
    r->bresult = req->bresult;
    r->async = req->async;
    r->op = req->op;
    r->f214 = req->f214;
    r->arg = req->arg;
    r->f220 = req->f220;
    r->f21c = req->f21c;
    r->f224 = req->f224;
    r->mode = req->mode;
    r->result = req->result;
    memcpy(r->path, req->path, 0x200);
    if (req->async == 0) {
        fn_8862E858(q, 0);
    } else {
        fn_8862E858(q, 0);
        if (r->op == 1) return;
    }
    ts4_tailcall_fn_88582F30_8857A128(r->event, -1);
    fn_8862E638(q, r);
    req->result = r->result;
    req->bresult = r->bresult;
    req->f238 = r->f238;
    ts4_get_u32_off144c_88614298(q);
    fn_8862E858(q, r);
}

/* CFileSystemPhysic open: op 0 request, returns the stream in *out */
void **ts4_io_open_request_88630F80(void **out, void *queue, void *fs, const char *path, u32 mode, u8 async)
{
    Pr3IoRequest req;
    char *d;
    req.result = 0;
    req.event = 0;
    req.f230 = 0;
    req.f238 = 0;
    req.status = 0;
    req.bresult = 0;
    req.op = 0;
    req.f214 = 0;
    req.arg = 0;
    req.f220 = 0;
    req.f224 = 0;
    d = req.path;
    while (d != req.path + 0x1fe) { if (*path == 0) break; *d++ = *path++; }
    *d = 0;
    req.fs = fs;
    req.mode = mode;
    req.async = async;
    ts4_io_run_request_88630C90(queue, &req);
    *out = req.result;
    return out;
}

/* op 2 query (synchronous), returns the byte result */
u8 ts4_io_query_request_88630EE8(void *queue, const char *path, u32 arg)
{
    Pr3IoRequest req;
    char *d;
    req.result = 0;
    req.event = 0;
    req.mode = 0;
    req.f230 = 0;
    req.f238 = 0;
    req.status = 0;
    req.async = 0;
    req.bresult = 0;
    req.fs = 0;
    req.op = 2;
    req.f214 = 0;
    req.f220 = 0;
    req.f224 = 0;
    d = req.path;
    while (d != req.path + 0x1fe) { if (*path == 0) break; *d++ = *path++; }
    *d = 0;
    req.arg = arg;
    ts4_io_run_request_88630C90(queue, &req);
    return req.bresult;
}

/* ---- CFileStreamWin32 (0x18 bytes, vtable 0x880DF3DC) ---- */
extern char lbl_880DF3DC[];
int fn_8857B848(const char *name, u32 access, u32 share, void *sa, u32 disposition, u32 attrs, void *tmpl);
typedef struct Pr3FileStreamWin32 { void *vt; void *fs; int flags; u32 f0c; u8 f10; int handle; } Pr3FileStreamWin32;

/* flags bit 1 = GENERIC_WRITE, bit 0 = GENERIC_READ; attributes 0x80 (normal); handle at +0x14 */
Pr3FileStreamWin32 *ts4_file_stream_win32_ctor_881A5508(Pr3FileStreamWin32 *s, void *fs, const char *path, int flags,
                                                        const char **prefix, u32 disposition)
{
    char buf[0x200];
    u32 access;
    s->fs = fs;
    s->flags = flags;
    s->f0c = 0;
    s->f10 = 0;
    s->handle = 0;
    s->vt = lbl_880DF3DC;
    access = 0;
    if ((flags & 2) == 2) access = 0x40000000;
    if ((flags & 1) == 1) access |= 0x80000000;
    strcpy(buf, *prefix);
    strcat(buf, path);
    s->handle = fn_8857B848(buf, access, 0, 0, disposition, 0x80, 0);
    return s;
}

/* ---- archive mount helpers ---- */
typedef struct Pr3Fs Pr3Fs;
typedef struct Pr3FsVt { void *s[17]; u8 (*exists)(Pr3Fs *, const char *); } Pr3FsVt;
struct Pr3Fs { Pr3FsVt *vt; };
typedef struct Pr3Factory Pr3Factory;
typedef struct Pr3FactoryVt { void *dtor; Pr3Fs *(*create)(Pr3Factory *); } Pr3FactoryVt;
struct Pr3Factory { Pr3FactoryVt *vt; };
typedef struct Pr3SBuf { char *p; u32 w[0x45]; } Pr3SBuf;     /* fixed-capacity string, 0x118 bytes */
typedef struct Pr3SBufS { char *p; u32 w[0x41]; } Pr3SBufS;   /* 0x108 bytes */

extern void *lbl_88D45B20;     /* class registry */
extern char lbl_880F6E80[];    /* "arc" */
extern char lbl_880F6E70[];    /* ".arc" */
extern char lbl_880F6E78[];    /* ".oarc" */
const char *fn_88214C20(const char *b, const char *e, const char *ch);
void ts4_sbuf_ctor_88180008(void *s, const char *src);
void ts4_fixed_string_append_8816CF48(void *s, const char *b, const char *e);
void ts4_byte_string_assign_8816D090(void *dst, void *src);
Pr3Factory *ts4_find_by_key_or_default_8816D220(void *reg, u32 key);

PR3_INL u8 pr3_streq(const char *a, const char *b) { return 0 == strcmp(a, b); }

/* Create the archive file system for a resolved path: an ".arc" extension (or "<path>.arc" existing) gives
 * CFileSystemPackArchive (class hash 0x9DE0A0F2), anything else CFileSystemOpenArchive (0x53780DC7, loose files). */
Pr3Fs *ts4_archive_create_for_path_88623190(const char *path, Pr3Fs *fs)
{
    char dot;
    const char *end = path + strlen(path) + 1;
    const char *p;
    u8 packed;
    dot = '.';
    p = fn_88214C20(path, end, &dot);
    if (end != p) {
        packed = pr3_streq(p + 1, lbl_880F6E80);
    } else {
        Pr3SBufS s;
        ts4_sbuf_ctor_88180008(&s, path);
        ts4_fixed_string_append_8816CF48(&s, lbl_880F6E70, lbl_880F6E70 + 4);
        packed = fs->vt->exists(fs, s.p);
    }
    {
        Pr3Factory *f;
        if (packed) { f = ts4_find_by_key_or_default_8816D220(lbl_88D45B20, 0x9DE0A0F2); if (f == 0) return 0; }
        else { f = ts4_find_by_key_or_default_8816D220(lbl_88D45B20, 0x53780DC7); if (f == 0) return 0; }
        return f->vt->create(f);
    }
}

/* Resolve an archive name to a path that exists on fs: as given when it has an extension, else "<name>.arc",
 * else "<name>.oarc". The chosen path is left in *out; returns whether it exists. */
u8 ts4_archive_resolve_path_886232C8(const char *name, Pr3Fs *fs, Pr3SBufS *out)
{
    char dot;
    const char *end = name + strlen(name) + 1;
    const char *p;
    Pr3SBuf t;
    u8 r;
    dot = '.';
    p = fn_88214C20(name, end, &dot);
    if (end != p) {
        r = fs->vt->exists(fs, name);
        ts4_sbuf_ctor_88180008(&t, name);
        ts4_byte_string_assign_8816D090(out, &t);
        return r;
    }
    ts4_sbuf_ctor_88180008(&t, name);
    ts4_byte_string_assign_8816D090(out, &t);
    ts4_fixed_string_append_8816CF48(out, lbl_880F6E70, lbl_880F6E70 + 4);
    r = fs->vt->exists(fs, out->p);
    if (!r) {
        ts4_sbuf_ctor_88180008(&t, name);
        ts4_byte_string_assign_8816D090(out, &t);
        ts4_fixed_string_append_8816CF48(out, lbl_880F6E78, lbl_880F6E78 + 5);
        r = fs->vt->exists(fs, out->p);
    }
    return r;
}
