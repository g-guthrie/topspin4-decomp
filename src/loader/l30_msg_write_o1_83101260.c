/* Loader_DLL.xex 0x83101260-0x83101508, executable version 0.0.0.3. */
#ifdef _MSC_VER
#define TS4L_NOINLINE __declspec(noinline)
#else
#define TS4L_NOINLINE
#endif
TS4L_NOINLINE static void ts4_set_u32_off0_83101088(void *m, int id)
{
    volatile int *h = (volatile int *)m;
    h[0] = 0; h[1] = 0; h[2] = 0; h[3] = 0; h[4] = 0;
    h[0] = 20; h[1] = id;
}
extern void *ts4l_call_seq_u32_off10_831010B0(void *m, void *buf, int n);

void ts4l_msg_write_o1_83101260(void *m, char *buf, float f1, float f2, float f3, float f4)
{
    ts4_set_u32_off0_83101088(m, 8);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 16);
    *(float *)(buf + 0) = f1;
    *(float *)(buf + 4) = f2;
    *(float *)(buf + 8) = f3;
    *(float *)(buf + 12) = f4;
}

void ts4l_msg_write_o1_831012D0(void *m, char *buf, float f1, float f2, float f3, float f4)
{
    ts4_set_u32_off0_83101088(m, 16);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 16);
    *(float *)(buf + 0) = f1;
    *(float *)(buf + 4) = f2;
    *(float *)(buf + 8) = f3;
    *(float *)(buf + 12) = f4;
}

void ts4l_msg_write_o1_83101340(void *m, char *buf, int a5)
{
    ts4_set_u32_off0_83101088(m, 18);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 4);
    *(int *)(buf + 0) = a5;
}

void ts4l_msg_write_o1_83101390(void *m, char *buf)
{
    ts4_set_u32_off0_83101088(m, 24);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 4);
    *(int *)(buf + 0) = 0;
}

void ts4l_msg_write_o1_831013D8(void *m, char *buf)
{
    ts4_set_u32_off0_83101088(m, 25);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 4);
    *(int *)(buf + 0) = 0;
}

void ts4l_msg_write_o1_83101478(void *m, char *buf, int a5, int a6, int a7, int a8)
{
    ts4_set_u32_off0_83101088(m, 2016);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 40);
    *(int *)(buf + 0) = a5;
    *(int *)(buf + 4) = a6;
    *(int *)(buf + 8) = a7;
    *(int *)(buf + 12) = a8;
}

void ts4l_msg_write_o1_831014C8(void *m, char *buf, int a5, int a6)
{
    ts4_set_u32_off0_83101088(m, 2048);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 16);
    *(int *)(buf + 0) = a5;
    *(int *)(buf + 4) = a6;
}

void ts4l_msg_write_o1_83101508(void *m, char *buf, float f1)
{
    ts4_set_u32_off0_83101088(m, 2042);
    ts4l_call_seq_u32_off10_831010B0(m, buf, 4);
    *(float *)(buf + 0) = f1;
}
