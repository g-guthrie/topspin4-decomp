/* 0x886B0F18: tears down the match-state object built by the constructor at 0x886B4D00 (draft
   me_886B4D00_nearmiss.cpp): clears the nine 0x44-byte slots and the track, resets and releases the owned
   sub-objects (virtual deleting destructor slot 0 with flag 1), frees the two event queues, then empties the
   32-byte and 16-byte record vectors (inlined vector::clear) and finalizes the trailing object. */
#include "ts4_vector.h"
typedef unsigned char U8;
typedef struct Obj Obj;
typedef struct ObjVt { void (*destroy)(Obj *self, int flags); void (*s1)(Obj *); void (*reset)(Obj *); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Rec32 { __int64 a, b, c, d; } Rec32;
typedef struct Vec32 { Rec32 *first; Rec32 *last; } Vec32;
typedef struct Vec16 { __vector4 *first; __vector4 *last; } Vec16;
typedef struct Queue { char p[0x7c]; void *owned; char p80[0x88 - 0x80]; int count; } Queue;
typedef struct Triple { char a[0x44]; char b[0x44]; char c[0x44]; void *cur; } Triple;
typedef struct Five { char p[4]; char a[0x44]; char b[0x44]; char c[0x44]; char d[0x44]; char e[0x44]; } Five;
typedef struct Pair { char p[0x18]; struct { char p[4]; int w4; char p8[4]; int wc; } *sub; } PairS;
typedef struct Rally {
    char p0[0x54]; Obj *listener; Triple *triple; Obj *pair; void *f60; void *pool; Obj *res68; Five *five; void *subs; void *fx;
    char p78[0x94 - 0x78]; char f94[0xc]; char fa0[0x14]; void *fb4_; void *fb8_; Obj *fbc; Obj *fc0; Obj *fc4; void *fc8;
    char slot[9][0x44]; char track[0x3c]; Vec16 v36c; char p374[4]; char f378[0x10]; Vec32 v388;
} Rally;
typedef struct Body { char p[0x1068]; unsigned int state_hash; } Body;
void fn_8890DDA8(void *slot);
void ga3_pool_destroy_88691798(void *pool);
void fn_8826B328(void *p);
void ts4_if_call_seq_fn_8890DDA8_886906E8(Five *f);
void ts4_destroy_two_subs_88671A98(void *s);
void ts4_object_finalize(void *o);
void ts4_vec16_clear_8890E088(void *v);
void ts4_obj44_dtor_8890F1E8(void *o);
void ts4_tsu_cleanup_end(void *mem);
void ts4_if_call_seq_fn_8890F1E8_886A1250(void *s);
void ts4_vector_clear_8865A5E0(Queue *q);
void ts4_destroy_owned_object(void *o);
static __inline void release(Obj *o) { if (o) o->vt->destroy(o, 1); }
static __inline void free_queue(Queue *q) { if (q) { ts4_vector_clear_8865A5E0(q); { int *pc = &q->count; *pc = 0; } if (q->owned) ts4_destroy_owned_object(q->owned); ts4_tsu_cleanup_end(q); } }
void ts4_match_state_teardown_886B0F18(Rally *self)
{
    Triple *t;
    Five *f;
    void *s;
    fn_8890DDA8(self->slot[0]);
    ((Body *)self->fx)->state_hash = 0xD32429A6;
    ga3_pool_destroy_88691798(self->pool);
    fn_8826B328(self->f94);
    t = self->triple;
    fn_8890DDA8(t->c);
    fn_8890DDA8(t->b);
    fn_8890DDA8(t->a);
    t->cur = 0;
    ts4_if_call_seq_fn_8890DDA8_886906E8(self->five);
    ((int *)self->res68)[12] = 0;
    ts4_destroy_two_subs_88671A98(self->subs);
    {
        PairS *p = (PairS *)self->pair;
        { struct { char p[4]; int w4; char p8[4]; int wc; } *q = p->sub; q->wc = 0; q->w4 = 0; }
        ((int *)p)[5] = 0; ((int *)p)[4] = 0;
    }
    ts4_object_finalize(self->fa0);
    self->listener->vt->reset(self->listener);
    ts4_vec16_clear_8890E088(self->track);
    fn_8890DDA8(self->slot[5]); fn_8890DDA8(self->slot[6]); fn_8890DDA8(self->slot[7]); fn_8890DDA8(self->slot[8]);
    fn_8890DDA8(self->slot[2]); fn_8890DDA8(self->slot[3]); fn_8890DDA8(self->slot[4]); fn_8890DDA8(self->slot[1]);
    release((Obj *)self->pool);
    t = self->triple;
    if (t) { ts4_obj44_dtor_8890F1E8(t->c); ts4_obj44_dtor_8890F1E8(t->b); ts4_obj44_dtor_8890F1E8(t->a); ts4_tsu_cleanup_end(t); }
    release(self->fc0);
    release(self->res68);
    s = self->subs;
    if (s) { ts4_if_call_seq_fn_8890F1E8_886A1250(s); ts4_tsu_cleanup_end(s); }
    ts4_tsu_cleanup_end(self->fc8);
    free_queue((Queue *)self->fb8_);
    release(self->fbc);
    free_queue((Queue *)self->fb4_);
    release(self->fc4);
    release(self->pair);
    release(self->listener);
    f = self->five;
    if (f) { ts4_obj44_dtor_8890F1E8(f->e); ts4_obj44_dtor_8890F1E8(f->d); ts4_obj44_dtor_8890F1E8(f->c); ts4_obj44_dtor_8890F1E8(f->b); ts4_obj44_dtor_8890F1E8(f->a); ts4_tsu_cleanup_end(f); }
    {
        Vec32 *v = &self->v388; Rec32 *src = v->last, *dst = v->first; int n = (int)(v->last - src);
        for (; n > 0; n--) *dst++ = *src++;
        v->last = dst;
    }
    {
        Vec16 *v = &self->v36c; __vector4 *src = v->last, *dst = v->first; int n = (int)(v->last - src);
        for (; n > 0; n--) *dst++ = *src++;
        v->last = dst;
    }
    ts4_object_finalize(self->f378);
}
