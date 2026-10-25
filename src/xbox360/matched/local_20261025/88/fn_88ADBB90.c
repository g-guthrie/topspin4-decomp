typedef unsigned int ts4_u32;

extern unsigned int lbl_88C09550;
extern unsigned int lbl_88D19174;
extern unsigned int lbl_88046F9C;
extern unsigned int lbl_88D191D4;
extern unsigned int lbl_8807AB40;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ADBB90(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D191D4, (ts4_u32)&lbl_88046F9C, (ts4_u32)&lbl_88D19174, 0, 0, 0, (ts4_u32)&lbl_8807AB40, 1, (ts4_u32)&lbl_88C09550, 11, 0, 0, 0);
}