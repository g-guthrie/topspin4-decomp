/* agentA2 2026-11-18: skipped: operand order on strength-reduced/inner-loop index sites, pads 1-8 already swept (known-unsolved); still 3. */
/* NEAR MISS 0x8867B800: 3 off: add/stwx/lwzx operand order only (i*16+offset; units base vs idx*4). 7 variants (indexing spellings).  ME sweep: 4 dead int pads at the function top fix the outer i*16+offset site but the inner-loop stwx/lwzx/stwx triple flips (still 3); inner/outer loop pads 1-8 and five more index spellings with it: no change. */
typedef unsigned int u32;
struct vec { u32 *first; u32 *last; };
void ts4_vec_resize_8826B298(struct vec *v, u32 n);

typedef struct Group { char p[0x10]; struct vec members; char q[0x10]; int side; } Group;
typedef struct Unit { char p[0x14]; int index; int slot; char q[0x30]; Group *group; } Unit;
typedef struct GroupDef { int members_off; int pad[2]; u32 kind; } GroupDef;   /* self-relative member index list */
typedef struct RelTable { int offset; } RelTable;                              /* self-relative GroupDef array */
typedef struct Layout { char p[0x50]; RelTable defs; } Layout;
typedef struct Pool { char p[0x78]; char *units; } Pool;                      /* Unit records, stride 0x3D0 */
typedef struct Counts { int groups; int per_group; } Counts;
typedef struct Team {
    void *vt; Unit **units; char p0[8]; Group **groups; char p1[0x2c]; Layout *layout;
    char p2[0x20]; Pool *pool; char p3[0x10]; Counts *counts;
} Team;

/* 0x8867B800: assign every group its side from the layout kind hash and fill its member list from the unit pool. */
void ts4_team_build_groups_8867B800(Team *t)
{
    int ngroups = t->counts->groups;
    int per = t->counts->per_group;
    int i, j;
    for (i = 0; i < ngroups; i++) {
        Group *g = t->groups[i];
        RelTable *tab = &t->layout->defs;
        GroupDef *def = (GroupDef *)((char *)tab + (i * 16 + tab->offset));
        struct vec *members;
        if (def->kind == 0xDA554856)
            g->side = 0;
        else if (def->kind == 0x750B5A10)
            g->side = 1;
        members = &g->members;
        ts4_vec_resize_8826B298(members, per);
        for (j = 0; j < per; j++) {
            int idx = *(int *)((char *)def + def->members_off + j * 4);
            Unit *u = (Unit *)(t->pool->units + idx * 0x3D0);
            Unit *s;
            t->units[idx] = u;
            s = t->units[idx];
            s->slot = j;
            s->group = g;
            u->index = idx;
            members->first[j] = (u32)s;
        }
    }
}
