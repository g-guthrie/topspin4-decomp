/* NEAR MISS 0x886CD580: 5 off, register swap between entry index and column. */
/* 0x886CD580 (hand match): whether the current entry has the bit for the given pair set in the data
 * block's bit table (row = entry index * stride + column, tested against the pair's mask). False when
 * the owner's list is empty. */
typedef struct Entry { char p[0x8c]; } Entry;
typedef struct Rel { volatile int offset; unsigned int count; } Rel;
typedef struct Data { char p[0xc]; int stride; char p2[0x50 - 0x10]; Rel entries; char p3[0x84 - 0x58]; int bits_offset; } Data;
typedef struct Src { char p[0xc]; Data *data; } Src;
typedef struct Node2 { char p[8]; Entry *entry; } Node2;
typedef struct Node { char p[4]; Node2 *n; } Node;
typedef struct Ctx { char p[0x18]; Src *src; char p2[0x8c - 0x1c]; Node **nodes; } Ctx;
typedef struct List { char p[0x5c]; void *begin; void *end; } List;
typedef struct Obj { char p[0x28]; Ctx *ctx; List *list; } Obj;
void ts4_entry_sub_key_bit_886C87B8(Src *src, int *a, int *b, int *column, unsigned int *mask);
static __forceinline Entry *ebegin(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + off); return r; }
static __forceinline int eindex(Rel *t, Entry *e) { return e - ebegin(t); }
static __forceinline int eindex2(Rel *t, Entry *e) { Entry *b = ebegin(t); return e - b; }
static __forceinline unsigned int eindex3(Rel *t, Entry *e) { return (unsigned int)(e - ebegin(t)); }
static __forceinline int eindex4(Rel *t, Entry *e) { int d = (char *)e - (char *)ebegin(t); return d / 0x8c; }
unsigned char ts4_entry_pair_bit_set_886CD580(Obj *o, int a, int b)
{ int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0;
    int column;
    unsigned int mask;
    Entry *e;
    unsigned char r = 0;
    Data *d;
    unsigned int *bits;
    int stride;
    int idx;
    if (o->list->begin != o->list->end) {
    e = o->ctx->nodes[0]->n->entry;
    ts4_entry_sub_key_bit_886C87B8(o->ctx->src, &a, &b, &column, &mask);
    d = o->ctx->src->data;
    { int *bo = &d->bits_offset; Rel *t = &d->entries; bits = (unsigned int *)(*bo + (char *)bo);
    stride = d->stride;
    r = 0 != (bits[eindex(t, e) * stride + column] & mask); }
    }
    return r;
}
