/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef EX3_ZLIB_H
#define EX3_ZLIB_H
/* Full zlib 1.2.3 style deflate state, with the trees.c section, as laid out in Swing_DLL.xex
 * (offsets verified against the machine code). Family EX3. */

#define EX3_L_CODES 286
#define EX3_D_CODES 30
#define EX3_BL_CODES 19
#define EX3_HEAP_SIZE (2 * EX3_L_CODES + 1)
#define EX3_MAX_BITS 15

typedef struct ex3_ct_data {
    unsigned short fc; /* freq or code */
    unsigned short dl; /* dad or len */
} ex3_ct_data;

typedef struct ex3_static_tree_desc {
    const ex3_ct_data *static_tree; /* +0x00 */
    const int *extra_bits;          /* +0x04 */
    int extra_base;                 /* +0x08 */
    int elems;                      /* +0x0C */
    int max_length;                 /* +0x10 */
} ex3_static_tree_desc;

typedef struct ex3_tree_desc {
    ex3_ct_data *dyn_tree;                /* +0x00 */
    int max_code;                         /* +0x04 */
    const ex3_static_tree_desc *stat_desc; /* +0x08 */
} ex3_tree_desc;

typedef struct ex3_z_stream ex3_z_stream;

typedef struct ex3_deflate_state {
    ex3_z_stream *strm;                 /* +0x000 */
    int status;                         /* +0x004 */
    unsigned char *pending_buf;         /* +0x008 */
    unsigned long pending_buf_size;     /* +0x00C */
    unsigned char *pending_out;         /* +0x010 */
    unsigned int pending;               /* +0x014 */
    int wrap;                           /* +0x018 */
    void *gzhead;                       /* +0x01C */
    unsigned int gzindex;               /* +0x020 */
    unsigned char method;               /* +0x024 */
    int last_flush;                     /* +0x028 */
    unsigned int w_size;                /* +0x02C */
    unsigned int w_bits;                /* +0x030 */
    unsigned int w_mask;                /* +0x034 */
    unsigned char *window;              /* +0x038 */
    unsigned long window_size;          /* +0x03C */
    unsigned short *prev;               /* +0x040 */
    unsigned short *head;               /* +0x044 */
    unsigned int ins_h;                 /* +0x048 */
    unsigned int hash_size;             /* +0x04C */
    unsigned int hash_bits;             /* +0x050 */
    unsigned int hash_mask;             /* +0x054 */
    unsigned int hash_shift;            /* +0x058 */
    long block_start;                   /* +0x05C */
    unsigned int match_length;          /* +0x060 */
    unsigned int prev_match;            /* +0x064 */
    int match_available;                /* +0x068 */
    unsigned int strstart;              /* +0x06C */
    unsigned int match_start;           /* +0x070 */
    unsigned int lookahead;             /* +0x074 */
    unsigned int prev_length;           /* +0x078 */
    unsigned int max_chain_length;      /* +0x07C */
    unsigned int max_lazy_match;        /* +0x080 */
    int level;                          /* +0x084 */
    int strategy;                       /* +0x088 */
    unsigned int good_match;            /* +0x08C */
    int nice_match;                     /* +0x090 */
    ex3_ct_data dyn_ltree[EX3_HEAP_SIZE];          /* +0x094 */
    ex3_ct_data dyn_dtree[2 * EX3_D_CODES + 1];    /* +0x988 */
    ex3_ct_data bl_tree[2 * EX3_BL_CODES + 1];     /* +0xA7C */
    ex3_tree_desc l_desc;               /* +0xB18 */
    ex3_tree_desc d_desc;               /* +0xB24 */
    ex3_tree_desc bl_desc;              /* +0xB30 */
    unsigned short bl_count[EX3_MAX_BITS + 1]; /* +0xB3C */
    int heap[2 * EX3_L_CODES + 1];      /* +0xB5C */
    int heap_len;                       /* +0x1450 */
    int heap_max;                       /* +0x1454 */
    unsigned char depth[2 * EX3_L_CODES + 1]; /* +0x1458 */
    unsigned char *l_buf;               /* +0x1698 */
    unsigned int lit_bufsize;           /* +0x169C */
    unsigned int last_lit;              /* +0x16A0 */
    unsigned short *d_buf;              /* +0x16A4 */
    unsigned long opt_len;              /* +0x16A8 */
    unsigned long static_len;           /* +0x16AC */
    unsigned int matches;               /* +0x16B0 */
    int last_eob_len;                   /* +0x16B4 */
    unsigned short bi_buf;              /* +0x16B8 */
    int bi_valid;                       /* +0x16BC */
} ex3_deflate_state;

#define EX3_PUT_BYTE(s, c) { (s)->pending_buf[(s)->pending++] = (unsigned char)(c); }
#define EX3_PUT_SHORT(s, w)                          \
    {                                                \
        EX3_PUT_BYTE(s, (unsigned char)((w)&0xff));  \
        EX3_PUT_BYTE(s, (unsigned char)((unsigned short)(w) >> 8)); \
    }

#define EX3_BUF_SIZE 16
#define EX3_SEND_BITS(s, value, length)                                          \
    {                                                                            \
        int len = (length);                                                      \
        if ((s)->bi_valid > (int)EX3_BUF_SIZE - len) {                           \
            int val = (value);                                                   \
            (s)->bi_buf |= (val << (s)->bi_valid);                               \
            EX3_PUT_SHORT(s, (s)->bi_buf);                                       \
            (s)->bi_buf = (unsigned short)val >> (EX3_BUF_SIZE - (s)->bi_valid); \
            (s)->bi_valid += len - EX3_BUF_SIZE;                                 \
        } else {                                                                 \
            (s)->bi_buf |= (value) << (s)->bi_valid;                             \
            (s)->bi_valid += len;                                                \
        }                                                                        \
    }

#endif
