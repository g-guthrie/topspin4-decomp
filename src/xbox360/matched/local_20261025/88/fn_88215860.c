typedef unsigned int u32;
extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_88785A00(void *memory, void *argument);

void *fn_88215860(void *argument)
{
    void *memory = (void *)fn_88613268(lbl_88D45B38, 0x230, 4, 0, 2);

    if (memory != 0) {
        return fn_88785A00(memory, argument);
    }
    return 0;
}