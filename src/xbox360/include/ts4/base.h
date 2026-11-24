/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: base.h
 * Macros shared by every ts4/ header. Conventions: docs/agents/types.md.
 *
 * The headers are plain C that also compiles as C++ (cl 16.00.10224 PPC decides by file extension).
 * They declare no scalar typedefs on purpose: matched sources bring their own (ts4_u8, u32, ...), and the
 * load/store width of a field is part of the proof, so fields use the built-in types directly.
 */
#ifndef TS4_BASE_H
#define TS4_BASE_H

#ifdef __cplusplus
#define TS4_EXTERN_C extern "C"
#define TS4_EXTERN_C_BEGIN extern "C" {
#define TS4_EXTERN_C_END }
#else
#define TS4_EXTERN_C
#define TS4_EXTERN_C_BEGIN
#define TS4_EXTERN_C_END
#endif

#ifdef _MSC_VER
#define TS4_NOINLINE __declspec(noinline)
#define TS4_INLINE __inline
/* cl 16 has no __builtin_offsetof and the build has no CRT headers; this form is a constant expression for it. */
#define TS4_OFFSETOF(T, f) ((unsigned int)&((T *)0)->f)
#else
#define TS4_NOINLINE
#define TS4_INLINE inline
#define TS4_OFFSETOF(T, f) __builtin_offsetof(T, f)
#if defined(__cplusplus) && defined(__GNUC__)
/* a few C++ views embed objects with a vtable; offsetof on them is fine for every compiler we use */
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
#endif

/*
 * Static layout asserts (typedef of a char array with size 1 or -1: works in C89, C11 and C++).
 * The target is ILP32 (4-byte pointers). On a 64-bit host the pointer fields are wider, so the asserts are
 * only armed when sizeof(void *) == 4: under the matching compiler, under `cc -m32`, and under
 * `clang -target powerpc-unknown-linux-gnu -fsyntax-only` (the check used in docs/agents/types.md).
 */
#define TS4_CAT2_(a, b) a##b
#define TS4_CAT2(a, b) TS4_CAT2_(a, b)
#define TS4_STATIC_ASSERT(cond, tag) typedef char TS4_CAT2(ts4_static_assert_, tag)[(cond) ? 1 : -1]
#define TS4_ASSERT_OFFSET(T, f, off) \
    TS4_STATIC_ASSERT(sizeof(void *) != 4 || TS4_OFFSETOF(T, f) == (off), TS4_CAT2(T, TS4_CAT2(_at_, f)))
#define TS4_ASSERT_SIZE(T, size) \
    TS4_STATIC_ASSERT(sizeof(void *) != 4 || sizeof(T) == (size), TS4_CAT2(T, _size))

#endif /* TS4_BASE_H */
