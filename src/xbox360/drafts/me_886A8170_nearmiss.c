/* near miss 0x886A8170 (ME agent B): 189 off on /Oc (plain and LTCG). Control flow and calls right;
 * residue: frame 0xa0 vs 0xb0 (target gives each hash its own stack slot 0x58..0x6c), r26/r28 and r30/r31
 * swapped for self/result and ctl/player, and the clrrwi copy lands on team->kind instead of the team pointer.
 * Function: decides whether the serve/umpire cue for the current match phase must be posted, posts it via
 * fn_886A5718 and returns 1 when posted. */
typedef unsigned char U8;
typedef unsigned int U32;
typedef struct Ctl Ctl;
typedef struct Match { char p[0x7c]; int round; char p80[0x310 - 0x80]; int phase; char p314[0x328 - 0x314]; U8 locked; U8 p329; U8 allow_cue; } Match;
typedef struct Rules { char p[0x88]; U8 serve_check; char p89[3]; int server; } Rules;
typedef struct Flags48 { char p[8]; U8 busy; } Flags48;
typedef struct Cue { char p[0x2c]; U32 kind; char p30[0xb0 - 0x30]; int phase_b0; char pb4[0xb8 - 0xb4]; int phase_b8; char pbc[0xd8 - 0xbc];
    int phase_d8; char pdc[0xe0 - 0xdc]; int arg; char pe4[0xe8 - 0xe4]; char tail[4]; } Cue;
typedef struct CueOwner { char p[0x20]; Cue *cue; } CueOwner;
typedef struct Player { char p[0x30]; Match *match; char p34[0x44 - 0x34]; Rules *rules; Flags48 *f48; char p4c[0x5c - 0x4c]; CueOwner *cues; } Player;
typedef struct Team { char p[0x10]; Ctl **members; char p14[0x28 - 0x14]; int round; int kind; } Team;
typedef struct Status { char p[0x14]; U8 down; } Status;
struct Ctl { char p[0x14]; int id; int side; char p1c[0x48 - 0x1c]; Player *player; Team *team; char p50[0x84 - 0x50]; Status *status; };
typedef struct Owner { char p[0x1c]; Ctl *ctl; } Owner;
typedef struct CuePair { char *tail; Player *player; } CuePair;
U8 ts4_find_scheduled_frame_8866E250(Player *pl, int *frame);
U32 ts4_if_get_u32_off0_8867BB18(CuePair *p);
void fn_886A5718(Ctl *c, U32 *hash, int arg);
static __inline Team *team_of(Team *t) { return t; }
static __inline Ctl *peer(Ctl *c, Team *t)
{
    if (team_of(t)->kind == 2)
        return team_of(t)->members[c->side == 0];
    return c;
}
int fn_886A8170(Owner *self)
{
    Ctl *c = self->ctl;
    Player *pl = c->player;
    U8 posted = 0;
    U8 serve;
    Player *p27;
    Cue *cue;
    CuePair pair;
    if (pl->match->locked)
        return posted;
    {
        int frame = 0;
        if (ts4_find_scheduled_frame_8866E250(pl, &frame))
            return 1;
    }
    if (pl->f48->busy)
        return 1;
    if (self->ctl->player->match->round != self->ctl->team->round)
        return 0;
    serve = 0;
    if (pl->rules->serve_check) {
        int server = self->ctl->player->rules->server;
        serve = server == self->ctl->id;
        if (c->team->kind == 2)
            serve |= server == peer(c, c->team)->id;
    }
    p27 = self->ctl->player;
    pair.player = p27;
    cue = p27->cues->cue;
    pair.tail = cue->tail;
    if (serve && !c->status->down) {
        Ctl *o = c;
        posted = 1;
        if (c->team->kind == 2) {
            o = peer(c, c->team);
            posted = o->status->down == 0;
        }
        if (posted) {
            { U32 h1 = 0x79EE9B03; fn_886A5718(self->ctl, &h1, self->ctl->player->match->phase); }
        }
    }
    if (!posted && p27->match->phase == cue->phase_d8 && self->ctl->player->match->allow_cue) {
        U8 alt = cue->kind == 0x02315629;
        if (cue->kind == 0x8F903DFB) {
            posted = 1;
            { U32 h2 = 0xC9238771; fn_886A5718(self->ctl, &h2, cue->arg); }
        }
        if (alt) {
            posted = 1;
            { U32 h3 = 0x5E11F1A7; fn_886A5718(self->ctl, &h3, cue->arg); }
        }
    }
    if (posted)
        return posted;
    if (p27->match->phase == cue->phase_b0) {
        { U32 h4 = 0x5E11F1A7; fn_886A5718(self->ctl, &h4, self->ctl->player->match->phase); }
        return 1;
    }
    if (ts4_if_get_u32_off0_8867BB18(&pair)) {
        { U32 h5 = 0xC222A5E0; fn_886A5718(self->ctl, &h5, self->ctl->player->match->phase); }
        return 1;
    }
    if (p27->match->phase == cue->phase_b8) {
        { U32 h6 = 0x7DDEC718; fn_886A5718(self->ctl, &h6, self->ctl->player->match->phase); }
        return 1;
    }
    return posted;
}
