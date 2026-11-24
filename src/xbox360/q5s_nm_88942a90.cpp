/* 0x88942A90: Ts4PointOwner::GetPoint - copy point i of the owner's Vec3 array into out when the array
 * exists and i is in range; returns true on success.
 * Byte-exact only with the value built as a Ts4Vec3 temporary (3-float ctor) and assigned through an
 * inline member-wise operator=: that gives the target's x,y,z load order (f0,f13,f12) and x,y,z store
 * order. A plain struct copy, a set(x,y,z) helper or direct field stores reorder the loads or stores. */
struct Ts4Vec3 {
    float x, y, z;
    Ts4Vec3() {}
    Ts4Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Ts4Vec3 &operator=(const Ts4Vec3 &o) { x = o.x; y = o.y; z = o.z; return *this; }
};

struct Ts4Vec3Array {
    Ts4Vec3 *data; /* +0x0 */
    int count;     /* +0x4 */
};

struct Ts4PointOwner {
    void *vtable;          /* +0x0 */
    Ts4Vec3Array *points;  /* +0x4 */
    bool GetPoint(int i, Ts4Vec3 &out) const;
};

bool Ts4PointOwner::GetPoint(int i, Ts4Vec3 &out) const
{
    Ts4Vec3Array *a = points;
    if (a && i >= 0 && i < a->count) {
        out = Ts4Vec3(a->data[i].x, a->data[i].y, a->data[i].z);
        return true;
    }
    return false;
}
