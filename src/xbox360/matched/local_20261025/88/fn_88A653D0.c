typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA6300;
extern unsigned int lbl_880420E4;
extern unsigned int lbl_88CE8CDC;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A653D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE8CDC, (ts4_u32)&lbl_880420E4, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BA6300, 1, 0, 0, 0);
}