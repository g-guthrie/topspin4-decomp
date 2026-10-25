typedef unsigned int ts4_u32;

extern unsigned int lbl_88BDDB78;
extern unsigned int lbl_88045350;
extern unsigned int lbl_88D05F14;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AAC6E8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D05F14, (ts4_u32)&lbl_88045350, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BDDB78, 3, 0, 0, 0);
}