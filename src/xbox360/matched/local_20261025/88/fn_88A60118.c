typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA4AD0;
extern unsigned int lbl_88CE68F4;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88CE6AD4;
extern unsigned int lbl_880617A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A60118(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE6AD4, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88CE68F4, 0, 0, 0, (ts4_u32)&lbl_880617A0, 1, (ts4_u32)&lbl_88BA4AD0, 5, 0, 0, 0);
}