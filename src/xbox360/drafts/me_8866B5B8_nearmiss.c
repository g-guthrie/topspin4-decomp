/* NEAR MISS 0x8866B5B8: 19 off (0x124 vs 0x128): target reloads self->ctx after the reach compare (we reuse it), keeps the bool unextended until its test, and ends with li 0/li 1 + clrlwi. 6 variants. */
#include "vx1_vector.h"

typedef struct Court { char p[0x5c0]; float baseline; } Court;
typedef struct BallState {
    char p[0x5d9]; unsigned char f5d9, f5da; char q[2]; unsigned char f5dd, f5de, f5df;
    char r[0x8d0 - 0x5e0]; int side_hash; char s[0xc]; Vx1Vec anchor;
} BallState;
typedef struct Body { char p[0x5e0]; Vx1Vec pos; } Body;
typedef struct Model { char p[0x24]; Body *body; } Model;
typedef struct Player { char p[0x5c]; Model *model; } Player;
typedef struct Ctx { char p[0x2c]; Court *court; char q[0x18]; Player *player; char r[0x28]; BallState *ball; } Ctx;
typedef struct Limits { char p[0x2c8]; float reach; } Limits;
typedef struct Check { char p[0x1c]; Ctx *ctx; Limits *limits; } Check;

/* 0x8866B5B8: true when the shot is out of play for this side: player past the anchor, court beyond reach, or any blocking flag. */
unsigned char ts4_check_out_of_play_8866B5B8(Check *c)
{
    Ctx *ctx = c->ctx;
    unsigned char behind = ctx->court->baseline < c->limits->reach;
    Ctx *cx = c->ctx;
    Vx1Vec pos;
    BallState *b;
    float d;
    pos.v = cx->player->model->body->pos.v;
    if (cx->ball->side_hash == (int)0xA2EDA1E7) {
        vx1_vec_set_x(&pos, -vx1_vec_x(&pos));
        vx1_vec_set_z(&pos, -vx1_vec_z(&pos));
    }
    b = ctx->ball;
    {
        Vx1Vec a;
        a.v = b->anchor.v;
        d = vx1_vec_x(&a) - vx1_vec_x(&pos);
    }
    {
        unsigned char r;
        if ((unsigned char)(*(unsigned short *)&d >> 15) || behind || b->f5da || b->f5d9 || b->f5dd || b->f5de)
            r = 1;
        else
            r = b->f5df != 0;
        return r;
    }
}
