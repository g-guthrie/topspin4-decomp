/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned char ts4_u8;

/* Swing_DLL.xex 0x883BAB88-0x883BAB98, executable version 0.0.0.3. */
ts4_u8 ts4_object_byte5_bit0_883bab88(const void *holder)
{
    return (*(const ts4_u8 *const *)holder)[5] & 0x01;
}

/* Swing_DLL.xex 0x883BAB98-0x883BABA8, executable version 0.0.0.3. */
ts4_u8 ts4_object_byte5_bit1_883bab98(const void *holder)
{
    return (*(const ts4_u8 *const *)holder)[5] & 0x02;
}

/* Swing_DLL.xex 0x883BABA8-0x883BABB8, executable version 0.0.0.3. */
ts4_u8 ts4_object_byte5_bit2_883baba8(const void *holder)
{
    return (*(const ts4_u8 *const *)holder)[5] & 0x04;
}
