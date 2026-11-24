/* Swing_DLL.xex 0x8830B840: copies four optional Vec3 outputs (+0x00, +0x18, +0x48, +0x30) from slot i (0x70 bytes each,
 * array at +0x51A0, 4 slots); 0x25 when i is out of range. agAE: /Oc. */
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Slot { Vec3 a; char padc[0xc]; Vec3 b; char pad24[0xc]; Vec3 d; char pad3c[0xc]; Vec3 c; char pad54[0x70 - 0x54]; } Slot;
typedef struct Rig { char pad[0x51a0]; Slot slots[4]; } Rig;
int fn_8830B840(Rig *r, int i, Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d)
{
    if (i < 0 || i >= 4) return 0x25;
    if (a) *a = r->slots[i].a;
    if (b) *b = r->slots[i].b;
    if (c) *c = r->slots[i].c;
    if (d) *d = r->slots[i].d;
    return 0;
}
