/* Loader_DLL.xex 0x833F7F70-0x833F7FB0, executable version 0.0.0.3. */
extern void fn_833EA5D8(void);
extern int fn_833F7D60(void *cb, int a, int b, int c, int d);
extern void fn_833EDDC0(void);
extern void fn_833EEC88(void);

int ts4l_thunk_cb4z_833F7F70(int a, int b, int c)
{
    return fn_833F7D60((void *)fn_833EA5D8, a, b, 0, c);
}

int ts4l_thunk_cb4z_833F7F90(int a, int b, int c)
{
    return fn_833F7D60((void *)fn_833EDDC0, a, b, 0, c);
}

int ts4l_thunk_cb4z_833F7FB0(int a, int b, int c)
{
    return fn_833F7D60((void *)fn_833EEC88, a, b, 0, c);
}
