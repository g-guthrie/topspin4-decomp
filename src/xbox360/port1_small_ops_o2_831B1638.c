/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l11_small_ops_o2_831B1638.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
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
#define TS4_EMIT(x) __emit(x)
#define TS4_STWBR(v, p) __storewordbytereverse(v, 0, p)
#define TS4_LWBR(p) __loadwordbytereverse(0, p)
#define TS4_CLZ(x) _CountLeadingZeros(x)
#define TS4_FABS(x) __fabs(x)
#else
#define TS4_EMIT(x) ((void)0)
#define TS4_STWBR(v, p) (*(unsigned int *)(p) = (v))
#define TS4_LWBR(p) (*(unsigned int *)(p))
#define TS4_CLZ(x) ((unsigned int)(x))
#define TS4_FABS(x) ((x) < 0 ? -(x) : (x))
#endif

extern int fn_8828E000();

/* Swing_DLL.xex 0x888DF8C0 */
int ts4_forward_call_888DF8C0(unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
    return fn_8828E000(a3, a4, a5, a6, a7, (0x8000000000000000ULL >> (unsigned long long)((((((unsigned int)(95) - a4) * (unsigned int)(21846)) >> 16) + (unsigned int)(32)))));
}

/* Swing_DLL.xex 0x8890C580 */
unsigned long long ts4_make_bit_mask64_8890C580(unsigned int a3, unsigned int a4, unsigned int a5)
{
    return ((unsigned long long)(((long long)(0x8000000000000000ULL) >> (unsigned long long)((a5 - a4)))) >> (unsigned long long)(((a3 & 0xFFU) + a4)));
}

