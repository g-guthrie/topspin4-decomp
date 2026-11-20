/* Loader_DLL.xex 0x83168F00-0x831691C4, executable version 0.0.0.3.
 * zlib deflate (deflate.c): deflateInit2_. */
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;

typedef struct { ush fc; ush dl; } Ts4lCtData;

typedef struct {
    const Ts4lCtData *static_tree;
    const int *extra_bits;
    int extra_base;
    int elems;
    int max_length;
} Ts4lStaticTreeDesc;

typedef struct Ts4lZStream {
    uch *next_in;
    unsigned avail_in;
    ulg total_in;
    uch *next_out;
    unsigned avail_out;
    ulg total_out;
    const char *msg;
    struct Ts4lDeflateStateTag *state;
    void *(*zalloc)(void *opaque, unsigned items, unsigned size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
    int data_type;
    ulg adler;
    ulg reserved;
} Ts4lZStream;

typedef struct {
    Ts4lCtData *dyn_tree;
    int max_code;
    const Ts4lStaticTreeDesc *stat_desc;
} Ts4lTreeDesc;

typedef struct Ts4lDeflateStateTag {
    Ts4lZStream *strm;              /* 0x00 */
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

extern const char *lbl_83006B54[];   /* z_errmsg */
extern void *fn_8316C0D8(void *opaque, unsigned items, unsigned size);
extern void fn_8316C130(void *opaque, void *address);
extern int fn_83167968(Ts4lZStream *strm);
extern int fn_83168CD0(Ts4lZStream *strm);

#define ZALLOC(strm, items, size) \
    ((items) > 0xFFFFFFFFu / (size) ? (void *)0 : (*(strm)->zalloc)((strm)->opaque, (items), (size)))

int ts4l_deflate_init2_83168F00(Ts4lZStream *strm, int level, int method, int windowBits,
                                int memLevel, int strategy, const char *version, int stream_size)
{
    Ts4lDeflateState *s;
    int noheader = 0;
    ush *overlay;

    if (version == 0 || version[0] != '1' || (unsigned)stream_size != sizeof(Ts4lZStream))
        return -6;
    if (strm == 0)
        return -2;
    strm->msg = 0;
    if (strm->zalloc == 0) {
        strm->zalloc = fn_8316C0D8;
        strm->opaque = 0;
    }
    if (strm->zfree == 0)
        strm->zfree = fn_8316C130;
    if (level == -1)
        level = 6;
    if (windowBits < 0) {
        noheader = 1;
        windowBits = -windowBits;
    }
    if (memLevel < 1 || memLevel > 9 || method != 8 || windowBits < 9 || windowBits > 15 ||
        level < 0 || level > 9 || strategy < 0 || strategy > 2)
        return -2;
    s = (Ts4lDeflateState *)ZALLOC(strm, 1, sizeof(Ts4lDeflateState));
    if (s == 0)
        return -4;
    s->status = 42;
    strm->state = s;
    s->strm = strm;
    s->noheader = noheader;
    s->w_bits = windowBits;
    s->w_size = 1 << s->w_bits;
    s->w_mask = s->w_size - 1;
    s->hash_bits = memLevel + 7;
    s->hash_size = 1 << s->hash_bits;
    s->hash_mask = s->hash_size - 1;
    s->hash_shift = (s->hash_bits + 3 - 1) / 3;
    s->window = (uch *)ZALLOC(strm, s->w_size, 2);
    s->prev = (ush *)ZALLOC(strm, s->w_size, 2);
    s->head = (ush *)ZALLOC(strm, s->hash_size, 2);
    s->lit_bufsize = 1 << (memLevel + 6);
    overlay = (ush *)ZALLOC(strm, s->lit_bufsize, 4);
    s->pending_buf = (uch *)overlay;
    s->pending_buf_size = (ulg)s->lit_bufsize * 4L;
    if (s->window == 0 || s->prev == 0 || s->head == 0 || s->pending_buf == 0) {
        strm->msg = lbl_83006B54[6];
        fn_83167968(strm);
        return -4;
    }
    s->d_buf = overlay + s->lit_bufsize / 2;
    s->l_buf = s->pending_buf + 3 * s->lit_bufsize;
    s->level = level;
    s->strategy = strategy;
    s->method = (uch)method;
    return fn_83168CD0(strm);
}
