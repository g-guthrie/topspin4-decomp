typedef unsigned int u32;
#ifdef _MSC_VER
#define W7B_FI static __forceinline
#else
#define W7B_FI static inline
#endif
struct W7bRel { int rel; u32 count; };
struct W7bEnt { unsigned char pad[0xc]; u32 key; int v10; unsigned char pad2[0x28 - 0x14]; };
struct W7bGrp { unsigned char pad[0x14]; struct W7bRel h; };
struct W7bP34 { unsigned char pad[0xc]; struct W7bGrp *p0c; };
struct W7bT { unsigned char pad[0x14c]; int *arr; int pad2; int count; };
struct W7bP28 { unsigned char pad[0x10]; struct W7bT *p10; unsigned char pad2[0x560 - 0x14]; int d560; };
struct W7bO { unsigned char pad[0x28]; struct W7bP28 *p28; unsigned char pad2[0x34 - 0x2c]; struct W7bP34 *p34; };
W7B_FI struct W7bEnt *w7b_begin(struct W7bRel *r)
{
    struct W7bEnt *x = 0;
    if (r->rel != -1) x = (struct W7bEnt *)((char *)r + r->rel);
    return x;
}
W7B_FI struct W7bEnt *w7b_end(struct W7bRel *r)
{
    struct W7bEnt *x = 0;
    if (r->rel != -1) x = (struct W7bEnt *)((char *)r + (r->rel + r->count * 0x28));
    return x;
}
/* Swing_DLL.xex 0x886CDA68: look up a slot id (0x959A9407) in a 0x28-stride table and test a flag word */
int ts4_check_slot_886CDA68(struct W7bO *o, int idx)
{
    int result = 0;
    if (idx >= 0) {
        struct W7bGrp *g = o->p34->p0c;
        struct W7bRel *h = &g->h;
        struct W7bP28 *p28 = o->p28;
        struct W7bRel *sub;
        struct W7bEnt *e, *end;
        int found = -1;
        int d;
        sub = (struct W7bRel *)((char *)h + (p28->d560 * 0x1c + h->rel));
        e = w7b_begin(sub);
        end = w7b_end(sub);
        for (; e != end; e++) {
            if (e->key == 0x959A9407) { found = e->v10; break; }
        }
        d = idx - found;
        if (d >= 0) {
            struct W7bT *t = p28->p10;
            if (d < t->count) result = t->arr[d] <= 0;
            else result = 1;
        } else result = 1;
    }
    return result;
}
