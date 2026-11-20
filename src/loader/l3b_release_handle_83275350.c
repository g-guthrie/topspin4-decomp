/* Loader_DLL.xex 0x83275350-0x8328B300, executable version 0.0.0.3.
 * Handle owners: release a held object once and clear the slot. */

extern void fn_832863B0(void *);
extern void fn_8333E6C0(void *);
extern void fn_8333E5D8(void *);
extern void fn_83275540(void *);

void ts4l_release_handle_83275350(void **o)
{
    if (o != 0 && *o != 0) {
        fn_832863B0(*o);
        *o = 0;
    }
}

void ts4l_destroy_members_8328B300(char *o)
{
    fn_8333E6C0(o + 4);
    fn_8333E5D8(o + 16);
    fn_8333E5D8(o + 28);
    fn_8333E5D8(o + 40);
    fn_83275540(o + 52);
    if (o != 0 && *(void **)o != 0) {
        fn_832863B0(*(void **)o);
        *(void **)o = 0;
    }
}
