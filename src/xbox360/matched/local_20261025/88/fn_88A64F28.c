typedef unsigned int ts4_u32;

extern unsigned int lbl_88BAD550;
extern unsigned int lbl_88CE894C;
extern unsigned int lbl_88041210;
extern unsigned int lbl_88CE8AFC;
extern unsigned int lbl_880631F0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A64F28(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE8AFC, (ts4_u32)&lbl_88041210, (ts4_u32)&lbl_88CE894C, 0, 0, 0, (ts4_u32)&lbl_880631F0, 2, (ts4_u32)&lbl_88BAD550, 16, 0, 0, 0);
}