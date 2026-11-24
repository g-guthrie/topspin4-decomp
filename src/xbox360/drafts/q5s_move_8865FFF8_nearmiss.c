/* nearmiss: 1 off (fn_check_ltcg /Oc + pp1_pool_primer.c): the last `fadds f10,f13,f11` (blend + step) comes out
   `fadds f10,f11,f13`. Round 5 fix: the else value is g_ts4_event_value (BINKCONS 0.0f), not a literal, so all
   relocations agree. Tried: += / swapped operands / temporaries / lerp(a,b,t) in four forms; perm_auto 400s (94
   candidates) no gain. Blocker: commutative fadds operand order (same open class as 8864E640 in matching-tips). */
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;
struct Ts4BlendTarget { unsigned char pad_000[0x4F0]; float blend; };
struct Ts4BlendHolder { unsigned char pad_00[0x78]; struct Ts4BlendTarget *target; };
struct Ts4RelFlags { int rel; };
struct Ts4BlendState {
    unsigned char pad_00[0x18];
    struct Ts4BlendHolder *holder;
    unsigned char pad_1c[4];
    unsigned char *flags;
};
#ifdef _MSC_VER
#pragma fp_contract(off)
#endif
static void ease(float *b, float g) { *b = *b + (g - *b) * g_ts4_script_constants[0x2AC / 4]; }
void ts4_ease_blend_to_flag_8865FFF8(struct Ts4BlendState *self)
{
    float *bl = &self->holder->target->blend;
    struct Ts4RelFlags *r = (struct Ts4RelFlags *)(self->flags + 0x10);
    float goal;
    if (*((unsigned char *)r - r->rel + 0x10))
        goal = g_ts4_script_constants[0];
    else
        goal = g_ts4_event_value;
    ease(bl, goal);
}
