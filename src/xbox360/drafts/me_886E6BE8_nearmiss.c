/* rough draft 0x886E6BE8 (ME agent B): 97 off (/Oc). Follow-point lerp toward a target, snapping (w = 1) when
 * the bone-space directions are within the bone's cone. */
#include "ts4_vector.h"
typedef struct Target { __vector4 pos; } Target;
typedef struct Follow { __vector4 pos; char p10[0x34 - 0x10]; int bone; float rate; char p3c[0x40 - 0x3c]; } Follow;
typedef struct Bone { char p[0x80]; __vector4 m[4]; char pc0[0xcc - 0xc0]; float cone; } Bone;
typedef struct BoneRef { int index; char p[0xc]; } BoneRef;
typedef struct Rig { char p[0x20]; Bone *bones; char p24[0x28 - 0x24]; BoneRef *refs; char p2c[0x30 - 0x2c]; Target *targets; char p34[0x40 - 0x34]; Follow *follows; unsigned int count; } Rig;
extern float g_ts4_event_value;
extern const float g_ts4_script_constants[];
static __inline __vector4 transform(__vector4 v, Bone *b)
{
    __vector4 r = __vmaddfp(b->m[2], __vspltw(v, 2), b->m[3]);
    r = __vmaddfp(__vspltw(v, 1), b->m[1], r);
    return __vmaddfp(__vspltw(v, 0), b->m[0], r);
}
static __inline __vector4 normalize3(__vector4 v, __vector4 zero, __vector4 half)
{
    __vector4 l = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(l);
    __vector4 z = __vcmpeqfp(l, zero);
    r = __vmaddfp(r, __vnmsubfp(__vmulfp(l, half), __vmulfp(r, r), half), r);
    return __vsel(__vmulfp(v, r), l, z);
}
void fn_886E6BE8(Rig *self)
{
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        Follow *f = &self->follows[i];
        Target *t = &self->targets[i];
        Bone *b = &self->bones[self->refs[f->bone].index];
        float w = f->rate;
        if (b->cone < g_ts4_event_value) {
            __vector4 zero = __vspltisw(0);
            __vector4 half = __vcfsx(__vspltisw(1), 1);
            __vector4 ev = __lvlx(&g_ts4_event_value, 0);
            __vector4 tp = __vrlimi(transform(t->pos, b), ev, 4, 3);
            __vector4 fp = __vrlimi(transform(f->pos, b), ev, 4, 3);
            __vector4 d = __vmsum3fp(normalize3(fp, zero, half), normalize3(tp, zero, half));
            if (d.v[0] < b->cone)
                w = g_ts4_script_constants[0];
        }
        {
            __vector4 p = f->pos;
            f->pos = __vmaddfp(__vsubfp(t->pos, p), __vspltw(__lvlx(&w, 0), 0), p);
        }
    }
}
