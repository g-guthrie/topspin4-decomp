typedef unsigned int ts4_u32;

extern unsigned int lbl_88BEBA90;
extern unsigned int lbl_88D0844C;
extern unsigned int lbl_880410F8;
extern unsigned int lbl_88D0847C;
extern unsigned int lbl_880716F0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB2278(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0847C, (ts4_u32)&lbl_880410F8, (ts4_u32)&lbl_88D0844C, 0, 0, 0, (ts4_u32)&lbl_880716F0, 2, (ts4_u32)&lbl_88BEBA90, 12, 0, 0, 0);
}