/*
 * SC1 (LTCG route): 0x8864A920. Check with
 *   tools/fn_check_ltcg.py src/xbox360/sc1_ltcg_a.c ts4_init_state_8864A920=0x8864A920
 *     --context src/xbox360/pp1_pool_primer.c --flags /Oc
 * Store order follows the member sub-objects (three-word vectors at +0x00/+0x0c
 * and +0x28/+0x34/+0x40, the {word, vector} block at +0x70, the words at +0x94);
 * see docs/agents/near-misses/SC1.md. The 1.0f is a literal: under LTCG it is
 * pool entry 0 (g_ts4_script_constants, 0x880D0F70) and its load is scheduled
 * freely, where a load through the extern array is held behind the stores.
 */
#include "vx1_vector.h"
extern const float g_ts4_event_value;
typedef struct Sc1V3 { int b, e, c; } Sc1V3;
static __inline void sc1_v3_init(Sc1V3 *v) { v->b = 0; v->e = 0; v->c = 0; }
typedef struct Sc1S70 { int f70; unsigned char pad74[0xc]; Vx1Vec v80; } Sc1S70;
static __inline void sc1_s70_init(Sc1S70 *t) { t->f70 = 0; t->v80.v = __vspltisw(0); }
typedef struct Sc1G94 { int f94, f98; unsigned char pad9c[4]; int fa0, fa4; } Sc1G94;
static __inline void sc1_g94_init(Sc1G94 *g) { g->f94 = 0; g->f98 = 0; g->fa0 = 0; g->fa4 = 0; }
typedef struct Sc1State8864A920 {
    Sc1V3 v00, v0c;
    unsigned char b18; unsigned char pad19[3];
    float f1c;
    unsigned char b20; unsigned char pad21[3];
    float f24;
    Sc1V3 v28, v34, v40;
    unsigned char pad4c[0x70 - 0x4c];
    Sc1S70 s70;
    float f90;
    Sc1G94 g94;
    int fa8, fac, fb0, fb4, fb8, fbc;
} Sc1State8864A920;

/* Swing_DLL.xex 0x8864A920: ts4_init_state_8864A920 */
void ts4_init_state_8864A920(Sc1State8864A920 *s)
{
    sc1_v3_init(&s->v00); sc1_v3_init(&s->v0c);
    sc1_v3_init(&s->v28); sc1_v3_init(&s->v34); sc1_v3_init(&s->v40);
    s->f90 = g_ts4_event_value;
    sc1_s70_init(&s->s70);
    sc1_g94_init(&s->g94);
    {
        float one = 1.0f;
        s->f1c = one;
        s->f24 = one;
    }
    s->fb8 = 0; s->fa8 = 0; s->fb0 = 0; s->b20 = 0; s->b18 = 0; s->fb4 = 0; s->fbc = 0; s->fac = 0;
}
