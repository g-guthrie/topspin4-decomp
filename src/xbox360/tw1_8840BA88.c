/* Swing_DLL.xex 0x8840BA88: byte-swap a float through a stack union */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef union Ts4Word32 {
    float f;
    ts4_u32 u;
    ts4_u8 b[4];
} Ts4Word32;

float ts4_swap_float_bytes_8840BA88(float value)
{
    Ts4Word32 in, out;
    in.f = value;
    out.b[0] = in.b[3];
    out.b[1] = in.b[2];
    out.b[2] = in.b[1];
    out.b[3] = in.b[0];
    return out.f;
}
