typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB7160;
extern unsigned int lbl_88CEDC14;
extern unsigned int lbl_88048224;
extern unsigned int lbl_88CEDCD4;
extern unsigned int lbl_88065170;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A716E0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEDCD4, (ts4_u32)&lbl_88048224, (ts4_u32)&lbl_88CEDC14, 0, 0, 0, (ts4_u32)&lbl_88065170, 1, (ts4_u32)&lbl_88BB7160, 10, 0, 0, 0);
}