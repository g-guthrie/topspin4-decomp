/*
 * VX1: helpers for matching the game's VMX128 code (docs/agents/near-misses/VX1.md).
 *
 * The game was written against an xnamath-style vector library: XMVECTOR is __vector4 passed by
 * value in v1.., component setters are `__lvlx(&x, 0)` + `__vrlimi`, a scalar splat is
 * `__lvlx(&x, 0)` + `__vspltw(.., 0)`. The helpers below reproduce those inline bodies under
 * project names (written for this project, not copied from any SDK header).
 *
 * Also gives C++ sources the intrinsic declarations with C linkage (ts4_vector.h has no
 * extern "C", so a .cpp that includes it directly fails to link: unresolved ?__vrlimi@@...).
 */
#ifndef VX1_VECTOR_H
#define VX1_VECTOR_H

#ifdef TS4_VECTOR_H
#error "include vx1_vector.h instead of ts4_vector.h (it defines a 16-byte aligned __vector4)"
#endif
#define TS4_VECTOR_H 1 /* ts4_vector.h included later becomes a no-op */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * __vector4 with 16-byte alignment. ts4_vector.h declares it with alignment 4
 * (__alignof(__vector4) == 4, sizeof(struct { int a; __vector4 v; }) == 0x14), so a struct or
 * union holding one is copied with four lwz/stw pairs, and stack slots are only 4-aligned.
 * With __declspec(align(16)) a struct copy is two ld/std pairs, as in the game
 * (0x88670C20), and passinreg still puts by-value vectors in v1.. (checked: `return __vaddfp(a, b)`
 * compiles to `vaddfp v1,v1,v2; blr`).
 */
#ifdef _MSC_VER
typedef struct __declspec(passinreg) __declspec(align(16)) __vector4 {
    float v[4];
} __vector4;
#else
typedef struct __attribute__((aligned(16))) __vector4 {
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

/* Added by VX1 (names from the intrinsic table in c1.dll). */
__vector4 __vcmpeqfpR(__vector4 a, __vector4 b, unsigned int *cr); /* vcmpeqfp128. (RT1) */
void __stvewx(__vector4 v, void *p, int off);                      /* stvewx128 */
#ifdef _MSC_VER
#pragma intrinsic(__vcmpeqfpR, __stvewx)
#endif

/* vrlimi128 vD,vX,8,0: replace lane x. */
static __inline __vector4 vx1_set_x(__vector4 v, float x)
{
    __vector4 t = __lvlx(&x, 0);
    return __vrlimi(v, t, 8, 0);
}

/* vrlimi128 vD,vX,4,3: replace lane y. */
static __inline __vector4 vx1_set_y(__vector4 v, float y)
{
    __vector4 t = __lvlx(&y, 0);
    return __vrlimi(v, t, 4, 3);
}

/* vrlimi128 vD,vX,2,2: replace lane z. */
static __inline __vector4 vx1_set_z(__vector4 v, float z)
{
    __vector4 t = __lvlx(&z, 0);
    return __vrlimi(v, t, 2, 2);
}

/* vrlimi128 vD,vX,1,1: replace lane w. */
static __inline __vector4 vx1_set_w(__vector4 v, float w)
{
    __vector4 t = __lvlx(&w, 0);
    return __vrlimi(v, t, 1, 1);
}

/* lvlx128 + vspltw128 0: all four lanes = x. */
static __inline __vector4 vx1_replicate(float x)
{
    __vector4 t = __lvlx(&x, 0);
    return __vspltw(t, 0);
}

/*
 * A vector member changed in place through a pointer to it. The store is kept, the following read
 * of the member is forwarded late and appears as `vor128 vD,vS,vS` (the vector form of CL1's
 * clrrwi copy), and later scalar accesses stay below the store.
 */
typedef struct Vx1Vec {
    __vector4 v;
} Vx1Vec;

static __inline void vx1_vec_set_x(Vx1Vec *p, float x) { p->v = vx1_set_x(p->v, x); }
static __inline void vx1_vec_set_y(Vx1Vec *p, float y) { p->v = vx1_set_y(p->v, y); }
static __inline void vx1_vec_set_z(Vx1Vec *p, float z) { p->v = vx1_set_z(p->v, z); }
static __inline float vx1_vec_x(const Vx1Vec *p) { return p->v.v[0]; }
static __inline float vx1_vec_y(const Vx1Vec *p) { return p->v.v[1]; }
static __inline float vx1_vec_z(const Vx1Vec *p) { return p->v.v[2]; }

#ifdef __cplusplus
}
#endif

#endif /* VX1_VECTOR_H */
