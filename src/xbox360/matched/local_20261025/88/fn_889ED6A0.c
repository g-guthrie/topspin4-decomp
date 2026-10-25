typedef unsigned int ts4_u32;

extern unsigned int lbl_88B51000;
extern unsigned int lbl_88CB74F4;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88CB7764;
extern unsigned int lbl_8804F03C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889ED6A0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CB7764, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88CB74F4, 0, 0, 0, (ts4_u32)&lbl_8804F03C, 1, (ts4_u32)&lbl_88B51000, 4, 0, 0, 0);
}