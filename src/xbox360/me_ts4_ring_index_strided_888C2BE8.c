/* 0x888C2BE8: returns (stride(+0x5C) * i + j) modulo the number of 6-byte entries of the array at v(+0x20)+0xC..+0x10 when i is below the count at *(+0x4C), else 0. */
/* Matched on /Oc (agAB). Sibling of 888C2C38: result variable r = 0 before the guard. */
typedef struct V { char p[0xc]; char *begin; char *end; } V;
typedef struct T { char p0[0x20]; V *v; char p24[0x4c - 0x24]; unsigned int *count; char p50[0x5c - 0x50]; int stride; } T;
unsigned int fn_888C2BE8(T *t, unsigned int i, unsigned int j)
{
    unsigned int r = 0;
    if (i < *t->count) {
        unsigned int n = (t->v->end - t->v->begin) / 6;
        r = (t->stride * i + j) % n;
    }
    return r;
}
