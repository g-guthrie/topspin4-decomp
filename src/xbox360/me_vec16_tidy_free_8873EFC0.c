typedef unsigned int u32;
typedef struct Rest12 { u32 b, c, d; } Rest12;
typedef struct Item16 { u32 a; Rest12 r; } Item16;
typedef struct Vec16 { Item16 *begin; Item16 *end; void *alloc; } Vec16;
extern void *lbl_88D45B38;
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, Item16 *p, void *a);
void fn_885651F8(Item16 *p);

static __inline Item16 *copy16(Item16 *first, Item16 *last, Item16 *dest)
{
    int n;
    for (n = last - first; n > 0; n--) {
        dest->a = first->a;
        dest->r = first->r;
        dest++; first++;
    }
    return dest;
}

void fn_8873EFC0(Vec16 *v)
{
    Item16 *b;
    {
        Item16 *e = copy16(v->end, v->end, v->begin);
        b = v->begin;
        v->end = e;
    }
    if (b) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, b, v->alloc);
        else
            fn_885651F8(b);
    }
}
