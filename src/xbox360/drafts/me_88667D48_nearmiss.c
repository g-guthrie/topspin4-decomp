/* me_88667D48 near-miss: 96 off (LTCG + primer; most lines are base-register offsets). Shot stat counter: unless
   the shot ended or has id 0xC9238771, count it for its row (only when forced or the roster player's |lateral| is
   under 600), and as an own shot when row == player (also sets stats dirty); then bump record 0/1 bonus when the
   stats flags at +6/+0xe are set. Open: the target keeps sh = rally + 0x90 as a separate base (we fold it into the
   rally base; deriving sh from &ended keeps a base, but at the wrong offset) and addresses the flags with an extra
   addi. 8 variants. */
extern double fabs(double);
#pragma intrinsic(fabs)
typedef struct RelArr { int off; } RelArr;
typedef struct Body { char p[0xe10]; float lateral; } Body;
typedef struct PlayerCtx { char p[0x74]; Body *body; } PlayerCtx;
typedef struct Roster { char p[4]; PlayerCtx **players; char q[0x38]; char *tables; } Roster;  /* tables + 0x50: rel array of 16-byte rows, each a rel array of player indices */
typedef struct Rec { char p[0x5c]; int shots; int own_shots; char q[0xc4]; int bonus; char r[8]; } Rec;   /* 0x134 */
typedef struct Flag8 { char p[6]; unsigned char on; char q; } Flag8;
typedef struct Stats { char p[0xc]; RelArr flags; char q[0x21]; unsigned char dirty; char r[0x2a]; RelArr recs; } Stats;
typedef struct Shot { char p[9]; unsigned char ended; char q[0x36]; unsigned id; char r[4]; unsigned player; char s[0xc1]; unsigned char forced; char t[0x82]; unsigned row; unsigned col; } Shot;
typedef struct Rally { char p[0x90]; Shot shot; } Rally;
typedef struct Tracker { char p[0x20]; Rally *rally; char q[4]; Stats *stats; char r[8]; Roster *roster; } Tracker;
static __inline Rec *rec_at(Stats *s, unsigned i) { return (Rec *)((char *)&s->recs + (i * sizeof(Rec) + s->recs.off)); }
static __inline Flag8 *flags(Stats *s) { return (Flag8 *)((char *)&s->flags + s->flags.off); }

static __inline unsigned char near_center(Tracker *t, unsigned row, unsigned col)
{
    RelArr *tab = (RelArr *)(t->roster->tables + 0x50);
    RelArr *r = (RelArr *)((char *)tab + (row * 16 + tab->off));
    unsigned idx = *(unsigned *)((char *)r + (col * 4 + r->off));
    float d;
    d = t->roster->players[idx]->body->lateral;
    d = (float)fabs(d);
    d = d - 600.0f;
    return (unsigned char)(*(unsigned short *)&d >> 15);
}
void fn_88667D48(Tracker *t)
{
    Shot *sh = &t->rally->shot;
    if (!t->rally->shot.ended && sh->id != 0xC9238771u) {
        unsigned who = sh->player;
        unsigned row = sh->row;
        if (sh->forced || near_center(t, row, sh->col)) {
            rec_at(t->stats, row)->shots++;
            if (row == who) {
                rec_at(t->stats, who)->own_shots++;
                t->stats->dirty = 1;
            }
        }
    }
    if (flags(t->stats)[0].on) rec_at(t->stats, 0)->bonus++;
    if (flags(t->stats)[1].on) rec_at(t->stats, 1)->bonus++;
}
