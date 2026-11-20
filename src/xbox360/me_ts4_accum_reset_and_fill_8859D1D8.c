/* 0x8859D1D8: clears the three-word accumulator at +0x13C, then feeds every index below the count at +0x134 to fn_8859B210 */
/* Matched on /Oc /Os (agAH). Counter initialised once and stored into the accumulator through a pointer local. */
typedef struct Acc { int a, b, c; } Acc;
typedef struct Grp { char pad[0x134]; unsigned int count; int pad138; Acc acc; int pad148; void *src; } Grp;
void fn_8859B210(void *src, unsigned int i, Acc *acc);
void fn_8859D1D8(Grp *g)
{
    unsigned int i = 0;
    Acc *acc = &g->acc;
    acc->a = i;
    acc->b = i;
    acc->c = i;
    for (; i < g->count; i++)
        fn_8859B210(g->src, i, acc);
}
