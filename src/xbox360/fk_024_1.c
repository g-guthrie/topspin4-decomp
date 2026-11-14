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

extern char fn_886171D8[];
extern char fn_8861D6A8[];
extern char ts4_forward_with_global_and_one_88894B08[];
extern char fn_88894B30[];
extern char ts4_forward_with_global_and_one_88894B58[];
extern char fn_88894B80[];
extern char ts4_addr_lbl_880CF238_88895140[];
extern char ts4_get_u32_off11c_888A43C0[];
extern char lbl_880CB0B8[];
extern char lbl_880CF238[];
extern char lbl_880CF3A8[];
extern char lbl_880CF518[];
extern char lbl_880D1E64[];
extern char lbl_880D3A48[];
extern char lbl_880DB2A4[];
extern char lbl_880DCE14[];
extern char lbl_880DEF10[];
extern char lbl_880DF1F8[];
extern char lbl_880DF220[];
extern char lbl_880DF380[];
extern char lbl_880DF40C[];
extern char lbl_880DFDB4[];
extern char lbl_880DFDCC[];
extern char lbl_880DFDDC[];
extern char lbl_880DFDEC[];
extern char lbl_880DFE00[];
extern char lbl_880DFE10[];
extern char lbl_880E0660[];
extern char lbl_880F6400[];
extern char lbl_8814B440[];
extern char lbl_88C46F6A[];
extern char lbl_88C6A444[];
extern char lbl_88C6AEF0[];
extern char lbl_88C6B8E0[];
extern char lbl_88C6BDF8[];
extern char lbl_88C6BE08[];
extern char lbl_88C6BE38[];
extern char lbl_88C6BE58[];
extern char lbl_88C6BE68[];
extern char lbl_88CACF08[];
extern char lbl_88D3EB60[];
extern char lbl_88D45908[];
extern char lbl_88D45918[];
extern char lbl_88D459D0[];
extern char lbl_88D459D4[];
extern char lbl_88D459DC[];
extern char lbl_88D459E8[];
extern char lbl_88D45A04[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B34[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
extern char ts4_noop_88605E88[];
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlInitializeCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word XNotifyGetNext();
ts4_word fn_88163990();
ts4_word fn_8816C930();
ts4_word fn_8816CAA0();
ts4_word fn_8816D1A8();
ts4_word fn_881A6A00();
ts4_word fn_881A7A20();
ts4_word fn_881A7B98();
ts4_word fn_881A7FF8();
ts4_word fn_881A84E8();
ts4_word fn_881A88D8();
ts4_word fn_881A8AB0();
ts4_word fn_881A8D28();
ts4_word fn_881A9BE8();
ts4_word fn_881AB108();
ts4_word fn_881B9148();
ts4_word fn_88419DE8();
ts4_word fn_8841B5E0();
ts4_word fn_8841BA98();
ts4_word fn_8857A1E0();
ts4_word fn_8857B6D8();
ts4_word fn_88608590();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88617D88();
ts4_word fn_8861B128();
ts4_word fn_886220F8();
ts4_word fn_8862EA10();
ts4_word fn_88638FC8();
ts4_word fn_887EB4A0();
ts4_word ts4_member_field_addr_8883B318();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_88854258();
ts4_word fn_8885B210();
ts4_word fn_8885BA18();
ts4_word fn_8885D370();
ts4_word fn_8885E268();
ts4_word fn_8885EDD8();
ts4_word fn_8885F268();
ts4_word fn_8885F628();
ts4_word fn_88863348();
ts4_word fn_88865028();
ts4_word fn_88865708();
ts4_word fn_88865AB0();
ts4_word fn_88865F70();
ts4_word fn_88866D00();
ts4_word fn_88868A88();
ts4_word fn_888690F0();
ts4_word fn_88869530();
ts4_word fn_8886A350();
ts4_word ts4_loop_call_seq_u32_off30_8886B150();
ts4_word fn_88870AC0();
ts4_word fn_88871368();
ts4_word fn_88871810();
ts4_word ex3_init_block_88873058();
ts4_word ex3_deflateInit2__88877400();
ts4_word fn_888860A0();
ts4_word fn_88889F50();
ts4_word fn_888905C0();
ts4_word ts4_loop_get_u32_off8_88890670();
ts4_word fn_88890AE0();
ts4_word fn_88890CB0();
ts4_word fn_88891030();
ts4_word ts4_xmltok_normal_update_position_88892AD0();
ts4_word ts4_xmltok_get_encoding_index_88894BA8();
ts4_word ts4_xmltok_init_unknown_encoding_88899C70();
ts4_word fn_888A4B00();
ts4_word fn_888A4BE0();
ts4_word fn_888A73D8();
ts4_word fn_888A81F8();
ts4_word ts4_if_get_u8_offec_888A8610();
ts4_word fn_888A8778();
ts4_word fn_888AA1C8();
ts4_word fn_888B1488();
ts4_word fn_888B14F0();
ts4_word fn_888B1628();
ts4_word ts4_store_scaled_ratio_and_update_888C1990();
ts4_word fn_888F67B8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_copy_bytes();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_keyed_item_list_add_unique_88866FA8();
ts4_word ts4_keyed_item_list_add_unique_888671B0();
ts4_word ts4_keyed_item_list_add_unique_88867260();
ts4_word ts4_keyed_item_list_add_unique_88867388();
ts4_word ts4_keyed_item_list_add_unique_88867438();
ts4_word ts4_keyed_item_list_add_unique_888674E8();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88899AA8: if_call_seq ts4_xmltok_get_encoding_index_88894BA8, u8@0x49, u32@0x4c, fn_88894B30, ts4_forward_with_global_and_one_88894B08, ts4_addr_lbl_880CF238_88895140 */
ts4_word ts4_if_call_seq_fn_88894BA8_88899AA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_xmltok_get_encoding_index_88894BA8((ts4_word)a2);
    if ((int)t1 == -1) {
        p2 = (ts4_word)0;
    } else {
        *(unsigned char *)((char *)(ts4_word)(a0) + 73) = (unsigned char)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88894B30;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)ts4_forward_with_global_and_one_88894B08;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(ts4_word)ts4_addr_lbl_880CF238_88895140;
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
        p2 = (ts4_word)1;
    }
    return p2;
}

/* Swing_DLL.xex 0x88899BF0: if_call_seq ts4_xmltok_get_encoding_index_88894BA8, u8@0x49, u32@0x4c, fn_88894B80, ts4_forward_with_global_and_one_88894B58, ts4_addr_lbl_880CF238_88895140 */
ts4_word ts4_if_call_seq_fn_88894BA8_88899BF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    ts4_word t1;

    t1 = ts4_xmltok_get_encoding_index_88894BA8((ts4_word)a2);
    if ((int)t1 == -1) {
        p2 = (ts4_word)0;
    } else {
        *(unsigned char *)((char *)(ts4_word)(a0) + 73) = (unsigned char)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88894B80;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)ts4_forward_with_global_and_one_88894B58;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(ts4_word)ts4_addr_lbl_880CF238_88895140;
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
        p2 = (ts4_word)1;
    }
    return p2;
}

/* Swing_DLL.xex 0x888A4D58: if_get u32@0x18, u32@0x1c, u32@0x24, u32@0x118, u32@0x128, u32@0x1c */
ts4_word ts4_if_get_u32_off18_888A4D58(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t2 + a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(t3 + a1);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t4))((ts4_word)a0, (ts4_word)t1, (ts4_word)(t2 + a1), (ts4_word)0, (ts4_word)(t3 + a1));
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)t5;
    if ((int)t5 == 0) {
        return 1;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 288);
    *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)ts4_get_u32_off11c_888A43C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)t6;
    return 0;
}

/* Swing_DLL.xex 0x888A8848: if_call_seq ts4_if_get_u8_offec_888A8610, fn_888A8778, u32@0x118, fn_888A8778 */
ts4_word ts4_if_call_seq_fn_888A8610_888A8848(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_if_get_u8_offec_888A8610((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)fn_888A8778;
        t2 = fn_888A8778((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x888AA518: if_call_seq ts4_if_get_u8_offec_888A8610, fn_888AA1C8, u32@0x118, fn_888AA1C8 */
ts4_word ts4_if_call_seq_fn_888A8610_888AA518(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_if_get_u8_offec_888A8610((ts4_word)a0);
    p3 = (ts4_word)t1;
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)fn_888AA1C8;
        t2 = fn_888AA1C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p3 = (ts4_word)t2;
    }
    return p3;
}

