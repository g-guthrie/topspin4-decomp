/* Swing_DLL.xex 0x8899E740: Resets the owner's stats block: clears the counters, marks it 0xAAAAAAAA, clears the range and every 12-byte slot's two values in the self-relative table at +0x44, then the current triple.
 * /Oc. Inline clear helpers on embedded {a,b}/{a,b,c} structs give one reload per group and the clrrwi copy; the null test is signed (cmpwi). */
typedef struct Slot { int id; int a; int b; } Slot;
typedef struct SlotTab { int first; int count; } SlotTab;
typedef struct Stats {
    unsigned char pad[0x3c];
    unsigned int mark;     /* 0x3c */
    int x40;               /* 0x40 */
    SlotTab slots;         /* 0x44 */
    unsigned char pad4c[4];
    struct Range { int a, b; } range;  /* 0x50 */
    struct Triple { int a, b, c; } cur; /* 0x58 */
    int w3, w4, w5, w6, w7, w8, w9, w10, w11; /* 0x64..0x84 */
} Stats;
typedef struct Owner { unsigned char pad[0xb8]; Stats *stats; } Owner;

static __inline Slot *tbegin(SlotTab *t) { Slot *e = 0; if (t->first != -1) e = (Slot *)((char *)t + t->first); return e; }
static __inline Slot *tend(SlotTab *t) { Slot *e = 0; if (t->first != -1) e = (Slot *)((char *)t + t->first + t->count * sizeof(Slot)); return e; }

static __inline void range_clear(struct Range *r) { r->a = 0; r->b = 0; }
static __inline void triple_clear(struct Triple *t) { t->a = 0; t->b = 0; t->c = 0; }
static __inline void stats_clear(Stats *s)
{
    s->mark = 0;
    s->x40 = 0;
    triple_clear(&s->cur); s->w3 = 0; s->w4 = 0; s->w5 = 0;
    s->w6 = 0; s->w7 = 0; s->w8 = 0; s->w9 = 0; s->w10 = 0; s->w11 = 0;
}

void fn_8899E740(Owner *o)
{
    Slot *e, *end;
    if ((int)o->stats == 0) return;
    stats_clear(o->stats);
    o->stats->mark = 0xAAAAAAAA;
    range_clear(&o->stats->range);
    end = tend(&o->stats->slots);
    for (e = tbegin(&o->stats->slots); e != end; e++) {
        e->a = 0;
        e->b = 0;
    }
    triple_clear(&o->stats->cur);
}
