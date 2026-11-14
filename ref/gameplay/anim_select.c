/*
 * Swing animation selection reference.  See anim_select.h for the contract
 * and docs/gameplay/movement-and-animation.md for addresses and confidence.
 */
#include "anim_select.h"

#include <math.h>

static int leaf(const AsClip *c, int qtype, uint32_t want_mask, int exclusive)
{
    if (qtype < 0 || qtype >= AS_QUALIFIER_TYPES)
        return 0;
    uint32_t have = c->q[qtype];
    if (exclusive)
        return have != 0 && (have & ~want_mask) == 0;
    return have == 0 || (have & want_mask) != 0;
}

int as_eval(const AsNode *n, const AsClip *c, const uint32_t *keys)
{
    switch (n->kind) {
    case AS_NODE_EQUALS:
        return leaf(c, n->qtype, 1u << n->value, n->exclusive);
    case AS_NODE_MATCH_KEY:
        return leaf(c, n->qtype, 1u << keys[n->key], n->exclusive);
    case AS_NODE_MATCH_KEY_MASK:
        return leaf(c, n->qtype, keys[n->key], n->exclusive);
    case AS_NODE_ALL:
        for (int i = 0; i < n->nchildren; ++i)
            if (!as_eval(n->children[i], c, keys))
                return 0;
        return 1;
    case AS_NODE_ANY:
        for (int i = 0; i < n->nchildren; ++i)
            if (as_eval(n->children[i], c, keys))
                return 1;
        return 0;
    case AS_NODE_NOT:
        return n->nchildren > 0 && !as_eval(n->children[0], c, keys);
    }
    return 0;
}

static int key_ok(const AsClip *c, int qtype, int value)
{
    return value < 0 || leaf(c, qtype, 1u << value, 0);
}

int as_swing_matches(const AsClip *c, const AsSwingKeys *k)
{
    if (!(c->q[AS_Q_CATEGORY] & 1u))     /* Category value 0 = Swing */
        return 0;
    return key_ok(c, AS_Q_TIMING, k->timing) && key_ok(c, AS_Q_POWER, k->power) &&
           key_ok(c, AS_Q_CONTROL, k->control) && key_ok(c, AS_Q_MOVE_TO_NET, k->move_to_net) &&
           key_ok(c, AS_Q_POSITION_ON_COURT, k->position_on_court) &&
           key_ok(c, AS_Q_SWING_EFFECT, k->swing_effect) &&
           key_ok(c, AS_Q_SWING_TYPE, k->swing_type);
}

int as_mirror_mode(const AsClip *c, int left_handed, int reject_no_mirror)
{
    if (!left_handed)
        return 0;
    if (c->no_mirror)
        return reject_no_mirror ? -1 : 0;
    return 1;
}

static AsVec3 rot_xz(AsVec3 v, float s, float c)
{
    AsVec3 r = { v.x * c - v.z * s, v.y, v.x * s + v.z * c };
    return r;
}

float as_fit_cost(const AsFitCandidate *cd, const AsFitParams *p, AsVec3 *contact_out)
{
    /* Game form x' = x c - z s, z' = x s + z c with (s, c) = sincos(angle);
     * the game angle is -yaw in the left-positive yaw of locomotion.h (I). */
    float s = sinf(-p->facing_yaw), c = cosf(-p->facing_yaw);
    AsVec3 m = { cd->root_at_contact.x * p->scale, cd->root_at_contact.y * p->y_scale * p->scale,
                 cd->root_at_contact.z * p->scale };
    if (cd->side_matches)
        m = rot_xz(m, s, c);
    if (cd->has_offset) {
        AsVec3 o = { cd->offset.x * p->scale, cd->offset.y * p->y_scale * p->scale,
                     cd->offset.z * p->scale };
        o = rot_xz(o, s, c);
        m.x += o.x; m.y += o.y; m.z += o.z;
    }
    AsVec3 pos = { m.x + p->base.x, m.y + p->base.y, m.z + p->base.z };
    AsVec3 e = { pos.x - (p->target.x - p->ref.x), pos.y - (p->target.y - p->ref.y),
                 pos.z - (p->target.z - p->ref.z) };
    if (contact_out) {
        contact_out->x = pos.x + p->ref.x;
        contact_out->y = pos.y + p->ref.y;
        contact_out->z = pos.z + p->ref.z;
    }
    if (cd->contact_frame < p->t_min || cd->contact_frame > p->t_max)
        return -1.0f;
    if (fabsf(e.x) >= p->tol_x || fabsf(e.z) >= p->tol_z)
        return -1.0f;
    return e.x * e.x + e.y * e.y + e.z * e.z;
}

int as_fit_best(const AsFitCandidate *c, int n, const AsFitParams *p, float *best_cost)
{
    int best = -1;
    float bc = INFINITY;
    for (int i = 0; i < n; ++i) {
        float k = as_fit_cost(&c[i], p, 0);
        if (k >= 0.0f && k < bc) {
            bc = k;
            best = i;
        }
    }
    if (best_cost)
        *best_cost = bc;
    return best;
}

float as_contact_frame(const AsClip *c)
{
    return c->contact_phase < 0.0f ? -1.0f : c->contact_phase * c->frame_count;
}

void as_dive_defaults(AsDiveCfg *c)
{
    c->min_x = -600.0f;          /* pool+0x390 */
    c->a_min = 60.0f;            /* pool+0x15C */
    c->b_max = 45.0f;            /* pool+0x874 */
    c->forbidden_team_mode = 2;
}

int as_volley_spectacular(const AsDiveInputs *in, const AsDiveCfg *c)
{
    return in->pos_x > c->min_x && in->team_mode != c->forbidden_team_mode && in->ctx_flag &&
           in->has_spectacular_skill && in->timing_a > c->a_min && in->timing_b < c->b_max;
}

uint32_t as_rewards_from_props(uint32_t props, int trick_shot_bit)
{
    static const struct { int prop; uint32_t rw; } map[] = {
        { AS_PROP_SPECTACULAR, AS_RW_SPECTACULAR }, { AS_PROP_SWING_REACH, AS_RW_REACH },
        { AS_PROP_RUSHING, AS_RW_RUSHING }, { AS_PROP_POWERFUL_SHOT, AS_RW_POWERFUL },
        { AS_PROP_REFLEX_VOLLEY, AS_RW_REFLEX_VOLLEY }, { AS_PROP_SMASH, AS_RW_SMASH },
    };
    uint32_t out = 0;
    for (unsigned i = 0; i < sizeof map / sizeof map[0]; ++i)
        if (props & (1u << map[i].prop))
            out |= map[i].rw;
    if (trick_shot_bit >= 0 && trick_shot_bit < 32 && (props & (1u << trick_shot_bit)))
        out |= AS_RW_TRICK_SHOT;
    return out;
}

uint32_t as_reward_edges(uint32_t prev, uint32_t cur)
{
    return cur & ~prev;
}

int as_rushing_to_ball(float distance, float ratio, float d_min, float r_min)
{
    return distance > d_min && ratio > r_min;
}

int as_reach_allowed(const AsReachCfg *c, float contact_height, float target_distance)
{
    return contact_height >= c->h_min && contact_height <= c->h_max && target_distance >= c->min_dist;
}
