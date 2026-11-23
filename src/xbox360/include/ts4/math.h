/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: math.h
 * Vectors, lines and curve lists. Conventions and evidence tags: docs/agents/types.md.
 *
 * Vector register type: `__vector4` comes from src/xbox360/vx1_vector.h (16-byte aligned, passinreg). A source
 * that needs the 4-aligned flavour includes ts4_vector.h BEFORE ts4/ts4.h; this header then leaves it alone.
 */
#ifndef TS4_MATH_H
#define TS4_MATH_H

#include "base.h"
#include "containers.h"
#ifndef TS4_VECTOR_H
#include "../../vx1_vector.h"
#endif

/*
 * A 16-byte vector field. One storage, three views; pick the view that gives the original instruction:
 *   .v     whole-vector access through the VMX register type (lvx128 / stvx128, intrinsics)
 *   .f[i]  scalar component access (lfs / stfs)
 *   .q[i]  8-byte halves: aggregate copies compile to ld / std pairs (bm: ts4_bm_vec4)
 * Checked byte-exact against private `__vector4` fields (0x8826AC10, 0x88189888) and against the bm union
 * (0x888AB558); see the validation table in docs/agents/types.md.
 */
typedef union Ts4Vec4 {
    __vector4 v;
    float f[4];
    unsigned long long q[2];
} Ts4Vec4;
TS4_ASSERT_SIZE(Ts4Vec4, 0x10);

/* Line: point + unit direction (0x20 bytes). q5: Q5Line; rt1: Rt1Line. */
typedef struct Ts4Line {
    Ts4Vec4 point;                               /* +0x00 V 8826AC10 88189888 8826D3A0 */
    Ts4Vec4 dir;                                 /* +0x10 V 8826AC10 88189888 8826D3A0 (unit length) */
} Ts4Line;
TS4_ASSERT_OFFSET(Ts4Line, dir, 0x10);
TS4_ASSERT_SIZE(Ts4Line, 0x20);

/* Ramp list {InStart, InStop, OutStart, OutStop}[] evaluated by ts4_range_lookup_881899D8. rt1: Rt1RangeList. */
typedef Ts4RelArray12 Ts4RangeList;

#ifdef __cplusplus
/*
 * C++ flavour of a vector value with a user-declared destructor. The original vector class had one: by-value
 * temporaries of this type are real memory temporaries (stored to the stack, block-copied with ld/std), which
 * a plain struct does not reproduce (see src/xbox360/q5_line_project.cpp, q5_path_sample.cpp).
 * Same layout as Ts4Vec4 / Ts4Line; use these names in C++ sources that need that codegen.
 */
struct Ts4VecD {
    __vector4 v;
    Ts4VecD() {}
    ~Ts4VecD() {}
};
struct Ts4LineD {
    Ts4VecD point;                               /* +0x00 V 8826D3A0 */
    Ts4VecD dir;                                 /* +0x10 V 8826D3A0 */
};
TS4_STATIC_ASSERT(sizeof(Ts4VecD) == 0x10, Ts4VecD_size);
TS4_STATIC_ASSERT(sizeof(Ts4LineD) == 0x20, Ts4LineD_size);
#endif

/* ---- byte-matched functions (current symbol names, config/54540859/symbols.txt) ---- */
TS4_EXTERN_C_BEGIN
/* out->point = *point; out->dir = normalize3(*dir)                                             8826AC10 */
void ts4_line_init_normalized_8826AC10(Ts4Line *out, const __vector4 *point, const __vector4 *dir);
/* out->point = *from; out->dir = normalize3(*to - *from)                                       88189888 */
void ts4_line_init_two_points_88189888(Ts4Line *out, const __vector4 *from, const __vector4 *to);
/* closest point on the line to *p and its parameter t. The matched source is C++ and takes the destructor
 * flavour (Ts4VecD / Ts4LineD), which is what gives its codegen; C callers see the same layout.  8826D3A0 */
#ifdef __cplusplus
void ts4_line_closest_point_8826D3A0(const Ts4VecD *p, const Ts4LineD *line, Ts4VecD *out, float *t_out);
#else
void ts4_line_closest_point_8826D3A0(const __vector4 *p, const Ts4Line *line, __vector4 *out, float *t_out);
#endif
/* clamped ramp over a Ts4RangeList (x in f1, list in r4)                                       881899D8 */
float ts4_range_lookup_881899D8(float x, const void *list);
/* game RNG: uniform in [lo, hi) (rng = World+0xB4)                                             8861E598 */
float ts4_rng_range_8861E598(void *rng, float lo, float hi);
TS4_EXTERN_C_END

#endif /* TS4_MATH_H */
