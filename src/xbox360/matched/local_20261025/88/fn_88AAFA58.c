typedef unsigned int ts4_u32;

extern unsigned int lbl_88BE1E88;
extern unsigned int lbl_8803BA20;
extern unsigned int lbl_88D0745C;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AAFA58(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D0745C, (ts4_u32)&lbl_8803BA20, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88BE1E88, 6, 0, 0, 0);
}