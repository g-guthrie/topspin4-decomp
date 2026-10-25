typedef unsigned int ts4_u32;

extern unsigned int lbl_88C05348;
extern unsigned int lbl_88D12C7C;
extern unsigned int lbl_88073E3C;
extern unsigned int lbl_88D13DEC;
extern unsigned int lbl_88077C48;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ACED48(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D13DEC, (ts4_u32)&lbl_88073E3C, (ts4_u32)&lbl_88D12C7C, 0, 0, 0, (ts4_u32)&lbl_88077C48, 3, (ts4_u32)&lbl_88C05348, 22, 0, 0, 0);
}