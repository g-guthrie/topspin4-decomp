/* nearmiss: 15 off (LTCG /Oc, pool primer); vector regs match; target computes (idx*0x1070 + arr) + arr->off and numbers the product r10, ours (prod + off) + arr. Blocker: every rel/operator[] spelling canonicalises to ours (C1). */
#include "vx1_vector.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Slot { char pad0[0xff0]; __vector4 pos; u8 active; char pad1001[3]; u32 f1004; float f1008; char pad100c[0x1070 - 0x100c]; } Slot;
typedef struct RelArr { int off; } RelArr;
typedef struct Mgr { char pad0[0xe80]; RelArr slots; } Mgr;
typedef struct Flags { char pad0[0xf0]; u8 paused; } Flags;
typedef struct Self { Mgr *mgr; char pad4[0x1c]; Flags *flags; } Self;
typedef struct Ev { char pad0[0x42c]; int idx; float x, y, z; u32 f43c; float f440; } Ev;
static __inline Slot *rel_slot(RelArr *a, int i) { return (Slot *)((char *)a + i * sizeof(Slot) + a->off); }
#define M 8
#define R 0
static __inline void set_x(__vector4 *v, const float *x) { __vector4 t = __lvlx(x, 0); *v = __vrlimi(*v, t, M, R); }
#undef M
#undef R
#define M 4
#define R 3
static __inline void set_y(__vector4 *v, const float *x) { __vector4 t = __lvlx(x, 0); *v = __vrlimi(*v, t, M, R); }
#undef M
#undef R
#define M 2
#define R 2
static __inline void set_z(__vector4 *v, const float *x) { __vector4 t = __lvlx(x, 0); *v = __vrlimi(*v, t, M, R); }
void ts4_input_on_slot_update_88916F48(Self *self, Ev *ev)
{
    Slot *s;
    if (self->flags->paused)
        return;
    s = rel_slot(&self->mgr->slots, ev->idx);
    s->pos = vx1_set_x(s->pos, ev->x);
    s->pos = vx1_set_y(s->pos, ev->y);
    s->pos = vx1_set_z(s->pos, ev->z);
    s->f1004 = ev->f43c;
    s->f1008 = ev->f440;
    s->active = 1;
}
