/* 0x887F7678: returns the first non-null object in the pointer vector at +0x34/+0x38 whose id (+0x20) equals *key, or 0. */
/* Near miss (agAB, /Oc): 1 off, cmplw operand order (target key, id with id loaded first). `o->id == *key` fixes the load
 * order; `*key == o->id`, an id local and a subtraction test all move the loads back. */
typedef struct O { char p[0x20]; unsigned int id; } O;
typedef struct Vec { O **begin; O **end; } Vec;
typedef struct S { char p[0x34]; Vec v; } S;
static unsigned int vsize(Vec *v) { return v->end - v->begin; }
O *fn_887F7678(S *s, const unsigned int *key)
{
    unsigned int i, n = vsize(&s->v);
    for (i = 0; i < n; i++) {
        O *o = s->v.begin[i];
        if (o && o->id == *key)
            return o;
    }
    return 0;
}
