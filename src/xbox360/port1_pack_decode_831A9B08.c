/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_pack_decode_831A9B08.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */


extern float lbl_8802C1D4;
extern float lbl_88091E18;

/* Swing_DLL.xex 0x885A4758 */
float ts4_decode_s24_scaled_885A4758(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 8) * lbl_8802C1D4;
}

/* Swing_DLL.xex 0x885BC658 */
float ts4_decode_s20_scaled_885BC658(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 12) * lbl_88091E18;
}

