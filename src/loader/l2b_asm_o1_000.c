/* Loader_DLL.xex 0x83114F00-0x83120A18, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Loader_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_83516810[];
extern char fn_83516820[];
extern char fn_83516830[];
extern char fn_83516840[];
extern char lbl_830009E0[];
extern char lbl_830009F8[];
extern char lbl_8352C070[];
extern char lbl_8352F7A0[];
extern char lbl_8352F7A8[];
extern char lbl_8352F7BC[];
extern char lbl_8352F7D8[];
extern char lbl_8352F8CC[];
extern char lbl_83530FA4[];
extern char lbl_83530FB8[];
extern char lbl_83530FBC[];
extern char lbl_83530FD0[];
extern char lbl_83530FD4[];
extern char lbl_83530FE8[];
extern char lbl_83530FEC[];
extern char lbl_83531000[];
extern char lbl_8353102C[];
extern char lbl_83531048[];
extern char lbl_8353104C[];
extern char lbl_8353105C[];
extern char lbl_83531078[];
extern char lbl_8353107C[];
extern char lbl_83531098[];
extern char lbl_8353109C[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830FD2F8();
ts4_word fn_830FFB68();
ts4_word fn_830FFBE8();
ts4_word fn_83109390();
ts4_word fn_83109520();
ts4_word fn_83111448();
ts4_word fn_83111588();
ts4_word fn_83111970();
ts4_word fn_83112B88();
ts4_word fn_83112C10();
ts4_word fn_831143F8();
ts4_word fn_83114708();
ts4_word fn_83114A28();
ts4_word fn_831152B0();
ts4_word fn_83115368();
ts4_word fn_83116E20();
ts4_word fn_83116E88();
ts4_word fn_83116F28();
ts4_word fn_83117348();
ts4_word fn_83117A90();
ts4_word fn_83117B88();
ts4_word fn_83117C80();
ts4_word fn_83117DA0();
ts4_word fn_83117F00();
ts4_word fn_831186D0();
ts4_word fn_83118B18();
ts4_word fn_83119820();
ts4_word fn_83119928();
ts4_word fn_8311B538();
ts4_word fn_8311C5D0();
ts4_word fn_8311CCA0();
ts4_word fn_8311CCA8();
ts4_word fn_8311D1C0();
ts4_word fn_8311D2F0();
ts4_word fn_8311D4C0();
ts4_word fn_8311DBA0();
ts4_word fn_8311E7C0();
ts4_word fn_8311ECC8();
ts4_word fn_8311EDD0();
ts4_word fn_8311EEC0();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_831403E8();
ts4_word fn_83140408();
ts4_word fn_83140C60();
ts4_word fn_83142508();
ts4_word fn_83144290();
ts4_word fn_83146618();
ts4_word fn_831466E0();
ts4_word fn_8314E0B8();
ts4_word fn_83156690();
ts4_word fn_83156F48();
ts4_word fn_833E4608();
ts4_word fn_833E4920();

/* Loader_DLL.xex 0x83114F00: call_seq fn_83114A28, fn_830FFB68, fn_83109520 */
ts4_word ts4l_call_seq_fn_83114A28_83114F00(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    fn_83114A28((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109520((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    return ((((t3) >> 31) + -1) & t4);
}

/* Loader_DLL.xex 0x831159F0: if_call_seq fn_8311CCA0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8311CCA0_831159F0(ts4_word a0, ts4_word a1)
{

    fn_8311CCA0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83115E50: if_call_seq u32@0x0, fn_830FFB68, fn_83114708, fn_83109390, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83115E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t1;
    int t3;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        p6 = (ts4_word)((2147942400) | 87);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        t1 = fn_830FFB68((ts4_word)a0);
        fn_83114708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
        t3 = fn_83109390((ts4_word)t1, (ts4_word)(ts4_word)&loc60[0]);
        p5 = (ts4_word)t3;
        if ((int)t3 >= 0) {
            t4 = loc50[0];
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t4;
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    }
    return p6;
}

/* Loader_DLL.xex 0x831164E0: if_call_seq u32@lbl_8352F7D8, fn_83111448, fn_83115368 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F7D8_831164E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7D8));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = fn_83115368((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83116610: if_call_seq u32@lbl_8352F7BC, fn_83111448, u32@0x24, u32@0x24, fn_831152B0, u32@lbl_8352F7BC */
ts4_word ts4l_if_call_seq_u32_lbl_8352F7BC_83116610(ts4_word a0)
{
    ts4_word p27;
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t4;
    ts4_word t15;
    ts4_word t16;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t23;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7BC));
    if ((int)t2 == 0) {
        p27 = (ts4_word)((2147942400) | 87);
    } else {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 36);
        if ((ts4_word)t4 != 0) {
            t15 = fn_83111448((ts4_word)t4, (ts4_word)(*(ts4_word *)lbl_8352F7BC));
            if ((ts4_word)t15 != 0) {
                t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 56);
                if ((int)(t16 & 0x3) != 0) {
                    fn_831143F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)42);
                    fn_83109390((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 36)), (ts4_word)(ts4_word)&loc50[0]);
                }
            }
        } else {
            t5 = fn_831152B0((ts4_word)a0);
            if ((int)t5 != 0) {
                t7 = fn_83111448((ts4_word)t5, (ts4_word)(*(ts4_word *)lbl_8352F7BC));
                if ((ts4_word)t7 != 0) {
                    t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 56);
                    if ((int)(t8 & 0x3) != 0) {
                        fn_831143F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)42);
                        fn_83109390((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
                    }
                }
            }
        }
        t23 = *(ts4_word *)((char *)(ts4_word)(t2) + 56);
        if ((int)(t23 & 0x3) != 0) {
            fn_831143F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)42);
            fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        }
        p27 = (ts4_word)0;
    }
    return p27;
}

/* Loader_DLL.xex 0x831167E8: if_call_seq u32@lbl_8352F7A8, fn_83111448, u32@0xe4, u32@0xe4, fn_8311C5D0 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F7A8_831167E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7A8));
    if ((ts4_word)t2 == 0) {
        p7 = (ts4_word)((2150629376) | 22);
    } else {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 228);
        if ((ts4_word)t4 == 0) {
            p6 = (ts4_word)((2147942400) | 87);
        } else {
            t5 = fn_8311C5D0((ts4_word)t4, (ts4_word)a1, (ts4_word)a2);
            p6 = (ts4_word)t5;
        }
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Loader_DLL.xex 0x83116B78: if_call_seq u32@lbl_8352F7A0, fn_83111448, fn_83115368 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F7A0_83116B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 == 0) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7A0));
        if ((ts4_word)t2 == 0) {
            p4 = (ts4_word)((2150629376) | 22);
        } else {
            t3 = fn_83115368((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
            p4 = (ts4_word)t3;
        }
        p5 = (ts4_word)p4;
    }
    return p5;
}

/* Loader_DLL.xex 0x83117F08: if_call_seq fn_83117C80, fn_83117DA0, fn_83117A90, fn_83117B88 */
ts4_word ts4l_if_call_seq_fn_83117C80_83117F08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    ts4_word p9;
    ts4_word t4;
    ts4_word t3;
    ts4_word t2;
    ts4_word t1;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p9 = (ts4_word)0;
    } else {
        if ((ts4_word)a1 >= 1) {
            if ((ts4_word)a1 != 1) {
                if ((ts4_word)a1 >= 3) {
                    if ((ts4_word)a1 != 3) {
                        p5 = (ts4_word)0;
                    } else {
                        t4 = fn_83117B88((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
                        p5 = (ts4_word)t4;
                    }
                    p6 = (ts4_word)p5;
                } else {
                    t3 = fn_83117A90((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
                    p6 = (ts4_word)t3;
                }
                p7 = (ts4_word)p6;
            } else {
                t2 = fn_83117DA0((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
                p7 = (ts4_word)t2;
            }
            p8 = (ts4_word)p7;
        } else {
            t1 = fn_83117C80((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
            p8 = (ts4_word)t1;
        }
        p9 = (ts4_word)p8;
    }
    return p9;
}

/* Loader_DLL.xex 0x83118048: if_call_seq lbl_83530FA4, u32@lbl_8352C070, u32@lbl_83530FB8, u32@lbl_83530FB8, fn_83140408, fn_83516810 */
ts4_word ts4l_if_call_seq_lbl_83530FA4_83118048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    float t3;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)lbl_8352C070;
    t2 = *(ts4_word *)lbl_83530FB8;
    loc50[3] = (ts4_word)t1;
    if ((int)(t2 & 0x1) == 0) {
        *(ts4_word *)lbl_83530FB8 = (ts4_word)(t2 | 1);
        t3 = *(float *)lbl_830009F8;
        *(float *)((char *)loc50 + 0) = t3;
        *(float *)((char *)loc50 + 4) = t3;
        *(float *)((char *)loc50 + 8) = t3;
        fn_83140408((ts4_word)(ts4_word)lbl_83530FA4, (ts4_word)(ts4_word)&loc50[0]);
        fn_833E4920((ts4_word)(ts4_word)fn_83516810);
    }
    t7 = loc50[3];
    fn_833E4608((ts4_word)t7);
    return (ts4_word)lbl_83530FA4;
}

/* Loader_DLL.xex 0x831180D0: if_call_seq lbl_83530FBC, u32@lbl_8352C070, u32@lbl_83530FD0, u32@lbl_83530FD0, fn_83140408, fn_83516820 */
ts4_word ts4l_if_call_seq_lbl_83530FBC_831180D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    float t3;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)lbl_8352C070;
    t2 = *(ts4_word *)lbl_83530FD0;
    loc50[3] = (ts4_word)t1;
    if ((int)(t2 & 0x1) == 0) {
        *(ts4_word *)lbl_83530FD0 = (ts4_word)(t2 | 1);
        t3 = *(float *)lbl_830009E0;
        *(float *)((char *)loc50 + 0) = t3;
        *(float *)((char *)loc50 + 4) = t3;
        *(float *)((char *)loc50 + 8) = t3;
        fn_83140408((ts4_word)(ts4_word)lbl_83530FBC, (ts4_word)(ts4_word)&loc50[0]);
        fn_833E4920((ts4_word)(ts4_word)fn_83516820);
    }
    t7 = loc50[3];
    fn_833E4608((ts4_word)t7);
    return (ts4_word)lbl_83530FBC;
}

/* Loader_DLL.xex 0x83118158: if_call_seq lbl_83530FD4, u32@lbl_83530FE8, u32@lbl_83530FE8, fn_83140C60, fn_83516830, fn_833E4920 */
ts4_word ts4l_if_call_seq_lbl_83530FD4_83118158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[4];
    ts4_word t1;
    float t2;
    float t3;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)lbl_83530FE8;
    if ((int)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_83530FE8 = (ts4_word)(t1 | 1);
        t2 = *(float *)lbl_830009F8;
        t3 = *(float *)lbl_830009E0;
        *(float *)((char *)loc50 + 0) = t2;
        *(float *)((char *)loc50 + 4) = t2;
        *(float *)((char *)loc50 + 8) = t2;
        *(float *)((char *)loc50 + 12) = t3;
        fn_83140C60((ts4_word)(ts4_word)lbl_83530FD4, (ts4_word)(ts4_word)&loc50[0]);
        fn_833E4920((ts4_word)(ts4_word)fn_83516830);
    }
    return (ts4_word)lbl_83530FD4;
}

/* Loader_DLL.xex 0x831181D8: if_call_seq lbl_83530FEC, u32@lbl_83531000, u32@lbl_83531000, fn_831403E8, fn_83516840, fn_833E4920 */
ts4_word ts4l_if_call_seq_lbl_83530FEC_831181D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)lbl_83531000;
    if ((int)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_83531000 = (ts4_word)(t1 | 1);
        fn_831403E8((ts4_word)(ts4_word)lbl_83530FEC, (ts4_word)0);
        fn_833E4920((ts4_word)(ts4_word)fn_83516840);
    }
    return (ts4_word)lbl_83530FEC;
}

/* Loader_DLL.xex 0x831182B0: if_call_seq u32@0x4, fn_83112B88, fn_83117348, u32@0x4, fn_83112C10, fn_83117348 */
ts4_word ts4l_if_call_seq_u32_off4_831182B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p9;
    ts4_word p10;
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    fn_83112B88((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    if ((ts4_word)t3 == 0) {
        fn_83112C10((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc50[0];
        if ((ts4_word)t7 == 0) {
            p9 = (ts4_word)((2147483648) | 16389);
        } else {
            t8 = fn_83117348((ts4_word)t7, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
            p9 = (ts4_word)t8;
        }
        p10 = (ts4_word)p9;
    } else {
        t4 = fn_83117348((ts4_word)t3, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Loader_DLL.xex 0x83118688: if_call_seq fn_83116F28, u32@0xc */
ts4_word ts4l_if_call_seq_fn_83116F28_83118688(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p2;
    int t1;

    (void)a1;
    t1 = fn_83116F28();
    p2 = (ts4_word)t1;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a2;
        p2 = (ts4_word)1;
    }
    return p2;
}

/* Loader_DLL.xex 0x83118738: if_call_seq fn_83116F28, u32@0xc, u32@0xc, fn_83142508, fn_83120540, u32@0xc */
ts4_word ts4l_if_call_seq_fn_83116F28_83118738(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    int t1;
    ts4_word t3;

    (void)a1;
    t1 = fn_83116F28();
    p7 = (ts4_word)t1;
    if ((int)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((ts4_word)t3 != 0) {
            fn_83142508((ts4_word)t3);
            fn_83120540((ts4_word)t3);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a2;
        p7 = (ts4_word)1;
    }
    return p7;
}

/* Loader_DLL.xex 0x83118788: if_call_seq fn_831186D0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_831186D0_83118788(ts4_word a0, ts4_word a1)
{

    fn_831186D0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83119590: if_call_seq fn_83111588, u32@0x30, fn_83118B18 */
ts4_word ts4l_if_call_seq_fn_83111588_83119590(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83111588();
    if ((ts4_word)t1 == 0) {
        p4 = (ts4_word)((2150629376) | 10);
    } else {
        t3 = fn_83118B18((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 48)), (ts4_word)4, (ts4_word)2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x831195E8: if_call_seq fn_83111588, u32@0x34, fn_83118B18 */
ts4_word ts4l_if_call_seq_fn_83111588_831195E8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83111588();
    if ((ts4_word)t1 == 0) {
        p4 = (ts4_word)((2150629376) | 10);
    } else {
        t3 = fn_83118B18((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 52)), (ts4_word)3, (ts4_word)0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83119640: if_call_seq fn_83111588, u32@0x2c, fn_83118B18 */
ts4_word ts4l_if_call_seq_fn_83111588_83119640(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83111588();
    if ((ts4_word)t1 == 0) {
        p4 = (ts4_word)((2150629376) | 10);
    } else {
        t3 = fn_83118B18((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 44)), (ts4_word)1, (ts4_word)0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8311A0D0: if_call_seq fn_83116E20, fn_83119820 */
ts4_word ts4l_if_call_seq_fn_83116E20_8311A0D0(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_83116E20();
    if ((int)t1 == -1) {
        p3 = (ts4_word)0;
    } else {
        t2 = fn_83119820((ts4_word)a0, (ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8311A120: if_call_seq fn_83116E88, fn_83119928 */
ts4_word ts4l_if_call_seq_fn_83116E88_8311A120(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_83116E88();
    if ((int)t1 == -1) {
        p3 = (ts4_word)0;
    } else {
        t2 = fn_83119928((ts4_word)a0, (ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8311B5B8: call_seq u32@0x28, u32@0x2c, fn_83144290, u32@0x18, u32@0x1c, u32@0x20 */
ts4_word ts4l_call_seq_u32_off28_8311B5B8(ts4_word a0)
{
    ts4_word t1;
    float t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    t1 = fn_83144290((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t2 = *(float *)lbl_830009F8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 48) = t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return t1;
}

/* Loader_DLL.xex 0x8311BAB8: if_call_seq u32@0x18, fn_8311B538, u32@0x18, fn_83109390 */
ts4_word ts4l_if_call_seq_u32_off18_8311BAB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_8311B538((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
        t4 = fn_83109390((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)(ts4_word)&loc60[0]);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8311BB58: if_call_seq u32@0x0, fn_8311B538, u32@0x0, fn_83109520 */
ts4_word ts4l_if_call_seq_u32_off0_8311BB58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        fn_8311B538((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t1);
        t4 = fn_83109520((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc60[0]);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8311CED8: loop_call_seq u32@0x4, fn_83120540, u32@0x8, fn_83120540, u32@0xc, fn_83120540 */
ts4_word ts4l_loop_call_seq_u32_off4_8311CED8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p11;
    ts4_word p12;
    ts4_word p14;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p14 = (ts4_word)a0;
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        lv1 = (ts4_word)a1;
        lv2 = (ts4_word)(a0 + -4);
        do {
            fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 4)));
            fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 8)));
            fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 12)));
            fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)((lv2 + 20)) + 0)));
            p11 = (ts4_word)(lv1 + -1);
            p12 = (ts4_word)(lv2 + 20);
            lv1 = p11;
            lv2 = p12;
        } while ((int)p11 != 0);
        t13 = fn_83120540((ts4_word)a0);
        p14 = (ts4_word)t13;
    }
    return p14;
}

/* Loader_DLL.xex 0x8311D228: if_call_seq fn_8311D1C0, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_8311D1C0_8311D228(ts4_word a0)
{
    ts4_word p4;
    int t1;

    t1 = fn_8311D1C0();
    if ((int)t1 == -1) {
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4))));
    }
    return p4;
}

/* Loader_DLL.xex 0x8311D550: if_call_seq lbl_8353102C, RtlEnterCriticalSection, lbl_8353104C, fn_8311D1C0, u32@0x8, u32@0x8 */
ts4_word ts4l_if_call_seq_lbl_8353102C_8311D550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p19;
    int t2;
    int t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p19 = (ts4_word)((2147942400) | 87);
    } else {
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353102C);
        t2 = fn_8311D1C0((ts4_word)(ts4_word)lbl_8353104C, (ts4_word)a0);
        if ((int)t2 > -1) {
            if ((int)t2 == 0) {
                t4 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353104C) + 8);
                if ((int)t4 > 1) {
                    fn_830FFBE8((ts4_word)(ts4_word)lbl_83531048, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353104C) + 4))) + 4))) + 0)));
                } else {
                    fn_83120540((ts4_word)(*(ts4_word *)lbl_83531048));
                    *(ts4_word *)lbl_83531048 = (ts4_word)0;
                }
            }
            fn_8311CCA8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((t2 << 2)) + (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353104C) + 4)))));
            fn_8311D2F0((ts4_word)(ts4_word)lbl_8353104C, (ts4_word)t2);
        }
        RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353102C);
        p19 = (ts4_word)0;
    }
    return p19;
}

/* Loader_DLL.xex 0x8311D988: loop_call_seq lbl_8353105C, RtlEnterCriticalSection, u32@lbl_83531078, u32@0x0, u32@0x10, u32@0x10 */
ts4_word ts4l_loop_call_seq_lbl_8353105C_8311D988(ts4_word a0)
{
    ts4_word lv3;
    ts4_word p8;
    ts4_word t4;
    ts4_word t10;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353105C);
    lv3 = (ts4_word)(*(ts4_word *)lbl_83531078);
    while ((ts4_word)lv3 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        if ((ts4_word)t4 == (ts4_word)a0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 16)) | 1);
        }
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 20));
        lv3 = p8;
    }
    t10 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353105C);
    return t10;
}

/* Loader_DLL.xex 0x8311DE10: if_call_seq u8@lbl_83531098, lbl_8353107C, RtlEnterCriticalSection, fn_831466E0, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_u8_lbl_83531098_8311DE10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    unsigned char t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)lbl_83531098;
    p5 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
        fn_831466E0((ts4_word)t2);
        t4 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8311E038: if_get u16@0x0, u32@0x0, u32@lbl_8352F8CC, fn_830FFBE8, u32@0x0, u32@0x0 */
ts4_word ts4l_if_get_u16_off0_8311E038(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    int t6;
    ts4_word t7;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if (((ts4_word)a0 != 0 && (ts4_word)(*(volatile unsigned short *)((char *)(ts4_word)(a0) + 0)) != 0) && (ts4_word)a1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        t2 = *(volatile ts4_word *)lbl_8352F8CC;
        if ((ts4_word)t2 != 0) {
            t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2, (ts4_word)a0, (ts4_word)a1);
            p9 = (ts4_word)t6;
            if ((int)t6 < 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
                p8 = (ts4_word)t6;
                if ((int)t6 == (int)((2147483648) | 16385)) {
                    t7 = fn_830FFBE8((ts4_word)a1, (ts4_word)a0);
                    p8 = (ts4_word)t7;
                }
                p9 = (ts4_word)p8;
            }
            p10 = (ts4_word)p9;
        } else {
            t3 = fn_830FFBE8((ts4_word)a1, (ts4_word)a0);
            p10 = (ts4_word)t3;
        }
        p11 = (ts4_word)p10;
    } else {
        p11 = (ts4_word)((2147942400) | 87);
    }
    return p11;
}

/* Loader_DLL.xex 0x8311E8C0: if_call_seq fn_8311E7C0, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_8311E7C0_8311E8C0(ts4_word a0)
{
    ts4_word p4;
    int t1;

    t1 = fn_8311E7C0();
    if ((int)t1 == -1) {
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4))));
    }
    return p4;
}

/* Loader_DLL.xex 0x8311F9F8: if_addr lbl_8353107C, RtlEnterCriticalSection, u32@lbl_8353109C, fn_8311E7C0, u32@lbl_8353109C, u32@0x4 */
ts4_word ts4l_if_addr_lbl_8353107C_8311F9F8(ts4_word a0)
{
    ts4_word t3;
    ts4_word t6;
    ts4_word t13;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t3 = fn_8311E7C0((ts4_word)(*(ts4_word *)lbl_8353109C), (ts4_word)a0);
    if ((int)t3 >= 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_8353109C)) + 4))) + (t3 << 2));
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 4))))((ts4_word)t6);
        fn_8311ECC8((ts4_word)(*(ts4_word *)lbl_8353109C), (ts4_word)t3);
    }
    t13 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t13;
}

/* Loader_DLL.xex 0x8311FA70: if_call_seq fn_8311E7C0, fn_8311ECC8 */
ts4_word ts4l_if_call_seq_fn_8311E7C0_8311FA70(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_8311E7C0();
    if ((int)t1 == -1) {
        p3 = (ts4_word)0;
    } else {
        t2 = fn_8311ECC8((ts4_word)a0, (ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8311FC28: if_call_seq fn_8311EDD0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8311EDD0_8311FC28(ts4_word a0, ts4_word a1)
{

    fn_8311EDD0();
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8311FC78: if_call_seq lbl_8353109C, u8@-0x4, u8@-0x4, fn_83146618, fn_8311D4C0, fn_8311EEC0 */
ts4_word ts4l_if_call_seq_lbl_8353109C_8311FC78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word p10;
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;
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
    t1 = *(volatile unsigned char *)((char *)(ts4_word)((ts4_word)lbl_8353109C) + -4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_8353109C) + -4) = (unsigned char)0;
        t2 = fn_83146618();
        t3 = fn_8311D4C0((ts4_word)t2);
        t4 = fn_8311EEC0((ts4_word)t3);
        t5 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353109C) + 0);
        p8 = (ts4_word)t4;
        if ((ts4_word)t5 != 0) {
            fn_8311EDD0((ts4_word)t5);
            t7 = fn_83120540((ts4_word)t5);
            p8 = (ts4_word)t7;
        }
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_8353109C) + 0) = (ts4_word)0;
        p10 = (ts4_word)p8;
    }
    return p10;
}

/* Loader_DLL.xex 0x83120640: if_call_seq fn_83120518, u16@0x0, u16@0x2, u32@0x0, u32@0x4, u32@0x0 */
ts4_word ts4l_if_call_seq_fn_83120518_83120640(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;

    t1 = fn_83120518((ts4_word)8);
    if ((int)t1 == 0) {
        fn_830FD2F8((ts4_word)a0);
        p4 = (ts4_word)0;
    } else {
        *(unsigned short *)((char *)(ts4_word)(t1) + 0) = (unsigned short)a1;
        *(unsigned short *)((char *)(ts4_word)(t1) + 2) = (unsigned short)a2;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
        p4 = (ts4_word)1;
    }
    return p4;
}

/* Loader_DLL.xex 0x831207C8: if_call_seq fn_83156F48, u32@0x0, u32@0x0, fn_83156690, u32@0x0 */
ts4_word ts4l_if_call_seq_fn_83156F48_831207C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p7;
    ts4_word loc50[4];
    int t1;
    ts4_word t3;
    ts4_word t6;

    t1 = fn_83156F48((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0]);
    p7 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        if ((ts4_word)t3 != 0) {
            fn_83156690((ts4_word)t3);
        }
        t6 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t6;
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Loader_DLL.xex 0x83120858: if_call_seq u32@0x8, fn_8314E0B8, u32@0x8, u32@0x84, u32@0x84 */
ts4_word ts4l_if_call_seq_u32_off8_83120858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    p4 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8314E0B8((ts4_word)t1);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 132)) | 1);
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x831208E8: call_seq u32@0xf4, u32@0xf4, fn_83111970, u32@0x0, fn_830FFB68, fn_83117F00 */
ts4_word ts4l_call_seq_u32_offf4_831208E8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 244)) | 2);
    t2 = fn_83111970((ts4_word)a1);
    t4 = fn_830FFB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t5 = fn_83117F00((ts4_word)t4, (ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 244)) & 0xfffffffd);
    return t5;
}

/* Loader_DLL.xex 0x831209C8: if_call_seq u32@0x24, u32@0x0, fn_8311DBA0, u32@0x48, u32@0x48 */
ts4_word ts4l_if_call_seq_u32_off24_831209C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    p6 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t3 = fn_8311DBA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)((2864381952) | 52445));
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 72)) & 0xfffffffd);
        p6 = (ts4_word)t3;
    }
    return p6;
}
