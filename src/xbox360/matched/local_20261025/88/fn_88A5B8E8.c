typedef unsigned int ts4_u32;

extern unsigned int lbl_88B9EC8C;
extern unsigned int lbl_8803F9B0;
extern unsigned int lbl_88CE4D64;
extern unsigned int lbl_88060EE4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A5B8E8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE4D64, (ts4_u32)&lbl_8803F9B0, 0, 0, 0, 0, (ts4_u32)&lbl_88060EE4, 1, (ts4_u32)&lbl_88B9EC8C, 2, 0, 0, 0);
}