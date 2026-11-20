/*
 * PP1: integrate a rate into a float value (Swing_DLL.xex 0x888ADD78).
 * o->rel is a self-relative handle: the rate block lives at rel + *(int *)rel. The value grows by
 * rate * dt (one fmadds), is floored (below 1e-6 it is reset to 1e-5) and the object is marked dirty.
 *
 * LTCG route. Both float constants come from the module constant pool (g_ts4_script_constants+0x300
 * and +0x310); context src/xbox360/pp1_pool_primer.c, listed last, lays the pool out at the original
 * offsets (docs/agents/near-misses/PP1.md). The floor goes through an inline helper that re-reads the
 * value it was passed: the late load removal turns that read into the target's dead `fmr f11,f12`
 * (the float form of the CL1 clrrwi copy).
 */
#if defined(__clang__) || defined(__GNUC__)
typedef long pp1_handle;         /* host syntax check: pointer-sized */
#else
typedef int pp1_handle;
#endif

typedef struct Pp1RateBlock {
    unsigned char pad00[0xb4];
    float rate;                 /* +0xb4 */
} Pp1RateBlock;

typedef struct Pp1RateValue {
    unsigned char pad00[0x08];
    pp1_handle rel;             /* +0x08: self-relative handle, 0 = none (signed: cmpwi) */
    unsigned char pad0c[0x37 - 0x0c];
    unsigned char dirty;        /* +0x37 */
    unsigned char pad38[0xb0 - 0x38];
    float value;                /* +0xb0 */
} Pp1RateValue;

static __inline void pp1_floor_reset(float *p, float lo, float reset)
{
    if (*p < lo)
        *p = reset;
}

void ts4_value_integrate_rate_888ADD78(Pp1RateValue *o, float dt)
{
    pp1_handle rel = o->rel;
    if (rel == 0)
        return;
    o->value = ((Pp1RateBlock *)(rel + *(int *)rel))->rate * dt + o->value;
    pp1_floor_reset(&o->value, 1e-06f, 1e-05f);
    o->dirty = 1;
}
