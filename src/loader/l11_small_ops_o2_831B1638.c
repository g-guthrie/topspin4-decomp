/* Loader_DLL.xex 0x831B1638-0x833533B8, executable version 0.0.0.3. */

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

void ts4l_float_op_831B1638(char * a3, float fa1)
{
    unsigned int t0;
    float t1;
    unsigned int t2;
    float t3;
    unsigned int t4;
    t0 = *(unsigned int *)(a3 + 16384);
    t1 = *(float *)(a3 + 16396);
    t2 = *(unsigned int *)(a3 + 16388);
    t3 = *(float *)((a3 + (((t0 - t2) & 0xFFFU) << 2)));
    *(float *)(a3 + 16404) = (float)((t3 * t1));
    ((float *)a3)[t0] = (float)(fa1);
    t4 = *(unsigned int *)(a3 + 16384);
    *(unsigned int *)(a3 + 16384) = ((t4 + (unsigned int)(1)) & 0xFFFU);
}

void ts4l_field_op_831B18B8(char * a3, float fa1)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 8192);
    ((float *)a3)[t0] = (float)(fa1);
    t1 = *(unsigned int *)(a3 + 8192);
    *(unsigned int *)(a3 + 8192) = ((t1 + (unsigned int)(1)) & 0x7FFU);
}

float ts4l_field_op_831B18D8(char * a3, unsigned int a4)
{
    unsigned int t0;
    float t1;
    t0 = *(unsigned int *)(a3 + 8192);
    t1 = *(float *)((a3 + (((t0 - a4) & 0x7FFU) << 2)));
    return t1;
}

unsigned int ts4l_field_op_831F62A0(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)a3;
    t1 = *(unsigned char *)(char *)(unsigned long)(t0);
    *(unsigned int *)a3 = (t0 + (unsigned int)(1));
    return ((t1 - (unsigned int)(128)) << 8);
}

extern char lbl_83025CD0[];
int ts4l_field_op_831F6380(unsigned int a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(unsigned int *)(((char *)lbl_83025CD0 + ((a3 & 0xFU) << 2)));
    if (((int)((t0 * a4)) >> 8) >= 16) {
        return ((int)((t0 * a4)) >> 8);
    }
    return 16;
}

int ts4l_barrier_io_832113B8(char * a3, char * a4)
{
    unsigned int t0;
    unsigned int t1;
    *(unsigned long long *)a4 = 0LL;
    t0 = *(unsigned int *)(a4 + 4);
    *(unsigned int *)(a4 + 4) = (t0 | 65536U);
    t1 = *(unsigned int *)(a3 + 12);
    if ((int)(t1) >= 0) {
        *(unsigned int *)(a4 + 8) = 0;
        *(unsigned int *)(a4 + 12) = 0;
        TS4L_EMIT(0x7C2004AC);
        return 1;
    }
    TS4L_EMIT(0x7C2004AC);
    return 1;
}

unsigned long long ts4l_make_bit_mask64_8321EE08(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_8321EE30(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_8321EE70(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8321EEB0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8321EEF0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830B3558();
int ts4l_forward_call_8321F138(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_8321F160(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_83221200(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_83221228(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_83221268(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_832212A8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_832212E8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830B3558();
int ts4l_forward_call_83221530(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_83221558(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

int ts4l_forward_call_832258C0(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)a3;
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 52);
    return ((int (*)())(unsigned long)(t1))(a3, (unsigned long long)(a4));
}

int ts4l_update_flags64_8324E640(char * a3, char * a4, char * a5)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    unsigned long long t4;
    unsigned int t5;
    unsigned int t6;
    *(unsigned long long *)a4 = 0LL;
    *(unsigned int *)a5 = 0;
    t0 = *(unsigned int *)(a3 + 44);
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 16);
    t2 = *(unsigned int *)((char *)(unsigned long)(t1) + 8);
    if (!t2) {
        return 0;
    }
    t3 = *(unsigned int *)(char *)(unsigned long)(t2);
    t4 = *(unsigned long long *)((char *)(unsigned long)(t3) + 8);
    *(unsigned long long *)a4 = t4;
    t5 = *(unsigned int *)(char *)(unsigned long)(t2);
    t6 = *(unsigned int *)((char *)(unsigned long)(t5) + 4);
    *(unsigned int *)a5 = t6;
    return 0;
}

int ts4l_update_flags64_832500F0(char * a3, char * a4, char * a5)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    unsigned long long t4;
    unsigned int t5;
    unsigned int t6;
    *(unsigned long long *)a4 = 0LL;
    *(unsigned int *)a5 = 0;
    t0 = *(unsigned int *)(a3 + 44);
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 16);
    t2 = *(unsigned int *)((char *)(unsigned long)(t1) + 8);
    if (!t2) {
        return 0;
    }
    t3 = *(unsigned int *)(char *)(unsigned long)(t2);
    t4 = *(unsigned long long *)((char *)(unsigned long)(t3) + 8);
    *(unsigned long long *)a4 = t4;
    t5 = *(unsigned int *)(char *)(unsigned long)(t2);
    t6 = *(unsigned int *)((char *)(unsigned long)(t5) + 4);
    *(unsigned int *)a5 = t6;
    return 0;
}

int ts4l_update_flags64_83251820(char * a3, char * a4, char * a5)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    unsigned long long t4;
    unsigned int t5;
    unsigned int t6;
    *(unsigned long long *)a4 = 0LL;
    *(unsigned int *)a5 = 0;
    t0 = *(unsigned int *)(a3 + 44);
    t1 = *(unsigned int *)((char *)(unsigned long)(t0) + 16);
    t2 = *(unsigned int *)((char *)(unsigned long)(t1) + 4);
    if (!t2) {
        return 0;
    }
    t3 = *(unsigned int *)(char *)(unsigned long)(t2);
    t4 = *(unsigned long long *)((char *)(unsigned long)(t3) + 8);
    *(unsigned long long *)a4 = t4;
    t5 = *(unsigned int *)(char *)(unsigned long)(t2);
    t6 = *(unsigned int *)((char *)(unsigned long)(t5) + 4);
    *(unsigned int *)a5 = t6;
    return 0;
}

unsigned int ts4l_update_bit_range_mask_83274FC8(char * a3, unsigned int a4)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)a3;
    return ((unsigned int)((t0 >> (unsigned long long)(((unsigned int)(64) - a4)))) & 0xFFFFFFFFU);
}

int ts4l_update_flags64_832A0A28(unsigned int a3)
{
    unsigned long long t0;
    if (!a3) {
        return -11;
    }
    t0 = *(unsigned long long *)(char *)(unsigned long)(a3);
    if (t0 != ((429462051ULL & 0xFFFFFFFFULL) | (((429261076ULL << 32) | (429261076ULL >> 32)) & 0xFFFFFFFF00000000ULL))) {
        return -12;
    }
    return 0;
}

unsigned long long ts4l_update_flags64_832A0E60(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned long long t3;
    t0 = *(unsigned int *)(a3 + 16);
    t1 = *(unsigned int *)(a3 + 12);
    t2 = *(unsigned int *)a3;
    t3 = *(unsigned long long *)((char *)(unsigned long)(t0) + 3640);
    return ((((t3 << 2) + (unsigned long long)((long long)(int)(t1))) << 4) + (unsigned long long)((long long)(int)(t2)));
}

void ts4l_update_flags64_83303B80(char * a3)
{
    unsigned long long t0;
    unsigned int t1;
    t0 = *(unsigned long long *)a3;
    t1 = *(unsigned int *)(a3 + 8);
    *(unsigned long long *)a3 = (t0 << 1);
    *(unsigned int *)(a3 + 8) = (t1 - (unsigned int)(1));
}

unsigned long long ts4l_make_bit_mask64_83353348(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern int fn_830B3558();
int ts4l_forward_call_833533B8(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}
