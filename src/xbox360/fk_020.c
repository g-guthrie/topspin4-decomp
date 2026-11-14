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
ts4_word fn_886ECE38();
ts4_word fn_886F1900();
ts4_word fn_886F5A00();
ts4_word fn_886F5CB8();
ts4_word fn_886F6128();
ts4_word fn_887000D8();
ts4_word fn_88883CD0();
ts4_word fn_88884DE0();
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

/* Swing_DLL.xex 0x8867A0D8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8867A0D8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867B9A8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8867B9A8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867BA58: call_seq fn_88617D88, lbl_880F4890, u32@0x1c, u32@0x0, u32@0x20, u32@0x30 */
ts4_word ts4_call_seq_fn_88617D88_8867BA58(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4890;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 40) = (ts4_u64)0;
    return a0;
}

/* Swing_DLL.xex 0x8867D728: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8867D728(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867D900: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8867D900(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867DE50: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8867DE50(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8867E288: call_seq fn_8867DEF0, fn_8867DF68 */
ts4_word ts4_call_seq_fn_8867DEF0_8867E288(ts4_word a0)
{
    ts4_word t2;

    fn_8867DEF0((ts4_word)a0);
    t2 = fn_8867DF68((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8867E918: call_seq fn_8890DDA8, fn_8890DDA8, u32@0x4, fn_8867DB30, u32@0x4, fn_8867DB30 */
ts4_word ts4_call_seq_fn_8890DDA8_8867E918(ts4_word a0)
{
    ts4_word t6;

    fn_8890DDA8((ts4_word)(a0 + 100));
    fn_8890DDA8((ts4_word)(a0 + 32));
    fn_8867DB30((ts4_word)(a0 + 8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t6 = fn_8867DB30((ts4_word)(a0 + 20), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t6;
}

/* Swing_DLL.xex 0x8867F8F8: tailcall fn_8867F290 */
ts4_word ts4_tailcall_fn_8867F290_8867F8F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_8867F290((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)0);
}

/* Swing_DLL.xex 0x8867F900: tailcall fn_8867F290 */
ts4_word ts4_tailcall_fn_8867F290_8867F900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_8867F290((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)1);
}

/* Swing_DLL.xex 0x886813B8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_886813B8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88681410: call_seq fn_88617D88, lbl_880F4DC8, u32@0x1c, u32@0x0, u32@0x3c, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88681410(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4DC8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88681548: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88681548(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886816C8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_886816C8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88681D00: call_seq u8@0x8, fn_881B9148, u32@0x1c, u32@0x40, u32@0x3c */
ts4_word ts4_call_seq_u8_off8_88681D00(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88681D60: call_seq fn_88617D88, lbl_880F4D10, u32@0x1c, u32@0x0, u32@0x38, u32@0x40 */
ts4_word ts4_call_seq_fn_88617D88_88681D60(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4D10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88681EA0: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88681EA0(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88682020: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88682020(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88682978: get u32@0x1c, u32@0x8, fn_8867DB30 */
ts4_word ts4_get_u32_off1c_88682978(ts4_word a0)
{
    return fn_8867DB30((ts4_word)(a0 + 36), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8)));
}

/* Swing_DLL.xex 0x88682988: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88682988(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88682A28: call_seq fn_88617D88, lbl_880F4C50, u32@0x1c, u32@0x0, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_88682A28(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4C50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88682DC0: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88682DC0(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88682F40: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88682F40(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886894A8: call_seq u32@0x8, u32@0x4, fn_88689068, u32@0x8, u32@0x4, fn_88689068 */
ts4_word ts4_call_seq_u32_off8_886894A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    fn_88689068((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1, (ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t6 = fn_88689068((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 52), (ts4_word)(t4 + 96), (ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8868C930: call_seq u8@0x8, fn_881B9148, u32@0x1c, fn_8890DDA8, fn_8890DDA8, fn_8890DDA8 */
ts4_word ts4_call_seq_u8_off8_8868C930(ts4_word a0)
{
    ts4_word t5;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    fn_8890DDA8((ts4_word)(a0 + 160));
    fn_8890DDA8((ts4_word)(a0 + 228));
    fn_8890DDA8((ts4_word)(a0 + 296));
    t5 = fn_8890DDA8((ts4_word)(a0 + 92));
    return t5;
}

/* Swing_DLL.xex 0x8868CA78: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8868CA78(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8868CEF8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8868CEF8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8868D078: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8868D078(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8868D1F8: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8868D1F8(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8868D378: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_8868D378(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8868D4C8: call_seq u32@0x4, u32@0x64, fn_8826D088, u32@0x18 */
ts4_word ts4_call_seq_u32_off4_8868D4C8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = fn_8826D088((ts4_word)(a0 + 12), (ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 100)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x8868FA38: if_call_seq u32@0x8c, u8@0x93, u32@0x8, fn_8868F9C8, u32@0x30, u8@0x328 */
ts4_word ts4_if_call_seq_u32_off8c_8868FA38(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    unsigned char t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 140);
    *(unsigned char *)((char *)(ts4_word)(a1) + 147) = (unsigned char)1;
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 8));
    t3 = fn_8868F9C8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t5 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 808);
    if ((ts4_word)t5 == 0) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 72))) + 8) = (unsigned char)1;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t8 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(t7) + 136) = (ts4_word)t8;
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t10 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(t9) + 208) = (ts4_word)t10;
    return t3;
}

/* Swing_DLL.xex 0x886906E8: if_call_seq fn_8890DDA8, fn_8890DDA8, fn_8890DDA8, fn_8890DDA8, fn_8890DDA8, u32@0x1c8 */
ts4_word ts4_if_call_seq_fn_8890DDA8_886906E8(ts4_word a0)
{
    ts4_word p8;
    ts4_word t6;
    ts4_word t7;

    fn_8890DDA8((ts4_word)(a0 + 276));
    fn_8890DDA8((ts4_word)(a0 + 72));
    fn_8890DDA8((ts4_word)(a0 + 4));
    fn_8890DDA8((ts4_word)(a0 + 140));
    fn_8890DDA8((ts4_word)(a0 + 208));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    p8 = (ts4_word)t6;
    if ((int)t6 != 0) {
        t7 = fn_888860A0((ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 456) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 460) = (ts4_word)0;
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88691230: if_call_seq u32@0x28, ts4_if_call_seq_u32_off10_8890E0E0, u32@0x28, ts4_tsu_cleanup_end, u32@0x24, u32@0x28 */
ts4_word ts4_if_call_seq_u32_off28_88691230(ts4_word a0)
{
    ts4_word p5;
    ts4_word p9;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;

    ts4_if_call_seq_u32_off10_8890E0E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = ts4_tsu_cleanup_end((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    p9 = (ts4_word)p5;
    if ((ts4_word)t6 != 0) {
        fn_8867C418((ts4_word)t6);
        t8 = ts4_tsu_cleanup_end((ts4_word)t6);
        p9 = (ts4_word)t8;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return p9;
}

/* Swing_DLL.xex 0x88693F08: call_seq u8@0x8, fn_881B9148, u32@0x1c */
ts4_word ts4_call_seq_u8_off8_88693F08(ts4_word a0)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t1 = fn_881B9148((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x88695358: call_seq u32@0x4, u32@0x64, fn_8826C198, u32@0x30 */
ts4_word ts4_call_seq_u32_off4_88695358(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = fn_8826C198((ts4_word)(a0 + 12), (ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 100)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x886953A0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_886953A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886953C0: call_seq fn_8890F1E8, fn_8890F1E8, fn_8890F1E8 */
ts4_word ts4_call_seq_fn_8890F1E8_886953C0(ts4_word a0)
{
    ts4_word t3;

    fn_8890F1E8((ts4_word)(a0 + 136));
    fn_8890F1E8((ts4_word)(a0 + 68));
    t3 = fn_8890F1E8((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x886954F8: if_call_seq lbl_880F4608, u32@0x0, fn_8890F1E8, fn_8890F1E8, u32@0x14, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F4608_886954F8(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4608;
    fn_8890F1E8((ts4_word)(a0 + 100));
    fn_8890F1E8((ts4_word)(a0 + 32));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_destroy_owned_object((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F45D0;
    return p8;
}

/* Swing_DLL.xex 0x88695E20: if_call_seq lbl_880F4650, u32@0x0, fn_8890F1E8, fn_8890F1E8, u32@0x4, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F4650_88695E20(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4650;
    fn_8890F1E8((ts4_word)(a0 + 92));
    fn_8890F1E8((ts4_word)(a0 + 24));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = ts4_destroy_owned_object((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88695F70: call_seq lbl_880F4E2C, u32@0x0, fn_8890F1E8, lbl_880D5A64, u32@0x0 */
ts4_word ts4_call_seq_lbl_880F4E2C_88695F70(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E2C;
    t1 = fn_8890F1E8((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A64;
    return t1;
}

/* Swing_DLL.xex 0x8869AF48: call_seq lbl_880F4BCC, u32@0x0, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8 */
ts4_word ts4_call_seq_lbl_880F4BCC_8869AF48(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4BCC;
    fn_8890F1E8((ts4_word)(a0 + 148));
    fn_8890F1E8((ts4_word)(a0 + 80));
    t3 = fn_8890F1E8((ts4_word)(a0 + 12));
    return t3;
}

/* Swing_DLL.xex 0x8869BBD0: if_call_seq lbl_880F4708, u32@0x0, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8 */
ts4_word ts4_if_call_seq_lbl_880F4708_8869BBD0(ts4_word a0)
{
    ts4_word t5;
    ts4_word t8;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4708;
    fn_8890F1E8((ts4_word)(a0 + 296));
    fn_8890F1E8((ts4_word)(a0 + 228));
    fn_8890F1E8((ts4_word)(a0 + 160));
    fn_8890F1E8((ts4_word)(a0 + 92));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t5 != 0) {
        ts4_destroy_owned_object((ts4_word)t5);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F43A4;
    t8 = fn_88617D28((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x8869CFB8: call_seq lbl_880F4468, u32@0x0, fn_8890F1E8, fn_8890F1E8 */
ts4_word ts4_call_seq_lbl_880F4468_8869CFB8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4468;
    fn_8890F1E8((ts4_word)(a0 + 92));
    t2 = fn_8890F1E8((ts4_word)(a0 + 20));
    return t2;
}

/* Swing_DLL.xex 0x8869DE40: if_call_seq u32@0xb4, u32@0x88, u32@0x5a0, u32@0x5a4, u32@0x48, u32@0x74 */
ts4_word ts4_if_call_seq_u32_offb4_8869DE40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p18;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 136);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 1440);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 1444);
    p18 = (ts4_word)t1;
    if ((ts4_word)t3 != (ts4_word)t4) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 196);
        fn_88692468((ts4_word)t1, (ts4_word)t7, (ts4_word)t6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 48))) + 784)), (ts4_word)1);
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 200);
        t13 = fn_88660690((ts4_word)(ts4_word)&loc50[0], (ts4_word)t11);
        *(ts4_word *)((char *)(ts4_word)(t12) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 0));
        *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 4));
        *(ts4_word *)((char *)(ts4_word)(t12) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 8));
        *(ts4_word *)((char *)(ts4_word)(t12) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 12));
        p18 = (ts4_word)t13;
    }
    return p18;
}

/* Swing_DLL.xex 0x8869FA88: call_seq fn_8890F1E8, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8 */
ts4_word ts4_call_seq_fn_8890F1E8_8869FA88(ts4_word a0)
{
    ts4_word t5;

    fn_8890F1E8((ts4_word)(a0 + 276));
    fn_8890F1E8((ts4_word)(a0 + 208));
    fn_8890F1E8((ts4_word)(a0 + 140));
    fn_8890F1E8((ts4_word)(a0 + 72));
    t5 = fn_8890F1E8((ts4_word)(a0 + 4));
    return t5;
}

/* Swing_DLL.xex 0x886A03C0: call_seq lbl_880F444C, u32@0x0, fn_8890F1E8, lbl_880D19F0, u32@0x0 */
ts4_word ts4_call_seq_lbl_880F444C_886A03C0(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F444C;
    t1 = fn_8890F1E8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return t1;
}

/* Swing_DLL.xex 0x886A0A40: get u32@0x1c, fn_8869D870 */
ts4_word ts4_get_u32_off1c_886A0A40(ts4_word a0)
{
    return fn_8869D870((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x886A10D8: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_call_seq_u32_off0_886A10D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    fn_886A0FC0();
    return a0;
}

/* Swing_DLL.xex 0x886A48B0: get u32@0x1c, fn_8869D870 */
ts4_word ts4_get_u32_off1c_886A48B0(ts4_word a0)
{
    return fn_8869D870((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x886A4928: addr lbl_880C8F26, ts4_keyed_items_register_all_8869C9E8 */
ts4_word ts4_addr_lbl_880C8F26_886A4928(void)
{
    return ts4_keyed_items_register_all_8869C9E8((ts4_word)(ts4_word)lbl_880C8F26);
}

/* Swing_DLL.xex 0x886A4938: addr lbl_880C8F25, ts4_keyed_items_register_all_8869C9E8 */
ts4_word ts4_addr_lbl_880C8F25_886A4938(void)
{
    return ts4_keyed_items_register_all_8869C9E8((ts4_word)(ts4_word)lbl_880C8F25);
}

/* Swing_DLL.xex 0x886A7020: if_get fn_886A6F78, u32@0x84, u32@0x0, u32@0x0, vcall, u32@0x74 */
ts4_word ts4_if_get_fn_886A6F78_886A7020(ts4_word a0)
{
    ts4_word t2;
    ts4_word t7;
    ts4_word t12;

    fn_886A6F78();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2, (ts4_word)1);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    if ((ts4_word)t7 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 0))))((ts4_word)t7, (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t12 = fn_881B9148((ts4_word)(a0 + 16));
    return t12;
}

/* Swing_DLL.xex 0x886A7FC0: call_seq u32@0x28, u32@0x2c, u32@0x30, u32@0x34, u32@0x38, u32@0x3c */
ts4_word ts4_call_seq_u32_off28_886A7FC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    fn_881705B0((ts4_word)(a0 + 40), (ts4_word)8);
    fn_881705B0((ts4_word)(a0 + 52), (ts4_word)3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x886A8020: if_call_seq ts4_object_finalize, ts4_object_finalize, ts4_object_finalize, u32@0x20, ts4_destroy_owned_object, u32@0x0 */
ts4_word ts4_if_call_seq_ts4_object_finalize_886A8020(ts4_word a0)
{
    ts4_word p12;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    ts4_object_finalize((ts4_word)(a0 + 8));
    ts4_object_finalize((ts4_word)(a0 + 20));
    ts4_object_finalize((ts4_word)(a0 + 32));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)((a0 + 20)) + 0);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_destroy_owned_object((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x886A8088: set u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off8_886A8088(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1856) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1860) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1864) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1865) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1866) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1867) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1868) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1872) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1876) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1880) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1884) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1888) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1892) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886A9DF0: if_call_seq u32@0x154, u32@0x2c, fn_886A2E48, u32@0x154, u32@0x2c, fn_886A2E48 */
ts4_word ts4_if_call_seq_u32_off154_886A9DF0(ts4_word a0)
{
    ts4_word p7;
    ts4_word t3;
    ts4_word t6;

    t3 = fn_886A2E48((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 568));
    p7 = (ts4_word)t3;
    if ((ts4_word)(t3 & 0xff) == 0) {
        t6 = fn_886A2E48((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 584));
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x886AA650: call_seq lbl_880C8F26, ts4_keyed_items_register_all_8869C9E8, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C8F26_886AA650(ts4_word a0)
{
    ts4_word t2;

    ts4_keyed_items_register_all_8869C9E8((ts4_word)(ts4_word)lbl_880C8F26);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x886AB3F8: call_seq u32@0x4, fn_881609C8, u32@0x18, fn_886AB320 */
ts4_word ts4_call_seq_u32_off4_886AB3F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;

    fn_881609C8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = fn_886AB320((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)a1, (ts4_word)a2);
    return t4;
}

/* Swing_DLL.xex 0x886AC0C0: tailcall fn_886ABAE8 */
ts4_word ts4_tailcall_fn_886ABAE8_886AC0C0(ts4_word a0)
{
    return fn_886ABAE8((ts4_word)a0, (ts4_word)2, (ts4_word)((4085776384) | 45819));
}

/* Swing_DLL.xex 0x886AD748: tailcall fn_886AD278 */
ts4_word ts4_tailcall_fn_886AD278_886AD748(ts4_word a0, ts4_word a1)
{
    return fn_886AD278((ts4_word)a0, (ts4_word)a1, (ts4_word)(a0 + 96), (ts4_word)1, (ts4_word)1);
}

/* Swing_DLL.xex 0x886B0410: tailcall fn_886B0250 */
ts4_word ts4_tailcall_fn_886B0250_886B0410(ts4_word a0)
{
    return fn_886B0250((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x886B1268: call_seq fn_8866EBC0, u32@0x7c, u8@0x42, u32@0x5c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_8866EBC0_886B1268(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    fn_8866EBC0();
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 124))) + 66) = (unsigned char)1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 32);
    fn_886AD278((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 36)), (ts4_word)a0, (ts4_word)t4, (ts4_word)1, (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 124))) + 66) = (unsigned char)0;
    t9 = fn_8866F090((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)));
    return t9;
}

/* Swing_DLL.xex 0x886B6030: tailcall fn_88911668 */
ts4_word ts4_tailcall_fn_88911668_886B6030(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88911668((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)(a0 + 212));
}

/* Swing_DLL.xex 0x886B7178: if_call_seq u32@0x4, u32@0x50, fn_886A0EC8, u32@0x44, fn_8866F028, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_886B7178(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t14;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_886A0EC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 80)));
    t5 = fn_8866F028((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 68)), (ts4_word)(t3 + 64));
    if ((ts4_word)t5 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 68);
        fn_88911668((ts4_word)(a0 + 32), (ts4_word)(t6 + 816), (ts4_word)t5, (ts4_word)(t7 + 140), (ts4_word)(t7 + 212));
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_886B6448((ts4_word)t3, (ts4_word)(a0 + 8), (ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 80))) + 40)));
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t17 = fn_886B6448((ts4_word)(t3 + 12), (ts4_word)(a0 + 20), (ts4_word)t14, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 80))) + 40)));
    return t17;
}

/* Swing_DLL.xex 0x886B7A08: get fn_8865A7D8, fn_886B7208, u32@0x4, fn_8868F178, fn_8867E968, u32@0x0 */
ts4_word ts4_get_fn_8865A7D8_886B7A08(ts4_word a0)
{
    ts4_word t8;

    fn_8865A7D8((ts4_word)a0);
    fn_886B7208((ts4_word)a0);
    fn_8868F178((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    fn_8867E968((ts4_word)a0);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x886BF1B8: tailcall fn_886BEEE8 */
ts4_word ts4_tailcall_fn_886BEEE8_886BF1B8(ts4_word a0)
{
    return fn_886BEEE8((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x886C3428: fn  */
ts4_word ts4_fn_886C3428(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886C3438: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_886C3438(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886C3508: fn  */
ts4_word ts4_fn_886C3508(ts4_word a0)
{
    return (a0 + 108);
}

/* Swing_DLL.xex 0x886C3510: addr lbl_880F3798, lbl_880D6B70, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880F3798_886C3510(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3798;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880D6B70;
    return;
}

/* Swing_DLL.xex 0x886C3560: get u32@0x0 */
ts4_word ts4_get_u32_off0_886C3560(ts4_word a0)
{
    return (((1065353216) - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) == 0);
}

/* Swing_DLL.xex 0x886C3578: get u32@0x0 */
ts4_word ts4_get_u32_off0_886C3578(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) == 0);
}

/* Swing_DLL.xex 0x886C3738: set u32@0x4, fn_886C3658 */
ts4_word ts4_set_u32_off4_886C3738(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return fn_886C3658((ts4_word)a0);
}

/* Swing_DLL.xex 0x886C3AA8: set u32@0x70 */
void ts4_set_u32_off70_886C3AA8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886C3AB0: get u32@0xc */
ts4_word ts4_get_u32_offc_886C3AB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x886C3AB8: get u32@0x84 */
ts4_word ts4_get_u32_off84_886C3AB8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) != 0);
}

/* Swing_DLL.xex 0x886C3AC8: get u32@0x60, u32@0x5c */
ts4_word ts4_get_u32_off60_886C3AC8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 92))) >> 2);
}

/* Swing_DLL.xex 0x886C3AF8: get u32@0x8, u32@-0x4 */
ts4_word ts4_get_u32_off8_886C3AF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + -4));
}

/* Swing_DLL.xex 0x886C3B08: get u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_886C3B08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 4))) >> 2);
}

/* Swing_DLL.xex 0x886C3C58: set u32@0x8, u32@0xc */
void ts4_set_u32_off8_886C3C58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a1 + 48);
    return;
}

/* Swing_DLL.xex 0x886C3C68: addr lbl_880F4460, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_880F4460_886C3C68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4460;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886C3C88: get u32@0x1c, u32@0x50 */
ts4_word ts4_get_u32_off1c_886C3C88(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80))) + (a1 << 2))) + 1232);
}

/* Swing_DLL.xex 0x886C3CA8: get u32@0x5c, u32@0x4 */
ts4_word ts4_get_u32_off5c_886C3CA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 92))) + 4));
}

/* Swing_DLL.xex 0x886C3F38: get u32@0x24 */
void ts4_get_u32_off24_886C3F38(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a1 + 12) << 2)) + a0))) + 36) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x886C3F50: get u32@0x30, u32@0x24, u32@0x30, u32@0x28, u32@0x34, u32@0x24 */
void ts4_get_u32_off30_886C3F50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 40) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886C3F78: set u32@0x20, u32@0x3c */
void ts4_set_u32_off20_886C3F78(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886C3FB8: addr lbl_880F3784, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880F3784_886C3FB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3784;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886C4180: get u32@0xb8, fn_88644990 */
ts4_word ts4_get_u32_offb8_886C4180(ts4_word a0)
{
    return fn_88644990((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 184)), (ts4_word)a0);
}

/* Swing_DLL.xex 0x886C4478: get  */
void ts4_get_886C4478(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    return;
}

/* Swing_DLL.xex 0x886C4838: call_seq ts4_object_finalize */
ts4_word ts4_call_seq_ts4_object_finalize_886C4838(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_object_finalize((ts4_word)(a0 + 4));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)lbl_8814B440);
    return t1;
}

/* Swing_DLL.xex 0x886C4AB8: call_seq ts4_object_finalize, u32@0x18 */
ts4_word ts4_call_seq_ts4_object_finalize_886C4AB8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_object_finalize((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x886C4C18: get u32@0x5c, u32@0x28, u32@0x28 */
void ts4_get_u32_off5c_886C4C18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 92);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
    return;
}

/* Swing_DLL.xex 0x886C4DE0: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_886C4DE0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(a1 + 92);
    return;
}

/* Swing_DLL.xex 0x886C4FB0: get u32@0x2c, u8@0x13 */
ts4_word ts4_get_u32_off2c_886C4FB0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 19));
}

/* Swing_DLL.xex 0x886C4FC0: get u32@0x28, u32@0x14, u32@0x400, u32@0x28, u32@0x14, u32@0x404 */
void ts4_get_u32_off28_886C4FC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 20))) + 1024) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 20))) + 1028) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x886C4FE0: get u32@0x28, u32@0x5e4, fn_886C3FE0 */
ts4_word ts4_get_u32_off28_886C4FE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_886C3FE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 1508)), (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x886C4FF0: get u32@0x28, u32@0x5e4, fn_886C3FE0 */
ts4_word ts4_get_u32_off28_886C4FF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_886C3FE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 1508)), (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Swing_DLL.xex 0x886C5050: get u32@0x28, u32@0x24 */
void ts4_get_u32_off28_886C5050(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a1 + 264) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 40))))) + 36) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x886C51E0: if_get u32@0x34, u8@0x1c, u8@0x1d */
ts4_word ts4_if_get_u32_off34_886C51E0(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 28);
    if ((ts4_word)t2 != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 29);
        if ((ts4_word)t3 == 0) {
            return 1;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x886C54B8: get u32@0xc, u32@0xc */
ts4_word ts4_get_u32_offc_886C54B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 12));
}

/* Swing_DLL.xex 0x886C59F0: get u8@0x1c */
ts4_word ts4_get_u8_off1c_886C59F0(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a1 + 12) << 2)) + a0))) + 28));
}

/* Swing_DLL.xex 0x886C6038: set u8@0x61 */
void ts4_set_u8_off61_886C6038(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 97) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886C7060: if_get u32@0xc, u32@0x20, u32@0x1c, u32@0xc, u32@0xc, u32@0x14 */
void ts4_if_get_u32_offc_886C7060(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    float t5;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(float *)((char *)(ts4_word)(t2) + 20) = (*(float *)((char *)(ts4_word)(a0) + 8));
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t5 = *(float *)((char *)(ts4_word)(a0) + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + -1);
        *(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 20))) + 480) = t5;
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))) + 1072) = (unsigned char)1;
        return;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 20))) + 1072) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886C70C0: set u32@0x1c, u32@0x20, u32@0x14, u32@0x48c, u32@0x488, u32@0x1c */
ts4_word ts4_set_u32_off1c_886C70C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(a1 + 48);
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1160) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 1164));
    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20);
    *(ts4_word *)((char *)(ts4_word)(t4) + 1172) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 1176));
    t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 1188);
    *(ts4_word *)((char *)(ts4_word)(t7) + 1184) = (ts4_word)t8;
    return t8;
}

/* Swing_DLL.xex 0x886C7100: addr g_ts4_script_constants, lbl_880D6B70, u8@0x4, u32@0x0, u32@0xc, u32@0x14 */
void ts4_addr_g_ts4_script_constants_886C7100(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)g_ts4_script_constants;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 8) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    t2 = *(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 240);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 49) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886C72B8: tailcall fn_886C71C8 */
ts4_word ts4_tailcall_fn_886C71C8_886C72B8(ts4_word a0)
{
    return fn_886C71C8((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x886C7D58: if_call_seq u32@0x28, u32@0x0, fn_886C66C0, u32@0x8c, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off28_886C7D58(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3751936000) | 45041);
    t2 = fn_886C66C0((ts4_word)(t1 + 48));
    if ((int)t2 != -1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 140))) + (t2 << 2)))) + 4))) + 8))) + 132));
    }
    return a0;
}

/* Swing_DLL.xex 0x886C7DC8: get u32@0x28, u8@0x101 */
void ts4_get_u32_off28_886C7DC8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 257) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x886C7EC0: get u32@0x28, fn_886C73B8 */
ts4_word ts4_get_u32_off28_886C7EC0(ts4_word a0)
{
    return fn_886C73B8((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + 1072));
}

/* Swing_DLL.xex 0x886C7FD0: call_seq ts4_object_finalize, ts4_object_finalize, ts4_object_finalize */
ts4_word ts4_call_seq_ts4_object_finalize_886C7FD0(ts4_word a0)
{
    ts4_word t3;

    ts4_object_finalize((ts4_word)(a0 + 72));
    ts4_object_finalize((ts4_word)(a0 + 84));
    t3 = ts4_object_finalize((ts4_word)(a0 + 96));
    return t3;
}

/* Swing_DLL.xex 0x886E8448: call_seq lbl_880F345C, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_886E80E8, lbl_880F346C, fn_88608590 */
ts4_word ts4_call_seq_lbl_880F345C_886E8448(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F345C);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_if_mode_886E80E8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F346C);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_if_mode_886E8228((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F3484);
    loc50[0] = (ts4_word)t7;
    t9 = ts4_keyed_item_list_add_unique_if_mode_886E7FC8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x886E84E8: get u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall, u32@0x18, fn_882882A0 */
ts4_word ts4_get_u32_lbl_88D45A4C_886E84E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    fn_882882A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return 1;
}

/* Swing_DLL.xex 0x886E9490: call_seq fn_88617D88, lbl_880F3540, u32@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_886E9490(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3540;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x886E9B68: if_call_seq lbl_880F34E4, u32@0x0, fn_886E61E0, u32@0x90, ts4_destroy_owned_object, u32@0x84 */
ts4_word ts4_if_call_seq_lbl_880F34E4_886E9B68(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F34E4;
    t1 = fn_886E61E0((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 144);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t5 != 0) {
        ts4_destroy_owned_object((ts4_word)t5);
    }
    t8 = fn_88617D28((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x886E9E60: get u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall, u32@0x18, u32@0x1c */
ts4_word ts4_get_u32_lbl_88D45A4C_886E9E60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t7 = fn_88287FA0((ts4_word)a0, (ts4_word)12, (ts4_word)0, (ts4_word)t5, (ts4_word)0, (ts4_word)t5, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)18, (ts4_word)0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return t7;
}

/* Swing_DLL.xex 0x886EB140: fn  */
ts4_word ts4_fn_886EB140(void)
{
    return 3;
}

/* Swing_DLL.xex 0x886EB208: get  */
void ts4_get_886EB208(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a3) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a3) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a3) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a3) + 12));
    return;
}

/* Swing_DLL.xex 0x886EB250: fn  */
ts4_word ts4_fn_886EB250(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886EB258: fn  */
ts4_word ts4_fn_886EB258(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EB3A0: fn  */
ts4_word ts4_fn_886EB3A0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBA90: get u32@0x14 */
ts4_word ts4_get_u32_off14_886EBA90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x886EBA98: set u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_886EBA98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EBB50: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_886EBB50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EBBB8: fn  */
ts4_word ts4_fn_886EBBB8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC00: fn  */
ts4_word ts4_fn_886EBC00(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC08: fn  */
ts4_word ts4_fn_886EBC08(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886EBC10: fn  */
ts4_word ts4_fn_886EBC10(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886EBC18: fn  */
ts4_word ts4_fn_886EBC18(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC28: fn  */
ts4_word ts4_fn_886EBC28(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC30: fn  */
ts4_word ts4_fn_886EBC30(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC48: fn  */
ts4_word ts4_fn_886EBC48(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC58: fn  */
ts4_word ts4_fn_886EBC58(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC60: fn  */
ts4_word ts4_fn_886EBC60(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC68: fn  */
ts4_word ts4_fn_886EBC68(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC70: fn  */
ts4_word ts4_fn_886EBC70(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBC78: fn  */
ts4_word ts4_fn_886EBC78(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886EBC80: fn  */
ts4_word ts4_fn_886EBC80(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886EBCA0: fn  */
ts4_word ts4_fn_886EBCA0(void)
{
    return 5;
}

/* Swing_DLL.xex 0x886EBCC8: if_get u32@0x14, u32@0x1c, u32@0x18, u32@0x1c */
void ts4_if_get_u32_off14_886EBCC8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p4 = (ts4_word)t1;
    if ((int)t1 == (int)t2) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)p4;
    return;
}

/* Swing_DLL.xex 0x886EBD60: fn  */
ts4_word ts4_fn_886EBD60(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBD98: fn  */
ts4_word ts4_fn_886EBD98(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EBFB0: get u32@0x0 */
ts4_word ts4_get_u32_off0_886EBFB0(ts4_word a0, ts4_word a1)
{
    return ((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x886EC068: get u8@0x1c */
ts4_word ts4_get_u8_off1c_886EC068(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x886EC070: fn  */
ts4_word ts4_fn_886EC070(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886EC0C8: addr lbl_880D6B70, u32@0x24, u32@0x0 */
void ts4_addr_lbl_880D6B70_886EC0C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    return;
}

/* Swing_DLL.xex 0x886EC180: get u32@0x38 */
ts4_word ts4_get_u32_off38_886EC180(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x886EC428: set u8@0x8, u8@0x9 */
void ts4_set_u8_off8_886EC428(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)a2;
    return;
}

/* Swing_DLL.xex 0x886EC438: get u32@0x54 */
ts4_word ts4_get_u32_off54_886EC438(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 84));
}

/* Swing_DLL.xex 0x886EC450: set u8@0xa */
void ts4_set_u8_offa_886EC450(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 10) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886EC528: set u32@0x1c */
void ts4_set_u32_off1c_886EC528(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EC538: set u32@0x1c */
void ts4_set_u32_off1c_886EC538(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EC848: set u32@0x84, u32@0x90, u32@0x88, u32@0x8c, u32@0xc8 */
void ts4_set_u32_off84_886EC848(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886ECD18: set u32@0x5c, u32@0x60, u8@0x6c, u32@0x54, u32@0x50, u32@0x58 */
ts4_word ts4_set_u32_off5c_886ECD18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)a0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 108) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)a2;
    return (a0 + 80);
}

/* Swing_DLL.xex 0x886ECEA8: fn  */
ts4_word ts4_fn_886ECEA8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886ED010: if_get u32@lbl_88D45AD4 */
ts4_word ts4_if_get_u32_lbl_88D45AD4_886ED010(ts4_word a0)
{
    if ((int)a0 < 4) {
        return (*(unsigned char *)((char *)(ts4_word)(((*(ts4_word *)lbl_88D45AD4) + a0)) + ((65536) | 22084)));
    }
    return 1;
}

/* Swing_DLL.xex 0x886ED1F0: set u8@0x0 */
void ts4_set_u8_off0_886ED1F0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886ED280: if_get u8@0xc, u32@0x28 */
void ts4_if_get_u8_offc_886ED280(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886ED438: if_call_seq u32@0x0, u32@0x4, u32@lbl_88D42940, fn_8857C1F8, u32@lbl_88D41FDC, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_if_call_seq_u32_off0_886ED438(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p7 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        fn_8857C1F8((ts4_word)(*(ts4_word *)lbl_88D42940));
        t6 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)lbl_88D41FDC), (ts4_word)-1);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x886ED480: get u32@lbl_88D42940, fn_8857C1F8 */
ts4_word ts4_get_u32_lbl_88D42940_886ED480(void)
{
    return fn_8857C1F8((ts4_word)(*(ts4_word *)lbl_88D42940));
}

/* Swing_DLL.xex 0x886EDB30: get u32@0x4, u32@lbl_88D45AD4, u32@0x24, u32@0x84 */
ts4_word ts4_get_u32_off4_886EDB30(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 36))) + 132))) + ((t1 + (t1 << 2)) << 2))) + ((a1 + (a1 << 1)) << 2));
}

/* Swing_DLL.xex 0x886EDB68: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_886EDB68(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x886EDCA8: set u32@0x1c */
void ts4_set_u32_off1c_886EDCA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886EECF8: if_get u32@0x8, u32@0x0, u32@0x0, u32@0x70 */
ts4_word ts4_if_get_u32_off8_886EECF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t2 == (ts4_word)((3766681600) | 20946)) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 112))))((ts4_word)a0, (ts4_word)t1, (ts4_word)a2, (ts4_word)a3);
    }
    return 0;
}

/* Swing_DLL.xex 0x886EEE70: if_get u32@0x34, u32@0xc */
float ts4_if_get_u32_off34_886EEE70(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 12);
    if ((ts4_word)t2 != 0) {
        return (*(float *)((char *)(ts4_word)(t2) + 8));
    }
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x886EF170: if_get u32@0x34, u32@0xa8, u32@0xc, u8@0x58, u16@0xac, u16@0xac */
void ts4_if_get_u32_off34_886EF170(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t2 != 0) {
        *(unsigned short *)((char *)(ts4_word)(a0) + 172) = (unsigned short)(*(unsigned char *)((char *)(ts4_word)(t2) + 88));
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 172) = (unsigned short)1;
    return;
}

/* Swing_DLL.xex 0x886EF228: if_get u32@lbl_88D45AD0, u32@0x0, u32@0x38, vcall */
ts4_word ts4_if_get_u32_lbl_88D45AD0_886EF228(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD0;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 56))))((ts4_word)t1, (ts4_word)a0);
    }
    return 0;
}

/* Swing_DLL.xex 0x886EF440: set u32@0x0, u32@0x4, u32@0x8, u8@0xc, u8@0xd */
void ts4_set_u32_off0_886EF440(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886EF4E8: if_get fn_886ECE38, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_fn_886ECE38_886EF4E8(void)
{
    ts4_word t1;

    t1 = fn_886ECE38();
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)0, (ts4_word)-1);
    }
    return 0;
}

/* Swing_DLL.xex 0x886EF9C8: if_get u32@0xc, u32@0x10 */
void ts4_if_get_u32_offc_886EF9C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EF9E0: addr lbl_880F2480, u32@0xc, u32@0x0, u32@0x4, u32@0x8, u32@0x14 */
void ts4_addr_lbl_880F2480_886EF9E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2480;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886EFF10: if_fn  */
ts4_word ts4_if_fn_886EFF10(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0xff) != 0) {
        return (a0 + 48);
    }
    return (a0 + 36);
}

/* Swing_DLL.xex 0x886F0010: set u8@0x78, u8@0x94, u8@0x98, u8@0x97 */
void ts4_set_u8_off78_886F0010(ts4_word a0)
{
    float t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 148) = (unsigned char)0;
    t1 = *(float *)lbl_8814B440;
    *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)0;
    *(float *)((char *)(ts4_word)(a0) + 108) = t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 151) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886F0040: get u32@0xc */
ts4_word ts4_get_u32_offc_886F0040(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x886F0048: fn  */
ts4_word ts4_fn_886F0048(ts4_word a0)
{
    return (a0 + 16);
}

/* Swing_DLL.xex 0x886F0050: if_fn  */
ts4_word ts4_if_fn_886F0050(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0xff) != 0) {
        return (a0 + 16);
    }
    return (a0 + 40);
}

/* Swing_DLL.xex 0x886F0070: get u32@0xc */
ts4_word ts4_get_u32_offc_886F0070(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + 12);
}

/* Swing_DLL.xex 0x886F0510: if_get u32@lbl_88D45AD4, u32@0x164, u32@0x16c, u32@0x168 */
ts4_word ts4_if_get_u32_lbl_88D45AD4_886F0510(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88D45AD4;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 356);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 364);
    if ((int)t2 != (int)t3) {
        return t2;
    }
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 360));
}

/* Swing_DLL.xex 0x886F05A0: get u32@lbl_88D45AD4, u8@0x160 */
void ts4_get_u32_lbl_88D45AD4_886F05A0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 352) = (unsigned char)((a0 & 0xff) == 0);
    return;
}

/* Swing_DLL.xex 0x886F19C0: if_call_seq u32@0x34, fn_88883CD0, u32@0x10, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off34_886F19C0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t1;
    }
    return t2;
}

/* Swing_DLL.xex 0x886F1A08: if_call_seq fn_88883CD0, u32@0x10, u32@0x34, u32@0x38, fn_88883CD0, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88883CD0_886F1A08(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16));
    } else {
        p3 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)p3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t5 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t4;
    }
    return t5;
}

/* Swing_DLL.xex 0x886F1E18: call_seq u32@lbl_88D45AD4, fn_882907D8 */
ts4_word ts4_call_seq_u32_lbl_88D45AD4_886F1E18(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t3;

    loc50[0] = (ts4_word)a0;
    loc50[1] = (ts4_word)0;
    loc50[3] = (ts4_word)0;
    loc50[2] = (ts4_word)1;
    t3 = fn_882907D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + ((65536) | 22304))), (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    return t3;
}

/* Swing_DLL.xex 0x886F2458: tailcall fn_88884DE0 */
ts4_word ts4_tailcall_fn_88884DE0_886F2458(ts4_word a0)
{
    return fn_88884DE0((ts4_word)a0, (ts4_word)(2155806720));
}

/* Swing_DLL.xex 0x886F2EC8: get u32@0x0, u32@0x38, vcall, fn_886F1900 */
ts4_word ts4_get_u32_off0_886F2EC8(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)1);
    t4 = fn_886F1900((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x886F3638: addr lbl_880F2508, u32@0xc, u32@0x4, u32@0x0, u32@0x8, u32@0x14 */
void ts4_addr_lbl_880F2508_886F3638(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886F44C0: if_call_seq u32@lbl_88D45AA0, ts4_find_service, u32@lbl_88D45AA0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AA0_886F44C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AA0;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = ts4_find_service((ts4_word)((3587637248) | 61564));
        *(ts4_word *)lbl_88D45AA0 = (ts4_word)t2;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x886F5AD8: get u32@0x0, fn_886F5A00 */
ts4_word ts4_get_u32_off0_886F5AD8(ts4_word a0)
{
    return fn_886F5A00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x886F6400: call_seq ts4_object_finalize, u32@0x38 */
ts4_word ts4_call_seq_ts4_object_finalize_886F6400(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_object_finalize((ts4_word)(a0 + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)-1;
    return t1;
}

/* Swing_DLL.xex 0x886F9C80: if_call_seq u32@0x0, fn_888860A0, u32@0x8, u32@0x0, u32@0x4, fn_88884DE0 */
ts4_word ts4_if_call_seq_u32_off0_886F9C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    if ((ts4_word)t1 != 0) {
        fn_888860A0((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_88884DE0((ts4_word)t4, (ts4_word)(2155806720));
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x886FBD90: if_call_seq u32@0x44, u32@lbl_88D45B1C, u32@0x27c, ts4_find_service, u32@0x40, fn_886F6128 */
ts4_word ts4_if_call_seq_u32_off44_886FBD90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
    if ((ts4_word)t3 != (ts4_word)t1) {
        t4 = ts4_find_service((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)t4;
    }
    t6 = fn_886F6128((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x886FD3A0: if_get fn_886F6128, u32@0x38, u32@0x0, u32@0xc, vcall */
ts4_word ts4_if_get_fn_886F6128_886FD3A0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    fn_886F6128();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    p6 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 12))))((ts4_word)t2, (ts4_word)0);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x887035A0: call_seq u32@0x0, fn_88608590, fn_886F5CB8 */
ts4_word ts4_call_seq_u32_off0_887035A0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t3 = fn_886F5CB8((ts4_word)a0, (ts4_word)t2);
    return t3;
}

/* Swing_DLL.xex 0x88703D88: call_seq u32@0x24, fn_888860A0, u32@0x24 */
ts4_word ts4_call_seq_u32_off24_88703D88(ts4_word a0)
{
    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x887117D0: call_seq fn_887000D8 */
ts4_word ts4_call_seq_fn_887000D8_887117D0(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)((1648099328) | 49452);
    loc50[1] = (ts4_word)((3916169216) | 53061);
    loc50[2] = (ts4_word)((3916169216) | 53061);
    loc50[3] = (ts4_word)((3916169216) | 53061);
    t1 = fn_887000D8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)-1, (ts4_word)6, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x88713D68: call_seq ts4_object_finalize, ts4_object_finalize, fn_88161CF8 */
ts4_word ts4_call_seq_ts4_object_finalize_88713D68(ts4_word a0)
{
    ts4_word t3;

    ts4_object_finalize((ts4_word)a0);
    ts4_object_finalize((ts4_word)(a0 + 12));
    t3 = fn_88161CF8((ts4_word)(a0 + 24));
    return t3;
}

/* Swing_DLL.xex 0x88714730: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_88714730(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return a0;
}
