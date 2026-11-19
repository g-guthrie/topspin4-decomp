/* 0x884C0EE8: fsel(v, v, lbl_88001A20) of d->v (+0xc), negated first when c->on and o->flip */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
#ifdef _MSC_VER
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
#else
static float __fself(float a, float b, float c) { return a >= 0 ? b : c; }
#endif
extern const float lbl_88001A20;
typedef struct { char pad[0x14]; unsigned char flip; } O;
typedef struct { char pad[0xcc]; unsigned char on; } C;
typedef struct { char pad[0xc]; float v; } D;
float ts4_fsel_clamp_signed_884C0EE8(O *o, int b, C *c, D *d)
{
    if (c->on && o->flip) { float n = -d->v; return __fself(n, n, lbl_88001A20); }
    return __fself(d->v, d->v, lbl_88001A20);
}
