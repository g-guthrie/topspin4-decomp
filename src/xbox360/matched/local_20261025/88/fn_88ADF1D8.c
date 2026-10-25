typedef unsigned int ts4_u32;

extern unsigned int lbl_88C0C0A0;
extern unsigned int lbl_88D1A734;
extern unsigned int lbl_88046438;
extern unsigned int lbl_88D1A794;
extern unsigned int lbl_8807B4E4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ADF1D8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D1A794, (ts4_u32)&lbl_88046438, (ts4_u32)&lbl_88D1A734, 0, 0, 0, (ts4_u32)&lbl_8807B4E4, 1, (ts4_u32)&lbl_88C0C0A0, 6, 0, 0, 0);
}