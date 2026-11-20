/* Loader_DLL.xex 0x834302D0-0x83430314, 0x83477528-0x8347756C, executable version 0.0.0.3. */
/* 4-float vector subtraction returned by value (two identical copies in separate translation units). */
struct Ts4lV4 {
    float x, y, z, w;
    Ts4lV4() {}
    Ts4lV4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    Ts4lV4 operator-(const Ts4lV4 &o) const { return Ts4lV4(x - o.x, y - o.y, z - o.z, w - o.w); }
};
extern "C" Ts4lV4 ts4l_v4_sub_834302D0(const Ts4lV4 &p, const Ts4lV4 &q) { return p - q; }
extern "C" Ts4lV4 ts4l_v4_sub_83477528(const Ts4lV4 &p, const Ts4lV4 &q) { return p - q; }
