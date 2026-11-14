/*
 * Reference implementation of the Top Spin 4 controller-to-shot path.
 * See shot_select.h and docs/gameplay/controls-and-shot-selection.md.
 */
#include "shot_select.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint32_t ts4_crc32(const char *name)
{
    uint32_t c = 0xffffffffu;
    for (const unsigned char *p = (const unsigned char *)name; *p; ++p) {
        c ^= *p;
        for (int k = 0; k < 8; ++k)
            c = (c >> 1) ^ (0xedb88320u & (0u - (c & 1u)));
    }
    return ~c;
}

/* ------------------------------------------------------------------ tree */

static int parse_child(const char *tok, Ts4Child *c)
{
    memset(c, 0, sizeof *c);
    c->row = -1;
    if (tok[0] == 'n') {
        c->node = atoi(tok + 1);
        return 0;
    }
    if (tok[0] == 'l') {
        char *end;
        c->is_leaf = 1;
        c->shot_id = (uint32_t)strtoul(tok + 1, &end, 16);
        if (*end == ':')
            c->row = atoi(end + 1);
        return 0;
    }
    if (tok[0] == '-') { /* single-child node: never taken */
        c->is_leaf = 1;
        return 0;
    }
    return -1;
}

int ts4_shot_tree_parse(const char *text, Ts4ShotTree *tree)
{
    memset(tree, 0, sizeof *tree);
    const char *p = text;
    while (*p) {
        const char *eol = strchr(p, '\n');
        size_t len = eol ? (size_t)(eol - p) : strlen(p);
        char line[1024];
        if (len >= sizeof line)
            return -1;
        memcpy(line, p, len);
        line[len] = 0;
        p += len + (eol ? 1 : 0);
        if (line[0] == '#' || line[0] == 0)
            continue;
        char a[32], b[32], c[32], d[32];
        int idx;
        unsigned cond;
        float f[4];
        if (sscanf(line, "node %d %x %31s %31s", &idx, &cond, a, b) == 4) {
            if (idx < 0 || idx >= TS4_TREE_MAX_NODES || idx != tree->n_nodes)
                return -1;
            Ts4Node *n = &tree->nodes[idx];
            n->condition = cond;
            if (parse_child(a, &n->if_true) || parse_child(b, &n->if_false))
                return -1;
            tree->n_nodes++;
        } else if (sscanf(line, "power_curve %f %f %f %f", &f[0], &f[1], &f[2], &f[3]) == 4) {
            memcpy(tree->power_curve, f, sizeof f);
            tree->has_power_curve = 1;
        } else if (sscanf(line, "risk_curve %f %f %f %f", &f[0], &f[1], &f[2], &f[3]) == 4) {
            memcpy(tree->risk_curve, f, sizeof f);
            tree->has_risk_curve = 1;
        } else if (sscanf(line, "frequency %d", &idx) == 1) {
            if (idx <= 0)
                return -1;
            tree->frequency = idx;
        } else if (sscanf(line, "tier %15s %31s %31s", c, a, d) == 3) {
            if (tree->n_tiers >= TS4_TIER_MAX)
                return -1;
            Ts4Tier *t = &tree->tiers[tree->n_tiers++];
            size_t L = strlen(c); /* sscanf limited c to 15 chars */
            memcpy(t->name, c, L + 1);
            t->lo = strtof(a, NULL);
            t->hi = strtof(d, NULL);
        } else {
            return -1;
        }
    }
    /* every node reference must point inside the table */
    for (int i = 0; i < tree->n_nodes; ++i) {
        const Ts4Child *k[2] = {&tree->nodes[i].if_true, &tree->nodes[i].if_false};
        for (int j = 0; j < 2; ++j)
            if (!k[j]->is_leaf && (k[j]->node <= i || k[j]->node >= tree->n_nodes))
                return -1;
    }
    return tree->n_nodes > 0 ? 0 : -1;
}

int ts4_shot_tree_load(const char *path, Ts4ShotTree *tree)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return -1;
    static char buf[1 << 16];
    size_t n = fread(buf, 1, sizeof buf - 1, f);
    fclose(f);
    buf[n] = 0;
    return ts4_shot_tree_parse(buf, tree);
}

int ts4_condition_value(uint32_t condition, const Ts4Request *rq, const Ts4ShotContext *ctx)
{
    /* The data binds each node to an XData path; the condition id is crc32 of the
     * attribute name.  These are the 12 ids of the shipped tree. */
    switch (condition) {
    case 0x628ff1c4u: return rq->is_wood_down;      /* IsWoodDown      */
    case 0x9a0c0937u: return rq->is_wood;           /* IsWood          */
    case 0x0140379fu: return rq->is_classic_serve;  /* IsClassicServe  */
    case 0x7e04871fu: return rq->is_advanced_serve; /* IsAdvancedServe */
    case 0x79d86836u: return rq->is_smash;          /* IsSmash         */
    case 0x82747a4bu: return ctx->mode_baseline;    /* IsBaseLine -> Context/ShotContext/@ModeBaseLine */
    case 0xbc06cec7u: return rq->is_powerful;       /* IsPowerful      */
    case 0xfe6d2d3bu: return rq->is_medium;         /* IsMedium        */
    case 0xf271f3c8u: return rq->is_topspin;        /* IsTopSpin       */
    case 0xfb043007u: return rq->is_slice;          /* IsSlice         */
    case 0xd212c1efu: return rq->is_lob;            /* IsLob           */
    case 0xdf97c57bu: return rq->is_risk;           /* IsRisk          */
    case 0xf3dbba7eu: return rq->is_flat;           /* IsFlat (unused) */
    default: return 0;                              /* unbound: byte stays 0 */
    }
}

int ts4_shot_select(const Ts4ShotTree *tree, const Ts4Request *rq, const Ts4ShotContext *ctx,
                    Ts4ShotChoice *out)
{
    memset(out, 0, sizeof *out);
    int i = 0;
    for (int guard = 0; guard < TS4_TREE_MAX_NODES; ++guard) {
        if (i < 0 || i >= tree->n_nodes)
            return -1;
        const Ts4Node *n = &tree->nodes[i];
        out->path[out->path_len++] = i;
        const Ts4Child *c = ts4_condition_value(n->condition, rq, ctx) == 1 ? &n->if_true : &n->if_false;
        if (c->is_leaf) {
            out->row_id = c->shot_id;
            out->row = c->row;
            /* fn_8868F178 tail: the two drop rows rename the current shot "DropShot" */
            out->shot_id = (c->shot_id == TS4_ID_DROPSHOTNORMAL || c->shot_id == TS4_ID_DROPVOLLEY)
                               ? TS4_ID_DROPSHOT : 0;
            return c->shot_id ? 0 : -1;
        }
        i = c->node;
    }
    return -1;
}

/* ------------------------------------------------------------------ input */

int ts4_button_level(int slot, uint8_t value, int invert)
{
    /* fn_8890DB90 +0x34..+0x44: subfic r11,r9,0x80 for slots 6/7 */
    int down = (slot == TS4_PAD_LT || slot == TS4_PAD_RT) ? (value > 0x80) : (value != 0);
    return invert ? !down : down;
}

uint32_t ts4_latch_update(uint32_t *latched, const uint8_t abxy[4], int *released)
{
    static const uint32_t ids[4] = {TS4_ID_FLAT, TS4_ID_TOPSPIN, TS4_ID_SLICE, TS4_ID_LOB};
    *released = 0;
    if (*latched == 0) {
        for (int i = 0; i < 4; ++i)
            if (abxy[i]) {
                *latched = ids[i];
                break;
            }
    }
    if (*latched) {
        for (int i = 0; i < 4; ++i)
            if (ids[i] == *latched && !abxy[i])
                *released = 1; /* InputState +0xCE ("Raise"); the latch is cleared by the reset */
    }
    return *latched;
}

Ts4Request ts4_build_request(const Ts4RequestInput *in, uint32_t *shot_id_out)
{
    Ts4Request r;
    memset(&r, 0, sizeof r); /* fn_8868F178 clears +0x400..+0x40B */
    uint32_t id = in->overhead ? TS4_ID_SMASH : in->stroke_id;
    r.is_flat = id == TS4_ID_FLAT;
    r.is_slice = id == TS4_ID_SLICE;
    r.is_topspin = id == TS4_ID_TOPSPIN;
    r.is_lob = id == TS4_ID_LOB;
    r.is_smash = id == TS4_ID_SMASH;
    r.is_risk = (uint8_t)(in->risk != 0);
    /* fn_886783B0: IsPowerful/IsMedium copied from SwingSelection.Request.Power */
    r.is_powerful = (uint8_t)(in->tier_powerful != 0);
    r.is_medium = (uint8_t)(in->tier_medium != 0);
    r.is_classic_serve = (uint8_t)(in->classic_serve != 0);
    r.is_advanced_serve = (uint8_t)(in->advanced_serve != 0);
    r.is_wood = (uint8_t)(in->wood != 0);
    r.is_wood_down = (uint8_t)(in->wood_down != 0);
    if (shot_id_out)
        *shot_id_out = id;
    return r;
}

/* ------------------------------------------------------------------ power */

float ts4_curve16(const float k[4], float x)
{
    float span = k[1] - k[0];
    float d = x - k[0];
    if (!(d >= 0.0f)) /* fsel on an unordered compare also gives 0 */
        d = 0.0f;
    if (d - span >= 0.0f)
        d = span;
    return k[2] + (d / span) * (k[3] - k[2]);
}

float ts4_power(const Ts4ShotTree *tree, int frames, int divisor)
{
    if (divisor == 0)
        divisor = tree->frequency;
    if (!tree->has_power_curve || divisor == 0)
        return 0.0f;
    return ts4_curve16(tree->power_curve, (float)frames / (float)divisor);
}

void ts4_charge_start(Ts4Charge *c)
{
    c->frames = 0;      /* fn_88698538: FrameCount = 0, Value = 0 */
    c->latched = 1;     /* PC+0x58D */
    c->committed = 0;   /* PC+0x58C */
}

int ts4_charge_update(Ts4Charge *c, int released, int frames_to_contact, int lead_frames)
{
    if (c->committed || !c->latched)
        return c->committed;
    /* the per-frame power read (fn_8869D720) runs before the state machine, so the
     * frame of the release still counts */
    c->frames++;
    if (released || ts4_swing_now(1, frames_to_contact, lead_frames))
        c->committed = 1;
    return c->committed;
}

int ts4_swing_now(int valid, int frames_to_contact, int lead_frames)
{
    return valid && frames_to_contact <= lead_frames;
}

/* ------------------------------------------------------------------ serve */

Ts4Request ts4_serve_request(const Ts4ServeInput *in)
{
    Ts4Request r;
    memset(&r, 0, sizeof r);
    r.is_flat = (uint8_t)(in->throw_flat != 0);
    r.is_slice = (uint8_t)(in->throw_slice != 0);
    r.is_topspin = (uint8_t)(in->throw_topspin != 0);
    float p = in->press_and_hold;
    r.is_powerful = (uint8_t)(p > 0.8f);                    /* g_ts4_script_constants+0x110 */
    r.is_medium = (uint8_t)(!(p < 0.1f) && !r.is_powerful); /* +0x2AC */
    r.is_classic_serve = (uint8_t)(in->classic_throw != 0);
    r.is_advanced_serve = (uint8_t)(in->advanced_throw != 0 || in->motion_device != 0);
    return r;
}

float ts4_serve_power(int release, int toss_start, int toss_len, int released)
{
    if (!released || toss_len <= 0)
        return 1.0f;
    float v = (float)(release - toss_start) / (float)toss_len;
    return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v);
}

float ts4_serve_timing(const float (*keys)[4], int n, float frames, int released)
{
    if (!released || n <= 0)
        return 1.0f;
    int k = 0;
    for (int i = 0; i < n; ++i)
        if (keys[i][0] <= frames)
            k = i;
    return ts4_curve16(keys[k], frames);
}

/* ------------------------------------------------------------------ wood */

int ts4_wood_check(int armed, float t)
{
    return armed && (t >= 0.1f || t <= -0.1f);
}

int ts4_wood_down(float target[3], const float ref[3], int is_wood)
{
    if (target[0] < 0.0f)
        target[0] = target[0] < -50.0f ? target[0] : -50.0f; /* +0x570 = -50 */
    else
        target[0] = target[0] > 50.0f ? target[0] : 50.0f;   /* +0xF0 = 50 */
    if (!(target[0] < 0.0f) || is_wood)
        return 0;
    float dx = target[0] - ref[0], dy = target[1] - ref[1], dz = target[2] - ref[2];
    return dx * dx + dy * dy + dz * dz < 640000.0f;          /* +0x7EC */
}

/* ------------------------------------------------------------------ sticks */

Ts4Stick ts4_stick_channel(int16_t raw_x, int16_t raw_y, float dz, int inv_x, int inv_y)
{
    Ts4Stick s = {0.0f, 0.0f, 0.0f, 0.0f};
    float x = (float)raw_x, y = (float)raw_y;
    if (inv_x)
        x = -x;
    if (inv_y)
        y = -y;
    float mag = sqrtf(x * x + y * y);
    if (mag <= dz * 32767.0f) /* const 0x880023EC = 32767 */
        return s;
    float m = mag * (1.0f / 32767.0f);
    if (m > 1.0f)
        m = 1.0f;
    float out = (m - dz) / (1.0f - dz);
    s.x = out * x / mag;
    s.y = out * y / mag;
    s.mag = out;
    s.angle = atan2f(x, y); /* fn_88564BF8(f1 = x, f2 = y) */
    return s;
}

void ts4_stick_cartesian(const Ts4Stick *s, const float scale[2], float out[2])
{
    out[0] = s->x * scale[0];
    out[1] = s->y * scale[1];
}

void ts4_stick_polar(const Ts4Stick *s, const float ar[2], const float pr[2], float out[2])
{
    float u = s->angle * 0.159154943f + 0.5f; /* g_ts4_script_constants+0x1B8 = 1/(2 pi) */
    out[0] = pr[0] + (pr[1] - pr[0]) * s->mag;
    out[1] = ar[0] + (ar[1] - ar[0]) * u;
}

int ts4_lt_forced_commit(int lt, float power, float angle, int alt, int mirrored)
{
    const float pi = 3.14159265f;
    if (!lt || !(power > 0.2f)) /* g_ts4_script_constants+0x10C */
        return 0;
    if (mirrored)
        angle += pi;
    float d = angle - (alt ? 4.712389f : 1.5707964f); /* +0x774 / +0xE8 */
    while (d > pi)
        d -= 2.0f * pi;
    while (d < -pi)
        d += 2.0f * pi;
    return fabsf(d) < 0.8727f; /* +0x778 */
}

void ts4_tier_flags(const Ts4ShotTree *tree, float power, int out[3])
{
    static const char *names[3] = {"Finesse", "Medium", "Powerful"};
    for (int i = 0; i < 3; ++i) {
        out[i] = 0;
        for (int t = 0; t < tree->n_tiers; ++t) {
            const Ts4Tier *k = &tree->tiers[t];
            /* graph CURVE key [lo, hi): output 1 inside, so "> 0.5" is true there.  The
             * last key of a curve stays clamped at its end, so the top tier extends past hi. */
            int last = 1;
            for (int u = 0; u < tree->n_tiers; ++u)
                if (strcmp(tree->tiers[u].name, k->name) == 0 && tree->tiers[u].lo > k->lo)
                    last = 0;
            if (strcmp(k->name, names[i]) == 0 && power >= k->lo &&
                (power < k->hi || (last && k->hi >= 1.0f)))
                out[i] = 1;
        }
    }
}

/* ------------------------------------------------------------------ aim */

static float wrap_pi(float a)
{
    const float pi = 3.14159265f;
    while (a > pi)
        a -= 2.0f * pi;
    while (a < -pi)
        a += 2.0f * pi;
    return a;
}

Ts4Aim ts4_aim_from_stick(float move_x, float move_y, int mirrored_side)
{
    Ts4Aim a;
    float vx = move_y, vz = -move_x; /* (S+0x44C, 0, -S+0x448) */
    float mag = sqrtf(vx * vx + vz * vz);
    if (!(mag >= 0.0f))
        mag = 0.0f;
    a.depth = mag > 1.0f ? 1.0f : mag;
    a.angle = wrap_pi(atan2f(vx, vz) + (mirrored_side ? 3.14159265f : 0.0f));
    return a;
}

Ts4Aim ts4_aim_auto(const float player_xz[2], const float target_xz[2], const float ball30_xz[2])
{
    Ts4Aim a = {0.0f, 0.0f};
    float dx = target_xz[0] - ball30_xz[0], dz = target_xz[1] - ball30_xz[1];
    if (sqrtf(dx * dx + dz * dz) > 30.0f) { /* g_ts4_script_constants+0x42C = 30.0 */
        float vx = target_xz[0] - player_xz[0], vz = target_xz[1] - player_xz[1];
        a.depth = 1.0f;
        a.angle = -atan2f(vx, vz);
    }
    return a;
}
