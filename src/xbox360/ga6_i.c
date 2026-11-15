/*
 * GA6: gameplay object helpers (vector pop, vector copies, forwarders).
 */
#include "ts4_vector.h"

typedef unsigned int ts4_word;

void fn_886CDFD8(void *self);
void ts4_r2_swing_ring_release_entry_886DC9C0(void *self, ts4_word item);
void fn_886D3A00(void *list, void *item, int a, ts4_word b, int c);
void fn_886DBF40(void *a, ts4_word b, void *c, ts4_word d, int e, ts4_word f);
void ts4_init_state_8864A920(void *obj, ts4_word a, ts4_word b, void *owner);
void fn_8864A770(void *obj, ts4_word a, void *b, ts4_word c);
void fn_8864A5E8(void *obj);
void ts4_if_call_seq_u32_off40_8864A8A8(void *obj);

struct Ga6VecPtrs {
    char pad_00[0x568];
    __vector4 *dst_a;          /* +0x568 */
    char pad_56c[4];
    __vector4 src;             /* +0x570 */
};
struct Ga6VecPtrs2 {
    char pad_00[0x564];
    __vector4 *dst_b;          /* +0x564 */
    __vector4 *dst_a;          /* +0x568 */
    char pad_56c[4];
    __vector4 src;             /* +0x570 */
};

/* Copy the vector at +0x570 to *(+0x568), then that copy to *(+0x564), and run fn_886CDFD8. */
void ga6_copy_vectors_886D28E8(struct Ga6VecPtrs2 *self)
{
    *self->dst_a = self->src;
    *self->dst_b = *self->dst_a;
    fn_886CDFD8(self);
}

struct Ga6PtrVec {
    ts4_word *begin;
    ts4_word *end;
};
struct Ga6Stack {
    char pad_00[0x5C];
    struct Ga6PtrVec vec;      /* +0x5C */
};

static void ga6_ptr_vec_pop(struct Ga6PtrVec *v)
{
    v->end = v->end - 1;
}

/* Release the last entry of the vector at +0x5C and shrink it by one slot. */
void ga6_pop_back_886DCFB0(struct Ga6Stack *self)
{
    ts4_r2_swing_ring_release_entry_886DC9C0(self, self->vec.end[-1]);
    ga6_ptr_vec_pop(&self->vec);
}

/* ---- 886DFC38: clear a vector of 16-byte elements (erase(begin, end)) ---- */
struct Ga6Vec16Data {
    __vector4 *begin;          /* +0x00 */
    __vector4 *end;            /* +0x04 */
};
struct Ga6Vec16 {
    char pad_00[4];
    ts4_word w04;              /* +0x04 */
    ts4_word w08;              /* +0x08 */
    struct Ga6Vec16Data vec;   /* +0x0C */
};
static __vector4 *ga6_copy_vec16(__vector4 *src, __vector4 *src_end, __vector4 *dest)
{
    int n = (int)((char *)src_end - (char *)src) >> 4;
    for (; n > 0; --n)
        *dest++ = *src++;
    return dest;
}
void ga6_clear_vec16_886DFC38(struct Ga6Vec16 *self)
{
    struct Ga6Vec16Data *v = &self->vec;
    __vector4 *first = v->begin;
    __vector4 *last = v->end;
    v->end = ga6_copy_vec16(last, v->end, first);
    self->w08 = 0;
    self->w04 = 0;
}

/* ---- 886D19C8: initialise a four-vector block with the default pose ---- */
extern char lbl_880FC650[];
extern float lbl_8814B440;
struct Ga6Pose { __vector4 v[4]; ts4_word w40; float f44; };
struct Ga6PoseHolder { char pad_00[8]; struct Ga6Pose *pose; char pad_0c[0xC]; int w18; };
