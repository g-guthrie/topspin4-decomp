typedef unsigned int ts4_u32;

extern unsigned int lbl_88BD02F8;
extern unsigned int lbl_880605F0;
extern unsigned int lbl_88CFE96C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A9A6E0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CFE96C, (ts4_u32)&lbl_880605F0, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BD02F8, 1, 0, 0, 0);
}