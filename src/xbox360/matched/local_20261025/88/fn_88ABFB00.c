typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF7B88;
extern unsigned int lbl_88041174;
extern unsigned int lbl_88D0DC54;
extern unsigned int lbl_88074A88;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ABFB00(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0DC54, (ts4_u32)&lbl_88041174, 0, 0, 0, 0, (ts4_u32)&lbl_88074A88, 2, (ts4_u32)&lbl_88BF7B88, 11, 0, 0, 0);
}