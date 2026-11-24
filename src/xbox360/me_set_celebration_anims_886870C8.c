/* 0x886870C8 (hand match): once the game is won, set every player's celebration animation
 * set: players on the leading side (side 1 leads on ties) get the winner states, the others
 * the loser states; all get the common idle state, are flagged and restarted. */
typedef struct Side { char p[0xc]; int score; char p2[0x18 - 0x10]; } Side;
typedef struct Rel { int offset; } Rel;
typedef struct SideData { char p[0x24]; Rel sides; } SideData;
typedef struct Anim { char p[0x2fc]; unsigned int upper; unsigned int lower; unsigned int idle; char p1[0x318 - 0x308]; unsigned int body;
    char p2[0xfbc - 0x31c]; unsigned char restart; } Anim;
typedef struct Info { char p[0x28]; int side; } Info;
typedef struct Player { char p[0x4c]; Info *info; char p1[0x74 - 0x50]; Anim *anim; } Player;
typedef struct MatchSt { char p[0x93]; unsigned char game_won; } MatchSt;
typedef struct Ctx { char p[4]; Player **first; Player **last; char p1[0x30 - 0xc]; MatchSt *match; } Ctx;
typedef struct Obj { char p[4]; Ctx *ctx; SideData *data; } Obj;
void fn_8867AC60(Player *p);
static __inline Side *at(Rel *t, int i) { return (Side *)((char *)t + t->offset) + i; }
void ts4_set_celebration_anims_886870C8(Obj *o)
{
    Player **it, **end;
    int lead;
    if (!o->ctx->match->game_won)
        return;
    lead = at(&o->data->sides, 1)->score >= at(&o->data->sides, 0)->score;
    end = o->ctx->last;
    for (it = o->ctx->first; it != end; it++) {
        if (*it) {
            Anim *a = (*it)->anim;
            if ((*it)->info->side == lead) {
                a->body = 0x4A4FA42E;
                a->upper = 0xB388F633;
                a->lower = 0xB388F633;
                { unsigned int *ip = &a->idle; *ip = 0xC1DF4081; }
            } else {
                a->body = 0x87B1920F;
                a->upper = 0xD6FE8128;
                a->lower = 0xD6FE8128;
                { unsigned int *ip = &a->idle; *ip = 0xC1DF4081; }
            }
            (*it)->anim->restart = 1;
            fn_8867AC60(*it);
        }
    }
}
