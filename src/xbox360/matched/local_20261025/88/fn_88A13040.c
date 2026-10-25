typedef unsigned int ts4_u32;

extern unsigned int lbl_88B6ED78;
extern unsigned int lbl_88CC6FEC;
extern unsigned int lbl_88040260;
extern unsigned int lbl_88CC704C;
extern unsigned int lbl_880546D0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A13040(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CC704C, (ts4_u32)&lbl_88040260, (ts4_u32)&lbl_88CC6FEC, 0, 0, 0, (ts4_u32)&lbl_880546D0, 1, (ts4_u32)&lbl_88B6ED78, 2, 0, 0, 0);
}