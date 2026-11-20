/* Loader_DLL.xex 0x8321B9C8-0x8321BA50, executable version 0.0.0.3. */
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

void ts4l_msg_write_8321B9C8(void *m, char *buf, float f1)
{
    ts4_set_u32_off0_8321B918(m, 2042);
    fn_8321B940(m, buf, 4);
    *(float *)(buf + 0) = f1;
}

void ts4l_msg_write_8321BA50(void *m, char *buf, int a5)
{
    ts4_set_u32_off0_8321B918(m, 2045);
    fn_8321B940(m, buf, 4);
    *(int *)(buf + 0) = a5;
}
