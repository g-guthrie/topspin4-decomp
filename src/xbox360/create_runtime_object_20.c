typedef unsigned int u32;

extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_889270C0(void);

/* Swing_DLL.xex 0x881716F0. */
void *ts4_create_runtime_object_20(void)
{
    if (fn_88613268(lbl_88D45B38, 0x20, 4, 0, 2) != 0) {
        return fn_889270C0();
    }
    return 0;
}
