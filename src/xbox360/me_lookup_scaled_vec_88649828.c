/* 0x88649828 (hand match). */
#include "vx1_vector.h"
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Vec { __vector4 v; } Vec;
typedef struct Rec { char p[0xc]; float fc; char q[8]; void *f18; } Rec;
typedef struct Tbl { int rel; } Tbl;
typedef struct C8 { char p[0x60]; Tbl t; } C8;
typedef struct Ba8 { char p[8]; C8 *f8; } Ba8;
typedef struct Obj { char p[0xa8]; Ba8 *fa8; } Obj;
extern u8 ts4_record_table_lookup_88649778(Obj *self, void *key, Rec **rec, u32 *out);
extern void fn_884098E8(void *o, float x, float y, Vec *out);
Vec ts4_lookup_scaled_vec_88649828(Obj *a, int idx, float x, float y){ Rec *rec; u32 tmp; Tbl *t; __vector4 z = __vspltisw(0); Vec r;
 t = &a->fa8->f8->t;
 if (ts4_record_table_lookup_88649778(a, (char *)t + t->rel + idx * 0x1c, &rec, &tmp)) { void *o = rec->f18; float s = rec->fc; if (o != 0) { Vec out; fn_884098E8(o, x * s, y * s, &out); r.v = out.v; return r; } }
 r.v = z; return r; }
