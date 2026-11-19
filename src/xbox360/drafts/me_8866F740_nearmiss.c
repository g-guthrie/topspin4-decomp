/* NEAR MISS fn_8866F740 Mover_PreHitFreeze: 51 instructions off, same size 0x2B0, /Oc plain route (was 138). */
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
 * byte-matched. 51 instructions off (2026-11-18, fn_check /Oc, TS4_MATCHING_DIR=work/matching-b105,
 * same size 0x2B0): self/pc get r31/r30 (target r30/r31); both move copies load both words before
 * storing (target stores the first word before loading the second and places the clrrwi later);
 * the zero constant load in the return-of-serve path is scheduled before the stb.
 */
#include "rt1_types.h"

extern const float g_ts4_event_value;         /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0x2AC: 0.1f */

ts4_bool ts4_next_hitter_planned_frame_8865EF98(struct Rt1MatchView *match, int *frame_out);

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

/* Bitwise move copy (field by field, as words). */
/* Bitwise move copy (both words at once). */
struct Rt1MoveWords { ts4_u32 dir; ts4_u32 power; };
static __inline void rt1_move_copy(struct Rt1Move *dst, const struct Rt1Move *src)
{
    *(struct Rt1MoveWords *)dst = *(const struct Rt1MoveWords *)src;
}

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
        if ((ts4_u32)flow->hitter_team != (ts4_u32)pc->team->team && ts4_next_hitter_planned_frame_8865EF98((struct Rt1MatchView *)pc->match, &frame))
            pc->state->move.frozen = (ts4_u32)(frame - flow->frame) < pc->world->settings->hit_lead_frames;
    }

    pc = self->pc;
    s = pc->state;
    if (s->move.frozen) {
        if (rt1_is_return_of_serve((const struct Ts4PlayerController *)pc)) {
            float zero = g_ts4_event_value;
            self->latched = 1;
            pc->state->move.latched.power = zero;
            self->pc->state->move.stick.power = zero;
            self->pc->state->move.required.power = zero;
            return;
        }
        if (!self->latched) {
            struct Rt1MoveBlock *m;
            self->latched = 1;
            m = &pc->state->move;
            rt1_move_copy(&m->required, &m->stick);
            rt1_move_copy(&self->pc->state->move.latched, &m->required);
            return;
        }
        {
            struct Rt1MatchM *match = self->pc->match;
            ts4_bool planned = ts4_next_hitter_planned_frame_8865EF98((struct Rt1MatchView *)match, &frame);
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
            rt1_move_copy(&s->move.stick, &s->move.latched);
            rt1_move_copy(&self->pc->state->move.required, &s->move.stick);
        }
    } else {
        self->released = 0;
        self->latched = 0;
    }
}
