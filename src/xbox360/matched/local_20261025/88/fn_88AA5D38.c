typedef unsigned int ts4_u32;

extern unsigned int lbl_88BD9D2C;
extern unsigned int lbl_8803CB50;
extern unsigned int lbl_88D033F4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AA5D38(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D033F4, (ts4_u32)&lbl_8803CB50, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BD9D2C, 2, 0, 0, 0);
}