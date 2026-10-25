typedef unsigned int ts4_u32;

extern unsigned int lbl_88B848C8;
extern unsigned int lbl_88CD4E04;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88CD5014;
extern unsigned int lbl_88059A08;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A34FC0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CD5014, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88CD4E04, 0, 0, 0, (ts4_u32)&lbl_88059A08, 1, (ts4_u32)&lbl_88B848C8, 5, 0, 0, 0);
}