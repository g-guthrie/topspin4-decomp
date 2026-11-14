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
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char g_ts4_session_context[];
extern char lbl_880C1320[];
extern char lbl_880D382C[];
extern char lbl_880D3DF8[];
extern char lbl_880D3E20[];
extern char lbl_880D3E40[];
extern char lbl_880D3E68[];
extern char lbl_88D458D0[];
extern char lbl_88D459D0[];
extern char lbl_88D45A60[];
extern char lbl_88D45B38[];
extern char lbl_88D45BB8[];
ts4_word fn_88159870();
ts4_word fn_881599B8();
ts4_word fn_88161540();
ts4_word fn_88608590();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D5B8();
ts4_word fn_88627EC0();
ts4_word fn_8862C0E8();
ts4_word ts4_call_seq_u32_off8_8869FD88();
ts4_word fn_8877D388();
ts4_word ts4_if_call_seq_u32_off50_88793A78();
ts4_word ts4_if_call_seq_u32_off70_88793D30();
ts4_word fn_8886A0A0();
ts4_word fn_88923530();
ts4_word fn_8892DA08();
ts4_word fn_8892DC70();
ts4_word fn_88931388();
ts4_word fn_88931EF0();
ts4_word fn_8893AD90();
ts4_word fn_8893CFD8();
ts4_word fn_88940B18();
ts4_word fn_88941B30();
ts4_word fn_88943AA0();
ts4_word fn_88943B70();
ts4_word fn_8894F188();
ts4_word fn_88950808();
ts4_word ts4_call_seq_ts4_assign_formatted_text_8895BDD8();
ts4_word fn_8895F308();
ts4_word fn_8895F6C8();
ts4_word fn_8897CD88();
ts4_word fn_88980358();
ts4_word fn_8898F450();
ts4_word fn_889913B0(ts4_word, ts4_word, ts4_word, ts4_word, float, ts4_word);
ts4_word fn_88991DA8();
ts4_word fn_88995AB8();
ts4_word fn_889B0E98();
ts4_word fn_889B1D68();
ts4_word fn_889B76D0();
ts4_word ts4_call_seq_lbl_880F7AEC_8860D648();
ts4_word ts4_concat3_881642B0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();

/* Swing_DLL.xex 0x886A7550: loop_call_seq u32@0xc, u32@0x8, u32@0x48, ts4_call_seq_u32_off8_8869FD88 */
void ts4_loop_call_seq_u32_offc_886A7550(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p8;
    int t1;
    ts4_word t2;
    int t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        lv4 = (ts4_word)t2;
        while ((ts4_word)lv4 < (ts4_word)((t2 + t1) + -1)) {
            t5 = *(ts4_word *)((char *)(ts4_word)((((int)((ts4_word)lv4 % 10) * 1052) + a0)) + 72);
            if ((int)t5 != 0) {
                break;
            }
            ts4_call_seq_u32_off8_8869FD88((ts4_word)a0);
            p8 = (ts4_word)(lv4 + 1);
            lv4 = p8;
        }
    }
    return;
}

/* Swing_DLL.xex 0x887957B8: if_call_seq u32@0x110, u32@lbl_88D45A60, u32@0x1e4, ts4_if_call_seq_u32_off50_88793A78, u32@0x110, u32@0x110 */
ts4_word ts4_if_call_seq_u32_off110_887957B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    if ((ts4_word)t1 == 0) {
        t4 = ts4_if_call_seq_u32_off50_88793A78((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45A60)) + 484)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(t4 + 448);
    }
    return ((((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 272))) + 0)) - 375128064) + 16919) == 0);
}

/* Swing_DLL.xex 0x887961A0: if_call_seq u32@0x70, ts4_if_call_seq_u32_off70_88793D30, u8@0x75, u8@0x74, u8@0x74, u8@0x74 */
void ts4_if_call_seq_u32_off70_887961A0(ts4_word a0, int a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t9;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)(0xff & a2) != 0 || (ts4_word)a1 != (ts4_word)t1) {
        ts4_if_call_seq_u32_off70_88793D30((ts4_word)a0, (ts4_word)a1);
        if ((ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 117)) != 1) {
            if ((ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 116)) != 1) {
                t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72);
                if (!((int)t7 != 0)) {
                    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)1;
                } else {
                    t9 = fn_8877D388((ts4_word)t7, (ts4_word)a1, (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 130)));
                    if ((ts4_word)(t9 & 0xff) == 0) {
                        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)1;
                    }
                }
            }
        } else {
            *(volatile unsigned char *)((char *)(ts4_word)(a0) + 116) = (unsigned char)1;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8892DE20: if_get u32@0x0, u32@lbl_88D45B38, fn_88161540, u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D5B8, ts4_call_seq_lbl_880F7AEC_8860D648 */
ts4_word ts4_if_get_u32_off0_8892DE20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word loc50[6];
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t14;
    ts4_word t16;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != -1) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t5 = ts4_if_call_seq_fn_88883CD0_8860D5B8();
            p7 = (ts4_word)t5;
        } else {
            p7 = (ts4_word)0;
        }
        ts4_call_seq_lbl_880F7AEC_8860D648((ts4_word)(ts4_word)&loc50[0], (ts4_word)p7);
        t9 = loc50[0];
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t9) + 4))))((ts4_word)(ts4_word)&loc50[0]);
        fn_8892DA08((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        t14 = loc50[0];
        t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 8))))((ts4_word)(ts4_word)&loc50[0]);
        return t16;
    }
    t3 = fn_88161540((ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x8892E198: if_get u32@0x0, u32@lbl_88D45B38, fn_88161540, u32@lbl_88D45B38, ts4_if_call_seq_fn_88883CD0_8860D5B8, ts4_call_seq_lbl_880F7AEC_8860D648 */
ts4_word ts4_if_get_u32_off0_8892E198(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word loc50[6];
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t14;
    ts4_word t16;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != -1) {
        t4 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t4 != 0) {
            t5 = ts4_if_call_seq_fn_88883CD0_8860D5B8();
            p7 = (ts4_word)t5;
        } else {
            p7 = (ts4_word)0;
        }
        ts4_call_seq_lbl_880F7AEC_8860D648((ts4_word)(ts4_word)&loc50[0], (ts4_word)p7);
        t9 = loc50[0];
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t9) + 4))))((ts4_word)(ts4_word)&loc50[0]);
        fn_8892DA08((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        t14 = loc50[0];
        t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 8))))((ts4_word)(ts4_word)&loc50[0]);
        return t16;
    }
    t3 = fn_88161540((ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x88951178: loop_call_seq u32@0x0, u32@0x4, lbl_880D382C, u32@0x24, u32@0x0, ts4_concat3_881642B0 */
ts4_word ts4_loop_call_seq_u32_off0_88951178(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p9;
    ts4_word p11;
    ts4_word p12;
    ts4_word p14;
    ts4_word loc60[26];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    int t5;
    ts4_word t8;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p14 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t2) {
        lv3 = (ts4_word)a0;
        lv4 = (ts4_word)t1;
        do {
            t5 = *(ts4_word *)((char *)(ts4_word)(lv4) + 36);
            p9 = (ts4_word)lv3;
            if ((int)t5 == 4) {
                ts4_concat3_881642B0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0)), (ts4_word)a1, (ts4_word)(ts4_word)lbl_880D382C);
                t8 = fn_8894F188((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
                p9 = (ts4_word)t8;
            }
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
            p11 = (ts4_word)p9;
            p12 = (ts4_word)(lv4 + 48);
            lv3 = p11;
            lv4 = p12;
        } while ((ts4_word)p12 != (ts4_word)t10);
        p14 = (ts4_word)lv3;
    }
    return p14;
}

/* Swing_DLL.xex 0x88954078: loop_call_seq u32@0x530, u32@0x52c, u32@0x538, u32@0x0, u32@0x68, u32@0x530 */
ts4_word ts4_loop_call_seq_u32_off530_88954078(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p7;
    ts4_word p12;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t11;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1328);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1324);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1336) = (ts4_word)t1;
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv3 = (ts4_word)t2;
        do {
            t4 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
            if ((ts4_word)t4 != 0 && (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t4) + 104)) == 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1336) = (ts4_word)lv3;
                break;
            }
            t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1328);
            p7 = (ts4_word)(lv3 + 4);
            lv3 = p7;
        } while ((ts4_word)p7 != (ts4_word)t6);
    }
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 1336);
    p12 = (ts4_word)a0;
    if ((ts4_word)t1 != (ts4_word)t9) {
        fn_88950808((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D3E20, (ts4_word)(ts4_word)lbl_880D3DF8);
        t11 = fn_88950808((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D3E68, (ts4_word)(ts4_word)lbl_880D3E40);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x8895B3C0: call_seq u32@0x20, fn_881599B8, fn_88991DA8, fn_88159870 */
ts4_word ts4_call_seq_u32_off20_8895B3C0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    fn_881599B8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    fn_88991DA8((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = fn_88159870((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x8895E320: if_call_seq u32@lbl_88D458D0, u32@0x1c, fn_8862C0E8, fn_88923530, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_88D458D0_8895E320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p9;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)lbl_88D458D0;
    if ((ts4_word)t1 == 0) {
        p9 = (ts4_word)0;
    } else {
        fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        t4 = loc50[2];
        t5 = fn_88923530((ts4_word)t4, *(ts4_args3 *)&loc50[0], (ts4_word)((3317366784) | 46560));
        t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 0);
        *(ts4_word *)((char *)(ts4_word)((t6 + t5)) + 4) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)((t6 + t5)) + 8) = (ts4_word)a2;
        *(unsigned char *)((char *)(ts4_word)((t6 + t5)) + 20) = (unsigned char)0;
        p9 = (ts4_word)1;
    }
    return p9;
}

/* Swing_DLL.xex 0x88960118: loop_get u32@0x58, u32@0x0, u32@0x0, u32@0x4 */
void ts4_loop_get_u32_off58_88960118(ts4_word a0)
{
    ts4_word p3;
    ts4_word lv5;
    ts4_word p7;
    ts4_word p8;
    ts4_word t1;
    int t2;
    int t4;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    lv5 = (ts4_word)p3;
    do {
        p7 = (ts4_word)0;
        if ((int)t4 != -1) {
            p7 = (ts4_word)((((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) << 3) + t4) + t1);
        }
        if ((ts4_word)lv5 == (ts4_word)p7) {
            return;
        }
        p8 = (ts4_word)(lv5 + 8);
        lv5 = p8;
    } while (1);
}

/* Swing_DLL.xex 0x889639F8: if_call_seq u32@0x30, u32@0x0, u32@0x34, u32@0x34, fn_88161540, u32@0x34 */
void ts4_if_call_seq_u32_off30_889639F8(ts4_word a0)
{
    ts4_word p15;
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    int t14;
    ts4_word t16;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != 0) {
        t14 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
        if ((int)t14 != -1) {
            p15 = (ts4_word)(t14 + t1);
        } else {
            p15 = (ts4_word)(ts4_word)lbl_880C1320;
        }
        t16 = fn_8862C0E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)p15);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t16) + 0));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t16) + 4));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t16) + 8));
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t4 != 0) {
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)0;
        loc50[2] = (ts4_word)0;
        fn_88161540((ts4_word)(ts4_word)&loc50[0]);
        fn_8892DC70((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 52)), (ts4_word)(ts4_word)&loc50[0]);
        t8 = loc50[0];
        t9 = *(volatile ts4_word *)((char *)(ts4_word)(t8) + 0);
        t10 = *(volatile ts4_word *)((char *)(ts4_word)(t8) + 4);
        t11 = *(volatile ts4_word *)((char *)(ts4_word)(t8) + 8);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)t9;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)t10;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)t11;
        ts4_destroy_owned_object((ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x88964398: call_seq u32@0x0, fn_88940B18, ts4_call_seq_ts4_assign_formatted_text_8895BDD8, fn_8895F308 */
ts4_word ts4_call_seq_u32_off0_88964398(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    ts4_word loc60[64];
    ts4_word loc50[4];
    ts4_word t6;

    fn_88940B18((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0)), (ts4_word)(ts4_word)&loc60[0]);
    (void)sp1.w[2];
    ts4_call_seq_ts4_assign_formatted_text_8895BDD8((ts4_word)(ts4_word)&loc50[0], sp1, (ts4_word)(ts4_word)&loc60[0]);
    (void)loc50[2];
    t6 = fn_8895F308((ts4_word)a0, *(ts4_args3 *)&loc50[0], (ts4_word)a4);
    return t6;
}

/* Swing_DLL.xex 0x889643F8: call_seq u32@0x0, fn_88940B18, ts4_call_seq_ts4_assign_formatted_text_8895BDD8, fn_8895F6C8 */
ts4_word ts4_call_seq_u32_off0_889643F8(ts4_args3 sp0, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc60[64];
    ts4_word loc50[4];
    ts4_word t6;

    fn_88940B18((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)), (ts4_word)(ts4_word)&loc60[0]);
    (void)sp0.w[2];
    ts4_call_seq_ts4_assign_formatted_text_8895BDD8((ts4_word)(ts4_word)&loc50[0], sp0, (ts4_word)(ts4_word)&loc60[0]);
    (void)loc50[2];
    t6 = fn_8895F6C8(*(ts4_args3 *)&loc50[0], (ts4_word)a3, (ts4_word)a4);
    return t6;
}

/* Swing_DLL.xex 0x8897D0A0: if_call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30, fn_88943AA0 */
ts4_word ts4_if_call_seq_u32_off0_8897D0A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t5 == 0) {
        t6 = fn_88943AA0((ts4_word)a0, (ts4_word)a1);
        if ((ts4_word)t6 != 0) {
            t7 = fn_8897CD88((ts4_word)a2, (ts4_word)t6);
            return t7;
        }
    }
    return t5;
}

/* Swing_DLL.xex 0x889804E8: if_call_seq u32@0x0, fn_88608590, u32@0x0, fn_88608590, fn_88941B30, fn_88943B70 */
ts4_word ts4_if_call_seq_u32_off0_889804E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    int t8;
    ts4_word t9;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    t4 = fn_88608590((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)));
    loc50[0] = (ts4_word)t4;
    t5 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t5 == 0) {
        t6 = fn_88943B70((ts4_word)a0, (ts4_word)a1);
        if ((ts4_word)t6 != 0) {
            t7 = fn_88980358((ts4_word)a2, (ts4_word)t6);
            t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
            if ((int)t8 == 7) {
                t9 = fn_88941B30((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
                return t9;
            }
            return t7;
        }
    }
    return t5;
}

/* Swing_DLL.xex 0x8898E0A0: addr lbl_88D45BB8, u32@lbl_88D45BB8, u8@0x4 */
void ts4_addr_lbl_88D45BB8_8898E0A0(void)
{
    *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45BB8) + 4) = (unsigned char)0;
    *(ts4_word *)lbl_88D45BB8 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88991B88: if_call_seq fn_8898F450, u32@0x0, fn_889913B0 */
ts4_word ts4_if_call_seq_fn_8898F450_88991B88(ts4_word a0, ts4_word a1, float f1)
{
    ts4_word p4;
    ts4_word t1;

    t1 = fn_8898F450((ts4_word)a0);
    if ((ts4_word)(t1 & 0xff) == 0) {
        p4 = (ts4_word)0;
    } else {
        fn_889913B0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 48), (ts4_word)a1, (ts4_word)0, (ts4_word)1, f1, (ts4_word)(a0 + 16));
        p4 = (ts4_word)1;
    }
    return p4;
}

/* Swing_DLL.xex 0x88991C08: if_call_seq fn_8898F450, u32@0x4, u32@0x0, fn_889913B0 */
ts4_word ts4_if_call_seq_fn_8898F450_88991C08(ts4_word a0, ts4_word a1, float f1)
{
    ts4_word p4;
    ts4_word t1;

    t1 = fn_8898F450((ts4_word)a0);
    if ((ts4_word)(t1 & 0xff) == 0) {
        p4 = (ts4_word)0;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        fn_889913B0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 48), (ts4_word)a1, (ts4_word)0, (ts4_word)0, f1, (ts4_word)(a0 + 16));
        p4 = (ts4_word)1;
    }
    return p4;
}

/* Swing_DLL.xex 0x88995320: loop_get u32@0x14, u32@0x10, u64@0x0, u32@0x0, u64@0x50 */
ts4_word ts4_loop_get_u32_off14_88995320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_u64 t3;
    ts4_word t6;
    ts4_u64 t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t2 != (ts4_word)t1) {
        t3 = *(ts4_u64 *)((char *)(ts4_word)(a1) + 0);
        lv4 = (ts4_word)t2;
        do {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
            t7 = *(ts4_u64 *)((char *)(ts4_word)(t6) + 80);
            if ((ts4_u64)t7 == (ts4_u64)t3) {
                return t6;
            }
            p8 = (ts4_word)(lv4 + 4);
            lv4 = p8;
        } while ((ts4_word)p8 != (ts4_word)t1);
    }
    return 0;
}

/* Swing_DLL.xex 0x88995B58: call_seq u32@0x6c, fn_88995AB8 */
ts4_word ts4_call_seq_u32_off6c_88995B58(ts4_word a0, ts4_word a1, ts4_u64 a2)
{
    ts4_word loc50[6];
    ts4_word t2;

    loc50[0] = (ts4_word)a1;
    *(ts4_u64 *)((char *)loc50 + 16) = (ts4_u64)a2;
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)2;
    t2 = fn_88995AB8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)), (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x88995B90: call_seq u32@0x6c, fn_88995AB8 */
ts4_word ts4_call_seq_u32_off6c_88995B90(ts4_word a0, ts4_word a1, ts4_u64 a2)
{
    ts4_word loc50[6];
    ts4_word t2;

    loc50[0] = (ts4_word)a1;
    *(ts4_u64 *)((char *)loc50 + 16) = (ts4_u64)a2;
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)2;
    t2 = fn_88995AB8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108)), (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x88995F00: if_get u32@0x32c, u64@0x70, u32@0x328, u32@0x32c, u32@0x32c */
void ts4_if_get_u32_off32c_88995F00(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_u64 t2;

    if ((ts4_word)a1 == 0) {
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 812);
    t2 = *(ts4_u64 *)((char *)(ts4_word)(a1) + 112);
    *(ts4_u64 *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 808))) + (t1 << 3)) = (ts4_u64)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 812) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 812)) + 1);
    return;
}

/* Swing_DLL.xex 0x8899D5D0: loop_get u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x18, vcall */
ts4_word ts4_loop_get_u32_off8_8899D5D0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word p12;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 24))))((ts4_word)t4);
        if ((ts4_word)(t7 & 0xff) != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(((((int)(*(ts4_word *)((char *)(ts4_word)(t4) + 128)) * 216) + (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 172))) + 0))) + (*(ts4_word *)((char *)(ts4_word)(a0) + 172)))) + 210)) == 0) {
            return 0;
        }
        p12 = (ts4_word)(lv3 + 4);
        lv3 = p12;
    }
    return 1;
}

/* Swing_DLL.xex 0x889B0F70: loop_get u32@0x1c, u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x0 */
void ts4_loop_get_u32_off1c_889B0F70(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv3;
    ts4_word lv7;
    ts4_word p18;
    ts4_word p24;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t10;
    int t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
            lv7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
            while ((ts4_word)lv7 != (ts4_word)t5) {
                t10 = *(ts4_word *)((char *)(ts4_word)(lv7) + 0);
                t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 128);
                if ((int)a1 == (int)t11) {
                    t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 104);
                    loc50[0] = (ts4_word)((2804154368) | 1986);
                    fn_8893CFD8((ts4_word)a0, (ts4_word)t12, (ts4_word)(ts4_word)&loc50[0]);
                    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
                    t15 = *(ts4_word *)((char *)(ts4_word)(t10) + 104);
                    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t14) + 64))))((ts4_word)a0, (ts4_word)t15);
                    return;
                }
                p18 = (ts4_word)(lv7 + 4);
                lv7 = p18;
            }
        }
        p24 = (ts4_word)(lv3 + 4);
        lv3 = p24;
    }
    return;
}

/* Swing_DLL.xex 0x889B1230: get fn_88627EC0, ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x1c */
ts4_word ts4_get_fn_88627EC0_889B1230(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = ts4_find_service((ts4_word)((2710831104) | 7610));
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 76))))((ts4_word)t3, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t6;
    t7 = ts4_find_service((ts4_word)((1704919040) | 59170));
    t10 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 76))))((ts4_word)t7, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 104));
    return t10;
}

/* Swing_DLL.xex 0x889B3E70: loop_call_seq u32@g_ts4_session_context, u32@0x3c, u32@0x64, fn_88931EF0, u32@0x14, fn_88931388 */
void ts4_loop_call_seq_u32_g_ts4_session_context_889B3E70(ts4_word a0)
{
    ts4_word lv6;
    ts4_word lv7;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t14;
    ts4_word t15;
    ts4_word t5;
    ts4_word t8;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60);
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    t3 = fn_88931EF0((ts4_word)a0);
    if ((ts4_word)t3 != 0) {
        t14 = *(ts4_word *)g_ts4_session_context;
        *(ts4_word *)((char *)(ts4_word)(t2) + 640) = (ts4_word)((3465084928) | 47812);
        t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 28);
        if ((ts4_word)t15 != 0) {
            fn_8893AD90((ts4_word)t15, (ts4_word)0);
            return;
        }
        return;
    }
    t5 = fn_88931388((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    lv6 = (ts4_word)t5;
    lv7 = (ts4_word)t5;
    while ((ts4_word)lv7 < 4) {
        p9 = (ts4_word)lv6;
        if ((int)lv7 != -1) {
            t8 = fn_889B1D68((ts4_word)lv7);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
        p11 = (ts4_word)(lv7 + 1);
        lv6 = p10;
        lv7 = p11;
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 640) = (ts4_word)((220528640) | 31475);
    return;
}

/* Swing_DLL.xex 0x889B6798: get u32@0x1c, u32@0x28, u32@0x140, u32@lbl_88D459D0, fn_8886A0A0 */
ts4_word ts4_get_u32_off1c_889B6798(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 320);
    return fn_8886A0A0((ts4_word)(*(volatile ts4_word *)lbl_88D459D0), (ts4_word)0, (ts4_word)((1110704128) | 32272), (ts4_word)((3751936000) | 45041), (ts4_word)t2, (ts4_word)t3, (ts4_word)(t3 - t2));
}

/* Swing_DLL.xex 0x889B7EF8: if_get u32@0x0, u8@0x12, fn_889B0E98, u32@0x14, u32@0x48, u32@0x40 */
ts4_word ts4_if_get_u32_off0_889B7EF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 <= (ts4_word)((1929183232) | 14320)) {
        if ((ts4_word)t1 != (ts4_word)((1929183232) | 14320)) {
            if ((ts4_word)t1 != (ts4_word)((88735744) | 45439) && (ts4_word)t1 != (ts4_word)((1479213056) | 12422)) {
                return a0;
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)1;
            return fn_889B0E98((ts4_word)a0);
        }
    } else {
        if ((ts4_word)t1 != (ts4_word)((2851930112) | 57941)) {
            return a0;
        }
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(t4) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t4) + 64) = (ts4_word)0;
    t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 0);
    *(ts4_word *)((char *)(ts4_word)(t6) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t6) + 64) = (ts4_word)1;
    return fn_889B76D0((ts4_word)a0);
}

/* Swing_DLL.xex 0x889C61C0: if_get u32@0x0, u32@0x8, u32@0x0, u8@0x1, u8@0x0, u32@0x8 */
void ts4_if_get_u32_off0_889C61C0(ts4_word a0, int a1)
{
    ts4_word t1;
    int t2;
    int t3;
    unsigned char t4;
    unsigned char t5;

    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 >= (int)t3) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + t2);
    t5 = *(unsigned char *)((char *)(ts4_word)((t1 + t2)) + 1);
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + 2);
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)t5;
    return;
}
