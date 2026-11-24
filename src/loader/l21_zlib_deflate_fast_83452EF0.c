/* Loader_DLL.xex 0x83452EF0-0x83452F00, executable version 0.0.0.3.
 * zlib deflate_fast() (deflate.c). */


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


extern const unsigned char lbl_8307BA70[512]; /* _dist_code */
extern const unsigned char lbl_8307BC70[256]; /* _length_code */

void fn_83452070(ts4l_z_stream *strm); /* flush_pending */
void fn_83452B18(ts4l_deflate_state *s); /* fill_window */
unsigned int fn_83452960(ts4l_deflate_state *s, unsigned int cur_match); /* longest_match */
void fn_83465708(ts4l_deflate_state *s, char *buf, unsigned long stored_len, int eof); /* _tr_flush_block */

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

#define put_byte(s, c) { s->pending_buf[s->pending++] = (unsigned char)(c); }

enum { need_more, block_done, finish_started, finish_done };



#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)
#define TOO_FAR 4096

#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)
#define INSERT_STRING(s, str, match_head)                                                    \
    (UPDATE_HASH(s, (s)->ins_h, (s)->window[(str) + (3 - 1)]),                               \
     (s)->prev[(str) & (s)->w_mask] = match_head = (s)->head[(s)->ins_h],                    \
     (s)->head[(s)->ins_h] = (unsigned short)(str))

#define d_code(dist) ((unsigned char)((dist) < 256 ? lbl_8307BA70[dist] : lbl_8307BA70[256 + ((dist) >> 7)]))

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
        (s)->dyn_ltree[lbl_8307BC70[len] + 256 + 1].fc++;                                   \
        (s)->dyn_dtree[d_code(dist)].fc++;                                                  \
        flush = ((s)->last_lit == (s)->lit_bufsize - 1);                                    \
    }

#define FLUSH_BLOCK_ONLY(s, eof)                                                                \
    {                                                                                           \
        fn_83465708((s), ((s)->block_start >= 0L ? (char *)&(s)->window[(unsigned)(s)->block_start] \
                                                 : (char *)0),                                  \
                    (unsigned long)((long)(s)->strstart - (s)->block_start), (eof));            \
        (s)->block_start = (s)->strstart;                                                       \
        fn_83452070((s)->strm);                                                                 \
    }
#define FLUSH_BLOCK(s, eof)                                                     \
    {                                                                           \
        FLUSH_BLOCK_ONLY(s, eof);                                               \
        if ((s)->strm->avail_out == 0)                                          \
            return (eof) ? finish_started : need_more;                          \
    }

/* Greedy compression without lazy matching, used for the fast levels; zlib
 * deflate_fast() */
int ts4l_zlib_deflate_fast_83452EF0(ts4l_deflate_state *s, int flush)
{
    unsigned int hash_head = 0;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            fn_83452B18(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == TS4L_Z_NO_FLUSH) {
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
                s->match_length = fn_83452960(s, hash_head);
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
    FLUSH_BLOCK(s, flush == TS4L_Z_FINISH);
    return flush == TS4L_Z_FINISH ? finish_done : block_done;
}

