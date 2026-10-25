typedef unsigned int ts4_u32;

extern unsigned int lbl_8803B47C;
extern unsigned int lbl_8803B4DC;
extern unsigned int lbl_88CACC38;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889D3A38(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CACC38, (ts4_u32)&lbl_8803B4DC, 0, 8, 0, 0, 0, 0, (ts4_u32)&lbl_8803B47C, 2, 0, 0, 0);
}