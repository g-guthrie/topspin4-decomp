/* 0x884C0E78: takes w->v (+0xC), negated when u flips (+0xCC) and t is mirrored (+0x14); returns 1.0 when u flips but t is not mirrored, otherwise 0 for a positive value and -value for the rest. */
/* Matched on /Oc (agAF). Float literals 1.0f, 0.0f and -1.0f (the .rdata labels hold those bytes). */
typedef struct T { char p[0x14]; unsigned char mirrored; } T;
typedef struct U { char p[0xcc]; signed char flip; } U;
typedef struct W { char p[0xc]; float v; } W;
float fn_884C0E78(T *t, void *unused, U *u, W *w)
{
    float y;
    if (u->flip && t->mirrored)
        y = -w->v;
    else
        y = w->v;
    if (!t->mirrored && u->flip)
        return 1.0f;
    if (y > 0.0f)
        return 0.0f;
    return y * -1.0f;
}
