typedef unsigned int ts4_u32;

extern unsigned int lbl_88B9AE28;
extern unsigned int lbl_88CDFDFC;
extern unsigned int lbl_88046FBC;
extern unsigned int lbl_88CDEFBC;
extern unsigned int lbl_8805E880;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A4D3C8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CDEFBC, (ts4_u32)&lbl_88046FBC, (ts4_u32)&lbl_88CDFDFC, 0, 0, 0, (ts4_u32)&lbl_8805E880, 1, (ts4_u32)&lbl_88B9AE28, 13, 0, 0, 0);
}