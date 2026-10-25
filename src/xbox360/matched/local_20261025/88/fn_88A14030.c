typedef unsigned int ts4_u32;

extern unsigned int lbl_88B6EF88;
extern unsigned int lbl_8804C33C;
extern unsigned int lbl_88CC76DC;
extern unsigned int lbl_88054948;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A14030(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CC76DC, (ts4_u32)&lbl_8804C33C, 0, 0, 0, 0, (ts4_u32)&lbl_88054948, 1, (ts4_u32)&lbl_88B6EF88, 5, 0, 0, 0);
}