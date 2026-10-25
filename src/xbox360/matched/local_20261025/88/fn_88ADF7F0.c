typedef unsigned int ts4_u32;

extern unsigned int lbl_88C0C240;
extern unsigned int lbl_88D1A9A4;
extern unsigned int lbl_880469DC;
extern unsigned int lbl_88D1AA34;

ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void fn_88ADF7F0(void) {
    struct {
        ts4_u32 p1;
        ts4_u32 p2;
        ts4_u32 p3;
        ts4_u32 p4;
        ts4_u32 p5;
    } args;

    args.p1 = (ts4_u32)&lbl_88C0C240;
    args.p2 = 1;
    args.p3 = 0;
    args.p4 = 0;
    args.p5 = 0;

    fn_8841F080((ts4_u32 *)&lbl_88D1AA34, (ts4_u32)&lbl_880469DC, (ts4_u32)&lbl_88D1A9A4, 0, 0, 1, 0, 0, args.p1, args.p2, args.p3, args.p4, args.p5);
}