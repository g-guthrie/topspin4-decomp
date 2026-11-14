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

extern char g_ts4_script_constants[];
extern char lbl_880C88D9[];
extern char lbl_880C88DA[];
extern char lbl_880D6B70[];
extern char lbl_880F436C[];
extern char lbl_880F43E0[];
extern char lbl_880F4508[];
extern char lbl_880F4518[];
extern char lbl_880F45D0[];
extern char lbl_880F4640[];
extern char lbl_880F46B8[];
extern char lbl_880F4804[];
extern char lbl_880F482C[];
extern char lbl_880F48B8[];
extern char lbl_880F4900[];
extern char lbl_880F4948[];
extern char lbl_880F4990[];
extern char lbl_880F49D8[];
extern char lbl_880F4A20[];
extern char lbl_880F4E04[];
extern char lbl_880F4E40[];
extern char lbl_880F4E54[];
extern char lbl_880F4FD0[];
extern char lbl_880F4FDC[];
extern char lbl_880F51E0[];
extern char lbl_880F5848[];
extern char lbl_880F5860[];
extern char lbl_880F5878[];
extern char lbl_880F5890[];
extern char lbl_880F7AEC[];
extern char lbl_8814B440[];
extern char lbl_88C6CE84[];
extern char lbl_88CACF08[];
extern char lbl_88D429F0[];
extern char lbl_88D45B0C[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_88151A70();
ts4_word fn_88176CD0();
ts4_word fn_881B8360();
ts4_word fn_881B9148();
ts4_word fn_8825D450();
ts4_word fn_8826B328();
ts4_word fn_88278450();
ts4_word ts4_msg_list_pop_882784F0();
ts4_word fn_884022C0();
ts4_word fn_884060F0();
ts4_word fn_8841A510();
ts4_word fn_8841A820();
ts4_word ts4_tailcall_NetDll_socket_884F0240();
ts4_word ts4_tailcall_NetDll_ioctlsocket_884F0268();
ts4_word ts4_tailcall_NetDll_connect_884F02B8();
ts4_word ts4_tailcall_NetDll_recv_884F0318();
ts4_word ts4_tailcall_NetDll_send_884F0350();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857A1E0();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word fn_8857C040();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_88613268();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word ts4_if_get_u32_off0_88644860();
ts4_word fn_88644A48();
ts4_word fn_88644AE0();
ts4_word fn_88644BD0();
ts4_word fn_886456A0();
ts4_word fn_88645A68();
ts4_word fn_88646388();
ts4_word fn_886465A0();
ts4_word fn_88646928();
ts4_word ts4_if_get_u32_off0_88647668();
ts4_word fn_886480B0();
ts4_word ts4_if_call_seq_u32_off28_88648740();
ts4_word fn_88648998();
ts4_word ts4_call_seq_u32_lbl_88D45B20_886496F0();
ts4_word fn_88649A90();
ts4_word fn_8864B528();
ts4_word fn_8864BAE8();
ts4_word fn_8864CF98();
ts4_word ts4_msg_pool_service_get_8864DFF0();
ts4_word fn_8864E310();
ts4_word fn_88655718();
ts4_word fn_88655BC8();
ts4_word fn_88658B90();
ts4_word fn_8865A938();
ts4_word fn_8865A9C8();
ts4_word fn_8865D6E8();
ts4_word fn_88669C30();
ts4_word fn_8866BDD8();
ts4_word fn_8866DD78();
ts4_word fn_8866E250();
ts4_word fn_88674ED0();
ts4_word fn_888860A0();
ts4_word fn_8890DDA8();
ts4_word fn_8890E088();
ts4_word fn_8892AFF0();
ts4_word fn_8899F760();
ts4_word fn_889BD910();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_keyed_item_list_add_unique_88657AE0();
ts4_word ts4_keyed_item_list_add_unique_88657EB8();
ts4_word ts4_keyed_item_list_add_unique_if_mode_886487A0();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88649058();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88890F50();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88646210: if_call_seq u32@0x2c, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A820, u32@0x2c, u32@0x28 */
ts4_word ts4_if_call_seq_u32_off2c_88646210(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A820((ts4_word)t3, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t6 != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A820((ts4_word)t8, (ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t11 != 0) {
        ts4_if_get_u32_off0_88644860((ts4_word)a0);
    }
    t14 = ts4_object_finalize((ts4_word)(a0 + 16));
    return t14;
}

/* Swing_DLL.xex 0x88647708: call_seq ts4_if_get_u32_off0_88647668, u32@0x34, u32@0x4 */
ts4_word ts4_call_seq_fn_88647668_88647708(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_if_get_u32_off0_88647668((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    return t1;
}

/* Swing_DLL.xex 0x886492F0: if_get ts4_if_call_seq_u32_off28_88648740, u32@0xa0, u32@0x0, u32@0x0, vcall, u32@0xa0 */
ts4_word ts4_if_get_fn_88648740_886492F0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    ts4_if_call_seq_u32_off28_88648740((ts4_word)(a0 + 112));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 160);
    p6 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8864A0A8: addr lbl_880C88DA, ts4_call_seq_u32_lbl_88D45B20_886496F0 */
ts4_word ts4_addr_lbl_880C88DA_8864A0A8(void)
{
    return ts4_call_seq_u32_lbl_88D45B20_886496F0((ts4_word)(ts4_word)lbl_880C88DA);
}

/* Swing_DLL.xex 0x8864A0B8: addr lbl_880C88D9, ts4_call_seq_u32_lbl_88D45B20_886496F0 */
ts4_word ts4_addr_lbl_880C88D9_8864A0B8(void)
{
    return ts4_call_seq_u32_lbl_88D45B20_886496F0((ts4_word)(ts4_word)lbl_880C88D9);
}

/* Swing_DLL.xex 0x8864A160: call_seq lbl_880C88DA, ts4_call_seq_u32_lbl_88D45B20_886496F0, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C88DA_8864A160(ts4_word a0)
{
    ts4_word t2;

    ts4_call_seq_u32_lbl_88D45B20_886496F0((ts4_word)(ts4_word)lbl_880C88DA);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

