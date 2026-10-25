typedef unsigned int ts4_u32;

extern unsigned int lbl_88B56E40;
extern unsigned int lbl_88046C24;
extern unsigned int lbl_88CBC534;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889F9288(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CBC534, (ts4_u32)&lbl_88046C24, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88B56E40, 6, 0, 0, 0);
}