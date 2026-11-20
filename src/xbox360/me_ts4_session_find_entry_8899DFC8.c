/* 0x8899DFC8: in the session context's current row (self-relative row table at +0x64 of the block at +0x3E8), finds the 0x24-byte entry with the given key */
/* Matched on /Oc (agAH). A 'Rel *rel = &s->rows' local flips the add order of the row address (OP1 symbol-number rule); count hoisted into a local. */
typedef struct Ent { unsigned int key; char p[0x20]; } Ent;
typedef struct Row { int first; unsigned int count; int pad[2]; } Row;
typedef struct Rel { int first; int count; } Rel;
typedef struct Sub { char p[0x64]; Rel rows; char p2[4]; int cur; } Sub;
typedef struct Inner { char p[0x3e8]; Sub sub; } Inner;
typedef struct G { char p[0x3c]; Inner *in; } G;
extern G *g_ts4_session_context;
static __inline Row *row_at(Rel *r, int i) { return (Row *)((char *)r + r->first) + i; }
static __inline Ent *ent_at(Row *r, unsigned int i) { return (Ent *)((char *)r + r->first) + i; }
Ent *fn_8899DFC8(unsigned int key)
{
    Sub *s = &g_ts4_session_context->in->sub;
    Rel *rel = &s->rows;
    Row *row = row_at(rel, s->cur);
    unsigned int i, n = row->count;
    for (i = 0; i < n; i++) {
        Ent *e = ent_at(row, i);
        if (e->key == key)
            return e;
    }
    return 0;
}
