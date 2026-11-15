#include "w6b_types.h"

static __inline __vector4 w6b_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

typedef struct W6bHolder {
    unsigned char pad00[0x10];
    const float *vec; /* +0x10 */
} W6bHolder;

int ts4_vec3_equals_8864F618(const W6bHolder *self, const float *other)
{
    unsigned int cr;
    __vector4 a = w6b_load3(other);
    __vector4 b = w6b_load3(self->vec);
    __vcmpeqfpR(__vpermwi(b, 24), __vpermwi(a, 24), &cr);
    return (cr >> 7) & 1;
}

typedef struct W6bPair {
    __vector4 a;
    __vector4 b;
} W6bPair;

typedef struct W6bInit {
    __vector4 a;           /* +0x00 */
    __vector4 b;           /* +0x10 */
    unsigned char pad20[0x58 - 0x20];
    unsigned int z[5];     /* +0x58 */
    unsigned int one;      /* +0x6c */
} W6bInit;

extern const __vector4 lbl_880FC760;
extern const __vector4 lbl_880FC770;

void ts4_init_two_vectors_886E7738(W6bInit *s)
{
    __vector4 t0 = lbl_880FC770;
    __vector4 t1 = lbl_880FC760;
    s->a = t0;
    s->b = t1;
    s->z[0] = 0;
    s->z[1] = 0;
    s->z[2] = 0;
    s->z[3] = 0;
    s->z[4] = 0;
    s->one = 1;
}

extern char lbl_880F34BC[];

typedef struct W6bVecPair {
    __vector4 a;
    __vector4 b;
} W6bVecPair;

static __inline void w6b_init_pair(W6bVecPair *p)
{
    __vector4 t0 = lbl_880FC770;
    __vector4 t1 = lbl_880FC760;
    p->a = t0;
    p->b = t1;
}

typedef struct W6bObjA {
    void *vtbl;                 /* +0x00 */
    unsigned char pad04[0x1c - 0x04];
    unsigned int f1c;           /* +0x1c */
    W6bVecPair pair;            /* +0x20 */
    unsigned char pad40[0x78 - 0x40];
    unsigned int z[5];          /* +0x78 */
    unsigned int one;           /* +0x8c */
} W6bObjA;

void fn_88617D88(W6bObjA *self);

W6bObjA *ts4_construct_obj_886E7EF0(W6bObjA *self)
{
    fn_88617D88(self);
    self->vtbl = lbl_880F34BC;
    self->f1c = 0;
    w6b_init_pair(&self->pair);
    self->one = 1;
    self->z[0] = 0;
    self->z[1] = 0;
    self->z[2] = 0;
    self->z[3] = 0;
    self->z[4] = 0;
    return self;
}
