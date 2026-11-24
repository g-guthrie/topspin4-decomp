/* 0x886AC928 (hand match): for each id in the relative-offset id table, selects it and queries a cost;
 * returns the smallest cost that is not -1 (or -1 when none).
 * The table's offset is re-read at every use in the target; a volatile field reproduces that. */
typedef struct Rel { volatile int offset; unsigned int count; } Rel;
typedef struct Data { char p[0x5b0]; Rel ids; } Data;
typedef struct Sel { char p[0x380]; int id; } Sel;
typedef struct Obj { char p[0x2c]; Data *data; char p2[0x60 - 0x30]; void *query; char p3[0x74 - 0x64]; Sel *sel; } Obj;
int fn_886DAA48(void *q, int a, int b, int c);
static __forceinline int *ibegin(Rel *t) { int *r = 0; int off = t->offset; if (off != -1) r = (int *)((char *)t + off); return r; }
static __forceinline int *iend(Rel *t) { int *r = 0; int off = t->offset; if (off != -1) r = (int *)((char *)t + (t->count * 4 + off)); return r; }
static __forceinline int pick(int best, int r) { if (r != -1 && (best == -1 || r < best)) return r; return best; }
static __forceinline int pick2(int best, int r) { if (r != -1) { if (best == -1 || r < best) best = r; } return best; }
int ts4_min_cost_over_ids_886AC928(Obj *o)
{
    int best = -1;
    Rel *t = &o->data->ids;
    int *end = iend(t);
    int *it;
    for (it = ibegin(t); it != end; it++) {
        int r;
        o->sel->id = *it;
        r = fn_886DAA48(o->query, 1, 3, 1);
        if (r != -1) { if (best == -1) best = r; else if (r < best) best = r; }
    }
    return best;
}
