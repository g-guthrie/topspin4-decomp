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
extern char lbl_880C8F25[];
extern char lbl_880C8F26[];
extern char lbl_880C8F93[];
extern char lbl_880C8FA4[];
extern char lbl_880D19F0[];
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880F2480[];
extern char lbl_880F2508[];
extern char lbl_880F345C[];
extern char lbl_880F346C[];
extern char lbl_880F3484[];
extern char lbl_880F34E4[];
extern char lbl_880F3540[];
extern char lbl_880F3784[];
extern char lbl_880F3798[];
extern char lbl_880F43A4[];
extern char lbl_880F444C[];
extern char lbl_880F4460[];
extern char lbl_880F4468[];
extern char lbl_880F4524[];
extern char lbl_880F45D0[];
extern char lbl_880F4608[];
extern char lbl_880F4650[];
extern char lbl_880F4708[];
extern char lbl_880F4890[];
extern char lbl_880F4BCC[];
extern char lbl_880F4C50[];
extern char lbl_880F4D10[];
extern char lbl_880F4DC8[];
extern char lbl_880F4E2C[];
extern char lbl_8814B440[];
extern char lbl_88D41FDC[];
extern char lbl_88D42940[];
extern char lbl_88D45A4C[];
extern char lbl_88D45AA0[];
extern char lbl_88D45AD0[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
ts4_word fn_881609C8();
ts4_word fn_88161CF8();
ts4_word fn_881705B0();
ts4_word fn_881B9148();
ts4_word fn_88255AA0();
ts4_word fn_8826C198();
ts4_word fn_8826D088();
ts4_word fn_88287FA0();
ts4_word fn_882882A0();
ts4_word fn_882907D8();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857C1F8();
ts4_word fn_88608590();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88644990();
ts4_word fn_8865A7D8();
ts4_word fn_88660690();
ts4_word fn_8866EBC0();
ts4_word fn_8866F028();
ts4_word fn_8866F090();
ts4_word fn_8867C418();
ts4_word fn_8867DB30();
ts4_word fn_8867DEF0();
ts4_word fn_8867DF68();
ts4_word fn_8867E968();
ts4_word fn_8867F290();
ts4_word fn_88689068();
ts4_word fn_8868F178();
ts4_word fn_8868F9C8();
ts4_word fn_88692468();
ts4_word ts4_keyed_items_register_all_8869C9E8();
ts4_word fn_8869D870();
ts4_word fn_886A0EC8();
ts4_word fn_886A0FC0();
ts4_word fn_886A2E48();
ts4_word fn_886A6F78();
ts4_word ts4_if_call_seq_ts4_object_finalize_886A8020();
ts4_word fn_886AB320();
ts4_word fn_886ABAE8();
ts4_word fn_886AD278();
ts4_word fn_886B0250();
ts4_word fn_886B6448();
ts4_word fn_886B7208();
ts4_word fn_886BEEE8();
ts4_word fn_886C3658();
ts4_word fn_886C3FE0();
ts4_word fn_886C66C0();
ts4_word fn_886C71C8();
ts4_word fn_886C73B8();
ts4_word fn_886E61E0();
ts4_word ts4_call_seq_lbl_880F345C_886E8448();
ts4_word ts4_loop_get_u32_off48_886ECE38();
ts4_word fn_886F1900();
ts4_word fn_886F5A00();
ts4_word fn_886F5CB8();
ts4_word fn_886F6128();
ts4_word fn_887000D8();
ts4_word fn_88883CD0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_888860A0();
ts4_word fn_8890DDA8();
ts4_word ts4_if_call_seq_u32_off10_8890E0E0();
ts4_word fn_8890F1E8();
ts4_word fn_88911668();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_keyed_item_list_add_unique_if_mode_886E7FC8();
ts4_word ts4_keyed_item_list_add_unique_if_mode_886E80E8();
ts4_word ts4_keyed_item_list_add_unique_if_mode_886E8228();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x886AC0D0: if_call_seq u32@0x38, lbl_880F4524, u32@0x0, ts4_if_call_seq_ts4_object_finalize_886A8020, ts4_tsu_cleanup_end, fn_88617D28 */
ts4_word ts4_if_call_seq_u32_off38_886AC0D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4524;
    if ((ts4_word)t1 != 0) {
        ts4_if_call_seq_ts4_object_finalize_886A8020((ts4_word)t1);
        ts4_tsu_cleanup_end((ts4_word)t1);
    }
    t5 = fn_88617D28((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x886E8620: addr lbl_880C8FA4, ts4_call_seq_lbl_880F345C_886E8448 */
ts4_word ts4_addr_lbl_880C8FA4_886E8620(void)
{
    return ts4_call_seq_lbl_880F345C_886E8448((ts4_word)(ts4_word)lbl_880C8FA4);
}

/* Swing_DLL.xex 0x886E8630: addr lbl_880C8F93, ts4_call_seq_lbl_880F345C_886E8448 */
ts4_word ts4_addr_lbl_880C8F93_886E8630(void)
{
    return ts4_call_seq_lbl_880F345C_886E8448((ts4_word)(ts4_word)lbl_880C8F93);
}

/* Swing_DLL.xex 0x886E93A8: call_seq lbl_880C8FA4, ts4_call_seq_lbl_880F345C_886E8448, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C8FA4_886E93A8(ts4_word a0)
{
    ts4_word t2;

    ts4_call_seq_lbl_880F345C_886E8448((ts4_word)(ts4_word)lbl_880C8FA4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

