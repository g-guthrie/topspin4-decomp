typedef unsigned int ts4_u32;

extern unsigned int lbl_88B3BA40;
extern unsigned int lbl_88CACF0C;
extern unsigned int lbl_8803BBA4;
extern unsigned int lbl_88CACE48;
extern unsigned int lbl_8803BB40;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889D3F18(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CACE48, (ts4_u32)&lbl_8803BBA4, (ts4_u32)&lbl_88CACF0C, 36, 0, 0, (ts4_u32)&lbl_8803BB40, 1, (ts4_u32)&lbl_88B3BA40, 6, 0, 0, 0);
}