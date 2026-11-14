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
ts4_word fn_8818A4C8();
ts4_word fn_8818C868();
ts4_word fn_8818E2D8();
ts4_word fn_8818E7B0();
ts4_word fn_8818EA28();
ts4_word fn_8818F500();
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
ts4_word fn_88197260();
ts4_word fn_88197958();
ts4_word fn_88197E10();
ts4_word fn_88197F90();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_88199880();
ts4_word fn_88199C90();
ts4_word fn_8819A9D8();
ts4_word fn_8819B208();
ts4_word ts4_if_call_seq_fn_8887A350_881A64D8();
ts4_word fn_881A6A00();
ts4_word fn_881AC6A0();
ts4_word ts4_call_seq_fn_881AD7D8_881AC828();
ts4_word fn_881AD7D8();
ts4_word fn_881B3548();
ts4_word fn_881C38D0();
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
ts4_word fn_88822230();
ts4_word fn_88823D48();
ts4_word fn_88824CF8();
ts4_word fn_8882E368();
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

/* Swing_DLL.xex 0x8818FFE8: if_call_seq u32@0x0, fn_8818C868, fn_881992A8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8818FFE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
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
    if ((ts4_word)t1 != 0) {
        fn_8818C868((ts4_word)t1);
        t3 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x881A75A8: tailcall ts4_if_call_seq_fn_8887A350_881A64D8 */
ts4_word ts4_tailcall_fn_881A64D8_881A75A8(ts4_word a0)
{
    return ts4_if_call_seq_fn_8887A350_881A64D8((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x881A75B0: tailcall ts4_if_call_seq_fn_8887A350_881A64D8 */
ts4_word ts4_tailcall_fn_881A64D8_881A75B0(ts4_word a0)
{
    return ts4_if_call_seq_fn_8887A350_881A64D8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x881AC890: call_seq u32@0x0, u32@0x0, u8@0x4, u8@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_881AC890(ts4_word a0, ts4_word a1)
{
    ts4_word t17;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 16));
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 17));
    *(unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 18));
    *(unsigned char *)((char *)(ts4_word)(a0) + 19) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 19));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    ts4_call_seq_fn_881AD7D8_881AC828((ts4_word)(a0 + 36), (ts4_word)(a1 + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 96));
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
    t17 = *(ts4_word *)((char *)(ts4_word)(a1) + 108);
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)t17;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    return t17;
}

