typedef unsigned int ts4_u32;

extern unsigned int lbl_88BDFF28;
extern unsigned int lbl_88D02704;
extern unsigned int lbl_88040244;
extern unsigned int lbl_88D02A94;
extern unsigned int lbl_8806D5A0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AA4648(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D02A94, (ts4_u32)&lbl_88040244, (ts4_u32)&lbl_88D02704, 0, 0, 0, (ts4_u32)&lbl_8806D5A0, 1, (ts4_u32)&lbl_88BDFF28, 11, 0, 0, 0);
}