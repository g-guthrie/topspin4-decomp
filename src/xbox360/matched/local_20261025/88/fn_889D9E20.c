typedef unsigned int ts4_u32;

extern unsigned int lbl_88B40498;
extern unsigned int lbl_88CAD81C;
extern unsigned int lbl_8803F084;
extern unsigned int lbl_88CAF5EC;
extern unsigned int lbl_8804BF60;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889D9E20(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CAF5EC, (ts4_u32)&lbl_8803F084, (ts4_u32)&lbl_88CAD81C, 0, 0, 0, (ts4_u32)&lbl_8804BF60, 1, (ts4_u32)&lbl_88B40498, 5, 0, 0, 0);
}