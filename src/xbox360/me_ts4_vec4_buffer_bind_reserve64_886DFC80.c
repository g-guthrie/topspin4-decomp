/* Swing_DLL.xex 0x886DFC80: binds the owner to a source (+4) and its block at source->base + 0x330 (+8), then reserves 64 __vector4 slots (16-byte aligned heap allocation, lvx/stvx copy).
 * /Oc. Same forceinline allocate/reserve as 8890EBB8 with alignment 16. */
#include "vx1_vector.h"
typedef struct V4Vec { __vector4 *first; __vector4 *last; __vector4 *end; } V4Vec;
typedef struct Source { unsigned char p0[0x14]; unsigned char *base; } Source;
typedef struct Owner { unsigned int f0; Source *src; unsigned char *block; V4Vec items; } Owner;
extern void *lbl_88D45B38;
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
void *fn_88613570(void *alloc, unsigned int size, unsigned int align, void *owner);
void ts4_destroy_owned_object(void *obj);

static __forceinline __vector4 *allocate(V4Vec *v, unsigned int n)
{
    return (__vector4 *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, n * sizeof(__vector4), 16, &v->end);
}

static __forceinline void reserve(V4Vec *v, unsigned int n)
{
    __vector4 *first = v->first;
    if ((unsigned int)(v->end - first) < n) {
        __vector4 *last = v->last;
        int size = last - first;
        if (first != 0) {
            __vector4 *buffer = allocate(v, n);
            __vector4 *src = first;
            __vector4 *dest = buffer;
            for (; src != last; ++src) {
                if (dest) *dest = *src;
                ++dest;
            }
            first = buffer;
            ts4_destroy_owned_object(v->first);
        } else {
            first = allocate(v, n);
        }
        v->first = first;
        v->last = first + size;
        v->end = first + n;
    }
}

void fn_886DFC80(Owner *o, Source *src)
{
    o->src = src;
    o->block = src->base + 0x330;
    reserve(&o->items, 64);
}
