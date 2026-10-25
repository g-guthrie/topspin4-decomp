typedef unsigned int ts4_u32;

extern unsigned int lbl_88B722A0;
extern unsigned int lbl_88CCBF54;
extern unsigned int lbl_8804011C;
extern unsigned int lbl_88CCBEF4;
extern unsigned int lbl_880561D0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A1EEA8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CCBEF4, (ts4_u32)&lbl_8804011C, (ts4_u32)&lbl_88CCBF54, 0, 0, 0, (ts4_u32)&lbl_880561D0, 1, (ts4_u32)&lbl_88B722A0, 2, 0, 0, 0);
}