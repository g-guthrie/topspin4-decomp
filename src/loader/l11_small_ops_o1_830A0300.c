/* Loader_DLL.xex 0x830A0300-0x830B1BA8, executable version 0.0.0.3. */

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

unsigned int ts4l_field_op_830A0300(char * a3)
{
    unsigned int t0;
    t0 = *(unsigned char *)(a3 + 2232);
    return t0;
}

extern int ts4l_call_seq_u32_off4_8348BD40();
extern int ts4l_if_call_seq_u32_off0_8348BCB0();
int ts4l_forward_call_830A13E0(unsigned int a3, char * a4)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    t0 = *(unsigned int *)(a4 + 4);
    if (t0 == 19U) {
        return ts4l_call_seq_u32_off4_8348BD40();
    }
    if (t0 == 14U) {
        t1 = *(unsigned int *)(a4 + 16);
        t2 = *(unsigned int *)(char *)(unsigned long)(t1);
        if (t2 == 1U) {
            t3 = *(unsigned int *)((char *)(unsigned long)(t1) + 4);
            return ts4l_if_call_seq_u32_off0_8348BCB0(a3, t3, (a4 + 8));
        }
        return 0;
    }
    return 0;
}

unsigned long long ts4l_make_bit_mask64_830A6080(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

void ts4l_update_bit_range_mask_830A62E0(char * a3, int a4, unsigned int a5, unsigned int a6)
{
    unsigned long long t0;
    t0 = ((unsigned long long *)a3)[(a4 >> 16)];
    ((unsigned long long *)a3)[(a4 >> 16)] = (((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a6 - a5)))) >> (unsigned long long)((((unsigned int)(a4) & 0xFFU) + a5))) | t0);
}

void ts4l_update_bit_range_mask_830A6320(char * a3, int a4, unsigned int a5, unsigned int a6)
{
    unsigned long long t0;
    t0 = ((unsigned long long *)a3)[(a4 >> 16)];
    ((unsigned long long *)a3)[(a4 >> 16)] = (t0 & (~((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a6 - a5)))) >> (unsigned long long)((((unsigned int)(a4) & 0xFFU) + a5)))));
}

void ts4l_update_bit_range_mask_830A6360(char * a3, int a4, unsigned int a5)
{
    unsigned long long t0;
    t0 = ((unsigned long long *)a3)[(a4 >> 16)];
    ((unsigned long long *)a3)[(a4 >> 16)] = (((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a4)) & 0xFFULL)) | t0);
}

void ts4l_update_flags64_830A6398(char * a3)
{
    unsigned long long t0;
    t0 = *(unsigned long long *)(a3 + 24);
    *(unsigned long long *)(a3 + 24) = (t0 & 0xFFFFFFF7FFFFFFFFULL);
}

unsigned long long ts4l_make_bit_mask64_830AA060(unsigned int a3, unsigned int a4)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)(a4))) >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830AA080(int a3)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a3 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a3)) & 0xFFULL));
}

extern int fn_830B3558();
int ts4l_forward_call_830AA0D8(unsigned int a3, unsigned int a4)
{
    return fn_830B3558(a3, a4, 0, 0, 4, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

extern int fn_830AE288();
int ts4l_forward_call_830AA108(unsigned int a3, unsigned int a4)
{
    return fn_830AE288(a3, a4, 0, (0x8000000000000000ULL >> (unsigned long long)((a4 + (unsigned int)(32)))));
}

void ts4l_update_bit_range_mask_830AA268(char * a3, int a4)
{
    unsigned long long t0;
    t0 = ((unsigned long long *)a3)[(a4 >> 16)];
    ((unsigned long long *)a3)[(a4 >> 16)] = (t0 & (~((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((((unsigned int)((a4 >> 8)) & 0xFFU) - (unsigned int)(1))))) >> ((unsigned long long)((long long)(a4)) & 0xFFULL))));
}

unsigned int ts4l_count_zeros_830AB6A0(unsigned int a3)
{
    return ((unsigned int)(31) - TS4L_CLZ(a3));
}

unsigned int ts4l_count_zeros_830AB6B0(unsigned int a3)
{
    return ((unsigned int)(32) - TS4L_CLZ((a3 - (unsigned int)(1))));
}

unsigned int ts4l_count_zeros_830AB6C0(unsigned int a3)
{
    return ((unsigned int)(31) - TS4L_CLZ(a3));
}

extern char lbl_83086A40[];
unsigned int ts4l_field_op_830AB718(unsigned int a3)
{
    unsigned int t0;
    t0 = *(unsigned char *)((((char *)lbl_83086A40 + 1) + ((a3 & 0x3FU) << 1)));
    return t0;
}

unsigned long long ts4l_make_bit_mask64_830AE518(unsigned int a3)
{
    return (0x8000000000000000ULL >> ((unsigned long long)(a3) & 0xFFULL));
}

unsigned long long ts4l_make_bit_mask64_830B04C8(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

extern char lbl_83084840[];
float ts4l_float_op_830B0618(unsigned int a3)
{
    float t0;
    t0 = *(float *)((char *)lbl_83084840 + 52);
    return ((float)((double)((a3 >> 24))) * t0);
}

extern char lbl_83084840[];
float ts4l_float_op_830B0640(unsigned int a3)
{
    float t0;
    t0 = *(float *)((char *)lbl_83084840 + 52);
    return ((float)((double)(((a3 >> 16) & 0xFFU))) * t0);
}

extern char lbl_83084840[];
float ts4l_float_op_830B0668(unsigned int a3)
{
    float t0;
    t0 = *(float *)((char *)lbl_83084840 + 52);
    return ((float)((double)(((a3 >> 8) & 0xFFU))) * t0);
}

extern char lbl_83084840[];
float ts4l_float_op_830B0690(unsigned int a3)
{
    float t0;
    t0 = *(float *)((char *)lbl_83084840 + 52);
    return ((float)((double)((a3 & 0xFFU))) * t0);
}

void ts4l_update_flags64_830B1528(char * a3, unsigned int a4)
{
    unsigned int t0;
    unsigned long long t1;
    t0 = *(volatile unsigned int *)(a3 + 10680);
    *(volatile unsigned int *)(a3 + 10680) = ((t0 & 0xFFFFFBFFU) | (((a4 << 10) | (a4 >> 22)) & 0x400U));
    t1 = *(volatile unsigned long long *)(a3 + 32);
    *(volatile unsigned long long *)(a3 + 32) = (t1 | 0x2000000000ULL);
}

void ts4l_update_flags64_830B18C8(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10499) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 268435456ULL);
}

void ts4l_update_flags64_830B18E8(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10498) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 268435456ULL);
}

void ts4l_update_flags64_830B1908(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10497) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 268435456ULL);
}

void ts4l_update_flags64_830B1928(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10495) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 536870912ULL);
}

void ts4l_update_flags64_830B1948(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10494) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 536870912ULL);
}

void ts4l_update_flags64_830B1968(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned char *)(a3 + 10493) = a4;
    t0 = *(volatile unsigned long long *)(a3 + 16);
    *(volatile unsigned long long *)(a3 + 16) = (t0 | 536870912ULL);
}

void ts4l_update_flags64_830B1BA8(char * a3, unsigned int a4)
{
    unsigned long long t0;
    *(volatile unsigned int *)(a3 + 10752) = (a4 & 0xFFFFU);
    t0 = *(volatile unsigned long long *)(a3 + 32);
    *(volatile unsigned long long *)(a3 + 32) = (t0 | 524288ULL);
}
