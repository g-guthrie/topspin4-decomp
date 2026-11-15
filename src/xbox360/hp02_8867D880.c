#include "vx1_vector.h"

extern const __vector4 lbl_880FC650;
extern const float g_ts4_event_value;

typedef struct Hp02Mover {
    __vector4 a;
    __vector4 b;
    float f20;
    float f24;
} Hp02Mover;

typedef struct Hp02Copy48 {
    unsigned long long q[6];
} Hp02Copy48;

void ts4_mover_clamp_speed_half_vel_88670C20(Hp02Mover *s);

void ts4_mover_init_8867D880(Hp02Mover *s, const Hp02Copy48 *src)
{
    __vector4 c0 = lbl_880FC650;
    __vector4 c1 = lbl_880FC650;
    float zero = g_ts4_event_value;

    s->a = c0;
    s->f20 = zero;
    s->f24 = zero;
    s->b = __vor(c0, c1);
    *(Hp02Copy48 *)s = *src;
    ts4_mover_clamp_speed_half_vel_88670C20(s);
}
