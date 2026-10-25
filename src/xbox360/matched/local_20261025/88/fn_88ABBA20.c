typedef unsigned int ts4_u32;

extern unsigned int lbl_88BEDC68;
extern unsigned int lbl_88D08E9C;
extern unsigned int lbl_88044CA0;
extern unsigned int lbl_88D0C1CC;
extern unsigned int lbl_88072ED8;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ABBA20(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0C1CC, (ts4_u32)&lbl_88044CA0, (ts4_u32)&lbl_88D08E9C, 0, 0, 0, (ts4_u32)&lbl_88072ED8, 1, (ts4_u32)&lbl_88BEDC68, 13, 0, 0, 0);
}