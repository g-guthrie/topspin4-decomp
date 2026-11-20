/* 0x883DD070: binds a into slot +0x20 (or +0x24 when b is given and swap set) and b into the other slot via fn_883DC0D0(t, src, t->f1c, slot); returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct T { char pad[0x1c]; void *ctx; void *slot[2]; } T;
int fn_883DC0D0(T *t, void *src, void *ctx, void **slot);
int ts4_bind_pair_slots_883DD070(T *t, void *a, void *b, unsigned char swap)
{
    int r = fn_883DC0D0(t, a, t->ctx, &t->slot[(b && swap) ? 1 : 0]);
    if (r)
        return r;
    if (b) {
        r = fn_883DC0D0(t, b, t->ctx, &t->slot[!swap]);
        if (r)
            return r;
    }
    return 0;
}
