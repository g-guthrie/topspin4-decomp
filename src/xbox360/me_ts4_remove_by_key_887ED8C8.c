
typedef unsigned int u32;
typedef struct Item { u32 pad; u32 key; } Item;
typedef struct Vec { Item **begin, **end; } Vec;
typedef struct O { u32 pad[19]; Vec v; } O;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
extern void fn_887ED280(O *o, Item *it);
static __inline void erase_at(Vec *v, Item **p, Item **n)
{
    if (n != v->end) fn_88562DC0(p, n, (char *)v->end - (char *)n);
    v->end--;
}
void fn_887ED8C8(O *o, u32 key)
{
    Item **p = o->v.begin, **n;
    if (p != o->v.end) {
        n = p + 1;
        do {
            if ((*p)->key == key) { fn_887ED280(o, *p); erase_at(&o->v, p, n); }
            else { n++; p++; }
        } while (p != o->v.end);
    }
}
