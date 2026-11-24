/* Loader_DLL.xex 0x831BBA00-0x83268C58, executable version 0.0.0.3.
 * Small paired helpers: stream block geometry, fixed-point interpolation, 6-word compare. */

#ifdef _MSC_VER
typedef __int64 ts4l_i64;
#else
typedef long long ts4l_i64;
#endif
typedef struct { char pad[0x58]; int x58; unsigned x5c, x60; int x64; char pad2[6]; unsigned short u6e; } Ts4lBlockGeom;
typedef struct { char pad[0xc8]; int base; int slope; int knee; } Ts4lRamp;
typedef struct { unsigned w0, w1, w2, w3, w4; int w5; } Ts4lSix;

int ts4l_block_geometry_831BBA00(Ts4lBlockGeom *o)
{
    if (o->x64 == 0) {
        o->x60 = ((unsigned)o->u6e * 4 - 4) | (o->x58 - 1);
    } else if (o->x64 == 1) {
        o->x60 = 0;
    }
    o->x5c = o->x58 << 3;
    return 0;
}

int ts4l_block_geometry_83252A30(Ts4lBlockGeom *o)
{
    if (o->x64 == 0) {
        o->x60 = ((unsigned)o->u6e * 4 - 4) | (o->x58 - 1);
    } else if (o->x64 == 1) {
        o->x60 = 0;
    }
    o->x5c = o->x58 << 3;
    return 0;
}

int ts4l_ramp_value_831C7988(Ts4lRamp *o, int x)
{
    if (x <= o->knee)
        return o->base;
    return (int)(((ts4l_i64)(x - o->knee) * (ts4l_i64)o->slope) >> 20) + o->base - x + o->knee;
}

int ts4l_ramp_value_832624A8(Ts4lRamp *o, int x)
{
    if (x <= o->knee)
        return o->base;
    return (int)(((ts4l_i64)(x - o->knee) * (ts4l_i64)o->slope) >> 20) + o->base - x + o->knee;
}

int ts4l_six_words_equal_831CDEF0(const Ts4lSix *a, const Ts4lSix *b)
{
    return a->w0 == b->w0 && a->w1 == b->w1 && a->w2 == b->w2 && a->w3 == b->w3 && a->w4 == b->w4 && a->w5 == b->w5;
}

int ts4l_six_words_equal_83268C58(const Ts4lSix *a, const Ts4lSix *b)
{
    return a->w0 == b->w0 && a->w1 == b->w1 && a->w2 == b->w2 && a->w3 == b->w3 && a->w4 == b->w4 && a->w5 == b->w5;
}
