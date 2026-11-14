/* Loader_DLL.xex 0x8321B990-0x8321BAA0, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_8321B918(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *fn_8321B940(void *m, void *buf, int n);

void ts4l_msg_ctor_8321B990(void *m, void *buf)
{
    ts4_set_u32_off0_8321B918(m, 6);
    fn_8321B940(m, buf, 8);
}

void ts4l_msg_ctor_8321BA18(void *m, void *buf)
{
    ts4_set_u32_off0_8321B918(m, 2041);
    fn_8321B940(m, buf, 4);
}

void ts4l_msg_ctor_8321BAA0(void *m, void *buf)
{
    ts4_set_u32_off0_8321B918(m, 2044);
    fn_8321B940(m, buf, 4);
}
