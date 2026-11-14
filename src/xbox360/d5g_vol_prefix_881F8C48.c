/* Swing_DLL.xex 0x881F8C48-0x881F8E48, executable version 0.0.0.3. */
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

extern char lbl_880E97F0[];
ts4_word fn_8818EB10();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_881F8DF8();
ts4_word fn_881FBC60();
ts4_word ts4_call_seq_fn_881FBB40_881FB860();

/* Swing_DLL.xex 0x881F8C48: if_call_seq lbl_880E97F0, u32@0x4, u32@0x0, u32@0x8, fn_8818EB10, u32@0x10 */
ts4_word ts4_if_call_seq_lbl_880E97F0_881F8C48(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word p11;
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t10;
    ts4_word t12;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E97F0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_8818EB10((ts4_word)(a0 + 12), (ts4_word)a1);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    t2 = fn_88199068((ts4_word)0, (ts4_word)280, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        t3 = fn_881F8DF8((ts4_word)t2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t6 != 0) {
        ts4_call_seq_fn_881FBB40_881FB860((ts4_word)t6);
        fn_881992A8((ts4_word)0, (ts4_word)t6);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)p4;
    loc58[0] = (ts4_word)1000;
    loc58[1] = (ts4_word)0;
    t10 = fn_88199068((ts4_word)0, (ts4_word)32, (ts4_word)(ts4_word)&loc58[0]);
    if ((ts4_word)t10 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t10) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t10) + 12) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t10) + 8) = (ts4_word)12;
        p11 = (ts4_word)t10;
    } else {
        p11 = (ts4_word)0;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t12 != 0) {
        fn_881FBC60((ts4_word)t12);
        fn_881992A8((ts4_word)0, (ts4_word)t12);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)p11;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)3;
    return a0;
}
