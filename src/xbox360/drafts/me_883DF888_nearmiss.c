/* 0x883DF888 near miss (2 off on /O1): both fmuls have swapped operands (target fmuls f1,f1,f0 / f13,f1,f13); v*k, k*v, *= and a merged k local all give the same order. */
#include "ts4_vector.h"
typedef __vector4 V;
extern const float lbl_88001B14;
extern const float lbl_88039028;
extern const float lbl_8802E88C;
extern const float lbl_88039494;
extern const float lbl_88001A68;
typedef struct T { char pad[0x28]; float gain; char pad2[0x44 - 0x2c]; void *sink; } T;
int ts4_fetch_then_use_float_88317AF0(void *sink, float v);
int ts4_set_gain_exp_883DF888(T *t, float v, int unit)
{
    switch (unit) {
    case 1:
        v *= lbl_88001B14;
        break;
    case 2:
        v *= lbl_88039028;
        break;
    case 3:
        v *= lbl_8802E88C;
        break;
    }
    t->gain = v;
    if (t->sink) {
        V e;
        int r;
        e.v[0] = v * lbl_88039494;
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
