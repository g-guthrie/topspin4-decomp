/* Swing_DLL.xex 0x8864E640: Ts4PosObject8864E640::AddPosition: adds (dx, dy, dz) to the position vector at +0x30.
 * Matched on /Oc as a C++ member that indexes the position through Vec3::operator[] (float& into the
 * component array): the member puts the parameter first in each fadds (docs/agents/regalloc.md C1
 * member rule), and the indexed float& keeps each load after the previous store. Plain `pos.x += dx`
 * hoists the y/z loads (7 off); the C form with the object first gives (field, param) operands. */
struct Ts4Vec3 {
    float x, y, z;

    float &operator[](int i) { return (&x)[i]; }
};

struct Ts4PosObject8864E640 {
    char pad00[0x30];
    Ts4Vec3 pos; /* +0x30 */

    void AddPosition(float dx, float dy, float dz);
};

void Ts4PosObject8864E640::AddPosition(float dx, float dy, float dz)
{
    pos[0] += dx;
    pos[1] += dy;
    pos[2] += dz;
}
