/*
 * SC2 (LTCG route): a store to a global whose address is never taken does not
 * alias any pointer access under LTCG, so it is scheduled freely around loads
 * through `self` (see docs/agents/near-misses/SC2.md).
 */

typedef unsigned int Sc2LU32;

/* Swing_DLL.xex 0x88690AA0: ts4_destruct_object_88690AA0
 * Destructor. The +0xa8 owned pointer is freed through `own_free(&self->pa8)`
 * (its load stays behind the vtable store, SC1 A3); under LTCG the store
 * `lbl_88D45B00 = 0` is free to sink below that load, as in the target. */
extern const char lbl_880F4318[];
extern const char lbl_880D75FC[];
extern void *lbl_88D45B00;
extern void ts4_destroy_owned_object(void *p);
extern void ts4_loop_get_u32_off0_8826DF58(void *a, Sc2LU32 b);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
typedef struct Sc2Own88690AA0 { void *p; } Sc2Own88690AA0;
typedef struct Sc2Sub88690AA0 { const char *vtbl; Sc2Own88690AA0 own; } Sc2Sub88690AA0;
typedef struct Sc2Obj88690AA0 {
    const char *vtbl;
    unsigned char pad04[0x74];
    void *p78;
    unsigned char pad7c[0x10];
    Sc2Sub88690AA0 sub8c;
    unsigned char pad94[8];
    void *p9c;
    Sc2LU32 pa0;
    unsigned char pada4[4];
    Sc2Own88690AA0 pa8;
} Sc2Obj88690AA0;
static __inline void sc2_own_free_88690AA0(Sc2Own88690AA0 *o)
{
    if (o->p != 0)
        ts4_destroy_owned_object(o->p);
}
static __inline void sc2_sub_dtor_88690AA0(Sc2Sub88690AA0 *s)
{
    s->vtbl = lbl_880D75FC;
    sc2_own_free_88690AA0(&s->own);
}
void ts4_destruct_object_88690AA0(Sc2Obj88690AA0 *self)
{
    self->vtbl = lbl_880F4318;
    lbl_88D45B00 = 0;
    sc2_own_free_88690AA0(&self->pa8);
    ts4_loop_get_u32_off0_8826DF58(self->p9c, self->pa0);
    if (self->p9c != 0)
        ts4_destroy_owned_object(self->p9c);
    sc2_sub_dtor_88690AA0(&self->sub8c);
    if (self->p78 != 0)
        ts4_destroy_owned_object(self->p78);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
