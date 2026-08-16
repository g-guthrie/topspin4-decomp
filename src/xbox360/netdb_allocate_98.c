typedef unsigned int u32;

extern void *lbl_88D45B38;
extern void *fn_8860D250(void *context);
extern void fn_88613570(void *context, u32 byte_count, u32 alignment, void *output);

/* Swing_DLL.xex 0x88152C98. */
void ts4_netdb_allocate_98(void *output, u32 element_count)
{
    void *context;

    if (lbl_88D45B38 != 0) {
        context = fn_8860D250(lbl_88D45B38);
    } else {
        context = 0;
    }
    fn_88613570(context, element_count * 0x98, 4, output);
}
