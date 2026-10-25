typedef unsigned int ts4_u32;

extern unsigned int lbl_88B61710;
extern unsigned int lbl_88CC0F5C;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88CC11CC;
extern unsigned int lbl_88051ACC;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A04B80(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CC11CC, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88CC0F5C, 0, 0, 0, (ts4_u32)&lbl_88051ACC, 1, (ts4_u32)&lbl_88B61710, 4, 0, 0, 0);
}