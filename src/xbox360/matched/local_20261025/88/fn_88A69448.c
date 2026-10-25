typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA9688;
extern unsigned int lbl_88CEA74C;
extern unsigned int lbl_8804233C;
extern unsigned int lbl_88CEA77C;
extern unsigned int lbl_880638F4;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A69448(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CEA77C, (ts4_u32)&lbl_8804233C, (ts4_u32)&lbl_88CEA74C, 0, 0, 0, (ts4_u32)&lbl_880638F4, 1, (ts4_u32)&lbl_88BA9688, 5, 0, 0, 0);
}