typedef unsigned int ts4_u32;

extern unsigned int lbl_88BC12D0;
extern unsigned int lbl_88CF2CFC;
extern unsigned int lbl_88048224;
extern unsigned int lbl_88CF2DBC;
extern unsigned int lbl_880672D8;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A7DC68(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF2DBC, (ts4_u32)&lbl_88048224, (ts4_u32)&lbl_88CF2CFC, 0, 0, 0, (ts4_u32)&lbl_880672D8, 1, (ts4_u32)&lbl_88BC12D0, 10, 0, 0, 0);
}