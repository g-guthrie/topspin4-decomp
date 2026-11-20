/* Loader_DLL.xex 0x831674C0-0x83168CE0, executable version 0.0.0.3.
 * zlib 1.1.x deflate helpers (deflate.c). */


#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
void *memset(void *destination, int value, unsigned int size);
#else
#include <string.h>
#endif

struct ts4l_deflate_state;

typedef struct ts4l_z_stream {
    const unsigned char *next_in;    /* 0x00 */
    unsigned int avail_in;           /* 0x04 */
    unsigned long total_in;          /* 0x08 */
    unsigned char *next_out;         /* 0x0c */
    unsigned int avail_out;          /* 0x10 */
    unsigned long total_out;         /* 0x14 */
    const char *msg;                 /* 0x18 */
    struct ts4l_deflate_state *state; /* 0x1c */
    void *(*zalloc)(void *opaque, unsigned int items, unsigned int size); /* 0x20 */
    void (*zfree)(void *opaque, void *address); /* 0x24 */
    void *opaque;                    /* 0x28 */
    int data_type;                   /* 0x2c */
    unsigned long adler;             /* 0x30 */
    unsigned long reserved;          /* 0x34 */
} ts4l_z_stream;

typedef struct ts4l_ct_data {
    unsigned short fc; /* freq or code */
    unsigned short dl; /* dad or len */
} ts4l_ct_data;

typedef struct ts4l_deflate_state {
    ts4l_z_stream *strm;              /* 0x00 */
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
    ts4l_ct_data dyn_ltree[2 * 286 + 1];  /* 0x08c */
    ts4l_ct_data dyn_dtree[2 * 30 + 1];   /* 0x980 */
    ts4l_ct_data bl_tree[2 * 19 + 1];     /* 0xa74 */
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
} ts4l_deflate_state;

typedef int (*ts4l_compress_func)(ts4l_deflate_state *s, int flush);

typedef struct ts4l_config {
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    ts4l_compress_func func;
} ts4l_config;

#define TS4L_Z_NO_FLUSH 0
#define TS4L_Z_FINISH 4
#define TS4L_Z_OK 0
#define TS4L_Z_STREAM_ERROR (-2)
#define TS4L_Z_DATA_ERROR (-3)
#define TS4L_Z_MEM_ERROR (-4)
#define TS4L_Z_VERSION_ERROR (-6)
#define TS4L_INIT_STATE 42
#define TS4L_BUSY_STATE 113
#define TS4L_FINISH_STATE 666


extern const ts4l_config lbl_83005F68[10]; /* configuration_table */

/* _tr_flush_block, _tr_init, adler32, zcalloc, zcfree of this zlib copy. */
void fn_8316BD10(ts4l_deflate_state *s, char *buf, unsigned long stored_len, int eof);
void fn_8316B370(ts4l_deflate_state *s);
unsigned long fn_83169DA8(unsigned long adler, const unsigned char *buf, unsigned int len);

enum { ts4l_need_more, ts4l_block_done, ts4l_finish_started, ts4l_finish_done };
#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)

#define FLUSH_BLOCK_ONLY(s, eof)                                                                \
    {                                                                                           \
        fn_8316BD10(s, ((s)->block_start >= 0L ? (char *)&(s)->window[(unsigned)(s)->block_start] \
                                                 : (char *)0),                                  \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (eof));            \
        (s)->block_start = (s)->strstart;                                                       \
        ts4l_zlib_flush_pending_831674C0((s)->strm);                                             \
    }
#define FLUSH_BLOCK(s, eof)                                                                     \
    {                                                                                           \
        FLUSH_BLOCK_ONLY(s, eof);                                                               \
        if ((s)->strm->avail_out == 0)                                                          \
            return (eof) ? ts4l_finish_started : ts4l_need_more;                                  \
    }
#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)

/* Copies as much pending output as fits into the stream output buffer */
void ts4l_zlib_flush_pending_831674C0(ts4l_z_stream *strm)
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

/* Frees a deflate stream's buffers and state */
int ts4l_zlib_deflateEnd_83167968(ts4l_z_stream *strm)
{
    int status;

    if (strm == 0 || strm->state == 0)
        return TS4L_Z_STREAM_ERROR;
    status = strm->state->status;
    if (status != TS4L_INIT_STATE && status != TS4L_BUSY_STATE && status != TS4L_FINISH_STATE) {
        return TS4L_Z_STREAM_ERROR;
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
    return status == TS4L_BUSY_STATE ? TS4L_Z_DATA_ERROR : TS4L_Z_OK;
}


/* Refills the window from the input, sliding it when nearly full */
void ts4l_zlib_fill_window_83167FB8(ts4l_deflate_state *s)
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
            ts4l_z_stream *strm = s->strm;
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
                    strm->adler = fn_83169DA8(strm->adler, strm->next_in, len);
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

/* Level 0 compression: copies input into stored blocks */
int ts4l_zlib_deflate_stored_831681C0(ts4l_deflate_state *s, int flush)
{
    unsigned long max_block_size = 0xffff;
    unsigned long max_start;

    if (max_block_size > s->pending_buf_size - 5) {
        max_block_size = s->pending_buf_size - 5;
    }
    for (;;) {
        if (s->lookahead <= 1) {
            ts4l_zlib_fill_window_83167FB8(s);
            if (s->lookahead == 0 && flush == TS4L_Z_NO_FLUSH)
                return ts4l_need_more;
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
    FLUSH_BLOCK(s, flush == TS4L_Z_FINISH);
    return flush == TS4L_Z_FINISH ? ts4l_finish_done : ts4l_block_done;
}

/* Resets a deflate stream to its initial state, keeping its allocations
 * */
int ts4l_zlib_deflateReset_83168CD0(ts4l_z_stream *strm)
{
    ts4l_deflate_state *s;

    if (strm == 0 || strm->state == 0 || strm->zalloc == 0 || strm->zfree == 0)
        return TS4L_Z_STREAM_ERROR;
    strm->total_in = strm->total_out = 0;
    strm->msg = 0;
    strm->data_type = 2;
    s = strm->state;
    s->pending = 0;
    s->pending_out = s->pending_buf;
    if (s->noheader < 0) {
        s->noheader = 0;
    }
    s->status = s->noheader ? TS4L_BUSY_STATE : TS4L_INIT_STATE;
    strm->adler = 1;
    s->last_flush = TS4L_Z_NO_FLUSH;
    fn_8316B370(s);
    s->window_size = (unsigned long)2L * s->w_size;
    s->head[s->hash_size - 1] = 0;
    memset(s->head, 0, (unsigned int)(s->hash_size - 1) * sizeof(*s->head));
    s->max_lazy_match = lbl_83005F68[s->level].max_lazy;
    s->good_match = lbl_83005F68[s->level].good_length;
    s->nice_match = lbl_83005F68[s->level].nice_length;
    s->max_chain_length = lbl_83005F68[s->level].max_chain;
    s->strstart = 0;
    s->block_start = 0L;
    s->lookahead = 0;
    s->match_length = s->prev_length = 2;
    s->match_available = 0;
    s->ins_h = 0;
    return TS4L_Z_OK;
}

