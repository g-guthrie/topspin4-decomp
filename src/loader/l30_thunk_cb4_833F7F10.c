/* Loader_DLL.xex 0x833F7F10-0x833F7F50, executable version 0.0.0.3. */
extern void fn_833EA5D8(void);
extern int fn_833F7D60(void *cb, int a, int b, int c, int d);
extern void fn_833EDDC0(void);
extern void fn_833EEC88(void);

int ts4l_thunk_cb4_833F7F10(int a, int b, int c, int d)
{
    return fn_833F7D60((void *)fn_833EA5D8, a, b, c, d);
}

int ts4l_thunk_cb4_833F7F30(int a, int b, int c, int d)
{
    return fn_833F7D60((void *)fn_833EDDC0, a, b, c, d);
}

int ts4l_thunk_cb4_833F7F50(int a, int b, int c, int d)
{
    return fn_833F7D60((void *)fn_833EEC88, a, b, c, d);
}
