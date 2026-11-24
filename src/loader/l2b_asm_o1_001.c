/* Loader_DLL.xex 0x83117A28-0x8313B9D4, executable version 0.0.0.3. */
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

extern char fn_831213F0[];
extern char fn_83121400[];
extern char fn_83121410[];
extern char fn_83134208[];
extern char fn_831343C8[];
extern char fn_83134490[];
extern char fn_83136F00[];
extern char fn_835168C0[];
extern char lbl_83002050[];
extern char lbl_83002064[];
extern char lbl_8352F7A8[];
extern char lbl_8352F7B4[];
extern char lbl_8352F804[];
extern char lbl_83531098[];
extern char lbl_835310E8[];
extern char lbl_835310FC[];
ts4_word fn_830FF250();
ts4_word fn_830FFB68();
ts4_word fn_83109390();
ts4_word fn_83109520();
ts4_word fn_8310D4E0();
ts4_word fn_83111448();
ts4_word fn_83111610();
ts4_word fn_83112428();
ts4_word fn_831124C0();
ts4_word fn_83113188();
ts4_word fn_83115E50();
ts4_word fn_831161B0();
ts4_word fn_831163B8();
ts4_word fn_83119498();
ts4_word fn_8311B000();
ts4_word fn_8311B5B8();
ts4_word fn_8311BA20();
ts4_word fn_8311BBA8();
ts4_word fn_8311CA80();
ts4_word fn_8311CCA0();
ts4_word fn_8311DAD8();
ts4_word fn_8311DE90();
ts4_word fn_8311E038();
ts4_word fn_8311EF40();
ts4_word fn_83120540();
ts4_word fn_83121700();
ts4_word fn_83121FD8();
ts4_word fn_831221D0();
ts4_word fn_83123478();
ts4_word fn_831234C0();
ts4_word fn_831235E8();
ts4_word fn_83123A38();
ts4_word fn_83123B10();
ts4_word fn_83124370();
ts4_word fn_831244B8();
ts4_word fn_831246B8();
ts4_word fn_83124800();
ts4_word fn_83124848();
ts4_word fn_83124890();
ts4_word fn_831248D8();
ts4_word fn_83124920();
ts4_word fn_83124D08();
ts4_word fn_83125930();
ts4_word fn_83126A08();
ts4_word fn_831291F8();
ts4_word fn_8312ACB0();
ts4_word fn_8312AD30();
ts4_word fn_8312B060();
ts4_word fn_8312B4E8();
ts4_word fn_8312B970();
ts4_word fn_8312DF48();
ts4_word fn_8312E6E0();
ts4_word fn_8312F008();
ts4_word fn_83131B78();
ts4_word fn_83132450();
ts4_word fn_83133558();
ts4_word fn_8313B898();
ts4_word fn_831403E8();
ts4_word fn_8314DF10();
ts4_word fn_8314E0B8();
ts4_word fn_8314E408();
ts4_word fn_83150770();
ts4_word fn_8315B2B8();
ts4_word fn_8315DED8();
ts4_word fn_833E3AD0();
ts4_word fn_833E4920();
ts4_word fn_8340CE98();

/* Loader_DLL.xex 0x83117A28: if_call_seq fn_83115E50, u32@lbl_8352F7B4, fn_83111448 */
ts4_word ts4l_if_call_seq_fn_83115E50_83117A28(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[4];
    int t1;
    ts4_word t4;

    t1 = fn_83115E50((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t1 >= 0 && (int)(loc50[0]) != 0) {
        t4 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7B4));
        p5 = (ts4_word)(t4 != 0);
    } else {
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x8311BCF8: call_seq fn_8311BA20, u32@0x28, u32@0x28, u32@0x2c, u32@0x2c, fn_833E3AD0 */
ts4_word ts4l_call_seq_fn_8311BA20_8311BCF8(ts4_word a0, ts4_word a1)
{
    ts4_word t14;

    fn_8311BA20((ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 48));
    fn_833E3AD0((ts4_word)a1, (ts4_word)a0, (ts4_word)24);
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    *(ts4_word *)((char *)(ts4_word)(a1) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    *(ts4_word *)((char *)(ts4_word)(a1) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    *(ts4_word *)((char *)(ts4_word)(a1) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64));
    *(ts4_word *)((char *)(ts4_word)(a1) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    *(ts4_word *)((char *)(ts4_word)(a1) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52));
    t14 = fn_8311B5B8((ts4_word)a0);
    return t14;
}

/* Loader_DLL.xex 0x8311F460: if_call_seq u8@lbl_83531098, u32@0x0, fn_8311E038, fn_8311DE90, fn_8311EF40, fn_83120540 */
ts4_word ts4l_if_call_seq_u8_lbl_83531098_8311F460(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word p13;
    ts4_word p14;
    ts4_word p15;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word loc5c[1];
    unsigned char t1;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)lbl_83531098;
    if ((ts4_word)t1 == 0) {
        p15 = (ts4_word)((2147483648) | 65535);
    } else {
        if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            loc50[0] = (ts4_word)0;
            t2 = fn_8311E038((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
            p13 = (ts4_word)t2;
            if ((int)t2 >= 0) {
                t3 = loc50[0];
                t4 = fn_8311DE90((ts4_word)t3, (ts4_word)(ts4_word)&loc5c[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0]);
                p10 = (ts4_word)t4;
                if ((int)t4 >= 0) {
                    t5 = loc54[0];
                    t6 = loc58[0];
                    t7 = loc5c[0];
                    t8 = fn_8311EF40((ts4_word)t7, (ts4_word)t6, (ts4_word)t5, (ts4_word)a1, (ts4_word)a2);
                    p10 = (ts4_word)t8;
                }
                t11 = loc50[0];
                fn_83120540((ts4_word)t11);
                p13 = (ts4_word)p10;
            }
            p14 = (ts4_word)p13;
        } else {
            p14 = (ts4_word)((2147942400) | 87);
        }
        p15 = (ts4_word)p14;
    }
    return p15;
}

/* Loader_DLL.xex 0x83120AC8: if_call_seq u32@0xf0, u32@0xf0, u32@0xf4, fn_8314DF10, u32@0xf4, fn_8315B2B8 */
ts4_word ts4l_if_call_seq_u32_offf0_83120AC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 240)) & 0xfffbffff);
    p6 = (ts4_word)0;
    if ((ts4_word)a1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 244)) != 0) {
        fn_8314DF10((ts4_word)a1, (ts4_word)(a0 + 164));
        t5 = fn_8315B2B8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 244)));
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83120E80: if_set u32@0x28, u32@0x24, u32@0x20, u32@0x20, u32@0x24, u32@0x2c */
ts4_word ts4l_if_set_u32_off28_83120E80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 40) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 36) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)a3;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 32) = (ts4_word)a1;
    }
    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 36) = (ts4_word)a1;
    }
    if ((ts4_word)a2 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)a1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 240)) | 32768);
    return 0;
}

/* Loader_DLL.xex 0x83121510: if_call_seq u32@0x0, fn_831161B0, fn_8310D4E0, u32@0x10, u32@0x10 */
ts4_word ts4l_if_call_seq_u32_off0_83121510(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    fn_831161B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_8310D4E0((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) & 0xfffffffb);
    return p5;
}

/* Loader_DLL.xex 0x83121760: if_call_seq u32@lbl_8352F7A8, fn_83111448, u32@0x20, fn_83121700, u32@0x0, fn_830FF250 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F7A8_83121760(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t4;

    t2 = fn_83111448((ts4_word)a1, (ts4_word)(*(ts4_word *)lbl_8352F7A8));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 32);
    if ((ts4_word)t3 == 0) {
        t5 = fn_830FF250((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
        t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t7 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + 1);
        p9 = (ts4_word)t5;
    } else {
        t4 = fn_83121700((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
        p9 = (ts4_word)t4;
    }
    return p9;
}

/* Loader_DLL.xex 0x831219D8: if_call_seq u32@0x0, fn_831161B0, u32@0x0, lbl_83002050, lbl_83002064, fn_831163B8 */
ts4_word ts4l_if_call_seq_u32_off0_831219D8(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    loc50[0] = (ts4_word)0;
    t2 = fn_831161B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    p6 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t5 = fn_831163B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)lbl_83002064, (ts4_word)(ts4_word)lbl_83002050, (ts4_word)0, (ts4_word)0);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83121B50: if_get u32@0xa0, u32@0xa4, u32@0x9c, u32@0x9c, u32@0xa4, u32@0x9c */
void ts4l_if_get_u32_offa0_83121B50(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 160);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)0;
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 156)) & 0xfffffffd) & 0xfffffff7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)1;
        return;
    }
    if ((int)t1 == 1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 156)) & 0xfffffffe) & 0xfffffffb);
        *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)1;
        return;
    }
    if ((int)t1 != 4 && (int)t1 != 5) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 156)) & 0xfffffff0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x83122178: if_call_seq u8@0xbc, fn_8340CE98, u32@0xb8, u32@0x0, fn_8311DAD8, u8@0xbc */
ts4_word ts4l_if_call_seq_u8_offbc_83122178(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
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
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 188);
    p6 = (ts4_word)a0;
    if ((ts4_word)t1 == 0) {
        t2 = fn_8340CE98();
        *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)t2;
        t4 = fn_8311DAD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)((2864381952) | 52445), (ts4_word)16);
        *(unsigned char *)((char *)(ts4_word)(a0) + 188) = (unsigned char)1;
        p6 = (ts4_word)t4;
    }
    return p6;
}

/* Loader_DLL.xex 0x83122EA8: get  */
void ts4l_get_83122EA8(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(float *)((char *)(ts4_word)(a0) + 24) = (*(float *)((char *)(ts4_word)(a1) + 24));
    *(float *)((char *)(ts4_word)(a0) + 28) = (*(float *)((char *)(ts4_word)(a1) + 28));
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    *(float *)((char *)(ts4_word)(a0) + 56) = (*(float *)((char *)(ts4_word)(a1) + 56));
    *(float *)((char *)(ts4_word)(a0) + 60) = (*(float *)((char *)(ts4_word)(a1) + 60));
    return;
}

/* Loader_DLL.xex 0x83123028: get  */
void ts4l_get_83123028(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    float t3;
    float t5;
    float t7;

    t1 = *(float *)((char *)(ts4_word)(a2) + 0);
    *(float *)((char *)(ts4_word)(a0) + 0) = ((*(float *)((char *)(ts4_word)(a1) + 0)) * t1);
    t3 = *(float *)((char *)(ts4_word)(a2) + 4);
    *(float *)((char *)(ts4_word)(a0) + 4) = ((*(float *)((char *)(ts4_word)(a1) + 4)) * t3);
    t5 = *(float *)((char *)(ts4_word)(a2) + 8);
    *(float *)((char *)(ts4_word)(a0) + 8) = ((*(float *)((char *)(ts4_word)(a1) + 8)) * t5);
    t7 = *(float *)((char *)(ts4_word)(a1) + 12);
    *(float *)((char *)(ts4_word)(a0) + 12) = (t7 * (*(float *)((char *)(ts4_word)(a2) + 12)));
    return;
}

/* Loader_DLL.xex 0x83124208: call_seq fn_831234C0, fn_830FFB68, fn_83109520 */
ts4_word ts4l_call_seq_fn_831234C0_83124208(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    fn_831234C0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109520((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    return ((((t3) >> 31) + -1) & t4);
}

/* Loader_DLL.xex 0x83124260: call_seq fn_83123478, fn_830FFB68, fn_83109520 */
ts4_word ts4l_call_seq_fn_83123478_83124260(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    fn_83123478((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_830FFB68((ts4_word)a0);
    t3 = fn_83109520((ts4_word)t2, (ts4_word)(ts4_word)&loc60[0]);
    t4 = loc50[0];
    return ((((t3) >> 31) + -1) & t4);
}

/* Loader_DLL.xex 0x83124458: if_call_seq fn_83123A38, fn_83109390, u32@0x0 */
ts4_word ts4l_if_call_seq_fn_83123A38_83124458(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t3;
    ts4_word t4;

    fn_83123A38((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    if ((ts4_word)a1 != 0) {
        t3 = loc50[1];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
    }
    t4 = loc50[0];
    return t4;
}

/* Loader_DLL.xex 0x83124598: if_call_seq fn_83123B10, fn_83109390 */
ts4_word ts4l_if_call_seq_fn_83123B10_83124598(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word loc60[8];
    int t2;
    ts4_word t3;

    fn_83123B10((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    if ((int)t2 < 0) {
        p4 = (ts4_word)0;
    } else {
        t3 = loc50[1];
        p4 = (ts4_word)((((t3) >> 31) + -1) & t3);
    }
    return p4;
}

/* Loader_DLL.xex 0x83124600: if_call_seq fn_83123B10, fn_83109390 */
ts4_word ts4l_if_call_seq_fn_83123B10_83124600(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word loc60[8];
    int t2;
    ts4_word t3;

    fn_83123B10((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    if ((int)t2 < 0) {
        p4 = (ts4_word)0;
    } else {
        t3 = loc50[1];
        p4 = (ts4_word)((((t3) >> 31) + -1) & t3);
    }
    return p4;
}

/* Loader_DLL.xex 0x83124D68: if_call_seq fn_831244B8, fn_83124D08, fn_831246B8 */
ts4_word ts4l_if_call_seq_fn_831244B8_83124D68(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    int t2;
    ts4_word t3;

    t1 = fn_831244B8((ts4_word)a0, (ts4_word)a1);
    if ((int)t1 >= 0) {
        t2 = fn_83124D08((ts4_word)a0, (ts4_word)a1);
        if ((int)t2 == 0) {
            t3 = fn_831246B8((ts4_word)a0, (ts4_word)a1);
            p4 = (ts4_word)t3;
        } else {
            p4 = (ts4_word)t1;
        }
        p5 = (ts4_word)p4;
    } else {
        p5 = (ts4_word)t1;
    }
    return p5;
}

/* Loader_DLL.xex 0x83125B08: call_seq fn_83125930 */
ts4_word ts4l_call_seq_fn_83125930_83125B08(ts4_word a0, ts4_word a1)
{
    fn_83125930((ts4_word)a0);
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 100));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 104));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 108));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 112));
    *(float *)((char *)(ts4_word)(a1) + 16) = (*(float *)((char *)(ts4_word)(a0) + 116));
    *(float *)((char *)(ts4_word)(a1) + 20) = (*(float *)((char *)(ts4_word)(a0) + 120));
    *(float *)((char *)(ts4_word)(a1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 124));
    *(float *)((char *)(ts4_word)(a1) + 28) = (*(float *)((char *)(ts4_word)(a0) + 128));
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a0) + 132));
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a0) + 136));
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 140));
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 144));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 148));
    *(float *)((char *)(ts4_word)(a1) + 52) = (*(float *)((char *)(ts4_word)(a0) + 152));
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 156));
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 160));
    return 0;
}

/* Loader_DLL.xex 0x83125BC8: call_seq fn_83125930 */
ts4_word ts4l_call_seq_fn_83125930_83125BC8(ts4_word a0, ts4_word a1)
{
    fn_83125930((ts4_word)a0);
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 164));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 168));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 172));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 176));
    *(float *)((char *)(ts4_word)(a1) + 16) = (*(float *)((char *)(ts4_word)(a0) + 180));
    *(float *)((char *)(ts4_word)(a1) + 20) = (*(float *)((char *)(ts4_word)(a0) + 184));
    *(float *)((char *)(ts4_word)(a1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 188));
    *(float *)((char *)(ts4_word)(a1) + 28) = (*(float *)((char *)(ts4_word)(a0) + 192));
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a0) + 196));
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a0) + 200));
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 204));
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 208));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 212));
    *(float *)((char *)(ts4_word)(a1) + 52) = (*(float *)((char *)(ts4_word)(a0) + 216));
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 220));
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 224));
    return 0;
}

/* Loader_DLL.xex 0x83125FE8: if_call_seq u32@0xe4, fn_8311BBA8, u32@0xe4, fn_8311CCA0, fn_83120540, u32@0xe4 */
ts4_word ts4l_if_call_seq_u32_offe4_83125FE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p13;
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    if ((ts4_word)t1 != 0) {
        fn_8311BBA8((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    if ((ts4_word)t4 != 0) {
        fn_8311CCA0((ts4_word)t4);
        fn_83120540((ts4_word)t4);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)a1;
    if ((ts4_word)a1 != 0) {
        t9 = fn_830FFB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 228))) + 0) = (ts4_word)t9;
        t12 = fn_8311CA80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 228)));
        p13 = (ts4_word)t12;
    } else {
        p13 = (ts4_word)0;
    }
    return p13;
}

/* Loader_DLL.xex 0x831268F0: if_call_seq fn_831124C0, fn_830FFB68, fn_831235E8, fn_83109520 */
ts4_word ts4l_if_call_seq_fn_831124C0_831268F0(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word loc70[6];
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    loc50[0] = (ts4_word)0;
    fn_831124C0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    if ((ts4_word)t2 == 0) {
        p7 = (ts4_word)0;
    } else {
        t3 = fn_830FFB68((ts4_word)a0);
        fn_831235E8((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)t3);
        t5 = loc50[0];
        t6 = fn_83109520((ts4_word)t5, (ts4_word)(ts4_word)&loc70[0]);
        p7 = (ts4_word)t6;
    }
    return p7;
}

/* Loader_DLL.xex 0x83126C28: if_call_seq u32@0x0, fn_830FFB68, fn_83124890, fn_831248D8, u8@0x38, fn_83111610 */
ts4_word ts4l_if_call_seq_u32_off0_83126C28(ts4_word a0)
{
    ts4_word p21;
    ts4_word p22;
    ts4_word p23;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t2;
    int t3;
    int t7;
    ts4_word t13;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;

    t2 = fn_830FFB68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    t3 = fn_83124890((ts4_word)t2);
    p23 = (ts4_word)t3;
    if ((int)t3 != 0) {
        fn_831248D8((ts4_word)t2, (ts4_word)0);
        fn_83111610((ts4_word)t2, (ts4_word)0, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 56)));
        t7 = fn_83124800((ts4_word)t2);
        if ((int)t7 != 0) {
            fn_83126A08((ts4_word)t2, (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 56)));
        }
        fn_83124920((ts4_word)t2);
        loc50[0] = (ts4_word)0;
        fn_831161B0((ts4_word)t2, (ts4_word)(ts4_word)&loc50[0]);
        t13 = loc50[0];
        p22 = (ts4_word)t13;
        if ((ts4_word)t13 != 0) {
            loc54[0] = (ts4_word)0;
            fn_83113188((ts4_word)t13, (ts4_word)(ts4_word)&loc54[0]);
            t15 = loc54[0];
            p21 = (ts4_word)t15;
            if ((ts4_word)t15 != 0) {
                t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 24);
                t17 = *(ts4_word *)((char *)(ts4_word)(t15) + 12);
                t18 = *(ts4_word *)((char *)(ts4_word)(t15) + 16);
                t20 = fn_8311B000((ts4_word)t15, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t15) + 8)), (ts4_word)t17, (ts4_word)t17, (ts4_word)t18, (ts4_word)((t16 + 1) != 0));
                p21 = (ts4_word)t20;
            }
            p22 = (ts4_word)p21;
        }
        p23 = (ts4_word)p22;
    }
    return p23;
}

/* Loader_DLL.xex 0x83127858: if_call_seq u32@0x0, u32@0x4, fn_830FFB68, fn_83124848 */
ts4_word ts4l_if_call_seq_u32_off0_83127858(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    int t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)t1 != 1) {
        p5 = (ts4_word)((2147942400) | 87);
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        t3 = fn_830FFB68((ts4_word)a1);
        fn_83124848((ts4_word)t3, (ts4_word)t2);
        p5 = (ts4_word)0;
    }
    return p5;
}

/* Loader_DLL.xex 0x8312B538: if_call_seq u8@0x8, u32@0x84, u32@0x4, fn_8312B4E8, u8@0x8 */
ts4_word ts4l_if_call_seq_u8_off8_8312B538(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        fn_8312B4E8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t2, (ts4_word)(a0 + 12));
        *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x8312B900: if_call_seq u8@0xc, u32@0x88, u32@0x8, fn_8312B060, fn_8315DED8, u8@0xc */
ts4_word ts4l_if_call_seq_u8_offc_8312B900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
        fn_8312B060((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)t2, (ts4_word)(a0 + 16), (ts4_word)(a0 + 152));
        fn_8315DED8((ts4_word)(a0 + 152), (ts4_word)(a0 + 152));
        *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x8312BCF8: if_call_seq u32@lbl_8352F804, fn_83111448, fn_8312ACB0 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F804_8312BCF8(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F804));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = fn_8312ACB0((ts4_word)t2, (ts4_word)a1);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x8312CBA8: if_call_seq u32@0x4, u32@0x1c, u32@0x4, fn_8314E0B8, u32@0x0, u32@0x8 */
ts4_word ts4l_if_call_seq_u32_off4_8312CBA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p12;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    int t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t1 & 0xfffffffe);
    if ((ts4_word)t2 != 0) {
        fn_8314E0B8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)((a0 + 28)) + 0) = (ts4_word)0;
    }
    loc50[0] = (ts4_word)0;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t7 = fn_831291F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t5);
    p12 = (ts4_word)t7;
    if ((int)t7 >= 0) {
        t8 = loc50[0];
        t9 = fn_83150770((ts4_word)t8, (ts4_word)(a0 + 28));
        t10 = loc50[0];
        fn_83120540((ts4_word)t10);
        p12 = (ts4_word)t9;
    }
    return p12;
}

/* Loader_DLL.xex 0x8312CD20: if_call_seq u32@0x4, u32@0xa8, fn_83120540, u32@0xc, u32@0xa8, u32@0xc */
ts4_word ts4l_if_call_seq_u32_off4_8312CD20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t29;
    ts4_word t34;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t21;
    ts4_word t23;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 != 10) {
        if ((ts4_word)t1 != 40) {
            if ((ts4_word)t1 == 41) {
                t29 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
                if ((ts4_word)t29 != 0) {
                    fn_83120540((ts4_word)t29);
                    *(ts4_word *)((char *)(ts4_word)((a0 + 168)) + 0) = (ts4_word)0;
                }
                loc50[0] = (ts4_word)0;
                fn_831124C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)&loc50[0]);
                t34 = loc50[0];
                fn_831291F8((ts4_word)(a0 + 168), (ts4_word)t34, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 248)));
            }
        } else {
            t15 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 16))) + 0);
            if ((ts4_word)(t15 & 0x1) == 1) {
                t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
                if ((ts4_word)t16 != 0) {
                    fn_83120540((ts4_word)t16);
                    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t18 | 2);
                }
                t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
                if ((ts4_word)t21 != 0) {
                    fn_8314E408((ts4_word)t21, (ts4_word)1);
                    t23 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
                    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t23 | 2);
                }
            }
        }
    } else {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
        if ((ts4_word)t2 != 0) {
            fn_83120540((ts4_word)t2);
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
            *(ts4_word *)((char *)(ts4_word)(a0) + 168) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t4 | 2);
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 172);
        if ((ts4_word)t7 != 0) {
            fn_8314E408((ts4_word)t7, (ts4_word)1);
            t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
            *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t9 | 2);
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x8312E798: if_call_seq u32@0xc8, fn_8312E6E0 */
ts4_word ts4l_if_call_seq_u32_offc8_8312E798(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 200);
    p3 = (ts4_word)a0;
    if ((ts4_word)(t1 & 0x4) != 4) {
        t2 = fn_8312E6E0((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 188));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 192));
    return p3;
}

/* Loader_DLL.xex 0x8312E7F0: if_call_seq lbl_835310E8, u32@lbl_835310FC, u32@lbl_835310FC, fn_831403E8, fn_835168C0, fn_833E4920 */
ts4_word ts4l_if_call_seq_lbl_835310E8_8312E7F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)lbl_835310FC;
    if ((int)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_835310FC = (ts4_word)(t1 | 1);
        fn_831403E8((ts4_word)(ts4_word)lbl_835310E8, (ts4_word)22592);
        fn_833E4920((ts4_word)(ts4_word)fn_835168C0);
    }
    return (ts4_word)lbl_835310E8;
}

/* Loader_DLL.xex 0x8312F1C8: if_call_seq u32@0xa8, fn_83119498, fn_8312F008, fn_83124370, u32@0x2c, u32@0x0 */
ts4_word ts4l_if_call_seq_u32_offa8_8312F1C8(ts4_word a0, ts4_word a1)
{
    ts4_word p9;
    ts4_word p15;
    ts4_word p16;
    ts4_word p17;
    ts4_word loc50[4];
    int t2;
    ts4_word t3;
    int t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    int t12;
    ts4_word t13;
    ts4_word t14;

    loc50[0] = (ts4_word)0;
    t2 = fn_83119498((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 168)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)1, (ts4_word)0);
    p17 = (ts4_word)t2;
    if ((int)t2 >= 0) {
        t3 = loc50[0];
        t4 = fn_8312F008((ts4_word)a0, (ts4_word)a1, (ts4_word)t3);
        p16 = (ts4_word)t4;
        if ((int)t4 >= 0) {
            t5 = loc50[0];
            fn_83124370((ts4_word)t5, (ts4_word)0);
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
            p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
            if ((ts4_word)t7 != 0) {
                p9 = (ts4_word)t7;
            }
            t10 = loc50[0];
            t11 = fn_830FFB68((ts4_word)p9);
            t12 = fn_83112428((ts4_word)t11, (ts4_word)t10);
            p15 = (ts4_word)t12;
            if ((int)t12 >= 0) {
                t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 176);
                t14 = loc50[0];
                *(ts4_word *)((char *)(ts4_word)(t13) + (a1 << 2)) = (ts4_word)t14;
                p15 = (ts4_word)0;
            }
            p16 = (ts4_word)p15;
        }
        p17 = (ts4_word)p16;
    }
    return p17;
}

/* Loader_DLL.xex 0x83132640: if_call_seq u32@0x4, fn_8312B970, u32@0x0, fn_83132450, u8@0xc, u32@0x10 */
ts4_word ts4l_if_call_seq_u32_off4_83132640(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word p20;
    ts4_word t1;
    ts4_word t10;
    ts4_word t6;
    int t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 != 0) {
        if ((ts4_word)t1 != 16) {
            if ((ts4_word)t1 != 33) {
                if ((ts4_word)t1 != 40) {
                    if ((ts4_word)t1 == 41) {
                        fn_8312B970((ts4_word)a0);
                        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
                    }
                } else {
                    t10 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 16))) + 0);
                    if ((ts4_word)(t10 & 0x1) == 1 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)) == 1) {
                        fn_831221D0((ts4_word)(a0 + 4));
                        *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
                    }
                }
            } else {
                t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
                *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
                *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)1;
            }
        } else {
            *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
        }
        p20 = (ts4_word)0;
    } else {
        t2 = fn_8312B970((ts4_word)a0);
        p5 = (ts4_word)t2;
        if ((int)t2 >= 0) {
            t4 = fn_83132450((ts4_word)(a0 + 4), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
            p5 = (ts4_word)t4;
        }
        p20 = (ts4_word)p5;
    }
    return p20;
}

/* Loader_DLL.xex 0x83132720: if_call_seq u32@lbl_8352F804, fn_83111448, u32@0x48, u32@0x44, fn_83131B78 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F804_83132720(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F804));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        *(ts4_word *)((char *)(ts4_word)(t2) + 72) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 68) = (ts4_word)a2;
        t3 = fn_83131B78((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83133920: if_call_seq u32@0x8, u32@0x18, u32@0xf0, u32@0xf0, u32@0x10, fn_8312DF48 */
ts4_word ts4l_if_call_seq_u32_off8_83133920(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 240);
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)(t2 | 262144);
    if ((ts4_word)t1 != 0) {
        fn_8312DF48((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)), (ts4_word)1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(t2 | 262144));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 240);
        if ((ts4_word)(t5 & 0x4000) == 16384) {
            fn_83133558((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16)));
        }
    }
    return 0;
}

/* Loader_DLL.xex 0x831356A0: if_call_seq u32@0x0, fn_83124800, u32@0x74, u32@0x94, u32@0x74, u32@0x6c */
ts4_word ts4l_if_call_seq_u32_off0_831356A0(ts4_word a0, int a1)
{
    ts4_word p6;
    ts4_word p10;
    ts4_word p11;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    t2 = fn_83124800((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    p11 = (ts4_word)t2;
    if ((int)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
        *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t3 + -5);
        if ((ts4_word)(t4 & 0x1) == 1) {
            p6 = (ts4_word)0;
        } else {
            p6 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 108)) + 5);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)p6;
        fn_83121FD8((ts4_word)a0);
        t8 = fn_83131B78((ts4_word)a0);
        p10 = (ts4_word)t8;
        if ((int)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)2;
            t9 = fn_8312AD30((ts4_word)a0, (ts4_word)(a0 + 4));
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x83135740: if_call_seq u32@0x0, fn_83124800, u32@0x74, u32@0x94, u32@0x74, u32@0x6c */
ts4_word ts4l_if_call_seq_u32_off0_83135740(ts4_word a0, int a1)
{
    ts4_word p6;
    ts4_word p10;
    ts4_word p11;
    int t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    t2 = fn_83124800((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
    p11 = (ts4_word)t2;
    if ((int)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
        *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(t3 + 5);
        if ((ts4_word)(t4 & 0x1) == 1) {
            p6 = (ts4_word)0;
        } else {
            p6 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 108)) + -5);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)p6;
        fn_83121FD8((ts4_word)a0);
        t8 = fn_83131B78((ts4_word)a0);
        p10 = (ts4_word)t8;
        if ((int)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)2;
            t9 = fn_8312AD30((ts4_word)a0, (ts4_word)(a0 + 20));
            p10 = (ts4_word)t9;
        }
        p11 = (ts4_word)p10;
    }
    return p11;
}

/* Loader_DLL.xex 0x83136050: if_call_seq u32@lbl_8352F804, fn_83111448, u32@0x8c, u32@0x90, u32@0x5c, u32@0x74 */
ts4_word ts4l_if_call_seq_u32_lbl_8352F804_83136050(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F804));
    if ((ts4_word)t2 == 0) {
        p11 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 140);
        *(ts4_word *)((char *)(ts4_word)(t2) + 144) = (ts4_word)a1;
        if ((ts4_word)a1 < (ts4_word)t3) {
            *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 92))) + (a1 << 1)) = (unsigned short)0;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 116);
        t7 = *(ts4_word *)((char *)(ts4_word)(t2) + 108);
        t8 = *(ts4_word *)((char *)(ts4_word)(t2) + 144);
        if ((ts4_word)t8 < (ts4_word)(t7 + t6)) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 108) = (ts4_word)(t8 - t6);
        }
        t10 = fn_83131B78((ts4_word)t2);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Loader_DLL.xex 0x831375B0: addr fn_831213F0, fn_83121400, u32@0x0, u32@0x4, fn_83136F00, fn_83134208 */
void ts4l_addr_fn_831213F0_831375B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_831213F0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_83121400;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_83136F00;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_83134208;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)fn_831343C8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)fn_83134490;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(ts4_word)fn_83121410;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8313B968: if_call_seq u32@0x74, u32@0x6c, u32@0x0, fn_83124800, u32@0x6c, u32@0x74 */
ts4_word ts4l_if_call_seq_u32_off74_8313B968(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p8;
    ts4_word p9;
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    if ((int)(t2 + t1) != 0) {
        t4 = fn_83124800((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        if ((int)t4 != 0) {
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
            t7 = fn_8313B898((ts4_word)a0, (ts4_word)((t5 + (*(ts4_word *)((char *)(ts4_word)(a0) + 116))) + -1), (ts4_word)1);
            p8 = (ts4_word)t7;
        } else {
            p8 = (ts4_word)0;
        }
        p9 = (ts4_word)p8;
    } else {
        p9 = (ts4_word)0;
    }
    return p9;
}
