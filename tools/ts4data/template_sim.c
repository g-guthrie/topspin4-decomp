/* Host driver: simulate one shot of one shot-template row with the bit-exact ball model
 * (src/xbox360/drafts/gp4b_ball_model.c) and print one line of measurements.
 *
 *   cc -std=c11 -O1 -I src/xbox360 -o template_sim tools/ts4data/template_sim.c \
 *      src/xbox360/drafts/gp4b_ball_model.c -lm
 *   template_sim FILE ROW_OFFSET fx fy fz tx ty tz blend f430 sidesign [a4 g radius_cm net_cm]
 *
 * FILE is a raw Settings.bin / State.bin (not committed), ROW_OFFSET the byte offset of the 0x8C-byte row.
 * Coordinates are world cm: x along the court (net at x = 0, hitter at x < 0), y up, z across.
 * Defaults a4 = 0.06, g = 9.81, radius = 4.0 cm are the values stored in the default ball block of State.bin
 * (docs/gameplay/shot-templates.md); net = 91.4 cm is an assumption (centre strap). */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gp4b_types.h"

void gp4b_probe(Gp4bBall *B, const uint8_t *row, Gp4bSolve *O);
void gp4b_to_local(Gp4bBall *B);
void gp4b_launch(Gp4bBall *B, const uint8_t *row, float ticks_per_second);
void gp4b_arc1_position(float dt, Gp4bBall *B);
void gp4b_velocity_arrival(const Gp4bBall *B, float out[4]);
void gp4b_velocity_launch(const Gp4bBall *B, float out[4]);

static uint32_t be32(const uint8_t *p) { return ((uint32_t)p[0] << 24) | ((uint32_t)p[1] << 16) | ((uint32_t)p[2] << 8) | p[3]; }
static float bef32(const uint8_t *p) { uint32_t u = be32(p); float f; memcpy(&f, &u, 4); return f; }

/* curve16 evaluator (same rule as the model's static one) */
static float c16(const uint8_t *hdr, float x)
{
    int32_t first = (int32_t)be32(hdr), n = (int32_t)be32(hdr + 4), i;
    const uint8_t *sel, *cur;
    float x0, x1, y0, y1, t, span;
    if (first == -1 || n <= 0) return 0.0f;
    sel = cur = hdr + first;
    for (i = 0; i < n; i++, cur += 16) { if (bef32(cur) > x) break; sel = cur; }
    x0 = bef32(sel); x1 = bef32(sel + 4); y0 = bef32(sel + 8); y1 = bef32(sel + 12);
    span = x1 - x0;
    t = x - x0; if (t < 0) t = 0; if (t > span) t = span;
    return y0 + (span != 0 ? t / span : 0) * (y1 - y0);
}

static float wrap_pi(float a) { while (a > 3.14159265f) a -= 6.28318531f; while (a <= -3.14159265f) a += 6.28318531f; return a; }

static void rotate(float v[3], const float ax_in[3], float ang)
{
    float ax[3], l = sqrtf(ax_in[0] * ax_in[0] + ax_in[1] * ax_in[1] + ax_in[2] * ax_in[2]);
    float c = cosf(ang), s = sinf(ang), d, cr[3], o[3];
    int i;
    if (l == 0) return;
    for (i = 0; i < 3; i++) ax[i] = ax_in[i] / l;
    d = ax[0] * v[0] + ax[1] * v[1] + ax[2] * v[2];
    cr[0] = ax[1] * v[2] - ax[2] * v[1]; cr[1] = ax[2] * v[0] - ax[0] * v[2]; cr[2] = ax[0] * v[1] - ax[1] * v[0];
    for (i = 0; i < 3; i++) o[i] = v[i] * c + cr[i] * s + ax[i] * d * (1 - c);
    for (i = 0; i < 3; i++) v[i] = o[i];
}

int main(int argc, char **argv)
{
    static uint8_t buf[1 << 20];
    FILE *f;
    size_t n;
    const uint8_t *row;
    Gp4bBall B;
    Gp4bSolve O;
    float v[4], vl[4], va[4], bv[3], up[3] = {0, 1, 0}, axis[3] = {0, 0, 1};
    float tau, t, dt = 0.001f, apex = -1e9f, apex_t = 0, net_c = -1e9f, dev_max = 0, net_bottom = -1e9f;
    float rad_m, net_m, lenx, lenz, ux, uz, spd_in, ang_in, theta, sf, w, delta, yaw, spd_out, ang_out, vlen;
    float prevx = 0, prevy = 0, lat_acc, a4, g;
    int have_net = 0;
    if (argc < 12) { fprintf(stderr, "usage: %s FILE ROW fx fy fz tx ty tz blend f430 sidesign [a4 g radius_cm net_cm]\n", argv[0]); return 2; }
    f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 2; }
    n = fread(buf, 1, sizeof buf, f);
    fclose(f);
    row = buf + strtoul(argv[2], NULL, 0);
    if ((size_t)(row - buf) + 0x90 > n) return 2;
    memset(&B, 0, sizeof B);
    memset(&O, 0, sizeof O);
    B.cmd_from[0] = (float)atof(argv[3]); B.cmd_from[1] = (float)atof(argv[4]); B.cmd_from[2] = (float)atof(argv[5]);
    B.cmd_to[0] = (float)atof(argv[6]); B.cmd_to[1] = (float)atof(argv[7]); B.cmd_to[2] = (float)atof(argv[8]);
    B.blend = (float)atof(argv[9]);
    B.shot_f430 = (float)atof(argv[10]);
    B.sidespin_neg = (uint8_t)atoi(argv[11]);
    B.a4 = argc > 12 ? (float)atof(argv[12]) : 0.06f;
    B.g = argc > 13 ? (float)atof(argv[13]) : 9.81f;
    B.radius_cm = argc > 14 ? (float)atof(argv[14]) : 4.0f;
    B.net_height_cm = argc > 15 ? (float)atof(argv[15]) : 91.4f;
    B.planned = 1; B.shot_id = 0x12345678u; B.launch_frame = 0;
    a4 = B.a4; g = B.g;
    rad_m = B.radius_cm * 0.01f; net_m = B.net_height_cm * 0.01f;

    gp4b_probe(&B, row, &O);
    tau = B.tau;
    gp4b_to_local(&B);
    gp4b_launch(&B, row, 60.0f);
    gp4b_velocity_launch(&B, vl);
    gp4b_velocity_arrival(&B, va);

    lenx = B.P1[0] - B.P0[0]; lenz = B.P1[2] - B.P0[2];
    vlen = sqrtf(lenx * lenx + lenz * lenz);
    ux = lenx / vlen; uz = lenz / vlen;
    B.tick = 1; B.tick_prev = 0;                              /* arc1_position computes t = (tick - tick_prev) * dt */
    for (t = 0; t <= tau + 1e-6f; t += dt) {
        float x, y, z, rx, rz, dev;
        gp4b_arc1_position(t, &B);
        x = B.pos[0]; y = B.pos[1] + rad_m; z = B.pos[2];   /* y: ball-centre height above the ground */
        if (y > apex) { apex = y; apex_t = t; }
        rx = x - B.P0[0]; rz = z - B.P0[2];
        dev = fabsf(rx * (-uz) + rz * ux);                   /* horizontal distance from the straight chord */
        if (dev > dev_max) dev_max = dev;
        if (t > 0 && prevx < 0 && x >= 0) {
            float fr = -prevx / (x - prevx);
            net_c = prevy + (y - prevy) * fr;
            net_bottom = net_c - rad_m;
            have_net = 1;
        }
        prevx = x; prevy = y;
    }
    gp4b_arc1_position(tau, &B);

    /* ground bounce response, same as gp4_bounce (docs/gameplay/gp4b.md 4.3), spin_a / spin_b at launch */
    bv[0] = va[0]; bv[1] = va[1]; bv[2] = va[2];
    spd_in = sqrtf(bv[0] * bv[0] + bv[1] * bv[1] + bv[2] * bv[2]);
    {
        float hs = sqrtf(bv[0] * bv[0] + bv[2] * bv[2]);
        ang_in = atan2f(-bv[1], hs);
    }
    v[0] = bv[0]; v[1] = -bv[1]; v[2] = bv[2];
    {
        float len = spd_in, cosang = v[1] / len, cr[3];
        if (fabsf(cosang) < 0.99999f) {
            cr[0] = v[1] * up[2] - v[2] * up[1]; cr[1] = v[2] * up[0] - v[0] * up[2]; cr[2] = v[0] * up[1] - v[1] * up[0];
            axis[0] = cr[0]; axis[1] = cr[1]; axis[2] = cr[2];
        }
    }
    theta = atan2f(v[1], v[0]);
    if (theta > 1.5707964f) theta = 3.1415927f - theta;
    sf = 1.0f - c16(row + 0x58, B.spin_a);
    w = fabsf(B.spin_a * 5.0f);
    delta = wrap_pi(c16(row + 0x70, theta) - theta);
    yaw = c16(row + 0x7C, B.spin_b);
    v[0] *= sf; v[1] *= sf; v[2] *= sf;
    rotate(v, axis, delta * w);
    rotate(v, up, yaw);
    spd_out = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    ang_out = atan2f(v[1], sqrtf(v[0] * v[0] + v[2] * v[2]));
    {
        /* lateral spin acceleration: component of A along c1 = (-u.z, 0, u.x), u = (P0-P1)/|P0-P1| */
        float dx = B.P0[0] - B.P1[0], dy = B.P0[1] - B.P1[1], dz = B.P0[2] - B.P1[2];
        float dl = sqrtf(dx * dx + dy * dy + dz * dz), u0 = dx / dl, u2 = dz / dl;
        lat_acc = (B.A[0] * (-u2) + B.A[2] * u0) / a4;
    }

    printf("tau=%.4f tick=%u dist=%.3f init_kmh=%.2f launch_kmh=%.2f arrive_kmh=%.2f apex_m=%.3f apex_t=%.3f "
           "net_centre_m=%.3f net_bottom_m=%.3f raised=%d unreach=%d has_min=%d land_err=%.5f "
           "in_deg=%.2f in_kmh=%.2f sf=%.3f out_kmh=%.2f out_deg=%.2f e_vert=%.3f h_ret=%.3f "
           "spin_a=%.4f spin_b=%.4f spin_c=%.4f k=%.4f drift_g=%.3f lat_acc=%.3f lat_dev_m=%.3f T=%.4f launch_deg=%.2f\n",
           tau, (unsigned)B.bounce_tick, vlen, O.initial_kmh, sqrtf(vl[0] * vl[0] + vl[1] * vl[1] + vl[2] * vl[2]) * 3.6f,
           spd_in * 3.6f, apex, apex_t, have_net ? net_c - net_m : -99.0f, have_net ? net_bottom - net_m : -99.0f,
           O.raised, O.net_unreachable, O.has_min,
           sqrtf((B.pos[0] - B.P1[0]) * (B.pos[0] - B.P1[0]) + (B.pos[2] - B.P1[2]) * (B.pos[2] - B.P1[2])),
           ang_in * 57.29578f, spd_in * 3.6f, sf, spd_out * 3.6f, ang_out * 57.29578f,
           fabsf(v[1] / (-bv[1])), sqrtf(v[0] * v[0] + v[2] * v[2]) / sqrtf(bv[0] * bv[0] + bv[2] * bv[2]),
           B.spin_a, B.spin_b, B.spin_c, B.T / a4, -(B.A[1] / a4) / g, lat_acc, dev_max, B.T,
           atan2f(vl[1], sqrtf(vl[0] * vl[0] + vl[2] * vl[2])) * 57.29578f);
    return 0;
}
