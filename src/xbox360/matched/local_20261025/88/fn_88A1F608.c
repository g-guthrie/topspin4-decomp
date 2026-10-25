typedef unsigned int ts4_u32;

extern unsigned int lbl_88B72580;
extern unsigned int lbl_88CCBF24;
extern unsigned int lbl_8803EF9C;
extern unsigned int lbl_88CCC1F4;
extern unsigned int lbl_8805627C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A1F608(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CCC1F4, (ts4_u32)&lbl_8803EF9C, (ts4_u32)&lbl_88CCBF24, 0, 0, 0, (ts4_u32)&lbl_8805627C, 2, (ts4_u32)&lbl_88B72580, 5, 0, 0, 0);
}