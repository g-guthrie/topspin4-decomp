/* W5B batch C */
static const float w5b_zero = 0.0f;
static __inline float w5b_min(float a, float b) { return (a - b >= w5b_zero) ? b : a; }
static __inline float w5b_max(float a, float b) { return (a - b >= w5b_zero) ? a : b; }
extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif

typedef struct W5cSub {
    unsigned char pad00[0x544];
    float v544;
    unsigned char pad548[0x1044 - 0x548];
    float avg;                  /* +0x1044 */
    unsigned count;             /* +0x1048 */
} W5cSub;
typedef struct W5cObj {
    unsigned char pad00[0x74];
    W5cSub *sub;
    unsigned char pad78[0x344 - 0x78];
    float acc;                  /* +0x344 */
} W5cObj;

void ts4_accumulate_abs_avg_8867A710(W5cObj *o)
{
    W5cSub *s = o->sub;
    float d, x;
    d = s->v544;
    d = (float)fabs(d);
    s->count++;
    x = w5b_min(w5b_max(d, 0.0f), 1.0f);
    o->acc = x + o->acc;
    if (s->count != 0)
        o->sub->avg = o->acc / (float)s->count;
}
