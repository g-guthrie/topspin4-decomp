typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE8FC0;
extern unsigned int lbl_88D08E9C;
extern unsigned int lbl_88045430;
extern unsigned int lbl_88D0BC2C;
extern unsigned int lbl_88072B2C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ABABE0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0BC2C, (ts4_u32)&lbl_88045430, (ts4_u32)&lbl_88D08E9C, 0, 0, 0, (ts4_u32)&lbl_88072B2C, 2, (ts4_u32)&lbl_88BE8FC0, 67, 0, 0, 0);
}