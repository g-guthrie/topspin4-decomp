typedef unsigned int ts4_u32;

extern unsigned int lbl_88BF7798;
extern unsigned int lbl_88D0D144;
extern unsigned int lbl_88041210;
extern unsigned int lbl_88D0D2F4;
extern unsigned int lbl_88074680;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88ABE3C8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0D2F4, (ts4_u32)&lbl_88041210, (ts4_u32)&lbl_88D0D144, 0, 0, 0, (ts4_u32)&lbl_88074680, 2, (ts4_u32)&lbl_88BF7798, 17, 0, 0, 0);
}