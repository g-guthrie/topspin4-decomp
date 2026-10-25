typedef unsigned int ts4_u32;

extern unsigned int lbl_88BA9E90;
extern unsigned int lbl_88CEADDC;
extern unsigned int lbl_880466D4;
extern unsigned int lbl_88CEB0AC;

ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void fn_88A6AAD8(void) {
    struct {
        ts4_u32 p1;
        ts4_u32 p2;
        ts4_u32 p3;
        ts4_u32 p4;
        ts4_u32 p5;
    } args;

    args.p1 = (ts4_u32)&lbl_88BA9E90;
    args.p2 = 3;
    args.p3 = 0;
    args.p4 = 0;
    args.p5 = 0;

    fn_8841F080((ts4_u32 *)&lbl_88CEB0AC, (ts4_u32)&lbl_880466D4, (ts4_u32)&lbl_88CEADDC, 0, 0, 0, 0, 0, args.p1, args.p2, args.p3, args.p4, args.p5);
}