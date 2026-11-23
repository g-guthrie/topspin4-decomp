/* nearmiss: 4 off; blocker: scheduling of lfs f13,4(r4) (V3 tail) vs the memcpy arg setup li r5/addi r4/addi r3 - needs the original Matrix/Vector3 class definitions (operator= shape); tried arrays, M33 wrapper, void op=, POD tail (10 off), memcpy op= (26 off), perm_auto on the V3 helper. */
struct Q5sV3 {
    float x, y, z;
    Q5sV3 &operator=(const Q5sV3 &s) { float z_ = s.z, y_ = s.y, x_ = s.x; x = x_; y = y_; z = z_; return *this; }
    Q5sV3() {}
    Q5sV3(const Q5sV3 &s) : x(s.x), y(s.y), z(s.z) {}
};
struct Q5sM { float m[16]; };
struct Q5sBlk {
    Q5sV3 a, b, c;
    __declspec(align(16)) Q5sM m;
    float dx, dy, dz;
};
extern "C" void fn_88187B18(Q5sBlk *d, const Q5sBlk *s)
{
    *d = *s;
}
