/* 0x88589748: Allocates the block range at index*64, then on success binds blk to arg, sets state bits to 0x20 and commits the range. */
/* Near miss (agAH): /O1, 3 off: rotlwi of index*64 is scheduled after the r5/r6 address setup instead of before. */
typedef struct Block { char p0[0x35]; unsigned char flags; unsigned short index; } Block;
extern int ts4_if_call_seq_fn_88589330_885896D8(void *ctx, unsigned int offset, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d);
extern void fn_88585BA8(Block *blk, void *arg, unsigned int a);
extern void fn_88585B00(void *ctx, unsigned int b, unsigned int c, unsigned int d);
int fn_88589748(void *ctx, Block *blk, void *arg)
{
    unsigned int a, b, c, d;
    int r = ts4_if_call_seq_fn_88589330_885896D8(ctx, blk->index * 64, &a, &b, &c, &d);
    if (r >= 0) {
        fn_88585BA8(blk, arg, a);
        blk->flags = (blk->flags & 0xCF) | 0x20;
        fn_88585B00(ctx, b, c, d);
    }
    return r;
}
