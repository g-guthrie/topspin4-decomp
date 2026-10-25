typedef unsigned int ts4_u32;

extern unsigned int lbl_88BAE738;
extern unsigned int lbl_88CEC12C;
extern unsigned int lbl_88047034;
extern unsigned int lbl_88CEC15C;
extern unsigned int lbl_88064170;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A6D450(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEC15C, (ts4_u32)&lbl_88047034, (ts4_u32)&lbl_88CEC12C, 0, 0, 0, (ts4_u32)&lbl_88064170, 1, (ts4_u32)&lbl_88BAE738, 5, 0, 0, 0);
}