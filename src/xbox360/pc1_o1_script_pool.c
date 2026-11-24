/* PC1: functions in the /O1 regions (0x8828B..0x8828E) that read the script float-constant pool.
 *
 * The pool is declared per translation unit as a static const array; this is the only form that
 * reproduces the original `addi rX, REFLO pool; lfs fN, disp(rX)` access pattern (an extern
 * declaration does not).  The relocation still resolves to g_ts4_script_constants.
 *
 * Source: Swing_DLL.xex.  Build flags: /O1 (see work/specs/PC1/pc1_o1_script_pool.json).
 */
static const float g_ts4_script_constants[668] = {1.0f};

/* Float constant used as the rounding bias in the pack/convert helpers below. */
extern float lbl_8814B910;

/* Float results are returned as raw bits in r3 by these accessors. */
typedef union Ts4FloatBits {
    float f;
    unsigned u;
} Ts4FloatBits;

/* ---- plain field accessors on a large object ---- */

typedef struct Ts4ObjScaleA { char pad[0x2a50]; float value; } Ts4ObjScaleA;
typedef struct Ts4ObjScaleB { char pad[0x2904]; float value; } Ts4ObjScaleB;
typedef struct Ts4ObjScaleC {
    char pad0[0x10];
    unsigned long long flags;
    char pad1[0x2904 - 0x18];
    float value;
} Ts4ObjScaleC;
typedef struct Ts4ObjScaleD { char pad[0x296e]; unsigned short value; } Ts4ObjScaleD;
typedef struct Ts4ObjColor { char pad[0x28e0]; float c0, c1, c2, c3; } Ts4ObjColor;


/* Swing_DLL.xex 0x8828C020: (unsigned)(self+0x2904 float * pool[28] + bias). */
unsigned ts4_value_to_fixed_8828C020(Ts4ObjScaleB *self)
{
    return (unsigned)(self->value * g_ts4_script_constants[28] + lbl_8814B910);
}

/* Swing_DLL.xex 0x8828BFE8: store (float)x * pool[17] at +0x2904 and set flag bit 27 of the 64-bit word at +0x10. */
void ts4_set_scaled_value_flag_8828BFE8(Ts4ObjScaleC *self, unsigned x)
{
    volatile unsigned long long *flags = &self->flags;
    self->value = (float)x * g_ts4_script_constants[17];
    *flags |= 0x8000000ull;
}

/* Swing_DLL.xex 0x8828C208: (float)(u16 at +0x296e) * pool[75] as float bits. */
unsigned ts4_u16_scaled_bits_8828C208(Ts4ObjScaleD *self)
{
    Ts4FloatBits r;
    r.f = (float)(int)self->value * g_ts4_script_constants[75];
    return r.u;
}

/* Swing_DLL.xex 0x8828C118: pack four floats (+0x28e0..+0x28ec) scaled by pool[28] into a 4-byte value. */
unsigned ts4_pack_color_bytes_8828C118(Ts4ObjColor *self)
{
    unsigned b = (unsigned)(self->c1 * g_ts4_script_constants[28] + lbl_8814B910);
    unsigned g = (unsigned)(self->c2 * g_ts4_script_constants[28] + lbl_8814B910);
    unsigned r = (unsigned)(self->c0 * g_ts4_script_constants[28] + lbl_8814B910);
    unsigned a = (unsigned)(self->c3 * g_ts4_script_constants[28] + lbl_8814B910);
    return (a << 24) | ((r & 0xff) << 16) | ((b & 0xff) << 8) | (g & 0xff);
}

/* ---- signed bitfield getters on 0x18-byte entries starting at the object base ---- */

typedef struct Ts4SlotEntry {
    char pad[0x10];
    struct { int lo : 10; int value : 10; int rest : 12; } w10;
    struct { int lo : 23; int value : 4; int rest : 5; } w14;
} Ts4SlotEntry;
typedef struct Ts4SlotTable { char pad0[0x18]; unsigned long long dirty; } Ts4SlotTable;


