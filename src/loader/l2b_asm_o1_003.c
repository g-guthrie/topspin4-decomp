/* Loader_DLL.xex 0x8313F648-0x8314E0B4, executable version 0.0.0.3. */
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

extern char lbl_830028D8[];
extern char lbl_83002904[];
extern char lbl_83002920[];
extern char lbl_8300293C[];
extern char lbl_83003F5C[];
extern char lbl_83003F80[];
extern char lbl_83004078[];
extern char lbl_8353107C[];
extern char lbl_835311AC[];
extern char lbl_835312BC[];
extern char lbl_835312C4[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_830FF018();
ts4_word fn_830FF250();
ts4_word fn_8311FCF0();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_8313F138();
ts4_word fn_831463B8();
ts4_word fn_83149D00();
ts4_word fn_8314AD58();
ts4_word fn_8314AF10();
ts4_word fn_8314B808();
ts4_word fn_83153F48();
ts4_word fn_83156E08();
ts4_word fn_8315B730();
ts4_word fn_833E3AD0();

/* Loader_DLL.xex 0x8313F648: if_call_seq fn_830FF250, u32@0x0, u32@0x4, u32@0x4, u32@0x4, u32@0x4 */
ts4_word ts4l_if_call_seq_fn_830FF250_8313F648(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[4];
    int t1;
    ts4_word t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    (void)a0;
    t1 = fn_830FF250((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    p13 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        t3 = loc50[0];
        if ((ts4_word)t3 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 3) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
            t8 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
            if ((ts4_word)t8 != (ts4_word)t7) {
                *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t7;
                t9 = loc50[0];
                fn_8313F138((ts4_word)t9);
            }
            p12 = (ts4_word)0;
        } else {
            p12 = (ts4_word)((2147942400) | 87);
        }
        p13 = (ts4_word)p12;
    }
    return p13;
}

/* Loader_DLL.xex 0x83146680: call_seq lbl_8353107C, RtlEnterCriticalSection, u32@lbl_835311AC, fn_831463B8, RtlLeaveCriticalSection */
ts4_word ts4l_call_seq_lbl_8353107C_83146680(ts4_word a0)
{
    ts4_word t3;

    RtlEnterCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    t3 = fn_831463B8((ts4_word)(*(ts4_word *)lbl_835311AC), (ts4_word)a0);
    RtlLeaveCriticalSection((ts4_word)(ts4_word)lbl_8353107C);
    return t3;
}

/* Loader_DLL.xex 0x83146B90: if_get u32@0x1c, u32@0x0, u32@0x4, vcall, u32@0x1c, u32@0x0 */
ts4_word ts4l_if_get_u32_off1c_83146B90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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

/* Loader_DLL.xex 0x83146C30: if_call_seq lbl_830028D8, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_830028D8_83146C30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028D8;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831474F0: if_call_seq lbl_83002904, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83002904_831474F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002904;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83147750: if_get u32@0x0, u32@0x14, vcall, u32@0x4, u32@0xc, fn_833E3AD0 */
ts4_word ts4l_if_get_u32_off0_83147750(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word t3;
    ts4_word t5;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
    p4 = (ts4_word)a2;
    if ((ts4_word)a2 >= (ts4_word)t3) {
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_833E3AD0((ts4_word)a1, (ts4_word)(t5 + (*(ts4_word *)((char *)(ts4_word)(a0) + 12))), (ts4_word)p4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + p4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)p4;
    return 0;
}

/* Loader_DLL.xex 0x83147820: if_addr fn_83120518, lbl_83002904, u32@0x4, u32@0x0, fn_8311FCF0, u32@0x0 */
ts4_word ts4l_if_addr_fn_83120518_83147820(void)
{
    ts4_word p2;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83120518((ts4_word)8);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_83002904;
        p2 = (ts4_word)t1;
    } else {
        p2 = (ts4_word)0;
    }
    if ((ts4_word)p2 == 0) {
        p7 = (ts4_word)((2147942400) | 14);
    } else {
        t3 = fn_8311FCF0((ts4_word)p2, (ts4_word)0);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p2) + 0))) + 4))))((ts4_word)p2);
        p7 = (ts4_word)(((int)t3 >> 31) & t3);
    }
    return p7;
}

/* Loader_DLL.xex 0x83147948: if_call_seq lbl_83002920, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_83002920_83147948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002920;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83147B30: if_get u32@0x0, u32@0x0, vcall, u32@0x14, u32@0x0, u32@0x4 */
ts4_word ts4l_if_get_u32_off0_83147B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 0))))((ts4_word)a1);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t5 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 4))))((ts4_word)t5);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x83147BD8: if_call_seq lbl_8300293C, u32@0x0, fn_83120540 */
ts4_word ts4l_if_call_seq_lbl_8300293C_83147BD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300293C;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83147EA8: if_call_seq fn_83120518, u32@0x8, u32@0x4, u32@0x14, lbl_8300293C, u32@0x10 */
ts4_word ts4l_if_call_seq_fn_83120518_83147EA8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = fn_83120518((ts4_word)24);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_8300293C;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
        p5 = (ts4_word)t1;
    } else {
        p5 = (ts4_word)0;
    }
    if ((ts4_word)p5 == 0) {
        p6 = (ts4_word)((2147942400) | 14);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p5;
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Loader_DLL.xex 0x83147F48: if_addr fn_83120518, lbl_83002920, u32@0x4, u32@0x0, fn_8311FCF0, u32@0x0 */
ts4_word ts4l_if_addr_fn_83120518_83147F48(void)
{
    ts4_word p2;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;

    t1 = fn_83120518((ts4_word)8);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_83002920;
        p2 = (ts4_word)t1;
    } else {
        p2 = (ts4_word)0;
    }
    if ((ts4_word)p2 == 0) {
        p7 = (ts4_word)((2147942400) | 14);
    } else {
        t3 = fn_8311FCF0((ts4_word)p2, (ts4_word)0);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p2) + 0))) + 4))))((ts4_word)p2);
        p7 = (ts4_word)(((int)t3 >> 31) & t3);
    }
    return p7;
}

/* Loader_DLL.xex 0x83148430: get u32@0x0, u32@0x0, u8@0x4, u8@0x4, u8@0x5, u8@0x5 */
void ts4l_get_u32_off0_83148430(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(unsigned char *)((char *)(ts4_word)(a1) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 4));
    *(unsigned char *)((char *)(ts4_word)(a1) + 5) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 5));
    *(unsigned char *)((char *)(ts4_word)(a1) + 6) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 6));
    *(unsigned char *)((char *)(ts4_word)(a1) + 7) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 7));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83149D68: loop_call_seq u32@0x10, u32@0x10, u32@0x14, fn_83149D00, u8@0xc, u32@0x10 */
ts4_word ts4l_loop_call_seq_u32_off10_83149D68(ts4_word a0)
{
    ts4_word lv2;
    ts4_word p7;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    lv2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 16);
        t5 = fn_83149D00((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 20)), (ts4_word)t3);
        *(unsigned char *)((char *)(ts4_word)(lv2) + 12) = (unsigned char)t5;
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        p7 = (ts4_word)t3;
        lv2 = p7;
    } while ((ts4_word)p7 != (ts4_word)t6);
    return t5;
}

/* Loader_DLL.xex 0x83149E08: if_addr lbl_83003F5C, u32@0x0, fn_83156E08, fn_8315B730, u32@0x8, u32@0x0 */
ts4_word ts4l_if_addr_lbl_83003F5C_83149E08(ts4_word a0)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F5C;
    t1 = fn_83156E08();
    fn_8315B730((ts4_word)t1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p7 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3);
        p7 = (ts4_word)t6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p7;
}

/* Loader_DLL.xex 0x8314A0D8: if_call_seq fn_830FF018, u32@0x4, u32@0x10, u32@0x8 */
ts4_word ts4l_if_call_seq_fn_830FF018_8314A0D8(ts4_word a0)
{
    ts4_word p2;
    ts4_word t1;

    t1 = fn_830FF018((ts4_word)400);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p2 = (ts4_word)((2147942400) | 14);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)50;
        p2 = (ts4_word)0;
    }
    return p2;
}

/* Loader_DLL.xex 0x8314A8C0: if_get u32@0x9c, u32@0xa0, u32@0x0, u32@0x98, vcall, u32@0xbc */
ts4_word ts4l_if_get_u32_off9c_8314A8C0(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p21;
    ts4_word p22;
    ts4_word p23;
    int t1;
    ts4_word t4;
    int t5;
    int t14;
    ts4_word t20;
    ts4_word t11;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((int)t1 != 0) {
        p23 = (ts4_word)((2147483648) | 65535);
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)a2;
        t4 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 152))))((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 180);
        if ((int)t5 == 0) {
            t14 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0, (ts4_word)a1);
            p21 = (ts4_word)t14;
            if ((int)t14 >= 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 156)) + 1);
                if ((int)a2 == 0) {
                    fn_83153F48((ts4_word)t14);
                }
                t20 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)1);
                p21 = (ts4_word)(((int)t20 >> 31) & t20);
            }
            p22 = (ts4_word)p21;
        } else {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 156)) + 1);
            if ((int)a2 == 0) {
                fn_83153F48((ts4_word)t4);
            }
            t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0, (ts4_word)1);
            p22 = (ts4_word)(((int)t11 >> 31) & t11);
        }
        p23 = (ts4_word)p22;
    }
    return p23;
}

/* Loader_DLL.xex 0x8314AB78: get  */
ts4_word ts4l_get_8314AB78(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 8));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 12));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 20));
    *(float *)((char *)(ts4_word)(a1) + 16) = (*(float *)((char *)(ts4_word)(a0) + 24));
    *(float *)((char *)(ts4_word)(a1) + 20) = (*(float *)((char *)(ts4_word)(a0) + 28));
    *(float *)((char *)(ts4_word)(a1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 32));
    *(float *)((char *)(ts4_word)(a1) + 28) = (*(float *)((char *)(ts4_word)(a0) + 36));
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a0) + 40));
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a0) + 44));
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 48));
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 52));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 56));
    *(float *)((char *)(ts4_word)(a1) + 52) = (*(float *)((char *)(ts4_word)(a0) + 60));
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 64));
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 68));
    return 0;
}

/* Loader_DLL.xex 0x8314ACC8: get  */
ts4_word ts4l_get_8314ACC8(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 72));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 76));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 80));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 84));
    *(float *)((char *)(ts4_word)(a1) + 16) = (*(float *)((char *)(ts4_word)(a0) + 88));
    *(float *)((char *)(ts4_word)(a1) + 20) = (*(float *)((char *)(ts4_word)(a0) + 92));
    *(float *)((char *)(ts4_word)(a1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 96));
    *(float *)((char *)(ts4_word)(a1) + 28) = (*(float *)((char *)(ts4_word)(a0) + 100));
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a0) + 104));
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a0) + 108));
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 112));
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 116));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 120));
    *(float *)((char *)(ts4_word)(a1) + 52) = (*(float *)((char *)(ts4_word)(a0) + 124));
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 128));
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 132));
    return 0;
}

/* Loader_DLL.xex 0x8314B130: if_set u32@0x94, u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x3c */
ts4_word ts4l_if_set_u32_off94_8314B130(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)a1;
    if ((ts4_word)a1 == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
        p7 = (ts4_word)0;
    } else {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)a0);
        p7 = (ts4_word)t3;
    }
    return p7;
}

/* Loader_DLL.xex 0x8314B190: if_set u32@0x94, u32@0x0, u32@0x8, vcall, u32@0x0, u32@0x3c */
ts4_word ts4l_if_set_u32_off94_8314B190(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)a1;
    if ((ts4_word)a1 == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
        p7 = (ts4_word)0;
    } else {
        t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 8))))((ts4_word)a1, (ts4_word)a0);
        p7 = (ts4_word)t3;
    }
    return p7;
}

/* Loader_DLL.xex 0x8314B2C0: if_set u32@0x98, u32@0x0, u32@0x30, vcall */
ts4_word ts4l_if_set_u32_off98_8314B2C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        p4 = (ts4_word)((2147942400) | 87);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0, (ts4_word)0, (ts4_word)0);
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8314B370: if_get u32@0xa4, u32@0x9c, u32@0xa4, u32@0x0, u32@0x78, vcall */
ts4_word ts4l_if_get_u32_offa4_8314B370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    int t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 164);
    if ((ts4_word)t1 != (ts4_word)a1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)a1;
        if ((int)t2 > 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0);
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x8314B3C0: if_get u32@0xac, u32@0x9c, u32@0xac, u32@0x0, u32@0xa4, vcall */
ts4_word ts4l_if_get_u32_offac_8314B3C0(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    int t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
    if ((int)a1 != (int)t1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)a1;
        if ((int)t2 > 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 164))))((ts4_word)a0);
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x8314B410: if_get u32@0xb0, u32@0x9c, u32@0xb0, u32@0x0, u32@0xa8, vcall */
ts4_word ts4l_if_get_u32_offb0_8314B410(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    int t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    if ((ts4_word)a1 != (ts4_word)t1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
        *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)a1;
        if ((int)t2 > 0) {
            ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 168))))((ts4_word)a0);
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x8314B8C0: call_seq lbl_83004078, u32@0x0, fn_8314B808, lbl_83003F80, u32@0x0 */
ts4_word ts4l_call_seq_lbl_83004078_8314B8C0(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83004078;
    t1 = fn_8314B808();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83003F80;
    return t1;
}

/* Loader_DLL.xex 0x8314BAE0: get u32@0x14c, u32@0x88, u32@0x0, u32@0x34, vcall, u32@0x14c */
ts4_word ts4l_get_u32_off14c_8314BAE0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t15;
    ts4_word t19;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)t1, (ts4_word)0, (ts4_word)20, (ts4_word)(((~(t2 | t2)) >> 4) & 0x1));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 52))))((ts4_word)t6, (ts4_word)0, (ts4_word)16, (ts4_word)(((~(t7 | t7)) >> 5) & 0x1));
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 52))))((ts4_word)t11, (ts4_word)0, (ts4_word)24, (ts4_word)1);
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 52))))((ts4_word)t15, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    t22 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t19) + 0))) + 52))))((ts4_word)t19, (ts4_word)0, (ts4_word)4, (ts4_word)0);
    return t22;
}

/* Loader_DLL.xex 0x8314BC88: if_get u32@0xb0, u32@0x14c, u32@0x0, u32@0x30 */
ts4_word ts4l_if_get_u32_offb0_8314BC88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word p3;
    ts4_word p4;
    ts4_word p5;
    ts4_word p6;
    ts4_word p8;
    ts4_word t1;
    ts4_word t9;

    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
    p6 = (ts4_word)a7;
    p8 = (ts4_word)15;
    if ((ts4_word)t1 != 0) {
        p2 = (ts4_word)15;
        if ((int)(t1 & 0x8) == 0) {
            p2 = (ts4_word)7;
        }
        p3 = (ts4_word)p2;
        if ((int)(t1 & 0x1) == 0) {
            p3 = (ts4_word)(p2 & 0xfffffffe);
        }
        p4 = (ts4_word)p3;
        if ((int)(t1 & 0x2) == 0) {
            p4 = (ts4_word)(p3 & 0xfffffffd);
        }
        p5 = (ts4_word)p4;
        if ((int)(t1 & 0x4) == 0) {
            p5 = (ts4_word)(p4 & 0xfffffffb);
        }
        p6 = (ts4_word)(t1 & 0x2);
        p8 = (ts4_word)p5;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 48))))((ts4_word)t9, (ts4_word)212, (ts4_word)p8, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)p6);
}

/* Loader_DLL.xex 0x8314C238: get fn_8314AD58, u32@0x14c, u32@0x0, u32@0x24, vcall */
ts4_word ts4l_get_fn_8314AD58_8314C238(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    fn_8314AD58();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 36))))((ts4_word)t2, (ts4_word)0, (ts4_word)(a0 + 200), (ts4_word)4);
    return t5;
}

/* Loader_DLL.xex 0x8314C288: get fn_8314AF10, u32@0x14c, u32@0x0, u32@0x24, vcall, u32@0x0 */
ts4_word ts4l_get_fn_8314AF10_8314C288(ts4_word a0)
{
    ts4_word t2;
    ts4_word t11;

    fn_8314AF10();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 36))))((ts4_word)t2, (ts4_word)4, (ts4_word)(a0 + 264), (ts4_word)4);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 172))))((ts4_word)a0);
    t11 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 120))))((ts4_word)a0);
    return t11;
}

/* Loader_DLL.xex 0x8314C8E0: if_get u32@0x14c, u32@0x0, u32@0x10, vcall, u32@0x0, u32@0x0 */
ts4_word ts4l_if_get_u32_off14c_8314C8E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    if ((int)t4 == 0) {
        p8 = (ts4_word)((2147942400) | 87);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
        p8 = (ts4_word)0;
    }
    return p8;
}

/* Loader_DLL.xex 0x8314CAC8: if_get u32@0x14, u32@0x0, u32@0x4, vcall, u32@0x10, u32@0x14 */
ts4_word ts4l_if_get_u32_off14_8314CAC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p20;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    if ((ts4_word)t6 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 192))))((ts4_word)t7);
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t11) + 20))))((ts4_word)t10, (ts4_word)t12, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p20 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 8))))((ts4_word)t16);
        p20 = (ts4_word)t19;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    return p20;
}

/* Loader_DLL.xex 0x8314CEC0: if_get u32@0x14, u32@0x0, u32@0x4, vcall, u32@0x10, u32@0x14 */
ts4_word ts4l_if_get_u32_off14_8314CEC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p20;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    if ((ts4_word)t6 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 192))))((ts4_word)t7);
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t11) + 20))))((ts4_word)t10, (ts4_word)t12, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p20 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 8))))((ts4_word)t16);
        p20 = (ts4_word)t19;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return p20;
}

/* Loader_DLL.xex 0x8314D270: if_get u32@0x14, u32@0x0, u32@0x4, vcall, u32@0x10, u32@0x14 */
ts4_word ts4l_if_get_u32_off14_8314D270(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p20;
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t16;
    ts4_word t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    if ((ts4_word)t6 != 0) {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 192))))((ts4_word)t7);
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t11) + 20))))((ts4_word)t10, (ts4_word)t12, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p20 = (ts4_word)t16;
    if ((ts4_word)t16 != 0) {
        t19 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t16) + 0))) + 8))))((ts4_word)t16);
        p20 = (ts4_word)t19;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return p20;
}

/* Loader_DLL.xex 0x8314D320: if_get u32@0x0, u32@0xc, vcall, u32@0xc, u32@0x0, u32@0x4 */
ts4_word ts4l_if_get_u32_off0_8314D320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p23;
    ts4_word p24;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t9;
    ts4_word t12;
    int t15;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    loc50[0] = (ts4_word)128;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 12))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1);
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 192))))((ts4_word)a1);
    t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 12))))((ts4_word)t9, (ts4_word)a2, (ts4_word)a3, (ts4_word)(a0 + 20));
    *(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0) = (ts4_word)t12;
    if ((ts4_word)t12 == 0) {
        t15 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 220))))((ts4_word)a1, (ts4_word)128, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3, (ts4_word)(a0 + 20));
        p23 = (ts4_word)t15;
        if ((int)t15 >= 0) {
            t18 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 192))))((ts4_word)a1);
            t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 0);
            t20 = *(ts4_word *)((char *)(ts4_word)((a0 + 20)) + 0);
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t19) + 28))))((ts4_word)t18, (ts4_word)a2, (ts4_word)a3, (ts4_word)t20, (ts4_word)(a0 + 16));
            p23 = (ts4_word)0;
        }
        p24 = (ts4_word)p23;
    } else {
        p24 = (ts4_word)0;
    }
    return p24;
}

/* Loader_DLL.xex 0x8314DAB0: if_get u32@lbl_835312BC, u32@0x0, u32@0x4, vcall, u32@lbl_835312BC */
ts4_word ts4l_if_get_u32_lbl_835312BC_8314DAB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile ts4_word *)lbl_835312BC;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1);
    }
    *(volatile ts4_word *)lbl_835312BC = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x8314DD28: if_get u32@lbl_835312C4, u32@lbl_835312C4, u32@0x0, u32@0x8, vcall, u32@lbl_835312C4 */
ts4_word ts4l_if_get_u32_lbl_835312C4_8314DD28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p11;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p11 = (ts4_word)((2147942400) | 87);
    } else {
        t2 = *(ts4_word *)lbl_835312C4;
        if ((ts4_word)t2 == (ts4_word)a0) {
            if ((ts4_word)t2 != 0) {
                ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 8))))((ts4_word)t2);
            }
            *(ts4_word *)lbl_835312C4 = (ts4_word)0;
        }
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
        p11 = (ts4_word)0;
    }
    return p11;
}

/* Loader_DLL.xex 0x8314DDB8: if_get u32@0x0, u32@0x98, vcall */
ts4_word ts4l_if_get_u32_off0_8314DDB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p4 = (ts4_word)((2147942400) | 87);
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 152))))((ts4_word)a0);
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8314E028: if_get u32@0x0, u32@0x10, vcall */
ts4_word ts4l_if_get_u32_off0_8314E028(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p4 = (ts4_word)((2147942400) | 87);
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Loader_DLL.xex 0x8314E070: if_get u32@0x0, u32@0x14, vcall */
ts4_word ts4l_if_get_u32_off0_8314E070(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        p4 = (ts4_word)((2147942400) | 87);
    } else {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
        p4 = (ts4_word)0;
    }
    return p4;
}
