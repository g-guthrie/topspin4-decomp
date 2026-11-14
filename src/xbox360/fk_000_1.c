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

extern char lbl_880C1320[];
extern char lbl_880D19F0[];
extern char lbl_880D1FD0[];
extern char lbl_880D2208[];
extern char lbl_880D2D10[];
extern char lbl_880D2DEC[];
extern char lbl_880D3118[];
extern char lbl_880D4B88[];
extern char lbl_880D4EA0[];
extern char lbl_880D5078[];
extern char lbl_880D5168[];
extern char lbl_880D5528[];
extern char lbl_880D5570[];
extern char lbl_880D55B8[];
extern char lbl_880D5600[];
extern char lbl_880D5864[];
extern char lbl_880D5A64[];
extern char lbl_880D5AA0[];
extern char lbl_880D5B10[];
extern char lbl_880D5BBC[];
extern char lbl_880D5EE8[];
extern char lbl_880D6A78[];
extern char lbl_880D6B70[];
extern char lbl_880D7058[];
extern char lbl_880D7074[];
extern char lbl_880D709C[];
extern char lbl_880D70B8[];
extern char lbl_880D70D4[];
extern char lbl_880D70F0[];
extern char lbl_880D710C[];
extern char lbl_880D7128[];
extern char lbl_880D7144[];
extern char lbl_880D7160[];
extern char lbl_880D717C[];
extern char lbl_880D7310[];
extern char lbl_880D7380[];
extern char lbl_880D73C4[];
extern char lbl_880D73FC[];
extern char lbl_880D7570[];
extern char lbl_880DB358[];
extern char lbl_880DB478[];
extern char lbl_880DB648[];
extern char lbl_880DB6C0[];
extern char lbl_880F7D28[];
extern char lbl_88D45878[];
extern char lbl_88D4588C[];
extern char lbl_88D458A0[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_88155A40();
ts4_word fn_88157B78();
ts4_word ts4_byte_string_assign_88158908();
ts4_word fn_88159870();
ts4_word ts4_if_call_seq_u32_off0_88159A58();
ts4_word fn_8815B060();
ts4_word fn_8815C9E8();
ts4_word fn_8815D160();
ts4_word fn_8815DB40();
ts4_word fn_8815DC10();
ts4_word fn_8815DCE0();
ts4_word fn_8815DDC0();
ts4_word fn_8815DF80();
ts4_word fn_8815E628();
ts4_word fn_8815ED78();
ts4_word fn_8815EF18();
ts4_word fn_881616D8();
ts4_word fn_881617C8();
ts4_word fn_88161B30();
ts4_word fn_88165F68();
ts4_word fn_88165FC8();
ts4_word fn_8816C6B0();
ts4_word fn_8816D1A8();
ts4_word fn_8816DFB8();
ts4_word fn_88173C00();
ts4_word fn_8817EB80();
ts4_word fn_8817F860();
ts4_word fn_881A6A00();
ts4_word ts4_tailcall_NetDll_ioctlsocket_884F0268();
ts4_word ts4_tailcall_NetDll_accept_884F02E0();
ts4_word fn_88562DC0();
ts4_word ts4_tailcall_fn_88564B00_88564770();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_8860DCF8();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word fn_88616758();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_888860A0();
ts4_word ts4_call_seq_fn_88617D88_888CB0F0();
ts4_word ts4_call_seq_fn_88617D88_888CB978();
ts4_word fn_888CBD50();
ts4_word ts4_singleton_service_ctor_888CCF98();
ts4_word ts4_call_seq_fn_88617D88_888CDDC0();
ts4_word fn_888CED28();
ts4_word ts4_call_seq_fn_88617D88_888CF0D8();
ts4_word fn_888D7500();
ts4_word fn_888D8B18();
ts4_word fn_888DDBC8();
ts4_word ts4_call_seq_fn_88617D88_888DE4C8();
ts4_word ts4_call_seq_lbl_880DB358_888DF440();
ts4_word fn_888DF740();
ts4_word fn_888F1658();
ts4_word fn_88901810();
ts4_word fn_8890FF78();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word fn_88913740();
ts4_word fn_88918908();
ts4_word ts4_if_call_seq_u32_off24_88929630();
ts4_word fn_8892AF80();
ts4_word ts4_if_call_seq_u32_off14_88936980();
ts4_word fn_88936F98();
ts4_word fn_88938660();
ts4_word fn_88938740();
ts4_word ts4_call_seq_fn_88617D88_88945A10();
ts4_word fn_88951690();
ts4_word fn_88951E48();
ts4_word fn_88955100();
ts4_word ts4_call_seq_fn_88617D88_88955D78();
ts4_word fn_88956498();
ts4_word ts4_call_seq_fn_88617D88_88956CC8();
ts4_word ts4_call_seq_fn_88617D88_889585F8();
ts4_word fn_88959958();
ts4_word fn_88961050();
ts4_word fn_889659E0();
ts4_word fn_88975C98();
ts4_word ts4_call_seq_fn_88617D88_88978968();
ts4_word ts4_if_get_u32_off1c_8898EDC8();
ts4_word fn_88998B10();
ts4_word fn_88999F38();
ts4_word ts4_call_seq_fn_88617D88_889A0AE8();
ts4_word fn_889A0CA8();
ts4_word fn_889A3CF0();
ts4_word fn_889A4270();
ts4_word fn_889C53E0();
ts4_word fn_889C7180();
ts4_word fn_889C7E98();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8815BBD0: call_seq u32@0x0, u32@0x0, ts4_if_call_seq_u32_off0_88159A58, ts4_if_call_seq_u32_off0_88159A58, u8@0x1c, u8@0x1c */
ts4_word ts4_call_seq_u32_off0_8815BBD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 4), (ts4_word)(a1 + 4));
    ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 28));
    return a0;
}

/* Swing_DLL.xex 0x8815BC30: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_8815BC30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    ts4_if_call_seq_u32_off0_88159A58((ts4_word)(a0 + 28), (ts4_word)(a1 + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    return a0;
}

/* Swing_DLL.xex 0x88166A10: call_seq fn_8815ED78, u32@0x30, ts4_assign_formatted_text, u32@0x3c, ts4_assign_formatted_text, u32@0x48 */
ts4_word ts4_call_seq_fn_8815ED78_88166A10(ts4_word a0, ts4_word a1)
{
    fn_8815ED78((ts4_word)a0, (ts4_word)a1);
    ts4_assign_formatted_text((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48)));
    ts4_assign_formatted_text((ts4_word)(a0 + 60), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60)));
    ts4_assign_formatted_text((ts4_word)(a0 + 72), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 84));
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 92));
    return a0;
}

/* Swing_DLL.xex 0x8817F480: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8817F480(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 2)) << 2), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88181618: if_call_seq u32@0x0, ts4_assign_formatted_text, u16@0xc, u16@0xc, u16@0xe, u16@0xe */
ts4_word ts4_if_call_seq_u32_off0_88181618(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t2 = ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a1) + 12));
        *(unsigned short *)((char *)(ts4_word)(a0) + 14) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a1) + 14));
        p6 = (ts4_word)t2;
    }
    return p6;
}

