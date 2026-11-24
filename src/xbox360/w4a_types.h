/* Shared helpers for the w4a_* reconstructions (matching decompilation, Swing_DLL.xex). */
#ifndef W4A_TYPES_H
#define W4A_TYPES_H
#ifdef _MSC_VER
#define W4A_INLINE static __inline
#else
#define W4A_INLINE static inline
#endif
#define W4A_CAT2(a, b) a##b
#define W4A_CAT(a, b) W4A_CAT2(a, b)
#define W4A_PAD(n) char W4A_CAT(pad_, __COUNTER__)[n]
typedef unsigned char w4a_u8;
typedef unsigned int w4a_u32;
#endif
