typedef unsigned int u32;
typedef unsigned long uintptr_t;

extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_887855B8(void *memory, void *argument);

void *fn_88215940(void *argument)
{
    void *memory = (void *)(uintptr_t)fn_88613268(
        lbl_88D45B38, 0x878, 4, 0, 2);

    if (memory != 0) {
        return fn_887855B8(memory, argument);
    }
    return 0;
}