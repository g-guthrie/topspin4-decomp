/* Swing_DLL.xex 0x888FBCA0 (/Oc): school-play scoring: when the context's descriptor type
 * (ctx->+0x24->+0x60) is 0x30F9B07C and a block is pending (+0xAC == 1), remember the cursor,
 * advance it by b0 * a8 * a0 points, add those points to the score, then clear the pending
 * block, set the refresh byte (+0x9A) and clear the dirty flag at ctx->+0x44->+0x10->+0x54.
 * Matching note: a0 is read into its own local before the b0 * a8 product local; with the
 * product written in one expression the target's a8-before-a0 load order is not reached,
 * and with only the product local the last mullw operands swap (1 off). */
typedef unsigned char u8;
typedef struct Ts4SpDesc { u8 pad[0x60]; unsigned type; } Ts4SpDesc;
typedef struct Ts4SpFlag { u8 pad[0x54]; u8 dirty; } Ts4SpFlag;
typedef struct Ts4SpInner { u8 pad[0x10]; Ts4SpFlag *flag; } Ts4SpInner;
typedef struct Ts4SpCtx { u8 pad[0x24]; Ts4SpDesc *desc; u8 pad28[0x1c]; Ts4SpInner *inner; } Ts4SpCtx;
typedef struct Ts4SpBlock {
    int pad0;
    Ts4SpCtx *ctx;      /* +0x04 */
    int cursor;         /* +0x08 */
    int prev_cursor;    /* +0x0C */
    u8 pad10[0x8a];
    u8 refresh;         /* +0x9A */
    u8 pad9b[5];
    int a0;             /* +0xA0 */
    int pada4;
    int a8;             /* +0xA8 */
    u8 pending;         /* +0xAC */
    u8 padad[3];
    int b0;             /* +0xB0 */
} Ts4SpBlock;

void ts4_school_play_add_score_888FBA90(int points);

void ts4_school_play_commit_block_888FBCA0(Ts4SpBlock *o)
{
    if (o->ctx->desc->type == 0x30F9B07C && o->pending == 1) {
        o->prev_cursor = o->cursor;
        {
            int w = o->a0;
            int n = o->b0 * o->a8;
            o->cursor += n * w;
            ts4_school_play_add_score_888FBA90(n * w);
        }
        o->pending = 0;
        o->a0 = 0;
        o->a8 = 0;
        o->refresh = 1;
        o->ctx->inner->flag->dirty = 0;
    }
}
