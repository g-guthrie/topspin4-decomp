/* Loader_DLL.xex 0x830A1260-0x831B1088, executable version 0.0.0.3. */

#ifdef _MSC_VER
void __emit(unsigned);
void __storewordbytereverse(unsigned int, int, void *);
unsigned int __loadwordbytereverse(int, void *);
int _CountLeadingZeros(unsigned int);
double __fabs(double);
#pragma intrinsic(__emit)
#pragma intrinsic(__storewordbytereverse)
#pragma intrinsic(__loadwordbytereverse)
#pragma intrinsic(_CountLeadingZeros)
#pragma intrinsic(__fabs)
#define TS4L_EMIT(x) __emit(x)
#define TS4L_STWBR(v, p) __storewordbytereverse(v, 0, p)
#define TS4L_LWBR(p) __loadwordbytereverse(0, p)
#define TS4L_CLZ(x) _CountLeadingZeros(x)
#define TS4L_FABS(x) __fabs(x)
#else
#define TS4L_EMIT(x) ((void)0)
#define TS4L_STWBR(v, p) (*(unsigned int *)(p) = (v))
#define TS4L_LWBR(p) (*(unsigned int *)(p))
#define TS4L_CLZ(x) ((unsigned int)(x))
#define TS4L_FABS(x) ((x) < 0 ? -(x) : (x))
#endif

int ts4l_field_op_830A1260(unsigned int a3, char * a4)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    (void)a3;
    t0 = *(volatile unsigned int *)(a4 + 4);
    if (t0 == 19U) {
        return 0;
    }
    if (t0 != 14U) {
        return 0;
    }
    t1 = *(volatile unsigned int *)(a4 + 16);
    t2 = *(volatile unsigned int *)(char *)(unsigned long)(t1);
    (void)t2;
    return 0;
}

void ts4l_barrier_io_830AAC30(char * a3)
{
    TS4L_EMIT(0x7C0006AC);
    *(unsigned int *)(a3 + 10888) = 0;
}

void ts4l_barrier_io_830AAC40(char * a3, unsigned int a4)
{
    TS4L_EMIT(0x7C0006AC);
    *(unsigned int *)(a3 + 10888) = a4;
}

void ts4l_barrier_io_830BA750(char * a3, unsigned int a4)
{
    *(unsigned int *)(a3 + 10956) = a4;
    TS4L_EMIT(0x7C0004AC);
    *(unsigned int *)((char *)(unsigned long)(2143813632U) + 1812) = a4;
    TS4L_EMIT(0x7C0006AC);
    TS4L_EMIT(0x7C0004AC);
}

void ts4l_barrier_io_830BC520(void)
{
    TS4L_EMIT(0x7C2004AC);
}

void ts4l_barrier_io_830BC578(char * a3)
{
    TS4L_EMIT(0x7C2004AC);
    *(unsigned int *)a3 = 0;
}

extern char __imp_KeCertMonitorData[];
int ts4l_forward_call_830D7EA8(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)__imp_KeCertMonitorData;
    t1 = *(unsigned int *)(char *)(unsigned long)(t0);
    if (t1) {
        t2 = *(unsigned int *)(char *)(unsigned long)(t1);
        if (t2) {
            return ((int (*)())(unsigned long)(t2))(27, a3);
        }
        return 0;
    }
    return 0;
}

void ts4l_barrier_io_830D9E30(char * a3, unsigned int a4)
{
    *(unsigned int *)(a3 + 13724) = a4;
    TS4L_EMIT(0x7C0004AC);
}

void ts4l_barrier_io_830D9E40(char * a3)
{
    *(unsigned int *)(a3 + 13724) = 0;
    TS4L_EMIT(0x7C0004AC);
}

extern char __imp_KeCertMonitorData[];
int ts4l_forward_call_830DA008(void)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)__imp_KeCertMonitorData;
    t1 = *(unsigned int *)(char *)(unsigned long)(t0);
    if (t1) {
        t2 = *(unsigned int *)(char *)(unsigned long)(t1);
        if (t2) {
            return ((int (*)())(unsigned long)(t2))();
        }
        return 0;
    }
    return 0;
}

extern char lbl_8300CCC4[];
extern char lbl_8300CCC8[];
float ts4l_float_op_831A9AB0(char * a3)
{
    unsigned int t0;
    float t1;
    float t2;
    t0 = *(unsigned char *)a3;
    t1 = *(float *)lbl_8300CCC8;
    t2 = *(float *)lbl_8300CCC4;
    return (((float)((double)(t0)) - t1) * t2);
}

extern char lbl_8300CCC0[];
float ts4l_float_op_831A9AE0(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned short *)a3;
    t1 = *(float *)lbl_8300CCC0;
    return ((float)((double)((short)(t0))) * t1);
}

extern char lbl_8300CCCC[];
float ts4l_float_op_831A9B98(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_8300CCCC;
    return ((float)((double)((long long)(((int)(t0) >> 12)))) * t1);
}

extern char lbl_830027C4[];
float ts4l_float_op_831A9BC8(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_830027C4;
    return ((float)((double)((long long)(((int)(t0) >> 8)))) * t1);
}

extern char lbl_8300CCD0[];
float ts4l_float_op_831A9BF8(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_8300CCD0;
    return ((float)((double)((long long)(int)(t0))) * t1);
}

extern char lbl_8300CCC4[];
extern char lbl_8300CCC8[];
float ts4l_float_op_831ADD70(char * a3)
{
    unsigned int t0;
    float t1;
    float t2;
    t0 = *(unsigned char *)a3;
    t1 = *(float *)lbl_8300CCC8;
    t2 = *(float *)lbl_8300CCC4;
    return (((float)((double)(t0)) - t1) * t2);
}

extern char lbl_8300CCC0[];
float ts4l_float_op_831ADDA0(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned short *)a3;
    t1 = *(float *)lbl_8300CCC0;
    return ((float)((double)((short)(t0))) * t1);
}

extern char lbl_8300CCCC[];
float ts4l_float_op_831ADE58(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_8300CCCC;
    return ((float)((double)((long long)(((int)(t0) >> 12)))) * t1);
}

extern char lbl_830027C4[];
float ts4l_float_op_831ADE88(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_830027C4;
    return ((float)((double)((long long)(((int)(t0) >> 8)))) * t1);
}

extern char lbl_8300CCD0[];
float ts4l_float_op_831ADEB8(char * a3)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)a3;
    t1 = *(float *)lbl_8300CCD0;
    return ((float)((double)((long long)(int)(t0))) * t1);
}

void ts4l_float_op_831B0748(char * a3, float fa1)
{
    unsigned int t0;
    float t1;
    float t2;
    float t3;
    t0 = *(unsigned int *)(a3 + 8);
    t1 = *(float *)(a3 + 12);
    t2 = *(float *)a3;
    t3 = ((float *)a3)[t0];
    *(float *)(a3 + 4) = (float)(t2);
    *(float *)a3 = (float)(fa1);
    *(float *)(a3 + 16) = (float)((t1 * t3));
}

void ts4l_float_op_831B07A8(char * a3, float fa1)
{
    float t0;
    unsigned int t1;
    float t2;
    float t3;
    float t4;
    t0 = *(float *)(a3 + 12);
    t1 = *(unsigned int *)(a3 + 8);
    t2 = *(float *)(a3 + 16);
    t3 = *(float *)a3;
    t4 = ((float *)a3)[t1];
    *(float *)(a3 + 4) = (float)(t3);
    *(float *)a3 = (float)(fa1);
    *(float *)(a3 + 20) = (float)(((t2 * t4) + (t0 * fa1)));
}

void ts4l_field_op_831B0ED8(char * a3, float fa1)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 65536);
    ((float *)a3)[t0] = (float)(fa1);
    t1 = *(unsigned int *)(a3 + 65536);
    *(unsigned int *)(a3 + 65536) = ((t1 + (unsigned int)(1)) & 0x3FFFU);
}

float ts4l_field_op_831B0F00(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)((a3 + 65536U));
    t1 = *(float *)((a3 + (((t0 - a4) & 0x3FFFU) << 2)));
    return t1;
}

void ts4l_field_op_831B0F60(char * a3, float fa1)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 131072);
    ((float *)a3)[t0] = (float)(fa1);
    t1 = *(unsigned int *)(a3 + 131072);
    *(unsigned int *)(a3 + 131072) = ((t1 + (unsigned int)(1)) & 0x7FFFU);
}

float ts4l_field_op_831B0F88(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)((a3 + 131072U));
    t1 = *(float *)((a3 + (((t0 - a4) & 0x7FFFU) << 2)));
    return t1;
}

void ts4l_field_op_831B0FE8(char * a3, float fa1)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 1024);
    ((float *)a3)[t0] = (float)(fa1);
    t1 = *(unsigned int *)(a3 + 1024);
    *(unsigned int *)(a3 + 1024) = ((t1 + (unsigned int)(1)) & 0xFFU);
}

float ts4l_field_op_831B1008(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)(a3 + 1024);
    t1 = *(float *)((a3 + (((t0 - a4) & 0xFFU) << 2)));
    return t1;
}

void ts4l_field_op_831B1068(char * a3, float fa1)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 2048);
    ((float *)a3)[t0] = (float)(fa1);
    t1 = *(unsigned int *)(a3 + 2048);
    *(unsigned int *)(a3 + 2048) = ((t1 + (unsigned int)(1)) & 0x1FFU);
}

float ts4l_field_op_831B1088(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)(a3 + 2048);
    t1 = *(float *)((a3 + (((t0 - a4) & 0x1FFU) << 2)));
    return t1;
}
