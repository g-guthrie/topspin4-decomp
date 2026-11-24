/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8848E4F8: calls ts4_noop_884927B8 on the arrays at +0x28 and +0x34 back to front, then on +0x20.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_8848E4F8_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2) (the first loop body still reads through the parameter).
 * See work/specs/Q5S/sweep_8848E4F8.json for route and flags. */
typedef struct Item Item;
typedef struct T { char p0[0x20]; Item *root; char p24[4]; Item **a; int na; char p30[4]; Item **b; int nb; } T;
extern void ts4_noop_884927B8(Item *it);
void ts4_visit_items_reverse_8848E4F8(T *t)
{ T* tree = t; 
    int i;
    for (i = tree->na - 1; i >= 0; i--)
        ts4_noop_884927B8(t->a[i]);
    for (i = tree->nb - 1; i >= 0; i--)
        ts4_noop_884927B8(tree->b[i]);
    {  ts4_noop_884927B8(tree->root); }
}
