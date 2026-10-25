typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE6EB0;
extern unsigned int lbl_88D0A15C;
extern unsigned int lbl_88046924;
extern unsigned int lbl_88D0A1BC;
extern unsigned int lbl_88072234;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB6B78(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0A1BC, (ts4_u32)&lbl_88046924, (ts4_u32)&lbl_88D0A15C, 0, 0, 0, (ts4_u32)&lbl_88072234, 1, (ts4_u32)&lbl_88BE6EB0, 2, 0, 0, 0);
}