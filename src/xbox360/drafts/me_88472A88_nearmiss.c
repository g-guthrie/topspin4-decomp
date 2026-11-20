/* 0x88472A88: Takes the minimum of three floats; stores min * lbl_880026EC into +0x48 when it is below lbl_88001978, else lbl_88029278. */
/* Near miss (agAH): /Oc, 1 instruction off: fmuls operands come out (K, m) where the target has (m, K); operand swap, a helper, (float) casts, extern order and 0-8 operand_order_pad locals all leave it. */
extern const float lbl_88001978;
extern const float lbl_880026EC;
extern const float lbl_88029278;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Scaled { char pad[0x48]; float scale; } Scaled;

static float MinF(float a, float b) { return a - b >= 0.0f ? b : a; }

void fn_88472A88(Scaled *o, const Vec3 *v)
{
    float m = MinF(MinF(v->x, v->y), v->z);
    if (m < lbl_88001978)
        o->scale = m * lbl_880026EC;
    else
        o->scale = lbl_88029278;
}
