typedef unsigned int u32;

extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_8892AFF0(void);

/* Swing_DLL.xex 0x88170A58. */
void *ts4_create_container_factory(void)
{
    if (fn_88613268(lbl_88D45B38, 0x54, 4, 0, 2) != 0) {
        return fn_8892AFF0();
    }
    return 0;
}
