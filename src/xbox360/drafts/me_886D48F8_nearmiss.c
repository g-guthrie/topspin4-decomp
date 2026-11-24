/* nearmiss: 4 off; real C++ ctor forms worse: init-list + Sub member ctor 11 off (vt store after li r30), loop 18 off, assignment body worse */
/* agP 2026-11-19: now 4 off (both routes). Pointer-local vtbl/n18/n1c/slots stores, early sub pointer, result local: 4-9, no gain. */
/* agentA2 (arg-setup pass, 2026-11-18): n10 zero stored through a block-local pointer `{ ts4_u32 *p = &self->n10; *p = 0; }` -> 9 to 4 off (plain and LTCG). Residue: `addi r3,r3,0x30` before the n10 store and `mr r3,r31` before the 0x150 store. Named sub/return locals, restrict, other block-pointer stores: no gain. */
/* NEAR MISS fn_886D48F8: 9 off (store scheduling around the vtable store), LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886D48F8: constructor: install the vtable, clear the counters, set the invalid id 0xFFFFF,
   construct the embedded sub-object at +0x30, and clear the six trailing slots. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern char lbl_880F3794[];
void fn_886D0F78(void *sub);
struct Ts4CtObj {
    void *vtbl; ts4_u8 pad_04[0xC]; ts4_u32 n10; ts4_u32 id; ts4_u32 n18; ts4_u32 n1c; ts4_u32 n20;
    ts4_u8 pad_24[0xC]; ts4_u8 sub[0x120]; ts4_u32 slots[6];
};

struct Ts4CtObj *ts4_ctor_886D48F8(struct Ts4CtObj *self)
{
    self->vtbl = lbl_880F3794;
    { ts4_u32 *p = &self->n10; *p = 0; }
    self->n18 = 0;
    self->id = 0xFFFFF;
    self->n20 = 0;
    fn_886D0F78(self->sub);
    self->n1c = 0;
    self->slots[0] = 0;
    self->slots[1] = 0;
    self->slots[2] = 0;
    self->slots[3] = 0;
    self->slots[4] = 0;
    self->slots[5] = 0;
    return self;
}
