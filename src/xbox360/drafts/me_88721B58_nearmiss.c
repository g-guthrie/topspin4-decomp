/* NEAR MISS (agO round 2, 2026-11-19): 2 off on plain and LTCG (/Oc): the reload of begin is hoisted above the end store.
 * Tried a begin local, an erase helper and a second base expression. */
/* Swing_DLL.xex 0x88721B58: clears and frees the vector at +0xc: erases [begin, end) through fn_88186110, then releases the buffer
 * to the global allocator lbl_88D45B38 (with the owner slot at vec+8) or fn_885651F8. */
typedef struct Item Item;
typedef struct Vec { Item *begin; Item *end; void *alloc; } Vec;
typedef struct Obj { char pad[0xc]; Vec vec; } Obj;
extern void *lbl_88D45B38;
Item *fn_88186110(Item *first, Item *last, Item *dest);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, Item *p, void *a);
void fn_885651F8(Item *p);

static __inline void vec_tidy(Vec *v)
{
    v->end = fn_88186110(v->end, v->end, v->begin);
    if (v->begin) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, v->begin, v->alloc);
        else
            fn_885651F8(v->begin);
    }
}

void fn_88721B58(Obj *o)
{
    vec_tidy(&o->vec);
}
