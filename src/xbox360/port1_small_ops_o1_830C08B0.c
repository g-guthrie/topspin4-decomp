/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l11_small_ops_o1_830C08B0.c.
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



/* Swing_DLL.xex 0x882A28B8 */
void ts4_barrier_io_882A28B8(void)
{
    *(unsigned int *)((char *)(unsigned long)(2143813632U) + 12820) = 7;
    TS4_EMIT(0x7C0006AC);
    *(unsigned int *)((char *)(unsigned long)(2143813632U) + 13320) = 2048;
    TS4_EMIT(0x7C0006AC);
}

