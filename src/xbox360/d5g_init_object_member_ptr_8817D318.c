/* Swing_DLL.xex 0x8817D318-0x8817D3E0, executable version 0.0.0.3. */
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

extern char lbl_880DB670[];
extern char lbl_88D45B38[];
ts4_word fn_88613570();
ts4_word fn_88617D88();
ts4_word ts4_if_call_seq_fn_88883CD0_8860D250();

/* Swing_DLL.xex 0x8817D318: if_call_seq fn_88617D88, lbl_880DB670, u32@lbl_88D45B38, u32@0x0, u32@0x3c, ts4_if_call_seq_fn_88883CD0_8860D250 */
ts4_word ts4_init_object_member_ptr_8817D318(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    volatile ts4_word *sub;

    fn_88617D88((ts4_word)a0);
    sub = (volatile ts4_word *)(a0 + 60);
    t2 = *(ts4_word *)lbl_88D45B38;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB670;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        t3 = ts4_if_call_seq_fn_88883CD0_8860D250((ts4_word)t2);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    t5 = fn_88613570((ts4_word)p4, (ts4_word)20, (ts4_word)4, (ts4_word)(a0 + 60));
    sub[1] = 0;
    sub[0] = t5;
    *(volatile unsigned char *)((char *)(ts4_word)(t5) + 0) = (unsigned char)0;
    *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 60)) + 0))) + 4) = (ts4_word)0;
    t7 = *(ts4_word *)((char *)(ts4_word)((a0 + 60)) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 8) = (ts4_word)t7;
    t8 = *(ts4_word *)((char *)(ts4_word)((a0 + 60)) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(t8) + 12) = (ts4_word)t8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 136) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    return a0;
}
