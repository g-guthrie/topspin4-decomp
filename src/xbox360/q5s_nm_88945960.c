/* 0x88945960: finds the 0x170-byte entry whose +0x44 key equals the +0x27C key of the global lbl_88D45B1C in the
 * self-relative table at +0x1C (0 when the table pointer is null).
 * Matched (/Oc plain): the target loads e->key first but compares `cmplw global_key,e->key`. The entry key is a
 * one-word struct copied into a loop local (the 0x886EFCC0 fix). */
typedef struct Ts4GKey { unsigned int id; } Ts4GKey;
typedef struct Ts4GKeyEnt { char pad_00[0x44]; Ts4GKey key; char pad_48[0x170 - 0x48]; } Ts4GKeyEnt;
typedef struct Ts4GKeyTab { int first; int count; } Ts4GKeyTab;
typedef struct Ts4GKeySrc { char pad_00[0x27C]; Ts4GKey key; } Ts4GKeySrc;
typedef struct Ts4GKeyOwner { char pad_00[0x1C]; Ts4GKeyTab *tab; } Ts4GKeyOwner;
extern Ts4GKeySrc *lbl_88D45B1C;

static __inline Ts4GKeyEnt *ts4_gkey_begin(Ts4GKeyTab *t)
{
    Ts4GKeyEnt *e = 0;
    if (t->first != -1)
        e = (Ts4GKeyEnt *)((char *)t + t->first);
    return e;
}

static __inline Ts4GKeyEnt *ts4_gkey_end(Ts4GKeyTab *t)
{
    Ts4GKeyEnt *e = 0;
    if (t->first != -1)
        e = (Ts4GKeyEnt *)((char *)t + t->first + t->count * sizeof(Ts4GKeyEnt));
    return e;
}

Ts4GKeyEnt *ts4_find_rel_entry_by_global_key_88945960(Ts4GKeyOwner *t)
{
    Ts4GKeyEnt *e;
    if (!t->tab)
        return 0;
    for (e = ts4_gkey_begin(t->tab); e != ts4_gkey_end(t->tab); e++) {
        Ts4GKey k;
        k = e->key;
        if (lbl_88D45B1C->key.id == k.id)
            return e;
    }
    return 0;
}
