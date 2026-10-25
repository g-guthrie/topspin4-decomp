typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF9BF8;
extern unsigned int lbl_88D10E94;
extern unsigned int lbl_880458E0;
extern unsigned int lbl_88D10EC4;
extern unsigned int lbl_88075D5C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AC7860(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D10EC4, (ts4_u32)&lbl_880458E0, (ts4_u32)&lbl_88D10E94, 0, 0, 0, (ts4_u32)&lbl_88075D5C, 1, (ts4_u32)&lbl_88BF9BF8, 5, 0, 0, 0);
}