/* NEAR MISS fn_8867A970: 1 off (fadds operand order f0,f13 vs f13,f0), LTCG + pp1_pool_primer.c, /Oc. ~14 variants: k+in, in+k, ternary, init-then-if, temp struct, compound add, pointer select.  +11 (ME sweep): inline side_k/rad_of/addf/rot helpers in both orders, restrict store, volatile read, float local, temp struct - all 1 off (or worse). */
/* nearmiss: 1 off (nmF, 2026-11-24); blocker: target fadds (phi k, load in->rad) is against C1 (load before variable). Not moved by: float literals for pi/0 (the lever that fixed 8843F788/88472A88), r = in->rad read before the if, in->rad stored to out then += k, block-scoped struct temps, C++ struct return with NRVO (r3 = return slot, r4 = this: register layout fits as ?CourtAngle@PC@@ member), C++ member of the angle class (this = out), and a 1111-candidate perm_auto run (540 s). */
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
