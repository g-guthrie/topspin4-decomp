
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Ent { float f[22]; u32 w58; void *owner; void *key; u32 w64; } Ent;
typedef struct EntVec { Ent *begin; Ent *end; u32 pad; Ent *cap; } EntVec;
typedef struct Sub { u8 pad[0xc]; void *ready; } Sub;
typedef struct Mgr { u8 pad[0x34]; Sub *sub; u8 pad38[0x48]; EntVec ents; } Mgr;
typedef struct Req { u8 pad[0x34]; void *key; } Req;
extern const float g_ts4_event_value;
void *memcpy(void *d, const void *s, unsigned n);
void ts4_vector_grow_append_88227298(EntVec *v, Ent *where, const Ent *val);
int render_ent_register(Mgr *m, Req *r){
  Ent *it;
  if (!r->key || !m->sub->ready) return 0;
  for (it = m->ents.begin; it != m->ents.end; it++) if (it->key == r->key) return 0;
  {
    EntVec *v = &m->ents; Ent t; int i;
    t.w58 = 0; t.owner = 0; t.key = 0; t.w64 = 0;
        t.f[0] = g_ts4_event_value;
    t.f[1] = g_ts4_event_value;
    t.f[2] = g_ts4_event_value;
    t.f[3] = g_ts4_event_value;
    t.f[4] = g_ts4_event_value;
    t.f[5] = g_ts4_event_value;
    t.f[6] = g_ts4_event_value;
    t.f[7] = g_ts4_event_value;
    t.f[8] = g_ts4_event_value;
    t.f[9] = g_ts4_event_value;
    t.f[10] = g_ts4_event_value;
    t.f[11] = g_ts4_event_value;
    t.f[12] = g_ts4_event_value;
    t.f[13] = g_ts4_event_value;
    t.f[14] = g_ts4_event_value;
    t.f[15] = g_ts4_event_value;
    t.f[16] = g_ts4_event_value;
    t.f[17] = g_ts4_event_value;
    t.f[18] = g_ts4_event_value;
    t.f[19] = g_ts4_event_value;
    t.f[20] = g_ts4_event_value;
    t.f[21] = g_ts4_event_value;
    if (v->end != v->cap) { if (v->end) memcpy(v->end, &t, sizeof t); v->end++; }
    else ts4_vector_grow_append_88227298(v, v->end, &t);
  }
  { Ent *b = m->ents.end - 1; void *k = r->key; b->owner = m; b->key = k; }
  return 1;
}
