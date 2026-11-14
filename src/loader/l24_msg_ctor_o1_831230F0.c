/* Loader_DLL.xex 0x83123180-0x831240E8, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Message header initialiser: zero a 5-word header, then tag it with a type and id. */
typedef struct ts4l_hdr { int w[5]; } ts4l_hdr;
TS4L_NOINLINE static void ts4_set_u32_off0_831230F0(void *m, int id)
{
    volatile ts4l_hdr *h = (volatile ts4l_hdr *)m;
    h->w[0] = 0; h->w[1] = 0; h->w[2] = 0; h->w[3] = 0; h->w[4] = 0;
    h->w[0] = 20; h->w[1] = id;
}
extern void *fn_83123118(void *m, void *buf, int n);

typedef struct ts4l_msg_83123180 { int f0; } ts4l_msg_83123180;
void ts4l_msg_ctor_4_83123180(void *m, ts4l_msg_83123180 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 4);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831231D0 { int f0; } ts4l_msg_831231D0;
void ts4l_msg_ctor_32_831231D0(void *m, ts4l_msg_831231D0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 32);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123220 { int f0; int f4; int f8; } ts4l_msg_83123220;
void ts4l_msg_ctor_5_83123220(void *m, ts4l_msg_83123220 *buf, int a5, int a6, int a7)
{
    ts4_set_u32_off0_831230F0(m, 5);
    fn_83123118(m, buf, 12);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
}

typedef struct ts4l_msg_83123268 { long long f0; } ts4l_msg_83123268;
void ts4l_msg_ctor_3_83123268(void *m, ts4l_msg_83123268 *buf, long long a5)
{
    ts4_set_u32_off0_831230F0(m, 3);
    fn_83123118(m, buf, 12);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831232F0 { int f0; int f4; int f8; int f12; int f16; } ts4l_msg_831232F0;
void ts4l_msg_ctor_0_831232F0(void *m, ts4l_msg_831232F0 *buf, int a5, int a6, int a7)
{
    ts4_set_u32_off0_831230F0(m, 0);
    fn_83123118(m, buf, 20);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
    buf->f12 = 0;
    buf->f16 = 0;
}

typedef struct ts4l_msg_831233F0 { int f0; } ts4l_msg_831233F0;
void ts4l_msg_ctor_18_831233F0(void *m, ts4l_msg_831233F0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 18);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123478 { int f0; } ts4l_msg_83123478;
void ts4l_msg_ctor_24_83123478(void *m, ts4l_msg_83123478 *buf)
{
    ts4_set_u32_off0_831230F0(m, 24);
    fn_83123118(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_831234C0 { int f0; } ts4l_msg_831234C0;
void ts4l_msg_ctor_34_831234C0(void *m, ts4l_msg_831234C0 *buf)
{
    ts4_set_u32_off0_831230F0(m, 34);
    fn_83123118(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_83123508 { int f0; } ts4l_msg_83123508;
void ts4l_msg_ctor_2051_83123508(void *m, ts4l_msg_83123508 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2051);
    fn_83123118(m, buf, 20);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123558 { int f0; int f4; int f8; int f12; int f16; } ts4l_msg_83123558;
void ts4l_msg_ctor_2052_83123558(void *m, ts4l_msg_83123558 *buf, int a5, int a6, int a7, int a8, int a9)
{
    ts4_set_u32_off0_831230F0(m, 2052);
    fn_83123118(m, buf, 20);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
    buf->f12 = a8;
    buf->f16 = a9;
}

typedef struct ts4l_msg_83123848 { int f0; } ts4l_msg_83123848;
void ts4l_msg_ctor_2001_83123848(void *m, ts4l_msg_83123848 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2001);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831238D0 { int f0; } ts4l_msg_831238D0;
void ts4l_msg_ctor_2003_831238D0(void *m, ts4l_msg_831238D0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2003);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123958 { int f0; } ts4l_msg_83123958;
void ts4l_msg_ctor_2040_83123958(void *m, ts4l_msg_83123958 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2040);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831239E0 { int f0; int f4; } ts4l_msg_831239E0;
void ts4l_msg_ctor_2006_831239E0(void *m, ts4l_msg_831239E0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2006);
    fn_83123118(m, buf, 16);
    buf->f4 = a5;
    buf->f0 = 1;
}

typedef struct ts4l_msg_83123A70 { int f0; } ts4l_msg_83123A70;
void ts4l_msg_ctor_2008_83123A70(void *m, ts4l_msg_83123A70 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2008);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123AC0 { int f0; } ts4l_msg_83123AC0;
void ts4l_msg_ctor_2009_83123AC0(void *m, ts4l_msg_83123AC0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2009);
    fn_83123118(m, buf, 8);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123B10 { int f0; } ts4l_msg_83123B10;
void ts4l_msg_ctor_2012_83123B10(void *m, ts4l_msg_83123B10 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2012);
    fn_83123118(m, buf, 8);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123B98 { int f0; } ts4l_msg_83123B98;
void ts4l_msg_ctor_2011_83123B98(void *m, ts4l_msg_83123B98 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2011);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123D48 { int f0; int f4; int f8; } ts4l_msg_83123D48;
void ts4l_msg_ctor_2017_83123D48(void *m, ts4l_msg_83123D48 *buf, int a5, int a6, int a7)
{
    ts4_set_u32_off0_831230F0(m, 2017);
    fn_83123118(m, buf, 28);
    buf->f0 = a5;
    buf->f8 = a7;
    buf->f4 = a6;
}

typedef struct ts4l_msg_83123D90 { int f0; int f4; int f8; int f12; } ts4l_msg_83123D90;
void ts4l_msg_ctor_2016_83123D90(void *m, ts4l_msg_83123D90 *buf, int a5, int a6, int a7, int a8)
{
    ts4_set_u32_off0_831230F0(m, 2016);
    fn_83123118(m, buf, 40);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
    buf->f12 = a8;
}

typedef struct ts4l_msg_83123DE0 { int f0; int f4; int f8; char pad16[4]; int f16; int f20; int f24; } ts4l_msg_83123DE0;
void ts4l_msg_ctor_2018_83123DE0(void *m, ts4l_msg_83123DE0 *buf, int a5, int a6, int a7, int a8, int a9, int a10)
{
    ts4_set_u32_off0_831230F0(m, 2018);
    fn_83123118(m, buf, 28);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
    buf->f16 = a8;
    buf->f20 = a9;
    buf->f24 = a10;
}

typedef struct ts4l_msg_83123E40 { int f0; } ts4l_msg_83123E40;
void ts4l_msg_ctor_2019_83123E40(void *m, ts4l_msg_83123E40 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2019);
    fn_83123118(m, buf, 8);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123ED0 { int f0; } ts4l_msg_83123ED0;
void ts4l_msg_ctor_2024_83123ED0(void *m, ts4l_msg_83123ED0 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2024);
    fn_83123118(m, buf, 8);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83123F20 { int f0; int f4; float f8; float f12; } ts4l_msg_83123F20;
void ts4l_msg_ctor_2059_83123F20(void *m, ts4l_msg_83123F20 *buf, int a5, int a6, float f1, float f2)
{
    ts4_set_u32_off0_831230F0(m, 2059);
    fn_83123118(m, buf, 16);
    buf->f8 = f1;
    buf->f12 = f2;
    buf->f0 = a5;
    buf->f4 = a6;
}

typedef struct ts4l_msg_83123F80 { char pad4[4]; char f4; } ts4l_msg_83123F80;
void ts4l_msg_ctor_2021_83123F80(void *m, ts4l_msg_83123F80 *buf, char a5)
{
    ts4_set_u32_off0_831230F0(m, 2021);
    fn_83123118(m, buf, 12);
    buf->f4 = a5;
}

typedef struct ts4l_msg_83124050 { int f0; } ts4l_msg_83124050;
void ts4l_msg_ctor_2023_83124050(void *m, ts4l_msg_83124050 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2023);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831240A0 { int f0; int f4; int f8; } ts4l_msg_831240A0;
void ts4l_msg_ctor_2056_831240A0(void *m, ts4l_msg_831240A0 *buf, int a5, int a6, int a7)
{
    ts4_set_u32_off0_831230F0(m, 2056);
    fn_83123118(m, buf, 12);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
}

typedef struct ts4l_msg_831240E8 { int f0; } ts4l_msg_831240E8;
void ts4l_msg_ctor_2028_831240E8(void *m, ts4l_msg_831240E8 *buf, int a5)
{
    ts4_set_u32_off0_831230F0(m, 2028);
    fn_83123118(m, buf, 4);
    buf->f0 = a5;
}

