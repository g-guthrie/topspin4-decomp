typedef unsigned int ts4_u32;

extern unsigned int lbl_88BEB580;
extern unsigned int lbl_88D07ABC;
extern unsigned int lbl_88040244;
extern unsigned int lbl_88D07E4C;
extern unsigned int lbl_88071438;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB1300(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D07E4C, (ts4_u32)&lbl_88040244, (ts4_u32)&lbl_88D07ABC, 0, 0, 0, (ts4_u32)&lbl_88071438, 1, (ts4_u32)&lbl_88BEB580, 11, 0, 0, 0);
}