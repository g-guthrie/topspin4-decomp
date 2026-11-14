/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex.
 * Second zlib copy in Swing_DLL.xex (auto_03_882F0854), an older 1.2.x deflate with
 * the `noheader` flag instead of gzip support, so its state layout differs from ex3_zlib.h. (RM3) */

#ifdef _MSC_VER
void *memset(void *destination, int value, unsigned int size);
#else
#include <string.h>
#endif

struct rm3_deflate_state;

typedef struct rm3_z_stream {
    const unsigned char *next_in;    /* 0x00 */
    unsigned int avail_in;           /* 0x04 */
    unsigned long total_in;          /* 0x08 */
    unsigned char *next_out;         /* 0x0c */
    unsigned int avail_out;          /* 0x10 */
    unsigned long total_out;         /* 0x14 */
    const char *msg;                 /* 0x18 */
    struct rm3_deflate_state *state; /* 0x1c */
    void *zalloc;                    /* 0x20 */
    void *zfree;                     /* 0x24 */
    void *opaque;                    /* 0x28 */
    int data_type;                   /* 0x2c */
    unsigned long adler;             /* 0x30 */
    unsigned long reserved;          /* 0x34 */
} rm3_z_stream;

typedef struct rm3_ct_data {
    unsigned short fc; /* freq or code */
    unsigned short dl; /* dad or len */
} rm3_ct_data;

typedef struct rm3_deflate_state {
    rm3_z_stream *strm;              /* 0x00 */
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
    rm3_ct_data dyn_ltree[2 * 286 + 1];  /* 0x08c */
    rm3_ct_data dyn_dtree[2 * 30 + 1];   /* 0x980 */
    rm3_ct_data bl_tree[2 * 19 + 1];     /* 0xa74 */
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
} rm3_deflate_state;

typedef int (*rm3_compress_func)(rm3_deflate_state *s, int flush);

typedef struct rm3_config {
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    rm3_compress_func func;
} rm3_config;

extern const rm3_config lbl_88026258[10]; /* configuration_table */
extern const char *const lbl_88027644[10]; /* z_errmsg */

extern const unsigned char lbl_88027218[512]; /* _dist_code */
extern const unsigned char lbl_88027418[256]; /* _length_code */

void ts4_zlib_flush_pending_882F16C8(rm3_z_stream *strm); /* flush_pending */
void ts4_zlib_fill_window_882F1E40(rm3_deflate_state *s); /* fill_window */
unsigned int ts4_zlib_longest_match_882F1C88(rm3_deflate_state *s, unsigned int cur_match); /* longest_match */
void fn_88303CE0(rm3_deflate_state *s, char *buf, unsigned long stored_len, int eof); /* _tr_flush_block */
void fn_883039B0(rm3_deflate_state *s); /* _tr_align */
void fn_88303828(rm3_deflate_state *s, char *buf, unsigned long stored_len, int eof); /* _tr_stored_block */

#define RM3_Z_NO_FLUSH 0
#define RM3_Z_PARTIAL_FLUSH 1
#define RM3_Z_FULL_FLUSH 3
#define RM3_Z_FINISH 4
#define RM3_Z_OK 0
#define RM3_Z_STREAM_END 1
#define RM3_Z_STREAM_ERROR (-2)
#define RM3_Z_BUF_ERROR (-5)
#define RM3_INIT_STATE 42
#define RM3_BUSY_STATE 113
#define RM3_FINISH_STATE 666
#define RM3_PRESET_DICT 0x20

#define ERR_RETURN(strm, err) return (strm->msg = lbl_88027644[2 - (err)], (err))
#define put_byte(s, c) { s->pending_buf[s->pending++] = (unsigned char)(c); }

enum { need_more, block_done, finish_started, finish_done };

/* Writes a 16-bit value MSB first into the pending buffer (inlined). */
static void putShortMSB(rm3_deflate_state *s, unsigned int b)
{
    put_byte(s, (unsigned char)(b >> 8));
    put_byte(s, (unsigned char)(b & 0xff));
}

/* Compresses as much input as possible into the output buffer, honouring the
 * flush mode; zlib deflate() (Swing_DLL.xex 0x882F1788). */
int ts4_zlib_deflate_882F1788(rm3_z_stream *strm, int flush)
{
    int old_flush;
    rm3_deflate_state *s;

    if (strm == 0 || strm->state == 0 || flush > RM3_Z_FINISH || flush < 0) {
        return RM3_Z_STREAM_ERROR;
    }
    s = strm->state;

    if (strm->next_out == 0 || (strm->next_in == 0 && strm->avail_in != 0) ||
        (s->status == RM3_FINISH_STATE && flush != RM3_Z_FINISH)) {
        ERR_RETURN(strm, RM3_Z_STREAM_ERROR);
    }
    if (strm->avail_out == 0)
        ERR_RETURN(strm, RM3_Z_BUF_ERROR);

    s->strm = strm;
    old_flush = s->last_flush;
    s->last_flush = flush;

    if (s->status == RM3_INIT_STATE) {
        unsigned int header = (8 + ((s->w_bits - 8) << 4)) << 8;
        unsigned int level_flags = (s->level - 1) >> 1;

        if (level_flags > 3)
            level_flags = 3;
        header |= (level_flags << 6);
        if (s->strstart != 0)
            header |= RM3_PRESET_DICT;
        header += 31 - (header % 31);

        s->status = RM3_BUSY_STATE;
        putShortMSB(s, header);

        if (s->strstart != 0) {
            putShortMSB(s, (unsigned int)(strm->adler >> 16));
            putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
        }
        strm->adler = 1L;
    }

    if (s->pending != 0) {
        ts4_zlib_flush_pending_882F16C8(strm);
        if (strm->avail_out == 0) {
            s->last_flush = -1;
            return RM3_Z_OK;
        }
    } else if (strm->avail_in == 0 && flush <= old_flush && flush != RM3_Z_FINISH) {
        ERR_RETURN(strm, RM3_Z_BUF_ERROR);
    }

    if (s->status == RM3_FINISH_STATE && strm->avail_in != 0) {
        ERR_RETURN(strm, RM3_Z_BUF_ERROR);
    }

    if (strm->avail_in != 0 || s->lookahead != 0 ||
        (flush != RM3_Z_NO_FLUSH && s->status != RM3_FINISH_STATE)) {
        int bstate;

        bstate = (*(lbl_88026258[s->level].func))(s, flush);

        if (bstate == finish_started || bstate == finish_done) {
            s->status = RM3_FINISH_STATE;
        }
        if (bstate == need_more || bstate == finish_started) {
            if (strm->avail_out == 0) {
                s->last_flush = -1;
            }
            return RM3_Z_OK;
        }
        if (bstate == block_done) {
            if (flush == RM3_Z_PARTIAL_FLUSH) {
                fn_883039B0(s);
            } else {
                fn_88303828(s, (char *)0, 0L, 0);
                if (flush == RM3_Z_FULL_FLUSH) {
                    s->head[s->hash_size - 1] = 0;
                    memset((unsigned char *)s->head, 0, (unsigned)(s->hash_size - 1) * sizeof(*s->head));
                }
            }
            ts4_zlib_flush_pending_882F16C8(strm);
            if (strm->avail_out == 0) {
                s->last_flush = -1;
                return RM3_Z_OK;
            }
        }
    }

    if (flush != RM3_Z_FINISH)
        return RM3_Z_OK;
    if (s->noheader)
        return RM3_Z_STREAM_END;

    putShortMSB(s, (unsigned int)(strm->adler >> 16));
    putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
    ts4_zlib_flush_pending_882F16C8(strm);
    s->noheader = -1;
    return s->pending != 0 ? RM3_Z_OK : RM3_Z_STREAM_END;
}

#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)
#define TOO_FAR 4096

#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)
#define INSERT_STRING(s, str, match_head)                                                    \
    (UPDATE_HASH(s, (s)->ins_h, (s)->window[(str) + (3 - 1)]),                               \
     (s)->prev[(str) & (s)->w_mask] = match_head = (s)->head[(s)->ins_h],                    \
     (s)->head[(s)->ins_h] = (unsigned short)(str))

#define d_code(dist) ((unsigned char)((dist) < 256 ? lbl_88027218[dist] : lbl_88027218[256 + ((dist) >> 7)]))

#define _tr_tally_lit(s, c, flush)                          \
    {                                                       \
        unsigned char cc = (c);                             \
        (s)->d_buf[(s)->last_lit] = 0;                      \
        (s)->l_buf[(s)->last_lit++] = cc;                   \
        (s)->dyn_ltree[cc].fc++;                            \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);    \
    }
#define _tr_tally_dist(s, distance, length, flush)                                          \
    {                                                                                       \
        unsigned char len = (unsigned char)(length);                                        \
        unsigned short dist = (unsigned short)(distance);                                   \
        (s)->d_buf[(s)->last_lit] = dist;                                                   \
        (s)->l_buf[(s)->last_lit++] = len;                                                  \
        dist--;                                                                             \
        (s)->dyn_ltree[lbl_88027418[len] + 256 + 1].fc++;                                   \
        (s)->dyn_dtree[d_code(dist)].fc++;                                                  \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);                                    \
    }

#define FLUSH_BLOCK_ONLY(s, eof)                                                                \
    {                                                                                           \
        fn_88303CE0((s), ((s)->block_start >= 0L ? (char *)&(s)->window[(unsigned)(s)->block_start] \
                                                 : (char *)0),                                  \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (eof));            \
        (s)->block_start = (s)->strstart;                                                       \
        ts4_zlib_flush_pending_882F16C8((s)->strm);                                                                 \
    }
#define FLUSH_BLOCK(s, eof)                                                     \
    {                                                                           \
        FLUSH_BLOCK_ONLY(s, eof);                                               \
        if ((s)->strm->avail_out == 0)                                          \
            return (eof) ? finish_started : need_more;                          \
    }

/* Greedy compression without lazy matching, used for the fast levels; zlib
 * deflate_fast() (Swing_DLL.xex 0x882F2218). */
int ts4_zlib_deflate_fast_882F2218(rm3_deflate_state *s, int flush)
{
    unsigned int hash_head = 0;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            ts4_zlib_fill_window_882F1E40(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == RM3_Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0)
                break;
        }

        if (s->lookahead >= 3) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        if (hash_head != 0 && s->strstart - hash_head <= MAX_DIST(s)) {
            if (s->strategy != 2) {
                s->match_length = ts4_zlib_longest_match_882F1C88(s, hash_head);
            }
        }
        if (s->match_length >= 3) {
            _tr_tally_dist(s, s->strstart - s->match_start, s->match_length - 3, bflush);

            s->lookahead -= s->match_length;

            if (s->match_length <= s->max_lazy_match && s->lookahead >= 3) {
                s->match_length--;
                do {
                    s->strstart++;
                    INSERT_STRING(s, s->strstart, hash_head);
                } while (--s->match_length != 0);
                s->strstart++;
            } else {
                s->strstart += s->match_length;
                s->match_length = 0;
                s->ins_h = s->window[s->strstart];
                UPDATE_HASH(s, s->ins_h, s->window[s->strstart + 1]);
            }
        } else {
            _tr_tally_lit(s, s->window[s->strstart], bflush);
            s->lookahead--;
            s->strstart++;
        }
        if (bflush)
            FLUSH_BLOCK(s, 0);
    }
    FLUSH_BLOCK(s, flush == RM3_Z_FINISH);
    return flush == RM3_Z_FINISH ? finish_done : block_done;
}

/* Lazy-match compression used for the higher levels; zlib deflate_slow()
 * (Swing_DLL.xex 0x882F2630). */
int ts4_zlib_deflate_slow_882F2630(rm3_deflate_state *s, int flush)
{
    unsigned int hash_head = 0;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            ts4_zlib_fill_window_882F1E40(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == RM3_Z_NO_FLUSH) {
                return need_more;
            }
            if (s->lookahead == 0)
                break;
        }

        if (s->lookahead >= 3) {
            INSERT_STRING(s, s->strstart, hash_head);
        }

        s->prev_length = s->match_length, s->prev_match = s->match_start;
        s->match_length = 3 - 1;

        if (hash_head != 0 && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= MAX_DIST(s)) {
            if (s->strategy != 2) {
                s->match_length = ts4_zlib_longest_match_882F1C88(s, hash_head);
            }
            if (s->match_length <= 5 &&
                (s->strategy == 1 || (s->match_length == 3 && s->strstart - s->match_start > TOO_FAR))) {
                s->match_length = 3 - 1;
            }
        }
        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            unsigned int max_insert = s->strstart + s->lookahead - 3;

            _tr_tally_dist(s, s->strstart - 1 - s->prev_match, s->prev_length - 3, bflush);

            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 3 - 1;
            s->strstart++;

            if (bflush)
                FLUSH_BLOCK(s, 0);

        } else if (s->match_available) {
            _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0)
                return need_more;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        _tr_tally_lit(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    FLUSH_BLOCK(s, flush == RM3_Z_FINISH);
    return flush == RM3_Z_FINISH ? finish_done : block_done;
}
