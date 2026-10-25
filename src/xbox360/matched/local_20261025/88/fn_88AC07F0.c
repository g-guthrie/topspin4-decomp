typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF8710;
extern unsigned int lbl_88D0D3B4;
extern unsigned int lbl_88073A00;
extern unsigned int lbl_88D0E134;
extern unsigned int lbl_88074D40;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AC07F0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0E134, (ts4_u32)&lbl_88073A00, (ts4_u32)&lbl_88D0D3B4, 0, 0, 0, (ts4_u32)&lbl_88074D40, 2, (ts4_u32)&lbl_88BF8710, 11, 0, 0, 0);
}