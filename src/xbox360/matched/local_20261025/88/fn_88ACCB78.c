typedef unsigned int ts4_u32;

extern unsigned int lbl_88C04208;
extern unsigned int lbl_88D12C7C;
extern unsigned int lbl_88040244;
extern unsigned int lbl_88D130CC;
extern unsigned int lbl_88077568;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ACCB78(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D130CC, (ts4_u32)&lbl_88040244, (ts4_u32)&lbl_88D12C7C, 0, 0, 0, (ts4_u32)&lbl_88077568, 1, (ts4_u32)&lbl_88C04208, 11, 0, 0, 0);
}