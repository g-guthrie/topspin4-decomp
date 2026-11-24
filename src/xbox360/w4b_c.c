#include "w4b_types.h"

struct W4bObjVtbl { void (*slot[8])(void *); };
struct W4bObj { struct W4bObjVtbl *vtbl; };
struct W4bB1 { W4B_PAD(0x7C); int key; };
struct W4bB2 { W4B_PAD(0x30); struct W4bB1 *b1; };
struct W4bB3 { W4B_PAD(0x20); struct W4bB2 *b2; W4B_PAD(4); int key; };
struct W4bC5C { W4B_PAD(0x5C); void *unused; };
struct W4bC48 { W4B_PAD(0x5C); void *target; };
struct W4bSelfC {
    W4B_PAD(0x48);
    struct W4bC48 *c48;
    struct W4bB3 *b3;
    W4B_PAD(0x54 - 0x50);
    struct W4bObj *obj;
    W4B_PAD(0x68 - 0x58);
    int arg68;
    W4B_PAD(0x3BC - 0x6C);
    int counter;
};

extern void ts4_call_with_range_endpoints_8869FCF0(void *target, int arg);
extern void fn_8869D8D0(struct W4bSelfC *self);

W4B_INLINE int *w4b_counter(struct W4bSelfC *s) { return &s->counter; }

/* Swing_DLL.xex 0x886A5C00 */
void ts4_tick_selection_886A5C00(struct W4bSelfC *self)
{
    if (self->b3->b2->b1->key == self->b3->key) {
        ts4_call_with_range_endpoints_8869FCF0(self->c48->target, self->arg68);
        fn_8869D8D0(self);
    }
    self->obj->vtbl->slot[3](self->obj);
    if (self->counter >= 0)
        --*w4b_counter(self);
}
