typedef unsigned int ts4_u32;

extern unsigned int lbl_88C06380;
extern unsigned int lbl_88D167EC;
extern unsigned int lbl_880458E0;
extern unsigned int lbl_88D1681C;
extern unsigned int lbl_88078A44;

extern ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void *fn_88AD54D8(void) {
    return fn_8841F080((ts4_u32 *)&lbl_88D1681C, (ts4_u32)&lbl_880458E0, (ts4_u32)&lbl_88D167EC, 0, 0, 0, (ts4_u32)&lbl_88078A44, 1, (ts4_u32)&lbl_88C06380, 5, 0, 0, 0);
}