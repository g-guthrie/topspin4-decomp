/*
 * 0x88266740: copy constructor of the 132-byte (0x84) item of the std::vector grown by
 * 0x88266840 (me_ts4_vector_realloc_insert_88266840.c calls it for every copied element).
 *
 * The item stores vtable ts4_vtbl_Q5sTrackerItem880F3798 at +0x00 and ts4_vtbl_Ts4TrackerShell880D6B70 at +0x08 and has the same field layout as
 * Ts4Tracker (include/ts4/classes.h) up to +0x80. It is not taken as Ts4Tracker itself: the vector
 * stride says 0x84, while Ts4Tracker is 0x98 (its vector delete 88262730 has stride 0x98). ts4_vtbl_Q5sTrackerItem880F3798
 * holds only a scalar deleting dtor, so two classes can share it through vtable folding. Whether it is a
 * Tracker base or twin is open. The shell and accumulator members use the shared types.
 *
 * Codegen: memberwise copy constructor. +0x38..+0x43 is copied with lwz/stw, not lfs/stfs, so it is one
 * 12-byte POD member (three floats copied as a block). Separate float members give 6 lfs/stfs off.
 * The accumulators (Ts4TrackerAcc, 0x14) are copied with the 5-word lwzu/stwu ctr loops.
 * LTCG route, primer-only context.
 */
#include "include/ts4/ts4.h"
#include "include/ts4/classes.h"

struct Q5sTrackerItemK {              /* +0x38: f_38, scale, f_40 in Ts4Tracker */
    float f_38, scale, f_40;
};

struct Q5sTrackerItem {               /* 0x84, vtable ts4_vtbl_Q5sTrackerItem880F3798 at +0x00 */
    int f_04;                         /* +0x04 */
    Ts4TrackerShell shell;            /* +0x08 vptr ts4_vtbl_Ts4TrackerShell880D6B70 */
    float f_0c, f_10, f_14, f_18;     /* +0x0C */
    float f_1c, f_20, f_24, f_28, f_2c; /* +0x1C */
    int f_30;                         /* +0x30 */
    int f_34;                         /* +0x34 */
    Q5sTrackerItemK k;                /* +0x38 */
    Ts4TrackerAcc a;                  /* +0x44 */
    Ts4TrackerAcc b;                  /* +0x58 */
    int f_6c;                         /* +0x6C */
    float f_70;                       /* +0x70 */
    int f_74, f_78, f_7c;             /* +0x74 */
    unsigned char f_80;               /* +0x80 */
    Q5sTrackerItem(const Q5sTrackerItem &o);
    virtual ~Q5sTrackerItem() {}
};
TS4_ASSERT_SIZE(Q5sTrackerItem, 0x84);

Q5sTrackerItem::Q5sTrackerItem(const Q5sTrackerItem &o)
    : f_04(o.f_04), shell(o.shell), f_0c(o.f_0c), f_10(o.f_10), f_14(o.f_14), f_18(o.f_18),
      f_1c(o.f_1c), f_20(o.f_20), f_24(o.f_24), f_28(o.f_28), f_2c(o.f_2c), f_30(o.f_30),
      f_34(o.f_34), k(o.k), a(o.a), b(o.b), f_6c(o.f_6c), f_70(o.f_70), f_74(o.f_74), f_78(o.f_78),
      f_7c(o.f_7c), f_80(o.f_80)
{
}
