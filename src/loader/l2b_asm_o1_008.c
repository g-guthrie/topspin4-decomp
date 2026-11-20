/* Loader_DLL.xex 0x8317AAF8-0x8318A310, executable version 0.0.0.3. */
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

extern char lbl_83008318[];
extern char lbl_83008348[];
extern char lbl_83008434[];
extern char lbl_830084E0[];
extern char lbl_830088C4[];
extern char lbl_830088D8[];
extern char lbl_830088EC[];
extern char lbl_83008970[];
extern char lbl_830089AC[];
extern char lbl_830089C0[];
extern char lbl_83008A30[];
extern char lbl_83008A44[];
extern char lbl_83008A80[];
extern char lbl_83008A94[];
extern char lbl_83008AD0[];
extern char lbl_83008AE4[];
extern char lbl_83008B24[];
extern char lbl_83008B38[];
extern char lbl_835284F8[];
extern char lbl_83528928[];
extern char lbl_83528D58[];
extern char lbl_83529188[];
extern char lbl_835295B8[];
extern char lbl_835299E8[];
extern char lbl_83531690[];
ts4_word fn_8316F010();
ts4_word fn_83176ED8();
ts4_word fn_831792D8();
ts4_word fn_83179DB0();
ts4_word fn_83179E40();
ts4_word fn_8317B558();
ts4_word fn_8317CB38();
ts4_word fn_8317CBC8();
ts4_word fn_83180808();
ts4_word fn_83181578();
ts4_word fn_83181C08();
ts4_word fn_83181D00();
ts4_word fn_83182128();
ts4_word fn_83182760();
ts4_word fn_831834A8();
ts4_word fn_83183A38();
ts4_word fn_83184218();
ts4_word fn_83184338();
ts4_word fn_83185C28();
ts4_word fn_83186590();
ts4_word fn_83187058();
ts4_word fn_83187EF8();
ts4_word fn_831886B8();
ts4_word fn_83188820();
ts4_word fn_83188868();
ts4_word fn_83188B68();
ts4_word fn_83188F68();
ts4_word fn_831890B8();
ts4_word fn_83189338();
ts4_word fn_83189500();
ts4_word fn_8319D4C0();
ts4_word fn_8319E878();
ts4_word fn_831A14B0();
ts4_word fn_831A1598();
ts4_word fn_831A3268();
ts4_word fn_831A49B0();
ts4_word fn_831A5178();
ts4_word fn_831BB1B8();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();

/* Loader_DLL.xex 0x8317AAF8: call_seq lbl_83008348, lbl_83008318, u32@0x4, u32@0x8c, u32@0x0, fn_83179E40 */
ts4_word ts4l_call_seq_lbl_83008348_8317AAF8(ts4_word a0)
{
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_83008348;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(ts4_word)lbl_83008318;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_83179E40((ts4_word)(a0 + 664));
    fn_83179E40((ts4_word)(a0 + 624));
    fn_831792D8((ts4_word)(a0 + 616));
    fn_83179DB0((ts4_word)(a0 + 548));
    fn_83179DB0((ts4_word)(a0 + 508));
    t6 = fn_83176ED8((ts4_word)a0);
    return t6;
}

/* Loader_DLL.xex 0x8317D8A0: call_seq lbl_830084E0, lbl_83008434, u32@0x4, u32@0x8c, u32@0x0, fn_8317CBC8 */
ts4_word ts4l_call_seq_lbl_830084E0_8317D8A0(ts4_word a0)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_830084E0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(ts4_word)lbl_83008434;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_8317CBC8((ts4_word)(a0 + 540));
    fn_8317CB38((ts4_word)(a0 + 500));
    fn_8317B558((ts4_word)(a0 + 492));
    t4 = fn_83176ED8((ts4_word)a0);
    return t4;
}

/* Loader_DLL.xex 0x83182288: if_call_seq fn_83181578, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4l_if_call_seq_fn_83181578_83182288(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83181578((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 208));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83182458: if_get u32@0x48, u32@0x80, u32@0x0, u32@0x3c, vcall, fn_83181C08 */
ts4_word ts4l_if_get_u32_off48_83182458(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p21;
    ts4_word t1;
    ts4_word t8;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 128)) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0, (ts4_word)1);
    }
    fn_83181C08((ts4_word)a0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t8 != 0) {
        fn_8319D4C0((ts4_word)t8);
        fn_83180808((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t12 != 0) {
        fn_831A14B0((ts4_word)t12);
        fn_83180808((ts4_word)t12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p21 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t19 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 4))))((ts4_word)t16, (ts4_word)0);
        t20 = fn_83180808((ts4_word)t19);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
        p21 = (ts4_word)t20;
    }
    return p21;
}

/* Loader_DLL.xex 0x83182550: if_get u32@0x1c, u32@0x8, vcall, u32@0x17c, fn_83181D00, u32@0x0 */
ts4_word ts4l_if_get_u32_off1c_83182550(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    int t4;
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 380);
    p6 = (ts4_word)0;
    if ((int)t4 == 2) {
        t5 = fn_83181D00((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    return p6;
}

/* Loader_DLL.xex 0x831825C8: if_get u32@0x48, u32@0x40, u32@0x8, vcall, u32@0x1c, u32@0x8 */
ts4_word ts4l_if_get_u32_off48_831825C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t13;
    int t18;
    ts4_word t21;
    ts4_word t26;
    ts4_word t29;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64))) + 8))))((ts4_word)(t1 + 64));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    fn_831A1598((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)(a1 + 4));
    fn_83182128((ts4_word)a0, (ts4_word)(a1 + 4));
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 40))))((ts4_word)(a1 + 4));
    fn_8319E878((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)t13);
    t18 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 36))))((ts4_word)(a1 + 4));
    if ((int)t18 == 2) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    }
    t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 4)) + 0))) + 4))))((ts4_word)(a1 + 4), (ts4_word)0);
    fn_83180808((ts4_word)t21);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t29 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 64))) + 20))))((ts4_word)(t26 + 64));
    return t29;
}

/* Loader_DLL.xex 0x83182BA0: if_call_seq fn_83182760, fn_83180808 */
ts4_word ts4l_if_call_seq_fn_83182760_83182BA0(ts4_word a0, ts4_word a1)
{

    fn_83182760((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83180808((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83183900: call_seq lbl_830088EC, lbl_830088D8, lbl_830088C4, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4l_call_seq_lbl_830088EC_83183900(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830088EC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_830088D8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(ts4_word)lbl_830088C4;
    fn_831834A8((ts4_word)a0);
    t2 = fn_831A3268((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x831839B8: call_seq lbl_835284F8, fn_831A5178, lbl_83008970, u32@0x20, u32@0x0, u32@0x24 */
ts4_word ts4l_call_seq_lbl_835284F8_831839B8(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_835284F8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008970;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    return a0;
}

/* Loader_DLL.xex 0x83183C70: if_call_seq lbl_83008970, u32@0x0, fn_831A3268, fn_83183A38 */
ts4_word ts4l_if_call_seq_lbl_83008970_83183C70(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008970;
    fn_831A3268((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83183A38((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83183CC8: call_seq u32@0x38, u32@0x2c, fn_833E3A30, u32@0x38, u32@0x30, fn_833E3A30 */
ts4_word ts4l_call_seq_u32_off38_83183CC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)0, (ts4_word)(t1 << 2));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t6 = fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)0, (ts4_word)(t4 << 2));
    return t6;
}

/* Loader_DLL.xex 0x83184140: call_seq lbl_83528928, fn_831A5178, lbl_830089C0, lbl_830089AC, u32@0x60, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83528928_83184140(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_83528928);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830089C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_830089AC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    fn_833E3A30((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)36);
    fn_833E3A30((ts4_word)(a0 + 72), (ts4_word)0, (ts4_word)24);
    return a0;
}

/* Loader_DLL.xex 0x831842E8: call_seq lbl_830089C0, lbl_830089AC, u32@0x0, u32@0x20, fn_83184218, fn_831A3268 */
ts4_word ts4l_call_seq_lbl_830089C0_831842E8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830089C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_830089AC;
    fn_83184218((ts4_word)a0);
    t2 = fn_831A3268((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x831844A0: if_call_seq fn_831A49B0, u32@0x0, u16@0x2, fn_83184338 */
ts4_word ts4l_if_call_seq_fn_831A49B0_831844A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    int t1;
    ts4_word t4;

    (void)a1;
    t1 = fn_831A49B0((ts4_word)a0, (ts4_word)1, (ts4_word)a2, (ts4_word)1);
    p5 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t4 = fn_83184338((ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 2)));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x83184660: if_call_seq u32@0x104, u32@0x60, u32@0x54, fn_833E3A30, u32@0x60, u32@0x58 */
ts4_word ts4l_if_call_seq_u32_off104_83184660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 260);
    p8 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)0, (ts4_word)(t2 << 2));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        t7 = fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)0, (ts4_word)(t5 << 2));
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Loader_DLL.xex 0x83185B08: call_seq lbl_83528D58, fn_831A5178, lbl_83008A44, lbl_83008A30, u32@0xb8, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83528D58_83185B08(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_83528D58);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008A44;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008A30;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    fn_833E3A30((ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)36);
    fn_833E3A30((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)40);
    fn_833E3A30((ts4_word)(a0 + 112), (ts4_word)0, (ts4_word)72);
    return a0;
}

/* Loader_DLL.xex 0x83185DA8: call_seq lbl_83008A44, lbl_83008A30, u32@0x0, u32@0x20, fn_83185C28, fn_831A3268 */
ts4_word ts4l_call_seq_lbl_83008A44_83185DA8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008A44;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008A30;
    fn_83185C28((ts4_word)a0);
    t2 = fn_831A3268((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83186998: call_seq lbl_83529188, fn_831A5178, lbl_83008A94, lbl_83008A80, u16@0x24, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83529188_83186998(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_83529188);
    *(unsigned short *)((char *)(ts4_word)(a0) + 36) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008A94;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008A80;
    *(unsigned short *)((char *)(ts4_word)(a0) + 38) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 40) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    return a0;
}

/* Loader_DLL.xex 0x83186A58: if_call_seq u32@0x2c, lbl_83008A94, lbl_83008A80, u32@0x0, u32@0x20, fn_83186590 */
ts4_word ts4l_if_call_seq_u32_off2c_83186A58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008A94;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008A80;
    if ((ts4_word)t1 != 0) {
        fn_83186590((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t5 = fn_831A3268((ts4_word)a0);
    return t5;
}

/* Loader_DLL.xex 0x83186B10: call_seq u32@0x2c, u32@0x28, fn_833E3A30, u32@0x2c, u32@0x24, fn_833E3A30 */
ts4_word ts4l_call_seq_u32_off2c_83186B10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)0, (ts4_word)(t1 << 2));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)0, (ts4_word)(t4 << 2));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)0, (ts4_word)(t7 << 2));
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t12 = fn_833E3A30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)0, (ts4_word)(t10 << 2));
    return t12;
}

/* Loader_DLL.xex 0x83186F98: call_seq lbl_835295B8, fn_831A5178, lbl_83008AE4, lbl_83008AD0, u32@0x3c, u32@0x0 */
ts4_word ts4l_call_seq_lbl_835295B8_83186F98(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_835295B8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008AE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008AD0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    fn_833E3A30((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)24);
    return a0;
}

/* Loader_DLL.xex 0x83187128: call_seq lbl_83008AE4, lbl_83008AD0, u32@0x0, u32@0x20, fn_83187058, fn_831A3268 */
ts4_word ts4l_call_seq_lbl_83008AE4_83187128(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008AE4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008AD0;
    fn_83187058();
    t2 = fn_831A3268((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83187E18: call_seq lbl_835299E8, fn_831A5178, lbl_83008B38, lbl_83008B24, u32@0x24, u32@0x0 */
ts4_word ts4l_call_seq_lbl_835299E8_83187E18(ts4_word a0)
{
    fn_831A5178((ts4_word)a0, (ts4_word)(ts4_word)lbl_835299E8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008B38;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008B24;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    fn_8316F010((ts4_word)(ts4_word)lbl_83531690);
    fn_833E3A30((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)156);
    return a0;
}

/* Loader_DLL.xex 0x83187FC0: call_seq lbl_83008B38, lbl_83008B24, u32@0x0, u32@0x20, fn_83187EF8, fn_831A3268 */
ts4_word ts4l_call_seq_lbl_83008B38_83187FC0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008B38;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_83008B24;
    fn_83187EF8((ts4_word)a0);
    t2 = fn_831A3268((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83188A58: if_call_seq fn_831886B8, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_831886B8_83188A58(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_831886B8((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83189130: get u32@0x0, u32@0x4, u32@0x8, u32@0x18, u32@0x0, u32@0xc */
ts4_word ts4l_get_u32_off0_83189130(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)0, (ts4_word)t4, (ts4_word)((((int)t3 * (int)t2) + 3) << 2));
    t9 = fn_833E3AD0((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)12);
    return t9;
}

/* Loader_DLL.xex 0x831892E8: if_call_seq fn_831BB1B8, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_831BB1B8_831892E8(ts4_word a0, ts4_word a1)
{

    fn_831BB1B8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83188F68((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83189480: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x38, u32@0x0 */
ts4_word ts4l_get_u32_off30_83189480(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Loader_DLL.xex 0x83189588: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x84, u32@0x0 */
ts4_word ts4l_get_u32_off30_83189588(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5, (ts4_word)0, (ts4_word)a2, (ts4_word)a1, (ts4_word)12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x83189608: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x84, u32@0x0 */
ts4_word ts4l_get_u32_off30_83189608(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)0, (ts4_word)a1, (ts4_word)12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t12;
}

/* Loader_DLL.xex 0x83189690: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_83189500, u32@0x8 */
ts4_word ts4l_get_u32_off30_83189690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_83189500((ts4_word)a0, (ts4_word)a1);
    t7 = fn_831890B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 8)), (ts4_word)a2, (ts4_word)a3);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t7;
}

/* Loader_DLL.xex 0x83189770: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x30, u32@0x2c */
ts4_word ts4l_get_u32_off30_83189770(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 72));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 44))) + 20))))((ts4_word)(t6 + 44));
    return t9;
}

/* Loader_DLL.xex 0x831897E0: if_get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x0, u32@0x60 */
ts4_word ts4l_if_get_u32_off30_831897E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    if ((int)t7 >= 0) {
        fn_833E3AD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)a2, (ts4_word)(a1 << 2));
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 44))) + 20))))((ts4_word)(t11 + 44));
    return t7;
}

/* Loader_DLL.xex 0x83189870: if_get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, u32@0x3c */
ts4_word ts4l_if_get_u32_off30_83189870(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t5;
    ts4_word t12;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t5 != 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    }
    if ((ts4_word)a1 == (ts4_word)p8) {
        fn_833E3AD0((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)), (ts4_word)(a1 << 2));
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 44))) + 20))))((ts4_word)(t12 + 44));
    return t15;
}

/* Loader_DLL.xex 0x831898F0: get u32@0x30, u32@0x2c, u32@0x8, vcall, fn_83189500, u32@0x8 */
ts4_word ts4l_get_u32_off30_831898F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = fn_83189500((ts4_word)a0, (ts4_word)a1);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
    fn_833E3AD0((ts4_word)a4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 20)), (ts4_word)(((int)t7 * (int)t8) << 2));
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 44))) + 20))))((ts4_word)(t11 + 44));
    return t14;
}

/* Loader_DLL.xex 0x83189CA8: if_call_seq fn_83188B68, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_83188B68_83189CA8(ts4_word a0, ts4_word a1)
{

    fn_83188B68();
    if ((int)(a1 & 0x1) != 0) {
        fn_83188F68((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83189F40: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_83189F40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x83189FB0: if_call_seq fn_83189338, fn_831BB1B8, fn_83188F68 */
ts4_word ts4l_if_call_seq_fn_83189338_83189FB0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            fn_831BB1B8((ts4_word)a2);
            t4 = fn_83188F68((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_83189338((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x8318A240: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_83188820 */
ts4_word ts4l_get_u32_off30_8318A240(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_83188820((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t6;
}

/* Loader_DLL.xex 0x8318A2A8: get u32@0x30, u32@0x2c, u32@0x8, vcall, u32@0x34, fn_83188868 */
ts4_word ts4l_get_u32_off30_8318A2A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t6 = fn_83188868((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)a2);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 44))) + 20))))((ts4_word)(t7 + 44));
    return t6;
}
