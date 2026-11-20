/* 0x8873DF48: dtor body: vector<0x30-byte elem> at +0x1C cleared via inline erase(first,last), owned objects at +0x50/+0x44 destroyed, vector tidied, base vt 0x880F33E0 and base dtor. */
typedef struct { char b[0x30]; } Elem;
typedef struct { Elem *first; Elem *last; Elem *cap; } ElemVec;
typedef struct { void *vt; char p4[0x18]; ElemVec v; char p28[0x1c]; void *a44; char p48[8]; void *a50; } Obj;
extern char lbl_880F28C0[], lbl_880F33E0[];
void ts4_call_seq_u32_off0_8821B688(Elem *dst, Elem *src); /* element assign */
void ts4_loop_call_seq_u32_offc_88233530(Elem *first, Elem *last); /* range destroy */
void ts4_destroy_owned_object(void *obj);
void ts4_if_call_seq_u32_off0_88224070(ElemVec *v);
void ts4_if_call_seq_lbl_880F7EE4_88617D28(Obj *o);
static __inline Elem *elem_move(Elem *s, Elem *e, Elem *d)
{
    int n;
    for (n = e - s; n > 0; n--, s++, d++) ts4_call_seq_u32_off0_8821B688(d, s);
    return d;
}
static __inline void elemvec_clear(ElemVec *v);
static __inline void elemvec_erase(ElemVec *v, Elem *f, Elem *l)
{
    Elem *p = elem_move(l, v->last, f);
    ts4_loop_call_seq_u32_offc_88233530(p, v->last);
    v->last = p;
}
static __inline void elemvec_clear(ElemVec *v) { elemvec_erase(v, v->first, v->last); }
void fn_8873DF48(Obj *o)
{
    ElemVec *v;
    o->vt = lbl_880F28C0;
    v = &o->v;
    elemvec_clear(v);
    ts4_destroy_owned_object(o->a50);
    ts4_destroy_owned_object(o->a44);
    ts4_if_call_seq_u32_off0_88224070(&o->v);
    o->vt = lbl_880F33E0;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}
