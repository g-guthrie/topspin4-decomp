/* Loader_DLL.xex 0x83114688-0x831151D0, executable version 0.0.0.3. */
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

extern void fn_8310D5D0(void *self, void *msg);

typedef struct Ts4lPayloadA { int a; char b; } Ts4lPayloadA;

void ts4l_msg_ctor_13_83114688(void *m, Ts4lPayloadA *buf, int a, char b)
{
    ts4_set_u32_off0_831143F8(m, 13);
    ts4l_call_seq_u32_off10_83114420(m, buf, 8);
    buf->a = a;
    buf->b = b;
}

void ts4l_msg_ctor_12_831146C8(void *m, Ts4lPayloadA *buf, int a, char b)
{
    ts4_set_u32_off0_831143F8(m, 12);
    ts4l_call_seq_u32_off10_83114420(m, buf, 8);
    buf->a = a;
    buf->b = b;
}

void ts4l_msg_send_31_831151D0(void *self)
{
    int msg[5];
    ts4_set_u32_off0_831143F8(msg, 31);
    fn_8310D5D0(self, msg);
}
