/* 0x8848E4F8: calls ts4_noop_884927B8 on the arrays at +0x28 and +0x34 back to front, then on +0x20 */
/* Near miss (agAH): /Oc, 1 off at +0x4c: the second loop lwzx is index-first in the target. Loop-body locals, embedded array structs, inline accessors, block-scoped counters and C++ all give base-first. */
typedef struct Item Item;
typedef struct T { char p0[0x20]; Item *root; char p24[4]; Item **a; int na; char p30[4]; Item **b; int nb; } T;
extern void ts4_noop_884927B8(Item *it);
void fn_8848E4F8(T *t)
{
    int i;
    for (i = t->na - 1; i >= 0; i--)
        ts4_noop_884927B8(t->a[i]);
    for (i = t->nb - 1; i >= 0; i--)
        ts4_noop_884927B8(t->b[i]);
    ts4_noop_884927B8(t->root);
}
