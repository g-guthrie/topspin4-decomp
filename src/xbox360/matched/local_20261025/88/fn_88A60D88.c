typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA4B60;
extern unsigned int lbl_88CE6FB4;
extern unsigned int lbl_88047034;
extern unsigned int lbl_88CE6FE4;
extern unsigned int lbl_880618D8;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A60D88(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE6FE4, (ts4_u32)&lbl_88047034, (ts4_u32)&lbl_88CE6FB4, 0, 0, 0, (ts4_u32)&lbl_880618D8, 1, (ts4_u32)&lbl_88BA4B60, 5, 0, 0, 0);
}