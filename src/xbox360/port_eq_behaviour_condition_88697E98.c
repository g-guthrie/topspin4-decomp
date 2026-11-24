/* NEAR MISS fn_88697E98 behaviour condition evaluator (hash switch): size 0x66C vs target 0x6A0, 365 off, 31 relocs (same),
 * LTCG + pp1_pool_primer.c, /Oc. Behaviour: EQUIVALENT under fn_equiv seed 1, 3000 trials, 2688 valid, 82/83 blocks, using a
 * scratch copy of tools/fn_equiv.py (sha256 755e11c2bbd9fae1...) whose code_consts also seeds 32-bit lis/ori constants;
 * the stock checker reaches 28% coverage (the hash is read from memory) and reports UNCHECKED.
 * Remaining: the target does not CSE repeated pc->state / self->pc loads (two lwz 0x74 in one case, a reload of self->pc
 * plus "mr"/"clrrwi rX,rX,0" copies), which looks like accessors inlined across modules by LTCG after CSE; ours shares them. */
/* Swing_DLL.xex 0x88697E98: evaluate one player behaviour condition, selected by its name hash. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern const float g_ts4_event_value;   /* 0.0f; +0x4D0 0.5f */
#define CE_HALF (((const float *)&g_ts4_event_value)[0x4D0 / 4])
extern char lbl_880D0934[];      /* float threshold */
ts4_u8 fn_8866B6E0(void *self);
ts4_u8 fn_8868F0D8(void *pc, void *data);

#define CE_SIGN(d) (*(unsigned short *)&(d) >> 15)
#define CE_NEG(d) (*(unsigned short *)&(d) & 0x8000)

struct Ts4CeState {
    ts4_u8 pad_000[0x388]; ts4_u8 b388; ts4_u8 pad_389[0x4E0 - 0x389]; ts4_u8 b4e0;
    ts4_u8 pad_4e1[0x544 - 0x4E1]; float f544; ts4_u8 pad_548[0x5DB - 0x548]; ts4_u8 b5db; ts4_u8 pad_5dc; ts4_u8 b5dd;
    ts4_u8 pad_5de; ts4_u8 b5df; ts4_u8 pad_5e0[0x7B8 - 0x5E0]; float f7b8; ts4_u8 pad_7bc[0x7CC - 0x7BC]; float f7cc;
    ts4_u8 pad_7d0[4]; float f7d4; ts4_u8 pad_7d8[0x8E0 - 0x7D8]; float pos_x; ts4_u8 pad_8e4[0xA5C - 0x8E4]; float fa5c;
    ts4_u8 pad_a60[0xABC - 0xA60]; float fabc; ts4_u8 pad_ac0[0xD08 - 0xAC0]; float fd08; ts4_u8 pad_d0c[0xE00 - 0xD0C]; float fe00;
};
struct Ts4CeBall {
    ts4_u8 pad_000[0x1B0]; float f1b0; float f1b4; ts4_u8 pad_1b8[0x5BC - 0x1B8]; float f5bc;
    ts4_u8 pad_5c0[4]; float f5c4; float f5c8;
};
struct Ts4CeTeam { ts4_u8 pad_00[0x2C]; int size; };
struct Ts4CePC {
    ts4_u8 pad_00[0x10]; ts4_u8 b10; ts4_u8 pad_11[0x1B]; struct Ts4CeBall *ball; ts4_u8 pad_30[0xC]; ts4_u32 style;
    ts4_u8 pad_40[0xC]; struct Ts4CeTeam *team; ts4_u8 pad_50[0x24]; struct Ts4CeState *state;
};
struct Ts4CeSelf { ts4_u8 pad_00[0x1C]; struct Ts4CePC *pc; ts4_u8 pad_20[0x1D]; ts4_u8 b3d; };
struct Ts4CeCond { ts4_u8 pad_00[0x8]; ts4_u32 hash; ts4_u8 data[4]; };

static const float kZero = 0.0f;
static __inline float ce_min(float a, float b) { return (a - b >= kZero) ? b : a; }

static __forceinline float ce_min_st(struct Ts4CeState *st)
{
    float a = st->fa5c;
    float b = st->fabc;
    return ce_min(a, b);
}
static __forceinline ts4_u8 ce_within(struct Ts4CeSelf *self)
{
    struct Ts4CePC *pc = self->pc;
    float d = pc->ball->f5c8 - pc->state->f544;
    if (CE_NEG(d)) {
        float e = pc->state->f544 - pc->ball->f5c4;
        if (CE_NEG(e))
            return 1;
    }
    return 0;
}

ts4_u8 ts4_behaviour_condition_88697E98(struct Ts4CeSelf *self, struct Ts4CeCond *c)
{
    ts4_u8 r = 0;
    switch (c->hash) {
    case 0x1DE220E2u:
        r = self->pc->state->b388;
        break;
    case 0x07F0DF25u:
        r = self->pc->state->f7d4 > CE_HALF;
        break;
    case 0x28D4D485u: {
        float d = CE_HALF - self->pc->state->f7b8;
        r = (ts4_u8)CE_SIGN(d);
        break;
    }
    case 0x4041760Au: {
        struct Ts4CePC *pc = self->pc;
        float a = pc->ball->f5bc - pc->state->f544;
        ts4_u8 sa = (ts4_u8)CE_SIGN(a);
        float b = pc->state->f7cc - CE_HALF;
        r = sa && CE_SIGN(b);
        break;
    }
    case 0x42864090u: {
        struct Ts4CePC *pc = self->pc;
        ts4_u8 near = pc->ball->f1b4 < ce_min_st(pc->state);
        ts4_u8 in = ce_within(self);
        r = near && !in;
        break;
    }
    case 0x60D5B606u: {
        struct Ts4CePC *pc = self->pc;
        r = pc->ball->f1b4 < ce_min_st(pc->state);
        break;
    }
    case 0x693616C3u: {
        struct Ts4CePC *pc = self->pc;
        r = pc->ball->f1b0 < ce_min_st(pc->state);
        break;
    }
    case 0x7D633A62u: {
        struct Ts4CePC *pc = self->pc;
        float px = pc->state->pos_x;
        float x = px + (pc->team->size == 2 ? 600.0f : 450.0f);
        ts4_u8 s = (ts4_u8)CE_SIGN(x);
        ts4_u8 other = (pc->style == 0xFC6F57A1u || pc->style == 0x990377A5u) ? 0 : 1;
        r = s && other;
        break;
    }
    case 0x7E522D55u:
        r = self->b3d && fn_8866B6E0(self);
        break;
    case 0x990377A5u:
        r = self->pc->style == 0x990377A5u;
        break;
    case 0xBD8EA388u:
        r = self->pc->state->b5db;
        break;
    case 0xC42EF3FEu:
        r = fn_8868F0D8(self->pc, c->data);
        break;
    case 0xC78C8F06u: {
        struct Ts4CePC *pc = self->pc;
        ts4_u8 busy = (!pc->b10 && pc->state->b4e0) ? 1 : 0;
        ts4_u8 act = (self->b3d && fn_8866B6E0(self)) ? 1 : 0;
        ts4_u8 hi = pc->state->fe00 > *(float *)lbl_880D0934;
        r = !busy && !act && hi;
        break;
    }
    case 0xD00AC582u: {
        float d = self->pc->ball->f5bc - self->pc->state->fd08;
        r = (ts4_u8)CE_SIGN(d);
        break;
    }
    case 0xDE050FD0u: {
        struct Ts4CePC *pc = self->pc;
        ts4_u8 near = pc->ball->f1b0 < ce_min_st(pc->state);
        ts4_u8 in = ce_within(self);
        r = near && (!pc->b10 || in);
        break;
    }
    case 0xDE102FECu: {
        float d = CE_HALF - self->pc->state->f7b8;
        r = (ts4_u8)(~CE_SIGN(d) & 1);
        break;
    }
    case 0xFE98362Eu: {
        struct Ts4CeState *st = self->pc->state;
        r = st->b5dd || st->b5df;
        break;
    }
    }
    return r;
}
