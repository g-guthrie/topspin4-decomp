/* 0x883DF888: scales the value by the unit factor (1: 0.25, 2: 1/48, 3: 1/24), stores it at +0x28 and forwards exp2(v * 4) (vexptefp) to the sink at +0x44 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the four multiplier constants are float literals (the labels lbl_88001B14/88039028/8802E88C/88039494 hold the same bytes); the externs swap the fmuls operands. */
#include "ts4_vector.h"
typedef __vector4 V;
extern const float lbl_88001A68;
typedef struct T { char pad[0x28]; float gain; char pad2[0x44 - 0x2c]; void *sink; } T;
int ts4_fetch_then_use_float_88317AF0(void *sink, float v);
int ts4_set_gain_exp_883DF888(T *t, float v, int unit)
{
    switch (unit) {
    case 1:
        v *= 0.25f;
        break;
    case 2:
        v *= 0.020833334f;
        break;
    case 3:
        v *= 0.041666668f;
        break;
    }
    t->gain = v;
    if (t->sink) {
        V e;
        int r;
        e.v[0] = v * 4.0f;
        e.v[1] = lbl_88001A68;
        e.v[2] = lbl_88001A68;
        e.v[3] = lbl_88001A68;
        e = __vexptefp(e);
        r = ts4_fetch_then_use_float_88317AF0(t->sink, e.v[0]);
        if (r)
            return r;
    }
    return 0;
}
