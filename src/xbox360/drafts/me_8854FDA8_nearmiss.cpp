/* 0x8854FDA8: Returns true when the largest absolute component of a Vec3 is within tol of lbl_88001A68 (unit-length test by max norm). */
/* Near miss (agAH, C++ /Oc): the body matches; the target also has a dead store of lbl_88001A20 to -4(r1) (lis/lfs/stfs, 3 instructions) that no tried source keeps. Must be C++: the float fabs overload removes the frsp that C emits. */
extern "C" float __fself(float, float, float);
#pragma intrinsic(__fself)
extern "C" double fabs(double);
#pragma intrinsic(fabs)
inline float fabs(float x) { return (float)fabs((double)x); }
struct Vec3 { float x, y, z; };
extern "C" const float lbl_88001A68;
extern "C" bool fn_8854FDA8(const Vec3 *v, float tol)
{
    float x = fabs(v->x);
    float y = fabs(v->y);
    float z = fabs(v->z);
    float m = __fself(x - y, x, y);
    m = __fself(z - m, z, m);
    return fabs(m - lbl_88001A68) < tol;
}
