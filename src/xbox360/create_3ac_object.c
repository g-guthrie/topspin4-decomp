typedef unsigned int u32;
#if defined(__clang__)
typedef unsigned long uintptr_t;
#else
typedef unsigned int uintptr_t;
#endif

extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_8879A038(void *memory, void *argument);

/* Swing_DLL.xex 0x88154598. */
void *ts4_create_3ac_object(void *argument)
{
    void *memory = (void *)(uintptr_t)fn_88613268(
        lbl_88D45B38, 0x3AC, 4, 0, 2);

    if (memory != 0) {
        return fn_8879A038(memory, argument);
    }
    return 0;
}
