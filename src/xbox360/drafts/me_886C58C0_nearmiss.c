/* NEAR MISS 0x886C58C0: 21 off, register choice (rows pointer r31, row index r30, segments r3) and
 * the resulting scheduling; structure and all loads/stores are right. */
/* 0x886C58C0 (hand match): turns a key's two blend factors into values. The first is interpolated
 * across the key's segment range; the second across the row's range, which comes from the row's own
 * pair table when the data block has one for it and from the block entry's default range otherwise. */
typedef struct Key { unsigned short segment; unsigned short row; float t; float u; } Key;
typedef struct Segment { char p[4]; float lo; float hi; char p2[0xc]; } Segment;
typedef struct Row { char p[8]; unsigned short entry; unsigned short pair; } Row;
typedef struct Rows { char p[0x14]; Row *rows; } Rows;
typedef struct Segments { char p[8]; Segment *segments; } Segments;
typedef struct Obj { char p[4]; Rows *rows; Segments *segments; } Obj;
typedef struct Rel { volatile int offset; } Rel;
typedef struct Pair { float lo; float hi; char p[8]; } Pair;
typedef struct Entry { Rel pairs; char p[0xc]; float lo; char p2[8]; float hi; char p3[8]; } Entry;
typedef struct Data { char p[0x70]; Rel entries; } Data;
static __forceinline Entry *entry_at(Rel *t, int index) { int off = t->offset; return (Entry *)((char *)t + (index * 0x28 + off)); }
static __forceinline Rel *sub(Rel *t) { Rel *r = 0; int off = t->offset; if (off != -1) r = (Rel *)((char *)t + off); return r; }
static __forceinline Pair *pair_at(Rel *t, int index) { int off = t->offset; return (Pair *)((char *)t + (index * 0x10 + off)); }
void ts4_key_blend_values_886C58C0(Obj *o, Key *k, Data *d, float *out_a, float *out_b)
{
    Rel *tb = &d->entries; unsigned short ri = k->row; float t = k->t; Rows *rs = o->rows; float u = k->u; unsigned short si = k->segment; int off = tb->offset; Row *row = &rs->rows[ri]; float *seg = &o->segments->segments[si].lo;
    Entry *e;
    float lo, hi;
    int po;
    *out_b = u;
    e = (Entry *)((char *)tb + (row->entry * 0x28 + off));
    po = e->pairs.offset;
    *out_a = (seg[1] - seg[0]) * t + seg[0];
    if (po != -1) {
        Pair *p = pair_at((Rel *)((char *)e + po), row->pair);
        lo = p->lo;
        hi = p->hi;
    } else {
        lo = e->lo;
        hi = e->hi;
    }
    *out_b = (hi - lo) * u + lo;
}
