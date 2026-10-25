typedef unsigned int ts4_u32;

extern unsigned int lbl_88BCB9B0;
extern unsigned int lbl_88CF8A44;
extern unsigned int lbl_880410F8;
extern unsigned int lbl_88CF8A74;
extern unsigned int lbl_88069550;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A8BEF8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF8A74, (ts4_u32)&lbl_880410F8, (ts4_u32)&lbl_88CF8A44, 0, 0, 0, (ts4_u32)&lbl_88069550, 2, (ts4_u32)&lbl_88BCB9B0, 12, 0, 0, 0);
}