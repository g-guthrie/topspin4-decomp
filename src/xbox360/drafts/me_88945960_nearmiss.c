/* 0x88945960: finds the 0x170-byte entry whose +0x44 key equals the +0x27C key of the global lbl_88D45B1C in the self-relative table at +0x1C */
/* Near miss (agAH): /Oc, 1 off at +0x5c: cmplw operand order (the 886EFCC0 class, key read from memory). Key locals, != forms and an inline getter leave it. */
typedef struct Ent { char p[0x44]; unsigned int key; char p2[0x170 - 0x48]; } Ent;
typedef struct Tab { int first; int count; } Tab;
typedef struct G { char p[0x27c]; unsigned int key; } G;
extern G *lbl_88D45B1C;
typedef struct T { char p[0x1c]; Tab *tab; } T;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_88945960(T *t)
{
    Ent *e;
    if (!t->tab)
        return 0;
    for (e = tbegin(t->tab); e != tend(t->tab); e++)
        if (e->key == lbl_88D45B1C->key)
            return e;
    return 0;
}
