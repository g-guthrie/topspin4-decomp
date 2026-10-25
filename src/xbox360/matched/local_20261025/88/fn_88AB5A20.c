typedef unsigned int ts4_u32;

extern unsigned int lbl_88BECD50;
extern unsigned int lbl_88D08E9C;
extern unsigned int lbl_88046B2C;
extern unsigned int lbl_88D09ACC;
extern unsigned int lbl_88071FC0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB5A20(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D09ACC, (ts4_u32)&lbl_88046B2C, (ts4_u32)&lbl_88D08E9C, 0, 0, 4, (ts4_u32)&lbl_88071FC0, 1, (ts4_u32)&lbl_88BECD50, 2, 0, 0, 0);
}