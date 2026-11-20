/* Loader_DLL.xex 0x83488AE0-0x83488B18, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_83488A48(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *fn_834889F8(void *m, void *buf, int n);

void ts4l_msg_ctor_83488AE0(void *m, void *buf)
{
    ts4_set_u32_off0_83488A48(m, 27);
    fn_834889F8(m, buf, 4);
}

void ts4l_msg_ctor_83488B18(void *m, void *buf)
{
    ts4_set_u32_off0_83488A48(m, 6);
    fn_834889F8(m, buf, 8);
}
