typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF88C0;
extern unsigned int lbl_88D0D3B4;
extern unsigned int lbl_88073B18;
extern unsigned int lbl_88D0E374;
extern unsigned int lbl_88074E20;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AC0DB8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0E374, (ts4_u32)&lbl_88073B18, (ts4_u32)&lbl_88D0D3B4, 0, 0, 0, (ts4_u32)&lbl_88074E20, 1, (ts4_u32)&lbl_88BF88C0, 7, 0, 0, 0);
}