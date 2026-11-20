/* CX33: scaled-range clamp wrapper (Swing_DLL.xex 0x8890EFB0), sibling of 0x8890E300. */
typedef unsigned char u8;
typedef unsigned int u32;
extern float g_ts4_script_constants[];
typedef struct I13R { float lo, hi, ref; } I13R;
extern u8 fn_8890E238(I13R *r, const float *x);
u8 ts4_range_clamp_scaled_8890EFB0(const float *v, const float *x)
{
    float out[3];
    float k = g_ts4_script_constants[97];
    out[2] = v[2] * k;
    out[0] = v[0] * k;
    out[1] = v[1] * k;
    return fn_8890E238((I13R *)out, x);
}

