typedef unsigned int ts4_u32;

extern unsigned int lbl_88B44040;
extern unsigned int lbl_88042170;
extern unsigned int lbl_88CB1764;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889DEE70(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CB1764, (ts4_u32)&lbl_88042170, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88B44040, 4, 0, 0, 0);
}