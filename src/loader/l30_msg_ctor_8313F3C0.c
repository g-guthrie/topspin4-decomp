/* Loader_DLL.xex 0x8313F3C0-0x8313F4D0, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_8313F348(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *fn_8313F370(void *m, void *buf, int n);

void ts4l_msg_ctor_8313F3C0(void *m, void *buf)
{
    ts4_set_u32_off0_8313F348(m, 2038);
    fn_8313F370(m, buf, 4);
}

void ts4l_msg_ctor_8313F448(void *m, void *buf)
{
    ts4_set_u32_off0_8313F348(m, 2041);
    fn_8313F370(m, buf, 4);
}

void ts4l_msg_ctor_8313F4D0(void *m, void *buf)
{
    ts4_set_u32_off0_8313F348(m, 2044);
    fn_8313F370(m, buf, 4);
}
