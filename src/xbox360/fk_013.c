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

extern char fn_884EDC20[];
extern char fn_884EEF90[];
extern char fn_884EF3A0[];
extern char fn_884F4408[];
extern char fn_88521A98[];
extern char fn_88521B08[];
extern char fn_88521B30[];
extern char fn_88521B50[];
extern char fn_88521B90[];
extern char fn_88521BC0[];
extern char fn_88521BD8[];
extern char fn_88521BF0[];
extern char fn_88521C08[];
extern char fn_88521C80[];
extern char fn_88521CB8[];
extern char fn_8852DA00[];
extern char fn_8852DB78[];
extern char lbl_88001A20[];
extern char lbl_8803A308[];
extern char lbl_88088A4C[];
extern char lbl_8808C36C[];
extern char lbl_8808C434[];
extern char lbl_8808C570[];
extern char lbl_8808C6DC[];
extern char lbl_8808C82C[];
extern char lbl_8808CEFC[];
extern char lbl_8808CF00[];
extern char lbl_8808CF4C[];
extern char lbl_8808D3F4[];
extern char lbl_8808D4C4[];
extern char lbl_8808D514[];
extern char lbl_8808D560[];
extern char lbl_8808D57C[];
extern char lbl_8808DF6C[];
extern char lbl_8808DFE8[];
extern char lbl_8808E0A0[];
extern char lbl_8808E0B0[];
extern char lbl_8808E150[];
extern char lbl_880DCF0C[];
extern char lbl_88C2625C[];
extern char lbl_88C264D8[];
extern char lbl_88C2681C[];
extern char lbl_88C26908[];
extern char lbl_88C2D57C[];
extern char lbl_88C2D5EC[];
extern char lbl_88CACF08[];
extern char lbl_88D26FD0[];
extern char lbl_88D26FD8[];
extern char lbl_88D26FDC[];
extern char lbl_88D26FE0[];
extern char lbl_88D26FE4[];
extern char lbl_88D275C0[];
extern char lbl_88D2E294[];
ts4_word KeTlsGetValue();
ts4_word NetDll_WSACleanup();
ts4_word NetDll_WSAGetLastError();
ts4_word NetDll_XNetCleanup();
ts4_word NetDll_XNetDnsLookup();
ts4_word NetDll_XNetDnsRelease();
ts4_word NetDll_XNetGetEthernetLinkStatus();
ts4_word NetDll_XNetInAddrToString();
ts4_word NetDll_XNetInAddrToXnAddr();
ts4_word NetDll_XNetQosListen();
ts4_word NetDll_XNetServerToInAddr();
ts4_word NetDll_XNetUnregisterKey();
ts4_word NetDll_XNetXnAddrToInAddr();
ts4_word NetDll___WSAFDIsSet();
ts4_word NetDll_accept();
ts4_word NetDll_bind();
ts4_word NetDll_closesocket();
ts4_word NetDll_connect();
ts4_word NetDll_inet_addr();
ts4_word NetDll_ioctlsocket();
ts4_word NetDll_listen();
ts4_word NetDll_recv();
ts4_word NetDll_recvfrom();
ts4_word NetDll_select();
ts4_word NetDll_send();
ts4_word NetDll_sendto();
ts4_word NetDll_setsockopt();
ts4_word NetDll_socket();
ts4_word RtlLeaveCriticalSection();
ts4_word XamUserGetXUID();
ts4_word XamUserWriteProfileSettings();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841A820();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word fn_8841EF38();
ts4_word fn_884210E8();
ts4_word fn_884214A8();
ts4_word fn_88423660();
ts4_word fn_88423730();
ts4_word fn_88423788();
ts4_word fn_88423CE0();
ts4_word fn_88423D60();
ts4_word ts4_get_u16_offe_88426148();
ts4_word fn_88426FA0();
ts4_word ts4_ref_holder_dtor_88427338();
ts4_word fn_88427418();
ts4_word ts4_tailcall_fn_88426FF8_884276E8();
ts4_word ts4_set_u16_off2_88468338();
ts4_word fn_88472530();
ts4_word fn_88472858();
ts4_word ts4_addr_lbl_8808BFAC_884C5458();
ts4_word fn_884CEEC0();
ts4_word fn_884D17A0();
ts4_word ts4_ref_holder_dtor_nullable_member_884D4008();
ts4_word fn_884D4138();
ts4_word fn_884D44A8();
ts4_word fn_884D58B0();
ts4_word fn_884D63A0();
ts4_word fn_884D75B0();
ts4_word fn_884D7C98();
ts4_word fn_884D8100();
ts4_word fn_884D8240();
ts4_word fn_884D9180();
ts4_word ts4_ref_holder_dtor_owner_884DA7B0();
ts4_word fn_884DB350();
ts4_word fn_884DB7D8();
ts4_word fn_884DCC60();
ts4_word ts4_ref_holder_dtor_884DCDD8();
ts4_word fn_884DCFA8();
ts4_word fn_884DD040();
ts4_word fn_884E1430();
ts4_word fn_884E16F8();
ts4_word fn_884E1760();
ts4_word fn_884E17F8();
ts4_word fn_884E18D0();
ts4_word fn_884E19D8();
ts4_word fn_884E1AE8();
ts4_word ts4_pooled_deleting_dtor_884E2060();
ts4_word fn_884E7310();
ts4_word fn_884E7418();
ts4_word fn_884EB998();
ts4_word ts4_if_call_seq_fn_884EB998_884EBBC0();
ts4_word ts4_if_call_seq_u32_off10_884ECE70();
ts4_word fn_884EDB18();
ts4_word ts4_call_seq_fn_884EDC20_884EDC80();
ts4_word ts4_if_call_seq_fn_884EDB18_884EE568();
ts4_word fn_884EE5D0();
ts4_word ts4_call_seq_fn_884EEF90_884EEFF0();
ts4_word ts4_if_call_seq_fn_884EE5D0_884EF048();
ts4_word fn_884EF320();
ts4_word ts4_call_seq_fn_884EF3A0_884EF3F0();
ts4_word ts4_if_call_seq_fn_884EF320_884EF450();
ts4_word fn_884EFDD0();
ts4_word fn_884F0178();
ts4_word fn_884F1978();
ts4_word fn_884F3040();
ts4_word fn_884F3090();
ts4_word fn_884F3458();
ts4_word fn_884F4698();
ts4_word ts4_call_seq_fn_884FD970_884F90D8();
ts4_word ts4_call_seq_fn_884FD970_884F9108();
ts4_word fn_884FD878();
ts4_word fn_884FD910();
ts4_word fn_884FD970();
ts4_word fn_885127C0();
ts4_word fn_88520B88();
ts4_word fn_88520CE8();
ts4_word fn_88520DD8();
ts4_word fn_88523FC0();
ts4_word fn_8852CD50();
ts4_word fn_8852D668();
ts4_word ts4_addr_fn_8852DA00_8852DB68();
ts4_word fn_8852E0C0();
ts4_word fn_88531FF8();
ts4_word fn_88538098();
ts4_word fn_885637C0();
ts4_word fn_88579FC0();
ts4_word fn_885E76C0();
ts4_word fn_885E7AD8();
ts4_word fn_885E7BA8();
ts4_word fn_885EC530();
ts4_word ts4_ref_holder_dtor_nullable_885EC7D8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x884CE9B8: set u32@0xc, u32@0x10, lbl_8808C36C, u32@0x8, u16@0x6, u32@0x0 */
void ts4_set_u32_offc_884CE9B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C36C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x884CEB30: get u32@lbl_88C2625C, u32@0x0 */
void ts4_get_u32_lbl_88C2625C_884CEB30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)lbl_88C2625C);
    return;
}

/* Swing_DLL.xex 0x884CEB40: get u8@0x0, u8@0x0, u8@0x1, u8@0x1, u8@0x2, u8@0x2 */
void ts4_get_u8_off0_884CEB40(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    *(unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 1));
    *(unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 2));
    *(unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 3));
    return;
}

/* Swing_DLL.xex 0x884CF190: if_call_seq fn_88423730, u32@0x8, fn_884CEEC0 */
ts4_word ts4_if_call_seq_fn_88423730_884CF190(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88423730((ts4_word)a2, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    p4 = (ts4_word)t1;
    if ((int)t1 > (int)t2) {
        t3 = fn_884CEEC0((ts4_word)a1, (ts4_word)a0, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x884CF1D8: if_call_seq lbl_8808C434, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808C434_884CF1D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C434;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884CF638: if_call_seq fn_88423D60, lbl_8808C434, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_fn_88423D60_884CF638(ts4_word a0, ts4_word a1)
{
    fn_88423D60((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C434;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CF698: if_call_seq fn_884D8100, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D8100_884CF698(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884D8100();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884CF8F0: addr lbl_8808C570, u32@0x0, fn_884D8100 */
ts4_word ts4_addr_lbl_8808C570_884CF8F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C570;
    return fn_884D8100((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_8808C570);
}

/* Swing_DLL.xex 0x884D1188: get u32@0x8, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off8_884D1188(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x884D11C8: get u32@0x8, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off8_884D11C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884D1238: if_get u32@0xc, u32@0x8, u32@0x0, u32@0x1c */
ts4_word ts4_if_get_u32_offc_884D1238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;
    ts4_word t3;

    p2 = (ts4_word)a1;
    if ((int)a2 == 0) {
        p2 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + a1);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 28))))((ts4_word)t3, (ts4_word)p2, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884D1260: get u32@0x8, u32@0x0, u32@0x20, vcall, u32@0xc */
ts4_word ts4_get_u32_off8_884D1260(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1);
    return (t4 - (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Swing_DLL.xex 0x884D1318: if_call_seq lbl_8808C570, u32@0x0, fn_884D8100, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_lbl_8808C570_884D1318(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C570;
    fn_884D8100();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D1858: if_call_seq fn_884D17A0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D17A0_884D1858(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884D17A0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)5);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D1958: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_884D1958(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x884D1968: if_call_seq ts4_get_u16_offe_88426148, ts4_get_u16_offe_88426148 */
ts4_word ts4_if_call_seq_fn_88426148_884D1968(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_get_u16_offe_88426148((ts4_word)a0);
    if ((int)t1 != 0) {
        t2 = ts4_get_u16_offe_88426148((ts4_word)a0);
        return t2;
    }
    return 1;
}

/* Swing_DLL.xex 0x884D33D0: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_884D33D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D3518: get u32@0xc */
ts4_word ts4_get_u32_offc_884D3518(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x884D36D0: call_seq u32@0x8, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A820, fn_884214A8, u32@0x8 */
ts4_word ts4_call_seq_u32_off8_884D36D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    fn_8841A820((ts4_word)t3, (ts4_word)t1);
    t5 = fn_884214A8((ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    return t5;
}

/* Swing_DLL.xex 0x884D3B70: get u32@0x14 */
ts4_word ts4_get_u32_off14_884D3B70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x884D3B78: call_seq ts4_addr_lbl_8808BFAC_884C5458, u32@0x14, fn_884210E8 */
ts4_word ts4_call_seq_fn_884C5458_884D3B78(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = ts4_addr_lbl_8808BFAC_884C5458();
    t3 = fn_884210E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t1);
    return (t3 == 0);
}

/* Swing_DLL.xex 0x884D3BB8: call_seq lbl_8808C6DC, u16@0x6, u32@0x0, fn_88423CE0, u32@0x14 */
ts4_word ts4_call_seq_lbl_8808C6DC_884D3BB8(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C6DC;
    fn_88423CE0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x884D3EE0: call_seq u32@0x14, lbl_8808C6DC, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A820 */
ts4_word ts4_call_seq_u32_off14_884D3EE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C6DC;
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    fn_8841A820((ts4_word)t3, (ts4_word)t1);
    t5 = fn_88423D60((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return t5;
}

/* Swing_DLL.xex 0x884D3F48: call_seq u32@0x14, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A820, fn_884214A8, u32@0x14 */
ts4_word ts4_call_seq_u32_off14_884D3F48(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    fn_8841A820((ts4_word)t3, (ts4_word)t1);
    t5 = fn_884214A8((ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t5;
    return t5;
}

/* Swing_DLL.xex 0x884D3F88: if_call_seq u32@0x14, lbl_8808C6DC, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A820 */
ts4_word ts4_if_call_seq_u32_off14_884D3F88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C6DC;
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    fn_8841A820((ts4_word)t3, (ts4_word)t1);
    fn_88423D60((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t7 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t7, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D4248: if_call_seq ts4_ref_holder_dtor_nullable_member_884D4008, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D4008_884D4248(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_nullable_member_884D4008((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D42B0: if_call_seq ts4_get_u16_offe_88426148, ts4_get_u16_offe_88426148 */
ts4_word ts4_if_call_seq_fn_88426148_884D42B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_get_u16_offe_88426148((ts4_word)a0);
    if ((int)t1 != 0) {
        t2 = ts4_get_u16_offe_88426148((ts4_word)a0);
        return t2;
    }
    return 1;
}

/* Swing_DLL.xex 0x884D4750: tailcall fn_884D44A8 */
ts4_word ts4_tailcall_fn_884D44A8_884D4750(ts4_word a0)
{
    return fn_884D44A8((ts4_word)a0);
}

/* Swing_DLL.xex 0x884D4AC8: call_seq u32@0x1c, u32@0x1c, fn_884D4138, u32@0x1c */
ts4_word ts4_call_seq_u32_off1c_884D4AC8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    t2 = fn_884D4138((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
    return t2;
}

/* Swing_DLL.xex 0x884D4BC8: tailcall fn_885E7AD8 */
ts4_word ts4_tailcall_fn_885E7AD8_884D4BC8(ts4_word a0, ts4_word a1)
{
    return fn_885E7AD8((ts4_word)(a0 + 44), (ts4_word)a1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884D5208: get u32@0x10 */
ts4_word ts4_get_u32_off10_884D5208(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) & 0x7fffffff);
}

/* Swing_DLL.xex 0x884D5218: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_884D5218(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(2147483648);
    return;
}

/* Swing_DLL.xex 0x884D5860: call_seq u32@0x0, u32@0x4, u32@0x8, fn_88423CE0, u32@0x18 */
ts4_word ts4_call_seq_u32_off0_884D5860(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(2147483648);
    fn_88423CE0((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)-1;
    return a0;
}

/* Swing_DLL.xex 0x884D5CF8: call_seq lbl_8808C82C, u32@0x0, fn_885E7BA8, fn_885E7BA8, fn_884D58B0, ts4_ref_holder_dtor_nullable_member_884D4008 */
ts4_word ts4_call_seq_lbl_8808C82C_884D5CF8(ts4_word a0)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C82C;
    fn_885E7BA8((ts4_word)(a0 + 60));
    fn_885E7BA8((ts4_word)(a0 + 44));
    fn_884D58B0((ts4_word)(a0 + 32));
    t4 = ts4_ref_holder_dtor_nullable_member_884D4008((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x884D5EE8: if_call_seq lbl_8808C82C, u32@0x0, fn_885E7BA8, fn_885E7BA8, fn_884D58B0, ts4_ref_holder_dtor_nullable_member_884D4008 */
ts4_word ts4_if_call_seq_lbl_8808C82C_884D5EE8(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C82C;
    fn_885E7BA8((ts4_word)(a0 + 60));
    fn_885E7BA8((ts4_word)(a0 + 44));
    fn_884D58B0((ts4_word)(a0 + 32));
    ts4_ref_holder_dtor_nullable_member_884D4008((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t6 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t6, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)21);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D60B8: get u32@0x18 */
ts4_word ts4_get_u32_off18_884D60B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x884D6180: get u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off0_884D6180(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x884D6388: get u32@0x44, u32@0x34, fn_88423788 */
ts4_word ts4_get_u32_off44_884D6388(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    return fn_88423788((ts4_word)(t1 + 40), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 52)), (ts4_word)0);
}

/* Swing_DLL.xex 0x884D7508: call_seq u32@0x28, u32@0x28, fn_884DB350, u32@0x28, u32@0x28 */
ts4_word ts4_call_seq_u32_off28_884D7508(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + 1);
    t2 = fn_884DB350();
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + -1);
    return t2;
}

/* Swing_DLL.xex 0x884D7668: if_call_seq fn_884D75B0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D75B0_884D7668(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884D75B0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)5);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D7940: if_call_seq fn_884D63A0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884D63A0_884D7940(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884D63A0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884D79A8: if_get fn_8841EF38, u8@0x0, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_fn_8841EF38_884D79A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    unsigned char t2;
    ts4_word t5;

    t1 = fn_8841EF38((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t2 != 0) {
        if ((ts4_word)a2 != 0) {
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 16))))((ts4_word)a2, (ts4_word)a0);
            return t5;
        }
        return 0;
    }
    return a1;
}

/* Swing_DLL.xex 0x884D7B10: tailcall fn_88423660 */
ts4_word ts4_tailcall_fn_88423660_884D7B10(ts4_word a0)
{
    return fn_88423660((ts4_word)(a0 + 44));
}

/* Swing_DLL.xex 0x884D7F38: tailcall fn_884D7C98 */
ts4_word ts4_tailcall_fn_884D7C98_884D7F38(ts4_word a0)
{
    return fn_884D7C98((ts4_word)a0);
}

/* Swing_DLL.xex 0x884D7F40: call_seq fn_884D7C98, fn_88423660 */
ts4_word ts4_call_seq_fn_884D7C98_884D7F40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_884D7C98((ts4_word)a0, (ts4_word)a2);
    t2 = fn_88423660((ts4_word)(a0 + 156), (ts4_word)a1, (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x884D7F90: call_seq fn_884D7C98, ts4_get_u32_off0_8841EAC8, fn_885E76C0 */
ts4_word ts4_call_seq_fn_884D7C98_884D7F90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_884D7C98((ts4_word)a0, (ts4_word)a2);
    t2 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
    t3 = fn_885E76C0((ts4_word)(a0 + 168), (ts4_word)t2, (ts4_word)t1);
    return t3;
}

/* Swing_DLL.xex 0x884D84A8: call_seq u32@lbl_88C264D8, fn_884D8240, fn_88423788, u32@0x8c, fn_88423788, u32@0x90 */
ts4_word ts4_call_seq_u32_lbl_88C264D8_884D84A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t3;
    ts4_word t4;

    fn_884D8240((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)(*(ts4_word *)lbl_88C264D8));
    t3 = fn_88423788((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)-1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)t3;
    t4 = fn_88423788((ts4_word)(a0 + 20), (ts4_word)a2, (ts4_word)-1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)t4;
    return t4;
}

/* Swing_DLL.xex 0x884D8508: if_call_seq ts4_get_u16_offe_88426148 */
ts4_word ts4_if_call_seq_fn_88426148_884D8508(ts4_word a0)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_get_u16_offe_88426148((ts4_word)a0);
    p2 = (ts4_word)t1;
    if ((int)t1 == 0) {
        p2 = (ts4_word)1;
    }
    return p2;
}

/* Swing_DLL.xex 0x884D9228: tailcall fn_884D9180 */
ts4_word ts4_tailcall_fn_884D9180_884D9228(ts4_word a0)
{
    return fn_884D9180((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x884D9230: tailcall fn_884D9180 */
ts4_word ts4_tailcall_fn_884D9180_884D9230(ts4_word a0)
{
    return fn_884D9180((ts4_word)a0, (ts4_word)-1);
}

/* Swing_DLL.xex 0x884D92F0: tailcall fn_884D9180 */
ts4_word ts4_tailcall_fn_884D9180_884D92F0(ts4_word a0)
{
    return fn_884D9180((ts4_word)(a0 + 8));
}

/* Swing_DLL.xex 0x884DA470: get u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off0_884DA470(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;

    (void)a0;
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return ((a3 - t3) != 0);
}

/* Swing_DLL.xex 0x884DAA38: if_call_seq ts4_ref_holder_dtor_owner_884DA7B0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884DA7B0_884DAA38(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_owner_884DA7B0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884DB580: get u32@0x14 */
ts4_word ts4_get_u32_off14_884DB580(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x884DCB60: if_call_seq fn_884DB7D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884DB7D8_884DCB60(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884DB7D8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884DCD68: if_call_seq fn_884DCC60, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884DCC60_884DCD68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884DCC60();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)1);
    }
    return a0;
}

/* Swing_DLL.xex 0x884DCE88: if_call_seq ts4_get_u16_offe_88426148 */
ts4_word ts4_if_call_seq_fn_88426148_884DCE88(ts4_word a0)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_get_u16_offe_88426148((ts4_word)a0);
    p2 = (ts4_word)t1;
    if ((int)t1 == 0) {
        p2 = (ts4_word)1;
    }
    return p2;
}

/* Swing_DLL.xex 0x884DD800: if_call_seq lbl_8808CF00, fn_884DCFA8, fn_884DD040, lbl_8808CEFC, fn_884DCFA8 */
ts4_word ts4_if_call_seq_lbl_8808CF00_884DD800(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a0;
    fn_884DCFA8((ts4_word)a1, (ts4_word)(ts4_word)lbl_8808CF00);
    t2 = fn_884DD040((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    if ((int)t2 == 0) {
        fn_884DCFA8((ts4_word)a1, (ts4_word)(ts4_word)lbl_8808CEFC);
    }
    return t2;
}

/* Swing_DLL.xex 0x884DF650: if_call_seq ts4_ref_holder_dtor_884DCDD8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884DCDD8_884DF650(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_884DCDD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x884E1690: if_call_seq fn_884E1430, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884E1430_884E1690(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884E1430();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884E1860: if_call_seq u32@0x18, fn_88472530, fn_884E1760, fn_884E17F8, u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_u32_off18_884E1860(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    fn_88472530((ts4_word)t1);
    t3 = fn_884E1760((ts4_word)a0, (ts4_word)a1);
    if ((int)t3 < 0) {
        p6 = (ts4_word)0;
    } else {
        t4 = fn_884E17F8((ts4_word)a0, (ts4_word)t3, (ts4_word)a2);
        p6 = (ts4_word)t4;
    }
    *(ts4_u64 *)((char *)(ts4_word)(t1) + 32) = (ts4_u64)-1;
    RtlLeaveCriticalSection((ts4_word)t1);
    return p6;
}

/* Swing_DLL.xex 0x884E1AA8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884E18D0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884E1AA8(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)28, (ts4_word)53);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)28;
    t4 = fn_884E18D0((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x884E1E80: if_call_seq fn_884E19D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884E19D8_884E1E80(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884E19D8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884E2100: if_call_seq u32@0x8, lbl_88088A4C, u32@0x0, ts4_pooled_deleting_dtor_884E2060, u32@0x8, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off8_884E2100(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88088A4C;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_pooled_deleting_dtor_884E2060((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x884E33C8: call_seq fn_885EC530, u32@0x0, fn_885EC530, u32@0x4, fn_885EC530, u32@0x8 */
ts4_word ts4_call_seq_fn_885EC530_884E33C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    fn_885EC530((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4, (ts4_word)1);
    t2 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    fn_885EC530((ts4_word)a0, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)1);
    t4 = loc54[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t4;
    t5 = fn_885EC530((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4, (ts4_word)1);
    t6 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t6;
    return t5;
}

/* Swing_DLL.xex 0x884E3450: call_seq fn_885EC530 */
ts4_word ts4_call_seq_fn_885EC530_884E3450(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_885EC530((ts4_word)a0, (ts4_word)a1, (ts4_word)4, (ts4_word)3);
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)lbl_88001A20);
    return t1;
}

/* Swing_DLL.xex 0x884E3E90: if_call_seq ts4_ref_holder_dtor_nullable_885EC7D8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_885EC7D8_884E3E90(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_nullable_885EC7D8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884E4B60: get  */
float ts4_get_884E4B60(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 144));
}

/* Swing_DLL.xex 0x884E4B68: get  */
float ts4_get_884E4B68(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 148));
}

/* Swing_DLL.xex 0x884E4B70: get  */
float ts4_get_884E4B70(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 152));
}

/* Swing_DLL.xex 0x884E4B78: get u32@0x9c */
ts4_word ts4_get_u32_off9c_884E4B78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 156));
}

/* Swing_DLL.xex 0x884E5170: fn  */
ts4_word ts4_fn_884E5170(ts4_word a0)
{
    return (a0 + 144);
}

/* Swing_DLL.xex 0x884E5810: get  */
float ts4_get_884E5810(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 136));
}

/* Swing_DLL.xex 0x884E5818: get  */
float ts4_get_884E5818(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 132));
}

/* Swing_DLL.xex 0x884E6028: call_seq u32@0x14, fn_88472530, u32@0x14, u32@0xc, u64@0x20, RtlLeaveCriticalSection */
ts4_word ts4_call_seq_u32_off14_884E6028(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    fn_88472530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(t3) + 32) = (ts4_u64)-1;
    t4 = RtlLeaveCriticalSection((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x884E74A0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884E7310 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884E74A0(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)24, (ts4_word)53);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)24;
    t4 = fn_884E7310((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x884E74E0: if_call_seq fn_884E7418, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884E7418_884E74E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884E7418((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EB2B0: if_call_seq lbl_8808D3F4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808D3F4_884EB2B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D3F4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884EB2F8: addr lbl_88C2681C, u32@0x0, u32@0x0 */
void ts4_addr_lbl_88C2681C_884EB2F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(ts4_word)lbl_88C2681C;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x884EB450: call_seq u32@0x10, fn_88427418, u32@0x10, fn_88426FA0, u32@0x10, fn_88427418 */
ts4_word ts4_call_seq_u32_off10_884EB450(ts4_word a0, ts4_word a1)
{
    fn_88427418((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)5);
    fn_88426FA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)193);
    fn_88427418((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1);
    return 0;
}

/* Swing_DLL.xex 0x884EBB08: if_call_seq fn_88423D60, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_88423D60_884EBB08(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88423D60((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EBB80: get u32@lbl_88D26FD8 */
ts4_word ts4_get_u32_lbl_88D26FD8_884EBB80(void)
{
    return (*(ts4_word *)lbl_88D26FD8);
}

/* Swing_DLL.xex 0x884EBB90: tailcall ts4_if_call_seq_fn_884EB998_884EBBC0 */
ts4_word ts4_tailcall_fn_884EBBC0_884EBB90(ts4_word a0)
{
    return ts4_if_call_seq_fn_884EB998_884EBBC0((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x884EBBA0: get u32@lbl_88D26FD0, fn_884E1760 */
ts4_word ts4_get_u32_lbl_88D26FD0_884EBBA0(void)
{
    return fn_884E1760((ts4_word)(*(ts4_word *)lbl_88D26FD0));
}

/* Swing_DLL.xex 0x884EBBB0: get u32@lbl_88D26FD0, fn_884E16F8 */
ts4_word ts4_get_u32_lbl_88D26FD0_884EBBB0(void)
{
    return fn_884E16F8((ts4_word)(*(ts4_word *)lbl_88D26FD0));
}

/* Swing_DLL.xex 0x884EBD40: call_seq ts4_call_seq_fn_884EF3A0_884EF3F0, ts4_call_seq_fn_884EEF90_884EEFF0, ts4_call_seq_fn_884EDC20_884EDC80 */
ts4_word ts4_call_seq_fn_884EF3F0_884EBD40(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_call_seq_fn_884EF3A0_884EF3F0();
    t2 = ts4_call_seq_fn_884EEF90_884EEFF0((ts4_word)t1);
    t3 = ts4_call_seq_fn_884EDC20_884EDC80((ts4_word)t2);
    return t3;
}

/* Swing_DLL.xex 0x884EBFD0: if_call_seq lbl_8808D4C4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8808D4C4_884EBFD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D4C4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884ECDF8: if_call_seq u32@0x10, lbl_8808D560, lbl_8808D514, u32@0x0, u32@0x8, fn_88472858 */
ts4_word ts4_if_call_seq_u32_off10_884ECDF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D560;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808D514;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88472858((ts4_word)t1, (ts4_word)1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808D4C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p3;
}

/* Swing_DLL.xex 0x884ECE68: tailcall ts4_if_call_seq_u32_off10_884ECE70 */
ts4_word ts4_tailcall_fn_884ECE70_884ECE68(ts4_word a0)
{
    return ts4_if_call_seq_u32_off10_884ECE70((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884ECF68: call_seq u32@0x0, fn_88427418, u32@0x4, fn_88427418, u32@0x8, fn_88427418 */
ts4_word ts4_call_seq_u32_off0_884ECF68(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    fn_88427418((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    fn_88427418((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t6 = fn_88427418((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
    return t6;
}

/* Swing_DLL.xex 0x884ECFC0: tailcall ts4_tailcall_fn_88426FF8_884276E8 */
ts4_word ts4_tailcall_fn_884276E8_884ECFC0(ts4_word a0, ts4_word a1)
{
    return ts4_tailcall_fn_88426FF8_884276E8((ts4_word)a0, (ts4_word)a1, (ts4_word)3);
}

/* Swing_DLL.xex 0x884ED578: if_call_seq ts4_ref_holder_dtor_88427338, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88427338_884ED578(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_ref_holder_dtor_88427338((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)13);
    }
    return a0;
}

/* Swing_DLL.xex 0x884ED5E0: addr lbl_88C26908, u32@0x0, u32@0x0 */
void ts4_addr_lbl_88C26908_884ED5E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(ts4_word)lbl_88C26908;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)5;
    return;
}

/* Swing_DLL.xex 0x884EE550: get u32@lbl_88D26FDC */
ts4_word ts4_get_u32_lbl_88D26FDC_884EE550(void)
{
    return (*(ts4_word *)lbl_88D26FDC);
}

/* Swing_DLL.xex 0x884EE560: tailcall ts4_if_call_seq_fn_884EDB18_884EE568 */
ts4_word ts4_tailcall_fn_884EE568_884EE560(ts4_word a0)
{
    return ts4_if_call_seq_fn_884EDB18_884EE568((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884EF030: get u32@lbl_88D26FE0 */
ts4_word ts4_get_u32_lbl_88D26FE0_884EF030(void)
{
    return (*(ts4_word *)lbl_88D26FE0);
}

/* Swing_DLL.xex 0x884EF040: tailcall ts4_if_call_seq_fn_884EE5D0_884EF048 */
ts4_word ts4_tailcall_fn_884EF048_884EF040(ts4_word a0)
{
    return ts4_if_call_seq_fn_884EE5D0_884EF048((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884EF170: get u32@-0x8, u32@0x0, u32@lbl_88D26FE4, u32@0x14 */
ts4_word ts4_get_u32_0x8_884EF170(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -8);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)lbl_88D26FE4;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)t3);
}

/* Swing_DLL.xex 0x884EF248: get u32@-0x8, u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_0x8_884EF248(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 56))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EF260: get u32@-0x8, u32@0x0, u32@0x3c */
ts4_word ts4_get_u32_0x8_884EF260(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EF430: get u32@lbl_88D26FE4 */
ts4_word ts4_get_u32_lbl_88D26FE4_884EF430(void)
{
    return (*(ts4_word *)lbl_88D26FE4);
}

/* Swing_DLL.xex 0x884EF440: tailcall ts4_if_call_seq_fn_884EF320_884EF450 */
ts4_word ts4_tailcall_fn_884EF450_884EF440(ts4_word a0)
{
    return ts4_if_call_seq_fn_884EF320_884EF450((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884EF448: tailcall ts4_if_call_seq_fn_884EF320_884EF450 */
ts4_word ts4_tailcall_fn_884EF450_884EF448(ts4_word a0)
{
    return ts4_if_call_seq_fn_884EF320_884EF450((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884EFE90: tailcall fn_884EFDD0 */
ts4_word ts4_tailcall_fn_884EFDD0_884EFE90(ts4_word a0)
{
    return fn_884EFDD0((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x884EFEA0: tailcall NetDll_XNetCleanup */
ts4_word ts4_tailcall_NetDll_XNetCleanup_884EFEA0(void)
{
    return NetDll_XNetCleanup((ts4_word)1);
}

/* Swing_DLL.xex 0x884EFEA8: tailcall NetDll_XNetUnregisterKey */
ts4_word ts4_tailcall_NetDll_XNetUnregisterKey_884EFEA8(ts4_word a0)
{
    return NetDll_XNetUnregisterKey((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x884EFEB8: tailcall NetDll_XNetXnAddrToInAddr */
ts4_word ts4_tailcall_NetDll_XNetXnAddrToInAddr_884EFEB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetXnAddrToInAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EFED0: tailcall NetDll_XNetServerToInAddr */
ts4_word ts4_tailcall_NetDll_XNetServerToInAddr_884EFED0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetServerToInAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EFEE8: tailcall NetDll_XNetInAddrToXnAddr */
ts4_word ts4_tailcall_NetDll_XNetInAddrToXnAddr_884EFEE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetInAddrToXnAddr((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EFF00: tailcall NetDll_XNetInAddrToString */
ts4_word ts4_tailcall_NetDll_XNetInAddrToString_884EFF00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetInAddrToString((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EFF48: tailcall NetDll_XNetDnsLookup */
ts4_word ts4_tailcall_NetDll_XNetDnsLookup_884EFF48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_XNetDnsLookup((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884EFF60: tailcall NetDll_XNetDnsRelease */
ts4_word ts4_tailcall_NetDll_XNetDnsRelease_884EFF60(ts4_word a0)
{
    return NetDll_XNetDnsRelease((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x884EFF70: tailcall NetDll_XNetQosListen */
ts4_word ts4_tailcall_NetDll_XNetQosListen_884EFF70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_XNetQosListen((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884F0010: tailcall NetDll_XNetGetEthernetLinkStatus */
ts4_word ts4_tailcall_NetDll_XNetGetEthernetLinkStatus_884F0010(void)
{
    return NetDll_XNetGetEthernetLinkStatus((ts4_word)1);
}

/* Swing_DLL.xex 0x884F0228: tailcall fn_884F0178 */
ts4_word ts4_tailcall_fn_884F0178_884F0228(ts4_word a0, ts4_word a1)
{
    return fn_884F0178((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884F0238: tailcall NetDll_WSACleanup */
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238(void)
{
    return NetDll_WSACleanup((ts4_word)1);
}

/* Swing_DLL.xex 0x884F0240: tailcall NetDll_socket */
ts4_word ts4_tailcall_NetDll_socket_884F0240(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_socket((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F0258: tailcall NetDll_closesocket */
ts4_word ts4_tailcall_NetDll_closesocket_884F0258(ts4_word a0)
{
    return NetDll_closesocket((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x884F0268: tailcall NetDll_ioctlsocket */
ts4_word ts4_tailcall_NetDll_ioctlsocket_884F0268(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_ioctlsocket((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F0280: tailcall NetDll_setsockopt */
ts4_word ts4_tailcall_NetDll_setsockopt_884F0280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_setsockopt((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884F02A0: tailcall NetDll_bind */
ts4_word ts4_tailcall_NetDll_bind_884F02A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_bind((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F02B8: tailcall NetDll_connect */
ts4_word ts4_tailcall_NetDll_connect_884F02B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_connect((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F02D0: tailcall NetDll_listen */
ts4_word ts4_tailcall_NetDll_listen_884F02D0(ts4_word a0, ts4_word a1)
{
    return NetDll_listen((ts4_word)1, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x884F02E0: tailcall NetDll_accept */
ts4_word ts4_tailcall_NetDll_accept_884F02E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return NetDll_accept((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F02F8: tailcall NetDll_select */
ts4_word ts4_tailcall_NetDll_select_884F02F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return NetDll_select((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x884F0318: tailcall NetDll_recv */
ts4_word ts4_tailcall_NetDll_recv_884F0318(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_recv((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x884F0330: tailcall NetDll_recvfrom */
ts4_word ts4_tailcall_NetDll_recvfrom_884F0330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return NetDll_recvfrom((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Swing_DLL.xex 0x884F0350: tailcall NetDll_send */
ts4_word ts4_tailcall_NetDll_send_884F0350(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return NetDll_send((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x884F0368: tailcall NetDll_sendto */
ts4_word ts4_tailcall_NetDll_sendto_884F0368(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return NetDll_sendto((ts4_word)1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Swing_DLL.xex 0x884F0388: tailcall NetDll_inet_addr */
ts4_word ts4_tailcall_NetDll_inet_addr_884F0388(ts4_word a0)
{
    return NetDll_inet_addr((ts4_word)a0);
}

/* Swing_DLL.xex 0x884F0390: tailcall NetDll_WSAGetLastError */
ts4_word ts4_tailcall_NetDll_WSAGetLastError_884F0390(ts4_word a0)
{
    return NetDll_WSAGetLastError((ts4_word)a0);
}

/* Swing_DLL.xex 0x884F0398: tailcall NetDll___WSAFDIsSet */
ts4_word ts4_tailcall_NetDll__WSAFDIsSet_884F0398(ts4_word a0)
{
    return NetDll___WSAFDIsSet((ts4_word)a0);
}

/* Swing_DLL.xex 0x884F1968: get u16@0x0, u16@0x0 */
ts4_word ts4_get_u16_off0_884F1968(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return (t1 - (*(unsigned short *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x884F1A00: addr lbl_88C2D57C, fn_884F1978 */
ts4_word ts4_addr_lbl_88C2D57C_884F1A00(void)
{
    return fn_884F1978((ts4_word)(ts4_word)lbl_88C2D57C);
}

/* Swing_DLL.xex 0x884F1DD0: call_seq XamUserGetXUID, XamUserWriteProfileSettings */
ts4_word ts4_call_seq_XamUserGetXUID_884F1DD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word t2;

    XamUserGetXUID((ts4_word)a0, (ts4_word)3, (ts4_word)(ts4_word)&loc50[0]);
    t2 = XamUserWriteProfileSettings((ts4_word)0, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t2;
}

/* Swing_DLL.xex 0x884F1F98: call_seq fn_884F3458 */
ts4_word ts4_call_seq_fn_884F3458_884F1F98(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;

    loc50[0] = (ts4_word)1;
    t1 = fn_884F3458((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x884F2020: call_seq fn_884F3458 */
ts4_word ts4_call_seq_fn_884F3458_884F2020(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;

    loc50[0] = (ts4_word)2;
    t1 = fn_884F3458((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x884F2FF8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_884F2FF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a4;
    return;
}

/* Swing_DLL.xex 0x884F3018: if_get u32@0x8, u32@0xc */
ts4_word ts4_if_get_u32_off8_884F3018(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)a1 > (ts4_word)t1) {
        return ((2149056512) | 8193);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x884F3428: call_seq u32@0x10, fn_884F3090 */
ts4_word ts4_call_seq_u32_off10_884F3428(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    loc50[0] = (ts4_word)2;
    t2 = fn_884F3090((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x884F34A8: tailcall fn_884F3040 */
ts4_word ts4_tailcall_fn_884F3040_884F34A8(ts4_word a0)
{
    return fn_884F3040((ts4_word)a0);
}

/* Swing_DLL.xex 0x884F4420: addr fn_884F4408 */
ts4_word ts4_addr_fn_884F4408_884F4420(void)
{
    return (ts4_word)fn_884F4408;
}

/* Swing_DLL.xex 0x884F4738: tailcall fn_884F4698 */
ts4_word ts4_tailcall_fn_884F4698_884F4738(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_884F4698((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884F4828: call_seq ts4_call_seq_fn_884FD970_884F90D8 */
ts4_word ts4_call_seq_fn_884F90D8_884F4828(ts4_word a0)
{
    ts4_call_seq_fn_884FD970_884F90D8((ts4_word)(a0 + 64));
    return 0;
}

/* Swing_DLL.xex 0x884F4850: call_seq ts4_call_seq_fn_884FD970_884F9108 */
ts4_word ts4_call_seq_fn_884F9108_884F4850(ts4_word a0)
{
    ts4_call_seq_fn_884FD970_884F9108((ts4_word)(a0 + 32));
    return 0;
}

/* Swing_DLL.xex 0x884F6138: addr lbl_88C2D5EC */
ts4_word ts4_addr_lbl_88C2D5EC_884F6138(void)
{
    return (ts4_word)lbl_88C2D5EC;
}

/* Swing_DLL.xex 0x884F6148: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_884F6148(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884F65E8: get u32@0xec */
ts4_word ts4_get_u32_offec_884F65E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 236));
}

/* Swing_DLL.xex 0x884FD928: if_call_seq u32@lbl_88D275C0, fn_884FD878, u32@0x14c */
ts4_word ts4_if_call_seq_u32_lbl_88D275C0_884FD928(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)lbl_88D275C0;
    p3 = (ts4_word)a0;
    if ((int)t1 == 0) {
        t2 = fn_884FD878();
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x885018B0: if_call_seq u32@0x18, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off18_885018B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88579FC0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x885037B8: fn  */
ts4_word ts4_fn_885037B8(ts4_word a0)
{
    return (a0 + 16);
}

/* Swing_DLL.xex 0x885037C0: fn  */
ts4_word ts4_fn_885037C0(ts4_word a0)
{
    return (a0 + 16);
}

/* Swing_DLL.xex 0x885037D0: fn  */
ts4_word ts4_fn_885037D0(ts4_word a0, ts4_word a1)
{
    return ((((a1 + (a1 << 3)) << 4) + a0) + 32);
}

/* Swing_DLL.xex 0x88503A68: get u32@0x0, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_get_u32_off0_88503A68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + -16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t2))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88512790: set  */
void ts4_set_88512790(ts4_word a0, ts4_word a1, float f1)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 4) = f1;
    return;
}

/* Swing_DLL.xex 0x88512798: set  */
void ts4_set_88512798(ts4_word a0, ts4_word a1, ts4_word a2, float f1, float f2)
{
    (void)a0;
    (void)a1;
    *(float *)((char *)(ts4_word)(a2) + 0) = f1;
    *(float *)((char *)(ts4_word)(a2) + 4) = f2;
    return;
}

/* Swing_DLL.xex 0x885127A8: set  */
void ts4_set_885127A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, float f1, float f2, float f3, float f4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    *(float *)((char *)(ts4_word)(a4) + 0) = f1;
    *(float *)((char *)(ts4_word)(a4) + 4) = f2;
    *(float *)((char *)(ts4_word)(a4) + 8) = f3;
    *(float *)((char *)(ts4_word)(a4) + 12) = f4;
    return;
}

/* Swing_DLL.xex 0x885134F8: tailcall fn_885127C0 */
ts4_word ts4_tailcall_fn_885127C0_885134F8(ts4_word a0)
{
    return fn_885127C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88514FF0: get u32@lbl_88D2E294, u32@lbl_88D2E294 */
void ts4_get_u32_lbl_88D2E294_88514FF0(void)
{
    *(ts4_word *)lbl_88D2E294 = (ts4_word)((*(ts4_word *)lbl_88D2E294) + 1);
    return;
}

/* Swing_DLL.xex 0x88515008: tailcall fn_885637C0 */
ts4_word ts4_tailcall_fn_885637C0_88515008(ts4_word a0)
{
    return fn_885637C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88515010: tailcall fn_885637C0 */
ts4_word ts4_tailcall_fn_885637C0_88515010(void)
{
    return fn_885637C0((ts4_word)0);
}

/* Swing_DLL.xex 0x88516D30: set  */
void ts4_set_88516D30(ts4_word a0, float f1, float f2, float f3, float f4)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    *(float *)((char *)(ts4_word)(a0) + 12) = f4;
    return;
}

/* Swing_DLL.xex 0x88516D48: get  */
void ts4_get_88516D48(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Swing_DLL.xex 0x88517330: fn  */
ts4_word ts4_fn_88517330(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + a0);
}

/* Swing_DLL.xex 0x88520B30: tailcall fn_885637C0 */
ts4_word ts4_tailcall_fn_885637C0_88520B30(ts4_word a0)
{
    return fn_885637C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88520B38: tailcall fn_885637C0 */
ts4_word ts4_tailcall_fn_885637C0_88520B38(void)
{
    return fn_885637C0((ts4_word)0);
}

/* Swing_DLL.xex 0x88520B58: if_addr lbl_8808DF6C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808DF6C_88520B58(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808DF6C;
    return;
}

/* Swing_DLL.xex 0x88520B78: addr lbl_8808DF6C */
ts4_word ts4_addr_lbl_8808DF6C_88520B78(void)
{
    return (ts4_word)lbl_8808DF6C;
}

/* Swing_DLL.xex 0x88520C28: if_call_seq fn_88520B88, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88520B88_88520C28(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88520B88();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88520CB8: if_addr lbl_8808DFE8, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808DFE8_88520CB8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808DFE8;
    return;
}

/* Swing_DLL.xex 0x88520CD8: addr lbl_8808DFE8 */
ts4_word ts4_addr_lbl_8808DFE8_88520CD8(void)
{
    return (ts4_word)lbl_8808DFE8;
}

/* Swing_DLL.xex 0x88520D60: if_call_seq fn_88520CE8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88520CE8_88520D60(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88520CE8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)40);
    }
    return a0;
}

/* Swing_DLL.xex 0x88520E88: tailcall fn_88520DD8 */
ts4_word ts4_tailcall_fn_88520DD8_88520E88(ts4_word a0)
{
    return fn_88520DD8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88520E90: get u32@0x0, lbl_8808E0A0, u32@0x10, vcall, fn_8852E0C0, u32@0x0 */
ts4_word ts4_get_u32_off0_88520E90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t7;

    (void)a0;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 16))))((ts4_word)a3, (ts4_word)(ts4_word)lbl_8808E0A0);
    fn_8852E0C0((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 20))))((ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88520F10: get u32@0x0, u32@0x0, u32@0x14, vcall, ts4_addr_fn_8852DA00_8852DB68 */
ts4_word ts4_get_u32_off0_88520F10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[7];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
    loc50[3] = (ts4_word)t4;
    loc50[0] = (ts4_word)a2;
    loc50[1] = (ts4_word)a3;
    loc50[4] = (ts4_word)a4;
    loc50[5] = (ts4_word)a5;
    loc50[6] = (ts4_word)a6;
    t5 = ts4_addr_fn_8852DA00_8852DB68((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88520F78: get u32@0x0, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_88520F78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88521690: get u32@0x0, lbl_8808E0B0, u32@0x10, vcall, fn_8852E0C0, u32@0x0 */
ts4_word ts4_get_u32_off0_88521690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t7;

    (void)a0;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 16))))((ts4_word)a3, (ts4_word)(ts4_word)lbl_8808E0B0);
    fn_8852E0C0((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 20))))((ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88521710: get u32@0x0, u32@0x0, u32@0x14, vcall, ts4_addr_fn_8852DA00_8852DB68 */
ts4_word ts4_get_u32_off0_88521710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[7];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
    loc50[3] = (ts4_word)t4;
    loc50[0] = (ts4_word)a2;
    loc50[1] = (ts4_word)a3;
    loc50[4] = (ts4_word)a4;
    loc50[5] = (ts4_word)a5;
    loc50[6] = (ts4_word)a6;
    t5 = ts4_addr_fn_8852DA00_8852DB68((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88521908: if_call_seq u32@0x0, u32@0x4, u32@0x8, fn_8852CD50 */
ts4_word ts4_if_call_seq_u32_off0_88521908(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a0;
    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(2147483648);
    }
    fn_8852CD50((ts4_word)a2);
    return (a2 + 16);
}

/* Swing_DLL.xex 0x88521BB8: tailcall fn_88523FC0 */
ts4_word ts4_tailcall_fn_88523FC0_88521BB8(ts4_word a0)
{
    return fn_88523FC0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88522380: call_seq u32@0x4, u32@0x0, u8@0x2, u16@0x0, u16@0x2, u16@0x4 */
ts4_word ts4_call_seq_u32_off4_88522380(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0);
    *(unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)0;
    *(unsigned short *)((char *)(ts4_word)(a2) + 0) = (unsigned short)((0) | 65535);
    *(unsigned short *)((char *)(ts4_word)(a2) + 2) = (unsigned short)((0) | 65535);
    *(unsigned short *)((char *)(ts4_word)(a2) + 4) = (unsigned short)((0) | 65535);
    fn_88538098((ts4_word)(t2 + 32), (ts4_word)(a2 + 8));
    return (a2 + 32);
}

/* Swing_DLL.xex 0x88522B80: if_call_seq ts4_set_u16_off2_88468338 */
ts4_word ts4_if_call_seq_fn_88468338_88522B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a0;
    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        ts4_set_u16_off2_88468338((ts4_word)a2);
    }
    return (a2 + 64);
}

/* Swing_DLL.xex 0x88524038: call_seq fn_88531FF8, u8@0x2 */
ts4_word ts4_call_seq_fn_88531FF8_88524038(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = fn_88531FF8((ts4_word)(a1 + 12), (ts4_word)a2, (ts4_word)a3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x88524840: get u32@0x0, lbl_8808E150, u32@0x10, vcall, fn_8852E0C0, u32@0x0 */
ts4_word ts4_get_u32_off0_88524840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t7;

    (void)a0;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 16))))((ts4_word)a3, (ts4_word)(ts4_word)lbl_8808E150);
    fn_8852E0C0((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 20))))((ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x8852DD28: addr fn_8852DB78, fn_8852D668 */
ts4_word ts4_addr_fn_8852DB78_8852DD28(ts4_word a0, ts4_word a1)
{
    return fn_8852D668((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)fn_8852DB78);
}
