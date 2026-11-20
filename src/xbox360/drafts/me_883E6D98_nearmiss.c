/* NEAR MISS (agAD, b169): /O1, 8 off: prev and the early stream-vtable local get r29/r28 swapped against the target. */
/* Swing_DLL.xex 0x883E6D98: opens a chunk window (state 1 -> 2): its start comes from the previous chunk's end (when that one is in
 * state 2 or 3) or from the stream position (slot 6, or slot 22 plus slot 9, then aligned through slot 21); end = start + slot 11.
 * Without a previous chunk it seeks the stream (slot 19) and optionally prefetches (slot 17). Then 883E67E0 and fn_883E5610. agAD: /O1. */
typedef unsigned __int64 u64;
typedef struct Stream { const struct StreamVt *vt; } Stream;
typedef struct StreamVt {
    void *s0[5]; unsigned char (*has_pos)(Stream *s); u64 (*pos)(Stream *s); void *s7[2]; unsigned int (*header)(Stream *s);
    void *s10; u64 (*size)(Stream *s); void *s12; unsigned char (*can_prefetch)(Stream *s); void *s14[3];
    void (*prefetch)(Stream *s, u64 at); void *s18; void (*seek)(Stream *s, u64 at, void *file, int a); void *s20;
    u64 (*align)(Stream *s, u64 at); int (*tell)(Stream *s, u64 *at);
} StreamVt;
typedef struct File { const struct FileVt *vt; } File;
typedef struct FileVt { void *s0[6]; void (*sync)(File *f); void *s7[2]; void *(*pending)(File *f); } FileVt;
typedef struct Chunk {
    char pad0[8]; Stream *stream; void *ctx; File *file; int pad14; u64 start; u64 end; u64 extra; int state;
} Chunk;
int ts4_acquire_key_ref_883E67E0(Chunk *c);
int fn_883E5610(void *ctx, u64 start, u64 end, u64 extra);

int fn_883E6D98(Chunk *c, Chunk *prev)
{
    int r;
    if (c->state != 1)
        return 0x21;
    c->state = 2;
    if (prev && prev->state != 3)
        prev = prev->state == 2 ? prev : 0;
    if (!c->file || !c->file->vt->pending(c->file)) {
        if (prev)
            c->start = prev->end;
        else {
            if (c->stream->vt->has_pos(c->stream))
                c->start = c->stream->vt->pos(c->stream);
            else {
                r = c->stream->vt->tell(c->stream, &c->start);
                if (r)
                    return r;
                c->start += c->stream->vt->header(c->stream);
            }
            c->start = c->stream->vt->align(c->stream, c->start);
        }
        {
            const StreamVt *vt = c->stream->vt;
            c->file->vt->sync(c->file);
            { u64 sz = vt->size(c->stream); c->end = c->start + sz; }
        }
    }
    if (!prev) {
        c->stream->vt->seek(c->stream, c->start, c->file, 1);
        if (c->stream->vt->can_prefetch(c->stream))
            c->stream->vt->prefetch(c->stream, c->extra + c->start);
    }
    r = ts4_acquire_key_ref_883E67E0(c);
    if (r)
        return r;
    return fn_883E5610(c->ctx, c->start, c->end, c->extra);
}
