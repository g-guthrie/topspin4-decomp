typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);

/* Swing_DLL.xex 0x88170DC0. */
void *ts4_create_zeroed_triplet(void)
{
    u32 *value = (u32 *)fn_88613268(lbl_88D45B38, 0xC, 4, 0, 2);
    if (value != 0) {
        value[0] = 0;
        value[1] = 0;
        value[2] = 0;
        return value;
    }
    return 0;
}
