/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

/* 0x88197898-0x881978A8 (compiled). Slot +0x34 of installed vtable 0x880DD528.
 * Same instruction shape as matched ts4_runtime_dispatch_slot_38.
 * ABI (resolved): 0x880DD528 is the only table holding this wrapper (sole
 * data word 0x880DD55C), so the dispatched slot +0x28 is always that table's
 * entry 0x88197838 (`return [this+0x88] - [this+0x8C]`), which reads r3 only.
 * The one-argument prototype therefore loses no argument. */
ts4_u32 ts4_runtime_dispatch_slot_28(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x28 / sizeof(ts4_dispatch_fn)](object);
}

/* 0x881A53C0-0x881A53C8 (compiled, runtime). Slot +0x40 of installed vtable 0x880DF1F8.
 * Same shape as matched ts4_runtime_record_get_word_90. */
ts4_u32 ts4_runtime_record_get_word_24c(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x24c);
}

/* 0x88606B10-0x88606B18 (compiled). Shared slot of twelve table words
 * (0x880DF3D4, 0x880F7994, 0x880F7BD4, 0x880F7E94, 0x880F80C4, 0x880F8124,
 * 0x880F8214, 0x880F82D4, 0x880F838C, 0x880F8414, 0x880F8494, 0x880F85A4).
 * Same shape as matched ts4_runtime_type_code_none. */
ts4_u32 ts4_runtime_slot_return_zero_606b10(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887EFC70-0x887EFC74. */
void ts4_runtime_slot_no_op_7efc70(void *object)
{
    (void)object;
}

/* Swing_DLL.xex 0x88864D18-0x88864D1C. */
void ts4_runtime_slot_no_op_864d18(void *object)
{
    (void)object;
}

/* 0x8827F030-0x8827F044 (compiled, runtime). Slot +0xAC of vtable 0x880F8188
 * and slot +0x18 of vtable 0x880F85AC: load the child object at +0x14 and
 * dispatch its vtable slot +0x18 with the child as `this`.
 * PROTOTYPE UNRESOLVED: the machine code leaves r4-r10 and f1-f13 untouched,
 * so the child slot receives every argument of the caller. The child's class
 * is not recovered (the 0x880F85AC factory 0x88281B00 copies it from a
 * caller-supplied pointer into +0x14), so the slot's arity is unknown. The
 * one-argument function type below is a placeholder; a compiled C call with
 * it is not guaranteed to preserve r4 and above. */
ts4_u32 ts4_runtime_child_14_dispatch_slot_18(void *object)
{
    void *child = *(void **)((ts4_u8 *)object + 0x14);
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)child;
    return dispatch[0x18 / sizeof(ts4_dispatch_fn)](child);
}
