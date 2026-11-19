/* 0x88531FF8: passes every id other than 0xFFFF in the count x 8-byte entries to the sink's slot-5 release, then clears the three header bytes */
/* Matched on /Oc (agAH). Plain counted loop; the entry's u16 id sits at +2. */
typedef struct Ent { unsigned short kind; unsigned short id; int data; } Ent;
typedef struct S S;
typedef struct SVt { void *f[5]; void (*release)(S *s, unsigned int id, void *ctx); } SVt;
struct S { SVt *vt; };
typedef struct T { unsigned char a, b, count; char pad[1]; Ent ents[1]; } T;
void fn_88531FF8(T *t, S *s, void *ctx)
{
    unsigned int i;
    for (i = 0; i < t->count; i++)
        if (t->ents[i].id != 0xFFFF)
            s->vt->release(s, t->ents[i].id, ctx);
    t->count = 0;
    t->a = 0;
    t->b = 0;
}
