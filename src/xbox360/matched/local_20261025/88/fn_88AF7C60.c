typedef unsigned int ts4_u32;

extern unsigned int lbl_88C23000;
extern unsigned int lbl_88D257D0;
extern unsigned int lbl_880456A4;
extern unsigned int lbl_88D24900;
extern unsigned int lbl_880842A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AF7C60(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D24900, (ts4_u32)&lbl_880456A4, (ts4_u32)&lbl_88D257D0, 176, 0, 0, (ts4_u32)&lbl_880842A0, 1, (ts4_u32)&lbl_88C23000, 5, 0, 0, 0);
}