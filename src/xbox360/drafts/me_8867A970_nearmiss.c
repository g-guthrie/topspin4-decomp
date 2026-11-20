/* NEAR MISS fn_8867A970: 1 off (fadds operand order f0,f13 vs f13,f0), LTCG + pp1_pool_primer.c, /Oc. ~14 variants: k+in, in+k, ternary, init-then-if, temp struct, compound add, pointer select.  +11 (ME sweep): inline side_k/rad_of/addf/rot helpers in both orders, restrict store, volatile read, float local, temp struct - all 1 off (or worse). */
/* Swing_DLL.xex 0x8867A970: angle in court space: add pi on the far side (style 0xA2EDA1E7), then wrap. */
typedef unsigned char ts4_u8;
struct Ts4AnAngle { float rad; };
extern float lbl_880C88DC;            /* pi */
extern const float g_ts4_event_value;  /* 0.0f */
void fn_8817B608(struct Ts4AnAngle *angle);
struct Ts4AnCourt { ts4_u8 pad_00[0xB0]; int style; };
struct Ts4AnLink { ts4_u8 pad_00[0x24]; struct Ts4AnCourt *court; };
struct Ts4AnPC { ts4_u8 pad_00[0x4C]; struct Ts4AnLink *link; };

struct Ts4AnAngle *ts4_angle_to_court_8867A970(struct Ts4AnAngle *out, struct Ts4AnPC *pc, const struct Ts4AnAngle *in)
{
    float k;
    if (pc->link->court->style == (int)0xA2EDA1E7u)
        k = lbl_880C88DC;
    else
        k = g_ts4_event_value;
    out->rad = k + in->rad;
    fn_8817B608(out);
    return out;
}
