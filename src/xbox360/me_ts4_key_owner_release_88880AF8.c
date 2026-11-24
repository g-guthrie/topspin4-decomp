/* 0x88880AF8: removes every entry of the 12-byte key vector at +0x1c from the global registry, clears the
 * vector, resets the flag at +8 and compacts the vector at +0x10 (agAT). size()/at()/clear() inlines give the
 * target's r29 vector base and r30 byte offset. */
typedef struct { int a, b, c; } TS4Key12;
typedef struct { TS4Key12 *begin; TS4Key12 *end; } TS4KeyVec12;
typedef struct { char p[8]; unsigned char active; char q[7]; char tail[0xc]; TS4KeyVec12 keys; } TS4KeyOwner;
typedef struct { char p[0x24]; char reg[1]; } TS4KeyMgr;
extern TS4KeyMgr *lbl_88D459C4;
extern void ts4_remove_entry_by_key_8887E268(void *reg, TS4Key12 *e);
extern void ts4_vector_erase_range_88150310(TS4KeyVec12 *v, TS4Key12 *b, TS4Key12 *e);
extern void ts4_vec204_move_tail_881B9148(void *p);
static int keyvec_size(TS4KeyVec12 *v) { return v->end - v->begin; }
static TS4Key12 *keyvec_at(TS4KeyVec12 *v, int i) { return &v->begin[i]; }
static void keyvec_clear(TS4KeyVec12 *v) { ts4_vector_erase_range_88150310(v, v->begin, v->end); }
void ts4_key_owner_release_88880AF8(TS4KeyOwner *o) {
  int i; int n = keyvec_size(&o->keys);
  if (lbl_88D459C4)
    for (i = 0; i < n; i++) ts4_remove_entry_by_key_8887E268(lbl_88D459C4->reg, keyvec_at(&o->keys, i));
  keyvec_clear(&o->keys);
  o->active = 0;
  ts4_vec204_move_tail_881B9148(o->tail);
}
