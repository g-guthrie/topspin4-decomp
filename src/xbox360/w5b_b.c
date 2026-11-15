/* W5B batch B */
static const float w5b_zero = 0.0f;
static __inline float w5b_min(float a, float b) { return (a - b >= w5b_zero) ? b : a; }
static __inline float w5b_max(float a, float b) { return (a - b >= w5b_zero) ? a : b; }

extern float fn_8869C868(void *p);

typedef struct W5bCfg { unsigned char pad00[0x5a0]; float cap; } W5bCfg;
typedef struct W5bOwner { unsigned char pad00[0x74]; W5bCfg *cfg_dummy; } W5bOwner;
typedef struct W5bIn { unsigned char pad00[0x10]; unsigned char *owner; unsigned pad14; void *src; } W5bIn;

void ts4_clamp_cap_886A48B8(W5bIn *o)
{
    W5bCfg *c = *(W5bCfg **)(o->owner + 0x74);
    float v = fn_8869C868(o->src);
    c->cap = w5b_min(v, c->cap);
}

void ts4_approach_step_8867C128(float *p, float target)
{
    float cur = *p;
    *p = w5b_min(w5b_max(target - cur, -0.01f), 0.01f) + cur;
}
