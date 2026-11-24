/* 0x888CA5A8: resets four 0x3c-byte service slots: empties each 12-byte entry vector, resets the range record
 * (lo=0, cur=0, hi=0xFFFFF), and for each bound entry whose service id still resolves clears the +0x10 field of its items. */

typedef unsigned int u32;
typedef struct { u32 a, b, c; } E12;
typedef struct { char pad[0x10]; u32 f10; } I14;
typedef struct { u32 svc; I14 *first, *last; u32 pad; } E16;
typedef struct { E12 *first, *last; } V12;
static void e12_erase(V12 *v, E12 *dst, E12 *first) {
    int n = v->last - first; E12 *p = dst; E12 *s = first;
    while (n > 0) { *p = *s; n--; p++; s++; }
    v->last = p;
}
typedef struct {
    E16 *lfirst, *llast; char p8[0x18-8];
    struct Sub { V12 v; char p20[4]; struct Rng { u32 lo; u32 hi; u32 cur; } rng; } s; char p30[0x3c-0x30];
} Rec;
static void rng_reset(struct Rng *g) { g->lo = 0; g->cur = 0; g->hi = 0xFFFFF; }
static void sub_reset(struct Sub *s) { e12_erase(&s->v, s->v.first, s->v.last); rng_reset(&s->rng); }
typedef struct { char pad[0x1c]; Rec recs[4]; } O;
extern void *ts4_find_service(u32 service_id);
void ts4_service_slots_reset_888CA5A8(O *o) {
    int i;
    for (i = 0; i < 4; i++) {
        Rec *r = &o->recs[i];
        E16 *e, *ee;
        sub_reset(&r->s);
        ee = r->llast;
        for (e = r->lfirst; ee != e; e++) {
            if (e->svc && ts4_find_service(e->svc)) {
                I14 *it, *end = e->last;
                for (it = e->first; end != it; it++) it->f10 = 0;
            }
        }
    }
}
