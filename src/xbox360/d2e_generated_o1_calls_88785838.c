/* Swing_DLL.xex 0x88785838-0x88879BF8, executable version 0.0.0.3. */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#endif
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_88D459D0[];
extern char lbl_88D459D8[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_88213D38();
ts4_word fn_8846C178();
ts4_word fn_88613268();
ts4_word fn_88799490();
ts4_word fn_88851F00();
ts4_word fn_88852068();
ts4_word fn_8886F8B0();
ts4_word fn_889C0AE0();





/* Swing_DLL.xex 0x88878DE0: call_seq u32@0x0, fn_889C0AE0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88878DE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc60[16];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    loc60[3] = (ts4_word)a0;
    loc60[0] = (ts4_word)a2;
    loc60[1] = (ts4_word)a3;
    loc50[0] = (ts4_word)t1;
    loc60[4] = (ts4_word)t1;
    t2 = fn_889C0AE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t3;
    return t2;
}

/* Swing_DLL.xex 0x88878E38: call_seq u32@0x0, fn_889C0AE0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88878E38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[4];
    ts4_word loc60[16];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    loc60[3] = (ts4_word)a1;
    loc60[0] = (ts4_word)a3;
    loc60[1] = (ts4_word)a4;
    loc50[0] = (ts4_word)t1;
    loc60[4] = (ts4_word)t1;
    t2 = fn_889C0AE0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    t3 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t3;
    return t2;
}

/* Swing_DLL.xex 0x88879BF8: if_call_seq u32@0x10, u32@0x34, u32@0x34, fn_8846C178 */
ts4_word ts4_if_call_seq_u32_off10_88879BF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0 && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52)) + -1);
        t3 = fn_8846C178((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1, (ts4_word)a1);
        p4 = (ts4_word)t3;
    }
    return p4;
}
