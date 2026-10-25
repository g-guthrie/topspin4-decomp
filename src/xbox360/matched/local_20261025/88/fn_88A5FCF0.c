typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA49F8;
extern unsigned int lbl_88CE49A4;
extern unsigned int lbl_8803F0C8;
extern unsigned int lbl_88CE6924;
extern unsigned int lbl_880616F4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A5FCF0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE6924, (ts4_u32)&lbl_8803F0C8, (ts4_u32)&lbl_88CE49A4, 0, 0, 0, (ts4_u32)&lbl_880616F4, 3, (ts4_u32)&lbl_88BA49F8, 9, 0, 0, 0);
}