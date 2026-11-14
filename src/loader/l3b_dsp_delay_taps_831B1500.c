/* Loader_DLL.xex 0x831B10A8-0x831B44E8, executable version 0.0.0.3.
 * Fixed-size delay-line helpers: tap readers and reset routines. */

extern float lbl_830009F8;
extern void *fn_833E3A30(void *, int, unsigned);
typedef struct { float buf[1024]; int pos, d1, d2; float g1, g2, o1, o2; } Ts4lTaps1024;
typedef struct { float buf[4096]; int pos, d1, d2; float g1, g2, o1, o2; } Ts4lTaps4096;
typedef struct { float buf[512]; int pos; float pad[6]; float a, b, c; } Ts4lReset512;
typedef struct { float buf[2048]; int pos; float pad[6]; float a, b, c; } Ts4lReset2048;

void ts4l_delay_taps_1024_831B1500(Ts4lTaps1024 *d, float in)
{
    float x2 = d->buf[(d->pos - d->d2) & 1023];
    float x1 = d->buf[(d->pos - d->d1) & 1023];
    float y2 = x2 * d->g2;
    float y1 = x1 * d->g1;
    d->o1 = y1;
    d->o2 = y2;
    d->buf[d->pos] = in;
    d->pos = (d->pos + 1) & 1023;
}

void ts4l_delay_taps_4096_831B15E0(Ts4lTaps4096 *d, float in)
{
    float x2 = d->buf[(d->pos - d->d2) & 4095];
    float x1 = d->buf[(d->pos - d->d1) & 4095];
    float y2 = x2 * d->g2;
    float y1 = x1 * d->g1;
    d->o1 = y1;
    d->o2 = y2;
    d->buf[d->pos] = in;
    d->pos = (d->pos + 1) & 4095;
}

void ts4l_delay_reset_512_831B10A8(Ts4lReset512 *d)
{
    fn_833E3A30(d, 0, 0x800);
    d->pos = 0;
    d->a = lbl_830009F8;
    d->b = d->a;
    d->c = d->a;
}

void ts4l_delay_reset_2048_831B44E8(Ts4lReset2048 *d)
{
    fn_833E3A30(d, 0, 0x2000);
    d->pos = 0;
    d->a = lbl_830009F8;
    d->b = d->a;
    d->c = d->a;
}

void ts4l_delay_reset_16384_831B1910(char *d)
{
    float z;
    fn_833E3A30(d, 0, 0x10000);
    z = lbl_830009F8;
    *(int *)(d + 0x10000) = 0;
    *(float *)(d + 0x10018) = z;
}
