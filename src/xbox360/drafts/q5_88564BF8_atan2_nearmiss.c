/* Q5 round 4 near-miss of 0x88564BF8 (CRT atan2, outside LTCG; plain fn_check): 68 off, size 0x13c vs 0x130; gaps: record-form clrrwi., fabs order, polynomial register allocation. Not a match. */
typedef struct Q5Atan2Table {
    double pad00;
    double half_pi;       /* +0x08 */
    double pi;            /* +0x10 */
    double tan_15deg;     /* +0x18 */
    double pad20;
    double sqrt3;         /* +0x28 */
    double pad30;
    double p[4];          /* +0x38 numerator coefficients, constant term first */
    double q[4];          /* +0x58 denominator coefficients, constant term first */
    double pad78;
    double offset[4];     /* +0x80 0, pi/6, pi/2, pi/3 */
    double padA0;
    float zero;           /* +0xA8 */
    float padAC;
    float one;            /* +0xB0 */
} Q5Atan2Table;
double fabs(double x);
#pragma intrinsic(fabs)
extern const Q5Atan2Table lbl_88C30C70;
#define Q5_SIGN(d) (*(const unsigned int *)&(d) & 0x80000000u)
double fn_88564BF8(double y, double x)
{
    const Q5Atan2Table *k = &lbl_88C30C70;
    double r;
    if (x == k->zero) {
        if (y == k->zero) {
            if (Q5_SIGN(x) == 0)
                return y;
            if (Q5_SIGN(y) == 0)
                return k->pi;
            return -k->pi;
        }
        r = k->half_pi;
    } else {
        double ax = fabs(x), ay = fabs(y), den = ax, z, p, q;
        int n = 0;
        if (ay > ax) {
            den = ay;
            n = 2;
            ay = ax;
        }
        r = ay / den;
        if (r > k->tan_15deg) {
            n++;
            r = (k->sqrt3 * r - k->one) / (k->sqrt3 + r);
        }
        z = r * r;
        p = k->p[3];
        q = k->q[3] + z;
        p = p * z + k->p[2];
        q = q * z + k->q[2];
        p = p * z + k->p[1];
        q = q * z + k->q[1];
        p = p * z + k->p[0];
        q = q * z + k->q[0];
        p = p * z;
        p = p * r;
        r = p / q + r;
        if (n > 1)
            r = -r;
        r = k->offset[n] + r;
    }
    r = __fsel(x, r, k->pi - r);
    if (Q5_SIGN(y))
        r = -r;
    return r;
}
