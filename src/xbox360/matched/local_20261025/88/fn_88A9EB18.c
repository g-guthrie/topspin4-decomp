typedef unsigned int ts4_u32;

extern unsigned int lbl_88BD6C08;
extern unsigned int lbl_88D0034C;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88D0052C;
extern unsigned int lbl_8806C280;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A9EB18(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0052C, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88D0034C, 0, 0, 0, (ts4_u32)&lbl_8806C280, 1, (ts4_u32)&lbl_88BD6C08, 5, 0, 0, 0);
}