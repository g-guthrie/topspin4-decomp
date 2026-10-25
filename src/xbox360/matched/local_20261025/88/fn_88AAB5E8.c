typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE1158;
extern unsigned int lbl_88D05644;
extern unsigned int lbl_88040364;
extern unsigned int lbl_88D05824;
extern unsigned int lbl_8806E490;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AAB5E8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D05824, (ts4_u32)&lbl_88040364, (ts4_u32)&lbl_88D05644, 0, 0, 0, (ts4_u32)&lbl_8806E490, 1, (ts4_u32)&lbl_88BE1158, 5, 0, 0, 0);
}