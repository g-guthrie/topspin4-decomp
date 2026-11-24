/* Q5 equivalent tier: thin forwarders whose exact frame or register shape could not be reproduced.
 * Behaviour checked with tools/fn_equiv.py (plain compile, no flags). */
typedef unsigned char u8;

/* 16-byte aligned float4 as the vector code reads it (lvx128). */
typedef struct Q5Vec4 { float v[4]; } Q5Vec4;
/* Two consecutive float4 rows (the callee reads +0x00 and +0x10 of each input). */
typedef struct Q5VecPair { Q5Vec4 row[2]; } Q5VecPair;

/* VMX box/segment test: three row pairs in, four float4 results out (the last two only on success);
 * returns a bool (its caller fn_88267F00 tests the low byte). */
extern u8 fn_886C8878(const Q5VecPair *a, const Q5VecPair *b, const Q5VecPair *c, Q5Vec4 *out0, Q5Vec4 *out1,
                      Q5Vec4 *out2, Q5Vec4 *out3);

/* Swing_DLL.xex 0x886C8C48: forward all seven arguments to fn_886C8878 and return its result.
 * The original keeps a 0xA0-byte frame around a non-tail call (open matching item since b90). */
/* byte-gap: 8 off; original keeps a 0xA0-byte frame around a non-tail call */
u8 ts4_vec_box_test_forward_886C8C48(const Q5VecPair *a, const Q5VecPair *b, const Q5VecPair *c, Q5Vec4 *out0,
                                     Q5Vec4 *out1, Q5Vec4 *out2, Q5Vec4 *out3)
{
    return fn_886C8878(a, b, c, out0, out1, out2, out3);
}

/* Object with vtable at +0, built by the constructor chain fn_887F4708 -> fn_887F4BA0. */
typedef struct Q5Obj887F4BA0 { const void *vtable; } Q5Obj887F4BA0;
extern const void *lbl_880E4528[];
/* Base constructor; like every constructor it returns its object pointer. */
extern Q5Obj887F4BA0 *fn_887F4BA0(Q5Obj887F4BA0 *self);

/* Swing_DLL.xex 0x887F4C18: derived constructor: run the base constructor, then install vtable lbl_880E4528.
 * The original stores through the base constructor's return value (which is `self`) but still saves self in
 * r31; no plain or LTCG source form reproduced that dead save. */
/* byte-gap: 12 off; keeps a dead save of self in r31 after the base ctor; no plain or LTCG source form reproduced it */
Q5Obj887F4BA0 *ts4_ctor_vtable_880E4528_887F4C18(Q5Obj887F4BA0 *self)
{
    Q5Obj887F4BA0 *obj = fn_887F4BA0(self);
    obj->vtable = lbl_880E4528;
    return obj;
}
