typedef unsigned int ts4_u32;

extern unsigned int lbl_88BED680;
extern unsigned int lbl_88D0B5CC;
extern unsigned int lbl_880458E0;
extern unsigned int lbl_88D0B5FC;
extern unsigned int lbl_880728C4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB9D50(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0B5FC, (ts4_u32)&lbl_880458E0, (ts4_u32)&lbl_88D0B5CC, 0, 0, 0, (ts4_u32)&lbl_880728C4, 1, (ts4_u32)&lbl_88BED680, 5, 0, 0, 0);
}