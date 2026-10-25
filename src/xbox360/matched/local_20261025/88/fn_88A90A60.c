typedef unsigned int ts4_u32;

extern unsigned int lbl_88BCC628;
extern unsigned int lbl_8804215C;
extern unsigned int lbl_88CFA964;
extern unsigned int lbl_88069F50;
extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A90A60(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CFA964, (ts4_u32)&lbl_8804215C, 0, 0, 0, 0, (ts4_u32)&lbl_88069F50, 2, (ts4_u32)&lbl_88BCC628, 1, 0, 0, 0);
}