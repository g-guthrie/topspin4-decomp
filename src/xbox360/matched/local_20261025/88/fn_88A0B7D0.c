typedef unsigned int ts4_u32;

extern unsigned int lbl_88B63FC8;
extern unsigned int lbl_88040278;
extern unsigned int lbl_88CC3E84;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A0B7D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CC3E84, (ts4_u32)&lbl_88040278, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88B63FC8, 9, 0, 0, 0);
}