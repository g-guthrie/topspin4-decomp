/* 0x88439050: converts ax and ay with slot 4 of the converters cx and cy and forwards (self, b - 0xC, x, y) to fn_88438FC0; sibling 0x884A5EB8 forwards to fn_884A5A40. */
/* Near miss (agAF, /Oc): 3 off at +0x50, the target sets r3 before r5 and r4 for the final call. An inline base cast, void return and int/char arithmetic all keep r5, r4, r3; the b - 0xC is probably a C++ base-class cast. */
typedef struct Conv Conv;
typedef struct ConvVt { void *f[4]; void *(*get)(Conv *c, void *arg); } ConvVt;
struct Conv { ConvVt *vt; };
typedef struct Base Base;
typedef struct Iface Iface;
extern int fn_88438FC0(void *self, Base *b, void *x, void *y);
int fn_88439050(void *self, Iface *b, int u5, int u6, int u7, Conv *cx, Conv *cy, void *ax, void *ay)
{
    void *x = cx->vt->get(cx, ax);
    void *y = cy->vt->get(cy, ay);
    return fn_88438FC0(self, (Base *)((char *)b - 0xc), x, y);
}
