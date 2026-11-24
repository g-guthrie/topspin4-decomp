/* Loader_DLL.xex 0x83114570-0x83114C18, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_831143F8(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *ts4l_call_seq_u32_off10_83114420(void *m, void *buf, int n);

void ts4l_msg_ctor_83114570(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 6);
    ts4l_call_seq_u32_off10_83114420(m, buf, 8);
}

void ts4l_msg_ctor_83114708(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 11);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
}

void ts4l_msg_ctor_83114888(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 17);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
}

void ts4l_msg_ctor_831148C0(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 2054);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
}

void ts4l_msg_ctor_83114B58(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 27);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
}

void ts4l_msg_ctor_83114BE0(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 2002);
    ts4l_call_seq_u32_off10_83114420(m, buf, 4);
}

void ts4l_msg_ctor_83114C18(void *m, void *buf)
{
    ts4_set_u32_off0_831143F8(m, 2006);
    ts4l_call_seq_u32_off10_83114420(m, buf, 16);
}
