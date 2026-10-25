typedef unsigned int ts4_u32;

extern unsigned int lbl_88BDF9B8;
extern unsigned int lbl_88D03304;
extern unsigned int lbl_88046FBC;
extern unsigned int lbl_88D02254;
extern unsigned int lbl_8806D2A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AA31D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D02254, (ts4_u32)&lbl_88046FBC, (ts4_u32)&lbl_88D03304, 0, 0, 0, (ts4_u32)&lbl_8806D2A0, 1, (ts4_u32)&lbl_88BDF9B8, 13, 0, 0, 0);
}