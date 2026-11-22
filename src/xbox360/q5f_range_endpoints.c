/* Top Spin 4 (Xbox 360, Swing_DLL.xex) - Q5 gameplay: forward the current and the last
 * element of a keyframe list, or the owner's default pair, to fn_88692670.
 * (src/xbox360/w6b_d.c carries an older near-miss of the same function.) */
#include "ts4_vector.h"

typedef struct Q5fKeyElem { __vector4 v[3]; } Q5fKeyElem;      /* 0x30 bytes */
typedef struct Q5fKeyList {
    unsigned char pad0[0x5a0];
    Q5fKeyElem *begin;          /* +0x5a0 */
    Q5fKeyElem *end;            /* +0x5a4 */
    unsigned char pad5a8[0x5bc - 0x5a8];
    unsigned int index;         /* +0x5bc */
} Q5fKeyList;
typedef struct Q5fKeyDefault {
    unsigned char pad0[0x100];
    __vector4 a;                /* +0x100 */
    __vector4 b;                /* +0x110 */
} Q5fKeyDefault;
typedef struct Q5fKeyOwner {
    unsigned char pad0[0x20];
    Q5fKeyDefault *def20;       /* +0x20 */
    Q5fKeyList *list24;         /* +0x24 */
} Q5fKeyOwner;

void fn_88692670(void *arg, __vector4 a, __vector4 b);

static __inline Q5fKeyElem *q5f_key_current(Q5fKeyList *l)
{
    Q5fKeyElem *r = 0;
    if (l->begin != l->end)
        r = l->begin + l->index;
    return r;
}

/* back(): the end pointer is read again through its address, as the target does */
static __inline Q5fKeyElem *q5f_key_last(Q5fKeyList *l)
{
    Q5fKeyElem *r = 0;
    if (l->begin != l->end) {
        Q5fKeyElem **pe = &l->end;
        r = *pe - 1;
    }
    return r;
}

/* Swing_DLL.xex 0x8869FCF0 */
void ts4_call_with_range_endpoints_8869FCF0(Q5fKeyOwner *self, void *arg)
{
    Q5fKeyList *l = self->list24;
    Q5fKeyElem *cur = q5f_key_current(l);
    Q5fKeyElem *last = q5f_key_last(l);
    if (cur != 0 && last != 0)
        fn_88692670(arg, cur->v[0], last->v[0]);
    else
        fn_88692670(arg, self->def20->a, self->def20->b);
}
