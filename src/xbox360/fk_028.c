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

extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_880C1324[];
extern char lbl_880C1334[];
extern char lbl_880C13BC[];
extern char lbl_880CDBB7[];
extern char lbl_880CDC02[];
extern char lbl_880CFC4F[];
extern char lbl_880D052B[];
extern char lbl_880D0532[];
extern char lbl_880D0533[];
extern char lbl_880D19F0[];
extern char lbl_880D1F80[];
extern char lbl_880D1F8C[];
extern char lbl_880D2208[];
extern char lbl_880D23E0[];
extern char lbl_880D24AC[];
extern char lbl_880D24B8[];
extern char lbl_880D24E0[];
extern char lbl_880D2A68[];
extern char lbl_880D2CF8[];
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880D7310[];
extern char lbl_880D7380[];
extern char lbl_880D73C4[];
extern char lbl_880D73FC[];
extern char lbl_880D7570[];
extern char lbl_880E23A0[];
extern char lbl_880E23D8[];
extern char lbl_88C6B4AC[];
extern char lbl_88D3CD50[];
extern char lbl_88D3EB60[];
extern char lbl_88D45834[];
extern char lbl_88D45838[];
extern char lbl_88D45848[];
extern char lbl_88D45910[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
ts4_word fn_881512B8();
ts4_word fn_88151560();
ts4_word ts4_flagged_object_create_extra_88153678();
ts4_word fn_88153A70();
ts4_word ts4_flagged_object_create_88153B30();
ts4_word ts4_flagged_object_create_88153BE0();
ts4_word ts4_flagged_object_create_extra_88153C90();
ts4_word ts4_flagged_object_create_88153D48();
ts4_word ts4_flagged_object_create_88153DF8();
ts4_word fn_88153EA8();
ts4_word ts4_flagged_object_create_extra_88153F60();
ts4_word ts4_flagged_object_create_88154018();
ts4_word ts4_flagged_object_create_88154180();
ts4_word fn_88154230();
ts4_word ts4_flagged_object_create_881544D8();
ts4_word fn_88177110();
ts4_word fn_881ACBA8();
ts4_word fn_881B9148();
ts4_word ts4_tailcall_NetDll_WSACleanup_884F0238();
ts4_word fn_88563F20();
ts4_word fn_885640B0();
ts4_word fn_88564430();
ts4_word fn_88564B10();
ts4_word fn_88564D28();
ts4_word fn_88565040();
ts4_word fn_88565118();
ts4_word fn_88569B08();
ts4_word ts4_tailcall_fn_88569A10_88569BD0();
ts4_word fn_8857A1E0();
ts4_word fn_88608088();
ts4_word fn_88608590();
ts4_word fn_8860DCF8();
ts4_word fn_88616758();
ts4_word fn_88616A70();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8862F0B8();
ts4_word fn_8864B268();
ts4_word fn_8864B468();
ts4_word fn_8864BBB0();
ts4_word ts4_if_call_seq_u32_off0_8864BC08();
ts4_word fn_8864C170();
ts4_word ts4_msg_pool_service_get_8864DFF0();
ts4_word fn_88823320();
ts4_word fn_88823FC0();
ts4_word fn_888240B8();
ts4_word fn_88824188();
ts4_word ts4_lua_opt_number_default_8882EA98();
ts4_word fn_88866B60();
ts4_word fn_88866C30();
ts4_word fn_88883CD0();
ts4_word fn_888860A0();
ts4_word fn_888892A8();
ts4_word fn_888D7FA8();
ts4_word fn_888F70A0();
ts4_word fn_88912090();
ts4_word fn_889122D8();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word fn_889298D8();
ts4_word fn_889333F0();
ts4_word ts4_call_seq_u32_off8_889343E8();
ts4_word fn_88934458();
ts4_word fn_88934B80();
ts4_word fn_88935C70();
ts4_word fn_88935D10();
ts4_word fn_88936BB0();
ts4_word fn_889375D8();
ts4_word fn_88937A00();
ts4_word fn_88937A88();
ts4_word fn_88938660();
ts4_word fn_88938F38();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_889396A8();
ts4_word fn_8893AFB0();
ts4_word fn_8893B080();
ts4_word fn_8893B3E0();
ts4_word fn_8893C990();
ts4_word fn_8893CCE8();
ts4_word fn_8893EA28();
ts4_word fn_8893EFD8();
ts4_word fn_88997D08();
ts4_word fn_889988E0();
ts4_word fn_889989A0();
ts4_word fn_88998B10();
ts4_word ts4_call_seq_lbl_880D2570_8899A0D8();
ts4_word fn_8899A3C0();
ts4_word fn_8899A9B8();
ts4_word ts4_get_u32_off0_8899AD88();
ts4_word fn_8899ADF8();
ts4_word fn_8899B2E8();
ts4_word fn_8899B370();
ts4_word fn_8899B710();
ts4_word fn_8899CB48();
ts4_word fn_8899D518();
ts4_word fn_8899D750();
ts4_word fn_8899FA00();
ts4_word fn_8899FAE8();
ts4_word ts4_session_event_post_8899FE40();
ts4_word fn_889A00A8();
ts4_word fn_889A0208();
ts4_word fn_889A0808();
ts4_word fn_889A1108();
ts4_word fn_889A12E8();
ts4_word fn_889A13B0();
ts4_word fn_889A14B0();
ts4_word fn_889A15A0();
ts4_word fn_889A16A8();
ts4_word fn_889A17C0();
ts4_word fn_889A4A28();
ts4_word fn_889A4E50();
ts4_word fn_889A4FD0();
ts4_word fn_889A7620();
ts4_word fn_889A7818();
ts4_word fn_889A7D38();
ts4_word fn_889ABE30();
ts4_word fn_889AC4B0();
ts4_word fn_889B0AD8();
ts4_word fn_889B11B0();
ts4_word fn_889B4418();
ts4_word fn_889B5A30();
ts4_word fn_889BAC88();
ts4_word fn_889BB7F0();
ts4_word fn_889BBD50();
ts4_word ts4_keyed_item_add_unique_889BCC28();
ts4_word ts4_keyed_item_add_unique_889BCCD8();
ts4_word fn_889BD910();
ts4_word fn_889BE668();
ts4_word ts4_if_call_seq_fn_889BD910_889BFB60();
ts4_word ts4_if_call_seq_fn_889BD910_889BFBD0();
ts4_word fn_889BFC40();
ts4_word fn_889BFDA8();
ts4_word fn_889C0298();
ts4_word ts4_if_call_seq_fn_889BD910_889C0778();
ts4_word fn_889C0878();
ts4_word ts4_keyed_item_add_or_remove_889C30B8();
ts4_word ts4_keyed_item_add_or_remove_889C5468();
ts4_word ts4_keyed_item_add_or_remove_889C5818();
ts4_word ts4_keyed_item_add_or_remove_889C5BC0();
ts4_word ts4_keyed_item_add_or_remove_889C5F18();
ts4_word fn_889C64C0();
ts4_word fn_889C6888();
ts4_word fn_889C8148();
ts4_word ts4_clear_intrusive_list();
ts4_word ts4_create_lobby_message();
ts4_word ts4_find_service();
ts4_word ts4_initialize_netdb_extended_record();
ts4_word ts4_memset();

/* Swing_DLL.xex 0x8899B7C0: if_call_seq u32@0xc, fn_8860DCF8, fn_88938660, lbl_880D2CF8, u8@0x34, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_8899B7C0(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)56, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88938660((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 52) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D2CF8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899B838: if_call_seq u32@0xc, fn_8860DCF8, fn_8899A9B8 */
ts4_word ts4_if_call_seq_u32_offc_8899B838(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)112, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8899A9B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899B888: call_seq fn_88935C70, fn_8899B710 */
ts4_word ts4_call_seq_fn_88935C70_8899B888(ts4_word a0)
{
    ts4_word t2;

    fn_88935C70((ts4_word)a0);
    t2 = fn_8899B710((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8899B8C0: call_seq lbl_880D052B, u32@lbl_88D45848, ts4_call_seq_lbl_880D2570_8899A0D8, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880D052B_8899B8C0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)lbl_88D45848 = (ts4_word)0;
    ts4_call_seq_lbl_880D2570_8899A0D8((ts4_word)(ts4_word)lbl_880D052B);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x8899BBB8: if_call_seq fn_88937A88, u8@0x24, fn_8893EA28, fn_8899A3C0 */
ts4_word ts4_if_call_seq_fn_88937A88_8899BBB8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    unsigned char t2;
    ts4_word t3;
    ts4_word t6;

    fn_88937A88();
    t2 = *(unsigned char *)((char *)(ts4_word)(a1) + 36);
    p5 = (ts4_word)0;
    if ((ts4_word)t2 == 1) {
        t3 = fn_8893EA28((ts4_word)a0, (ts4_word)0);
        p5 = (ts4_word)t3;
    }
    t6 = fn_8899A3C0((ts4_word)a1, (ts4_word)p5);
    return t6;
}

/* Swing_DLL.xex 0x8899BC18: tailcall fn_8893EFD8 */
ts4_word ts4_tailcall_fn_8893EFD8_8899BC18(ts4_word a0)
{
    return fn_8893EFD8((ts4_word)a0);
}

/* Swing_DLL.xex 0x8899BF90: fn  */
ts4_word ts4_fn_8899BF90(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8899BFD8: fn  */
ts4_word ts4_fn_8899BFD8(ts4_word a0, ts4_word a1)
{
    return (((a0 << 3) + a1) + -1);
}

/* Swing_DLL.xex 0x8899C008: set u32@0x8 */
void ts4_set_u32_off8_8899C008(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8899C070: addr lbl_880D1F80, u8@0x48, u32@0x0, u8@0x58 */
void ts4_addr_lbl_880D1F80_8899C070(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D1F80;
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8899C0D0: addr lbl_880D19F0, u32@0x0 */
void ts4_addr_lbl_880D19F0_8899C0D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x8899C0E0: addr lbl_880D24AC, u64@0x8, u32@0x0, u64@0x10, u64@0x18, u64@0x20 */
void ts4_addr_lbl_880D24AC_8899C0E0(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D24AC;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)0;
    return;
}

/* Swing_DLL.xex 0x8899C108: if_set u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_set_u32_off0_8899C108(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((int)(a2 - a1) != 1) {
        if ((int)(a2 - a1) != 2) {
            if ((int)(a2 - a1) != 3) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1688993792) | 54990);
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2092040192) | 59587);
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((526516224) | 56825);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1850277888) | 30948);
    return;
}

/* Swing_DLL.xex 0x8899C168: if_set u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_set_u32_off0_8899C168(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)(a3 & 0xff) != 0) {
        if ((int)(a2 - a1) != 1) {
            if ((int)(a2 - a1) != 2) {
                if ((int)(a2 - a1) != 3) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((988872704) | 31234);
                    return;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3753705472) | 52574);
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3985309696) | 45020);
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1369112576) | 26635);
        return;
    }
    if ((int)(a2 - a1) != 1) {
        if ((int)(a2 - a1) != 2) {
            if ((int)(a2 - a1) != 3) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3800170496) | 25697);
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2014183424) | 64450);
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2439839744) | 24311);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1426128896) | 46072);
    return;
}

/* Swing_DLL.xex 0x8899C228: get u32@g_ts4_session_context, u32@0x68 */
ts4_word ts4_get_u32_g_ts4_session_context_8899C228(void)
{
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 104)) + 544);
}

/* Swing_DLL.xex 0x8899C240: get u32@0x0, u32@-0x4 */
ts4_word ts4_get_u32_off0_8899C240(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (*(ts4_word *)((char *)(ts4_word)(((((a1 << 3) + a2) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)))) + -4));
}

/* Swing_DLL.xex 0x8899C260: if_get u32@0x0, u32@-0x4, u32@-0x4, u32@0x0, u32@-0x4 */
void ts4_if_get_u32_off0_8899C260(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(((((a1 << 3) + a2) << 2) + t1)) + -4);
    if ((int)t2 >= (int)a3) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((((a1 << 3) + a2) << 2) + t1)) + -4) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(((((a2 << 3) + a1) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)))) + -4) = (ts4_word)a3;
    return;
}

/* Swing_DLL.xex 0x8899C2B0: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_8899C2B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x8899C2D0: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_8899C2D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x8899C2F0: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_8899C2F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x8899C458: get ts4_find_service, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_get_ts4_find_service_8899C458(void)
{
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_find_service((ts4_word)((3003318272) | 57388));
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    return t4;
}

/* Swing_DLL.xex 0x8899C4F0: get u32@0x2c, u8@0x245 */
ts4_word ts4_get_u32_off2c_8899C4F0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 581));
}

/* Swing_DLL.xex 0x8899C500: get u32@0x2c, u8@0x244 */
ts4_word ts4_get_u32_off2c_8899C500(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 580));
}

/* Swing_DLL.xex 0x8899C640: get u32@g_ts4_session_context, u32@0x68, u32@0x22c */
ts4_word ts4_get_u32_g_ts4_session_context_8899C640(void)
{
    return ((((3712679936) | 63449) - (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 104))) + 556))) == 0);
}

/* Swing_DLL.xex 0x8899C6C8: set u32@0x0, u8@0x4, u32@0xc */
void ts4_set_u32_off0_8899C6C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x8899C6E0: set u32@0x0, u8@0x4 */
void ts4_set_u32_off0_8899C6E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)a2;
    return;
}

/* Swing_DLL.xex 0x8899C6F0: if_call_seq u32@0xc, fn_8860DCF8, lbl_880D1F80, u8@0x48, u32@0x0, u8@0x58 */
ts4_word ts4_if_call_seq_u32_offc_8899C6F0(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)96, (ts4_word)8, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t2) + 72) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D1F80;
        *(unsigned char *)((char *)(ts4_word)(t2) + 88) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899CA38: get u32@0x2c, u32@0x48 */
ts4_word ts4_get_u32_off2c_8899CA38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 72));
}

/* Swing_DLL.xex 0x8899CAA8: if_get u32@0x2c, u32@0x90, u8@0x245 */
ts4_word ts4_if_get_u32_off2c_8899CAA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 144);
        t4 = *(ts4_word *)((char *)(ts4_word)((((*(unsigned char *)((char *)(ts4_word)(t1) + 581)) + 34) << 2)) + a0);
        if ((ts4_word)t4 == (ts4_word)t2) {
            return 1;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x8899CE60: if_get u32@0xbc, u32@0xb0 */
ts4_word ts4_if_get_u32_offbc_8899CE60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    if ((int)t1 == (int)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        if ((ts4_word)t2 != 0) {
            return 1;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x8899CFB8: tailcall fn_888860A0 */
ts4_word ts4_tailcall_fn_888860A0_8899CFB8(ts4_word a0)
{
    return fn_888860A0((ts4_word)a0);
}

/* Swing_DLL.xex 0x8899D070: set u32@0x4c */
void ts4_set_u32_off4c_8899D070(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 76) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x8899D910: set u8@0x44 */
void ts4_set_u8_off44_8899D910(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 68) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8899D920: tailcall fn_8899D518 */
ts4_word ts4_tailcall_fn_8899D518_8899D920(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8899D518((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8899D938: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x8, u32@-0x4, u32@-0x4 */
void ts4_if_get_u32_off0_8899D938(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t5 = *(ts4_word *)((char *)(ts4_word)(((((t1 << 3) + t2) << 2) + t3)) + -4);
    if ((int)t5 >= (int)t4) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((((t1 << 3) + t2) << 2) + t3)) + -4) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(((((t2 << 3) + t1) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)))) + -4) = (ts4_word)t4;
    return;
}

/* Swing_DLL.xex 0x8899E0E0: tailcall ts4_clear_intrusive_list */
ts4_word ts4_tailcall_ts4_clear_intrusive_list_8899E0E0(ts4_word a0)
{
    return ts4_clear_intrusive_list((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x8899E330: call_seq fn_88608088, u32@0x280, u32@0x18, u32@0x274, u32@0x40 */
ts4_word ts4_call_seq_fn_88608088_8899E330(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88608088((ts4_word)(a1 + 480), (ts4_word)(a0 + 32), (ts4_word)32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 640));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 628));
    return t1;
}

/* Swing_DLL.xex 0x8899F238: get u32@0x80, u32@0x80, fn_88997D08 */
ts4_word ts4_get_u32_off80_8899F238(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    return fn_88997D08((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8899F248: set u64@0x70, u8@0x78, ts4_call_seq_u32_off8_889343E8 */
ts4_word ts4_set_u64_off70_8899F248(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    return ts4_call_seq_u32_off8_889343E8((ts4_word)a0);
}

/* Swing_DLL.xex 0x8899F258: addr lbl_880D2A68, u32@0x0, fn_88934458 */
ts4_word ts4_addr_lbl_880D2A68_8899F258(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2A68;
    return fn_88934458((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2A68);
}

/* Swing_DLL.xex 0x8899F5B0: if_get u32@0xd8, u32@0x0, u32@0x8 */
void ts4_if_get_u32_offd8_8899F5B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    if ((int)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x889A01B8: get u32@g_ts4_session_context, u32@0x68, fn_88866B60 */
ts4_word ts4_get_u32_g_ts4_session_context_889A01B8(ts4_word a0)
{
    return fn_88866B60((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 104)) + 5056));
}

/* Swing_DLL.xex 0x889A01D0: get u32@g_ts4_session_context, u32@0x68, fn_88866C30 */
ts4_word ts4_get_u32_g_ts4_session_context_889A01D0(ts4_word a0)
{
    return fn_88866C30((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 104)) + 5056));
}

/* Swing_DLL.xex 0x889A01E8: get u32@g_ts4_session_context, u32@0x3c, u32@0x280 */
void ts4_get_u32_g_ts4_session_context_889A01E8(void)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60))) + 640) = (ts4_word)((3465084928) | 47812);
    return;
}

/* Swing_DLL.xex 0x889A0430: tailcall ts4_session_event_post_8899FE40 */
ts4_word ts4_tailcall_fn_8899FE40_889A0430(ts4_word a0)
{
    return ts4_session_event_post_8899FE40((ts4_word)a0);
}

/* Swing_DLL.xex 0x889A0438: tailcall fn_8899FAE8 */
ts4_word ts4_tailcall_fn_8899FAE8_889A0438(ts4_word a0)
{
    return fn_8899FAE8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889A0440: tailcall fn_889A0208 */
ts4_word ts4_tailcall_fn_889A0208_889A0440(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889A0208((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889A0460: tailcall fn_889A00A8 */
ts4_word ts4_tailcall_fn_889A00A8_889A0460(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889A00A8((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889A08D0: if_call_seq fn_8899D750, u32@g_ts4_session_context, u32@0x10, u32@0x68, fn_88866C30, u32@0xec */
ts4_word ts4_if_call_seq_fn_8899D750_889A08D0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;

    t1 = fn_8899D750((ts4_word)0);
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)g_ts4_session_context;
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
        t5 = fn_88866C30((ts4_word)t3, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 104)) + 5056));
        if ((ts4_word)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 172) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 236));
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 176) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 20));
        p8 = (ts4_word)t5;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t10 = *(ts4_word *)g_ts4_session_context;
    *(ts4_word *)((char *)(ts4_word)(a1) + 180) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 320));
    *(ts4_word *)((char *)(ts4_word)(a1) + 196) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 60))) + 2244));
    return p8;
}

/* Swing_DLL.xex 0x889A0A58: if_call_seq u8@0x8, fn_881B9148, u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4 */
ts4_word ts4_if_call_seq_u8_off8_889A0A58(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 64);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
    if ((ts4_word)t4 > 73) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
        *(ts4_word *)((char *)(ts4_word)(t5) + 1168) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 1172) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 1176) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t5) + 1180) = (ts4_word)0;
    }
    return t1;
}

/* Swing_DLL.xex 0x889A0AC0: tailcall fn_889A0808 */
ts4_word ts4_tailcall_fn_889A0808_889A0AC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889A0808((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889A0AD8: addr lbl_880D24E0, u32@0x0, fn_88617D28 */
ts4_word ts4_addr_lbl_880D24E0_889A0AD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D24E0;
    return fn_88617D28((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D24E0);
}

/* Swing_DLL.xex 0x889A0AE8: call_seq fn_88617D88, lbl_880D24E0, u32@0x1c, u32@0x0, u8@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_889A0AE8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D24E0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    ts4_initialize_netdb_extended_record((ts4_word)(a0 + 76));
    ts4_memset((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)32);
    ts4_memset((ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)208);
    return a0;
}

/* Swing_DLL.xex 0x889A0B80: call_seq u32@0x64, u32@0x64, fn_88934B80, u8@0x34, u8@0x34, u8@0x38 */
ts4_word ts4_call_seq_u32_off64_889A0B80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
    fn_88934B80();
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 52));
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    return a0;
}

/* Swing_DLL.xex 0x889A0C98: addr lbl_880D24B8, u32@0x0, fn_88617D28 */
ts4_word ts4_addr_lbl_880D24B8_889A0C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D24B8;
    return fn_88617D28((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D24B8);
}

/* Swing_DLL.xex 0x889A0DE8: tailcall fn_88936BB0 */
ts4_word ts4_tailcall_fn_88936BB0_889A0DE8(ts4_word a0, ts4_word a1)
{
    return fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889A22A0: tailcall fn_889988E0 */
ts4_word ts4_tailcall_fn_889988E0_889A22A0(ts4_word a0)
{
    return fn_889988E0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889A26A8: get fn_889333F0, u32@0x0, u32@0x40, vcall, fn_889989A0 */
ts4_word ts4_get_fn_889333F0_889A26A8(ts4_word a0)
{
    ts4_word t5;

    fn_889333F0();
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    t5 = fn_889989A0((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x889A2710: call_seq fn_88998B10, lbl_880D2208, u32@0x0 */
ts4_word ts4_call_seq_fn_88998B10_889A2710(ts4_word a0)
{
    fn_88998B10((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2208;
    return a0;
}

/* Swing_DLL.xex 0x889A27A0: call_seq fn_88935D10, u32@0x64, fn_8857A1E0, ts4_tailcall_NetDll_WSACleanup_884F0238 */
ts4_word ts4_call_seq_fn_88935D10_889A27A0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    fn_88935D10();
    t3 = fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)));
    t4 = ts4_tailcall_NetDll_WSACleanup_884F0238((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x889A27D8: call_seq fn_88617D88, lbl_880D23E0, u32@0x0 */
ts4_word ts4_call_seq_fn_88617D88_889A27D8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D23E0;
    return a0;
}

/* Swing_DLL.xex 0x889A3208: if_call_seq u32@0x38, fn_881ACBA8, fn_8899CB48 */
ts4_word ts4_if_call_seq_u32_off38_889A3208(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_881ACBA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)), (ts4_word)a1);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8899CB48((ts4_word)a0, (ts4_word)(t2 + 12));
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x889A3EF8: call_seq fn_889375D8, lbl_880D1F8C, u64@0x70, u32@0x0, u8@0x78, u32@0x80 */
ts4_word ts4_call_seq_fn_889375D8_889A3EF8(ts4_word a0)
{
    fn_889375D8();
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D1F8C;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)-1;
    return a0;
}

/* Swing_DLL.xex 0x889A4190: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_881544D8, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A4190(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_881544D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A4878: get u8@0x430, u32@0x42c, fn_8899FA00 */
ts4_word ts4_get_u8_off430_889A4878(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 1072);
    return fn_8899FA00((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x889A5A00: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88154180, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A5A00(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88154180((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A5B48: get u32@g_ts4_session_context, u32@0xc, ts4_create_lobby_message, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A5B48(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_create_lobby_message((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A5C88: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88154018, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A5C88(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88154018((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A5CE8: addr lbl_88D3CD50, fn_889A1108, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889A5CE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    (void)a2;
    t1 = fn_889A1108((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889A4A28((ts4_word)a3, (ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889A5D68: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A1108, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A5D68(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1212, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A1108((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A5DE8: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_extra_88153F60, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A5DE8(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_extra_88153F60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A5F38: get u32@g_ts4_session_context, u32@0xc, fn_88153EA8, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A5F38(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88153EA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A5F98: addr lbl_88D3CD50, fn_889A16A8, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889A5F98(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    t1 = fn_889A16A8((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    t5 = fn_8899FAE8((ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t5, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889A5FF8: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A16A8, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A5FF8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1092, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A16A8((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A6078: addr lbl_88D3CD50, fn_889A12E8, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889A6078(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889A12E8((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889A0208((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889A60F0: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A12E8, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A60F0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1296, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A12E8((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A6170: addr lbl_88D3CD50, fn_889A13B0, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889A6170(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t7;

    t1 = fn_889A13B0((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t7;
}

/* Swing_DLL.xex 0x889A61D0: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A13B0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A61D0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1088, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A13B0((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A64E8: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88153DF8, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A64E8(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88153DF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A6548: addr lbl_88D3CD50, fn_889A14B0, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889A6548(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889A14B0((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889A4E50((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889A65C0: tailcall fn_889A4E50 */
ts4_word ts4_tailcall_fn_889A4E50_889A65C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889A4E50((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889A65D8: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A14B0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A65D8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1084, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A14B0((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A6658: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88153D48, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A6658(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88153D48((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A66B8: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_extra_88153C90, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A66B8(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_extra_88153C90((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A6718: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88153BE0, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A6718(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88153BE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A6858: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_88153B30, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A6858(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_88153B30((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A68B8: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A15A0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A68B8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1084, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A15A0((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A6A20: get u32@g_ts4_session_context, u32@0xc, fn_88153A70, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A6A20(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88153A70((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A6A80: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A17C0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889A6A80(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1084, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A17C0((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889A6FA0: get u32@g_ts4_session_context, u32@0xc, ts4_flagged_object_create_extra_88153678, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_g_ts4_session_context_889A6FA0(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_flagged_object_create_extra_88153678((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3, (ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889A7440: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_889A7440(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889A7450: call_seq fn_88936BB0, fn_889395D8, fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_88936BB0_889A7450(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    t4 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    return t4;
}

/* Swing_DLL.xex 0x889A74B8: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_889A74B8(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889A74C8: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_889A74C8(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889A7558: get u32@g_ts4_session_state, fn_88938F38 */
ts4_word ts4_get_u32_g_ts4_session_state_889A7558(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88938F38((ts4_word)a1, (ts4_word)((*(ts4_word *)g_ts4_session_state) + 280), (ts4_word)8);
}

/* Swing_DLL.xex 0x889A76C8: call_seq fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_889395D8_889A76C8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
    t2 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    return t2;
}

/* Swing_DLL.xex 0x889A7718: call_seq fn_88939470, fn_889395D8, fn_88939470, fn_889395D8 */
ts4_word ts4_call_seq_fn_88939470_889A7718(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)8);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1076), (ts4_word)7);
    t4 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    return t4;
}

/* Swing_DLL.xex 0x889A8B30: call_seq fn_8893C990, fn_8893C990, fn_8893C990, fn_8893C990 */
ts4_word ts4_call_seq_fn_8893C990_889A8B30(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_8893C990((ts4_word)a1, (ts4_word)(a0 + 8));
    fn_8893C990((ts4_word)a1, (ts4_word)(a0 + 16));
    fn_8893C990((ts4_word)a1, (ts4_word)(a0 + 24));
    t4 = fn_8893C990((ts4_word)a1, (ts4_word)(a0 + 32));
    return t4;
}

/* Swing_DLL.xex 0x889ABDB0: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889A7620, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_889ABDB0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1460, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889A7620((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x889ABE68: if_call_seq u8@0x2c, fn_88937A00, fn_889A4FD0 */
ts4_word ts4_if_call_seq_u8_off2c_889ABE68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 44);
    if ((ts4_word)t1 != 0) {
        fn_88937A00((ts4_word)a0);
    }
    t4 = fn_889A4FD0((ts4_word)a0, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x889AC588: if_call_seq u32@g_ts4_session_state, fn_88154230, u32@g_ts4_session_state, fn_88151560 */
ts4_word ts4_if_call_seq_u32_g_ts4_session_state_889AC588(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = fn_88154230((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)((875823104) | 18339));
        t4 = fn_88151560((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)t2);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x889ACB20: tailcall fn_889ABE30 */
ts4_word ts4_tailcall_fn_889ABE30_889ACB20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889ABE30((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889ACC20: addr lbl_88D3CD50, fn_889A15A0, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889ACC20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889A15A0((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889AC4B0((ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889ADF38: call_seq fn_8893AFB0, fn_889395D8 */
ts4_word ts4_call_seq_fn_8893AFB0_889ADF38(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8893AFB0();
    t2 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 100));
    return t2;
}

/* Swing_DLL.xex 0x889ADF80: call_seq fn_8893B080, u32@g_ts4_session_context, u32@0x3c, u32@0x84c, fn_889396A8 */
ts4_word ts4_call_seq_fn_8893B080_889ADF80(ts4_word a0, ts4_word a1)
{
    ts4_word t5;

    (void)a0;
    fn_8893B080();
    t5 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60))) + 2124)));
    return t5;
}

/* Swing_DLL.xex 0x889AF370: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889AF370(ts4_word a0, ts4_word a1)
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

/* Swing_DLL.xex 0x889AF458: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889AF458(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t19;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1076)));
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1084)));
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1088)));
    t19 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1092)));
    return t19;
}

/* Swing_DLL.xex 0x889AF560: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889AF560(ts4_word a0, ts4_word a1)
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

/* Swing_DLL.xex 0x889AF640: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889AF640(ts4_word a0, ts4_word a1)
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

/* Swing_DLL.xex 0x889AF690: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889AF690(ts4_word a0, ts4_word a1)
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

/* Swing_DLL.xex 0x889AF7B8: tailcall ts4_get_u32_off0_8899AD88 */
ts4_word ts4_tailcall_fn_8899AD88_889AF7B8(ts4_word a0)
{
    return ts4_get_u32_off0_8899AD88((ts4_word)a0);
}

/* Swing_DLL.xex 0x889AF7C0: tailcall fn_881512B8 */
ts4_word ts4_tailcall_fn_881512B8_889AF7C0(ts4_word a0, ts4_word a1)
{
    return fn_881512B8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889AF7D0: tailcall fn_881512B8 */
ts4_word ts4_tailcall_fn_881512B8_889AF7D0(ts4_word a0)
{
    return fn_881512B8((ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889AFFA0: call_seq fn_88936BB0, fn_889395D8, fn_889395D8, fn_889A7818, u32@0x0, u32@0x438 */
ts4_word ts4_call_seq_fn_88936BB0_889AFFA0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t6;

    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    t4 = fn_889A7818((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1080) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    t6 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
    return t6;
}

/* Swing_DLL.xex 0x889B00C0: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889B00C0(ts4_word a0, ts4_word a1)
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
    t9 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    return t9;
}

/* Swing_DLL.xex 0x889B0450: call_seq fn_889395D8, fn_889395D8, fn_88939470, fn_889395D8, u32@0x438 */
ts4_word ts4_call_seq_fn_889395D8_889B0450(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
    t2 = fn_889395D8((ts4_word)t1, (ts4_word)(a0 + 1072));
    t3 = fn_88939470((ts4_word)t2, (ts4_word)(a0 + 1076), (ts4_word)2);
    loc50[0] = (ts4_word)0;
    t4 = fn_889395D8((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 1080) = (ts4_word)t5;
    return t4;
}

/* Swing_DLL.xex 0x889B0690: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_889B0690(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t15;
    ts4_word t17;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t9 = fn_889396A8((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    t11 = fn_889396A8((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1076)));
    t13 = fn_889396A8((ts4_word)t11, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1080)));
    t15 = fn_889396A8((ts4_word)t13, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1084)));
    t17 = fn_889396A8((ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1088)));
    return t17;
}

/* Swing_DLL.xex 0x889B0808: tailcall fn_8899ADF8 */
ts4_word ts4_tailcall_fn_8899ADF8_889B0808(ts4_word a0)
{
    return fn_8899ADF8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889B0AB8: addr lbl_880D0533, fn_889A7D38 */
ts4_word ts4_addr_lbl_880D0533_889B0AB8(void)
{
    return fn_889A7D38((ts4_word)(ts4_word)lbl_880D0533);
}

/* Swing_DLL.xex 0x889B0AC8: addr lbl_880D0532, fn_889A7D38 */
ts4_word ts4_addr_lbl_880D0532_889B0AC8(void)
{
    return fn_889A7D38((ts4_word)(ts4_word)lbl_880D0532);
}

/* Swing_DLL.xex 0x889B0C80: addr lbl_88D3CD50, fn_889A7620, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889B0C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889A7620((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889B0AD8((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889B0CF8: tailcall fn_889B0AD8 */
ts4_word ts4_tailcall_fn_889B0AD8_889B0CF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889B0AD8((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889B0D10: call_seq fn_8893CCE8, fn_88938F38, fn_88936BB0, fn_889395D8 */
ts4_word ts4_call_seq_fn_8893CCE8_889B0D10(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    fn_8893CCE8((ts4_word)a0, (ts4_word)a1);
    fn_88938F38((ts4_word)a1, (ts4_word)(a0 + 112), (ts4_word)8);
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 120));
    t4 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 128));
    return t4;
}

/* Swing_DLL.xex 0x889B0D70: call_seq fn_8899B2E8, u32@0x80, fn_889396A8 */
ts4_word ts4_call_seq_fn_8899B2E8_889B0D70(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8899B2E8((ts4_word)a0, (ts4_word)a1);
    t3 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)));
    return t3;
}

/* Swing_DLL.xex 0x889B11A0: addr lbl_880D2CF8, u32@0x0, fn_8893B3E0 */
ts4_word ts4_addr_lbl_880D2CF8_889B11A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D2CF8;
    return fn_8893B3E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880D2CF8);
}

/* Swing_DLL.xex 0x889B13A8: tailcall fn_8899B370 */
ts4_word ts4_tailcall_fn_8899B370_889B13A8(ts4_word a0)
{
    return fn_8899B370((ts4_word)a0);
}

/* Swing_DLL.xex 0x889B1400: call_seq lbl_880D0533, u32@lbl_88D45838, fn_889A7D38, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880D0533_889B1400(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)lbl_88D45838 = (ts4_word)0;
    fn_889A7D38((ts4_word)(ts4_word)lbl_880D0533);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x889B2850: if_call_seq u32@0xc, fn_8860DCF8, fn_889B11B0 */
ts4_word ts4_if_call_seq_u32_offc_889B2850(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)104, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889B11B0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x889B2B08: if_call_seq u32@0x0, fn_889B5A30, ts4_memset, u32@0xd4, u32@0x0, u32@0xa4 */
ts4_word ts4_if_call_seq_u32_off0_889B2B08(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word loc60[3];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    t2 = fn_889B5A30((ts4_word)a0, (ts4_word)12, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0);
    if ((ts4_word)(t2 & 0xff) == 0) {
        ts4_memset((ts4_word)(ts4_word)&loc60[0], (ts4_word)0, (ts4_word)12);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        loc58[0] = (ts4_word)17;
        loc58[1] = (ts4_word)(ts4_word)&loc60[0];
        t7 = *(ts4_word *)((char *)(ts4_word)(t4) + 1072);
        loc60[2] = (ts4_word)1;
        loc60[0] = (ts4_word)t5;
        loc60[1] = (ts4_word)t7;
        fn_889C0298((ts4_word)t6, (ts4_word)(ts4_word)&loc58[0]);
    }
    return 1;
}

/* Swing_DLL.xex 0x889B44D8: call_seq u8@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_call_seq_u8_off4_889B44D8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 88) = (ts4_u64)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    ts4_memset((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)16);
    ts4_memset((ts4_word)(a0 + 52), (ts4_word)0, (ts4_word)16);
    ts4_memset((ts4_word)(a0 + 68), (ts4_word)0, (ts4_word)16);
    fn_889B4418((ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x889B5BE0: if_call_seq fn_889B5A30, u32@0xb0, u32@0xa4, fn_889C0298 */
ts4_word ts4_if_call_seq_fn_889B5A30_889B5BE0(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word loc58[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    t1 = fn_889B5A30((ts4_word)a0, (ts4_word)5, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0);
    p5 = (ts4_word)t1;
    if ((ts4_word)(t1 & 0xff) == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        loc58[0] = (ts4_word)0;
        loc58[1] = (ts4_word)(ts4_word)&loc50[0];
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        loc50[0] = (ts4_word)t2;
        t4 = fn_889C0298((ts4_word)t3, (ts4_word)(ts4_word)&loc58[0]);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x889BB770: addr lbl_88D3CD50, fn_889A17C0, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_889BB770(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    (void)a2;
    t1 = fn_889A17C0((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_889BAC88((ts4_word)a3, (ts4_word)t1);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x889BBD00: if_call_seq u32@0xc, fn_8860DCF8, fn_889BB7F0 */
ts4_word ts4_if_call_seq_u32_offc_889BBD00(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)212, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889BB7F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x889BC128: call_seq fn_88935C70, fn_8899B710, fn_889BBD50 */
ts4_word ts4_call_seq_fn_88935C70_889BC128(ts4_word a0)
{
    ts4_word t3;

    fn_88935C70((ts4_word)a0);
    fn_8899B710((ts4_word)a0);
    t3 = fn_889BBD50((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889BCA48: tailcall fn_88883CD0 */
ts4_word ts4_tailcall_fn_88883CD0_889BCA48(ts4_word a0)
{
    return fn_88883CD0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889BCA50: call_seq u32@lbl_88D3EB60, fn_8857A1E0, u32@lbl_88D3EB60 */
ts4_word ts4_call_seq_u32_lbl_88D3EB60_889BCA50(void)
{
    ts4_word t2;

    t2 = fn_8857A1E0((ts4_word)(*(ts4_word *)lbl_88D3EB60));
    *(ts4_word *)lbl_88D3EB60 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x889BCD88: if_call_seq lbl_880C1324, u32@lbl_88D45B20, u8@0xc, u8@0xc, fn_88608590, ts4_keyed_item_add_unique_889BCCD8 */
ts4_word ts4_if_call_seq_lbl_880C1324_889BCD88(void)
{
    ts4_word p11;
    ts4_word loc50[1];
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    unsigned char t9;
    ts4_word t10;

    t1 = *(ts4_word *)lbl_88D45B20;
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 12);
    *(unsigned char *)((char *)(ts4_word)(t1) + 12) = (unsigned char)1;
    t3 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880C1324);
    loc50[0] = (ts4_word)t3;
    ts4_keyed_item_add_unique_889BCCD8((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880C1334);
    loc50[0] = (ts4_word)t5;
    t7 = ts4_keyed_item_add_unique_889BCC28((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t9 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 630);
    p11 = (ts4_word)t7;
    if ((ts4_word)t9 != 0) {
        t10 = fn_889298D8((ts4_word)(ts4_word)lbl_880CFC4F);
        p11 = (ts4_word)t10;
    }
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B20)) + 12) = (unsigned char)t2;
    return p11;
}

/* Swing_DLL.xex 0x889BD310: call_seq lbl_880C13BC, u32@0x0, fn_8862F0B8, u32@0x2e4, u32@0x2e8, u32@0x2ec */
ts4_word ts4_call_seq_lbl_880C13BC_889BD310(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880C13BC;
    fn_8862F0B8((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 740) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 744) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 748) = (ts4_word)0;
    *(ts4_word *)lbl_88D45834 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x889BD368: tailcall fn_888892A8 */
ts4_word ts4_tailcall_fn_888892A8_889BD368(ts4_word a0)
{
    return fn_888892A8((ts4_word)(a0 + 740));
}

/* Swing_DLL.xex 0x889BD9E8: call_seq u32@0x0, u32@0x0, fn_8857A1E0, ts4_msg_pool_service_get_8864DFF0, fn_888860A0, ts4_msg_pool_service_get_8864DFF0 */
ts4_word ts4_call_seq_u32_off0_889BD9E8(ts4_word a0)
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

/* Swing_DLL.xex 0x889BDB18: call_seq fn_8864B268 */
ts4_word ts4_call_seq_fn_8864B268_889BDB18(ts4_word a0, ts4_word a1)
{
    fn_8864B268((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Swing_DLL.xex 0x889BDB70: if_call_seq fn_8864B468, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8864B468_889BDB70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_8864B468();
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x889BFAB8: if_call_seq fn_889BD910, u32@0x0, u16@0xc, u32@0x10, fn_8864BBB0 */
ts4_word ts4_if_call_seq_fn_889BD910_889BFAB8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_889BD910((ts4_word)2, (ts4_word)0);
    if ((ts4_word)t1 == 0) {
        p4 = (ts4_word)-1;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        *(unsigned short *)((char *)(ts4_word)(t1) + 12) = (unsigned short)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)t2;
        fn_8864BBB0((ts4_word)a0, (ts4_word)t1);
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x889BFB28: call_seq ts4_if_call_seq_u32_off0_8864BC08, u8@0x234 */
ts4_word ts4_call_seq_fn_8864BC08_889BFB28(ts4_word a0)
{
    ts4_if_call_seq_u32_off0_8864BC08((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x889C0838: call_seq fn_8864C170, u32@0x7c, u8@0x234 */
ts4_word ts4_call_seq_fn_8864C170_889C0838(ts4_word a0)
{
    fn_8864C170((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)a0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x889C08E8: call_seq fn_8864B268 */
ts4_word ts4_call_seq_fn_8864B268_889C08E8(ts4_word a0, ts4_word a1)
{
    fn_8864B268((ts4_word)a0, (ts4_word)a1);
    return 0;
}

/* Swing_DLL.xex 0x889C09D0: tailcall ts4_if_call_seq_fn_889BD910_889BFB60 */
ts4_word ts4_tailcall_fn_889BFB60_889C09D0(ts4_word a0)
{
    return ts4_if_call_seq_fn_889BD910_889BFB60((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C09D8: tailcall ts4_if_call_seq_fn_889BD910_889BFBD0 */
ts4_word ts4_tailcall_fn_889BFBD0_889C09D8(ts4_word a0)
{
    return ts4_if_call_seq_fn_889BD910_889BFBD0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C09E0: tailcall fn_889BE668 */
ts4_word ts4_tailcall_fn_889BE668_889C09E0(ts4_word a0)
{
    return fn_889BE668((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C09E8: call_seq ts4_if_call_seq_u32_off0_8864BC08, u8@0x234 */
ts4_word ts4_call_seq_fn_8864BC08_889C09E8(ts4_word a0)
{
    ts4_if_call_seq_u32_off0_8864BC08((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x889C0A20: tailcall fn_889BFDA8 */
ts4_word ts4_tailcall_fn_889BFDA8_889C0A20(ts4_word a0)
{
    return fn_889BFDA8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C0A28: tailcall fn_889C0298 */
ts4_word ts4_tailcall_fn_889C0298_889C0A28(ts4_word a0)
{
    return fn_889C0298((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C0A30: tailcall ts4_if_call_seq_fn_889BD910_889C0778 */
ts4_word ts4_tailcall_fn_889C0778_889C0A30(ts4_word a0)
{
    return ts4_if_call_seq_fn_889BD910_889C0778((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C0A38: tailcall fn_889BFC40 */
ts4_word ts4_tailcall_fn_889BFC40_889C0A38(ts4_word a0)
{
    return fn_889BFC40((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C0AD8: tailcall fn_889C0878 */
ts4_word ts4_tailcall_fn_889C0878_889C0AD8(ts4_word a0)
{
    return fn_889C0878((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C2AC0: call_seq u32@0x24, u32@0x20, u32@0x2c, lbl_880D7570, u32@0x0, fn_88616758 */
ts4_word ts4_call_seq_u32_off24_889C2AC0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7570;
    t4 = fn_88616758((ts4_word)t3, (ts4_word)t2, (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    return t4;
}

/* Swing_DLL.xex 0x889C3868: tailcall fn_889122D8 */
ts4_word ts4_tailcall_fn_889122D8_889C3868(ts4_word a0)
{
    return fn_889122D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C53A0: call_seq fn_88616A70, fn_88177110, fn_88912090 */
ts4_word ts4_call_seq_fn_88616A70_889C53A0(ts4_word a0)
{
    ts4_word t3;

    fn_88616A70((ts4_word)(a0 + 32));
    fn_88177110((ts4_word)(a0 + 8));
    t3 = fn_88912090((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x889C5548: tailcall fn_889122D8 */
ts4_word ts4_tailcall_fn_889122D8_889C5548(ts4_word a0)
{
    return fn_889122D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C5660: call_seq fn_88177110, fn_88912090 */
ts4_word ts4_call_seq_fn_88177110_889C5660(ts4_word a0)
{
    ts4_word t2;

    fn_88177110((ts4_word)(a0 + 8));
    t2 = fn_88912090((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x889C5698: call_seq ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73FC, u32@0x0 */
ts4_word ts4_call_seq_fn_88912AC0_889C5698(ts4_word a0)
{
    ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D73FC;
    return a0;
}

/* Swing_DLL.xex 0x889C58F8: tailcall fn_889122D8 */
ts4_word ts4_tailcall_fn_889122D8_889C58F8(ts4_word a0)
{
    return fn_889122D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C5900: if_call_seq u32@0x0, u32@0x8, u32@0x0, u32@0x8, fn_889C6888 */
ts4_word ts4_if_call_seq_u32_off0_889C5900(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 < (int)t3) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t2 + 4);
    }
    loc50[0] = (ts4_word)123;
    fn_889C6888((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return 0;
}

/* Swing_DLL.xex 0x889C5AF8: call_seq fn_88177110, fn_88912090 */
ts4_word ts4_call_seq_fn_88177110_889C5AF8(ts4_word a0)
{
    ts4_word t2;

    fn_88177110((ts4_word)(a0 + 8));
    t2 = fn_88912090((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x889C5B30: call_seq ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D73C4, u32@0x0 */
ts4_word ts4_call_seq_fn_88912AC0_889C5B30(ts4_word a0)
{
    ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D73C4;
    return a0;
}

/* Swing_DLL.xex 0x889C5B80: if_get u32@lbl_88D45910, u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_lbl_88D45910_889C5B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45910;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x889C5D88: tailcall fn_889122D8 */
ts4_word ts4_tailcall_fn_889122D8_889C5D88(ts4_word a0)
{
    return fn_889122D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C5D90: call_seq fn_888F70A0 */
ts4_word ts4_call_seq_fn_888F70A0_889C5D90(void)
{
    fn_888F70A0();
    return 0;
}

/* Swing_DLL.xex 0x889C5DB8: call_seq fn_88177110, fn_88912090 */
ts4_word ts4_call_seq_fn_88177110_889C5DB8(ts4_word a0)
{
    ts4_word t2;

    fn_88177110((ts4_word)(a0 + 8));
    t2 = fn_88912090((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x889C5EC0: call_seq ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7380, u32@0x0 */
ts4_word ts4_call_seq_fn_88912AC0_889C5EC0(ts4_word a0)
{
    ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7380;
    return a0;
}

/* Swing_DLL.xex 0x889C5F00: fn  */
ts4_word ts4_fn_889C5F00(void)
{
    return 0;
}

/* Swing_DLL.xex 0x889C6098: tailcall fn_889122D8 */
ts4_word ts4_tailcall_fn_889122D8_889C6098(ts4_word a0)
{
    return fn_889122D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C6138: call_seq fn_88177110, fn_88912090 */
ts4_word ts4_call_seq_fn_88177110_889C6138(ts4_word a0)
{
    ts4_word t2;

    fn_88177110((ts4_word)(a0 + 8));
    t2 = fn_88912090((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x889C6170: call_seq ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880D7310, u32@0x0 */
ts4_word ts4_call_seq_fn_88912AC0_889C6170(ts4_word a0)
{
    ts4_call_seq_lbl_880D72B0_88912AC0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7310;
    return a0;
}

/* Swing_DLL.xex 0x889C61B0: get u32@0x0 */
ts4_word ts4_get_u32_off0_889C61B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x889C61B8: get u32@0x0 */
ts4_word ts4_get_u32_off0_889C61B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x889C6310: get u32@0x0, u32@0x8, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_get_u32_off0_889C6310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)20;
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)20;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)a3;
    return;
}

/* Swing_DLL.xex 0x889C65C0: if_call_seq u32@0x0, fn_888860A0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_889C65C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x889C6600: if_call_seq u32@0x4, u32@0x0, u32@0x8, fn_889C64C0, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off4_889C6600(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_889C64C0((ts4_word)a0);
    if ((ts4_word)a1 != (ts4_word)((4241948672) | 16366)) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)20;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)20;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)a3;
    }
    return a0;
}

/* Swing_DLL.xex 0x889C6AB0: call_seq u8@0x0, fn_889C6888 */
ts4_word ts4_call_seq_u8_off0_889C6AB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;

    loc50[0] = (ts4_word)((*(unsigned char *)((char *)(ts4_word)(a1) + 0)) != 0);
    t2 = fn_889C6888((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x889C6FE0: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off0_889C6FE0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        return (((*(ts4_word *)((char *)(ts4_word)(t2) + 4)) - t3) == 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x889C7010: if_call_seq u32@0x4, fn_888860A0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_889C7010(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x889C7560: call_seq lbl_880CDC02, u32@lbl_88D45B20, ts4_keyed_item_add_or_remove_889C30B8, u32@lbl_88D45B20, ts4_keyed_item_add_or_remove_889C5818, u32@lbl_88D45B20 */
ts4_word ts4_call_seq_lbl_880CDC02_889C7560(void)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;

    loc50[0] = (ts4_word)((4016570368) | 61677);
    ts4_keyed_item_add_or_remove_889C30B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDC02);
    t3 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((4190765056) | 37994);
    ts4_keyed_item_add_or_remove_889C5818((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDC02);
    t5 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((4195352576) | 31643);
    ts4_keyed_item_add_or_remove_889C5468((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDC02);
    t7 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((632029184) | 32192);
    ts4_keyed_item_add_or_remove_889C5BC0((ts4_word)t7, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDC02);
    t9 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((2838298624) | 33820);
    t10 = ts4_keyed_item_add_or_remove_889C5F18((ts4_word)t9, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDC02);
    return t10;
}

/* Swing_DLL.xex 0x889C7628: call_seq lbl_880CDBB7, u32@lbl_88D45B20, ts4_keyed_item_add_or_remove_889C30B8, u32@lbl_88D45B20, ts4_keyed_item_add_or_remove_889C5818, u32@lbl_88D45B20 */
ts4_word ts4_call_seq_lbl_880CDBB7_889C7628(void)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;

    loc50[0] = (ts4_word)((4016570368) | 61677);
    ts4_keyed_item_add_or_remove_889C30B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDBB7);
    t3 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((4190765056) | 37994);
    ts4_keyed_item_add_or_remove_889C5818((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDBB7);
    t5 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((4195352576) | 31643);
    ts4_keyed_item_add_or_remove_889C5468((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDBB7);
    t7 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((632029184) | 32192);
    ts4_keyed_item_add_or_remove_889C5BC0((ts4_word)t7, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDBB7);
    t9 = *(ts4_word *)lbl_88D45B20;
    loc50[0] = (ts4_word)((2838298624) | 33820);
    t10 = ts4_keyed_item_add_or_remove_889C5F18((ts4_word)t9, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CDBB7);
    return t10;
}

/* Swing_DLL.xex 0x889C92A0: tailcall fn_889C8148 */
ts4_word ts4_tailcall_fn_889C8148_889C92A0(ts4_word a0)
{
    return fn_889C8148((ts4_word)a0);
}

/* Swing_DLL.xex 0x889CE958: call_seq fn_88823320, fn_88823320 */
ts4_word ts4_call_seq_fn_88823320_889CE958(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    fn_88823320((ts4_word)a0, (ts4_word)1, (ts4_word)a1);
    t2 = fn_88823320((ts4_word)a0, (ts4_word)1, (ts4_word)a2);
    return t2;
}

/* Swing_DLL.xex 0x889CF610: call_seq fn_88824188, lbl_880E23A0, fn_88823FC0, lbl_880E23D8, fn_88823FC0 */
ts4_word ts4_call_seq_fn_88824188_889CF610(ts4_word a0)
{
    fn_88824188((ts4_word)a0);
    fn_88823FC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E23A0, (ts4_word)54);
    fn_88823FC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E23D8, (ts4_word)6);
    return 3;
}

/* Swing_DLL.xex 0x889CFB18: call_seq ts4_lua_opt_number_default_8882EA98, fn_88565118, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFB18(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88565118((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFB58: call_seq ts4_lua_opt_number_default_8882EA98, fn_885640B0, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFB58(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_885640B0((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFB98: call_seq ts4_lua_opt_number_default_8882EA98, fn_88563F20, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFB98(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88563F20((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFCD8: call_seq ts4_lua_opt_number_default_8882EA98, fn_88564430, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFCD8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88564430((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFD18: call_seq ts4_lua_opt_number_default_8882EA98, fn_88564D28, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFD18(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88564D28((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFDB8: call_seq ts4_lua_opt_number_default_8882EA98, fn_88564B10, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFDB8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88564B10((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFDF8: call_seq ts4_lua_opt_number_default_8882EA98, ts4_tailcall_fn_88569A10_88569BD0, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFDF8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    ts4_tailcall_fn_88569A10_88569BD0((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFE38: call_seq ts4_lua_opt_number_default_8882EA98, fn_88569B08, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFE38(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88569B08((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x889CFE78: call_seq ts4_lua_opt_number_default_8882EA98, fn_88565040, fn_888240B8 */
ts4_word ts4_call_seq_fn_8882EA98_889CFE78(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_lua_opt_number_default_8882EA98((ts4_word)a0, (ts4_word)1);
    fn_88565040((ts4_word)t1);
    fn_888240B8((ts4_word)a0);
    return 1;
}
