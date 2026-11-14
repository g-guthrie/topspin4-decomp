/*
 * GP7 draft: AOD ("animation on demand") clip streaming of the swing animation engine.
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Not compiled into the matching build. Offsets are read from machine code; `/ * ? * /` marks guesses.
 *
 * Covers: fn_886CE170 (enqueue), fn_886CE5B0 (request by clip), fn_886CE2D8 / fn_886D2B58 (start the next
 * file read, single / loop form), fn_886D2E78 (per-frame tick), fn_886CE648 (finish a read),
 * fn_886C52F0 (cancel), fn_886C3D50 / ts4_find_by_id_886C3DC0 / fn_886C3DA8 (queries), fn_886D7970 / fn_886D79D8 /
 * fn_886D7A60 (blocking waits), fn_886472C0 (hkx packfile -> animation object).
 *
 * What it does: clips live in one file each, "Media\Animation\AOD\%u.hkx" (%u = clip id, the u32 at +0 of
 * the clip object, same id as the +0x84 field of the AnimationRecord in Animations.bin). Requests are queued in a
 * small manager; one file read is in flight at a time into a single staging buffer (default 0xD2000 bytes,
 * asked from the engine service at lbl_88D45B1C+0x2a4); on completion the Havok packfile in the buffer is
 * parsed (fn_886472C0) and the resulting animation object is stored in the clip (clip+0xc).
 * Nothing here depends on the ball or on swings: it only decides *when the clip data is resident*.
 */

typedef unsigned char u8;
typedef unsigned int u32;

/* Request states (AodRequest.state). 0..2 = still pending, 3 = loaded, 6 = to be removed. */
enum {
    AOD_QUEUED    = 0, /* waiting for the manager to open the file */
    AOD_READING   = 1, /* async read issued (this == manager->current) */
    AOD_READ_DONE = 2, /* read finished, needs fn_886CE648 */
    AOD_LOADED    = 3, /* hkx parsed, clip+0xc valid (also set immediately when the clip already had data) */
    AOD_CANCEL_A  = 4, /* cancel requested while queued */
    AOD_CANCEL_B  = 5, /* cancel while reading -> fn_886C52F0 */
    AOD_REMOVE    = 6  /* closed; tick removes it from the vector and recycles the object */
};

struct AodClip {            /* clip object, key of a request */
    u32   id;               /* +0x00 -> "%u.hkx" */
    int   requested;        /* +0x04 set to 1 when a request exists (fn_886CE170 sets clip+4 = 1) */
    void *stream;           /* +0x08 memory stream object created by fn_886472C0 */
    void *animation;        /* +0x0c loaded Havok animation (0 until loaded) */
};

struct AodRequest {         /* 0x20+ bytes, recycled through manager->free_list */
    int            state;        /* +0x00 AOD_* */
    struct AodClip *clip;        /* +0x04 */
    u8            *done_flag;    /* +0x08 caller byte, set to 1 when finished (or on failure) */
    int            arg_c;        /* +0x0c from the caller (fn_886CE170 r5) */
    int            arg_10;       /* +0x10 from the caller (r6) */
    void          *file;         /* +0x14 file object from the engine file system (g_engine+0x224, vtbl+0x28 = open) */
    int            file_size;    /* +0x18 file->vtbl[+0x14]() */
    u8             read_done;    /* +0x1c set by the async completion */
    u8             priority;     /* +0x1d 1 = stream (async, 0x8001 open flags), 0 = synchronous */
};

struct AodManager {
    unsigned char pad00[4];
    struct AodRequest **begin;   /* +0x04 active request vector */
    struct AodRequest **end;     /* +0x08 */
    unsigned char pad0c[4];
    struct AodRequest **free_begin; /* +0x10 vector header of recycled requests (+0x14 end, +0x18 cap) */
    struct AodRequest **free_end;   /* +0x14 */
    struct AodRequest **free_cap;   /* +0x18 */
    unsigned char pad1c[0x28 - 0x1c];
    struct AodRequest *current;  /* +0x28 request whose read is in flight (0 = idle) */
    u8   reading_a;              /* +0x2c set to 1 when a read starts */
    u8   reading_b;              /* +0x2d */
    unsigned char pad2e[2];
    int  bytes_read;             /* +0x30 reset to 0 when a read starts */
    int  buffer_size;            /* +0x34 staging buffer size (service vtbl+0x38(0xD2000)) */
    void *buffer;                /* +0x38 staging buffer (fn_88613268(heap, size, align...)), allocated lazily */
    unsigned char pad3c[4];
    int  needed_size;            /* +0x40 buffer size the current file needs */
    u8   streaming;              /* +0x44 1 = async streaming mode */
};

/* ---- fn_886D2B58: start the next read (loop form; fn_886CE2D8 is the same body for ONE request and has no caller) ---- */
void aod_start_next_886D2B58(struct AodManager *m)
{
    struct AodRequest **it;

    if (m->current != 0 || m->begin == m->end) {
        return;
    }
    for (it = m->begin; it != m->end; ++it) {
        struct AodRequest *r = *it;
        char path[0x100];
        int stream;

        if (r->state != AOD_QUEUED) {
            continue;
        }
        /* ts4_format_text(path, 0x100, "Media\\Animation\\AOD\\%u.hkx", r->clip->id) */
        stream = m->streaming && r->priority;
        if (r->file == 0) {
            /* open: engine.file_system->open(path, flags = stream ? 0x8001 : 1, async = stream) */
            r->file = 0 /* g_engine+0x224 ->vtbl[+0x28](...) */;
        }
        if (r->file == 0) {
            /* open failed: only the caller's done flag is raised (request stays state 0), keep scanning */
            if (r->done_flag) *r->done_flag = 1;
            continue;
        }
        r->file_size = 0 /* file->vtbl[+0x14]() */;
        if (stream) {
            /* first use: buffer_size = service->vtbl[+0x38](0xD2000), buffer = heap alloc */
            m->current = r;
            m->reading_a = 1;
            m->reading_b = 1;
            m->bytes_read = 0;
            r->state = AOD_READING;
            m->needed_size = 0 /* service->vtbl[+0x38](r->file_size) */;
            if (m->buffer_size < m->needed_size) {
                /* does not fit in the staging buffer: fn_886C52F0 (cancel) */
                return;
            }
            /* file->vtbl: seek(0,2); r->read_done = 0; async read of needed_size bytes, tag 0x2800,
             * callback fn_886C3DA8 (returns r->state == 1 => "still wanted"), completion byte = &r->read_done */
            return;
        }
        /* synchronous: (debug log through fn_88618B68), fn_886472C0(file, r->clip) parses the packfile,
         * state = AOD_LOADED, *done_flag = 1 -- then keep scanning: only an async start leaves the loop */
    }
}

/* ---- fn_886D2E78: per-frame manager tick ---- */
void aod_tick_886D2E78(struct AodManager *m)
{
    struct AodRequest **it = m->begin;
    while (it != m->end) {
        struct AodRequest *r = *it;
        if (r->state == AOD_REMOVE) {
            /* erase from the vector (move last element into this slot), push r on the free list */
            continue;
        }
        if (r->read_done) {
            if (r->state == AOD_READING)  r->state = AOD_READ_DONE;
            if (r->state == AOD_CANCEL_A) r->state = AOD_CANCEL_B;
        }
        if (r->state == AOD_READ_DONE) {
            /* fn_886CE648: state = LOADED; close the file; fn_886472C0(buffer, clip) builds the hkaAnimation;
             * *done_flag = 1; if (m->current == r) m->current = 0 */
        } else if (r->state == AOD_CANCEL_B) {
            /* fn_886C52F0: state = REMOVE; close the file; *done_flag = 0; if (m->current == r) m->current = 0 */
        }
        ++it;
    }
    aod_start_next_886D2B58(m);
}

/* ---- blocking helpers (poll the tick, Sleep(1) between polls, at most 1000 iterations) ---- */
/* fn_886D7970: wait until no request is in state 0/1/2 (fn_886C3D50 == 1 means "all settled"). */
/* fn_886D79D8: wait until the request for `clip` (ts4_find_by_id_886C3DC0: lookup by clip pointer at request+4) leaves states 0/1/2. */
/* fn_886D7A60: wait until the request for `clip` leaves state 4. */

/* ---- fn_886CE170: enqueue (clip, arg_c, arg_10, done_flag) ----
 * Reuses an existing request for the same clip, otherwise pops one from the free list (or allocates), links it into
 * the vector, sets request->clip, arg_c, arg_10, priority = 1; state = (clip->animation != 0) ? AOD_LOADED : AOD_QUEUED
 * and clip->requested = 1; request->done_flag = done_flag.
 * fn_886CE5B0(manager, key_struct) first looks the clip up in a cache (fn_886C8438 / fn_886C5230):
 *   entry found, entry->+4 (use count) == 0 -> fn_886CE170 (enqueue);   found, count != 0 -> ++count only;
 *   not found -> *done_flag = 1 (nothing to load).
 */
