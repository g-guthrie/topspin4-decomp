typedef unsigned int ts4_u32;

extern unsigned int lbl_880814D8;
extern unsigned int lbl_88046208;
extern unsigned int lbl_88D23C54;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AF63D0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D23C54, (ts4_u32)&lbl_88046208, 0, 48, 0, 0, 0, 0, (ts4_u32)&lbl_880814D8, 4, 0, 0, 0);
}