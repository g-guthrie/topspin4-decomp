/* Loader_DLL.xex 0x8322CA20-0x8322CCB4, executable version 0.0.0.3. */
typedef struct ts4l_table_a_elem {
    unsigned pad0;
    void *buf4;
    unsigned pad8;
    void *bufc;
} ts4l_table_a_elem;

typedef struct ts4l_table_b_elem {
    unsigned pad0;
    unsigned pad4;
    unsigned pad8;
    void *bufc;
    void *buf10;
} ts4l_table_b_elem;

typedef struct ts4l_table_a {
    unsigned short count;
    unsigned short pad;
    ts4l_table_a_elem *elems;
} ts4l_table_a;

typedef struct ts4l_table_b {
    unsigned short count;
    unsigned short pad;
    ts4l_table_b_elem *elems;
} ts4l_table_b;

typedef struct ts4l_block5 {
    unsigned pad0;
    unsigned pad4;
    unsigned pad8;
    void *buf0c;
    void *buf10;
    void *buf14;
    void *buf18;
    void *buf1c;
} ts4l_block5;

typedef struct ts4l_pair {
    unsigned pad0;
    void *buf4;
} ts4l_pair;

typedef struct ts4l_context {
    unsigned char pad0[0xcc];
    ts4l_block5 *block5;
    ts4l_table_a *table_a;
    unsigned char pad_d4[0xe0 - 0xd4];
    void *buf_e0;
    unsigned char pad_e4[0xe8 - 0xe4];
    ts4l_table_b *table_b;
    unsigned char pad_ec[0x248 - 0xec];
    void *buf_248;
    unsigned char pad_24c[0x264 - 0x24c];
    void *buf_264;
    ts4l_pair *pair_268;
} ts4l_context;

extern void fn_8323A9F0(void *p);
extern void fn_8340D830(void *p, unsigned tag);

#define TS4L_FREE_TAG 0x248C8000u

/* Frees every allocation hanging off a context object and clears the owner's pointer. */
int ts4l_destroy_context_8322CA20(ts4l_context **owner)
{
    ts4l_context *ctx;
    ts4l_block5 *block;
    ts4l_pair *pair;
    unsigned i;
    unsigned tag;

    if (owner == 0)
        return 2;
    ctx = *owner;
    if (ctx != 0) {
        fn_8323A9F0(ctx->buf_248);
        tag = TS4L_FREE_TAG;
        ctx->buf_248 = 0;
        if (ctx->buf_e0 != 0) {
            fn_8340D830(ctx->buf_e0, tag);
            ctx->buf_e0 = 0;
        }
        block = ctx->block5;
        if (block != 0) {
            fn_8340D830(block->buf0c, tag);
            fn_8340D830(block->buf10, tag);
            fn_8340D830(block->buf14, tag);
            fn_8340D830(block->buf18, tag);
            fn_8340D830(block->buf1c, tag);
            fn_8340D830(block, tag);
            ctx->block5 = 0;
        }
        if (ctx->table_a != 0) {
            if (ctx->table_a->count != 0) {
                for (i = 0; i < ctx->table_a->count; i++) {
                    fn_8340D830(ctx->table_a->elems[i].bufc, tag);
                    fn_8340D830(ctx->table_a->elems[i].buf4, tag);
                    ctx->table_a->elems[i].bufc = 0;
                    ctx->table_a->elems[i].buf4 = 0;
                }
                fn_8340D830(ctx->table_a->elems, tag);
                ctx->table_a->elems = 0;
            }
            fn_8340D830(ctx->table_a, tag);
            ctx->table_a = 0;
        }
        if (ctx->table_b != 0) {
            if (ctx->table_b->count != 0) {
                for (i = 0; i < ctx->table_b->count; i++) {
                    if (ctx->table_b->elems != 0) {
                        void *p = ctx->table_b->elems[i].bufc;
                        if (p != 0)
                            fn_8340D830(p, tag);
                        ctx->table_b->elems[i].bufc = 0;
                        p = ctx->table_b->elems[i].buf10;
                        if (p != 0)
                            fn_8340D830(p, tag);
                        ctx->table_b->elems[i].buf10 = 0;
                    }
                }
                fn_8340D830(ctx->table_b->elems, tag);
                ctx->table_b->elems = 0;
            }
            fn_8340D830(ctx->table_b, tag);
            ctx->table_b = 0;
        }
        if (ctx->buf_264 != 0)
            fn_8340D830(ctx->buf_264, tag);
        pair = ctx->pair_268;
        ctx->buf_264 = 0;
        if (pair != 0) {
            if (pair->buf4 != 0)
                fn_8340D830(pair->buf4, tag);
            fn_8340D830(pair, tag);
        }
        ctx->pair_268 = 0;
        fn_8340D830(ctx, tag);
        *owner = 0;
        return 0;
    }
    return 2;
}
