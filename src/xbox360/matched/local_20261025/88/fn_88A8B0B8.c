typedef unsigned int ts4_u32;

extern unsigned int lbl_88BCB6F8;
extern unsigned int lbl_88CF8114;
extern unsigned int lbl_88040244;
extern unsigned int lbl_88CF84A4;
extern unsigned int lbl_88069378;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A8B0B8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF84A4, (ts4_u32)&lbl_88040244, (ts4_u32)&lbl_88CF8114, 0, 0, 0, (ts4_u32)&lbl_88069378, 1, (ts4_u32)&lbl_88BCB6F8, 11, 0, 0, 0);
}