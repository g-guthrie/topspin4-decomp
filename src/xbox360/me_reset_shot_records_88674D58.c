/* 0x88674D58 (hand match): reset the per-shot records: every 0x1070-byte record's timer goes
 * back to its default, the two running counters are cleared, and both flags of every
 * 16-byte marker entry are cleared. */
typedef struct Shot { char p[0xf80]; float timer; char p2[0x1070 - 0xf84]; } Shot;
typedef struct ShotTab { volatile int offset; unsigned int count; } ShotTab;
typedef struct Marker { char p[0xc]; unsigned char active; unsigned char hit; char p2[2]; } Marker;
typedef struct MarkTab { int offset; unsigned int count; } MarkTab;
typedef struct Data { char p[0x3c]; MarkTab markers; } Data;
typedef struct Obj { char p[0x28]; Data *data; ShotTab *shots; char p2[0x39c - 0x30]; int c0; int c1; } Obj;
extern float lbl_8814B440;
static __forceinline Shot *sbegin(ShotTab *t) { Shot *r = 0; int off = t->offset; if (off != -1) r = (Shot *)((char *)t + off); return r; }
static __forceinline Shot *send(ShotTab *t) { Shot *r = 0; int off = t->offset; if (off != -1) r = (Shot *)((char *)t + (t->count * sizeof(Shot) + off)); return r; }
void ts4_reset_shot_records_88674D58(Obj *o)
{
    Shot *e = send(o->shots);
    Shot *__restrict p;
    unsigned int i, n;
    MarkTab *m;
    for (p = sbegin(o->shots); p != e; p++)
        p->timer = lbl_8814B440;
    { int *sp = &o->c0; *sp = 0; } { int *sp = &o->c1; *sp = 0; }
    m = &o->data->markers;
    n = m->count;
    for (i = 0; i < n; i++) {
        Marker *k = (Marker *)((char *)m + (i * sizeof(Marker) + m->offset));
        k->active = 0;
        k->hit = 0;
    }
}
