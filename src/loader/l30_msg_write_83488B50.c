/* Loader_DLL.xex 0x83488B50-0x83488BE8, executable version 0.0.0.3. */
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

void ts4l_msg_write_83488B50(void *m, char *buf, int a5)
{
    ts4_set_u32_off0_83488A48(m, 2003);
    fn_834889F8(m, buf, 4);
    *(int *)(buf + 0) = a5;
}

void ts4l_msg_write_83488BA0(void *m, char *buf)
{
    ts4_set_u32_off0_83488A48(m, 18);
    fn_834889F8(m, buf, 4);
    *(int *)(buf + 0) = 0;
}

void ts4l_msg_write_83488BE8(void *m, char *buf, int a5)
{
    ts4_set_u32_off0_83488A48(m, 2016);
    fn_834889F8(m, buf, 40);
    *(int *)(buf + 12) = a5;
    *(int *)(buf + 0) = 0;
    *(int *)(buf + 4) = 0;
    *(int *)(buf + 8) = 0;
}
