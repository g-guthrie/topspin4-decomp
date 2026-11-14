/* Loader_DLL.xex 0x831232B8-0x83123B60, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_831230F0(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *fn_83123118(void *m, void *buf, int n);

void ts4l_msg_ctor_831232B8(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 6);
    fn_83123118(m, buf, 8);
}

void ts4l_msg_ctor_831233B8(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 17);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_83123440(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2054);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_831235B0(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 27);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_83123810(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2000);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_83123898(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2002);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_83123920(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2039);
    fn_83123118(m, buf, 4);
}

void ts4l_msg_ctor_831239A8(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2006);
    fn_83123118(m, buf, 16);
}

void ts4l_msg_ctor_83123A38(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2007);
    fn_83123118(m, buf, 8);
}

void ts4l_msg_ctor_83123B60(void *m, void *buf)
{
    ts4_set_u32_off0_831230F0(m, 2010);
    fn_83123118(m, buf, 4);
}
