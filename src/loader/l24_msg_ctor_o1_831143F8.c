/* Loader_DLL.xex 0x831144D8-0x83114B90, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif

/* Message header initialiser: zero a 5-word header, then tag it with a type and id. */
typedef struct ts4l_hdr { int w[5]; } ts4l_hdr;
TS4L_NOINLINE static void ts4_set_u32_off0_831143F8(void *m, int id)
{
    volatile ts4l_hdr *h = (volatile ts4l_hdr *)m;
    h->w[0] = 0; h->w[1] = 0; h->w[2] = 0; h->w[3] = 0; h->w[4] = 0;
    h->w[0] = 20; h->w[1] = id;
}
extern void *ts4l_call_seq_u32_off10_83114420(void *m, void *buf, int n);

typedef struct ts4l_msg_831144D8 { int f0; int f4; int f8; } ts4l_msg_831144D8;
void ts4l_msg_ctor_5_831144D8(void *m, ts4l_msg_831144D8 *buf, int a5, int a6, int a7)
{
    ts4_set_u32_off0_831143F8(m, 5);
    ts4l_call_seq_u32_off10_83114420(m, buf, 12);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
}

typedef struct ts4l_msg_83114520 { long long f0; } ts4l_msg_83114520;
void ts4l_msg_ctor_3_83114520(void *m, ts4l_msg_83114520 *buf, long long a5)
{
    ts4_set_u32_off0_831143F8(m, 3);
    ts4l_call_seq_u32_off10_83114420(m, buf, 12);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831145A8 { float f0; float f4; float f8; float f12; } ts4l_msg_831145A8;
void ts4l_msg_ctor_8_831145A8(void *m, ts4l_msg_831145A8 *buf, float f1, float f2, float f3, float f4)
{
    ts4_set_u32_off0_831143F8(m, 8);
    ts4l_call_seq_u32_off10_83114420(m, buf, 16);
    buf->f0 = f1;
    buf->f4 = f2;
    buf->f8 = f3;
    buf->f12 = f4;
}

typedef struct ts4l_msg_83114618 { float f0; float f4; float f8; float f12; } ts4l_msg_83114618;
void ts4l_msg_ctor_16_83114618(void *m, ts4l_msg_83114618 *buf, float f1, float f2, float f3, float f4)
{
    ts4_set_u32_off0_831143F8(m, 16);
    ts4l_call_seq_u32_off10_83114420(m, buf, 16);
    buf->f0 = f1;
    buf->f4 = f2;
    buf->f8 = f3;
    buf->f12 = f4;
}

typedef struct ts4l_msg_831147A0 { short f0; char pad4[2]; int f4; char f8; } ts4l_msg_831147A0;
void ts4l_msg_ctor_38_831147A0(void *m, ts4l_msg_831147A0 *buf, short a5, int a6, char a7)
{
    ts4_set_u32_off0_831143F8(m, 38);
    ts4l_call_seq_u32_off10_83114420(m, buf, 12);
    buf->f0 = a5;
    buf->f4 = a6;
    buf->f8 = a7;
}

typedef struct ts4l_msg_831147E8 { int f0; } ts4l_msg_831147E8;
void ts4l_msg_ctor_40_831147E8(void *m, ts4l_msg_831147E8 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 40);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83114838 { int f0; } ts4l_msg_83114838;
void ts4l_msg_ctor_47_83114838(void *m, ts4l_msg_83114838 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 47);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_831148F8 { int f0; } ts4l_msg_831148F8;
void ts4l_msg_ctor_19_831148F8(void *m, ts4l_msg_831148F8 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 19);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83114948 { int f0; } ts4l_msg_83114948;
void ts4l_msg_ctor_2053_83114948(void *m, ts4l_msg_83114948 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 2053);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83114998 { int f0; } ts4l_msg_83114998;
void ts4l_msg_ctor_24_83114998(void *m, ts4l_msg_83114998 *buf)
{
    ts4_set_u32_off0_831143F8(m, 24);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_831149E0 { int f0; } ts4l_msg_831149E0;
void ts4l_msg_ctor_25_831149E0(void *m, ts4l_msg_831149E0 *buf)
{
    ts4_set_u32_off0_831143F8(m, 25);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_83114A28 { int f0; } ts4l_msg_83114A28;
void ts4l_msg_ctor_34_83114A28(void *m, ts4l_msg_83114A28 *buf)
{
    ts4_set_u32_off0_831143F8(m, 34);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_83114A70 { int f0; } ts4l_msg_83114A70;
void ts4l_msg_ctor_35_83114A70(void *m, ts4l_msg_83114A70 *buf)
{
    ts4_set_u32_off0_831143F8(m, 35);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = 0;
}

typedef struct ts4l_msg_83114AB8 { int f0; } ts4l_msg_83114AB8;
void ts4l_msg_ctor_43_83114AB8(void *m, ts4l_msg_83114AB8 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 43);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83114B08 { int f0; } ts4l_msg_83114B08;
void ts4l_msg_ctor_26_83114B08(void *m, ts4l_msg_83114B08 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 26);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
    buf->f0 = a5;
}

typedef struct ts4l_msg_83114B90 { int f0; } ts4l_msg_83114B90;
void ts4l_msg_ctor_28_83114B90(void *m, ts4l_msg_83114B90 *buf, int a5)
{
    ts4_set_u32_off0_831143F8(m, 28);
    ts4l_call_seq_u32_off10_83114420(m, buf, 8);
    buf->f0 = a5;
}

