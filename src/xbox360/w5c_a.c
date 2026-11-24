/* W5C batch a: small float selects. */
#define W5C_SEL
#include "w5c_types.h"

typedef struct W5cClipDesc { unsigned char pad00[0x14]; float time_ratio; } W5cClipDesc;
typedef struct W5cClipRef { unsigned char pad00[8]; W5cClipDesc *desc; } W5cClipRef;
typedef struct W5cLayer { unsigned char pad00[4]; W5cClipRef *inner; } W5cLayer;

/* Swing_DLL.xex 0x886CBBD8 */
float ts4_clip_ratio_excess_886CBBD8(W5cLayer *l)
{
    float r = l->inner->desc->time_ratio - 1.0f;
    return w5c_max(0.0f, (r - 18.0f) / r);
}

typedef struct W5cRange { float lo; float hi; } W5cRange;
typedef struct W5cClamp { unsigned char pad00[0x18]; W5cRange *range; } W5cClamp;

/* Swing_DLL.xex 0x886CAE50 */
float ts4_clamp_to_range_offset_886CAE50(W5cClamp *o, float d, float x)
{
    W5cRange *r = o->range;
    return w5c_min(w5c_max(x, r->hi + d), r->lo + d);
}
