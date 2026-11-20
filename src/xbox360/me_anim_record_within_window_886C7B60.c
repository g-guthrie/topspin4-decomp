/* 0x886C7B60 (hand match, LTCG route): is the keyed record time within the layer blend window. */
typedef struct Rec { unsigned key; float f4; } Rec;
typedef struct In8 { char p[0x14]; float f14; } In8;
typedef struct Sub { int f0; int f4; In8 *f8; } Sub;
typedef struct Ent { int f0; Sub *f4; char p[0xc]; float f14; char q[0xc]; float f24; } Ent;
typedef struct Lay { char p[0x18]; float f18; char q[0x40]; Ent **f5c; } Lay;
typedef struct Obj { char p[0xc]; Lay *fc; } Obj;
int ts4_anim_layer_index_886C66C0(Lay *l);
Rec *ts4_find_record_by_key_886C7150(void *o, const unsigned *key);
extern float g_ts4_script_constants[]; extern float lbl_880C8F9C;
int ts4_anim_record_within_window_886C7B60(Obj *o, unsigned key){ Lay *l = o->fc; int r = 0; int i = ts4_anim_layer_index_886C66C0(l); Ent *e; Sub *s; Rec *rec; float k, d, inv, lim, v;
 if (i != -1 && (e = l->f5c[i]) != 0) { s = e->f4; rec = ts4_find_record_by_key_886C7150(&s->f4, &key);
  if (rec) { k = g_ts4_script_constants[0]; d = s->f8->f14 - k; lim = (e->f14 * d + (l->f18 + k - e->f24)) * (k / d); v = rec->f4;
   if (key == 0xAA06A2F1u) v = v + (k / d) * lbl_880C8F9C;
   if (v <= lim) r = 1; } }
 return r; }
