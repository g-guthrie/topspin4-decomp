typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA71C8;
extern unsigned int lbl_88041174;
extern unsigned int lbl_88CE942C;
extern unsigned int lbl_88063378;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A665B0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE942C, (ts4_u32)&lbl_88041174, 0, 0, 0, 0, (ts4_u32)&lbl_88063378, 1, (ts4_u32)&lbl_88BA71C8, 8, 0, 0, 0);
}