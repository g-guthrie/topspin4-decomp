/* 0x88838500: adds d (> 0) to u16 counter j (0..3) of 20-byte entry i of the vector at +0x68/+0x6C, ignoring out-of-range arguments. */
/* Matched on /Oc (agAF). Inline vector size and element helpers on &t->v give the end-first size loads and the clrrwi copy of begin. */
typedef struct Ent { unsigned short p[5]; unsigned short c[4]; unsigned short pad; } Ent;
typedef struct Vec { Ent *begin; Ent *end; } Vec;
typedef struct T { char p[0x68]; Vec v; } T;
static __inline int vsize(const Vec *v) { return v->end - v->begin; }
static __inline Ent *vat(Vec *v, int i) { return &v->begin[i]; }
void fn_88838500(T *t, int i, int j, int d)
{
    if (i > -1 && (unsigned int)i < (unsigned int)vsize(&t->v) && j >= 0 && j < 4 && d > 0)
        vat(&t->v, i)->c[j] += d;
}
