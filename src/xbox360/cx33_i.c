/* CX33: add-unique to the key vector at +0x14 (Swing_DLL.xex 0x889121C0). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct I5Key { u32 w0; int w4; u32 w8; u32 wc; } I5Key;
typedef struct I5Vec { I5Key **first; I5Key **last; I5Key **cap; } I5Vec;
typedef struct I5Hub { u8 pad[0x14]; I5Vec v; } I5Hub;
extern void fn_88174A38(I5Vec *v, I5Key **pos, I5Key **val);
int ts4_hub_add_unique_889121C0(I5Hub *h, I5Key *k)
{
    I5Vec *v = &h->v;
    I5Key **end = h->v.last;
    I5Key **p;
    for (p = v->first; p != end; p++) {
        I5Key *e = *p;
        if (k->w8 == e->w8 && k->wc == e->wc && k->w4 == e->w4)
            return 0;
    }
    if (v->last != v->cap) {
        if (v->last)
            *v->last = k;
        v->last++;
    } else {
        fn_88174A38(v, v->last, &k);
    }
    return 1;
}
