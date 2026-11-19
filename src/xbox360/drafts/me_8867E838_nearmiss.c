/* NEAR MISS 0x8867E838: 13 off (LTCG route, ctx pp1_pool_primer): register numbering only (r3/r11 swapped around the sync reload). 7 variants. */
extern float lbl_8814B910; /* 0.5f */
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);

typedef struct RelSlot { int offset; int active; } RelSlot;  /* self-relative: target = (char*)slot + offset */
typedef struct Anim { char p[0x18]; unsigned int clip_hash; char q[0x10]; float blend; } Anim;
typedef struct Body { char p[0x44]; RelSlot slot; } Body;
typedef struct Holder { char p[0x28]; void *impl; } Holder;
typedef struct Sync { char p[0x410]; void *lead; char q[0x18]; int idx; char r[0x114]; void *partner; } Sync;
typedef struct Player { char p[0x5c]; Holder *h; } Player;
typedef struct Graphs { char p[0x224]; char g0[0x44]; char g1[4]; } Graphs;
typedef struct Phys { char p[0x3f0]; float t; } Phys;
typedef struct Ctx { char p[0x48]; Player *player; char p4[4]; Holder *self_h; char q[0xc]; Holder *sync_h; char r[0x10]; Phys *phys; } Ctx;
typedef struct State { void *vt; Ctx *ctx; char p[0xa0]; unsigned char late; } State;

/* 0x8867E838: enter state: start the 0x968230B3 clip at full blend, link the sync partner, reset graphs, latch timing. */
void ts4_state_enter_8867E838(State *s)
{
    RelSlot *slot = &((Body *)s->ctx->self_h->impl)->slot;
    Sync *sy;
    Holder *holder;
    void *lead;
    Graphs *g;
    float d;
    slot->active = 1;
    ((Anim *)((char *)slot + slot->offset))->clip_hash = 0x968230B3;
    ((Anim *)((char *)slot + slot->offset))->blend = 3.4028234663852886e+38f;
    lead = s->ctx->player->h->impl;
    holder = s->ctx->sync_h;
    ((Sync *)holder->impl)->partner = lead;
    sy = (Sync *)holder->impl;
    sy->idx = -1;
    sy->lead = lead;
    g = (Graphs *)s->ctx->self_h;
    ts4_loop_call_seq_u32_off2c_8890E988(g->g0);
    ts4_loop_call_seq_u32_off2c_8890E988(g->g1);
    d = lbl_8814B910 - s->ctx->phys->t;
    s->late = (unsigned char)(*(unsigned short *)&d >> 15);
}
