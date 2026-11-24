/* Loader_DLL.xex 0x83162FF8-0x83176F8C, executable version 0.0.0.3. */
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

extern char fn_83174D38[];
ts4_word fn_83161B98();
ts4_word fn_83162618();
ts4_word fn_8316E690();
ts4_word fn_8316F200();
ts4_word fn_8316F538();
ts4_word fn_8316FBA8();
ts4_word fn_83170708();
ts4_word fn_83170810();
ts4_word fn_83170908();
ts4_word fn_83170A00();
ts4_word fn_83170AF8();
ts4_word fn_83170BF0();
ts4_word fn_83171100();
ts4_word fn_83171270();
ts4_word fn_83171C98();
ts4_word fn_831728B0();
ts4_word fn_83172938();
ts4_word fn_83172AB8();
ts4_word fn_831732A8();
ts4_word fn_83173E20();
ts4_word fn_83173F28();
ts4_word fn_831745E8();
ts4_word fn_83174E40();
ts4_word fn_83174FE0();
ts4_word fn_83175FD8();
ts4_word fn_831760C8();
ts4_word fn_83176ED8();
ts4_word fn_83218608();
ts4_word fn_832188D0();
ts4_word fn_83218A90();
ts4_word fn_8340D860();

/* Loader_DLL.xex 0x83162FF8: if_call_seq u32@0x1c, u32@0x1c, fn_83162618, u32@0x0, fn_83161B98, fn_83162618 */
ts4_word ts4l_if_call_seq_u32_off1c_83162FF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word p8;
    int t2;
    int t4;
    ts4_word t5;
    ts4_word t3;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 == 0) {
        p8 = (ts4_word)((2147483648) | 6);
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 28);
        if ((int)t2 == 0) {
            t4 = fn_83161B98((ts4_word)a2, (ts4_word)a0);
            p6 = (ts4_word)t4;
            if ((int)t4 >= 0) {
                t5 = fn_83162618((ts4_word)a2, (ts4_word)(a1 & 0xffff));
                if ((ts4_word)a3 != 0) {
                    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)((int)(t5 + 15) >> 4);
                }
                p6 = (ts4_word)0;
            }
            p7 = (ts4_word)p6;
        } else {
            t3 = fn_83162618((ts4_word)a2, (ts4_word)(a1 & 0xffff));
            if ((ts4_word)a3 != 0) {
                *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)((int)(t3 + 15) >> 4);
            }
            p7 = (ts4_word)0;
        }
        p8 = (ts4_word)p7;
    }
    return p8;
}

/* Loader_DLL.xex 0x8316F870: if_get u32@0xb0, u32@0xb8, u32@0xb8, u32@0x0, u32@0x34, vcall */
ts4_word ts4l_if_get_u32_offb0_8316F870(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p16;
    ts4_word t1;
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t15;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    p16 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
        if ((ts4_word)t3 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)t3);
            *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
        }
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 180);
        if ((ts4_word)t8 != 0) {
            t9 = *(ts4_word *)((char *)(ts4_word)((a0 + 176)) + 0);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 52))))((ts4_word)t9, (ts4_word)t8);
            *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
        }
        fn_831745E8((ts4_word)(a0 + 592));
        t15 = fn_8316E690((ts4_word)(a0 + 176));
        p16 = (ts4_word)t15;
    }
    return p16;
}

/* Loader_DLL.xex 0x831700D8: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_offcc_831700D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x831701E8: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_831701E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x83170338: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_83170338(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x831703E8: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_831703E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x831705A0: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_831705A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x83170D88: if_call_seq fn_83170A00, u32@0x0, u32@0x18, u32@0x4, u32@0x8, u32@0x18 */
ts4_word ts4l_if_call_seq_fn_83170A00_83170D88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170A00((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x831715A0: if_get u32@0x2c, u32@0x8, vcall, fn_8340D860, u32@0xac, u32@0x50 */
ts4_word ts4l_if_get_u32_off2c_831715A0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    int t9;
    ts4_word t19;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = fn_8340D860((ts4_word)t3);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((ts4_word)t4 != (ts4_word)t5) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 80))) + 8))))((ts4_word)(a0 + 80));
        t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
        if ((int)t9 != 0) {
            fn_8316FBA8((ts4_word)a0, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 80)) + 0))) + 20))))((ts4_word)(a0 + 80));
    }
    t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 44)) + 0))) + 20))))((ts4_word)(a0 + 44));
    return t19;
}

/* Loader_DLL.xex 0x831717E0: if_call_seq fn_83170708, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4l_if_call_seq_fn_83170708_831717E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170708((ts4_word)a0);
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

/* Loader_DLL.xex 0x831718F0: if_call_seq fn_83170810, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83170810_831718F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170810((ts4_word)a0);
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

/* Loader_DLL.xex 0x83171B08: if_call_seq fn_83170AF8, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83170AF8_83171B08(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170AF8((ts4_word)a0);
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

/* Loader_DLL.xex 0x83171C18: if_call_seq fn_83170BF0, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83170BF0_83171C18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170BF0((ts4_word)a0);
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

/* Loader_DLL.xex 0x83171D28: if_call_seq fn_83170908, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83170908_83171D28(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83170908((ts4_word)a0);
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

/* Loader_DLL.xex 0x83171FF0: if_get u32@0x2c, u32@0x8, vcall, fn_83171270, u32@0x98, u32@0x0 */
ts4_word ts4l_if_get_u32_off2c_83171FF0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    int t4;
    ts4_word t10;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 8))))((ts4_word)(a0 + 44));
    t4 = fn_83171270((ts4_word)a0);
    loc50[0] = (ts4_word)t4;
    if ((int)t4 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 152));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 44)) + 0))) + 20))))((ts4_word)(a0 + 44));
    fn_8316F538((ts4_word)(ts4_word)&loc50[0]);
    t10 = loc50[0];
    return t10;
}

/* Loader_DLL.xex 0x83172860: if_call_seq fn_83171C98, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_83171C98_83172860(ts4_word a0, ts4_word a1)
{

    fn_83171C98((ts4_word)(a0 + 4));
    if ((int)(a1 & 0x1) != 0) {
        fn_8316F200((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83172A00: loop_call_seq u32@0x0, u32@0x4, u32@0x0, fn_83171100 */
ts4_word ts4l_loop_call_seq_u32_off0_83172A00(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    c1 = (ts4_word)2;
    lv2 = (ts4_word)a0;
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 8)) + 0) = (ts4_word)((2147418112) | 65535);
        p3 = (ts4_word)(lv2 + 8);
        lv2 = p3;
    } while (--c1 != 0);
    fn_83171100((ts4_word)(a0 + 20));
    return a0;
}

/* Loader_DLL.xex 0x83172A68: if_call_seq fn_83172938, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_83172938_83172A68(ts4_word a0, ts4_word a1)
{

    fn_83172938((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_8316F200((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83172C70: if_call_seq fn_831728B0, fn_83171C98, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_831728B0_83172C70(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
            fn_83171C98((ts4_word)(a2 + 4));
            t4 = fn_8316F200((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_831728B0((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x83172DC0: if_call_seq fn_83172AB8, fn_83172938, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_83172AB8_83172DC0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
            fn_83172938((ts4_word)a2);
            t4 = fn_8316F200((ts4_word)a2);
            p5 = (ts4_word)t4;
        }
        p6 = (ts4_word)p5;
    } else {
        p2 = (ts4_word)a0;
        if ((ts4_word)a2 != 0) {
            t1 = fn_83172AB8((ts4_word)a2, (ts4_word)3);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    return p6;
}

/* Loader_DLL.xex 0x83173800: if_call_seq fn_831732A8, fn_8316F200 */
ts4_word ts4l_if_call_seq_fn_831732A8_83173800(ts4_word a0, ts4_word a1)
{

    fn_831732A8();
    if ((int)(a1 & 0x1) != 0) {
        fn_8316F200((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83173A60: if_get u32@0x4, u32@0x4, vcall, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4l_if_get_u32_off4_83173A60(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4))))((ts4_word)(a0 + 4));
    if ((int)t3 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1);
    }
    return t3;
}

/* Loader_DLL.xex 0x831740C8: if_call_seq fn_83173F28, u32@0x0, u32@0x18, u32@0x4, u32@0x8, u32@0x18 */
ts4_word ts4l_if_call_seq_fn_83173F28_831740C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83173F28((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83174148: if_call_seq fn_83173E20, u32@0x0, u32@0xcc, u32@0x4, u32@0x8, u32@0xcc */
ts4_word ts4l_if_call_seq_fn_83173E20_83174148(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83173E20((ts4_word)a0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 204));
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 204);
        if ((ts4_word)t3 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)t1;
        } else {
            *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)t1;
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 212);
        *(ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)t1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)(t4 + 1);
    }
    return t1;
}

/* Loader_DLL.xex 0x83174DB8: if_call_seq u32@0x0, fn_83218A90, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_off0_83174DB8(ts4_word a0, ts4_word a1)
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

/* Loader_DLL.xex 0x83174F70: if_get u32@0x0, u32@0x0, u32@0x8, vcall, u32@0x0 */
ts4_word ts4l_if_get_u32_off0_83174F70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x83175390: loop_call_seq u32@0x4, u32@0x4, u32@0x0, fn_83218A90, u32@0x0, fn_832188D0 */
ts4_word ts4l_loop_call_seq_u32_off4_83175390(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x831754C0: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x3c, u32@0x0 */
ts4_word ts4l_get_u32_off34_831754C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 44))) + 20))))((ts4_word)(t8 + 44));
    return t11;
}

/* Loader_DLL.xex 0x831756E0: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_831756E0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 32))))((ts4_word)t5, (ts4_word)0);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x83175758: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_83175758(ts4_word a0)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 40))))((ts4_word)t5);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x831757D0: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_831757D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 36))))((ts4_word)t5, (ts4_word)a1);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t8;
}

/* Loader_DLL.xex 0x83175920: get u32@0x34, u32@0x2c, u32@0x8, vcall, u32@0x90, u32@0x0 */
ts4_word ts4l_get_u32_off34_83175920(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t9;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44))) + 8))))((ts4_word)(t1 + 44));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)1, (ts4_word)a1, (ts4_word)4);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 44))) + 20))))((ts4_word)(t9 + 44));
    return t12;
}

/* Loader_DLL.xex 0x83175A30: if_get u32@0x30, fn_83218608, u32@0x38, u32@0x0, u32@0x10, vcall */
ts4_word ts4l_if_get_u32_off30_83175A30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p10;
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    t2 = fn_83218608((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48)), (ts4_word)a1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    p11 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3, (ts4_word)a1);
        p10 = (ts4_word)t6;
        if ((int)(a2 & 0x40) != 0) {
            t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 8))))((ts4_word)t3);
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x83175C30: if_call_seq fn_83174D38, fn_83174E40 */
ts4_word ts4l_if_call_seq_fn_83174D38_83175C30(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)a1;
    t1 = fn_83174E40((ts4_word)(a0 + 228), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)fn_83174D38, (ts4_word)0);
    p2 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p2 = (ts4_word)((2147483648) | 16389);
    }
    return p2;
}

/* Loader_DLL.xex 0x83175D00: if_get u32@0x4, u32@0x5c, vcall, u32@0x8, u32@0x34, u32@0x2c */
ts4_word ts4l_if_get_u32_off4_83175D00(ts4_word a0)
{
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t11;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 92))))((ts4_word)(a0 + 4));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t4 != 2) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        *(ts4_word *)((char *)(ts4_word)(t5) + 40) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 40)) - t6);
    }
    t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0, (ts4_word)1);
    return t11;
}

/* Loader_DLL.xex 0x83175EA0: if_get u32@0xcc, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_offcc_83175EA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x83175F50: if_get u32@0x18, u32@0x0, u32@0x8, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_get_u32_off18_83175F50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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

/* Loader_DLL.xex 0x831766A0: if_call_seq fn_831760C8, u32@0x0, u32@0x4, u32@0xd0, u32@0x8, u32@0xd0 */
ts4_word ts4l_if_call_seq_fn_831760C8_831766A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_831760C8((ts4_word)a0);
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

/* Loader_DLL.xex 0x83176720: if_call_seq fn_83175FD8, u32@0x0, u32@0x4, u32@0x1c, u32@0x8, u32@0x1c */
ts4_word ts4l_if_call_seq_fn_83175FD8_83176720(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83175FD8((ts4_word)a0);
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

/* Loader_DLL.xex 0x83176F40: if_call_seq fn_83176ED8, fn_83174FE0 */
ts4_word ts4l_if_call_seq_fn_83176ED8_83176F40(ts4_word a0, ts4_word a1)
{

    fn_83176ED8();
    if ((int)(a1 & 0x1) != 0) {
        fn_83174FE0((ts4_word)a0);
    }
    return a0;
}
