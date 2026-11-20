/* Loader_DLL.xex 0x831687A8-0x83168CD0, executable version 0.0.0.3.
 * zlib deflate (deflate.c): deflate_slow (lazy match evaluation), with
 * INSERT_STRING, _tr_tally and FLUSH_BLOCK inlined. */
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

typedef struct { uch *next_in; unsigned avail_in; ulg total_in; uch *next_out; unsigned avail_out; } Ts4lZStream;

typedef struct {
    Ts4lCtData *dyn_tree;
    int max_code;
    const Ts4lStaticTreeDesc *stat_desc;
} Ts4lTreeDesc;

typedef struct {
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

extern const uch lbl_830066B8[];   /* _dist_code */
extern const uch lbl_830068B8[];   /* _length_code */
extern void fn_83167FB8(Ts4lDeflateState *s);
extern unsigned fn_83167DF8(Ts4lDeflateState *s, unsigned cur_match);
extern void fn_831674C0(Ts4lZStream *strm);
extern void fn_8316BD10(Ts4lDeflateState *s, char *buf, ulg stored_len, int eof);

#define MIN_LOOKAHEAD 262
#define UPDATE_HASH(s, h, c) (h = (((h) << s->hash_shift) ^ (c)) & s->hash_mask)
#define INSERT_STRING(s, str, match_head) \
    (UPDATE_HASH(s, s->ins_h, s->window[(str) + 2]), \
     s->prev[(str) & s->w_mask] = match_head = s->head[s->ins_h], \
     s->head[s->ins_h] = (ush)(str))
#define d_code(dist) ((uch)((dist) < 256 ? lbl_830066B8[dist] : lbl_830066B8[256 + ((dist) >> 7)]))
#define tally_dist(s, distance, length, flush) \
    { uch len = (length); ush dist = (distance); \
      s->d_buf[s->last_lit] = dist; \
      s->l_buf[s->last_lit++] = len; \
      dist--; \
      s->dyn_ltree[lbl_830068B8[len] + 256 + 1].fc++; \
      s->dyn_dtree[d_code(dist)].fc++; \
      flush = (s->last_lit == s->lit_bufsize - 1); \
    }
#define tally_lit(s, c, flush) \
    { uch cc = (c); \
      s->d_buf[s->last_lit] = 0; \
      s->l_buf[s->last_lit++] = cc; \
      s->dyn_ltree[cc].fc++; \
      flush = (s->last_lit == s->lit_bufsize - 1); \
    }
#define FLUSH_BLOCK_ONLY(s, eof) \
    { fn_8316BD10(s, (s->block_start >= 0L ? (char *)&s->window[(unsigned)s->block_start] : (char *)0), \
                  (ulg)((long)s->strstart - s->block_start), (eof)); \
      s->block_start = s->strstart; \
      fn_831674C0(s->strm); }
#define FLUSH_BLOCK(s, eof) \
    { FLUSH_BLOCK_ONLY(s, eof); \
      if (s->strm->avail_out == 0) return (eof) ? 2 : 0; }

int ts4l_deflate_slow_831687A8(Ts4lDeflateState *s, int flush)
{
    unsigned hash_head = 0;
    int bflush;

    for (;;) {
        if (s->lookahead < MIN_LOOKAHEAD) {
            fn_83167FB8(s);
            if (s->lookahead < MIN_LOOKAHEAD && flush == 0)
                return 0;
            if (s->lookahead == 0)
                break;
        }
        if (s->lookahead >= 3) {
            INSERT_STRING(s, s->strstart, hash_head);
        }
        s->prev_length = s->match_length;
        s->prev_match = s->match_start;
        s->match_length = 2;
        if (hash_head != 0 && s->prev_length < s->max_lazy_match &&
            s->strstart - hash_head <= s->w_size - MIN_LOOKAHEAD) {
            if (s->strategy != 2) {
                s->match_length = fn_83167DF8(s, hash_head);
            }
            if (s->match_length <= 5 &&
                (s->strategy == 1 || (s->match_length == 3 && s->strstart - s->match_start > 4096))) {
                s->match_length = 2;
            }
        }
        if (s->prev_length >= 3 && s->match_length <= s->prev_length) {
            unsigned max_insert = s->strstart + s->lookahead - 3;
            tally_dist(s, s->strstart - 1 - s->prev_match, s->prev_length - 3, bflush);
            s->lookahead -= s->prev_length - 1;
            s->prev_length -= 2;
            do {
                if (++s->strstart <= max_insert) {
                    INSERT_STRING(s, s->strstart, hash_head);
                }
            } while (--s->prev_length != 0);
            s->match_available = 0;
            s->match_length = 2;
            s->strstart++;
            if (bflush)
                FLUSH_BLOCK(s, 0);
        } else if (s->match_available) {
            tally_lit(s, s->window[s->strstart - 1], bflush);
            if (bflush) {
                FLUSH_BLOCK_ONLY(s, 0);
            }
            s->strstart++;
            s->lookahead--;
            if (s->strm->avail_out == 0)
                return 0;
        } else {
            s->match_available = 1;
            s->strstart++;
            s->lookahead--;
        }
    }
    if (s->match_available) {
        tally_lit(s, s->window[s->strstart - 1], bflush);
        s->match_available = 0;
    }
    FLUSH_BLOCK(s, flush == 4);
    return flush == 4 ? 3 : 1;
}
