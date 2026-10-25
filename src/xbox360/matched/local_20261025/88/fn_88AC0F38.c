typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF8968;
extern unsigned int lbl_88D0D3B4;
extern unsigned int lbl_88073CE8;
extern unsigned int lbl_88D0E404;
extern unsigned int lbl_88074E6C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AC0F38(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0E404, (ts4_u32)&lbl_88073CE8, (ts4_u32)&lbl_88D0D3B4, 0, 0, 0, (ts4_u32)&lbl_88074E6C, 2, (ts4_u32)&lbl_88BF8968, 25, 0, 0, 0);
}