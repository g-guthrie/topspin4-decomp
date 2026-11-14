/* Loader_DLL.xex 0x83167580-0x83167590, executable version 0.0.0.3.
 * zlib deflate() (deflate.c). */


#ifdef _MSC_VER
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
    void *zalloc;                    /* 0x20 */
    void *zfree;                     /* 0x24 */
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
} ts4l_deflate_state;

typedef int (*ts4l_compress_func)(ts4l_deflate_state *s, int flush);

typedef struct ts4l_config {
    unsigned short good_length;
    unsigned short max_lazy;
    unsigned short nice_length;
    unsigned short max_chain;
    ts4l_compress_func func;
} ts4l_config;

extern const ts4l_config lbl_83005F68[10]; /* configuration_table */
extern const char *const lbl_83006B54[10]; /* z_errmsg */


void fn_831674C0(ts4l_z_stream *strm); /* flush_pending */
void ts4l_tr_align_8316B9E0(ts4l_deflate_state *s); /* _tr_align */
void fn_8316B858(ts4l_deflate_state *s, char *buf, unsigned long stored_len, int eof); /* _tr_stored_block */

#define TS4L_Z_NO_FLUSH 0
#define TS4L_Z_PARTIAL_FLUSH 1
#define TS4L_Z_FULL_FLUSH 3
#define TS4L_Z_FINISH 4
#define TS4L_Z_OK 0
#define TS4L_Z_STREAM_END 1
#define TS4L_Z_STREAM_ERROR (-2)
#define TS4L_Z_BUF_ERROR (-5)
#define TS4L_INIT_STATE 42
#define TS4L_BUSY_STATE 113
#define TS4L_FINISH_STATE 666
#define TS4L_PRESET_DICT 0x20

#define ERR_RETURN(strm, err) return (strm->msg = lbl_83006B54[2 - (err)], (err))
#define put_byte(s, c) { s->pending_buf[s->pending++] = (unsigned char)(c); }

enum { need_more, block_done, finish_started, finish_done };

/* Writes a 16-bit value MSB first into the pending buffer (inlined). */
static void putShortMSB(ts4l_deflate_state *s, unsigned int b)
{
    put_byte(s, (unsigned char)(b >> 8));
    put_byte(s, (unsigned char)(b & 0xff));
}

/* Compresses as much input as possible into the output buffer, honouring the
 * flush mode; zlib deflate() */
int ts4l_zlib_deflate_83167580(ts4l_z_stream *strm, int flush)
{
    int old_flush;
    ts4l_deflate_state *s;

    if (strm == 0 || strm->state == 0 || flush > TS4L_Z_FINISH || flush < 0) {
        return TS4L_Z_STREAM_ERROR;
    }
    s = strm->state;

    if (strm->next_out == 0 || (strm->next_in == 0 && strm->avail_in != 0) ||
        (s->status == TS4L_FINISH_STATE && flush != TS4L_Z_FINISH)) {
        ERR_RETURN(strm, TS4L_Z_STREAM_ERROR);
    }
    if (strm->avail_out == 0)
        ERR_RETURN(strm, TS4L_Z_BUF_ERROR);

    s->strm = strm;
    old_flush = s->last_flush;
    s->last_flush = flush;

    if (s->status == TS4L_INIT_STATE) {
        unsigned int header = (8 + ((s->w_bits - 8) << 4)) << 8;
        unsigned int level_flags = (s->level - 1) >> 1;

        if (level_flags > 3)
            level_flags = 3;
        header |= (level_flags << 6);
        if (s->strstart != 0)
            header |= TS4L_PRESET_DICT;
        header += 31 - (header % 31);

        s->status = TS4L_BUSY_STATE;
        putShortMSB(s, header);

        if (s->strstart != 0) {
            putShortMSB(s, (unsigned int)(strm->adler >> 16));
            putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
        }
        strm->adler = 1L;
    }

    if (s->pending != 0) {
        fn_831674C0(strm);
        if (strm->avail_out == 0) {
            s->last_flush = -1;
            return TS4L_Z_OK;
        }
    } else if (strm->avail_in == 0 && flush <= old_flush && flush != TS4L_Z_FINISH) {
        ERR_RETURN(strm, TS4L_Z_BUF_ERROR);
    }

    if (s->status == TS4L_FINISH_STATE && strm->avail_in != 0) {
        ERR_RETURN(strm, TS4L_Z_BUF_ERROR);
    }

    if (strm->avail_in != 0 || s->lookahead != 0 ||
        (flush != TS4L_Z_NO_FLUSH && s->status != TS4L_FINISH_STATE)) {
        int bstate;

        bstate = (*(lbl_83005F68[s->level].func))(s, flush);

        if (bstate == finish_started || bstate == finish_done) {
            s->status = TS4L_FINISH_STATE;
        }
        if (bstate == need_more || bstate == finish_started) {
            if (strm->avail_out == 0) {
                s->last_flush = -1;
            }
            return TS4L_Z_OK;
        }
        if (bstate == block_done) {
            if (flush == TS4L_Z_PARTIAL_FLUSH) {
                ts4l_tr_align_8316B9E0(s);
            } else {
                fn_8316B858(s, (char *)0, 0L, 0);
                if (flush == TS4L_Z_FULL_FLUSH) {
                    s->head[s->hash_size - 1] = 0;
                    memset((unsigned char *)s->head, 0, (unsigned)(s->hash_size - 1) * sizeof(*s->head));
                }
            }
            fn_831674C0(strm);
            if (strm->avail_out == 0) {
                s->last_flush = -1;
                return TS4L_Z_OK;
            }
        }
    }

    if (flush != TS4L_Z_FINISH)
        return TS4L_Z_OK;
    if (s->noheader)
        return TS4L_Z_STREAM_END;

    putShortMSB(s, (unsigned int)(strm->adler >> 16));
    putShortMSB(s, (unsigned int)(strm->adler & 0xffff));
    fn_831674C0(strm);
    s->noheader = -1;
    return s->pending != 0 ? TS4L_Z_OK : TS4L_Z_STREAM_END;
}

#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)
#define TOO_FAR 4096

#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)
#define INSERT_STRING(s, str, match_head)                                                    \
    (UPDATE_HASH(s, (s)->ins_h, (s)->window[(str) + (3 - 1)]),                               \
     (s)->prev[(str) & (s)->w_mask] = match_head = (s)->head[(s)->ins_h],                    \
     (s)->head[(s)->ins_h] = (unsigned short)(str))


#define _tr_tally_lit(s, c, flush)                          \
    {                                                       \
        unsigned char cc = (c);                             \
        (s)->d_buf[(s)->last_lit] = 0;                      \
        (s)->l_buf[(s)->last_lit++] = cc;                   \
        (s)->dyn_ltree[cc].fc++;                            \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);    \
    }

#define FLUSH_BLOCK(s, eof)                                                     \
    {                                                                           \
        FLUSH_BLOCK_ONLY(s, eof);                                               \
        if ((s)->strm->avail_out == 0)                                          \
            return (eof) ? finish_started : need_more;                          \
    }


