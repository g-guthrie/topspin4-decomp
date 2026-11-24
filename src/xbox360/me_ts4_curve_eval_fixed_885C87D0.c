/* 0x885C87D0: Evaluates a fixed-point piecewise-linear curve at x: a table index from the masked offset plus either slope*frac+value or interpolation between neighbouring values. */
/* Matched on /Oc (agAH). Plain C. */
typedef struct Curve {
    void *p0;
    int *values;
    int *slopes;
    unsigned int base;
    unsigned int index_mask;
    unsigned int shift;
    unsigned int frac_mask;
    int use_slopes;
} Curve;
int fn_885C87D0(const Curve *c, unsigned int x)
{
    unsigned int d = x - c->base;
    unsigned int i = (c->index_mask & d) >> c->shift;
    int f = c->frac_mask & d;
    if (c->use_slopes)
        return c->slopes[i] * f + c->values[i];
    else {
        const int *v = &c->values[i];
        return (v[1] - v[0]) * f / (1 << c->shift) + v[0];
    }
}
