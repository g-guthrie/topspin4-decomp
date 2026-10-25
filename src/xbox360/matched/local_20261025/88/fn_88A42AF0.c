typedef unsigned int ts4_u32;

extern unsigned int lbl_88B92A70;
extern unsigned int lbl_88CDB644;
extern unsigned int lbl_8803EE48;
extern unsigned int lbl_88CDAA44;
extern unsigned int lbl_8805BF68;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A42AF0(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CDAA44, (ts4_u32)&lbl_8803EE48, (ts4_u32)&lbl_88CDB644, 0, 0, 0, (ts4_u32)&lbl_8805BF68, 1, (ts4_u32)&lbl_88B92A70, 5, 0, 0, 0);
}