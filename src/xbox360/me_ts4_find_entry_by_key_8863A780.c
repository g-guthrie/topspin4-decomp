/* 0x8863A780: finds the 0x50-byte entry whose +0x28 field equals key in a self-relative table {first offset (-1 = none), count} */
/* Matched on /Oc (agAH). begin/end inlines as 'e = 0; if (first != -1) e = ...', found-result local, loop test written 'end != e'. */
typedef struct Ent { char p[0x28]; void *key; char p2[0x24]; } Ent;
typedef struct Tab { int first; int count; } Tab;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_8863A780(void *key, Tab *t)
{
    Ent *r = 0;
    Ent *end = tend(t);
    Ent *e;
    for (e = tbegin(t); end != e; e++)
        if (e->key == key) {
            r = e;
            break;
        }
    return r;
}
