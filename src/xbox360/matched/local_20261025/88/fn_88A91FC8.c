typedef unsigned int ts4_u32;

extern unsigned int lbl_88CF8D14;
extern unsigned int lbl_88045A30;
extern unsigned int lbl_88CFB204;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A91FC8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CFB204, (ts4_u32)&lbl_88045A30, (ts4_u32)&lbl_88CF8D14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}