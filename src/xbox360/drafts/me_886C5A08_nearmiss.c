/* 0x886C5A08 near miss (66 off, /Oc plain C). Checks whether a shot target allows the actor's side: grid lookup of
 * a cell (actor pose x entry), link must carry hash 0x575896F4, then kind 5/6/7 rules against side and q->sub.
 * Keys: rel() inline for relative tables, single exit, kind_allows inline. Residue: target keeps each bool as
 * li 1 / li 0 branches (we get cntlzw), a dead li r9,0 for ok, and an early r9/r7 register swap. */
typedef unsigned int u32; typedef unsigned char u8; typedef unsigned short u16;
typedef struct Pose { char _0[0x22]; short cell; } Pose;
typedef struct PoseH { char _0[8]; Pose *pose; } PoseH;
typedef struct PoseHH { char _0[4]; PoseH *h; } PoseHH;
typedef struct Count { char _0[0x74]; int n; } Count;
typedef struct CountH { char _0[8]; Count *c; } CountH;
typedef struct CountHH { char _0[4]; CountH *h; } CountHH;
typedef struct Mode { char _0[0x2A]; u16 alt_side; u8 split; } Mode;
typedef struct Actor { char _0[4]; PoseH *pose; char _8[0x2C]; CountHH *count; char _38[0x34]; Mode *mode; } Actor;
typedef struct Rel { int offset; } Rel;
typedef struct Grid { char _0[0x10]; int stride; } Grid;
typedef struct Link { int offset; u32 hash; } Link;
typedef struct Target { char _0[4]; u8 kind, sub; } Target;
typedef struct Db { char _0[0x14]; Rel grid; char _18[0x20]; Rel links; char _3c[8]; Rel cells; char _48[8]; Rel entries; } Db;
typedef struct DbH { char _0[8]; Db *db; } DbH;
typedef struct Sys { char _0[0x1C]; DbH *dbh; char _20[0x6C]; Actor **actors; } Sys;
typedef struct Ref { Sys *sys; } Ref;
typedef struct Who { char _0[0x14]; u8 actor, side; } Who;
typedef struct Query { int entry; char _4[4]; u16 sub; } Query;
typedef struct Query Query;
typedef struct Entry { char _0[0x22]; short cell; char _24[0x68]; } Entry;
static __inline u8 kind_allows(u8 kind, int side, Query *q)
{
    if (kind == 5) {
        if (side == 0) return q->sub == 0;
        if (side == 1) return q->sub == 1;
        return 0;
    }
    if (kind == 6) {
        if (side == 0 || side == 1) return q->sub == 0;
        return 0;
    }
    if (kind == 7) {
        if (side == 2 || side == 3) return q->sub == 0;
    }
    return 0;
}
static __inline void *rel(Rel *r) { return (char *)r + r->offset; }
u8 ts4_target_allows_8865C5A08(Ref *ref, Who *who, Query *q)
{
    Sys *sys = ref->sys;
    int side = who->side;
    Db *db = sys->dbh->db;
    Actor **pa = &sys->actors[who->actor];
    Entry *e = (Entry *)rel(&db->entries) + q->entry;
    Actor *a = *pa;
    Mode *m = a->mode;
    Pose *p = a->pose->pose;
    short cell;
    Link *l;
    Target *t;
    u8 ok, ret;
    if (m->split) {
        if (side == 0) {
            if (a->count) {
                int n = a->count->h->c->n - 1;
                if (n <= 1) side = 1; else side = n;
            }
        } else if (side == 1) {
            p = pa[1]->pose->pose;
            side = m->alt_side;
        }
    }
    {
        Grid *g = (Grid *)rel(&db->grid);
        cell = ((short *)rel(&db->cells))[p->cell * g->stride + e->cell];
    }
    ret = 0;
    if (cell != -1) {
        l = (Link *)rel(&db->links) + cell;
        if (l->hash == 0x575896F4u) {
            t = (Target *)rel((Rel *)l);
            ok = kind_allows(t->kind, side, q);
            if (ok || (side == t->kind && q->sub == t->sub))
                ret = 1;
            else
                ret = 0;
        }
    }
    return ret;
}
