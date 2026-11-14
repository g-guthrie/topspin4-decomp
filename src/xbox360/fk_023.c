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
extern char ts4_call_seq_fn_88822888_88834F08[];
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
ts4_word ts4_call_seq_fn_8881C130_8881C200();
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
ts4_word fn_888354D8();
ts4_word fn_88835D88();
ts4_word fn_888364F8();
ts4_word fn_888368B0();
ts4_word fn_88836968();
ts4_word fn_888374C8();
ts4_word fn_88837880();
ts4_word ts4_call_seq_u32_off18_88837CB0();
ts4_word ts4_member_field_addr_8883B318();
ts4_word ts4_member_field_addr_8883B388();
ts4_word ts4_member_field_addr_8883B578();
ts4_word fn_8883B5E8();
ts4_word fn_8883B748();
ts4_word fn_8883CC80();
ts4_word fn_8883EF20();
ts4_word fn_8883F0C0();
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

/* Swing_DLL.xex 0x888032F8: call_seq fn_88617D88, lbl_880E3838, u8@0x8, u32@0x0 */
ts4_word ts4_call_seq_fn_88617D88_888032F8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3838;
    return a0;
}

/* Swing_DLL.xex 0x888033D8: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_888033D8(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x888033E0: call_seq ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_ts4_object_finalize_888033E0(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x88803C50: call_seq u32@0x8, u32@0xc, u32@0x0, lib3_lua_type_88822738 */
ts4_word ts4_call_seq_u32_off8_88803C50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
    lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
    return 0;
}

/* Swing_DLL.xex 0x88803FE8: addr lbl_880E3828, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880E3828_88803FE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3828;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88804B88: call_seq fn_88804B18, lbl_880E37D8, u32@0x3c, u32@0x0, u8@0x40, u8@0x41 */
ts4_word ts4_call_seq_fn_88804B18_88804B88(ts4_word a0)
{
    fn_88804B18((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E37D8;
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 65) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x88804BE8: call_seq fn_88804B18, lbl_880E3798, u32@0x3c, u32@0x0, u8@0x40, u8@0x41 */
ts4_word ts4_call_seq_fn_88804B18_88804BE8(ts4_word a0)
{
    fn_88804B18((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3798;
    *(unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 65) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888050D0: call_seq lbl_880E3818, u32@0x0, fn_881B19A0, fn_881B19A0, fn_881B19A0, fn_881B19A0 */
ts4_word ts4_call_seq_lbl_880E3818_888050D0(ts4_word a0)
{
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3818;
    fn_881B19A0((ts4_word)(a0 + 104));
    fn_881B19A0((ts4_word)(a0 + 72));
    fn_881B19A0((ts4_word)(a0 + 40));
    fn_881B19A0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3738;
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88805288: call_seq u32@0x3c, u32@0x0, fn_881B18E0, lbl_880E17D0, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_88805288(ts4_word a0)
{
    ts4_word loc60[5];
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    loc60[2] = (ts4_word)0;
    loc60[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)t1, (ts4_word)(t2 + 72));
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E17D0, (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t5;
}

/* Swing_DLL.xex 0x88805970: if_call_seq u32@0x0, u32@0x6c, u32@0x0, lib3_lua_type_88822738, lbl_880E3044, fn_881B3640 */
ts4_word ts4_if_call_seq_u32_off0_88805970(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t4;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc50[1] = (ts4_word)1;
        fn_881B3640((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E3044, (ts4_word)0);
        loc50[0] = (ts4_word)t2;
        loc50[1] = (ts4_word)1;
        fn_881B3640((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E302C, (ts4_word)0);
        loc50[0] = (ts4_word)t2;
        loc50[1] = (ts4_word)1;
        fn_881B3640((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E3038, (ts4_word)((983040) | 65535));
    }
    return 0;
}

/* Swing_DLL.xex 0x8880BF70: get u32@0x3c, u32@0x0, u32@0x0, lib3_lua_dostring_8882ED00 */
ts4_word ts4_get_u32_off3c_8880BF70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return lib3_lua_dostring_8882ED00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
}

/* Swing_DLL.xex 0x8880BF80: get u32@0x0, u32@0x3c, ts4_if_get_u32_lbl_88D45B1C_881B3778 */
ts4_word ts4_get_u32_off0_8880BF80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ts4_if_get_u32_lbl_88D45B1C_881B3778((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x8880BF90: get u32@0x8, u32@0x0, u32@0x0, lib3_lua_dostring_8882ED00 */
ts4_word ts4_get_u32_off8_8880BF90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return lib3_lua_dostring_8882ED00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
}

/* Swing_DLL.xex 0x8880C018: set u32@0xc, u32@0x10, ts4_if_get_u32_off4_8882DB60, u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_offc_8880C018(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)ts4_if_get_u32_off4_8882DB60;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88810038: get u8@lbl_88C6A108 */
ts4_word ts4_get_u8_lbl_88C6A108_88810038(void)
{
    return ((signed char)(*(unsigned char *)lbl_88C6A108));
}

/* Swing_DLL.xex 0x88810380: call_seq lua2_LoadBlock_888102D8 */
ts4_word ts4_call_seq_fn_888102D8_88810380(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    lua2_LoadBlock_888102D8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4);
    t2 = loc50[0];
    return t2;
}

/* Swing_DLL.xex 0x88811028: call_seq lua2_LoadHeader_88810408, lua2_LoadFunction_88810F00 */
ts4_word ts4_call_seq_fn_88810408_88811028(ts4_word a0)
{
    ts4_word t2;

    lua2_LoadHeader_88810408((ts4_word)a0);
    t2 = lua2_LoadFunction_88810F00((ts4_word)a0, (ts4_word)0);
    return t2;
}

/* Swing_DLL.xex 0x888110D8: if_get u32@0x0, u32@0x14, u32@0x8, u32@0xc, u32@0x8, u32@0x10 */
ts4_word ts4_if_get_u32_off0_888110D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 5) {
        if ((int)t1 != 7) {
            return (*(ts4_word *)((char *)(ts4_word)(((t1 + 13) << 4)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))));
        }
        return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + 12));
    }
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + 16));
}

/* Swing_DLL.xex 0x88811AC0: if_call_seq fn_889CE718, u16@0xa, u32@0x14, u32@0x4, u32@0x14, u32@0x14 */
ts4_word ts4_if_call_seq_fn_889CE718_88811AC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;

    t1 = fn_889CE718((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)40);
    *(unsigned short *)((char *)(ts4_word)(t1) + 10) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 20);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 20));
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 20) = (ts4_word)t1;
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t6 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)t1;
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 9) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(t1) + 8) = (unsigned char)5;
    t8 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 288);
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)t8;
    if ((ts4_word)t8 != 0) {
        *(unsigned short *)((char *)(ts4_word)(t8) + 10) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(t8) + 10)) + 1);
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(t1) + 12) = (unsigned char)255;
    *(unsigned char *)((char *)(ts4_word)(t1) + 13) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
    lua2_setarrayvector_88811768((ts4_word)a0, (ts4_word)t1, (ts4_word)a1);
    lua2_setnodevector_88811688((ts4_word)a0, (ts4_word)t1, (ts4_word)a2);
    return t1;
}

/* Swing_DLL.xex 0x88812730: call_seq fn_88811B98, fn_888182A8, lua2_resize_88812378 */
ts4_word ts4_call_seq_fn_88811B98_88812730(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    fn_88811B98((ts4_word)a1, (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    t3 = fn_888182A8((ts4_word)t2);
    t4 = loc54[0];
    t5 = lua2_resize_88812378((ts4_word)a0, (ts4_word)a1, (ts4_word)t4, (ts4_word)(t3 + 1));
    return t5;
}

/* Swing_DLL.xex 0x88813400: get u32@0x14, u32@0x68, u32@0x8, u32@0xc, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off14_88813400(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t4))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16)), (ts4_word)t5, (ts4_word)(t3 << 2), (ts4_word)0, (ts4_word)0, (ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) - (t3 << 2));
    return t7;
}

/* Swing_DLL.xex 0x88813468: set u32@0x20, u32@0x24, u32@0x60, u32@0x40, u8@0x36, u8@0x34 */
void ts4_set_u32_off20_88813468(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 48) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 50) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888134D0: get u32@0x14, fn_88834E10, u32@0x184 */
void ts4_get_u32_off14_888134D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 388) = (ts4_word)(ts4_word)fn_88834E10;
    return;
}

/* Swing_DLL.xex 0x88813510: if_call_seq fn_885651F8, fn_88565320 */
ts4_word ts4_if_call_seq_fn_885651F8_88813510(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a0;
    (void)a2;
    if ((ts4_word)a3 == 0) {
        fn_885651F8((ts4_word)a1);
        return 0;
    }
    t2 = fn_88565320((ts4_word)a1, (ts4_word)a3);
    return t2;
}

/* Swing_DLL.xex 0x88813558: fn  */
ts4_word ts4_fn_88813558(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88813840: if_get u32@0x14, u32@0x68, u32@0xc, u32@0x10, vcall, u32@0x60 */
ts4_word ts4_if_get_u32_off14_88813840(ts4_word a0)
{
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t3))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 16)), (ts4_word)0, (ts4_word)0, (ts4_word)112, (ts4_word)0, (ts4_word)t2);
    p14 = (ts4_word)t5;
    if ((ts4_word)t5 == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        if ((ts4_word)t6 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t6) + 1360) = (ts4_word)4;
            fn_88569D30((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96)) + 16), (ts4_word)1);
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 48))))((ts4_word)a0);
        t13 = ts4_tailcall_fn_88564208_885643D0((ts4_word)1);
        p14 = (ts4_word)t13;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) + 112);
    return p14;
}

/* Swing_DLL.xex 0x888138F0: get u32@0x20, lua2_luaF_close_8881C3C0, lua2_freestack_88813598, u32@0x68, u32@0x14, u32@0xc */
ts4_word ts4_get_u32_off20_888138F0(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    lua2_luaF_close_8881C3C0((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32)));
    lua2_freestack_88813598((ts4_word)a0, (ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 12);
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t6))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 16)), (ts4_word)a1, (ts4_word)112, (ts4_word)0, (ts4_word)0, (ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(t5) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 44)) + -112);
    return t8;
}

/* Swing_DLL.xex 0x888143B0: set u32@0x14, u32@0x4, u32@0x8, u32@0x34, u32@0xc, u32@0x10 */
void ts4_set_u32_off14_888143B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52));
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88814528: set u32@0x0, u32@0x4, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_88814528(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x88814B80: call_seq lua2_luaX_lex_8881A6E8, u32@0x20 */
ts4_word ts4_call_seq_fn_8881A6E8_88814B80(ts4_word a0)
{
    ts4_word t1;

    t1 = lua2_luaX_lex_8881A6E8((ts4_word)a0, (ts4_word)(a0 + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88815118: call_seq lua2_next_88814BB8 */
ts4_word ts4_call_seq_fn_88814BB8_88815118(ts4_word a0)
{
    lua2_next_88814BB8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x888157D8: if_call_seq u32@0x10, lbl_880E2B10, lua2_luaX_syntaxerror_888195F0, fn_888154C8, u32@0x4, lua2_next_88814BB8 */
ts4_word ts4_if_call_seq_u32_off10_888157D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 != 40) {
        p3 = (ts4_word)a0;
        if ((int)t1 != 279) {
            t2 = lua2_luaX_syntaxerror_888195F0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2B10);
            p3 = (ts4_word)t2;
        }
        t4 = fn_888154C8((ts4_word)p3, (ts4_word)a1);
        return t4;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    lua2_next_88814BB8((ts4_word)a0);
    lua2_subexpr_88816C30((ts4_word)a0, (ts4_word)a1, (ts4_word)-1);
    lua2_check_match_88815580((ts4_word)a0, (ts4_word)41, (ts4_word)40, (ts4_word)t5);
    t10 = lua2_luaK_dischargevars_88820C30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)a1);
    return t10;
}

/* Swing_DLL.xex 0x888170A8: call_seq lua2_next_88814BB8, fn_88817030, lua2_check_88815628, lua2_block_888153C0 */
ts4_word ts4_call_seq_fn_88814BB8_888170A8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    lua2_next_88814BB8((ts4_word)a0);
    fn_88817030((ts4_word)a0, (ts4_word)a1);
    lua2_check_88815628((ts4_word)a0, (ts4_word)275);
    t4 = lua2_block_888153C0((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88817A00: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off0_88817A00(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (ts4_word)t1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t3 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return;
}

/* Swing_DLL.xex 0x88819590: get u32@0x4, lua2_luaX_errorline_88819520 */
ts4_word ts4_get_u32_off4_88819590(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return lua2_luaX_errorline_88819520((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8881C130: call_seq u32@0x14, lua2_markroot_8881BE58, lua2_propagatemarks_8881C030, lua2_cleartablevalues_8881B108, lua2_cleartablevalues_8881B108, lua2_luaC_separateudata_8881B770 */
ts4_word ts4_call_seq_u32_off14_8881C130(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t13;
    ts4_word t15;
    ts4_word t17;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    loc50[5] = (ts4_word)a0;
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[4] = (ts4_word)t1;
    loc50[3] = (ts4_word)0;
    lua2_markroot_8881BE58((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    lua2_propagatemarks_8881C030((ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[3];
    lua2_cleartablevalues_8881B108((ts4_word)a0, (ts4_word)t4);
    t6 = loc50[2];
    lua2_cleartablevalues_8881B108((ts4_word)a0, (ts4_word)t6);
    loc50[2] = (ts4_word)0;
    t8 = loc50[3];
    loc50[3] = (ts4_word)0;
    t9 = lua2_luaC_separateudata_8881B770((ts4_word)a0);
    lua2_marktmu_8881B888((ts4_word)(ts4_word)&loc50[0]);
    lua2_propagatemarks_8881C030((ts4_word)(ts4_word)&loc50[0]);
    lua2_cleartablekeys_8881B230((ts4_word)a0, (ts4_word)t8);
    t13 = loc50[1];
    lua2_cleartablekeys_8881B230((ts4_word)a0, (ts4_word)t13);
    t15 = loc50[2];
    lua2_cleartablevalues_8881B108((ts4_word)a0, (ts4_word)t15);
    t17 = loc50[3];
    lua2_cleartablekeys_8881B230((ts4_word)a0, (ts4_word)t17);
    t19 = loc50[3];
    lua2_cleartablevalues_8881B108((ts4_word)a0, (ts4_word)t19);
    return t9;
}

/* Swing_DLL.xex 0x8881EF60: get u32@0x38 */
ts4_word ts4_get_u32_off38_8881EF60(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x8881EF68: get u8@0x34 */
ts4_word ts4_get_u8_off34_8881EF68(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x88820120: if_get u32@0x34, u32@0x24, u32@0x24 */
void ts4_if_get_u32_off34_88820120(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)a1 < (int)t1) {
        return;
    }
    if ((int)a1 >= 250) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + -1);
    return;
}

/* Swing_DLL.xex 0x888201D0: get u32@0x18, u32@0x1c */
ts4_word ts4_get_u32_off18_888201D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
    return t1;
}

/* Swing_DLL.xex 0x88820450: get u32@0x18, u32@0x1c, lua2_luaK_concat_888203F0 */
ts4_word ts4_get_u32_off18_88820450(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    return lua2_luaK_concat_888203F0((ts4_word)a0, (ts4_word)(a0 + 32), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88820778: call_seq u32@0x18, u32@0x20, lua2_luaK_patchlistaux_88820468, u32@0x20 */
ts4_word ts4_call_seq_u32_off18_88820778(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t3 = lua2_luaK_patchlistaux_88820468((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)t1, (ts4_word)255, (ts4_word)t1, (ts4_word)255, (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    return t3;
}

/* Swing_DLL.xex 0x88820DD0: call_seq u32@0x20, u32@0x20, lua2_luaK_code_888208A8, lua2_luaK_concat_888203F0 */
ts4_word ts4_call_seq_u32_off20_88820DD0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    t2 = lua2_luaK_code_888208A8((ts4_word)a0, (ts4_word)((8323072) | 65432));
    loc50[0] = (ts4_word)t2;
    lua2_luaK_concat_888203F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    t4 = loc50[0];
    return t4;
}

/* Swing_DLL.xex 0x88821C80: call_seq lua2_luaK_exp2RK_88821878, u32@0x8, u32@0x0 */
ts4_word ts4_call_seq_fn_88821878_88821C80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = lua2_luaK_exp2RK_88821878((ts4_word)a0, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)8;
    return t1;
}

/* Swing_DLL.xex 0x88821F08: get u32@0x14, u32@0x10, u32@0xc, u32@0x0 */
ts4_word ts4_get_u32_off14_88821F08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    return t3;
}

/* Swing_DLL.xex 0x88821F20: get u32@0x14, u32@0x2c */
ts4_word ts4_get_u32_off14_88821F20(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 44))) >> 10);
}

/* Swing_DLL.xex 0x88821F30: get u32@0x14, u32@0x28 */
ts4_word ts4_get_u32_off14_88821F30(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 40))) >> 10);
}

/* Swing_DLL.xex 0x88821F40: if_addr lbl_880E17A4, lbl_880C9684 */
ts4_word ts4_if_addr_lbl_880E17A4_88821F40(ts4_word a0)
{
    if ((int)a0 == -1) {
        return (ts4_word)lbl_880E17A4;
    }
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_880C9684));
}

/* Swing_DLL.xex 0x88821F68: get u32@0xc, u32@0x10 */
ts4_word ts4_get_u32_offc_88821F68(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 16))) >> 4);
}

/* Swing_DLL.xex 0x88821F80: get u32@0x14, ts4_call_seq_fn_88822888_88834F08, u32@0x30, u32@0x30 */
ts4_word ts4_get_u32_off14_88821F80(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    *(ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)(ts4_word)ts4_call_seq_fn_88822888_88834F08;
    return t2;
}

/* Swing_DLL.xex 0x88822108: if_get u32@0x10, lib3_lua_negindex_88821F98 */
ts4_word ts4_if_get_u32_off10_88822108(ts4_word a0, ts4_word a1)
{
    if ((int)a1 > 0) {
        return (((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + (a1 << 4)) + -16);
    }
    return lib3_lua_negindex_88821F98((ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88822960: get u32@0x4, u32@0x0, lua2_luaD_call_8881E258 */
ts4_word ts4_get_u32_off4_88822960(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return lua2_luaD_call_8881E258((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88822A08: if_call_seq u32@0x14, u32@0x2c, u32@0x28, ts4_call_seq_fn_8881C130_8881C200, fn_888188F8 */
ts4_word ts4_if_call_seq_u32_off14_88822A08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 40);
    if ((ts4_word)t2 >= (ts4_word)t3) {
        ts4_call_seq_fn_8881C130_8881C200((ts4_word)a0);
    }
    t6 = fn_888188F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t6;
}

/* Swing_DLL.xex 0x88824E20: if_call_seq u32@0x0, fn_88565320, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88824E20(ts4_word a0, ts4_word a1)
{
    ts4_word p1;
    ts4_word t3;

    p1 = (ts4_word)a1;
    if ((ts4_word)a1 < 32) {
        p1 = (ts4_word)32;
    }
    t3 = fn_88565320((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)p1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    return t3;
}

/* Swing_DLL.xex 0x88825C78: if_call_seq lib3_capture_to_close_88825A50, u32@0x14, lib3_match_88825EF0, u32@0x14 */
ts4_word ts4_if_call_seq_fn_88825A50_88825C78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t3;

    t1 = lib3_capture_to_close_88825A50((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(((t1 << 3) + a0)) + 20) = (ts4_word)(a1 - (*(ts4_word *)((char *)(ts4_word)(((t1 + 2) << 3)) + a0)));
    t3 = lib3_match_88825EF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    if ((ts4_word)t3 == 0) {
        *(ts4_word *)((char *)(ts4_word)(((t1 << 3) + a0)) + 20) = (ts4_word)-1;
    }
    return t3;
}

/* Swing_DLL.xex 0x88825CD8: call_seq lib3_luaL_addlstring_8882E828 */
ts4_word ts4_call_seq_fn_8882E828_88825CD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    (void)a2;
    lib3_luaL_addlstring_8882E828((ts4_word)a3);
    return 1;
}

/* Swing_DLL.xex 0x8882AF38: tailcall fn_8882AA90 */
ts4_word ts4_tailcall_fn_8882AA90_8882AF38(ts4_word a0)
{
    return fn_8882AA90((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x8882B398: fn  */
ts4_word ts4_fn_8882B398(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8882B450: call_seq fn_88824188, fn_88824438 */
ts4_word ts4_call_seq_fn_88824188_8882B450(ts4_word a0)
{
    fn_88824188((ts4_word)a0);
    fn_88824438((ts4_word)a0, (ts4_word)-2);
    return 2;
}

/* Swing_DLL.xex 0x8882B568: if_call_seq lbl_880E18EC, fn_88823FC0, lib3_lua_getglobal_top_88823BA8, lib3_lua_tostring_88822888, fn_888246A8, lbl_880E2028 */
ts4_word ts4_if_call_seq_lbl_880E18EC_8882B568(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;

    fn_88823FC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E18EC, (ts4_word)8);
    lib3_lua_getglobal_top_88823BA8((ts4_word)a0);
    t3 = lib3_lua_tostring_88822888((ts4_word)a0, (ts4_word)-1);
    fn_888246A8((ts4_word)a0, (ts4_word)-2);
    if ((ts4_word)t3 != 0) {
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)(ts4_word)lbl_880E2028;
    }
    return p5;
}

/* Swing_DLL.xex 0x8882C988: call_seq fn_8882B6A8, lib3_auxwrap_8882BEC0, lib3_lua_pushcclosure_88823E00 */
ts4_word ts4_call_seq_fn_8882B6A8_8882C988(ts4_word a0)
{
    fn_8882B6A8((ts4_word)a0);
    lib3_lua_pushcclosure_88823E00((ts4_word)a0, (ts4_word)(ts4_word)lib3_auxwrap_8882BEC0, (ts4_word)1);
    return 1;
}

/* Swing_DLL.xex 0x8882D9D8: if_call_seq fn_8882D360, lib3_has_fenv_8882B4F8, fn_888246A8 */
ts4_word ts4_if_call_seq_fn_8882D360_8882D9D8(ts4_word a0)
{
    ts4_word t2;

    fn_8882D360((ts4_word)a0);
    t2 = lib3_has_fenv_8882B4F8((ts4_word)a0);
    if ((int)t2 == 0) {
        fn_888246A8((ts4_word)a0, (ts4_word)-2);
    }
    return 1;
}

/* Swing_DLL.xex 0x8882DAF0: set u32@0xc, u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_offc_8882DAF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(a1 + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8882DB88: set u32@0xc, u32@0x8, u32@0x0, u32@0x4 */
void ts4_set_u32_offc_8882DB88(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(a1 + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8882E520: if_call_seq lib3_emptybuffer_8882DE88, lib3_adjuststack_8882DBA8 */
ts4_word ts4_if_call_seq_fn_8882DE88_8882E520(ts4_word a0)
{
    ts4_word t1;

    t1 = lib3_emptybuffer_8882DE88((ts4_word)a0);
    if ((int)t1 != 0) {
        lib3_adjuststack_8882DBA8((ts4_word)a0);
    }
    return (a0 + 16);
}

/* Swing_DLL.xex 0x8882E8A0: if_call_seq lib3_lua_type_88822738, lbl_880E1C98, lib3_luaL_argerror_8882E6B8 */
ts4_word ts4_if_call_seq_fn_88822738_8882E8A0(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = lib3_lua_type_88822738((ts4_word)a0, (ts4_word)a1);
    p3 = (ts4_word)t1;
    if ((int)t1 == -1) {
        t2 = lib3_luaL_argerror_8882E6B8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_880E1C98);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x8882EC88: call_seq lib3_lua_load_buffer_88824CF8 */
ts4_word ts4_call_seq_fn_88824CF8_8882EC88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    t1 = lib3_lua_load_buffer_88824CF8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    return t1;
}

/* Swing_DLL.xex 0x8882ECB8: call_seq lib3_lua_load_buffer_88824CF8, lib3_aux_do_8882E368 */
ts4_word ts4_call_seq_fn_88824CF8_8882ECB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    t1 = lib3_lua_load_buffer_88824CF8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    t2 = lib3_aux_do_8882E368((ts4_word)a0, (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x8882FCA8: if_call_seq fn_8882FA70, u32@0x14, fn_8882FEF8, u32@0x14 */
ts4_word ts4_if_call_seq_fn_8882FA70_8882FCA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_8882FA70((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(((t1 + 2) << 3)) + a0);
    *(ts4_word *)((char *)(ts4_word)(((t1 << 3) + a0)) + 20) = (ts4_word)((int)(a1 - t2) >> 1);
    t3 = fn_8882FEF8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)((int)(a1 - t2) >> 1), (ts4_word)(a1 - t2), (ts4_word)t2, (ts4_word)((t1 + 2) << 3), (ts4_word)(t1 + 2));
    if ((ts4_word)t3 == 0) {
        *(ts4_word *)((char *)(ts4_word)(((t1 << 3) + a0)) + 20) = (ts4_word)-1;
    }
    return t3;
}

/* Swing_DLL.xex 0x888327B8: fn  */
ts4_word ts4_fn_888327B8(void)
{
    return -10003;
}

/* Swing_DLL.xex 0x88832DE0: get u32@0x18, u32@0x0, fn_8880C738 */
ts4_word ts4_get_u32_off18_88832DE0(ts4_word a0, ts4_word a1)
{
    return fn_8880C738((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0)), (ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
}

/* Swing_DLL.xex 0x88832EB0: call_seq u32@0x8, u32@0x10, u32@0x0, u32@0x14, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off8_88832EB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)a1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 20)) + 56));
    return a0;
}

/* Swing_DLL.xex 0x88834860: vcall lib3_lua_touserdata_88822230, vcall */
ts4_word ts4_vcall_fn_88822230_88834860(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = lib3_lua_touserdata_88822230((ts4_word)a0, (ts4_word)-10002);
    t2 = ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88834C48: set u32@0x4, u8@0x8 */
ts4_word ts4_set_u32_off4_88834C48(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return 1;
}

/* Swing_DLL.xex 0x88834DA8: addr lbl_880E1880, u32@0x4, u32@0x0, u8@0x8 */
void ts4_addr_lbl_880E1880_88834DA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1880;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88834DE8: get u32@0x0, u32@0x6c */
void ts4_get_u32_off0_88834DE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x88834F38: call_seq lib3_lua_tostring_88822888, fn_88562EF8 */
ts4_word ts4_call_seq_fn_88822888_88834F38(ts4_word a0)
{
    ts4_word t1;

    t1 = lib3_lua_tostring_88822888((ts4_word)a0, (ts4_word)1);
    fn_88562EF8((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x88834F68: call_seq u32@0x20, u32@0x0, fn_88823C98, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_u32_off20_88834F68(ts4_word a0)
{
    fn_88823C98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x88834FB0: call_seq u32@0x20, ts4_call_seq_u32_off0_881B1C90, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_u32_off20_88834FB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    ts4_call_seq_u32_off0_881B1C90((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x88834FF8: call_seq u32@0x20, fn_881B1A98, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_u32_off20_88834FF8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    fn_881B1A98((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x88835040: call_seq u32@0x20, fn_881B1A98, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_u32_off20_88835040(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    fn_881B1A98((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x88835088: call_seq fn_881B19A0, fn_881B19A0, fn_881B19A0 */
ts4_word ts4_call_seq_fn_881B19A0_88835088(ts4_word a0)
{
    ts4_word t3;

    fn_881B19A0((ts4_word)(a0 + 64));
    fn_881B19A0((ts4_word)(a0 + 32));
    t3 = fn_881B19A0((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x888351F8: call_seq u32@0x0, u32@0x8, u32@0x10, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off0_888351F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)a1, (ts4_word)(t1 + 72));
    return a0;
}

/* Swing_DLL.xex 0x888352B8: get u32@0x0, u32@0x14, u32@0x10, u32@0xc, fn_88835240, vcall */
ts4_word ts4_get_u32_off0_888352B8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 16);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    fn_88835240();
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t4))((ts4_word)t3, (ts4_word)a0, (ts4_word)28, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    return t6;
}

/* Swing_DLL.xex 0x888353A8: call_seq ts4_call_seq_u32_off18_88837CB0, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_fn_88837CB0_888353A8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];

    ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 1);
    return a0;
}

/* Swing_DLL.xex 0x888353E8: call_seq u32@0x8, u32@0x10, u32@0x18, fn_881B18E0, u32@0x18, u32@0x20 */
ts4_word ts4_call_seq_u32_off8_888353E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)(a1 + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(((int)(t5 - (*(ts4_word *)((char *)(ts4_word)(t4) + 16))) >> 4) + 1);
    ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88835468: if_call_seq u32@0x58, fn_888350C8, u8@0x60 */
ts4_word ts4_if_call_seq_u32_off58_88835468(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_888350C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)(a0 + 64), (ts4_word)a0, (ts4_word)(a0 + 32));
    if ((ts4_word)(t2 & 0xff) == 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 96) = (unsigned char)1;
        return 0;
    }
    return 1;
}

/* Swing_DLL.xex 0x88835540: call_seq u32@0x18, u32@0x18, u32@0x4, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_off18_88835540(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t4;
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)(a0 + 32);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 4) = (ts4_word)(a0 + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(t4 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    fn_881B18E0((ts4_word)(a0 + 64), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)(a1 + 8), (ts4_word)t5, (ts4_word)t3, (ts4_word)t2, (ts4_word)(t4 + 4), (ts4_word)(a0 + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 96) = (unsigned char)0;
    fn_888354D8((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88835FC8: call_seq u32@0x14, lua2_lua_open_888140E0, u32@0x0, u8@0x18, u32@0x14, fn_88834E10 */
ts4_word ts4_call_seq_u32_off14_88835FC8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    t1 = lua2_lua_open_888140E0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 20))) + 388) = (ts4_word)(ts4_word)fn_88834E10;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_88835D88((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88836100: get u32@0x10 */
ts4_word ts4_get_u32_off10_88836100(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88836108: if_get u32@0x8, u32@0x10, u32@0x10, u32@0x18, u32@0x10 */
ts4_word ts4_if_get_u32_off8_88836108(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 2) {
        if ((int)t1 != 7) {
            return 0;
        }
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 16);
        if ((ts4_word)(t3 & 0x1) != 0) {
            return (*(ts4_word *)((char *)(ts4_word)(t2) + 24));
        }
        return (t2 + 24);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x888361A8: get u32@0x8 */
ts4_word ts4_get_u32_off8_888361A8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + -1) == 0);
}

/* Swing_DLL.xex 0x888361D8: get u32@0x8 */
ts4_word ts4_get_u32_off8_888361D8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + -6) == 0);
}

/* Swing_DLL.xex 0x888361F0: get u32@0x8 */
ts4_word ts4_get_u32_off8_888361F0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + -9) == 0);
}

/* Swing_DLL.xex 0x88836208: get u32@0x8 */
ts4_word ts4_get_u32_off8_88836208(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + -4) == 0);
}

/* Swing_DLL.xex 0x888362A8: get u32@0x8 */
ts4_word ts4_get_u32_off8_888362A8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + -5) == 0);
}

/* Swing_DLL.xex 0x888362C0: get u32@0x8 */
ts4_word ts4_get_u32_off8_888362C0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) == 0);
}

/* Swing_DLL.xex 0x888362D0: get u32@0x8 */
ts4_word ts4_get_u32_off8_888362D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Swing_DLL.xex 0x88836320: get u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_get_u32_off0_88836320(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    return ((int)(t2 - (*(ts4_word *)((char *)(ts4_word)(t1) + 16))) >> 4);
}

/* Swing_DLL.xex 0x88836468: call_seq u32@0x18, u32@0x0, lua2_luaV_settable_8880D278 */
ts4_word ts4_call_seq_u32_off18_88836468(ts4_word a0, ts4_word a1, ts4_word a2)
{
    lua2_luaV_settable_8880D278((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0)), (ts4_word)(a0 + 8), (ts4_word)(a1 + 8), (ts4_word)a2);
    return a0;
}

/* Swing_DLL.xex 0x888364B0: call_seq u32@0x18, u32@0x0, lua2_luaV_settable_8880D278 */
ts4_word ts4_call_seq_u32_off18_888364B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    lua2_luaV_settable_8880D278((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0)), (ts4_word)(a0 + 8), (ts4_word)a1, (ts4_word)a2);
    return a0;
}

/* Swing_DLL.xex 0x88836558: call_seq u32@0x18, u32@0x0, lua2_luaV_settable_8880D278 */
ts4_word ts4_call_seq_u32_off18_88836558(ts4_word a0, ts4_word a1, ts4_word a2)
{
    lua2_luaV_settable_8880D278((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0)), (ts4_word)(a0 + 8), (ts4_word)(a1 + 8), (ts4_word)(a2 + 8));
    return a0;
}

/* Swing_DLL.xex 0x88836630: call_seq u32@0x18, u32@0x0, lua2_luaV_settable_8880D278 */
ts4_word ts4_call_seq_u32_off18_88836630(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[3];
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    loc50[2] = (ts4_word)(a2 & 0xff);
    loc50[0] = (ts4_word)1;
    lua2_luaV_settable_8880D278((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)(a0 + 8), (ts4_word)(a1 + 8), (ts4_word)(ts4_word)&loc50[0]);
    return a0;
}

/* Swing_DLL.xex 0x88836688: call_seq u32@0x18, u32@0x0, lua2_luaV_settable_8880D278 */
ts4_word ts4_call_seq_u32_off18_88836688(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    lua2_luaV_settable_8880D278((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)(a0 + 8), (ts4_word)(a1 + 8), (ts4_word)(ts4_word)&loc50[0]);
    return a0;
}

/* Swing_DLL.xex 0x888366E0: call_seq fn_888364F8 */
ts4_word ts4_call_seq_fn_888364F8_888366E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_888364F8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x88836BA8: tailcall fn_88836968 */
ts4_word ts4_tailcall_fn_88836968_88836BA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88836968((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88837430: call_seq fn_888368B0 */
ts4_word ts4_call_seq_fn_888368B0_88837430(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_888368B0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x88837578: call_seq fn_881B19A0, u32@0x18 */
ts4_word ts4_call_seq_fn_881B19A0_88837578(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_881B19A0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x888375B8: call_seq fn_881B19A0, u32@0x18, fn_881B18E0 */
ts4_word ts4_call_seq_fn_881B19A0_888375B8(ts4_word a0, ts4_word a1)
{
    fn_881B19A0((ts4_word)a0);
    fn_881B18E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)(a1 + 8));
    return a0;
}

/* Swing_DLL.xex 0x88837608: if_call_seq u32@0x8, u32@0x10, u32@0x0, u32@0x4, u32@0x0, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off8_88837608(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 > 0) {
        p7 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t3) + 16)) + (t2 << 4)) + -16);
    } else {
        t5 = lib3_lua_negindex_88821F98((ts4_word)t3, (ts4_word)t2);
        p7 = (ts4_word)t5;
    }
    fn_881B18E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)p7);
    return a0;
}

/* Swing_DLL.xex 0x88837688: call_seq u32@0x8, u32@0x10, u32@0x18, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off8_88837688(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)(a1 + 8));
    return a0;
}

/* Swing_DLL.xex 0x888376D0: call_seq u32@0x8, u32@0x10, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off8_888376D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return a0;
}

/* Swing_DLL.xex 0x88837710: if_call_seq u32@0x8, u32@0x10, u32@0x0, u32@0x10, lib3_lua_negindex_88821F98, fn_881B18E0 */
ts4_word ts4_if_call_seq_u32_off8_88837710(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)a2 > 0) {
        p5 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t1) + 16)) + (a2 << 4)) + -16);
    } else {
        t3 = lib3_lua_negindex_88821F98((ts4_word)t1, (ts4_word)a2);
        p5 = (ts4_word)t3;
    }
    fn_881B18E0((ts4_word)a0, (ts4_word)a1, (ts4_word)p5);
    return a0;
}

/* Swing_DLL.xex 0x88837790: call_seq fn_888368B0 */
ts4_word ts4_call_seq_fn_888368B0_88837790(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    ts4_word t1;

    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_888368B0((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x888377C0: call_seq u32@0x10, ts4_if_call_seq_u32_off0_88812188, u32@0x18, u32@0x8, u32@0x10, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off10_888377C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_if_call_seq_u32_off0_88812188((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)(a2 + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)t3, (ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88837820: call_seq u32@0x10, fn_88811930, u32@0x18, u32@0x8, u32@0x10, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off10_88837820(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88811930((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)a2);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    fn_881B18E0((ts4_word)a0, (ts4_word)t3, (ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x88837A38: call_seq fn_88837880 */
ts4_word ts4_call_seq_fn_88837880_88837A38(ts4_word a0)
{
    fn_88837880();
    return a0;
}

/* Swing_DLL.xex 0x88837D18: call_seq fn_88837880 */
ts4_word ts4_call_seq_fn_88837880_88837D18(ts4_word a0)
{
    fn_88837880();
    return a0;
}

/* Swing_DLL.xex 0x88837F48: call_seq ts4_call_seq_u32_off18_88837CB0, u32@0x18, u32@0x0, u32@0xc, u32@0x10, fn_888345F8 */
ts4_word ts4_call_seq_fn_88837CB0_88837F48(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t6 = fn_888345F8((ts4_word)t3, (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 16))) >> 4));
    fn_888246A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0)), (ts4_word)-2);
    return t6;
}

/* Swing_DLL.xex 0x88838378: get u32@lbl_88D459E8, u32@0x1c, u32@0xc, vcall */
ts4_word ts4_get_u32_lbl_88D459E8_88838378(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D459E8;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 28))) + 12))))((ts4_word)(t1 + 28));
    return 0;
}

/* Swing_DLL.xex 0x888383C8: get u32@0x1c, u32@0x8 */
ts4_word ts4_get_u32_off1c_888383C8(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28), (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x888383E0: set u32@0x24, u32@0x28, u32@0x34, u32@0x38, u32@0x3c, u32@0x40 */
void ts4_set_u32_off24_888383E0(ts4_word a0)
{
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
    return;
}

/* Swing_DLL.xex 0x88838480: set u32@0x8 */
void ts4_set_u32_off8_88838480(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838498: set u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off8_88838498(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888384D0: set u32@0x1c */
void ts4_set_u32_off1c_888384D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888384E0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_888384E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888384F0: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_888384F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838648: addr lbl_880E174C, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880E174C_88838648(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E174C;
    return;
}

/* Swing_DLL.xex 0x88838670: addr lbl_880E1674, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_880E1674_88838670(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1674;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838690: get u32@0x24, u8@0x0 */
void ts4_get_u32_off24_88838690(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 0) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x888386A0: get u32@0x60, u8@0x18 */
void ts4_get_u32_off60_888386A0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 24) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x888386B0: get u32@0x24, u8@0x0 */
ts4_word ts4_get_u32_off24_888386B0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 0));
}

/* Swing_DLL.xex 0x88838710: addr lbl_880E1674, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
void ts4_addr_lbl_880E1674_88838710(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1674;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838750: addr lbl_880E1674, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880E1674_88838750(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1674;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888387C0: addr lbl_880E1674, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880E1674_888387C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1674;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88838930: set u32@0x1c, u32@0x20, u32@0x24 */
void ts4_set_u32_off1c_88838930(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8883B128: get u32@0x64, u8@0x47 */
ts4_word ts4_get_u32_off64_8883B128(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 100))) + 71));
}

/* Swing_DLL.xex 0x8883B308: get u32@0x1c, u32@0x34, u32@0x0 */
void ts4_get_u32_off1c_8883B308(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 28))) + 52));
    return;
}

/* Swing_DLL.xex 0x8883C538: call_seq ts4_find_service, ts4_build_name_from_two_literals_8883AEE0, u32@0x0, fn_88611620 */
ts4_word ts4_call_seq_ts4_find_service_8883C538(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = ts4_find_service((ts4_word)((3803054080) | 35129));
    t2 = ts4_build_name_from_two_literals_8883AEE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88611620((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
    return t4;
}

/* Swing_DLL.xex 0x8883CA10: get u32@0x24, u32@0xc */
void ts4_get_u32_off24_8883CA10(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 12) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8883CA20: if_get u32@0x44, u32@0x1c, u32@0x34, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off44_8883CA20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68))) + 28))) + 52);
    if ((ts4_word)t3 != (ts4_word)((3751936000) | 45041)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((490209280) | 27437);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3015835648) | 8748);
    return;
}

/* Swing_DLL.xex 0x8883CAC0: get u32@0x24, u32@0xd28 */
void ts4_get_u32_off24_8883CAC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 3368) = (ts4_word)((521797632) | 25178);
    return;
}

/* Swing_DLL.xex 0x8883CD78: if_get u32@0x4, u32@0xc, fn_889254C8 */
ts4_word ts4_if_get_u32_off4_8883CD78(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t2 == 0) {
        return t1;
    }
    return fn_889254C8((ts4_word)t1, (ts4_word)1);
}

/* Swing_DLL.xex 0x8883CE70: call_seq lbl_880E16A4, u32@0x4, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_lbl_880E16A4_8883CE70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16A4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    fn_881AD8E0((ts4_word)(a0 + 28));
    return a0;
}

/* Swing_DLL.xex 0x8883D9C0: tailcall fn_881AD968 */
ts4_word ts4_tailcall_fn_881AD968_8883D9C0(ts4_word a0)
{
    return fn_881AD968((ts4_word)(a0 + 92));
}

/* Swing_DLL.xex 0x8883DB68: call_seq ts4_member_field_addr_8883B318, u32@0x60, u32@0x0 */
ts4_word ts4_call_seq_fn_8883B318_8883DB68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_member_field_addr_8883B318((ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 96));
    return a0;
}

/* Swing_DLL.xex 0x8883DF90: call_seq ts4_member_field_addr_8883B578, u32@0x4 */
ts4_word ts4_call_seq_fn_8883B578_8883DF90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_member_field_addr_8883B578((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a2;
    return t1;
}

/* Swing_DLL.xex 0x8883DFC0: call_seq ts4_member_field_addr_8883B578, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_fn_8883B578_8883DFC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_member_field_addr_8883B578((ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    return a0;
}

/* Swing_DLL.xex 0x8883E000: call_seq ts4_member_field_addr_8883B578, u32@0x0 */
ts4_word ts4_call_seq_fn_8883B578_8883E000(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_member_field_addr_8883B578((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a2;
    return t1;
}

/* Swing_DLL.xex 0x8883E270: call_seq fn_8883B5E8 */
ts4_word ts4_call_seq_fn_8883B5E8_8883E270(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;

    loc50[0] = (ts4_word)((2800287744) | 3287);
    t1 = fn_8883B5E8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    return t1;
}

/* Swing_DLL.xex 0x8883E2A8: call_seq fn_8883B748 */
ts4_word ts4_call_seq_fn_8883B748_8883E2A8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;

    loc50[0] = (ts4_word)((2800287744) | 3287);
    t1 = fn_8883B748((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t1;
}

/* Swing_DLL.xex 0x8883E598: get u32@lbl_88D459E8, u32@0x24, u32@0xd28 */
ts4_word ts4_get_u32_lbl_88D459E8_8883E598(void)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 36))) + 3368) = (ts4_word)((521797632) | 25178);
    return 0;
}

/* Swing_DLL.xex 0x8883EDC0: call_seq fn_8883CC80, u32@0xa8 */
ts4_word ts4_call_seq_fn_8883CC80_8883EDC0(void)
{
    ts4_word t1;

    t1 = fn_8883CC80();
    return (*(ts4_word *)((char *)(ts4_word)(t1) + 168));
}

/* Swing_DLL.xex 0x8883F238: if_call_seq u32@lbl_88D459E4, ts4_if_call_seq_u32_lbl_88D45B38_881AE608, fn_88617788, u32@lbl_88D459E4, u8@0x2df0, u8@0x20 */
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D459E4;
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = ts4_if_call_seq_u32_lbl_88D45B38_881AE608((ts4_word)t1);
        fn_88617788((ts4_word)t2, (ts4_word)((3414360064) | 39745));
        *(ts4_word *)lbl_88D459E4 = (ts4_word)t2;
        *(unsigned char *)((char *)(ts4_word)(t2) + 11760) = (unsigned char)1;
        *(unsigned char *)((char *)(ts4_word)(t2) + 32) = (unsigned char)1;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Swing_DLL.xex 0x8883FD38: call_seq fn_8883F508, fn_8883F508 */
ts4_word ts4_call_seq_fn_8883F508_8883FD38(ts4_word a0)
{
    ts4_word t2;

    fn_8883F508((ts4_word)a0, (ts4_word)((322109440) | 21128), (ts4_word)1);
    t2 = fn_8883F508((ts4_word)a0, (ts4_word)((302514176) | 55079), (ts4_word)1);
    return t2;
}

/* Swing_DLL.xex 0x88842618: if_call_seq u32@0x4c, u32@lbl_88D459E0, ts4_member_field_addr_8883B578, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4c_88842618(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = ts4_member_field_addr_8883B578((ts4_word)(*(ts4_word *)lbl_88D459E0), (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t1;
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88842658: call_seq u32@lbl_88D459E0, ts4_member_field_addr_8883B578, u32@0x0, u32@0x4c */
ts4_word ts4_call_seq_u32_lbl_88D459E0_88842658(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = ts4_member_field_addr_8883B578((ts4_word)(*(ts4_word *)lbl_88D459E0), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0));
    return t2;
}

/* Swing_DLL.xex 0x88842FD0: call_seq lbl_880E1614, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_888416A8, lbl_880E1628, fn_88608590 */
ts4_word ts4_call_seq_lbl_880E1614_88842FD0(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t12;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E1614);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_888416A8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E1628);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_88842C30((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E1638);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_88841FE0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880E164C);
    loc50[0] = (ts4_word)t10;
    t12 = ts4_keyed_item_list_add_unique_8883EAF8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return t12;
}

/* Swing_DLL.xex 0x88843078: call_seq u32@0x24, u32@0x8, fn_8883F0C0, fn_8883EF20 */
ts4_word ts4_call_seq_u32_off24_88843078(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 8) = (ts4_word)a1;
    fn_8883F0C0();
    t3 = fn_8883EF20((ts4_word)a0, (ts4_word)((3600154624) | 52457));
    return t3;
}

/* Swing_DLL.xex 0x88843700: get u32@0x34, fn_8883F508 */
ts4_word ts4_get_u32_off34_88843700(ts4_word a0, ts4_word a1)
{
    return fn_8883F508((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x88844710: call_seq fn_88840B50, fn_88840F30 */
ts4_word ts4_call_seq_fn_88840B50_88844710(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[3];
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88840B50((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t2 = loc50[1];
    t3 = fn_88840F30((ts4_word)(a0 + 12), (ts4_word)((731316224) | 32497), (ts4_word)t2);
    return t3;
}

/* Swing_DLL.xex 0x888456D8: call_seq u32@lbl_88D459E8, fn_88843768 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_888456D8(void)
{
    fn_88843768((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88846970: get u32@0x24, u32@0x34, u32@0xd1c, fn_888443A8 */
ts4_word ts4_get_u32_off24_88846970(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return fn_888443A8((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 3356)));
}

/* Swing_DLL.xex 0x88847520: if_call_seq lbl_880E16FC, u32@0x0, fn_881AD9C8, fn_881AD968, u32@0x68, u32@lbl_88D459E0 */
ts4_word ts4_if_call_seq_lbl_880E16FC_88847520(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t13;
    ts4_word t16;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16FC;
    fn_881AD9C8((ts4_word)(a0 + 104));
    fn_881AD968((ts4_word)(a0 + 92));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    *(ts4_word *)lbl_88D459E0 = (ts4_word)0;
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 92)) + 0);
    if ((ts4_word)t6 != 0) {
        ts4_destroy_owned_object((ts4_word)t6);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)));
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    t16 = fn_88617D28((ts4_word)a0);
    return t16;
}

/* Swing_DLL.xex 0x888475C8: call_seq u32@lbl_88D459E8, u32@0x24, u32@0x34, u32@0xd1c, fn_888443A8 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_888475C8(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88D459E8;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 52);
    fn_888443A8((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 3356)));
    return 0;
}

/* Swing_DLL.xex 0x88847600: call_seq u32@lbl_88D459E8, fn_88846890 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88847600(void)
{
    fn_88846890((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88847630: call_seq u32@lbl_88D459E8, fn_888468F0 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88847630(void)
{
    fn_888468F0((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88848938: call_seq u32@lbl_88D459E8, fn_88847D88 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88848938(void)
{
    fn_88847D88((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88848968: call_seq u32@lbl_88D459E8, fn_88847B38 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88848968(void)
{
    fn_88847B38((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8884C208: call_seq u32@lbl_88D459E8, fn_8884A320 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884C208(void)
{
    fn_8884A320((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8884C238: call_seq u32@lbl_88D459E8, fn_88848E80 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884C238(void)
{
    fn_88848E80((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8884C518: if_call_seq ts4_hash_find_null_88848DF0, ts4_hash_find_null_88848DF0, u32@0xc */
ts4_word ts4_if_call_seq_fn_88848DF0_8884C518(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_hash_find_null_88848DF0();
    if ((ts4_word)t1 != 0) {
        t2 = ts4_hash_find_null_88848DF0((ts4_word)t1);
        return (*(ts4_word *)((char *)(ts4_word)(t2) + 12));
    }
    return 0;
}

/* Swing_DLL.xex 0x8884C560: if_call_seq ts4_hash_find_null_88848DF0, u32@0x20 */
ts4_word ts4_if_call_seq_fn_88848DF0_8884C560(void)
{
    ts4_word t1;

    t1 = ts4_hash_find_null_88848DF0();
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 32));
    }
    return 0;
}

/* Swing_DLL.xex 0x8884C5A0: if_call_seq ts4_hash_find_null_88848DF0, u32@0x1c */
ts4_word ts4_if_call_seq_fn_88848DF0_8884C5A0(void)
{
    ts4_word t1;

    t1 = ts4_hash_find_null_88848DF0();
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 28));
    }
    return 0;
}

/* Swing_DLL.xex 0x8884CAF0: get u32@0x24, fn_8884A8F8 */
ts4_word ts4_get_u32_off24_8884CAF0(ts4_word a0, ts4_word a1)
{
    return fn_8884A8F8((ts4_word)a0, (ts4_word)a1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + 440));
}

/* Swing_DLL.xex 0x8884F270: call_seq u32@lbl_88D459E8, fn_8884C7A8 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884F270(void)
{
    fn_8884C7A8((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8884F2A0: call_seq u32@lbl_88D459E8, fn_8884C5E0 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_8884F2A0(void)
{
    fn_8884C5E0((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x8884F630: get u32@0x34, fn_8884CF80 */
ts4_word ts4_get_u32_off34_8884F630(ts4_word a0)
{
    return fn_8884CF80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)));
}

/* Swing_DLL.xex 0x888505D8: if_get u32@0x30, u32@0x0, u32@0x0, vcall, fn_8884FEA8, u32@0x48 */
ts4_word ts4_if_get_u32_off30_888505D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    fn_8884FEA8((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t7 = fn_881B9148((ts4_word)(a0 + 16));
    return t7;
}

/* Swing_DLL.xex 0x88850648: call_seq fn_88617D88, lbl_880E16D4, u32@0x0, fn_8884CEA8, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_88850648(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16D4;
    fn_8884CEA8((ts4_word)(a0 + 28));
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
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)lbl_88D459E8 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88853710: call_seq u32@lbl_88D459E8, fn_88850028 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88853710(void)
{
    fn_88850028((ts4_word)(*(ts4_word *)lbl_88D459E8), (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88853BC8: call_seq u32@lbl_88D459E8, fn_8884F638 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88853BC8(void)
{
    fn_8884F638((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88853BF8: call_seq u32@lbl_88D459E8, fn_888502F8 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88853BF8(void)
{
    fn_888502F8((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88853C28: call_seq u32@lbl_88D459E8, fn_8884FEA8 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88853C28(void)
{
    fn_8884FEA8((ts4_word)(*(ts4_word *)lbl_88D459E8));
    return 0;
}

/* Swing_DLL.xex 0x88853E00: get u32@0x24, u32@0x38, u32@0xd1c, fn_88851628 */
ts4_word ts4_get_u32_off24_88853E00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    return fn_88851628((ts4_word)t2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 3356)) + a1));
}

/* Swing_DLL.xex 0x888540D8: tailcall fn_88850028 */
ts4_word ts4_tailcall_fn_88850028_888540D8(ts4_word a0)
{
    return fn_88850028((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x888547C8: call_seq fn_8884E000, fn_888522D0 */
ts4_word ts4_call_seq_fn_8884E000_888547C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_8884E000((ts4_word)(a0 + 32));
    fn_888522D0((ts4_word)a0, (ts4_word)a1, (ts4_word)t1, (ts4_word)a2, (ts4_word)1);
    return t1;
}

/* Swing_DLL.xex 0x88855088: call_seq u32@lbl_88D459E0, ts4_member_field_addr_8883B388, ts4_assign_formatted_text, fn_88150600, ts4_destroy_owned_object */
ts4_word ts4_call_seq_u32_lbl_88D459E0_88855088(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    t2 = ts4_member_field_addr_8883B388((ts4_word)(*(ts4_word *)lbl_88D459E0), (ts4_word)a1);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2);
    fn_88150600((ts4_word)(a0 + 80), (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc50[0];
    t6 = ts4_destroy_owned_object((ts4_word)t5);
    return t6;
}

/* Swing_DLL.xex 0x88855E98: call_seq u32@0x1c, u32@lbl_88D45B1C, lbl_880C1320, u32@0x38, u32@0x3c, u32@0x48 */
ts4_word ts4_call_seq_u32_off1c_88855E98(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 636));
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 80), (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc50[0];
    t6 = ts4_destroy_owned_object((ts4_word)t5);
    return t6;
}

/* Swing_DLL.xex 0x88855FB8: call_seq u32@lbl_88D459E8, fn_88850028 */
ts4_word ts4_call_seq_u32_lbl_88D459E8_88855FB8(void)
{
    fn_88850028((ts4_word)(*(ts4_word *)lbl_88D459E8), (ts4_word)1);
    return 0;
}

/* Swing_DLL.xex 0x88855FE8: call_seq fn_888514B0 */
ts4_word ts4_call_seq_fn_888514B0_88855FE8(void)
{
    fn_888514B0();
    return 0;
}

/* Swing_DLL.xex 0x88856498: get u32@0x24, u32@0x38, u32@0xd20, fn_88854258 */
ts4_word ts4_get_u32_off24_88856498(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    return fn_88854258((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 3360)));
}

