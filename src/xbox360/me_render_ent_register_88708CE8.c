
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Ent { float f[22]; u32 w58; void *owner; void *key; u32 w64; } Ent;
typedef struct EntVec { Ent *begin; Ent *end; u32 pad; Ent *cap; } EntVec;
typedef struct Sub { u8 pad[0xc]; void *ready; } Sub;
typedef struct Mgr { u8 pad[0x34]; Sub *sub; u8 pad38[0x48]; EntVec ents; } Mgr;
typedef struct Req { u8 pad[0x34]; void *key; } Req;
extern const float lbl_8814B440;
void *memcpy(void *d, const void *s, unsigned n);
void ts4_vector_grow_append_88227298(EntVec *v, Ent *where, const Ent *val);
int render_ent_register(Mgr *m, Req *r){
  Ent *it;
  if (!r->key || !m->sub->ready) return 0;
  for (it = m->ents.begin; it != m->ents.end; it++) if (it->key == r->key) return 0;
  {
    EntVec *v = &m->ents; Ent t; int i;
    t.w58 = 0; t.owner = 0; t.key = 0; t.w64 = 0;
        t.f[0] = lbl_8814B440;
    t.f[1] = lbl_8814B440;
    t.f[2] = lbl_8814B440;
    t.f[3] = lbl_8814B440;
    t.f[4] = lbl_8814B440;
    t.f[5] = lbl_8814B440;
    t.f[6] = lbl_8814B440;
    t.f[7] = lbl_8814B440;
    t.f[8] = lbl_8814B440;
    t.f[9] = lbl_8814B440;
    t.f[10] = lbl_8814B440;
    t.f[11] = lbl_8814B440;
    t.f[12] = lbl_8814B440;
    t.f[13] = lbl_8814B440;
    t.f[14] = lbl_8814B440;
    t.f[15] = lbl_8814B440;
    t.f[16] = lbl_8814B440;
    t.f[17] = lbl_8814B440;
    t.f[18] = lbl_8814B440;
    t.f[19] = lbl_8814B440;
    t.f[20] = lbl_8814B440;
    t.f[21] = lbl_8814B440;
    if (v->end != v->cap) { if (v->end) memcpy(v->end, &t, sizeof t); v->end++; }
    else ts4_vector_grow_append_88227298(v, v->end, &t);
  }
  { Ent *b = m->ents.end - 1; void *k = r->key; b->owner = m; b->key = k; }
  return 1;
}
