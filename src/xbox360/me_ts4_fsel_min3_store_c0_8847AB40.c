/* 0x8847AB40: min(in[0], in[5], in[10]) through two fsel steps, stored to +0xc0/+0xc4/+0xc8 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float a, float b, float c) { return a >= 0 ? b : c; }
#endif
typedef struct { float v; float pad[4]; float lo; float pad2[4]; float hi; } In;
typedef struct { char pad[0xc0]; float a, b, c; } O;
void ts4_fsel_min3_store_c0_8847AB40(O *o, In *in)
{
    float lo = in->lo, v = in->v;
    float t = __fself(v - lo, lo, v);
    t = __fself(t - in->hi, in->hi, t);
    o->a = t; o->b = t; o->c = t;
}
