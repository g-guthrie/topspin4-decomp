/* Emitter describe accessor. Byte-matches on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_describe.json. */
#include "vx1_vector.h"
#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif
typedef unsigned int u32;
typedef struct Ts4EmitClipInfo { char pad[0x40]; u32 f40; u32 f44; char pad48[0x10]; u32 f58; } Ts4EmitClipInfo;
typedef struct Ts4EmitterDesc {
    char pad[0xc]; Ts4EmitClipInfo *clip; char pad10[0x60]; const char *name;
    char pad74[0x12c]; __vector4 offset;
} Ts4EmitterDesc;
extern void fn_8816CAA0(void *dst, const char *s);
static __inline __vector4 ts4_vlen3_splat(const __vector4 *p)
{
    __vector4 d = __vmsum3fp(*p, *p);
    float s = __fsqrts(d.v[0]);
    return __vspltw(__lvlx(&s, 0), 0);
}
static __inline float ts4_vx(__vector4 v) { float f; __stvewx(v, &f, 0); return f; }

/* Swing_DLL.xex 0x88880750: copy the name and, when a clip is attached, its fields and the offset length. */
void ts4_emitter_describe_88880750(Ts4EmitterDesc *self, void *name_out, u32 *f40, float *len, u32 *f58, u32 *f44)
{
    Ts4EmitClipInfo *c;
    fn_8816CAA0(name_out, self->name);
    c = self->clip;
    if (c) {
        *f40 = c->f40;
        *len = ts4_vx(ts4_vlen3_splat(&self->offset));
        *f58 = c->f58;
        *f44 = c->f44;
    }
}
