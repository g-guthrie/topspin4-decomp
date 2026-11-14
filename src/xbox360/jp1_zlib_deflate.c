/* Derived from zlib 1.1.x (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Second statically linked zlib copy (auto_03_882F0854): deflate helpers and stream setup,
 * state layout as in rm3_zlib_deflate.c. (JP1) */

#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
void *memset(void *destination, int value, unsigned int size);
#else
#include <string.h>
#endif

struct jp1_deflate_state;

typedef struct jp1_z_stream {
    const unsigned char *next_in;    /* 0x00 */
    unsigned int avail_in;           /* 0x04 */
    unsigned long total_in;          /* 0x08 */
    unsigned char *next_out;         /* 0x0c */
    unsigned int avail_out;          /* 0x10 */
    unsigned long total_out;         /* 0x14 */
    const char *msg;                 /* 0x18 */
    struct jp1_deflate_state *state; /* 0x1c */
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size); /* 0x20 */
    void (*zfree)(void *opaque, void *address); /* 0x24 */
    void *opaque;                    /* 0x28 */
    int data_type;                   /* 0x2c */
    unsigned long adler;             /* 0x30 */
    unsigned long reserved;          /* 0x34 */
} jp1_z_stream;

typedef struct jp1_ct_data {
    unsigned short fc; /* freq or code */
    unsigned short dl; /* dad or len */
} jp1_ct_data;

typedef struct jp1_deflate_state {
    jp1_z_stream *strm;              /* 0x00 */
    int status;                      /* 0x04 */
    unsigned char *pending_buf;      /* 0x08 */
    unsigned long pending_buf_size;  /* 0x0c */
    unsigned char *pending_out;      /* 0x10 */
    int pending;                     /* 0x14 */
    int noheader;                    /* 0x18 */
    unsigned char data_type;         /* 0x1c */
    unsigned char method;            /* 0x1d */
    int last_flush;                  /* 0x20 */
    unsigned int w_size;             /* 0x24 */
    unsigned int w_bits;             /* 0x28 */
    unsigned int w_mask;             /* 0x2c */
    unsigned char *window;           /* 0x30 */
    unsigned long window_size;       /* 0x34 */
    unsigned short *prev;            /* 0x38 */
    unsigned short *head;            /* 0x3c */
    unsigned int ins_h;              /* 0x40 */
    unsigned int hash_size;          /* 0x44 */
    unsigned int hash_bits;          /* 0x48 */
    unsigned int hash_mask;          /* 0x4c */
    unsigned int hash_shift;         /* 0x50 */
    long block_start;                /* 0x54 */
    unsigned int match_length;       /* 0x58 */
    unsigned int prev_match;         /* 0x5c */
    int match_available;             /* 0x60 */
    unsigned int strstart;           /* 0x64 */
    unsigned int match_start;        /* 0x68 */
    unsigned int lookahead;          /* 0x6c */
    unsigned int prev_length;        /* 0x70 */
    unsigned int max_chain_length;   /* 0x74 */
    unsigned int max_lazy_match;     /* 0x78 */
    int level;                       /* 0x7c */
    int strategy;                    /* 0x80 */
    unsigned int good_match;         /* 0x84 */
    int nice_match;                  /* 0x88 */
    jp1_ct_data dyn_ltree[2 * 286 + 1];  /* 0x08c */
    jp1_ct_data dyn_dtree[2 * 30 + 1];   /* 0x980 */
    jp1_ct_data bl_tree[2 * 19 + 1];     /* 0xa74 */
    unsigned char tree_descs[0x24];      /* 0xb10: l_desc, d_desc, bl_desc */
    unsigned short bl_count[16];         /* 0xb34 */
    int heap[2 * 286 + 1];               /* 0xb54 */
    int heap_len;                        /* 0x1448 */
    int heap_max;                        /* 0x144c */
    unsigned char depth[2 * 286 + 1];    /* 0x1450 */
    unsigned char *l_buf;                /* 0x1690 */
    unsigned int lit_bufsize;            /* 0x1694 */
    unsigned int last_lit;               /* 0x1698 */
    unsigned short *d_buf;               /* 0x169c */
    unsigned char tail[0x18];            /* 0x16a0: trees.c counters and bit buffer (opt_len .. bi_valid) */
} jp1_deflate_state;

typedef int (*jp1_compress_func)(jp1_deflate_state *s, int flush);

typedef struct jp1_config {
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    jp1_compress_func func;
} jp1_config;

#define JP1_Z_NO_FLUSH 0
#define JP1_Z_FINISH 4
#define JP1_Z_OK 0
#define JP1_Z_STREAM_ERROR (-2)
#define JP1_Z_DATA_ERROR (-3)
#define JP1_Z_MEM_ERROR (-4)
#define JP1_Z_VERSION_ERROR (-6)
#define JP1_INIT_STATE 42
#define JP1_BUSY_STATE 113
#define JP1_FINISH_STATE 666


extern const jp1_config lbl_88026258[10]; /* configuration_table */
extern const char *const lbl_88027644[10]; /* z_errmsg */

/* _tr_flush_block, _tr_init, adler32, zcalloc, zcfree of this zlib copy. */
void png2_zlib_tr_flush_block_88303CE0(jp1_deflate_state *s, char *buf, unsigned long stored_len, int eof);
void png2_zlib_tr_init_883034B8(jp1_deflate_state *s);
unsigned long png2_zlib_adler32_883022B0(unsigned long adler, const unsigned char *buf, unsigned int len);
void *png2_zlib_zcalloc_88304058(void *opaque, unsigned int items, unsigned int size);
void ts4_tailcall_fn_88884DE0_883040B8(void *opaque, void *address);

enum { jp1_need_more, jp1_block_done, jp1_finish_started, jp1_finish_done };
#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)

#define FLUSH_BLOCK_ONLY(s, eof)                                                                \
    {                                                                                           \
        png2_zlib_tr_flush_block_88303CE0(s, ((s)->block_start >= 0L ? (char *)&(s)->window[(unsigned)(s)->block_start] \
                                                 : (char *)0),                                  \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (eof));            \
        (s)->block_start = (s)->strstart;                                                       \
        ts4_zlib_flush_pending_882F16C8((s)->strm);                                             \
    }
#define FLUSH_BLOCK(s, eof)                                                                     \
    {                                                                                           \
        FLUSH_BLOCK_ONLY(s, eof);                                                               \
        if ((s)->strm->avail_out == 0)                                                          \
            return (eof) ? jp1_finish_started : jp1_need_more;                                  \
    }
#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)

/* Copies as much pending output as fits into the stream output buffer (Swing_DLL.xex 0x882F16C8). */
void ts4_zlib_flush_pending_882F16C8(jp1_z_stream *strm)
{
    unsigned int len = strm->state->pending;

    if (len > strm->avail_out)
        len = strm->avail_out;
    if (len == 0)
        return;
    memcpy(strm->next_out, strm->state->pending_out, len);
    strm->next_out += len;
    strm->state->pending_out += len;
    strm->avail_out -= len;
    strm->total_out += len;
    strm->state->pending -= len;
    if (strm->state->pending == 0) {
        strm->state->pending_out = strm->state->pending_buf;
    }
}

/* Frees a deflate stream's buffers and state (Swing_DLL.xex 0x882F1B70). */
int ts4_zlib_deflateEnd_882F1B70(jp1_z_stream *strm)
{
    int status;

    if (strm == 0 || strm->state == 0)
        return JP1_Z_STREAM_ERROR;
    status = strm->state->status;
    if (status != JP1_INIT_STATE && status != JP1_BUSY_STATE && status != JP1_FINISH_STATE) {
        return JP1_Z_STREAM_ERROR;
    }
    if (strm->state->pending_buf)
        (*strm->zfree)(strm->opaque, strm->state->pending_buf);
    if (strm->state->head)
        (*strm->zfree)(strm->opaque, strm->state->head);
    if (strm->state->prev)
        (*strm->zfree)(strm->opaque, strm->state->prev);
    if (strm->state->window)
        (*strm->zfree)(strm->opaque, strm->state->window);
    (*strm->zfree)(strm->opaque, strm->state);
    strm->state = 0;
    return status == JP1_BUSY_STATE ? JP1_Z_DATA_ERROR : JP1_Z_OK;
}

/* Finds the longest earlier match for the current string along the hash chain
 * (Swing_DLL.xex 0x882F1C88). */
unsigned int ts4_zlib_longest_match_882F1C88(jp1_deflate_state *s, unsigned int cur_match)
{
    unsigned int chain_length = s->max_chain_length;
    unsigned char *scan = s->window + s->strstart;
    unsigned char *match;
    int len;
    int best_len = (int)s->prev_length;
    int nice_match = s->nice_match;
    unsigned int limit = s->strstart > (unsigned int)MAX_DIST(s) ? s->strstart - (unsigned int)MAX_DIST(s) : 0;
    unsigned short *prev = s->prev;
    unsigned int wmask = s->w_mask;
    unsigned char *strend = s->window + s->strstart + 258;
    unsigned char scan_end1 = scan[best_len - 1];
    unsigned char scan_end = scan[best_len];

    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    if ((unsigned int)nice_match > s->lookahead)
        nice_match = (int)s->lookahead;
    do {
        match = s->window + cur_match;
        if (match[best_len] != scan_end || match[best_len - 1] != scan_end1 || *match != *scan ||
            *++match != scan[1])
            continue;
        scan += 2, match++;
        do {
        } while (*++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match && scan < strend);
        len = 258 - (int)(strend - scan);
        scan = strend - 258;
        if (len > best_len) {
            s->match_start = cur_match;
            best_len = len;
            if (len >= nice_match)
                break;
            scan_end1 = scan[best_len - 1];
            scan_end = scan[best_len];
        }
    } while ((cur_match = prev[cur_match & wmask]) > limit && --chain_length != 0);
    if ((unsigned int)best_len <= s->lookahead)
        return (unsigned int)best_len;
    return s->lookahead;
}

/* Refills the window from the input, sliding it when nearly full (Swing_DLL.xex 0x882F1E40). */
void ts4_zlib_fill_window_882F1E40(jp1_deflate_state *s)
{
    unsigned int n, m;
    unsigned short *p;
    unsigned int more;
    unsigned int wsize = s->w_size;

    do {
        more = (unsigned int)(s->window_size - (unsigned long)s->lookahead - (unsigned long)s->strstart);
        if (more == 0 && s->strstart == 0 && s->lookahead == 0) {
            more = wsize;
        } else if (more == (unsigned int)(-1)) {
            more--;
        } else if (s->strstart >= wsize + MAX_DIST(s)) {
            memcpy(s->window, s->window + wsize, (unsigned int)wsize);
            s->match_start -= wsize;
            s->strstart -= wsize;
            s->block_start -= (long)wsize;
            n = s->hash_size;
            p = &s->head[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : 0);
            } while (--n);
            n = wsize;
            p = &s->prev[n];
            do {
                m = *--p;
                *p = (unsigned short)(m >= wsize ? m - wsize : 0);
            } while (--n);
            more += wsize;
        }
        if (s->strm->avail_in == 0)
            return;
        {
            jp1_z_stream *strm = s->strm;
            unsigned char *buf = s->window + s->strstart + s->lookahead;
            unsigned int size = more;
            unsigned int len = strm->avail_in;

            if (len > size)
                len = size;
            if (len == 0) {
                n = 0;
            } else {
                strm->avail_in -= len;
                if (!strm->state->noheader) {
                    strm->adler = png2_zlib_adler32_883022B0(strm->adler, strm->next_in, len);
                }
                memcpy(buf, strm->next_in, len);
                strm->next_in += len;
                strm->total_in += len;
                n = len;
            }
        }
        s->lookahead += n;
        if (s->lookahead >= 3) {
            s->ins_h = s->window[s->strstart];
            UPDATE_HASH(s, s->ins_h, s->window[s->strstart + 1]);
        }
    } while (s->lookahead < MIN_LOOKAHEAD && s->strm->avail_in != 0);
}

/* Level 0 compression: copies input into stored blocks (Swing_DLL.xex 0x882F2048). */
int ts4_zlib_deflate_stored_882F2048(jp1_deflate_state *s, int flush)
{
    unsigned long max_block_size = 0xffff;
    unsigned long max_start;

    if (max_block_size > s->pending_buf_size - 5) {
        max_block_size = s->pending_buf_size - 5;
    }
    for (;;) {
        if (s->lookahead <= 1) {
            ts4_zlib_fill_window_882F1E40(s);
            if (s->lookahead == 0 && flush == JP1_Z_NO_FLUSH)
                return jp1_need_more;
            if (s->lookahead == 0)
                break;
        }
        s->strstart += s->lookahead;
        s->lookahead = 0;
        max_start = s->block_start + max_block_size;
        if (s->strstart == 0 || (unsigned long)s->strstart >= max_start) {
            s->lookahead = (unsigned int)(s->strstart - max_start);
            s->strstart = (unsigned int)max_start;
            FLUSH_BLOCK(s, 0);
        }
        if (s->strstart - (unsigned int)s->block_start >= MAX_DIST(s)) {
            FLUSH_BLOCK(s, 0);
        }
    }
    FLUSH_BLOCK(s, flush == JP1_Z_FINISH);
    return flush == JP1_Z_FINISH ? jp1_finish_done : jp1_block_done;
}

/* Resets a deflate stream to its initial state, keeping its allocations
 * (Swing_DLL.xex 0x882F2B58). */
int ts4_zlib_deflateReset_882F2B58(jp1_z_stream *strm)
{
    jp1_deflate_state *s;

    if (strm == 0 || strm->state == 0 || strm->zalloc == 0 || strm->zfree == 0)
        return JP1_Z_STREAM_ERROR;
    strm->total_in = strm->total_out = 0;
    strm->msg = 0;
    strm->data_type = 2;
    s = strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;
    if (s->noheader < 0) {
        s->noheader = 0;
    }
    s->status = s->noheader ? JP1_BUSY_STATE : JP1_INIT_STATE;
    strm->adler = 1;
    s->last_flush = JP1_Z_NO_FLUSH;
    png2_zlib_tr_init_883034B8(s);
    s->window_size = (unsigned long)2L * s->w_size;
    s->head[s->hash_size - 1] = 0;
    memset(s->head, 0, (unsigned int)(s->hash_size - 1) * sizeof(*s->head));
    s->max_lazy_match = lbl_88026258[s->level].max_lazy;
    s->good_match = lbl_88026258[s->level].good_length;
    s->nice_match = lbl_88026258[s->level].nice_length;
    s->max_chain_length = lbl_88026258[s->level].max_chain;
    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->match_length = s->prev_length = 2;
    s->match_available = 0;
    s->ins_h = 0;
    return JP1_Z_OK;
}

/* Allocates and initialises a deflate stream with explicit parameters
 * (Swing_DLL.xex 0x882F2C98). */
int ts4_zlib_deflateInit2__882F2C98(jp1_z_stream *strm, int level, int method, int windowBits,
                                    int memLevel, int strategy, const char *version,
                                    int stream_size)
{
    jp1_deflate_state *s;
    int noheader = 0;
    unsigned short *overlay;

    if (version == 0 || version[0] != '1' || stream_size != sizeof(jp1_z_stream)) {
        return JP1_Z_VERSION_ERROR;
    }
    if (strm == 0)
        return JP1_Z_STREAM_ERROR;
    strm->msg = 0;
    if (strm->zalloc == 0) {
        strm->zalloc = png2_zlib_zcalloc_88304058;
        strm->opaque = 0;
    }
    if (strm->zfree == 0)
        strm->zfree = ts4_tailcall_fn_88884DE0_883040B8;
    if (level == -1)
        level = 6;
    if (windowBits < 0) {
        noheader = 1;
        windowBits = -windowBits;
    }
    if (memLevel < 1 || memLevel > 9 || method != 8 || windowBits < 9 || windowBits > 15 ||
        level < 0 || level > 9 || strategy < 0 || strategy > 2) {
        return JP1_Z_STREAM_ERROR;
    }
    s = (jp1_deflate_state *)(*strm->zalloc)(strm->opaque, 1, sizeof(jp1_deflate_state));
    if (s == 0)
        return JP1_Z_MEM_ERROR;
    s->status = JP1_INIT_STATE;
    strm->state = s;
    s->strm = strm;
    s->noheader = noheader;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;
    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = ((s->hash_bits + 3 - 1) / 3);
    s->window = (unsigned char *)(*strm->zalloc)(strm->opaque, s->w_size, 2);
    s->prev = (unsigned short *)(*strm->zalloc)(strm->opaque, s->w_size, 2);
    s->head = (unsigned short *)(*strm->zalloc)(strm->opaque, s->hash_size, 2);
    s->lit_bufsize = 1 << (memLevel + 6);
    overlay = (unsigned short *)(*strm->zalloc)(strm->opaque, s->lit_bufsize, 4);
    s->pending_buf = (unsigned char *)overlay;
    s->pending_buf_size = (unsigned long)s->lit_bufsize * 4L;
    if (s->window == 0 || s->prev == 0 || s->head == 0 || s->pending_buf == 0) {
        strm->msg = (char *)lbl_88027644[2 - JP1_Z_MEM_ERROR];
        ts4_zlib_deflateEnd_882F1B70(strm);
        return JP1_Z_MEM_ERROR;
    }
    s->d_buf = overlay + s->lit_bufsize / sizeof(unsigned short);
    s->l_buf = s->pending_buf + (1 + sizeof(unsigned short)) * s->lit_bufsize;
    s->level = level;
    s->strategy = strategy;
    s->method = (unsigned char)method;
    return ts4_zlib_deflateReset_882F2B58(strm);
}
