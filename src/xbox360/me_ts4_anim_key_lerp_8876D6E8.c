/* Swing_DLL.xex 0x8876D6E8: linearly interpolate an animation channel between keys a and b at frame `t`
   (returns b's value when the keys are closer than the minimum span). */
typedef struct Ts4AnimKey { char pad[8]; float value; unsigned short frame; } Ts4AnimKey;
extern const float lbl_880C960C;
float ts4_anim_key_lerp_8876D6E8(unsigned int t, Ts4AnimKey *a, Ts4AnimKey *b)
{
    if ((float)(int)(b->frame - a->frame) < lbl_880C960C) return b->value;
    return (b->value - a->value) * (float)(t - a->frame) / (float)(int)(b->frame - a->frame) + a->value;
}
