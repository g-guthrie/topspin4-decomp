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
ts4_word fn_88644A48();
ts4_word fn_88644AE0();
ts4_word fn_88644BD0();
ts4_word fn_886456A0();
ts4_word fn_88645A68();
ts4_word ts4_if_call_seq_u32_off2c_88646210();
ts4_word fn_88646388();
ts4_word fn_886465A0();
ts4_word fn_88646928();
ts4_word fn_886480B0();
ts4_word fn_88648998();
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

/* Swing_DLL.xex 0x88644848: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_88644848(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x88644860: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88644860(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        p5 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p5;
}

/* Swing_DLL.xex 0x886448C0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_886448C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886448D0: if_get u32@0x0, u32@0x0, u32@0x0, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_886448D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88644920: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88644920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88644980: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88644980(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886451B0: set u8@0x20 */
void ts4_set_u8_off20_886451B0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)g_ts4_script_constants);
    return;
}

/* Swing_DLL.xex 0x886451C8: get u32@0xa0 */
ts4_word ts4_get_u32_offa0_886451C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 160)) != 0);
}

/* Swing_DLL.xex 0x886454C0: call_seq u32@0x24, fn_884022C0, u32@0x28, fn_884022C0 */
ts4_word ts4_call_seq_u32_off24_886454C0(ts4_word a0)
{
    ts4_word t4;

    fn_884022C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    t4 = fn_884022C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
    return t4;
}

/* Swing_DLL.xex 0x88645628: if_call_seq u32@lbl_88D45B38, fn_88613268, u8@0x8, u32@0xb8, u32@0x0, u32@0xb8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88645628(ts4_word a0)
{
    ts4_word p3;
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t2) + 8) = (unsigned char)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)p3;
    *(ts4_word *)((char *)(ts4_word)(p3) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 184))) + 8) = (unsigned char)1;
    return t2;
}

/* Swing_DLL.xex 0x88645E18: call_seq u32@0x4, u32@0x0, u32@0x0, fn_88645A68, u32@0x4 */
ts4_word ts4_call_seq_u32_off4_88645E18(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    t4 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t4;
    return t4;
}

/* Swing_DLL.xex 0x88645E58: if_call_seq u32@0x4, u32@0x0, u32@0x0, fn_88645A68, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_88645E58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p25;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t12;
    ts4_word t16;
    ts4_word t17;
    ts4_word t20;
    ts4_word t24;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0);
    p25 = (ts4_word)t3;
    if ((int)t3 != 0) {
        t4 = fn_88645A68((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t4;
        t8 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0)), (ts4_word)(a1 + 8));
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t8;
        t12 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0)), (ts4_word)(a1 + 16));
        *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)t12;
        t16 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0)), (ts4_word)(a1 + 24));
        *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)t16;
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t20 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 0))) + 0)), (ts4_word)(a1 + 32), (ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)t20;
        t24 = fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))) + 0)), (ts4_word)(a1 + 40));
        *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)t24;
        p25 = (ts4_word)t24;
    }
    return p25;
}

/* Swing_DLL.xex 0x88646290: call_seq ts4_object_finalize, ts4_if_call_seq_u32_off2c_88646210, u32@0xc, u32@0x8 */
ts4_word ts4_call_seq_ts4_object_finalize_88646290(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 28));
    t2 = ts4_if_call_seq_u32_off2c_88646210((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x886462D8: if_call_seq u32@0xb8, ts4_tsu_cleanup_end, u32@0xb8 */
ts4_word ts4_if_call_seq_u32_offb8_886462D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_tsu_cleanup_end((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x88646918: get u32@0x24, u32@0x0, fn_88645A68 */
ts4_word ts4_get_u32_off24_88646918(ts4_word a0)
{
    return fn_88645A68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 0)));
}

/* Swing_DLL.xex 0x88646FC8: get u32@0x24, fn_88646928 */
ts4_word ts4_get_u32_off24_88646FC8(ts4_word a0)
{
    return fn_88646928((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
}

/* Swing_DLL.xex 0x88647200: if_addr lbl_880F7AEC, u32@lbl_88D45B38, fn_8860D250, u32@lbl_88C6CE84, fn_88618998, u32@0x4 */
ts4_word ts4_if_addr_lbl_880F7AEC_88647200(ts4_word a0)
{
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t13;
    ts4_word t15;

    loc50[0] = (ts4_word)(ts4_word)lbl_880F7AEC;
    t1 = *(ts4_word *)lbl_88D45B38;
    t2 = fn_8860D250((ts4_word)t1);
    loc50[1] = (ts4_word)t2;
    t4 = fn_88618998((ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88C6CE84));
    loc50[2] = (ts4_word)t4;
    t5 = loc50[0];
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 4))))((ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t8 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 0))))((ts4_word)t8, (ts4_word)1);
    }
    t13 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t13) + 8))))((ts4_word)(ts4_word)&loc50[0]);
    return t15;
}

/* Swing_DLL.xex 0x88647668: if_get u32@0x0, u32@0x0, u32@0x0, vcall, u32@0x0, u32@lbl_88CACF08 */
ts4_word ts4_if_get_u32_off0_88647668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t8;
    ts4_word t9;
    ts4_word t13;
    ts4_word t14;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t9 = fn_8841A510((ts4_word)t8, (ts4_word)48, (ts4_word)61);
    *(unsigned short *)((char *)(ts4_word)(t9) + 4) = (unsigned short)48;
    t13 = fn_884060F0((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 4))) + 0))) + (a3 << 2))));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t13;
    t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 52);
    *(float *)((char *)(ts4_word)(t13) + 32) = (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t14;
    return t13;
}

/* Swing_DLL.xex 0x88648590: if_call_seq fn_886465A0, fn_88644BD0, fn_88646388, fn_886480B0, fn_88644AE0, u8@0x55 */
ts4_word ts4_if_call_seq_fn_886465A0_88648590(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t6;
    ts4_word t9;

    fn_886465A0((ts4_word)a0, (ts4_word)(a0 + 112));
    fn_88644BD0((ts4_word)a0, (ts4_word)(a0 + 112));
    fn_88646388((ts4_word)a0, (ts4_word)(a0 + 112), (ts4_word)a2);
    fn_886480B0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    fn_88644AE0((ts4_word)a0);
    t6 = *(unsigned char *)((char *)(ts4_word)(a2) + 85);
    if ((ts4_word)t6 == 0) {
        fn_886456A0((ts4_word)a0, (ts4_word)a1);
    }
    t9 = fn_88644A48((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88648740: if_call_seq u32@0x28, fn_881B8360, u32@0x24, u32@0x28, fn_881B8360, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off28_88648740(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        fn_881B8360((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_881B8360((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x88649048: set u32@0x8, fn_88648998 */
ts4_word ts4_set_u32_off8_88649048(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return fn_88648998((ts4_word)a0);
}

/* Swing_DLL.xex 0x886496F0: call_seq u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_88649058, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_88890F50, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_886487A0 */
ts4_word ts4_call_seq_u32_lbl_88D45B20_886496F0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    loc50[0] = (ts4_word)((4067164160) | 44643);
    ts4_keyed_item_list_add_unique_if_mode_88649058((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t3 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((1680605184) | 34887);
    ts4_keyed_item_list_add_unique_if_mode_88890F50((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t5 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((3463774208) | 58863);
    t6 = ts4_keyed_item_list_add_unique_if_mode_886487A0((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88649BD8: call_seq fn_88649A90 */
ts4_word ts4_call_seq_fn_88649A90_88649BD8(ts4_word a0)
{
    fn_88649A90((ts4_word)a0, (ts4_word)(a0 + 112));
    return (a0 + 112);
}

/* Swing_DLL.xex 0x8864A0C8: if_call_seq u32@0x1c, ts4_destroy_owned_object, u32@0x10, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off1c_8864A0C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8864A110: set u32@0x0, u32@0x4, u32@0x10, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off0_8864A110(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864A8A8: if_call_seq u32@0x40, ts4_destroy_owned_object, u32@0x34, ts4_destroy_owned_object, u32@0x28, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off40_8864A8A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p15;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p15 = (ts4_word)t13;
    if ((ts4_word)t13 != 0) {
        t14 = ts4_destroy_owned_object((ts4_word)t13);
        p15 = (ts4_word)t14;
    }
    return p15;
}

/* Swing_DLL.xex 0x8864AFF0: set u32@0x0 */
void ts4_set_u32_off0_8864AFF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8864B088: call_seq u32@0x0, u32@0x0, fn_8857A1E0, ts4_msg_pool_service_get_8864DFF0, fn_888860A0, ts4_msg_pool_service_get_8864DFF0 */
ts4_word ts4_call_seq_u32_off0_8864B088(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
    ts4_msg_pool_service_get_8864DFF0((ts4_word)t3);
    t5 = fn_888860A0((ts4_word)t1);
    ts4_msg_pool_service_get_8864DFF0((ts4_word)t5);
    t7 = fn_888860A0((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8864B188: set u32@0x0 */
void ts4_set_u32_off0_8864B188(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8864B190: get u32@0x0, RtlLeaveCriticalSection */
ts4_word ts4_get_u32_off0_8864B190(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8864B198: get u32@0x0, RtlEnterCriticalSection */
ts4_word ts4_get_u32_off0_8864B198(ts4_word a0)
{
    return RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8864B460: tailcall fn_889BD910 */
ts4_word ts4_tailcall_fn_889BD910_8864B460(ts4_word a0)
{
    return fn_889BD910((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x8864BB40: if_call_seq u32@0x44, u32@0x0, RtlEnterCriticalSection, ts4_msg_pool_service_get_8864DFF0, fn_8899F760, fn_88151A70 */
ts4_word ts4_if_call_seq_u32_off44_8864BB40(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t3 = RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
    ts4_msg_pool_service_get_8864DFF0((ts4_word)t3);
    t5 = fn_8899F760((ts4_word)232);
    if ((ts4_word)t5 != 0) {
        t6 = fn_88151A70((ts4_word)t5);
        p7 = (ts4_word)t6;
    } else {
        p7 = (ts4_word)0;
    }
    loc50[0] = (ts4_word)p7;
    memcpy((ts4_word)p7, (ts4_word)a1, (ts4_word)232);
    fn_88278450((ts4_word)(a0 + 44), (ts4_word)(ts4_word)&loc50[0]);
    RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
    return 0;
}

/* Swing_DLL.xex 0x8864BC08: if_call_seq u32@0x0, u8@0x50, ts4_get_u32__imp_KeTimeStampBundle_8857B830, u32@0x4c, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8864BC08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 80) = (unsigned char)1;
        ts4_get_u32__imp_KeTimeStampBundle_8857B830();
        fn_8857C040((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 76))) + 0))) + 0)), (ts4_word)1, (ts4_word)(ts4_word)&loc50[0]);
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))) + 0)), (ts4_word)-1);
        t11 = fn_8864B528((ts4_word)a0);
        ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t11);
    }
    return 0;
}

/* Swing_DLL.xex 0x8864BF60: if_call_seq u32@0x44, u32@0x0, RtlEnterCriticalSection, u32@0x30, u32@0x8, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off44_8864BF60(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;

    if ((ts4_word)(a2 & 0xff) != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        RtlEnterCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 8);
        *(ts4_word *)((char *)(ts4_word)(t5) + 36) = (ts4_word)a1;
        fn_8864BAE8((ts4_word)a0, (ts4_word)t5);
        ts4_msg_list_pop_882784F0((ts4_word)(a0 + 44));
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
        *(unsigned char *)((char *)(ts4_word)(t8) + 13) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t8) + 14) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 36) = (ts4_word)0;
        t10 = RtlLeaveCriticalSection((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
        return t10;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 8);
    *(ts4_word *)((char *)(ts4_word)(t12) + 36) = (ts4_word)a1;
    fn_8864BAE8((ts4_word)a0, (ts4_word)t12);
    t14 = ts4_msg_list_pop_882784F0((ts4_word)(a0 + 44));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    *(unsigned char *)((char *)(ts4_word)(t15) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t15) + 14) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t15) + 36) = (ts4_word)0;
    return t14;
}

/* Swing_DLL.xex 0x8864D078: call_seq fn_8864CF98 */
ts4_word ts4_call_seq_fn_8864CF98_8864D078(void)
{
    fn_8864CF98();
    return 0;
}

/* Swing_DLL.xex 0x8864D180: set u32@0x8, u32@0x4, u8@0xd */
void ts4_set_u32_off8_8864D180(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8864D3B8: if_call_seq u32@0x28, u32@0x10, u32@0x20, u32@0x1c, u32@0x4, ts4_tailcall_NetDll_send_884F0350 */
ts4_word ts4_if_call_seq_u32_off28_8864D3B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t6 = ts4_tailcall_NetDll_send_884F0350((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)), (ts4_word)(t3 + t2), (ts4_word)(t4 - t2), (ts4_word)0);
    if ((int)t6 <= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)2;
        *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)1;
        return 0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t7 + t6);
    if ((int)(t7 + t6) == (int)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)4;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    return 1;
}

/* Swing_DLL.xex 0x8864D470: if_call_seq u32@0x28, u32@0x10, u32@0x20, u32@0x1c, u32@0x4, ts4_tailcall_NetDll_recv_884F0318 */
ts4_word ts4_if_call_seq_u32_off28_8864D470(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t6 = ts4_tailcall_NetDll_recv_884F0318((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)), (ts4_word)(t3 + t2), (ts4_word)(t4 - t2), (ts4_word)0);
    if ((int)t6 <= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)2;
        *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)1;
        return 0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t7 + t6);
    if ((int)(t7 + t6) == (int)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)1;
    }
    return 1;
}

/* Swing_DLL.xex 0x8864DEC8: get u32@0x4, ts4_tailcall_NetDll_connect_884F02B8 */
ts4_word ts4_get_u32_off4_8864DEC8(ts4_word a0, ts4_word a1)
{
    return ts4_tailcall_NetDll_connect_884F02B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)16);
}

/* Swing_DLL.xex 0x8864DED8: call_seq u32@0x4, ts4_tailcall_NetDll_ioctlsocket_884F0268 */
ts4_word ts4_call_seq_u32_off4_8864DED8(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)1;
    t2 = ts4_tailcall_NetDll_ioctlsocket_884F0268((ts4_word)t1, (ts4_word)((2147745792) | 26238), (ts4_word)(ts4_word)&loc50[0]);
    return (t2 == 0);
}

/* Swing_DLL.xex 0x8864DF30: call_seq u32@0x0, ts4_tailcall_NetDll_socket_884F0240, u32@0x4 */
ts4_word ts4_call_seq_u32_off0_8864DF30(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = ts4_tailcall_NetDll_socket_884F0240((ts4_word)2, (ts4_word)1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x8864DF78: addr lbl_88D429F0, u32@0x400, u32@0x404 */
void ts4_addr_lbl_88D429F0_8864DF78(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D429F0) + 1024) = (ts4_word)(ts4_word)lbl_88D429F0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D429F0) + 1028) = (ts4_word)1024;
    return;
}

/* Swing_DLL.xex 0x8864DFE8: fn  */
ts4_word ts4_fn_8864DFE8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8864E060: get  */
float ts4_get_8864E060(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E070: get  */
float ts4_get_8864E070(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E080: get  */
float ts4_get_8864E080(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E090: get  */
float ts4_get_8864E090(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E0A0: get  */
float ts4_get_8864E0A0(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E0B0: get  */
float ts4_get_8864E0B0(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x8864E4A0: set u32@0x8 */
void ts4_set_u32_off8_8864E4A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864EB60: set u32@0x1c, u32@0x24, u32@0x20 */
void ts4_set_u32_off1c_8864EB60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x8864EB80: set u32@0x8 */
void ts4_set_u32_off8_8864EB80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864EB90: set u32@0x8 */
void ts4_set_u32_off8_8864EB90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864EBA0: set u32@0x8 */
void ts4_set_u32_off8_8864EBA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864EC60: set u32@0x8 */
void ts4_set_u32_off8_8864EC60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864EC88: addr lbl_880F5848, u32@0x4, u32@0x0, u32@0xc, u32@0x8 */
void ts4_addr_lbl_880F5848_8864EC88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F310: set u32@0x8, u32@0x14 */
void ts4_set_u32_off8_8864F310(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F320: set u32@0x8 */
void ts4_set_u32_off8_8864F320(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F350: addr lbl_880F5860, u32@0x4, u32@0x0, u32@0x8, u32@0x10, u32@0xc */
void ts4_addr_lbl_880F5860_8864F350(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5860;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F6B8: addr lbl_880F5890, u32@0x4, u32@0x0, u32@0xc, u32@0x8, u32@0x10 */
void ts4_addr_lbl_880F5890_8864F6B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5890;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8864F778: call_seq fn_8825D450, fn_8864E310 */
ts4_word ts4_call_seq_fn_8825D450_8864F778(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_8825D450((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_8864E310((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x886521D0: if_call_seq lbl_880F5878, u32@0x0, ts4_object_finalize, ts4_object_finalize, u32@0x20, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F5878_886521D0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5878;
    ts4_object_finalize((ts4_word)(a0 + 20));
    ts4_object_finalize((ts4_word)(a0 + 32));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 20)) + 0);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t9 = fn_8860BBD8((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88652260: call_seq lbl_880F5878, u32@0x4, u32@0x0, u32@0x8, u32@0x10, u32@0xc */
ts4_word ts4_call_seq_lbl_880F5878_88652260(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5878;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_88176CD0((ts4_word)(a0 + 20), (ts4_word)3);
    fn_88176CD0((ts4_word)(a0 + 32), (ts4_word)3);
    return a0;
}

/* Swing_DLL.xex 0x88655168: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_88655168(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88655190: fn  */
ts4_word ts4_fn_88655190(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88655198: fn  */
ts4_word ts4_fn_88655198(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886551A0: fn  */
ts4_word ts4_fn_886551A0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886551A8: fn  */
ts4_word ts4_fn_886551A8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886551B8: fn  */
ts4_word ts4_fn_886551B8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88655398: set u32@0xc, u32@0x10 */
void ts4_set_u32_offc_88655398(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886554D0: if_get u32@0x10, u32@0xc, u32@0x4 */
ts4_word ts4_if_get_u32_off10_886554D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 < (ts4_word)t1) {
        return ((t1 - t2) + -1);
    }
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) - t2) + t1);
}

/* Swing_DLL.xex 0x88655500: get u32@0x1c, u32@0x30 */
ts4_word ts4_get_u32_off1c_88655500(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88655518: if_get u32@0x1c, u32@0x30, vcall, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_if_get_u32_off1c_88655518(ts4_word a0)
{
    ts4_word p7;
    ts4_word t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28));
    p7 = (ts4_word)t3;
    if ((ts4_word)(t3 & 0xff) != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88655578: get u32@0x1c, u32@0x14, vcall, u64@0x70 */
ts4_word ts4_get_u32_off1c_88655578(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    return t3;
}

/* Swing_DLL.xex 0x886555C0: if_call_seq u32@0xc, u32@0x8, u32@0x4, memcpy, u32@0xc, u32@0xc */
ts4_word ts4_if_call_seq_u32_offc_886555C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)(t1 + a2) <= (ts4_word)t2) {
        memcpy((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + t1), (ts4_word)a1, (ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a2 + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    }
    return 1;
}

/* Swing_DLL.xex 0x886557D0: call_seq fn_88655718 */
ts4_word ts4_call_seq_fn_88655718_886557D0(ts4_word a0, ts4_word a1)
{
    fn_88655718((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88655AC0: get u32@lbl_88D45B1C, u32@0x270 */
ts4_word ts4_get_u32_lbl_88D45B1C_88655AC0(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 624));
}

/* Swing_DLL.xex 0x88655BB0: get u32@0x8, u32@0xc, u32@0x10 */
void ts4_get_u32_off8_88655BB0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88657A68: if_call_seq u32@0x8, fn_88655BC8, u32@0x8, fn_88655BC8, ts4_tsu_cleanup_end, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88657A68(ts4_word a0)
{
    ts4_word t3;
    ts4_word t8;

    fn_88655BC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        fn_88655BC8((ts4_word)t3);
        ts4_tsu_cleanup_end((ts4_word)t3);
    }
    t8 = fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t8;
}

/* Swing_DLL.xex 0x886580B8: call_seq lbl_880F4FD0, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88657EB8, lbl_880F4FDC, fn_88608590 */
ts4_word ts4_call_seq_lbl_880F4FD0_886580B8(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F4FD0);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88657EB8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F4FDC);
    loc50[0] = (ts4_word)t4;
    t6 = ts4_keyed_item_list_add_unique_88657AE0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t6;
}

/* Swing_DLL.xex 0x88658910: call_seq fn_88617D88, lbl_880F51E0, u32@0x0, fn_8892AFF0, u64@0x70, u32@0x78 */
ts4_word ts4_call_seq_fn_88617D88_88658910(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F51E0;
    fn_8892AFF0((ts4_word)(a0 + 28));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(ts4_word *)lbl_88D45B0C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88658D60: if_call_seq u32@0x28, u32@lbl_88D45B38, fn_88613268, u32@0x24, u32@0x2c, fn_88658B90 */
ts4_word ts4_if_call_seq_u32_off28_88658D60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a2;
        t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)a2, (ts4_word)1, (ts4_word)0, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t5 = fn_88658B90((ts4_word)a0, (ts4_word)0);
    return t5;
}

/* Swing_DLL.xex 0x88659518: fn  */
ts4_word ts4_fn_88659518(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886597C0: if_fn  */
ts4_word ts4_if_fn_886597C0(ts4_word a0)
{
    if ((int)a0 == (int)((830210048) | 20919)) {
        return ((2733441024) | 41447);
    }
    return ((830210048) | 20919);
}

/* Swing_DLL.xex 0x886599F0: set u32@0x4 */
void ts4_set_u32_off4_886599F0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886599F8: addr lbl_880F45D0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F45D0_886599F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F45D0;
    return;
}

/* Swing_DLL.xex 0x88659A10: get u32@0x8 */
ts4_word ts4_get_u32_off8_88659A10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88659A18: addr lbl_880D6B70, u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D6B70_88659A18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659A38: set u32@0x4 */
void ts4_set_u32_off4_88659A38(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88659A40: addr lbl_880F46B8, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F46B8_88659A40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F46B8;
    return;
}

/* Swing_DLL.xex 0x88659A58: get u32@0x4, u32@0x50 */
ts4_word ts4_get_u32_off4_88659A58(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80));
}

/* Swing_DLL.xex 0x88659A68: set u32@0x4 */
void ts4_set_u32_off4_88659A68(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88659A80: set u32@0x8 */
void ts4_set_u32_off8_88659A80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659A90: set u32@0x8 */
void ts4_set_u32_off8_88659A90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659B10: set u32@0x8 */
void ts4_set_u32_off8_88659B10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659B20: get u32@0x38, u32@0x20 */
ts4_word ts4_get_u32_off38_88659B20(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 32));
}

/* Swing_DLL.xex 0x88659B30: get u32@0x38, u32@0x20 */
void ts4_get_u32_off38_88659B30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88659B70: get u32@0x28, u32@0x8 */
void ts4_get_u32_off28_88659B70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88659B80: get u32@0x28, u32@0x8 */
ts4_word ts4_get_u32_off28_88659B80(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 8));
}

/* Swing_DLL.xex 0x88659B90: get u32@0x28, u32@0x0 */
void ts4_get_u32_off28_88659B90(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88659BA0: get u32@0x28, u32@0x0 */
ts4_word ts4_get_u32_off28_88659BA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 0));
}

/* Swing_DLL.xex 0x88659C24: set u8@0x2, u32@0x20, u8@0x3, u32@0x20, u8@0x4 */
void ts4_set_u8_off2_88659C24(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(unsigned char *)((char *)(ts4_word)(a7) + 2) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 3) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 4) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88659C48: if_get u32@0x20, u8@0x4, u32@0x28, u32@0x8, u8@0x3, u32@0x28 */
void ts4_if_get_u32_off20_88659C48(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t4;
    unsigned char t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 8) = (ts4_word)3;
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + 3);
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 8) = (ts4_word)2;
        return;
    }
    t6 = *(unsigned char *)((char *)(ts4_word)(t1) + 2);
    if ((ts4_word)t6 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 8) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x88659CA0: set u32@0x20, u32@0x24 */
void ts4_set_u32_off20_88659CA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659D00: set u8@0x73f */
void ts4_set_u8_off73f_88659D00(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1855) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88659D38: addr lbl_880F4508, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F4508_88659D38(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4508;
    return;
}

/* Swing_DLL.xex 0x88659D50: get u32@0x8, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off8_88659D50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88659D68: if_get u32@0x8, u32@0x0, u32@0x8, vcall, u32@0x8, u32@0x4 */
ts4_word ts4_if_get_u32_off8_88659D68(ts4_word a0)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p9 = (ts4_word)t5;
    if ((ts4_word)t5 != 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x88659DE8: addr lbl_880F4518, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F4518_88659DE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4518;
    return;
}

/* Swing_DLL.xex 0x88659E00: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659E00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E10: addr lbl_880F48B8, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F48B8_88659E10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F48B8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E30: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659E30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E40: addr lbl_880F4900, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4900_88659E40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4900;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E60: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659E60(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E70: addr lbl_880F4990, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4990_88659E70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4990;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659E90: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659E90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659EA0: addr lbl_880F4A20, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4A20_88659EA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4A20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659EC0: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659EC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659ED0: addr lbl_880F49D8, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F49D8_88659ED0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F49D8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88659EF0: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_88659EF0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A050: addr lbl_880D6B70, u32@0xc, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880D6B70_8865A050(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A090: get u32@0x14, u32@0x5c */
ts4_word ts4_get_u32_off14_8865A090(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 92));
}

/* Swing_DLL.xex 0x8865A0C8: set u32@0xc, u32@0x4 */
void ts4_set_u32_offc_8865A0C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A0D8: addr lbl_880F4804, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880F4804_8865A0D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4804;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A100: addr lbl_880F4804, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_880F4804_8865A100(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4804;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A180: set u32@0x0 */
void ts4_set_u32_off0_8865A180(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8865A1D8: get u32@0x1c, u32@0x8 */
ts4_word ts4_get_u32_off1c_8865A1D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8));
}

/* Swing_DLL.xex 0x8865A1E8: set u32@0x8 */
void ts4_set_u32_off8_8865A1E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A208: addr lbl_880F436C, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F436C_8865A208(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F436C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A2C8: get u32@0x1c */
ts4_word ts4_get_u32_off1c_8865A2C8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x8865A2D0: get u32@0x1c */
ts4_word ts4_get_u32_off1c_8865A2D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x8865A328: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8865A328(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8865A448: get u32@0x4, u32@0x80, u32@0x7c */
ts4_word ts4_get_u32_off4_8865A448(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 128);
    return ((int)(t2 - (*(ts4_word *)((char *)(ts4_word)(t1) + 124))) >> 3);
}

/* Swing_DLL.xex 0x8865A5D0: fn  */
ts4_word ts4_fn_8865A5D0(ts4_word a0, ts4_word a1)
{
    return (((a1 + 3) << 4) + a0);
}

/* Swing_DLL.xex 0x8865A640: set u32@0x30 */
void ts4_set_u32_off30_8865A640(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A650: set u32@0x30 */
void ts4_set_u32_off30_8865A650(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8865A678: set u32@0x8 */
void ts4_set_u32_off8_8865A678(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A708: set u32@0x8 */
void ts4_set_u32_off8_8865A708(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865A7C0: get u32@0x18, u32@0x8 */
ts4_word ts4_get_u32_off18_8865A7C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 8));
}

/* Swing_DLL.xex 0x8865A7D0: get u32@0x1c */
ts4_word ts4_get_u32_off1c_8865A7D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x8865A878: addr lbl_880F4640, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F4640_8865A878(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4640;
    return;
}

/* Swing_DLL.xex 0x8865A9B8: get u32@0x18, fn_8865A938 */
ts4_word ts4_get_u32_off18_8865A9B8(ts4_word a0, ts4_word a1)
{
    return fn_8865A938((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x8865AA78: call_seq u32@0x18, fn_8865A9C8, u32@0x4 */
ts4_word ts4_call_seq_u32_off18_8865AA78(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    loc50[0] = (ts4_word)0;
    t2 = fn_8865A9C8((ts4_word)a0, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    return t2;
}

/* Swing_DLL.xex 0x8865AAC0: if_get u32@0xc, u32@0x10, u32@0x0, u32@0xc, vcall, u32@0xc */
ts4_word ts4_if_get_u32_offc_8865AAC0(ts4_word a0)
{
    ts4_word p14;
    ts4_word t1;
    ts4_word t5;
    ts4_word t10;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    p14 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 0))))((ts4_word)t10, (ts4_word)1);
        p14 = (ts4_word)t13;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p14;
}

/* Swing_DLL.xex 0x8865AB98: get u32@0x4, u32@0x74, u8@0x4d9 */
ts4_word ts4_get_u32_off4_8865AB98(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 116))) + 1241));
}

/* Swing_DLL.xex 0x8865ABE8: addr lbl_880F4E54, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4E54_8865ABE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E54;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865ACF8: addr lbl_880F4E40, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4E40_8865ACF8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E40;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865AD30: addr lbl_880F4E04, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F4E04_8865AD30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E04;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865AD50: if_get u32@0x38, u8@0x38, u32@0x1c, u32@0x80, u8@0xd2, u32@0x38 */
void ts4_if_get_u32_off38_8865AD50(ts4_word a0)
{
    unsigned char t2;
    ts4_word t7;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 56);
    if ((ts4_word)t2 != 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 128))) + 210) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 56) = (unsigned char)1;
    t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 52) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 72))) + 48))) + 784));
    return;
}

/* Swing_DLL.xex 0x8865ADA0: get u32@0x1c, u32@0x74, u8@0x5d8, u32@0x1c, u32@0x74, u8@0x4b5 */
void ts4_get_u32_off1c_8865ADA0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116))) + 1496) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116))) + 1205) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116))) + 1152) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8865B0D8: if_fn  */
ts4_word ts4_if_fn_8865B0D8(ts4_word a0)
{
    if ((ts4_word)a0 == (ts4_word)((1103298560) | 10954)) {
        return -256;
    }
    if ((ts4_word)a0 == (ts4_word)((2696740864) | 58926)) {
        return ((4278190080) | 32768);
    }
    return (4294901760);
}

/* Swing_DLL.xex 0x8865B530: get u32@0xc, u32@0xb0, u32@0x54 */
ts4_word ts4_get_u32_offc_8865B530(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    return (((*(ts4_word *)((char *)(ts4_word)(t1) + 84)) - t2) == 0);
}

/* Swing_DLL.xex 0x8865B5C8: get u32@0xc, u32@0xf0, u32@0x34 */
ts4_word ts4_get_u32_offc_8865B5C8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 240);
    return (((*(ts4_word *)((char *)(ts4_word)(t1) + 52)) - t2) == 0);
}

/* Swing_DLL.xex 0x8865B628: get u32@0x44 */
ts4_word ts4_get_u32_off44_8865B628(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 68)) == 0);
}

/* Swing_DLL.xex 0x8865B740: get u32@0x44, u32@0x14, u32@0x50, u32@0x10, u32@0x38, u32@0x18 */
void ts4_get_u32_off44_8865B740(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 832);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 28))) + 108)) + 3124);
    return;
}

/* Swing_DLL.xex 0x8865BD58: if_get u8@0x74b, u32@0x2c, u32@0xc0, u32@0x2c, u32@0xc4, u32@0x2c */
void ts4_if_get_u8_off74b_8865BD58(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1867);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 192) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 200) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1864) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1872) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1876) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865C0B8: set u8@0x37c */
void ts4_set_u8_off37c_8865C0B8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 892) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8865C148: set u32@0x30, u32@0x34, u8@0x37c, u32@0x2c, u32@0x28, u32@0x24 */
void ts4_set_u32_off30_8865C148(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 892) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865C260: if_get u32@0x4, u32@0x30, u8@0x328, u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_if_get_u32_off4_8865C260(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    unsigned char t3;
    ts4_word t4;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t3 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 48))) + 808);
    if ((ts4_word)t3 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4);
    }
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 68))) + 105) = (unsigned char)1;
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x8865C3C0: set u32@0x4, u32@0x44, u32@0x8 */
void ts4_set_u32_off4_8865C3C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 144);
    return;
}

/* Swing_DLL.xex 0x8865C558: get u32@0x0, u32@0x4, u32@0x20, u32@0x48 */
ts4_word ts4_get_u32_off0_8865C558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t3))((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 72)), (ts4_word)a2);
}

/* Swing_DLL.xex 0x8865CBC0: set u32@0x4, u32@0x44, u32@0x8 */
void ts4_set_u32_off4_8865CBC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 144);
    return;
}

/* Swing_DLL.xex 0x8865CF70: set u32@0x4, u32@0x44, u32@0x8 */
void ts4_set_u32_off4_8865CF70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 144);
    return;
}

/* Swing_DLL.xex 0x8865D3A8: set u32@0x4, u32@0x44, u32@0x8 */
void ts4_set_u32_off4_8865D3A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 144);
    return;
}

/* Swing_DLL.xex 0x8865D688: set u32@0x4, u32@0x44, u32@0x8 */
void ts4_set_u32_off4_8865D688(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68)) + 144);
    return;
}

/* Swing_DLL.xex 0x8865D790: if_call_seq u32@0x118, u32@0x2c, fn_8865D6E8, fn_8865D6E8 */
ts4_word ts4_if_call_seq_u32_off118_8865D790(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t3 = fn_8865D6E8((ts4_word)(t2 + 96), (ts4_word)(t1 + 52));
    t4 = fn_8865D6E8((ts4_word)t2, (ts4_word)t1);
    p5 = (ts4_word)t4;
    if ((int)t3 >= (int)t4) {
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x886690A0: set u8@0x8 */
void ts4_set_u8_off8_886690A0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8866A038: get u32@0x4, u32@0x30, u8@0x93, u32@0x4, u8@0x20, u32@0x4c */
void ts4_get_u32_off4_8866A038(ts4_word a0)
{
    ts4_word t3;

    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 48))) + 147) = (unsigned char)1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 76))) + 30) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8866A188: call_seq fn_88669C30, u32@0x18, u32@0x1c, u8@0x20 */
ts4_word ts4_call_seq_fn_88669C30_8866A188(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88669C30((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x8866A5E0: set u32@0x4, u32@0x44, u32@0x18, u32@0x1c, u8@0x20, u32@0x8 */
void ts4_set_u32_off4_8866A5E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t1 + 144);
    return;
}

/* Swing_DLL.xex 0x8866B598: addr lbl_880F4948, u32@0x4, u32@0x0, u32@0x8, u8@0x10 */
void ts4_addr_lbl_880F4948_8866B598(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4948;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8866BC20: if_get u32@0x24, u32@0x10 */
ts4_word ts4_if_get_u32_off24_8866BC20(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 16);
    if ((ts4_word)t2 != 17) {
        if ((ts4_word)t2 != 18) {
            return 0;
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x8866BED0: get u32@0x154, u32@0x74, fn_8866BDD8 */
ts4_word ts4_get_u32_off154_8866BED0(ts4_word a0)
{
    return fn_8866BDD8((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 116)) + 2272));
}

/* Swing_DLL.xex 0x8866BFB0: get u32@0x154, u32@0x28, u32@0x74, u32@0xc, u8@0xbd1 */
ts4_word ts4_get_u32_off154_8866BFB0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 340);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 40);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 116);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    return ((((((3663003648) | 18518) - t4) == 0) - (*(unsigned char *)((char *)(ts4_word)(t3) + 3025))) != 0);
}

/* Swing_DLL.xex 0x8866C878: call_seq fn_8890DDA8, fn_8890DDA8, fn_8890DDA8 */
ts4_word ts4_call_seq_fn_8890DDA8_8866C878(ts4_word a0)
{
    ts4_word t3;

    fn_8890DDA8((ts4_word)(a0 + 148));
    fn_8890DDA8((ts4_word)(a0 + 80));
    t3 = fn_8890DDA8((ts4_word)(a0 + 12));
    return t3;
}

/* Swing_DLL.xex 0x8866D330: call_seq fn_8826B328, u32@0x4 */
ts4_word ts4_call_seq_fn_8826B328_8866D330(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8826B328((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8866D8E0: call_seq fn_8890DDA8, fn_8890DDA8, u32@0xc, u32@0x10, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_fn_8890DDA8_8866D8E0(ts4_word a0)
{
    ts4_word t2;

    fn_8890DDA8((ts4_word)(a0 + 20));
    t2 = fn_8890DDA8((ts4_word)(a0 + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x8866DEF0: get u32@0x74, u32@0x90, u32@0x74, u32@0x98, u32@0x74, u32@0xa0 */
void ts4_get_u32_off74_8866DEF0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + 144) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + 152) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + 160) = (ts4_word)((2147418112) | 65535);
    return;
}

/* Swing_DLL.xex 0x8866E2E8: call_seq fn_8866E250 */
ts4_word ts4_call_seq_fn_8866E250_8866E2E8(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    t1 = fn_8866E250((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x8866E3E8: get u32@0x44, u32@0x10, u32@0x54, u32@0x24, u32@0x10, u32@0xb8 */
ts4_word ts4_get_u32_off44_8866E3E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t4 = *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 84)) << 2)) + t2);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 36);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 16);
    return (*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t5) + 184)) << 2)) + t6));
}

/* Swing_DLL.xex 0x8866E418: get u32@0x44, u32@0x10, u32@0x54, u32@0x4, u32@0x24, u32@0x10 */
ts4_word ts4_get_u32_off44_8866E418(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t4 = *(ts4_word *)((char *)(ts4_word)((t2 - ((*(ts4_word *)((char *)(ts4_word)(t1) + 84)) << 2))) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 36);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 16);
    return (*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t5) + 184)) << 2)) + t6));
}

/* Swing_DLL.xex 0x8866F710: addr lbl_880F43E0, u32@0x18, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
void ts4_addr_lbl_880F43E0_8866F710(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F43E0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8866FD48: get u32@0x4, u32@0x0, u32@0x88, u32@0x5a0 */
ts4_word ts4_get_u32_off4_8866FD48(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 136))) + 1440)) + ((t2 + (t2 << 1)) << 4));
}

/* Swing_DLL.xex 0x8866FD70: get u32@0x4, u32@0x0, u32@0x88, u32@0x5a0 */
ts4_word ts4_get_u32_off4_8866FD70(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 136))) + 1440)) + ((t2 + (t2 << 1)) << 4));
}

/* Swing_DLL.xex 0x8866FD98: call_seq fn_8890DDA8, u32@0x4 */
ts4_word ts4_call_seq_fn_8890DDA8_8866FD98(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8890DDA8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886702C0: if_get u32@0x1c, u32@lbl_88D45B1C, u32@0x28, u32@0x27c, u8@0x0 */
void ts4_if_get_u32_off1c_886702C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)lbl_88D45B1C;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 40);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 636);
    if ((ts4_word)t3 == (ts4_word)t4) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)((t3 - a1) != 0);
    return;
}

/* Swing_DLL.xex 0x88670508: addr lbl_880F482C, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F482C_88670508(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F482C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88671550: call_seq u32@0x10, fn_8866DD78, ts4_object_finalize, ts4_object_finalize */
ts4_word ts4_call_seq_u32_off10_88671550(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)((1191575552) | 245);
    fn_8866DD78((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    ts4_object_finalize((ts4_word)(a0 + 60));
    t4 = ts4_object_finalize((ts4_word)(a0 + 48));
    return t4;
}

/* Swing_DLL.xex 0x886726F0: get u32@0x1c, u32@0x5c, u32@0x14, u8@0x70, u32@0x5c, u8@0x71 */
void ts4_get_u32_off1c_886726F0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 92);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 20);
    *(unsigned char *)((char *)(ts4_word)(t2) + 112) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 92) = (ts4_word)((2656108544) | 9259);
    *(unsigned char *)((char *)(ts4_word)(t2) + 113) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116))) + 3264) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88672728: get u32@0x1c, u32@0x5c, u32@0x14, u8@0x70, u32@0x5c, u8@0x71 */
void ts4_get_u32_off1c_88672728(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 92);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 20);
    *(unsigned char *)((char *)(ts4_word)(t2) + 112) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 92) = (ts4_word)((2656108544) | 9259);
    *(unsigned char *)((char *)(ts4_word)(t2) + 113) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88676950: get u32@0x4, u32@0x4c, fn_88674ED0 */
ts4_word ts4_get_u32_off4_88676950(ts4_word a0)
{
    return fn_88674ED0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 76)));
}

/* Swing_DLL.xex 0x88679FC8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88679FC8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867A068: call_seq fn_8890DDA8, fn_8890DDA8, fn_8890DDA8, fn_8890DDA8, fn_8890E088, u32@0x24 */
ts4_word ts4_call_seq_fn_8890DDA8_8867A068(ts4_word a0)
{
    ts4_word t6;

    fn_8890DDA8((ts4_word)(a0 + 256));
    fn_8890DDA8((ts4_word)(a0 + 188));
    fn_8890DDA8((ts4_word)(a0 + 120));
    fn_8890DDA8((ts4_word)(a0 + 52));
    fn_8890E088((ts4_word)(a0 + 324));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t6 = ts4_object_finalize((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t6;
}
