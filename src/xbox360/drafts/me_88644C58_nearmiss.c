/* agF 2026-11-19: not retried beyond reading (5); no new idea. */
/* agD round 2: still 5. Reload/decl variants (late s read, struct copy, named products, operand swaps) give 5 to 10; only the volatile s read keeps the right reload order. */
/* agD 2026-11-19: volatile store of p.v.v[2] (`*(volatile float *)&p.v.v[2] = a2;`) fixes the early a2/a stfs order: 7 -> 5 off. Remaining: s reload lands in f9 (target reuses f13) because of the volatile read; plain reads of sc.s give the wrong reload order (8). */
/* agentA2 (2026-11-18 tips pass): volatile read of sc.s -> 8 to 7 off (plain and LTCG); reload/fmuls order now right, residue: early a/a2 stfs order and f9 vs f13 for s. Also tried decl order, named products, operand swaps. */
/* me_88644C58 near-miss: 8 off (plain /Oc). Rotate (x, y) by angle a using polynomial cos/sin: builds (1, a, a^2, a^3),
   cos = dot4(p*p, coeffs@0x880D1B10), sin = dot4(p*p*a, coeffs@0x880D1B00); y' = y*cos - x*sin, x' = y*sin + x*cos.
   Putting cos/sin in a {s, c} struct fixes the stack slots; residue is f0/f13 assignment of the two reloads and the
   resulting fmuls/fmsubs/fmadds register numbers. 8 variants (decl order, dot4 helper, struct, block locals). */
#include "../vx1_vector.h"
void __stvewx(__vector4 v, void *p, int off);
extern const __vector4 lbl_880D1B00;   /* sine series coefficients */
extern const __vector4 lbl_880D1B10;   /* cosine series coefficients */

void fn_88644C58(float *x, float *y, float a)
{
    Vx1Vec p;
    __vector4 sq;
    struct { float s, c; } sc;
    float a2 = a * a;
    float px, py;
    *(volatile float *)&p.v.v[2] = a2;
    p.v.v[1] = a;
    p.v.v[0] = 1.0f;
    p.v.v[3] = a2 * a;
    sq = __vmulfp(p.v, p.v);
    __stvewx(__vmsum4fp(sq, lbl_880D1B10), &sc.c, 0);
    __stvewx(__vmsum4fp(__vmulfp(sq, __vspltw(p.v, 1)), lbl_880D1B00), &sc.s, 0);
    {
        float c = sc.c, s = *(volatile float *)&sc.s;
        py = *y;
        px = *x;
        *y = py * c - px * s;
        *x = py * s + px * c;
    }
}
