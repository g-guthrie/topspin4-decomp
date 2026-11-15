/* W6B: shared declarations for the vector (VMX128) sources, on top of vx1_vector.h. */
#ifndef W6B_TYPES_H
#define W6B_TYPES_H
#include "vx1_vector.h"

/* Dead locals used to shift local symbol numbers (operand order, docs/agents/matching-tips.md). */
#ifdef _MSC_VER
#define W6B_UNUSED
#else
#define W6B_UNUSED __attribute__((unused))
#endif

#ifdef __cplusplus
extern "C" {
#endif

__vector4 __vslw(__vector4 a, __vector4 b);
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
__vector4 __vcmpgefpR(__vector4 a, __vector4 b, unsigned int *cr);
__vector4 __vcmpgtfpR(__vector4 a, __vector4 b, unsigned int *cr);

#ifdef _MSC_VER
#pragma intrinsic(__vslw, __vsldoi, __vcmpgefpR, __vcmpgtfpR)
#endif

#ifdef __cplusplus
}
#endif
#endif
