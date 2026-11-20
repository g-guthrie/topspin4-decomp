/* Loader_DLL.xex 0x83167348-0x83167FB8, executable version 0.0.0.3.
 * zlib 1.1.x deflate helpers (deflate.c), first copy: deflateSetDictionary, deflateCopy, longest_match. */


#ifdef _MSC_VER
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
extern void *fn_833E3AD0(void *dst, const void *src, unsigned int n);

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
    struct { unsigned short *dyn_tree; void *stat_desc; int max_code; } tree_descs[3]; /* 0xb10: l_desc, d_desc, bl_desc */
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

unsigned long fn_83169DA8(unsigned long adler, const unsigned char *buf, unsigned int len);
int ts4l_zlib_deflateEnd_83167968(ts4l_z_stream *strm);

enum { ts4l_need_more, ts4l_block_done, ts4l_finish_started, ts4l_finish_done };
#define MIN_LOOKAHEAD 262
#define MAX_DIST(s) ((s)->w_size - MIN_LOOKAHEAD)

#define UPDATE_HASH(s, h, c) (h = (((h) << (s)->hash_shift) ^ (c)) & (s)->hash_mask)
#define INSERT_STRING(s, str, match_head)                                                    \
    (UPDATE_HASH(s, (s)->ins_h, (s)->window[(str) + (3 - 1)]),                               \
     (s)->prev[(str) & (s)->w_mask] = match_head = (s)->head[(s)->ins_h],                    \
     (s)->head[(s)->ins_h] = (unsigned short)(str))

/* Preloads the compression dictionary into the window; zlib deflateSetDictionary */
int ts4l_zlib_deflateSetDictionary_83167348(ts4l_z_stream *strm, const unsigned char *dictionary,
                                            unsigned int dictLength)
{
    ts4l_deflate_state *s;
    unsigned int length = dictLength;
    unsigned int n;
    unsigned int hash_head = 0;

    if (strm == 0 || strm->state == 0 || dictionary == 0 || strm->state->status != TS4L_INIT_STATE)
        return TS4L_Z_STREAM_ERROR;
    s = strm->state;
    strm->adler = fn_83169DA8(strm->adler, dictionary, dictLength);
    if (length < 3)
        return TS4L_Z_OK;
    if (length > MAX_DIST(s)) {
        length = MAX_DIST(s);
        dictionary += dictLength - length;
    }
    fn_833E3AD0(s->window, dictionary, length);
    s->strstart = length;
    s->block_start = (long)length;
    s->ins_h = s->window[0];
    UPDATE_HASH(s, s->ins_h, s->window[1]);
    for (n = 0; n <= length - 3; n++) {
        INSERT_STRING(s, n, hash_head);
    }
    if (hash_head)
        hash_head = 0;
    return TS4L_Z_OK;
}

/* Duplicates a deflate stream; zlib deflateCopy */
/* The allocator wrapper of this zlib copy refuses requests whose byte count overflows. */
#define ZALLOC_CHK(strm, items, size)                                                           \
    ((items) > (unsigned int)-1 / (size) ? 0 : (*(strm)->zalloc)((strm)->opaque, (items), (size)))

int ts4l_zlib_deflateCopy_83167A80(ts4l_z_stream *dest, ts4l_z_stream *source)
{
    ts4l_deflate_state *ds;
    ts4l_deflate_state *ss;
    unsigned short *overlay;

    if (source == 0 || dest == 0 || source->state == 0)
        return TS4L_Z_STREAM_ERROR;
    ss = source->state;
    fn_833E3AD0(dest, source, sizeof(*dest));
    ds = (ts4l_deflate_state *)ZALLOC_CHK(dest, 1, sizeof(ts4l_deflate_state));
    if (ds == 0)
        return TS4L_Z_MEM_ERROR;
    dest->state = ds;
    fn_833E3AD0(ds, ss, sizeof(*ds));
    ds->strm = dest;
    ds->window = (unsigned char *)ZALLOC_CHK(dest, ds->w_size, 2);
    ds->prev = (unsigned short *)ZALLOC_CHK(dest, ds->w_size, 2);
    ds->head = (unsigned short *)ZALLOC_CHK(dest, ds->hash_size, 2);
    overlay = (unsigned short *)ZALLOC_CHK(dest, ds->lit_bufsize, 4);
    ds->pending_buf = (unsigned char *)overlay;
    if (ds->window == 0 || ds->prev == 0 || ds->head == 0 || ds->pending_buf == 0) {
        ts4l_zlib_deflateEnd_83167968(dest);
        return TS4L_Z_MEM_ERROR;
    }
    fn_833E3AD0(ds->window, ss->window, ds->w_size * 2);
    fn_833E3AD0(ds->prev, ss->prev, ds->w_size * 2);
    fn_833E3AD0(ds->head, ss->head, ds->hash_size * 2);
    fn_833E3AD0(ds->pending_buf, ss->pending_buf, (unsigned int)ds->pending_buf_size);
    ds->pending_out = ds->pending_buf + (ss->pending_out - ss->pending_buf);
    ds->d_buf = overlay + ds->lit_bufsize / 2;
    ds->l_buf = ds->pending_buf + 3 * ds->lit_bufsize;
    ds->tree_descs[0].dyn_tree = (unsigned short *)ds->dyn_ltree;
    ds->tree_descs[1].dyn_tree = (unsigned short *)ds->dyn_dtree;
    ds->tree_descs[2].dyn_tree = (unsigned short *)ds->bl_tree;
    return TS4L_Z_OK;
}

/* Finds the longest match in the hash chain at strstart; zlib longest_match */
unsigned int ts4l_zlib_longest_match_83167DF8(ts4l_deflate_state *s, unsigned int cur_match)
{
    unsigned int chain_length = s->max_chain_length;
    register unsigned char *scan = s->window + s->strstart;
    register unsigned char *match;
    register int len;
    int best_len = s->prev_length;
    int nice_match = s->nice_match;
    unsigned int limit = s->strstart > (unsigned int)MAX_DIST(s) ? s->strstart - (unsigned int)MAX_DIST(s) : 0;
    unsigned short *prev = s->prev;
    unsigned int wmask = s->w_mask;
    register unsigned char *strend = s->window + s->strstart + 258;
    register unsigned char scan_end1 = scan[best_len - 1];
    register unsigned char scan_end = scan[best_len];

    if (chain_length == 0)
        return (unsigned int)best_len;
    if (s->prev_length >= s->good_match) {
        chain_length >>= 2;
    }
    if ((unsigned int)nice_match > s->lookahead)
        nice_match = s->lookahead;

    do {
        match = s->window + cur_match;
        if (match[best_len] != scan_end || match[best_len - 1] != scan_end1 || *match != *scan ||
            *++match != scan[1])
            continue;
        scan += 2, match++;
        do {
        } while (*++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 *++scan == *++match && *++scan == *++match && *++scan == *++match && *++scan == *++match &&
                 scan < strend);
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
