/* 0x886C84F0 (hand match): returns the handle of the span that contains the entry's index in its
 * table, or the global default handle when no span does. */
typedef struct Handle { unsigned int v; } Handle;
typedef struct Span { Handle handle; short start; unsigned short length; char p[0x18 - 8]; } Span;
typedef struct Spans { int offset; unsigned int count; } Spans;
typedef struct Entry { char p[0x8c]; } Entry;
typedef struct Rel { volatile int offset; unsigned int count; } Rel;
typedef struct Data { char p[0x50]; Rel entries; } Data;
typedef struct A { char p[0xc]; Data *data; } A;
typedef struct Globals { char p[0x27c]; Handle default_handle; } Globals;
extern Globals *lbl_88D45B1C;
static __forceinline Entry *ebegin(Rel *t) { Entry *r = 0; int off = t->offset; if (off != -1) r = (Entry *)((char *)t + off); return r; }
static __forceinline Span *sbegin(Spans *t) { Span *r = 0; if (t->offset != -1) r = (Span *)((char *)t + t->offset); return r; }
static __forceinline Span *send(Spans *t) { Span *r = 0; if (t->offset != -1) r = (Span *)((char *)t + (t->count * 0x18 + t->offset)); return r; }
static __forceinline unsigned char contains(Span *s, int i) { return s->start <= i && i < s->start + s->length; }
Handle *ts4_span_handle_for_entry_886C84F0(Handle *__restrict out, A *a, Entry *e, Spans *t)
{
    int idx = e - ebegin(&a->data->entries);
    Span *end;
    Span *it;
    *out = lbl_88D45B1C->default_handle;
    end = send(t);
    for (it = sbegin(t); it != end; it++) {
        if (contains(it, idx)) {
            *out = it->handle;
            return out;
        }
    }
    return out;
}
