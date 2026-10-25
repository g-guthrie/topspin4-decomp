typedef unsigned int ts4_u32;

extern unsigned int lbl_88BAD8C8;
extern unsigned int lbl_88CE94EC;
extern unsigned int lbl_880410F8;
extern unsigned int lbl_88CE951C;
extern unsigned int lbl_88063408;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A667F8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CE951C, (ts4_u32)&lbl_880410F8, (ts4_u32)&lbl_88CE94EC, 0, 0, 0, (ts4_u32)&lbl_88063408, 2, (ts4_u32)&lbl_88BAD8C8, 12, 0, 0, 0);
}