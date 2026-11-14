/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef struct ts4_args2 { ts4_word w[2]; } ts4_args2;
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;
typedef struct ts4_q6 { ts4_u64 q[6]; } ts4_q6;
typedef struct ts4_q8 { ts4_u64 q[8]; } ts4_q8;
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
#include "ts4_vector.h"

extern char lbl_88042C70[];
extern char lbl_880C1320[];
extern char lbl_880D082C[];
extern char lbl_880D5930[];
extern char lbl_880D5938[];
extern char lbl_880D594C[];
extern char lbl_880D5964[];
extern char lbl_880D5988[];
extern char lbl_880D59A4[];
extern char lbl_880D59BC[];
extern char lbl_880D59D4[];
extern char lbl_880D60F8[];
extern char lbl_880D6108[];
extern char lbl_880D611C[];
extern char lbl_880D612C[];
extern char lbl_880D6144[];
extern char lbl_880D6164[];
extern char lbl_880D6188[];
extern char lbl_880D61A8[];
extern char lbl_880D61D0[];
extern char lbl_880D6ECC[];
extern char lbl_880D6EDC[];
extern char lbl_880D6EF0[];
extern char lbl_880D6F0C[];
extern char lbl_880D6F24[];
extern char lbl_880D6F3C[];
extern char lbl_880D6F54[];
extern char lbl_880D6F6C[];
extern char lbl_880D6F84[];
extern char lbl_880D6F9C[];
extern char lbl_880D6FB4[];
extern char lbl_880D6FCC[];
extern char lbl_880D6FE4[];
extern char lbl_880D6FFC[];
extern char lbl_880D7018[];
extern char lbl_880D82D0[];
extern char lbl_880D8300[];
extern char lbl_880D85CC[];
extern char lbl_880D9E24[];
extern char lbl_880DBEC0[];
extern char lbl_880DBED4[];
extern char lbl_880DBEDC[];
extern char lbl_880DBEFC[];
extern char lbl_880DBF20[];
extern char lbl_880DBF4C[];
extern char lbl_880DBF78[];
extern char lbl_880DBFA0[];
extern char lbl_880DBFAC[];
extern char lbl_880DBFB4[];
extern char lbl_880DBFC4[];
extern char lbl_880DF0F0[];
extern char lbl_880DF104[];
extern char lbl_880DF114[];
extern char lbl_880DF128[];
extern char lbl_880DF138[];
extern char lbl_880DF150[];
extern char lbl_880DF168[];
extern char lbl_880DF17C[];
extern char lbl_880DF190[];
extern char lbl_880DF1A0[];
extern char lbl_880DF1B0[];
extern char lbl_880DF1C4[];
extern char lbl_880DF1D8[];
extern char lbl_880DF64C[];
extern char lbl_880E04C4[];
extern char lbl_880E13DC[];
extern char lbl_880E17D8[];
extern char lbl_880E3588[];
extern char lbl_880E3598[];
extern char lbl_880E35AC[];
extern char lbl_880E35C8[];
extern char lbl_880E35E4[];
extern char lbl_880E3604[];
extern char lbl_880E3614[];
extern char lbl_880E3620[];
extern char lbl_880E44CC[];
extern char lbl_880E4D50[];
extern char lbl_880E4D64[];
extern char lbl_880E4D7C[];
extern char lbl_880E4D94[];
extern char lbl_880E4DAC[];
extern char lbl_880E4DC0[];
extern char lbl_880E4DD8[];
extern char lbl_880E4DEC[];
extern char lbl_880E4E04[];
extern char lbl_880E4E18[];
extern char lbl_880E4E2C[];
extern char lbl_880E4E40[];
extern char lbl_880EA35C[];
extern char lbl_880ED610[];
extern char lbl_880EE068[];
extern char lbl_880EE4A4[];
extern char lbl_880EE4B0[];
extern char lbl_880EE4C8[];
extern char lbl_880EE4E0[];
extern char lbl_880EE4FC[];
extern char lbl_880EE514[];
extern char lbl_880EE528[];
extern char lbl_880EE53C[];
extern char lbl_880EE550[];
extern char lbl_880EE564[];
extern char lbl_880EE570[];
extern char lbl_880EEC38[];
extern char lbl_880EEC78[];
extern char lbl_880F436C[];
extern char lbl_880F44B4[];
extern char lbl_880F500C[];
extern char lbl_880F50FC[];
extern char lbl_880F5A24[];
extern char lbl_880F5F70[];
extern char lbl_880F8C44[];
extern char lbl_8814B440[];
extern char lbl_8814B910[];
extern char lbl_88C6A10C[];
extern char lbl_88C6AEF0[];
extern char lbl_88C6B810[];
extern char lbl_88C6B838[];
extern char lbl_88C6B8F4[];
extern char lbl_88C6B90C[];
extern char lbl_88CAD340[];
extern char lbl_88D26FCC[];
extern char lbl_88D3EB60[];
extern char lbl_88D41F80[];
extern char lbl_88D41FDC[];
extern char lbl_88D42940[];
extern char lbl_88D44040[];
extern char lbl_88D45894[];
extern char lbl_88D45930[];
extern char lbl_88D459E0[];
extern char lbl_88D459E8[];
extern char lbl_88D459EC[];
extern char lbl_88D459F4[];
extern char lbl_88D45A08[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A60[];
extern char lbl_88D45A70[];
extern char lbl_88D45A74[];
extern char lbl_88D45AA7[];
extern char lbl_88D45AD0[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B0C[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B2C[];
extern char lbl_88D45B30[];
extern char lbl_88D45B38[];
extern char ts4_if_call_seq_u32_off90_888A8198[];
ts4_word RtlInitializeCriticalSection();
ts4_word fn_88150600();
ts4_word fn_881643D0();
ts4_word fn_88169350();
ts4_word fn_8816CAA0();
ts4_word fn_881705B0();
ts4_word ts4_loop_call_seq_u32_off4_88174B90();
ts4_word ts4_loop_call_seq_u32_off4_88174C40();
ts4_word fn_881784B0();
ts4_word fn_8817EA90();
ts4_word ts4_if_call_seq_fn_8892EE88_8817F5E0();
ts4_word fn_881800D8();
ts4_word fn_88181240();
ts4_word fn_881898E8();
ts4_word fn_88189E18();
ts4_word ts4_if_get_RtlEnterCriticalSection_8818A4C8();
ts4_word fn_88198CE0();
ts4_word fn_881992A8();
ts4_word fn_881ABB20();
ts4_word fn_881AC7D0();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B1CF0();
ts4_word fn_881BBC00();
ts4_word fn_881F04B8();
ts4_word fn_882159B0();
ts4_word fn_88221570();
ts4_word fn_88280708();
ts4_word fn_8841CBF8();
ts4_word fn_88420F08();
ts4_word ts4_call_seq_lbl_88041928_88436500();
ts4_word ts4_if_get_u32_off0_884C6B58();
ts4_word fn_885635D0(ts4_word, ts4_word, ...);
ts4_word fn_88566048();
ts4_word ts4_xam_signin_info_8857A990();
ts4_word fn_8857B848();
ts4_word fn_8857C8C8();
ts4_word fn_88608590();
ts4_word fn_8860A938();
ts4_word fn_8860A9E0();
ts4_word fn_8860AB08();
ts4_word fn_8860D360();
ts4_word fn_8860DBC8();
ts4_word fn_8860F748();
ts4_word fn_88612D60();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88615280();
ts4_word fn_88617D88();
ts4_word ts4_if_addr_ts4_call_88613268_88618368_8861D760();
ts4_word fn_88627EC0();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_8862CC90();
ts4_word ts4_if_get_u32_off1c_88656900();
ts4_word fn_8865A5E0();
ts4_word fn_8865E638();
ts4_word fn_88661188();
ts4_word fn_88661A70();
ts4_word fn_8866CDC8();
float fn_886887C0(ts4_word, float);
ts4_word fn_886917F8();
ts4_word fn_8869C010();
ts4_word fn_886A7610();
ts4_word fn_886C0050();
ts4_word fn_886EC0E0();
ts4_word fn_88713970();
ts4_word fn_88718C90();
ts4_word fn_88728C48();
ts4_word ts4_if_addr_ts4_handle_forward_88150770_88731540();
ts4_word fn_88736FB8();
ts4_word fn_88748350();
ts4_word fn_88748B18();
ts4_word fn_8877DF00();
ts4_word fn_8878FA48();
ts4_word fn_8879FF30();
ts4_word fn_887A2CD0();
ts4_word fn_887F8218();
ts4_word fn_88803198();
ts4_word fn_88805368();
ts4_word fn_888063B0();
ts4_word fn_88806428();
ts4_word lib3_lua_type_88822738();
ts4_word lib3_lua_tostring_88822888();
ts4_word fn_88837B00();
ts4_word fn_88866030();
ts4_word fn_88867E68();
ts4_word fn_88883CD0();
ts4_word ts4_if_get_u32_lbl_88D45B1C_88885C18();
ts4_word fn_888866E8();
ts4_word fn_888870F0();
ts4_word fn_888877F8();
ts4_word fn_888A4630();
ts4_word fn_888A4B00();
ts4_word fn_888A73D8();
ts4_word fn_888AA6C0();
ts4_word fn_888B12E8();
ts4_word fn_888B7F08();
ts4_word ts4_if_get_u32_off8_888C2CC8();
ts4_word ts4_if_get_u32_off8_888C2D40();
ts4_word fn_888C7AF8();
ts4_word fn_888CBDA8();
ts4_word fn_888CEAA8();
ts4_word fn_888D82E0();
ts4_word fn_888D8368();
ts4_word fn_888DD560();
ts4_word fn_888F19A8();
ts4_word fn_88909988();
ts4_word fn_8890E8B0();
ts4_word fn_8890F1E8();
ts4_word fn_88911A00();
ts4_word fn_88923380();
ts4_word fn_88923458();
ts4_word fn_88923530();
ts4_word fn_889254C8();
ts4_word fn_88925640();
ts4_word fn_88929E70();
ts4_word fn_88936BB0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_88941B30();
ts4_word fn_88987938();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_fn_884025C0_88402FB0();
ts4_word ts4_call_seq_fn_884027D8_88402FD8();
ts4_word ts4_call_seq_fn_88617D88_8892AFF0();
ts4_word ts4_call_seq_u32_off0_88627AD0();
ts4_word ts4_call_seq_u32_off14_88835FC8();
ts4_word ts4_call_seq_u32_off18_88837CB0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_record_by_key_881AC778();
ts4_word ts4_find_record_by_key_881ACBA8();
ts4_word ts4_find_record_by_key_881AD158();
ts4_word ts4_find_service();
ts4_word ts4_find_typed_entry_887819C0();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word ts4_get_u32_lbl_88CAD338_8841B618();
ts4_word ts4_get_u32_off0_8816CD98();
ts4_word ts4_get_u32_off0_8822AFE8();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8();
ts4_word ts4_if_call_seq_fn_88582680_884F1D68();
ts4_word ts4_if_call_seq_fn_887DACE0_887DB6B0();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();
ts4_word ts4_if_call_seq_ts4_find_service_888C32E8();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_888DAEE8();
ts4_word ts4_if_call_seq_u32_off0_886ED438();
ts4_word ts4_if_call_seq_u32_off10_8861C5C8();
ts4_word ts4_if_call_seq_u32_off3c34_88779858();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_call_seq_u32_off8_88837608();
ts4_word ts4_if_call_seq_u32_off90_888A70B0();
ts4_word ts4_if_get_fn_8883F238_88844310();
ts4_word ts4_if_get_fn_8883F238_88848698();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_if_get_u32_off0_8892FE20();
ts4_word ts4_if_get_u32_off8_8841D058();
ts4_word ts4_keyed_item_list_add_unique_88621EA0();
ts4_word ts4_keyed_item_list_add_unique_88622B10();
ts4_word ts4_keyed_item_list_add_unique_88623400();
ts4_word ts4_keyed_item_list_add_unique_88623CE0();
ts4_word ts4_keyed_item_list_add_unique_88623E40();
ts4_word ts4_keyed_item_list_add_unique_88639BD8();
ts4_word ts4_keyed_item_list_add_unique_88780FE0();
ts4_word ts4_keyed_item_list_add_unique_88781090();
ts4_word ts4_keyed_item_list_add_unique_88781140();
ts4_word ts4_keyed_item_list_add_unique_887811F0();
ts4_word ts4_keyed_item_list_add_unique_887812A0();
ts4_word ts4_keyed_item_list_add_unique_887813A0();
ts4_word ts4_keyed_item_list_add_unique_88781450();
ts4_word ts4_keyed_item_list_add_unique_88781500();
ts4_word ts4_keyed_item_list_add_unique_887815F0();
ts4_word ts4_keyed_item_list_add_unique_887816F0();
ts4_word ts4_keyed_item_list_add_unique_88781B68();
ts4_word ts4_keyed_item_list_add_unique_887D5B20();
ts4_word ts4_keyed_item_list_add_unique_887D5EF8();
ts4_word ts4_keyed_item_list_add_unique_887D5FA8();
ts4_word ts4_keyed_item_list_add_unique_887D6058();
ts4_word ts4_keyed_item_list_add_unique_887D6108();
ts4_word ts4_keyed_item_list_add_unique_887D61B8();
ts4_word ts4_keyed_item_list_add_unique_887D6268();
ts4_word ts4_keyed_item_list_add_unique_887D6318();
ts4_word ts4_keyed_item_list_add_unique_887D63C8();
ts4_word ts4_keyed_item_list_add_unique_887D6478();
ts4_word ts4_keyed_item_list_add_unique_887D7260();
ts4_word ts4_keyed_item_list_add_unique_887D7310();
ts4_word ts4_keyed_item_list_add_unique_88803438();
ts4_word ts4_keyed_item_list_add_unique_888034E8();
ts4_word ts4_keyed_item_list_add_unique_88803610();
ts4_word ts4_keyed_item_list_add_unique_888036C0();
ts4_word ts4_keyed_item_list_add_unique_88803770();
ts4_word ts4_keyed_item_list_add_unique_88803820();
ts4_word ts4_keyed_item_list_add_unique_888038D0();
ts4_word ts4_keyed_item_list_add_unique_8883E498();
ts4_word ts4_keyed_item_list_add_unique_88878FA0();
ts4_word ts4_keyed_item_list_add_unique_88887B30();
ts4_word ts4_keyed_item_list_add_unique_88887D50();
ts4_word ts4_keyed_item_list_add_unique_88887EB0();
ts4_word ts4_keyed_item_list_add_unique_88888000();
ts4_word ts4_keyed_item_list_add_unique_888880B0();
ts4_word ts4_keyed_item_list_add_unique_888B1DC8();
ts4_word ts4_keyed_item_list_add_unique_888B1E78();
ts4_word ts4_keyed_item_list_add_unique_888B42F8();
ts4_word ts4_keyed_item_list_add_unique_888B4810();
ts4_word ts4_keyed_item_list_add_unique_888B4FC8();
ts4_word ts4_keyed_item_list_add_unique_888B5080();
ts4_word ts4_keyed_item_list_add_unique_888B7250();
ts4_word ts4_keyed_item_list_add_unique_888B73D8();
ts4_word ts4_keyed_item_list_add_unique_888B79B0();
ts4_word ts4_keyed_item_list_add_unique_888B8138();
ts4_word ts4_keyed_item_list_add_unique_888B81F0();
ts4_word ts4_keyed_item_list_add_unique_88912FE8();
ts4_word ts4_keyed_item_list_add_unique_88913098();
ts4_word ts4_keyed_item_list_add_unique_88913148();
ts4_word ts4_keyed_item_list_add_unique_889131F8();
ts4_word ts4_keyed_item_list_add_unique_889132A8();
ts4_word ts4_keyed_item_list_add_unique_88913368();
ts4_word ts4_keyed_item_list_add_unique_88913428();
ts4_word ts4_keyed_item_list_add_unique_889134D8();
ts4_word ts4_keyed_item_list_add_unique_88913588();
ts4_word ts4_keyed_item_list_add_unique_88913638();
ts4_word ts4_keyed_item_list_add_unique_889137B0();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88928A10();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88929120();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88929470();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88929550();
ts4_word ts4_keyed_item_list_add_unique_if_mode_88929758();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
ts4_word ts4_loop_call_seq_u32_off3c34_88778C48();
ts4_word ts4_loop_get_u32_off8_8861DDB0();
ts4_word ts4_lua_pushnumber_888240B8(ts4_word, double);
float ts4_lua_tonumber_88822420();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_ref_holder_dtor_8841D638();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word ts4_resume_thread();
ts4_word ts4_tailcall_NetDll__WSAFDIsSet_884F0398();
ts4_word ts4_tailcall_NetDll_select_884F02F8();
ts4_word ts4_tailcall_fn_88565410_885654D8();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_xml_parser_free_888A7110();
ts4_word ts4_xml_set_implicit_context_888A5370();

/* Swing_DLL.xex 0x8819A338: if_get u32@0x720, u32@0x4, vcall, u32@0x1c, fn_88198CE0, u32@0x8 */
ts4_word ts4_if_get_u32_off720_8819A338(ts4_word a0, ts4_word a1)
{
    ts4_word t5;
    int t6;
    ts4_word t13;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1824))) + 4))))((ts4_word)(a0 + 1824));
    t5 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t6 < 512) {
        ts4_if_get_RtlEnterCriticalSection_8818A4C8((ts4_word)((((int)((int)t6 / 16) * 56) + a0) + 32), (ts4_word)a1);
    } else {
        fn_881992A8((ts4_word)0, (ts4_word)a1);
    }
    fn_88198CE0((ts4_word)t5);
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 1824)) + 0))) + 8))))((ts4_word)(a0 + 1824));
    return t13;
}

/* Swing_DLL.xex 0x8819A790: if_get u32@0x3a0, u32@0x4, vcall, u32@0x1c, fn_88198CE0, u32@0x8 */
ts4_word ts4_if_get_u32_off3a0_8819A790(ts4_word a0, ts4_word a1)
{
    ts4_word t5;
    int t6;
    ts4_word t13;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 928))) + 4))))((ts4_word)(a0 + 928));
    t5 = fn_88198CE0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((int)t6 < 256) {
        ts4_if_get_RtlEnterCriticalSection_8818A4C8((ts4_word)((((int)((int)t6 / 16) * 56) + a0) + 32), (ts4_word)a1);
    } else {
        fn_881992A8((ts4_word)0, (ts4_word)a1);
    }
    fn_88198CE0((ts4_word)t5);
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 928)) + 0))) + 8))))((ts4_word)(a0 + 928));
    return t13;
}

/* Swing_DLL.xex 0x884365A0: call_seq lbl_88042C70, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off4_88426130, ts4_get_u32_off0_88428980 */
ts4_word ts4_call_seq_lbl_88042C70_884365A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc68[3];
    ts4_word loc60[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042C70);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042C70);
    t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ts4_get_u32_off4_88426130((ts4_word)t3);
    loc68[1] = (ts4_word)t4;
    t5 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0]);
    loc68[0] = (ts4_word)t5;
    t6 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0]);
    t7 = ts4_get_u32_off4_88426130((ts4_word)t6);
    loc60[1] = (ts4_word)t7;
    t8 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc58[0]);
    loc60[0] = (ts4_word)t8;
    t9 = ts4_call_seq_lbl_88041928_88436500((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc60[0]);
    return t9;
}

/* Swing_DLL.xex 0x8860A5F0: get u32@0x4, u32@0x0, u32@0x4, u32@0x4, u32@0x2c, u32@0x4 */
ts4_word ts4_get_u32_off4_8860A5F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_u64 t5;

    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 88);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t5 = *(ts4_u64 *)((char *)(ts4_word)((t3 << 4)) + (*(ts4_word *)((char *)(ts4_word)(t2) + 44)));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(((ts4_u64)t5 >> 4) & 0xfffff);
    return (((ts4_u64)t5 >> 4) & 0xfffff);
}

/* Swing_DLL.xex 0x8860BD70: loop_call_seq u32@0xc, ts4_resume_thread, u32@0x8, ts4_if_call_seq_NtSetEvent_8857C1F8, u32@0xc, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_loop_call_seq_u32_offc_8860BD70(ts4_word a0)
{
    ts4_word lv14;
    ts4_word p17;
    ts4_word t13;
    ts4_word t16;
    ts4_word t18;

    ts4_resume_thread((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)-1);
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    lv14 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t16 = *(ts4_word *)((char *)(ts4_word)(lv14) + 0);
        if ((ts4_word)t13 == (ts4_word)t16) {
            *(ts4_word *)((char *)(ts4_word)(lv14) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(lv14) + 4) = (ts4_word)0;
            break;
        }
        p17 = (ts4_word)(lv14 + 520);
        lv14 = p17;
    } while ((ts4_word)p17 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    t18 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t13);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return t18;
}

/* Swing_DLL.xex 0x8860D5B8: if_call_seq fn_88883CD0, u32@0x4, u32@0xc */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D5B8(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t2 != 0) {
            return t2;
        }
    }
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 12));
}

/* Swing_DLL.xex 0x88610158: get u32@0x0, u32@0xb4, vcall, u32@0x4, u32@0x4, fn_8860F748 */
ts4_word ts4_get_u32_off0_88610158(ts4_word a0, ts4_word a1, ts4_args3 sp2)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    t1 = sp2.w[0];
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 180))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t6 = sp2.w[1];
    t8 = fn_8860F748((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t5, (ts4_word)t6, (ts4_word)t4);
    return t8;
}

/* Swing_DLL.xex 0x886131F0: if_call_seq fn_881F04B8, fn_8860DBC8, fn_8860D360, u32@0x24, fn_8860DBC8 */
void ts4_if_call_seq_fn_881F04B8_886131F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;

    if ((ts4_word)a1 != 0) {
        if ((ts4_word)a2 != 0) {
            t1 = fn_881F04B8((ts4_word)a2, (ts4_word)a1);
            if ((ts4_word)(t1 & 0xff) != 0) {
                fn_8860DBC8((ts4_word)a2, (ts4_word)a1);
                return;
            }
        }
        t4 = fn_8860D360((ts4_word)a0, (ts4_word)a1);
        p6 = (ts4_word)t4;
        if ((ts4_word)t4 == 0) {
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
        }
        fn_8860DBC8((ts4_word)p6, (ts4_word)a1);
    }
    return;
}

/* Swing_DLL.xex 0x88614E10: if_get u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u8@0x0 */
void ts4_if_get_u32_off4_88614E10(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == (ts4_word)((1158479872) | 189)) {
        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a0));
        return;
    }
    if ((ts4_word)t1 == (ts4_word)((4172939264) | 27439)) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a0));
        return;
    }
    if (((ts4_word)t1 != (ts4_word)((963510272) | 16339) && (ts4_word)t1 != (ts4_word)((597491712) | 17153)) && (ts4_word)t1 != (ts4_word)((3752132608) | 8466)) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a0));
    return;
}

/* Swing_DLL.xex 0x886157F0: get u32@0x0, u32@0x4c, vcall, u32@0x4, u32@0x4, fn_88615280 */
ts4_word ts4_get_u32_off0_886157F0(ts4_word a0, ts4_word a1, ts4_args3 sp2, ts4_word a4)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = sp2.w[0];
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t7 = sp2.w[1];
    t8 = fn_88615280((ts4_word)t5, (ts4_word)t6, (ts4_word)t4, (ts4_word)t7);
    *(ts4_word *)((char *)(ts4_word)(a4) + 4) = (ts4_word)t8;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 88);
    return t8;
}

/* Swing_DLL.xex 0x886186C8: if_call_seq fn_88612D60, u32@0x2c, u32@0x2c */
ts4_word ts4_if_call_seq_fn_88612D60_886186C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t1 = fn_88612D60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) - a2);
        p4 = (ts4_word)t1;
    }
    return p4;
}

/* Swing_DLL.xex 0x8861D868: call_seq u32@0x4, u32@0x6c, u32@0x70, u8@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off4_8861D868(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 112) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    t1 = ts4_if_addr_ts4_call_88613268_88618368_8861D760((ts4_word)a0, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((983040) | 65535);
    return t1;
}

/* Swing_DLL.xex 0x88625DA0: if_call_seq fn_88617D88, lbl_880F8C44, u32@0x20, u32@0x0, u8@0x1c, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88617D88_88625DA0(ts4_word a0)
{
    ts4_word t3;

    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8C44;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t3 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t3;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    return a0;
}

/* Swing_DLL.xex 0x88627B30: if_call_seq u32@0x2c, ts4_call_seq_u32_off0_88627AD0, ts4_if_call_seq_u32_off10_8861C5C8, ts4_object_finalize, ts4_destroy_owned_object */
void ts4_if_call_seq_u32_off2c_88627B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t107;
    ts4_word loc50[12];
    ts4_u64 t2;
    ts4_word t6;

    t107 = (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44));
    t2 = *(ts4_u64 *)((char *)(ts4_word)((a2 << 4)) + t107);
    if ((int)(((ts4_u64)t2 >> 2) & 0x3) == 1) {
        ts4_call_seq_u32_off0_88627AD0((ts4_word)(ts4_word)&loc50[0]);
        loc50[4] = (ts4_word)a0;
        loc50[8] = (ts4_word)a2;
        loc50[6] = (ts4_word)a3;
        loc50[7] = (ts4_word)a4;
        ts4_if_call_seq_u32_off10_8861C5C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 4));
        ts4_object_finalize((ts4_word)(ts4_word)&loc50[0]);
        t6 = loc50[0];
        if ((ts4_word)t6 != 0) {
            ts4_destroy_owned_object((ts4_word)t6);
        }
    }
    return;
}

/* Swing_DLL.xex 0x88628720: get fn_88627EC0, u32@lbl_88D45B38, u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_fn_88627EC0_88628720(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t6;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = *(ts4_word *)lbl_88D45B38;
    t6 = ((ts4_word (*)(ts4_word, ts4_args3))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3, sp1);
    return t6;
}

/* Swing_DLL.xex 0x88628780: if_call_seq fn_88627EC0, fn_88883CD0, u32@0xc, u32@0x4, fn_88883CD0, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88627EC0_88628780(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t4;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
    }
    t4 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 8) = (ts4_word)0;
    }
    return t4;
}

/* Swing_DLL.xex 0x88628F38: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x44, vcall, ts4_assign_formatted_text */
ts4_word ts4_if_get_u32_lbl_88D45B1C_88628F38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p3;
    ts4_word p29;
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word loc50[2];
    ts4_word t6;
    ts4_word t11;
    ts4_word t18;
    ts4_word t20;
    ts4_word t23;
    ts4_word t24;
    ts4_word t25;

    if ((ts4_word)a5 != 0) {
        p3 = (ts4_word)a5;
    } else {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548));
    }
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p3) + 0))) + 68))))((ts4_word)p3, (ts4_word)a2);
    if ((ts4_word)(t6 & 0xff) != 0) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)a2);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p3) + 0))) + 60))))((ts4_word)p3, (ts4_word)(ts4_word)&loc58[0]);
        t11 = loc58[0];
        ts4_destroy_owned_object((ts4_word)t11);
    }
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)a2);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p3) + 0))) + 52))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)p3, (ts4_word)(ts4_word)&loc68[0], (ts4_word)3, (ts4_word)0);
    t18 = loc68[0];
    ts4_destroy_owned_object((ts4_word)t18);
    t20 = loc50[0];
    p29 = (ts4_word)1;
    if ((ts4_word)t20 != 0) {
        t23 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)a1, (ts4_word)t20, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t24 = loc50[0];
        t25 = *(ts4_word *)((char *)(ts4_word)(t24) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t25) + 0))) + 88))))((ts4_word)t25, (ts4_word)(ts4_word)&loc50[0]);
        p29 = (ts4_word)t23;
    }
    return p29;
}

/* Swing_DLL.xex 0x88629E10: if_get u32@0x1c, u32@lbl_88D45B1C, u32@0x220, ts4_assign_formatted_text, u32@0x0, u32@0x48 */
ts4_word ts4_if_get_u32_off1c_88629E10(ts4_word a0)
{
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word loc78[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t15;
    ts4_word t22;
    ts4_word t23;
    ts4_word t25;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 544);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)t1);
    t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 72))))((ts4_word)t3, (ts4_word)(ts4_word)&loc58[0]);
    t8 = loc58[0];
    ts4_destroy_owned_object((ts4_word)t8);
    if ((ts4_word)(t7 & 0xff) != 0) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 60))))((ts4_word)t3, (ts4_word)(ts4_word)&loc68[0]);
        t15 = loc68[0];
        ts4_destroy_owned_object((ts4_word)t15);
    }
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc78[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t22 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 52))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)(ts4_word)&loc78[0], (ts4_word)3, (ts4_word)0);
    t23 = loc78[0];
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t22) + 0));
    t25 = ts4_destroy_owned_object((ts4_word)t23);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 296) = (unsigned char)1;
    return t25;
}

/* Swing_DLL.xex 0x8862F6D8: loop_set fn_8857C8C8, u32@0x10, u32@0x0, ts4_if_call_seq_NtSetEvent_8857C1F8, u32@lbl_88D45B38, u32@0x40 */
ts4_word ts4_loop_set_fn_8857C8C8_8862F6D8(ts4_word a0)
{
    ts4_word p13;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    int t11;
    ts4_word t12;
    int t15;
    ts4_word t20;
    ts4_word t26;
    int t28;
    ts4_word t29;
    ts4_word t35;

    t1 = fn_8857C8C8();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t4 = *(ts4_word *)lbl_88D45B38;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t6 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t6 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 12) = (ts4_word)t5;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)t5;
    }
    if ((ts4_word)t5 != 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(t4) + 32) = (unsigned char)0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t8 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t8 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 16) = (ts4_word)t7;
        *(volatile ts4_word *)((char *)(ts4_word)(t8) + 8) = (ts4_word)t7;
    }
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)-1);
    do {
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        p13 = (ts4_word)1;
        if ((int)t11 != 0) {
            t12 = fn_8862CC90((ts4_word)t11);
            p13 = (ts4_word)t12;
        }
    } while ((ts4_word)(p13 & 0xff) == 0);
    loc50[0] = (ts4_word)((4020830208) | 36533);
    ts4_if_call_seq_ts4_find_service_888C32E8((ts4_word)(ts4_word)&loc50[0]);
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t15 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 20))))((ts4_word)t15);
    }
    t20 = ts4_find_service((ts4_word)((1680605184) | 34887));
    if ((ts4_word)t20 != 0) {
        ts4_get_u32_lbl_88CAD338_8841B618((ts4_word)t20);
    }
    *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 60))) + 0) = (unsigned char)1;
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)-1);
    t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    loc50[0] = (ts4_word)((4020830208) | 36533);
    *(volatile unsigned char *)((char *)(ts4_word)(t26) + 0) = (unsigned char)0;
    ts4_if_call_seq_ts4_find_service_888C32E8((ts4_word)(ts4_word)&loc50[0]);
    t28 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t28 != 0) {
        t29 = *(ts4_word *)((char *)(ts4_word)(t28) + 0);
        ((ts4_word (*)(ts4_word, ts4_args3))((*(ts4_word *)((char *)(ts4_word)(t29) + 16))))((ts4_word)t28, *(ts4_args3 *)((char *)(ts4_word)(a0) + 48));
    }
    t35 = ts4_find_service((ts4_word)((1680605184) | 34887));
    if ((ts4_word)t35 != 0) {
        ts4_get_u32_lbl_88CAD338_8841B618((ts4_word)t35);
    }
    *(volatile unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 60))) + 0) = (unsigned char)1;
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88639E10: copy u8@0x23e, u8@0x23d */
void ts4_copy_u8_off23e_88639E10(ts4_word a0, ts4_word a1)
{
    *(ts4_q8 *)(a0) = *(ts4_q8 *)(a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 574) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 573) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88639F18: get u32@0x4, u8@0x23e, u8@0x23d */
void ts4_get_u32_off4_88639F18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_q8 *)(t1) = *(ts4_q8 *)(a1);
    *(unsigned char *)((char *)(ts4_word)(t1) + 574) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(t1) + 573) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8863B0E0: if_call_seq u32@0x8, u32@0x4, fn_88280708, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_8863B0E0(ts4_word a0, ts4_word a1, ts4_args3 sp2, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t4;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        p1 = (ts4_word)(a0 + 1056);
    } else {
        p1 = (ts4_word)(a0 + 1068);
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(p1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(p1) + 4);
    if ((ts4_word)t3 != (ts4_word)t2) {
        if ((ts4_word)t3 != 0) {
            t5 = sp2.w[0];
            t6 = sp2.w[1];
            t7 = sp2.w[2];
            *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t5;
            *(volatile ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t6;
            *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t7;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(p1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(p1) + 4)) + 12);
        return p1;
    }
    t4 = fn_88280708((ts4_word)p1, (ts4_word)t3, (ts4_word)(ts4_word)&sp2, (ts4_word)1, (ts4_word)1);
    return t4;
}

/* Swing_DLL.xex 0x88645408: call_seq u32@0x24, ts4_call_seq_fn_884025C0_88402FB0, u32@0x0 */
void ts4_call_seq_u32_off24_88645408(ts4_word a0, ts4_word a1, ts4_word a2)
{
    __vector4 vv4;
    ts4_word t2;

    t2 = ts4_call_seq_fn_884025C0_88402FB0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    vv4 = *(__vector4 *)((ts4_word)((((a1 + (a1 << 1)) << 4) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 32));
    *(__vector4 *)((ts4_word)(a2)) = vv4;
    return;
}

/* Swing_DLL.xex 0x88645468: call_seq u32@0x24, ts4_call_seq_fn_884025C0_88402FB0, u32@0x0 */
void ts4_call_seq_u32_off24_88645468(ts4_word a0, ts4_word a1, ts4_word a2)
{
    __vector4 vv4;
    ts4_word t2;

    t2 = ts4_call_seq_fn_884025C0_88402FB0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    vv4 = *(__vector4 *)((ts4_word)(((a1 + (a1 << 1)) << 4) + (*(ts4_word *)((char *)(ts4_word)(t2) + 0))));
    *(__vector4 *)((ts4_word)(a2)) = vv4;
    return;
}

/* Swing_DLL.xex 0x886454F8: set u32@0x0, u32@0x24, u32@0x28 */
void ts4_set_u32_off0_886454F8(ts4_word a0)
{
    __vector4 vv1;
    float t2;

    vv1 = __vspltisw(0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t2 = *(float *)lbl_8814B440;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 32) = t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv1;
    return;
}

/* Swing_DLL.xex 0x88645968: call_seq u32@0x24, ts4_call_seq_fn_884027D8_88402FD8, u32@0x0 */
ts4_word ts4_call_seq_u32_off24_88645968(ts4_word a0, ts4_word a1)
{
    __vector4 vv4;
    ts4_word t2;

    t2 = ts4_call_seq_fn_884027D8_88402FD8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    vv4 = *(__vector4 *)((ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))));
    *(__vector4 *)((ts4_word)(a1)) = vv4;
    return t2;
}

/* Swing_DLL.xex 0x886459A8: call_seq u32@0x24, ts4_call_seq_fn_884027D8_88402FD8, u32@0x0, fn_88420F08 */
ts4_word ts4_call_seq_u32_off24_886459A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    __vector4 vv8;
    __vector4 vv13;
    ts4_word loc50[4];
    ts4_word loc70[4];
    ts4_word loc60[4];
    ts4_word t2;
    float t3;
    float t4;
    float t5;
    float t6;
    ts4_word t7;
    ts4_word t9;
    float t10;
    float t11;
    float t12;

    t2 = ts4_call_seq_fn_884027D8_88402FD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    t3 = *(float *)((char *)(ts4_word)(a2) + 0);
    t4 = *(float *)((char *)(ts4_word)(a2) + 4);
    t5 = *(float *)((char *)(ts4_word)(a2) + 8);
    *(float *)((char *)loc50 + 0) = t3;
    *(float *)((char *)loc50 + 4) = t4;
    t6 = *(float *)lbl_8814B440;
    *(float *)((char *)loc50 + 8) = t5;
    t7 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    *(float *)((char *)loc50 + 12) = t6;
    vv8 = *(__vector4 *)((ts4_word)((ts4_word)&loc50[0]));
    *(__vector4 *)((ts4_word)((ts4_word)&loc70[0])) = vv8;
    t9 = fn_88420F08((ts4_word)(ts4_word)&loc60[0], (ts4_word)(((a1 + (a1 << 1)) << 4) + t7), (ts4_word)(ts4_word)&loc70[0]);
    t10 = *(float *)((char *)loc60 + 0);
    t11 = *(float *)((char *)loc60 + 4);
    t12 = *(float *)((char *)loc60 + 8);
    *(float *)((char *)loc50 + 12) = t6;
    *(float *)((char *)loc50 + 0) = t10;
    *(float *)((char *)loc50 + 4) = t11;
    *(float *)((char *)loc50 + 8) = t12;
    vv13 = *(__vector4 *)((ts4_word)((ts4_word)&loc50[0]));
    *(__vector4 *)((ts4_word)(a2)) = vv13;
    return t9;
}

/* Swing_DLL.xex 0x88645DB0: get u32@0x0, ts4_find_service, u32@0x0, u32@0x28, vcall, fn_88923530 */
ts4_word ts4_get_u32_off0_88645DB0(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t7;

    t2 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2);
    (void)loc50[2];
    t7 = fn_88923530((ts4_word)t2, *(ts4_args3 *)&loc50[0], (ts4_word)((2657419264) | 21659));
    return t7;
}

/* Swing_DLL.xex 0x8864A348: call_seq fn_88627EC0, lbl_880F5F70, fn_8862C0E8, fn_88923530, u32@0x1c */
ts4_word ts4_call_seq_fn_88627EC0_8864A348(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t5;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F5F70);
    t4 = loc50[2];
    t5 = fn_88923530((ts4_word)t4, *(ts4_args3 *)&loc50[0], (ts4_word)((815923200) | 17443));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t5;
    return t5;
}

/* Swing_DLL.xex 0x8864B318: if_call_seq u32@0x80, u32@0x4, ts4_tailcall_NetDll_select_884F02F8, ts4_tailcall_NetDll__WSAFDIsSet_884F0398, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off80_8864B318(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc60[68];
    ts4_word loc50[4];
    ts4_word loc170[68];
    ts4_word t1;
    ts4_word t2;
    int t3;
    int t4;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    loc60[0] = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc60[0] = (ts4_word)1;
    loc170[0] = (ts4_word)1;
    loc60[1] = (ts4_word)t2;
    loc170[1] = (ts4_word)t2;
    t3 = ts4_tailcall_NetDll_select_884F02F8((ts4_word)(t2 + 1), (ts4_word)0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc170[0], (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t3;
    if ((int)t3 != 0) {
        if ((int)t3 < 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)2;
            return t3;
        }
        t4 = ts4_tailcall_NetDll__WSAFDIsSet_884F0398((ts4_word)t2, (ts4_word)(ts4_word)&loc170[0]);
        if ((int)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)2;
        }
        t5 = ts4_tailcall_NetDll__WSAFDIsSet_884F0398((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
        if ((int)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)3;
        }
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8864D528: if_call_seq u32@0x0, u32@0x20, u32@0x1c, lbl_88D44040, u8@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_8864D528(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    int t1;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)1;
        return -1;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a3;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    memset((ts4_word)(ts4_word)lbl_88D44040, (ts4_word)0, (ts4_word)512);
    t4 = fn_885635D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)(ts4_word)lbl_880F5A24, (ts4_word)a2, (ts4_word)a3);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t4;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t5 = ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t4);
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 304) = (ts4_u64)((ts4_s64)(ts4_word)t5);
    return 0;
}

/* Swing_DLL.xex 0x8864E3A0: set  */
void ts4_set_8864E3A0(ts4_word a0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, float f14, float f15, float f16)
{
    *(float *)((char *)(ts4_word)(a0) + 44) = f12;
    *(float *)((char *)(ts4_word)(a0) + 48) = f13;
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    *(float *)((char *)(ts4_word)(a0) + 12) = f4;
    *(float *)((char *)(ts4_word)(a0) + 16) = f5;
    *(float *)((char *)(ts4_word)(a0) + 20) = f6;
    *(float *)((char *)(ts4_word)(a0) + 24) = f7;
    *(float *)((char *)(ts4_word)(a0) + 28) = f8;
    *(float *)((char *)(ts4_word)(a0) + 32) = f9;
    *(float *)((char *)(ts4_word)(a0) + 36) = f10;
    *(float *)((char *)(ts4_word)(a0) + 40) = f11;
    *(float *)((char *)(ts4_word)(a0) + 52) = f14;
    *(float *)((char *)(ts4_word)(a0) + 56) = f15;
    *(float *)((char *)(ts4_word)(a0) + 60) = f16;
    return;
}

/* Swing_DLL.xex 0x88655AD0: if_get u32@0x54, lbl_880F500C, u32@0x38, vcall, u32@0x0, u32@0x4c */
ts4_word ts4_if_get_u32_off54_88655AD0(ts4_word a0)
{
    ts4_word p14;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 84))) + 56))))((ts4_word)(a0 + 84), (ts4_word)(ts4_word)lbl_880F500C, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)(t3 & 0xff) == 0) {
        p14 = (ts4_word)0;
    } else {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0))) + 76))))((ts4_word)(a0 + 84), (ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)t6;
        t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0))) + 76))))((ts4_word)(a0 + 84), (ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)(t9 + 12);
        t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0))) + 76))))((ts4_word)(a0 + 84), (ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t12) + 24));
        p14 = (ts4_word)1;
    }
    return p14;
}

/* Swing_DLL.xex 0x88657290: if_get u32@0x1c, u32@0x30, vcall, u32@0x78, u32@lbl_88D45B1C, u32@0x234 */
void ts4_if_get_u32_off1c_88657290(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t7;
    ts4_word t10;
    ts4_u64 t11;
    ts4_u64 t12;

    if ((ts4_word)a1 != 0) {
        t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28));
        if ((ts4_word)(t3 & 0xff) != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)) == (ts4_word)a2) {
            t7 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a2);
            if ((ts4_word)t7 != 0) {
                t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
                t11 = *(ts4_u64 *)((char *)(ts4_word)(t7) + 168);
                t12 = *(ts4_u64 *)((char *)(ts4_word)(a0) + 112);
                if ((ts4_u64)t12 == (ts4_u64)t11) {
                    *(ts4_u64 *)((char *)(ts4_word)(t10) + 88) = (ts4_u64)t11;
                    fn_88925640((ts4_word)(a0 + 28), (ts4_word)a1);
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x88657750: if_get u32@0x24, u32@0x2c, u32@0x2c, u32@0x1c, u32@0x0, u32@0x10 */
ts4_word ts4_if_get_u32_off24_88657750(ts4_word a0)
{
    int t1;
    ts4_word t3;
    ts4_word t4;
    int t12;
    unsigned char t14;
    ts4_word t22;
    ts4_word t16;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((ts4_word)t3 != 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4, (ts4_word)t1, (ts4_word)t3);
        }
        ts4_registry_dispatch_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    }
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t12 != 0) {
        t14 = *(unsigned char *)((char *)(ts4_word)(a0) + 48);
        if ((ts4_word)t14 != 0) {
            t22 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 4);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t22) + 0))) + 88))))((ts4_word)t22, (ts4_word)(a0 + 28));
        } else {
            t16 = *(ts4_word *)lbl_88D45B2C;
            if ((ts4_word)t16 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 56))))((ts4_word)t16, (ts4_word)(a0 + 28));
            }
        }
        *(volatile ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0) = (ts4_word)0;
    }
    return 1;
}

/* Swing_DLL.xex 0x88657B90: call_seq u32@0x8, lbl_880F50FC, u32@0xc, u32@0x0, u32@lbl_88D45B38, fn_88613268 */
ts4_word ts4_call_seq_u32_off8_88657B90(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F50FC;
    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)a1, (ts4_word)1, (ts4_word)0, (ts4_word)2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    return a0;
}

/* Swing_DLL.xex 0x8865A0A0: get u32@0x14 */
void ts4_get_u32_off14_8865A0A0(ts4_word a0)
{
    __vector4 vv1;
    ts4_word t2;

    vv1 = __vspltisw(0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(float *)((char *)(ts4_word)(t2) + 16) = (*(float *)lbl_8814B440);
    *(__vector4 *)((ts4_word)(t2)) = vv1;
    return;
}

/* Swing_DLL.xex 0x8865E730: if_get  */
void ts4_if_get_8865E730(ts4_word a0, int a1)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv6;
    __vector4 vv7;
    ts4_word locm10[1];
    ts4_word locmc[1];
    float t1;

    if ((int)a1 == (int)((2733441024) | 41447)) {
        t1 = *(float *)((char *)(ts4_word)(a0) + 0);
        vv2 = *(__vector4 *)((ts4_word)(a0));
        *(float *)((char *)locm10 + 0) = (-t1);
        vv3 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
        vv4 = __vrlimi(vv2, vv3, 8, 0);
        *(__vector4 *)((ts4_word)(a0)) = vv4;
        *(float *)((char *)locmc + 0) = (-(*(float *)((char *)(ts4_word)(a0) + 8)));
        vv6 = __lvlx((void *)((ts4_word)&locmc[0]), 0);
        vv7 = __vrlimi(vv4, vv6, 2, 2);
        *(__vector4 *)((ts4_word)(a0)) = vv7;
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8865EAC0: get u32@0x28, u32@0x20, u32@0x10 */
ts4_word ts4_get_u32_off28_8865EAC0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    return (*(ts4_word *)((char *)(ts4_word)(((t1 == 0) << 2)) + (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 16))));
}

/* Swing_DLL.xex 0x8865EBA8: if_get u32@0x4c, u32@0x2c, u32@0x18, u32@0x10 */
ts4_word ts4_if_get_u32_off4c_8865EBA8(ts4_word a0)
{
    ts4_word t1;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    if ((int)t2 != 2) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return (*(ts4_word *)((char *)(ts4_word)(((t3 == 0) << 2)) + (*(ts4_word *)((char *)(ts4_word)(t1) + 16))));
}

/* Swing_DLL.xex 0x8865EBF8: if_get u32@0x4c, u32@0x24, u32@0xb0 */
void ts4_if_get_u32_off4c_8865EBF8(ts4_word a0, ts4_word a1)
{
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv9;
    __vector4 vv10;
    ts4_word locm10[1];
    ts4_word locmc[1];
    int t3;
    float t4;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 76))) + 36))) + 176);
    if ((int)t3 == (int)((2733441024) | 41447)) {
        t4 = *(float *)((char *)(ts4_word)(a1) + 0);
        vv5 = *(__vector4 *)((ts4_word)(a1));
        *(float *)((char *)locm10 + 0) = (-t4);
        vv6 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
        vv7 = __vrlimi(vv5, vv6, 8, 0);
        *(__vector4 *)((ts4_word)(a1)) = vv7;
        *(float *)((char *)locmc + 0) = (-(*(float *)((char *)(ts4_word)(a1) + 8)));
        vv9 = __lvlx((void *)((ts4_word)&locmc[0]), 0);
        vv10 = __vrlimi(vv7, vv9, 2, 2);
        *(__vector4 *)((ts4_word)(a1)) = vv10;
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8865EC70: if_get u32@0x4c, u32@0x74, u32@0x24, u32@0xb0 */
void ts4_if_get_u32_off4c_8865EC70(ts4_word a0, ts4_word a1)
{
    __vector4 vv4;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 pv12;
    ts4_word locm10[3];
    ts4_word locm20[1];
    ts4_word locm1c[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 116);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    vv4 = *(__vector4 *)((ts4_word)(t2 + 2272));
    *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv4;
    t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 176);
    pv12 = vv4;
    if ((int)t5 == (int)((2733441024) | 41447)) {
        *(float *)((char *)locm20 + 0) = (-(*(float *)((char *)locm10 + 0)));
        vv7 = __lvlx((void *)((ts4_word)&locm20[0]), 0);
        vv8 = __vrlimi(vv4, vv7, 8, 0);
        *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv8;
        *(float *)((char *)locm1c + 0) = (-(*(float *)((char *)locm10 + 8)));
        vv10 = __lvlx((void *)((ts4_word)&locm1c[0]), 0);
        vv11 = __vrlimi(vv8, vv10, 2, 2);
        pv12 = vv11;
    }
    *(__vector4 *)((ts4_word)(a0)) = pv12;
    return;
}

/* Swing_DLL.xex 0x8865FC68: get u32@0x20, u32@0x20, u32@0xc8, u32@0x20, u32@0xd0, u32@0x20 */
void ts4_get_u32_off20_8865FC68(ts4_word a0)
{
    __vector4 vv1;

    vv1 = __vspltisw(0);
    *(__vector4 *)((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) + 64)) = vv1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 200) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 208) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 216) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 224) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 232) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 176) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 184) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 192) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8865FDA8: get u32@0xc, u32@0x8, u32@0x54, u32@0x38, u32@0x0 */
void ts4_get_u32_offc_8865FDA8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((((int)((ts4_word)((t1 + (*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + -1) % 10) * 1052) + a1)) + 84))) + 56));
    return;
}

/* Swing_DLL.xex 0x88661398: get  */
void ts4_get_88661398(ts4_word a0)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    ts4_word locm10[1];
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 8);
    vv2 = *(__vector4 *)((ts4_word)(a0));
    *(float *)((char *)locm10 + 0) = (-t1);
    vv3 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv4 = __vrlimi(vv2, vv3, 2, 2);
    *(__vector4 *)((ts4_word)(a0)) = vv4;
    return;
}

/* Swing_DLL.xex 0x886613C0: if_get  */
void ts4_if_get_886613C0(ts4_word a0, int a1)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv6;
    __vector4 vv7;
    ts4_word locm10[1];
    ts4_word locmc[1];
    float t1;

    if ((int)a1 == (int)((2733441024) | 41447)) {
        t1 = *(float *)((char *)(ts4_word)(a0) + 0);
        vv2 = *(__vector4 *)((ts4_word)(a0));
        *(float *)((char *)locm10 + 0) = (-t1);
        vv3 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
        vv4 = __vrlimi(vv2, vv3, 8, 0);
        *(__vector4 *)((ts4_word)(a0)) = vv4;
        *(float *)((char *)locmc + 0) = (-(*(float *)((char *)(ts4_word)(a0) + 8)));
        vv6 = __lvlx((void *)((ts4_word)&locmc[0]), 0);
        vv7 = __vrlimi(vv4, vv6, 2, 2);
        *(__vector4 *)((ts4_word)(a0)) = vv7;
        return;
    }
    return;
}

/* Swing_DLL.xex 0x88661460: copy memcpy */
ts4_word ts4_copy_memcpy_88661460(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_q6 *)(a1) = *(ts4_q6 *)(a2);
    memcpy((ts4_word)a0, (ts4_word)a2, (ts4_word)48);
    return a0;
}

/* Swing_DLL.xex 0x886614D8: get  */
void ts4_get_886614D8(ts4_word a0)
{
    __vector4 vv1;

    vv1 = __vspltisw(0);
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)lbl_8814B440);
    *(__vector4 *)((ts4_word)(a0)) = vv1;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv1;
    return;
}

/* Swing_DLL.xex 0x88662DF0: call_seq fn_88923530, u32@0x0, u32@0x8, u32@0x44, u32@0xc */
ts4_word ts4_call_seq_fn_88923530_88662DF0(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;

    (void)a3;
    (void)a4;
    t1 = sp1.w[2];
    t2 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2768175104) | 50209));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0)) + t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a5) + 68)) + 180);
    return t2;
}

/* Swing_DLL.xex 0x88663328: if_get u32@0x1c, u32@0x18, u32@0x50, u32@0x1c, u32@0x8, u32@0x2c */
ts4_word ts4_if_get_u32_off1c_88663328(ts4_word a0)
{
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv20;
    __vector4 vv21;
    __vector4 vv22;
    ts4_word locm10[1];
    ts4_word t3;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t25;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t14;

    t3 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 24))) + 80);
    if ((ts4_word)t3 == (ts4_word)((2686844928) | 5384)) {
        t15 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
        t16 = *(volatile ts4_word *)((char *)(ts4_word)(t15) + 8);
        t17 = *(volatile ts4_word *)((char *)(ts4_word)(t15) + 44);
        t18 = *(volatile ts4_word *)((char *)(ts4_word)(t16) + 116);
        *(float *)((char *)locm10 + 0) = (-(*(float *)((char *)(ts4_word)(t17) + 52)));
        vv20 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
        vv21 = *(__vector4 *)((ts4_word)((t18 + 2464)));
        vv22 = __vrlimi(vv21, vv20, 8, 0);
        *(__vector4 *)((ts4_word)((t18 + 2464))) = vv22;
        t25 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))) + 116);
        *(volatile ts4_word *)((char *)(ts4_word)(t25) + 2556) = (ts4_word)((1215627264) | 28900);
        return t25;
    }
    if ((ts4_word)t3 != (ts4_word)((395706368) | 58243)) {
        return a0;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 8);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 44);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(t5) + 116);
    *(float *)((char *)locm10 + 0) = (-(*(float *)((char *)(ts4_word)(t6) + 48)));
    vv9 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv10 = *(__vector4 *)((ts4_word)((t7 + 2464)));
    vv11 = __vrlimi(vv10, vv9, 8, 0);
    *(__vector4 *)((ts4_word)((t7 + 2464))) = vv11;
    t14 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))) + 116);
    *(volatile ts4_word *)((char *)(ts4_word)(t14) + 2556) = (ts4_word)((1215627264) | 28900);
    return t14;
}

/* Swing_DLL.xex 0x8866BA40: if_get u32@0x1c, u32@0x48, u32@0x74, u32@0x5c, u32@0x8d0, u32@0x20 */
ts4_word ts4_if_get_u32_off1c_8866BA40(ts4_word a0, float f11, float f12, float f13)
{
    __vector4 vv7;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv12;
    __vector4 vv13;
    __vector4 pv14;
    ts4_word locm10[3];
    ts4_word locm20[1];
    ts4_word locm1c[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    ts4_word t22;
    float t23;
    float t25;

    (void)f11;
    (void)f12;
    (void)f13;
    (void)pv14;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 72);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 116);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 92);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 2256);
    vv7 = *(__vector4 *)((ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t4) + 32)) + 64));
    *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv7;
    pv14 = vv7;
    if ((int)t5 == (int)((2733441024) | 41447)) {
        *(float *)((char *)locm20 + 0) = (-(*(float *)((char *)locm10 + 0)));
        vv9 = __lvlx((void *)((ts4_word)&locm20[0]), 0);
        vv10 = __vrlimi(vv7, vv9, 8, 0);
        *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv10;
        *(float *)((char *)locm1c + 0) = (-(*(float *)((char *)locm10 + 8)));
        vv12 = __lvlx((void *)((ts4_word)&locm1c[0]), 0);
        vv13 = __vrlimi(vv10, vv12, 2, 2);
        *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv13;
        pv14 = vv13;
    }
    t22 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t23 = *(float *)((char *)locm10 + 0);
    t25 = *(float *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t22) + 116))) + 2272);
    if (t25 > t23) {
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8866CD98: get u32@0x14, u8@0x70, u32@0x5c, u8@0x71 */
void ts4_get_u32_off14_8866CD98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)(((((1215627264) | 28900) - a1) == 0) ? a2 : 0);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 92) = (ts4_word)a1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8866CF40: call_seq u32@0x10, u32@0x18, u32@0x74, u32@0x14, fn_8865E638 */
ts4_word ts4_call_seq_u32_off10_8866CF40(ts4_word a0)
{
    __vector4 vv5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    float t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 116)) + 2464);
    t4 = fn_8865E638((ts4_word)t2, (ts4_word)t1);
    vv5 = __vspltisw(0);
    t6 = *(float *)lbl_8814B440;
    *(float *)((char *)(ts4_word)(a0) + 100) = t6;
    *(float *)((char *)(ts4_word)(a0) + 104) = t6;
    *(__vector4 *)((ts4_word)(a0 + 64)) = vv5;
    *(__vector4 *)((ts4_word)(a0 + 80)) = vv5;
    return t4;
}

/* Swing_DLL.xex 0x8866DC18: if_call_seq u32@0x0, fn_881BBC00, u32@0x4, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8866DC18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = fn_881BBC00((ts4_word)(a1 + 200), (ts4_word)(ts4_word)&a2);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4);
        p5 = (ts4_word)(t1 + 4);
        if ((ts4_word)t3 == (ts4_word)((3751936000) | 45041)) {
            loc50[0] = (ts4_word)((753074176) | 14659);
            p5 = (ts4_word)(ts4_word)&loc50[0];
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(p5) + 0));
    }
    return a0;
}

/* Swing_DLL.xex 0x8866E448: loop_get u32@0x8, u32@0x4, u32@0x4, u32@0x44, u8@0x84, u32@0x44 */
void ts4_loop_get_u32_off8_8866E448(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    unsigned char t10;

    (void)a1;
    (void)a2;
    (void)a3;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)((int)(t1 - t2) >> 2) != 0) {
        c3 = (ts4_word)((int)(t1 - t2) >> 2);
        lv4 = (ts4_word)0;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
            if ((ts4_word)t6 != 0) {
                t10 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 68))) + 132);
                if ((ts4_word)t10 == 0 || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t6) + 16)) == 0) {
                    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 116))) + 1253) = (unsigned char)0;
                } else {
                    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 116))) + 1253) = (unsigned char)1;
                }
            }
            p17 = (ts4_word)(lv4 + 4);
            lv4 = p17;
        } while (--c3 != 0);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8866F5E0: get u32@0x20, u32@0xc8, u32@0x20, u32@0xd0, u32@0x20, u32@0xd8 */
void ts4_get_u32_off20_8866F5E0(ts4_word a0)
{
    __vector4 vv2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    vv2 = __vspltisw(0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 200) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 208) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 216) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 224) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 232) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 176) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 184) = (ts4_word)((2147418112) | 65535);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 192) = (ts4_word)((2147418112) | 65535);
    *(__vector4 *)((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68)) + 512)) = vv2;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68))) + 532) = (ts4_word)0;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886708D0: call_seq fn_88661188 */
void ts4_call_seq_fn_88661188_886708D0(void)
{
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    ts4_word loc50[2];
    ts4_word t1;

    t1 = fn_88661188();
    *(float *)((char *)loc50 + 0) = (-(*(float *)((char *)(ts4_word)(t1) + 72)));
    vv3 = *(__vector4 *)((ts4_word)((t1 + 64)));
    vv4 = __lvlx((void *)((ts4_word)&loc50[0]), 0);
    vv5 = __vrlimi(vv3, vv4, 2, 2);
    *(__vector4 *)((ts4_word)((t1 + 64))) = vv5;
    return;
}

/* Swing_DLL.xex 0x8867AEB8: if_get u32@0x74, u8@0x5da, u8@0x4d8, u8@0x404, u32@0x3c, u8@0x400 */
void ts4_if_get_u32_off74_8867AEB8(ts4_word a0)
{
    ts4_word t1;
    signed char t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1498);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)((2125660160) | 3984);
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1024) = (unsigned char)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1025) = (unsigned char)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1026) = (unsigned char)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1027) = (unsigned char)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1033) = (unsigned char)1;
        *(volatile unsigned char *)(1028 + (char *)(ts4_word)(t1)) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(t1) + 1240));
        return;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 1028) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(t1) + 1240));
    return;
}

/* Swing_DLL.xex 0x88683D78: call_seq u32@0x0, fn_88181240, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_88683D78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, float f1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    t2 = fn_88181240((ts4_word)t1, (ts4_word)a1, *(ts4_args2 *)&loc50[0]);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)a2;
    *(volatile float *)((char *)(ts4_word)(t3) + 20) = f1;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)a4;
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)a5;
    t5 = ts4_loop_get_u32_off8_8861DDB0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t2);
    return t5;
}

/* Swing_DLL.xex 0x88698B28: if_call_seq u8@0x13c, u8@0x13c, fn_886887C0, u32@0x154, u32@0x74, u8@0xdec */
float ts4_if_call_seq_u8_off13c_88698B28(ts4_word a0, ts4_word a1, float f1, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    float pf8;
    unsigned char t1;
    float t2;
    ts4_word t4;
    float t5;

    (void)a1;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 316);
    pf8 = f1;
    if ((ts4_word)t1 == 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 316) = (unsigned char)1;
        t2 = fn_886887C0((ts4_word)a0, f1);
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 116);
        t5 = *(float *)lbl_8814B440;
        *(volatile unsigned char *)((char *)(ts4_word)(t4) + 3564) = (unsigned char)1;
        *(volatile float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 116))) + 3560) = t2;
        *(volatile float *)((char *)(ts4_word)(a0) + 320) = t2;
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 332) = (unsigned char)0;
        *(volatile float *)((char *)(ts4_word)(a0) + 324) = t5;
        *(volatile float *)((char *)(ts4_word)(a0) + 328) = t2;
        *(volatile float *)((char *)(ts4_word)(a0) + 336) = t5;
        pf8 = t2;
    }
    return pf8;
}

/* Swing_DLL.xex 0x8869FD88: call_seq u32@0x8, u32@0x54, fn_886917F8, u32@0x8, u32@0xc, u32@0xc */
ts4_word ts4_call_seq_u32_off8_8869FD88(ts4_word a0)
{
    ts4_word t4;

    fn_886917F8((ts4_word)(a0 + 32), (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((((int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)) * 1052) + a0)) + 84)) + 20), (ts4_word)-1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12)) + -1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((int)(t4 + 1) % 10);
    return ((int)(t4 + 1) % 10);
}

/* Swing_DLL.xex 0x886A7678: call_seq u32@0xc, u32@0x8, u32@0xc, fn_886A7610 */
ts4_word ts4_call_seq_u32_offc_886A7678(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 + 1);
    fn_886A7610((ts4_word)a0, (ts4_word)((((int)((int)(t2 + t1) % 10) * 1052) + a0) + 52), (ts4_word)a1);
    return ((((int)((int)(t2 + t1) % 10) * 1052) + a0) + 52);
}

/* Swing_DLL.xex 0x886A7988: if_get u32@0xd4, lbl_880F44B4, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_offd4_886A7988(ts4_word a0)
{
    ts4_word p39;
    ts4_word t1;
    ts4_word t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    ts4_word t24;
    ts4_word t27;
    ts4_word t31;
    ts4_word t34;
    ts4_word t37;
    ts4_word t38;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 212);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F44B4;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    fn_8890F1E8((ts4_word)(a0 + 616));
    fn_8890F1E8((ts4_word)(a0 + 548));
    fn_8890F1E8((ts4_word)(a0 + 480));
    fn_8890F1E8((ts4_word)(a0 + 412));
    fn_8890F1E8((ts4_word)(a0 + 344));
    t11 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 280);
    if ((ts4_word)t11 != 0) {
        ts4_destroy_owned_object((ts4_word)t11);
    }
    t14 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 268);
    if ((ts4_word)t14 != 0) {
        ts4_destroy_owned_object((ts4_word)t14);
    }
    t17 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 256);
    if ((ts4_word)t17 != 0) {
        ts4_destroy_owned_object((ts4_word)t17);
    }
    t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 244);
    if ((ts4_word)t20 != 0) {
        ts4_destroy_owned_object((ts4_word)t20);
    }
    fn_88661A70((ts4_word)(a0 + 216));
    t24 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 228);
    if ((ts4_word)t24 != 0) {
        ts4_destroy_owned_object((ts4_word)t24);
    }
    t27 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 216)) + 0);
    if ((ts4_word)t27 != 0) {
        ts4_destroy_owned_object((ts4_word)t27);
    }
    fn_8865A5E0((ts4_word)(a0 + 64));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    t31 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188);
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    t34 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t34 != 0) {
        ts4_destroy_owned_object((ts4_word)t34);
    }
    t37 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    p39 = (ts4_word)t37;
    if ((ts4_word)t37 != 0) {
        t38 = ts4_destroy_owned_object((ts4_word)t37);
        p39 = (ts4_word)t38;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F436C;
    return p39;
}

/* Swing_DLL.xex 0x886C15A0: loop_call_seq u32@0x8, u32@0x4, u32@0x0, u32@0x40, u8@0x0, u32@0x5c */
ts4_word ts4_loop_call_seq_u32_off8_886C15A0(ts4_word a0)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p16;
    ts4_word p17;
    ts4_word p18;
    ts4_word p19;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p19 = (ts4_word)a0;
    lv3 = (ts4_word)a0;
    lv4 = (ts4_word)t2;
    while ((ts4_word)lv4 != (ts4_word)t1) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        p16 = (ts4_word)lv3;
        if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 64))) + 0)) == 0) {
            fn_8869C010((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 92)));
            fn_8866CDC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv4) + 0))) + 92)));
            t15 = fn_886C0050((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv4) + 0))) + 100)));
            p16 = (ts4_word)t15;
        }
        p17 = (ts4_word)p16;
        p18 = (ts4_word)(lv4 + 4);
        lv3 = p17;
        lv4 = p18;
        p19 = (ts4_word)lv3;
    }
    return p19;
}

/* Swing_DLL.xex 0x886C3E28: fn  */
__vector4 ts4_fn_886C3E28(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;
    __vector4 vv13;
    __vector4 vv14;
    __vector4 vv15;

    vv1 = *(__vector4 *)((ts4_word)(a0));
    vv2 = *(__vector4 *)((ts4_word)(a1));
    vv3 = __vspltisw(0);
    vv4 = __vsubfp(vv1, vv2);
    vv5 = *(__vector4 *)((ts4_word)(a0 + 16));
    vv6 = __vupkd3d(vv3, 0);
    vv7 = *(__vector4 *)((ts4_word)(a1 + 16));
    vv8 = __vsubfp(vv5, vv1);
    vv9 = __vsubfp(vv7, vv2);
    vv10 = __vsubfp(vv9, vv8);
    vv11 = __vrefp(vv10);
    vv12 = __vnmsubfp(vv10, vv11, vv6);
    vv13 = __vmaddfp(vv11, vv12, vv11);
    vv14 = __vmulfp(vv4, vv13);
    vv15 = __vspltw(vv14, 3);
    return vv15;
}

/* Swing_DLL.xex 0x886C3E70: fn  */
void ts4_fn_886C3E70(ts4_word a0, ts4_word a1, __vector4 vp1, __vector4 vp2, __vector4 vp3, __vector4 vp4)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;
    __vector4 vv13;
    __vector4 vv14;

    vv1 = __vsubfp(vp2, vp1);
    vv2 = __vspltisw(0);
    vv3 = *(__vector4 *)((ts4_word)(a0));
    vv4 = __vsubfp(vp3, vp1);
    vv5 = *(__vector4 *)((ts4_word)(a1));
    vv6 = __vsubfp(vp4, vp1);
    vv7 = __vsubfp(vv5, vv3);
    vv8 = __vupkd3d(vv2, 0);
    vv9 = __vrefp(vv1);
    vv10 = __vnmsubfp(vv1, vv9, vv8);
    vv11 = __vmaddfp(vv9, vv10, vv9);
    vv12 = __vmulfp(vv11, vv7);
    vv13 = __vmaddfp(vv12, vv4, vv3);
    vv14 = __vmaddfp(vv12, vv6, vv3);
    *(__vector4 *)((ts4_word)(a0)) = vv13;
    *(__vector4 *)((ts4_word)(a1)) = vv14;
    return;
}

/* Swing_DLL.xex 0x886C3F88: get u32@0x15c */
void ts4_get_u32_off15c_886C3F88(ts4_word a0, ts4_word a1)
{
    __vector4 vv3;
    __vector4 vv5;
    __vector4 vv6;
    ts4_word locm10[1];
    ts4_word t1;
    float t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 348);
    t2 = *(float *)((char *)(ts4_word)(a1) + 8);
    vv3 = *(__vector4 *)((ts4_word)(a1));
    *(float *)((char *)locm10 + 0) = ((*(float *)((char *)(ts4_word)(t1) + 1372)) * t2);
    vv5 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv6 = __vrlimi(vv3, vv5, 2, 2);
    *(__vector4 *)((ts4_word)(a1)) = vv6;
    return;
}

/* Swing_DLL.xex 0x886C4B90: loop_get u32@0x44 */
ts4_word ts4_loop_get_u32_off44_886C4B90(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p4;
    ts4_word p5;
    ts4_word p6;
    ts4_word t3;

    if ((ts4_word)(a0 + 128) == (ts4_word)a1) {
        return 0;
    }
    lv1 = (ts4_word)(a0 + 128);
    lv2 = (ts4_word)0;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv1) + 68);
        p4 = (ts4_word)lv2;
        if ((ts4_word)t3 == (ts4_word)((8257536) | 25588)) {
            p4 = (ts4_word)1;
        }
        p5 = (ts4_word)(lv1 + 128);
        p6 = (ts4_word)p4;
        lv1 = p5;
        lv2 = p6;
    } while ((ts4_word)p5 != (ts4_word)a1);
    return lv2;
}

/* Swing_DLL.xex 0x886C4EE0: fn  */
void ts4_fn_886C4EE0(ts4_word a0, __vector4 vp1, __vector4 vp2, __vector4 vp3, __vector4 vp4)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;

    vv1 = __vmulfp(vp2, vp4);
    vv2 = __vspltisw(0);
    vv3 = __vspltw(vp1, 1);
    vv4 = __vupkd3d(vv2, 0);
    vv5 = __vsubfp(vv3, vp3);
    vv6 = __vspltw(vv1, 1);
    vv7 = __vcmpeqfp(vv6, vv2);
    vv8 = __vsel(vv6, vv4, vv7);
    vv9 = __vrefp(vv8);
    vv10 = __vmulfp(vv5, vv9);
    vv11 = __vmulfp(vv10, vv1);
    vv12 = __vsubfp(vp1, vv11);
    *(__vector4 *)((ts4_word)(a0)) = vv12;
    return;
}

/* Swing_DLL.xex 0x886C6568: set u32@0x70, u8@0x0, u32@0x10, u32@0x74, u32@0x78 */
void ts4_set_u32_off70_886C6568(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = __vspltisw(0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886EB148: fn  */
ts4_u64 ts4_fn_886EB148(ts4_word a0, ts4_word a1)
{
    return ((ts4_u64)((ts4_s64)((ts4_u64)1 << 63) >> ((ts4_s64)(ts4_word)(a1 - a0))) >> ((ts4_s64)(ts4_word)(a0 + 32)));
}

/* Swing_DLL.xex 0x886EB310: loop_get u32@0x4, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off4_886EB310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    lv4 = (ts4_word)0;
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)a1 == (ts4_word)t6) {
            return lv4;
        }
        p7 = (ts4_word)(lv3 + 4);
        p8 = (ts4_word)(lv4 + 1);
        lv3 = p7;
        lv4 = p8;
    }
    return -1;
}

/* Swing_DLL.xex 0x886EB350: loop_get u32@0x4, u32@0x0, u32@0x10, u32@0x10 */
ts4_word ts4_loop_get_u32_off4_886EB350(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    lv4 = (ts4_word)0;
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 16);
        if ((ts4_word)a1 == (ts4_word)t6) {
            return lv4;
        }
        p7 = (ts4_word)(lv3 + 20);
        p8 = (ts4_word)(lv4 + 1);
        lv3 = p7;
        lv4 = p8;
    }
    return -1;
}

/* Swing_DLL.xex 0x886ECDB8: loop_get u32@0x48, u32@0x44, u32@0x0, u32@0x0, u32@0x28, vcall */
ts4_word ts4_loop_get_u32_off48_886ECDB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4);
                if ((ts4_word)(t7 & 0xff) != 0) {
                    return 1;
                }
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t1);
        p11 = (ts4_word)0;
    } else {
        p11 = (ts4_word)0;
    }
    return p11;
}

/* Swing_DLL.xex 0x886ECE38: loop_get u32@0x48, u32@0x44, u32@0x0, u32@0x0, u32@0x28, vcall */
ts4_word ts4_loop_get_u32_off48_886ECE38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4);
                if ((ts4_word)(t7 & 0xff) == 0) {
                    return t4;
                }
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x886ED628: call_seq fn_886EC0E0, u16@0x10, u16@0x14, u16@0x10, u32@0x8 */
void ts4_call_seq_fn_886EC0E0_886ED628(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    unsigned short t3;
    unsigned short t4;

    t1 = fn_886EC0E0((ts4_word)a0, (ts4_word)a1);
    *(float *)((char *)(ts4_word)(a2) + 0) = ((float)((double)((ts4_s64)((short)(*(unsigned short *)((char *)(ts4_word)(t1) + 16))))));
    t3 = *(unsigned short *)((char *)(ts4_word)(t1) + 20);
    t4 = *(unsigned short *)((char *)(ts4_word)(t1) + 16);
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)t1;
    *(float *)((char *)(ts4_word)(a2) + 4) = (((float)((double)((ts4_s64)((short)t3)))) - ((float)((double)((ts4_s64)((short)t4)))));
    return;
}

/* Swing_DLL.xex 0x886EF1A0: if_get u32@0x34, u32@0xc, u32@0x80, u32@lbl_88D45AD0, u32@0x0, u32@0x34 */
ts4_word ts4_if_get_u32_off34_886EF1A0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    float t9;
    float t10;
    ts4_word t11;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 12);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 128);
    if ((ts4_word)t3 == (ts4_word)((2194472960) | 5838)) {
        t9 = *(float *)((char *)(ts4_word)(a0) + 220);
        t10 = *(float *)((char *)(ts4_word)(t2) + 144);
        if (t9 < t10) {
            return 0;
        }
        t11 = *(ts4_word *)lbl_88D45AD0;
        if ((ts4_word)t11 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 52))))((ts4_word)t11, (ts4_word)0, (ts4_word)-1);
        }
        return 1;
    }
    t4 = *(ts4_word *)lbl_88D45AD0;
    if ((ts4_word)t4 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 52))))((ts4_word)t4, (ts4_word)0, (ts4_word)-1);
    }
    return 1;
}

/* Swing_DLL.xex 0x886EF938: loop_get u32@0xc, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x24 */
ts4_word ts4_loop_get_u32_offc_886EF938(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word lv6;
    ts4_word p8;
    ts4_word p11;
    ts4_word t1;
    int t3;
    int t5;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
        p4 = (ts4_word)0;
        if ((int)t3 != -1) {
            p4 = (ts4_word)(t3 + t1);
        }
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
        lv6 = (ts4_word)p4;
        do {
            p8 = (ts4_word)0;
            if ((int)t5 != -1) {
                p8 = (ts4_word)((((int)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) * 52) + t5) + t1);
            }
            if ((ts4_word)lv6 == (ts4_word)p8) {
                return 0;
            }
            t10 = *(volatile ts4_word *)((char *)(ts4_word)(lv6) + 36);
            if ((ts4_word)a1 == (ts4_word)t10) {
                return lv6;
            }
            p11 = (ts4_word)(lv6 + 52);
            lv6 = p11;
        } while (1);
    }
    return 0;
}

/* Swing_DLL.xex 0x886F15E8: loop_get u32@0x40, u32@0x8, u32@0x4, vcall, u32@0x40, u32@0x28 */
void ts4_loop_get_u32_off40_886F15E8(ts4_word a0)
{
    ts4_word lv8;
    ts4_word lv19;
    ts4_word lv20;
    ts4_word p29;
    ts4_word p31;
    ts4_word p32;
    ts4_word lv40;
    ts4_word p45;
    ts4_word p51;
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;
    unsigned char t10;
    ts4_word t12;
    ts4_word t34;
    ts4_word t35;
    ts4_word t38;
    ts4_word t41;
    ts4_word t17;
    ts4_word t18;
    ts4_word t21;
    ts4_word t22;
    ts4_word t27;
    ts4_word t28;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8))) + 4))))((ts4_word)(t1 + 8));
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 40);
        lv8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 0));
        while ((ts4_word)lv8 != (ts4_word)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)(lv8) + 8);
            t10 = *(unsigned char *)((char *)(ts4_word)(t9) + 24);
            if ((ts4_word)t10 == 0) {
                t12 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
                if ((ts4_word)t12 == (ts4_word)((4293066752) | 60000)) {
                    t34 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
                    t35 = *(ts4_word *)((char *)(ts4_word)(t34) + 0);
                    if ((ts4_word)t35 != 0) {
                        *(ts4_word *)((char *)(ts4_word)(t34) + 0) = (ts4_word)(t35 + -1);
                    } else {
                        t38 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
                        lv40 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
                        while ((ts4_word)lv40 != (ts4_word)t38) {
                            t41 = *(ts4_word *)((char *)(ts4_word)(lv40) + 0);
                            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t41) + 0))) + 48))))((ts4_word)t41, (ts4_word)t34);
                            p45 = (ts4_word)(lv40 + 4);
                            lv40 = p45;
                        }
                        *(unsigned char *)((char *)(ts4_word)(t9) + 24) = (unsigned char)1;
                    }
                } else {
                    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
                    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
                    lv19 = (ts4_word)t12;
                    lv20 = (ts4_word)t18;
                    while ((ts4_word)lv20 != (ts4_word)t17) {
                        t21 = *(ts4_word *)((char *)(ts4_word)(lv20) + 0);
                        t22 = *(ts4_word *)((char *)(ts4_word)(t21) + 4);
                        p29 = (ts4_word)lv19;
                        if ((ts4_word)lv19 == (ts4_word)t22 || (ts4_word)lv19 == (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t21) + 8))) {
                            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t21) + 0))) + 16))))((ts4_word)t21, (ts4_word)t9);
                            t27 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
                            t28 = *(ts4_word *)((char *)(ts4_word)(t21) + 4);
                            if ((ts4_word)t27 == (ts4_word)t28) {
                                break;
                            }
                            p29 = (ts4_word)t27;
                        }
                        p31 = (ts4_word)p29;
                        p32 = (ts4_word)(lv20 + 4);
                        lv19 = p31;
                        lv20 = p32;
                    }
                    *(unsigned char *)((char *)(ts4_word)(t9) + 24) = (unsigned char)1;
                }
            }
            p51 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 0));
            lv8 = p51;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((t1 + 8)) + 0))) + 8))))((ts4_word)(t1 + 8));
    }
    return;
}

/* Swing_DLL.xex 0x886F57E0: loop_get u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_loop_get_u32_off0_886F57E0(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    int lv1;
    ts4_word p8;
    ts4_word lv2;
    ts4_word p9;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    lv2 = (ts4_word)0;
    lv1 = (ts4_word)a3;
    do {
        if ((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0)) == 0) {
            t5 = sp1.w[0];
            t6 = sp1.w[1];
            t7 = sp1.w[2];
            *(ts4_word *)((char *)(ts4_word)(((lv2 << 4) + a3)) + 0) = (ts4_word)a0;
            *(ts4_word *)(4 + (char *)(ts4_word)(((lv2 << 4) + a3))) = (ts4_word)t5;
            *(volatile ts4_word *)(8 + (char *)(ts4_word)(((lv2 << 4) + a3))) = (ts4_word)t6;
            *(volatile ts4_word *)(12 + (char *)(ts4_word)(((lv2 << 4) + a3))) = (ts4_word)t7;
            return;
        }
        p9 = (ts4_word)(lv2 + 1);
        p8 = (ts4_word)(lv1 + 16);
        lv1 = p8;
        lv2 = p9;
    } while ((int)p9 < 30);
    return;
}

/* Swing_DLL.xex 0x886F5988: call_seq u32@0x10, u32@0x18, u32@0x14, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_u32_off10_886F5988(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    t1 = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)((ts4_s64)(ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)((0) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x886F5AE0: loop_get u32@0x0, u32@lbl_88D45A74, fn_88608590, u32@0x0, u32@0x4, u32@0x10c */
ts4_word ts4_loop_get_u32_off0_886F5AE0(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p20;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    int t11;
    ts4_word t14;
    ts4_word t27;
    ts4_word t29;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)lbl_88D45A74;
    t3 = fn_88608590((ts4_word)0, (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    lv6 = (ts4_word)t4;
    while ((ts4_word)lv6 < (ts4_word)t5) {
        t9 = *(ts4_word *)((char *)(ts4_word)(lv6) + 268);
        if ((ts4_word)t9 == (ts4_word)t3) {
            t11 = *(ts4_word *)((char *)(ts4_word)(lv6) + 284);
            if ((int)t11 != 1) {
                if ((int)t11 == 2) {
                    ts4_if_call_seq_u32_off0_886ED438((ts4_word)t2);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv6) + 272));
                    return a0;
                }
                t14 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 40))))((ts4_word)a0, (ts4_word)t14, (ts4_word)t1, (ts4_word)1, (ts4_word)0);
                return a0;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv6) + 272));
            return a0;
        }
        p20 = (ts4_word)(lv6 + 308);
        lv6 = p20;
    }
    if ((ts4_word)t4 != (ts4_word)t5) {
        ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)lbl_88D42940));
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)lbl_88D41FDC), (ts4_word)-1);
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t29 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t29) + 0))) + 40))))((ts4_word)a0, (ts4_word)t29, (ts4_word)t27, (ts4_word)1, (ts4_word)0);
    return a0;
}

/* Swing_DLL.xex 0x88716458: get u32@0xe0, u32@0x0, u32@0x1c, vcall, u32@0x8, u64@0x0 */
ts4_word ts4_get_u32_offe0_88716458(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    fn_88713970(*(ts4_args3 *)((char *)(ts4_word)(t4) + 0), (ts4_word)0, (ts4_word)a1, (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88719768: get u32@0x0, u32@0x40, vcall, u32@0x8, u64@0x0, fn_88713970 */
ts4_word ts4_get_u32_off0_88719768(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t6 = fn_88713970(*(ts4_args3 *)((char *)(ts4_word)(t3) + 0), (ts4_word)0, (ts4_word)a1, (ts4_word)0);
    return t6;
}

/* Swing_DLL.xex 0x88734D68: if_call_seq lbl_880C1320, ts4_assign_formatted_text, ts4_if_addr_ts4_handle_forward_88150770_88731540, fn_881643D0, fn_88728C48, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880C1320_88734D68(ts4_args3 sp0)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C1320);
    loc50[0] = (ts4_word)((4262526976) | 53560);
    ts4_if_addr_ts4_handle_forward_88150770_88731540((ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C1320);
    if ((ts4_word)(t3 & 0xff) == 0) {
        fn_88728C48((ts4_word)(ts4_word)&loc58[0]);
    }
    t6 = loc58[0];
    t7 = ts4_destroy_owned_object((ts4_word)t6);
    return t7;
}

/* Swing_DLL.xex 0x88734DF0: if_call_seq lbl_880C1320, ts4_assign_formatted_text, ts4_if_addr_ts4_handle_forward_88150770_88731540, fn_881643D0, fn_88718C90, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880C1320_88734DF0(ts4_args3 sp0)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C1320);
    loc50[0] = (ts4_word)((4262526976) | 53560);
    ts4_if_addr_ts4_handle_forward_88150770_88731540((ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t3 = fn_881643D0((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C1320);
    if ((ts4_word)(t3 & 0xff) == 0) {
        fn_88718C90((ts4_word)(ts4_word)&loc58[0]);
    }
    t6 = loc58[0];
    t7 = ts4_destroy_owned_object((ts4_word)t6);
    return t7;
}

/* Swing_DLL.xex 0x8873B940: call_seq ts4_if_addr_ts4_handle_forward_88150770_88731540, fn_88736FB8 */
ts4_word ts4_call_seq_fn_88731540_8873B940(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[4];
    ts4_word t3;

    loc50[0] = (ts4_word)((3613655040) | 5928);
    ts4_if_addr_ts4_handle_forward_88150770_88731540((ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 56));
    (void)sp1.w[2];
    t3 = fn_88736FB8((ts4_word)a0, sp1);
    return t3;
}

/* Swing_DLL.xex 0x8873D008: loop_call_seq fn_88736FB8, u32@lbl_88D45A70, u32@0x68, u32@0x64, u32@0x38, u32@0x0 */
ts4_word ts4_loop_call_seq_fn_88736FB8_8873D008(ts4_word a0, ts4_args3 sp1)
{
    ts4_word lv6;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;

    (void)sp1.w[2];
    t2 = fn_88736FB8((ts4_word)a0, sp1);
    t3 = *(ts4_word *)lbl_88D45A70;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 104);
    t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 100);
    if ((ts4_word)t5 != (ts4_word)t4) {
        lv6 = (ts4_word)t5;
        do {
            t9 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
            t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
            if ((ts4_word)t10 == (ts4_word)((205520896) | 64918)) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t9;
                return t2;
            }
            p11 = (ts4_word)(lv6 + 4);
            lv6 = p11;
        } while ((ts4_word)p11 != (ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        return t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return t2;
}

/* Swing_DLL.xex 0x887417F0: get u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall, u32@lbl_88D45AD4, u32@0x10 */
ts4_word ts4_get_u32_lbl_88D45A4C_887417F0(ts4_args3 sp0)
{
    ts4_word t1;
    ts4_word t11;

    t1 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    (void)sp0.w[2];
    fn_88221570((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 16)), sp0);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return t11;
}

/* Swing_DLL.xex 0x88752C78: if_call_seq u32@0x0, u8@lbl_88D45AA7, fn_88748B18, fn_88748350, u32@0x38, u8@lbl_88D45AA7 */
ts4_word ts4_if_call_seq_u32_off0_88752C78(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    int t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    *(unsigned char *)lbl_88D45AA7 = (unsigned char)1;
    if ((int)t1 != 0) {
        fn_88748350((ts4_word)a0, (ts4_word)(ts4_word)&sp1, (ts4_word)a3);
    } else {
        fn_88748B18((ts4_word)a0, (ts4_word)(ts4_word)&sp1);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(unsigned char *)lbl_88D45AA7 = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(t5 | 1024);
    return 1;
}

/* Swing_DLL.xex 0x8876DD50: if_get u32@0x50, u32@0x4c */
void ts4_if_get_u32_off50_8876DD50(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    ts4_word locm10[2];
    int t2;

    vv1 = *(__vector4 *)((ts4_word)(a0 + 96));
    *(__vector4 *)((ts4_word)(a1)) = vv1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t2 < 0) {
        return;
    }
    *(float *)((char *)locm10 + 0) = (((float)((double)((ts4_s64)(int)t2))) / ((float)((double)((ts4_s64)(int)(*(ts4_word *)((char *)(ts4_word)(a0) + 76))))));
    vv4 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv5 = __vspltw(vv4, 0);
    vv6 = __vmulfp(vv1, vv5);
    *(__vector4 *)((ts4_word)(a1)) = vv6;
    return;
}

/* Swing_DLL.xex 0x8876DDB8: if_get u32@0x50, u32@0x4c */
void ts4_if_get_u32_off50_8876DDB8(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    ts4_word locm10[2];
    int t2;
    ts4_word t3;

    vv1 = *(__vector4 *)((ts4_word)(a0 + 96));
    *(__vector4 *)((ts4_word)(a1)) = vv1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t2 <= 0) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    *(float *)((char *)locm10 + 0) = (((float)((double)((ts4_s64)(int)(t3 - t2)))) / ((float)((double)((ts4_s64)(int)t3))));
    vv4 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv5 = __vspltw(vv4, 0);
    vv6 = __vmulfp(vv1, vv5);
    *(__vector4 *)((ts4_word)(a1)) = vv6;
    return;
}

/* Swing_DLL.xex 0x88777AF0: if_call_seq u32@0x24, u32@0x28, u32@0x30, fn_8862C0E8, fn_88923458, u32@0x3c */
ts4_word ts4_if_call_seq_u32_off24_88777AF0(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != (ts4_word)t2) {
        fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48)));
        t5 = loc50[2];
        t6 = fn_88923458((ts4_word)t5, *(ts4_args3 *)&loc50[0], (ts4_word)64);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t6;
    }
    fn_88150600((ts4_word)(a0 + 64), (ts4_word)(a0 + 36));
    t9 = ts4_find_service((ts4_word)((4227596288) | 37830));
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(t9) + 28);
    t11 = *(volatile ts4_word *)((char *)(ts4_word)(t9) + 32);
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(t9) + 36);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)t10;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)t11;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t12;
    return t9;
}

/* Swing_DLL.xex 0x88781EA8: loop_call_seq u8@0x620, u32@0x61c, u32@lbl_88D45B30, u32@0x20, u32@0x1c, u32@0x61c */
void ts4_loop_call_seq_u8_off620_88781EA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv10;
    ts4_word p14;
    ts4_word p15;
    ts4_word p17;
    ts4_word p18;
    unsigned char t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;

    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1568);
    if ((ts4_word)t1 != 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1564);
        t7 = *(ts4_word *)lbl_88D45B30;
        t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 32);
        t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 28);
        p17 = (ts4_word)0;
        p18 = (ts4_word)a5;
        if ((ts4_word)t8 != (ts4_word)t9) {
            p15 = (ts4_word)0;
            lv10 = (ts4_word)t9;
            do {
                t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
                if ((ts4_word)t6 == (ts4_word)t12) {
                    p15 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv10) + 4));
                    break;
                }
                p14 = (ts4_word)(lv10 + 8);
                lv10 = p14;
            } while ((ts4_word)t8 != (ts4_word)p14);
            p17 = (ts4_word)p15;
            p18 = (ts4_word)t12;
        }
        ts4_if_call_seq_u32_off3c34_88779858((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1560)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)p18, (ts4_word)t6, (ts4_word)t8);
        fn_888870F0((ts4_word)p17, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1560))) + 15412)));
        ts4_loop_call_seq_u32_off3c34_88778C48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1560)));
        *(unsigned char *)((char *)(ts4_word)(a0) + 1568) = (unsigned char)0;
    }
    return;
}

/* Swing_DLL.xex 0x88782188: loop_get u32@0x2c, u32@0x0, u32@0x10, u32@0x8, vcall, u32@0x10 */
ts4_word ts4_loop_get_u32_off2c_88782188(ts4_word a0)
{
    ts4_word lv10;
    ts4_word p14;
    ts4_word p15;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t18;
    ts4_word t25;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 8))))((ts4_word)t1, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t7 = *(ts4_word *)lbl_88D45B30;
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 32);
    t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 28);
    p17 = (ts4_word)0;
    if ((ts4_word)t8 != (ts4_word)t9) {
        p15 = (ts4_word)0;
        lv10 = (ts4_word)t9;
        do {
            t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
            if ((ts4_word)t6 == (ts4_word)t12) {
                p15 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv10) + 4));
                break;
            }
            p14 = (ts4_word)(lv10 + 8);
            lv10 = p14;
        } while ((ts4_word)t8 != (ts4_word)p14);
        p17 = (ts4_word)p15;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    fn_888877F8((ts4_word)p17, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t18) + 15412)), (ts4_word)(t18 + 12));
    ts4_loop_call_seq_u32_off3c34_88778C48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
    t25 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 15412))) + 0);
    if ((ts4_word)t25 == 0) {
        return 1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3905880064) | 13061);
    return 0;
}

/* Swing_DLL.xex 0x887849B0: call_seq lbl_880EE4A4, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88781450, lbl_880EE4B0, fn_88608590 */
ts4_word ts4_call_seq_lbl_880EE4A4_887849B0(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t33;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE4A4);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88781450((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE4B0);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_88781500((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE4C8);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_887816F0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE4E0);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_887811F0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE4FC);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88781140((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE514);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_887815F0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE528);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_887813A0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE53C);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_88780FE0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE550);
    loc50[0] = (ts4_word)t25;
    ts4_keyed_item_list_add_unique_887812A0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE564);
    loc50[0] = (ts4_word)t28;
    ts4_keyed_item_list_add_unique_88781090((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EE570);
    loc50[0] = (ts4_word)t31;
    t33 = ts4_keyed_item_list_add_unique_88781B68((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t33;
}

/* Swing_DLL.xex 0x8878C820: if_get ts4_if_call_seq_u32_lbl_88D459E4_8883F238, u32@0x850, u32@0x10, fn_88867E68, u32@0x0, u32@0x28 */
ts4_word ts4_if_get_ts4_if_call_seq_u32_lbl_88D459E4_8883F238_8878C820(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc80[128];
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t9;
    ts4_word t17;
    ts4_word t24;
    ts4_word t26;
    ts4_word t27;
    ts4_word t30;
    ts4_word t31;
    ts4_word t34;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 2128);
    fn_88867E68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)t2, (ts4_word)(ts4_word)&loc80[0], (ts4_word)512, (ts4_word)a1);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc54[0], (ts4_word)t1, (ts4_word)(ts4_word)&loc80[0], (ts4_word)1, (ts4_word)0);
    t8 = loc54[0];
    if ((ts4_word)t8 != 0) {
        t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 88))))((ts4_word)t9, (ts4_word)(ts4_word)&loc54[0]);
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc80[0]);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)(ts4_word)&loc58[0]);
        t17 = loc58[0];
        ts4_destroy_owned_object((ts4_word)t17);
    }
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc80[0]);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(ts4_word)&loc68[0], (ts4_word)3072, (ts4_word)a2, (ts4_word)0);
    t24 = loc68[0];
    ts4_destroy_owned_object((ts4_word)t24);
    t26 = loc50[0];
    t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 2132);
    memcpy((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t26) + 28)), (ts4_word)t27, (ts4_word)a2);
    t30 = loc50[0];
    t31 = *(ts4_word *)((char *)(ts4_word)(t30) + 4);
    t34 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t31) + 0))) + 88))))((ts4_word)t31, (ts4_word)(ts4_word)&loc50[0]);
    return t34;
}

/* Swing_DLL.xex 0x8878E6D0: if_addr lbl_880EEC38, fn_8862BE08, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_addr_lbl_880EEC38_8878E6D0(ts4_word a0)
{
    ts4_word loc58[3];
    ts4_word loc78[3];
    ts4_word loc50[2];
    ts4_word loc68[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    int t9;
    ts4_word t13;
    ts4_word t14;
    ts4_word t17;

    fn_8862BE08((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880EEC38);
    t2 = loc58[0];
    t3 = loc58[1];
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t3, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    fn_8862BE08((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)lbl_880EEC78);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t9 == 0) {
        loc50[0] = (ts4_word)((3610640384) | 55597);
        ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)t9);
    }
    fn_8862BE08((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)lbl_880ED610);
    t13 = loc68[0];
    t14 = loc68[1];
    t17 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 40))))((ts4_word)t13, (ts4_word)(ts4_word)&loc68[0], (ts4_word)t14, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(t17) + 0) = (unsigned char)1;
    return t17;
}

/* Swing_DLL.xex 0x8878FC70: loop_addr lbl_880D8300, fn_8862C0E8, fn_88923530, u32@0x0, u32@0x4, u8@0xd */
ts4_word ts4_loop_addr_lbl_880D8300_8878FC70(void)
{
    ts4_word p5;
    ts4_word p8;
    ts4_word lv9;
    ts4_word lv10;
    ts4_word p22;
    ts4_word p23;
    ts4_word p24;
    ts4_word p25;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    int t4;
    unsigned char t11;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t21;

    fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D8300);
    t2 = loc50[2];
    t3 = fn_88923530((ts4_word)t2, *(ts4_args3 *)&loc50[0], (ts4_word)((3630694400) | 12420));
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    p5 = (ts4_word)0;
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + t3);
    }
    p8 = (ts4_word)0;
    if ((int)t4 != -1) {
        p8 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(t3) + 4)) * 176) + t4) + t3);
    }
    p25 = (ts4_word)t3;
    if ((ts4_word)p5 != (ts4_word)p8) {
        lv9 = (ts4_word)t3;
        lv10 = (ts4_word)(p5 + 12);
        do {
            t11 = *(unsigned char *)((char *)(ts4_word)(lv10) + 13);
            p22 = (ts4_word)lv9;
            if ((ts4_word)t11 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(lv10) + 14)) != 0) {
                t14 = fn_882159B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv10) + 0)));
                t15 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
                t16 = *(ts4_word *)((char *)(ts4_word)(t14) + 0);
                *(ts4_word *)((char *)(ts4_word)(t14) + 32) = (ts4_word)t15;
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t16) + 12))))((ts4_word)t14);
                t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 0))))((ts4_word)t14, (ts4_word)1);
                p22 = (ts4_word)t21;
            }
            p23 = (ts4_word)p22;
            p24 = (ts4_word)(lv10 + 176);
            lv9 = p23;
            lv10 = p24;
        } while ((ts4_word)(p24 + -12) != (ts4_word)p8);
        p25 = (ts4_word)lv9;
    }
    return p25;
}

/* Swing_DLL.xex 0x88793A78: if_call_seq u32@0x50, lbl_880D85CC, fn_8862C0E8, fn_88923530, u32@0x50, u32@0x50 */
ts4_word ts4_if_call_seq_u32_off50_88793A78(ts4_word a0)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 == 0) {
        fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D85CC);
        t3 = loc50[2];
        t4 = fn_88923530((ts4_word)t3, *(ts4_args3 *)&loc50[0], (ts4_word)((4170514432) | 60593));
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)t4;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 80));
}

/* Swing_DLL.xex 0x88793D30: if_call_seq u32@0x70, u32@0x70, u32@0x8c, u32@0x88, fn_8878FA48, fn_88169350 */
void ts4_if_call_seq_u32_off70_88793D30(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t1 != (ts4_word)a1) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)a1;
        t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140);
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
        if ((int)(t2 - t3) != 0) {
            loc50[0] = (ts4_word)((3849912320) | 7316);
            fn_8878FA48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(a0 + 136), (ts4_word)(ts4_word)&loc50[0]);
            fn_88169350((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
            ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&a1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x887A2F78: if_set u32@0x18, fn_8877DF00, lbl_880EE068, u32@lbl_88D45B1C, u32@0x224, u32@0x0 */
ts4_word ts4_if_set_u32_off18_887A2F78(ts4_word a0)
{
    ts4_word p22;
    ts4_word loc50[4];
    ts4_word loc60[24];
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;
    ts4_word t21;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    fn_8877DF00();
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)(ts4_word)lbl_880EE068, (ts4_word)1, (ts4_word)0);
    t7 = loc50[0];
    p22 = (ts4_word)t6;
    if ((ts4_word)t7 != 0) {
        ts4_call_seq_fn_88617D88_8892AFF0((ts4_word)(ts4_word)&loc60[0]);
        t9 = loc50[0];
        ts4_if_get_u32_off0_8892FE20((ts4_word)(ts4_word)&loc60[0], (ts4_word)t9, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t11 = loc60[0];
        t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t11) + 76))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
        fn_887A2CD0((ts4_word)a0, (ts4_word)t13);
        fn_88929E70((ts4_word)(ts4_word)&loc60[0]);
        t16 = loc50[0];
        t17 = *(ts4_word *)((char *)(ts4_word)(t16) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 0))) + 88))))((ts4_word)t17, (ts4_word)(ts4_word)&loc50[0]);
        t21 = ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(ts4_word)&loc60[0]);
        p22 = (ts4_word)t21;
    }
    return p22;
}

/* Swing_DLL.xex 0x887A3848: loop_call_seq u8@0x4c, u8@0x4c, fn_8879FF30, u32@lbl_88D45894, fn_88987938, u32@lbl_88D459E0 */
ts4_word ts4_loop_call_seq_u8_off4c_887A3848(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv11;
    ts4_word p16;
    ts4_word p17;
    ts4_word p19;
    ts4_word p21;
    unsigned char t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t14;
    int t15;
    ts4_word t20;

    p21 = (ts4_word)a0;
    if ((ts4_word)a1 == (ts4_word)((2801139712) | 59735) || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 76)) != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 76);
        if ((ts4_word)t2 != 0) {
            fn_8879FF30((ts4_word)a0, (ts4_word)a2, (ts4_word)1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((2801139712) | 59735));
            t4 = *(ts4_word *)lbl_88D45894;
            if ((ts4_word)t4 != 0) {
                fn_88987938((ts4_word)t4, (ts4_word)1);
            }
        }
        t8 = *(ts4_word *)lbl_88D459E0;
        t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 36);
        t10 = *(ts4_word *)((char *)(ts4_word)(t8) + 32);
        p19 = (ts4_word)0;
        if ((ts4_word)t10 != (ts4_word)t9) {
            p17 = (ts4_word)0;
            lv11 = (ts4_word)t10;
            do {
                t14 = *(ts4_word *)((char *)(ts4_word)(lv11) + 0);
                t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 384);
                if ((int)t15 == (int)a2) {
                    p17 = (ts4_word)t14;
                    break;
                }
                p16 = (ts4_word)(lv11 + 4);
                lv11 = p16;
            } while ((ts4_word)p16 != (ts4_word)t9);
            p19 = (ts4_word)p17;
        }
        t20 = ts4_if_get_fn_8883F238_88848698((ts4_word)p19, (ts4_word)0);
        p21 = (ts4_word)t20;
    }
    return p21;
}

/* Swing_DLL.xex 0x887A5C88: if_call_seq u32@lbl_88D459E8, u32@0x44, u32@0x1c, u32@0x34, u32@0x0, ts4_lua_pushnumber_888240B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D459E8_887A5C88(ts4_word a0)
{
    ts4_word p5;
    ts4_word t4;

    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 68))) + 28))) + 52);
    if ((ts4_word)t4 != (ts4_word)((3751936000) | 45041)) {
        p5 = (ts4_word)((490209280) | 27437);
    } else {
        p5 = (ts4_word)((3015835648) | 8748);
    }
    ts4_lua_pushnumber_888240B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), ((double)((ts4_s64)(ts4_word)p5)));
    return 1;
}

/* Swing_DLL.xex 0x887C7A60: call_seq ts4_tailcall_fn_88565410_885654D8 */
ts4_word ts4_call_seq_ts4_tailcall_fn_88565410_885654D8_887C7A60(ts4_word a0, ...)
{
    ts4_va_list ap;
    ts4_word loc60[514];
    ts4_word t1;

    TS4_VA_START(ap, a0);
    t1 = ts4_tailcall_fn_88565410_885654D8((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)ap);
    return t1;
}

/* Swing_DLL.xex 0x887CB7B0: call_seq lbl_880EA35C, u32@0x4, u32@0x8, u32@0x0, u32@0x14, u32@0xc */
ts4_word ts4_call_seq_lbl_880EA35C_887CB7B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA35C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    t1 = fn_8857B848((ts4_word)a2, (ts4_word)(2147483648), (ts4_word)0, (ts4_word)0, (ts4_word)3, (ts4_word)128, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x887CD990: get u32@0x0, u32@0x38, vcall, u32@0x4c, vcall */
void ts4_get_u32_off0_887CD990(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 76))))((ts4_word)a0, (ts4_word)(((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 56))))((ts4_word)a0)), (ts4_word)0, (ts4_word)a2);
    return;
}

/* Swing_DLL.xex 0x887D2740: if_get u32@0x0, u32@0x28, u32@0x0, u32@0x0, u32@0x28, vcall */
void ts4_if_get_u32_off0_887D2740(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p11;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t7;
    ts4_word t9;

    (void)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t2 != (ts4_word)((853999616) | 58594)) {
        loc50[0] = (ts4_word)((3525181440) | 63726);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t7 == (ts4_word)((853999616) | 58594)) {
        t9 = *(volatile ts4_word *)lbl_88D45930;
        p11 = (ts4_word)0;
        if ((ts4_word)t9 != 0 && (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(t9) + 321)) != 0) {
            p11 = (ts4_word)1;
        }
        if ((ts4_word)(p11 & 0xff) == 0) {
            loc54[0] = (ts4_word)((3525181440) | 63726);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0, (ts4_word)(ts4_word)&loc54[0], (ts4_word)1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x887D8F28: call_seq lbl_880E4D50, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_887D7260, lbl_880E4D64, fn_88608590 */
ts4_word ts4_call_seq_lbl_880E4D50_887D8F28(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t34;
    ts4_word t36;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4D50);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_887D7260((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4D64);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_887D63C8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4D7C);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_887D6318((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4D94);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_887D5FA8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4DAC);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_887D5EF8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4DC0);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_887D6108((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4DD8);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_887D6058((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4DEC);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_887D6268((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4E04);
    loc50[0] = (ts4_word)t25;
    ts4_keyed_item_list_add_unique_887D61B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4E18);
    loc50[0] = (ts4_word)t28;
    ts4_keyed_item_list_add_unique_887D5B20((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4E2C);
    loc50[0] = (ts4_word)t31;
    ts4_keyed_item_list_add_unique_887D6478((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t34 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E4E40);
    loc50[0] = (ts4_word)t34;
    t36 = ts4_keyed_item_list_add_unique_887D7310((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t36;
}

/* Swing_DLL.xex 0x887DA398: if_get fn_88627EC0, ts4_memset, ts4_memset, ts4_find_service, u32@0x0, u32@0x4c */
ts4_word ts4_if_get_fn_88627EC0_887DA398(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p29;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t13;
    ts4_word t15;
    ts4_word t18;
    ts4_word t20;
    ts4_word t23;
    ts4_word t25;
    ts4_word t28;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    ts4_memset((ts4_word)(a0 + 28), (ts4_word)0, (ts4_word)4);
    ts4_memset((ts4_word)(a0 + 32), (ts4_word)0, (ts4_word)4);
    t5 = ts4_find_service((ts4_word)((2756837376) | 15079));
    if ((ts4_word)t5 != 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 76))))((ts4_word)t5, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t8;
    }
    t10 = ts4_find_service((ts4_word)((2354708480) | 18722));
    if ((ts4_word)t10 != 0) {
        t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 76))))((ts4_word)t10, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t13;
    }
    t15 = ts4_find_service((ts4_word)((2055471104) | 43325));
    if ((ts4_word)t15 != 0) {
        t18 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 76))))((ts4_word)t15, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)t18;
    }
    t20 = ts4_find_service((ts4_word)((3259957248) | 60588));
    if ((ts4_word)t20 != 0) {
        t23 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 76))))((ts4_word)t20, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t23;
    }
    t25 = ts4_find_service((ts4_word)((1915092992) | 31797));
    p29 = (ts4_word)t25;
    if ((ts4_word)t25 != 0) {
        t28 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t25) + 0))) + 76))))((ts4_word)t25, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t28;
        p29 = (ts4_word)t28;
    }
    return p29;
}

/* Swing_DLL.xex 0x887DCD08: if_call_seq fn_881898E8, ts4_if_call_seq_fn_887DACE0_887DB6B0, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_fn_881898E8_887DCD08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_881898E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&a1);
    t2 = ts4_if_call_seq_fn_887DACE0_887DB6B0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    t3 = loc50[0];
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    return t2;
}

/* Swing_DLL.xex 0x887ED750: if_call_seq fn_88627EC0, fn_88923530, u32@0x1c, ts4_find_service, u32@0x1c, ts4_find_service */
void ts4_if_call_seq_fn_88627EC0_887ED750(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2165964800) | 25373));
    t5 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 28)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t5;
    t6 = ts4_find_service((ts4_word)((2218131456) | 51023));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t6;
    t7 = ts4_find_service((ts4_word)((587202560) | 1299));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t7;
    t8 = ts4_find_service((ts4_word)((3769106432) | 21937));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t8;
    t10 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t10;
    t11 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t11 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t11) + 16));
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887EFDB8: if_get u32@lbl_88D26FCC, ts4_if_get_u32_off0_884C6B58, fn_8841CBF8, lbl_880DF64C, ts4_if_get_u32_off8_8841D058, lbl_880E44CC */
ts4_word ts4_if_get_u32_lbl_88D26FCC_887EFDB8(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word loc60[130];
    ts4_word loc50[4];
    int t2;
    ts4_word t5;
    ts4_word t9;

    (void)a0;
    t2 = ts4_if_get_u32_off0_884C6B58((ts4_word)a1, (ts4_word)(*(ts4_word *)lbl_88D26FCC));
    p10 = (ts4_word)t2;
    if ((int)t2 != 0) {
        fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
        ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880DF64C);
        t5 = *(ts4_word *)lbl_88CAD340;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)1, (ts4_word)0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E44CC, (ts4_word)430);
        t9 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x887EFED8: loop_get u32@0x50, u32@0x0, u32@0x0, u32@0x50, u32@0x0, u32@0x4 */
void ts4_loop_get_u32_off50_887EFED8(ts4_word a0)
{
    ts4_word p4;
    ts4_word lv5;
    ts4_word p10;
    ts4_word p14;
    ts4_word t1;
    int t3;
    ts4_word t6;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        p4 = (ts4_word)0;
        if ((int)t3 != -1) {
            p4 = (ts4_word)(t3 + t1);
        }
        lv5 = (ts4_word)p4;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
            t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
            p10 = (ts4_word)0;
            if ((int)t7 != -1) {
                p10 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t6) + 4)) << 6) + t7) + t6);
            }
            if ((ts4_word)lv5 == (ts4_word)p10) {
                *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)0;
                return;
            }
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)lv5);
            p14 = (ts4_word)(lv5 + 64);
            lv5 = p14;
        } while (1);
    }
    return;
}

/* Swing_DLL.xex 0x887F7B18: set u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_set_u32_off0_887F7B18(ts4_word a0, ts4_word a1)
{
    switch ((ts4_word)((a1 & 0xff))) {
        case 0:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3440050176) | 8751);
        return;
        case 1:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2511470592) | 37527);
        return;
        case 2:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1161297920) | 45556);
        return;
        case 3:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3227451392) | 42662);
        return;
        case 4:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3849912320) | 7316);
        return;
        case 5:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((1661206528) | 21791);
        return;
        case 6:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((791478272) | 381);
        return;
        default:
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
        return;
    }
}

/* Swing_DLL.xex 0x887F8190: get u32@0x10, u32@0x0 */
ts4_word ts4_get_u32_off10_887F8190(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return (((t1 - (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) == 0) ? a0 : 0);
}

/* Swing_DLL.xex 0x887F9C40: if_call_seq u32@0x8, u32@0x4, u32@0x10, fn_881784B0, u64@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_887F9C40(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    loc50[1] = (ts4_word)a0;
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_u64 *)((char *)(ts4_word)(t2) + 0) = (ts4_u64)*(ts4_u64 *)((char *)loc50 + 0);
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 8);
        return a1;
    }
    t4 = fn_881784B0((ts4_word)a1, (ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x88803A30: call_seq lbl_880E3588, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88803610, lbl_880E3598, fn_88608590 */
ts4_word ts4_call_seq_lbl_880E3588_88803A30(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t24;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E3588);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88803610((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E3598);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_888034E8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E35AC);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_88803820((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E35C8);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_88803438((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E35E4);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88803770((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E3604);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_888036C0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E3614);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_888038D0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E3620);
    loc50[0] = (ts4_word)t22;
    t24 = ts4_keyed_item_list_add_unique_8883E498((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t24;
}

/* Swing_DLL.xex 0x888072E0: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, fn_881B1CF0, ts4_if_call_seq_u32_off8_88837608 */
ts4_word ts4_if_call_seq_u32_off0_888072E0(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t13;
    ts4_word t14;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc50[1] = (ts4_word)2;
        t5 = fn_881B1CF0((ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)(t5 & 0xff) != 0) {
            loc50[0] = (ts4_word)t2;
            loc58[0] = (ts4_word)0;
            loc58[2] = (ts4_word)0;
            loc58[1] = (ts4_word)((983040) | 65535);
            loc50[1] = (ts4_word)1;
            t6 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
            t7 = fn_888063B0((ts4_word)t6, (ts4_word)(ts4_word)&loc58[0]);
            if ((ts4_word)(t7 & 0xff) != 0) {
                t9 = loc58[0];
                p11 = (ts4_word)0;
                if ((ts4_word)t9 == 0 || (ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535)) {
                    p11 = (ts4_word)1;
                }
                if ((ts4_word)(p11 & 0xff) == 0) {
                    t13 = lib3_lua_tostring_88822888((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)2);
                    t14 = fn_88608590((ts4_word)0, (ts4_word)t13);
                    loc50[0] = (ts4_word)t14;
                    ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
                }
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x888073C8: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, u32@0x0, lib3_lua_type_88822738 */
ts4_word ts4_if_call_seq_u32_off0_888073C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    int t6;
    ts4_word t7;
    ts4_word t8;
    double t10;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        t6 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)2);
        if ((int)t6 == 3) {
            loc50[0] = (ts4_word)t2;
            loc58[0] = (ts4_word)0;
            loc58[2] = (ts4_word)0;
            loc58[1] = (ts4_word)((983040) | 65535);
            loc50[1] = (ts4_word)1;
            t7 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
            t8 = fn_888063B0((ts4_word)t7, (ts4_word)(ts4_word)&loc58[0]);
            if ((ts4_word)(t8 & 0xff) != 0) {
                t10 = ts4_lua_tonumber_88822420((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)2);
                *(float *)((char *)loc50 + 0) = ((float)t10);
                ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88807F00: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, ts4_if_call_seq_u32_off8_88837608, fn_88806428 */
ts4_word ts4_if_call_seq_u32_off0_88807F00(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc58[0] = (ts4_word)0;
        loc58[2] = (ts4_word)0;
        loc58[1] = (ts4_word)((983040) | 65535);
        loc50[1] = (ts4_word)1;
        t5 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
        t6 = fn_88806428((ts4_word)t5, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t6 & 0xff) != 0) {
            fn_8860A938((ts4_word)(ts4_word)&loc58[0]);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88808058: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, ts4_if_call_seq_u32_off8_88837608, fn_88806428 */
ts4_word ts4_if_call_seq_u32_off0_88808058(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc58[0] = (ts4_word)0;
        loc58[2] = (ts4_word)0;
        loc58[1] = (ts4_word)((983040) | 65535);
        loc50[1] = (ts4_word)1;
        t5 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
        t6 = fn_88806428((ts4_word)t5, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t6 & 0xff) != 0) {
            fn_8860A9E0((ts4_word)(ts4_word)&loc58[0]);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x888081B0: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, ts4_if_call_seq_u32_off8_88837608, fn_88806428 */
ts4_word ts4_if_call_seq_u32_off0_888081B0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc58[0] = (ts4_word)0;
        loc58[2] = (ts4_word)0;
        loc58[1] = (ts4_word)((983040) | 65535);
        loc50[1] = (ts4_word)1;
        t5 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
        t6 = fn_88806428((ts4_word)t5, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t6 & 0xff) != 0) {
            fn_8860AB08((ts4_word)(ts4_word)&loc58[0]);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x888092A8: if_get u32@0x8, u32@0xc, u32@0x0, lib3_lua_type_88822738, ts4_if_call_seq_u32_off8_88837608, fn_88805368 */
ts4_word ts4_if_get_u32_off8_888092A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p13;
    ts4_word p14;
    ts4_word loc90[10];
    ts4_word loc58[3];
    ts4_word loc70[8];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
    if ((int)t4 != 5) {
        p14 = (ts4_word)0;
    } else {
        t5 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc90[0], (ts4_word)(a2 + 8));
        t6 = fn_88805368((ts4_word)t5);
        if ((ts4_word)t6 == 0) {
            p13 = (ts4_word)0;
        } else {
            loc70[0] = (ts4_word)0;
            loc70[1] = (ts4_word)0;
            loc70[6] = (ts4_word)0;
            loc70[2] = (ts4_word)0;
            loc70[4] = (ts4_word)0;
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 40))))((ts4_word)(ts4_word)&loc58[0], (ts4_word)t6);
            fn_881ABB20((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)&loc70[0]);
            ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0]);
            fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
            p13 = (ts4_word)1;
        }
        p14 = (ts4_word)p13;
    }
    return p14;
}

/* Swing_DLL.xex 0x88834C60: call_seq ts4_tailcall_fn_88565410_885654D8, u32@0x4, fn_88566048 */
ts4_word ts4_call_seq_ts4_tailcall_fn_88565410_885654D8_88834C60(ts4_word a0, ts4_word a1, ...)
{
    ts4_va_list ap;
    ts4_word loc60[200];
    ts4_word t3;

    TS4_VA_START(ap, a1);
    ts4_tailcall_fn_88565410_885654D8((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)ap);
    t3 = fn_88566048((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t3;
}

/* Swing_DLL.xex 0x88836040: if_addr lbl_880E17D8, u32@lbl_88C6A10C, u32@lbl_88D459EC, vcall, ts4_call_seq_u32_off14_88835FC8 */
ts4_word ts4_if_addr_lbl_880E17D8_88836040(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88C6A10C;
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)lbl_88D459EC), (ts4_word)0, (ts4_word)0, (ts4_word)28, (ts4_word)(ts4_word)lbl_880E17D8, (ts4_word)0);
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        ts4_call_seq_u32_off14_88835FC8((ts4_word)t3, (ts4_word)a0);
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x88836190: get  */
ts4_word ts4_get_88836190(ts4_word a0)
{
    return (ts4_word)((*(double *)((char *)(ts4_word)(a0) + 16)));
}

/* Swing_DLL.xex 0x8883C128: get u32@0x0, u32@0x6c, u32@0x0, ts4_lua_tonumber_88822420, u32@lbl_88D459E8, u32@0x1c */
ts4_word ts4_get_u32_off0_8883C128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    float t4;
    ts4_word t5;

    (void)a0;
    t4 = ts4_lua_tonumber_88822420((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108))) + 0)), (ts4_word)1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    t5 = *(ts4_word *)lbl_88D459E8;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 28))) + 8))))((ts4_word)(t5 + 28), (ts4_word)(int)(t4), (ts4_word)1);
    return 0;
}

/* Swing_DLL.xex 0x8883C2B0: loop_get u32@0x0, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4_loop_get_u32_off0_8883C2B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word lv6;
    ts4_word p9;
    int t1;
    ts4_word t2;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((int)t1 != -1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p4 = (ts4_word)((((t2 + (t2 << 1)) << 2) + t1) + a0);
    }
    p5 = (ts4_word)0;
    if ((int)t1 != -1) {
        p5 = (ts4_word)(t1 + a0);
    }
    lv6 = (ts4_word)p5;
    while ((ts4_word)lv6 != (ts4_word)p4) {
        t8 = *(ts4_word *)((char *)(ts4_word)(lv6) + 4);
        if ((ts4_word)t8 == (ts4_word)a1) {
            return lv6;
        }
        p9 = (ts4_word)(lv6 + 12);
        lv6 = p9;
    }
    return 0;
}

/* Swing_DLL.xex 0x8883CB50: loop_get u32@lbl_88D459E0, u32@0x24, u32@0x20, u32@0x0, u32@0x180, u32@0x0 */
ts4_word ts4_loop_get_u32_lbl_88D459E0_8883CB50(int a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word p10;
    ts4_word p13;
    ts4_word p26;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    int t8;
    ts4_word t15;
    ts4_word t18;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D459E0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    p13 = (ts4_word)0;
    if ((ts4_word)t3 != (ts4_word)t2) {
        p10 = (ts4_word)0;
        lv4 = (ts4_word)t3;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 384);
            if ((int)t8 == (int)a0) {
                p10 = (ts4_word)t7;
                break;
            }
            p9 = (ts4_word)(lv4 + 4);
            lv4 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        p13 = (ts4_word)p10;
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(p13) + 268);
    p26 = (ts4_word)t15;
    if ((ts4_word)t15 != 0) {
        t18 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 76))))((ts4_word)t15, (ts4_word)0);
        t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 64);
        if ((ts4_word)t19 != 0) {
            fn_889254C8((ts4_word)(t18 + 52), (ts4_word)1);
        }
        t22 = *(ts4_word *)((char *)(ts4_word)(t18) + 3240);
        if ((ts4_word)t22 != 0) {
            fn_889254C8((ts4_word)(t18 + 3228), (ts4_word)1);
        }
        t25 = fn_889254C8((ts4_word)(p13 + 256), (ts4_word)1);
        p26 = (ts4_word)t25;
    }
    return p26;
}

/* Swing_DLL.xex 0x8883CC20: loop_get u32@lbl_88D459E0, u32@0x24, u32@0x20, u32@0x0, u32@0x180, u32@0x0 */
ts4_word ts4_loop_get_u32_lbl_88D459E0_8883CC20(int a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    int t8;
    ts4_word t15;

    (void)a1;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D459E0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    p11 = (ts4_word)a7;
    p13 = (ts4_word)a4;
    p14 = (ts4_word)0;
    if ((ts4_word)t3 != (ts4_word)t2) {
        p10 = (ts4_word)0;
        lv4 = (ts4_word)t3;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 384);
            if ((int)t8 == (int)a0) {
                p10 = (ts4_word)t7;
                break;
            }
            p9 = (ts4_word)(lv4 + 4);
            lv4 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        p11 = (ts4_word)t7;
        p13 = (ts4_word)t8;
        p14 = (ts4_word)p10;
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(p14) + 332);
    if ((ts4_word)t15 == 0) {
        return a0;
    }
    return fn_889254C8((ts4_word)(p14 + 320), (ts4_word)1, (ts4_word)a2, (ts4_word)a3, (ts4_word)p13, (ts4_word)p14, (ts4_word)t2, (ts4_word)p11);
}

/* Swing_DLL.xex 0x8883E990: if_call_seq u32@0xc, ts4_find_record_by_key_881AD158, ts4_find_record_by_key_881AD158, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_offc_8883E990(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
    t2 = ts4_find_record_by_key_881AD158((ts4_word)t1, (ts4_word)(ts4_word)&a2);
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 == 0) {
        loc50[0] = (ts4_word)((1761411072) | 46104);
        t3 = ts4_find_record_by_key_881AD158((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p4 = (ts4_word)t3;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(p4) + 4));
    return a0;
}

/* Swing_DLL.xex 0x8883EA00: if_call_seq u32@0x8, ts4_find_record_by_key_881ACBA8, ts4_find_record_by_key_881ACBA8, u32@0x10, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off8_8883EA00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = ts4_find_record_by_key_881ACBA8((ts4_word)t1, (ts4_word)(ts4_word)&a2);
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 == 0) {
        loc50[0] = (ts4_word)((91947008) | 19160);
        t3 = ts4_find_record_by_key_881ACBA8((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p4 = (ts4_word)t3;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(p4) + 16));
    return a0;
}

/* Swing_DLL.xex 0x8883EDE8: call_seq u32@0x24, ts4_find_record_by_key_881AC778, u32@0x4, u32@0x4 */
ts4_word ts4_call_seq_u32_off24_8883EDE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ts4_find_record_by_key_881AC778((ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)) + 116), (ts4_word)(ts4_word)&a1);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 4)) + a2);
    return t2;
}

/* Swing_DLL.xex 0x8883EEB0: call_seq u32@0x24, fn_881AC7D0 */
float ts4_call_seq_u32_off24_8883EEB0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = fn_881AC7D0((ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)) + 116), (ts4_word)(ts4_word)&a1);
    return (*(float *)((char *)(ts4_word)(t2) + 4));
}

/* Swing_DLL.xex 0x8884FDE8: loop_call_seq u32@lbl_88D459E0, u32@0x24, u32@0x20, u32@0x0, u32@0x180, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_lbl_88D459E0_8884FDE8(int a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word p13;
    ts4_word p14;
    ts4_word loc60[4];
    ts4_word loc50[4];
    ts4_word loc70[128];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    int t8;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t21;
    ts4_word t23;
    ts4_word t24;

    (void)a1;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D459E0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    p11 = (ts4_word)a7;
    p13 = (ts4_word)a4;
    p14 = (ts4_word)0;
    if ((ts4_word)t3 != (ts4_word)t2) {
        p10 = (ts4_word)0;
        lv4 = (ts4_word)t3;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 384);
            if ((int)t8 == (int)a0) {
                p10 = (ts4_word)t7;
                break;
            }
            p9 = (ts4_word)(lv4 + 4);
            lv4 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        p11 = (ts4_word)t7;
        p13 = (ts4_word)t8;
        p14 = (ts4_word)p10;
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(p14) + 392);
    t16 = fn_88923380((ts4_word)(ts4_word)&loc60[0], (ts4_word)(p14 + 320), (ts4_word)a2, (ts4_word)a3, (ts4_word)p13, (ts4_word)p14, (ts4_word)t2, (ts4_word)p11);
    t17 = *(ts4_word *)((char *)(ts4_word)(t16) + 8);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88867E68((ts4_word)a0, (ts4_word)t15, (ts4_word)(ts4_word)&loc70[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880E13DC);
    fn_8816CAA0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0]);
    t21 = loc50[0];
    ts4_if_get_fn_8883F238_88844310((ts4_word)t17, (ts4_word)t21);
    t23 = loc50[0];
    t24 = ts4_destroy_owned_object((ts4_word)t23);
    return t24;
}

/* Swing_DLL.xex 0x88868008: loop_get u32@lbl_88D45B1C, u32@0x234, u32@0x38, u32@0x4, u32@0x0, u8@0x19 */
ts4_word ts4_loop_get_u32_lbl_88D45B1C_88868008(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word c5;
    ts4_word lv6;
    ts4_word lv7;
    ts4_word p9;
    ts4_word p10;
    ts4_word p12;
    ts4_word p13;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;

    (void)a0;
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564))) + 56);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
    p12 = (ts4_word)a5;
    p13 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        c5 = (ts4_word)t4;
        lv6 = (ts4_word)0;
        lv7 = (ts4_word)t4;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
            *(unsigned char *)((char *)(ts4_word)(((t8 + lv6) + t3)) + 25) = (unsigned char)0;
            p9 = (ts4_word)(lv6 + 176);
            p10 = (ts4_word)((t8 + lv6) + t3);
            lv6 = p9;
            lv7 = p10;
        } while (--c5 != 0);
        p12 = (ts4_word)0;
        p13 = (ts4_word)lv7;
    }
    return fn_888C7AF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A08)) + 28)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)p12, (ts4_word)p13, (ts4_word)t3);
}

/* Swing_DLL.xex 0x8886EEB8: if_call_seq fn_88627EC0, fn_88923530, u32@lbl_88D459F4, fn_88803198, u32@0x1c, u32@0x3c */
ts4_word ts4_if_call_seq_fn_88627EC0_8886EEB8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[8];
    ts4_word loc70[8];
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t14;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2407989248) | 28388));
    t5 = fn_88803198((ts4_word)(*(ts4_word *)lbl_88D459F4), (ts4_word)(t3 + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t5;
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 60);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t6;
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
    loc50[2] = (ts4_word)0;
    loc50[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc50[0], (ts4_word)t6, (ts4_word)(t7 + 72));
    fn_88837B00((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E04C4);
    fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    t11 = *(ts4_word *)((char *)(ts4_word)(t3) + 32);
    if ((ts4_word)t11 > 0) {
        fn_88866030((ts4_word)a0, (ts4_word)(t3 + 28));
    }
    t14 = fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    return t14;
}

/* Swing_DLL.xex 0x88884520: loop_addr lbl_88D3EB60, u32@0x0, u32@0x0, u32@0x0, u32@0x4, ts4_if_get_u32_lbl_88C32048_8857A1E0 */
ts4_word ts4_loop_addr_lbl_88D3EB60_88884520(ts4_word a0)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word t3;

    lv1 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        if ((ts4_word)a0 == (ts4_word)t3) {
            *(ts4_word *)((char *)(ts4_word)(lv1) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(lv1) + 4) = (ts4_word)0;
            break;
        }
        p4 = (ts4_word)(lv1 + 520);
        lv1 = p4;
    } while ((ts4_word)p4 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    return ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88884910: if_get u32@0x1c, u32@0x0, u32@0x4, u32@0x0, u32@0x58 */
ts4_word ts4_if_get_u32_off1c_88884910(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 88))))((ts4_word)t3, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88884FD0: loop_call_seq u32@0x0, ts4_resume_thread, u32@0x4, u8@0xc, ts4_if_call_seq_NtSetEvent_8857C1F8, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off0_88884FD0(ts4_word a0)
{
    ts4_word lv10;
    ts4_word p13;
    ts4_word t3;
    ts4_word t9;
    ts4_word t12;
    ts4_word t14;

    ts4_resume_thread((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
    ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)t3);
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)-1);
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    lv10 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
        if ((ts4_word)t9 == (ts4_word)t12) {
            *(ts4_word *)((char *)(ts4_word)(lv10) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(lv10) + 4) = (ts4_word)0;
            break;
        }
        p13 = (ts4_word)(lv10 + 520);
        lv10 = p13;
    } while ((ts4_word)p13 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    t14 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t9);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return t14;
}

/* Swing_DLL.xex 0x888862A0: loop_get u32@0x14f4, u32@0x4, vcall, u8@0x14, u8@0x14, u8@0x14 */
ts4_word ts4_loop_get_u32_off14f4_888862A0(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p7;
    ts4_word p8;
    ts4_word p10;
    unsigned char t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5364))) + 4))))((ts4_word)(a0 + 5364));
    p10 = (ts4_word)0;
    if ((ts4_word)(a0 + 5364) != (ts4_word)(a0 + 5340)) {
        p8 = (ts4_word)0;
        lv4 = (ts4_word)(a0 + 5340);
        do {
            t6 = *(unsigned char *)((char *)(ts4_word)(lv4) + 20);
            if ((ts4_word)t6 == 0) {
                *(unsigned char *)((char *)(ts4_word)(lv4) + 20) = (unsigned char)1;
                p8 = (ts4_word)lv4;
                break;
            }
            p7 = (ts4_word)(lv4 + 24);
            lv4 = p7;
        } while ((ts4_word)(a0 + 5364) != (ts4_word)p7);
        p10 = (ts4_word)p8;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 5364)) + 0))) + 8))))((ts4_word)(a0 + 5364));
    return p10;
}

/* Swing_DLL.xex 0x88888338: call_seq lbl_880DF0F0, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88887D50, lbl_880DF104, fn_88608590 */
ts4_word ts4_call_seq_lbl_880DF0F0_88888338(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t34;
    ts4_word t37;
    ts4_word t39;
    ts4_word t40;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF0F0);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88887D50((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF104);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_88887D50((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF114);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_88623CE0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF128);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_88623400((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF138);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88623E40((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF150);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_88887B30((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF168);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_88622B10((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF17C);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_88621EA0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF190);
    loc50[0] = (ts4_word)t25;
    ts4_keyed_item_list_add_unique_88878FA0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF1A0);
    loc50[0] = (ts4_word)t28;
    ts4_keyed_item_list_add_unique_88639BD8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF1B0);
    loc50[0] = (ts4_word)t31;
    ts4_keyed_item_list_add_unique_888880B0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t34 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF1C4);
    loc50[0] = (ts4_word)t34;
    ts4_keyed_item_list_add_unique_88887EB0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t37 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF1D8);
    loc50[0] = (ts4_word)t37;
    t39 = ts4_keyed_item_list_add_unique_88888000((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t40 = ts4_if_get_u32_lbl_88D45B1C_88885C18((ts4_word)t39);
    return t40;
}

/* Swing_DLL.xex 0x88888598: call_seq fn_88627EC0, fn_88923530, u32@0x1c, fn_888866E8, u8@0x30 */
ts4_word ts4_call_seq_fn_88627EC0_88888598(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2724331520) | 38299));
    t5 = fn_888866E8((ts4_word)(a0 + 28), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 28)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    return t5;
}

/* Swing_DLL.xex 0x88890AE0: if_call_seq u32@0x8, u32@0x8, u32@0x4, fn_88189E18, u64@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88890AE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    t2 = *(ts4_word *)((char *)(ts4_word)((((a3 + (a3 << 1)) << 2) + t1)) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)((((a3 + (a3 << 1)) << 2) + t1)) + 4);
    if ((ts4_word)t3 != (ts4_word)t2) {
        if ((ts4_word)t3 != 0) {
            *(ts4_u64 *)((char *)(ts4_word)(t3) + 0) = (ts4_u64)*(ts4_u64 *)((char *)loc50 + 0);
        }
        *(ts4_word *)((char *)(ts4_word)((((a3 + (a3 << 1)) << 2) + t1)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((((a3 + (a3 << 1)) << 2) + t1)) + 4)) + 8);
        return (((a3 + (a3 << 1)) << 2) + t1);
    }
    t4 = fn_88189E18((ts4_word)(((a3 + (a3 << 1)) << 2) + t1), (ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x888A7320: if_call_seq u32@0x90, fn_888A4630, u32@0x1cc, u32@0x1cc, u32@0x90, ts4_if_call_seq_u32_off90_888A8198 */
ts4_word ts4_if_call_seq_u32_off90_888A7320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p9;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t10;
    ts4_word t6;
    int t7;
    ts4_word t8;

    t2 = fn_888A4630((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 144)), (ts4_word)(ts4_word)&a1, (ts4_word)a2, (ts4_word)a3);
    t3 = a1;
    if ((ts4_word)t3 != 0) {
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 460);
        if ((ts4_word)t5 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)ts4_if_call_seq_u32_off90_888A70B0;
            t10 = ts4_if_call_seq_u32_off90_888A70B0((ts4_word)a0, (ts4_word)t3, (ts4_word)a2, (ts4_word)a3);
            return t10;
        }
        t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(ts4_word)ts4_if_call_seq_u32_off90_888A8198;
        t7 = fn_888A73D8((ts4_word)a0, (ts4_word)0, (ts4_word)t6, (ts4_word)t3, (ts4_word)a2, (ts4_word)a3);
        p9 = (ts4_word)t7;
        if ((int)t7 == 0) {
            t8 = fn_888A4B00((ts4_word)a0);
            p9 = (ts4_word)((t8 & 0xff) == 0);
        }
        return p9;
    }
    return t2;
}

/* Swing_DLL.xex 0x888AA8D0: if_call_seq fn_888AA6C0, u8@0xec, ts4_xml_set_implicit_context_888A5370, ts4_xml_parser_free_888A7110 */
ts4_word ts4_if_call_seq_fn_888AA6C0_888AA8D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = fn_888AA6C0((ts4_word)a0);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 236)) != 0) {
        t3 = ts4_xml_set_implicit_context_888A5370((ts4_word)t1);
        if ((ts4_word)(t3 & 0xff) == 0) {
            ts4_xml_parser_free_888A7110((ts4_word)t1);
            return 0;
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x888AF140: if_get u32@0x8, u32@0x0, u8@0x7c, u8@0x34, u8@0x35, u8@0x36 */
void ts4_if_get_u32_off8_888AF140(ts4_word a0)
{
    float pf13;
    int t1;
    ts4_word t3;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(volatile float *)((char *)(ts4_word)(a0) + 164) = (*(float *)lbl_8814B440);
    if ((int)t1 == 0) {
        return;
    }
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 4));
    *(volatile float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 8));
    *(volatile float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 12));
    *(volatile float *)((char *)(ts4_word)(a0) + 24) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 16));
    *(volatile float *)((char *)(ts4_word)(a0) + 28) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 20));
    *(volatile float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)((t3 + t1)) + 24));
    t10 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t10 != 0) {
        pf13 = (*(float *)((char *)(ts4_word)((t3 + t1)) + 44));
    } else {
        pf13 = (*(float *)((char *)(ts4_word)((t3 + t1)) + 40));
    }
    *(volatile float *)((char *)(ts4_word)(a0) + 48) = pf13;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 55) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888AF790: loop_get ts4_object_finalize, u32@0x2c, u32@0x28, fn_881705B0, u32@0x2c, u32@0x28 */
ts4_word ts4_loop_get_ts4_object_finalize_888AF790(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word lv7;
    ts4_word p36;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    int t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t22;
    ts4_word t24;
    ts4_word t27;
    ts4_word t28;
    ts4_word t29;
    ts4_word t39;

    ts4_object_finalize((ts4_word)a4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    fn_881705B0((ts4_word)a4, (ts4_word)((int)(t2 - (*(ts4_word *)((char *)(ts4_word)(a0) + 40))) >> 2));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    lv7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    while ((ts4_word)lv7 != (ts4_word)t5) {
        t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
        t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 8);
        if ((int)t9 != 0) {
            t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 44))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t8);
            t13 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            t14 = *(ts4_word *)((char *)(ts4_word)(t12) + 0);
            if ((ts4_word)t13 == (ts4_word)t14) {
                t15 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
                t18 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 40))))((ts4_word)(ts4_word)&loc54[0], (ts4_word)t15);
                t19 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
                t20 = *(ts4_word *)((char *)(ts4_word)(t18) + 0);
                if ((ts4_word)t19 == (ts4_word)t20) {
                    t22 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
                    if ((ts4_word)t22 != 0) {
                        t24 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
                        t27 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t24) + 0))) + 48))))((ts4_word)(ts4_word)&loc58[0], (ts4_word)t24);
                        t28 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
                        t29 = *(ts4_word *)((char *)(ts4_word)(t27) + 0);
                        if ((ts4_word)t28 == (ts4_word)t29) {
                            fn_881898E8((ts4_word)a4, (ts4_word)lv7);
                        }
                    } else {
                        fn_881898E8((ts4_word)a4, (ts4_word)lv7);
                    }
                }
            }
        }
        p36 = (ts4_word)(lv7 + 4);
        lv7 = p36;
    }
    t39 = *(ts4_word *)((char *)(ts4_word)(a4) + 4);
    return ((int)(t39 - (*(ts4_word *)((char *)(ts4_word)(a4) + 0))) >> 2);
}

/* Swing_DLL.xex 0x888B1488: if_get u32@0x0, u32@0x1c, vcall, u32@0x78, fn_888B12E8 */
ts4_word ts4_if_get_u32_off0_888B1488(ts4_word a0, float f1)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
        if ((ts4_word)t4 != 0) {
            *(float *)((char *)(ts4_word)(t4) + 0) = f1;
        }
    }
    t5 = fn_888B12E8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x888B83E8: call_seq lbl_880DBEC0, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_888B1DC8, lbl_880DBED4, fn_88608590 */
ts4_word ts4_call_seq_lbl_880DBEC0_888B83E8(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t33;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBEC0);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_888B1DC8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBED4);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_888B79B0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBEDC);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_888B5080((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBEFC);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_888B4FC8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBF20);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_888B4810((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBF4C);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_888B7250((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBF78);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_888B73D8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBFA0);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_888B1E78((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBFAC);
    loc50[0] = (ts4_word)t25;
    ts4_keyed_item_list_add_unique_888B42F8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBFB4);
    loc50[0] = (ts4_word)t28;
    ts4_keyed_item_list_add_unique_888B81F0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DBFC4);
    loc50[0] = (ts4_word)t31;
    t33 = ts4_keyed_item_list_add_unique_888B8138((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t33;
}

/* Swing_DLL.xex 0x888B8628: if_get u32@0x8, u32@0x84, u32@0x8c, u32@0x0, u32@0x98, u8@0x34 */
ts4_word ts4_if_get_u32_off8_888B8628(ts4_word a0, float f9, float f10, float f11, float f12, ts4_word a5, float f13, ts4_word a7)
{
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t16;
    ts4_word t9;
    ts4_word t47;
    ts4_word t53;
    float t54;

    (void)f9;
    (void)f10;
    (void)f11;
    (void)f12;
    (void)a5;
    (void)f13;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 == 0) {
        return a0;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t2 != 0) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140);
        if ((ts4_word)t3 != 0) {
            t5 = *(volatile ts4_word *)((char *)(ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0)) + t1)) + 152);
            if ((ts4_word)t5 >= 1) {
                if ((ts4_word)t5 == 1) {
                    *(volatile float *)((char *)(ts4_word)(a0) + 24) = (*(float *)((char *)(ts4_word)(t3) + 0));
                    *(volatile float *)((char *)(ts4_word)(a0) + 28) = (*(float *)((char *)(ts4_word)(t3) + 4));
                    *(volatile float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(t3) + 8));
                    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)1;
                    t16 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132);
                    *(volatile float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(t16) + 0));
                    *(volatile float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(t16) + 4));
                    *(volatile float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(t16) + 8));
                    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
                }
            } else {
                *(volatile float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(t2) + 0));
                *(volatile float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(t2) + 4));
                *(volatile float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(t2) + 8));
                *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
                t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140);
                *(volatile float *)((char *)(ts4_word)(a0) + 24) = (*(float *)((char *)(ts4_word)(t9) + 0));
                *(volatile float *)((char *)(ts4_word)(a0) + 28) = (*(float *)((char *)(ts4_word)(t9) + 4));
                *(volatile float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(t9) + 8));
                *(volatile unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)1;
            }
        }
    }
    t47 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t47 != 0) {
        *(volatile float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(t47) + 0));
        *(volatile float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(t47) + 4));
        *(volatile float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(t47) + 8));
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
    }
    t53 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t53 != 0) {
        t54 = *(float *)((char *)(ts4_word)(t53) + 0);
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
        *(volatile float *)((char *)(ts4_word)(a0) + 48) = t54;
    }
    return fn_888B7F08((ts4_word)a0);
}

/* Swing_DLL.xex 0x888BFAA0: fn  */
ts4_u64 ts4_fn_888BFAA0(ts4_word a0, ts4_word a1)
{
    return ((ts4_u64)((ts4_s64)((ts4_u64)1 << 63) >> ((ts4_s64)(ts4_word)(a1 - a0))) >> ((ts4_s64)(ts4_word)a0));
}

/* Swing_DLL.xex 0x888C05D0: if_get u32@lbl_88D45A60, u32@lbl_88D41F80, u32@0x0, u32@0x38 */
ts4_word ts4_if_get_u32_lbl_88D45A60_888C05D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45A60;
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t2 = *(ts4_word *)lbl_88D41F80;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 56))))((ts4_word)t2);
}

/* Swing_DLL.xex 0x888C07D0: if_get u32@0x84 */
void ts4_if_get_u32_off84_888C07D0(ts4_word a0, float f1)
{
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    ts4_word locm10[1];
    ts4_word t1;
    float t2;
    float t3;
    float t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t2 = *(float *)((char *)(ts4_word)(a0) + 140);
    t3 = *(float *)((char *)(ts4_word)(t1) + 20);
    *(float *)((char *)locm10 + 0) = (t3 + f1);
    if (!((t3 + f1) > t2)) {
        t4 = *(float *)((char *)(ts4_word)(a0) + 136);
        if ((t3 + f1) < t4) {
            *(float *)((char *)locm10 + 0) = t4;
        }
    } else {
        *(float *)((char *)locm10 + 0) = t2;
    }
    vv6 = *(__vector4 *)((ts4_word)((t1 + 16)));
    vv7 = __lvlx((void *)((ts4_word)&locm10[0]), 0);
    vv8 = __vrlimi(vv6, vv7, 4, 3);
    *(__vector4 *)((ts4_word)((t1 + 16))) = vv8;
    return;
}

/* Swing_DLL.xex 0x888C1888: if_get u8@0x5c, u32@0x28, u32@0x60, u32@0x4, u32@0x60, u32@0x44 */
void ts4_if_get_u8_off5c_888C1888(ts4_word a0)
{
    ts4_word t2;
    int t3;
    float t4;
    float t5;
    ts4_word t6;

    if ((ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 92)) == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t5 = *(float *)lbl_8814B910;
    t4 = *(float *)((char *)(ts4_word)(t2) + 276);
    if ((int)(int)((t4 + t5)) <= (int)t3) {
        return;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(int)((t4 + t5));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 68))) + 16))) + 112) = (ts4_word)(int)((t4 + t5));
    return;
}

/* Swing_DLL.xex 0x888C23F8: if_call_seq u32@0x1c, u32@0x0, u8@0x1a, ts4_xam_signin_info_8857A990, u64@0xa8 */
ts4_word ts4_if_call_seq_u32_off1c_888C23F8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word loc50[12];
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(unsigned char *)((char *)(ts4_word)(((((int)a1 * 176) + t2) + t1)) + 26);
    p5 = (ts4_word)a0;
    if ((ts4_word)t3 != 0) {
        t4 = ts4_xam_signin_info_8857A990((ts4_word)a1, (ts4_word)2, (ts4_word)(ts4_word)&loc50[0]);
        *(ts4_u64 *)((char *)(ts4_word)(((((int)a1 * 176) + t2) + t1)) + 168) = (ts4_u64)*(ts4_u64 *)((char *)loc50 + 0);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x888D6580: if_call_seq u32@0x4c, u32@0x48, lbl_880D082C, ts4_if_call_seq_fn_88582680_884F1D68, u32@0x4c, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off4c_888D6580(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    t1 = ts4_if_call_seq_fn_88582680_884F1D68((ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)(ts4_word)lbl_880D082C, (ts4_word)(a0 + 76), (ts4_word)0, (ts4_word)0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    p5 = (ts4_word)t1;
    if ((ts4_word)t2 != 0 && (ts4_word)t1 == 122) {
        t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t2, (ts4_word)1, (ts4_word)0, (ts4_word)2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)t4;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x888D6E70: if_call_seq u8@0x34, u32@0x1c, u8@0x7b4, u8@0x34, u32@0x3c, u8@0x42 */
ts4_word ts4_if_call_seq_u8_off34_888D6E70(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 == 1) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1973) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 66) = (unsigned char)0;
        fn_888CBDA8((ts4_word)a0, (ts4_word)0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    } else {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1972) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)2;
        *(unsigned char *)((char *)(ts4_word)(a0) + 66) = (unsigned char)1;
        fn_888CBDA8((ts4_word)a0, (ts4_word)1);
    }
    return 1;
}

/* Swing_DLL.xex 0x888D73B0: if_call_seq u32@0x15c, u32@0x12c, fn_881800D8, u32@0x8, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off15c_888D73B0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 348);
    p8 = (ts4_word)0;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 300)) != 0) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)0;
        t3 = fn_881800D8((ts4_word)t1, (ts4_word)((4293066752) | 60000), *(ts4_args2 *)&loc50[0]);
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        ts4_loop_get_u32_off8_8861DDB0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 348)), (ts4_word)t3);
        p8 = (ts4_word)t4;
    }
    return p8;
}

/* Swing_DLL.xex 0x888D84B8: if_call_seq fn_8817EA90, fn_888D8368, u32@lbl_88C6B810, fn_888D82E0, u32@0x18, u16@0x1c */
ts4_word ts4_if_call_seq_fn_8817EA90_888D84B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    unsigned short t6;
    ts4_word t11;

    if ((ts4_word)a1 < 4) {
        fn_8817EA90((ts4_word)(ts4_word)&loc58[0], (ts4_word)a4);
        t2 = fn_888D8368((ts4_word)a0, (ts4_word)a3, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)t2 != 0) {
            loc50[0] = (ts4_word)(*(ts4_word *)lbl_88C6B810);
            t4 = fn_888D82E0((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
            t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 24);
            t6 = *(unsigned short *)((char *)(ts4_word)(t2) + 28);
            *(unsigned short *)((char *)loc58 + 0) = (unsigned short)t4;
            loc58[1] = (ts4_word)t5;
            *(unsigned short *)((char *)loc58 + 8) = (unsigned short)t6;
            fn_888CEAA8((ts4_word)a0, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(a1 & 0xff));
        }
    }
    t11 = ts4_if_call_seq_u32_off4_8817E430((ts4_word)a4);
    return t11;
}

/* Swing_DLL.xex 0x888DC540: get fn_88627EC0, ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x30 */
ts4_word ts4_get_fn_88627EC0_888DC540(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = ts4_find_service((ts4_word)((1670447104) | 60230));
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 76))))((ts4_word)t3, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(t6) + 36) = (ts4_word)(*(ts4_word *)lbl_88C6B90C);
    t8 = *(ts4_word *)lbl_88C6B8F4;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 32) = (ts4_word)t8;
    return t6;
}

/* Swing_DLL.xex 0x888DF008: loop_call_seq u32@0x20, u32@0x40, u32@0x1c, u32@0x20, u32@0x0, u32@0x10 */
ts4_word ts4_loop_call_seq_u32_off20_888DF008(ts4_word a0)
{
    ts4_word lv6;
    ts4_word lv7;
    ts4_word p14;
    ts4_word p16;
    ts4_word p18;
    ts4_word p20;
    ts4_word p26;
    ts4_word p29;
    ts4_word p30;
    ts4_word p33;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    int t8;
    ts4_word t10;
    ts4_word t19;
    ts4_word t17;
    ts4_word t15;
    ts4_word t12;
    ts4_word t11;
    ts4_word t21;
    ts4_word t22;
    ts4_word t28;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    p33 = (ts4_word)a0;
    if ((ts4_word)t3 != (ts4_word)t4) {
        lv6 = (ts4_word)a0;
        lv7 = (ts4_word)t3;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 16);
            p26 = (ts4_word)lv6;
            if ((int)t5 == (int)t8) {
                t10 = *(ts4_word *)((char *)(ts4_word)(lv7) + 4);
                if ((ts4_word)t10 == (ts4_word)((2898788352) | 35534)) {
                    t19 = fn_888DD560((ts4_word)a0, (ts4_word)lv7);
                    p20 = (ts4_word)t19;
                } else {
                    if ((ts4_word)t10 == (ts4_word)((2910388224) | 28399)) {
                        t17 = ts4_if_get_u32_off8_888C2D40((ts4_word)a0, (ts4_word)lv7);
                        p18 = (ts4_word)t17;
                    } else {
                        if ((ts4_word)t10 == (ts4_word)((1252392960) | 42723)) {
                            t15 = ts4_if_get_u32_off8_888C2CC8((ts4_word)a0, (ts4_word)lv7);
                            p16 = (ts4_word)t15;
                        } else {
                            if ((ts4_word)t10 == (ts4_word)((801636352) | 13216)) {
                                t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
                                *(unsigned char *)((char *)(ts4_word)(t12) + 564) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(lv7) + 36));
                                p14 = (ts4_word)lv6;
                            } else {
                                t11 = ts4_if_call_seq_u32_lbl_88D45B1C_888DAEE8((ts4_word)a0, (ts4_word)lv7);
                                p14 = (ts4_word)t11;
                            }
                            p16 = (ts4_word)p14;
                        }
                        p18 = (ts4_word)p16;
                    }
                    p20 = (ts4_word)p18;
                }
                t21 = *(ts4_word *)((char *)(ts4_word)(lv7) + 4);
                if ((ts4_word)t21 == (ts4_word)((3480354816) | 6071)) {
                    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
                    *(float *)((char *)(ts4_word)(t22) + 560) = (*(float *)((char *)(ts4_word)(lv7) + 28));
                }
                p26 = (ts4_word)p20;
            }
            t28 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 32);
            p29 = (ts4_word)p26;
            p30 = (ts4_word)(lv7 + 48);
            lv6 = p29;
            lv7 = p30;
        } while ((ts4_word)p30 != (ts4_word)t28);
        p33 = (ts4_word)lv6;
    }
    return p33;
}

/* Swing_DLL.xex 0x888E3490: if_get ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x28, lbl_880D9E24 */
ts4_word ts4_if_get_ts4_find_service_888E3490(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;

    t1 = ts4_find_service((ts4_word)((2055471104) | 43325));
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t4;
    }
    fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D9E24);
    t7 = loc50[2];
    t8 = fn_88923530((ts4_word)t7, *(ts4_args3 *)&loc50[0], (ts4_word)((1513553920) | 29823));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t8;
    t9 = ts4_find_service((ts4_word)((2354708480) | 18722));
    t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 76))))((ts4_word)t9, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t12;
    t13 = ts4_find_service((ts4_word)((2624585728) | 60147));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)t13;
    *(unsigned char *)((char *)(ts4_word)(a0) + 250) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 248) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 251) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    return t13;
}

/* Swing_DLL.xex 0x888E6DE0: loop_call_seq lbl_880D82D0, u32@lbl_88D45B0C, fn_8862BE08, fn_88169350, lbl_88C6B838, u32@0x0 */
ts4_word ts4_loop_call_seq_lbl_880D82D0_888E6DE0(void)
{
    ts4_word lv5;
    ts4_word lv6;
    ts4_word p10;
    ts4_word p11;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)lbl_88D45B0C;
    fn_8862BE08((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880D82D0);
    t3 = fn_88169350((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t4 = loc50[0];
    lv5 = (ts4_word)0;
    lv6 = (ts4_word)(ts4_word)lbl_88C6B838;
    do {
        t8 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
        if ((ts4_word)t8 == (ts4_word)t4) {
            if ((int)(lv5 + 29) <= 72) {
                t9 = ts4_if_get_u32_off1c_88656900((ts4_word)t1, (ts4_word)(lv5 + 29), (ts4_word)0);
                return t9;
            }
            return t3;
        }
        p10 = (ts4_word)(lv5 + 1);
        p11 = (ts4_word)(lv6 + 4);
        lv5 = p10;
        lv6 = p11;
    } while ((int)p11 < (int)((ts4_word)lbl_88C6B838 + 168));
    return t3;
}

/* Swing_DLL.xex 0x888E7308: loop_call_seq lbl_880D8300, fn_8862C0E8, fn_88923530, u32@0x0, u32@0x4, u8@-0x1 */
ts4_word ts4_loop_call_seq_lbl_880D8300_888E7308(void)
{
    ts4_word p5;
    ts4_word p7;
    ts4_word lv9;
    ts4_word p11;
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t3;
    int t4;
    unsigned char t10;

    fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D8300);
    t2 = loc50[2];
    t3 = fn_88923530((ts4_word)t2, *(ts4_args3 *)&loc50[0], (ts4_word)((3630694400) | 12420));
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    p5 = (ts4_word)0;
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + t3);
    }
    p7 = (ts4_word)0;
    if ((int)t4 != -1) {
        p7 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(t3) + 4)) * 176) + t4) + t3);
    }
    if ((ts4_word)p5 != (ts4_word)p7) {
        lv9 = (ts4_word)(p5 + 25);
        do {
            t10 = *(unsigned char *)((char *)(ts4_word)(lv9) + -1);
            if ((ts4_word)t10 != 0) {
                *(unsigned char *)((char *)(ts4_word)(lv9) + 0) = (unsigned char)1;
            }
            p11 = (ts4_word)(lv9 + 176);
            lv9 = p11;
        } while ((ts4_word)(p11 + -25) != (ts4_word)p7);
    }
    return t3;
}

/* Swing_DLL.xex 0x88909FF0: if_call_seq u32@lbl_88C6AEF0, fn_888F19A8, u8@0x5c, ts4_find_typed_entry_887819C0, u32@0x0, ts4_find_typed_entry_887819C0 */
void ts4_if_call_seq_u32_lbl_88C6AEF0_88909FF0(ts4_word a0)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)lbl_88C6AEF0;
    if ((int)t1 != -1) {
        t2 = fn_888F19A8();
        if ((ts4_word)(t2 & 0xff) == 1) {
            *(volatile unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
            loc50[0] = (ts4_word)((797638656) | 9246);
            t3 = ts4_find_typed_entry_887819C0((ts4_word)(ts4_word)&loc50[0]);
            if ((ts4_word)t3 != 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)((272171008) | 17109);
            }
            loc50[0] = (ts4_word)((1374552064) | 54614);
            t4 = ts4_find_typed_entry_887819C0((ts4_word)(ts4_word)&loc50[0]);
            if ((ts4_word)t4 != 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)((2438725632) | 36937);
            }
            fn_88909988((ts4_word)a0, (ts4_word)0, (ts4_word)(*(volatile ts4_word *)lbl_88C6AEF0));
            *(volatile ts4_word *)lbl_88C6AEF0 = (ts4_word)-1;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8890D5B8: if_fn  */
ts4_word ts4_if_fn_8890D5B8(ts4_word a0)
{
    if ((ts4_word)a0 != (ts4_word)((3591372800) | 51922)) {
        return (((((3663003648) | 18518) - a0) != 0) ? 3 : 0);
    }
    return 2;
}

/* Swing_DLL.xex 0x8890D6D0: fn  */
__vector4 ts4_fn_8890D6D0(__vector4 vp1, __vector4 vp2, __vector4 vp3)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;

    vv1 = __vsubfp(vp2, vp1);
    vv2 = __vspltisw(0);
    vv3 = __vsubfp(vp3, vp1);
    vv4 = __vupkd3d(vv2, 0);
    vv5 = __vrefp(vv1);
    vv6 = __vmulfp(vv5, vv3);
    vv7 = __vspltw(vv6, 1);
    vv8 = __vminfp(vv7, vv4);
    vv9 = __vmaxfp(vv2, vv8);
    vv10 = __vmaddfp(vv1, vv9, vp1);
    return vv10;
}

/* Swing_DLL.xex 0x8890D7E8: loop_get u32@0x20, u32@0x24, u32@0x0, u32@0x4, u32@0x14 */
void ts4_loop_get_u32_off20_8890D7E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv3;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return;
    }
    lv3 = (ts4_word)t1;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            *(float *)((char *)(ts4_word)(t4) + 0) = (*(float *)((char *)(ts4_word)((t5 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))));
        }
        p11 = (ts4_word)(lv3 + 8);
        lv3 = p11;
    } while ((ts4_word)p11 != (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x8890D828: loop_get u32@0x2c, u32@0x30, u32@0x0, u32@0x4, u32@0x14 */
void ts4_loop_get_u32_off2c_8890D828(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv3;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    float t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return;
    }
    lv3 = (ts4_word)t1;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            t6 = *(float *)((char *)(ts4_word)(t4) + 0);
            *(float *)((char *)(ts4_word)((t5 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))) = t6;
        }
        p11 = (ts4_word)(lv3 + 8);
        lv3 = p11;
    } while ((ts4_word)p11 != (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x8890E988: loop_call_seq u32@0x2c, u32@0x30, u32@0x0, u32@0x4, u32@0x14, fn_8890E8B0 */
ts4_word ts4_loop_call_seq_u32_off2c_8890E988(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, int a7)
{
    float t322;
    ts4_word t222;
    ts4_word t122;
    int lv3;
    ts4_word p11;
    ts4_word lv20;
    ts4_word p25;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    lv3 = (ts4_word)t1;
    while ((ts4_word)lv3 != (ts4_word)t2) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 4);
            t222 = (*(volatile ts4_word *)(20 + (char *)(ts4_word)(a0)));
            t122 = t222;
            t322 = (*(float *)((char *)(ts4_word)(t4) + 0));
            *(volatile float *)((char *)(ts4_word)((t5 << 2)) + t122) = t322;
        }
        p11 = (ts4_word)(lv3 + 8);
        lv3 = p11;
    }
    t17 = fn_8890E8B0((ts4_word)a0);
    t18 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    lv20 = (ts4_word)t18;
    while ((ts4_word)lv20 != (ts4_word)t19) {
        t21 = *(volatile ts4_word *)((char *)(ts4_word)(lv20) + 0);
        if (0 != (ts4_word)t21) {
            *(volatile float *)((char *)(ts4_word)(t21) + 0) = (*(float *)((char *)(ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(lv20) + 4)) << 2)) + (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20))));
        }
        p25 = (ts4_word)(lv20 + 8);
        lv20 = p25;
    }
    return t17;
}

/* Swing_DLL.xex 0x88911B70: if_get u32@0x44, u32@0x48, u32@0x54, u32@0x4c, u32@0x48, fn_88911A00 */
ts4_word ts4_if_get_u32_off44_88911B70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t2 < (ts4_word)t1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        if ((int)(t3 - t4) != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(t2 + 1);
            return a0;
        }
    }
    return fn_88911A00((ts4_word)a0);
}

/* Swing_DLL.xex 0x88912B38: get u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_get_u32_off0_88912B38(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t2))((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)196);
}

/* Swing_DLL.xex 0x88912B58: get u32@0x0, u32@0x10, u32@0x8 */
ts4_word ts4_get_u32_off0_88912B58(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t2))((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)196);
}

/* Swing_DLL.xex 0x88912D80: if_get u32@0x48, u32@0x1c, u32@0x4, u32@0x0, u32@0x58 */
ts4_word ts4_if_get_u32_off48_88912D80(ts4_word a0)
{
    int t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 88))))((ts4_word)t3, (ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x889139A0: call_seq lbl_880D6ECC, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88913638, lbl_880D6EDC, fn_88608590 */
ts4_word ts4_call_seq_lbl_880D6ECC_889139A0(void)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t31;
    ts4_word t34;
    ts4_word t37;
    ts4_word t40;
    ts4_word t43;
    ts4_word t45;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6ECC);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88913638((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6EDC);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_889137B0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6EF0);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_88913588((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F0C);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_889134D8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F24);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88913428((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F3C);
    ts4_loop_call_seq_u32_off4_88174B90((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)t16);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F54);
    ts4_loop_call_seq_u32_off4_88174B90((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)t19);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F6C);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_88913368((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F84);
    ts4_loop_call_seq_u32_off4_88174C40((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)t25);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6F9C);
    ts4_loop_call_seq_u32_off4_88174C40((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)t28);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6FB4);
    loc50[0] = (ts4_word)t31;
    ts4_keyed_item_list_add_unique_889132A8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t34 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6FCC);
    loc50[0] = (ts4_word)t34;
    ts4_keyed_item_list_add_unique_889131F8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t37 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6FE4);
    loc50[0] = (ts4_word)t37;
    ts4_keyed_item_list_add_unique_88913148((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t40 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6FFC);
    loc50[0] = (ts4_word)t40;
    ts4_keyed_item_list_add_unique_88913098((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t43 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D7018);
    loc50[0] = (ts4_word)t43;
    t45 = ts4_keyed_item_list_add_unique_88912FE8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t45;
}

/* Swing_DLL.xex 0x88913BD8: if_set u32@0x48, u32@0x34, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_set_u32_off48_88913BD8(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word p26;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t6;
    ts4_word t9;
    ts4_word t11;
    ts4_word t15;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;
    ts4_word t25;
    ts4_word t1;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)a2;
    if ((int)a2 == 1) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 68))))((ts4_word)t6);
        if ((ts4_word)(t9 & 0xff) != 0) {
            ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1);
            t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 60))))((ts4_word)t11, (ts4_word)(ts4_word)&loc58[0]);
            t15 = loc58[0];
            ts4_destroy_owned_object((ts4_word)t15);
        }
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1);
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t22 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t19) + 0))) + 52))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t19, (ts4_word)(ts4_word)&loc68[0], (ts4_word)2, (ts4_word)0);
        t23 = loc68[0];
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t22) + 0));
        t25 = ts4_destroy_owned_object((ts4_word)t23);
        p26 = (ts4_word)t25;
    } else {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)a1, (ts4_word)1, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
        p26 = (ts4_word)t4;
    }
    return p26;
}

/* Swing_DLL.xex 0x88916408: loop_get u32@0xc, u32@0x430, u32@0x42c, u32@0x10, u32@0x430, u32@0x0 */
void ts4_loop_get_u32_offc_88916408(ts4_word a0, ts4_word a1)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word lv6;
    ts4_word p10;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1072) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 1068) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((ts4_word)t2 == (ts4_word)((3626369024) | 58723)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1072) = (ts4_word)1;
    }
    c3 = (ts4_word)2;
    lv6 = (ts4_word)0;
    lv4 = (ts4_word)(a0 + 1084);
    do {
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(((t7 + lv6) + a1)) + 0);
        *(ts4_word *)((char *)(ts4_word)(lv4) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv4) + -8) = (ts4_word)t8;
        t9 = *(ts4_word *)((char *)(ts4_word)(((t7 + lv6) + a1)) + 4);
        if ((ts4_word)t9 == (ts4_word)((830210048) | 20919)) {
            *(ts4_word *)((char *)(ts4_word)(lv4) + 0) = (ts4_word)1;
        }
        p10 = (ts4_word)(lv4 + 4);
        p12 = (ts4_word)(lv6 + 8);
        lv4 = p10;
        lv6 = p12;
    } while (--c3 != 0);
    return;
}

/* Swing_DLL.xex 0x8891EAF8: if_call_seq fn_88939470, fn_889395D8, fn_889395D8, fn_889395D8, fn_889395D8, fn_889395D8 */
ts4_word ts4_if_call_seq_fn_88939470_8891EAF8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t41;
    ts4_word t45;
    ts4_word t46;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1088));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1092));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1096));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1100));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1104));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1108));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1112));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1116));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1120));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1124));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1128));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1132));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1136));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1140));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1144));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1148));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1152));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1156));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1160));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1164));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1168));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1172));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1176));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1180));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1184));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1188));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1208));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1212));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1216));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1217));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1218));
    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1219));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1196));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1192));
    fn_88939470((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)2);
    t41 = loc50[0];
    if ((ts4_word)t41 >= 1) {
        if ((ts4_word)t41 != 1) {
            if ((ts4_word)t41 < 3) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 1200) = (ts4_word)((3751936000) | 45041);
            }
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 1200) = (ts4_word)((4220583936) | 63194);
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 1200) = (ts4_word)((2684157952) | 13278);
    }
    t45 = fn_88939470((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)3);
    t46 = loc50[0];
    switch ((ts4_word)(t46)) {
        case 0:
        case 2:
        *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)((4118282240) | 1402);
        break;
        case 1:
        *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)((3657039872) | 6967);
        break;
        case 3:
        *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)((3340238848) | 55978);
        break;
        case 4:
        *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)((2567110656) | 30629);
        break;
        case 5:
        *(ts4_word *)((char *)(ts4_word)(a0) + 1204) = (ts4_word)((2125660160) | 3984);
        break;
    }
    return t45;
}

/* Swing_DLL.xex 0x88923778: get u32@0x28 */
ts4_word ts4_get_u32_off28_88923778(ts4_word a0, ts4_word a1)
{
    return ((ts4_word)a1 < (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
}

/* Swing_DLL.xex 0x889245D0: if_get u32@0x0, u32@0x10, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_if_get_u32_off0_889245D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 != (ts4_word)((1505886208) | 14123)) {
        if ((ts4_word)t1 != (ts4_word)((2527723520) | 28840)) {
            return;
        }
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + (p3 << 2));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t7;
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 12)) + t9);
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88924710: if_get u32@0x0, u32@0x10, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_if_get_u32_off0_88924710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 != (ts4_word)((1505886208) | 14123)) {
        if ((ts4_word)t1 != (ts4_word)((2527723520) | 28840)) {
            return;
        }
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)1;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + (p3 << 2));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t7;
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 12)) + t9);
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88924F20: if_get u32@0x0, u32@0x10, u32@0x0, u32@0x0, u32@0xc, u32@0x4 */
void ts4_if_get_u32_off0_88924F20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 != (ts4_word)((1505492992) | 22375)) {
        if ((ts4_word)t1 != (ts4_word)((3081895936) | 13899)) {
            if ((ts4_word)t1 != (ts4_word)((3233087488) | 1757)) {
                return;
            }
            p3 = (ts4_word)1;
        } else {
            p3 = (ts4_word)0;
        }
        p6 = (ts4_word)p3;
    } else {
        p6 = (ts4_word)2;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + (p6 << 2));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t10;
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 12);
    t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 12)) + t12);
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88926938: loop_get u32@0x58, u32@0x54, u32@0x0, u32@0x0, u32@0x48, vcall */
ts4_word ts4_loop_get_u32_off58_88926938(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p14;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 88);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 84));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 72))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)a2, (ts4_word)a3);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
            if ((ts4_word)t8 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 72))))((ts4_word)a0, (ts4_word)t4, (ts4_word)a2, (ts4_word)a3);
                return a0;
            }
        }
        p14 = (ts4_word)(lv3 + 4);
        lv3 = p14;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return a0;
}

/* Swing_DLL.xex 0x889298D8: call_seq lbl_880D60F8, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_88929120, lbl_880D6108, fn_88608590 */
ts4_word ts4_call_seq_lbl_880D60F8_889298D8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t25;
    ts4_word t27;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D60F8);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_if_mode_88929120((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6108);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_if_mode_88929758((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D611C);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_if_mode_88929550((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D612C);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_if_mode_88929470((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6144);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_if_mode_88929120((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6164);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_if_mode_88929758((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D6188);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_if_mode_88929550((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D61A8);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_if_mode_88929470((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880D61D0);
    loc50[0] = (ts4_word)t25;
    t27 = ts4_keyed_item_list_add_unique_if_mode_88928A10((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return t27;
}

/* Swing_DLL.xex 0x88930038: if_get u32@0x8, u32@0x0, u32@0x48, vcall, u32@0x8, ts4_if_call_seq_fn_8892EE88_8817F5E0 */
ts4_word ts4_if_get_u32_off8_88930038(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t4;
    int t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a2);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p7 = (ts4_word)t4;
    if ((int)t5 == 11) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t6 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)t4, *(ts4_args3 *)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x889300B0: if_get u32@0x8, u32@0x0, u32@0x48, vcall, u32@0x8, ts4_if_call_seq_fn_8892EE88_8817F5E0 */
ts4_word ts4_if_get_u32_off8_889300B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t4;
    int t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a2);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p7 = (ts4_word)t4;
    if ((int)t5 == 11) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t6 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)t4, *(ts4_args3 *)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88930A40: addr lbl_880D5930, lbl_880D5938, lbl_880D594C, lbl_880D5964, lbl_880D5988, lbl_880D59D4 */
ts4_word ts4_addr_lbl_880D5930_88930A40(ts4_word a0)
{
    switch ((ts4_word)(a0)) {
        case 0:
        return (ts4_word)lbl_880D5930;
        case 1:
        return (ts4_word)lbl_880D5938;
        case 2:
        return (ts4_word)lbl_880D594C;
        case 3:
        return (ts4_word)lbl_880D5964;
        case 4:
        return (ts4_word)lbl_880D5988;
        case 5:
        default:
        return (ts4_word)lbl_880D59D4;
        case 6:
        return (ts4_word)lbl_880D59A4;
        case 7:
        return (ts4_word)lbl_880D59BC;
    }
}

/* Swing_DLL.xex 0x88931FE0: loop_get u32@0x1c, u32@0x8, u32@0x4, vcall, u32@0x1c, u32@0x28 */
void ts4_loop_get_u32_off1c_88931FE0(ts4_word a0, ts4_word a1)
{
    ts4_word lv8;
    ts4_word p29;
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;
    signed char t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    int t15;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 8))) + 4))))((ts4_word)(t1 + 8));
    t6 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + 40);
    lv8 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t6) + 0));
    while ((ts4_word)lv8 != (ts4_word)t6) {
        t9 = *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 8);
        t10 = *(volatile unsigned char *)((char *)(ts4_word)(t9) + 24);
        if ((ts4_word)t10 == 0) {
            t11 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
            t12 = *(volatile ts4_word *)((char *)(ts4_word)(t9) + 0);
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(t9) + 8);
            if ((ts4_word)t12 == (ts4_word)t11) {
                t15 = *(volatile ts4_word *)((char *)(ts4_word)(t13) + 4);
                if ((int)t15 == 1) {
                    ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)t13);
                }
                ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0, (ts4_word)t13);
                *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(lv8) + 8))) + 24) = (unsigned char)1;
            }
        }
        p29 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv8) + 0));
        lv8 = p29;
    }
    ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((t1 + 8)) + 0))) + 8))))((ts4_word)(t1 + 8));
    return;
}

/* Swing_DLL.xex 0x88932328: if_get u32@0x14, u32@0xc, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off14_88932328(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)(((ts4_word)t1 >= (ts4_word)a1) & 0xff) != 0) {
        return ((ts4_word)t1 >= (ts4_word)a1);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t3 != 0) {
        return ((ts4_word)t1 >= (ts4_word)a1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
    return ((ts4_word)t1 >= (ts4_word)a1);
}

/* Swing_DLL.xex 0x889324A0: loop_get u32@0x4, u32@0x14, u32@0x4, u32@0x14, u32@0x8, u32@0x4 */
void ts4_loop_get_u32_off4_889324A0(ts4_word a0)
{
    ts4_word lv8;
    ts4_word p18;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 20)) != 0) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + 20);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 8);
        lv8 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 4));
        while ((ts4_word)lv8 != (ts4_word)t5) {
            t9 = *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 0);
            t12 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t9) + 0))) + 24))))((ts4_word)t9);
            if ((ts4_word)(t12 & 0xff) != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0, (ts4_word)t9);
            }
            p18 = (ts4_word)(lv8 + 4);
            lv8 = p18;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88932530: loop_get u32@0x4, u32@0x14, u32@0x4, u32@0x14, u32@0x8, u32@0x4 */
void ts4_loop_get_u32_off4_88932530(ts4_word a0)
{
    ts4_word lv8;
    ts4_word p18;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 20)) != 0) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + 20);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 8);
        lv8 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 4));
        while ((ts4_word)lv8 != (ts4_word)t5) {
            t9 = *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 0);
            t12 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t9) + 0))) + 24))))((ts4_word)t9);
            if ((ts4_word)(t12 & 0xff) != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)t9);
            }
            p18 = (ts4_word)(lv8 + 4);
            lv8 = p18;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88936B70: if_get u32@0x8, u32@0x4, u32@0xc, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off8_88936B70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    int t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(((ts4_word)t2 >= (ts4_word)(t1 + a1)) & 0xff) != 0) {
        return ((ts4_word)t2 >= (ts4_word)(t1 + a1));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t4 != 0) {
        return ((ts4_word)t2 >= (ts4_word)(t1 + a1));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)2;
    return ((ts4_word)t2 >= (ts4_word)(t1 + a1));
}

/* Swing_DLL.xex 0x8893E0C0: call_seq fn_88627EC0, u8@0x94, RtlInitializeCriticalSection, fn_88923530, u32@0x20, ts4_find_service */
ts4_word ts4_call_seq_fn_88627EC0_8893E0C0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 148) = (unsigned char)0;
    RtlInitializeCriticalSection((ts4_word)(a0 + 84));
    t4 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((645332992) | 55984));
    t6 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 32)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
    return t6;
}

/* Swing_DLL.xex 0x8893E120: set fn_88627EC0, u8@0x20, fn_88923530, u32@0x0, u32@0x28, vcall */
ts4_word ts4_set_fn_88627EC0_8893E120(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((801505280) | 64393));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)t3);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88941250: get u32@0x88, u32@0x8c, u32@0x90, u32@0x84, u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off88_88941250(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    float t8;
    float t9;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    t7 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
    t8 = *(float *)((char *)(ts4_word)(t5) + 0);
    t9 = *(float *)((char *)(ts4_word)(t6) + 0);
    *(float *)((char *)loc50 + 0) = (((t9 - t8) * (*(float *)((char *)(ts4_word)(t7) + 0))) + t8);
    t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 12))))((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)t7, (ts4_word)t6, (ts4_word)t5, (ts4_word)t3);
    return t13;
}

/* Swing_DLL.xex 0x88942AF0: loop_get u32@0x550, u32@0x550, u32@0xec, u32@0x550, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off550_88942AF0(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word lv7;
    ts4_word p9;
    ts4_word p14;
    int t2;
    ts4_word t3;
    int t4;
    int t6;
    ts4_word t12;
    ts4_word t13;

    if ((ts4_word)a1 == 0) {
        return;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1360);
    if ((int)t2 == 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 236) = (ts4_word)0;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1360);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0);
    p5 = (ts4_word)0;
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + t3);
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0);
    lv7 = (ts4_word)p5;
    do {
        p9 = (ts4_word)0;
        if ((int)t6 != -1) {
            p9 = (ts4_word)((((*(volatile ts4_word *)((char *)(ts4_word)(t3) + 4)) << 4) + t6) + t3);
        }
        if ((ts4_word)lv7 == (ts4_word)p9) {
            return;
        }
        t12 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 104);
        t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv7) + 12);
        if ((ts4_word)t12 == (ts4_word)t13) {
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 236) = (ts4_word)lv7;
            return;
        }
        p14 = (ts4_word)(lv7 + 16);
        lv7 = p14;
    } while (1);
}

/* Swing_DLL.xex 0x88943E70: if_call_seq u32@0x20, u32@lbl_88D45B1C, u32@0x27c, fn_887F8218 */
ts4_word ts4_if_call_seq_u32_off20_88943E70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
        loc50[0] = (ts4_word)t3;
        t4 = fn_887F8218((ts4_word)t1, (ts4_word)(ts4_word)&a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t3);
        return t4;
    }
    return 0;
}

/* Swing_DLL.xex 0x88945FD8: if_set u32@0x0, u32@0x8, u32@0x4, u32@0x0, fn_88608590, u32@0x0 */
ts4_word ts4_if_set_u32_off0_88945FD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t5 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t5) + 4)) == 2) {
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 108))))((ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)a2, (ts4_word)0);
        t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
        t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        t12 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t10;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t11;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t12;
    }
    return a0;
}
