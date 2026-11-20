/* 0x886AC7E0: unless the player's character is the 0x85E3E155 kind or the selector is locked, selects
 * each id of the relative-offset id table in turn and queries its cost; keeps the smallest cost that is
 * not -1 and stops at a zero cost. On a zero cost it clears the "ready" flag on this side's panel and,
 * in doubles (mode 2), on the partner's panel too. Returns the chosen cost (-1 when none). */
typedef struct Rel { volatile int offset; unsigned int count; } Rel;
typedef struct Data { char p[0x5b0]; Rel ids; } Data;
typedef struct Sel { char p[0x380]; int id; char p2[0xfbc - 0x384]; unsigned char locked; } Sel;
typedef struct Panel { char p[0x8c]; unsigned char ready; } Panel;
typedef struct Character { char p[0x318]; unsigned int kind; } Character;
typedef struct Body { char p[0x30]; Character *character; } Body;
struct Obj;
typedef struct Team { char p[0x10]; struct Obj **members; char p2[0x2c - 0x14]; int mode; } Team;
typedef struct Obj {
    char p[0x18]; int side; char p1[0x2c - 0x1c]; Data *data; char p2[0x48 - 0x30]; Body *body; Team *team;
    char p3[0x60 - 0x50]; void *query; char p4[0x74 - 0x64]; Sel *sel; char p5[0x80 - 0x78]; Panel *panel;
} Obj;
int fn_886DAA48(void *q, int a, int b, int c);
static __forceinline int *ibegin(Rel *t) { int *r = 0; int off = t->offset; if (off != -1) r = (int *)((char *)t + off); return r; }
static __forceinline int *iend(Rel *t) { int *r = 0; int off = t->offset; if (off != -1) r = (int *)((char *)t + (t->count * 4 + off)); return r; }
int ts4_min_cost_until_zero_886AC7E0(Obj *o, int a, int b)
{
    int best = -1;
    if (o->body->character->kind != 0x85E3E155 && !o->sel->locked) {
        Rel *t = &o->data->ids;
        int *end = iend(t);
        int *it;
        for (it = ibegin(t); it != end; it++) {
            int r;
            if (best == 0) break;
            o->sel->id = *it;
            r = fn_886DAA48(o->query, a, b, 0);
            if (r == 0) { best = 0; break; }
            else if (r != -1) { if (best == -1) best = r; else if (r < best) best = r; }
        }
        if (best == 0) {
            Team *tm;
            o->panel->ready = 0;
            tm = o->team;
            if (tm->mode == 2) tm->members[o->side == 0]->panel->ready = 0;
        }
    }
    return best;
}
