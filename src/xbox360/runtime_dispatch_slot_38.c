typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

/* Swing_DLL.xex 0x88151538-0x88151548, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_dispatch_slot_38(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x38 / sizeof(ts4_dispatch_fn)](object);
}
