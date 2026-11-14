/* Loader_DLL.xex 0x83227348-0x8328B2A8, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char fn_83259100[];
extern char lbl_8302B4E0[];
extern char lbl_8302B8A0[];
extern char lbl_8302B908[];
extern char lbl_8302BAB0[];
ts4l_word fn_83226FC0();
ts4l_word fn_8322E7C8();
ts4l_word fn_832335F8();
ts4l_word fn_83233950();
ts4l_word fn_83233A38();
ts4l_word fn_83233D68();
ts4l_word fn_83236240();
ts4l_word fn_8324DEA8();
ts4l_word fn_8324E448();
ts4l_word fn_8324E540();
ts4l_word fn_8324F9C8();
ts4l_word fn_8324FF60();
ts4l_word fn_83251168();
ts4l_word fn_832515D8();
ts4l_word fn_832522A8();
ts4l_word fn_832523C8();
ts4l_word fn_83256640();
ts4l_word fn_83256D18();
ts4l_word fn_83257180();
ts4l_word fn_832584D8();
ts4l_word fn_83259BC8();
ts4l_word fn_83259EB8();
ts4l_word fn_83267780();
ts4l_word fn_832678F8();
ts4l_word fn_83268E98();
ts4l_word fn_8326C1B8();
ts4l_word fn_8326C9E0();
ts4l_word fn_8326F390();
ts4l_word fn_8326F6E8();
ts4l_word fn_83272CF8();
ts4l_word fn_83272D18();
ts4l_word fn_83273160();
ts4l_word fn_83273180();
ts4l_word fn_8327C060();
ts4l_word fn_8327E318();
ts4l_word fn_8327EDF8();
ts4l_word fn_8327EF18();
ts4l_word fn_8327F178();
ts4l_word fn_83286398();
ts4l_word fn_8328B3F0();
ts4l_word fn_8329FAF8();
ts4l_word fn_832DA598();
ts4l_word fn_833E3A30();
ts4l_word fn_833E3AD0();
ts4l_word fn_8340D0A0();
ts4l_word fn_8340D830();
ts4l_word fn_834138F0();

/* Loader_DLL.xex 0x83227348: call_seq fn_83226FC0, lbl_8302B4E0, u32@0x2c, u32@0x0, u32@0x30, u32@0x34 */
ts4l_word ts4l_call_seq_fn_83226FC0_83227348(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B4E0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x8322E8F0: call_seq fn_83236240, lbl_8302B8A0, u32@0x0, fn_8322E7C8 */
ts4l_word ts4l_call_seq_fn_83236240_8322E8F0(ts4l_word a0)
{
    fn_83236240((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B8A0;
    fn_8322E7C8((ts4l_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x8322EE88: call_seq fn_83226FC0, u32@0x38, lbl_8302B908, u32@0x3c, u32@0x40, u32@0x0 */
ts4l_word ts4l_call_seq_fn_83226FC0_8322EE88(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302B908;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83233540: call_seq fn_83226FC0, lbl_8302BAB0, u32@0x2c, u32@0x0, u32@0x30, u32@0x34 */
ts4l_word ts4l_call_seq_fn_83226FC0_83233540(ts4l_word a0)
{
    fn_83226FC0((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302BAB0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 56) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 64) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 92) = (ts4l_word)1;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 72) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 80) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 88) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83233768: if_call_seq fn_832335F8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_fn_832335F8_83233768(ts4l_word a0, ts4l_word a1)
{
    fn_832335F8((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32770));
    }
    return a0;
}

/* Loader_DLL.xex 0x83233AE8: if_call_seq fn_83233950, fn_83233950 */
ts4l_word ts4l_if_call_seq_fn_83233950_83233AE8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, int a5, ts4l_word a6)
{
    ts4l_word loc50[4];
    ts4l_word loc60[6];
    ts4l_word t1;

    loc50[0] = (ts4l_word)0;
    loc60[0] = (ts4l_word)0;
    loc60[1] = (ts4l_word)0;
    t1 = fn_83233950((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a6, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)1);
    if ((int)a5 != 0) {
        loc50[1] = (ts4l_word)t1;
        loc50[2] = (ts4l_word)a4;
        loc50[0] = (ts4l_word)1;
        loc60[0] = (ts4l_word)0;
        loc60[1] = (ts4l_word)0;
        fn_83233950((ts4l_word)a0, (ts4l_word)a6, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x83249F00: loop_call_seq u32@0x4c, u16@0x48, u16@0x48, u32@0x0, u32@0xe0, fn_83233D68 */
ts4l_word ts4l_loop_call_seq_u32_off4c_83249F00(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word lv4;
    ts4l_word p9;
    ts4l_word lv18;
    ts4l_word p23;
    ts4l_word t1;
    unsigned short t3;
    ts4l_word t5;
    unsigned short t8;
    ts4l_word t15;
    unsigned short t17;
    ts4l_word t19;
    unsigned short t22;

    (void)a0;
    (void)a2;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 76);
    if ((ts4l_word)t1 != 0) {
        t3 = *(unsigned short *)((char *)(ts4l_word)(a1) + 72);
        if ((ts4l_word)t3 != 0) {
            lv4 = (ts4l_word)0;
            do {
                t5 = *(ts4l_word *)((char *)(ts4l_word)((a1 + 76)) + 0);
                fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)(((lv4 << 3) + t5) + 4));
                t8 = *(unsigned short *)((char *)(ts4l_word)(a1) + 72);
                p9 = (ts4l_word)((lv4 + 1) & 0xffff);
                lv4 = p9;
            } while ((ts4l_word)p9 < (ts4l_word)t8);
        }
        fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)(a1 + 76));
    }
    t15 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 80);
    if ((ts4l_word)t15 != 0) {
        t17 = *(unsigned short *)((char *)(ts4l_word)(a1) + 74);
        if ((ts4l_word)t17 != 0) {
            lv18 = (ts4l_word)0;
            do {
                t19 = *(ts4l_word *)((char *)(ts4l_word)((a1 + 80)) + 0);
                fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)((((int)lv18 * 28) + t19) + 24));
                t22 = *(unsigned short *)((char *)(ts4l_word)(a1) + 74);
                p23 = (ts4l_word)((lv18 + 1) & 0xffff);
                lv18 = p23;
            } while ((ts4l_word)p23 < (ts4l_word)t22);
        }
        fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)(a1 + 80));
    }
    return 0;
}

/* Loader_DLL.xex 0x83249FE0: if_call_seq u32@0x48, u32@0xe0, fn_83233D68, u32@0xe0, fn_83233D68 */
ts4l_word ts4l_if_call_seq_u32_off48_83249FE0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a0;
    (void)a2;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 72);
    if ((ts4l_word)t1 != 0) {
        fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)(t1 + 16));
        fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a3) + 224)), (ts4l_word)11, (ts4l_word)(a1 + 72));
    }
    return 0;
}

/* Loader_DLL.xex 0x8324E980: if_call_seq u32@0x2c, fn_8324DEA8, fn_8324E540, fn_8324E448, u32@0x10, u32@0x48 */
ts4l_word ts4l_if_call_seq_u32_off2c_8324E980(ts4l_word a0)
{
    ts4l_word p10;
    ts4l_word p11;
    ts4l_word p14;
    ts4l_word loc50[4];
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t13;

    loc50[0] = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44));
    fn_8324DEA8();
    fn_8324E540((ts4l_word)a0);
    t4 = fn_8324E448((ts4l_word)a0, (ts4l_word)1);
    t5 = loc50[0];
    t6 = *(ts4l_word *)((char *)(ts4l_word)(t5) + 16);
    p10 = (ts4l_word)t5;
    p11 = (ts4l_word)t4;
    if ((ts4l_word)t6 != 0) {
        t8 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t5) + 72)), (ts4l_word)29, (ts4l_word)(t5 + 16));
        t9 = loc50[0];
        p10 = (ts4l_word)t9;
        p11 = (ts4l_word)t8;
    }
    p14 = (ts4l_word)p11;
    if ((ts4l_word)p10 != 0) {
        t13 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(p10) + 72)), (ts4l_word)29, (ts4l_word)(ts4l_word)&loc50[0]);
        p14 = (ts4l_word)t13;
    }
    return p14;
}

/* Loader_DLL.xex 0x83250370: if_call_seq u32@0x2c, fn_8324F9C8, fn_8324FF60, u32@0x10, u32@0x30, fn_83233D68 */
ts4l_word ts4l_if_call_seq_u32_off2c_83250370(ts4l_word a0)
{
    ts4l_word p9;
    ts4l_word p10;
    ts4l_word p13;
    ts4l_word loc50[4];
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t12;

    loc50[0] = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44));
    fn_8324F9C8();
    t3 = fn_8324FF60((ts4l_word)a0);
    t4 = loc50[0];
    t5 = *(ts4l_word *)((char *)(ts4l_word)(t4) + 16);
    p9 = (ts4l_word)t4;
    p10 = (ts4l_word)t3;
    if ((ts4l_word)t5 != 0) {
        t7 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t4) + 48)), (ts4l_word)30, (ts4l_word)(t4 + 16));
        t8 = loc50[0];
        p9 = (ts4l_word)t8;
        p10 = (ts4l_word)t7;
    }
    p13 = (ts4l_word)p10;
    if ((ts4l_word)p9 != 0) {
        t12 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(p9) + 48)), (ts4l_word)30, (ts4l_word)(ts4l_word)&loc50[0]);
        p13 = (ts4l_word)t12;
    }
    return p13;
}

/* Loader_DLL.xex 0x832519E8: if_call_seq u32@0x2c, fn_83251168, fn_832515D8, u32@0x30, fn_83233D68, u32@0x30 */
ts4l_word ts4l_if_call_seq_u32_off2c_832519E8(ts4l_word a0)
{
    ts4l_word p10;
    ts4l_word p11;
    ts4l_word p12;
    ts4l_word loc50[4];
    int t2;
    int t3;
    ts4l_word t4;
    int t6;
    ts4l_word t7;
    ts4l_word t9;

    loc50[0] = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44));
    t2 = fn_83251168();
    p12 = (ts4l_word)t2;
    if ((int)t2 >= 0) {
        t3 = fn_832515D8((ts4l_word)a0);
        p11 = (ts4l_word)t3;
        if ((int)t3 >= 0) {
            t4 = loc50[0];
            t6 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t4) + 48)), (ts4l_word)31, (ts4l_word)(t4 + 16));
            p10 = (ts4l_word)t6;
            if ((int)t6 >= 0) {
                t7 = loc50[0];
                t9 = fn_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t7) + 48)), (ts4l_word)31, (ts4l_word)(ts4l_word)&loc50[0]);
                p10 = (ts4l_word)t9;
            }
            p11 = (ts4l_word)p10;
        }
        p12 = (ts4l_word)p11;
    }
    return p12;
}

/* Loader_DLL.xex 0x83253130: if_call_seq u32@0x3c, fn_83257180, fn_83256640, fn_83256D18, fn_8326C9E0 */
ts4l_word ts4l_if_call_seq_u32_off3c_83253130(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p7;
    int t1;
    int t5;
    ts4l_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 60);
    if ((int)t1 > 2) {
        fn_83257180();
    }
    fn_83256640((ts4l_word)a0);
    t5 = fn_83256D18((ts4l_word)a0);
    p7 = (ts4l_word)t5;
    if ((int)t5 >= 0) {
        t6 = fn_8326C9E0((ts4l_word)a0);
        p7 = (ts4l_word)t6;
    }
    return p7;
}

/* Loader_DLL.xex 0x832540C0: if_get u32@0x1bc, u32@0x1c0, u32@0x1c0, u32@0xfc, u32@0x100, u32@0x10c */
void ts4l_if_get_u32_off1bc_832540C0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p15;
    int t1;
    ts4l_word t11;
    ts4l_word t12;
    ts4l_word t13;
    int t14;
    int t3;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t9;
    ts4l_word t10;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 444);
    if ((int)t1 != 0) {
        t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 456);
        t12 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
        t13 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
        t14 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)((int)t12 >> t11);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)((int)t13 >> t11);
        p15 = (ts4l_word)((short)a1);
        if ((int)t14 < (int)((short)a1)) {
            p15 = (ts4l_word)t14;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)p15;
        return;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 448);
    if ((int)t3 != 0) {
        t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 456);
        t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
        t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
        t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)(t8 << t7);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)(t9 << t7);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)t10;
        return;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 252);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 256);
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 268);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 464) = (ts4l_word)t4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 468) = (ts4l_word)t5;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 472) = (ts4l_word)t6;
    return;
}

/* Loader_DLL.xex 0x83255558: call_seq fn_833E3A30, fn_83272CF8, fn_83273160, fn_83273160, fn_83273160, fn_83273160 */
ts4l_word ts4l_call_seq_fn_833E3A30_83255558(ts4l_word a0)
{
    ts4l_word t6;

    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)168);
    fn_83272CF8((ts4l_word)a0);
    fn_83273160((ts4l_word)(a0 + 24));
    fn_83273160((ts4l_word)(a0 + 44));
    fn_83273160((ts4l_word)(a0 + 64));
    t6 = fn_83273160((ts4l_word)(a0 + 84));
    return t6;
}

/* Loader_DLL.xex 0x832555B8: if_call_seq fn_83272D18, fn_83273180, fn_83273180, fn_83273180, fn_83273180, u32@0x94 */
ts4l_word ts4l_if_call_seq_fn_83272D18_832555B8(ts4l_word a0)
{
    ts4l_word t6;
    ts4l_word t9;
    ts4l_word t17;

    fn_83272D18((ts4l_word)a0);
    fn_83273180((ts4l_word)(a0 + 24));
    fn_83273180((ts4l_word)(a0 + 44));
    fn_83273180((ts4l_word)(a0 + 64));
    fn_83273180((ts4l_word)(a0 + 84));
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 148);
    if ((ts4l_word)t6 != 0) {
        fn_832522A8((ts4l_word)t6);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 148) = (ts4l_word)0;
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 160);
    if ((ts4l_word)t9 != 0) {
        fn_832522A8((ts4l_word)t9);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 160) = (ts4l_word)0;
    }
    fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)168);
    fn_83272CF8((ts4l_word)a0);
    fn_83273160((ts4l_word)(a0 + 24));
    fn_83273160((ts4l_word)(a0 + 44));
    fn_83273160((ts4l_word)(a0 + 64));
    t17 = fn_83273160((ts4l_word)(a0 + 84));
    return t17;
}

/* Loader_DLL.xex 0x83259108: if_get u32@0x8, u32@0x24, u32@0x28, u32@0x2c, u32@0x30, u32@0x20 */
void ts4l_if_get_u32_off8_83259108(ts4l_word a0)
{
    ts4l_word t1;
    int t2;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 704);
    if ((int)t2 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)(ts4l_word)fn_83259100;
    return;
}

/* Loader_DLL.xex 0x832594F0: if_get u32@0x4c, u32@0x8, u32@0x2c0, u32@0x8, u32@0x2c0, u32@0x1c */
ts4l_word ts4l_if_get_u32_off4c_832594F0(ts4l_word a0)
{
    int t1;
    int t5;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 76);
    if ((int)t1 != 0) {
        t5 = *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 8))) + 704);
        if ((int)t5 == 0 || (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 32)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 28))) >= (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 24)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 20)))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83259710: if_set u32@0x8, u32@0x0, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4l_if_set_u32_off8_83259710(ts4l_word a0, ts4l_word a1)
{
    int t3;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)15;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 212));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 704);
    if ((int)t3 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)(ts4l_word)fn_83259100;
    return;
}

/* Loader_DLL.xex 0x83259FE8: if_call_seq fn_83259BC8, u16@0x10 */
ts4l_word ts4l_if_call_seq_fn_83259BC8_83259FE8(ts4l_word a0)
{
    ts4l_word loc50[4];
    int t1;
    ts4l_word t2;

    t1 = fn_83259BC8((ts4l_word)(a0 + 224), (ts4l_word)1, (ts4l_word)(ts4l_word)&loc50[0]);
    if ((int)t1 >= 0) {
        t2 = loc50[0];
        *(unsigned short *)((char *)(ts4l_word)(a0) + 16) = (unsigned short)t2;
    }
    return t1;
}

/* Loader_DLL.xex 0x83261260: if_call_seq u16@0xae, fn_8326C1B8, u32@0xa4, u16@0xa8, fn_832584D8 */
ts4l_word ts4l_if_call_seq_u16_offae_83261260(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4)
{
    int t3;

    fn_8326C1B8((ts4l_word)a2, (ts4l_word)a4, (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 174)));
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 164);
    if ((int)t3 == 1) {
        fn_832584D8((ts4l_word)a0, (ts4l_word)a2, (ts4l_word)(a1 + 1616), (ts4l_word)a3, (ts4l_word)(a1 + 1456), (ts4l_word)a4, (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(a0) + 168)));
    }
    return 1;
}

/* Loader_DLL.xex 0x83262060: call_seq fn_833E3A30, u32@0x8, u32@0x4, u32@0x0, u64@0x10, u64@0x18 */
ts4l_word ts4l_call_seq_fn_833E3A30_83262060(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)120);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 16) = (ts4l_u64)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 24) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 104) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(4288675840);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)500;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)200;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 88) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 92) = (ts4l_word)2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 96) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 100) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 108) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 112) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x83266788: if_call_seq fn_832678F8, fn_83267780, fn_83259EB8, fn_83259BC8, u32@0x0, fn_83259EB8 */
ts4l_word ts4l_if_call_seq_fn_832678F8_83266788(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word loc50[4];
    int t1;
    int t2;
    ts4l_word t4;
    int t11;
    int t8;
    int t9;
    ts4l_word t10;
    int t5;
    int t6;
    ts4l_word t7;

    t1 = fn_832678F8((ts4l_word)a2, (ts4l_word)(a1 + 3));
    if ((int)t1 >= 0) {
        t2 = fn_83267780((ts4l_word)a2, (ts4l_word)3, (ts4l_word)(ts4l_word)&loc50[0]);
        if ((int)t2 >= 0) {
            t4 = loc50[0];
            if ((ts4l_word)(t4 & 0x80000000) == 0) {
                t11 = fn_83259EB8((ts4l_word)a2, (ts4l_word)1);
                if ((int)t11 >= 0) {
                    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
                    return t11;
                }
                return t11;
            }
            if ((int)(t4 & 0x40000000) == 0) {
                t8 = fn_83259EB8((ts4l_word)a2, (ts4l_word)2);
                if ((int)t8 >= 0) {
                    t9 = fn_83259BC8((ts4l_word)a2, (ts4l_word)2, (ts4l_word)(ts4l_word)&loc50[0]);
                    if ((int)t9 >= 0) {
                        t10 = loc50[0];
                        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(t10 + 1);
                        return t9;
                    }
                    return t9;
                }
                return t8;
            }
            if ((int)(t4 & 0x20000000) == 0) {
                t5 = fn_83259EB8((ts4l_word)a2, (ts4l_word)3);
                if ((int)t5 >= 0) {
                    t6 = fn_83259BC8((ts4l_word)a2, (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc50[0]);
                    if ((int)t6 >= 0) {
                        t7 = loc50[0];
                        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(t7 + 4);
                        return t6;
                    }
                    return t6;
                }
                return t5;
            }
            return ((2147745792) | 2);
        }
        return t2;
    }
    return t1;
}

/* Loader_DLL.xex 0x83269238: if_call_seq u32@0x20, u32@0x44, fn_8327C060, fn_83268E98, u32@0x8, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_off20_83269238(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t3;
    int t4;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    t3 = fn_8327C060((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 68)));
    t4 = fn_83268E98((ts4l_word)t3);
    if ((int)t4 >= 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 8) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 12) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 16) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 20) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(t1) + 80) = (ts4l_word)0;
        *(ts4l_u64 *)((char *)(ts4l_word)(t1) + 72) = (ts4l_u64)0;
    }
    return t4;
}

/* Loader_DLL.xex 0x83269340: call_seq u32@0x20, u32@0x44, fn_8327EDF8, u32@0x6c, u32@0x0, fn_83268E98 */
ts4l_word ts4l_call_seq_u32_off20_83269340(ts4l_word a0, ts4l_word a1)
{
    ts4l_word loc50[2];
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 32);
    *(unsigned short *)((char *)loc50 + 0) = (unsigned short)0;
    t3 = fn_8327EDF8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 68)), (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)15);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t1) + 108);
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)((int)t4 * (int)(*(unsigned short *)((char *)loc50 + 0)));
    t6 = fn_83268E98((ts4l_word)t3);
    return t6;
}

/* Loader_DLL.xex 0x83269488: if_call_seq u32@0x1c, u32@0x1084, fn_8327EF18, u32@0x0, u32@0x1084, fn_8327F178 */
ts4l_word ts4l_if_call_seq_u32_off1c_83269488(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p10;
    ts4l_word p11;
    ts4l_word p12;
    ts4l_word loc50[4];
    ts4l_word loc60[14];
    ts4l_word t1;
    ts4l_word t2;
    int t3;
    ts4l_word t4;
    int t6;
    int t8;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a1) + 28);
    loc50[0] = (ts4l_word)0;
    loc60[0] = (ts4l_word)12;
    loc60[1] = (ts4l_word)1;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4228);
    loc60[2] = (ts4l_word)2;
    loc60[3] = (ts4l_word)3;
    loc60[4] = (ts4l_word)4;
    loc60[5] = (ts4l_word)5;
    loc60[6] = (ts4l_word)6;
    loc60[7] = (ts4l_word)7;
    loc60[8] = (ts4l_word)8;
    loc60[9] = (ts4l_word)9;
    loc60[10] = (ts4l_word)10;
    loc60[11] = (ts4l_word)11;
    t3 = fn_8327EF18((ts4l_word)a1, (ts4l_word)t2, (ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)12, (ts4l_word)(a0 + 100), (ts4l_word)(a0 + 104), (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)8);
    p12 = (ts4l_word)t3;
    if ((int)t3 >= 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)((a0 + 104)) + 0);
        t6 = fn_8327F178((ts4l_word)a1, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4228)), (ts4l_word)t4, (ts4l_word)(a0 + 32), (ts4l_word)(a0 + 36), (ts4l_word)(a0 + 108), (ts4l_word)(ts4l_word)&loc50[0]);
        p11 = (ts4l_word)t6;
        if ((int)t6 >= 0) {
            t8 = fn_83233A38((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4228)), (ts4l_word)t1, (ts4l_word)(589824), (ts4l_word)0);
            p10 = (ts4l_word)t8;
            if ((int)t8 >= 0 && (int)(loc50[0]) != 0) {
                p10 = (ts4l_word)((5242880) | 9);
            }
            p11 = (ts4l_word)p10;
        }
        p12 = (ts4l_word)p11;
    }
    return p12;
}

/* Loader_DLL.xex 0x8326B2D8: call_seq u32@0x1c, fn_832523C8, u32@0x20, fn_832523C8, u32@0x24, fn_832523C8 */
ts4l_word ts4l_call_seq_u32_off1c_8326B2D8(ts4l_word a0)
{
    ts4l_word t12;

    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 28)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 32)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 36)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 40)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 24)));
    t12 = fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)));
    return t12;
}

/* Loader_DLL.xex 0x8326B428: call_seq u32@0x30, fn_832523C8, u32@0x34, fn_832523C8, u32@0x24, fn_832523C8 */
ts4l_word ts4l_call_seq_u32_off30_8326B428(ts4l_word a0)
{
    ts4l_word t10;

    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 48)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 52)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 36)));
    fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 40)));
    t10 = fn_832523C8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)));
    return t10;
}

/* Loader_DLL.xex 0x8326F850: call_seq fn_8326F6E8, fn_8326F390 */
ts4l_word ts4l_call_seq_fn_8326F6E8_8326F850(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    ts4l_word loc50[12];
    ts4l_word loc80[12];
    ts4l_word t2;

    fn_8326F6E8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)(ts4l_word)&loc80[0], (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a3);
    t2 = fn_8326F390((ts4l_word)a0, (ts4l_word)(ts4l_word)&loc80[0], (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a2, (ts4l_word)a3);
    return t2;
}

/* Loader_DLL.xex 0x83275288: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_83275288(ts4l_word a0)
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

/* Loader_DLL.xex 0x83275698: if_call_seq u32@0x0, u32@0x4, u32@0xc, fn_8328B3F0, fn_8340D0A0, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_off0_83275698(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t7;
    ts4l_word t5;

    if (((ts4l_word)a0 != 0 && (ts4l_word)a1 >= (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) && (ts4l_word)a1 < (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 4))) {
        t7 = fn_8328B3F0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)));
        return t7;
    }
    fn_8328B3F0((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)), (ts4l_word)a1);
    t5 = fn_8340D0A0((ts4l_word)a1);
    return t5;
}

/* Loader_DLL.xex 0x83278030: if_call_seq u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x5710, u32@0x5710 */
ts4l_word ts4l_if_call_seq_u32_off2e0_83278030(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t3;
    int t4;
    int t6;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 736);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 22288);
    if ((int)t6 != 0) {
        fn_832DA598((ts4l_word)t3, (ts4l_word)(a1 & 0xff));
    }
    return 0;
}

/* Loader_DLL.xex 0x832785C0: if_get u32@0xd78, u32@0x3d0c, u32@0x3d0c, u32@0xd68, u32@0xd68, u32@0xea4 */
ts4l_word ts4l_if_get_u32_offd78_832785C0(ts4l_word a0)
{
    int t1;
    int t3;
    int t5;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3448);
    if ((int)t1 != 0) {
        return fn_8329FAF8((ts4l_word)(a0 + 3772), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3764)));
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 15628);
    if ((int)t3 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3432)) != 0) {
        return fn_8329FAF8((ts4l_word)(a0 + 3772), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3760)));
    }
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3432);
    if ((int)t5 != 0) {
        return fn_8329FAF8((ts4l_word)(a0 + 3772), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3744)));
    }
    return fn_8329FAF8((ts4l_word)(a0 + 3772), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 3748)));
}

/* Loader_DLL.xex 0x83278DC0: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x39f4, u32@0x0 */
ts4l_word ts4l_if_get_u32_off2e0_83278DC0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t3;
    int t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((ts4l_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 736);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    if ((ts4l_word)a1 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t3) + 14836)) != 0);
    }
    return 0;
}

/* Loader_DLL.xex 0x83279988: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x6070, u32@0xc0 */
ts4l_word ts4l_if_get_u32_off2e0_83279988(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word t3;
    int t4;
    ts4l_word t8;

    if ((ts4l_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 736);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    t8 = *(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t3) + 24688))) + 192);
    if ((ts4l_word)t8 == 0) {
        return -3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 22032) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 22036) = (ts4l_word)a2;
    return 0;
}

/* Loader_DLL.xex 0x83279A08: if_call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4l_word ts4l_if_call_seq_u32_off0_83279A08(ts4l_word a0, ts4l_word a1, ts4l_word a2)
{
    ts4l_word p26;
    ts4l_word t18;
    ts4l_word t19;
    ts4l_word t20;
    ts4l_word t21;
    ts4l_word t22;
    ts4l_word t23;
    ts4l_word t25;
    ts4l_word t24;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 8));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 12));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 16));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 20));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 24));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 28));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 32));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 36));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 40));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 44));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 48));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 52) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 52));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 56));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 60));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a2) + 64));
    t18 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 68);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)t18;
    t19 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 72);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)t19;
    t20 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 76);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)t20;
    t21 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 80);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 80) = (ts4l_word)t21;
    t22 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 84);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 84) = (ts4l_word)t22;
    t23 = *(ts4l_word *)((char *)(ts4l_word)(a2) + 88);
    if ((ts4l_word)t23 != 0) {
        t25 = fn_833E3AD0((ts4l_word)(a0 + 88), (ts4l_word)t23, (ts4l_word)128, (ts4l_word)t22, (ts4l_word)t21, (ts4l_word)t20, (ts4l_word)t19, (ts4l_word)t18);
        p26 = (ts4l_word)t25;
    } else {
        t24 = fn_833E3A30((ts4l_word)(a0 + 88), (ts4l_word)0, (ts4l_word)128, (ts4l_word)t22, (ts4l_word)t21, (ts4l_word)t20, (ts4l_word)t19, (ts4l_word)t18);
        p26 = (ts4l_word)t24;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 21888)) != 0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 22056));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a1) + 22060));
    return p26;
}

/* Loader_DLL.xex 0x8327EC18: if_get u32@0x2e0, u32@0x10, u32@0x2e0, u32@0x10, u32@0x39f4, u32@0x39f4 */
ts4l_word ts4l_if_get_u32_off2e0_8327EC18(ts4l_word a0)
{
    ts4l_word t3;
    int t4;
    int t6;

    if ((ts4l_word)a0 == 0) {
        return -3;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 736);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 16);
    if ((int)t4 != 0) {
        return -4;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(t3) + 14836);
    if ((((int)t6 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 22132)) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 15364)) == 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 15432)) == 0) {
        *(ts4l_word *)((char *)(ts4l_word)(t3) + 22132) = (ts4l_word)1;
        return fn_8327E318((ts4l_word)a0);
    }
    return 2;
}

/* Loader_DLL.xex 0x832856C0: set u32@0x549c, u32@0xd8c, u32@0xd98, u32@0xd94, u32@0x5428, u32@0x556c */
void ts4l_set_u32_off549c_832856C0(ts4l_word a0)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21660) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3468) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3480) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3476) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21544) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21868) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21676) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3488) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21576) = (ts4l_word)-1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 408) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21664) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21672) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21668) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4020) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 21784) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 340) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 332) = (ts4l_word)0;
    return;
}

/* Loader_DLL.xex 0x832879F0: if_call_seq u32@0x8, fn_834138F0, u32@0x8, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off8_832879F0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p3;
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    p3 = (ts4l_word)a0;
    if ((ts4l_word)a1 >= (ts4l_word)t1) {
        t2 = fn_834138F0();
        p3 = (ts4l_word)t2;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    if ((ts4l_word)a1 < (ts4l_word)t4) {
        *(ts4l_word *)((char *)(ts4l_word)((a1 << 2)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) = (ts4l_word)a2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83287A50: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_83287A50(ts4l_word a0)
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

/* Loader_DLL.xex 0x8328B2A8: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_8328B2A8(ts4l_word a0)
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
