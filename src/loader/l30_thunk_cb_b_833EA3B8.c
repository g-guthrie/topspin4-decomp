/* Loader_DLL.xex 0x833EA3B8-0x833F77C0, executable version 0.0.0.3. */
extern void fn_833E92C0(void);
extern void fn_833EA310(void *cb, void *a, int b, int c);
extern void fn_833EA5D8(void);
extern void fn_833EB1E0(void *cb, void *a, int b, int c);
extern void fn_833EEC88(void);
extern void fn_833F7690(void *cb, void *a, int b, int c);
extern void fn_833EDDC0(void);

void ts4l_thunk_cb_b_833EA3B8(void *a, int b, int c)
{
    fn_833EA310((void *)fn_833E92C0, a, b, c);
}

void ts4l_thunk_cb_b_833EB288(void *a, int b, int c)
{
    fn_833EB1E0((void *)fn_833EA5D8, a, b, c);
}

void ts4l_thunk_cb_b_833EB2B8(void *a, int b, int c)
{
    fn_833EB1E0((void *)fn_833EEC88, a, b, c);
}

void ts4l_thunk_cb_b_833F7790(void *a, int b, int c)
{
    fn_833F7690((void *)fn_833EA5D8, a, b, c);
}

void ts4l_thunk_cb_b_833F77A8(void *a, int b, int c)
{
    fn_833F7690((void *)fn_833EDDC0, a, b, c);
}

void ts4l_thunk_cb_b_833F77C0(void *a, int b, int c)
{
    fn_833F7690((void *)fn_833EEC88, a, b, c);
}
