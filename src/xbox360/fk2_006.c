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
extern char lbl_880C9684[];
extern char lbl_880C9748[];
extern char lbl_880C9758[];
extern char lbl_880D7A20[];
extern char lbl_880D9F94[];
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
extern char lbl_880E2654[];
extern char lbl_880E2A14[];
extern char lbl_880E2AB8[];
extern char lbl_880E2E70[];
extern char lbl_880E302C[];
extern char lbl_880E3038[];
extern char lbl_880E3044[];
extern char lbl_880E3658[];
extern char lbl_880E365C[];
extern char lbl_880E3664[];
extern char lbl_880E366C[];
extern char lbl_880E3674[];
extern char lbl_880E367C[];
extern char lbl_880E3688[];
extern char lbl_880E369C[];
extern char lbl_880E36A8[];
extern char lbl_880E36D0[];
extern char lbl_880E3738[];
extern char lbl_880E3828[];
extern char lbl_880E38C0[];
extern char lbl_880E3D5C[];
extern char lbl_880E3DAC[];
extern char lbl_880E3DE0[];
extern char lbl_880E3E14[];
extern char lbl_880E3E3C[];
extern char lbl_880E3E74[];
extern char lbl_880E3EB0[];
extern char lbl_880E3F54[];
extern char lbl_880E3F88[];
extern char lbl_880E3FBC[];
extern char lbl_880E3FF0[];
extern char lbl_880E4028[];
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
extern char lbl_880E4528[];
extern char lbl_880E4630[];
extern char lbl_880E4910[];
extern char lbl_880E4BBC[];
extern char lbl_880E4BF8[];
extern char lbl_880E70D8[];
extern char lbl_880EA218[];
extern char lbl_880EA5E4[];
extern char lbl_880EA718[];
extern char lbl_880EF3B0[];
extern char lbl_880EF6F0[];
extern char lbl_880F2968[];
extern char lbl_880F2B00[];
extern char lbl_880F2B80[];
extern char lbl_8814B440[];
extern char lbl_88C6C014[];
extern char lbl_88C6C018[];
extern char lbl_88C6C05C[];
extern char lbl_88C6C21C[];
extern char lbl_88C6C220[];
extern char lbl_88D41FC4[];
extern char lbl_88D45910[];
extern char lbl_88D459E8[];
extern char lbl_88D45A10[];
extern char lbl_88D45A24[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
ts4_word RtlEnterCriticalSection();
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88150600();
ts4_word fn_88166BC0();
ts4_word fn_8816CAA0();
ts4_word fn_881705B0();
ts4_word ts4_call_seq_u32_off0_8817B998();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word fn_8817EA90();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_881A50F0();
ts4_word fn_881AD020();
ts4_word fn_881AD8E0();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881B1CF0();
ts4_word ts4_if_call_seq_fn_888380A8_881B2518();
ts4_word ts4_if_call_seq_fn_888380A8_881B25F0();
ts4_word fn_881B26C8();
ts4_word fn_881B2808();
ts4_word fn_881B3268();
ts4_word ts4_loop_call_seq_u32_off4_881B6840();
ts4_word ts4_loop_call_seq_u32_off0_881B68A8();
ts4_word fn_881B9148();
ts4_word fn_881F41E8();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211A60();
ts4_word fn_885651F8();
ts4_word ts4_tailcall_fn_88565410_885654D8();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_tailcall_XamContentGetCreator_8857B2E8();
ts4_word fn_8857C8C8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_88610620();
ts4_word fn_886131F0();
ts4_word fn_88617788();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word ts4_if_call_seq_lbl_880F21E8_88720080();
ts4_word fn_887BD430();
ts4_word fn_887C0948();
ts4_word fn_887C5D30();
ts4_word fn_887CB978();
ts4_word fn_887CDAA0();
ts4_word fn_887CE250();
ts4_word fn_887CE478();
ts4_word fn_887CFC48();
ts4_word fn_887D0378();
ts4_word fn_887D0C80();
ts4_word fn_887D9A10();
ts4_word fn_887E15D0();
ts4_word fn_887E2770();
ts4_word fn_887E2FE8();
ts4_word fn_887E6380();
ts4_word fn_887E6478();
ts4_word fn_887E6A50();
ts4_word fn_887E72E0();
ts4_word fn_887EC7A0();
ts4_word fn_887EEA00();
ts4_word fn_887EF2D8();
ts4_word fn_887F0CA0();
ts4_word fn_887F4698();
ts4_word fn_887FC678();
ts4_word fn_887FEE60();
ts4_word fn_888063B0();
ts4_word fn_88806428();
ts4_word fn_88807D48();
ts4_word fn_88810408();
ts4_word fn_88810F00();
ts4_word fn_88811318();
ts4_word ts4_loop_get_u8_offd_888114E0();
ts4_word fn_88813BA8();
ts4_word fn_88814470();
ts4_word ts4_call_seq_u32_off34_888145C8();
ts4_word ts4_loop_call_seq_fn_88814418_88814950();
ts4_word fn_88814A70();
ts4_word fn_88814BB8();
ts4_word fn_88814D20();
ts4_word fn_88814E68();
ts4_word fn_88815428();
ts4_word fn_88815580();
ts4_word fn_88815628();
ts4_word fn_88816C30();
ts4_word fn_88817818();
ts4_word fn_88817F88();
ts4_word fn_888195F0();
ts4_word fn_8881C828();
ts4_word fn_8881C8B8();
ts4_word fn_8881D170();
ts4_word fn_8881D478();
ts4_word fn_8881E350();
ts4_word fn_8881F6D8();
ts4_word fn_888203F0();
ts4_word fn_88820468();
ts4_word fn_888208A8();
ts4_word fn_88820AF0();
ts4_word fn_88820C30();
ts4_word fn_888214B0();
ts4_word fn_88821568();
ts4_word fn_88821618();
ts4_word fn_888216D0();
ts4_word fn_88821878();
ts4_word fn_88822398();
ts4_word fn_88822738();
ts4_word fn_88822888();
ts4_word fn_88822DB0();
ts4_word fn_88823768();
ts4_word fn_88823AE8();
ts4_word fn_88823FC0();
ts4_word fn_88824188();
ts4_word fn_88824248();
ts4_word fn_888246A8();
ts4_word fn_88824B68();
ts4_word ts4_match_class_88824F38();
ts4_word fn_88825118();
ts4_word fn_88829550();
ts4_word fn_8882DE88();
ts4_word fn_8882E218();
ts4_word fn_8882E6B8();
ts4_word fn_8882E950();
ts4_word fn_8882ED00();
ts4_word ts4_match_flag_char_8882EED0();
ts4_word fn_8882F1E8();
ts4_word fn_888319E0();
ts4_word ts4_call_seq_u32_off0_88832F70();
ts4_word fn_888368B0();
ts4_word ts4_if_call_seq_u32_off8_88837608();
ts4_word ts4_call_seq_u32_off18_88837CB0();
ts4_word fn_88838B00();
ts4_word ts4_member_field_addr_8883B578();
ts4_word fn_8883DDA0();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_888429E8();
ts4_word fn_88843650();
ts4_word fn_8884C160();
ts4_word fn_88867E68();
ts4_word fn_888AD568();
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0();
ts4_word fn_889254C8();
ts4_word fn_8892DC70();
ts4_word fn_889C63A0();
ts4_word fn_889CE718();
ts4_word fn_889CE7D8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88720180: if_call_seq lbl_880F2B80, u32@0x0, u32@0x80, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F2B80_88720180(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2B80;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 136)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    t9 = ts4_if_call_seq_lbl_880F21E8_88720080((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x887201F0: if_call_seq lbl_880F2B00, u32@0x0, u32@0x80, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F2B00_887201F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2B00;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 136)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    t9 = ts4_if_call_seq_lbl_880F21E8_88720080((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88723A60: if_call_seq lbl_880F2968, u32@0x0, u32@0x80, u32@lbl_88D45B38, u32@lbl_88D45B38, fn_885651F8 */
ts4_word ts4_if_call_seq_lbl_880F2968_88723A60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2968;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128);
    if ((ts4_word)t1 != 0) {
        t3 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t3 != 0) {
            fn_886131F0((ts4_word)t3, (ts4_word)t1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 136)));
        } else {
            fn_885651F8((ts4_word)t1, (ts4_word)t1);
        }
    }
    t9 = ts4_if_call_seq_lbl_880F21E8_88720080((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x887B5DD8: call_seq lbl_880EF6F0, u32@0x0, u32@0x28, ts4_destroy_owned_object, fn_881F41E8 */
ts4_word ts4_call_seq_lbl_880EF6F0_887B5DD8(ts4_word a0)
{
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF6F0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 40)));
    t3 = fn_881F41E8((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x887B6788: if_call_seq lbl_880EF3B0, u32@0x0, u32@0x50, ts4_destroy_owned_object, u32@0x44, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880EF3B0_887B6788(ts4_word a0)
{
    ts4_word t9;
    ts4_word t12;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF3B0;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 80)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 68)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 56)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 44)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA218;
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t9 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t9);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    t12 = fn_881F41E8((ts4_word)a0);
    return t12;
}

/* Swing_DLL.xex 0x887BDBA0: if_get u32@0x28, u8@0x398, u32@0x4, u32@0x28, u8@0x8, u32@0x28 */
ts4_word ts4_if_get_u32_off28_887BDBA0(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    unsigned char t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 920);
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)((2696740864) | 58926);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(unsigned char *)((char *)(ts4_word)(t3) + 8) = (unsigned char)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(unsigned char *)((char *)(ts4_word)(t4) + 9) = (unsigned char)0;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(unsigned char *)((char *)(ts4_word)(t5) + 16) = (unsigned char)t2;
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)0;
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)0;
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(unsigned char *)((char *)(ts4_word)(t8) + 8) = (unsigned char)0;
    t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 920);
    if ((ts4_word)t9 == 0) {
        return a0;
    }
    return fn_887BD430((ts4_word)a0, (ts4_word)t5, (ts4_word)t4, (ts4_word)t3, (ts4_word)t9, (ts4_word)t8, (ts4_word)t7, (ts4_word)t6);
}

/* Swing_DLL.xex 0x887C4650: call_seq fn_889C63A0, u32@lbl_88D41FC4, u32@0x88, u32@0x0, fn_8882ED00 */
ts4_word ts4_call_seq_fn_889C63A0_887C4650(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[258];

    (void)a0;
    loc50[0] = (ts4_word)1024;
    fn_889C63A0((ts4_word)a1, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_8882ED00((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D41FC4)) + 136))) + 0)), (ts4_word)(ts4_word)&loc60[0]);
    return 0;
}

/* Swing_DLL.xex 0x887C69A0: if_get u32@0x2c, fn_887C0948, fn_887C5D30 */
ts4_word ts4_if_get_u32_off2c_887C69A0(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)t1 == 1) {
        return fn_887C5D30((ts4_word)a0);
    }
    if ((int)t1 != 0) {
        return a0;
    }
    return fn_887C0948((ts4_word)a0);
}

/* Swing_DLL.xex 0x887C79B8: call_seq ts4_tailcall_fn_88565410_885654D8 */
ts4_word ts4_call_seq_fn_885654D8_887C79B8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[514];
    ts4_word t1;

    t1 = ts4_tailcall_fn_88565410_885654D8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    return t1;
}

/* Swing_DLL.xex 0x887C79E8: if_call_seq u32@0x150, RtlEnterCriticalSection, u32@0x150, u32@0x114, u32@0x2a88, u32@0x114 */
ts4_word ts4_if_call_seq_u32_off150_887C79E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word p11;
    ts4_word p12;
    int t1;
    ts4_word t2;
    int t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
    p12 = (ts4_word)a0;
    if ((int)t1 >= 0) {
        t2 = RtlEnterCriticalSection((ts4_word)(a0 + 308));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 336);
        p11 = (ts4_word)t2;
        if ((int)t3 == 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
            t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 10888);
            p9 = (ts4_word)t2;
            if ((ts4_word)t7 != 0) {
                t8 = fn_8857C8C8((ts4_word)t2);
                p9 = (ts4_word)t8;
            }
            t10 = fn_8857C8C8((ts4_word)p9);
            *(ts4_word *)((char *)(ts4_word)(t6) + 10888) = (ts4_word)t10;
            p11 = (ts4_word)t10;
        }
        p12 = (ts4_word)p11;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 336)) + 1);
    return p12;
}

/* Swing_DLL.xex 0x887C7DB8: addr lbl_880EA5E4, u32@lbl_88D45B1C, u32@0x0, u32@0x280, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_addr_lbl_880EA5E4_887C7DB8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA5E4;
    *(ts4_word *)((char *)(ts4_word)(t1) + 640) = (ts4_word)0;
    return ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
}

/* Swing_DLL.xex 0x887C8350: call_seq lbl_880EA718, u32@0x0, u32@0xac, ts4_destroy_owned_object, u32@0xa0, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880EA718_887C8350(ts4_word a0)
{
    ts4_word t9;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA718;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 172)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 160)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 148)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 136)));
    t9 = fn_8860BBD8((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x887CBAE8: if_call_seq u32@0x0, fn_887CB978, u32@0x0, u32@0x374, u32@0x374, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_887CBAE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a3;
    t2 = fn_887CB978((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    if ((ts4_word)(t2 & 0xff) == 1 && (ts4_word)(a4 & 0xff) == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 884);
        loc50[0] = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a1) + 884) = (ts4_word)(t3 + 1);
        loc54[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
        t5 = ts4_if_call_seq_u32_lbl_88D45B38_88211A60((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t5;
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x887CBB70: if_call_seq u8@0x370, u32@0x360, ts4_tailcall_XamContentGetCreator_8857B2E8 */
ts4_word ts4_if_call_seq_u8_off370_887CBB70(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 880);
    if ((ts4_word)t1 == 1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 864);
        loc50[0] = (ts4_word)0;
        t3 = ts4_tailcall_XamContentGetCreator_8857B2E8((ts4_word)t2, (ts4_word)(a0 + 552), (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)0);
        if ((ts4_word)t3 == 0) {
            t4 = loc50[0];
            return ((t4 + -1) == 0);
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x887CBE40: if_call_seq lbl_880E4BBC, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E4BBC_887CBE40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887CC8F8: if_call_seq memcpy, u8@0x370, ts4_assign_formatted_text, fn_88150600, ts4_destroy_owned_object, u32@0x360 */
ts4_word ts4_if_call_seq_memcpy_887CC8F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p10;
    ts4_word loc50[6];
    unsigned char t2;
    ts4_word t5;
    ts4_word t8;

    memcpy((ts4_word)(a0 + 552), (ts4_word)a1, (ts4_word)308);
    t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 880);
    p10 = (ts4_word)0;
    if ((ts4_word)t2 == 0) {
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
        fn_88150600((ts4_word)(a0 + 868), (ts4_word)(ts4_word)&loc50[0]);
        t5 = loc50[0];
        ts4_destroy_owned_object((ts4_word)t5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 864) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)2;
        t8 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 868)));
        fn_88617788((ts4_word)a0, (ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 860) = (ts4_word)a4;
        *(unsigned char *)((char *)(ts4_word)(a0) + 880) = (unsigned char)1;
        p10 = (ts4_word)1;
    }
    return p10;
}

/* Swing_DLL.xex 0x887CDA68: if_get u32@lbl_88C6C220, u32@0x0, u32@lbl_88C6C21C, u32@0x0 */
void ts4_if_get_u32_lbl_88C6C220_887CDA68(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)lbl_8814B440;
    if (!(t1 < t2)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)lbl_88C6C21C);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)lbl_88C6C220);
    return;
}

/* Swing_DLL.xex 0x887CDD08: get u32@0x2c, u32@0x368 */
ts4_word ts4_get_u32_off2c_887CDD08(ts4_word a0)
{
    return ((int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 872)) / (int)60);
}

/* Swing_DLL.xex 0x887CE660: if_get u32@0x58, u32@0xa8, u32@0x11c */
ts4_word ts4_if_get_u32_off58_887CE660(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((int)t1 != 6) {
        return ((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) + 180);
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + 88);
}

/* Swing_DLL.xex 0x887CEAE0: get  */
void ts4_get_887CEAE0(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a0) + 0) = (-t1);
    *(float *)((char *)(ts4_word)(a0) + 8) = (-t2);
    return;
}

/* Swing_DLL.xex 0x887CF118: if_get u32@0x4, u32@0x0, fn_887E15D0 */
ts4_word ts4_if_get_u32_off4_887CF118(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != (ts4_word)((2247622656) | 27837)) {
        return a0;
    }
    return fn_887E15D0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0));
}

/* Swing_DLL.xex 0x887CF7C0: if_call_seq u32@0x8, u8@0x28, u8@0x28, u32@0xc, u32@0xc, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off8_887CF7C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p19;
    ts4_word p26;
    ts4_word t1;
    unsigned char t3;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;
    ts4_word t22;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    p26 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a1) + 40);
        p19 = (ts4_word)a0;
        if ((ts4_word)t3 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
            if ((ts4_word)t5 != 0) {
                *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 20))) + t5) = (unsigned char)1;
            }
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
            *(ts4_word *)((char *)(ts4_word)(t9) + 1812) = (ts4_word)t10;
            t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            t12 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
            *(ts4_word *)((char *)(ts4_word)(t11) + 1816) = (ts4_word)t12;
            t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            t14 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
            *(ts4_word *)((char *)(ts4_word)(t13) + 1808) = (ts4_word)(t14 + 1);
            t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            *(ts4_word *)((char *)(ts4_word)(t15) + 1804) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 28)) + 1);
            t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            t18 = fn_887CE250((ts4_word)a0, (ts4_word)(t17 + 1820), (ts4_word)(t17 + 1824), (ts4_word)(t14 + 1), (ts4_word)t13, (ts4_word)t12, (ts4_word)t11, (ts4_word)t10);
            p19 = (ts4_word)t18;
        }
        t20 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)(ts4_word)(t20) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
        t22 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)(ts4_word)(t22) + 5) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 41));
        p26 = (ts4_word)p19;
    }
    return p26;
}

/* Swing_DLL.xex 0x887D0790: set u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x24 */
void ts4_set_u32_off4_887D0790(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D09D8: set u32@0x1c, u32@0x20, u32@0x24, u32@0x28, u32@0x2c, u32@0x30 */
void ts4_set_u32_off1c_887D09D8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D0B48: set u32@0x4, u32@0x0, u32@0x4, u32@0x8, u32@0xc, u8@0x10 */
void ts4_set_u32_off4_887D0B48(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x887D0DF8: if_call_seq u32@0x34, u8@0x344, u8@0x99, fn_887D0C80, u32@0x30, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off34_887D0DF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word loc50[1];
    ts4_word t1;
    unsigned char t2;
    ts4_word t5;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 836);
    if ((ts4_word)t2 != 1 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 153)) != 1) {
        fn_887D0C80((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
        t5 = loc50[0];
        if ((ts4_word)t5 != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)((1994981376) | 32180);
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)t5;
            t6 = fn_887CE478((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
            p7 = (ts4_word)t6;
        } else {
            p7 = (ts4_word)0;
        }
        p8 = (ts4_word)p7;
    } else {
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Swing_DLL.xex 0x887D13C8: if_get u32@0x34, u8@0xd4, u8@0x95, u8@0x95, u32@0xd0, u32@0x0 */
ts4_word ts4_if_get_u32_off34_887D13C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t1;
    unsigned char t2;
    unsigned char t4;
    ts4_word t13;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t21;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 212);
    if ((ts4_word)t2 == 0) {
        t4 = *(unsigned char *)((char *)(ts4_word)(t1) + 149);
        if ((ts4_word)t4 != 0) {
            t13 = *(ts4_word *)((char *)(ts4_word)(t1) + 208);
            if ((ts4_word)t13 != (ts4_word)((3374514176) | 34673) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 153)) == 0) {
                t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
                loc50[0] = (ts4_word)((3691315200) | 12162);
                t18 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t15) + 64))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
                if ((ts4_word)t16 == (ts4_word)t18 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 840)) != 0) {
                    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)((1774583808) | 15994);
                    t21 = fn_887CE478((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
                    return t21;
                }
                return 0;
            }
            return 0;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        loc50[0] = (ts4_word)((3691315200) | 12162);
        t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t6) + 64))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)t7 == (ts4_word)t9 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 840)) != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)((1774583808) | 15994);
            t12 = fn_887CE478((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
            return t12;
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x887D2B40: call_seq fn_88617D88, lbl_880E70D8, u32@0x0, u32@0x24, u32@0x28, u32@0x40 */
ts4_word ts4_call_seq_fn_88617D88_887D2B40(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E70D8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)lbl_88D45A24 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887D3C88: if_call_seq u32@0x0, u32@0xd8, fn_888AD568, u8@0x2fd, u32@0x0, u32@0x118 */
ts4_word ts4_if_call_seq_u32_off0_887D3C88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        t3 = fn_888AD568((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 216)));
        if ((ts4_word)t3 != 0) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 765) = (unsigned char)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
            p5 = (ts4_word)t3;
        } else {
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    } else {
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Swing_DLL.xex 0x887D4C38: call_seq fn_887CDAA0, fn_887D0378 */
ts4_word ts4_call_seq_fn_887CDAA0_887D4C38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[16];
    ts4_word t2;

    fn_887CDAA0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_887D0378((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t2;
}

/* Swing_DLL.xex 0x887D4D08: get u32@0x0, u32@0x2e0, u32@0x2dc */
void ts4_get_u32_off0_887D4D08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 736) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 732) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x887D5760: set u32@0xc, u32@0x10, u32@0x14, u32@0x18, u32@0x0, u32@0xc */
void ts4_set_u32_offc_887D5760(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887D9510: if_call_seq u32@lbl_88D45910, u32@0x0, u32@0x4, ts4_call_seq_u32_off0_8817B998, fn_8817EA90, ts4_if_call_seq_fn_8817EA90_888D85B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45910_887D9510(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D45910;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        ts4_call_seq_u32_off0_8817B998((ts4_word)(ts4_word)&loc50[0]);
        fn_8817EA90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
        ts4_if_call_seq_fn_8817EA90_888D85B0((ts4_word)t1, (ts4_word)t3, (ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
        ts4_if_call_seq_u32_off4_8817E430((ts4_word)(ts4_word)&loc50[0]);
    }
    return 1;
}

/* Swing_DLL.xex 0x887DAA58: if_call_seq u32@0x58, u8@0x126, fn_887CFC48, u32@0xf8, fn_887D9A10, u8@0x124 */
ts4_word ts4_if_call_seq_u32_off58_887DAA58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p9;
    int t1;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    p9 = (ts4_word)a0;
    if ((int)t1 == 3 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 294)) != 0) {
        t3 = fn_887CFC48((ts4_word)a0);
        p8 = (ts4_word)t3;
        if ((ts4_word)(t3 & 0xff) != 0) {
            t5 = fn_887D9A10((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 248)) + 88));
            if ((ts4_word)(t5 & 0xff) == 0) {
                *(unsigned char *)((char *)(ts4_word)(a0) + 292) = (unsigned char)1;
            }
            p8 = (ts4_word)t5;
        }
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Swing_DLL.xex 0x887DBC70: call_seq lbl_880D7A20, fn_8862C0E8, lbl_880D9F94, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_lbl_880D7A20_887DBC70(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D7A20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t4;
    t5 = fn_8862C0E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880D9F94);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(t5) + 4);
    t8 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t8;
    return t8;
}

/* Swing_DLL.xex 0x887E40A0: if_call_seq fn_887E2FE8, fn_887E2770, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_if_call_seq_fn_887E2FE8_887E40A0(ts4_word a0)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_887E2FE8();
    if ((ts4_word)t1 != 0) {
        t2 = fn_887E2770((ts4_word)t1);
        if ((ts4_word)t2 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4)) == (ts4_word)((1578893312) | 34803)) {
            *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
            p4 = (ts4_word)1;
        } else {
            p4 = (ts4_word)0;
        }
        p5 = (ts4_word)p4;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Swing_DLL.xex 0x887E6550: if_call_seq u32@0xc, u32@0x4, u32@0x0, u32@0xc, fn_88166BC0, fn_887E6380 */
ts4_word ts4_if_call_seq_u32_offc_887E6550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p9;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;

    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if (((ts4_word)t1 != (ts4_word)a1 && (int)a1 > 0) && (ts4_word)a1 < (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) / (int)36)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a1 + -1);
        t4 = fn_88166BC0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
        fn_887E6380((ts4_word)a0, (ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    p9 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        t8 = ts4_destroy_owned_object((ts4_word)t7);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x887E6F00: get u32@0x1c, u32@0x54, u32@0x1c, u32@0x50, u32@0x1c, fn_887E6A50 */
ts4_word ts4_get_u32_off1c_887E6F00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80) = (ts4_word)1;
    return fn_887E6A50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x887E6F20: get u32@0x1c, u32@0x54, u32@0x1c, u32@0x50, u32@0x1c, u8@0x301 */
ts4_word ts4_get_u32_off1c_887E6F20(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 769) = (unsigned char)1;
    return fn_887E6A50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x887E6F48: get u32@0x1c, u32@0x54, u32@0x1c, u32@0x50, u32@0x1c, fn_887E6A50 */
ts4_word ts4_get_u32_off1c_887E6F48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 80) = (ts4_word)2;
    return fn_887E6A50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x887E81E0: if_call_seq u32@0x0, u32@0x58, u32@0x58, fn_887E72E0, u32@0x58, u8@0x125 */
ts4_word ts4_if_call_seq_u32_off0_887E81E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t3;
    int t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != -1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
        if ((int)t3 != 3) {
            if ((int)t3 == 1) {
                fn_887E72E0((ts4_word)a0, (ts4_word)2, (ts4_word)0);
            }
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
            if ((int)t6 != 3) {
                *(volatile unsigned char *)((char *)(ts4_word)(a0) + 293) = (unsigned char)1;
                fn_887E72E0((ts4_word)a0, (ts4_word)3, (ts4_word)0);
            }
        }
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 292) = (unsigned char)0;
        fn_887E6478((ts4_word)a0, (ts4_word)1, (ts4_word)t1);
    }
    return 1;
}

/* Swing_DLL.xex 0x887E9580: loop_get u32@0x20, u32@0x24, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off20_887E9580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 0))))((ts4_word)t4, (ts4_word)1);
            }
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t9);
    }
    t14 = ts4_object_finalize((ts4_word)(a0 + 32));
    return t14;
}

/* Swing_DLL.xex 0x887E9660: loop_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_loop_get_u32_off0_887E9660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 0))))((ts4_word)t4, (ts4_word)1);
            }
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            p10 = (ts4_word)(lv3 + 4);
            lv3 = p10;
        } while ((ts4_word)p10 != (ts4_word)t9);
    }
    t14 = ts4_object_finalize((ts4_word)a0);
    return t14;
}

/* Swing_DLL.xex 0x887E96D8: loop_get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x14, u32@0x10 */
ts4_word ts4_loop_get_u32_off0_887E96D8(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word lv4;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == (ts4_word)t2) {
        return t1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    lv4 = (ts4_word)t1;
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 20);
        if ((ts4_word)t6 == (ts4_word)t3 && (int)(*(ts4_word *)((char *)(ts4_word)(t5) + 16)) == (int)a2) {
            return lv4;
        }
        p8 = (ts4_word)(lv4 + 4);
        lv4 = p8;
    } while ((ts4_word)p8 != (ts4_word)t2);
    return lv4;
}

/* Swing_DLL.xex 0x887EA7B0: if_get u8@0x1, u32@0x8, ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_if_get_u8_off1_887EA7B0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    if ((ts4_word)t1 != 1) {
        return a0;
    }
    return ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)-1);
}

/* Swing_DLL.xex 0x887EA818: if_get u8@0x1, u32@0x8, ts4_if_get_u32_lbl_88C32048_8857A1E0 */
ts4_word ts4_if_get_u8_off1_887EA818(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    if ((ts4_word)t1 != 1) {
        return a0;
    }
    return ts4_if_get_u32_lbl_88C32048_8857A1E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Swing_DLL.xex 0x887EB400: if_call_seq lbl_880E4BBC, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E4BBC_887EB400(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887EB450: call_seq fn_88617D88, lbl_880E4BBC, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_887EB450(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BBC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x887EB5F8: if_get u32@0x0, u32@0xc, u32@0x4, u32@0x38, u32@0x38, u32@0x0 */
ts4_word ts4_if_get_u32_off0_887EB5F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;
    ts4_word t13;
    ts4_word t19;
    ts4_word t23;
    ts4_word t29;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12) = (ts4_word)0;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t2 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        if ((ts4_word)t4 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 36))))((ts4_word)t4, (ts4_word)(t2 + 4), (ts4_word)0);
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 96))))((ts4_word)t9);
        t13 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t13 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 0))))((ts4_word)t13, (ts4_word)1);
        }
    }
    t19 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t19 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t19) + 0))) + 20))))((ts4_word)t19);
        t23 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        if ((ts4_word)t23 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 0))))((ts4_word)t23, (ts4_word)1);
        }
    }
    t29 = ts4_tsu_cleanup_end((ts4_word)a1);
    return t29;
}

/* Swing_DLL.xex 0x887ECAE0: loop_call_seq u32@0x4c, u32@0x50, u32@0x0, fn_887EC7A0, u32@0x50, u32@0x58 */
ts4_word ts4_loop_call_seq_u32_off4c_887ECAE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word lv13;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t11;
    ts4_word t12;
    ts4_word t16;
    ts4_word t22;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            fn_887EC7A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0)));
            t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
            p7 = (ts4_word)(lv3 + 4);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t6);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t11 != (ts4_word)t12) {
        lv13 = (ts4_word)t11;
        do {
            fn_887EC7A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv13) + 0)));
            t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
            p17 = (ts4_word)(lv13 + 4);
            lv13 = p17;
        } while ((ts4_word)p17 != (ts4_word)t16);
    }
    ts4_object_finalize((ts4_word)(a0 + 76));
    t22 = ts4_object_finalize((ts4_word)(a0 + 88));
    return t22;
}

/* Swing_DLL.xex 0x887EE780: if_call_seq lbl_880E4BF8, u32@0x0, u32@0x58, ts4_destroy_owned_object, u32@0x4c, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880E4BF8_887EE780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BF8;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    t16 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t16;
}

/* Swing_DLL.xex 0x887EEF68: loop_get u32@0x1dc, u32@0x4c, vcall, u32@0x0, u32@0x4, fn_887EEA00 */
ts4_word ts4_loop_get_u32_off1dc_887EEF68(ts4_word a0)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word lv8;
    ts4_word p10;
    ts4_word p11;
    ts4_word t3;
    int t4;
    ts4_word t9;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 476))) + 76))))((ts4_word)(a0 + 476), (ts4_word)0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    p6 = (ts4_word)0;
    if ((int)t4 != -1) {
        p6 = (ts4_word)((((*(ts4_word *)((char *)(ts4_word)(t3) + 4)) << 4) + t4) + t3);
    }
    p7 = (ts4_word)0;
    if ((int)t4 != -1) {
        p7 = (ts4_word)(t4 + t3);
    }
    p11 = (ts4_word)t3;
    if ((ts4_word)p6 != (ts4_word)p7) {
        lv8 = (ts4_word)p7;
        do {
            t9 = fn_887EEA00((ts4_word)a0, (ts4_word)lv8, (ts4_word)0);
            p10 = (ts4_word)(lv8 + 16);
            lv8 = p10;
        } while ((ts4_word)p10 != (ts4_word)p6);
        p11 = (ts4_word)t9;
    }
    return p11;
}

/* Swing_DLL.xex 0x887EF420: loop_get u32@lbl_88D45A10, u32@0x18, u32@0x1c, u32@0x0, u32@0x8, vcall */
ts4_word ts4_loop_get_u32_lbl_88D45A10_887EF420(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    int t2;
    ts4_word t5;
    int t6;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)lbl_88D45A10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((3751936000) | 45041);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    p7 = (ts4_word)t2;
    p8 = (ts4_word)a0;
    if ((int)t2 == 1) {
        do {
            t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
            t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
        } while ((int)t6 == 1);
        p7 = (ts4_word)t6;
        p8 = (ts4_word)t5;
    }
    p10 = (ts4_word)p8;
    if ((int)p7 == 2) {
        t9 = fn_887EF2D8((ts4_word)t1);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x887EFD68: loop_get u32@0x7c, u32@0x78, u32@0x0, u32@0x0, u32@0x30, vcall */
ts4_word ts4_loop_get_u32_off7c_887EFD68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    p9 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 48))))((ts4_word)t4, (ts4_word)a1);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x887EFF80: loop_get u32@0x7c, u32@0x78, u32@0x0, u32@0x0, u32@0x20, vcall */
ts4_word ts4_loop_get_u32_off7c_887EFF80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    p9 = (ts4_word)a0;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)t4);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 73) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 75) = (unsigned char)1;
    return p9;
}

/* Swing_DLL.xex 0x887F0550: if_set u32@0xe0, u32@0x10, u32@0x0, u32@0x18 */
ts4_word ts4_if_set_u32_offe0_887F0550(ts4_word a0, ts4_word a1)
{
    int t1;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t1 == -1) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0, (ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x887F0588: if_set u32@0xe0, u32@0x10, u32@0x0, u32@0x18 */
ts4_word ts4_if_set_u32_offe0_887F0588(ts4_word a0, ts4_word a1)
{
    int t1;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t1 == -1) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0, (ts4_word)t1, (ts4_word)0, (ts4_word)1, (ts4_word)0);
}

/* Swing_DLL.xex 0x887F05C0: if_set u32@0xe0, u32@0x10, u32@0x0, u32@0x18 */
ts4_word ts4_if_set_u32_offe0_887F05C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    if ((ts4_word)(a2 & 0xff) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)a1;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t1 == -1) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0, (ts4_word)t1, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x887F0BD0: if_get u32@0xe0, u32@lbl_88D45B1C, u32@0x27c, u32@0xc, u32@lbl_88C6C014, u32@0x27c */
ts4_word ts4_if_get_u32_offe0_887F0BD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p5;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    t2 = *(ts4_word *)lbl_88D45B1C;
    if ((ts4_word)t1 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 636));
    }
    t6 = *(ts4_word *)lbl_88C6C014;
    if ((ts4_word)p5 == (ts4_word)t6) {
        return a0;
    }
    if ((ts4_word)t1 != 0) {
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 636));
    }
    t10 = *(ts4_word *)lbl_88C6C05C;
    if ((ts4_word)p9 == (ts4_word)t10) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)t2, (ts4_word)t6);
}

/* Swing_DLL.xex 0x887F0C38: if_get u32@0xe0, u32@lbl_88D45B1C, u32@0x27c, u32@0xc, u32@lbl_88C6C014, u32@0x27c */
ts4_word ts4_if_get_u32_offe0_887F0C38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p5;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    t2 = *(ts4_word *)lbl_88D45B1C;
    if ((ts4_word)t1 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 636));
    }
    t6 = *(ts4_word *)lbl_88C6C014;
    if ((ts4_word)p5 == (ts4_word)t6) {
        return a0;
    }
    if ((ts4_word)t1 != 0) {
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 636));
    }
    t10 = *(ts4_word *)lbl_88C6C05C;
    if ((ts4_word)p9 == (ts4_word)t10) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)t2, (ts4_word)t6);
}

/* Swing_DLL.xex 0x887F1858: if_get u32@0xe0, u32@lbl_88D45B1C, u32@0x27c, u32@0xc, u32@lbl_88C6C018, lbl_88C6C014 */
ts4_word ts4_if_get_u32_offe0_887F1858(ts4_word a0)
{
    ts4_word p5;
    ts4_word p12;
    ts4_word p13;
    ts4_word t1;
    ts4_word t6;
    ts4_word t16;
    ts4_word t7;
    int t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 224);
    if ((ts4_word)t1 != 0) {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    } else {
        p5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    }
    t6 = *(ts4_word *)lbl_88C6C018;
    if ((ts4_word)p5 == (ts4_word)t6) {
        t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0);
        return t16;
    }
    t7 = fn_887F0CA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C6C014);
    p13 = (ts4_word)t7;
    if ((ts4_word)t7 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)t7;
        t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 16);
        p12 = (ts4_word)t7;
        if ((int)t8 != -1) {
            t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0, (ts4_word)t8, (ts4_word)0, (ts4_word)1, (ts4_word)0);
            p12 = (ts4_word)t11;
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Swing_DLL.xex 0x887F4E30: call_seq lbl_880E4630, u32@0x0, u32@0x13c, ts4_destroy_owned_object, u32@0x130, ts4_destroy_owned_object */
ts4_word ts4_call_seq_lbl_880E4630_887F4E30(ts4_word a0)
{
    ts4_word t17;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4630;
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 316)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 304)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 292)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 280)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 268)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 256)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 244)));
    ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 232)));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4528;
    t17 = fn_887F4698((ts4_word)a0);
    return t17;
}

/* Swing_DLL.xex 0x887F4F48: if_call_seq lbl_880E4910, u32@0x0, u32@0xe8, ts4_destroy_owned_object, lbl_880E4528, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880E4910_887F4F48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4910;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 232);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4528;
    t4 = fn_887F4698((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887F90F0: call_seq fn_88617D88, lbl_880E3E14, u32@0x0, u32@0x20, u32@0x30, u32@0x34 */
ts4_word ts4_call_seq_fn_88617D88_887F90F0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E14;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    ts4_object_finalize((ts4_word)(a0 + 60));
    return a0;
}

/* Swing_DLL.xex 0x887F93C8: if_call_seq lbl_880E3D5C, u32@0x0, u32@0x34, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E3D5C_887F93C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887F9418: call_seq fn_88617D88, lbl_880E3D5C, u32@0x0, u32@0x34, u32@0x38, u32@0x3c */
ts4_word ts4_call_seq_fn_88617D88_887F9418(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3D5C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x887F9CB8: set u32@0x10, u32@0x0, u32@0x8, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_set_u32_off10_887F9CB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a5;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a6;
    return ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 48))))((ts4_word)a0);
}

/* Swing_DLL.xex 0x887FB270: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB270(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB2C0: addr lbl_880E3DAC, u32@0x4, u32@0x0, u32@0x10, u32@0x14, u32@0x18 */
void ts4_addr_lbl_880E3DAC_887FB2C0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB700: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB700(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB750: set u32@0x4, u32@0x10, lbl_880E434C, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FB750(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E434C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB790: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB790(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB7E0: set u32@0x4, u32@0x10, lbl_880E4314, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FB7E0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4314;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB820: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB820(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB870: set u32@0x4, u32@0x10, lbl_880E42E0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FB870(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E42E0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB8B0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB8B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB900: set u32@0x4, u32@0x10, lbl_880E42AC, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FB900(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E42AC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB940: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB940(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FB990: set u32@0x4, u32@0x10, lbl_880E41EC, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FB990(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E41EC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FB9D0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FB9D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBA20: set u32@0x4, u32@0x10, lbl_880E4174, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBA20(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4174;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBA60: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBA60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBAB0: set u32@0x4, u32@0x10, lbl_880E406C, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBAB0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E406C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBAF0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBAF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBB40: set u32@0x4, u32@0x10, lbl_880E4028, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBB40(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4028;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBB80: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBB80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBBD0: set u32@0x4, u32@0x10, lbl_880E3FF0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBBD0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3FF0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBC10: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBC10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBC60: set u32@0x4, u32@0x10, lbl_880E3FBC, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBC60(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3FBC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBE78: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBE78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FBEC8: set u32@0x4, u32@0x10, lbl_880E3F88, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBEC8(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3F88;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FBF08: if_call_seq lbl_880E3F54, u32@0x0, u32@0x44, ts4_destroy_owned_object, u32@0x38, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880E3F54_887FBF08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3F54;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = fn_8860BBD8((ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x887FBF90: set u32@0x4, u32@0x10, lbl_880E3F54, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FBF90(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3F54;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x887FBFF0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FBFF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC0A0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC0A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC0F0: set u32@0x4, u32@0x10, lbl_880E3EB0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC0F0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3EB0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC130: if_call_seq lbl_880E3E3C, u32@0x0, u32@0x60, u32@0x5c, ts4_loop_call_seq_u32_off4_881B6840, u32@0x5c */
ts4_word ts4_if_call_seq_lbl_880E3E3C_887FC130(ts4_word a0)
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

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E3C;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96);
    ts4_loop_call_seq_u32_off4_881B6840((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 92)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84);
    ts4_loop_call_seq_u32_off0_881B68A8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 80)), (ts4_word)t7);
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t13 != 0) {
        ts4_destroy_owned_object((ts4_word)t13);
    }
    t16 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((ts4_word)t16 != 0) {
        ts4_destroy_owned_object((ts4_word)t16);
    }
    t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t19 != 0) {
        ts4_destroy_owned_object((ts4_word)t19);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DAC;
    t22 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t22 != 0) {
        ts4_destroy_owned_object((ts4_word)t22);
    }
    t25 = fn_8860BBD8((ts4_word)a0);
    return t25;
}

/* Swing_DLL.xex 0x887FC1F0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC1F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC240: set u32@0x4, u32@0x10, lbl_880E3DE0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC240(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3DE0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x887FC2A0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC2A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC2F0: set u32@0x4, u32@0x10, lbl_880E4268, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC2F0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4268;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC330: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC380: set u32@0x4, u32@0x10, lbl_880E4220, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC380(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4220;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC3C0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC3C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC410: set u32@0x4, u32@0x10, lbl_880E41A8, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC410(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E41A8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC450: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC4A0: set u32@0x4, u32@0x10, lbl_880E4130, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC4A0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4130;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC4E0: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC4E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC530: set u32@0x4, u32@0x10, lbl_880E40E8, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC530(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E40E8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC570: if_call_seq lbl_880E3DAC, u32@0x0, u32@0x14, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E3DAC_887FC570(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x887FC5C0: set u32@0x4, u32@0x10, lbl_880E40A0, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off4_887FC5C0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E40A0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x887FC8F0: call_seq fn_887FC678, lbl_880E3E74, u32@0x0, u32@0x68, u32@0x6c, u32@0x70 */
ts4_word ts4_call_seq_fn_887FC678_887FC8F0(ts4_word a0)
{
    fn_887FC678();
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3E74;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x887FEF20: if_call_seq u32@0x40, fn_8892DC70, u32@0x0, u32@0x4, u32@0x8, u32@0x34 */
ts4_word ts4_if_call_seq_u32_off40_887FEF20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word loc50[3];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    p11 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_8892DC70((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        t3 = loc50[0];
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
        t6 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)t4;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t5;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t6;
        fn_887FEE60((ts4_word)a0);
        t8 = loc50[0];
        p10 = (ts4_word)t8;
        if ((ts4_word)t8 != 0) {
            t9 = ts4_destroy_owned_object((ts4_word)t8);
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88800BC0: set u32@0x1c, u32@0x24, u32@0x20, u8@0x8, fn_881B9148 */
ts4_word ts4_set_u32_off1c_88800BC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return fn_881B9148((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88803008: loop_get u32@0x94, u32@0x90, u32@0x0, u32@0x0, u32@0x8, vcall */
ts4_word ts4_loop_get_u32_off94_88803008(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word p9;
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
            t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4);
            p8 = (ts4_word)(lv3 + 4);
            lv3 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
        p9 = (ts4_word)t7;
    }
    return p9;
}

/* Swing_DLL.xex 0x88803CB0: if_call_seq lbl_880E36A8, u32@0x0, u32@0x1c, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E36A8_88803CB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88803D00: call_seq fn_88617D88, lbl_880E36A8, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88803D00(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E36A8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    fn_881705B0((ts4_word)(a0 + 28), (ts4_word)256);
    return a0;
}

/* Swing_DLL.xex 0x88803F80: if_call_seq lbl_880E3828, u32@0x0, u32@0xc, u32@0x8, ts4_loop_call_seq_u32_off0_88150378, u32@0x8 */
ts4_word ts4_if_call_seq_lbl_880E3828_88803F80(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3828;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    ts4_loop_call_seq_u32_off0_88150378((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t1);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E3738;
    t7 = fn_8860BBD8((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88804AB8: if_call_seq lbl_880E36D0, u32@0x0, u32@0x30, ts4_destroy_owned_object, u32@0x20, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880E36D0_88804AB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E36D0;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x88804B18: call_seq fn_88617D88, lbl_880E36D0, u32@0x0, u32@0x1c, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88804B18(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E36D0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88805AF0: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E369C, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_88805AF0(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E369C, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t4;
}

/* Swing_DLL.xex 0x88805C38: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E366C, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_88805C38(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E366C, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t4;
}

/* Swing_DLL.xex 0x88805C90: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E3674, fn_888368B0, lbl_880E367C */
ts4_word ts4_call_seq_u32_off3c_88805C90(ts4_word a0)
{
    ts4_word loc60[8];
    ts4_word loc50[4];
    ts4_word t5;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3674, (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E367C, (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t5;
}

/* Swing_DLL.xex 0x88805D10: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E3688, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_88805D10(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3688, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t4;
}

/* Swing_DLL.xex 0x88806070: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E3664, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_88806070(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3664, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t4;
}

/* Swing_DLL.xex 0x888061B8: call_seq u32@0x3c, lbl_880E3658, ts4_call_seq_u32_off0_88832F70, lbl_880E365C, fn_888368B0, fn_881B19A0 */
ts4_word ts4_call_seq_u32_off3c_888061B8(ts4_word a0)
{
    ts4_word loc60[10];
    ts4_word loc50[4];
    ts4_word t4;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)), (ts4_word)(ts4_word)lbl_880E3658);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E365C, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t4;
}

/* Swing_DLL.xex 0x88806570: call_seq ts4_call_seq_u32_off0_88832F70, lbl_880E3044, fn_888368B0, lbl_880E302C, fn_888368B0, lbl_880E3038 */
ts4_word ts4_call_seq_fn_88832F70_88806570(ts4_word a0, ts4_word a1)
{
    ts4_word loc60[8];
    ts4_word loc50[4];
    ts4_word loc80[8];
    ts4_word t10;

    ts4_call_seq_u32_off0_88832F70((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)a0);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3044, (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E302C, (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E3038, (ts4_word)(ts4_word)&loc50[0]);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880E38C0, (ts4_word)(ts4_word)&loc50[0]);
    loc80[2] = (ts4_word)0;
    loc80[4] = (ts4_word)0;
    fn_881B18E0((ts4_word)(ts4_word)&loc80[0], (ts4_word)a1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) + 72));
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_888368B0((ts4_word)(ts4_word)&loc80[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    fn_881B19A0((ts4_word)(ts4_word)&loc80[0]);
    t10 = fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
    return t10;
}

/* Swing_DLL.xex 0x888082F8: if_call_seq u32@0x0, u32@0x6c, u32@0x0, fn_88822738, fn_881B1CF0, ts4_if_call_seq_u32_off8_88837608 */
ts4_word ts4_if_call_seq_u32_off0_888082F8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    (void)a0;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = fn_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 == 5) {
        loc50[0] = (ts4_word)t2;
        loc50[1] = (ts4_word)2;
        t5 = fn_881B1CF0((ts4_word)(ts4_word)&loc50[0]);
        if ((ts4_word)(t5 & 0xff) != 0) {
            loc50[0] = (ts4_word)t2;
            loc60[0] = (ts4_word)0;
            loc60[2] = (ts4_word)0;
            loc60[1] = (ts4_word)((983040) | 65535);
            loc50[1] = (ts4_word)1;
            t6 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
            t7 = fn_88806428((ts4_word)t6, (ts4_word)(ts4_word)&loc60[0]);
            if ((ts4_word)(t7 & 0xff) != 0) {
                t9 = fn_88822888((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)2);
                fn_88610620((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)t9);
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88808F58: tailcall fn_88807D48 */
ts4_word ts4_tailcall_fn_88807D48_88808F58(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88807D48((ts4_word)a1);
}

/* Swing_DLL.xex 0x888090C0: tailcall fn_881B2808 */
ts4_word ts4_tailcall_fn_881B2808_888090C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_881B2808((ts4_word)a1);
}

/* Swing_DLL.xex 0x88809178: tailcall fn_881B26C8 */
ts4_word ts4_tailcall_fn_881B26C8_88809178(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_881B26C8((ts4_word)a1);
}

/* Swing_DLL.xex 0x8880A478: if_call_seq u32@0x0, u32@0x6c, u32@0x0, fn_88822738, ts4_if_call_seq_u32_off8_88837608, fn_888063B0 */
ts4_word ts4_if_call_seq_u32_off0_8880A478(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word loc90[8];
    ts4_word loc70[8];
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = fn_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if ((int)t4 != 5) {
        return 0;
    }
    loc50[0] = (ts4_word)t2;
    loc60[0] = (ts4_word)0;
    loc60[2] = (ts4_word)0;
    loc60[1] = (ts4_word)((983040) | 65535);
    loc50[1] = (ts4_word)1;
    t5 = ts4_if_call_seq_u32_off8_88837608((ts4_word)(ts4_word)&loc90[0], (ts4_word)(ts4_word)&loc50[0]);
    t6 = fn_888063B0((ts4_word)t5, (ts4_word)(ts4_word)&loc60[0]);
    if ((ts4_word)(t6 & 0xff) == 0) {
        return 0;
    }
    loc70[0] = (ts4_word)0;
    loc70[1] = (ts4_word)0;
    loc70[6] = (ts4_word)0;
    loc70[2] = (ts4_word)0;
    loc70[4] = (ts4_word)0;
    fn_881B3268((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    ts4_if_call_seq_fn_888380A8_881B2518((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0]);
    ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc70[0]);
    fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    return 1;
}

/* Swing_DLL.xex 0x8880B488: if_call_seq u32@0x0, u32@0x6c, u32@0x0, fn_88822738, u32@0x0, fn_88822888 */
ts4_word ts4_if_call_seq_u32_off0_8880B488(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc60[7];
    ts4_word loc50[1];
    ts4_word t2;
    int t4;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = fn_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if (((int)t4 != 4 && (int)t4 != 3) && (int)t4 != 9) {
        p11 = (ts4_word)0;
    } else {
        loc60[0] = (ts4_word)0;
        loc60[1] = (ts4_word)0;
        loc60[6] = (ts4_word)0;
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        t6 = fn_88822888((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
        fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)t6);
        ts4_if_call_seq_fn_888380A8_881B25F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
        p11 = (ts4_word)1;
    }
    return p11;
}

/* Swing_DLL.xex 0x8880B730: if_call_seq u32@0x0, u32@0x6c, u32@0x0, fn_88822738, u32@0x0, fn_88822888 */
ts4_word ts4_if_call_seq_u32_off0_8880B730(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc60[7];
    ts4_word loc50[1];
    ts4_word t2;
    int t4;
    ts4_word t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108);
    t4 = fn_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
    if (((int)t4 != 4 && (int)t4 != 3) && (int)t4 != 9) {
        p11 = (ts4_word)0;
    } else {
        loc60[0] = (ts4_word)0;
        loc60[1] = (ts4_word)0;
        loc60[6] = (ts4_word)0;
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        t6 = fn_88822888((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 0)), (ts4_word)1);
        fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)t6);
        ts4_if_call_seq_fn_888380A8_881B2518((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
        p11 = (ts4_word)1;
    }
    return p11;
}

/* Swing_DLL.xex 0x88811060: if_call_seq u32@0x10, u8@0x0, lbl_880E2E70, fn_88810408, fn_88810F00 */
ts4_word ts4_if_call_seq_u32_off10_88811060(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word loc50[5];
    ts4_word t1;
    unsigned char t2;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 0);
    if ((int)((signed char)t2) != 64 && (int)((signed char)t2) != 61) {
        p3 = (ts4_word)t1;
        if ((int)((signed char)t2) == 27) {
            p3 = (ts4_word)(ts4_word)lbl_880E2E70;
        }
        loc50[4] = (ts4_word)p3;
    } else {
        loc50[4] = (ts4_word)(t1 + 1);
    }
    loc50[0] = (ts4_word)a0;
    loc50[1] = (ts4_word)a1;
    loc50[2] = (ts4_word)a2;
    fn_88810408((ts4_word)(ts4_word)&loc50[0]);
    t6 = fn_88810F00((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    return t6;
}

/* Swing_DLL.xex 0x88811118: if_get u32@0x14, u32@0x0, u32@0x8, u32@0x10, ts4_loop_get_u8_offd_888114E0, u32@0x8 */
ts4_word ts4_if_get_u32_off14_88811118(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    int t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(((a2 + 34) << 2)) + t1);
    if ((int)t2 != 5) {
        if ((int)t2 != 7) {
            return (((t2 << 4) + t1) + 200);
        }
        return ts4_loop_get_u8_offd_888114E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + 12)), (ts4_word)t3, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)((a2 + 34) << 2), (ts4_word)t1, (ts4_word)a1);
    }
    return ts4_loop_get_u8_offd_888114E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 8))) + 16)), (ts4_word)t3, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)((a2 + 34) << 2), (ts4_word)t1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88811478: loop_get u8@0xd, u32@0x10, u32@0x18, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_loop_get_u8_offd_88811478(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p8;
    unsigned char t1;
    ts4_word t2;
    int t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    lv4 = (ts4_word)((((((1 << t1) + -1) & t2) + ((((1 << t1) + -1) & t2) << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((int)t5 == 9 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 8)) == (ts4_word)a1) {
            return (lv4 + 16);
        }
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 32));
        lv4 = p8;
    } while ((ts4_word)p8 != 0);
    return (ts4_word)lbl_880C9748;
}

/* Swing_DLL.xex 0x88811548: loop_get u8@0xd, u32@0x10, u32@0x18, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_loop_get_u8_offd_88811548(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p8;
    unsigned char t1;
    ts4_word t2;
    int t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    lv4 = (ts4_word)((((((1 << t1) + -1) & t2) + ((((1 << t1) + -1) & t2) << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((int)t5 == 9 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 8)) == (ts4_word)a1) {
            return lv4;
        }
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 32));
        lv4 = p8;
    } while ((ts4_word)p8 != 0);
    return lv4;
}

/* Swing_DLL.xex 0x888115A0: loop_get u8@0xd, u32@0x10, u32@0x18, u32@0x0, u32@0x8, u32@0x20 */
ts4_word ts4_loop_get_u8_offd_888115A0(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p8;
    unsigned char t1;
    ts4_word t2;
    int t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 13);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    lv4 = (ts4_word)((((((1 << t1) + -1) & t2) + ((((1 << t1) + -1) & t2) << 2)) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    do {
        t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((int)t5 == 4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 8)) == (ts4_word)a1) {
            return lv4;
        }
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 32));
        lv4 = p8;
    } while ((ts4_word)p8 != 0);
    return lv4;
}

/* Swing_DLL.xex 0x88813350: if_call_seq fn_889CE718, u32@0x10, u8@0x9, u8@0x8, u16@0xa, u32@0x14 */
ts4_word ts4_if_call_seq_fn_889CE718_88813350(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t9;

    t1 = fn_889CE718((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)(((a1 + 1) & 0xfffffffe) + 24));
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)((a1 + 1) & 0xfffffffe);
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 9) = (unsigned char)2;
    *(volatile unsigned char *)((char *)(ts4_word)(t1) + 8) = (unsigned char)7;
    *(volatile unsigned short *)((char *)(ts4_word)(t1) + 10) = (unsigned short)0;
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 320);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)t3;
    *(volatile unsigned short *)((char *)(ts4_word)(t3) + 10) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(t3) + 10)) + 1);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 24);
    *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 24));
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 24) = (ts4_word)t1;
    t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t9 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)t1;
    }
    return t1;
}

/* Swing_DLL.xex 0x88814388: if_fn  */
ts4_word ts4_if_fn_88814388(int a0)
{
    if ((int)a0 != 45) {
        return ((((a0 + -271) == 0) ^ 1) + 1);
    }
    return 0;
}

/* Swing_DLL.xex 0x888147A0: if_call_seq u32@0x30, u32@0x0, u32@0x30, u32@0x3c, u32@0x1c, u32@0x34 */
ts4_word ts4_if_call_seq_u32_off30_888147A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    int t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 60);
    if ((int)(t3 + 1) > (int)t4) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 28);
        t7 = fn_889CE7D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)t5, (ts4_word)(t2 + 60), (ts4_word)12, (ts4_word)((2147418112) | 65533), (ts4_word)(ts4_word)lbl_880C1320);
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)t7;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    *(ts4_word *)((char *)(ts4_word)(((t9 + (t9 << 1)) << 2)) + (*(ts4_word *)((char *)(ts4_word)(t2) + 28))) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a1) + 10) = (unsigned short)((*(unsigned short *)((char *)(ts4_word)(a1) + 10)) + 1);
    t12 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    *(ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)(t12 + 1);
    return t12;
}

/* Swing_DLL.xex 0x88814F80: if_call_seq u32@0x14, u32@0xc, u32@0x0, u32@0x14, u32@0xc, fn_88814470 */
ts4_word ts4_if_call_seq_u32_off14_88814F80(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    int t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    fn_88814470((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 12)));
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    if ((int)t6 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        fn_888208A8((ts4_word)a0, (ts4_word)((((t7 << 24) | (t7 >> 8)) & 0xff000000) | (37 & 0xffffff)));
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t10;
    t12 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t11;
    t13 = fn_888203F0((ts4_word)a0, (ts4_word)(a0 + 32), (ts4_word)t12);
    return t13;
}

/* Swing_DLL.xex 0x888150D0: if_call_seq u32@0x10, lbl_880E2A14, fn_888195F0, u32@0x18, fn_88814BB8 */
ts4_word ts4_if_call_seq_u32_off10_888150D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    int t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)a0;
    if ((int)t1 != 279) {
        t2 = fn_888195F0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2A14);
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(p3) + 24);
    fn_88814BB8((ts4_word)p3);
    return t4;
}

/* Swing_DLL.xex 0x888154C8: if_call_seq u32@0x10, lbl_880E2A14, fn_888195F0, u32@0x18, fn_88814BB8, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off10_888154C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    int t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)a0;
    if ((int)t1 != 279) {
        t2 = fn_888195F0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2A14);
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    fn_88814BB8((ts4_word)p3);
    ts4_loop_call_seq_fn_88814418_88814950((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)t4, (ts4_word)a1, (ts4_word)1);
    return t4;
}

/* Swing_DLL.xex 0x88815520: if_call_seq u32@0x10, lbl_880E2A14, fn_888195F0, u32@0x18, fn_88814BB8, u32@0x30 */
ts4_word ts4_if_call_seq_u32_off10_88815520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    int t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)a0;
    if ((int)t1 != 279) {
        t2 = fn_888195F0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2A14);
        p3 = (ts4_word)t2;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    fn_88814BB8((ts4_word)p3);
    t7 = fn_88820AF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)t4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t7;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)4;
    return t7;
}

/* Swing_DLL.xex 0x88815860: if_call_seq ts4_call_seq_u32_off34_888145C8, u32@0x40, fn_88815628, lbl_880E2AB8, fn_88814A70, fn_88815428 */
ts4_word ts4_if_call_seq_fn_888145C8_88815860(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word loc50[374];
    ts4_word t2;
    ts4_word t11;

    ts4_call_seq_u32_off34_888145C8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(t2) + 64) = (ts4_word)a3;
    fn_88815628((ts4_word)a0, (ts4_word)40);
    if ((int)a2 != 0) {
        fn_88814A70((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E2AB8);
    }
    fn_88815428((ts4_word)a0);
    fn_88815628((ts4_word)a0, (ts4_word)41);
    fn_88817818((ts4_word)a0);
    fn_88815580((ts4_word)a0, (ts4_word)263, (ts4_word)266, (ts4_word)a3);
    fn_88814D20((ts4_word)a0);
    t11 = fn_88814E68((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    return t11;
}

/* Swing_DLL.xex 0x88815A40: if_call_seq u32@0x0, fn_888214B0, u32@0x20, u32@0x0, u32@0x14, u32@0x1c */
ts4_word ts4_if_call_seq_u32_off0_88815A40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word p13;
    int t1;
    ts4_word t2;
    int t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p13 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t2 = fn_888214B0((ts4_word)a0, (ts4_word)a1);
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        p11 = (ts4_word)t2;
        if ((int)t3 == 32) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
            t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
            t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
            t7 = fn_888208A8((ts4_word)a0, (ts4_word)((((((t6 << 18) | (t5 + -1)) << 6) | (((t6 << 18) | (t5 + -1)) >> 26)) & 0xffffffc0) | (35 & 0x3f)));
            t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
            *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 4)) + 1);
            p11 = (ts4_word)t7;
        }
        p13 = (ts4_word)p11;
    }
    return p13;
}

/* Swing_DLL.xex 0x88815F80: if_call_seq fn_88814BB8, fn_88816C30, u32@0xc, u32@0x10, u32@0x30, fn_88820C30 */
ts4_word ts4_if_call_seq_fn_88814BB8_88815F80(ts4_word a0, ts4_word a1)
{
    int t3;
    int t4;
    ts4_word t5;
    ts4_word t9;

    fn_88814BB8((ts4_word)a0);
    fn_88816C30((ts4_word)a0, (ts4_word)a1, (ts4_word)-1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t3 != (int)t4) {
        fn_888216D0((ts4_word)t5, (ts4_word)a1);
    } else {
        fn_88820C30((ts4_word)t5, (ts4_word)a1);
    }
    t9 = fn_88815628((ts4_word)a0, (ts4_word)93);
    return t9;
}

/* Swing_DLL.xex 0x88816D58: call_seq fn_88816C30, u32@0x30, fn_888214B0 */
ts4_word ts4_call_seq_fn_88816C30_88816D58(ts4_word a0)
{
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t3;

    fn_88816C30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)-1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t3 = loc50[0];
    fn_888214B0((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x88817030: if_call_seq fn_88816C30, u32@0x0, u32@0x0, u32@0x30, fn_88821618, u32@0x30 */
ts4_word ts4_if_call_seq_fn_88816C30_88817030(ts4_word a0, ts4_word a1)
{
    int t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    fn_88816C30((ts4_word)a0, (ts4_word)a1, (ts4_word)-1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t2 == 1) {
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)3;
    }
    fn_88821618((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)a1);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(t6) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 24));
    t9 = fn_888203F0((ts4_word)t6, (ts4_word)(t6 + 32), (ts4_word)t7);
    return t9;
}

/* Swing_DLL.xex 0x888182A8: if_addr lbl_880C9758, u8@-0x1, lbl_880C9758, u8@-0x1, lbl_880C9758, u8@-0x1 */
ts4_word ts4_if_addr_lbl_880C9758_888182A8(ts4_word a0)
{
    if ((ts4_word)a0 >= (ts4_word)(65536)) {
        if ((ts4_word)a0 >= (ts4_word)(16777216)) {
            return ((*(unsigned char *)((char *)(ts4_word)((((a0) >> 24) + (ts4_word)lbl_880C9758)) + -1)) + 24);
        }
        return ((*(unsigned char *)((char *)(ts4_word)((((a0 >> 16) & 0xff) + (ts4_word)lbl_880C9758)) + -1)) + 16);
    }
    if ((ts4_word)a0 >= 256) {
        return ((*(unsigned char *)((char *)(ts4_word)((((a0 >> 8) & 0xff) + (ts4_word)lbl_880C9758)) + -1)) + 8);
    }
    if ((ts4_word)a0 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)(((a0 & 0xff) + (ts4_word)lbl_880C9758)) + -1));
    }
    return -1;
}

/* Swing_DLL.xex 0x8881CB90: call_seq u32@0x30, fn_8881C828, u32@0x30, u32@0x10, fn_8881C8B8 */
ts4_word ts4_call_seq_u32_off30_8881CB90(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t5;

    loc50[0] = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 48));
    fn_8881C828((ts4_word)(ts4_word)&loc50[0], (ts4_word)4, (ts4_word)a1);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    t5 = fn_8881C8B8((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)t3, (ts4_word)4, (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x8881D2B0: if_get u32@0x24, u32@0x20, u16@0x30, u32@0x1c, u32@0x18, u32@0x2c */
ts4_word ts4_if_get_u32_off24_8881D2B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    unsigned short t3;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 48);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(((t1 << 4) + t2) + -16);
    if ((ts4_word)t3 <= 4096) {
        return a0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((int)(((int)(t6 - t7) / (int)24) + 1) >= 4096) {
        return a0;
    }
    return fn_8881D170((ts4_word)a0, (ts4_word)4096);
}

/* Swing_DLL.xex 0x8881D588: if_get u32@0x24, fn_8881D478, fn_8881D478 */
ts4_word ts4_if_get_u32_off24_8881D588(ts4_word a0, int a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)a1 <= (int)t1) {
        return fn_8881D478((ts4_word)a0, (ts4_word)(t1 << 1));
    }
    return fn_8881D478((ts4_word)a0, (ts4_word)((t1 + a1) + 5));
}

/* Swing_DLL.xex 0x8881EC98: if_get u8@0x4b, u32@0x2c */
ts4_word ts4_if_get_u8_off4b_8881EC98(ts4_word a0, int a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 75);
    if ((int)a1 >= (int)t1) {
        if ((int)a1 < 250 || (int)(a1 + -250) >= (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 44))) {
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x8881ED20: if_get u8@0x4b, u32@0x34, u32@0x30, u32@0x34, u32@0x30, u32@0x10 */
ts4_word ts4_if_get_u8_off4b_8881ED20(ts4_word a0)
{
    unsigned char t1;
    int t4;
    int t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 75);
    if ((ts4_word)t1 > 250) {
        return 0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t4 != (int)t5 && (int)t4 != 0) {
        return 0;
    }
    return ((((*(ts4_word *)((char *)(ts4_word)(((t5 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 16)))) + -4)) & 0x3f) + -31) == 0);
}

/* Swing_DLL.xex 0x8881EE28: if_get u32@0x8, u8@0xc, u32@0x14, u32@0x24, u32@0x10, u32@0x14 */
ts4_word ts4_if_get_u32_off8_8881EE28(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    unsigned char t2;
    int t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 12);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_880E25A0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)lbl_880E25A8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 20))) + 36)) + 24);
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 20))) + 64);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
        if ((int)t6 == 0) {
            p7 = (ts4_word)(ts4_word)lbl_880E25AC;
        } else {
            p7 = (ts4_word)(ts4_word)lbl_880E25B4;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p7;
    }
    return fn_88817F88((ts4_word)(a0 + 32), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Swing_DLL.xex 0x8881EEA8: if_get u32@0x8, u32@0x0, u32@-0x8, u32@0x14 */
ts4_word ts4_if_get_u32_off8_8881EEA8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)(t1 & 0x1) == 0) {
        return (*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + -8))) + 20));
    }
    return 0;
}

/* Swing_DLL.xex 0x8881EFB8: if_get u32@0x8, u32@0x10, u32@0x0, u32@0xc, u32@0x0, u32@0xc */
ts4_word ts4_if_get_u32_off8_8881EFB8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)(t1 & 0x1) != 0) {
        return -1;
    }
    if ((int)(t1 & 0x2) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 0));
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return (((int)(t7 - (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + -8))) + 20))) + 16))) >> 2) + -1);
}

/* Swing_DLL.xex 0x8881F450: loop_get u32@0x18, u32@0x2c, u32@0x8, u32@0x10, u32@0x0, u32@0xc */
void ts4_loop_get_u32_off18_8881F450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)t1;
        do {
            t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 8);
            if ((int)(t4 & 0x1) == 0 && (int)(t4 & 0x2) != 0) {
                *(ts4_word *)((char *)(ts4_word)(lv3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 16))) + 0));
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            p9 = (ts4_word)(lv3 + -24);
            lv3 = p9;
        } while ((ts4_word)p9 != (ts4_word)t8);
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 54) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8881F8E0: if_get u32@0x0, lbl_880E2654, fn_8881F6D8 */
ts4_word ts4_if_get_u32_off0_8881F8E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    p2 = (ts4_word)a1;
    if ((int)t1 == 4) {
        p2 = (ts4_word)a2;
    }
    return fn_8881F6D8((ts4_word)a0, (ts4_word)p2, (ts4_word)(ts4_word)lbl_880E2654);
}

/* Swing_DLL.xex 0x88820148: if_get u32@0x0, u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_88820148(ts4_word a0, int a1)
{
    ts4_word p2;

    p2 = (ts4_word)a1;
    if ((int)a1 == 255) {
        p2 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) >> 15) & 0x1ff);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((p2 << 24) | (p2 >> 8)) & 0xff000000) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xffffff));
    return;
}

/* Swing_DLL.xex 0x88820240: if_get u32@0x0, u32@0x4, u32@0x34, u32@0x4, u32@0x34, u32@0x24 */
void ts4_if_get_u32_off0_88820240(ts4_word a0, ts4_word a1)
{
    int t1;
    int t4;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 11) {
        return;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t4 < (int)t5) {
        return;
    }
    if ((int)t4 >= 250) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + -1);
    return;
}

/* Swing_DLL.xex 0x88820318: if_get u32@0x0, u32@0x24, u8@0x4b, u8@0x4b, u32@0xc, lbl_880E2550 */
ts4_word ts4_if_get_u32_off0_88820318(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t3 = *(unsigned char *)((char *)(ts4_word)(t1) + 75);
    if ((int)(t2 + a1) <= (int)t3) {
        return a0;
    }
    if ((int)(t2 + a1) >= 250) {
        return fn_888195F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)(ts4_word)lbl_880E2550, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)t3, (ts4_word)t1);
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 75) = (unsigned char)(t2 + a1);
    return a0;
}

/* Swing_DLL.xex 0x88820748: if_get u32@0x18, fn_88820468, u32@0x1c, fn_888203F0 */
ts4_word ts4_if_get_u32_off18_88820748(ts4_word a0, ts4_word a1, int a2)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((int)a2 == (int)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        return fn_888203F0((ts4_word)a0, (ts4_word)(a0 + 32), (ts4_word)a1);
    }
    return fn_88820468((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)255, (ts4_word)a2, (ts4_word)255, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88820BD0: tailcall fn_888208A8 */
ts4_word ts4_tailcall_fn_888208A8_88820BD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_888208A8((ts4_word)a0, (ts4_word)((((a2 << 18) | a3) << 6) | a1));
}

/* Swing_DLL.xex 0x88820BE8: tailcall fn_888208A8 */
ts4_word ts4_tailcall_fn_888208A8_88820BE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_888208A8((ts4_word)a0, (ts4_word)((((((a2 << 9) | a3) << 9) | a4) << 6) | a1));
}

/* Swing_DLL.xex 0x88820C08: get u32@0x18, u32@0x1c, fn_888208A8 */
ts4_word ts4_get_u32_off18_88820C08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    return fn_888208A8((ts4_word)a0, (ts4_word)((((((((a1 << 9) | a2) << 9) | a3) << 6) | (((((a1 << 9) | a2) << 9) | a3) >> 26)) & 0xffffffc0) | (2 & 0x3f)), (ts4_word)a2, (ts4_word)a3, (ts4_word)((((a1 << 9) | a2) << 9) | a3), (ts4_word)(((a1 << 9) | a2) << 9), (ts4_word)((a1 << 9) | a2), (ts4_word)(a1 << 9));
}

/* Swing_DLL.xex 0x88821758: if_get u32@0xc, u32@0x10, fn_88820C30, fn_888216D0 */
ts4_word ts4_if_get_u32_offc_88821758(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;
    int t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((int)t1 != (int)t2) {
        return fn_888216D0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    }
    return fn_88820C30((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x88821BC8: if_call_seq fn_888214B0, fn_88821618, u32@0x18, u32@0xc, u32@0x1c, fn_888203F0 */
ts4_word ts4_if_call_seq_fn_888214B0_88821BC8(ts4_word a0, int a1, ts4_word a2)
{
    ts4_word p11;
    ts4_word p12;
    ts4_word p13;
    ts4_word t10;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t1;

    if ((int)a1 != 9) {
        if ((int)a1 != 16) {
            if ((int)a1 != 17) {
                t10 = fn_88821878((ts4_word)a0, (ts4_word)a2);
                p11 = (ts4_word)t10;
            } else {
                fn_88821568((ts4_word)a0, (ts4_word)a2);
                t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
                t8 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
                *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t7;
                t9 = fn_888203F0((ts4_word)a0, (ts4_word)(a0 + 32), (ts4_word)t8);
                *(ts4_word *)((char *)(ts4_word)(a2) + 16) = (ts4_word)-1;
                p11 = (ts4_word)t9;
            }
            p12 = (ts4_word)p11;
        } else {
            fn_88821618((ts4_word)a0, (ts4_word)a2);
            t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
            t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t3;
            t5 = fn_888203F0((ts4_word)a0, (ts4_word)(a0 + 32), (ts4_word)t4);
            *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)-1;
            p12 = (ts4_word)t5;
        }
        p13 = (ts4_word)p12;
    } else {
        t1 = fn_888214B0((ts4_word)a0, (ts4_word)a2);
        p13 = (ts4_word)t1;
    }
    return p13;
}

/* Swing_DLL.xex 0x88822128: if_get u32@0x10, u32@0x0, u32@0x8, u8@0xc, u32@0x8, u8@0xc */
ts4_word ts4_if_get_u32_off10_88822128(ts4_word a0, int a1, ts4_word a2)
{
    ts4_word t1;
    int t2;
    ts4_word t5;
    unsigned char t6;
    unsigned char t16;
    ts4_word t10;
    int t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 != 6) {
        return 0;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t6 = *(unsigned char *)((char *)(ts4_word)(t5) + 12);
    if ((ts4_word)t6 != 0) {
        t16 = *(unsigned char *)((char *)(ts4_word)(t5) + 13);
        if ((int)a1 > (int)t16) {
            return 0;
        }
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(((a1 << 4) + t5) + 8);
        return (ts4_word)lbl_880C1320;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t5) + 20);
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 40);
    if ((int)a1 > (int)t11) {
        return 0;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 32);
    t13 = *(ts4_word *)((char *)(ts4_word)(((a1 + 9) << 2)) + t5);
    t14 = *(ts4_word *)((char *)(ts4_word)((t12 + (a1 << 2))) + -4);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t13) + 12));
    return (t14 + 24);
}

/* Swing_DLL.xex 0x88825370: if_get u8@0x0, u8@0x1, ts4_match_class_88824F38, fn_88825118 */
ts4_word ts4_if_get_u8_off0_88825370(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 37) {
        if ((ts4_word)t1 != 46) {
            if ((ts4_word)t1 != 91) {
                return ((a0 - t1) == 0);
            }
            return fn_88825118((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 + -1));
        }
        return 1;
    }
    return ts4_match_class_88824F38((ts4_word)a0, (ts4_word)((signed char)(*(unsigned char *)((char *)(ts4_word)(a1) + 1))));
}

/* Swing_DLL.xex 0x8882A370: if_call_seq fn_88829550, fn_8882DE88, fn_88822DB0 */
ts4_word ts4_if_call_seq_fn_88829550_8882A370(ts4_word a0)
{
    ts4_word loc50[134];
    int t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_88829550((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)1);
    if ((int)t1 == 0) {
        return t1;
    }
    fn_8882DE88((ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[1];
    t4 = loc50[3];
    fn_88822DB0((ts4_word)t4, (ts4_word)t3);
    return 1;
}

/* Swing_DLL.xex 0x8882B3A0: get u32@0xc, u32@0x10, fn_8881E350 */
ts4_word ts4_get_u32_offc_8882B3A0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return fn_8881E350((ts4_word)a0, (ts4_word)((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 16))) >> 4));
}

/* Swing_DLL.xex 0x8882C7E0: if_call_seq u32@0x10, u32@0xc, u32@0x0, lbl_880E1C98, fn_8882E6B8, fn_88823768 */
ts4_word ts4_if_call_seq_u32_off10_8882C7E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    int t6;
    int t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if (((ts4_word)t1 >= (ts4_word)t2 || (ts4_word)t1 == 0) || (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)) == -1) {
        fn_8882E6B8((ts4_word)a0, (ts4_word)1, (ts4_word)(ts4_word)lbl_880E1C98);
    }
    t6 = fn_88823768((ts4_word)a0, (ts4_word)1);
    if ((int)t6 == 0) {
        fn_88824188((ts4_word)a0);
    } else {
        t7 = fn_88823768((ts4_word)a0, (ts4_word)1);
        if ((int)t7 != 0) {
            fn_8882E218((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1E54);
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x8882CD48: if_call_seq u32@0x10, u32@0xc, u32@0x0, lbl_880C9684, u32@0x14, fn_8882E950 */
ts4_word ts4_if_call_seq_u32_off10_8882CD48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if (((ts4_word)t1 >= (ts4_word)t2 || (ts4_word)t1 == 0) || (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)) != 5) {
        fn_8882E950((ts4_word)a0, (ts4_word)1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_880C9684) + 20)));
    }
    fn_88823FC0((ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1F70, (ts4_word)4);
    fn_88823AE8((ts4_word)a0, (ts4_word)-10001);
    fn_88824248((ts4_word)a0, (ts4_word)1);
    fn_88824188((ts4_word)a0);
    return 3;
}

/* Swing_DLL.xex 0x8882CDE8: if_call_seq u32@0x10, u32@0xc, u32@0x0, lbl_880C9684, u32@0x14, fn_8882E950 */
ts4_word ts4_if_call_seq_u32_off10_8882CDE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    int t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if (((ts4_word)t1 >= (ts4_word)t2 || (ts4_word)t1 == 0) || (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)) != 5) {
        fn_8882E950((ts4_word)a0, (ts4_word)1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_880C9684) + 20)));
    }
    fn_888246A8((ts4_word)a0, (ts4_word)2);
    t8 = fn_88824B68((ts4_word)a0);
    if ((int)t8 != 0) {
        return 2;
    }
    fn_88824188((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x8882E4E0: call_seq fn_8882DE88, u32@0x4, u32@0xc, fn_88822DB0, u32@0x4 */
ts4_word ts4_call_seq_fn_8882DE88_8882E4E0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    fn_8882DE88((ts4_word)a0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = fn_88822DB0((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return t4;
}

/* Swing_DLL.xex 0x8882F440: if_get u16@0x0, u16@0x2, ts4_match_flag_char_8882EED0, fn_8882F1E8 */
ts4_word ts4_if_get_u16_off0_8882F440(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 37) {
        if ((ts4_word)t1 != 46) {
            if ((ts4_word)t1 != 91) {
                return (((a0 & 0xffff) - t1) == 0);
            }
            return fn_8882F1E8((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 + -2));
        }
        return 1;
    }
    return ts4_match_flag_char_8882EED0((ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 2)));
}

/* Swing_DLL.xex 0x88832760: if_call_seq fn_888319E0, fn_8882DE88, fn_88822DB0 */
ts4_word ts4_if_call_seq_fn_888319E0_88832760(ts4_word a0)
{
    ts4_word loc50[134];
    int t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_888319E0((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    if ((int)t1 == 0) {
        return t1;
    }
    fn_8882DE88((ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[1];
    t4 = loc50[3];
    fn_88822DB0((ts4_word)t4, (ts4_word)t3);
    return 1;
}

/* Swing_DLL.xex 0x88835240: if_get u32@0x14, u32@0x0, u32@0x14, u32@0x10, u32@0xc, fn_881B19A0 */
ts4_word ts4_if_get_u32_off14_88835240(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p13;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20);
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
        t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
        fn_881B19A0((ts4_word)t1);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t5))((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)32, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p13 = (ts4_word)t10;
    if ((ts4_word)t10 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 24)) != 0) {
        t12 = fn_88813BA8((ts4_word)t10);
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x888363D0: set u32@0x18, u32@0x4, u32@0x0, u32@0x4, u32@0x0, u32@0x4 */
void ts4_set_u32_off18_888363D0(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4) = (ts4_word)a0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a1 + 4);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88837B98: get u32@0x18, u32@0x10, u32@0x0, fn_88811318 */
ts4_word ts4_get_u32_off18_88837B98(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    return fn_88811318((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)(a0 + 8), (ts4_word)t2);
}

/* Swing_DLL.xex 0x88838428: get u32@0x1c, u32@-0x2c, u32@0x0 */
void ts4_get_u32_off1c_88838428(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((((int)a2 * 44) + (*(ts4_word *)((char *)(ts4_word)(a1) + 28)))) + -44));
    return;
}

/* Swing_DLL.xex 0x8883B138: loop_get u32@0x4, u32@0xc, u32@0x0, u32@0x4c, vcall, u32@0x0 */
ts4_word ts4_loop_get_u32_off4_8883B138(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word lv10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t5;
    int t6;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 12);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 76))))((ts4_word)t2, (ts4_word)0);
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
    p8 = (ts4_word)0;
    if ((int)t6 != -1) {
        p8 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(t5) + 4)) * 660) + t6) + t5);
    }
    p9 = (ts4_word)0;
    if ((int)t6 != -1) {
        p9 = (ts4_word)(t6 + t5);
    }
    lv10 = (ts4_word)p9;
    while ((ts4_word)lv10 != (ts4_word)p8) {
        *(unsigned char *)((char *)(ts4_word)(lv10) + 644) = (unsigned char)0;
        p11 = (ts4_word)(lv10 + 660);
        lv10 = p11;
    }
    *(unsigned char *)((char *)(ts4_word)(((((int)a1 * 660) + (*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + t5)) + 644) = (unsigned char)1;
    return t5;
}

/* Swing_DLL.xex 0x8883B290: set u32@0x8, u32@0xc, u32@0x10, u32@0x18, u32@0x14, fn_881AD8E0 */
ts4_word ts4_set_u32_off8_8883B290(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return fn_881AD8E0((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x8883CE20: if_call_seq lbl_880E16A4, u32@0x0, u32@0x1c, ts4_destroy_owned_object, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880E16A4_8883CE20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = fn_8860BBD8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8883D798: call_seq fn_88617D88, lbl_880E16AC, u32@0x0, u32@0x20, u32@0x24, u32@0x1c */
ts4_word ts4_call_seq_fn_88617D88_8883D798(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E16AC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88841758: if_call_seq lbl_880E167C, u32@0x0, u32@0x20, ts4_destroy_owned_object, ts4_if_call_seq_lbl_880F7EE4_88617D28 */
ts4_word ts4_if_call_seq_lbl_880E167C_88841758(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
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
    t4 = ts4_if_call_seq_lbl_880F7EE4_88617D28((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888417A8: call_seq fn_88617D88, lbl_880E167C, u32@0x0, u32@0x20, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_888417A8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E167C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88841BC8: if_call_seq u32@0x1c, u32@0x34, u32@0x0, u32@0x1c, fn_881AD020, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off1c_88841BC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t2;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 52);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    if ((ts4_word)t2 == (ts4_word)((3751936000) | 45041)) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((3751936000) | 45041);
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        return a0;
    }
    t4 = fn_881AD020((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)), (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 16));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 20));
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 24));
    return t4;
}

/* Swing_DLL.xex 0x88841C40: loop_get u32@0x0, u32@0x4, u32@0x0, u32@0x4, u8@0xf0 */
void ts4_loop_get_u32_off0_88841C40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p6;
    ts4_word lv7;
    ts4_word p11;
    ts4_word p12;
    ts4_word lv13;
    ts4_word p14;
    ts4_word p16;
    int t1;
    ts4_word t2;
    int t8;

    (void)a1;
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
        p4 = (ts4_word)((((t2 + (t2 << 3)) << 2) + t1) + a0);
    }
    p6 = (ts4_word)0;
    if ((int)t1 != -1) {
        p6 = (ts4_word)(t1 + a0);
    }
    if ((ts4_word)p6 == (ts4_word)p4) {
        return;
    }
    lv7 = (ts4_word)p6;
    do {
        t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
        p11 = (ts4_word)0;
        if ((int)t8 != -1) {
            p11 = (ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(lv7) + 4)) * 244) + t8) + lv7);
        }
        p12 = (ts4_word)0;
        if ((int)t8 != -1) {
            p12 = (ts4_word)(t8 + lv7);
        }
        lv13 = (ts4_word)p12;
        while ((ts4_word)lv13 != (ts4_word)p11) {
            *(unsigned char *)((char *)(ts4_word)(lv13) + 240) = (unsigned char)0;
            p14 = (ts4_word)(lv13 + 244);
            lv13 = p14;
        }
        p16 = (ts4_word)(lv7 + 36);
        lv7 = p16;
    } while ((ts4_word)p16 != (ts4_word)p4);
    return;
}

/* Swing_DLL.xex 0x88842938: if_call_seq ts4_member_field_addr_8883B578, u32@0x8, fn_8883DDA0, fn_8883DDA0 */
ts4_word ts4_if_call_seq_fn_8883B578_88842938(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = ts4_member_field_addr_8883B578((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    if ((ts4_word)a2 == (ts4_word)((3354329088) | 46281) || (ts4_word)a2 == (ts4_word)((3061645312) | 4295)) {
        if ((ts4_word)t2 == (ts4_word)((1963655168) | 23056) || (ts4_word)t2 == (ts4_word)((1541931008) | 38447)) {
            t3 = fn_8883DDA0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
            return t3;
        }
        return 0;
    }
    if ((ts4_word)a2 != (ts4_word)((1038090240) | 35242) && (ts4_word)a2 != (ts4_word)((1282539520) | 11684)) {
        return 0;
    }
    if ((ts4_word)t2 == (ts4_word)((3663003648) | 18518) || (ts4_word)t2 == (ts4_word)((1541931008) | 38447)) {
        t4 = fn_8883DDA0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        return t4;
    }
    return 0;
}

/* Swing_DLL.xex 0x888455A8: call_seq u32@0x0, u32@0x6c, u32@0x0, fn_88822398, u32@lbl_88D459E8, fn_88843650 */
ts4_word ts4_call_seq_u32_off0_888455A8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    (void)a0;
    t4 = fn_88822398((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0))) + 108))) + 0)), (ts4_word)1);
    fn_88843650((ts4_word)(*(volatile ts4_word *)lbl_88D459E8), (ts4_word)(t4 != 0));
    return 0;
}

/* Swing_DLL.xex 0x88848698: if_get ts4_if_call_seq_u32_lbl_88D459E4_8883F238, u32@0x8c, u32@0x0, u32@0x4c, vcall, u32@0xc */
ts4_word ts4_if_get_fn_8883F238_88848698(ts4_word a0, ts4_word a1)
{
    ts4_word p23;
    ts4_word loc60[132];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;
    ts4_word t11;
    ts4_word t13;
    ts4_word t14;
    ts4_word t19;
    ts4_word t22;

    t1 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    p23 = (ts4_word)t1;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 76))))((ts4_word)t2, (ts4_word)0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 12);
        fn_881A50F0((ts4_word)(ts4_word)&loc60[0]);
        fn_888429E8((ts4_word)t6, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 388)), (ts4_word)(ts4_word)&loc60[0]);
        t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t11 = loc60[0];
        t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t10) + 68))))((ts4_word)t1, (ts4_word)t11);
        if ((ts4_word)(t13 & 0xff) == 1) {
            t14 = loc60[0];
            ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)t14);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
            t19 = loc50[0];
            ts4_destroy_owned_object((ts4_word)t19);
        }
        *(ts4_word *)((char *)(ts4_word)(t5) + 4676) = (ts4_word)((4063100928) | 3261);
        t22 = fn_889254C8((ts4_word)(a0 + 128), (ts4_word)1);
        p23 = (ts4_word)t22;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)((3751936000) | 45041);
    if ((ts4_word)(a1 & 0xff) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 384)) + 1);
    }
    return p23;
}

/* Swing_DLL.xex 0x8884EF00: if_call_seq fn_88838B00, fn_88838B00, fn_8884C160, fn_8884C160 */
ts4_word ts4_if_call_seq_fn_88838B00_8884EF00(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word p6;
    ts4_word t1;
    ts4_word t5;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88838B00((ts4_word)a0, (ts4_word)a1, (ts4_word)((3168534528) | 46373));
    if ((ts4_word)(t1 & 0xff) != 0) {
        t5 = fn_8884C160((ts4_word)a0, (ts4_word)((3168534528) | 46373), (ts4_word)((2919956480) | 47525));
        p6 = (ts4_word)t5;
    } else {
        t2 = fn_88838B00((ts4_word)a0, (ts4_word)a1, (ts4_word)((89915392) | 12938));
        if ((ts4_word)(t2 & 0xff) != 0) {
            t3 = fn_8884C160((ts4_word)a0, (ts4_word)((89915392) | 12938), (ts4_word)((2919956480) | 47525));
            p4 = (ts4_word)t3;
        } else {
            p4 = (ts4_word)0;
        }
        p6 = (ts4_word)p4;
    }
    return p6;
}

/* Swing_DLL.xex 0x8884F748: call_seq lbl_880E13F8, fn_88867E68, fn_8816CAA0 */
ts4_word ts4_call_seq_lbl_880E13F8_8884F748(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[128];
    ts4_word t2;

    fn_88867E68((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880E13F8);
    t2 = fn_8816CAA0((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8884F790: call_seq lbl_880E13EC, fn_88867E68, fn_8816CAA0 */
ts4_word ts4_call_seq_lbl_880E13EC_8884F790(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[128];
    ts4_word t2;

    fn_88867E68((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880E13EC);
    t2 = fn_8816CAA0((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8884F7D8: call_seq lbl_880E13DC, fn_88867E68, fn_8816CAA0 */
ts4_word ts4_call_seq_lbl_880E13DC_8884F7D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[128];
    ts4_word t2;

    fn_88867E68((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)512, (ts4_word)(ts4_word)lbl_880E13DC);
    t2 = fn_8816CAA0((ts4_word)a2, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}
