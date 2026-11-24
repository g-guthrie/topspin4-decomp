/* 0x888C2C38: returns (i + j) modulo the number of 24-byte entries of the vector at +0x20 when i is below the count at *(+0x4C), else 0. */
/* Matched on /Oc (agAB). Result variable r = 0 set before the guard (li r3,0 first). */
typedef struct V { char *begin; char *end; } V;
typedef struct T { char p0[0x20]; V *v; char p24[0x4c - 0x24]; unsigned int *count; } T;
unsigned int fn_888C2C38(T *t, unsigned int i, unsigned int j)
{
    unsigned int r = 0;
    if (i < *t->count) {
        unsigned int n = (t->v->end - t->v->begin) / 24;
        r = (i + j) % n;
    }
    return r;
}
