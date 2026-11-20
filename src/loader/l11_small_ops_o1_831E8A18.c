/* Loader_DLL.xex 0x831E8A18-0x8342C0B8, executable version 0.0.0.3. */

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

float ts4l_field_op_831E8A18(char * a3, unsigned int a4)
{
    float t0;
    t0 = ((float *)a3)[a4];
    return t0;
}

float ts4l_field_op_831FE120(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)(a3 + 16);
    t1 = *(float *)(((char *)(unsigned long)(t0) + (a4 << 2)));
    return t1;
}

void ts4l_field_op_83203258(unsigned int a3, char * a4, unsigned int a5, float fa1)
{
    (void)a3;
    ((float *)a4)[a5] = (float)(fa1);
}

float ts4l_field_op_83203268(char * a3, unsigned int a4)
{
    float t0;
    t0 = ((float *)a3)[a4];
    return t0;
}

float ts4l_field_op_8320C428(char * a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    float t0;
    (void)a4;
    (void)a5;
    t0 = ((float *)a3)[a6];
    return t0;
}

int ts4l_update_flags64_83224A98(char * a3, char * a4)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 288);
    *(unsigned long long *)a4 = t0;
    return 0;
}

unsigned int ts4l_update_flags64_83226E28(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 64);
    return ((unsigned int)(t0) & 0xFFFFFFFFU);
}

void ts4l_convert_float_83230818(char * a3, float fa1, float fa2, float fa3, float fa4, float fa5, float fa6, float fa7, float fa8, float fa9)
{
    *(float *)a3 = (float)(fa1);
    *(float *)(a3 + 4) = (float)(fa2);
    *(float *)(a3 + 8) = (float)(fa3);
    *(float *)(a3 + 12) = (float)(fa4);
    *(float *)(a3 + 16) = (float)(fa5);
    *(float *)(a3 + 20) = (float)(fa6);
    *(float *)(a3 + 24) = (float)(fa7);
    *(float *)(a3 + 28) = (float)(fa8);
    *(float *)(a3 + 32) = (float)(fa9);
}

unsigned long long ts4l_update_flags64_832335E0(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 56);
    return t0;
}

unsigned long long ts4l_update_flags64_832335F0(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 64);
    return t0;
}

int ts4l_field_op_83242B90(unsigned int a3)
{
    if ((a3 & 0xFFFFU) == 352U) {
        return 22;
    }
    if ((a3 & 0xFFFFU) == 353U) {
        return 28;
    }
    if ((a3 & 0xFFFFU) != 354U) {
        if ((a3 & 0xFFFFU) != 355U) {
            return -1;
        }
        return 36;
    }
    return 36;
}

long long ts4l_field_op_8326F930(int a3)
{
    return ((long long)(a3) * (long long)(a3));
}

float ts4l_field_op_83271F68(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)(a3 + 16);
    t1 = *(float *)(((char *)(unsigned long)(t0) + (a4 << 2)));
    return t1;
}

extern char lbl_8353AF34[];
unsigned int ts4l_forward_call_83274F78(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(volatile unsigned int *)lbl_8353AF34;
    if (!t0) {
        return 0x80004003U;
    }
    t1 = *(volatile unsigned int *)(char *)(unsigned long)(t0);
    t2 = *(volatile unsigned int *)((char *)(unsigned long)(t1) + 16);
    return (unsigned int)(((int (*)())(unsigned long)(t2))(t0, a3, a4, a5, a6));
}

unsigned long long ts4l_update_flags64_8329A1B8(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)a3;
    return (t0 >> 63);
}

void ts4l_field_op_83329800(char * a3, int a4, unsigned int a5)
{
    *(unsigned int *)a3 = a5;
    *(unsigned int *)(a3 + 4) = a4;
    if (a4 > 2) {
        *(unsigned int *)(a3 + 8) = 2;
        return;
    }
    *(unsigned int *)(a3 + 8) = 1;
}

unsigned int ts4l_field_op_833E9280(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)a3;
    t1 = (((t0 + (unsigned int)(7)) & 0xFFFFFFF8U) + (unsigned int)(8));
    *(unsigned int *)a3 = t1;
    t2 = *(unsigned int *)((char *)(unsigned long)(t1) - 4);
    return t2;
}

unsigned long long ts4l_update_flags64_833E92A0(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned long long t2;
    t0 = *(unsigned int *)a3;
    t1 = (((t0 + (unsigned int)(7)) & 0xFFFFFFF8U) + (unsigned int)(8));
    *(unsigned int *)a3 = t1;
    t2 = *(unsigned long long *)((char *)(unsigned long)(t1) - 8);
    return t2;
}

unsigned int ts4l_field_op_833EA5B8(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)a3;
    t1 = (((t0 + (unsigned int)(7)) & 0xFFFFFFF8U) + (unsigned int)(8));
    *(unsigned int *)a3 = t1;
    t2 = *(unsigned short *)((char *)(unsigned long)(t1) - 2);
    return t2;
}

unsigned long long ts4l_update_flags64_833EEC68(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned long long t2;
    t0 = *(unsigned int *)a3;
    t1 = (((t0 + (unsigned int)(7)) & 0xFFFFFFF8U) + (unsigned int)(8));
    *(unsigned int *)a3 = t1;
    t2 = *(unsigned long long *)((char *)(unsigned long)(t1) - 8);
    return t2;
}

extern char lbl_8352CA04[];
unsigned int ts4l_field_op_833FA1B0(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)lbl_8352CA04;
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 200);
    t2 = *(unsigned short *)(((char *)(unsigned long)(((a3 & 0xFFU) << 1)) + t1));
    return (t2 & 0xFFFF8000U);
}

extern char lbl_8352CA04[];
unsigned int ts4l_field_op_833FA1D0(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned int *)lbl_8352CA04;
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 200);
    t2 = *(unsigned short *)(((char *)(unsigned long)(((a3 & 0xFFU) << 1)) + t1));
    return (t2 & 0xFFFF8000U);
}

int ts4l_forward_call_834009F0(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    t0 = *(unsigned int *)(a3 + 4);
    if (t0) {
        t1 = *(unsigned int *)(char *)(unsigned long)(t0);
        if (t1) {
            t2 = *(unsigned int *)(char *)(unsigned long)(t1);
            t3 = *(unsigned int *)(char *)(unsigned long)(t2);
            return ((int (*)())(unsigned long)(t3))(t1);
        }
        return 0;
    }
    return 0;
}

int ts4l_forward_call_83400A20(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    t0 = *(unsigned int *)(a3 + 4);
    if (t0) {
        t1 = *(unsigned int *)(char *)(unsigned long)(t0);
        if (t1) {
            t2 = *(unsigned int *)(char *)(unsigned long)(t1);
            t3 = *(unsigned int *)((char *)(unsigned long)(t2) + 4);
            return ((int (*)())(unsigned long)(t3))(t1);
        }
        return 0;
    }
    return 0;
}

int ts4l_forward_call_83400A50(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    t0 = *(unsigned int *)(a3 + 4);
    if (t0) {
        t1 = *(unsigned int *)(char *)(unsigned long)(t0);
        if (t1) {
            t2 = *(unsigned int *)(char *)(unsigned long)(t1);
            t3 = *(unsigned int *)((char *)(unsigned long)(t2) + 8);
            return ((int (*)())(unsigned long)(t3))(t1);
        }
        return (int)(a4);
    }
    return (int)(a4);
}

extern int ts4l_if_call_seq_fn_834144F0_8340B7B8();
int ts4l_forward_call_8340B820(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8, unsigned int a9)
{
    return ts4l_if_call_seq_fn_834144F0_8340B7B8(0, a4, (unsigned long long)(a5), a3, a6, a7, a8, a9);
}

extern int XamReadString();
int ts4l_forward_call_8340BA20(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    return XamReadString(0, (unsigned long long)(a3), 254, a4, a5, a6);
}

unsigned int ts4l_count_zeros_834178B8(unsigned int a3)
{
    return ((unsigned int)(31) - TS4L_CLZ(a3));
}

unsigned int ts4l_count_zeros_8341B738(unsigned int a3)
{
    return ((unsigned int)(32) - TS4L_CLZ((a3 - (unsigned int)(1))));
}

int ts4l_field_op_8342C0B8(float fa1)
{
    return (int)(fa1);
}
