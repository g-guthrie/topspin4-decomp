/* Loader_DLL.xex 0x83158C38-0x831CE1F0, executable version 0.0.0.3. */

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

void ts4l_update_bit_range_mask_83158C38(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0x7FFFFFFU) | (((a5 << 27) | (a5 >> 5)) & 0xF8000000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_83158C78(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFFBU) | (((a5 << 2) | (a5 >> 30)) & 0x4U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830AE288();
int ts4l_forward_call_83158D00(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_call_seq_83158FA8(unsigned int a3, unsigned int a4, unsigned int a5)
{
    fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
    return 0;
}

unsigned long long ts4l_make_bit_mask64_8315E138(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

unsigned long long ts4l_make_bit_mask64_8315E190(unsigned int a3)
{
    return (0x8000000000000000ULL >> (unsigned long long)((a3 + (unsigned int)(32))));
}

void ts4l_update_bit_range_mask_8315E1E0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFFE3FFU) | (((a5 << 10) | (a5 >> 22)) & 0x1C00U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E218(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFFF1FFFU) | (((a5 << 13) | (a5 >> 19)) & 0xE000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E250(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24))));
    *(unsigned int *)((a3 + ((a4 + (unsigned int)(48)) * (unsigned int)(24)))) = ((t0 & 0xFFF8FFFFU) | (((a5 << 16) | (a5 >> 16)) & 0x70000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E288(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1164) = ((t0 & 0xFE7FFFFFU) | (((a5 << 23) | (a5 >> 9)) & 0x1800000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E310(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFE7U) | (((a5 << 3) | (a5 >> 29)) & 0x18U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E350(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0xF83FFFFFU) | (((a5 << 22) | (a5 >> 10)) & 0x7C00000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E390(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1168) = ((t0 & 0x7FFFFFFU) | (((a5 << 27) | (a5 >> 5)) & 0xF8000000U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

void ts4l_update_bit_range_mask_8315E3D0(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172);
    *(unsigned int *)((a3 + (a4 * (unsigned int)(24))) + 1172) = ((t0 & 0xFFFFFFFBU) | (((a5 << 2) | (a5 >> 30)) & 0x4U));
    t1 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = ((0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))) | t1);
}

extern int fn_830AE288();
int ts4l_forward_call_8315E458(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return fn_830AE288(a3, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_call_seq_8315E8F8(char * a3, unsigned int a4, unsigned int a5)
{
    unsigned int t0;
    t0 = *(unsigned int *)(a3 + 12);
    fn_830AE288(t0, a4, a5, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
    return 0;
}

int ts4l_field_op_8315EA48(char * a3, unsigned int a4, unsigned int a5, unsigned int a6)
{
    unsigned int t0;
    unsigned int t1;
    t0 = *(unsigned int *)(a3 + 12);
    t1 = *(unsigned int *)((char *)(unsigned long)((t0 + a5)) + 468);
    ((int (*)())(unsigned long)(t1))(t0, a4, a6);
    return 0;
}

unsigned int ts4l_barrier_io_83177920(void)
{
    unsigned int t0;
    t0 = TS4L_LWBR((char *)(unsigned long)(2146048024U));
    return (t0 ^ 512U);
}

void ts4l_barrier_io_83177970(unsigned int a3, unsigned int a4)
{
    TS4L_STWBR(a4, (char *)(unsigned long)((((a3 + (unsigned int)(536543232)) - (unsigned int)(31152)) << 2)));
    TS4L_EMIT(0x7C0006AC);
}

void ts4l_barrier_io_83177988(unsigned int a3, unsigned int a4)
{
    TS4L_STWBR(a4, (char *)(unsigned long)((((a3 + (unsigned int)(536543232)) - (unsigned int)(31088)) << 2)));
    TS4L_EMIT(0x7C0006AC);
}

void ts4l_barrier_io_831779A0(unsigned int a3, unsigned int a4)
{
    TS4L_STWBR(a4, (char *)(unsigned long)((((a3 + (unsigned int)(536543232)) - (unsigned int)(31072)) << 2)));
    TS4L_EMIT(0x7C0006AC);
}

void ts4l_barrier_io_831779B8(unsigned int a3, unsigned int a4)
{
    TS4L_STWBR((((a4 & 0xFFFFFFFDU) | (((a3 << 1) | (a3 >> 31)) & 0x2U)) & 0x3U), (char *)(unsigned long)(2146048004U));
    TS4L_EMIT(0x7C0006AC);
}

extern char lbl_83531710[];
void ts4l_barrier_io_83177AB0(void)
{
    unsigned int t0;
    t0 = TS4L_LWBR((char *)(unsigned long)(2146048000U));
    *(unsigned int *)lbl_83531710 = t0;
}

unsigned int ts4l_field_op_8317AF70(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    t0 = *(unsigned char *)a3;
    t1 = *(unsigned char *)(a3 + 1);
    t2 = *(unsigned char *)(a3 + 2);
    return (((((t0 & 0x3U) << 8) | t1) << 5) | (t2 >> 3));
}

unsigned long long ts4l_field_op_83181680(unsigned long long a3, unsigned long long a4)
{
    return (a3 * a4);
}

unsigned int ts4l_field_op_83188320(void)
{
    return 0x88960001U;
}

extern int fn_83195E10();
extern int ts4_tailcall_fn_8340D830_831BB278();
unsigned int ts4l_call_seq_83196AE8(unsigned int a3)
{
    int t1;
    if (!a3) {
        return a3;
    }
    fn_83195E10();
    t1 = ts4_tailcall_fn_8340D830_831BB278(a3);
    return (unsigned int)(t1);
}

int ts4l_field_op_8319C888(unsigned int a3)
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

float ts4l_field_op_831B0268(char * a3, unsigned int a4)
{
    float t0;
    t0 = ((float *)a3)[a4];
    return t0;
}

unsigned long long ts4l_update_flags64_831CE1F0(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 120);
    return t0;
}
