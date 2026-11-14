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
#include "ts4_vector.h"
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedExchange(volatile long *value, long v);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedExchange, _InterlockedIncrement)
#endif

extern char __imp_KeCertMonitorData[];
extern char __imp_VdGlobalDevice[];
extern char __imp_VdGlobalXamDevice[];
extern char g_ts4_online_state[];
extern char g_ts4_script_constants[];
extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88028BDC[];
extern char lbl_8803A308[];
extern char lbl_8803A3B0[];
extern char lbl_88081F98[];
extern char lbl_88081FB0[];
extern char lbl_88082070[];
extern char lbl_88082540[];
extern char lbl_88082644[];
extern char lbl_88089254[];
extern char lbl_880C1320[];
extern char lbl_880D1A70[];
extern char lbl_880D1A80[];
extern char lbl_880D1A90[];
extern char lbl_880D1B20[];
extern char lbl_880D6330[];
extern char lbl_880D67D0[];
extern char lbl_880E1880[];
extern char lbl_880E2CCC[];
extern char lbl_880E4630[];
extern char lbl_880F3858[];
extern char lbl_880F4900[];
extern char lbl_880F4948[];
extern char lbl_880F4990[];
extern char lbl_880F49D8[];
extern char lbl_880F4A20[];
extern char lbl_880F7D28[];
extern char lbl_880F7D58[];
extern char lbl_880F7D74[];
extern char lbl_880F7DA0[];
extern char lbl_880F8C74[];
extern char lbl_8814B440[];
extern char lbl_8814B910[];
extern char lbl_88B3302C[];
extern char lbl_88B330C4[];
extern char lbl_88B36C18[];
extern char lbl_88C46F6A[];
extern char lbl_88C6A0E8[];
extern char lbl_88C6A0F8[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B4B0[];
extern char lbl_88C6B6C0[];
extern char lbl_88C6B760[];
extern char lbl_88C6B7C0[];
extern char lbl_88C922FC[];
extern char lbl_88CACF08[];
extern char lbl_88D3CD50[];
extern char lbl_88D3E3A4[];
extern char lbl_88D3E3A8[];
extern char lbl_88D3EB60[];
extern char lbl_88D41FC4[];
extern char lbl_88D44040[];
extern char lbl_88D45A04[];
extern char lbl_88D45A58[];
extern char lbl_88D45A8C[];
extern char lbl_88D45A90[];
extern char lbl_88D45A94[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
extern char lbl_88D48CC0[];
extern char ts4_noop_88AFF000[];
extern char ts4_noop_88AFF320[];
ts4_word KeGetCurrentProcessType();
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlInitAnsiString();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_88150600();
ts4_word fn_88151560();
ts4_word fn_88157F10();
ts4_word fn_88161540();
ts4_word fn_88166108();
ts4_word fn_88166178();
ts4_word ts4_chunk_reader_read_8816B5A8();
ts4_word fn_8816D1A8();
ts4_word fn_881705B0();
ts4_word fn_8817B608();
ts4_word fn_8817C510();
ts4_word fn_8817EA90();
ts4_word fn_88187E70();
ts4_word fn_8818A3E0();
ts4_word fn_88195368();
ts4_word fn_88195578();
ts4_word fn_88196708();
ts4_word fn_88198CE0();
ts4_word fn_881991A0();
ts4_word fn_881992A8();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word fn_8819B148();
ts4_word fn_881A5020();
ts4_word fn_881AA7A0();
ts4_word fn_881AAE70();
ts4_word fn_881AB1A0();
ts4_word fn_881AC348();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B9148();
ts4_word ts4_counted_ptr_assign_881C38D0();
ts4_word fn_881C8958();
ts4_word ts4_loop_call_seq_u32_off28_881D0878();
ts4_word fn_881E3988();
ts4_word fn_881EC6D8();
ts4_word ts4_dynamic_cast_by_class_881F1A50();
ts4_word ts4_dynamic_cast_by_class_881F1AC8();
ts4_word ts4_loop_get_u32_off14_881F4C00();
ts4_word ts4_loop_get_u32_off0_881F59C8();
ts4_word fn_881F5D60();
ts4_word ts4_if_get_u32_off14_881F8AD0();
ts4_word fn_8826D958();
ts4_word fn_8827DC68();
ts4_word fn_88292A78();
ts4_word ts4_jpeg_get_small_882F51D8();
ts4_word fn_8830E6C8();
ts4_word fn_8830F378();
ts4_word ts4_read_u8_to_u8_883199C0();
ts4_word fn_88319C40();
ts4_word fn_8832EDB0();
ts4_word ts4_if_call_seq_u32_lbl_88B3302C_883323B8();
ts4_word fn_88376AD0();
ts4_word fn_884025C0();
ts4_word fn_884027D8();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_884235C0();
ts4_word fn_88423660();
ts4_word fn_88423CE0();
ts4_word fn_88424050();
ts4_word fn_884616C0();
ts4_word fn_88461C60();
ts4_word fn_88462090();
ts4_word fn_88470870();
ts4_word fn_88474120();
ts4_word fn_884741B0();
ts4_word fn_88489498();
ts4_word fn_88492220();
ts4_word fn_8849EF70();
ts4_word fn_88563470();
ts4_word fn_88566FE8();
ts4_word fn_8857ACB8();
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8();
ts4_word fn_8857C8C8();
ts4_word fn_885AA208();
ts4_word fn_885ABDB0();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885C3770();
ts4_word fn_885C38E0();
ts4_word fn_885CD338();
ts4_word fn_885CD4B0();
ts4_word fn_885E7AD8();
ts4_word ts4_field_set_string_885F8540();
ts4_word ts4_field_set_string_885FFA88();
ts4_word ts4_field_set_string_885FFC30();
ts4_word ts4_field_set_string_885FFCB0();
ts4_word fn_88608590();
ts4_word fn_88608A40();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88615650();
ts4_word fn_886156B8();
ts4_word ts4_crc32_guarded_8864B2C8();
ts4_word fn_8864BBB0();
ts4_word fn_8867BB78();
ts4_word fn_88690920();
ts4_word fn_886921A0();
ts4_word fn_886A1128();
ts4_word fn_886BC480();
ts4_word fn_886F5AE0();
ts4_word fn_886F5BD0();
ts4_word fn_886F5FB0();
ts4_word fn_88700F88();
ts4_word fn_88719330();
ts4_word fn_887193A8();
ts4_word fn_887573E0();
ts4_word fn_88758A00();
ts4_word fn_887D4360();
ts4_word fn_887EA830();
ts4_word fn_887EB830();
ts4_word fn_887EC298();
ts4_word fn_887EC4A8();
ts4_word fn_887F4BA0();
ts4_word ts4_call_seq_lbl_880E2FE4_888085E0();
ts4_word fn_88811930();
ts4_word fn_88811A08();
ts4_word lua2_luaH_getany_88811E80();
ts4_word lua2_luaH_getanynode_88811F40();
ts4_word lua2_searchvar_88814418();
ts4_word lua2_newupvalue_88814668();
ts4_word ts4_loop_call_seq_fn_88814418_88814950();
ts4_word lua2_DumpBlock_8881C828();
ts4_word lua2_luaU_dump_8881D0A8();
ts4_word lua2_luaK_stringK_88820AF0();
ts4_word fn_88833E80();
ts4_word fn_88834CF0();
ts4_word fn_888368B0();
ts4_word fn_88837880();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word fn_888CDF68();
ts4_word fn_888CEAA8();
ts4_word fn_888D8368();
ts4_word fn_8890F370();
ts4_word fn_88913BD8();
ts4_word fn_88925640();
ts4_word fn_88929E70();
ts4_word fn_8892A380();
ts4_word fn_8892D5F8();
ts4_word fn_88933EF8();
ts4_word fn_88936AF0();
ts4_word fn_88939288();
ts4_word fn_889393C0();
ts4_word fn_88995AB8();
ts4_word fn_889BD910();
ts4_word fn_889C14F8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word ts4_call_seq_fn_88467768_884544F8();
ts4_word ts4_call_seq_fn_88617D88_8892AFF0();
ts4_word ts4_call_seq_lbl_880DD434_88193BE0();
ts4_word ts4_call_seq_lbl_880F7D90_88628EE0();
ts4_word ts4_call_seq_u32_off0_88832F70();
ts4_word ts4_call_seq_u32_off10_88837820();
ts4_word ts4_call_then_conditionally_forward_result_88317B90();
ts4_word ts4_copy_bytes();
ts4_word ts4_create_zeroed_triplet();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_get_u16_off0_8858B248();
ts4_word ts4_get_u32_off3ea0_88594050();
ts4_word ts4_get_u32_off7c_8846AA28();
ts4_word ts4_if_addr_lbl_88D45908_888E7A80();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word ts4_if_call_seq_fn_88931950_889330D8();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_if_call_seq_lbl_88028EA4_8831ACF0();
ts4_word ts4_if_call_seq_u32_g_ts4_session_context_88916FD0();
ts4_word ts4_if_call_seq_u32_off0_886F9C80();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_if_get_u32_g_ts4_session_context_88915980();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_if_get_u32_off0_8892FE20();
ts4_word ts4_if_get_u32_off0_88940A18();
ts4_word ts4_if_get_u32_off54c_882E71A0();
ts4_word ts4_if_get_u8_off420_88934FB8();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word ts4_loop_call_seq_u32_off18_88165F68();
ts4_word ts4_loop_call_seq_u32_offc_88166048();
ts4_word ts4_loop_call_seq_u32_offc_881661F8();
ts4_word ts4_loop_call_seq_u32_offc_88166278();
ts4_word ts4_loop_get_u32_off0_8891B7A0();
ts4_word ts4_loop_get_u8_offd_88811478();
ts4_word ts4_loop_get_u8_offd_888114E0();
ts4_word ts4_loop_get_u8_offd_88811548();
ts4_word ts4_loop_get_u8_offd_888115A0();
ts4_word ts4_memset();
ts4_word ts4_resume_thread();
ts4_word ts4_span28_append();
ts4_word ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000();
ts4_word ts4_tailcall_NetDll_XNetInAddrToString_884EFF00();
ts4_word ts4_tailcall_fn_884EFDD0_884EFE90();
ts4_word ts4_tailcall_fn_884F0178_884F0228();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88155540: loop_get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_loop_get_u32_off0_88155540(ts4_word a0, ts4_word a1)
{
    ts4_word c2;
    ts4_word lv5;
    ts4_word p7;
    ts4_word c8;
    ts4_word lv9;
    ts4_word p11;
    ts4_word c12;
    ts4_word lv13;
    ts4_word p15;
    ts4_word c16;
    ts4_word lv17;
    ts4_word p19;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    c2 = (ts4_word)64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    lv5 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 12)) + lv5) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 + 12)) + lv5));
        p7 = (ts4_word)(lv5 + 1);
        lv5 = p7;
    } while (--c2 != 0);
    c8 = (ts4_word)32;
    lv9 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 76)) + lv9) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 + 76)) + lv9));
        p11 = (ts4_word)(lv9 + 1);
        lv9 = p11;
    } while (--c8 != 0);
    c12 = (ts4_word)16;
    lv13 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 108)) + lv13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 + 108)) + lv13));
        p15 = (ts4_word)(lv13 + 1);
        lv13 = p15;
    } while (--c12 != 0);
    c16 = (ts4_word)16;
    lv17 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 124)) + lv17) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 + 124)) + lv17));
        p19 = (ts4_word)(lv17 + 1);
        lv17 = p19;
    } while (--c16 != 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 140));
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 144));
    *(unsigned char *)((char *)(ts4_word)(a0) + 148) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 148));
    return;
}

/* Swing_DLL.xex 0x881600E8: if_call_seq u32@0xd4, ts4_destroy_owned_object, u32@0xc8, ts4_destroy_owned_object, u32@0xbc, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_offd4_881600E8(ts4_word a0)
{
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
    ts4_word t58;

    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 200)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 188)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    ts4_loop_call_seq_u32_offc_88166278((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 172)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    ts4_loop_call_seq_u32_offc_88166278((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 160)), (ts4_word)t13);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 160);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    ts4_loop_call_seq_u32_offc_881661F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 148)), (ts4_word)t19);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    if ((ts4_word)t22 != 0) {
        ts4_destroy_owned_object((ts4_word)t22);
    }
    t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 136)), (ts4_word)t25);
    t28 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t28 != 0) {
        ts4_destroy_owned_object((ts4_word)t28);
    }
    t31 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    fn_88166178((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)), (ts4_word)t31);
    t34 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t34 != 0) {
        ts4_destroy_owned_object((ts4_word)t34);
    }
    t37 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)), (ts4_word)t37);
    t40 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t40 != 0) {
        ts4_destroy_owned_object((ts4_word)t40);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    t58 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    return t58;
}

/* Swing_DLL.xex 0x88160438: if_call_seq u32@0xe4, u32@0xe0, fn_88166108, u32@0xe0, ts4_destroy_owned_object, u32@0xd8 */
ts4_word ts4_if_call_seq_u32_offe4_88160438(ts4_word a0)
{
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
    ts4_word t46;
    ts4_word t49;
    ts4_word t52;
    ts4_word t55;
    ts4_word t58;
    ts4_word t74;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    fn_88166108((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 224)), (ts4_word)t1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 216);
    ts4_loop_call_seq_u32_offc_88166048((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 200)), (ts4_word)t13);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 200);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 192);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 188)), (ts4_word)t19);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    if ((ts4_word)t22 != 0) {
        ts4_destroy_owned_object((ts4_word)t22);
    }
    t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176)), (ts4_word)t25);
    t28 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    if ((ts4_word)t28 != 0) {
        ts4_destroy_owned_object((ts4_word)t28);
    }
    t31 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 164)), (ts4_word)t31);
    t34 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    if ((ts4_word)t34 != 0) {
        ts4_destroy_owned_object((ts4_word)t34);
    }
    t37 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 152)), (ts4_word)t37);
    t40 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t40 != 0) {
        ts4_destroy_owned_object((ts4_word)t40);
    }
    t43 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 140)), (ts4_word)t43);
    t46 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    if ((ts4_word)t46 != 0) {
        ts4_destroy_owned_object((ts4_word)t46);
    }
    t49 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)t49);
    t52 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t52 != 0) {
        ts4_destroy_owned_object((ts4_word)t52);
    }
    t55 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    ts4_loop_call_seq_u32_off18_88165F68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116)), (ts4_word)t55);
    t58 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t58 != 0) {
        ts4_destroy_owned_object((ts4_word)t58);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t74 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    return t74;
}

/* Swing_DLL.xex 0x881876D0: if_atomic interlocked_dec, u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_atomic_interlocked_dec_881876D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 4)));
    if ((int)t1 == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    }
    return t1;
}

/* Swing_DLL.xex 0x88195BF8: if_get u32@lbl_88D3E3A4, fn_88198CE0, fn_88195578, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8 */
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195BF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word p12;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t16;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = fn_88195578((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    t4 = *(ts4_word *)lbl_88D3E3A8;
    p7 = (ts4_word)t4;
    if ((ts4_word)t4 == 0) {
        fn_88195368((ts4_word)t3);
        p7 = (ts4_word)(*(ts4_word *)lbl_88D3E3A8);
    }
    t10 = fn_8818A3E0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 4)) + 68));
    if ((ts4_word)t10 != 0) {
        t11 = ts4_call_seq_lbl_880DD434_88193BE0((ts4_word)t10);
        p12 = (ts4_word)t11;
    } else {
        p12 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p12;
    if ((ts4_word)p12 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((p12 + 4)));
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t14) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t14) + 16) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(t14) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t14) + 24) = (ts4_word)0;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t14 + 32), (ts4_word)a2);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t16) + 120) = (ts4_word)a4;
    ts4_counted_ptr_assign_881C38D0((ts4_word)(t16 + 100), (ts4_word)a5);
    fn_88196708((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a6);
    fn_88198CE0((ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x8819B6C0: if_get u32@0xc, u32@0x0, u32@0x0, u32@0x4, u32@0x4, vcall */
ts4_word ts4_if_get_u32_offc_8819B6C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p11;
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 >= 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 12)));
        p11 = (ts4_word)a0;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 4))))((ts4_word)t2, (ts4_word)t4, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        memcpy((ts4_word)(t6 + 16), (ts4_word)(a0 + 16), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1));
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x8819C5F0: if_get u32@0xc, u32@0x0, u32@0x0, u32@0x4, u32@0x4, vcall */
ts4_word ts4_if_get_u32_offc_8819C5F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p11;
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 >= 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 12)));
        p11 = (ts4_word)a0;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 4))))((ts4_word)t2, (ts4_word)t4, (ts4_word)2);
        *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        memcpy((ts4_word)(t6 + 16), (ts4_word)(a0 + 16), (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1) << 1));
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x881A4870: addr lbl_880D1B20, lbl_880D1A70, lbl_880D1A80, lbl_880D1A90 */
__vector4 ts4_addr_lbl_880D1B20_881A4870(__vector4 vp1)
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
    __vector4 vv16;
    __vector4 vv17;
    __vector4 vv18;
    __vector4 vv19;
    __vector4 vv20;
    __vector4 vv21;
    __vector4 vv22;
    __vector4 vv23;
    __vector4 vv24;
    __vector4 vv25;
    __vector4 vv26;
    __vector4 vv27;
    __vector4 vv28;
    __vector4 vv29;
    __vector4 vv30;
    __vector4 vv31;
    __vector4 vv32;
    __vector4 vv33;
    __vector4 vv34;
    __vector4 vv35;
    __vector4 vv36;
    __vector4 vv37;
    __vector4 vv38;
    __vector4 vv39;
    __vector4 vv40;
    __vector4 vv41;
    __vector4 vv42;
    __vector4 vv43;

    vv1 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880D1B20));
    vv2 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880D1A70));
    vv3 = __vspltw(vv1, 3);
    vv4 = __vspltw(vv1, 1);
    vv5 = __vspltw(vv2, 1);
    vv6 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880D1A80));
    vv7 = __vspltw(vv2, 2);
    vv8 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880D1A90));
    vv9 = __vmulfp(vp1, vv3);
    vv10 = __vspltw(vv2, 3);
    vv11 = __vspltw(vv6, 0);
    vv12 = __vspltw(vv6, 1);
    vv13 = __vspltw(vv6, 2);
    vv14 = __vspltw(vv6, 3);
    vv15 = __vspltw(vv8, 0);
    vv16 = __vspltw(vv8, 1);
    vv17 = __vspltw(vv8, 2);
    vv18 = __vspltw(vv8, 3);
    vv19 = __vrfin(vv9);
    vv20 = __vnmsubfp(vv4, vv19, vp1);
    vv21 = __vmulfp(vv20, vv20);
    vv22 = __vmulfp(vv21, vv20);
    vv23 = __vmulfp(vv22, vv21);
    vv24 = __vmaddfp(vv5, vv22, vv20);
    vv25 = __vmulfp(vv23, vv21);
    vv26 = __vmaddfp(vv7, vv23, vv24);
    vv27 = __vmulfp(vv25, vv21);
    vv28 = __vmaddfp(vv10, vv25, vv26);
    vv29 = __vmulfp(vv27, vv21);
    vv30 = __vmaddfp(vv11, vv27, vv28);
    vv31 = __vmulfp(vv29, vv21);
    vv32 = __vmaddfp(vv12, vv29, vv30);
    vv33 = __vmulfp(vv31, vv21);
    vv34 = __vmaddfp(vv13, vv31, vv32);
    vv35 = __vmulfp(vv33, vv21);
    vv36 = __vmaddfp(vv14, vv33, vv34);
    vv37 = __vmulfp(vv35, vv21);
    vv38 = __vmaddfp(vv15, vv35, vv36);
    vv39 = __vmulfp(vv37, vv21);
    vv40 = __vmaddfp(vv16, vv37, vv38);
    vv41 = __vmulfp(vv39, vv21);
    vv42 = __vmaddfp(vv17, vv39, vv40);
    vv43 = __vmaddfp(vv18, vv41, vv42);
    return vv43;
}

/* Swing_DLL.xex 0x881A7638: fn  */
void ts4_fn_881A7638(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    *(__vector4 *)((ts4_word)(a0)) = vv1;
    vv2 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv2;
    vv3 = *(__vector4 *)((ts4_word)(a1 + 32));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv3;
    return;
}

/* Swing_DLL.xex 0x881AA740: loop_get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_loop_get_u32_off0_881AA740(ts4_word a0, ts4_word a1)
{
    ts4_word c2;
    ts4_word lv9;
    ts4_word p11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    c2 = (ts4_word)32;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 24));
    lv9 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 25)) + lv9) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((a1 + 25)) + lv9));
        p11 = (ts4_word)(lv9 + 1);
        lv9 = p11;
    } while (--c2 != 0);
    return;
}

/* Swing_DLL.xex 0x881AAFF8: loop_call_seq u16@0x0, u16@0x0, u32@0x4, u32@0x0, fn_881AC348 */
ts4_word ts4_loop_call_seq_u16_off0_881AAFF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p8;
    ts4_word p13;
    ts4_word p14;
    unsigned short t1;
    unsigned short t4;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 0);
    p8 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        lv2 = (ts4_word)a1;
        lv3 = (ts4_word)0;
        do {
            t4 = *(unsigned short *)((char *)(ts4_word)((lv2 + 2)) + 0);
            p5 = (ts4_word)(lv2 + 2);
            p6 = (ts4_word)(lv3 + 1);
            lv2 = p5;
            lv3 = p6;
        } while ((ts4_word)t4 != 0);
        p8 = (ts4_word)lv3;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)p8 <= (ts4_word)((int)(t10 - t11) >> 1)) {
        t12 = fn_881AC348((ts4_word)t11, (ts4_word)t10, (ts4_word)a1, (ts4_word)((p8 << 1) + a1));
        if ((ts4_word)t12 != (ts4_word)t10) {
            p13 = (ts4_word)((int)(t12 - t11) >> 1);
        } else {
            p13 = (ts4_word)-1;
        }
        p14 = (ts4_word)p13;
    } else {
        p14 = (ts4_word)-1;
    }
    return p14;
}

/* Swing_DLL.xex 0x881CB498: loop_get u32@0x0, u32@0x0, vcall, u32@0x8, u32@0x8, u32@0x8 */
ts4_word ts4_loop_get_u32_off0_881CB498(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    lv4 = (ts4_word)t3;
    do {
        if ((ts4_word)lv4 == (ts4_word)a1) {
            return 1;
        }
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 8));
        lv4 = p9;
    } while ((ts4_word)p9 != 0);
    return lv4;
}

/* Swing_DLL.xex 0x881D0878: loop_call_seq u32@0x28, u32@0x14, u32@0x14, ts4_loop_call_seq_u32_off28_881D0878, u32@0x18, u32@0x18 */
ts4_word ts4_loop_call_seq_u32_off28_881D0878(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p8;
    ts4_word p9;
    ts4_word p11;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)a1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        if ((ts4_word)t3 != 0) {
            lv4 = (ts4_word)t3;
            do {
                t5 = ((ts4_word (*)())ts4_loop_call_seq_u32_off28_881D0878)((ts4_word)lv4, (ts4_word)a1);
                if ((ts4_word)t5 != 0) {
                    return t5;
                }
                p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 24));
                lv4 = p8;
            } while ((ts4_word)p8 != 0);
            p9 = (ts4_word)0;
        } else {
            p9 = (ts4_word)0;
        }
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x881E2F68: call_seq fn_88837880, ts4_call_seq_u32_off10_88837820, fn_881B19A0, ts4_call_seq_u32_off10_88837820, fn_881B19A0, ts4_call_seq_u32_off10_88837820 */
ts4_word ts4_call_seq_fn_88837880_881E2F68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[8];
    ts4_word loc70[8];
    ts4_word loc90[8];
    ts4_word locb0[8];
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;

    fn_88837880((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    *(float *)((char *)(ts4_word)(a2) + 0) = ((float)(*(double *)((char *)(ts4_word)(t2) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    t5 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&loc90[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)2);
    *(float *)((char *)(ts4_word)(a2) + 4) = ((float)(*(double *)((char *)(ts4_word)(t5) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&loc90[0]);
    t8 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&locb0[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)3);
    *(float *)((char *)(ts4_word)(a2) + 8) = ((float)(*(double *)((char *)(ts4_word)(t8) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&locb0[0]);
    fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x881E39E0: if_call_seq fn_881991A0, fn_881E3988, fn_881992A8 */
ts4_word ts4_if_call_seq_fn_881991A0_881E39E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t1;

    (void)a0;
    (void)a2;
    if ((ts4_word)a3 == 0) {
        fn_881992A8((ts4_word)0);
        return 0;
    }
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)1000;
    loc58[0] = (ts4_word)0;
    *(unsigned char *)((char *)loc58 + 4) = (unsigned char)0;
    t1 = fn_881991A0((ts4_word)a1, (ts4_word)a3, (ts4_word)(ts4_word)&loc50[0]);
    fn_881E3988((ts4_word)(ts4_word)&loc58[0]);
    return t1;
}

/* Swing_DLL.xex 0x881F1598: if_get u32@0x24, ts4_dynamic_cast_by_class_881F1A50, ts4_dynamic_cast_by_class_881F1AC8, u32@0x0, u32@0x0, u32@0x34 */
ts4_word ts4_if_get_u32_off24_881F1598(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    t2 = ts4_dynamic_cast_by_class_881F1A50((ts4_word)(t1 + 20));
    t3 = ts4_dynamic_cast_by_class_881F1AC8((ts4_word)(t1 + 20));
    if ((ts4_word)(t1 + 20) != 0) {
        if ((ts4_word)t2 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 68);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t6;
            if ((ts4_word)t6 != 0) {
                _InterlockedIncrement((volatile long *)(ts4_word)((t6 + 4)));
                return a0;
            }
            return a0;
        }
        if ((ts4_word)t3 != 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 52);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
            if ((ts4_word)t4 != 0) {
                _InterlockedIncrement((volatile long *)(ts4_word)((t4 + 4)));
                return a0;
            }
            return a0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x881F2898: call_seq fn_881F5D60, u32@0x0, u8@0x23, u8@0x23 */
ts4_word ts4_call_seq_fn_881F5D60_881F2898(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;

    (void)a0;
    t1 = fn_881F5D60((ts4_word)a1);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a2) + 0));
    t3 = loc50[0];
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t3;
    *(volatile unsigned char *)((char *)(ts4_word)(a1) + 35) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 35)) | 128);
    return t1;
}

/* Swing_DLL.xex 0x881F4C00: loop_get u32@0x14, u32@0x18, ts4_loop_get_u32_off14_881F4C00, u32@0x0, u32@0x4, vcall */
ts4_word ts4_loop_get_u32_off14_881F4C00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p9 = (ts4_word)a0;
    lv2 = (ts4_word)t1;
    while ((ts4_word)lv2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 24);
        ((ts4_word (*)())ts4_loop_get_u32_off14_881F4C00)((ts4_word)lv2);
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv2) + 0))) + 4))))((ts4_word)lv2, (ts4_word)0);
        p8 = (ts4_word)t3;
        lv2 = p8;
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x881F59C8: loop_get u32@0x0, u32@0x30, vcall, u32@0x14, ts4_loop_get_u32_off0_881F59C8, u32@0x18 */
ts4_word ts4_loop_get_u32_off0_881F59C8(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p8;
    ts4_word p9;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p9 = (ts4_word)t3;
    lv5 = (ts4_word)t4;
    while ((ts4_word)lv5 != 0) {
        t6 = ts4_loop_get_u32_off0_881F59C8((ts4_word)lv5);
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 24));
        lv5 = p8;
        p9 = (ts4_word)t6;
    }
    return p9;
}

/* Swing_DLL.xex 0x881F8AD0: if_get u32@0x14, u32@0xc, u32@0xc, u32@0xc, ts4_if_get_u32_off14_881F8AD0, u32@0xc */
ts4_word ts4_if_get_u32_off14_881F8AD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        p13 = (ts4_word)(t1 + 1);
        p14 = (ts4_word)a0;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t3 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 12)) != 0) {
            ((ts4_word (*)())ts4_if_get_u32_off14_881F8AD0)((ts4_word)t3);
        }
        t9 = fn_881C8958((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 16)));
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t9;
        p12 = (ts4_word)t9;
        if ((ts4_word)t10 != 0) {
            t11 = ((ts4_word (*)(ts4_word))(t10))((ts4_word)t9);
            p12 = (ts4_word)t11;
        }
        p13 = (ts4_word)1;
        p14 = (ts4_word)p12;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)p13;
    return p14;
}

/* Swing_DLL.xex 0x8820EF88: if_addr lbl_880C1320, fn_8819B148, u32@0x0, u32@0x54, fn_881AA7A0, u32@0x54 */
ts4_word ts4_if_addr_lbl_880C1320_8820EF88(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t20;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    float t13;
    ts4_word t14;
    ts4_word t18;

    fn_8819B148((ts4_word)(a0 + 80), (ts4_word)(ts4_word)lbl_880C1320);
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    fn_881AA7A0((ts4_word)(ts4_word)&loc50[0]);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t4 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
        *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)g_ts4_script_constants);
        t20 = ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        return t20;
    }
    t7 = *(ts4_word *)lbl_88D41FC4;
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 240);
    if ((ts4_word)t8 != 0) {
        t9 = fn_881EC6D8((ts4_word)t7, (ts4_word)(a0 + 84), (ts4_word)(ts4_word)&loc50[0]);
        p10 = (ts4_word)t9;
    } else {
        p10 = (ts4_word)0;
    }
    if ((ts4_word)(p10 & 0xff) != 0) {
        t12 = loc50[1];
        if ((ts4_word)t12 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)t12;
        }
        t13 = *(float *)((char *)loc50 + 8);
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(float *)((char *)(ts4_word)(a0) + 96) = t13;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 92))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    }
    t18 = ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
    return t18;
}

/* Swing_DLL.xex 0x882109B8: loop_get u32@0x10, u32@0x4, vcall, u32@0x4, u32@0x8, u32@0x0 */
ts4_word ts4_loop_get_u32_off10_882109B8(ts4_word a0)
{
    ts4_word lv9;
    ts4_word p17;
    ts4_word p21;
    ts4_word t4;
    ts4_word t5;
    int t13;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 4))))((ts4_word)(a0 + 16));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != (ts4_word)t5) {
        lv9 = (ts4_word)t4;
        do {
            t13 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv9) + 0))) + 36);
            if ((int)t13 == 2 || (int)t13 == 4) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
                return 1;
            }
            p17 = (ts4_word)(lv9 + 4);
            lv9 = p17;
        } while ((ts4_word)p17 != (ts4_word)t5);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
        p21 = (ts4_word)0;
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
        p21 = (ts4_word)0;
    }
    return p21;
}

/* Swing_DLL.xex 0x88210A68: loop_get u32@0x10, u32@0x4, vcall, u32@0x4, u32@0x8, u32@0x0 */
ts4_word ts4_loop_get_u32_off10_88210A68(ts4_word a0)
{
    ts4_word lv9;
    ts4_word p17;
    ts4_word p21;
    ts4_word t4;
    ts4_word t5;
    int t13;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 4))))((ts4_word)(a0 + 16));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != (ts4_word)t5) {
        lv9 = (ts4_word)t4;
        do {
            t13 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv9) + 0))) + 36);
            if ((int)t13 == 32 || (int)t13 == 16) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
                return 1;
            }
            p17 = (ts4_word)(lv9 + 4);
            lv9 = p17;
        } while ((ts4_word)p17 != (ts4_word)t5);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
        p21 = (ts4_word)0;
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 8))))((ts4_word)(a0 + 16));
        p21 = (ts4_word)0;
    }
    return p21;
}

/* Swing_DLL.xex 0x88224F10: get u8@0xc, u8@0xc, u8@0xd, u8@0xd, u8@0xe, u8@0xe */
void ts4_get_u8_offc_88224F10(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    *(unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 14));
    *(unsigned char *)((char *)(ts4_word)(a0) + 15) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 15));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 16));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 24));
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 41));
    *(unsigned char *)((char *)(ts4_word)(a0) + 42) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 42));
    *(unsigned char *)((char *)(ts4_word)(a0) + 43) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 43));
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 45) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 45));
    *(unsigned char *)((char *)(ts4_word)(a0) + 46) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 46));
    *(unsigned char *)((char *)(ts4_word)(a0) + 47) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 47));
    return;
}

/* Swing_DLL.xex 0x88224FB0: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88224FB0(ts4_word a0, ts4_word a1)
{
    float t15;
    float t16;
    float t17;
    float t18;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 24));
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 25));
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 26));
    *(unsigned char *)((char *)(ts4_word)(a0) + 27) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 27));
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 29));
    *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 30));
    *(unsigned char *)((char *)(ts4_word)(a0) + 31) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 31));
    t15 = *(float *)((char *)(ts4_word)(a1) + 32);
    t16 = *(float *)((char *)(ts4_word)(a1) + 44);
    t17 = *(float *)((char *)(ts4_word)(a1) + 40);
    t18 = *(float *)((char *)(ts4_word)(a1) + 36);
    *(float *)((char *)(ts4_word)(a0) + 32) = t15;
    *(float *)((char *)(ts4_word)(a0) + 36) = t18;
    *(float *)((char *)(ts4_word)(a0) + 40) = t17;
    *(float *)((char *)(ts4_word)(a0) + 44) = t16;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 84));
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 96));
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 108));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 132));
    *(unsigned char *)((char *)(ts4_word)(a0) + 133) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 133));
    *(unsigned char *)((char *)(ts4_word)(a0) + 134) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 134));
    *(unsigned char *)((char *)(ts4_word)(a0) + 135) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 135));
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 136));
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 137));
    *(unsigned char *)((char *)(ts4_word)(a0) + 138) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 138));
    *(unsigned char *)((char *)(ts4_word)(a0) + 139) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 139));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 140));
    *(unsigned char *)((char *)(ts4_word)(a0) + 141) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 141));
    *(unsigned char *)((char *)(ts4_word)(a0) + 142) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 142));
    *(unsigned char *)((char *)(ts4_word)(a0) + 143) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 143));
    return;
}

/* Swing_DLL.xex 0x88225150: get u8@0x18, u8@0x18, u8@0x19, u8@0x19, u8@0x1a, u8@0x1a */
float ts4_get_u8_off18_88225150(ts4_word a0, ts4_word a1)
{
    float t24;

    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 24));
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 25));
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 26));
    *(unsigned char *)((char *)(ts4_word)(a0) + 27) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 27));
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 29));
    *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 30));
    *(unsigned char *)((char *)(ts4_word)(a0) + 31) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 31));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 32));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 40) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    *(float *)((char *)(ts4_word)(a0) + 56) = (*(float *)((char *)(ts4_word)(a1) + 56));
    *(float *)((char *)(ts4_word)(a0) + 60) = (*(float *)((char *)(ts4_word)(a1) + 60));
    *(float *)((char *)(ts4_word)(a0) + 64) = (*(float *)((char *)(ts4_word)(a1) + 64));
    *(float *)((char *)(ts4_word)(a0) + 68) = (*(float *)((char *)(ts4_word)(a1) + 68));
    *(float *)((char *)(ts4_word)(a0) + 72) = (*(float *)((char *)(ts4_word)(a1) + 72));
    t24 = *(float *)((char *)(ts4_word)(a1) + 76);
    *(float *)((char *)(ts4_word)(a0) + 76) = t24;
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 80));
    *(float *)((char *)(ts4_word)(a0) + 84) = (*(float *)((char *)(ts4_word)(a1) + 84));
    *(float *)((char *)(ts4_word)(a0) + 88) = (*(float *)((char *)(ts4_word)(a1) + 88));
    *(float *)((char *)(ts4_word)(a0) + 92) = (*(float *)((char *)(ts4_word)(a1) + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 96));
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 108));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 132));
    *(unsigned char *)((char *)(ts4_word)(a0) + 133) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 133));
    *(unsigned char *)((char *)(ts4_word)(a0) + 134) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 134));
    *(unsigned char *)((char *)(ts4_word)(a0) + 135) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 135));
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 136));
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 137));
    *(unsigned char *)((char *)(ts4_word)(a0) + 138) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 138));
    *(unsigned char *)((char *)(ts4_word)(a0) + 139) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 139));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 140));
    *(unsigned char *)((char *)(ts4_word)(a0) + 141) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 141));
    *(unsigned char *)((char *)(ts4_word)(a0) + 142) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 142));
    *(unsigned char *)((char *)(ts4_word)(a0) + 143) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 143));
    return t24;
}

/* Swing_DLL.xex 0x882344C8: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_882344C8(ts4_word a0, ts4_word a1)
{
    float t21;
    float t22;
    float t23;
    float t24;
    float t25;
    float t26;
    float t27;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    t21 = *(float *)((char *)(ts4_word)(a1) + 80);
    t22 = *(float *)((char *)(ts4_word)(a1) + 92);
    t23 = *(float *)((char *)(ts4_word)(a1) + 88);
    t24 = *(float *)((char *)(ts4_word)(a1) + 84);
    *(float *)((char *)(ts4_word)(a0) + 80) = t21;
    *(float *)((char *)(ts4_word)(a0) + 84) = t24;
    *(float *)((char *)(ts4_word)(a0) + 88) = t23;
    *(float *)((char *)(ts4_word)(a0) + 92) = t22;
    t25 = *(float *)((char *)(ts4_word)(a1) + 108);
    t26 = *(float *)((char *)(ts4_word)(a1) + 104);
    t27 = *(float *)((char *)(ts4_word)(a1) + 100);
    *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)((char *)(ts4_word)(a1) + 96));
    *(float *)((char *)(ts4_word)(a0) + 100) = t27;
    *(float *)((char *)(ts4_word)(a0) + 104) = t26;
    *(float *)((char *)(ts4_word)(a0) + 108) = t25;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 112));
    *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 116));
    *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 117));
    *(unsigned char *)((char *)(ts4_word)(a0) + 118) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 118));
    *(unsigned char *)((char *)(ts4_word)(a0) + 119) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 119));
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 120));
    *(unsigned char *)((char *)(ts4_word)(a0) + 121) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 121));
    *(unsigned char *)((char *)(ts4_word)(a0) + 122) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 122));
    *(unsigned char *)((char *)(ts4_word)(a0) + 123) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 123));
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 124));
    *(unsigned char *)((char *)(ts4_word)(a0) + 125) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 125));
    *(unsigned char *)((char *)(ts4_word)(a0) + 126) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 126));
    *(unsigned char *)((char *)(ts4_word)(a0) + 127) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 127));
    return;
}

/* Swing_DLL.xex 0x8823FEF8: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
float ts4_get_u32_off0_8823FEF8(ts4_word a0, ts4_word a1)
{
    float t20;
    float t21;
    float t22;
    float t23;
    float t33;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 60));
    *(unsigned char *)((char *)(ts4_word)(a0) + 61) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 61));
    *(unsigned char *)((char *)(ts4_word)(a0) + 62) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 62));
    *(unsigned char *)((char *)(ts4_word)(a0) + 63) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 63));
    t20 = *(float *)((char *)(ts4_word)(a1) + 64);
    t21 = *(float *)((char *)(ts4_word)(a1) + 76);
    t22 = *(float *)((char *)(ts4_word)(a1) + 72);
    t23 = *(float *)((char *)(ts4_word)(a1) + 68);
    *(float *)((char *)(ts4_word)(a0) + 64) = t20;
    *(float *)((char *)(ts4_word)(a0) + 68) = t23;
    *(float *)((char *)(ts4_word)(a0) + 72) = t22;
    *(float *)((char *)(ts4_word)(a0) + 76) = t21;
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 80));
    *(float *)((char *)(ts4_word)(a0) + 84) = (*(float *)((char *)(ts4_word)(a1) + 84));
    *(float *)((char *)(ts4_word)(a0) + 88) = (*(float *)((char *)(ts4_word)(a1) + 88));
    *(float *)((char *)(ts4_word)(a0) + 92) = (*(float *)((char *)(ts4_word)(a1) + 92));
    *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)((char *)(ts4_word)(a1) + 96));
    *(float *)((char *)(ts4_word)(a0) + 100) = (*(float *)((char *)(ts4_word)(a1) + 100));
    *(float *)((char *)(ts4_word)(a0) + 104) = (*(float *)((char *)(ts4_word)(a1) + 104));
    *(float *)((char *)(ts4_word)(a0) + 108) = (*(float *)((char *)(ts4_word)(a1) + 108));
    *(float *)((char *)(ts4_word)(a0) + 112) = (*(float *)((char *)(ts4_word)(a1) + 112));
    t33 = *(float *)((char *)(ts4_word)(a1) + 116);
    *(float *)((char *)(ts4_word)(a0) + 116) = t33;
    *(unsigned char *)((char *)(ts4_word)(a0) + 120) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 120));
    *(unsigned char *)((char *)(ts4_word)(a0) + 121) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 121));
    *(unsigned char *)((char *)(ts4_word)(a0) + 122) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 122));
    *(unsigned char *)((char *)(ts4_word)(a0) + 123) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 123));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 132));
    *(unsigned char *)((char *)(ts4_word)(a0) + 133) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 133));
    *(unsigned char *)((char *)(ts4_word)(a0) + 134) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 134));
    *(unsigned char *)((char *)(ts4_word)(a0) + 135) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 135));
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 136));
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 137));
    *(unsigned char *)((char *)(ts4_word)(a0) + 138) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 138));
    *(unsigned char *)((char *)(ts4_word)(a0) + 139) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 139));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 140));
    *(unsigned char *)((char *)(ts4_word)(a0) + 141) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 141));
    *(unsigned char *)((char *)(ts4_word)(a0) + 142) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 142));
    *(unsigned char *)((char *)(ts4_word)(a0) + 143) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 143));
    return t33;
}

/* Swing_DLL.xex 0x88260088: get u32@0x4, u32@0x4, u32@0x8, u32@0x8, u8@0xc, u8@0xc */
void ts4_get_u32_off4_88260088(ts4_word a0, ts4_word a1)
{
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;
    __vector4 vv15;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    vv5 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv5;
    vv6 = *(__vector4 *)((ts4_word)(a1 + 32));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    vv10 = *(__vector4 *)((ts4_word)(a1 + 80));
    *(__vector4 *)((ts4_word)(a0 + 80)) = vv10;
    vv11 = *(__vector4 *)((ts4_word)(a1 + 96));
    *(__vector4 *)((ts4_word)(a0 + 96)) = vv11;
    vv12 = *(__vector4 *)((ts4_word)(a1 + 112));
    *(__vector4 *)((ts4_word)(a0 + 112)) = vv12;
    *(float *)((char *)(ts4_word)(a0) + 128) = (*(float *)((char *)(ts4_word)(a1) + 128));
    *(float *)((char *)(ts4_word)(a0) + 132) = (*(float *)((char *)(ts4_word)(a1) + 132));
    vv15 = *(__vector4 *)((ts4_word)(a1 + 144));
    *(__vector4 *)((ts4_word)(a0 + 144)) = vv15;
    return;
}

/* Swing_DLL.xex 0x88260678: get u32@0x4, u32@0x4, u32@0x8, u32@0x8, u8@0xc, u8@0xc */
void ts4_get_u32_off4_88260678(ts4_word a0, ts4_word a1)
{
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv22;
    __vector4 vv23;
    __vector4 vv25;
    __vector4 vv26;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    vv5 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv5;
    vv6 = *(__vector4 *)((ts4_word)(a1 + 32));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 64) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 64));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 72) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 72));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 80) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 80));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 88) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 88));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 96) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 96));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 104) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 104));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 112) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 112));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 120) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 120));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 128) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 128));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 136) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 136));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 144) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 144));
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 152) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 152));
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 160));
    vv22 = *(__vector4 *)((ts4_word)(a1 + 176));
    *(__vector4 *)((ts4_word)(a0 + 176)) = vv22;
    vv23 = *(__vector4 *)((ts4_word)(a1 + 192));
    *(__vector4 *)((ts4_word)(a0 + 192)) = vv23;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 208));
    vv25 = *(__vector4 *)((ts4_word)(a1 + 224));
    *(__vector4 *)((ts4_word)(a0 + 224)) = vv25;
    vv26 = *(__vector4 *)((ts4_word)(a1 + 240));
    *(__vector4 *)((ts4_word)(a0 + 240)) = vv26;
    *(float *)((char *)(ts4_word)(a0) + 256) = (*(float *)((char *)(ts4_word)(a1) + 256));
    *(float *)((char *)(ts4_word)(a0) + 260) = (*(float *)((char *)(ts4_word)(a1) + 260));
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 264));
    *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 268));
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 272));
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 276));
    *(unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 280));
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 284));
    return;
}

/* Swing_DLL.xex 0x882625F0: get u32@0x40, u32@0x40, u32@0x44, u32@0x44, u32@0x48, u32@0x48 */
float ts4_get_u32_off40_882625F0(ts4_word a0, ts4_word a1)
{
    __vector4 vv5;
    __vector4 vv9;
    ts4_word locm10[4];
    float t1;
    float t2;
    float t3;
    float t4;
    float t6;
    float t7;
    float t8;
    float t17;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a1) + 4);
    *(float *)((char *)locm10 + 0) = t1;
    t3 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)locm10 + 4) = t2;
    t4 = *(float *)lbl_8814B440;
    *(float *)((char *)locm10 + 12) = t4;
    *(float *)((char *)locm10 + 8) = t3;
    vv5 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    *(__vector4 *)((ts4_word)(a0)) = vv5;
    t6 = *(float *)((char *)(ts4_word)(a1) + 16);
    t7 = *(float *)((char *)(ts4_word)(a1) + 20);
    t8 = *(float *)((char *)(ts4_word)(a1) + 24);
    *(float *)((char *)locm10 + 12) = t4;
    *(float *)((char *)locm10 + 0) = t6;
    *(float *)((char *)locm10 + 4) = t7;
    *(float *)((char *)locm10 + 8) = t8;
    vv9 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv9;
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    *(float *)((char *)(ts4_word)(a0) + 56) = (*(float *)((char *)(ts4_word)(a1) + 56));
    t17 = *(float *)((char *)(ts4_word)(a1) + 60);
    *(float *)((char *)(ts4_word)(a0) + 60) = t17;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 80));
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 84));
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 92));
    *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)((char *)(ts4_word)(a1) + 96));
    *(float *)((char *)(ts4_word)(a0) + 100) = (*(float *)((char *)(ts4_word)(a1) + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
    *(float *)((char *)(ts4_word)(a0) + 108) = (*(float *)((char *)(ts4_word)(a1) + 108));
    *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 112));
    *(unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 113));
    *(unsigned char *)((char *)(ts4_word)(a0) + 114) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 114));
    *(unsigned char *)((char *)(ts4_word)(a0) + 115) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 115));
    *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 116));
    *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 117));
    *(unsigned char *)((char *)(ts4_word)(a0) + 118) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 118));
    *(unsigned char *)((char *)(ts4_word)(a0) + 119) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 119));
    return t17;
}

/* Swing_DLL.xex 0x8827E658: loop_get fn_8827DC68, u32@0x0, u32@0x2c, u32@0x28, u32@0x4, u32@0x0 */
ts4_word ts4_loop_get_fn_8827DC68_8827E658(ts4_word a0, ts4_word a1)
{
    ts4_word lv6;
    ts4_word p12;
    ts4_word p15;
    ts4_word p17;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    t1 = fn_8827DC68();
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p17 = (ts4_word)t1;
    if ((int)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        p15 = (ts4_word)t1;
        if ((ts4_word)t3 != (ts4_word)t4) {
            t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
            lv6 = (ts4_word)t4;
            do {
                t8 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
                if ((ts4_word)t5 == (ts4_word)t8) {
                    t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 88))))((ts4_word)t5, (ts4_word)a1);
                    return t11;
                }
                p12 = (ts4_word)(lv6 + 4);
                lv6 = p12;
            } while ((ts4_word)t3 != (ts4_word)p12);
            p15 = (ts4_word)t5;
        }
        p17 = (ts4_word)p15;
    }
    return p17;
}

/* Swing_DLL.xex 0x882864E8: loop_addr lbl_880F8C74, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_loop_addr_lbl_880F8C74_882864E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p17;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    c1 = (ts4_word)a1;
    lv2 = (ts4_word)a0;
    do {
        if ((ts4_word)lv2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)(ts4_word)lbl_880F8C74;
            *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 4));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 8));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 12));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 16));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 20));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 24));
            *(ts4_word *)((char *)(ts4_word)(lv2) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 28));
            *(unsigned char *)((char *)(ts4_word)(lv2) + 32) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a2) + 32));
        }
        p17 = (ts4_word)(lv2 + 36);
        lv2 = p17;
    } while (--c1 != 0);
    return lv2;
}

/* Swing_DLL.xex 0x882885B0: if_get KeGetCurrentProcessType, u32@__imp_VdGlobalDevice, u32@__imp_VdGlobalXamDevice, u32@0x0, interlocked_inc, u32@0x0 */
ts4_word ts4_if_get_KeGetCurrentProcessType_882885B0(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    int t1;
    ts4_word t5;

    (void)a0;
    t1 = KeGetCurrentProcessType();
    if ((int)t1 == 2) {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalXamDevice);
    } else {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalDevice);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(p4) + 0);
    if ((ts4_word)t5 != 0) {
        _InterlockedIncrement((volatile long *)(ts4_word)((t5 + 60)));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t5;
    return t1;
}

/* Swing_DLL.xex 0x882ECD40: if_get u32@0x4, u32@0x0, u32@0x14, u32@0x0, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off4_882ECD40(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t16;
    ts4_word t24;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)a2 > (ts4_word)((999948288) | 51696)) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)54;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)3;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    p9 = (ts4_word)a2;
    if ((ts4_word)(a2 & 0x7) != 0) {
        p9 = (ts4_word)((a2 - (a2 & 0x7)) + 8);
    }
    if ((int)a1 < 0 || (int)a1 >= 2) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)14;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    t16 = ts4_jpeg_get_small_882F51D8((ts4_word)a0, (ts4_word)(p9 + 16));
    if ((ts4_word)t16 == 0) {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)54;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)4;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 76) = (ts4_word)((p9 + (*(ts4_word *)((char *)(ts4_word)(t1) + 76))) + 16);
    t24 = *(ts4_word *)((char *)(ts4_word)(((a1 + 15) << 2)) + t1);
    *(ts4_word *)((char *)(ts4_word)(t16) + 4) = (ts4_word)p9;
    *(ts4_word *)((char *)(ts4_word)(t16) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)t24;
    *(ts4_word *)((char *)(ts4_word)(((a1 + 15) << 2)) + t1) = (ts4_word)t16;
    return (t16 + 16);
}

/* Swing_DLL.xex 0x882EFEE8: call_seq u32@0x600, ts4_if_get_u32_off54c_882E71A0 */
ts4_word ts4_call_seq_u32_off600_882EFEE8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1536);
    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)((t1) >> 24);
    *(unsigned char *)((char *)loc50 + 1) = (unsigned char)((t1 >> 16) & 0xff);
    *(unsigned char *)((char *)loc50 + 2) = (unsigned char)((t1 >> 8) & 0xff);
    *(unsigned char *)((char *)loc50 + 3) = (unsigned char)t1;
    t2 = ts4_if_get_u32_off54c_882E71A0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4);
    return t2;
}

/* Swing_DLL.xex 0x88314370: if_call_seq u32@0x0, u32@0x4, u32@0x4, fn_8830E6C8, u32@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88314370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p17;
    ts4_word p23;
    ts4_word p29;
    ts4_word p35;
    ts4_word t1;
    int t3;
    ts4_word t4;
    int t6;
    int t8;
    unsigned char t10;
    ts4_word t16;
    ts4_word t18;
    ts4_word t20;
    ts4_word t24;
    ts4_word t26;
    ts4_word t30;
    ts4_word t32;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p17 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p5 = (ts4_word)t1;
        if ((int)t3 != 8) {
            t4 = fn_8830E6C8((ts4_word)t1, (ts4_word)t3);
            p5 = (ts4_word)t4;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((int)t6 != 12) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 1184) = (ts4_word)t6;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((int)t8 != 0) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 1188) = (ts4_word)t8;
        }
        t10 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t10 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 21)) == 0) {
            ts4_if_call_seq_u32_lbl_88B3302C_883323B8((ts4_word)p5);
        }
        t16 = fn_8830F378((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)0);
        p17 = (ts4_word)t16;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p23 = (ts4_word)p17;
    if ((ts4_word)t18 != 0) {
        t20 = ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t18) + 0)), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0) = (ts4_word)0;
        p23 = (ts4_word)t20;
    }
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p29 = (ts4_word)p23;
    if ((ts4_word)t24 != 0) {
        t26 = ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t24) + 0)), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 0) = (ts4_word)0;
        p29 = (ts4_word)t26;
    }
    t30 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p35 = (ts4_word)p29;
    if ((ts4_word)t30 != 0) {
        t32 = ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t30) + 0)), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0) = (ts4_word)0;
        p35 = (ts4_word)t32;
    }
    return p35;
}

/* Swing_DLL.xex 0x883200E8: if_get u32@0x1c4, u32@0x1dc, u32@0x1d8, vcall, u32@0x18c, u32@0x55d8 */
ts4_word ts4_if_get_u32_off1c4_883200E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 452);
    if ((ts4_word)t1 == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 396))) + 21976);
        if ((ts4_word)t6 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 476);
            ((ts4_word (*)(ts4_word, ts4_word))(t6))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 472)), (ts4_word)t7);
        }
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 476);
        ((ts4_word (*)(ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 472)), (ts4_word)t2);
    }
    return 0;
}

/* Swing_DLL.xex 0x8832C090: if_call_seq u32@0x0, u32@0x18, u32@0x0, u32@0x0, u32@0x224, u32@0x130 */
ts4_word ts4_if_call_seq_u32_off0_8832C090(ts4_word a0, int a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    int t5;

    (void)a5;
    if ((int)a1 >= 0 && (int)a1 < 4) {
        t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24);
        if ((ts4_word)t1 != 0) {
            if ((int)a2 >= 0) {
                t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 548))) + 304);
                if ((int)a2 < (int)t5) {
                    if ((ts4_word)a3 != 0) {
                        fn_8857ACB8((ts4_word)a3, (ts4_word)(((int)a2 * 84) + t1), (ts4_word)76);
                    }
                    if ((ts4_word)a4 != 0) {
                        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + (*(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24)))) + 76));
                    }
                    return 0;
                }
                if ((ts4_word)a4 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
                }
                return 37;
            }
            if ((ts4_word)a4 != 0) {
                *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
            }
            return 37;
        }
        if ((ts4_word)a4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
        }
        return 73;
    }
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
    }
    return 73;
}

/* Swing_DLL.xex 0x8832C160: if_call_seq u32@0x18, u32@0x224, u32@0x130, fn_8857ACB8, u32@0x18, u32@0x44 */
ts4_word ts4_if_call_seq_u32_off18_8832C160(ts4_word a0, int a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    int t3;
    ts4_word t5;
    ts4_word t7;

    (void)a5;
    if ((int)a1 >= 0 && (int)a1 < 4) {
        t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24);
        if ((ts4_word)t1 != 0) {
            if ((int)a2 >= 0) {
                t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 548))) + 304);
                if ((int)a2 < (int)t3) {
                    if ((ts4_word)a3 != 0) {
                        fn_8857ACB8((ts4_word)(((int)a2 * 84) + t1), (ts4_word)a3, (ts4_word)76);
                        t5 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24);
                        *(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + t5)) + 68) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + t5)) + 68)) & 0xffffff0f);
                        t7 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24);
                        *(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + t7)) + 68) = (ts4_word)((16 << a1) | (*(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + t7)) + 68)));
                    }
                    if ((ts4_word)a4 != 0) {
                        *(ts4_word *)((char *)(ts4_word)((((int)a2 * 84) + (*(ts4_word *)((char *)(ts4_word)((((int)a1 * 132) + a0)) + 24)))) + 76) = (ts4_word)a4;
                    }
                    return 0;
                }
                return 37;
            }
            return 37;
        }
        return 73;
    }
    return 73;
}

/* Swing_DLL.xex 0x88331908: if_call_seq fn_8832EDB0, u32@0x24, u32@lbl_88B330C4, fn_8832EDB0, u32@lbl_88B3302C, u32@0x5c */
ts4_word ts4_if_call_seq_fn_8832EDB0_88331908(ts4_word a0, ts4_word a1)
{
    ts4_word p15;
    ts4_word p22;
    ts4_word p24;
    ts4_word p29;
    ts4_word p34;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t17;
    ts4_word t18;
    ts4_word t26;
    ts4_word t31;
    ts4_word t36;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)48);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t2 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)(*(ts4_word *)lbl_88B330C4));
    }
    t6 = *(ts4_word *)lbl_88B3302C;
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 92);
    p24 = (ts4_word)t6;
    if ((ts4_word)t7 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)52);
        t9 = *(ts4_word *)lbl_88B3302C;
        t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 92);
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 24);
        p15 = (ts4_word)t9;
        if ((ts4_word)t11 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 28)) << 2));
            p15 = (ts4_word)(*(ts4_word *)lbl_88B3302C);
        }
        t17 = *(ts4_word *)((char *)(ts4_word)(p15) + 92);
        t18 = *(ts4_word *)((char *)(ts4_word)(t17) + 32);
        p22 = (ts4_word)p15;
        if ((ts4_word)t18 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)(((int)(*(ts4_word *)((char *)(ts4_word)(t17) + 48)) * 61) + 17));
            p22 = (ts4_word)(*(ts4_word *)lbl_88B3302C);
        }
        p24 = (ts4_word)p22;
    }
    t26 = *(ts4_word *)((char *)(ts4_word)(p24) + 88);
    p29 = (ts4_word)p24;
    if ((ts4_word)t26 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)24);
        p29 = (ts4_word)(*(ts4_word *)lbl_88B3302C);
    }
    t31 = *(ts4_word *)((char *)(ts4_word)(p29) + 84);
    p34 = (ts4_word)p29;
    if ((ts4_word)t31 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)24);
        p34 = (ts4_word)(*(ts4_word *)lbl_88B3302C);
    }
    t36 = *(ts4_word *)((char *)(ts4_word)(p34) + 80);
    if ((ts4_word)t36 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(65536), (ts4_word)24);
    }
    return 0;
}

/* Swing_DLL.xex 0x88335370: if_get u32@0x44, u32@0x104, fn_88376AD0 */
ts4_word ts4_if_get_u32_off44_88335370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    if ((ts4_word)a3 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 260);
        if ((ts4_word)t2 != 0) {
            return fn_88376AD0((ts4_word)t2);
        }
        return 78;
    }
    return 78;
}

/* Swing_DLL.xex 0x88343BF0: if_set u32@0x150 */
ts4_word ts4_if_set_u32_off150_88343BF0(ts4_word a0, ts4_word a1, float f1)
{
    float t1;
    float t2;
    ts4_word t4;
    float t5;

    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 < 3) {
                *(float *)((char *)(ts4_word)(a0) + 316) = f1;
            }
        } else {
            *(float *)((char *)(ts4_word)(a0) + 312) = f1;
        }
    } else {
        *(float *)((char *)(ts4_word)(a0) + 320) = f1;
    }
    t1 = *(float *)((char *)(ts4_word)(a0) + 320);
    t2 = *(float *)lbl_88001A20;
    if (!(t1 == t2)) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
        t5 = *(float *)lbl_88028BDC;
        *(float *)((char *)(ts4_word)(a0) + 324) = ((*(float *)lbl_88001A68) / ((((float)((double)((ts4_s64)(int)t4))) * t1) * t5));
        return 0;
    }
    *(float *)((char *)(ts4_word)(a0) + 324) = (*(float *)lbl_88001A68);
    return 0;
}

/* Swing_DLL.xex 0x8834E408: loop_call_seq u32@0x108, ts4_read_u8_to_u8_883199C0, u32@0x108, fn_88319C40, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off108_8834E408(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p9;
    ts4_word loc50[4];
    int t3;
    unsigned char t5;
    int t8;

    lv1 = (ts4_word)0;
    do {
        t3 = ts4_read_u8_to_u8_883199C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)), (ts4_word)(ts4_word)&loc50[0]);
        if ((int)t3 != 0) {
            return t3;
        }
        t5 = *(unsigned char *)((char *)loc50 + 0);
        p6 = (ts4_word)(lv1 + 1);
        lv1 = p6;
    } while ((((ts4_word)t5 == 32 || (ts4_word)t5 == 9) || (ts4_word)t5 == 10) || (ts4_word)t5 == 13);
    t8 = fn_88319C40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)), (ts4_word)-1, (ts4_word)1);
    p9 = (ts4_word)t8;
    if ((int)t8 == 0) {
        if ((ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(lv1 + -1);
        }
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x8836F668: loop_call_seq u32@0x14c, u32@0x148, u32@0x11c, fn_8832EDB0, u32@0x120, fn_8832EDB0 */
ts4_word ts4_loop_call_seq_u32_off14c_8836F668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p34;
    ts4_word lv66;
    ts4_word p69;
    ts4_word t1;
    ts4_word t8;
    ts4_word t12;
    ts4_word t15;
    ts4_word t18;
    ts4_word t19;
    ts4_word t24;
    ts4_word t27;
    ts4_word t31;
    int t33;
    ts4_word t37;
    ts4_word t38;
    ts4_word t43;
    ts4_word t46;
    ts4_word t50;
    ts4_word t54;
    ts4_word t58;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    if ((ts4_word)t1 != 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 328)) != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) << 2));
    }
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 288)));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 340);
    if ((ts4_word)t8 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) << 2));
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
    if ((ts4_word)t12 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)368);
        t15 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 364))) + 64);
        if ((ts4_word)t15 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)296);
        }
        t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
        t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 232);
        if ((ts4_word)t19 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 240)) + 16));
        }
    }
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
    if ((ts4_word)t24 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)300);
        t27 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 372))) + 64);
        if ((ts4_word)t27 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)296);
        }
        t31 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 372))) + 276);
        if ((ts4_word)t31 != 0) {
            t33 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
            p34 = (ts4_word)t33;
            if ((int)t33 <= 2) {
                p34 = (ts4_word)1;
            }
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)(((int)p34 * 18732) + 16));
        }
        t37 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
        t38 = *(ts4_word *)((char *)(ts4_word)(t37) + 292);
        if ((ts4_word)t38 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t37) + 240)) + 16));
        }
    }
    t43 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    if ((ts4_word)t43 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)752);
        t46 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 376))) + 64);
        if ((ts4_word)t46 != 0) {
            fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)296);
        }
    }
    t50 = *(ts4_word *)((char *)(ts4_word)(a0) + 220);
    if ((ts4_word)t50 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 224)));
    }
    t54 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    if ((ts4_word)t54 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 240)) + 16));
    }
    t58 = *(ts4_word *)((char *)(ts4_word)(a0) + 352);
    if ((ts4_word)t58 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) << 2));
    }
    ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)));
    lv66 = (ts4_word)(*(ts4_word *)lbl_88B36C18);
    while ((ts4_word)lv66 != (ts4_word)(ts4_word)lbl_88B36C18) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)128, (ts4_word)88);
        p69 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv66) + 0));
        lv66 = p69;
    }
    ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 48)));
    return 0;
}

/* Swing_DLL.xex 0x88384550: if_get u32@0x24, u32@0x54, u32@0x11c, u32@0x11c, u32@0x18, u32@0x18c */
ts4_word ts4_if_get_u32_off24_88384550(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t12;
    ts4_word t16;
    ts4_word t20;
    ts4_word t24;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)(t1 & 0x20) == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        *(ts4_word *)((char *)(ts4_word)(t2) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 284)) | 2);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 396);
            if ((ts4_word)t5 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t5) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 284)) | 2);
            }
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 768);
        if ((ts4_word)t12 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t12) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 284)) | 2);
        }
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 772);
        if ((ts4_word)t16 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t16) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 284)) | 2);
        }
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 780);
        if ((ts4_word)t20 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t20) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 284)) | 2);
        }
        t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t24 == 0) {
            return 0;
        }
        *(ts4_word *)((char *)(ts4_word)(t24) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t24) + 284)) | 2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8838DA88: if_call_seq u32@lbl_88C922FC, ts4_memset, ts4_tailcall_fn_884EFDD0_884EFE90, ts4_tailcall_fn_884F0178_884F0228, u32@lbl_88C922FC, u32@lbl_88C922FC */
ts4_word ts4_if_call_seq_u32_lbl_88C922FC_8838DA88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[4];
    ts4_word loc60[100];
    int t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88C922FC;
    if ((int)t1 == 0) {
        ts4_memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)13);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)13;
        *(unsigned char *)((char *)loc50 + 1) = (unsigned char)1;
        ts4_tailcall_fn_884EFDD0_884EFE90((ts4_word)(ts4_word)&loc50[0]);
        ts4_tailcall_fn_884F0178_884F0228((ts4_word)2, (ts4_word)(ts4_word)&loc60[0]);
        *(ts4_word *)lbl_88C922FC = (ts4_word)((*(ts4_word *)lbl_88C922FC) + 1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883BAF20: if_get u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_if_get_u32_off4_883BAF20(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 < 0) {
        return -1;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)(t2 + a1) > (int)t1) {
        return -1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + a1);
    return 0;
}

/* Swing_DLL.xex 0x883DBAF8: loop_get u32@0x10, u32@0x10, u32@0x0, u32@0x8, u32@0x10, u32@0x0 */
ts4_word ts4_loop_get_u32_off10_883DBAF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv5;
    ts4_word lv6;
    ts4_word p9;
    ts4_word p10;
    ts4_word t2;
    int t3;
    ts4_word t8;

    if ((ts4_word)a2 != 0 && (ts4_word)a1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t2 == 0) {
            return 81;
        }
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((int)t3 > 0) {
            lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
            lv6 = (ts4_word)0;
            do {
                t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
                if ((ts4_word)t8 == (ts4_word)a1) {
                    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)lv6;
                    return 0;
                }
                p9 = (ts4_word)(lv5 + 4);
                p10 = (ts4_word)(lv6 + 1);
                lv5 = p9;
                lv6 = p10;
            } while ((int)p10 < (int)t3);
            return 37;
        }
        return 37;
    }
    return 37;
}

/* Swing_DLL.xex 0x883DF9A0: if_call_seq u32@0x44, ts4_call_then_conditionally_forward_result_88317B90, u8@0x1c */
ts4_word ts4_if_call_seq_u32_off44_883DF9A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    p3 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_call_then_conditionally_forward_result_88317B90((ts4_word)t1, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)a1;
    return p3;
}

/* Swing_DLL.xex 0x88402008: loop_get u32@0x0, u32@0x10, u32@0x1c, u8@0x29, u8@0x28 */
void ts4_loop_get_u32_off0_88402008(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word p6;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16);
    if ((int)t2 > 0) {
        c3 = (ts4_word)t2;
        lv4 = (ts4_word)0;
        do {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv4) = (ts4_word)3;
            p6 = (ts4_word)(lv4 + 4);
            lv4 = p6;
        } while (--c3 != 0);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88402150: loop_get u32@0x0, u32@0x10, u32@0x1c, u8@0x28, u8@0x29 */
ts4_word ts4_loop_get_u32_off0_88402150(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word p6;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16);
    if ((int)t2 > 0) {
        c3 = (ts4_word)t2;
        lv4 = (ts4_word)0;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv4) = (ts4_word)2;
            p6 = (ts4_word)(lv4 + 4);
            lv4 = p6;
        } while (--c3 != 0);
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)1;
    return (a0 + 4);
}

/* Swing_DLL.xex 0x88402198: loop_get u32@0x0, u32@0x10, u32@0x1c, u8@0x29, u8@0x28 */
ts4_word ts4_loop_get_u32_off0_88402198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word p6;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16);
    if ((int)t2 > 0) {
        c3 = (ts4_word)t2;
        lv4 = (ts4_word)0;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv4) = (ts4_word)1;
            p6 = (ts4_word)(lv4 + 4);
            lv4 = p6;
        } while (--c3 != 0);
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)1;
    return (a0 + 16);
}

/* Swing_DLL.xex 0x88402978: loop_call_seq fn_884025C0, u32@0x0, u32@0x10, u32@0x1c, u8@0x28, u8@0x29 */
ts4_word ts4_loop_call_seq_fn_884025C0_88402978(ts4_word a0)
{
    ts4_word c4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word t1;
    int t3;

    t1 = fn_884025C0();
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16);
    if ((int)t3 > 0) {
        c4 = (ts4_word)t3;
        lv5 = (ts4_word)0;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv5) = (ts4_word)2;
            p7 = (ts4_word)(lv5 + 4);
            lv5 = p7;
        } while (--c4 != 0);
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)1;
    return (a0 + 4);
}

/* Swing_DLL.xex 0x884029E8: loop_call_seq fn_884027D8, u32@0x0, u32@0x10, u32@0x1c, u8@0x29, u8@0x28 */
ts4_word ts4_loop_call_seq_fn_884027D8_884029E8(ts4_word a0)
{
    ts4_word c4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word t1;
    int t3;

    t1 = fn_884027D8();
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16);
    if ((int)t3 > 0) {
        c4 = (ts4_word)t3;
        lv5 = (ts4_word)0;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv5) = (ts4_word)1;
            p7 = (ts4_word)(lv5 + 4);
            lv5 = p7;
        } while (--c4 != 0);
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)1;
    return (a0 + 16);
}

/* Swing_DLL.xex 0x8841AD18: if_get u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_u32_off0_8841AD18(ts4_word a0)
{
    ts4_word loc50[2];
    int t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    if ((int)t3 != 0) {
        return ((signed char)(*(unsigned char *)((char *)loc50 + 0)));
    }
    return -1;
}

/* Swing_DLL.xex 0x884553C8: if_get u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88462090, u32@0xc */
ts4_word ts4_if_get_u32_lbl_88CACF08_884553C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t5;
    ts4_word t8;
    ts4_word t17;
    ts4_word t20;
    ts4_word t30;
    ts4_word t31;
    ts4_word t26;
    ts4_word t27;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t10;
    ts4_word t11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    if ((ts4_word)a3 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        if ((ts4_word)t8 >= 1) {
            if ((ts4_word)t8 != 1) {
                if ((ts4_word)t8 < 3) {
                    t17 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
                    t20 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 0))) + 12))))((ts4_word)t17, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2);
                    if ((ts4_word)t20 >= 1) {
                        if ((ts4_word)t20 != 1) {
                            if ((ts4_word)t20 >= 3) {
                                return 0;
                            }
                            t30 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                            t31 = fn_8841A510((ts4_word)t30, (ts4_word)128, (ts4_word)31);
                            *(unsigned short *)((char *)(ts4_word)(t31) + 4) = (unsigned short)128;
                            ts4_call_seq_fn_88466AB0_88467768((ts4_word)t31, (ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
                            *(ts4_word *)((char *)(ts4_word)(t31) + 0) = (ts4_word)(ts4_word)lbl_88082540;
                            return t31;
                        }
                        t26 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                        t27 = fn_8841A510((ts4_word)t26, (ts4_word)56, (ts4_word)31);
                        *(unsigned short *)((char *)(ts4_word)(t27) + 4) = (unsigned short)56;
                        fn_88462090((ts4_word)t27, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
                        *(ts4_word *)((char *)(ts4_word)(t27) + 0) = (ts4_word)(ts4_word)lbl_88082070;
                        return t27;
                    }
                    t22 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                    t23 = fn_8841A510((ts4_word)t22, (ts4_word)144, (ts4_word)31);
                    *(unsigned short *)((char *)(ts4_word)(t23) + 4) = (unsigned short)144;
                    t24 = ts4_call_seq_fn_88467768_884544F8((ts4_word)t23, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
                    return t24;
                }
                return 0;
            }
            t14 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
            t15 = fn_8841A510((ts4_word)t14, (ts4_word)56, (ts4_word)31);
            *(unsigned short *)((char *)(ts4_word)(t15) + 4) = (unsigned short)56;
            t16 = fn_88462090((ts4_word)t15, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
            return t16;
        }
        t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t11 = fn_8841A510((ts4_word)t10, (ts4_word)144, (ts4_word)31);
        *(unsigned short *)((char *)(ts4_word)(t11) + 4) = (unsigned short)144;
        ts4_call_seq_fn_88467768_884544F8((ts4_word)t11, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
        *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)(ts4_word)lbl_88082644;
        return t11;
    }
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)56, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)56;
    t4 = fn_88462090((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    return t4;
}

/* Swing_DLL.xex 0x884569E0: call_seq lbl_88081F98, fn_884616C0 */
ts4_word ts4_call_seq_lbl_88081F98_884569E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    float t1;
    ts4_word t2;

    (void)a0;
    loc50[2] = (ts4_word)a4;
    loc60[2] = (ts4_word)(ts4_word)&loc50[0];
    t1 = *(float *)lbl_8803A3B0;
    loc50[0] = (ts4_word)(ts4_word)lbl_88081F98;
    *(float *)((char *)loc50 + 4) = t1;
    loc60[0] = (ts4_word)(ts4_word)lbl_88081F98;
    *(float *)((char *)loc60 + 4) = t1;
    t2 = fn_884616C0((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Swing_DLL.xex 0x88456A40: call_seq lbl_88081FB0, fn_88461C60 */
ts4_word ts4_call_seq_lbl_88081FB0_88456A40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t1;

    (void)a0;
    loc50[2] = (ts4_word)a4;
    *(unsigned char *)((char *)loc50 + 4) = (unsigned char)0;
    loc50[0] = (ts4_word)(ts4_word)lbl_88081FB0;
    *(unsigned char *)((char *)loc60 + 4) = (unsigned char)0;
    loc60[0] = (ts4_word)(ts4_word)lbl_88081FB0;
    loc60[2] = (ts4_word)(ts4_word)&loc50[0];
    t1 = fn_88461C60((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(ts4_word)&loc60[0]);
    return t1;
}

/* Swing_DLL.xex 0x88457B98: if_call_seq u32@0x14, u32@lbl_88CACF08, KeTlsGetValue, u32@0xc, fn_8841A590, lbl_8803A308 */
ts4_word ts4_if_call_seq_u32_off14_88457B98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)((t1 & 0x3fffffff) << 1), (ts4_word)23);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t8, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x8846BEB8: if_get u32@0x84, u32@0x0, u32@0xc, vcall, u32@0x7c, fn_88489498 */
ts4_word ts4_if_get_u32_off84_8846BEB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((int)t1 != 0) {
        loc50[1] = (ts4_word)a1;
        loc50[2] = (ts4_word)a2;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)34;
        fn_88489498((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)), (ts4_word)(ts4_word)&loc50[0]);
    } else {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12))))((ts4_word)a1, (ts4_word)a2);
    }
    return a1;
}

/* Swing_DLL.xex 0x88471EB8: if_call_seq u32@0x84, fn_88470870, u32@0x7c, fn_88489498 */
ts4_word ts4_if_call_seq_u32_off84_88471EB8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    int t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((int)t1 != 0) {
        loc50[1] = (ts4_word)a1;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)11;
        t4 = fn_88489498((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
        return t4;
    }
    t2 = fn_88470870();
    return t2;
}

/* Swing_DLL.xex 0x88473208: if_call_seq u32@0x8, u32@0x84, fn_88492220, ts4_get_u32_off7c_8846AA28 */
ts4_word ts4_if_call_seq_u32_off8_88473208(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    int t1;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        loc50[1] = (ts4_word)a0;
        *(unsigned char *)((char *)loc50 + 8) = (unsigned char)a1;
        *(unsigned char *)((char *)loc50 + 9) = (unsigned char)a2;
        *(unsigned char *)((char *)loc50 + 10) = (unsigned char)a3;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)4;
        t4 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        return t4;
    }
    t3 = fn_88492220();
    return t3;
}

/* Swing_DLL.xex 0x884742C0: if_call_seq u32@0x8, u32@0x84, fn_88474120, ts4_get_u32_off7c_8846AA28 */
ts4_word ts4_if_call_seq_u32_off8_884742C0(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        loc50[1] = (ts4_word)a0;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)32;
        t4 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        return t4;
    }
    t3 = fn_88474120((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x88474320: if_call_seq u32@0x8, u32@0x84, fn_884741B0, ts4_get_u32_off7c_8846AA28 */
ts4_word ts4_if_call_seq_u32_off8_88474320(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        loc50[1] = (ts4_word)a0;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)33;
        t4 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        return t4;
    }
    t3 = fn_884741B0((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x8847AC48: fn  */
void ts4_fn_8847AC48(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    vv2 = *(__vector4 *)((ts4_word)((a0 + 224)));
    vv3 = *(__vector4 *)((ts4_word)(a0 + 192));
    vv4 = __vmaddfp(vv3, vv1, vv2);
    *(__vector4 *)((ts4_word)((a0 + 224))) = vv4;
    return;
}

/* Swing_DLL.xex 0x88485C40: fn  */
void ts4_fn_88485C40(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    vv2 = *(__vector4 *)((ts4_word)((a0 + 224)));
    vv3 = *(__vector4 *)((ts4_word)(a0 + 192));
    vv4 = __vmaddfp(vv3, vv1, vv2);
    *(__vector4 *)((ts4_word)((a0 + 224))) = vv4;
    return;
}

/* Swing_DLL.xex 0x8849E770: if_call_seq u8@0x1d, u16@0x2, u32@0x4, u32@0x8, fn_8849EF70 */
ts4_word ts4_if_call_seq_u8_off1d_8849E770(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word loc50[6];
    unsigned char t1;
    unsigned short t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 29);
    p6 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(unsigned short *)((char *)(ts4_word)(a0) + 2);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(unsigned short *)((char *)loc50 + 0) = (unsigned short)5;
        *(unsigned short *)((char *)loc50 + 2) = (unsigned short)t2;
        loc50[1] = (ts4_word)t3;
        loc50[2] = (ts4_word)t4;
        t5 = fn_8849EF70((ts4_word)(a2 + 20), (ts4_word)(ts4_word)&loc50[0]);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x884B4F10: loop_call_seq lbl_88089254, u32@0x0, fn_88423CE0, fn_884235C0, fn_88424050, u32@0x0 */
ts4_word ts4_loop_call_seq_lbl_88089254_884B4F10(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p8;
    ts4_word p9;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88089254;
    fn_88423CE0((ts4_word)(a0 + 4));
    fn_884235C0((ts4_word)(a0 + 4));
    fn_88424050((ts4_word)(a0 + 4), (ts4_word)a2);
    if ((int)a2 > 0) {
        lv4 = (ts4_word)(a1 + -4);
        lv5 = (ts4_word)a2;
        do {
            fn_88423660((ts4_word)(a0 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv4 + 4)) + 0)), (ts4_word)1);
            p8 = (ts4_word)(lv4 + 4);
            p9 = (ts4_word)(lv5 + -1);
            lv4 = p8;
            lv5 = p9;
        } while ((int)p9 != 0);
    }
    return a0;
}

/* Swing_DLL.xex 0x884C9620: loop_get u32@0x34, u32@0x38, u32@0x0 */
void ts4_loop_get_u32_off34_884C9620(ts4_word a0, int a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p4;
    ts4_word t3;

    if ((int)a1 <= 0) {
        return;
    }
    c1 = (ts4_word)a1;
    lv2 = (ts4_word)(a0 + -12);
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 52);
        *(ts4_word *)((char *)(ts4_word)(lv2) + 56) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 48)) + 0) = (ts4_word)t3;
        p4 = (ts4_word)(lv2 + 48);
        lv2 = p4;
    } while (--c1 != 0);
    return;
}

/* Swing_DLL.xex 0x884F6450: atomic interlocked_xchg */
ts4_word ts4_atomic_interlocked_xchg_884F6450(ts4_word a0, ts4_word a1)
{
    _InterlockedExchange((volatile long *)(ts4_word)((a0 + 292)), (long)a1);
    return 0;
}

/* Swing_DLL.xex 0x88509CE0: fn  */
__vector4 ts4_fn_88509CE0(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = *(__vector4 *)((ts4_word)(a0 + a1));
    return vv1;
}

/* Swing_DLL.xex 0x8850B758: fn  */
__vector4 ts4_fn_8850B758(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = *(__vector4 *)((ts4_word)(a0 + a1));
    return vv1;
}

/* Swing_DLL.xex 0x8851FAD0: fn  */
void ts4_fn_8851FAD0(ts4_word a0, ts4_word a1, __vector4 vp1)
{
    *(__vector4 *)((ts4_word)(a0 + a1)) = vp1;
    return;
}

/* Swing_DLL.xex 0x88582148: call_seq RtlInitAnsiString, ts4_get_u16_off0_8858B248 */
ts4_word ts4_call_seq_RtlInitAnsiString_88582148(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t2;

    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    *(unsigned short *)((char *)loc50 + 2) = (unsigned short)0;
    loc50[1] = (ts4_word)0;
    RtlInitAnsiString((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = ts4_get_u16_off0_8858B248((ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x885862F0: if_set u32@0x88, u32@0xd0, u32@0xd4, vcall, u32@0xd0 */
ts4_word ts4_if_set_u32_off88_885862F0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)a1;
    p6 = (ts4_word)a0;
    if ((int)a1 < 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
        p5 = (ts4_word)a0;
        if ((ts4_word)t1 != 0) {
            t3 = ((ts4_word (*)(ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
            p5 = (ts4_word)t3;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88593EC0: atomic interlocked_inc */
ts4_word ts4_atomic_interlocked_inc_88593EC0(ts4_word a0)
{
    ts4_word t1;

    t1 = _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 4)));
    return t1;
}

/* Swing_DLL.xex 0x88595FD8: atomic interlocked_inc */
ts4_word ts4_atomic_interlocked_inc_88595FD8(ts4_word a0)
{
    ts4_word t1;

    t1 = _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 12)));
    return t1;
}

/* Swing_DLL.xex 0x885A6158: atomic interlocked_inc */
ts4_word ts4_atomic_interlocked_inc_885A6158(ts4_word a0)
{
    ts4_word t1;

    t1 = _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 20)));
    return t1;
}

/* Swing_DLL.xex 0x885A6E08: atomic interlocked_inc */
ts4_word ts4_atomic_interlocked_inc_885A6E08(ts4_word a0)
{
    ts4_word t1;

    t1 = _InterlockedIncrement((volatile long *)(ts4_word)((a0 + 28)));
    return t1;
}

/* Swing_DLL.xex 0x885ABE30: if_get fn_885ABDB0, u32@0x34, fn_885AA208, ts4_pool_free_885B72F0, u32@0x34, u32@0x80 */
ts4_word ts4_if_get_fn_885ABDB0_885ABE30(ts4_word a0)
{
    ts4_word p18;
    ts4_word t2;
    ts4_word t6;
    ts4_word t10;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;

    fn_885ABDB0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t2 != 0) {
        fn_885AA208((ts4_word)t2);
        ts4_pool_free_885B72F0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t6 != 0) {
        ts4_get_u32_off3ea0_88594050((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t10 != 0) {
        ts4_get_u32_off3ea0_88594050((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)t10);
        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    if ((ts4_word)t14 != 0) {
        _InterlockedDecrement((volatile long *)(ts4_word)(t14));
        *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    p18 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t17 = ts4_pool_free_885B72F0((ts4_word)t16);
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
        p18 = (ts4_word)t17;
    }
    return p18;
}

/* Swing_DLL.xex 0x885B5E88: if_atomic interlocked_dec, u8@0x0, ts4_pool_free_885B72F0 */
ts4_word ts4_if_atomic_interlocked_dec_885B5E88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = _InterlockedDecrement((volatile long *)(ts4_word)((a0 + 16)));
    if ((ts4_word)t1 == 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)15;
        ts4_pool_free_885B72F0();
    }
    return 1;
}

/* Swing_DLL.xex 0x885BFA90: loop_set u32@0x30, u32@0x28, u32@0x28, u32@0x0, u32@0x0, u32@0x30 */
void ts4_loop_set_u32_off30_885BFA90(ts4_word a0, int a1, ts4_word a2, int a3)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p7;
    ts4_word p8;
    int t2;
    int t6;

    *(ts4_word *)((char *)(ts4_word)(a2) + 48) = (ts4_word)0;
    if ((int)a3 != 3) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 40);
    if ((int)t2 == 0) {
        return;
    }
    if ((ts4_word)a0 == 0) {
        return;
    }
    if ((int)a1 <= 0) {
        return;
    }
    lv3 = (ts4_word)a0;
    lv4 = (ts4_word)0;
    do {
        t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((int)t6 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a2) + 48) = (ts4_word)1;
            return;
        }
        p7 = (ts4_word)(lv3 + 4);
        p8 = (ts4_word)(lv4 + 1);
        lv3 = p7;
        lv4 = p8;
    } while ((int)p8 < (int)a1);
    return;
}

/* Swing_DLL.xex 0x885CC568: if_call_seq fn_885CD4B0, fn_885CD338, fn_885C38E0, fn_885C3770, u32@0x0, fn_885C38E0 */
ts4_word ts4_if_call_seq_fn_885CD4B0_885CC568(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    int t1;
    int t2;
    ts4_word t4;
    int t11;
    int t8;
    int t9;
    ts4_word t10;
    int t5;
    int t6;
    ts4_word t7;

    t1 = fn_885CD4B0((ts4_word)a2, (ts4_word)(a1 + 3));
    if ((int)t1 >= 0) {
        t2 = fn_885CD338((ts4_word)a2, (ts4_word)3, (ts4_word)(ts4_word)&loc50[0]);
        if ((int)t2 >= 0) {
            t4 = loc50[0];
            if ((ts4_word)(t4 & 0x80000000) == 0) {
                t11 = fn_885C38E0((ts4_word)a2, (ts4_word)1);
                if ((int)t11 >= 0) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
                    return t11;
                }
                return t11;
            }
            if ((int)(t4 & 0x40000000) == 0) {
                t8 = fn_885C38E0((ts4_word)a2, (ts4_word)2);
                if ((int)t8 >= 0) {
                    t9 = fn_885C3770((ts4_word)a2, (ts4_word)2, (ts4_word)(ts4_word)&loc50[0]);
                    if ((int)t9 >= 0) {
                        t10 = loc50[0];
                        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t10 + 1);
                        return t9;
                    }
                    return t9;
                }
                return t8;
            }
            if ((int)(t4 & 0x20000000) == 0) {
                t5 = fn_885C38E0((ts4_word)a2, (ts4_word)3);
                if ((int)t5 >= 0) {
                    t6 = fn_885C3770((ts4_word)a2, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
                    if ((int)t6 >= 0) {
                        t7 = loc50[0];
                        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t7 + 4);
                        return t6;
                    }
                    return t6;
                }
                return t5;
            }
            return ((2147745792) | 2);
        }
        return t2;
    }
    return t1;
}

/* Swing_DLL.xex 0x885ECAE0: if_get fn_885E7AD8, u32@0x8, vcall */
ts4_word ts4_if_get_fn_885E7AD8_885ECAE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_885E7AD8((ts4_word)(a0 + 8), (ts4_word)a2, (ts4_word)0);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
        if ((ts4_word)t2 != 0) {
            ((ts4_word (*)(ts4_word))(t2))((ts4_word)a1);
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x88608698: loop_get u32@0x120, u32@0x0, u32@0x4, vcall, u32@0x124, u32@0x0 */
ts4_word ts4_loop_get_u32_off120_88608698(ts4_word a0, ts4_word a1)
{
    ts4_word lv10;
    ts4_word lv11;
    ts4_word p17;
    ts4_word p18;
    ts4_word t1;
    ts4_word t9;
    ts4_word t12;
    ts4_word t16;
    ts4_word t25;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 288);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    if ((ts4_word)a1 == 0) {
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
        if ((ts4_word)t9 > 0) {
            lv10 = (ts4_word)(a0 + 44);
            lv11 = (ts4_word)a1;
            do {
                t12 = *(ts4_word *)((char *)(ts4_word)((lv10 + 4)) + 0);
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 104))))((ts4_word)t12);
                t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
                p17 = (ts4_word)(lv10 + 4);
                p18 = (ts4_word)(lv11 + 1);
                lv10 = p17;
                lv11 = p18;
            } while ((ts4_word)p18 < (ts4_word)t16);
        }
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 104))))((ts4_word)a1);
    }
    t25 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    return t25;
}

/* Swing_DLL.xex 0x8860F040: if_get u32@0x34, u32@0x1c, u32@0x30, u32@0x1c, u32@0x3c */
ts4_word ts4_if_get_u32_off34_8860F040(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p8;
    int t1;
    int t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)a1 < (int)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + (a1 << 2));
        p6 = (ts4_word)t4;
        if ((int)t4 == -1) {
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        }
        p8 = (ts4_word)p6;
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    }
    return (((int)p8 * 196) + (*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
}

/* Swing_DLL.xex 0x88611D08: loop_get u8@0x8, u32@0x20, u32@0x1c, u32@0x0, u8@0x8, u32@0x0 */
ts4_word ts4_loop_get_u8_off8_88611D08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p10;
    ts4_word p11;
    ts4_word p12;
    ts4_word p14;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    unsigned char t6;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    p14 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        p12 = (ts4_word)a0;
        lv4 = (ts4_word)t3;
        while ((ts4_word)lv4 != (ts4_word)t2) {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 8);
            p10 = (ts4_word)t5;
            if ((ts4_word)t6 != 0) {
                t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 8))))((ts4_word)t5);
                p10 = (ts4_word)t9;
            }
            p11 = (ts4_word)(lv4 + 4);
            lv4 = p11;
            p12 = (ts4_word)p10;
        }
        p14 = (ts4_word)p12;
    }
    return p14;
}

/* Swing_DLL.xex 0x886178A0: loop_call_seq u32@0x4, ts4_resume_thread, u32@0x10, u8@0x20, ts4_if_call_seq_NtSetEvent_8857C1F8, u32@0x4 */
ts4_word ts4_loop_call_seq_u32_off4_886178A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word p18;
    int t1;
    ts4_word t3;
    ts4_word t11;
    ts4_word t14;
    ts4_word t15;
    ts4_word t17;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p18 = (ts4_word)t1;
    if ((int)t1 != 0) {
        ts4_resume_thread((ts4_word)t1);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
        ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)t3);
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)-1);
        ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        lv12 = (ts4_word)(ts4_word)lbl_88D3EB60;
        do {
            t14 = *(ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((ts4_word)t11 == (ts4_word)t14) {
                *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0) = (ts4_word)0;
                *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 4) = (ts4_word)0;
                t15 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t11);
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
                return t15;
            }
            p16 = (ts4_word)(lv12 + 520);
            lv12 = p16;
        } while ((ts4_word)p16 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
        t17 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t11);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        p18 = (ts4_word)t17;
    }
    return p18;
}

/* Swing_DLL.xex 0x8862DB58: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0xc, u32@0x10, lbl_880F7D58, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8862DB58(ts4_word a0)
{
    ts4_word p3;
    ts4_word p6;
    ts4_word p10;
    ts4_word p13;
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t21;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F7D58;
        *(volatile unsigned char *)((char *)(ts4_word)(t2) + 8) = (unsigned char)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)20;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p3;
    t5 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t5 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(ts4_word)lbl_880F7D74;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t5) + 32) = (ts4_word)0;
        p6 = (ts4_word)t5;
    } else {
        p6 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p6;
    t8 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t8 != 0) {
        t9 = ts4_call_seq_lbl_880F7D90_88628EE0((ts4_word)t8);
        p10 = (ts4_word)t9;
    } else {
        p10 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p10;
    t12 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t12 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)4;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 0) = (ts4_word)(ts4_word)lbl_880F7DA0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t12) + 32) = (ts4_word)0;
        p13 = (ts4_word)t12;
    } else {
        p13 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p13;
    fn_886156B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    fn_886156B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    fn_88615650((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t21 = fn_88615650((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    return t21;
}

/* Swing_DLL.xex 0x88637040: loop_get u32@0x78, u32@0x7c, u32@0x14, u32@0x14, u32@0xc, u32@0xc */
void ts4_loop_get_u32_off78_88637040(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return;
    }
    lv3 = (ts4_word)t1;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 20);
        if ((ts4_word)t5 == (ts4_word)a1) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 12)) + -1);
            return;
        }
        p7 = (ts4_word)(lv3 + 24);
        lv3 = p7;
    } while ((ts4_word)p7 != (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x88637080: loop_get u32@0x78, u32@0x7c, u32@0x14, u32@0x14, u32@0xc */
ts4_word ts4_loop_get_u32_off78_88637080(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 20);
            if ((ts4_word)t5 == (ts4_word)a1) {
                return (*(ts4_word *)((char *)(ts4_word)(lv3) + 12));
            }
            p7 = (ts4_word)(lv3 + 24);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t2);
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x88637170: loop_get u32@0x84, u32@0x4, vcall, u32@0x64, u32@0x60, u32@0x0 */
ts4_word ts4_loop_get_u32_off84_88637170(ts4_word a0, ts4_word a1)
{
    ts4_word lv10;
    ts4_word p16;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((ts4_word)t4 != (ts4_word)t5) {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        lv10 = (ts4_word)t5;
        do {
            t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
            if ((ts4_word)t9 == (ts4_word)t12) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
                return lv10;
            }
            p16 = (ts4_word)(lv10 + 276);
            lv10 = p16;
        } while ((ts4_word)t4 != (ts4_word)p16);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
        return 0;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return 0;
}

/* Swing_DLL.xex 0x88639EF0: loop_get u32@0x4, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off4_88639EF0(ts4_word a0, ts4_word a1)
{
    ts4_word c2;
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    c2 = (ts4_word)9;
    lv3 = (ts4_word)(t1 + 444);
    lv4 = (ts4_word)(a1 + -4);
    do {
        *(ts4_word *)((char *)(ts4_word)((lv3 + 4)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv4 + 4)) + 0));
        p6 = (ts4_word)(lv3 + 4);
        p7 = (ts4_word)(lv4 + 4);
        lv3 = p6;
        lv4 = p7;
    } while (--c2 != 0);
    return;
}

/* Swing_DLL.xex 0x8863ADD0: loop_get u32@0x4a4, u32@0x4a0, u32@0x8, u32@0x8, u8@0x11 */
void ts4_loop_get_u32_off4a4_8863ADD0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1188);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1184);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return;
    }
    lv3 = (ts4_word)t2;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 8);
        if ((ts4_word)t5 == (ts4_word)a1) {
            *(unsigned char *)((char *)(ts4_word)(lv3) + 17) = (unsigned char)0;
            return;
        }
        p6 = (ts4_word)(lv3 + 20);
        lv3 = p6;
    } while ((ts4_word)p6 != (ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88644DC8: get  */
void ts4_get_88644DC8(ts4_word a0, __vector4 vp1)
{
    *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)lbl_8814B440);
    *(__vector4 *)((ts4_word)(a0 + 80)) = vp1;
    return;
}

/* Swing_DLL.xex 0x8864C0D0: if_call_seq fn_889BD910, u32@0x4, u32@0x24, u16@0xc, u64@0x30, u64@0x20 */
ts4_word ts4_if_call_seq_fn_889BD910_8864C0D0(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_889BD910((ts4_word)28, (ts4_word)0);
    if ((ts4_word)t1 == 0) {
        p9 = (ts4_word)-1;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)0;
        *(unsigned short *)((char *)(ts4_word)(t1) + 12) = (unsigned short)t2;
        *(ts4_u64 *)((char *)(ts4_word)(t1) + 32) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 48));
        *(unsigned short *)((char *)(ts4_word)(t1) + 14) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
        fn_8864BBB0((ts4_word)a0, (ts4_word)t1, (ts4_word)t5);
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 148))) + 14) = (unsigned char)1;
        p9 = (ts4_word)0;
    }
    return p9;
}

/* Swing_DLL.xex 0x8864C6A8: if_call_seq u32@0x18, u32@0x38, ts4_crc32_guarded_8864B2C8, u32@0x14, fn_889BD910, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off18_8864C6A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    t3 = ts4_crc32_guarded_8864B2C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56)), (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)t3;
    t4 = fn_889BD910((ts4_word)27, (ts4_word)0);
    if ((ts4_word)t4 == 0) {
        return -1;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(t4) + 16) = (unsigned short)t5;
    *(ts4_word *)((char *)(ts4_word)(t4) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(unsigned short *)((char *)(ts4_word)(t4) + 18) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(ts4_word *)((char *)(ts4_word)(t4) + 28) = (ts4_word)t8;
    *(ts4_word *)((char *)(ts4_word)(t4) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(t4) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    ts4_field_set_string_885FFA88((ts4_word)t4, (ts4_word)(a1 + 64), (ts4_word)t8);
    *(ts4_u64 *)((char *)(ts4_word)(t4) + 48) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 48));
    fn_8864BBB0((ts4_word)a0, (ts4_word)t4);
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 148))) + 14) = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x8864D318: call_seq lbl_88D44040, u32@0x0, u32@0x18, u8@0xc, u8@0xd, u8@0xe */
ts4_word ts4_call_seq_lbl_88D44040_8864D318(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(ts4_word)lbl_88D44040;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 44) = (unsigned short)0;
    memset((ts4_word)(a0 + 46), (ts4_word)0, (ts4_word)128);
    memset((ts4_word)(a0 + 174), (ts4_word)0, (ts4_word)128);
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 304) = (ts4_u64)0;
    return a0;
}

/* Swing_DLL.xex 0x8864E2E0: fn  */
void ts4_fn_8864E2E0(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    *(__vector4 *)((ts4_word)(a0)) = vv1;
    vv2 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv2;
    vv3 = *(__vector4 *)((ts4_word)(a1 + 32));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv3;
    vv4 = *(__vector4 *)((ts4_word)(a1 + 48));
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv4;
    return;
}

/* Swing_DLL.xex 0x8864E3F0: fn  */
void ts4_fn_8864E3F0(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    *(__vector4 *)((ts4_word)(a0)) = vv1;
    vv2 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv2;
    vv3 = *(__vector4 *)((ts4_word)(a1 + 32));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv3;
    vv4 = *(__vector4 *)((ts4_word)(a1 + 48));
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv4;
    return;
}

/* Swing_DLL.xex 0x8864E668: fn  */
void ts4_fn_8864E668(ts4_word a0, ts4_word a1)
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

    vv1 = *(__vector4 *)((ts4_word)(a0));
    vv2 = *(__vector4 *)((ts4_word)(a0 + 32));
    vv3 = *(__vector4 *)((ts4_word)(a0 + 48));
    vv4 = *(__vector4 *)((ts4_word)(a0 + 16));
    vv5 = __vmrghw(vv1, vv2);
    vv6 = __vmrglw(vv1, vv2);
    vv7 = __vmrghw(vv4, vv3);
    vv8 = __vmrglw(vv4, vv3);
    vv9 = __vmrghw(vv5, vv7);
    vv10 = __vmrglw(vv5, vv7);
    vv11 = __vmrghw(vv6, vv8);
    vv12 = __vmrglw(vv6, vv8);
    *(__vector4 *)((ts4_word)(a1)) = vv9;
    *(__vector4 *)((ts4_word)(a1 + 16)) = vv10;
    *(__vector4 *)((ts4_word)(a1 + 32)) = vv11;
    *(__vector4 *)((ts4_word)(a1 + 48)) = vv12;
    return;
}

/* Swing_DLL.xex 0x8865EC58: get u32@0x74 */
void ts4_get_u32_off74_8865EC58(ts4_word a0, ts4_word a1)
{
    __vector4 vv2;

    vv2 = *(__vector4 *)((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 116)) + 2272));
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    return;
}

/* Swing_DLL.xex 0x8865F588: if_get u32@0x1c, u32@0x0, u32@0x14, vcall, u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_8865F588(ts4_word a0)
{
    ts4_word p18;
    ts4_word t1;
    ts4_word t5;
    ts4_word t10;
    ts4_word t14;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 20))))((ts4_word)t10);
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    p18 = (ts4_word)t14;
    if ((ts4_word)t14 != 0) {
        t17 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 0))))((ts4_word)t14, (ts4_word)1);
        p18 = (ts4_word)t17;
    }
    return p18;
}

/* Swing_DLL.xex 0x8865FCD0: set u32@0x2c */
void ts4_set_u32_off2c_8865FCD0(ts4_word a0, ts4_word a1, __vector4 vp1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vp1;
    return;
}

/* Swing_DLL.xex 0x886614C0: set  */
void ts4_set_886614C0(ts4_word a0, float f1, __vector4 vp1, __vector4 vp2)
{
    *(float *)((char *)(ts4_word)(a0) + 32) = f1;
    *(__vector4 *)((ts4_word)(a0)) = vp1;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vp2;
    return;
}

/* Swing_DLL.xex 0x886631B0: get u32@0x1c, u32@0x8, u32@0x74 */
void ts4_get_u32_off1c_886631B0(ts4_word a0)
{
    __vector4 vv7;
    ts4_word locm10[4];
    ts4_word t2;
    float t3;
    ts4_word t4;
    float t5;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8);
    t3 = *(float *)lbl_8814B440;
    *(float *)((char *)locm10 + 4) = t3;
    *(float *)((char *)locm10 + 12) = t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 116);
    t5 = *(float *)((char *)(ts4_word)(t4) + 1096);
    *(float *)((char *)locm10 + 0) = (*(float *)((char *)(ts4_word)(t4) + 1100));
    *(float *)((char *)locm10 + 8) = (-t5);
    vv7 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    *(__vector4 *)((ts4_word)(t4 + 2496)) = vv7;
    return;
}

/* Swing_DLL.xex 0x88676028: if_get u32@0x4, u32@0x38, u32@0x1d0, u32@lbl_88D45B38, fn_88613268, lbl_880F49D8 */
ts4_word ts4_if_get_u32_off4_88676028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word p9;
    ts4_word p16;
    ts4_word p19;
    ts4_word p22;
    ts4_word t3;
    ts4_word t21;
    ts4_word t18;
    ts4_word t15;
    ts4_word t8;
    ts4_word t5;
    ts4_word t31;
    ts4_word t32;
    ts4_word t35;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 56))) + 464);
    if ((ts4_word)t3 <= (ts4_word)((3661889536) | 11157)) {
        if ((ts4_word)t3 != (ts4_word)((3661889536) | 11157)) {
            if ((ts4_word)t3 != (ts4_word)((1589837824) | 60981)) {
                if ((ts4_word)t3 == (ts4_word)((3632857088) | 35820)) {
                    t21 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)2);
                    if ((ts4_word)t21 != 0) {
                        *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)0;
                        *(ts4_word *)((char *)(ts4_word)(t21) + 0) = (ts4_word)(ts4_word)lbl_880F4990;
                        *(ts4_word *)((char *)(ts4_word)(t21) + 8) = (ts4_word)0;
                        p22 = (ts4_word)t21;
                    } else {
                        p22 = (ts4_word)0;
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p22;
                }
            } else {
                t18 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)2);
                if ((ts4_word)t18 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(t18) + 4) = (ts4_word)0;
                    *(ts4_word *)((char *)(ts4_word)(t18) + 0) = (ts4_word)(ts4_word)lbl_880F4A20;
                    *(ts4_word *)((char *)(ts4_word)(t18) + 8) = (ts4_word)0;
                    p19 = (ts4_word)t18;
                } else {
                    p19 = (ts4_word)0;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p19;
            }
        } else {
            t15 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
            if ((ts4_word)t15 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t15) + 4) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)(ts4_word)lbl_880F4948;
                *(ts4_word *)((char *)(ts4_word)(t15) + 8) = (ts4_word)0;
                *(unsigned char *)((char *)(ts4_word)(t15) + 16) = (unsigned char)0;
                p16 = (ts4_word)t15;
            } else {
                p16 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p16;
        }
    } else {
        if ((ts4_word)t3 != (ts4_word)((3696623616) | 17390)) {
            if ((ts4_word)t3 == (ts4_word)((3917545472) | 46545)) {
                t8 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
                if ((ts4_word)t8 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)0;
                    *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)(ts4_word)lbl_880F4900;
                    *(ts4_word *)((char *)(ts4_word)(t8) + 8) = (ts4_word)0;
                    p9 = (ts4_word)t8;
                } else {
                    p9 = (ts4_word)0;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p9;
            }
        } else {
            t5 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)0, (ts4_word)2);
            if ((ts4_word)t5 != 0) {
                *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(ts4_word)lbl_880F49D8;
                *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)0;
                p6 = (ts4_word)t5;
            } else {
                p6 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p6;
        }
    }
    t31 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t32 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t35 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t31) + 0))) + 4))))((ts4_word)t31, (ts4_word)t32);
    return t35;
}

/* Swing_DLL.xex 0x88696340: if_call_seq u32@0x34, u32@0x2c, u32@0x10, fn_8826D958, u32@0x2c, fn_8826D958 */
ts4_word ts4_if_call_seq_u32_off34_88696340(ts4_word a0)
{
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t16;
    ts4_word t30;
    ts4_word t37;
    ts4_word t38;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16));
    t4 = fn_8826D958((ts4_word)(t2 + 148), (ts4_word)(ts4_word)&loc50[0]);
    p7 = (ts4_word)t4;
    if ((ts4_word)t4 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        loc50[0] = (ts4_word)((753074176) | 14659);
        t6 = fn_8826D958((ts4_word)(t5 + 148), (ts4_word)(ts4_word)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)p7;
    *(ts4_word *)((char *)(ts4_word)(t8) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 44) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 45) = (unsigned char)0;
    fn_88187E70((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 240) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 242) = (unsigned char)0;
    t16 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 12);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 220) = (ts4_word)t16;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 228) = (ts4_word)((2525102080) | 12467);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68))) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68))) + 548) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 68))) + 132) = (unsigned char)0;
    t30 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 16))) + 0))) + 16))) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t30;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t30) + 116))) + 1253) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 20) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 52) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 116) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 243) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 232) = (ts4_word)-1;
    t37 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    t38 = *(ts4_word *)((char *)(ts4_word)(t37) + 116);
    *(ts4_word *)((char *)(ts4_word)(t38) + 1012) = (ts4_word)0;
    return t38;
}

/* Swing_DLL.xex 0x886A0350: loop_call_seq u32@0x18, u32@0x48, u32@0x1c, fn_881705B0, u8@0x3c, u8@0x3d */
ts4_word ts4_loop_call_seq_u32_off18_886A0350(ts4_word a0, ts4_word a1)
{
    ts4_word c3;
    ts4_word lv4;
    ts4_word p5;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    t2 = fn_881705B0((ts4_word)(a0 + 56), (ts4_word)16);
    c3 = (ts4_word)20;
    lv4 = (ts4_word)(a0 + 76);
    do {
        *(unsigned char *)((char *)(ts4_word)(lv4) + 60) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(lv4) + 61) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(lv4) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv4) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv4 + 48)) + 0) = (ts4_word)0;
        p5 = (ts4_word)(lv4 + 48);
        lv4 = p5;
    } while (--c3 != 0);
    return t2;
}

/* Swing_DLL.xex 0x886A11E8: if_call_seq fn_886A1128, u32@0x4, u32@0x48, u32@0x28, u8@0x48, u8@0x6c */
ts4_word ts4_if_call_seq_fn_886A1128_886A11E8(ts4_word a0)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    unsigned char t5;
    ts4_word t8;

    t1 = fn_886A1128();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 72))) + 40);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 72);
    p9 = (ts4_word)t1;
    if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t4) + 108)) != 0) {
        t8 = fn_886921A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 180)), (ts4_word)0, (ts4_word)0, (ts4_word)1);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x886BC568: loop_set ts4_find_service, u32@0x60, u32@0x0, u32@0x4c, vcall, u32@0x0 */
ts4_word ts4_loop_set_ts4_find_service_886BC568(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv12;
    ts4_word p14;
    ts4_word p33;
    ts4_word p34;
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;
    ts4_word t10;
    ts4_word t18;
    unsigned char t22;
    ts4_word t23;
    int t24;
    ts4_word t26;
    ts4_word t32;

    t1 = ts4_find_service((ts4_word)((874053632) | 51016));
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)t1;
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0)) + t4);
    fn_88690920((ts4_word)a0);
    fn_889C14F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132)), (ts4_word)a3);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 44);
    lv12 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 40));
    while ((ts4_word)lv12 != (ts4_word)t10) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv12) + 0))) + 1328) = (unsigned char)0;
        p14 = (ts4_word)(lv12 + 4);
        lv12 = p14;
    }
    fn_886BC480((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    t18 = fn_8867BB78((ts4_word)a0);
    t22 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 120))) + 0))) + 48))) + 9);
    p34 = (ts4_word)t18;
    if ((ts4_word)t22 != 0) {
        t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
        p33 = (ts4_word)t18;
        if ((ts4_word)t23 != 0) {
            t24 = *(ts4_word *)((char *)(ts4_word)(t23) + 72);
            if ((int)t24 != 0) {
                t26 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 28))) + 4);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 0))) + 88))))((ts4_word)t26, (ts4_word)(t23 + 28));
            }
            t32 = fn_88913BD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 204)), (ts4_word)(ts4_word)lbl_880F3858, (ts4_word)1);
            p33 = (ts4_word)t32;
        }
        p34 = (ts4_word)p33;
    }
    return p34;
}

/* Swing_DLL.xex 0x886C3BF8: fn  */
void ts4_fn_886C3BF8(ts4_word a0, __vector4 vp1, __vector4 vp2, __vector4 vp3, __vector4 vp4)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;

    vv1 = __vmulfp(vp4, vp2);
    vv2 = __vspltw(vp1, 1);
    vv3 = __vspltw(vv1, 1);
    vv4 = __vaddfp(vv2, vv3);
    vv5 = __vsubfp(vv2, vv3);
    vv6 = __vminfp(vp3, vv4);
    vv7 = __vmaxfp(vv5, vv6);
    *(__vector4 *)((ts4_word)(a0)) = vv7;
    return;
}

/* Swing_DLL.xex 0x886C3C20: fn  */
void ts4_fn_886C3C20(ts4_word a0, __vector4 vp1, __vector4 vp2, __vector4 vp3)
{
    __vector4 vv1;
    __vector4 vv2;

    vv1 = __vmulfp(vp2, vp3);
    vv2 = __vsubfp(vp1, vv1);
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    return;
}

/* Swing_DLL.xex 0x886C3F28: fn  */
void ts4_fn_886C3F28(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = *(__vector4 *)((ts4_word)(a1 + 16));
    *(__vector4 *)((ts4_word)(a0)) = vv1;
    return;
}

/* Swing_DLL.xex 0x886C4468: fn  */
void ts4_fn_886C4468(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = *(__vector4 *)((ts4_word)(a1));
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv1;
    return;
}

/* Swing_DLL.xex 0x886EB130: fn  */
__vector4 ts4_fn_886EB130(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;

    vv1 = *(__vector4 *)((ts4_word)(a0 + a1));
    return vv1;
}

/* Swing_DLL.xex 0x886EB138: fn  */
void ts4_fn_886EB138(ts4_word a0, __vector4 vp1)
{
    *(__vector4 *)((ts4_word)(a0)) = vp1;
    return;
}

/* Swing_DLL.xex 0x886ECA40: get  */
__vector4 ts4_get_886ECA40(ts4_word a0)
{
    __vector4 vv5;
    ts4_word locm10[4];
    float t2;
    float t3;

    *(float *)((char *)locm10 + 0) = (*(float *)((char *)(ts4_word)(a0) + 0));
    t2 = *(float *)((char *)(ts4_word)(a0) + 4);
    t3 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)locm10 + 4) = t2;
    *(float *)((char *)locm10 + 12) = (*(float *)lbl_8814B440);
    *(float *)((char *)locm10 + 8) = t3;
    vv5 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    return vv5;
}

/* Swing_DLL.xex 0x886ECFC8: if_get u32@0x38, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off38_886ECFC8(ts4_word a0, ts4_word a1)
{
    int t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t2 != -1) {
            if ((int)t2 > 0) {
                if ((ts4_word)(a1 & 0xff) == 1) {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(t2 + -1);
                }
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x886F04D0: loop_get u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off4_886F04D0(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return t1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    lv4 = (ts4_word)t2;
    do {
        t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((ts4_word)t3 == (ts4_word)t6) {
            return lv4;
        }
        p7 = (ts4_word)(lv4 + 16);
        lv4 = p7;
    } while ((ts4_word)p7 != (ts4_word)t1);
    return t1;
}

/* Swing_DLL.xex 0x886F1578: loop_get u32@0x0, u32@0x4, u32@0x10c, u32@0x10c */
ts4_word ts4_loop_get_u32_off0_886F1578(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 < (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 268);
            if ((ts4_word)t5 == (ts4_word)a1) {
                return lv3;
            }
            p6 = (ts4_word)(lv3 + 308);
            lv3 = p6;
        } while ((ts4_word)p6 < (ts4_word)t2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x886F2460: if_get u8@0x0, u32@__imp_KeCertMonitorData, u32@0x0, u32@0x4, vcall, RtlEnterCriticalSection */
ts4_word ts4_if_get_u8_off0_886F2460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p13;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    unsigned char t11;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22538)) + 0);
    p13 = (ts4_word)a0;
    if ((ts4_word)t1 == 1) {
        t2 = *(ts4_word *)__imp_KeCertMonitorData;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + ((65536) | 22304));
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
            if ((ts4_word)t5 != 0) {
                ((ts4_word (*)(ts4_word))(t5))((ts4_word)1);
            }
        }
        t9 = RtlEnterCriticalSection((ts4_word)(t3 + 15156));
        t10 = fn_8857C8C8((ts4_word)t9);
        t11 = *(unsigned char *)((char *)(ts4_word)(t3) + 10942);
        *(ts4_word *)((char *)(ts4_word)(t3) + 10888) = (ts4_word)t10;
        *(unsigned char *)((char *)(ts4_word)(t3) + 10942) = (unsigned char)((t11 & 0xff) & 0xfffffffd);
        t12 = RtlLeaveCriticalSection((ts4_word)(t3 + 15156));
        *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22538)) + 0) = (unsigned char)0;
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x886F5280: loop_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_loop_call_seq_u32_lbl_88D45AD4_886F5280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word lv13;
    ts4_word lv14;
    ts4_word p16;
    ts4_word p17;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    unsigned char t15;
    ts4_word t18;
    ts4_word t20;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t25;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)1, (ts4_word)p4, (ts4_word)2);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(((t8 << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)))) + 12) = (ts4_word)t7;
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    lv13 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 4) + t10)) + 12)) + -1);
    lv14 = (ts4_word)(a1 + -1);
    do {
        t15 = *(unsigned char *)((char *)(ts4_word)((lv14 + 1)) + 0);
        *(unsigned char *)((char *)(ts4_word)((lv13 + 1)) + 0) = (unsigned char)t15;
        p16 = (ts4_word)(lv13 + 1);
        p17 = (ts4_word)(lv14 + 1);
        lv13 = p16;
        lv14 = p17;
    } while ((ts4_word)t15 != 0);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)((t18 << 4)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) = (ts4_word)((1415053312) | 12868);
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(((t22 << 4) + t20)) + 4) = (ts4_word)t21;
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 4) + t23)) + 8) = (ts4_word)52;
    t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 52);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t25 + 1);
    return ((t22 << 4) + t20);
}

/* Swing_DLL.xex 0x886F56C0: loop_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x4, u32@0x0 */
void ts4_loop_get_u32_off0_886F56C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 >= (ts4_word)t2) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    lv4 = (ts4_word)t1;
    do {
        t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
        if ((ts4_word)t8 == (ts4_word)t3) {
            *(unsigned char *)((char *)(ts4_word)(t7) + 8) = (unsigned char)a1;
            return;
        }
        p9 = (ts4_word)(lv4 + 4);
        lv4 = p9;
    } while ((ts4_word)p9 < (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x886FC830: loop_get fn_886F5FB0, u32@0x48, u32@0x44, u32@0x34, u32@0x0, u32@0x24 */
ts4_word ts4_loop_get_fn_886F5FB0_886FC830(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv5;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_886F5FB0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        lv5 = (ts4_word)t3;
        while ((ts4_word)lv5 != (ts4_word)t2) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv5) + 0))) + 36))))((ts4_word)lv5, (ts4_word)t4);
            p9 = (ts4_word)(lv5 + 44);
            lv5 = p9;
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x886FCB88: loop_get u32@0x44, u32@0x0, u32@0x4c, vcall, u32@0x0, u32@0x4 */
ts4_word ts4_loop_get_u32_off44_886FCB88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p9;
    ts4_word lv10;
    ts4_word p13;
    ts4_word p16;
    ts4_word p18;
    ts4_word t1;
    ts4_word t4;
    int t5;
    ts4_word t7;
    ts4_word t12;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
        p6 = (ts4_word)0;
        if ((int)t5 != -1) {
            p6 = (ts4_word)(t5 + t4);
        }
        p9 = (ts4_word)0;
        if ((int)t5 != -1) {
            t7 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
            p9 = (ts4_word)((((t7 + (t7 << 1)) << 2) + t5) + t4);
        }
        if ((ts4_word)p6 != (ts4_word)p9) {
            lv10 = (ts4_word)p6;
            do {
                t12 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
                if ((ts4_word)t12 == 0) {
                    *(ts4_word *)((char *)(ts4_word)(lv10) + 0) = (ts4_word)a1;
                    *(ts4_word *)((char *)(ts4_word)(lv10) + 8) = (ts4_word)a2;
                    *(unsigned char *)((char *)(ts4_word)(lv10) + 4) = (unsigned char)1;
                    return 1;
                }
                p13 = (ts4_word)(lv10 + 12);
                lv10 = p13;
            } while ((ts4_word)p13 != (ts4_word)p9);
            p16 = (ts4_word)0;
        } else {
            p16 = (ts4_word)0;
        }
        p18 = (ts4_word)p16;
    } else {
        p18 = (ts4_word)0;
    }
    return p18;
}

/* Swing_DLL.xex 0x88711900: if_call_seq u32@0x1c, u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, memset, fn_88700F88 */
ts4_word ts4_if_call_seq_u32_off1c_88711900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p12;
    ts4_word p13;
    ts4_word t1;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p13 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0xfff) != 0) {
        p12 = (ts4_word)a0;
        if ((ts4_word)(4096 - (t1 & 0xfff)) != 0) {
            t2 = *(ts4_word *)lbl_88D45AD4;
            p5 = (ts4_word)0;
            if ((ts4_word)t2 != 0) {
                p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + ((65536) | 22144)));
            }
            t8 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)(4096 - (t1 & 0xfff)), (ts4_word)1, (ts4_word)p5, (ts4_word)2);
            memset((ts4_word)t8, (ts4_word)0, (ts4_word)(4096 - (t1 & 0xfff)));
            fn_88700F88((ts4_word)a0, (ts4_word)t8, (ts4_word)(4096 - (t1 & 0xfff)));
            t11 = ts4_registry_dispatch_888860A0((ts4_word)t8);
            p12 = (ts4_word)t11;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x88713880: if_get u32@0x110, u32@0x0, u32@0x0, vcall, u32@0x114, ts4_registry_dispatch_888860A0 */
ts4_word ts4_if_get_u32_off110_88713880(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p18;
    ts4_word p19;
    ts4_word p20;
    ts4_word p24;
    int t1;
    int t6;
    ts4_word t7;
    unsigned char t9;
    ts4_word t10;
    ts4_word t14;
    ts4_word t17;
    int t21;
    ts4_word t23;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    if ((int)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
    p8 = (ts4_word)t6;
    if ((int)t6 != 0) {
        t7 = ts4_registry_dispatch_888860A0((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 280);
    p20 = (ts4_word)p8;
    if ((ts4_word)t9 == 0) {
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 304);
        p19 = (ts4_word)t10;
        if ((ts4_word)t10 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 20))))((ts4_word)t10);
            t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 304);
            p18 = (ts4_word)t14;
            if ((ts4_word)t14 != 0) {
                t17 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 0))))((ts4_word)t14, (ts4_word)1);
                p18 = (ts4_word)t17;
            }
            p19 = (ts4_word)p18;
        }
        p20 = (ts4_word)p19;
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
    p24 = (ts4_word)p20;
    if ((int)t21 != 0) {
        ts4_if_call_seq_u32_off0_886F9C80((ts4_word)t21);
        t23 = ts4_tsu_cleanup_end((ts4_word)t21);
        p24 = (ts4_word)t23;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 304) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)0;
    return p24;
}

/* Swing_DLL.xex 0x8873B7E8: if_get u8@0x0, u32@__imp_KeCertMonitorData, u32@0x0, u32@0x4, vcall, fn_88292A78 */
ts4_word ts4_if_get_u8_off0_8873B7E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p15;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;
    unsigned char t12;
    ts4_word t13;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22538)) + 0);
    p15 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t2 = *(ts4_word *)__imp_KeCertMonitorData;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + ((65536) | 22304));
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
            if ((ts4_word)t5 != 0) {
                ((ts4_word (*)(ts4_word))(t5))((ts4_word)2);
            }
        }
        fn_88292A78((ts4_word)t3);
        RtlEnterCriticalSection((ts4_word)(t3 + 15156));
        t11 = *(ts4_word *)((char *)(ts4_word)(t3) + 11324);
        t12 = *(unsigned char *)((char *)(ts4_word)(t3) + 10942);
        t13 = *(ts4_word *)((char *)(ts4_word)((((int)t11 * 108) + t3)) + 11408);
        *(unsigned char *)((char *)(ts4_word)(t3) + 10942) = (unsigned char)(t12 | 2);
        *(ts4_word *)((char *)(ts4_word)(t3) + 10888) = (ts4_word)t13;
        t14 = RtlLeaveCriticalSection((ts4_word)(t3 + 15156));
        *(unsigned char *)((char *)(ts4_word)(((a0 + 65536) + 22538)) + 0) = (unsigned char)1;
        p15 = (ts4_word)t14;
    }
    return p15;
}

/* Swing_DLL.xex 0x8875AF70: loop_set u32@lbl_88D45A94, lbl_88D45A90, fn_887573E0, interlocked_dec, u8@lbl_88D45A8C, u32@lbl_88D45A94 */
ts4_word ts4_loop_set_u32_lbl_88D45A94_8875AF70(void)
{
    int t2;

    *(ts4_word *)lbl_88D45A94 = (ts4_word)1;
    do {
        fn_887573E0();
        t2 = _InterlockedDecrement((volatile long *)(ts4_word)((ts4_word)lbl_88D45A90));
    } while ((int)t2 > 0 && (ts4_word)(*(unsigned char *)lbl_88D45A8C) == 0);
    *(ts4_word *)lbl_88D45A94 = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x8875B568: if_get fn_88608A40, fn_881A5020, fn_886F5BD0, u32@0x0, u32@0x4c, vcall */
ts4_word ts4_if_get_fn_88608A40_8875B568(ts4_word a0, ts4_word a1)
{
    ts4_word loc1d0[128];
    ts4_word locc0[68];
    ts4_word loc60[24];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t12;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t6;
    ts4_word t7;

    fn_88608A40((ts4_word)a1, (ts4_word)(ts4_word)&loc1d0[0]);
    fn_881A5020((ts4_word)(ts4_word)&locc0[0], (ts4_word)a1);
    t3 = fn_886F5BD0((ts4_word)(ts4_word)&locc0[0]);
    if ((ts4_word)t3 == 0) {
        ts4_call_seq_fn_88617D88_8892AFF0((ts4_word)(ts4_word)&loc60[0]);
        *(unsigned char *)((char *)loc60 + 28) = (unsigned char)1;
        fn_881A5020((ts4_word)(ts4_word)&locc0[0], (ts4_word)a1);
        fn_886F5AE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&locc0[0]);
        t12 = loc50[0];
        ts4_if_get_u32_off0_8892FE20((ts4_word)(ts4_word)&loc60[0], (ts4_word)t12, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t14 = loc60[0];
        t16 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 76))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
        t17 = fn_88758A00((ts4_word)a0, (ts4_word)t16, (ts4_word)(ts4_word)&loc1d0[0]);
        fn_88929E70((ts4_word)(ts4_word)&loc60[0]);
        fn_88719330((ts4_word)(ts4_word)&loc50[0]);
        ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(ts4_word)&loc60[0]);
        return t17;
    }
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 76))))((ts4_word)t3, (ts4_word)0);
    t7 = fn_88758A00((ts4_word)a0, (ts4_word)t6, (ts4_word)(ts4_word)&loc1d0[0]);
    fn_887193A8((ts4_word)t3, (ts4_word)0);
    return t7;
}

/* Swing_DLL.xex 0x88782898: if_call_seq u32@lbl_88D45A58, u32@0x14, fn_888CDF68, u32@lbl_88D45A58, u8@0x0, u32@lbl_88D45A58 */
ts4_word ts4_if_call_seq_u32_lbl_88D45A58_88782898(ts4_word a0)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    unsigned char t7;
    unsigned char t8;

    t1 = *(ts4_word *)lbl_88D45A58;
    if ((ts4_word)t1 != 0) {
        t3 = fn_888CDF68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
        if ((ts4_word)(t3 & 0xff) == 0) {
            t7 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A58)) + 0);
            if ((ts4_word)t7 != 1) {
                t8 = *(unsigned char *)lbl_88C46F6A;
                p9 = (ts4_word)0;
                if ((ts4_word)t8 == 0) {
                    p9 = (ts4_word)1;
                }
                p10 = (ts4_word)p9;
            } else {
                p10 = (ts4_word)1;
            }
            if ((ts4_word)(p10 & 0xff) == 0) {
                *(ts4_word *)lbl_88D45A58 = (ts4_word)(p10 & 0xff);
                return p10;
            }
            return p10;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88785A80: if_call_seq u32@0x18, fn_887EA830, u32@0x10, u32@lbl_88D45A04, fn_887EC298, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_if_call_seq_u32_off18_88785A80(ts4_word a0)
{
    ts4_word p8;
    ts4_word p13;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    unsigned char t10;
    ts4_word t11;
    ts4_word t12;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    fn_887EA830((ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t4 = fn_887EC298((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)(a0 + 32), (ts4_word)(a0 + 40));
    t5 = *(unsigned char *)((char *)loc50 + 1);
    p8 = (ts4_word)t4;
    if ((ts4_word)t5 == 1) {
        t6 = loc50[2];
        t7 = ts4_tailcall_fn_88582F30_8857A128((ts4_word)t6, (ts4_word)-1);
        p8 = (ts4_word)t7;
    }
    t9 = loc50[1];
    t10 = *(unsigned char *)((char *)loc50 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t9;
    p13 = (ts4_word)p8;
    if ((ts4_word)t10 == 1) {
        t11 = loc50[2];
        t12 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t11);
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x8878A530: if_call_seq u32@0x18, fn_887EA830, u8@0x20, u32@0x10, u32@lbl_88D45A04, fn_887EC4A8 */
ts4_word ts4_if_call_seq_u32_off18_8878A530(ts4_word a0)
{
    ts4_word p16;
    ts4_word loc50[6];
    unsigned char t2;
    ts4_word t3;
    unsigned char t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t12;
    unsigned char t13;
    ts4_word t14;
    ts4_word t15;

    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    fn_887EA830((ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 32);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    fn_887EC4A8((ts4_word)(*(ts4_word *)lbl_88D45A04), (ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)t2);
    t6 = *(unsigned char *)((char *)loc50 + 1);
    if ((ts4_word)t6 == 1) {
        t7 = loc50[2];
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)t7, (ts4_word)-1);
    }
    t11 = fn_881AAE70((ts4_word)(a0 + 40), (ts4_word)((*(ts4_word *)lbl_88D45A04) + 44));
    t12 = loc50[1];
    t13 = *(unsigned char *)((char *)loc50 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t12;
    p16 = (ts4_word)t11;
    if ((ts4_word)t13 == 1) {
        t14 = loc50[2];
        t15 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t14);
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Swing_DLL.xex 0x887CBF90: if_call_seq fn_881AB1A0, u32@0x20, fn_887EB830, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_fn_881AB1A0_887CBF90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t4;
    ts4_word t5;

    loc50[1] = (ts4_word)a3;
    loc60[0] = (ts4_word)0;
    loc60[1] = (ts4_word)0;
    loc60[2] = (ts4_word)0;
    loc50[0] = (ts4_word)((753664000) | 63511);
    fn_881AB1A0((ts4_word)(ts4_word)&loc60[0], (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    loc50[2] = (ts4_word)a2;
    loc50[1] = (ts4_word)0;
    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)1;
    *(unsigned char *)((char *)loc50 + 1) = (unsigned char)0;
    fn_887EB830((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)a1);
    t4 = loc60[0];
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x887D4FF0: if_call_seq u32@0x0, u32@0x60, u32@0x48, u8@0x97, u32@0x18, u32@0x2c */
ts4_word ts4_if_call_seq_u32_off0_887D4FF0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t3;
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t7;
    unsigned char t9;
    unsigned char t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t1) + 96)) + 2) << 2)) + a0);
    if ((int)t3 == 0) {
        return 0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 72);
    if ((ts4_word)t4 == 0) {
        return 0;
    }
    t5 = *(unsigned char *)((char *)(ts4_word)(t1) + 151);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 24);
    t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    if ((ts4_word)t5 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 151) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t7) + 93) = (unsigned char)0;
    }
    t9 = *(unsigned char *)((char *)(ts4_word)(t7) + 93);
    if ((ts4_word)t9 != 0) {
        t10 = *(unsigned char *)((char *)(ts4_word)(t6) + 13);
        if ((ts4_word)t10 == 0) {
            return 0;
        }
        fn_887D4360((ts4_word)t1);
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x887F5400: call_seq fn_887F4BA0, lbl_880E4630, u32@0x0, fn_8816D1A8, fn_8816D1A8, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_887F4BA0_887F5400(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t12;
    ts4_word t16;
    ts4_word t20;
    ts4_word t24;
    ts4_word t28;
    ts4_word t32;
    ts4_word t36;
    ts4_word t40;

    t1 = fn_887F4BA0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4630;
    fn_8816D1A8((ts4_word)(t1 + 232));
    fn_8816D1A8((ts4_word)(a0 + 244));
    fn_8816D1A8((ts4_word)(a0 + 256));
    fn_8816D1A8((ts4_word)(a0 + 268));
    fn_8816D1A8((ts4_word)(a0 + 280));
    fn_8816D1A8((ts4_word)(a0 + 292));
    fn_8816D1A8((ts4_word)(a0 + 304));
    fn_8816D1A8((ts4_word)(a0 + 316));
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(t1 + 232), (ts4_word)(ts4_word)&loc50[0]);
    t12 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t12);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 244), (ts4_word)(ts4_word)&loc50[0]);
    t16 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t16);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 256), (ts4_word)(ts4_word)&loc50[0]);
    t20 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t20);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 268), (ts4_word)(ts4_word)&loc50[0]);
    t24 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t24);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 280), (ts4_word)(ts4_word)&loc50[0]);
    t28 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t28);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 292), (ts4_word)(ts4_word)&loc50[0]);
    t32 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t32);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 304), (ts4_word)(ts4_word)&loc50[0]);
    t36 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t36);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 316), (ts4_word)(ts4_word)&loc50[0]);
    t40 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t40);
    return a0;
}

/* Swing_DLL.xex 0x888064A0: loop_call_seq ts4_call_seq_u32_off0_88832F70, u32@0x0, fn_888368B0, lbl_880E2CCC, fn_888368B0, u32@0x0 */
ts4_word ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p7;
    ts4_word p8;
    ts4_word loc80[8];
    ts4_word loc50[4];
    ts4_word loc60[8];
    int t2;
    ts4_word t20;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc80[0], (ts4_word)a3, (ts4_word)a2);
    t2 = loc80[2];
    if ((int)t2 != 0) {
        if ((ts4_word)a1 != 0) {
            lv3 = (ts4_word)(a0 + -8);
            lv4 = (ts4_word)a1;
            do {
                loc50[0] = (ts4_word)0;
                loc50[2] = (ts4_word)0;
                fn_888368B0((ts4_word)(ts4_word)&loc80[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv3 + 8)) + 0)), (ts4_word)(ts4_word)&loc50[0]);
                p7 = (ts4_word)(lv3 + 8);
                p8 = (ts4_word)(lv4 + -1);
                lv3 = p7;
                lv4 = p8;
            } while ((int)p8 != 0);
        }
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc80[0], (ts4_word)(ts4_word)lbl_880E2CCC, (ts4_word)(ts4_word)&loc50[0]);
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        fn_881B18E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)a3, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0)) + 72));
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    }
    t20 = fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
    return t20;
}

/* Swing_DLL.xex 0x88809470: loop_call_seq u32@0x3c, lbl_88C6A0E8, u32@0x0, fn_881B18E0, u32@0x0, fn_888368B0 */
ts4_word ts4_loop_call_seq_u32_off3c_88809470(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word lv11;
    ts4_word lv12;
    ts4_word p18;
    ts4_word p19;
    ts4_word loc60[8];
    ts4_word loc50[4];
    ts4_word loc80[10];
    ts4_word t1;
    ts4_word t4;
    ts4_word t13;
    ts4_word t20;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    lv2 = (ts4_word)((ts4_word)lbl_88C6A0E8 + -8);
    lv3 = (ts4_word)2;
    do {
        t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        fn_881B18E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)t1, (ts4_word)(t4 + 72));
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv2 + 8)) + 0)), (ts4_word)(ts4_word)&loc50[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
        p9 = (ts4_word)(lv2 + 8);
        p10 = (ts4_word)(lv3 + -1);
        lv2 = p9;
        lv3 = p10;
    } while ((int)p10 != 0);
    lv11 = (ts4_word)((ts4_word)lbl_88C6A0F8 + -8);
    lv12 = (ts4_word)2;
    do {
        t13 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        loc80[2] = (ts4_word)0;
        loc80[4] = (ts4_word)0;
        fn_881B18E0((ts4_word)(ts4_word)&loc80[0], (ts4_word)t1, (ts4_word)(t13 + 72));
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(ts4_word)&loc80[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv11 + 8)) + 0)), (ts4_word)(ts4_word)&loc50[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
        p18 = (ts4_word)(lv11 + 8);
        p19 = (ts4_word)(lv12 + -1);
        lv11 = p18;
        lv12 = p19;
    } while ((int)p19 != 0);
    t20 = ts4_call_seq_lbl_880E2FE4_888085E0((ts4_word)t1);
    return t20;
}

/* Swing_DLL.xex 0x88811880: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_88811880(ts4_word a0)
{
    int t1;
    double t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 == 3) {
        t2 = *(double *)((char *)(ts4_word)(a0) + 8);
        if ((((double)((ts4_s64)(int)(int)(t2))) == t2 && (int)(int)(t2) >= 1) && (int)(((int)(t2) + -1) & 0xff000000) == 0) {
            return (int)(t2);
        }
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x88812188: if_call_seq u32@0x0, lua2_luaH_getany_88811E80, fn_88811930, u32@0x8, ts4_loop_get_u8_offd_888114E0, lua2_luaH_getany_88811E80 */
ts4_word ts4_if_call_seq_u32_off0_88812188(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t9;
    ts4_word t7;
    ts4_word t6;
    double t2;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 3) {
        if ((int)t1 != 4) {
            if ((int)t1 == 9) {
                t9 = ts4_loop_get_u8_offd_88811478((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
                return t9;
            }
            t7 = lua2_luaH_getany_88811E80((ts4_word)a0, (ts4_word)a1);
            return t7;
        }
        t6 = ts4_loop_get_u8_offd_888114E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
        return t6;
    }
    t2 = *(double *)((char *)(ts4_word)(a1) + 8);
    if (((double)((ts4_s64)(int)(int)(t2))) == t2) {
        t4 = fn_88811930((ts4_word)a0, (ts4_word)(int)(t2));
        return t4;
    }
    t3 = lua2_luaH_getany_88811E80((ts4_word)a0, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88812238: if_call_seq u32@0x0, lua2_luaH_getanynode_88811F40, fn_88811A08, u32@0x8, ts4_loop_get_u8_offd_888115A0, lua2_luaH_getanynode_88811F40 */
ts4_word ts4_if_call_seq_u32_off0_88812238(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t9;
    ts4_word t7;
    ts4_word t6;
    double t2;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 3) {
        if ((int)t1 != 4) {
            if ((int)t1 == 9) {
                t9 = ts4_loop_get_u8_offd_88811548((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
                return t9;
            }
            t7 = lua2_luaH_getanynode_88811F40((ts4_word)a0, (ts4_word)a1);
            return t7;
        }
        t6 = ts4_loop_get_u8_offd_888115A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
        return t6;
    }
    t2 = *(double *)((char *)(ts4_word)(a1) + 8);
    if (((double)((ts4_s64)(int)(int)(t2))) == t2) {
        t4 = fn_88811A08((ts4_word)a0, (ts4_word)(int)(t2));
        return t4;
    }
    t3 = lua2_luaH_getanynode_88811F40((ts4_word)a0, (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x888143E0: loop_get u32@0x14, u32@0xc, u32@0x0, u32@0x0, u32@0xc, u32@0x0 */
void ts4_loop_get_u32_off14_888143E0(ts4_word a0, int a1)
{
    ts4_word lv2;
    ts4_word p9;
    ts4_word t1;
    int t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 == 0) {
        return;
    }
    lv2 = (ts4_word)t1;
    do {
        t6 = *(ts4_word *)((char *)(ts4_word)(lv2) + 12);
        if ((int)t6 <= (int)a1) {
            *(ts4_word *)((char *)(ts4_word)(lv2) + 16) = (ts4_word)1;
            return;
        }
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
        lv2 = p9;
    } while ((ts4_word)p9 != 0);
    return;
}

/* Swing_DLL.xex 0x88814950: loop_call_seq lua2_searchvar_88814418, u32@0x8, ts4_loop_call_seq_fn_88814418_88814950, u32@0x0, lua2_newupvalue_88814668, u32@0x4 */
ts4_word ts4_loop_call_seq_fn_88814418_88814950(ts4_word a0, ts4_word a1, ts4_word a2, int a3)
{
    ts4_word lv8;
    ts4_word p13;
    int t1;
    ts4_word t7;
    int t11;
    ts4_word t3;
    int t4;
    ts4_word t6;
    ts4_word t5;

    if ((ts4_word)a0 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a2) + 16) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)7;
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)255;
        return a0;
    }
    t1 = lua2_searchvar_88814418((ts4_word)a0, (ts4_word)a1);
    if ((int)t1 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a2) + 16) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)5;
        if ((int)a3 == 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            if ((ts4_word)t7 != 0) {
                lv8 = (ts4_word)t7;
                do {
                    t11 = *(ts4_word *)((char *)(ts4_word)(lv8) + 12);
                    if ((int)t11 <= (int)t1) {
                        *(ts4_word *)((char *)(ts4_word)(lv8) + 16) = (ts4_word)1;
                        return t1;
                    }
                    p13 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 0));
                    lv8 = p13;
                } while ((ts4_word)p13 != 0);
                return t1;
            }
            return t1;
        }
        return t1;
    }
    t3 = ts4_loop_call_seq_fn_88814418_88814950((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)t4 == 7) {
        if ((int)a3 != 0) {
            t6 = lua2_luaK_stringK_88820AF0((ts4_word)a0, (ts4_word)a1);
            *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t6;
            return t6;
        }
        return t3;
    }
    t5 = lua2_newupvalue_88814668((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)6;
    return t5;
}

/* Swing_DLL.xex 0x8881CA00: call_seq lua2_DumpBlock_8881C828 */
ts4_word ts4_call_seq_fn_8881C828_8881CA00(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;

    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)a0;
    t1 = lua2_DumpBlock_8881C828((ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)a1);
    return t1;
}

/* Swing_DLL.xex 0x8881EC28: loop_get u32@0x0, u32@0x4 */
ts4_word ts4_loop_get_u32_off0_8881EC28(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 < (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            if ((ts4_word)a1 == (ts4_word)lv3) {
                return 1;
            }
            p4 = (ts4_word)(lv3 + 16);
            lv3 = p4;
        } while ((ts4_word)p4 < (ts4_word)t2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88822A50: if_call_seq u32@0xc, u32@-0x10, u32@-0x8, u8@0xc, u8@0xd, u32@0x14 */
ts4_word ts4_if_call_seq_u32_offc_88822A50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    int t2;
    ts4_word t3;
    unsigned char t4;
    unsigned char t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + -16);
    if ((int)t2 == 6) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + -8);
        t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 12);
        if ((ts4_word)t4 == 0) {
            t5 = *(unsigned char *)((char *)(ts4_word)(t3) + 13);
            if ((ts4_word)t5 == 0) {
                lua2_luaU_dump_8881D0A8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 20)), (ts4_word)a1, (ts4_word)a2);
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88833F80: if_call_seq lbl_880E1880, fn_88834CF0, fn_88833E80, fn_88566FE8, fn_88566FE8 */
ts4_word ts4_if_call_seq_lbl_880E1880_88833F80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t7;
    ts4_word t2;
    ts4_word t3;

    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)(ts4_word)lbl_880E1880;
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)0;
    t1 = fn_88834CF0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) == 0) {
        t7 = loc50[1];
        loc50[0] = (ts4_word)(ts4_word)lbl_880E1880;
        if ((ts4_word)t7 != 0 && (ts4_word)(*(unsigned char *)((char *)loc50 + 8)) != 0) {
            fn_88566FE8((ts4_word)t7);
        }
        return 0;
    }
    t2 = fn_88833E80((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    t3 = loc50[1];
    loc50[0] = (ts4_word)(ts4_word)lbl_880E1880;
    if ((ts4_word)t3 != 0 && (ts4_word)(*(unsigned char *)((char *)loc50 + 8)) != 0) {
        fn_88566FE8((ts4_word)t3);
    }
    return t2;
}

/* Swing_DLL.xex 0x88865818: loop_get u32@lbl_88D45B1C, u32@0x234, u32@0x38, u32@0x4, u32@0x0, u32@0xc */
void ts4_loop_get_u32_lbl_88D45B1C_88865818(int a0)
{
    ts4_word c5;
    ts4_word lv6;
    ts4_word p9;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    int t8;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564))) + 56);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
    if ((ts4_word)t4 == 0) {
        return;
    }
    c5 = (ts4_word)t4;
    lv6 = (ts4_word)0;
    do {
        t7 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(((t7 + lv6) + t3)) + 12);
        if ((int)a0 != (int)t8) {
            *(unsigned char *)((char *)(ts4_word)(((t7 + lv6) + t3)) + 25) = (unsigned char)0;
        }
        p9 = (ts4_word)(lv6 + 176);
        lv6 = p9;
    } while (--c5 != 0);
    return;
}

/* Swing_DLL.xex 0x88883C40: get u32@0x0, interlocked_xchg */
void ts4_get_u32_off0_88883C40(ts4_word a0, ts4_word a1)
{
    _InterlockedExchange((volatile long *)(ts4_word)(a0), (long)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return;
}

/* Swing_DLL.xex 0x88883D90: loop_addr lbl_88D3EB60, u32@0x0, u32@0x0, u32@0x0, u32@0x4 */
void ts4_loop_addr_lbl_88D3EB60_88883D90(ts4_word a0)
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
            return;
        }
        p4 = (ts4_word)(lv1 + 520);
        lv1 = p4;
    } while ((ts4_word)p4 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    return;
}

/* Swing_DLL.xex 0x88884560: loop_addr lbl_88D3EB60, u32@0x0, u32@0x0, u32@0x0, u32@0x4, ts4_memset */
ts4_word ts4_loop_addr_lbl_88D3EB60_88884560(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word t3;

    lv1 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        if ((ts4_word)t3 == 0) {
            *(ts4_word *)((char *)(ts4_word)(lv1) + 0) = (ts4_word)a0;
            *(ts4_word *)((char *)(ts4_word)(lv1) + 4) = (ts4_word)a1;
            return ts4_memset((ts4_word)(lv1 + 8), (ts4_word)0, (ts4_word)512);
        }
        p4 = (ts4_word)(lv1 + 520);
        lv1 = p4;
    } while ((ts4_word)p4 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    return a0;
}

/* Swing_DLL.xex 0x88887928: loop_call_seq u32@0x1c, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x0, u32@0x4 */
ts4_word ts4_loop_call_seq_u32_off1c_88887928(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word p11;
    ts4_word lv12;
    ts4_word p18;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    int t5;
    ts4_word t6;
    ts4_word t9;
    int t10;
    ts4_word t14;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564);
    t4 = fn_88614938((ts4_word)t3, (ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    p8 = (ts4_word)0;
    if ((int)t5 != -1) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        p8 = (ts4_word)((((t6 + (t6 << 3)) << 3) + t5) + t4);
    }
    t9 = fn_88614938((ts4_word)t3);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
    p11 = (ts4_word)0;
    if ((int)t10 != -1) {
        p11 = (ts4_word)(t10 + t9);
    }
    if ((ts4_word)p8 != (ts4_word)p11) {
        lv12 = (ts4_word)p11;
        do {
            t14 = *(ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((ts4_word)a1 == (ts4_word)t14) {
                ts4_memset((ts4_word)(lv12 + 4), (ts4_word)0, (ts4_word)64);
                ts4_copy_bytes((ts4_word)(lv12 + 4), (ts4_word)a2, (ts4_word)64);
                t17 = fn_88608590((ts4_word)0, (ts4_word)(lv12 + 4));
                *(ts4_word *)((char *)(ts4_word)(lv12) + 68) = (ts4_word)t17;
                return t17;
            }
            p18 = (ts4_word)(lv12 + 72);
            lv12 = p18;
        } while ((ts4_word)p8 != (ts4_word)p18);
        return t9;
    }
    return t9;
}

/* Swing_DLL.xex 0x88888BA0: call_seq ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000, ts4_tailcall_NetDll_XNetInAddrToString_884EFF00, ts4_assign_formatted_text */
ts4_word ts4_call_seq_ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000_88888BA0(ts4_word a0)
{
    ts4_word loc50[12];
    ts4_word loc80[18];
    ts4_word t2;

    loc50[0] = (ts4_word)0;
    ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000((ts4_word)(ts4_word)&loc50[0]);
    *(unsigned char *)((char *)loc80 + 0) = (unsigned char)0;
    t2 = loc50[0];
    ts4_tailcall_NetDll_XNetInAddrToString_884EFF00((ts4_word)t2, (ts4_word)(ts4_word)&loc80[0], (ts4_word)64);
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)&loc80[0]);
    return a0;
}

/* Swing_DLL.xex 0x888C0210: loop_set  */
void ts4_loop_set_888C0210(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)4;
    lv2 = (ts4_word)0;
    do {
        *(unsigned char *)((char *)(ts4_word)((a0 + 148)) + lv2) = (unsigned char)0;
        p3 = (ts4_word)(lv2 + 1);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Swing_DLL.xex 0x888C0EF8: get u32@0x30, u32@0x34, g_ts4_script_constants */
ts4_word ts4_get_u32_off30_888C0EF8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return (int)(((((float)((double)((ts4_s64)(int)t2))) * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 60))) / ((float)((double)((ts4_s64)(int)t1)))));
}

/* Swing_DLL.xex 0x888C0F50: get u32@0x30, u32@0x34 */
ts4_word ts4_get_u32_off30_888C0F50(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return (int)(((((float)((double)((ts4_s64)(int)t2))) / ((float)((double)((ts4_s64)(int)t1)))) + (*(float *)lbl_8814B910)));
}

/* Swing_DLL.xex 0x888D85B0: if_call_seq fn_8817EA90, fn_888D8368, u32@0x18, u16@0x1c, fn_888CEAA8, ts4_if_call_seq_u32_off4_8817E430 */
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t3;
    unsigned short t4;
    ts4_word t8;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 < 4) {
        fn_8817EA90((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
        t2 = fn_888D8368((ts4_word)a0, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)t2 != 0) {
            t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 24);
            t4 = *(unsigned short *)((char *)(ts4_word)(t2) + 28);
            *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
            loc50[1] = (ts4_word)t3;
            *(unsigned short *)((char *)loc50 + 8) = (unsigned short)t4;
            fn_888CEAA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 & 0xff));
        }
    }
    t8 = ts4_if_call_seq_u32_off4_8817E430((ts4_word)a3);
    return t8;
}

/* Swing_DLL.xex 0x888EE890: loop_call_seq ts4_if_addr_lbl_88D45908_888E7A80, fn_8817C510, lbl_88D45CC0, u32@0x684, ts4_if_call_seq_NtSetEvent_8857C1F8, u32@0x680 */
ts4_word ts4_loop_call_seq_ts4_if_addr_lbl_88D45908_888E7A80_888EE890(void)
{
    ts4_word lv8;
    ts4_word p14;
    ts4_word t1;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t17;

    t1 = ts4_if_addr_lbl_88D45908_888E7A80();
    fn_8817C510((ts4_word)t1);
    ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1668)));
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1664)), (ts4_word)-1);
    t7 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1664);
    lv8 = (ts4_word)(ts4_word)lbl_88D3EB60;
    do {
        t10 = *(ts4_word *)((char *)(ts4_word)(lv8) + 0);
        if ((ts4_word)t7 == (ts4_word)t10) {
            *(ts4_word *)((char *)(ts4_word)(lv8) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(lv8) + 4) = (ts4_word)0;
            ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t7);
            t13 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1668)));
            return t13;
        }
        p14 = (ts4_word)(lv8 + 520);
        lv8 = p14;
    } while ((ts4_word)p14 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
    ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t7);
    t17 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 1668)));
    return t17;
}

/* Swing_DLL.xex 0x8890DA08: loop_get u32@0x0, lbl_88C6B7C0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_8890DA08(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    lv2 = (ts4_word)0;
    lv3 = (ts4_word)(ts4_word)lbl_88C6B7C0;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t5 == (ts4_word)t1) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv2 << 3)) + ((ts4_word)lbl_88C6B7C0 + 4)));
            return;
        }
        p7 = (ts4_word)(lv2 + 1);
        p8 = (ts4_word)(lv3 + 8);
        lv2 = p7;
        lv3 = p8;
    } while ((int)p8 < (int)((ts4_word)lbl_88C6B7C0 + 64));
    return;
}

/* Swing_DLL.xex 0x8890DA58: loop_get u32@0x0, lbl_88C6B760, u32@0x0, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_8890DA58(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    lv2 = (ts4_word)0;
    lv3 = (ts4_word)(ts4_word)lbl_88C6B760;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t5 == (ts4_word)t1) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv2 << 3)) + ((ts4_word)lbl_88C6B760 + 4)));
            return;
        }
        p7 = (ts4_word)(lv2 + 1);
        p8 = (ts4_word)(lv3 + 8);
        lv2 = p7;
        lv3 = p8;
    } while ((int)p8 < (int)((ts4_word)lbl_88C6B760 + 96));
    return;
}

/* Swing_DLL.xex 0x8890F8D8: call_seq u32@0x0, u32@0x28, fn_8890F370, g_ts4_script_constants, fn_8817B608 */
ts4_word ts4_call_seq_u32_off0_8890F8D8(ts4_word a0, ts4_word a1, ts4_word a2, float f1)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    float t3;
    float t4;
    float t5;
    float t7;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(float *)((char *)loc54 + 0) = f1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(a1 + 56);
    loc50[0] = (ts4_word)t1;
    fn_8890F370((ts4_word)(a1 + 56), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
    t3 = *(float *)((char *)(ts4_word)(a1) + 64);
    t4 = *(float *)((char *)loc50 + 0);
    t5 = *(float *)((char *)loc54 + 0);
    *(volatile float *)((char *)(ts4_word)(a0) + 8) = (t3 * (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 388)));
    *(volatile float *)((char *)(ts4_word)(a0) + 4) = t4;
    *(volatile float *)((char *)(ts4_word)(a0) + 16) = t5;
    t7 = *(float *)((char *)(ts4_word)(a1) + 84);
    *(volatile float *)((char *)(ts4_word)(a0) + 12) = ((t4 - (*(float *)((char *)(ts4_word)(a0) + 8))) + t7);
    t9 = fn_8817B608((ts4_word)(a0 + 12));
    return t9;
}

/* Swing_DLL.xex 0x889181D0: if_call_seq u32@0x38, u32@g_ts4_session_context, u8@0x388, u32@0x38, u8@0x2e4, u32@0x40 */
ts4_word ts4_if_call_seq_u32_off38_889181D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_word t23;
    ts4_word t24;
    ts4_word t25;
    ts4_word t27;
    ts4_word t28;
    ts4_word t29;
    ts4_word t31;
    ts4_word t32;
    ts4_word t33;
    ts4_word t35;
    ts4_word t36;
    ts4_word t37;
    ts4_word t39;
    ts4_word t40;
    ts4_word t41;
    ts4_word t43;
    ts4_word t44;
    ts4_word t45;
    ts4_word t47;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t2 = *(ts4_word *)g_ts4_session_context;
    *(unsigned char *)((char *)(ts4_word)(t1) + 904) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 740) = (unsigned char)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 64);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
    if ((ts4_word)t5 > 19) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        *(ts4_word *)((char *)(ts4_word)(t6) + 304) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t6) + 308) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t6) + 312) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t6) + 316) = (ts4_word)0;
    }
    t8 = ts4_if_call_seq_u32_g_ts4_session_context_88916FD0((ts4_word)(a0 + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    ts4_if_get_u32_g_ts4_session_context_88915980((ts4_word)t8);
    t10 = *(ts4_word *)g_ts4_session_context;
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 8);
    if ((ts4_word)t12 > 21) {
        t13 = *(ts4_word *)((char *)(ts4_word)(t11) + 4);
        *(ts4_word *)((char *)(ts4_word)(t13) + 336) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t13) + 340) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t13) + 344) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t13) + 348) = (ts4_word)0;
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 8);
    if ((ts4_word)t16 > 22) {
        t17 = *(ts4_word *)((char *)(ts4_word)(t15) + 4);
        *(ts4_word *)((char *)(ts4_word)(t17) + 352) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t17) + 356) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t17) + 360) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t17) + 364) = (ts4_word)0;
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t20 = *(ts4_word *)((char *)(ts4_word)(t19) + 8);
    if ((ts4_word)t20 > 23) {
        t21 = *(ts4_word *)((char *)(ts4_word)(t19) + 4);
        *(ts4_word *)((char *)(ts4_word)(t21) + 368) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t21) + 372) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t21) + 376) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t21) + 380) = (ts4_word)0;
    }
    t23 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t24 = *(ts4_word *)((char *)(ts4_word)(t23) + 8);
    if ((ts4_word)t24 > 24) {
        t25 = *(ts4_word *)((char *)(ts4_word)(t23) + 4);
        *(ts4_word *)((char *)(ts4_word)(t25) + 384) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t25) + 388) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t25) + 392) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t25) + 396) = (ts4_word)0;
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t28 = *(ts4_word *)((char *)(ts4_word)(t27) + 8);
    if ((ts4_word)t28 > 25) {
        t29 = *(ts4_word *)((char *)(ts4_word)(t27) + 4);
        *(ts4_word *)((char *)(ts4_word)(t29) + 400) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t29) + 404) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t29) + 408) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t29) + 412) = (ts4_word)0;
    }
    t31 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t32 = *(ts4_word *)((char *)(ts4_word)(t31) + 8);
    if ((ts4_word)t32 > 36) {
        t33 = *(ts4_word *)((char *)(ts4_word)(t31) + 4);
        *(ts4_word *)((char *)(ts4_word)(t33) + 576) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t33) + 580) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t33) + 584) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t33) + 588) = (ts4_word)0;
    }
    t35 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t36 = *(ts4_word *)((char *)(ts4_word)(t35) + 8);
    if ((ts4_word)t36 > 37) {
        t37 = *(ts4_word *)((char *)(ts4_word)(t35) + 4);
        *(ts4_word *)((char *)(ts4_word)(t37) + 592) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t37) + 596) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t37) + 600) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t37) + 604) = (ts4_word)0;
    }
    t39 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t40 = *(ts4_word *)((char *)(ts4_word)(t39) + 8);
    if ((ts4_word)t40 > 38) {
        t41 = *(ts4_word *)((char *)(ts4_word)(t39) + 4);
        *(ts4_word *)((char *)(ts4_word)(t41) + 608) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t41) + 612) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t41) + 616) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t41) + 620) = (ts4_word)0;
    }
    t43 = *(ts4_word *)((char *)(ts4_word)(t10) + 64);
    t44 = *(ts4_word *)((char *)(ts4_word)(t43) + 8);
    if ((ts4_word)t44 > 18) {
        t45 = *(ts4_word *)((char *)(ts4_word)(t43) + 4);
        *(ts4_word *)((char *)(ts4_word)(t45) + 288) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t45) + 292) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t45) + 296) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t45) + 300) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t47 = fn_881B9148((ts4_word)(a0 + 16));
    return t47;
}

/* Swing_DLL.xex 0x8891B8E0: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_loop_get_u32_off0_8891B8E0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv11;
    ts4_word p13;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t20;
    ts4_word t23;
    ts4_word t26;
    ts4_word t31;
    ts4_word t32;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    if ((ts4_word)(t7 & 0xff) != 0) {
        if ((int)t6 < 0) {
            p8 = (ts4_word)1;
            p9 = (ts4_word)(-(int)t6);
        } else {
            p8 = (ts4_word)0;
            p9 = (ts4_word)t6;
        }
        t10 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
        if ((ts4_word)(t10 & 0xff) != 0) {
            lv11 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p9 >> lv11) & 0x1));
                p13 = (ts4_word)(lv11 + 1);
                lv11 = p13;
            } while ((ts4_word)p13 < 3);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p8);
    }
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1072));
    t20 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t20);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1076));
    t23 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t23);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1080));
    t26 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t26);
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1084)));
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1088));
    t31 = loc50[0];
    t32 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t31);
    return t32;
}

/* Swing_DLL.xex 0x8891F628: loop_get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_loop_get_u32_off0_8891F628(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv11;
    ts4_word p13;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    int t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t22;
    ts4_word t25;
    ts4_word t28;
    ts4_word t29;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1068);
    t7 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
    if ((ts4_word)(t7 & 0xff) != 0) {
        if ((int)t6 < 0) {
            p8 = (ts4_word)1;
            p9 = (ts4_word)(-(int)t6);
        } else {
            p8 = (ts4_word)0;
            p9 = (ts4_word)t6;
        }
        t10 = fn_88933EF8((ts4_word)a1, (ts4_word)3);
        if ((ts4_word)(t10 & 0xff) != 0) {
            lv11 = (ts4_word)0;
            do {
                fn_88936AF0((ts4_word)a1, (ts4_word)((p9 >> lv11) & 0x1));
                p13 = (ts4_word)(lv11 + 1);
                lv11 = p13;
            } while ((ts4_word)p13 < 3);
        }
        fn_88936AF0((ts4_word)a1, (ts4_word)p8);
    }
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1076));
    t22 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t22);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1080));
    t25 = loc50[0];
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t25);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1084));
    t28 = loc50[0];
    t29 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t28);
    return t29;
}

/* Swing_DLL.xex 0x8891FFD8: call_seq ts4_loop_get_u32_off0_8891B7A0, u32@0x430, ts4_if_call_seq_fn_88933EF8_889396A8, ts4_if_call_seq_fn_88933EF8_889396A8 */
ts4_word ts4_call_seq_ts4_loop_get_u32_off0_8891B7A0_8891FFD8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t5;
    ts4_word t6;

    ts4_loop_get_u32_off0_8891B7A0();
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1076));
    t5 = loc50[0];
    t6 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t5);
    return t6;
}

/* Swing_DLL.xex 0x88920030: call_seq ts4_loop_get_u32_off0_8891B7A0, u32@0x430, ts4_if_call_seq_fn_88933EF8_889396A8, ts4_if_call_seq_fn_88933EF8_889396A8 */
ts4_word ts4_call_seq_ts4_loop_get_u32_off0_8891B7A0_88920030(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t5;
    ts4_word t6;

    ts4_loop_get_u32_off0_8891B7A0();
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a0) + 1076));
    t5 = loc50[0];
    t6 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)t5);
    return t6;
}

/* Swing_DLL.xex 0x88924668: loop_get u32@0x0, lbl_88C6B6C0, u32@0x0, u32@0x0, u32@0x10, u32@0x0 */
void ts4_loop_get_u32_off0_88924668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    lv2 = (ts4_word)0;
    lv3 = (ts4_word)(ts4_word)lbl_88C6B6C0;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t5 == (ts4_word)t1) {
            if ((int)lv2 == -1) {
                return;
            }
            t8 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0))) + (lv2 << 2));
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t8;
            t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 12);
            t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
            *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 12)) + t10);
            *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
            return;
        }
        p13 = (ts4_word)(lv2 + 1);
        p14 = (ts4_word)(lv3 + 4);
        lv2 = p13;
        lv3 = p14;
    } while ((int)p14 < (int)((ts4_word)lbl_88C6B6C0 + 64));
    return;
}

/* Swing_DLL.xex 0x88929200: call_seq u32@0x28, u32@lbl_88D45B38, fn_88613268, lbl_880F7D28, fn_88925640, u32@0x0 */
ts4_word ts4_call_seq_u32_off28_88929200(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[10];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)(t1 + 20), (ts4_word)1, (ts4_word)0, (ts4_word)2);
    loc50[7] = (ts4_word)t3;
    loc50[6] = (ts4_word)(t1 + 20);
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)(ts4_word)lbl_880F7D28;
    loc50[2] = (ts4_word)0;
    loc50[3] = (ts4_word)0;
    loc50[5] = (ts4_word)0;
    loc50[8] = (ts4_word)0;
    *(unsigned char *)((char *)loc50 + 16) = (unsigned char)1;
    fn_88925640((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t1 + 20);
    return t3;
}

/* Swing_DLL.xex 0x8892A460: loop_call_seq lbl_880D6330, u32@0x0, u32@0x4, u32@0x8, u32@0xc, ts4_create_zeroed_triplet */
ts4_word ts4_loop_call_seq_lbl_880D6330_8892A460(ts4_word a0)
{
    ts4_word c2;
    ts4_word lv3;
    ts4_word p4;
    ts4_word t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6330;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t1 = ts4_create_zeroed_triplet();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D67D0;
    c2 = (ts4_word)16;
    lv3 = (ts4_word)(a0 + 20);
    do {
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)0;
        *(volatile unsigned short *)((char *)(ts4_word)(lv3) + 4) = (unsigned short)0;
        *(volatile unsigned short *)((char *)(ts4_word)(lv3) + 6) = (unsigned short)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 24) = (ts4_word)0;
        p4 = (ts4_word)(lv3 + 28);
        lv3 = p4;
    } while (--c2 != 0);
    fn_881705B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)16);
    fn_8892A380((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x8892DA90: if_call_seq u32@0x4, fn_88161540, ts4_span28_append, u32@0x0, fn_8892D5F8 */
ts4_word ts4_if_call_seq_u32_off4_8892DA90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[10];
    int t1;
    ts4_word t5;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    if ((int)t1 != 0) {
        loc50[2] = (ts4_word)a3;
        loc50[3] = (ts4_word)0;
        loc50[5] = (ts4_word)0;
        loc50[4] = (ts4_word)((983040) | 65535);
        *(unsigned char *)((char *)loc50 + 24) = (unsigned char)0;
        ts4_span28_append((ts4_word)a4, (ts4_word)(ts4_word)&loc50[0]);
        t5 = fn_8892D5F8((ts4_word)a0, (ts4_word)a1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + a2), (ts4_word)a4);
        return t5;
    }
    t2 = fn_88161540((ts4_word)a4);
    return t2;
}

/* Swing_DLL.xex 0x88931520: if_get u32@0x0, u32@0xc, vcall, u32@0x8, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_off0_88931520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12))))((ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 < (ts4_word)t4) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t6 = *(ts4_word *)((char *)(ts4_word)(((t3 << 4) + t5)) + 4);
        if ((ts4_word)t6 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t6))((ts4_word)a1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((t3 << 4) + t5)) + 12)));
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88932ED8: loop_get u32@0x14, u32@0x1c, u32@0x18, u32@0x28, u32@0x0, u32@0x28 */
ts4_word ts4_loop_get_u32_off14_88932ED8(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 40);
    if ((ts4_word)t3 != (ts4_word)t2) {
        lv5 = (ts4_word)t3;
        do {
            t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv5) + 0))) + 40);
            if ((ts4_word)t9 != (ts4_word)t4) {
                return 0;
            }
            p10 = (ts4_word)(lv5 + 4);
            lv5 = p10;
        } while ((ts4_word)p10 != (ts4_word)t2);
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x889333A8: loop_get u32@0x0, lbl_88C6B4B0, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_889333A8(ts4_word a0)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    lv2 = (ts4_word)0;
    lv3 = (ts4_word)(ts4_word)lbl_88C6B4B0;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t1 == (ts4_word)t5) {
            return ((lv2 << 4) + (ts4_word)lbl_88C6B4B0);
        }
        p6 = (ts4_word)(lv2 + 1);
        p7 = (ts4_word)(lv3 + 16);
        lv2 = p6;
        lv3 = p7;
    } while ((ts4_word)p6 < 33);
    return 0;
}

/* Swing_DLL.xex 0x88933858: loop_get u32@0xc, u32@0x0, u32@0x4, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_loop_get_u32_offc_88933858(ts4_word a0)
{
    ts4_word lv7;
    ts4_word p18;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    unsigned char t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        return 1;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
    if ((ts4_word)t6 != (ts4_word)t5) {
        lv7 = (ts4_word)t6;
        do {
            t15 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv7) + 8))) + 0))) + 1053);
            if ((ts4_word)t15 == 1) {
                return 1;
            }
            p18 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv7) + 0));
            lv7 = p18;
        } while ((ts4_word)p18 != (ts4_word)t5);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88934018: loop_get u32@0x1c, u32@0x8, u32@0x4, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_loop_get_u32_off1c_88934018(ts4_word a0, int a1)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    int t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t3 != (ts4_word)t2) {
        lv4 = (ts4_word)t3;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
            if ((int)a1 == (int)t8) {
                return t7;
            }
            p9 = (ts4_word)(lv4 + 4);
            lv4 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88934050: loop_get u32@0x1c, u32@0x8, u32@0x4, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_loop_get_u32_off1c_88934050(ts4_word a0, int a1)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    int t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t3 != (ts4_word)t2) {
        lv4 = (ts4_word)t3;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
            if ((int)a1 == (int)t8) {
                return t7;
            }
            p9 = (ts4_word)(lv4 + 4);
            lv4 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x889367A8: if_call_seq u32@0x0, u8@0x41c, u8@0x41d, ts4_if_get_u8_off420_88934FB8 */
ts4_word ts4_if_call_seq_u32_off0_889367A8(ts4_word a0)
{
    ts4_word p4;
    ts4_word p6;
    ts4_word t1;
    unsigned char t2;
    unsigned char t3;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 1052);
    p6 = (ts4_word)14;
    if ((ts4_word)t2 == 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 1053);
        p4 = (ts4_word)47;
        if ((ts4_word)t3 == 0) {
            p4 = (ts4_word)79;
        }
        p6 = (ts4_word)p4;
    }
    t7 = ts4_if_get_u8_off420_88934FB8((ts4_word)t1);
    return (t7 + (((p6 + 7)) >> 3));
}

/* Swing_DLL.xex 0x8893B740: if_get u32@lbl_88C6B4AC, fn_88939288, u32@0x0, u32@0x8, u32@0x4, u32@0x8 */
ts4_word ts4_if_get_u32_lbl_88C6B4AC_8893B740(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    fn_88939288((ts4_word)a1, (ts4_word)a4, (ts4_word)(*(ts4_word *)lbl_88C6B4AC));
    t3 = *(ts4_word *)((char *)(ts4_word)(a4) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 < (ts4_word)t4) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t6 = *(ts4_word *)((char *)(ts4_word)(((t3 << 4) + t5)) + 8);
        if ((ts4_word)t6 != 0) {
            ts4_memset((ts4_word)(ts4_word)lbl_88D3CD50, (ts4_word)0, (ts4_word)3072);
            t8 = *(ts4_word *)((char *)(ts4_word)(((t3 << 4) + t5)) + 8);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t8))((ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((t3 << 4) + t5)) + 12)));
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8893C968: call_seq ts4_if_call_seq_fn_88933EF8_889396A8 */
ts4_word ts4_call_seq_ts4_if_call_seq_fn_88933EF8_889396A8_8893C968(ts4_word a0, float f1)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    *(float *)((char *)loc50 + 0) = f1;
    t1 = loc50[0];
    t2 = ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a0, (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88940D18: if_get u32@0x0, u32@0x30, vcall, ts4_if_get_u32_off0_88940A18, u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88940D18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t5;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)a1);
        return 1;
    }
    ts4_if_get_u32_off0_88940A18((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)(a2 & 0xff) == 1) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
        if ((ts4_word)t5 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 60))))((ts4_word)t5, (ts4_word)a1);
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x88940E48: loop_get u32@0x0, u32@0x3c, vcall, u32@0x40, u32@0x44, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_88940E48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv6;
    ts4_word p12;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t11;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
    if ((ts4_word)(t3 & 0xff) == 0) {
        return 0;
    }
    if ((ts4_word)(a2 & 0xff) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        if ((ts4_word)t4 != (ts4_word)t5) {
            lv6 = (ts4_word)t4;
            do {
                t7 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 60))))((ts4_word)t7, (ts4_word)a1);
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
                p12 = (ts4_word)(lv6 + 4);
                lv6 = p12;
            } while ((ts4_word)p12 != (ts4_word)t11);
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x889445C0: call_seq ts4_chunk_reader_read_8816B5A8 */
ts4_word ts4_call_seq_fn_8816B5A8_889445C0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];

    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a1) + 8));
    ts4_chunk_reader_read_8816B5A8((ts4_word)(a0 + 112), (ts4_word)(ts4_word)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x88945190: call_seq ts4_chunk_reader_read_8816B5A8, ts4_chunk_reader_read_8816B5A8, ts4_chunk_reader_read_8816B5A8 */
ts4_word ts4_call_seq_fn_8816B5A8_88945190(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];

    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a1) + 8));
    ts4_chunk_reader_read_8816B5A8((ts4_word)(a0 + 112), (ts4_word)(ts4_word)&loc50[0]);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a1) + 12));
    ts4_chunk_reader_read_8816B5A8((ts4_word)(a0 + 112), (ts4_word)(ts4_word)&loc50[0]);
    *(float *)((char *)loc50 + 0) = (*(float *)((char *)(ts4_word)(a1) + 16));
    ts4_chunk_reader_read_8816B5A8((ts4_word)(a0 + 112), (ts4_word)(ts4_word)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x88947CF0: if_set u32@0x17c, u32@0x17c */
void ts4_if_set_u32_off17c_88947CF0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != (ts4_word)((2801139712) | 59735) && (ts4_word)a1 != (ts4_word)((465633280) | 29333)) {
        if (((ts4_word)a1 != (ts4_word)((499777536) | 29317) && (ts4_word)a1 != (ts4_word)((4150788096) | 12377)) && (ts4_word)a1 != (ts4_word)((145817600) | 51551)) {
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)((499777536) | 29317);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)((2801139712) | 59735);
    return;
}

/* Swing_DLL.xex 0x88995BC8: call_seq u32@0x6c, fn_88995AB8 */
ts4_word ts4_call_seq_u32_off6c_88995BC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    ts4_word t2;

    loc50[0] = (ts4_word)a1;
    loc50[4] = (ts4_word)a2;
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)1;
    t2 = fn_88995AB8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)), (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8899A5C8: if_call_seq u32@g_ts4_session_context, u32@0x3c, u32@0x2cc, u32@g_ts4_session_context, u32@0x3c, u32@0x2cc */
ts4_word ts4_if_call_seq_u32_g_ts4_session_context_8899A5C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_u64 a5, ts4_word a6, ts4_word a7)
{
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t16;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 716);
        if ((ts4_word)t6 != (ts4_word)((2583166976) | 51440) || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 640)) != (ts4_word)((499777536) | 29317)) {
            t9 = fn_88157F10((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)((3662872576) | 783));
            t10 = *(ts4_word *)g_ts4_session_state;
            t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
            *(ts4_word *)((char *)(ts4_word)(t11) + 20) = (ts4_word)1;
            *(ts4_u64 *)((char *)(ts4_word)(t11) + 24) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 112));
            fn_88151560((ts4_word)t10, (ts4_word)t9);
        }
    }
    t16 = ts4_if_call_seq_fn_88931950_889330D8((ts4_word)a0, (ts4_word)a1);
    return t16;
}

/* Swing_DLL.xex 0x8899D1E8: loop_get u32@0x1c, u32@0x18, u32@0x1c, u32@0x18, u32@0x0, u32@0x60 */
ts4_word ts4_loop_get_u32_off1c_8899D1E8(ts4_word a0, int a1)
{
    ts4_word lv5;
    ts4_word p10;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    int t9;

    if ((int)a1 == 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t4 != (ts4_word)t3) {
        lv5 = (ts4_word)t4;
        do {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 96);
            if ((int)t9 == (int)a1) {
                return t8;
            }
            p10 = (ts4_word)(lv5 + 4);
            lv5 = p10;
        } while ((ts4_word)p10 != (ts4_word)t3);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899D3E0: loop_get u32@0x14, u8@0x2c, u32@0x1c, u32@0x18, u32@0x0, u8@0x44 */
ts4_word ts4_loop_get_u32_off14_8899D3E0(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p10;
    unsigned char t2;
    ts4_word t3;
    ts4_word t4;
    unsigned char t9;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 44);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        if ((ts4_word)t4 != (ts4_word)t3) {
            lv5 = (ts4_word)t4;
            do {
                t9 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv5) + 0))) + 68);
                if ((ts4_word)t9 == 0) {
                    return 0;
                }
                p10 = (ts4_word)(lv5 + 4);
                lv5 = p10;
            } while ((ts4_word)p10 != (ts4_word)t3);
            return 1;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x8899DAB8: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x80, u32@0x0, u32@0x80 */
ts4_word ts4_loop_get_u32_off8_8899DAB8(ts4_word a0, int a1)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 128);
            if ((int)t7 == (int)a1) {
                return t6;
            }
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8899DD40: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x80, u32@0x0, u32@0x80 */
ts4_word ts4_loop_get_u32_off8_8899DD40(ts4_word a0, int a1)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 128);
            if ((int)a1 == (int)t7) {
                return t6;
            }
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x889A2750: loop_get u32@g_ts4_online_state, u32@0x1c, u32@0x8, u32@0x4, u32@0x0, u32@0x80 */
ts4_word ts4_loop_get_u32_g_ts4_online_state_889A2750(int a0)
{
    ts4_word lv5;
    ts4_word p10;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    int t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_online_state)) + 28);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        if ((ts4_word)t4 != (ts4_word)t3) {
            lv5 = (ts4_word)t4;
            do {
                t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
                t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 128);
                if ((int)a0 == (int)t9) {
                    return t8;
                }
                p10 = (ts4_word)(lv5 + 4);
                lv5 = p10;
            } while ((ts4_word)p10 != (ts4_word)t3);
            return 0;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x889BFB60: if_call_seq fn_889BD910, u32@0x0, u16@0xc, u64@0x8, u64@0x10, fn_8864BBB0 */
ts4_word ts4_if_call_seq_fn_889BD910_889BFB60(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;

    t1 = fn_889BD910((ts4_word)1536, (ts4_word)0);
    if ((ts4_word)t1 == 0) {
        p5 = (ts4_word)-1;
    } else {
        *(unsigned short *)((char *)(ts4_word)(t1) + 12) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_u64 *)((char *)(ts4_word)(t1) + 16) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 8));
        fn_8864BBB0((ts4_word)a0, (ts4_word)t1);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x889BFBD0: if_call_seq fn_889BD910, u32@0x0, u16@0xc, u64@0x8, u64@0x10, fn_8864BBB0 */
ts4_word ts4_if_call_seq_fn_889BD910_889BFBD0(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;

    t1 = fn_889BD910((ts4_word)1, (ts4_word)0);
    if ((ts4_word)t1 == 0) {
        p5 = (ts4_word)-1;
    } else {
        *(unsigned short *)((char *)(ts4_word)(t1) + 12) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_u64 *)((char *)(ts4_word)(t1) + 16) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 8));
        fn_8864BBB0((ts4_word)a0, (ts4_word)t1);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x889C0778: if_call_seq fn_889BD910, u32@0x0, u16@0x18, u16@0x10, u16@0x20, u16@0x12 */
ts4_word ts4_if_call_seq_fn_889BD910_889C0778(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    unsigned short t6;
    ts4_word t7;

    t1 = fn_889BD910((ts4_word)23, (ts4_word)0);
    if ((ts4_word)t1 == 0) {
        return -1;
    }
    *(unsigned short *)((char *)(ts4_word)(t1) + 24) = (unsigned short)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(unsigned short *)((char *)(ts4_word)(t1) + 32) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a1) + 16));
    *(unsigned short *)((char *)(ts4_word)(t1) + 34) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a1) + 18));
    ts4_field_set_string_885F8540((ts4_word)t1, (ts4_word)(a1 + 20));
    t6 = *(unsigned short *)((char *)(ts4_word)(a1) + 18);
    if ((ts4_word)t6 != 0) {
        t7 = fn_889BD910((ts4_word)24, (ts4_word)0);
        ts4_field_set_string_885FFC30((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)));
        ts4_field_set_string_885FFCB0((ts4_word)t7, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 40)) + 17));
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 40))) + 36));
        *(ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)t7;
    }
    *(ts4_u64 *)((char *)(ts4_word)(t1) + 16) = (ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)(a1) + 8));
    fn_8864BBB0((ts4_word)a0, (ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x889C56E0: loop_get u32@0x0, u32@0x8, u32@0x0, u32@0x8, u32@0x8, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_889C56E0(ts4_word a0, ts4_word a1)
{
    ts4_word c2;
    ts4_word t1;
    int t3;
    int t4;
    int t6;
    int t7;
    int t9;
    int t10;
    int t12;
    int t13;
    int t15;
    int t16;
    int t18;
    int t19;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    c2 = (ts4_word)111;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t3 < (int)t4) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t3 + 4);
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t6 < (int)t7) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t6 + 4);
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t9 < (int)t10) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t9 + 4);
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t13 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t12 < (int)t13) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t12 + 4);
        }
        t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t16 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t15 < (int)t16) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t15 + 4);
        }
        t18 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t19 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t18 < (int)t19) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t18 + 4);
        }
    } while (--c2 != 0);
    return 0;
}

/* Swing_DLL.xex 0x889C5788: loop_get u32@0x0, u32@0x8, u32@0x0, u32@0x8, u32@0x8, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_889C5788(ts4_word a0, ts4_word a1)
{
    ts4_word c2;
    ts4_word t1;
    int t3;
    int t4;
    int t6;
    int t7;
    int t9;
    int t10;
    int t12;
    int t13;
    int t15;
    int t16;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    c2 = (ts4_word)200;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t3 < (int)t4) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t3 + 4);
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t6 < (int)t7) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t6 + 4);
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t9 < (int)t10) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t9 + 4);
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t13 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t12 < (int)t13) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t12 + 4);
        }
        t15 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t16 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t15 < (int)t16) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t15 + 4);
        }
    } while (--c2 != 0);
    return 0;
}

/* Swing_DLL.xex 0x889D1FC8: addr lbl_88C6B4B0, u32@lbl_88C6B4B0, u32@0x10, u32@0x20, u32@0x30, u32@0x40 */
ts4_word ts4_addr_lbl_88C6B4B0_889D1FC8(void)
{
    *(ts4_word *)lbl_88C6B4B0 = (ts4_word)((3359113216) | 23464);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 16) = (ts4_word)((1865744384) | 65160);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 32) = (ts4_word)((3350265856) | 47176);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 48) = (ts4_word)((2354446336) | 12065);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 64) = (ts4_word)((57475072) | 45351);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 80) = (ts4_word)((3367501824) | 6458);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 96) = (ts4_word)((553254912) | 122);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 112) = (ts4_word)((4196204544) | 16912);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 128) = (ts4_word)((3937468416) | 1025);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 144) = (ts4_word)((3662872576) | 783);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 160) = (ts4_word)((875823104) | 18339);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 176) = (ts4_word)((3649830912) | 25555);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 192) = (ts4_word)((841285632) | 39134);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 208) = (ts4_word)((791609344) | 9050);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 224) = (ts4_word)((3853058048) | 44644);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 240) = (ts4_word)((3958702080) | 27290);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 256) = (ts4_word)((3435659264) | 19291);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 272) = (ts4_word)((2007367680) | 9569);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 288) = (ts4_word)((2453864448) | 19101);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 304) = (ts4_word)((248119296) | 13256);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 320) = (ts4_word)((3740663808) | 6502);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 336) = (ts4_word)((1028915200) | 54398);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 352) = (ts4_word)((1301479424) | 10358);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 368) = (ts4_word)((52887552) | 39258);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 384) = (ts4_word)((3846111232) | 7677);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 400) = (ts4_word)((4271439872) | 53366);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 416) = (ts4_word)((513933312) | 3150);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 432) = (ts4_word)((3886088192) | 17125);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 448) = (ts4_word)((3104374784) | 28902);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 464) = (ts4_word)((2333802496) | 51624);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 480) = (ts4_word)((1407254528) | 11889);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 496) = (ts4_word)((2349006848) | 58833);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6B4B0) + 512) = (ts4_word)((1871118336) | 52045);
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF000);
}

/* Swing_DLL.xex 0x889D30B0: loop_addr lbl_88D48CC0, u32@0x48, u32@0x50, u32@0x0, ts4_noop_88AFF320, fn_88563470 */
ts4_word ts4_loop_addr_lbl_88D48CC0_889D30B0(void)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)20;
    lv2 = (ts4_word)((ts4_word)lbl_88D48CC0 + -8);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 72) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(lv2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 76)) + 0) = (ts4_word)((983040) | 65535);
        p3 = (ts4_word)(lv2 + 76);
        lv2 = p3;
    } while (--c1 != 0);
    return fn_88563470((ts4_word)(ts4_word)ts4_noop_88AFF320);
}
