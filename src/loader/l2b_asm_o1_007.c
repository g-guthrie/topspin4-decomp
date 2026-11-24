/* Loader_DLL.xex 0x83178A48-0x83182098, executable version 0.0.0.3. */
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

extern char lbl_83008650[];
extern char lbl_830086C0[];
extern char lbl_83008710[];
extern char lbl_83008780[];
extern char lbl_8352808C[];
extern char lbl_83531718[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_83177C20();
ts4_word fn_831791F0();
ts4_word fn_831797A8();
ts4_word fn_831798A0();
ts4_word fn_8317AAF8();
ts4_word fn_8317AFF0();
ts4_word fn_8317B410();
ts4_word fn_8317BD38();
ts4_word fn_8317BE28();
ts4_word fn_8317C060();
ts4_word fn_8317C168();
ts4_word fn_8317D8A0();
ts4_word fn_8317F460();
ts4_word fn_8317FF40();
ts4_word fn_8317FFE0();
ts4_word fn_83180388();
ts4_word fn_83180808();
ts4_word fn_83180E30();
ts4_word fn_83180ED0();
ts4_word fn_831811A8();
ts4_word fn_83181280();
ts4_word fn_83181308();
ts4_word fn_8318AB00();
ts4_word fn_8318B2C8();
ts4_word fn_8319D240();
ts4_word fn_8319D4C0();
ts4_word fn_8319D568();
ts4_word fn_8319ED80();
ts4_word fn_831A14B0();
ts4_word fn_832188D0();
ts4_word fn_83218A90();
ts4_word fn_8340D830();

/* Loader_DLL.xex 0x83178A48: if_call_seq u32@0x4, lbl_8352808C, RtlEnterCriticalSection, u32@0x8, lbl_83531718, u16@0x50 */
ts4_word ts4l_if_call_seq_u32_off4_83178A48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    unsigned short t4;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t1 & 0x4) != 0) {
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8352808C);
        t4 = *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 80);
        *(ts4_word *)((char *)(ts4_word)(((t4 << 2) | (t4 >> 30))) + (ts4_word)lbl_83531718) = (ts4_word)0;
        RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8352808C);
    }
    fn_83177C20((ts4_word)a0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)(t8 & 0x2) == 0) {
        fn_8340D830((ts4_word)a0, (ts4_word)(2811691008));
    }
    return 0;
}

/* Loader_DLL.xex 0x83179070: if_call_seq u32@0x0, fn_83218A90, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83179070(ts4_word a0, ts4_word a1)
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

/* Loader_DLL.xex 0x831792D8: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_83218A90, u32@0x0, fn_832188D0 */
ts4_word ts4l_loop_call_seq_u32_off4_831792D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x83179428: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_83179428(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 52))))((ts4_word)t5, (ts4_word)512);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x831796F0: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_831796F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x83179CB0: if_call_seq fn_831797A8, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_831797A8_83179CB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_831797A8((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83179D30: if_call_seq fn_831798A0, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_831798A0_83179D30(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_831798A0((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8317AB70: if_call_seq fn_8317AAF8, fn_831791F0 */
ts4_word ts4l_if_call_seq_fn_8317AAF8_8317AB70(ts4_word a0, ts4_word a1)
{

    fn_8317AAF8((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_831791F0((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8317B1B8: if_call_seq fn_8317AFF0, u32@0x0, u32@0x0 */
ts4_word ts4l_if_call_seq_fn_8317AFF0_8317B1B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_8317AFF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)((a3) >> 9));
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)((a3 >> 7) & 0x3);
        p2 = (ts4_word)0;
    } else {
        p2 = (ts4_word)((2147483648) | 16389);
    }
    return p2;
}

/* Loader_DLL.xex 0x8317B2B0: if_call_seq u32@0x0, fn_83218A90, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_8317B2B0(ts4_word a0, ts4_word a1)
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

/* Loader_DLL.xex 0x8317B558: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_83218A90, u32@0x0, fn_832188D0 */
ts4_word ts4l_loop_call_seq_u32_off4_8317B558(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x8317B728: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_8317B728(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 52))))((ts4_word)t5, (ts4_word)512);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x8317BB70: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_8317BB70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x8317BC80: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_8317BC80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x8317BF90: if_get u32@0x6c, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off6c_8317BF90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x8317C938: if_call_seq fn_8317BD38, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_8317BD38_8317C938(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8317BD38((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8317C9B8: if_call_seq fn_8317BE28, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_8317BE28_8317C9B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8317BE28((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8317CA38: if_call_seq fn_8317C060, u32@0x0, u32@0x6c, u32@0x4, u32@0x8, u32@0x6c */
ts4_word ts4l_if_call_seq_fn_8317C060_8317CA38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8317C060((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 108));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8317CAB8: if_call_seq fn_8317C168, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4l_if_call_seq_fn_8317C168_8317CAB8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_8317C168((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 208));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x8317D908: if_call_seq fn_8317D8A0, fn_8317B410 */
ts4_word ts4l_if_call_seq_fn_8317D8A0_8317D908(ts4_word a0, ts4_word a1)
{

    fn_8317D8A0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8317B410((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8317FCC8: if_get u32@0x8c, u32@0x30, u32@0xb0, u32@0x0, u32@0x34, vcall */
ts4_word ts4l_if_get_u32_off8c_8317FCC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p22;
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;
    ts4_word t10;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 52))))((ts4_word)t3, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t8 != 0) {
        t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 52))))((ts4_word)t10, (ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    }
    t15 = fn_8318B2C8((ts4_word)a0);
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    p22 = (ts4_word)t15;
    if ((ts4_word)t16 != 0) {
        t18 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
        t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 0))) + 28))))((ts4_word)t18, (ts4_word)t16);
        p22 = (ts4_word)t21;
    }
    return p22;
}

/* Loader_DLL.xex 0x8317FD78: call_seq fn_8318AB00, lbl_830086C0, lbl_83008650, u32@0x8c, u32@0x0, u32@0x4 */
ts4_word ts4l_call_seq_fn_8318AB00_8317FD78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    fn_8318AB00((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830086C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_83008650;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x8317FF90: if_call_seq fn_8317FF40, fn_8317F460 */
ts4_word ts4l_if_call_seq_fn_8317FF40_8317FF90(ts4_word a0, ts4_word a1)
{

    fn_8317FF40((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8317F460((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831801E0: call_seq fn_8318AB00, u32@0x8c, lbl_83008780, u32@0x90, lbl_83008710, u32@0x0 */
ts4_word ts4l_call_seq_fn_8318AB00_831801E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    fn_8318AB00((ts4_word)(a0 + 4), (ts4_word)a1, (ts4_word)a4, (ts4_word)a5);
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83008780;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_83008710;
    return a0;
}

/* Loader_DLL.xex 0x831803D8: if_call_seq fn_83180388, fn_8317FFE0 */
ts4_word ts4l_if_call_seq_fn_83180388_831803D8(ts4_word a0, ts4_word a1)
{

    fn_83180388((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8317FFE0((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83180438: if_get u32@0x1c, u32@0x4, vcall, u32@0x54, u32@0x4, vcall */
ts4_word ts4l_if_get_u32_off1c_83180438(ts4_word a0)
{
    ts4_word p7;
    int t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 4))))((ts4_word)(a0 + 28));
    p7 = (ts4_word)t3;
    if ((int)t3 >= 0) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 4))))((ts4_word)(a0 + 84));
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Loader_DLL.xex 0x83180508: if_get u32@0x1c, u32@0x8, vcall, u32@0x0, u32@0x17c, u32@0x0 */
ts4_word ts4l_if_get_u32_off1c_83180508(ts4_word a0, ts4_word a1)
{
    int t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 380);
    if ((int)t4 == 2) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0))) + 20))))((ts4_word)(a0 + 28));
    return 0;
}

/* Loader_DLL.xex 0x83180570: get u32@0x1c, u32@0x8, vcall, u32@0x44, fn_8319D568, u32@0x1c */
ts4_word ts4l_get_u32_off1c_83180570(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    t5 = fn_8319D568((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)a1, (ts4_word)a2);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    return t5;
}

/* Loader_DLL.xex 0x831805D8: get u32@0x1c, u32@0x8, vcall, u32@0x44, fn_8319D240, u32@0x1c */
ts4_word ts4l_get_u32_off1c_831805D8(ts4_word a0, ts4_word a1)
{
    ts4_word t8;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 8))))((ts4_word)(a0 + 28));
    fn_8319D240((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)a1);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 20))))((ts4_word)(a0 + 28));
    return t8;
}

/* Loader_DLL.xex 0x83180660: if_get u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x28, vcall */
ts4_word ts4l_if_get_u32_off0_83180660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t8;
    ts4_word t10;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p5 = (ts4_word)0;
    if ((ts4_word)a1 != 0) {
        t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 40))))((ts4_word)a1);
        p5 = (ts4_word)t3;
    }
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 40))))((ts4_word)a2);
    t10 = fn_8319ED80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72)), (ts4_word)p5, (ts4_word)t8);
    return t10;
}

/* Loader_DLL.xex 0x831806D8: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_83218A90, u32@0x0, fn_832188D0 */
ts4_word ts4l_loop_call_seq_u32_off4_831806D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x83180F30: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_83180F30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x83181158: if_call_seq fn_8319D4C0, fn_83180808 */
ts4_word ts4l_if_call_seq_fn_8319D4C0_83181158(ts4_word a0, ts4_word a1)
{

    fn_8319D4C0();
    if ((int)(a1 & 0x1) != 0) {
        fn_83180808((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83181230: if_call_seq fn_831A14B0, fn_83180808 */
ts4_word ts4l_if_call_seq_fn_831A14B0_83181230(ts4_word a0, ts4_word a1)
{

    fn_831A14B0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83180808((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83181508: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_offcc_83181508(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a1 == (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 208);
    if ((ts4_word)a1 == (ts4_word)t8) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    } else {
        t9 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(t9) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t15 + -1);
    return t2;
}

/* Loader_DLL.xex 0x83181C08: loop_get u32@0x54, u32@0x8, vcall, u32@0x14c, fn_83180E30, u32@0x0 */
ts4_word ts4l_loop_get_u32_off54_83181C08(ts4_word a0)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;
    ts4_word t15;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84))) + 8))))((ts4_word)(a0 + 84));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    if ((ts4_word)t4 != 0) {
        do {
            t5 = fn_83180E30((ts4_word)(a0 + 120));
            t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 4))))((ts4_word)t5, (ts4_word)0);
            fn_83180808((ts4_word)t8);
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
        } while ((ts4_word)t10 != 0);
    }
    t15 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0))) + 20))))((ts4_word)(a0 + 84));
    return t15;
}

/* Loader_DLL.xex 0x83181C88: loop_get u32@0x174, fn_83180ED0, u32@0x4, u32@0x0, vcall, fn_83180808 */
ts4_word ts4l_loop_get_u32_off174_83181C88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
    p9 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        do {
            t2 = fn_83180ED0((ts4_word)(a0 + 340));
            t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 4))) + 0))))((ts4_word)(t2 + 4), (ts4_word)0);
            t6 = fn_83180808((ts4_word)t5);
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 372);
        } while ((ts4_word)t7 != 0);
        p9 = (ts4_word)t6;
    }
    return p9;
}

/* Loader_DLL.xex 0x83181F58: if_call_seq fn_83181308, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83181308_83181F58(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83181308((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83181FD8: if_call_seq fn_831811A8, fn_8319D4C0, fn_83180808 */
ts4_word ts4l_if_call_seq_fn_831811A8_83181FD8(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            fn_8319D4C0((ts4_word)a2);
            t4 = fn_83180808((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_831811A8((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x83182038: if_call_seq fn_83181280, fn_831A14B0, fn_83180808 */
ts4_word ts4l_if_call_seq_fn_83181280_83182038(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p5;
    ts4_word p6;
    ts4_word t4;
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a1 == 0) {
        p5 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            fn_831A14B0((ts4_word)a2);
            t4 = fn_83180808((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_83181280((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}
