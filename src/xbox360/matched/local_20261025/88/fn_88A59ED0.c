typedef unsigned int ts4_u32;

extern unsigned int lbl_88060A4C;
extern unsigned int lbl_88B9DC18;
extern unsigned int lbl_88CE3EF4;
extern unsigned int lbl_88041618;
extern unsigned int lbl_88CE42B4;

ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void fn_88A59ED0(void) {
    struct {
        ts4_u32 p1;
        ts4_u32 p2;
        ts4_u32 p3;
        ts4_u32 p4;
        ts4_u32 p5;
    } args;

    args.p1 = (ts4_u32)&lbl_88B9DC18;
    args.p2 = 8;
    args.p3 = 0;
    args.p4 = 0;
    args.p5 = 0;

    fn_8841F080((ts4_u32 *)&lbl_88CE42B4, (ts4_u32)&lbl_88041618, (ts4_u32)&lbl_88CE3EF4, 0, 0, 0, 0, 0, args.p1, args.p2, (ts4_u32)&lbl_88060A4C, args.p3, args.p4);
}