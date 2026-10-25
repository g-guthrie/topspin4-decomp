typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE6830;
extern unsigned int lbl_88D099DC;
extern unsigned int lbl_88046438;
extern unsigned int lbl_88D09A3C;
extern unsigned int lbl_88071F74;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AB58B8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D09A3C, (ts4_u32)&lbl_88046438, (ts4_u32)&lbl_88D099DC, 0, 0, 0, (ts4_u32)&lbl_88071F74, 1, (ts4_u32)&lbl_88BE6830, 6, 0, 0, 0);
}