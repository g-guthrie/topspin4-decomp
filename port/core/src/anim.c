/*
 * ts4core: animation selection state (what a renderer needs to drive the game's Havok clips).
 *
 * Data: the ANIM section (clip catalogue, anim groups/subgroups, move sets, transition rules and matrix) built from
 * data/gameplay/animation_rules.yaml (G6, docs/gameplay/movement-and-animation.md). Decoded parts used here:
 *   - move-set sectors (8 directions + stand, relative to the facing; lo_sector8 of ref/gameplay/locomotion.c),
 *   - the transition matrix subgroup -> subgroup -> rule, rule blend frames and vivacity speeds,
 *   - the play rate formula (lo_play_rate), the swing time scaling to the EventRacket contact frame (gp7),
 *   - swing qualifiers (Category, PositionOnCourt, SwingType, SwingEffect, SwingCategory, Properties),
 *   - the dive volley (VolleySpectacular) trigger of fn_886BCE88,
 *   - the swing-category rule walk with the Fatality put-away gate (src/swingcat.c, G6b) and the exact
 *     match_key filter of ref/gameplay/anim_select.c (an unconstrained clip passes any set key).
 * Port policy (not decoded): which clip of a subgroup plays (the selection-procedure DSL needs gameplay keys the
 * core does not model: first clip), the clip-fit cost (needs Havok root motion: replaced by the smallest time
 * scaling), the per-clip speed coefficient (1.0), and the male clip set only.
 */
#include <math.h>
#include <string.h>

#include "ts4_internal.h"

#define PI_F 3.14159265f

static const uint8_t *A(const Ts4Core *c) { return c->ext.anim; }
static int16_t le16s(const uint8_t *p) { return (int16_t)(p[0] | (p[1] << 8)); }
static uint32_t le16(const uint8_t *p) { return (uint32_t)(p[0] | (p[1] << 8)); }
static const uint8_t *clip_at(const Ts4Core *c, int32_t i) { return A(c) + c->ext.an_clips + c->ext.an_stride * (uint32_t)i; }
static const uint8_t *group_at(const Ts4Core *c, int32_t g) { return A(c) + c->ext.an_groups + 16u * (uint32_t)g; }
static const uint8_t *sub_at(const Ts4Core *c, int32_t s) { return A(c) + c->ext.an_subs + 12u * (uint32_t)s; }

int32_t ts4_anim_ready(const Ts4Core *c) { return c->ext.anim && c->ext.an_nclips > 0; }

/* qualifier slot of a global type index, -1 when the clip table does not carry it */
static int qslot_of_type(const Ts4Core *c, uint32_t qtype)
{
    uint32_t i;
    for (i = 0; i < c->ext.an_nq; i++)
        if (ts4_le32(A(c) + c->ext.an_q + 4 * i) == qtype) return (int)i;
    return -1;
}

/* (slot, value index) of a qualifier given by names; slot -1 when unknown */
static int qlookup(const Ts4Core *c, const char *type, const char *value, int *vidx)
{
    uint32_t th = ts4_crc32(type), vh = ts4_crc32(value), i;
    for (i = 0; i < c->ext.an_nqv; i++) {
        const uint8_t *q = A(c) + c->ext.an_qv + 12 * i;
        if (ts4_le32(q) == th && ts4_le32(q + 4) == vh) { *vidx = q[9]; return q[8]; }
    }
    return -1;
}

static int clip_has(const Ts4Core *c, int32_t clip, int slot, int vidx)
{
    if (clip < 0 || slot < 0 || vidx < 0 || vidx > 31) return 0;
    return (ts4_le32(clip_at(c, clip) + 20 + 4 * (uint32_t)slot) >> vidx) & 1u;
}

float ts4_anim_qual(const Ts4Core *c, int player, uint32_t qtype, uint32_t qvalue)
{
    const Ts4AnimState *s = &c->pl[player].anim;
    int slot;
    if (!ts4_anim_ready(c) || s->layer != TS4_ANIM_SWING) return 0.0f;
    slot = qslot_of_type(c, qtype);
    return clip_has(c, s->clip, slot, (int)qvalue) ? 1.0f : 0.0f;
}

void ts4_anim_reset(Ts4Core *c, int player)
{
    Ts4AnimState *s = &c->pl[player].anim;
    memset(s, 0, sizeof *s);
    s->clip = s->prev_clip = -1;
    s->group = s->sub = -1;
    s->moveset = -1;
    s->contact_frame = -1.0f;
    (void)c;
}

static int32_t moveset_find(const Ts4Core *c, const char *name)
{
    uint32_t h = ts4_crc32(name), i;
    for (i = 0; i < c->ext.an_nms; i++)
        if (ts4_le32(A(c) + c->ext.an_ms + 12 * i) == h) return (int32_t)i;
    return -1;
}

/* lo_sector8 (ref/gameplay/locomotion.c) without fmodf/floorf: 0 front, 1 front-left .. 7 front-right, 8 stand */
static int sector8(float facing_yaw, float dx, float dz, float dead_sq)
{
    float a;
    int s;
    if (dx * dx + dz * dz <= dead_sq) return 8;
    a = atan2f(dx, dz) - facing_yaw;
    while (a < 0.0f) a += 2.0f * PI_F;
    while (a >= 2.0f * PI_F) a -= 2.0f * PI_F;
    s = (int)(a / (PI_F / 4.0f) + 0.5f);
    return s & 7;
}

/* transition rule from the current subgroup to `to_sub`: blend frames (anim.blend_frames when no cell) */
static float blend_frames(const Ts4Core *c, int32_t from_sub, int32_t to_sub, float *speed)
{
    float bf = TUN_HAS(c, ANIM_BLEND_FRAMES) ? TUN(c, ANIM_BLEND_FRAMES) : 15.0f;
    *speed = 1.0f;
    if (from_sub >= 0 && (uint32_t)from_sub < c->ext.an_msize) {
        const uint8_t *row = A(c) + c->ext.an_mat + 8u * (uint32_t)from_sub;
        uint32_t n = ts4_le32(row), off = ts4_le32(row + 4), i;
        for (i = 0; i < n; i++) {
            const uint8_t *cell = A(c) + off + 4 * i;
            if (le16s(cell) == to_sub) {
                int32_t r = le16s(cell + 2);
                if (r >= 0 && (uint32_t)r < c->ext.an_nrules) {
                    const uint8_t *ru = A(c) + c->ext.an_rules + 24u * (uint32_t)r;
                    bf = ts4_lef32(ru + 16);
                    *speed = ts4_lef32(ru + 12);   /* HighVivacitySpeedCoef (vivacity not modelled: high) */
                }
                break;
            }
        }
    }
    return bf;
}

static void play(Ts4Core *c, Ts4AnimState *s, uint32_t layer, int32_t clip, float frame0, float rate)
{
    float spd = 1.0f;
    const uint8_t *cl;
    int32_t sub;
    if (clip == s->clip && layer == s->layer) { s->rate = rate; return; }
    cl = clip_at(c, clip);
    sub = le16s(cl + 10);
    if (s->clip >= 0) {
        s->prev_clip = s->clip;
        s->prev_frame = s->frame;
        s->prev_rate = s->rate;
        s->blend_len = blend_frames(c, s->sub, sub, &spd);
        s->blend_t = 0.0f;
    }
    s->layer = layer;
    s->clip = clip;
    s->frame = frame0;
    s->rate = rate * (spd > 0.0f ? spd : 1.0f);
    s->group = le16s(cl + 8);
    s->sub = sub;
}

static int32_t sector_clip(const Ts4Core *c, int32_t ms, int sector, float *frames, uint32_t *allow)
{
    const uint8_t *m = A(c) + c->ext.an_ms + 12u * (uint32_t)ms;
    uint32_t n = ts4_le32(m + 4), off = ts4_le32(m + 8);
    int16_t g, sb;
    int32_t clip;
    if (!n) return -1;
    if ((uint32_t)sector >= n) sector = (n > 8) ? 8 : 0;
    g = le16s(A(c) + off + 4 * (uint32_t)sector);
    sb = le16s(A(c) + off + 4 * (uint32_t)sector + 2);
    if (g < 0 || (uint32_t)g >= c->ext.an_ngroups) return -1;
    if (sb >= 0 && (uint32_t)sb < c->ext.an_nsubs && le16(sub_at(c, sb) + 8)) clip = (int32_t)le16(sub_at(c, sb) + 6);
    else clip = (int32_t)le16(group_at(c, g) + 4);
    if ((uint32_t)clip >= c->ext.an_nclips) return -1;
    *frames = ts4_lef32(clip_at(c, clip) + 4);
    *allow = group_at(c, g)[12];
    return clip;
}

/* match_key leaf of ref/gameplay/anim_select.c (updated G6b rules): an unset key (vidx < 0) passes; an
 * unconstrained clip (no bit of the type set) passes any key; else the key bit must be present. */
static int key_ok(const Ts4Core *c, int32_t clip, int slot, int vidx)
{
    uint32_t have;
    /* match_key (332e57c4, ref anim_select.c leaf_key): vidx -1 = key not part of this query; -2 = key unset, which
     * wants an unconstrained clip; a set key passes an unconstrained clip or one carrying the bit */
    if (vidx == -1) return 1;
    if (slot < 0 || vidx > 31) return vidx == -2;
    have = ts4_le32(clip_at(c, clip) + 20 + 4 * (uint32_t)slot);
    if (vidx == -2) return have == 0;
    return have == 0 || ((have >> vidx) & 1u);
}

typedef struct SwingQuery {
    const Ts4Core *c;
    int s_cat, v_swing, slot[5], vidx[5];   /* PositionOnCourt, SwingType, SwingEffect, MoveToNet, Properties(dive) */
    int s_scat, s_pref, dive_slot, dive_v, dive;
    float want;                              /* contact frame wanted at rate 1 */
    const uint32_t *occ;
    int32_t best;
} SwingQuery;

static int swing_ok(const SwingQuery *q, int32_t i)
{
    const uint8_t *cl = clip_at(q->c, i);
    int k;
    if (!clip_has(q->c, i, q->s_cat, q->v_swing)) return 0;          /* as_swing_matches: Category = Swing */
    if (ts4_lef32(cl + 12) < 0.0f || ts4_lef32(cl + 4) <= 0.0f) return 0;
    for (k = 0; k < 4; k++) if (!key_ok(q->c, i, q->slot[k], q->vidx[k])) return 0;
    if (q->dive_slot >= 0 && q->dive_v >= 0 && q->dive != clip_has(q->c, i, q->dive_slot, q->dive_v)) return 0;
    return 1;
}

/* the clip query of one (SwingCategory, SwingPreferenceLevel): 0 = a clip starts (best time scaling kept), -1 none */
static int swing_query(void *user, uint32_t category, uint32_t level)
{
    SwingQuery *q = (SwingQuery *)user;
    const Ts4Core *c = q->c;
    char lv[2] = {0, 0};
    int v_cat = -1, v_lvl = -1, s_cat = -1, s_lvl, k;
    uint32_t i;
    float best_cost = 1e30f;
    q->best = -1;
    for (i = 0; i < c->ext.an_nqv; i++) {   /* value index of the category hash */
        const uint8_t *e = A(c) + c->ext.an_qv + 12 * i;
        if (ts4_le32(e) == ts4_crc32("SwingCategory") && ts4_le32(e + 4) == category) { s_cat = e[8]; v_cat = e[9]; }
    }
    if (s_cat < 0) return -1;
    lv[0] = (char)('0' + (int)level);
    s_lvl = qlookup(c, "SwingPreferenceLevel", lv, &v_lvl);
    for (i = 0; i < c->ext.an_nclips; i++) {
        const uint8_t *cl = clip_at(c, (int32_t)i);
        float cost;
        if (!swing_ok(q, (int32_t)i) || !clip_has(c, (int32_t)i, s_cat, v_cat)) continue;
        if (s_lvl >= 0 && !key_ok(c, (int32_t)i, s_lvl, v_lvl)) continue;
        cost = fabsf(ts4_lef32(cl + 12) * ts4_lef32(cl + 4) - q->want);   /* policy fit: least time scaling */
        for (k = 0; k < 8; k++) if (q->occ[k] == ts4_le32(cl) && cl[17] == 1) cost += 1000.0f;
        if (cost < best_cost) { best_cost = cost; q->best = (int32_t)i; }
    }
    return q->best >= 0 ? 0 : -1;
}

void ts4_anim_swing(Ts4Core *c, int player, uint32_t stroke, int volley, int smash, int forehand, int is_return,
                    int32_t ticks_to_contact)
{
    Ts4SimPlayer *p = &c->pl[player];
    Ts4AnimState *s = &p->anim;
    SwingQuery q;
    Ts4ScInputs in;
    uint32_t shot_id, category = 0;
    int started = 0, cls, v_move = -1;
    float gcoef = TUN_HAS(c, ANIM_SPEED_COEF) ? TUN(c, ANIM_SPEED_COEF) : 1.0f;
    if (!ts4_anim_ready(c)) return;
    memset(&q, 0, sizeof q);
    q.c = c;
    q.best = -1;
    q.occ = s->occ;
    q.want = (float)ticks_to_contact * gcoef;
    shot_id = ts4_crc32(smash ? "Smash" : (stroke & TS4_BTN_LOB) ? "Lob" :
                        ((stroke & TS4_BTN_SLICE) && (stroke & TS4_BTN_RISK)) ? "DropShot" :
                        (stroke & TS4_BTN_SLICE) ? "Slice" : (stroke & TS4_BTN_TOPSPIN) ? "TopSpin" : "Flat");
    q.s_cat = qlookup(c, "Category", "Swing", &q.v_swing);
    q.slot[0] = qlookup(c, "PositionOnCourt", is_return ? "Return Serve" : (volley ? "Volley" : "Baseline"), &q.vidx[0]);
    q.slot[1] = qlookup(c, "SwingType", forehand ? "FH" : "BH", &q.vidx[1]);
    q.slot[2] = qlookup(c, "SwingEffect", smash ? "Smash" : (stroke & TS4_BTN_LOB) ? "Lob" :
                        ((stroke & TS4_BTN_SLICE) && (stroke & TS4_BTN_RISK)) ? "DropShot" : (stroke & TS4_BTN_SLICE) ? "Slice" :
                        (stroke & TS4_BTN_TOPSPIN) ? "TopSpin" : "Flat", &q.vidx[2]);
    q.slot[3] = qlookup(c, "MoveToNet", "Yes", &v_move);
    q.vidx[3] = (p->in.buttons & TS4_BTN_SPRINT) ? v_move : -2;     /* MoveToNet set when following to the net, else unset */
    if (q.slot[3] < 0) q.vidx[3] = -1;
    q.dive_slot = qlookup(c, "Properties", "Spectacular", &q.dive_v);
    /* dive volley (fn_886BCE88, G6): local x, singles, skill SpectacularVolleys, two TimingState thresholds */
    if (volley && c->ext.skil) {
        uint32_t k, n = ts4_le32(c->ext.skil);
        int has = 0;
        for (k = 0; k < n && k < 32; k++)
            if (ts4_le32(c->ext.skil + 4 + 4 * k) == 0x1E8D4F10u && ((c->extra[player].skill_mask >> k) & 1u)) has = 1;
        q.dive = has && PS_GET(p, 0x8E0) > TUN(c, DIVE_X_MIN) && PS_GET(p, 0xD00) > TUN(c, DIVE_D00_MIN) &&
                 PS_GET(p, 0xCF0) < TUN(c, DIVE_CF0_MAX);
    }
    /* swing category walk (fn_886AFDF8, G6b): writes S+0x360, Fatality = put-away gate */
    memset(&in, 0, sizeof in);
    in.is_human = p->setup.human != 0;
    in.sticky_rb = (p->in.buttons & TS4_BTN_SPRINT) != 0;
    in.in_net_zone = (p->pos[2] < 300.0f && p->pos[2] > -300.0f);
    in.power = PS_GET(p, 0xE00);
    in.perfect_eval = PS_GET(p, 0x7D4);
    in.volley_release = PS_GET(p, 0x7B8);
    in.slow_down = PS_GET(p, 0x7CC);
    in.manual_timing = PS_GET(p, 0x544);
    in.timing_value = PS_GET(p, 0xD08);
    in.min_speed_left = PS_GET(p, 0xA5C);
    in.min_speed_right = PS_GET(p, 0xABC);
    in.volley_spectacular = q.dive;
    in.is_fast_ball = PS_GET(p, 0x5DD) != 0.0f;   /* byte flags read as words: zero unless written */
    in.is_inside_out = p->inside_out != 0;
    in.shot_id = shot_id;
    in.local_x = PS_GET(p, 0x8E0);
    in.skill_ok = 1;
    cls = ts4_sc_class(volley, smash, shot_id, PS_GET(p, 0x3D4) > 0.5f);
    if (c->ext.scat) category = ts4_sc_walk(c, cls, &in, swing_query, &q, &started);
    if (category) __builtin_memcpy(p->ps + 0x360, &category, 4);
    if (!started) {
        /* no row started a clip (or no SCAT): any category, relaxed keys, least time scaling (policy) */
        uint32_t i;
        float best_cost = 1e30f;
        q.best = -1;
        for (i = 0; i < c->ext.an_nclips; i++) {
            const uint8_t *cl = clip_at(c, (int32_t)i);
            float cost;
            int k;
            if (!clip_has(c, (int32_t)i, q.s_cat, q.v_swing) || !key_ok(c, (int32_t)i, q.slot[1], q.vidx[1])) continue;
            if (ts4_lef32(cl + 12) < 0.0f || ts4_lef32(cl + 4) <= 0.0f) continue;
            cost = fabsf(ts4_lef32(cl + 12) * ts4_lef32(cl + 4) - q.want);
            for (k = 0; k < 4; k++) if (k != 1 && !key_ok(c, (int32_t)i, q.slot[k], q.vidx[k])) cost += 10000.0f;
            if (cost < best_cost) { best_cost = cost; q.best = (int32_t)i; }
        }
    }
    if (q.best < 0) return;
    {
        const uint8_t *cl = clip_at(c, q.best);
        float cf = ts4_lef32(cl + 12) * ts4_lef32(cl + 4);
        /* the contact frame lands on the contact tick (gp7 time scaling): play at the global rate from the frame
         * that leaves exactly ticks_to_contact, scaling only when the clip is too short for that (policy) */
        float f0 = cf - (float)ticks_to_contact * gcoef, rate;
        if (f0 < 0.0f) f0 = 0.0f;
        rate = ticks_to_contact > 0 ? (cf - f0) / (float)ticks_to_contact : gcoef;
        memmove(&s->occ[1], &s->occ[0], 7 * sizeof s->occ[0]);
        s->occ[0] = ts4_le32(cl);
        play(c, s, TS4_ANIM_SWING, q.best, f0, rate);
        s->contact_frame = cf;
        s->moveset = -1;
    }
}

void ts4_anim_tick(Ts4Core *c, int player)
{
    Ts4SimPlayer *p = &c->pl[player];
    Ts4AnimState *s = &p->anim;
    float gcoef = TUN_HAS(c, ANIM_SPEED_COEF) ? TUN(c, ANIM_SPEED_COEF) : 1.0f;
    if (!ts4_anim_ready(c)) return;
    /* advance */
    if (s->clip >= 0) {
        float frames = ts4_lef32(clip_at(c, s->clip) + 4);
        s->frame += s->rate;
        if (s->layer == TS4_ANIM_SWING || s->layer == TS4_ANIM_SERVE) {
            if (s->frame >= frames) { s->frame = frames; if (p->swing_state == 0) s->layer = TS4_ANIM_IDLE; }
        } else if (frames > 0.0f) {
            while (s->frame >= frames) s->frame -= frames;
        }
    }
    if (s->prev_clip >= 0) {
        s->prev_frame += s->prev_rate;
        s->blend_t += 1.0f;
        if (s->blend_t >= s->blend_len) { s->prev_clip = -1; s->blend_len = 0.0f; }
    }
    /* choose the locomotion / idle / serve clip when no swing is playing */
    if ((s->layer == TS4_ANIM_SWING || s->layer == TS4_ANIM_SERVE) && s->clip >= 0 &&
        s->frame < ts4_lef32(clip_at(c, s->clip) + 4))
        return;
    {
        float vx = p->vel[0], vz = p->vel[2], sp = sqrtf(vx * vx + vz * vz), frames = 0.0f;
        float osign = p->pos[0] < 0.0f ? -1.0f : 1.0f, yaw = -osign * (PI_F * 0.5f);
        uint32_t allow = 0, layer;
        int32_t ms, clip;
        const char *name;
        int sector;
        if (c->phase == TS4_PHASE_SERVE && c->server == player && p->toss_tick >= 0) { name = "BaselineServeSwing"; layer = TS4_ANIM_SERVE; }
        else if (sp > 1.0f) { name = (p->planner.state == MV_RUSH) ? "Rush" : "Jog"; layer = TS4_ANIM_MOVE; }
        else if (c->phase == TS4_PHASE_SERVE && c->server == player) { name = "MovesServe"; layer = TS4_ANIM_IDLE; }
        else { name = "BeforeMatch"; layer = TS4_ANIM_IDLE; }
        ms = moveset_find(c, name);
        if (ms < 0) return;
        sector = (layer == TS4_ANIM_MOVE) ? sector8(yaw, vx, vz, 1.0f) : 0;
        clip = sector_clip(c, ms, sector, &frames, &allow);
        if (clip < 0) return;
        {
            float ref = TUN(c, MOVE_SPEED_JOG), gp = (layer == TS4_ANIM_MOVE && ref > 0.0f) ? sp / ref : 1.0f;
            uint8_t isc = clip_at(c, clip)[16];
            float rate = gcoef * ((allow && !isc) ? gp : 1.0f);   /* lo_play_rate, clip speed coef 1 */
            play(c, s, layer, clip, 0.0f, rate);
            s->moveset = ms;
            s->contact_frame = -1.0f;
        }
    }
}

int32_t ts4_anim_view(const Ts4Core *c, uint32_t player, Ts4AnimView *out)
{
    const Ts4AnimState *s;
    if (!c || c->magic != TS4_MAGIC || player > 1 || !out || out->struct_size < sizeof(Ts4AnimView)) return TS4_ERR_ARG;
    memset(out, 0, sizeof *out);
    out->struct_size = sizeof(Ts4AnimView);
    out->clip = out->prev_clip = -1;
    out->group = out->subgroup = -1;
    out->contact_frame = -1.0f;
    out->blend = 1.0f;
    if (!ts4_anim_ready(c)) return TS4_ERR_MISSING_DATA;
    if (!c->started) return TS4_ERR_NOT_STARTED;
    s = &c->pl[player].anim;
    out->layer = s->layer;
    out->clip = s->clip;
    out->frame = s->frame;
    out->rate = s->rate;
    out->group = s->group;
    out->subgroup = s->sub;
    out->contact_frame = s->contact_frame;
    out->mirrored = c->pl[player].setup.left_handed ? 1u : 0u;
    if (s->clip >= 0) out->clip_hash = ts4_le32(clip_at(c, s->clip));
    if (s->prev_clip >= 0 && s->blend_len > 0.0f) {
        out->prev_clip = s->prev_clip;
        out->prev_hash = ts4_le32(clip_at(c, s->prev_clip));
        out->prev_frame = s->prev_frame;
        out->blend = s->blend_t / s->blend_len > 1.0f ? 1.0f : s->blend_t / s->blend_len;   /* lo_blend_weight */
    }
    return TS4_OK;
}

uint32_t ts4_anim_view_size(void) { return (uint32_t)sizeof(Ts4AnimView); }
