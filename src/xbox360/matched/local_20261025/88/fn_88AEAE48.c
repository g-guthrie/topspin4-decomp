typedef unsigned int ts4_u32;

extern unsigned int lbl_88C1F0B0;
extern unsigned int lbl_88D1E22C;
extern unsigned int lbl_88073CE8;
extern unsigned int lbl_88D1F39C;
extern unsigned int lbl_8807E174;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AEAE48(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D1F39C, (ts4_u32)&lbl_88073CE8, (ts4_u32)&lbl_88D1E22C, 0, 0, 0, (ts4_u32)&lbl_8807E174, 2, (ts4_u32)&lbl_88C1F0B0, 25, 0, 0, 0);
}