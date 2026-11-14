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

extern char lbl_88095F40[];
extern char lbl_880B2858[];
extern char lbl_880B4540[];
extern char lbl_880B6858[];
extern char lbl_880B6868[];
extern char lbl_880B692C[];
extern char lbl_880BCAD8[];
extern char lbl_880BCB28[];
ts4_word ts4_pool1_clear_88599CF8();
ts4_word fn_8859D5A8();
ts4_word ts4_call_seq_lbl_88091F2C_885A7320();
ts4_word ts4_call_seq_lbl_88091FB8_885A7AC8();
ts4_word ts4_call_seq_lbl_88092008_885A9298();
ts4_word ts4_if_call_seq_u32_off2c_885A9E38();
ts4_word ts4_if_call_seq_u32_off4_885B6060();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885CE2A8();
ts4_word ts4_if_get_u32_off84_885CE668();
ts4_word ts4_if_call_seq_u32_off78_885CEA48();
ts4_word ts4_if_get_u32_off0_885CF1F0();
ts4_word fn_885DC838();
ts4_word ts4_if_call_seq_fn_885DCFD0_885DCA80();
ts4_word ts4_if_call_seq_lbl_880B4540_885DCBE0();
ts4_word fn_885DD1F8();
ts4_word fn_885DD2C0();
ts4_word ts4_call_seq_u32_off0_885E37E0();
ts4_word fn_885E3830();
ts4_word ts4_get_u32_off858_885E3900();
ts4_word ts4_get_u32_off4_885E3B50();
ts4_word fn_885E3E60();
ts4_word fn_885E4248();
ts4_word ts4_if_call_seq_u32_off2c_885E4748();
ts4_word ts4_call_seq_fn_885E4248_885E48D8();
ts4_word ts4_call_seq_fn_885E4248_885E4938();
ts4_word ts4_if_get_fn_885E4248_885E4980();
ts4_word ts4_call_seq_fn_885E4248_885E5308();
ts4_word ts4_if_call_seq_fn_885E4248_885E5358();
ts4_word ts4_if_call_seq_fn_885E4248_885E53E0();
ts4_word ts4_call_seq_fn_885E4248_885E54C8();
ts4_word ts4_call_seq_fn_885E4248_885E5530();
ts4_word ts4_call_seq_fn_885E4248_885E5598();
ts4_word ts4_call_seq_fn_885E5BC8_885E6138();

/* Swing_DLL.xex 0x885A7378: if_call_seq ts4_call_seq_lbl_88091F2C_885A7320, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A7320_885A7378(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_lbl_88091F2C_885A7320((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A7CD8: if_call_seq ts4_call_seq_lbl_88091FB8_885A7AC8, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A7AC8_885A7CD8(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_lbl_88091FB8_885A7AC8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A9990: if_call_seq ts4_call_seq_lbl_88092008_885A9298, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A9298_885A9990(ts4_word a0, ts4_word a1)
{

    ts4_call_seq_lbl_88092008_885A9298((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885A9EA0: if_call_seq ts4_if_call_seq_u32_off2c_885A9E38, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885A9E38_885A9EA0(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off2c_885A9E38((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B6258: if_call_seq ts4_if_call_seq_u32_off4_885B6060, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885B6060_885B6258(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off4_885B6060((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885B7DE0: get u32@0x4, u32@0x0, u32@0x1c, vcall */
ts4_word ts4_get_u32_off4_885B7DE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x885B7E18: get u32@0x4, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off4_885B7E18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x885B7EE0: set u32@0x4, u32@0x8, lbl_88095F40, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off4_885B7EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095F40;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885B7F98: if_get u32@0x4, lbl_88095F40, u32@0x0, u32@0x0, u32@0xc, vcall */
ts4_word ts4_if_get_u32_off4_885B7F98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88095F40;
    p6 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)0);
        t5 = ts4_pool_free_885B72F0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x885CE808: if_get u32@0x94, u32@0x8c, u32@0x90, u32@0x84, u32@0x80, u32@0x0 */
ts4_word ts4_if_get_u32_off94_885CE808(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2, (ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)t6;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 40))))((ts4_word)t8, (ts4_word)1, (ts4_word)(t9 + 56), (ts4_word)1, (ts4_word)(a0 + 136), (ts4_word)1);
    ts4_if_get_u32_off84_885CE668((ts4_word)a0);
    return 0;
}

/* Swing_DLL.xex 0x885CED60: if_call_seq ts4_if_call_seq_u32_off78_885CEA48, ts4_pool_free_885B72F0 */
ts4_word ts4_if_call_seq_fn_885CEA48_885CED60(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off78_885CEA48((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        ts4_pool_free_885B72F0((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x885D9D10: loop_get u32@0x8, lbl_880B2858, u32@0x0, u32@0x0, u32@0x24, vcall */
ts4_word ts4_loop_get_u32_off8_885D9D10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t15;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880B2858;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t6 != 0) {
        do {
            t7 = fn_8859D5A8((ts4_word)(a0 + 16));
            fn_885CE2A8((ts4_word)t7);
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        } while ((ts4_word)t9 != 0);
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    if ((ts4_word)t12 != 0) {
        do {
            t13 = fn_8859D5A8((ts4_word)(a0 + 56));
            fn_885CE2A8((ts4_word)t13);
            t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
        } while ((ts4_word)t15 != 0);
    }
    ts4_if_get_u32_off0_885CF1F0((ts4_word)(a0 + 8));
    ts4_if_get_u32_off0_885CF1F0((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_pool1_clear_88599CF8((ts4_word)(a0 + 56));
    t21 = ts4_pool1_clear_88599CF8((ts4_word)(a0 + 16));
    return t21;
}

/* Swing_DLL.xex 0x885DCCA8: if_call_seq lbl_880B4540, lbl_880B6868, lbl_880B692C, fn_885DC838, u32@0x0, ts4_if_call_seq_fn_885DCFD0_885DCA80 */
ts4_word ts4_if_call_seq_lbl_880B4540_885DCCA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    if ((ts4_word)a0 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B692C, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)3144);
    }
    t4 = ts4_if_call_seq_fn_885DCFD0_885DCA80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    if ((int)t4 == 0) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B6858, (ts4_word)(ts4_word)lbl_880B6868, (ts4_word)3149);
    }
    *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)a1;
    ts4_if_call_seq_lbl_880B4540_885DCBE0((ts4_word)a0, (ts4_word)t4);
    return t4;
}

/* Swing_DLL.xex 0x885E38A8: if_call_seq u32@0x18, u32@0xc, u32@0x18, u32@0x20, u32@0x18, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off18_885E38A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 12) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 32) = (ts4_word)a1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t5 = fn_885E3E60((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t3);
    p7 = (ts4_word)t5;
    if ((ts4_word)t5 == 0) {
        t6 = ts4_call_seq_u32_off0_885E37E0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Swing_DLL.xex 0x885E4A58: call_seq fn_885E4248, lbl_880BCB28, u32@0x0, u32@0xab0, ts4_get_u32_off858_885E3900, u8@0x5 */
ts4_word ts4_call_seq_fn_885E4248_885E4A58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    fn_885E4248();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCB28;
    ts4_get_u32_off858_885E3900((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 2736)), (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x885E52C8: call_seq ts4_call_seq_fn_885E4248_885E48D8, lbl_880BCAD8, u32@0x0 */
ts4_word ts4_call_seq_fn_885E48D8_885E52C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_call_seq_fn_885E4248_885E48D8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCAD8;
    return a0;
}

/* Swing_DLL.xex 0x885E5470: if_call_seq ts4_if_call_seq_u32_off2c_885E4748, u32@-0x4, fn_885DD2C0 */
ts4_word ts4_if_call_seq_fn_885E4748_885E5470(ts4_word a0, ts4_word a1)
{

    ts4_if_call_seq_u32_off2c_885E4748((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0 && (ts4_word)a0 != 0) {
        fn_885DD2C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + -4)), (ts4_word)(a0 + -4));
    }
    return a0;
}

/* Swing_DLL.xex 0x885E5A80: if_call_seq u32@0x50, u32@0x3b8, u32@0xab0, u32@0xac, fn_885E3830, u32@0xe4 */
ts4_word ts4_if_call_seq_u32_off50_885E5A80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 == 11) {
        fn_885E3830((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 952))) + 2736))) + 172)), (ts4_word)a0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 228)) & 0xfffffffe);
    t8 = ts4_get_u32_off4_885E3B50((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x885E6898: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E5BC8_885E6138 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6898(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)964);
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E5BC8_885E6138((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6D80: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E48D8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6D80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E48D8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6E30: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_if_get_fn_885E4248_885E4980 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6E30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)68);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_if_get_fn_885E4248_885E4980((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6F90: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E5308 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6F90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E5308((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E6FE8: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E5598 */
ts4_word ts4_if_call_seq_u32_off5ac_885E6FE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E5598((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E7040: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E5530 */
ts4_word ts4_if_call_seq_u32_off5ac_885E7040(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E5530((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E7098: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E54C8 */
ts4_word ts4_if_call_seq_u32_off5ac_885E7098(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)56);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E54C8((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E7148: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_if_call_seq_fn_885E4248_885E5358 */
ts4_word ts4_if_call_seq_u32_off5ac_885E7148(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_if_call_seq_fn_885E4248_885E5358((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E71A0: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_if_call_seq_fn_885E4248_885E53E0 */
ts4_word ts4_if_call_seq_u32_off5ac_885E71A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)52);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_if_call_seq_fn_885E4248_885E53E0((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x885E7250: if_call_seq u32@0x5ac, fn_885DD1F8, u32@0x0, ts4_call_seq_fn_885E4248_885E4938 */
ts4_word ts4_if_call_seq_u32_off5ac_885E7250(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 1452);
    t2 = fn_885DD1F8((ts4_word)t1, (ts4_word)60);
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    if ((int)(t2 + 4) != 0) {
        t3 = ts4_call_seq_fn_885E4248_885E4938((ts4_word)(t2 + 4), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}
