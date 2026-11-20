/* Loader_DLL.xex 0x8313F508-0x8313F548, executable version 0.0.0.3. */
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
extern void *fn_830FFB68(void *self);
extern void fn_83109390(void *a, void *msg);

void ts4l_msg_send_2036_8313F508(void *self)
{
    int msg[5];
    ts4_set_u32_off0_8313F348(msg, 2036);
    fn_83109390(fn_830FFB68(self), msg);
}

void ts4l_msg_send_2037_8313F548(void *self)
{
    int msg[5];
    ts4_set_u32_off0_8313F348(msg, 2037);
    fn_83109390(fn_830FFB68(self), msg);
}
