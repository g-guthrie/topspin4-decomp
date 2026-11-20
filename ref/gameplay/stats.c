/*
 * Reference implementation: player stat block, curve evaluation and the
 * data-flow graph runtime that turns stats into gameplay quantities.
 *
 * Source: Swing_DLL.xex (see docs/gameplay/stats-swing-clipfit.md, part A).
 * Clean-room: structure and arithmetic only; no data tables, no tunables.
 */
#include "gp_swing.h"

/* ---- name hash --------------------------------------------------------- */

uint32_t gp_crc32(const char *name)
{
    uint32_t crc = 0xFFFFFFFFu;

    for (; *name; ++name) {
        crc ^= (uint8_t)*name;
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc >> 1) ^ (0xEDB88320u & (0u - (crc & 1u)));
    }
    return ~crc;
}

/* ---- stat selection ---------------------------------------------------- */

/* Engine routine 0x88699300 stores one rating into the "current stroke
 * skill" slot of the player state on entry to each swing state:
 *   ground stroke : Return rating when returning, else Forehand/Backhand
 *   volley states : Volley rating
 *   the serve state selects the Serve rating (inferred, not observed). */
float gp_stat_for_stroke(const GpPlayerStats *s, GpStroke stroke, int forehand_side)
{
    switch (stroke) {
    case GP_STROKE_RETURN:
        return s->ret;
    case GP_STROKE_VOLLEY:
        return s->volley;
    case GP_STROKE_SERVE:
        return s->serve;
    case GP_STROKE_GROUND:
    default:
        return forehand_side ? s->forehand : s->backhand;
    }
}

/* Engine routines 0x8865B3B0 / 0x88694200 compare the two wing ratings with
 * a small epsilon before deciding which side is the "stronger" one. */
int gp_stronger_side(const GpPlayerStats *s, float eps)
{
    if (s->forehand > s->backhand + eps)
        return 1;
    if (s->backhand > s->forehand + eps)
        return -1;
    return 0;
}

/* ---- piecewise-linear curve (engine 0x8817A688) ------------------------ */

float gp_curve_eval(const GpCurve *curve, float x)
{
    if (curve->count == 0)
        return 0.0f;

    /* last segment whose start is <= x; the first segment is the fallback */
    const GpCurveSeg *seg = &curve->segs[0];
    for (size_t i = 0; i < curve->count; ++i) {
        if (curve->segs[i].x0 > x)
            break;
        seg = &curve->segs[i];
    }

    float local = x - seg->x0;
    float span = seg->x1 - seg->x0;
    if (local >= span)
        local = span;
    if (local < 0.0f)
        local = 0.0f;
    return local * seg->slope + seg->y0;
}

/* ---- data-flow graph (engine 0x8890E988 / 0x8890E8B0) ------------------ */

static float clamp01(float v)
{
    if (v < 0.0f)
        v = 0.0f;
    if (v - 1.0f >= 0.0f)
        v = 1.0f;
    return v;
}

static void run_node(GpGraph *g, const GpNode *n)
{
    float *r = g->regs;
    float acc;

    switch (n->kind) {
    case GP_NODE_CONST:
        r[n->out] = n->literal;
        break;
    case GP_NODE_SUM:
    case GP_NODE_PRODUCT:
    case GP_NODE_MIN:
    case GP_NODE_MAX:
        acc = r[n->in[0]];
        for (int i = 1; i < n->in_count; ++i) {
            float v = r[n->in[i]];
            if (n->kind == GP_NODE_SUM)
                acc += v;
            else if (n->kind == GP_NODE_PRODUCT)
                acc *= v;
            else if (n->kind == GP_NODE_MIN)
                acc = (acc < v) ? acc : v;
            else
                acc = (acc < v) ? v : acc;
        }
        r[n->out] = acc;
        break;
    case GP_NODE_SUM_OR_FLAG: {
        int bad = 0;
        acc = 0.0f;
        for (int i = 0; i < n->in_count; ++i) {
            float v = r[n->in[i]];
            if (v < 0.0f) {
                bad = 1;
                break;
            }
            acc = (i == 0) ? v : acc + v;
        }
        r[n->out] = bad ? n->invalid_value : acc;
        break;
    }
    case GP_NODE_CURVE:
        if (n->out >= 0)
            r[n->out] = gp_curve_eval(n->curve, r[n->in[0]]);
        break;
    case GP_NODE_SUB:
        r[n->out] = r[n->in[0]] - r[n->in[1]];
        break;
    case GP_NODE_DIV:
        r[n->out] = r[n->in[0]] / r[n->in[1]];
        break;
    case GP_NODE_LERP: {
        float a = r[n->in[0]];
        float b = r[n->in[1]];
        r[n->out] = clamp01(r[n->in[2]]) * (b - a) + a;
        break;
    }
    case GP_NODE_INVLERP: {
        float a = r[n->in[0]];
        float b = r[n->in[1]];
        r[n->out] = clamp01((r[n->in[2]] - a) / (b - a));
        break;
    }
    }
}

void gp_graph_eval(GpGraph *g)
{
    for (size_t i = 0; i < g->input_count; ++i)
        if (g->inputs[i].var)
            g->regs[g->inputs[i].reg] = *g->inputs[i].var;
    for (size_t i = 0; i < g->node_count; ++i)
        run_node(g, &g->nodes[i]);
    for (size_t i = 0; i < g->output_count; ++i)
        if (g->outputs[i].var)
            *g->outputs[i].var = g->regs[g->outputs[i].reg];
}
