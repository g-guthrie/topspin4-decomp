typedef unsigned int ts4_u32;

extern unsigned int lbl_88BC3D90;
extern unsigned int lbl_8806043C;
extern unsigned int lbl_88CF81A4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A8A950(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF81A4, (ts4_u32)&lbl_8806043C, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BC3D90, 2, 0, 0, 0);
}