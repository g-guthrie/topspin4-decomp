/* EQUIVALENT, not byte-matched: fn_8866F740 contains `clrrwi rX,rX,0` 64-bit-to-pointer idiom copies (known blocker,
 * docs/agents/codegen-idioms.md) and a 0x2B0-byte multi-branch body; see work/equiv/rt3_8866F740.json for the evidence.
 * Gameplay (docs/gameplay/movement-and-ai.md E.4): pre-hit freeze of the recovering player's movement.
 * Flags /Oc /fp:precise. */
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;

struct Rt3Cfg { char pad0[0xa88]; unsigned freeze_window; unsigned freeze_release_window; };   /* 20, 10 frames */
struct Rt3Cfg0 { char pad0[0x6c]; struct Rt3Cfg *cfg; };
struct Rt3Move {                      /* PlayerState (ctx+0x74) movement block */
    char pad0[0x9d0];
    float local_direction;            /* 0x9d0 */
    float power;                      /* 0x9d4 */
    float stick_direction;            /* 0x9d8 */
    float stick_power;                /* 0x9dc */
    char pad9e0[0x9e8 - 0x9e0];
    float latched_direction;          /* 0x9e8 */
    float latched_power;              /* 0x9ec */
    unsigned char freeze_active;      /* 0x9f0 */
};
struct Rt3Match { char pad0[0x7c]; void *next_hitter; char pad80[0xa8 - 0x80]; void *designated; char pad_ac[0x310 - 0xac]; unsigned clock; };
struct Rt3MatchSetup { char pad0[0x328]; unsigned char b328; unsigned char designated_player_flag; };
struct Rt3Match2 { char pad0[0x328]; unsigned char b328; unsigned char b329; unsigned char designated_flag; };
struct Rt3Team { char pad0[0x24]; struct { char pad0[0xb8]; void *slot; } *t24; void *id; };
struct Rt3WorldMode { int mode; };
struct Rt3World { char pad0[0x30]; struct Rt3Match2 *match; char pad34[0x78 - 0x34]; struct Rt3WorldMode *mode; };
struct Rt3Ctx {
    char pad0[0x18]; void *self_slot;
    char pad1c[0x44 - 0x1c]; struct Rt3Cfg0 *cfg0;
    struct Rt3World *world;
    struct Rt3Team *team;
    char pad50[0x74 - 0x50]; struct Rt3Move *move;
};
struct Rt3Clock { char pad0[0x40]; int frames; };
struct Rt3ClockHolder { char pad0[0x70]; struct Rt3Clock *clock; };
struct Rt3Freeze {
    char pad0[0x14];
    unsigned char latched;            /* 0x14 */
    unsigned char stopped;            /* 0x15 */
    char pad16[2];
    struct Rt3Ctx *ctx;               /* 0x18 */
    struct Rt3ClockHolder *clocks;    /* 0x1c */
};

unsigned char ts4_next_hitter_planned_frame_8865EF98(struct Rt3World *world, unsigned *planned_frame);

/* Swing_DLL.xex 0x8866F740: pre-hit freeze (rs_prehit_freeze): for the last cfg+0xA88 frames before the opponent's hit the
 * recovering player keeps the direction/power latched at window start; releasing the stick early stops him. */
void ts4_prehit_freeze_update_8866F740(struct Rt3Freeze *self)
{
    unsigned planned;
    struct Rt3Ctx *ctx = self->ctx;
    struct Rt3Move *mv;
    struct Rt3Match2 *m;
    unsigned char designated;
    unsigned char zero = 0;

    if (((struct Rt3Match2 *)((struct Rt3World *)ctx->world)->match)->b328 == 0)
        ((struct Rt3Move *)ctx->move)->freeze_active = zero;

    ctx = self->ctx;
    if (ctx->world->mode->mode == 2) {
        struct Rt3Match *match = (struct Rt3Match *)ctx->world->match;
        if (match->next_hitter != *(void **)((char *)ctx->team + 0x28)) {
            if (ts4_next_hitter_planned_frame_8865EF98(ctx->world, &planned))
                ctx->move->freeze_active = (unsigned)(planned - match->clock) < ctx->cfg0->cfg->freeze_window;
        }
    }

    ctx = self->ctx;
    mv = ctx->move;
    if (!mv->freeze_active) {
        self->stopped = 0;
        self->latched = 0;
        return;
    }
    m = ctx->world->match;
    designated = 0;
    if (m->designated_flag != 0 && ((struct Rt3Match *)m)->designated != *(void **)((char *)ctx->team + 0x28)
        && *(void **)((char *)ctx->team->t24 + 0xb8) == ctx->self_slot)
        designated = 1;
    if (designated) {
        self->latched = 1;
        ctx->move->latched_power = g_ts4_event_value;
        self->ctx->move->stick_power = g_ts4_event_value;
        self->ctx->move->power = g_ts4_event_value;
        return;
    }
    if (!self->latched) {
        self->latched = 1;
        mv->local_direction = mv->stick_direction;
        mv->power = mv->stick_power;
        self->ctx->move->latched_direction = mv->local_direction;
        self->ctx->move->latched_power = mv->power;
        return;
    } else {
        struct Rt3World *world = ctx->world;
        unsigned char ok = ts4_next_hitter_planned_frame_8865EF98(world, &planned);
        unsigned char forever = 1;
        unsigned frames_to_hit;
        if (!ok) {
            int clk = self->clocks->clock->frames;
            planned = ((struct Rt3Match *)world->match)->clock + clk;
            forever = (0x7fffffff - clk) != 0;
        }
        frames_to_hit = planned - ((struct Rt3Match *)world->match)->clock;
        if (ctx->cfg0->cfg->freeze_release_window < frames_to_hit && (ok || forever)) {
            float tenth = g_ts4_script_constants[0xab];
            if (mv->power < tenth && mv->latched_power > tenth)
                self->stopped = 1;
        }
        mv = ctx->move = ctx->move;
        if (self->stopped) {
            mv->power = g_ts4_event_value;
            self->ctx->move->stick_power = g_ts4_event_value;
            self->ctx->move->latched_power = g_ts4_event_value;
        } else {
            mv->stick_direction = mv->latched_direction;
            mv->stick_power = mv->latched_power;
            self->ctx->move->local_direction = mv->latched_direction;
            self->ctx->move->power = mv->stick_power;
        }
    }
}
