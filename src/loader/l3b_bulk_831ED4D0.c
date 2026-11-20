/* Loader_DLL.xex 0x831ED4D0-0x83223978, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

extern char lbl_830009E0[];
extern char lbl_830009F8[];
extern char lbl_83002678[];
extern char lbl_8302AA08[];
extern char lbl_8302AA48[];
extern char lbl_8302AFB8[];
ts4l_word fn_830AAAC0();
ts4l_word fn_830FFB68();
ts4l_word fn_83109390();
ts4l_word fn_8316F2A0();
ts4l_word fn_831BB278();
ts4l_word fn_831C0030();
ts4l_word fn_831E8D30();
ts4l_word fn_831F2E18();
ts4l_word fn_83211778();
ts4l_word fn_8321B9C8();
ts4l_word fn_8321BA50();
ts4l_word fn_8321F468();
ts4l_word fn_8321F7A0();
ts4l_word fn_8321F9F8();
ts4l_word fn_8321FD40();
ts4l_word fn_83220068();
ts4l_word fn_83221098();
ts4l_word fn_83221648();
ts4l_word fn_83227008();
ts4l_word fn_832272F0();
ts4l_word fn_83227300();
ts4l_word fn_83227348();
ts4l_word fn_83227440();
ts4l_word fn_8322C010();
ts4l_word fn_8322C398();
ts4l_word fn_8340CE90();
ts4l_word fn_8340D830();
ts4l_word fn_83413818();

/* Loader_DLL.xex 0x831ED4D0: call_seq u32@0x0, u32@0x68, fn_831C0030, u32@0x68, fn_831C0030, u32@0x68 */
ts4l_word ts4l_call_seq_u32_off0_831ED4D0(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t11;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    fn_831C0030((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 104)), (ts4l_word)1, (ts4l_word)((a0 + 65536) + 2340));
    fn_831C0030((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 104)), (ts4l_word)2, (ts4l_word)((a0 + 65536) + 2342));
    fn_831C0030((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 104)), (ts4l_word)4, (ts4l_word)((a0 + 65536) + 2344));
    fn_831C0030((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 104)), (ts4l_word)16, (ts4l_word)((a0 + 65536) + 2346));
    t11 = fn_831C0030((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(t1) + 104)), (ts4l_word)32, (ts4l_word)((a0 + 65536) + 2348));
    return t11;
}

/* Loader_DLL.xex 0x831F2FE8: if_call_seq u32@0x2c, fn_831F2E18, u32@0x2c, u32@0x38, fn_831F2E18, u32@0x38 */
ts4l_word ts4l_if_call_seq_u32_off2c_831F2FE8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t4;
    ts4l_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        fn_831F2E18((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    if ((ts4l_word)t4 != 0) {
        fn_831F2E18((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    }
    t7 = fn_8316F2A0((ts4l_word)a0);
    return t7;
}

/* Loader_DLL.xex 0x831F3BA0: get u32@0x8, u32@0x7c, u32@0x78, u32@0x60, u32@0x0, u32@0x0 */
ts4l_word ts4l_get_u32_off8_831F3BA0(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t2;
    ts4l_word t3;
    ts4l_word t4;
    ts4l_word t5;
    ts4l_word t6;
    ts4l_word t7;

    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 8);
    t2 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 124);
    t3 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 120);
    t4 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 96);
    t5 = *(volatile ts4l_word *)((char *)(ts4l_word)(t1) + 0);
    t6 = *(volatile ts4l_word *)((char *)(ts4l_word)(t2) + 0);
    t7 = *(volatile ts4l_word *)((char *)(ts4l_word)(t3) + 0);
    ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word, ts4l_word))((*(volatile ts4l_word *)((char *)(ts4l_word)(t5) + 40))))((ts4l_word)t1, (ts4l_word)1, (ts4l_word)t7, (ts4l_word)1, (ts4l_word)t6, (ts4l_word)t4, (ts4l_word)t3, (ts4l_word)t2);
    return 0;
}

/* Loader_DLL.xex 0x831F63C0: if_fn  */
ts4l_word ts4l_if_fn_831F63C0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5)
{
    if ((int)(((int)(((int)a0 * (int)a1) + ((int)a2 * (int)a3)) >> 8) + ((int)((int)((signed char)(a4 << 4)) >> 4) * (int)a5)) > 32767) {
        return 32767;
    }
    if ((int)(((int)(((int)a0 * (int)a1) + ((int)a2 * (int)a3)) >> 8) + ((int)((int)((signed char)(a4 << 4)) >> 4) * (int)a5)) >= -32768) {
        return (((int)(((int)a0 * (int)a1) + ((int)a2 * (int)a3)) >> 8) + ((int)((int)((signed char)(a4 << 4)) >> 4) * (int)a5));
    }
    return -32768;
}

/* Loader_DLL.xex 0x831FF338: if_call_seq u32@0x8, fn_831BB278, u32@0x8, u32@0xc, fn_831BB278, u32@0xc */
ts4l_word ts4l_if_call_seq_u32_off8_831FF338(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
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
        fn_831BB278((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 8) = (ts4l_word)0;
    }
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 12);
    p6 = (ts4l_word)t4;
    if ((ts4l_word)t4 != 0) {
        t5 = fn_831BB278((ts4l_word)t4);
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

/* Loader_DLL.xex 0x83201D50: if_call_seq u32@0x0, u32@0x0, fn_8340D830 */
ts4l_word ts4l_if_call_seq_u32_off0_83201D50(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    int t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 0);
    if ((int)t2 != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((613154816) | 32768));
    }
    return 0;
}

/* Loader_DLL.xex 0x83202348: if_call_seq u32@0x4, fn_831E8D30, u32@0x4, u32@0xe0 */
ts4l_word ts4l_if_call_seq_u32_off4_83202348(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3)
{
    int t2;

    t2 = fn_831E8D30((ts4l_word)a0, (ts4l_word)a1, (ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)) + ((int)a1 * 464)), (ts4l_word)a2, (ts4l_word)a3);
    if ((int)t2 < 0) {
        *(ts4l_word *)((char *)(ts4l_word)(((*(ts4l_word *)((char *)(ts4l_word)(a0) + 4)) + ((int)a1 * 464))) + 224) = (ts4l_word)t2;
    }
    return t2;
}

/* Loader_DLL.xex 0x832050D8: get u32@0x34, u32@0x30, u32@0x0, u32@0x34, u32@0x4, u32@0x0 */
ts4l_word ts4l_get_u32_off34_832050D8(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t3;
    float t4;

    t1 = *(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(t1) + 0) = (ts4l_word)1;
    t3 = *(volatile ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 4);
    t4 = *(float *)lbl_830009E0;
    *(ts4l_word *)((char *)(ts4l_word)(t3) + 0) = (ts4l_word)1;
    *(float *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 148))) + 0) = t4;
    *(float *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 144))) + 0) = t4;
    *(ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 8) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 12) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)((*(volatile ts4l_word *)((char *)(ts4l_word)(a0) + 52))) + 16) = (ts4l_word)2;
    return 0;
}

/* Loader_DLL.xex 0x8321A130: if_get u32@0x8, u32@0x28, u32@0x28, u32@0x0 */
ts4l_word ts4l_if_get_u32_off8_8321A130(ts4l_word a0, ts4l_word a1)
{
    int t3;

    if (((ts4l_word)a0 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 8)) == (int)((1281753088) | 20588)) && (ts4l_word)a1 != 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 40);
        if ((int)t3 == -1) {
            return ((2147483648) | 16389);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)t3;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8321A3A0: if_call_seq u32@0x8, fn_83211778, u32@0x0, u32@0x0 */
ts4l_word ts4l_if_call_seq_u32_off8_8321A3A0(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;

    if (((ts4l_word)a0 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 8)) == (int)((1281753088) | 20588)) && (ts4l_word)a1 != 0) {
        t2 = fn_83211778((ts4l_word)a0);
        if ((ts4l_word)t2 == 0) {
            *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)0;
            return ((2147942400) | 8);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)t2;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8321A760: if_get u32@0x8, u32@0x2c, u32@0x2c, u32@0x0 */
ts4l_word ts4l_if_get_u32_off8_8321A760(ts4l_word a0, ts4l_word a1)
{
    int t3;

    if (((ts4l_word)a0 != 0 && (int)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 8)) == (int)((1281753088) | 20588)) && (ts4l_word)a1 != 0) {
        t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
        if ((int)t3 == -1) {
            return ((2147483648) | 16389);
        }
        *(ts4l_word *)((char *)(ts4l_word)(a1) + 0) = (ts4l_word)t3;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8321B8C8: if_call_seq fn_83413818 */
ts4l_word ts4l_if_call_seq_fn_83413818_8321B8C8(ts4l_word a0, ts4l_word a1)
{
    ts4l_word p2;
    int t1;

    (void)a0;
    if ((ts4l_word)a1 == 0) {
        return 258;
    }
    t1 = fn_83413818();
    p2 = (ts4l_word)t1;
    if ((int)t1 > 0) {
        p2 = (ts4l_word)((t1 & 0xffff) | 2147942400);
    }
    return p2;
}

/* Loader_DLL.xex 0x8321C5F8: if_call_seq fn_8321BA50, fn_830FFB68, fn_83109390 */
ts4l_word ts4l_if_call_seq_fn_8321BA50_8321C5F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word loc50[4];
    ts4l_word loc60[8];
    ts4l_word t2;
    ts4l_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4l_word)((2147942400) | 87);
    if ((ts4l_word)a0 != 0) {
        fn_8321BA50((ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)(ts4l_word)&loc50[0], (ts4l_word)a1);
        t2 = fn_830FFB68((ts4l_word)a0);
        t3 = fn_83109390((ts4l_word)t2, (ts4l_word)(ts4l_word)&loc60[0]);
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8321C6C0: if_call_seq fn_8321B9C8, fn_830FFB68, fn_83109390 */
ts4l_word ts4l_if_call_seq_fn_8321B9C8_8321C6C0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word p4;
    ts4l_word loc50[4];
    ts4l_word loc60[8];
    ts4l_word t2;
    ts4l_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4l_word)((2147942400) | 87);
    if ((ts4l_word)a0 != 0) {
        fn_8321B9C8((ts4l_word)(ts4l_word)&loc60[0], (ts4l_word)(ts4l_word)&loc50[0]);
        t2 = fn_830FFB68((ts4l_word)a0);
        t3 = fn_83109390((ts4l_word)t2, (ts4l_word)(ts4l_word)&loc60[0]);
        p4 = (ts4l_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8321EBD8: if_get u32@0x0, u32@0x2c, vcall, u32@0x74 */
ts4l_word ts4l_if_get_u32_off0_8321EBD8(ts4l_word a0)
{
    int t3;

    t3 = ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 44))))((ts4l_word)a0);
    if ((int)t3 >= 0) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 116) = (ts4l_word)1;
    }
    return t3;
}

/* Loader_DLL.xex 0x8321EC38: if_set u32@0x110, u32@0x11c, u32@0x108, u32@0x114, u32@0x10c, u32@0x118 */
ts4l_word ts4l_if_set_u32_off110_8321EC38(ts4l_word a0, int a1, ts4l_word a2, ts4l_word a3)
{
    if ((int)a1 != 1) {
        if ((int)a1 != 3 && (int)a1 == 4) {
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 268) = (ts4l_word)a2;
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 280) = (ts4l_word)a3;
            return 0;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 264) = (ts4l_word)a2;
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 276) = (ts4l_word)a3;
        return 0;
    }
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 272) = (ts4l_word)a2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 284) = (ts4l_word)a3;
    return 0;
}

/* Loader_DLL.xex 0x8321EC88: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x3c, vcall */
ts4l_word ts4l_get_u32_off0_8321EC88(ts4l_word a0, ts4l_word a1)
{
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 60))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8321ECF0: if_get u32@0x2c, u32@0x0, u32@0x8, vcall, u32@0x2c */
ts4l_word ts4l_if_get_u32_off2c_8321ECF0(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x8321FA30: call_seq fn_830AAAC0, u32@0x38, fn_8321F7A0 */
ts4l_word ts4l_call_seq_fn_830AAAC0_8321FA30(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t2;

    fn_830AAAC0((ts4l_word)a1);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)a1;
    t2 = fn_8321F7A0((ts4l_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x83220078: call_seq fn_83227300, u32@0x38, u32@0x3c, u32@0x40, u32@0x44 */
ts4l_word ts4l_call_seq_fn_83227300_83220078(ts4l_word a0)
{
    ts4l_word t1;
    float t2;

    t1 = fn_83227300((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    t2 = *(float *)lbl_83002678;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(float *)((char *)(ts4l_word)(a0) + 72) = t2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x83220118: call_seq fn_83227348, lbl_8302AA08, u32@0x0, fn_83227300, u32@0x38, u32@0x3c */
ts4l_word ts4l_call_seq_fn_83227348_83220118(ts4l_word a0)
{
    float t3;

    fn_83227348((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AA08;
    fn_83227300((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    t3 = *(float *)lbl_83002678;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(float *)((char *)(ts4l_word)(a0) + 72) = t3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83220180: if_call_seq lbl_8302AA08, u32@0x0, fn_832272F0, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302AA08_83220180(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AA08;
    fn_832272F0((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32773));
    }
    return a0;
}

/* Loader_DLL.xex 0x83220238: call_seq fn_83227300, u32@0x38, u32@0x3c, u32@0x40, u32@0x44, u32@0x48 */
ts4l_word ts4l_call_seq_fn_83227300_83220238(ts4l_word a0)
{
    ts4l_word t1;
    float t2;

    t1 = fn_83227300((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    t2 = *(float *)lbl_830009F8;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(float *)((char *)(ts4l_word)(a0) + 80) = t2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x83220300: call_seq fn_83227348, lbl_8302AA48, u32@0x0, fn_83227300, u32@0x38, u32@0x3c */
ts4l_word ts4l_call_seq_fn_83227348_83220300(ts4l_word a0)
{
    float t3;

    fn_83227348((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AA48;
    fn_83227300((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 60) = (ts4l_word)0;
    t3 = *(float *)lbl_830009F8;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 64) = (ts4l_word)0;
    *(float *)((char *)(ts4l_word)(a0) + 80) = t3;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 68) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 72) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 76) = (ts4l_word)0;
    return a0;
}

/* Loader_DLL.xex 0x83220370: if_call_seq lbl_8302AA48, u32@0x0, fn_832272F0, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302AA48_83220370(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AA48;
    fn_832272F0((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32772));
    }
    return a0;
}

/* Loader_DLL.xex 0x83220488: if_get u32@0x0, u32@0x54, vcall, u32@0x38, u32@0x0, u32@0x48 */
ts4l_word ts4l_if_get_u32_off0_83220488(ts4l_word a0)
{
    ts4l_word t4;
    int t9;
    ts4l_word t11;

    ((ts4l_word (*)(ts4l_word, ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 84))))((ts4l_word)a0, (ts4l_word)2);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 56);
    if ((ts4l_word)t4 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t4) + 0))) + 72))))((ts4l_word)t4);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 56) = (ts4l_word)0;
    }
    t9 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 652);
    if ((int)t9 != 0) {
        t11 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 656);
        if ((ts4l_word)t11 != 0) {
            ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t11) + 0))) + 8))))((ts4l_word)t11);
            *(ts4l_word *)((char *)(ts4l_word)(a0) + 656) = (ts4l_word)0;
        }
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 652) = (ts4l_word)0;
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 60))))((ts4l_word)a0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 88))))((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83220588: if_get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x3c, vcall */
ts4l_word ts4l_if_get_u32_off0_83220588(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4l_word)a1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 60))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x832205F8: if_get u32@0x2c, u32@0x0, u32@0x8, vcall, u32@0x2c */
ts4l_word ts4l_if_get_u32_off2c_832205F8(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83221118: loop_call_seq u32@0x170, fn_8340CE90, u32@0x170 */
ts4l_word ts4l_loop_call_seq_u32_off170_83221118(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 368);
    if ((ts4l_word)t1 != 0) {
        do {
            fn_8340CE90((ts4l_word)50);
            t3 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 368);
        } while ((ts4l_word)t3 != 0);
    }
    return 0;
}

/* Loader_DLL.xex 0x83221190: if_call_seq u32@0x7c, u32@0x80, u32@0x7c, fn_8321FD40, u32@0x7c, u32@0x7c */
ts4l_word ts4l_if_call_seq_u32_off7c_83221190(ts4l_word a0)
{
    ts4l_word t1;
    ts4l_word t3;
    ts4l_word t4;

    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 124);
    if ((ts4l_word)t1 == 1440 && (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 128)) == 1080) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)1920;
    }
    t3 = fn_8321FD40((ts4l_word)a0);
    t4 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 124);
    if ((ts4l_word)t1 != (ts4l_word)t4) {
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 124) = (ts4l_word)t1;
    }
    return t3;
}

/* Loader_DLL.xex 0x832215A0: call_seq fn_8321F468, lbl_8302AFB8, u32@0x0, fn_83221098 */
ts4l_word ts4l_call_seq_fn_8321F468_832215A0(ts4l_word a0)
{
    fn_8321F468((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AFB8;
    fn_83221098((ts4l_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x83221E08: if_call_seq lbl_8302AFB8, u32@0x0, fn_83221648, fn_8321F9F8, fn_8340D830 */
ts4l_word ts4l_if_call_seq_lbl_8302AFB8_83221E08(ts4l_word a0, ts4l_word a1)
{
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 0) = (ts4l_word)(ts4l_word)lbl_8302AFB8;
    fn_83221648();
    fn_8321F9F8((ts4l_word)a0);
    if ((ts4l_word)(a1 & 0x1) != 0) {
        fn_8340D830((ts4l_word)a0, (ts4l_word)((546045952) | 32810));
    }
    return a0;
}

/* Loader_DLL.xex 0x83221F28: call_seq fn_83227440, u32@0x208, u32@0x1fc, u32@0x20c, u64@0x210, u32@0x218 */
ts4l_word ts4l_call_seq_fn_83227440_83221F28(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_83227440((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 520) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 508) = (ts4l_word)2;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 524) = (ts4l_word)0;
    *(ts4l_u64 *)((char *)(ts4l_word)(a0) + 528) = (ts4l_u64)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 536) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 540) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 544) = (ts4l_word)1;
    return t1;
}

/* Loader_DLL.xex 0x83222178: if_get u32@0x20c, fn_8340D830, u32@0x20c, u32@0x0, u32@0x4c, vcall */
ts4l_word ts4l_if_get_u32_off20c_83222178(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 524);
    if ((ts4l_word)t1 != 0) {
        fn_8340D830((ts4l_word)t1, (ts4l_word)((546045952) | 32797));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 524) = (ts4l_word)0;
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 76))))((ts4l_word)a0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 80))))((ts4l_word)a0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 132))))((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83222270: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x50, vcall */
ts4l_word ts4l_get_u32_off0_83222270(ts4l_word a0, ts4l_word a1)
{
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 80))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x83222388: if_get u32@0x30, u32@0x0, u32@0x8, vcall, u32@0x30 */
ts4l_word ts4l_if_get_u32_off30_83222388(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 48);
    if ((ts4l_word)t1 != 0) {
        ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(t1) + 0))) + 8))))((ts4l_word)t1);
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x83222C00: call_seq fn_8322C010, fn_83220068, fn_832272F0, fn_83227008 */
ts4l_word ts4l_call_seq_fn_8322C010_83222C00(ts4l_word a0)
{
    ts4l_word t4;

    fn_8322C010((ts4l_word)(a0 + 212));
    fn_83220068((ts4l_word)(a0 + 136));
    fn_832272F0((ts4l_word)(a0 + 56));
    t4 = fn_83227008((ts4l_word)a0);
    return t4;
}

/* Loader_DLL.xex 0x83222F40: call_seq fn_8322C398, u32@0x2a0, u32@0x294, u32@0x2a4, u32@0x298, u32@0x29c */
ts4l_word ts4l_call_seq_fn_8322C398_83222F40(ts4l_word a0)
{
    ts4l_word t1;

    t1 = fn_8322C398((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 672) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 660) = (ts4l_word)1;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 676) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 664) = (ts4l_word)0;
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 668) = (ts4l_word)0;
    return t1;
}

/* Loader_DLL.xex 0x83223558: if_get u32@0x2c, fn_8340D830, u32@0x2c, u32@0x0, u32@0x4c, vcall */
ts4l_word ts4l_if_get_u32_off2c_83223558(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 44);
    if ((ts4l_word)t1 != 0) {
        fn_8340D830((ts4l_word)t1, (ts4l_word)((546045952) | 32791));
        *(ts4l_word *)((char *)(ts4l_word)(a0) + 44) = (ts4l_word)0;
    }
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 76))))((ts4l_word)a0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 80))))((ts4l_word)a0);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 132))))((ts4l_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x83223978: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x50, vcall */
ts4l_word ts4l_get_u32_off0_83223978(ts4l_word a0, ts4l_word a1)
{
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a1) + 0))) + 4))))((ts4l_word)a1);
    ((ts4l_word (*)(ts4l_word))((*(ts4l_word *)((char *)(ts4l_word)((*(ts4l_word *)((char *)(ts4l_word)(a0) + 0))) + 80))))((ts4l_word)a0);
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 48) = (ts4l_word)a1;
    return 0;
}
