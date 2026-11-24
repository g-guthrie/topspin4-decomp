/* 0x88645AD8 (hand match): copy the position (x, y, z, 0) of each 0x30-byte record into the output array. */
#include "vx1_vector.h"
typedef struct Rec { char p[0x20]; __vector4 pos; } Rec;
typedef struct List { Rec *recs; } List;
typedef struct Self { char p[0x24]; void *f24; } Self;
List *ts4_call_seq_fn_884025C0_88402FB0(void *p);
static __inline float plx(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 0), &f, 0); return f; }
static __inline float ply(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 1), &f, 0); return f; }
static __inline float plz(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 2), &f, 0); return f; }
static __inline __vector4 make(float x, float y, float z, float w) { __vector4 t; t.v[0] = x; t.v[1] = y; t.v[2] = z; t.v[3] = w; return t; }
static __inline __vector4 make3(float x, float y, float z) { __vector4 t; t.v[0] = x; t.v[1] = y; t.v[2] = z; t.v[3] = 0.0f; return t; }
void ts4_copy_record_positions_88645AD8(Self *s, __vector4 *out, unsigned n)
{
    List *l = ts4_call_seq_fn_884025C0_88402FB0(s->f24);
    unsigned i;
    for (i = 0; i < n; i++) { const __vector4 *p = &l->recs[i].pos; out[i] = make(plx(p), ply(p), plz(p), 0.0f); }
}
