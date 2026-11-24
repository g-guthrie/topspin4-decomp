/* CX33: analyser-framework float helpers (Swing_DLL.xex 0x8890xxxx). */
typedef unsigned char u8;
typedef unsigned int u32;

extern float g_ts4_script_constants[];

/* range object: [lo, hi] with a reference at +8 */
typedef struct Cx33Range { float lo, hi, ref; } Cx33Range;

extern u8 ts4_input_wrapped_in_range_8890DF58(Cx33Range *r, const float *x);

/* 0x8890E300: scale a 3-vector by a script constant into a range and test x against it */
u8 ts4_range_contains_scaled_8890E300(const float *v, const float *x)
{
    float out[3];
    float k = g_ts4_script_constants[97];
    out[2] = v[2] * k;
    out[0] = v[0] * k;
    out[1] = v[1] * k;
    return ts4_input_wrapped_in_range_8890DF58((Cx33Range *)out, x);
}

