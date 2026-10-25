typedef unsigned int ts4_u32;

extern unsigned int lbl_88BC8870;
extern unsigned int lbl_8804229C;
extern unsigned int lbl_88CFB114;
extern unsigned int lbl_8806A198;
extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A91D80(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CFB114, (ts4_u32)&lbl_8804229C, 0, 0, 0, 0, (ts4_u32)&lbl_8806A198, 1, (ts4_u32)&lbl_88BC8870, 3, 0, 0, 0);
}