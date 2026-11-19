typedef struct Ent { char pad[0x10]; unsigned int id; char p1[4]; unsigned char a; unsigned char c; unsigned char b; char p2[0x95]; } Ent;
typedef struct RelArr { int rel; int n; } RelArr;
typedef struct Db { char pad[0x38]; RelArr *ents; } Db;
typedef struct Game { char pad[0x234]; Db *db; } Game;
extern Game *lbl_88D45B1C;
extern unsigned int *lbl_88D459CC;
void ts4_param_dispatch_88865128(unsigned int *base, int idx, float f, unsigned int arg);
static Ent *rbegin(RelArr *a) { Ent *b = 0; if (a->rel != -1) b = (Ent *)((char *)a + a->rel); return b; }
static Ent *rend(RelArr *a) { Ent *e = 0; if (a->rel != -1) e = (Ent *)((char *)a + (a->n * sizeof(Ent) + a->rel)); return e; }
/* Dispatches a param update for every table entry whose three enable flags are set. */
void fn_888C7A38(int who, float t)
{
    RelArr *a = lbl_88D45B1C->db->ents;
    Ent *e = rbegin(a);
    Ent *end = rend(a);
    for (; e != end; e++)
        if (e->a && e->b && e->c)
            ts4_param_dispatch_88865128(lbl_88D459CC, who, t, e->id);
}
