/* 0x8859D398: returns the largest ts4_if_get_u32_off4_8859B2D0(tab, i) over i below the count at +0x1C0 (table at +0x1D8). */
/* Matched on /Oc (agAB). Count re-read each pass; best <= v keeps the target compare. */
typedef struct T { char p[0x1c0]; unsigned int n; char p1c4[0x1d8 - 0x1c4]; void *tab; } T;
unsigned int ts4_if_get_u32_off4_8859B2D0(void *tab, unsigned int i);
unsigned int fn_8859D398(T *t)
{
    unsigned int best = 0, i;
    for (i = 0; i < t->n; i++) {
        unsigned int v = ts4_if_get_u32_off4_8859B2D0(t->tab, i);
        if (best <= v)
            best = v;
    }
    return best;
}
