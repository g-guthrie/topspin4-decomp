/* nearmiss: 53 diff lines (fn_check_ltcg /Oc --auto-context: w9a_a.c for ts4_obj44_triple_ctor_8869AF98 + pool
   primer). MovePlanner constructor (vtable lbl_880F46F0). All stores/values/relocations agree; the remaining diff is
   list-scheduler placement: the +0 vtable store lands after `mr r7,r3`, and the dead `addi base,0x14` copies of the
   3rd/4th lbl_880D7600 sub-objects are hoisted (the target keeps them late, next to the 0x224 stores), with the
   0x130/0x134 and 0x288/0x28C float stores moving with them. Probed: float pair placement 0..4 (best: A after obj2,
   B after obj4), pair helpers, loops, vtable store position, tail order (no effect); perm_auto ~25 min from this version (-j 3), no improvement over 53.
   Blocker: the sub-object types (two-obj44 aggregate? +0x28 shell class, +0x130 float pair) are not identified; the
   original was probably C++ member construction of typed members. Swing_DLL.xex 0x886A3AC8, 0x1D0 bytes. */
#include "include/ts4/ts4.h"

extern char lbl_880F46F0[];
extern char ts4_vtbl_Ts4TrackerShell880D6B70[];
extern char lbl_880D7600[];
extern const float g_ts4_event_value;
void ts4_obj44_triple_ctor_8869AF98(void *o);

typedef unsigned int MvU32;
typedef struct MvVec { MvU32 *b, *e, *c; } MvVec;
typedef struct MvVec3 { MvVec v0, v1, v2; } MvVec3;
typedef struct MvObj44 { void *vt; MvU32 w04, w08, w0c, w10; MvVec3 m; MvVec x; } MvObj44;
typedef struct MvShell { void *vt; MvU32 w04, w08, w0c; } MvShell;

static __inline void mv_vec_init(MvVec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void mv_vec3_init(MvVec3 *m) { mv_vec_init(&m->v0); mv_vec_init(&m->v1); mv_vec_init(&m->v2); }
static __inline void mv_obj44_init(MvObj44 *s)
{
    s->vt = lbl_880D7600;
    mv_vec3_init(&s->m);
    mv_vec_init(&s->x);
    s->w04 = 0; s->w08 = 0; s->w0c = 0; s->w10 = 0;
}

#define MV_AT(s, off, T) (*(T *)((char *)(s) + (off)))

struct Ts4MovePlanner *ts4_move_planner_ctor_886A3AC8(struct Ts4MovePlanner *self)
{
    MvShell *sh = &MV_AT(self, 0x28, MvShell);
    MV_AT(self, 0x0, void *) = lbl_880F46F0;
    MV_AT(self, 0x10, MvU32) = 0;
    MV_AT(self, 0x18, MvU32) = 0;
    MV_AT(self, 0x14, MvU32) = 0;
    MV_AT(self, 0x20, MvU32) = 0;
    sh->vt = ts4_vtbl_Ts4TrackerShell880D6B70;
    sh->w0c = 0; sh->w04 = 0; sh->w08 = 0;
    ts4_obj44_triple_ctor_8869AF98((char *)self + 0x38);
    mv_obj44_init(&MV_AT(self, 0x158, MvObj44));
    mv_obj44_init(&MV_AT(self, 0x19c, MvObj44));
    MV_AT(self, 0x130, float) = g_ts4_event_value;
    MV_AT(self, 0x134, float) = g_ts4_event_value;
    mv_obj44_init(&MV_AT(self, 0x1e0, MvObj44));
    mv_obj44_init(&MV_AT(self, 0x224, MvObj44));
    MV_AT(self, 0x288, float) = g_ts4_event_value;
    MV_AT(self, 0x28c, float) = g_ts4_event_value;
    self->player = 0;
    MV_AT(self, 0x114, MvU32) = 0;
    MV_AT(self, 0x118, MvU32) = 0;
    MV_AT(self, 0x280, int) = -1;
    MV_AT(self, 0x290, int) = -1;
    MV_AT(self, 0x285, unsigned char) = 0;
    return self;
}
