/* Loader_DLL.xex 0x8314EB60-0x8316FC58, executable version 0.0.0.3. */
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

extern char fn_83169BA0[];
extern char fn_83169BF0[];
extern char fn_83169BF8[];
extern char fn_83169C00[];
extern char lbl_8300554C[];
extern char lbl_830080DC[];
extern char lbl_8352C070[];
extern char lbl_835312F8[];
extern char lbl_8353130C[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_8311E288();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_8314E408();
ts4_word fn_8314EA48();
ts4_word fn_83151108();
ts4_word fn_83151628();
ts4_word fn_83155620();
ts4_word fn_83156D60();
ts4_word fn_8315C668();
ts4_word fn_8315E7A8();
ts4_word fn_83161840();
ts4_word fn_83161D60();
ts4_word fn_83162D10();
ts4_word fn_83162DD0();
ts4_word fn_83162DF0();
ts4_word fn_83162F50();
ts4_word fn_83162FF8();
ts4_word fn_83163070();
ts4_word fn_83163140();
ts4_word fn_831648C0();
ts4_word fn_831650D0();
ts4_word fn_83166018();
ts4_word fn_83166248();
ts4_word fn_831668D0();
ts4_word fn_83166D08();
ts4_word fn_8316C138();
ts4_word fn_8316F200();
ts4_word fn_8316F2A0();
ts4_word fn_832188D0();
ts4_word fn_83218A90();
ts4_word fn_833E3A30();
ts4_word fn_833E4608();

/* Loader_DLL.xex 0x8314EB60: if_call_seq fn_8314EA48, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8314EA48_8314EB60(ts4_word a0, ts4_word a1)
{

    fn_8314EA48((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83151680: if_call_seq RtlEnterCriticalSection, u32@0x8, u32@0x54, u32@0x38, u32@0x54, u32@0x34 */
ts4_word ts4l_if_call_seq_RtlEnterCriticalSection_83151680(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t12;

    RtlEnterCriticalSection((ts4_word)(a0 + 100));
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if ((ts4_word)t2 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(t3 - (*(ts4_word *)((char *)(ts4_word)(a1) + 56)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 52);
        if ((ts4_word)t5 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 92)) + -1);
        }
        fn_83151628((ts4_word)a0, (ts4_word)a1);
        fn_83151108((ts4_word)a1);
        fn_83120540((ts4_word)a1);
    }
    t12 = RtlLeaveCriticalSection((ts4_word)(a0 + 100));
    return t12;
}

/* Loader_DLL.xex 0x83156E10: if_call_seq lbl_835312F8, u32@-0x4, u32@0x0, lbl_8353130C, fn_83156D60, fn_83155620 */
ts4_word ts4l_if_call_seq_lbl_835312F8_83156E10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312F8) + -4);
    if ((ts4_word)t1 == 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_835312F8) + 0)) == (ts4_word)(ts4_word)lbl_8353130C) {
        t3 = fn_83156D60((ts4_word)1);
        fn_83155620((ts4_word)t3);
        p5 = (ts4_word)1;
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x8315C880: if_call_seq u32@0xa4, lbl_8300554C, u32@0x0, fn_83120540, u32@0xa8, u32@0xa4 */
ts4_word ts4l_if_call_seq_u32_offa4_8315C880(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300554C;
    fn_83120540((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    if ((ts4_word)t3 != 0) {
        fn_8314E408((ts4_word)t3, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
    }
    t6 = fn_8315C668((ts4_word)a0);
    return t6;
}

/* Loader_DLL.xex 0x8315D630: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D630(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D6D0: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D6D0(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D720: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D720(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D770: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D770(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D7C0: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D7C0(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D810: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D810(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D860: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D860(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D8B0: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D8B0(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315D900: if_call_seq fn_8315C668, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315C668_8315D900(ts4_word a0, ts4_word a1)
{

    fn_8315C668((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315E838: if_call_seq fn_8315E7A8, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8315E7A8_8315E838(ts4_word a0, ts4_word a1)
{

    fn_8315E7A8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315F568: if_call_seq u32@0x4, u32@0x4, fn_83162FF8, u32@0x0, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F568(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    int t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = fn_83162FF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    if ((int)p4 == 0) {
        t5 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t5;
    }
    return p4;
}

/* Loader_DLL.xex 0x8315F5D0: if_call_seq u32@0x4, u32@0x4, fn_83163070, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F5D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word loc5c[1];
    ts4_word loc58[1];
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    int t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = fn_83163070((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc5c[0]);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    if ((int)p4 == 0) {
        if ((ts4_word)a3 != 0) {
            t5 = loc50[0];
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t5;
        }
        if ((ts4_word)a4 != 0) {
            t6 = loc54[0];
            *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)t6;
        }
        if ((ts4_word)a5 != 0) {
            t7 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)t7;
        }
        if ((ts4_word)a6 != 0) {
            t8 = loc5c[0];
            *(ts4_word *)((char *)(ts4_word)(a6) + 0) = (ts4_word)t8;
        }
    }
    return p4;
}

/* Loader_DLL.xex 0x8315F670: if_call_seq u32@0x4, u32@0x4, fn_83163140, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off4_8315F670(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t3 = fn_83163140((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1, (ts4_word)t1, (ts4_word)a3);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8315F980: if_call_seq u32@0x4, fn_83162F50, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_8315F980(ts4_word a0, ts4_word a1)
{

    fn_83162F50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315F9D0: if_call_seq u32@0x4, fn_83162DF0, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_8315F9D0(ts4_word a0, ts4_word a1)
{

    fn_83162DF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315FBD0: if_call_seq u32@0x4, fn_83161840, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_8315FBD0(ts4_word a0, ts4_word a1)
{

    fn_83161840((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8315FC20: if_call_seq u32@0x4, fn_83161D60, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_8315FC20(ts4_word a0, ts4_word a1)
{

    fn_83161D60((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83160260: if_call_seq fn_83120518, u32@0x4, u32@0x4, fn_83162DD0, u32@0x0 */
ts4_word ts4l_if_call_seq_fn_83120518_83160260(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83120518((ts4_word)8);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        t3 = fn_83162DD0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(t1 + 4));
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t3;
        p4 = (ts4_word)t1;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x83160300: if_get u8@0x4, u8@0x4 */
ts4_word ts4l_if_get_u8_off4_83160300(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t2;

    if ((ts4_word)a1 != 0 && (ts4_word)a2 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t2 == 0) {
            return ((2147483648) | 65535);
        }
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a1) + 8));
        *(float *)((char *)(ts4_word)(a2) + 20) = (*(float *)((char *)(ts4_word)(a1) + 4));
        *(float *)((char *)(ts4_word)(a2) + 4) = (*(float *)((char *)(ts4_word)(a1) + 28));
        *(float *)((char *)(ts4_word)(a2) + 8) = (*(float *)((char *)(ts4_word)(a1) + 32));
        *(float *)((char *)(ts4_word)(a2) + 12) = (*(float *)((char *)(ts4_word)(a1) + 20));
        *(float *)((char *)(ts4_word)(a2) + 16) = (*(float *)((char *)(ts4_word)(a1) + 24));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83162ED8: if_call_seq u32@lbl_8352C070, fn_83120518, u32@0x0, fn_83162D10, u32@0x0, fn_83166248 */
ts4_word ts4l_if_call_seq_u32_lbl_8352C070_83162ED8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word loc50[8];
    ts4_word t2;
    ts4_word t8;

    loc50[7] = (ts4_word)(*(ts4_word *)lbl_8352C070);
    t2 = fn_83120518((ts4_word)32);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    if ((int)t2 == 0) {
        p7 = (ts4_word)-8;
    } else {
        fn_83162D10((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)a0;
        fn_83166248((ts4_word)(ts4_word)&loc50[0]);
        fn_83166018((ts4_word)(t2 + 4), (ts4_word)(ts4_word)&loc50[0]);
        p7 = (ts4_word)0;
    }
    t8 = loc50[7];
    fn_833E4608((ts4_word)t8);
    return p7;
}

/* Loader_DLL.xex 0x831638E8: if_call_seq u32@0x4, u32@0x4, fn_8311E288, u32@0x0, u32@0x4, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off4_831638E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p4 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t3 = fn_8311E288((ts4_word)t2);
            p4 = (ts4_word)t3;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p5 = (ts4_word)p4;
    }
    return p5;
}

/* Loader_DLL.xex 0x83165078: if_call_seq u32@0x0, fn_831648C0, fn_831650D0 */
ts4_word ts4l_if_call_seq_u32_off0_83165078(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    t2 = fn_831648C0((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 304), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 == 0) {
        p4 = (ts4_word)-1;
    } else {
        t3 = fn_831650D0((ts4_word)a0, (ts4_word)a1, (ts4_word)t2, (ts4_word)0, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x831671A8: if_call_seq fn_83166D08, fn_831668D0 */
ts4_word ts4l_if_call_seq_fn_83166D08_831671A8(ts4_word a0, ts4_word a1, ts4_word a2, int a3)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    t1 = fn_83166D08();
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0 && (int)a3 != 0) {
        t2 = fn_831668D0((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83169D60: set u32@0x10, fn_83169BA0, fn_83169BF0, u32@0x0, u32@0x8, fn_83169BF8 */
ts4_word ts4l_set_u32_off10_83169D60(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_83169BA0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_83169BF0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_83169BF8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_83169C00;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x8316C0D8: if_call_seq fn_83120518, fn_833E3A30 */
ts4_word ts4l_if_call_seq_fn_83120518_8316C0D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_83120518((ts4_word)((int)a1 * (int)a2));
    if ((int)t1 != 0) {
        fn_833E3A30((ts4_word)t1, (ts4_word)0, (ts4_word)((int)a1 * (int)a2));
    }
    return t1;
}

/* Loader_DLL.xex 0x8316CBB8: get fn_8316C138, u32@0x24, u32@0x28, u32@0x28, vcall, u32@0x24 */
ts4_word ts4l_get_fn_8316C138_8316CBB8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;

    fn_8316C138((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    ((ts4_word (*)(ts4_word, ts4_word))(t2))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)t3);
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))(t6))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))(t10))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x8316CCA0: if_get u32@0x20, u32@0x28, vcall, u32@0x14, u32@0x18, u32@0x0 */
ts4_word ts4l_if_get_u32_off20_8316CCA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a4) + 32);
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 40)), (ts4_word)1, (ts4_word)28);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)a2;
        *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)a3;
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t3) + 16) = (unsigned char)a0;
        *(unsigned char *)((char *)(ts4_word)(t3) + 17) = (unsigned char)a1;
    }
    return t3;
}

/* Loader_DLL.xex 0x8316E108: if_get u32@0x2c, u32@0x4, vcall, u32@0x50, u32@0x4, vcall */
ts4_word ts4l_if_get_u32_off2c_8316E108(ts4_word a0)
{
    ts4_word p10;
    ts4_word p11;
    int t3;
    int t6;
    ts4_word t9;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 4))))((ts4_word)(a0 + 44));
    p11 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 4))))((ts4_word)(a0 + 80));
        p10 = (ts4_word)t6;
        if ((int)t6 >= 0) {
            t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + 4))))((ts4_word)(a0 + 116));
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x8316E280: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_83218A90, u32@0x0, fn_832188D0 */
ts4_word ts4l_loop_call_seq_u32_off4_8316E280(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word loc50[2];
    int t1;
    int t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p6 = (ts4_word)a0;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        do {
            t3 = fn_83218A90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
        } while ((int)t3 >= 0);
        t5 = fn_832188D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x8316E2F8: if_call_seq u32@0x0, fn_83218A90, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_8316E2F8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[4];
    int t2;
    ts4_word t3;

    t2 = fn_83218A90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 >= 0) {
        t3 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
        p4 = (ts4_word)1;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8316E690: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4_word ts4l_if_get_u32_off0_8316E690(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Loader_DLL.xex 0x8316F3C0: if_call_seq fn_8316F2A0, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_8316F2A0_8316F3C0(ts4_word a0, ts4_word a1)
{

    fn_8316F2A0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8316F200((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8316F4F0: if_call_seq lbl_830080DC, u32@0x0, fn_8316F200 */
ts4_word ts4l_if_call_seq_lbl_830080DC_8316F4F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830080DC;
    if ((int)(a1 & 0x1) != 0) {
        fn_8316F200();
    }
    return a0;
}

/* Loader_DLL.xex 0x8316FAB0: get u32@0x2c, u32@0x8, vcall, u32@0xb0, u32@0x0, u32@0x4c */
ts4_word ts4l_get_u32_off2c_8316FAB0(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t17;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 76))))((ts4_word)t4, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 400));
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    *(ts4_word *)((char *)(ts4_word)(a1) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    *(ts4_word *)((char *)(ts4_word)(a1) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
    return t17;
}

/* Loader_DLL.xex 0x8316FB48: get u32@0x2c, u32@0x8, vcall, u32@0x2c, u32@0x14, vcall */
ts4_word ts4l_get_u32_off2c_8316FB48(ts4_word a0)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
    return t6;
}

/* Loader_DLL.xex 0x8316FBA8: if_get u32@0x50, u32@0x8, vcall, u32@0xa8, u32@0x2c, u32@0x14 */
ts4_word ts4l_if_get_u32_off50_8316FBA8(ts4_word a0, ts4_word a1)
{
    int t4;
    ts4_word t8;
    ts4_word t19;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 8))))((ts4_word)(a0 + 80));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    if ((int)t4 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 60))))((ts4_word)t8, (ts4_word)a1);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
        *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)((a1 + -1) != 0);
    }
    t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 20))))((ts4_word)(a0 + 80));
    return t19;
}
