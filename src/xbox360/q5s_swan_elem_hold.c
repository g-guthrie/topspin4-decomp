/* Swing_DLL.xex 0x886D8078: for each 0x98-byte element with a nonzero gain, offset the input point by -off,
 * latch it as the hold value on a fresh element (or clamp it to the held value with the fsel table select),
 * store the gain into the inner node and forward to the clamp-window apply (886D6D18).
 * LTCG route (pl1_clamp_window.c with /Ob1, pool primer last).
 * Codegen notes: the zero must be the literal 0.0f in both the gain test and the min helper (a named const
 * gives branches or a reloaded pool constant); v.x += o / v.y += o sets the fneg/fadds register numbering;
 * reading inner->n and self->ctx into locals before the gain store sets the argument setup order. */
typedef struct Ts4SwanV2 { float x, y; } Ts4SwanV2;
typedef struct Ts4SwanNode { unsigned char pad00[4]; float gain; } Ts4SwanNode;
typedef struct Ts4SwanInner { unsigned char pad00[8]; Ts4SwanNode *n; } Ts4SwanInner;
typedef struct Ts4SwanElem {
    unsigned char pad00[4];
    Ts4SwanInner *inner;        /* +0x04 */
    unsigned char pad08[0x14 - 0x08];
    float scale;                /* +0x14 */
    unsigned char pad18[0x24 - 0x18];
    float off;                  /* +0x24 */
    unsigned char pad28[0x44 - 0x28];
    float rec[4];               /* +0x44 */
    unsigned char pad54[0x84 - 0x54];
    unsigned int fresh;         /* +0x84 */
    unsigned char pad88[0x8c - 0x88];
    float gain;                 /* +0x8c */
    float held;                 /* +0x90 */
    unsigned char has_held;     /* +0x94 */
    unsigned char pad95[3];
} Ts4SwanElem;                  /* 0x98 */
typedef struct Ts4SwanElemSet {
    unsigned char pad00[8];
    void *ctx;                  /* +0x08 */
    Ts4SwanElem *begin;         /* +0x0c */
    unsigned int pad10;
    Ts4SwanElem *end;           /* +0x14 */
} Ts4SwanElemSet;

static __inline float ts4_swan_hold_min(float a, float b) { return (a - b >= 0.0f) ? b : a; }

extern void ts4_clamp_window_apply_886D6D18(Ts4SwanInner *in, void *ctx, float *rec, Ts4SwanV2 *v, float f);

void ts4_swan_update_held_elems_886D8078(Ts4SwanElemSet *self, Ts4SwanV2 *pt)
{
    Ts4SwanElem *e;
    Ts4SwanElem *end = self->end;
    for (e = self->begin; e != end; e++) {
        float g = e->gain;
        if (g != 0.0f) {
            Ts4SwanV2 v = *pt;
            float o = -e->off;
            float x, y;
            v.x += o;
            v.y += o;
            x = v.x;
            y = v.y;
            if (e->fresh != 0) {
                e->held = x;
                e->has_held = 1;
            } else if (e->has_held != 0) {
                float h = e->held;
                float nx = ts4_swan_hold_min(h, x);
                float ny = ts4_swan_hold_min(h, y);
                v.x = nx;
                v.y = ny;
            }
            {
                Ts4SwanNode *n = e->inner->n;
                void *ctx = self->ctx;
                n->gain = g;
                ts4_clamp_window_apply_886D6D18(e->inner, ctx, e->rec, &v, e->scale);
            }
        }
    }
}
