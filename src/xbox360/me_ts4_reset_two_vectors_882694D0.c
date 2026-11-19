/* Swing_DLL.xex 0x882694D0: Stores the argument at +0xBC, then clears a vector of 28-byte and one of 20-byte PODs (erase(begin,end) as copy(last,last,first)).
 * Leaf; the counted word-copy loops stay in even though the count is always 0. */
typedef struct Item28 { unsigned int w[7]; } Item28;
typedef struct Item20 { unsigned int w[5]; } Item20;
typedef struct Vec28 { Item28 *first; Item28 *last; Item28 *end; } Vec28;
typedef struct Vec20 { Item20 *first; Item20 *last; Item20 *end; } Vec20;
typedef struct Owner {
    Vec28 a;
    Vec20 b;
    unsigned char pad[0xbc - 0x18];
    int state;
} Owner;

static __inline Item28 *copy28(Item28 *f, Item28 *l, Item28 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}
static __inline Item20 *copy20(Item20 *f, Item20 *l, Item20 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}
static __inline void clear28(Vec28 *v) { v->last = copy28(v->last, v->last, v->first); }
static __inline void clear20(Vec20 *v) { v->last = copy20(v->last, v->last, v->first); }

void fn_882694D0(Owner *o, int state)
{
    o->state = state;
    clear28(&o->a);
    clear20(&o->b);
}
