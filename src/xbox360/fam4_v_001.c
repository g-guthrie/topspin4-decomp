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
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char g_ts4_session_context[];
extern char g_ts4_session_state[];
extern char lbl_8808D674[];
extern char lbl_880D0938[];
extern char lbl_880D1EB8[];
extern char lbl_880D21C0[];
extern char lbl_880D35C0[];
extern char lbl_880D3820[];
extern char lbl_880D4204[];
extern char lbl_880D991C[];
extern char lbl_880D9988[];
extern char lbl_880E1674[];
extern char lbl_880E1880[];
extern char lbl_880E2F64[];
extern char lbl_880E2F80[];
extern char lbl_880E2F94[];
extern char lbl_880E2FA8[];
extern char lbl_880E2FE4[];
extern char lbl_880E2FF4[];
extern char lbl_880EFA80[];
extern char lbl_880EFA9C[];
extern char lbl_880EFAB4[];
extern char lbl_880EFAD8[];
extern char lbl_880EFAF0[];
extern char lbl_880EFB08[];
extern char lbl_880EFB20[];
extern char lbl_880EFB38[];
extern char lbl_88C69E60[];
extern char lbl_88C69F78[];
extern char lbl_88C6A098[];
extern char lbl_88C6A0C0[];
extern char lbl_88C6A128[];
extern char lbl_88C6A45C[];
extern char lbl_88C6B930[];
extern char lbl_88C6BEF4[];
extern char lbl_88C6BEFC[];
extern char lbl_88C6BF04[];
extern char lbl_88C6BF0C[];
extern char lbl_88C6C00C[];
extern char lbl_88C6C010[];
extern char lbl_88D3EB60[];
extern char lbl_88D41FC4[];
extern char lbl_88D42940[];
extern char lbl_88D458AC[];
extern char lbl_88D458B0[];
extern char lbl_88D458E0[];
extern char lbl_88D458F0[];
extern char lbl_88D4590C[];
extern char lbl_88D45919[];
extern char lbl_88D4592C[];
extern char lbl_88D45930[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A60[];
extern char lbl_88D45AD4[];
extern char lbl_88D45AF0[];
extern char lbl_88D45B0C[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B34[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
ts4_word fn_88151560();
ts4_word fn_8815D480();
ts4_word fn_8816C2F0();
ts4_word fn_8816CAA0();
ts4_word fn_88171F50();
ts4_word fn_88174A38();
ts4_word ts4_if_call_seq_u32_off24_8817BDD8();
ts4_word ts4_if_call_seq_u32_off8_8817E578();
ts4_word ts4_if_call_seq_fn_8892EE88_8817F5E0();
ts4_word fn_881AB830();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word ts4_loop_call_seq_u32_off10_88202BF8();
ts4_word fn_882256B0();
ts4_word fn_8822C898();
ts4_word fn_8822D0A8();
ts4_word ts4_if_call_seq_fn_8822A4A0_88232CE0();
ts4_word fn_8828E120();
ts4_word ts4_if_call_seq_u32_off0_884F5220();
ts4_word fn_885630C0();
ts4_word fn_885651F8();
ts4_word fn_88566FE8();
ts4_word fn_88582018();
ts4_word fn_885820B0();
ts4_word fn_88608590();
ts4_word fn_8860AB08();
ts4_word fn_88611620();
ts4_word ts4_if_call_seq_fn_881F04B8_886131F0();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88617788();
ts4_word fn_88627EC0();
ts4_word fn_88628C48();
ts4_word fn_8862BE08();
ts4_word ts4_get_ts4_handle_forward_88150770_8864F6E8();
ts4_word fn_88657120();
ts4_word ts4_loop_get_u32_off1c_88718480();
ts4_word fn_88739110();
ts4_word fn_8873B890();
ts4_word ts4_call_seq_fn_88731540_8873B940();
ts4_word fn_88758DA8();
ts4_word fn_8875A0F0();
ts4_word fn_8875B680();
ts4_word fn_8875EB68();
ts4_word fn_8876D8D8();
ts4_word fn_8876D970();
ts4_word fn_8876DF40();
float fn_88771618();
ts4_word fn_887744D8();
ts4_word fn_887D2960();
ts4_word fn_887D9C90();
ts4_word fn_887E0540();
ts4_word fn_887E5898();
ts4_word fn_887E72E0();
ts4_word fn_887EDAF0();
ts4_word fn_887EDDE8();
ts4_word fn_887EEFF0();
ts4_word fn_887F0CA0();
ts4_word fn_88804240();
ts4_word fn_888052F0();
ts4_word ts4_lua_register_methods_88805B48();
ts4_word ts4_lua_register_methods_88805D68();
ts4_word ts4_lua_register_methods_88805E58();
ts4_word ts4_lua_register_methods_88805F80();
ts4_word ts4_lua_register_methods_888060C8();
ts4_word ts4_lua_register_methods_88806210();
ts4_word ts4_if_addr_lbl_880E17D8_88836040();
ts4_word fn_888368B0();
ts4_word fn_88852548();
ts4_word ts4_loop_get_u32_lbl_88D45B1C_88868008();
ts4_word fn_88868A88();
ts4_word fn_88868B48();
ts4_word fn_88869690();
ts4_word fn_888697B0();
ts4_word fn_88869830();
ts4_word fn_8886B1B0();
ts4_word fn_8886C1C0();
ts4_word fn_88883CD0();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88884DE0();
ts4_word fn_888903D8();
ts4_word fn_888B8F58();
ts4_word fn_888B9E40();
ts4_word fn_888C2C80();
ts4_word fn_888C39A0();
ts4_word fn_888D3330();
ts4_word fn_888DCE38();
ts4_word fn_888DFAD0();
ts4_word fn_888E62C8();
ts4_word fn_888EE650();
ts4_word fn_888F67B8();
ts4_word fn_888FA780();
ts4_word fn_888FBCA0();
ts4_word fn_88901010();
ts4_word fn_88907128();
ts4_word fn_889074A8();
ts4_word fn_88907570();
ts4_word fn_88908530();
ts4_word fn_88909360();
ts4_word fn_88923238();
ts4_word fn_88939C30();
ts4_word fn_889423E0();
ts4_word fn_88943760();
ts4_word fn_88950A30();
ts4_word fn_88956170();
ts4_word fn_88972828();
ts4_word fn_8897EA30();
ts4_word fn_889C73B8();
ts4_word fn_889C7CE0();
ts4_word fn_88B09368();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_fn_88832F70_88806570();
ts4_word ts4_concat3_881642B0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_dtor_5_88165440();
ts4_word ts4_find_service();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610778();
ts4_word ts4_handle_forward_88610A48();
ts4_word ts4_hash_find_881AB900();
ts4_word ts4_hash_find_pair_88848CA0();
ts4_word ts4_if_addr_lbl_880D2AC0_8899A668();
ts4_word ts4_if_call_seq_NtSetEvent_8857C1F8();
ts4_word ts4_if_call_seq_lbl_880E2FBC_88806718();
ts4_word ts4_if_call_seq_lbl_880E2FD4_88806650();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word ts4_if_call_seq_u32_off4_88161D58();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_if_get_u32_off0_8816CE90();
ts4_word ts4_if_get_u8_off0_886F2460();
ts4_word ts4_if_get_u8_off0_8873B7E8();
ts4_word ts4_init_range_and_run_service_opt_88164450();
ts4_word ts4_keyed_item_add_or_remove_8876FD58();
ts4_word ts4_keyed_item_add_or_remove_8876FE38();
ts4_word ts4_keyed_item_add_or_remove_887700C8();
ts4_word ts4_keyed_item_add_or_remove_887701A8();
ts4_word ts4_keyed_item_add_or_remove_88770750();
ts4_word ts4_keyed_item_add_or_remove_88770AB0();
ts4_word ts4_keyed_item_add_or_remove_88770B90();
ts4_word ts4_keyed_item_add_or_remove_88770D50();
ts4_word ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0();
ts4_word ts4_loop_get_u32_off0_88402150();
ts4_word ts4_loop_get_u32_off0_886F5700();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_offset_array_end8_8815E4D0();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x884F5A80: if_call_seq u32@0x4, u32@0x4, ts4_if_call_seq_u32_lbl_88D45B38_88884DE0, u32@0x4, u32@0x0, ts4_if_call_seq_u32_off0_884F5220 */
void ts4_if_call_seq_u32_off4_884F5A80(ts4_word a0)
{
    ts4_word t2;

    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t2 != 0) {
            ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)t2, (ts4_word)((1636433920) | 3));
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        }
        ts4_if_call_seq_u32_off0_884F5220((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0((ts4_word)a0, (ts4_word)((1636433920) | 32787));
    }
    return;
}

/* Swing_DLL.xex 0x88650C70: get ts4_get_ts4_handle_forward_88150770_8864F6E8, ts4_handle_forward_88610A48, ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_fn_8864F6E8_88650C70(ts4_word a0, ts4_args3 sp1)
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
    ts4_get_ts4_handle_forward_88150770_8864F6E8((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((3210346496) | 34467);
    ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    loc54[0] = (ts4_word)((3081895936) | 13899);
    t4 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0]);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)t4, (ts4_word)t6, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t9;
    return;
}

/* Swing_DLL.xex 0x88721D98: loop_call_seq u32@0x0, u32@0x4, u32@0x10c, u32@0x11c, u32@0x4, u32@0xc */
void ts4_loop_call_seq_u32_off0_88721D98(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p15;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 268);
    if ((ts4_word)t1 < (ts4_word)t2) {
        lv12 = (ts4_word)t1;
        do {
            t14 = *(ts4_word *)((char *)(ts4_word)(lv12) + 268);
            if ((ts4_word)t14 == (ts4_word)t3) {
                return;
            }
            p15 = (ts4_word)(lv12 + 308);
            lv12 = p15;
        } while ((ts4_word)p15 < (ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a1) + 284) = (ts4_word)2;
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t16 != (ts4_word)t17) {
            ts4_if_call_seq_fn_8822A4A0_88232CE0((ts4_word)t16, (ts4_word)a1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 308);
        } else {
            fn_882256B0((ts4_word)a0, (ts4_word)t16, (ts4_word)a1);
        }
        ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)lbl_88D42940));
    } else {
        *(ts4_word *)((char *)(ts4_word)(a1) + 284) = (ts4_word)2;
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t4 != (ts4_word)t5) {
            ts4_if_call_seq_fn_8822A4A0_88232CE0((ts4_word)t4, (ts4_word)a1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 308);
        } else {
            fn_882256B0((ts4_word)a0, (ts4_word)t4, (ts4_word)a1);
        }
        ts4_if_call_seq_NtSetEvent_8857C1F8((ts4_word)(*(ts4_word *)lbl_88D42940));
    }
    return;
}

/* Swing_DLL.xex 0x88722798: if_call_seq u8@0x2d, u32@lbl_88D45AD4, u8@0x7c, u8@0x2d, u32@0x20, u32@0x20 */
void ts4_if_call_seq_u8_off2d_88722798(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    ts4_word t3;
    unsigned char t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t11;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 45);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + ((65536) | 22304));
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)t1;
    t4 = *(unsigned char *)((char *)(ts4_word)(a1) + 45);
    if ((ts4_word)t4 == 1) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
        fn_8828E120((ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((t5 << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32)))) + 8)));
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    *(ts4_word *)((char *)(ts4_word)(a0) + 796) = (ts4_word)t10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 804) = (unsigned char)((((int)2 < (int)(*(ts4_word *)((char *)(ts4_word)(a1) + 24))) - (!((ts4_word)t11 <= 2))) != 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return;
}

/* Swing_DLL.xex 0x8874B890: if_call_seq ts4_handle_forward_88150770, u32@0x4, ts4_if_get_u32_off0_8816CE90, u32@0x90, fn_8822D0A8, ts4_call_seq_fn_88731540_8873B940 */
void ts4_if_call_seq_ts4_handle_forward_88150770_8874B890(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    loc50[0] = (ts4_word)((3379888128) | 51545);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 == (ts4_word)((983040) | 65535)) {
        p5 = (ts4_word)10;
    } else {
        t3 = ts4_if_get_u32_off0_8816CE90((ts4_word)t1);
        p5 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)p5;
    fn_8822D0A8((ts4_word)(a0 + 128), (ts4_word)p5);
    (void)sp1.w[2];
    ts4_call_seq_fn_88731540_8873B940((ts4_word)a0, sp1);
    return;
}

/* Swing_DLL.xex 0x8874B920: if_call_seq u32@0x94, ts4_handle_forward_88150770, u32@0x4, ts4_if_get_u32_off0_8816CE90, u32@0x90, fn_8822C898 */
void ts4_if_call_seq_u32_off94_8874B920(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)-1;
    loc50[0] = (ts4_word)((2020933632) | 43525);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t2 == (ts4_word)((983040) | 65535)) {
        p5 = (ts4_word)10;
    } else {
        t3 = ts4_if_get_u32_off0_8816CE90((ts4_word)t1);
        p5 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)p5;
    fn_8822C898((ts4_word)(a0 + 128), (ts4_word)p5);
    (void)sp1.w[2];
    ts4_call_seq_fn_88731540_8873B940((ts4_word)a0, sp1);
    return;
}

/* Swing_DLL.xex 0x8875A408: get u32@lbl_88D45A4C, u32@lbl_88D45AD4, u32@0x154, u32@0x4, vcall, ts4_if_get_u8_off0_8873B7E8 */
void ts4_get_u32_lbl_88D45A4C_8875A408(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45A4C;
    t2 = *(ts4_word *)lbl_88D45AD4;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 4))))((ts4_word)(t1 + 340));
    ts4_if_get_u8_off0_8873B7E8((ts4_word)t2);
    fn_8875A0F0((ts4_word)(t2 + 236), *(ts4_args3 *)((char *)(ts4_word)(t2) + 164));
    ts4_if_get_u8_off0_886F2460((ts4_word)t2);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 340))) + 8))))((ts4_word)(t1 + 340));
    return;
}

/* Swing_DLL.xex 0x8875F488: loop_get u32@0x1c, ts4_loop_get_u32_off1c_88718480, u32@0x1c, u32@0x50, ts4_loop_get_u32_off0_886F5700, u32@0x1c */
void ts4_loop_get_u32_off1c_8875F488(ts4_word a0)
{
    ts4_word lv10;
    ts4_word p16;
    ts4_word lv34;
    ts4_word p40;
    int t1;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t15;
    ts4_word t22;
    ts4_word t32;
    ts4_word t33;
    ts4_word t35;
    ts4_word t39;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 != 0) {
        ts4_loop_get_u32_off1c_88718480((ts4_word)(t1 + 336));
        ts4_loop_get_u32_off0_886F5700((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80)));
        fn_8873B890((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        if ((ts4_word)t9 != (ts4_word)t8) {
            lv10 = (ts4_word)t9;
            do {
                t11 = *(ts4_word *)((char *)(ts4_word)(lv10) + 0);
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 8))))((ts4_word)t11);
                t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
                p16 = (ts4_word)(lv10 + 4);
                lv10 = p16;
            } while ((ts4_word)p16 != (ts4_word)t15);
        }
        fn_8875B680((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 108)));
        t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t22) + 0))) + 0))))((ts4_word)t22);
        fn_88739110((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 32)));
        fn_88758DA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 108)));
        t32 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        t33 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((ts4_word)t33 != (ts4_word)t32) {
            lv34 = (ts4_word)t33;
            do {
                t35 = *(ts4_word *)((char *)(ts4_word)(lv34) + 0);
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t35) + 0))) + 8))))((ts4_word)t35);
                t39 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
                p40 = (ts4_word)(lv34 + 4);
                lv34 = p40;
            } while ((ts4_word)p40 != (ts4_word)t39);
        }
        fn_8875EB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    }
    return;
}

/* Swing_DLL.xex 0x88771440: call_seq lbl_880EFA80, fn_88608590, u32@lbl_88D45B20, ts4_keyed_item_add_or_remove_8876FD58, lbl_880EFA9C, fn_88608590 */
void ts4_call_seq_lbl_880EFA80_88771440(ts4_word a0)
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

    t1 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFA80);
    loc50[0] = (ts4_word)t1;
    ts4_keyed_item_add_or_remove_8876FD58((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFA9C);
    loc50[0] = (ts4_word)t4;
    ts4_keyed_item_add_or_remove_887701A8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t7 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFAB4);
    loc50[0] = (ts4_word)t7;
    ts4_keyed_item_add_or_remove_88770AB0((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t10 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFAD8);
    loc50[0] = (ts4_word)t10;
    ts4_keyed_item_add_or_remove_88770B90((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t13 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFAF0);
    loc50[0] = (ts4_word)t13;
    ts4_keyed_item_add_or_remove_88770D50((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t16 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFB08);
    loc50[0] = (ts4_word)t16;
    ts4_keyed_item_add_or_remove_887700C8((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t19 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFB20);
    loc50[0] = (ts4_word)t19;
    ts4_keyed_item_add_or_remove_88770750((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t22 = fn_88608590((ts4_word)0, (ts4_word)(ts4_word)lbl_880EFB38);
    loc50[0] = (ts4_word)t22;
    ts4_keyed_item_add_or_remove_8876FE38((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x887717A8: if_call_seq u32@0x10, u32@0x14, u32@0xc, fn_88771618, u8@0x69, u32@0x0 */
void ts4_if_call_seq_u32_off10_887717A8(ts4_word a0, int a1, int a2)
{
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    t2 = fn_88771618((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    *(float *)((char *)(ts4_word)(a0) + 8) = t2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 105) = (unsigned char)1;
    if ((int)a2 == -1 || (int)a1 >= (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))) {
        fn_8876D8D8((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x88771808: if_call_seq u32@0x10, u32@0x14, u32@0xc, fn_88771618, u8@0x69, u32@0x0 */
void ts4_if_call_seq_u32_off10_88771808(ts4_word a0, int a1, int a2)
{
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    t2 = fn_88771618((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    *(float *)((char *)(ts4_word)(a0) + 8) = t2;
    *(unsigned char *)((char *)(ts4_word)(a0) + 105) = (unsigned char)1;
    if ((int)a2 == -1 || (int)a1 >= (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))) {
        fn_8876D970((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x88775380: loop_get fn_887744D8, fn_8876DF40, u32@0x50, u32@0x4c, u32@0x0, u32@0xb8 */
void ts4_loop_get_fn_887744D8_88775380(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p18;
    ts4_word lv24;
    ts4_word p37;
    ts4_word lv43;
    ts4_word p49;
    ts4_word lv56;
    ts4_word p62;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    int t7;
    int t8;
    ts4_word t9;
    float t10;
    int t13;
    ts4_word t17;
    ts4_word t22;
    ts4_word t23;
    ts4_word t25;
    int t26;
    int t27;
    ts4_word t28;
    float t29;
    int t32;
    ts4_word t36;
    ts4_word t41;
    ts4_word t42;
    ts4_word t44;
    ts4_word t48;
    ts4_word t53;
    ts4_word t54;
    ts4_word t55;
    ts4_word t57;
    ts4_word t61;

    fn_887744D8((ts4_word)(a0 + 148));
    fn_8876DF40((ts4_word)(a0 + 168));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t4 != (ts4_word)t3) {
        lv5 = (ts4_word)t4;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
            t9 = *(ts4_word *)((char *)(ts4_word)(t6) + 12);
            *(ts4_word *)((char *)(ts4_word)(t6) + 20) = (ts4_word)t7;
            *(ts4_word *)((char *)(ts4_word)(t6) + 16) = (ts4_word)t8;
            t10 = fn_88771618((ts4_word)t6, (ts4_word)t9);
            *(float *)((char *)(ts4_word)(t6) + 8) = t10;
            *(unsigned char *)((char *)(ts4_word)(t6) + 105) = (unsigned char)1;
            if ((int)t7 != -1) {
                t13 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 32);
                if ((int)t8 >= (int)t13) {
                    fn_8876D970((ts4_word)t6);
                }
            } else {
                fn_8876D970((ts4_word)t6);
            }
            t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
            p18 = (ts4_word)(lv5 + 4);
            lv5 = p18;
        } while ((ts4_word)p18 != (ts4_word)t17);
    }
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t22 != (ts4_word)t23) {
        lv24 = (ts4_word)t22;
        do {
            t25 = *(ts4_word *)((char *)(ts4_word)(lv24) + 0);
            t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
            t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
            t28 = *(ts4_word *)((char *)(ts4_word)(t25) + 12);
            *(ts4_word *)((char *)(ts4_word)(t25) + 20) = (ts4_word)t26;
            *(ts4_word *)((char *)(ts4_word)(t25) + 16) = (ts4_word)t27;
            t29 = fn_88771618((ts4_word)t25, (ts4_word)t28);
            *(float *)((char *)(ts4_word)(t25) + 8) = t29;
            *(unsigned char *)((char *)(ts4_word)(t25) + 105) = (unsigned char)1;
            if ((int)t26 != -1) {
                t32 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t25) + 0))) + 32);
                if ((int)t27 >= (int)t32) {
                    fn_8876D8D8((ts4_word)t25);
                }
            } else {
                fn_8876D8D8((ts4_word)t25);
            }
            t36 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
            p37 = (ts4_word)(lv24 + 4);
            lv24 = p37;
        } while ((ts4_word)p37 != (ts4_word)t36);
    }
    t41 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t42 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t41 != (ts4_word)t42) {
        lv43 = (ts4_word)t41;
        do {
            t44 = *(ts4_word *)((char *)(ts4_word)(lv43) + 0);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t44) + 0))) + 8))))((ts4_word)t44);
            t48 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
            p49 = (ts4_word)(lv43 + 4);
            lv43 = p49;
        } while ((ts4_word)p49 != (ts4_word)t48);
    }
    t53 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 196))) + 0);
    if ((ts4_word)t53 != (ts4_word)((499777536) | 29317)) {
        t54 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
        t55 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        if ((ts4_word)t54 != (ts4_word)t55) {
            lv56 = (ts4_word)t54;
            do {
                t57 = *(ts4_word *)((char *)(ts4_word)(lv56) + 0);
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t57) + 0))) + 8))))((ts4_word)t57);
                t61 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
                p62 = (ts4_word)(lv56 + 4);
                lv56 = p62;
            } while ((ts4_word)p62 != (ts4_word)t61);
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 192)) + 1);
    return;
}

/* Swing_DLL.xex 0x88779E30: loop_call_seq u32@0xb0, u32@0xac, u32@0x4, u32@0x0, u32@-0xc, u32@-0xc */
void ts4_loop_call_seq_u32_offb0_88779E30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    int t6;
    int t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 4);
            t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            t6 = *(ts4_word *)((char *)(ts4_word)(t4) + -12);
            t7 = *(ts4_word *)((char *)(ts4_word)(t5) + -12);
            if ((int)t6 != (int)t7) {
                p9 = (ts4_word)0;
            } else {
                t8 = fn_885630C0((ts4_word)t4, (ts4_word)t5, (ts4_word)t6);
                p9 = (ts4_word)(t8 == 0);
            }
            if ((ts4_word)(p9 & 0xff) != 0) {
                *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0));
                return;
            }
            p12 = (ts4_word)(lv3 + 8);
            lv3 = p12;
        } while ((ts4_word)t1 != (ts4_word)p12);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x887993C8: if_set u32@0x314, u32@lbl_88D45B0C, lbl_880D1EB8, fn_8886B1B0, ts4_if_call_seq_u32_lbl_88D459E4_8883F238, u32@0x0 */
void ts4_if_set_u32_off314_887993C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 788) = (ts4_word)a1;
    t1 = *(ts4_word *)lbl_88D45B0C;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8886B1B0((ts4_word)a1, (ts4_word)(ts4_word)&loc60[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880D1EB8, (ts4_word)1);
        t3 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t2);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)(ts4_word)&loc60[0], (ts4_word)3072, (ts4_word)0);
            t7 = loc50[0];
            if ((ts4_word)t7 != 0) {
                fn_88657120((ts4_word)(*(ts4_word *)lbl_88D45B0C), (ts4_word)t7, (ts4_word)a1);
                t10 = loc50[0];
                t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 88))))((ts4_word)t11, (ts4_word)(ts4_word)&loc50[0]);
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x887BEB60: if_call_seq u8@0xc4, u32@lbl_88D41FC4, u32@0x6c, ts4_loop_call_seq_u32_off10_88202BF8, u8@0xc4 */
void ts4_if_call_seq_u8_offc4_887BEB60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 196);
    if ((ts4_word)t1 != 0) {
        ts4_loop_call_seq_u32_off10_88202BF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 108)), (ts4_word)((501481472) | 29513));
        *(unsigned char *)((char *)(ts4_word)(a0) + 196) = (unsigned char)0;
    }
    return;
}

/* Swing_DLL.xex 0x887D5CB8: if_call_seq u32@0x0, u32@0x24, u32@0x0, ts4_memset, ts4_memset, u32@0x0 */
void ts4_if_call_seq_u32_off0_887D5CB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t6;

    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t2 == (ts4_word)((80281600) | 473)) {
        ts4_memset((ts4_word)(a0 + 28), (ts4_word)0, (ts4_word)4);
        ts4_memset((ts4_word)(a0 + 32), (ts4_word)0, (ts4_word)4);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t6 == (ts4_word)((1792475136) | 11351) || (ts4_word)t6 == (ts4_word)((375062528) | 48617)) {
        fn_887D2960((ts4_word)a0, (ts4_word)0);
    }
    return;
}

/* Swing_DLL.xex 0x887E5D40: if_call_seq u32@lbl_88D45AF0, u8@0x44, u32@0x58, fn_887D9C90, fn_887E5898 */
void ts4_if_call_seq_u32_lbl_88D45AF0_887E5D40(ts4_word a0)
{
    ts4_word loc50[4];
    unsigned char t2;
    ts4_word t3;
    ts4_word t4;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AF0)) + 68);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
        t4 = fn_887D9C90((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
        fn_887E5898((ts4_word)t3, (ts4_word)t4);
    }
    return;
}

/* Swing_DLL.xex 0x887E7EF0: if_call_seq u32@0xa8, u8@0x255, u32@0x11c, u8@0x96, u8@0xcd, u8@0xcd */
void ts4_if_call_seq_u32_offa8_887E7EF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[2];
    ts4_word t2;
    unsigned char t3;
    ts4_word t15;
    unsigned char t5;
    unsigned char t7;
    unsigned char t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 168))) + 597) = (unsigned char)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 150);
    if ((ts4_word)t3 != 0) {
        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
        *(unsigned char *)((char *)(ts4_word)(a0) + 782) = (unsigned char)1;
        fn_88171F50((ts4_word)(t15 + 160), (ts4_word)(t2 + 144));
    } else {
        t5 = *(unsigned char *)((char *)(ts4_word)(t2) + 205);
        if ((ts4_word)t5 != 0) {
            t7 = *(unsigned char *)((char *)(ts4_word)(t2) + 214);
            if ((ts4_word)t7 != 0) {
                *(unsigned char *)((char *)(ts4_word)(a0) + 98) = (unsigned char)1;
            }
            t9 = *(unsigned char *)((char *)(ts4_word)(t2) + 215);
            if ((ts4_word)t9 != 0) {
                loc50[0] = (ts4_word)((3556769792) | 59237);
                fn_887E0540((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0);
                *(ts4_word *)((char *)(ts4_word)(a0) + 428) = (ts4_word)7;
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 782) = (unsigned char)0;
            fn_887E72E0((ts4_word)a0, (ts4_word)1, (ts4_word)0);
        }
    }
    return;
}

/* Swing_DLL.xex 0x887EA320: loop_get u32@0x1c, u32@lbl_88D45B38, fn_88883CD0, u32@0xc, u32@0x4, u8@0x20 */
void ts4_loop_get_u32_off1c_887EA320(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    unsigned char t8;
    ts4_word t9;
    ts4_word t13;
    ts4_word t14;
    unsigned char t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)lbl_88D45B38;
    t3 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
    }
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t2) + 32) = (unsigned char)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t5 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 16) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t4;
    }
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)), (ts4_word)-1);
    t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t8 == 0) {
        do {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 12))))((ts4_word)t9);
            t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
            t14 = *(ts4_word *)((char *)(ts4_word)(t13) + 24);
            if ((ts4_word)t14 == (ts4_word)((3751936000) | 45041)) {
                *(ts4_word *)((char *)(ts4_word)(t13) + 8) = (ts4_word)3;
            } else {
                *(ts4_word *)((char *)(ts4_word)(t13) + 8) = (ts4_word)4;
            }
            ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)), (ts4_word)-1);
            t17 = *(unsigned char *)((char *)(ts4_word)(a0) + 104);
        } while ((ts4_word)t17 == 0);
    }
    return;
}

/* Swing_DLL.xex 0x887EF358: if_call_seq u32@0x1d8, u32@0x1cc, u32@0x1c, fn_887EEFF0, u32@0x1c, u32@0x1d8 */
void ts4_if_call_seq_u32_off1d8_887EF358(ts4_word a0)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    int t9;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 472);
    if ((ts4_word)t1 >= 1) {
        if ((ts4_word)t1 != 1) {
            if ((ts4_word)t1 < 3) {
                t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 460);
                if ((int)t9 != 0) {
                    if ((int)t9 == 1) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)2;
                        fn_887EDAF0();
                        fn_887EDDE8((ts4_word)a0, (ts4_word)(a0 + 32));
                    } else {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)3;
                        fn_887EDDE8((ts4_word)a0, (ts4_word)(a0 + 32));
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)0;
                }
            }
        } else {
            t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 460);
            if ((int)t2 != 0) {
                if ((int)t2 == 1) {
                    t3 = fn_887EEFF0((ts4_word)a0);
                    if ((ts4_word)(t3 & 0xff) != 0) {
                        p4 = (ts4_word)2;
                    } else {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)3;
                        p4 = (ts4_word)0;
                    }
                    p5 = (ts4_word)p4;
                } else {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)3;
                    p5 = (ts4_word)0;
                }
                *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)p5;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x887F0728: loop_get u8@0x7, u32@lbl_88D45930, u32@0x20, u32@0x40, u32@0x3c, u32@0x54 */
void ts4_loop_get_u8_off7_887F0728(ts4_word a0)
{
    ts4_word lv6;
    ts4_word p19;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    unsigned short t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    unsigned char t14;
    unsigned short t15;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 7);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)lbl_88D45930;
        if ((ts4_word)t2 != 0) {
            t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 32);
            t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 64);
            lv6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 60));
            while ((ts4_word)lv6 != (ts4_word)t4) {
                t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
                t8 = *(unsigned short *)((char *)(ts4_word)(lv6) + 0);
                t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 92);
                t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 608);
                if ((ts4_word)t8 == (ts4_word)t10 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(lv6) + 6)) == (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16))) {
                    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                    t14 = *(unsigned char *)((char *)(ts4_word)(lv6) + 7);
                    t15 = *(unsigned short *)((char *)(ts4_word)(lv6) + 2);
                    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t13) + 24))))((ts4_word)a0, (ts4_word)t15, (ts4_word)t14, (ts4_word)0, (ts4_word)1, (ts4_word)t10, (ts4_word)t9);
                }
                p19 = (ts4_word)(lv6 + 8);
                lv6 = p19;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x887F1718: if_get u8@0x2c, u32@0xc, u32@lbl_88C6BEF4, u32@0xc, u32@lbl_88C6BEF4, u32@lbl_88C6BF0C */
void ts4_if_get_u8_off2c_887F1718(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;
    ts4_word t8;
    ts4_word t9;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 44);
    if ((ts4_word)t1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t5 = *(ts4_word *)lbl_88C6BEF4;
        if ((ts4_word)t4 != (ts4_word)t5 && (ts4_word)t4 != (ts4_word)(*(ts4_word *)lbl_88C6BF0C)) {
            t12 = *(ts4_word *)lbl_88C6BEFC;
            if ((ts4_word)t4 == (ts4_word)t12 || (ts4_word)t4 == (ts4_word)(*(ts4_word *)lbl_88C6BF04)) {
                t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                t15 = fn_887F0CA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C6C00C);
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 68))))((ts4_word)a0, (ts4_word)t15, (ts4_word)0);
            }
        } else {
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
            t9 = fn_887F0CA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C6C010);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 68))))((ts4_word)a0, (ts4_word)t9, (ts4_word)0);
        }
    }
    return;
}

/* Swing_DLL.xex 0x887F78F0: loop_get u32@0x2c, u32@0x30, u32@0x0, u32@0x0, u32@0x20, vcall */
void ts4_loop_get_u32_off2c_887F78F0(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)t4);
            }
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t9);
    }
    return;
}

/* Swing_DLL.xex 0x888085E0: call_seq lbl_880E2FE4, ts4_call_seq_fn_88832F70_88806570, lbl_880E2FF4, ts4_call_seq_fn_88832F70_88806570, ts4_if_call_seq_lbl_880E2FD4_88806650, ts4_if_call_seq_lbl_880E2FBC_88806718 */
void ts4_call_seq_lbl_880E2FE4_888085E0(ts4_word a0)
{
    ts4_call_seq_fn_88832F70_88806570((ts4_word)(ts4_word)lbl_880E2FE4, (ts4_word)a0);
    ts4_call_seq_fn_88832F70_88806570((ts4_word)(ts4_word)lbl_880E2FF4, (ts4_word)a0);
    ts4_if_call_seq_lbl_880E2FD4_88806650((ts4_word)a0);
    ts4_if_call_seq_lbl_880E2FBC_88806718((ts4_word)a0);
    ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0((ts4_word)(ts4_word)lbl_88C69F78, (ts4_word)36, (ts4_word)(ts4_word)lbl_880E2FA8, (ts4_word)a0);
    ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0((ts4_word)(ts4_word)lbl_88C69E60, (ts4_word)35, (ts4_word)(ts4_word)lbl_880E2F94, (ts4_word)a0);
    ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0((ts4_word)(ts4_word)lbl_88C6A098, (ts4_word)5, (ts4_word)(ts4_word)lbl_880E2F80, (ts4_word)a0);
    ts4_loop_call_seq_ts4_call_seq_u32_off0_88832F70_888064A0((ts4_word)(ts4_word)lbl_88C6A0C0, (ts4_word)5, (ts4_word)(ts4_word)lbl_880E2F64, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x8880BD50: if_get u32@0x0, u32@0x28, vcall, u32@0x3c, ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60 */
void ts4_if_get_u32_off0_8880BD50(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p8;
    ts4_word loc50[2];
    ts4_word loc58[3];
    int t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((int)t4 == 0) {
        loc50[0] = (ts4_word)((2026110976) | 52102);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
        t6 = loc58[1];
        if ((ts4_word)t6 == (ts4_word)((983040) | 65535)) {
            p8 = (ts4_word)0;
        } else {
            t7 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
            p8 = (ts4_word)t7;
        }
        t9 = ts4_if_addr_lbl_880E17D8_88836040((ts4_word)((p8 & 0xff) == 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t9;
    }
    fn_888052F0((ts4_word)a0);
    ts4_lua_register_methods_88805E58((ts4_word)a0);
    ts4_lua_register_methods_88805F80((ts4_word)a0);
    ts4_lua_register_methods_88806210((ts4_word)a0);
    ts4_lua_register_methods_88805D68((ts4_word)a0);
    ts4_lua_register_methods_888060C8((ts4_word)a0);
    ts4_lua_register_methods_88805B48((ts4_word)a0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    (void)sp1.w[2];
    fn_88804240((ts4_word)a0, sp1);
    return;
}

/* Swing_DLL.xex 0x88834CC8: if_get u32@0x4, u8@0x8, u8@0x8, fn_88566FE8 */
void ts4_if_get_u32_off4_88834CC8(ts4_word a0)
{
    ts4_word t1;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 == 0) {
        return;
    }
    fn_88566FE8((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88834D78: if_get u32@0x4, lbl_880E1880, u32@0x0, u8@0x8, u8@0x8, fn_88566FE8 */
void ts4_if_get_u32_off4_88834D78(ts4_word a0)
{
    ts4_word t1;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1880;
    if ((ts4_word)t1 == 0) {
        return;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 == 0) {
        return;
    }
    fn_88566FE8((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x8884CCB8: if_call_seq fn_88627EC0, u32@lbl_88D45B1C, u32@0x2bc, u32@0x48, ts4_find_service, u32@0x4c */
void ts4_if_call_seq_fn_88627EC0_8884CCB8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word p8;
    ts4_word loc50[3];
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 700));
    t5 = ts4_find_service((ts4_word)((1101463552) | 35577));
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)t5;
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t7) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)(ts4_word)lbl_880E1674;
        p8 = (ts4_word)t7;
    } else {
        p8 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)p8;
    ts4_hash_find_pair_88848CA0((ts4_word)p8);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    t10 = *(ts4_word *)lbl_88D458F0;
    loc50[2] = (ts4_word)0;
    t11 = ts4_hash_find_881AB900((ts4_word)t10, (ts4_word)((3773562880) | 15243), *(ts4_args3 *)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)t11;
    return;
}

/* Swing_DLL.xex 0x888536B8: loop_call_seq u32@0x24, u32@0x20, u32@0x0, u32@0x8c, u32@0x180, fn_88852548 */
void ts4_loop_call_seq_u32_off24_888536B8(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 140)) != 0) {
            fn_88852548((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 384)));
        }
        p9 = (ts4_word)(lv3 + 4);
        lv3 = p9;
    }
    return;
}

/* Swing_DLL.xex 0x888621C0: loop_call_seq u32@0x3c, lbl_88C6A128, u32@0x0, fn_881B18E0, u32@0x0, fn_888368B0 */
void ts4_loop_call_seq_u32_off3c_888621C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    lv2 = (ts4_word)((ts4_word)lbl_88C6A128 + -4);
    lv3 = (ts4_word)97;
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
    return;
}

/* Swing_DLL.xex 0x88869E80: if_call_seq fn_88868A88, u8@0x85, fn_88869690, fn_88868B48, u8@0x7e, fn_88868B48 */
void ts4_if_call_seq_fn_88868A88_88869E80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t6;
    ts4_word t5;
    ts4_word t4;
    ts4_word t1;

    if ((ts4_word)a1 == (ts4_word)((3556769792) | 59237)) {
        fn_888697B0((ts4_word)a0, (ts4_word)a2);
        return;
    }
    if ((ts4_word)a1 != (ts4_word)((3572826112) | 65486) && (ts4_word)a1 != (ts4_word)((1563033600) | 1414)) {
        if ((ts4_word)a1 == (ts4_word)((3394109440) | 60957)) {
            fn_88869830((ts4_word)a0, (ts4_word)a2);
            return;
        }
        if ((ts4_word)a1 != (ts4_word)((2501050368) | 33759)) {
            if ((ts4_word)a1 == (ts4_word)((995360768) | 58411)) {
                t6 = fn_88868B48((ts4_word)a0);
                if ((ts4_word)t6 != 0) {
                    *(unsigned char *)((char *)(ts4_word)(t6) + 124) = (unsigned char)a2;
                    return;
                }
                return;
            }
            if ((ts4_word)a1 == (ts4_word)((2724003840) | 46481)) {
                t5 = fn_88868B48((ts4_word)a0);
                if ((ts4_word)t5 != 0) {
                    *(unsigned char *)((char *)(ts4_word)(t5) + 125) = (unsigned char)a2;
                    return;
                }
                return;
            }
            if ((ts4_word)a1 == (ts4_word)((3579445248) | 34055)) {
                t4 = fn_88868B48((ts4_word)a0);
                if ((ts4_word)t4 != 0) {
                    *(unsigned char *)((char *)(ts4_word)(t4) + 126) = (unsigned char)a2;
                    return;
                }
                return;
            }
            if ((ts4_word)a1 == (ts4_word)((1213923328) | 46648)) {
                fn_88869690((ts4_word)a0, (ts4_word)a2);
                return;
            }
            if ((ts4_word)a1 == (ts4_word)((1347420160) | 13321)) {
                t1 = fn_88868A88((ts4_word)a0);
                if ((ts4_word)t1 != 0) {
                    *(unsigned char *)((char *)(ts4_word)(t1) + 133) = (unsigned char)a2;
                }
            }
            return;
        }
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8886B520: if_call_seq u32@lbl_88D45B1C, u32@0x234, fn_88614938, u8@0x1a, u32@g_ts4_session_state, fn_881AB830 */
void ts4_if_call_seq_u32_lbl_88D45B1C_8886B520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a2);
    if ((ts4_word)t3 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t3) + 26)) != 0) {
        t6 = fn_881AB830((ts4_word)(*(ts4_word *)g_ts4_session_state), (ts4_word)((3846111232) | 7677));
        t7 = *(ts4_word *)g_ts4_session_state;
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
        *(ts4_word *)((char *)(ts4_word)(t8) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 + 7) << 2)) + a0));
        *(ts4_word *)((char *)(ts4_word)(t8) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 16));
        fn_88151560((ts4_word)t7, (ts4_word)t6);
        fn_888F67B8((ts4_word)a2, (ts4_word)(*(ts4_word *)lbl_88D45B34));
    }
    return;
}

/* Swing_DLL.xex 0x8886C680: if_call_seq ts4_find_service, fn_88611620, fn_8886C1C0 */
void ts4_if_call_seq_ts4_find_service_8886C680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 != 0) {
        t1 = ts4_find_service((ts4_word)((3803054080) | 35129));
        t2 = fn_88611620((ts4_word)t1, (ts4_word)a1);
        fn_8886C1C0((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)0);
    }
    return;
}

/* Swing_DLL.xex 0x88885308: call_seq fn_885820B0, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_call_seq_fn_885820B0_88885308(ts4_word a0)
{
    ts4_word loc50[4];
    unsigned short t2;
    unsigned short t3;
    unsigned short t4;
    unsigned short t5;
    unsigned short t6;
    unsigned short t7;
    unsigned short t8;
    unsigned short t9;

    fn_885820B0((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(unsigned short *)((char *)loc50 + 10);
    t3 = *(unsigned short *)((char *)loc50 + 12);
    t4 = *(unsigned short *)((char *)loc50 + 14);
    t5 = *(unsigned short *)((char *)loc50 + 0);
    t6 = *(unsigned short *)((char *)loc50 + 2);
    t7 = *(unsigned short *)((char *)loc50 + 4);
    t8 = *(unsigned short *)((char *)loc50 + 6);
    t9 = *(unsigned short *)((char *)loc50 + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t9;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t4;
    return;
}

/* Swing_DLL.xex 0x88885388: call_seq fn_88582018, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_call_seq_fn_88582018_88885388(ts4_word a0)
{
    ts4_word loc50[4];
    unsigned short t2;
    unsigned short t3;
    unsigned short t4;
    unsigned short t5;
    unsigned short t6;
    unsigned short t7;
    unsigned short t8;
    unsigned short t9;

    fn_88582018((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(unsigned short *)((char *)loc50 + 10);
    t3 = *(unsigned short *)((char *)loc50 + 12);
    t4 = *(unsigned short *)((char *)loc50 + 14);
    t5 = *(unsigned short *)((char *)loc50 + 0);
    t6 = *(unsigned short *)((char *)loc50 + 2);
    t7 = *(unsigned short *)((char *)loc50 + 4);
    t8 = *(unsigned short *)((char *)loc50 + 6);
    t9 = *(unsigned short *)((char *)loc50 + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t9;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t4;
    return;
}

/* Swing_DLL.xex 0x888890D0: get fn_88628C48, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, fn_8816CAA0 */
void ts4_get_fn_88628C48_888890D0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    (void)sp1.w[2];
    fn_88628C48((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((3066429440) | 22117);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    t5 = loc58[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)1);
    fn_8816CAA0((ts4_word)(a0 + 36), (ts4_word)t8);
    *(ts4_word *)lbl_88C6A45C = (ts4_word)4;
    return;
}

/* Swing_DLL.xex 0x88890590: if_get u32@0x1c, fn_888903D8 */
void ts4_if_get_u32_off1c_88890590(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 == 0) {
        return;
    }
    fn_888903D8((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88890670: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off8_88890670(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 2) + t1)) + 4);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((a1 + (a1 << 1)) << 2) + t1)) + 0));
    while ((ts4_word)lv4 != (ts4_word)t2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 4);
        t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t8 = *(ts4_word *)((char *)(ts4_word)(t5) + 44);
        t9 = ts4_loop_get_u32_off0_88402150((ts4_word)t5);
        t11 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t11))((ts4_word)t6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0)), (ts4_word)t8, (ts4_word)t7);
        p14 = (ts4_word)(lv4 + 8);
        lv4 = p14;
    }
    return;
}

/* Swing_DLL.xex 0x88890EE8: call_seq ts4_handle_forward_88150770, ts4_if_get_u32_off0_8816CE90, ts4_handle_forward_88150770, ts4_if_get_u32_off0_8816CE90 */
void ts4_call_seq_ts4_handle_forward_88150770_88890EE8(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t3;

    loc50[0] = (ts4_word)((4258856960) | 55657);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_get_u32_off0_8816CE90((ts4_word)t1);
    loc54[0] = (ts4_word)((126550016) | 42205);
    t3 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc54[0]);
    ts4_if_get_u32_off0_8816CE90((ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x888BA500: if_call_seq u32@0x8, u32@0x0, u32@lbl_88D45B1C, u32@0x104, u32@0x234, u32@0x34 */
void ts4_if_call_seq_u32_off8_888BA500(ts4_word a0)
{
    ts4_word p11;
    ts4_word p12;
    int t1;
    ts4_word t2;
    ts4_word t3;
    int t4;
    ts4_word t5;
    int t6;
    int t9;
    ts4_word t14;
    unsigned short t15;
    unsigned short t20;
    unsigned short t25;
    unsigned short t30;
    unsigned short t35;
    unsigned short t40;
    unsigned short t45;
    unsigned short t50;
    unsigned short t55;
    unsigned short t60;
    unsigned short t65;
    unsigned short t70;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t3 = *(ts4_word *)lbl_88D45B1C;
        t4 = *(ts4_word *)((char *)(ts4_word)((t2 + t1)) + 260);
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 564);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 52);
        if ((int)t4 < (int)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 48))) + (t4 << 2));
            p11 = (ts4_word)t9;
            if ((int)t9 == -1) {
                p11 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 28));
            }
            p12 = (ts4_word)p11;
        } else {
            p12 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 28));
        }
        t14 = *(ts4_word *)((char *)(ts4_word)(t5) + 60);
        t15 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 72);
        if ((ts4_word)(t15 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 120)));
        }
        t20 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 76);
        if ((ts4_word)(t20 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 124)));
        }
        t25 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 80);
        if ((ts4_word)(t25 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 128)));
        }
        t30 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 84);
        if ((ts4_word)(t30 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 132)));
        }
        t35 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 48);
        if ((ts4_word)(t35 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 96)));
        }
        t40 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 52);
        if ((ts4_word)(t40 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 100)));
        }
        t45 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 56);
        if ((ts4_word)(t45 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 104)));
        }
        t50 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 60);
        if ((ts4_word)(t50 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 108)));
        }
        t55 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 64);
        if ((ts4_word)(t55 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 112)));
        }
        t60 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 68);
        if ((ts4_word)(t60 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 116)));
        }
        t65 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 92);
        if ((ts4_word)(t65 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 140)));
        }
        t70 = *(unsigned short *)((char *)(ts4_word)((((int)p12 * 196) + t14)) + 88);
        if ((ts4_word)(t70 & 0x40) == 64) {
            fn_888B9E40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 136)));
        }
    }
    return;
}

/* Swing_DLL.xex 0x888BB500: get fn_888B8F58, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall, fn_8862BE08 */
void ts4_get_fn_888B8F58_888BB500(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;

    (void)sp1.w[2];
    fn_888B8F58((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((2749431808) | 30809);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    t5 = loc58[1];
    t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 80))))((ts4_word)t4, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t5, (ts4_word)1);
    fn_8862BE08((ts4_word)(ts4_word)&loc68[0], (ts4_word)t8);
    t10 = loc68[0];
    t11 = loc68[1];
    t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 40))))((ts4_word)t10, (ts4_word)(ts4_word)&loc68[0], (ts4_word)t11, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t14;
    return;
}

/* Swing_DLL.xex 0x888C0970: if_call_seq u8@0x1c, u32@0x28, u32@0x10c, ts4_find_service, u32@0x28, u8@0x1c */
void ts4_if_call_seq_u8_off1c_888C0970(ts4_word a0)
{
    ts4_word p6;
    unsigned char t1;
    ts4_word t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 == 0) {
        t4 = ts4_find_service((ts4_word)((2989293568) | 3617));
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t4;
        *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 268));
    } else {
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 268));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)p6;
    return;
}

/* Swing_DLL.xex 0x888C2CC8: if_get u32@0x8, ts4_find_service, u32@0x0, u32@0x34, vcall, u32@0x154 */
void ts4_if_get_u32_off8_888C2CC8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t6;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    t2 = ts4_find_service((ts4_word)((2027552768) | 37131));
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 52))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
        t6 = loc50[0];
        if ((ts4_word)t6 == (ts4_word)((2812346368) | 35025)) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 1072) = (ts4_word)0;
        }
    }
    return;
}

/* Swing_DLL.xex 0x888C2D40: if_get u32@0x8, ts4_find_service, u32@0x0, u32@0x2c, vcall, u32@0x154 */
void ts4_if_get_u32_off8_888C2D40(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    t2 = ts4_find_service((ts4_word)((2027552768) | 37131));
    if ((ts4_word)t2 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 44))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
        t6 = loc50[0];
        if ((ts4_word)t6 == (ts4_word)((2812346368) | 35025)) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 340);
            *(ts4_word *)((char *)(ts4_word)(t7) + 1072) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 308));
        }
    }
    return;
}

/* Swing_DLL.xex 0x888C3220: loop_call_seq u32@0x20, u8@0x1c, ts4_tailcall_fn_88582F30_8857A128, u32@0x20, lbl_88D3EB60, u32@0x0 */
void ts4_loop_call_seq_u32_off20_888C3220(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p7;
    int t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    if ((int)t1 != 0) {
        ts4_tailcall_fn_88582F30_8857A128((ts4_word)t1, (ts4_word)-1);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        lv4 = (ts4_word)(ts4_word)lbl_88D3EB60;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            if ((ts4_word)t3 == (ts4_word)t6) {
                *(ts4_word *)((char *)(ts4_word)(lv4) + 0) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(lv4) + 4) = (ts4_word)0;
                break;
            }
            p7 = (ts4_word)(lv4 + 520);
            lv4 = p7;
        } while ((ts4_word)p7 != (ts4_word)((ts4_word)lbl_88D3EB60 + 13000));
        ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x888C6FE0: if_get u32@0x5c, u8@0x265, u32@0x8, u32@lbl_88D4592C, u32@0x4c, u32@0x2c */
void ts4_if_get_u32_off5c_888C6FE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 613)) != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t4 = *(ts4_word *)lbl_88D4592C;
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 76);
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 44);
        t7 = ((ts4_word (*)(ts4_word, ts4_word))(t5))((ts4_word)(a0 + 8), (ts4_word)0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)(t7 + 12), (ts4_word)0);
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 20))))((ts4_word)t11);
        *(unsigned char *)((char *)(ts4_word)(a0) + 613) = (unsigned char)0;
    }
    return;
}

/* Swing_DLL.xex 0x888CCBE8: if_get u32@0x5c, u8@0x265, u32@0x60, u32@0x0, u32@0x28, vcall */
void ts4_if_get_u32_off5c_888CCBE8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    unsigned char t9;
    ts4_word t15;
    ts4_word t16;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 613)) == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)(a0 + 100), (ts4_word)1, (ts4_word)0);
        t7 = loc50[0];
        if ((ts4_word)t7 != 0) {
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
            t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 612);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 92))))((ts4_word)t8, (ts4_word)t7, (ts4_word)(a0 + 100), (ts4_word)t9);
            t15 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 76))))((ts4_word)(a0 + 8), (ts4_word)0);
            t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
            fn_88617788((ts4_word)t16, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t15) + 12)));
            t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
            ts4_if_call_seq_u32_off8_8817E578((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D4592C)) + 44)), (ts4_word)t19, (ts4_word)1);
            *(unsigned char *)((char *)(ts4_word)(a0) + 613) = (unsigned char)1;
        }
    }
    return;
}

/* Swing_DLL.xex 0x888CDB38: get ts4_handle_forward_88610778, ts4_init_range_and_run_service_opt_88164450, u32@0x0, u32@0x4, u32@0x0, u32@0x28 */
void ts4_get_ts4_handle_forward_88610778_888CDB38(ts4_args3 sp0)
{
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word loc68[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    loc50[0] = (ts4_word)((3582459904) | 4403);
    ts4_handle_forward_88610778((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    loc54[0] = (ts4_word)((2954821632) | 20373);
    t2 = ts4_init_range_and_run_service_opt_88164450((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 40))))((ts4_word)t3, (ts4_word)t2, (ts4_word)t4, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(t7) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888D8078: if_call_seq fn_888C39A0, u32@lbl_88D4590C, fn_888C39A0, lbl_88D45CC0, ts4_if_call_seq_u32_off24_8817BDD8 */
void ts4_if_call_seq_fn_888C39A0_888D8078(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p6;
    int t1;
    ts4_word t2;
    int t4;

    t1 = fn_888C39A0((ts4_word)a1);
    t2 = *(ts4_word *)lbl_88D4590C;
    p3 = (ts4_word)0;
    if ((int)t1 != -1) {
        p3 = (ts4_word)((t1 << 5) + t2);
    }
    if ((ts4_word)a3 != 0) {
        t4 = fn_888C39A0((ts4_word)a3);
        p5 = (ts4_word)0;
        if ((int)t4 != -1) {
            p5 = (ts4_word)((t4 << 5) + t2);
        }
        p6 = (ts4_word)p5;
    } else {
        p6 = (ts4_word)0;
    }
    ts4_if_call_seq_u32_off24_8817BDD8((ts4_word)(((int)a0 * 412) + ((ts4_word)lbl_88D45CC0 + 12)), (ts4_word)p3, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(((int)a0 * 412)) + ((ts4_word)lbl_88D45CC0 + 356)) = (ts4_word)p6;
    return;
}

/* Swing_DLL.xex 0x888DC9A0: loop_call_seq fn_88627EC0, ts4_find_service, u8@0x1c, ts4_tailcall_fn_88584548_8857AFE8, u8@0x1c */
void ts4_loop_call_seq_fn_88627EC0_888DC9A0(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    unsigned char t6;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = ts4_find_service((ts4_word)((285147136) | 26048));
    if ((ts4_word)t3 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t3) + 28)) != 0) {
        do {
            ts4_tailcall_fn_88584548_8857AFE8((ts4_word)16);
            t6 = *(unsigned char *)((char *)(ts4_word)(t3) + 28);
        } while ((ts4_word)t6 != 0);
    }
    return;
}

/* Swing_DLL.xex 0x888E63A8: if_get u8@0x35, u8@0x36, u8@0x36, u8@lbl_88D45919, u8@lbl_88D45919, fn_888E62C8 */
void ts4_if_get_u8_off35_888E63A8(ts4_word a0)
{
    unsigned char t1;
    ts4_word t26;
    unsigned char t3;
    ts4_word t19;
    ts4_word t25;
    unsigned char t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;
    ts4_word t16;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 53);
    if ((ts4_word)t1 == 1) {
        t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        *(unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
        *(unsigned char *)((char *)(ts4_word)(t26) + 2265) = (unsigned char)0;
        return;
    }
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 54);
    if ((ts4_word)t3 == 1) {
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        *(unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t19) + 1940) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1956) = (ts4_word)60;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1964) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1960) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1944) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1969) = (unsigned char)0;
        t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        *(unsigned char *)lbl_88D45919 = (unsigned char)t3;
        *(unsigned char *)((char *)(ts4_word)(t25) + 1970) = (unsigned char)0;
        return;
    }
    t5 = *(unsigned char *)lbl_88D45919;
    if ((ts4_word)t5 != 0) {
        fn_888E62C8();
        *(unsigned char *)lbl_88D45919 = (unsigned char)0;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 2536);
    t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 2544);
    if ((ts4_word)t11 >= (ts4_word)(t10 + -1)) {
        *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 564) = (unsigned char)0;
        t13 = ts4_find_service((ts4_word)((2354708480) | 18722));
        t16 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 76))))((ts4_word)t13, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(t16) + 452) = (ts4_word)((80281600) | 473);
    }
    return;
}

/* Swing_DLL.xex 0x888E9088: loop_call_seq u32@lbl_88D458F0, ts4_hash_find_881AB900, u8@0x19, u32@0x40, u32@0x3c, fn_888DFAD0 */
void ts4_loop_call_seq_u32_lbl_88D458F0_888E9088(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p7;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    t1 = *(ts4_word *)lbl_88D458F0;
    loc50[2] = (ts4_word)0;
    t2 = ts4_hash_find_881AB900((ts4_word)t1, (ts4_word)((1519255552) | 20316), *(ts4_args3 *)&loc50[0]);
    *(unsigned char *)((char *)(ts4_word)(t2) + 25) = (unsigned char)1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t3 != (ts4_word)t4) {
        lv5 = (ts4_word)t4;
        do {
            fn_888DFAD0((ts4_word)lv5);
            p7 = (ts4_word)(lv5 + 240);
            lv5 = p7;
        } while ((ts4_word)p7 != (ts4_word)t3);
    }
    return;
}

/* Swing_DLL.xex 0x888FC080: if_call_seq u8@0x88, u32@0x24, fn_888FBCA0, u8@0x98, u8@0x89, u32@0x20 */
void ts4_if_call_seq_u8_off88_888FC080(ts4_word a0)
{
    unsigned char t1;
    unsigned char t5;
    unsigned char t9;
    unsigned char t12;
    unsigned char t20;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t1 == 1 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)) <= 0) {
        fn_888FBCA0((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    }
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 137);
    if ((ts4_word)t5 == 1 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)) < 0) {
        fn_888FBCA0((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    }
    t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 139);
    if ((ts4_word)t9 == 1 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)) >= (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 148))) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    }
    t12 = *(unsigned char *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t12 == 1 && (int)(((int)((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 176)) * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 168))) * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 160))) + (*(ts4_word *)((char *)(ts4_word)(a0) + 8))) >= (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 148))) {
        fn_888FBCA0((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    }
    t20 = *(unsigned char *)((char *)(ts4_word)(a0) + 138);
    if ((ts4_word)t20 == 1 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) <= 0) {
        fn_888FBCA0((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    }
    return;
}

/* Swing_DLL.xex 0x888FDFF0: if_call_seq u32@0x154, u32@0x1c0, u8@0x138, u8@0x138, fn_888C2C80, fn_888FA780 */
void ts4_if_call_seq_u32_off154_888FDFF0(ts4_word a0)
{
    ts4_word t2;
    unsigned char t3;
    ts4_word t9;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 340))) + 448);
    if ((ts4_word)t2 == (ts4_word)((80281600) | 473) || (ts4_word)t2 == (ts4_word)((1792475136) | 11351)) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 312);
        if ((ts4_word)t3 == 0) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 312) = (unsigned char)1;
            fn_888C2C80((ts4_word)a0);
        }
    }
    fn_888FA780((ts4_word)a0);
    t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 620);
    if ((ts4_word)t9 == (ts4_word)((966918144) | 43504)) {
        fn_888DCE38((ts4_word)a0);
    } else {
        if ((ts4_word)t9 == (ts4_word)((1815281664) | 16157) && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)) != 0) {
            fn_888EE650((ts4_word)a0);
        }
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t15 != 0) {
        t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
        *(ts4_word *)((char *)(ts4_word)(t17) + 600) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t16) + 0));
    }
    return;
}

/* Swing_DLL.xex 0x88903120: call_seq u32@0x44, u32@lbl_88C6B930, fn_88901010, u32@lbl_88C6B930, u32@0x8, fn_888D3330 */
void ts4_call_seq_u32_off44_88903120(ts4_word a0)
{
    ts4_word t1;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    fn_88901010((ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88C6B930));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B930);
    fn_888D3330((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 176))) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 180))) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 184))) + 0) = (ts4_word)0;
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t9) + 1772) = (ts4_word)((2188050432) | 12168);
    return;
}

/* Swing_DLL.xex 0x889077B8: if_call_seq u8@0x54, u32@0x50, u8@0x0, u32@0x2c, u8@0x8c8, u8@0x54 */
void ts4_if_call_seq_u8_off54_889077B8(ts4_word a0)
{
    unsigned char t1;
    unsigned char t7;
    ts4_word t10;
    ts4_word t13;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t1 != 0) {
        t7 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 0);
        if ((ts4_word)t7 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 2248)) == 0) {
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
            *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
            t13 = fn_88907128((ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 788)), (ts4_word)((2504327168) | 40598), (ts4_word)1);
            ts4_loop_get_u32_lbl_88D45B1C_88868008((ts4_word)t13);
            return;
        }
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 2248));
    return;
}

/* Swing_DLL.xex 0x88909488: if_call_seq u8@0x20, u32@0x54, u32@0x54, u32@0x18, u32@0x18, fn_88908530 */
void ts4_if_call_seq_u8_off20_88909488(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t1;
    float t7;
    float t8;
    ts4_word t17;
    ts4_word t18;
    int t10;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    int t3;

    (void)a2;
    (void)a3;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 32);
    if ((ts4_word)t1 == 1) {
        t7 = *(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 68))) + 0);
        t8 = *(float *)lbl_880D0938;
        if (!(t7 < t8)) {
            t17 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
            t18 = *(ts4_word *)((char *)(ts4_word)(a1) + 88);
            *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)3;
            fn_88907570((ts4_word)a0, (ts4_word)t18, (ts4_word)(ts4_word)lbl_880D991C, (ts4_word)t17, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
            fn_88909360((ts4_word)a0, (ts4_word)a1);
        } else {
            t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 84);
            if ((int)t10 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 696)) != 0) {
                t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
                t13 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
                t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 92);
                *(ts4_word *)((char *)(ts4_word)(a1) + 76) = (ts4_word)(t12 + 1);
                fn_889074A8((ts4_word)a0, (ts4_word)t14, (ts4_word)(ts4_word)lbl_880D9988, (ts4_word)t13, (ts4_word)(t12 + 1), (ts4_word)a5, (ts4_word)a6);
            }
        }
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 84);
        if ((int)t3 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)5;
            fn_88908530((ts4_word)a0, (ts4_word)a1);
        } else {
            *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)0;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88913F48: if_get u32@0x108, u8@0x104, fn_88B09368 */
void ts4_if_get_u32_off108_88913F48(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    *(unsigned char *)((char *)(ts4_word)(a0) + 260) = (unsigned char)0;
    if ((ts4_word)t1 == 0) {
        return;
    }
    fn_88B09368((ts4_word)t1, (ts4_word)0);
    return;
}

/* Swing_DLL.xex 0x88913F70: get u32@0x3c, u32@0x40, u32@0x44, ts4_handle_forward_88150770, u32@0x0, u32@0x28 */
void ts4_get_u32_off3c_88913F70(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    loc50[0] = (ts4_word)((2954821632) | 20373);
    loc58[0] = (ts4_word)t1;
    loc58[1] = (ts4_word)t2;
    loc58[2] = (ts4_word)t3;
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
    t5 = loc68[0];
    t6 = loc68[1];
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5, (ts4_word)(ts4_word)&loc68[0], (ts4_word)t6, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(t9) + 0) = (unsigned char)1;
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t10) + 24))))((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x889236D8: if_get u32@0x34, u8@0x38, u8@0x38, u8@0x38, u32@0x0, u32@0x14 */
void ts4_if_get_u32_off34_889236D8(ts4_word a0)
{
    ts4_word t1;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 56);
        if ((ts4_word)t3 != 0) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x889283D8: get ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0, u32@0x50, vcall */
void ts4_get_ts4_handle_forward_88150770_889283D8(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)((166330368) | 27171);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)t1, (ts4_word)t3, (ts4_word)1);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)t6, (ts4_word)1);
    return;
}

/* Swing_DLL.xex 0x8892FEE8: if_get u32@0x8, u32@0x0, u32@0x48, vcall, u32@0x8, memcpy */
void ts4_if_get_u32_off8_8892FEE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, int a5)
{
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t4;
    int t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 72))))((ts4_word)t1, (ts4_word)a2);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t5 == 11) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t8 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)t4, *(ts4_args3 *)&loc50[0]);
        if ((ts4_word)t8 != 0) {
            memcpy((ts4_word)t8, (ts4_word)a3, (ts4_word)a4);
            return;
        }
        return;
    }
    if ((int)t5 == (int)a5) {
        memcpy((ts4_word)t4, (ts4_word)a3, (ts4_word)a4);
    }
    return;
}

/* Swing_DLL.xex 0x889315C0: if_get u32@0x44, u32@0x44, u32@0x0, u32@0x0, vcall, u32@0x44 */
void ts4_if_get_u32_off44_889315C0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889325C8: loop_get u32@0x0, u32@0x1c, u32@0x18, u32@0x0, u32@0x8, u32@0x4 */
void ts4_loop_get_u32_off0_889325C8(ts4_word a0)
{
    ts4_word lv4;
    ts4_word lv8;
    ts4_word lv12;
    ts4_word p17;
    ts4_word p20;
    ts4_word p23;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24));
    while ((ts4_word)lv4 != (ts4_word)t2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
        lv8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 4));
        while ((ts4_word)lv8 != (ts4_word)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            t11 = *(ts4_word *)((char *)(ts4_word)(lv8) + 0);
            lv12 = (ts4_word)t10;
            while ((ts4_word)lv12 != (ts4_word)t9) {
                t13 = *(ts4_word *)((char *)(ts4_word)(lv12) + 0);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 20))))((ts4_word)t13, (ts4_word)t11);
                p17 = (ts4_word)(lv12 + 4);
                lv12 = p17;
            }
            p20 = (ts4_word)(lv8 + 4);
            lv8 = p20;
        }
        p23 = (ts4_word)(lv4 + 4);
        lv4 = p23;
    }
    return;
}

/* Swing_DLL.xex 0x88932658: loop_get u32@0x0, u32@0x1c, u32@0x18, u32@0x0, u32@0x8, u32@0x4 */
void ts4_loop_get_u32_off0_88932658(ts4_word a0)
{
    ts4_word lv4;
    ts4_word lv8;
    ts4_word lv12;
    ts4_word p17;
    ts4_word p20;
    ts4_word p23;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24));
    while ((ts4_word)lv4 != (ts4_word)t2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
        lv8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 4));
        while ((ts4_word)lv8 != (ts4_word)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            t11 = *(ts4_word *)((char *)(ts4_word)(lv8) + 0);
            lv12 = (ts4_word)t10;
            while ((ts4_word)lv12 != (ts4_word)t9) {
                t13 = *(ts4_word *)((char *)(ts4_word)(lv12) + 0);
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 16))))((ts4_word)t13, (ts4_word)t11);
                p17 = (ts4_word)(lv12 + 4);
                lv12 = p17;
            }
            p20 = (ts4_word)(lv8 + 4);
            lv8 = p20;
        }
        p23 = (ts4_word)(lv4 + 4);
        lv4 = p23;
    }
    return;
}

/* Swing_DLL.xex 0x88932848: loop_get u32@0x1c, u32@0x8, u32@0x4, vcall, u32@0x1c, u32@0x28 */
void ts4_loop_get_u32_off1c_88932848(ts4_word a0)
{
    ts4_word lv8;
    ts4_word p18;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    unsigned char t10;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8))) + 4))))((ts4_word)(t1 + 8));
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 40);
        t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        if ((ts4_word)t7 != (ts4_word)t6) {
            lv8 = (ts4_word)t7;
            do {
                t9 = *(ts4_word *)((char *)(ts4_word)(lv8) + 8);
                t10 = *(unsigned char *)((char *)(ts4_word)(t9) + 24);
                if ((ts4_word)t10 == 0) {
                    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0, (ts4_word)t9);
                }
                t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
                t16 = *(ts4_word *)((char *)(ts4_word)(lv8) + 0);
                t17 = *(ts4_word *)((char *)(ts4_word)(t15) + 40);
                p18 = (ts4_word)t16;
                lv8 = p18;
            } while ((ts4_word)p18 != (ts4_word)t17);
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((t1 + 8)) + 0))) + 8))))((ts4_word)(t1 + 8));
    }
    return;
}

/* Swing_DLL.xex 0x88932918: if_get u32@0x40, u32@lbl_88D458E0, u32@lbl_88D458E0, u32@0x0, u32@0x24, u32@0x3c */
void ts4_if_get_u32_off40_88932918(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 <= 0) {
        return;
    }
    t3 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t3 == 0) {
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    ((void (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t4) + 60))))((ts4_word)t3, (ts4_word)t5);
    return;
}

/* Swing_DLL.xex 0x88932950: if_get u32@0x40, u32@lbl_88D458E0, u32@lbl_88D458E0, u32@0x0, u32@0x38 */
void ts4_if_get_u32_off40_88932950(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 <= 0) {
        return;
    }
    t3 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t3 == 0) {
        return;
    }
    ((void (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 56))))((ts4_word)t3, (ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x88932A88: if_get u32@lbl_88D458E0, u32@0x0, u32@0x4c */
void ts4_if_get_u32_lbl_88D458E0_88932A88(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t1 == 0) {
        return;
    }
    ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x88939E98: loop_get u32@0x0, u8@0x5c, u32@0x1c, u32@0x18, u32@0x1c, u32@0x18 */
void ts4_loop_get_u32_off0_88939E98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv7;
    ts4_word lv11;
    ts4_word p13;
    ts4_word p16;
    ts4_word lv25;
    ts4_word p30;
    ts4_word t1;
    unsigned char t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t23;
    ts4_word t26;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 92);
    if ((ts4_word)t2 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
        lv7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24));
        while ((ts4_word)lv7 != (ts4_word)t5) {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
            t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 8);
            lv11 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t8) + 4));
            while ((ts4_word)lv11 != (ts4_word)t9) {
                *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv11) + 0))) + 110) = (unsigned char)0;
                p13 = (ts4_word)(lv11 + 4);
                lv11 = p13;
            }
            p16 = (ts4_word)(lv7 + 4);
            lv7 = p16;
        }
        fn_88939C30((ts4_word)a0);
        t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        lv25 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
        while ((ts4_word)lv25 != (ts4_word)t23) {
            t26 = *(ts4_word *)((char *)(ts4_word)(lv25) + 0);
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 0))) + 12))))((ts4_word)t26);
            p30 = (ts4_word)(lv25 + 4);
            lv25 = p30;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8893E7C0: if_get u32@lbl_88D458E0, ts4_assign_formatted_text, u32@lbl_88D458E0, u32@0x0, u32@0x44, vcall */
void ts4_if_get_u32_lbl_88D458E0_8893E7C0(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t1 != 0) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
        t3 = *(ts4_word *)lbl_88D458E0;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 68))))((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x8893E820: if_get u32@lbl_88D458E0, ts4_assign_formatted_text, u32@lbl_88D458E0, u32@0x0, u32@0x40, vcall */
void ts4_if_get_u32_lbl_88D458E0_8893E820(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;
    ts4_word t7;

    t1 = *(ts4_word *)lbl_88D458E0;
    if ((ts4_word)t1 != 0) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
        t3 = *(ts4_word *)lbl_88D458E0;
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 64))))((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t7);
    }
    return;
}

/* Swing_DLL.xex 0x88941BA8: loop_get u8@0x25, u32@0x44, u32@0x8, u32@0x14, u32@0x0, u32@0x50 */
void ts4_loop_get_u8_off25_88941BA8(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p12;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t10;
    ts4_word t11;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 37);
    if ((ts4_word)t1 == 1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
        if ((ts4_word)t3 != (ts4_word)t2) {
            lv4 = (ts4_word)t3;
            do {
                t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 20);
                if ((ts4_word)t5 != 0) {
                    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 80))))((ts4_word)t5);
                }
                t10 = fn_8815D480((ts4_word)lv4);
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
                p12 = (ts4_word)t10;
                lv4 = p12;
            } while ((ts4_word)p12 != (ts4_word)t11);
        }
    }
    return;
}

/* Swing_DLL.xex 0x88942B70: loop_call_seq u32@0x53c, u32@0x540, u32@0xc, u32@0x14, memset, u32@0x540 */
void ts4_loop_call_seq_u32_off53c_88942B70(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1340);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 1344);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 12);
            if ((int)t4 != 0) {
                memset((ts4_word)t4, (ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 20)));
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 1344);
            p9 = (ts4_word)(lv3 + 32);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x88942D40: if_call_seq u32@0x2c, u32@lbl_88D458AC, u32@lbl_88D458B0, fn_88923238, u32@0x4c, u32@0x50 */
void ts4_if_call_seq_u32_off2c_88942D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)lbl_88D458AC;
        fn_88923238((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88D458B0), (ts4_word)t2);
        t5 = loc50[0];
        t6 = loc50[1];
        t7 = loc50[2];
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t7;
    }
    return;
}

/* Swing_DLL.xex 0x889448D8: loop_call_seq u32@0x0, ts4_offset_array_end8_8815E4D0, u32@0x0, u32@0x8, u32@0x4, u32@0x8 */
void ts4_loop_call_seq_u32_off0_889448D8(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word lv4;
    ts4_word p15;
    ts4_word loc50[4];
    int t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p2 = (ts4_word)0;
    if ((int)t1 != -1) {
        p2 = (ts4_word)(t1 + a0);
    }
    t3 = ts4_offset_array_end8_8815E4D0((ts4_word)a0);
    if ((ts4_word)p2 != (ts4_word)t3) {
        lv4 = (ts4_word)(p2 + 4);
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            loc50[0] = (ts4_word)(lv4 - t5);
            if ((int)(lv4 - t5) != 0) {
                t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
                t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
                if ((ts4_word)t9 != (ts4_word)t8) {
                    if ((ts4_word)t9 != 0) {
                        *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)(lv4 - t5);
                    }
                    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 4);
                } else {
                    fn_88174A38((ts4_word)a1, (ts4_word)t9, (ts4_word)(ts4_word)&loc50[0]);
                }
            }
            t14 = ts4_offset_array_end8_8815E4D0((ts4_word)a0);
            p15 = (ts4_word)(lv4 + 8);
            lv4 = p15;
        } while ((ts4_word)(p15 + -4) != (ts4_word)t14);
    }
    return;
}

/* Swing_DLL.xex 0x88945F38: if_get u32@0x8, u32@0x8, u8@0x2c, u8@0x2c, u32@0x38, u64@0x30 */
void ts4_if_get_u32_off8_88945F38(ts4_word a0, ts4_word a1)
{
    int t2;
    unsigned char t4;

    if ((ts4_word)a1 == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t2 != 2) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t4 != 0) {
        ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
        return;
    }
    fn_88943760((ts4_word)a1, *(ts4_args3 *)((char *)(ts4_word)(a0) + 48));
    return;
}

/* Swing_DLL.xex 0x88945F88: if_get u32@0x8, u32@0x8, u8@0x1c, u8@0x1c, u32@0x28, u64@0x20 */
void ts4_if_get_u32_off8_88945F88(ts4_word a0, ts4_word a1)
{
    int t2;
    unsigned char t4;

    if ((ts4_word)a1 == 0) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t2 != 0) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ((void (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0);
        return;
    }
    fn_88943760((ts4_word)a1, *(ts4_args3 *)((char *)(ts4_word)(a0) + 32));
    return;
}

/* Swing_DLL.xex 0x88954198: loop_call_seq u32@0x0, u32@0x4, lbl_880D35C0, u32@0x538, u32@0x0, u32@0x0 */
void ts4_loop_call_seq_u32_off0_88954198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p12;
    ts4_word loc60[64];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 1336);
            t5 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            ts4_concat3_881642B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)t5, (ts4_word)(ts4_word)lbl_880D35C0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 36)));
            fn_88950A30((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0)), (ts4_word)(ts4_word)&loc60[0]);
            t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
            p12 = (ts4_word)(lv3 + 48);
            lv3 = p12;
        } while ((ts4_word)p12 != (ts4_word)t11);
    }
    return;
}

/* Swing_DLL.xex 0x88957F00: loop_set u32@0x3c, fn_88956170, u32@0x0, ts4_offset_array_end8_8815E4D0, u32@0x0, u32@0x0 */
void ts4_loop_set_u32_off3c_88957F00(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word lv5;
    ts4_word p12;
    int t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    fn_88956170((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + a1);
    }
    t4 = ts4_offset_array_end8_8815E4D0((ts4_word)a1);
    if ((ts4_word)p3 != (ts4_word)t4) {
        lv5 = (ts4_word)(p3 + 4);
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            if ((int)(lv5 - t6) != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0, (ts4_word)(lv5 - t6));
            }
            t11 = ts4_offset_array_end8_8815E4D0((ts4_word)a1);
            p12 = (ts4_word)(lv5 + 8);
            lv5 = p12;
        } while ((ts4_word)(p12 + -4) != (ts4_word)t11);
    }
    return;
}

/* Swing_DLL.xex 0x889584F8: loop_set u32@0x3c, fn_88956170, u32@0x0, ts4_offset_array_end8_8815E4D0, u32@0x0, u32@0x0 */
void ts4_loop_set_u32_off3c_889584F8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word lv5;
    ts4_word p12;
    int t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    fn_88956170((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + a1);
    }
    t4 = ts4_offset_array_end8_8815E4D0((ts4_word)a1);
    if ((ts4_word)p3 != (ts4_word)t4) {
        lv5 = (ts4_word)(p3 + 4);
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
            if ((int)(lv5 - t6) != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)(lv5 - t6));
            }
            t11 = ts4_offset_array_end8_8815E4D0((ts4_word)a1);
            p12 = (ts4_word)(lv5 + 8);
            lv5 = p12;
        } while ((ts4_word)(p12 + -4) != (ts4_word)t11);
    }
    return;
}

/* Swing_DLL.xex 0x8895B160: if_call_seq u32@0x8, u32@0xc, u32@0x10, fn_8860AB08, u32@0x0, u32@0x0 */
void ts4_if_call_seq_u32_off8_8895B160(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t12;

    if ((ts4_word)a0 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        loc50[0] = (ts4_word)t1;
        loc50[1] = (ts4_word)t2;
        loc50[2] = (ts4_word)t3;
        fn_8860AB08((ts4_word)(ts4_word)&loc50[0]);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        if ((ts4_word)t5 != 0) {
            t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
            if ((ts4_word)t7 != 0) {
                ts4_destroy_owned_object((ts4_word)t7);
            }
            ts4_tsu_cleanup_end((ts4_word)t5);
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t12 != 0) {
            fn_8816C2F0((ts4_word)t12);
            ts4_tsu_cleanup_end((ts4_word)t12);
        }
        ts4_dtor_5_88165440((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x8897EE18: if_call_seq fn_889423E0, u32@0x0, lbl_880D4204, ts4_assign_formatted_text, lbl_880D3820, ts4_assign_formatted_text */
void ts4_if_call_seq_fn_889423E0_8897EE18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t21;
    int t24;
    ts4_word t6;
    ts4_word t8;
    int t11;
    ts4_word t14;

    fn_889423E0((ts4_word)a0, (ts4_word)a2);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t2 != (ts4_word)((2801139712) | 59735) && (ts4_word)t2 != (ts4_word)((465633280) | 29333)) {
        if (((ts4_word)t2 == (ts4_word)((499777536) | 29317) || (ts4_word)t2 == (ts4_word)((4150788096) | 12377)) || (ts4_word)t2 == (ts4_word)((145817600) | 51551)) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)0;
            *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)0;
            *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)0;
            *(unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)1;
            *(unsigned char *)((char *)(ts4_word)(a0) + 115) = (unsigned char)0;
            *(unsigned char *)((char *)(ts4_word)(a0) + 114) = (unsigned char)0;
            ts4_object_finalize((ts4_word)(a0 + 76));
            t21 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
            if ((ts4_word)t21 != (ts4_word)((145817600) | 51551)) {
                ts4_object_finalize((ts4_word)(a0 + 88));
            }
            t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
            if ((int)t24 != 0) {
                fn_8897EA30((ts4_word)a0, (ts4_word)0);
                ts4_if_call_seq_u32_off4_88161D58((ts4_word)(a0 + 100));
                return;
            }
            ts4_if_call_seq_u32_off4_88161D58((ts4_word)(a0 + 100));
            return;
        }
        return;
    }
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880D4204);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D3820);
    fn_88972828((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    t6 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t6);
    t8 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t8);
    *(unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 113) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 114) = (unsigned char)1;
    ts4_object_finalize((ts4_word)(a0 + 76));
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((int)t11 != 0) {
        t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        if ((ts4_word)t14 == (ts4_word)((465633280) | 29333)) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)0;
            *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)0;
            fn_8897EA30((ts4_word)a0, (ts4_word)1);
            *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)1;
            *(unsigned char *)((char *)(ts4_word)(a0) + 115) = (unsigned char)1;
            ts4_if_call_seq_u32_off4_88161D58((ts4_word)(a0 + 100));
            return;
        }
        *(unsigned char *)((char *)(ts4_word)(a0) + 117) = (unsigned char)1;
        ts4_object_finalize((ts4_word)(a0 + 88));
        *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)1;
        fn_8897EA30((ts4_word)a0, (ts4_word)1);
        *(unsigned char *)((char *)(ts4_word)(a0) + 115) = (unsigned char)0;
        ts4_if_call_seq_u32_off4_88161D58((ts4_word)(a0 + 100));
        return;
    }
    ts4_if_call_seq_u32_off4_88161D58((ts4_word)(a0 + 100));
    return;
}

/* Swing_DLL.xex 0x88997B88: if_get u32@0xc, u8@0x6c, u32@0x4, u32@lbl_88D45B1C, u32@0x234, fn_88614938 */
void ts4_if_get_u32_offc_88997B88(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word loc50[2];
    int t1;
    ts4_word t3;
    ts4_word t6;
    int t11;
    ts4_word t12;
    int t16;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if (((int)t1 != 0 && (ts4_word)a1 != 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 108)) != 1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        t6 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t3);
        if ((ts4_word)t6 != 0) {
            p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 16));
        } else {
            p8 = (ts4_word)-1;
        }
        t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)p8);
        if ((int)t11 >= 0) {
            t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
            loc50[0] = (ts4_word)(*(ts4_word *)lbl_8808D674);
            t16 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 12))))((ts4_word)t12, (ts4_word)p8, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
            if ((int)t16 >= 0) {
                *(unsigned char *)((char *)(ts4_word)(a1) + 108) = (unsigned char)1;
                *(unsigned char *)((char *)(ts4_word)(a1) + 109) = (unsigned char)0;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x889A04F0: if_call_seq u32@0x0, ts4_registry_dispatch_888860A0, u32@0x0, u32@0x4, u32@0x8 */
void ts4_if_call_seq_u32_off0_889A04F0(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != 0) {
        ts4_registry_dispatch_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p3 = (ts4_word)0;
    } else {
        p3 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p3;
    return;
}

/* Swing_DLL.xex 0x889AC718: if_call_seq lbl_880D21C0, u32@g_ts4_session_context, u32@0x0, u32@0x40, u32@0x8, u32@0x4 */
void ts4_if_call_seq_lbl_880D21C0_889AC718(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    ts4_word t26;
    ts4_word t27;
    ts4_word t28;
    ts4_word t30;
    ts4_word t31;
    ts4_word t32;
    ts4_word t34;
    ts4_word t35;
    ts4_word t36;
    ts4_word t38;
    ts4_word t39;
    ts4_word t40;
    ts4_word t42;
    ts4_word t43;
    ts4_word t44;
    ts4_word t46;
    ts4_word t47;
    ts4_word t48;
    ts4_word t50;
    ts4_word t51;
    ts4_word t52;
    ts4_word t54;
    ts4_word t55;
    ts4_word t56;
    ts4_word t58;
    ts4_word t59;
    ts4_word t60;
    ts4_word t62;
    ts4_word t63;
    ts4_word t64;
    ts4_word t66;
    ts4_word t67;
    ts4_word t68;
    ts4_word t70;
    ts4_word t71;
    ts4_word t72;
    ts4_word t74;
    ts4_word t75;
    ts4_word t76;
    ts4_word t78;
    ts4_word t80;

    t1 = *(ts4_word *)g_ts4_session_context;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D21C0;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 52) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(ts4_word *)((char *)(ts4_word)(t4) + 832) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 836) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 840) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 844) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 53) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(ts4_word *)((char *)(ts4_word)(t8) + 848) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 852) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 856) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 860) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
    if ((ts4_word)t11 > 56) {
        t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
        *(ts4_word *)((char *)(ts4_word)(t12) + 896) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 900) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 904) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 908) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 8);
    if ((ts4_word)t15 > 62) {
        t16 = *(ts4_word *)((char *)(ts4_word)(t14) + 4);
        *(ts4_word *)((char *)(ts4_word)(t16) + 992) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 996) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 1000) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 1004) = (ts4_word)0;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 8);
    if ((ts4_word)t19 > 71) {
        t20 = *(ts4_word *)((char *)(ts4_word)(t18) + 4);
        *(ts4_word *)((char *)(ts4_word)(t20) + 1136) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t20) + 1140) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t20) + 1144) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t20) + 1148) = (ts4_word)0;
    }
    t22 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t23 = *(ts4_word *)((char *)(ts4_word)(t22) + 8);
    if ((ts4_word)t23 > 57) {
        t24 = *(ts4_word *)((char *)(ts4_word)(t22) + 4);
        *(ts4_word *)((char *)(ts4_word)(t24) + 912) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t24) + 916) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t24) + 920) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t24) + 924) = (ts4_word)0;
    }
    t26 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t27 = *(ts4_word *)((char *)(ts4_word)(t26) + 8);
    if ((ts4_word)t27 > 64) {
        t28 = *(ts4_word *)((char *)(ts4_word)(t26) + 4);
        *(ts4_word *)((char *)(ts4_word)(t28) + 1024) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t28) + 1028) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t28) + 1032) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t28) + 1036) = (ts4_word)0;
    }
    t30 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t31 = *(ts4_word *)((char *)(ts4_word)(t30) + 8);
    if ((ts4_word)t31 > 58) {
        t32 = *(ts4_word *)((char *)(ts4_word)(t30) + 4);
        *(ts4_word *)((char *)(ts4_word)(t32) + 928) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t32) + 932) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t32) + 936) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t32) + 940) = (ts4_word)0;
    }
    t34 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t35 = *(ts4_word *)((char *)(ts4_word)(t34) + 8);
    if ((ts4_word)t35 > 59) {
        t36 = *(ts4_word *)((char *)(ts4_word)(t34) + 4);
        *(ts4_word *)((char *)(ts4_word)(t36) + 944) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t36) + 948) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t36) + 952) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t36) + 956) = (ts4_word)0;
    }
    t38 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t39 = *(ts4_word *)((char *)(ts4_word)(t38) + 8);
    if ((ts4_word)t39 > 65) {
        t40 = *(ts4_word *)((char *)(ts4_word)(t38) + 4);
        *(ts4_word *)((char *)(ts4_word)(t40) + 1040) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t40) + 1044) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t40) + 1048) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t40) + 1052) = (ts4_word)0;
    }
    t42 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t43 = *(ts4_word *)((char *)(ts4_word)(t42) + 8);
    if ((ts4_word)t43 > 60) {
        t44 = *(ts4_word *)((char *)(ts4_word)(t42) + 4);
        *(ts4_word *)((char *)(ts4_word)(t44) + 960) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t44) + 964) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t44) + 968) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t44) + 972) = (ts4_word)0;
    }
    t46 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t47 = *(ts4_word *)((char *)(ts4_word)(t46) + 8);
    if ((ts4_word)t47 > 61) {
        t48 = *(ts4_word *)((char *)(ts4_word)(t46) + 4);
        *(ts4_word *)((char *)(ts4_word)(t48) + 976) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t48) + 980) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t48) + 984) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t48) + 988) = (ts4_word)0;
    }
    t50 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t51 = *(ts4_word *)((char *)(ts4_word)(t50) + 8);
    if ((ts4_word)t51 > 54) {
        t52 = *(ts4_word *)((char *)(ts4_word)(t50) + 4);
        *(ts4_word *)((char *)(ts4_word)(t52) + 864) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t52) + 868) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t52) + 872) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t52) + 876) = (ts4_word)0;
    }
    t54 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t55 = *(ts4_word *)((char *)(ts4_word)(t54) + 8);
    if ((ts4_word)t55 > 55) {
        t56 = *(ts4_word *)((char *)(ts4_word)(t54) + 4);
        *(ts4_word *)((char *)(ts4_word)(t56) + 880) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t56) + 884) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t56) + 888) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t56) + 892) = (ts4_word)0;
    }
    t58 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t59 = *(ts4_word *)((char *)(ts4_word)(t58) + 8);
    if ((ts4_word)t59 > 74) {
        t60 = *(ts4_word *)((char *)(ts4_word)(t58) + 4);
        *(ts4_word *)((char *)(ts4_word)(t60) + 1184) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t60) + 1188) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t60) + 1192) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t60) + 1196) = (ts4_word)0;
    }
    t62 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t63 = *(ts4_word *)((char *)(ts4_word)(t62) + 8);
    if ((ts4_word)t63 > 66) {
        t64 = *(ts4_word *)((char *)(ts4_word)(t62) + 4);
        *(ts4_word *)((char *)(ts4_word)(t64) + 1056) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t64) + 1060) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t64) + 1064) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t64) + 1068) = (ts4_word)0;
    }
    t66 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t67 = *(ts4_word *)((char *)(ts4_word)(t66) + 8);
    if ((ts4_word)t67 > 67) {
        t68 = *(ts4_word *)((char *)(ts4_word)(t66) + 4);
        *(ts4_word *)((char *)(ts4_word)(t68) + 1072) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t68) + 1076) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t68) + 1080) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t68) + 1084) = (ts4_word)0;
    }
    t70 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t71 = *(ts4_word *)((char *)(ts4_word)(t70) + 8);
    if ((ts4_word)t71 > 69) {
        t72 = *(ts4_word *)((char *)(ts4_word)(t70) + 4);
        *(ts4_word *)((char *)(ts4_word)(t72) + 1104) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t72) + 1108) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t72) + 1112) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t72) + 1116) = (ts4_word)0;
    }
    t74 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t75 = *(ts4_word *)((char *)(ts4_word)(t74) + 8);
    if ((ts4_word)t75 > 72) {
        t76 = *(ts4_word *)((char *)(ts4_word)(t74) + 4);
        *(ts4_word *)((char *)(ts4_word)(t76) + 1152) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t76) + 1156) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t76) + 1160) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t76) + 1164) = (ts4_word)0;
    }
    t78 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t78 != 0) {
        t80 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t80 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t80, (ts4_word)t78, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)));
        } else {
            fn_885651F8((ts4_word)t78, (ts4_word)t78);
        }
    }
    ts4_if_addr_lbl_880D2AC0_8899A668((ts4_word)a0);
    return;
}

/* Swing_DLL.xex 0x889C7508: if_get u32@0x1c, u32@0x0, u32@0x20, u32@0x10, vcall, u32@0x20 */
void ts4_if_get_u32_off1c_889C7508(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 16))))((ts4_word)t1, (ts4_word)t3);
    if ((int)t5 != -1) {
        fn_889C73B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)t5);
    }
    return;
}

/* Swing_DLL.xex 0x889C7E00: loop_get fn_889C7CE0, u32@0x28, u32@0x24, u32@0x0, u32@0x0, u32@0x10 */
void ts4_loop_get_fn_889C7CE0_889C7E00(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p9;
    ts4_word t2;
    ts4_word t5;
    ts4_word t12;
    ts4_word t13;
    int t16;

    fn_889C7CE0();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    while ((ts4_word)lv4 != (ts4_word)t2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 16))))((ts4_word)t5);
        p9 = (ts4_word)(lv4 + 4);
        lv4 = p9;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t16 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 16))))((ts4_word)t12, (ts4_word)t13);
    if ((int)t16 != -1) {
        fn_889C73B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)), (ts4_word)t16);
    }
    return;
}
