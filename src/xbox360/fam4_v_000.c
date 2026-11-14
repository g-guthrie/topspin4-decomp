/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset.
   FAM4 variants: void returns, repeated member reads (MSVC turns the
   re-read of a tested pointer into `clrrwi rX,rY,0`), the inlined
   reference-counted string release of fam4_refstr.h. */
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

extern char fn_886182D0[];
extern char fn_8861D6A8[];
extern char lbl_88001A20[];
extern char lbl_88001B14[];
extern char lbl_8802E890[];
extern char lbl_88045824[];
extern char lbl_880876A0[];
extern char lbl_880897EC[];
extern char lbl_880C13B8[];
extern char lbl_880D3A48[];
extern char lbl_880D3B5C[];
extern char lbl_880D6B70[];
extern char lbl_880D71E0[];
extern char lbl_880D71EC[];
extern char lbl_880DCF20[];
extern char lbl_880F5230[];
extern char lbl_880F5250[];
extern char lbl_880F526C[];
extern char lbl_880F528C[];
extern char lbl_880F52A8[];
extern char lbl_880F52C8[];
extern char lbl_880F52E4[];
extern char lbl_880F5308[];
extern char lbl_880F5334[];
extern char lbl_880F533C[];
extern char lbl_880F5348[];
extern char lbl_880F5354[];
extern char lbl_880F5360[];
extern char lbl_880F5370[];
extern char lbl_880F537C[];
extern char lbl_880F538C[];
extern char lbl_880F7C94[];
extern char lbl_880F8C1C[];
extern char lbl_8814B440[];
extern char lbl_88B3302C[];
extern char lbl_88C74998[];
extern char lbl_88C78998[];
extern char lbl_88C7C998[];
extern char lbl_88C82998[];
extern char lbl_88C86AA0[];
extern char lbl_88CAD05C[];
extern char lbl_88CAD32C[];
extern char lbl_88CAD568[];
extern char lbl_88CAD56C[];
extern char lbl_88D24530[];
extern char lbl_88D4597C[];
extern char lbl_88D45980[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A70[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B2C[];
extern char lbl_88D45B38[];
extern char ts4_call_88613268_88618368[];
extern char ts4_forward_88618388[];
extern char ts4_if_get_u8_off8_886171D8[];
extern char ts4_noop_88605E88[];
ts4_word fn_88150600();
ts4_word fn_881608E8();
ts4_word fn_88162BB8();
ts4_word fn_88169350();
ts4_word fn_8816C930();
void ts4_loop_call_seq_u32_offc_8817F860();
ts4_word fn_881898E8();
float fn_881899D8(ts4_word, ts4_word, float);
ts4_word fn_8818A530();
ts4_word fn_88197408();
ts4_word fn_881974B0();
ts4_word fn_881992A8();
ts4_word ts4_small_string256_from_cstr_881A5020();
ts4_word fn_881B2AC8();
ts4_word fn_881B9148();
ts4_word fn_881C5950();
ts4_word fn_881C8BD0();
ts4_word fn_881E1D70();
ts4_word fn_881E2DA0();
ts4_word fn_881E2ED0();
ts4_word fn_881F0608();
ts4_word fn_881F25F0();
ts4_word fn_881F26C0();
ts4_word fn_88201118();
ts4_word fn_88214448();
ts4_word fn_8821FA18();
ts4_word fn_88222AF0();
ts4_word fn_8822A4A0();
ts4_word fn_8822CA90();
ts4_word fn_8826D010();
ts4_word fn_882736E8();
ts4_word fn_88286F38();
ts4_word fn_882882A0();
ts4_word fn_882D22B0();
ts4_word fn_882DD300();
ts4_word fn_88315F10();
ts4_word fn_8841C678();
ts4_word ts4_chunk_elem24_8841ED08();
ts4_word fn_8841ED80();
ts4_word fn_8841EF38();
ts4_word fn_884210E8();
ts4_word fn_884223A0();
ts4_word fn_88423660();
ts4_word fn_88423788();
ts4_word fn_88426FA0();
ts4_word fn_88470870();
ts4_word fn_8847FA78();
ts4_word fn_8847FBE8();
ts4_word fn_8847FC28();
ts4_word fn_8848E420();
ts4_word fn_884BE3E0(ts4_word, ts4_word, ts4_word, float, ts4_word, ts4_word);
ts4_word fn_884E0220();
ts4_word fn_884E05F0();
ts4_word fn_88562DC0();
ts4_word fn_885651F8();
ts4_word fn_8857B6D8();
ts4_word fn_8857C820();
ts4_word fn_885AC6C8();
ts4_word fn_885C18C8();
ts4_word fn_885C2378();
ts4_word fn_885C8B20();
ts4_word fn_88608590();
ts4_word fn_8860B060();
ts4_word fn_8860D360();
ts4_word fn_8860DBC8();
ts4_word fn_8860EBE0();
ts4_word fn_88612A60();
ts4_word fn_88612D60();
ts4_word ts4_if_call_seq_fn_881F04B8_886131F0();
ts4_word fn_88613268();
ts4_word fn_88614770();
ts4_word fn_886176F0();
ts4_word fn_886180E0();
ts4_word fn_88618998();
ts4_word fn_88627EC0();
ts4_word fn_8862AAC0();
ts4_word fn_88639480();
ts4_word ts4_get_fn_8864F6E8_88650C70();
ts4_word fn_8865C578();
ts4_word fn_8866DD78();
ts4_word fn_8866F028();
ts4_word fn_88674BC8();
ts4_word fn_88674ED0();
ts4_word fn_88676898();
ts4_word fn_886A4F28();
ts4_word fn_886A5C00();
ts4_word ts4_if_call_seq_u32_off64_886AA6D0();
ts4_word fn_886EA398();
ts4_word fn_886F6128();
ts4_word fn_886FC898();
ts4_word fn_886FC9F0();
ts4_word fn_886FFE00();
ts4_word fn_8870ECE0();
ts4_word fn_8870FE00();
ts4_word fn_88717218();
ts4_word fn_88718288();
ts4_word fn_8871B870();
ts4_word fn_88883CD0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word ts4_if_call_seq_fn_888AA6C0_888AA8D0();
ts4_word fn_88911668();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_byte_string_assign_8816D090();
ts4_word ts4_call_seq_fn_881EF750_881EDCD8();
ts4_word ts4_call_seq_u32_off0_887393F0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_fixed_string_append_8816CF48();
ts4_word ts4_forward_with_const_248C8000_885BE200();
ts4_word ts4_free_with_header_885BE2C8();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off148c_88614300();
ts4_word ts4_get_u32_off8_8841EF28();
ts4_word ts4_get_u32_off8_88427208();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word ts4_handle_forward0_886107F8();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610A48();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word ts4_if_call_seq_u32_off0_8818C588();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_get_RtlEnterCriticalSection_8818A360();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_if_get_u32_off0_8816CE90();
ts4_word ts4_if_get_u32_off18_888A4DF8();
ts4_word ts4_if_tailcall_MmSetAddressProtect_8857B148();
ts4_word ts4_init_object_884BF7C0();
ts4_word ts4_keyed_item_list_add_unique_8864F8A0();
ts4_word ts4_keyed_item_list_add_unique_8864FD60();
ts4_word ts4_keyed_item_list_add_unique_88650380();
ts4_word ts4_keyed_item_list_add_unique_88650AD0();
ts4_word ts4_keyed_item_list_add_unique_88650D10();
ts4_word ts4_keyed_item_list_add_unique_88651160();
ts4_word ts4_keyed_item_list_add_unique_886515B8();
ts4_word ts4_keyed_item_list_add_unique_88651828();
ts4_word ts4_keyed_item_list_add_unique_88652398();
ts4_word ts4_keyed_item_list_add_unique_88652448();
ts4_word ts4_keyed_item_list_add_unique_886524F8();
ts4_word ts4_keyed_item_list_add_unique_886525A8();
ts4_word ts4_keyed_item_list_add_unique_88652658();
ts4_word ts4_keyed_item_list_add_unique_88652708();
ts4_word ts4_keyed_item_list_add_unique_886527B8();
ts4_word ts4_keyed_item_list_add_unique_88652868();
ts4_word ts4_loop_get_u32_off8_8861DDB0();
ts4_word ts4_memset();
ts4_word ts4_noop_881B3360();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word ts4_select_pair_const_8865C790();
ts4_word ts4_set_u32_off8_8847FA60();
ts4_word ts4_stream_write_f32_884274D8(ts4_word, float);
ts4_word ts4_stream_write_i32_b_88427448();
ts4_word ts4_tailcall_MmFreePhysicalMemory_8857B158();
ts4_word ts4_tsu_cleanup_end();
ts4_word ts4_vector_push_back_construct_88220060();
ts4_word ts4_xml_parser_free_888A7110();

/* Swing_DLL.xex 0x881733D8: loop_get u32@0x2c, u32@0x30, u32@0x0, u32@0x0, u32@0x2c, vcall */
void ts4_loop_get_u32_off2c_881733D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 44))))((ts4_word)t4, (ts4_word)(a0 + 56));
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
            p9 = (ts4_word)(lv3 + 4);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x88174B90: loop_call_seq u32@0x4, u32@0x0, u32@lbl_88D45B38, fn_88613268, u32@0x4, lbl_880D71E0 */
void ts4_loop_call_seq_u32_off4_88174B90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word lv7;
    ts4_word p12;
    ts4_word p15;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv7 = (ts4_word)t2;
        do {
            t10 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
            t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
            if ((ts4_word)t11 == (ts4_word)a1) {
                return;
            }
            p12 = (ts4_word)(lv7 + 4);
            lv7 = p12;
        } while ((ts4_word)p12 != (ts4_word)t1);
        t14 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2, (ts4_word)t11, (ts4_word)t10, (ts4_word)t1);
        if ((ts4_word)t14 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t14) + 4) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t14) + 0) = (ts4_word)(ts4_word)lbl_880D71E0;
            p15 = (ts4_word)t14;
        } else {
            p15 = (ts4_word)0;
        }
        loc50[0] = (ts4_word)p15;
        fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    } else {
        t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_880D71E0;
            p5 = (ts4_word)t4;
        } else {
            p5 = (ts4_word)0;
        }
        loc50[0] = (ts4_word)p5;
        fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    }
    return;
}

/* Swing_DLL.xex 0x88174C40: loop_call_seq u32@0x4, u32@0x0, u32@lbl_88D45B38, fn_88613268, u32@0x4, lbl_880D71EC */
void ts4_loop_call_seq_u32_off4_88174C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word lv7;
    ts4_word p12;
    ts4_word p15;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv7 = (ts4_word)t2;
        do {
            t10 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
            t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
            if ((ts4_word)t11 == (ts4_word)a1) {
                return;
            }
            p12 = (ts4_word)(lv7 + 4);
            lv7 = p12;
        } while ((ts4_word)p12 != (ts4_word)t1);
        t14 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2, (ts4_word)t11, (ts4_word)t10, (ts4_word)t1);
        if ((ts4_word)t14 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t14) + 4) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t14) + 0) = (ts4_word)(ts4_word)lbl_880D71EC;
            p15 = (ts4_word)t14;
        } else {
            p15 = (ts4_word)0;
        }
        loc50[0] = (ts4_word)p15;
        fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    } else {
        t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_880D71EC;
            p5 = (ts4_word)t4;
        } else {
            p5 = (ts4_word)0;
        }
        loc50[0] = (ts4_word)p5;
        fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    }
    return;
}

/* Swing_DLL.xex 0x88176D60: get ts4_handle_forward0_886107F8, u32@0x0, u32@0x4, u32@0x0, u32@0x28, vcall */
void ts4_get_ts4_handle_forward0_886107F8_88176D60(ts4_args3 sp0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_handle_forward0_886107F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)t1, (ts4_word)t3, (ts4_word)4);
    return;
}

/* Swing_DLL.xex 0x8817F860: loop_call_seq u32@0xc, ts4_loop_call_seq_u32_offc_8817F860, u32@lbl_88D45B38, u32@0x8, fn_885651F8, fn_8860D360 */
void ts4_loop_call_seq_u32_offc_8817F860(ts4_word a0, ts4_word a1)
{
    ts4_word lv1;
    ts4_word p13;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    lv1 = (ts4_word)a1;
    while ((ts4_word)lv1 != 0) {
        ((void (*)())ts4_loop_call_seq_u32_offc_8817F860)((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
        t4 = *(ts4_word *)lbl_88D45B38;
        t5 = *(ts4_word *)((char *)(ts4_word)(lv1) + 8);
        if ((ts4_word)t4 != 0) {
            t7 = fn_8860D360((ts4_word)t4, (ts4_word)lv1);
            if ((ts4_word)t7 != 0) {
                fn_8860DBC8((ts4_word)t7, (ts4_word)lv1);
            } else {
                fn_8860DBC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 36)), (ts4_word)lv1);
            }
        } else {
            fn_885651F8((ts4_word)lv1);
        }
        p13 = (ts4_word)t5;
        lv1 = p13;
    }
    return;
}

/* Swing_DLL.xex 0x88197260: if_call_seq u32@0x0, u32@0x0, fn_88197408, ts4_if_get_RtlEnterCriticalSection_8818A360, ts4_if_get_RtlEnterCriticalSection_8818A360, fn_881974B0 */
void ts4_if_call_seq_u32_off0_88197260(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_88197408((ts4_word)(t1 + 180));
        ts4_if_get_RtlEnterCriticalSection_8818A360((ts4_word)(t1 + 124));
        ts4_if_get_RtlEnterCriticalSection_8818A360((ts4_word)(t1 + 68));
        fn_881974B0((ts4_word)(t1 + 36));
        t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880DCF20;
        if ((ts4_word)t6 != 0) {
            ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t6);
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        }
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x881972E8: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, vcall, fn_881992A8 */
void ts4_if_get_u32_off0_881972E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x88199880: if_call_seq u32@lbl_88D45B38, u32@0x2c, u32@0x2c, u32@0x70, ts4_if_tailcall_MmSetAddressProtect_8857B148, fn_881992A8 */
void ts4_if_call_seq_u32_lbl_88D45B38_88199880(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)lbl_88D45B38;
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) - a1);
    if ((ts4_word)a2 == 0) {
        if ((ts4_word)(a3 & 0x1) != 0) {
            ts4_tailcall_MmFreePhysicalMemory_8857B158((ts4_word)a0);
            *(ts4_word *)lbl_88D4597C = (ts4_word)((*(ts4_word *)lbl_88D4597C) - a1);
            return;
        }
        if ((ts4_word)(a3 & 0x2) != 0) {
            fn_8857C820((ts4_word)a0, (ts4_word)0, (ts4_word)((0) | 32768));
            return;
        }
        if ((ts4_word)(a3 & 0x4) != 0) {
            ts4_tailcall_MmFreePhysicalMemory_8857B158((ts4_word)a0);
            *(ts4_word *)lbl_88D45980 = (ts4_word)((*(ts4_word *)lbl_88D45980) - a1);
            return;
        }
        return;
    }
    if ((ts4_word)(a3 & 0x8) == 0 && (ts4_word)(a3 & 0x2) == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 112);
        if ((ts4_word)a3 != (ts4_word)t3) {
            p4 = (ts4_word)4;
            if ((ts4_word)(t3 & 0x4) != 0) {
                p4 = (ts4_word)1028;
            }
            ts4_if_tailcall_MmSetAddressProtect_8857B148((ts4_word)a0, (ts4_word)a1, (ts4_word)p4);
        }
    }
    fn_881992A8((ts4_word)a2, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x881AC978: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x8, memcpy, u32@0x4 */
void ts4_if_call_seq_u32_off4_881AC978(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((int)t2 != -1) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((int)t3 != -1) {
                t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
                if ((ts4_word)t4 >= (ts4_word)t1) {
                    memcpy((ts4_word)(t2 + a0), (ts4_word)(t3 + a1), (ts4_word)((int)t1 * 136));
                    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                    p7 = (ts4_word)t6;
                    if ((ts4_word)t6 < (ts4_word)t1) {
                        p7 = (ts4_word)t1;
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p7;
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x881AD7D8: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x8, memcpy, u32@0x4 */
void ts4_if_call_seq_u32_off4_881AD7D8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((int)t2 != -1) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((int)t3 != -1 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) >= (ts4_word)t1) {
                memcpy((ts4_word)(t2 + a0), (ts4_word)(t3 + a1), (ts4_word)((t1 + (t1 << 1)) << 3));
                t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                p7 = (ts4_word)t6;
                if ((ts4_word)t6 < (ts4_word)t1) {
                    p7 = (ts4_word)t1;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p7;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x881B3AE8: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x8, memcpy, u32@0x4 */
void ts4_if_call_seq_u32_off4_881B3AE8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((int)t2 != -1) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((int)t3 != -1 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) >= (ts4_word)t1) {
                memcpy((ts4_word)(t2 + a0), (ts4_word)(t3 + a1), (ts4_word)((t1 + (t1 << 1)) << 2));
                t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                p7 = (ts4_word)t6;
                if ((ts4_word)t6 < (ts4_word)t1) {
                    p7 = (ts4_word)t1;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p7;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x881B8670: if_call_seq u32@0x8, u32@0x4, u32@0x0, memcpy, u32@0x4, u32@0x4 */
void ts4_if_call_seq_u32_off8_881B8670(ts4_word a0, ts4_word a1)
{
    int t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t2 < (int)t1) {
        memcpy((ts4_word)(((t2 << 6) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a0), (ts4_word)a1, (ts4_word)64);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    }
    return;
}

/* Swing_DLL.xex 0x881BD640: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x8, memcpy, u32@0x4 */
void ts4_if_call_seq_u32_off4_881BD640(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 > 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((int)t2 != -1) {
            t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((int)t3 != -1) {
                t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
                if ((ts4_word)t4 >= (ts4_word)t1) {
                    memcpy((ts4_word)(t2 + a0), (ts4_word)(t3 + a1), (ts4_word)(t1 << 3));
                    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
                    p7 = (ts4_word)t6;
                    if ((ts4_word)t6 < (ts4_word)t1) {
                        p7 = (ts4_word)t1;
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p7;
                }
            }
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    return;
}

/* Swing_DLL.xex 0x881C8B60: if_call_seq u32@0x0, u32@0x0, fn_881C8BD0, u32@0x4, fn_8818A530, u32@0x4 */
void ts4_if_call_seq_u32_off0_881C8B60(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_881C8BD0((ts4_word)t1);
        fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x881E2258: if_call_seq u32@0x4, u32@0xc, u32@0xc, u32@0x8, fn_881F25F0, u32@0x8 */
void ts4_if_call_seq_u32_off4_881E2258(ts4_word a0, ts4_word a1)
{
    ts4_word t14;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    if ((ts4_word)a1 == 0) {
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t14 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t14);
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)a1 <= (ts4_word)t3) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        if ((ts4_word)t6 > (ts4_word)a1) {
            t7 = ts4_if_call_seq_u32_off0_8818C588((ts4_word)a0, (ts4_word)(a1 << 2));
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
            fn_88562DC0((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(t8 << 2));
            t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            if ((ts4_word)t11 != 0) {
                fn_881992A8((ts4_word)0, (ts4_word)t11);
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t7;
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
            return;
        }
        return;
    }
    fn_881F25F0((ts4_word)a0, (ts4_word)a1);
    return;
}

/* Swing_DLL.xex 0x881E2E38: if_call_seq u32@0x30, u32@0x2c, fn_881E2ED0, u32@0x2c, u32@0x28, fn_881E2DA0 */
void ts4_if_call_seq_u32_off30_881E2E38(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 >= 10) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((ts4_word)t4 > 10) {
            fn_881E2DA0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + 40), (ts4_word)(t4 + -10));
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            fn_88562DC0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)(t7 << 2));
            *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)10;
            *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)10;
            return;
        }
        return;
    }
    fn_881E2ED0((ts4_word)a0, (ts4_word)10);
    return;
}

/* Swing_DLL.xex 0x881ED580: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x4, vcall, fn_881992A8 */
void ts4_if_get_u32_off0_881ED580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1, (ts4_word)0);
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x881F0598: if_call_seq u32@0x0, u32@0x0, fn_881F0608, u32@0x4, fn_8818A530, u32@0x4 */
void ts4_if_call_seq_u32_off0_881F0598(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_881F0608((ts4_word)t1);
        fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88200E58: if_call_seq u32@0x0, u32@0x0, u32@0x0, u32@0x0, fn_881992A8, u32@0x0 */
void ts4_if_call_seq_u32_off0_88200E58(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((ts4_word)t3 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t3);
        }
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88200EB8: if_call_seq u32@0x0, u32@0x0, fn_881C5950, u32@0x88, fn_8818A530, u32@0x88 */
void ts4_if_call_seq_u32_off0_88200EB8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_881C5950((ts4_word)(t1 + 132));
        fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 136)));
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 136) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 136) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)0;
        t6 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 120);
        if ((ts4_word)t6 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t6);
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 104);
        if ((ts4_word)t9 != 0) {
            fn_881F26C0((ts4_word)t9, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 108)));
        }
        fn_881E1D70((ts4_word)(t1 + 64));
        fn_881E1D70((ts4_word)(t1 + 60));
        fn_881E1D70((ts4_word)(t1 + 56));
        ts4_call_seq_fn_881EF750_881EDCD8((ts4_word)t1);
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88201058: if_call_seq u32@0x24, u32@0x2c, u32@0x2c, u32@0x28, fn_88201118, u32@0x28 */
void ts4_if_call_seq_u32_off24_88201058(ts4_word a0, ts4_word a1)
{
    ts4_word t14;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    if ((ts4_word)a1 == 0) {
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((ts4_word)t14 != 0) {
            fn_881F26C0((ts4_word)t14, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((ts4_word)a1 <= (ts4_word)t3) {
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
            if ((ts4_word)t6 > (ts4_word)a1) {
                fn_881F26C0((ts4_word)((a1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 36))), (ts4_word)(t6 - a1));
                t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
                fn_88562DC0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)(t9 << 2));
                *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a0;
                *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
                *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
            }
        } else {
            fn_88201118((ts4_word)a0, (ts4_word)a1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x88213D38: if_call_seq u32@0x8, u32@0x4, fn_88214448, fn_881B2AC8, u32@0x20c, u32@0x20c */
void ts4_if_call_seq_u32_off8_88213D38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            fn_881B2AC8((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(t2) + 524) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 524));
            *(ts4_word *)((char *)(ts4_word)(t2) + 528) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 528));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 532);
        return;
    }
    fn_88214448((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)1);
    return;
}

/* Swing_DLL.xex 0x88232CE0: if_call_seq fn_8822A4A0, u32@0x10c, u32@0x10c, u32@0x110, u32@0x110, u32@0x114 */
void ts4_if_call_seq_fn_8822A4A0_88232CE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        fn_8822A4A0();
        *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 268));
        *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 272));
        *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 276));
        *(unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 280));
        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 284));
        *(ts4_word *)((char *)(ts4_word)(a0) + 288) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 288));
        *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 292));
        *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 296));
        *(ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 300));
        *(ts4_word *)((char *)(ts4_word)(a0) + 304) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 304));
    }
    return;
}

/* Swing_DLL.xex 0x882334C0: if_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, ts4_assign_formatted_text */
void ts4_if_call_seq_u32_off0_882334C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
        ts4_assign_formatted_text((ts4_word)(a0 + 8), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    }
    return;
}

/* Swing_DLL.xex 0x8825BE70: get ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0, u32@0x50, vcall */
void ts4_get_ts4_handle_forward_88150770_8825BE70(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[68];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((2875588608) | 9265);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)t1, (ts4_word)t3, (ts4_word)1);
    ts4_small_string256_from_cstr_881A5020((ts4_word)(ts4_word)&loc70[0], (ts4_word)t6);
    ts4_byte_string_assign_8816D090((ts4_word)(a0 + 4), (ts4_word)(ts4_word)&loc70[0]);
    return;
}

/* Swing_DLL.xex 0x8825D008: if_call_seq u32@0x0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x8 */
void ts4_if_call_seq_u32_off0_8825D008(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t2 != 0) {
            t4 = *(ts4_word *)lbl_88D45B38;
            if ((ts4_word)t4 != 0) {
                ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            } else {
                fn_885651F8((ts4_word)t2, (ts4_word)t2);
            }
        }
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x8827CCB0: if_set u8@0x8, fn_881B9148, u32@0x20, u32@0x0, u32@0x14, vcall */
void ts4_if_set_u8_off8_8827CCB0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t6;
    int t12;
    ts4_word t14;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        if ((ts4_word)t6 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 0))))((ts4_word)t6, (ts4_word)1);
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    }
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t12 != 0) {
        t14 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 36)) + 0))) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 0))) + 88))))((ts4_word)t14, (ts4_word)(a0 + 36));
    }
    return;
}

/* Swing_DLL.xex 0x8827F420: loop_get u32@0x30, u32@0x2c, u32@0x0, fn_88612A60, u32@0x0, u32@0x28 */
void ts4_loop_get_u32_off30_8827F420(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p16;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    unsigned char t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = fn_88612A60((ts4_word)t4, (ts4_word)a1);
            if ((ts4_word)t5 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 40))))((ts4_word)t4, (ts4_word)t5);
                t9 = *(unsigned char *)((char *)(ts4_word)(t4) + 28);
                if ((ts4_word)t9 != 0) {
                    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 44))))((ts4_word)t4);
                }
            }
        }
        p16 = (ts4_word)(lv3 + 4);
        lv3 = p16;
    }
    return;
}

/* Swing_DLL.xex 0x88281850: if_get u32@0x208, u32@0x208, u32@0x20c, ts4_registry_dispatch_888860A0, u32@0x208, u32@0x0 */
void ts4_if_get_u32_off208_88281850(ts4_word a0)
{
    int t2;
    ts4_word t5;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 520);
        if ((int)t2 != 0) {
            ts4_registry_dispatch_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 524)));
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 520);
            if ((ts4_word)t5 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
            }
        }
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x882D8538: if_call_seq u32@0x10, fn_882D22B0, u32@0x60, u32@0x64, u32@0x68, u32@0x20 */
void ts4_if_call_seq_u32_off10_882D8538(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p4 = (ts4_word)a3;
    if ((int)t1 != 0) {
        t2 = fn_882D22B0();
        p4 = (ts4_word)t2;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    fn_882DD300((ts4_word)((((int)t5 * (int)a1) + ((int)t6 * (int)a2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))), (ts4_word)p4, (ts4_word)(t7 << 2));
    return;
}

/* Swing_DLL.xex 0x88316460: if_call_seq u32@0x4, u32@0x4, u32@0x4, u32@0x0, u32@lbl_88B3302C, u32@0x4 */
void ts4_if_call_seq_u32_off4_88316460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;
    int t3;
    ts4_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 + -1);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t3 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t4 != 0) {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        }
    }
    return;
}

/* Swing_DLL.xex 0x883403E0: call_seq ts4_memset, ts4_memset, ts4_memset, ts4_memset, ts4_memset, lbl_88C86AA0 */
void ts4_call_seq_ts4_memset_883403E0(ts4_word a0)
{
    ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)16384);
    ts4_memset((ts4_word)(a0 + 16384), (ts4_word)0, (ts4_word)16384);
    ts4_memset((ts4_word)(a0 + ((0) | 32768)), (ts4_word)0, (ts4_word)8208);
    ts4_memset((ts4_word)((a0 + 65536) + -24560), (ts4_word)0, (ts4_word)8208);
    ts4_memset((ts4_word)((a0 + 65536) + -16352), (ts4_word)0, (ts4_word)((0) | 32768));
    ts4_memset((ts4_word)(ts4_word)lbl_88C86AA0, (ts4_word)0, (ts4_word)((0) | 32768));
    ts4_memset((ts4_word)(ts4_word)lbl_88C78998, (ts4_word)0, (ts4_word)16384);
    ts4_memset((ts4_word)(ts4_word)lbl_88C7C998, (ts4_word)0, (ts4_word)16384);
    ts4_memset((ts4_word)(ts4_word)lbl_88C74998, (ts4_word)0, (ts4_word)16384);
    ts4_memset((ts4_word)(ts4_word)lbl_88C82998, (ts4_word)0, (ts4_word)16384);
    *(ts4_word *)((char *)(ts4_word)(a0) + ((65536) | 16420)) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88396230: if_call_seq u32@0x510, u32@0x510, lbl_8802E890, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
void ts4_if_call_seq_u32_off510_88396230(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1296);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802E890, (ts4_word)263);
        *(ts4_word *)((char *)(ts4_word)(a0) + 1296) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1296) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883962A8: if_call_seq u32@0x43c, u32@0x43c, lbl_8802E890, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
void ts4_if_call_seq_u32_off43c_883962A8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1084);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802E890, (ts4_word)273);
        *(ts4_word *)((char *)(ts4_word)(a0) + 1084) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 1084) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x884224B0: if_get u32@0x0, u32@0xc, vcall, fn_8841EF38, u8@0x0, ts4_get_u32_off8_8841EF28 */
void ts4_if_get_u32_off0_884224B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p13;
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;
    unsigned char t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    if ((ts4_word)a1 != 0) {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a4) + 0))) + 12))))((ts4_word)a4, (ts4_word)a2);
        t4 = fn_8841EF38((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
        t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 0);
        if ((ts4_word)t5 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 12))))((ts4_word)a3, (ts4_word)a0, (ts4_word)t3, (ts4_word)a1);
            return;
        }
        t6 = ts4_get_u32_off8_8841EF28((ts4_word)a2);
        t7 = *(ts4_word *)lbl_88CAD32C;
        t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 60))))((ts4_word)t7, (ts4_word)t6);
        if ((ts4_word)a0 != 0) {
            p13 = (ts4_word)a0;
        } else {
            t11 = ts4_get_u32_off0_8841EAC8((ts4_word)a2);
            p13 = (ts4_word)t11;
        }
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 8))))((ts4_word)a3, (ts4_word)p13, (ts4_word)t3, (ts4_word)a1, (ts4_word)t6, (ts4_word)t10);
        fn_884223A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x88422FA8: if_get u32@lbl_88CAD56C, u32@lbl_88CAD568, u32@0x0, u32@0x10, vcall, fn_884223A0 */
void ts4_if_get_u32_lbl_88CAD56C_88422FA8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    ts4_word t3;
    ts4_word t6;

    p2 = (ts4_word)a2;
    if ((ts4_word)a2 == 0) {
        p2 = (ts4_word)(*(ts4_word *)lbl_88CAD56C);
    }
    t3 = *(ts4_word *)lbl_88CAD568;
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3, (ts4_word)a0);
    if ((ts4_word)t6 != 0) {
        fn_884223A0((ts4_word)0, (ts4_word)a0, (ts4_word)t6, (ts4_word)a1, (ts4_word)p2);
    }
    return;
}

/* Swing_DLL.xex 0x88433DD8: if_call_seq ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428980, ts4_get_u32_off0_88428980, u32@0x0, u32@0x4 */
void ts4_if_call_seq_ts4_if_call_seq_u32_off4_88428890_88433DD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    int t6;
    ts4_word t9;
    unsigned short t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t16;
    unsigned short t17;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a2);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)a2);
    t3 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0]);
    t4 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc58[0]);
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 8) = (ts4_word)(2147483648);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    if ((int)t6 == (int)(t5 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t4, (ts4_word)2);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t10 = *(unsigned short *)((char *)(ts4_word)(t3) + 0);
    *(unsigned short *)((char *)(ts4_word)((t9 << 1)) + (*(ts4_word *)((char *)(ts4_word)(t4) + 0))) = (unsigned short)t10;
    t12 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
    t13 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)(t13 + 1);
    if ((int)(t13 + 1) == (int)(t12 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t4, (ts4_word)2);
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t17 = *(unsigned short *)((char *)(ts4_word)(t3) + 2);
    *(unsigned short *)((char *)(ts4_word)((t16 << 1)) + (*(ts4_word *)((char *)(ts4_word)(t4) + 0))) = (unsigned short)t17;
    *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x8846A398: if_get u32@0x8, ts4_set_u32_off8_8847FA60 */
void ts4_if_get_u32_off8_8846A398(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    ts4_set_u32_off8_8847FA60((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    return;
}

/* Swing_DLL.xex 0x88476C88: if_get u32@0x8, u32@0x8, fn_8848E420 */
void ts4_if_get_u32_off8_88476C88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return;
    }
    fn_8848E420((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)), (ts4_word)a0, (ts4_word)1);
    return;
}

/* Swing_DLL.xex 0x88480FF0: get u32@0xc, u32@0x28, u32@0x1c, u32@0x1c */
void ts4_get_u32_offc_88480FF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 28);
    *(unsigned char *)((char *)(ts4_word)((((t3 + (t3 << 1)) << 4) + t4)) + a1) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)((((t3 + (t3 << 1)) << 4) + t4)) + a1)) & ~(3 << (a2 << 1))) | (0 << (a2 << 1)));
    return;
}

/* Swing_DLL.xex 0x88481038: get u32@0xc, u32@0x28, u32@0x1c, u32@0x1c */
void ts4_get_u32_offc_88481038(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 28);
    *(unsigned char *)((char *)(ts4_word)((((t3 + (t3 << 1)) << 4) + t4)) + a1) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)((((t3 + (t3 << 1)) << 4) + t4)) + a1)) & ~(3 << (a2 << 1))) | (2 << (a2 << 1)));
    return;
}

/* Swing_DLL.xex 0x8849F060: loop_call_seq u32@0x24, u32@0x10, u16@0x0, fn_8847FBE8, fn_8847FA78, fn_8847FC28 */
void ts4_loop_call_seq_u32_off24_8849F060(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p14;
    ts4_word p15;
    ts4_word t2;
    ts4_word t12;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) + 16);
    if ((ts4_word)t2 != 0) {
        lv4 = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t2) + 0));
        lv5 = (ts4_word)t2;
        while ((ts4_word)lv4 >= 23) {
            if ((int)lv4 != 23) {
                if ((int)lv4 != 24) {
                    if ((int)lv4 == 26) {
                        fn_8847FC28((ts4_word)lv5, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
                    }
                } else {
                    fn_8847FA78((ts4_word)lv5, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
                }
            } else {
                fn_8847FBE8((ts4_word)lv5, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
            }
            t12 = *(ts4_word *)((char *)(ts4_word)(lv5) + 20);
            p14 = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t12) + 0));
            p15 = (ts4_word)t12;
            lv4 = p14;
            lv5 = p15;
        }
    }
    return;
}

/* Swing_DLL.xex 0x884A2450: if_get u32@-0x58, u32@0xc, u32@0x0, u32@0x10, vcall, u32@-0x58 */
void ts4_if_get_u32_0x58_884A2450(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -88);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        if ((int)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
            if ((int)t5 != 11) {
                fn_884E05F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -88)), (ts4_word)a1, (ts4_word)(ts4_word)lbl_88D24530, (ts4_word)(ts4_word)lbl_880876A0);
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x884A24D0: if_get u32@-0x58, u32@0xc, u32@0x0, u32@0x10, vcall, u32@-0x58 */
void ts4_if_get_u32_0x58_884A24D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + -88);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        if ((int)t2 != 0) {
            t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
            if ((int)t5 != 11) {
                fn_884E0220((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -88)), (ts4_word)a1);
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x884BB3B0: call_seq fn_884BE3E0, fn_884BE3E0 */
void ts4_call_seq_fn_884BE3E0_884BB3B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    float t1;

    (void)a2;
    (void)a3;
    t1 = *(float *)lbl_88001B14;
    fn_884BE3E0((ts4_word)(a0 + 192), (ts4_word)(a0 + 64), (ts4_word)(a0 + 96), t1, (ts4_word)(4294901760), (ts4_word)a1);
    fn_884BE3E0((ts4_word)(a0 + 192), (ts4_word)(a0 + 80), (ts4_word)(a0 + 144), t1, (ts4_word)-1, (ts4_word)a1);
    return;
}

/* Swing_DLL.xex 0x884BEC88: if_addr lbl_880897EC, u16@0x6, u32@0x0, ts4_init_object_884BF7C0 */
void ts4_if_addr_lbl_880897EC_884BEC88(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880897EC;
    ts4_init_object_884BF7C0((ts4_word)(a0 + 20));
    return;
}

/* Swing_DLL.xex 0x884C19E0: if_get u8@0xf, u32@0x0, u32@0x20, vcall */
float ts4_if_get_u8_offf_884C19E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    ts4_word t2;
    float t3;
    float t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a2) + 15);
    if ((ts4_word)t1 != 0) {
        return (*(float *)lbl_88001A20);
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(float *)((char *)(ts4_word)(a1) + 180);
    t5 = ((float (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 32))))((ts4_word)a0);
    return (t5 * t3);
}

/* Swing_DLL.xex 0x884DFF08: if_get u32@0xc, u32@0x4, u32@0xc, u32@0x10, vcall, u32@0x4 */
void ts4_if_get_u32_offc_884DFF08(ts4_word a0, ts4_word a1, float f1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 4);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 12))) + 16))))((ts4_word)(t2 + 12));
    if ((ts4_word)(t5 & 0xff) != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 4))) + 24);
        ts4_stream_write_i32_b_88427448((ts4_word)t7, (ts4_word)5);
        fn_88426FA0((ts4_word)t7, (ts4_word)0);
        ts4_stream_write_f32_884274D8((ts4_word)t7, f1);
        t11 = ts4_get_u32_off8_88427208((ts4_word)t7);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 20))))((ts4_word)t11);
    }
    return;
}

/* Swing_DLL.xex 0x884F51C0: if_call_seq u32@0x10, u32@0x10, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x10, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
void ts4_if_call_seq_u32_off10_884F51C0(ts4_word a0)
{
    ts4_word t2;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t2 != 0) {
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t2, (ts4_word)((1636433920) | 3));
            *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        }
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)((1636433920) | 32773));
    }
    return;
}

/* Swing_DLL.xex 0x884F5220: if_call_seq u32@0x0, u32@0x0, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x0, u32@0x4, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0 */
void ts4_if_call_seq_u32_off0_884F5220(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t2 != 0) {
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t2, (ts4_word)((1619656704) | 8194));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t5 != 0) {
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t5, (ts4_word)((1636433920) | 9));
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        }
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)((1636433920) | 32774));
    }
    return;
}

/* Swing_DLL.xex 0x885AC8C0: if_call_seq ts4_noop_881B3360, fn_885AC6C8, ts4_forward_with_const_248C8000_885BE200 */
void ts4_if_call_seq_ts4_noop_881B3360_885AC8C0(ts4_word a0)
{

    if ((ts4_word)a0 != 0) {
        ts4_noop_881B3360((ts4_word)2, (ts4_word)0, (ts4_word)0);
        fn_885AC6C8((ts4_word)a0);
        ts4_forward_with_const_248C8000_885BE200((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x885BE2E8: if_call_seq ts4_noop_881B3360, u32@0x164, ts4_forward_with_const_248C8000_885BE200, u32@0x164, u32@0x168, ts4_forward_with_const_248C8000_885BE200 */
void ts4_if_call_seq_ts4_noop_881B3360_885BE2E8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t26;
    ts4_word t29;
    ts4_word t32;
    ts4_word t35;
    ts4_word t38;
    ts4_word t41;
    ts4_word t44;
    ts4_word t47;
    int t50;
    ts4_word t53;
    ts4_word t56;
    ts4_word t59;
    ts4_word t62;
    ts4_word t65;
    ts4_word t68;
    ts4_word t71;
    ts4_word t74;

    if ((ts4_word)a0 != 0) {
        ts4_noop_881B3360((ts4_word)(a0 + 664));
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 356);
        if ((ts4_word)t2 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(a0) + 356) = (ts4_word)0;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 360);
        if ((ts4_word)t5 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t5);
            *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)0;
        }
        ts4_free_with_header_885BE2C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 364)));
        ts4_free_with_header_885BE2C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 368)));
        ts4_free_with_header_885BE2C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 324)));
        ts4_free_with_header_885BE2C8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 328)));
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 436);
        if ((ts4_word)t16 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t16);
            *(ts4_word *)((char *)(ts4_word)(a0) + 436) = (ts4_word)0;
        }
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 340);
        *(ts4_word *)((char *)(ts4_word)(a0) + 432) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 428) = (ts4_word)0;
        if ((ts4_word)t19 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t19);
            *(ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
        }
        t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
        if ((ts4_word)t22 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t22);
            *(ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)0;
        }
        fn_885C18C8((ts4_word)a0);
        t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 352);
        if ((ts4_word)t26 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t26);
            *(ts4_word *)((char *)(ts4_word)(a0) + 352) = (ts4_word)0;
        }
        t29 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
        if ((ts4_word)t29 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t29);
            *(ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)0;
        }
        t32 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
        if ((ts4_word)t32 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t32);
            *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
        }
        t35 = *(ts4_word *)((char *)(ts4_word)(a0) + 412);
        if ((ts4_word)t35 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t35);
            *(ts4_word *)((char *)(ts4_word)(a0) + 412) = (ts4_word)0;
        }
        t38 = *(ts4_word *)((char *)(ts4_word)(a0) + 416);
        if ((ts4_word)t38 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t38);
            *(ts4_word *)((char *)(ts4_word)(a0) + 416) = (ts4_word)0;
        }
        t41 = *(ts4_word *)((char *)(ts4_word)(a0) + 420);
        if ((ts4_word)t41 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t41);
            *(ts4_word *)((char *)(ts4_word)(a0) + 420) = (ts4_word)0;
        }
        t44 = *(ts4_word *)((char *)(ts4_word)(a0) + 424);
        if ((ts4_word)t44 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t44);
            *(ts4_word *)((char *)(ts4_word)(a0) + 424) = (ts4_word)0;
        }
        t47 = *(ts4_word *)((char *)(ts4_word)(a0) + 316);
        if ((ts4_word)t47 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t47);
            *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)0;
        }
        t50 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
        if ((int)t50 > 2) {
            fn_885C2378((ts4_word)a0);
        }
        t53 = *(ts4_word *)((char *)(ts4_word)(a0) + 552);
        if ((ts4_word)t53 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t53);
            *(ts4_word *)((char *)(ts4_word)(a0) + 552) = (ts4_word)0;
        }
        t56 = *(ts4_word *)((char *)(ts4_word)(a0) + 556);
        if ((ts4_word)t56 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t56);
            *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
        }
        t59 = *(ts4_word *)((char *)(ts4_word)(a0) + 560);
        if ((ts4_word)t59 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t59);
            *(ts4_word *)((char *)(ts4_word)(a0) + 560) = (ts4_word)0;
        }
        t62 = *(ts4_word *)((char *)(ts4_word)(a0) + 564);
        if ((ts4_word)t62 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t62);
            *(ts4_word *)((char *)(ts4_word)(a0) + 564) = (ts4_word)0;
        }
        t65 = *(ts4_word *)((char *)(ts4_word)(a0) + 568);
        if ((ts4_word)t65 != 0) {
            fn_885C8B20((ts4_word)t65);
        }
        t68 = *(ts4_word *)((char *)(ts4_word)(a0) + 568);
        if ((ts4_word)t68 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t68);
            *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
        }
        t71 = *(ts4_word *)((char *)(ts4_word)(a0) + 584);
        if ((ts4_word)t71 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t71);
            *(ts4_word *)((char *)(ts4_word)(a0) + 584) = (ts4_word)0;
        }
        t74 = *(ts4_word *)((char *)(ts4_word)(a0) + 740);
        if ((ts4_word)t74 != 0) {
            ts4_forward_with_const_248C8000_885BE200((ts4_word)t74);
            *(ts4_word *)((char *)(ts4_word)(a0) + 740) = (ts4_word)0;
        }
        ts4_forward_with_const_248C8000_885BE200((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x885ECF48: if_call_seq fn_88423788, fn_88423660, ts4_get_u32_off0_8841EAC8, lbl_88045824, fn_884210E8, fn_8841ED80 */
void ts4_if_call_seq_fn_88423788_885ECF48(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t5;
    ts4_word t6;

    t1 = fn_88423788((ts4_word)a1, (ts4_word)a0, (ts4_word)0);
    if ((int)(t1 & 0x4) == 0) {
        fn_88423660((ts4_word)a1, (ts4_word)a0, (ts4_word)(t1 | 4));
        t3 = ts4_get_u32_off0_8841EAC8((ts4_word)a0);
        t4 = fn_884210E8((ts4_word)t3, (ts4_word)(ts4_word)lbl_88045824);
        if ((int)t4 == 0) {
            t5 = fn_8841ED80((ts4_word)a0, (ts4_word)2);
            t6 = ts4_chunk_elem24_8841ED08((ts4_word)(ts4_word)lbl_88CAD05C, (ts4_word)4);
            *(unsigned char *)((char *)(ts4_word)((*(unsigned short *)((char *)(ts4_word)(t6) + 18))) + t5) = (unsigned char)25;
        }
    }
    return;
}

/* Swing_DLL.xex 0x885F3C98: loop_get u32@0x0, u32@0x4, u8@0x4, u8@0x4, u32@0x0, u32@0x8 */
void ts4_loop_get_u32_off0_885F3C98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p11;
    ts4_word p12;
    ts4_word t3;
    ts4_word t4;
    unsigned char t5;
    unsigned char t6;
    ts4_word t7;

    lv1 = (ts4_word)(a2 + -1);
    lv2 = (ts4_word)a1;
    while ((int)lv1 >= 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(lv2) + 4);
        t5 = *(unsigned char *)((char *)(ts4_word)(t3) + 4);
        t6 = *(unsigned char *)((char *)(ts4_word)(t4) + 4);
        t7 = *(ts4_word *)((char *)(ts4_word)((((((signed char)t5) << 3) + ((signed char)t6)) << 2)) + a0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 8))))((ts4_word)t7, (ts4_word)lv2, (ts4_word)(((((signed char)t5) << 3) + ((signed char)t6)) << 2), (ts4_word)((((signed char)t5) << 3) + ((signed char)t6)), (ts4_word)((signed char)t5), (ts4_word)t6, (ts4_word)t5);
        p11 = (ts4_word)(lv1 + -1);
        p12 = (ts4_word)(lv2 + 8);
        lv1 = p11;
        lv2 = p12;
    }
    return;
}

/* Swing_DLL.xex 0x885F4C70: if_get u32@0x8, fn_88470870 */
void ts4_if_get_u32_off8_885F4C70(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 == 0) {
        return;
    }
    fn_88470870((ts4_word)t1, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x8860B230: if_get u32@0x10, u32@0x4, fn_8860B060, u32@0x4, u32@0x14, u32@0x0 */
void ts4_if_get_u32_off10_8860B230(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        t3 = fn_8860B060((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 56), (ts4_word)t1);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t3;
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t7 = *(ts4_word *)((char *)(ts4_word)(t4) + 56);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 4))))((ts4_word)a1, (ts4_word)(t7 + t3), (ts4_word)t6);
    }
    return;
}

/* Swing_DLL.xex 0x8860BF08: if_get u32@0x2c, u32@0x0, u32@0x38, u64@0x30, u32@0x10 */
void ts4_if_get_u32_off2c_8860BF08(ts4_word a0)
{
    int t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t1 == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    ((void (*)(ts4_word, ts4_args3))((*(ts4_word *)((char *)(ts4_word)(t2) + 16))))((ts4_word)t1, *(ts4_args3 *)((char *)(ts4_word)(a0) + 48));
    return;
}

/* Swing_DLL.xex 0x88613050: if_call_seq u32@0x180, u8@0x189, u32@0x17c, ts4_memset, u32@0x184, u8@0x189 */
void ts4_if_call_seq_u32_off180_88613050(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 384);
    if ((ts4_word)t1 != 0) {
        ts4_memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 380)), (ts4_word)0, (ts4_word)((int)t1 * 56));
        *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 393) = (unsigned char)1;
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 393) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88614490: call_seq u32@0x0, u8@0x4, u8@0x234, u32@0x22c, u32@0x8, fn_8857B6D8 */
void ts4_call_seq_u32_off0_88614490(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)4;
    t1 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 528) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 532) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 548) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88617760: if_get u8@0x0, fn_886176F0, u32@0x8, u32@0x4 */
void ts4_if_get_u8_off0_88617760(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)10937;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((65536) | 18438);
        return;
    }
    fn_886176F0((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88618158: loop_call_seq u32@0x2c, u32@0x28, u32@0x0, u32@0x4, u8@0x20, u32@0x0 */
void ts4_loop_call_seq_u32_off2c_88618158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word lv19;
    ts4_word p23;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        if ((ts4_word)t1 != (ts4_word)t2) {
            lv3 = (ts4_word)t2;
            do {
                t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
                t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
                if ((ts4_word)t5 == (ts4_word)a1) {
                    *(unsigned char *)((char *)(ts4_word)(t4) + 32) = (unsigned char)1;
                    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 34) = (unsigned char)1;
                }
                p8 = (ts4_word)(lv3 + 4);
                lv3 = p8;
            } while ((ts4_word)p8 != (ts4_word)t1);
        }
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t17 != (ts4_word)t18) {
        lv19 = (ts4_word)t18;
        do {
            t20 = *(ts4_word *)((char *)(ts4_word)(lv19) + 4);
            if ((ts4_word)t20 == (ts4_word)a2) {
                *(unsigned char *)((char *)(ts4_word)(lv19) + 32) = (unsigned char)0;
                *(unsigned char *)((char *)(ts4_word)(lv19) + 35) = (unsigned char)0;
                fn_886180E0((ts4_word)a0, (ts4_word)lv19);
            }
            p23 = (ts4_word)(lv19 + 36);
            lv19 = p23;
        } while ((ts4_word)p23 != (ts4_word)t17);
    }
    return;
}

/* Swing_DLL.xex 0x88618260: if_get fn_88612A60, u32@0x0, u32@0x28, vcall, u8@0x1c, u32@0x0 */
void ts4_if_get_fn_88612A60_88618260(ts4_word a0)
{
    ts4_word t1;
    unsigned char t5;

    t1 = fn_88612A60();
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0, (ts4_word)t1);
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t5 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
        }
    }
    return;
}

/* Swing_DLL.xex 0x88618460: if_get u32@0x178, u8@0x189, u8@0x189, u32@0x0, u32@0x38, vcall */
void ts4_if_get_u32_off178_88618460(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    unsigned char t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
        if ((ts4_word)t1 != 0) {
            t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 393);
            if ((ts4_word)t3 != 0) {
                t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 56))))((ts4_word)t1);
                if ((ts4_word)t6 > 4) {
                    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
                    t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 56))))((ts4_word)t7, (ts4_word)a1);
                    t11 = fn_88612D60((ts4_word)a0, (ts4_word)a1, (ts4_word)(t10 + -4));
                    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) - t11);
                }
            }
            fn_8860DBC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 376)), (ts4_word)a1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x8861AA88: if_get u32@0x0, u8@0x14d8, u8@0x14d8, fn_8860EBE0, u32@0x14c0, u32@0x14c0 */
void ts4_if_get_u32_off0_8861AA88(ts4_word a0, ts4_word a1)
{
    int t1;
    unsigned char t3;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 5336);
        if ((ts4_word)t3 != 0) {
            fn_8860EBE0((ts4_word)a0, (ts4_word)t1);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 5312) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5312)) + -1);
        t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        if ((ts4_word)t7 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t7) + 1)) == 0) {
            ts4_get_u32_off148c_88614300((ts4_word)a0, (ts4_word)t7);
            *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
        }
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0, (ts4_word)a1);
    }
    return;
}

/* Swing_DLL.xex 0x8861D760: if_addr ts4_call_88613268_88618368, ts4_forward_88618388, fn_886182D0, ts4_if_call_seq_fn_888AA6C0_888AA8D0, u32@0x0, u32@0x4 */
void ts4_if_addr_ts4_call_88613268_88618368_8861D760(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    if ((ts4_word)a1 != 0) {
        loc50[0] = (ts4_word)(ts4_word)ts4_call_88613268_88618368;
        loc50[2] = (ts4_word)(ts4_word)ts4_forward_88618388;
        loc50[1] = (ts4_word)(ts4_word)fn_886182D0;
        t1 = ts4_if_call_seq_fn_888AA6C0_888AA8D0((ts4_word)(ts4_word)&loc50[0]);
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a0;
        if ((ts4_word)t3 == (ts4_word)t2) {
            *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)a0;
        }
        *(ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)(ts4_word)fn_8861D6A8;
        *(ts4_word *)((char *)(ts4_word)(t1) + 56) = (ts4_word)(ts4_word)ts4_if_get_u8_off8_886171D8;
        *(ts4_word *)((char *)(ts4_word)(t1) + 60) = (ts4_word)(ts4_word)ts4_noop_88605E88;
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 20))))((ts4_word)a1);
        t8 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t6, (ts4_word)1, (ts4_word)0, (ts4_word)0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)t8, (ts4_word)t6);
        ts4_if_get_u32_off18_888A4DF8((ts4_word)t1, (ts4_word)t8, (ts4_word)t6);
        ts4_registry_dispatch_888860A0((ts4_word)t8);
        ts4_xml_parser_free_888A7110((ts4_word)t1);
    }
    return;
}

/* Swing_DLL.xex 0x88623BF0: if_call_seq lbl_880F7C94, u32@lbl_88D45B1C, u32@0x0, u32@0x234, u32@0x3c, u32@0x40 */
void ts4_if_call_seq_lbl_880F7C94_88623BF0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7C94;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 564) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88628E70: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@lbl_88D45B20, fn_88286F38, u32@lbl_88D45B20 */
void ts4_if_call_seq_u32_lbl_88D45B38_88628E70(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88286F38((ts4_word)t2, (ts4_word)512);
        *(ts4_word *)lbl_88D45B20 = (ts4_word)t3;
        return;
    }
    *(ts4_word *)lbl_88D45B20 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88629AC8: if_get u32@0x34, lbl_880F8C1C, u32@0x0, u32@0x0, u32@0x14, vcall */
void ts4_if_get_u32_off34_88629AC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t10;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8C1C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 0))))((ts4_word)t5, (ts4_word)1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x8862B028: if_get ts4_find_service, fn_88608590, u32@0x0, u32@0x24, vcall, fn_88614770 */
void ts4_if_get_ts4_find_service_8862B028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t10;
    ts4_word t14;

    (void)a0;
    t1 = ts4_find_service((ts4_word)a2);
    if ((ts4_word)t1 != 0) {
        if ((ts4_word)a3 == 0) {
            t2 = fn_88608590((ts4_word)0, (ts4_word)a1);
            p3 = (ts4_word)t2;
        } else {
            p3 = (ts4_word)a3;
        }
        loc50[0] = (ts4_word)p3;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
        t7 = fn_88614770((ts4_word)a1);
        if ((ts4_word)(t7 & 0xff) != 0) {
            ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1);
            t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 60))))((ts4_word)t10, (ts4_word)(ts4_word)&loc58[0]);
            t14 = loc58[0];
            ts4_destroy_owned_object((ts4_word)t14);
        }
    }
    return;
}

/* Swing_DLL.xex 0x8862D1A8: if_call_seq fn_8862AAC0, u32@lbl_88D45B38, fn_88613268, u32@0x30, u32@0x4, lbl_880D6B70 */
void ts4_if_call_seq_fn_8862AAC0_8862D1A8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t4;

    (void)sp1.w[2];
    fn_8862AAC0((ts4_word)a0, sp1);
    t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t4;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8862E7D0: loop_get u32@0x14b8, u32@0x14b4, lbl_880C13B8, u32@0x0, ts4_assign_formatted_text, fn_8816C930 */
void ts4_loop_get_u32_off14b8_8862E7D0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p14;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 5304);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 5300));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0)) + 28));
        fn_8816C930((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C13B8, (ts4_word)((ts4_word)lbl_880C13B8 + 1));
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t8 = loc50[0];
        t9 = loc50[1];
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t7) + 16))))((ts4_word)a1, (ts4_word)t8, (ts4_word)(t9 - t8));
        t12 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t12);
        p14 = (ts4_word)(lv3 + 4);
        lv3 = p14;
    }
    return;
}

/* Swing_DLL.xex 0x88638588: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, u32@0x4, u32@lbl_88D45B38, fn_88618998, u32@lbl_88D45B38 */
void ts4_if_call_seq_u32_lbl_88D45B38_88638588(void)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t3 == (ts4_word)((1266286592) | 2783)) {
        t5 = fn_88618998((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)((3487367168) | 35449));
        t6 = *(ts4_word *)lbl_88D45B38;
        t7 = fn_88883CD0((ts4_word)0);
        if ((ts4_word)t7 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t5;
            *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)t5;
        }
        if ((ts4_word)t5 != 0) {
            *(unsigned char *)((char *)(ts4_word)(t6) + 32) = (unsigned char)0;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88639678: call_seq fn_88627EC0, ts4_handle_forward_88610A48, u32@0x8, u64@0x0, fn_88639480 */
void ts4_call_seq_fn_88627EC0_88639678(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((3043098624) | 54106);
    t3 = ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    fn_88639480((ts4_word)a0, *(ts4_args3 *)((char *)(ts4_word)(t3) + 0));
    return;
}

/* Swing_DLL.xex 0x8863EFF0: if_call_seq fn_88162BB8, fn_881608E8, ts4_if_call_seq_u32_off0_8816D140, fn_88150600, ts4_destroy_owned_object, ts4_destroy_owned_object */
void ts4_if_call_seq_fn_88162BB8_8863EFF0(ts4_word a0)
{
    ts4_word loc60[4];
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    t1 = fn_88162BB8((ts4_word)(a0 + 1124), (ts4_word)91);
    if ((int)t1 != -1) {
        t2 = fn_881608E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(a0 + 1124), (ts4_word)0, (ts4_word)t1);
        ts4_if_call_seq_u32_off0_8816D140((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2);
        fn_88150600((ts4_word)(a0 + 1124), (ts4_word)(ts4_word)&loc50[0]);
        t5 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t5);
        t7 = loc60[0];
        ts4_destroy_owned_object((ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x8864F6E8: get ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0, u32@0x50, vcall */
void ts4_get_ts4_handle_forward_88150770_8864F6E8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((4262526976) | 53560);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)t1, (ts4_word)t3, (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t6;
    return;
}

/* Swing_DLL.xex 0x88652A90: call_seq lbl_880F5230, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_list_add_unique_88652448, lbl_880F5250, fn_88608590 */
void ts4_call_seq_lbl_880F5230_88652A90(void)
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
    ts4_word t46;

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5230);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_list_add_unique_88652448((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5250);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_list_add_unique_88652398((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F526C);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_list_add_unique_886525A8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F528C);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_list_add_unique_886524F8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F52A8);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_list_add_unique_88652868((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F52C8);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_list_add_unique_886527B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F52E4);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_list_add_unique_88652658((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5308);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_list_add_unique_88652708((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t25 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5334);
    loc50[0] = (ts4_word)t25;
    ts4_keyed_item_list_add_unique_88650380((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t28 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F533C);
    loc50[0] = (ts4_word)t28;
    ts4_keyed_item_list_add_unique_88650AD0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t31 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5348);
    loc50[0] = (ts4_word)t31;
    ts4_keyed_item_list_add_unique_8864F8A0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t34 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5354);
    loc50[0] = (ts4_word)t34;
    ts4_keyed_item_list_add_unique_88651828((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t37 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5360);
    loc50[0] = (ts4_word)t37;
    ts4_keyed_item_list_add_unique_8864FD60((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t40 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F5370);
    loc50[0] = (ts4_word)t40;
    ts4_keyed_item_list_add_unique_88651160((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t43 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F537C);
    loc50[0] = (ts4_word)t43;
    ts4_keyed_item_list_add_unique_88650D10((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    t46 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880F538C);
    loc50[0] = (ts4_word)t46;
    ts4_keyed_item_list_add_unique_886515B8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0]);
    return;
}

/* Swing_DLL.xex 0x88652E68: get ts4_get_fn_8864F6E8_88650C70, ts4_handle_forward_88610A48, ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_fn_88650C70_88652E68(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word loc68[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    (void)sp1.w[2];
    ts4_get_fn_8864F6E8_88650C70((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((3166371840) | 21264);
    ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    loc54[0] = (ts4_word)((3081895936) | 13899);
    t4 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0]);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)t4, (ts4_word)t6, (ts4_word)12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t9;
    return;
}

/* Swing_DLL.xex 0x88655680: if_get u8@0x0, u32@lbl_88D45B2C, u32@lbl_88D45B2C, u32@0x0, u32@0x40, u32@lbl_88D45B1C */
void ts4_if_get_u8_off0_88655680(ts4_word a0)
{
    unsigned char t1;
    ts4_word t7;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 544);
        ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 64))))((ts4_word)t7);
        return;
    }
    t3 = *(ts4_word *)lbl_88D45B2C;
    if ((ts4_word)t3 == 0) {
        return;
    }
    ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 64))))((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x886556D0: if_get u8@0x0, u32@lbl_88D45B2C, u32@lbl_88D45B2C, u32@0x0, u32@0x38, u32@0x0 */
void ts4_if_get_u8_off0_886556D0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    ts4_word t7;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4);
        ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 88))))((ts4_word)t7);
        return;
    }
    t3 = *(ts4_word *)lbl_88D45B2C;
    if ((ts4_word)t3 == 0) {
        return;
    }
    ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 56))))((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x88657340: if_get u32@0x1c, u32@0x30, vcall, fn_882736E8, u32@0x0, u32@0x4c */
void ts4_if_get_u32_off1c_88657340(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word p7;
    ts4_word loc50[8];
    ts4_word t3;
    ts4_word t4;
    ts4_word t10;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48))))((ts4_word)(a0 + 28));
    p7 = (ts4_word)0;
    if ((ts4_word)(t3 & 0xff) != 0) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        loc50[3] = (ts4_word)0;
        loc50[4] = (ts4_word)0;
        loc50[5] = (ts4_word)0;
        loc50[6] = (ts4_word)0;
        loc50[7] = (ts4_word)0;
        t4 = fn_882736E8((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
        p5 = (ts4_word)0;
        if ((ts4_word)(t4 & 0xff) == 0) {
            p5 = (ts4_word)1;
        }
        p7 = (ts4_word)p5;
    }
    if ((ts4_word)(p7 & 0xff) != 0) {
        t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 76))))((ts4_word)(a0 + 28), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
        *(ts4_word *)((char *)(ts4_word)(t10) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
        *(ts4_word *)((char *)(ts4_word)(t10) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
        *(ts4_word *)((char *)(ts4_word)(t10) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
        *(ts4_word *)((char *)(ts4_word)(t10) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    }
    return;
}

/* Swing_DLL.xex 0x8865E5C0: if_call_seq u32@0x4, u32@0x40, u8@0x0, u32@0x8, u32@0xc, fn_8826D010 */
void ts4_if_call_seq_u32_off4_8865E5C0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    unsigned char t3;
    ts4_word t4;
    ts4_word t5;

    t3 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 64))) + 0);
    if ((ts4_word)t3 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        loc50[0] = (ts4_word)((3074818048) | 110);
        t5 = fn_8826D010((ts4_word)(t4 + 32), (ts4_word)(ts4_word)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88677058: if_get u32@0x4, u32@0x40, u8@0xe, u32@0x78, u8@0xe, u32@0x78 */
void ts4_if_get_u32_off4_88677058(ts4_word a0)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;
    ts4_word t5;
    ts4_word t6;
    unsigned char t8;
    ts4_word t21;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 14);
    if ((ts4_word)t3 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 120);
        if ((ts4_word)t5 == (ts4_word)((1077215232) | 58079)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
            *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
        } else {
            t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
            *(float *)((char *)(ts4_word)(t6) + 812) = (*(float *)lbl_8814B440);
            t8 = *(unsigned char *)((char *)(ts4_word)(t2) + 12);
            p10 = (ts4_word)0;
            if ((ts4_word)t8 == 0) {
                p10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p10;
            *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t2) + 13));
            *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 8));
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
        t21 = ts4_select_pair_const_8865C790((ts4_word)a0);
        t22 = fn_8865C578((ts4_word)t21);
        fn_88676898((ts4_word)t22);
        fn_88674ED0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 76)));
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
    } else {
        *(unsigned char *)((char *)(ts4_word)(t2) + 14) = (unsigned char)1;
    }
    fn_88674BC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 76)));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 96) = (ts4_word)((2525102080) | 12467);
    return;
}

/* Swing_DLL.xex 0x8868E1D8: call_seq u32@0x48, u32@0x44, u32@0x0, u32@0x0, fn_881899D8 */
void ts4_call_seq_u32_off48_8868E1D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    float t5;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 72))) + 68);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t5 = fn_881899D8((ts4_word)a0, (ts4_word)a2, (((float)((double)((ts4_s64)(int)t3))) / ((float)((double)((ts4_s64)(int)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)))))));
    *(float *)((char *)(ts4_word)(a1) + 4) = t5;
    return;
}

/* Swing_DLL.xex 0x88691888: loop_call_seq u32@0x0, u32@0x4, u32@0x0, u32@0x4, fn_8866DD78 */
void ts4_loop_call_seq_u32_off0_88691888(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word lv6;
    ts4_word p10;
    ts4_word loc50[4];
    int t1;
    ts4_word t7;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p4 = (ts4_word)0;
    if ((int)t1 != -1) {
        p4 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) << 2) + t1) + a1);
    }
    p5 = (ts4_word)0;
    if ((int)t1 != -1) {
        p5 = (ts4_word)(t1 + a1);
    }
    lv6 = (ts4_word)p5;
    while ((ts4_word)lv6 != (ts4_word)p4) {
        t7 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        loc50[0] = (ts4_word)t7;
        fn_8866DD78((ts4_word)t8, (ts4_word)(ts4_word)&loc50[0]);
        p10 = (ts4_word)(lv6 + 4);
        lv6 = p10;
    }
    return;
}

/* Swing_DLL.xex 0x886A6510: loop_get u32@0x8, u32@0x4, u32@0x0, fn_886A5C00, u32@0x14, u32@0x10 */
void ts4_loop_get_u32_off8_886A6510(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word lv12;
    ts4_word p15;
    ts4_word lv19;
    ts4_word p28;
    ts4_word lv32;
    ts4_word p38;
    ts4_word t1;
    ts4_word t4;
    ts4_word t10;
    ts4_word t20;
    ts4_word t23;
    ts4_word t33;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            fn_886A5C00((ts4_word)t4);
        }
        p7 = (ts4_word)(lv3 + 4);
        lv3 = p7;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    lv12 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    while ((ts4_word)lv12 != (ts4_word)t10) {
        fn_886A4F28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv12) + 0)));
        p15 = (ts4_word)(lv12 + 4);
        lv12 = p15;
    }
    lv19 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv19 != (ts4_word)t1) {
        t20 = *(ts4_word *)((char *)(ts4_word)(lv19) + 0);
        if ((ts4_word)t20 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 64))) + 0)) == 0) {
            t23 = *(ts4_word *)((char *)(ts4_word)(t20) + 80);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 4))))((ts4_word)t23);
        }
        p28 = (ts4_word)(lv19 + 4);
        lv19 = p28;
    }
    lv32 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv32 != (ts4_word)t1) {
        t33 = *(ts4_word *)((char *)(ts4_word)(lv32) + 0);
        if ((ts4_word)t33 != 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t33) + 0))) + 12))))((ts4_word)t33);
        }
        p38 = (ts4_word)(lv32 + 4);
        lv32 = p38;
    }
    return;
}

/* Swing_DLL.xex 0x886AA8B0: loop_get u32@0x30, u8@0x324, u32@0x8, u32@0x4, u32@0x0, u32@0x40 */
void ts4_loop_get_u32_off30_886AA8B0(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p17;
    unsigned char t2;
    ts4_word t3;
    ts4_word t6;
    unsigned char t8;
    ts4_word t9;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 804);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        while ((ts4_word)lv5 != (ts4_word)t3) {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            if ((ts4_word)t6 != 0) {
                t8 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 64))) + 0);
                if ((ts4_word)t8 == 0) {
                    t9 = *(ts4_word *)((char *)(ts4_word)(t6) + 80);
                    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 12))))((ts4_word)t9);
                }
                ts4_if_call_seq_u32_off64_886AA6D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0)));
            }
            p17 = (ts4_word)(lv5 + 4);
            lv5 = p17;
        }
    }
    return;
}

/* Swing_DLL.xex 0x886B7CF8: if_call_seq u32@0x0, u32@0x48, u32@0x44, fn_8866F028, fn_88911668 */
void ts4_if_call_seq_u32_off0_886B7CF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(t1 + a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a4) + 68);
    t3 = fn_8866F028((ts4_word)t2, (ts4_word)(t1 + a1));
    if ((ts4_word)t3 != 0) {
        fn_88911668((ts4_word)(a0 + 4), (ts4_word)(a4 + 816), (ts4_word)t3, (ts4_word)(t2 + 140), (ts4_word)(t2 + 212));
    }
    return;
}

/* Swing_DLL.xex 0x886EA6A8: if_get u8@0x21, u8@0x20, u32@0x1c, fn_886EA398, u8@0x20, u32@0x1c */
void ts4_if_get_u8_off21_886EA6A8(ts4_word a0)
{
    unsigned char t1;
    int t6;
    ts4_word t9;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_word t24;
    ts4_word t27;
    ts4_word t28;
    ts4_word t29;
    ts4_word t30;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 33);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 32)) != 0) {
        fn_886EA398((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if (((int)t6 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t6) + 32)) != 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 8)) == 1) {
        t9 = *(ts4_word *)lbl_88D45A4C;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 340))) + 4))))((ts4_word)(t9 + 340));
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t14 = *(ts4_word *)lbl_88D45AD4;
        t15 = *(ts4_word *)((char *)(ts4_word)(t13) + 88);
        t17 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t14) + 36))) + 84);
        t18 = ts4_call_seq_u32_off0_887393F0((ts4_word)(((int)t15 * 60) + t17));
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t20 = *(ts4_word *)((char *)(ts4_word)(t19) + 112);
        t21 = *(ts4_word *)((char *)(ts4_word)(t19) + 108);
        memcpy((ts4_word)t18, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t19) + 104)), (ts4_word)((int)t20 * (int)t21));
        t24 = *(ts4_word *)((char *)(ts4_word)((((int)t15 * 60) + t17)) + 0);
        fn_882882A0((ts4_word)t24, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t24) + 24)) & 0xfffffffc), (ts4_word)0);
        t27 = *(ts4_word *)lbl_88D45AD4;
        t28 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t29 = *(ts4_word *)((char *)(ts4_word)(t28) + 92);
        t30 = *(ts4_word *)((char *)(ts4_word)(t28) + 88);
        fn_88222AF0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(t27) + 36)) + 52), (ts4_word)t30, (ts4_word)t29);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 340))) + 8))))((ts4_word)(t9 + 340));
    }
    return;
}

/* Swing_DLL.xex 0x886EA7B8: call_seq fn_88627EC0, ts4_handle_forward_88150770, fn_88169350, ts4_find_service, u32@0x1c, fn_886EA398 */
void ts4_call_seq_fn_88627EC0_886EA7B8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((2511339520) | 58053);
    t3 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    fn_88169350((ts4_word)(ts4_word)&loc54[0], (ts4_word)t3);
    t5 = loc54[0];
    t6 = ts4_find_service((ts4_word)t5);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
    fn_886EA398((ts4_word)t6, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x886FD0C8: loop_get fn_886F6128, u32@0x64, u32@0x0, u32@0xc, vcall, u32@0x54 */
void ts4_loop_get_fn_886F6128_886FD0C8(ts4_word a0)
{
    ts4_word lv20;
    ts4_word p26;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t13;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t21;
    ts4_word t22;

    fn_886F6128();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 12))))((ts4_word)t2, (ts4_word)0);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t7 != 0) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 12))))((ts4_word)t8, (ts4_word)0);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t13 == 0) {
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
        t16 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
        if ((ts4_word)t16 != (ts4_word)t14) {
            t17 = ts4_find_service((ts4_word)t14);
            *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)t17;
            if ((ts4_word)t17 != 0) {
                t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
                lv20 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
                while ((ts4_word)lv20 != (ts4_word)t18) {
                    t21 = *(ts4_word *)((char *)(ts4_word)(lv20) + 0);
                    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
                    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t21) + 0))) + 16))))((ts4_word)t21, (ts4_word)t22, (ts4_word)2);
                    p26 = (ts4_word)(lv20 + 4);
                    lv20 = p26;
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x886FF820: call_seq u32@lbl_88D45AD4, u32@0x54, ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x34 */
void ts4_call_seq_u32_lbl_88D45AD4_886FF820(ts4_args3 sp0)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    loc50[0] = (ts4_word)((4094427136) | 52484);
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 84);
    t3 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t4 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)t3);
    *(unsigned char *)((char *)(ts4_word)(t2) + 52) = (unsigned char)t4;
    return;
}

/* Swing_DLL.xex 0x8870D9F8: if_call_seq u32@lbl_88D45A70, u32@0x40, u32@0x12c, u32@0x130, fn_8822CA90, u32@0x8 */
void ts4_if_call_seq_u32_lbl_88D45A70_8870D9F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    float t8;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A70)) + 64);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 300);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 304);
        if ((ts4_word)t3 != 0 && (ts4_word)t4 != 0) {
            loc50[0] = (ts4_word)0;
            loc50[1] = (ts4_word)0;
            t5 = fn_8822CA90((ts4_word)t2, (ts4_word)t3, *(ts4_args2 *)&loc50[0]);
            t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
            t7 = *(ts4_word *)lbl_88D45A70;
            *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)((3766681600) | 20946);
            *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)t4;
            t8 = *(float *)((char *)(ts4_word)(a1) + 0);
            t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 64);
            *(float *)((char *)(ts4_word)(t6) + 12) = t8;
            *(float *)((char *)(ts4_word)(t6) + 16) = (*(float *)((char *)(ts4_word)(a1) + 4));
            *(float *)((char *)(ts4_word)(t6) + 20) = (*(float *)((char *)(ts4_word)(a1) + 8));
            *(float *)((char *)(ts4_word)(t6) + 24) = (*(float *)((char *)(ts4_word)(a2) + 0));
            *(float *)((char *)(ts4_word)(t6) + 28) = (*(float *)((char *)(ts4_word)(a2) + 4));
            *(float *)((char *)(ts4_word)(t6) + 32) = (*(float *)((char *)(ts4_word)(a2) + 8));
            ts4_loop_get_u32_off8_8861DDB0((ts4_word)t9, (ts4_word)t5);
        }
    }
    return;
}

/* Swing_DLL.xex 0x88710080: if_get u32@0x34, u32@0xc, u8@0x8, u32@0x38, u32@0x0, u32@0x20 */
void ts4_if_get_u32_off34_88710080(ts4_word a0)
{
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    float t13;
    float t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        if ((ts4_word)t2 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 8)) != 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
            if ((ts4_word)t4 != 0) {
                t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4);
                t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
                if ((ts4_word)t8 == (ts4_word)((983040) | 65535)) {
                    p10 = (ts4_word)0;
                } else {
                    t9 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)t7);
                    p10 = (ts4_word)t9;
                }
                if ((ts4_word)(p10 & 0xff) != 0) {
                    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
                    if ((ts4_word)t11 != 0) {
                        t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 12);
                        if ((ts4_word)t12 != 0) {
                            t13 = *(float *)((char *)(ts4_word)(t12) + 16);
                            t14 = *(float *)lbl_8814B440;
                            if (t13 > t14) {
                                *(float *)((char *)(ts4_word)(t12) + 16) = t14;
                                fn_8870FE00((ts4_word)a0);
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x88718408: if_call_seq ts4_handle_forward_88150770, u32@0x4, ts4_if_get_u32_off0_8816CE90, fn_886FFE00, fn_886FFE00 */
void ts4_if_call_seq_ts4_handle_forward_88150770_88718408(ts4_args3 sp0)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)((2165833728) | 4077);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 == (ts4_word)((983040) | 65535)) {
        fn_886FFE00((ts4_word)-1);
        return;
    }
    t3 = ts4_if_get_u32_off0_8816CE90((ts4_word)t1);
    fn_886FFE00((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x88718480: loop_get u32@0x1c, u32@0x8, u32@0x4, vcall, u32@0x1c, u32@0x28 */
void ts4_loop_get_u32_off1c_88718480(ts4_word a0)
{
    ts4_word lv8;
    ts4_word p28;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t6;
    ts4_word t9;
    unsigned char t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;
    unsigned char t18;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8))) + 4))))((ts4_word)(t1 + 8));
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 40);
        lv8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 0));
        while ((ts4_word)lv8 != (ts4_word)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)(lv8) + 8);
            t10 = *(unsigned char *)((char *)(ts4_word)(t9) + 24);
            if ((ts4_word)t10 == 0) {
                t12 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
                if ((ts4_word)t12 == (ts4_word)((326238208) | 36391)) {
                    fn_886FFE00((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 8))) + 0)));
                    *(unsigned char *)((char *)(ts4_word)(t9) + 24) = (unsigned char)1;
                } else {
                    if ((ts4_word)t12 == (ts4_word)((3658874880) | 16911)) {
                        t13 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
                        fn_886FFE00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 0)));
                        t16 = *(ts4_word *)lbl_88D45AD4;
                        t17 = *(ts4_word *)((char *)(ts4_word)(t13) + 0);
                        t18 = *(unsigned char *)((char *)(ts4_word)(t13) + 4);
                        loc50[1] = (ts4_word)t17;
                        loc50[0] = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 7476)) + 96);
                        loc50[2] = (ts4_word)0;
                        fn_88718288(*(ts4_args3 *)&loc50[0], (ts4_word)t18, (ts4_word)0);
                        *(unsigned char *)((char *)(ts4_word)(t9) + 24) = (unsigned char)1;
                    }
                }
            }
            p28 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 0));
            lv8 = p28;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((t1 + 8)) + 0))) + 8))))((ts4_word)(t1 + 8));
    }
    return;
}

/* Swing_DLL.xex 0x8871A740: get fn_88627EC0, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, fn_88608590 */
void ts4_get_fn_88627EC0_8871A740(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((865992704) | 40860);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    t5 = loc58[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)1);
    t9 = fn_88608590((ts4_word)0, (ts4_word)t8);
    t10 = ts4_find_service((ts4_word)t9);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t10;
    return;
}

/* Swing_DLL.xex 0x8871A7D0: get fn_88627EC0, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, fn_88608590 */
void ts4_get_fn_88627EC0_8871A7D0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((865992704) | 40860);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    t5 = loc58[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)1);
    t9 = fn_88608590((ts4_word)0, (ts4_word)t8);
    t10 = ts4_find_service((ts4_word)t9);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t10;
    return;
}

/* Swing_DLL.xex 0x8871B7E0: loop_call_seq u32@0x34, u32@0xc, u32@0x48, u32@0x44, fn_886FC9F0, fn_886FC898 */
void ts4_loop_call_seq_u32_off34_8871B7E0(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12)) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68));
        while ((ts4_word)lv5 != (ts4_word)t3) {
            t6 = fn_886FC9F0((ts4_word)lv5, (ts4_word)t1);
            t7 = fn_886FC898((ts4_word)lv5, (ts4_word)t1);
            if ((ts4_word)(t6 & 0xff) != 0 || (ts4_word)(t7 & 0xff) != 0) {
                fn_88717218((ts4_word)a0, (ts4_word)lv5);
            }
            p10 = (ts4_word)(lv5 + 44);
            lv5 = p10;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8871B960: loop_get u32@0x34, u32@0xc, u32@0x64, u32@0x64, u32@0x0, u32@0x20 */
void ts4_loop_get_u32_off34_8871B960(ts4_word a0)
{
    ts4_word p10;
    ts4_word lv21;
    ts4_word p27;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t16;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12)) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
        if ((ts4_word)t4 != 0) {
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
            if ((ts4_word)t8 == (ts4_word)((983040) | 65535)) {
                p10 = (ts4_word)0;
            } else {
                t9 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)t7);
                p10 = (ts4_word)t9;
            }
            if ((ts4_word)(p10 & 0xff) != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 12))) + 104)) != 0) {
                fn_8871B870((ts4_word)a0);
            }
        }
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        if ((ts4_word)t16 != 0) {
            fn_8870ECE0((ts4_word)t16);
        }
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
        lv21 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
        while ((ts4_word)lv21 != (ts4_word)t19) {
            t22 = *(ts4_word *)((char *)(ts4_word)(lv21) + 0);
            t23 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t22) + 0))) + 40))))((ts4_word)t22, (ts4_word)t23);
            p27 = (ts4_word)(lv21 + 4);
            lv21 = p27;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8871F410: if_call_seq u32@0x4, u8@-0x4, u8@-0x5, lbl_880D3B5C, fn_8821FA18, ts4_vector_push_back_construct_88220060 */
void ts4_if_call_seq_u32_off4_8871F410(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[70];
    ts4_word t1;
    unsigned char t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + -4);
    if ((ts4_word)t2 != 46 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + -5)) != 46) {
        t4 = fn_8821FA18((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_880D3B5C);
        ts4_vector_push_back_construct_88220060((ts4_word)a0, (ts4_word)t4);
        ts4_fixed_string_append_8816CF48((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D3A48, (ts4_word)((ts4_word)lbl_880D3A48 + 4));
    }
    return;
}
