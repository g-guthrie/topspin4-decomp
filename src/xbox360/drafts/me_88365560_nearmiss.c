/* Swing_DLL.xex 0x88365560: MOD-style vibrato step: waveform (sine table lbl_88B3A48C, ramp, square, CRT rand) by waveCtl & 3,
 * out->vibrato = +/-(depth * wave) >> 7, position advances by speed and wraps at 0x20. agAE: /Oc.
 * NEAR MISS (1 instruction): the target has one more `clrlwi r11,r11,24` at the join after the ramp case (both paths). These
 * did not add it: the ramp inline returning int/u16, explicit (u8) casts, ~v, and the ramp written inline in the case. A ternary
 * moves the clrlwi before the branch (24 off). Siblings 88361168 (same, `>> 7 << 2`) and 88368958 (tremolo, out +0x1DC, clamps 0..0x40) share the template. */
typedef struct Ptd { char pad[0x60]; unsigned int holdrand; } Ptd;
extern Ptd *lbl_88B3302C;
extern const unsigned char lbl_88B3A48C[32];
typedef struct VoiceOut { char pad[0x1cc]; unsigned char dirty; char pad1cd[0x1e0 - 0x1cd]; int vibrato; } VoiceOut;
typedef struct Channel {
    VoiceOut *out; char pad4[0x286 - 4]; signed char vibPos; signed char vibSpeed; unsigned char vibDepth;
    char pad289[0x2a6 - 0x289]; unsigned char waveCtl;
} Channel;
static __inline int ts4_rand(void)
{
    lbl_88B3302C->holdrand = lbl_88B3302C->holdrand * 214013 + 2531011;
    return (lbl_88B3302C->holdrand >> 16) & 0x7fff;
}
static __inline unsigned char ramp_down(unsigned char pos, signed char raw)
{
    unsigned char v = pos << 3;
    if (raw < 0) v = 0xff - v;
    return v;
}
static __inline unsigned char vib_wave(Channel *c)
{
    unsigned char pos = c->vibPos & 0x1f;
    switch (c->waveCtl & 3) {
    case 0: return lbl_88B3A48C[pos];
    case 1: return ramp_down(pos, c->vibPos);
    case 2: return 0xff;
    case 3: return (unsigned char)ts4_rand();
    }
    return 0;
}
int fn_88365560(Channel *c)
{
    VoiceOut *o = c->out;
    int delta = (c->vibDepth * vib_wave(c)) >> 7;
    if ((unsigned char)c->vibPos >= 0x80) delta = -delta;
    o->vibrato = delta;
    c->vibPos += c->vibSpeed;
    if (c->vibPos > 0x1f) c->vibPos -= 0x40;
    o->dirty |= 1;
    return 0;
}
