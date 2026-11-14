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

extern char g_ts4_default_script_value[];
extern char g_ts4_session_context[];
extern char g_ts4_true_string[];
extern char lbl_880C1320[];
extern char lbl_880C91A2[];
extern char lbl_880C91A3[];
extern char lbl_880E4BA0[];
extern char lbl_880EF46C[];
extern char lbl_880EF47C[];
extern char lbl_880EF484[];
extern char lbl_880EF4A0[];
extern char lbl_880EF4BC[];
extern char lbl_880EF4D8[];
extern char lbl_880EF580[];
extern char lbl_880EF5F4[];
extern char lbl_880EF62C[];
extern char lbl_880EF6B8[];
extern char lbl_880EF6C4[];
extern char lbl_880EF7EC[];
extern char lbl_880EFE30[];
extern char lbl_880F22A8[];
extern char lbl_880F2540[];
extern char lbl_880F2C98[];
extern char lbl_88C4589D[];
extern char lbl_88C47614[];
extern char lbl_88C47630[];
extern char lbl_88C47658[];
extern char lbl_88C47670[];
extern char lbl_88C4768C[];
extern char lbl_88C476C0[];
extern char lbl_88C476F4[];
extern char lbl_88C47734[];
extern char lbl_88C47840[];
extern char lbl_88C6CBF0[];
extern char lbl_88D45870[];
extern char lbl_88D45898[];
extern char lbl_88D4594C[];
extern char lbl_88D45954[];
extern char lbl_88D45958[];
extern char lbl_88D459DC[];
extern char lbl_88D459F4[];
extern char lbl_88D45A04[];
extern char lbl_88D45A0C[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A60[];
extern char lbl_88D45A6C[];
extern char lbl_88D45AB0[];
extern char lbl_88D45AD0[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B06[];
extern char lbl_88D45B0C[];
extern char lbl_88D45CC0[];
ts4_word fn_88150310();
ts4_word fn_88152DF8();
ts4_word fn_881608E8();
ts4_word fn_88161CF8();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881629B0();
ts4_word fn_88166BC0();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_8816D1A8();
ts4_word fn_881AAE70();
ts4_word fn_881B9148();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215B88();
ts4_word fn_8821FBC8();
ts4_word fn_88220690();
ts4_word fn_882266F8();
ts4_word fn_882267F0();
ts4_word fn_882280B0();
ts4_word fn_8822A3D8();
ts4_word fn_8822AD70();
ts4_word fn_8822C1C8();
ts4_word fn_8822C518();
ts4_word fn_88255AA0();
ts4_word fn_8825DA28();
ts4_word ts4_if_call_seq_u32_off8_88280958();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882886B8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_88617D88();
ts4_word ts4_if_get_u32_off1c_88655518();
ts4_word fn_886F5700();
ts4_word fn_88713190();
ts4_word fn_88716458();
ts4_word fn_88719768();
ts4_word fn_887197C8();
ts4_word fn_8871F260();
ts4_word fn_88721100();
ts4_word ts4_call_seq_u32_off540_88721838();
ts4_word fn_88721CB0();
ts4_word fn_88721F10();
ts4_word fn_88722AB0();
ts4_word fn_88722CA8();
ts4_word fn_88725348();
ts4_word fn_8872CDE0();
ts4_word fn_88731540();
ts4_word fn_88734098();
ts4_word fn_8873B890();
ts4_word fn_8873EFC0();
ts4_word fn_88748150();
ts4_word fn_887482D8();
ts4_word fn_8874B668();
ts4_word ts4_loop_get_u32_off1c_8875F488();
ts4_word fn_887690A8();
ts4_word fn_8876BCA8();
ts4_word fn_8876CF38();
ts4_word fn_8876D180();
ts4_word ts4_type_register_88771378();
ts4_word ts4_call_seq_lbl_880EFA80_88771440();
ts4_word fn_88778BE8();
ts4_word fn_8877DC48();
ts4_word fn_8877DF00();
ts4_word fn_88784DC8();
ts4_word fn_887EB080();
ts4_word fn_887EB4A0();
ts4_word ts4_set_u8_off42_887F9318();
ts4_word fn_88803198();
ts4_word ts4_loop_get_u32_lbl_88D45B1C_88865818();
ts4_word fn_888860A0();
ts4_word fn_88888668();
ts4_word ts4_if_call_seq_ts4_find_service_888C1C28();
ts4_word fn_888C8190();
ts4_word fn_888C8230();
ts4_word fn_888C82D0();
ts4_word fn_888C87D8();
ts4_word fn_888C8B30();
ts4_word fn_888C9178();
ts4_word fn_888CB4D0();
ts4_word fn_888D0838();
ts4_word fn_88940FE0();
ts4_word fn_889A05E0();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_object_finalize();
ts4_word ts4_script_string_equals();

/* Swing_DLL.xex 0x88722750: tailcall ts4_call_seq_u32_off540_88721838 */
ts4_word ts4_tailcall_fn_88721838_88722750(ts4_word a0)
{
    return ts4_call_seq_u32_off540_88721838((ts4_word)(a0 + 288));
}

/* Swing_DLL.xex 0x88722758: call_seq ts4_call_seq_u32_off540_88721838, u32@0x34, u32@0x38 */
ts4_word ts4_call_seq_fn_88721838_88722758(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_call_seq_u32_off540_88721838((ts4_word)(a0 + 288));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return t1;
}

