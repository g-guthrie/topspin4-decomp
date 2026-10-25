typedef unsigned int ts4_u32;

extern unsigned int lbl_88B9B350;
extern unsigned int lbl_88CDFC1C;
extern unsigned int lbl_880410F8;
extern unsigned int lbl_88CDFC4C;
extern unsigned int lbl_8805EC28;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A4F2C0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CDFC4C, (ts4_u32)&lbl_880410F8, (ts4_u32)&lbl_88CDFC1C, 0, 0, 0, (ts4_u32)&lbl_8805EC28, 2, (ts4_u32)&lbl_88B9B350, 12, 0, 0, 0);
}