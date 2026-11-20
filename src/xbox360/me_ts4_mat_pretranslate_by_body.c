/* 0x886633E8: pre-multiply the matrix in place by the translation to the body position (o->body + 0xa0):
 * m = T(pos) * m, the matrix taken by value so its rows load as li/lvx (af1_vector.h rule). */
#include "af1_vector.h"
typedef struct Body { char p[0xa0]; float pos[3]; } Body;
typedef struct Obj { char p[0x2c]; Body *body; } Obj;
AF1_FORCEINLINE Af1Mat translation(float x, float y, float z)
{
    __vector4 id = __vupkd3d(__vspltisw(0), 1);
    Af1Mat m;
    __vector4 t;
    t.v[0] = x;
    t.v[1] = y;
    t.v[2] = z;
    t.v[3] = 1.0f;
    m.r[3] = t;
    m.r[2] = __vpermwi(id, 174);
    m.r[1] = __vpermwi(id, 186);
    m.r[0] = __vpermwi(id, 234);
    return m;
}
AF1_FORCEINLINE Af1Mat mulv(Af1Mat a, Af1Mat b) { return af1_mat_mul(a, &b); }
void ts4_mat_pretranslate_by_body_886633E8(Obj *o, Af1Mat *m)
{
    const float *p = o->body->pos;
    Af1Mat t = translation(p[0], p[1], p[2]);
    Af1Mat r = mulv(t, *m);
    af1_mat_set(m, &r);
}
