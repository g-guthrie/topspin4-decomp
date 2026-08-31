typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);

/* Swing_DLL.xex 0x88170E28. */
void *ts4_allocate_zeroed_triplets(int count)
{
    u32 *value = (u32 *)fn_88613268(lbl_88D45B38, count * 12 + 4, 4, 0, 0);
    if (value != 0) {
        int i;
        u32 *current = value;
        for (i = count - 1; i >= 0; i--) {
            current[0] = 0;
            current[1] = 0;
            current[2] = 0;
            current += 3;
        }
        return value;
    }
    return 0;
}
