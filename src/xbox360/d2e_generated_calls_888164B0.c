/* Swing_DLL.xex 0x888164B0-0x88887060, executable version 0.0.0.3. */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#endif
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

extern char lbl_880C9D1B[];
extern char lbl_880D6B70[];
extern char lbl_88C6BE68[];
extern char lbl_88D459B8[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word fn_88581AF0();
ts4_word fn_88581B70();
ts4_word fn_88613350();
ts4_word fn_88614938();
ts4_word fn_8861AB88();
ts4_word fn_88814BB8();
ts4_word ts4_if_call_seq_u32_off10_88815520();
ts4_word fn_888216D0();
ts4_word fn_88821878();
ts4_word fn_88837880();
ts4_word ts4_call_seq_lbl_880DF600_8887E558();
ts4_word fn_88884FD0();
ts4_word ts4_tailcall_XamContentClose_8857B2D8();
ts4_word ts4_tailcall_XamContentDelete_8857B2D0();
ts4_word ts4_tailcall_fn_88582660_8857B840();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word ts4_tailcall_fn_88582F30_8857A128();



/* Swing_DLL.xex 0x8887EA78: call_seq lbl_880C9D1B, ts4_call_seq_lbl_880DF600_8887E558, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_lbl_880C9D1B_8887EA78(ts4_word a0)
{
    ts4_word t2;

    ts4_call_seq_lbl_880DF600_8887E558((ts4_word)(ts4_word)lbl_880C9D1B);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}











