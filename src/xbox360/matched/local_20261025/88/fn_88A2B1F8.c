typedef unsigned int ts4_u32;

extern unsigned int lbl_88B7D5A8;
extern unsigned int lbl_88CD0D0C;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88CD0F1C;
extern unsigned int lbl_88057FB0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A2B1F8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CD0F1C, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88CD0D0C, 0, 0, 0, (ts4_u32)&lbl_88057FB0, 1, (ts4_u32)&lbl_88B7D5A8, 5, 0, 0, 0);
}