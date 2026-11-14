/* Loader_DLL.xex 0x832DBE78-0x83354368, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

ts4l_word RtlEnterCriticalSection();
ts4l_word RtlLeaveCriticalSection();
ts4l_word fn_830AFD98();
ts4l_word fn_830AFEA0();
ts4l_word fn_830B3700();
ts4l_word fn_83286398();
ts4l_word fn_832863B0();
ts4l_word fn_8328B5B0();
ts4l_word fn_8328B5B8();
ts4l_word fn_832A1198();
ts4l_word fn_832D5368();
ts4l_word fn_832DBAD0();
ts4l_word fn_83319FF8();
ts4l_word fn_8331AB00();
ts4l_word fn_8331BFD8();
ts4l_word fn_8331C4C0();
ts4l_word fn_8331CB20();
ts4l_word fn_8331D100();
ts4l_word fn_8331D2F0();
ts4l_word fn_833201C8();
ts4l_word fn_8332B0D8();
ts4l_word fn_8332B230();
ts4l_word fn_833504E0();
ts4l_word fn_83350838();
ts4l_word fn_83350910();
ts4l_word fn_833509D0();
ts4l_word fn_83351900();
ts4l_word fn_833519E0();
ts4l_word fn_83352880();
ts4l_word fn_833539A0();
ts4l_word fn_8336E060();
ts4l_word fn_83379CC8();
ts4l_word fn_833A8160();
ts4l_word fn_833AC790();
ts4l_word fn_833B2078();
ts4l_word fn_833B4730();
ts4l_word fn_833B7440();
ts4l_word fn_833E3A30();
ts4l_word fn_833E74C0();
ts4l_word fn_8340CE90();
ts4l_word fn_834162C8();
ts4l_word fn_83417600();

/* Loader_DLL.xex 0x832DBE78: if_call_seq fn_832DBAD0, fn_832863B0 */
ts4l_word ts4l_if_call_seq_fn_832DBAD0_832DBE78(ts4l_word a0)
{
    if ((ts4l_word)a0 == 0) {
        return 1;
    }
    fn_832DBAD0((ts4l_word)a0);
    fn_832863B0((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x832DC218: if_call_seq fn_832DBAD0, fn_832863B0 */
ts4l_word ts4l_if_call_seq_fn_832DBAD0_832DC218(ts4l_word a0)
{
    if ((ts4l_word)a0 == 0) {
        return 1;
    }
    fn_832DBAD0((ts4l_word)a0);
    fn_832863B0((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8331A520: if_call_seq fn_83286398, fn_8336E060, fn_83379CC8, u32@0x0, fn_83319FF8, u32@0x0 */
ts4l_word ts4l_if_call_seq_fn_83286398_8331A520(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word p6;
    ts4l_word t1;
    int t4;

    t1 = fn_83286398((ts4l_word)14668, (ts4l_word)0);
    if ((ts4l_word)t1 == 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)1;
        return t1;
    }
    fn_8336E060((ts4l_word)t1);
    fn_83379CC8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)t1, (ts4l_word)a3);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p6 = (ts4l_word)t1;
    if ((int)t4 != 0) {
        fn_83319FF8((ts4l_word)t1);
        p6 = (ts4l_word)0;
    }
    return p6;
}

/* Loader_DLL.xex 0x8331D3E8: if_get u32@0x3d10, u32@0x18, u32@0xf8c, u32@0xf8c, u32@0x18, u32@0x18 */
ts4l_word ts4l_if_get_u32_off3d10_8331D3E8(ts4l_word a0)
{
    int t1;
    int t7;
    int t4;
    int t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 15632);
    if ((int)t1 != 0) {
        t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
        if ((int)t7 != 0) {
            return fn_8331AB00((ts4l_word)a0);
        }
        return fn_8331CB20((ts4l_word)a0);
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3980);
    if ((int)t4 != 0) {
        return fn_8331C4C0((ts4l_word)a0);
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    if ((int)t6 != 0) {
        return fn_8331AB00((ts4l_word)a0);
    }
    return fn_8331BFD8((ts4l_word)a0);
}

/* Loader_DLL.xex 0x83321508: call_seq fn_8331D100, fn_8331D2F0, fn_833201C8 */
ts4l_word ts4l_call_seq_fn_8331D100_83321508(ts4l_word a0)
{
    fn_8331D100((ts4l_word)a0, (ts4l_word)0);
    fn_8331D2F0((ts4l_word)a0, (ts4l_word)1);
    fn_833201C8((ts4l_word)a0, (ts4l_word)2);
    return 0;
}

/* Loader_DLL.xex 0x8332B318: loop_get u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x0 */
ts4l_word ts4l_loop_get_u32_off10_8332B318(ts4l_word a0, ts4l_word a1, int a2)
{
    ts4l_word c4;
    ts4l_word lv5;
    ts4l_word p7;
    ts4l_word p8;
    ts4l_word t3;

    if ((ts4l_word)a1 != 0 && (int)a2 < (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 16))) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
        p8 = (ts4l_word)t3;
        if ((int)a2 > 0) {
            c4 = (ts4l_word)a2;
            lv5 = (ts4l_word)t3;
            do {
                p7 = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(lv5) + 0));
                lv5 = p7;
            } while (--c4 != 0);
            p8 = (ts4l_word)lv5;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(p8) + 4));
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x8332B360: loop_call_seq u32@0xc, u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0x4 */
ts4l_word ts4l_loop_call_seq_u32_offc_8332B360(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word lv9;
    ts4l_word p28;
    ts4l_word p43;
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t10;
    ts4l_word t13;
    ts4l_word t16;
    ts4l_word t20;
    ts4l_word t22;
    ts4l_word t23;
    ts4l_word t24;
    ts4l_word t25;
    ts4l_word t26;
    ts4l_word t40;
    ts4l_word t41;
    ts4l_word t42;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    if ((ts4l_word)t1 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 16)) > 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 0);
        t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 0);
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)t4;
        if ((ts4l_word)t4 == 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 4) = (ts4l_word)0;
        }
        t5 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 8);
        t6 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 4);
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 0) = (ts4l_word)t5;
        t7 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 12);
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)t3;
        if ((ts4l_word)t7 == 0) {
            *(ts4l_word *)((char *)(ts4l_word)(t1) + 12) = (ts4l_word)t3;
        }
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 16) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 16)) + -1);
        lv9 = (ts4l_word)t6;
        while ((ts4l_word)lv9 != 0) {
            t10 = *(ts4l_word *)((char *)(ts4l_word)(lv9) + 12);
            if ((ts4l_word)t10 != 0) {
                fn_8328B5B0((ts4l_word)a0, (ts4l_word)t10);
                *(ts4l_word *)((char *)(ts4l_word)(lv9) + 12) = (ts4l_word)0;
            }
            t13 = *(ts4l_word *)((char *)(ts4l_word)(lv9) + 16);
            if ((ts4l_word)t13 != 0) {
                fn_8328B5B0((ts4l_word)a0, (ts4l_word)t13);
                *(ts4l_word *)((char *)(ts4l_word)(lv9) + 16) = (ts4l_word)0;
            }
            t16 = *(ts4l_word *)((char *)(ts4l_word)(lv9) + 20);
            if ((ts4l_word)t16 != 0) {
                fn_8328B5B0((ts4l_word)a0, (ts4l_word)t16);
                *(ts4l_word *)((char *)(ts4l_word)(lv9) + 20) = (ts4l_word)0;
            }
            fn_8328B5B0((ts4l_word)a0, (ts4l_word)lv9);
            t20 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
            if ((ts4l_word)t20 == 0 || (int)(*(ts4l_word *)((char *)(ts4l_word)(t20) + 16)) <= 0) {
                break;
            }
            t22 = *(ts4l_word *)((char *)(ts4l_word)(t20) + 0);
            t23 = *(ts4l_word *)((char *)(ts4l_word)(t22) + 0);
            *(ts4l_word *)((char *)(ts4l_word)(t20) + 0) = (ts4l_word)t23;
            if ((ts4l_word)t23 == 0) {
                *(ts4l_word *)((char *)(ts4l_word)(t20) + 4) = (ts4l_word)0;
            }
            t24 = *(ts4l_word *)((char *)(ts4l_word)(t20) + 8);
            t25 = *(ts4l_word *)((char *)(ts4l_word)(t22) + 4);
            *(ts4l_word *)((char *)(ts4l_word)(t22) + 0) = (ts4l_word)t24;
            *(ts4l_word *)((char *)(ts4l_word)(t20) + 8) = (ts4l_word)t22;
            t26 = *(ts4l_word *)((char *)(ts4l_word)(t20) + 12);
            if ((ts4l_word)t26 == 0) {
                *(ts4l_word *)((char *)(ts4l_word)(t20) + 12) = (ts4l_word)t22;
            }
            *(ts4l_word *)((char *)(ts4l_word)(t20) + 16) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t20) + 16)) + -1);
            p28 = (ts4l_word)t25;
            lv9 = p28;
        }
    }
    t40 = fn_8332B0D8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 12)));
    t41 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 12);
    p43 = (ts4l_word)t40;
    if ((ts4l_word)t41 != 0) {
        t42 = fn_8328B5B0((ts4l_word)a0, (ts4l_word)t41);
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)0;
        p43 = (ts4l_word)t42;
    }
    return p43;
}

/* Loader_DLL.xex 0x8332B4C0: if_get u32@0xc, u32@0x10, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_get_u32_offc_8332B4C0(ts4l_word a0, ts4l_word a1, int a2)
{
    ts4l_word t1;
    int t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 16);
    if ((int)t2 != 0 && (int)a2 <= (int)(t2 + -1)) {
        if ((int)a2 >= 0 || (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)) == (int)t2) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)) + -1);
        }
        return fn_8332B230((ts4l_word)t1, (ts4l_word)a1);
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x8332DD50: if_call_seq u32@0x0, u32@0x8, u32@0x6070, fn_8328B5B0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_8332DD50(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    p5 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 8)) == 0) {
        t4 = fn_8328B5B0((ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 24688)) + 8), (ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
        p5 = (ts4l_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8332DDA8: if_call_seq u32@0x0, u32@0x6070, fn_8328B5B0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_8332DDA8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 0);
    p4 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        t3 = fn_8328B5B0((ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 24688)) + 8), (ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8333D520: loop_get u16@-0x2, u16@0x0, u16@0x2, u16@-0x4, u16@-0x4, u16@-0x2 */
ts4l_word ts4l_loop_get_u16_0x2_8333D520(ts4l_word a0, ts4l_word a1)
{
    ts4l_word c1;
    ts4l_word lv2;
    ts4l_word lv3;
    ts4l_word p8;
    ts4l_word p9;
    unsigned short t4;
    unsigned short t5;
    unsigned short t6;
    unsigned short t7;

    c1 = (ts4l_word)8;
    lv2 = (ts4l_word)1;
    lv3 = (ts4l_word)a0;
    do {
        t4 = *(unsigned short *)((char *)(ts4l_word)(lv3) + -2);
        t5 = *(unsigned short *)((char *)(ts4l_word)(lv3) + 0);
        t6 = *(unsigned short *)((char *)(ts4l_word)(lv3) + 2);
        t7 = *(unsigned short *)((char *)(ts4l_word)(lv3) + -4);
        *(unsigned short *)((char *)(ts4l_word)(lv3) + -4) = (unsigned short)((int)(((((((short)t7) << 3) - ((short)t7)) + ((short)t6)) + lv2) + 3) >> 3);
        *(unsigned short *)((char *)(ts4l_word)(lv3) + -2) = (unsigned short)((int)(((((((((short)t4) << 3) - ((short)t4)) - ((short)t7)) - lv2) + ((short)t5)) + ((short)t6)) + 4) >> 3);
        *(unsigned short *)((char *)(ts4l_word)(lv3) + 0) = (unsigned short)((int)(((((((((short)t5) << 3) - ((short)t5)) - ((short)t6)) + ((short)t4)) + ((short)t7)) + lv2) + 3) >> 3);
        *(unsigned short *)((char *)(ts4l_word)(lv3) + 2) = (unsigned short)((int)(((((((short)t6) << 3) - ((short)t6)) - lv2) + ((short)t7)) + 4) >> 3);
        p8 = (ts4l_word)(lv2 ^ 1);
        p9 = (ts4l_word)((a1 << 1) + lv3);
        lv2 = p8;
        lv3 = p9;
    } while (--c1 != 0);
    return lv3;
}

/* Loader_DLL.xex 0x8333E5D8: if_call_seq u32@0x0, u32@0x4, fn_833E3A30, u32@0x0, fn_833E74C0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_8333E5D8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p6 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)) << 2));
        t5 = fn_833E74C0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)));
        p6 = (ts4l_word)t5;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    return p6;
}

/* Loader_DLL.xex 0x8333E6C0: if_call_seq u32@0x0, u32@0x4, fn_833E3A30, u32@0x0, fn_833E74C0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off0_8333E6C0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p6 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)) << 2));
        t5 = fn_833E74C0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)));
        p6 = (ts4l_word)t5;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    return p6;
}

/* Loader_DLL.xex 0x8334FA88: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_8334FA88(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_83286398((ts4l_word)a0, (ts4l_word)0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x83350980: if_get u32@0xf6c, u32@0x120, u32@0x120, u32@0x3cb0 */
ts4l_word ts4l_if_get_u32_offf6c_83350980(ts4l_word a0)
{
    int t1;
    int t3;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3948);
    if ((int)t1 != 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 288);
        if (((int)t3 != 1 && (int)t3 != 2) && (int)t3 != 4) {
            if ((int)t3 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 15536)) == 7) {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x83351A48: if_call_seq u32@0x120, fn_833504E0, fn_833509D0 */
ts4l_word ts4l_if_call_seq_u32_off120_83351A48(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word p8;
    ts4l_word p9;
    int t1;
    int t4;
    ts4l_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if ((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368));
        if ((int)t4 == 0 || (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 288)) != 4) {
            fn_833504E0((ts4l_word)a0);
            t7 = fn_833509D0((ts4l_word)a0, (ts4l_word)a1);
            p8 = (ts4l_word)t7;
        } else {
            p8 = (ts4l_word)0;
        }
        p9 = (ts4l_word)p8;
    } else {
        p9 = (ts4l_word)0;
    }
    return p9;
}

/* Loader_DLL.xex 0x83351AE0: if_call_seq u32@0x120, fn_83351900, u32@0x54c8, fn_833519E0, fn_83350838, fn_833509D0 */
ts4l_word ts4l_if_call_seq_u32_off120_83351AE0(ts4l_word a0, ts4l_word a1)
{
    int t1;
    int t4;
    int t7;
    ts4l_word t11;
    int t12;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if ((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368));
        if ((int)t4 == 0 || (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 288)) != 4) {
            fn_83351900((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)1);
            t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 21704);
            if ((int)t7 == 1) {
                fn_833519E0((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)0);
            }
            fn_83350838((ts4l_word)a0);
            t11 = fn_833509D0((ts4l_word)a0, (ts4l_word)a1);
            t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 21704);
            if ((int)t12 == 1) {
                fn_833519E0((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)1);
            }
            return t11;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83351BB8: if_call_seq u32@0xea4, u32@0xea4, fn_83350910, fn_833509D0 */
ts4l_word ts4l_if_call_seq_u32_offea4_83351BB8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word p8;
    ts4l_word p9;
    int t1;
    ts4l_word t5;
    ts4l_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if (((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368))) == 0) {
        t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3748);
        if ((ts4l_word)t5 == 0) {
            p8 = (ts4l_word)1;
        } else {
            fn_83350910((ts4l_word)a0);
            t7 = fn_833509D0((ts4l_word)a0, (ts4l_word)a1);
            p8 = (ts4l_word)t7;
        }
        p9 = (ts4l_word)p8;
    } else {
        p9 = (ts4l_word)0;
    }
    return p9;
}

/* Loader_DLL.xex 0x83351D78: call_seq fn_832A1198, fn_833A8160 */
ts4l_word ts4l_call_seq_fn_832A1198_83351D78(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[1];
    ts4l_word loc54[1];
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;

    fn_832A1198((ts4l_word)(a0 + 15984), (ts4l_word)a2, (ts4l_word)(ts4l_word)&loc54[0], (ts4l_word)(ts4l_word)&loc50[0]);
    t2 = loc50[0];
    t3 = loc54[0];
    t4 = fn_833A8160((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)t3, (ts4l_word)t2);
    return t4;
}

/* Loader_DLL.xex 0x83351DD0: if_get fn_833AC790 */
ts4l_word ts4l_if_get_fn_833AC790_83351DD0(ts4l_word a0, ts4l_word a1)
{
    int t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if (((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368))) == 0) {
        return fn_833AC790((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1);
    }
    return 0;
}

/* Loader_DLL.xex 0x83351E20: if_call_seq u32@0x120, u32@0x3cb0, fn_832D5368 */
ts4l_word ts4l_if_call_seq_u32_off120_83351E20(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    int t1;
    int t3;
    int t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if ((int)t1 == 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368));
        if ((int)t3 == 0 || (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 288)) != 4) {
            t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372));
            if ((int)t5 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 15536)) == 7) {
                fn_832D5368();
            }
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x83352090: if_get u32@0x54c8, fn_833B2078 */
ts4l_word ts4l_if_get_u32_off54c8_83352090(ts4l_word a0, ts4l_word a1)
{
    int t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if (((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368))) == 0) {
        return fn_833B2078((ts4l_word)a0, (ts4l_word)((((int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 21704)) * 2208) + a0) + 15984), (ts4l_word)a1);
    }
    return 0;
}

/* Loader_DLL.xex 0x833522E0: call_seq fn_832A1198, fn_833B4730 */
ts4l_word ts4l_call_seq_fn_832A1198_833522E0(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[1];
    ts4l_word loc54[1];
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;

    fn_832A1198((ts4l_word)(a0 + 15984), (ts4l_word)a2, (ts4l_word)(ts4l_word)&loc54[0], (ts4l_word)(ts4l_word)&loc50[0]);
    t2 = loc50[0];
    t3 = loc54[0];
    t4 = fn_833B4730((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)t3, (ts4l_word)t2);
    return t4;
}

/* Loader_DLL.xex 0x83352338: if_get fn_833B7440 */
ts4l_word ts4l_if_get_fn_833B7440_83352338(ts4l_word a0, ts4l_word a1)
{
    int t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if (((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368))) == 0) {
        return fn_833B7440((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1);
    }
    return 0;
}

/* Loader_DLL.xex 0x833529E8: if_call_seq fn_83352880 */
ts4l_word ts4l_if_call_seq_fn_83352880_833529E8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if ((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) {
        fn_83352880((ts4l_word)a0, (ts4l_word)(a0 + 15984));
    }
    return 0;
}

/* Loader_DLL.xex 0x83352A38: if_call_seq fn_83352880 */
ts4l_word ts4l_if_call_seq_fn_83352880_83352A38(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45228));
    if (((int)t1 == 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45368))) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45372))) == 0) {
        fn_83352880((ts4l_word)a0, (ts4l_word)(a0 + 15984));
    }
    return 0;
}

/* Loader_DLL.xex 0x83352AA0: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_83352AA0(ts4l_word a0)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_83286398((ts4l_word)a0, (ts4l_word)0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)a0);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x83352D50: if_call_seq u32@0xc, u32@0x10, fn_8328B5B8, u32@0x14, u32@0x10, fn_8328B5B0 */
ts4l_word ts4l_if_call_seq_u32_offc_83352D50(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t5;
    ts4l_word t9;
    ts4l_word t12;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    if ((ts4l_word)t1 != 0) {
        fn_8328B5B8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 16)), (ts4l_word)t1);
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    if ((ts4l_word)t5 != 0) {
        fn_8328B5B0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 16)), (ts4l_word)t5);
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t9 != 0) {
        fn_832863B0((ts4l_word)t9);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    }
    t12 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)44);
    return t12;
}

/* Loader_DLL.xex 0x83352DC8: call_seq u32@0x0, RtlEnterCriticalSection, u32@0x18, u32@0x0, u32@0x18, RtlLeaveCriticalSection */
ts4l_word ts4l_call_seq_u32_off0_83352DC8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t3;
    ts4l_word t4;

    RtlEnterCriticalSection((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)));
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)(t3 + a1);
    RtlLeaveCriticalSection((ts4l_word)t4);
    return (*(ts4l_word *)((char *)(ts4l_word)(a0) + 24));
}

/* Loader_DLL.xex 0x83352E20: call_seq u32@0x0, RtlEnterCriticalSection, u32@0x24, u32@0x1c, u32@0x14, u32@0x1c */
ts4l_word ts4l_call_seq_u32_off0_83352E20(ts4l_word a0)
{
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t8;

    RtlEnterCriticalSection((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0)));
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 36);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 28);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)t4;
    *(ts4l_word *)((char *)(ts4l_word)((t3 << 2)) + t5) = (ts4l_word)0;
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 36));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)-1;
    t8 = RtlLeaveCriticalSection((ts4l_word)t6);
    return t8;
}

/* Loader_DLL.xex 0x83353B50: call_seq fn_834162C8, fn_83417600, u32@0xdac, fn_830B3700 */
ts4l_word ts4l_call_seq_fn_834162C8_83353B50(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t4;

    fn_834162C8((ts4l_word)(a3 << 1), (ts4l_word)4, (ts4l_word)1, (ts4l_word)0, (ts4l_word)0, (ts4l_word)a1);
    fn_83417600((ts4l_word)a1, (ts4l_word)a2);
    t4 = fn_830B3700((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3500)), (ts4l_word)a1);
    return t4;
}

/* Loader_DLL.xex 0x83353BA8: call_seq fn_834162C8, fn_83417600, u32@0xdac, fn_830B3700 */
ts4l_word ts4l_call_seq_fn_834162C8_83353BA8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word t4;

    fn_834162C8((ts4l_word)(a3 << 2), (ts4l_word)4, (ts4l_word)6, (ts4l_word)0, (ts4l_word)0, (ts4l_word)a1);
    fn_83417600((ts4l_word)a1, (ts4l_word)a2);
    t4 = fn_830B3700((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3500)), (ts4l_word)a1);
    return t4;
}

/* Loader_DLL.xex 0x83353D00: loop_call_seq u32@0xdb0, u32@0xdb4, fn_8340CE90, u32@0xdb0, u32@0xdb4, u32@0xdb0 */
ts4l_word ts4l_loop_call_seq_u32_offdb0_83353D00(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t4;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 3504);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 3508);
    if ((int)(t1 - t2) >= 255) {
        do {
            fn_8340CE90((ts4l_word)1);
            t4 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 3504);
            t5 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 3508);
        } while ((int)(t4 - t5) >= 255);
    }
    return ((((int)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 3504)) & 0xff) * 56) + a0) + 3524);
}

/* Loader_DLL.xex 0x83354368: if_call_seq u32@0xdc0, fn_833539A0, u32@0xdac, fn_830AFD98, u32@0xdac, fn_830AFEA0 */
ts4l_word ts4l_if_call_seq_u32_offdc0_83354368(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p7;
    ts4l_word loc50[8];
    ts4l_word t1;
    ts4l_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3520);
    p7 = (ts4l_word)a0;
    if ((ts4l_word)t1 != 0) {
        fn_833539A0((ts4l_word)a0, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0, (ts4l_word)t1, (ts4l_word)4);
        fn_830AFD98((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3500)), (ts4l_word)0, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0);
        t6 = fn_830AFEA0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3500)), (ts4l_word)0, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)0);
        p7 = (ts4l_word)t6;
    }
    return p7;
}
