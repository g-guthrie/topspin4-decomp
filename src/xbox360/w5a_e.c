/* W5A: ramp weight from two edge distances, clamped to [0,1]. */
static const float w5a_zero = 0.0f;
extern const float lbl_880C8FB0;

typedef struct W5aEdge { unsigned char pad00[0x08]; float inv_in; float inv_out; } W5aEdge;
typedef struct W5aRamp { unsigned char pad00[0x18]; W5aEdge *edge; } W5aRamp;
typedef struct W5aRange { unsigned char pad00[0x24]; float lo; float hi; } W5aRange;

static __inline float w5a_max(float a, float b) { return (a - b >= w5a_zero) ? a : b; }
static __inline float w5a_min(float a, float b) { return (a - b >= w5a_zero) ? b : a; }

float ts4_ramp_weight_886CAEC0(W5aRamp *r, W5aRange *g, float x)
{
    float a = 1.0f - ((g->lo + lbl_880C8FB0) - x) * r->edge->inv_in;
    float b = 1.0f - (x - (g->hi - lbl_880C8FB0)) * r->edge->inv_out;
    return w5a_min(w5a_max(w5a_min(a, b), 0.0f), 1.0f);
}
