typedef unsigned int ts4_u32;

extern unsigned int lbl_88C1D8C8;
extern unsigned int lbl_88D1F6FC;
extern unsigned int lbl_88046FBC;
extern unsigned int lbl_88D1DC5C;
extern unsigned int lbl_8807D0CC;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AE7310(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D1DC5C, (ts4_u32)&lbl_88046FBC, (ts4_u32)&lbl_88D1F6FC, 0, 0, 0, (ts4_u32)&lbl_8807D0CC, 1, (ts4_u32)&lbl_88C1D8C8, 9, 0, 0, 0);
}