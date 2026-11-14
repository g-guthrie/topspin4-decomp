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

extern char lbl_880C1320[];
extern char lbl_880D19E0[];
extern char lbl_880D19F0[];
extern char lbl_880D4B20[];
extern char lbl_880D4BB0[];
extern char lbl_880D4C18[];
extern char lbl_880D4C88[];
extern char lbl_880D4E38[];
extern char lbl_880D5A64[];
extern char lbl_880D5AA0[];
extern char lbl_880D6DA0[];
extern char lbl_880D6DFC[];
extern char lbl_880D6E2C[];
extern char lbl_880D709C[];
extern char lbl_880D70B8[];
extern char lbl_880D70D4[];
extern char lbl_880D70F0[];
extern char lbl_880D710C[];
extern char lbl_880D7128[];
extern char lbl_880D7144[];
extern char lbl_880D7160[];
extern char lbl_880D717C[];
extern char lbl_880D7228[];
extern char lbl_880D754C[];
extern char lbl_880D75FC[];
extern char lbl_880D7604[];
extern char lbl_880DB228[];
extern char lbl_880DB2A4[];
extern char lbl_880DB2C8[];
extern char lbl_880DB350[];
extern char lbl_880DB370[];
extern char lbl_880DB580[];
extern char lbl_880DB670[];
extern char lbl_880DB794[];
extern char lbl_880DB7E4[];
extern char lbl_880DB8DC[];
extern char lbl_880DBCDC[];
extern char lbl_880DBD58[];
extern char lbl_880DC5DC[];
extern char lbl_880DC614[];
extern char lbl_880DC8A0[];
extern char lbl_880DCF20[];
extern char lbl_880DCFA0[];
extern char lbl_880DD020[];
extern char lbl_880DD088[];
extern char lbl_880DD434[];
extern char lbl_880DD7F4[];
extern char lbl_880DF824[];
extern char lbl_880DF874[];
extern char lbl_880DF8AC[];
extern char lbl_880DF900[];
extern char lbl_880E0728[];
extern char lbl_880E167C[];
extern char lbl_880E16A4[];
extern char lbl_880E1880[];
extern char lbl_880E1890[];
extern char lbl_880E302C[];
extern char lbl_880E3038[];
extern char lbl_880E3044[];
extern char lbl_880E36A8[];
extern char lbl_880E3D5C[];
extern char lbl_880E3DAC[];
extern char lbl_880E3DE0[];
extern char lbl_880E3E74[];
extern char lbl_880E3EB0[];
extern char lbl_880E3F54[];
extern char lbl_880E3F88[];
extern char lbl_880E3FBC[];
extern char lbl_880E3FF0[];
extern char lbl_880E406C[];
extern char lbl_880E40A0[];
extern char lbl_880E40E8[];
extern char lbl_880E4130[];
extern char lbl_880E4174[];
extern char lbl_880E41A8[];
extern char lbl_880E41EC[];
extern char lbl_880E4220[];
extern char lbl_880E4268[];
extern char lbl_880E42AC[];
extern char lbl_880E42E0[];
extern char lbl_880E4314[];
extern char lbl_880E434C[];
extern char lbl_880E4BBC[];
extern char lbl_880E73CC[];
extern char lbl_880E7504[];
extern char lbl_880E75A8[];
extern char lbl_880E7D04[];
extern char lbl_880E7D0C[];
extern char lbl_880E7D14[];
extern char lbl_880E7DA0[];
extern char lbl_880E8168[];
extern char lbl_880E8230[];
extern char lbl_880E84A8[];
extern char lbl_880E84E4[];
extern char lbl_880E8530[];
extern char lbl_880E8BB4[];
extern char lbl_8814B440[];
extern char lbl_88C6C2A0[];
extern char lbl_88C6C300[];
extern char lbl_88CACF08[];
extern char lbl_88D3E374[];
extern char lbl_88D3E390[];
extern char lbl_88D3E3A4[];
extern char lbl_88D3E3A8[];
extern char lbl_88D3E414[];
extern char lbl_88D45910[];
extern char lbl_88D45974[];
extern char lbl_88D45978[];
extern char lbl_88D459B4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word fn_88150310();
ts4_word fn_88150600();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88150878();
ts4_word fn_881519D0();
ts4_word fn_88158B28();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8815C920();
ts4_word fn_8815C980();
ts4_word fn_8815EF18();
ts4_word fn_881636A0();
ts4_word fn_88166BC0();
ts4_word fn_8816D1A8();
ts4_word fn_88177EC8();
ts4_word fn_8817C0D0();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_loop_call_seq_u32_offc_8817F860();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8818A0F8();
ts4_word fn_8818A530();
ts4_word ts4_call_seq_fn_881928F8_8818AB48();
ts4_word fn_8818ADD0();
ts4_word fn_88190570();
ts4_word ts4_call_seq_fn_8818F850_88190770();
ts4_word ts4_if_call_seq_u32_off8_881929F8();
ts4_word fn_88192DF0();
ts4_word fn_88193198();
ts4_word fn_88194028();
ts4_word fn_88195368();
ts4_word ts4_if_get_u32_lbl_88D3E3A4_88195BF8();
ts4_word fn_88196268();
ts4_word fn_88196E20();
ts4_word ts4_if_get_u32_off0_881972E8();
ts4_word fn_881976E0();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_8819A9D8();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word fn_8819ADD0();
ts4_word fn_8819B308();
ts4_word fn_881A2158();
ts4_word fn_881A62E8();
ts4_word ts4_loop_call_seq_u32_off4_881A7108();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B1B68();
ts4_word ts4_loop_call_seq_u32_off0_881B68A8();
ts4_word fn_881B8728();
ts4_word ts4_if_call_seq_u32_off10_881C3820();
ts4_word fn_881C5598();
ts4_word ts4_call_seq_u32_off4_881C5C30();
ts4_word fn_881C6D48();
ts4_word fn_881C70D8();
ts4_word ts4_call_seq_u32_offc_881CCDF0();
ts4_word fn_881CECD0();
ts4_word fn_881CF1C8();
ts4_word ts4_call_seq_lbl_880E7704_881CF7A0();
ts4_word fn_881DA660();
ts4_word fn_881DC558();
ts4_word fn_881DC818();
ts4_word ts4_call_seq_fn_881B19A0_881DC8C8();
ts4_word fn_881DC928();
ts4_word fn_881DFA08();
ts4_word ts4_call_seq_lbl_880E8AE8_881E0A88();
ts4_word ts4_if_call_seq_u8_off7d_881E1480();
ts4_word fn_881EFE08();
ts4_word fn_881F0388();
ts4_word fn_881F4108();
ts4_word ts4_call_seq_lbl_880E9660_881F41E8();
ts4_word fn_881F7958();
ts4_word fn_881FBA58();
ts4_word fn_88280708();
ts4_word fn_8841A590();
ts4_word ts4_tailcall_NetDll_closesocket_884F0258();
ts4_word ts4_tailcall_NetDll_connect_884F02B8();
ts4_word ts4_tailcall_NetDll_select_884F02F8();
ts4_word fn_88562DC0();
ts4_word fn_88562E80();
ts4_word fn_88562EF8();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_88563500();
ts4_word fn_885646F8();
ts4_word fn_885651F8();
ts4_word fn_88566FE8();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word fn_8857B4C8();
ts4_word fn_8857BD30();
ts4_word ts4_tailcall_fn_8857C078_8857C128();
ts4_word fn_8857C1F8();
ts4_word fn_8860BBD8();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();
ts4_word fn_8860DCF8();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word ts4_if_call_seq_lbl_880E3E3C_887FC130();
ts4_word fn_88823430();
ts4_word lua3_lua_settop_888246A8();
ts4_word fn_888367F8();
ts4_word fn_888368B0();
ts4_word fn_88837880();
ts4_word ts4_call_seq_u32_off18_88837CB0();
ts4_word fn_888380A8();
ts4_word fn_88883CD0();
ts4_word fn_888860A0();
ts4_word fn_88890718();
ts4_word fn_888AF5C0();
ts4_word fn_88912A38();
ts4_word ts4_loop_call_seq_lbl_880D6268_8892AF80();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_memset();
ts4_word ts4_resume_thread();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88150378: loop_call_seq u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off0_88150378(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p4;
    ts4_word p5;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t3 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
        p4 = (ts4_word)(lv1 + 12);
        lv1 = p4;
        p5 = (ts4_word)t3;
    }
    return p5;
}

/* Swing_DLL.xex 0x881505A8: if_call_seq u32@0x4, fn_88562DC0, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_881505A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != (ts4_word)a2) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((int)((t1 - a2) + 1) != 0) {
            fn_88562DC0((ts4_word)a1, (ts4_word)a2, (ts4_word)((t1 - a2) + 1));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) - a2) + a1);
    }
    return a1;
}

/* Swing_DLL.xex 0x88151DF8: if_call_seq lbl_880D5A64, lbl_880D19F0, u32@0x42c, u32@0x4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D5A64_88151DF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1068) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88151FC0: if_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x10, u8@0x14, ts4_memset */
ts4_word ts4_if_call_seq_u32_off0_88151FC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a4;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    ts4_memset((ts4_word)(a0 + 8), (ts4_word)0, (ts4_word)8);
    if (((ts4_word)a4 <= 8 && (ts4_word)a3 != 0) && (ts4_word)a4 != 0) {
        memcpy((ts4_word)(a0 + 8), (ts4_word)a3, (ts4_word)a4);
    }
    return a0;
}

/* Swing_DLL.xex 0x88155A40: if_call_seq lbl_880D19E0, fn_88562EF8, fn_88562E80, ts4_if_call_seq_u32_lbl_88D45B38_88150878, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880D19E0_88155A40(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t3;
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 <= (ts4_word)-1 && (ts4_word)a1 != 0) {
        t3 = ts4_if_call_seq_u32_lbl_88D45B38_88150878((ts4_word)(a0 + 8));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t3 + a1);
        p4 = (ts4_word)t3;
    } else {
        t1 = fn_88562EF8((ts4_word)(ts4_word)lbl_880D19E0);
        t2 = fn_88562E80((ts4_word)t1);
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Swing_DLL.xex 0x88157088: if_call_seq lbl_880D5A64, lbl_880D5AA0, u32@0x4c8, u32@0x0, u32@0x4, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D5A64_88157088(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1224) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5AA0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x881578E0: tailcall ts4_tailcall_NetDll_closesocket_884F0258 */
ts4_word ts4_tailcall_fn_884F0258_881578E0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ts4_tailcall_NetDll_closesocket_884F0258((ts4_word)a1);
}

/* Swing_DLL.xex 0x881579E0: if_get u32@0x0, u32@0xc, vcall, u32@0x0, u32@0x1c, vcall */
ts4_word ts4_if_get_u32_off0_881579E0(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[68];
    ts4_word loc50[4];
    ts4_word t6;
    ts4_word t9;
    int t11;
    int t14;
    ts4_word t15;
    int t16;

    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 28))))((ts4_word)a1);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    t11 = ts4_tailcall_NetDll_connect_884F02B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t9, (ts4_word)t6);
    if ((int)t11 != 0) {
        t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
        if ((int)t14 != 3) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
            return 0;
        }
        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        loc60[0] = (ts4_word)1;
        loc50[0] = (ts4_word)1;
        loc50[1] = (ts4_word)0;
        loc60[1] = (ts4_word)t15;
        t16 = ts4_tailcall_NetDll_select_884F02F8((ts4_word)t15, (ts4_word)0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
        if ((int)t16 == 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x88158408: if_call_seq u32@0x14, u32@0x10, u32@0x0, fn_888860A0, u32@0x0, u32@lbl_88D45B38 */
ts4_word ts4_if_call_seq_u32_off14_88158408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t12;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)((int)a1 * (int)a2) != (ts4_word)((int)t2 * (int)t1)) {
        fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        if ((ts4_word)((int)a1 * (int)a2) != 0) {
            t6 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)((((int)a1 * (int)a2) + (((int)a1 * (int)a2) << 1)) << 2), (ts4_word)128, (ts4_word)0, (ts4_word)2);
            memset((ts4_word)t6, (ts4_word)0, (ts4_word)((((int)a1 * (int)a2) + (((int)a1 * (int)a2) << 1)) << 2));
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t6;
        }
    }
    t12 = fn_88158B28((ts4_word)(a0 + 4), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    return t12;
}

/* Swing_DLL.xex 0x8815C9E8: if_call_seq lbl_880D19E0, fn_88562EF8, fn_88562E80, fn_8815C980, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880D19E0_8815C9E8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    if ((ts4_word)a1 > (ts4_word)-1 || (ts4_word)a1 == 0) {
        t1 = fn_88562EF8((ts4_word)(ts4_word)lbl_880D19E0);
        t2 = fn_88562E80((ts4_word)t1);
        p4 = (ts4_word)t2;
    } else {
        t3 = fn_8815C980((ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t3 + a1);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8815E550: call_seq lbl_880C1320, ts4_assign_formatted_text, ts4_assign_formatted_text, ts4_assign_formatted_text, ts4_assign_formatted_text, ts4_assign_formatted_text */
ts4_word ts4_call_seq_lbl_880C1320_8815E550(ts4_word a0)
{
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 36), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 48), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 60), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 72), (ts4_word)(ts4_word)lbl_880C1320);
    *(unsigned char *)((char *)(ts4_word)(a0) + 84) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 85) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 86) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 87) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 90) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 91) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 94) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 104) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 105) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 106) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 107) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8815E628: call_seq lbl_880C1320, ts4_assign_formatted_text, ts4_assign_formatted_text, ts4_assign_formatted_text, u32@0x28, u32@0x24 */
ts4_word ts4_call_seq_lbl_880C1320_8815E628(ts4_word a0)
{
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(ts4_word)lbl_880C1320);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)16;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8815E810: call_seq u32@0x0, lbl_880C1320, ts4_assign_formatted_text, fn_88150600, ts4_destroy_owned_object, u32@lbl_88D45B1C */
ts4_word ts4_call_seq_u32_off0_8815E810(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t3;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    fn_88150600((ts4_word)(a0 + 4), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    t4 = ts4_destroy_owned_object((ts4_word)t3);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return t4;
}

/* Swing_DLL.xex 0x8815ED78: call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, ts4_assign_formatted_text, u32@0x18, ts4_assign_formatted_text */
ts4_word ts4_call_seq_u32_off0_8815ED78(ts4_word a0, ts4_word a1)
{
    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12)));
    ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    return a0;
}

/* Swing_DLL.xex 0x8815F098: if_call_seq lbl_880D4BB0, u32@0x0, u32@0x40, ts4_destroy_owned_object, lbl_880D4B20, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D4BB0_8815F098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4BB0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4B20;
    t5 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)));
    return t5;
}

/* Swing_DLL.xex 0x8815F140: if_call_seq lbl_880D4C18, u32@0x0, u32@0x80, ts4_destroy_owned_object, u32@0x74, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D4C18_8815F140(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t20;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4C18;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    t16 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4B20;
    t20 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)));
    return t20;
}

/* Swing_DLL.xex 0x8815F238: call_seq fn_8815EF18, u32@0x44, u32@0x48, lbl_880D4C88, u32@0x4c, u32@0x50 */
ts4_word ts4_call_seq_fn_8815EF18_8815F238(ts4_word a0)
{
    fn_8815EF18();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4C88;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return a0;
}

/* Swing_DLL.xex 0x8815F408: if_call_seq lbl_880D4E38, u32@0x0, u32@0x40, ts4_destroy_owned_object, lbl_880D4B20, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D4E38_8815F408(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4E38;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D4B20;
    t5 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)));
    return t5;
}

/* Swing_DLL.xex 0x8815FFF0: loop_call_seq u32@0x4, u32@0x0, u32@0x0, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off4_8815FFF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t10;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                ts4_destroy_owned_object((ts4_word)t4);
            }
            p7 = (ts4_word)(lv3 + 12);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t1);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_destroy_owned_object((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x881611E8: if_get u32@0x8, u32@0x4, fn_88280708, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off8_881611E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
            *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
            *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 12);
        return a0;
    }
    return fn_88280708((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)1, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x88161CF8: if_call_seq u32@0x4, u32@0x0, u32@0x4, ts4_loop_call_seq_u32_offc_8817F860, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off4_88161CF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = ts4_loop_call_seq_u32_offc_8817F860((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x88161D58: if_call_seq u32@0x4, u32@0x0, u32@0x4, fn_881636A0, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off4_88161D58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_881636A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x88162520: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 84), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88162A80: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88162A80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 76), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88165F68: loop_call_seq u32@0x18, ts4_destroy_owned_object, u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off18_88165F68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p8;
    ts4_word p9;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 24)));
        ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
        t7 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
        p8 = (ts4_word)(lv1 + 48);
        lv1 = p8;
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88166048: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_88166048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p6;
    ts4_word p7;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p7 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
        t5 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
        p6 = (ts4_word)(lv1 + 32);
        lv1 = p6;
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Swing_DLL.xex 0x881661F8: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object, u32@-0xc, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_881661F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p14;
    ts4_word p15;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p15 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 60);
        do {
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -12)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -36)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -48)));
            t13 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -60)));
            p14 = (ts4_word)(lv1 + 96);
            lv1 = p14;
        } while ((ts4_word)(p14 + -60) != (ts4_word)a1);
        p15 = (ts4_word)t13;
    }
    return p15;
}

/* Swing_DLL.xex 0x88166278: loop_call_seq u32@0xc, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object, u32@-0x18, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_offc_88166278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p12;
    ts4_word p13;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p13 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 48);
        do {
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 12)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -24)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -36)));
            t11 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -48)));
            p12 = (ts4_word)(lv1 + 84);
            lv1 = p12;
        } while ((ts4_word)(p12 + -48) != (ts4_word)a1);
        p13 = (ts4_word)t11;
    }
    return p13;
}

/* Swing_DLL.xex 0x881662F0: if_call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, u32@0xc, u32@0x10, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_881662F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t2 = ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
        p9 = (ts4_word)t2;
    }
    return p9;
}

/* Swing_DLL.xex 0x88166360: if_call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, ts4_assign_formatted_text, u32@0x18, ts4_assign_formatted_text */
ts4_word ts4_if_call_seq_u32_off0_88166360(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p23;
    ts4_word t22;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p23 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12)));
        ts4_assign_formatted_text((ts4_word)(a0 + 24), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)));
        fn_88166BC0((ts4_word)(a0 + 36), (ts4_word)(a1 + 36));
        *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 48));
        ts4_assign_formatted_text((ts4_word)(a0 + 52), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52)));
        ts4_assign_formatted_text((ts4_word)(a0 + 64), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64)));
        ts4_assign_formatted_text((ts4_word)(a0 + 76), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76)));
        ts4_assign_formatted_text((ts4_word)(a0 + 88), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 88)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 100));
        *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 104));
        ts4_assign_formatted_text((ts4_word)(a0 + 108), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 108)));
        t22 = ts4_assign_formatted_text((ts4_word)(a0 + 120), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120)));
        p23 = (ts4_word)t22;
    }
    return p23;
}

/* Swing_DLL.xex 0x881664E8: if_call_seq u32@0x0, ts4_assign_formatted_text, u32@0xc, ts4_assign_formatted_text, u32@0x18, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off0_881664E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p8 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        t4 = ts4_assign_formatted_text((ts4_word)(a0 + 12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
        p8 = (ts4_word)t4;
    }
    return p8;
}

/* Swing_DLL.xex 0x8816D4B0: if_call_seq lbl_880D19F0, lbl_880D5A64, u32@0x42c, u32@0x4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D19F0_8816D4B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1068) = (ts4_word)(ts4_word)lbl_880D19F0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8816DE38: if_call_seq u32@0x0, fn_88613570, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8816DE38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_88613570((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)12, (ts4_word)4, (ts4_word)a1);
    if ((int)(t2 + 8) != 0) {
        *(ts4_word *)((char *)(ts4_word)((t2 + 8)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t2;
    return a0;
}

/* Swing_DLL.xex 0x8816DFB8: if_call_seq u32@lbl_88D45B38, fn_88618998, u32@lbl_88D45B38, u32@0x0, u32@0x0, ts4_if_call_seq_fn_88883CD0_8860D250 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8816DFB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    p4 = (ts4_word)t1;
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_88618998((ts4_word)t1, (ts4_word)((3733127168) | 5755));
        t3 = *(ts4_word *)lbl_88D45B38;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
        p4 = (ts4_word)t3;
        p5 = (ts4_word)t2;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p9 = (ts4_word)p5;
    if ((ts4_word)t6 == 0) {
        if ((ts4_word)p4 != 0) {
            t7 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)p4);
            p8 = (ts4_word)t7;
        } else {
            p8 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p8;
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x8816E648: if_call_seq fn_8860DCF8, u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_fn_8860DCF8_8816E648(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8860DCF8((ts4_word)a0, (ts4_word)16, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t2;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t3;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)t4;
        *(volatile unsigned short *)((char *)(ts4_word)(t1) + 12) = (unsigned short)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 14) = (unsigned char)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 1044) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 1044)) + 1);
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88173270: loop_call_seq lbl_880D6DA0, u32@0x0, u32@0x3c, u32@0x38, u32@0x4, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_lbl_880D6DA0_88173270(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv3;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t9;
    ts4_word t12;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6DA0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv3) + 4)));
            p6 = (ts4_word)(lv3 + 16);
            lv3 = p6;
        } while ((ts4_word)p6 != (ts4_word)t1);
    }
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t9 != 0) {
        ts4_destroy_owned_object((ts4_word)t9);
    }
    t12 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t12 != 0) {
        ts4_destroy_owned_object((ts4_word)t12);
    }
    t15 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t15;
}

/* Swing_DLL.xex 0x881738D8: if_call_seq lbl_880D6DFC, u32@0x0, u32@0x30, ts4_destroy_owned_object, u32@0x24, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880D6DFC_881738D8(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6DFC;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88173B28: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880D6DFC, u32@0x4, u32@0x0, fn_8816D1A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88173B28(void)
{
    ts4_word p6;
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)300, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6DFC;
        fn_8816D1A8((ts4_word)(t2 + 8));
        fn_8816D1A8((ts4_word)(t2 + 36));
        fn_8816D1A8((ts4_word)(t2 + 48));
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 68) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880D6E2C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 268) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 276) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 272) = (ts4_word)((983040) | 65535);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 288) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 296) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t2) + 260) = (unsigned char)1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 280) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 292) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 284) = (ts4_word)0;
        p6 = (ts4_word)t2;
    } else {
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Swing_DLL.xex 0x88174688: if_call_seq lbl_880D709C, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D709C_88174688(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D709C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88174818: if_call_seq lbl_880D70B8, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D70B8_88174818(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D70B8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881757E0: if_call_seq lbl_880D70D4, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D70D4_881757E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D70D4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88175AD8: if_call_seq lbl_880D70F0, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D70F0_88175AD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D70F0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88175D10: if_call_seq lbl_880D710C, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D710C_88175D10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D710C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88175F60: if_call_seq lbl_880D7128, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D7128_88175F60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7128;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88176238: if_call_seq lbl_880D7144, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D7144_88176238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7144;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88176580: if_call_seq lbl_880D7160, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D7160_88176580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7160;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88176840: if_call_seq lbl_880D717C, u32@0x0, u32@0x8, ts4_destroy_owned_object, lbl_880D7228, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880D717C_88176840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D717C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7228;
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881779F8: if_call_seq lbl_880D754C, u32@0x0, u32@0x34, ts4_destroy_owned_object, fn_88912A38, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D754C_881779F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D754C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    fn_88912A38((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88177E30: if_call_seq fn_8816D1A8, u32@0x0, u32@0x4, u32@0x4, fn_88177EC8, fn_88150310 */
ts4_word ts4_if_call_seq_fn_8816D1A8_88177E30(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    t1 = fn_8816D1A8((ts4_word)(ts4_word)&loc50[0]);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)a1 < (ts4_word)((int)(t3 - t2) / (int)12)) {
        fn_88150310((ts4_word)a0, (ts4_word)(((a1 + (a1 << 1)) << 2) + t2), (ts4_word)t3, (ts4_word)t1);
    } else {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
        fn_88177EC8((ts4_word)a0, (ts4_word)t4, (ts4_word)(a1 - ((int)(t4 - t2) / (int)12)), (ts4_word)t1);
    }
    t8 = loc50[0];
    t9 = ts4_destroy_owned_object((ts4_word)t8);
    return t9;
}

/* Swing_DLL.xex 0x88178148: if_call_seq lbl_880D75FC, u32@0x0, u32@0x4, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D75FC_88178148(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D75FC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88178200: if_call_seq lbl_880D7604, u32@0x0, u32@0x14, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880D7604_88178200(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7604;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88178BE0: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88178BE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 52), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8817B6F0: if_call_seq lbl_880DBD58, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DBD58_8817B6F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBD58;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817BA50: if_call_seq u32@lbl_88D45910, u8@0xdc, lbl_88D45CC0, u8@0x8, fn_8817C0D0, u8@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45910_8817BA50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45910;
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 220)) != 0) {
        *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 8) = (unsigned char)1;
        t3 = fn_8817C0D0();
        *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 8) = (unsigned char)0;
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8817CBB8: if_call_seq lbl_880DB370, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DB370_8817CBB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB370;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817CC28: if_call_seq lbl_880DB350, u32@0x0, u32@0x268, ts4_destroy_owned_object, ts4_loop_call_seq_lbl_880D6268_8892AF80, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880DB350_8817CC28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB350;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 616);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_loop_call_seq_lbl_880D6268_8892AF80((ts4_word)(a0 + 8));
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817CF30: if_call_seq lbl_880DBCDC, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DBCDC_8817CF30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBCDC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817D178: if_call_seq lbl_880DB580, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DB580_8817D178(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB580;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817D3E0: if_call_seq lbl_880DB670, u32@0x0, u32@0x88, ts4_destroy_owned_object, u32@0x78, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DB670_8817D3E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t17;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB670;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    ts4_if_call_seq_u32_off4_8817E430((ts4_word)(a0 + 60));
    t17 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t17;
}

/* Swing_DLL.xex 0x8817D528: if_call_seq lbl_880DB794, u32@0x0, u32@0x58, ts4_destroy_owned_object, u32@0x4c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DB794_8817D528(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB794;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 88)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 76)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 64)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817DA00: if_call_seq lbl_880DB2C8, u32@0x0, u32@0xc, ts4_destroy_owned_object, lbl_880DB2A4, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880DB2C8_8817DA00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2C8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB2A4;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817DA78: if_call_seq lbl_880DB7E4, u32@0x0, u32@0xe8, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DB7E4_8817DA78(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB7E4;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 232)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8817DBA0: if_call_seq lbl_880DB8DC, u32@0x0, u32@0x68, ts4_destroy_owned_object, u32@0x5c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DB8DC_8817DBA0(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB8DC;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 104)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 92)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881815A8: loop_call_seq u32@0x40, ts4_destroy_owned_object, u32@0x0, ts4_destroy_owned_object, u32@-0xc, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off40_881815A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p10;
    ts4_word p11;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p11 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 140);
        do {
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 64)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -12)));
            t9 = ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + -24)));
            p10 = (ts4_word)(lv1 + 244);
            lv1 = p10;
        } while ((ts4_word)(p10 + -140) != (ts4_word)a1);
        p11 = (ts4_word)t9;
    }
    return p11;
}

/* Swing_DLL.xex 0x88181670: loop_call_seq u32@-0x4, u32@0xc, u32@0x0, u32@0x4, u8@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_0x4_88181670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p8;
    ts4_word p9;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    if ((ts4_word)a0 != (ts4_word)a1) {
        lv1 = (ts4_word)(a0 + 4);
        do {
            *(volatile ts4_word *)((char *)(ts4_word)(lv1) + -4) = (ts4_word)0;
            *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 12) = (ts4_word)0;
            t2 = *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0);
            t3 = *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 4);
            if ((ts4_word)t2 != (ts4_word)t3) {
                *(volatile unsigned char *)((char *)(ts4_word)(t2) + 0) = (unsigned char)0;
                *(volatile ts4_word *)((char *)(ts4_word)(lv1) + 4) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0));
            }
            t7 = ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv1) + 0)));
            p8 = (ts4_word)(lv1 + 20);
            lv1 = p8;
        } while ((ts4_word)(p8 + -4) != (ts4_word)a1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x881844A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB228, u32@0x0, u32@0x22c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881844A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)580, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB228;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 556) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 560) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184528: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB228, u32@0x0, u32@0x22c */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184528(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)580, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB228;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 556) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 560) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881878A0: loop_get u32@0x8, u32@-0x8, u32@0x4, vcall, u32@0x4 */
ts4_word ts4_loop_get_u32_off8_881878A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p8 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)(a0 + 4)) {
        lv2 = (ts4_word)t1;
        do {
            t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv2) + -8))) + 4))))((ts4_word)(lv2 + -8));
            p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 4));
            lv2 = p7;
        } while ((ts4_word)p7 != (ts4_word)(a0 + 4));
        p8 = (ts4_word)t5;
    }
    return p8;
}

/* Swing_DLL.xex 0x88187A00: call_seq u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_call_seq_u32_off4_88187A00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 27) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    ts4_memset((ts4_word)(a0 + 32), (ts4_word)0, (ts4_word)64);
    *(unsigned char *)((char *)(ts4_word)(a0) + 96) = (unsigned char)0;
    ts4_memset((ts4_word)(a0 + 97), (ts4_word)0, (ts4_word)64);
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 168) = (ts4_u64)0;
    return a0;
}

/* Swing_DLL.xex 0x88188690: if_call_seq lbl_880DC614, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DC614_88188690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC614;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88188800: if_call_seq lbl_880DC5DC, u32@0x0, u32@0x48, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DC5DC_88188800(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC5DC;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 72)));
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88189240: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888AF5C0, lbl_880DC8A0, u32@0x84, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88189240(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)148, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888AF5C0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t3) + 132) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880DC8A0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 140) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 136) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 144) = (ts4_word)0;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881892B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888AF5C0, lbl_880DC8A0, u32@0x84, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881892B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)148, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888AF5C0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t3) + 132) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880DC8A0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 140) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 136) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t3) + 144) = (ts4_word)0;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88189D30: if_call_seq fn_88890718, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88890718_88189D30(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88890718((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)26);
    }
    return a0;
}

/* Swing_DLL.xex 0x8818A360: if_get RtlEnterCriticalSection, u32@0x28, fn_8818A530, u32@0x28, u32@0x24, u32@0x0 */
ts4_word ts4_if_get_RtlEnterCriticalSection_8818A360(ts4_word a0)
{
    ts4_word p9;
    ts4_word t7;
    ts4_word t8;

    RtlEnterCriticalSection((ts4_word)(a0 + 8));
    fn_8818A530((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCF20;
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t7);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x8818A5E0: call_seq fn_88198CE0, fn_88199068, u32@0x0, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_fn_88198CE0_8818A5E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88198CE0((ts4_word)a2);
    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t2 = fn_88199068((ts4_word)0, (ts4_word)(a1 + 8), (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(a1 + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    fn_88198CE0((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x8818AAD0: if_call_seq fn_88199068, ts4_call_seq_fn_881928F8_8818AB48 */
ts4_word ts4_if_call_seq_fn_88199068_8818AAD0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)72, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = ts4_call_seq_fn_881928F8_8818AB48((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8818AB98: if_call_seq u32@0x8, lbl_880DCFA0, u32@0x0, fn_8818ADD0, u32@0x38, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off8_8818AB98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DCFA0;
    if ((int)t1 != 0) {
        fn_8818ADD0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(ts4_word)lbl_880DCFA0, (ts4_word)t1);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
    ts4_if_call_seq_u32_off8_881929F8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8818ACB8: if_get u32@0x34, fn_88192DF0, u32@0x0, u32@0x1c, vcall, u32@0x34 */
ts4_word ts4_if_get_u32_off34_8818ACB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t10;
    ts4_word t2;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 != 0) {
        if ((int)a3 != -1) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a3, (ts4_word)2);
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 4))))((ts4_word)t7, (ts4_word)a1, (ts4_word)a2);
        return t10;
    }
    t2 = fn_88192DF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t2;
}

/* Swing_DLL.xex 0x8818AD38: if_get u32@0x34, fn_88193198, u32@0x0, u32@0x2c */
ts4_word ts4_if_get_u32_off34_8818AD38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    return fn_88193198((ts4_word)a0);
}

/* Swing_DLL.xex 0x8818AE90: if_call_seq u32@0x8, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, ts4_if_get_u32_lbl_88D3E3A4_88195BF8 */
ts4_word ts4_if_call_seq_u32_off8_8818AE90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;

    (void)a6;
    (void)a7;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    t1 = *(volatile ts4_word *)lbl_88D3E3A8;
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
        p5 = (ts4_word)(*(volatile ts4_word *)lbl_88D3E3A8);
    }
    ts4_if_get_u32_lbl_88D3E3A4_88195BF8((ts4_word)a0, (ts4_word)p5, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return a0;
}

/* Swing_DLL.xex 0x8818B220: if_addr lbl_880DD020, u32@0x4, u32@0x0, u32@0x8, u8@0xc, u32@0x10 */
ts4_word ts4_if_addr_lbl_880DD020_8818B220(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD020;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1024;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)1;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8818B4A0: if_get u32@0x14, u32@0x18, u32@0x14, u32@0x18, u32@0x10, u32@0x10 */
ts4_word ts4_if_get_u32_off14_8818B4A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p11;
    ts4_word p13;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t14;
    ts4_word t17;
    ts4_word t18;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((ts4_word)a2 == 0) {
        return 0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p13 = (ts4_word)a2;
    if ((ts4_word)(t3 + a2) > (ts4_word)t4) {
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        if ((ts4_word)t6 > 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 100))))((ts4_word)a0, (ts4_word)(t3 + a2));
            p11 = (ts4_word)a2;
        } else {
            p11 = (ts4_word)(t4 - t3);
        }
        p13 = (ts4_word)p11;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    memcpy((ts4_word)(t14 + (*(ts4_word *)((char *)(ts4_word)(a0) + 20))), (ts4_word)a1, (ts4_word)p13);
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(t17 + p13);
    if ((ts4_word)(t17 + p13) > (ts4_word)t18) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t17 + p13);
    }
    return p13;
}

/* Swing_DLL.xex 0x8818B708: if_call_seq u32@0x10, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10, lbl_880DD088, u32@0x0, fn_881992A8 */
ts4_word ts4_if_call_seq_u32_off10_8818B708(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8818F7F8: get fn_881519D0, u32@0x0, u32@0x10, vcall, u32@0x4, u32@0x8 */
ts4_word ts4_get_fn_881519D0_8818F7F8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_881519D0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t4 + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x881906E8: if_call_seq ts4_call_seq_fn_8818F850_88190770, u32@0x0, u32@0x0, u32@0x0, u32@0x18, u32@0x30 */
ts4_word ts4_if_call_seq_fn_88190770_881906E8(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_call_seq_fn_8818F850_88190770((ts4_word)a1);
    if ((ts4_word)a1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    }
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t3 + -1);
    p8 = (ts4_word)t1;
    if ((ts4_word)(t3 + -1) < (ts4_word)t4 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t6 = fn_881F0388((ts4_word)a0, (ts4_word)(t3 + -1));
        t7 = fn_88190570((ts4_word)a0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x881908D0: get u32@lbl_88D3E374, fn_88199068 */
ts4_word ts4_get_u32_lbl_88D3E374_881908D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_88199068((ts4_word)(*(ts4_word *)lbl_88D3E374), (ts4_word)((int)a1 * (int)a2), (ts4_word)0);
}

/* Swing_DLL.xex 0x881919E8: if_get u32@lbl_88D3E390, vcall, u32@0x70, fn_881992A8, u32@0x70, u32@0x6c */
ts4_word ts4_if_get_u32_lbl_88D3E390_881919E8(ts4_word a0)
{
    ts4_word p5;
    ts4_word p8;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t2 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)lbl_88D3E390)))((ts4_word)(a0 + 52));
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    p5 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t4 = fn_881992A8((ts4_word)0, (ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108);
    p8 = (ts4_word)p5;
    if ((ts4_word)t6 != 0) {
        t7 = fn_881992A8((ts4_word)0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    return p8;
}

/* Swing_DLL.xex 0x88192B78: if_call_seq u32@lbl_88D45974, u32@0x2c, u32@0x10, u32@0x2c, u32@lbl_88D3E3A8, u32@lbl_88D3E3A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45974_88192B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45974;
    if ((int)t1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        if ((int)t4 != 0) {
            t6 = *(ts4_word *)lbl_88D3E3A8;
            if ((ts4_word)t6 == 0) {
                fn_88195368();
            }
            return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20));
        }
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88193A28: if_call_seq u32@0x8, u8@0x30, u32@lbl_88D3E3A8, fn_88195368, u32@lbl_88D3E3A8, ts4_if_get_u32_lbl_88D3E3A4_88195BF8 */
ts4_word ts4_if_call_seq_u32_off8_88193A28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;

    (void)a6;
    (void)a7;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a1) + 48) = (unsigned char)1;
    t1 = *(volatile ts4_word *)lbl_88D3E3A8;
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
        p5 = (ts4_word)(*(volatile ts4_word *)lbl_88D3E3A8);
    }
    ts4_if_get_u32_lbl_88D3E3A4_88195BF8((ts4_word)a0, (ts4_word)p5, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return a0;
}

/* Swing_DLL.xex 0x88193BE0: call_seq lbl_880DD434, u32@0x4, u32@0x0, u32@0x1c, u32@0x20, fn_881976E0 */
ts4_word ts4_call_seq_lbl_880DD434_88193BE0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD434;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    fn_881976E0((ts4_word)(a0 + 36), (ts4_word)1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88196660: if_call_seq u32@lbl_88D3E3A4, fn_88198CE0, u32@lbl_88D45978, u32@0x0, fn_88196E20, fn_88196268 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A4_88196660(ts4_word a0)
{
    ts4_word p13;
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t5;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)lbl_88D45978;
    if ((int)t3 == 0) {
        loc54[0] = (ts4_word)t3;
        fn_88196268((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)0);
        fn_88194028((ts4_word)(ts4_word)&loc50[0]);
        t8 = loc50[0];
        t9 = loc58[0];
        if ((ts4_word)t8 != 0) {
            ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
        }
        p13 = (ts4_word)t9;
    } else {
        t5 = fn_88196E20((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        p13 = (ts4_word)t5;
    }
    fn_88198CE0((ts4_word)t2);
    return p13;
}

/* Swing_DLL.xex 0x88196B30: if_call_seq u32@lbl_88D3E3A4, fn_88198CE0, u32@0x10, ts4_if_get_u32_lbl_88C32048_8857A1E0, u32@0x1c, u32@0x10 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A4_88196B30(ts4_word a0)
{
    ts4_word t2;
    int t3;
    ts4_word t7;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D3E3A4));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t3 != -1) {
        ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)t3);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    fn_8819B308((ts4_word)(a0 + 20));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t7 = fn_88198CE0((ts4_word)t2);
    return t7;
}

/* Swing_DLL.xex 0x88197360: if_get u32@0x0, u32@0x4, u32@0x4, u32@lbl_88D45978, u32@0x4, u32@0x5c */
ts4_word ts4_if_get_u32_off0_88197360(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p19;
    ts4_word t1;
    int t3;
    ts4_word t8;
    ts4_word t12;
    ts4_word t18;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p19 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((int)t3 != 0 && (int)(*(ts4_word *)lbl_88D45978) == 0) {
            fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 4))) + 92)));
            t8 = *(ts4_word *)((char *)(ts4_word)((t1 + 4)) + 0);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 32))) + 4))))((ts4_word)(t8 + 32), (ts4_word)1, (ts4_word)0);
            t12 = *(ts4_word *)((char *)(ts4_word)((t1 + 4)) + 0);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 8))))((ts4_word)t12, (ts4_word)1);
        }
        ts4_if_get_u32_off0_881972E8((ts4_word)(t1 + 4));
        t18 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p19 = (ts4_word)t18;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p19;
}

/* Swing_DLL.xex 0x88197550: if_get u32@0x8, u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x8 */
ts4_word ts4_if_get_u32_off8_88197550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 8))))((ts4_word)t2);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t5 == 0);
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) == 0);
}

/* Swing_DLL.xex 0x88197DA8: if_call_seq u32@0x90, u32@0x7c, memset, u32@0x80, u32@0x84, u32@0x88 */
ts4_word ts4_if_call_seq_u32_off90_88197DA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0xff) != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
        t3 = memset((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)), (ts4_word)222, (ts4_word)t1);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)t5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)t6;
    return p4;
}

/* Swing_DLL.xex 0x881995E0: tailcall fn_888860A0 */
ts4_word ts4_tailcall_fn_888860A0_881995E0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_888860A0((ts4_word)a1);
}

/* Swing_DLL.xex 0x88199988: if_set u32@0x0, u32@lbl_88D459B4, fn_88883CD0, u32@0x0, fn_8818A0F8, u32@0x0 */
ts4_word ts4_if_set_u32_off0_88199988(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;
    ts4_word t12;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a2;
    if ((ts4_word)a2 == 0) {
        t2 = fn_88883CD0((ts4_word)(*(ts4_word *)lbl_88D459B4));
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        p5 = (ts4_word)t3;
        if ((int)t3 == -1 || (ts4_word)t3 == 0) {
            t4 = fn_8818A0F8((ts4_word)t2);
            p5 = (ts4_word)t4;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)p5;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 84))))((ts4_word)t8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t11;
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 88))))((ts4_word)t12, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x8819ABC8: if_get u32@lbl_88D3E414, fn_8819A9D8, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D3E414_8819ABC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)lbl_88D3E414;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = fn_8819A9D8((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    t6 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(p3) + 0))) + 16))))((ts4_word)p3);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t6 + 16);
    fn_8819ADD0((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x8819B8D0: if_call_seq u32@0x0, u32@-0xc, fn_88563500, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8819B8D0(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + -12);
    if ((int)a2 >= (int)t2) {
        return -1;
    }
    t3 = fn_88563500((ts4_word)(t1 + a2), (ts4_word)((signed char)a1), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    if ((ts4_word)t3 == 0) {
        return -1;
    }
    return (t3 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8819B940: if_call_seq u32@0x0, u32@-0xc, fn_885646F8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8819B940(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + -12);
    if ((int)t2 < 0) {
        return -1;
    }
    t3 = fn_885646F8((ts4_word)t1, (ts4_word)a1);
    if ((ts4_word)t3 == 0) {
        return -1;
    }
    return (t3 - (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8819F528: if_get u32@0x8, u32@0x0, u32@0x4, vcall, u32@0x1c, u32@0x1c */
ts4_word ts4_if_get_u32_off8_8819F528(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p11;
    ts4_word t1;
    ts4_word t2;
    int t4;
    int t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    p11 = (ts4_word)a0;
    if ((ts4_word)t2 != 0) {
        t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)));
        if ((int)t4 >= 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
        } else {
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
            if ((int)t6 == 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((t4 << 8) + -9);
            }
        }
        p11 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 1);
    return p11;
}

/* Swing_DLL.xex 0x881A1E10: if_call_seq lbl_880DD7F4, u32@0x0, fn_881A2158, u32@0x4, fn_881992A8, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880DD7F4_881A1E10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD7F4;
    t1 = fn_881A2158((ts4_word)a0, (ts4_word)1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_880DD7F4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p4 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t3 = fn_881992A8((ts4_word)0, (ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return p4;
}

/* Swing_DLL.xex 0x881A2068: if_call_seq u32@0x4, u32@0x60, u32@0x60, fn_8857B4C8, u32@0x4, u32@0x60 */
ts4_word ts4_if_call_seq_u32_off4_881A2068(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 96);
    if ((ts4_word)t2 == 0) {
        p9 = (ts4_word)0;
    } else {
        t4 = fn_8857B4C8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 96)));
        if ((ts4_word)t4 > 2) {
            ts4_resume_thread((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + 96)));
        }
        p9 = (ts4_word)t4;
    }
    return p9;
}

/* Swing_DLL.xex 0x881A20D8: loop_call_seq u32@0x4, u32@0x60, u32@0x60, ts4_resume_thread, u32@0x4, u32@0x60 */
ts4_word ts4_loop_call_seq_u32_off4_881A20D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    int t4;
    int t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 96);
    if ((ts4_word)t2 == 0) {
        p9 = (ts4_word)0;
    } else {
        t4 = ts4_resume_thread((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 96)));
        p8 = (ts4_word)t4;
        if ((ts4_word)(a1 & 0xff) != 0 && (int)t4 > 0) {
            do {
                t7 = ts4_resume_thread((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + 96)));
            } while ((int)t7 > 0);
            p8 = (ts4_word)t7;
        }
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x881A2338: loop_get u32@0x4, u32@0x58, fn_8857C1F8, u32@0x4, u32@0x5c, u32@0x58 */
ts4_word ts4_loop_get_u32_off4_881A2338(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t4;
    ts4_word t7;
    ts4_word t13;

    fn_8857C1F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 88)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 92));
    loc50[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 88));
    t7 = ts4_tailcall_fn_8857C078_8857C128((ts4_word)2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)-1);
    if ((ts4_word)t7 == 1) {
        do {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80) = (ts4_word)2;
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80) = (ts4_word)1;
            t13 = ts4_tailcall_fn_8857C078_8857C128((ts4_word)2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)-1);
        } while ((ts4_word)t13 == 1);
    }
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x881A26D8: if_get u32@0x4, u32@0x8, u32@-0xc, u8@0x18, u32@0xc, u32@0x14 */
void ts4_if_get_u32_off4_881A26D8(ts4_word a0)
{
    ts4_word t1;
    int t2;
    int t3;
    ts4_word t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + -12);
    if ((int)t2 < (int)t3) {
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + 1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((signed char)(*(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + t2)));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(t4 + 1);
        return;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x881A5630: call_seq u32@0x14, fn_8857BD30 */
ts4_word ts4_call_seq_u32_off14_881A5630(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    loc50[0] = (ts4_word)0;
    fn_8857BD30((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t3 = loc50[0];
    return t3;
}

/* Swing_DLL.xex 0x881A5A30: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5A30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 268), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881A6398: if_call_seq lbl_880DF900, u32@0x0, u32@0x18, u32@0x14, ts4_loop_call_seq_u32_off4_881A7108, u32@0x14 */
ts4_word ts4_if_call_seq_lbl_880DF900_881A6398(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t4;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF900;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    ts4_loop_call_seq_u32_off4_881A7108((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A6410: if_call_seq lbl_880DF8AC, u32@0x0, u32@0x2c, ts4_destroy_owned_object, u32@0x20, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DF8AC_881A6410(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

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
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A65A0: if_call_seq lbl_880DF874, u32@0x0, u32@0x144, ts4_destroy_owned_object, fn_881A62E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DF874_881A65A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

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
    fn_881A62E8((ts4_word)(a0 + 132));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A6660: if_call_seq lbl_880DF824, u32@0x0, u32@0x28, ts4_destroy_owned_object, u32@0x1c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880DF824_881A6660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

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
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881AA980: if_call_seq lbl_880E0728, u32@0x0, u32@0x24, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E0728_881AA980(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E0728;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881AC6A0: if_call_seq lbl_880D19E0, fn_88562EF8, fn_88562E80, ts4_if_call_seq_u32_lbl_88D45B38_8815C920, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880D19E0_881AC6A0(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    if ((ts4_word)a1 > (ts4_word)((2147418112) | 65535) || (ts4_word)a1 == 0) {
        t1 = fn_88562EF8((ts4_word)(ts4_word)lbl_880D19E0);
        t2 = fn_88562E80((ts4_word)t1);
        p4 = (ts4_word)t2;
    } else {
        t3 = ts4_if_call_seq_u32_lbl_88D45B38_8815C920((ts4_word)(a0 + 8));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((a1 << 1) + t3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x881AD4A8: if_call_seq lbl_880E167C, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E167C_881AD4A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E167C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881AD518: if_call_seq lbl_880E16A4, u32@0x0, u32@0x1c, ts4_destroy_owned_object, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E16A4_881AD518(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16A4;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881AE078: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AE078(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 44), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881B1D48: if_call_seq u32@0xc, lbl_880E1890, u32@0x0, fn_885651F8, u32@0x4, lbl_880E1880 */
ts4_word ts4_if_call_seq_u32_offc_881B1D48(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1890;
    fn_885651F8((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1880;
    p6 = (ts4_word)t3;
    if ((ts4_word)t3 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 8)) != 0) {
        t5 = fn_88566FE8((ts4_word)t3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x881B1EF0: if_call_seq u32@0x4, lbl_880E1880, u32@0x0, u8@0x8, fn_88566FE8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_u32_off4_881B1EF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E1880;
    if ((ts4_word)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 8)) != 0) {
        fn_88566FE8((ts4_word)t1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B2108: if_call_seq lbl_880E36A8, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E36A8_881B2108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E36A8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B2178: call_seq fn_888380A8, fn_881B19A0, u32@0x18, fn_881B18E0, fn_881B19A0 */
ts4_word ts4_call_seq_fn_888380A8_881B2178(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[10];
    ts4_word t1;
    ts4_word t5;

    t1 = fn_888380A8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(a0 + 72));
    fn_881B19A0((ts4_word)a1);
    fn_881B18E0((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24)), (ts4_word)(t1 + 8));
    t5 = fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x881B24B8: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B24B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 524), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881B2518: if_call_seq fn_888380A8, fn_881B19A0, u32@0x18, fn_881B18E0, fn_881B19A0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_888380A8_881B2518(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc80[10];
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    int t11;
    ts4_word t12;
    ts4_word t15;

    t1 = fn_888380A8((ts4_word)(ts4_word)&loc80[0], (ts4_word)(a0 + 8));
    fn_881B19A0((ts4_word)a2);
    fn_881B18E0((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24)), (ts4_word)(t1 + 8));
    fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)2;
    loc50[2] = (ts4_word)t6;
    fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3044, (ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    loc50[0] = (ts4_word)2;
    loc50[2] = (ts4_word)t8;
    fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E302C, (ts4_word)(ts4_word)&loc50[0]);
    fn_88837880((ts4_word)(ts4_word)&loc60[0], (ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3038);
    t11 = loc60[2];
    if ((int)t11 != 0) {
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        loc50[0] = (ts4_word)2;
        loc50[2] = (ts4_word)t12;
        fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3038, (ts4_word)(ts4_word)&loc50[0]);
    }
    t15 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t15;
}

/* Swing_DLL.xex 0x881B25F0: if_call_seq fn_888380A8, fn_881B19A0, u32@0x18, fn_881B18E0, fn_881B19A0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_888380A8_881B25F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc80[10];
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t1;
    ts4_word t6;
    ts4_word t8;
    int t11;
    ts4_word t12;
    ts4_word t15;

    t1 = fn_888380A8((ts4_word)(ts4_word)&loc80[0], (ts4_word)(a0 + 40));
    fn_881B19A0((ts4_word)a2);
    fn_881B18E0((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24)), (ts4_word)(t1 + 8));
    fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc50[0] = (ts4_word)2;
    loc50[2] = (ts4_word)t6;
    fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3044, (ts4_word)(ts4_word)&loc50[0]);
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    loc50[0] = (ts4_word)2;
    loc50[2] = (ts4_word)t8;
    fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E302C, (ts4_word)(ts4_word)&loc50[0]);
    fn_88837880((ts4_word)(ts4_word)&loc60[0], (ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3038);
    t11 = loc60[2];
    if ((int)t11 != 0) {
        t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        loc50[0] = (ts4_word)2;
        loc50[2] = (ts4_word)t12;
        fn_888367F8((ts4_word)a2, (ts4_word)(ts4_word)lbl_880E3038, (ts4_word)(ts4_word)&loc50[0]);
    }
    t15 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t15;
}

/* Swing_DLL.xex 0x881B42E0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E3DAC_881B42E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B4460: if_call_seq lbl_880E3E74, u32@0x0, u32@0x68, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880E3E3C_887FC130, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E3E74_881B4460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E74;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880E3E3C_887FC130((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B44D0: if_call_seq lbl_880E3D5C, u32@0x0, u32@0x34, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E3D5C_881B44D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3D5C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B5CF8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3DE0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B5CF8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3DE0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        *(volatile unsigned char *)((char *)(ts4_word)(t2) + 48) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B5D88: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E42E0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B5D88(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E42E0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B5E18: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3EB0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B5E18(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3EB0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B5F58: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3F54, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B5F58(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F54;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 48) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 52) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 56) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 68) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 72) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 76) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6008: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3F88, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6008(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)56, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F88;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B60F0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3FBC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B60F0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3FBC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6180: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3FF0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6180(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3FF0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6210: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E406C, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6210(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E406C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B62A0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E40A0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B62A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E40A0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6330: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E40E8, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6330(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E40E8;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B63C0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4130, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B63C0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4130;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6450: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4174, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6450(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4174;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B64E0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E41EC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B64E0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E41EC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6570: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4220, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6570(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4220;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6600: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4268, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6600(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4268;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6690: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E42AC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6690(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E42AC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6720: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4314, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6720(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4314;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B67B0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E434C, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B67B0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E434C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6840: loop_call_seq u32@0x4, u32@0x0, ts4_loop_call_seq_u32_off0_881B68A8, u32@0x0, ts4_destroy_owned_object */
ts4_word ts4_loop_call_seq_u32_off4_881B6840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p9 = (ts4_word)a0;
    lv1 = (ts4_word)a0;
    while ((ts4_word)lv1 != (ts4_word)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(lv1) + 4);
        ts4_loop_call_seq_u32_off0_881B68A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 0)), (ts4_word)t2);
        t5 = *(ts4_word *)((char *)(ts4_word)(lv1) + 0);
        p7 = (ts4_word)t5;
        if ((ts4_word)t5 != 0) {
            t6 = ts4_destroy_owned_object((ts4_word)t5);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)(lv1 + 12);
        lv1 = p8;
        p9 = (ts4_word)p7;
    }
    return p9;
}

/* Swing_DLL.xex 0x881B7108: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3DE0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7108(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3DE0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        *(volatile unsigned char *)((char *)(ts4_word)(t2) + 48) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B71A0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3EB0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B71A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3EB0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B72F0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3F54, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B72F0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F54;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 48) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 52) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 56) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 60) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 68) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 72) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 76) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B73A8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3F88, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B73A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)56, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F88;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B74A0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3FBC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B74A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3FBC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7538: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E3FF0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7538(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3FF0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B75D0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E406C, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B75D0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E406C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7668: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E40A0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7668(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E40A0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7700: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E40E8, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7700(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E40E8;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7798: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4130, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7798(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4130;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7830: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4174, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7830(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4174;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B78C0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E41A8, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B78C0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E41A8;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7950: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E41A8, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7950(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E41A8;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B79E8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E41EC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B79E8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E41EC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7A80: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4220, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7A80(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4220;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7B18: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4268, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7B18(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4268;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7BB0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E42AC, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7BB0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E42AC;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7C48: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E42E0, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7C48(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E42E0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7CE0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4314, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7CE0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E4314;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7D78: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E434C, u32@0x14 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7D78(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(volatile ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E434C;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)-1;
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)-1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B86D0: if_get u32@0x8, u32@0x4, fn_881B8728, u16@0x0, u16@0x0, u16@0x2 */
ts4_word ts4_if_get_u32_off8_881B86D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(volatile unsigned short *)((char *)(ts4_word)(t2) + 0) = (unsigned short)(*(volatile unsigned short *)((char *)(ts4_word)(a1) + 0));
            *(volatile unsigned short *)((char *)(ts4_word)(t2) + 2) = (unsigned short)(*(volatile unsigned short *)((char *)(ts4_word)(a1) + 2));
            *(volatile unsigned short *)((char *)(ts4_word)(t2) + 4) = (unsigned short)(*(volatile unsigned short *)((char *)(ts4_word)(a1) + 4));
            *(volatile unsigned short *)((char *)(ts4_word)(t2) + 6) = (unsigned short)(*(volatile unsigned short *)((char *)(ts4_word)(a1) + 6));
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)) + 8);
        return a0;
    }
    return fn_881B8728((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t1);
}

/* Swing_DLL.xex 0x881B8FE8: if_call_seq lbl_880E4BBC, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E4BBC_881B8FE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BBC;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881B93D8: if_call_seq u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B93D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((int)a1 * 516), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x881BDAB0: if_call_seq lbl_880E7504, u32@0x0, u32@0x10, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10, lbl_880DD088 */
ts4_word ts4_if_call_seq_lbl_880E7504_881BDAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7504;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return p3;
}

/* Swing_DLL.xex 0x881C3D40: if_call_seq fn_88199068, fn_881F4108, u32@0x28, lbl_880E75A8, u32@0x2c, u8@0x25 */
ts4_word ts4_if_call_seq_fn_88199068_881C3D40(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)48, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t1) + 37) = (unsigned char)1;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E75A8;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x881C3DC8: if_call_seq fn_881F4108, lbl_880E75A8, u32@0x28, u8@0x25, u32@0x0, u32@0x2c */
ts4_word ts4_if_call_seq_fn_881F4108_881C3DC8(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)1;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E75A8;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881C5528: if_call_seq fn_881C5598, fn_881FBA58, u32@0x4 */
ts4_word ts4_if_call_seq_fn_881C5598_881C5528(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = fn_881C5598((ts4_word)a0);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    t2 = fn_881FBA58((ts4_word)t1, (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 == 0) {
        return 0;
    }
    return (*(volatile ts4_word *)((char *)(ts4_word)(t2) + 4));
}

/* Swing_DLL.xex 0x881C5B50: if_call_seq ts4_call_seq_u32_off4_881C5C30, u32@0x0, u32@0x0, u32@0x0, u32@0x18, u32@0x30 */
ts4_word ts4_if_call_seq_fn_881C5C30_881C5B50(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_call_seq_u32_off4_881C5C30((ts4_word)a1);
    if ((ts4_word)a1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(t3 + -1);
    p8 = (ts4_word)t1;
    if ((ts4_word)(t3 + -1) < (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)) == 0) {
        t6 = fn_881F0388((ts4_word)a0, (ts4_word)(t3 + -1));
        t7 = fn_881EFE08((ts4_word)a0, (ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x881C6DC8: call_seq u32@0x0, fn_881DA660, u32@0x14, u32@0x4, u32@0xc, u16@0xe */
ts4_word ts4_call_seq_u32_off0_881C6DC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    t1 = fn_881DA660();
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(unsigned short *)((char *)(ts4_word)(t2) + 14) = (unsigned short)((*(ts4_word *)((char *)(ts4_word)(t2) + 12)) + 1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) & 0xff000000);
    return a0;
}

/* Swing_DLL.xex 0x881C7028: call_seq fn_881C6D48, u32@0x0, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_fn_881C6D48_881C7028(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_881C6D48();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((t2 & 0xff000001) | (((t2 & 0xfffffffe) + 2) & 0xfffffe));
    return a0;
}

/* Swing_DLL.xex 0x881C7078: call_seq u32@0x0, u32@0x8, u32@0x8, fn_881C70D8, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_881C7078(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((t2 & 0xff000001) | (((t2 & 0xfffffffe) + 2) & 0xfffffe));
    fn_881C70D8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)((t2 & 0xff000001) | (((t2 & 0xfffffffe) + 2) & 0xfffffe)), (ts4_word)t2, (ts4_word)(t2 & 0xfffffffe));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return a0;
}

/* Swing_DLL.xex 0x881C81F8: if_get u32@0x0, u8@0x8, u32@0xc, u32@0x8, u32@0x8, u32@0x10 */
ts4_word ts4_if_get_u32_off0_881C81F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 8);
    if ((ts4_word)(t2 & 0x10) != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)a2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)(t2 & 0x10), (ts4_word)a2, (ts4_word)t2);
    }
    if ((ts4_word)(t2 & 0x20) != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p4 = (ts4_word)(t1 + 12);
    }
    *(float *)((char *)(ts4_word)(p4) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) | 1);
    return a0;
}

/* Swing_DLL.xex 0x881C82E8: if_get u32@0x0, u8@0x8, u32@0xc, u32@0x8, u32@0x8, u32@0x10 */
ts4_word ts4_if_get_u32_off0_881C82E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 8);
    if ((ts4_word)(t2 & 0x10) != 0) {
        return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 16))))((ts4_word)a0, (ts4_word)a2, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)(t2 & 0x10), (ts4_word)a2, (ts4_word)t2);
    }
    if ((ts4_word)(t2 & 0x20) != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p4 = (ts4_word)(t1 + 12);
    }
    *(double *)((char *)(ts4_word)(p4) + 0) = (*(double *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) | 1);
    return a0;
}

/* Swing_DLL.xex 0x881CE908: call_seq fn_881CF1C8 */
ts4_word ts4_call_seq_fn_881CF1C8_881CE908(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    fn_881CF1C8((ts4_word)a0, (ts4_word)a2);
    return a0;
}

/* Swing_DLL.xex 0x881CEB10: call_seq fn_881F4108, lbl_880E7DA0, u32@0x0, u32@0x24, u32@0x28, u32@0x2c */
ts4_word ts4_call_seq_fn_881F4108_881CEB10(ts4_word a0)
{
    float t2;

    fn_881F4108((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7DA0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    t2 = *(float *)lbl_8814B440;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile float *)((char *)(ts4_word)(a0) + 60) = t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x881CEBD0: if_call_seq u32@0x30, lbl_880E7DA0, u32@0x0, lbl_880E73CC, fn_888368B0, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off30_881CEBD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[3];
    int t1;
    ts4_word t11;
    ts4_word t14;
    ts4_word t18;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7DA0;
    if ((int)t1 != 0) {
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)t1, (ts4_word)(ts4_word)lbl_880E73CC, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)(ts4_word)lbl_880E7D04, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)(ts4_word)lbl_880E7D0C, (ts4_word)(ts4_word)&loc50[0]);
        loc50[0] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_888368B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)(ts4_word)lbl_880E7D14, (ts4_word)(ts4_word)&loc50[0]);
        fn_881B19A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)));
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        if ((ts4_word)t11 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)(*(ts4_word *)lbl_88C6C300);
            *(ts4_word *)lbl_88C6C300 = (ts4_word)t11;
        }
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t14 != 0) {
        ts4_if_call_seq_u32_off10_881C3820((ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(t14) + 0) = (ts4_word)(*(ts4_word *)lbl_88C6C2A0);
        *(ts4_word *)lbl_88C6C2A0 = (ts4_word)t14;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t18 = ts4_call_seq_lbl_880E9660_881F41E8((ts4_word)a0);
    return t18;
}

/* Swing_DLL.xex 0x881CF660: if_call_seq u32@0x30, lbl_880C1320, ts4_assign_text_from_c_string, u32@0x0, fn_88837880, fn_881B19A0 */
ts4_word ts4_if_call_seq_u32_off30_881CF660(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[5];
    int t1;
    int t5;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
    if ((int)t1 != 0) {
        fn_88837880((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
        t5 = loc50[2];
        if ((int)t5 == 4) {
            t8 = loc50[4];
            ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(t8 + 24));
            fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
        } else {
            fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
            ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320);
        }
    } else {
        ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320);
    }
    return a0;
}

/* Swing_DLL.xex 0x881CF6E8: call_seq u32@0x30, u32@0x18, fn_881B18E0, u32@0x30, u32@0x18, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off30_881CF6E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc80[10];
    ts4_word loc60[8];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t18;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    loc80[2] = (ts4_word)0;
    loc80[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc80[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24)), (ts4_word)(t1 + 8));
    loc60[2] = (ts4_word)0;
    loc60[4] = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    fn_881B18E0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 24)), (ts4_word)(t4 + 8));
    t7 = loc60[6];
    fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc80[0]);
    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    fn_881B1B68((ts4_word)(ts4_word)&loc50[0], (ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    fn_88823430((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 0)), (ts4_word)-3);
    lua3_lua_settop_888246A8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 0)), (ts4_word)-2);
    t18 = fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
    return t18;
}

/* Swing_DLL.xex 0x881D08E8: if_call_seq u32@0x30, u32@0x0, u32@0x4, u32@0x18, u32@0x8, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off30_881D08E8(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 48);
    if ((int)t1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        fn_881B18E0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 24)), (ts4_word)(t1 + 8));
        return a0;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x881D3FD0: get u32@0x0 */
ts4_word ts4_get_u32_off0_881D3FD0(ts4_word a0, ts4_word a1)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 0))))((ts4_word)a1);
}

/* Swing_DLL.xex 0x881D4888: if_call_seq u32@0x34, lbl_880E8168, u32@0x0, fn_881992A8, u32@0x34, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off34_881D4888(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8168;
    if ((ts4_word)t1 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t7 = ts4_call_seq_u32_offc_881CCDF0((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x881D5218: if_call_seq fn_88199068, fn_881F4108, lbl_880E8230, u32@0x0, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88199068_881D5218(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)60, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8230;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x881D5290: if_call_seq fn_881F4108, lbl_880E8230, u32@0x0, u32@0x24 */
ts4_word ts4_if_call_seq_fn_881F4108_881D5290(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8230;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB960: get u8@0x7c */
ts4_word ts4_get_u8_off7c_881DB960(ts4_word a0)
{
    return (((*(unsigned char *)((char *)(ts4_word)(a0) + 124)) >> 4) & 0x1);
}

/* Swing_DLL.xex 0x881DBA10: addr fn_881F7958, lbl_880E8BB4, u32@0x0, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_addr_fn_881F7958_881DBA10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_881F7958((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8BB4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(t5 + 16);
    *(volatile float *)((char *)(ts4_word)(a0) + 32) = (*(float *)lbl_8814B440);
    return a0;
}

/* Swing_DLL.xex 0x881DBBB8: if_call_seq u32@0x18, u32@0x14, u8@0x7d, lbl_880E84E4, ts4_assign_text_from_c_string, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_881DBBB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[1];
    unsigned char t2;
    ts4_word t5;
    ts4_word t10;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    t2 = *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20))) + 125);
    if ((ts4_word)(t2 & 0x20) == 0) {
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E84E4);
        t5 = ts4_call_seq_lbl_880E7704_881CF7A0((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)(ts4_word)&loc50[0]);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)t5 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t5) + 40));
        }
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E8530);
        t10 = ts4_call_seq_lbl_880E7704_881CF7A0((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)(ts4_word)&loc50[0]);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)t10 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t10) + 40));
        }
    }
    t15 = fn_881CECD0((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 24)));
    *(volatile ts4_word *)((char *)(ts4_word)(t15) + 24) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t15) + 24)) | 268435456);
    return t15;
}

/* Swing_DLL.xex 0x881DBD60: if_get u32@0xc, u32@0x4, u32@0xc, u32@0x5c, u32@0xc */
void ts4_if_get_u32_offc_881DBD60(ts4_word a0, ts4_word a1)
{
    int t1;
    ts4_word t2;
    float t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 == 0) {
        return;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12))) + 92) = (ts4_word)t2;
    t4 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(volatile float *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12))) + 96) = t4;
    return;
}

/* Swing_DLL.xex 0x881DC7B8: call_seq fn_881DC818, u32@0x14, fn_881DC558, fn_881DC928, ts4_call_seq_fn_881B19A0_881DC8C8 */
ts4_word ts4_call_seq_fn_881DC818_881DC7B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[62];
    ts4_word t5;

    (void)a1;
    fn_881DC818((ts4_word)(ts4_word)&loc50[0]);
    fn_881DC558((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(ts4_word)&loc50[0]);
    fn_881DC928((ts4_word)a0, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    t5 = ts4_call_seq_fn_881B19A0_881DC8C8((ts4_word)(ts4_word)&loc50[0]);
    return t5;
}

/* Swing_DLL.xex 0x881DDAB0: get u32@0x0, fn_881DFA08 */
ts4_word ts4_get_u32_off0_881DDAB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    return fn_881DFA08((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
}

/* Swing_DLL.xex 0x881DDAC0: tailcall ts4_if_call_seq_u8_off7d_881E1480 */
ts4_word ts4_tailcall_fn_881E1480_881DDAC0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ts4_if_call_seq_u8_off7d_881E1480((ts4_word)a1);
}

/* Swing_DLL.xex 0x881E0F78: call_seq ts4_call_seq_lbl_880E8AE8_881E0A88, u8@0x7c, u8@0x7c */
ts4_word ts4_call_seq_fn_881E0A88_881E0F78(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_call_seq_lbl_880E8AE8_881E0A88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)(a0) + 124)) & 0xff) & 0xffffffdf);
    return t1;
}

/* Swing_DLL.xex 0x881E13E8: call_seq u32@0x1c, u32@0x30, u32@0x18, fn_881B18E0, lbl_880E84A8, fn_88837880 */
ts4_word ts4_call_seq_u32_off1c_881E13E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[8];
    ts4_word loc70[10];
    ts4_word t2;
    ts4_word t5;
    ts4_word t10;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 48);
    loc50[2] = (ts4_word)0;
    loc50[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 24)), (ts4_word)(t2 + 8));
    t5 = fn_88837880((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E84A8);
    fn_881B19A0((ts4_word)a1);
    fn_881B18E0((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 24)), (ts4_word)(t5 + 8));
    fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    t10 = fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    return t10;
}

/* Swing_DLL.xex 0x881E1510: get u16@0x20, u16@0x20 */
void ts4_get_u16_off20_881E1510(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 32) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(a0) + 32)) & 0xfffffffe);
    return;
}
