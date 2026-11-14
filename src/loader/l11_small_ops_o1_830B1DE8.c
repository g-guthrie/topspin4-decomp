/* Loader_DLL.xex 0x830B1DE8-0x830C0748, executable version 0.0.0.3. */

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

void ts4l_update_flags64_830B1DE8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & (~((unsigned int)(15) << a4))) | (a5 << a4));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1E28(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & (~((unsigned int)(15) << a4))) | (a5 << a4));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B1E68(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFFFFFFF0U) | a4);
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1E88(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFFFFFF0FU) | (a4 << 4));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1EB0(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFFFFF0FFU) | (a4 << 8));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1ED8(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFFFF0FFFU) | (a4 << 12));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1F00(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFFF0FFFFU) | (a4 << 16));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1F28(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xFF0FFFFFU) | (a4 << 20));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1F50(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10540);
    *(volatile unsigned int *)(a3 + 10540) = ((t0 & 0xF0FFFFFFU) | (a4 << 24));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 8192ULL);
}

void ts4l_update_flags64_830B1F98(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFFFFFFF0U) | a4);
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B1FB8(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFFFFFF0FU) | (a4 << 4));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B1FE0(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFFFFF0FFU) | (a4 << 8));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B2008(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFFFF0FFFU) | (a4 << 12));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B2030(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFFF0FFFFU) | (a4 << 16));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B2058(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xFF0FFFFFU) | (a4 << 20));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B2080(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10544);
    *(volatile unsigned int *)(a3 + 10544) = ((t0 & 0xF0FFFFFFU) | (a4 << 24));
    t1 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t1 | 4096ULL);
}

void ts4l_update_flags64_830B2900(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10562) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 256ULL);
}

void ts4l_update_bit_range_mask_830B30D0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830B3120(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830B3170(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

unsigned long long ts4l_make_bit_mask64_830B4968(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B4988(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

unsigned long long ts4l_update_bit_range_mask_830B4AE8(char * a3, int a4)
{
    unsigned long long t0;
    t0 = ((unsigned long long *)a3)[(a4 >> 16)];
    return ((((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a4 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a4)) & 0xFFULL)) & t0) << ((unsigned long long)((long long)(a4)) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B60C8(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B60E8(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B98C8(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B98E8(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

int ts4l_field_op_830B9A80(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 21748);
    if (t0) {
        return 1;
    }
    t1 = *(unsigned char *)(a3 + 10941);
    return (int)((((~(t1 | t1)) >> 1) & 0x1U));
}

unsigned long long ts4l_make_bit_mask64_830BC398(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

void ts4l_barrier_io_830C0748(unsigned int a3, unsigned int a4)
{
    *(unsigned int *)(char *)(unsigned long)(((a3 + (unsigned int)(535953408)) << 2)) = a4;
    TS4L_EMIT(0x7C0006AC);
}
