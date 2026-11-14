/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

ts4_word fn_887F49B8();
ts4_word ts4_loop_get_u32_off8_88890670();

/* Swing_DLL.xex 0x886091E0: get u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off0_886091E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 16))))((ts4_word)a3, (ts4_word)a0, (ts4_word)((int)a1 * (int)a2));
    return ((int)t3 / (int)a1);
}

/* Swing_DLL.xex 0x88609228: get u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off0_88609228(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 4))))((ts4_word)a3, (ts4_word)a0, (ts4_word)((int)a1 * (int)a2));
    return ((int)t3 / (int)a1);
}

/* Swing_DLL.xex 0x887F4D30: loop_get u32@0x0, u32@0x40, vcall, u32@0x24, u32@0x5c, u32@0x24 */
void ts4_loop_get_u32_off0_887F4D30(ts4_word a0)
{
    ts4_word lv25;
    ts4_word p34;
    ts4_word t4;
    ts4_word t5;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_word t22;
    ts4_word t26;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(t4 + 1);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 620));
    }
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 48))))((ts4_word)a0);
    fn_887F49B8((ts4_word)a0);
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 168);
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
    ts4_loop_get_u32_off8_88890670((ts4_word)t20, (ts4_word)(t19 % t18), (ts4_word)t19);
    lv25 = (ts4_word)t21;
    while ((ts4_word)lv25 != (ts4_word)t22) {
        t26 = *(ts4_word *)((char *)(ts4_word)(lv25) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 0))) + 16))))((ts4_word)t26, (ts4_word)(t19 % t18));
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t26) + 0))) + 20))))((ts4_word)t26, (ts4_word)(t19 % t18));
        p34 = (ts4_word)(lv25 + 4);
        lv25 = p34;
    }
    return;
}

/* Swing_DLL.xex 0x88884CD0: get u32@0x8, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x10 */
ts4_word ts4_get_u32_off8_88884CD0(ts4_word a0)
{
    ts4_word h1;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    h1 = (ts4_word)((char *)(ts4_word)(a0) + 8);
    t1 = *(ts4_word *)h1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(((t1 << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4)))) + 4);
    *(ts4_word *)h1 = (ts4_word)((t1 + 1) % t2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + -1);
    return t4;
}

/* Swing_DLL.xex 0x88884D10: get u32@0xc, u32@0x4, u32@0x4, u32@0xc, u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_offc_88884D10(ts4_word a0, ts4_word a1)
{
    ts4_word h1;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;

    h1 = (ts4_word)((char *)(ts4_word)(a0) + 12);
    t1 = *(ts4_word *)h1;
    *(unsigned char *)((char *)(ts4_word)((t1 << 3)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 4))) = (unsigned char)0;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)h1) << 3) + t3)) + 4) = (ts4_word)a1;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t6 = *(ts4_word *)h1;
    *(ts4_word *)h1 = (ts4_word)((t6 + 1) % t5);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 1);
    return t6;
}

/* Swing_DLL.xex 0x8890DAE8: if_get u32@0x1c, u32@0x20, u32@0x1c, u32@0x20, u32@0x1c, u32@0x20 */
void ts4_if_get_u32_off1c_8890DAE8(ts4_word a0, ts4_word a1)
{
    ts4_word h3;
    int h2;
    ts4_word h1;
    ts4_word t6;

    h3 = (ts4_word)(28 + (char *)(ts4_word)(a0));
    h2 = (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) - (*(volatile ts4_word *)h3)) / (int)52);
    if ((ts4_word)a1 >= (ts4_word)h2) {
        return;
    }
    if ((int)a1 < 0) {
        return;
    }
    h1 = (ts4_word)((((int)a1 * 52) + (*(ts4_word *)h3)));
    t6 = *(volatile ts4_word *)((char *)(ts4_word)h1 + 32);
    if ((ts4_word)t6 >= (ts4_word)h2) {
        return;
    }
    if ((int)t6 < 0) {
        return;
    }
    *(volatile unsigned char *)((char *)(ts4_word)h1 + 48) = (unsigned char)1;
    return;
}
