#ifndef W6C_TYPES_H
#define W6C_TYPES_H
#include "vx1_vector.h"

/* two vectors then two floats (0x30 bytes) */
typedef struct W6cVV {
    Vx1Vec a;       /* +0x00 */
    Vx1Vec b;       /* +0x10 */
    float x;        /* +0x20 */
    float y;        /* +0x24 */
} W6cVV;

static __inline void w6c_vmul(Vx1Vec *p, __vector4 k) { p->v = __vmulfp(p->v, k); }
static __inline void w6c_vadd(Vx1Vec *p, __vector4 k) { p->v = __vaddfp(p->v, k); }
static __inline void w6c_vsub(Vx1Vec *p, __vector4 k) { p->v = __vsubfp(p->v, k); }
static __inline void w6c_fmul(float *p, float k) { *p = *p * k; }
static __inline void w6c_fadd(float *p, float k) { *p = *p + k; }
static __inline void w6c_fsub(float *p, float k) { *p = *p - k; }

typedef struct W6cMat {
    Vx1Vec r[4];
} W6cMat;

#endif
