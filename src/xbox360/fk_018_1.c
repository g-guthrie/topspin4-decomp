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

extern char lbl_880D19F0[];
extern char lbl_880D1F0C[];
extern char lbl_880D3BA8[];
extern char lbl_880E196C[];
extern char lbl_880E7620[];
extern char lbl_880F20E8[];
extern char lbl_880F7940[];
extern char lbl_880F7AEC[];
extern char lbl_880F7B28[];
extern char lbl_880F7C10[];
extern char lbl_880F7D28[];
extern char lbl_880F7DB0[];
extern char lbl_880F7EA0[];
extern char lbl_880F7F38[];
extern char lbl_880F80D0[];
extern char lbl_880F81C0[];
extern char lbl_880F8280[];
extern char lbl_880F83C0[];
extern char lbl_880F86A8[];
extern char lbl_880F8748[];
extern char lbl_880F8888[];
extern char lbl_880F89A0[];
extern char lbl_880F8A40[];
extern char lbl_880F8BF4[];
extern char lbl_880F8C44[];
extern char lbl_880F8CF8[];
extern char lbl_880F8D28[];
extern char lbl_88C4589D[];
extern char lbl_88D41F80[];
extern char lbl_88D41FC0[];
extern char lbl_88D4528C[];
extern char lbl_88D45290[];
extern char lbl_88D45930[];
extern char lbl_88D45B06[];
extern char lbl_88D45B14[];
extern char lbl_88D45B18[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B2C[];
extern char lbl_88D45B38[];
ts4_word RtlInitializeCriticalSection();
ts4_word fn_88150310();
ts4_word fn_881506A0();
ts4_word fn_88152DF8();
ts4_word ts4_if_call_seq_u32_off8_88160D30();
ts4_word fn_881705B0();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_88198CE0();
ts4_word fn_881A4F30();
ts4_word fn_881A5088();
ts4_word fn_881A50F0();
ts4_word fn_881B9148();
ts4_word fn_88280A50();
ts4_word fn_88280E60();
ts4_word fn_883C6460();
ts4_word fn_883CB4A0();
ts4_word fn_883CB4F0();
ts4_word fn_8857A1E0();
ts4_word fn_8857A720();
ts4_word fn_8857A8A0();
ts4_word fn_88606788();
ts4_word fn_88608590();
ts4_word fn_88609F90();
ts4_word fn_8860BBD8();
ts4_word fn_8860C128();
ts4_word fn_8860D250();
ts4_word ts4_loop_call_seq_RtlEnterCriticalSection_8860D8E8();
ts4_word fn_8860DCF8();
ts4_word ts4_if_get_u32_lbl_88D45B1C_8860F998();
ts4_word fn_8860FA68();
ts4_word fn_8860FF08();
ts4_word fn_88613268();
ts4_word fn_88613418();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word ts4_if_call_seq_u8_off68_886195A0();
ts4_word fn_88619628();
ts4_word fn_886197F0();
ts4_word fn_8861A720();
ts4_word fn_8861AA20();
ts4_word fn_8861B128();
ts4_word fn_8861B4D8();
ts4_word ts4_if_call_seq_u8_off824_8861B790();
ts4_word fn_8861B8E0();
ts4_word fn_8861C4F0();
ts4_word fn_8861C830();
ts4_word fn_8861E938();
ts4_word fn_88625478();
ts4_word fn_88625798();
ts4_word ts4_name_keys_register_88626F70();
ts4_word fn_88627B30();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88628E70();
ts4_word fn_8862BB50();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_8862C210();
ts4_word fn_8862CC90();
ts4_word fn_8862E858();
ts4_word fn_886328B0();
ts4_word fn_886376E0();
ts4_word fn_886378F0();
ts4_word fn_88637BF0();
ts4_word fn_88637F10();
ts4_word fn_88638100();
ts4_word fn_88638188();
ts4_word fn_88638210();
ts4_word fn_88638418();
ts4_word fn_88638770();
ts4_word fn_88638918();
ts4_word ts4_if_get_u32_off84_886389E8();
ts4_word fn_8863A8F0();
ts4_word fn_8863AA58();
ts4_word fn_8863AE08();
ts4_word fn_8863B6E8();
ts4_word fn_8863B7B8();
ts4_word fn_8863B9F0();
ts4_word fn_8863DC80();
ts4_word fn_8863DF58();
ts4_word fn_8863EF50();
ts4_word ts4_if_call_seq_fn_88162BB8_8863EFF0();
ts4_word fn_8863F068();
ts4_word fn_8863F858();
ts4_word fn_88640150();
ts4_word fn_88640968();
ts4_word fn_886412C0();
ts4_word fn_88641970();
ts4_word fn_88641A58();
ts4_word fn_88644138();
ts4_word fn_88883CD0();
ts4_word fn_888860A0();
ts4_word fn_88888338();
ts4_word fn_888D7230();
ts4_word fn_888D72F0();
ts4_word fn_888DF110();
ts4_word fn_8892AF80();
ts4_word fn_8892EB28();
ts4_word ts4_if_call_seq_u32_off8_8892ED88();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8860FA58: get u32@0x0, ts4_if_get_u32_lbl_88D45B1C_8860F998 */
ts4_word ts4_get_u32_off0_8860FA58(ts4_word a0, ts4_word a1)
{
    return ts4_if_get_u32_lbl_88D45B1C_8860F998((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88610250: call_seq u32@0x4, u32@0x0, u32@0x8, u32@0x4, u32@0x4, ts4_if_get_u32_lbl_88D45B1C_8860F998 */
ts4_word ts4_call_seq_u32_off4_88610250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t3 = ts4_if_get_u32_lbl_88D45B1C_8860F998((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)a3, (ts4_word)t1, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x88638C50: get u32@lbl_88D45B18, ts4_if_get_u32_off84_886389E8 */
ts4_word ts4_get_u32_lbl_88D45B18_88638C50(void)
{
    return ts4_if_get_u32_off84_886389E8((ts4_word)(*(ts4_word *)lbl_88D45B18));
}

