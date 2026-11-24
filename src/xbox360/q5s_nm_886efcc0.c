/* 0x886EFCC0: finds the 0x78-byte entry whose +0x74 key equals *key in the self-relative table at data+0x14
 * (0 when data is null).
 * Matched (/Oc plain): the target loads e->key first but compares `cmplw key,e->key`. The entry key is a one-word
 * struct copied into a loop local, which keeps its load first while the compare follows the written order. */
typedef struct Ts4RelKey { unsigned int id; } Ts4RelKey;
typedef struct Ts4RelKeyEnt { char pad_00[0x74]; Ts4RelKey key; } Ts4RelKeyEnt;
typedef struct Ts4RelKeyTab { int first; int count; } Ts4RelKeyTab;
typedef struct Ts4RelKeyData { char pad_00[0x14]; Ts4RelKeyTab tab; } Ts4RelKeyData;
typedef struct Ts4RelKeyOwner { char pad_00[0x14]; Ts4RelKeyData *data; } Ts4RelKeyOwner;

static __inline Ts4RelKeyEnt *ts4_relkey_begin(Ts4RelKeyTab *t)
{
    Ts4RelKeyEnt *e = 0;
    if (t->first != -1)
        e = (Ts4RelKeyEnt *)((char *)t + t->first);
    return e;
}

static __inline Ts4RelKeyEnt *ts4_relkey_end(Ts4RelKeyTab *t)
{
    Ts4RelKeyEnt *e = 0;
    if (t->first != -1)
        e = (Ts4RelKeyEnt *)((char *)t + t->first + t->count * sizeof(Ts4RelKeyEnt));
    return e;
}

Ts4RelKeyEnt *ts4_find_rel_entry_by_key_886EFCC0(Ts4RelKeyOwner *t, const Ts4RelKey *key)
{
    Ts4RelKeyEnt *e;
    if (!t->data)
        return 0;
    for (e = ts4_relkey_begin(&t->data->tab); e != ts4_relkey_end(&t->data->tab); e++) {
        Ts4RelKey k;
        k = e->key;
        if (key->id == k.id)
            return e;
    }
    return 0;
}
