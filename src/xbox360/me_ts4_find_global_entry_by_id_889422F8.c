/* 0x889422F8: finds the 0x60-byte entry whose +0x48 id equals id in the self-relative table at +0x18 of the global lbl_88D458C0 */
/* Matched on /Oc (agAH). 88942370 template with a different table offset and stride. */
typedef struct Ent { char p[0x48]; int id; char p2[0x14]; } Ent;
typedef struct Tab { int first; int count; } Tab;
typedef struct Db { char p[0x18]; Tab tab; } Db;
extern Db *lbl_88D458C0;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_889422F8(int id)
{
    Ent *e = tbegin(&lbl_88D458C0->tab);
    Ent *end = tend(&lbl_88D458C0->tab);
    for (; e != end; e++)
        if (e->id == id)
            return e;
    return 0;
}
