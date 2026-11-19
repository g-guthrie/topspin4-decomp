/* 0x883E67E0: when the object at +0x10 has a key (slot 9), finds its entry in the lbl_88CAC9A8 table (slot 5, then slot 3); 0x21 if missing */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); first reference copies the 64-bit value at t+0x18 into the entry, claims an empty owner, and bumps the count; pair of 0x883E68B0. */
typedef unsigned __int64 Pos;
typedef struct E { char pad[0x10]; Pos pos; int count; void *owner; } E;
typedef struct X X;
typedef struct XVt { void *s[3]; E *(*find)(X *x, void *key); } XVt;
struct X { XVt *vt; };
typedef struct M M;
typedef struct MVt { void *s[5]; X *(*table)(M *m); } MVt;
struct M { MVt *vt; };
typedef struct O O;
typedef struct OVt { void *s[9]; void *(*key)(O *o); } OVt;
struct O { OVt *vt; };
extern M *lbl_88CAC9A8;
typedef struct T { char pad[0x10]; O *opt; int f14; Pos pos; } T;
int ts4_acquire_key_ref_883E67E0(T *t)
{
    if (t->opt && t->opt->vt->key(t->opt)) {
        X *x = lbl_88CAC9A8->vt->table(lbl_88CAC9A8);
        E *e = x->vt->find(x, t->opt->vt->key(t->opt));
        if (!e)
            return 0x21;
        if (e->count == 0)
            e->pos = t->pos;
        if (!e->owner)
            e->owner = t;
        e->count++;
    }
    return 0;
}
