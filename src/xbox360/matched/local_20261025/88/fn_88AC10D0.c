typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF8BC0;
extern unsigned int lbl_88D0D3B4;
extern unsigned int lbl_88073E3C;
extern unsigned int lbl_88D0E494;
extern unsigned int lbl_88074F60;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AC10D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0E494, (ts4_u32)&lbl_88073E3C, (ts4_u32)&lbl_88D0D3B4, 0, 0, 0, (ts4_u32)&lbl_88074F60, 3, (ts4_u32)&lbl_88BF8BC0, 22, 0, 0, 0);
}