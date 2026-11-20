/* 0x885897C8: If blk is not yet marked 0x20, allocates its range at index*64, then sets 0x20 and commits. */
/* Near miss (agAH): /O1, 3 off: same rotlwi scheduling as 88589748. */
typedef struct Block { char p0[0x35]; unsigned char flags; unsigned short index; } Block;
extern int ts4_if_call_seq_fn_88589330_885896D8(void *ctx, unsigned int offset, unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d);
extern void fn_88585BA8(Block *blk, void *arg, unsigned int a);
extern void fn_88585B00(void *ctx, unsigned int b, unsigned int c, unsigned int d);
int fn_885897C8(void *ctx, Block *blk)
{
    unsigned int a, b, c, d;
    int r;
    if (blk->flags & 0x20)
        return 0;
    r = ts4_if_call_seq_fn_88589330_885896D8(ctx, blk->index * 64, &a, &b, &c, &d);
    if (r >= 0) {
        blk->flags |= 0x20;
        fn_88585B00(ctx, b, c, d);
    }
    return r;
}
