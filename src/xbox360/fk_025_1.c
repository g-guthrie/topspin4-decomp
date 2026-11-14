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
extern char lbl_880CF0C7[];
extern char lbl_880CFC4E[];
extern char lbl_880D0830[];
extern char lbl_880D19F0[];
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880D6D50[];
extern char lbl_880D7058[];
extern char lbl_880D7074[];
extern char lbl_880D72B0[];
extern char lbl_880DB278[];
extern char lbl_880DB300[];
extern char lbl_880DB350[];
extern char lbl_880DB358[];
extern char lbl_880DB450[];
extern char lbl_880DB478[];
extern char lbl_880DB4E0[];
extern char lbl_880DB580[];
extern char lbl_880DB620[];
extern char lbl_880DB6C0[];
extern char lbl_880DB76C[];
extern char lbl_880DB7BC[];
extern char lbl_880DB7E4[];
extern char lbl_880DBD30[];
extern char lbl_8814B440[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B910[];
extern char lbl_88C6B914[];
extern char lbl_88C6B918[];
extern char lbl_88C6B91C[];
extern char lbl_88C6B920[];
extern char lbl_88C6B924[];
extern char lbl_88C6B928[];
extern char lbl_88C6B92C[];
extern char lbl_88C6B930[];
extern char lbl_88D3CD50[];
extern char lbl_88D45908[];
extern char lbl_88D4590C[];
extern char lbl_88D45914[];
extern char lbl_88D4592C[];
extern char lbl_88D45938[];
extern char lbl_88D45944[];
extern char lbl_88D45960[];
extern char lbl_88D459DC[];
extern char lbl_88D459E0[];
extern char lbl_88D45AD4[];
extern char lbl_88D45AF4[];
extern char lbl_88D45AF8[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
extern char lbl_88D46350[];
extern char lbl_88D4BD24[];
extern char lbl_88D4BD34[];
ts4_word fn_88150310();
ts4_word fn_8816D1A8();
ts4_word fn_881705B0();
ts4_word fn_88174B90();
ts4_word fn_88174C40();
ts4_word fn_88177110();
ts4_word fn_88178C40();
ts4_word fn_8817E720();
ts4_word fn_881816D8();
ts4_word fn_881882D0();
ts4_word fn_881A6A00();
ts4_word fn_881B9148();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882908C0();
ts4_word fn_88290C68();
ts4_word fn_8841B618();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_8857A1E0();
ts4_word fn_8857B598();
ts4_word fn_8860BBD8();
ts4_word fn_8860DCF8();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_886220F8();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_886E0E60();
ts4_word fn_886F1FC0();
ts4_word ts4_member_field_addr_8883B578();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_8886B8E0();
ts4_word fn_8886FE50();
ts4_word fn_8886FED0();
ts4_word fn_88870500();
ts4_word fn_888705A0();
ts4_word fn_88871108();
ts4_word fn_888718A8();
ts4_word fn_88871A50();
ts4_word fn_88871BD8();
ts4_word fn_888860A0();
ts4_word fn_888C04D8();
ts4_word ts4_if_get_u32_off10_888C3028();
ts4_word fn_888C39A0();
ts4_word fn_888C6FE0();
ts4_word fn_888CB3F0();
ts4_word fn_888CC2C8();
ts4_word fn_888CC890();
ts4_word fn_888CCCC8();
ts4_word fn_888CEBA8();
ts4_word fn_888D3330();
ts4_word fn_888D3648();
ts4_word fn_888D73B0();
ts4_word fn_888D8078();
ts4_word fn_888DA428();
ts4_word fn_888DA698();
ts4_word fn_888DA850();
ts4_word fn_888DDA80();
ts4_word fn_888DF008();
ts4_word ts4_call_seq_lbl_880DB358_888DF440();
ts4_word ts4_hash_lookup_null_release_888E38A8();
ts4_word ts4_hash_lookup_null_release_888E3908();
ts4_word fn_888F14D8();
ts4_word fn_888F4E70();
ts4_word fn_888F70A0();
ts4_word ts4_if_get_u32_off5c_888FA388();
ts4_word fn_888FBEB0();
ts4_word fn_88901010();
ts4_word fn_88901810();
ts4_word fn_88904C40();
ts4_word fn_88906EE8();
ts4_word fn_88907128();
ts4_word fn_88908258();
ts4_word fn_88908B80();
ts4_word fn_8890F008();
ts4_word fn_88912090();
ts4_word fn_889124A8();
ts4_word fn_88915DC8();
ts4_word fn_88917490();
ts4_word fn_88917CF0();
ts4_word fn_88917EE0();
ts4_word fn_88917FC8();
ts4_word fn_88918908();
ts4_word fn_889189B0();
ts4_word fn_88918EA8();
ts4_word fn_889254C8();
ts4_word fn_8892AF80();
ts4_word fn_8892AFF0();
ts4_word fn_88936BB0();
ts4_word fn_88938660();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_889396A8();
ts4_word fn_8893B328();
ts4_word ts4_read_scaled_counter_8893C808();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x888C7088: if_get u32@0x0, u32@0x14, vcall, u32@0x10, u32@0x30, vcall */
ts4_word ts4_if_get_u32_off0_888C7088(ts4_word a0)
{
    ts4_word p8;
    ts4_word t6;
    ts4_word t7;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 48))))((ts4_word)(a0 + 16));
    p8 = (ts4_word)t6;
    if ((ts4_word)(t6 & 0xff) != 0) {
        t7 = ts4_if_get_u32_off10_888C3028((ts4_word)a0);
        p8 = (ts4_word)t7;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)0;
    return p8;
}

/* Swing_DLL.xex 0x888E69E0: call_seq ts4_call_seq_lbl_880DB358_888DF440, lbl_880DB478, u32@0x68, u32@0x0 */
ts4_word ts4_call_seq_fn_888DF440_888E69E0(ts4_word a0)
{
    ts4_call_seq_lbl_880DB358_888DF440((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB478;
    return a0;
}

/* Swing_DLL.xex 0x888FDC10: call_seq u32@0x84, fn_8857A1E0, ts4_if_get_u32_off5c_888FA388 */
ts4_word ts4_call_seq_u32_off84_888FDC10(ts4_word a0)
{
    ts4_word t3;

    fn_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)));
    t3 = ts4_if_get_u32_off5c_888FA388((ts4_word)a0);
    return t3;
}

