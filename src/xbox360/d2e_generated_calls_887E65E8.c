/* Swing_DLL.xex 0x887E65E8-0x888841D8, executable version 0.0.0.3. */
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

extern char lbl_8803A308[];
extern char lbl_88087B80[];
extern char lbl_88088DD4[];
extern char lbl_880C1320[];
extern char lbl_880C9684[];
extern char lbl_880C9748[];
extern char lbl_880C9758[];
extern char lbl_880D91F4[];
extern char lbl_880DF600[];
extern char lbl_880DF618[];
extern char lbl_880DF62C[];
extern char lbl_880DF824[];
extern char lbl_880DF840[];
extern char lbl_880DF84C[];
extern char lbl_880DF860[];
extern char lbl_880DF874[];
extern char lbl_880DF878[];
extern char lbl_880DF8AC[];
extern char lbl_880DF900[];
extern char lbl_880DF968[];
extern char lbl_880DF9D0[];
extern char lbl_880DFC6C[];
extern char lbl_880E0728[];
extern char lbl_880E1048[];
extern char lbl_880E13DC[];
extern char lbl_880E13EC[];
extern char lbl_880E13F8[];
extern char lbl_880E167C[];
extern char lbl_880E16A4[];
extern char lbl_880E16AC[];
extern char lbl_880E1C98[];
extern char lbl_880E1E54[];
extern char lbl_880E1F70[];
extern char lbl_880E2550[];
extern char lbl_880E25A0[];
extern char lbl_880E25A8[];
extern char lbl_880E25AC[];
extern char lbl_880E25B4[];
extern char lbl_880E2A14[];
extern char lbl_880E2AB8[];
extern char lbl_880E2FBC[];
extern char lbl_880E2FD4[];
extern char lbl_880E3004[];
extern char lbl_880E3018[];
extern char lbl_880E3638[];
extern char lbl_880E3644[];
extern char lbl_880E3658[];
extern char lbl_880E3E74[];
extern char lbl_8814B440[];
extern char lbl_88D452A0[];
extern char lbl_88D4598E[];
extern char lbl_88D459D4[];
extern char lbl_88D459DC[];
extern char lbl_88D459E8[];
extern char lbl_88D45A04[];
extern char lbl_88D45B20[];
extern char lbl_88D45B24[];
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88161620();
ts4_word fn_881640A8();
ts4_word fn_8816CAA0();
ts4_word fn_881898E8();
ts4_word fn_8819AE68();
ts4_word fn_8819C190();
ts4_word fn_881A50F0();
ts4_word fn_881A62E8();
ts4_word fn_881A6A00();
ts4_word ts4_loop_call_seq_u32_off4_881A7108();
ts4_word fn_881A7A20();
ts4_word fn_881A9BE8();
ts4_word fn_881AB108();
ts4_word ts4_find_record_by_key_881AD020();
ts4_word fn_881AD8E0();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_8846F580();
ts4_word fn_88474078();
ts4_word fn_88474B90();
ts4_word fn_88569D30();
ts4_word fn_88581AF0();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88619E50();
ts4_word fn_8862A1F0();
ts4_word fn_887D9C90();
ts4_word ts4_if_call_seq_u32_offc_887E6550();
ts4_word fn_887EB4A0();
ts4_word ts4_if_call_seq_lbl_880E3E3C_887FC130();
ts4_word fn_88804058();
ts4_word ts4_call_seq_u32_off3c_88805AF0();
ts4_word ts4_call_seq_u32_off3c_88805C38();
ts4_word ts4_call_seq_u32_off3c_88805C90();
ts4_word ts4_call_seq_u32_off3c_88805D10();
ts4_word ts4_call_seq_u32_off3c_88806070();
ts4_word ts4_call_seq_u32_off3c_888061B8();
ts4_word ts4_call_seq_fn_88832F70_88806570();
ts4_word lua2_lua_close_88813BA8();
ts4_word lua2_removevars_88814470();
ts4_word ts4_loop_call_seq_fn_88814418_88814950();
ts4_word lua2_create_local_88814A70();
ts4_word lua2_next_88814BB8();
ts4_word lua2_close_func_88814D20();
ts4_word lua2_pushclosure_88814E68();
ts4_word lua2_parlist_88815428();
ts4_word lua2_check_match_88815580();
ts4_word lua2_check_88815628();
ts4_word lua2_subexpr_88816C30();
ts4_word lua2_chunk_88817818();
ts4_word lua3_luaO_chunkid_88817F88();
ts4_word lua2_luaX_syntaxerror_888195F0();
ts4_word lua2_DumpBlock_8881C828();
ts4_word lua2_DumpVector_8881C8B8();
ts4_word lua2_luaD_reallocCI_8881D170();
ts4_word lua2_luaK_concat_888203F0();
ts4_word lua2_luaK_patchlistaux_88820468();
ts4_word lua2_luaK_code_888208A8();
ts4_word lua2_luaK_stringK_88820AF0();
ts4_word lua2_luaK_dischargevars_88820C30();
ts4_word lua2_luaK_exp2nextreg_888214B0();
ts4_word lua2_luaK_goiffalse_88821568();
ts4_word lua2_luaK_goiftrue_88821618();
ts4_word lua2_luaK_exp2anyreg_888216D0();
ts4_word lua2_luaK_exp2RK_88821878();
ts4_word fn_88822398();
ts4_word fn_88822DB0();
ts4_word fn_88823768();
ts4_word fn_88823AE8();
ts4_word fn_88823FC0();
ts4_word fn_88824188();
ts4_word fn_88824248();
ts4_word lua3_lua_settop_888246A8();
ts4_word fn_88824B68();
ts4_word ts4_match_class_88824F38();
ts4_word lib3_matchbracketclass_88825118();
ts4_word fn_88829550();
ts4_word lib3_emptybuffer_8882DE88();
ts4_word lib3_getmetafield_tail_8882E218();
ts4_word lib3_luaL_argerror_8882E6B8();
ts4_word lib3_luaL_typerror_8882E950();
ts4_word ts4_match_flag_char_8882EED0();
ts4_word lib3_wmatchbracketclass_8882F1E8();
ts4_word lua3_wstr_format_888319E0();
ts4_word ts4_call_seq_u32_off0_88832F70();
ts4_word fn_888368B0();
ts4_word fn_88838B00();
ts4_word ts4_member_field_addr_8883B578();
ts4_word fn_8883DDA0();
ts4_word fn_888429E8();
ts4_word fn_88843650();
ts4_word fn_8884C160();
ts4_word ts4_hash_lookup_null_release_clear_8884CB50();
ts4_word fn_88864E48();
ts4_word fn_88865AB0();
ts4_word fn_88866980();
ts4_word fn_88866DA0();
ts4_word fn_88867E68();
ts4_word ts4_hash_lookup_null_888689A8();
ts4_word fn_88868B48();
ts4_word fn_888690F0();
ts4_word fn_88869530();
ts4_word fn_8886B1B0();
ts4_word fn_8886B5C0();
ts4_word fn_8886F9A0();
ts4_word fn_88870220();
ts4_word fn_888708D8();
ts4_word fn_88879AA8();
ts4_word fn_88879B28();
ts4_word fn_8887EEB0();
ts4_word fn_88882868();
ts4_word fn_889254C8();
ts4_word ts4_if_call_seq_u32_off0_889C6EF0();
ts4_word fn_889CE7D8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_adler32_88878A90();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_u32_off34_888145C8();
ts4_word ts4_call_seq_u32_off3c_88805288();
ts4_word ts4_crc32_big_88878408();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_get_u32_off0_888352B8();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word ts4_if_call_seq_u32_off48_88871778();
ts4_word ts4_keyed_item_list_add_unique_if_mode_8887DA90();
ts4_word ts4_keyed_item_list_add_unique_if_mode_8887DF50();
ts4_word ts4_keyed_item_list_add_unique_if_mode_8887E328();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_tailcall_fn_88564208_885643D0();





/* Swing_DLL.xex 0x888083C0: if_get fn_88804058, u32@0x0, u32@0x28, vcall, ts4_call_seq_u32_off3c_88805AF0, ts4_call_seq_u32_off3c_88806070 */
ts4_word ts4_if_get_fn_88804058_888083C0(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t12;
    ts4_word t13;
    unsigned char t17;
    unsigned char t21;
    ts4_word t25;

    fn_88804058();
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    ts4_call_seq_u32_off3c_88805AF0((ts4_word)a0);
    ts4_call_seq_u32_off3c_88806070((ts4_word)a0);
    ts4_call_seq_u32_off3c_88805D10((ts4_word)a0);
    ts4_call_seq_u32_off3c_888061B8((ts4_word)a0);
    ts4_call_seq_u32_off3c_88805C90((ts4_word)a0);
    ts4_call_seq_u32_off3c_88805C38((ts4_word)a0);
    ts4_call_seq_u32_off3c_88805288((ts4_word)a0);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t13 = *(ts4_word *)((char *)(ts4_word)(t12) + 0);
    loc60[2] = (ts4_word)0;
    loc60[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)t12, (ts4_word)(t13 + 72));
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3658, (ts4_word)(ts4_word)&loc50[0]);
    fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    t17 = *(unsigned char *)((char *)(ts4_word)(a0) + 65);
    if ((ts4_word)t17 == 1) {
        ts4_get_u32_off0_888352B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    }
    t21 = *(unsigned char *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t21 == 1) {
        *(unsigned char *)lbl_88D4598E = (unsigned char)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    t25 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    return t25;
}













/* Swing_DLL.xex 0x8881C630: if_get u32@0x14, u32@0x68, u32@0xc, u32@0x10, vcall, u32@0x60 */
ts4_word ts4_if_get_u32_off14_8881C630(ts4_word a0)
{
    ts4_word p15;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t14;
    ts4_word t21;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t3))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16)), (ts4_word)0, (ts4_word)0, (ts4_word)76, (ts4_word)0, (ts4_word)t2);
    p15 = (ts4_word)t5;
    if ((ts4_word)t5 == 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        if ((ts4_word)t7 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t7) + 1360) = (ts4_word)4;
            fn_88569D30((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96)) + 16), (ts4_word)1);
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 48))))((ts4_word)a0);
        t14 = ts4_tailcall_fn_88564208_885643D0((ts4_word)1);
        p15 = (ts4_word)t14;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) + 76);
    *(unsigned short *)((char *)(ts4_word)(p15) + 10) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 20);
    *(ts4_word *)((char *)(ts4_word)(p15) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 20));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 20) = (ts4_word)p15;
    t21 = *(ts4_word *)((char *)(ts4_word)(p15) + 0);
    if ((ts4_word)t21 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)p15;
    }
    *(unsigned char *)((char *)(ts4_word)(p15) + 9) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(p15) + 8) = (unsigned char)10;
    *(ts4_word *)((char *)(ts4_word)(p15) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 40) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(p15) + 72) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 32) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(p15) + 73) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(p15) + 74) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(p15) + 75) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(p15) + 36) = (ts4_word)0;
    return p15;
}



























/* Swing_DLL.xex 0x8883DE38: if_call_seq ts4_member_field_addr_8883B578, u32@0x8, u32@0x8, u32@0x8, u32@0x8, u32@0x8 */
ts4_word ts4_if_call_seq_fn_8883B578_8883DE38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t16;
    ts4_word t2;

    t1 = ts4_member_field_addr_8883B578((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)a2 != (ts4_word)((3354329088) | 46281) && (ts4_word)a2 != (ts4_word)((3061645312) | 4295)) {
        if ((ts4_word)a2 == (ts4_word)((1038090240) | 35242) || (ts4_word)a2 == (ts4_word)((1282539520) | 11684)) {
            t16 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
            if ((ts4_word)(a3 & 0xff) == 1) {
                if ((ts4_word)t16 != (ts4_word)((3751936000) | 45041)) {
                    if ((ts4_word)t16 == (ts4_word)((1963655168) | 23056)) {
                        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((1541931008) | 38447);
                    }
                } else {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((3663003648) | 18518);
                }
            } else {
                if ((ts4_word)t16 == (ts4_word)((3663003648) | 18518)) {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((3751936000) | 45041);
                } else {
                    if ((ts4_word)t16 == (ts4_word)((1541931008) | 38447)) {
                        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((1963655168) | 23056);
                    }
                }
            }
        }
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
        if ((ts4_word)(a3 & 0xff) == 1) {
            if ((ts4_word)t2 == (ts4_word)((3751936000) | 45041)) {
                *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((1963655168) | 23056);
            } else {
                if ((ts4_word)t2 == (ts4_word)((3663003648) | 18518)) {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((1541931008) | 38447);
                }
            }
        } else {
            if ((ts4_word)t2 == (ts4_word)((1963655168) | 23056)) {
                *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((3751936000) | 45041);
            } else {
                if ((ts4_word)t2 == (ts4_word)((1541931008) | 38447)) {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((3663003648) | 18518);
                }
            }
        }
    }
    return t1;
}












/* Swing_DLL.xex 0x8884FEA8: if_get u32@0x34, u32@0x8, u32@0xc, u32@0x10, u32@0x18, u32@0x14 */
ts4_word ts4_if_get_u32_off34_8884FEA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t3;
    int t9;
    ts4_word t10;
    int t16;
    ts4_word t17;
    int t23;
    ts4_word t24;
    ts4_word t30;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
        fn_881AD8E0((ts4_word)(t1 + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 0))))((ts4_word)t3, (ts4_word)1);
        }
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((int)t9 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t9) + 12) = (ts4_word)0;
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
        if ((ts4_word)t10 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 0))))((ts4_word)t10, (ts4_word)1);
        }
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t16 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t16) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 44) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 48) = (ts4_word)0;
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        if ((ts4_word)t17 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t17) + 0))) + 0))))((ts4_word)t17, (ts4_word)1);
        }
    }
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((int)t23 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t23) + 8) = (ts4_word)0;
        t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
        if ((ts4_word)t24 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t24) + 0))) + 0))))((ts4_word)t24, (ts4_word)1);
        }
    }
    t30 = ts4_hash_lookup_null_release_clear_8884CB50((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return t30;
}












/* Swing_DLL.xex 0x88870C28: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off0_88870C28(ts4_word a0, ts4_word a1)
{
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 84), (ts4_word)1);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 88), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 92), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 96), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 100), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 104), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 108), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 112), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 116), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 124), (ts4_word)4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(a0 + 128), (ts4_word)4);
    fn_888708D8((ts4_word)a0, (ts4_word)a1, (ts4_word)(a0 + 100), (ts4_word)(a0 + 88));
    fn_88870220((ts4_word)(a0 + 12), (ts4_word)a1, (ts4_word)(a0 + 104), (ts4_word)(a0 + 88));
    return 1;
}





/* Swing_DLL.xex 0x88878E90: call_seq u32@0x0, ts4_if_call_seq_u32_off0_889C6EF0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88878E90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    t2 = ts4_if_call_seq_u32_off0_889C6EF0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
    return t2;
}

/* Swing_DLL.xex 0x88878ED0: call_seq u32@0x0, ts4_if_call_seq_u32_off0_889C6EF0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88878ED0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = ts4_if_call_seq_u32_off0_889C6EF0((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3, (ts4_word)a4);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    return t2;
}

/* Swing_DLL.xex 0x88878F30: call_seq fn_88617D88, lbl_88D452A0, lbl_880DF9D0, u32@lbl_88D45B24, u32@0x0, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88878F30(ts4_word a0)
{
    ts4_word t2;

    fn_88617D88((ts4_word)a0);
    t2 = *(ts4_word *)lbl_88D45B24;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF9D0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)2;
    *(ts4_word *)lbl_88D45B24 = (ts4_word)(t2 + 1);
    *(ts4_word *)((char *)(ts4_word)((t2 << 2)) + (ts4_word)lbl_88D452A0) = (ts4_word)a0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x888799D0: if_get u32@0x28, u32@0x0, u32@0x18, vcall, u32@0x14, u32@0x24 */
ts4_word ts4_if_get_u32_off28_888799D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    int t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((int)t1 == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p10 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        t9 = memcpy((ts4_word)t6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)), (ts4_word)(t7 << 6));
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88879A30: if_get u32@0x28, u32@0x20, u32@0x28, u32@0x20, u32@0x0, u32@0x14 */
ts4_word ts4_if_get_u32_off28_88879A30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((int)t1 == 0) {
        return a0;
    }
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 + -1);
        if ((int)t2 > 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t2 + -1);
        }
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x88879E68: loop_get u32@0x40, u32@0x44, u32@0x0, u32@0x14, u32@0x0 */
ts4_word ts4_loop_get_u32_off40_88879E68(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0)) == (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 20))) {
                return t4;
            }
            p7 = (ts4_word)(lv3 + 4);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t2);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8887A350: if_call_seq lbl_880DF840, lbl_880DF84C, lbl_880DF860, u32@0x0, u32@0x8, u32@0xc */
ts4_word ts4_if_call_seq_lbl_880DF840_8887A350(ts4_word a0)
{
    ts4_word t4;
    int t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF840;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880DF84C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)lbl_880DF860;
    fn_88474078((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(a0 + 8));
    t4 = fn_88474B90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(a0 + 12));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 20) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)((a0 + 12)) + 0) = (ts4_word)(ts4_word)lbl_88087B80;
    *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0) = (ts4_word)(ts4_word)lbl_88088DD4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return t4;
}

/* Swing_DLL.xex 0x8887B3D8: loop_get u32@0x40, u32@0x44, u32@0x0, u32@0x14, u32@0x0, fn_88879AA8 */
ts4_word ts4_loop_get_u32_off40_8887B3D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return a0;
    }
    lv3 = (ts4_word)t1;
    do {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0)) == (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 20))) {
            return fn_88879AA8((ts4_word)t4);
        }
        p7 = (ts4_word)(lv3 + 4);
        lv3 = p7;
    } while ((ts4_word)p7 != (ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x8887B418: loop_get u32@0x40, u32@0x44, u32@0x0, u32@0x14, u32@0x0, fn_88879B28 */
ts4_word ts4_loop_get_u32_off40_8887B418(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return a0;
    }
    lv3 = (ts4_word)t1;
    do {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0)) == (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 20))) {
            return fn_88879B28((ts4_word)t4);
        }
        p7 = (ts4_word)(lv3 + 4);
        lv3 = p7;
    } while ((ts4_word)p7 != (ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x8887C3B8: loop_call_seq u32@0x40, u32@0x44, u32@0x0, u32@0x14, u32@0x0, fn_881898E8 */
ts4_word ts4_loop_call_seq_u32_off40_8887C3B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a3;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0)) == (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 20))) {
                loc50[0] = (ts4_word)a1;
                p8 = (ts4_word)a0;
                if ((ts4_word)a1 != 0) {
                    t7 = fn_881898E8((ts4_word)(t4 + 40), (ts4_word)(ts4_word)&loc50[0]);
                    p8 = (ts4_word)t7;
                }
                return p8;
            }
            p9 = (ts4_word)(lv3 + 4);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        return a0;
    }
    return a0;
}

/* Swing_DLL.xex 0x8887C438: loop_call_seq u32@0x40, u32@0x44, u32@0x0, u32@0x14, u32@0x0, fn_881898E8 */
ts4_word ts4_loop_call_seq_u32_off40_8887C438(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a3;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a2) + 0)) == (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 20))) {
                loc50[0] = (ts4_word)a1;
                p8 = (ts4_word)a0;
                if ((ts4_word)a1 != 0) {
                    t7 = fn_881898E8((ts4_word)(t4 + 28), (ts4_word)(ts4_word)&loc50[0]);
                    p8 = (ts4_word)t7;
                }
                return p8;
            }
            p9 = (ts4_word)(lv3 + 4);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t2);
        return a0;
    }
    return a0;
}

/* Swing_DLL.xex 0x8887C4C0: if_get u32@0x14, u32@0x0, u32@0x0, vcall, u32@0x14, u32@0x10 */
ts4_word ts4_if_get_u32_off14_8887C4C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t6 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t7 = fn_88161620((ts4_word)(a0 + 324));
    *(unsigned char *)((char *)(ts4_word)(a0) + 440) = (unsigned char)0;
    return t7;
}

/* Swing_DLL.xex 0x8887D8A0: if_call_seq lbl_880DF878, u32@0x0, u32@0x74, ts4_destroy_owned_object, fn_881A6A00, fn_881A6A00 */
ts4_word ts4_if_call_seq_lbl_880DF878_8887D8A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p14;
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF878;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    fn_881A6A00((ts4_word)(a0 + 104));
    fn_881A6A00((ts4_word)(a0 + 92));
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    p14 = (ts4_word)t12;
    if ((ts4_word)t12 != 0) {
        t13 = ts4_destroy_owned_object((ts4_word)t12);
        p14 = (ts4_word)t13;
    }
    return p14;
}

/* Swing_DLL.xex 0x8887D9E0: if_call_seq lbl_880DF824, u32@0x0, u32@0x28, ts4_destroy_owned_object, u32@0x1c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DF824_8887D9E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF824;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8887E408: if_call_seq lbl_880DF8AC, u32@0x0, u32@0x2c, ts4_destroy_owned_object, u32@0x20, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DF8AC_8887E408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF8AC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8887E460: addr lbl_880DF8AC, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880DF8AC_8887E460(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF8AC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8887E558: call_seq lbl_880DF600, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_if_mode_8887DA90, lbl_880DF618, fn_88608590 */
ts4_word ts4_call_seq_lbl_880DF600_8887E558(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF600);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_if_mode_8887DA90((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF618);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_if_mode_8887E328((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880DF62C);
    loc50[0] = (ts4_word)t7;
    t9 = ts4_keyed_item_list_add_unique_if_mode_8887DF50((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x8887EB98: if_call_seq lbl_880DF874, u32@0x0, u32@0x144, ts4_destroy_owned_object, fn_881A62E8 */
ts4_word ts4_if_call_seq_lbl_880DF874_8887EB98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF874;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 324);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_881A62E8((ts4_word)(a0 + 132));
    return t4;
}

/* Swing_DLL.xex 0x8887EE08: if_call_seq lbl_880DF968, u32@0x0, u32@0x20, u32@0x1c, ts4_loop_call_seq_u32_off0_88150378, u32@0x1c */
ts4_word ts4_if_call_seq_lbl_880DF968_8887EE08(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF968;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8887EE60: call_seq fn_88617D88, lbl_880DF968, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_8887EE60(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF968;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88880168: if_call_seq fn_8887EEB0, u32@0x2c, u32@0x2c, u32@0x8, fn_8846F580 */
ts4_word ts4_if_call_seq_fn_8887EEB0_88880168(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t4;

    t1 = fn_8887EEB0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t2 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p5 = (ts4_word)t3;
    if ((int)t3 != 0) {
        t4 = fn_8846F580((ts4_word)t3, (ts4_word)a0, (ts4_word)0, (ts4_word)1);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x888801C0: if_call_seq fn_8887EEB0, u8@0xd8, u8@0xd8, u16@0x2a, u16@0x2a, u16@0x2a */
ts4_word ts4_if_call_seq_fn_8887EEB0_888801C0(ts4_word a0)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    unsigned char t3;
    unsigned short t5;
    int t6;
    ts4_word t7;

    t1 = fn_8887EEB0();
    p9 = (ts4_word)t1;
    if ((ts4_word)a0 != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 216);
        if ((ts4_word)t3 == 6) {
            *(volatile unsigned short *)((char *)(ts4_word)(a0) + 42) = (unsigned short)9;
        }
        t5 = *(unsigned short *)((char *)(ts4_word)(a0) + 42);
        if ((ts4_word)t5 == 4) {
            *(volatile unsigned short *)((char *)(ts4_word)(a0) + 42) = (unsigned short)t5;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t1;
        p8 = (ts4_word)t1;
        if ((int)t6 != 0) {
            t7 = fn_8846F580((ts4_word)t6, (ts4_word)a0, (ts4_word)0, (ts4_word)1);
            p8 = (ts4_word)t7;
        }
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x888803C0: if_call_seq lbl_880DF900, u32@0x0, u32@0x18, u32@0x14, ts4_loop_call_seq_u32_off4_881A7108, u32@0x14 */
ts4_word ts4_if_call_seq_lbl_880DF900_888803C0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF900;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    ts4_loop_call_seq_u32_off4_881A7108((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88880410: addr lbl_880DF900, u8@0x8, u32@0x0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_addr_lbl_880DF900_88880410(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF900;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}



