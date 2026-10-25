typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB3100;
extern unsigned int lbl_88CEF864;
extern unsigned int lbl_8804233C;
extern unsigned int lbl_88CEF894;
extern unsigned int lbl_880658A4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A75A30(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEF894, (ts4_u32)&lbl_8804233C, (ts4_u32)&lbl_88CEF864, 0, 0, 0, (ts4_u32)&lbl_880658A4, 1, (ts4_u32)&lbl_88BB3100, 5, 0, 0, 0);
}