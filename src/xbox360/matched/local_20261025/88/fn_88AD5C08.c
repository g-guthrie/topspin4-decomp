typedef unsigned int ts4_u32;

extern unsigned int lbl_88C063F8;
extern unsigned int lbl_88D140BC;
extern unsigned int lbl_88045A44;
extern unsigned int lbl_88D16B1C;
extern unsigned int lbl_88078B70;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AD5C08(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D16B1C, (ts4_u32)&lbl_88045A44, (ts4_u32)&lbl_88D140BC, 0, 0, 0, (ts4_u32)&lbl_88078B70, 1, (ts4_u32)&lbl_88C063F8, 11, 0, 0, 0);
}