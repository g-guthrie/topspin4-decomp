/* 0x88347650: publishes t->cur to lbl_88B3302C, resets the slot (+0x180 = -1) and selection (+0x178 = 0), then calls vtable slot 10 (t, i, items[i].v) for each entry and returns the first nonzero result, else 0. */
/* Matched on /Oc plain only (work/army/ME/v.py chk); model 0x88343EB0. */
typedef struct Ent { int a, b; float v; char pad[0x24]; } Ent;
struct T;
typedef struct VT { void *s[10]; int (*apply)(struct T *t, int i, float v); } VT;
typedef struct T { VT *vt; char pad[0x14]; int cur; char pad2[0x88]; int count; Ent *items; char pad3[0xcc]; int sel; int pad4; short slot; } T;
extern int lbl_88B3302C;
int ts4_apply_entries_reset_88347650(T *t)
{
    int i;
    lbl_88B3302C = t->cur;
    t->slot = -1;
    t->sel = 0;
    for (i = 0; i < t->count; i++) {
        int r = t->vt->apply(t, i, t->items[i].v);
        if (r)
            return r;
    }
    return 0;
}
