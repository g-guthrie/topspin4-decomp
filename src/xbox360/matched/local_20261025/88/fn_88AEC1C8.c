typedef unsigned int ts4_u32;

extern unsigned int lbl_88C181FC;
extern unsigned int lbl_8804E560;
extern unsigned int lbl_88D1FB7C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AEC1C8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D1FB7C, (ts4_u32)&lbl_8804E560, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88C181FC, 2, 0, 0, 0);
}