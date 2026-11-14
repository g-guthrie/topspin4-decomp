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
ts4_word fn_88158908();
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
ts4_word fn_8816B5A8();
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
ts4_word fn_8893C210();
ts4_word fn_8893CBE0();
ts4_word fn_8893CCE8();
ts4_word fn_8893CFD8();
ts4_word fn_8893D1D0();
ts4_word fn_8893D2A0();
ts4_word fn_8893EB50();
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
ts4_word fn_889781B0();
ts4_word fn_8897DCC0();
ts4_word fn_88987938();
ts4_word fn_88987D68();
ts4_word fn_8898BC00();
ts4_word fn_8898FE30();
ts4_word fn_8898FEB0();
ts4_word fn_88991DA8();
ts4_word fn_88994740();
ts4_word ts4_call_seq_fn_881599B8_88994B28();
ts4_word fn_88997318();
ts4_word fn_889989A0();
ts4_word fn_88999520();
ts4_word fn_889997C8();
ts4_word fn_889998A8();
ts4_word fn_88999C30();
ts4_word fn_8899A158();
ts4_word fn_8899A270();
ts4_word fn_8899A3C0();
ts4_word fn_8899A4B8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88936CE8: if_get u32@0x0, u32@0x0, u32@0x10, vcall, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_88936CE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)(((t2 + 7)) >> 3));
    if ((ts4_word)(t4 & 0xff) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    }
    return t4;
}

/* Swing_DLL.xex 0x88936F28: if_set u8@0x8, fn_881B9148, u32@0x1c, u32@g_ts4_session_context, u32@0x0, u32@0x60 */
ts4_word ts4_if_set_u8_off8_88936F28(ts4_word a0)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p7 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)g_ts4_session_context;
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 96))))((ts4_word)t3, (ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return p7;
}

/* Swing_DLL.xex 0x88937010: call_seq fn_88617D88, lbl_880D5C60, u32@0x1c, u32@0x0, u32@0x20, u32@g_ts4_online_state */
ts4_word ts4_call_seq_fn_88617D88_88937010(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5C60;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)g_ts4_online_state = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88938148: tailcall fn_88937968 */
ts4_word ts4_tailcall_fn_88937968_88938148(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88937968((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88938360: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889365A8, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_88938360(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1080, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889365A8((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x88938980: call_seq fn_88935E70, fn_88935E70, fn_88935E70, fn_88157B78, fn_88157B78, fn_88157B78 */
ts4_word ts4_call_seq_fn_88935E70_88938980(ts4_word a0)
{
    ts4_word t6;

    fn_88935E70();
    fn_88935E70((ts4_word)(a0 + 8));
    fn_88935E70((ts4_word)(a0 + 16));
    fn_88157B78((ts4_word)(a0 + 16));
    fn_88157B78((ts4_word)(a0 + 8));
    t6 = fn_88157B78((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88938A78: tailcall fn_88936BB0 */
ts4_word ts4_tailcall_fn_88936BB0_88938A78(ts4_word a0, ts4_word a1)
{
    return fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x88938DA0: call_seq u32@0x4, u32@0x8, lbl_880D5EE8, u32@0x0, u32@g_ts4_session_context, u32@0xc */
ts4_word ts4_call_seq_u32_off4_88938DA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5EE8;
    fn_889369D8((ts4_word)(a0 + 12), (ts4_word)a3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a4;
    return a0;
}

/* Swing_DLL.xex 0x889398B8: if_call_seq fn_88933EF8, fn_88938E98 */
ts4_word ts4_if_call_seq_fn_88933EF8_889398B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88933EF8((ts4_word)a0, (ts4_word)8);
    if ((ts4_word)(t1 & 0xff) != 0) {
        fn_88938E98((ts4_word)a0, (ts4_word)a1);
    }
    return a0;
}

/* Swing_DLL.xex 0x88939A38: call_seq fn_88939040, fn_88939040 */
ts4_word ts4_call_seq_fn_88939040_88939A38(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_88939040((ts4_word)a1, (ts4_word)(a0 + 8), (ts4_word)4);
    t2 = fn_88939040((ts4_word)a1, (ts4_word)(a0 + 6), (ts4_word)2);
    return t2;
}

/* Swing_DLL.xex 0x88939A90: call_seq fn_88939470, fn_88936BB0 */
ts4_word ts4_call_seq_fn_88939470_88939A90(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)2);
    t2 = fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1072));
    return t2;
}

/* Swing_DLL.xex 0x88939AE0: call_seq fn_88939288, fn_88939470, fn_889395D8, u32@0x40c, fn_88938F38 */
ts4_word ts4_call_seq_fn_88939288_88939AE0(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    fn_88939288((ts4_word)a1, (ts4_word)(a0 + 4), (ts4_word)1);
    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 8), (ts4_word)3);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1036));
    t5 = fn_88938F38((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1036)));
    return t5;
}

/* Swing_DLL.xex 0x8893A9B0: get u16@0x0, fn_889397D8 */
ts4_word ts4_get_u16_off0_8893A9B0(ts4_word a0, ts4_word a1)
{
    return fn_889397D8((ts4_word)a1, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8893AF28: call_seq lbl_880D5BC0, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u16@0x10 */
ts4_word ts4_call_seq_lbl_880D5BC0_8893AF28(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5BC0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    ts4_call_seq_fn_8816DFB8_8816D728((ts4_word)(a0 + 24));
    ts4_call_seq_fn_8816DFB8_8816D728((ts4_word)(a0 + 40));
    t3 = fn_8893A258((ts4_word)(a0 + 72));
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 104) = (unsigned char)0;
    t4 = ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t3);
    *(unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)t4;
    ts4_object_finalize((ts4_word)(a0 + 24));
    return a0;
}

/* Swing_DLL.xex 0x8893B190: if_call_seq u32@0x1c, fn_88935E70, fn_88935E70, fn_88935E70, fn_88157B78, fn_88157B78 */
ts4_word ts4_if_call_seq_u32_off1c_8893B190(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_88935E70((ts4_word)t1);
        fn_88935E70((ts4_word)(t1 + 8));
        fn_88935E70((ts4_word)(t1 + 16));
        fn_88157B78((ts4_word)(t1 + 16));
        fn_88157B78((ts4_word)(t1 + 8));
        fn_88157B78((ts4_word)t1);
        t8 = ts4_tsu_cleanup_end((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p9 = (ts4_word)t8;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    return p9;
}

/* Swing_DLL.xex 0x8893B9D8: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_8893B9D8(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x8893B9E8: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8893B9E8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8893BA38: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_8893BA38(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x8893BA48: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8893BA48(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8893BA98: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_8893BA98(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x8893BAA8: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, ts4_get_u32__imp_KeTimeStampBundle_8857B830 */
ts4_word ts4_get_u32_off0_8893BAA8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    t5 = fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t5);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)t6);
    return t7;
}

/* Swing_DLL.xex 0x8893BE60: call_seq fn_889365A8, lbl_880D5CBC, u32@0x438, u32@0x0, u32@0x43c, u8@0x440 */
ts4_word ts4_call_seq_fn_889365A8_8893BE60(ts4_word a0)
{
    fn_889365A8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1080) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5CBC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1084) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1088) = (unsigned char)0;
    ts4_call_seq_fn_8816DFB8_8816D728((ts4_word)(a0 + 1092));
    ts4_object_finalize((ts4_word)(a0 + 1092));
    return a0;
}

/* Swing_DLL.xex 0x8893BEC8: get fn_889395D8, fn_889395D8, u32@0x42c, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_fn_889395D8_8893BEC8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t6;

    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8893C018: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8893C018(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t9 = fn_889397D8((ts4_word)a1, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 1072)));
    return t9;
}

/* Swing_DLL.xex 0x8893C4F0: tailcall fn_8893C210 */
ts4_word ts4_tailcall_fn_8893C210_8893C4F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8893C210((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8893CB80: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8893CB80(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1068))) + 4))))((ts4_word)(a0 + 1068), (ts4_word)a1);
    return t8;
}

/* Swing_DLL.xex 0x8893CFD0: get u8@0x42c, fn_8893AD90 */
ts4_word ts4_get_u8_off42c_8893CFD0(ts4_word a0, ts4_word a1)
{
    return fn_8893AD90((ts4_word)a0, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 1068)));
}

/* Swing_DLL.xex 0x8893D160: get u32@0x68, fn_8893CFD8 */
ts4_word ts4_get_u32_off68_8893D160(ts4_word a0, ts4_word a1)
{
    return fn_8893CFD8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104)));
}

/* Swing_DLL.xex 0x8893D168: get u32@0x68, fn_8893CFD8, u32@0x0, u32@0x68, u32@0x40, vcall */
ts4_word ts4_get_u32_off68_8893D168(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 104);
    loc50[0] = (ts4_word)((2804154368) | 1986);
    fn_8893CFD8((ts4_word)a0, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 104);
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 64))))((ts4_word)a0, (ts4_word)t4);
    return t6;
}

/* Swing_DLL.xex 0x8893D618: tailcall fn_8893D1D0 */
ts4_word ts4_tailcall_fn_8893D1D0_8893D618(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8893D1D0((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8893DE98: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8893DE98(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8893E208: if_call_seq u32@0x20, ts4_destroy_owned_object, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off20_8893E208(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    return t5;
}

/* Swing_DLL.xex 0x8893E260: addr lbl_880D050B, fn_8893CBE0 */
ts4_word ts4_addr_lbl_880D050B_8893E260(void)
{
    return fn_8893CBE0((ts4_word)(ts4_word)lbl_880D050B);
}

/* Swing_DLL.xex 0x8893E270: addr lbl_880CFF37, fn_8893CBE0 */
ts4_word ts4_addr_lbl_880CFF37_8893E270(void)
{
    return fn_8893CBE0((ts4_word)(ts4_word)lbl_880CFF37);
}

/* Swing_DLL.xex 0x8893E880: call_seq lbl_880D050B, u32@lbl_88D458DC, fn_8893CBE0, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880D050B_8893E880(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)lbl_88D458DC = (ts4_word)0;
    fn_8893CBE0((ts4_word)(ts4_word)lbl_880D050B);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x8893F130: addr lbl_88D3CD50, fn_889365A8, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_8893F130(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889365A8((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_8893EB50((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x8893F1A8: tailcall fn_8893EB50 */
ts4_word ts4_tailcall_fn_8893EB50_8893F1A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8893EB50((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8893F5D8: if_get u32@0x50, u32@0x4, vcall, u32@0x7c, u32@0x80, fn_8816A1E8 */
ts4_word ts4_if_get_u32_off50_8893F5D8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t11;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 4))))((ts4_word)(a0 + 80));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t6 = fn_8816A1E8((ts4_word)t4, (ts4_word)t5, (ts4_word)a1);
    if ((ts4_word)t6 == (ts4_word)t5) {
        ts4_if_call_seq_u32_off8_88160D30((ts4_word)(a0 + 124), (ts4_word)a1);
    }
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 8))))((ts4_word)(a0 + 80));
    return t11;
}

/* Swing_DLL.xex 0x8893F650: if_get u32@0x50, u32@0x4, vcall, u32@0x70, u32@0x74, fn_8816A1E8 */
ts4_word ts4_if_get_u32_off50_8893F650(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t11;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 4))))((ts4_word)(a0 + 80));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    t6 = fn_8816A1E8((ts4_word)t4, (ts4_word)t5, (ts4_word)a1);
    if ((ts4_word)t6 == (ts4_word)t5) {
        ts4_if_call_seq_u32_off8_88160D30((ts4_word)(a0 + 112), (ts4_word)a1);
    }
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 8))))((ts4_word)(a0 + 80));
    return t11;
}

/* Swing_DLL.xex 0x8893FA30: call_seq ts4_object_finalize, ts4_object_finalize, u32@0x8c, u32@0x88, fn_88150310, u32@0x74 */
ts4_word ts4_call_seq_ts4_object_finalize_8893FA30(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;

    ts4_object_finalize((ts4_word)(a0 + 32));
    ts4_object_finalize((ts4_word)(a0 + 44));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    fn_88150310((ts4_word)(a0 + 136), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 136)), (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    fn_88150310((ts4_word)(a0 + 112), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)), (ts4_word)t6);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    fn_88150310((ts4_word)(a0 + 124), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)), (ts4_word)t9);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t12 = fn_881B9148((ts4_word)(a0 + 16));
    return t12;
}

/* Swing_DLL.xex 0x88940520: call_seq u32@0x4, fn_8816D1A8, u32@0x20, u32@0x24, u32@0x28, u8@0x1c */
ts4_word ts4_call_seq_u32_off4_88940520(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 8), (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88940820: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_88940820(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940838: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_88940838(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940850: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_88940850(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940868: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_88940868(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940880: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_88940880(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940898: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_88940898(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x889408B0: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_889408B0(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x889408C8: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_889408C8(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x889408E0: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_889408E0(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x889408F8: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_889408F8(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940910: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_88940910(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940928: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_88940928(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940940: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_88940940(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940958: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_88940958(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x88940970: if_get u32@0x0, u32@0x40, vcall, u32@0x0, u32@0x44, vcall */
ts4_word ts4_if_get_u32_off0_88940970(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)a1);
    }
    return 1;
}

/* Swing_DLL.xex 0x889409E0: get u32@0x0, u32@0x30, vcall */
ts4_word ts4_get_u32_off0_889409E0(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    return ((t3 & 0xff) == 0);
}

/* Swing_DLL.xex 0x88940A18: if_get u32@0x0, u32@0x30, vcall, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_off0_88940A18(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)a1);
    }
    return 1;
}

/* Swing_DLL.xex 0x88940A88: if_get u32@0x0, u32@0x38, vcall, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_off0_88940A88(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
    if ((int)t3 != -1) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)0, (ts4_word)t3);
    }
    return ((t3 + 1) != 0);
}

/* Swing_DLL.xex 0x88940F00: if_get u32@0x24 */
ts4_word ts4_if_get_u32_off24_88940F00(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        return (t1 + 16);
    }
    return 0;
}

/* Swing_DLL.xex 0x88940F18: get u32@0x24 */
ts4_word ts4_get_u32_off24_88940F18(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x88940F20: if_get u32@0x24 */
ts4_word ts4_if_get_u32_off24_88940F20(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        return (t1 + 28);
    }
    return 0;
}

/* Swing_DLL.xex 0x88940F38: if_get u32@0x24 */
ts4_word ts4_if_get_u32_off24_88940F38(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        return (t1 + 40);
    }
    return 0;
}

/* Swing_DLL.xex 0x88940F50: get u32@0x60, u32@0x0, u32@0x2c, vcall, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off60_88940F50(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(a0 + 44), (ts4_word)1, (ts4_word)0);
    t5 = loc50[0];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 4))))((ts4_word)t5, (ts4_word)a1, (ts4_word)20);
    t9 = loc50[0];
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 88))))((ts4_word)t10, (ts4_word)(ts4_word)&loc50[0]);
    return t8;
}

/* Swing_DLL.xex 0x889410D0: set u32@0x98, u32@0x9c */
void ts4_set_u32_off98_889410D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)(a1 + 12);
    return;
}

/* Swing_DLL.xex 0x889410E0: get u32@0x434, u32@0x14, vcall, u32@0x1e4, u32@0x14, vcall */
ts4_word ts4_get_u32_off434_889410E0(ts4_word a0)
{
    ts4_word t21;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1076))) + 20))))((ts4_word)(a0 + 1076));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 484))) + 20))))((ts4_word)(a0 + 484));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 292))) + 20))))((ts4_word)(a0 + 292));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 20))))((ts4_word)(a0 + 340));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1168))) + 20))))((ts4_word)(a0 + 1168));
    t21 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1288))) + 20))))((ts4_word)(a0 + 1288));
    return t21;
}

/* Swing_DLL.xex 0x88941198: get u32@0x434, u32@0x8, vcall, u32@0x1e4, u32@0x8, vcall */
ts4_word ts4_get_u32_off434_88941198(ts4_word a0)
{
    ts4_word t21;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1076))) + 8))))((ts4_word)(a0 + 1076));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 484))) + 8))))((ts4_word)(a0 + 484));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 292))) + 8))))((ts4_word)(a0 + 292));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 8))))((ts4_word)(a0 + 340));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1168))) + 8))))((ts4_word)(a0 + 1168));
    t21 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1288))) + 8))))((ts4_word)(a0 + 1288));
    return t21;
}

/* Swing_DLL.xex 0x88941820: if_set u32@0x218, u32@0x0, u32@lbl_88D458C0, u32@0x218, u32@0x218 */
void ts4_if_set_u32_off218_88941820(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)lbl_88D458C0;
    if ((ts4_word)t1 == (ts4_word)((4122935296) | 20375)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)(t2 + 300);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)(t2 + 500);
    return;
}

/* Swing_DLL.xex 0x88942440: if_get u32@lbl_88D458C0, u32@0x28, u32@0x0, u32@0x2c, u32@0x2c */
void ts4_if_get_u32_lbl_88D458C0_88942440(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D458C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t2 == (ts4_word)((4122935296) | 20375)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(t1 + 240);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(t1 + 440);
    return;
}

/* Swing_DLL.xex 0x88942BD8: if_set u8@0x554, u8@0x555, u8@0x554, u8@0x555 */
void ts4_if_set_u8_off554_88942BD8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == (ts4_word)((499777536) | 29317)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 1364) = (unsigned char)1;
        *(unsigned char *)((char *)(ts4_word)(a0) + 1365) = (unsigned char)0;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 1364) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1365) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88943870: call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30 */
ts4_word ts4_call_seq_u32_off0_88943870(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x889438C8: call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30 */
ts4_word ts4_call_seq_u32_off0_889438C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88943920: call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30 */
ts4_word ts4_call_seq_u32_off0_88943920(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88943A48: call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30 */
ts4_word ts4_call_seq_u32_off0_88943A48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88943C40: if_get u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88943C40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t5 != 0) {
        t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 48))))((ts4_word)t5);
        p9 = (ts4_word)t8;
    } else {
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x889445F8: call_seq u32@0x8, fn_8816B5A8 */
ts4_word ts4_call_seq_u32_off8_889445F8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_8816B5A8((ts4_word)(a0 + 112), (ts4_word)(ts4_word)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x889453E0: call_seq ts4_object_finalize, fn_88161620, fn_88161620, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_ts4_object_finalize_889453E0(ts4_word a0)
{
    ts4_word t4;

    ts4_object_finalize((ts4_word)(a0 + 44));
    fn_88161620((ts4_word)(a0 + 56));
    fn_88161620((ts4_word)(a0 + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t4 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t4;
}

/* Swing_DLL.xex 0x88945458: if_get u32@0x84, u32@0x0, u32@0x8, vcall, u32@0x84, u32@0x88 */
ts4_word ts4_if_get_u32_off84_88945458(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;
    ts4_word t16;
    ts4_word t26;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t6 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 8))))((ts4_word)t6, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    if ((ts4_word)t11 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 8))))((ts4_word)t11, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t16 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 8))))((ts4_word)t16, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    }
    ts4_object_finalize((ts4_word)(a0 + 148));
    fn_88161620((ts4_word)(a0 + 160));
    fn_88161620((ts4_word)(a0 + 172));
    fn_88161620((ts4_word)(a0 + 184));
    fn_88161620((ts4_word)(a0 + 196));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t26 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t26;
}

/* Swing_DLL.xex 0x889456D0: if_get u32@0x50, u32@0x0, u32@0x8, vcall, u32@0x50, ts4_object_finalize */
ts4_word ts4_if_get_u32_off50_889456D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    }
    ts4_object_finalize((ts4_word)(a0 + 88));
    fn_88161620((ts4_word)(a0 + 100));
    fn_88161620((ts4_word)(a0 + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t9 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t9;
}

/* Swing_DLL.xex 0x88945A10: call_seq fn_88617D88, lbl_880D50F0, u32@0x1c, u32@0x0, u32@0x20, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_88945A10(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D50F0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((983040) | 65535);
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    *(ts4_word *)lbl_88D458D8 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88945DA8: call_seq fn_88617D88, lbl_880D5168, u32@0x0, u32@lbl_88D458A0 */
ts4_word ts4_call_seq_fn_88617D88_88945DA8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5168;
    *(ts4_word *)lbl_88D458A0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88946F70: get u32@lbl_88D45B1C, u32@0x27c, fn_88946348 */
ts4_word ts4_get_u32_lbl_88D45B1C_88946F70(ts4_word a0, ts4_word a1)
{
    return fn_88946348((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636)));
}

/* Swing_DLL.xex 0x88946F88: tailcall fn_88946348 */
ts4_word ts4_tailcall_fn_88946348_88946F88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88946348((ts4_word)a0, (ts4_word)a1, (ts4_word)1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88947720: call_seq fn_88617D88, lbl_880D4B88, u32@0x0, u32@lbl_88D4588C */
ts4_word ts4_call_seq_fn_88617D88_88947720(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4B88;
    *(ts4_word *)lbl_88D4588C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88947FD0: call_seq fn_88617D88, lbl_880D5078, u32@0x0, u32@lbl_88D45878 */
ts4_word ts4_call_seq_fn_88617D88_88947FD0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5078;
    *(ts4_word *)lbl_88D45878 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x889558F0: addr lbl_880D5240, u32@0x0, fn_88955818 */
ts4_word ts4_addr_lbl_880D5240_889558F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5240;
    return fn_88955818((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D5240);
}

/* Swing_DLL.xex 0x88955D78: call_seq fn_88617D88, lbl_880D5140, u32@0x0, fn_8816D1A8, u32@lbl_88D458D0 */
ts4_word ts4_call_seq_fn_88617D88_88955D78(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5140;
    fn_8816D1A8((ts4_word)(a0 + 28));
    *(ts4_word *)lbl_88D458D0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x889565A0: if_get u32@0x60, u32@0x0, u32@0x48, vcall, u32@0x0, u32@0x3c */
ts4_word ts4_if_get_u32_off60_889565A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1);
    if ((ts4_word)(t4 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)a1);
    }
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)a1, (ts4_word)3, (ts4_word)0);
    t12 = loc50[0];
    fn_88947768((ts4_word)t12, (ts4_word)a3, (ts4_word)a2);
    t14 = loc50[0];
    t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 4);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 88))))((ts4_word)t15, (ts4_word)(ts4_word)&loc50[0]);
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return 1;
}

/* Swing_DLL.xex 0x88956CC8: call_seq fn_88617D88, lbl_880D50C8, u32@0x0, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_88956CC8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D50C8;
    fn_8816D1A8((ts4_word)(a0 + 28));
    fn_8816D1A8((ts4_word)(a0 + 40));
    fn_8816D1A8((ts4_word)(a0 + 52));
    fn_8816D1A8((ts4_word)(a0 + 64));
    *(ts4_word *)lbl_88D45874 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88957538: get u32@0x2c, u32@0xec, fn_88956B20 */
ts4_word ts4_get_u32_off2c_88957538(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    return fn_88956B20((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 236)), (ts4_word)(a0 + 148), (ts4_word)(a0 + 172), (ts4_word)(a0 + 160), (ts4_word)t1);
}

/* Swing_DLL.xex 0x889575F0: tailcall ts4_name_keys_register_88954210 */
ts4_word ts4_tailcall_fn_88954210_889575F0(ts4_word a0)
{
    return ts4_name_keys_register_88954210((ts4_word)a0);
}

/* Swing_DLL.xex 0x88957DE8: set u32@0x3c, fn_88956170 */
ts4_word ts4_set_u32_off3c_88957DE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return fn_88956170((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88958098: set u32@0x3c, fn_88956170 */
ts4_word ts4_set_u32_off3c_88958098(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return fn_88956170((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88958580: if_call_seq u32@0x4, u32@0x0, fn_881608E8, ts4_if_call_seq_u32_off0_8816D140, ts4_destroy_owned_object, lbl_880C1320 */
ts4_word ts4_if_call_seq_u32_off4_88958580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)(t1 - t2) > 5) {
        t3 = fn_881608E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)2, (ts4_word)3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 - t2), (ts4_word)t2);
        ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t3);
        t5 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t5);
    } else {
        ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 - t2), (ts4_word)t2);
    }
    return a0;
}

/* Swing_DLL.xex 0x889585F8: call_seq fn_88617D88, lbl_880D4FD8, u32@0x0, fn_8816D1A8, lbl_880C1320, ts4_assign_formatted_text */
ts4_word ts4_call_seq_fn_88617D88_889585F8(ts4_word a0)
{
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4FD8;
    fn_8816D1A8((ts4_word)(a0 + 40));
    ts4_assign_formatted_text((ts4_word)(a0 + 52), (ts4_word)(ts4_word)lbl_880C1320);
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    t4 = ts4_if_call_seq_u32_lbl_88D45B38_881629B0((ts4_word)(a0 + 68), (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(t4) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 68))) + 4) = (ts4_word)0;
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)t6;
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)lbl_88D4589C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88959918: call_seq u8@0x8, fn_881B9148, fn_88959880 */
ts4_word ts4_call_seq_u8_off8_88959918(ts4_word a0)
{
    ts4_word t2;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = fn_88959880((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8895DA28: set u32@0x3c, fn_88956170 */
ts4_word ts4_set_u32_off3c_8895DA28(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return fn_88956170((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8895DA30: set u32@0x3c, fn_88956170 */
ts4_word ts4_set_u32_off3c_8895DA30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return fn_88956170((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8895DA38: set u32@0x3c, fn_88956170 */
ts4_word ts4_set_u32_off3c_8895DA38(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return fn_88956170((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8895DA40: tailcall fn_889581B0 */
ts4_word ts4_tailcall_fn_889581B0_8895DA40(ts4_word a0)
{
    return fn_889581B0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889606E0: tailcall fn_88960528 */
ts4_word ts4_tailcall_fn_88960528_889606E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_88960528((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x889651A8: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_889651A8(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88965318: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_88965318(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88965448: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_88965448(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88965598: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_88965598(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889656B0: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_889656B0(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889657C8: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_889657C8(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88965928: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_88965928(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889659D8: tailcall fn_88963BF0 */
ts4_word ts4_tailcall_fn_88963BF0_889659D8(ts4_word a0)
{
    return fn_88963BF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88966E08: get u32@0x1c, ts4_call_seq_fn_881599B8_88994B28 */
ts4_word ts4_get_u32_off1c_88966E08(ts4_word a0)
{
    return ts4_call_seq_fn_881599B8_88994B28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x88975D68: call_seq fn_88150600, fn_88150600, fn_88150600, fn_88150600, fn_88150600, fn_88150600 */
ts4_word ts4_call_seq_fn_88150600_88975D68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t20;

    fn_88150600((ts4_word)a0, (ts4_word)a1);
    fn_88150600((ts4_word)(a0 + 12), (ts4_word)a2);
    fn_88150600((ts4_word)(a0 + 24), (ts4_word)a3);
    fn_88150600((ts4_word)(a0 + 36), (ts4_word)a4);
    fn_88150600((ts4_word)(a0 + 48), (ts4_word)a5);
    fn_88150600((ts4_word)(a0 + 72), (ts4_word)a7);
    *(unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 86) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 87) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 90) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 91) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 94) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 104) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 105) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 106) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 107) = (unsigned char)1;
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a5) + 0)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a6) + 0)));
    t20 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a7) + 0)));
    return t20;
}

/* Swing_DLL.xex 0x88977CD0: call_seq fn_8816D1A8, fn_8816D1A8, fn_8816D1A8, u32@0x28, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_8816D1A8_88977CD0(ts4_word a0)
{
    fn_8816D1A8((ts4_word)(a0 + 4));
    fn_8816D1A8((ts4_word)(a0 + 16));
    fn_8816D1A8((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 44));
    fn_8816D1A8((ts4_word)(a0 + 56));
    fn_8816D1A8((ts4_word)(a0 + 68));
    fn_8816D1A8((ts4_word)(a0 + 80));
    fn_8816D1A8((ts4_word)(a0 + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
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
    fn_8815E628((ts4_word)(a0 + 188));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 248) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 240) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)-1;
    return a0;
}

/* Swing_DLL.xex 0x88977DB8: if_get u32@0x0, u32@0x40, vcall, u32@0x0, u32@0x44, vcall */
ts4_word ts4_if_get_u32_off0_88977DB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)a1);
        return 1;
    }
    fn_88969230((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 1;
}

/* Swing_DLL.xex 0x88977E28: if_get u32@0x0, u32@0x30, vcall, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_off0_88977E28(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)a1);
        return 1;
    }
    fn_889695A8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return 1;
}

/* Swing_DLL.xex 0x88978508: if_call_seq fn_8896B820, fn_889781B0 */
ts4_word ts4_if_call_seq_fn_8896B820_88978508(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    t1 = fn_8896B820();
    if ((ts4_word)(t1 & 0xff) != 0) {
        t2 = fn_889781B0((ts4_word)a0, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8897E090: tailcall fn_8897DCC0 */
ts4_word ts4_tailcall_fn_8897DCC0_8897E090(ts4_word a0)
{
    return fn_8897DCC0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88987E78: tailcall fn_88987D68 */
ts4_word ts4_tailcall_fn_88987D68_88987E78(ts4_word a0)
{
    return fn_88987D68((ts4_word)a0);
}

/* Swing_DLL.xex 0x8898E0C0: tailcall fn_885637C0 */
ts4_word ts4_tailcall_fn_885637C0_8898E0C0(void)
{
    return fn_885637C0((ts4_word)0);
}

/* Swing_DLL.xex 0x8898E850: call_seq u32@0x18, u32@0x10, u32@0x8, u32@0xc, memcpy, u32@0x24 */
ts4_word ts4_call_seq_u32_off18_8898E850(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    memcpy((ts4_word)t1, (ts4_word)t2, (ts4_word)200);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    memcpy((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)t6, (ts4_word)120);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    memcpy((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56)), (ts4_word)200);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t4;
    return 1;
}

/* Swing_DLL.xex 0x8898EDC8: if_get u32@0x1c, u32@0x4, u32@0x0, u32@0x58, vcall, lbl_880C1320 */
ts4_word ts4_if_get_u32_off1c_8898EDC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)t1;
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 88))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    }
    t7 = fn_88159488((ts4_word)(a0 + 4), (ts4_word)(ts4_word)lbl_880C1320);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t7;
}

/* Swing_DLL.xex 0x8898EE70: call_seq lbl_880D3118, u32@0x0, ts4_call_seq_u32_off0_88159AC0, ts4_call_seq_u32_off0_88159AC0, fn_88158908, u32@0x10 */
ts4_word ts4_call_seq_lbl_880D3118_8898EE70(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D3118;
    ts4_call_seq_u32_off0_88159AC0((ts4_word)(a0 + 4));
    ts4_call_seq_u32_off0_88159AC0((ts4_word)(a0 + 16));
    fn_88158908((ts4_word)(a0 + 16), (ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(t4) + 5) = (unsigned char)48;
    fn_88159870((ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x8898FCA0: tailcall fn_8815B210 */
ts4_word ts4_tailcall_fn_8815B210_8898FCA0(ts4_word a0)
{
    return fn_8815B210((ts4_word)a0);
}

/* Swing_DLL.xex 0x88991220: tailcall fn_8898FE30 */
ts4_word ts4_tailcall_fn_8898FE30_88991220(ts4_word a0)
{
    return fn_8898FE30((ts4_word)a0);
}

/* Swing_DLL.xex 0x88991228: tailcall fn_8898FEB0 */
ts4_word ts4_tailcall_fn_8898FEB0_88991228(ts4_word a0)
{
    return fn_8898FEB0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88991F08: call_seq fn_881599B8, fn_88991DA8, fn_88159870 */
ts4_word ts4_call_seq_fn_881599B8_88991F08(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_881599B8((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_88991DA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    fn_88159870((ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x88994930: tailcall fn_88994740 */
ts4_word ts4_tailcall_fn_88994740_88994930(ts4_word a0, ts4_word a1)
{
    return fn_88994740((ts4_word)a1, (ts4_word)(a0 + 2872), (ts4_word)(a0 + 2876), (ts4_word)(a0 + 2880), (ts4_word)a0, (ts4_word)(a0 + 48));
}

/* Swing_DLL.xex 0x88994BC8: call_seq ts4_tailcall_NetDll_XNetGetEthernetLinkStatus_884F0010 */
ts4_word ts4_call_seq_fn_884F0010_88994BC8(void)
{
    ts4_word t1;

    t1 = ts4_tailcall_NetDll_XNetGetEthernetLinkStatus_884F0010();
    return (t1 != 0);
}

/* Swing_DLL.xex 0x88994C28: addr lbl_880D1F80, u8@0x48, u32@0x0 */
void ts4_addr_lbl_880D1F80_88994C28(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D1F80;
    return;
}

/* Swing_DLL.xex 0x88994C40: fn  */
ts4_word ts4_fn_88994C40(void)
{
    return 24;
}

/* Swing_DLL.xex 0x88994C50: addr lbl_880D5C10, u32@0x0 */
void ts4_addr_lbl_880D5C10_88994C50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5C10;
    return;
}

/* Swing_DLL.xex 0x88994C60: addr lbl_880D2DBC, u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D2DBC_88994C60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2DBC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x88994D78: addr lbl_880D5A64, lbl_880D5AA0, u32@0x4c8, u32@0x0, u32@0x4 */
void ts4_addr_lbl_880D5A64_88994D78(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1224) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5AA0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    return;
}

/* Swing_DLL.xex 0x88994D98: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88994D98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88994DB8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88994DB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88994DD8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88994DD8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88995248: if_get u32@0x0, u32@0x8, vcall, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off0_88995248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1, (ts4_word)1);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x889952D8: call_seq ts4_tailcall_NetDll_XNetXnAddrToInAddr_884EFEB8, u16@0x4, u16@0x6 */
ts4_word ts4_call_seq_fn_884EFEB8_889952D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_tailcall_NetDll_XNetXnAddrToInAddr_884EFEB8((ts4_word)(a1 + 8), (ts4_word)a1, (ts4_word)(a0 + 8));
    *(unsigned short *)((char *)(ts4_word)(a0) + 4) = (unsigned short)2;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1000;
    return t1;
}

/* Swing_DLL.xex 0x889953D8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_889953D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x889956B0: if_call_seq u32@0xc, fn_8860DCF8, lbl_880D1F80, u8@0x48, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_889956B0(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)88, (ts4_word)8, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t2) + 72) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D1F80;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88995738: set u64@0x50 */
void ts4_set_u64_off50_88995738(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 80) = (ts4_u64)0;
    return;
}

/* Swing_DLL.xex 0x88995748: if_get fn_889324A0, u32@0xc, u32@0x0, u32@0x4, vcall, u32@0xc */
ts4_word ts4_if_get_fn_889324A0_88995748(ts4_word a0)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    fn_889324A0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p6 = (ts4_word)t2;
    if ((int)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 4))))((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88995A98: get u32@0x4cc, u32@0x8 */
ts4_word ts4_get_u32_off4cc_88995A98(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1228);
    return ((((t1 + 7)) >> 3) + ((((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 7)) >> 3));
}

/* Swing_DLL.xex 0x88995FC8: if_call_seq u32@0x20, fn_888860A0, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off20_88995FC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x88996090: if_call_seq u32@0x1d4, fn_888860A0, u32@0x1d4 */
ts4_word ts4_if_call_seq_u32_off1d4_88996090(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 468);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x889961E8: if_call_seq u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, ts4_tailcall_fn_8857A2A0_8857A330 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_889961E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t6;

    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a0);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
    } else {
        p5 = (ts4_word)-1;
    }
    t6 = ts4_tailcall_fn_8857A2A0_8857A330((ts4_word)p5, (ts4_word)a1, (ts4_word)a2);
    return t6;
}

/* Swing_DLL.xex 0x88996B08: set u8@0x2c */
void ts4_set_u8_off2c_88996B08(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88996B18: set u8@0x2c */
void ts4_set_u8_off2c_88996B18(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x889972D0: call_seq fn_88932388, u8@0x14, u8@0x14 */
ts4_word ts4_call_seq_fn_88932388_889972D0(ts4_word a0, ts4_word a1)
{
    fn_88932388((ts4_word)a0, (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 20));
    return a0;
}

/* Swing_DLL.xex 0x88997390: call_seq fn_88932418, lbl_880D2A30, u8@0x14, u32@0x0 */
ts4_word ts4_call_seq_fn_88932418_88997390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_88932418((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2A30;
    return a0;
}

/* Swing_DLL.xex 0x88997D98: set u64@0x70, u8@0x78, ts4_call_seq_u32_off8_889343E8 */
ts4_word ts4_set_u64_off70_88997D98(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    return ts4_call_seq_u32_off8_889343E8((ts4_word)a0);
}

/* Swing_DLL.xex 0x88997DA8: addr lbl_880D2A68, u32@0x0, fn_88934458 */
ts4_word ts4_addr_lbl_880D2A68_88997DA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2A68;
    return fn_88934458((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2A68);
}

/* Swing_DLL.xex 0x88997DB8: set u32@0x4cc, u32@0x4d0, u32@0x4d4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off4cc_88997DB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1232) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88997F10: tailcall fn_88936BB0 */
ts4_word ts4_tailcall_fn_88936BB0_88997F10(ts4_word a0, ts4_word a1)
{
    return fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889987F0: if_call_seq u8@0xd0, u32@0x90, fn_8857A1E0, u32@0x90, u8@0xd0, fn_88934EA8 */
ts4_word ts4_if_call_seq_u8_offd0_889987F0(ts4_word a0)
{
    unsigned char t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 208);
    if ((ts4_word)t1 != 0) {
        t3 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 208) = (unsigned char)0;
        return t3;
    }
    fn_88934EA8((ts4_word)a0);
    t6 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    return t6;
}

/* Swing_DLL.xex 0x88998868: if_call_seq u8@0xd0, u32@0x90, fn_8857A1E0, u32@0x90, u8@0xd0, fn_88934EA8 */
ts4_word ts4_if_call_seq_u8_offd0_88998868(ts4_word a0)
{
    unsigned char t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 208);
    if ((ts4_word)t1 != 0) {
        t3 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 208) = (unsigned char)0;
        return t3;
    }
    fn_88934EA8((ts4_word)a0);
    t6 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    return t6;
}

/* Swing_DLL.xex 0x88998AA8: get fn_889333F0, u32@0x0, u32@0x40, vcall, fn_889989A0 */
ts4_word ts4_get_fn_889333F0_88998AA8(ts4_word a0)
{
    ts4_word t5;

    fn_889333F0();
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    t5 = fn_889989A0((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88998C78: if_get fn_88997318, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_fn_88997318_88998C78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        if ((ts4_word)(a2 & 0xff) != 0) {
            fn_88997318((ts4_word)a1);
        }
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1, (ts4_word)1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88998CD8: if_call_seq u32@0xc, fn_8860DCF8, fn_88932418, lbl_880D2A30, u8@0x14, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_88998CD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)24, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88932418((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 20) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2A30;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88998D48: call_seq fn_88935D10, u32@0x64, fn_8857A1E0, ts4_tailcall_NetDll_WSACleanup_884F0238 */
ts4_word ts4_call_seq_fn_88935D10_88998D48(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    fn_88935D10();
    t3 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)));
    t4 = ts4_tailcall_NetDll_WSACleanup_884F0238((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88998D80: addr lbl_880D2D10, u32@0x0, fn_88935DF8 */
ts4_word ts4_addr_lbl_880D2D10_88998D80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2D10;
    return fn_88935DF8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2D10);
}

/* Swing_DLL.xex 0x88999328: call_seq fn_88617D88, lbl_880D2D94, u32@0x0 */
ts4_word ts4_call_seq_fn_88617D88_88999328(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2D94;
    return a0;
}

/* Swing_DLL.xex 0x88999368: call_seq fn_889375D8, lbl_880D2A68, u64@0x70, u32@0x0, u8@0x78 */
ts4_word ts4_call_seq_fn_889375D8_88999368(ts4_word a0)
{
    fn_889375D8();
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2A68;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x889993B0: addr lbl_880D2E4C, u32@0x0, fn_88937648 */
ts4_word ts4_addr_lbl_880D2E4C_889993B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2E4C;
    return fn_88937648((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2E4C);
}

/* Swing_DLL.xex 0x889993C0: call_seq fn_889377F8, lbl_880D2E18, u32@0x0 */
ts4_word ts4_call_seq_fn_889377F8_889993C0(ts4_word a0)
{
    fn_889377F8();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2E18;
    return a0;
}

/* Swing_DLL.xex 0x88999400: get u32@g_ts4_session_context, u32@0xc, fn_88157C20, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_88999400(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88157C20((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x88999460: get u32@g_ts4_session_context, u32@0xc, fn_88157E60, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_88999460(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88157E60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889994C0: get u32@g_ts4_session_context, u32@0xc, fn_88157DA8, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889994C0(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88157DA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889995C0: get fn_88999520, u32@0x4, u32@0x4, vcall */
ts4_word ts4_get_fn_88999520_889995C0(ts4_word a0)
{
    ts4_word t4;

    fn_88999520();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4))))((ts4_word)(a0 + 4));
    return t4;
}

/* Swing_DLL.xex 0x88999600: tailcall fn_88938F38 */
ts4_word ts4_tailcall_fn_88938F38_88999600(ts4_word a0, ts4_word a1)
{
    return fn_88938F38((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)60);
}

/* Swing_DLL.xex 0x88999618: tailcall fn_88938F38 */
ts4_word ts4_tailcall_fn_88938F38_88999618(ts4_word a0, ts4_word a1)
{
    return fn_88938F38((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)60);
}

/* Swing_DLL.xex 0x88999630: get u32@g_ts4_session_state, fn_88938F38 */
ts4_word ts4_get_u32_g_ts4_session_state_88999630(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88938F38((ts4_word)a1, (ts4_word)((*(ts4_word *)g_ts4_session_state) + 280), (ts4_word)8);
}

/* Swing_DLL.xex 0x88999898: tailcall fn_889997C8 */
ts4_word ts4_tailcall_fn_889997C8_88999898(void)
{
    return fn_889997C8((ts4_word)0);
}

/* Swing_DLL.xex 0x889998A0: tailcall fn_889997C8 */
ts4_word ts4_tailcall_fn_889997C8_889998A0(void)
{
    return fn_889997C8((ts4_word)1);
}

/* Swing_DLL.xex 0x88999AD0: call_seq fn_88938740, lbl_880D2D10, u32@0x64, u32@0x0 */
ts4_word ts4_call_seq_fn_88938740_88999AD0(ts4_word a0)
{
    fn_88938740();
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2D10;
    return a0;
}

/* Swing_DLL.xex 0x88999EF0: call_seq lbl_880D2DEC, u32@0x0, fn_88157B78, fn_88936F98 */
ts4_word ts4_call_seq_lbl_880D2DEC_88999EF0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2DEC;
    fn_88157B78((ts4_word)(a0 + 36));
    t2 = fn_88936F98((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8899A0D8: call_seq lbl_880D2570, fn_88608590, u32@lbl_88D45B20, fn_889998A8, lbl_880D257C, fn_88608590 */
ts4_word ts4_call_seq_lbl_880D2570_8899A0D8(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D2570);
    loc50[0] = (ts4_word)t1;
    fn_889998A8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D257C);
    loc50[0] = (ts4_word)t4;
    t6 = fn_88999C30((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x8899A558: if_call_seq u8@0x42c, u8@0x34, fn_8899A4B8, u32@g_ts4_session_state, fn_881542F8, u32@g_ts4_session_state */
ts4_word ts4_if_call_seq_u8_off42c_8899A558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;

    (void)a0;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 1068);
    if ((ts4_word)t1 == 1) {
        *(unsigned char *)((char *)(ts4_word)(a2) + 52) = (unsigned char)t1;
        t2 = fn_8899A4B8();
        return t2;
    }
    t4 = fn_881542F8((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)((3350265856) | 47176));
    t6 = fn_88151560((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)t4);
    return t6;
}

/* Swing_DLL.xex 0x8899A7D0: tailcall fn_8899A158 */
ts4_word ts4_tailcall_fn_8899A158_8899A7D0(ts4_word a0)
{
    return fn_8899A158((ts4_word)a0);
}

/* Swing_DLL.xex 0x8899A8B8: tailcall fn_8899A270 */
ts4_word ts4_tailcall_fn_8899A270_8899A8B8(ts4_word a0)
{
    return fn_8899A270((ts4_word)a0);
}

/* Swing_DLL.xex 0x8899AAB0: addr lbl_880D2CF8, u32@0x0, fn_8893B3E0 */
ts4_word ts4_addr_lbl_880D2CF8_8899AAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2CF8;
    return fn_8893B3E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2CF8);
}

/* Swing_DLL.xex 0x8899AAC0: call_seq fn_88938660, lbl_880D2CF8, u8@0x34, u32@0x0 */
ts4_word ts4_call_seq_fn_88938660_8899AAC0(ts4_word a0)
{
    fn_88938660();
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2CF8;
    return a0;
}

/* Swing_DLL.xex 0x8899AC68: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, fn_88939040 */
ts4_word ts4_get_u32_off0_8899AC68(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = fn_88939040((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)60);
    return t6;
}

/* Swing_DLL.xex 0x8899ACC0: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, fn_88939040 */
ts4_word ts4_get_u32_off0_8899ACC0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = fn_88939040((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)60);
    return t6;
}

/* Swing_DLL.xex 0x8899AD88: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@g_ts4_session_state */
ts4_word ts4_get_u32_off0_8899AD88(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_88939040((ts4_word)a1, (ts4_word)((*(ts4_word *)g_ts4_session_state) + 280), (ts4_word)8);
    return t7;
}

/* Swing_DLL.xex 0x8899AF80: get u32@0x0, u32@0x2c, vcall, fn_8893B578 */
ts4_word ts4_get_u32_off0_8899AF80(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    t4 = fn_8893B578((ts4_word)a0, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x8899B130: if_call_seq u32@0xc, fn_8860DCF8, fn_889375D8, lbl_880D2A68, u64@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_8899B130(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)128, (ts4_word)8, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_889375D8((ts4_word)t2);
        *(ts4_u64 *)((char *)(ts4_word)(t2) + 112) = (ts4_u64)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2A68;
        *(unsigned char *)((char *)(ts4_word)(t2) + 120) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899B290: call_seq fn_8893CCE8, fn_88938F38, fn_88936BB0 */
ts4_word ts4_call_seq_fn_8893CCE8_8899B290(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8893CCE8((ts4_word)a0, (ts4_word)a1);
    fn_88938F38((ts4_word)a1, (ts4_word)(a0 + 112), (ts4_word)8);
    t3 = fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 120));
    return t3;
}

/* Swing_DLL.xex 0x8899B358: get u32@0x14, fn_8899A3C0 */
ts4_word ts4_get_u32_off14_8899B358(ts4_word a0)
{
    return fn_8899A3C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)1);
}

/* Swing_DLL.xex 0x8899B368: tailcall fn_8893D2A0 */
ts4_word ts4_tailcall_fn_8893D2A0_8899B368(ts4_word a0)
{
    return fn_8893D2A0((ts4_word)a0);
}
