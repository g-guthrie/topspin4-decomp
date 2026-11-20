/* Loader_DLL.xex 0x8316ACA0-0x8316B0CC, executable version 0.0.0.3.
 * zlib deflate (trees.c): compress_block. */
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
extern const unsigned char lbl_830066B8[512];
/* File-local trees.c tables (extra_lbits, extra_dbits, base_length, base_dist) of the original unit are reached
 * from one base register; model them as one table. Only sizes matter for code generation. */
static const int ts4l_tabs[0x270 + 30] = {1};
extern const unsigned char lbl_830066B8[512]; /* _dist_code */
extern const unsigned char lbl_830068B8[256]; /* _length_code */

#define extra_lbits (ts4l_tabs)
#define extra_dbits (ts4l_tabs + 0x22)
#define base_length (ts4l_tabs + 0x252)
#define base_dist   (ts4l_tabs + 0x270)
#define _dist_code  lbl_830066B8
#define _length_code lbl_830068B8
#define d_code(dist) ((dist) < 256 ? _dist_code[dist] : _dist_code[256 + ((dist) >> 7)])

void ts4l_compress_block_8316ACA0(Ts4lDeflateState *s, Ts4lCtData *ltree, Ts4lCtData *dtree)
{
    unsigned dist;
    int lc;
    unsigned lx = 0;
    unsigned code;
    int extra;

    if (s->last_lit != 0) do {
        dist = s->d_buf[lx];
        lc = s->l_buf[lx++];
        if (dist == 0) {
            send_code(s, lc, ltree);
        } else {
            code = _length_code[lc];
            send_code(s, code + 256 + 1, ltree);
            extra = extra_lbits[code];
            if (extra != 0) {
                lc -= base_length[code];
                send_bits(s, lc, extra);
            }
            dist--;
            code = (unsigned char)d_code(dist);
            send_code(s, code, dtree);
            extra = extra_dbits[code];
            if (extra != 0) {
                dist -= base_dist[code];
                send_bits(s, dist, extra);
            }
        }
    } while (lx < s->last_lit);
    send_code(s, 256, ltree);
    s->last_eob_len = ltree[256].dl;
}
