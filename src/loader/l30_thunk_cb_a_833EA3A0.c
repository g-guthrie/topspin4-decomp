/* Loader_DLL.xex 0x833EA3A0-0x833F7808, executable version 0.0.0.3. */
extern void fn_833E92C0(void);
extern void fn_833EA310(void *cb, void *a, int b, int c);
extern void fn_833EA5D8(void);
extern void fn_833EB1E0(void *cb, void *a, int b, int c);
extern void fn_833EEC88(void);
extern void fn_833F7690(void *cb, void *a, int b, int c);
extern void fn_833EDDC0(void);

void ts4l_thunk_cb_a_833EA3A0(void *a, int c)
{
    fn_833EA310((void *)fn_833E92C0, a, 0, c);
}

void ts4l_thunk_cb_a_833EB270(void *a, int c)
{
    fn_833EB1E0((void *)fn_833EA5D8, a, 0, c);
}

void ts4l_thunk_cb_a_833EB2A0(void *a, int c)
{
    fn_833EB1E0((void *)fn_833EEC88, a, 0, c);
}

void ts4l_thunk_cb_a_833F77D8(void *a, int c)
{
    fn_833F7690((void *)fn_833EA5D8, a, 0, c);
}

void ts4l_thunk_cb_a_833F77F0(void *a, int c)
{
    fn_833F7690((void *)fn_833EDDC0, a, 0, c);
}

void ts4l_thunk_cb_a_833F7808(void *a, int c)
{
    fn_833F7690((void *)fn_833EEC88, a, 0, c);
}
