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
extern char ts4_if_call_seq_fn_88894BA8_88899AA8[];
extern char ts4_if_call_seq_fn_88894BA8_88899BF0[];
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
ts4_word ts4_if_call_seq_u32_off4_88865028();
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
ts4_word ts4_if_get_u32_off18_888A4D58();
ts4_word fn_888A73D8();
ts4_word fn_888A81F8();
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

/* Swing_DLL.xex 0x88857A68: call_seq u32@lbl_88D459E8, u32@0x24, u32@0x38, u32@0xd20, fn_88854258 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88857A68(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88D459E8;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 56);
    fn_88854258((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 3360)));
    return 0;
}

/* Swing_DLL.xex 0x88857AA0: call_seq u32@lbl_88D459D4, ts4_loop_call_seq_u32_off30_8886B150, u32@lbl_88D459D4, ts4_loop_call_seq_u32_off30_8886B150 */
ts4_word ts4_call_seq_u32_lbl_88D459D4_88857AA0(void)
{
    ts4_loop_call_seq_u32_off30_8886B150((ts4_word)(*(ts4_word *)lbl_88D459D4), (ts4_word)((55902208) | 14141), (ts4_word)1);
    ts4_loop_call_seq_u32_off30_8886B150((ts4_word)(*(ts4_word *)lbl_88D459D4), (ts4_word)((55902208) | 14141), (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x8885D8F8: get u32@0x24, u32@0x128, fn_8885D370 */
ts4_word ts4_get_u32_off24_8885D8F8(ts4_word a0)
{
    return fn_8885D370((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 296)));
}

/* Swing_DLL.xex 0x8885E810: call_seq ts4_member_field_addr_8883B318, u32@0x60, u32@0x64, fn_8885E268 */
ts4_word ts4_call_seq_fn_8883B318_8885E810(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = ts4_member_field_addr_8883B318((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 96);
    t4 = fn_8885E268((ts4_word)a0, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 100)), (ts4_word)t1, (ts4_word)0);
    return t4;
}

/* Swing_DLL.xex 0x8885EB30: call_seq u32@lbl_88D459E8, fn_8885BA18 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8885EB30(void)
{
    fn_8885BA18((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8885EB60: call_seq u32@lbl_88D459E8, u32@0x44, fn_8885B210 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8885EB60(void)
{
    fn_8885B210((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 68)));
    return 0;
}

/* Swing_DLL.xex 0x8885EBE0: call_seq u32@lbl_88D459E8, u32@0x24, u32@0x128, fn_8885D370 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8885EBE0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D459E8;
    fn_8885D370((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 36))) + 296)));
    return 0;
}

/* Swing_DLL.xex 0x88862328: get u32@0x38, fn_8885F628 */
ts4_word ts4_get_u32_off38_88862328(ts4_word a0)
{
    return fn_8885F628((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
}

/* Swing_DLL.xex 0x88862330: get u32@0x40, fn_8885F268 */
ts4_word ts4_get_u32_off40_88862330(ts4_word a0)
{
    return fn_8885F268((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
}

/* Swing_DLL.xex 0x88862848: call_seq u32@lbl_88D459E8, u32@0x40, fn_8885F268 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88862848(void)
{
    fn_8885F268((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 64)));
    return 0;
}

/* Swing_DLL.xex 0x88862878: call_seq u32@lbl_88D459E8, u32@0x3c, fn_8885EDD8 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88862878(void)
{
    fn_8885EDD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 60)));
    return 0;
}

/* Swing_DLL.xex 0x88863CD0: call_seq u32@lbl_88D459E8, fn_88863348 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88863CD0(void)
{
    fn_88863348((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88864AE8: fn  */
ts4_word ts4_fn_88864AE8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88864AF0: fn  */
ts4_word ts4_fn_88864AF0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88864B80: tailcall ts4_copy_bytes */
ts4_word ts4_tailcall_ts4_copy_bytes_88864B80(ts4_word a0, ts4_word a1)
{
    return ts4_copy_bytes((ts4_word)a1, (ts4_word)(a0 + 18), (ts4_word)3);
}

/* Swing_DLL.xex 0x88864B98: call_seq ts4_copy_bytes, ts4_copy_bytes, ts4_copy_bytes, ts4_copy_bytes, ts4_copy_bytes */
ts4_word ts4_call_seq_ts4_copy_bytes_88864B98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t5;

    ts4_copy_bytes((ts4_word)a1, (ts4_word)(a0 + 3), (ts4_word)4);
    ts4_copy_bytes((ts4_word)a2, (ts4_word)(a0 + 7), (ts4_word)2);
    ts4_copy_bytes((ts4_word)a3, (ts4_word)(a0 + 9), (ts4_word)2);
    ts4_copy_bytes((ts4_word)a4, (ts4_word)(a0 + 11), (ts4_word)2);
    t5 = ts4_copy_bytes((ts4_word)a5, (ts4_word)(a0 + 13), (ts4_word)2);
    return t5;
}

/* Swing_DLL.xex 0x88864C10: get u8@0x2 */
ts4_word ts4_get_u8_off2_88864C10(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 2));
}

/* Swing_DLL.xex 0x88864D20: if_call_seq ts4_memset, ts4_memset */
ts4_word ts4_if_call_seq_ts4_memset_88864D20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)308);
        p2 = (ts4_word)t1;
    }
    p4 = (ts4_word)p2;
    if ((ts4_word)a1 != 0) {
        t3 = ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)12);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88865230: set u32@0x4, u32@0x0, u32@0x8, u8@0xc, u8@0xd, u8@0xe */
void ts4_set_u32_off4_88865230(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 15) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 532) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 540) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 18) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 274) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x88865750: tailcall ts4_find_service */
ts4_word ts4_tailcall_ts4_find_service_88865750(void)
{
    return ts4_find_service((ts4_word)((3803054080) | 35129));
}

/* Swing_DLL.xex 0x88865F30: call_seq u32@lbl_88D45A04, fn_887EB4A0, ts4_object_finalize */
ts4_word ts4_call_seq_u32_lbl_88D45A04_88865F30(ts4_word a0)
{
    ts4_word t3;

    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(a0 + 68));
    t3 = ts4_object_finalize((ts4_word)(a0 + 68));
    return t3;
}

/* Swing_DLL.xex 0x88865FF0: call_seq u8@0x8, fn_881B9148, fn_881AB108 */
ts4_word ts4_call_seq_u8_off8_88865FF0(ts4_word a0)
{
    ts4_word t2;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = fn_881AB108((ts4_word)(a0 + 92));
    return t2;
}

/* Swing_DLL.xex 0x88866320: call_seq fn_88865708, ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_fn_88865708_88866320(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = fn_88865708((ts4_word)a0);
    ts4_object_finalize((ts4_word)(t1 + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t3 = fn_881B9148((ts4_word)(a0 + 16));
    return t3;
}

/* Swing_DLL.xex 0x88866480: call_seq fn_88617D88, lbl_880E0660, u32@0x0, u32@0x1c, u32@lbl_88D459D0 */
ts4_word ts4_call_seq_fn_88617D88_88866480(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E0660;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)lbl_88D459D0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88866908: if_get u32@0x21c, u32@0x278, u32@0x270, u32@0x278, u32@0x21c, u32@0x270 */
void ts4_if_get_u32_off21c_88866908(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 540);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 632) = (ts4_word)((2679439360) | 32595);
        *(ts4_word *)((char *)(ts4_word)(a1) + 624) = (ts4_word)((1654325248) | 40539);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a1) + 632) = (ts4_word)((3052863488) | 27058);
        *(ts4_word *)((char *)(ts4_word)(a1) + 624) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 540));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 656) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 544));
    *(ts4_word *)((char *)(ts4_word)(a1) + 260) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 13));
    *(ts4_word *)((char *)(ts4_word)(a1) + 264) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a1) + 268) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 272) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 14));
    *(ts4_word *)((char *)(ts4_word)(a1) + 276) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 15));
    *(ts4_word *)((char *)(ts4_word)(a1) + 628) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 532));
    return;
}

/* Swing_DLL.xex 0x88867058: call_seq u32@lbl_88D459DC, fn_88866D00, u32@lbl_88D459DC, fn_88865AB0 */
ts4_word ts4_call_seq_u32_lbl_88D459DC_88867058(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t4;

    fn_88866D00((ts4_word)(*(ts4_word *)lbl_88D459DC), (ts4_word)a0);
    t4 = fn_88865AB0((ts4_word)(*(ts4_word *)lbl_88D459DC), (ts4_word)0, (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x88867110: call_seq u32@lbl_88D45A04, fn_887EB4A0, ts4_object_finalize, u32@lbl_88D45A04, fn_887EB4A0, ts4_object_finalize */
ts4_word ts4_call_seq_u32_lbl_88D45A04_88867110(ts4_word a0)
{
    ts4_word t6;

    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(a0 + 68));
    ts4_object_finalize((ts4_word)(a0 + 68));
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(a0 + 80));
    t6 = ts4_object_finalize((ts4_word)(a0 + 80));
    return t6;
}

/* Swing_DLL.xex 0x88867160: call_seq ts4_if_call_seq_u32_off4_88865028, fn_88865F70 */
ts4_word ts4_call_seq_fn_88865028_88867160(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    ts4_if_call_seq_u32_off4_88865028((ts4_word)(a0 + 68), (ts4_word)a1);
    t2 = fn_88865F70((ts4_word)(a0 + 80), (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x888671A8: tailcall fn_88865F70 */
ts4_word ts4_tailcall_fn_88865F70_888671A8(ts4_word a0)
{
    return fn_88865F70((ts4_word)(a0 + 68));
}

/* Swing_DLL.xex 0x88867958: call_seq lbl_880DFDB4, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_888671B0, lbl_880DFDCC, fn_88608590 */
ts4_word ts4_call_seq_lbl_880DFDB4_88867958(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t18;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFDB4);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_888671B0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFDCC);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_88867260((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFDDC);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_88867388((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFDEC);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_888674E8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFE00);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88867438((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DFE10);
    loc50[0] = (ts4_word)t16;
    t18 = ts4_keyed_item_list_add_unique_88866FA8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t18;
}

/* Swing_DLL.xex 0x88867DA0: call_seq ts4_if_call_seq_u32_lbl_88D459E4_8883F238, fn_886220F8 */
ts4_word ts4_call_seq_fn_8883F238_88867DA0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    t2 = fn_886220F8((ts4_word)t1, (ts4_word)(a0 + 8));
    return t2;
}

/* Swing_DLL.xex 0x88869658: if_call_seq fn_88868A88, u8@0x85 */
ts4_word ts4_if_call_seq_fn_88868A88_88869658(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88868A88((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 133) = (unsigned char)a1;
    }
    return t1;
}

/* Swing_DLL.xex 0x888698E0: addr lbl_880D3A48, fn_8816C930 */
ts4_word ts4_addr_lbl_880D3A48_888698E0(ts4_word a0)
{
    return fn_8816C930((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D3A48, (ts4_word)((ts4_word)lbl_880D3A48 + 4));
}

/* Swing_DLL.xex 0x8886A018: if_call_seq fn_88869530, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88869530_8886A018(void)
{
    ts4_word t1;

    t1 = fn_88869530();
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
    }
    return t1;
}

/* Swing_DLL.xex 0x8886A048: if_call_seq fn_88869530, fn_888690F0 */
ts4_word ts4_if_call_seq_fn_88869530_8886A048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = fn_88869530();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888690F0((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x8886A4B8: tailcall fn_8886A350 */
ts4_word ts4_tailcall_fn_8886A350_8886A4B8(ts4_word a0, ts4_word a1)
{
    return fn_8886A350((ts4_word)a0, (ts4_word)a1, (ts4_word)((2594504704) | 24015));
}

/* Swing_DLL.xex 0x8886A988: addr lbl_880D1E64, fn_8816CAA0 */
ts4_word ts4_addr_lbl_880D1E64_8886A988(ts4_word a0)
{
    return fn_8816CAA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D1E64);
}

/* Swing_DLL.xex 0x8886FFE0: set u8@0x54, u32@0x58, u32@0x5c, u32@0x60, u32@0x64, u32@0x68 */
void ts4_set_u8_off54_8886FFE0(ts4_word a0)
{
    float t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 116) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888700D0: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off0_888700D0(ts4_word a0, ts4_word a1)
{
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)a0, (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 24), (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 36), (ts4_word)4);
    return 1;
}

/* Swing_DLL.xex 0x88870178: get u32@0x0, u32@0x10, vcall, u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off0_88870178(ts4_word a0, ts4_word a1)
{
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)a0, (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(a0 + 24), (ts4_word)12);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1, (ts4_word)(a0 + 36), (ts4_word)4);
    return 1;
}

/* Swing_DLL.xex 0x888704F0: set u32@0xc */
void ts4_set_u32_offc_888704F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88870B80: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_88870B80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88870BE8: call_seq u32@0x4, u32@0x0, fn_881A9BE8, u32@0x4 */
ts4_word ts4_call_seq_u32_off4_88870BE8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_881A9BE8((ts4_word)t1, (ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    return t3;
}

/* Swing_DLL.xex 0x88870F70: call_seq fn_88163990, u32@lbl_88D45B1C, u32@0x27c, u32@0x4c */
ts4_word ts4_call_seq_fn_88163990_88870F70(ts4_word a0)
{
    fn_88163990((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return a0;
}

/* Swing_DLL.xex 0x88870FC8: set u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_offc_88870FC8(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 0) = t1;
    *(float *)((char *)(ts4_word)(a0) + 4) = t1;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    return;
}

/* Swing_DLL.xex 0x88871030: set u32@0xc, u32@0x78, fn_881A7B98 */
ts4_word ts4_set_u32_offc_88871030(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return fn_881A7B98((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120)));
}

/* Swing_DLL.xex 0x88871440: if_call_seq u32@0x4, u32@0x0, fn_881A8D28, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off4_88871440(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_881A8D28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88871488: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_88871488(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888714B8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_888714B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888716B0: get u32@0x7c, fn_881A8AB0 */
ts4_word ts4_get_u32_off7c_888716B0(ts4_word a0, ts4_word a1)
{
    return fn_881A8AB0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124)));
}

/* Swing_DLL.xex 0x888716D0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_888716D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888716F0: call_seq u8@0x54, u32@0x58, u32@0x5c, u32@0x60, u32@0x64, u32@0x68 */
ts4_word ts4_call_seq_u8_off54_888716F0(ts4_word a0, ts4_word a1)
{
    float t1;
    ts4_word t7;

    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    t1 = *(float *)lbl_8814B440;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 116) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)-1;
    fn_88871368();
    fn_88870AC0((ts4_word)(a0 + 12), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_881A7B98((ts4_word)(a0 + 28), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120)));
    t7 = fn_881A8AB0((ts4_word)(a0 + 44), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124)));
    return t7;
}

/* Swing_DLL.xex 0x88871778: if_call_seq u32@0x48, ts4_destroy_owned_object, u32@0x3c, ts4_destroy_owned_object, u32@0x2c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off48_88871778(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p21;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_881A8D28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t16);
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p21 = (ts4_word)t19;
    if ((ts4_word)t19 != 0) {
        t20 = ts4_destroy_owned_object((ts4_word)t19);
        p21 = (ts4_word)t20;
    }
    return p21;
}

/* Swing_DLL.xex 0x88871928: call_seq fn_881A84E8, fn_881A7FF8, fn_881A7A20, fn_881A88D8, u8@0x54, u8@0x54 */
ts4_word ts4_call_seq_fn_881A84E8_88871928(ts4_word a0, ts4_word a1)
{
    ts4_word t14;

    fn_881A84E8();
    fn_881A7FF8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    fn_881A7A20((ts4_word)(a0 + 28), (ts4_word)(a1 + 28));
    fn_881A88D8((ts4_word)(a0 + 44), (ts4_word)(a1 + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 84));
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 96));
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 108));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(float *)((char *)(ts4_word)(a0) + 116) = (*(float *)((char *)(ts4_word)(a1) + 116));
    t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 124);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)t14;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    return t14;
}

/* Swing_DLL.xex 0x88871C30: call_seq fn_88871810, u32@0x84, u32@0x88, u32@0x8c */
ts4_word ts4_call_seq_fn_88871810_88871C30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = fn_88871810((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 140) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88873720: addr lbl_88C6A444, u16@0x16b8, u32@0xb38, u32@0xb18, u32@0xb24, u32@0xb30 */
ts4_word ts4_addr_lbl_88C6A444_88873720(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 5816) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2872) = (ts4_word)(ts4_word)lbl_88C6A444;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2840) = (ts4_word)(a0 + 148);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2852) = (ts4_word)(a0 + 2440);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2864) = (ts4_word)(a0 + 2684);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2848) = (ts4_word)((ts4_word)lbl_88C6A444 + -816);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2860) = (ts4_word)((ts4_word)lbl_88C6A444 + -20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 5820) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 5812) = (ts4_word)8;
    return ex3_init_block_88873058((ts4_word)a0, (ts4_word)8, (ts4_word)((ts4_word)lbl_88C6A444 + -20), (ts4_word)((ts4_word)lbl_88C6A444 + -816), (ts4_word)(a0 + 2684), (ts4_word)(a0 + 2440), (ts4_word)(a0 + 148), (ts4_word)0);
}

/* Swing_DLL.xex 0x888741C8: addr lbl_880CB0B8, u32@0x54, u32@0x50, u32@0x58, u32@0x4c */
void ts4_addr_lbl_880CB0B8_888741C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)9;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(ts4_word)lbl_880CB0B8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)((ts4_word)lbl_880CB0B8 + -2048);
    return;
}

/* Swing_DLL.xex 0x888776A8: tailcall ex3_deflateInit2__88877400 */
ts4_word ts4_tailcall_fn_88877400_888776A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ex3_deflateInit2__88877400((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)15, (ts4_word)8, (ts4_word)0, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88883C38: get u32@0x0 */
ts4_word ts4_get_u32_off0_88883C38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x88883CA0: tailcall RtlInitializeCriticalSection */
ts4_word ts4_tailcall_RtlInitializeCriticalSection_88883CA0(ts4_word a0)
{
    return RtlInitializeCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88883D48: addr lbl_88D3EB60 */
ts4_word ts4_addr_lbl_88D3EB60_88883D48(void)
{
    return (ts4_word)lbl_88D3EB60;
}

/* Swing_DLL.xex 0x88883D58: call_seq u32@lbl_88D3EB60, fn_8857A1E0, u32@lbl_88D3EB60 */
ts4_word ts4_call_seq_u32_lbl_88D3EB60_88883D58(void)
{
    ts4_word t2;

    t2 = fn_8857A1E0((ts4_word)(*(ts4_word *)lbl_88D3EB60));
    *(ts4_word *)lbl_88D3EB60 = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88883DD0: fn  */
ts4_word ts4_fn_88883DD0(void)
{
    return -2;
}

/* Swing_DLL.xex 0x88883ED0: fn  */
ts4_word ts4_fn_88883ED0(ts4_word a0)
{
    return ((short)a0);
}

/* Swing_DLL.xex 0x88883ED8: fn  */
ts4_word ts4_fn_88883ED8(ts4_word a0)
{
    return (a0 + 8);
}

/* Swing_DLL.xex 0x88883F18: tailcall fn_8857B6D8 */
ts4_word ts4_tailcall_fn_8857B6D8_88883F18(void)
{
    return fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88884190: tailcall ts4_memset */
ts4_word ts4_tailcall_ts4_memset_88884190(ts4_word a0, ts4_word a1)
{
    return ts4_memset((ts4_word)a0, (ts4_word)((signed char)a1));
}

/* Swing_DLL.xex 0x88884898: set u32@0x0 */
void ts4_set_u32_off0_88884898(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888848A8: if_get u32@0x1c, u32@0x0, u32@0x4c */
ts4_word ts4_if_get_u32_off1c_888848A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    return 0;
}

/* Swing_DLL.xex 0x888848D0: if_get u32@0x1c, u32@0x0, u32@0x44 */
ts4_word ts4_if_get_u32_off1c_888848D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 68))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    return 0;
}

/* Swing_DLL.xex 0x888848F8: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_888848F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x888849C0: fn  */
ts4_word ts4_fn_888849C0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x888849D8: if_get u32@lbl_88D45B1C, u32@0x2cc, lbl_88C6BE68 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_888849D8(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 716);
    if ((int)t2 == 0) {
        return (ts4_word)lbl_88C6BE68;
    }
    return (t2 + 10992);
}

/* Swing_DLL.xex 0x88884A00: get u16@0x0, u32@0x0, u16@0x2, u32@0x4, u16@0x4, u32@0x8 */
void ts4_get_u16_off0_88884A00(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 2));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 6));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 10));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 14));
    return;
}

/* Swing_DLL.xex 0x88884A48: tailcall RtlLeaveCriticalSection */
ts4_word ts4_tailcall_RtlLeaveCriticalSection_88884A48(ts4_word a0)
{
    return RtlLeaveCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88884A50: tailcall RtlEnterCriticalSection */
ts4_word ts4_tailcall_RtlEnterCriticalSection_88884A50(ts4_word a0)
{
    return RtlEnterCriticalSection((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88884BF8: set u8@0x0 */
void ts4_set_u8_off0_88884BF8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88885078: if_addr lbl_88C6BE68, u32@lbl_88D45B1C, u32@0x2cc, u32@0x1c, u32@0x24c, u32@0x248 */
ts4_word ts4_if_addr_lbl_88C6BE68_88885078(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word p10;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;
    ts4_word t15;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 716);
    if ((int)t2 == 0) {
        p3 = (ts4_word)(ts4_word)lbl_88C6BE68;
    } else {
        p3 = (ts4_word)(t2 + 10992);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(p3) + 28);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 588);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t4))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 584)), (ts4_word)t5, (ts4_word)0, (ts4_word)0);
    t8 = *(ts4_word *)lbl_88D45B1C;
    loc50[0] = (ts4_word)0;
    t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 716);
    if ((int)t9 == 0) {
        p10 = (ts4_word)(ts4_word)lbl_88C6BE68;
    } else {
        p10 = (ts4_word)(t9 + 10992);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(p10) + 36);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t11))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 584)), (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 588);
    t15 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 588) = (ts4_word)(t14 + t15);
    return t15;
}

/* Swing_DLL.xex 0x888851A0: set u32@0x4, u32@0x8, u32@0x18, lbl_880DF220, u32@0xc, u8@0x10 */
void ts4_set_u32_off4_888851A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF220;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 540) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 548) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 552) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 560) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 564) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 576) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 580) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 584) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 588) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 592) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 596) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 620) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 608) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 612) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 616) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x88885300: get u32@0x258, fn_8857A1E0 */
ts4_word ts4_get_u32_off258_88885300(ts4_word a0)
{
    return fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 600)));
}

/* Swing_DLL.xex 0x88886338: set u32@0x8, u8@0xc, u8@0x14 */
void ts4_set_u32_off8_88886338(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888864B8: if_get u32@0x250, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off250_888864B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 592))) + 0) = (ts4_word)((2619080704) | 37749);
    if ((ts4_word)a1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x888864E0: get u32@0x1c, u32@lbl_88D45B1C, u32@0x234, fn_88614938 */
ts4_word ts4_get_u32_off1c_888864E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x888864F8: if_call_seq u32@0x1c, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off1c_888864F8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t1);
    if ((ts4_word)t4 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t4) + 16));
    }
    return -1;
}

/* Swing_DLL.xex 0x888866A0: call_seq fn_88617D88, lbl_880DF40C, u32@0x3c, u32@0x0, u8@0x40 */
ts4_word ts4_call_seq_fn_88617D88_888866A0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF40C;
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88886900: call_seq u32@0x40, ts4_tsu_cleanup_end, u32@0x40 */
ts4_word ts4_call_seq_u32_off40_88886900(ts4_word a0)
{
    ts4_word t2;

    t2 = ts4_tsu_cleanup_end((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x88886B68: get u32@0x14f4, u32@0x4, vcall, u32@0x8, u8@0xc, u8@0x14 */
ts4_word ts4_get_u32_off14f4_88886B68(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5364))) + 4))))((ts4_word)(a0 + 5364));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 20) = (unsigned char)0;
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5364))) + 8))))((ts4_word)(a0 + 5364));
    return t6;
}

/* Swing_DLL.xex 0x88887AD8: call_seq fn_88617D88, lbl_880DF1F8, u32@0x250, u32@0x0, u8@0x4d, u8@0x25d */
ts4_word ts4_call_seq_fn_88617D88_88887AD8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 592) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF1F8;
    *(unsigned char *)((char *)(ts4_word)(a0) + 77) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 605) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 606) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 607) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 608) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88888C08: call_seq fn_8861B128, lbl_880DF380, u32@0x0, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_8861B128_88888C08(ts4_word a0)
{
    fn_8861B128((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF380;
    fn_8816D1A8((ts4_word)(a0 + 36));
    return a0;
}

/* Swing_DLL.xex 0x88889578: call_seq u32@0x1c, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0xc, u32@lbl_88D45B34 */
ts4_word ts4_call_seq_u32_off1c_88889578(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 12);
    t7 = fn_888F67B8((ts4_word)t5, (ts4_word)(*(ts4_word *)lbl_88D45B34));
    return t7;
}

/* Swing_DLL.xex 0x8888A490: if_call_seq u32@0xc, fn_8862EA10, u32@0x4, u32@0xc, fn_88889F50 */
ts4_word ts4_if_call_seq_u32_offc_8888A490(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a0;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
    if ((ts4_word)t1 == 0) {
        t2 = fn_8862EA10();
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)t2;
    }
    t5 = fn_88889F50((ts4_word)a2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4);
    return t5;
}

/* Swing_DLL.xex 0x8888A5C0: fn  */
ts4_word ts4_fn_8888A5C0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8888AA18: if_get u32@0xac, u32@0xac, u32@0xac, u32@0xa4, lbl_88C6BE38, u32@0x0 */
void ts4_if_get_u32_offac_8888AA18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 172);
    *(ts4_word *)((char *)(ts4_word)(a1) + 172) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) == 8) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 172) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 164)) << 2)) + (ts4_word)lbl_88C6BE38));
    return;
}

/* Swing_DLL.xex 0x8888AA50: if_get u32@0xa4, u32@0xa4, u32@0xa4, u32@0xa4, lbl_88C6BE38, u32@0x0 */
void ts4_if_get_u32_offa4_8888AA50(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 164);
    *(ts4_word *)((char *)(ts4_word)(a1) + 164) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) == 8) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 164) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 164)) << 2)) + (ts4_word)lbl_88C6BE38));
    return;
}

/* Swing_DLL.xex 0x8888AA88: if_get u32@0xb0, u32@0xb0, u32@0xb0, u32@0xb0, lbl_88C6BE58, u32@0x0 */
void ts4_if_get_u32_offb0_8888AA88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 176);
    *(ts4_word *)((char *)(ts4_word)(a1) + 176) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) == 4) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 176) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 176)) << 2)) + (ts4_word)lbl_88C6BE58));
    return;
}

/* Swing_DLL.xex 0x8888AAC0: if_get u32@0xa8, u32@0xa8, u32@0xa8, u32@0xa8, lbl_88C6BE08, u32@0x0 */
void ts4_if_get_u32_offa8_8888AAC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 168);
    *(ts4_word *)((char *)(ts4_word)(a1) + 168) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) == 4) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 168) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 168)) << 2)) + (ts4_word)lbl_88C6BE08));
    return;
}

/* Swing_DLL.xex 0x8888AAF8: if_get u32@0xa0, u32@0xa0, u32@0xa0, u32@0xa0, lbl_88C6BDF8, u32@0x0 */
void ts4_if_get_u32_offa0_8888AAF8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 160);
    *(ts4_word *)((char *)(ts4_word)(a1) + 160) = (ts4_word)(t1 + 1);
    if ((int)(t1 + 1) == 4) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 160) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a1) + 160)) << 2)) + (ts4_word)lbl_88C6BDF8));
    return;
}

/* Swing_DLL.xex 0x8888D228: call_seq lbl_880DEF10, u32@0x0, fn_881A6A00, lbl_880F6400, u32@0x0, fn_88638FC8 */
ts4_word ts4_call_seq_lbl_880DEF10_8888D228(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DEF10;
    fn_881A6A00((ts4_word)(a0 + 188));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F6400;
    t2 = fn_88638FC8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88890240: set u8@0x0 */
void ts4_set_u8_off0_88890240(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88890250: set u8@0x0 */
void ts4_set_u8_off0_88890250(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88890308: get u32@0x8, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off8_88890308(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88890398: get u32@0x8, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off8_88890398(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88890570: set u32@0x4, u32@0x0, u32@0xc, u32@0x8, u32@0x14, u32@0x10 */
void ts4_set_u32_off4_88890570(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888905B0: get u32@0x20, fn_8841B5E0 */
ts4_word ts4_get_u32_off20_888905B0(ts4_word a0)
{
    return fn_8841B5E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
}

/* Swing_DLL.xex 0x888906F0: get u32@0x0, fn_888905C0 */
ts4_word ts4_get_u32_off0_888906F0(ts4_word a0)
{
    return fn_888905C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88890700: get u32@0x0, ts4_loop_get_u32_off8_88890670 */
ts4_word ts4_get_u32_off0_88890700(ts4_word a0)
{
    return ts4_loop_get_u32_off8_88890670((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88890708: set u32@0x0 */
void ts4_set_u32_off0_88890708(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88890820: if_call_seq u32@0x1c, ts4_tsu_cleanup_end, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off1c_88890820(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_tsu_cleanup_end((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x88890B60: get u32@0x0, fn_88890AE0 */
ts4_word ts4_get_u32_off0_88890B60(ts4_word a0)
{
    return fn_88890AE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88890B88: call_seq fn_888860A0 */
ts4_word ts4_call_seq_fn_888860A0_88890B88(ts4_word a0)
{
    fn_888860A0((ts4_word)a0);
    return 0;
}

/* Swing_DLL.xex 0x88890BB0: get u32@lbl_88D45B38, fn_88613268 */
ts4_word ts4_get_u32_lbl_88D45B38_88890BB0(ts4_word a0)
{
    return fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)a0, (ts4_word)16, (ts4_word)0, (ts4_word)2);
}

/* Swing_DLL.xex 0x88890BD0: if_get u32@0x1c, ts4_tsu_cleanup_end, u32@0x1c, u32@0x20, u32@0x24, u32@lbl_88CACF08 */
ts4_word ts4_if_get_u32_off1c_88890BD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t13;
    ts4_word t14;
    ts4_word t16;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_tsu_cleanup_end((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t5 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t6 = *(ts4_word *)lbl_88CACF08;
    t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 32);
    t8 = KeTlsGetValue((ts4_word)t6);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 4))))((ts4_word)t8, (ts4_word)t7);
    t13 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t14 = fn_88419DE8((ts4_word)t13);
    fn_8841BA98((ts4_word)t14);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t16 = fn_881B9148((ts4_word)(a0 + 16));
    return t16;
}

/* Swing_DLL.xex 0x88890C68: call_seq fn_88617D88, lbl_880DCE14, u32@0x1c, u32@0x0, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88890C68(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCE14;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88890DB0: if_call_seq u32@0x0, fn_88890CB0, u32@0x0, ts4_tsu_cleanup_end, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88890DB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != 0) {
        fn_88890CB0((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_tsu_cleanup_end((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x88891180: call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, fn_88891030 */
ts4_word ts4_call_seq_u32_lbl_88D45B38_88891180(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    t3 = fn_88891030((ts4_word)t2, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x888912F0: addr lbl_880CF3A8 */
ts4_word ts4_addr_lbl_880CF3A8_888912F0(void)
{
    return (ts4_word)lbl_880CF3A8;
}

/* Swing_DLL.xex 0x88891300: addr lbl_880CF518 */
ts4_word ts4_addr_lbl_880CF518_88891300(void)
{
    return (ts4_word)lbl_880CF518;
}

/* Swing_DLL.xex 0x88891788: fn  */
ts4_word ts4_fn_88891788(void)
{
    return 1912;
}

/* Swing_DLL.xex 0x88894B00: fn  */
ts4_word ts4_fn_88894B00(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88895140: addr lbl_880CF238, ts4_xmltok_normal_update_position_88892AD0 */
ts4_word ts4_addr_lbl_880CF238_88895140(void)
{
    return ts4_xmltok_normal_update_position_88892AD0((ts4_word)(ts4_word)lbl_880CF238);
}

/* Swing_DLL.xex 0x8889B450: if_call_seq ts4_xmltok_init_unknown_encoding_88899C70, u8@0x86 */
ts4_word ts4_if_call_seq_fn_88899C70_8889B450(void)
{
    ts4_word t1;

    t1 = ts4_xmltok_init_unknown_encoding_88899C70();
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 134) = (unsigned char)23;
    }
    return t1;
}

/* Swing_DLL.xex 0x888A09C0: fn  */
ts4_word ts4_fn_888A09C0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x888A3920: set u32@0x14, u32@0x0, u32@0x4, u32@0x10, u32@0xc, u32@0x8 */
void ts4_set_u32_off14_888A3920(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888A3988: get u32@0x4, u32@0x0, u32@0x0, u32@0x4 */
void ts4_get_u32_off4_888A3988(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((t1 << 2) + t2);
    return;
}

/* Swing_DLL.xex 0x888A39A8: set u32@0x10, u32@0x4, u32@0xc, u32@0x8, u32@0x0 */
void ts4_set_u32_off10_888A39A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888A43C0: get u32@0x11c */
ts4_word ts4_get_u32_off11c_888A43C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 284));
}

/* Swing_DLL.xex 0x888A4EA8: addr ts4_noop_88605E88, u32@0x3c */
void ts4_addr_ts4_noop_88605E88_888A4EA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(ts4_word)ts4_noop_88605E88;
    return;
}

/* Swing_DLL.xex 0x888A4EB8: addr fn_8861D6A8, fn_886171D8, u32@0x34, u32@0x38 */
void ts4_addr_fn_8861D6A8_888A4EB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(ts4_word)fn_8861D6A8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(ts4_word)fn_886171D8;
    return;
}

/* Swing_DLL.xex 0x888A4ED8: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
void ts4_if_get_u32_off0_888A4ED8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    if ((ts4_word)t2 != (ts4_word)t1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x888A70B0: if_call_seq u32@0x90, fn_888A73D8, fn_888A4B00 */
ts4_word ts4_if_call_seq_u32_off90_888A70B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_888A73D8((ts4_word)a0, (ts4_word)1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    p4 = (ts4_word)t2;
    if ((int)t2 == 0) {
        t3 = fn_888A4B00((ts4_word)a0);
        p4 = (ts4_word)((t3 & 0xff) == 0);
    }
    return p4;
}

/* Swing_DLL.xex 0x888A8198: if_call_seq u32@0x90, fn_888A73D8, fn_888A4B00 */
ts4_word ts4_if_call_seq_u32_off90_888A8198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_888A73D8((ts4_word)a0, (ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    p4 = (ts4_word)t2;
    if ((int)t2 == 0) {
        t3 = fn_888A4B00((ts4_word)a0);
        p4 = (ts4_word)((t3 & 0xff) == 0);
    }
    return p4;
}

/* Swing_DLL.xex 0x888A8610: if_get u8@0xec, u32@0xe8, ts4_if_call_seq_fn_88894BA8_88899AA8, ts4_if_call_seq_fn_88894BA8_88899BF0, vcall, u32@0xe8 */
ts4_word ts4_if_get_u8_offec_888A8610(ts4_word a0)
{
    ts4_word p3;
    unsigned char t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 236);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(ts4_word)ts4_if_call_seq_fn_88894BA8_88899AA8;
    } else {
        p3 = (ts4_word)(ts4_word)ts4_if_call_seq_fn_88894BA8_88899BF0;
    }
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(p3))((ts4_word)(a0 + 148), (ts4_word)(a0 + 144), (ts4_word)t2);
    if ((int)t4 != 0) {
        return 0;
    }
    t6 = fn_888A81F8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 232)));
    return t6;
}

/* Swing_DLL.xex 0x888AA948: get  */
float ts4_get_888AA948(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x888B0E28: get u32@0x0, u32@0xa8 */
void ts4_get_u32_off0_888B0E28(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x888B1D68: get u32@0x0, u32@0x8, u32@0x0, u32@0x4 */
void ts4_get_u32_off0_888B1D68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x888B3C7C: get u8@0x68, u8@0x68 */
void ts4_get_u8_off68_888B3C7C(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 104) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 104)) == 0);
    return;
}

/* Swing_DLL.xex 0x888B7300: if_get u32@0x8, u32@0x0, fn_888B1488 */
ts4_word ts4_if_get_u32_off8_888B7300(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 248) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888B7320: if_get u32@0x8, u32@0x0, fn_888B14F0 */
ts4_word ts4_if_get_u32_off8_888B7320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 244) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B14F0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888B7340: if_get u32@0x8, u32@0x0, fn_888B1628 */
ts4_word ts4_if_get_u32_off8_888B7340(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 240) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B1628((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888B7488: if_get u32@0x8, u32@0x0, fn_888B1488 */
ts4_word ts4_if_get_u32_off8_888B7488(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 188) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B1488((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888B74A8: if_get u32@0x8, u32@0x0, fn_888B14F0 */
ts4_word ts4_if_get_u32_off8_888B74A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 184) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B14F0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888B74C8: if_get u32@0x8, u32@0x0, fn_888B1628 */
ts4_word ts4_if_get_u32_off8_888B74C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7, float f1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p3 = (ts4_word)a7;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        *(float *)((char *)(ts4_word)((t2 + t1)) + 180) = f1;
        p3 = (ts4_word)t2;
    }
    return fn_888B1628((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p3);
}

/* Swing_DLL.xex 0x888BFA98: fn  */
ts4_word ts4_fn_888BFA98(void)
{
    return 0;
}

/* Swing_DLL.xex 0x888BFB10: set  */
void ts4_set_888BFB10(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Swing_DLL.xex 0x888BFB20: set  */
void ts4_set_888BFB20(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Swing_DLL.xex 0x888BFBA8: fn  */
ts4_word ts4_fn_888BFBA8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x888BFCD0: get u8@lbl_88C46F6A */
ts4_word ts4_get_u8_lbl_88C46F6A_888BFCD0(void)
{
    return (*(unsigned char *)lbl_88C46F6A);
}

/* Swing_DLL.xex 0x888BFCF0: fn  */
ts4_word ts4_fn_888BFCF0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x888BFD70: addr lbl_88C6B8E0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_88C6B8E0_888BFD70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B8E0) + 4));
    return;
}

/* Swing_DLL.xex 0x888BFE20: get u8@lbl_88D45918 */
ts4_word ts4_get_u8_lbl_88D45918_888BFE20(void)
{
    return (*(unsigned char *)lbl_88D45918);
}

/* Swing_DLL.xex 0x888C0098: fn  */
ts4_word ts4_fn_888C0098(void)
{
    return 1;
}

/* Swing_DLL.xex 0x888C0108: get u32@0x80 */
void ts4_get_u32_off80_888C0108(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 128) = f1;
    return;
}

/* Swing_DLL.xex 0x888C0118: set u32@0x4, lbl_880DB2A4, u32@0x0 */
void ts4_set_u32_off4_888C0118(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2A4;
    return;
}

/* Swing_DLL.xex 0x888C0150: get u32@0xc4, u32@0x0 */
void ts4_get_u32_offc4_888C0150(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 196))) + 0) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888C0160: get u32@0xc8, u32@0x0 */
void ts4_get_u32_offc8_888C0160(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 200))) + 0) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888C0170: get u32@0xc4, u32@0x0 */
void ts4_get_u32_offc4_888C0170(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 196))) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C0180: get u32@0xc8, u32@0x0 */
void ts4_get_u32_offc8_888C0180(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 200))) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C0238: if_get u32@lbl_88D45B1C, u32@0x2cc, u8@0x9 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_888C0238(void)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 716);
    if ((int)t2 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)(t2) + 9));
    }
    return 0;
}

/* Swing_DLL.xex 0x888C0328: get u32@0x28, u32@lbl_88C6AEF0 */
void ts4_get_u32_off28_888C0328(ts4_word a0)
{
    *(ts4_word *)lbl_88C6AEF0 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    return;
}

/* Swing_DLL.xex 0x888C03C8: get u32@0x1c */
ts4_word ts4_get_u32_off1c_888C03C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) != 0);
}

/* Swing_DLL.xex 0x888C03F8: get u32@0xc */
ts4_word ts4_get_u32_offc_888C03F8(ts4_word a0, ts4_word a1)
{
    return ((((a1 + (a1 << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 12);
}

/* Swing_DLL.xex 0x888C0418: get u32@0xc */
ts4_word ts4_get_u32_offc_888C0418(ts4_word a0, ts4_word a1)
{
    return ((((a1 + (a1 << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 36);
}

/* Swing_DLL.xex 0x888C0438: get u32@0xc */
ts4_word ts4_get_u32_offc_888C0438(ts4_word a0, ts4_word a1)
{
    return ((((a1 + (a1 << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 24);
}

/* Swing_DLL.xex 0x888C0458: get u32@0xc */
ts4_word ts4_get_u32_offc_888C0458(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Swing_DLL.xex 0x888C0600: get u32@lbl_88D45908, u32@0x54, u32@0x4 */
ts4_word ts4_get_u32_lbl_88D45908_888C0600(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45908)) + 84))) + 4));
}

/* Swing_DLL.xex 0x888C0618: addr lbl_88D45CC0, u32@0x68c, u32@0x0, u32@0x14 */
ts4_word ts4_addr_lbl_88D45CC0_888C0618(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1676);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x888C0638: get u32@0x28, u32@0x24 */
ts4_word ts4_get_u32_off28_888C0638(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 36))) >> 3);
}

/* Swing_DLL.xex 0x888C0650: fn  */
ts4_word ts4_fn_888C0650(void)
{
    return 1;
}

/* Swing_DLL.xex 0x888C0678: if_get u32@0xe0 */
ts4_word ts4_if_get_u32_offe0_888C0678(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    if ((int)t1 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)((a1 & 0xff)) + t1));
    }
    return a1;
}

/* Swing_DLL.xex 0x888C0790: set u8@0x0, u32@0xe8 */
void ts4_set_u8_off0_888C0790(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C07A0: set u32@0x1c */
void ts4_set_u32_off1c_888C07A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x888C08F0: if_get u32@0x20, u8@0x0, u32@0x2c, u32@0x3c, u32@0x40, u32@0x2c */
void ts4_if_get_u32_off20_888C08F0(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 == 0) {
        return;
    }
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t2 != 1) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t3 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888C09D0: if_get u32@0xd0, u32@0xd0, u32@0xd0 */
void ts4_if_get_u32_offd0_888C09D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    if ((ts4_word)t1 == 9) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)(t1 + 1);
    return;
}

/* Swing_DLL.xex 0x888C0DD0: get u32@0x20, u32@0x20 */
void ts4_get_u32_off20_888C0DD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + -1);
    return;
}

/* Swing_DLL.xex 0x888C0DE0: get u32@0x18, u32@0x18, u32@0x1c */
void ts4_get_u32_off18_888C0DE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t1 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x888C0DF8: get u32@0x10, u8@0x9b, u32@0x10, u32@0x14 */
void ts4_get_u32_off10_888C0DF8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(unsigned char *)((char *)(ts4_word)(a0) + 155) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t1 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x888C0EA0: get u32@0x4, u32@0x8, u32@0xc, u32@0x44, u32@0x10, u32@0x2c */
void ts4_get_u32_off4_888C0EA0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 68))) + 16))) + 44) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C0EC0: get u32@0xb0, u32@0xa8, u32@0xa0 */
ts4_word ts4_get_u32_offb0_888C0EC0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    return ((int)((int)t1 * (int)t2) * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 160)));
}

/* Swing_DLL.xex 0x888C0ED8: set u8@0x38 */
void ts4_set_u8_off38_888C0ED8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C0EE8: set u8@0x38 */
void ts4_set_u8_off38_888C0EE8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C1748: get u32@0x20, u32@0x20 */
void ts4_get_u32_off20_888C1748(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + 1);
    return;
}

/* Swing_DLL.xex 0x888C1848: get u32@0x4, u32@0x44, u32@0x10 */
void ts4_get_u32_off4_888C1848(ts4_word a0)
{
    ts4_word t1;
    float t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(float *)lbl_8814B440;
    *(float *)((char *)(ts4_word)(a0) + 100) = t2;
    *(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 68))) + 16))) + 56) = t2;
    return;
}

/* Swing_DLL.xex 0x888C1868: get u32@0x4, u32@0x60, u32@0x44, u32@0x10, u32@0x70 */
void ts4_get_u32_off4_888C1868(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 68))) + 16))) + 112) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x888C18D8: set u8@0x5c */
void ts4_set_u8_off5c_888C18D8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C18E8: get u32@0x4, u32@0x60, u32@0x44, u32@0x10, u32@0x70, u8@0x5c */
void ts4_get_u32_off4_888C18E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 68))) + 16))) + 112) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C1A08: set u8@0x54 */
void ts4_set_u8_off54_888C1A08(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C1A18: set u8@0x54, ts4_store_scaled_ratio_and_update_888C1990 */
ts4_word ts4_set_u8_off54_888C1A18(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)1;
    return ts4_store_scaled_ratio_and_update_888C1990((ts4_word)a0);
}

/* Swing_DLL.xex 0x888C1A28: get u32@0x28, u8@0x69, u32@0x28, u8@0x3a, u32@0x4, u32@0x44 */
void ts4_get_u32_off28_888C1A28(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 105) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 58) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 68))) + 16))) + 101) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C1BE0: if_get u8@0x22, u32@0x14, u32@0x10 */
ts4_word ts4_if_get_u8_off22_888C1BE0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 34);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    }
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 16));
}

/* Swing_DLL.xex 0x888C1C00: get u32@0x250, u32@0x2c8, u8@0x234, u8@0x235, u32@0x238, u8@0x2d8 */
void ts4_get_u32_off250_888C1C00(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 592);
    *(ts4_word *)((char *)(ts4_word)(a0) + 712) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 565) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 728) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t1) + 130) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C1C28: if_call_seq ts4_find_service, u32@0x250, u32@0x2c8, u8@0x234, u8@0x235, u32@0x238 */
ts4_word ts4_if_call_seq_ts4_find_service_888C1C28(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((1193410560) | 32379));
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 592);
        *(ts4_word *)((char *)(ts4_word)(t1) + 712) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t1) + 564) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t1) + 565) = (unsigned char)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 568) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t1) + 728) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 130) = (unsigned char)1;
    }
    return t1;
}

/* Swing_DLL.xex 0x888C2398: if_call_seq u32@0x84, XNotifyGetNext, u8@0x88, u8@0x88 */
ts4_word ts4_if_call_seq_u32_off84_888C2398(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t3;

    t2 = XNotifyGetNext((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)), (ts4_word)9, (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 != 0) {
        t3 = loc50[0];
        *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)((t3 + -1) == 0);
    }
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 136));
}

/* Swing_DLL.xex 0x888C2550: set u8@0x1fc */
void ts4_set_u8_off1fc_888C2550(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 508) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C2A18: get u32@0x1c, u8@0x35, u8@0x36, u8@0x8d9 */
void ts4_get_u32_off1c_888C2A18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(t1) + 2265) = (unsigned char)0;
    return;
}
