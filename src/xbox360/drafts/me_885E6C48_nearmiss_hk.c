/* NEAR MISS (round 2): near-miss, 16 off: the handle store order matches (0x14, 0x10, vtable, 0x14, 0x10, +0x80 global) but the target keeps the object in r3 after the base call (it reads the base ctor return) and saves r31; ours uses r31 and the extra lis is scheduled differently. Size 0x54 vs 0x58. Draft, not matched.
 */
typedef unsigned int u32;
typedef struct Ts4Object { void *vtable; } Ts4Object;
extern void fn_885E5BC8(Ts4Object *object);
extern char lbl_880BDBC0[], lbl_880BD0CC[];
typedef struct Ts4Handle8 { u32 a, b; } Ts4Handle8;
typedef struct Ts4HolderA { Ts4Object base; char p[0xc]; Ts4Handle8 handle; char q[0x68]; u32 f80; } Ts4HolderA;
static __inline void ts4_handle8_null(Ts4Handle8 *h) { h->b = 0; h->a = 0; }
Ts4HolderA *ts4_holder_a_ctor_885E6C48(Ts4HolderA *o)
{
    Ts4Handle8 *h;
    fn_885E5BC8(&o->base);
    h = &o->handle;
    ts4_handle8_null(h);
    o->base.vtable = lbl_880BDBC0;
    ts4_handle8_null(h);
    o->f80 = *(u32 *)lbl_880BD0CC;
    return o;
}
