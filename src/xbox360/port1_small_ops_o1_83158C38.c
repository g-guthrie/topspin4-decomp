/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l11_small_ops_o1_83158C38.c.
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

extern char lbl_88D2F1A8[];

/* Swing_DLL.xex 0x8859AB28 */
void ts4_barrier_io_8859AB28(void)
{
    unsigned int t0;
    t0 = TS4_LWBR((char *)(unsigned long)(2146048000U));
    *(unsigned int *)lbl_88D2F1A8 = t0;
}

