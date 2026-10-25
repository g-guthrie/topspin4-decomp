typedef unsigned int ts4_u32;

extern unsigned int lbl_88B80968;
extern unsigned int lbl_88CD4114;
extern unsigned int lbl_8803EF9C;
extern unsigned int lbl_88CD43E4;
extern unsigned int lbl_8805965C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A33190(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CD43E4, (ts4_u32)&lbl_8803EF9C, (ts4_u32)&lbl_88CD4114, 0, 0, 0, (ts4_u32)&lbl_8805965C, 2, (ts4_u32)&lbl_88B80968, 5, 0, 0, 0);
}