/* 0x88879C48 near miss (agBF, 1 missing instruction): releases the owned object at +0x10: fetches its record
 * (ts4_call_seq_u32_lbl_88CACF08_8846BE08), detaches it (fn_88472130), releases each counted ref in the record's
 * array at +8, drops the record's refcount (+6, gated by +4) and deletes it at zero, then deletes the object and
 * clears +0x10/+0x34. Plain /Oc and LTCG ctx=[] give the same: the target reloads o->p10 into r11 *before*
 * `mr r28,r3` and then copies it to r3 (`lwz r11; mr r28,r3; mr r3,r11`); ours loads straight into r3. */

typedef unsigned int u32; typedef unsigned short u16;
typedef struct Obj Obj;
typedef struct { void (*dtor)(Obj *o, int f); } Vt;
struct Obj { Vt *vt; };
typedef struct { void **items; int n; } Arr;
typedef struct R { Vt *vt; u16 h4; short h6; Arr arr; } R;
typedef struct { char pad[0x10]; Obj *p10; char p14[0x34-0x14]; u32 f34; } O;
extern R *ts4_call_seq_u32_lbl_88CACF08_8846BE08(Obj *o);
extern void fn_88472130(Obj *o, R *r);
extern void ts4_counted_ref_release_88475B08(void *it);
void ts4_owner_release_88879C48(O *o) {
    if (o->p10) {
        R *r = ts4_call_seq_u32_lbl_88CACF08_8846BE08(o->p10);
        int i;
        fn_88472130(o->p10, r);
        { Arr *a = &r->arr; for (i = 0; i < a->n; i++) ts4_counted_ref_release_88475B08(a->items[i]); }
        if (r->h4) {
            if (--r->h6 == 0) r->vt->dtor((Obj *)r, 1);
        }
    }
    if ((int)o->p10 != 0) { o->p10->vt->dtor(o->p10, 1); o->p10 = 0; }
    o->f34 = 0;
}
