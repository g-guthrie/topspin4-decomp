/* Loader_DLL.xex 0x83464DB8-0x83464E58, executable version 0.0.0.3.
 * zlib 1.1.x trees.c: _tr_init (with init_block). */
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

typedef struct { const Ts4lCtData *static_tree; const int *extra_bits; int extra_base; int elems; int max_length; } Ts4lStaticDesc;
extern const Ts4lStaticDesc lbl_8307BE88;

void ts4l_zlib_tr_init_83464DB8(Ts4lDeflateState *s)
{
    int n;
        s->l_desc.dyn_tree = s->dyn_ltree;
    s->l_desc.stat_desc = &lbl_8307BE88 - 2;
    s->d_desc.stat_desc = &lbl_8307BE88 - 1;
    s->d_desc.dyn_tree = s->dyn_dtree;
    s->bl_desc.dyn_tree = s->bl_tree;
    s->bl_desc.stat_desc = &lbl_8307BE88;
    s->bi_buf = 0;
    s->bi_valid = 0;
    s->last_eob_len = 8;
        for (n = 0; n < 286; n++) s->dyn_ltree[n].fc = 0;
    for (n = 0; n < 30; n++) s->dyn_dtree[n].fc = 0;
    for (n = 0; n < 19; n++) s->bl_tree[n].fc = 0;
    s->dyn_ltree[256].fc = 1;
    s->opt_len = s->static_len = 0L;
    s->last_lit = s->matches = 0;
}

