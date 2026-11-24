/* nearmiss: 6 off (LTCG /Oc, context src/xbox360/fk2_004.c + pp1_pool_primer.c, --include ts4_if_call_seq_fn_88883CD0_8860D250).
 * Scheduling only: target issues `mr r31,r3` before `lis r9`, `li r7,1` after the w4 store and the heap stw +0xc after
 * the cmplwi. Global read sweep over all 8 statement positions (best: after the vt store, this file); perm_auto run.
 * Blocker: likely a C++ ctor with base/member initialisers (vtable lbl_880F7EE4 not yet named as a class vtable). */
typedef unsigned int u32;
typedef unsigned char u8;
extern char lbl_880F7EE4[];
extern void *lbl_88D45B38;
extern void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
typedef struct HeapUser {
    const void *vt;
    u32 w4;
    u8 active;
    u8 pad9[3];
    void *heap;
    u32 w10;
    u32 w14;
    u32 w18;
} HeapUser;
HeapUser *ts4_heap_user_ctor_88617D88(HeapUser *self)
{
    void *g;
    self->w4 = 0;
    self->vt = lbl_880F7EE4;
    g = lbl_88D45B38;
    self->heap = 0;
    self->w10 = 0;
    self->w14 = 0;
    self->w18 = 0;
    self->active = 1;
    if (g)
        self->heap = ts4_if_call_seq_fn_88883CD0_8860D250(g);
    return self;
}
