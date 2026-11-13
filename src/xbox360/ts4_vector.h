/*
 * Minimal Xenon VMX128 vector type and intrinsic declarations for matching.
 *
 * Written for this project (not taken from any SDK header). With the Xbox 360
 * compiler, a 16-byte struct marked __declspec(passinreg) lives in vector
 * registers: dereferencing a `__vector4 *` emits lvx128/stvx128, and the
 * declared intrinsics below emit their VMX128 instructions once listed in
 * `#pragma intrinsic`. Verified with cl 16.00.10224.00 /O2 /Oi:
 *     *d = __vmaddfp(*s, *t, __vaddfp(*s, *t));
 *   compiles to lvx128, lvx128, vaddfp, vmaddfp, stvx128.
 *
 * On a host compiler the same names are plain declarations so sources still
 * pass the repository's syntax check; nothing here is executable on the host.
 */
#ifndef TS4_VECTOR_H
#define TS4_VECTOR_H

#ifdef _MSC_VER
typedef struct __declspec(passinreg) __vector4 {
    float v[4];
} __vector4;
#else
typedef struct __vector4 {
    float v[4];
} __vector4;
#endif

__vector4 __vaddfp(__vector4 a, __vector4 b);
__vector4 __vsubfp(__vector4 a, __vector4 b);
__vector4 __vmulfp(__vector4 a, __vector4 b);
__vector4 __vmaddfp(__vector4 a, __vector4 b, __vector4 c);
__vector4 __vnmsubfp(__vector4 a, __vector4 b, __vector4 c);
__vector4 __vmaxfp(__vector4 a, __vector4 b);
__vector4 __vminfp(__vector4 a, __vector4 b);
__vector4 __vrsqrtefp(__vector4 a);
__vector4 __vrefp(__vector4 a);
__vector4 __vand(__vector4 a, __vector4 b);
__vector4 __vor(__vector4 a, __vector4 b);
__vector4 __vxor(__vector4 a, __vector4 b);

#ifdef _MSC_VER
#pragma intrinsic(__vaddfp, __vsubfp, __vmulfp, __vmaddfp, __vnmsubfp)
#pragma intrinsic(__vmaxfp, __vminfp, __vrsqrtefp, __vrefp, __vand, __vor, __vxor)
#endif

#endif /* TS4_VECTOR_H */
