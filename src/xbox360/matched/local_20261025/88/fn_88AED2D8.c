typedef unsigned int ts4_u32;

extern unsigned int lbl_88C19098;
extern unsigned int lbl_88D2023C;
extern unsigned int lbl_88046438;
extern unsigned int lbl_88D2029C;
extern unsigned int lbl_8807E734;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AED2D8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D2029C, (ts4_u32)&lbl_88046438, (ts4_u32)&lbl_88D2023C, 0, 0, 0, (ts4_u32)&lbl_8807E734, 1, (ts4_u32)&lbl_88C19098, 6, 0, 0, 0);
}