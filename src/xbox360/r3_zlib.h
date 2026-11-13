/* Derived from zlib (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#ifndef R3_ZLIB_H
#define R3_ZLIB_H
/* zlib 1.2.x deflate state (public zlib layout) as used by the R3 deflate functions.
 * Offsets verified against Swing_DLL.xex machine code. */

typedef struct ts4_z_stream {
    unsigned char *next_in;     /* +0x00 */
    unsigned int avail_in;      /* +0x04 */
    unsigned long total_in;     /* +0x08 */
    unsigned char *next_out;    /* +0x0C */
    unsigned int avail_out;     /* +0x10 */
} ts4_z_stream;

typedef struct ts4_deflate_state {
    ts4_z_stream *strm;                 /* +0x00 */
    int status;                         /* +0x04 */
    unsigned char *pending_buf;         /* +0x08 */
    unsigned long pending_buf_size;     /* +0x0C */
    unsigned char *pending_out;         /* +0x10 */
    unsigned int pending;               /* +0x14 */
    int wrap;                           /* +0x18 */
    void *gzhead;                       /* +0x1C */
    unsigned int gzindex;               /* +0x20 */
    unsigned char method;               /* +0x24 */
    int last_flush;                     /* +0x28 */
    unsigned int w_size;                /* +0x2C */
    unsigned int w_bits;                /* +0x30 */
    unsigned int w_mask;                /* +0x34 */
    unsigned char *window;              /* +0x38 */
    unsigned long window_size;          /* +0x3C */
    unsigned short *prev;               /* +0x40 */
    unsigned short *head;               /* +0x44 */
    unsigned int ins_h;                 /* +0x48 */
    unsigned int hash_size;             /* +0x4C */
    unsigned int hash_bits;             /* +0x50 */
    unsigned int hash_mask;             /* +0x54 */
    unsigned int hash_shift;            /* +0x58 */
    long block_start;                   /* +0x5C */
    unsigned int match_length;          /* +0x60 */
    unsigned int prev_match;            /* +0x64 */
    int match_available;                /* +0x68 */
    unsigned int strstart;              /* +0x6C */
    unsigned int match_start;           /* +0x70 */
    unsigned int lookahead;             /* +0x74 */
    unsigned int prev_length;           /* +0x78 */
    unsigned int max_chain_length;      /* +0x7C */
    unsigned int max_lazy_match;        /* +0x80 */
    int level;                          /* +0x84 */
    int strategy;                       /* +0x88 */
    unsigned int good_match;            /* +0x8C */
    int nice_match;                     /* +0x90 */
} ts4_deflate_state;

#endif
