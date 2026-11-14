/* Loader_DLL.xex 0x833C4C18-0x833C4CA0, 0x833C4CA0-0x833C4D28, executable version 0.0.0.3. */
/* Run an operation on up to three sub-objects of a parent (at +8, +0 and +16) depending on three enable flags; the last operation's result is returned. */
typedef unsigned long ts4l_u32;

extern ts4l_u32 fn_833C2F50(ts4l_u32 obj, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d);
extern ts4l_u32 fn_833C3578(ts4l_u32 obj, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d);
extern ts4l_u32 fn_833C3A80(ts4l_u32 obj, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d);
extern ts4l_u32 fn_833C3E68(ts4l_u32 obj, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d);

ts4l_u32 ts4l_apply_three_833C4C18(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, int a3, int a4, ts4l_u32 a5, ts4l_u32 a6, int a7, ts4l_u32 a8, ts4l_u32 a9)
{
    ts4l_u32 r = a0;
    (void)a1; (void)a2; (void)a5; (void)a6;
    if (a7) r = fn_833C2F50(a0 + 8, 1, a9, 16, a8);
    if (a3) r = fn_833C2F50(a0, 1, a9, 16, a8);
    if (a4) r = fn_833C3578(a0 + 16, 1, a9, 16, a8);
    return r;
}

ts4l_u32 ts4l_apply_three_833C4CA0(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, int a3, int a4, ts4l_u32 a5, ts4l_u32 a6, int a7, ts4l_u32 a8, ts4l_u32 a9)
{
    ts4l_u32 r = a0;
    (void)a1; (void)a2; (void)a5; (void)a6;
    if (a7) r = fn_833C3A80(a0 + 8, 1, a9, 16, a8);
    if (a3) r = fn_833C3A80(a0, 1, a9, 16, a8);
    if (a4) r = fn_833C3E68(a0 + 16, 1, a9, 16, a8);
    return r;
}
