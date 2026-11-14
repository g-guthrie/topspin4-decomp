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

extern char fn_8893C328[];
extern char ts4_call_8893C170_8893C400[];
extern char fn_8893C410[];
extern char ts4_tailcall_fn_8893C210_8893C4F0[];
extern char fn_88AFEE40[];
extern char fn_88AFEF90[];
extern char ts4_addr_lbl_8803A308_88AFF620[];
extern char g_ts4_script_constants[];
extern char g_ts4_session_context[];
extern char lbl_88042110[];
extern char lbl_88046220[];
extern char lbl_88046B60[];
extern char lbl_8805BF00[];
extern char lbl_8805D2B0[];
extern char lbl_8805E8B4[];
extern char lbl_880C1320[];
extern char lbl_880C13BC[];
extern char lbl_880D19F0[];
extern char lbl_880D245C[];
extern char lbl_880D2AC0[];
extern char lbl_880D2B04[];
extern char lbl_880D2E18[];
extern char lbl_880D2E9C[];
extern char lbl_880D5000[];
extern char lbl_880D5118[];
extern char lbl_880D51F8[];
extern char lbl_880D5448[];
extern char lbl_880D547C[];
extern char lbl_880D54E8[];
extern char lbl_880D566C[];
extern char lbl_880D5694[];
extern char lbl_880D5A64[];
extern char lbl_880D5A78[];
extern char lbl_880D5B58[];
extern char lbl_880D5BBC[];
extern char lbl_880D5DB8[];
extern char lbl_880D5E0C[];
extern char lbl_880D5EE8[];
extern char lbl_880D6268[];
extern char lbl_880D62D8[];
extern char lbl_880D6330[];
extern char lbl_880D6968[];
extern char lbl_880D6A28[];
extern char lbl_880D6A78[];
extern char lbl_880D6B70[];
extern char lbl_880D6B74[];
extern char lbl_880D7244[];
extern char lbl_880DC6B8[];
extern char lbl_880DFA20[];
extern char lbl_880E3DAC[];
extern char lbl_880EFA5C[];
extern char lbl_88B3B730[];
extern char lbl_88B3B734[];
extern char lbl_88B3B768[];
extern char lbl_88B8F168[];
extern char lbl_88B8F46C[];
extern char lbl_88B8F658[];
extern char lbl_88B8FAC8[];
extern char lbl_88B8FDD0[];
extern char lbl_88B8FDD4[];
extern char lbl_88B9028C[];
extern char lbl_88B904C8[];
extern char lbl_88B90C70[];
extern char lbl_88B91020[];
extern char lbl_88B911A8[];
extern char lbl_88B911AC[];
extern char lbl_88B911B0[];
extern char lbl_88B933D0[];
extern char lbl_88B93478[];
extern char lbl_88B935B0[];
extern char lbl_88B935C8[];
extern char lbl_88B93670[];
extern char lbl_88B936B8[];
extern char lbl_88B93790[];
extern char lbl_88B93808[];
extern char lbl_88B93820[];
extern char lbl_88B938E0[];
extern char lbl_88B93C40[];
extern char lbl_88B93CA4[];
extern char lbl_88B94084[];
extern char lbl_88B944B0[];
extern char lbl_88B94840[];
extern char lbl_88B94938[];
extern char lbl_88B94970[];
extern char lbl_88B9498C[];
extern char lbl_88B95C5C[];
extern char lbl_88B95C78[];
extern char lbl_88B95DEC[];
extern char lbl_88B95F78[];
extern char lbl_88B96240[];
extern char lbl_88B9637C[];
extern char lbl_88B9657C[];
extern char lbl_88B96688[];
extern char lbl_88B97260[];
extern char lbl_88B97634[];
extern char lbl_88B976CC[];
extern char lbl_88B977D8[];
extern char lbl_88B97D68[];
extern char lbl_88B9AD68[];
extern char lbl_88B9ADB0[];
extern char lbl_88B9AE28[];
extern char lbl_88B9AF60[];
extern char lbl_88B9AFD8[];
extern char lbl_88B9B158[];
extern char lbl_88B9B248[];
extern char lbl_88B9B350[];
extern char lbl_88B9B470[];
extern char lbl_88B9B4A0[];
extern char lbl_88B9B560[];
extern char lbl_88B9B638[];
extern char lbl_88B9B668[];
extern char lbl_88B9B698[];
extern char lbl_88B9B6C8[];
extern char lbl_88B9B740[];
extern char lbl_88B9B788[];
extern char lbl_88B9B800[];
extern char lbl_88B9B830[];
extern char lbl_88B9B8D8[];
extern char lbl_88B9B998[];
extern char lbl_88B9BA58[];
extern char lbl_88C46F43[];
extern char lbl_88C6AEFC[];
extern char lbl_88C6B468[];
extern char lbl_88C6B484[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B804[];
extern char lbl_88C6B938[];
extern char lbl_88C6BB10[];
extern char lbl_88C6BB1C[];
extern char lbl_88C6BB28[];
extern char lbl_88C6BE98[];
extern char lbl_88C6C20C[];
extern char lbl_88C6C234[];
extern char lbl_88C6C3C0[];
extern char lbl_88C6C438[];
extern char lbl_88C6CDA4[];
extern char lbl_88C6CE08[];
extern char lbl_88C6CE78[];
extern char lbl_88C6CE94[];
extern char lbl_88C6CEA8[];
extern char lbl_88C6D120[];
extern char lbl_88C6D960[];
extern char lbl_88CDC1B4[];
extern char lbl_88CDC3F4[];
extern char lbl_88CDEBB4[];
extern char lbl_88CDF07C[];
extern char lbl_88D45884[];
extern char lbl_88D45888[];
extern char lbl_88D45894[];
extern char lbl_88D45898[];
extern char lbl_88D458C0[];
extern char lbl_88D45A10[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
extern char lbl_88D45BAC[];
extern char lbl_88D45BB8[];
extern char lbl_88D45CBC[];
extern char lbl_88D4635C[];
extern char lbl_88D46380[];
extern char lbl_88D46384[];
extern char lbl_88D463D0[];
extern char lbl_88D46800[];
extern char lbl_88D48850[];
extern char lbl_88D48860[];
extern char lbl_88D488A0[];
extern char lbl_88D488A4[];
extern char lbl_88D492F8[];
extern char lbl_88D492FC[];
extern char lbl_88D49300[];
extern char lbl_88D49308[];
extern char lbl_88D4930C[];
extern char ts4_session_field_getter_vcall8_88938CC8[];
extern char ts4_session_field_getter_vcall8_88938D28[];
ts4_word RtlInitializeCriticalSection();
ts4_word fn_88150310();
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88150600();
ts4_word fn_881506A0();
ts4_word fn_88154D40();
ts4_word fn_88157B78();
ts4_word fn_88159870();
ts4_word fn_8815B210();
ts4_word ts4_call_seq_u32_off0_8815E810();
ts4_word ts4_if_call_seq_u32_off78_8815FB60();
ts4_word ts4_if_call_seq_u32_offd4_881600E8();
ts4_word fn_88161620();
ts4_word fn_88164AE8();
ts4_word fn_88164BE0();
ts4_word fn_88164F60();
ts4_word fn_8816D1A8();
ts4_word fn_8816D220();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8();
ts4_word fn_8817C5D8();
ts4_word fn_881898E8();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word fn_88287FA0();
ts4_word fn_882882A0();
ts4_word fn_8841F080();
ts4_word ts4_set_u32_offc_884CE988();
ts4_word ts4_tailcall_NetDll_recv_884F0318();
ts4_word fn_88563470();
ts4_word fn_885651F8();
ts4_word fn_8857A720();
ts4_word ts4_if_call_seq_u32_off4_8857A748();
ts4_word fn_8857A798();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860DCF8();
ts4_word ts4_handle_forward0_886107F8();
ts4_word ts4_if_call_seq_fn_881F04B8_886131F0();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8861B698();
ts4_word fn_8862EFF8();
ts4_word ts4_if_call_seq_u32_off0_8864BC08();
ts4_word fn_886F1BA8();
ts4_word fn_887EEC78();
ts4_word fn_88837880();
ts4_word ex3_inflateEnd_88873FE0();
ts4_word fn_88874270();
ts4_word ex3_inflateInit2__88875B18();
ts4_word ts4_call_seq_fn_885820B0_88885308();
ts4_word fn_888860A0();
ts4_word ts4_call_seq_fn_88617D88_888B1D08();
ts4_word ts4_if_call_seq_u32_off2c_888CB568();
ts4_word fn_888CB5F8();
ts4_word ts4_set_u8_offf0_889166A8();
ts4_word ts4_if_get_u32_off8_88916EB8();
ts4_word ts4_if_get_u32_off8_88916ED0();
ts4_word ts4_get_u32_off8_88916F10();
ts4_word fn_88918FA0();
ts4_word fn_88923380();
ts4_word fn_88923790();
ts4_word fn_88927110();
ts4_word ts4_call_seq_u32_off28_88929200();
ts4_word fn_88929290();
ts4_word ts4_if_call_seq_u32_off24_88929630();
ts4_word fn_8892F508();
ts4_word fn_889316F8();
ts4_word fn_88933198();
ts4_word fn_88933B20();
ts4_word fn_88933EF8();
ts4_word ts4_call_seq_u32_off8_889343E8();
ts4_word fn_88935088();
ts4_word fn_88935298();
ts4_word fn_88935E70();
ts4_word ts4_if_call_seq_u32_off0_889367A8();
ts4_word ts4_if_call_seq_u32_off14_88936980();
ts4_word fn_88936AF0();
ts4_word fn_88936BB0();
ts4_word fn_88937148();
ts4_word fn_889377F8();
ts4_word fn_88938E98();
ts4_word fn_88939288();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_88939738();
ts4_word fn_8893AD90();
ts4_word fn_8893AE90();
ts4_word fn_8893C6A8();
ts4_word fn_88941C68();
ts4_word fn_88947D60();
ts4_word fn_8894CDB0();
ts4_word fn_889593B0();
ts4_word fn_88960D08();
ts4_word fn_8897D628();
ts4_word fn_8897FE48();
ts4_word fn_88987938();
ts4_word fn_88987D68();
ts4_word fn_8898E9C0();
ts4_word fn_889973D8();
ts4_word fn_88999060();
ts4_word fn_88999D10();
ts4_word fn_8899AFD0();
ts4_word fn_8899FB48();
ts4_word fn_889A44C0();
ts4_word fn_889A4590();
ts4_word fn_889B7A08();
ts4_word fn_889C0AE0();
ts4_word fn_889C63A0();
ts4_word fn_889C6AE8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_create_zeroed_triplet();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_memset();
ts4_word ts4_netdb_release_owned_list();
ts4_word ts4_object_finalize();
ts4_word ts4_online_debug_end_season();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88832F70: call_seq u32@0x0, fn_881B18E0, fn_88837880, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off0_88832F70(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[10];
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[2] = (ts4_word)0;
    loc50[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(t1 + 72));
    fn_88837880((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    return a0;
}

/* Swing_DLL.xex 0x888B9410: call_seq ts4_call_seq_fn_88617D88_888B1D08, lbl_880DC6B8, u32@0x0, u32@0x3c, u32@0x40, u32@0x44 */
ts4_word ts4_call_seq_fn_888B1D08_888B9410(ts4_word a0)
{
    ts4_call_seq_fn_88617D88_888B1D08((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC6B8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CB688: if_call_seq u8@lbl_88C46F43, u32@0x34, u32@0x30, u32@0x30, ts4_if_call_seq_u32_off2c_888CB568, u8@lbl_88C46F43 */
ts4_word ts4_if_call_seq_u8_lbl_88C46F43_888CB688(ts4_word a0)
{
    unsigned char t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t5;

    t1 = *(unsigned char *)lbl_88C46F43;
    if ((ts4_word)t1 == 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) != 997) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        if ((ts4_word)t4 == 0) {
            t6 = fn_888CB5F8();
            return t6;
        }
        t5 = ts4_if_call_seq_u32_off2c_888CB568((ts4_word)a0);
        *(unsigned char *)lbl_88C46F43 = (unsigned char)1;
        return t5;
    }
    return a0;
}

/* Swing_DLL.xex 0x88915920: addr lbl_880D6B70, u32@0x0, u32@0x8, u32@0xc, u32@0x10, u32@0x18 */
void ts4_addr_lbl_880D6B70_88915920(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88916678: if_get u32@0x3c, u32@0xd0, u32@0x54 */
ts4_word ts4_if_get_u32_off3c_88916678(ts4_word a0)
{
    ts4_word t1;
    int t2;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 84);
    if ((int)t2 == (int)t3) {
        return ((1814167552) | 48250);
    }
    return ((400031744) | 37371);
}

/* Swing_DLL.xex 0x88916E80: tailcall ts4_set_u8_offf0_889166A8 */
ts4_word ts4_tailcall_fn_889166A8_88916E80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return ts4_set_u8_offf0_889166A8((ts4_word)a2);
}

/* Swing_DLL.xex 0x88916F20: tailcall ts4_get_u32_off8_88916F10 */
ts4_word ts4_tailcall_fn_88916F10_88916F20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return ts4_get_u32_off8_88916F10((ts4_word)a2);
}

/* Swing_DLL.xex 0x88916F38: tailcall ts4_if_get_u32_off8_88916EB8 */
ts4_word ts4_tailcall_fn_88916EB8_88916F38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return ts4_if_get_u32_off8_88916EB8((ts4_word)a2);
}

/* Swing_DLL.xex 0x88916F40: tailcall ts4_if_get_u32_off8_88916ED0 */
ts4_word ts4_tailcall_fn_88916ED0_88916F40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return ts4_if_get_u32_off8_88916ED0((ts4_word)a2);
}

/* Swing_DLL.xex 0x889190D0: if_get u32@0x8, u32@0x8, u32@0x4, u32@0x310, fn_88918FA0 */
ts4_word ts4_if_get_u32_off8_889190D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) <= 2) {
        return a0;
    }
    return fn_88918FA0((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 784)) + 10));
}

/* Swing_DLL.xex 0x889190F8: if_get u32@0x20, u8@0x38, u32@0x8, u32@0x8, u32@0x4, u32@0x310 */
ts4_word ts4_if_get_u32_off20_889190F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t2;
    ts4_word t3;

    (void)a1;
    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 56);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t3 + 1);
    if ((int)(t3 + 1) <= 2) {
        return a0;
    }
    return fn_88918FA0((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 784)) + 10), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x8891B7A0: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_loop_get_u32_off0_8891B7A0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv11;
    ts4_word p13;
    ts4_word p17;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t16;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    p17 = (ts4_word)t7;
    if ((ts4_word)(t7 & 0xff) != 0) {
        if ((int)t6 < 0) {
            p8 = (ts4_word)1;
            p9 = (ts4_word)(-(int)t6);
        } else {
            p8 = (ts4_word)0;
            p9 = (ts4_word)t6;
        }
        t10 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
        if ((ts4_word)(t10 & 0xff) != 0) {
            lv11 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p9 >> lv11) & 0x1));
                p13 = (ts4_word)(lv11 + 1);
                lv11 = p13;
            } while ((ts4_word)p13 < 3);
        }
        t16 = fn_88936AF0((ts4_word)a1, (ts4_word)p8);
        p17 = (ts4_word)t16;
    }
    return p17;
}

/* Swing_DLL.xex 0x88922390: loop_get u32@0x58, u32@0x54, u32@0x0, u32@0x0, u32@0x44, vcall */
ts4_word ts4_loop_get_u32_off58_88922390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 68))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            if ((ts4_word)(t7 & 0xff) != 0) {
                return 1;
            }
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88922400: loop_get u32@0x58, u32@0x54, u32@0x0, u32@0x0, u32@0x40, vcall */
ts4_word ts4_loop_get_u32_off58_88922400(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 64))))((ts4_word)t4, (ts4_word)a1);
            if ((ts4_word)(t7 & 0xff) != 0) {
                return 1;
            }
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x889225B0: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_889225B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889225D0: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_889225D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x889225F0: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_889225F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88922610: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_88922610(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88922710: if_get u8@0x0, u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_get_u8_off0_88922710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;

    if ((ts4_word)a1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 0)) != 0) {
        p4 = (ts4_word)a4;
        if ((ts4_word)a4 == 0) {
            p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548));
        }
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p4) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)p4, (ts4_word)a1, (ts4_word)1, (ts4_word)0);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t9 = loc50[0];
        t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 60))))((ts4_word)a0, (ts4_word)t9, (ts4_word)a2, (ts4_word)a3, (ts4_word)a5, (ts4_word)a6);
        t12 = loc50[0];
        if ((ts4_word)t12 != 0) {
            t13 = *(ts4_word *)((char *)(ts4_word)(t12) + 4);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 88))))((ts4_word)t13, (ts4_word)(ts4_word)&loc50[0]);
        }
        return t11;
    }
    return 0;
}

/* Swing_DLL.xex 0x88922BB8: get u32@0xc, u32@0x10, u32@0x14, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_offc_88922BB8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88922CB8: set u32@0xc, u32@0x14, u32@0x10, u8@0x18, u32@0x8 */
void ts4_set_u32_offc_88922CB8(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((983040) | 65535);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x889230E8: if_get u32@0x4, u32@0x0, u8@0xd, u32@0x0, u8@0x7 */
void ts4_if_get_u32_off4_889230E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == (ts4_word)((4244045824) | 15907)) {
        *(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0)) + 7) = (unsigned char)0;
        return;
    }
    if ((((ts4_word)t1 != (ts4_word)((1431896064) | 54742) && (ts4_word)t1 != (ts4_word)((3377594368) | 59504)) && (ts4_word)t1 != (ts4_word)((1736835072) | 2568)) && (ts4_word)t1 != (ts4_word)((1593442304) | 65465)) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0)) + 13) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88923168: if_get u32@0x4, u32@0x0, u8@0xc, u32@0x0, u8@0x6 */
void ts4_if_get_u32_off4_88923168(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == (ts4_word)((4244045824) | 15907)) {
        *(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0)) + 6) = (unsigned char)1;
        return;
    }
    if ((((ts4_word)t1 != (ts4_word)((1431896064) | 54742) && (ts4_word)t1 != (ts4_word)((3377594368) | 59504)) && (ts4_word)t1 != (ts4_word)((1736835072) | 2568)) && (ts4_word)t1 != (ts4_word)((1593442304) | 65465)) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0)) + 12) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88923330: if_get u32@0x8, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x0 */
void ts4_if_get_u32_off8_88923330(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    if ((ts4_word)a2 >= (ts4_word)t1) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4))) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(((a2 << 4) + t3)) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(((a2 << 4) + t3)) + 8);
    t6 = *(ts4_word *)((char *)(ts4_word)(((a2 << 4) + t3)) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t6;
    return;
}

/* Swing_DLL.xex 0x88923810: if_get u32@0x34, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x30, u32@0x20 */
ts4_word ts4_if_get_u32_off34_88923810(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 52);
    if ((ts4_word)t1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
        loc50[0] = (ts4_word)t4;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)a0, (ts4_word)t1, (ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return a0;
}

/* Swing_DLL.xex 0x88923918: if_get u32@0x0, u32@0x14, vcall, u32@0x28, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_88923918(ts4_word a0, ts4_word a1)
{
    ts4_word p12;
    ts4_word loc50[8];
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 20))))((ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p12 = (ts4_word)t3;
    if ((ts4_word)t4 == (ts4_word)(t3 + -20)) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)20);
        t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 4))))((ts4_word)a1, (ts4_word)t9, (ts4_word)(t3 + -20));
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x88924578: addr lbl_880D62D8, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D62D8_88924578(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D62D8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88924778: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x8c, vcall */
ts4_word ts4_get_u32_off0_88924778(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 140))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x889247E8: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x88, vcall */
ts4_word ts4_get_u32_off0_889247E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 136))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88924858: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_get_u32_off0_88924858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 76))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x889249B0: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x3c, vcall */
ts4_word ts4_get_u32_off0_889249B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 60))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88924A20: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x38, vcall */
ts4_word ts4_get_u32_off0_88924A20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 56))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88924BC0: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x18, vcall */
ts4_word ts4_get_u32_off0_88924BC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 24))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x88924D40: get u32@0x0, u32@0xc8, vcall, u32@0x0, u32@0x40, vcall */
ts4_word ts4_get_u32_off0_88924D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;
    ts4_word t7;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 200))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t4 = loc50[0];
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 64))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    return t7;
}

/* Swing_DLL.xex 0x889271D8: if_get u32@0xc, u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall */
ts4_word ts4_if_get_u32_offc_889271D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        t3 = fn_8816D220((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)((1193148416) | 37738));
        if ((ts4_word)t3 == 0) {
            p8 = (ts4_word)0;
        } else {
            t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3);
            p8 = (ts4_word)t6;
        }
        t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 60))))((ts4_word)p8, (ts4_word)a2, (ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        if ((ts4_word)(t11 & 0xff) == 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 20))))((ts4_word)p8);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 0))))((ts4_word)p8, (ts4_word)1);
            return 0;
        }
        fn_88927110((ts4_word)a0, (ts4_word)p8);
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x88929040: if_get u32@0xc, u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall */
ts4_word ts4_if_get_u32_offc_88929040(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t16;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        t3 = fn_8816D220((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)((1193148416) | 37738));
        if ((ts4_word)t3 == 0) {
            p8 = (ts4_word)0;
        } else {
            t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3);
            p8 = (ts4_word)t6;
        }
        t9 = fn_88923790((ts4_word)p8, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        if ((ts4_word)(t9 & 0xff) != 0) {
            t16 = fn_88927110((ts4_word)a0, (ts4_word)p8);
            if ((ts4_word)(t16 & 0xff) != 0) {
                return 1;
            }
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 20))))((ts4_word)p8);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 0))))((ts4_word)p8, (ts4_word)1);
            return 0;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 20))))((ts4_word)p8);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p8) + 0))) + 0))))((ts4_word)p8, (ts4_word)1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88929420: call_seq lbl_880D6330, u32@0x0, u32@0x4, u32@0x8, u32@0xc, ts4_create_zeroed_triplet */
ts4_word ts4_call_seq_lbl_880D6330_88929420(ts4_word a0)
{
    ts4_word t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6330;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t1 = ts4_create_zeroed_triplet();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x88929838: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D62D8, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88929838(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D62D8;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)p3;
    *(volatile ts4_word *)((char *)(ts4_word)(p3) + 4) = (ts4_word)t4;
    t5 = fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88929A60: call_seq lbl_880D6330, u32@0x0, u32@0x4, u32@0x8, u32@0xc, ts4_create_zeroed_triplet */
ts4_word ts4_call_seq_lbl_880D6330_88929A60(ts4_word a0)
{
    ts4_word t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6330;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t1 = ts4_create_zeroed_triplet();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6968;
    return a0;
}

/* Swing_DLL.xex 0x88929E58: if_get u32@0xc, ts4_call_seq_u32_off28_88929200 */
ts4_word ts4_if_get_u32_offc_88929E58(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        return ts4_call_seq_u32_off28_88929200((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x8892A060: if_call_seq lbl_880D6A28, u32@0x0, u32@0x74, ts4_destroy_owned_object, u32@0x60, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D6A28_8892A060(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6A28;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6A78;
    ts4_object_finalize((ts4_word)(a0 + 84));
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = ts4_if_call_seq_u32_off24_88929630((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x8892AF80: loop_call_seq lbl_880D6268, u32@0x0, u32@0x40, u32@0x3c, fn_88929290, u32@0x3c */
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6268;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            fn_88929290((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 16);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B74;
    t11 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x8892AFF0: call_seq fn_88617D88, lbl_880D6268, u32@0x0, u32@0x3c, u32@0x40, u32@0x44 */
ts4_word ts4_call_seq_fn_88617D88_8892AFF0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6268;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8892FC88: if_call_seq fn_8892F508, u32@0x0, u32@0x8, u32@0x4, u32@0x14, fn_88923380 */
ts4_word ts4_if_call_seq_fn_8892F508_8892FC88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8892F508((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t3 = fn_88923380((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
        t4 = ts4_handle_forward0_886107F8((ts4_word)(ts4_word)&loc60[0], (ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
        *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
        p10 = (ts4_word)t4;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)((983040) | 65535);
        p10 = (ts4_word)t1;
    }
    return p10;
}

/* Swing_DLL.xex 0x8892FDA0: if_call_seq fn_8892F508, u32@lbl_88D45B1C, u32@0x27c, u32@0x0, u32@0x14, fn_88923380 */
ts4_word ts4_if_call_seq_fn_8892F508_8892FDA0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t5;

    t1 = fn_8892F508((ts4_word)a1, (ts4_word)a2);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t5 = fn_88923380((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20)));
        fn_881506A0((ts4_word)a0, (ts4_word)t5);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    }
    return a0;
}

/* Swing_DLL.xex 0x8892FE20: if_get u32@0x0, u32@0x68, vcall, u32@0x0, u32@0x54, vcall */
ts4_word ts4_if_get_u32_off0_8892FE20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t3;
    ts4_word t12;

    if ((ts4_word)a1 != 0) {
        t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
        if ((ts4_word)(t3 & 0xff) != 0) {
            if ((ts4_word)a2 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
            }
            if ((ts4_word)(a4 & 0xff) != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 92))))((ts4_word)a0, (ts4_word)a5);
            }
            t12 = *(ts4_word *)lbl_88D45A10;
            if ((ts4_word)t12 != 0) {
                fn_887EEC78((ts4_word)t12, (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636)));
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88930EB0: if_get u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_88930EB0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1);
}

/* Swing_DLL.xex 0x889312A8: loop_get u32@0x1c, u32@0x18, u32@0x0, u32@0x18, u32@0x0, u32@0xc */
ts4_word ts4_loop_get_u32_off1c_889312A8(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 24);
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)a1);
            if ((ts4_word)(t8 & 0xff) != 0) {
                return t4;
            }
            p9 = (ts4_word)(lv3 + 4);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x889317B0: if_get u32@0xc, u32@0xc */
void ts4_if_get_u32_offc_889317B0(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88931950: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x14, vcall */
ts4_word ts4_loop_get_u32_off8_88931950(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

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
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 20))))((ts4_word)t4, (ts4_word)a1);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x889319A0: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x10, vcall */
ts4_word ts4_loop_get_u32_off8_889319A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

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
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4, (ts4_word)a1);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88931A88: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_loop_get_u32_off8_88931A88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p11 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
        p9 = (ts4_word)a0;
        if ((ts4_word)t2 != (ts4_word)t1) {
            lv3 = (ts4_word)t2;
            do {
                t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
                t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 4))))((ts4_word)t4, (ts4_word)a1);
                p8 = (ts4_word)(lv3 + 4);
                lv3 = p8;
            } while ((ts4_word)p8 != (ts4_word)t1);
            p9 = (ts4_word)t7;
        }
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x889321F8: if_get u32@0x1c, u32@0x0, u32@0x28, vcall, u32@0x1c, u32@0x4 */
ts4_word ts4_if_get_u32_off1c_889321F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p12;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p12 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t4;
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        p11 = (ts4_word)t4;
        if ((ts4_word)t5 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 630)) != 0) {
            t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 4))))((ts4_word)t4, (ts4_word)a1);
            p11 = (ts4_word)t10;
        }
        p12 = (ts4_word)p11;
    }
    return p12;
}

/* Swing_DLL.xex 0x88932300: set u32@0x0, u32@0x4, u32@0x8, u16@0xc, u8@0xe, u32@0x414 */
void ts4_set_u32_off0_88932300(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1044) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 1044)) + 1);
    return;
}

/* Swing_DLL.xex 0x88932A40: if_get u32@0x14, u8@0x26, u8@0x26, u32@0x0, u32@0x14 */
ts4_word ts4_if_get_u32_off14_88932A40(ts4_word a0, ts4_word a1)
{
    int t1;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 == 2) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 38);
        if ((ts4_word)t3 == 0) {
            return 1;
        }
        if ((ts4_word)(a1 & 0xff) != 0) {
            return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88932B90: loop_get u32@0x14, u32@0x10, u32@0x0, u8@0x48 */
void ts4_loop_get_u32_off14_88932B90(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return;
    }
    lv3 = (ts4_word)t2;
    do {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 72) = (unsigned char)1;
        p5 = (ts4_word)(lv3 + 4);
        lv3 = p5;
    } while ((ts4_word)p5 != (ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88932CC0: if_get u32@0x4, u32@0x0, ts4_tailcall_NetDll_recv_884F0318, u32@0x0, u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32_off4_88932CC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p8;
    ts4_word t1;
    int t3;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = ts4_tailcall_NetDll_recv_884F0318((ts4_word)t1, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)), (ts4_word)0);
    if ((int)t3 < 0) {
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
        p8 = (ts4_word)t7;
    } else {
        if ((int)t3 == 0) {
            p4 = (ts4_word)4;
        } else {
            *(volatile ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
            p4 = (ts4_word)0;
        }
        p8 = (ts4_word)p4;
    }
    return p8;
}

/* Swing_DLL.xex 0x88932F88: loop_get u32@0x18, u32@0x1c, u32@0x0, u8@0x2c, u32@0x0, u32@0x40 */
ts4_word ts4_loop_get_u32_off18_88932F88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p10 = (ts4_word)t1;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            *(unsigned char *)((char *)(ts4_word)(t4) + 44) = (unsigned char)0;
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0, (ts4_word)t4);
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            p9 = (ts4_word)t7;
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t8);
        p10 = (ts4_word)lv3;
    }
    return p10;
}

/* Swing_DLL.xex 0x88933380: if_get u32@0x14, u8@0x18, u32@0x20, u32@0x14 */
ts4_word ts4_if_get_u32_off14_88933380(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    if ((int)t1 == -1 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 24)) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    }
    return 1;
}

/* Swing_DLL.xex 0x889337A8: get u32@0x4, lbl_880D5BBC, u32@0x0, fn_888860A0 */
ts4_word ts4_get_u32_off4_889337A8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5BBC;
    return fn_888860A0((ts4_word)t1);
}

/* Swing_DLL.xex 0x88933FA0: get u32@0x8, u32@0x8 */
void ts4_get_u32_off8_88933FA0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 7) & 0xfffffff8);
    return;
}

/* Swing_DLL.xex 0x88933FB8: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_88933FB8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 7) & 0xfffffff8);
    return;
}

/* Swing_DLL.xex 0x88933FE8: addr lbl_880D5A64, u32@0x0, u32@0x4, u32@0x8, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880D5A64_88933FE8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88934328: loop_get u32@0x44, u32@0x48, u32@0x0, u32@0x1c, u32@0x0, u32@0xc */
ts4_word ts4_loop_get_u32_off44_88934328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 28);
            p9 = (ts4_word)t4;
            if ((ts4_word)a1 == (ts4_word)t5) {
                t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 12))))((ts4_word)t4);
                p9 = (ts4_word)t8;
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t2);
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x88934458: if_call_seq lbl_880D5B58, u32@0x0, ts4_call_seq_u32_off8_889343E8, u32@0x10, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_lbl_880D5B58_88934458(ts4_word a0)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5B58;
    t1 = ts4_call_seq_u32_off8_889343E8();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p9 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
            p8 = (ts4_word)t7;
        } else {
            t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
            p8 = (ts4_word)t5;
        }
        p9 = (ts4_word)p8;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return p9;
}

/* Swing_DLL.xex 0x88935278: if_get u32@lbl_88D45B1C, u8@0x276, fn_88935088 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_88935278(ts4_word a0)
{
    unsigned char t2;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 630);
    if ((ts4_word)t2 != 0) {
        return a0;
    }
    return fn_88935088((ts4_word)a0);
}

/* Swing_DLL.xex 0x88935C70: loop_get fn_88935298, u32@lbl_88D45B1C, u8@0x276, fn_88935088, u32@0x1c, u32@0x0 */
ts4_word ts4_loop_get_fn_88935298_88935C70(ts4_word a0)
{
    ts4_word p10;
    ts4_word lv13;
    ts4_word p18;
    ts4_word p19;
    unsigned char t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t17;

    fn_88935298();
    t3 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 630);
    if ((ts4_word)t3 == 0) {
        fn_88935088((ts4_word)a0);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p10 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 12))))((ts4_word)t6);
        p10 = (ts4_word)t9;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p19 = (ts4_word)p10;
    if ((ts4_word)t12 != (ts4_word)t11) {
        lv13 = (ts4_word)t12;
        do {
            t14 = *(ts4_word *)((char *)(ts4_word)(lv13) + 0);
            t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 8))))((ts4_word)t14);
            p18 = (ts4_word)(lv13 + 4);
            lv13 = p18;
        } while ((ts4_word)p18 != (ts4_word)t11);
        p19 = (ts4_word)t17;
    }
    return p19;
}

/* Swing_DLL.xex 0x889366E0: if_call_seq u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4, u32@0x50, u32@0x54 */
ts4_word ts4_if_call_seq_u32_g_ts4_session_context_889366E0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;
    ts4_word t16;
    ts4_word t14;

    t1 = *(ts4_word *)g_ts4_session_context;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 5) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 80) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 84) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 88) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 92) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 6) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 96) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 100) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 104) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 108) = (ts4_word)0;
    }
    t10 = fn_889316F8((ts4_word)a0);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t11 != 0) {
        t13 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t13 != 0) {
            t16 = ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t13, (ts4_word)t11, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t16;
        }
        t14 = fn_885651F8((ts4_word)t11, (ts4_word)t11);
        return t14;
    }
    return t10;
}

/* Swing_DLL.xex 0x88936888: if_get u32@0x10, u32@lbl_88D45B38, fn_88613268, fn_8860DCF8 */
ts4_word ts4_if_get_u32_off10_88936888(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        return fn_8860DCF8((ts4_word)t1, (ts4_word)a1, (ts4_word)1, (ts4_word)2);
    }
    return fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)a1, (ts4_word)1, (ts4_word)0, (ts4_word)2);
}

/* Swing_DLL.xex 0x889368B8: if_call_seq u32@0x18, u32@0x10, u32@lbl_88D45B38, fn_88613268, fn_8860DCF8, u32@0xc */
ts4_word ts4_if_call_seq_u32_off18_889368B8(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t5;
    int t12;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)a1 > (ts4_word)t1) {
        p2 = (ts4_word)((((t1 + 1)) >> 1) + t1);
        if ((ts4_word)a1 > (ts4_word)((((t1 + 1)) >> 1) + t1)) {
            p2 = (ts4_word)a1;
        }
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t3 != 0) {
            t6 = fn_8860DCF8((ts4_word)t3, (ts4_word)p2, (ts4_word)1, (ts4_word)2);
            p7 = (ts4_word)t6;
        } else {
            t5 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)p2, (ts4_word)1, (ts4_word)0, (ts4_word)2);
            p7 = (ts4_word)t5;
        }
        if ((ts4_word)p7 == 0) {
            t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
            if ((int)t12 == 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
            }
            return 0;
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        memcpy((ts4_word)p7, (ts4_word)t9, (ts4_word)t1);
        fn_888860A0((ts4_word)t9);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)p7;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)p2;
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x889369D8: if_call_seq lbl_880D5A78, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_lbl_880D5A78_889369D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    ts4_word p6;
    ts4_word t5;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A78;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    if ((ts4_word)a1 != 0) {
        p2 = (ts4_word)a1;
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)3;
        p2 = (ts4_word)16;
    }
    if ((ts4_word)a2 != 0) {
        t5 = fn_8860DCF8((ts4_word)a2, (ts4_word)p2, (ts4_word)1, (ts4_word)2);
        p6 = (ts4_word)t5;
    } else {
        t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)p2, (ts4_word)1, (ts4_word)0, (ts4_word)2);
        p6 = (ts4_word)t4;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)p6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)p2;
    return a0;
}

/* Swing_DLL.xex 0x88937388: addr lbl_88C6B484, fn_88937148, u32@0x0, fn_88608590, lbl_88C6B468, fn_88164F60 */
ts4_word ts4_addr_lbl_88C6B484_88937388(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    (void)a0;
    fn_88937148((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88C6B484);
    t3 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88164F60((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88C6B468, (ts4_word)0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)t4, (ts4_word)t6, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)t3;
    return t9;
}

/* Swing_DLL.xex 0x88937B60: if_get u32@0x1c, fn_88933B20 */
ts4_word ts4_if_get_u32_off1c_88937B60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 28);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_88933B20((ts4_word)t1, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88938D88: addr lbl_880D5EE8, u32@0x0, ts4_if_call_seq_u32_off14_88936980 */
ts4_word ts4_addr_lbl_880D5EE8_88938D88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5EE8;
    return ts4_if_call_seq_u32_off14_88936980((ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x889396A8: if_call_seq fn_88933EF8, fn_88938E98, fn_88938E98, fn_88938E98, fn_88938E98 */
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88933EF8((ts4_word)a0, (ts4_word)32);
    if ((ts4_word)(t1 & 0xff) != 0) {
        fn_88938E98((ts4_word)a0, (ts4_word)((a1) >> 24));
        fn_88938E98((ts4_word)a0, (ts4_word)((a1 >> 16) & 0xff));
        fn_88938E98((ts4_word)a0, (ts4_word)((a1 >> 8) & 0xff));
        fn_88938E98((ts4_word)a0, (ts4_word)(a1 & 0xff));
    }
    return a0;
}

/* Swing_DLL.xex 0x889397D8: if_call_seq fn_88933EF8, fn_88938E98, fn_88938E98 */
ts4_word ts4_if_call_seq_fn_88933EF8_889397D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88933EF8((ts4_word)a0, (ts4_word)16);
    if ((ts4_word)(t1 & 0xff) != 0) {
        fn_88938E98((ts4_word)a0, (ts4_word)((a1 >> 8) & 0xff));
        fn_88938E98((ts4_word)a0, (ts4_word)(a1 & 0xff));
    }
    return a0;
}

/* Swing_DLL.xex 0x88939F58: if_get u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4, u32@0x270, u32@0x274 */
ts4_word ts4_if_get_u32_g_ts4_session_context_88939F58(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t12;

    t1 = *(ts4_word *)g_ts4_session_context;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 39) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(ts4_word *)((char *)(ts4_word)(t4) + 624) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 628) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 632) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 636) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 40) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(ts4_word *)((char *)(ts4_word)(t8) + 640) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 644) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 648) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 652) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t10 == 0) {
        return a0;
    }
    t12 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t12 != 0) {
        return ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t12, (ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    }
    return fn_885651F8((ts4_word)t10, (ts4_word)t10);
}

/* Swing_DLL.xex 0x8893B328: loop_get u32@0x8, u32@0x4, u32@0x14, u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_loop_get_u32_off8_8893B328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word p20;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t11;
    ts4_word t18;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
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
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p20 = (ts4_word)p9;
    if ((ts4_word)t11 != 0) {
        fn_88935E70((ts4_word)t11);
        fn_88935E70((ts4_word)(t11 + 8));
        fn_88935E70((ts4_word)(t11 + 16));
        fn_88157B78((ts4_word)(t11 + 16));
        fn_88157B78((ts4_word)(t11 + 8));
        fn_88157B78((ts4_word)t11);
        t18 = ts4_tsu_cleanup_end((ts4_word)t11);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)0;
        p20 = (ts4_word)t18;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return p20;
}

/* Swing_DLL.xex 0x8893B4E0: call_seq fn_88939738, u32@0xc, u32@0xc */
ts4_word ts4_call_seq_fn_88939738_8893B4E0(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88939738((ts4_word)(a0 + 4), (ts4_word)(a0 + 1220));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + 7) & 0xfffffff8);
    return t1;
}

/* Swing_DLL.xex 0x8893C508: if_call_seq ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8, u32@0x0, u32@0x4, u32@0x8, ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8, u32@0xc */
ts4_word ts4_if_call_seq_fn_8816DFB8_8893C508(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    loc50[0] = (ts4_word)0;
    ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8((ts4_word)(ts4_word)&loc50[0]);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8((ts4_word)(a0 + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t3 = *(ts4_word *)g_ts4_session_context;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 64);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
    if ((ts4_word)t5 > 5) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 80) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_88938D28;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 84) = (ts4_word)(ts4_word)ts4_tailcall_fn_8893C210_8893C4F0;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 88) = (ts4_word)(ts4_word)fn_8893C410;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 92) = (ts4_word)a0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(t3) + 64);
    t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 8);
    if ((ts4_word)t9 > 6) {
        t10 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t10) + 96) = (ts4_word)(ts4_word)ts4_session_field_getter_vcall8_88938CC8;
        *(volatile ts4_word *)((char *)(ts4_word)(t10) + 100) = (ts4_word)(ts4_word)ts4_call_8893C170_8893C400;
        *(volatile ts4_word *)((char *)(ts4_word)(t10) + 104) = (ts4_word)(ts4_word)fn_8893C328;
        *(volatile ts4_word *)((char *)(ts4_word)(t10) + 108) = (ts4_word)a0;
    }
    return a0;
}

/* Swing_DLL.xex 0x8893C5E8: if_call_seq fn_88939288, fn_88939288, fn_88936BB0, u8@0x0, u8@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88939288_8893C5E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[1];
    unsigned char t4;
    unsigned char t7;
    ts4_word t11;
    ts4_word t12;

    fn_88939288((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)11);
    fn_88939288((ts4_word)a0, (ts4_word)a1, (ts4_word)2);
    fn_88936BB0((ts4_word)a0, (ts4_word)a2);
    t4 = *(unsigned char *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t4 == 0) {
        fn_88936BB0((ts4_word)a0, (ts4_word)a3);
        fn_889395D8((ts4_word)a0, (ts4_word)a4);
        t7 = *(unsigned char *)((char *)(ts4_word)(a3) + 0);
        if ((ts4_word)t7 == 0) {
            fn_889395D8((ts4_word)a0, (ts4_word)a5);
        } else {
            *(volatile ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)0;
        }
    } else {
        *(volatile unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t12 = loc50[0];
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((t11 + 7) & 0xfffffff8);
    return t12;
}

/* Swing_DLL.xex 0x8893D6B0: if_call_seq ts4_if_call_seq_u32_off0_889367A8, u32@0x8, fn_8893C6A8, u32@0x8, u32@0x8, u16@0x4c4 */
ts4_word ts4_if_call_seq_fn_889367A8_8893D6B0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_if_call_seq_u32_off0_889367A8((ts4_word)a1);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)((((t2 + 7)) >> 3) + t1) > 1200) {
        p8 = (ts4_word)0;
    } else {
        fn_8893C6A8((ts4_word)a1, (ts4_word)(a0 + 4));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)) + 7) & 0xfffffff8);
        *(volatile unsigned short *)((char *)(ts4_word)(a1) + 12) = (unsigned short)(*(volatile unsigned short *)((char *)(ts4_word)(a0) + 1220));
        p8 = (ts4_word)1;
    }
    return p8;
}

/* Swing_DLL.xex 0x8893E198: if_call_seq lbl_880D5DB8, u32@0x0, u32@0x50, ts4_destroy_owned_object, u32@0x44, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D5DB8_8893E198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5DB8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    t11 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x8893E248: addr lbl_880D5E0C, u32@0x0, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_addr_lbl_880D5E0C_8893E248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5E0C;
    return ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D5E0C);
}

/* Swing_DLL.xex 0x88941860: if_set u32@0x218, u32@0x0, u32@lbl_88D458C0, u32@0x218, u32@0x0, u8@0x21c */
void ts4_if_set_u32_off218_88941860(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)lbl_88D458C0;
    if ((ts4_word)t1 == (ts4_word)((4122935296) | 20375)) {
        p3 = (ts4_word)(t2 + 300);
    } else {
        p3 = (ts4_word)(t2 + 500);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)p3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t4 != (ts4_word)((2801139712) | 59735) && (ts4_word)t4 != (ts4_word)((465633280) | 29333)) {
        if (((ts4_word)t4 != (ts4_word)((499777536) | 29317) && (ts4_word)t4 != (ts4_word)((4150788096) | 12377)) && (ts4_word)t4 != (ts4_word)((145817600) | 51551)) {
            return;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 540) = (unsigned char)0;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 540) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x889419A0: if_get u32@0x8, u8@0x1c, u8@0x1c, u32@0x0, u32@0x54, vcall */
ts4_word ts4_if_get_u32_off8_889419A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    unsigned char t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0) {
        if ((int)t1 == 2 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 44)) != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
        }
    } else {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0);
        }
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88942480: if_get u32@lbl_88D458C0, u32@0x28, u32@0x0, u32@0x2c, u32@0x0, u8@0x1d */
void ts4_if_get_u32_lbl_88D458C0_88942480(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)lbl_88D458C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t2 == (ts4_word)((4122935296) | 20375)) {
        p3 = (ts4_word)(t1 + 240);
    } else {
        p3 = (ts4_word)(t1 + 440);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)p3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t4 != (ts4_word)((2801139712) | 59735) && (ts4_word)t4 != (ts4_word)((465633280) | 29333)) {
        if (((ts4_word)t4 != (ts4_word)((499777536) | 29317) && (ts4_word)t4 != (ts4_word)((4150788096) | 12377)) && (ts4_word)t4 != (ts4_word)((145817600) | 51551)) {
            return;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88942C10: loop_get u32@lbl_88D45888, u32@0x5c, u32@0x28, u32@0x0, u32@0x5c, u32@0x28 */
ts4_word ts4_loop_get_u32_lbl_88D45888_88942C10(void)
{
    ts4_word lv8;
    ts4_word lv9;
    ts4_word p11;
    ts4_word p12;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88D45888;
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 92))) + 40);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
    if ((ts4_word)t7 == (ts4_word)t6) {
        return 0;
    }
    lv8 = (ts4_word)t7;
    lv9 = (ts4_word)0;
    do {
        p11 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 0));
        p12 = (ts4_word)(lv9 + 1);
        lv8 = p11;
        lv9 = p12;
    } while ((ts4_word)p11 != (ts4_word)t6);
    return lv9;
}

/* Swing_DLL.xex 0x889441E8: if_get u32@0x24, u32@0xc, fn_88941C68 */
ts4_word ts4_if_get_u32_off24_889441E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        return fn_88941C68((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12)));
    }
    return 0;
}

/* Swing_DLL.xex 0x88951608: if_call_seq lbl_880D54E8, u32@0x0, u32@0x44, ts4_destroy_owned_object, u32@0x38, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D54E8_88951608(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D54E8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = fn_8860BBD8((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x88951690: call_seq u32@0x4, u32@0x10, lbl_880D54E8, u32@0x14, u32@0x18, u32@0x1c */
ts4_word ts4_call_seq_u32_off4_88951690(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D54E8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    ts4_object_finalize((ts4_word)(a0 + 44));
    fn_88161620((ts4_word)(a0 + 56));
    fn_88161620((ts4_word)(a0 + 68));
    return a0;
}

/* Swing_DLL.xex 0x889519B0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_889519B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88951B10: if_call_seq lbl_880D547C, u32@0x0, u32@0xc4, ts4_destroy_owned_object, u32@0xb8, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D547C_88951B10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D547C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 196);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 184);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 160);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 148);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t16 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    t19 = fn_8860BBD8((ts4_word)a0);
    return t19;
}

/* Swing_DLL.xex 0x88951DC0: if_call_seq lbl_880D5448, u32@0x0, u32@0x70, ts4_destroy_owned_object, u32@0x64, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D5448_88951DC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5448;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = fn_8860BBD8((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x88952898: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_88952898(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88952E90: if_call_seq u32@0x0, u32@0x8, u32@0x4, u32@0x8, fn_8894CDB0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88952E90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    if ((ts4_word)(a3 & 0xff) != 0 || (int)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 8)) == 1) {
        t2 = fn_8894CDB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 140), (ts4_word)(a1 + 152), (ts4_word)a2);
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0);
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    }
    return a0;
}

/* Swing_DLL.xex 0x889550B0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_889550B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88955188: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_88955188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88955368: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_88955368(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88955538: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_88955538(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x889555F0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_889555F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x889556A8: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_889556A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88955760: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_88955760(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88955818: if_call_seq lbl_880D51F8, u32@0x0, u32@0x48, ts4_destroy_owned_object, lbl_880E3DAC, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D51F8_88955818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D51F8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = fn_8860BBD8((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88956498: call_seq fn_88617D88, lbl_880D5694, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88956498(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5694;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 40));
    *(volatile ts4_word *)lbl_88D45894 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x8895E298: loop_call_seq u32@0xe8, u8@0x178, u32@0x184, u32@0x188, u32@0x184, u32@0x188 */
ts4_word ts4_loop_call_seq_u32_offe8_8895E298(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv7;
    ts4_word p12;
    ts4_word p16;
    int t1;
    ts4_word t5;
    ts4_word t6;
    unsigned char t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    if ((int)t1 == 5 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 376)) != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
        if ((ts4_word)t5 != (ts4_word)t6) {
            lv7 = (ts4_word)t5;
            do {
                t8 = *(unsigned char *)((char *)(ts4_word)(lv7) + 48);
                if ((ts4_word)t8 == 0) {
                    fn_889593B0((ts4_word)lv7);
                }
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
                p12 = (ts4_word)(lv7 + 132);
                lv7 = p12;
            } while ((ts4_word)p12 != (ts4_word)t11);
        }
        p16 = (ts4_word)1;
    } else {
        p16 = (ts4_word)0;
    }
    return p16;
}

/* Swing_DLL.xex 0x889666A8: call_seq fn_88617D88, lbl_880D5000, u32@0x0, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_889666A8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5000;
    fn_8816D1A8((ts4_word)(a0 + 28));
    fn_8816D1A8((ts4_word)(a0 + 40));
    fn_8816D1A8((ts4_word)(a0 + 52));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45884 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88966E10: if_call_seq u32@0x8, u32@0x10, u32@0xc, u32@lbl_88D45AD4, u32@0x24, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off8_88966E10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t15;
    ts4_word t17;
    ts4_word t8;
    ts4_word t10;

    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t7 = *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 36))) + 32)) + (t1 << 4))) + 8);
    if ((int)t2 == 4) {
        t15 = *(ts4_word *)((char *)(ts4_word)(t7) + 24);
        t17 = fn_88287FA0((ts4_word)t7, (ts4_word)12, (ts4_word)0, (ts4_word)t15, (ts4_word)0, (ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 28)), (ts4_word)18, (ts4_word)0);
        fn_88164AE8((ts4_word)(a0 + 112), (ts4_word)t17, (ts4_word)t3);
        fn_882882A0((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 24)), (ts4_word)0);
    } else {
        if ((int)t2 == 6) {
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 24);
            t10 = fn_88287FA0((ts4_word)t7, (ts4_word)12, (ts4_word)0, (ts4_word)t8, (ts4_word)0, (ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 28)), (ts4_word)18, (ts4_word)0);
            fn_88164BE0((ts4_word)(a0 + 112), (ts4_word)t10, (ts4_word)t3);
            fn_882882A0((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 24)), (ts4_word)0);
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x8896BD28: call_seq fn_88617D88, lbl_880D5118, u32@0x0, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_8896BD28(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t8;
    ts4_word t12;
    ts4_word t16;

    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5118;
    fn_8816D1A8((ts4_word)(a0 + 44));
    fn_8816D1A8((ts4_word)(a0 + 56));
    fn_8816D1A8((ts4_word)(a0 + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)lbl_88D45898 = (ts4_word)a0;
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 44), (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t8);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 56), (ts4_word)(ts4_word)&loc50[0]);
    t12 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t12);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 68), (ts4_word)(ts4_word)&loc50[0]);
    t16 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x889736E8: if_call_seq fn_88960D08, u8@0x35, u32@lbl_88D45B1C, u32@0x270, fn_8817C5D8 */
ts4_word ts4_if_call_seq_fn_88960D08_889736E8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    unsigned char t2;
    ts4_word t5;

    t1 = fn_88960D08();
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 53);
    p6 = (ts4_word)t1;
    if ((ts4_word)t2 == 1 && (int)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 624)) & 0x1) != 0) {
        t5 = fn_8817C5D8((ts4_word)1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8897E958: if_call_seq fn_88947D60, u32@lbl_88D45B38, fn_88613268, fn_8816D1A8, u32@0x10, u32@0x28 */
ts4_word ts4_if_call_seq_fn_88947D60_8897E958(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word p16;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t15;

    t1 = fn_88947D60();
    p16 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t3 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)4, (ts4_word)0, (ts4_word)2);
        if ((ts4_word)t3 != 0) {
            fn_8816D1A8((ts4_word)(t3 + 4));
            *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 40) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 44) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 48) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 52) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 56) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t3) + 60) = (ts4_word)0;
            ts4_call_seq_u32_off0_8815E810((ts4_word)t3);
            *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
            *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
            *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
            *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
            *(ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
            fn_88150600((ts4_word)(t3 + 4), (ts4_word)(a1 + 4));
            p13 = (ts4_word)t3;
        } else {
            p13 = (ts4_word)0;
        }
        loc50[0] = (ts4_word)p13;
        fn_881898E8((ts4_word)(a0 + 132), (ts4_word)(ts4_word)&loc50[0]);
        t15 = loc50[0];
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Swing_DLL.xex 0x8897FFE0: if_get u32@0x50, u32@0xc, u32@0xc, lbl_880C1320, fn_8897FE48 */
ts4_word ts4_if_get_u32_off50_8897FFE0(ts4_word a0)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((int)t3 == -1) {
        return a0;
    }
    return fn_8897FE48((ts4_word)a0, (ts4_word)t3, (ts4_word)(ts4_word)lbl_880C1320);
}

/* Swing_DLL.xex 0x88987E80: loop_call_seq lbl_880D566C, u32@0x0, fn_88987D68, u32@lbl_88D45888, u32@0x188, u32@0x184 */
ts4_word ts4_loop_call_seq_lbl_880D566C_88987E80(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p6;
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t13;
    ts4_word t16;
    ts4_word t29;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D566C;
    fn_88987D68((ts4_word)a0);
    *(ts4_word *)lbl_88D45888 = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
    if ((ts4_word)t3 != (ts4_word)t2) {
        lv4 = (ts4_word)t3;
        do {
            ts4_if_call_seq_u32_off78_8815FB60((ts4_word)lv4);
            p6 = (ts4_word)(lv4 + 132);
            lv4 = p6;
        } while ((ts4_word)p6 != (ts4_word)t2);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 388);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    ts4_if_call_seq_u32_offd4_881600E8((ts4_word)(a0 + 128));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)), (ts4_word)t13);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
    t29 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t29;
}

/* Swing_DLL.xex 0x88988540: if_call_seq u8@0x8, fn_881B9148, u32@0x1c, fn_8897D628, fn_88987938, u32@lbl_88D45888 */
ts4_word ts4_if_call_seq_u8_off8_88988540(ts4_word a0)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 == (ts4_word)((499777536) | 29317)) {
        fn_88987938((ts4_word)a0, (ts4_word)0);
    } else {
        if ((ts4_word)t2 == (ts4_word)((2801139712) | 59735)) {
            fn_8897D628((ts4_word)t1);
        }
    }
    t7 = *(ts4_word *)lbl_88D45888;
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = fn_88987D68((ts4_word)t7);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x8898E8B0: if_call_seq lbl_88D45BB8, u32@lbl_88D45BB8, u32@0x4, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_88D45BB8_8898E8B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45BB8;
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45BB8) + 0) = (ts4_word)a0;
        p4 = (ts4_word)(t2 - t3);
        if ((ts4_word)(t2 - t3) >= 256) {
            p4 = (ts4_word)255;
        }
        memcpy((ts4_word)((ts4_word)lbl_88D45BB8 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)p4);
        *(unsigned char *)((char *)(ts4_word)(p4) + ((ts4_word)lbl_88D45BB8 + 4)) = (unsigned char)0;
    }
    t10 = fn_88159870((ts4_word)a1);
    return t10;
}

/* Swing_DLL.xex 0x8898FCA8: if_get u32@0x90, fn_8815B210, fn_8898E9C0 */
ts4_word ts4_if_get_u32_off90_8898FCA8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t1 != 1568) {
        return fn_8898E9C0((ts4_word)a0);
    }
    return fn_8815B210((ts4_word)a0);
}

/* Swing_DLL.xex 0x889960D0: addr lbl_880EFA5C, u32@0x4, u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880EFA5C_889960D0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((2696740864) | 58926);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFA5C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88996250: addr lbl_880D2B04, u32@0x4, u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880D2B04_88996250(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((2696740864) | 58926);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2B04;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x889972C8: tailcall ts4_call_seq_fn_885820B0_88885308 */
ts4_word ts4_tailcall_fn_88885308_889972C8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ts4_call_seq_fn_885820B0_88885308((ts4_word)a1);
}

/* Swing_DLL.xex 0x88997598: loop_get u32@0x28, u32@0x0, u32@0x2c, u8@0x30, u32@0x0, u32@0x1c */
ts4_word ts4_loop_get_u32_off28_88997598(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    p8 = (ts4_word)a5;
    p9 = (ts4_word)a6;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 44);
            if ((ts4_word)a1 == (ts4_word)t4) {
                *(unsigned char *)((char *)(ts4_word)(lv3) + 48) = (unsigned char)1;
            }
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0));
            lv3 = p6;
        } while ((ts4_word)t1 != (ts4_word)p6);
        p8 = (ts4_word)t4;
        p9 = (ts4_word)1;
    }
    return fn_88933198((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)p8, (ts4_word)p9, (ts4_word)t1);
}

/* Swing_DLL.xex 0x88997680: if_get u8@0x78, u32@0x4, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10 */
ts4_word ts4_if_get_u8_off78_88997680(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t2;
    ts4_word t5;
    int t8;
    ts4_word t11;

    if ((ts4_word)a1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 120)) == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t5 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t2);
        if ((ts4_word)t5 != 0) {
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 16));
        } else {
            p7 = (ts4_word)-1;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((int)t8 != 0) {
            t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 52))))((ts4_word)t8, (ts4_word)p7);
            return ((t11 + -1) == 0);
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88997AF0: if_get u32@0xc, u8@0x6c, u32@0x4, u32@lbl_88D45B1C, u32@0x234, fn_88614938 */
ts4_word ts4_if_get_u32_offc_88997AF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p12;
    int t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p12 = (ts4_word)a0;
    if (((int)t1 != 0 && (ts4_word)a1 != 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 108)) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t6 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t3);
        if ((ts4_word)t6 != 0) {
            p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 16));
        } else {
            p8 = (ts4_word)-1;
        }
        t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)p8);
        *(unsigned char *)((char *)(ts4_word)(a1) + 108) = (unsigned char)0;
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x88998BB0: if_call_seq fn_8857A798, fn_8857A720, u32@0xc, u32@0x0, fn_8860DCF8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8857A798_88998BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[1];
    int t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    int t8;
    ts4_word t9;

    loc50[0] = (ts4_word)0;
    t1 = fn_8857A798((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        fn_8857A720((ts4_word)t2, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
        t6 = fn_8860DCF8((ts4_word)t4, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0)), (ts4_word)1, (ts4_word)2);
        t7 = loc50[0];
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t6;
        t8 = fn_8857A720((ts4_word)t7, (ts4_word)t6, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        t9 = loc50[0];
        ts4_if_call_seq_u32_off4_8857A748((ts4_word)t9);
        if ((int)t8 != 0) {
            fn_888860A0((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0)));
            return 0;
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88999E98: if_call_seq fn_88999D10, fn_889973D8, u32@0x30, u32@0x30, fn_88999060 */
ts4_word ts4_if_call_seq_fn_88999D10_88999E98(ts4_word a0)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t2;
    int t3;
    ts4_word t4;

    fn_88999D10();
    t2 = fn_889973D8((ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    p6 = (ts4_word)t2;
    if ((int)t3 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(t3 + -1);
        p5 = (ts4_word)t2;
        if ((int)(t3 + -1) == 0) {
            t4 = fn_88999060((ts4_word)a0);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8899A668: if_addr lbl_880D2AC0, u32@g_ts4_session_context, u32@0x0, u32@0x40, u32@0x8, u32@0x4 */
ts4_word ts4_if_addr_lbl_880D2AC0_8899A668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p13;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    t1 = *(volatile ts4_word *)g_ts4_session_context;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2AC0;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 47) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 752) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 756) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 760) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 764) = (ts4_word)0;
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 48) {
        t8 = *(volatile ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 768) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 772) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 776) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 780) = (ts4_word)0;
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 64);
    t11 = *(volatile ts4_word *)((char *)(ts4_word)(t10) + 8);
    p13 = (ts4_word)t10;
    if ((ts4_word)t11 > 49) {
        t12 = *(volatile ts4_word *)((char *)(ts4_word)(t10) + 4);
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 784) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 788) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 792) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 796) = (ts4_word)0;
        p13 = (ts4_word)t12;
    }
    return fn_8893AE90((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)t3, (ts4_word)t7, (ts4_word)t11, (ts4_word)p13);
}

/* Swing_DLL.xex 0x8899AB08: call_seq fn_88939738, fn_88939738, u32@0xc, u32@0xc */
ts4_word ts4_call_seq_fn_88939738_8899AB08(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_88939738((ts4_word)(a0 + 4), (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_88939738((ts4_word)(a0 + 4), (ts4_word)(a0 + 1220));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + 7) & 0xfffffff8);
    return t2;
}

/* Swing_DLL.xex 0x8899B1B0: if_call_seq u32@0xc, fn_8860DCF8, fn_889377F8, lbl_880D2E18, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_offc_8899B1B0(ts4_word a0, ts4_word a1)
{
    ts4_word t5;
    ts4_word t2;

    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 == 1) {
            t5 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)8, (ts4_word)4, (ts4_word)2);
            if ((ts4_word)t5 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)-1;
                *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(ts4_word)lbl_880D2E9C;
                return t5;
            }
            return 0;
        }
        return 0;
    }
    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)72, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_889377F8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2E18;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899B660: if_get u32@lbl_88D45B1C, u32@0x2cc, u8@0x9, u32@0x2cc, u32@0x2cc, u8@0x2b1c */
ts4_word ts4_if_get_u32_lbl_88D45B1C_8899B660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word t1;
    int t2;
    int t6;
    unsigned char t8;

    (void)a1;
    (void)a2;
    t1 = *(volatile ts4_word *)lbl_88D45B1C;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 716);
    if ((int)t2 != 0) {
        p4 = (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(t2) + 9));
    } else {
        p4 = (ts4_word)0;
    }
    if ((ts4_word)(p4 & 0xff) == 0) {
        return a0;
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 716);
    if ((int)t6 == 0) {
        return a0;
    }
    t8 = *(volatile unsigned char *)((char *)(ts4_word)(t6) + 11036);
    if ((ts4_word)t8 == 0) {
        return a0;
    }
    return fn_8899AFD0((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t6) + 4)), (ts4_word)(t6 + 11037), (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t8);
}

/* Swing_DLL.xex 0x8899BFA0: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_8899BFA0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + a0));
    *(ts4_word *)((char *)(ts4_word)((a1 << 2)) + a0) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8899EED0: if_get u32@g_ts4_session_context, u32@0x1c, u32@0x14, u8@0x2c, u32@0x14, u8@0x2c */
ts4_word ts4_if_get_u32_g_ts4_session_context_8899EED0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    unsigned char t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 28);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    t6 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 20))) + 44);
    if ((ts4_word)t6 != 0) {
        return a0;
    }
    return ts4_online_debug_end_season((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068)));
}

/* Swing_DLL.xex 0x889A41F0: if_call_seq lbl_880D245C, u32@0x0, u32@0x158, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880D245C_889A41F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D245C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 344);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 352)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    fn_88157B78((ts4_word)(a0 + 332));
    ts4_netdb_release_owned_list((ts4_word)(a0 + 324));
    t11 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x889A4668: if_get u8@0x42c, fn_889A44C0, fn_889A4590 */
ts4_word ts4_if_get_u8_off42c_889A4668(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 1068);
    if ((ts4_word)t1 != 0) {
        return fn_889A4590((ts4_word)a0, (ts4_word)a1);
    }
    return fn_889A44C0((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889A4910: get u32@0x8, u32@0xc, fn_8899FB48 */
ts4_word ts4_get_u32_off8_889A4910(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return fn_8899FB48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t1, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x889A7818: if_call_seq u32@lbl_88D45B1C, u32@0x27c, u32@0x0, fn_88939470, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_889A7818(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    fn_88939470((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)2);
    t4 = loc50[0];
    if ((ts4_word)t4 >= 1) {
        if ((ts4_word)t4 == 1) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3914334208) | 13737);
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3751936000) | 45041);
    }
    return a0;
}

/* Swing_DLL.xex 0x889ABE30: if_get u32@0x42c, u32@0x30, u32@0x42c, u32@0x14, u32@0x30, u32@0x14 */
ts4_word ts4_if_get_u32_off42c_889ABE30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a2) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068));
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 1068);
    if ((ts4_word)t2 != (ts4_word)((220528640) | 31475)) {
        return a0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 48);
    if ((ts4_word)t6 != (ts4_word)((220528640) | 31475)) {
        return a0;
    }
    return fn_8893AD90((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x889B1A10: if_call_seq u32@0xc8, u8@0x114, u32@0xa4, ts4_if_call_seq_u32_off0_8864BC08, u8@0x234, u32@0xc8 */
ts4_word ts4_if_call_seq_u32_offc8_889B1A10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 200);
    *(unsigned char *)((char *)(ts4_word)(a0) + 276) = (unsigned char)0;
    if ((int)t1 == 2) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        ts4_if_call_seq_u32_off0_8864BC08((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 564) = (unsigned char)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x889B8050: tailcall fn_889B7A08 */
ts4_word ts4_tailcall_fn_889B7A08_889B8050(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return fn_889B7A08((ts4_word)a2);
}

/* Swing_DLL.xex 0x889BD208: if_get u32@0x2e8, u32@0x2e4, fn_88150310, fn_8861B698, u8@0x27a, u8@0x2f4 */
ts4_word ts4_if_get_u32_off2e8_889BD208(ts4_word a0)
{
    ts4_word p20;
    ts4_word p21;
    ts4_word t1;
    unsigned char t5;
    ts4_word t7;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 744);
    fn_88150310((ts4_word)(a0 + 740), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 740)), (ts4_word)t1);
    fn_8861B698((ts4_word)(a0 + 4));
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 634);
    if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 756)) != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 752);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 20))))((ts4_word)t7);
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 680);
    p21 = (ts4_word)t12;
    if ((ts4_word)t12 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 20))))((ts4_word)t12);
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 680);
        p20 = (ts4_word)t16;
        if ((ts4_word)t16 != 0) {
            t19 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 0))))((ts4_word)t16, (ts4_word)1);
            p20 = (ts4_word)t19;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 680) = (ts4_word)0;
        p21 = (ts4_word)p20;
    }
    return p21;
}

/* Swing_DLL.xex 0x889BD2B8: if_call_seq lbl_880C13BC, u32@0x0, u32@0x2e8, u32@0x2e4, ts4_loop_call_seq_u32_off0_88150378, u32@0x2e4 */
ts4_word ts4_if_call_seq_lbl_880C13BC_889BD2B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880C13BC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 744);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 740)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 740);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = fn_8862EFF8((ts4_word)(a0 + 4));
    return t7;
}

/* Swing_DLL.xex 0x889C0B88: call_seq u32@0x0, fn_889C0AE0 */
ts4_word ts4_call_seq_u32_off0_889C0B88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[14];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[3] = (ts4_word)a0;
    loc50[0] = (ts4_word)a2;
    loc50[1] = (ts4_word)a3;
    loc50[4] = (ts4_word)t1;
    t2 = fn_889C0AE0((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x889C49A8: call_seq fn_889C63A0, fn_889C6AE8 */
ts4_word ts4_call_seq_fn_889C63A0_889C49A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[128];

    (void)a0;
    loc50[0] = (ts4_word)512;
    fn_889C63A0((ts4_word)a1, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_889C6AE8((ts4_word)a2, (ts4_word)(ts4_word)&loc60[0]);
    return 1;
}

/* Swing_DLL.xex 0x889C64C0: if_call_seq u32@0x4, u32@0x0, u32@0x0, fn_888860A0, u32@0x0, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4_889C64C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t3;
    ts4_word t7;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 != 1024) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t3 != 0) {
            fn_888860A0((ts4_word)t3);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        }
        t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1024, (ts4_word)1, (ts4_word)0, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t7;
    }
    t10 = ts4_memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)0, (ts4_word)1024);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1024;
    return t10;
}

/* Swing_DLL.xex 0x889C6BA8: get u32@lbl_88D45AD4, fn_886F1BA8 */
ts4_word ts4_get_u32_lbl_88D45AD4_889C6BA8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45AD4;
    return fn_886F1BA8((ts4_word)(t1 + 116), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22076))));
}

/* Swing_DLL.xex 0x889C6EF0: if_call_seq u32@0x0, lbl_880DFA20, ex3_inflateInit2__88875B18, fn_88874270, u32@0x0, ex3_inflateEnd_88873FE0 */
ts4_word ts4_if_call_seq_u32_off0_889C6EF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word loc50[14];
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)a2;
    loc50[1] = (ts4_word)a3;
    loc50[3] = (ts4_word)a0;
    loc50[8] = (ts4_word)0;
    loc50[4] = (ts4_word)t1;
    loc50[9] = (ts4_word)0;
    t2 = ex3_inflateInit2__88875B18((ts4_word)(ts4_word)&loc50[0], (ts4_word)15, (ts4_word)(ts4_word)lbl_880DFA20, (ts4_word)56);
    p11 = (ts4_word)t2;
    if ((int)t2 == 0) {
        t3 = fn_88874270((ts4_word)(ts4_word)&loc50[0], (ts4_word)4);
        if ((int)t3 != 1) {
            ex3_inflateEnd_88873FE0((ts4_word)(ts4_word)&loc50[0]);
            if ((int)t3 != 2) {
                if ((int)t3 != -5 || (ts4_word)(loc50[1]) != 0) {
                    p8 = (ts4_word)t3;
                } else {
                    p8 = (ts4_word)-3;
                }
                p9 = (ts4_word)p8;
            } else {
                p9 = (ts4_word)-3;
            }
            p10 = (ts4_word)p9;
        } else {
            t4 = loc50[5];
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t4;
            t5 = ex3_inflateEnd_88873FE0((ts4_word)(ts4_word)&loc50[0]);
            p10 = (ts4_word)t5;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Swing_DLL.xex 0x889C7E98: call_seq fn_88617D88, lbl_880D7244, u32@0x0, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_889C7E98(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7244;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((983040) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x889D1DE0: get  */
void ts4_get_889D1DE0(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D45BAC = (t1 / (*(float *)lbl_88C6AEFC));
    return;
}

/* Swing_DLL.xex 0x889D1E00: call_seq lbl_88C6D120, fn_88154D40, u32@0x83c, u32@0x838, u32@0x834, RtlInitializeCriticalSection */
ts4_word ts4_call_seq_lbl_88C6D120_889D1E00(void)
{
    ts4_word loc50[512];
    ts4_word t3;

    fn_88154D40((ts4_word)((ts4_word)lbl_88C6D120 + 40), (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D120) + 2108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D120) + 2104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D120) + 2100) = (ts4_word)0;
    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_88C6D120 + 4));
    t3 = fn_88563470((ts4_word)(ts4_word)fn_88AFEE40);
    return t3;
}

/* Swing_DLL.xex 0x889D1F60: call_seq lbl_88C6D960, fn_88154D40, u32@0x83c, u32@0x838, u32@0x834, RtlInitializeCriticalSection */
ts4_word ts4_call_seq_lbl_88C6D960_889D1F60(void)
{
    ts4_word loc50[512];
    ts4_word t3;

    fn_88154D40((ts4_word)((ts4_word)lbl_88C6D960 + 40), (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D960) + 2108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D960) + 2104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6D960) + 2100) = (ts4_word)0;
    RtlInitializeCriticalSection((ts4_word)((ts4_word)lbl_88C6D960 + 4));
    t3 = fn_88563470((ts4_word)(ts4_word)fn_88AFEF90);
    return t3;
}

/* Swing_DLL.xex 0x889D2168: get  */
void ts4_get_889D2168(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D45CBC = (t1 / (*(float *)lbl_88C6B804));
    return;
}

/* Swing_DLL.xex 0x889D21F8: get  */
void ts4_get_889D21F8(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D4635C = (t1 / (*(float *)lbl_88C6B938));
    return;
}

/* Swing_DLL.xex 0x889D2218: get  */
void ts4_get_889D2218(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D46380 = (t1 / (*(float *)lbl_88C6BB10));
    return;
}

/* Swing_DLL.xex 0x889D2288: get  */
void ts4_get_889D2288(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D46384 = (t1 / (*(float *)lbl_88C6BB1C));
    return;
}

/* Swing_DLL.xex 0x889D22F8: get  */
void ts4_get_889D22F8(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D463D0 = (t1 / (*(float *)lbl_88C6BB28));
    return;
}

/* Swing_DLL.xex 0x889D2AD0: get  */
void ts4_get_889D2AD0(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D46800 = (t1 / (*(float *)lbl_88C6BE98));
    return;
}

/* Swing_DLL.xex 0x889D2C38: get  */
void ts4_get_889D2C38(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D48850 = (t1 / (*(float *)lbl_88C6C20C));
    return;
}

/* Swing_DLL.xex 0x889D2C58: get  */
void ts4_get_889D2C58(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D48860 = (t1 / (*(float *)lbl_88C6C234));
    return;
}

/* Swing_DLL.xex 0x889D2D38: get  */
void ts4_get_889D2D38(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D488A0 = (t1 / (*(float *)lbl_88C6C3C0));
    return;
}

/* Swing_DLL.xex 0x889D2DB8: get  */
void ts4_get_889D2DB8(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D488A4 = (t1 / (*(float *)lbl_88C6C438));
    return;
}

/* Swing_DLL.xex 0x889D3228: get  */
void ts4_get_889D3228(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D492F8 = (t1 / (*(float *)lbl_88C6CDA4));
    return;
}

/* Swing_DLL.xex 0x889D3248: get  */
void ts4_get_889D3248(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D492FC = (t1 / (*(float *)lbl_88C6CE08));
    return;
}

/* Swing_DLL.xex 0x889D3268: get  */
void ts4_get_889D3268(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D49300 = (t1 / (*(float *)lbl_88C6CE78));
    return;
}

/* Swing_DLL.xex 0x889D3298: get  */
void ts4_get_889D3298(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D49308 = (t1 / (*(float *)lbl_88C6CE94));
    return;
}

/* Swing_DLL.xex 0x889D32B8: get  */
void ts4_get_889D32B8(void)
{
    float t1;

    t1 = *(float *)g_ts4_script_constants;
    *(float *)lbl_88D4930C = (t1 / (*(float *)lbl_88C6CEA8));
    return;
}

/* Swing_DLL.xex 0x889D3660: addr lbl_88B3B768, u32@lbl_88B3B730, u32@lbl_88B3B734, u32@0xc8, u32@0xe0, u32@0xf8 */
void ts4_addr_lbl_88B3B768_889D3660(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B3B730;
    t2 = *(ts4_word *)lbl_88B3B734;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B768) + 200) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B768) + 224) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B768) + 248) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B3B768) + 272) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x88A463B0: call_seq lbl_88046B60, lbl_88CDC1B4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88046B60_88A463B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDC1B4, (ts4_word)(ts4_word)lbl_88046B60, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A468B0: call_seq lbl_88B8F168, lbl_88046220, lbl_88CDC3F4, fn_8841F080 */
ts4_word ts4_call_seq_lbl_88B8F168_88A468B0(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDC3F4, (ts4_word)(ts4_word)lbl_88046220, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_88B8F168, (ts4_word)4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A46FC8: addr lbl_88B933D0, u32@lbl_88B8F46C, u32@0x80 */
void ts4_addr_lbl_88B933D0_88A46FC8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B933D0) + 128) = (ts4_word)(*(ts4_word *)lbl_88B8F46C);
    return;
}

/* Swing_DLL.xex 0x88A47370: addr lbl_88B93478, u32@lbl_88B8F658, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B93478_88A47370(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B8F658;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93478) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93478) + 128) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A47CA8: addr lbl_88B935B0, u32@lbl_88B8FAC8, u32@0x8 */
void ts4_addr_lbl_88B935B0_88A47CA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B935B0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8FAC8);
    return;
}

/* Swing_DLL.xex 0x88A48420: addr lbl_88B935C8, u32@lbl_88B8FDD0, u32@0x50 */
void ts4_addr_lbl_88B935C8_88A48420(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B935C8) + 80) = (ts4_word)(*(ts4_word *)lbl_88B8FDD0);
    return;
}

/* Swing_DLL.xex 0x88A48BA8: addr lbl_88B93670, u32@lbl_88B8FDD4, u32@0x8 */
void ts4_addr_lbl_88B93670_88A48BA8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93670) + 8) = (ts4_word)(*(ts4_word *)lbl_88B8FDD4);
    return;
}

/* Swing_DLL.xex 0x88A48DF0: addr lbl_88B936B8, u32@lbl_88B9028C, u32@0x68 */
void ts4_addr_lbl_88B936B8_88A48DF0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B936B8) + 104) = (ts4_word)(*(ts4_word *)lbl_88B9028C);
    return;
}

/* Swing_DLL.xex 0x88A49218: addr lbl_88B93790, u32@lbl_88B904C8, u32@0x50 */
void ts4_addr_lbl_88B93790_88A49218(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93790) + 80) = (ts4_word)(*(ts4_word *)lbl_88B904C8);
    return;
}

/* Swing_DLL.xex 0x88A49D18: addr lbl_88B93808, u32@lbl_88B90C70, u32@0x8 */
void ts4_addr_lbl_88B93808_88A49D18(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93808) + 8) = (ts4_word)(*(ts4_word *)lbl_88B90C70);
    return;
}

/* Swing_DLL.xex 0x88A4A368: addr lbl_88B93820, u32@lbl_88B91020, u32@0x8 */
void ts4_addr_lbl_88B93820_88A4A368(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B93820) + 8) = (ts4_word)(*(ts4_word *)lbl_88B91020);
    return;
}

/* Swing_DLL.xex 0x88A4AA18: get u32@lbl_88B911B0, lbl_88B938E0, u32@lbl_88B911AC, u32@lbl_88B911A8, u32@0x50, u32@0x128 */
void ts4_get_u32_lbl_88B911B0_88A4AA18(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88B911B0;
    t2 = *(ts4_word *)lbl_88B911AC;
    t3 = *(ts4_word *)lbl_88B911A8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B938E0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B938E0) + 296) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B938E0) + 632) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x88A4C9E8: call_seq lbl_8805BF00, lbl_8805D2B0, lbl_88CDEBB4, ts4_set_u32_offc_884CE988, ts4_addr_lbl_8803A308_88AFF620, fn_88563470 */
ts4_word ts4_call_seq_lbl_8805BF00_88A4C9E8(void)
{
    ts4_word t2;

    ts4_set_u32_offc_884CE988((ts4_word)(ts4_word)lbl_88CDEBB4, (ts4_word)(ts4_word)lbl_8805D2B0, (ts4_word)4, (ts4_word)(ts4_word)lbl_8805BF00);
    t2 = fn_88563470((ts4_word)(ts4_word)ts4_addr_lbl_8803A308_88AFF620);
    return t2;
}

/* Swing_DLL.xex 0x88A4CAA0: addr lbl_88B9AD68, u32@lbl_88B93C40, u32@0x38 */
void ts4_addr_lbl_88B9AD68_88A4CAA0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9AD68) + 56) = (ts4_word)(*(ts4_word *)lbl_88B93C40);
    return;
}

/* Swing_DLL.xex 0x88A4CC08: addr lbl_88B9ADB0, u32@lbl_88B93CA4, u32@0x8 */
void ts4_addr_lbl_88B9ADB0_88A4CC08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9ADB0) + 8) = (ts4_word)(*(ts4_word *)lbl_88B93CA4);
    return;
}

/* Swing_DLL.xex 0x88A4D3B0: addr lbl_88B9AE28, u32@lbl_88B94084, u32@0x128 */
void ts4_addr_lbl_88B9AE28_88A4D3B0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9AE28) + 296) = (ts4_word)(*(ts4_word *)lbl_88B94084);
    return;
}

/* Swing_DLL.xex 0x88A4D5A8: call_seq lbl_8805E8B4, lbl_88B944B0, lbl_88042110, lbl_88CDF07C, fn_8841F080 */
ts4_word ts4_call_seq_lbl_8805E8B4_88A4D5A8(void)
{
    ts4_word t1;

    t1 = fn_8841F080((ts4_word)(ts4_word)lbl_88CDF07C, (ts4_word)(ts4_word)lbl_88042110, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)lbl_8805E8B4, (ts4_word)1, (ts4_word)(ts4_word)lbl_88B944B0, (ts4_word)14, (ts4_word)((ts4_word)lbl_8805E8B4 + 20), (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88A4D940: addr lbl_88B9AF60, u32@lbl_88B94840, u32@0x68 */
void ts4_addr_lbl_88B9AF60_88A4D940(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9AF60) + 104) = (ts4_word)(*(ts4_word *)lbl_88B94840);
    return;
}

/* Swing_DLL.xex 0x88A4DAB8: addr lbl_88B9AFD8, u32@lbl_88B94938, u32@0x8 */
void ts4_addr_lbl_88B9AFD8_88A4DAB8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9AFD8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B94938);
    return;
}

/* Swing_DLL.xex 0x88A4DBC0: addr lbl_88B9B158, u32@lbl_88B94970, u32@0x68 */
void ts4_addr_lbl_88B9B158_88A4DBC0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B158) + 104) = (ts4_word)(*(ts4_word *)lbl_88B94970);
    return;
}

/* Swing_DLL.xex 0x88A4E4F0: addr lbl_88B9B248, u32@lbl_88B9498C, u32@0x50 */
void ts4_addr_lbl_88B9B248_88A4E4F0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B248) + 80) = (ts4_word)(*(ts4_word *)lbl_88B9498C);
    return;
}

/* Swing_DLL.xex 0x88A4F2A8: addr lbl_88B9B350, u32@lbl_88B95C5C, u32@0x50 */
void ts4_addr_lbl_88B9B350_88A4F2A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B350) + 80) = (ts4_word)(*(ts4_word *)lbl_88B95C5C);
    return;
}

/* Swing_DLL.xex 0x88A4F3A8: addr lbl_88B9B470, u32@lbl_88B95C78, u32@0x20 */
void ts4_addr_lbl_88B9B470_88A4F3A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B470) + 32) = (ts4_word)(*(ts4_word *)lbl_88B95C78);
    return;
}

/* Swing_DLL.xex 0x88A4F890: addr lbl_88B9B4A0, u32@lbl_88B95DEC, u32@0x50, u32@0x68 */
void ts4_addr_lbl_88B9B4A0_88A4F890(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B95DEC;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B4A0) + 80) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B4A0) + 104) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x88A4FA70: addr lbl_88B9B560, u32@lbl_88B95F78, u32@0x68 */
void ts4_addr_lbl_88B9B560_88A4FA70(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B560) + 104) = (ts4_word)(*(ts4_word *)lbl_88B95F78);
    return;
}

/* Swing_DLL.xex 0x88A4FE08: addr lbl_88B9B638, u32@lbl_88B96240, u32@0x20 */
void ts4_addr_lbl_88B9B638_88A4FE08(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B638) + 32) = (ts4_word)(*(ts4_word *)lbl_88B96240);
    return;
}

/* Swing_DLL.xex 0x88A4FE90: addr lbl_88B9B668, u32@lbl_88B96240, u32@0x20 */
void ts4_addr_lbl_88B9B668_88A4FE90(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B668) + 32) = (ts4_word)(*(ts4_word *)lbl_88B96240);
    return;
}

/* Swing_DLL.xex 0x88A4FF88: addr lbl_88B9B698, u32@lbl_88B96240, u32@0x20 */
void ts4_addr_lbl_88B9B698_88A4FF88(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B698) + 32) = (ts4_word)(*(ts4_word *)lbl_88B96240);
    return;
}

/* Swing_DLL.xex 0x88A505D0: addr lbl_88B9B6C8, u32@lbl_88B9637C, u32@0x8 */
void ts4_addr_lbl_88B9B6C8_88A505D0(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B6C8) + 8) = (ts4_word)(*(ts4_word *)lbl_88B9637C);
    return;
}

/* Swing_DLL.xex 0x88A50740: addr lbl_88B9B740, u32@lbl_88B9657C, u32@0x20 */
void ts4_addr_lbl_88B9B740_88A50740(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B740) + 32) = (ts4_word)(*(ts4_word *)lbl_88B9657C);
    return;
}

/* Swing_DLL.xex 0x88A508A8: addr lbl_88B9B788, u32@lbl_88B96688, u32@0x8 */
void ts4_addr_lbl_88B9B788_88A508A8(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B788) + 8) = (ts4_word)(*(ts4_word *)lbl_88B96688);
    return;
}

/* Swing_DLL.xex 0x88A51658: addr lbl_88B9B800, u32@lbl_88B97260, u32@0x8 */
void ts4_addr_lbl_88B9B800_88A51658(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B800) + 8) = (ts4_word)(*(ts4_word *)lbl_88B97260);
    return;
}

/* Swing_DLL.xex 0x88A52188: addr lbl_88B9B830, u32@lbl_88B976CC, u32@lbl_88B97634, u32@0x8, u32@0x20 */
void ts4_addr_lbl_88B9B830_88A52188(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88B976CC;
    t2 = *(ts4_word *)lbl_88B97634;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B830) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B830) + 32) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x88A52220: addr lbl_88B9B8D8, u32@lbl_88B97634, u32@0x80 */
void ts4_addr_lbl_88B9B8D8_88A52220(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B8D8) + 128) = (ts4_word)(*(ts4_word *)lbl_88B97634);
    return;
}

/* Swing_DLL.xex 0x88A52328: addr lbl_88B9B998, u32@lbl_88B97D68, u32@0x80 */
void ts4_addr_lbl_88B9B998_88A52328(void)
{
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9B998) + 128) = (ts4_word)(*(ts4_word *)lbl_88B97D68);
    return;
}

/* Swing_DLL.xex 0x88A525E0: addr lbl_88B9BA58, u32@lbl_88B977D8, u32@0x68, u32@0x80 */
void ts4_addr_lbl_88B9BA58_88A525E0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88B977D8;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BA58) + 104) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88B9BA58) + 128) = (ts4_word)t1;
    return;
}
