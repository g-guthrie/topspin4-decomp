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
ts4_word fn_881C38D0();
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
ts4_word fn_8875F488();
ts4_word fn_887690A8();
ts4_word fn_8876BCA8();
ts4_word fn_8876CF38();
ts4_word fn_8876D180();
ts4_word fn_88771378();
ts4_word fn_88771440();
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

/* Swing_DLL.xex 0x8871AD10: call_seq u32@0x48, ts4_if_atomic_interlocked_dec_88288530, u32@0x4c, ts4_if_atomic_interlocked_dec_88288530, u32@0x40, ts4_if_atomic_interlocked_dec_88288530 */
ts4_word ts4_call_seq_u32_off48_8871AD10(ts4_word a0)
{
    ts4_word t8;

    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    t8 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)));
    return t8;
}

/* Swing_DLL.xex 0x8871AEC0: if_get fn_88719768, u32@lbl_88D45AD0, u32@0x0, u32@0x38, vcall, fn_88716458 */
ts4_word ts4_if_get_fn_88719768_8871AEC0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88719768((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t2 = *(ts4_word *)lbl_88D45AD0;
        if ((ts4_word)t2 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 56))))((ts4_word)t2, (ts4_word)a1);
        }
        fn_88716458((ts4_word)a0, (ts4_word)a1);
        p8 = (ts4_word)1;
    } else {
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Swing_DLL.xex 0x8871B698: get u32@0x38, fn_887197C8 */
ts4_word ts4_get_u32_off38_8871B698(ts4_word a0, ts4_word a1)
{
    return fn_887197C8((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
}

/* Swing_DLL.xex 0x8871C530: if_call_seq ts4_object_finalize, ts4_object_finalize, u32@0x1c, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_ts4_object_finalize_8871C530(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    ts4_object_finalize((ts4_word)(a0 + 16));
    ts4_object_finalize((ts4_word)(a0 + 28));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0);
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_destroy_owned_object((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x8871DB80: tailcall ts4_if_call_seq_u32_off8_88280958 */
ts4_word ts4_tailcall_fn_88280958_8871DB80(ts4_word a0)
{
    return ts4_if_call_seq_u32_off8_88280958((ts4_word)(a0 + 6368));
}

/* Swing_DLL.xex 0x88720078: tailcall fn_88888668 */
ts4_word ts4_tailcall_fn_88888668_88720078(ts4_word a0)
{
    return fn_88888668((ts4_word)a0, (ts4_word)(3162439680));
}

/* Swing_DLL.xex 0x887215E0: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_887215E0(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_8822C1C8((ts4_word)a0, (ts4_word)32);
    return a0;
}

/* Swing_DLL.xex 0x88721838: call_seq u32@0x540, u32@0x544, u32@0x548, u32@0x54c, u32@0x550, u32@0x554 */
ts4_word ts4_call_seq_u32_off540_88721838(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 1344) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1348) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1352) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1356) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1360) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1364) = (ts4_word)-1;
    fn_8821FBC8((ts4_word)(a0 + 444));
    fn_8821FBC8((ts4_word)(a0 + 460));
    t3 = fn_8821FBC8((ts4_word)(a0 + 476));
    return t3;
}

/* Swing_DLL.xex 0x88721960: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_88721960(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x887219C0: call_seq u32@lbl_88D45AD4, u32@0x1c, ts4_if_call_seq_u32_off8_88280958, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88D45AD4_887219C0(ts4_word a0)
{
    ts4_word t3;

    t3 = ts4_if_call_seq_u32_off8_88280958((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 28)) + 6368));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    return t3;
}

/* Swing_DLL.xex 0x88721BD8: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_88721BD8(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_8822AD70((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88721FB8: call_seq fn_88721CB0, lbl_880F22A8, u32@0x0, u32@lbl_88D45A6C */
ts4_word ts4_call_seq_fn_88721CB0_88721FB8(ts4_word a0)
{
    fn_88721CB0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F22A8;
    *(ts4_word *)lbl_88D45A6C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88722D58: call_seq u32@0x0, fn_88722CA8 */
ts4_word ts4_call_seq_u32_off0_88722D58(ts4_word a0, ts4_word a1)
{
    fn_88722CA8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x88723978: call_seq u32@0xc, u32@lbl_88D45AD4, u32@0x1c, ts4_if_call_seq_u32_off8_88280958, u32@0x8 */
ts4_word ts4_call_seq_u32_offc_88723978(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = ts4_if_call_seq_u32_off8_88280958((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 28)) + 6368));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)-1;
    return t4;
}

/* Swing_DLL.xex 0x88724E28: call_seq fn_88721F10, lbl_880F2540, u32@0x0, u32@0x8, u32@0x38, u32@lbl_88D45AB0 */
ts4_word ts4_call_seq_fn_88721F10_88724E28(ts4_word a0)
{
    fn_88721F10();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2540;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((336068608) | 63697);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)lbl_88D45AB0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887265B8: call_seq u32@0x0, fn_8825DA28 */
ts4_word ts4_call_seq_u32_off0_887265B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_8825DA28((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88727710: get u32@lbl_88D45AD4, u32@0x58, fn_88725348 */
ts4_word ts4_get_u32_lbl_88D45AD4_88727710(void)
{
    return fn_88725348((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 88)));
}

/* Swing_DLL.xex 0x88729600: if_call_seq u32@0x4, u32@0x0, fn_881608E8, ts4_if_call_seq_u32_off0_8816D140, ts4_destroy_owned_object, lbl_880C1320 */
ts4_word ts4_if_call_seq_u32_off4_88729600(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)(t1 - t2) > 5) {
        t3 = fn_881608E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)2, (ts4_word)3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 - t2), (ts4_word)t2);
        ts4_if_call_seq_u32_off0_8816D140((ts4_word)a0, (ts4_word)t3);
        t5 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t5);
    } else {
        ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 - t2), (ts4_word)t2);
    }
    return a0;
}

/* Swing_DLL.xex 0x8872B458: if_call_seq ts4_object_finalize, ts4_object_finalize, fn_88161CF8, fn_88161CF8, u32@0x18, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_ts4_object_finalize_8872B458(ts4_word a0)
{
    ts4_word p12;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    ts4_object_finalize((ts4_word)a0);
    ts4_object_finalize((ts4_word)(a0 + 12));
    fn_88161CF8((ts4_word)(a0 + 24));
    fn_88161CF8((ts4_word)(a0 + 24));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_destroy_owned_object((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x8872B4D0: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_call_seq_u32_off0_8872B4D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t1 = ts4_if_call_seq_u32_lbl_88D45B38_881629B0((ts4_word)(a0 + 24), (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
    *(unsigned char *)((char *)(ts4_word)(t1) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 4) = (ts4_word)0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)t4;
    fn_8822A3D8((ts4_word)a0, (ts4_word)1000);
    fn_8822A3D8((ts4_word)(a0 + 12), (ts4_word)20000);
    return a0;
}

/* Swing_DLL.xex 0x88731410: get u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall, fn_882886B8, u32@0x0 */
ts4_word ts4_get_u32_lbl_88D45A4C_88731410(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    t5 = fn_882886B8((ts4_word)a0, (ts4_word)8, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t5;
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return t8;
}

/* Swing_DLL.xex 0x887315E0: call_seq fn_8816D1A8, fn_88731540, fn_88722AB0, ts4_destroy_owned_object */
ts4_word ts4_call_seq_fn_8816D1A8_887315E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t5;

    fn_8816D1A8((ts4_word)(ts4_word)&loc50[0]);
    fn_88731540((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    fn_88722AB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    t4 = loc50[0];
    t5 = ts4_destroy_owned_object((ts4_word)t4);
    return t5;
}

/* Swing_DLL.xex 0x88732950: call_seq fn_8872CDE0, lbl_880F2C98, u32@0x0, u32@0x8 */
ts4_word ts4_call_seq_fn_8872CDE0_88732950(ts4_word a0)
{
    fn_8872CDE0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2C98;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((2162688) | 7955);
    return a0;
}

/* Swing_DLL.xex 0x88735628: call_seq fn_88220690, u8@0x34 */
ts4_word ts4_call_seq_fn_88220690_88735628(ts4_word a0)
{
    fn_88220690();
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8873B928: get u32@lbl_88D45AD4, fn_8873B890 */
ts4_word ts4_get_u32_lbl_88D45AD4_8873B928(void)
{
    return fn_8873B890((ts4_word)(*(ts4_word *)lbl_88D45AD4));
}

/* Swing_DLL.xex 0x8873F048: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_8873F048(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    fn_8822C518((ts4_word)a0);
    t4 = ts4_find_service((ts4_word)((3525378048) | 45865));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t4;
    t5 = ts4_find_service((ts4_word)((1260912640) | 58003));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
    return a0;
}

/* Swing_DLL.xex 0x8874AD48: get u32@lbl_88D45AD4, u32@0x2f1c */
void ts4_get_u32_lbl_88D45AD4_8874AD48(void)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + ((65536) | 22304)))) + 12060) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8874AD68: get u32@lbl_88D45AD4, u32@0x2f1c */
void ts4_get_u32_lbl_88D45AD4_8874AD68(void)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + ((65536) | 22304)))) + 12060) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x8874BB48: call_seq fn_8873EFC0, fn_88721100 */
ts4_word ts4_call_seq_fn_8873EFC0_8874BB48(ts4_word a0)
{
    ts4_word t2;

    fn_8873EFC0((ts4_word)(a0 + 100));
    t2 = fn_88721100((ts4_word)(a0 + 4));
    return t2;
}

/* Swing_DLL.xex 0x8874EAD0: call_seq fn_8871F260, fn_88748150, fn_882267F0, fn_882266F8 */
ts4_word ts4_call_seq_fn_8871F260_8874EAD0(ts4_word a0)
{
    ts4_word t4;

    fn_8871F260();
    fn_88748150((ts4_word)(a0 + 132));
    fn_882267F0((ts4_word)(a0 + 52));
    t4 = fn_882266F8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88750DC0: get u32@0x3c, u32@0x40, fn_8874B668 */
ts4_word ts4_get_u32_off3c_88750DC0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    return fn_8874B668((ts4_word)a0, (ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x887510C8: call_seq fn_887482D8, u32@0x32c */
ts4_word ts4_call_seq_fn_887482D8_887510C8(ts4_word a0)
{
    fn_887482D8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 812) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88752BD0: call_seq fn_882280B0, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_fn_882280B0_88752BD0(ts4_word a0)
{
    ts4_word t2;

    fn_882280B0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((int)(t2 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) >> 2) + -1);
}

/* Swing_DLL.xex 0x887606D0: get u32@0x1c, fn_8875F488 */
ts4_word ts4_get_u32_off1c_887606D0(ts4_word a0)
{
    return fn_8875F488((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x88769AE0: get u32@0x1c, fn_887690A8, u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall */
ts4_word ts4_get_u32_off1c_88769AE0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t10;

    fn_887690A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t3 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 340))) + 4))))((ts4_word)(t3 + 340));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 340))) + 8))))((ts4_word)(t3 + 340));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t10 = fn_881B9148((ts4_word)(a0 + 16));
    return t10;
}

/* Swing_DLL.xex 0x8876CE58: get u32@lbl_88D45AD4, fn_8876BCA8 */
ts4_word ts4_get_u32_lbl_88D45AD4_8876CE58(void)
{
    return fn_8876BCA8((ts4_word)((*(ts4_word *)lbl_88D45AD4) + 336));
}

/* Swing_DLL.xex 0x8876CE68: if_call_seq fn_88734098, u32@0x1c, u32@lbl_88D45AD4, u32@0x1c, ts4_if_call_seq_u32_off8_88280958, u32@0x8 */
ts4_word ts4_if_call_seq_fn_88734098_8876CE68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((65536) | 22056));
    if ((int)t1 == 6) {
        fn_88734098((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)t1, (ts4_word)((65536) | 22056));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    ts4_if_call_seq_u32_off8_88280958((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 28)) + 6368));
    *(ts4_word *)((char *)(ts4_word)(t4) + 8) = (ts4_word)-1;
    fn_8876BCA8((ts4_word)(a0 + 336));
    fn_88713190((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t12 = fn_886F5700((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)));
    return t12;
}

/* Swing_DLL.xex 0x8876D040: get u32@0x1c, fn_8876CF38 */
ts4_word ts4_get_u32_off1c_8876D040(ts4_word a0)
{
    return fn_8876CF38((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x8876D048: call_seq fn_8876CF38, fn_8875F488 */
ts4_word ts4_call_seq_fn_8876CF38_8876D048(ts4_word a0)
{
    ts4_word t2;

    fn_8876CF38((ts4_word)a0);
    t2 = fn_8875F488((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8876D0B0: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_8876D0B0(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x8876D0E0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8876D0E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8876DE98: call_seq ts4_object_finalize, fn_8876D180 */
ts4_word ts4_call_seq_ts4_object_finalize_8876DE98(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 84));
    t2 = fn_8876D180((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8876E058: if_get u32@0x0, fn_88608590, ts4_find_service, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_if_get_u32_off0_8876E058(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t3 = ts4_find_service((ts4_word)t2);
    p7 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 76))))((ts4_word)t3, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t6;
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x8876E310: set u8@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u8_off0_8876E310(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8876E328: set u8@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u8_off0_8876E328(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8876E340: set u8@0x14 */
void ts4_set_u8_off14_8876E340(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88771768: addr lbl_880C91A3, fn_88771440 */
ts4_word ts4_addr_lbl_880C91A3_88771768(void)
{
    return fn_88771440((ts4_word)(ts4_word)lbl_880C91A3);
}

/* Swing_DLL.xex 0x88771778: call_seq lbl_880C91A2, fn_88771440, fn_88771378 */
ts4_word ts4_call_seq_lbl_880C91A2_88771778(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88771440((ts4_word)(ts4_word)lbl_880C91A2);
    t2 = fn_88771378((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88771E10: call_seq lbl_880C91A3, fn_88771440, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C91A3_88771E10(ts4_word a0)
{
    ts4_word t2;

    fn_88771440((ts4_word)(ts4_word)lbl_880C91A3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88772D10: call_seq fn_88617D88, lbl_880EFE30, u32@0x0, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_88772D10(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFE30;
    fn_8816D1A8((ts4_word)(a0 + 28));
    return a0;
}

/* Swing_DLL.xex 0x88775E58: call_seq u32@0x74, u32@0x70, fn_88150310, fn_8876D180 */
ts4_word ts4_call_seq_u32_off74_88775E58(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    fn_88150310((ts4_word)(a0 + 112), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)), (ts4_word)t1);
    t4 = fn_8876D180((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887782A8: addr lbl_88C47840 */
ts4_word ts4_addr_lbl_88C47840_887782A8(void)
{
    return (ts4_word)lbl_88C47840;
}

/* Swing_DLL.xex 0x887782B8: addr lbl_88C47734 */
ts4_word ts4_addr_lbl_88C47734_887782B8(void)
{
    return (ts4_word)lbl_88C47734;
}

/* Swing_DLL.xex 0x88778338: addr lbl_88C476F4 */
ts4_word ts4_addr_lbl_88C476F4_88778338(void)
{
    return (ts4_word)lbl_88C476F4;
}

/* Swing_DLL.xex 0x88778378: addr lbl_88C476C0, u32@0x10 */
ts4_word ts4_addr_lbl_88C476C0_88778378(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C476C0) + 16));
}

/* Swing_DLL.xex 0x88778388: addr lbl_88C476C0 */
ts4_word ts4_addr_lbl_88C476C0_88778388(void)
{
    return (ts4_word)lbl_88C476C0;
}

/* Swing_DLL.xex 0x887783B8: addr lbl_88C4768C */
ts4_word ts4_addr_lbl_88C4768C_887783B8(void)
{
    return (ts4_word)lbl_88C4768C;
}

/* Swing_DLL.xex 0x887783C8: addr lbl_88C47670 */
ts4_word ts4_addr_lbl_88C47670_887783C8(void)
{
    return (ts4_word)lbl_88C47670;
}

/* Swing_DLL.xex 0x887783D8: addr lbl_88C47658, u32@0x10 */
ts4_word ts4_addr_lbl_88C47658_887783D8(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C47658) + 16));
}

/* Swing_DLL.xex 0x887783E8: addr lbl_88C47658 */
ts4_word ts4_addr_lbl_88C47658_887783E8(void)
{
    return (ts4_word)lbl_88C47658;
}

/* Swing_DLL.xex 0x88778418: get u32@0x0, u32@0x24, vcall, u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_88778418(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
    return ((t3 - t6) == 0);
}

/* Swing_DLL.xex 0x88778480: addr lbl_88C47630 */
ts4_word ts4_addr_lbl_88C47630_88778480(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_88C47630));
}

/* Swing_DLL.xex 0x88778498: addr lbl_88C47614 */
ts4_word ts4_addr_lbl_88C47614_88778498(void)
{
    return (ts4_word)lbl_88C47614;
}

/* Swing_DLL.xex 0x887785E0: fn  */
ts4_word ts4_fn_887785E0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887785E8: fn  */
ts4_word ts4_fn_887785E8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887785F0: fn  */
ts4_word ts4_fn_887785F0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887785F8: fn  */
ts4_word ts4_fn_887785F8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778600: fn  */
ts4_word ts4_fn_88778600(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778608: fn  */
ts4_word ts4_fn_88778608(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778610: fn  */
ts4_word ts4_fn_88778610(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778618: fn  */
ts4_word ts4_fn_88778618(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778620: fn  */
ts4_word ts4_fn_88778620(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778628: fn  */
ts4_word ts4_fn_88778628(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778630: fn  */
ts4_word ts4_fn_88778630(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778638: fn  */
ts4_word ts4_fn_88778638(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778640: fn  */
ts4_word ts4_fn_88778640(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88778648: fn  */
ts4_word ts4_fn_88778648(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778650: fn  */
ts4_word ts4_fn_88778650(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88778658: fn  */
ts4_word ts4_fn_88778658(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778660: fn  */
ts4_word ts4_fn_88778660(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88778668: fn  */
ts4_word ts4_fn_88778668(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778670: fn  */
ts4_word ts4_fn_88778670(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88778678: get u8@lbl_88C4589D */
ts4_word ts4_get_u8_lbl_88C4589D_88778678(void)
{
    return (*(unsigned char *)lbl_88C4589D);
}

/* Swing_DLL.xex 0x88778688: get u8@lbl_88D45B06 */
ts4_word ts4_get_u8_lbl_88D45B06_88778688(void)
{
    return (*(unsigned char *)lbl_88D45B06);
}

/* Swing_DLL.xex 0x887786D8: fn  */
ts4_word ts4_fn_887786D8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887786E0: fn  */
ts4_word ts4_fn_887786E0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887786E8: fn  */
ts4_word ts4_fn_887786E8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887786F0: fn  */
ts4_word ts4_fn_887786F0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x887786F8: get u8@0xc9 */
ts4_word ts4_get_u8_offc9_887786F8(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 201));
}

/* Swing_DLL.xex 0x88778700: if_get u8@0x64, u16@0x54, u16@0x56, u16@0x56 */
void ts4_if_get_u8_off64_88778700(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t1 == 1) {
        *(unsigned short *)((char *)(ts4_word)(a0) + 84) = (unsigned short)20000;
        *(unsigned short *)((char *)(ts4_word)(a0) + 86) = (unsigned short)20000;
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 86) = (unsigned short)20000;
    return;
}

/* Swing_DLL.xex 0x88778C90: set u32@0x3c34 */
void ts4_set_u32_off3c34_88778C90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 15412) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88778D28: get u32@g_ts4_session_context */
ts4_word ts4_get_u32_g_ts4_session_context_88778D28(void)
{
    return (*(ts4_word *)g_ts4_session_context);
}

/* Swing_DLL.xex 0x88778D38: call_seq u32@0x0, u32@0x8, u32@0x4, ts4_object_finalize, u32@0x18, u8@0x28 */
ts4_word ts4_call_seq_u32_off0_88778D38(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t1 = ts4_object_finalize((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x88778E78: get u32@0x0, u32@0x34 */
ts4_word ts4_get_u32_off0_88778E78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x887791D0: set u8@0x65, u32@0x4c, u32@0x50, u32@0x6c, u32@0x7c, u32@0x84 */
void ts4_set_u8_off65_887791D0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 101) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 141) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 138) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)9;
    *(unsigned short *)((char *)(ts4_word)(a0) + 84) = (unsigned short)20000;
    *(unsigned short *)((char *)(ts4_word)(a0) + 86) = (unsigned short)20000;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 139) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 148) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 149) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 142) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 143) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)30;
    return;
}

/* Swing_DLL.xex 0x887793D0: set u32@0x1cc, u32@0x1d4, u32@0x1d0 */
void ts4_set_u32_off1cc_887793D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 460) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x88779558: get u32@lbl_88D45A60, u8@0x1f9 */
ts4_word ts4_get_u32_lbl_88D45A60_88779558(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 505));
}

/* Swing_DLL.xex 0x88779568: get u32@lbl_88D45A60, u32@0x314 */
ts4_word ts4_get_u32_lbl_88D45A60_88779568(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 788));
}

/* Swing_DLL.xex 0x88779588: addr lbl_880EF6B8, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880EF6B8_88779588(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF6B8;
    return;
}

/* Swing_DLL.xex 0x887795B8: get u32@0x70 */
ts4_word ts4_get_u32_off70_887795B8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 112));
}

/* Swing_DLL.xex 0x88779678: get u32@0x28 */
ts4_word ts4_get_u32_off28_88779678(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 40));
}

/* Swing_DLL.xex 0x88779680: get  */
void ts4_get_88779680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 72) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x88779690: get  */
float ts4_get_88779690(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 72));
}

/* Swing_DLL.xex 0x88779698: get  */
void ts4_get_88779698(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 68) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x887796B0: get  */
void ts4_get_887796B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 64) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x887796C0: get  */
float ts4_get_887796C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 64));
}

/* Swing_DLL.xex 0x887796C8: get  */
void ts4_get_887796C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x887796D8: get  */
float ts4_get_887796D8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 60));
}

/* Swing_DLL.xex 0x887796E0: get  */
void ts4_get_887796E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x887796F0: get  */
float ts4_get_887796F0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 56));
}

/* Swing_DLL.xex 0x88779710: if_get u32@0x18, u32@0x0, u32@0x14, u32@0x10, u32@0x0, u32@0x24 */
ts4_word ts4_if_get_u32_off18_88779710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 36))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88779748: if_get u32@0x18, u32@0x0, u32@0x18, u32@0x10, u32@0x0, u32@0xc */
ts4_word ts4_if_get_u32_off18_88779748(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 12))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88779780: set u32@0x8 */
void ts4_set_u32_off8_88779780(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887797B0: get u32@lbl_88D45A60 */
ts4_word ts4_get_u32_lbl_88D45A60_887797B0(void)
{
    return ((*(ts4_word *)lbl_88D45A60) + 148);
}

/* Swing_DLL.xex 0x88779828: get u32@0x28, u8@0x10 */
void ts4_get_u32_off28_88779828(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88779840: set u32@0x20 */
void ts4_set_u32_off20_88779840(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88779848: set u32@0x20 */
void ts4_set_u32_off20_88779848(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88779850: set u32@0x20 */
void ts4_set_u32_off20_88779850(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x887798C0: addr lbl_880EF46C, u32@0x4, u32@0x0, u32@0x8, u32@0x3c34 */
void ts4_addr_lbl_880EF46C_887798C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF46C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15412) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88779900: if_get u32@0x4, u8@0x10c */
ts4_word ts4_if_get_u32_off4_88779900(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        return ((*(unsigned char *)((char *)(ts4_word)(t1) + 268)) == 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x88779928: if_call_seq u32@lbl_88D45870, fn_88940FE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45870_88779928(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)lbl_88D45870;
    if ((ts4_word)t1 != 0) {
        fn_88940FE0((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88779A50: if_call_seq u32@lbl_88D45B0C, ts4_if_get_u32_off1c_88655518 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B0C_88779A50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)lbl_88D45B0C;
    if ((ts4_word)t1 != 0) {
        ts4_if_get_u32_off1c_88655518((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88779A88: get u32@lbl_88D45A60, u8@0x320 */
ts4_word ts4_get_u32_lbl_88D45A60_88779A88(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 800));
}

/* Swing_DLL.xex 0x88779B90: addr lbl_880EF7EC, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880EF7EC_88779B90(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF7EC;
    return;
}

/* Swing_DLL.xex 0x88779F40: get u32@0x70, u32@lbl_88C6CBF0 */
ts4_word ts4_get_u32_off70_88779F40(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    return (((*(ts4_word *)lbl_88C6CBF0) - t1) != 0);
}

/* Swing_DLL.xex 0x88779F70: addr lbl_880EF6C4, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880EF6C4_88779F70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF6C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88779F90: get u32@lbl_88D45A60, u32@0x90 */
ts4_word ts4_get_u32_lbl_88D45A60_88779F90(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 144));
}

/* Swing_DLL.xex 0x88779FA0: get u32@lbl_88D45A60, u32@0x88 */
ts4_word ts4_get_u32_lbl_88D45A60_88779FA0(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 136));
}

/* Swing_DLL.xex 0x88779FB0: get u32@lbl_88D45A60, u32@0x8c */
ts4_word ts4_get_u32_lbl_88D45A60_88779FB0(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 140));
}

/* Swing_DLL.xex 0x88779FC0: get u32@lbl_88D45A60, u32@0x84 */
ts4_word ts4_get_u32_lbl_88D45A60_88779FC0(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 132));
}

/* Swing_DLL.xex 0x8877A130: if_get u32@0x24, u8@0xc6, u32@0x3c, u32@0xc8, u32@0x24, u8@0xdc */
void ts4_if_get_u32_off24_8877A130(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    if ((ts4_word)t1 == (ts4_word)((680001536) | 54827)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 198) = (unsigned char)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    if ((ts4_word)t4 != (ts4_word)((2933981184) | 37553)) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 220) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8877A380: set u32@0x20, u8@0x648 */
void ts4_set_u32_off20_8877A380(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1608) = (unsigned char)a2;
    return;
}

/* Swing_DLL.xex 0x8877A5F8: fn  */
ts4_word ts4_fn_8877A5F8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A600: fn  */
ts4_word ts4_fn_8877A600(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A6F8: fn  */
ts4_word ts4_fn_8877A6F8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A700: fn  */
ts4_word ts4_fn_8877A700(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A708: fn  */
ts4_word ts4_fn_8877A708(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A710: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_8877A710(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 1) {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 896)) + 56);
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    return 0;
}

/* Swing_DLL.xex 0x8877A768: fn  */
ts4_word ts4_fn_8877A768(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A770: get u32@lbl_88D45958, u32@0x1c */
ts4_word ts4_get_u32_lbl_88D45958_8877A770(void)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45958)) + 28) = (ts4_word)1;
    return 0;
}

/* Swing_DLL.xex 0x8877A788: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_8877A788(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 1) {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 896)) + 56);
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    return 1;
}

/* Swing_DLL.xex 0x8877A7E0: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_8877A7E0(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 1) {
        p5 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 896)) + 56);
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    return 1;
}

/* Swing_DLL.xex 0x8877A838: fn  */
ts4_word ts4_fn_8877A838(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8877A840: fn  */
ts4_word ts4_fn_8877A840(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8877A848: fn  */
ts4_word ts4_fn_8877A848(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A850: fn  */
ts4_word ts4_fn_8877A850(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A858: fn  */
ts4_word ts4_fn_8877A858(void)
{
    return 1;
}

/* Swing_DLL.xex 0x8877A860: fn  */
ts4_word ts4_fn_8877A860(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A868: fn  */
ts4_word ts4_fn_8877A868(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877A870: fn  */
ts4_word ts4_fn_8877A870(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877B2A0: call_seq ts4_if_call_seq_ts4_find_service_888C1C28 */
ts4_word ts4_call_seq_fn_888C1C28_8877B2A0(void)
{
    ts4_if_call_seq_ts4_find_service_888C1C28();
    return 0;
}

/* Swing_DLL.xex 0x8877B870: fn  */
ts4_word ts4_fn_8877B870(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877BB60: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_8877BB60(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    t6 = ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45954)) + 56) = (unsigned char)t6;
    return 0;
}

/* Swing_DLL.xex 0x8877BC28: if_call_seq u32@lbl_88D45870, fn_88940FE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45870_8877BC28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)lbl_88D45870;
    if ((ts4_word)t1 != 0) {
        fn_88940FE0((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x8877BC60: if_call_seq u32@lbl_88D45870, fn_88940FE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45870_8877BC60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)lbl_88D45870;
    if ((ts4_word)t1 != 0) {
        fn_88940FE0((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x8877C350: get u32@lbl_88D45A04, u8@0x29 */
ts4_word ts4_get_u32_lbl_88D45A04_8877C350(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A04)) + 41));
}

/* Swing_DLL.xex 0x8877C360: get u32@lbl_88D45A04, u8@0x28 */
ts4_word ts4_get_u32_lbl_88D45A04_8877C360(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A04)) + 40));
}

/* Swing_DLL.xex 0x8877C370: fn  */
ts4_word ts4_fn_8877C370(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877C378: fn  */
ts4_word ts4_fn_8877C378(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877C380: fn  */
ts4_word ts4_fn_8877C380(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877C388: fn  */
ts4_word ts4_fn_8877C388(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877C390: fn  */
ts4_word ts4_fn_8877C390(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8877C398: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_8877C398(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    return 0;
}

/* Swing_DLL.xex 0x8877C808: get u32@lbl_88D45A60, u8@0x1e8 */
ts4_word ts4_get_u32_lbl_88D45A60_8877C808(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 488));
}

/* Swing_DLL.xex 0x8877C818: get u32@lbl_88D45A60, u8@0x1e */
ts4_word ts4_get_u32_lbl_88D45A60_8877C818(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 30));
}

/* Swing_DLL.xex 0x8877D720: call_seq u32@lbl_88D459F4, fn_88803198 */
ts4_word ts4_call_seq_u32_lbl_88D459F4_8877D720(void)
{
    ts4_word loc50[1];
    ts4_word t2;

    loc50[0] = (ts4_word)((4258463744) | 6070);
    t2 = fn_88803198((ts4_word)(*(ts4_word *)lbl_88D459F4), (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8877DCB8: set u32@0x20, u32@0x24, u32@0x28, u32@0x650 */
void ts4_set_u32_off20_8877DCB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1616) = (ts4_word)a3;
    return;
}

/* Swing_DLL.xex 0x8877DCD0: call_seq lbl_880EF4A0, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_call_seq_lbl_880EF4A0_8877DCD0(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4A0;
    fn_8877DC48((ts4_word)(a0 + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t2 = fn_8860BBD8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8877DD20: call_seq lbl_880EF4D8, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_call_seq_lbl_880EF4D8_8877DD20(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4D8;
    fn_8877DC48((ts4_word)(a0 + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t2 = fn_8860BBD8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8877DD70: call_seq lbl_880EF4BC, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_call_seq_lbl_880EF4BC_8877DD70(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4BC;
    fn_8877DC48((ts4_word)(a0 + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t2 = fn_8860BBD8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x8877DE38: if_get u32@0x2c, lbl_880EF484, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off2c_8877DE38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF484;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    fn_8877DC48((ts4_word)(a0 + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t7 = fn_8860BBD8((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8877DFE0: get u32@0x0, u32@0x20 */
void ts4_get_u32_off0_8877DFE0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x8877DFF0: if_call_seq lbl_880EF580, u32@0x0, fn_8877DF00, u32@0x24, ts4_destroy_owned_object, lbl_880E4BA0 */
ts4_word ts4_if_call_seq_lbl_880EF580_8877DFF0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF580;
    fn_8877DF00();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x8877E330: call_seq u32@lbl_88D45A60, u32@0x314, ts4_loop_get_u32_lbl_88D45B1C_88865818 */
ts4_word ts4_call_seq_u32_lbl_88D45A60_8877E330(void)
{
    ts4_loop_get_u32_lbl_88D45B1C_88865818((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 788)));
    return 0;
}

/* Swing_DLL.xex 0x8877F2C8: addr lbl_88D45CC0, u8@0x8 */
ts4_word ts4_addr_lbl_88D45CC0_8877F2C8(void)
{
    *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 8) = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x88781350: call_seq fn_881C38D0, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_fn_881C38D0_88781350(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    loc50[0] = (ts4_word)0;
    fn_881C38D0((ts4_word)(a0 + 28), (ts4_word)(ts4_word)&loc50[0]);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88781DE8: if_call_seq u32@0x854, lbl_880EF62C, u32@0x0, fn_888860A0, u32@0x85c, u32@0x854 */
ts4_word ts4_if_call_seq_u32_off854_88781DE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2132);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF62C;
    if ((int)t1 != 0) {
        fn_888860A0((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 2140);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2136) = (ts4_word)0;
    if ((int)t4 != 0) {
        fn_888860A0((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 2148);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2144) = (ts4_word)0;
    if ((int)t7 != 0) {
        fn_888860A0((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 2156);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2152) = (ts4_word)0;
    if ((int)t10 != 0) {
        fn_888860A0((ts4_word)t10);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 2156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2160) = (ts4_word)0;
    fn_8877DC48((ts4_word)(a0 + 556));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t14 = fn_8860BBD8((ts4_word)a0);
    return t14;
}

/* Swing_DLL.xex 0x88781F50: call_seq lbl_880EF47C, u32@0x4, u32@0x0, fn_88152DF8, u32@0x614, u32@0x618 */
ts4_word ts4_call_seq_lbl_880EF47C_88781F50(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF47C;
    t1 = fn_88152DF8((ts4_word)(a0 + 1544));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1560) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1564) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1568) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1569) = (unsigned char)0;
    t2 = ts4_if_call_seq_u32_lbl_88D45B38_88215B88((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1560) = (ts4_word)t2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 520) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1032) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88782320: if_call_seq u32@0x1094, lbl_880EF5F4, u32@0x0, fn_888860A0, u32@0x1098, fn_888860A0 */
ts4_word ts4_if_call_seq_u32_off1094_88782320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4244);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF5F4;
    if ((int)t1 != 0) {
        fn_888860A0((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4248);
    if ((int)t4 != 0) {
        fn_888860A0((ts4_word)t4);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4248) = (ts4_word)0;
    fn_8877DC48((ts4_word)(a0 + 2664));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2652)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    t10 = fn_8860BBD8((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x88782B90: call_seq ts4_find_service, fn_888CB4D0 */
ts4_word ts4_call_seq_ts4_find_service_88782B90(void)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((279773184) | 64090));
    fn_888CB4D0((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x88782D18: if_call_seq u32@0x10, u32@0x384, u32@0x380, u32@g_ts4_default_script_value, g_ts4_true_string, ts4_script_string_equals */
ts4_word ts4_if_call_seq_u32_off10_88782D18(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    if ((ts4_word)t2 > 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p5 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    t6 = ts4_script_string_equals((ts4_word)(p5 + 16), (ts4_word)(ts4_word)g_ts4_true_string);
    fn_888C9178((ts4_word)(*(ts4_word *)lbl_88D45954), (ts4_word)t6);
    return 0;
}

/* Swing_DLL.xex 0x88782EC0: if_call_seq u32@lbl_88D45898, u32@0x20, u8@0x43, ts4_set_u8_off42_887F9318 */
ts4_word ts4_if_call_seq_u32_lbl_88D45898_88782EC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    unsigned char t3;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45898)) + 32);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 67);
    if ((ts4_word)t3 == 0) {
        ts4_set_u8_off42_887F9318((ts4_word)t2);
    }
    return 0;
}

/* Swing_DLL.xex 0x88782F00: call_seq u32@lbl_88D45954, fn_888C8190 */
ts4_word ts4_call_seq_u32_lbl_88D45954_88782F00(void)
{
    fn_888C8190((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x88782F30: call_seq u32@lbl_88D45954, fn_888C8230 */
ts4_word ts4_call_seq_u32_lbl_88D45954_88782F30(void)
{
    fn_888C8230((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x887832C0: call_seq u32@lbl_88D45954, fn_888C87D8 */
ts4_word ts4_call_seq_u32_lbl_88D45954_887832C0(void)
{
    fn_888C87D8((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x887832F0: call_seq u32@lbl_88D45954, fn_888C8B30 */
ts4_word ts4_call_seq_u32_lbl_88D45954_887832F0(void)
{
    fn_888C8B30((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x88783320: call_seq u32@lbl_88D45954, fn_888C82D0 */
ts4_word ts4_call_seq_u32_lbl_88D45954_88783320(void)
{
    fn_888C82D0((ts4_word)(*(ts4_word *)lbl_88D45954));
    return 0;
}

/* Swing_DLL.xex 0x88783450: call_seq u32@lbl_88D4594C, u8@0x38, ts4_object_finalize */
ts4_word ts4_call_seq_u32_lbl_88D4594C_88783450(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D4594C;
    *(unsigned char *)((char *)(ts4_word)(t1) + 56) = (unsigned char)0;
    ts4_object_finalize((ts4_word)(t1 + 32));
    return 0;
}

/* Swing_DLL.xex 0x88783520: if_call_seq ts4_find_service, fn_889A05E0 */
ts4_word ts4_if_call_seq_ts4_find_service_88783520(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((102432768) | 19064));
    if ((ts4_word)t1 != 0) {
        t2 = fn_889A05E0((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88783E88: get u32@lbl_88D45A0C, fn_887EB080 */
ts4_word ts4_get_u32_lbl_88D45A0C_88783E88(void)
{
    return fn_887EB080((ts4_word)(*(ts4_word *)lbl_88D45A0C));
}

/* Swing_DLL.xex 0x88783F88: call_seq u32@lbl_88D459DC, u32@lbl_88D45A04, fn_887EB4A0, ts4_object_finalize */
ts4_word ts4_call_seq_u32_lbl_88D459DC_88783F88(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D459DC;
    fn_887EB4A0((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(t1 + 68));
    ts4_object_finalize((ts4_word)(t1 + 68));
    return 0;
}

/* Swing_DLL.xex 0x88784068: if_call_seq ts4_object_finalize, u32@0xc, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_ts4_object_finalize_88784068(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    ts4_object_finalize((ts4_word)(a0 + 12));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = ts4_destroy_owned_object((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x887840A8: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_887840A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_88166BC0((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    return a0;
}

/* Swing_DLL.xex 0x88784128: set u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_88784128(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88784B40: get u32@lbl_88D45A60, fn_881AAE70 */
ts4_word ts4_get_u32_lbl_88D45A60_88784B40(ts4_word a0)
{
    return fn_881AAE70((ts4_word)((*(ts4_word *)lbl_88D45A60) + 148), (ts4_word)a0);
}

/* Swing_DLL.xex 0x88784F10: tailcall fn_88784DC8 */
ts4_word ts4_tailcall_fn_88784DC8_88784F10(ts4_word a0)
{
    return fn_88784DC8((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x88785288: tailcall fn_88784DC8 */
ts4_word ts4_tailcall_fn_88784DC8_88785288(ts4_word a0)
{
    return fn_88784DC8((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88785290: if_call_seq u32@lbl_88D45954, fn_888D0838, u32@0x108, fn_88778BE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45954_88785290(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45954;
    if ((ts4_word)t1 != 0) {
        fn_888D0838((ts4_word)t1, (ts4_word)((3535798272) | 44736));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
    t4 = fn_88778BE8((ts4_word)a0, (ts4_word)3);
    return t4;
}
