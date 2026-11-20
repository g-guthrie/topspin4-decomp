/* W5A: layer inverse time warp, clamped to [t_ref, ..] in [0,1]. */
#include "w5a_types.h"

static const float w5a_zero = 0.0f;

typedef struct W5aClipDesc { unsigned char pad00[0x14]; float time_ratio; } W5aClipDesc;
typedef struct W5aClipRef { unsigned char pad00[0x08]; W5aClipDesc *desc; } W5aClipRef;
typedef struct W5aLayer {
    unsigned char pad00[0x04];
    W5aClipRef *inner;          /* +0x04 */
    unsigned char pad08[0x14 - 0x08];
    float t_ref;                /* +0x14 */
    unsigned char pad18[0x24 - 0x18];
    float base;                 /* +0x24 */
} W5aLayer;

static __inline float w5a_max(float a, float b) { return (a - b >= w5a_zero) ? a : b; }
static __inline float w5a_min(float a, float b) { return (a - b >= w5a_zero) ? b : a; }

float ts4_layer_inv_time_warp_886D1318(W5aLayer *l, float t)
{
    float d = l->inner->desc->time_ratio - 1.0f;
    float inv = __fres(d);
    float x;
    inv = ((1.0f - inv * d) + 1.0f) * inv;
    x = (t - l->base) * inv + l->t_ref;
    return w5a_max(w5a_min(w5a_max(x, 0.0f), 1.0f), l->t_ref);
}
