/* nearmiss: 25 off; first vec pair at offset 0 is CSEd with the owner pointer (target keeps a vor copy and stores via r31 after the callee addi), zero is born in f0+fmr instead of lfs f31, and 0xf4/0xf8 store order differs. Tried: C++ member, local vs extern zero, nested helpers, statement order (inert), auto-context (51 off). Odds improve if the owner class gets a shared type with a real base class at +0. */
/*
 * 0x882733F8: resets a slot-owner block: two zero vector pairs, scalar state, the four 0x2C-byte
 * slots at +0x40 (ts4_slot_quad_init_88273318, called), a record at +0xF0 and nine floats at +0x140.
 * Layout from the store offsets only; field meanings unknown.
 */
#include "vx1_vector.h"

extern const float g_ts4_event_value;    /* 0.0f */
extern const __vector4 lbl_880FC650;     /* {0, 0, 0, 0} */

typedef struct Q5sSlotOwnerQuad {
    char bytes[0xB0];
} Q5sSlotOwnerQuad;

void ts4_slot_quad_init_88273318(Q5sSlotOwnerQuad *q);

typedef struct Q5sSlotOwnerVecPair {
    __vector4 a;
    __vector4 b;
} Q5sSlotOwnerVecPair;

typedef struct Q5sSlotOwnerV3 {
    float x, y, z;
} Q5sSlotOwnerV3;

typedef struct Q5sSlotOwnerNine {
    Q5sSlotOwnerV3 r[3];
} Q5sSlotOwnerNine;

typedef struct Q5sSlotOwnerHead {
    Q5sSlotOwnerVecPair v0;   /* +0x00 */
    unsigned int w20;         /* +0x20 */
    float f24;                /* +0x24 */
    unsigned char b28, b29;   /* +0x28 */
    float f2c;                /* +0x2C */
    float f30;                /* +0x30 */
    char pad_0034[0xC];
} Q5sSlotOwnerHead;

typedef struct Q5sSlotOwner {
    Q5sSlotOwnerHead head;    /* +0x00 */
    Q5sSlotOwnerQuad slots;   /* +0x40 */
    float f0f0;               /* +0xF0 */
    unsigned int w0f4;        /* +0xF4 */
    float f0f8;               /* +0xF8 */
    unsigned char b0fc;       /* +0xFC */
    unsigned int w100;        /* +0x100 */
    unsigned char b104;       /* +0x104 */
    char pad_0105[0xB];
    Q5sSlotOwnerVecPair v1;   /* +0x110 */
    float f130;               /* +0x130 */
    unsigned char b134, b135; /* +0x134 */
    unsigned int w138;        /* +0x138 */
    char pad_013c[4];
    Q5sSlotOwnerNine nine;    /* +0x140 */
} Q5sSlotOwner;

static __inline void q5s_vec_pair_init(Q5sSlotOwnerVecPair *p)
{
    p->a = lbl_880FC650;
    p->b = p->a;
}

static __inline void q5s_v3_init(Q5sSlotOwnerV3 *v, float z)
{
    v->x = z;
    v->y = z;
    v->z = z;
}

static __inline void q5s_nine_init(Q5sSlotOwnerNine *n, float z)
{
    q5s_v3_init(&n->r[0], z);
    q5s_v3_init(&n->r[1], z);
    q5s_v3_init(&n->r[2], z);
}

static __inline void q5s_head_init(Q5sSlotOwnerHead *h, float z)
{
    q5s_vec_pair_init(&h->v0);
    h->w20 = 0;
    h->f24 = z;
    h->b28 = 0;
    h->b29 = 1;
    h->f2c = z;
    h->f30 = z;
}

void ts4_slot_owner_init_882733F8(Q5sSlotOwner *o)
{
    float z = g_ts4_event_value;

    q5s_head_init(&o->head, z);
    ts4_slot_quad_init_88273318(&o->slots);
    o->f0f0 = z;
    o->w0f4 = 0;
    o->f0f8 = z;
    o->b0fc = 0;
    o->w100 = 0;
    o->b104 = 0;
    q5s_vec_pair_init(&o->v1);
    o->f130 = z;
    o->b134 = 0;
    o->b135 = 0;
    o->w138 = 0;
    q5s_nine_init(&o->nine, z);
}
