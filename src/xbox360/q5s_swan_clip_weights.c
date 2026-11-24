/* Swing animation engine (swan): clamp each clip's weight into the owner's offset range. */

/* 0x98-byte clip records ([begin, end) at +0x0C/+0x14 of the owner); the ramp evaluator 886CAEC0 reads the
 * clip's window at +0x24/+0x28. */
typedef struct Ts4SwanClipRange { float lo; float hi; } Ts4SwanClipRange;
typedef struct Ts4SwanClip {
    char pad_0000[0x84];
    void *data;                       /* +0x84: ramp evaluated only when set */
    float weight;                     /* +0x88 */
    char pad_008c[0x98 - 0x8C];
} Ts4SwanClip;
typedef struct Ts4SwanClipSet {
    char pad_0000[0x0C];
    Ts4SwanClip *begin;               /* +0x0C */
    char pad_0010[4];
    Ts4SwanClip *end;                 /* +0x14 */
    Ts4SwanClipRange *range;          /* +0x18 */
} Ts4SwanClipSet;

static const float ts4_swan_zero = 0.0f;
static __inline float ts4_swan_max(float a, float b) { return (a - b >= ts4_swan_zero) ? a : b; }
static __inline float ts4_swan_min(float a, float b) { return (a - b >= ts4_swan_zero) ? b : a; }

extern float ts4_ramp_weight_886CAEC0(void *ramp, void *clip, float x);

/* inlined 0x886CAF78: ramp weight when the clip has data, else 0 */
static __inline float ts4_swan_clip_eval(Ts4SwanClipSet *self, Ts4SwanClip *c, float t)
{
    if (c->data != 0)
        return ts4_ramp_weight_886CAEC0(self, c, t);
    return 0.0f;
}

/* Swing_DLL.xex 0x886CAF98: for every clip, weight = clamp(ramp(t), [weight + lo, weight + hi]) with the
 * hi bound applied first (max against hi + w, then min against lo + w), as in 0x886CAE50 */
void ts4_swan_clamp_clip_weights_886CAF98(Ts4SwanClipSet *self, float t)
{
    Ts4SwanClip *end = self->end;
    Ts4SwanClip *it;
    for (it = self->begin; it != end; it++) {
        float w = ts4_swan_clip_eval(self, it, t);
        Ts4SwanClipRange *r = self->range;
        float lo = r->lo;
        float d = it->weight;
        it->weight = ts4_swan_min(ts4_swan_max(w, r->hi + d), lo + d);
    }
}
