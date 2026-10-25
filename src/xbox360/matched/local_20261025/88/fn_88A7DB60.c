typedef unsigned int ts4_u32;

extern unsigned int lbl_88BC1138;
extern unsigned int lbl_88CF2BAC;
extern unsigned int lbl_88041210;
extern unsigned int lbl_88CF2D5C;
extern unsigned int lbl_880672A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A7DB60(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF2D5C, (ts4_u32)&lbl_88041210, (ts4_u32)&lbl_88CF2BAC, 0, 0, 0, (ts4_u32)&lbl_880672A0, 2, (ts4_u32)&lbl_88BC1138, 17, 0, 0, 0);
}