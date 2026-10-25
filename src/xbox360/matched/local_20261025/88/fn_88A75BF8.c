typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB7A78;
extern unsigned int lbl_88CEE904;
extern unsigned int lbl_88042318;
extern unsigned int lbl_88CEF954;
extern unsigned int lbl_880658E0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A75BF8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEF954, (ts4_u32)&lbl_88042318, (ts4_u32)&lbl_88CEE904, 0, 0, 4, (ts4_u32)&lbl_880658E0, 1, (ts4_u32)&lbl_88BB7A78, 2, 0, 0, 0);
}