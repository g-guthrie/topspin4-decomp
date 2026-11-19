
typedef unsigned int u32;
typedef struct Item { char pad[0xc]; u32 live; } Item;
typedef struct Vec { Item **begin, **end; } Vec;
typedef struct O { u32 pad[22]; Vec v; } O;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
extern void fn_887EC7A0(O *o, Item *it);
static __inline void vec_erase(Vec *v, Item **p)
{
    Item **n = p + 1;
    if (n != v->end) fn_88562DC0(p, n, (char *)v->end - (char *)n);
    v->end--;
}
static __inline void erase_at(Vec *v, Item **p, Item **n)
{
    if (n != v->end) fn_88562DC0(p, n, (char *)v->end - (char *)n);
    v->end--;
}
void fn_887ECA58(O *o)
{
    Item **p = o->v.begin, **n;
    if (p != o->v.end) {
        n = p + 1;
        do {
            if ((*p)->live == 0) {
                fn_887EC7A0(o, *p);
                erase_at(&o->v, p, n);
            } else { n++; p++; }
        } while (p != o->v.end);
    }
}
