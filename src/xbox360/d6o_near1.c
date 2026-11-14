/* Swing_DLL.xex 0x8835DC40-0x884EB3C8, executable version 0.0.0.3. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#pragma clang diagnostic ignored "-Wunused-function"
#endif
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef unsigned int ts4_u32;
#ifdef _MSC_VER
unsigned __int64 __mftb(void);
#pragma intrinsic(__mftb)
#else
static inline unsigned long long __mftb(void) { return 0; }
#endif
typedef struct ts4_Rec { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; ts4_u32 tag2; } ts4_Rec;
typedef struct ts4_Rec12 { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; } ts4_Rec12;
typedef struct ts4_TlsBuf { ts4_u32 pad0; void *cur; ts4_u32 pad1; void *end; } ts4_TlsBuf;
extern ts4_u32 lbl_88CAD338;
ts4_word KeTlsGetValue();
#define ts4_trace1(T) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec12 *)tb_->cur < (ts4_Rec12 *)tb_->end) { ts4_Rec12 *rc_ = (ts4_Rec12 *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)
#define ts4_trace2(T, U) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec *)tb_->cur < (ts4_Rec *)tb_->end) { ts4_Rec *rc_ = (ts4_Rec *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->tag2 = (ts4_u32)(U); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)

extern char fn_8833DE28[];
extern char fn_88346080[];
extern char ts4_clear_owned_buffer_adj1c_883460E8[];
extern char ts4_set_float_slot_by_index4_adj1c_88346150[];
extern char fn_883471D0[];
extern char fn_88347278[];
extern char fn_88349D08[];
extern char fn_88349D60[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_8802A6B4[];
extern char lbl_8802AA68[];
extern char lbl_8802ACE8[];
extern char lbl_8802B140[];
extern char lbl_8802B4B4[];
extern char lbl_8802B5C8[];
extern char lbl_8802B8B8[];
extern char lbl_8802B924[];
extern char lbl_8802BB80[];
extern char lbl_8802BB9C[];
extern char lbl_8802BE58[];
extern char lbl_8802BEF8[];
extern char lbl_8802CE9C[];
extern char lbl_8802CEA0[];
extern char lbl_8802CEA4[];
extern char lbl_8802CEA8[];
extern char lbl_8802EE60[];
extern char lbl_8802EE94[];
extern char lbl_8802EEB0[];
extern char lbl_8802EEDC[];
extern char lbl_8802EF04[];
extern char lbl_88035378[];
extern char lbl_8803538C[];
extern char lbl_88B3302C[];
extern char lbl_88B34AE0[];
extern char lbl_88B34BA0[];
extern char lbl_88B34C40[];
extern char lbl_88B34F70[];
extern char lbl_88B351A0[];
extern char lbl_88B35200[];
extern char lbl_88B3A48C[];
extern char lbl_88B3B008[];
extern char ts4_adjust_minus_28_thunk_88346138[];
extern char ts4_adjust_minus_28_thunk_883461B0[];
extern char ts4_adjust_minus_28_thunk_88346488[];
extern char ts4_adjust_minus_28_thunk_883464A0[];
extern char ts4_adjust_minus_28_thunk_88347248[];
extern char ts4_adjust_minus_28_thunk_88347260[];
extern char ts4_adjust_minus_28_thunk_883472C0[];
extern char ts4_adjust_minus_28_thunk_88347540[];
extern char ts4_adjust_minus_28_thunk_88347558[];
extern char ts4_adjust_minus_28_thunk_88349D48[];
extern char ts4_adjust_minus_28_thunk_88349DA0[];
extern char ts4_adjust_minus_28_thunk_88349EA8[];
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word fn_883194F0();
ts4_word ts4_read_u8_to_u8_883199C0();
ts4_word fn_88319C40();
ts4_word fn_88326520();
ts4_word ts4_strlen_88329658();
ts4_word fn_88329680();
ts4_word fn_88329820();
ts4_word fn_8832FC40();
ts4_word fn_88338028();
ts4_word ts4_loop_call_seq_u32_off108_8834E408();
ts4_word fn_88356588();
ts4_word fn_8835D5D8();
ts4_word fn_8835D7F0();
ts4_word fn_8836CBE8();
ts4_word fn_8836CCD8();
ts4_word fn_88376C40();
ts4_word fn_883777F0();
ts4_word fn_88378000();
ts4_word fn_8837BA88();
ts4_word fn_8838B248();
ts4_word fn_883A3218();
ts4_word fn_883A3950();
ts4_word fn_883AAD18();
ts4_word ts4_init_descriptor_defaults_883AFBC0();
ts4_word fn_883AFF60();
ts4_word fn_883B03F0();
ts4_word fn_883B0D50();
ts4_word fn_883B1460();
ts4_word fn_883B3A08();
ts4_word fn_883B5418();
ts4_word fn_883B54C0();
ts4_word fn_883B5600();
ts4_word fn_883B5C70();
ts4_word lib2_FLAC__MD5Transform_883B81B8();
ts4_word fn_883C2F08();
ts4_word fn_88562DC0();
ts4_word fn_885651F8();
ts4_word fn_88569190();
ts4_word fn_8857ACB8();
ts4_word ts4_addr_lbl_8802EE60_883B1EC8();
ts4_word ts4_addr_lbl_88C30DA8_88567BC8();
ts4_word ts4_call_seq_fn_883AA340_883AA840();
ts4_word ts4_call_seq_lbl_8802EE60_883B2400();
ts4_word ts4_get_u32_lbl_88B3302C_883163E0();
ts4_word ts4_get_u32_off0_883B3368();
ts4_word ts4_get_u32_off14_883B7088();
ts4_word ts4_get_u32_off4_883B39C0();
ts4_word ts4_get_u32_off8_883B70B0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word ts4_if_call_seq_fn_8831E890_883330F0();
ts4_word ts4_if_call_seq_u32_off0_883BADF0();
ts4_word ts4_if_call_seq_u32_off108_8834E490();
ts4_word ts4_if_call_seq_u32_off880_883632B8();
ts4_word ts4_if_call_seq_u32_off880_88369A38();
ts4_word ts4_if_get_u32_off0_883B39D0();
ts4_word ts4_if_get_u32_off4_883AA2E0();
ts4_word ts4_memset();
ts4_word ts4_tailcall_NetDll_WSAGetLastError_884F0390();
ts4_word ts4_tailcall_NetDll_accept_884F02E0();
ts4_word ts4_tailcall_fn_88315C60_88316068();
extern char ts4_set_float_capped_by_index_adj1c_8834C558[];
extern char ts4_thunk_adj1c_arg1_88363798[];
extern char fn_8836F918[];
extern char fn_8836F980[];
extern char fn_88370328[];
extern char fn_883A3758[];
extern char fn_883A37C8[];
extern char ts4_get_word_31c_883A3828[];
extern char fn_883A3858[];
extern char ts4_get_child_float_adj1c_883A38C0[];
extern char ts4_thunk_adj1c_set_float_883A3910[];
extern char ts4_get_float_off868_adj1c_883A3930[];
extern char fn_883A3B70[];
extern char lbl_88001970[];
extern char lbl_880023C4[];
extern char lbl_88004448[];
extern char lbl_8802A0C4[];
extern char lbl_8802AD3C[];
extern char lbl_8802AE30[];
extern char lbl_8802AEDC[];
extern char lbl_8802B0B4[];
extern char lbl_8802B6C4[];
extern char lbl_8802B72C[];
extern char lbl_8802B7EC[];
extern char lbl_8802B994[];
extern char lbl_8802BDCC[];
extern char lbl_8802BDD8[];
extern char lbl_8802BE24[];
extern char lbl_8802BE30[];
extern char lbl_8802EF28[];
extern char lbl_8802EF54[];
extern char lbl_8802EFC8[];
extern char lbl_8802F7CC[];
extern char lbl_88035F48[];
extern char lbl_88B35488[];
extern char lbl_88B354E8[];
extern char lbl_88B36680[];
extern char lbl_88B36730[];
extern char lbl_88B36840[];
extern char lbl_88B36B98[];
extern char lbl_88B3A4B0[];
extern char lbl_88C8EAA0[];
extern char lbl_88C8EAA4[];
extern char lbl_88C8EAA8[];
extern char ts4_adjust_minus_28_thunk_8834B290[];
extern char ts4_adjust_minus_28_thunk_8834C8B8[];
extern char ts4_adjust_minus_28_thunk_8834C8D0[];
extern char ts4_adjust_minus_28_thunk_8835DD08[];
extern char ts4_adjust_minus_28_thunk_8835DD20[];
extern char ts4_adjust_minus_28_thunk_8835E178[];
extern char ts4_adjust_minus_28_thunk_88360D20[];
extern char ts4_adjust_minus_28_thunk_88363768[];
extern char ts4_adjust_minus_28_thunk_88363780[];
extern char ts4_adjust_minus_28_thunk_88363BE8[];
extern char ts4_adjust_minus_28_thunk_88365188[];
extern char ts4_adjust_minus_28_thunk_88369E48[];
extern char ts4_adjust_minus_28_thunk_88369E60[];
extern char ts4_adjust_minus_28_thunk_8836A2B0[];
extern char ts4_adjust_minus_28_thunk_8836B2D0[];
extern char ts4_adjust_minus_28_thunk_8836F900[];
extern char ts4_adjust_minus_28_thunk_88370310[];
extern char ts4_adjust_minus_28_thunk_88371468[];
extern char ts4_adjust_minus_28_thunk_88371480[];
extern char ts4_adjust_minus_28_thunk_88371498[];
extern char ts4_adjust_minus_28_thunk_883714B0[];
extern char ts4_adjust_minus_28_thunk_88373870[];
ts4_word fn_8831CBA8();
ts4_word fn_8831CD30();
ts4_word fn_88325370();
ts4_word fn_88327480();
ts4_word fn_883318D8();
ts4_word fn_88356420();
ts4_word fn_883579C0();
ts4_word fn_8839A4E0();
ts4_word lib2_ogg_sync_buffer_883BAE48();
ts4_word ts4_if_get_u32_off4_883BAF20();
ts4_word lib2_oggpack_read_883BD268();
ts4_word fn_883C2A48();
ts4_word ts4_addr_lbl_88029348_88332070();
ts4_word ts4_call_seq_ts4_memset_883BD130();
ts4_word ts4_call_seq_u32_off18c_883189A8();
ts4_word ts4_call_vtable_slot11_883AC3C8();
ts4_word ts4_get_u32_lbl_88B3302C_883163B8();
ts4_word ts4_if_call_seq_fn_8856CD88_88567ED8();
ts4_word ts4_if_call_seq_u32_off880_88366B60();
ts4_word ts4_if_get_u32_off188_88319E00();
ts4_word ts4_loop_get_u32_off0_88335CA0();
ts4_word ts4_set_u32_off40_883B8B68();
ts4_word ts4_set_u32_offc_883B6FC8();
ts4_word ts4_tailcall_NetDll_send_884F0350();
extern char $LN88354DC4[];
extern char fn_88348828[];
extern char ts4_clear_owned_buffer_adj1c_883488A0[];
extern char fn_8834A6E0[];
extern char fn_8834A730[];
extern char fn_8834A758[];
extern char fn_8834B210[];
extern char ts4_set_float_by_index_adj1c_8834B260[];
extern char fn_8834C9B0[];
extern char fn_8834D4E8[];
extern char fn_883818B8[];
extern char ts4_get_u32_off2A0_adj1c_88381958[];
extern char fn_883819B8[];
extern char fn_883826D8[];
extern char ts4_thunk_adj1c_bool_arg_88382F90[];
extern char lbl_8802AC54[];
extern char lbl_8802AD40[];
extern char lbl_8802AD98[];
extern char lbl_8802AECC[];
extern char lbl_8802AF28[];
extern char lbl_8802B0F4[];
extern char lbl_8802B898[];
extern char lbl_8802B8D8[];
extern char lbl_8802BDF8[];
extern char lbl_8802BE04[];
extern char lbl_8802BEE4[];
extern char lbl_8802E890[];
extern char lbl_88035FCC[];
extern char lbl_88035FD4[];
extern char lbl_88035FE0[];
extern char lbl_880C1320[];
extern char lbl_88B35010[];
extern char lbl_88B35100[];
extern char lbl_88B352A4[];
extern char lbl_88B352D8[];
extern char lbl_88B35380[];
extern char lbl_88B353E0[];
extern char lbl_88B35590[];
extern char lbl_88B355F0[];
extern char lbl_88B36E98[];
extern char ts4_adjust_minus_28_thunk_883441F0[];
extern char ts4_adjust_minus_28_thunk_88348810[];
extern char ts4_adjust_minus_28_thunk_883488F0[];
extern char ts4_adjust_minus_28_thunk_88348908[];
extern char ts4_adjust_minus_28_thunk_88348920[];
extern char ts4_adjust_minus_28_thunk_8834A718[];
extern char ts4_adjust_minus_28_thunk_8834A868[];
extern char ts4_adjust_minus_28_thunk_8834B248[];
extern char ts4_adjust_minus_28_thunk_8834B360[];
extern char ts4_adjust_minus_28_thunk_8834D4D0[];
extern char ts4_adjust_minus_28_thunk_8834D560[];
extern char ts4_fn_883E63B8[];
extern char ts4_forward_adjusted_or_null_m1c_883818A0[];
extern char ts4_forward_adjusted_or_null_m1c_88381928[];
extern char ts4_forward_adjusted_or_null_m1c_88381940[];
extern char ts4_forward_adjusted_or_null_m1c_88381988[];
extern char ts4_forward_adjusted_or_null_m1c_883819A0[];
extern char ts4_forward_adjusted_or_null_m1c_88381A28[];
extern char ts4_forward_adjusted_or_null_m1c_88381A40[];
extern char ts4_forward_adjusted_or_null_m1c_88381A58[];
extern char ts4_forward_adjusted_or_null_m1c_88382738[];
extern char ts4_if_call_seq_lbl_8802BE78_883817E8[];
extern char ts4_if_get_u32_off0_88381850[];
extern char ts4_set_u32_off0_88374A00[];
ts4_word ts4_get_unit_and_chunks_8830B140();
ts4_word fn_8830C210();
ts4_word fn_8830C628();
ts4_word fn_88316070();
ts4_word fn_88316460();
ts4_word fn_88316650();
ts4_word fn_8831CE30();
ts4_word fn_8831F158();
ts4_word fn_88323DC0();
ts4_word fn_88327878();
ts4_word fn_883282A8();
ts4_word fn_88329188();
ts4_word fn_883297E8();
ts4_word fn_883299F0();
ts4_word fn_8832B630();
ts4_word fn_88338428();
ts4_word fn_8834D650();
ts4_word fn_8834D6B8();
ts4_word fn_8834EBD8();
ts4_word fn_8834EC78();
ts4_word fn_8835AC70();
ts4_word fn_88361360();
ts4_word fn_88361630();
ts4_word fn_8836CD70();
ts4_word fn_88374280();
ts4_word fn_88376740();
ts4_word fn_883768A0();
ts4_word fn_88376D10();
ts4_word fn_8839CB20();
ts4_word fn_883A1E30();
ts4_word fn_883A2090();
ts4_word lib2_set_defaults__883A3DB8();
ts4_word fn_883AAE58();
ts4_word ts4_set_flag_bit5_off24_883AC468();
ts4_word fn_883AD0D0();
ts4_word lib2_FLAC__MD5Final_883B8BB0();
ts4_word fn_883BC3B8();
ts4_word ts4_ratio_q15_even_883C02F0();
ts4_word fn_88566FE8();
ts4_word ts4_call_seq_fn_88332070_8837B2D0();
ts4_word ts4_if_call_seq_fn_883BBE98_883BBF50();
ts4_word ts4_if_call_seq_fn_88592800_88592F70();
ts4_word ts4_if_call_seq_u32_off0_883B6F68();
ts4_word ts4_if_call_seq_u32_off0_883BAC48();
ts4_word ts4_if_call_seq_u32_off10_883BDAA0();
ts4_word ts4_if_call_seq_u32_off24_883BDA50();
ts4_word ts4_if_get_u32_off128_8831F0C0();
ts4_word ts4_if_get_u32_off174_88319E70();
ts4_word ts4_if_get_u32_off18_88319E40();
ts4_word ts4_if_get_u32_off18_8832C248();
ts4_word ts4_if_get_u32_off4c_883258A0();
ts4_word ts4_if_get_u32_offc_883AC430();
ts4_word ts4_tailcall_NetDll_bind_884F02A0();
ts4_word ts4_tailcall_NetDll_ioctlsocket_884F0268();
ts4_word ts4_tailcall_NetDll_listen_884F02D0();
ts4_word ts4_tailcall_NetDll_socket_884F0240();
extern char fn_88432FD0[];
extern char fn_88433078[];
extern char lbl_8803A308[];
extern char lbl_8803A51C[];
extern char lbl_8803A528[];
extern char lbl_8803BC50[];
extern char lbl_8803C290[];
extern char lbl_8803C3E4[];
extern char lbl_8803C404[];
extern char lbl_8803CB5C[];
extern char lbl_8803E670[];
extern char lbl_8803E744[];
extern char lbl_8803EB50[];
extern char lbl_8803EBA4[];
extern char lbl_8803EC14[];
extern char lbl_8803ED40[];
extern char lbl_8803ED58[];
extern char lbl_88040154[];
extern char lbl_8804080C[];
extern char lbl_88040818[];
extern char lbl_88040B78[];
extern char lbl_88040B80[];
extern char lbl_88041544[];
extern char lbl_88041928[];
extern char lbl_88041E68[];
extern char lbl_8804201C[];
extern char lbl_8804202C[];
extern char lbl_88042C70[];
extern char lbl_88042D08[];
extern char lbl_88043104[];
extern char lbl_88043ED0[];
extern char lbl_88043EE0[];
extern char lbl_8807FF50[];
extern char lbl_88081810[];
extern char lbl_880818D4[];
extern char lbl_88081A10[];
extern char lbl_88081A1C[];
extern char lbl_8808DE60[];
extern char lbl_880DF9C0[];
extern char lbl_880E1DE4[];
extern char lbl_880EE678[];
extern char lbl_88B3D198[];
extern char lbl_88B3D1E8[];
extern char lbl_88CACF08[];
extern char lbl_88CAD340[];
extern char lbl_88CAD350[];
extern char lbl_88CAD568[];
extern char lbl_88CAD56C[];
extern char lbl_88CFF5CC[];
extern char lbl_88CFF9EC[];
extern char lbl_88D0013C[];
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841C5E8();
ts4_word fn_8841CBF8();
ts4_word fn_8841ED08();
ts4_word fn_8841ED98();
ts4_word ts4_last_node_nonzero_8841EF38();
ts4_word fn_884210E8();
ts4_word fn_88421338();
ts4_word fn_884215B0();
ts4_word fn_88422860();
ts4_word fn_88423E28();
ts4_word fn_88424900();
ts4_word fn_88425490();
ts4_word fn_88426178();
ts4_word fn_884272A0();
ts4_word ts4_ref_holder_dtor_88427338();
ts4_word fn_884299C8();
ts4_word ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480();
ts4_word fn_8842B568();
ts4_word fn_88430B38();
ts4_word fn_88432BE0();
ts4_word fn_88433120();
ts4_word fn_88435638();
ts4_word fn_88436A98();
ts4_word fn_88436B38();
ts4_word fn_884394B8();
ts4_word fn_884555E8();
ts4_word fn_88460200();
ts4_word fn_885219D0();
ts4_word fn_885221B8();
ts4_word fn_88525F18();
ts4_word fn_885E7378();
ts4_word ts4_call_seq_fn_8841A510_8841A7C8();
ts4_word ts4_call_seq_fn_88428B48_88433568();
ts4_word ts4_call_seq_fn_884522B0_884649C0();
ts4_word ts4_call_seq_fn_8845F838_88439588();
ts4_word ts4_call_seq_u32_off4_88428B48();
ts4_word ts4_find_entry_by_name_884278D0();
ts4_word ts4_forward_88421460();
ts4_word ts4_get_u16_offe_88426148();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_88428960();
ts4_word ts4_get_u32_off0_88428978();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off0_88428988();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_get_u32_off0_88428A28();
ts4_word ts4_get_u32_off0_88428B30();
ts4_word ts4_get_u32_off4_8841EAD0();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off8_8841D7B0();
ts4_word ts4_get_u32_off8_8841EF28();
ts4_word ts4_get_u32_off8_88426140();
ts4_word ts4_get_u32_off8_88427198();
ts4_word ts4_if_call_seq_lbl_8803D504_884314B0();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_call_seq_u32_off4_88428AC8();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_index_u16_array_at_field0_88428A08();
ts4_word ts4_index_u64_array_at_field0_88428A88();
ts4_word ts4_ref_holder_dtor_8841D638();
ts4_word ts4_register_callback_tables_88453940();
ts4_word ts4_register_callback_tables_884568A8();
ts4_word ts4_register_callback_tables_88460C20();
ts4_word ts4_register_callback_tables_88462348();
ts4_word ts4_register_callback_tables_88462F20();
ts4_word ts4_register_callback_tables_88464540();
ts4_word ts4_set_pair_base_plus_u16_field_88428878();
ts4_word ts4_set_u8_off1e23_88451528();
ts4_word ts4_stream_write_i32_a_88427418();
ts4_word ts4_sum_list_field_1C_8841ECE0();
ts4_word ts4_tailcall_NetDll__WSAFDIsSet_884F0398();
ts4_word ts4_tailcall_NetDll_select_884F02F8();
ts4_word ts4_tailcall_NetDll_setsockopt_884F0280();
ts4_word ts4_tailcall_memcpy_88421450();
extern char fn_88421120[];
extern char g_ts4_true_string[];
extern char lbl_88029198[];
extern char lbl_8803A514[];
extern char lbl_8803A570[];
extern char lbl_8803BC48[];
extern char lbl_8803BC70[];
extern char lbl_8803BC7C[];
extern char lbl_8803C3F8[];
extern char lbl_8803D1C8[];
extern char lbl_8803E660[];
extern char lbl_8803E6E0[];
extern char lbl_8803E7C4[];
extern char lbl_8803E7F8[];
extern char lbl_8803E820[];
extern char lbl_8803F49C[];
extern char lbl_8803F52C[];
extern char lbl_8803F53C[];
extern char lbl_8803F54C[];
extern char lbl_8803F55C[];
extern char lbl_8803F9E8[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_88040134[];
extern char lbl_880407B0[];
extern char lbl_880407BC[];
extern char lbl_880407C8[];
extern char lbl_880408F8[];
extern char lbl_8804090C[];
extern char lbl_88040CE8[];
extern char lbl_88040CF8[];
extern char lbl_88040D08[];
extern char lbl_88040D18[];
extern char lbl_880410F0[];
extern char lbl_88041AB0[];
extern char lbl_88041AC8[];
extern char lbl_88041AE8[];
extern char lbl_880D1B30[];
extern char lbl_880D2F08[];
extern char lbl_880DD510[];
extern char lbl_88B3C464[];
extern char lbl_88B3C520[];
extern char lbl_88B3D18C[];
extern char lbl_88B3D1AC[];
extern char lbl_88B3D1EC[];
extern char lbl_88CAD32C[];
extern char lbl_88CAD560[];
extern char lbl_88CAD564[];
extern char lbl_88CAD574[];
ts4_word fn_8832EDB0();
ts4_word fn_884054F0();
ts4_word fn_88408B18();
ts4_word fn_88413498();
ts4_word fn_8841A3F8();
ts4_word fn_8841C428();
ts4_word fn_8841C678();
ts4_word fn_884223A0();
ts4_word fn_88423660();
ts4_word fn_88424D80();
ts4_word fn_88428C10();
ts4_word fn_8842A378();
ts4_word fn_88430C80();
ts4_word fn_88431250();
ts4_word fn_884312B8();
ts4_word fn_88431B10();
ts4_word fn_88474120();
ts4_word fn_88475AE8();
ts4_word fn_885646F8();
ts4_word fn_8857C3D8();
ts4_word ts4_get_u32_off0_884289A8();
ts4_word ts4_get_u32_off0_884289B8();
ts4_word ts4_get_u32_off0_88428A18();
ts4_word ts4_get_u32_off0_88428A70();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_offd0_884736C8();
ts4_word ts4_if_call_seq_RtlInitAnsiString_8857C370();
ts4_word ts4_if_call_seq_fn_884214A8_88428B98();
ts4_word ts4_if_call_seq_fn_885844E8_8857C468();
ts4_word ts4_if_call_seq_lbl_8803E76C_88425178();
ts4_word ts4_if_call_seq_u32_off0_884288F8();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
extern char fn_88434910[];
extern char lbl_8802B120[];
extern char lbl_8803A258[];
extern char lbl_8803A280[];
extern char lbl_8803A2EC[];
extern char lbl_8803A374[];
extern char lbl_8803A974[];
extern char lbl_8803B558[];
extern char lbl_8803B570[];
extern char lbl_8803B618[];
extern char lbl_8803C474[];
extern char lbl_8803DCB4[];
extern char lbl_8803DDEC[];
extern char lbl_8803F500[];
extern char lbl_8803F5D4[];
extern char lbl_88040148[];
extern char lbl_88040344[];
extern char lbl_88040740[];
extern char lbl_8804074C[];
extern char lbl_88040758[];
extern char lbl_88041080[];
extern char lbl_880418CC[];
extern char lbl_880418D8[];
extern char lbl_880418E8[];
extern char lbl_8804190C[];
extern char lbl_88042C44[];
extern char lbl_88042C5C[];
extern char lbl_88042D18[];
extern char lbl_88042DA4[];
extern char lbl_88042DB4[];
extern char lbl_88B3C7EC[];
extern char lbl_88B3D184[];
extern char lbl_88B3D1E4[];
extern char lbl_88B3D1F8[];
extern char lbl_88B3D3C8[];
ts4_word KeTlsSetValue();
ts4_word fn_88316808();
ts4_word fn_88419568();
ts4_word fn_8841D598();
ts4_word fn_8841DA58();
ts4_word fn_8841EF70();
ts4_word fn_884214A8();
ts4_word fn_88421B10();
ts4_word fn_88421BF8();
ts4_word fn_884224B0();
ts4_word fn_88422638();
ts4_word fn_88423788();
ts4_word fn_88424C88();
ts4_word fn_88426440();
ts4_word fn_8842AC78();
ts4_word fn_88434990();
ts4_word fn_88435838();
ts4_word fn_88470208();
ts4_word fn_88471DC8();
ts4_word fn_884C5468();
ts4_word fn_885E7AD8();
ts4_word fn_885E7BA8();
ts4_word ts4_call_seq_fn_88428B48_88433F90();
ts4_word ts4_get_u32_off0_88428998();
ts4_word ts4_get_u32_off0_88428A60();
ts4_word ts4_get_u32_off4_88426138();
ts4_word ts4_if_call_seq_fn_88309DB8_88309438();
ts4_word ts4_if_call_seq_fn_88426110_8841F670();
ts4_word ts4_if_get_fn_8832BFC0_883168A8();
ts4_word ts4_lookup_then_forward_88317468();
extern char fn_88436868[];
extern char lbl_88041554[];
extern char lbl_88041AA4[];
extern char lbl_88041FEC[];
extern char lbl_88041FF8[];
extern char lbl_88042C0C[];
extern char lbl_8804812C[];
extern char lbl_88048144[];
extern char lbl_88049804[];
extern char lbl_8807FF74[];
extern char lbl_88080278[];
extern char lbl_8808029C[];
extern char lbl_8808030C[];
extern char lbl_88080CE4[];
extern char lbl_88080CF4[];
extern char lbl_88080D04[];
extern char lbl_8808122C[];
extern char lbl_88081250[];
extern char lbl_88081830[];
extern char lbl_88081980[];
extern char lbl_88081E00[];
extern char lbl_88081E10[];
extern char lbl_88081E20[];
extern char lbl_88081E44[];
extern char lbl_88081E74[];
extern char lbl_88082070[];
extern char lbl_880820E8[];
extern char lbl_8808212C[];
extern char lbl_88082540[];
extern char lbl_88082D30[];
extern char lbl_88082DFC[];
extern char lbl_8808338C[];
ts4_word fn_8841C9F0();
ts4_word fn_88436D30();
ts4_word fn_88441FF8();
ts4_word fn_8844EF88();
ts4_word fn_88451948();
ts4_word fn_88462090();
ts4_word fn_88475F30();
ts4_word fn_885E76C0();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word ts4_call_seq_fn_88467768_884544F8();
ts4_word ts4_call_seq_fn_88557200_88528678();
ts4_word ts4_call_seq_lbl_88049700_88436488();
ts4_word ts4_call_seq_u32_lbl_88CACF08_885E7B40();
ts4_word ts4_if_get_u8_offd_884263F0();
extern char lbl_88007998[];
extern char lbl_880490E4[];
extern char lbl_880490F4[];
extern char lbl_8804910C[];
extern char lbl_8804911C[];
extern char lbl_88080174[];
extern char lbl_8808019C[];
extern char lbl_880804FC[];
extern char lbl_88081BB0[];
extern char lbl_88081BD4[];
extern char lbl_88081E84[];
extern char lbl_88081EA8[];
extern char lbl_88081F8C[];
extern char lbl_88081FB0[];
extern char lbl_88082034[];
extern char lbl_880820AC[];
extern char lbl_8808233C[];
extern char lbl_8808257C[];
extern char lbl_88082600[];
extern char lbl_8808260C[];
extern char lbl_88082618[];
extern char lbl_880827F4[];
extern char lbl_88082CB0[];
extern char lbl_88082D48[];
extern char lbl_880831CC[];
extern char lbl_88086A7C[];
extern char lbl_88C2287C[];
ts4_word fn_88420ED0();
ts4_word fn_884430E8();
ts4_word fn_8844D060();
ts4_word fn_88451380();
ts4_word fn_88451728();
ts4_word fn_88460CF0();
ts4_word fn_88461C60();
ts4_word fn_88465FE0();
ts4_word fn_884664B0();
ts4_word fn_88466AB0();
ts4_word fn_88466E80();
ts4_word fn_88474400();
ts4_word fn_88488828();
ts4_word fn_88489498();
ts4_word fn_88489C28();
ts4_word fn_8848C298();
ts4_word fn_8848E6A8();
ts4_word fn_88490868();
ts4_word fn_88537FC8();
ts4_word ts4_get_address_of_global_88466768();
ts4_word ts4_if_call_seq_u32_off3c_8846A0F8();
ts4_word ts4_set_885E85A8();
extern char lbl_88029268[];
extern char lbl_8802B770[];
extern char lbl_88043C2C[];
extern char lbl_8804901C[];
extern char lbl_8804903C[];
extern char lbl_8807FF98[];
extern char lbl_8808083C[];
extern char lbl_88080848[];
extern char lbl_8808085C[];
extern char lbl_88080868[];
extern char lbl_88080874[];
extern char lbl_88081BA0[];
extern char lbl_88081C00[];
extern char lbl_88081D34[];
extern char lbl_88082624[];
extern char lbl_88082E34[];
extern char lbl_88082E44[];
extern char lbl_880832C4[];
extern char lbl_8808333C[];
extern char lbl_88084834[];
extern char lbl_88086C58[];
extern char lbl_88086EA8[];
extern char lbl_88086F50[];
extern char lbl_88086F54[];
extern char lbl_88086F58[];
extern char lbl_880E49E0[];
ts4_word fn_88436500();
ts4_word ts4_ref_holder_dtor_88436F58();
ts4_word fn_8843AE88();
ts4_word fn_8843B8F8();
ts4_word fn_8843BB28();
ts4_word fn_88441E80();
ts4_word fn_88465E08();
ts4_word fn_884684A8();
ts4_word fn_88468D78();
ts4_word fn_88470870();
ts4_word fn_88476058();
ts4_word fn_88476B48();
ts4_word fn_88477140();
ts4_word fn_8847ED38();
ts4_word fn_8847EDC0();
ts4_word fn_8848C6D0();
ts4_word ts4_if_call_seq_u32_off8_8848E420();
ts4_word fn_884909E8();
ts4_word fn_885283E8();
ts4_word ts4_if_call_seq_u32_off4_88472748();
ts4_word ts4_ref_holder_dtor_8847B270();
extern char fn_884667B0[];
extern char fn_884667D8[];
extern char fn_88466878[];
extern char lbl_880026EC[];
extern char lbl_880038E0[];
extern char lbl_88028C14[];
extern char lbl_88029278[];
extern char lbl_8802CEC8[];
extern char lbl_8802E918[];
extern char lbl_8803A3B0[];
extern char lbl_88080AA4[];
extern char lbl_88080AD8[];
extern char lbl_88081AE0[];
extern char lbl_88081AE8[];
extern char lbl_88081C10[];
extern char lbl_88081C34[];
extern char lbl_88081C90[];
extern char lbl_88081CB4[];
extern char lbl_88081DF0[];
extern char lbl_88081F98[];
extern char lbl_88082164[];
extern char lbl_88082170[];
extern char lbl_880826AC[];
extern char lbl_880826EC[];
extern char lbl_8808276C[];
extern char lbl_88082830[];
extern char lbl_88082CF8[];
extern char lbl_8808384C[];
extern char lbl_88086C5C[];
extern char lbl_88086EC0[];
extern char lbl_88086EC4[];
extern char lbl_88086EC8[];
extern char lbl_88086ED0[];
extern char lbl_88086EE0[];
extern char lbl_88086EF0[];
extern char lbl_88086F00[];
extern char lbl_880EE0E4[];
extern char ts4_get_u32_off0_88466798[];
extern char ts4_get_u32_off0_88466800[];
extern char ts4_get_u32_off0_88466818[];
extern char ts4_get_u32_off0_88466830[];
extern char ts4_get_u32_off0_88466848[];
extern char ts4_get_u32_off0_88466860[];
extern char ts4_get_u32_off0_88466928[];
ts4_word fn_8841A328();
ts4_word fn_8843AD08();
ts4_word fn_884433D8();
ts4_word fn_884520E8();
ts4_word fn_8845FF60();
ts4_word fn_8846B868();
ts4_word fn_8846B998();
ts4_word fn_8846BAA8();
ts4_word fn_8846BB60();
ts4_word fn_8846BC08();
ts4_word fn_8846BD20();
ts4_word ts4_counted_ref_release_88475B08();
ts4_word fn_88477070();
ts4_word fn_8848C370();
ts4_word ts4_if_call_seq_u8_off26_8848F310();
ts4_word fn_88490B30();
ts4_word fn_88490C88();
ts4_word fn_8852CD50();
ts4_word ts4_addr_lbl_88084264_8847EF68();
ts4_word ts4_if_call_seq_u32_off1e30_88451E90();
ts4_word ts4_if_get_u32_offb8_8848F838();
ts4_word ts4_if_get_u8_off9_8846A538();
extern char lbl_88001A6C[];
extern char lbl_8802C1D4[];
extern char lbl_8808386C[];
extern char lbl_880838A4[];
extern char lbl_880849B0[];
extern char lbl_88086A94[];
extern char lbl_88087078[];
extern char lbl_880870F4[];
extern char lbl_8808726C[];
extern char lbl_88087300[];
extern char lbl_88087534[];
extern char lbl_8808762C[];
extern char lbl_880878E4[];
extern char lbl_88087918[];
extern char lbl_8808793C[];
extern char lbl_88087A7C[];
extern char lbl_88087A8C[];
extern char lbl_88087A9C[];
extern char lbl_88087AA8[];
extern char lbl_88087AB4[];
extern char lbl_88087AC8[];
extern char lbl_88087AD4[];
extern char lbl_88087B80[];
extern char lbl_88087C28[];
extern char lbl_88087C34[];
extern char lbl_88087C48[];
extern char lbl_88087C54[];
extern char lbl_88087C60[];
extern char lbl_88087E48[];
extern char lbl_88087E60[];
extern char lbl_88087E6C[];
extern char lbl_88087E78[];
extern char lbl_88087E8C[];
extern char lbl_88087EA0[];
extern char lbl_88D3CB10[];
ts4_word RtlInitializeCriticalSectionAndSpinCount();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_884717C0();
ts4_word fn_88472530();
ts4_word fn_88474B90();
ts4_word fn_88475D10();
ts4_word fn_88478548();
ts4_word fn_884785B8();
ts4_word fn_8847EE48();
ts4_word fn_8847F1E8();
ts4_word fn_8848B708();
ts4_word fn_8848CB28();
ts4_word ts4_if_call_seq_u8_off26_8848F1E0();
ts4_word fn_88490F78();
ts4_word fn_884911B8();
ts4_word fn_88492868();
ts4_word fn_88492D28();
ts4_word fn_884942A8();
ts4_word fn_884944C0();
ts4_word fn_884958C8();
ts4_word fn_884980C0();
ts4_word fn_8849F380();
ts4_word fn_884A0420();
ts4_word fn_884A04C8();
ts4_word fn_884A2580();
ts4_word fn_8854D9B0();
ts4_word fn_885E9568();
ts4_word fn_885EA1A8();
ts4_word fn_885F42B0();
ts4_word ts4_addr_lbl_8808384C_88476C30();
ts4_word ts4_call_seq_u32_lbl_88CACF08_8846BE08();
ts4_word ts4_forward_to_fn_884381D8();
ts4_word ts4_get_u32_off7c_8846AA28();
ts4_word ts4_get_u32_offac_8846AA30();
ts4_word ts4_get_u32_offac_8846C158();
ts4_word ts4_if_call_seq_u32_offcc_884A5900();
ts4_word ts4_push_back_word_8846C498();
ts4_word ts4_push_back_word_8846C508();
ts4_word ts4_push_back_word_8846C578();
ts4_word ts4_push_back_word_8846C5E8();
ts4_word ts4_push_back_word_8846C968();
ts4_word ts4_set_u16_off20_885F45F0();
ts4_word ts4_set_u32_off8_8847FA60();
ts4_word ts4_tailcall_fn_885127C0_885134F8();
extern char fn_88484248[];
extern char lbl_88001978[];
extern char lbl_88004450[];
extern char lbl_88028B58[];
extern char lbl_8802A0C8[];
extern char lbl_8802E8D8[];
extern char lbl_88083F24[];
extern char lbl_8808406C[];
extern char lbl_88084334[];
extern char lbl_880846E8[];
extern char lbl_88084A14[];
extern char lbl_88086C3C[];
extern char lbl_88087004[];
extern char lbl_88087154[];
extern char lbl_8808755C[];
extern char lbl_880876F0[];
ts4_word fn_88470678();
ts4_word fn_88473EB0();
ts4_word fn_88475FB8();
ts4_word fn_88476B90();
ts4_word fn_88476EC0();
ts4_word fn_88478648();
ts4_word fn_88479EA8();
ts4_word fn_8847EED8();
ts4_word fn_88484538();
ts4_word fn_88484C78();
ts4_word fn_8848E368();
ts4_word fn_88493ED0();
ts4_word fn_884954A8();
ts4_word fn_8854DFB0();
ts4_word fn_8854E1F8();
ts4_word ts4_extract_bits_5_4_of_byte38_or_zero_88473FE8();
ts4_word ts4_get_u32_off7c_8846AA10();
ts4_word ts4_if_call_seq_u32_off118_8848E3E0();
extern char lbl_88029644[];
extern char lbl_8803E6B0[];
extern char lbl_880836F4[];
extern char lbl_88084BDC[];
extern char lbl_88087038[];
extern char lbl_88087424[];
extern char lbl_880874B0[];
extern char lbl_880874EC[];
extern char lbl_880875EC[];
extern char lbl_8808770C[];
extern char lbl_88087754[];
extern char lbl_88087764[];
extern char lbl_88087770[];
extern char lbl_88087780[];
extern char lbl_8808778C[];
extern char lbl_880878D8[];
extern char lbl_8808790C[];
extern char lbl_88087B98[];
extern char lbl_88087BB0[];
extern char lbl_88087BBC[];
extern char lbl_88087BC8[];
extern char lbl_88087BDC[];
extern char lbl_88087BEC[];
ts4_word fn_88474A60();
ts4_word fn_88477210();
ts4_word fn_884782D0();
ts4_word fn_8847EB88();
ts4_word fn_8847FA78();
ts4_word fn_8847FBE8();
ts4_word fn_8847FC28();
ts4_word fn_8848AFB8();
ts4_word fn_8848BF58();
ts4_word fn_88494180();
ts4_word fn_8849F6D8();
ts4_word fn_8849F848();
ts4_word fn_884A0690();
ts4_word fn_884A2768();
ts4_word fn_8850C3D0();
ts4_word fn_8854DD10();
ts4_word fn_8854DDE8();
ts4_word fn_8854EAA8();
ts4_word ts4_clear_pointer_slot_8846B2F8();
ts4_word ts4_if_call_seq_lbl_88083354_88477588();
ts4_word ts4_if_get_u32_off28_88476C68();
ts4_word ts4_noop_884927F8();
extern char lbl_88087904[];
extern char lbl_88087EDC[];
extern char lbl_88088130[];
extern char lbl_8808859C[];
extern char lbl_88088868[];
extern char lbl_88088878[];
extern char lbl_88088894[];
extern char lbl_880888A4[];
extern char lbl_880888B4[];
extern char lbl_880888C4[];
extern char lbl_880888E4[];
extern char lbl_88088F80[];
extern char lbl_88088F90[];
extern char lbl_88088FA8[];
extern char lbl_88088FB8[];
extern char lbl_88088FD8[];
extern char lbl_880890EC[];
extern char lbl_880890FC[];
extern char lbl_88089114[];
extern char lbl_88089124[];
extern char lbl_88089144[];
extern char lbl_88089584[];
extern char lbl_880896B0[];
extern char lbl_880897EC[];
extern char lbl_880898EC[];
extern char lbl_8808BFAC[];
extern char lbl_8808C24C[];
extern char lbl_88C2625C[];
extern char lbl_88D25FB4[];
ts4_word fn_8841F000();
ts4_word fn_88420E00();
ts4_word fn_88423730();
ts4_word fn_88423CE0();
ts4_word fn_88423D60();
ts4_word fn_88424B50();
ts4_word fn_88424E30();
ts4_word fn_88439630();
ts4_word fn_8846E050();
ts4_word fn_88471F10();
ts4_word fn_884758C0();
ts4_word fn_88477368();
ts4_word fn_8849B2F8();
ts4_word fn_884A6080();
ts4_word fn_884A8B00();
ts4_word fn_884AC9B8();
ts4_word fn_884AD988();
ts4_word fn_884B35F8();
ts4_word fn_884B70D0();
ts4_word fn_884B9B20();
ts4_word fn_884BDD80();
ts4_word fn_884C6A10();
ts4_word fn_884CC378();
ts4_word fn_884CC5F8();
ts4_word fn_884DA650();
ts4_word fn_884E30B8();
ts4_word fn_88510C48();
ts4_word fn_88552158();
ts4_word fn_885E75E0();
ts4_word fn_885E7660();
ts4_word fn_885E76A0();
ts4_word ts4_call_885ED0A8_884D3B60();
ts4_word ts4_call_seq_fn_884235C0_885EB618();
ts4_word ts4_call_seq_fn_884235C0_885EB660();
ts4_word ts4_call_seq_lbl_88089248_884B4E88();
ts4_word ts4_clear_pointer_slot_8846B028();
ts4_word ts4_clear_pointer_slot_8846B078();
ts4_word ts4_clear_pointer_slot_8846B168();
ts4_word ts4_get_u32_off8_885E7640();
ts4_word ts4_if_tailcall_ts4_copy_bytes_88421328();
ts4_word ts4_tailcall_fn_884235C0_885EB658();
ts4_word ts4_tailcall_fn_88559990_8854F778();
extern char ts4_delete_member_0_884D5F78[];
extern char lbl_8803E690[];
extern char lbl_880444EC[];
extern char lbl_880885AC[];
extern char lbl_8808882C[];
extern char lbl_8808883C[];
extern char lbl_8808885C[];
extern char lbl_88088BE0[];
extern char lbl_88088BF0[];
extern char lbl_88088C08[];
extern char lbl_88088C18[];
extern char lbl_88088C38[];
extern char lbl_8808BFC0[];
extern char lbl_8808C35C[];
extern char lbl_8808C5A0[];
extern char lbl_8808C7DC[];
extern char lbl_8808C8B4[];
extern char lbl_8808CCCC[];
extern char lbl_8808CDAC[];
extern char lbl_8808CDC8[];
extern char lbl_880FC690[];
extern char lbl_88D25C34[];
extern char lbl_88D26F54[];
extern char lbl_88D26F84[];
ts4_word ts4_link_chain_contains_8841EB08();
ts4_word fn_8841F3E0();
ts4_word fn_884235C0();
ts4_word fn_88423858();
ts4_word fn_884A86D8();
ts4_word fn_884AAD20();
ts4_word fn_884B6FF8();
ts4_word fn_884B76C8();
ts4_word fn_884BB3B0();
ts4_word fn_884BB418();
ts4_word fn_884BB5F8();
ts4_word fn_884C25E8();
ts4_word fn_884C4688();
ts4_word fn_884C6220();
ts4_word fn_884C6B58();
ts4_word fn_884C9DD0();
ts4_word fn_884C9F08();
ts4_word fn_884CAD68();
ts4_word fn_884CB2C8();
ts4_word fn_884CB7F8();
ts4_word fn_884CD420();
ts4_word fn_884CF9E8();
ts4_word fn_884CFAA0();
ts4_word fn_884CFBB8();
ts4_word fn_884D0158();
ts4_word fn_884D1388();
ts4_word fn_884D1418();
ts4_word fn_884D3C58();
ts4_word fn_884D6670();
ts4_word fn_884D9798();
ts4_word ts4_pooled_deleting_dtor_884DA998();
ts4_word fn_885E7A90();
ts4_word fn_885EBBC8();
ts4_word ts4_call_seq_u32_off14_884D3EE0();
ts4_word ts4_get_u32_off8_885E7620();
ts4_word ts4_if_call_seq_u32_off0_884CCBB8();
ts4_word ts4_invoke_arg_vslot_8841CEC8();
ts4_word ts4_loop_call_seq_fn_885ED260_884D7550();
ts4_word ts4_noop_885ED200();
ts4_word ts4_push_back_word_8846C738();
ts4_word ts4_set_u32_off0_884BE220();
ts4_word ts4_set_u32_off8_885ED1E8();
ts4_word ts4_tailcall_fn_884CD990_884CE090();
extern char fn_88521390[];
extern char fn_88521778[];
extern char fn_88521CB8[];
extern char fn_88522640[];
extern char fn_88522C48[];
extern char fn_885234A0[];
extern char fn_88524258[];
extern char fn_88525208[];
extern char lbl_8803CC5C[];
extern char lbl_8803CCC4[];
extern char lbl_8803CCD4[];
extern char lbl_8803D124[];
extern char lbl_880881D8[];
extern char lbl_880887DC[];
extern char lbl_880887EC[];
extern char lbl_8808880C[];
extern char lbl_8808894C[];
extern char lbl_8808895C[];
extern char lbl_88088974[];
extern char lbl_88088984[];
extern char lbl_880889A4[];
extern char lbl_88088D1C[];
extern char lbl_88088D2C[];
extern char lbl_88088D44[];
extern char lbl_88088D54[];
extern char lbl_88088D74[];
extern char lbl_880894F4[];
extern char lbl_88089504[];
extern char lbl_88089524[];
extern char lbl_88089534[];
extern char lbl_88089554[];
extern char lbl_8808A544[];
extern char lbl_8808B924[];
extern char lbl_8808C29C[];
extern char lbl_8808C8A4[];
extern char lbl_8808CD00[];
extern char lbl_880CDD40[];
extern char lbl_880CE328[];
extern char lbl_880E9128[];
extern char lbl_88C6ACB0[];
extern char lbl_88CAD05C[];
extern char lbl_88D25FD4[];
extern char lbl_88D26F88[];
extern char lbl_88D3CB4C[];
extern char lbl_88D3CB50[];
ts4_word fn_8841EC10();
ts4_word fn_8841ED80();
ts4_word fn_884281A0();
ts4_word ts4_remove_key_swap_last_884A2988();
ts4_word fn_884A73A0();
ts4_word fn_884AD868();
ts4_word fn_884B38E0();
ts4_word fn_884B4FF8();
ts4_word fn_884B74E8();
ts4_word fn_884C4FA8();
ts4_word fn_884C5170();
ts4_word fn_884C5520();
ts4_word fn_884C5660();
ts4_word fn_884C5D80();
ts4_word fn_884CF220();
ts4_word fn_884CF848();
ts4_word fn_884D18E0();
ts4_word fn_884D1D48();
ts4_word fn_884D21E0();
ts4_word fn_884D2938();
ts4_word fn_884D4138();
ts4_word fn_884D4B10();
ts4_word fn_884D5020();
ts4_word fn_884D5948();
ts4_word fn_884DA900();
ts4_word fn_884DAC70();
ts4_word fn_885E78C8();
ts4_word fn_885F4D10();
ts4_word ts4_get_u32_lbl_88C2625C_884CEB30();
ts4_word ts4_get_u32_off1c_8841ED78();
ts4_word ts4_get_u32_off8_884271C8();
ts4_word ts4_get_u32_offc_884D3518();
ts4_word ts4_get_u8_off0_884CEB40();
ts4_word ts4_if_call_seq_fn_88423730_884CF190();
ts4_word ts4_if_get_fn_884C5458_884D3E08();
extern char fn_88522300[];
extern char fn_88522340[];
extern char fn_885223F0[];
extern char fn_88522460[];
extern char lbl_88007B20[];
extern char lbl_88087888[];
extern char lbl_88088A4C[];
extern char lbl_8808CE18[];
extern char lbl_8808D020[];
extern char lbl_8808D0DC[];
extern char lbl_8808D0EC[];
extern char lbl_8808D0FC[];
extern char lbl_8808D1F0[];
extern char lbl_8808D240[];
extern char lbl_8808D258[];
extern char lbl_8808D318[];
extern char lbl_8808D478[];
extern char lbl_8808D8A0[];
extern char lbl_8808E724[];
extern char lbl_8808F798[];
extern char lbl_88C30B24[];
extern char lbl_88C313A0[];
extern char lbl_88D26FF0[];
extern char lbl_88D270B0[];
extern char lbl_88D270C0[];
extern char lbl_88D275C0[];
extern char lbl_88D2E58C[];
extern char lbl_88D4DF80[];
extern char lbl_88D4E000[];
extern char ts4_call_seq_u32_off4_88522380[];
extern char ts4_if_tailcall_fn_8856CF60_885776B8[];
extern char ts4_noop_88522378[];
extern char ts4_tailcall_fn_885223F0_88522458[];
ts4_word KeGetCurrentProcessType();
ts4_word KeTlsAlloc();
ts4_word RtlEnterCriticalSection();
ts4_word XMsgCancelIORequest();
ts4_word XMsgInProcessCall();
ts4_word XamVoiceClose();
ts4_word fn_88426FA0();
ts4_word fn_884727C8();
ts4_word fn_88483650();
ts4_word fn_884DB768();
ts4_word fn_884DFE30();
ts4_word fn_884DFF08();
ts4_word fn_884E1FE8();
ts4_word fn_884F25B8();
ts4_word fn_884F4DC0();
ts4_word fn_884F4EF0();
ts4_word fn_884F50A0();
ts4_word fn_884F5220();
ts4_word fn_884F7E18();
ts4_word fn_884F8798();
ts4_word fn_884FA5E0();
ts4_word fn_884FA7C8();
ts4_word fn_884FAAE0();
ts4_word fn_884FD5C0();
ts4_word fn_88500770();
ts4_word fn_88501178();
ts4_word fn_8854DB58();
ts4_word fn_88564470();
ts4_word fn_88566B48();
ts4_word fn_88567F48();
ts4_word fn_88568A40();
ts4_word fn_8856C298();
ts4_word fn_8856C718();
ts4_word fn_8856D2C0();
ts4_word fn_8856D948();
ts4_word fn_8856DC88();
ts4_word fn_8856F610();
ts4_word fn_8857C4C0();
ts4_word fn_8857C8C8();
ts4_word fn_885EC530();
ts4_word fn_88884DE0();
ts4_word ts4_addr_lbl_8808EADC_88558D40();
ts4_word ts4_call_seq_RtlEnterCriticalSection_884F6518();
ts4_word ts4_call_seq_fn_8856F8B0_88564168();
ts4_word ts4_call_seq_fn_885EC530_884E3450();
ts4_word ts4_get_u32_off8_885EC668();
ts4_word ts4_if_call_seq_NtClearEvent_885826F8();
ts4_word ts4_if_call_seq_fn_88423730_884237F0();
ts4_word ts4_if_call_seq_fn_8856CD88_88567F10();
ts4_word ts4_if_call_seq_lbl_88C31FF4_88582D30();
ts4_word ts4_if_call_seq_u32_lbl_88C313A0_8856CD20();
ts4_word ts4_if_call_seq_u32_off10_8856C3E0();
ts4_word ts4_if_call_seq_u32_offc_88573560();
ts4_word ts4_if_get_u32_off0_885E9628();
ts4_word ts4_if_get_u32_off4_884F4C70();
ts4_word ts4_if_get_u32_off8_8841D058();
ts4_word ts4_set_u32_off0_884F2FF8();
ts4_word ts4_stream_write_f32_884274D8();
ts4_word ts4_stream_write_i16_b_884273E8();
ts4_word ts4_stream_write_i32_b_88427448();
ts4_word ts4_tailcall_fn_884276E8_884ECFC0();
ts4_word ts4_tailcall_fn_88582660_8857B840();
extern char fn_884EDA30[];
extern char lbl_88024CFC[];
extern char lbl_8803CB64[];
extern char lbl_88081B20[];
extern char lbl_88088A64[];
extern char lbl_8808C2FC[];
extern char lbl_8808C5C8[];
extern char lbl_8808C6C0[];
extern char lbl_8808C8E8[];
extern char lbl_8808C8F0[];
extern char lbl_8808CA38[];
extern char lbl_8808CB0C[];
extern char lbl_8808CB1C[];
extern char lbl_8808CCB0[];
extern char lbl_8808CD8C[];
extern char lbl_8808D364[];
extern char lbl_8808D394[];
extern char lbl_8808D594[];
extern char lbl_8808D5B4[];
extern char lbl_880E1A00[];
extern char lbl_88CACFCC[];
extern char lbl_88CAD02C[];
ts4_word ObDereferenceObject();
ts4_word XamAlloc();
ts4_word XamCreateEnumeratorHandle();
ts4_word XamFree();
ts4_word XamGetPrivateEnumStructureFromHandle();
ts4_word fn_8841D3B0();
ts4_word fn_884D35F8();
ts4_word fn_884D5740();
ts4_word fn_884D5E30();
ts4_word fn_884D6020();
ts4_word fn_884D76D0();
ts4_word fn_884D9180();
ts4_word fn_884DAF90();
ts4_word fn_884DBE78();
ts4_word fn_884DF2D0();
ts4_word fn_884E0300();
ts4_word fn_884EB720();
ts4_word fn_884EB790();
ts4_word fn_884EBC28();
ts4_word fn_884ED968();
ts4_word fn_884F2478();
ts4_word fn_884F2540();
ts4_word fn_884F2698();
ts4_word fn_884F6478();
ts4_word fn_884F8680();
ts4_word fn_885E77F8();
ts4_word fn_885E7940();
ts4_word ts4_addr_lbl_88C2D5EC_884F6138();
ts4_word ts4_call_seq_fn_884F27D8_884F2FC8();
ts4_word ts4_call_seq_fn_884F3458_884F2020();
ts4_word ts4_call_seq_u32_off10_884F3428();
ts4_word ts4_get_u32_offc_884F4770();
ts4_word ts4_if_get_u16_off18_884F2440();
ts4_word ts4_if_get_u32_off0_884F3530();
ts4_word ts4_tailcall_fn_88426FF8_884276E8();
ts4_word ts4_tailcall_fn_884F0178_884F0228();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#define memset ts4_host_memset
#endif
ts4_word memcpy();
ts4_word memset();

/* Swing_DLL.xex 0x8835DC40: loop_call_seq u32@0x4f4, u32@0x4f4, fn_8835D7F0, u32@0x4f4, fn_8835D5D8, u32@0x4f4 */
ts4_word ts4_loop_call_seq_u32_off4f4_8835DC40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t6;
    ts4_word t8;
    unsigned char t11;
    unsigned char t12;

    (void)a1;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a3 == 256) {
        fn_8835D7F0((ts4_word)a0, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 2192) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)a2;
        return 0;
    }
    if ((ts4_word)a3 == 2) {
        p4 = (ts4_word)0;
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
        if ((ts4_word)a2 == (ts4_word)t2) {
            return 0;
        }
        if ((ts4_word)a2 < (ts4_word)t2) {
            fn_8835D7F0((ts4_word)a0, (ts4_word)0);
            p4 = (ts4_word)1;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
        if ((ts4_word)t6 < (ts4_word)a2) {
            do {
                fn_8835D5D8((ts4_word)a0, (ts4_word)1);
                t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
            } while ((ts4_word)t8 < (ts4_word)a2);
        }
        if ((ts4_word)(p4 & 0xff) != 0) {
            t11 = *(unsigned char *)((char *)(ts4_word)(a0) + 2172);
            t12 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
            fn_883A3218((ts4_word)a0);
            *(unsigned char *)((char *)(ts4_word)(a0) + 2172) = (unsigned char)t11;
            *(unsigned char *)((char *)(ts4_word)(a0) + 2173) = (unsigned char)t12;
        }
        return 0;
    }
    return 25;
}

/* Swing_DLL.xex 0x88384080: if_get u32@0x18c, u32@0x16c, u32@0x300, u32@0x180, ts4_call_vtable_slot11_883AC3C8, u32@0x18c */
ts4_word ts4_if_get_u32_off18c_88384080(ts4_word a0)
{
    ts4_word p25;
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t5;
    ts4_word t10;
    ts4_word t15;
    ts4_word t20;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 396);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 364) = (ts4_word)0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 768);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 384) = (ts4_word)0;
    }
    t3 = ts4_call_vtable_slot11_883AC3C8((ts4_word)a0);
    p25 = (ts4_word)t3;
    if ((int)t3 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 396);
        if ((ts4_word)t5 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 20))))((ts4_word)t5, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
        }
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        if ((ts4_word)t10 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 20))))((ts4_word)t10, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
        }
        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 768);
        if ((ts4_word)t15 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 20))))((ts4_word)t15, (ts4_word)1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 768) = (ts4_word)0;
        }
        t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 772);
        if ((ts4_word)t20 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 20))))((ts4_word)t20, (ts4_word)1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 772) = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 780) = (ts4_word)0;
        return 0;
    }
    return p25;
}

/* Swing_DLL.xex 0x8838DB48: if_call_seq ts4_tailcall_NetDll_socket_884F0240, ts4_tailcall_NetDll_ioctlsocket_884F0268, ts4_memset, ts4_tailcall_NetDll_bind_884F02A0, ts4_tailcall_NetDll_listen_884F02D0, u32@0x0 */
ts4_word ts4_if_call_seq_ts4_tailcall_NetDll_socket_884F0240_8838DB48(ts4_word a0, ts4_word a1)
{
    struct { ts4_word loc50[4]; ts4_word loc60[4]; } LL;
    int t1;

    LL.loc50[0] = (ts4_word)1;
    t1 = ts4_tailcall_NetDll_socket_884F0240((ts4_word)2, (ts4_word)1, (ts4_word)0);
    if ((int)t1 == -1) {
        return 44;
    }
    if ((int)ts4_tailcall_NetDll_ioctlsocket_884F0268((ts4_word)t1, (ts4_word)((2147745792) | 26238), (ts4_word)(ts4_word)&LL.loc50[0]) == -1) {
        return 53;
    }
    ts4_memset((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0, (ts4_word)16);
    *(short *)((char *)LL.loc60 + 0) = (short)2;
    LL.loc60[1] = (ts4_word)0;
    *(short *)((char *)LL.loc60 + 2) = (short)a0;
    if ((int)ts4_tailcall_NetDll_bind_884F02A0((ts4_word)t1, (ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)16) == -1) {
        return 53;
    }
    if ((int)ts4_tailcall_NetDll_listen_884F02D0((ts4_word)t1, (ts4_word)3) == -1) {
        return 53;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x88424E30: if_addr lbl_8803E744, u32@0x0, fn_88424900, u32@0x8, u32@0x0, u32@0x14 */
ts4_word ts4_if_addr_lbl_8803E744_88424E30(ts4_word a0)
{
    ts4_word p14;
    ts4_word p15;
    ts4_word p23;
    ts4_word t2;
    ts4_word t7;
    short t10;
    ts4_word t13;
    unsigned char t16;
    ts4_word t17;
    ts4_word t19;
    ts4_word t22;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803E744;
    fn_88424900();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p15 = (ts4_word)t7;
    if ((ts4_word)t7 != 0 && (ts4_word)(*(short *)((char *)(ts4_word)(t7) + 4)) != 0) {
        t10 = (short)((*(short *)((char *)(ts4_word)(t7) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t7) + 6) = t10;
        p14 = (ts4_word)t7;
        if (t10 == 0) {
            t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 0))))((ts4_word)t7, (ts4_word)1);
            p14 = (ts4_word)t13;
        }
        p15 = (ts4_word)p14;
    }
    t16 = *(unsigned char *)((char *)(ts4_word)(a0) + 24);
    p23 = (ts4_word)p15;
    if ((ts4_word)t16 != 0) {
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t19 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t22 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t19) + 0))) + 4))))((ts4_word)t19, (ts4_word)t17);
        p23 = (ts4_word)t22;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p23;
}

/* Swing_DLL.xex 0x88429820: if_call_seq lbl_8803F49C, ts4_if_call_seq_u32_off4_88428890, lbl_8803C404, ts4_if_call_seq_u32_off4_88428890, lbl_8803C3F8, ts4_if_call_seq_u32_off4_88428890 */
static ts4_word ts4_if_call_seq_lbl_8803F49C_88429820(ts4_word a0, ts4_word a1)
{
    ts4_word p24;
    ts4_word p26;
    ts4_word p28;
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word loc50[2];
    ts4_word loc70[2];
    ts4_word loc78[2];
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    unsigned char t7;
    ts4_word t8;
    unsigned char t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t16;
    ts4_word t17;
    ts4_word t20;
    ts4_word t21;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F49C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803C404);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803C3F8);
    t4 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    p28 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        t7 = *(unsigned char *)((char *)(ts4_word)(t6) + 0);
        p26 = (ts4_word)t6;
        if ((ts4_word)t7 != 0) {
            t8 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc68[0]);
            t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
            p24 = (ts4_word)t8;
            if ((ts4_word)t9 != 0) {
                t10 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0]);
                t11 = ts4_get_u32_off4_88426130((ts4_word)t10);
                ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&loc70[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8803C404);
                ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&loc78[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8803C3F8);
                t16 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
                t17 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc70[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t17) + 0));
                *(ts4_word *)((char *)(ts4_word)(t16) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t17) + 4));
                t20 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
                t21 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&loc78[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t20) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t21) + 0));
                *(ts4_word *)((char *)(ts4_word)(t20) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t21) + 4));
                p24 = (ts4_word)t21;
            }
            p26 = (ts4_word)p24;
        }
        p28 = (ts4_word)p26;
    }
    return p28;
}

/* Swing_DLL.xex 0x88429AB0: call_seq lbl_8803B570, lbl_8803F500, fn_884C5468, lbl_8803B558, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890 */
static ts4_word ts4_call_seq_lbl_8803B570_88429AB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F500, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B570);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803B558);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B558);
    t4 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t6) + 0) = (unsigned short)t5;
    return t6;
}

/* Swing_DLL.xex 0x88429BB0: if_call_seq lbl_8803A528, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428960 */
ts4_word ts4_if_call_seq_lbl_8803A528_88429BB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc50[2];
    ts4_word loc68[2];
    ts4_word loc70[2];
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t7;
    int t8;
    ts4_word t9;
    ts4_word t16;
    unsigned char t17;
    ts4_word t18;
    unsigned char t19;
    ts4_word t20;
    int t21;
    ts4_word t22;
    ts4_word t27;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A528);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803A528);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        if ((ts4_word)t6 != 0) {
            t7 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
            t8 = (short)*(unsigned short *)((char *)(ts4_word)(t7) + 0);
            t9 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)t8;
        }
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A51C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc70[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803A51C);
    t16 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc68[0]);
    t17 = *(unsigned char *)((char *)(ts4_word)(t16) + 0);
    if ((ts4_word)t17 != 0) {
        t18 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0]);
        t19 = *(unsigned char *)((char *)(ts4_word)(t18) + 0);
        if ((ts4_word)t19 != 0) {
            t20 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
            t21 = (short)*(unsigned short *)((char *)(ts4_word)(t20) + 0);
            t22 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc70[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t22) + 0) = (ts4_word)t21;
        }
    }
    t27 = fn_884299C8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t27;
}

/* Swing_DLL.xex 0x88429F98: if_addr lbl_8803A974, ts4_if_call_seq_u32_off4_88428890, lbl_8803B618, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0 */
ts4_word ts4_if_addr_lbl_8803A974_88429F98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p17;
    ts4_word p19;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t13;
    ts4_word t16;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A974);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B618);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p19 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p17 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t8 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
            t9 = ts4_call_seq_fn_8841A510_8841A7C8((ts4_word)t8, (ts4_word)8, (ts4_word)5);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 12))))((ts4_word)a2, (ts4_word)t9);
            t13 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 0));
            *(ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 4));
            t16 = ts4_index_u64_array_at_field0_88428A88((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)t9;
            *(ts4_word *)((char *)(ts4_word)(t16) + 4) = (ts4_word)1;
            p17 = (ts4_word)t16;
        }
        p19 = (ts4_word)p17;
    }
    return p19;
}

/* Swing_DLL.xex 0x8842A900: if_call_seq lbl_8803A514, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428960 */
ts4_word ts4_if_call_seq_lbl_8803A514_8842A900(ts4_word a0, ts4_word a1)
{
    ts4_word p23;
    ts4_word p25;
    ts4_word p27;
    ts4_word p29;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[2]; ts4_word loc70[2]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t8;
    ts4_word t12;
    ts4_word t15;
    unsigned char t16;
    ts4_word t17;
    unsigned char t18;
    ts4_word t19;
    ts4_word t20;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803A514);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803A514);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p29 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p27 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t8 = ts4_get_u32_off4_88426130(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]));
            ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&LL.loc68[0], ts4_get_u32_off0_88428978((ts4_word)(ts4_word)&LL.loc58[0]), (ts4_word)t8, (ts4_word)(ts4_word)lbl_88040134);
            t12 = ts4_get_u32_off4_88426130(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc60[0]));
            ts4_if_call_seq_u32_off0_884288F8((ts4_word)(ts4_word)&LL.loc70[0], ts4_get_u32_off0_88428978((ts4_word)(ts4_word)&LL.loc60[0]), (ts4_word)t12, (ts4_word)(ts4_word)lbl_8803A570);
            t15 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc68[0]);
            t16 = *(unsigned char *)((char *)(ts4_word)(t15) + 0);
            p25 = (ts4_word)t15;
            if ((ts4_word)t16 != 0) {
                t17 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc70[0]);
                t18 = *(unsigned char *)((char *)(ts4_word)(t17) + 0);
                p23 = (ts4_word)t17;
                if ((ts4_word)t18 != 0) {
                    t19 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)0);
                    t20 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)0);
                    *(unsigned char *)((char *)(ts4_word)(t20) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t19) + 0));
                    p23 = (ts4_word)t20;
                }
                p25 = (ts4_word)p23;
            }
            p27 = (ts4_word)p25;
        }
        p29 = (ts4_word)p27;
    }
    return p29;
}

/* Swing_DLL.xex 0x8842BA88: if_call_seq lbl_880E1DE4, u16@lbl_88B3D198, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off8_88426140, lbl_88040818 */
ts4_word ts4_if_call_seq_lbl_880E1DE4_8842BA88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[4]; } LL;
    unsigned short t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t10;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)lbl_88B3D198;
    if ((ts4_word)t1 == 65535) {
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
        t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]);
        t4 = ts4_get_u32_off8_88426140((ts4_word)t3);
        ts4_find_entry_by_name_884278D0((ts4_word)t4, (ts4_word)(ts4_word)lbl_88040818, (ts4_word)(ts4_word)&LL.loc50[0]);
        t6 = LL.loc50[0];
        *(unsigned short *)lbl_88B3D198 = (unsigned short)t6;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
    t10 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t10) + 0) = (unsigned short)(*(unsigned short *)lbl_88B3D198);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804080C);
    t13 = ts4_get_u32_off0_88428A28((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t13) + 0) = (unsigned char)a1;
    return t13;
}

/* Swing_DLL.xex 0x8842C030: if_call_seq lbl_880E1DE4, u16@lbl_88B3D1AC, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off8_88426140, lbl_8804090C */
ts4_word ts4_if_call_seq_lbl_880E1DE4_8842C030(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[4]; } LL;
    unsigned short t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t10;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)lbl_88B3D1AC;
    if ((ts4_word)t1 == 65535) {
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
        t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]);
        t4 = ts4_get_u32_off8_88426140((ts4_word)t3);
        ts4_find_entry_by_name_884278D0((ts4_word)t4, (ts4_word)(ts4_word)lbl_8804090C, (ts4_word)(ts4_word)&LL.loc50[0]);
        t6 = LL.loc50[0];
        *(unsigned short *)lbl_88B3D1AC = (unsigned short)t6;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
    t10 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t10) + 0) = (unsigned short)(*(unsigned short *)lbl_88B3D1AC);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880408F8);
    t13 = ts4_get_u32_off0_88428A28((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t13) + 0) = (unsigned char)a1;
    return t13;
}

/* Swing_DLL.xex 0x8842D298: if_call_seq lbl_88040B78, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428B30, u16@lbl_88B3D1E8, ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480, u16@lbl_88B3D1E8 */
ts4_word ts4_if_call_seq_lbl_88040B78_8842D298(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040B78);
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    if (*(short *)lbl_88B3D1E8 == -1) {
        *(short *)lbl_88B3D1E8 = (short)ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480((ts4_word)(ts4_word)&loc50[0]);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], ts4_if_call_seq_u32_off4_88428AC8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88040B80)), (ts4_word)t6, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8842D320: if_call_seq lbl_88040B78, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428B30, u16@lbl_88B3D1EC, ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480, u16@lbl_88B3D1EC */
ts4_word ts4_if_call_seq_lbl_88040B78_8842D320(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040B78);
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    if (*(short *)lbl_88B3D1EC == -1) {
        *(short *)lbl_88B3D1EC = (short)ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480((ts4_word)(ts4_word)&loc50[0]);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], ts4_if_call_seq_u32_off4_88428AC8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88040B80)), (ts4_word)t6, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8842DAE0: if_call_seq lbl_88040B78, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428B30, u16@lbl_88B3D1F8, ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480, u16@lbl_88B3D1F8 */
ts4_word ts4_if_call_seq_lbl_88040B78_8842DAE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040B78);
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    if (*(short *)lbl_88B3D1F8 == -1) {
        *(short *)lbl_88B3D1F8 = (short)ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480((ts4_word)(ts4_word)&loc50[0]);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], ts4_if_call_seq_u32_off4_88428AC8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88040B80)), (ts4_word)t6, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8842DCA0: if_call_seq u32@0x4, lbl_8803FC80, fn_88431250, u8@0x0, u32@0x4, lbl_8803F9E8 */
static ts4_word ts4_if_call_seq_u32_off4_8842DCA0(ts4_word a0, ts4_word a1)
{
    ts4_word p10;
    ts4_word p13;
    ts4_word p16;
    struct { ts4_word loc50[1]; ts4_word loc54[1]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[2]; } LL;
    ts4_word t22;
    ts4_word t24;

    if (*(unsigned char *)((char *)(ts4_word)(fn_88431250((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803FC80)) + 0) != 0) {
        p16 = (ts4_word)(ts4_word)lbl_88040D18;
    } else {
        if (*(unsigned char *)((char *)(ts4_word)(fn_88431250((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803F9E8)) + 0) != 0) {
            p13 = (ts4_word)(ts4_word)lbl_88040D08;
        } else {
            if (*(unsigned char *)((char *)(ts4_word)(fn_88431250((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8803FCA0)) + 0) != 0) {
                p10 = (ts4_word)(ts4_word)lbl_88040CF8;
            } else {
                p10 = (ts4_word)(ts4_word)lbl_88040CE8;
            }
            p13 = (ts4_word)p10;
        }
        p16 = (ts4_word)p13;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1), (ts4_word)(ts4_word)lbl_880E1DE4);
    ts4_find_entry_by_name_884278D0(ts4_get_u32_off8_88426140(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0])), (ts4_word)p16, (ts4_word)(ts4_word)&LL.loc54[0]);
    t22 = LL.loc54[0];
    t24 = ts4_get_u32_off0_88428A18(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880E1DE4), (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t24) + 0) = (unsigned char)t22;
    return t24;
}

/* Swing_DLL.xex 0x88431598: call_seq lbl_88041544, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_u32_off4_88428B48, u32@0x0, ts4_call_seq_u32_off4_88428B48 */
ts4_word ts4_call_seq_lbl_88041544_88431598(ts4_word a0, ts4_word a1, ts4_word a2)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[2]; ts4_word loc70[4]; } LL;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041544);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041544);
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)(ts4_word)&LL.loc50[0]);
    LL.loc60[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)(ts4_word)&LL.loc50[0]);
    LL.loc60[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 4));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)(ts4_word)&LL.loc58[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
    LL.loc68[0] = (ts4_word)t8;
    t9 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)t8, (ts4_word)t7);
    LL.loc68[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 4));
    t11 = ts4_if_call_seq_lbl_8803D504_884314B0((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a2);
    return t11;
}

/* Swing_DLL.xex 0x88431650: if_call_seq lbl_8803D1C8, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428960 */
ts4_word ts4_if_call_seq_lbl_8803D1C8_88431650(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word p13;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803D1C8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803D1C8);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p13 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p11 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t7 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
            t8 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 0));
            p11 = (ts4_word)t8;
        }
        p13 = (ts4_word)p11;
    }
    return p13;
}

/* Swing_DLL.xex 0x88431BF0: call_seq lbl_88041AE8, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, fn_88431B10, lbl_88041AC8, ts4_if_call_seq_u32_off4_88428890 */
static ts4_word ts4_call_seq_lbl_88041AE8_88431BF0(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t6;
    ts4_word t7;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AE8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AE8);
    fn_88431B10((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AC8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AB0);
    t6 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)-1;
    t7 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)-1;
    return t7;
}

/* Swing_DLL.xex 0x88432FD0: if_call_seq lbl_88041FF8, ts4_if_call_seq_u32_off4_88428890, lbl_88041FEC, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0 */
ts4_word ts4_if_call_seq_lbl_88041FF8_88432FD0(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word p11;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t7;
    ts4_word t8;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041FF8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041FEC);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p11 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p9 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t7 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)0;
            t8 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(t8) + 0) = (ts4_word)0;
            p9 = (ts4_word)t8;
        }
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x88433330: if_call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, lbl_88042C0C, ts4_if_call_seq_u32_off4_88428890, lbl_88041554, ts4_if_call_seq_u32_off4_88428890 */
static ts4_word ts4_if_call_seq_lbl_8803CB5C_88433330(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[4];
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t9;
    unsigned char t10;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042C0C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041554);
    t4 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
    if ((ts4_word)t5 != 0) {
        t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t6) + 0) = (short)((*(short *)((char *)(ts4_word)(t6) + 0)) | 1);
    }
    t9 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t10 = *(unsigned char *)((char *)(ts4_word)(t9) + 0);
    p13 = (ts4_word)t9;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t11) + 0) = (short)((*(short *)((char *)(ts4_word)(t11) + 0)) | 2);
        p13 = (ts4_word)t11;
    }
    return p13;
}

/* Swing_DLL.xex 0x884334B0: call_seq lbl_8804190C, ts4_if_call_seq_u32_off4_88428890, lbl_88042C5C, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289B8, ts4_get_u32_off0_884289B8 */
ts4_word ts4_call_seq_lbl_8804190C_884334B0(ts4_word a0, ts4_word a1)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; } LL;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804190C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042C5C);
    t3 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t4) + 0) = (*(float *)((char *)(ts4_word)(t3) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880418E8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042C44);
    t8 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    t9 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t9) + 0) = (*(float *)((char *)(ts4_word)(t8) + 0));
    return t9;
}

/* Swing_DLL.xex 0x88434020: call_seq lbl_88042DB4, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_fn_88428B48_88433F90, lbl_88042DA4, ts4_if_call_seq_u32_off4_88428890 */
ts4_word ts4_call_seq_lbl_88042DB4_88434020(ts4_word a0, ts4_word a1, ts4_word a2)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; } LL;
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042DB4);
    ts4_call_seq_fn_88428B48_88433F90(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042DB4), (ts4_word)t1, (ts4_word)a2);
    t4 = ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88042DA4);
    return ts4_call_seq_fn_88428B48_88433F90(ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88042DA4), (ts4_word)t4, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884342A0: call_seq lbl_88041AA4, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, fn_88426178, ts4_get_u32_off0_88428980 */
static ts4_word ts4_call_seq_lbl_88041AA4_884342A0(ts4_word a0, ts4_word a1)
{
    struct { ts4_word loc50[2]; ts4_word loc58[4]; } LL;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AA4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AA4);
    t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc50[0]);
    t4 = fn_88426178((ts4_word)t3);
    t5 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&LL.loc50[0]);
    t7 = ts4_tailcall_memcpy_88421450(ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&LL.loc58[0]), (ts4_word)t5, (ts4_word)t4);
    return t7;
}

/* Swing_DLL.xex 0x88434EC8: call_seq lbl_88048144, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428988, ts4_get_u32_off0_88428988, u32@0x0 */
ts4_word ts4_call_seq_lbl_88048144_88434EC8(ts4_word a0, ts4_word a1)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; } LL;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88048144);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88048144);
    t3 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804812C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8804812C);
    t8 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 0);
    t10 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t10) + 0) = (unsigned short)t9;
    return t10;
}

/* Swing_DLL.xex 0x884350B0: get ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_u32_off4_88428B48, u32@0x4, ts4_call_seq_u32_off4_88428B48, u32@0x0 */
static ts4_word ts4_get_ts4_if_call_seq_u32_off4_88428890_884350B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc70[2];
    ts4_word loc78[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a3);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)a3);
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc58[0]);
    loc68[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 4));
    t9 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0]);
    loc68[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0));
    t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(a4))((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)a2);
    return t11;
}

/* Swing_DLL.xex 0x884352E8: if_call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_884289F8, ts4_index_u16_array_at_field0_884289F8, u16@0x0 */
static ts4_word ts4_if_call_seq_lbl_8803CB5C_884352E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    t3 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t4 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    *(short *)((char *)(ts4_word)(t4) + 0) = (short)(*(short *)((char *)(ts4_word)(t3) + 0));
    p9 = (ts4_word)t4;
    if ((ts4_word)(a2 & 0xff) != 0) {
        t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        *(short *)((char *)(ts4_word)(t6) + 0) = (short)((*(short *)((char *)(ts4_word)(t6) + 0)) | 2048);
        p9 = (ts4_word)t6;
    }
    return p9;
}

/* Swing_DLL.xex 0x88435638: if_addr lbl_88040148, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428960 */
ts4_word ts4_if_addr_lbl_88040148_88435638(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p19;
    ts4_word p21;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; ts4_word loc70[4]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t15;
    ts4_word t18;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88040148);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040148);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p21 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p19 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            fn_88435838((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)(ts4_word)lbl_88B3D3C8);
            t8 = ts4_get_u32_off0_88428998((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
            t10 = fn_885E7AD8((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t8) + 0)), (ts4_word)0);
            if ((ts4_word)t10 != 0) {
                t11 = fn_884214A8((ts4_word)t10);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 12))))((ts4_word)a2, (ts4_word)t11);
                t15 = ts4_get_u32_off0_88428998((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)t11;
            }
            t18 = fn_885E7BA8((ts4_word)(ts4_word)&LL.loc70[0]);
            p19 = (ts4_word)t18;
        }
        p21 = (ts4_word)p19;
    }
    return p21;
}

/* Swing_DLL.xex 0x88435F68: call_seq lbl_8804911C, ts4_if_call_seq_u32_off4_88428890, lbl_8804910C, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289B8, ts4_get_u32_off0_884289B8 */
ts4_word ts4_call_seq_lbl_8804911C_88435F68(ts4_word a0, ts4_word a1)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[4]; } LL;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804911C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8804910C);
    t3 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t4) + 0) = (*(float *)((char *)(ts4_word)(t3) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880490F4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880490E4);
    t8 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    t9 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t9) + 0) = (*(float *)((char *)(ts4_word)(t8) + 0));
    return t9;
}

/* Swing_DLL.xex 0x88436500: call_seq lbl_88041928, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off4_88426130, ts4_get_u32_off0_88428980 */
static ts4_word ts4_call_seq_lbl_88041928_88436500(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc68[2];
    ts4_word loc60[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041928);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928);
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
    t9 = ts4_call_seq_lbl_88049700_88436488((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc60[0]);
    return t9;
}

/* Swing_DLL.xex 0x884365A0: call_seq lbl_88042C70, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off4_88426130, ts4_get_u32_off0_88428980 */
static ts4_word ts4_call_seq_lbl_88042C70_884365A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc68[2];
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
    t9 = fn_88436500((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc60[0]);
    return t9;
}

/* Swing_DLL.xex 0x884369C8: call_seq lbl_88049804, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, fn_88436868, fn_88436D30, lbl_88041928 */
ts4_word ts4_call_seq_lbl_88049804_884369C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[4]; } LL;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88049804);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88049804);
    fn_88436D30((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)(ts4_word)fn_88436868, (ts4_word)a2);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041928);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928);
    t6 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc50[0]);
    t7 = ts4_get_u32_off4_88426130((ts4_word)t6);
    LL.loc68[1] = (ts4_word)t7;
    t8 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&LL.loc50[0]);
    LL.loc68[0] = (ts4_word)t8;
    t9 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]);
    t10 = ts4_get_u32_off4_88426130((ts4_word)t9);
    LL.loc60[1] = (ts4_word)t10;
    t11 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&LL.loc58[0]);
    LL.loc60[0] = (ts4_word)t11;
    t12 = ts4_call_seq_lbl_88049700_88436488((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    return t12;
}

/* Swing_DLL.xex 0x8843B3A0: if_call_seq u16@0x4, u16@0x6, u16@0x6, u32@0x38, u32@0x34, fn_8841C678 */
ts4_word ts4_if_call_seq_u16_off4_8843B3A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    short t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    int t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(short *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 != 0) {
        t3 = ((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
        *(short *)((char *)(ts4_word)(a1) + 6) = (short)t3;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t7 = (a0 + 48);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    p10 = (ts4_word)a0;
    if ((int)t8 == (int)(t6 & 0x3fffffff)) {
        t9 = fn_8841C678((ts4_word)t7, (ts4_word)4);
        p10 = (ts4_word)t9;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
    *(ts4_word *)((char *)(ts4_word)((t11 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t7) + 0))) = (ts4_word)a1;
    t14 = ((*(ts4_word *)((char *)(ts4_word)(t7) + 4)) + 1);
    *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)t14;
    return p10;
}

/* Swing_DLL.xex 0x8843CAF8: if_get u32@0x1c, lbl_8808029C, lbl_88080278, u32@0x0, u32@0x10, u16@0x4 */
ts4_word ts4_if_get_u32_off1c_8843CAF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p17;
    ts4_word p18;
    ts4_word t1;
    short t2;
    short t4;
    ts4_word t10;
    short t11;
    short t13;
    ts4_word t16;

    (void)a1;
    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808029C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88080278;
    t2 = *(short *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 != 0) {
        t4 = (short)((*(short *)((char *)(ts4_word)(t1) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t1) + 6) = t4;
        if (t4 == 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        }
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t11 = *(short *)((char *)(ts4_word)(t10) + 4);
    p18 = (ts4_word)t10;
    if ((ts4_word)t11 != 0) {
        t13 = (short)((*(short *)((char *)(ts4_word)(t10) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t10) + 6) = t13;
        p17 = (ts4_word)t10;
        if (t13 == 0) {
            t16 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 0))))((ts4_word)t10, (ts4_word)1);
            p17 = (ts4_word)t16;
        }
        p18 = (ts4_word)p17;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_8807FF50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p18;
}

/* Swing_DLL.xex 0x8844BB30: if_get u32@0x18, lbl_88081250, lbl_8808122C, u32@0x0, u32@0x10, u16@0x4 */
ts4_word ts4_if_get_u32_off18_8844BB30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    short t2;
    short t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081250;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_8808122C;
    t2 = *(short *)((char *)(ts4_word)(t1) + 4);
    p9 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t4 = (short)((*(short *)((char *)(ts4_word)(t1) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t1) + 6) = t4;
        p8 = (ts4_word)t1;
        if (t4 == 0) {
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
            p8 = (ts4_word)t7;
        }
        p9 = (ts4_word)p8;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_8807FF50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p9;
}

/* Swing_DLL.xex 0x88454800: if_call_seq lbl_88082618, lbl_8808260C, ts4_trace2, lbl_8808257C, fn_88466E80, lbl_88081F8C */
void ts4_if_call_seq_lbl_88082618_88454800(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    struct { ts4_word loc50[2]; ts4_word loc58[6]; } LL;
    signed char t3;

    ts4_trace2((ts4_word)(ts4_word)lbl_88082618, (ts4_word)(ts4_word)lbl_8808260C);
    *(signed char *)((char *)LL.loc50 + 4) = (signed char)0;
    LL.loc50[0] = (ts4_word)(ts4_word)lbl_8808257C;
    fn_88466E80((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&LL.loc50[0]);
    t3 = *(signed char *)((char *)LL.loc50 + 4);
    if ((ts4_word)t3 != 0) {
        ts4_trace1((ts4_word)(ts4_word)lbl_88082600);
        LL.loc58[2] = (ts4_word)a3;
        *(signed char *)((char *)LL.loc58 + 4) = (signed char)0;
        LL.loc58[0] = (ts4_word)(ts4_word)lbl_88081FB0;
        fn_88461C60((ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)(ts4_word)&LL.loc58[0]);
        LL.loc58[0] = (ts4_word)(ts4_word)lbl_88081F8C;
    }
    LL.loc50[0] = (ts4_word)(ts4_word)lbl_88081F8C;
    ts4_trace1((ts4_word)(ts4_word)lbl_88007998);
    return;
}

/* Swing_DLL.xex 0x884684A8: if_get u32@0x10, lbl_8808333C, u32@0x0, u16@0x4, u16@0x6, u16@0x6 */
ts4_word ts4_if_get_u32_off10_884684A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word p15;
    ts4_word p21;
    int t1;
    short t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t12;
    ts4_word t14;
    ts4_word t16;
    ts4_word t18;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808333C;
    p9 = (ts4_word)t1;
    if ((int)t1 != 0 && (ts4_word)(*(short *)((char *)(ts4_word)(t1) + 4)) != 0) {
        t4 = (short)((*(short *)((char *)(ts4_word)(t1) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t1) + 6) = t4;
        p8 = (ts4_word)t1;
        if (t4 == 0) {
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
            p8 = (ts4_word)t7;
        }
        p9 = (ts4_word)p8;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    p15 = (ts4_word)p9;
    if ((int)(t10 & 0x80000000) == 0) {
        t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t14 = fn_8841A590((ts4_word)t12, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116)), (ts4_word)(t10 << 4), (ts4_word)23);
        p15 = (ts4_word)t14;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    p21 = (ts4_word)p15;
    if ((int)(t16 & 0x80000000) == 0) {
        t18 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t20 = fn_8841A590((ts4_word)t18, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)(t16 << 3), (ts4_word)23);
        p21 = (ts4_word)t20;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p21;
}

/* Swing_DLL.xex 0x88475D88: if_get u32@0x8, u32@0x84, u16@0x4, u16@0x6, u16@0x6, u32@0x0 */
ts4_word ts4_if_get_u32_off8_88475D88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word loc50[2];
    int t1;
    ts4_word t11;
    short t3;
    short t5;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        loc50[1] = (ts4_word)a0;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)30;
        t11 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        return t11;
    }
    t3 = *(short *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t3 != 0) {
        t5 = (short)((*(short *)((char *)(ts4_word)(a0) + 6)) + -1);
        *(short *)((char *)(ts4_word)(a0) + 6) = t5;
        p9 = (ts4_word)a0;
        if (t5 == 0) {
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x884761E0: if_get u16@0x4, u16@0x6, u16@0x6, u16@0x4, u16@0x6, u16@0x6 */
ts4_word ts4_if_get_u16_off4_884761E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p13;
    ts4_word p14;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    short t9;
    ts4_word t12;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0 && (ts4_word)(*(short *)((char *)(ts4_word)(a2) + 4)) != 0) {
        t3 = ((*(short *)((char *)(ts4_word)(a2) + 6)) + 1);
        *(short *)((char *)(ts4_word)(a2) + 6) = (short)t3;
    }
    t5 = (a1 + 56);
    t6 = *(ts4_word *)((char *)(ts4_word)((t5 << 2)) + a0);
    p14 = (ts4_word)t6;
    if ((ts4_word)t6 != 0 && (ts4_word)(*(short *)((char *)(ts4_word)(t6) + 4)) != 0) {
        t9 = (short)((*(short *)((char *)(ts4_word)(t6) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t6) + 6) = t9;
        p13 = (ts4_word)t6;
        if (t9 == 0) {
            t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 0))))((ts4_word)t6, (ts4_word)1);
            p13 = (ts4_word)t12;
        }
        p14 = (ts4_word)p13;
    }
    *(ts4_word *)((char *)(ts4_word)((t5 << 2)) + a0) = (ts4_word)a2;
    return p14;
}

/* Swing_DLL.xex 0x8847EE48: if_call_seq u16@0x4, u16@0x4, u16@0x6, u16@0x6, u32@0x1c, u32@0x18 */
ts4_word ts4_if_call_seq_u16_off4_8847EE48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p17;
    short t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    int t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p17 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = *(short *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t2 != 0) {
            t4 = ((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
            *(short *)((char *)(ts4_word)(a1) + 6) = (short)t4;
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t8 = (a0 + 20);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        p11 = (ts4_word)a0;
        if ((int)t9 == (int)(t7 & 0x3fffffff)) {
            t10 = fn_8841C678((ts4_word)t8, (ts4_word)4);
            p11 = (ts4_word)t10;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        *(ts4_word *)((char *)(ts4_word)((t12 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t8) + 0))) = (ts4_word)a1;
        t15 = ((*(ts4_word *)((char *)(ts4_word)(t8) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)t15;
        p17 = (ts4_word)p11;
    }
    return p17;
}

/* Swing_DLL.xex 0x8847EED8: if_call_seq u16@0x4, u16@0x4, u16@0x6, u16@0x6, u32@0x28, u32@0x24 */
ts4_word ts4_if_call_seq_u16_off4_8847EED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p17;
    short t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    int t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p17 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = *(short *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t2 != 0) {
            t4 = ((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
            *(short *)((char *)(ts4_word)(a1) + 6) = (short)t4;
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        t8 = (a0 + 32);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        p11 = (ts4_word)a0;
        if ((int)t9 == (int)(t7 & 0x3fffffff)) {
            t10 = fn_8841C678((ts4_word)t8, (ts4_word)4);
            p11 = (ts4_word)t10;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        *(ts4_word *)((char *)(ts4_word)((t12 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t8) + 0))) = (ts4_word)a1;
        t15 = ((*(ts4_word *)((char *)(ts4_word)(t8) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)t15;
        p17 = (ts4_word)p11;
    }
    return p17;
}

/* Swing_DLL.xex 0x884A73A0: if_call_seq u16@0x4, u16@0x4, u16@0x6, u16@0x6, u32@0x4c, u32@0x48 */
ts4_word ts4_if_call_seq_u16_off4_884A73A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p17;
    short t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    int t9;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p17 = (ts4_word)a0;
    if ((ts4_word)a1 != 0) {
        t2 = *(short *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t2 != 0) {
            t4 = ((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
            *(short *)((char *)(ts4_word)(a1) + 6) = (short)t4;
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        t8 = (a0 + 68);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        p11 = (ts4_word)a0;
        if ((int)t9 == (int)(t7 & 0x3fffffff)) {
            t10 = fn_8841C678((ts4_word)t8, (ts4_word)4);
            p11 = (ts4_word)t10;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
        *(ts4_word *)((char *)(ts4_word)((t12 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t8) + 0))) = (ts4_word)a1;
        t15 = ((*(ts4_word *)((char *)(ts4_word)(t8) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t8) + 4) = (ts4_word)t15;
        p17 = (ts4_word)p11;
    }
    return p17;
}

/* Swing_DLL.xex 0x884B7900: call_seq lbl_88D25C34, ts4_get_u32_off0_8841EAC8, ts4_if_call_seq_u32_off0_884CCBB8, lbl_88D26F54, fn_884B76C8 */
static ts4_word ts4_call_seq_lbl_88D25C34_884B7900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    struct { ts4_word loc50[4]; ts4_word loc60[6]; } LL;

    ts4_if_call_seq_u32_off0_884CCBB8((ts4_word)(ts4_word)&LL.loc60[0], ts4_get_u32_off0_8841EAC8((ts4_word)(ts4_word)lbl_88D25C34), (ts4_word)a1, (ts4_word)(ts4_word)lbl_88D25C34);
    LL.loc50[1] = (ts4_word)1;
    LL.loc50[0] = (ts4_word)(ts4_word)&LL.loc60[0];
    fn_884B76C8((ts4_word)a0, (ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)lbl_88D26F54, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)1);
    return a0;
}

/* Swing_DLL.xex 0x884C44B0: if_get u32@0x0, u32@lbl_88CACF08, u32@0x0, KeTlsGetValue, fn_8841A510, u16@0x4 */
ts4_word ts4_if_get_u32_off0_884C44B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;
    ts4_word t12;
    ts4_word t15;
    ts4_word t16;
    short t17;
    ts4_word t19;
    ts4_word t20;
    short t21;
    ts4_word t23;
    ts4_word t25;
    short t26;
    ts4_word t28;
    ts4_word t30;
    short t31;
    ts4_word t33;
    ts4_word t35;
    short t36;
    ts4_word t38;
    ts4_word t40;
    short t41;
    ts4_word t43;
    ts4_word t45;
    short t46;
    ts4_word t48;
    ts4_word t50;
    short t51;
    ts4_word t53;
    ts4_word t55;
    short t56;
    ts4_word t58;
    ts4_word t60;
    ts4_word t63;
    short t64;
    ts4_word t66;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)lbl_88CACF08;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = KeTlsGetValue((ts4_word)t2);
    t5 = fn_8841A510((ts4_word)t4, (ts4_word)212, (ts4_word)11);
    *(short *)((char *)(ts4_word)(t5) + 4) = (short)212;
    t6 = fn_884C25E8((ts4_word)t5, (ts4_word)t3);
    fn_884C4688((ts4_word)t6, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(t6) + 24) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t6) + 12) = (ts4_word)0;
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 24))))((ts4_word)t8, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(t6) + 60) = (ts4_word)t11;
    *(unsigned char *)((char *)(ts4_word)(t11) + 8) = (unsigned char)1;
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 12))))((ts4_word)t12);
    t16 = *(ts4_word *)((char *)(ts4_word)(t6) + 28);
    *(ts4_word *)((char *)(ts4_word)(t6) + 156) = (ts4_word)t15;
    t17 = *(short *)((char *)(ts4_word)(t16) + 4);
    if ((ts4_word)t17 != 0) {
        t19 = ((*(short *)((char *)(ts4_word)(t16) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t16) + 6) = (short)t19;
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(t6) + 32);
    t21 = *(short *)((char *)(ts4_word)(t20) + 4);
    if ((ts4_word)t21 != 0) {
        t23 = ((*(short *)((char *)(ts4_word)(t20) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t20) + 6) = (short)t23;
    }
    t25 = *(ts4_word *)((char *)(ts4_word)(t6) + 36);
    t26 = *(short *)((char *)(ts4_word)(t25) + 4);
    if ((ts4_word)t26 != 0) {
        t28 = ((*(short *)((char *)(ts4_word)(t25) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t25) + 6) = (short)t28;
    }
    t30 = *(ts4_word *)((char *)(ts4_word)(t6) + 40);
    t31 = *(short *)((char *)(ts4_word)(t30) + 4);
    if ((ts4_word)t31 != 0) {
        t33 = ((*(short *)((char *)(ts4_word)(t30) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t30) + 6) = (short)t33;
    }
    t35 = *(ts4_word *)((char *)(ts4_word)(t6) + 44);
    t36 = *(short *)((char *)(ts4_word)(t35) + 4);
    if ((ts4_word)t36 != 0) {
        t38 = ((*(short *)((char *)(ts4_word)(t35) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t35) + 6) = (short)t38;
    }
    t40 = *(ts4_word *)((char *)(ts4_word)(t6) + 48);
    t41 = *(short *)((char *)(ts4_word)(t40) + 4);
    if ((ts4_word)t41 != 0) {
        t43 = ((*(short *)((char *)(ts4_word)(t40) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t40) + 6) = (short)t43;
    }
    t45 = *(ts4_word *)((char *)(ts4_word)(t6) + 52);
    t46 = *(short *)((char *)(ts4_word)(t45) + 4);
    if ((ts4_word)t46 != 0) {
        t48 = ((*(short *)((char *)(ts4_word)(t45) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t45) + 6) = (short)t48;
    }
    t50 = *(ts4_word *)((char *)(ts4_word)(t6) + 56);
    t51 = *(short *)((char *)(ts4_word)(t50) + 4);
    if ((ts4_word)t51 != 0) {
        t53 = ((*(short *)((char *)(ts4_word)(t50) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t50) + 6) = (short)t53;
    }
    t55 = *(ts4_word *)((char *)(ts4_word)(t6) + 68);
    t56 = *(short *)((char *)(ts4_word)(t55) + 4);
    if ((ts4_word)t56 != 0) {
        t58 = ((*(short *)((char *)(ts4_word)(t55) + 6)) + 1);
        *(short *)((char *)(ts4_word)(t55) + 6) = (short)t58;
    }
    t60 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t60 != 0) {
        t63 = *(ts4_word *)((char *)(ts4_word)(t6) + 64);
        t64 = *(short *)((char *)(ts4_word)(t63) + 4);
        if ((ts4_word)t64 != 0) {
            t66 = ((*(short *)((char *)(ts4_word)(t63) + 6)) + 1);
            *(short *)((char *)(ts4_word)(t63) + 6) = (short)t66;
            return t6;
        }
        return t6;
    }
    return t6;
}

/* Swing_DLL.xex 0x884C5468: if_call_seq ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428960, u8@0x0, ts4_get_u32_off0_88428960, u8@0x0 */
ts4_word ts4_if_call_seq_ts4_if_call_seq_u32_off4_88428890_884C5468(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p12;
    ts4_word p15;
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; } LL;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    unsigned char t6;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)a1);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a2, (ts4_word)a3);
    t3 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc60[0]);
    t4 = *(unsigned char *)((char *)(ts4_word)(t3) + 0);
    p15 = (ts4_word)t3;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_get_u32_off0_88428960((ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)(ts4_word)&LL.loc58[0]);
        t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 0);
        p12 = (ts4_word)t5;
        if ((ts4_word)t6 != 0) {
            t8 = fn_88426178(ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]));
            t9 = ts4_get_u32_off0_88428978((ts4_word)(ts4_word)&LL.loc60[0]);
            p12 = ts4_tailcall_memcpy_88421450(ts4_get_u32_off0_88428978((ts4_word)(ts4_word)&LL.loc58[0]), (ts4_word)t9, (ts4_word)t8);
        }
        p15 = (ts4_word)p12;
    }
    return p15;
}

/* Swing_DLL.xex 0x884C6B58: if_get u32@0x0, u32@0x24, vcall, lbl_8808BFAC, fn_884210E8, u32@0x0 */
static ts4_word ts4_if_get_u32_off0_884C6B58(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t7;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
    if ((int)fn_884210E8((ts4_word)t3, (ts4_word)(ts4_word)lbl_8808BFAC) != 0) {
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
        if ((int)*(ts4_word *)((char *)(ts4_word)(t7) + 4) != 0) {
            if ((int)fn_884C6A10((ts4_word)t7, ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0), (ts4_word)a1, (ts4_word)t3, (ts4_word)(ts4_word)lbl_8808BFAC) == 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_8808BFAC);
                return 0;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x884CB388: if_get u32@0x78, lbl_8808C29C, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off78_884CB388(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;
    short t10;
    short t12;
    ts4_word t18;
    ts4_word t20;
    ts4_word t24;
    ts4_word t26;
    ts4_word t30;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C29C;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t6 != 0) {
        fn_884C4FA8((ts4_word)t6, (ts4_word)1);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t10 = *(short *)((char *)(ts4_word)(t9) + 4);
    if ((ts4_word)t10 != 0) {
        t12 = (short)((*(short *)((char *)(ts4_word)(t9) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t9) + 6) = t12;
        if (t12 == 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 0))))((ts4_word)t9, (ts4_word)1);
        }
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((int)(t18 & 0x80000000) == 0) {
        t20 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t20, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)), (ts4_word)(t18 << 2), (ts4_word)23);
    }
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)(t24 & 0x80000000) == 0) {
        t26 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t26, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)(t24 << 2), (ts4_word)23);
    }
    t30 = ts4_call_seq_u32_off14_884D3EE0((ts4_word)a0);
    return t30;
}

/* Swing_DLL.xex 0x884D4C48: loop_call_seq fn_885E75E0, fn_885E76A0, ts4_get_u32_off8_885E7620, ts4_get_u32_off8_885E7640, fn_885E76C0, fn_885E76C0 */
static ts4_word ts4_loop_call_seq_fn_885E75E0_884D4C48(ts4_word a0, ts4_word a1)
{
    ts4_word p14;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    signed char t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    signed char t11;

    t1 = fn_885E75E0((ts4_word)a1);
    t2 = fn_885E76A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
    t3 = *(signed char *)((char *)loc50 + 0);
    p14 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t4 = (a0 + 44);
        t5 = (a0 + 60);
        do {
            t6 = ts4_get_u32_off8_885E7620((ts4_word)a1, (ts4_word)t1);
            t7 = ts4_get_u32_off8_885E7640((ts4_word)a1, (ts4_word)t1);
            fn_885E76C0((ts4_word)t4, (ts4_word)t6, (ts4_word)t7);
            fn_885E76C0((ts4_word)t5, (ts4_word)t7, (ts4_word)t6);
            t10 = fn_885E76A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
            t11 = *(signed char *)((char *)loc50 + 0);
        } while ((ts4_word)t11 != 0);
        p14 = (ts4_word)t10;
    }
    return p14;
}

/* Swing_DLL.xex 0x884D63A0: if_get u32@0x44, lbl_8808C8B4, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off44_884D63A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t6;
    short t7;
    short t9;
    ts4_word t15;
    ts4_word t17;
    ts4_word t21;
    ts4_word t23;
    ts4_word t25;
    ts4_word t29;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C8B4;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t7 = *(short *)((char *)(ts4_word)(t6) + 4);
    if ((ts4_word)t7 != 0) {
        t9 = (short)((*(short *)((char *)(ts4_word)(t6) + 6)) + -1);
        *(short *)((char *)(ts4_word)(t6) + 6) = t9;
        if (t9 == 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 0))))((ts4_word)t6, (ts4_word)1);
        }
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((int)(t15 & 0x80000000) == 0) {
        t17 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t17, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)), (ts4_word)(t15 << 3), (ts4_word)23);
    }
    t21 = (a0 + 40);
    fn_885E7BA8((ts4_word)t21);
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)(t23 & 0x80000000) == 0) {
        t25 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t25, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)(t23 << 2), (ts4_word)23);
    }
    t29 = ts4_call_seq_u32_off14_884D3EE0((ts4_word)a0);
    return t29;
}

/* Swing_DLL.xex 0x884D76D0: if_addr ts4_delete_member_0_884D5F78, ts4_set_u32_off8_885ED1E8, u32@0x0, u32@0x14, vcall, ts4_loop_call_seq_fn_885ED260_884D7550 */
ts4_word ts4_if_addr_fn_884D5F78_884D76D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    struct { ts4_word loc50[1]; ts4_word loc54[5]; } LL;
    int t4;
    ts4_word t9;

    LL.loc50[0] = (ts4_word)(ts4_word)ts4_delete_member_0_884D5F78;
    ts4_set_u32_off8_885ED1E8((ts4_word)(ts4_word)&LL.loc54[0], (ts4_word)4);
    t4 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&LL.loc50[0], (ts4_word)a3);
    if ((int)t4 == 0) {
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
        ts4_loop_call_seq_fn_885ED260_884D7550((ts4_word)(ts4_word)&LL.loc50[0]);
        ts4_noop_885ED200((ts4_word)(ts4_word)&LL.loc54[0]);
        return t9;
    }
    ts4_loop_call_seq_fn_885ED260_884D7550((ts4_word)(ts4_word)&LL.loc50[0]);
    ts4_noop_885ED200((ts4_word)(ts4_word)&LL.loc54[0]);
    return t4;
}

/* Swing_DLL.xex 0x884DD2A8: if_call_seq u32@0x8, lbl_8808CE18, u16@0x6, u32@0x0, u16@0x4, u32@lbl_88CACF08 */
ts4_word ts4_if_call_seq_u32_off8_884DD2A8(ts4_word a0, ts4_word a1)
{
    short t6;
    ts4_word t8;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(short *)((char *)(ts4_word)(a0) + 6) = (short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808CE18;
    if ((ts4_word)a1 != 0) {
        t6 = *(short *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t6 != 0) {
            t8 = ((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
            *(short *)((char *)(ts4_word)(a1) + 6) = (short)t8;
            return a0;
        }
        return a0;
    }
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t4 = fn_8841A510((ts4_word)t3, (ts4_word)32, (ts4_word)6);
    *(short *)((char *)(ts4_word)(t4) + 4) = (short)32;
    t5 = fn_884DB768((ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    return a0;
}

/* Swing_DLL.xex 0x884EB310: if_get u32@0x8, fn_885EC530, u32@0x8, ts4_get_u32_off8_885EC668, u8@0x0, u32@-0x4 */
ts4_word ts4_if_get_u32_off8_884EB310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p22;
    ts4_word p23;
    ts4_word p24;
    struct { ts4_word a[1]; ts4_word b[1]; } LL;
    ts4_word t15;
    unsigned char t16;
    ts4_word t18;
    ts4_word t19;
    ts4_word t21;
    ts4_word t4;
    unsigned char t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0xff) != 194) {
        p23 = (ts4_word)a0;
        if ((int)(a1 & 0xff) == 195) {
            fn_885EC530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)((ts4_word)LL.b), (ts4_word)4, (ts4_word)1);
            t15 = ts4_get_u32_off8_885EC668((ts4_word)(ts4_word)&LL.a[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            t16 = *(unsigned char *)((char *)(ts4_word)(t15) + 0);
            p22 = (ts4_word)t15;
            if ((ts4_word)t16 != 0) {
                t18 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + -4))) + 24);
                t19 = (a0 + -4);
                t21 = ((ts4_word (*)(ts4_word, ts4_word))(t18))((ts4_word)t19, (ts4_word)(*(ts4_word *)((char *)LL.b)));
                p22 = (ts4_word)t21;
            }
            p23 = (ts4_word)p22;
        }
        p24 = (ts4_word)p23;
    } else {
        fn_885EC530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)((ts4_word)LL.b), (ts4_word)4, (ts4_word)1);
        t4 = ts4_get_u32_off8_885EC668((ts4_word)((ts4_word)LL.a + 1), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
        t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
        p11 = (ts4_word)t4;
        if ((ts4_word)t5 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + -4))) + 20);
            t8 = (a0 + -4);
            t10 = ((ts4_word (*)(ts4_word, ts4_word))(t7))((ts4_word)t8, (ts4_word)(*(ts4_word *)((char *)LL.b)));
            p11 = (ts4_word)t10;
        }
        p24 = (ts4_word)p11;
    }
    return p24;
}
