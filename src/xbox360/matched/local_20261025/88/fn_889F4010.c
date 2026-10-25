typedef unsigned int ts4_u32;

extern unsigned int lbl_88B52FA8;
extern unsigned int lbl_88CBA05C;
extern unsigned int lbl_8803EF9C;
extern unsigned int lbl_88CBA32C;
extern unsigned int lbl_8804FC7C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_889F4010(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CBA32C, (ts4_u32)&lbl_8803EF9C, (ts4_u32)&lbl_88CBA05C, 0, 0, 0, (ts4_u32)&lbl_8804FC7C, 2, (ts4_u32)&lbl_88B52FA8, 4, 0, 0, 0);
}