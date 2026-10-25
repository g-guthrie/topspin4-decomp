typedef unsigned int ts4_u32;

extern unsigned int lbl_88BC0EE0;
extern unsigned int lbl_88CF3A1C;
extern unsigned int lbl_8803EE48;
extern unsigned int lbl_88CF263C;
extern unsigned int lbl_88067038;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A7CA08(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF263C, (ts4_u32)&lbl_8803EE48, (ts4_u32)&lbl_88CF3A1C, 0, 0, 0, (ts4_u32)&lbl_88067038, 1, (ts4_u32)&lbl_88BC0EE0, 5, 0, 0, 0);
}