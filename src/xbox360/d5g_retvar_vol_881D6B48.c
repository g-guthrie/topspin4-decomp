/* Swing_DLL.xex 0x881D6B48-0x882073A0, executable version 0.0.0.3. */
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

extern char lbl_880E8624[];
extern char lbl_880E9E98[];
extern char lbl_8814B440[];
ts4_word fn_88199068();

/* Swing_DLL.xex 0x881D6B48: if_call_seq fn_88199068, u32@0x4, lbl_880E8624, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88199068_881D6B48(void)
{
    ts4_word r_ = 0;
    ts4_word loc50[4];
    ts4_word t1;
    float t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)64, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8624;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
        t2 = *(float *)lbl_8814B440;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 56) = (ts4_word)0;
        *(volatile float *)((char *)(ts4_word)(t1) + 60) = t2;
        r_ = t1;
    }
    return r_;
}

/* Swing_DLL.xex 0x882071A0: if_call_seq fn_88199068, u32@0x4, u32@0x8, lbl_880E9E98, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_fn_88199068_882071A0(void)
{
    ts4_word r_ = 0;
    ts4_word loc50[4];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)60, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E9E98;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 20) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 32) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 52) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t1) + 56) = (ts4_word)0;
        r_ = t1;
    }
    return r_;
}
