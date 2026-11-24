/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888CA910: destructor body: install vtable lbl_880DB200, clear lbl_88D45948, empty the vector at +0x2c,
 * finalize and free the owned buffer at +0x54, free the vector buffer, then run the base destructor 0x88617D28.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_888CA910.json for route and flags. */
/* from eq_q5_gameplay_small_h.c */
typedef unsigned int u32;
typedef struct Dc44 Dc44; /* 0x44-byte element */
typedef struct Q5Vec { Dc44 *first; Dc44 *last; Dc44 *cap; } Q5Vec;
typedef struct Q5Own { void *first; } Q5Own;
typedef struct Q5Svc { void *vtbl; char pad04[0x28]; Q5Vec items; char pad38[0x1c]; Q5Own owned; } Q5Svc;
extern char lbl_880DB200[];
extern u32 lbl_88D45948;
extern Dc44 *ts4_dc44_copy_881817A0(Dc44 *first, Dc44 *last, Dc44 *dst);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern void ts4_object_finalize(void *p);
extern void ts4_destroy_owned_object(void *p);

void ts4_svc_dtor_888CA910(Q5Svc *self)
{
    Q5Vec *v = &self->items;
    self->vtbl = lbl_880DB200;
    lbl_88D45948 = 0;
    v->last = ts4_dc44_copy_881817A0(v->last, v->last, v->first);
    ts4_object_finalize(&self->owned);
    if (self->owned.first)
        ts4_destroy_owned_object(self->owned.first);
    if (v->first)
        ts4_destroy_owned_object(v->first);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}
