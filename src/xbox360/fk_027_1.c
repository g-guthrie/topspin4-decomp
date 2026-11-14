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

extern char g_ts4_online_state[];
extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_880C1320[];
extern char lbl_880CFF37[];
extern char lbl_880D050B[];
extern char lbl_880D052A[];
extern char lbl_880D052B[];
extern char lbl_880D19F0[];
extern char lbl_880D1F80[];
extern char lbl_880D2570[];
extern char lbl_880D257C[];
extern char lbl_880D2A30[];
extern char lbl_880D2A68[];
extern char lbl_880D2CF8[];
extern char lbl_880D2D10[];
extern char lbl_880D2D94[];
extern char lbl_880D2DBC[];
extern char lbl_880D2DEC[];
extern char lbl_880D2E18[];
extern char lbl_880D2E4C[];
extern char lbl_880D3118[];
extern char lbl_880D4B88[];
extern char lbl_880D4FD8[];
extern char lbl_880D5078[];
extern char lbl_880D50C8[];
extern char lbl_880D50F0[];
extern char lbl_880D5140[];
extern char lbl_880D5168[];
extern char lbl_880D5240[];
extern char lbl_880D566C[];
extern char lbl_880D5A64[];
extern char lbl_880D5AA0[];
extern char lbl_880D5BC0[];
extern char lbl_880D5C10[];
extern char lbl_880D5C60[];
extern char lbl_880D5CBC[];
extern char lbl_880D5EE8[];
extern char lbl_88C6B4AC[];
extern char lbl_88D3CD50[];
extern char lbl_88D45874[];
extern char lbl_88D45878[];
extern char lbl_88D45888[];
extern char lbl_88D4588C[];
extern char lbl_88D45894[];
extern char lbl_88D4589C[];
extern char lbl_88D458A0[];
extern char lbl_88D458C0[];
extern char lbl_88D458C4[];
extern char lbl_88D458D0[];
extern char lbl_88D458D8[];
extern char lbl_88D458DC[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
ts4_word fn_88150310();
ts4_word fn_88150600();
ts4_word fn_88151560();
ts4_word fn_881542F8();
ts4_word fn_88157B78();
ts4_word fn_88157C20();
ts4_word fn_88157DA8();
ts4_word fn_88157E60();
ts4_word ts4_byte_string_assign_88158908();
ts4_word fn_88159488();
ts4_word fn_88159870();
ts4_word fn_881599B8();
ts4_word ts4_call_seq_u32_off0_88159AC0();
ts4_word fn_8815B210();
ts4_word fn_8815E628();
ts4_word fn_881608E8();
ts4_word ts4_if_call_seq_u32_off8_88160D30();
ts4_word fn_88161620();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881629B0();
ts4_word fn_8816A1E8();
ts4_word ts4_chunk_reader_read_8816B5A8();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_8816D1A8();
ts4_word ts4_call_seq_fn_8816DFB8_8816D728();
ts4_word fn_881B9148();
ts4_word ts4_tailcall_NetDll_XNetXnAddrToInAddr_884EFEB8();
ts4_word ts4_tailcall_NetDll_XNetGetEthernetLinkStatus_884F0010();
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238();
ts4_word ts4_call_seq_fn_884F0238_884F1A10();
ts4_word fn_885637C0();
ts4_word fn_8857A1E0();
ts4_word ts4_tailcall_fn_8857A2A0_8857A330();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word fn_88608590();
ts4_word fn_8860DCF8();
ts4_word fn_88614938();
ts4_word fn_88617D88();
ts4_word fn_888860A0();
ts4_word fn_88932388();
ts4_word fn_88932418();
ts4_word fn_889324A0();
ts4_word fn_889333F0();
ts4_word fn_88933EF8();
ts4_word ts4_call_seq_u32_off8_889343E8();
ts4_word fn_88934458();
ts4_word fn_88934EA8();
ts4_word fn_88935D10();
ts4_word fn_88935DF8();
ts4_word fn_88935E70();
ts4_word fn_889365A8();
ts4_word fn_889369D8();
ts4_word fn_88936BB0();
ts4_word ts4_if_set_u8_off8_88936F28();
ts4_word fn_88936F98();
ts4_word fn_889375D8();
ts4_word fn_88937648();
ts4_word fn_889377F8();
ts4_word fn_88937968();
ts4_word fn_88938660();
ts4_word fn_88938740();
ts4_word fn_88938E98();
ts4_word fn_88938F38();
ts4_word fn_88939040();
ts4_word fn_88939288();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_889396A8();
ts4_word fn_889397D8();
ts4_word fn_8893A258();
ts4_word fn_8893AD90();
ts4_word fn_8893B3E0();
ts4_word fn_8893B578();
ts4_word ts4_call_seq_fn_889365A8_8893BE60();
ts4_word fn_8893C210();
ts4_word fn_8893CBE0();
ts4_word fn_8893CCE8();
ts4_word fn_8893CFD8();
ts4_word fn_8893D1D0();
ts4_word fn_8893D2A0();
ts4_word fn_8893EB50();
ts4_word ts4_if_get_u32_off0_88940970();
ts4_word ts4_if_get_u32_off0_88940A88();
ts4_word ts4_get_u32_off434_88941198();
ts4_word fn_88941B30();
ts4_word fn_88943E70();
ts4_word fn_88946348();
ts4_word fn_88947768();
ts4_word ts4_name_keys_register_88954210();
ts4_word fn_88955818();
ts4_word fn_88956170();
ts4_word fn_88956B20();
ts4_word fn_889581B0();
ts4_word fn_88959880();
ts4_word fn_88960528();
ts4_word fn_88963BF0();
ts4_word fn_88969230();
ts4_word fn_889695A8();
ts4_word fn_8896B820();
ts4_word ts4_call_seq_fn_8816D1A8_88977CD0();
ts4_word fn_889781B0();
ts4_word fn_8897DCC0();
ts4_word fn_88987938();
ts4_word fn_88987D68();
ts4_word fn_8898BC00();
ts4_word fn_8898FE30();
ts4_word fn_8898FEB0();
ts4_word fn_88991DA8();
ts4_word fn_88994740();
ts4_word fn_88997318();
ts4_word fn_889989A0();
ts4_word fn_88999520();
ts4_word fn_889997C8();
ts4_word ts4_keyed_item_add_or_remove_889998A8();
ts4_word ts4_keyed_item_add_or_remove_88999C30();
ts4_word ts4_call_seq_lbl_880D2570_8899A0D8();
ts4_word fn_8899A158();
ts4_word fn_8899A270();
ts4_word fn_8899A3C0();
ts4_word fn_8899A4B8();
ts4_word ts4_if_call_seq_u8_off42c_8899A558();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8893D5A0: addr lbl_88D3CD50, ts4_call_seq_fn_889365A8_8893BE60, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_8893D5A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = ts4_call_seq_fn_889365A8_8893BE60((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_8893D1D0((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x8893D630: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, ts4_call_seq_fn_889365A8_8893BE60, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_8893D630(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1108, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = ts4_call_seq_fn_889365A8_8893BE60((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x88940CA0: if_get u32@0x0, u32@0x40, vcall, u32@0x0, u32@0x44, vcall */
ts4_word ts4_if_get_u32_off0_88940CA0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t7;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)a1);
        p8 = (ts4_word)1;
    } else {
        t7 = ts4_if_get_u32_off0_88940970((ts4_word)a0, (ts4_word)a1);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x889462F0: if_call_seq u32@0x0, fn_88943E70, ts4_if_get_u32_off0_88940A88 */
ts4_word ts4_if_call_seq_u32_off0_889462F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88943E70((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    if ((ts4_word)t2 != 0) {
        t3 = ts4_if_get_u32_off0_88940A88((ts4_word)t2, (ts4_word)a2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88978968: call_seq fn_88617D88, lbl_880D566C, u32@0x0, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_88978968(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D566C;
    fn_8816D1A8((ts4_word)(a0 + 32));
    fn_8816D1A8((ts4_word)(a0 + 44));
    fn_8816D1A8((ts4_word)(a0 + 56));
    fn_8816D1A8((ts4_word)(a0 + 68));
    fn_8816D1A8((ts4_word)(a0 + 80));
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)0;
    ts4_call_seq_fn_8816D1A8_88977CD0((ts4_word)(a0 + 128));
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)lbl_88D45888 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x8898BD48: if_call_seq fn_8898BC00, ts4_get_u32_off434_88941198, u32@lbl_88D458C4, u8@0xc, u32@lbl_88D45894, fn_88987938 */
ts4_word ts4_if_call_seq_fn_8898BC00_8898BD48(ts4_word a0)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word p12;
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    ts4_word t6;

    fn_8898BC00();
    t2 = ts4_get_u32_off434_88941198((ts4_word)a0);
    t3 = *(ts4_word *)lbl_88D458C4;
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 12);
    p12 = (ts4_word)t2;
    if ((ts4_word)t4 != 0) {
        t5 = *(ts4_word *)lbl_88D45894;
        p8 = (ts4_word)t3;
        p9 = (ts4_word)t5;
        if ((ts4_word)t5 != 0) {
            t6 = fn_88987938((ts4_word)t5, (ts4_word)1);
            p8 = (ts4_word)(*(ts4_word *)lbl_88D458C4);
            p9 = (ts4_word)t6;
        }
        *(unsigned char *)((char *)(ts4_word)(p8) + 12) = (unsigned char)0;
        p12 = (ts4_word)p9;
    }
    return p12;
}

/* Swing_DLL.xex 0x88994B28: call_seq fn_881599B8, fn_88994740, fn_88159870 */
ts4_word ts4_call_seq_fn_881599B8_88994B28(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_881599B8((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_88994740((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 2872), (ts4_word)(a0 + 2876), (ts4_word)(a0 + 2880), (ts4_word)a0, (ts4_word)(a0 + 48));
    fn_88159870((ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x889992E8: call_seq u32@0x2c, fn_8857A1E0, ts4_call_seq_fn_884F0238_884F1A10, ts4_if_set_u8_off8_88936F28 */
ts4_word ts4_call_seq_u32_off2c_889992E8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
    ts4_call_seq_fn_884F0238_884F1A10((ts4_word)t2);
    t4 = ts4_if_set_u8_off8_88936F28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8899A9A0: tailcall ts4_if_call_seq_u8_off42c_8899A558 */
ts4_word ts4_tailcall_fn_8899A558_8899A9A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_if_call_seq_u8_off42c_8899A558((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8899B270: addr lbl_880D052B, ts4_call_seq_lbl_880D2570_8899A0D8 */
ts4_word ts4_addr_lbl_880D052B_8899B270(void)
{
    return ts4_call_seq_lbl_880D2570_8899A0D8((ts4_word)(ts4_word)lbl_880D052B);
}

/* Swing_DLL.xex 0x8899B280: addr lbl_880D052A, ts4_call_seq_lbl_880D2570_8899A0D8 */
ts4_word ts4_addr_lbl_880D052A_8899B280(void)
{
    return ts4_call_seq_lbl_880D2570_8899A0D8((ts4_word)(ts4_word)lbl_880D052A);
}

