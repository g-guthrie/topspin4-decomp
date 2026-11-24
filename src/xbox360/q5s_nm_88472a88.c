/* 0x88472A88: takes the minimum of the three floats of v; stores min * 0.2 into +0x48 when it is below 0.5, else 0.1.
 * Matched (/Oc plain) with float literals for lbl_88001978 (0.5), lbl_880026EC (0.2) and lbl_88029278 (0.1):
 * the extern multiplier gives `fmuls f0,f13,f0`, the literal the target's `fmuls f0,f0,f13`. */
typedef struct Ts4MinVec3 { float x, y, z; } Ts4MinVec3;
typedef struct Ts4MinScaled { char pad_00[0x48]; float scale; } Ts4MinScaled;

static float ts4_minf(float a, float b) { return a - b >= 0.0f ? b : a; }

void ts4_set_scale_from_min3_88472A88(Ts4MinScaled *o, const Ts4MinVec3 *v)
{
    float m = ts4_minf(ts4_minf(v->x, v->y), v->z);
    if (m < 0.5f)
        o->scale = m * 0.2f;
    else
        o->scale = 0.1f;
}
