typedef unsigned int ts4_u32;

extern unsigned int lbl_88B76EE0;
extern unsigned int lbl_88042110;
extern unsigned int lbl_88CCE96C;
extern unsigned int lbl_88057314;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88A25618(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88CCE96C, (ts4_u32)&lbl_88042110, 0, 0, 0, 0, (ts4_u32)&lbl_88057314, 1, (ts4_u32)&lbl_88B76EE0, 11, 0, 0, 0);
}