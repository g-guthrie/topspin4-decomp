/* W5A: bilinear lattice gradient difference. */
typedef struct W5aCell { float v[4]; } W5aCell;
typedef struct W5aNoise { unsigned char pad00[0xac]; unsigned char *table; } W5aNoise;
typedef struct W5aGrid { unsigned char pad00[0x0c]; int stride; float scale; } W5aGrid;

static __inline float w5a_lerp(float a, float b, float t) { return a * (1.0f - t) + b * t; }
static __inline float w5a_lerp2(float a, float b, float t) { return b * t + a * (1.0f - t); }

void fn_88644CE8(W5aNoise *n, W5aGrid *g, float u, float v, float *out_a, float *out_b)
{
    float su = g->scale * u;
    float sv = g->scale * v;
    unsigned w = g->stride;
    unsigned i = (unsigned)su;
    unsigned j = (unsigned)sv;
    float fu = su - (float)i;
    float fv = sv - (float)j;
    const float *ea = (const float *)(n->table + (i + w) * 8);
    const float *eb = (const float *)(n->table + (j + w) * 8);
    float bb = w5a_lerp2(eb[1], eb[3], fv);
    float ba = w5a_lerp2(ea[1], ea[3], fu);
    float ab = w5a_lerp(eb[0], eb[2], fv);
    float aa = w5a_lerp(ea[0], ea[2], fu);
    *out_a = ab - aa;
    *out_b = bb - ba;
}
