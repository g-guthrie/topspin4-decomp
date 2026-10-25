/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned int ts4_u32;

extern ts4_u32 fn_8862E858(void *object, ts4_u32 argument);
extern ts4_u32 fn_883C72E0(void *object, ts4_u32 argument, ts4_u32 flag);

/* Swing_DLL.xex 0x8862EAE8-0x8862EAF0. */
ts4_u32 ts4_runtime_call_8862e858_with_zero(void *object)
{
    return fn_8862E858(object, 0);
}

/* Swing_DLL.xex 0x883CC1E8-0x883CC1F0. */
ts4_u32 ts4_runtime_call_883c72e0_with_flag(void *object, ts4_u32 argument)
{
    return fn_883C72E0(object, argument, 1);
}
