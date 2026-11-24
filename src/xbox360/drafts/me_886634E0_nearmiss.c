/* agentA2 (2026-11-18 tips pass): volatile matrix read keeps 19 off; custom mul with volatile row loads grows size (0x140-0x148). */
/* NEAR MISS 0x886634E0: 19 off (LTCG): vector register numbering only (target allocates m.r[0] before the splats). Sibling of matched 0x886633E8. 7 variants. */
/* 0x886634E0: pre-multiply the matrix in place by a Y rotation of the object's yaw: m = R_y(yaw) * m. */
#include "af1_vector.h"
struct Ts4Basis { float x[4]; float y[4]; float z[4]; };
void ts4_basis_rotate_y_8864ED80(struct Ts4Basis *m, float angle);
typedef struct Obj { char p[0x64]; float yaw; } Obj;

AF1_FORCEINLINE Af1Mat identity(void)
{
    __vector4 id = __vupkd3d(__vspltisw(0), 1);
    Af1Mat m;
    m.r[0] = __vpermwi(id, 234);
    m.r[1] = __vpermwi(id, 186);
    m.r[2] = __vpermwi(id, 174);
    m.r[3] = __vpermwi(id, 171);
    return m;
}
AF1_FORCEINLINE Af1Mat mulv(Af1Mat a, Af1Mat b) { return af1_mat_mul(a, &b); }

void ts4_mat_prerotate_yaw_886634E0(Obj *o, Af1Mat *m)
{
    __vector4 id = __vupkd3d(__vspltisw(0), 1);
    Af1Mat r;
    Af1Mat x;
    r.r[0] = __vpermwi(id, 234);
    r.r[1] = __vpermwi(id, 186);
    r.r[2] = __vpermwi(id, 174);
    r.r[3] = __vpermwi(id, 171);
    ts4_basis_rotate_y_8864ED80((struct Ts4Basis *)&r, o->yaw);
    x = mulv(r, *m);
    af1_mat_set(m, &x);
}
