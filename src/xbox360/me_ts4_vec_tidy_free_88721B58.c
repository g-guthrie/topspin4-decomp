/* Swing_DLL.xex 0x88721B58: clears and frees the vector at +0xc: erases [begin, end) through fn_88186110, then releases the buffer
 * to the global allocator lbl_88D45B38 (with the owner slot at vec+8) or fn_885651F8. agO: the Item **pe local for the end store keeps the begin reload after it (no volatile); plain and LTCG. */
typedef struct Item Item;
typedef struct Vec { Item *begin; Item *end; void *alloc; } Vec;
typedef struct Obj { char pad[0xc]; Vec vec; } Obj;
extern void *lbl_88D45B38;
Item *fn_88186110(Item *first, Item *last, Item *dest);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, Item *p, void *a);
void fn_885651F8(Item *p);

static __inline void vec_tidy(Vec *v)
{
    Item *b;
    { Item **pe = &v->end; *pe = fn_88186110(*pe, *pe, v->begin); }
    b = v->begin;
    if (b) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, b, v->alloc);
        else
            fn_885651F8(b);
    }
}

void fn_88721B58(Obj *o)
{
    vec_tidy(&o->vec);
}
