#ifndef GA3_TYPES_H
#define GA3_TYPES_H
/* GA3: shared helpers for the ga3_* gameplay sources (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#ifdef _MSC_VER
#define GA3_INLINE static __forceinline
#else
#define GA3_INLINE static inline
#endif

/* Self-relative array header: byte offset from this header to the first element (-1 = empty), element count. */
struct Ga3RelArr {
    int offset;
    int count;
};

/* 32-bit id/name hash. Passing it as a one-member struct by value reproduces the original
 * codegen (constant built in a scratch register, then moved into the argument register). */
struct Ga3Id {
    unsigned int value;
};
#endif
