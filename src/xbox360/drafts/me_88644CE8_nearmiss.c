/* 0x88644CE8 (draft, 27 instructions off): samples a table of (a, b) pairs at two scaled positions with
 * linear interpolation and returns the differences of the two samples. Open: float scheduling order of the
 * four interpolations (target multiplies B1b*ty, A1b*tx, B0a*(1-ty), A0a*(1-tx) plainly and fuses the rest). */
typedef struct Pair { float a, b; } Pair;
typedef struct Cfg { char p[0xc]; int base; float scale; } Cfg;
typedef struct Obj { char p[0xac]; Pair *table; } Obj;
extern const float g_ts4_script_constants[];
#define ONE g_ts4_script_constants[0]
void ts4_sample_pair_table_delta_88644CE8(Obj *o, Cfg *c, float u, float w, float *da, float *db)
{
    float fy = c->scale * w;
    float fx = c->scale * u;
    unsigned int ix = (unsigned int)fx;
    unsigned int iy = (unsigned int)fy;
    Pair *A = &o->table[ix + c->base];
    Pair *B = &o->table[iy + c->base];
    float ty = fy - (float)iy;
    float tx = fx - (float)ix;
    float vbA = A[0].b * (ONE - tx) + A[1].b * tx;
    float vbB = B[0].b * (ONE - ty) + B[1].b * ty;
    float vaA = A[1].a * tx + A[0].a * (ONE - tx);
    float vaB = B[1].a * ty + B[0].a * (ONE - ty);
    *db = vbB - vbA;
    *da = vaB - vaA;
}
