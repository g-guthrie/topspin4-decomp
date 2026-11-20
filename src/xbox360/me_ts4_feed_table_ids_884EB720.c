/* Swing_DLL.xex 0x884EB720: passes the first word of every 20-byte entry of the global table lbl_88D26FD0->+0xc, with
 * its index, to virtual slot 1 of the sink at self+8; returns 0. agO: lookalike of 88461390, plain and LTCG. */
typedef struct Entry { int id; char rest[0x10]; } Entry;
typedef struct EntryVec { Entry *items; int count; } EntryVec;
typedef struct Table { char pad[0xc]; EntryVec entries; } Table;
typedef struct Sink Sink;
typedef struct SinkVt { void *s0; void (*add)(Sink *self, int id, int index); } SinkVt;
struct Sink { SinkVt *vt; };
typedef struct Obj { char pad[8]; Sink sink; } Obj;
extern Table *lbl_88D26FD0;

int fn_884EB720(Obj *o)
{
    int i;
    EntryVec *v = &lbl_88D26FD0->entries;
    for (i = 0; i < v->count; i++)
        o->sink.vt->add(&o->sink, v->items[i].id, i);
    return 0;
}
