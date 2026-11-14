/* Swing_DLL.xex 0x8834E490-0x8848B10C, executable version 0.0.0.3. */
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
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#endif

extern char lbl_8802BEAC[];
extern char lbl_8803BA9C[];
extern char lbl_8803BABC[];
extern char lbl_8803BADC[];
extern char lbl_8803BAF8[];
extern char lbl_8803CB5C[];
extern char lbl_8803CB7C[];
extern char lbl_8803DAB8[];
extern char lbl_8803DB48[];
extern char lbl_8803DC28[];
extern char lbl_8803EC94[];
extern char lbl_8803ECB0[];
extern char lbl_8803ECD0[];
extern char lbl_88048118[];
extern char lbl_880E1DE4[];
extern char lbl_88C922E4[];
extern char lbl_88CACF08[];
extern char lbl_88CAD330[];
extern char lbl_88CAD334[];
ts4_word KeTlsGetValue();
ts4_word fn_88189D98();
ts4_word ts4_read_u8_to_u8_883199C0();
ts4_word fn_88319C40();
ts4_word fn_883296A0();
ts4_word fn_883332F0();
ts4_word fn_88361A50();
ts4_word fn_88362688();
ts4_word fn_88365668();
ts4_word fn_883661F0();
ts4_word fn_88368A50();
ts4_word fn_88369310();
ts4_word fn_88389CD8();
ts4_word fn_883A3218();
ts4_word fn_8841A510();
ts4_word fn_8841A740();
ts4_word fn_8841B498();
ts4_word fn_8841B6C0();
ts4_word fn_8841BBC8();
ts4_word fn_884210E8();
ts4_word ts4_find_entry_by_name_884278D0();
ts4_word fn_88431D40();
ts4_word fn_88474120();
ts4_word ts4_traced_t2_8848C968();
ts4_word ts4_traced_t3_8848D648();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_call_seq_lbl_8803DAE8_8841BEF0();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_88428988();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_get_u32_off0_88428B30();
ts4_word ts4_get_u32_off4_88426138();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off7c_8846AA28();
ts4_word ts4_get_u32_off8_88426140();
ts4_word ts4_if_call_seq_u32_lbl_88CACF08_8841C3A0();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_get_u8_off50_88381458();
ts4_word ts4_index_u16_array_at_field0_88428A08();
ts4_word ts4_memset();
ts4_word ts4_tailcall_memcpy_88421450();

/* Swing_DLL.xex 0x8834E490: if_call_seq u32@0x108, ts4_read_u8_to_u8_883199C0, u32@0x108, fn_88319C40 */
ts4_word ts4_if_call_seq_u32_off108_8834E490(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];

    if ((int)((signed char)a1) != 10) {
        if ((int)((signed char)a1) != 13) {
            return 0;
        }
        ts4_read_u8_to_u8_883199C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)), (ts4_word)(ts4_word)&loc50[0]);
        fn_88319C40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)), (ts4_word)-1, (ts4_word)1);
        return (((*(unsigned char *)((char *)loc50 + 0)) + -10) != 0);
    }
    return 1;
}

/* Swing_DLL.xex 0x883632B8: if_call_seq u32@0x880, u8@0x87d, fn_88362688, u8@0x87d, u8@0x87e, u32@0x8a0 */
ts4_word ts4_if_call_seq_u32_off880_883632B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    unsigned char t5;
    int t7;
    int t8;
    int t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    unsigned char t14;
    int t15;
    int t16;
    int t25;
    ts4_word t26;
    ts4_word t27;
    ts4_word t29;

    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
    if ((int)t1 == 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
        if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 2174)) == 0) {
            fn_883A3218();
        } else {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 2208);
            if ((int)t7 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2192) = (ts4_word)t7;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)-1;
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t8 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2188) = (ts4_word)t8;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)-1;
            }
            fn_88361A50((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)-1);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t10 == -1) {
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 2192);
                t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 2188);
                t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 528);
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)(t12 + 1);
                t14 = *(unsigned char *)((char *)(ts4_word)((t11 + a0)) + 540);
                t15 = *(ts4_word *)((char *)(ts4_word)(((t14 << 3) | (t14 >> 29))) + t13);
                if ((int)(t12 + 1) >= (int)t15) {
                    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 1416);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(t11 + 1);
                    if ((int)(t11 + 1) >= (int)t16) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2148));
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)0;
                }
            }
        }
    } else {
        if ((ts4_word)(a1 & 0xff) != 0) {
            fn_88362688((ts4_word)a0);
        }
    }
    t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 2180);
    if ((int)t25 != 0) {
        t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
        t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 2196);
        *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)(t26 + 1);
        if ((int)(t26 + 1) >= (int)(t27 + t25)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 2196) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)0;
        }
    } else {
        *(unsigned char *)((char *)(ts4_word)(a0) + 2173) = (unsigned char)1;
    }
    t29 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1268) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1264)) + t29);
    return 0;
}

/* Swing_DLL.xex 0x88366B60: if_call_seq u32@0x880, u8@0x87d, fn_883661F0, u8@0x87d, u8@0x87e, u32@0x8a0 */
ts4_word ts4_if_call_seq_u32_off880_88366B60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    unsigned char t5;
    int t7;
    int t8;
    int t10;
    ts4_word t11;
    ts4_word t12;
    int t13;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;

    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
    if ((int)t1 == 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
        if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 2174)) == 0) {
            fn_883A3218();
        } else {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 2208);
            if ((int)t7 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2192) = (ts4_word)t7;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)-1;
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t8 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2188) = (ts4_word)t8;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)-1;
            }
            fn_88365668((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)-1);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t10 == -1) {
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 2188);
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)(t11 + 1);
                if ((int)(t11 + 1) >= 64) {
                    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 2192);
                    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 1416);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(t12 + 1);
                    if ((int)(t12 + 1) >= (int)t13) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2148));
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)0;
                }
            }
        }
    } else {
        if ((ts4_word)(a1 & 0xff) != 0) {
            fn_883661F0((ts4_word)a0);
        }
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 2180);
    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 2196);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)(t21 + 1);
    if ((int)(t21 + 1) >= (int)(t22 + t23)) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 2196) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)0;
    }
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1268) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1264)) + t24);
    return 0;
}

/* Swing_DLL.xex 0x88369A38: if_call_seq u32@0x880, u8@0x87d, fn_88369310, u8@0x87d, u8@0x87e, u32@0x8a0 */
ts4_word ts4_if_call_seq_u32_off880_88369A38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    unsigned char t5;
    int t7;
    int t8;
    int t10;
    ts4_word t11;
    ts4_word t12;
    int t13;
    int t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t25;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
    if ((int)t1 == 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 2173);
        if ((ts4_word)t5 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 2174)) == 0) {
            fn_883A3218();
        } else {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 2208);
            if ((int)t7 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2192) = (ts4_word)t7;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)-1;
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t8 >= 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 2188) = (ts4_word)t8;
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)-1;
            }
            fn_88368A50((ts4_word)a0);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 2204);
            if ((int)t10 == -1) {
                t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 2188);
                *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)(t11 + 1);
                if ((int)(t11 + 1) >= 64) {
                    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 2192);
                    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 1416);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(t12 + 1);
                    if ((int)(t12 + 1) >= (int)t13) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 2208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2148));
                    }
                    *(ts4_word *)((char *)(ts4_word)(a0) + 2204) = (ts4_word)0;
                }
            }
        }
    } else {
        if ((ts4_word)(a1 & 0xff) != 0) {
            fn_88369310((ts4_word)a0);
        }
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 2180);
    if ((int)t21 != 0) {
        t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 2176);
        t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 2196);
        *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)(t22 + 1);
        if ((int)(t22 + 1) >= (int)(t23 + t21)) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 2196) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)0;
        }
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 2176) = (ts4_word)-1;
        *(unsigned char *)((char *)(ts4_word)(a0) + 2173) = (unsigned char)1;
    }
    t25 = *(ts4_word *)((char *)(ts4_word)(a0) + 1268);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1268) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1264)) + t25);
    return 0;
}

/* Swing_DLL.xex 0x883814B8: if_call_seq ts4_if_get_u8_off50_88381458, lbl_8802BEAC, fn_883296A0, u8@-0x1, ts4_memset, lbl_88C922E4 */
ts4_word ts4_if_call_seq_ts4_if_get_u8_off50_88381458_883814B8(ts4_word a0, int a1, ts4_word a2, int a3, ts4_word a4)
{
    int t1;

    if ((int)a1 >= 0 && (int)a1 < 4) {
        t1 = ts4_if_get_u8_off50_88381458((ts4_word)a0);
        if ((int)t1 == 0) {
            if ((ts4_word)a2 != 0 && (int)a3 >= 1) {
                fn_883296A0((ts4_word)a2, (ts4_word)(ts4_word)lbl_8802BEAC, (ts4_word)(a3 + -1));
                *(unsigned char *)((char *)(ts4_word)((a2 + a3)) + -1) = (unsigned char)0;
            }
            if ((ts4_word)a4 != 0) {
                ts4_memset((ts4_word)a4, (ts4_word)0, (ts4_word)16);
                *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_88C922E4));
            }
            return 0;
        }
        return t1;
    }
    return 37;
}

/* Swing_DLL.xex 0x88385DD0: if_call_seq u32@0x24, u32@0x24, u32@0x30c, u32@0x30c, u32@0x300, u32@0x300 */
ts4_word ts4_if_call_seq_u32_off24_88385DD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p31;
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;
    unsigned char t28;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        p31 = (ts4_word)37;
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((ts4_word)(t2 & 0x10) != 0) {
            *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)1;
        } else {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 780);
            if ((ts4_word)t4 != 0) {
                fn_883332F0((ts4_word)t4, (ts4_word)a1);
                *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 0)) == 0);
            } else {
                t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 768);
                if ((ts4_word)t6 != 0) {
                    fn_883332F0((ts4_word)t6, (ts4_word)a1);
                    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 0)) == 0);
                } else {
                    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 396);
                    if ((ts4_word)t8 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)) != 0) {
                        fn_88389CD8((ts4_word)t8, (ts4_word)a1);
                        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 0)) == 0);
                    } else {
                        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
                    }
                }
            }
        }
        t28 = *(unsigned char *)((char *)(ts4_word)(a1) + 0);
        if ((ts4_word)t28 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) & 0xffffffef) & 0xffffffbf);
        }
        p31 = (ts4_word)0;
    }
    return p31;
}

/* Swing_DLL.xex 0x88402048: loop_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x10, ts4_tailcall_memcpy_88421450, u32@0x1c */
ts4_word ts4_loop_call_seq_u32_off0_88402048(ts4_word a0, ts4_word a1)
{
    ts4_word c6;
    ts4_word lv7;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    int t4;
    ts4_word t5;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16);
    t5 = ts4_tailcall_memcpy_88421450((ts4_word)t3, (ts4_word)t2, (ts4_word)((t4 + (t4 << 1)) << 4));
    if ((int)t4 > 0) {
        c6 = (ts4_word)t4;
        lv7 = (ts4_word)0;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28))) + lv7) = (ts4_word)2;
            p9 = (ts4_word)(lv7 + 4);
            lv7 = p9;
        } while (--c6 != 0);
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    return t5;
}

/* Swing_DLL.xex 0x8841B958: if_get u8@lbl_88CAD334, lbl_8803DB48, memcpy, vcall, fn_8841B498, lbl_8803DC28 */
ts4_word ts4_if_get_u8_lbl_88CAD334_8841B958(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[58];
    unsigned char t1;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t19;

    t1 = *(unsigned char *)lbl_88CAD334;
    if ((ts4_word)t1 == 0) {
        if ((ts4_word)a0 != 0) {
            fn_8841B498((ts4_word)a0);
            if ((ts4_word)a1 != 0) {
                t7 = fn_8841A740((ts4_word)a1);
                ts4_if_call_seq_u32_lbl_88CACF08_8841C3A0((ts4_word)t7);
                t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                t11 = fn_8841A510((ts4_word)t10, (ts4_word)8, (ts4_word)21);
                *(unsigned short *)((char *)(ts4_word)(t11) + 4) = (unsigned short)8;
                *(ts4_word *)((char *)(ts4_word)(t11) + 0) = (ts4_word)(ts4_word)lbl_8803DAB8;
                *(unsigned short *)((char *)(ts4_word)(t11) + 6) = (unsigned short)1;
                fn_88189D98((ts4_word)t11);
                t14 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                t15 = fn_8841A510((ts4_word)t14, (ts4_word)40, (ts4_word)21);
                *(unsigned short *)((char *)(ts4_word)(t15) + 4) = (unsigned short)40;
                t16 = ts4_call_seq_lbl_8803DAE8_8841BEF0((ts4_word)t15, (ts4_word)a2, (ts4_word)a3);
                t17 = fn_8841BBC8((ts4_word)t16);
                fn_8841B6C0((ts4_word)t17);
                t19 = *(ts4_word *)lbl_88CAD330;
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t19) + 0))) + 12))))((ts4_word)t19);
                *(unsigned char *)lbl_88CAD334 = (unsigned char)1;
                return 0;
            }
            memcpy((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803DC28, (ts4_word)120);
            ((ts4_word (*)(ts4_word, ts4_word))(a2))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
            return 1;
        }
        memcpy((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803DB48, (ts4_word)220);
        ((ts4_word (*)(ts4_word, ts4_word))(a2))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88431DB0: if_call_seq ts4_get_u32_off0_88428B30, lbl_880E1DE4, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, u32@0x4, ts4_get_u32_off0_8841EAC8 */
ts4_word ts4_if_call_seq_ts4_get_u32_off0_88428B30_88431DB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc50[2];
    ts4_word loc68[2];
    ts4_word loc70[4];
    ts4_word t3;
    ts4_word t5;
    int t6;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    ts4_word t8;
    int t9;
    ts4_word t18;
    ts4_word t11;
    int t12;
    ts4_word t16;
    ts4_word t14;

    (void)a0;
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880E1DE4);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t5 = ts4_get_u32_off0_8841EAC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t6 = fn_884210E8((ts4_word)t5, (ts4_word)(ts4_word)lbl_8803ECB0);
    if ((int)t6 == 0) {
        ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1);
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)lbl_880E1DE4);
        t21 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc70[0]);
        t22 = ts4_get_u32_off8_88426140((ts4_word)t21);
        t23 = ts4_find_entry_by_name_884278D0((ts4_word)t22, (ts4_word)(ts4_word)lbl_8803BADC, (ts4_word)(ts4_word)&loc50[0]);
        t24 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t24;
        return t23;
    }
    t8 = ts4_get_u32_off0_8841EAC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t9 = fn_884210E8((ts4_word)t8, (ts4_word)(ts4_word)lbl_8803ECD0);
    if ((int)t9 == 0) {
        ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
        t18 = fn_88431D40((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803BABC);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t18;
        return t18;
    }
    t11 = ts4_get_u32_off0_8841EAC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    t12 = fn_884210E8((ts4_word)t11, (ts4_word)(ts4_word)lbl_8803EC94);
    if ((int)t12 == 0) {
        ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
        t16 = fn_88431D40((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803BA9C);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t16;
        return t16;
    }
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t14 = fn_88431D40((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803BAF8);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)t14;
    return t14;
}

/* Swing_DLL.xex 0x88434D10: loop_call_seq lbl_88048118, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, lbl_8803CB7C, u32@0x0 */
ts4_word ts4_loop_call_seq_lbl_88048118_88434D10(ts4_word a0, ts4_word a1)
{
    ts4_word lv14;
    ts4_word lv15;
    ts4_word p22;
    ts4_word p23;
    ts4_word p25;
    ts4_word loc68[2];
    ts4_word loc80[2];
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc50[2];
    ts4_word loc70[2];
    ts4_word loc78[2];
    ts4_word t3;
    int t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t19;
    ts4_word t20;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88048118);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc80[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88048118);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB7C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB7C);
    t7 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
    ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t10 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0]);
    t11 = ts4_get_u32_off4_88426138((ts4_word)t10);
    loc50[1] = (ts4_word)t11;
    t12 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc60[0]);
    t13 = ts4_get_u32_off4_88426138((ts4_word)t12);
    p25 = (ts4_word)t13;
    if ((int)t4 > 0) {
        lv14 = (ts4_word)(t8 + -4);
        lv15 = (ts4_word)t4;
        do {
            loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv14 + 4)) + 0));
            ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803CB5C);
            ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803CB5C);
            t19 = ts4_index_u16_array_at_field0_88428A08((ts4_word)(ts4_word)&loc70[0], (ts4_word)0);
            t20 = ts4_index_u16_array_at_field0_88428A08((ts4_word)(ts4_word)&loc78[0], (ts4_word)0);
            *(unsigned short *)((char *)(ts4_word)(t20) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(t19) + 0));
            p22 = (ts4_word)(lv14 + 4);
            p23 = (ts4_word)(lv15 + -1);
            lv14 = p22;
            lv15 = p23;
        } while ((int)p23 != 0);
        p25 = (ts4_word)t20;
    }
    return p25;
}

/* Swing_DLL.xex 0x88473758: if_get u32@0x8, u32@0x84, fn_88474120, u32@0xd0, u32@0x40, vcall */
ts4_word ts4_if_get_u32_off8_88473758(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[6];
    int t1;
    float t7;
    float t8;
    float t9;
    ts4_word t10;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        t7 = *(float *)((char *)(ts4_word)(a1) + 0);
        t8 = *(float *)((char *)(ts4_word)(a1) + 4);
        loc50[1] = (ts4_word)a0;
        t9 = *(float *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)24;
        *(float *)((char *)loc50 + 8) = t7;
        *(float *)((char *)loc50 + 12) = t8;
        *(float *)((char *)loc50 + 16) = t9;
        t10 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p11 = (ts4_word)t10;
    } else {
        fn_88474120((ts4_word)a0);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 64))))((ts4_word)(a0 + 208), (ts4_word)a1);
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x884737F8: if_get u32@0x8, u32@0x84, fn_88474120, u32@0xd0, u32@0x44, vcall */
ts4_word ts4_if_get_u32_off8_884737F8(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[6];
    int t1;
    float t7;
    float t8;
    float t9;
    ts4_word t10;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        t7 = *(float *)((char *)(ts4_word)(a1) + 0);
        t8 = *(float *)((char *)(ts4_word)(a1) + 4);
        loc50[1] = (ts4_word)a0;
        t9 = *(float *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)25;
        *(float *)((char *)loc50 + 8) = t7;
        *(float *)((char *)loc50 + 12) = t8;
        *(float *)((char *)loc50 + 16) = t9;
        t10 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p11 = (ts4_word)t10;
    } else {
        fn_88474120((ts4_word)a0);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 68))))((ts4_word)(a0 + 208), (ts4_word)a1);
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x88473898: if_get u32@0x8, u32@0x84, fn_88474120, u32@0xd0, u32@0x48, vcall */
ts4_word ts4_if_get_u32_off8_88473898(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[6];
    int t1;
    float t7;
    float t8;
    float t9;
    ts4_word t10;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        t7 = *(float *)((char *)(ts4_word)(a1) + 0);
        t8 = *(float *)((char *)(ts4_word)(a1) + 4);
        loc50[1] = (ts4_word)a0;
        t9 = *(float *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)26;
        *(float *)((char *)loc50 + 8) = t7;
        *(float *)((char *)loc50 + 12) = t8;
        *(float *)((char *)loc50 + 16) = t9;
        t10 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p11 = (ts4_word)t10;
    } else {
        fn_88474120((ts4_word)a0);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 72))))((ts4_word)(a0 + 208), (ts4_word)a1);
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x88473938: if_get u32@0x8, u32@0x84, fn_88474120, u32@0xd0, u32@0x50, vcall */
ts4_word ts4_if_get_u32_off8_88473938(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[6];
    int t1;
    float t7;
    float t8;
    float t9;
    ts4_word t10;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 132)) != 0) {
        t7 = *(float *)((char *)(ts4_word)(a1) + 0);
        t8 = *(float *)((char *)(ts4_word)(a1) + 4);
        loc50[1] = (ts4_word)a0;
        t9 = *(float *)((char *)(ts4_word)(a1) + 8);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)28;
        *(float *)((char *)loc50 + 8) = t7;
        *(float *)((char *)loc50 + 12) = t8;
        *(float *)((char *)loc50 + 16) = t9;
        t10 = ts4_get_u32_off7c_8846AA28((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p11 = (ts4_word)t10;
    } else {
        fn_88474120((ts4_word)a0);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 208))) + 80))))((ts4_word)(a0 + 208), (ts4_word)a1);
        p11 = (ts4_word)t6;
    }
    return p11;
}

/* Swing_DLL.xex 0x8848ABC8: if_call_seq u32@0x10, u32@0x14, u32@0x8, ts4_traced_t3_8848D648, u16@0x1f4, ts4_traced_t2_8848C968 */
ts4_word ts4_if_call_seq_u32_off10_8848ABC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word p10;
    ts4_word loc50[10];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    unsigned short t5;
    ts4_word t6;
    unsigned short t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)-1;
    loc50[1] = (ts4_word)a2;
    loc50[2] = (ts4_word)t1;
    loc50[3] = (ts4_word)t2;
    loc50[5] = (ts4_word)a0;
    loc50[6] = (ts4_word)a1;
    t4 = ts4_traced_t3_8848D648((ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
    t5 = *(unsigned short *)((char *)(ts4_word)(t1) + 500);
    p7 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = ts4_traced_t2_8848C968((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    t8 = *(unsigned short *)((char *)(ts4_word)(t2) + 500);
    p10 = (ts4_word)p7;
    if ((ts4_word)t8 != 0) {
        t9 = ts4_traced_t2_8848C968((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x8848B080: if_call_seq u32@0x58, u32@0x5c, u32@0xc, ts4_traced_t3_8848D648, u16@0x1f4, ts4_traced_t2_8848C968 */
ts4_word ts4_if_call_seq_u32_off58_8848B080(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word p10;
    ts4_word loc50[10];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    unsigned short t5;
    ts4_word t6;
    unsigned short t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    loc50[6] = (ts4_word)a1;
    loc50[5] = (ts4_word)a0;
    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)-1;
    loc50[1] = (ts4_word)a2;
    loc50[2] = (ts4_word)t1;
    loc50[3] = (ts4_word)t2;
    t4 = ts4_traced_t3_8848D648((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)(ts4_word)&loc50[0]);
    t5 = *(unsigned short *)((char *)(ts4_word)(t1) + 500);
    p7 = (ts4_word)t4;
    if ((ts4_word)t5 != 0) {
        t6 = ts4_traced_t2_8848C968((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
        p7 = (ts4_word)t6;
    }
    t8 = *(unsigned short *)((char *)(ts4_word)(t2) + 500);
    p10 = (ts4_word)p7;
    if ((ts4_word)t8 != 0) {
        t9 = ts4_traced_t2_8848C968((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
        p10 = (ts4_word)t9;
    }
    return p10;
}
