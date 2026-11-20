/* 0x888D5298: copy count 0x2d-byte records (11 words + flag byte) from a 0x44-stride source array into the 0x30-stride self-relative table (agAY). Plain /Oc; needs the src_at inline that copies o->src to a local base. */
typedef unsigned char u8;
typedef struct Rec { int w[11]; u8 b; } Rec;
typedef struct SrcRec { Rec r; u8 pad[0x14]; } SrcRec;
typedef struct RelTab { int rel; int count; } RelTab;
typedef struct Obj { u8 pad[0x24]; RelTab *tab; int pad28; SrcRec *src; } Obj;
static void rec_copy(Rec *d, const Rec *s)
{
    d->w[0] = s->w[0]; d->w[1] = s->w[1]; d->w[2] = s->w[2]; d->w[3] = s->w[3];
    d->w[4] = s->w[4]; d->w[5] = s->w[5]; d->w[6] = s->w[6]; d->w[7] = s->w[7];
    d->w[8] = s->w[8]; d->w[9] = s->w[9]; d->w[10] = s->w[10]; d->b = s->b;
}
static Rec *tab_at(RelTab *t, int i) { return (Rec *)((char *)t + t->rel) + i; }
static Rec *src_at(Obj *o, int i) { SrcRec *b = o->src; return &b[i].r; }
void ts4_reltab_fill_records_888D5298(Obj *o)
{
    int i, n = o->tab->count;
    for (i = 0; i < n; i++) { Rec *s = src_at(o, i); rec_copy(tab_at(o->tab, i), s); }
}
