/* 0x88343EB0: publishes t->cur (+0x18) to lbl_88B3302C, then calls vtable slot 10 (t, i, items[i].v) for each 0x30-byte entry and returns the first nonzero result, else 0. */
/* Matched on /Oc plain only; LTCG is 5 off (work/army/ME/v.py chk); the 883FB5A0 loop shape with a virtual call. */
typedef struct Ent { int a, b; float v; char pad[0x24]; } Ent;
struct T;
typedef struct VT { void *s[10]; int (*apply)(struct T *t, int i, float v); } VT;
typedef struct T { VT *vt; char pad[0x14]; int cur; char pad2[0x88]; int count; Ent *items; } T;
extern int lbl_88B3302C;
int ts4_apply_entries_88343EB0(T *t)
{
    int i;
    lbl_88B3302C = t->cur;
    for (i = 0; i < t->count; i++) {
        int r = t->vt->apply(t, i, t->items[i].v);
        if (r)
            return r;
    }
    return 0;
}
