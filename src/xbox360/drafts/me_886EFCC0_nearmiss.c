/* 0x886EFCC0: finds the 0x78-byte entry whose +0x74 key equals *key in the self-relative table at data+0x14 (0 when data is null) */
/* Near miss (agAH): /Oc, 1 off at +0x54: cmplw operand order (target key, e->key with e->key loaded first). Operand order, key locals and eq() inlines in all four arrangements leave it 1 or 3 off. */
typedef struct Ent { char p[0x74]; unsigned int key; } Ent;
typedef struct Tab { int first; int count; } Tab;
typedef struct Data { char p[0x14]; Tab tab; } Data;
typedef struct T { char p[0x14]; Data *data; } T;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_886EFCC0(T *t, const unsigned int *key)
{
    Ent *e;
    if (!t->data)
        return 0;
    for (e = tbegin(&t->data->tab); e != tend(&t->data->tab); e++)
        if (e->key == *key)
            return e;
    return 0;
}
