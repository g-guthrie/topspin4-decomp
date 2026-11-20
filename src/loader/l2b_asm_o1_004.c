/* Loader_DLL.xex 0x83149E90-0x8315F568, executable version 0.0.0.3. */
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

extern char lbl_83003F24[];
extern char lbl_83003F80[];
extern char lbl_83004214[];
extern char lbl_83004248[];
extern char lbl_83004264[];
extern char lbl_83004280[];
extern char lbl_830049A0[];
extern char lbl_830055D8[];
extern char lbl_83527E10[];
extern char lbl_835312B8[];
extern char lbl_835312C4[];
extern char lbl_835312D0[];
extern char lbl_835312EC[];
extern char lbl_835312F4[];
extern char lbl_835312FC[];
extern char lbl_83531304[];
extern char lbl_83531330[];
extern char lbl_83531658[];
extern char lbl_8353165C[];
extern char lbl_83531660[];
extern char lbl_83531664[];
extern char lbl_83531668[];
extern char lbl_8353166C[];
extern char lbl_83531670[];
extern char lbl_83531674[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830AF1B8();
ts4_word fn_830C1B40();
ts4_word fn_830C1FA8();
ts4_word fn_830C2240();
ts4_word fn_83120518();
ts4_word fn_83120520();
ts4_word fn_83120540();
ts4_word fn_83149448();
ts4_word fn_83149E08();
ts4_word fn_83149FD8();
ts4_word fn_8314B8C0();
ts4_word fn_8314CAC8();
ts4_word fn_8314CEC0();
ts4_word fn_8314D270();
ts4_word fn_8314D640();
ts4_word fn_83150F98();
ts4_word fn_83151108();
ts4_word fn_83151598();
ts4_word fn_83153048();
ts4_word fn_83154BA8();
ts4_word fn_83155820();
ts4_word fn_83156600();
ts4_word fn_831592B8();
ts4_word fn_8315B628();
ts4_word fn_8315C880();
ts4_word fn_8315E760();
ts4_word fn_83162FA0();

/* Loader_DLL.xex 0x83149E90: if_call_seq fn_83149E08, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83149E08_83149E90(ts4_word a0, ts4_word a1)
{

    fn_83149E08((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314E0B8: if_get u32@0x0, u32@0x0, vcall */
ts4_word ts4l_if_get_u32_off0_8314E0B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p4 = (ts4_word)((2147942400) | 87);
    } else {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8314E580: if_get u32@0x4, u32@0x0, u32@0x8, u32@0x0, u32@0xc, u32@0x0 */
ts4_word ts4l_if_get_u32_off4_8314E580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    if (((((ts4_word)a1 != 0 && (ts4_word)a2 != 0) && (ts4_word)a3 != 0) && (ts4_word)a4 != 0) && (ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)) * 3);
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8314E600: get u32@lbl_835312C4, u32@lbl_835312B8, u32@lbl_835312B8, u32@0x0, u32@0xc0, vcall */
ts4_word ts4l_get_u32_lbl_835312C4_8314E600(void)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)lbl_835312C4;
    *(ts4_word *)lbl_835312B8 = (ts4_word)((*(ts4_word *)lbl_835312B8) + 1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 192))))((ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 44))))((ts4_word)t5);
    t9 = fn_83156600((ts4_word)t8);
    return t9;
}

/* Loader_DLL.xex 0x8314EA48: if_call_seq u32@0x8, lbl_83004214, u32@0x0, fn_830AF1B8, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off8_8314EA48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004214;
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x8314EBB0: call_seq lbl_83004214, u32@0x8, u32@0x0, u32@0x4, fn_83149448 */
ts4_word ts4l_call_seq_lbl_83004214_8314EBB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004214;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    fn_83149448((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Loader_DLL.xex 0x8314EC88: if_call_seq lbl_83003F24, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83003F24_8314EC88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314EE70: call_seq lbl_83004248, u32@0x0, fn_8314CAC8, lbl_83003F24, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83004248_8314EE70(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004248;
    t1 = fn_8314CAC8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    return t1;
}

/* Loader_DLL.xex 0x8314EEB8: if_call_seq lbl_83004248, u32@0x0, fn_8314CAC8, lbl_83003F24, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83004248_8314EEB8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004248;
    fn_8314CAC8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314F060: call_seq lbl_83004264, u32@0x0, fn_8314CEC0, lbl_83003F24, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83004264_8314F060(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004264;
    t1 = fn_8314CEC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    return t1;
}

/* Loader_DLL.xex 0x8314F0A8: if_call_seq lbl_83004264, u32@0x0, fn_8314CEC0, lbl_83003F24, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83004264_8314F0A8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004264;
    fn_8314CEC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314F250: call_seq lbl_83004280, u32@0x0, fn_8314D270, lbl_83003F24, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83004280_8314F250(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004280;
    t1 = fn_8314D270((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    return t1;
}

/* Loader_DLL.xex 0x8314F298: if_call_seq lbl_83004280, u32@0x0, fn_8314D270, lbl_83003F24, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83004280_8314F298(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004280;
    fn_8314D270((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314F9C0: if_call_seq lbl_83003F80, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83003F80_8314F9C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F80;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8314FA08: if_get u32@0x0, u32@0x14, vcall, fn_8314D640 */
ts4_word ts4l_if_get_u32_off0_8314FA08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p6;
    int t3;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        p6 = (ts4_word)((2147942400) | 87);
    } else {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)1);
        p5 = (ts4_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_8314D640((ts4_word)a1, (ts4_word)a0);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8314FC70: if_call_seq fn_8314B8C0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8314B8C0_8314FC70(ts4_word a0, ts4_word a1)
{

    fn_8314B8C0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83150AF8: if_call_seq fn_83149FD8, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83149FD8_83150AF8(ts4_word a0, ts4_word a1)
{

    fn_83149FD8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83150B48: if_call_seq fn_83149FD8, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83149FD8_83150B48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p3 = (ts4_word)((2147942400) | 87);
    } else {
        fn_83149FD8((ts4_word)a0);
        fn_83120540((ts4_word)a0);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x831513A0: if_call_seq RtlEnterCriticalSection, u32@lbl_835312B8, u32@0x2c, fn_83150F98, u32@0x4c, u32@0x44 */
ts4_word ts4l_if_call_seq_RtlEnterCriticalSection_831513A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p8 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        RtlEnterCriticalSection((ts4_word)(a0 + 100));
        *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)lbl_835312B8);
        fn_83150F98((ts4_word)a0, (ts4_word)a1);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        if ((ts4_word)t4 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)a1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(t4) + 68) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(a1) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)a1;
        t7 = RtlLeaveCriticalSection((ts4_word)(a0 + 100));
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Loader_DLL.xex 0x83151418: if_call_seq fn_83151108, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83151108_83151418(ts4_word a0, ts4_word a1)
{

    fn_83151108((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83151628: if_get u32@0x40, u32@0x3c, u32@0x3c, u32@0x4, u32@0x3c, u32@0x3c */
ts4_word ts4l_if_get_u32_off40_83151628(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 64);
    if ((ts4_word)t1 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)((((t3 - ((int)(t3 / 17) * 17)) + 1) << 2)) + a0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    } else {
        *(ts4_word *)((char *)(ts4_word)(t1) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    if ((ts4_word)t8 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t8) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    }
    return fn_83150F98((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83151700: if_call_seq lbl_83003F24, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83003F24_83151700(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F24;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831527A0: if_call_seq fn_83151598, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83151598_831527A0(ts4_word a0, ts4_word a1)
{

    fn_83151598();
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83152FA8: if_get u32@0x20, u32@0x20, u32@0x0, u32@0x4, vcall, u32@0x20 */
ts4_word ts4l_if_get_u32_off20_83152FA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p11 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
        p6 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)0;
            *(unsigned short *)((char *)(ts4_word)(a1) + 44) = (unsigned short)0;
            *(unsigned char *)((char *)(ts4_word)(a1) + 28) = (unsigned char)0;
            p6 = (ts4_word)t5;
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 804);
        if ((ts4_word)t7 < 100) {
            *(ts4_word *)((char *)(ts4_word)(((t7 + 101) << 2)) + a0) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 804) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 804)) + 1);
            p10 = (ts4_word)p6;
        } else {
            t8 = fn_83120540((ts4_word)a1);
            p10 = (ts4_word)t8;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x83153EE8: if_get u32@0x50, u32@0x4c, u32@0xcc, u32@0x4c, u32@0x4c, u32@0x4c */
void ts4l_if_get_u32_off50_83153EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 80);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
    if ((ts4_word)t6 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t6) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 80) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83153F48: loop_call_seq lbl_835312D0, u32@lbl_835312FC, u32@lbl_835312FC, RtlEnterCriticalSection, u32@lbl_835312F4, u32@0x18 */
ts4_word ts4l_loop_call_seq_lbl_835312D0_83153F48(void)
{
    ts4_word lv4;
    ts4_word p6;
    ts4_word t7;

    *(volatile ts4_word *)lbl_835312FC = (ts4_word)((*(volatile ts4_word *)lbl_835312FC) + 1);
    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_835312D0);
    lv4 = (ts4_word)(*(volatile ts4_word *)lbl_835312F4);
    while ((ts4_word)lv4 != 0) {
        p6 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv4) + 24));
        lv4 = p6;
    }
    t7 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_835312D0);
    return t7;
}

/* Loader_DLL.xex 0x831546C8: if_set u32@lbl_83527E10, u32@lbl_83527E10, u32@lbl_83527E10, u32@lbl_83527E10, u32@lbl_83527E10, u32@lbl_83527E10 */
ts4_word ts4l_if_set_u32_lbl_83527E10_831546C8(ts4_word a0)
{
    if ((int)(a0 & 0xffc0ffff) == 0) {
        if ((int)(a0 & 0x10000) != 0) {
            if ((int)(a0 & 0x20000) == 0) {
                if ((int)(a0 & 0x40000) != 0) {
                    if ((int)(a0 & 0x80000) == 0) {
                        if ((int)(a0 & 0x100000) != 0) {
                            if ((int)(a0 & 0x200000) == 0) {
                                *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                                return 0;
                            }
                            return ((2147942400) | 87);
                        }
                        *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                        return 0;
                    }
                    return ((2147942400) | 87);
                }
                if ((int)(a0 & 0x100000) != 0) {
                    if ((int)(a0 & 0x200000) == 0) {
                        *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                        return 0;
                    }
                    return ((2147942400) | 87);
                }
                *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                return 0;
            }
            return ((2147942400) | 87);
        }
        if ((int)(a0 & 0x40000) != 0) {
            if ((int)(a0 & 0x80000) == 0) {
                if ((int)(a0 & 0x100000) != 0) {
                    if ((int)(a0 & 0x200000) == 0) {
                        *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                        return 0;
                    }
                    return ((2147942400) | 87);
                }
                *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                return 0;
            }
            return ((2147942400) | 87);
        }
        if ((int)(a0 & 0x100000) != 0) {
            if ((int)(a0 & 0x200000) == 0) {
                *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
                return 0;
            }
            return ((2147942400) | 87);
        }
        *(ts4_word *)lbl_83527E10 = (ts4_word)a0;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83155FA8: if_call_seq fn_83154BA8, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83154BA8_83155FA8(ts4_word a0, ts4_word a1)
{

    fn_83154BA8();
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83156D60: if_addr fn_83156600, lbl_835312EC, u32@0xc, u32@0x8, u32@0x0, u32@0x4 */
ts4_word ts4l_if_addr_fn_83156600_83156D60(ts4_word a0)
{
    ts4_word p16;
    ts4_word t2;
    ts4_word t8;
    ts4_word t14;
    ts4_word t15;

    fn_83156600();
    t2 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 12);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 8) = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 12) = (ts4_word)0;
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 0);
    if ((ts4_word)t8 != 0) {
        fn_83120520((ts4_word)t8);
        fn_83120540((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 0)));
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312EC) + 0) = (ts4_word)0;
    }
    t14 = fn_83153048((ts4_word)(ts4_word)lbl_83531330);
    p16 = (ts4_word)t14;
    if ((int)(a0 & 0xff) == 0) {
        t15 = fn_83155820((ts4_word)(ts4_word)lbl_83531304);
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Loader_DLL.xex 0x83159450: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4_word ts4l_if_get_u32_off0_83159450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Loader_DLL.xex 0x831594A8: if_get u32@0x0, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4_word ts4l_if_get_u32_off0_831594A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Loader_DLL.xex 0x831597A8: loop_get u32@0x0, u32@0x8, vcall, u32@0x18 */
ts4_word ts4l_loop_get_u32_off0_831597A8(ts4_word a0)
{
    ts4_word lv1;
    ts4_word p6;

    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 8))))((ts4_word)lv1);
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 24));
        lv1 = p6;
    }
    return 0;
}

/* Loader_DLL.xex 0x8315A678: if_get u32@0x0, u32@0x8, vcall, u32@0x10, fn_830C1FA8, u32@0xc */
ts4_word ts4l_if_get_u32_off0_8315A678(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != 0) {
        fn_830C1FA8((ts4_word)t3, (ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t7 != 0) {
        fn_830C2240((ts4_word)t3, (ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t10 != 0) {
        fn_830C1B40((ts4_word)t3, (ts4_word)t10);
    }
    return 0;
}

/* Loader_DLL.xex 0x8315B4F8: loop_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0xc, u32@0x0, u32@0x4 */
void ts4l_loop_call_seq_u32_off0_8315B4F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    while ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 12);
        if ((ts4_word)t6 != 0) {
            fn_830AF1B8((ts4_word)t6);
        }
        fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t7;
    }
    return;
}

/* Loader_DLL.xex 0x8315B560: call_seq fn_83120518, fn_831592B8, u32@0x0, u32@0x4, u32@0x8, u32@0x0 */
ts4_word ts4l_call_seq_fn_83120518_8315B560(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_83120518((ts4_word)16);
    t2 = fn_831592B8((ts4_word)a0, (ts4_word)a2);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return t2;
}

/* Loader_DLL.xex 0x8315B730: if_call_seq u32@lbl_83531658, fn_830AF1B8, u32@lbl_83531658, u32@lbl_8353165C, fn_830AF1B8, u32@lbl_8353165C */
ts4_word ts4l_if_call_seq_u32_lbl_83531658_8315B730(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p27;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t14;
    ts4_word t20;
    ts4_word t24;
    ts4_word t25;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)lbl_83531658;
    if ((ts4_word)t1 != 0) {
        fn_830AF1B8((ts4_word)t1);
        *(ts4_word *)lbl_83531658 = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)lbl_8353165C;
    if ((ts4_word)t4 != 0) {
        fn_830AF1B8((ts4_word)t4);
        *(ts4_word *)lbl_8353165C = (ts4_word)0;
    }
    t7 = *(volatile ts4_word *)lbl_83531660;
    if ((ts4_word)t7 != 0) {
        fn_830AF1B8((ts4_word)t7);
        *(ts4_word *)lbl_83531660 = (ts4_word)0;
    }
    t10 = *(volatile ts4_word *)lbl_83531664;
    if ((ts4_word)t10 != 0) {
        fn_830AF1B8((ts4_word)t10);
        *(ts4_word *)lbl_83531664 = (ts4_word)0;
    }
    loc50[0] = (ts4_word)0;
    t13 = *(volatile ts4_word *)lbl_83531668;
    if ((ts4_word)t13 != 0) {
        t14 = fn_8315B628((ts4_word)(ts4_word)lbl_83531674, (ts4_word)t13, (ts4_word)(ts4_word)&loc50[0]);
        if ((int)(t14 & 0xff) == 0) {
            fn_830AF1B8((ts4_word)(*(volatile ts4_word *)lbl_83531668));
        }
        *(ts4_word *)lbl_83531668 = (ts4_word)0;
    }
    t20 = *(volatile ts4_word *)lbl_8353166C;
    if ((ts4_word)t20 != 0) {
        fn_830AF1B8((ts4_word)t20);
        *(ts4_word *)lbl_8353166C = (ts4_word)0;
    }
    t24 = *(volatile ts4_word *)lbl_83531670;
    p27 = (ts4_word)t24;
    if ((ts4_word)t24 != 0) {
        t25 = fn_830AF1B8((ts4_word)t24);
        *(ts4_word *)lbl_83531670 = (ts4_word)0;
        p27 = (ts4_word)t25;
    }
    return p27;
}

/* Loader_DLL.xex 0x8315C668: if_call_seq lbl_830049A0, u32@0x0, u32@0xc, fn_830AF1B8, u32@0xc, u32@0x10 */
ts4_word ts4l_if_call_seq_lbl_830049A0_8315C668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p11;
    ts4_word p12;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830049A0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_830AF1B8((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_830AF1B8((ts4_word)t4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    loc50[0] = (ts4_word)0;
    p12 = (ts4_word)p6;
    if ((ts4_word)t7 != 0) {
        t8 = fn_8315B628((ts4_word)(ts4_word)lbl_83531674, (ts4_word)t7, (ts4_word)(ts4_word)&loc50[0]);
        p11 = (ts4_word)t8;
        if ((int)(t8 & 0xff) == 0) {
            t10 = fn_830AF1B8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
            p11 = (ts4_word)t10;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        p12 = (ts4_word)p11;
    }
    return p12;
}

/* Loader_DLL.xex 0x8315D680: if_call_seq fn_8315C880, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C880_8315D680(ts4_word a0, ts4_word a1)
{

    fn_8315C880((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315E7A8: if_addr lbl_830055D8, u32@0x0, fn_8315E760, u32@0x90, u32@0x0, u32@0x4 */
ts4_word ts4l_if_addr_lbl_830055D8_8315E7A8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830055D8;
    fn_8315E760((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    p6 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    return p6;
}

/* Loader_DLL.xex 0x8315F520: if_call_seq u32@0x4, u32@0x4, fn_83162FA0, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = fn_83162FA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)t1);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}
