typedef unsigned int ts4_u32;

extern unsigned int lbl_88BBAA88;
extern unsigned int lbl_88041174;
extern unsigned int lbl_88CF368C;
extern unsigned int lbl_880674A8;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A7F1F0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF368C, (ts4_u32)&lbl_88041174, 0, 0, 0, 0, (ts4_u32)&lbl_880674A8, 1, (ts4_u32)&lbl_88BBAA88, 8, 0, 0, 0);
}