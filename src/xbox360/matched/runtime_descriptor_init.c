/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned int ts4_u32;

ts4_u32 *ts4_runtime_fill_record12_8841f080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored,
    ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10)
{
    (void)ignored;
    record[0] = a0;
    record[1] = a1;
    record[2] = a2;
    record[3] = a3;
    record[4] = a4;
    record[5] = a5;
    record[6] = a6;
    record[7] = a7;
    record[8] = a8;
    record[9] = a9;
    record[10] = a10;
    record[11] = 0;
    return record;
}
