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

extern char ts4_get_u32_lbl_88D493C8_88AFF0B0[];
extern char lbl_880D19F0[];
extern char lbl_880D6B70[];
extern char lbl_880DB834[];
extern char lbl_880DCF20[];
extern char lbl_880DD088[];
extern char lbl_880DD110[];
extern char lbl_880DD1D4[];
extern char lbl_880DD464[];
extern char lbl_880DD6D8[];
extern char lbl_880DEF10[];
extern char lbl_880DF220[];
extern char lbl_880DF260[];
extern char lbl_880DF40C[];
extern char lbl_880DF490[];
extern char lbl_880E174C[];
extern char lbl_880E3828[];
extern char lbl_880E3838[];
extern char lbl_880E39C8[];
extern char lbl_880F31D8[];
extern char lbl_880F6400[];
extern char lbl_880F7F38[];
extern char lbl_8814B440[];
extern char lbl_88C6A6E8[];
extern char lbl_88C6A720[];
extern char lbl_88C6A73C[];
extern char lbl_88C6A758[];
extern char lbl_88C6A7A4[];
extern char lbl_88C6A7C4[];
extern char lbl_88C6A7E0[];
extern char lbl_88C6A7FC[];
extern char lbl_88C6A818[];
extern char lbl_88C6A850[];
extern char lbl_88C6AC78[];
extern char lbl_88C6AC94[];
extern char lbl_88C6BE68[];
extern char lbl_88CACF08[];
extern char lbl_88D3E374[];
extern char lbl_88D3E378[];
extern char lbl_88D3E3A4[];
extern char lbl_88D3E3A8[];
extern char lbl_88D3E3BC[];
extern char lbl_88D3E414[];
extern char lbl_88D45984[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D493C8[];
extern char lbl_88D4D9BC[];
ts4_word KeTlsGetValue();
ts4_word fn_881519D0();
ts4_word fn_88155A40();
ts4_word fn_8817D318();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word ts4_if_get_RtlEnterCriticalSection_8818A4C8();
ts4_word fn_8818C868();
ts4_word fn_8818E2D8();
ts4_word fn_8818E7B0();
ts4_word fn_8818EA28();
ts4_word fn_8818F500();
ts4_word ts4_if_call_seq_u32_off0_8818FFE8();
ts4_word fn_88190200();
ts4_word fn_881903A8();
ts4_word fn_88190490();
ts4_word fn_881908F8();
ts4_word fn_881928F8();
ts4_word fn_88193438();
ts4_word fn_88193840();
ts4_word fn_88193C70();
ts4_word fn_88194F40();
ts4_word fn_88195368();
ts4_word fn_88195D00();
ts4_word ts4_if_call_seq_u32_off0_88197260();
ts4_word fn_88197958();
ts4_word fn_88197E10();
ts4_word fn_88197F90();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88199880();
ts4_word fn_88199C90();
ts4_word fn_8819A9D8();
ts4_word fn_8819B208();
ts4_word fn_881A6A00();
ts4_word fn_881AC6A0();
ts4_word ts4_if_call_seq_u32_off4_881AD7D8();
ts4_word fn_881B3548();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word fn_8841A590();
ts4_word fn_88474120();
ts4_word fn_88562DC0();
ts4_word fn_885630C0();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_88563470();
ts4_word fn_885647D0();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word fn_88566048();
ts4_word fn_88566750();
ts4_word fn_88566A68();
ts4_word fn_88566FE8();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857A1E0();
ts4_word fn_8857BE58();
ts4_word ts4_query_size_8857BF40();
ts4_word fn_8857C040();
ts4_word fn_8857C1B8();
ts4_word fn_8857C1F8();
ts4_word fn_8860D250();
ts4_word fn_88613268();
ts4_word fn_88613350();
ts4_word fn_88613570();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88622888();
ts4_word fn_88631048();
ts4_word fn_88636DC8();
ts4_word fn_88638FC8();
ts4_word fn_88803D00();
ts4_word ts4_call_seq_fn_88804B18_88804B88();
ts4_word lib3_lua_touserdata_88822230();
ts4_word fn_88823D48();
ts4_word lib3_lua_load_buffer_88824CF8();
ts4_word lib3_aux_do_8882E368();
ts4_word fn_8883D798();
ts4_word fn_888417A8();
ts4_word ts4_call_seq_fn_88617D88_88855F10();
ts4_word fn_88878F30();
ts4_word fn_8887A350();
ts4_word fn_8887CAD0();
ts4_word fn_8887DBF8();
ts4_word fn_8887EE60();
ts4_word fn_888860A0();
ts4_word fn_88886608();
ts4_word ts4_call_seq_fn_88617D88_88887AD8();
ts4_word fn_88888C80();
ts4_word fn_88889240();
ts4_word fn_8888D278();
ts4_word ts4_call_seq_fn_88617D88_888C7980();
ts4_word ts4_call_seq_fn_88617D88_888C7F30();
ts4_word fn_888C80A0();
ts4_word fn_888C9588();
ts4_word fn_888C9618();
ts4_word ts4_call_seq_fn_88617D88_888CA4E0();
ts4_word ts4_call_seq_fn_88617D88_888CAA40();
ts4_word fn_888CAB28();
ts4_word fn_888CAD50();
ts4_word fn_888CAFE8();
ts4_word fn_888D03A0();
ts4_word fn_888DDE20();
ts4_word fn_888DE118();
ts4_word fn_888DE300();
ts4_word fn_888E1EE0();
ts4_word fn_888FD948();
ts4_word fn_8892AF80();
ts4_word fn_8892AFF0();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88183EE0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAFE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183EE0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAFE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183F38: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAFE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183F38(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAFE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184080: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAD50 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184080(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAD50((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881840D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAD50 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881840D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAD50((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184130: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8817D318 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184130(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)192, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8817D318((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184188: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8817D318 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184188(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)192, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8817D318((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881841E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAB28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881841E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)784, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAB28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184238: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CAB28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184238(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)784, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CAB28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184340: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CAA40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184340(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CAA40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184398: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CAA40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184398(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CAA40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881845B0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE300 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881845B0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE300((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184608: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE300 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184608(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE300((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184660: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888FD948 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184660(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)352, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888FD948((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881846B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888FD948 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881846B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)352, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888FD948((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184800: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CA4E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184800(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CA4E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184858: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888CA4E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184858(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888CA4E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881848B0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE118 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881848B0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE118((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184908: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE118 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184908(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE118((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184A10: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C9618 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184A10(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C9618((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184A68: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C9618 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184A68(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C9618((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184AC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C9588 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184AC0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C9588((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184B18: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C9588 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184B18(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C9588((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184C20: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DDE20 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184C20(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1312, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DDE20((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184C78: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DDE20 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184C78(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1312, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DDE20((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184CD0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888E1EE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184CD0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888E1EE0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184D28: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888E1EE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184D28(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888E1EE0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184D80: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D03A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184D80(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D03A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184DD8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888D03A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184DD8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888D03A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184E30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C80A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184E30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C80A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184E88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888C80A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184E88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888C80A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184FD0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888C7F30 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184FD0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888C7F30((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88185028: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888C7F30 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88185028(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888C7F30((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88185170: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888C7980 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88185170(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888C7980((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881851C8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_888C7980 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881851C8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_888C7980((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88185348: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB834, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88185348(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB834;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88185EB8: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88185EB8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 45) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 45));
    *(unsigned char *)((char *)(ts4_word)(a0) + 46) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 46));
    *(unsigned char *)((char *)(ts4_word)(a0) + 47) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 47));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    return;
}

/* Swing_DLL.xex 0x88185F60: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_88185F60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88187638: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88187638(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 2)) << 4), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88187DC8: set u8@0x4, u32@0x0, u8@0x5, u8@0x6, u8@0x7, u8@0x8 */
void ts4_set_u8_off4_88187DC8(ts4_word a0)
{
    float t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    t1 = *(float *)lbl_8814B440;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 10) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 11) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 61) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 62) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 63) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 68) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 69) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 70) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 71) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 76) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 77) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 86) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 104) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88188478: if_call_seq u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x8, fn_88155A40 */
ts4_word ts4_if_call_seq_u32_off0_88188478(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
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

/* Swing_DLL.xex 0x881884E0: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881884E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 4), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8818A0E8: get u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_get_u32_lbl_88CACF08_8818A0E8(void)
{
    return KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
}

/* Swing_DLL.xex 0x8818A970: addr lbl_88C6AC94 */
ts4_word ts4_addr_lbl_88C6AC94_8818A970(void)
{
    return (ts4_word)lbl_88C6AC94;
}

/* Swing_DLL.xex 0x8818A980: addr lbl_88C6AC78 */
ts4_word ts4_addr_lbl_88C6AC78_8818A980(void)
{
    return (ts4_word)lbl_88C6AC78;
}

/* Swing_DLL.xex 0x8818AAB8: get u8@0xc */
ts4_word ts4_get_u8_offc_8818AAB8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x8818AAC0: addr lbl_88C6A850 */
ts4_word ts4_addr_lbl_88C6A850_8818AAC0(void)
{
    return (ts4_word)lbl_88C6A850;
}

/* Swing_DLL.xex 0x8818AD90: if_get u32@0x34, u32@0x0, u32@0x18, fn_88193438 */
ts4_word ts4_if_get_u32_off34_8818AD90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    return fn_88193438((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818AE68: if_get u32@0x34, u32@0x0, u32@0x14, fn_88193840 */
ts4_word ts4_if_get_u32_off34_8818AE68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    return fn_88193840((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B170: addr lbl_88C6A818 */
ts4_word ts4_addr_lbl_88C6A818_8818B170(void)
{
    return (ts4_word)lbl_88C6A818;
}

/* Swing_DLL.xex 0x8818B3A0: if_get u32@0x18, u32@0x0, u32@0x64, vcall, u32@0x14, u32@0x1c */
ts4_word ts4_if_get_u32_off18_8818B3A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p5 = (ts4_word)a0;
    if ((ts4_word)a1 > (ts4_word)t1) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 100))))((ts4_word)a0);
        p5 = (ts4_word)t4;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    if ((ts4_word)a1 < (ts4_word)t6) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    }
    return p5;
}

/* Swing_DLL.xex 0x8818B640: addr lbl_88C6A7FC */
ts4_word ts4_addr_lbl_88C6A7FC_8818B640(void)
{
    return (ts4_word)lbl_88C6A7FC;
}

/* Swing_DLL.xex 0x8818B780: get u32@0x10, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off10_8818B780(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B798: get u32@0x10, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off10_8818B798(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B7C8: get u32@0x10, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off10_8818B7C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B7E0: get u32@0x10, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off10_8818B7E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B7F8: get u32@0x10, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off10_8818B7F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B810: get u32@0x10, u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off10_8818B810(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B868: get u32@0x10, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off10_8818B868(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B880: get u32@0x10, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off10_8818B880(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8818B938: get u32@0x10, u32@0x0, u32@0x40, vcall */
ts4_word ts4_get_u32_off10_8818B938(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818B978: get u32@0x10, u32@0x0, u32@0x44, vcall */
ts4_word ts4_get_u32_off10_8818B978(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 68))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818B9B8: get u32@0x10, u32@0x0, u32@0x48, vcall */
ts4_word ts4_get_u32_off10_8818B9B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818B9F8: get u32@0x10, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_get_u32_off10_8818B9F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BA38: get u32@0x10, u32@0x0, u32@0x50, vcall */
ts4_word ts4_get_u32_off10_8818BA38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BA78: get u32@0x10, u32@0x0, u32@0x54, vcall */
ts4_word ts4_get_u32_off10_8818BA78(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 84))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BAB8: get u32@0x10, u32@0x0, u32@0x58, vcall */
ts4_word ts4_get_u32_off10_8818BAB8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 88))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BAF8: get u32@0x10, u32@0x0, u32@0x5c, vcall */
ts4_word ts4_get_u32_off10_8818BAF8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 92))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BB38: get u32@0x10, u32@0x0, u32@0x60, vcall */
ts4_word ts4_get_u32_off10_8818BB38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 96))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8818BB78: addr lbl_88C6A7E0 */
ts4_word ts4_addr_lbl_88C6A7E0_8818BB78(void)
{
    return (ts4_word)lbl_88C6A7E0;
}

/* Swing_DLL.xex 0x8818BC98: if_call_seq u32@0x10, lbl_880DD110, u32@0x0, fn_88566FE8, u32@0x10, lbl_880DD088 */
ts4_word ts4_if_call_seq_u32_off10_8818BC98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD110;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88566FE8((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return p3;
}

/* Swing_DLL.xex 0x8818BED8: get u32@0x10, fn_88566048 */
ts4_word ts4_get_u32_off10_8818BED8(ts4_word a0, ts4_word a1)
{
    return fn_88566048((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Swing_DLL.xex 0x8818C4A8: if_call_seq u32@0x10, fn_88566750, u32@0x10, fn_88566A68 */
ts4_word ts4_if_call_seq_u32_off10_8818C4A8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = fn_88566750((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    if ((int)t2 != 0) {
        return -1;
    }
    t4 = fn_88566A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    return t4;
}

/* Swing_DLL.xex 0x8818C500: if_call_seq u32@0x10, fn_88566A68 */
ts4_word ts4_if_call_seq_u32_off10_8818C500(ts4_word a0)
{
    ts4_word p3;
    ts4_word t2;

    t2 = fn_88566A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    p3 = (ts4_word)t2;
    if ((int)t2 == -1) {
        p3 = (ts4_word)-1;
    }
    return p3;
}

/* Swing_DLL.xex 0x8818C548: if_call_seq u32@0x10, fn_88566FE8, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off10_8818C548(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88566FE8((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x8818E9C0: if_call_seq fn_8818EA28, u32@0x0, u32@0x4c, u32@0x8 */
ts4_word ts4_if_call_seq_fn_8818EA28_8818E9C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_8818EA28((ts4_word)a0, (ts4_word)a1);
    if ((int)t1 == -1) {
        return 0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 8))) + (t1 << 2))) + t3);
}

/* Swing_DLL.xex 0x8818EAB8: if_call_seq u32@0x4, fn_881992A8, u32@0x4, u32@0x8, u32@0xc, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4_8818EAB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p3 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x8818F480: if_call_seq lbl_880DD1D4, u32@0x0, u32@lbl_88D3E378, fn_88198CE0, fn_8818F500, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880DD1D4_8818F480(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD1D4;
    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E378));
    fn_8818F500((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t4 != 0) {
        fn_88190200((ts4_word)t4);
        fn_881992A8((ts4_word)0, (ts4_word)t4);
    }
    t8 = fn_88198CE0((ts4_word)t2);
    return t8;
}

/* Swing_DLL.xex 0x8818FEC0: if_call_seq u32@0x0, u32@0x0, u32@-0xc, u32@-0xc, fn_885630C0 */
ts4_word ts4_if_call_seq_u32_off0_8818FEC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + -12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + -12);
    if ((int)t3 != (int)t4) {
        return 0;
    }
    t5 = fn_885630C0((ts4_word)t1, (ts4_word)t2, (ts4_word)t3);
    return (t5 == 0);
}

/* Swing_DLL.xex 0x8818FF18: if_call_seq ts4_if_call_seq_u32_off0_8818FFE8, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8818FFE8_8818FF18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        ts4_if_call_seq_u32_off0_8818FFE8((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p4 = (ts4_word)a0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88190128: if_call_seq fn_881903A8, fn_88190490 */
ts4_word ts4_if_call_seq_fn_881903A8_88190128(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word loc58[1];
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_881903A8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = loc50[0];
        t3 = loc54[0];
        t4 = fn_88190490((ts4_word)a0, (ts4_word)a1, (ts4_word)t3, (ts4_word)t2);
        p5 = (ts4_word)t4;
    }
    return (p5 + 4);
}

/* Swing_DLL.xex 0x88190848: addr lbl_88C6A7C4 */
ts4_word ts4_addr_lbl_88C6A7C4_88190848(void)
{
    return (ts4_word)lbl_88C6A7C4;
}

/* Swing_DLL.xex 0x88190858: if_call_seq fn_88199068, fn_881908F8 */
ts4_word ts4_if_call_seq_fn_88199068_88190858(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)156, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881908F8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881908E8: get u32@lbl_88D3E374, fn_881992A8 */
ts4_word ts4_get_u32_lbl_88D3E374_881908E8(void)
{
    return fn_881992A8((ts4_word)(*(ts4_word *)lbl_88D3E374));
}

/* Swing_DLL.xex 0x88191858: if_call_seq u32@0x10, fn_8818E7B0, u32@0x10, u32@0x20, u32@0x14, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off10_88191858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8818E7B0((ts4_word)t1, (ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)-1;
    p6 = (ts4_word)p3;
    if ((ts4_word)t4 != 0) {
        t5 = fn_881992A8((ts4_word)0, (ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x88191A60: if_call_seq u32@0x0, u32@0x10, fn_8818E2D8, ts4_counted_ptr_assign_881C38D0, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_88191A60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((ts4_word)t1 != 0) {
        t2 = fn_8818E2D8((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)a1);
        ts4_counted_ptr_assign_881C38D0((ts4_word)a0, (ts4_word)t2);
        t4 = loc50[0];
        if ((ts4_word)t4 != 0) {
            ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
            loc50[0] = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)-1;
    if ((ts4_word)t8 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t8);
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88192770: set u32@0x0 */
void ts4_set_u32_off0_88192770(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88192780: get u32@0x10, u32@0x3c, u32@0x0, u32@0x60, vcall */
ts4_word ts4_get_u32_off10_88192780(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 16))) + 60);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 96))))((ts4_word)a0, (ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88192840: get u32@0x0, vcall */
ts4_word ts4_get_u32_off0_88192840(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 0))))((ts4_word)a1);
    return (t2 & 0xff);
}

/* Swing_DLL.xex 0x88192870: addr lbl_88C6A7A4 */
ts4_word ts4_addr_lbl_88C6A7A4_88192870(void)
{
    return (ts4_word)lbl_88C6A7A4;
}

/* Swing_DLL.xex 0x88192880: if_call_seq fn_88199068, fn_881928F8 */
ts4_word ts4_if_call_seq_fn_88199068_88192880(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)52, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881928F8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88193A98: if_call_seq u32@0x8, u8@0x30, u32@lbl_88D3E3A8, fn_88195368, fn_88195D00 */
ts4_word ts4_if_call_seq_u32_off8_88193A98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 48) = (unsigned char)0;
    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88195D00((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3);
    return a0;
}

/* Swing_DLL.xex 0x88193CF8: if_call_seq fn_88193C70, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, u32@0x4, ts4_if_get_RtlEnterCriticalSection_8818A4C8 */
ts4_word ts4_if_call_seq_fn_88193C70_88193CF8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88193C70();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = *(ts4_word *)lbl_88D3E3A8;
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 == 0) {
            fn_88195368((ts4_word)t1);
            p5 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
        }
        ts4_if_get_RtlEnterCriticalSection_8818A4C8((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 4)) + 68), (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88195200: call_seq u32@lbl_88D3E3A4, fn_88198CE0, u32@0x14, fn_8857C1F8, fn_88194F40, fn_88198CE0 */
ts4_word ts4_call_seq_u32_lbl_88D3E3A4_88195200(ts4_word a0)
{
    ts4_word t2;
    ts4_word t6;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    fn_88194F40((ts4_word)a0, (ts4_word)1);
    t6 = fn_88198CE0((ts4_word)t2);
    return t6;
}

/* Swing_DLL.xex 0x88195448: if_call_seq lbl_880DD464, u32@0x0, ts4_if_call_seq_u32_off0_88197260, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DD464_88195448(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD464;
    ts4_if_call_seq_u32_off0_88197260((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88196CA8: if_call_seq u32@lbl_88D3E3A4, fn_88198CE0, u32@0x10, fn_8857BE58, u32@0x18, fn_88198CE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A4_88196CA8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t4 = fn_8857BE58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    if ((int)t4 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)1;
    }
    t5 = fn_88198CE0((ts4_word)t2);
    return t5;
}

/* Swing_DLL.xex 0x88196D08: call_seq u32@lbl_88D3E3A4, fn_88198CE0, u32@0x10, ts4_query_size_8857BF40, fn_88198CE0 */
ts4_word ts4_call_seq_u32_lbl_88D3E3A4_88196D08(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t4 = ts4_query_size_8857BF40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)0);
    fn_88198CE0((ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x881975B0: get u32@0x4, fn_8857C1B8 */
ts4_word ts4_get_u32_off4_881975B0(ts4_word a0)
{
    return fn_8857C1B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x881975B8: call_seq u32@0x4, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_call_seq_u32_off4_881975B8(ts4_word a0)
{
    ts4_word t2;

    t2 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return (t2 == 0);
}

/* Swing_DLL.xex 0x881975E8: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_881975E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)-1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88197600: get u32@0x4, fn_8857C040 */
ts4_word ts4_get_u32_off4_88197600(ts4_word a0)
{
    return fn_8857C040((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x88197608: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_88197608(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)1, (ts4_word)0);
}

/* Swing_DLL.xex 0x88197620: if_call_seq u32@0x4, lbl_880DCF20, u32@0x0, fn_8857A1E0, u32@0x4, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_u32_off4_88197620(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCF20;
    if ((ts4_word)t1 != 0) {
        fn_8857A1E0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88197690: if_call_seq u32@0x4, lbl_880DCF20, u32@0x0, fn_8857A1E0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_88197690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCF20;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8857A1E0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x88197838: get u32@0x88, u32@0x8c */
ts4_word ts4_get_u32_off88_88197838(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 140)));
}

/* Swing_DLL.xex 0x88197848: get u32@0x0, u32@0x28, vcall, u32@0x90 */
ts4_word ts4_get_u32_off0_88197848(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 144)) - t3);
}

/* Swing_DLL.xex 0x88197898: get u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_88197898(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x881978C0: get u32@0x98, u32@0x98 */
ts4_word ts4_get_u32_off98_881978C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x881978D0: addr lbl_88C6A758 */
ts4_word ts4_addr_lbl_88C6A758_881978D0(void)
{
    return (ts4_word)lbl_88C6A758;
}

/* Swing_DLL.xex 0x881978E0: if_call_seq fn_88199068, fn_88197958 */
ts4_word ts4_if_call_seq_fn_88199068_881978E0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)196, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_88197958((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88197B80: if_call_seq u32@0x7c, u32@0x70, u32@0x9c, u32@0x90, ts4_if_call_seq_u32_lbl_88D45B38_88199880, u32@0x7c */
ts4_word ts4_if_call_seq_u32_off7c_88197B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    p6 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        t5 = ts4_if_call_seq_u32_lbl_88D45B38_88199880((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144)), (ts4_word)t3, (ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88197E00: addr lbl_88C6A73C */
ts4_word ts4_addr_lbl_88C6A73C_88197E00(void)
{
    return (ts4_word)lbl_88C6A73C;
}

/* Swing_DLL.xex 0x88197EA0: if_call_seq lbl_880DD088, u32@0x0, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880DD088_88197EA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88197EF0: set u32@0x90 */
void ts4_set_u32_off90_88197EF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88197EF8: get u32@0xbc */
ts4_word ts4_get_u32_offbc_88197EF8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 188)) != 0);
}

/* Swing_DLL.xex 0x88197F08: addr lbl_88C6A720 */
ts4_word ts4_addr_lbl_88C6A720_88197F08(void)
{
    return (ts4_word)lbl_88C6A720;
}

/* Swing_DLL.xex 0x88197F18: if_call_seq fn_88199068, fn_88197F90 */
ts4_word ts4_if_call_seq_fn_88199068_88197F18(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)192, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_88197F90((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881981E0: if_call_seq u32@0x7c, u32@0x70, u32@0xbc, u32@0x8c, ts4_if_call_seq_u32_lbl_88D45B38_88199880, u32@0x7c */
ts4_word ts4_if_call_seq_u32_off7c_881981E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    p6 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
        t5 = ts4_if_call_seq_u32_lbl_88D45B38_88199880((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 140)), (ts4_word)t3, (ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x881988B8: get u32@0x94, u32@0x94 */
ts4_word ts4_get_u32_off94_881988B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x881993D8: get u32@0x7c, u32@0x7c */
ts4_word ts4_get_u32_off7c_881993D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x881993E8: addr lbl_88C6A6E8 */
ts4_word ts4_addr_lbl_88C6A6E8_881993E8(void)
{
    return (ts4_word)lbl_88C6A6E8;
}

/* Swing_DLL.xex 0x881993F8: if_call_seq fn_88199068, fn_88197E10, u32@0x7c, lbl_880DD6D8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881993F8(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)132, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_88197E10((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 124) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880DD6D8;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x88199470: if_call_seq fn_88197E10, lbl_880DD6D8, u32@0x7c, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88197E10_88199470(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_88197E10((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD6D8;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88199B20: if_call_seq u32@0x1c, fn_88198CE0, fn_88199068, fn_88198CE0, u32@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off1c_88199B20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t3 = fn_88199068((ts4_word)0, (ts4_word)(((int)(a1 + 1) * (int)a2) + 16), (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t3 == 0) {
        fn_88198CE0((ts4_word)t2);
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
    fn_88198CE0((ts4_word)t2);
    return t3;
}

/* Swing_DLL.xex 0x88199BB0: if_call_seq u32@0x1c, fn_88198CE0, fn_881992A8, fn_88198CE0 */
ts4_word ts4_if_call_seq_u32_off1c_88199BB0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t5;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    if ((ts4_word)a1 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a1);
    }
    t5 = fn_88198CE0((ts4_word)t2);
    return t5;
}

/* Swing_DLL.xex 0x88199D60: if_get u32@lbl_88D45984, fn_88199C90, u32@lbl_88D3E3BC, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_lbl_88D45984_88199D60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45984;
    if ((int)t1 == 0) {
        fn_88199C90();
    }
    t4 = *(ts4_word *)lbl_88D3E3BC;
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t7 + 16);
    return a0;
}

/* Swing_DLL.xex 0x88199E28: if_call_seq u32@lbl_88D4D9BC, u32@lbl_88D4D9BC, ts4_get_u32_lbl_88D493C8_88AFF0B0, fn_88563470, lbl_88D493C8, lbl_88D493C8 */
ts4_word ts4_if_call_seq_u32_lbl_88D4D9BC_88199E28(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D4D9BC;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D4D9BC = (ts4_word)(t1 | 1);
        fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88D493C8_88AFF0B0);
        return (ts4_word)lbl_88D493C8;
    }
    return (ts4_word)lbl_88D493C8;
}

/* Swing_DLL.xex 0x8819A098: if_get u32@lbl_88D3E414, fn_8819A9D8 */
ts4_word ts4_if_get_u32_lbl_88D3E414_8819A098(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D3E414;
    if ((ts4_word)t1 != 0) {
        return t1;
    }
    return fn_8819A9D8((ts4_word)t1);
}

/* Swing_DLL.xex 0x8819AB68: get fn_881519D0, u32@0x0, u32@0x10, vcall, u32@0x0, fn_8819B208 */
ts4_word ts4_get_fn_881519D0_8819AB68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_881519D0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t4 + 16);
    fn_8819B208((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x8819AFB0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_8819AFB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1);
    return 0;
}

/* Swing_DLL.xex 0x8819B9A8: if_call_seq u32@0x0, fn_885647D0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8819B9A8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = fn_885647D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)((signed char)a1));
    if ((ts4_word)t2 == 0) {
        return -1;
    }
    return (t2 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8819F5A8: if_get u32@0x18, u32@0x10, u32@0x8, u32@0x0, u8@0x0, u32@0x0 */
void ts4_if_get_u32_off18_8819F5A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t2 < (int)t1) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 0) = (unsigned char)a1;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0)) + 1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 1);
    return;
}

/* Swing_DLL.xex 0x881A1D78: if_get u32@0x18, u32@0x10, u32@0x8, u32@0x0, u16@0x0, u32@0x0 */
void ts4_if_get_u32_off18_881A1D78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t2 < (int)t1) {
        *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 0) = (unsigned short)a1;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0)) + 2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 1);
    return;
}

/* Swing_DLL.xex 0x881A22C8: get u32@0x4, u32@0x58, fn_8857C1F8, u32@0x4, u32@0x50, u32@0x0 */
ts4_word ts4_get_u32_off4_881A22C8(ts4_word a0)
{
    fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 88)));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80) = (ts4_word)2;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80) = (ts4_word)3;
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x881A4DA0: if_call_seq lbl_880DEF10, u32@0x0, fn_881A6A00, lbl_880F6400, u32@0x0, fn_88638FC8 */
ts4_word ts4_if_call_seq_lbl_880DEF10_881A4DA0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DEF10;
    fn_881A6A00((ts4_word)(a0 + 188));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F6400;
    fn_88638FC8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A5160: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8888D278 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5160(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)208, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8888D278((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A51B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8888D278 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A51B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)208, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8888D278((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5388: if_get u32@lbl_88D45B1C, u32@0x2cc, lbl_88C6BE68, u32@0x20, u32@0x248 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_881A5388(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 716);
    if ((int)t2 == 0) {
        p3 = (ts4_word)(ts4_word)lbl_88C6BE68;
    } else {
        p3 = (ts4_word)(t2 + 10992);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(p3) + 32);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t4))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 584)), (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x881A53C8: if_call_seq lbl_880DF260, lbl_880D19F0, u32@0x0, u32@0x14f4, fn_88631048, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DF260_881A53C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF260;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5364) = (ts4_word)(ts4_word)lbl_880D19F0;
    fn_88631048();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A5808: if_call_seq lbl_880D6B70, lbl_880F7F38, u32@0x20, u32@0x0, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D6B70_881A5808(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7F38;
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A5A90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88887AD8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5A90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)632, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88887AD8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5AE8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88887AD8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5AE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)632, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88887AD8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5B40: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88889240 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5B40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)5396, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88889240((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5B98: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88889240 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5B98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)5396, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88889240((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5BF0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88888C80 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5BF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88888C80((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5C48: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88888C80 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5C48(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88888C80((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5D50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DF40C, u32@0x3c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5D50(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DF40C;
        *(unsigned char *)((char *)(ts4_word)(t2) + 64) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5DD8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DF40C, u32@0x3c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5DD8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DF40C;
        *(unsigned char *)((char *)(ts4_word)(t2) + 64) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5E60: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88886608 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5E60(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88886608((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5EB8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88886608 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5EB8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88886608((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5F10: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636DC8, lbl_880DF490, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5F10(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88636DC8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DF490;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A5F88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636DC8, lbl_880DF490, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5F88(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88636DC8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DF490;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A6200: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A6200(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)624, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t4;
        *(unsigned char *)((char *)(ts4_word)(t2) + 16) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 20) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 21) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 540) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 544) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 548) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 552) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 556) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 560) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 564) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 568) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 572) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 576) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 580) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 28) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DF220;
        *(ts4_word *)((char *)(ts4_word)(t2) + 584) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(t2) + 616) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(t2) + 588) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 592) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 596) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 620) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 608) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 612) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A64D8: if_call_seq fn_8887A350, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8887A350_881A64D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8887A350();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A6B90: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A6B90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 6), (ts4_word)16, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881A7398: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887EE60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A7398(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887EE60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A73F0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887EE60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A73F0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887EE60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A7448: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887CAD0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A7448(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887CAD0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A74A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887CAD0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A74A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887CAD0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A74F8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887DBF8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A74F8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887DBF8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A7550: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8887DBF8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A7550(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8887DBF8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A75B8: get fn_88474120, u32@0xd0, u32@0x44, vcall */
ts4_word ts4_get_fn_88474120_881A75B8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88474120((ts4_word)a0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 68))))((ts4_word)(a0 + 208), (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x881A7820: get fn_88474120, u32@0xd0, u32@0x40, vcall */
ts4_word ts4_get_fn_88474120_881A7820(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88474120((ts4_word)a0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 64))))((ts4_word)(a0 + 208), (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x881A78E8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88878F30 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A78E8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88878F30((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A7940: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88878F30 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A7940(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88878F30((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881A9828: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A9828(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 1), (ts4_word)2, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881A9890: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A9890(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 3), (ts4_word)2, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881AA538: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_881AA538(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    return;
}

/* Swing_DLL.xex 0x881AB7C0: if_call_seq u32@0x0, u32@0x4, u32@0x8, fn_881AC6A0, u32@0x0, fn_88562DC0 */
ts4_word ts4_if_call_seq_u32_off0_881AB7C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_881AC6A0((ts4_word)a0, (ts4_word)(((int)(a2 - a1) >> 1) + 1));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)t2;
    if ((ts4_word)a2 != (ts4_word)a1) {
        t3 = fn_88562DC0((ts4_word)t2, (ts4_word)a1, (ts4_word)(a2 - a1));
        p4 = (ts4_word)(t3 + (a2 - a1));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p4;
    *(unsigned short *)((char *)(ts4_word)(p4) + 0) = (unsigned short)0;
    return a0;
}

/* Swing_DLL.xex 0x881AC828: call_seq ts4_if_call_seq_u32_off4_881AD7D8, ts4_if_call_seq_u32_off4_881AD7D8, ts4_if_call_seq_u32_off4_881AD7D8, ts4_if_call_seq_u32_off4_881AD7D8, ts4_if_call_seq_u32_off4_881AD7D8 */
ts4_word ts4_call_seq_fn_881AD7D8_881AC828(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    ts4_if_call_seq_u32_off4_881AD7D8((ts4_word)a0, (ts4_word)a1);
    ts4_if_call_seq_u32_off4_881AD7D8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    ts4_if_call_seq_u32_off4_881AD7D8((ts4_word)(a0 + 24), (ts4_word)(a1 + 24));
    ts4_if_call_seq_u32_off4_881AD7D8((ts4_word)(a0 + 36), (ts4_word)(a1 + 36));
    t5 = ts4_if_call_seq_u32_off4_881AD7D8((ts4_word)(a0 + 48), (ts4_word)(a1 + 48));
    return t5;
}

/* Swing_DLL.xex 0x881AE0D8: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AE0D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 3)) << 3), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881AE608: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88622888 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AE608(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)11764, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88622888((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF1F8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88855F10 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF1F8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88855F10((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF250: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88855F10 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF250(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88855F10((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF2A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8883D798 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF2A8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8883D798((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF300: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8883D798 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF300(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8883D798((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF358: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888417A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF358(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888417A8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF3B0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888417A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF3B0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888417A8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF5A8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E174C, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF5A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E174C;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF610: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E174C, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF610(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E174C;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B1818: get lib3_lua_touserdata_88822230, u32@0x6c, u32@0x0, vcall */
ts4_word ts4_get_fn_88822230_881B1818(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = lib3_lua_touserdata_88822230((ts4_word)a0, (ts4_word)-10002);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 0))))((ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x881B1C90: call_seq u32@0x0, fn_88823D48, u32@0x0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_881B1C90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;

    fn_88823D48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)(a2 & 0xff));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x881B2C80: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88803D00 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2C80(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88803D00((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B2CD8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88803D00 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2CD8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88803D00((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B2D30: get lib3_lua_touserdata_88822230, fn_881B3548, u32@0x0, u32@0x6c, vcall */
ts4_word ts4_get_fn_88822230_881B2D30(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = lib3_lua_touserdata_88822230((ts4_word)a0, (ts4_word)-10002);
    t2 = fn_881B3548((ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))(t3))((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)));
    return t5;
}

/* Swing_DLL.xex 0x881B2D88: get lib3_lua_touserdata_88822230, u32@0x4, u32@0x6c, u32@0x0, vcall */
ts4_word ts4_get_fn_88822230_881B2D88(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = lib3_lua_touserdata_88822230((ts4_word)a0, (ts4_word)-10002);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))(t2))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t3);
    return t5;
}

/* Swing_DLL.xex 0x881B2DE0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3828, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2DE0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3828;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B2E58: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3828, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2E58(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3828;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B2ED0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880E3838, u8@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2ED0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 8) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3838;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B2F50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880E3838, u8@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B2F50(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 8) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3838;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3108: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88804B18_88804B88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3108(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88804B18_88804B88((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3160: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88804B18_88804B88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3160(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88804B18_88804B88((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3778: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_881B3778(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word loc50[1];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t22;
    ts4_word t23;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)0);
    t6 = loc50[0];
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 20))))((ts4_word)t6);
    t10 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t10 == 0) {
        t11 = ts4_crt_nh_malloc_88565258((ts4_word)t9);
        p13 = (ts4_word)t11;
    } else {
        t12 = fn_88613350((ts4_word)t10, (ts4_word)t9);
        p13 = (ts4_word)t12;
    }
    t14 = loc50[0];
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 4))))((ts4_word)t14, (ts4_word)p13, (ts4_word)t9);
    loc58[1] = (ts4_word)t9;
    loc58[0] = (ts4_word)p13;
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t19 = lib3_lua_load_buffer_88824CF8((ts4_word)t18, (ts4_word)(ts4_word)&loc58[0], (ts4_word)a1);
    t20 = lib3_aux_do_8882E368((ts4_word)t18, (ts4_word)t19);
    fn_888860A0((ts4_word)p13);
    t22 = loc50[0];
    t23 = *(ts4_word *)((char *)(ts4_word)(t22) + 4);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 88))))((ts4_word)t23, (ts4_word)(ts4_word)&loc50[0]);
    return t20;
}

/* Swing_DLL.xex 0x881B3970: if_call_seq lbl_880E39C8, u32@0x0, fn_8892AF80, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E39C8_881B3970(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E39C8;
    fn_8892AF80((ts4_word)(a0 + 28));
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B3C88: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_881B3C88(ts4_word a0)
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
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 48))))((ts4_word)t1, (ts4_word)t3, (ts4_word)7);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t5 & 0xff) == 0) {
        loc50[0] = (ts4_word)(ts4_word)lbl_880F31D8;
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 56))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t8, (ts4_word)(ts4_word)lbl_880F31D8);
        t11 = loc54[0];
        return t11;
    }
    t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)4);
    return (*(ts4_word *)((char *)(ts4_word)(t14) + 0));
}

/* Swing_DLL.xex 0x881B3E30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880E39C8, u32@0x0, fn_8892AFF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3E30(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E39C8;
        fn_8892AFF0((ts4_word)(t2 + 28));
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3EB0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880E39C8, u32@0x0, fn_8892AFF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3EB0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E39C8;
        fn_8892AFF0((ts4_word)(t2 + 28));
        return t2;
    }
    return 0;
}
