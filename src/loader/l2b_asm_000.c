/* Loader_DLL.xex 0x83114F58-0x83124C3C, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_830009F8[];
extern char lbl_8353102C[];
extern char lbl_8353104C[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830FFB68();
ts4_word fn_83109390();
ts4_word fn_8310D5D0();
ts4_word fn_83112428();
ts4_word fn_83112808();
ts4_word fn_831128F8();
ts4_word fn_83114888();
ts4_word fn_83114948();
ts4_word fn_831149E0();
ts4_word fn_83114A70();
ts4_word fn_83114B58();
ts4_word fn_83114B90();
ts4_word fn_83114BE0();
ts4_word fn_831168E8();
ts4_word fn_83116AF0();
ts4_word fn_8311CAE0();
ts4_word fn_8311D1C0();
ts4_word fn_8311DAD8();
ts4_word fn_83120540();
ts4_word fn_831233B8();
ts4_word fn_831233F0();
ts4_word fn_831235E8();
ts4_word fn_83123628();
ts4_word fn_83123810();
ts4_word fn_83123848();
ts4_word fn_83123898();
ts4_word fn_831238D0();
ts4_word fn_83123920();
ts4_word fn_83123958();
ts4_word fn_83123A70();
ts4_word fn_83123AC0();
ts4_word fn_83123B98();
ts4_word fn_83123BE8();
ts4_word fn_83123C28();
ts4_word fn_83123CF0();
ts4_word fn_83123D90();
ts4_word fn_83123DE0();
ts4_word fn_83123E40();
ts4_word fn_83123E90();
ts4_word fn_83123ED0();
ts4_word fn_831413A0();
ts4_word fn_83142508();
ts4_word fn_83144290();
ts4_word fn_831442B0();
ts4_word fn_83144868();
ts4_word fn_8340CE98();

/* Loader_DLL.xex 0x83114F58: call_seq fn_83114A70, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83114A70_83114F58(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t2;
    ts4_word t3;

    fn_83114A70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)a1;
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
    return t3;
}

/* Loader_DLL.xex 0x83114FB0: call_seq fn_831149E0, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_831149E0_83114FB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t2;
    ts4_word t3;

    fn_831149E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)a1;
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
    return t3;
}

/* Loader_DLL.xex 0x831150E8: call_seq fn_83114888, fn_83109390 */
ts4_word ts4l_call_seq_fn_83114888_831150E8(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83114888((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x83115208: call_seq fn_83114BE0, fn_83109390 */
ts4_word ts4l_call_seq_fn_83114BE0_83115208(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83114BE0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x831152B0: call_seq fn_83114B58, fn_83109390 */
ts4_word ts4l_call_seq_fn_83114B58_831152B0(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83114B58((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x831152F8: call_seq fn_83114B90, fn_83109390 */
ts4_word ts4l_call_seq_fn_83114B90_831152F8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83114B90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[1];
    return t3;
}

/* Loader_DLL.xex 0x83116A18: call_seq fn_831168E8, fn_83114948, fn_8310D5D0 */
ts4_word ts4l_call_seq_fn_831168E8_83116A18(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t3;

    fn_831168E8((ts4_word)a0, (ts4_word)a1);
    fn_83114948((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t3 = fn_8310D5D0((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t3;
}

/* Loader_DLL.xex 0x831186D0: if_call_seq u32@0xc, fn_83142508, fn_83120540, u32@0x0, fn_83120540, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_offc_831186D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_83142508((ts4_word)t1);
        fn_83120540((ts4_word)t1);
    }
    t6 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return t6;
}

/* Loader_DLL.xex 0x8311AE40: call_seq u32@0x0, fn_831442B0, u32@0x20, u32@0x1c, u32@0x24, u32@0x28 */
ts4_word ts4l_call_seq_u32_off0_8311AE40(ts4_word a0)
{
    ts4_word t1;
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = fn_831442B0((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t2 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 76) = t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    return t1;
}

/* Loader_DLL.xex 0x8311BA20: if_call_seq u32@0x3c, u32@0x40, fn_831413A0, u32@0x40, u32@0x34, u32@0x1c */
ts4_word ts4l_if_call_seq_u32_off3c_8311BA20(ts4_word a0)
{
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((int)t1 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        fn_83144868((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)t5, (ts4_word)t4);
    } else {
        fn_831413A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    fn_83144290((ts4_word)a0);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)1;
    t11 = fn_83120540((ts4_word)t10);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return t11;
}

/* Loader_DLL.xex 0x8311CC18: if_call_seq fn_8311CAE0, u32@0x2c, u32@0x24, u32@0x30, fn_831413A0, u32@0x30 */
ts4_word ts4l_if_call_seq_fn_8311CAE0_8311CC18(ts4_word a0)
{
    int t2;
    ts4_word t6;
    ts4_word t10;

    fn_8311CAE0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t2 == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((ts4_word)t6 != 0) {
            fn_83116AF0((ts4_word)t6, (ts4_word)3);
        }
    } else {
        fn_831413A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    t10 = fn_83144290((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)-1;
    return t10;
}

/* Loader_DLL.xex 0x8311D270: if_call_seq lbl_8353102C, RtlEnterCriticalSection, lbl_8353104C, fn_8311D1C0, u32@0x4, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_lbl_8353102C_8311D270(ts4_word a0)
{
    ts4_word p5;
    int t2;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353102C);
    t2 = fn_8311D1C0((ts4_word)(ts4_word)lbl_8353104C, (ts4_word)a0);
    if ((int)t2 == -1) {
        p5 = (ts4_word)0;
    } else {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((t2 << 2)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353104C) + 4))));
    }
    RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353102C);
    return p5;
}

/* Loader_DLL.xex 0x831205E8: loop_get u32@0x0, u16@0x0, u16@0x2, u32@0x4 */
ts4_word ts4l_loop_get_u32_off0_831205E8(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p6;
    ts4_word t1;
    unsigned short t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(unsigned short *)((char *)(ts4_word)(lv2) + 0);
            if ((ts4_word)(a1 & 0xffff) >= (ts4_word)t3 && (ts4_word)(a1 & 0xffff) <= (ts4_word)(*(unsigned short *)((char *)(ts4_word)(lv2) + 2))) {
                return 1;
            }
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 4));
            lv2 = p6;
        } while ((ts4_word)p6 != 0);
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83121CA0: call_seq u32@0x74, u32@0x7c, fn_8340CE98, u32@0x80, u32@0x0, fn_8311DAD8 */
ts4_word ts4l_call_seq_u32_off74_83121CA0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(float *)((char *)(ts4_word)(a0) + 104);
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)a1;
    *(float *)((char *)(ts4_word)(a0) + 120) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)a2;
    t2 = fn_8340CE98();
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)t2;
    t4 = fn_8311DAD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)1, (ts4_word)16);
    return t4;
}

/* Loader_DLL.xex 0x83122270: call_seq u32@0x84, fn_83112808, u32@0x84, fn_831128F8, u32@0x84, fn_83112428 */
ts4_word ts4l_call_seq_u32_off84_83122270(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)a2;
    fn_83112808((ts4_word)a2, (ts4_word)(a0 + 104));
    fn_831128F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)), (ts4_word)(a0 + 92));
    t5 = fn_83112428((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)2;
    return t5;
}

/* Loader_DLL.xex 0x831230A8: if_get  */
ts4_word ts4l_if_get_831230A8(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;
    float t6;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    if (!(t1 < t2)) {
        t3 = *(float *)((char *)(ts4_word)(a0) + 8);
        if (!(t1 > t3)) {
            t4 = *(float *)((char *)(ts4_word)(a1) + 4);
            t5 = *(float *)((char *)(ts4_word)(a0) + 4);
            if (!(t4 < t5)) {
                t6 = *(float *)((char *)(ts4_word)(a0) + 12);
                if (!(t4 > t6)) {
                    return 1;
                }
                return 0;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x831236F8: call_seq fn_831235E8, fn_83123628, u32@0x0, u32@0x4 */
ts4_word ts4l_call_seq_fn_831235E8_831236F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a3;
    fn_831235E8((ts4_word)a0, (ts4_word)a1, (ts4_word)4);
    t2 = fn_83123628((ts4_word)a1, (ts4_word)a2, (ts4_word)8);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)a5;
    return t2;
}

/* Loader_DLL.xex 0x83123780: call_seq fn_831235E8, fn_83123628, u32@0x0, u8@0x8 */
ts4_word ts4l_call_seq_fn_831235E8_83123780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a3;
    fn_831235E8((ts4_word)a0, (ts4_word)a1, (ts4_word)7);
    t2 = fn_83123628((ts4_word)a1, (ts4_word)a2, (ts4_word)12);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a5;
    *(unsigned char *)((char *)(ts4_word)(a2) + 8) = (unsigned char)a4;
    return t2;
}

/* Loader_DLL.xex 0x831237C8: call_seq fn_831235E8, fn_83123628, u32@0x0, u32@0x4 */
ts4_word ts4l_call_seq_fn_831235E8_831237C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a3;
    fn_831235E8((ts4_word)a0, (ts4_word)a1, (ts4_word)6);
    t2 = fn_83123628((ts4_word)a1, (ts4_word)a2, (ts4_word)8);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)a5;
    return t2;
}

/* Loader_DLL.xex 0x83124138: call_seq fn_831235E8, fn_83123628, u32@0x0, u32@0x4 */
ts4_word ts4l_call_seq_fn_831235E8_83124138(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a3;
    fn_831235E8((ts4_word)a0, (ts4_word)a1, (ts4_word)10);
    t2 = fn_83123628((ts4_word)a1, (ts4_word)a2, (ts4_word)8);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)a5;
    return t2;
}

/* Loader_DLL.xex 0x83124328: call_seq fn_831233B8, fn_83109390 */
ts4_word ts4l_call_seq_fn_831233B8_83124328(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_831233B8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x83124370: call_seq fn_831233F0, fn_83109390 */
ts4_word ts4l_call_seq_fn_831233F0_83124370(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_831233F0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x831244B8: call_seq fn_83123A70, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123A70_831244B8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123A70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124550: call_seq fn_83123AC0, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123AC0_83124550(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123AC0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[1];
    return t3;
}

/* Loader_DLL.xex 0x831246B8: call_seq fn_83123B98, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123B98_831246B8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123B98((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124700: call_seq fn_83123E90, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123E90_83124700(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123E90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124748: call_seq fn_83123D90, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123D90_83124748(ts4_word a0, ts4_word a1)
{
    ts4_word loc70[12];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_83123D90((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x831247A0: call_seq fn_83123DE0, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123DE0_831247A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc70[8];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_83123DE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)a1, (ts4_word)0, (ts4_word)0);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x83124800: call_seq fn_83123898, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123898_83124800(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123898((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x83124848: call_seq fn_831238D0, fn_83109390 */
ts4_word ts4l_call_seq_fn_831238D0_83124848(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_831238D0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124890: call_seq fn_83123920, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123920_83124890(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123920((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x831248D8: call_seq fn_83123958, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123958_831248D8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123958((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x831249E0: call_seq fn_83123810, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123810_831249E0(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123810((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x83124A28: call_seq fn_83123848, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123848_83124A28(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123848((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124A70: call_seq fn_83123BE8, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123BE8_83124A70(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123BE8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124AB8: call_seq fn_83123C28, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123C28_83124AB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83123C28((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124B00: call_seq fn_83123E40, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123E40_83124B00(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123E40((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[1];
    return t3;
}

/* Loader_DLL.xex 0x83124B48: call_seq fn_83123ED0, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123ED0_83124B48(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_83123ED0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[1];
    return t3;
}

/* Loader_DLL.xex 0x83124B90: call_seq fn_83123D90, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123D90_83124B90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc70[12];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_83123D90((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)0, (ts4_word)1, (ts4_word)a2);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x83124BE8: call_seq fn_83123CF0, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123CF0_83124BE8(ts4_word a0, ts4_word a1)
{
    ts4_word loc70[12];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t4;

    fn_83123CF0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)0, (ts4_word)1);
    t2 = fn_830FFB68((ts4_word)a0);
    fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc70[3];
    return t4;
}
