/* Loader_DLL.xex 0x83273180-0x83319FF8, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char fn_83316A28[];
extern char fn_83316BE8[];
extern char fn_833186A0[];
extern char fn_83318818[];
extern char lbl_8353B588[];
extern char lbl_8354A498[];
extern char lbl_8354A49C[];
ts4l_word RtlEnterCriticalSection();
ts4l_word RtlLeaveCriticalSection();
ts4l_word fn_832522A8();
ts4l_word fn_8327FA98();
ts4l_word fn_832804F8();
ts4l_word fn_83286398();
ts4l_word fn_832863B0();
ts4l_word fn_8329F758();
ts4l_word fn_8329FBB0();
ts4l_word fn_8329FF70();
ts4l_word fn_832A10F0();
ts4l_word fn_832A8DE8();
ts4l_word fn_832DBB50();
ts4l_word fn_832DBED8();
ts4l_word fn_832DC970();
ts4l_word fn_8332FE90();
ts4l_word fn_8332FF58();
ts4l_word fn_8333B9D8();
ts4l_word fn_8335C1C8();
ts4l_word fn_8335C1E8();
ts4l_word fn_8335D0D0();
ts4l_word fn_8335D0F0();
ts4l_word fn_83366F98();
ts4l_word fn_833674A0();
ts4l_word fn_833E3A30();
ts4l_word fn_833E3AD0();
ts4l_word fn_834138F0();
ts4l_word fn_83495D48();
ts4l_word fn_834F98B8();
ts4l_word fn_8350E030();

/* Loader_DLL.xex 0x83273180: if_call_seq u32@0x8, fn_832522A8, u32@0x8, u32@0xc, fn_832522A8, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_off8_83273180(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    if ((ts4l_word)t1 != 0) {
        fn_832522A8((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_832522A8((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
        p6 = (ts4l_word)t5;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    return p6;
}

/* Loader_DLL.xex 0x8328E250: if_call_seq fn_8329FBB0, u32@0xeb0, u32@0x0, u32@0xef8, u32@0x4, u32@0xefc */
ts4l_word ts4l_if_call_seq_fn_8329FBB0_8328E250(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t6;

    t1 = fn_8329FBB0((ts4l_word)(a0 + 3760), (ts4l_word)(a0 + 3764));
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3760);
    if ((ts4l_word)t2 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3832) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 0));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3836) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 4));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3840) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 8));
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)((a0 + 3764)) + 0);
    if ((ts4l_word)t6 != 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3844) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t6) + 0));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3848) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t6) + 4));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 3852) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t6) + 8));
    }
    return t1;
}

/* Loader_DLL.xex 0x83292BB8: if_get u32@0x728, u32@0x730, u32@0x734, u32@0x74c, u32@0x700, u32@0x72c */
void ts4l_if_get_u32_off728_83292BB8(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;
    int t5;
    ts4l_word t6;
    ts4l_word t7;
    ts4l_word t8;
    ts4l_word t9;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1832);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1840);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1844);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1868);
    t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1792);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1836) = (ts4l_word)t1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1856) = (ts4l_word)t2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1860) = (ts4l_word)t3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1864) = (ts4l_word)t4;
    if ((int)t5 == 0) {
        return;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1828);
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1848);
    t8 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1852);
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 1872);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1800) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1836) = (ts4l_word)t6;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1856) = (ts4l_word)t7;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1860) = (ts4l_word)t8;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 1864) = (ts4l_word)t9;
    return;
}

/* Loader_DLL.xex 0x832934B0: call_seq fn_8329FBB0, u32@0xea0, u32@0xeb0, u32@0x0, u32@0xec0, u32@0x4 */
ts4l_word ts4l_call_seq_fn_8329FBB0_832934B0(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    t1 = fn_8329FBB0((ts4l_word)(a0 + 3760), (ts4l_word)(a0 + 3744));
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3744);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3760);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3776) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3780) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3784) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 8));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3832) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3836) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3840) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 8));
    return t1;
}

/* Loader_DLL.xex 0x83293520: call_seq fn_8329FBB0, u32@0xeac, u32@0xeb0, u32@0x0, u32@0xed8, u32@0x4 */
ts4l_word ts4l_call_seq_fn_8329FBB0_83293520(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;

    t1 = fn_8329FBB0((ts4l_word)(a0 + 3760), (ts4l_word)(a0 + 3756));
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3756);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3760);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3800) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3804) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3808) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t2) + 8));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3832) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 0));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3836) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 4));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 3840) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 8));
    return t1;
}

/* Loader_DLL.xex 0x8329B030: if_call_seq u32@0xe6c, u32@0x54, fn_8327FA98, u32@0xe20, u32@0x54, fn_832804F8 */
ts4l_word ts4l_if_call_seq_u32_offe6c_8329B030(ts4l_word a0)
{
    ts4l_word loc50[4];
    int t1;
    int t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3692);
    if ((int)t1 == 0) {
        t3 = fn_8327FA98((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 84)), (ts4l_word)(ts4l_word)&loc50[0]);
        t4 = loc50[0];
        if ((int)t3 == (int)((1 << (t4 + -1)) + -1)) {
            t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3616);
            t7 = fn_832804F8((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 84)), (ts4l_word)(t5 + 16));
            return ((t7 + -1) == 0);
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x8329B800: if_get u8@0x0, u8@0x0, u8@0x0, u8@0x1, u8@0x1, u8@0x1 */
void ts4l_if_get_u8_off0_8329B800(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    unsigned char t1;
    unsigned char t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4l_word)(a0) + 0);
    if ((int)((signed char)t1) < (int)(-(int)a1)) {
        *(unsigned char *)((char *)(ts4l_word)(a0) + 0) = (unsigned char)((a1 << 1) + ((signed char)t1));
    } else {
        if ((int)((signed char)t1) >= (int)a1) {
            *(unsigned char *)((char *)(ts4l_word)(a0) + 0) = (unsigned char)(((signed char)t1) - (a1 << 1));
        }
    }
    t7 = *(unsigned char *)((char *)(ts4l_word)(a0) + 1);
    if ((int)((signed char)t7) < (int)(-(int)a1)) {
        *(unsigned char *)((char *)(ts4l_word)(a0) + 1) = (unsigned char)((a1 << 1) + ((signed char)t7));
        return;
    }
    if ((int)((signed char)t7) < (int)a1) {
        return;
    }
    *(unsigned char *)((char *)(ts4l_word)(a0) + 1) = (unsigned char)(((signed char)t7) - (a1 << 1));
    return;
}

/* Loader_DLL.xex 0x8329F7F8: if_call_seq fn_834138F0, u32@0x0, fn_834138F0, u32@0x18, fn_834138F0, u32@0x8 */
ts4l_word ts4l_if_call_seq_fn_834138F0_8329F7F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p2;
    ts4l_word p5;
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4l_word)a0;
    if ((ts4l_word)a0 == 0) {
        t1 = fn_834138F0();
        p2 = (ts4l_word)t1;
    }
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p5 = (ts4l_word)p2;
    if ((ts4l_word)t3 == 0) {
        t4 = fn_834138F0((ts4l_word)p2);
        p5 = (ts4l_word)t4;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 24);
    if ((ts4l_word)t6 == 0) {
        fn_834138F0((ts4l_word)p5);
    }
    return (*(ts4l_word *)((char *)(ts4l_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8329FA20: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_8329FA20(ts4l_word a0)
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

/* Loader_DLL.xex 0x8329FCD0: if_get u32@0x46dc, u32@0x47ec, u32@0x47ec, u32@0x46dc, u32@0x26c, u32@0x268 */
ts4l_word ts4l_if_get_u32_off46dc_8329FCD0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 18140);
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 18412);
    t3 = *(ts4l_word *)((char *)(ts4l_word)(((t1 + 4470) << 2)) + a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 18412) = (ts4l_word)(t2 + 1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 18140) = (ts4l_word)(t1 + -1);
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 620) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 616) = (ts4l_word)a1;
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 17880);
    if ((ts4l_word)t4 >= 64) {
        return t3;
    }
    *(ts4l_word *)((char *)(ts4l_word)(((t4 + 4406) << 2)) + a0) = (ts4l_word)t3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 17880) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 17880)) + 1);
    return t3;
}

/* Loader_DLL.xex 0x832A0D48: call_seq u32@0x4988, RtlEnterCriticalSection, u32@0x497c, u32@0xc, u16@0x4974, u16@0x4 */
ts4l_word ts4l_call_seq_u32_off4988_832A0D48(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t8;

    RtlEnterCriticalSection((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18824)));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 12) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18812));
    *(unsigned short *)((char *)(ts4l_word)(a1) + 4) = (unsigned short)(*(unsigned short *)((char *)(ts4l_word)(a0) + 18804));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18800));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 8) = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18808));
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 16) = (ts4l_word)-1;
    t8 = RtlLeaveCriticalSection((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18824)));
    return t8;
}

/* Loader_DLL.xex 0x832A4288: call_seq fn_833E3AD0, fn_833E3AD0, fn_833E3AD0 */
ts4l_word ts4l_call_seq_fn_833E3AD0_832A4288(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t3;

    fn_833E3AD0((ts4l_word)a0, (ts4l_word)a3, (ts4l_word)a6);
    fn_833E3AD0((ts4l_word)a1, (ts4l_word)a4, (ts4l_word)a7);
    t3 = fn_833E3AD0((ts4l_word)a2, (ts4l_word)a5, (ts4l_word)a7);
    return t3;
}

/* Loader_DLL.xex 0x832A5BF8: if_call_seq u32@0x49ac, fn_8329F758, u32@0x40, fn_833E3AD0 */
ts4l_word ts4l_if_call_seq_u32_off49ac_832A5BF8(ts4l_word a0, ts4l_word a1, int a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word loc50[4];
    ts4l_word t3;
    ts4l_word t5;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p6 = (ts4l_word)a0;
    if ((ts4l_word)a1 != 0 && (int)a2 == 0) {
        fn_8329F758((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 18860)), (ts4l_word)(ts4l_word)&loc50[0]);
        t3 = loc50[0];
        t5 = fn_833E3AD0((ts4l_word)a1, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t3) + 64)), (ts4l_word)512);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x832A6DF0: set  */
void ts4l_set_832A6DF0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45192)) = (ts4l_word)a1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45196)) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45200)) = (ts4l_word)a3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45180)) = (ts4l_word)a4;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45184)) = (ts4l_word)a5;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + ((0) | 45188)) = (ts4l_word)a6;
    return;
}

/* Loader_DLL.xex 0x832A8538: if_call_seq fn_833E3A30, u32@0xf8, u32@0xfc, u32@0x100 */
ts4l_word ts4l_if_call_seq_fn_833E3A30_832A8538(ts4l_word a0, int a1, ts4l_word a2)
{
    if ((int)a1 == 36 && (ts4l_word)a2 == 272) {
        fn_833E3A30((ts4l_word)a0, (ts4l_word)0, (ts4l_word)a2);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 248) = (ts4l_word)0;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 252) = (ts4l_word)256;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 256) = (ts4l_word)15;
        return 0;
    }
    return -10;
}

/* Loader_DLL.xex 0x832A8730: if_set u32@0x274, u32@0x26c, u32@0x278, u32@0x27c, u32@0x46dc, u32@0x46dc */
ts4l_word ts4l_if_set_u32_off274_832A8730(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;

    if ((ts4l_word)a1 == 0) {
        return a0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 628) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 620) = (ts4l_word)((2863267840) | 43690);
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 632) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a1) + 636) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)((((*(ts4l_word *)((char *)(ts4l_word)(a0) + 18140)) + 4471) << 2)) + a0) = (ts4l_word)a1;
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 18140);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 18412) = (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 18412)) + -1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 18140) = (ts4l_word)(t2 + 1);
    return fn_8329FF70((ts4l_word)a0);
}

/* Loader_DLL.xex 0x832A93B0: if_call_seq fn_832A8DE8, fn_83495D48 */
ts4l_word ts4l_if_call_seq_fn_832A8DE8_832A93B0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;

    if ((int)(a0 + 15984) != 0) {
        fn_832A8DE8((ts4l_word)a0, (ts4l_word)3);
        t2 = fn_83495D48((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1);
        return t2;
    }
    return -9;
}

/* Loader_DLL.xex 0x832A96E8: if_call_seq fn_832A8DE8, fn_834F98B8 */
ts4l_word ts4l_if_call_seq_fn_832A8DE8_832A96E8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;

    if ((int)(a0 + 15984) != 0) {
        fn_832A8DE8((ts4l_word)a0, (ts4l_word)3);
        t2 = fn_834F98B8((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1);
        return t2;
    }
    return -9;
}

/* Loader_DLL.xex 0x832AA038: if_call_seq fn_832A8DE8, fn_832A10F0, fn_8350E030 */
ts4l_word ts4l_if_call_seq_fn_832A8DE8_832AA038(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t3;

    if ((int)(a0 + 15984) != 0) {
        fn_832A8DE8((ts4l_word)a0, (ts4l_word)1);
        fn_832A10F0((ts4l_word)a0);
        t3 = fn_8350E030((ts4l_word)a0, (ts4l_word)(a0 + 15984), (ts4l_word)a1);
        return t3;
    }
    return -9;
}

/* Loader_DLL.xex 0x832AA088: if_call_seq fn_832A8DE8, fn_832A10F0, fn_8350E030 */
ts4l_word ts4l_if_call_seq_fn_832A8DE8_832AA088(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t3;

    if ((int)(a0 + 18192) != 0) {
        fn_832A8DE8((ts4l_word)a0, (ts4l_word)1);
        fn_832A10F0((ts4l_word)a0);
        t3 = fn_8350E030((ts4l_word)a0, (ts4l_word)(a0 + 18192), (ts4l_word)a1);
        return t3;
    }
    return -9;
}

/* Loader_DLL.xex 0x832BF620: if_call_seq fn_83286398, fn_833E3A30 */
ts4l_word ts4l_if_call_seq_fn_83286398_832BF620(void)
{
    ts4l_word p3;
    ts4l_word t1;

    t1 = fn_83286398((ts4l_word)72, (ts4l_word)0);
    p3 = (ts4l_word)t1;
    if ((ts4l_word)t1 != 0) {
        fn_833E3A30((ts4l_word)t1, (ts4l_word)0, (ts4l_word)72);
        p3 = (ts4l_word)t1;
    }
    return p3;
}

/* Loader_DLL.xex 0x832DBA48: call_seq u32@0x0, u32@0x130, u32@0x134, u32@0x4, u32@0x8, u32@0xc */
ts4l_word ts4l_call_seq_u32_off0_832DBA48(ts4l_word a0)
{
    ts4l_word t2;

    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 304) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 308) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 12) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 16) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 20) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 24) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 28) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 36) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 40) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 300) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 292) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 296) = (ts4l_word)0;
    fn_8335D0D0((ts4l_word)(a0 + 52));
    t2 = fn_8335C1C8((ts4l_word)(a0 + 156));
    return t2;
}

/* Loader_DLL.xex 0x832DBAD0: if_call_seq fn_8335D0F0, fn_8335C1E8, u32@0x130, fn_832863B0, u32@0x130, u32@0x134 */
ts4l_word ts4l_if_call_seq_fn_8335D0F0_832DBAD0(ts4l_word a0)
{
    ts4l_word p11;
    ts4l_word t3;
    ts4l_word t6;
    ts4l_word t9;
    ts4l_word t10;

    fn_8335D0F0((ts4l_word)(a0 + 52));
    fn_8335C1E8((ts4l_word)(a0 + 156));
    t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 304);
    if ((ts4l_word)t3 != 0) {
        fn_832863B0((ts4l_word)t3);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 304) = (ts4l_word)0;
    }
    t6 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 308);
    if ((ts4l_word)t6 != 0) {
        fn_832863B0((ts4l_word)t6);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 308) = (ts4l_word)0;
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    p11 = (ts4l_word)t9;
    if ((ts4l_word)t9 != 0) {
        t10 = fn_832863B0((ts4l_word)t9);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
        p11 = (ts4l_word)t10;
    }
    return p11;
}

/* Loader_DLL.xex 0x832DC278: if_get u32@0x4, u32@0x4, u32@0x8, u32@0xc, u32@0x10, fn_832DBB50 */
ts4l_word ts4l_if_get_u32_off4_832DC278(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    int t2;

    if (((ts4l_word)a3 != 0 && (ts4l_word)a6 != 0) && (ts4l_word)a0 != 0) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
        if ((((int)t2 >= 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 8)) >= 0) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 12)) >= 1) && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 16)) >= 1) {
            return fn_832DBED8((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a3, (ts4l_word)a4, (ts4l_word)a5, (ts4l_word)a6);
        }
        return fn_832DBB50((ts4l_word)a0);
    }
    return 1;
}

/* Loader_DLL.xex 0x832DDEE8: if_call_seq u32@0x130, fn_832863B0, u32@0x130, u32@0x134, fn_832863B0, u32@0x134 */
ts4l_word ts4l_if_call_seq_u32_off130_832DDEE8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t7;
    ts4l_word t9;
    ts4l_word t10;
    ts4l_word t12;
    ts4l_word t13;
    ts4l_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 304);
    if ((ts4l_word)t1 != 0) {
        fn_832863B0((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 304) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 308);
    if ((ts4l_word)t4 != 0) {
        fn_832863B0((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 308) = (ts4l_word)0;
    }
    t7 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
    t9 = fn_832DC970((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 36)), (ts4l_word)t7);
    t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    t12 = fn_832DC970((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 44)), (ts4l_word)t10);
    t13 = fn_83286398((ts4l_word)t9, (ts4l_word)0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 304) = (ts4l_word)t13;
    if ((ts4l_word)t13 == 0) {
        return t13;
    }
    t14 = fn_83286398((ts4l_word)t12, (ts4l_word)0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 308) = (ts4l_word)t14;
    return (t14 != 0);
}

/* Loader_DLL.xex 0x832DE938: if_fn  */
ts4l_word ts4l_if_fn_832DE938(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    ts4l_word p1;
    ts4l_word p2;
    ts4l_word p3;
    ts4l_word p4;
    ts4l_word p5;
    ts4l_word p6;

    p1 = (ts4l_word)a0;
    if ((int)a0 < (int)a1) {
        p1 = (ts4l_word)a1;
    }
    p2 = (ts4l_word)p1;
    if ((int)p1 < (int)a2) {
        p2 = (ts4l_word)a2;
    }
    p3 = (ts4l_word)p2;
    if ((int)p2 < (int)a3) {
        p3 = (ts4l_word)a3;
    }
    p4 = (ts4l_word)p3;
    if ((int)p3 < (int)a4) {
        p4 = (ts4l_word)a4;
    }
    p5 = (ts4l_word)p4;
    if ((int)p4 < (int)a5) {
        p5 = (ts4l_word)a5;
    }
    p6 = (ts4l_word)p5;
    if ((int)p5 < (int)a6) {
        p6 = (ts4l_word)a6;
    }
    if ((int)p6 < (int)a7) {
        return a7;
    }
    return p6;
}

/* Loader_DLL.xex 0x832E2918: if_call_seq fn_83366F98, fn_83366F98, fn_833674A0, fn_833674A0 */
ts4l_word ts4l_if_call_seq_fn_83366F98_832E2918(ts4l_word a0, ts4l_word a1, int a2, int a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p6;
    ts4l_word t4;
    ts4l_word t5;

    (void)a6;
    (void)a7;
    if ((int)a3 != 0) {
        fn_83366F98((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a5, (ts4l_word)1, (ts4l_word)16, (ts4l_word)a4);
    }
    fn_83366F98((ts4l_word)a0, (ts4l_word)((a5 << 3) + a1), (ts4l_word)a5, (ts4l_word)1, (ts4l_word)16, (ts4l_word)a4);
    t4 = fn_833674A0((ts4l_word)a0, (ts4l_word)(a1 + 8), (ts4l_word)1, (ts4l_word)a5, (ts4l_word)16, (ts4l_word)a4);
    p6 = (ts4l_word)t4;
    if ((int)a2 != 0) {
        t5 = fn_833674A0((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)1, (ts4l_word)a5, (ts4l_word)16, (ts4l_word)a4);
        p6 = (ts4l_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x832E29C0: if_call_seq fn_83366F98, fn_833674A0 */
ts4l_word ts4l_if_call_seq_fn_83366F98_832E29C0(ts4l_word a0, ts4l_word a1, int a2, int a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p2;
    ts4l_word p4;
    ts4l_word t1;
    ts4l_word t3;

    (void)a6;
    (void)a7;
    p2 = (ts4l_word)a0;
    if ((int)a3 != 0) {
        t1 = fn_83366F98((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)a5, (ts4l_word)1, (ts4l_word)8, (ts4l_word)a4);
        p2 = (ts4l_word)t1;
    }
    p4 = (ts4l_word)p2;
    if ((int)a2 != 0) {
        t3 = fn_833674A0((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)1, (ts4l_word)a5, (ts4l_word)8, (ts4l_word)a4);
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x832E6D08: call_seq fn_8332FE90, fn_8332FE90, fn_8332FF58, fn_8332FF58 */
ts4l_word ts4l_call_seq_fn_8332FE90_832E6D08(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word t4;

    fn_8332FE90((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)(a4 << 1));
    fn_8332FE90((ts4l_word)(a0 + 256), (ts4l_word)(a1 + a4), (ts4l_word)8, (ts4l_word)(a4 << 1));
    fn_8332FF58((ts4l_word)(a0 + 512), (ts4l_word)a2, (ts4l_word)8, (ts4l_word)a5);
    t4 = fn_8332FF58((ts4l_word)(a0 + 640), (ts4l_word)a3, (ts4l_word)8, (ts4l_word)a5);
    return t4;
}

/* Loader_DLL.xex 0x832E6D80: call_seq fn_8332FE90, fn_8332FE90, fn_8332FF58, fn_8332FF58 */
ts4l_word ts4l_call_seq_fn_8332FE90_832E6D80(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word t4;

    fn_8332FE90((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)8, (ts4l_word)a4);
    fn_8332FE90((ts4l_word)(a0 + 256), (ts4l_word)((a4 << 3) + a1), (ts4l_word)8, (ts4l_word)a4);
    fn_8332FF58((ts4l_word)(a0 + 512), (ts4l_word)a2, (ts4l_word)8, (ts4l_word)a5);
    t4 = fn_8332FF58((ts4l_word)(a0 + 640), (ts4l_word)a3, (ts4l_word)8, (ts4l_word)a5);
    return t4;
}

/* Loader_DLL.xex 0x832EAB20: get u32@0x3e20, vcall, u32@0x3e20, vcall, u32@0x3e20, vcall */
ts4l_word ts4l_get_u32_off3e20_832EAB20(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t12;

    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)a1, (ts4l_word)a2, (ts4l_word)a5);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 128), (ts4l_word)(a2 + 8), (ts4l_word)a5);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 256), (ts4l_word)((a5 << 3) + a2), (ts4l_word)a5);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 384), (ts4l_word)(((a5 << 3) + a2) + 8), (ts4l_word)a5);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 512), (ts4l_word)a3, (ts4l_word)a6);
    t12 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 640), (ts4l_word)a4, (ts4l_word)a6);
    return t12;
}

/* Loader_DLL.xex 0x832EABE8: get u32@0x3e20, vcall, u32@0x3e20, vcall, u32@0x3e20, vcall */
ts4l_word ts4l_get_u32_off3e20_832EABE8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6)
{
    ts4l_word t12;

    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)a1, (ts4l_word)a2, (ts4l_word)(a5 << 1));
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 128), (ts4l_word)(a2 + 8), (ts4l_word)(a5 << 1));
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 256), (ts4l_word)(a2 + a5), (ts4l_word)(a5 << 1));
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 384), (ts4l_word)((a2 + a5) + 8), (ts4l_word)(a5 << 1));
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 512), (ts4l_word)a3, (ts4l_word)a6);
    t12 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)(a0) + 15904))))((ts4l_word)(a1 + 640), (ts4l_word)a4, (ts4l_word)a6);
    return t12;
}

/* Loader_DLL.xex 0x83304470: if_set u32@0x9b0, u32@0x9d8, u32@0xa00, u32@0x9b0, u32@0x9d8, u32@0xa00 */
void ts4l_if_set_u32_off9b0_83304470(ts4l_word a0, int a1)
{
    if ((int)a1 < 5) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2480) = (ts4l_word)(a0 + 2468);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2520) = (ts4l_word)(a0 + 2484);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2560) = (ts4l_word)(a0 + 2524);
        return;
    }
    if ((int)a1 < 13) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2480) = (ts4l_word)(a0 + 2456);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2520) = (ts4l_word)(a0 + 2496);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 2560) = (ts4l_word)(a0 + 2536);
        return;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 2480) = (ts4l_word)(a0 + 2444);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 2520) = (ts4l_word)(a0 + 2508);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 2560) = (ts4l_word)(a0 + 2548);
    return;
}

/* Loader_DLL.xex 0x83304DA0: if_get u32@0xcc, u32@0x1cc, fn_8333B9D8, u32@0xc70, u32@0x108, u32@0xcc */
ts4l_word ts4l_if_get_u32_offcc_83304DA0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p8;
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t7;

    (void)a4;
    (void)a5;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 204);
    t3 = fn_8333B9D8((ts4l_word)a0, (ts4l_word)a3, (ts4l_word)t1, (ts4l_word)a1, (ts4l_word)t1, (ts4l_word)(a6 & 0x3), (ts4l_word)(a7 & 0x3), (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 460)));
    p8 = (ts4l_word)t3;
    if ((ts4l_word)a2 != 0) {
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3184);
        t5 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 264);
        t7 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))(t4))((ts4l_word)a1, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 204)), (ts4l_word)t5);
        p8 = (ts4l_word)t7;
    }
    return p8;
}

/* Loader_DLL.xex 0x83304E10: if_get u32@0xd0, fn_8333B9D8, u32@0xc70, u32@0x108, u32@0xd0, vcall */
ts4l_word ts4l_if_get_u32_offd0_83304E10(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    ts4l_word p7;
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t6;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 208);
    t2 = fn_8333B9D8((ts4l_word)a0, (ts4l_word)a3, (ts4l_word)t1, (ts4l_word)a1, (ts4l_word)t1, (ts4l_word)(a4 & 0x3), (ts4l_word)(a5 & 0x3), (ts4l_word)0);
    p7 = (ts4l_word)t2;
    if ((ts4l_word)a2 != 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 3184);
        t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 264);
        t6 = ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))(t3))((ts4l_word)a1, (ts4l_word)a1, (ts4l_word)a2, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 208)), (ts4l_word)t4);
        p7 = (ts4l_word)t6;
    }
    return p7;
}

/* Loader_DLL.xex 0x83305F78: if_get u32@0x55d0, u32@0x88, u32@0x6f8, u32@0x88, u32@0x6f8, u16@-0x2 */
ts4l_word ts4l_if_get_u32_off55d0_83305F78(ts4l_word a0, int a1, int a2)
{
    ts4l_word p6;
    ts4l_word t10;
    unsigned short t12;

    p6 = (ts4l_word)0;
    if (((int)a2 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 21968))) + (a2 << 2))) == 0) && (ts4l_word)(*(unsigned short *)((char *)(ts4l_word)(((((int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 136)) * (int)(a2 + -1)) + a1) << 1)) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 1784)))) == 16384) {
        p6 = (ts4l_word)1;
    }
    if ((int)a1 == 0) {
        return p6;
    }
    t10 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 136);
    t12 = *(unsigned short *)((char *)(ts4l_word)((((((int)t10 * (int)a2) + a1) << 1) + (*(ts4l_word *)((char *)(ts4l_word)(a0) + 1784)))) + -2);
    if ((ts4l_word)t12 != 16384) {
        return p6;
    }
    return 1;
}

/* Loader_DLL.xex 0x833185B0: call_seq fn_833E3AD0, fn_833E3AD0, fn_833E3AD0 */
ts4l_word ts4l_call_seq_fn_833E3AD0_833185B0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t3;

    fn_833E3AD0((ts4l_word)a0, (ts4l_word)a3, (ts4l_word)a6);
    fn_833E3AD0((ts4l_word)a1, (ts4l_word)a4, (ts4l_word)a7);
    t3 = fn_833E3AD0((ts4l_word)a2, (ts4l_word)a5, (ts4l_word)a7);
    return t3;
}

/* Loader_DLL.xex 0x83318B30: loop_get u32@lbl_8353B588, u8@0x80, u8@0x0 */
void ts4l_loop_get_u32_lbl_8353B588_83318B30(ts4l_word a0, ts4l_word a1, ts4l_word a2, int a3)
{
    ts4l_word c1;
    ts4l_word lv3;
    ts4l_word p6;
    ts4l_word t2;

    if ((int)a3 <= 0) {
        return;
    }
    c1 = (ts4l_word)a3;
    t2 = *(volatile ts4l_word *)lbl_8353B588;
    lv3 = (ts4l_word)a0;
    do {
        *(volatile unsigned char *)((char *)(ts4l_word)(lv3) + 0) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4l_word)((((int)(((int)((*(volatile unsigned char *)((char *)(ts4l_word)((a1 - a0)) + lv3)) + -128) * (int)a2) + 4) >> 3) + t2)) + 128));
        p6 = (ts4l_word)(lv3 + 1);
        lv3 = p6;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x83319F98: if_get u32@0x4fb0, fn_833186A0, fn_83318818, u32@0x3e30, u32@0x3e2c, u32@lbl_8354A49C */
void ts4l_if_get_u32_off4fb0_83319F98(ts4l_word a0, int a1)
{
    ts4l_word t1;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 20400);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 15920) = (ts4l_word)(ts4l_word)fn_833186A0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 15916) = (ts4l_word)(ts4l_word)fn_83318818;
    *(ts4l_word *)lbl_8354A49C = (ts4l_word)t1;
    *(ts4l_word *)lbl_8354A498 = (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 20404));
    if ((int)a1 == 0) {
        return;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 15920) = (ts4l_word)(ts4l_word)fn_83316A28;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 15916) = (ts4l_word)(ts4l_word)fn_83316BE8;
    return;
}

/* Loader_DLL.xex 0x83319FF8: if_call_seq u32@0x0, fn_832863B0, u32@0x0, u32@0x4, fn_832863B0, u32@0x4 */
ts4l_word ts4l_if_call_seq_u32_off0_83319FF8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((ts4l_word)t1 != 0) {
        fn_832863B0((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 4);
    if ((ts4l_word)t4 != 0) {
        fn_832863B0((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 4) = (ts4l_word)0;
    }
    fn_832863B0((ts4l_word)a0);
    return 0;
}
