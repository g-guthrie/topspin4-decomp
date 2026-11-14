/* Swing_DLL.xex 0x883CEF48-0x883CEFA8, executable version 0.0.0.3. */
typedef struct Ts4Ob2M7 { char pad0[0x18]; float f18; char pad1c[0x10]; float f2c; float f30; char pad34[4]; struct { char pad[0xac]; int *p; } *g; } Ts4Ob2M7;

int ts4_lerp_883CEF48(Ts4Ob2M7 *o, float *out)
{
    int *p = o->g->p;
    unsigned int v = p != 0 ? *p : 0;
    float a, b;
    if (v == 0)
        return 0x24;
    if (out == 0)
        return 0x25;
    a = o->f2c;
    b = o->f30;
    *out = (b - a) * o->f18 + a;
    return 0;
}
