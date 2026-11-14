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

extern char fn_885CCFF8[];
extern char ts4_addr_lbl_880D19F0_88AFF3E0[];
extern char ts4_addr_lbl_880D19F0_88AFF3F8[];
extern char ts4_addr_lbl_880D19F0_88AFF410[];
extern char ts4_addr_lbl_880D19F0_88AFF428[];
extern char g_ts4_script_constants[];
extern char lbl_8803A308[];
extern char lbl_880832C4[];
extern char lbl_8808338C[];
extern char lbl_88084A14[];
extern char lbl_88087F04[];
extern char lbl_880C070C[];
extern char lbl_880C1320[];
extern char lbl_880C88DC[];
extern char lbl_880C9DCC[];
extern char lbl_880D19F0[];
extern char lbl_880D2EFC[];
extern char lbl_880D2F00[];
extern char lbl_880D2F08[];
extern char lbl_880D4AFC[];
extern char lbl_880D4B08[];
extern char lbl_880D5864[];
extern char lbl_880D5870[];
extern char lbl_880D6B70[];
extern char lbl_880E7620[];
extern char lbl_880F20E8[];
extern char lbl_880F51C4[];
extern char lbl_880F5848[];
extern char lbl_880F5890[];
extern char lbl_880F5FEC[];
extern char lbl_880F604C[];
extern char lbl_880F61D0[];
extern char lbl_880F62E4[];
extern char lbl_880F63C0[];
extern char lbl_880F78D4[];
extern char lbl_880F7AE0[];
extern char lbl_880F7C94[];
extern char lbl_880F7D90[];
extern char lbl_880F7DEC[];
extern char lbl_880F7E00[];
extern char lbl_880F7E14[];
extern char lbl_880F7EE4[];
extern char lbl_880F7F90[];
extern char lbl_880F8928[];
extern char lbl_880F8B6C[];
extern char lbl_880F9018[];
extern char lbl_880F9574[];
extern char lbl_8814B440[];
extern char lbl_8814B45C[];
extern char lbl_8814B910[];
extern char lbl_88CACF08[];
extern char lbl_88D3EB60[];
extern char lbl_88D41F80[];
extern char lbl_88D45290[];
extern char lbl_88D452A0[];
extern char lbl_88D45A10[];
extern char lbl_88D45B05[];
extern char lbl_88D45B06[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B24[];
extern char lbl_88D45B28[];
extern char lbl_88D45B38[];
extern char lbl_88D45B3C[];
extern char lbl_88D45B40[];
extern char lbl_88D498BC[];
extern char lbl_88D498C0[];
extern char lbl_88D498C4[];
extern char lbl_88D498C8[];
extern char lbl_88D498CC[];
extern char lbl_88D498D0[];
extern char lbl_88D498D4[];
extern char lbl_88D498D8[];
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_88150600();
ts4_word fn_881519D0();
ts4_word fn_881608E8();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_8816D1A8();
ts4_word fn_8816D220();
ts4_word fn_8818A530();
ts4_word fn_881992A8();
ts4_word fn_881AD708();
ts4_word fn_881B9148();
ts4_word fn_8822BF98();
ts4_word ts4_msg_list_pop_882784F0();
ts4_word ts4_msg_buffer_alloc_88278620();
ts4_word ts4_clear_bucket_table_8827B998();
ts4_word fn_882802A0();
ts4_word ts4_if_call_seq_fn_88280958_882803B8();
ts4_word fn_88280C08();
ts4_word fn_88280E60();
ts4_word ts4_loop_get_u32_off0_88282ED8();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841C678();
ts4_word ts4_tailcall_memcpy_88421450();
ts4_word fn_88466AB0();
ts4_word fn_88472530();
ts4_word ts4_if_call_seq_lbl_88083354_88477588();
ts4_word ts4_addr_lbl_88084264_8847EF68();
ts4_word fn_8849EF70();
ts4_word ts4_tailcall_NetDll_connect_884F02B8();
ts4_word ts4_tailcall_NetDll_inet_addr_884F0388();
ts4_word ts4_tailcall_NetDll_WSAGetLastError_884F0390();
ts4_word fn_88534058();
ts4_word fn_88534240();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_88563470();
ts4_word fn_885647D0();
ts4_word fn_885651F8();
ts4_word ts4_tailcall_fn_885654E8_885655D0();
ts4_word ts4_tailcall_fn_8856A530_8856A658();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word fn_8856C718();
ts4_word fn_8856CC88();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();
ts4_word ts4_if_tailcall_MmSetAddressProtect_8857B148();
ts4_word fn_8857C1F8();
ts4_word fn_88581AA0();
ts4_word fn_88581AF0();
ts4_word ts4_forward_with_const_248C8000_885BE200();
ts4_word fn_885C3348();
ts4_word fn_885D9850();
ts4_word fn_885D9AA8();
ts4_word ts4_set_u32_off60_885D9B48();
ts4_word ts4_set_u32_off60_885D9B58();
ts4_word ts4_get_u32_off60_885D9B68();
ts4_word ts4_call_seq_u32_off0_885DBBB0();
ts4_word fn_885EABC8();
ts4_word ts4_get_u32_off0_885EAD98();
ts4_word ts4_msg_view_dtor_886047F8();
ts4_word fn_88605FA0();
ts4_word ts4_if_call_seq_lbl_880C1320_88606800();
ts4_word fn_88606978();
ts4_word fn_886074E8();
ts4_word fn_886077C0();
ts4_word fn_88608590();
ts4_word fn_88608FE0();
ts4_word fn_8860B180();
ts4_word ts4_if_get_u32_off10_8860B230();
ts4_word fn_8860B2A8();
ts4_word fn_8860BBD8();
ts4_word fn_8860BD70();
ts4_word fn_8860CDD8();
ts4_word fn_8860D5B8();
ts4_word fn_8860DCF8();
ts4_word fn_8860E320();
ts4_word ts4_handle_forward0_88610AC8();
ts4_word fn_88610FF0();
ts4_word fn_88612EB8();
ts4_word fn_886131F0();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88614B70();
ts4_word fn_88615168();
ts4_word fn_88615280();
ts4_word fn_88616F58();
ts4_word fn_88617788();
ts4_word ts4_loop_call_seq_u32_off4_886178A0();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word fn_886195A0();
ts4_word fn_88619628();
ts4_word fn_8861A370();
ts4_word fn_8861B8E0();
ts4_word fn_8861BAA0();
ts4_word fn_8861BB18();
ts4_word fn_8861BFD8();
ts4_word fn_8861C4F0();
ts4_word ts4_if_call_seq_u32_off14_8861C560();
ts4_word fn_8861C6F8();
ts4_word fn_8861DE40();
ts4_word fn_88624B58();
ts4_word fn_88629A00();
ts4_word fn_8862CB68();
ts4_word fn_886345E0();
ts4_word fn_88635678();
ts4_word ts4_if_get_u32_off84_886373C0();
ts4_word fn_88637420();
ts4_word fn_886379E0();
ts4_word fn_88639C88();
ts4_word fn_8863A238();
ts4_word fn_88640A30();
ts4_word fn_886443A0();
ts4_word fn_88657C70();
ts4_word fn_8865D7D8();
ts4_word fn_887EBC98();
ts4_word fn_88883CD0();
ts4_word fn_88884200();
ts4_word fn_888860A0();
ts4_word fn_889BCA90();
ts4_word fn_889BCB10();
ts4_word ts4_if_get_u32_off2e8_889BD208();
ts4_word ts4_if_call_seq_lbl_880C13BC_889BD2B8();
ts4_word ts4_call_seq_lbl_880C13BC_889BD310();
ts4_word fn_889BD370();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88467768: call_seq fn_88466AB0, lbl_880832C4, u32@0x0, u32@0x30 */
ts4_word ts4_call_seq_fn_88466AB0_88467768(ts4_word a0)
{
    fn_88466AB0();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880832C4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x884781E8: if_call_seq lbl_8808338C, u32@0x0, u32@0xc8, u32@lbl_88CACF08, KeTlsGetValue, u32@0xc0 */
ts4_word ts4_if_call_seq_lbl_8808338C_884781E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808338C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 200);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 192)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    t7 = ts4_if_call_seq_lbl_88083354_88477588((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88483028: if_call_seq lbl_88084A14, u32@0x0, u32@0x158, u32@lbl_88CACF08, KeTlsGetValue, u32@0x150 */
ts4_word ts4_if_call_seq_lbl_88084A14_88483028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88084A14;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 344);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 336)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    t7 = ts4_if_call_seq_lbl_88083354_88477588((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x884A4898: call_seq ts4_addr_lbl_88084264_8847EF68, lbl_88087F04, u32@0x0, u32@0x44, u32@0x48, u32@0x4c */
ts4_word ts4_call_seq_fn_8847EF68_884A4898(ts4_word a0)
{
    ts4_addr_lbl_88084264_8847EF68((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087F04;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(2147483648);
    return a0;
}

/* Swing_DLL.xex 0x88524080: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0xc, fn_88534058 */
ts4_word ts4_if_call_seq_u32_off4_88524080(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    unsigned char t10;
    unsigned char t11;
    unsigned char t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    if ((int)t5 == 4) {
        fn_88534240((ts4_word)a2, (ts4_word)t4, (ts4_word)t3, (ts4_word)(a0 + 16));
    } else {
        fn_88534058((ts4_word)a2, (ts4_word)t4, (ts4_word)t3, (ts4_word)(a0 + 16));
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a2) + 11) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)(a2) + 11)) & 0xff) & 0xffffffef);
    *(volatile ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)0;
    t10 = *(unsigned char *)((char *)(ts4_word)(a2) + 13);
    t11 = *(unsigned char *)((char *)(ts4_word)(a2) + 12);
    t12 = *(unsigned char *)((char *)(ts4_word)(a2) + 14);
    return ((((((((t12 << 2) | (t12 >> 30)) + t10) + t11) << 1) + 31) & 0xfffffff0) + a2);
}

/* Swing_DLL.xex 0x885C35D0: tailcall fn_885C3348 */
ts4_word ts4_tailcall_fn_885C3348_885C35D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return fn_885C3348((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((a7 ^ 2876637184) ^ 14558));
}

/* Swing_DLL.xex 0x885C83E0: if_call_seq u16@0xae, fn_885D9AA8, u32@0xa4, u16@0xa8, fn_885D9850 */
ts4_word ts4_if_call_seq_u16_offae_885C83E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    int t3;

    fn_885D9AA8((ts4_word)a2, (ts4_word)a4, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 174)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    if ((int)t3 == 1) {
        fn_885D9850((ts4_word)a0, (ts4_word)a2, (ts4_word)(a1 + 1616), (ts4_word)a3, (ts4_word)(a1 + 1456), (ts4_word)a4, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 168)));
    }
    return 1;
}

/* Swing_DLL.xex 0x885C8918: call_seq memset, u32@0x8, u32@0x4, u32@0x0, u64@0x10, u64@0x18 */
ts4_word ts4_call_seq_fn_8856ABA0_885C8918(ts4_word a0)
{
    ts4_word t1;

    t1 = memset((ts4_word)a0, (ts4_word)0, (ts4_word)120);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(4288675840);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)500;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)200;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x885CD0F8: if_get u32@0x0, u32@0x24c, fn_885CCFF8, u32@0x204, u32@0x1e4 */
void ts4_if_get_u32_off0_885CD0F8(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 588);
    if ((int)t2 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 484) = (ts4_word)(ts4_word)fn_885CCFF8;
    return;
}

/* Swing_DLL.xex 0x885CE9E8: get u32@0x8, u32@0x7c, u32@0x78, u32@0x60, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off8_885CE9E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t5) + 40))))((ts4_word)t1, (ts4_word)1, (ts4_word)t7, (ts4_word)1, (ts4_word)t6, (ts4_word)t4, (ts4_word)t3, (ts4_word)t2);
    return 0;
}

/* Swing_DLL.xex 0x885CF088: if_set u32@0x104, ts4_set_u32_off60_885D9B48 */
ts4_word ts4_if_set_u32_off104_885CF088(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return ts4_set_u32_off60_885D9B48((ts4_word)a0, (ts4_word)a1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)1;
    return a0;
}

/* Swing_DLL.xex 0x885CF0A0: if_set u32@0x104, ts4_set_u32_off60_885D9B58 */
ts4_word ts4_if_set_u32_off104_885CF0A0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return ts4_set_u32_off60_885D9B58((ts4_word)a0, (ts4_word)a1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x885CF0B8: if_get u32@0x104, ts4_get_u32_off60_885D9B68 */
ts4_word ts4_if_get_u32_off104_885CF0B8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return ts4_get_u32_off60_885D9B68((ts4_word)a0, (ts4_word)a1);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 260));
}

/* Swing_DLL.xex 0x885D9518: if_call_seq u32@0x8, ts4_forward_with_const_248C8000_885BE200, u32@0x8, u32@0xc, ts4_forward_with_const_248C8000_885BE200, u32@0xc */
ts4_word ts4_if_call_seq_u32_off8_885D9518(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_forward_with_const_248C8000_885BE200((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_forward_with_const_248C8000_885BE200((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x885DA218: if_get u32@0x10, u32@0x4, u32@0x0 */
ts4_word ts4_if_get_u32_off10_885DA218(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)t2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x885DBA68: if_get u32@0x0, ts4_call_seq_u32_off0_885DBBB0 */
ts4_word ts4_if_get_u32_off0_885DBA68(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ts4_call_seq_u32_off0_885DBBB0((ts4_word)a0);
}

/* Swing_DLL.xex 0x885E84B8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_880C070C, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_885E84B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)28, (ts4_word)21);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)28;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880C070C;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x885E8528: if_call_seq u32@0x18, u32@lbl_88CACF08, KeTlsGetValue, u32@0x10, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off18_885E8528(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(t1 << 5), (ts4_word)23);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(volatile unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x885E9CC8: set u8@0x3d, u8@0x3e, u8@0x3c, u8@0x41, u8@0x42, u8@0x40 */
ts4_word ts4_set_u8_off3d_885E9CC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a1;
    (void)a2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 61) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 62) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 65) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 66) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)2;
    return ts4_tailcall_memcpy_88421450((ts4_word)(a0 + 68), (ts4_word)(a0 + 60), (ts4_word)4, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x885E9D30: if_get u32@0x38, u32@0x24, u32@0xc, u32@0xc, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off38_885E9D30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    int t4;
    int t6;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 56);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 36);
    if ((int)(t1 + t2) == 0) {
        return a0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
    if ((int)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)(t4 + -1);
        return ts4_get_u32_off0_885EAD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    if ((int)t6 == 0) {
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(t6 + -1);
    return ts4_get_u32_off0_885EAD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)1);
}

/* Swing_DLL.xex 0x885EA008: if_call_seq fn_88472530, u32@0x38, fn_885EABC8, fn_8849EF70, u32@0x38, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88472530_885EA008(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    int t9;
    int t11;
    ts4_word t19;

    fn_88472530((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)a2 == 0) {
        fn_8849EF70((ts4_word)((((a3 + 1) + ((a3 + 1) << 2)) << 2) + t2), (ts4_word)a1);
    } else {
        fn_885EABC8((ts4_word)((((a3 + 1) + ((a3 + 1) << 2)) << 2) + t2), (ts4_word)a1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 56);
    t7 = *(ts4_word *)((char *)(ts4_word)(t2) + 36);
    if ((int)(t6 + t7) != 0) {
        t9 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
        if ((int)t9 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)(t9 + -1);
            ts4_get_u32_off0_885EAD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)1);
        } else {
            t11 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
            if ((int)t11 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t11 + -1);
                ts4_get_u32_off0_885EAD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)1);
            }
        }
    }
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)-1;
    t19 = RtlLeaveCriticalSection((ts4_word)a0);
    return t19;
}

/* Swing_DLL.xex 0x885ED230: loop_get u32@0x0, u32@0x8 */
ts4_word ts4_loop_get_u32_off0_885ED230(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    lv2 = (ts4_word)t1;
    lv3 = (ts4_word)0;
    do {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 8));
        p6 = (ts4_word)(lv3 + 1);
        lv2 = p5;
        lv3 = p6;
    } while ((ts4_word)p5 != 0);
    return lv3;
}

/* Swing_DLL.xex 0x885EDE28: if_get u32@0x10, u32@0xc */
ts4_word ts4_if_get_u32_off10_885EDE28(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 == 0) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F4610: if_get u32@0x0, u32@0xc, u32@0xc, u32@0x10, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off0_885F4610(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    int t3;
    ts4_word t6;
    ts4_word t8;
    int t9;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p14 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        p7 = (ts4_word)a0;
        if ((int)t3 == 10) {
            t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 16))) + 4))))((ts4_word)(t1 + 16));
            p7 = (ts4_word)t6;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 12);
        p13 = (ts4_word)p7;
        if ((int)t9 == 8) {
            t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 16))) + 4))))((ts4_word)(t8 + 16));
            p13 = (ts4_word)t12;
        }
        p14 = (ts4_word)p13;
    }
    return p14;
}

/* Swing_DLL.xex 0x885F4BC0: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x18, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off8_885F4BC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word p11;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a1, (ts4_word)4);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)((t5 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t6;
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(t9 + 1);
    p11 = (ts4_word)p4;
    if ((int)(t9 + 1) == (int)(t8 & 0x3fffffff)) {
        t10 = fn_8841C678((ts4_word)a1, (ts4_word)4);
        p11 = (ts4_word)t10;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)((t12 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t13;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 1);
    return p11;
}

/* Swing_DLL.xex 0x885F4DD0: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x18, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off8_885F4DD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a1, (ts4_word)4);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)((t5 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 1);
    return p4;
}

/* Swing_DLL.xex 0x885F5228: if_call_seq fn_889BCA90, ts4_call_seq_lbl_880C13BC_889BD310, u8@0x9, fn_889BD370, fn_889BCB10, ts4_if_get_u32_off2e8_889BD208 */
ts4_word ts4_if_call_seq_fn_889BCA90_885F5228(ts4_word a0)
{
    ts4_word loc50[192];
    ts4_word t9;

    fn_889BCA90();
    ts4_call_seq_lbl_880C13BC_889BD310((ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)a0 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 9)) != 0) {
        loc50[180] = (ts4_word)a0;
    }
    fn_889BD370((ts4_word)(ts4_word)&loc50[0]);
    fn_889BCB10((ts4_word)(ts4_word)&loc50[0]);
    ts4_if_get_u32_off2e8_889BD208((ts4_word)(ts4_word)&loc50[0]);
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)lbl_88D3EB60));
    *(ts4_word *)lbl_88D3EB60 = (ts4_word)0;
    t9 = ts4_if_call_seq_lbl_880C13BC_889BD2B8((ts4_word)(ts4_word)&loc50[0]);
    return t9;
}

/* Swing_DLL.xex 0x88600E00: addr lbl_880F9574, u32@0x0, ts4_msg_view_dtor_886047F8 */
ts4_word ts4_addr_lbl_880F9574_88600E00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9574;
    return ts4_msg_view_dtor_886047F8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88604388: if_call_seq u32@0x0, u32@0x0, ts4_msg_buffer_alloc_88278620, u32@0x0, memcpy, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88604388(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    if ((ts4_word)a2 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        return 0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    if ((ts4_word)a2 > (ts4_word)t2) {
        return -1;
    }
    t3 = ts4_msg_buffer_alloc_88278620((ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        return -1;
    }
    memcpy((ts4_word)t3, (ts4_word)a0, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0)) - a2);
    return a2;
}

/* Swing_DLL.xex 0x88604598: if_get u32@0x0, u32@0x4, u32@0x4, u32@0x14, u32@0x8, u32@0xc */
ts4_word ts4_if_get_u32_off0_88604598(ts4_word a0, int a1)
{
    ts4_word t3;

    if ((int)a1 == -1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t3;
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)2);
}

/* Swing_DLL.xex 0x88605D40: call_seq memcpy */
ts4_word ts4_call_seq_memcpy_88605D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = memcpy((ts4_word)a0, (ts4_word)(a1 + a2), (ts4_word)a3);
    *(unsigned char *)((char *)(ts4_word)(a0) + a3) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x88605DD0: get u32@0x0, u32@0x5c */
ts4_word ts4_get_u32_off0_88605DD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88605F88: get u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off0_88605F88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Swing_DLL.xex 0x88606208: if_call_seq ts4_tailcall_fn_8856A530_8856A658, u16@-0x2 */
ts4_word ts4_if_call_seq_fn_8856A658_88606208(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_tailcall_fn_8856A530_8856A658();
    p2 = (ts4_word)t1;
    if ((int)t1 < 0 || (ts4_word)t1 >= (ts4_word)a1) {
        if ((ts4_word)a1 != 0) {
            *(unsigned short *)((char *)(ts4_word)(((a1 << 1) + a0)) + -2) = (unsigned short)0;
        }
        p2 = (ts4_word)-1;
    }
    return p2;
}

/* Swing_DLL.xex 0x886062B8: if_call_seq ts4_tailcall_fn_885654E8_885655D0, u8@-0x1 */
ts4_word ts4_if_call_seq_fn_885655D0_886062B8(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_tailcall_fn_885654E8_885655D0();
    p2 = (ts4_word)t1;
    if ((int)t1 < 0 || (ts4_word)t1 >= (ts4_word)a1) {
        if ((ts4_word)a1 != 0) {
            *(unsigned char *)((char *)(ts4_word)((a0 + a1)) + -1) = (unsigned char)0;
        }
        p2 = (ts4_word)-1;
    }
    return p2;
}

/* Swing_DLL.xex 0x886064E8: fn  */
ts4_word ts4_fn_886064E8(ts4_word a0, ts4_word a1)
{
    return ((-(int)a0) & a1);
}

/* Swing_DLL.xex 0x886064F8: fn  */
ts4_word ts4_fn_886064F8(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & (-(int)a0));
}

/* Swing_DLL.xex 0x88606A58: if_fn  */
ts4_word ts4_if_fn_88606A58(ts4_word a0)
{
    ts4_word p1;

    p1 = (ts4_word)0;
    if ((int)(a0 & 0x20) != 0) {
        p1 = (ts4_word)256;
    }
    if ((int)(a0 & 0x40) != 0) {
        return (p1 | 128);
    }
    return p1;
}

/* Swing_DLL.xex 0x88606DF0: get u16@0x8a */
ts4_word ts4_get_u16_off8a_88606DF0(ts4_word a0)
{
    return (((*(unsigned short *)((char *)(ts4_word)(a0) + 138)) >> 14) & 0x1);
}

/* Swing_DLL.xex 0x88606E10: get  */
ts4_word ts4_get_88606E10(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned short *)((char *)(ts4_word)(((a1 + 12) << 2)) + a0)) >> 7) & 0x1);
}

/* Swing_DLL.xex 0x88606E28: get  */
ts4_word ts4_get_88606E28(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned short *)((char *)(ts4_word)(((a1 + 12) << 2)) + a0)) >> 6) & 0x1);
}

/* Swing_DLL.xex 0x88606E78: get u16@0x2, u8@0x0, u16@0x0, u16@0x0, u16@0x2 */
void ts4_get_u16_off2_88606E78(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(a0) + 0)) & 0xffffff00);
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)(t1 & 0x3f);
    return;
}

/* Swing_DLL.xex 0x88606EF8: if_get u32@0x14, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off14_88606EF8(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 == 0) {
        return;
    }
    if ((ts4_word)(a1 & 0xff) != 1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + -4);
    return;
}

/* Swing_DLL.xex 0x88607B58: get u32@0x4, u32@0x2c, u32@0x38, u32@0xc, memcpy */
ts4_word ts4_get_u32_off4_88607B58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 56);
    return memcpy((ts4_word)((((*(ts4_word *)((char *)(ts4_word)((t2 + (a2 << 4))) + 12))) >> 5) + t3), (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88607C08: if_get u32@0x4, fn_886074E8 */
ts4_word ts4_if_get_u32_off4_88607C08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    (void)a1;
    if ((ts4_word)a2 != (ts4_word)((983040) | 65535)) {
        return fn_886074E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a2, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((983040) | 65535));
    }
    return a0;
}

/* Swing_DLL.xex 0x88607C38: if_tail fn_88605FA0, u8@0x0, fn_88605FA0 */
ts4_word ts4_if_tail_fn_88605FA0_88607C38(int a0, ts4_word a1)
{
    if ((int)a0 < 0) {
        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)45;
        return fn_88605FA0((ts4_word)(-(int)a0), (ts4_word)(a1 + 1));
    }
    return fn_88605FA0((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88607C60: if_call_seq u32@lbl_88D498C0, lbl_88D498BC, lbl_880D4B08, u32@lbl_88D498C0, u32@lbl_88D498BC, lbl_88D498BC */
ts4_word ts4_if_call_seq_u32_lbl_88D498C0_88607C60(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D498C0;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D498C0 = (ts4_word)(t1 | 1);
        *(ts4_word *)lbl_88D498BC = (ts4_word)(ts4_word)lbl_880D4B08;
        fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_880D19F0_88AFF428);
        return (ts4_word)lbl_88D498BC;
    }
    return (ts4_word)lbl_88D498BC;
}

/* Swing_DLL.xex 0x88607CE0: if_call_seq u32@lbl_88D498C8, lbl_88D498C4, lbl_880D5870, u32@lbl_88D498C8, u32@lbl_88D498C4, lbl_88D498C4 */
ts4_word ts4_if_call_seq_u32_lbl_88D498C8_88607CE0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D498C8;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D498C8 = (ts4_word)(t1 | 1);
        *(ts4_word *)lbl_88D498C4 = (ts4_word)(ts4_word)lbl_880D5870;
        fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_880D19F0_88AFF410);
        return (ts4_word)lbl_88D498C4;
    }
    return (ts4_word)lbl_88D498C4;
}

/* Swing_DLL.xex 0x88607D60: if_call_seq u32@lbl_88D498D0, lbl_88D498CC, lbl_880D5864, u32@lbl_88D498D0, u32@lbl_88D498CC, lbl_88D498CC */
ts4_word ts4_if_call_seq_u32_lbl_88D498D0_88607D60(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D498D0;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D498D0 = (ts4_word)(t1 | 1);
        *(ts4_word *)lbl_88D498CC = (ts4_word)(ts4_word)lbl_880D5864;
        fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_880D19F0_88AFF3F8);
        return (ts4_word)lbl_88D498CC;
    }
    return (ts4_word)lbl_88D498CC;
}

/* Swing_DLL.xex 0x88607DE0: if_call_seq u32@lbl_88D498D8, lbl_88D498D4, lbl_880D4AFC, u32@lbl_88D498D8, u32@lbl_88D498D4, lbl_88D498D4 */
ts4_word ts4_if_call_seq_u32_lbl_88D498D8_88607DE0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D498D8;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D498D8 = (ts4_word)(t1 | 1);
        *(ts4_word *)lbl_88D498D4 = (ts4_word)(ts4_word)lbl_880D4AFC;
        fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_880D19F0_88AFF3E0);
        return (ts4_word)lbl_88D498D4;
    }
    return (ts4_word)lbl_88D498D4;
}

/* Swing_DLL.xex 0x88607E60: loop_get u32@0x78, u32@0x74, u32@0x0, u32@0x0, u32@0x34, vcall */
ts4_word ts4_loop_get_u32_off78_88607E60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return 0;
    }
    lv3 = (ts4_word)t2;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 52))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
        if ((ts4_word)(t7 & 0xff) != 0) {
            return 1;
        }
        p8 = (ts4_word)(lv3 + 4);
        lv3 = p8;
    } while ((ts4_word)p8 != (ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x88607ED0: loop_get u32@0x78, u32@0x74, u32@0x0, u32@0x0, u32@0x30, vcall */
ts4_word ts4_loop_get_u32_off78_88607ED0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return 0;
    }
    lv3 = (ts4_word)t2;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 48))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
        if ((ts4_word)(t7 & 0xff) != 0) {
            return 1;
        }
        p8 = (ts4_word)(lv3 + 4);
        lv3 = p8;
    } while ((ts4_word)p8 != (ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x88607F40: loop_get u32@0x78, u32@0x74, u32@0x0, u32@0x0, u32@0x2c, vcall */
ts4_word ts4_loop_get_u32_off78_88607F40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return 0;
    }
    lv3 = (ts4_word)t2;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 44))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
        if ((ts4_word)(t7 & 0xff) != 0) {
            return 1;
        }
        p8 = (ts4_word)(lv3 + 4);
        lv3 = p8;
    } while ((ts4_word)p8 != (ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x886087A8: if_get u32@0x120, u32@0x0, u32@0x4, vcall, u32@0x124, u32@0x124 */
ts4_word ts4_if_get_u32_off120_886087A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 288);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
    if ((ts4_word)t5 < 60) {
        *(volatile ts4_word *)((char *)(ts4_word)(((t5 + 12) << 2)) + a0) = (ts4_word)a1;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 292)) + 1);
    }
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    return t10;
}

/* Swing_DLL.xex 0x88608950: call_seq fn_88581AF0 */
ts4_word ts4_call_seq_fn_88581AF0_88608950(void)
{
    ts4_word loc50[10];
    ts4_word t2;

    fn_88581AF0((ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[3];
    return t2;
}

/* Swing_DLL.xex 0x886089E0: loop_get u32@0x20, u32@0x1c, u32@0x4, u32@0x0, u32@0x8, vcall */
ts4_word ts4_loop_get_u32_off20_886089E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4);
            p8 = (ts4_word)(lv3 + 8);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88608D10: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88608D10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    int t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p6 = (ts4_word)a0;
    if ((int)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) == (ts4_word)a0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88609978: addr lbl_88D452A0, u32@lbl_88D45B24, u32@lbl_88D45B24, u8@0x1c */
void ts4_addr_lbl_88D452A0_88609978(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B24;
    *(ts4_word *)lbl_88D45B24 = (ts4_word)(t1 + 1);
    *(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (ts4_word)lbl_88D452A0) = (ts4_word)a0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88609AF0: loop_get u32@0x10, vcall, u32@0x4, u32@0x4, fn_8857C1F8, u32@0x4 */
ts4_word ts4_loop_get_u32_off10_88609AF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t7;
    unsigned char t10;
    ts4_word t16;
    unsigned char t19;
    ts4_word t22;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
    }
    fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 0)), (ts4_word)-1);
    t10 = *(unsigned char *)((char *)(ts4_word)(t7) + 80);
    if ((ts4_word)t10 != 0) {
        do {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 24))))((ts4_word)a0);
            fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8)));
            t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t16) + 0)), (ts4_word)-1);
            t19 = *(unsigned char *)((char *)(ts4_word)(t16) + 80);
        } while ((ts4_word)t19 != 0);
    }
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t22 != 0) {
        ((ts4_word (*)(ts4_word))(t22))((ts4_word)a0);
    }
    fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 12)));
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88609BB0: if_get u8@0x824, u32@0x81c, u32@0x81c, u32@0x81c */
void ts4_if_get_u8_off824_88609BB0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    int t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 2084);
    if ((ts4_word)t1 != 1) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 2076);
    if ((int)t3 != 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 2076) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88609EB8: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_88609EB8(ts4_word a0, ts4_word a1)
{
    ts4_word p25;
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t6;
    ts4_word t10;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t20;
    ts4_word t21;
    ts4_word t24;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)0);
    t6 = loc50[0];
    p25 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 4))))((ts4_word)t6, (ts4_word)(ts4_word)&loc58[0], (ts4_word)8);
        t10 = loc50[0];
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 28))))((ts4_word)t10, (ts4_word)0, (ts4_word)2);
        t14 = fn_886077C0((ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)t14 != 0) {
            t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 0);
            t16 = loc50[0];
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t15) + 16))))((ts4_word)t14, (ts4_word)a0, (ts4_word)t16);
        }
        t20 = loc50[0];
        t21 = *(ts4_word *)((char *)(ts4_word)(t20) + 4);
        t24 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t21) + 0))) + 88))))((ts4_word)t21, (ts4_word)(ts4_word)&loc50[0]);
        p25 = (ts4_word)t24;
    }
    return p25;
}

/* Swing_DLL.xex 0x8860B3C0: if_get u32@0x4, u32@0x2c, u32@0xc, u32@0x0, u32@0x38, u32@0x4 */
ts4_word ts4_if_get_u32_off4_8860B3C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 44)) + (a2 << 4))) + 12);
    p8 = (ts4_word)0;
    if ((int)(t3 & 0x1f) == 4) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a5) + 0);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 56);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t4) + 4))))((ts4_word)a5, (ts4_word)a3, (ts4_word)(((t3) >> 5) + t5));
        p8 = (ts4_word)1;
    }
    return p8;
}

/* Swing_DLL.xex 0x8860BD18: addr lbl_880F78D4, u32@0x0, u32@0x4 */
void ts4_addr_lbl_880F78D4_8860BD18(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F78D4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8860BE28: if_get u32@0xc, fn_8860BD70 */
ts4_word ts4_if_get_u32_offc_8860BE28(ts4_word a0)
{
    int t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 == 0) {
        return a0;
    }
    return fn_8860BD70((ts4_word)a0);
}

/* Swing_DLL.xex 0x8860CE58: if_get u32@0x34, u32@0x24, u32@0x178, lbl_880C9DCC, ts4_if_tailcall_MmSetAddressProtect_8857B148, lbl_880C9DCC */
ts4_word ts4_if_get_u32_off34_8860CE58(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word p9;
    int t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    if ((int)t1 == 0) {
        p9 = (ts4_word)4;
        if ((int)a1 < 3) {
            p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_880C9DCC));
        }
        return fn_88581AA0((ts4_word)t3, (ts4_word)t2, (ts4_word)p9, (ts4_word)0);
    }
    p5 = (ts4_word)4;
    if ((int)a1 < 3) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_880C9DCC));
    }
    return ts4_if_tailcall_MmSetAddressProtect_8857B148((ts4_word)t3, (ts4_word)t2, (ts4_word)p5);
}

/* Swing_DLL.xex 0x8860D250: if_call_seq fn_88883CD0, u32@0xc, u32@0x24, fn_88883CD0, u32@0xc */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 12)) != 0) {
        t4 = fn_88883CD0((ts4_word)0);
        if ((ts4_word)t4 != 0) {
            return (*(volatile ts4_word *)((char *)(ts4_word)(t4) + 12));
        }
        return 0;
    }
    return (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x8860D540: if_call_seq fn_88883CD0, u32@0xc, u32@0x4 */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D540(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a0;
        if ((ts4_word)(a1 & 0xff) != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a0;
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x8860D6F8: if_get u32@0x34, u32@0x24, u32@0x178, lbl_880C9DCC, ts4_if_tailcall_MmSetAddressProtect_8857B148, lbl_880C9DCC */
ts4_word ts4_if_get_u32_off34_8860D6F8(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word p9;
    int t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    if ((int)t1 == 0) {
        p9 = (ts4_word)4;
        if ((int)a1 < 3) {
            p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_880C9DCC));
        }
        return fn_88581AA0((ts4_word)t3, (ts4_word)t2, (ts4_word)p9, (ts4_word)0);
    }
    p5 = (ts4_word)4;
    if ((int)a1 < 3) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_880C9DCC));
    }
    return ts4_if_tailcall_MmSetAddressProtect_8857B148((ts4_word)t3, (ts4_word)t2, (ts4_word)p5);
}

/* Swing_DLL.xex 0x8860E140: if_get u32@0x70, u32@0x7c, u32@0x4, u8@0x9e */
ts4_word ts4_if_get_u32_off70_8860E140(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    int t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 112);
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 124))) + 4) = (ts4_word)(a3 + a4);
        if ((ts4_word)(a2 & 0xff) != 0) {
            *(unsigned char *)((char *)(ts4_word)(a1) + 158) = (unsigned char)1;
            return 1;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x8860E3E8: if_call_seq u32@0x0, u32@0x4, u32@0x14, fn_8856C718, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8860E3E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    int t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p6 = (ts4_word)a0;
    if ((int)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) == (ts4_word)a0) {
        t4 = fn_8856C718((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 20)));
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8860E610: loop_get u32@0x28, u32@0x24, u32@0x0, u8@0x20, u32@0x0, u32@0x50 */
ts4_word ts4_loop_get_u32_off28_8860E610(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    unsigned char t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 32);
            p9 = (ts4_word)t4;
            if ((ts4_word)t5 != 0) {
                t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)a1);
                p9 = (ts4_word)t8;
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t1);
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x8860E6E8: loop_get u32@0x28, u32@0x24, u32@0x0, u8@0x20, u32@0x0, u32@0x40 */
ts4_word ts4_loop_get_u32_off28_8860E6E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    unsigned char t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 32);
            p9 = (ts4_word)t4;
            if ((ts4_word)t5 != 0) {
                t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 64))))((ts4_word)t4, (ts4_word)a1);
                p9 = (ts4_word)t8;
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t1);
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x8860F028: get u32@0x38, u32@0x0 */
ts4_word ts4_get_u32_off38_8860F028(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    return ((((int)a1 * 176) + (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1);
}

/* Swing_DLL.xex 0x8860F078: get u32@0x38, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off38_8860F078(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    return (*(volatile ts4_word *)((char *)(ts4_word)(((((int)a1 * 176) + (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + t1)) + 12));
}

/* Swing_DLL.xex 0x8860F4E0: get u32@0xbc, u32@0xbc */
void ts4_get_u32_offbc_8860F4E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)(((((~(t1 | t1)) << 2) | ((~(t1 | t1)) >> 30)) & 0x10) | (4 & 0xffffffef));
    return;
}

/* Swing_DLL.xex 0x8860F4F8: get u32@0xbc, u32@0xbc */
void ts4_get_u32_offbc_8860F4F8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)(((((~(t1 | t1)) << 2) | ((~(t1 | t1)) >> 30)) & 0x8) | (2 & 0xfffffff7));
    return;
}

/* Swing_DLL.xex 0x8860F5D0: if_get u32@0x278, u32@0x278, u32@0x270, u32@0xc, u32@0x270, u32@0x0 */
ts4_word ts4_if_get_u32_off278_8860F5D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 632);
    if ((int)t1 != 4) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 632) = (ts4_word)2;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 624);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 624) = (ts4_word)(t3 + 1);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886114B0: if_get u32@0x4, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x2c, u32@0x8 */
void ts4_if_get_u32_off4_886114B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    int t1;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 != 0 && (ts4_word)a3 != (ts4_word)((983040) | 65535)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) + (a3 << 4))) + 8));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x886114F8: get u32@0x0, u32@0x4, u32@0x0, u32@0x18, vcall, fn_88608590 */
ts4_word ts4_get_u32_off0_886114F8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[512];
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)2048);
    t6 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    return ((a1 - t6) == 0);
}

/* Swing_DLL.xex 0x88611B08: get u32@0x10, u8@0x20, fn_8857C1F8 */
ts4_word ts4_get_u32_off10_88611B08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    return fn_8857C1F8((ts4_word)t1);
}

/* Swing_DLL.xex 0x88611C00: if_get u32@0x0, u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off0_88611C00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p13;
    int t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    p13 = (ts4_word)0;
    if ((int)t1 != -1) {
        t3 = fn_8816D220((ts4_word)(*(volatile ts4_word *)lbl_88D45B20), (ts4_word)((1428815872) | 26185));
        if ((ts4_word)t3 == 0) {
            p8 = (ts4_word)0;
        } else {
            t6 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3);
            p8 = (ts4_word)t6;
        }
        t9 = *(volatile ts4_word *)((char *)(ts4_word)(p8) + 0);
        t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t9) + 44))))((ts4_word)p8, (ts4_word)(t10 + a0));
        p13 = (ts4_word)p8;
    }
    return p13;
}

/* Swing_DLL.xex 0x88611C98: loop_get u8@0x1c, u32@0x24, u32@0x20, u8@0x1c, u32@0x0, u8@0x8 */
ts4_word ts4_loop_get_u8_off1c_88611C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p10;
    ts4_word p11;
    ts4_word p12;
    ts4_word p15;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    unsigned char t6;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
    p15 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
        p12 = (ts4_word)a0;
        lv4 = (ts4_word)t3;
        while ((ts4_word)lv4 != (ts4_word)t2) {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 8);
            p10 = (ts4_word)t5;
            if ((ts4_word)t6 != 0) {
                t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5);
                p10 = (ts4_word)t9;
            }
            p11 = (ts4_word)(lv4 + 4);
            lv4 = p11;
            p12 = (ts4_word)p10;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
        p15 = (ts4_word)p12;
    }
    return p15;
}

/* Swing_DLL.xex 0x88613020: get u32@0x20, u32@0x4, u32@0x178, u8@0x188, u32@0x18c, fn_8860CDD8 */
ts4_word ts4_get_u32_off20_88613020(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)a1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 392) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    return fn_8860CDD8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x88613528: if_get u32@lbl_88D45B38, fn_8860D5B8 */
ts4_word ts4_if_get_u32_lbl_88D45B38_88613528(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        return fn_8860D5B8((ts4_word)a0);
    }
    return 0;
}

/* Swing_DLL.xex 0x88613548: if_get u32@lbl_88D45B38, fn_885651F8, fn_886131F0 */
ts4_word ts4_if_get_u32_lbl_88D45B38_88613548(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        return fn_886131F0((ts4_word)t1, (ts4_word)a1, (ts4_word)a0);
    }
    return fn_885651F8((ts4_word)a1, (ts4_word)a1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x88613D58: if_get fn_88608FE0, u32@0x0, u32@0x4, u32@0x14, u32@0x4, u32@0x0 */
ts4_word ts4_if_get_fn_88608FE0_88613D58(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word p15;
    ts4_word t1;
    int t2;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = fn_88608FE0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p15 = (ts4_word)t1;
    if ((int)t2 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4)) == (ts4_word)a0) {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 20))) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 88))))((ts4_word)t5, (ts4_word)(t2 + 20));
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        p13 = (ts4_word)t9;
        if ((ts4_word)t9 != 0) {
            t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 0))))((ts4_word)t9, (ts4_word)1);
            p13 = (ts4_word)t12;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p15 = (ts4_word)p13;
    }
    return p15;
}

/* Swing_DLL.xex 0x88614170: loop_get u32@0x2dd0, u32@0x4, vcall, u8@0x0, fn_8856CC88, fn_88608590 */
ts4_word ts4_loop_get_u32_off2dd0_88614170(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv4;
    ts4_word p6;
    ts4_word loc50[128];
    unsigned char t5;
    ts4_word t8;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 11728))) + 4))))((ts4_word)(a1 + 11728));
    lv4 = (ts4_word)a2;
    do {
        t5 = *(unsigned char *)((char *)(ts4_word)(lv4) + 0);
        *(unsigned char *)((char *)(ts4_word)(((ts4_word)&loc50[0] - a2)) + lv4) = (unsigned char)t5;
        p6 = (ts4_word)(lv4 + 1);
        lv4 = p6;
    } while ((ts4_word)t5 != 0);
    fn_8856CC88((ts4_word)(ts4_word)&loc50[0]);
    t8 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    fn_8860E320((ts4_word)a0, (ts4_word)a1, (ts4_word)t8, (ts4_word)a3);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a1 + 11728)) + 0))) + 8))))((ts4_word)(a1 + 11728));
    return a0;
}

/* Swing_DLL.xex 0x88614210: if_get u32@0x0, u32@0x4, u32@0x14, u32@0x4, u32@0x0, u32@0x58 */
ts4_word ts4_if_get_u32_off0_88614210(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p12;
    ts4_word p14;
    int t1;
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p14 = (ts4_word)a0;
    if ((int)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) == (ts4_word)a0) {
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 20))) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 88))))((ts4_word)t4, (ts4_word)(t1 + 20));
        t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        p12 = (ts4_word)t8;
        if ((ts4_word)t8 != 0) {
            t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 0))))((ts4_word)t8, (ts4_word)1);
            p12 = (ts4_word)t11;
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p14 = (ts4_word)p12;
    }
    return p14;
}

/* Swing_DLL.xex 0x88614298: get u32@0x144c, u32@0x4, vcall, u8@0x14ac, u32@0x144c, u32@0x8 */
ts4_word ts4_get_u32_off144c_88614298(ts4_word a0)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 5196))) + 4))))((ts4_word)(a0 + 5196));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5292) = (unsigned char)0;
    t6 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 5196))) + 8))))((ts4_word)(a0 + 5196));
    return t6;
}

/* Swing_DLL.xex 0x886146A0: get u8@0x14 */
ts4_word ts4_get_u8_off14_886146A0(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 20)) == 0);
}

/* Swing_DLL.xex 0x88614990: if_call_seq fn_88614938, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88614938_88614990(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88614938((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 16));
    }
    return -1;
}

/* Swing_DLL.xex 0x886149D0: if_call_seq fn_88614938, fn_88614938, u8@0x19, u32@0xc, u32@0xc, u32@0x30 */
ts4_word ts4_if_call_seq_fn_88614938_886149D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;
    ts4_word t4;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    if ((ts4_word)a1 != (ts4_word)a2) {
        t1 = fn_88614938((ts4_word)a0, (ts4_word)a1);
        t2 = fn_88614938((ts4_word)a0, (ts4_word)a2);
        t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 25);
        if ((ts4_word)t3 == 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a2;
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
            t5 = *(ts4_word *)((char *)(ts4_word)((a1 << 2)) + t4);
            *(ts4_word *)((char *)(ts4_word)((a1 << 2)) + t4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a2 << 2)) + t4));
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + (a2 << 2)) = (ts4_word)t5;
        }
        p9 = (ts4_word)t2;
    }
    return p9;
}

/* Swing_DLL.xex 0x886150A8: get u32@0x0, u32@0x0, u32@0x14, u32@0x10, u32@0x0, u32@0x4 */
void ts4_get_u32_off0_886150A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a4;
    return;
}

/* Swing_DLL.xex 0x88615720: call_seq ts4_handle_forward0_88610AC8, u32@0x4 */
ts4_word ts4_call_seq_fn_88610AC8_88615720(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;

    (void)a0;
    t1 = ts4_handle_forward0_88610AC8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 4));
}

/* Swing_DLL.xex 0x88615938: get u32@0x0, u32@0x0, u32@0xb4, vcall, u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off0_88615938(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 180))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t8 = fn_88615280((ts4_word)t5, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)t4, (ts4_word)t6);
    *(volatile ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)t8;
    *(volatile ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a0;
    return t8;
}

/* Swing_DLL.xex 0x886171D8: if_get u8@0x8, fn_8860B180, fn_88616F58 */
ts4_word ts4_if_get_u8_off8_886171D8(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return fn_88616F58((ts4_word)a0);
    }
    return fn_8860B180((ts4_word)a0);
}

/* Swing_DLL.xex 0x886171F0: if_set u32@0x4, u32@0x1c, u32@0x8, u32@0x20, u32@0x10, u32@0x14 */
ts4_word ts4_if_set_u32_off4_886171F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t15;

    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    if ((ts4_word)a2 != 0) {
        t1 = fn_8860B2A8((ts4_word)a0, (ts4_word)a2);
        if ((ts4_word)(t1 & 0xff) != 0) {
            ts4_if_get_u32_off10_8860B230((ts4_word)a0, (ts4_word)a2);
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            t5 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t3, (ts4_word)1, (ts4_word)0, (ts4_word)0);
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t5;
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 4))))((ts4_word)a2, (ts4_word)t5, (ts4_word)t6);
            fn_88610FF0((ts4_word)a0, (ts4_word)a3);
            fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        }
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return t15;
}

/* Swing_DLL.xex 0x88617C58: if_tailcall fn_882802A0 */
ts4_word ts4_if_tailcall_fn_882802A0_88617C58(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_882802A0((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88617D28: if_call_seq lbl_880F7EE4, u8@0x8, u32@0x0, fn_881B9148, u32@0x10, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7EE4;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88618068: call_seq lbl_880F7DEC, u32@0x0, u32@lbl_88D45B40, fn_88617D88, lbl_880F7E00, lbl_880F7E14 */
ts4_word ts4_call_seq_lbl_880F7DEC_88618068(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7DEC;
    *(volatile ts4_word *)lbl_88D45B40 = (ts4_word)a0;
    fn_88617D88((ts4_word)(a0 + 4));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7E00;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880F7E14;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x88618660: if_call_seq u8@0x189, u32@0x178, fn_88612EB8, u32@0x2c, u32@0x2c */
ts4_word ts4_if_call_seq_u8_off189_88618660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    unsigned char t1;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 393);
    p5 = (ts4_word)a0;
    if (((ts4_word)t1 != 0 && (ts4_word)a1 != 0) && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 376)) == 0) {
        t3 = fn_88612EB8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) + a2);
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x88618940: call_seq fn_88617D88, lbl_880F8928, u32@0x0, u32@0x1c, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88618940(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8928;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88619570: if_set u32@0xe8, u32@lbl_88D45B1C, u32@0x0, u32@0x4, u32@0x0, fn_88617788 */
ts4_word ts4_if_set_u32_offe8_88619570(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    t1 = *(ts4_word *)lbl_88D45B1C;
    if ((ts4_word)t1 != 0) {
        return fn_88617788((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a5) + 0)), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a5) + 0));
    return a0;
}

/* Swing_DLL.xex 0x8861A8D0: if_set u8@0x8, fn_881B9148, u32@0x1c, u8@0x20, u8@0x20, u32@0x24 */
ts4_word ts4_if_set_u8_off8_8861A8D0(ts4_word a0)
{
    ts4_word p21;
    ts4_word p22;
    ts4_word t1;
    int t2;
    unsigned char t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t13;
    ts4_word t17;
    ts4_word t20;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p22 = (ts4_word)t1;
    if ((int)t2 != 0) {
        t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 32);
        if ((ts4_word)t4 != 0) {
            t6 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
            if ((ts4_word)t6 != 0) {
                t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
                t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 36))))((ts4_word)t6, (ts4_word)(t8 + 4), (ts4_word)0);
            }
        }
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 20))))((ts4_word)t13);
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        p21 = (ts4_word)t17;
        if ((ts4_word)t17 != 0) {
            t20 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 0))) + 0))))((ts4_word)t17, (ts4_word)1);
            p21 = (ts4_word)t20;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p22 = (ts4_word)p21;
    }
    return p22;
}

/* Swing_DLL.xex 0x8861AD10: tailcall fn_888860A0 */
ts4_word ts4_tailcall_fn_888860A0_8861AD10(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_888860A0((ts4_word)a1);
}

/* Swing_DLL.xex 0x8861B2D8: get u32@0x30, fn_88614B70 */
ts4_word ts4_get_u32_off30_8861B2D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + (a1 << 2)) = (ts4_word)a2;
    return fn_88614B70((ts4_word)a0, (ts4_word)1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8861C110: if_get u32@0x8, fn_8861BFD8 */
ts4_word ts4_if_get_u32_off8_8861C110(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != (ts4_word)((1255866368) | 43424)) {
        return a0;
    }
    return fn_8861BFD8((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8861C468: if_get u32@0x10, u32@0x0, u32@0x28, vcall, u32@0x4, fn_88615168 */
ts4_word ts4_if_get_u32_off10_8861C468(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    int t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    t6 = fn_88615168((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4)));
    t7 = ts4_if_call_seq_u32_off14_8861C560((ts4_word)a0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t8 != 0 && (ts4_word)(t6 & 0xff) == 1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + -4);
    }
    return t7;
}

/* Swing_DLL.xex 0x8861C5C8: if_call_seq u32@0x10, u32@0x14, u32@0x0, u32@0x4, ts4_object_finalize, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off10_8861C5C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p12;
    ts4_word p14;
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p14 = (ts4_word)a0;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        p12 = (ts4_word)a0;
        if ((ts4_word)t2 != (ts4_word)t3) {
            ts4_object_finalize((ts4_word)a0);
            ts4_object_finalize((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
            ts4_object_finalize((ts4_word)a0);
            t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t9;
            t11 = fn_8861C4F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0)), (ts4_word)a0);
            p12 = (ts4_word)t11;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        p14 = (ts4_word)p12;
    }
    return p14;
}

/* Swing_DLL.xex 0x8861D960: get u32@0x4, fn_8861C6F8 */
ts4_word ts4_get_u32_off4_8861D960(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a1;
    return fn_8861C6F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x8861DDB0: loop_get u32@0x8, u32@0x4, vcall, u32@0x28, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off8_8861DDB0(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p8;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 4))))((ts4_word)(a0 + 8));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    if ((ts4_word)t5 != (ts4_word)t4) {
        lv6 = (ts4_word)t5;
        do {
            p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv6) + 0));
            lv6 = p8;
        } while ((ts4_word)p8 != (ts4_word)t4);
    }
    t10 = fn_88280E60((ts4_word)t3);
    if ((int)(t10 + 8) != 0) {
        *(ts4_word *)((char *)(ts4_word)((t10 + 8)) + 0) = (ts4_word)a1;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)t11;
    *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)t10;
    *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t10;
    t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0))) + 8))))((ts4_word)(a0 + 8));
    return t14;
}

/* Swing_DLL.xex 0x8861E938: loop_call_seq u32@0x0, u32@0x4, ts4_loop_call_seq_u32_off4_886178A0, u32@0x4, u32@0x0, fn_88280C08 */
ts4_word ts4_loop_call_seq_u32_off0_8861E938(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p16;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t1;
        do {
            ts4_loop_call_seq_u32_off4_886178A0((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 36);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t2);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_88280C08((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t8);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_loop_get_u32_off0_88282ED8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t11);
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p16 = (ts4_word)t14;
    if ((ts4_word)t14 != 0) {
        t15 = ts4_destroy_owned_object((ts4_word)t14);
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Swing_DLL.xex 0x8861F7E0: call_seq u32@0x174, fn_88581AF0, u32@0x24, fn_88619628 */
ts4_word ts4_call_seq_u32_off174_8861F7E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[10];
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 372) = (ts4_word)0;
    fn_88581AF0((ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[3];
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t2;
    t3 = fn_88619628((ts4_word)a0, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x8861FD10: if_get u32@0x180, u32@0x17c, ts4_memset, u32@0x184, u32@0x17c, fn_885651F8 */
ts4_word ts4_if_get_u32_off180_8861FD10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    int t5;
    unsigned char t8;
    ts4_word t9;
    ts4_word t17;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
    if ((ts4_word)t1 != 0) {
        ts4_memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 380)), (ts4_word)0, (ts4_word)((int)t1 * 56));
        *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 380);
    if ((int)t5 != 0) {
        fn_885651F8((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    }
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 392);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    if ((ts4_word)t8 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 20))))((ts4_word)t9);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 0))))((ts4_word)t9, (ts4_word)1);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 392) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    t17 = fn_886195A0((ts4_word)a0);
    return t17;
}

/* Swing_DLL.xex 0x88620290: if_set u32@0xe8, u32@lbl_88D45B1C, u32@0x0, u32@0x4, u32@0x0, fn_88617788 */
ts4_word ts4_if_set_u32_offe8_88620290(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    t1 = *(ts4_word *)lbl_88D45B1C;
    if ((ts4_word)t1 != 0) {
        return fn_88617788((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a5) + 0)), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a5) + 0));
    return a0;
}

/* Swing_DLL.xex 0x886203D8: call_seq fn_88619628, u32@0x5c, u32@0x188, u32@0x5c, u32@0x18c, u32@0x184 */
ts4_word ts4_call_seq_fn_88619628_886203D8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;
    ts4_word t13;

    fn_88619628();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 92));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 92));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    t4 = *(volatile ts4_word *)lbl_88D45B38;
    t6 = fn_88618998((ts4_word)t4, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 88)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)t6;
    t8 = fn_8860DCF8((ts4_word)t6, (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 392)) << 2), (ts4_word)4, (ts4_word)2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)t8;
    ts4_memset((ts4_word)t8, (ts4_word)0, (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 392)) << 2));
    t11 = *(volatile ts4_word *)lbl_88D45B38;
    t13 = fn_88618998((ts4_word)t11, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 84)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)t13;
    return t13;
}

/* Swing_DLL.xex 0x88620D80: if_call_seq fn_886195A0, u8@0xe5, u32@0xe8, u32@0x178, u32@0xe8, u32@0x178 */
ts4_word ts4_if_call_seq_fn_886195A0_88620D80(ts4_word a0)
{
    ts4_word p13;
    ts4_word p15;
    ts4_word p16;
    ts4_word t1;
    unsigned char t2;
    int t5;
    ts4_word t6;
    ts4_word t14;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;

    t1 = fn_886195A0();
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 229);
    p16 = (ts4_word)t1;
    if ((ts4_word)t2 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
        if ((int)t5 != 0) {
            t14 = ts4_tsu_cleanup_end((ts4_word)t6);
            p15 = (ts4_word)t14;
        } else {
            ts4_memset((ts4_word)t6, (ts4_word)-3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
            p13 = (ts4_word)t9;
            if ((ts4_word)t9 != 0) {
                t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
                t12 = fn_88884200((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)t10);
                p13 = (ts4_word)t12;
            }
            p15 = (ts4_word)p13;
        }
        p16 = (ts4_word)p15;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    return p16;
}

/* Swing_DLL.xex 0x88622778: call_seq ts4_memset, fn_88606978, fn_88608590, fn_8861A370 */
ts4_word ts4_call_seq_ts4_memset_88622778(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[130];
    ts4_word t3;
    ts4_word t4;

    ts4_memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)512);
    fn_88606978((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t3 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_8861A370((ts4_word)a0, (ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88623C60: call_seq fn_88617D88, lbl_880F7C94, u32@0x0, u32@0x24, u32@0x28, u32@0x2c */
ts4_word ts4_call_seq_fn_88617D88_88623C60(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7C94;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564) = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88624048: if_call_seq u32@0x88, ts4_destroy_owned_object, lbl_880D19F0, u32@0x68, u32@0x48, u32@0x28 */
ts4_word ts4_if_call_seq_u32_off88_88624048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(ts4_word)lbl_880D19F0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(ts4_word)lbl_880D19F0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)lbl_880D19F0;
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = ts4_destroy_owned_object((ts4_word)t7);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x88624D70: if_call_seq fn_8861BB18, fn_8861BAA0, fn_8861B8E0, fn_88624B58, u8@0x824, u32@0x81c */
ts4_word ts4_if_call_seq_fn_8861BB18_88624D70(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;

    t1 = fn_8861BB18((ts4_word)a0, (ts4_word)a1);
    p3 = (ts4_word)t1;
    if ((ts4_word)(t1 & 0xff) == 0) {
        t2 = fn_8861BAA0((ts4_word)a0, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    p5 = (ts4_word)p3;
    if ((ts4_word)(p3 & 0xff) == 0) {
        t4 = fn_8861B8E0((ts4_word)a0, (ts4_word)a1);
        p5 = (ts4_word)t4;
    }
    p7 = (ts4_word)p5;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t6 = fn_88624B58((ts4_word)a0, (ts4_word)a1);
        p7 = (ts4_word)t6;
    }
    if (((ts4_word)(p7 & 0xff) == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 2084)) == 1) && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 2076)) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 2076) = (ts4_word)8;
    }
    return p7;
}

/* Swing_DLL.xex 0x88625E48: if_call_seq fn_881B9148, u32@lbl_88D45A10, u32@0x4, fn_887EBC98 */
ts4_word ts4_if_call_seq_fn_881B9148_88625E48(ts4_word a0)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t4;

    fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)lbl_88D45A10;
    p5 = (ts4_word)t2;
    if ((ts4_word)t2 != 0 && (ts4_word)a0 != (ts4_word)t2) {
        t4 = fn_887EBC98((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(a0 + 16));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88626530: if_call_seq lbl_880F7AE0, u32@0x0, u32@0x180, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F7AE0_88626530(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t10;
    ts4_word t12;
    ts4_word t18;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7AE0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 384);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 392)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    ts4_if_call_seq_fn_88280958_882803B8((ts4_word)(a0 + 368));
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 352);
    if ((ts4_word)t10 != 0) {
        t12 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t12 != 0) {
            fn_886131F0((ts4_word)t12, (ts4_word)t10, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 360)));
        } else {
            fn_885651F8((ts4_word)t10, (ts4_word)t10);
        }
    }
    t18 = ts4_if_call_seq_fn_88280958_882803B8((ts4_word)(a0 + 336));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)(ts4_word)lbl_880D19F0;
    return t18;
}

/* Swing_DLL.xex 0x88627BD8: call_seq lbl_880F7D90, u32@0x0, u32@0x20, ts4_destroy_owned_object, u32@0x14, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880F7D90_88627BD8(ts4_word a0)
{
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7D90;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    t6 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return t6;
}

/* Swing_DLL.xex 0x88627D00: loop_call_seq u32@0x1c, u32@0x20, u32@0x0, fn_8861DE40 */
ts4_word ts4_loop_call_seq_u32_off1c_88627D00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t5 = fn_8861DE40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0)));
            p6 = (ts4_word)(lv3 + 4);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t2);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x886285F8: call_seq fn_88617D88, lbl_880F8B6C, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_886285F8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8B6C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45B3C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88628EE0: call_seq lbl_880F7D90, u32@0x0, u32@0x4, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_lbl_880F7D90_88628EE0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7D90;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 8));
    fn_8816D1A8((ts4_word)(a0 + 20));
    fn_8816D1A8((ts4_word)(a0 + 32));
    return a0;
}

/* Swing_DLL.xex 0x88629280: addr lbl_880F20E8, u32@0x0, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_addr_lbl_880F20E8_88629280(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F20E8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886292B0: get u32@0x0, u32@0x18, vcall, ts4_assign_formatted_text */
ts4_word ts4_get_u32_off0_886292B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[512];

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)2048);
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return a0;
}

/* Swing_DLL.xex 0x88629EE8: if_call_seq u32@0x0, lbl_880C1320, fn_885647D0, ts4_assign_formatted_text */
ts4_word ts4_if_call_seq_u32_off0_88629EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p5 = (ts4_word)(ts4_word)lbl_880C1320;
    if ((ts4_word)t1 != 0) {
        t2 = fn_885647D0((ts4_word)t1, (ts4_word)46);
        p3 = (ts4_word)t2;
        if ((ts4_word)t2 == 0) {
            p3 = (ts4_word)(ts4_word)lbl_880C1320;
        }
        p5 = (ts4_word)p3;
    }
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)p5);
    return a0;
}

/* Swing_DLL.xex 0x88629F58: call_seq lbl_880D2EFC, ts4_assign_formatted_text, lbl_880D2F00, ts4_assign_formatted_text, fn_88629A00, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880D2EFC_88629F58(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t6;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880D2EFC);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D2F00);
    fn_88629A00((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t4);
    t6 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t6);
    return a0;
}

/* Swing_DLL.xex 0x88629FD8: call_seq lbl_880D2F00, ts4_assign_formatted_text, lbl_880D2EFC, ts4_assign_formatted_text, fn_88629A00, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880D2F00_88629FD8(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t6;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880D2F00);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D2EFC);
    fn_88629A00((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t4);
    t6 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t6);
    return a0;
}

/* Swing_DLL.xex 0x8862E0A8: loop_get u32@0x4c, u8@0x28, u32@0x1c, u32@0x4c, u32@0x44, fn_8862CB68 */
ts4_word ts4_loop_get_u32_off4c_8862E0A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;
    ts4_word t13;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 76))) + 40) = (unsigned char)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    if ((int)t2 != 0) {
        t4 = fn_8862CB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)((2302410752) | 33901));
        if ((ts4_word)(t4 & 0xff) == 0) {
            do {
                ts4_tailcall_fn_88584548_8857AFE8((ts4_word)50);
                t7 = fn_8862CB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)((2302410752) | 33901));
            } while ((ts4_word)(t7 & 0xff) == 0);
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 20))))((ts4_word)t9);
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t13 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 0))))((ts4_word)t13, (ts4_word)1);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t19 = fn_881B9148((ts4_word)(a0 + 16));
    return t19;
}

/* Swing_DLL.xex 0x8862FA88: if_call_seq u32@0x0, ts4_if_call_seq_lbl_880C1320_88606800, ts4_assign_formatted_text, lbl_880C1320, fn_8822BF98, lbl_880D2F08 */
ts4_word ts4_if_call_seq_u32_off0_8862FA88(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[4];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t4;
    int t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t11;

    t2 = ts4_if_call_seq_lbl_880C1320_88606800((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)t2);
    t4 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)a0);
    if ((ts4_word)(t4 & 0xff) == 0) {
        t5 = fn_881AD708((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D2F08);
        if ((int)t5 != -1) {
            t6 = fn_881608E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)0, (ts4_word)t5);
            ts4_if_call_seq_u32_off0_8816D140((ts4_word)(ts4_word)&loc50[0], (ts4_word)t6);
            fn_88150600((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
            t9 = loc50[0];
            ts4_destroy_owned_object((ts4_word)t9);
            t11 = loc60[0];
            ts4_destroy_owned_object((ts4_word)t11);
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x88636A70: call_seq fn_88617D88, lbl_880F7F90, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88636A70(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7F90;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45B28 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88636AD0: if_tail fn_886345E0, u32@0x4c, u32@0x18, fn_88635678 */
ts4_word ts4_if_tail_fn_886345E0_88636AD0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 76))) + 24) = (ts4_word)a1;
        return fn_88635678((ts4_word)a0);
    }
    return fn_886345E0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88637560: loop_get u32@0x84, u32@0x4, vcall, u32@0x64, u32@0x60, u32@0x0 */
ts4_word ts4_loop_get_u32_off84_88637560(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p11;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t16;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((ts4_word)t4 != (ts4_word)t5) {
        lv6 = (ts4_word)t5;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((ts4_word)t7 == 0 || (ts4_word)t7 == (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv6) + 4))) {
                fn_88637420((ts4_word)a0, (ts4_word)lv6, (ts4_word)0);
            }
            p11 = (ts4_word)(lv6 + 276);
            lv6 = p11;
        } while ((ts4_word)p11 != (ts4_word)t4);
    }
    t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t16;
}

/* Swing_DLL.xex 0x88638100: if_get u32@0x84, u32@0x4, vcall, fn_886379E0, u8@0x111, ts4_if_get_u32_off84_886373C0 */
ts4_word ts4_if_get_u32_off84_88638100(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;
    ts4_word t10;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = fn_886379E0((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    if ((ts4_word)t4 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t4) + 273)) != (ts4_word)(a2 & 0xff)) {
        ts4_if_get_u32_off84_886373C0((ts4_word)a0, (ts4_word)t4, (ts4_word)a2);
    }
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t10;
}

/* Swing_DLL.xex 0x88638188: if_get u32@0x84, u32@0x4, vcall, fn_886379E0, u8@0x110, fn_88637420 */
ts4_word ts4_if_get_u32_off84_88638188(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;
    ts4_word t10;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = fn_886379E0((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    if ((ts4_word)t4 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t4) + 272)) != (ts4_word)(a2 & 0xff)) {
        fn_88637420((ts4_word)a0, (ts4_word)t4, (ts4_word)a2);
    }
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t10;
}

/* Swing_DLL.xex 0x88639020: call_seq fn_88617D88, lbl_880F63C0, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88639020(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F63C0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88639D28: set u8@lbl_88D45B06 */
void ts4_set_u8_lbl_88D45B06_88639D28(ts4_word a0)
{
    *(volatile unsigned char *)lbl_88D45B06 = (unsigned char)a0;
    return;
}

/* Swing_DLL.xex 0x88639EB0: set u8@lbl_88D45B05 */
void ts4_set_u8_lbl_88D45B05_88639EB0(ts4_word a0)
{
    *(volatile unsigned char *)lbl_88D45B05 = (unsigned char)a0;
    return;
}

/* Swing_DLL.xex 0x88639F98: tailcall fn_88639C88 */
ts4_word ts4_tailcall_fn_88639C88_88639F98(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88639C88((ts4_word)a1);
}

/* Swing_DLL.xex 0x8863A660: if_get u32@0x4, u32@0x488, u8@0x49b */
ts4_word ts4_if_get_u32_off4_8863A660(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 1160);
    if ((int)t2 == 0) {
        return 0;
    }
    return (*(unsigned char *)((char *)(ts4_word)(t1) + 1179));
}

/* Swing_DLL.xex 0x8863A710: if_tailcall fn_8863A238 */
ts4_word ts4_if_tailcall_fn_8863A238_8863A710(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_8863A238((ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8863B008: addr lbl_880F62E4, u32@0x4, u32@0x0, fn_881519D0, u32@0x0, u32@0x10 */
ts4_word ts4_addr_lbl_880F62E4_8863B008(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F62E4;
    t1 = fn_881519D0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t4 + 16);
    t5 = fn_881519D0((ts4_word)t4);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 16))))((ts4_word)t5);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t8 + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x886406D8: if_call_seq u32@lbl_88D45290, u32@lbl_88D45290, ts4_clear_bucket_table_8827B998, u32@0x4, fn_8818A530, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_88D45290_886406D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)lbl_88D45290;
    if ((ts4_word)t1 != 0) {
        ts4_clear_bucket_table_8827B998((ts4_word)t1);
        fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        t6 = ts4_tsu_cleanup_end((ts4_word)t1);
        *(ts4_word *)lbl_88D45290 = (ts4_word)0;
        return t6;
    }
    *(ts4_word *)lbl_88D45290 = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88641248: if_call_seq lbl_880F61D0, u32@0x0, u32@0x4, fn_88640A30, fn_881992A8, lbl_880E7620 */
ts4_word ts4_if_call_seq_lbl_880F61D0_88641248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F61D0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_88640A30((ts4_word)t1);
        t3 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7620;
    *(volatile ts4_word *)lbl_88D41F80 = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x886446C8: get u32@0x4, fn_886443A0 */
ts4_word ts4_get_u32_off4_886446C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a2;
    return fn_886443A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Swing_DLL.xex 0x886451D8: if_get u32@0x0, u32@0x10 */
float ts4_if_get_u32_off0_886451D8(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    if ((int)t2 == 3) {
        return (*(float *)((char *)(ts4_word)(t1) + 8));
    }
    return (-(*(float *)((char *)(ts4_word)(t1) + 12)));
}

/* Swing_DLL.xex 0x886468F8: set u32@0x40, u32@0x44, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off40_886468F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88647190: set u32@0x1c, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off1c_88647190(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88647608: call_seq fn_88617D88, lbl_880F5FEC, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88647608(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5FEC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8864AC10: call_seq fn_88617D88, lbl_880F604C, u32@0x0, u32@0x40, g_ts4_script_constants, u32@0x4c */
ts4_word ts4_call_seq_fn_88617D88_8864AC10(ts4_word a0)
{
    float t2;

    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F604C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    t2 = *(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 224);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 36) = t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8864B3D8: if_call_seq ts4_tailcall_NetDll_inet_addr_884F0388, u32@0x88, u32@0x80, u32@0x4, ts4_tailcall_NetDll_connect_884F02B8, ts4_tailcall_NetDll_WSAGetLastError_884F0390 */
ts4_word ts4_if_call_seq_fn_884F0388_8864B3D8(ts4_word a0)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    int t4;
    int t5;

    t1 = ts4_tailcall_NetDll_inet_addr_884F0388((ts4_word)(a0 + 432));
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)t1;
    t4 = ts4_tailcall_NetDll_connect_884F02B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 4)), (ts4_word)(a0 + 132), (ts4_word)16);
    if ((int)t4 == 0) {
        p7 = (ts4_word)3;
        p8 = (ts4_word)t4;
    } else {
        t5 = ts4_tailcall_NetDll_WSAGetLastError_884F0390((ts4_word)t4);
        if ((int)t5 == 10035) {
            p6 = (ts4_word)2;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)2;
            p6 = (ts4_word)0;
        }
        p7 = (ts4_word)p6;
        p8 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p7;
    return p8;
}

/* Swing_DLL.xex 0x8864B468: if_call_seq u32@0x38, u32@0x48, u32@0x0, RtlEnterCriticalSection, u32@0x3c, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off38_8864B468(ts4_word a0)
{
    int t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t1 == 0) {
        return 0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 60))) + 8);
    ts4_msg_list_pop_882784F0((ts4_word)(a0 + 56));
    RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
    return t6;
}

/* Swing_DLL.xex 0x8864B4C8: if_call_seq u32@0x18, u32@0x28, u32@0x0, RtlEnterCriticalSection, u32@0x1c, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off18_8864B4C8(ts4_word a0)
{
    int t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 == 0) {
        return 0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8);
    ts4_msg_list_pop_882784F0((ts4_word)(a0 + 24));
    RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
    return t6;
}

/* Swing_DLL.xex 0x8864DFA8: fn  */
ts4_word ts4_fn_8864DFA8(ts4_word a0)
{
    return ((a0 + 7) & 0xfffffff8);
}

/* Swing_DLL.xex 0x8864E2B0: get  */
void ts4_get_8864E2B0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 56) = (f1 + (*(float *)((char *)(ts4_word)(a0) + 56)));
    return;
}

/* Swing_DLL.xex 0x8864E2C0: get  */
void ts4_get_8864E2C0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 52) = (f1 + (*(float *)((char *)(ts4_word)(a0) + 52)));
    return;
}

/* Swing_DLL.xex 0x8864E2D0: get  */
void ts4_get_8864E2D0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 48) = (f1 + (*(float *)((char *)(ts4_word)(a0) + 48)));
    return;
}

/* Swing_DLL.xex 0x8864F330: addr lbl_880F5848, u32@0x10, u32@0x0, u32@0x8, fn_8860BBD8 */
ts4_word ts4_addr_lbl_880F5848_8864F330(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return fn_8860BBD8((ts4_word)a0);
}

/* Swing_DLL.xex 0x8864F378: addr lbl_880F5848, u32@0x10, u32@0x0, u32@0x14, u32@0x8, fn_8860BBD8 */
ts4_word ts4_addr_lbl_880F5848_8864F378(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return fn_8860BBD8((ts4_word)a0);
}

/* Swing_DLL.xex 0x8864F3C0: addr lbl_880F5848, u32@0x10, u32@0x0, u32@0x14, u32@0x8, fn_8860BBD8 */
ts4_word ts4_addr_lbl_880F5848_8864F3C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return fn_8860BBD8((ts4_word)a0);
}

/* Swing_DLL.xex 0x8864F658: if_call_seq lbl_880F5890, u32@0x0, u32@0x10, ts4_destroy_owned_object, lbl_880F5848, u32@0x8 */
ts4_word ts4_if_call_seq_lbl_880F5890_8864F658(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5890;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x886570B8: if_get u32@0x1c, u32@0x30, vcall, u32@0x78, u32@0x0, u32@0x4c */
ts4_word ts4_if_get_u32_off1c_886570B8(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t7;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28));
    p8 = (ts4_word)t3;
    if ((ts4_word)(t3 & 0xff) != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)) == (ts4_word)a1) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88657D20: if_get u8@0x20, u8@0x21, u32@0x24, u32@0x4, vcall, fn_88657C70 */
ts4_word ts4_if_get_u8_off20_88657D20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 33)) != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 4))))((ts4_word)(a0 + 36));
        t6 = fn_88657C70((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 8))))((ts4_word)(a0 + 36));
        return t6;
    }
    return 1;
}

/* Swing_DLL.xex 0x88658828: call_seq lbl_880F51C4, u32@0x0, u32@0x4, ts4_destroy_owned_object, lbl_880F9018, u32@0x0 */
ts4_word ts4_call_seq_lbl_880F51C4_88658828(ts4_word a0)
{
    ts4_word t2;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F51C4;
    t2 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9018;
    return t2;
}

/* Swing_DLL.xex 0x88659600: if_fn  */
ts4_word ts4_if_fn_88659600(float f1, float f2, float f3, float f4)
{
    if (!(f1 < ((f2 - f3) - f4))) {
        if (!(f1 > (f2 + f4))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x886598C8: get  */
float ts4_get_886598C8(float f1, float f2)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    return (((t1 - f2) * f1) * (*(float *)lbl_8814B45C));
}

/* Swing_DLL.xex 0x88659AA0: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0xc, vcall */
ts4_word ts4_loop_get_u32_off8_88659AA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 12))))((ts4_word)t4);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88659D18: if_fn  */
ts4_word ts4_if_fn_88659D18(float f1, float f2, float f3)
{
    if (!(f1 < (f2 - f3))) {
        if (!(f1 > f2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8865A2D8: if_get u32@0x40, u8@0x0, u32@0x50, u32@0x0, u32@0xc */
ts4_word ts4_if_get_u32_off40_8865A2D8(ts4_word a0)
{
    unsigned char t2;
    ts4_word t3;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 0);
    if ((ts4_word)t2 != 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3);
}

/* Swing_DLL.xex 0x8865A300: if_get u32@0x40, u8@0x0, u32@0x50, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off40_8865A300(ts4_word a0)
{
    unsigned char t2;
    ts4_word t3;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 0);
    if ((ts4_word)t2 != 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3);
}

/* Swing_DLL.xex 0x8865A3D0: get u32@0x5a0 */
ts4_word ts4_get_u32_off5a0_8865A3D0(ts4_word a0, ts4_word a1)
{
    return ((int)(a1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 1440))) / (int)48);
}

/* Swing_DLL.xex 0x8865A430: get u32@0x5a0, u32@0x5a4 */
ts4_word ts4_get_u32_off5a0_8865A430(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1440);
    return (((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1444)) - t1) == 0);
}

/* Swing_DLL.xex 0x8865B2C0: addr lbl_880D6B70, u32@0x0, u32@0x78 */
void ts4_addr_lbl_880D6B70_8865B2C0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865B4A0: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_8865B4A0(ts4_word a0)
{
    ts4_word t1;
    float t2;
    float t3;
    float t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(float *)((char *)(ts4_word)(a0) + 192);
    t3 = *(float *)((char *)(ts4_word)(a0) + 196);
    t4 = *(float *)((char *)(ts4_word)(t1) + 112);
    if ((t4 * t2) > t3) {
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8865B4C8: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_8865B4C8(ts4_word a0)
{
    ts4_word t1;
    float t2;
    float t3;
    float t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(float *)((char *)(ts4_word)(a0) + 192);
    t3 = *(float *)((char *)(ts4_word)(a0) + 196);
    t4 = *(float *)((char *)(ts4_word)(t1) + 132);
    if ((t4 * t2) > t3) {
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8865BF60: get u32@0x20, u32@0x28, u32@0x350, u32@0x58 */
void ts4_get_u32_off20_8865BF60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(t2) + 88) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 848)) / 60);
    return;
}

/* Swing_DLL.xex 0x8865D880: if_call_seq u32@0x118, u32@0x2c, fn_8865D7D8, fn_8865D7D8 */
ts4_word ts4_if_call_seq_u32_off118_8865D880(ts4_word a0)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    int t3;
    int t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t3 = fn_8865D7D8((ts4_word)(t2 + 96), (ts4_word)(t1 + 52));
    t4 = fn_8865D7D8((ts4_word)t2, (ts4_word)t1);
    p6 = (ts4_word)t4;
    if ((int)t3 != -1) {
        p5 = (ts4_word)t4;
        if ((int)t4 == -1 || (int)t3 < (int)t4) {
            p5 = (ts4_word)t3;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8865E530: if_get u32@0x1c, u32@0x74, u8@0x5d9, u8@0x5d9 */
void ts4_if_get_u32_off1c_8865E530(ts4_word a0)
{
    ts4_word t2;
    unsigned char t3;
    float t4;
    float t5;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 1497);
    if ((ts4_word)t3 == 0) {
        t4 = *(float *)((char *)(ts4_word)(t2) + 1460);
        t5 = *(float *)lbl_8814B910;
        if (t4 > t5) {
            *(unsigned char *)((char *)(ts4_word)(t2) + 1497) = (unsigned char)1;
            return;
        }
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8865E700: if_get  */
void ts4_if_get_8865E700(ts4_word a0, ts4_word a1)
{
    if ((int)a1 == (int)((2733441024) | 41447)) {
        *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)lbl_880C88DC);
        return;
    }
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)lbl_8814B440);
    return;
}

/* Swing_DLL.xex 0x8865EAE0: get u32@0x1c, u32@0x44 */
ts4_word ts4_get_u32_off1c_8865EAE0(ts4_word a0)
{
    return (*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68));
}

/* Swing_DLL.xex 0x8865EAF0: get u32@0x28, u32@0xc */
ts4_word ts4_get_u32_off28_8865EAF0(ts4_word a0)
{
    return ((((3663003648) | 18518) - (*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40))) + 12))) == 0);
}

/* Swing_DLL.xex 0x8865EB10: if_get u32@0x74, u32@0x5c0, u32@0x2c, u32@0x2c */
ts4_word ts4_if_get_u32_off74_8865EB10(ts4_word a0)
{
    ts4_word t2;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 116))) + 1472);
    if ((ts4_word)t2 == (ts4_word)((286261248) | 29210)) {
        return ((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)) + 64);
    }
    return (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Swing_DLL.xex 0x8865EB40: get u32@0x4c, u32@0x18, u32@0x24, u32@0xb8 */
ts4_word ts4_get_u32_off4c_8865EB40(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((t2 - (*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 36))) + 184))) == 0);
}

/* Swing_DLL.xex 0x8865F0B8: get u32@0x44, u32@0x10, u32@0x54 */
ts4_word ts4_get_u32_off44_8865F0B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    return (*(volatile ts4_word *)((char *)(ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 84)) << 2)) + t2));
}

/* Swing_DLL.xex 0x8865F108: get u32@0x44, u32@0x10, u32@0x54, u32@0x4 */
ts4_word ts4_get_u32_off44_8865F108(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    return (*(volatile ts4_word *)((char *)(ts4_word)((t2 - ((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 84)) << 2))) + 4));
}

/* Swing_DLL.xex 0x8865FB60: get u32@0x4, u32@0x0, u32@0x30, u32@0x0, u32@0x310 */
ts4_word ts4_get_u32_off4_8865FB60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 48);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0);
    return (t4 - (*(volatile ts4_word *)((char *)(ts4_word)(t3) + 784)));
}

/* Swing_DLL.xex 0x8865FB80: get u32@0x4, u32@0x0, u32@0x30, u32@0x0, u32@0x310 */
ts4_word ts4_get_u32_off4_8865FB80(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 48);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0);
    return ((t4 - (*(volatile ts4_word *)((char *)(ts4_word)(t3) + 784))) == 0);
}

/* Swing_DLL.xex 0x8865FBD8: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_8865FBD8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0) = (ts4_word)((2147418112) | 65535);
    return;
}

/* Swing_DLL.xex 0x8865FBF0: get u32@0x4, u32@0x0, u32@0x30, u32@0x310, u32@0x0 */
void ts4_get_u32_off4_8865FBF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 48))) + 784)) + a1);
    return;
}

/* Swing_DLL.xex 0x8865FC10: if_get u32@0x20, u32@0xc8, u32@0x20, u32@0xd0, u32@0x20, u32@0xd8 */
void ts4_if_get_u32_off20_8865FC10(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 200) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 208) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 216) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 224) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 232) = (ts4_word)((2147418112) | 65535);
    if ((ts4_word)(a1 & 0xff) != 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 176) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 184) = (ts4_word)((2147418112) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 32))) + 192) = (ts4_word)((2147418112) | 65535);
    return;
}

/* Swing_DLL.xex 0x8865FDF0: loop_get u32@0xc, u32@0x8, u32@0x0, u32@0x8 */
void ts4_loop_get_u32_offc_8865FDF0(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return;
    }
    lv3 = (ts4_word)t2;
    do {
        *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 8) = (ts4_word)0;
        p5 = (ts4_word)(lv3 + 4);
        lv3 = p5;
    } while ((ts4_word)p5 != (ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88660420: get u32@0x4, u32@0x0, u32@0x88, u32@0x5a0 */
ts4_word ts4_get_u32_off4_88660420(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 136))) + 1440)) + ((t2 + (t2 << 1)) << 4));
}

/* Swing_DLL.xex 0x88660448: get u32@0x4, u32@0x0, u32@0x88, u32@0x5a0 */
ts4_word ts4_get_u32_off4_88660448(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 136))) + 1440)) + ((t2 + (t2 << 1)) << 4));
}

/* Swing_DLL.xex 0x886604D8: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_886604D8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1);
    return;
}

/* Swing_DLL.xex 0x886604E8: if_set u32@0x0, u32@0x4, u32@0xc, u32@0x8c, u32@0xc */
void ts4_if_set_u32_off0_886604E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = (*(float *)lbl_8814B440);
    if ((ts4_word)a2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 140));
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88660A88: set u32@0x4, u32@0x0, u32@0xc */
void ts4_set_u32_off4_88660A88(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    t1 = *(float *)lbl_8814B440;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    return;
}
