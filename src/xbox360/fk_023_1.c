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

extern char lib3_auxwrap_8882BEC0[];
extern char ts4_if_get_u32_off4_8882DB60[];
extern char fn_88834E10[];
extern char lbl_880C1320[];
extern char lbl_880C9684[];
extern char lbl_880E1614[];
extern char lbl_880E1628[];
extern char lbl_880E1638[];
extern char lbl_880E164C[];
extern char lbl_880E1674[];
extern char lbl_880E16A4[];
extern char lbl_880E16D4[];
extern char lbl_880E16FC[];
extern char lbl_880E174C[];
extern char lbl_880E17A4[];
extern char lbl_880E17D0[];
extern char lbl_880E1880[];
extern char lbl_880E18EC[];
extern char lbl_880E1C98[];
extern char lbl_880E2028[];
extern char lbl_880E2B10[];
extern char lbl_880E302C[];
extern char lbl_880E3038[];
extern char lbl_880E3044[];
extern char lbl_880E3738[];
extern char lbl_880E3798[];
extern char lbl_880E37D8[];
extern char lbl_880E3818[];
extern char lbl_880E3828[];
extern char lbl_880E3838[];
extern char lbl_88C6A108[];
extern char lbl_88D459E0[];
extern char lbl_88D459E4[];
extern char lbl_88D459E8[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
ts4_word fn_88150600();
ts4_word fn_8816D1A8();
ts4_word fn_881AD8E0();
ts4_word fn_881AD968();
ts4_word fn_881AD9C8();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AE608();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B1A98();
ts4_word ts4_call_seq_u32_off0_881B1C90();
ts4_word fn_881B3640();
ts4_word ts4_if_get_u32_lbl_88D45B1C_881B3778();
ts4_word fn_881B9148();
ts4_word fn_88562EF8();
ts4_word ts4_tailcall_fn_88564208_885643D0();
ts4_word fn_885651F8();
ts4_word fn_88565320();
ts4_word fn_88569D30();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_88611620();
ts4_word fn_88617788();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88804B18();
ts4_word fn_8880C738();
ts4_word lua2_luaV_settable_8880D278();
ts4_word lua2_LoadBlock_888102D8();
ts4_word lua2_LoadHeader_88810408();
ts4_word lua2_LoadFunction_88810F00();
ts4_word lua2_setnodevector_88811688();
ts4_word lua2_setarrayvector_88811768();
ts4_word fn_88811930();
ts4_word ts4_if_call_seq_fn_889CE718_88811AC0();
ts4_word fn_88811B98();
ts4_word ts4_if_call_seq_u32_off0_88812188();
ts4_word lua2_resize_88812378();
ts4_word lua2_freestack_88813598();
ts4_word lua2_lua_open_888140E0();
ts4_word lua2_next_88814BB8();
ts4_word lua2_block_888153C0();
ts4_word fn_888154C8();
ts4_word lua2_check_match_88815580();
ts4_word lua2_check_88815628();
ts4_word lua2_subexpr_88816C30();
ts4_word fn_88817030();
ts4_word fn_888182A8();
ts4_word fn_888188F8();
ts4_word lua2_luaX_errorline_88819520();
ts4_word lua2_luaX_syntaxerror_888195F0();
ts4_word lua2_luaX_lex_8881A6E8();
ts4_word lua2_checkSizes_8881AB98();
ts4_word lua2_cleartablevalues_8881B108();
ts4_word lua2_cleartablekeys_8881B230();
ts4_word lua2_luaC_separateudata_8881B770();
ts4_word lua2_marktmu_8881B888();
ts4_word lua2_luaC_callGCTM_8881B950();
ts4_word lua2_markroot_8881BE58();
ts4_word lua2_luaC_sweep_8881BF80();
ts4_word lua2_propagatemarks_8881C030();
ts4_word ts4_call_seq_u32_off14_8881C130();
ts4_word lua2_luaF_close_8881C3C0();
ts4_word fn_8881C630();
ts4_word lua2_luaD_call_8881E258();
ts4_word lua2_luaK_concat_888203F0();
ts4_word lua2_luaK_patchlistaux_88820468();
ts4_word lua2_luaK_code_888208A8();
ts4_word lua2_luaK_dischargevars_88820C30();
ts4_word lua2_luaK_exp2RK_88821878();
ts4_word lib3_lua_negindex_88821F98();
ts4_word lib3_lua_touserdata_88822230();
ts4_word lib3_lua_type_88822738();
ts4_word lib3_lua_tostring_88822888();
ts4_word lib3_lua_getglobal_top_88823BA8();
ts4_word fn_88823C98();
ts4_word lib3_lua_pushcclosure_88823E00();
ts4_word fn_88823FC0();
ts4_word fn_88824188();
ts4_word fn_88824438();
ts4_word fn_888246A8();
ts4_word lib3_lua_load_buffer_88824CF8();
ts4_word lib3_capture_to_close_88825A50();
ts4_word lib3_match_88825EF0();
ts4_word fn_8882AA90();
ts4_word lib3_has_fenv_8882B4F8();
ts4_word fn_8882B6A8();
ts4_word fn_8882D360();
ts4_word lib3_adjuststack_8882DBA8();
ts4_word lib3_emptybuffer_8882DE88();
ts4_word lib3_aux_do_8882E368();
ts4_word lib3_luaL_argerror_8882E6B8();
ts4_word lib3_luaL_addlstring_8882E828();
ts4_word lib3_lua_dostring_8882ED00();
ts4_word fn_8882FA70();
ts4_word fn_8882FEF8();
ts4_word fn_888345F8();
ts4_word fn_888350C8();
ts4_word fn_88835240();
ts4_word ts4_if_call_seq_u32_off58_88835468();
ts4_word fn_888354D8();
ts4_word fn_88835D88();
ts4_word fn_888364F8();
ts4_word fn_888368B0();
ts4_word fn_88836968();
ts4_word fn_888374C8();
ts4_word fn_88837880();
ts4_word ts4_member_field_addr_8883B318();
ts4_word ts4_member_field_addr_8883B388();
ts4_word ts4_member_field_addr_8883B578();
ts4_word fn_8883B5E8();
ts4_word fn_8883B748();
ts4_word fn_8883CC80();
ts4_word fn_8883EF20();
ts4_word fn_8883F0C0();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_8883F508();
ts4_word fn_88840B50();
ts4_word fn_88840F30();
ts4_word fn_88843768();
ts4_word fn_888443A8();
ts4_word fn_88846890();
ts4_word fn_888468F0();
ts4_word fn_88847B38();
ts4_word fn_88847D88();
ts4_word ts4_hash_find_null_88848DF0();
ts4_word fn_88848E80();
ts4_word fn_8884A320();
ts4_word fn_8884A8F8();
ts4_word fn_8884C5E0();
ts4_word fn_8884C7A8();
ts4_word fn_8884CEA8();
ts4_word fn_8884CF80();
ts4_word fn_8884E000();
ts4_word fn_8884F638();
ts4_word fn_8884FEA8();
ts4_word fn_88850028();
ts4_word fn_888502F8();
ts4_word fn_888514B0();
ts4_word fn_88851628();
ts4_word fn_888522D0();
ts4_word fn_88854258();
ts4_word ts4_call_seq_u32_off1c_88855E98();
ts4_word fn_889254C8();
ts4_word fn_88925640();
ts4_word fn_889CE718();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_build_name_from_two_literals_8883AEE0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_keyed_item_list_add_unique_8883EAF8();
ts4_word ts4_keyed_item_list_add_unique_888416A8();
ts4_word ts4_keyed_item_list_add_unique_88841FE0();
ts4_word ts4_keyed_item_list_add_unique_88842C30();
ts4_word ts4_object_finalize();

/* Swing_DLL.xex 0x888145C8: call_seq u32@0x34, fn_8881C630, u32@0x0, u32@0x30, u32@0x8, u32@0xc */
ts4_word ts4_call_seq_u32_off34_888145C8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t6;

    t2 = fn_8881C630((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)0;
    t6 = ts4_if_call_seq_fn_889CE718_88811AC0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t6;
    *(unsigned short *)((char *)(ts4_word)(t6) + 10) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(t6) + 10)) + 1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    *(unsigned char *)((char *)(ts4_word)(t2) + 75) = (unsigned char)2;
    return t6;
}

/* Swing_DLL.xex 0x8881C200: call_seq ts4_call_seq_u32_off14_8881C130, lua2_luaC_sweep_8881BF80, lua2_checkSizes_8881AB98, lua2_luaC_callGCTM_8881B950 */
ts4_word ts4_call_seq_fn_8881C130_8881C200(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_call_seq_u32_off14_8881C130();
    lua2_luaC_sweep_8881BF80((ts4_word)a0, (ts4_word)0);
    lua2_checkSizes_8881AB98((ts4_word)a0, (ts4_word)t1);
    t4 = lua2_luaC_callGCTM_8881B950((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88834F08: call_seq lib3_lua_tostring_88822888, fn_88562EF8 */
ts4_word ts4_call_seq_fn_88822888_88834F08(ts4_word a0)
{
    ts4_word t1;

    t1 = lib3_lua_tostring_88822888((ts4_word)a0, (ts4_word)1);
    fn_88562EF8((ts4_word)t1);
    return -1;
}

/* Swing_DLL.xex 0x888358D0: call_seq ts4_if_call_seq_u32_off58_88835468 */
ts4_word ts4_call_seq_fn_88835468_888358D0(ts4_word a0)
{
    ts4_if_call_seq_u32_off58_88835468((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88837CB0: call_seq u32@0x18, u32@0x0, fn_888374C8, u32@0x18, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_off18_88837CB0(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    fn_888374C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 24))) + 0)), (ts4_word)(a1 + 8));
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((int)(t6 - (*(ts4_word *)((char *)(ts4_word)(t5) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x88844310: if_get ts4_if_call_seq_u32_lbl_88D459E4_8883F238, u32@0x0, u32@0x28, vcall, fn_88925640, ts4_if_call_seq_u32_lbl_88D459E4_8883F238 */
ts4_word ts4_if_get_fn_8883F238_88844310(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)a1, (ts4_word)3072, (ts4_word)0);
    t5 = loc50[0];
    p13 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = fn_88925640((ts4_word)a0, (ts4_word)t5);
        ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t6);
        t8 = loc50[0];
        t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 88))))((ts4_word)t9, (ts4_word)(ts4_word)&loc50[0]);
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x88855F10: call_seq fn_88617D88, lbl_880E16FC, u32@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88855F10(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16FC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 80));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    ts4_call_seq_u32_off1c_88855E98((ts4_word)a0);
    *(ts4_word *)lbl_88D459E0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88857A20: call_seq ts4_call_seq_u32_off1c_88855E98, ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_fn_88855E98_88857A20(ts4_word a0)
{
    ts4_word t3;

    ts4_call_seq_u32_off1c_88855E98((ts4_word)a0);
    ts4_object_finalize((ts4_word)(a0 + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t3 = fn_881B9148((ts4_word)(a0 + 16));
    return t3;
}
