
typedef unsigned int u32;
typedef struct Vec { u32 *begin, *end; } Vec;
typedef struct O { u32 pad[10]; Vec v; } O;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
static __inline void erase_at(Vec *v, u32 *p, u32 *n)
{
    if (n != v->end) fn_88562DC0(p, n, (char *)v->end - (char *)n);
    v->end--;
}
void fn_88879AA8(O *o, u32 x)
{
    u32 *p = o->v.begin, *n;
    if (p != o->v.end) {
        n = p + 1;
        do {
            if (x == *p) erase_at(&o->v, p, n);
            else { n++; p++; }
        } while (p != o->v.end);
    }
}
