typedef unsigned int ts4_u32;

extern unsigned int lbl_88B65F20;
extern unsigned int lbl_88CC3554;
extern unsigned int lbl_8803F084;
extern unsigned int lbl_88CC57D4;
extern unsigned int lbl_880538A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A0F4F0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CC57D4, (ts4_u32)&lbl_8803F084, (ts4_u32)&lbl_88CC3554, 0, 0, 0, (ts4_u32)&lbl_880538A0, 1, (ts4_u32)&lbl_88B65F20, 6, 0, 0, 0);
}