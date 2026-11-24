/* UPDATE (agentB, 2026-11-18): C++ rewrite, 48 off (was 50 in C). The registry remove is a real virtual (slot 12).
 * The +0x270 holder modelled as `struct Ts4StateHolder : Ts4HolderHead(0x30), Ts4State2` and reset through a base
 * reference reproduces the game's `addi r11,r31,0x270; addi r3,r11,0x30`, but MSVC adds a null test (addic./bne/mr)
 * the target does not have (+8 bytes). Reference conversion, static_cast<&>, C cast, inline by-ref helper, base
 * member call: all same or worse. Needs `char p3c0[0x10]` before f3d0 in C++ to keep the C offsets. */
/* 0x886E0D08 near miss (50 off, /Oc plain; everything after +0x8C is shifted by one instruction). Manager shutdown:
 * frees the owned pair object, resets sub-objects, finalizes three inner objects, resets three 0x120-byte states
 * (+0x30, +0x150, +0x270), clears the vector16 and pointer lists, drops the resource and unregisters it.
 * Residue: the game forms `addi r11,r31,0x270` and then `addi r3,r11,0x30` for the third reset (dead sub-object
 * addi); a one- or two-level inline helper and a typed member did not reproduce it. Inner/vec/list helpers did. */
#include "../vx1_vector.h"
extern "C" void ts4_reset_state_886D0E20(void *p);
typedef struct Ts4Owned2 { void *a; char p[8]; void *b; } Ts4Owned2;
typedef struct Ts4VecV { __vector4 *begin, *end; } Ts4VecV;
typedef struct Ts4VecP { void **begin, **end; } Ts4VecP;
typedef struct Ts4Res { char p[0xb8]; void *tsu; } Ts4Res;
struct Ts4Reg {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void remove(Ts4Res *res);   /* slot 12 */
};
typedef struct Ts4World { char p[0x148]; Ts4Reg *reg; } Ts4World;
typedef struct Ts4Inner { char p[0x48]; char o48[0xc]; char o54[0xc]; char o60[0xc]; } Ts4Inner;
typedef struct Ts4State2 { char d[0x120]; } Ts4State2;
struct Ts4HolderHead { char p[0x30]; };
struct Ts4StateHolder : Ts4HolderHead, Ts4State2 { void reset() { Ts4State2 &st = *this; ts4_reset_state_886D0E20(&st); } };
typedef struct Ts4VecHolder { int f0; int f4; int f8; Ts4VecV vecs; } Ts4VecHolder;
typedef struct Ts4Mgr {
    char p0[0x10]; Ts4World *world; char p14[8]; void *f1c; Ts4Res *res; char p24[0x30 - 0x24];
    char s30[0x150 - 0x30]; char s150[0x270 - 0x150]; Ts4StateHolder s270; char p3c0[0x10];
    int f3d0; char p3d4[0x3f0 - 0x3d4]; char s3f0[0x430 - 0x3f0];
    Ts4VecHolder s430; char p444[0x460 - 0x444];
    char s460[0x4d0 - 0x460]; Ts4Inner inner; char p53c[0x564 - 0x53c]; int f564, f568; char p56c[0x5ac - 0x56c];
    char s5ac[0x5e4 - 0x5ac]; Ts4Owned2 *owned; Ts4VecP list;
} Ts4Mgr;
extern "C" void ts4_finalize_and_clear_886C3748(Ts4Owned2 *o);
extern "C" void ts4_destroy_owned_object(void *p);
extern "C" void ts4_tsu_cleanup_end(void *p);
extern "C" void fn_886DC400(void *p);
extern "C" void ts4_pair_list_reset_886C5DB0(void *p);
extern "C" void ts4_object_finalize(void *p);
extern "C" void ts4_release_owned_object_886CA428(void *p);
extern "C" void **fn_882683B8(void **first, void **last, void **dst);
extern "C" void fn_8864A5E8(Ts4Res *r);
static __inline void inner_finalize(Ts4Inner *in) { ts4_object_finalize(in->o48); ts4_object_finalize(in->o54); ts4_object_finalize(in->o60); }
static __inline void vecv_clear(Ts4VecV *v)
{
    __vector4 *d = v->begin, *s = v->end;
    int n;
    for (n = (int)(v->end - s); n > 0; n--) *d++ = *s++;
    v->end = d;
}
static __inline void vec_holder_clear(Ts4VecHolder *h) { vecv_clear(&h->vecs); h->f8 = 0; h->f4 = 0; }
static __inline void list_clear(Ts4VecP *l) { l->end = fn_882683B8(l->end, l->end, l->begin); }
extern "C" void ts4_mgr_shutdown(Ts4Mgr *self)
{
    Ts4Owned2 *o;
    ts4_finalize_and_clear_886C3748(self->owned);
    o = self->owned;
    if (o) {
        if (o->b) ts4_destroy_owned_object(o->b);
        if (o->a) ts4_destroy_owned_object(o->a);
        ts4_tsu_cleanup_end(o);
    }
    self->owned = 0;
    fn_886DC400(self->s3f0);
    ts4_pair_list_reset_886C5DB0(self->s5ac);
    inner_finalize(&self->inner);
    ts4_release_owned_object_886CA428(self->s460);
    self->f3d0 = 0;
    self->s270.reset();
    ts4_reset_state_886D0E20(self->s150);
    ts4_reset_state_886D0E20(self->s30);
    vec_holder_clear(&self->s430);
    list_clear(&self->list);
    self->f564 = 0;
    self->f568 = 0;
    {
        Ts4Res *r = self->res;
        if (r->tsu) ts4_tsu_cleanup_end(r->tsu);
        r->tsu = 0;
    }
    fn_8864A5E8(self->res);
    self->world->reg->remove(self->res);
    self->f1c = 0;
    self->world = 0;
}
