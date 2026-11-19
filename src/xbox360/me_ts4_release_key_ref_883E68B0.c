/* 0x883E68B0: when the object at +0x10 has a key (slot 9), finds its entry in the lbl_88CAC9A8 table (slot 5, then slot 3); 0x21 if missing */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); drops the entry count (+0x18) and clears the owner (+0x1C) when it is t or the count reaches 0. */
typedef struct E { char pad[0x18]; int count; void *owner; } E;
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
typedef struct T { char pad[0x10]; O *opt; } T;
int ts4_release_key_ref_883E68B0(T *t)
{
    if (t->opt && t->opt->vt->key(t->opt)) {
        X *x = lbl_88CAC9A8->vt->table(lbl_88CAC9A8);
        E *e = x->vt->find(x, t->opt->vt->key(t->opt));
        if (!e)
            return 0x21;
        e->count--;
        if (e->owner == t || e->count == 0)
            e->owner = 0;
    }
    return 0;
}
