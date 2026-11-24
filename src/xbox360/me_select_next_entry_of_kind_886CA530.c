/* 0x886CA530 (hand match): finds the entry of kind 0x2DB2D90F whose id is the current selection, then
 * advances (wrapping) to the next entry of that kind, selects its id and raises the changed flag.
 * The table's offset is re-read at every use in the target; a volatile field reproduces that. */
typedef struct Entry { char p[0x60]; unsigned int kind; char p2[0x84 - 0x64]; unsigned int id; char p3[0x8c - 0x88]; } Entry;
typedef struct Rel { volatile int offset; unsigned int count; } Rel;
typedef struct Data { char p[0x50]; Rel entries; } Data;
typedef struct A { char p[0x74]; Data *data; } A;
typedef struct B { char p[0x40]; unsigned int selected; char p2[0x102 - 0x44]; unsigned char changed; } B;
typedef struct Link { char p[0x10]; A *a; B *b; } Link;
typedef struct Obj { char p[0x78]; Link *link; } Obj;
static __forceinline Entry *ebegin(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + off); return r; }
static __forceinline Entry *eend(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + (t->count * 0x8c + off)); return r; }
void ts4_select_next_entry_of_kind_886CA530(Obj *o)
{
    Link *l = o->link;
    B *b = l->b;
    Rel *t = &l->a->data->entries;
    unsigned int cur = b->selected;
    Entry *it = ebegin(t);
    Entry *end = eend(t);
    for (; it != end; it++) {
        if (it->kind == 0x2DB2D90F && it->id == cur) {
            it++;
            while (it->kind != 0x2DB2D90F) {
                it++;
                if (it == end)
                    it = ebegin(t);
            }
            b->selected = it->id;
            o->link->b->changed = 1;
            return;
        }
    }
}
