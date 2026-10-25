typedef unsigned int ts4_u32;

extern unsigned int lbl_88BB6E18;
extern unsigned int lbl_88CEE904;
extern unsigned int lbl_88046FBC;
extern unsigned int lbl_88CED884;
extern unsigned int lbl_88064F30;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A70C28(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CED884, (ts4_u32)&lbl_88046FBC, (ts4_u32)&lbl_88CEE904, 0, 0, 0, (ts4_u32)&lbl_88064F30, 1, (ts4_u32)&lbl_88BB6E18, 13, 0, 0, 0);
}