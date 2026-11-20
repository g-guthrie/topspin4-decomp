/* Loader_DLL.xex 0x83220F08-0x8322C968, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_830009E0[];
extern char lbl_830009F8[];
extern char lbl_8302AAA8[];
extern char lbl_8302B028[];
extern char lbl_8302B160[];
extern char lbl_8302B1E8[];
extern char lbl_8302B268[];
extern char lbl_8302B390[];
extern char lbl_8302B3F8[];
extern char lbl_8302B458[];
extern char lbl_8302B4E0[];
extern char lbl_8302B850[];
ts4l_word fn_83220068();
ts4l_word fn_83220118();
ts4l_word fn_83220228();
ts4l_word fn_83220300();
ts4l_word fn_83220488();
ts4l_word fn_83222178();
ts4l_word fn_83223558();
ts4l_word fn_83225F90();
ts4l_word fn_83226FC0();
ts4l_word fn_83227008();
ts4l_word fn_832272F0();
ts4l_word fn_83227348();
ts4l_word fn_83227440();
ts4l_word fn_83228290();
ts4l_word fn_83228A88();
ts4l_word fn_8322C010();
ts4l_word fn_8322C120();
ts4l_word fn_8322C398();
ts4l_word fn_8322E7B8();
ts4l_word fn_8322E8F0();
ts4l_word fn_8322EE88();
ts4l_word fn_832333B8();
ts4l_word fn_83234120();
ts4l_word fn_832341A0();
ts4l_word fn_83236198();
ts4l_word fn_832361A0();
ts4l_word fn_83239578();
ts4l_word fn_833E3A30();
ts4l_word fn_8340D710();
ts4l_word fn_8340D830();

/* Loader_DLL.xex 0x83220F08: if_call_seq lbl_8302AAA8, u32@0x0, fn_83220488, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302AAA8_83220F08(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AAA8;
    fn_83220488((ts4l_word)a0);
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32808));
    }
    return a0;
}

/* Loader_DLL.xex 0x83222BB8: call_seq fn_83226FC0, fn_83227348, fn_83220118, fn_8322C120 */
ts4l_word ts4l_call_seq_fn_83226FC0_83222BB8(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    fn_83227348((ts4l_word)(a0 + 56));
    fn_83220118((ts4l_word)(a0 + 136));
    fn_8322C120((ts4l_word)(a0 + 212));
    return a0;
}

/* Loader_DLL.xex 0x83222C48: call_seq lbl_8302B028, u32@0x0, fn_83222178, fn_8322C010, fn_83220068, fn_832272F0 */
ts4l_word ts4l_call_seq_lbl_8302B028_83222C48(ts4l_word a0)
{
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B028;
    fn_83222178((ts4l_word)a0);
    fn_8322C010((ts4l_word)(a0 + 212));
    fn_83220068((ts4l_word)(a0 + 136));
    fn_832272F0((ts4l_word)(a0 + 56));
    t5 = fn_83227008((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x83222D68: call_seq fn_83226FC0, fn_83227348, fn_83220118, fn_8322C120, lbl_8302B028, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83226FC0_83222D68(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    fn_83227348((ts4l_word)(a0 + 56));
    fn_83220118((ts4l_word)(a0 + 136));
    fn_8322C120((ts4l_word)(a0 + 212));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B028;
    fn_83227440((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 520) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 508) = (ts4l_word)2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 524) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 528) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 536) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 540) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 544) = (ts4l_word)1;
    return a0;
}

/* Loader_DLL.xex 0x83222DF0: if_call_seq lbl_8302B028, u32@0x0, fn_83222178, fn_8322C010, fn_83220068, fn_832272F0 */
ts4l_word ts4l_if_call_seq_lbl_8302B028_83222DF0(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B028;
    fn_83222178((ts4l_word)a0);
    fn_8322C010((ts4l_word)(a0 + 212));
    fn_83220068((ts4l_word)(a0 + 136));
    fn_832272F0((ts4l_word)(a0 + 56));
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32797));
    }
    return a0;
}

/* Loader_DLL.xex 0x83223A88: if_get u32@0x30, u32@0x0, u32@0x8, vcall, u32@0x30 */
ts4l_word ts4l_if_get_u32_off30_83223A88(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83224000: call_seq fn_83226FC0, fn_83227348, fn_83220300, fn_8322E8F0 */
ts4l_word ts4l_call_seq_fn_83226FC0_83224000(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    fn_83227348((ts4l_word)(a0 + 56));
    fn_83220300((ts4l_word)(a0 + 124));
    fn_8322E8F0((ts4l_word)(a0 + 208));
    return a0;
}

/* Loader_DLL.xex 0x83224048: call_seq fn_8322E7B8, fn_83220228, fn_832272F0, fn_83227008 */
ts4l_word ts4l_call_seq_fn_8322E7B8_83224048(ts4l_word a0)
{
    ts4l_word t4;

    fn_8322E7B8((ts4l_word)(a0 + 208));
    fn_83220228((ts4l_word)(a0 + 124));
    fn_832272F0((ts4l_word)(a0 + 56));
    t4 = fn_83227008((ts4l_word)a0);
    return t4;
}

/* Loader_DLL.xex 0x83224090: call_seq lbl_8302B160, u32@0x0, fn_83223558, fn_8322E7B8, fn_83220228, fn_832272F0 */
ts4l_word ts4l_call_seq_lbl_8302B160_83224090(ts4l_word a0)
{
    ts4l_word t5;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B160;
    fn_83223558((ts4l_word)a0);
    fn_8322E7B8((ts4l_word)(a0 + 208));
    fn_83220228((ts4l_word)(a0 + 124));
    fn_832272F0((ts4l_word)(a0 + 56));
    t5 = fn_83227008((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x832242C8: call_seq fn_83226FC0, fn_83227348, fn_83220300, fn_8322E8F0, lbl_8302B160, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83226FC0_832242C8(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    fn_83227348((ts4l_word)(a0 + 56));
    fn_83220300((ts4l_word)(a0 + 124));
    fn_8322E8F0((ts4l_word)(a0 + 208));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B160;
    fn_8322C398((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 672) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 660) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 676) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 664) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 668) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83224340: if_call_seq lbl_8302B160, u32@0x0, fn_83223558, fn_8322E7B8, fn_83220228, fn_832272F0 */
ts4l_word ts4l_if_call_seq_lbl_8302B160_83224340(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B160;
    fn_83223558((ts4l_word)a0);
    fn_8322E7B8((ts4l_word)(a0 + 208));
    fn_83220228((ts4l_word)(a0 + 124));
    fn_832272F0((ts4l_word)(a0 + 56));
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32791));
    }
    return a0;
}

/* Loader_DLL.xex 0x83224408: set u64@0x120, u64@0x130, u64@0x128, u32@0x138, u32@0x13c, u32@0x140 */
void ts4l_set_u64_off120_83224408(ts4l_word a0)
{
    float t1;
    float t2;

    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 288) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 304) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 296) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 312) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 316) = (ts4l_word)0;
    t1 = *(float *)lbl_830009F8;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 320) = (ts4l_word)0;
    t2 = *(float *)lbl_830009E0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 324) = (ts4l_word)0;
    *(volatile float *)((char *)(ts4l_word)(a0) + 336) = t1;
    *(volatile float *)((char *)(ts4l_word)(a0) + 340) = t2;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 328) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 332) = (ts4l_word)0;
    return;
}

/* Loader_DLL.xex 0x83224478: if_get u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x30, vcall */
ts4l_word ts4l_if_get_u32_off0_83224478(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word p10;
    ts4l_word p11;
    int t3;
    int t6;
    ts4l_word t9;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 40))))((ts4l_word)a0);
    p11 = (ts4l_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 48))))((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a3, (ts4l_word)a5);
        p10 = (ts4l_word)t6;
        if ((int)t6 >= 0) {
            t9 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 52))))((ts4l_word)a0, (ts4l_word)a2, (ts4l_word)a4, (ts4l_word)a6);
            p10 = (ts4l_word)t9;
        }
        p11 = (ts4l_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x83224508: get u32@0x44, u32@0x30, vcall, u32@0x8c, u32@0x30, vcall */
ts4l_word ts4l_get_u32_off44_83224508(ts4l_word a0)
{
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 68))) + 48))))((ts4l_word)(a0 + 68));
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 140))) + 48))))((ts4l_word)(a0 + 140));
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 212))) + 48))))((ts4l_word)(a0 + 212));
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 48))))((ts4l_word)a0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)0);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 52))))((ts4l_word)a0, (ts4l_word)0, (ts4l_word)0, (ts4l_word)0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 112))))((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832245C8: if_get u32@0x2c, u32@0x0, u32@0x8, vcall, u32@0x2c, u32@0x30 */
ts4l_word ts4l_if_get_u32_off2c_832245C8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t11;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    if ((ts4l_word)t6 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 8))))((ts4l_word)t6);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    }
    t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 52);
    if ((ts4l_word)t11 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t11) + 0))) + 8))))((ts4l_word)t11);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    }
    if ((ts4l_word)a1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)a1;
    }
    if ((ts4l_word)a2 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0))) + 4))))((ts4l_word)a2);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)a2;
    }
    if ((ts4l_word)a3 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a3) + 0))) + 4))))((ts4l_word)a3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)a3;
    }
    return 0;
}

/* Loader_DLL.xex 0x832246B8: if_get u32@0x38, u32@0x0, u32@0x8, vcall, u32@0x38, u32@0x3c */
ts4l_word ts4l_if_get_u32_off38_832246B8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t6;
    ts4l_word t11;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 60);
    if ((ts4l_word)t6 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t6) + 0))) + 8))))((ts4l_word)t6);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    }
    t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 64);
    if ((ts4l_word)t11 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t11) + 0))) + 8))))((ts4l_word)t11);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    }
    if ((ts4l_word)a1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)a1;
    }
    if ((ts4l_word)a2 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a2) + 0))) + 4))))((ts4l_word)a2);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)a2;
    }
    if ((ts4l_word)a3 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a3) + 0))) + 4))))((ts4l_word)a3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)a3;
    }
    return 0;
}

/* Loader_DLL.xex 0x83224B28: call_seq fn_83226FC0, lbl_8302B1E8, u32@0x0, fn_8322EE88, fn_8322EE88, fn_8322EE88 */
ts4l_word ts4l_call_seq_fn_83226FC0_83224B28(ts4l_word a0)
{
    float t5;
    float t6;

    fn_83226FC0((ts4l_word)a0);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B1E8;
    fn_8322EE88((ts4l_word)(a0 + 68));
    fn_8322EE88((ts4l_word)(a0 + 140));
    fn_8322EE88((ts4l_word)(a0 + 212));
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 288) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 304) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 296) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 312) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 316) = (ts4l_word)0;
    t5 = *(float *)lbl_830009F8;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 320) = (ts4l_word)0;
    t6 = *(float *)lbl_830009E0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 324) = (ts4l_word)0;
    *(volatile float *)((char *)(ts4l_word)(a0) + 336) = t5;
    *(volatile float *)((char *)(ts4l_word)(a0) + 340) = t6;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 328) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 332) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83224D48: if_get u32@0x44, u32@0x4, vcall, u32@0x0, u32@0x8c, u32@0x4 */
ts4l_word ts4l_if_get_u32_off44_83224D48(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 68))) + 4))))((ts4l_word)(a0 + 68));
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)(a0 + 68);
    }
    if ((ts4l_word)a2 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 140))) + 4))))((ts4l_word)(a0 + 140));
        *(ts4l_word *)((char *)(ts4l_word)(a2) + 0) = (ts4l_word)(a0 + 140);
    }
    if ((ts4l_word)a3 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 212))) + 4))))((ts4l_word)(a0 + 212));
        *(ts4l_word *)((char *)(ts4l_word)(a3) + 0) = (ts4l_word)(a0 + 212);
    }
    return 0;
}

/* Loader_DLL.xex 0x832251F8: if_call_seq lbl_8302B268, u32@0x0, fn_832333B8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B268_832251F8(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B268;
    fn_832333B8((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32819));
    }
    return a0;
}

/* Loader_DLL.xex 0x83225300: if_get u32@0x0, u32@0x30, vcall, u32@0x0, u32@0x30, vcall */
ts4l_word ts4l_if_get_u32_off0_83225300(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    int t3;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 48))))((ts4l_word)a0);
    if ((int)t3 >= 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)a1;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)a2;
        return t3;
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 48))))((ts4l_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x83225498: call_seq fn_83226FC0, lbl_8302B390, u64@0x30, u32@0x2c, u32@0x0, u32@0x38 */
ts4l_word ts4l_call_seq_fn_83226FC0_83225498(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 48) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B390;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83225508: addr lbl_8302B390, u32@0x0, u32@0x64, vcall, fn_83227008 */
ts4l_word ts4l_addr_lbl_8302B390_83225508(ts4l_word a0)
{
    ts4l_word t3;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B390;
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_8302B390) + 100))))((ts4l_word)a0);
    t3 = fn_83227008((ts4l_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x83225550: if_addr lbl_8302B390, u32@0x0, u32@0x64, vcall, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_addr_lbl_8302B390_83225550(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B390;
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((ts4l_word)lbl_8302B390) + 100))))((ts4l_word)a0);
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32780));
    }
    return a0;
}

/* Loader_DLL.xex 0x83225628: if_get u32@0x0, u32@0x30, vcall, fn_8340D710, u32@0x2c, u32@0x30 */
ts4l_word ts4l_if_get_u32_off0_83225628(ts4l_word a0, ts4l_word a1)
{
    int t3;
    ts4l_word t4;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 48))))((ts4l_word)a0);
    if ((int)t3 >= 0) {
        t4 = fn_8340D710((ts4l_word)a1, (ts4l_word)((546045952) | 32781));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)t4;
        if ((ts4l_word)t4 != 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)a1;
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)1;
            return t3;
        }
        return ((2147942400) | 14);
    }
    return t3;
}

/* Loader_DLL.xex 0x832256E0: if_call_seq u32@0x38, u32@0x2c, fn_8340D830, u32@0x2c, u32@0x30, u32@0x34 */
ts4l_word ts4l_if_call_seq_u32_off38_832256E0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    if ((int)t1 != 0) {
        fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)((546045952) | 32781));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    return 0;
}

/* Loader_DLL.xex 0x83225918: call_seq fn_83226FC0, lbl_8302B3F8, u32@0x2c, u32@0x0, u32@0x30, u32@0x34 */
ts4l_word ts4l_call_seq_fn_83226FC0_83225918(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B3F8;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83225968: if_call_seq u32@0x38, lbl_8302B3F8, u32@0x0, u32@0x2c, fn_8340D830, u32@0x2c */
ts4l_word ts4l_if_call_seq_u32_off38_83225968(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    int t1;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B3F8;
    if ((int)t1 != 0) {
        fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)((546045952) | 32781));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    t5 = fn_83227008((ts4l_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x832259D8: if_call_seq u32@0x38, lbl_8302B3F8, u32@0x0, u32@0x2c, fn_8340D830, u32@0x2c */
ts4l_word ts4l_if_call_seq_u32_off38_832259D8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    int t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B3F8;
    if ((int)t1 != 0) {
        fn_8340D830((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)((546045952) | 32781));
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32781));
    }
    return a0;
}

/* Loader_DLL.xex 0x83225AB0: set u64@0x38, u32@0x2c, u32@0x30, u64@0x40, u64@0x48, u64@0x50 */
void ts4l_set_u64_off38_83225AB0(ts4l_word a0)
{
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 56) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)-1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)1;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 64) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 72) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 80) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 88) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 96) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 104) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 108) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 112) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 128) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 132) = (ts4l_word)0;
    return;
}

/* Loader_DLL.xex 0x83226E48: call_seq fn_83226FC0, lbl_8302B458, u64@0x38, u32@0x2c, u32@0x0, u32@0x30 */
ts4l_word ts4l_call_seq_fn_83226FC0_83226E48(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 56) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)-1;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B458;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)1;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 64) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 72) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 80) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 88) = (ts4l_u64)0;
    *(volatile ts4l_u64 *)((char *)(ts4l_word)(a0) + 96) = (ts4l_u64)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 104) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 108) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 112) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 120) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 128) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 132) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83226F10: if_call_seq lbl_8302B458, u32@0x0, fn_83225F90, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B458_83226F10(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B458;
    fn_83225F90();
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32778));
    }
    return a0;
}

/* Loader_DLL.xex 0x83227398: if_call_seq lbl_8302B4E0, u32@0x0, fn_83227008, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B4E0_83227398(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B4E0;
    fn_83227008((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32771));
    }
    return a0;
}

/* Loader_DLL.xex 0x832279E0: if_call_seq u32@0x238, fn_832341A0, u32@0x23c, fn_832341A0, u32@0x0, u32@0x23c */
ts4l_word ts4l_if_call_seq_u32_off238_832279E0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word p12;
    ts4l_word loc54[1];
    ts4l_word loc50[1];
    int t2;
    ts4l_word t5;
    ts4l_word t11;

    (void)a2;
    loc54[0] = (ts4l_word)0;
    loc50[0] = (ts4l_word)0;
    t2 = fn_832341A0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 568)), (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc54[0], (ts4l_word)a3);
    p12 = (ts4l_word)t2;
    if ((int)t2 >= 0) {
        fn_832341A0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 572)), (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
        t5 = loc50[0];
        if ((ts4l_word)t5 != 0 && (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t5) + 0)) != 0) {
            fn_83234120((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 572)), (ts4l_word)a1);
        }
        t11 = fn_83234120((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 568)), (ts4l_word)a1);
        p12 = (ts4l_word)t11;
    }
    return p12;
}

/* Loader_DLL.xex 0x832296A0: if_call_seq u32@0x210, u32@0x4, u32@0x14, u32@0x238, fn_832341A0, u32@0x24 */
ts4l_word ts4l_if_call_seq_u32_off210_832296A0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word loc50[4];
    int t5;
    ts4l_word t6;
    ts4l_word t7;

    loc50[0] = (ts4l_word)0;
    if (((((ts4l_word)a0 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 528)) != 0) && (ts4l_word)a2 <= (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) + 20))) && (ts4l_word)(a1 & 0xffff) >= 1) && (ts4l_word)(a1 & 0xffff) <= 127) {
        t5 = fn_832341A0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 568)), (ts4l_word)(a1 & 0xff), (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a3);
        if ((int)t5 >= 0) {
            t6 = loc50[0];
            *(ts4l_word *)((char *)(ts4l_word)(t6) + 36) = (ts4l_word)a2;
        }
        t7 = fn_83228A88((ts4l_word)t5);
        return t7;
    }
    return 4;
}

/* Loader_DLL.xex 0x8322BAA8: if_call_seq u32@0x210, fn_83228290, fn_83228A88 */
ts4l_word ts4l_if_call_seq_u32_off210_8322BAA8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;
    ts4l_word t3;

    if ((((ts4l_word)a0 != 0 && (ts4l_word)(a1 & 0xffff) >= 1) && (ts4l_word)(a1 & 0xffff) <= 127) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 528)) != 0) {
        t2 = fn_83228290((ts4l_word)a0, (ts4l_word)(a1 & 0xff), (ts4l_word)0);
        t3 = fn_83228A88((ts4l_word)t2);
        return t3;
    }
    return 4;
}

/* Loader_DLL.xex 0x8322BB10: if_call_seq u32@0x210, fn_83228290, fn_83228A88 */
ts4l_word ts4l_if_call_seq_u32_off210_8322BB10(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;
    ts4l_word t3;

    if ((((ts4l_word)a0 != 0 && (ts4l_word)(a1 & 0xffff) >= 1) && (ts4l_word)(a1 & 0xffff) <= 127) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 528)) != 0) {
        t2 = fn_83228290((ts4l_word)a0, (ts4l_word)(a1 & 0xff), (ts4l_word)1);
        t3 = fn_83228A88((ts4l_word)t2);
        return t3;
    }
    return 4;
}

/* Loader_DLL.xex 0x8322C020: call_seq fn_833E3A30, fn_833E3A30, u32@0x11c, fn_832361A0 */
ts4l_word ts4l_call_seq_fn_833E3A30_8322C020(ts4l_word a0)
{
    ts4l_word t3;

    fn_833E3A30((ts4l_word)(a0 + 204), (ts4l_word)0, (ts4l_word)80);
    fn_833E3A30((ts4l_word)(a0 + 124), (ts4l_word)0, (ts4l_word)80);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 284) = (ts4l_word)0;
    t3 = fn_832361A0((ts4l_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x8322C078: call_seq fn_833E3A30, fn_833E3A30, u32@0x11c, fn_832361A0 */
ts4l_word ts4l_call_seq_fn_833E3A30_8322C078(ts4l_word a0)
{
    ts4l_word t3;

    fn_833E3A30((ts4l_word)(a0 + 204), (ts4l_word)0, (ts4l_word)80);
    fn_833E3A30((ts4l_word)(a0 + 124), (ts4l_word)0, (ts4l_word)80);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 284) = (ts4l_word)0;
    t3 = fn_832361A0((ts4l_word)a0);
    return t3;
}

/* Loader_DLL.xex 0x8322C190: if_call_seq lbl_8302B850, u32@0x0, fn_83236198, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302B850_8322C190(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B850;
    fn_83236198((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32824));
    }
    return a0;
}

/* Loader_DLL.xex 0x8322C968: if_call_seq fn_83239578, u32@0x40, u16@0x4c, u32@0x48, u32@0x44 */
ts4l_word ts4l_if_call_seq_fn_83239578_8322C968(ts4l_word a0)
{
    ts4l_word p6;
    int t1;

    if ((ts4l_word)a0 == 0) {
        return 2;
    }
    t1 = fn_83239578((ts4l_word)a0, (ts4l_word)0);
    p6 = (ts4l_word)t1;
    if (((((int)t1 != 0 || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 64)) == 0) || (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 76)) == 0) || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 72)) == 0) || (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 68)) == 0) {
        p6 = (ts4l_word)3;
    }
    return p6;
}
