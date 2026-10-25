typedef unsigned int ts4_u32;

extern unsigned int lbl_88C022C0;
extern unsigned int lbl_88D140BC;
extern unsigned int lbl_880459A0;
extern unsigned int lbl_88D16EAC;
extern unsigned int lbl_88078F24;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AD6488(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D16EAC, (ts4_u32)&lbl_880459A0, (ts4_u32)&lbl_88D140BC, 0, 0, 0, (ts4_u32)&lbl_88078F24, 1, (ts4_u32)&lbl_88C022C0, 6, 0, 0, 0);
}