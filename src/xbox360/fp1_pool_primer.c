/*
 * FP1: LTCG context only (not a matched function). Uses, in order, the constants that occupy the
 * first 0x68 bytes of the module constant pool g_ts4_script_constants (Swing_DLL.xex 0x880D0F70),
 * so that in a scratch `link /LTCG` the pool starts with 1.0f at +0 and the compiler-generated
 * +1/-1 select table lands at +0x68, as in the original. The pool layout is a whole-program
 * artefact; this file only stands in for it. Values are the raw words of the original pool.
 */
void fp1_pool_primer(float *o, double *d, float x, double y)
{
    o[0] = x + 1.0f;
    o[1] = x * 3.0517578125e-05f;
    d[0] = y * 3.0;
    d[1] = y * 0.5;
    d[2] = y * 16.0;
    o[2] = x * 100.0f;
    o[3] = x * 0.006f;
    o[4] = x * 42560.0f;
    o[5] = x * 89600.0f;
    o[6] = x * 1.08333e-06f;
    o[7] = x * 90.0f;
    o[8] = x * -1.0f;
    o[9] = x * 1000.0f;
    o[10] = x * 32.0f;
    o[11] = x * (1.0f / 255.0f);
    o[12] = x * 0.05f;
    o[13] = x * 3.0f;
    o[14] = x * 3.402823466e+38f;
    o[15] = x * 0.025f;
    d[3] = y * 0.0;
    o[16] = x * 7.0f;
    o[17] = x * 12.0f;
}
