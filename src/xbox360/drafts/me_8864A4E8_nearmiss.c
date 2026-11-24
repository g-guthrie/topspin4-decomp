/* near-miss: 49 off, size 0xf4 vs 0xfc (target keeps the record in r10 with an mr copy and a separate li 0 null path) */
/* 0x8864A4E8: creates a zeroed 0x48-byte record (4-aligned, from the main heap) and appends it to the
 * owner's record list at +0x1C; returns the record. Sibling of 0x8864AF28. */
typedef struct Rec { int a; int b; int c; int d; int e[14]; } Rec;
typedef struct Vec { Rec **first; Rec **last; Rec **end; } Vec;
typedef struct Obj { char p[0x1c]; Vec recs; } Obj;
extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int flags, int tag);
void ts4_vector_grow_append_scalar4_88174A38(Vec *v, Rec **where, Rec **value);
static Rec *ts4_rec_init(Rec *r)
{
    r->a = 0;
    r->b = 0;
    r->e[0] = 0;
    r->e[1] = 0;
    r->e[2] = 0;
    r->e[3] = 0;
    r->e[4] = 0;
    r->e[5] = 0;
    r->e[6] = 0;
    r->e[7] = 0;
    r->e[8] = 0;
    r->e[9] = 0;
    r->e[10] = 0;
    r->e[11] = 0;
    r->e[12] = 0;
    r->e[13] = 0;
    r->d = 0;
    r->c = 0;
    return r;
}
Rec *ts4_append_new_record_8864A4E8(Obj *o)
{
    Rec *m = (Rec *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x48, 4, 0, 2);
    Rec *s;
    Rec *t;
    Vec *v;
    if (m != 0)
        s = ts4_rec_init(m);
    else
        s = 0;
    t = s;
    v = &o->recs;
    { if (v->last != v->end) { if (v->last != 0) *v->last = s; v->last++; return s; } ts4_vector_grow_append_scalar4_88174A38(v, v->last, &t); return t; }
}
