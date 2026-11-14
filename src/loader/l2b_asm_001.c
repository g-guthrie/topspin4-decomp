/* Loader_DLL.xex 0x83124500-0x8314DD28, executable version 0.0.0.3. */
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

extern char lbl_8352C070[];
extern char lbl_8353107C[];
extern char lbl_835311A8[];
extern char lbl_835311AC[];
extern char lbl_835312BC[];
extern char lbl_835312C0[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlInitializeCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830AF140();
ts4_word fn_830AF1B8();
ts4_word fn_830FF0B0();
ts4_word fn_830FFB68();
ts4_word fn_83109390();
ts4_word fn_83109520();
ts4_word fn_83110430();
ts4_word fn_831127B8();
ts4_word fn_83120540();
ts4_word fn_83122AD0();
ts4_word fn_83123478();
ts4_word fn_83123508();
ts4_word fn_83123558();
ts4_word fn_831235B0();
ts4_word fn_831236F8();
ts4_word fn_83123D48();
ts4_word fn_83123DE0();
ts4_word fn_83124050();
ts4_word fn_8312ACB0();
ts4_word fn_8312B060();
ts4_word fn_8312BD48();
ts4_word fn_8312D868();
ts4_word fn_83131B78();
ts4_word fn_831331A0();
ts4_word fn_831354C8();
ts4_word fn_83137498();
ts4_word fn_8313F3C0();
ts4_word fn_8313F3F8();
ts4_word fn_8313F480();
ts4_word fn_831428E0();
ts4_word fn_83143B40();
ts4_word fn_83146478();
ts4_word fn_831464D0();
ts4_word fn_83146578();
ts4_word fn_83148D30();
ts4_word fn_8314BFC0();
ts4_word fn_8314DF10();
ts4_word fn_8314E028();
ts4_word fn_8315DD18();
ts4_word fn_833E1C00();
ts4_word fn_833E4608();

/* Loader_DLL.xex 0x83124500: call_seq fn_831236F8, fn_83109520 */
ts4_word ts4l_call_seq_fn_831236F8_83124500(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word loc70[8];
    ts4_word t2;

    fn_831236F8((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    t2 = fn_83109520((ts4_word)a0, (ts4_word)(ts4_word)&loc70[0]);
    return t2;
}

/* Loader_DLL.xex 0x83124C40: call_seq fn_83123DE0, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123DE0_83124C40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc70[8];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_83123DE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)0, (ts4_word)1, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x83124CA0: call_seq fn_83123D48, fn_830FFB68, fn_83109390, u32@0x0 */
ts4_word ts4l_call_seq_fn_83123D48_83124CA0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc70[10];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    fn_83123D48((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)0, (ts4_word)1);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc70[4];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    return t3;
}

/* Loader_DLL.xex 0x83124DB8: call_seq fn_83123508, fn_830FFB68, fn_83109390, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4l_call_seq_fn_83123508_83124DB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[8];
    ts4_word loc70[8];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    fn_83123508((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc70[0]);
    t4 = loc50[1];
    t5 = loc50[2];
    t6 = loc50[3];
    t7 = loc50[4];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)t7;
    return t3;
}

/* Loader_DLL.xex 0x83124E20: call_seq fn_83123558, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_83123558_83124E20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc70[8];
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_83123558((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x83124E78: call_seq fn_831235B0, fn_83109390 */
ts4_word ts4l_call_seq_fn_831235B0_83124E78(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;

    fn_831235B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    return t3;
}

/* Loader_DLL.xex 0x83124EC0: call_seq fn_83124050, fn_83109390 */
ts4_word ts4l_call_seq_fn_83124050_83124EC0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83124050((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x831278B0: if_call_seq fn_830FFB68, fn_83123478, fn_83109390, fn_83110430 */
ts4_word ts4l_if_call_seq_fn_830FFB68_831278B0(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = fn_830FFB68((ts4_word)a0);
    fn_83123478((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t3 = fn_83109390((ts4_word)t1, (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    p6 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = fn_83110430((ts4_word)t1, (ts4_word)0);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8312AA60: set u32@0x4, u32@0x10, u32@0x14, u32@0x18, u32@0x1c, u32@0x20 */
void ts4l_set_u32_off4_8312AA60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)100;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 48) = (unsigned short)48;
    *(unsigned short *)((char *)(ts4_word)(a0) + 50) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8312B4E8: call_seq u32@lbl_8352C070, fn_8312B060, fn_8314E028, fn_833E4608 */
ts4_word ts4l_call_seq_u32_lbl_8352C070_8312B4E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[20];
    ts4_word t4;
    ts4_word t5;

    loc50[16] = (ts4_word)(*(ts4_word *)lbl_8352C070);
    fn_8312B060((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc50[0]);
    fn_8314E028((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[16];
    t5 = fn_833E4608((ts4_word)t4);
    return t5;
}

/* Loader_DLL.xex 0x8312BF98: call_seq fn_8312BD48 */
ts4_word ts4l_call_seq_fn_8312BD48_8312BF98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_8312BD48((ts4_word)0, (ts4_word)0, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Loader_DLL.xex 0x8312CE30: call_seq u32@lbl_8352C070, fn_831127B8, fn_8315DD18, fn_8315DD18, fn_8315DD18, fn_8315DD18 */
ts4_word ts4l_call_seq_u32_lbl_8352C070_8312CE30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[20];
    ts4_word t7;
    ts4_word t8;

    (void)a0;
    loc50[16] = (ts4_word)(*(ts4_word *)lbl_8352C070);
    fn_831127B8((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    fn_8315DD18((ts4_word)a2, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    fn_8315DD18((ts4_word)(a2 + 12), (ts4_word)(a2 + 12), (ts4_word)(ts4_word)&loc50[0]);
    fn_8315DD18((ts4_word)(a2 + 24), (ts4_word)(a2 + 24), (ts4_word)(ts4_word)&loc50[0]);
    fn_8315DD18((ts4_word)(a2 + 36), (ts4_word)(a2 + 36), (ts4_word)(ts4_word)&loc50[0]);
    t7 = loc50[16];
    t8 = fn_833E4608((ts4_word)t7);
    return t8;
}

/* Loader_DLL.xex 0x8312D4E0: call_seq u32@0x0, fn_83120540, u32@0x0, u32@0xc, u32@0x4, fn_83122AD0 */
ts4_word ts4l_call_seq_u32_off0_8312D4E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t3 = fn_83122AD0((ts4_word)a0, (ts4_word)a1);
    return t3;
}

/* Loader_DLL.xex 0x8312DF00: call_seq fn_8312D868, u32@0x0, fn_8314DF10 */
ts4_word ts4l_call_seq_fn_8312D868_8312DF00(ts4_word a0, ts4_word a1)
{
    fn_8312D868();
    fn_8314DF10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)(a0 + 164));
    return 0;
}

/* Loader_DLL.xex 0x83135580: if_call_seq u32@0x94, fn_8312ACB0, fn_831354C8, u32@0x94, u32@0x94, fn_83131B78 */
ts4_word ts4l_if_call_seq_u32_off94_83135580(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 != 0) {
        fn_8312ACB0((ts4_word)a0, (ts4_word)1);
        fn_831354C8((ts4_word)a0, (ts4_word)1);
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 148)) | 4);
    } else {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 148)) & 0xfffffffb);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)p5;
    t7 = fn_83131B78((ts4_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83135658: if_get u32@0x8c, u32@0x90, u32@0x5c, u32@0x74, u32@0x6c, u32@0x90 */
ts4_word ts4l_if_get_u32_off8c_83135658(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)a1;
    if ((ts4_word)a1 < (ts4_word)t1) {
        *(volatile unsigned short *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 92))) + (a1 << 1)) = (unsigned short)0;
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108);
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t8 < (ts4_word)(t7 + t6)) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(t8 - t6);
    }
    return fn_83131B78((ts4_word)a0);
}

/* Loader_DLL.xex 0x83136B30: call_seq fn_833E1C00, fn_831331A0 */
ts4_word ts4l_call_seq_fn_833E1C00_83136B30(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833E1C00((ts4_word)a1);
    t2 = fn_831331A0((ts4_word)a0, (ts4_word)a1, (ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x8313C2E8: call_seq fn_83137498, fn_83120540 */
ts4_word ts4l_call_seq_fn_83137498_8313C2E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_83137498((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    fn_83120540((ts4_word)0);
    return t1;
}

/* Loader_DLL.xex 0x8313CE40: if_call_seq u32@0x4, fn_83120540, u32@0x8, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_8313CE40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        fn_83120540((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_83120540((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8313D0C0: if_call_seq u32@0x24, fn_83120540, u32@0x18, fn_83120540, u32@0xc, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off24_8313D0C0(ts4_word a0)
{
    ts4_word p12;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t7 != 0) {
        fn_83120540((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = fn_83120540((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Loader_DLL.xex 0x8313F758: call_seq fn_8313F3C0, u32@0x0, fn_830FFB68, fn_83109390 */
ts4_word ts4l_call_seq_fn_8313F3C0_8313F758(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t3;
    ts4_word t5;

    fn_8313F3C0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t3 = fn_830FFB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    fn_83109390((ts4_word)t3, (ts4_word)(ts4_word)&loc60[0]);
    t5 = loc50[0];
    return t5;
}

/* Loader_DLL.xex 0x8313F7A0: if_call_seq fn_8313F480, fn_830FFB68, fn_83109390 */
ts4_word ts4l_if_call_seq_fn_8313F480_8313F7A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)((2147942400) | 87);
    if ((ts4_word)a0 != 0) {
        fn_8313F480((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
        t2 = fn_830FFB68((ts4_word)a0);
        t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8313F8D0: if_call_seq fn_8313F3F8, fn_830FFB68, fn_83109390 */
ts4_word ts4l_if_call_seq_fn_8313F3F8_8313F8D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)((2147942400) | 87);
    if ((ts4_word)a0 != 0) {
        fn_8313F3F8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
        t2 = fn_830FFB68((ts4_word)a0);
        t3 = fn_83109390((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83140140: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0xc, RtlInitializeCriticalSection */
ts4_word ts4l_call_seq_u32_off0_83140140(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    RtlInitializeCriticalSection((ts4_word)(a0 + 16));
    return a0;
}

/* Loader_DLL.xex 0x83140430: if_call_seq u32@0x0, u32@0x4, fn_83120540, u32@0x4, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83140430(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)a0;
    if ((int)t1 == 5) {
        t3 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p4;
}

/* Loader_DLL.xex 0x83142AA8: call_seq fn_831428E0, fn_83120540 */
ts4_word ts4l_call_seq_fn_831428E0_83142AA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_831428E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    t2 = loc50[0];
    fn_83120540((ts4_word)t2);
    return t1;
}

/* Loader_DLL.xex 0x83142E68: call_seq fn_83148D30, fn_83148D30, fn_83148D30, u32@0x3c, u32@0x44 */
ts4_word ts4l_call_seq_fn_83148D30_83142E68(ts4_word a0)
{
    fn_83148D30((ts4_word)a0);
    fn_83148D30((ts4_word)(a0 + 20));
    fn_83148D30((ts4_word)(a0 + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83144170: if_call_seq u32@0x4, fn_83120540, fn_83143B40, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_83144170(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        fn_83143B40((ts4_word)a0);
        fn_83120540((ts4_word)a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x83146618: if_call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_83146478, u32@lbl_835311AC, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_8353107C_83146618(void)
{
    ts4_word t4;
    ts4_word t7;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    fn_83146478((ts4_word)(*(ts4_word *)lbl_835311AC));
    t4 = *(ts4_word *)lbl_835311AC;
    if ((ts4_word)t4 != 0) {
        fn_83120540((ts4_word)t4);
    }
    *(ts4_word *)lbl_835311AC = (ts4_word)0;
    t7 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t7;
}

/* Loader_DLL.xex 0x831466E0: if_call_seq lbl_835311A8, u32@lbl_835311A8, lbl_8353107C, RtlEnterCriticalSection, u32@0x4, fn_831464D0 */
ts4_word ts4l_if_call_seq_lbl_835311A8_831466E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    int t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_835311A8;
    p6 = (ts4_word)a0;
    if ((int)t1 != 0) {
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
        fn_831464D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835311A8) + 4)));
        t5 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83146818: if_call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_83146578, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_lbl_8353107C_83146818(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t2 = *(ts4_word *)lbl_835311AC;
    if ((ts4_word)t2 != 0) {
        fn_83146578((ts4_word)t2, (ts4_word)a0);
    }
    t5 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t5;
}

/* Loader_DLL.xex 0x83146878: if_call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_83146478, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_lbl_8353107C_83146878(void)
{
    ts4_word t2;
    ts4_word t5;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t2 = *(ts4_word *)lbl_835311AC;
    if ((ts4_word)t2 != 0) {
        fn_83146478((ts4_word)t2);
    }
    t5 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t5;
}

/* Loader_DLL.xex 0x83148000: if_call_seq u32@0x0, fn_83120540, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off0_83148000(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_83120540((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83148B08: call_seq u32@0x0, fn_83120540, u32@0xc, u32@0x0, fn_83120540, u32@0xc */
ts4_word ts4l_call_seq_u32_off0_83148B08(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t4 = fn_83120540((ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return t4;
}

/* Loader_DLL.xex 0x83149448: if_call_seq fn_830AF140, u32@0x8, fn_830AF1B8, u32@0x8, u32@0x8 */
ts4_word ts4l_if_call_seq_fn_830AF140_83149448(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    fn_830AF140((ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = fn_830AF1B8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return p4;
}

/* Loader_DLL.xex 0x831495D8: loop_call_seq u32@0x10, u32@0x10, fn_830FF0B0, u32@0x10, u32@0x10 */
ts4_word ts4l_loop_call_seq_u32_off10_831495D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 16);
            fn_830FF0B0((ts4_word)lv2);
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            p6 = (ts4_word)t3;
            lv2 = p6;
        } while ((ts4_word)p6 != (ts4_word)t5);
        p7 = (ts4_word)lv2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return p7;
}

/* Loader_DLL.xex 0x83149FD8: call_seq u32@0x4, u32@0x0, fn_83120540, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4l_call_seq_u32_off4_83149FD8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_83120540((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t6 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return t6;
}

/* Loader_DLL.xex 0x8314BEB8: if_get u32@0x9c, u32@0xb4, u32@0xb4, u32@0x14c, u32@0x0, u32@0x5c */
ts4_word ts4l_if_get_u32_off9c_8314BEB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;
    int t3;
    ts4_word t4;

    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((int)t1 != 0) {
        return ((2147483648) | 65535);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
    if ((int)t3 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 92))))((ts4_word)t4, (ts4_word)a2, (ts4_word)a3, (ts4_word)a1, (ts4_word)0, (ts4_word)a5, (ts4_word)a6, (ts4_word)t3);
    }
    return 0;
}

/* Loader_DLL.xex 0x8314DB00: if_get u32@lbl_835312BC, u32@lbl_835312C0, u32@lbl_835312C0, u32@0xc */
ts4_word ts4l_if_get_u32_lbl_835312BC_8314DB00(ts4_word a0)
{
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)lbl_835312BC;
    if ((ts4_word)t1 == 0) {
        return ((2147483648) | 65535);
    }
    t3 = *(ts4_word *)lbl_835312C0;
    if ((int)t3 == 0) {
        return ((2150629376) | 48);
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a0;
    return 0;
}

/* Loader_DLL.xex 0x8314DCD8: if_get u32@lbl_835312BC, u32@lbl_835312C0, u32@lbl_835312C0, fn_8314BFC0 */
ts4_word ts4l_if_get_u32_lbl_835312BC_8314DCD8(ts4_word a0)
{
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)lbl_835312BC;
    if ((ts4_word)t1 == 0) {
        return ((2147483648) | 65535);
    }
    t3 = *(ts4_word *)lbl_835312C0;
    if ((int)t3 == 0) {
        return ((2150629376) | 48);
    }
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return fn_8314BFC0((ts4_word)a0, (ts4_word)t1);
}
