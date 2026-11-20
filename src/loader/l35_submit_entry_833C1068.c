/* Loader_DLL.xex 0x833C1068-0x833C10E0, executable version 0.0.0.3. */
typedef unsigned long u32;
extern char lbl_83543658[];
extern u32 lbl_835437C0;
extern void fn_833C6510(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
#define FLD(off, k) (*(u32 *)(lbl_83543658 + (k) + (off)))
void ts4l_submit_entry_833C1068(u32 a, u32 b, u32 c)
{
    u32 off = lbl_835437C0 * 0x58;
    fn_833C6510(a, b, 0, FLD(off, 8), c, 1, 1, FLD(off, 0), FLD(off, 0x18), FLD(off, 0x38));
}
