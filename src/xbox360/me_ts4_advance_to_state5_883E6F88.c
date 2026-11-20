/* 0x883E6F88: in state 3 starts the object at +8 (slot 1) with +0x10->+4, then sets state (+0x30) to 5 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); runs ts4_release_key_ref_883E68B0(t) and ts4_chk_883E5798 on the optional child at +0xC; returns the first error. */
typedef struct S S;
typedef struct SVt { void *s0; int (*start)(S *s, void *arg); } SVt;
struct S { SVt *vt; };
typedef struct P { int f0; void *arg; } P;
typedef struct T { int f0, f4; S *s; void *child; P *p; char pad[0x30 - 0x14]; int state; } T;
int ts4_release_key_ref_883E68B0(T *t);
int ts4_chk_883E5798(void *child);
int ts4_advance_to_state5_883E6F88(T *t)
{
    int r;
    if (t->state == 3) {
        r = t->s->vt->start(t->s, t->p ? t->p->arg : 0);
        if (r)
            return r;
    }
    t->state = 5;
    r = ts4_release_key_ref_883E68B0(t);
    if (r)
        return r;
    if (t->child) {
        r = ts4_chk_883E5798(t->child);
        if (r)
            return r;
    }
    return 0;
}
