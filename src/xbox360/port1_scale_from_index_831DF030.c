/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_scale_from_index_831DF030.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */


/* Index-to-linear scale: 2^(n/4)-style division/multiplication of a table entry,
 * clamped to the valid index range. */
extern float lbl_8809D7C0[];
extern float lbl_8809D8E0[];

/* Swing_DLL.xex 0x885D47F0 */
float ts4_scale_from_index_885D47F0(int n)
{
    if (n <= 0) {
        if (n < -0x48)
            n = -0x47;
        return lbl_8809D7C0[-n] / (float)(1 << (-n >> 2));
    }
    if (n >= 0x3e)
        n = 0x3e;
    return (float)(1 << (n >> 2)) * lbl_8809D8E0[n - 1];
}

