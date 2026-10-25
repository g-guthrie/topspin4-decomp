typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB8378;
extern unsigned int lbl_88CF1244;
extern unsigned int lbl_88047034;
extern unsigned int lbl_88CF1274;
extern unsigned int lbl_88066120;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A79A38(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CF1274, (ts4_u32)&lbl_88047034, (ts4_u32)&lbl_88CF1244, 0, 0, 0, (ts4_u32)&lbl_88066120, 1, (ts4_u32)&lbl_88BB8378, 5, 0, 0, 0);
}