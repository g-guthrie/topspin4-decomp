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
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif

extern char lbl_88001A20[];
extern char lbl_880DD1EC[];
extern char lbl_88D3E374[];
extern char lbl_88D3E398[];
extern char lbl_88D3E39C[];
ts4_word fn_8818F298();
ts4_word fn_88198CE0();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_88199370();
ts4_word ts4_loop_get_fn_881F5E78_881F58F0();
ts4_word fn_881F5E78();
ts4_word fn_885B72F0();
ts4_word ts4_lua_getmetatable_88823768();

/* Swing_DLL.xex 0x881918C8: if_set u32@0x48, u32@0x5c, u32@lbl_88D3E374, fn_88198CE0, fn_8818F298, fn_88199068 */
ts4_word ts4_if_set_u32_off48_881918C8(ts4_word a0)
{
    ts4_word loc60[4];
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    unsigned char t13;
    ts4_word t19;
    ts4_word t20;
    ts4_word t22;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    t2 = fn_88198CE0((ts4_word)(*(volatile ts4_word *)lbl_88D3E374));
    fn_8818F298((ts4_word)(ts4_word)&loc60[0]);
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)1000;
    t4 = fn_88199068((ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)(ts4_word)&loc50[0]);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108);
    if ((ts4_word)t5 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t5);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)t4;
    loc58[0] = (ts4_word)1000;
    loc58[1] = (ts4_word)0;
    t8 = fn_88199068((ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)(ts4_word)&loc58[0]);
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t9 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t9);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)t8;
    t13 = *(volatile unsigned char *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16))) + 16);
    if ((ts4_word)(t13 & 0x40) != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)lbl_88D3E398)))((ts4_word)(a0 + 52), (ts4_word)-15, (ts4_word)(ts4_word)lbl_880DD1EC, (ts4_word)56);
    } else {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)lbl_88D3E39C)))((ts4_word)(a0 + 52), (ts4_word)(ts4_word)lbl_880DD1EC, (ts4_word)56);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    t19 = loc60[1];
    t20 = loc60[0];
    fn_88199370((ts4_word)t20, (ts4_word)t19);
    t22 = fn_88198CE0((ts4_word)t2);
    return t22;
}

/* Swing_DLL.xex 0x881F58F0: loop_get fn_881F5E78, u32@0x0, u32@0x2c, vcall, u32@0x14, ts4_loop_get_fn_881F5E78_881F58F0 */
ts4_word ts4_loop_get_fn_881F5E78_881F58F0(ts4_word a0)
{
    ts4_word lv6;
    ts4_word p9;
    ts4_word p10;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    fn_881F5E78((ts4_word)a0, (ts4_word)0);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p10 = (ts4_word)t4;
    lv6 = (ts4_word)t5;
    while ((ts4_word)lv6 != 0) {
        t7 = ((ts4_word (*)())ts4_loop_get_fn_881F5E78_881F58F0)((ts4_word)lv6);
        p9 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv6) + 24));
        lv6 = p9;
        p10 = (ts4_word)t7;
    }
    return p10;
}

/* Swing_DLL.xex 0x881F8BE8: call_seq u32@0x0, ts4_lua_getmetatable_88823768, u32@0x0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_881F8BE8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    ts4_lua_getmetatable_88823768((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x88335BF8: if_get u32@0x44, u32@0xc0 */
ts4_word ts4_if_get_u32_off44_88335BF8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 192);
        if ((ts4_word)t3 != 0) {
            return ((ts4_word (*)(ts4_word, ts4_word))(t3))((ts4_word)(t1 + 28), (ts4_word)a1);
        }
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)lbl_88001A20);
        return 25;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)lbl_88001A20);
    return 25;
}

/* Swing_DLL.xex 0x885B9010: if_get u32@0x0, interlocked_dec, u8@0x0, fn_885B72F0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_885B9010(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0 && (int)t1 != -1) {
        t2 = _InterlockedDecrement((volatile long *)(ts4_word)((t1 + 16)));
        p4 = (ts4_word)t1;
        if ((ts4_word)t2 == 0) {
            *(unsigned char *)((char *)(ts4_word)(t1) + 0) = (unsigned char)15;
            t3 = fn_885B72F0((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 + 16));
            p4 = (ts4_word)t3;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        p5 = (ts4_word)p4;
    }
    return p5;
}

/* Swing_DLL.xex 0x8883BDD0: loop_get u32@0x24, u32@0x20, u32@0x0, u32@0x0, u32@0x184, u32@0x8c */
ts4_word ts4_loop_get_u32_off24_8883BDD0(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv3;
    ts4_word p15;
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    int t8;
    ts4_word t10;
    ts4_word t13;

    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 36);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 32);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    lv3 = (ts4_word)t2;
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t7 = *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t8 = *(volatile ts4_word *)((char *)(ts4_word)(t7) + 388);
        if ((int)t8 == (int)a2) {
            t10 = *(volatile ts4_word *)((char *)(ts4_word)(t7) + 140);
            if ((ts4_word)t10 != 0) {
                t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t10) + 0))) + 76))))((ts4_word)t10, (ts4_word)0);
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t13) + 12));
                return a0;
            }
            return a0;
        }
        p15 = (ts4_word)(lv3 + 4);
        lv3 = p15;
    }
    return a0;
}

/* Swing_DLL.xex 0x888D4E80: loop_get u32@0x12c, u32@0x0, u32@0x0, u32@0x4, u32@0x44, u32@0x44 */
ts4_word ts4_loop_get_u32_off12c_888D4E80(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p7;
    ts4_word lv8;
    ts4_word p12;
    ts4_word t1;
    int t2;
    int t4;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 300);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    p7 = (ts4_word)0;
    if ((int)t4 != -1) {
        p7 = (ts4_word)((((int)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) * 368) + t4) + t1);
    }
    if ((ts4_word)p3 != (ts4_word)p7) {
        lv8 = (ts4_word)p3;
        do {
            t10 = *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 68);
            if ((ts4_word)t10 == 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 68) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0));
                *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 72) = (ts4_word)0;
                return lv8;
            }
            p12 = (ts4_word)(lv8 + 368);
            lv8 = p12;
        } while ((ts4_word)p12 != (ts4_word)p7);
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x888D8730: loop_get u32@0x28, u32@0x0, u32@0x0, u32@0x4, u32@0x44, u32@0x44 */
ts4_word ts4_loop_get_u32_off28_888D8730(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p7;
    ts4_word lv8;
    ts4_word p12;
    ts4_word t1;
    int t2;
    int t4;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    p3 = (ts4_word)0;
    if ((int)t2 != -1) {
        p3 = (ts4_word)(t2 + t1);
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    p7 = (ts4_word)0;
    if ((int)t4 != -1) {
        p7 = (ts4_word)((((int)(*(volatile ts4_word *)((char *)(ts4_word)(t1) + 4)) * 368) + t4) + t1);
    }
    if ((ts4_word)p3 != (ts4_word)p7) {
        lv8 = (ts4_word)p3;
        do {
            t10 = *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 68);
            if ((ts4_word)t10 == 0) {
                *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 68) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0));
                *(volatile ts4_word *)((char *)(ts4_word)(lv8) + 72) = (ts4_word)0;
                return lv8;
            }
            p12 = (ts4_word)(lv8 + 368);
            lv8 = p12;
        } while ((ts4_word)p12 != (ts4_word)p7);
        return 0;
    }
    return 0;
}
