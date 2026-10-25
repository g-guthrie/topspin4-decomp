typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE11E8;
extern unsigned int lbl_88D05DC4;
extern unsigned int lbl_88047034;
extern unsigned int lbl_88D05DF4;
extern unsigned int lbl_8806E64C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AAC420(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D05DF4, (ts4_u32)&lbl_88047034, (ts4_u32)&lbl_88D05DC4, 0, 0, 0, (ts4_u32)&lbl_8806E64C, 1, (ts4_u32)&lbl_88BE11E8, 5, 0, 0, 0);
}