/* nearmiss (q5s 2026-11-24): 2 off; lwz 0x18(r31) vs lwz 0x50(r1) order; reversed compare a!=o->a gives 3 */
/* agAU near-miss, plain /Oc, 2 off: target loads o->a (0x18) before the stack local a; every decl/ptr/cur/.cpp variant keeps the stack load first. */

typedef unsigned int u32;
typedef struct { char p0[0x20]; void *src; } Def;
typedef struct Obj Obj;
struct Obj { Def *def; char p4[0x14]; u32 a; u32 b; };
void fn_8876DCB8(Obj *o, void *src, u32 *a, u32 *b);
void fn_8876D560(Obj *o);
void fn_8876E0B0(Obj *o, Def *d)
{
    o->def = d;
    if (d) {
        u32 a = 0, b = 0;
        unsigned char changed;
        fn_8876DCB8(o, d->src, &a, &b);
        changed = 0;
        if (o->a != a) { o->a = a; changed = 1; }
        if (o->b != b) { o->b = b; changed = 1; }
        if (changed) fn_8876D560(o);
    }
}
