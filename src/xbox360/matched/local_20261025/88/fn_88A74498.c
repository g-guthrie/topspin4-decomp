typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB1C20;
extern unsigned int lbl_88CEED24;
extern unsigned int lbl_8803ED14;
extern unsigned int lbl_88CEEF94;
extern unsigned int lbl_88065764;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A74498(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEEF94, (ts4_u32)&lbl_8803ED14, (ts4_u32)&lbl_88CEED24, 0, 0, 0, (ts4_u32)&lbl_88065764, 1, (ts4_u32)&lbl_88BB1C20, 8, 0, 0, 0);
}