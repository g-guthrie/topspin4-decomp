typedef unsigned int ts4_u32;

extern unsigned int lbl_88BDFE38;
extern unsigned int lbl_88D025E4;
extern unsigned int lbl_88048224;
extern unsigned int lbl_88D026A4;
extern unsigned int lbl_8806D510;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AA3CA0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D026A4, (ts4_u32)&lbl_88048224, (ts4_u32)&lbl_88D025E4, 0, 0, 0, (ts4_u32)&lbl_8806D510, 1, (ts4_u32)&lbl_88BDFE38, 10, 0, 0, 0);
}