/* 0x88522BC0: Releases every pair value other than 0xFFFF through sink vt slot 5 (sink, value, ctx), empties the set, clears the owner dirty byte, and returns the address of the set tail at +0x40. */
/* Matched on /Oc (agAH). Same PairSet layout as 88468370. */
typedef struct Pair { unsigned char a; unsigned char b; unsigned short value; } Pair;
typedef struct PairSet { Pair items[8]; unsigned char p20; unsigned char count; char p22[0x1e]; char tail[4]; } PairSet;
typedef struct Owner { char p0[2]; unsigned char dirty; } Owner;
typedef struct Sink Sink;
typedef struct SinkVt { void *s[5]; void (*release)(Sink *, unsigned int, void *); } SinkVt;
struct Sink { SinkVt *vt; };
void *fn_88522BC0(Owner *o, PairSet *set, Sink *sink, void *ctx)
{
    int i;
    for (i = 0; i < set->count; i++) {
        unsigned short v = set->items[i].value;
        if (v != 0xFFFF)
            sink->vt->release(sink, v, ctx);
    }
    set->count = 0;
    o->dirty = 0;
    return set->tail;
}
