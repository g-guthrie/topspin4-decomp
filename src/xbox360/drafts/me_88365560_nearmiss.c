/* Swing_DLL.xex 0x88365560: MOD-style vibrato step: waveform (sine table lbl_88B3A48C, ramp, square, CRT rand) by waveCtl & 3,
 * out->vibrato = +/-(depth * wave) >> 7, position advances by speed and wraps at 0x20. agAE: /Oc.
 * NEAR MISS (register-only, 5 lines): an `int` return type on vib_wave (with the ramp inline still u8) produces the
 * target`s join clrlwi. Left: the position-advance add/extsb takes r9/r7 in the target and r7/r6 here. These made no difference:
 * the advance as an inline, `= a + b` forms, the ternary or signed-test negate, and an unsigned speed. 88365328 (`>> 7 << 2`) is also
 * exactly 5 off with this template. */
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
static __inline int vib_wave(Channel *c)
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
