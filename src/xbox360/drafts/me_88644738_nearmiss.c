/* NEAR MISS 0x88644738: 10 off; target keeps a dead `addi r3,r3,4` (&c->range) in the upper branch and reloads
 * split there. Helper forms from the dead-addi tips did not reproduce it. */
/* 0x88644738 (hand match): maps a value through a split point: values below the split scale to [0, 1)
 * by the split, values at or above it to [0, 1] over the rest of the range; with no split (split not above
 * the event threshold) the value passes through unchanged. */
typedef struct Range { float lo; float split; } Range;
typedef struct Curve { char p[4]; Range range; } Curve;
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
static __inline void upper(Range *r, float x, float *out) { *out = (x - r->split) / (g_ts4_script_constants[0] - r->split); }
void ts4_map_through_split_88644738(Curve *c, int unused, float *out, float x)
{
    if (!(c->range.split > g_ts4_event_value)) {
        *out = x;
        return;
    }
    if (x >= c->range.split)
        upper(&c->range, x, out);
    else
        *out = x / c->range.split;
}
