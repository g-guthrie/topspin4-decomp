typedef unsigned int ts4_u32;

extern unsigned int lbl_88BD6C98;
extern unsigned int lbl_88D00ACC;
extern unsigned int lbl_88047034;
extern unsigned int lbl_88D00AFC;
extern unsigned int lbl_8806C43C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A9F950(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D00AFC, (ts4_u32)&lbl_88047034, (ts4_u32)&lbl_88D00ACC, 0, 0, 0, (ts4_u32)&lbl_8806C43C, 1, (ts4_u32)&lbl_88BD6C98, 5, 0, 0, 0);
}