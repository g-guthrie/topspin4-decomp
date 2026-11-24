/* agAX near-miss 88760D00, plain /Oc: 1 off, the `add r3,r29,r11` operand order of &o->first[i]
   (target base-offset = r29 + r11). Tried o->first + i, char* forms both orders, a named base local,
   unsigned i, n-before-i: all 1 off. */
typedef struct E8C { char b[0x8c]; } E8C;
typedef struct IV { unsigned *first; unsigned *last; } IV;
typedef struct O { char pad[0x10]; IV used; char pad2[8]; E8C *first; E8C *last; } O;
void fn_88760BA0(E8C *e);
void ts4_pool_rel_8c_88220D90(O *o, int i);
void fn_882261F0(O *o);
static unsigned char is_free(IV *v, int i){
  unsigned *p;
  if (i < 0) return 0;
  { unsigned *e = v->last; for (p = v->first; e != p; p++) if ((unsigned)i == *p) return 0; }
  return 1;
}
void pool8c_release_free_slots_88760D00(O *o){
  int i;
  unsigned n = o->last - o->first;
  for (i = 0; i < n; i++) {
    if (is_free(&o->used, i) == 1) { fn_88760BA0(&o->first[i]); ts4_pool_rel_8c_88220D90(o, i); }
  }
  fn_882261F0(o);
}
