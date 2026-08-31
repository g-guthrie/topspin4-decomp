typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

/* Swing_DLL.xex 0x8815EFC0-0x8815EFE8, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_type_code_none(void)
{
    return 0;
}

ts4_u32 ts4_runtime_dispatch_slot_3c(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x3c / sizeof(ts4_dispatch_fn)](object);
}

ts4_u32 ts4_runtime_dispatch_slot_4c(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x4c / sizeof(ts4_dispatch_fn)](object);
}
