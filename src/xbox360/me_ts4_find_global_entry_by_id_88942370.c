/* 0x88942370: finds the 8-byte {id, value} entry with the given id in the self-relative table at +0x48 of the global lbl_88D458C0 */
/* Matched on /Oc (agAH). Same begin/end inlines as 8863A780; each inline takes &global->tab directly (a table local gives 0x6c). */
typedef struct Ent { int id; int value; } Ent;
typedef struct Tab { int first; int count; } Tab;
typedef struct Db { char p[0x48]; Tab tab; } Db;
extern Db *lbl_88D458C0;
static __inline Ent *tbegin(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first); return e; }
static __inline Ent *tend(Tab *t) { Ent *e = 0; if (t->first != -1) e = (Ent *)((char *)t + t->first + t->count * sizeof(Ent)); return e; }
Ent *fn_88942370(int id)
{
    Ent *e = tbegin(&lbl_88D458C0->tab);
    Ent *end = tend(&lbl_88D458C0->tab);
    for (; e != end; e++)
        if (e->id == id)
            return e;
    return 0;
}
