/* Loader_DLL.xex 0x831B1218-0x831B1838, executable version 0.0.0.3.
 * Fixed-size feedback delay lines (allpass-style): read, mix, write, advance both indices. */

typedef struct { float buf[128]; int w, r, pad; float a, b, out; } Ts4lAllpass128;

void ts4l_allpass_128_831B1218(Ts4lAllpass128 *d, float in)
{
    float a = d->a;
    float x = d->buf[d->r];
    float y = a * x + in;
    float b = d->b;
    d->buf[d->w] = y;
    d->out = b * y + x;
    d->r = (d->r + 1) & 127;
    d->w = (d->w + 1) & 127;
}

typedef struct { float buf[256]; int w, r, pad; float a, b, out; } Ts4lAllpass256;

void ts4l_allpass_256_831B1340(Ts4lAllpass256 *d, float in)
{
    float a = d->a;
    float x = d->buf[d->r];
    float y = a * x + in;
    float b = d->b;
    d->buf[d->w] = y;
    d->out = b * y + x;
    d->r = (d->r + 1) & 255;
    d->w = (d->w + 1) & 255;
}

typedef struct { float buf[512]; int w, r, pad; float a, b, out; } Ts4lAllpass512;

void ts4l_allpass_512_831B1420(Ts4lAllpass512 *d, float in)
{
    float a = d->a;
    float x = d->buf[d->r];
    float y = a * x + in;
    float b = d->b;
    d->buf[d->w] = y;
    d->out = b * y + x;
    d->r = (d->r + 1) & 511;
    d->w = (d->w + 1) & 511;
}

typedef struct { float buf[1024]; int w, r, pad; float a, b, out; } Ts4lAllpass1024;

void ts4l_allpass_1024_831B17E8(Ts4lAllpass1024 *d, float in)
{
    float a = d->a;
    float x = d->buf[d->r];
    float y = a * x + in;
    float b = d->b;
    d->buf[d->w] = y;
    d->out = b * y + x;
    d->r = (d->r + 1) & 1023;
    d->w = (d->w + 1) & 1023;
}

typedef struct { float buf[2048]; int w, r, pad; float a, b, out; } Ts4lAllpass2048;

void ts4l_allpass_2048_831B1710(Ts4lAllpass2048 *d, float in)
{
    float a = d->a;
    float x = d->buf[d->r];
    float y = a * x + in;
    float b = d->b;
    d->buf[d->w] = y;
    d->out = b * y + x;
    d->r = (d->r + 1) & 2047;
    d->w = (d->w + 1) & 2047;
}
