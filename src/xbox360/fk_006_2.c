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

extern char lbl_88028B5C[];
extern char lbl_88028BB4[];
extern char lbl_88028D18[];
extern char lbl_88028DE4[];
extern char lbl_88028EA4[];
extern char lbl_88028F78[];
extern char lbl_88028F80[];
extern char lbl_88028FA0[];
extern char lbl_880291FC[];
extern char lbl_88029204[];
extern char lbl_8802924C[];
extern char lbl_880292C8[];
extern char lbl_88029348[];
extern char lbl_8802936C[];
extern char lbl_880293EC[];
extern char lbl_880293F4[];
extern char lbl_88029544[];
extern char lbl_8802B0B4[];
extern char lbl_8802B7FC[];
extern char lbl_8802BA10[];
extern char lbl_8802BAA0[];
extern char lbl_8802BB80[];
extern char lbl_8802BDD8[];
extern char lbl_8802BE04[];
extern char lbl_8802BE30[];
extern char lbl_8802BE4C[];
extern char lbl_8802BE58[];
extern char lbl_8802BE90[];
extern char lbl_880C1320[];
extern char lbl_88B3302C[];
extern char lbl_88B3AA40[];
extern char lbl_88C6E260[];
extern char lbl_88C74994[];
extern char lbl_88C922E4[];
extern char lbl_88C922F4[];
extern char ts4_adjust_minus_28_thunk_8832ADF0[];
extern char ts4_forward_88315998[];
extern char ts4_forward_883159A0[];
extern char ts4_forward_883159A8[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word ts4_if_get_u32_offe4_88309B78();
ts4_word fn_8830C628();
ts4_word fn_8830F378();
ts4_word fn_88314478();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word fn_88316460();
ts4_word fn_883179C0();
ts4_word ts4_addr_lbl_88028B5C_88318518();
ts4_word fn_88318550();
ts4_word fn_88318638();
ts4_word fn_883194F0();
ts4_word fn_88319E00();
ts4_word ts4_call_seq_u32_off158_88319F08();
ts4_word fn_8831A058();
ts4_word ts4_if_call_seq_fn_8857A1E0_8831A740();
ts4_word fn_8831A830();
ts4_word ts4_if_call_seq_lbl_88028EA4_8831ACF0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word fn_8831CBA8();
ts4_word fn_8831CD30();
ts4_word fn_8831CE30();
ts4_word fn_8831DAC0();
ts4_word fn_8831E730();
ts4_word fn_8831E890();
ts4_word fn_88322CA8();
ts4_word fn_88324160();
ts4_word fn_88324B90();
ts4_word fn_88324EE0();
ts4_word fn_88326940();
ts4_word fn_88327480();
ts4_word fn_88327878();
ts4_word ts4_tailcall_fn_88327480_88328670();
ts4_word fn_883290D0();
ts4_word ts4_strlen_88329658();
ts4_word fn_883296A0();
ts4_word fn_8832AEE0();
ts4_word ts4_if_set_u32_off0_8832BFC0();
ts4_word ts4_if_get_u32_off238_8832C2E8();
ts4_word fn_8832D4F0();
ts4_word fn_8832E508();
ts4_word fn_8832E690();
ts4_word ts4_addr_lbl_880292C8_8832E758();
ts4_word fn_8832EDB0();
ts4_word ts4_if_set_u32_off0_8832F930();
ts4_word fn_883300E8();
ts4_word fn_88330278();
ts4_word fn_883306D8();
ts4_word ts4_if_get_u32_off14_88330948();
ts4_word ts4_addr_lbl_88029348_88332070();
ts4_word ts4_if_get_u32_off44_88334890();
ts4_word fn_88335DF8();
ts4_word fn_88336050();
ts4_word ts4_if_call_seq_lbl_88028B5C_88339B50();
ts4_word fn_88376FC0();
ts4_word fn_88377118();
ts4_word fn_88381F90();
ts4_word fn_88396320();
ts4_word fn_88397970();
ts4_word fn_883A3000();
ts4_word fn_883A5320();
ts4_word fn_883A69B0();
ts4_word fn_883ACE00();
ts4_word ts4_set_u32_off34_883ACE40();
ts4_word ts4_fn_883E63B8();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857A1E0();
ts4_word fn_8857ACB8();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();
ts4_word fn_8857BFA8();
ts4_word fn_8857C040();
ts4_word ts4_memset();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8832AFB0: if_get u32@0xd8, ts4_adjust_minus_28_thunk_8832ADF0, u32@0x20, vcall, u32@0x5c, ts4_if_call_seq_lbl_88028EA4_8831ACF0 */
ts4_word ts4_if_get_u32_offd8_8832AFB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)ts4_adjust_minus_28_thunk_8832ADF0;
        ((ts4_word (*)(ts4_word))(t1))((ts4_word)(a0 + 28));
    }
    ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)0);
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88029204, (ts4_word)101);
    return 0;
}

