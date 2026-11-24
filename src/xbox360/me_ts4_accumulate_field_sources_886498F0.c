/* 0x886498F0: resets the accumulator vector (+0x50) and weight (+0x60), sums one vector per 0x1c-byte source entry (lattice gradient pair for sources at or above the event threshold, else a scaled record lookup), then scales acc.z and the weight by 1.0 (mode 1) or the +0x1c factor. LTCG route, /Ob1. */
#include "vx1_vector.h"
typedef unsigned int u32; typedef unsigned char u8;
extern const float g_ts4_event_value;
typedef struct Vec { __vector4 v; } Vec;
typedef struct Acc { __int64 lo, hi; } Acc;
typedef struct Rec { char p[0xc]; float fc; char q[8]; void *f18; } Rec;
typedef struct Grid { char p[0x10]; float f10; } Grid;
typedef struct Elem { int f0; Grid *g; float x; float y; char pad[0xc]; } Elem;
typedef struct Self { Elem *begin; Elem *end; char p[0x14]; float f1c; char q[0x30]; Acc acc; float f60; char t[0xbc-0x64]; int fbc; } Self;
extern u8 ts4_record_table_lookup_88649778(Self *self, Grid *key, Rec **rec, u32 *out);
extern void fn_884098E8(void *o, float x, float y, Vec *out);
void fn_88644CE8(Self *n, Grid *g, float u, float v, float *out_a, float *out_b);
void ts4_accumulate_field_sources_886498F0(Self *self)
{
    u32 n, i; float k; Vec out; float zero = g_ts4_event_value;
    self->f60 = zero;
    *(__vector4 *)&self->acc = __vspltisw(0);
    n = (u32)(self->end - self->begin);
    for (i = 0; i < n; i++) {
        Elem *e = &self->begin[i];
        Grid *g = e->g;
        if (g) {
            float y = e->y, x = e->x; __vector4 v;
            if (!(g->f10 < zero)) {
                float a, b; Vec t;
                fn_88644CE8(self, g, x, y, &a, &b);
                ((float*)&t)[0] = a; ((float*)&t)[1] = zero; ((float*)&t)[2] = b; ((float*)&t)[3] = zero;
                v = t.v;
            } else {
                Rec *rec; u32 tmp;
                out.v = __vxor(out.v,out.v);
                if (ts4_record_table_lookup_88649778(self, g, &rec, &tmp)) { void *o = rec->f18;
                    if (o) { float s = rec->fc; fn_884098E8(o, s * x, s * y, &out); } }
                v = out.v;
            }
            { Acc r; *(__vector4 *)&r = __vaddfp(v, *(__vector4 *)&self->acc); self->acc = r; }
        }
    }
    if (self->fbc != 1) k = self->f1c; else k = 1.0f;
    vx1_vec_set_z((Vx1Vec *)&self->acc, vx1_vec_z((Vx1Vec *)&self->acc) * k);
    self->f60 = k * self->f60;
}
