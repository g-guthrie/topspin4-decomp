typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB6FC8;
extern unsigned int lbl_88CEDAC4;
extern unsigned int lbl_88041210;
extern unsigned int lbl_88CEDC74;
extern unsigned int lbl_88065138;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A715D8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEDC74, (ts4_u32)&lbl_88041210, (ts4_u32)&lbl_88CEDAC4, 0, 0, 0, (ts4_u32)&lbl_88065138, 2, (ts4_u32)&lbl_88BB6FC8, 17, 0, 0, 0);
}