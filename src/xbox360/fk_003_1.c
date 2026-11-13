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

extern char lbl_880D61F4[];
extern char lbl_880DD088[];
extern char lbl_880E4BA0[];
extern char lbl_880E94A4[];
extern char lbl_880E96D8[];
extern char lbl_880E9AC0[];
extern char lbl_880E9BF0[];
extern char lbl_880E9C68[];
extern char lbl_880E9DF8[];
extern char lbl_880E9F50[];
extern char lbl_880EA174[];
extern char lbl_880EA1C8[];
extern char lbl_880EA318[];
extern char lbl_880EA5E4[];
extern char lbl_880EF46C[];
extern char lbl_880EF4A0[];
extern char lbl_880EF4BC[];
extern char lbl_880EF4D8[];
extern char lbl_880EF6C4[];
extern char lbl_880EF750[];
extern char lbl_880EF7B8[];
extern char lbl_880EF7EC[];
extern char lbl_880EFE30[];
extern char lbl_880EFE8C[];
extern char lbl_880F20FC[];
extern char lbl_880F2138[];
extern char lbl_880F22A8[];
extern char lbl_880F2480[];
extern char lbl_880F2508[];
extern char lbl_880F28EC[];
extern char lbl_880F30CC[];
extern char lbl_880F31D8[];
extern char lbl_880F3350[];
extern char lbl_880F3430[];
extern char lbl_88C69458[];
extern char lbl_88C69474[];
extern char lbl_88C6948C[];
extern char lbl_88C694A8[];
extern char lbl_88C694C0[];
extern char lbl_88C694DC[];
extern char lbl_88C694F4[];
extern char lbl_88C69510[];
extern char lbl_88C69528[];
extern char lbl_88C69544[];
extern char lbl_88C6955C[];
extern char lbl_88C69578[];
extern char lbl_88C69594[];
extern char lbl_88C695AC[];
extern char lbl_88C695C8[];
extern char lbl_88C695E0[];
extern char lbl_88C695FC[];
extern char lbl_88C69614[];
extern char lbl_88C69630[];
extern char lbl_88C69648[];
extern char lbl_88C69664[];
extern char lbl_88C6967C[];
extern char lbl_88C69698[];
extern char lbl_88C696B0[];
extern char lbl_88C696CC[];
extern char lbl_88C696E4[];
extern char lbl_88C69700[];
extern char lbl_88C69718[];
extern char lbl_88C69734[];
extern char lbl_88C6974C[];
extern char lbl_88C69768[];
extern char lbl_88C69780[];
extern char lbl_88C6979C[];
extern char lbl_88C697B4[];
extern char lbl_88D41FC0[];
extern char lbl_88D41FC4[];
extern char lbl_88D45A60[];
extern char lbl_88D45A6C[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_881519D0();
ts4_word fn_8816D1A8();
ts4_word fn_881876D0();
ts4_word fn_8818EB10();
ts4_word fn_8818F1D8();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_8819ACC8();
ts4_word fn_8819B0C8();
ts4_word fn_8819C190();
ts4_word fn_881BD170();
ts4_word fn_881C38D0();
ts4_word fn_881C5BD8();
ts4_word fn_881C86B0();
ts4_word fn_881C88B0();
ts4_word fn_881CCD90();
ts4_word fn_881CCDF0();
ts4_word fn_881CCEE0();
ts4_word fn_881CE5B8();
ts4_word fn_881E1D70();
ts4_word fn_881E9010();
ts4_word fn_881F08F0();
ts4_word fn_881F2498();
ts4_word fn_881F4108();
ts4_word fn_881F41E8();
ts4_word fn_881F5DE0();
ts4_word fn_881F7958();
ts4_word fn_881FC068();
ts4_word fn_881FD7D8();
ts4_word fn_88201580();
ts4_word ts4_get_fn_881519D0_88201698();
ts4_word fn_882016F8();
ts4_word fn_88204E00();
ts4_word fn_882072F0();
ts4_word fn_8820AC88();
ts4_word fn_8820AF78();
ts4_word fn_8820B138();
ts4_word fn_8820B418();
ts4_word fn_8820CFB8();
ts4_word fn_8820D100();
ts4_word fn_8820E000();
ts4_word fn_8820EF88();
ts4_word fn_8820F160();
ts4_word fn_8820F448();
ts4_word fn_8820F740();
ts4_word fn_8820FD80();
ts4_word fn_88212420();
ts4_word ts4_call_seq_u32_off0_882125E0();
ts4_word ts4_call_seq_u32_off0_882126B8();
ts4_word fn_88222338();
ts4_word fn_88223540();
ts4_word fn_88223B10();
ts4_word fn_88225790();
ts4_word fn_8822B6E0();
ts4_word fn_88255AA0();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_886E81D8();
ts4_word fn_887104B8();
ts4_word fn_8871FFB0();
ts4_word fn_88720018();
ts4_word ts4_call_seq_fn_88255AA0_88721960();
ts4_word fn_88721CB0();
ts4_word fn_887261D0();
ts4_word fn_88736DE8();
ts4_word fn_88745F58();
ts4_word fn_88746018();
ts4_word fn_887727B8();
ts4_word fn_88773078();
ts4_word fn_88773218();
ts4_word fn_8877DC48();
ts4_word fn_887816A0();
ts4_word fn_88781FC8();
ts4_word fn_88782060();
ts4_word fn_887823A8();
ts4_word fn_887827A8();
ts4_word fn_887855B8();
ts4_word fn_88785A00();
ts4_word fn_8878BE98();
ts4_word fn_8879C218();
ts4_word fn_887A15A8();
ts4_word fn_887B53E8();
ts4_word ts4_call_seq_fn_881F1060_887B5CF8();
ts4_word fn_887B5E20();
ts4_word fn_887B6808();
ts4_word fn_887C4558();
ts4_word fn_887C8050();
ts4_word fn_887CB7B0();
ts4_word fn_887CBE90();
ts4_word fn_887CC248();
ts4_word fn_887EC668();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x882046B0: if_call_seq u32@0x14, fn_8818F1D8, ts4_get_fn_881519D0_88201698, u32@0x0, u32@0x4, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off14_882046B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = fn_8818F1D8((ts4_word)a0);
    if ((ts4_word)t2 != 0) {
        ts4_get_fn_881519D0_88201698((ts4_word)(t2 + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) + 1);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
        return t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x88206B20: addr fn_881F7958, lbl_880E9C68, u32@0x0, fn_881519D0, u32@0x0, u32@0x10 */
ts4_word ts4_addr_fn_881F7958_88206B20(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_881F7958((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9C68;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t5 + 16);
    return a0;
}

/* Swing_DLL.xex 0x88212FD0: call_seq u32@0x0, u32@0x0, fn_88212420, u8@0x58, u8@0x58, u8@0x59 */
ts4_word ts4_call_seq_u32_off0_88212FD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    fn_88212420((ts4_word)(a0 + 4));
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 88));
    *(unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 89));
    ts4_call_seq_u32_off0_882125E0((ts4_word)(a0 + 4), (ts4_word)(a1 + 4));
    return a0;
}

/* Swing_DLL.xex 0x88218648: call_seq u32@0x0, u32@0x0, ts4_call_seq_u32_off0_882126B8, u8@0x58, u8@0x58, u8@0x59 */
ts4_word ts4_call_seq_u32_off0_88218648(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    ts4_call_seq_u32_off0_882126B8((ts4_word)(a0 + 4), (ts4_word)(a1 + 4));
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 88));
    *(unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 89));
    return a0;
}

