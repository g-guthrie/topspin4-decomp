/*
 * 0x88273318: clears four consecutive 0x2C-byte slots: every float to 0.0f (read once from the
 * file-static zero, 0x8814B440 in the target) and every flag byte to 0.
 *
 * Slot layout (from the store offsets): {float, u8} at +0x00, three floats at +0x08..+0x10,
 * {float, u8, u8} at +0x14, two floats at +0x1C/+0x20, {u8, float} at +0x24.
 *
 * Codegen: one sub_init call per slot with nested inline helpers for the {value, flag} groups keeps
 * the dead `addi r10,r3,K` of each slot address (DA1 rule). The last group must be a {u8, float}
 * helper: plain stores or a {float, u8} group at +0x20 swap the stfs 0x20 / stb 0x24 pair.
 */
static const float q5s_slot_zero = 0.0f;

typedef struct Q5sSlotVf {
    float v;
    unsigned char on;
} Q5sSlotVf; /* {float, u8} */

typedef struct Q5sSlotVff {
    float v;
    unsigned char on, b;
} Q5sSlotVff; /* {float, u8, u8} */

typedef struct Q5sSlotFv {
    unsigned char on;
    float v;
} Q5sSlotFv; /* {u8, float} */

typedef struct Q5sSlot {
    Q5sSlotVf p;     /* +0x00 */
    float c, d, e;   /* +0x08 */
    Q5sSlotVff q;    /* +0x14 */
    float i, j;      /* +0x1C */
    Q5sSlotFv w;     /* +0x24 */
} Q5sSlot;           /* 0x2C */

typedef struct Q5sSlotQuad {
    Q5sSlot s[4];
} Q5sSlotQuad;

static __inline void q5s_slot_vf_init(Q5sSlotVf *x) { x->v = q5s_slot_zero; x->on = 0; }
static __inline void q5s_slot_vff_init(Q5sSlotVff *y) { y->v = q5s_slot_zero; y->on = 0; y->b = 0; }
static __inline void q5s_slot_fv_init(Q5sSlotFv *w) { w->on = 0; w->v = q5s_slot_zero; }

static __inline void q5s_slot_init(Q5sSlot *s)
{
    q5s_slot_vf_init(&s->p);
    s->c = q5s_slot_zero;
    s->d = q5s_slot_zero;
    s->e = q5s_slot_zero;
    q5s_slot_vff_init(&s->q);
    s->i = q5s_slot_zero;
    s->j = q5s_slot_zero;
    q5s_slot_fv_init(&s->w);
}

void ts4_slot_quad_init_88273318(Q5sSlotQuad *q)
{
    q5s_slot_init(&q->s[0]);
    q5s_slot_init(&q->s[1]);
    q5s_slot_init(&q->s[2]);
    q5s_slot_init(&q->s[3]);
}
