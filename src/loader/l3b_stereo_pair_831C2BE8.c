/* Loader_DLL.xex 0x831C2BE8-0x8325AF78, executable version 0.0.0.3.
 * Stereo pair split into difference/sum halves with optional joint-channel averaging. */

#ifdef _MSC_VER
#define TS4L_INLINE static __forceinline
#else
#define TS4L_INLINE static inline
#endif

typedef struct { char pad[0x8c]; int x8c; int x90; int x94; int x98; int x9c; } Ts4lStereoCfg;

TS4L_INLINE void ts4l_average_pair(short *p, short *q)
{
    short m = (short)((*p + *q) / 2);
    *p = m;
    *q = m;
}

void ts4l_stereo_split_831C2BE8(Ts4lStereoCfg *o, int mode, short a, short b, short *p, short *q)
{
    if (a >= b) {
        *p = 0;
        *q = b;
    } else {
        *p = (short)((b - a) / 2);
        *q = (short)((b + a) / 2);
    }
    if (mode == 1) {
        if (o->x8c == 1 && o->x94 == 0)
            ts4l_average_pair(p, q);
    } else {
        if (o->x8c == 1 && o->x9c == 0)
            ts4l_average_pair(p, q);
    }
}

void ts4l_stereo_split_8325AEA8(Ts4lStereoCfg *o, int mode, short a, short b, short *p, short *q)
{
    if (a >= b) {
        *p = 0;
        *q = b;
    } else {
        *p = (short)((b - a) / 2);
        *q = (short)((b + a) / 2);
    }
    if (mode == 1) {
        if (o->x8c == 1 && o->x94 == 0)
            ts4l_average_pair(p, q);
    } else {
        if (o->x8c == 1 && o->x9c == 0)
            ts4l_average_pair(p, q);
    }
}

void ts4l_stereo_split_offset_831C2CB8(Ts4lStereoCfg *o, int mode, short a, short b, int off, short *p, short *q)
{
    if (b >= a) {
        *p = off;
        *q = (short)(off * 2);
    } else {
        *p = (short)((a - b) / 2 + off);
        *q = (short)((a + b) / 2 + off);
    }
    if (mode == 1) {
        if (o->x8c == 1 && o->x9c == 0)
            ts4l_average_pair(p, q);
    } else {
        if (o->x8c == 1 && o->x94 == 0)
            ts4l_average_pair(p, q);
    }
}

void ts4l_stereo_split_offset_8325AF78(Ts4lStereoCfg *o, int mode, short a, short b, int off, short *p, short *q)
{
    if (b >= a) {
        *p = off;
        *q = (short)(off * 2);
    } else {
        *p = (short)((a - b) / 2 + off);
        *q = (short)((a + b) / 2 + off);
    }
    if (mode == 1) {
        if (o->x8c == 1 && o->x9c == 0)
            ts4l_average_pair(p, q);
    } else {
        if (o->x8c == 1 && o->x94 == 0)
            ts4l_average_pair(p, q);
    }
}
