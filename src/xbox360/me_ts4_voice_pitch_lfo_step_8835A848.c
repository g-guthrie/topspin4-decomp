/* Swing_DLL.xex 0x8835A848: one pitch-LFO step: waveform by shape (table lbl_88B3A4B0, triangle, square), pitch -= depth*amount*w>>23,
 * amount ramps to 0x10000, phase wraps at 0x100, marks the voice dirty. agAE: /Oc. */
typedef struct Lfo { unsigned char rate; unsigned char depth; unsigned char shape; unsigned char ramp; } Lfo;
typedef struct LfoDesc { char pad[0x2c]; Lfo lfo; } LfoDesc;
typedef struct Voice {
    char pad[0x1c0]; LfoDesc *desc; char pad1c4[0x1cc - 0x1c4]; unsigned char dirty; char pad1cd[0x1e0 - 0x1cd];
    int pitch; char pad1e4[0x240 - 0x1e4]; int phase; int amount;
} Voice;
extern const signed char lbl_88B3A4B0[];
int fn_8835A848(void *ctx, Voice *v)
{
    LfoDesc *d = v->desc;
    int w = 0;
    switch (d->lfo.shape) {
    case 1:
        w = (0x80 - (v->phase + 0x80) % 256) >> 1;
        break;
    case 2:
        if (v->phase < 0x80) w = 0x40;
        else w = -0x40;
        break;
    case 0:
    case 3:
        w = lbl_88B3A4B0[v->phase];
        break;
    }
    v->pitch -= (d->lfo.depth * v->amount * w) >> 23;
    v->amount += d->lfo.ramp * 2;
    if (v->amount > 0x10000) v->amount = 0x10000;
    v->phase += d->lfo.rate;
    if (v->phase > 0xff) v->phase -= 0x100;
    v->dirty |= 1;
    return 0;
}
