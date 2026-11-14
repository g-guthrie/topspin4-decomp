/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_audio_helpers_831BD408.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */




/* Swing_DLL.xex 0x885BFE48 */
void ts4_store_scaled_sample_885BFE48(int a, float *out, char *o, int idx)
{
    out[idx] = (float)a / (float)(1 << (*(unsigned short *)(o + 0x6e) - 1));
}

