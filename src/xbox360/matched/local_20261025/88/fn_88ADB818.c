typedef unsigned int ts4_u32;

extern unsigned int lbl_88C112F0;
extern unsigned int lbl_88041174;
extern unsigned int lbl_88D19084;
extern unsigned int lbl_8807A9B8;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ADB818(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D19084, (ts4_u32)&lbl_88041174, 0, 0, 0, 0, (ts4_u32)&lbl_8807A9B8, 2, (ts4_u32)&lbl_88C112F0, 11, 0, 0, 0);
}