typedef unsigned int ts4_u32;

extern unsigned int lbl_88BDE908;
extern unsigned int lbl_88044A58;
extern unsigned int lbl_88D06934;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AADF88(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D06934, (ts4_u32)&lbl_88044A58, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BDE908, 3, 0, 0, 0);
}