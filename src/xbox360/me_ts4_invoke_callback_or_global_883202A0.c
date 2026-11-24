/* 0x883202A0: calls the callback at +0x1D4 with (+0x1D8, +0x1DC) when it and +0x1D0 are set, else the global pair at +0x18C->+0x55E8/+0x55E4; returns its result or 0. */
/* Matched on /Oc (agAB). int r = 0; if/else-if assigning r (shared return). */
typedef int (*Cb)(void *a, void *b);
typedef struct G { char p[0x55e4]; void *ctx; Cb cb; } G;
typedef struct T { char p[0x18c]; G *g; char p190[0x1d0 - 0x190]; void *ctx; Cb cb; void *a; void *b; } T;
int fn_883202A0(T *t)
{
    int r = 0;
    if (t->cb && t->ctx)
        r = t->cb(t->a, t->b);
    else if (t->g->cb && t->g->ctx)
        r = t->g->cb(t->a, t->b);
    return r;
}
