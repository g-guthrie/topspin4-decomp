/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

/* Swing_DLL.xex 0x8828C658-0x8828C660, executable version 0.0.0.3. */
ts4_u32 fn_8828C658(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x2F00);
}
