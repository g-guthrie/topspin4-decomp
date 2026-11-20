/* Loader_DLL.xex 0x83167D30-0x8316B854, executable version 0.0.0.3.
 * zlib 1.1.x deflate: scan_tree, build_bl_tree, lm_init. */
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;

typedef struct { ush fc; ush dl; } Ts4lCtData;

typedef struct {
    Ts4lCtData *dyn_tree;
    int max_code;
    const void *stat_desc;
} Ts4lTreeDesc;

typedef struct {
    void *strm;                     /* 0x00 */
    int status;                     /* 0x04 */
    uch *pending_buf;               /* 0x08 */
    ulg pending_buf_size;           /* 0x0c */
    uch *pending_out;               /* 0x10 */
    unsigned pending;               /* 0x14 */
    int noheader;                   /* 0x18 */
    uch data_type;                  /* 0x1c */
    uch method;                     /* 0x1d */
    int last_flush;                 /* 0x20 */
    unsigned w_size, w_bits, w_mask; /* 0x24 */
    uch *window;                    /* 0x30 */
    ulg window_size;                /* 0x34 */
    ush *prev;                      /* 0x38 */
    ush *head;                      /* 0x3c */
    unsigned ins_h, hash_size, hash_bits, hash_mask, hash_shift; /* 0x40 */
    long block_start;               /* 0x54 */
    unsigned match_length;          /* 0x58 */
    unsigned prev_match;            /* 0x5c */
    int match_available;            /* 0x60 */
    unsigned strstart;              /* 0x64 */
    unsigned match_start;           /* 0x68 */
    unsigned lookahead;             /* 0x6c */
    unsigned prev_length;           /* 0x70 */
    unsigned max_chain_length;      /* 0x74 */
    unsigned max_lazy_match;        /* 0x78 */
    int level;                      /* 0x7c */
    int strategy;                   /* 0x80 */
    unsigned good_match;            /* 0x84 */
    int nice_match;                 /* 0x88 */
    Ts4lCtData dyn_ltree[573];      /* 0x8c */
    Ts4lCtData dyn_dtree[61];       /* 0x980 */
    Ts4lCtData bl_tree[39];         /* 0xa74 */
    Ts4lTreeDesc l_desc;            /* 0xb10 */
    Ts4lTreeDesc d_desc;            /* 0xb1c */
    Ts4lTreeDesc bl_desc;           /* 0xb28 */
    ush bl_count[16];               /* 0xb34 */
    int heap[573];                  /* 0xb54 */
    int heap_len;                   /* 0x1448 */
    int heap_max;                   /* 0x144c */
    uch depth[573];                 /* 0x1450 */
    uch *l_buf;                     /* 0x1690 */
    unsigned lit_bufsize;           /* 0x1694 */
    unsigned last_lit;              /* 0x1698 */
    ush *d_buf;                     /* 0x169c */
    ulg opt_len;                    /* 0x16a0 */
    ulg static_len;                 /* 0x16a4 */
    unsigned matches;               /* 0x16a8 */
    int last_eob_len;               /* 0x16ac */
    ush bi_buf;                     /* 0x16b0 */
    int bi_valid;                   /* 0x16b4 */
} Ts4lDeflateState;

typedef struct { ush good_length, max_lazy, nice_length, max_chain; void *func; } Ts4lConfig;
extern const Ts4lConfig lbl_83005F68[10];
extern const uch lbl_830060E4[19];
extern void fn_8316B4D8(Ts4lDeflateState *s, Ts4lTreeDesc *desc);
extern void *fn_833E3A30(void *p, int c, unsigned n);

Ts4lDeflateState *ts4l_scan_tree_8316A2C0(Ts4lDeflateState *s, Ts4lCtData *tree, int max_code)
{
    int n;
    int prevlen = -1;
    int curlen;
    int nextlen = tree[0].dl;
    int count = 0;
    int max_count = 7;
    int min_count = 4;

    if (nextlen == 0) {
        max_count = 138;
        min_count = 3;
    }
    tree[max_code + 1].dl = (ush)0xffff;
    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].dl;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            s->bl_tree[curlen].fc = (ush)(s->bl_tree[curlen].fc + count);
        } else if (curlen != 0) {
            if (curlen != prevlen) s->bl_tree[curlen].fc++;
            s->bl_tree[16].fc++;
        } else if (count <= 10) {
            s->bl_tree[17].fc++;
        } else {
            s->bl_tree[18].fc++;
        }
        count = 0;
        prevlen = curlen;
        if (nextlen == 0) {
            max_count = 138;
            min_count = 3;
        } else if (curlen == nextlen) {
            max_count = 6;
            min_count = 3;
        } else {
            max_count = 7;
            min_count = 4;
        }
    }
    return s;
}

int ts4l_build_bl_tree_8316B7C8(Ts4lDeflateState *s)
{
    int max_blindex;

    ts4l_scan_tree_8316A2C0(s, s->dyn_ltree, s->l_desc.max_code);
    ts4l_scan_tree_8316A2C0(s, s->dyn_dtree, s->d_desc.max_code);
    fn_8316B4D8(s, &s->bl_desc);
    for (max_blindex = 18; max_blindex >= 3; max_blindex--) {
        if (s->bl_tree[lbl_830060E4[max_blindex]].dl != 0) break;
    }
    s->opt_len += 3 * (max_blindex + 1) + 5 + 5 + 4;
    return max_blindex;
}

void ts4l_lm_init_83167D30(Ts4lDeflateState *s)
{
    s->window_size = (ulg)2L * s->w_size;
    s->head[s->hash_size - 1] = 0;
    fn_833E3A30(s->head, 0, (s->hash_size - 1) * sizeof(*s->head));
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
}
