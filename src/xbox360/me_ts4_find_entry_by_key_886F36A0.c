/* 0x886F36A0: finds the 0x30-byte entry whose +0x24 key equals key in the self-relative table at data+0xC (0 when data is null) */
/* Matched on /Oc (agAH). 8863A780 inlines with end recomputed in the loop test (e != tend(...)); 886EFCC0 is the 1-off pointer-key sibling. */
typedef struct Ent { char p[0x24]; unsigned int key; char p2[8]; } Ent;
typedef struct Tab { int first; int count; } Tab;
typedef struct Data { char p[0xc]; Tab tab; } Data;
typedef struct T { char p[0xc]; Data *data; } T;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_886F36A0(T *t, unsigned int key)
{
    Ent *e;
    if (!t->data)
        return 0;
    for (e = tbegin(&t->data->tab); e != tend(&t->data->tab); e++)
        if (key == e->key)
            return e;
    return 0;
}
