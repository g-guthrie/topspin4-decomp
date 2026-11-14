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

extern char __imp_KeCertMonitorData[];
extern char __imp_KeDebugMonitorData[];
extern char lbl_88001A20[];
extern char lbl_88028BDC[];
extern char lbl_88028EF0[];
extern char lbl_88029648[];
extern char lbl_880391A8[];
extern char lbl_88039A20[];
extern char lbl_8803A150[];
extern char lbl_8803A180[];
extern char lbl_8808D810[];
extern char lbl_88091EF4[];
extern char lbl_880B4540[];
extern char lbl_880B4598[];
extern char lbl_880B85D8[];
extern char lbl_880B9788[];
extern char lbl_880B9820[];
extern char lbl_880BA570[];
extern char lbl_880BA5D0[];
extern char lbl_880D1B30[];
extern char lbl_880F9EB8[];
extern char lbl_880F9ED8[];
extern char lbl_88B3302C[];
extern char lbl_88C42CC8[];
extern char lbl_88C42E88[];
extern char lbl_88D429E2[];
ts4_word fn_881506A0();
ts4_word ts4_if_call_seq_fn_8892EE88_8817F5E0();
ts4_word fn_882A1038();
ts4_word fn_882A13A8();
ts4_word fn_882A17F0();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word fn_883194F0();
ts4_word fn_883299F0();
ts4_word fn_883E3B60();
double ts4_call_seq_fn_88563F20_885640B0(float);
ts4_word fn_8857ACB8();
ts4_word fn_885DC838();
ts4_word fn_885DD4C8(ts4_word, ts4_word, float);
ts4_word fn_886328B0();
ts4_word fn_88633310();
ts4_word fn_88722870();
ts4_word fn_88722970();
ts4_word fn_888BD828();
ts4_word fn_888CF650();
ts4_word fn_88923530();
ts4_word fn_88947E40();
#ifndef _MSC_VER
#define sprintf ts4_host_sprintf
#endif
ts4_word sprintf();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_lbl_880F7D90_88627BD8();
ts4_word ts4_call_seq_lbl_880F7D90_88628EE0();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_if_call_seq_fn_88309DB8_88309108();
ts4_word ts4_if_call_seq_fn_88309DB8_88309160();
ts4_word ts4_read_indexed_u32_property_885DCDA8();

/* Swing_DLL.xex 0x882A20E0: if_addr lbl_88D429E2, u8@0x2902, u8@0x5e7c, u8@-0x1, u8@-0x1, u8@0x0 */
ts4_word ts4_if_addr_lbl_88D429E2_882A20E0(ts4_word a0)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word p22;
    ts4_word p25;
    ts4_word p26;
    ts4_word p27;
    ts4_word p28;
    ts4_word loc50[66];
    unsigned char t1;
    unsigned char t2;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t23;
    ts4_word t24;
    ts4_word t19;
    ts4_word t21;
    unsigned char t4;
    ts4_word t9;
    unsigned char t6;
    ts4_word t7;

    t1 = *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D429E2) + 10498);
    p28 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 24188);
        if ((int)(t2 & 0x10) == 0) {
            t11 = fn_882A1038();
            t12 = sprintf((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F9ED8, (ts4_word)(ts4_word)lbl_880F9EB8, (ts4_word)((t11 == 0) ? ((2147483648) | 16389) : 0));
            t14 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeCertMonitorData)) + 0);
            if ((ts4_word)t14 != 0) {
                t23 = *(ts4_word *)((char *)(ts4_word)(t14) + 0);
                p25 = (ts4_word)t12;
                if ((ts4_word)t23 != 0) {
                    t24 = ((ts4_word (*)(ts4_word, ts4_word))(t23))((ts4_word)27, (ts4_word)(ts4_word)&loc50[0]);
                    p25 = (ts4_word)t24;
                }
                p26 = (ts4_word)p25;
            } else {
                t19 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeDebugMonitorData)) + 0);
                p22 = (ts4_word)t12;
                if ((ts4_word)t19 != 0) {
                    t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t19) + 24))))((ts4_word)27, (ts4_word)(ts4_word)&loc50[0]);
                    p22 = (ts4_word)t21;
                }
                p26 = (ts4_word)p22;
            }
            p27 = (ts4_word)p26;
        } else {
            t4 = *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D429E2) + -1);
            if ((ts4_word)t4 != 0) {
                t9 = fn_882A13A8();
                p10 = (ts4_word)t9;
            } else {
                t6 = *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D429E2) + 0);
                p8 = (ts4_word)a0;
                if ((ts4_word)t6 != 0) {
                    t7 = fn_882A17F0();
                    p8 = (ts4_word)t7;
                }
                p10 = (ts4_word)p8;
            }
            p27 = (ts4_word)p10;
        }
        p28 = (ts4_word)p27;
    }
    return p28;
}

/* Swing_DLL.xex 0x883D1550: if_call_seq u32@0x24, lbl_880391A8, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x24 */
ts4_word ts4_if_call_seq_u32_off24_883D1550(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_880391A8, (ts4_word)1114);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    if ((ts4_word)a1 != 0) {
        t6 = fn_883299F0((ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t6;
        p7 = (ts4_word)((t6 == 0) ? 44 : 0);
    } else {
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x883D2C18: if_call_seq u32@0x14, ts4_if_call_seq_fn_88309DB8_88309160, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off14_883D2C18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p20;
    ts4_word loc50[6];
    ts4_word t1;
    float t4;
    float t5;
    float t7;
    float t8;
    float t10;
    float t11;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 32924));
    if ((ts4_word)t1 == 0) {
        p20 = (ts4_word)31;
    } else {
        if ((ts4_word)a2 != 0) {
            ts4_if_call_seq_fn_88309DB8_88309160((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0, (ts4_word)0);
            t4 = *(float *)((char *)(ts4_word)(a2) + 0);
            t5 = *(float *)((char *)loc50 + 0);
            if (t4 == t5) {
                t7 = *(float *)((char *)(ts4_word)(a2) + 4);
                t8 = *(float *)((char *)loc50 + 4);
                if (t7 == t8) {
                    t10 = *(float *)((char *)(ts4_word)(a2) + 8);
                    t11 = *(float *)((char *)loc50 + 8);
                    if (!(t10 == t11)) {
                        *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0)) | 8);
                    }
                } else {
                    *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0)) | 8);
                }
            } else {
                *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + -32600)) + 0)) | 8);
            }
        }
        t19 = ts4_if_call_seq_fn_88309DB8_88309108((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p20 = (ts4_word)t19;
    }
    return p20;
}

/* Swing_DLL.xex 0x883E3B10: if_call_seq ts4_call_seq_fn_88563F20_885640B0 */
float ts4_if_call_seq_fn_885640B0_883E3B10(ts4_word a0, float f1)
{
    float pf6;
    float t1;
    double t2;

    (void)a0;
    t1 = *(float *)lbl_88028BDC;
    if (!(f1 > t1)) {
        pf6 = (*(float *)lbl_88029648);
    } else {
        t2 = ts4_call_seq_fn_88563F20_885640B0(f1);
        pf6 = (((float)t2) * (*(float *)lbl_88028EF0));
    }
    return pf6;
}

/* Swing_DLL.xex 0x883E3E58: if_call_seq u32@0x44, fn_8857ACB8, u32@0xc, u32@0x0, u32@0x8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off44_883E3E58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word p5;
    ts4_word p7;
    ts4_word p14;
    ts4_word t1;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        p14 = (ts4_word)37;
    } else {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
        if ((int)(t1 & 0x10) != 0) {
            p7 = (ts4_word)0;
        } else {
            if ((int)(t1 & 0x20) != 0) {
                p5 = (ts4_word)1;
            } else {
                if ((int)(t1 & 0x40) != 0) {
                    p3 = (ts4_word)2;
                } else {
                    p3 = (ts4_word)(((t1 & 0x80) != 0) ? 3 : 0);
                }
                p5 = (ts4_word)p3;
            }
            p7 = (ts4_word)p5;
        }
        fn_8857ACB8((ts4_word)a1, (ts4_word)((((int)p7 * 76) + a0) + 20), (ts4_word)76);
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t10 - t9);
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t11 - (*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        p14 = (ts4_word)0;
    }
    return p14;
}

/* Swing_DLL.xex 0x883EA5C8: if_addr fn_883194F0, fn_883194F0, lbl_88039A20, u32@lbl_88B3302C, u32@0x4, fn_88315C60 */
ts4_word ts4_if_addr_fn_883194F0_883EA5C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word p17;
    ts4_word p18;
    ts4_word p19;
    ts4_word loc50[1];
    ts4_word loc54[1];
    int t1;
    int t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    float t9;
    ts4_word t12;
    float t13;

    (void)a0;
    (void)a2;
    t1 = fn_883194F0((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4, (ts4_word)1, (ts4_word)0);
    p19 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = fn_883194F0((ts4_word)a1, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)1, (ts4_word)0);
        p18 = (ts4_word)t2;
        if ((int)t2 == 0) {
            t5 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)328, (ts4_word)(ts4_word)lbl_88039A20, (ts4_word)2760, (ts4_word)0, (ts4_word)0);
            if ((ts4_word)t5 != 0) {
                t6 = fn_883E3B60((ts4_word)t5);
                p7 = (ts4_word)t6;
            } else {
                p7 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)p7;
            if ((ts4_word)p7 == 0) {
                p17 = (ts4_word)44;
            } else {
                t8 = *(ts4_word *)((char *)(ts4_word)(p7) + 0);
                t9 = *(float *)((char *)loc50 + 0);
                ((ts4_word (*)(ts4_word, float))((*(ts4_word *)((char *)(ts4_word)(t8) + 8))))((ts4_word)p7, t9);
                t12 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
                t13 = *(float *)((char *)loc54 + 0);
                ((ts4_word (*)(ts4_word, float))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 16))))((ts4_word)t12, t13);
                p17 = (ts4_word)0;
            }
            p18 = (ts4_word)p17;
        }
        p19 = (ts4_word)p18;
    }
    return p19;
}

/* Swing_DLL.xex 0x883FD310: if_call_seq lbl_8803A150, u32@lbl_88B3302C, u32@0x4, fn_88315C60, lbl_8803A180, u32@0x1c */
ts4_word ts4_if_call_seq_lbl_8803A150_883FD310(ts4_word a0)
{
    ts4_word p5;
    ts4_word t3;
    float t4;

    t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)40, (ts4_word)(ts4_word)lbl_8803A150, (ts4_word)137, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)0;
        t4 = *(float *)lbl_88001A20;
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)1;
        *(float *)((char *)(ts4_word)(t3) + 20) = t4;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_8803A180;
        *(float *)((char *)(ts4_word)(t3) + 24) = t4;
        *(unsigned char *)((char *)(ts4_word)(t3) + 36) = (unsigned char)0;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    *(float *)((char *)(ts4_word)(p5) + 20) = (*(float *)((char *)(ts4_word)(a0) + 20));
    *(float *)((char *)(ts4_word)(p5) + 24) = (*(float *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(p5) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(p5) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(unsigned char *)((char *)(ts4_word)(p5) + 36) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 36));
    return p5;
}

/* Swing_DLL.xex 0x885CF2F8: if_get u32@0x0, lbl_8808D810, u32@0x0, vcall, u32@0x0, lbl_88091EF4 */
ts4_word ts4_if_get_u32_off0_885CF2F8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    int t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_8808D810, (ts4_word)(a0 + 252));
    p7 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88091EF4, (ts4_word)(a0 + 256));
        p7 = (ts4_word)(((((2147483648) | 16386) - t6) != 0) ? t6 : 0);
    }
    return p7;
}

/* Swing_DLL.xex 0x885E0F70: if_set u32@0x0, fn_885DD4C8, lbl_88C42CC8, lbl_880B9820, u32@0x160, vcall */
ts4_word ts4_if_set_u32_off0_885E0F70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[8];

    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(1258291200);
    if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
        fn_885DD4C8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (*(float *)((char *)(ts4_word)(a2) + 0)));
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B9820, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 352)), (ts4_word)88, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    }
    return 1;
}

/* Swing_DLL.xex 0x885E0FE8: if_addr lbl_880B4540, lbl_880B9788, lbl_880B4598, fn_885DC838, ts4_read_indexed_u32_property_885DCDA8, ts4_read_indexed_u32_property_885DCDA8 */
ts4_word ts4_if_addr_lbl_880B4540_885E0FE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word loc50[10];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    if ((ts4_word)a0 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B4598, (ts4_word)(ts4_word)lbl_880B9788, (ts4_word)4437);
    }
    t3 = ts4_read_indexed_u32_property_885DCDA8((ts4_word)a0, (ts4_word)91, (ts4_word)a1);
    t4 = ts4_read_indexed_u32_property_885DCDA8((ts4_word)a0, (ts4_word)92, (ts4_word)a1);
    t5 = *(ts4_word *)((char *)(ts4_word)(((((t3 << 2) + t4) << 2) + (ts4_word)lbl_88C42E88)) + -4);
    if ((ts4_word)t3 != 2 && (ts4_word)t3 != 3) {
        p7 = (ts4_word)t4;
        if ((ts4_word)t3 != 1 && (ts4_word)t3 != 0) {
            t6 = fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B85D8, (ts4_word)(ts4_word)lbl_880B9788, (ts4_word)4450);
            p7 = (ts4_word)t6;
        }
        p8 = (ts4_word)7;
        p9 = (ts4_word)p7;
    } else {
        p8 = (ts4_word)2;
        p9 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((((p8 << 8) | 4915200) | t5) << 8);
    if ((ts4_word)a3 != 0 && (ts4_word)a4 != 0) {
        fn_885DD4C8((ts4_word)p9, (ts4_word)(ts4_word)&loc50[0], (*(float *)((char *)(ts4_word)(a2) + 0)));
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(a3))((ts4_word)a4, (ts4_word)(ts4_word)lbl_880B9820, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C42CC8) + 356)), (ts4_word)89, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    }
    return 1;
}

/* Swing_DLL.xex 0x885E3A10: loop_call_seq u8@0x751, lbl_880B4540, lbl_880BA570, lbl_880BA5D0, fn_885DC838, u32@0x0 */
ts4_word ts4_loop_call_seq_u8_off751_885E3A10(int a0, int a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word c8;
    ts4_word p10;
    ts4_word lv9;
    ts4_word p11;
    ts4_word p12;

    if ((ts4_word)(*(unsigned char *)(1873 + (char *)(ts4_word)(a0))) != 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880BA5D0, (ts4_word)(ts4_word)lbl_880BA570, (ts4_word)482);
    }
    lv5 = (ts4_word)0;
    lv4 = (ts4_word)(a0 + 912);
    do {
        if ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv4) + 0)) == 0) {
            *(ts4_word *)((char *)(ts4_word)(((lv5 + 244) << 2)) + a0) = (ts4_word)a1;
            *(ts4_word *)((char *)(ts4_word)(((lv5 + 260) << 2)) + a0) = (ts4_word)a2;
            *(ts4_word *)((char *)(ts4_word)(((lv5 + 228) << 2)) + a0) = (ts4_word)a3;
            if ((int)a1 != 33) {
                c8 = (ts4_word)4;
                lv9 = (ts4_word)0;
                do {
                    *(ts4_word *)((char *)(ts4_word)(((((lv5 + 69) << 2) + lv9) << 2)) + a0) = (ts4_word)5;
                    p10 = (ts4_word)(lv9 + 1);
                    lv9 = p10;
                } while (--c8 != 0);
                return lv5;
            }
            return lv5;
        }
        p11 = (ts4_word)(lv4 + 4);
        p12 = (ts4_word)(lv5 + 1);
        lv4 = p11;
        lv5 = p12;
    } while ((int)p12 < 16);
    fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880D1B30, (ts4_word)(ts4_word)lbl_880BA570, (ts4_word)499);
    return 0;
}

/* Swing_DLL.xex 0x88632A18: if_call_seq fn_88923530, u32@0x0, fn_886328B0 */
ts4_word ts4_if_call_seq_fn_88923530_88632A18(ts4_args3 sp0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    int t3;
    ts4_word t4;

    t1 = sp0.w[2];
    t2 = fn_88923530((ts4_word)t1, sp0, (ts4_word)((2707619840) | 49510));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    p5 = (ts4_word)1;
    if ((int)t3 != -1) {
        t4 = fn_886328B0((ts4_word)(t3 + t2));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88634570: call_seq ts4_call_seq_lbl_880F7D90_88628EE0, fn_88633310, ts4_call_seq_lbl_880F7D90_88627BD8 */
ts4_word ts4_call_seq_ts4_call_seq_lbl_880F7D90_88628EE0_88634570(ts4_args3 sp0, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[14];
    ts4_word t3;

    ts4_call_seq_lbl_880F7D90_88628EE0((ts4_word)(ts4_word)&loc50[0]);
    fn_88633310((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)a2, (ts4_word)(ts4_word)&sp0, (ts4_word)0, (ts4_word)a3, (ts4_word)0, (ts4_word)0);
    t3 = ts4_call_seq_lbl_880F7D90_88627BD8((ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x886ED140: set u32@0x24, u32@0x28, u32@0x2c */
void ts4_set_u32_off24_886ED140(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = sp1.w[1];
    t2 = sp1.w[2];
    t3 = sp1.w[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x886F54A0: call_seq fn_881506A0 */
ts4_word ts4_call_seq_fn_881506A0_886F54A0(ts4_args3 sp0)
{
    ts4_word loc50[2];

    fn_881506A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0);
    return 0;
}

/* Swing_DLL.xex 0x888BF188: if_call_seq fn_888BD828, u32@0x8, u32@0x0, ts4_if_call_seq_fn_8892EE88_8817F5E0, u32@0x84, ts4_if_call_seq_fn_8892EE88_8817F5E0 */
ts4_word ts4_if_call_seq_fn_888BD828_888BF188(ts4_word a0)
{
    ts4_word p8;
    ts4_word loc50[3];
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = fn_888BD828();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p8 = (ts4_word)t1;
    if ((int)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t4 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)((t3 + t2) + 156), *(ts4_args3 *)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)t4;
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t5 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)((t3 + t2) + 168), *(ts4_args3 *)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)t5;
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t6 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)((t3 + t2) + 180), *(ts4_args3 *)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)t6;
        loc50[0] = (ts4_word)0;
        loc50[1] = (ts4_word)((983040) | 65535);
        loc50[2] = (ts4_word)0;
        t7 = ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)((t3 + t2) + 192), *(ts4_args3 *)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)t7;
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x888CFBC8: call_seq fn_888CF650 */
ts4_word ts4_call_seq_fn_888CF650_888CFBC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[6];
    ts4_word t1;

    (void)a1;
    (void)a2;
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)-1;
    loc50[2] = (ts4_word)0;
    *(unsigned char *)((char *)loc50 + 12) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 13) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 14) = (unsigned char)0;
    *(unsigned char *)((char *)loc50 + 15) = (unsigned char)0;
    t1 = fn_888CF650((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)-1);
    return t1;
}

/* Swing_DLL.xex 0x88922668: get u32@0x24 */
ts4_word ts4_get_u32_off24_88922668(ts4_word a0, ts4_args3 sp1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = sp1.w[1];
    return (t1 + t2);
}

/* Swing_DLL.xex 0x8894D6C8: call_seq fn_88947E40 */
ts4_word ts4_call_seq_fn_88947E40_8894D6C8(ts4_args3 sp0)
{
    ts4_word t2;

    (void)sp0.w[2];
    t2 = fn_88947E40(sp0, (ts4_word)-1);
    return t2;
}

/* Swing_DLL.xex 0x8895BD70: call_seq ts4_assign_formatted_text, fn_88722870, ts4_destroy_owned_object */
ts4_word ts4_call_seq_ts4_assign_formatted_text_8895BD70(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    (void)sp1.w[2];
    fn_88722870((ts4_word)a0, sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t4);
    return a0;
}

/* Swing_DLL.xex 0x8895BDD8: call_seq ts4_assign_formatted_text, fn_88722970, ts4_destroy_owned_object */
ts4_word ts4_call_seq_ts4_assign_formatted_text_8895BDD8(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    ts4_word loc50[6];
    ts4_word t4;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    (void)sp1.w[2];
    fn_88722970((ts4_word)a0, sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t4);
    return a0;
}
