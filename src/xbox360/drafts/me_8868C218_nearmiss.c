/* agP 2026-11-19: pointer locals for at_net_depth / pc->state (no volatile): 3 off both routes; volatile version stays 2. */
/* agentA2 2026-11-18: still 2 (LTCG): lim=0 init then assign, block-local d with lim=-d, pc copy local; volatile lim 78. */
/* NEAR MISS fn_8868C218 repositioning behaviour switch: 2 off (same size 0x17C), LTCG + pp1_pool_primer.c, /Oc.
 * Volatile reads of at_net_depth and of r->pc->state fix the load order (was 3 off); the target still schedules
 * the fneg before the state-pointer lwz, ours after. Behaviour unchanged by the volatile casts. */
/* Swing_DLL.xex 0x8868C218: switch the repositioning behaviour (0 base, 2 net rush) and raise its one-shot flag. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef struct { float v[4]; } Ts4V4;
#include "../ts4_vector.h"

extern const float g_ts4_script_constants[];
void ts4_loop_call_seq_u32_off2c_8890E988(void *list);

struct Ts4BhState {
    ts4_u8 pad_000[0x39C]; float speed_39c;
    ts4_u8 pad_3a0[0x540]; ts4_u8 req_fast_repos_dummy[0];
};
struct Ts4BhPS {
    ts4_u8 pad_000[0x39C]; float speed_39c;
    ts4_u8 pad_3a0[0x4E2 - 0x3A0]; ts4_u8 req_fast_repos;
    ts4_u8 pad_4e3[0x8E0 - 0x4E3]; __vector4 local_position;
    ts4_u8 pad_8f0[0xFA0 - 0x8F0]; ts4_u8 flag_fa0; ts4_u8 flag_fa1;
    ts4_u8 pad_fa2[0xFBD - 0xFA2]; ts4_u8 flag_fbd;
};
struct Ts4BhAnim { ts4_u8 pad_000[0x41C]; float speed; };
struct Ts4BhSettings { ts4_u8 pad_000[0xA68]; float rush_delay; ts4_u8 pad_a6c[8]; float at_net_depth; };
struct Ts4BhWorld { ts4_u8 pad_00[0x6C]; struct Ts4BhSettings *settings; };
struct Ts4BhFlow { ts4_u8 pad_000[0x310]; int frame; };
struct Ts4BhMatch { ts4_u8 pad_00[0x30]; struct Ts4BhFlow *flow; };
struct Ts4BhPC {
    ts4_u8 pad_00[0x44]; struct Ts4BhWorld *world; struct Ts4BhMatch *match;
    ts4_u8 pad_4c[0x28]; struct Ts4BhPS *state; struct Ts4BhAnim *anim;
};
struct Ts4BhRepos {
    ts4_u8 pad_000[0x1C]; struct Ts4BhPC *pc;
    ts4_u8 pad_020[0x24]; int behaviour; ts4_u32 behaviour_frame;
    ts4_u8 pad_04c[0xDC]; ts4_u8 list_128[4];
};

void ts4_repositioning_set_behaviour_8868C218(struct Ts4BhRepos *r, int mode)
{
    struct Ts4BhPC *pc = r->pc;
    struct Ts4BhSettings *set;
    ts4_u8 rb;
    int b;
    ts4_u8 due;
    ts4_u8 at_net;
    __vector4 pos;

    {
        struct Ts4BhWorld *world = pc->world;
        rb = pc->state->req_fast_repos;
        pc->anim->speed = g_ts4_script_constants[0];
        set = world->settings;
    }
    {
        float lim = -*(volatile float *)&set->at_net_depth;
        pos = (*(struct Ts4BhPS *volatile *)&r->pc->state)->local_position;
        at_net = pos.v[0] > lim;
    }
    if (at_net) {
        b = 0;
        if (rb) {
            ts4_loop_call_seq_u32_off2c_8890E988(r->list_128);
            r->pc->anim->speed = r->pc->state->speed_39c;
        }
    } else {
        b = (mode == 2) ? 2 : 0;
    }
    pc = r->pc;
    due = set->rush_delay + (float)r->behaviour_frame < (float)pc->match->flow->frame;
    if (r->behaviour != b && due) {
        if (b == 0)
            pc->state->flag_fa0 = 1;
        else if (b == 1)
            pc->state->flag_fa1 = 1;
        else if (b == 2)
            pc->state->flag_fbd = 1;
        r->behaviour = b;
        r->behaviour_frame = r->pc->match->flow->frame;
    }
}
