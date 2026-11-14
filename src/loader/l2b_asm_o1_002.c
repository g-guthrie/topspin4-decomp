/* Loader_DLL.xex 0x8311C5D0-0x83146B04, executable version 0.0.0.3. */
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

extern char fn_83141BA8[];
extern char fn_831426B8[];
extern char lbl_83002270[];
extern char lbl_830028A4[];
extern char lbl_8352F86C[];
extern char lbl_8353107C[];
extern char lbl_83531194[];
extern char lbl_835311A8[];
extern char lbl_835311AC[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830FFBE8();
ts4_word fn_83107E40();
ts4_word fn_83107EA0();
ts4_word fn_83116F28();
ts4_word fn_83118238();
ts4_word fn_8311BB08();
ts4_word fn_8311BCF8();
ts4_word fn_8311DAD8();
ts4_word fn_8311DBA0();
ts4_word fn_8311E3B8();
ts4_word fn_8311E460();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_83120AC8();
ts4_word fn_83120C18();
ts4_word fn_83124260();
ts4_word fn_831256E8();
ts4_word fn_8312D868();
ts4_word fn_8312DF48();
ts4_word fn_8313CF80();
ts4_word fn_8313D0C0();
ts4_word fn_8313F080();
ts4_word fn_8313F508();
ts4_word fn_8313F548();
ts4_word fn_8313F928();
ts4_word fn_8313FD78();
ts4_word fn_83140430();
ts4_word fn_83140C58();
ts4_word fn_83142AA8();
ts4_word fn_83142C60();
ts4_word fn_83143790();
ts4_word fn_83143B40();
ts4_word fn_83144558();
ts4_word fn_83145588();
ts4_word fn_831458C0();
ts4_word fn_83145F40();
ts4_word fn_831460E0();
ts4_word fn_831461B0();
ts4_word fn_831468C8();
ts4_word fn_833E2CA0();
ts4_word fn_833E3AD0();

/* Loader_DLL.xex 0x8311C5D0: if_call_seq u32@0x1c, u32@0x20, fn_8311BCF8, fn_8311BB08 */
ts4_word ts4l_if_call_seq_u32_off1c_8311C5D0(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a2 >= 0 && (int)a2 < (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 28))) {
        fn_8311BCF8((ts4_word)a1, (ts4_word)(((int)a2 * 68) + (*(ts4_word *)((char *)(ts4_word)(a0) + 32))));
        fn_8311BB08((ts4_word)a0);
        p5 = (ts4_word)0;
    } else {
        p5 = (ts4_word)((2147942400) | 87);
    }
    return p5;
}

/* Loader_DLL.xex 0x831291F8: if_call_seq fn_8311E3B8, fn_83124260, fn_83118238, fn_8311E460, fn_830FFBE8 */
ts4_word ts4l_if_call_seq_fn_8311E3B8_831291F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word p7;
    int t1;
    ts4_word t6;
    ts4_word t3;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_8311E3B8((ts4_word)a2);
    if ((int)t1 != 0) {
        t6 = fn_830FFBE8((ts4_word)a0, (ts4_word)a2);
        p7 = (ts4_word)t6;
    } else {
        if ((ts4_word)a1 == 0) {
            t3 = fn_83118238((ts4_word)0);
            p4 = (ts4_word)t3;
        } else {
            t2 = fn_83124260((ts4_word)a1);
            p4 = (ts4_word)t2;
        }
        t5 = fn_8311E460((ts4_word)a0, (ts4_word)p4, (ts4_word)a2);
        p7 = (ts4_word)t5;
    }
    return p7;
}

/* Loader_DLL.xex 0x831339A0: if_call_seq u32@0x8, u32@0x18, u32@0xf0, u32@0x10, u32@0xf0, u32@0x10 */
ts4_word ts4l_if_call_seq_u32_off8_831339A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t13;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 240);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        if ((ts4_word)(t4 & 0x4000) == 16384) {
            fn_8312D868((ts4_word)a0, (ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
            fn_83120AC8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0)));
        } else {
            fn_8312D868((ts4_word)a0, (ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
            fn_8312DF48((ts4_word)a0, (ts4_word)t5, (ts4_word)0);
        }
        fn_83120C18((ts4_word)t5, (ts4_word)(ts4_word)&loc50[0]);
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
        if ((ts4_word)t13 == 0) {
            fn_831256E8((ts4_word)a0, (ts4_word)a1);
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x8313D000: if_call_seq fn_83120518, u32@0x0, fn_833E3AD0 */
ts4_word ts4l_if_call_seq_fn_83120518_8313D000(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t1;

    t1 = fn_83120518((ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p3 = (ts4_word)((2147942400) | 14);
    } else {
        fn_833E3AD0((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Loader_DLL.xex 0x8313D120: if_call_seq fn_8313D0C0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8313D0C0_8313D120(ts4_word a0, ts4_word a1)
{

    fn_8313D0C0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8313D1F0: if_get u8@0x0, u8@0x1, u16@0x1, u32@0x1 */
ts4_word ts4l_if_get_u8_off0_8313D1F0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((int)(t1 & 0xffffff80) != 0) {
        if ((int)(t1 & 0xffffff7f) != 1) {
            if ((int)(t1 & 0xffffff7f) != 2) {
                if ((int)(t1 & 0xffffff7f) != 4) {
                    return 0;
                }
                return (*(ts4_word *)((char *)(ts4_word)(a0) + 1));
            }
            return (*(unsigned short *)((char *)(ts4_word)(a0) + 1));
        }
        return (*(unsigned char *)((char *)(ts4_word)(a0) + 1));
    }
    return t1;
}

/* Loader_DLL.xex 0x8313D338: get u32@0x1c, u32@0x20, u32@0x18, u32@0x14, u32@0x4, u32@0x24 */
ts4_word ts4l_get_u32_off1c_8313D338(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((((((((((((t1 << 1) + t2) + t3) + t4) + t5) << 1) + t6) + t7) << 1) + ((int)t8 * 5)) + ((int)t9 * 11)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 16))) << 2);
}

/* Loader_DLL.xex 0x8313D3C0: if_call_seq fn_83120518, u32@0x0, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_83120518_8313D3C0(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_83120518((ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)((2147942400) | 14);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        p2 = (ts4_word)0;
    }
    return p2;
}

/* Loader_DLL.xex 0x8313E400: if_call_seq fn_83144558, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83144558_8313E400(ts4_word a0, ts4_word a1)
{

    fn_83144558((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8313F138: if_call_seq u32@0x8, u32@0x0, fn_8311DAD8, u32@0x8, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off8_8313F138(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p6 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0x1) != 1) {
        t3 = fn_8311DAD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)((2864381952) | 52445), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) | 1);
        p6 = (ts4_word)t3;
    }
    return p6;
}

/* Loader_DLL.xex 0x8313F5F8: if_call_seq fn_8313F080, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_8313F080_8313F5F8(ts4_word a0, ts4_word a1)
{

    fn_8313F080((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x8313F6C8: if_call_seq u32@0x0, fn_8313F508, u32@0x8, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off0_8313F6C8(ts4_word a0)
{
    int t2;

    t2 = fn_8313F508((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    if ((int)t2 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) | 32);
    }
    return t2;
}

/* Loader_DLL.xex 0x8313F710: if_call_seq u32@0x0, fn_8313F548, u32@0x8, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off0_8313F710(ts4_word a0)
{
    int t2;

    t2 = fn_8313F548((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    if ((int)t2 >= 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) & 0xffffffdf);
    }
    return t2;
}

/* Loader_DLL.xex 0x8313F990: call_seq u32@0x8, fn_83107E40, u32@0x4, u32@0x4, fn_83107EA0 */
ts4_word ts4l_call_seq_u32_off8_8313F990(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = fn_83107E40();
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
    t3 = fn_83107EA0((ts4_word)t1);
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(t3) + 4));
    return a0;
}

/* Loader_DLL.xex 0x8313FC20: if_call_seq fn_8313F928, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_8313F928_8313FC20(ts4_word a0)
{
    ts4_word p4;
    int t1;

    t1 = fn_8313F928();
    if ((int)t1 == -1) {
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4))));
    }
    return p4;
}

/* Loader_DLL.xex 0x8313FF80: if_call_seq fn_8313F928, fn_8313FD78 */
ts4_word ts4l_if_call_seq_fn_8313F928_8313FF80(ts4_word a0)
{
    ts4_word p3;
    int t1;
    ts4_word t2;

    t1 = fn_8313F928();
    if ((int)t1 == -1) {
        p3 = (ts4_word)0;
    } else {
        t2 = fn_8313FD78((ts4_word)a0, (ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x831406E0: call_seq fn_83140430, u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8 */
ts4_word ts4l_call_seq_fn_83140430_831406E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return t1;
}

/* Loader_DLL.xex 0x83140738: call_seq fn_83140430, u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8 */
ts4_word ts4l_call_seq_fn_83140430_83140738(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return t1;
}

/* Loader_DLL.xex 0x83140790: call_seq fn_83140430, u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8 */
ts4_word ts4l_call_seq_fn_83140430_83140790(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return t1;
}

/* Loader_DLL.xex 0x83140C90: call_seq fn_83140430, u32@0x0 */
ts4_word ts4l_call_seq_fn_83140430_83140C90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83140430((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)8;
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return t1;
}

/* Loader_DLL.xex 0x831416B8: if_call_seq u32@0x0, u32@0x8, fn_83120540, u32@0x0, u32@0x8, u32@0x4 */
ts4_word ts4l_if_call_seq_u32_off0_831416B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)a0;
    if ((int)(t1 & 0x1) == 0) {
        t3 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
        p4 = (ts4_word)t3;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return p4;
}

/* Loader_DLL.xex 0x83142458: if_call_seq u32@0x0, u16@0x0, fn_83120540, u32@0x4 */
ts4_word ts4l_if_call_seq_u32_off0_83142458(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    p3 = (ts4_word)a2;
    if ((ts4_word)a2 != 0 && (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a2) + 0)) == 0) {
        fn_83120540((ts4_word)a2);
        p3 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p3;
    return a0;
}

/* Loader_DLL.xex 0x831424B0: if_call_seq u32@0x0, u16@0x0, fn_83120540, u32@0x4 */
ts4_word ts4l_if_call_seq_u32_off0_831424B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p3;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    p3 = (ts4_word)a2;
    if ((ts4_word)a2 != 0 && (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a2) + 0)) == 0) {
        fn_83120540((ts4_word)a2);
        p3 = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p3;
    return a0;
}

/* Loader_DLL.xex 0x83142B08: if_call_seq fn_831426B8, fn_83142AA8, u32@0x0, u32@0x8, fn_83141BA8, fn_833E2CA0 */
ts4_word ts4l_if_call_seq_fn_831426B8_83142B08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p5;
    int t1;
    ts4_word t2;

    t1 = fn_83142AA8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)fn_831426B8);
    p5 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        fn_833E2CA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t2, (ts4_word)4, (ts4_word)(ts4_word)fn_83141BA8);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x83142D90: if_call_seq fn_83116F28, fn_83142C60, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83116F28_83142D90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    int t1;
    ts4_word t4;
    ts4_word t5;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t1 = fn_83116F28((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    if ((int)t1 != 0) {
        fn_83142C60((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    }
    t4 = loc50[0];
    t5 = fn_83120540((ts4_word)t4);
    return t5;
}

/* Loader_DLL.xex 0x83143940: if_get u32@0x8, u32@0x0, u32@0x50, vcall, lbl_8352F86C, RtlEnterCriticalSection */
ts4_word ts4l_if_get_u32_off8_83143940(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t8;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)t1, (ts4_word)0, (ts4_word)0);
        RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8352F86C);
        fn_83143790((ts4_word)(ts4_word)lbl_83531194, (ts4_word)(a0 + 8), (ts4_word)(a0 + 12));
        RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8352F86C);
        t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        fn_8311DBA0((ts4_word)t8, (ts4_word)((2864381952) | 52445));
    }
    return 0;
}

/* Loader_DLL.xex 0x83144090: if_call_seq u32@0x4, fn_83120540, fn_83143B40, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_off4_83144090(ts4_word a0, ts4_word a1)
{

    fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    fn_83143B40((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83144470: if_call_seq fn_83140C58, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83140C58_83144470(ts4_word a0, ts4_word a1)
{

    fn_83140C58((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83144508: if_get u16@0x0, u32@0xc, u32@0x8, fn_8313CF80, u32@0x8 */
ts4_word ts4l_if_get_u16_off0_83144508(ts4_word a0, ts4_word a1)
{
    unsigned short t1;
    ts4_word t4;
    ts4_word t2;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    if ((int)(t1 & 0x8) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(t4) + 4));
        *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(t4) + 8));
        *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(t4) + 12));
        *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(t4) + 16));
        return a0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return fn_8313CF80((ts4_word)(t2 + 24), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1, (ts4_word)16);
}

/* Loader_DLL.xex 0x83144D60: if_get u32@0x1c, u32@0x0, u32@0x4, vcall, u32@0x1c, u32@0x0 */
ts4_word ts4l_if_get_u32_off1c_83144D60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1);
    }
    return 0;
}

/* Loader_DLL.xex 0x83144EC0: if_call_seq lbl_830028A4, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_830028A4_83144EC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028A4;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831455F0: if_call_seq fn_83145588, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_83145588_831455F0(ts4_word a0)
{
    ts4_word p4;
    int t1;

    t1 = fn_83145588();
    if ((int)t1 == -1) {
        p4 = (ts4_word)0;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((t1 << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4))));
    }
    return p4;
}

/* Loader_DLL.xex 0x83145AD8: if_call_seq fn_831458C0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_831458C0_83145AD8(ts4_word a0, ts4_word a1)
{

    fn_831458C0();
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83145FE0: if_call_seq fn_83145F40, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_83145F40_83145FE0(ts4_word a0, ts4_word a1)
{

    fn_83145F40();
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83146240: if_call_seq fn_831460E0, fn_83120540 */
ts4_word ts4l_if_call_seq_fn_831460E0_83146240(ts4_word a0, ts4_word a1)
{

    fn_831460E0((ts4_word)a0);
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83146368: call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311A8, RtlLeaveCriticalSection */
ts4_word ts4l_call_seq_lbl_8353107C_83146368(ts4_word a0)
{
    ts4_word t2;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    *(ts4_word *)lbl_835311A8 = (ts4_word)a0;
    t2 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t2;
}

/* Loader_DLL.xex 0x831463B8: if_get fn_831461B0, u32@0x4, u32@0x0, u32@0x0, vcall, u32@0x4 */
ts4_word ts4l_if_get_fn_831461B0_831463B8(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_831461B0((ts4_word)a0, (ts4_word)a1);
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 0))))((ts4_word)t2);
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
    } else {
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Loader_DLL.xex 0x831467B0: if_call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_831461B0, u32@0x8, RtlLeaveCriticalSection */
ts4_word ts4l_if_call_seq_lbl_8353107C_831467B0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t3 = fn_831461B0((ts4_word)(*(ts4_word *)lbl_835311AC), (ts4_word)a0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
    }
    t4 = RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t4;
}

/* Loader_DLL.xex 0x831469E0: call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_831468C8, RtlLeaveCriticalSection */
ts4_word ts4l_call_seq_lbl_8353107C_831469E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t3 = fn_831468C8((ts4_word)(*(ts4_word *)lbl_835311AC), (ts4_word)a0, (ts4_word)a1);
    RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t3;
}

/* Loader_DLL.xex 0x83146AC0: if_call_seq lbl_83002270, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83002270_83146AC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002270;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}
