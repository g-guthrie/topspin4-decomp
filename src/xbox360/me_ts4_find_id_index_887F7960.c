/* 0x887F7960: returns the index of *key in the word vector at +0x68 (begin/end), or -1. */
/* Matched on /Oc (agAB). Size hoisted into n; element through an inline slot-address helper (clrrwi copy of begin). */
typedef struct Vec { unsigned int *begin; unsigned int *end; } Vec;
typedef struct S { char p[0x68]; Vec v; } S;
static unsigned int vsize(Vec *v) { return v->end - v->begin; }
static unsigned int *vat(Vec *v, unsigned int i) { return &v->begin[i]; }
int fn_887F7960(S *s, const unsigned int *key)
{
    unsigned int i, n = vsize(&s->v);
    for (i = 0; i < n; i++)
        if (*key == *vat(&s->v, i))
            return i;
    return -1;
}
