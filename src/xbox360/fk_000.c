/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_880C1320[];
extern char lbl_880D19F0[];
extern char lbl_880D1FD0[];
extern char lbl_880D2208[];
extern char lbl_880D2D10[];
extern char lbl_880D2DEC[];
extern char lbl_880D3118[];
extern char lbl_880D4B88[];
extern char lbl_880D4EA0[];
extern char lbl_880D5078[];
extern char lbl_880D5168[];
extern char lbl_880D5528[];
extern char lbl_880D5570[];
extern char lbl_880D55B8[];
extern char lbl_880D5600[];
extern char lbl_880D5864[];
extern char lbl_880D5A64[];
extern char lbl_880D5AA0[];
extern char lbl_880D5B10[];
extern char lbl_880D5BBC[];
extern char lbl_880D5EE8[];
extern char lbl_880D6A78[];
extern char lbl_880D6B70[];
extern char lbl_880D7058[];
extern char lbl_880D7074[];
extern char lbl_880D709C[];
extern char lbl_880D70B8[];
extern char lbl_880D70D4[];
extern char lbl_880D70F0[];
extern char lbl_880D710C[];
extern char lbl_880D7128[];
extern char lbl_880D7144[];
extern char lbl_880D7160[];
extern char lbl_880D717C[];
extern char lbl_880D7310[];
extern char lbl_880D7380[];
extern char lbl_880D73C4[];
extern char lbl_880D73FC[];
extern char lbl_880D7570[];
extern char lbl_880DB358[];
extern char lbl_880DB478[];
extern char lbl_880DB648[];
extern char lbl_880DB6C0[];
extern char lbl_880F7D28[];
extern char lbl_88D45878[];
extern char lbl_88D4588C[];
extern char lbl_88D458A0[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_88155A40();
ts4_word fn_88157B78();
ts4_word fn_88158908();
ts4_word fn_88159870();
ts4_word fn_8815B060();
ts4_word fn_8815C9E8();
ts4_word fn_8815D160();
ts4_word fn_8815DB40();
ts4_word fn_8815DC10();
ts4_word fn_8815DCE0();
ts4_word fn_8815DDC0();
ts4_word fn_8815DF80();
ts4_word fn_8815E628();
ts4_word fn_8815ED78();
ts4_word fn_8815EF18();
ts4_word fn_881616D8();
ts4_word fn_881617C8();
ts4_word fn_88161B30();
ts4_word fn_88165F68();
ts4_word fn_88165FC8();
ts4_word ts4_call_seq_fn_8815ED78_88166A10();
ts4_word fn_8816C6B0();
ts4_word fn_8816D1A8();
ts4_word fn_8816DFB8();
ts4_word fn_88173C00();
ts4_word fn_8817EB80();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8817F480();
ts4_word fn_8817F860();
ts4_word ts4_if_call_seq_u32_off0_88181618();
ts4_word fn_881A6A00();
ts4_word ts4_tailcall_NetDll_ioctlsocket_884F0268();
ts4_word ts4_tailcall_NetDll_accept_884F02E0();
ts4_word fn_88562DC0();
ts4_word ts4_tailcall_fn_88564B00_88564770();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_8860DCF8();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word fn_88616758();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_888860A0();
ts4_word ts4_call_seq_fn_88617D88_888CB0F0();
ts4_word ts4_call_seq_fn_88617D88_888CB978();
ts4_word fn_888CBD50();
ts4_word ts4_singleton_service_ctor_888CCF98();
ts4_word ts4_call_seq_fn_88617D88_888CDDC0();
ts4_word fn_888CED28();
ts4_word ts4_call_seq_fn_88617D88_888CF0D8();
ts4_word fn_888D7500();
ts4_word fn_888D8B18();
ts4_word fn_888DDBC8();
ts4_word ts4_call_seq_fn_88617D88_888DE4C8();
ts4_word ts4_call_seq_lbl_880DB358_888DF440();
ts4_word fn_888DF740();
ts4_word fn_888F1658();
ts4_word fn_88901810();
ts4_word fn_8890FF78();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word fn_88913740();
ts4_word fn_88918908();
ts4_word ts4_if_call_seq_u32_off24_88929630();
ts4_word fn_8892AF80();
ts4_word ts4_if_call_seq_u32_off14_88936980();
ts4_word fn_88936F98();
ts4_word fn_88938660();
ts4_word fn_88938740();
ts4_word ts4_call_seq_fn_88617D88_88945A10();
ts4_word fn_88951690();
ts4_word fn_88951E48();
ts4_word fn_88955100();
ts4_word ts4_call_seq_fn_88617D88_88955D78();
ts4_word fn_88956498();
ts4_word ts4_call_seq_fn_88617D88_88956CC8();
ts4_word ts4_call_seq_fn_88617D88_889585F8();
ts4_word fn_88959958();
ts4_word fn_88961050();
ts4_word fn_889659E0();
ts4_word fn_88975C98();
ts4_word ts4_call_seq_fn_88617D88_88978968();
ts4_word ts4_if_get_u32_off1c_8898EDC8();
ts4_word fn_88998B10();
ts4_word fn_88999F38();
ts4_word ts4_call_seq_fn_88617D88_889A0AE8();
ts4_word fn_889A0CA8();
ts4_word fn_889A3CF0();
ts4_word fn_889A4270();
ts4_word fn_889C53E0();
ts4_word fn_889C7180();
ts4_word fn_889C7E98();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88150878: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88150878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)a1, (ts4_word)1, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881508D8: set u32@0x0, u32@0x0, u32@0x4, vcall */
ts4_word ts4_set_u32_off0_881508D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88150920: if_get u32@0x0, lbl_880C1320 */
ts4_word ts4_if_get_u32_off0_88150920(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != -1) {
        return (t1 + a0);
    }
    return (ts4_word)lbl_880C1320;
}

/* Swing_DLL.xex 0x88151548: get u32@0xc, u32@0x0 */
ts4_word ts4_get_u32_offc_88151548(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return ((t1 + -1) != 0);
}

/* Swing_DLL.xex 0x88154890: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88938740, lbl_880D1FD0, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154890(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88938740((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D1FD0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154910: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88938740, lbl_880D1FD0, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154910(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88938740((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D1FD0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154990: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88998B10, lbl_880D2208, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154990(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)288, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88998B10((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2208;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154A08: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88998B10, lbl_880D2208, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154A08(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)288, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88998B10((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2208;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154A80: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A0CA8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154A80(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A0CA8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154AD8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A0CA8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154AD8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A0CA8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154B30: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_889A0AE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154B30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)284, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_889A0AE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154B88: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_889A0AE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154B88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)284, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_889A0AE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154BE0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A4270 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154BE0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)360, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A4270((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154C38: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A4270 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154C38(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)360, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A4270((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154C90: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A3CF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154C90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)480, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A3CF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88154CE8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889A3CF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88154CE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)480, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889A3CF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88156F58: if_call_seq lbl_880D2DEC, u32@0x0, fn_88157B78, fn_88936F98, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D2DEC_88156F58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2DEC;
    fn_88157B78((ts4_word)(a0 + 36));
    fn_88936F98((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88157870: get u32@0x0, u32@0x1c, vcall, u32@0x0, u32@0x18, vcall */
ts4_word ts4_get_u32_off0_88157870(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 28))))((ts4_word)a1);
    loc50[0] = (ts4_word)t3;
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    t8 = ts4_tailcall_NetDll_accept_884F02E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)&loc50[0]);
    return t8;
}

/* Swing_DLL.xex 0x881578E8: call_seq u32@0x4, ts4_tailcall_NetDll_ioctlsocket_884F0268 */
ts4_word ts4_call_seq_u32_off4_881578E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)((a1 & 0xff) == 0);
    t2 = ts4_tailcall_NetDll_ioctlsocket_884F0268((ts4_word)t1, (ts4_word)((2147745792) | 26238), (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x881580D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88999F38 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881580D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88999F38((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88158128: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88999F38 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88158128(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88999F38((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88158180: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88938740, lbl_880D2D10, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88158180(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)104, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88938740((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2D10;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88158200: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88938740, lbl_880D2D10, u32@0x64, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88158200(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)104, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88938740((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 100) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2D10;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88158350: call_seq lbl_880D3118, u32@0x0, ts4_if_get_u32_off1c_8898EDC8, fn_88159870, fn_88159870 */
ts4_word ts4_call_seq_lbl_880D3118_88158350(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D3118;
    ts4_if_get_u32_off1c_8898EDC8((ts4_word)a0);
    fn_88159870((ts4_word)(a0 + 16));
    t3 = fn_88159870((ts4_word)(a0 + 4));
    return t3;
}

/* Swing_DLL.xex 0x88158398: if_call_seq lbl_880D3118, u32@0x0, ts4_if_get_u32_off1c_8898EDC8, fn_88159870, fn_88159870, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D3118_88158398(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D3118;
    ts4_if_get_u32_off1c_8898EDC8((ts4_word)a0);
    fn_88159870((ts4_word)(a0 + 16));
    fn_88159870((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88158648: if_call_seq u32@0x0, fn_888860A0, u32@0x6c, u32@0x68, fn_8815DDC0, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off0_88158648(ts4_word a0)
{
    ts4_word p41;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;
    ts4_word t15;
    ts4_word t18;
    ts4_word t21;
    ts4_word t24;
    ts4_word t27;
    ts4_word t30;
    ts4_word t33;
    ts4_word t36;
    ts4_word t39;
    ts4_word t40;

    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    fn_8815DDC0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 104)), (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    fn_8815DCE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)t9);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t12 != 0) {
        ts4_destroy_owned_object((ts4_word)t12);
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    fn_8815DC10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)), (ts4_word)t15);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t18 != 0) {
        ts4_destroy_owned_object((ts4_word)t18);
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    fn_8815DB40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)t21);
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t24 != 0) {
        ts4_destroy_owned_object((ts4_word)t24);
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t27 != 0) {
        ts4_destroy_owned_object((ts4_word)t27);
    }
    t30 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t30 != 0) {
        ts4_destroy_owned_object((ts4_word)t30);
    }
    t33 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t33 != 0) {
        ts4_destroy_owned_object((ts4_word)t33);
    }
    t36 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t36 != 0) {
        ts4_destroy_owned_object((ts4_word)t36);
    }
    t39 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p41 = (ts4_word)t39;
    if ((ts4_word)t39 != 0) {
        t40 = ts4_destroy_owned_object((ts4_word)t39);
        p41 = (ts4_word)t40;
    }
    return p41;
}

/* Swing_DLL.xex 0x88158788: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, fn_8815B060 */
ts4_word ts4_call_seq_u32_off0_88158788(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    fn_8815B060((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
    return a0;
}

/* Swing_DLL.xex 0x88158890: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_88158890(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    fn_88158908((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    fn_88158908((ts4_word)(a0 + 28), (ts4_word)(a1 + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    return a0;
}

/* Swing_DLL.xex 0x88159A58: if_call_seq u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, fn_8815C9E8 */
ts4_word ts4_if_call_seq_u32_off0_88159A58(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    fn_8815C9E8((ts4_word)a0, (ts4_word)((t2 - t1) + 1));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t2 != (ts4_word)t1) {
        t5 = fn_88562DC0((ts4_word)t4, (ts4_word)t1, (ts4_word)(t2 - t1));
        p6 = (ts4_word)(t5 + (t2 - t1));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p6;
    *(unsigned char *)((char *)(ts4_word)(p6) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88159AC0: call_seq u32@0x0, u32@0x4, u32@0x8, fn_8815D160, u32@0x0, u32@0x4 */
ts4_word ts4_call_seq_u32_off0_88159AC0(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = fn_8815D160((ts4_word)8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t1 + 8);
    *(unsigned char *)((char *)(ts4_word)(t1) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8815C920: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8815C920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 1), (ts4_word)2, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8815CA60: if_call_seq fn_8815DF80 */
ts4_word ts4_if_call_seq_fn_8815DF80_8815CA60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word loc5c[1];
    ts4_word loc60[1];
    ts4_word t2;

    loc50[0] = (ts4_word)a2;
    loc54[0] = (ts4_word)a3;
    loc58[0] = (ts4_word)a0;
    loc5c[0] = (ts4_word)a1;
    fn_8815DF80((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc5c[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc60[0];
    if ((ts4_word)t2 == (ts4_word)a0) {
        return a1;
    }
    return ((t2 - a3) + a2);
}

/* Swing_DLL.xex 0x8815D770: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8815D770(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 2), (ts4_word)1, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8815E0F8: if_get u32@0xc, u32@0x8, u32@0xc, u32@0x8, u32@0x4, u32@0x4 */
void ts4_if_get_u32_offc_8815E0F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a0 == (ts4_word)t5) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        return;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)a0 == (ts4_word)t7) {
        *(ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t6) + 12) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8815E168: if_get u32@0x8, u32@0xc, u32@0x8, u32@0xc, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off8_8815E168(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)a0;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a0 == (ts4_word)t5) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        return;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 12);
    if ((ts4_word)a0 == (ts4_word)t7) {
        *(ts4_word *)((char *)(ts4_word)(t6) + 12) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8815E698: call_seq ts4_assign_formatted_text, lbl_880C1320, ts4_assign_formatted_text, ts4_assign_formatted_text, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_ts4_assign_formatted_text_8815E698(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    ts4_assign_formatted_text();
    ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8815E898: if_call_seq ts4_object_finalize, ts4_object_finalize, u32@0x34, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_ts4_object_finalize_8815E898(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t10;

    ts4_object_finalize((ts4_word)(a0 + 40));
    ts4_object_finalize((ts4_word)(a0 + 52));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 40)) + 0);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    t10 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t10;
}

/* Swing_DLL.xex 0x8815E9B0: call_seq u32@0x0, lbl_880C1320, u32@0x4, u32@0x8, ts4_assign_formatted_text, ts4_assign_formatted_text */
ts4_word ts4_call_seq_u32_off0_8815E9B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 36), (ts4_word)(ts4_word)lbl_880C1320);
    return a0;
}

/* Swing_DLL.xex 0x8815EA20: if_call_seq u32@0x24, ts4_destroy_owned_object, u32@0x18, ts4_destroy_owned_object, u32@0xc, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off24_8815EA20(ts4_word a0)
{
    ts4_word p12;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_destroy_owned_object((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x8815EB90: call_seq fn_8815E628, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8, u32@0x5c */
ts4_word ts4_call_seq_fn_8815E628_8815EB90(ts4_word a0)
{
    fn_8815E628((ts4_word)a0);
    fn_8816D1A8((ts4_word)(a0 + 48));
    fn_8816D1A8((ts4_word)(a0 + 60));
    fn_8816D1A8((ts4_word)(a0 + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8815EBE0: call_seq u32@0x48, ts4_destroy_owned_object, u32@0x3c, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_call_seq_u32_off48_8815EBE0(ts4_word a0)
{
    ts4_word t12;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t12 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t12;
}

/* Swing_DLL.xex 0x8815ED08: call_seq fn_88150600, fn_88150600, fn_88150600, u32@0x24, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88150600_8815ED08(ts4_word a0, ts4_word a1)
{
    fn_88150600((ts4_word)a0, (ts4_word)a1);
    fn_88150600((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    fn_88150600((ts4_word)(a0 + 24), (ts4_word)(a1 + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    return a0;
}

/* Swing_DLL.xex 0x8815EEC8: call_seq u32@0x3c, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object, u32@0x18, ts4_destroy_owned_object */
ts4_word ts4_call_seq_u32_off3c_8815EEC8(ts4_word a0)
{
    ts4_word t10;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t10 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t10;
}

/* Swing_DLL.xex 0x8815FAA0: if_get u8@0xc, u32@0x0, ts4_destroy_owned_object, u32@0x8, u8@0xc, u32@0x0 */
ts4_word ts4_if_get_u8_offc_8815FAA0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    unsigned char t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t14;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        return 0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
    t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 72))))((ts4_word)t4, (ts4_word)a1);
    if ((ts4_word)(t7 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 60))))((ts4_word)t4, (ts4_word)a1);
    }
    t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 52))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)a1, (ts4_word)3, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t14) + 0));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return 1;
}

/* Swing_DLL.xex 0x8815FB60: if_call_seq u32@0x78, ts4_destroy_owned_object, u32@0x6c, ts4_destroy_owned_object, u32@0x58, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off78_8815FB60(ts4_word a0)
{
    ts4_word t13;
    ts4_word t21;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t21 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t21;
}

/* Swing_DLL.xex 0x8815FCE0: call_seq u32@0x48, ts4_destroy_owned_object, u32@0x3c, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_call_seq_u32_off48_8815FCE0(ts4_word a0)
{
    ts4_word t14;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t14 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t14;
}

/* Swing_DLL.xex 0x88160340: call_seq fn_8816D1A8, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_8816D1A8_88160340(ts4_word a0)
{
    fn_8816D1A8();
    fn_8816D1A8((ts4_word)(a0 + 12));
    fn_8816D1A8((ts4_word)(a0 + 24));
    fn_8816D1A8((ts4_word)(a0 + 36));
    fn_8816D1A8((ts4_word)(a0 + 48));
    fn_8816D1A8((ts4_word)(a0 + 60));
    fn_8816D1A8((ts4_word)(a0 + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
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
    return a0;
}

/* Swing_DLL.xex 0x88160C08: if_call_seq u32@0x8, u32@0x4, fn_8815ED78, u32@0x4, u32@0x4, fn_881616D8 */
ts4_word ts4_if_call_seq_u32_off8_88160C08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        p4 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t3 = fn_8815ED78((ts4_word)t2, (ts4_word)a1);
            p4 = (ts4_word)t3;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 48);
        return p4;
    }
    t6 = fn_881616D8((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88160CE0: call_seq u32@0x4, u32@0x0, fn_88165FC8, u32@0x4, fn_88165F68, u32@0x4 */
ts4_word ts4_call_seq_u32_off4_88160CE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_88165FC8((ts4_word)t1, (ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t5 = fn_88165F68((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    return t5;
}

/* Swing_DLL.xex 0x88160D30: if_call_seq u32@0x8, u32@0x4, u32@0x0, ts4_assign_formatted_text, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88160D30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t4 = ts4_assign_formatted_text((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a1);
            p5 = (ts4_word)t4;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 12);
        return p5;
    }
    t7 = fn_881617C8((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)1);
    return t7;
}

/* Swing_DLL.xex 0x88160FB8: if_call_seq u32@0x8, u32@0x4, ts4_call_seq_fn_8815ED78_88166A10, u32@0x4, u32@0x4, fn_88161B30 */
ts4_word ts4_if_call_seq_u32_off8_88160FB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        p4 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t3 = ts4_call_seq_fn_8815ED78_88166A10((ts4_word)t2, (ts4_word)a1);
            p4 = (ts4_word)t3;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 96);
        return p4;
    }
    t6 = fn_88161B30((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88162340: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162340(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 2), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881624B8: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881624B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 5), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88162950: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162950(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 5), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881629B0: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881629B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 3), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88162A18: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162A18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 3)) << 2), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88162AE0: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162AE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 2)) << 3), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88165360: get u32@0x0, u32@0x4, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_get_u32_off0_88165360(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)12);
    *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return t5;
}

/* Swing_DLL.xex 0x881653C8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x4, fn_8816C6B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881653C8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)5;
        fn_8816C6B0((ts4_word)(t2 + 8));
        p4 = (ts4_word)t2;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88165ED8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8815EF18, lbl_880D4EA0, u32@0x3c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88165ED8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_8815EF18((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D4EA0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)6;
        *(ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88166A88: call_seq fn_8815ED78, u32@0x30, ts4_assign_formatted_text, u32@0x3c, ts4_assign_formatted_text, u32@0x4c */
ts4_word ts4_call_seq_fn_8815ED78_88166A88(ts4_word a0, ts4_word a1)
{
    fn_8815ED78((ts4_word)a0, (ts4_word)a1);
    ts4_assign_formatted_text((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48)));
    ts4_assign_formatted_text((ts4_word)(a0 + 60), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60)));
    *(float *)((char *)(ts4_word)(a0) + 72) = (*(float *)((char *)(ts4_word)(a1) + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    return a0;
}

/* Swing_DLL.xex 0x88167AF8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88955100 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167AF8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88955100((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167B50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88955100 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167B50(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88955100((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167BA8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951E48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167BA8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88951E48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167C00: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951E48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167C00(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88951E48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167F18: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5528, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167F18(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5528;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167F90: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5528, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167F90(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5528;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168008: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5570, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168008(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5570;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168080: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5570, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168080(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5570;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881680F8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D55B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881680F8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D55B8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168170: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D55B8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168170(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D55B8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881681E8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5600, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881681E8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5600;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168260: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690, lbl_880D5600, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168260(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88951690((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5600;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881683C8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88975C98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881683C8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1392, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88975C98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168420: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88975C98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168420(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1392, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88975C98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168478: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88961050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168478(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)264, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88961050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881684D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88961050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881684D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)264, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88961050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168528: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88956CC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168528(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)92, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88956CC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168580: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88956CC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168580(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)92, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88956CC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881685D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D5078, u32@0x0, u32@lbl_88D45878 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881685D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5078;
        *(ts4_word *)lbl_88D45878 = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168658: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D5078, u32@0x0, u32@lbl_88D45878 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168658(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5078;
        *(ts4_word *)lbl_88D45878 = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881686D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88959958 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881686D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)144, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88959958((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168730: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88959958 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168730(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)144, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88959958((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168838: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88978968 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168838(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88978968((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168890: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88978968 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168890(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)400, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88978968((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881688E8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D4B88, u32@0x0, u32@lbl_88D4588C */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881688E8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D4B88;
        *(ts4_word *)lbl_88D4588C = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168968: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D4B88, u32@0x0, u32@lbl_88D4588C */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168968(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D4B88;
        *(ts4_word *)lbl_88D4588C = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881689E8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88956498 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881689E8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88956498((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168A40: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88956498 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168A40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88956498((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168B48: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_889585F8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168B48(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_889585F8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168BA0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_889585F8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168BA0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_889585F8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168BF8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D5168, u32@0x0, u32@lbl_88D458A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168BF8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5168;
        *(ts4_word *)lbl_88D458A0 = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168C78: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880D5168, u32@0x0, u32@lbl_88D458A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168C78(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D5168;
        *(ts4_word *)lbl_88D458A0 = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168CF8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889659E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168CF8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)592, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889659E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168D50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889659E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168D50(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)592, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889659E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168DA8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88955D78 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168DA8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88955D78((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168E00: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88955D78 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168E00(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88955D78((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168E58: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88945A10 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168E58(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88945A10((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168EB0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88945A10 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168EB0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88945A10((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8816BD78: if_call_seq fn_88608590, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88608590_8816BD78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = fn_88608590((ts4_word)0, (ts4_word)a2);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8816BEF8: if_call_seq ts4_tailcall_fn_88564B00_88564770, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88564770_8816BEF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = ts4_tailcall_fn_88564B00_88564770((ts4_word)a2);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t2 != (int)t1) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8816CB60: if_call_seq u32@0x0, lbl_880C1320, ts4_assign_formatted_text */
ts4_word ts4_if_call_seq_u32_off0_8816CB60(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != -1) {
        p2 = (ts4_word)(t1 + a1);
    } else {
        p2 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)p2);
    return a0;
}

/* Swing_DLL.xex 0x8816CD98: get u32@0x0, u32@0x4, u32@0x0, u32@0x28, vcall */
ts4_word ts4_get_u32_off0_8816CD98(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)4);
    *(float *)((char *)(ts4_word)(t5) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    return t5;
}

/* Swing_DLL.xex 0x8816CE90: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8816CE90(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 48))))((ts4_word)t1, (ts4_word)t3, (ts4_word)8);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t5 & 0xff) == 0) {
        loc50[0] = (ts4_word)(ts4_word)lbl_880D5864;
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 56))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t8, (ts4_word)(ts4_word)lbl_880D5864);
        t11 = loc54[0];
        return t11;
    }
    t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)4);
    return (*(ts4_word *)((char *)(ts4_word)(t14) + 0));
}

/* Swing_DLL.xex 0x8816D140: if_call_seq u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, fn_88155A40 */
ts4_word ts4_if_call_seq_u32_off0_8816D140(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    fn_88155A40((ts4_word)a0, (ts4_word)((t2 - t1) + 1));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t2 != (ts4_word)t1) {
        t5 = fn_88562DC0((ts4_word)t4, (ts4_word)t1, (ts4_word)(t2 - t1));
        p6 = (ts4_word)(t5 + (t2 - t1));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p6;
    *(unsigned char *)((char *)(ts4_word)(p6) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8816D330: if_call_seq u32@0xc, fn_8860DCF8, fn_88938660 */
ts4_word ts4_if_call_seq_u32_offc_8816D330(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)52, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88938660((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8816D628: if_call_seq lbl_880D5EE8, u32@0x0, ts4_if_call_seq_u32_off14_88936980, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D5EE8_8816D628(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5EE8;
    ts4_if_call_seq_u32_off14_88936980((ts4_word)(a0 + 12));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8816D728: call_seq fn_8816DFB8, u32@0x0, u32@0x4, u32@0x8, fn_8816DFB8, u32@0xc */
ts4_word ts4_call_seq_fn_8816DFB8_8816D728(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_8816DFB8((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_8816DFB8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8816D888: if_call_seq u32@0x4, lbl_880D5BBC, u32@0x0, fn_888860A0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_u32_off4_8816D888(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5BBC;
    fn_888860A0((ts4_word)t1);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8816D8E8: if_call_seq lbl_880D5AA0, lbl_880D5A64, u32@0x0, u32@0x4, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D5AA0_8816D8E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5AA0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8816D9E0: if_get u32@0x4, lbl_880D5B10, u32@0x0, u32@0x14, vcall, u32@0x4 */
ts4_word ts4_if_get_u32_off4_8816D9E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B10;
    if ((int)t1 != -1) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_880D5B10) + 20))))((ts4_word)a0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8816F7A8: if_call_seq lbl_880D6A78, u32@0x0, ts4_object_finalize, u32@0x54, ts4_destroy_owned_object, ts4_if_call_seq_u32_off24_88929630 */
ts4_word ts4_if_call_seq_lbl_880D6A78_8816F7A8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6A78;
    ts4_object_finalize((ts4_word)(a0 + 84));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    ts4_if_call_seq_u32_off24_88929630((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88172288: if_call_seq lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D5A64_88172288(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88172A40: if_call_seq fn_8860DCF8, fn_88918908 */
ts4_word ts4_if_call_seq_fn_8860DCF8_88172A40(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8860DCF8((ts4_word)a0, (ts4_word)1252, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t1 != 0) {
        t2 = fn_88918908((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88173A78: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88173C00 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88173A78(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88173C00((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88173AD0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88173C00 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88173AD0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88173C00((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174278: if_call_seq lbl_880D7074, u32@0x0, fn_881A6A00, u32@0x28, ts4_destroy_owned_object, fn_88617D28 */
ts4_word ts4_if_call_seq_lbl_880D7074_88174278(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7074;
    fn_881A6A00((ts4_word)(a0 + 60));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88174DE0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7058, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174DE0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7058;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174E50: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7058, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174E50(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7058;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174EC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88913740 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174EC0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88913740((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174F18: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88913740 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174F18(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88913740((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174F70: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70D4, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174F70(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70D4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88174FE8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70D4, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88174FE8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70D4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175060: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70F0, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175060(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70F0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881750D8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70F0, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881750D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70F0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175150: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D710C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175150(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D710C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881751C8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D710C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881751C8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D710C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175240: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7128, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175240(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7128;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881752B8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7128, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881752B8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7128;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175330: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7160, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175330(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7160;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881753A8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7160, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881753A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7160;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175420: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7144, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175420(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7144;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175498: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D7144, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175498(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7144;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175510: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D717C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175510(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D717C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175588: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D717C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175588(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D717C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175600: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D709C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175600(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D709C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175678: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D709C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175678(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D709C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881756F0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70B8, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881756F0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70B8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88175768: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D70B8, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88175768(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D70B8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88176ED8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, u32@0x0, lbl_880F7D28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88176ED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F7D28;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 16) = (unsigned char)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177010: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C7E98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177010(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C7E98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177068: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C7E98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177068(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C7E98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177458: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7310, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177458(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7310;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881774D0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7310, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881774D0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7310;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881775A8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7380, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881775A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7380;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177620: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7380, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177620(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D7380;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881776F8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73C4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881776F8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D73C4;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177770: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73C4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177770(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D73C4;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177848: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73FC, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177848(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D73FC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881778C0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73FC, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881778C0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D73FC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177980: if_call_seq u32@0x24, u32@0x20, lbl_880D7570, u32@0x2c, u32@0x0, fn_88616758 */
ts4_word ts4_if_call_seq_u32_off24_88177980(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7570;
    fn_88616758((ts4_word)t3, (ts4_word)t2, (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88177A68: get u32@0x0, u32@0x4, u32@0x0, u32@0x28, vcall, u16@0x0 */
ts4_word ts4_get_u32_off0_88177A68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)2);
    *(unsigned short *)((char *)(ts4_word)(t5) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a1) + 0));
    return t5;
}

/* Swing_DLL.xex 0x88177C30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C53E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177C30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C53E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177C88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C53E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177C88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C53E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177D30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C7180 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177D30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C7180((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88177D88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889C7180 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88177D88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889C7180((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88178B78: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88178B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 5), (ts4_word)16, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8817A440: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8890FF78 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8817A440(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8890FF78((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8817A498: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8890FF78 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8817A498(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8890FF78((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8817B998: call_seq u32@0x0, ts4_if_call_seq_u32_lbl_88D45B38_8817F480, u32@0x0, u32@0x4, u8@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_8817B998(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = ts4_if_call_seq_u32_lbl_88D45B38_8817F480((ts4_word)a0, (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(t1) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)t4;
    return a0;
}

/* Swing_DLL.xex 0x8817CD00: if_call_seq lbl_880DB358, u32@0x0, fn_8892AF80, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DB358_8817CD00(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB358;
    fn_8892AF80((ts4_word)(a0 + 16));
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817E430: if_call_seq u32@0x4, u32@0x0, u32@0x4, fn_8817F860, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off4_8817E430(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        fn_8817F860((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    }
    t14 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t14;
}

/* Swing_DLL.xex 0x8817E498: if_call_seq u32@0x8, u32@0x4, ts4_if_call_seq_u32_off0_88181618, u32@0x4, u32@0x4, fn_8817EB80 */
ts4_word ts4_if_call_seq_u32_off8_8817E498(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        t3 = ts4_if_call_seq_u32_off0_88181618((ts4_word)t2, (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 16);
        return t3;
    }
    t5 = fn_8817EB80((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x88182A90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CF0D8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182A90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CF0D8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182AE8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CF0D8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182AE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CF0D8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182B40: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D8B18 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182B40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D8B18((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182B98: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D8B18 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182B98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D8B18((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182BF0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DF740 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182BF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DF740((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182C48: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DF740 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182C48(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DF740((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182D90: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CED28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182D90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CED28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88182DE8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CED28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182DE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CED28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881830D0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CDDC0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881830D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CDDC0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183128: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CDDC0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183128(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CDDC0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183270: get u32@0x14, u32@0x10 */
ts4_word ts4_get_u32_off14_88183270(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88183280: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DDBC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183280(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)156, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DDBC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881832D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DDBC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881832D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)156, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DDBC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881833E0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_888CCF98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881833E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_888CCF98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183438: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_888CCF98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183438(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_888CCF98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183580: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880DB358_888DF440, lbl_880DB478, u32@0x68, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183580(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880DB358_888DF440((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB478;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183600: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880DB358_888DF440, lbl_880DB478, u32@0x68, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183600(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_lbl_880DB358_888DF440((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 104) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB478;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183680: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D7500 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183680(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)384, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D7500((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881836D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D7500 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881836D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)384, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D7500((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183730: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888F1658 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183730(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)152, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888F1658((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183788: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888F1658 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183788(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)152, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888F1658((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881837E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CBD50 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881837E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)528, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CBD50((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183838: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CBD50 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183838(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)528, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CBD50((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183890: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CB978 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183890(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CB978((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881838E8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CB978 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881838E8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CB978((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881839B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB648, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881839B8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB648;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183B90: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88901810, lbl_880DB6C0, u8@0x88, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183B90(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)140, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88901810((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 136) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB6C0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183C10: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88901810, lbl_880DB6C0, u8@0x88, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183C10(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)140, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88901810((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 136) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB6C0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183C90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CB0F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183C90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CB0F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183CE8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CB0F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183CE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CB0F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183E30: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888DE4C8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183E30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888DE4C8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183E88: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888DE4C8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183E88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888DE4C8((ts4_word)t2);
        return t3;
    }
    return 0;
}
