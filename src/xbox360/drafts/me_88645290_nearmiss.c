/* agentB 2026-11-18: still 5 off (plain and LTCG same); per-iteration float t[4] temp with direct __stvewx: 29 off (0xBC). */
/* me_88645290 near-miss: 5 off (plain /Oc). 16 variants total (lane read orders, out++ stepping, Quat4 temp copy, store order). Copy the rotation (+0x10, 4 lanes) of each 0x30-byte record into a
   float[4] output array; sibling of ts4_copy_record_positions_88645AD8. `__restrict` on out (or on l) hoists the
   recs load like the target. Residue: one `addi r6,r1,0x50` is placed before the loop label in ours (inside the loop
   in the target). 8 variants (lane read order, recs local, restrict out/list, per-element pointer, != loop). */
#include "vx1_vector.h"
typedef struct Rec { char p[0x10]; __vector4 rot; char q[0x10]; } Rec;
typedef struct List { Rec *recs; } List;
typedef struct Self { char p[0x24]; void *f24; } Self;
typedef struct Quat4 { float x, y, z, w; } Quat4;
List *ts4_call_seq_fn_884025C0_88402FB0(void *p);
static __inline float plx(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 0), &f, 0); return f; }
static __inline float ply(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 1), &f, 0); return f; }
static __inline float plz(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 2), &f, 0); return f; }
static __inline float plw(const __vector4 *v) { float f; __stvewx(__vspltw(*v, 3), &f, 0); return f; }

void fn_88645290(Self *s, Quat4 *__restrict out, unsigned n)
{
    List *l = ts4_call_seq_fn_884025C0_88402FB0(s->f24);
    unsigned i;
    for (i = 0; i < n; i++) {
        const __vector4 *p = &l->recs[i].rot;
        float w = plw(p), z = plz(p), y = ply(p), x = plx(p);
        out[i].x = x; out[i].y = y; out[i].z = z; out[i].w = w;
    }
}
