/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l10_worker_clamp_o1_833E2480.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef long ts4_word;

ts4_word fn_88569360();
ts4_word fn_88575A28();

/* Swing_DLL.xex 0x885694D0 */
ts4_word ts4_call_worker_clamp_885694D0(ts4_word p0, ts4_word p1, ts4_word p2, ts4_word p3, ts4_word p4)
{
    ts4_word r = fn_88569360((ts4_word)fn_88575A28, p0, p1, p2, p3, p4);
    return r < 0 ? -1 : r;
}

