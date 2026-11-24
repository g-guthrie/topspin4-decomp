/* Swing_DLL.xex 0x8816C648: destructor body: free the trailing vector at +0x58, then destroy the four 20-byte slots (vector at +8) in reverse order.
 * /Oc. The reverse array destroy is an inline taking (first, count) with p = first + count and while (--count >= 0) { --p; ... }. */
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct Slot { unsigned int a; unsigned int b; Vec items; } Slot;
typedef struct SlotBank { unsigned int head[2]; Slot slots[4]; Vec extra; } SlotBank;
void ts4_destroy_owned_object(void *obj);

static __inline void vec_free(Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void slots_destroy(Slot *first, int count)
{
    Slot *p = first + count;
    while (--count >= 0) {
        --p;
        vec_free(&p->items);
    }
}

void fn_8816C648(SlotBank *b)
{
    vec_free(&b->extra);
    slots_destroy(b->slots, 4);
}
