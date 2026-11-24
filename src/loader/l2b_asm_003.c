/* Loader_DLL.xex 0x83165620-0x831988E0, executable version 0.0.0.3. */
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

extern char lbl_830009F8[];
extern char lbl_83000A00[];
extern char lbl_83002888[];
extern char lbl_8300A080[];
extern char lbl_8300C94C[];
extern char lbl_8300C958[];
extern char lbl_8300C95C[];
extern char lbl_8300C960[];
extern char lbl_8300C964[];
ts4_word fn_83120540();
ts4_word fn_83163540();
ts4_word fn_83186BB0();
ts4_word fn_8318BD40();
ts4_word fn_831CD7A8();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();

/* Loader_DLL.xex 0x83165620: if_call_seq u32@0xc, fn_83120540, u32@0x10, fn_83120540 */
ts4_word ts4l_if_call_seq_u32_offc_83165620(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_83120540((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_83120540((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Loader_DLL.xex 0x83166018: call_seq fn_83163540, u32@0x18, u32@0x18 */
ts4_word ts4l_call_seq_fn_83163540_83166018(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_83163540((ts4_word)a0, (ts4_word)16, (ts4_word)a1, (ts4_word)6);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return t1;
}

/* Loader_DLL.xex 0x83187058: if_call_seq u32@0x28, u32@0x3c, u32@0x40, u32@0x44, u32@0x48, fn_83186BB0 */
ts4_word ts4l_if_call_seq_u32_off28_83187058(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        fn_83186BB0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t4 != 0) {
        fn_83186BB0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)((a0 + 36)) + 0) = (ts4_word)0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t7 != 0) {
        fn_83186BB0((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t10 != 0) {
        fn_83186BB0((ts4_word)t10);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    }
    t13 = fn_833E3A30((ts4_word)(a0 + 36), (ts4_word)0, (ts4_word)24);
    return t13;
}

/* Loader_DLL.xex 0x8318BC30: if_get u32@0x0, u32@0x3c, u32@0xd4, u32@0x25c, u32@0x8, u32@0x25c */
ts4_word ts4l_if_get_u32_off0_8318BC30(ts4_word a0)
{
    ts4_word t1;
    int t2;
    int t8;
    int t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 60);
    if ((int)t2 <= 2) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 212);
        if ((int)t8 != 0) {
            return (((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) + 11) & 0xff);
        }
        return 0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 604);
    t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    if ((int)t6 != 0) {
        return ((t7 + 17) & 0xff);
    }
    return ((t7 + 6) & 0xff);
}

/* Loader_DLL.xex 0x8318BF88: if_call_seq fn_8318BD40, fn_833E3A30, u32@0x14, u32@0xc, u32@0x20, u32@0x24 */
ts4_word ts4l_if_call_seq_fn_8318BD40_8318BF88(ts4_word a0)
{
    int t1;

    t1 = fn_8318BD40();
    if ((int)t1 >= 0) {
        fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)720);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 164) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 692) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 696) = (ts4_word)1;
    }
    return t1;
}

/* Loader_DLL.xex 0x83193DD0: if_set u32@0x0, u32@0x0, lbl_8300A080, lbl_8300A080, u32@0x0, u32@0x0 */
void ts4l_if_set_u32_off0_83193DD0(ts4_word a0, int a1, int a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
    if ((int)a2 != 0) {
        if ((int)a1 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)((ts4_word)lbl_8300A080 + 8768);
            *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)11;
            return;
        }
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)((ts4_word)lbl_8300A080 + 6104);
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)22;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(ts4_word)lbl_8300A080;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)30;
    return;
}

/* Loader_DLL.xex 0x83194EE8: call_seq u32@0x0, u32@0x0, u16@0x4, u32@0x4, u16@0x4, fn_831CD7A8 */
ts4_word ts4l_call_seq_u32_off0_83194EE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4));
    t4 = fn_831CD7A8((ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 20));
    return t4;
}

/* Loader_DLL.xex 0x83195D08: if_get u16@0x0, u32@0x4, u16@0x0, u16@0x2, u16@0x2, u32@0x4 */
ts4_word ts4l_if_get_u16_off0_83195D08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;

    t1 = *(unsigned short *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    *(unsigned short *)((char *)(ts4_word)(a1) + 0) = (unsigned short)t1;
    *(unsigned short *)((char *)(ts4_word)(a1) + 2) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(a2) + 2));
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    if ((ts4_word)t5 == 0) {
        return a0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    return fn_833E3AD0((ts4_word)t2, (ts4_word)t5, (ts4_word)(((t6 + (t6 << 1)) << 1) + 4));
}

/* Loader_DLL.xex 0x83198838: if_get  */
float ts4l_if_get_83198838(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 <= 10) {
        return (*(float *)lbl_8300C964);
    }
    if ((ts4_word)a0 <= 25) {
        return (*(float *)lbl_8300C960);
    }
    if ((ts4_word)a0 <= 50) {
        return (*(float *)lbl_8300C94C);
    }
    if ((ts4_word)a0 <= 75) {
        return (*(float *)lbl_83002888);
    }
    if ((ts4_word)a0 <= 90) {
        return (*(float *)lbl_8300C95C);
    }
    if ((ts4_word)a0 < 100) {
        return (*(float *)lbl_8300C958);
    }
    if ((ts4_word)a0 == 100) {
        if ((ts4_word)(a1 & 0xffff) == 355 || (ts4_word)(a1 & 0xffff) == 359) {
            return (*(float *)lbl_830009F8);
        }
        return (*(float *)lbl_83000A00);
    }
    return (*(float *)lbl_83000A00);
}
