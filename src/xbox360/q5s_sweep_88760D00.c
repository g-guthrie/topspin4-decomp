/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88760D00: for every 0x8c-byte element whose index is free (not in the used-id vector at +0x10), run fn_88760BA0
 * on it and release the slot (88220D90); then fn_882261F0 on the pool.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_88760D00_nearmiss_agAX.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_88760D00.json for route and flags. */
typedef struct E8C { char b[0x8c]; } E8C;
typedef struct Ts4IdVec { unsigned *first; unsigned *last; } Ts4IdVec;
typedef struct Ts4Pool8c { char pad[0x10]; Ts4IdVec used; char pad2[8]; E8C *first; E8C *last; } Ts4Pool8c;
void fn_88760BA0(E8C *e);
void ts4_pool_rel_8c_88220D90(Ts4Pool8c *o, int i);
void fn_882261F0(Ts4Pool8c *o);
static unsigned char is_free(Ts4IdVec *v, int i){
  unsigned *p;
  if (i < 0) return 0;
  { unsigned *e = v->last; for (p = v->first; e != p; p++) if ((unsigned)i == *p) return 0; }
  return 1;
}
void ts4_pool8c_release_free_slots_88760D00(Ts4Pool8c *o){ Ts4Pool8c* pool = o;  Ts4Pool8c* pool2 = pool; 
  int i;
  unsigned n = pool2->last - pool2->first;
  for (i = 0; i < n; i++) {
    if (is_free(&pool2->used, i) == 1) { fn_88760BA0(&pool2->first[i]); ts4_pool_rel_8c_88220D90(pool2, i); }
  }
  fn_882261F0(pool2);
}
