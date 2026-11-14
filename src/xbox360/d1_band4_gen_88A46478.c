/* Swing_DLL.xex 0x88A46478-0x88A46F54, executable version 0.0.0.3. */

extern int fn_8841F080(char *, char *, char *, int, int, int, char *, int, int, int, int, int, int);
extern char lbl_8805C890[];
extern char lbl_88CDB644[];
extern char lbl_88046B18[];
extern char lbl_88CDC214[];
extern char lbl_88B93328[];
extern int lbl_88B8F504;
extern int lbl_88B8F46C;

void ts4_call_fn_88A46478(void)
{
    fn_8841F080(lbl_88CDC214, lbl_88046B18, lbl_88CDB644, 0, 0, 0, lbl_8805C890, 1, 0, 0, 0, 0, 0);
}

void ts4_store_globals_88A46F30(void)
{
    int v0 = lbl_88B8F504;
    int v1 = lbl_88B8F46C;
    *(int *)(lbl_88B93328 + 8) = v0;
    *(int *)(lbl_88B93328 + 32) = v1;
}
