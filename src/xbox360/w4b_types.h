/* Shared helpers for the w4b_* reconstructions (matching decompilation, Swing_DLL.xex). */
#ifndef W4B_TYPES_H
#define W4B_TYPES_H
#ifdef _MSC_VER
#define W4B_INLINE static __inline
#else
#define W4B_INLINE static inline
#endif
#ifdef _MSC_VER
#define W4B_PTR(x) (x)
#else
#define W4B_PTR(x) ((void *)(unsigned long)(x))
#endif
#define W4B_CAT2(a, b) a##b
#define W4B_CAT(a, b) W4B_CAT2(a, b)
#define W4B_PAD(n) char W4B_CAT(pad_, __COUNTER__)[n]
typedef unsigned char w4b_u8;
typedef unsigned int w4b_u32;
#endif
