typedef unsigned int ts4_u32;

extern unsigned int lbl_88BFCA68;
extern unsigned int lbl_88D1366C;
extern unsigned int lbl_88046F9C;
extern unsigned int lbl_88D136CC;
extern unsigned int lbl_88077868;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ACDA78(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D136CC, (ts4_u32)&lbl_88046F9C, (ts4_u32)&lbl_88D1366C, 0, 0, 0, (ts4_u32)&lbl_88077868, 1, (ts4_u32)&lbl_88BFCA68, 9, 0, 0, 0);
}