/* Loader_DLL.xex 0x830C08B0-0x830DDC48, executable version 0.0.0.3. */

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

void ts4l_field_op_830C08B0(char * a3, char * a4, char * a5)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    unsigned int t4;
    t0 = *(volatile unsigned int *)a3;
    *(volatile unsigned int *)a4 = t0;
    t1 = *(volatile unsigned short *)(a3 + 6);
    *(volatile unsigned int *)(a4 + 4) = t1;
    t2 = *(volatile unsigned short *)(a3 + 4);
    t3 = *(volatile unsigned int *)(a3 + 8);
    *(volatile unsigned int *)a5 = ((t3 << 16) | t2);
    t4 = *(volatile unsigned short *)(a3 + 8);
    *(volatile unsigned int *)(a5 + 4) = t4;
}

unsigned long long ts4l_make_bit_mask64_830C0930(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a4 - a3)))) >> (unsigned long long)(a3));
}

void ts4l_update_flags64_830C2240(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned int *)(a3 + 11992) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 524288ULL);
}

unsigned int ts4l_field_op_830C4EF8(char * a3, unsigned int a4)
{
    unsigned int t0;
    t0 = *(unsigned int *)((a3 + ((a4 & 0x3FU) << 2)));
    return (t0 | (a4 & 0xFFFFFFC0U));
}

unsigned long long ts4l_make_bit_mask64_830CA290(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a4 - a3)))) >> (unsigned long long)((a3 + (unsigned int)(32))));
}

unsigned long long ts4l_make_bit_mask64_830CA2B8(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_830CA2E8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA320(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA358(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA390(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164) = ((t0 & 0xFE7FFFFFU) | (((a5 << 23) | (a5 >> 9)) & 0x1800000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA418(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFE7U) | (((a5 << 3) | (a5 >> 29)) & 0x18U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA458(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0xF83FFFFFU) | (((a5 << 22) | (a5 >> 10)) & 0x7C00000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA498(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0x7FFFFFFU) | (((a5 << 27) | (a5 >> 5)) & 0xF8000000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_830CA4D8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFFBU) | (((a5 << 2) | (a5 >> 30)) & 0x4U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830AE288();
int ts4l_forward_call_830CA560(unsigned int a3, unsigned int a4)
{
    return fn_830AE288(a3, a4, 0, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

void ts4l_barrier_io_830CAD60(void)
{
    *(unsigned int *)((char *)(unsigned long)(2143813632U) + 12820) = 7;
    TS4L_EMIT(0x7C0006AC);
    *(unsigned int *)((char *)(unsigned long)(2143813632U) + 13320) = 2048;
    TS4L_EMIT(0x7C0006AC);
}

void ts4l_barrier_io_830CB420(unsigned int a3, unsigned int a4)
{
    *(unsigned int *)(char *)(unsigned long)(((a3 + (unsigned int)(535953408)) << 2)) = a4;
    TS4L_EMIT(0x7C0006AC);
}

unsigned long long ts4l_make_bit_mask64_830CBED0(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830CBEF0(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

int ts4l_update_flags64_830CBF98(char * a3)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)(a3 + 104);
    if (!t0) {
        return 1;
    }
    t1 = *(unsigned long long *)((a3 + t0));
    if (t1 != ((1432778633ULL & 0xFFFFFFFFULL) | (((287454020ULL << 32) | (287454020ULL >> 32)) & 0xFFFFFFFF00000000ULL))) {
        return 0;
    }
    return 1;
}

extern int fn_830CC618();
int ts4l_call_seq_830D0A60(char * a3)
{
    unsigned int t0;
    int t1;
    t0 = *(unsigned int *)(a3 + 108);
    *(unsigned int *)(a3 + 148) = 0;
    *(unsigned int *)(a3 + 108) = ((((t0 & 0xFFFFFFF0U) | (((unsigned int)(257)) & 0xFU)) & 0xFFFFFEFFU) | (((unsigned int)(257)) & 0x100U));
    t1 = fn_830CC618();
    TS4L_EMIT(0x7C0004AC);
    return t1;
}

unsigned long long ts4l_make_bit_mask64_830D33A0(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a4 - a3)))) >> (unsigned long long)(a3));
}

void ts4l_update_bit_range_mask_830D34E8(char * a3, int a4)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)a3;
    *(unsigned long long *)a3 = (((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a4 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a4)) & 0xFFULL)) | t0);
}

void ts4l_update_bit_range_mask_830D3520(char * a3, int a4)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)a3;
    *(unsigned long long *)a3 = (t0 & (~((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a4 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a4)) & 0xFFULL))));
}

extern char lbl_83084840[];
float ts4l_float_op_830D63E8(float fa1, float fa2, float fa3, float fa4)
{
    float t0;
    t0 = *(float *)((char *)lbl_83084840 + 36);
    return (((((((fa2 + fa3) * t0) - fa4) * fa1) + (((fa2 + fa3) * t0) - fa2)) * fa1) + fa4);
}

unsigned long long ts4l_make_bit_mask64_830D7D88(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830D7DA8(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830D9F18(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830D9F38(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830DDC48(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}
