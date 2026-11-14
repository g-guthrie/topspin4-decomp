/* Loader_DLL.xex 0x830B1390-0x830B27A8, executable version 0.0.0.3. */
/* D3D device state setters: store a value, then OR a bit into a 64-bit dirty mask. */
typedef unsigned int u32;
typedef struct { u32 hi:30; u32 lo:2; } l34_bf2_t;
typedef struct { u32 hi:31; u32 lo:1; } l34_bf1_t;
extern float lbl_83084840[];

int ts4l_get_scaled_bits_830B1AA8(char *p)
{
    float r = *(float *)(p + 0x2a50) * lbl_83084840[0x170 / 4];
    return *(int *)&r;
}

void ts4l_set_scaled_u32_830B1390(char *p, u32 v)
{
    long long *f;
    *(float *)(p + 0x2904) = (float)v * lbl_83084840[0x34 / 4];
    f = (long long *)(p + 0x10);
    *f |= 0x8000000LL;
}

void ts4l_set_bits_830B26A0(char *p, int v)
{
    long long *f;
    *(int *)(p + 0x28d8) = v;
    f = (long long *)(p + 0x10);
    *f |= (long long)1 << 38;
}

void ts4l_set_float_830B2590(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x2980) = *(float *)&v;
    f = (long long *)(p + 0x18);
    *f |= (long long)1 << 47;
}

void ts4l_set_float_830B25C8(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x297c) = *(float *)&v;
    f = (long long *)(p + 0x18);
    *f |= (long long)1 << 48;
}

void ts4l_set_float_830B2720(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x29cc) = *(float *)&v;
    f = (long long *)(p + 0x20);
    *f |= (long long)1 << 32;
}

void ts4l_set_float_830B2750(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x29c4) = *(float *)&v;
    f = (long long *)(p + 0x20);
    *f |= (long long)1 << 34;
}

void ts4l_set_float_830B27A8(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x29c8) = *(float *)&v;
    f = (long long *)(p + 0x20);
    *f |= (long long)1 << 33;
}

void ts4l_set_float_830B2780(char *p, int v)
{
    long long *f;
    *(float *)(p + 0x29d0) = *(float *)&v;
    f = (long long *)(p + 0x20);
    *f |= 0x80000000LL;
}

void ts4l_set_bf2_830B2600(char *p, int v)
{
    long long *f;
    ((l34_bf2_t *)(p + 0x2978))->lo = v;
    f = (long long *)(p + 0x18);
    *f |= (long long)1 << 49;
}

void ts4l_set_bf1_830B2638(char *p, int v)
{
    long long *f;
    ((l34_bf1_t *)(p + 0x29c0))->lo = v;
    f = (long long *)(p + 0x20);
    *f |= (long long)1 << 35;
}
