/* Loader_DLL.xex 0x83225088-0x832523E8, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char fn_83249C90[];
extern char fn_83249E48[];
extern char fn_83249F00[];
extern char fn_83249FE0[];
extern char lbl_830009E0[];
extern char lbl_8302B1E8[];
extern char lbl_8302B8A0[];
extern char lbl_8302B908[];
extern char lbl_8302B968[];
extern char lbl_8302BAB0[];
ts4l_word RtlInitializeCriticalSection();
ts4l_word fn_830AAAC0();
ts4l_word fn_830AAAE8();
ts4l_word fn_83224508();
ts4l_word fn_83227008();
ts4l_word fn_8322C248();
ts4l_word fn_8322CA20();
ts4l_word fn_8322EA10();
ts4l_word fn_8322EEE8();
ts4l_word fn_83231640();
ts4l_word fn_83233830();
ts4l_word fn_83233AE8();
ts4l_word fn_83233D10();
ts4l_word fn_83234000();
ts4l_word fn_832341A0();
ts4l_word fn_83234D50();
ts4l_word fn_83235280();
ts4l_word fn_83236198();
ts4l_word fn_832361A0();
ts4l_word fn_832386E0();
ts4l_word fn_8323A7F8();
ts4l_word fn_8324DEA8();
ts4l_word fn_8324E448();
ts4l_word fn_8324E540();
ts4l_word fn_8324F9C8();
ts4l_word fn_8324FF60();
ts4l_word fn_83251168();
ts4l_word fn_832515D8();
ts4l_word fn_83252310();
ts4l_word fn_833E3A30();
ts4l_word fn_833E7330();
ts4l_word fn_8340A360();
ts4l_word fn_8340CE10();
ts4l_word fn_8340CE90();
ts4l_word fn_8340D710();
ts4l_word fn_8340D830();

/* Loader_DLL.xex 0x83225088: call_seq lbl_8302B1E8, u32@0x0, fn_83224508, fn_8322EEE8, fn_8322EEE8, fn_8322EEE8 */
ts4l_word ts4l_call_seq_lbl_8302B1E8_83225088(ts4l_word a0)
{
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B1E8;
    fn_83224508((ts4l_word)a0);
    fn_8322EEE8((ts4l_word)(a0 + 212));
    fn_8322EEE8((ts4l_word)(a0 + 140));
    fn_8322EEE8((ts4l_word)(a0 + 68));
    t5 = fn_83227008((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x832250E0: if_call_seq lbl_8302B1E8, u32@0x0, fn_83224508, fn_8322EEE8, fn_8322EEE8, fn_8322EEE8 */
ts4l_word ts4l_if_call_seq_lbl_8302B1E8_832250E0(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B1E8;
    fn_83224508((ts4l_word)a0);
    fn_8322EEE8((ts4l_word)(a0 + 212));
    fn_8322EEE8((ts4l_word)(a0 + 140));
    fn_8322EEE8((ts4l_word)(a0 + 68));
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32817));
    }
    return a0;
}

/* Loader_DLL.xex 0x83226FC0: call_seq u32@0x4, u32@0x8, u32@0xc, RtlInitializeCriticalSection */
ts4l_word ts4l_call_seq_u32_off4_83226FC0(ts4l_word a0)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)a0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)a0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)1;
    RtlInitializeCriticalSection((ts4l_word)(a0 + 16));
    return a0;
}

/* Loader_DLL.xex 0x83227440: get fn_8322C248, u32@0x88, u32@0x3c, vcall, u32@0x1f8, u32@0x1f4 */
ts4l_word ts4l_get_fn_8322C248_83227440(ts4l_word a0)
{
    ts4l_word t4;

    fn_8322C248((ts4l_word)a0);
    t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 136))) + 60))))((ts4l_word)(a0 + 136));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 504) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 500) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 508) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 512) = (ts4l_word)1;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 128) = (ts4l_u64)0;
    return t4;
}

/* Loader_DLL.xex 0x8322C398: get fn_8322C248, u32@0x7c, u32@0x3c, vcall, u32@0x294 */
ts4l_word ts4l_get_fn_8322C248_8322C398(ts4l_word a0)
{
    ts4l_word t4;

    fn_8322C248((ts4l_word)a0);
    t4 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 124))) + 60))))((ts4l_word)(a0 + 124));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 660) = (ts4l_word)0;
    return t4;
}

/* Loader_DLL.xex 0x8322CCB8: if_call_seq fn_8322CA20, fn_8340D710, fn_833E3A30, u32@0x188, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_8322CA20_8322CCB8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 == 0) {
        p5 = (ts4l_word)2;
    } else {
        fn_8322CA20((ts4l_word)a0);
        t2 = fn_8340D710((ts4l_word)624, (ts4l_word)((613154816) | 32768));
        if ((ts4l_word)t2 == 0) {
            p4 = (ts4l_word)1;
        } else {
            fn_833E3A30((ts4l_word)t2, (ts4l_word)0, (ts4l_word)624);
            *(ts4l_word *)((char *)(ts4l_word)(t2) + 392) = (ts4l_word)1;
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)t2;
            p4 = (ts4l_word)0;
        }
        p5 = (ts4l_word)p4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8322D830: if_call_seq fn_832386E0, u32@0xd4 */
ts4l_word ts4l_if_call_seq_fn_832386E0_8322D830(ts4l_word a0)
{
    int t1;

    if ((ts4l_word)a0 != 0) {
        t1 = fn_832386E0((ts4l_word)a0, (ts4l_word)-1);
        if ((int)t1 == 0) {
            return (*(ts4l_word *)((char *)(ts4l_word)(a0) + 212));
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x8322E7C8: call_seq fn_833E3A30, fn_833E3A30, fn_833E3A30, fn_833E3A30, u32@0x1bc, u32@0x1c0 */
ts4l_word ts4l_call_seq_fn_833E3A30_8322E7C8(ts4l_word a0)
{
    ts4l_word t5;

    fn_833E3A30((ts4l_word)(a0 + 124), (ts4l_word)0, (ts4l_word)80);
    fn_833E3A30((ts4l_word)(a0 + 284), (ts4l_word)0, (ts4l_word)80);
    fn_833E3A30((ts4l_word)(a0 + 364), (ts4l_word)0, (ts4l_word)80);
    fn_833E3A30((ts4l_word)(a0 + 204), (ts4l_word)0, (ts4l_word)80);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 444) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 448) = (ts4l_word)0;
    t5 = fn_832361A0((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x8322E938: if_call_seq lbl_8302B8A0, u32@0x0, fn_83236198, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B8A0_8322E938(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B8A0;
    fn_83236198((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32823));
    }
    return a0;
}

/* Loader_DLL.xex 0x8322ED58: get u32@0x30, u32@0x4, vcall */
ts4l_word ts4l_get_u32_off30_8322ED58(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(((int)a1 * 60)) + t1))) + 4))))((ts4l_word)(((int)a1 * 60) + t1));
    return (((int)a1 * 60) + t1);
}

/* Loader_DLL.xex 0x8322F260: if_call_seq lbl_8302B908, u32@0x0, fn_8322EA10, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B908_8322F260(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B908;
    fn_8322EA10((ts4l_word)a0);
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32782));
    }
    return a0;
}

/* Loader_DLL.xex 0x8322F310: set u32@0xf4, u32@0xf8, u32@0xfc, u32@0x100, u32@0x2c, u32@0x30 */
void ts4l_set_u32_offf4_8322F310(ts4l_word a0)
{
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 244) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 248) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 252) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 256) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(volatile float *)((char *)(ts4l_word)(a0) + 280) = (*(float *)lbl_830009E0);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 212) = (ts4l_word)1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 216) = (ts4l_word)1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 220) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 224) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 228) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 232) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 236) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 240) = (ts4l_word)1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 260) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 264) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 268) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 272) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 276) = (ts4l_word)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 288) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 88) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 92) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 96) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 100) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 104) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 108) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 112) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 128) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 132) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 136) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 140) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 144) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 148) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 152) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 156) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 160) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 164) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 168) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 172) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 176) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 180) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 184) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 188) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 192) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 196) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 200) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 204) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 208) = (ts4l_word)0;
    return;
}

/* Loader_DLL.xex 0x8322F5E0: if_get u32@0x0, u32@0x4, vcall, u32@0x2c, u32@0x0, u32@0x8 */
ts4l_word ts4l_if_get_u32_off0_8322F5E0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t5 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t5) + 0))) + 8))))((ts4l_word)t5);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8322F698: if_get u32@0x0, u32@0xc, vcall, u32@0x0, u32@0xf4, vcall */
ts4l_word ts4l_if_get_u32_off0_8322F698(ts4l_word a0)
{
    ts4l_word p17;
    ts4l_word p19;
    int t6;
    int t9;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t6 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 244))))((ts4l_word)a0);
    if ((int)t6 == 3) {
        t9 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 248))))((ts4l_word)a0);
        if ((int)t9 == 3) {
            ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 276))))((ts4l_word)a0, (ts4l_word)1);
            ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 280))))((ts4l_word)a0, (ts4l_word)1);
            p17 = (ts4l_word)0;
        } else {
            p17 = (ts4l_word)((2147483648) | 16389);
        }
        p19 = (ts4l_word)p17;
    } else {
        p19 = (ts4l_word)((2147483648) | 16389);
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 20))))((ts4l_word)a0);
    return p19;
}

/* Loader_DLL.xex 0x83230550: if_get u32@0x0, u32@0xfc, vcall, u32@0x2c, u32@0x0, u32@0x4c */
ts4l_word ts4l_if_get_u32_off0_83230550(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p19;
    ts4l_word loc50[2];
    ts4l_word t3;
    ts4l_word t4;
    int t8;
    ts4l_word t12;
    ts4l_word t15;
    int t16;
    ts4l_word t18;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 252))))((ts4l_word)a0);
    if ((int)(t3 & 0x1) == 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
        ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t4) + 0))) + 76))))((ts4l_word)t4, (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
        t8 = loc50[0];
        if ((int)t8 > 5) {
            fn_8340CE90((ts4l_word)(t8 + -5));
        }
    }
    t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    t15 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t12) + 0))) + 88))))((ts4l_word)t12);
    t16 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 240);
    p19 = (ts4l_word)t15;
    if ((int)t16 != 0) {
        t18 = fn_8340CE10((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 272)));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 240) = (ts4l_word)0;
        p19 = (ts4l_word)t18;
    }
    return p19;
}

/* Loader_DLL.xex 0x83230600: if_get u32@0x2c, u32@0x0, u32@0x4c, vcall, u32@0x2c, u32@0x0 */
ts4l_word ts4l_if_get_u32_off2c_83230600(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p13;
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t9;
    int t10;
    ts4l_word t12;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a2 != 0) {
        t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 76))))((ts4l_word)t1);
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    t9 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 88))))((ts4l_word)t6);
    t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 240);
    p13 = (ts4l_word)t9;
    if ((int)t10 != 0) {
        t12 = fn_8340CE10((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 272)));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 240) = (ts4l_word)0;
        p13 = (ts4l_word)t12;
    }
    return p13;
}

/* Loader_DLL.xex 0x83230A68: get u32@0x0, u32@0xc, vcall, u32@0xdc, u32@0x0, u32@0xdc */
ts4l_word ts4l_get_u32_off0_83230A68(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 220);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 220) = (ts4l_word)(t4 | a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83230AD0: get u32@0x0, u32@0xc, vcall, u32@0xe0, u32@0x0, u32@0xe0 */
ts4l_word ts4l_get_u32_off0_83230AD0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 224);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 224) = (ts4l_word)(t4 | a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83230B38: get u32@0x0, u32@0xc, vcall, u32@0xe4, u32@0x0, u32@0xe4 */
ts4l_word ts4l_get_u32_off0_83230B38(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 228);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 228) = (ts4l_word)(t4 | a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83230BA0: get u32@0x0, u32@0xc, vcall, u32@0xdc, u32@0x0, u32@0xdc */
ts4l_word ts4l_get_u32_off0_83230BA0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 220);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 220) = (ts4l_word)(t4 & ~a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83230C08: get u32@0x0, u32@0xc, vcall, u32@0xe0, u32@0x0, u32@0xe0 */
ts4l_word ts4l_get_u32_off0_83230C08(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 224);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 224) = (ts4l_word)(t4 & ~a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x83230C70: get u32@0x0, u32@0xc, vcall, u32@0xe4, u32@0x0, u32@0xe4 */
ts4l_word ts4l_get_u32_off0_83230C70(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 12))))((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 228);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 228) = (ts4l_word)(t4 & ~a1);
    t7 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t5) + 20))))((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x832318E8: if_call_seq fn_830AAAC0, u32@0x30, fn_830AAAE8, u32@0x30, u32@0x30 */
ts4l_word ts4l_if_call_seq_fn_830AAAC0_832318E8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a1 != 0) {
        fn_830AAAC0((ts4l_word)a1);
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    if ((ts4l_word)t3 != 0) {
        fn_830AAAE8((ts4l_word)t3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x832333F8: if_call_seq lbl_8302B968, u32@0x0, fn_83231640, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B968_832333F8(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B968;
    fn_83231640((ts4l_word)a0);
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32818));
    }
    return a0;
}

/* Loader_DLL.xex 0x832334D8: if_get u32@0x2c, fn_8340D830, u32@0x58, fn_8340A360, u32@0x0, u32@0x4c */
ts4l_word ts4l_if_get_u32_off2c_832334D8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        fn_8340D830((ts4l_word)t1, (ts4l_word)((546045952) | 32770));
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 88);
    if ((ts4l_word)t4 != 0) {
        fn_8340A360((ts4l_word)t4);
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 76))))((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832335F8: if_get u32@0x2c, lbl_8302BAB0, u32@0x0, fn_8340D830, u32@0x58, fn_8340A360 */
ts4l_word ts4l_if_get_u32_off2c_832335F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302BAB0;
    if ((ts4l_word)t1 != 0) {
        fn_8340D830((ts4l_word)t1, (ts4l_word)((546045952) | 32770));
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 88);
    if ((ts4l_word)t4 != 0) {
        fn_8340A360((ts4l_word)t4);
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 76))))((ts4l_word)a0);
    t10 = fn_83227008((ts4l_word)a0);
    return t10;
}

/* Loader_DLL.xex 0x83233950: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x8, vcall, u32@0x0 */
ts4l_word ts4l_if_get_u32_off0_83233950(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, int a7)
{
    int t2;
    ts4l_word t3;
    ts4l_word t5;
    int t7;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t10;

    (void)a2;
    if ((int)a1 >= 0 && (int)a1 < 127) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 0);
        if ((int)t2 == 0) {
            return ((2152726528) | 182);
        }
        t3 = *(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 4);
        t5 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))(t3))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 8)), (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
        if ((int)a7 != 0) {
            t7 = *(ts4l_word *)((char *)(ts4l_word)(a6) + 0);
            if ((int)t7 != 1) {
                if ((int)t7 == 2) {
                    return ((2152726528) | 189);
                }
                return t5;
            }
            t8 = *(ts4l_word *)((char *)(ts4l_word)(a6) + 20);
            t9 = *(ts4l_word *)((char *)(ts4l_word)(a6) + 12);
            t10 = *(ts4l_word *)((char *)(ts4l_word)(a6) + 8);
            fn_83233AE8((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a6) + 16)), (ts4l_word)t10, (ts4l_word)t9, (ts4l_word)t8, (ts4l_word)1, (ts4l_word)a1);
            return t5;
        }
        return t5;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83233A38: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x8, vcall */
ts4l_word ts4l_if_get_u32_off0_83233A38(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word loc50[4];
    ts4l_word loc60[6];
    int t2;
    ts4l_word t3;
    ts4l_word t5;

    loc50[0] = (ts4l_word)0;
    loc60[0] = (ts4l_word)0;
    loc60[1] = (ts4l_word)0;
    if ((int)a1 >= 0 && (int)a1 < 127) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 0);
        if ((int)t2 == 0) {
            return ((2152726528) | 182);
        }
        t3 = *(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 4);
        t5 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))(t3))((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)((((a1 + (a1 << 1)) << 2) + a0)) + 8)), (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)(ts4l_word)&loc60[0]);
        return t5;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83233D68: call_seq u32@0x0, fn_8340D830, u32@0x0 */
ts4l_word ts4l_call_seq_u32_off0_83233D68(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    (void)a0;
    (void)a1;
    fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 0)), (ts4l_word)((546045952) | 32768));
    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)0;
    return 0;
}

/* Loader_DLL.xex 0x83235488: if_set u32@0x0, u32@0x4, u8@0x10, u8@0x60, u32@0x8, vcall */
ts4l_word ts4l_if_set_u32_off0_83235488(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p6;
    ts4l_word t1;
    int t4;
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)0;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4l_word)(a0) + 96) = (unsigned char)(*(unsigned char *)((char *)(ts4l_word)(a0) + 16));
    t4 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t1) + 8))))((ts4l_word)t1, (ts4l_word)a2, (ts4l_word)a1);
    p6 = (ts4l_word)t4;
    if ((int)t4 >= 0 && (int)t4 == (int)((5242880) | 13)) {
        t5 = fn_83234D50((ts4l_word)a0);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83235500: if_get u8@0x10, u32@0x48, fn_832341A0, u32@0x4, u32@0x10, vcall */
ts4l_word ts4l_if_get_u8_off10_83235500(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word p9;
    ts4l_word p10;
    ts4l_word loc50[4];
    unsigned char t1;
    int t3;
    ts4l_word t4;
    int t6;
    ts4l_word t7;
    ts4l_word t8;

    (void)a1;
    (void)a2;
    t1 = *(unsigned char *)((char *)(ts4l_word)(a0) + 16);
    loc50[0] = (ts4l_word)0;
    t3 = fn_832341A0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 72)), (ts4l_word)t1, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a3);
    p10 = (ts4l_word)t3;
    if ((int)t3 >= 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
        t6 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(t4) + 16))))((ts4l_word)t4);
        p9 = (ts4l_word)t6;
        if ((int)t6 >= 0) {
            t7 = loc50[0];
            t8 = fn_83235280((ts4l_word)a0, (ts4l_word)t7);
            p9 = (ts4l_word)t8;
        }
        p10 = (ts4l_word)p9;
    }
    return p10;
}

/* Loader_DLL.xex 0x832361E0: if_call_seq fn_833E3A30, fn_833E7330 */
ts4l_word ts4l_if_call_seq_fn_833E3A30_832361E0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p2;
    ts4l_word t3;

    (void)a0;
    fn_833E3A30((ts4l_word)a4, (ts4l_word)0, (ts4l_word)a3);
    p2 = (ts4l_word)a2;
    if ((ts4l_word)a2 > (ts4l_word)(a3 + -1)) {
        p2 = (ts4l_word)(a3 + -1);
    }
    t3 = fn_833E7330((ts4l_word)a4, (ts4l_word)a1, (ts4l_word)p2);
    *(unsigned short *)((char *)(ts4l_word)((p2 << 1)) + a4) = (unsigned short)0;
    return t3;
}

/* Loader_DLL.xex 0x8323A6E8: if_get u32@0x0, u32@0x3c, u32@0xd4, u32@0x25c, u32@0x8, u32@0x25c */
ts4l_word ts4l_if_get_u32_off0_8323A6E8(ts4l_word a0)
{
    ts4l_word t1;
    int t2;
    int t8;
    int t6;
    ts4l_word t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 60);
    if ((int)t2 <= 2) {
        t8 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 212);
        if ((int)t8 != 0) {
            return (((*(ts4l_word *)((char *)(ts4l_word)(t1) + 8)) + 11) & 0xff);
        }
        return 0;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 604);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 8);
    if ((int)t6 != 0) {
        return ((t7 + 17) & 0xff);
    }
    return ((t7 + 6) & 0xff);
}

/* Loader_DLL.xex 0x8323AA40: if_call_seq fn_8323A7F8, fn_833E3A30, u32@0x14, u32@0xc, u32@0x20, u32@0x24 */
ts4l_word ts4l_if_call_seq_fn_8323A7F8_8323AA40(ts4l_word a0)
{
    int t1;

    t1 = fn_8323A7F8();
    if ((int)t1 >= 0) {
        fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)720);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)2;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 216) = (ts4l_word)1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 164) = (ts4l_word)2;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 692) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 696) = (ts4l_word)1;
    }
    return t1;
}

/* Loader_DLL.xex 0x8324A7A8: if_call_seq fn_83233D10, fn_833E3A30, u32@0x0, u32@0x4, u64@0x8, u64@0x10 */
ts4l_word ts4l_if_call_seq_fn_83233D10_8324A7A8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    ts4l_word p54;
    ts4l_word p55;
    ts4l_word p56;
    ts4l_word p57;
    ts4l_word p58;
    ts4l_word p59;
    ts4l_word loc50[4];
    int t1;
    ts4l_word t2;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t10;
    ts4l_word t11;
    ts4l_word t12;
    ts4l_word t13;
    ts4l_word t14;
    ts4l_word t15;
    ts4l_word t16;
    ts4l_word t17;
    ts4l_word t18;
    ts4l_word t19;
    ts4l_word t20;
    ts4l_word t21;
    ts4l_word t22;
    ts4l_word t23;
    ts4l_word t24;
    int t25;
    ts4l_word t26;
    ts4l_word t29;
    int t30;
    ts4l_word t31;
    ts4l_word t34;
    ts4l_word t35;
    ts4l_word t36;
    ts4l_word t37;
    ts4l_word t38;
    ts4l_word t39;
    ts4l_word t40;
    ts4l_word t41;
    ts4l_word t42;
    ts4l_word t43;
    ts4l_word t44;
    int t46;
    ts4l_word t47;
    int t49;
    ts4l_word t50;
    int t51;
    ts4l_word t52;
    ts4l_word t53;

    (void)a0;
    loc50[0] = (ts4l_word)0;
    t1 = fn_83233D10((ts4l_word)a3, (ts4l_word)11, (ts4l_word)240, (ts4l_word)(ts4l_word)&loc50[0]);
    p59 = (ts4l_word)t1;
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        fn_833E3A30((ts4l_word)t2, (ts4l_word)0, (ts4l_word)240);
        t4 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t4) + 0) = (ts4l_word)a1;
        t5 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t5) + 4) = (ts4l_word)a2;
        t6 = loc50[0];
        *(ts4l_u64 *)((char *)(ts4l_word)(t6) + 8) = (ts4l_u64)0;
        t7 = loc50[0];
        *(ts4l_u64 *)((char *)(ts4l_word)(t7) + 16) = (ts4l_u64)0;
        t8 = loc50[0];
        *(ts4l_u64 *)((char *)(ts4l_word)(t8) + 24) = (ts4l_u64)0;
        t9 = loc50[0];
        *(ts4l_u64 *)((char *)(ts4l_word)(t9) + 32) = (ts4l_u64)0;
        t10 = loc50[0];
        *(ts4l_u64 *)((char *)(ts4l_word)(t10) + 40) = (ts4l_u64)0;
        t11 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t11) + 184) = (ts4l_word)0;
        t12 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t12) + 188) = (ts4l_word)0;
        t13 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t13) + 192) = (ts4l_word)0;
        t14 = loc50[0];
        *(unsigned char *)((char *)(ts4l_word)(t14) + 196) = (unsigned char)0;
        t15 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t15) + 200) = (ts4l_word)0;
        t16 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t16) + 208) = (ts4l_word)0;
        t17 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t17) + 212) = (ts4l_word)0;
        t18 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t18) + 216) = (ts4l_word)0;
        t19 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t19) + 220) = (ts4l_word)0;
        t20 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t20) + 204) = (ts4l_word)0;
        t21 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t21) + 224) = (ts4l_word)a3;
        t22 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t22) + 228) = (ts4l_word)0;
        t23 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(t23) + 232) = (ts4l_word)0;
        t24 = loc50[0];
        *(ts4l_word *)((char *)(ts4l_word)(a4) + 28) = (ts4l_word)t24;
        t25 = fn_83233D10((ts4l_word)a3, (ts4l_word)11, (ts4l_word)76, (ts4l_word)(t24 + 48), (ts4l_word)t20, (ts4l_word)t19, (ts4l_word)t18, (ts4l_word)t23);
        p58 = (ts4l_word)t25;
        if ((int)t25 >= 0) {
            t26 = loc50[0];
            fn_833E3A30((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t26) + 48)), (ts4l_word)0, (ts4l_word)76);
            t29 = loc50[0];
            t30 = fn_83233D10((ts4l_word)a3, (ts4l_word)11, (ts4l_word)92, (ts4l_word)(t29 + 52));
            p57 = (ts4l_word)t30;
            if ((int)t30 >= 0) {
                t31 = loc50[0];
                fn_833E3A30((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t31) + 52)), (ts4l_word)0, (ts4l_word)92);
                t34 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t34) + 56) = (ts4l_word)0;
                t35 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t35) + 60) = (ts4l_word)0;
                t36 = loc50[0];
                *(unsigned short *)((char *)(ts4l_word)(t36) + 64) = (unsigned short)0;
                t37 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t37) + 68) = (ts4l_word)0;
                t38 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t38) + 72) = (ts4l_word)0;
                t39 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t39) + 76) = (ts4l_word)1;
                t40 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t40) + 80) = (ts4l_word)1;
                t41 = loc50[0];
                *(ts4l_word *)((char *)(ts4l_word)(t41) + 112) = (ts4l_word)0;
                t42 = loc50[0];
                t43 = *(ts4l_word *)((char *)(ts4l_word)(t42) + 4);
                *(ts4l_word *)((char *)(ts4l_word)(t43) + 0) = (ts4l_word)1;
                t44 = loc50[0];
                t46 = fn_83234000((ts4l_word)a3, (ts4l_word)(ts4l_word)fn_83249E48, (ts4l_word)t44, (ts4l_word)32, (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t44) + 4)) + 124), (ts4l_word)t40, (ts4l_word)t39, (ts4l_word)t43);
                p56 = (ts4l_word)t46;
                if ((int)t46 >= 0) {
                    t47 = loc50[0];
                    t49 = fn_83234000((ts4l_word)a3, (ts4l_word)(ts4l_word)fn_83249F00, (ts4l_word)t47, (ts4l_word)88, (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t47) + 4)) + 128));
                    p55 = (ts4l_word)t49;
                    if ((int)t49 >= 0) {
                        t50 = loc50[0];
                        t51 = fn_83234000((ts4l_word)a3, (ts4l_word)(ts4l_word)fn_83249FE0, (ts4l_word)t50, (ts4l_word)104, (ts4l_word)(t50 + 148));
                        p54 = (ts4l_word)t51;
                        if ((int)t51 >= 0) {
                            t52 = loc50[0];
                            t53 = fn_83233830((ts4l_word)a3, (ts4l_word)4, (ts4l_word)(ts4l_word)fn_83249C90, (ts4l_word)t52);
                            p54 = (ts4l_word)t53;
                        }
                        p55 = (ts4l_word)p54;
                    }
                    p56 = (ts4l_word)p55;
                }
                p57 = (ts4l_word)p56;
            }
            p58 = (ts4l_word)p57;
        }
        p59 = (ts4l_word)p58;
    }
    return p59;
}

/* Loader_DLL.xex 0x8324EA08: if_call_seq u32@0x2c, fn_8324DEA8, fn_8324E540, fn_8324E448, u64@0x50, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off2c_8324EA08(ts4l_word a0)
{
    ts4l_word p5;
    ts4l_word p6;
    ts4l_word t1;
    int t2;
    int t3;
    int t4;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    t2 = fn_8324DEA8();
    p6 = (ts4l_word)t2;
    if ((int)t2 >= 0) {
        t3 = fn_8324E540((ts4l_word)a0);
        p5 = (ts4l_word)t3;
        if ((int)t3 >= 0) {
            t4 = fn_8324E448((ts4l_word)a0, (ts4l_word)1);
            if ((int)t4 >= 0) {
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 80) = (ts4l_u64)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)1;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 88) = (ts4l_word)0;
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 32) = (ts4l_u64)0;
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 40) = (ts4l_u64)0;
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 48) = (ts4l_u64)0;
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 64) = (ts4l_u64)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 92) = (ts4l_word)0;
                *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 96) = (ts4l_u64)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 144) = (ts4l_word)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 20) = (ts4l_word)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)0;
                *(ts4l_word *)((char *)(ts4l_word)(t1) + 148) = (ts4l_word)0;
            }
            p5 = (ts4l_word)t4;
        }
        p6 = (ts4l_word)p5;
    }
    return p6;
}

/* Loader_DLL.xex 0x832503E8: if_call_seq u32@0x2c, fn_8324F9C8, fn_8324FF60, u64@0x38, u32@0x0, u32@0x40 */
ts4l_word ts4l_if_call_seq_u32_off2c_832503E8(ts4l_word a0)
{
    ts4l_word p4;
    ts4l_word t1;
    int t2;
    int t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    t2 = fn_8324F9C8();
    p4 = (ts4l_word)t2;
    if ((int)t2 >= 0) {
        t3 = fn_8324FF60((ts4l_word)a0);
        if ((int)t3 >= 0) {
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 56) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)1;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 64) = (ts4l_word)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 32) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 40) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 128) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 68) = (ts4l_word)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 72) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 120) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 20) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)0;
        }
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83251A68: if_call_seq u32@0x2c, fn_83251168, fn_832515D8, u64@0x38, u32@0x0, u32@0x40 */
ts4l_word ts4l_if_call_seq_u32_off2c_83251A68(ts4l_word a0)
{
    ts4l_word p4;
    ts4l_word t1;
    int t2;
    int t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    t2 = fn_83251168();
    p4 = (ts4l_word)t2;
    if ((int)t2 >= 0) {
        t3 = fn_832515D8((ts4l_word)a0);
        if ((int)t3 >= 0) {
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 56) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)1;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 64) = (ts4l_word)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 32) = (ts4l_u64)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 40) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 68) = (ts4l_word)0;
            *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 72) = (ts4l_u64)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 120) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 20) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)0;
        }
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x832522B8: if_call_seq fn_8340D710, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_8340D710_832522B8(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_8340D710((ts4l_word)a0, (ts4l_word)((613154816) | 32768));
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x832523E8: if_call_seq fn_83252310, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83252310_832523E8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_83252310((ts4l_word)a0, (ts4l_word)a1);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}
