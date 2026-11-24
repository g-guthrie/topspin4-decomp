/* NEAR MISS (round 2): near-miss, 9 off: two vtables at +0 and +0x10, zeros at +0x60/+0x64 and 0x80000000 at +0x68. The target hoists both vtable address pairs before the stores; the locals form did not change that. Draft, not matched.
 */
typedef unsigned int u32;
typedef struct Ts4Object { void *vtable; } Ts4Object;
extern void fn_88443038(Ts4Object *object);
extern char lbl_88081EA8[], lbl_88081E84[];
typedef struct Ts4Holder3 { Ts4Object base; char p[0xc]; void *vt2; char q[0x48]; u32 f60; u32 f64; u32 f68; } Ts4Holder3;
Ts4Holder3 *ts4_holder_c_ctor_884482C0(Ts4Holder3 *o)
{
    fn_88443038(&o->base);
    o->vt2 = lbl_88081E84;
    o->base.vtable = lbl_88081EA8;
    o->f60 = 0;
    o->f64 = 0;
    o->f68 = 0x80000000u;
    return o;
}
