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
extern char ts4_tailcall_fn_88523FC0_88521BB8[];
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
ts4_word ts4_if_call_seq_u32_off8_884E2100();
ts4_word fn_884E7310();
ts4_word fn_884E7418();
ts4_word fn_884EB998();
ts4_word fn_884EDB18();
ts4_word fn_884EE5D0();
ts4_word fn_884EF320();
ts4_word fn_884EFDD0();
ts4_word fn_884F0178();
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238();
ts4_word fn_884F1978();
ts4_word fn_884F3040();
ts4_word fn_884F3090();
ts4_word fn_884F3458();
ts4_word fn_884F4698();
ts4_word fn_884FD878();
ts4_word fn_884FD910();
ts4_word ts4_if_call_seq_u32_lbl_88D275C0_884FD928();
ts4_word fn_884FD970();
ts4_word fn_885127C0();
ts4_word fn_88520B88();
ts4_word fn_88520CE8();
ts4_word fn_88520DD8();
ts4_word fn_88523FC0();
ts4_word fn_8852CD50();
ts4_word fn_8852D668();
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

/* Swing_DLL.xex 0x884E5F10: if_call_seq ts4_if_call_seq_u32_off8_884E2100, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884E2100_884E5F10(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_if_call_seq_u32_off8_884E2100((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)8);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EBBC0: if_call_seq fn_884EB998, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884EB998_884EBBC0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884EB998();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884ECE70: if_call_seq u32@0x10, lbl_8808D560, lbl_8808D514, u32@0x0, u32@0x8, fn_88472858 */
ts4_word ts4_if_call_seq_u32_off10_884ECE70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D560;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808D514;
    if ((ts4_word)t1 != 0) {
        fn_88472858((ts4_word)t1, (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808D4C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t5, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EDC80: call_seq fn_884EDC20, lbl_8808D57C, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26FDC */
ts4_word ts4_call_seq_fn_884EDC20_884EDC80(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_8808D57C, (ts4_word)(ts4_word)fn_884EDC20);
    *(ts4_word *)lbl_88D26FDC = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884EE568: if_call_seq fn_884EDB18, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884EDB18_884EE568(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884EDB18();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EEFF0: call_seq fn_884EEF90, lbl_880DCF0C, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26FE0 */
ts4_word ts4_call_seq_fn_884EEF90_884EEFF0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_880DCF0C, (ts4_word)(ts4_word)fn_884EEF90);
    *(ts4_word *)lbl_88D26FE0 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884EF048: if_call_seq fn_884EE5D0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884EE5D0_884EF048(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884EE5D0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884EF3F0: call_seq fn_884EF3A0, lbl_8808CF4C, u32@lbl_88D26FD0, fn_884E1AE8, u32@lbl_88D26FE4 */
ts4_word ts4_call_seq_fn_884EF3A0_884EF3F0(void)
{
    ts4_word t2;

    t2 = fn_884E1AE8((ts4_word)(*(ts4_word *)lbl_88D26FD0), (ts4_word)(ts4_word)lbl_8808CF4C, (ts4_word)(ts4_word)fn_884EF3A0);
    *(ts4_word *)lbl_88D26FE4 = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x884EF450: if_call_seq fn_884EF320, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884EF320_884EF450(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884EF320((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)53);
    }
    return a0;
}

/* Swing_DLL.xex 0x884F1A10: call_seq ts4_tailcall_NetDll_WSACleanup_884F0238 */
ts4_word ts4_call_seq_fn_884F0238_884F1A10(void)
{
    ts4_tailcall_NetDll_WSACleanup_884F0238();
    return 0;
}

/* Swing_DLL.xex 0x884F90D8: call_seq fn_884FD970, fn_884FD910 */
ts4_word ts4_call_seq_fn_884FD970_884F90D8(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_884FD970((ts4_word)a0, (ts4_word)160);
    fn_884FD910((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x884F9108: call_seq fn_884FD970, ts4_if_call_seq_u32_lbl_88D275C0_884FD928 */
ts4_word ts4_call_seq_fn_884FD970_884F9108(ts4_word a0)
{
    fn_884FD970((ts4_word)a0, (ts4_word)160);
    ts4_if_call_seq_u32_lbl_88D275C0_884FD928((ts4_word)(a0 + 640));
    return 0;
}

/* Swing_DLL.xex 0x88522110: addr fn_88521B50, fn_88521CB8, fn_88521C80, u32@0x0, ts4_tailcall_fn_88523FC0_88521BB8, u32@0x2c */
void ts4_addr_fn_88521B50_88522110(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88521B50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(ts4_word)fn_88521CB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(ts4_word)fn_88521C80;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)ts4_tailcall_fn_88523FC0_88521BB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_88521BC0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)fn_88521BD8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)fn_88521BF0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(ts4_word)fn_88521C08;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(ts4_word)fn_88521A98;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)fn_88521B08;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(ts4_word)fn_88521B30;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_88521B90;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8852DB68: addr fn_8852DA00, fn_8852D668 */
ts4_word ts4_addr_fn_8852DA00_8852DB68(ts4_word a0, ts4_word a1)
{
    return fn_8852D668((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)fn_8852DA00);
}

