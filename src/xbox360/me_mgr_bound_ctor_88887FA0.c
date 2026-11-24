/* 0x88887FA0: constructor: base constructor fn_8861B128, then the intermediate class (vtable lbl_880F84F0,
 * clears byte +0x24), copies the global manager's +0x2A4 value into +0x224, and installs the final vtable
 * lbl_880DF2C8. Returns the object. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4Object { void *vtable; } Ts4Object;
extern void fn_8861B128(Ts4Object *o);
extern char lbl_880F84F0, lbl_880DF2C8;
typedef struct Ts4Mgr2A4 { char p[0x2a4]; u32 value; } Ts4Mgr2A4;
extern Ts4Mgr2A4 *lbl_88D45B1C;
typedef struct Ts4MgrBound { Ts4Object base; char p[0x20]; u8 f24; char q[0x224 - 0x25]; u32 value; } Ts4MgrBound;
Ts4MgrBound *ts4_mgr_bound_ctor_88887FA0(Ts4MgrBound *o)
{
    fn_8861B128(&o->base);
    o->base.vtable = &lbl_880F84F0;
    o->f24 = 0;
    o->value = lbl_88D45B1C->value;
    o->base.vtable = &lbl_880DF2C8;
    return o;
}
