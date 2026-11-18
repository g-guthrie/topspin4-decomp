/* 0x886A6B68: resets a gameplay host between rounds: clears the stats counter and the flag bytes,
   zeroes the self-relative mark array, resets the timer, releases and deletes the holder's object,
   flushes the sink, releases the element pools, then zeroes the cached pointers and empties both
   byte vectors (vector::clear inlined as a self-erase with memmove fn_88562DC0).
   Store order of the zeroing block was fitted to the LTCG scheduler. */
typedef unsigned int U32;
typedef unsigned char U8;
extern void *fn_88562DC0(void *dst, void *src, U32 n);
typedef struct BVec { char *first; char *last; } BVec;
static __inline char *mcopy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        U32 n = (U32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
static __inline void clear(BVec *v) { v->last = mcopy(v->last, v->last, v->first); }
typedef struct Obj Obj;
typedef struct ObjVt { void (*dtor)(Obj *self, int flags); void (*s1)(Obj *); void (*release)(Obj *); void (*reset)(Obj *); void (*s4)(Obj *); void (*flush)(Obj *); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Holder { U8 pad0[4]; int active; Obj *obj; } Holder;
typedef struct Stats { U8 pad0[0x60]; int best; U8 pad64[0x310 - 0x64]; int count; } Stats;
typedef struct Flags { U8 pad0[0x10]; int marks_rel; U32 num_marks; U8 pad18[0x60 - 0x18]; U8 b60; U8 pad61[0x78 - 0x61]; U8 b78; U8 pad79[0x354 - 0x79]; U8 b354; } Flags;
typedef struct Host {
    U8 pad0[4]; BVec list_a; U8 padc[4]; BVec list_b; U8 pad18[4]; int f1c; int f20; int f24; int f28; U8 pad2c[4];
    Stats *stats; U8 pad34[4]; int f38; int f3c; int f40; Flags *flags; int f48; Obj *sink;
    U8 pad50[0x68 - 0x50]; Obj *timer; Holder *holder; U8 pad70[0x78 - 0x70]; int f78; U8 pad7c[0x84 - 0x7c]; U8 *busy;
} Host;
extern void *lbl_88C475FC;
extern char lbl_88D45B04[];
static __inline U8 *marks(int *rel) { return (U8 *)rel + *rel; }
struct Ga4PoolHost; /* src/xbox360/ga4_c.cpp: pools at +0x64 of the same object */
extern void ga4_release_pools_8869F428(struct Ga4PoolHost *self);
void ts4_host_reset_886A6B68(Host *self)
{
    U32 i;
    Holder *h;
    BVec *v;
    self->stats->count = 0;
    self->flags->b78 = 0;
    self->flags->b60 = 0;
    self->flags->b354 = 1;
    *self->busy = 0;
    lbl_88C475FC = lbl_88D45B04;
    for (i = 0; i < self->flags->num_marks; i++)
        marks(&self->flags->marks_rel)[i] = 0;
    self->timer->vt->reset(self->timer);
    h = self->holder;
    h->obj->vt->release(h->obj);
    h->active = 0;
    if (h->obj)
        h->obj->vt->dtor(h->obj, 1);
    self->sink->vt->flush(self->sink);
    ga4_release_pools_8869F428((struct Ga4PoolHost *)self);
    self->stats->best = 0x7fffffff;
    self->f20 = 0;
    self->flags = 0;
    self->f24 = 0;
    self->f48 = 0;
    self->f78 = 0;
    self->f3c = 0;
    self->stats = 0;
    self->f40 = 0;
    self->f28 = 0;
    clear(&self->list_a);
    clear(&self->list_b);
    self->f1c = 0; self->f38 = 0;
}
