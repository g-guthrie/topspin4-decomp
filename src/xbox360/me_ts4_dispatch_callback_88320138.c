/* 0x88320138: forwards (a, b, c) to the callback at +0x1C8, or else to the shared one at g(+0x18C)->+0x55DC, with ctx (+0x1D8) first and user (+0x1DC) last; 0 when neither is set. */
/* Matched on /Oc (agAB). r = 0 before the tests; only the second call goes through r. */
typedef int (*Cb)(void *ctx, int a, int b, int c, void *u);
typedef struct G { char p[0x55dc]; Cb cb; } G;
typedef struct T { char p0[0x18c]; G *g; char p190[0x1c8 - 0x190]; Cb cb; char p1cc[0x1d8 - 0x1cc]; void *ctx; void *user; } T;
int fn_88320138(T *t, int a, int b, int c)
{
    int r = 0;
    Cb cb = t->cb;
    if (cb)
        return cb(t->ctx, a, b, c, t->user);
    cb = t->g->cb;
    if (cb)
        r = cb(t->ctx, a, b, c, t->user);
    return r;
}
