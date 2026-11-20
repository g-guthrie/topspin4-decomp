/* 0x8833D978: publishes t->cur to lbl_88B3302C, calls fn_883997E0 on the embedded object at +0x138 (null-checked), then calls vtable slot 10 (t, i, items[i].v) for each entry and returns the first nonzero result, else 0. */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); model 0x88343EB0. */
typedef struct Ent { int a, b; float v; char pad[0x24]; } Ent;
struct T;
typedef struct VT { void *s[10]; int (*apply)(struct T *t, int i, float v); } VT;
typedef struct T { VT *vt; char pad[0x14]; int cur; char pad2[0x88]; int count; Ent *items; char pad3[0x8c]; char sub[4]; } T;
extern int lbl_88B3302C;
void fn_883997E0(void *sub);
int ts4_apply_entries_sub_8833D978(T *t)
{
    int i;
    void *s;
    lbl_88B3302C = t->cur;
    s = t->sub;
    if (s)
        fn_883997E0(s);
    for (i = 0; i < t->count; i++) {
        int r = t->vt->apply(t, i, t->items[i].v);
        if (r)
            return r;
    }
    return 0;
}
