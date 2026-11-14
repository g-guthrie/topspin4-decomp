/* Loader_DLL.xex 0x83114C50-0x83114CD0, executable version 0.0.0.3. */
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

void ts4l_msg_write_83114C50(void *m, char *buf, int a5, int a6)
{
    ts4_set_u32_off0_831143F8(m, 2048);
    ts4l_call_seq_u32_off10_83114420(m, buf, 16);
    *(int *)(buf + 0) = a5;
    *(int *)(buf + 4) = a6;
}

void ts4l_msg_write_83114C90(void *m, char *buf, int a5, int a6)
{
    ts4_set_u32_off0_831143F8(m, 29);
    ts4l_call_seq_u32_off10_83114420(m, buf, 12);
    *(int *)(buf + 0) = a5;
    *(int *)(buf + 8) = a6;
}

void ts4l_msg_write_83114CD0(void *m, char *buf, int a5, int a6)
{
    ts4_set_u32_off0_831143F8(m, 30);
    ts4l_call_seq_u32_off10_83114420(m, buf, 12);
    *(int *)(buf + 0) = a5;
    *(int *)(buf + 8) = a6;
}
