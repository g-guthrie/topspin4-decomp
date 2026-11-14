/* Loader_DLL.xex 0x833533E0-0x833D5140, executable version 0.0.0.3. */

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

extern int fn_830AE288();
int ts4l_forward_call_833533E0(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

void ts4l_barrier_io_83353D70(char * a3)
{
    unsigned int t0;
    TS4L_EMIT(0x7C2004AC);
    t0 = *(unsigned int *)(a3 + 3504);
    *(unsigned int *)(a3 + 3504) = (t0 + (unsigned int)(1));
}

extern char lbl_83050914[];
unsigned int ts4l_field_op_83397478(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned char *)(((char *)lbl_83050914 + (a3 & 0x7U)));
    t1 = *(unsigned char *)(((char *)lbl_83050914 + ((a3 >> 3) & 0x1FU)));
    return ((((t0 << 3) | (t0 >> 29)) | t1) & 0xFFU);
}

extern char lbl_83050AB4[];
unsigned int ts4l_field_op_833A3A80(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned char *)(((char *)lbl_83050AB4 + (a3 & 0x7U)));
    t1 = *(unsigned char *)(((char *)lbl_83050AB4 + ((a3 >> 3) & 0x1FU)));
    return ((((t0 << 3) | (t0 >> 29)) | t1) & 0xFFU);
}

extern char lbl_830522C0[];
unsigned int ts4l_field_op_833D23C0(unsigned int a3)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned char *)(((char *)lbl_830522C0 + (a3 & 0x7U)));
    t1 = *(unsigned char *)(((char *)lbl_830522C0 + ((a3 >> 3) & 0x1FU)));
    return ((((t0 << 3) | (t0 >> 29)) | t1) & 0xFFU);
}

unsigned long long ts4l_make_bit_mask64_833D24A0(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_833D24F8(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_833D2528(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D2568(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D25A8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830B3558();
int ts4l_forward_call_833D27F0(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_833D2818(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D3440(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_833D3498(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_833D34C8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D3508(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D3548(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830AE288();
int ts4l_forward_call_833D3790(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D3EE8(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern int fn_830B3558();
int ts4l_forward_call_833D3F58(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D42F0(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern int fn_830B3558();
int ts4l_forward_call_833D4360(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D4828(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern int fn_830B3558();
int ts4l_forward_call_833D4898(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D4C18(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern int fn_830B3558();
int ts4l_forward_call_833D4C88(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_830B3558(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

unsigned long long ts4l_make_bit_mask64_833D5078(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_833D50D0(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_833D5100(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_833D5140(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3)));
    *(unsigned int *)((a3 + (((a4 + (unsigned int)(48)) + ((a4 + (unsigned int)(48)) << 1)) << 3))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}
