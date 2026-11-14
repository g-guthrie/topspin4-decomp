/* Loader_DLL.xex 0x8316A938-0x8316ABE8, executable version 0.0.0.3.
 * zlib deflate (trees.c): send_all_trees. */
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

#define Buf_size 16
#define put_byte(s, c) { s->pending_buf[s->pending++] = (uch)(c); }
#define put_short(s, w) { put_byte(s, (uch)((w) & 0xff)); put_byte(s, (uch)((ush)(w) >> 8)); }
#define send_bits(s, value, length) \
    { int len = length; \
      if (s->bi_valid > (int)Buf_size - len) { \
          int val = value; \
          s->bi_buf |= (val << s->bi_valid); \
          put_short(s, s->bi_buf); \
          s->bi_buf = (ush)val >> (Buf_size - s->bi_valid); \
          s->bi_valid += len - Buf_size; \
      } else { \
          s->bi_buf |= (value) << s->bi_valid; \
          s->bi_valid += len; \
      } \
    }
#define send_code(s, c, tree) send_bits(s, tree[c].fc, tree[c].dl)
extern const unsigned char lbl_830060E4[19];
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE __attribute__((noinline, unused))
#endif

/* File-local copy of the already matched send_tree (0x8316A3E8): the original compiler saw it in the same
 * translation unit, which changes the caller's register allocation. */
static TS4L_NOINLINE Ts4lDeflateState *ts4l_send_tree_8316A3E8(Ts4lDeflateState *s, Ts4lCtData *tree, int max_code)
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
    for (n = 0; n <= max_code; n++) {
        curlen = nextlen;
        nextlen = tree[n + 1].dl;
        if (++count < max_count && curlen == nextlen) {
            continue;
        } else if (count < min_count) {
            do {
                send_code(s, curlen, s->bl_tree);
            } while (--count != 0);
        } else if (curlen != 0) {
            if (curlen != prevlen) {
                send_code(s, curlen, s->bl_tree);
                count--;
            }
            send_code(s, 16, s->bl_tree);
            send_bits(s, count - 3, 2);
        } else if (count <= 10) {
            send_code(s, 17, s->bl_tree);
            send_bits(s, count - 3, 3);
        } else {
            send_code(s, 18, s->bl_tree);
            send_bits(s, count - 11, 7);
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


void ts4l_send_all_trees_8316A938(Ts4lDeflateState *s, int lcodes, int dcodes, int blcodes)
{
    int rank;
    send_bits(s, lcodes - 257, 5);
    send_bits(s, dcodes - 1, 5);
    send_bits(s, blcodes - 4, 4);
    for (rank = 0; rank < blcodes; rank++) {
        send_bits(s, s->bl_tree[lbl_830060E4[rank]].dl, 3);
    }
    ts4l_send_tree_8316A3E8(s, s->dyn_ltree, lcodes - 1);
    ts4l_send_tree_8316A3E8(s, s->dyn_dtree, dcodes - 1);
}
