/* Loader_DLL.xex zlib 1.1.x declarations used by the l8_zlib_* sources
   (our own layout description; fields are named after the zlib ones). */
#ifndef TS4L_L8_ZLIB_H
#define TS4L_L8_ZLIB_H

typedef unsigned char ts4l_u8;
typedef unsigned short ts4l_u16;
typedef unsigned int ts4l_u32;

typedef struct ts4l_zct {
    ts4l_u16 freq;
    ts4l_u16 code;
} ts4l_zct;

typedef struct ts4l_zstatic {
    const ts4l_zct *static_tree;
    const int *extra_bits;
    int extra_base;
    int elems;
    int max_length;
} ts4l_zstatic;

typedef struct ts4l_ztdesc {
    ts4l_zct *dyn_tree;
    int max_code;
    ts4l_zstatic *stat_desc;
} ts4l_ztdesc;

typedef struct ts4l_zstream ts4l_zstream;
typedef struct ts4l_zstate ts4l_zstate;

struct ts4l_zstream {
    ts4l_u8 *next_in;
    ts4l_u32 avail_in;
    ts4l_u32 total_in;
    ts4l_u8 *next_out;
    ts4l_u32 avail_out;
    ts4l_u32 total_out;
    char *msg;
    ts4l_zstate *state;
    void *(*zalloc)(void *opaque, ts4l_u32 items, ts4l_u32 size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
    int data_type;
    ts4l_u32 adler;
    ts4l_u32 reserved;
};

struct ts4l_zstate {
    ts4l_zstream *strm;
    int status;
    ts4l_u8 *pending_buf;
    ts4l_u32 pending_buf_size;
    ts4l_u8 *pending_out;
    int pending;
    int noheader;
    ts4l_u8 data_type;
    ts4l_u8 method;
    int last_flush;
    ts4l_u32 w_size;
    ts4l_u32 w_bits;
    ts4l_u32 w_mask;
    ts4l_u8 *window;
    ts4l_u32 window_size;
    ts4l_u16 *prev;
    ts4l_u16 *head;
    ts4l_u32 ins_h;
    ts4l_u32 hash_size;
    ts4l_u32 hash_bits;
    ts4l_u32 hash_mask;
    ts4l_u32 hash_shift;
    long block_start;
    ts4l_u32 match_length;
    ts4l_u32 prev_match;
    int match_available;
    ts4l_u32 strstart;
    ts4l_u32 match_start;
    ts4l_u32 lookahead;
    ts4l_u32 prev_length;
    ts4l_u32 max_chain_length;
    ts4l_u32 max_lazy_match;
    int level;
    int strategy;
    char pad0[0x8c - 0x84];
    ts4l_zct dyn_ltree[573];
    ts4l_zct dyn_dtree[61];
    ts4l_zct bl_tree[39];
    ts4l_ztdesc l_desc;
    ts4l_ztdesc d_desc;
    ts4l_ztdesc bl_desc;
    ts4l_u16 bl_count[16];
    int heap[573];
    int heap_len;
    int heap_max;
    ts4l_u8 depth[573];
    char pad1[0x1690 - 0x168d];
    ts4l_u8 *l_buf;
    ts4l_u32 lit_bufsize;
    ts4l_u32 last_lit;
    ts4l_u16 *d_buf;
    ts4l_u32 opt_len;
    ts4l_u32 static_len;
    ts4l_u32 matches;
    int last_eob_len;
    ts4l_u16 bi_buf;
    int bi_valid;
};


#endif
