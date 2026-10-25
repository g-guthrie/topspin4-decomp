typedef unsigned int ts4_u32;

extern unsigned int lbl_88B73540;
extern unsigned int lbl_88042184;
extern unsigned int lbl_88CCCF74;
extern unsigned int lbl_88056680;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A21768(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CCCF74, (ts4_u32)&lbl_88042184, 0, 0, 0, 0, (ts4_u32)&lbl_88056680, 1, (ts4_u32)&lbl_88B73540, 7, 0, 0, 0);
}