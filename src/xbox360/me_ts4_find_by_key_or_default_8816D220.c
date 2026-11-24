/* 0x8816D220: finds the entry in [b, e) whose key (+4) equals k and returns it, or the default entry at +0x10. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); the caller must test !o first (model 0x888C2FD8). */
typedef struct O { int a; unsigned key; } O;
typedef struct S { O **b; O **e; int pad[2]; O *def; } S;
static __forceinline O *find_by_key(S *s, unsigned k)
{
    O **e = s->e;
    O **i = s->b;
    for (; i != e; ++i) {
        if ((*i)->key == k)
            return *i;
    }
    return 0;
}
O *ts4_find_by_key_or_default_8816D220(S *s, unsigned k)
{
    O *o = find_by_key(s, k);
    if (!o)
        return s->def;
    return o;
}
