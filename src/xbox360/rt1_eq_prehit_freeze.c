/*
 * RT1: Mover_PreHitFreeze (docs/gameplay/movement-and-ai.md E.4, symbols.md s4).
 *
 * In match play while the opponent is the next hitter, the freeze flag is set for the last
 * hit_lead_frames (20) frames before the opponent's planned hit. While frozen: a receiver of the
 * serve stands still; on the first frozen frame the stick move (#b21d6f76) is latched into
 * RequiredMove and the latched move (#3e07c540); afterwards, while more than release_frames (10)
 * remain, releasing the stick (RequiredMove.Power < 0.1 with a latched power > 0.1) stops the
 * player for the rest of the window; otherwise the latched move is forced.
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py; work/specs/RT1/rt1_eq_prehit_freeze.equiv.json). Not
 * byte-matched: the original copies the latched direction through `clrrwi rX,rY,0` (open idiom).
 */
#include "rt1_types.h"

extern const float g_ts4_event_value;         /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0x2AC: 0.1f */

ts4_bool fn_8865EF98(struct Rt1MatchView *match, int *frame_out);

/* Move pair {LocalDirection, Power}. */
struct Rt1Move {
    float local_direction;
    float power;
};
/* PlayerState MoveState.#5a7825cd (S+0x9D0). */
struct Rt1MoveBlock {
    struct Rt1Move required;               /* +0x00 (S+0x9D0) RequiredMove */
    struct Rt1Move stick;                  /* +0x08 (S+0x9D8) #b21d6f76 */
    struct Rt1Move constrained;            /* +0x10 (S+0x9E0) ConstrainedMove */
    struct Rt1Move latched;                /* +0x18 (S+0x9E8) #3e07c540 */
    ts4_bool frozen;                       /* +0x20 (S+0x9F0) #6964749b */
};
struct Rt1PlayerStateM {
    ts4_u8 pad_000[0x9D0];
    struct Rt1MoveBlock move;              /* +0x9D0 */
};
struct Rt1FreezeSettings {                 /* settings root (world +0x6C) */
    ts4_u8 pad_000[0xA88];
    ts4_u32 hit_lead_frames;               /* +0xA88 #98294782: 20 */
    ts4_u32 release_frames;                /* +0xA8C #5f4a986d: 10 */
};
struct Rt1WorldM { ts4_u8 pad_00[0x6C]; struct Rt1FreezeSettings *settings; /* +0x6C */ };
struct Rt1MatchFlowM {
    ts4_u8 pad_000[0x7C];
    int hitter_team;                       /* +0x07C team of the next hitter */
    ts4_u8 pad_080[0x290];
    int frame;                             /* +0x310 */
    ts4_u8 pad_314[0x14];
    ts4_u8 flag_328;                       /* +0x328 */
};
struct Rt1MatchM {
    ts4_u8 pad_00[0x30];
    struct Rt1MatchFlowM *flow;            /* +0x30 */
    ts4_u8 pad_34[0x44];
    struct Ts4MatchMode *mode;             /* +0x78 */
};
struct Rt1PlayerCtxM {
    ts4_u8 pad_00[0x44];
    struct Rt1WorldM *world;               /* +0x44 */
    struct Rt1MatchM *match;               /* +0x48 */
    struct Rt1TeamView *team;              /* +0x4C */
    ts4_u8 pad_50[0x24];
    struct Rt1PlayerStateM *state;         /* +0x74 */
};
struct Rt1PlanHolder { ts4_u8 pad_00[0x40]; int frames_to_hit; /* +0x40 own planned hit, frames */ };
struct Rt1PlanLink { ts4_u8 pad_00[0x70]; struct Rt1PlanHolder *plan; /* +0x70 */ };
struct Rt1Mover {                          /* locomotion mover */
    ts4_u8 pad_00[0x14];
    ts4_bool latched;                      /* +0x14 */
    ts4_bool released;                     /* +0x15 */
    ts4_u8 pad_16[2];
    struct Rt1PlayerCtxM *pc;              /* +0x18 */
    struct Rt1PlanLink *link;              /* +0x1C */
};

/* Swing_DLL.xex 0x8866F740 */
void ts4_mover_prehit_freeze_8866F740(struct Rt1Mover *self)
{
    struct Rt1PlayerCtxM *pc = self->pc;
    struct Rt1PlayerStateM *s;
    int frame;

    if (!pc->match->flow->flag_328)
        pc->state->move.frozen = 0;
    pc = self->pc;
    if (pc->match->mode->kind == 2) {
        struct Rt1MatchFlowM *flow = pc->match->flow;
        if (flow->hitter_team != pc->team->team && fn_8865EF98((struct Rt1MatchView *)pc->match, &frame))
            pc->state->move.frozen = (ts4_u32)(frame - flow->frame) < pc->world->settings->hit_lead_frames;
    }

    pc = self->pc;
    s = pc->state;
    if (!s->move.frozen) {
        self->released = 0;
        self->latched = 0;
        return;
    }
    if (rt1_is_return_of_serve((const struct Ts4PlayerController *)pc)) {
        float zero = g_ts4_event_value;
        self->latched = 1;
        pc->state->move.latched.power = zero;
        self->pc->state->move.stick.power = zero;
        self->pc->state->move.required.power = zero;
        return;
    }
    if (!self->latched) {
        struct Rt1MoveBlock *m = &pc->state->move;
        self->latched = 1;
        m->required = m->stick;
        self->pc->state->move.latched = m->required;
        return;
    }
    {
        struct Rt1MatchM *match = pc->match;
        ts4_bool planned = fn_8865EF98((struct Rt1MatchView *)match, &frame);
        ts4_bool known = 1;
        int hit;
        if (!planned) {
            int own = self->link->plan->frames_to_hit;
            hit = match->flow->frame + own;
            known = own != 0x7FFFFFFF;
        } else {
            hit = frame;
        }
        if (pc->world->settings->release_frames < (ts4_u32)(hit - match->flow->frame) && (planned || known)) {
            float lim = g_ts4_script_constants[0x2AC / 4];
            if (s->move.required.power < lim && s->move.latched.power > lim)
                self->released = 1;
        }
    }
    s = pc->state;
    if (self->released) {
        float zero = g_ts4_event_value;
        s->move.required.power = zero;
        self->pc->state->move.stick.power = zero;
        self->pc->state->move.latched.power = zero;
    } else {
        s->move.stick = s->move.latched;
        self->pc->state->move.required = s->move.stick;
    }
}
