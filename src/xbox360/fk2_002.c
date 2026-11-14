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

extern char fn_8831F298[];
extern char lbl_88001974[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88004440[];
extern char lbl_88028C18[];
extern char lbl_88028C20[];
extern char lbl_88028EA4[];
extern char lbl_88029048[];
extern char lbl_880290FC[];
extern char lbl_88029198[];
extern char lbl_88029224[];
extern char lbl_880292A8[];
extern char lbl_8802B898[];
extern char lbl_8802B8F8[];
extern char lbl_8802BB80[];
extern char lbl_8802BE78[];
extern char lbl_8802BF28[];
extern char lbl_8802BFE8[];
extern char lbl_8802E940[];
extern char lbl_8802E958[];
extern char lbl_8802E95C[];
extern char lbl_88039DD8[];
extern char lbl_8803A098[];
extern char lbl_8803A308[];
extern char lbl_8803AA08[];
extern char lbl_8803B324[];
extern char lbl_8803BB8C[];
extern char lbl_8803D504[];
extern char lbl_8803DA3C[];
extern char lbl_8803DAD4[];
extern char lbl_8803DAE8[];
extern char lbl_8803DDEC[];
extern char lbl_8803DE18[];
extern char lbl_8803E710[];
extern char lbl_8803E76C[];
extern char lbl_8803E794[];
extern char lbl_8803EAEC[];
extern char lbl_8803F4C4[];
extern char lbl_8803F518[];
extern char lbl_8803F520[];
extern char lbl_8803F5A0[];
extern char lbl_88040164[];
extern char lbl_88040170[];
extern char lbl_88040180[];
extern char lbl_880410F0[];
extern char lbl_88041528[];
extern char lbl_88041534[];
extern char lbl_88041544[];
extern char lbl_880418B4[];
extern char lbl_88041A9C[];
extern char lbl_88042C7C[];
extern char lbl_88042C8C[];
extern char lbl_88042CA4[];
extern char lbl_88042CB4[];
extern char lbl_88043C04[];
extern char lbl_88043C18[];
extern char lbl_88043E60[];
extern char lbl_8804901C[];
extern char lbl_8804903C[];
extern char lbl_880493E4[];
extern char lbl_880496E4[];
extern char lbl_88049700[];
extern char lbl_88057280[];
extern char lbl_88058C60[];
extern char lbl_880807C8[];
extern char lbl_880D2F14[];
extern char lbl_880D2F18[];
extern char lbl_880F3428[];
extern char lbl_880F342C[];
extern char lbl_88B3302C[];
extern char lbl_88B3C200[];
extern char lbl_88B3C460[];
extern char lbl_88B3C5B8[];
extern char lbl_88B3D248[];
extern char lbl_88B3D268[];
extern char lbl_88C74978[];
extern char lbl_88C8EB38[];
extern char lbl_88C8F3F8[];
extern char lbl_88C922FC[];
extern char lbl_88CACF08[];
extern char lbl_88CAD334[];
extern char lbl_88CAD338[];
extern char lbl_88CAD56C[];
extern char lbl_88D26FCC[];
ts4_word KeTlsGetValue();
ts4_word KeTlsSetValue();
ts4_word RtlInitializeCriticalSection();
ts4_word fn_8825C8E8();
ts4_word ts4_if_get_u32_offc_8827C828();
ts4_word fn_882809B8();
ts4_word fn_88288530();
ts4_word ts4_get_u32_off18_8828B1E0();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word ts4_tailcall_fn_88315C60_88316068();
ts4_word fn_88318298();
ts4_word ts4_if_call_seq_fn_8832BFC0_88318300();
ts4_word fn_88318550();
ts4_word ts4_if_call_seq_lbl_88028EA4_8831ACF0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word ts4_if_call_seq_fn_8857C040_8831AEC8();
ts4_word fn_8831CF58();
ts4_word fn_8831E168();
ts4_word fn_88321C50();
ts4_word fn_88322CA8();
ts4_word fn_88323D20();
ts4_word ts4_pair_table_lookup_883242E0();
ts4_word fn_88325370();
ts4_word ts4_tailcall_fn_883255A0_88325778();
ts4_word fn_88325780();
ts4_word ts4_forward_owned_slot23_88325830();
ts4_word ts4_if_get_u32_off4c_88325930();
ts4_word fn_88325EE0();
ts4_word fn_883296A0();
ts4_word ts4_if_set_u32_off0_8832BFC0();
ts4_word fn_8832EDB0();
ts4_word fn_8832F538();
ts4_word ts4_call_seq_ts4_memset_8832F8F0();
ts4_word fn_8832FC40();
ts4_word fn_8832FD28();
ts4_word fn_88330450();
ts4_word fn_88332408();
ts4_word fn_8834FB00();
ts4_word fn_88356728();
ts4_word fn_88358250();
ts4_word fn_8836CBE8();
ts4_word fn_8836CD70();
ts4_word fn_8837C680();
ts4_word fn_8837D100();
ts4_word fn_88381170();
ts4_word fn_8839CC70();
ts4_word fn_883A1AE0();
ts4_word ts4_deref_deref_ptr_883A3C60();
ts4_word fn_883A5320();
ts4_word fn_883A78E8();
ts4_word fn_883A9440();
ts4_word fn_883AA870();
ts4_word ts4_addr_lbl_8802BC90_883AC348();
ts4_word ts4_call_vtable_slot11_883AC3C8();
ts4_word ts4_call_seq_fn_883AC348_883AE450();
ts4_word ts4_if_call_seq_u32_off0_883B6BF0();
ts4_word fn_883B70D8();
ts4_word ts4_if_call_seq_u32_off0_883B8088();
ts4_word ts4_if_call_seq_u32_off0_883BAC48();
ts4_word ts4_if_call_seq_u32_off24_883BD9D8();
ts4_word fn_883BE648();
ts4_word ts4_if_get_u32_off3c_883CF0A8();
ts4_word fn_883FBC58();
ts4_word fn_883FDB00();
ts4_word fn_88408D58();
ts4_word fn_8840EE78();
ts4_word fn_8841A328();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841A740();
ts4_word fn_8841C428();
ts4_word fn_8841C678();
ts4_word fn_8841C970();
ts4_word fn_8841C9F0();
ts4_word fn_8841D800();
ts4_word fn_8841EA48();
ts4_word ts4_get_u32_off8_8841EF28();
ts4_word ts4_tailcall_fn_88420A90_88420C20();
ts4_word fn_88421338();
ts4_word fn_884214A8();
ts4_word fn_884223A0();
ts4_word fn_88422BA0();
ts4_word fn_88423730();
ts4_word fn_88423788();
ts4_word fn_88423858();
ts4_word fn_88423CE0();
ts4_word ts4_addr_lbl_88B3C5B8_88426110();
ts4_word ts4_get_u32_off4_88426130();
ts4_word fn_88426178();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_get_u32_off0_88428960();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off0_884289B8();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_index_u64_array_at_field0_88428A88();
ts4_word ts4_call_seq_u32_off4_88428B48();
ts4_word fn_8842AE60();
ts4_word fn_884334B0();
ts4_word ts4_call_seq_lbl_88042D94_88433ED8();
ts4_word fn_884340B0();
ts4_word fn_88436C28();
ts4_word fn_884430E8();
ts4_word fn_884C5468();
ts4_word fn_884C6220();
ts4_word ts4_tailcall_fn_884CD990_884CE090();
ts4_word ts4_tailcall_NetDll_XNetCleanup_884EFEA0();
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238();
ts4_word ts4_tailcall_NetDll_recv_884F0318();
ts4_word ts4_tailcall_NetDll_send_884F0350();
ts4_word fn_885651F8();
ts4_word fn_88565258();
ts4_word fn_88565320();
ts4_word ts4_tailcall_fn_885655E8_88565748();
ts4_word ts4_tailcall_fn_885659E8_88565AF8();
ts4_word fn_88565F50();
ts4_word fn_88566750();
ts4_word fn_88566FE8();
ts4_word ts4_addr_lbl_88C30DA8_88567BC8();
ts4_word fn_8857ACB8();
ts4_word fn_8857B048();
ts4_word ts4_tailcall_MmFreePhysicalMemory_8857B158();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_copy_bytes();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_lookup_then_forward_88318348();
ts4_word ts4_lookup_then_forward_88318420();
ts4_word ts4_memset();

/* Swing_DLL.xex 0x88233530: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_88233530(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p7;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 24);
        do {
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
            t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            p6 = (ts4_word)(lv1 + 48);
            lv1 = p6;
        } while ((ts4_word)(p6 + -24) != (ts4_word)a1);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x88233618: loop_call_seq u32@0x20, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off20_88233618(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p7;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 120);
        do {
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 32)));
            t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            p6 = (ts4_word)(lv1 + 188);
            lv1 = p6;
        } while ((ts4_word)(p6 + -120) != (ts4_word)a1);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x88233C08: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88233C08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 128);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88233CC0: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88233CC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 24);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88233F80: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88233F80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 16);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x882343C0: loop_call_seq lbl_880F3428, lbl_880F342C, u32@0x3c, fn_8825C8E8, u32@-0xc, fn_8825C8E8 */
ts4_word ts4_loop_call_seq_lbl_880F3428_882343C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word p5;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 20);
        do {
            *(ts4_word *)((char *)(ts4_word)(lv1) + 60) = (ts4_word)(ts4_word)lbl_880F342C;
            fn_8825C8E8((ts4_word)(lv1 + 68));
            *(ts4_word *)((char *)(ts4_word)(lv1) + -12) = (ts4_word)(ts4_word)lbl_880F3428;
            t3 = fn_8825C8E8((ts4_word)lv1);
            p4 = (ts4_word)(lv1 + 160);
            lv1 = p4;
        } while ((ts4_word)(p4 + -20) != (ts4_word)a1);
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x8825BF80: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_8825BF80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 176);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8825E428: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_8825E428(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 68);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88260460: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88260460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 160);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88260968: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88260968(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 288);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x88261B50: loop_get u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off0_88261B50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 4))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 140);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8826DFB8: loop_get u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_8826DFB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv1) + 0))) + 0))))((ts4_word)lv1, (ts4_word)0);
        p5 = (ts4_word)(lv1 + 20);
        lv1 = p5;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8827C8D0: loop_call_seq u32@0x4, u32@0x0, fn_882809B8, u32@0x4, u32@0x0, ts4_if_get_u32_offc_8827C828 */
ts4_word ts4_loop_call_seq_u32_off4_8827C8D0(ts4_word a0)
{
    ts4_word lv6;
    ts4_word p8;
    ts4_word p13;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_882809B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t5 != (ts4_word)t4) {
        lv6 = (ts4_word)t5;
        do {
            ts4_if_get_u32_offc_8827C828((ts4_word)lv6);
            p8 = (ts4_word)(lv6 + 20);
            lv6 = p8;
        } while ((ts4_word)p8 != (ts4_word)t4);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p13 = (ts4_word)t11;
    if ((ts4_word)t11 != 0) {
        t12 = ts4_destroy_owned_object((ts4_word)t11);
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x88282DF0: loop_call_seq u32@0x4, u32@0x0, fn_882809B8, u32@0x4, u32@0x0, ts4_if_get_u32_offc_8827C828 */
ts4_word ts4_loop_call_seq_u32_off4_88282DF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word lv7;
    ts4_word p9;
    ts4_word p14;
    ts4_word p15;
    ts4_word p16;
    ts4_word t2;
    ts4_word t5;
    ts4_word t12;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p16 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 4);
        fn_882809B8((ts4_word)lv1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)), (ts4_word)t2);
        t5 = *(ts4_word *)((char *)(ts4_word)(lv1) + 4);
        lv7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0));
        while ((ts4_word)lv7 != (ts4_word)t5) {
            ts4_if_get_u32_offc_8827C828((ts4_word)lv7);
            p9 = (ts4_word)(lv7 + 20);
            lv7 = p9;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        p14 = (ts4_word)t12;
        if ((ts4_word)t12 != 0) {
            t13 = ts4_destroy_owned_object((ts4_word)t12);
            p14 = (ts4_word)t13;
        }
        p15 = (ts4_word)(lv1 + 16);
        lv1 = p15;
        p16 = (ts4_word)p14;
    }
    return p16;
}

/* Swing_DLL.xex 0x882D12D8: if_call_seq u32@0x0, ts4_get_u32_off18_8828B1E0, u32@0x0, fn_88288530, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_882D12D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
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
    if ((ts4_word)t1 != 0) {
        ts4_get_u32_off18_8828B1E0((ts4_word)t1);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t3 != 0) {
            fn_88288530((ts4_word)t3);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x882EDD90: if_get u32@0x4, u32@0x24, vcall, u32@0x10, u32@0x134, u32@0x14 */
ts4_word ts4_if_get_u32_off4_882EDD90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;
    int t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 36))))((ts4_word)a0, (ts4_word)1);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((int)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 308) = (ts4_word)0;
            p6 = (ts4_word)200;
        } else {
            p6 = (ts4_word)100;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)p6;
        p9 = (ts4_word)t3;
    }
    return p9;
}

/* Swing_DLL.xex 0x88316F00: if_get ts4_if_set_u32_off0_8832BFC0, u32@0xdc, u32@0xdc, u32@0x0, u32@0xd0, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316F00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 == 0) {
        t4 = loc50[0];
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 220);
        if ((int)t5 != 0 && (int)t5 != 7) {
            return 56;
        }
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 208))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        return t8;
    }
    return t1;
}

/* Swing_DLL.xex 0x88316FF8: if_call_seq fn_88322CA8, fn_88323D20, u8@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88316FF8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = fn_88323D20((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88317180: if_call_seq fn_88322CA8, ts4_pair_table_lookup_883242E0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        }
        if ((ts4_word)a3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = ts4_pair_table_lookup_883242E0((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t3;
}

/* Swing_DLL.xex 0x88317370: if_call_seq fn_88322CA8, ts4_forward_owned_slot23_88325830, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317370(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        }
        p4 = (ts4_word)t1;
    } else {
        t2 = loc50[0];
        t3 = ts4_forward_owned_slot23_88325830((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317788: if_call_seq fn_88322CA8, fn_88325370, u8@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317788(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = fn_88325370((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x883177F0: if_call_seq fn_88322CA8, ts4_tailcall_fn_883255A0_88325778 */
ts4_word ts4_if_call_seq_fn_88322CA8_883177F0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)lbl_88001A20);
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = ts4_tailcall_fn_883255A0_88325778((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88317860: if_call_seq fn_88322CA8, fn_88325780, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317860(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = fn_88325780((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88317910: if_call_seq fn_88322CA8, ts4_if_get_u32_off4c_88325930, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317910(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = ts4_if_get_u32_off4c_88325930((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x883179C0: if_call_seq fn_88322CA8, ts4_if_get_u32_off3c_883CF0A8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88322CA8_883179C0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 != 0) {
        if ((ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            return t1;
        }
        return t1;
    }
    t2 = loc50[0];
    t3 = ts4_if_get_u32_off3c_883CF0A8((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88318638: if_get u32@0x118, ts4_if_call_seq_fn_8857C040_8831AEC8 */
ts4_word ts4_if_get_u32_off118_88318638(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    if ((ts4_word)t1 != 0) {
        return ts4_if_call_seq_fn_8857C040_8831AEC8((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88319E00: if_get u32@0x188, u32@0x168, u32@0x188, u32@0x0, u32@0x174, u32@0x0 */
ts4_word ts4_if_get_u32_off188_88319E00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 360);
    *(ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)(t1 & 0xffffffbf);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t2 - (*(ts4_word *)((char *)(ts4_word)(a0) + 372)));
    return 0;
}

/* Swing_DLL.xex 0x8831A510: get u32@0x188, u32@0x1c4, u32@0x1c0, u32@0x188 */
ts4_word ts4_get_u32_off188_8831A510(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
    *(ts4_word *)((char *)(ts4_word)(a0) + 452) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)(t1 & 0xfffffffd);
    return 0;
}

/* Swing_DLL.xex 0x8831A618: if_tail fn_88565258, fn_8857B048 */
ts4_word ts4_if_tail_fn_88565258_8831A618(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0x100000) != 0) {
        return fn_8857B048((ts4_word)a0, (ts4_word)-1, (ts4_word)0, (ts4_word)4);
    }
    return fn_88565258((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8831A638: if_tail fn_885651F8, ts4_tailcall_MmFreePhysicalMemory_8857B158 */
ts4_word ts4_if_tail_fn_885651F8_8831A638(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0x100000) != 0) {
        return ts4_tailcall_MmFreePhysicalMemory_8857B158((ts4_word)a0, (ts4_word)a1);
    }
    return fn_885651F8((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8831AC38: if_call_seq lbl_88028EA4, u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_88028EA4_8831AC38(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    if ((ts4_word)a0 == 0) {
        return 37;
    }
    if ((ts4_word)(a1 & 0xff) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88C74978;
        RtlInitializeCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        return 0;
    }
    t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)28, (ts4_word)(ts4_word)lbl_88028EA4, (ts4_word)602, (ts4_word)0, (ts4_word)0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        RtlInitializeCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        return 0;
    }
    return 44;
}

/* Swing_DLL.xex 0x8831B0B0: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8831B0B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Swing_DLL.xex 0x88320F88: loop_get u32@0x1cc, u32@0x1cc, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off1cc_88320F88(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 460);
    p8 = (ts4_word)0;
    if ((ts4_word)t2 != (ts4_word)(a0 + 460)) {
        lv3 = (ts4_word)0;
        lv4 = (ts4_word)t2;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            p6 = (ts4_word)(lv3 + 1);
            p7 = (ts4_word)t5;
            lv3 = p6;
            lv4 = p7;
        } while ((ts4_word)p7 != (ts4_word)(a0 + 460));
        p8 = (ts4_word)lv3;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p8;
    return 0;
}

/* Swing_DLL.xex 0x88320FC8: loop_get u32@0x160, u32@0x160, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off160_88320FC8(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 352);
    p8 = (ts4_word)0;
    if ((ts4_word)t2 != (ts4_word)(a0 + 352)) {
        lv3 = (ts4_word)0;
        lv4 = (ts4_word)t2;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            p6 = (ts4_word)(lv3 + 1);
            p7 = (ts4_word)t5;
            lv3 = p6;
            lv4 = p7;
        } while ((ts4_word)p7 != (ts4_word)(a0 + 352));
        p8 = (ts4_word)lv3;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p8;
    return 0;
}

/* Swing_DLL.xex 0x88321008: loop_get u32@0x24c, u32@0x24c, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off24c_88321008(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 588);
    p8 = (ts4_word)0;
    if ((ts4_word)t2 != (ts4_word)(a0 + 588)) {
        lv3 = (ts4_word)0;
        lv4 = (ts4_word)t2;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            p6 = (ts4_word)(lv3 + 1);
            p7 = (ts4_word)t5;
            lv3 = p6;
            lv4 = p7;
        } while ((ts4_word)p7 != (ts4_word)(a0 + 588));
        p8 = (ts4_word)lv3;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p8;
    return 0;
}

/* Swing_DLL.xex 0x88321F00: if_call_seq u32@0x44, u32@0x44, lbl_880290FC, u32@lbl_88B3302C, u32@0x4, ts4_tailcall_fn_88315C60_88316068 */
ts4_word ts4_if_call_seq_u32_off44_88321F00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a0;
    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
        p3 = (ts4_word)t2;
        if ((ts4_word)t2 < 272) {
            p3 = (ts4_word)272;
        }
        t6 = ts4_tailcall_fn_88315C60_88316068((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)p3, (ts4_word)(ts4_word)lbl_880290FC, (ts4_word)1578, (ts4_word)0);
        if ((ts4_word)t6 != 0) {
            t7 = fn_88321C50((ts4_word)t6);
            if ((ts4_word)t7 == 0) {
                return 44;
            }
            fn_8857ACB8((ts4_word)(t7 + 72), (ts4_word)a1, (ts4_word)124);
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t7;
            t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 116);
            if ((ts4_word)t9 == 0) {
                *(ts4_word *)((char *)(ts4_word)(t7) + 116) = (ts4_word)(ts4_word)fn_8831F298;
            }
            return 0;
        }
        return 44;
    }
    return 37;
}

/* Swing_DLL.xex 0x883250D8: if_get u32@0x4c, u32@0x20, u32@0x20, u32@0x0, u32@0x54, u32@0x164 */
ts4_word ts4_if_get_u32_off4c_883250D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    if ((ts4_word)(t3 & 0x10) == 0) {
        return 49;
    }
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    *(ts4_word *)((char *)(ts4_word)(a0) + 356) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(t5 | 16);
    return 0;
}

/* Swing_DLL.xex 0x883251A0: if_get u32@0x4c, u32@0x20, u32@0x20 */
ts4_word ts4_if_get_u32_off4c_883251A0(ts4_word a0, float f1)
{
    ts4_word t1;
    ts4_word t3;
    float t4;
    float t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    if ((ts4_word)(t3 & 0x10) == 0) {
        return 49;
    }
    t4 = *(float *)lbl_88001A20;
    if (!(f1 < t4)) {
        t5 = *(float *)lbl_88028C18;
        if (!(f1 > t5)) {
            *(float *)((char *)(ts4_word)(a0) + 408) = f1;
            return 0;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x88325200: if_get u32@0x4c, u32@0x20, u32@0x20 */
ts4_word ts4_if_get_u32_off4c_88325200(ts4_word a0, float f1)
{
    ts4_word t1;
    ts4_word t3;
    float t4;
    float t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    if ((ts4_word)(t3 & 0x10) == 0) {
        return 49;
    }
    t4 = *(float *)lbl_88001A20;
    if (!(f1 < t4)) {
        t5 = *(float *)lbl_88004440;
        if (!(f1 > t5)) {
            *(float *)((char *)(ts4_word)(a0) + 416) = f1;
            return 0;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x883258A0: if_get u32@0x4c, u32@0x4c, u32@0x0, u32@0x94, vcall, fn_8831CF58 */
ts4_word ts4_if_get_u32_off4c_883258A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word loc50[4];
    ts4_word t2;
    int t5;
    ts4_word t6;
    int t7;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t2 == 0) {
        return 36;
    }
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 148))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    p8 = (ts4_word)t5;
    if ((int)t5 == 0) {
        t6 = loc50[0];
        t7 = fn_8831CF58((ts4_word)t6, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)a2);
        if ((int)t7 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)a1;
        }
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x883268B8: if_get u32@0x4c, u32@0x20, u32@0x20, u32@0x24, fn_88325EE0 */
ts4_word ts4_if_get_u32_off4c_883268B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, float f1)
{
    ts4_word t1;
    ts4_word t3;
    float t4;
    float t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    if ((ts4_word)(t3 & 0x10) == 0) {
        return 49;
    }
    t4 = *(float *)lbl_88001A20;
    if (!(f1 < t4)) {
        t5 = *(float *)lbl_88001A68;
        if (!(f1 > t5)) {
            *(float *)((char *)(ts4_word)(a0) + 412) = f1;
            t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
            if ((ts4_word)(t6 & 0x20) != 0) {
                if (f1 < t5) {
                    return fn_88325EE0((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t3 & 0x10), (ts4_word)(t6 & 0x20));
                }
                return 0;
            }
            return 0;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x88329410: if_get u32@0x4, u32@0x14, u32@0x14, u32@0xc, u32@0x14, u32@0x0 */
ts4_word ts4_if_get_u32_off4_88329410(ts4_word a0, int a1, ts4_word a2, ts4_word a3)
{
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    if (((ts4_word)a2 != 0 && (int)a1 >= 0) && (int)a1 < (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 4))) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + (a1 << 2)) = (ts4_word)a2;
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + (a1 << 2));
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)a0;
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + (a1 << 2));
        t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 0))))((ts4_word)t6, (ts4_word)a1, (ts4_word)t9, (ts4_word)t8, (ts4_word)a3, (ts4_word)t4);
    }
    return 37;
}

/* Swing_DLL.xex 0x8832C280: if_get u32@0x0, u32@0x238, u32@0x4, u32@0x23c, u32@0x8, u32@0x240 */
ts4_word ts4_if_get_u32_off0_8832C280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1, float f2)
{
    float t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
        *(ts4_word *)((char *)(ts4_word)(a0) + 576) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    t7 = *(float *)((char *)(ts4_word)(a0) + 584);
    *(float *)((char *)(ts4_word)(a0) + 580) = f1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 561) = (unsigned char)1;
    if (f1 > t7) {
        *(float *)((char *)(ts4_word)(a0) + 584) = f1;
    }
    *(float *)((char *)(ts4_word)(a0) + 584) = f2;
    if (f2 < f1) {
        *(float *)((char *)(ts4_word)(a0) + 580) = f2;
    }
    *(float *)((char *)(ts4_word)(a0) + 588) = (f2 - (*(float *)((char *)(ts4_word)(a0) + 580)));
    return 0;
}

/* Swing_DLL.xex 0x8832CBA8: if_call_seq u32@0x0, u32@0x0, memcpy */
ts4_word ts4_if_call_seq_u32_off0_8832CBA8(ts4_word a0, ts4_word a1)
{
    int t2;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t2 >= 0 && (int)t2 < 4) {
        memcpy((ts4_word)a1, (ts4_word)((((int)t2 * 132) + a0) + 28), (ts4_word)124);
        return 0;
    }
    return 73;
}

/* Swing_DLL.xex 0x8832CE00: if_get u32@0x224, u32@0x130, u32@0x18 */
ts4_word ts4_if_get_u32_off224_8832CE00(ts4_word a0, int a1, int a2, float f1)
{
    if ((int)a1 < 0 || (int)a1 >= 4) {
        return 73;
    }
    if ((int)a2 < 0 || (int)a2 >= (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 548))) + 304))) {
        return 37;
    }
    *(volatile float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24)) + ((int)a2 * 84))) + 80) = f1;
    return 0;
}

/* Swing_DLL.xex 0x8832CE58: if_get u32@0x224, u32@0x130, u32@0x18 */
ts4_word ts4_if_get_u32_off224_8832CE58(ts4_word a0, int a1, int a2, ts4_word a3)
{
    if ((int)a1 < 0 || (int)a1 >= 4) {
        return 73;
    }
    if (((int)a2 < 0 || (int)a2 >= (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 548))) + 304))) || (ts4_word)a3 == 0) {
        return 37;
    }
    *(volatile float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24)) + ((int)a2 * 84))) + 80));
    return 0;
}

/* Swing_DLL.xex 0x8832E690: if_call_seq u32@0x13c, u8@0x128, fn_88318550, u32@0x12c, lbl_880292A8, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_off13c_8832E690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 316);
    *(unsigned char *)((char *)(ts4_word)(a0) + 296) = (unsigned char)0;
    p10 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88318550((ts4_word)a0);
        p9 = (ts4_word)t2;
        if ((int)t2 == 0) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 300);
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t3, (ts4_word)(ts4_word)lbl_880292A8, (ts4_word)170);
            *(ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)0;
            t8 = ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 316)), (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)0;
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88332730: if_get u32@lbl_88B3302C, u32@0x4c, u32@0x4c, fn_88332408 */
ts4_word ts4_if_get_u32_lbl_88B3302C_88332730(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    t1 = *(volatile ts4_word *)lbl_88B3302C;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 76);
    if ((ts4_word)t2 == 0) {
        return 81;
    }
    return fn_88332408((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 76)), (ts4_word)a0, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)t2, (ts4_word)a0);
}

/* Swing_DLL.xex 0x88333248: if_call_seq u32@0x180, u32@0x180, u32@0x118, u32@0x190, u32@0x24, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off180_88333248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)(a1 & 0xff) == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 400))) + 36) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0xfffffff7);
    } else {
        if ((ts4_word)(a2 & 0xff) != 0) {
            ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4348)));
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 400))) + 36) = (ts4_word)0;
            ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4348)));
        } else {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
            if ((ts4_word)t2 != 0) {
                t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 280);
                *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 400))) + 36) = (ts4_word)(t3 + 1);
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88334A18: if_get  */
ts4_word ts4_if_get_88334A18(ts4_word a0, float f1, float f2, float f3)
{
    float t1;

    t1 = *(float *)lbl_88001A20;
    if (!(f1 < t1)) {
        *(float *)((char *)(ts4_word)(a0) + 96) = f1;
    }
    if (!(f2 < t1)) {
        *(float *)((char *)(ts4_word)(a0) + 100) = f2;
    }
    if (!(f3 < t1)) {
        *(float *)((char *)(ts4_word)(a0) + 104) = f3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88334A88: if_get  */
ts4_word ts4_if_get_88334A88(ts4_word a0, float f1, float f2)
{
    float t1;

    t1 = *(float *)lbl_88001A20;
    if (!(f1 < t1)) {
        if (!(f2 < t1)) {
            if (!(f2 < f1)) {
                *(float *)((char *)(ts4_word)(a0) + 108) = f1;
                *(float *)((char *)(ts4_word)(a0) + 112) = f2;
                return 0;
            }
            return 37;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x88335CA0: loop_get u32@0x0, u32@0x84, vcall, u32@0x0, u32@0x88, vcall */
ts4_word ts4_loop_get_u32_off0_88335CA0(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p11;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    int t3;
    int t8;
    ts4_word t9;
    int t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    loc50[0] = (ts4_word)0;
    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 132))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t3 == 0 && (int)(loc50[0]) > 0) {
        lv5 = (ts4_word)0;
        do {
            t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 136))))((ts4_word)a0, (ts4_word)lv5, (ts4_word)(ts4_word)&loc54[0]);
            if ((int)t8 == 0) {
                t9 = loc54[0];
                *(unsigned short *)((char *)(ts4_word)(t9) + 30) = (unsigned short)lv5;
            }
            t10 = loc50[0];
            p11 = (ts4_word)(lv5 + 1);
            lv5 = p11;
        } while ((int)p11 < (int)t10);
    }
    return 0;
}

/* Swing_DLL.xex 0x88335D40: if_set u32@0x0, ts4_call_seq_ts4_memset_8832F8F0, u32@0x0, u32@0x4, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off0_88335D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[52];
    int t4;
    int t7;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    ts4_call_seq_ts4_memset_8832F8F0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)0);
    p13 = (ts4_word)t4;
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        p12 = (ts4_word)t7;
        if ((int)t7 == 0) {
            if ((ts4_word)a4 != 0) {
                memcpy((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)192);
            }
            if ((ts4_word)a3 != 0) {
                t10 = fn_8832F538((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
            }
            p12 = (ts4_word)0;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x8833EBD0: if_call_seq u8@0x134, u32@0x158, u32@0x158, u32@0x164, fn_8832EDB0, u8@0x134 */
ts4_word ts4_if_call_seq_u8_off134_8833EBD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t7;
    ts4_word t9;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 308);
        if ((ts4_word)t7 == 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
            if ((ts4_word)t9 != 0) {
                fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 356)));
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)1;
        }
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
        if ((ts4_word)t3 != 0) {
            fn_8832EDB0((ts4_word)0, (ts4_word)0, (ts4_word)16384, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 356)));
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883461C8: if_call_seq u8@0x134, u32@0x158, u32@0x158, u32@0x160, fn_8832EDB0, u8@0x134 */
ts4_word ts4_if_call_seq_u8_off134_883461C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t7;
    ts4_word t9;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 308);
        if ((ts4_word)t7 == 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
            if ((ts4_word)t9 != 0) {
                fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 352)));
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)1;
        }
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
        if ((ts4_word)t3 != 0) {
            fn_8832EDB0((ts4_word)0, (ts4_word)0, (ts4_word)16384, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 352)));
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883472D8: if_call_seq u8@0x134, u32@0x204, u32@0x204, u32@0x208, fn_8832EDB0, u8@0x134 */
ts4_word ts4_if_call_seq_u8_off134_883472D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t7;
    ts4_word t9;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 308);
        if ((ts4_word)t7 == 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 516);
            if ((ts4_word)t9 != 0) {
                fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 520)) + 16));
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)1;
        }
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 516);
        if ((ts4_word)t3 != 0) {
            fn_8832EDB0((ts4_word)0, (ts4_word)0, (ts4_word)16384, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 520)) + 16));
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88350280: if_call_seq lbl_88C8EB38, u32@lbl_88C8F3F8, fn_8834FB00, fn_883A1AE0, fn_8839CC70 */
ts4_word ts4_if_call_seq_lbl_88C8EB38_88350280(void)
{
    ts4_word p4;
    ts4_word p5;
    int t1;
    int t2;
    ts4_word t3;

    *(ts4_word *)lbl_88C8F3F8 = (ts4_word)(((ts4_word)lbl_88C8EB38 + 15) & 0xfffffff0);
    t1 = fn_8834FB00((ts4_word)1);
    p5 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = fn_883A1AE0((ts4_word)t1);
        p4 = (ts4_word)t2;
        if ((int)t2 == 0) {
            t3 = fn_8839CC70((ts4_word)32);
            p4 = (ts4_word)t3;
        }
        p5 = (ts4_word)p4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88358690: loop_call_seq u32@0x2d9c, fn_88356728, u32@0x2d9c, fn_88358250, u32@0x2d9c */
ts4_word ts4_loop_call_seq_u32_off2d9c_88358690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 11676);
    if ((ts4_word)a2 != (ts4_word)t1) {
        if ((ts4_word)a2 < (ts4_word)t1) {
            fn_88356728((ts4_word)a0, (ts4_word)0);
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 11676);
        if ((ts4_word)t4 < (ts4_word)a2) {
            do {
                fn_88358250((ts4_word)a0, (ts4_word)1);
                t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 11676);
            } while ((ts4_word)t6 < (ts4_word)a2);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88359A88: if_get u8@0x279, u32@0x0, u32@0x25c, u32@0x25c, u32@0x25c, u32@0x25c */
ts4_word ts4_if_get_u8_off279_88359A88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;
    ts4_word t2;
    int t9;
    int t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 633);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)(t1 & 0xf) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 604) = (ts4_word)(((t1) >> 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 604)));
    }
    if ((ts4_word)(t1 & 0xfffffff0) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 604) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 604)) - (t1 & 0xf));
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 604);
    if ((int)t9 > 64) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 604) = (ts4_word)64;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 604);
    if ((int)t11 < 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 604) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(t2) + 460) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t2) + 460)) | 2);
    return 0;
}

/* Swing_DLL.xex 0x883688D8: if_get u32@0x0, u32@0x280, u32@0x1d0, u8@0x284, u32@0x1d0, u32@0x280 */
ts4_word ts4_if_get_u32_off0_883688D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    int t2;
    int t3;
    unsigned char t4;
    int t5;
    int t8;
    int t9;
    unsigned char t10;
    ts4_word t11;
    int t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 640);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464);
    if ((int)t3 < (int)t2) {
        t4 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 644);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464) = (ts4_word)(((t4 << 2) | (t4 >> 30)) + t3);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 640);
        if ((int)(((t4 << 2) | (t4 >> 30)) + t3) > (int)t5) {
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464) = (ts4_word)t5;
        }
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464);
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 640);
    if ((int)t8 > (int)t9) {
        t10 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 644);
        t11 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464) = (ts4_word)(t11 - ((t10 << 2) | (t10 >> 30)));
        t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 640);
        if ((int)(t11 - ((t10 << 2) | (t10 >> 30))) < (int)t12) {
            *(volatile ts4_word *)((char *)(ts4_word)(t1) + 464) = (ts4_word)t12;
        }
    }
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 460) = (unsigned char)((*(volatile unsigned char *)((char *)(ts4_word)(t1) + 460)) | 1);
    return 0;
}

/* Swing_DLL.xex 0x8836B940: if_call_seq u32@0x114, u8@0x118, u8@0x118, fn_883A78E8, u32@0xf8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off114_8836B940(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    unsigned char t3;
    int t8;

    (void)a1;
    (void)a2;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
    if ((ts4_word)t1 == 0) {
        return 37;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 280);
    if ((ts4_word)t3 == 0) {
        fn_883A78E8((ts4_word)a0, (ts4_word)t1);
    }
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 248));
    *(unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)0;
    t8 = ts4_deref_deref_ptr_883A3C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 276)));
    if ((int)t8 == 4) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
        return 22;
    }
    return 0;
}

/* Swing_DLL.xex 0x8836CC60: if_call_seq u32@lbl_88B3302C, lbl_8802B898, u32@0x4, ts4_tailcall_fn_88315C60_88316068, u32@0x500, u32@0x500 */
ts4_word ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    t3 = ts4_tailcall_fn_88315C60_88316068((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)((int)a1 * (int)a2), (ts4_word)(ts4_word)lbl_8802B898, (ts4_word)33, (ts4_word)0);
    if ((ts4_word)t3 != 0 && (ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1280) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1280)) + ((int)a1 * (int)a2));
    }
    return t3;
}

/* Swing_DLL.xex 0x8836D198: if_call_seq u8@0x110, u32@0x500, fn_8832EDB0, u8@0x110, u8@0x110, u32@0x500 */
ts4_word ts4_if_call_seq_u8_off110_8836D198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 272);
        if ((ts4_word)t4 == 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1280)));
            *(unsigned char *)((char *)(ts4_word)(a0) + 272) = (unsigned char)1;
        }
    } else {
        fn_8832EDB0((ts4_word)0, (ts4_word)0, (ts4_word)128, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1280)));
        *(unsigned char *)((char *)(ts4_word)(a0) + 272) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8836DEB8: if_call_seq u32@0x16c, lbl_8802B8F8, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x16c */
ts4_word ts4_if_call_seq_u32_off16c_8836DEB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;
    ts4_word t16;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
    if ((ts4_word)t1 != 0 && (ts4_word)t1 != (ts4_word)(a0 + 324)) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802B8F8, (ts4_word)517);
        *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_8802B8F8, (ts4_word)522);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 220);
    if ((ts4_word)t11 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8802B8F8, (ts4_word)527);
        *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 316);
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    if ((ts4_word)t16 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t16, (ts4_word)(ts4_word)lbl_8802B8F8, (ts4_word)533);
        *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)0;
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)0;
    if ((ts4_word)t21 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t21, (ts4_word)(ts4_word)lbl_8802B8F8, (ts4_word)542);
        *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x88376998: loop_call_seq u32@0x0, lbl_8802BB80, u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off0_88376998(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p20;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != (ts4_word)a0) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv2) + 4))) + 0) = (ts4_word)t3;
            t5 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
            *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 4));
            t7 = *(ts4_word *)((char *)(ts4_word)(lv2) + 20);
            *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)lv2;
            *(ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)lv2;
            *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)0;
            if ((ts4_word)t7 != 0) {
                fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t7, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)90);
                *(ts4_word *)((char *)(ts4_word)(lv2) + 20) = (ts4_word)0;
            }
            t12 = *(ts4_word *)((char *)(ts4_word)(lv2) + 24);
            if ((ts4_word)t12 != 0) {
                fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t12, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)98);
                *(ts4_word *)((char *)(ts4_word)(lv2) + 24) = (ts4_word)0;
            }
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)lv2, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)102);
            p20 = (ts4_word)t3;
            lv2 = p20;
        } while ((ts4_word)p20 != (ts4_word)a0);
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)186);
    return 0;
}

/* Swing_DLL.xex 0x88377E08: if_get u32@0xdc, u32@0x130, u32@0x3c */
ts4_word ts4_if_get_u32_offdc_88377E08(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 220);
    if ((int)t1 != 0 && (int)t1 != 7) {
        return 56;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 304) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88379AB0: get u32@0x0, u32@0x58 */
ts4_word ts4_get_u32_off0_88379AB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x8837D2C0: if_tail fn_8837D100, fn_8837C680 */
ts4_word ts4_if_tail_fn_8837D100_8837D2C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == 0) {
        return fn_8837C680((ts4_word)a0, (ts4_word)a2, (ts4_word)a2);
    }
    return fn_8837D100((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88381228: if_call_seq fn_88381170, u32@0x3c, u8@0x2e0, u32@0x30, u32@0x1c, u32@0x2e8 */
ts4_word ts4_if_call_seq_fn_88381170_88381228(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    fn_88381170();
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t2 != 0 && (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 736)) != 0) {
        t5 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48))) + 28);
        t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 744);
        if ((ts4_word)(t5 & 0x200000) != 0) {
            fn_8832FD28((ts4_word)t2, (ts4_word)(t6 != 0), (ts4_word)1);
        } else {
            fn_8832FC40((ts4_word)t2, (ts4_word)(t6 != 0), (ts4_word)1);
        }
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 736) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883817E8: if_call_seq lbl_8802BE78, fn_883296A0, u8@-0x1 */
ts4_word ts4_if_call_seq_lbl_8802BE78_883817E8(ts4_word a0, ts4_word a1, ts4_word a2, int a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a0;
    (void)a1;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0 && (int)a3 >= 1) {
        fn_883296A0((ts4_word)a2, (ts4_word)(ts4_word)lbl_8802BE78, (ts4_word)(a3 + -1));
        *(unsigned char *)((char *)(ts4_word)((a2 + a3)) + -1) = (unsigned char)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88383C48: if_get ts4_call_vtable_slot11_883AC3C8, u32@0x184, u32@0x184, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_fn_883AC3C8_88383C48(ts4_word a0)
{
    ts4_word p8;
    int t1;
    ts4_word t3;

    t1 = ts4_call_vtable_slot11_883AC3C8();
    p8 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 20))))((ts4_word)t3, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
        }
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Swing_DLL.xex 0x88383F10: call_seq ts4_addr_lbl_8802BC90_883AC348, lbl_8802BF28, u32@0x0, fn_8831E168, lbl_88028C20, u32@0x50 */
ts4_word ts4_call_seq_fn_883AC348_88383F10(ts4_word a0)
{
    ts4_addr_lbl_8802BC90_883AC348();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BF28;
    fn_8831E168((ts4_word)(a0 + 80));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(ts4_word)lbl_88028C20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88386510: call_seq ts4_call_seq_fn_883AC348_883AE450, lbl_8802BFE8, u32@0x0, fn_8831E168, lbl_88028C20, u32@0x58 */
ts4_word ts4_call_seq_fn_883AE450_88386510(ts4_word a0)
{
    ts4_call_seq_fn_883AC348_883AE450();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BFE8;
    fn_8831E168((ts4_word)(a0 + 88));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(ts4_word)lbl_88028C20;
    fn_8831E168((ts4_word)(a0 + 400));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 400) = (ts4_word)(ts4_word)lbl_88029048;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 768) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 780) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 772) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 784) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 776) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88389C40: if_call_seq u32@0x14, u32@0x10fc, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, u32@0x14, u32@0x168, u32@0x10fc */
ts4_word ts4_if_call_seq_u32_off14_88389C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t11;
    ts4_word t4;
    ts4_word t8;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)(a1 & 0xff) == 0) {
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
        *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)(t11 & 0xfffffff7);
    } else {
        if ((ts4_word)(a2 & 0xff) != 0) {
            ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4348)));
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)0;
            ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4348)));
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
        if ((ts4_word)t8 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 280)) + 1);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x8838BBF0: if_get u32@0x18, u32@0x18, u32@0x14, u32@0x38, u32@0x14, u32@0x38 */
void ts4_if_get_u32_off18_8838BBF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((int)(t1 & 0x400) != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(t1 | 1024);
    *(ts4_word *)((char *)(ts4_word)(a1) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 56);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 44) = (ts4_word)a1;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(t4 | 32);
    return;
}

/* Swing_DLL.xex 0x8838DB00: if_call_seq u32@lbl_88C922FC, u32@lbl_88C922FC, ts4_tailcall_NetDll_WSACleanup_884F0238, ts4_tailcall_NetDll_XNetCleanup_884EFEA0 */
ts4_word ts4_if_call_seq_u32_lbl_88C922FC_8838DB00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88C922FC;
    if ((int)t1 > 0) {
        *(volatile ts4_word *)lbl_88C922FC = (ts4_word)(t1 + -1);
        if ((int)(t1 + -1) == 0) {
            t2 = ts4_tailcall_NetDll_WSACleanup_884F0238();
            ts4_tailcall_NetDll_XNetCleanup_884EFEA0((ts4_word)t2);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88399670: get  */
float ts4_get_88399670(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a0) + 4);
    t2 = *(float *)lbl_8802E940;
    return ((t1 - t2) * (*(float *)lbl_8802E95C));
}

/* Swing_DLL.xex 0x883996A8: get  */
float ts4_get_883996A8(ts4_word a0)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 12);
    return (t1 * (*(float *)lbl_88029224));
}

/* Swing_DLL.xex 0x883996D8: get  */
float ts4_get_883996D8(ts4_word a0)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 20);
    return (t1 * (*(float *)lbl_88001974));
}

/* Swing_DLL.xex 0x88399708: get  */
float ts4_get_88399708(ts4_word a0)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 32);
    return (t1 * (*(float *)lbl_8802E958));
}

/* Swing_DLL.xex 0x88399738: if_get  */
float ts4_if_get_88399738(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a0) + 40);
    t2 = *(float *)lbl_8802E958;
    if (!(t1 < t2)) {
        return (*(float *)lbl_88001A68);
    }
    return (*(float *)lbl_88001A20);
}

/* Swing_DLL.xex 0x883A3720: if_call_seq u32@0x50, fn_88330450 */
ts4_word ts4_if_call_seq_u32_off50_883A3720(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)(t1 + 800) != 0) {
        fn_88330450((ts4_word)(t1 + 1076));
    }
    return 0;
}

/* Swing_DLL.xex 0x883A3BE8: if_get u32@0x0, u32@0x0, u32@0x18 */
ts4_word ts4_if_get_u32_off0_883A3BE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 != 9) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x883A69B0: loop_call_seq fn_883A5320, u32@0x4, u32@0x460, fn_885651F8, u32@0x4, u32@0x3c */
ts4_word ts4_loop_call_seq_fn_883A5320_883A69B0(ts4_word a0, ts4_word a1)
{
    ts4_word lv9;
    ts4_word p12;
    ts4_word t3;
    ts4_word t17;

    (void)a0;
    fn_883A5320();
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 1120);
    if ((ts4_word)t3 != 0) {
        fn_885651F8((ts4_word)t3);
    }
    ts4_if_call_seq_u32_off0_883B8088((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 60)));
    lv9 = (ts4_word)0;
    do {
        ts4_if_call_seq_u32_off0_883B6BF0((ts4_word)((lv9 + (*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 128));
        p12 = (ts4_word)(lv9 + 12);
        lv9 = p12;
    } while ((ts4_word)p12 < 96);
    fn_885651F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    fn_885651F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t17 = fn_885651F8((ts4_word)a1);
    return t17;
}

/* Swing_DLL.xex 0x883AA280: if_get u32@0x4, u32@0x48, u32@0x58, u32@0x34, u32@0x34, u32@0x48 */
ts4_word ts4_if_get_u32_off4_883AA280(ts4_word a0, int a1)
{
    int t1;
    int t7;
    ts4_word t9;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 != 0) {
        if ((int)a1 < 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
            if ((int)t7 >= 3) {
                t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
                return ((t9 << 5) + (*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
            }
            return (*(ts4_word *)((char *)(ts4_word)(a0) + 72));
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        if ((int)a1 >= (int)t5) {
            return 0;
        }
        return ((*(ts4_word *)((char *)(ts4_word)(a0) + 72)) + (a1 << 5));
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 72));
}

/* Swing_DLL.xex 0x883AA2E0: if_get u32@0x4, u32@0x4c, u32@0x58, u32@0x34, u32@0x34, u32@0x4c */
ts4_word ts4_if_get_u32_off4_883AA2E0(ts4_word a0, int a1)
{
    int t1;
    int t7;
    ts4_word t9;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 != 0) {
        if ((int)a1 < 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
            if ((int)t7 >= 3) {
                t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
                return ((t9 << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
            }
            return (*(ts4_word *)((char *)(ts4_word)(a0) + 76));
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        if ((int)a1 >= (int)t5) {
            return 0;
        }
        return ((*(ts4_word *)((char *)(ts4_word)(a0) + 76)) + (a1 << 4));
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 76));
}

/* Swing_DLL.xex 0x883AAC28: if_call_seq u32@0x58, u32@0x4, u32@0x58, u32@0x58, fn_883AA870, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off58_883AAC28(ts4_word a0, ts4_word a1)
{
    int t1;
    int t2;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 88);
    if ((int)t1 != 1) {
        return -131;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 88) = (ts4_word)2;
    if ((int)t2 != 0) {
        t3 = fn_883AA870((ts4_word)a0, (ts4_word)a1);
        if ((int)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            fn_883A9440((ts4_word)a0, (ts4_word)a1);
        }
        return t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 88) = (ts4_word)3;
    return 0;
}

/* Swing_DLL.xex 0x883AC430: if_get u32@0xc, u32@0x8, u32@0x8, u32@0x24, u32@0x24 */
ts4_word ts4_if_get_u32_offc_883AC430(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) + -1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((((1 << 7) | (1 >> 25)) & 0xf0) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) & 0xffffff0f));
    return 0;
}

/* Swing_DLL.xex 0x883AC490: if_get u32@0x24, u8@0x0 */
ts4_word ts4_if_get_u32_off24_883AC490(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) >> 5) & 0x1);
    return 0;
}

/* Swing_DLL.xex 0x883B1D68: set  */
void ts4_set_883B1D68(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    *(float *)((char *)(ts4_word)(a0) + 12) = ((*(float *)lbl_88001A68) - f1);
    return;
}

/* Swing_DLL.xex 0x883B6C48: if_call_seq u32@0x8, u32@0x0, fn_88565320, u32@0x0, u32@0x4, fn_88565320 */
ts4_word ts4_if_call_seq_u32_off8_883B6C48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 < (ts4_word)a1) {
        t3 = fn_88565320((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)((1 << a1) << 2), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(1 << a1));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        if ((ts4_word)t3 == 0) {
            return 0;
        }
        t5 = fn_88565320((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)((1 << a1) << 2));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t5;
        if ((ts4_word)t5 == 0) {
            return 0;
        }
        ts4_memset((ts4_word)t5, (ts4_word)0, (ts4_word)((1 << a1) << 2));
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x883B70A0: get u32@0x14 */
ts4_word ts4_get_u32_off14_883B70A0(ts4_word a0)
{
    return (8 - ((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) & 0x7));
}

/* Swing_DLL.xex 0x883B7328: if_call_seq fn_883B70D8, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_883B70D8_883B7328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    int t1;

    (void)a0;
    (void)a1;
    t1 = fn_883B70D8();
    p3 = (ts4_word)t1;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) << (32 - a3)) >> (32 - a3));
        p3 = (ts4_word)1;
    }
    return p3;
}

/* Swing_DLL.xex 0x883B9150: if_call_seq fn_88565258, u32@0x0, u32@0x0, fn_885651F8, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88565258_883B9150(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p1;
    ts4_word t2;
    ts4_word t4;

    if ((ts4_word)a0 > (ts4_word)((1073676288) | 65535)) {
        return 0;
    }
    p1 = (ts4_word)(a0 << 2);
    if ((ts4_word)(a0 << 2) == 0) {
        p1 = (ts4_word)1;
    }
    t2 = fn_88565258((ts4_word)p1);
    if ((ts4_word)t2 == 0) {
        return 0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t4 != 0) {
        fn_885651F8((ts4_word)t4);
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
    return 1;
}

/* Swing_DLL.xex 0x883BAB60: loop_fn  */
ts4_word ts4_loop_fn_883BAB60(ts4_word a0)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p3;
    ts4_word p4;

    if ((ts4_word)((a0) >> 1) == 0) {
        return 0;
    }
    lv1 = (ts4_word)((a0) >> 1);
    lv2 = (ts4_word)0;
    do {
        p3 = (ts4_word)((lv1) >> 1);
        p4 = (ts4_word)(lv2 + 1);
        lv1 = p3;
        lv2 = p4;
    } while ((ts4_word)p3 != 0);
    return lv2;
}

/* Swing_DLL.xex 0x883BAB98: get u32@0x0, u8@0x5 */
ts4_word ts4_get_u32_off0_883BAB98(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 5)) & 0x2);
}

/* Swing_DLL.xex 0x883BABA8: get u32@0x0, u8@0x5 */
ts4_word ts4_get_u32_off0_883BABA8(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 5)) & 0x4);
}

/* Swing_DLL.xex 0x883BB920: if_call_seq ts4_memset, u32@0x4, u32@0x18, fn_8836CBE8, u32@0x0, u32@0x18 */
ts4_word ts4_if_call_seq_ts4_memset_883BB920(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    if ((ts4_word)a1 != 0) {
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)360);
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)4608;
        *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)64;
        t2 = fn_8836CBE8((ts4_word)a0, (ts4_word)4608);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
        t4 = fn_8836CBE8((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) << 2));
        *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)t4;
        t6 = fn_8836CBE8((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) << 3));
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)t6;
        if (((ts4_word)t7 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)) != 0) && (ts4_word)t6 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 336) = (ts4_word)a2;
            return 0;
        }
        ts4_if_call_seq_u32_off0_883BAC48((ts4_word)a0, (ts4_word)a1);
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x883BD0F0: if_get u32@0x14, u32@0x10, u32@0x14, u32@0x14 */
ts4_word ts4_if_get_u32_off14_883BD0F0(ts4_word a0, int a1)
{
    if ((int)a1 != 0 && (int)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + a1) > (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 16))) {
        return -131;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + a1);
    return 0;
}

/* Swing_DLL.xex 0x883BDA50: if_call_seq u32@0x24, ts4_if_call_seq_u32_off24_883BD9D8, fn_8836CD70 */
ts4_word ts4_if_call_seq_u32_off24_883BDA50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    p4 = (ts4_word)a0;
    if ((int)t1 != 0) {
        ts4_if_call_seq_u32_off24_883BD9D8((ts4_word)a0, (ts4_word)a1);
        t3 = fn_8836CD70((ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883BE820: if_call_seq u32@0x8, fn_883BE648, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off8_883BE820(ts4_word a0)
{
    int t1;
    int t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 > 0) {
        t2 = fn_883BE648();
        if ((int)t2 >= 0) {
            return (*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24))) + (t2 << 2)));
        }
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x883C7098: get u16@0x64 */
ts4_word ts4_get_u16_off64_883C7098(ts4_word a0)
{
    return (((*(unsigned short *)((char *)(ts4_word)(a0) + 100)) >> 5) & 0x1);
}

/* Swing_DLL.xex 0x883D2588: if_get u32@0x0, u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_if_get_u32_off0_883D2588(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32612)) + 0);
    if ((ts4_word)t1 == 0) {
        return 31;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32612)) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 12))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x883E7728: get u32@0x1c, u32@0x20, u32@0x0, u32@0x4 */
void ts4_get_u32_off1c_883E7728(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x883EA9C8: get u32@0x14, u32@0x18, u32@0x0, u32@0x4 */
void ts4_get_u32_off14_883EA9C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x883EE5B0: if_get u32@0x9c, ts4_lookup_then_forward_88318348 */
ts4_word ts4_if_get_u32_off9c_883EE5B0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((ts4_word)t1 != 0) {
        return ts4_lookup_then_forward_88318348((ts4_word)t1);
    }
    return 36;
}

/* Swing_DLL.xex 0x883EE5E0: if_get u32@0x9c, fn_88318298 */
ts4_word ts4_if_get_u32_off9c_883EE5E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((ts4_word)t1 != 0) {
        return fn_88318298((ts4_word)t1);
    }
    return 36;
}

/* Swing_DLL.xex 0x883EE5F8: if_get u32@0x9c, ts4_if_call_seq_fn_8832BFC0_88318300 */
ts4_word ts4_if_get_u32_off9c_883EE5F8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((ts4_word)t1 != 0) {
        return ts4_if_call_seq_fn_8832BFC0_88318300((ts4_word)t1);
    }
    return 36;
}

/* Swing_DLL.xex 0x883EE628: if_get u32@0x9c, ts4_lookup_then_forward_88318420 */
ts4_word ts4_if_get_u32_off9c_883EE628(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((ts4_word)t1 != 0) {
        return ts4_lookup_then_forward_88318420((ts4_word)t1);
    }
    return 36;
}

/* Swing_DLL.xex 0x883F2C90: get u32@0x18, fn_883FDB00 */
ts4_word ts4_get_u32_off18_883F2C90(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_883FDB00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)));
}

/* Swing_DLL.xex 0x883F3238: addr lbl_88039DD8, u32@0x4, u32@0x0, u32@0xc, u32@0x10, u32@0x14 */
void ts4_addr_lbl_88039DD8_883F3238(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88039DD8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a0 + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(a0 + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(a0 + 24);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(a0 + 24);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(a0 + 36);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(a0 + 36);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883F8E48: set u32@0x14, u8@0x18, u32@0x1c, u32@0x2c, u32@0x30, u32@0x34 */
ts4_word ts4_set_u32_off14_883F8E48(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(a0 + 108);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(a0 + 108);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883FADF0: loop_call_seq u32@0x8, lbl_8803A098, u32@lbl_88B3302C, u32@0x0, u32@0x4, fn_88315F10 */
ts4_word ts4_loop_call_seq_u32_off8_883FADF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != (ts4_word)(a0 + 8)) {
        lv2 = (ts4_word)t1;
        do {
            t3 = *(ts4_word *)lbl_88B3302C;
            t4 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4)), (ts4_word)lv2, (ts4_word)(ts4_word)lbl_8803A098, (ts4_word)84);
            p7 = (ts4_word)t4;
            lv2 = p7;
        } while ((ts4_word)p7 != (ts4_word)(a0 + 8));
    }
    return 0;
}

/* Swing_DLL.xex 0x883FB8D8: if_get u32@0x98, u32@0x9c */
ts4_word ts4_if_get_u32_off98_883FB8D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t1))((ts4_word)2, (ts4_word)a1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 156)));
    }
    return 97;
}

/* Swing_DLL.xex 0x883FB900: if_get u32@0x98, u32@0x9c */
ts4_word ts4_if_get_u32_off98_883FB900(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t1))((ts4_word)3, (ts4_word)a1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 156)));
    }
    return 97;
}

/* Swing_DLL.xex 0x883FFB28: if_get u32@0x4, u32@0xa0, u32@0xa8, fn_883FBC58 */
ts4_word ts4_if_get_u32_off4_883FFB28(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 160);
    if ((ts4_word)t2 != 0) {
        return fn_883FBC58((ts4_word)t2, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 168)));
    }
    return a1;
}

/* Swing_DLL.xex 0x88408AA0: if_call_seq u32@0x8c, u32@lbl_88CACF08, KeTlsGetValue, u32@0x84, fn_8841A590, fn_88408D58 */
ts4_word ts4_if_call_seq_u32_off8c_88408AA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)), (ts4_word)(t1 << 2), (ts4_word)23);
    }
    fn_88408D58((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t9, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)60);
    }
    return a0;
}

/* Swing_DLL.xex 0x8840EDF8: call_seq lbl_8803AA08, u16@0x6, u32@0x0, u32@0x10, u32@0x14, u32@0x18 */
ts4_word ts4_call_seq_lbl_8803AA08_8840EDF8(ts4_word a0)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803AA08;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
    fn_8840EE78((ts4_word)(a0 + 8));
    return a0;
}

/* Swing_DLL.xex 0x8840F158: fn  */
ts4_word ts4_fn_8840F158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((((a2 << 4) | a1) << 2) | a0) & 0xff);
}

/* Swing_DLL.xex 0x8841A820: if_get u32@-0xc, u32@-0x8, u32@-0x10, fn_8841A590 */
ts4_word ts4_if_get_u32_0xc_8841A820(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + -12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + -8);
    *(ts4_word *)((char *)(ts4_word)(a1) + -16) = (ts4_word)((3735879680) | 48879);
    return fn_8841A590((ts4_word)a0, (ts4_word)(a1 + -16), (ts4_word)(t1 + 16), (ts4_word)t2);
}

/* Swing_DLL.xex 0x8841AA30: if_tailcall fn_88422BA0 */
ts4_word ts4_if_tailcall_fn_88422BA0_8841AA30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 == 0) {
        return a0;
    }
    return fn_88422BA0((ts4_word)a0, (ts4_word)a2, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x8841AAA8: if_get u32@0x8, u32@0x8 */
void ts4_if_get_u32_off8_8841AAA8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) | 2147483648);
    return;
}

/* Swing_DLL.xex 0x8841B0E8: get u32@0x18, u8@0x0 */
void ts4_get_u32_off18_8841B0E8(ts4_word a0, ts4_word a1)
{
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((*(ts4_word *)((char *)(ts4_word)(a1) + 24)) != 0);
    return;
}

/* Swing_DLL.xex 0x8841B128: if_get u32@0x1c, u32@0x10 */
ts4_word ts4_if_get_u32_off1c_8841B128(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 >= 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x8841B1B8: if_get u32@0x8, u32@0x0, u32@0x2c, vcall, u32@0x10, u32@0x14 */
ts4_word ts4_if_get_u32_off8_8841B1B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1);
    if ((int)t4 >= 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        return ((t5 - (*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + t4);
    }
    return -1;
}

/* Swing_DLL.xex 0x8841B228: get u32@lbl_88CACF08, KeTlsGetValue, u32@0x0, u32@0x0, vcall, u32@0x0 */
ts4_word ts4_get_u32_lbl_88CACF08_8841B228(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t5;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2, (ts4_word)64, (ts4_word)a1, (ts4_word)26);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    return a0;
}

/* Swing_DLL.xex 0x8841B2A8: get u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off0_8841B2A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3, (ts4_word)t1);
    return t6;
}

/* Swing_DLL.xex 0x8841B520: if_fn  */
ts4_word ts4_if_fn_8841B520(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((int)a1 > 16) {
        return (((a1 + 15) & 0xfffffff0) + 16);
    }
    return (a1 + 8);
}

/* Swing_DLL.xex 0x8841B580: if_addr lbl_8803DA3C, u32@0x0, u32@lbl_88B3C200, vcall */
ts4_word ts4_if_addr_lbl_8803DA3C_8841B580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DA3C;
    p3 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)lbl_88B3C200)))((ts4_word)a0);
        p3 = (ts4_word)a0;
    }
    return p3;
}

/* Swing_DLL.xex 0x8841B608: get u8@lbl_88CAD334, u8@0x0 */
void ts4_get_u8_lbl_88CAD334_8841B608(ts4_word a0)
{
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)lbl_88CAD334);
    return;
}

/* Swing_DLL.xex 0x8841B618: get u32@lbl_88CAD338, KeTlsGetValue, fn_8841C428, u32@lbl_88CACF08, KeTlsGetValue, u32@0x0 */
ts4_word ts4_get_u32_lbl_88CAD338_8841B618(void)
{
    ts4_word t2;
    ts4_word t5;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    fn_8841C428((ts4_word)t2);
    t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5);
    fn_8841A740((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x8841B670: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, lbl_8803DAD4, u16@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8841B670(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)8, (ts4_word)21);
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)8;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803DAD4;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    return t3;
}

/* Swing_DLL.xex 0x8841BC50: get u32@lbl_88B3C460 */
ts4_word ts4_get_u32_lbl_88B3C460_8841BC50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)lbl_88B3C460)))((ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8841BEF0: call_seq lbl_8803DAE8, u16@0x6, u32@0x0, fn_88423CE0, u32@0x14, u32@0x18 */
ts4_word ts4_call_seq_lbl_8803DAE8_8841BEF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DAE8;
    fn_88423CE0((ts4_word)(a0 + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a2;
    return a0;
}

/* Swing_DLL.xex 0x8841C0C8: call_seq fn_88423788, u8@0x0 */
ts4_word ts4_call_seq_fn_88423788_8841C0C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_88423788((ts4_word)(a1 + 8), (ts4_word)a2, (ts4_word)0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(t1 == 0);
    return a0;
}

/* Swing_DLL.xex 0x8841C390: get u32@0x0, u32@0x4 */
void ts4_get_u32_off0_8841C390(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    return;
}

/* Swing_DLL.xex 0x8841C3A0: if_call_seq u32@lbl_88CACF08, KeTlsGetValue, u32@0x50, fn_8841A328, u32@0x54, u32@0x54 */
ts4_word ts4_if_call_seq_u32_lbl_88CACF08_8841C3A0(void)
{
    ts4_word p8;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t10;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 80);
    if ((ts4_word)t3 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 84)) + -1);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
        p8 = (ts4_word)t3;
    } else {
        t4 = fn_8841A328((ts4_word)t2, (ts4_word)3);
        p8 = (ts4_word)t4;
    }
    t10 = KeTlsSetValue((ts4_word)(*(ts4_word *)lbl_88CAD338), (ts4_word)p8);
    *(volatile unsigned char *)((char *)(ts4_word)(p8) + 16) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(p8) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(p8) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(p8) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(p8) + 12) = (ts4_word)0;
    return t10;
}

/* Swing_DLL.xex 0x8841CA58: call_seq ts4_tailcall_fn_88420A90_88420C20, fn_8841C9F0 */
ts4_word ts4_call_seq_fn_88420C20_8841CA58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[18];
    ts4_word t2;

    ts4_tailcall_fn_88420A90_88420C20((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_8841C9F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t2;
}

/* Swing_DLL.xex 0x8841CBA8: call_seq fn_8841C970, fn_8841C9F0 */
ts4_word ts4_call_seq_fn_8841C970_8841CBA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[18];
    ts4_word t2;

    fn_8841C970((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    t2 = fn_8841C9F0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8841CE58: if_get u32@0x0, lbl_88029198, u32@0x10, vcall, u32@0x0, fn_88421338 */
ts4_word ts4_if_get_u32_off0_8841CE58(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t3;

    if ((ts4_word)a1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t5 = fn_88421338((ts4_word)a1);
        t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t4) + 16))))((ts4_word)a0, (ts4_word)a1, (ts4_word)t5);
        return t7;
    }
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_88029198, (ts4_word)6);
    return t3;
}

/* Swing_DLL.xex 0x8841D058: if_get u32@0x8, u32@0x0, lbl_88029198, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off8_8841D058(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t6 = fn_88421338((ts4_word)a1);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)t6);
        return a0;
    }
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)(ts4_word)lbl_88029198, (ts4_word)6);
    return a0;
}

/* Swing_DLL.xex 0x8841D730: call_seq lbl_8803DE18, u16@0x6, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510 */
ts4_word ts4_call_seq_lbl_8803DE18_8841D730(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DE18;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)20, (ts4_word)26);
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)20;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803DDEC;
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)1;
    fn_8841D800((ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x8841F058: if_get u32@0x24, fn_8841EA48 */
ts4_word ts4_if_get_u32_off24_8841F058(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        return fn_8841EA48((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88421308: loop_get u8@0x0 */
void ts4_loop_get_u8_off0_88421308(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p3;
    unsigned char t2;

    lv1 = (ts4_word)a1;
    do {
        t2 = *(unsigned char *)((char *)(ts4_word)(lv1) + 0);
        *(unsigned char *)((char *)(ts4_word)((a0 - a1)) + lv1) = (unsigned char)t2;
        p3 = (ts4_word)(lv1 + 1);
        lv1 = p3;
    } while ((ts4_word)t2 != 0);
    return;
}

/* Swing_DLL.xex 0x88421328: if_tailcall ts4_copy_bytes */
ts4_word ts4_if_tailcall_ts4_copy_bytes_88421328(ts4_word a0, ts4_word a1, int a2)
{
    if ((int)a2 == 0) {
        return a0;
    }
    return ts4_copy_bytes((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88421450: tailcall memcpy */
ts4_word ts4_tailcall_memcpy_88421450(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return memcpy((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88422478: if_get u32@lbl_88CAD56C */
ts4_word ts4_if_get_u32_lbl_88CAD56C_88422478(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        return a0;
    }
    return (*(ts4_word *)lbl_88CAD56C);
}

/* Swing_DLL.xex 0x884225C0: if_call_seq u8@0xd, ts4_addr_lbl_88B3C5B8_88426110, u16@0x8, u8@0x0, u8@0x0, ts4_get_u32_off4_88426130 */
ts4_word ts4_if_call_seq_u8_offd_884225C0(ts4_word a0)
{
    ts4_word t2;
    unsigned short t3;
    unsigned char t5;
    ts4_word t6;
    ts4_word t7;

    t2 = ts4_addr_lbl_88B3C5B8_88426110((ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 13)));
    t3 = *(unsigned short *)((char *)(ts4_word)(t2) + 8);
    if ((int)((short)t3) <= 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
        if ((ts4_word)t5 == 25) {
            t6 = ts4_get_u32_off4_88426130((ts4_word)a0);
            t7 = ts4_get_u32_off8_8841EF28((ts4_word)t6);
            return t7;
        }
        return -1;
    }
    return ((short)t3);
}

/* Swing_DLL.xex 0x88422F80: if_get u32@lbl_88CAD56C, fn_884223A0 */
ts4_word ts4_if_get_u32_lbl_88CAD56C_88422F80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    p2 = (ts4_word)a3;
    if ((ts4_word)a3 == 0) {
        p2 = (ts4_word)(*(ts4_word *)lbl_88CAD56C);
    }
    return fn_884223A0((ts4_word)0, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)p2);
}

/* Swing_DLL.xex 0x884231B8: if_get u32@0x0, u32@lbl_88B3C200, vcall, u32@lbl_88B3C200, u32@0x4, vcall */
ts4_word ts4_if_get_u32_off0_884231B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)lbl_88B3C200)))((ts4_word)t1);
        t4 = *(volatile ts4_word *)lbl_88B3C200;
        t6 = ((ts4_word (*)(ts4_word))(t4))((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)));
        p7 = (ts4_word)t6;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p7;
}

/* Swing_DLL.xex 0x88423640: loop_fn  */
ts4_word ts4_loop_fn_88423640(int a0)
{
    ts4_word lv1;
    ts4_word p2;
    ts4_word p3;

    p3 = (ts4_word)4;
    if ((int)a0 > 4) {
        lv1 = (ts4_word)4;
        do {
            p2 = (ts4_word)(lv1 << 1);
            lv1 = p2;
        } while ((int)p2 < (int)a0);
        p3 = (ts4_word)lv1;
    }
    return (p3 << 5);
}

/* Swing_DLL.xex 0x884237F0: if_call_seq fn_88423730, u32@0x8, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88423730_884237F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    int t1;
    int t2;

    t1 = fn_88423730((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 <= (int)t2) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((t2 + t1) + 1) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))));
        p6 = (ts4_word)0;
    } else {
        p6 = (ts4_word)1;
    }
    return p6;
}

/* Swing_DLL.xex 0x88423DC8: if_call_seq fn_88423730, u32@0x8, fn_88423858 */
ts4_word ts4_if_call_seq_fn_88423730_88423DC8(ts4_word a0, ts4_word a1)
{
    int t1;
    int t2;

    t1 = fn_88423730((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 <= (int)t2) {
        fn_88423858((ts4_word)a0, (ts4_word)t1);
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x884246A8: if_call_seq u32@0xc, ts4_tailcall_fn_885659E8_88565AF8, u8@0x10 */
ts4_word ts4_if_call_seq_u32_offc_884246A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t2;

    t2 = ts4_tailcall_fn_885659E8_88565AF8((ts4_word)a1, (ts4_word)1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    if ((int)t2 <= 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    }
    return t2;
}

/* Swing_DLL.xex 0x884246F0: get u8@0x10, u8@0x0 */
void ts4_get_u8_off10_884246F0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 16));
    return;
}

/* Swing_DLL.xex 0x88424720: call_seq u32@0xc, fn_88566750 */
ts4_word ts4_call_seq_u32_offc_88424720(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88566750((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    return (t2 != 0);
}

/* Swing_DLL.xex 0x88424758: call_seq lbl_8803E710, u16@0x6, u32@0x0, u32@0x8, lbl_880D2F14, u8@0x10 */
ts4_word ts4_call_seq_lbl_8803E710_88424758(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E710;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    t1 = ts4_tailcall_fn_885655E8_88565748((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D2F14);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)(t1 != 0);
    return a0;
}

/* Swing_DLL.xex 0x884247C8: if_call_seq u32@0xc, lbl_8803E710, u32@0x0, fn_88566FE8, lbl_8803A308, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_884247C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E710;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88566FE8((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_8803E710);
        p3 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x88424818: get u32@0x0, u32@0x2c, vcall, u32@0x8 */
ts4_word ts4_get_u32_off0_88424818(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return ((t3 + 1) == 0);
}

/* Swing_DLL.xex 0x88424860: get u32@0x0, u32@0x8, u32@0x28 */
ts4_word ts4_get_u32_off0_88424860(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 40))))((ts4_word)a0, (ts4_word)t2, (ts4_word)0);
}

/* Swing_DLL.xex 0x88424878: if_call_seq u32@0xc, lbl_8803E710, u32@0x0, fn_88566FE8, lbl_8803A308, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_88424878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E710;
    if ((ts4_word)t1 != 0) {
        fn_88566FE8((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_8803E710);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t5, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x88424FB0: if_call_seq u32@0x8, u8@0xc, fn_88566FE8, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_88424FB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12)) != 0) {
        t3 = fn_88566FE8((ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x88425000: if_call_seq u32@0x8, fn_88565F50, u32@0x8, u32@0x8, u8@0xc, fn_88566FE8 */
ts4_word ts4_if_call_seq_u32_off8_88425000(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    int t2;
    ts4_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        t2 = fn_88565F50((ts4_word)a1, (ts4_word)1, (ts4_word)a2, (ts4_word)t1);
        if ((int)t2 <= 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
            if ((ts4_word)t4 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12)) != 0) {
                fn_88566FE8((ts4_word)t4);
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        }
        p9 = (ts4_word)t2;
    } else {
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x884250D8: call_seq u32@0x8, fn_88566750 */
ts4_word ts4_call_seq_u32_off8_884250D8(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88566750((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    return (t2 != 0);
}

/* Swing_DLL.xex 0x88425110: if_call_seq lbl_8803E76C, u16@0x6, u32@0x0, u8@0xc, ts4_addr_lbl_88C30DA8_88567BC8, ts4_addr_lbl_88C30DA8_88567BC8 */
ts4_word ts4_if_call_seq_lbl_8803E76C_88425110(ts4_word a0, int a1)
{
    ts4_word p3;
    ts4_word t2;
    ts4_word t1;

    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E76C;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    if ((int)a1 == 2) {
        t2 = ts4_addr_lbl_88C30DA8_88567BC8();
        p3 = (ts4_word)(t2 + 64);
    } else {
        t1 = ts4_addr_lbl_88C30DA8_88567BC8();
        p3 = (ts4_word)(t1 + 32);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p3;
    return a0;
}

/* Swing_DLL.xex 0x88425178: if_call_seq lbl_8803E76C, u16@0x6, u32@0x0, u32@0x8, u8@0xc, lbl_880D2F18 */
ts4_word ts4_if_call_seq_lbl_8803E76C_88425178(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E76C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
    if ((ts4_word)a1 != 0) {
        t1 = ts4_tailcall_fn_885655E8_88565748((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D2F18);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    }
    return a0;
}

/* Swing_DLL.xex 0x884251E0: if_call_seq u32@0x8, lbl_8803E76C, u32@0x0, u8@0xc, fn_88566FE8, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off8_884251E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E76C;
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12)) != 0) {
        t3 = fn_88566FE8((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_8803E76C);
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p4;
}

/* Swing_DLL.xex 0x88425248: if_call_seq u32@0x8, lbl_8803E76C, u32@0x0, u8@0xc, fn_88566FE8, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off8_88425248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E76C;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12)) != 0) {
        fn_88566FE8((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_8803E76C);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t6 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t6, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x884252E8: addr lbl_8803E794 */
ts4_word ts4_addr_lbl_8803E794_884252E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    return ((ts4_word (*)(ts4_word, ts4_word))(a3))((ts4_word)(ts4_word)lbl_8803E794, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88425570: if_call_seq lbl_8803A308, u32@0x14, u32@0x8, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_8803A308_88425570(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_8803A308;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8803A308;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(ts4_word)lbl_8803A308, (ts4_word)(a1 & 0x1));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x88426160: if_get u32@0x14, fn_8841EA48 */
ts4_word ts4_if_get_u32_off14_88426160(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        return fn_8841EA48((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x884262E8: get u16@0x10, u8@0x0 */
void ts4_get_u16_off10_884262E8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(((*(unsigned short *)((char *)(ts4_word)(a1) + 16)) >> 9) & 0x1);
    return;
}

/* Swing_DLL.xex 0x884263F0: if_get u8@0xd, u32@0x4, ts4_get_u32_off8_8841EF28, lbl_88B3C5B8 */
ts4_word ts4_if_get_u8_offd_884263F0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    if ((ts4_word)t1 != 24 && (ts4_word)t1 != 31) {
        if ((ts4_word)t1 != 25) {
            return ((short)(*(unsigned short *)((char *)(ts4_word)(((t1 + (t1 << 1)) << 2)) + ((ts4_word)lbl_88B3C5B8 + 8))));
        }
        return ts4_get_u32_off8_8841EF28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    }
    return -1;
}

/* Swing_DLL.xex 0x884264B8: if_call_seq fn_88426178, u8@0x0, u16@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88426178_884264B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_88426178((ts4_word)a0);
    if ((int)t1 != 1) {
        if ((int)t1 != 2) {
            if ((int)t1 == 4) {
                *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a2;
            }
        } else {
            *(unsigned short *)((char *)(ts4_word)(a1) + 0) = (unsigned short)a2;
        }
    } else {
        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)a2;
    }
    return t1;
}

/* Swing_DLL.xex 0x88427A08: if_get u32@0xc, fn_8841EA48 */
ts4_word ts4_if_get_u32_offc_88427A08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        return fn_8841EA48((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88427C08: get u32@0x8 */
ts4_word ts4_get_u32_off8_88427C08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (~(t1 | t1));
}

/* Swing_DLL.xex 0x88427C18: addr lbl_8803EAEC, u16@0x6, u32@0x0, u32@0x8 */
void ts4_addr_lbl_8803EAEC_88427C18(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803EAEC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(~(a1 | a1));
    return;
}

/* Swing_DLL.xex 0x88428B98: if_call_seq fn_884214A8, u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_fn_884214A8_88428B98(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t4;
    ts4_word t6;

    t1 = fn_884214A8((ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p5 = (ts4_word)t1;
    if ((int)t3 == (int)(t2 & 0x3fffffff)) {
        t4 = fn_8841C678((ts4_word)a0, (ts4_word)4);
        p5 = (ts4_word)t4;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)((t6 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return p5;
}

/* Swing_DLL.xex 0x88428F40: if_get u32@0x20, ts4_tailcall_NetDll_recv_884F0318, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off20_88428F40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    int t1;
    int t2;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 != -1) {
        t2 = ts4_tailcall_NetDll_recv_884F0318((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
        p6 = (ts4_word)t2;
        if ((int)t2 <= 0 || (int)t2 == -1) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
            p6 = (ts4_word)0;
        }
        p7 = (ts4_word)p6;
    } else {
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x88428FA8: if_get u32@0x20, ts4_tailcall_NetDll_send_884F0350, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off20_88428FA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    int t1;
    int t2;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 != -1) {
        t2 = ts4_tailcall_NetDll_send_884F0350((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
        p6 = (ts4_word)t2;
        if ((int)t2 <= 0 || (int)t2 == -1) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
            p6 = (ts4_word)0;
        }
        p7 = (ts4_word)p6;
    } else {
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x88429CE0: addr lbl_8803F520, lbl_8803F518, fn_884C5468 */
ts4_word ts4_addr_lbl_8803F520_88429CE0(ts4_word a0, ts4_word a1)
{
    return fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F518, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803F520);
}

/* Swing_DLL.xex 0x8842AF00: addr lbl_88040164, fn_8842AE60 */
ts4_word ts4_addr_lbl_88040164_8842AF00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8842AE60((ts4_word)a0, (ts4_word)(ts4_word)lbl_88040164, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040164, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8842AF20: addr lbl_88040180, lbl_88040170, fn_8842AE60 */
ts4_word ts4_addr_lbl_88040180_8842AF20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8842AE60((ts4_word)a0, (ts4_word)(ts4_word)lbl_88040170, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040180, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884314B0: if_call_seq lbl_8803D504, ts4_if_call_seq_u32_off4_88428890, lbl_88041534, ts4_if_call_seq_u32_off4_88428890, lbl_88041528, ts4_if_call_seq_u32_off4_88428890 */
ts4_word ts4_if_call_seq_lbl_8803D504_884314B0(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word p15;
    ts4_word p17;
    ts4_word loc58[2];
    ts4_word loc68[2];
    ts4_word loc60[2];
    ts4_word loc50[2];
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    unsigned char t7;
    ts4_word t8;
    unsigned char t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    (void)a0;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803D504);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041534);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041528);
    t4 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    p17 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc68[0]);
        t7 = *(unsigned char *)((char *)(ts4_word)(t6) + 0);
        p15 = (ts4_word)t6;
        if ((ts4_word)t7 != 0) {
            t8 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
            t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
            p13 = (ts4_word)t8;
            if ((ts4_word)t9 != 0) {
                t10 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)-15;
                t11 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)0;
                t12 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
                *(unsigned short *)((char *)(ts4_word)(t12) + 0) = (unsigned short)0;
                p13 = (ts4_word)t12;
            }
            p15 = (ts4_word)p13;
        }
        p17 = (ts4_word)p15;
    }
    return p17;
}

/* Swing_DLL.xex 0x88431AA0: call_seq lbl_880418B4, fn_88436C28, lbl_88057280, u32@lbl_88D26FCC, ts4_tailcall_fn_884CD990_884CE090, lbl_88B3D248 */
ts4_word ts4_call_seq_lbl_880418B4_88431AA0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_88436C28((ts4_word)a0, (ts4_word)(ts4_word)lbl_880418B4, (ts4_word)a1);
    t3 = ts4_tailcall_fn_884CD990_884CE090((ts4_word)(*(ts4_word *)lbl_88D26FCC), (ts4_word)(ts4_word)lbl_88057280);
    t4 = fn_884C6220((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88B3D248, (ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88431CA8: call_seq lbl_88041A9C, fn_88436C28, lbl_88058C60, u32@lbl_88D26FCC, ts4_tailcall_fn_884CD990_884CE090, lbl_88B3D268 */
ts4_word ts4_call_seq_lbl_88041A9C_88431CA8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_88436C28((ts4_word)a0, (ts4_word)(ts4_word)lbl_88041A9C, (ts4_word)a1);
    t3 = ts4_tailcall_fn_884CD990_884CE090((ts4_word)(*(ts4_word *)lbl_88D26FCC), (ts4_word)(ts4_word)lbl_88058C60);
    t4 = fn_884C6220((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88B3D268, (ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88433568: call_seq ts4_call_seq_u32_off4_88428B48, u32@0x0, ts4_call_seq_u32_off4_88428B48, u32@0x4, ts4_call_seq_u32_off4_88428B48, u32@0x0 */
ts4_word ts4_call_seq_fn_88428B48_88433568(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;

    t1 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0);
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], (ts4_word)a0);
    loc50[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1);
    loc58[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1);
    loc58[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 4));
    t9 = fn_884334B0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)a2);
    return t9;
}

/* Swing_DLL.xex 0x88433778: call_seq lbl_88042C8C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428980, ts4_index_u16_array_at_field0_884289F8, lbl_88042C7C */
ts4_word ts4_call_seq_lbl_88042C8C_88433778(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word loc60[2];
    ts4_word t3;
    ts4_word t4;
    unsigned short t5;
    ts4_word t7;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042C8C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042C8C);
    t3 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0]);
    t4 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t5 = *(unsigned short *)((char *)(ts4_word)(t4) + 0);
    *(unsigned short *)((char *)(ts4_word)(t3) + 2) = (unsigned short)t5;
    *(unsigned short *)((char *)(ts4_word)(t3) + 0) = (unsigned short)t5;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042C7C);
    t7 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc60[0]);
    *(unsigned char *)((char *)(ts4_word)(t7) + 1) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(t7) + 0) = (unsigned char)1;
    return t7;
}

/* Swing_DLL.xex 0x88433820: call_seq lbl_88042CB4, ts4_if_call_seq_u32_off4_88428890, lbl_88042CA4, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, u32@0x0 */
ts4_word ts4_call_seq_lbl_88042CB4_88433820(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042CB4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042CA4);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)-1;
    t4 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)-1;
    return t4;
}

/* Swing_DLL.xex 0x88433F90: call_seq ts4_call_seq_u32_off4_88428B48, u32@0x0, ts4_call_seq_u32_off4_88428B48, u32@0x4, ts4_call_seq_u32_off4_88428B48, u32@0x0 */
ts4_word ts4_call_seq_fn_88428B48_88433F90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;

    t1 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0);
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], (ts4_word)a0);
    loc50[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1);
    loc58[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1);
    loc58[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 4));
    t9 = ts4_call_seq_lbl_88042D94_88433ED8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)a2);
    return t9;
}

/* Swing_DLL.xex 0x88434160: call_seq lbl_880410F0, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_u32_off4_88428B48, u32@0x0, ts4_call_seq_u32_off4_88428B48 */
ts4_word ts4_call_seq_lbl_880410F0_88434160(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc70[2];
    ts4_word loc78[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880410F0);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880410F0);
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 4));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc58[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
    loc68[0] = (ts4_word)t8;
    t9 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)t8, (ts4_word)t7);
    loc68[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 4));
    t11 = fn_884340B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)a2);
    return t11;
}

/* Swing_DLL.xex 0x88434580: call_seq lbl_88043C18, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, lbl_88043C04, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890 */
ts4_word ts4_call_seq_lbl_88043C18_88434580(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word loc68[2];
    ts4_word loc60[2];
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88043C18);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88043C18);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88043C04);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88043C04);
    t5 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t6 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 0));
    *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 4));
    t9 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t10 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t10) + 0));
    *(ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t10) + 4));
    return t10;
}

/* Swing_DLL.xex 0x884348F8: addr lbl_88043E60, lbl_88041544, fn_884C5468 */
ts4_word ts4_addr_lbl_88043E60_884348F8(ts4_word a0, ts4_word a1)
{
    return fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_88041544, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88043E60);
}

/* Swing_DLL.xex 0x88435948: call_seq lbl_8803F5A0, ts4_if_call_seq_u32_off4_88428890, lbl_8803B324, ts4_if_call_seq_u32_off4_88428890, ts4_index_u64_array_at_field0_88428A88, ts4_index_u64_array_at_field0_88428A88 */
ts4_word ts4_call_seq_lbl_8803F5A0_88435948(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F5A0);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B324);
    t3 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    return t4;
}

/* Swing_DLL.xex 0x884359C8: call_seq lbl_8803F4C4, ts4_if_call_seq_u32_off4_88428890, lbl_8803BB8C, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, ts4_get_u32_off0_884289C8 */
ts4_word ts4_call_seq_lbl_8803F4C4_884359C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F4C4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803BB8C);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88435D98: call_seq lbl_8804903C, ts4_if_call_seq_u32_off4_88428890, lbl_8804901C, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_884289F8, ts4_index_u16_array_at_field0_884289F8 */
ts4_word ts4_call_seq_lbl_8804903C_88435D98(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804903C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8804901C);
    t3 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t4) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88436470: addr lbl_880493E4, lbl_88040180, fn_884C5468 */
ts4_word ts4_addr_lbl_880493E4_88436470(ts4_word a0, ts4_word a1)
{
    return fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_88040180, (ts4_word)a1, (ts4_word)(ts4_word)lbl_880493E4);
}

/* Swing_DLL.xex 0x88436488: call_seq lbl_88049700, ts4_if_call_seq_u32_off4_88428890, lbl_880496E4, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289B8, ts4_get_u32_off0_884289B8 */
ts4_word ts4_call_seq_lbl_88049700_88436488(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88049700);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880496E4);
    t3 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t4) + 0) = (*(float *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88437B80: call_seq fn_884430E8, lbl_880807C8 */
ts4_word ts4_call_seq_fn_884430E8_88437B80(void)
{
    ts4_word loc50[26];

    fn_884430E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    return (ts4_word)lbl_880807C8;
}

/* Swing_DLL.xex 0x884380A8: if_call_seq u32@0x18, u32@lbl_88CACF08, KeTlsGetValue, u32@0x10, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off18_884380A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)(t1 << 5), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}
