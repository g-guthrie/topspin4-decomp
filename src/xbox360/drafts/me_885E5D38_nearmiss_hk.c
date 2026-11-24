/* NEAR MISS (round 2): near-miss, 19 off: the field stores match in order (+0xac, +0x14=1, vtable, +0xb0, +0xb4, +0x10=1) but the target keeps r31 saved and stores through r3 after the base call; the void-base form does not reproduce that. Size 0x48 vs 0x54. Draft, not matched.
 */
typedef unsigned int u32;
typedef struct Ts4Object { void *vtable; } Ts4Object;
extern Ts4Object *fn_885E5BC8(Ts4Object *object);
extern char lbl_880BD320[];
typedef struct Ts4HolderB { Ts4Object base; u32 f04; u32 f08; u32 f0c; u32 f10; u32 f14; char q[0x98]; u32 fac; u32 fb0; u32 fb4; } Ts4HolderB;
Ts4HolderB *ts4_holder_b_ctor_885E5D38(Ts4HolderB *o)
{
    Ts4HolderB *r = (Ts4HolderB *)fn_885E5BC8(&o->base);
    r->fac = 0;
    r->f14 = 1;
    r->base.vtable = lbl_880BD320;
    r->fb0 = 0;
    r->fb4 = 0;
    r->f10 = 1;
    return r;
}
