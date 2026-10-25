typedef unsigned int ts4_u32;

extern unsigned int lbl_88BCC910;
extern unsigned int lbl_88CF8D14;
extern unsigned int lbl_8803F5D4;
extern unsigned int lbl_88CFBA14;
extern unsigned int lbl_8806A450;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A93378(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CFBA14, (ts4_u32)&lbl_8803F5D4, (ts4_u32)&lbl_88CF8D14, 0, 0, 0, (ts4_u32)&lbl_8806A450, 1, (ts4_u32)&lbl_88BCC910, 8, 0, 0, 0);
}