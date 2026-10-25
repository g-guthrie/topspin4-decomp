typedef unsigned int ts4_u32;

extern unsigned int lbl_88C033E0;
extern unsigned int lbl_88044408;
extern unsigned int lbl_88D176EC;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AD78D8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D176EC, (ts4_u32)&lbl_88044408, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88C033E0, 3, 0, 0, 0);
}