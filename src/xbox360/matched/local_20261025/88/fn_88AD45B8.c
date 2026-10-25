typedef unsigned int ts4_u32;

extern unsigned int lbl_88C062F0;
extern unsigned int lbl_88D1600C;
extern unsigned int lbl_880456A4;
extern unsigned int lbl_88D161EC;
extern unsigned int lbl_88078888;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AD45B8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D161EC, (ts4_u32)&lbl_880456A4, (ts4_u32)&lbl_88D1600C, 0, 0, 0, (ts4_u32)&lbl_88078888, 1, (ts4_u32)&lbl_88C062F0, 5, 0, 0, 0);
}