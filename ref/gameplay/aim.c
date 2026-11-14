/* See aim.h.  Portable C11, no game data. */
#include "aim.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TS4_FLT_EPSILON 1.1920929e-07f /* lbl_880C960C */
#define TS4_SQRT2 1.4142135f           /* g_ts4_script_constants+0x518 */
#define TS4_DOUBLES_SCALE 1.4f         /* g_ts4_script_constants+0x51C */

static float lerpf(float a, float b, float t) { return a + (b - a) * t; }
static float clamp01(float v) { return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v); }

static void lerp_quad(const Ts4Quad *a, const Ts4Quad *b, float t, Ts4Quad *o)
{
    for (int k = 0; k < 4; k++) {
        o->c[k].x = lerpf(a->c[k].x, b->c[k].x, t);
        o->c[k].z = lerpf(a->c[k].z, b->c[k].z, t);
    }
}

int ts4_aim_quad_state(float sx, float sy, int far_side, float *ax, float *ay)
{
    int sel = fabsf(sx) > TS4_FLT_EPSILON || fabsf(sy) > TS4_FLT_EPSILON;
    *ax = far_side ? -sx : sx;
    *ay = far_side ? -sy : sy;
    return sel;
}

/* corners 0 and 2 are on z-, 1 and 3 on z+: the doubles alley pushes them outward */
static void shift(const Ts4Quad *q, float w, Ts4Quad *o)
{
    *o = *q;
    o->c[0].z -= w; o->c[2].z -= w;
    o->c[1].z += w; o->c[3].z += w;
}

static void scale_z(const Ts4Quad *q, Ts4Quad *o)
{
    *o = *q;
    for (int k = 0; k < 4; k++) o->c[k].z *= TS4_DOUBLES_SCALE;
}

void ts4_aim_zone_quad(const Ts4AimZone *z, float m, float w, Ts4Quad *out)
{
    Ts4Quad a, b;
    float t;
    int big = w > 1.0f;
    if (m < 0.5f) {                      /* quads 0 .. 1 */
        t = clamp01(m * 2.0f);
        a = z->quad[0];
        if (big) scale_z(&z->quad[1], &b); else b = z->quad[1];
    } else if (m <= 1.0f) {              /* quads 1 .. 2 */
        t = clamp01((m - 0.5f) * 2.0f);
        if (big) scale_z(&z->quad[1], &a); else a = z->quad[1];
        shift(&z->quad[2], w, &b);
    } else {                             /* quads 2 .. 3 (the Out path, m = OutEfficiency + 1) */
        t = clamp01(m - 1.0f);
        shift(&z->quad[2], w, &a);
        b = z->quad[3];
    }
    lerp_quad(&a, &b, t, out);
}

void ts4_aim_config_quad(const Ts4AimConfig *cfg, float px, float pz, float m, int mirror,
                         float w, Ts4Quad *quad, Ts4Pt *centre)
{
    float f0 = fabsf(pz) - cfg->center_distance;
    float span = cfg->side_distance - cfg->center_distance;
    float lat = f0 <= 0.0f ? 0.0f : (f0 >= span ? 1.0f : f0 / span);
    float dep;
    Ts4Quad q[4], vq, bq;
    f0 = px + cfg->baseline_distance;
    span = cfg->baseline_distance - cfg->volley_distance;
    dep = f0 <= 0.0f ? 0.0f : (f0 >= span ? 1.0f : f0 / span);
    for (int k = 0; k < 4; k++) ts4_aim_zone_quad(&cfg->zone[k], m, w, &q[k]);
    lerp_quad(&q[0], &q[1], lat, &vq);   /* volley: center -> side */
    lerp_quad(&q[2], &q[3], lat, &bq);   /* baseline: center -> side */
    lerp_quad(&bq, &vq, dep, quad);      /* baseline -> volley */
    {
        Ts4Pt cv = {lerpf(cfg->zone[0].centre.x, cfg->zone[1].centre.x, lat),
                    lerpf(cfg->zone[0].centre.z, cfg->zone[1].centre.z, lat)};
        Ts4Pt cb = {lerpf(cfg->zone[2].centre.x, cfg->zone[3].centre.x, lat),
                    lerpf(cfg->zone[2].centre.z, cfg->zone[3].centre.z, lat)};
        centre->x = lerpf(cb.x, cv.x, dep);
        centre->z = lerpf(cb.z, cv.z, dep);
    }
    if (mirror) {                        /* fn_88661188: negate z, swap c0<->c1 and c2<->c3 */
        Ts4Quad m2 = *quad;
        for (int k = 0; k < 4; k++) m2.c[k].z = -m2.c[k].z;
        quad->c[0] = m2.c[1]; quad->c[1] = m2.c[0];
        quad->c[2] = m2.c[3]; quad->c[3] = m2.c[2];
        centre->z = -centre->z;
    }
}

Ts4Pt ts4_aim_quad_point(const Ts4Quad *q, float ax, float ay)
{
    float n = 1.0f / sqrtf(ay * ay + ax * ax);
    float s;
    const Ts4Pt *a, *b;
    Ts4Pt r;
    if (ax * ax > ay * ay) {             /* left or right edge, position by the y share */
        s = (ay * n * TS4_SQRT2 + 1.0f) * 0.5f;
        if (ax >= 0.0f) { a = &q->c[1]; b = &q->c[3]; } else { a = &q->c[0]; b = &q->c[2]; }
    } else {                             /* deep or short edge, position by the x share */
        s = (ax * n * TS4_SQRT2 + 1.0f) * 0.5f;
        if (ay >= 0.0f) { a = &q->c[2]; b = &q->c[3]; } else { a = &q->c[0]; b = &q->c[1]; }
    }
    r.x = lerpf(a->x, b->x, s);
    r.z = lerpf(a->z, b->z, s);
    return r;
}

int ts4_aim_mirror(int serving, int ad_court, float pos_z)
{
    if (serving) return ad_court;
    return !signbit(pos_z);
}

Ts4Pt ts4_aim_target(const Ts4AimConfig *cfg, float px, float pz, float eff, float ax, float ay,
                     int selected, int mirror, float w)
{
    Ts4Quad q;
    Ts4Pt c;
    ts4_aim_config_quad(cfg, px, pz, eff, mirror, w, &q, &c);
    if (!selected) return c;
    return ts4_aim_quad_point(&q, ax, ay);
}

int ts4_aim_load(const char *path, Ts4AimConfig *out, int max)
{
    FILE *f = fopen(path, "r");
    static char line[16384];
    int n = 0;
    if (!f) return 0;
    while (n < max && fgets(line, sizeof line, f)) {
        char *p = line, *e;
        Ts4AimConfig *c = &out[n];
        float v[2 + 4 * 4 * 2];
        if (line[0] == '#' || line[0] == '\n') continue;
        c->id = (uint32_t)strtoul(p, &e, 16); p = e;
        c->volley_distance = strtof(p, &e); p = e;
        c->baseline_distance = strtof(p, &e); p = e;
        c->center_distance = strtof(p, &e); p = e;
        c->side_distance = strtof(p, &e); p = e;
        for (int z = 0; z < 4; z++) {
            for (size_t k = 0; k < sizeof v / sizeof v[0]; k++) { v[k] = strtof(p, &e); p = e; }
            c->zone[z].centre.x = v[0];
            c->zone[z].centre.z = v[1];
            for (int q = 0; q < 4; q++)
                for (int k = 0; k < 4; k++) {
                    c->zone[z].quad[q].c[k].x = v[2 + 8 * q + 2 * k];
                    c->zone[z].quad[q].c[k].z = v[3 + 8 * q + 2 * k];
                }
        }
        n++;
    }
    fclose(f);
    return n;
}
