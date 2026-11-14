/* Loader_DLL.xex 0x833C9B78-0x833C9BEC, 0x833C9BF0-0x833C9C60, executable version 0.0.0.3. */
typedef unsigned long u32;
extern u32 lbl_83542CB0;
extern u32 lbl_83542C90;
extern u32 lbl_83542CAC;
extern void (*lbl_83542B28)(u32, u32, u32, u32, u32);
extern u32 lbl_83542B6C;
extern void fn_833982C0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void ts4l_blit_flags_833C9B78(u32 unused, u32 dst, u32 cb, u32 src, u32 u1, u32 u2, u32 f1, u32 f2)
{
    (void)unused; (void)u1; (void)u2;
    fn_833982C0(src, lbl_83542CB0, dst, lbl_83542CB0, f1 & 3, f2 & 3, lbl_83542C90);
    if (cb)
        lbl_83542B28(dst, dst, cb, lbl_83542CB0, lbl_83542B6C);
}

void ts4l_blit_flags_833C9BF0(u32 unused, u32 dst, u32 cb, u32 src, u32 f1, u32 f2)
{
    (void)unused;
    fn_833982C0(src, lbl_83542CAC, dst, lbl_83542CAC, f1 & 3, f2 & 3, 0);
    if (cb)
        lbl_83542B28(dst, dst, cb, lbl_83542CAC, lbl_83542B6C);
}
