#include "w6a_types.h"

typedef struct W6aCtx8d0 {
    unsigned char pad00[0x8d0];
    int type;                           /* +0x8d0 */
    unsigned char pad8d4[0x8e0 - 0x8d4];
    __vector4 pos;                      /* +0x8e0 */
    unsigned char pad8f0[0xf04 - 0x8f0];
    float f;                            /* +0xf04 */
} W6aCtx8d0;

typedef struct W6aOutSub {
    Vx1Vec vec;                         /* +0x00 */
    float a;                            /* +0x10 */
    float b;                            /* +0x14 */
    float c;                            /* +0x18 */
} W6aOutSub;

typedef struct W6aOut10 {
    unsigned char pad00[0x10];
    W6aOutSub sub;                      /* +0x10 */
} W6aOut10;

void ts4_fill_flip_vector_886605C0(W6aOut10 *out, W6aCtx8d0 *ctx)
{
    W6aOutSub *sub = &out->sub;
    Vx1Vec t;
    float f;
    t.v = ctx->pos;
    if (ctx->type == (int)0xa2eda1e7u) {
        vx1_vec_set_x(&t, -vx1_vec_x(&t));
        vx1_vec_set_z(&t, -vx1_vec_z(&t));
    }
    sub->vec = t;
    f = ctx->f;
    sub->a = f;
    sub->b = f * 5.0f;
    sub->c = 1.0f / (sub->b - f);
}

typedef struct W6aCfg5c {
    unsigned char pad00[0x20];
    char *data;                         /* +0x20 */
} W6aCfg5c;

typedef struct W6aNode48 {
    unsigned char pad00[0x5c];
    W6aCfg5c *cfg;                      /* +0x5c */
    unsigned char pad60[0x78 - 0x60];
    int *mode;                          /* +0x78 */
} W6aNode48;

typedef struct W6aActor1068 {
    unsigned char pad00[0x8d0];
    int type;                           /* +0x8d0 */
    unsigned char pad8d4[0x1068 - 0x8d4];
    unsigned int id;                    /* +0x1068 */
} W6aActor1068;

typedef struct W6aMode4c {
    unsigned char pad00[0x2c];
    int kind;                           /* +0x2c */
    unsigned char pad30[0x74 - 0x30];
    W6aActor1068 *actor;                /* +0x74 */
} W6aMode4c;

typedef struct W6aHost1c {
    unsigned char pad00[0x48];
    W6aNode48 *node;                    /* +0x48 */
    W6aMode4c *mode;                    /* +0x4c */
    unsigned char pad50[0x74 - 0x50];
    W6aActor1068 *actor;                /* +0x74 */
} W6aHost1c;

typedef struct W6aSelf1c {
    unsigned char pad00[0x1c];
    W6aHost1c *host;                    /* +0x1c */
} W6aSelf1c;

extern const float g_ts4_event_value;

void ts4_pick_swing_id_8866CA00(W6aSelf1c *self)
{
    Vx1Vec t;
    int flag;
    t.v = *(__vector4 *)(self->host->node->cfg->data + 0x40);
    if (self->host->actor->type == (int)0xa2eda1e7u) {
        vx1_vec_set_x(&t, -vx1_vec_x(&t));
        vx1_vec_set_z(&t, -vx1_vec_z(&t));
    }
    flag = vx1_vec_x(&t) < g_ts4_event_value;
    if (self->host->mode->kind == 2) {
        if ((unsigned char)flag)
            self->host->actor->id = 0xbf5d35b1u;
        else
            self->host->actor->id = 0xa4aac6d8u;
    } else if (*self->host->node->mode == 1 && (unsigned char)flag) {
        self->host->actor->id = 0xd32429a6u;
    } else {
        self->host->actor->id = 0xa4aac6d8u;
    }
}
