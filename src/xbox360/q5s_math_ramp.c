/*
 * 0x88179740: precomputes the slope of every 20-byte ramp record in a self-relative array:
 *   slope = (out1 - out0) / (in1 - in0), or 0 when the input span is 0 (g_ts4_event_value == 0.0f).
 * Only caller: 0x8890DFC8 (fam5_h_000.c), which passes the array header.
 *
 * Codegen: begin/end helpers in the `T *p = 0; if (offset != -1) p = ...;` form (li before cmpwi),
 * end computed first. The slope must be one `?:` store: an if/else with two stores duplicates the
 * stfs and rematerialises the zero.
 */
#include "include/ts4/ts4.h"

extern const float g_ts4_event_value;   /* 0.0f */

typedef struct Q5sRamp {
    float in0;     /* +0x00 */
    float in1;     /* +0x04 */
    float out0;    /* +0x08 */
    float slope;   /* +0x0C written here */
    float out1;    /* +0x10 */
} Q5sRamp;

static __inline Q5sRamp *q5s_ramp_begin(Ts4RelArray *a)
{
    Q5sRamp *p = 0;
    if (a->offset != -1)
        p = (Q5sRamp *)((char *)a + a->offset);
    return p;
}

static __inline Q5sRamp *q5s_ramp_end(Ts4RelArray *a)
{
    Q5sRamp *p = 0;
    if (a->offset != -1)
        p = (Q5sRamp *)((char *)a + a->offset) + a->count;
    return p;
}

void ts4_ramp_slopes_init_88179740(Ts4RelArray *a)
{
    Q5sRamp *end = q5s_ramp_end(a);
    Q5sRamp *p;
    for (p = q5s_ramp_begin(a); p != end; ++p) {
        float d = p->in1 - p->in0;
        p->slope = d == g_ts4_event_value ? g_ts4_event_value : (p->out1 - p->out0) / d;
    }
}
