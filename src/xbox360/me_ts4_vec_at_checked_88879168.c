/* 0x88879168: returns the *i-th pointer of the vector at +0x28 (begin/end), or 0 when *i is not below the size. */
/* Matched on /Oc (agAB). Size and element both through inline helpers on &s->v; the element helper returns the slot address (clrrwi copy of begin, index-first lwzx). */
typedef struct Vec { void **begin; void **end; } Vec;
typedef struct S { char pad[0x28]; Vec v; } S;
static int vsize(Vec *v) { return v->end - v->begin; }
static void **vat(Vec *v, int i) { return &v->begin[i]; }
void *fn_88879168(S *s, int *i)
{
    if (*i < vsize(&s->v))
        return *vat(&s->v, *i);
    return 0;
}
