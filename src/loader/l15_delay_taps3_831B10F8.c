/* Loader_DLL.xex 0x831B10F8-0x831B45AC, executable version 0.0.0.3. */
/* Three-tap delay-line reader: scale three delayed samples into the output slots,
 * then push the new input sample. */
typedef struct { float buf[512]; int w, d1, d2, d3; float g1, g2, g3, o1, o2, o3; } Ts4lTaps3x512;

void ts4l_delay_taps3_512_831B10F8(Ts4lTaps3x512 *d, float in)
{
    float x1 = d->buf[(d->w - d->d1) & 511];
    float x2 = d->buf[(d->w - d->d2) & 511];
    float x3 = d->buf[(d->w - d->d3) & 511];
    d->o1 = x1 * d->g1;
    d->o2 = x2 * d->g2;
    d->o3 = x3 * d->g3;
    d->buf[d->w] = in;
    d->w = (d->w + 1) & 511;
}

typedef struct { float buf[2048]; int w, d1, d2, d3; float g1, g2, g3, o1, o2, o3; } Ts4lTaps3x2048;

void ts4l_delay_taps3_2048_831B4538(Ts4lTaps3x2048 *d, float in)
{
    float x1 = d->buf[(d->w - d->d1) & 2047];
    float x2 = d->buf[(d->w - d->d2) & 2047];
    float x3 = d->buf[(d->w - d->d3) & 2047];
    d->o1 = x1 * d->g1;
    d->o2 = x2 * d->g2;
    d->o3 = x3 * d->g3;
    d->buf[d->w] = in;
    d->w = (d->w + 1) & 2047;
}
