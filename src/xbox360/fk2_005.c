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

extern char ts4_ascii_lower_to_upper_88564790[];
extern char g_ts4_script_constants[];
extern char lbl_880C1320[];
extern char lbl_880C88DC[];
extern char lbl_880C8F40[];
extern char lbl_880D19F0[];
extern char lbl_880D2EFC[];
extern char lbl_880D6B70[];
extern char lbl_880D6B74[];
extern char lbl_880DFEDC[];
extern char lbl_880DFFF8[];
extern char lbl_880ECE4C[];
extern char lbl_880ECE64[];
extern char lbl_880ED610[];
extern char lbl_880EF47C[];
extern char lbl_880EF5D4[];
extern char lbl_880EF7C4[];
extern char lbl_880EF980[];
extern char lbl_880EF9F8[];
extern char lbl_880EFCDC[];
extern char lbl_880EFD04[];
extern char lbl_880EFD3C[];
extern char lbl_880EFD64[];
extern char lbl_880EFD8C[];
extern char lbl_880EFDB4[];
extern char lbl_880EFDE0[];
extern char lbl_880EFE08[];
extern char lbl_880EFE30[];
extern char lbl_880F1F58[];
extern char lbl_880F2118[];
extern char lbl_880F2138[];
extern char lbl_880F2148[];
extern char lbl_880F21E8[];
extern char lbl_880F2254[];
extern char lbl_880F22D4[];
extern char lbl_880F23AC[];
extern char lbl_880F2410[];
extern char lbl_880F24A4[];
extern char lbl_880F2530[];
extern char lbl_880F259C[];
extern char lbl_880F2600[];
extern char lbl_880F2668[];
extern char lbl_880F26D0[];
extern char lbl_880F2738[];
extern char lbl_880F27E8[];
extern char lbl_880F2810[];
extern char lbl_880F2958[];
extern char lbl_880F29F8[];
extern char lbl_880F2A74[];
extern char lbl_880F2AF0[];
extern char lbl_880F2B70[];
extern char lbl_880F2BF0[];
extern char lbl_880F2C8C[];
extern char lbl_880F30A4[];
extern char lbl_880F3388[];
extern char lbl_880F3510[];
extern char lbl_880F3540[];
extern char lbl_880F4340[];
extern char lbl_880F436C[];
extern char lbl_880F43E8[];
extern char lbl_880F4420[];
extern char lbl_880F44EC[];
extern char lbl_880F4550[];
extern char lbl_880F4C50[];
extern char lbl_880F5FEC[];
extern char lbl_880F604C[];
extern char lbl_880F63C0[];
extern char lbl_880F77E0[];
extern char lbl_880F7810[];
extern char lbl_880F7908[];
extern char lbl_880F7940[];
extern char lbl_880F7AEC[];
extern char lbl_880F8440[];
extern char lbl_880F84BC[];
extern char lbl_880F8BF4[];
extern char lbl_880F8D28[];
extern char lbl_8814B440[];
extern char lbl_88C6CBEC[];
extern char lbl_88C6CBF4[];
extern char lbl_88C6CD7C[];
extern char lbl_88C6CD84[];
extern char lbl_88C6CD88[];
extern char lbl_88D3E414[];
extern char lbl_88D4595C[];
extern char lbl_88D45A4C[];
extern char lbl_88D45A60[];
extern char lbl_88D45A74[];
extern char lbl_88D45A78[];
extern char lbl_88D45A94[];
extern char lbl_88D45AB4[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B34[];
extern char lbl_88D45B38[];
extern char lbl_88D48CC0[];
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88150600();
ts4_word fn_88150770();
ts4_word fn_8815D480();
ts4_word fn_88160848();
ts4_word fn_881608E8();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word fn_881643D0();
ts4_word fn_88165E80();
ts4_word fn_8816CAA0();
ts4_word ts4_if_call_seq_u32_off0_8816D140();
ts4_word fn_8816D1A8();
ts4_word fn_8816DD48();
ts4_word fn_8817B608();
ts4_word fn_88180070();
ts4_word fn_8819A9D8();
ts4_word fn_8819AD80();
ts4_word fn_881A5020();
ts4_word fn_881A50F0();
ts4_word fn_881A52D8();
ts4_word fn_881AA7A0();
ts4_word fn_881AAE70();
ts4_word fn_881AB4F0();
ts4_word fn_881AC778();
ts4_word fn_881AD708();
ts4_word ts4_call_seq_u32_off0_881B1B08();
ts4_word fn_881D4050();
ts4_word ts4_if_call_seq_u32_offc_882124A8();
ts4_word fn_88213D38();
ts4_word fn_88216460();
ts4_word fn_88218AD0();
ts4_word ts4_loop_call_seq_u32_offc_88219E68();
ts4_word ts4_if_call_seq_u32_off8_8821FD70();
ts4_word fn_88220060();
ts4_word fn_88222528();
ts4_word fn_88223B10();
ts4_word fn_88223DA0();
ts4_word fn_8822AE40();
ts4_word fn_8822BF98();
ts4_word ts4_loop_call_seq_u32_off20_88233618();
ts4_word fn_8823DD50();
ts4_word fn_88262528();
ts4_word fn_8826ACB8();
ts4_word ts4_set_u8_off0_8826B918();
ts4_word ts4_loop_get_u32_off4_8826C568();
ts4_word ts4_loop_get_u32_off0_8826DFB8();
ts4_word fn_8827EC98();
ts4_word fn_88287FA0();
ts4_word ts4_if_call_seq_u32_off0_8828B128();
ts4_word fn_8828DF30();
ts4_word fn_882C5EA8();
ts4_word ts4_set_u8_off0_88401F80();
ts4_word fn_885651F8();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();
ts4_word fn_88608590();
ts4_word fn_886090A0();
ts4_word fn_8860BBD8();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();
ts4_word fn_886131F0();
ts4_word fn_88613268();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word ts4_call_seq_lbl_880D2EFC_88629F58();
ts4_word fn_8862BE08();
ts4_word fn_8865A5E0();
ts4_word fn_8865D8D8();
ts4_word fn_88662E58();
ts4_word fn_8866DD78();
ts4_word fn_8866DE40();
ts4_word ts4_shot_reward_list_push_88673630();
ts4_word fn_8867BCF8();
ts4_word fn_8867DB30();
ts4_word ts4_selection_scorer_score_both_sides_88689AF0();
ts4_word fn_8868AF88();
ts4_word fn_886917F8();
ts4_word fn_88691888();
ts4_word fn_88692468();
ts4_word fn_88696D40();
ts4_word fn_8869AB70();
ts4_word fn_886A65F8();
ts4_word fn_886A6860();
ts4_word fn_886A6E98();
ts4_word fn_886AA748();
ts4_word fn_886ED860();
ts4_word fn_886EDB70();
ts4_word fn_886EDBC8();
ts4_word fn_886EFA20();
ts4_word fn_886EFA70();
ts4_word fn_886EFAC0();
ts4_word fn_886EFD38();
ts4_word fn_886FBF18();
ts4_word fn_886FC638();
ts4_word fn_88702A88();
ts4_word fn_8870EA08();
ts4_word fn_8870FE00();
ts4_word fn_88713FD0();
ts4_word fn_88717408();
ts4_word ts4_call_seq_fn_887143E0_88719CD8();
ts4_word fn_8871B7E0();
ts4_word fn_88721A08();
ts4_word fn_88721D98();
ts4_word fn_88722798();
ts4_word fn_88722B80();
ts4_word fn_8872D070();
ts4_word fn_88731540();
ts4_word ts4_call_seq_fn_88163B90_88736BB8();
ts4_word fn_88739D80();
ts4_word fn_88748350();
ts4_word fn_88748B18();
ts4_word fn_8874E3F8();
ts4_word fn_8874E518();
ts4_word fn_8874FCD8();
ts4_word fn_8874FF68();
ts4_word fn_88755E58();
ts4_word fn_887561A8();
ts4_word fn_88756638();
ts4_word fn_887568C0();
ts4_word fn_887569C8();
ts4_word fn_88758018();
ts4_word ts4_loop_call_seq_u32_off10_8875A070();
ts4_word fn_8875EB68();
ts4_word ts4_if_call_seq_fn_88734098_8876CE68();
ts4_word fn_8876D210();
ts4_word fn_8876D2C0();
ts4_word fn_8876D560();
ts4_word fn_88773A18();
ts4_word fn_88778208();
ts4_word fn_88778BE8();
ts4_word fn_887818A0();
ts4_word fn_8878C820();
ts4_word fn_887961A0();
ts4_word fn_88796240();
ts4_word fn_88799490();
ts4_word fn_887A33A8();
ts4_word fn_888348A0();
ts4_word fn_88883CD0();
ts4_word fn_888DDD70();
ts4_word fn_888F67B8();
ts4_word fn_8890E988();
ts4_word fn_88912A38();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word fn_889C0BC8();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();

/* Swing_DLL.xex 0x8860D598: if_get u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250 */
ts4_word ts4_if_get_u32_lbl_88D45B38_8860D598(void)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        return ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x886181F8: addr lbl_880F77E0, u32@lbl_88D45B1C, u32@0x0, u32@0x238, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F77E0_886181F8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F77E0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 568) = (ts4_word)0;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x886197D0: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_886197D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x8861B0F8: if_addr lbl_880F7940, u32@lbl_88D45B1C, u32@0x0, u32@0x224, u32@0x220, u32@0x224 */
ts4_word ts4_if_addr_lbl_880F7940_8861B0F8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 548);
    if ((ts4_word)a0 == (ts4_word)t2) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 544));
    }
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x8861DB98: call_seq lbl_880F8D28, u32@0x0, u32@0x34, ts4_destroy_owned_object, u32@0x28, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880F8D28_8861DB98(ts4_word a0)
{
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8D28;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8861F838: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_8861F838(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x8861F998: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_8861F998(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x8861FE78: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_8861FE78(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88620170: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_88620170(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88620460: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_88620460(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88620BF0: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_88620BF0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88621008: addr lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880F7810_88621008(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x886215A8: if_get u32@0xc, lbl_880F7AEC, u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, u32@0x4, vcall */
ts4_word ts4_if_get_u32_offc_886215A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p12;
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    loc58[0] = (ts4_word)(ts4_word)lbl_880F7AEC;
    t3 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    loc58[1] = (ts4_word)t3;
    loc58[2] = (ts4_word)t1;
    t4 = loc58[0];
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t4) + 4))))((ts4_word)(ts4_word)&loc58[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    t8 = fn_886090A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    t9 = fn_8827EC98((ts4_word)t7, (ts4_word)t8);
    if ((ts4_word)t9 != 0) {
        t11 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
        if ((ts4_word)t11 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t11) + 4) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(t11) + 8) = (ts4_word)a3;
            *(ts4_word *)((char *)(ts4_word)(t11) + 20) = (ts4_word)t9;
            *(ts4_word *)((char *)(ts4_word)(t11) + 12) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)(ts4_word)lbl_880F84BC;
            *(unsigned char *)((char *)(ts4_word)(t11) + 16) = (unsigned char)0;
            *(ts4_word *)((char *)(ts4_word)(t11) + 24) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t11) + 28) = (ts4_word)0;
            p12 = (ts4_word)t11;
        } else {
            p12 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p12;
    }
    t14 = loc58[0];
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 8))))((ts4_word)(ts4_word)&loc58[0]);
    return a0;
}

/* Swing_DLL.xex 0x88622A90: if_addr lbl_880F7940, u32@lbl_88D45B1C, u32@0x0, u32@0x224, u32@0x220, u32@0x224 */
ts4_word ts4_if_addr_lbl_880F7940_88622A90(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 548);
    if ((ts4_word)a0 == (ts4_word)t2) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 544));
    }
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88622BC0: if_addr lbl_880F7940, u32@lbl_88D45B1C, u32@0x0, u32@0x224, u32@0x220, u32@0x224 */
ts4_word ts4_if_addr_lbl_880F7940_88622BC0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 548);
    if ((ts4_word)a0 == (ts4_word)t2) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 544));
    }
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x88622D68: if_addr lbl_880F7940, u32@lbl_88D45B1C, u32@0x0, u32@0x224, u32@0x220, u32@0x224 */
ts4_word ts4_if_addr_lbl_880F7940_88622D68(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 548);
    if ((ts4_word)a0 == (ts4_word)t2) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 544));
    }
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x886267C0: if_call_seq lbl_880F8440, u32@0x0, u32@0x7c, ts4_destroy_owned_object, lbl_880D19F0, lbl_880F7940 */
ts4_word ts4_if_call_seq_lbl_880F8440_886267C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8440;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)lbl_88D45B1C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D19F0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t4) + 548);
    if ((ts4_word)a0 == (ts4_word)t5) {
        *(volatile ts4_word *)((char *)(ts4_word)(t4) + 548) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 544));
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88629D70: if_call_seq lbl_880F8BF4, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880F8BF4_88629D70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8BF4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8862C308: if_call_seq lbl_880F7908, lbl_880D6B70, u32@0x0, u32@0x60, u32@0x58, u32@0x4c */
ts4_word ts4_if_call_seq_lbl_880F7908_8862C308(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7908;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)(ts4_word)lbl_880D6B70;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B74;
    t10 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x8862FB38: if_call_seq ts4_call_seq_lbl_880D2EFC_88629F58, lbl_880C1320, fn_8822BF98, lbl_880D2EFC, fn_881AD708, fn_88160848 */
ts4_word ts4_if_call_seq_fn_88629F58_8862FB38(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[6];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t11;

    ts4_call_seq_lbl_880D2EFC_88629F58((ts4_word)a0, (ts4_word)a1);
    t2 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)a0);
    if ((ts4_word)(t2 & 0xff) == 0) {
        t3 = fn_881AD708((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D2EFC);
        t4 = fn_88160848((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D2EFC);
        if (((ts4_word)t3 != (ts4_word)t4 && (int)t3 != -1) && (int)t4 != -1) {
            t6 = fn_881608E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)t4, (ts4_word)(t3 - t4));
            ts4_if_call_seq_u32_off0_8816D140((ts4_word)(ts4_word)&loc50[0], (ts4_word)t6);
            fn_88150600((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
            t9 = loc50[0];
            ts4_destroy_owned_object((ts4_word)t9);
            t11 = loc60[0];
            ts4_destroy_owned_object((ts4_word)t11);
            return a0;
        }
        fn_8816CAA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)t4);
        return a0;
    }
    return a0;
}

/* Swing_DLL.xex 0x88630410: call_seq fn_8816CAA0, ts4_assign_formatted_text, ts4_call_seq_lbl_880D2EFC_88629F58, fn_88150600, ts4_destroy_owned_object, ts4_destroy_owned_object */
ts4_word ts4_call_seq_fn_8816CAA0_88630410(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;

    fn_8816CAA0((ts4_word)a1, (ts4_word)a0);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t3 = ts4_call_seq_lbl_880D2EFC_88629F58((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_88150600((ts4_word)a1, (ts4_word)t3);
    t5 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t5);
    t7 = loc50[0];
    t8 = ts4_destroy_owned_object((ts4_word)t7);
    return t8;
}

/* Swing_DLL.xex 0x88638FC8: if_call_seq lbl_880F63C0, u32@0x0, u32@0x20, u32@0x1c, ts4_loop_call_seq_u32_off0_88150378, u32@0x1c */
ts4_word ts4_if_call_seq_lbl_880F63C0_88638FC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F63C0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x886475A8: if_call_seq lbl_880F5FEC, u32@0x0, u32@0x28, ts4_destroy_owned_object, u32@0x1c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F5FEC_886475A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5FEC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8864AB90: if_call_seq lbl_880F604C, u32@0x0, u32@0x88, ts4_destroy_owned_object, u32@0x7c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F604C_8864AB90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F604C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x88660AB0: if_set u32@0x4, u32@0x0, u32@0x8c, u32@0xc */
void ts4_if_set_u32_off4_88660AB0(ts4_word a0, ts4_word a1)
{
    ts4_word p3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)lbl_8814B440);
    p3 = (ts4_word)0;
    if ((ts4_word)a1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 140));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p3;
    return;
}

/* Swing_DLL.xex 0x88660E38: if_get u32@0x18, u32@0x48, u32@0x30, u8@0x32b, u8@0x0 */
void ts4_if_get_u32_off18_88660E38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t4;

    t4 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 72))) + 48))) + 811);
    if ((ts4_word)t4 != 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a2) + 0) = (unsigned char)((((3155623936) | 35317) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x88663190: if_get u32@0x3c, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off3c_88663190(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t2 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88666078: if_get u8@0x4, u32@0x24, u32@0x24, u32@0x10c, u32@0x10c */
void ts4_if_get_u8_off4_88666078(ts4_word a0, ts4_word a1)
{
    unsigned char t1;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t3 != (ts4_word)a1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 268)) + 1);
    return;
}

/* Swing_DLL.xex 0x88668BF8: if_get u32@0x20, u8@0x99, u32@0xd0, u32@0xd0, u32@0xd8, u32@0x28 */
void ts4_if_get_u32_off20_88668BF8(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 153);
    if ((ts4_word)t2 != 0) {
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 208);
    if ((ts4_word)t4 == (ts4_word)((3374514176) | 34673)) {
        return;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 216);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 24) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 28) = (ts4_word)(t5 ^ 1);
    return;
}

/* Swing_DLL.xex 0x8866AAB8: loop_get u32@0x4, u32@0x8, u32@0x4, u32@0x0, u32@0x74, u32@0x304 */
void ts4_loop_get_u32_off4_8866AAB8(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    if ((ts4_word)t3 == (ts4_word)t2) {
        return;
    }
    lv4 = (ts4_word)t3;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((ts4_word)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 116))) + 772) = (ts4_word)((2865037312) | 15937);
        }
        p8 = (ts4_word)(lv4 + 4);
        lv4 = p8;
    } while ((ts4_word)p8 != (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x8866D2C8: loop_call_seq u32@0x18, u32@0x10, u32@0xc, ts4_set_u8_off0_8826B918, u32@0x1c, u32@0x20 */
ts4_word ts4_loop_call_seq_u32_off18_8866D2C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    p6 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = ts4_set_u8_off0_8826B918((ts4_word)lv3);
            p5 = (ts4_word)(lv3 + 16);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
        p6 = (ts4_word)t4;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x8866FAE0: loop_get u32@0xc, u32@0x8, u32@0x0, u8@0x4, u32@0x4, u32@0x98 */
ts4_word ts4_loop_get_u32_offc_8866FAE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word lv12;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t18;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 4) = (unsigned char)0;
            p5 = (ts4_word)(lv3 + 4);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 152);
    t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 148);
    if ((ts4_word)t11 != (ts4_word)t10) {
        lv12 = (ts4_word)t11;
        do {
            ts4_set_u8_off0_88401F80((ts4_word)lv12);
            p14 = (ts4_word)(lv12 + 16);
            lv12 = p14;
        } while ((ts4_word)p14 != (ts4_word)t10);
    }
    t18 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80);
    t21 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 0))) + 32))))((ts4_word)t18);
    return t21;
}

/* Swing_DLL.xex 0x886716A0: if_call_seq lbl_880F4420, u32@0x0, u32@0xc, u32@0x8, ts4_loop_get_u32_off0_8826DFB8, u32@0x8 */
ts4_word ts4_if_call_seq_lbl_880F4420_886716A0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4420;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_loop_get_u32_off0_8826DFB8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88671A28: loop_get u32@0x10, u32@0x14, u32@0x0, fn_88662E58, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off10_88671A28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word p11;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p12 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            fn_88662E58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0)));
            t6 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            p10 = (ts4_word)t6;
            if ((ts4_word)t6 != 0) {
                t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 0))))((ts4_word)t6, (ts4_word)1);
                p10 = (ts4_word)t9;
            }
            p11 = (ts4_word)(lv3 + 4);
            lv3 = p11;
        } while ((ts4_word)p11 != (ts4_word)t2);
        p12 = (ts4_word)p10;
    }
    return p12;
}

/* Swing_DLL.xex 0x88673E40: if_call_seq u32@0x20, u8@0x94, u32@0x38, ts4_shot_reward_list_push_88673630, u32@0x20, u8@0x98 */
ts4_word ts4_if_call_seq_u32_off20_88673E40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word p10;
    unsigned char t2;
    ts4_word t4;
    unsigned char t7;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 148);
    p5 = (ts4_word)a0;
    if ((ts4_word)t2 != 0) {
        t4 = ts4_shot_reward_list_push_88673630((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)), (ts4_word)((4245749760) | 37718));
        p5 = (ts4_word)t4;
    }
    t7 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + 152);
    p10 = (ts4_word)p5;
    if ((ts4_word)t7 != 0) {
        t9 = ts4_shot_reward_list_push_88673630((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)), (ts4_word)((2300313600) | 7138));
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x88678468: if_call_seq u32@0x1c, fn_8826ACB8, fn_8866DD78, u32@0x1c, fn_8826ACB8, fn_8866DD78 */
ts4_word ts4_if_call_seq_u32_off1c_88678468(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p8;
    ts4_word p9;
    ts4_word p10;
    ts4_word p16;
    ts4_word loc50[1];
    ts4_word loc58[1];
    ts4_word loc54[1];
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 <= (int)((4142596096) | 26166)) {
        if ((int)a1 == (int)((4142596096) | 26166)) {
            *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 116))) + 1505) = (unsigned char)0;
        }
        p16 = (ts4_word)a0;
    } else {
        if ((int)a1 != (int)((895746048) | 39298)) {
            p9 = (ts4_word)a0;
            if ((int)a1 == (int)((1703608320) | 11793)) {
                t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
                loc50[0] = (ts4_word)((1191575552) | 245);
                t6 = fn_8826ACB8((ts4_word)(t5 + 148), (ts4_word)(ts4_word)&loc50[0]);
                p8 = (ts4_word)t6;
                if ((ts4_word)(t6 & 0xff) != 0) {
                    loc54[0] = (ts4_word)((1191575552) | 245);
                    t7 = fn_8866DD78((ts4_word)t5, (ts4_word)(ts4_word)&loc54[0]);
                    p8 = (ts4_word)t7;
                }
                p9 = (ts4_word)p8;
            }
            p10 = (ts4_word)p9;
        } else {
            t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            loc50[0] = (ts4_word)((1191575552) | 245);
            t2 = fn_8826ACB8((ts4_word)(t1 + 148), (ts4_word)(ts4_word)&loc50[0]);
            p4 = (ts4_word)t2;
            if ((ts4_word)(t2 & 0xff) != 0) {
                loc58[0] = (ts4_word)((1191575552) | 245);
                t3 = fn_8866DD78((ts4_word)t1, (ts4_word)(ts4_word)&loc58[0]);
                p4 = (ts4_word)t3;
            }
            p10 = (ts4_word)p4;
        }
        p16 = (ts4_word)p10;
    }
    return p16;
}

/* Swing_DLL.xex 0x886799B8: get fn_8817B608 */
ts4_word ts4_get_fn_8817B608_886799B8(ts4_word a0)
{
    float t1;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    *(float *)((char *)(ts4_word)(a0) + 0) = (t1 + (*(float *)lbl_880C88DC));
    return fn_8817B608((ts4_word)a0);
}

/* Swing_DLL.xex 0x88679F48: if_call_seq lbl_880F43E8, u32@0x0, u32@0xc, ts4_destroy_owned_object, lbl_880F436C, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F43E8_88679F48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F43E8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_destroy_owned_object((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F436C;
    return p3;
}

/* Swing_DLL.xex 0x8867B910: if_call_seq lbl_880F4340, u32@0x0, u32@0x1c, ts4_destroy_owned_object, u32@0x4, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F4340_8867B910(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4340;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8867C828: if_call_seq fn_8865A5E0, u32@0x88, u32@0x7c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_fn_8865A5E0_8867C828(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    fn_8865A5E0((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = ts4_destroy_owned_object((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8867E758: if_call_seq lbl_880F44EC, u32@0x0, u32@0x3c, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F44EC_8867E758(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F44EC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x886811B8: if_get u32@0x14, fn_8890E988 */
ts4_word ts4_if_get_u32_off14_886811B8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_8890E988((ts4_word)(a0 + 92));
}

/* Swing_DLL.xex 0x886811D8: if_get u32@0x48, u8@0x4, fn_8890E988 */
ts4_word ts4_if_get_u32_off48_886811D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char t2;

    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 72))) + 4);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    return fn_8890E988((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x886829D0: if_call_seq lbl_880F4C50, u32@0x0, u32@0x24, ts4_destroy_owned_object, lbl_880F4550, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F4C50_886829D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4C50;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4550;
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8868C910: if_get u32@0x1c, u8@0x10, fn_8867DB30 */
ts4_word ts4_if_get_u32_off1c_8868C910(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 16);
    if ((ts4_word)t2 != 0) {
        return a0;
    }
    return fn_8867DB30((ts4_word)(a0 + 80), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88691900: loop_call_seq fn_886917F8, u32@0x0, u32@0x4, u32@0x0, u32@0x4, fn_8866DE40 */
ts4_word ts4_loop_call_seq_fn_886917F8_88691900(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word lv6;
    ts4_word p10;
    ts4_word p11;
    ts4_word loc50[1];
    ts4_word t1;
    int t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t1 = fn_886917F8((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    p4 = (ts4_word)0;
    if ((int)t2 != -1) {
        p4 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a2) + 4)) << 2) + t2) + a2);
    }
    p5 = (ts4_word)0;
    if ((int)t2 != -1) {
        p5 = (ts4_word)(t2 + a2);
    }
    p11 = (ts4_word)t1;
    if ((ts4_word)p5 != (ts4_word)p4) {
        lv6 = (ts4_word)p5;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            loc50[0] = (ts4_word)t7;
            t9 = fn_8866DE40((ts4_word)t8, (ts4_word)(ts4_word)&loc50[0]);
            p10 = (ts4_word)(lv6 + 4);
            lv6 = p10;
        } while ((ts4_word)p10 != (ts4_word)p4);
        p11 = (ts4_word)t9;
    }
    return p11;
}

/* Swing_DLL.xex 0x886970B8: call_seq u32@0x14, fn_88696D40, u32@0x14, u32@0x0 */
ts4_word ts4_call_seq_u32_off14_886970B8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88696D40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    *(ts4_word *)((char *)(ts4_word)(((t3 + 169) << 2)) + a0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(((t3 + 83) << 2)) + a0))) + 0));
    return t2;
}

/* Swing_DLL.xex 0x8869DED0: get u32@0x48, u32@0x74, u32@0xc0, u32@0xb8, u32@0x30, u32@0x310 */
ts4_word ts4_get_u32_off48_8869DED0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 192);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    return fn_88692468((ts4_word)t4, (ts4_word)t3, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 48))) + 784)), (ts4_word)1);
}

/* Swing_DLL.xex 0x8869FD70: get u32@0x20, u8@0x4, fn_88691888 */
ts4_word ts4_get_u32_off20_8869FD70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    *(unsigned char *)((char *)(ts4_word)(a1) + 4) = (unsigned char)0;
    return fn_88691888((ts4_word)(a0 + 32), (ts4_word)(t1 + 32));
}

/* Swing_DLL.xex 0x886A31B8: if_call_seq u32@0x154, u32@0x2c, u8@0x1b8, u8@0x1b8, u32@0x154, u32@0x2c */
ts4_word ts4_if_call_seq_u32_off154_886A31B8(ts4_word a0)
{
    ts4_word t2;
    unsigned char t3;
    ts4_word t9;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44);
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)0;
    fn_8869AB70((ts4_word)(a0 + 56), (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 552));
    fn_8868AF88((ts4_word)(a0 + 56));
    ts4_selection_scorer_score_both_sides_88689AF0((ts4_word)(a0 + 56), (ts4_word)0);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)t3;
    t9 = fn_8865D8D8((ts4_word)a0);
    if ((ts4_word)(t9 & 0xff) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 552);
    }
    return t9;
}

/* Swing_DLL.xex 0x886A3238: if_call_seq u32@0x154, u32@0x2c, u8@0x1b8, u8@0x1b8, u32@0x154, u32@0x2c */
ts4_word ts4_if_call_seq_u32_off154_886A3238(ts4_word a0)
{
    ts4_word t2;
    unsigned char t3;
    ts4_word t9;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44);
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)0;
    fn_8869AB70((ts4_word)(a0 + 56), (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 536));
    fn_8868AF88((ts4_word)(a0 + 56));
    ts4_selection_scorer_score_both_sides_88689AF0((ts4_word)(a0 + 56), (ts4_word)0);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)t3;
    t9 = fn_8865D8D8((ts4_word)a0);
    if ((ts4_word)(t9 & 0xff) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 536);
    }
    return t9;
}

/* Swing_DLL.xex 0x886A33C0: if_call_seq u32@0x154, u32@0x2c, u8@0x1b8, u8@0x1b8, u32@0x154, u32@0x2c */
ts4_word ts4_if_call_seq_u32_off154_886A33C0(ts4_word a0)
{
    ts4_word t2;
    unsigned char t3;
    ts4_word t9;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44);
    t3 = *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)0;
    fn_8869AB70((ts4_word)(a0 + 56), (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 520));
    fn_8868AF88((ts4_word)(a0 + 56));
    ts4_selection_scorer_score_both_sides_88689AF0((ts4_word)(a0 + 56), (ts4_word)0);
    *(volatile unsigned char *)((char *)(ts4_word)(t2) + 440) = (unsigned char)t3;
    t9 = fn_8865D8D8((ts4_word)a0);
    if ((ts4_word)(t9 & 0xff) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 340))) + 44)) + 520);
    }
    return t9;
}

/* Swing_DLL.xex 0x886A6E48: loop_call_seq u32@0x7c, u32@0x78, u32@0x0, fn_886A6860 */
ts4_word ts4_loop_call_seq_u32_off7c_886A6E48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120);
    p7 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t5 = fn_886A6860((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0)));
            p6 = (ts4_word)(lv3 + 4);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t1);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x886A6F78: loop_get u32@0x84, fn_889C0BC8, u32@0x7c, u32@0x78, u32@0x0, fn_886A65F8 */
ts4_word ts4_loop_get_u32_off84_886A6F78(ts4_word a0)
{
    ts4_word lv5;
    ts4_word p8;
    ts4_word p23;
    ts4_word t3;
    ts4_word t4;
    ts4_word t19;
    ts4_word t22;

    fn_889C0BC8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 132)));
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120);
    if ((ts4_word)t4 != (ts4_word)t3) {
        lv5 = (ts4_word)t4;
        do {
            fn_886A65F8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv5) + 0)));
            p8 = (ts4_word)(lv5 + 4);
            lv5 = p8;
        } while ((ts4_word)p8 != (ts4_word)t3);
    }
    *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 120))) + 0))) + 68))) + 93) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 120))) + 0))) + 68))) + 116) = (unsigned char)0;
    fn_886A6E98((ts4_word)a0);
    fn_8867BCF8((ts4_word)a0);
    t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    p23 = (ts4_word)t19;
    if ((ts4_word)t19 != 0) {
        t22 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t19) + 0))) + 0))))((ts4_word)t19, (ts4_word)1);
        p23 = (ts4_word)t22;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    return p23;
}

/* Swing_DLL.xex 0x886A7F38: if_call_seq ts4_object_finalize, ts4_object_finalize, u32@0x24, u32@0x20, u32@0x14, u32@0x10 */
ts4_word ts4_if_call_seq_ts4_object_finalize_886A7F38(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    ts4_object_finalize((ts4_word)(a0 + 40));
    ts4_object_finalize((ts4_word)(a0 + 52));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 40)) + 0);
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_destroy_owned_object((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x886AB080: loop_call_seq u32@0xc0, u8@0x0, u32@0x7c, u32@0x78, u32@0x0, fn_886AA748 */
ts4_word ts4_loop_call_seq_u32_offc0_886AB080(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv5;
    ts4_word p8;
    ts4_word p9;
    ts4_word p11;
    int t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192);
    p11 = (ts4_word)a0;
    if ((int)t1 == 0 || (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(t1) + 0)) == 0) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124);
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120);
        p9 = (ts4_word)a0;
        if ((ts4_word)t4 != (ts4_word)t3) {
            lv5 = (ts4_word)t4;
            do {
                t7 = fn_886AA748((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv5) + 0)));
                p8 = (ts4_word)(lv5 + 4);
                lv5 = p8;
            } while ((ts4_word)p8 != (ts4_word)t3);
            p9 = (ts4_word)t7;
        }
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x886AC790: addr lbl_880C8F40, fn_8862BE08, u32@0x0, u32@0x28, vcall */
ts4_word ts4_addr_lbl_880C8F40_886AC790(void)
{
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C8F40);
    t2 = loc50[0];
    t3 = loc50[1];
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t3, (ts4_word)4);
    return t6;
}

/* Swing_DLL.xex 0x886C3AE0: get u32@0x5c, u32@0x60 */
ts4_word ts4_get_u32_off5c_886C3AE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    return (((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 96)) - t1) == 0);
}

/* Swing_DLL.xex 0x886C4E48: get u32@0x8 */
void ts4_get_u32_off8_886C4E48(ts4_word a0, float f1)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(volatile float *)((char *)(ts4_word)(t1) + 68) = ((*(float *)((char *)(ts4_word)(t1) + 68)) + f1);
    *(volatile float *)((char *)(ts4_word)(a0) + 32) = ((*(float *)((char *)(ts4_word)(a0) + 32)) + f1);
    return;
}

/* Swing_DLL.xex 0x886C7288: get u32@0x8 */
void ts4_get_u32_off8_886C7288(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    float t2;
    float t3;
    float t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(float *)((char *)(ts4_word)(a1) + 4);
    t3 = *(float *)((char *)(ts4_word)(a1) + 0);
    t4 = *(float *)((char *)(ts4_word)(t1) + 20);
    *(volatile float *)((char *)(ts4_word)(a1) + 8) = ((t2 - t3) * (t4 - (*(float *)g_ts4_script_constants)));
    return;
}

/* Swing_DLL.xex 0x886C7E78: if_get u32@0x2c, u32@0x5c, u32@0x60, u32@0x2c, u32@0x60, u32@-0x4 */
float ts4_if_get_u32_off2c_886C7E78(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    float t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 92);
    t3 = *(float *)((char *)(ts4_word)(t1) + 24);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 96);
    if ((ts4_word)t2 == (ts4_word)t4) {
        return ((*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 1076)) - t3);
    }
    return ((*(float *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44))) + 96))) + -4))) + 40)) - t3);
}

/* Swing_DLL.xex 0x886E81D8: call_seq fn_88617D88, lbl_880F3510, u8@0x21, u8@0x20, u32@0x0, u32@0x1c */
ts4_word ts4_call_seq_fn_88617D88_886E81D8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3510;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x886E8308: loop_call_seq u32@0x1c, u32@0x8, u32@0x4, u32@0x1c, u32@0x0, u32@0x1c */
ts4_word ts4_loop_call_seq_u32_off1c_886E8308(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word p10;
    ts4_word lv12;
    ts4_word p14;
    ts4_word p15;
    ts4_word t1;
    ts4_word t3;
    int t4;
    ts4_word t6;
    int t7;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    p5 = (ts4_word)0;
    if ((int)t4 != -1) {
        p5 = (ts4_word)(t4 + t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
    p10 = (ts4_word)0;
    if ((int)t7 != -1) {
        p10 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(t6) + 4)) * 368) + t7) + t6);
    }
    p15 = (ts4_word)a0;
    if ((ts4_word)p5 != (ts4_word)p10) {
        lv12 = (ts4_word)p5;
        do {
            t13 = fn_88262528((ts4_word)lv12);
            p14 = (ts4_word)(lv12 + 368);
            lv12 = p14;
        } while ((ts4_word)p14 != (ts4_word)p10);
        p15 = (ts4_word)t13;
    }
    return p15;
}

/* Swing_DLL.xex 0x886E9440: if_call_seq lbl_880F3540, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880F3540_886E9440(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3540;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x886EB288: if_fn  */
ts4_word ts4_if_fn_886EB288(int a0)
{
    if ((int)a0 <= 511) {
        return a0;
    }
    return (a0 + -1024);
}

/* Swing_DLL.xex 0x886EBD48: get u32@lbl_88D45A94 */
ts4_word ts4_get_u32_lbl_88D45A94_886EBD48(void)
{
    return ((*(volatile ts4_word *)lbl_88D45A94) != 0);
}

/* Swing_DLL.xex 0x886EBD78: get u32@0x70, lbl_88D48CC0 */
ts4_word ts4_get_u32_off70_886EBD78(ts4_word a0)
{
    return (((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 112)) * 76) + (ts4_word)lbl_88D48CC0);
}

/* Swing_DLL.xex 0x886EBEB0: loop_get u32@0x0, u32@0x4, u32@0x11c */
ts4_word ts4_loop_get_u32_off0_886EBEB0(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    int t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 < (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 284);
            if ((int)t4 != 3 && (int)t4 != 0) {
                return 0;
            }
            p5 = (ts4_word)(lv3 + 308);
            lv3 = p5;
        } while ((ts4_word)p5 < (ts4_word)t2);
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x886EC078: get u8@0x0, u8@0x1, u8@0x1, u8@0x0 */
void ts4_get_u8_off0_886EC078(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;

    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    return;
}

/* Swing_DLL.xex 0x886EC090: get u8@0x0, u8@0x3, u8@0x2, u8@0x1, u8@0x3, u8@0x0 */
void ts4_get_u8_off0_886EC090(ts4_word a0)
{
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 3);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 2);
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)t1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)t2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)t3;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)t4;
    return;
}

/* Swing_DLL.xex 0x886EC488: get u32@lbl_88D45AD4, u32@0xa0, u32@0x20, u32@0x328 */
void ts4_get_u32_lbl_88D45AD4_886EC488(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 808) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 160))) + 32)) + ((int)a1 * 176)) + 32);
    return;
}

/* Swing_DLL.xex 0x886ECB38: if_get u32@lbl_88D45AD4, u32@0x20, u32@0x218, g_ts4_script_constants */
float ts4_if_get_u32_lbl_88D45AD4_886ECB38(void)
{
    int t3;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 32))) + 536);
    if ((int)t3 == 1) {
        return (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 312));
    }
    return (*(float *)((char *)(ts4_word)((ts4_word)g_ts4_script_constants) + 316));
}

/* Swing_DLL.xex 0x886ECCE8: if_get u32@lbl_88D45AD4, u32@0x24, u32@0x54 */
ts4_word ts4_if_get_u32_lbl_88D45AD4_886ECCE8(ts4_word a0, int a1)
{
    (void)a0;
    if ((int)a1 != -1) {
        return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 36))) + 84)) + ((int)a1 * 60));
    }
    return 0;
}

/* Swing_DLL.xex 0x886ECD60: loop_get u32@0x48, u32@0x44, u32@0x0, u32@0x0, u32@0x38, vcall */
ts4_word ts4_loop_get_u32_off48_886ECD60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 56))))((ts4_word)t4, (ts4_word)a1);
            }
            p9 = (ts4_word)(lv3 + 4);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t1);
    }
    return 1;
}

/* Swing_DLL.xex 0x886ED040: loop_get u32@lbl_88D45AD4, u32@0x1d54, u32@0x1d58, u8@0xa5, u8@0xa5 */
void ts4_loop_get_u32_lbl_88D45AD4_886ED040(ts4_word a0, int a1)
{
    ts4_word lv4;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    unsigned char t5;

    t1 = *(ts4_word *)lbl_88D45AD4;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 7508);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 7512);
    if ((ts4_word)t2 == (ts4_word)t3) {
        return;
    }
    lv4 = (ts4_word)t2;
    do {
        t5 = *(unsigned char *)((char *)(ts4_word)(lv4) + 165);
        if ((int)((signed char)t5) == (int)a1) {
            *(unsigned char *)((char *)(ts4_word)(lv4) + 165) = (unsigned char)a0;
        }
        p6 = (ts4_word)(lv4 + 176);
        lv4 = p6;
    } while ((ts4_word)p6 != (ts4_word)t3);
    return;
}

/* Swing_DLL.xex 0x886ED748: get u32@0x3c */
ts4_word ts4_get_u32_off3c_886ED748(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 140) + (*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
}

/* Swing_DLL.xex 0x886EED30: if_get u32@0x34, u32@0x0, u32@0x8, u32@lbl_88D45B1C, u32@0x18, u32@0x27c */
ts4_word ts4_if_get_u32_off34_886EED30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p12;
    ts4_word p16;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t15;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t4 = *(ts4_word *)lbl_88D45B1C;
        t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 24);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t5))((ts4_word)a0, (ts4_word)(t3 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 636)));
        t8 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
        if ((ts4_word)t8 == (ts4_word)((1994326016) | 41423)) {
            t15 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0, (ts4_word)t3);
            p16 = (ts4_word)t15;
        } else {
            if ((ts4_word)t8 == (ts4_word)((1589051392) | 35677)) {
                t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 124))))((ts4_word)a0, (ts4_word)t3);
                p12 = (ts4_word)t11;
            } else {
                p12 = (ts4_word)0;
            }
            p16 = (ts4_word)p12;
        }
        p17 = (ts4_word)p16;
    } else {
        p17 = (ts4_word)0;
    }
    return p17;
}

/* Swing_DLL.xex 0x886EEF48: if_get u32@0x44, u32@0x0, u32@0x58, vcall, u32@0x44, u32@0x40 */
ts4_word ts4_if_get_u32_off44_886EEF48(ts4_word a0)
{
    int t1;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((int)t1 != -1) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
            return ((*(ts4_word *)((char *)(ts4_word)(t4) + 64)) + (t5 << 6));
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x886EEFC0: if_get u32@0x4c, u32@lbl_88D45AD4, u32@0xa0, u32@0x20 */
ts4_word ts4_if_get_u32_off4c_886EEFC0(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((int)t1 != -1) {
        return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 160))) + 32)) + ((int)t1 * 176)) + 32);
    }
    return 0;
}

/* Swing_DLL.xex 0x886EF078: if_get u32@0x4, u32@0x8, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off4_886EF078(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 == (ts4_word)((3480354816) | 6071) && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) != (ts4_word)((1982136320) | 73)) {
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
        p9 = (ts4_word)t5;
        if ((ts4_word)(t5 & 0xff) != 0) {
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)0);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    }
    return p10;
}

/* Swing_DLL.xex 0x886EF2E0: if_get u32@lbl_88D45AD4 */
ts4_word ts4_if_get_u32_lbl_88D45AD4_886EF2E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45AD4;
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return (*(unsigned char *)((char *)(ts4_word)(((a0 & 0xff) + t1)) + ((65536) | 22080)));
}

/* Swing_DLL.xex 0x886EF6C8: get u32@0x48, u32@0x4c, u32@0x50, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off48_886EF6C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 80);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x886EF6E8: get u32@0x3c, u32@0x40, u32@0x44, u32@0x0, u32@0x4, u32@0x8 */
void ts4_get_u32_off3c_886EF6E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    return;
}

/* Swing_DLL.xex 0x886EF708: if_get u32@0x4, u32@0x8, u32@0x8, u32@0xc, u32@0x44, u8@0x10 */
void ts4_if_get_u32_off4_886EF708(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 == (ts4_word)((806551552) | 42270)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 288) = (unsigned char)1;
        return;
    }
    if ((ts4_word)t1 == (ts4_word)((1005715456) | 13608)) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(unsigned char *)((char *)(ts4_word)((((int)t7 * 44) + (*(ts4_word *)((char *)(ts4_word)(a0) + 68)))) + 16) = (unsigned char)1;
        return;
    }
    if ((ts4_word)t1 != (ts4_word)((3480354816) | 6071)) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t3 != (ts4_word)((1982136320) | 73)) {
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(unsigned char *)((char *)(ts4_word)((((int)t4 * 44) + (*(ts4_word *)((char *)(ts4_word)(a0) + 68)))) + 16) = (unsigned char)1;
    *(float *)((char *)(ts4_word)(a0) + 308) = (*(float *)((char *)(ts4_word)(a1) + 32));
    return;
}

/* Swing_DLL.xex 0x886F0180: if_get u32@0x54, u32@0x60, u8@0xc, u32@0x64, u8@0x3a */
ts4_word ts4_if_get_u32_off54_886F0180(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((int)t1 == 1) {
        return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 100))) + 58));
    }
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 12));
}

/* Swing_DLL.xex 0x886F1C98: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_886F1C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Swing_DLL.xex 0x886F1E70: if_set u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_set_u32_off0_886F1E70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 >= 3) {
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2045247488) | 6472);
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((250544128) | 10718);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2548432896) | 30820);
    return;
}

/* Swing_DLL.xex 0x886F1EC0: if_set u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_set_u32_off0_886F1EC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 >= 3) {
                return;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3922657280) | 11493);
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((2555576320) | 38160);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((3727556608) | 52086);
    return;
}

/* Swing_DLL.xex 0x886F1F10: get u32@0x4, u32@lbl_88D45AD4, u32@0x24, u32@0x84, fn_886EDB70 */
ts4_word ts4_get_u32_off4_886F1F10(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return fn_886EDB70((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 36))) + 132)) + ((t1 + (t1 << 2)) << 2)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x886F1F38: get u32@0x4, u32@lbl_88D45AD4, u32@0x24, u32@0x84, fn_886EDBC8 */
ts4_word ts4_get_u32_off4_886F1F38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return fn_886EDBC8((ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 36))) + 132)) + ((t1 + (t1 << 2)) << 2)), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886F1F60: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x18 */
ts4_word ts4_call_seq_u32_off0_886F1F60(ts4_word a0)
{
    ts4_word loc50[6];

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    fn_88222528((ts4_word)(a0 + 28), (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x886F24F8: addr lbl_880F2C8C, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2C8C_886F24F8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2C8C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2660: addr lbl_880F2BF0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2BF0_886F2660(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2BF0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2688: addr lbl_880F2958, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2958_886F2688(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2958;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2700: addr lbl_880F2A74, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2A74_886F2700(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2A74;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2CF0: addr lbl_880F2B70, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2B70_886F2CF0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2B70;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2D18: addr lbl_880F2AF0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2AF0_886F2D18(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2AF0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2D40: addr lbl_880F29F8, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F29F8_886F2D40(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F29F8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F2F10: addr lbl_880F26D0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F26D0_886F2F10(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F26D0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3198: addr lbl_880F2668, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2668_886F3198(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2668;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F31C0: loop_get u32@0x88, u32@0x84, u32@0x0, u32@0x0, u8@0x8 */
void ts4_loop_get_u32_off88_886F31C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return;
    }
    lv3 = (ts4_word)t2;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0))) + 0);
        if ((ts4_word)t5 != 0) {
            *(unsigned char *)((char *)(ts4_word)(t5) + 8) = (unsigned char)a1;
        }
        p6 = (ts4_word)(lv3 + 4);
        lv3 = p6;
    } while ((ts4_word)p6 != (ts4_word)t1);
    return;
}

/* Swing_DLL.xex 0x886F3290: addr lbl_880F2410, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2410_886F3290(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2410;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F33A0: addr lbl_880F22D4, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F22D4_886F33A0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F22D4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3678: addr lbl_880F24A4, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F24A4_886F3678(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F24A4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3828: addr lbl_880F23AC, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F23AC_886F3828(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F23AC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3A80: addr lbl_880F2738, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2738_886F3A80(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2738;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3AB0: addr lbl_880F2530, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2530_886F3AB0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2530;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3AE0: addr lbl_880F259C, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F259C_886F3AE0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F259C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F3C00: addr lbl_880F2600, u32@0x4, u32@0x8, u32@0x0, u32@0x4, u32@0x8 */
void ts4_addr_lbl_880F2600_886F3C00(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2600;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F5700: loop_get u32@0x0, u32@0x4, u32@0x0, u8@0x8, u32@0x0, u32@0x8 */
ts4_word ts4_loop_get_u32_off0_886F5700(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    unsigned char t5;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p11 = (ts4_word)a0;
    if ((ts4_word)t1 < (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t5 = *(unsigned char *)((char *)(ts4_word)(t4) + 8);
            p9 = (ts4_word)t4;
            if ((ts4_word)t5 != 0) {
                t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4);
                p9 = (ts4_word)t8;
            }
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 < (ts4_word)t2);
        p11 = (ts4_word)p9;
    }
    return p11;
}

/* Swing_DLL.xex 0x886F5DF0: loop_call_seq ts4_object_finalize, u32@0x58, u32@0x54, u32@0x0, u32@0x8, u32@0xc */
ts4_word ts4_loop_call_seq_ts4_object_finalize_886F5DF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv4;
    ts4_word p15;
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t18;

    ts4_object_finalize((ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
    while ((ts4_word)lv4 != (ts4_word)t2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
        loc50[0] = (ts4_word)t5;
        if ((ts4_word)a2 == (ts4_word)t6) {
            t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
            t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
            if ((ts4_word)t10 != (ts4_word)t9) {
                if ((ts4_word)t10 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)t5;
                }
                *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 4)) + 4);
            } else {
                fn_8816DD48((ts4_word)a1, (ts4_word)t10, (ts4_word)(ts4_word)&loc50[0]);
            }
        }
        p15 = (ts4_word)(lv4 + 4);
        lv4 = p15;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return ((int)(t18 - (*(ts4_word *)((char *)(ts4_word)(a1) + 0))) >> 2);
}

/* Swing_DLL.xex 0x886F78C8: if_get fn_88150770, u32@0x0, u32@0x50, vcall, fn_88608590, fn_886ED860 */
ts4_word ts4_if_get_fn_88150770_886F78C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[1];
    ts4_word loc58[2];
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    loc50[0] = (ts4_word)0;
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 < 3) {
                loc50[0] = (ts4_word)((2045247488) | 6472);
            }
        } else {
            loc50[0] = (ts4_word)((250544128) | 10718);
        }
    } else {
        loc50[0] = (ts4_word)((2548432896) | 30820);
    }
    fn_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc58[0];
    t9 = loc58[1];
    t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 80))))((ts4_word)t8, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t9, (ts4_word)1);
    t13 = fn_88608590((ts4_word)0, (ts4_word)t12);
    t14 = fn_886ED860((ts4_word)t13);
    return t14;
}

/* Swing_DLL.xex 0x886F9088: get ts4_if_call_seq_u32_off0_8828B128, ts4_if_call_seq_u32_off0_8828B128, u32@lbl_88D45A4C, u32@0x154, u32@0x4, vcall */
ts4_word ts4_get_fn_8828B128_886F9088(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[10];
    ts4_word t3;
    ts4_word t10;

    ts4_if_call_seq_u32_off0_8828B128((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_u32_off0_8828B128((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    t3 = *(ts4_word *)lbl_88D45A4C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 340))) + 4))))((ts4_word)(t3 + 340));
    fn_882C5EA8((ts4_word)a1, (ts4_word)0, (ts4_word)0, (ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)1, (ts4_word)0);
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 340))) + 8))))((ts4_word)(t3 + 340));
    return t10;
}

/* Swing_DLL.xex 0x886FC0A8: loop_call_seq u32@0x94, u32@0x0, u32@0x0, u32@0x94, u32@0x88, u32@0x84 */
ts4_word ts4_loop_call_seq_u32_off94_886FC0A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv6;
    ts4_word p9;
    ts4_word p10;
    ts4_word p12;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    p12 = (ts4_word)a0;
    if ((ts4_word)(a2 & 0xff) != 0 || (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0)) != (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 148))) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0));
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132);
        p10 = (ts4_word)a0;
        if ((ts4_word)t5 != (ts4_word)t4) {
            lv6 = (ts4_word)t5;
            do {
                t8 = fn_886FBF18((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv6) + 0)), (ts4_word)a1);
                p9 = (ts4_word)(lv6 + 4);
                lv6 = p9;
            } while ((ts4_word)p9 != (ts4_word)t4);
            p10 = (ts4_word)t8;
        }
        p12 = (ts4_word)p10;
    }
    return p12;
}

/* Swing_DLL.xex 0x8870FFF0: if_get u32@0x34, u32@0xc, u32@0xc, fn_8870FE00 */
ts4_word ts4_if_get_u32_off34_8870FFF0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    float t4;
    float t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    t4 = *(float *)((char *)(ts4_word)(t3) + 16);
    t5 = *(float *)lbl_8814B440;
    if (!(t4 > t5)) {
        return a0;
    }
    *(float *)((char *)(ts4_word)(t3) + 16) = t5;
    return fn_8870FE00((ts4_word)a0);
}

/* Swing_DLL.xex 0x88710028: if_get u32@0x34, u32@0xc, u32@0xc, u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_if_get_u32_off34_88710028(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    float t8;
    float t9;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t5 != (ts4_word)((80281600) | 473)) {
        return a0;
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t7 == 0) {
        return a0;
    }
    t8 = *(float *)((char *)(ts4_word)(t7) + 16);
    t9 = *(float *)lbl_8814B440;
    if (!(t8 > t9)) {
        return a0;
    }
    *(volatile float *)((char *)(ts4_word)(t7) + 16) = t9;
    return fn_8870FE00((ts4_word)a0);
}

/* Swing_DLL.xex 0x88713190: loop_call_seq u32@0x18d4, u32@0x8, fn_88702A88, fn_8815D480 */
ts4_word ts4_loop_call_seq_u32_off18d4_88713190(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 6356);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    p7 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            fn_88702A88((ts4_word)(lv3 + 20));
            t5 = fn_8815D480((ts4_word)lv3);
            p6 = (ts4_word)t5;
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t1);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x887140B8: if_call_seq u32@0x88, fn_881AC778, u32@0x4, u32@0x4, u32@0x88, u32@0x88 */
ts4_word ts4_if_call_seq_u32_off88_887140B8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)15;
    loc50[0] = (ts4_word)((789184512) | 28378);
    t1 = fn_881AC778((ts4_word)(a1 + 60), (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t3 == (ts4_word)((1466368000) | 57173)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)1;
        } else {
            if ((ts4_word)t3 == (ts4_word)((985268224) | 15294)) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)2;
            } else {
                if ((ts4_word)t3 == (ts4_word)((1255145472) | 53041)) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)4;
                } else {
                    if ((ts4_word)t3 == (ts4_word)((3554213888) | 40587)) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)8;
                    } else {
                        if ((ts4_word)t3 == (ts4_word)((4127260672) | 57329)) {
                            *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)15;
                        }
                    }
                }
            }
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x887141A0: if_call_seq fn_881AC778, u32@0x4, u32@0x7c, u32@0x4, u32@0x7c, u32@0x7c */
ts4_word ts4_if_call_seq_fn_881AC778_887141A0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;

    loc50[0] = (ts4_word)((437977088) | 14216);
    t1 = fn_881AC778((ts4_word)(a1 + 60), (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t3 == (ts4_word)((1469120512) | 45015)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)1;
        } else {
            if ((ts4_word)t3 == (ts4_word)((537133056) | 42082)) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)3;
            } else {
                if ((ts4_word)t3 == (ts4_word)((4060217344) | 11254)) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)4;
                } else {
                    if ((ts4_word)t3 == (ts4_word)((3160866816) | 14133)) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)5;
                    } else {
                        if ((ts4_word)t3 != (ts4_word)((3452764160) | 33048)) {
                            if ((ts4_word)t3 == (ts4_word)((1260978176) | 14438)) {
                                *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)6;
                            }
                        } else {
                            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)2;
                        }
                    }
                }
            }
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)2;
    }
    return t1;
}

/* Swing_DLL.xex 0x88714348: if_call_seq fn_881AC778, u32@0x4, u32@0x4, u32@0x78, u32@0x78, u32@0x78 */
ts4_word ts4_if_call_seq_fn_881AC778_88714348(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;

    loc50[0] = (ts4_word)((1879638016) | 50781);
    t1 = fn_881AC778((ts4_word)(a1 + 60), (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t3 == (ts4_word)((1399586816) | 3852)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
        } else {
            if ((ts4_word)t3 == (ts4_word)((2847473664) | 35830)) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)37;
            } else {
                if ((ts4_word)t3 == (ts4_word)((1089536000) | 12692)) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)1;
                }
            }
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x887143E0: if_call_seq fn_881AC778, u32@0x4, u32@0x4, u32@0x74, u32@0x74, u32@0x74 */
ts4_word ts4_if_call_seq_fn_881AC778_887143E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t3;

    loc50[0] = (ts4_word)((2560032768) | 16003);
    t1 = fn_881AC778((ts4_word)(a1 + 60), (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t3 == (ts4_word)((1225064448) | 60795)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
        } else {
            if ((ts4_word)t3 == (ts4_word)((1870790656) | 51822)) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)2;
            } else {
                if ((ts4_word)t3 == (ts4_word)((2747662336) | 12826)) {
                    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)6;
                }
            }
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x88717650: if_get u32@0x34, u32@0x18, u32@0x18, fn_8870EA08, u32@0x1c, fn_886EFAC0 */
ts4_word ts4_if_get_u32_off34_88717650(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t4;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
        if ((ts4_word)t3 != 0) {
            t5 = fn_886EFAC0((ts4_word)t1);
            if ((ts4_word)t5 != 0) {
                t6 = fn_886EFD38((ts4_word)t1, (ts4_word)t5);
                if ((ts4_word)t6 != 0) {
                    t7 = fn_886EFA70((ts4_word)t1);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t7;
                    t8 = fn_886EFA20((ts4_word)t1);
                    *(ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)t8;
                    *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)t6;
                }
            }
        } else {
            t4 = fn_8870EA08((ts4_word)t1);
            *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)t4;
        }
        t12 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
        if ((ts4_word)t12 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)0, (ts4_word)-1);
        }
        return ((*(ts4_word *)((char *)(ts4_word)(t1) + 28)) != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x88718060: loop_get fn_88717408, u32@0x1c, u32@0x18, u32@0x1c, u32@0x18, u32@0x0 */
ts4_word ts4_loop_get_fn_88717408_88718060(ts4_word a0)
{
    ts4_word lv6;
    ts4_word p14;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    unsigned char t8;
    ts4_word t9;

    t1 = fn_88717408();
    if ((ts4_word)(t1 & 0xff) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        lv6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
        while ((ts4_word)lv6 != (ts4_word)t4) {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv6) + 0);
            t8 = *(unsigned char *)((char *)(ts4_word)(t7) + 172);
            if ((ts4_word)t8 != 0) {
                t9 = *(ts4_word *)lbl_88D45AB4;
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 104))))((ts4_word)t9, (ts4_word)t7);
            }
            p14 = (ts4_word)(lv6 + 4);
            lv6 = p14;
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8871C748: if_call_seq ts4_object_finalize, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x8 */
ts4_word ts4_if_call_seq_ts4_object_finalize_8871C748(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = ts4_object_finalize((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return t7;
        }
        t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
        return t5;
    }
    return t1;
}

/* Swing_DLL.xex 0x8871E450: addr lbl_880F2148, u32@0x0, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_addr_lbl_880F2148_8871E450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2148;
    return ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880F2148);
}

/* Swing_DLL.xex 0x8871E468: if_get u32@0x0, u32@0x10, vcall, fn_88713FD0, u8@0x1c, u32@0x28 */
ts4_word ts4_if_get_u32_off0_8871E468(ts4_word a0)
{
    unsigned char t5;
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
    fn_88713FD0((ts4_word)a0, (ts4_word)-1);
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t5 == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        ts4_call_seq_fn_887143E0_88719CD8((ts4_word)a0, (ts4_word)t6);
        *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 104));
        *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 100));
        *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)1;
        *(unsigned char *)((char *)(ts4_word)(a0) + 45) = (unsigned char)1;
    }
    return 1;
}

/* Swing_DLL.xex 0x8871FA98: call_seq fn_8822AE40, u32@0x4, u32@0x0, u8@-0x3, fn_88220060 */
ts4_word ts4_call_seq_fn_8822AE40_8871FA98(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[70];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    fn_8822AE40((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t4 = loc50[0];
    *(unsigned char *)((char *)(ts4_word)(((t2 - t3) + t4)) + -3) = (unsigned char)112;
    t5 = fn_88220060((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x88720018: call_seq fn_88617D88, lbl_880F30A4, u32@0x0, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_88720018(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F30A4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    ts4_object_finalize((ts4_word)(a0 + 32));
    ts4_object_finalize((ts4_word)(a0 + 44));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88720080: if_call_seq lbl_880F21E8, u32@0x0, u32@0x38, ts4_destroy_owned_object, lbl_880F3388, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F21E8_88720080(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t8;
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F21E8;
    t2 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 56)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3388;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t3 != 0) {
        t5 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t5 != 0) {
            t8 = fn_886131F0((ts4_word)t5, (ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)));
            return t8;
        }
        t6 = fn_885651F8((ts4_word)t3, (ts4_word)t3);
        return t6;
    }
    return t2;
}

/* Swing_DLL.xex 0x88721100: if_call_seq ts4_if_call_seq_u32_off8_8821FD70, u32@0xc, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8, u32@0x14 */
ts4_word ts4_if_call_seq_fn_8821FD70_88721100(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t5;

    t1 = ts4_if_call_seq_u32_off8_8821FD70((ts4_word)(a0 + 48));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t7 = fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
            return t7;
        }
        t5 = fn_885651F8((ts4_word)t2, (ts4_word)t2);
        return t5;
    }
    return t1;
}

/* Swing_DLL.xex 0x88721AE8: if_call_seq u32@0x0, lbl_880C1320, fn_881A5020, ts4_ascii_lower_to_upper_88564790, fn_88165E80, fn_88721A08 */
ts4_word ts4_if_call_seq_u32_off0_88721AE8(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word loc50[68];
    int t1;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != -1) {
        p2 = (ts4_word)(t1 + a1);
    } else {
        p2 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    fn_881A5020((ts4_word)(ts4_word)&loc50[0], (ts4_word)p2);
    t4 = loc50[0];
    fn_88165E80((ts4_word)t4, (ts4_word)(t4 + 1), (ts4_word)t4, (ts4_word)(ts4_word)ts4_ascii_lower_to_upper_88564790);
    t6 = loc50[0];
    t7 = fn_88721A08((ts4_word)a0, (ts4_word)t6);
    return t7;
}

/* Swing_DLL.xex 0x88721C40: if_call_seq lbl_880F2254, u32@0x0, u32@0x1c, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F2254_88721C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2254;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    t9 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88721D08: call_seq fn_88617D88, lbl_880F2810, u32@0x0, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88721D08(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2810;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 76));
    fn_8816D1A8((ts4_word)(a0 + 88));
    *(volatile ts4_word *)lbl_88D45A78 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88721EE0: addr lbl_880F2148, u32@0x0, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_addr_lbl_880F2148_88721EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2148;
    return ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880F2148);
}

/* Swing_DLL.xex 0x88721EF8: addr lbl_880F2148, u32@0x0, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_addr_lbl_880F2148_88721EF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2148;
    return ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880F2148);
}

/* Swing_DLL.xex 0x887230C0: if_get u32@0x328, u32@0x74, u32@0x40, fn_88722798 */
ts4_word ts4_if_get_u32_off328_887230C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 808);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 116);
    if ((int)t2 != 0) {
        return a0;
    }
    return fn_88722798((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 64)) + (a1 << 6)));
}

/* Swing_DLL.xex 0x8872A898: if_call_seq lbl_880F27E8, u32@0x0, fn_88223DA0, u32@0x1c, u32@lbl_88D45B38, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_lbl_880F27E8_8872A898(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t10;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F27E8;
    fn_88223DA0((ts4_word)(a0 + 44));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            fn_886131F0((ts4_word)t4, (ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
        } else {
            fn_885651F8((ts4_word)t2, (ts4_word)t2);
        }
    }
    t10 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x8872AE40: addr lbl_880F2138, u32@0x0, fn_88223B10 */
ts4_word ts4_addr_lbl_880F2138_8872AE40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2138;
    return fn_88223B10((ts4_word)(a0 + 4));
}

/* Swing_DLL.xex 0x88731630: if_call_seq u32@0x0, u32@0x8, u32@0x4, fn_8816D1A8, fn_88731540, lbl_880C1320 */
ts4_word ts4_if_call_seq_u32_off0_88731630(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(ts4_word)&loc50[0]);
    fn_88731540((ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    t3 = fn_881643D0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    if ((ts4_word)(t3 & 0xff) == 0) {
        t4 = fn_88722B80((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
        t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        t7 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t6;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t7;
    }
    t9 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t9);
    return a0;
}

/* Swing_DLL.xex 0x88731DA8: loop_get u32@0x20, u32@0x1c, u32@0x10, u32@0x0, u32@0x38, vcall */
ts4_word ts4_loop_get_u32_off20_88731DA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t12;
    ts4_word t17;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 16) = (ts4_word)0;
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0, (ts4_word)lv3);
            p7 = (ts4_word)(lv3 + 188);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t1);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t12 = fn_8823DD50((ts4_word)t10, (ts4_word)t10, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_loop_call_seq_u32_off20_88233618((ts4_word)t12, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t12;
    t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
    return t17;
}

/* Swing_DLL.xex 0x88732998: if_call_seq u32@0x0, u32@lbl_88C6CD84, u32@lbl_88C6CD88, fn_8871B7E0, u32@0x0, u32@lbl_88C6CD7C */
ts4_word ts4_if_call_seq_u32_off0_88732998(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)lbl_88C6CD84;
    if ((ts4_word)t2 == (ts4_word)t1 || (ts4_word)(*(ts4_word *)lbl_88C6CD88) == (ts4_word)t1) {
        fn_8871B7E0((ts4_word)a0);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    fn_886FC638((ts4_word)a0, (ts4_word)((t6 - (*(ts4_word *)lbl_88C6CD7C)) != 0));
    t9 = fn_8872D070((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 288) = (unsigned char)0;
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t10 == (ts4_word)((3479240704) | 34949)) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 288) = (unsigned char)1;
    }
    return t9;
}

/* Swing_DLL.xex 0x88736F30: call_seq lbl_880F2148, u32@0x0, u32@0x4, fn_8816D1A8, lbl_880C1320, u32@lbl_88D45B1C */
ts4_word ts4_call_seq_lbl_880F2148_88736F30(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2148;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 8), (ts4_word)(ts4_word)&loc50[0]);
    t6 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t6);
    return a0;
}

/* Swing_DLL.xex 0x887393F0: call_seq u32@0x0, u32@0x18, u32@0x1c, fn_88287FA0 */
ts4_word ts4_call_seq_u32_off0_887393F0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    t4 = fn_88287FA0((ts4_word)t1, (ts4_word)10, (ts4_word)0, (ts4_word)(t2 & 0xfffffffc), (ts4_word)0, (ts4_word)(t2 & 0xfffffffc), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 28)) & 0x3fffffc), (ts4_word)0, (ts4_word)(50331648));
    return t4;
}

/* Swing_DLL.xex 0x88739440: call_seq u32@0x0, u32@0x18, u32@0x1c, fn_88287FA0 */
ts4_word ts4_call_seq_u32_off0_88739440(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    t4 = fn_88287FA0((ts4_word)t1, (ts4_word)10, (ts4_word)0, (ts4_word)(t2 & 0xfffffffc), (ts4_word)0, (ts4_word)(t2 & 0xfffffffc), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 28)) & 0x3fffffc), (ts4_word)16, (ts4_word)(50331648));
    return t4;
}

/* Swing_DLL.xex 0x88745730: if_call_seq ts4_call_seq_fn_88163B90_88736BB8, u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88883CD0, u32@0x10, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_fn_88736BB8_88745730(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[80];
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;
    ts4_word t3;
    ts4_word t13;

    ts4_call_seq_fn_88163B90_88736BB8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    loc50[75] = (ts4_word)a1;
    loc50[74] = (ts4_word)0;
    if ((ts4_word)a1 == 0) {
        t4 = fn_88883CD0((ts4_word)0);
        if ((ts4_word)t4 != 0) {
            p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 16));
        } else {
            p6 = (ts4_word)0;
        }
        t7 = loc50[74];
        loc50[75] = (ts4_word)p6;
        if ((ts4_word)t7 == 0) {
            t9 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
            loc50[74] = (ts4_word)t9;
        }
    } else {
        t3 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
        loc50[74] = (ts4_word)t3;
    }
    t13 = fn_88721D98((ts4_word)(*(ts4_word *)lbl_88D45A74), (ts4_word)(ts4_word)&loc50[0]);
    return t13;
}

/* Swing_DLL.xex 0x8874A130: call_seq u32@0x0, ts4_assign_formatted_text, fn_88739D80 */
ts4_word ts4_call_seq_u32_off0_8874A130(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    ts4_word t3;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    t3 = fn_88739D80((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x8874B648: get u32@lbl_88D45AD4, fn_8828DF30 */
ts4_word ts4_get_u32_lbl_88D45AD4_8874B648(ts4_word a0)
{
    return fn_8828DF30((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + ((65536) | 22304))), (ts4_word)(a0 + 148));
}

/* Swing_DLL.xex 0x8874EC38: if_call_seq u32@0x0, fn_88748B18, fn_88748350 */
ts4_word ts4_if_call_seq_u32_off0_8874EC38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;

    (void)a0;
    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)t1 != 0) {
        fn_88748350();
        return 1;
    }
    fn_88748B18();
    return 1;
}

/* Swing_DLL.xex 0x8874FF08: get u32@0x24, u32@0x8, fn_8874FCD8, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off24_8874FF08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t5;
    ts4_word t8;

    fn_8874FCD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((((int)a1 * 68) + (*(ts4_word *)((char *)(ts4_word)(a0) + 36)))) + 8)), (ts4_word)a2, (ts4_word)a3);
    t5 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 4);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 88))))((ts4_word)t5, (ts4_word)a2);
    return t8;
}

/* Swing_DLL.xex 0x88750128: get u32@0x24, u32@0x8, fn_8874FF68 */
ts4_word ts4_get_u32_off24_88750128(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_8874FF68((ts4_word)(*(ts4_word *)((char *)(ts4_word)((((int)a1 * 68) + (*(ts4_word *)((char *)(ts4_word)(a0) + 36)))) + 8)), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Swing_DLL.xex 0x88752C60: if_tail fn_8874E3F8, fn_8874E518 */
ts4_word ts4_if_tail_fn_8874E3F8_88752C60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)(a3 & 0xff) != 0) {
        return fn_8874E518((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    }
    return fn_8874E3F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x887567D8: if_call_seq u32@0x10, fn_887561A8, u32@0x10, u32@0x80, fn_88756638 */
ts4_word ts4_if_call_seq_u32_off10_887567D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    int t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p7 = (ts4_word)t1;
    if ((int)t1 != 0) {
        fn_887561A8((ts4_word)t1, (ts4_word)0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 128);
        p6 = (ts4_word)t3;
        if ((ts4_word)t4 != 0) {
            t5 = fn_88756638((ts4_word)t3, (ts4_word)7);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x88756970: call_seq fn_887568C0, lbl_880F2118, u32@0x0, u32@lbl_88D45AD4 */
ts4_word ts4_call_seq_fn_887568C0_88756970(ts4_word a0)
{
    fn_887568C0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2118;
    *(unsigned char *)((char *)(ts4_word)(a0) + ((65536) | 22560)) = (unsigned char)0;
    *(ts4_word *)lbl_88D45AD4 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x88759B70: if_get u32@lbl_88D45AD4, u32@0x10, u32@0x24, u32@0x8, fn_88755E58 */
ts4_word ts4_if_get_u32_lbl_88D45AD4_88759B70(ts4_word a0, int a1)
{
    if ((int)a1 == -1) {
        return a0;
    }
    return fn_88755E58((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 16))) + 36)) + ((int)a1 * 68))) + 8)));
}

/* Swing_DLL.xex 0x8875B538: call_seq lbl_880F1F58, fn_881A5020, fn_88758018 */
ts4_word ts4_call_seq_lbl_880F1F58_8875B538(void)
{
    ts4_word loc50[70];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_881A5020((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F1F58);
    t2 = fn_88758018((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x8875EDC8: get u32@lbl_88D45AD4, fn_8875EB68 */
ts4_word ts4_get_u32_lbl_88D45AD4_8875EDC8(void)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)lbl_88D45AD4;
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + ((65536) | 22089)) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22060)) = (ts4_word)0;
    return fn_8875EB68((ts4_word)t1);
}

/* Swing_DLL.xex 0x8876CEE8: call_seq u32@lbl_88D45AD4, ts4_if_call_seq_fn_88734098_8876CE68, u32@lbl_88D45AD4 */
ts4_word ts4_call_seq_u32_lbl_88D45AD4_8876CEE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = ts4_if_call_seq_fn_88734098_8876CE68((ts4_word)(*(ts4_word *)lbl_88D45AD4));
    t3 = *(ts4_word *)lbl_88D45AD4;
    *(ts4_word *)((char *)(ts4_word)(t3) + ((65536) | 22056)) = (ts4_word)1;
    *(unsigned char *)((char *)(ts4_word)(t3) + ((65536) | 22090)) = (unsigned char)1;
    return t2;
}

/* Swing_DLL.xex 0x8876D370: if_get u32@0x10, u32@0x0, fn_8876D2C0, u32@0x0, u32@0x18, vcall */
ts4_word ts4_if_get_u32_off10_8876D370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = fn_8876D2C0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        p7 = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 24))))((ts4_word)t3);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)p7;
    }
    return p8;
}

/* Swing_DLL.xex 0x8876D3B8: if_get u32@0x10, u32@0x0, fn_8876D2C0, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_u32_off10_8876D3B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p8 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = fn_8876D2C0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        p7 = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 20))))((ts4_word)t3);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)p7;
    }
    return p8;
}

/* Swing_DLL.xex 0x8876D400: if_get u32@0x10, u32@0x0, fn_8876D2C0, u32@0x0, u32@0x10, u32@0x1c */
ts4_word ts4_if_get_u32_off10_8876D400(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p11 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = fn_8876D2C0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        p10 = (ts4_word)t3;
        if ((ts4_word)t3 != 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
            t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 28);
            t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 184);
            t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t6))((ts4_word)t3, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 180)), (ts4_word)t7);
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Swing_DLL.xex 0x8876DC70: if_get u32@0x0, u32@0x18, u32@0x18, u32@0x0, u32@0x1c, u32@0x1c */
ts4_word ts4_if_get_u32_off0_8876DC70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p3 = (ts4_word)0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        p3 = (ts4_word)1;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    p6 = (ts4_word)p3;
    if ((ts4_word)t5 != (ts4_word)t4) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t4;
        p6 = (ts4_word)1;
    }
    if ((ts4_word)(p6 & 0xff) == 0) {
        return a0;
    }
    return fn_8876D560((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)t5, (ts4_word)p6);
}

/* Swing_DLL.xex 0x8876E350: if_get u8@0x15, u8@0x14, u8@0x14, u32@0x0, u32@0x24 */
ts4_word ts4_if_get_u8_off15_8876E350(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    unsigned char t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 21);
    if ((ts4_word)t1 == 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 20);
        if ((ts4_word)t3 == 0) {
            return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        }
        return a0;
    }
    return a0;
}

/* Swing_DLL.xex 0x8876FC88: if_call_seq lbl_880EFCDC, u32@0x0, u32@0x8, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880EFCDC_8876FC88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8876FCD8: addr lbl_880EFCDC, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880EFCDC_8876FCD8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((3066429440) | 22117);
    return;
}

/* Swing_DLL.xex 0x8876FD38: addr lbl_880EFD04, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_addr_lbl_880EFD04_8876FD38(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFD04;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88771208: if_call_seq lbl_880EFCDC, u32@0x0, u32@0x8, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880EFCDC_88771208(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88771AB8: call_seq lbl_880EFE30, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_call_seq_lbl_880EFE30_88771AB8(ts4_word a0)
{
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFE30;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    t3 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x88771B00: if_call_seq lbl_880EFDE0, u32@0x0, u32@0x40, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880EFDE0_88771B00(ts4_word a0)
{
    ts4_word t7;
    ts4_word t10;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFDE0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 64)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = fn_8860BBD8((ts4_word)a0);
    return t10;
}

/* Swing_DLL.xex 0x88771B70: if_call_seq lbl_880EFDB4, u32@0x0, u32@0x24, ts4_destroy_owned_object, lbl_880EFCDC, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880EFDB4_88771B70(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFDB4;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = fn_8860BBD8((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88771BD0: if_call_seq lbl_880EFD64, u32@0x0, u32@0x54, ts4_destroy_owned_object, u32@0x3c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880EFD64_88771BD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t10;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFD64;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 60)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = fn_8860BBD8((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x88771C50: if_call_seq lbl_880EFD3C, u32@0x0, u32@0x54, ts4_destroy_owned_object, lbl_880EFCDC, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880EFD3C_88771C50(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFD3C;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 84)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = fn_8860BBD8((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88773198: if_call_seq lbl_880EFD8C, u32@0x0, u32@0x74, u32@0x70, ts4_loop_call_seq_u32_off0_88150378, u32@0x70 */
ts4_word ts4_if_call_seq_lbl_880EFD8C_88773198(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;
    ts4_word t12;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFD8C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 112)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFCDC;
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    t12 = fn_8860BBD8((ts4_word)a0);
    return t12;
}

/* Swing_DLL.xex 0x88773AB8: if_call_seq lbl_880EFE08, u32@0x0, u32@0x2c, u32@0x28, ts4_loop_call_seq_u32_off0_88150378, u32@0x28 */
ts4_word ts4_if_call_seq_lbl_880EFE08_88773AB8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EFE08;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    ts4_loop_call_seq_u32_offc_88219E68((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)t7);
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x88774408: if_call_seq u32@0x10, u32@0x0, fn_8876D210, u8@0x15, fn_88773A18 */
ts4_word ts4_if_call_seq_u32_off10_88774408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        t3 = fn_8876D210((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        if ((ts4_word)t3 != 0) {
            *(unsigned char *)((char *)(ts4_word)(t3) + 21) = (unsigned char)0;
        }
    }
    t5 = fn_88773A18((ts4_word)a0, (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x887789A0: if_get u32@0x18, u32@0x10, u32@0x0, u32@0x2c, u32@0x0, u32@0x2c */
ts4_word ts4_if_get_u32_off18_887789A0(ts4_word a0)
{
    int t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 44))))((ts4_word)t2);
}

/* Swing_DLL.xex 0x887789D0: if_get u32@0x18, u32@0x10, u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32_off18_887789D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 32))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
    }
    return a0;
}

/* Swing_DLL.xex 0x88778C48: loop_call_seq u32@0x3c34, u8@0x8, ts4_tailcall_fn_88584548_8857AFE8, u8@0x8 */
ts4_word ts4_loop_call_seq_u32_off3c34_88778C48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;
    unsigned char t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 15412);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 8);
    p6 = (ts4_word)a0;
    if ((ts4_word)t2 == 0) {
        do {
            t3 = ts4_tailcall_fn_88584548_8857AFE8((ts4_word)1);
            t4 = *(unsigned char *)((char *)(ts4_word)(t1) + 8);
        } while ((ts4_word)t4 == 0);
        p6 = (ts4_word)t3;
    }
    return p6;
}

/* Swing_DLL.xex 0x88779858: if_call_seq u32@0x3c34, ts4_memset, ts4_memset */
ts4_word ts4_if_call_seq_u32_off3c34_88779858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 15412);
    p3 = (ts4_word)(a0 + 12);
    if ((int)(a0 + 12) != 0) {
        t2 = ts4_memset((ts4_word)(a0 + 12), (ts4_word)0, (ts4_word)308);
        p3 = (ts4_word)t2;
    }
    p5 = (ts4_word)p3;
    if ((ts4_word)t1 != 0) {
        t4 = ts4_memset((ts4_word)t1, (ts4_word)0, (ts4_word)12);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x8877CF50: call_seq fn_88617D88, lbl_880EF7C4, u32@0x0, u32@0x1c */
ts4_word ts4_call_seq_fn_88617D88_8877CF50(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF7C4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8877DAD0: call_seq u32@0xac, u8@0xc6, u32@0xc0, u32@0xc8, u8@0xbc, u32@0xb0 */
ts4_word ts4_call_seq_u32_offac_8877DAD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)a1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 198) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 188) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)a4;
    fn_88778BE8((ts4_word)a0, (ts4_word)11);
    t2 = ts4_tailcall_fn_88584548_8857AFE8((ts4_word)160);
    return t2;
}

/* Swing_DLL.xex 0x8877DC48: if_get u32@0x618, lbl_880EF47C, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off618_8877DC48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1560);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF47C;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1560) = (ts4_word)0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 1544)));
    t8 = fn_8860BBD8((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x8877E8E8: get u32@lbl_88D4595C, u32@0x54, u32@0x50, u32@0x0 */
ts4_word ts4_get_u32_lbl_88D4595C_8877E8E8(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D4595C;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 84);
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 80))) + 0) = (ts4_word)t2;
    return 0;
}

/* Swing_DLL.xex 0x887816A0: call_seq fn_881D4050, lbl_880EF9F8, u32@0x0, u32@0x18, u8@0x1c, u32@0x18 */
ts4_word ts4_call_seq_fn_881D4050_887816A0(ts4_word a0)
{
    fn_881D4050((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF9F8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 540) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88784B58: if_get u32@0x10, fn_88218AD0, u32@0x20, u32@0x0, u32@0xc, vcall */
ts4_word ts4_if_get_u32_off10_88784B58(ts4_word a0)
{
    ts4_word p9;
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t6;
    int t7;
    ts4_word t12;

    loc50[0] = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16));
    t2 = fn_88218AD0((ts4_word)(ts4_word)&loc50[0]);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)((55902208) | 14141);
    ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 12))))((ts4_word)t2);
    loc50[0] = (ts4_word)((1495072768) | 51852);
    t6 = fn_887818A0((ts4_word)(ts4_word)&loc50[0]);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36);
    if ((int)t7 == 0) {
        p9 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t2) + 48));
    } else {
        p9 = (ts4_word)0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)p9;
    t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2, (ts4_word)1);
    return t12;
}

/* Swing_DLL.xex 0x88785940: call_seq fn_881A50F0, fn_88180070, fn_881A52D8, fn_88213D38 */
ts4_word ts4_call_seq_fn_881A50F0_88785940(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[136];
    ts4_word loc270[134];
    ts4_word t4;

    fn_881A50F0((ts4_word)(ts4_word)&loc50[0]);
    loc50[131] = (ts4_word)0;
    loc50[132] = (ts4_word)0;
    fn_88180070((ts4_word)(ts4_word)&loc270[0], (ts4_word)a1);
    fn_881A52D8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc270[0]);
    t4 = fn_88213D38((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x887859B0: call_seq fn_88180070, fn_881A52D8, u32@0x22c */
ts4_word ts4_call_seq_fn_88180070_887859B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[134];
    ts4_word t2;

    (void)a1;
    fn_88180070((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_881A52D8((ts4_word)(a0 + 32), (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)a2;
    return t2;
}

/* Swing_DLL.xex 0x88789DE8: call_seq u32@0x8, u32@0xc, u32@0x0, fn_888348A0, fn_881AB4F0, u32@lbl_88D45A60 */
ts4_word ts4_call_seq_u32_off8_88789DE8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t4 = fn_888348A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
    fn_881AB4F0((ts4_word)(ts4_word)&loc50[0], (ts4_word)t4);
    fn_881AAE70((ts4_word)((*(ts4_word *)lbl_88D45A60) + 148), (ts4_word)(ts4_word)&loc50[0]);
    t8 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t8);
    return 0;
}

/* Swing_DLL.xex 0x887905F0: if_call_seq u32@0x854, u32@0x858, lbl_880DFEDC, fn_8878C820, u32@0x85c, u32@0x860 */
ts4_word ts4_if_call_seq_u32_off854_887905F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p8;
    ts4_word p12;
    ts4_word p16;
    int t1;
    ts4_word t3;
    int t5;
    ts4_word t7;
    int t9;
    ts4_word t11;
    int t13;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2132);
    p4 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t3 = fn_8878C820((ts4_word)a0, (ts4_word)(ts4_word)lbl_880DFEDC, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2136)));
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 2140);
    p8 = (ts4_word)p4;
    if ((int)t5 != 0) {
        t7 = fn_8878C820((ts4_word)a0, (ts4_word)(ts4_word)lbl_880DFFF8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2144)));
        p8 = (ts4_word)t7;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 2148);
    p12 = (ts4_word)p8;
    if ((int)t9 != 0) {
        t11 = fn_8878C820((ts4_word)a0, (ts4_word)(ts4_word)lbl_880ECE4C, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2152)));
        p12 = (ts4_word)t11;
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 2156);
    p16 = (ts4_word)p12;
    if ((int)t13 != 0) {
        t15 = fn_8878C820((ts4_word)a0, (ts4_word)(ts4_word)lbl_880ECE64, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2160)));
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Swing_DLL.xex 0x88790698: if_call_seq u32@0x18, u32@0x20, u32@lbl_88D45B34, fn_888DDD70, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_88790698(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = fn_888DDD70((ts4_word)t1, (ts4_word)(*(volatile ts4_word *)lbl_88D45B34));
    if ((ts4_word)(t3 & 0xff) == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((2619080704) | 37749);
    }
    return t3;
}

/* Swing_DLL.xex 0x887915B0: call_seq lbl_880ED610, fn_8862BE08, ts4_gp0_xdata_get_bool_88163C60 */
ts4_word ts4_call_seq_lbl_880ED610_887915B0(void)
{
    ts4_word loc50[6];
    ts4_word t2;

    fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880ED610);
    t2 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc50[0]);
    return ((t2 & 0xff) == 0);
}

/* Swing_DLL.xex 0x88793BB8: loop_call_seq lbl_880EF980, u32@0x0, u32@0xc0, u32@0xbc, fn_88216460, u32@0xbc */
ts4_word ts4_loop_call_seq_lbl_880EF980_88793BB8(ts4_word a0)
{
    ts4_word lv16;
    ts4_word p18;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t14;
    ts4_word t15;
    ts4_word t21;
    ts4_word t24;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF980;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192);
    fn_88216460((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 188)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 160);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    ts4_if_call_seq_u32_offc_882124A8((ts4_word)(a0 + 60));
    t14 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    t15 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t15 != (ts4_word)t14) {
        lv16 = (ts4_word)t15;
        do {
            ts4_if_call_seq_u32_offc_882124A8((ts4_word)lv16);
            p18 = (ts4_word)(lv16 + 84);
            lv16 = p18;
        } while ((ts4_word)p18 != (ts4_word)t14);
    }
    t21 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t21 != 0) {
        ts4_destroy_owned_object((ts4_word)t21);
    }
    t24 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t24;
}

/* Swing_DLL.xex 0x88797608: if_get u32@0x48, fn_88796240 */
ts4_word ts4_if_get_u32_off48_88797608(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 == 0) {
        return a0;
    }
    return fn_88796240((ts4_word)a0);
}

/* Swing_DLL.xex 0x88798308: loop_call_seq lbl_880EF5D4, u32@0x0, u32@0x24, u32@0x20, ts4_if_call_seq_u32_offc_882124A8, u32@0x20 */
ts4_word ts4_loop_call_seq_lbl_880EF5D4_88798308(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p5;
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF5D4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            ts4_if_call_seq_u32_offc_882124A8((ts4_word)(lv3 + 4));
            p5 = (ts4_word)(lv3 + 92);
            lv3 = p5;
        } while ((ts4_word)p5 != (ts4_word)t1);
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t8 != 0) {
        ts4_destroy_owned_object((ts4_word)t8);
    }
    t11 = fn_88912A38((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x88798368: call_seq ts4_call_seq_lbl_880D72B0_88912AC0, lbl_880EF5D4, u32@0x0, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88912AC0_88798368(ts4_word a0)
{
    ts4_call_seq_lbl_880D72B0_88912AC0();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF5D4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)2;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8879A320: if_call_seq u32@0x18, u32@0x20, u32@lbl_88D45B34, fn_888F67B8, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_8879A320(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = fn_888F67B8((ts4_word)t1, (ts4_word)(*(volatile ts4_word *)lbl_88D45B34));
    if ((ts4_word)(t3 & 0xff) == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((2619080704) | 37749);
    }
    return t3;
}

/* Swing_DLL.xex 0x8879D918: if_get u32@0x48, u32@lbl_88C6CBF4, fn_887961A0, fn_88799490 */
ts4_word ts4_if_get_u32_off48_8879D918(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 == 0) {
        return fn_88799490((ts4_word)a0, (ts4_word)0);
    }
    return fn_887961A0((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6CBF4), (ts4_word)1);
}

/* Swing_DLL.xex 0x8879D940: if_get u32@0x48, u32@lbl_88C6CBEC, fn_887961A0, fn_88799490 */
ts4_word ts4_if_get_u32_off48_8879D940(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 == 0) {
        return fn_88799490((ts4_word)a0, (ts4_word)1);
    }
    return fn_887961A0((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6CBEC), (ts4_word)1);
}

/* Swing_DLL.xex 0x887A5E48: if_get fn_881AA7A0, u32@lbl_88D3E414, fn_8819A9D8, u32@0x0, u32@0x10, vcall */
ts4_word ts4_if_get_fn_881AA7A0_887A5E48(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word p18;
    ts4_word loc60[6];
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t12;
    ts4_word t13;

    t1 = fn_881AA7A0((ts4_word)(ts4_word)&loc60[0]);
    t2 = *(ts4_word *)lbl_88D3E414;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)t2;
    } else {
        t3 = fn_8819A9D8((ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p4) + 0))) + 16))))((ts4_word)p4);
    loc50[0] = (ts4_word)(t7 + 16);
    t8 = fn_887A33A8((ts4_word)(a1 + 8), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    if ((ts4_word)(t8 & 0xff) == 1) {
        fn_887A33A8((ts4_word)(a1 + 16), (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
        t12 = loc50[0];
        t13 = loc60[1];
        fn_88778208((ts4_word)t13, (ts4_word)t12);
        ts4_call_seq_u32_off0_881B1B08((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
        fn_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        fn_8819AD80((ts4_word)(ts4_word)&loc60[0]);
        p18 = (ts4_word)1;
    } else {
        fn_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        fn_8819AD80((ts4_word)(ts4_word)&loc60[0]);
        p18 = (ts4_word)0;
    }
    return p18;
}
