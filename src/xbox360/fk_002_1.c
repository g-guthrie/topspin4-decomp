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
extern char lbl_880C1320[];
extern char lbl_880D35C0[];
extern char lbl_880DD088[];
extern char lbl_880E3A40[];
extern char lbl_880E3EF0[];
extern char lbl_880E3F00[];
extern char lbl_880E3F10[];
extern char lbl_880E4528[];
extern char lbl_880E46C8[];
extern char lbl_880E4760[];
extern char lbl_880E7494[];
extern char lbl_880E75A8[];
extern char lbl_880E7620[];
extern char lbl_880E7750[];
extern char lbl_880E7810[];
extern char lbl_880E78A8[];
extern char lbl_880E7990[];
extern char lbl_880E7AF4[];
extern char lbl_880E7B80[];
extern char lbl_880E7C30[];
extern char lbl_880E8230[];
extern char lbl_880E83EC[];
extern char lbl_880E8424[];
extern char lbl_880E8588[];
extern char lbl_880E86D8[];
extern char lbl_880E8738[];
extern char lbl_880E8798[];
extern char lbl_880E87F8[];
extern char lbl_880E8858[];
extern char lbl_880E8C58[];
extern char lbl_880E9154[];
extern char lbl_880E9158[];
extern char lbl_880E9168[];
extern char lbl_880E9378[];
extern char lbl_8814B440[];
extern char lbl_88C697D0[];
extern char lbl_88C697EC[];
extern char lbl_88C69804[];
extern char lbl_88C69820[];
extern char lbl_88C6983C[];
extern char lbl_88C69854[];
extern char lbl_88C69870[];
extern char lbl_88C69888[];
extern char lbl_88C698A4[];
extern char lbl_88C698BC[];
extern char lbl_88C698D8[];
extern char lbl_88C698F0[];
extern char lbl_88C6990C[];
extern char lbl_88C69924[];
extern char lbl_88C69940[];
extern char lbl_88C69958[];
extern char lbl_88C69974[];
extern char lbl_88C6998C[];
extern char lbl_88C699A8[];
extern char lbl_88C699C0[];
extern char lbl_88C699DC[];
extern char lbl_88C699F4[];
extern char lbl_88C69A10[];
extern char lbl_88C69A28[];
extern char lbl_88C69A44[];
extern char lbl_88C69A78[];
extern char lbl_88C69A94[];
extern char lbl_88C69AE4[];
extern char lbl_88C69B00[];
extern char lbl_88C69B18[];
extern char lbl_88C69B34[];
extern char lbl_88C69B4C[];
extern char lbl_88C69BB0[];
extern char lbl_88C69BCC[];
extern char lbl_88C69BE4[];
extern char lbl_88C69C00[];
extern char lbl_88C69C18[];
extern char lbl_88C69C34[];
extern char lbl_88C69C4C[];
extern char lbl_88C69C68[];
extern char lbl_88C69C80[];
extern char lbl_88C69C9C[];
extern char lbl_88C69CC4[];
extern char lbl_88C69CE0[];
extern char lbl_88C69CF8[];
extern char lbl_88C69D14[];
extern char lbl_88C69D2C[];
extern char lbl_88C69D48[];
extern char lbl_88C69D98[];
extern char lbl_88C69DB4[];
extern char lbl_88C69DE8[];
extern char lbl_88C69E04[];
extern char lbl_88C69E20[];
extern char lbl_88C69E3C[];
extern char lbl_88D41F80[];
extern char lbl_88D41F9C[];
extern char lbl_88D41FC4[];
extern char lbl_88D45B38[];
ts4_word fn_881519D0();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8818EB10();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_8819ACC8();
ts4_word ts4_if_call_seq_u32_off0_8819B0C8();
ts4_word ts4_loop_call_seq_u8_off0_8819B1A8();
ts4_word fn_8819B2A0();
ts4_word fn_8819B308();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881C23E8();
ts4_word fn_881C2590();
ts4_word fn_881C5F68();
ts4_word fn_881C6998();
ts4_word fn_881C7078();
ts4_word fn_881C86B0();
ts4_word fn_881C8D98();
ts4_word fn_881C8E18();
ts4_word fn_881CCD90();
ts4_word ts4_call_seq_u32_offc_881CCDF0();
ts4_word fn_881CDFE0();
ts4_word fn_881CEB10();
ts4_word fn_881D4050();
ts4_word fn_881D4788();
ts4_word fn_881D6CA0();
ts4_word fn_881DA460();
ts4_word ts4_call_seq_fn_8819B0C8_881DB800();
ts4_word fn_881DBA10();
ts4_word fn_881DD5E0();
ts4_word fn_881DDE58();
ts4_word fn_881E88D0();
ts4_word fn_881E92C0();
ts4_word fn_881EC4A0();
ts4_word ts4_if_call_seq_u32_off0_881F0598();
ts4_word fn_881F07F8();
ts4_word fn_881F1060();
ts4_word ts4_if_get_u32_off24_881F1598();
ts4_word fn_881F26C0();
ts4_word fn_881F4108();
ts4_word ts4_call_seq_lbl_880E9660_881F41E8();
ts4_word fn_881F4D38();
ts4_word fn_881F8B58();
ts4_word fn_881FBA58();
ts4_word fn_88202CD8();
ts4_word ts4_addr_fn_881F7958_88206B20();
ts4_word fn_8820AC88();
ts4_word fn_8820FD80();
ts4_word fn_8820FE68();
ts4_word fn_885630C0();
ts4_word ts4_tailcall_fn_885655E8_88565748();
ts4_word fn_88566FE8();
ts4_word fn_88569190();
ts4_word fn_88613268();
ts4_word fn_887D2B40();
ts4_word fn_887E1020();
ts4_word fn_887EE4B0();
ts4_word fn_887F4BA0();
ts4_word ts4_call_seq_fn_887F4BA0_887F5400();
ts4_word fn_887F9418();
ts4_word fn_887FC8F0();
ts4_word ts4_singleton_service_ctor_888006F0();
ts4_word fn_88800758();
ts4_word fn_88800BF8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x881CE548: call_seq ts4_if_call_seq_u32_off0_8819B0C8, fn_881C86B0, u32@0x10, u32@0x10, u32@0x14, u32@0x14 */
ts4_word ts4_call_seq_fn_8819B0C8_881CE548(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    t2 = fn_881C86B0((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    return t2;
}

/* Swing_DLL.xex 0x881D58B8: addr ts4_addr_fn_881F7958_88206B20, lbl_880E83EC, u32@0x20, u32@0x0, u8@0x24, u32@0x28 */
ts4_word ts4_addr_fn_88206B20_881D58B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_addr_fn_881F7958_88206B20((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E83EC;
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(t5 + 16);
    return a0;
}

/* Swing_DLL.xex 0x881DB8F8: call_seq ts4_call_seq_fn_8819B0C8_881DB800 */
ts4_word ts4_call_seq_fn_881DB800_881DB8F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_call_seq_fn_8819B0C8_881DB800((ts4_word)a0, (ts4_word)a1);
    *(float *)((char *)(ts4_word)(a0) + 144) = (*(float *)((char *)(ts4_word)(a1) + 144));
    return t1;
}

