/* rough draft 0x886E6470 (ME agent B): 165 off (/Oc). Sibling of 0x886E6BE8 (same Rig): keeps follow points
 * outside bone collision spheres (radius_sq at +0xC8), re-attaching a detached point to the first bone in its
 * ref list that contains it. Structure from the disassembly; not tuned. */
#include "ts4_vector.h"
extern float g_ts4_event_value;
extern double sqrt(double);
#pragma intrinsic(sqrt)
typedef struct Follow { __vector4 pos; char p10[0x10]; __vector4 off; unsigned int bone; int ref; char p38[8]; } Follow;
typedef struct Bone { char p[0x40]; __vector4 to_world[4]; __vector4 to_local[4]; float push; char pc4[4]; float radius_sq; char pcc[4]; } Bone;
typedef struct BoneRef { unsigned int index; char p[0xc]; } BoneRef;
typedef struct Rig { char p[0x20]; Bone *bones; unsigned int nbones; BoneRef *refs; char p2c[0x40 - 0x2c]; Follow *follows; unsigned int count; } Rig;
static __inline __vector4 xform(__vector4 v, __vector4 *m)
{
    __vector4 r = __vmaddfp(m[2], __vspltw(v, 2), m[3]);
    r = __vmaddfp(__vspltw(v, 1), m[1], r);
    return __vmaddfp(__vspltw(v, 0), m[0], r);
}
static __inline __vector4 push_out(__vector4 p, float l, float r2)
{
    float y = p.v[1];
    float s = (float)sqrt((r2 - y * y) / (l - y * y));
    __vector4 q = __vmulfp(p, __vspltw(__lvlx(&s, 0), 0));
    return __vrlimi(q, __lvlx(&y, 0), 4, 3);
}
void fn_886E6470(Rig *self)
{
    unsigned int i;
    for (i = 0; i < self->count; i++) {
        Follow *f = &self->follows[i];
        if (f->bone < self->nbones) {
            Bone *b = &self->bones[f->bone];
            __vector4 off = f->off;
            __vector4 d = __vsubfp(xform(f->pos, b->to_local), off);
            __vector4 t = __vmsum3fp(off, d);
            float dot = t.v[0];
            if (dot < g_ts4_event_value) {
                __vector4 oo = __vmsum3fp(off, off), dd = __vmsum3fp(d, d);
                if (oo.v[0] - dot * dot / dd.v[0] < b->radius_sq) {
                    __vector4 o2 = __vmaddfp(d, __vspltw(__lvlx(&b->push, 0), 0), off);
                    __vector4 l = __vmsum3fp(o2, o2);
                    if (l.v[0] < b->radius_sq)
                        o2 = push_out(o2, l.v[0], b->radius_sq);
                    f->off = o2;
                    f->pos = xform(o2, b->to_world);
                    goto next;
                }
            }
            f->bone = self->nbones;
        }
    next:
        if (f->bone == self->nbones) {
            int j;
            for (j = f->ref; self->refs[j].index < self->nbones; j++) {
                Bone *b = &self->bones[self->refs[j].index];
                __vector4 p = xform(f->pos, b->to_local);
                __vector4 l = __vmsum3fp(p, p);
                if (l.v[0] < b->radius_sq) {
                    __vector4 q;
                    f->bone = self->refs[j].index;
                    q = push_out(p, l.v[0], b->radius_sq);
                    f->off = q;
                    f->pos = xform(q, b->to_world);
                    break;
                }
            }
        }
    }
}
