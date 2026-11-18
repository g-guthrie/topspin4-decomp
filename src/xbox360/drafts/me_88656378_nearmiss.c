/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). Clamp spellings: >3 or int index 6; && form, ternary min, 4<=i 5;
 * result-variable forms 58-59; early return or ternary on busy, flattened slot: 54-55 (0xE4-0xE8). */
/* agentA2 (b120 real-virtuals pass): C++ with the vtable callees as real virtuals (correct slots) gives the same 5 off;
   tried up to 8 variants (inline members, guard object, zero/hash locals, early-return spellings). Still 5 off. */
/* NEAR MISS 0x88656378: 5 off, block order of the final clamp (target falls through to "4" and
 * branches to "i"); invariant over ternary/if/early-return spellings. */
/* 0x88656378 (hand match): slot index (0-3) of the entry with the given key in the source's entry
 * table; 4 when the owner is busy, the source is not ready, or the key is not in the first four. */
typedef struct Entry { char p[0x18]; unsigned int key; } Entry;
typedef struct Rel { int offset; int count; } Rel;
typedef struct Data { char p[0x48]; Rel entries; } Data;
typedef struct Source Source;
typedef struct SourceVt { void *s[12]; unsigned char (*ready)(Source *self); void *s2[6]; Data *(*data)(Source *self, int which); } SourceVt;
struct Source { SourceVt *vt; };
typedef struct Obj { char p[0x1c]; Source source; char p2[0x78 - 0x20]; void *busy; } Obj;
static __forceinline Entry *eend(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + (t->count * 0x1c + off)); return r; }
static __forceinline Entry *ebegin(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + off); return r; }
static __forceinline unsigned int find(Source *s, unsigned int key)
{
    unsigned int i = 0;
    Data *d = s->vt->data(s, 0);
    Rel *t = &d->entries;
    Entry *end = eend(t);
    Entry *e;
    for (e = ebegin(t); end != e; e++) {
        if (key == e->key)
            break;
        i++;
    }
    return i;
}
static __forceinline unsigned int slot(Source *s, unsigned int key)
{
    unsigned int i;
    if (!s->vt->ready(s) || (i = find(s, key)) >= 4)
        return 4;
    return i;
}
unsigned int ts4_entry_slot_for_key_88656378(Obj *o, unsigned int key)
{
    unsigned int r = 4;
    if (o->busy == 0)
        r = slot(&o->source, key);
    return r;
}
