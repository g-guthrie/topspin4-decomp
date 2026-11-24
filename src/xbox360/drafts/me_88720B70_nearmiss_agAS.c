/* nearmiss: 3 off; C++ dtor form (vt store before global) fixes order but 10 off register numbering (target allocates li r11,0 first) */
/* agAS near-miss (3 off, plain /Oc): singleton-clearing dtor. The target emits lis(vt) before lis(global) and stores the vtable before the global clear; writing the clear first gets the order of the lis pair wrong, writing it second (or LTCG ctx=[]) is 8-10 off. Same family as agAQ 88888C80. */
typedef struct PtrVec { void **first; void **last; void *alloc; } PtrVec;
typedef struct Obj { void *vt; char p4[0x20]; PtrVec v; char p30[0x18]; void *owned; } Obj;
extern char lbl_880F23B8[], lbl_880F3388[];
extern void *lbl_88D45AB8;
extern void *lbl_88D45B38;
void ts4_destroy_owned_object(void *p);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void **p, void *a);
void fn_885651F8(void **p);
static __inline void ptrvec_free(PtrVec *v)
{
    void **b = v->first;
    if (b) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, b, v->alloc);
        else
            fn_885651F8(b);
    }
}
void fn_88720B70(Obj *o)
{
    lbl_88D45AB8 = 0;
    o->vt = lbl_880F23B8;
    ts4_destroy_owned_object(o->owned);
    o->vt = lbl_880F3388;
    ptrvec_free(&o->v);
}
