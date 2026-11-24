/* Loader_DLL.xex 0x831B0500-0x831B1790, executable version 0.0.0.3.
 * Reset functions of fixed-size float delay lines. */

extern float lbl_830009F8;
extern void *fn_833E3A30(void *, int, unsigned);

typedef struct { float buf[2048]; int head, tail, delay; float pad[3]; float level; } Ts4lDelay831B0500;

void ts4l_reset_delay_line_831B0500(Ts4lDelay831B0500 *d)
{
    fn_833E3A30(d, 0, 0x2000);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 2047;
}

typedef struct { float buf[128]; int head, tail, delay; float pad[2]; float level; } Ts4lDelay831B11C0;

void ts4l_reset_delay_line_831B11C0(Ts4lDelay831B11C0 *d)
{
    fn_833E3A30(d, 0, 0x200);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 127;
}

typedef struct { float buf[256]; int head, tail, delay; float pad[2]; float level; } Ts4lDelay831B12E8;

void ts4l_reset_delay_line_831B12E8(Ts4lDelay831B12E8 *d)
{
    fn_833E3A30(d, 0, 0x400);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 255;
}

typedef struct { float buf[512]; int head, tail, delay; float pad[2]; float level; } Ts4lDelay831B13C8;

void ts4l_reset_delay_line_831B13C8(Ts4lDelay831B13C8 *d)
{
    fn_833E3A30(d, 0, 0x800);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 511;
}

typedef struct { float buf[2048]; int head, tail, delay; float pad[2]; float level; } Ts4lDelay831B16B8;

void ts4l_reset_delay_line_831B16B8(Ts4lDelay831B16B8 *d)
{
    fn_833E3A30(d, 0, 0x2000);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 2047;
}

typedef struct { float buf[1024]; int head, tail, delay; float pad[2]; float level; } Ts4lDelay831B1790;

void ts4l_reset_delay_line_831B1790(Ts4lDelay831B1790 *d)
{
    fn_833E3A30(d, 0, 0x1000);
    d->head = 0;
    d->level = lbl_830009F8;
    d->tail = -d->delay & 1023;
}
