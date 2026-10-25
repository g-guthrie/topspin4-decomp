typedef unsigned int ts4_u32;

extern unsigned int lbl_8807ABE0;
extern unsigned int lbl_88C09960;
extern unsigned int lbl_88D19BF4;
extern unsigned int lbl_88043828;
extern unsigned int lbl_88D193E4;

ts4_u32 *fn_8841F080(ts4_u32 *record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

void fn_88ADC098(void) {
    struct {
        ts4_u32 p1;
        ts4_u32 p2;
        ts4_u32 p3;
        ts4_u32 p4;
        ts4_u32 p5;
    } args;

    args.p1 = (ts4_u32)&lbl_88C09960;
    args.p2 = 23;
    args.p3 = 0;
    args.p4 = 0;
    args.p5 = 0;

    fn_8841F080((ts4_u32 *)&lbl_88D193E4, (ts4_u32)&lbl_88043828, (ts4_u32)&lbl_88D19BF4, 0, 0, 0, 0, 0, args.p1, args.p2, (ts4_u32)&lbl_8807ABE0, args.p3, args.p4);
}