typedef unsigned int ts4_u32;

extern unsigned int lbl_88BAD7C0;
extern unsigned int lbl_88CE8BBC;
extern unsigned int lbl_88040244;
extern unsigned int lbl_88CE8F4C;
extern unsigned int lbl_88063298;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A659D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE8F4C, (ts4_u32)&lbl_88040244, (ts4_u32)&lbl_88CE8BBC, 0, 0, 0, (ts4_u32)&lbl_88063298, 1, (ts4_u32)&lbl_88BAD7C0, 11, 0, 0, 0);
}