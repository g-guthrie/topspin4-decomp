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

/* Added by family BM; each emits the named VMX128 instruction (cl 16.00.10224.00 /O2 /Oi, checked
 * with a one-function compile and disassembly). Immediates must be compile-time constants. */
__vector4 __vspltw(__vector4 a, int imm);                        /* vspltw128 */
__vector4 __vspltisw(int imm);                                   /* vspltisw */
__vector4 __vperm(__vector4 a, __vector4 b, __vector4 c);        /* vperm128 */
__vector4 __vpermwi(__vector4 a, int imm);                       /* vpermwi128 */
__vector4 __vsel(__vector4 a, __vector4 b, __vector4 c);         /* vsel */
__vector4 __vrlimi(__vector4 a, __vector4 b, int mask, int rot); /* vrlimi128 (a is also the destination) */
__vector4 __vmrghw(__vector4 a, __vector4 b);                    /* vmrghw128 */
__vector4 __vmrglw(__vector4 a, __vector4 b);                    /* vmrglw128 */
__vector4 __vmsum3fp(__vector4 a, __vector4 b);                  /* vmsum3fp128 (3-element dot product) */
__vector4 __vmsum4fp(__vector4 a, __vector4 b);                  /* vmsum4fp128 (4-element dot product) */
__vector4 __vcfsx(__vector4 a, int imm);                         /* vcfsx128 */
__vector4 __vcfux(__vector4 a, int imm);                         /* vcfux128 */
__vector4 __vctsxs(__vector4 a, int imm);                        /* vctsxs128 */
__vector4 __vctuxs(__vector4 a, int imm);                        /* vctuxs128 */
__vector4 __vrfin(__vector4 a);                                  /* vrfin128 (round to nearest) */
__vector4 __vrfiz(__vector4 a);                                  /* vrfiz128 (truncate) */
__vector4 __vrfim(__vector4 a);                                  /* vrfim128 (floor) */
__vector4 __vrfip(__vector4 a);                                  /* vrfip128 (ceil) */
__vector4 __vexptefp(__vector4 a);                               /* vexptefp128 */
__vector4 __vlogefp(__vector4 a);                                /* vlogefp128 */
__vector4 __vcmpgtfp(__vector4 a, __vector4 b);                  /* vcmpgtfp128 */
__vector4 __vcmpgefp(__vector4 a, __vector4 b);                  /* vcmpgefp128 */
__vector4 __vcmpeqfp(__vector4 a, __vector4 b);                  /* vcmpeqfp128 */
__vector4 __vupkd3d(__vector4 a, int imm);                       /* vupkd3d128 */
__vector4 __lvlx(const void *p, int off);                        /* lvlx */
__vector4 __lvrx(const void *p, int off);                        /* lvrx */
void __stvlx(__vector4 v, void *p, int off);                     /* stvlx128 */
void __stvrx(__vector4 v, void *p, int off);                     /* stvrx128 */

#ifdef _MSC_VER
#pragma intrinsic(__vaddfp, __vsubfp, __vmulfp, __vmaddfp, __vnmsubfp)
#pragma intrinsic(__vmaxfp, __vminfp, __vrsqrtefp, __vrefp, __vand, __vor, __vxor)
#pragma intrinsic(__vspltw, __vspltisw, __vperm, __vpermwi, __vsel, __vrlimi, __vmrghw, __vmrglw)
#pragma intrinsic(__vmsum3fp, __vmsum4fp, __vcfsx, __vcfux, __vctsxs, __vctuxs)
#pragma intrinsic(__vrfin, __vrfiz, __vrfim, __vrfip, __vexptefp, __vlogefp)
#pragma intrinsic(__vcmpgtfp, __vcmpgefp, __vcmpeqfp, __vupkd3d, __lvlx, __lvrx, __stvlx, __stvrx)
#endif

#endif /* TS4_VECTOR_H */
