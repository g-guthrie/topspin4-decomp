/* 0x88668EE8 (hand match): resets the tracker. When not dirty it clears state, re-seeds the current pair
 * from the saved pair and zeroes three counters; when dirty it also clears the record lists and every
 * entry of the relative-offset pair array. Then bumps the side tallies and clears the pending flag.
 * The record-clearing callees hand the object back in r3 (the target does not reload it); the array
 * offset is re-read at every use (volatile field). */
typedef struct Pair { int a, b; } Pair;
typedef struct RelArray { volatile int offset; unsigned int count; } RelArray;
typedef struct Sub { char p[0x18]; Pair saved; Pair cur; char p2[0x12c - 0x28]; int c12c, c130, c134;
    char p3[0x170 - 0x138]; RelArray pairs; } Sub;
typedef struct Obj { char p[0x28]; Sub *sub; char p2[0x37c - 0x2c]; unsigned char dirty; char p3[0x3a4 - 0x37d]; unsigned char pending; } Obj;
void ts4_clear_state_8865C018(Obj *o);
Obj *fn_88668DF8(Obj *o);
Obj *ts4_clear_records_88668D70(Obj *o);
void ts4_clear_records_88668C80(Obj *o);
void ts4_bump_side_tallies_88668780(Obj *o);
static __inline void zero3a(Sub *s) { s->c12c = 0; s->c130 = 0; s->c134 = 0; }
static __inline void zero3b(Sub *s) { s->c130 = 0; s->c134 = 0; s->c12c = 0; }
static __inline void reseed(Sub *s) { s->cur = s->saved; }
static __inline void zero3o(Obj *o) { Sub *s = o->sub; s->c12c = 0; s->c130 = 0; s->c134 = 0; }
static __inline void reseedo(Obj *o) { Sub *s = o->sub; s->cur = s->saved; }
static __inline void clean(Obj *o) { reseed(o->sub); zero3a(o->sub); }
void ts4_reset_tracker_88668EE8(Obj *o)
{
    if (!o->dirty) {
        ts4_clear_state_8865C018(o);
        reseed(o->sub);
        { int *c = &o->sub->c12c; c[0] = 0; c[1] = 0; c[2] = 0; }
    } else {
        ts4_clear_state_8865C018(o);
        ts4_clear_records_88668C80(ts4_clear_records_88668D70(fn_88668DF8(o)));
        { int *c = &o->sub->c12c; c[0] = 0; c[1] = 0; c[2] = 0; }
        {
            RelArray *a = &o->sub->pairs;
            unsigned int i, n = a->count;
            for (i = 0; i < n; i++) {
                int off = a->offset;
                Pair *e = (Pair *)((char *)a + (i * 8 + off));
                e->a = 0;
                e->b = 0;
            }
        }
        o->dirty = 0;
    }
    ts4_bump_side_tallies_88668780(o);
    o->pending = 0;
}
