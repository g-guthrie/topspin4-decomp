typedef unsigned int ts4_u32;

extern unsigned int lbl_88C03CF8;
extern unsigned int lbl_88D12A0C;
extern unsigned int lbl_88048210;
extern unsigned int lbl_88D127CC;
extern unsigned int lbl_88076EE0;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ACB510(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D127CC, (ts4_u32)&lbl_88048210, (ts4_u32)&lbl_88D12A0C, 0, 0, 0, (ts4_u32)&lbl_88076EE0, 1, (ts4_u32)&lbl_88C03CF8, 12, 0, 0, 0);
}