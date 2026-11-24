/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88614900: store byte v at +8 of every item of the pointer range at +0x24/+0x28.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_88614900_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_88614900.json for route and flags. */
typedef struct { char p[8]; unsigned char v; } Ts4Byte8Item;
typedef struct { char p[0x24]; Ts4Byte8Item **b, **e; } Ts4ItemPtrRange;
void ts4_set_items_byte8_88614900(Ts4ItemPtrRange *s, unsigned char v) { Ts4ItemPtrRange* set = s;  unsigned i, n = s->e - set->b; for (i = 0; i < n; i++) set->b[i]->v = v; }
