/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, a named pointer
   for a repeated base+offset, ||/&& conditions kept in a bool temporary,
   ...).  In .cpp files a function whose first argument is `this` is a member
   of a one-function struct ts4_obj_<ADDR>: MSVC orders the operands of
   commutative instructions differently for `this` than for a plain argument.
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_8803DA00[];
extern char lbl_88080278[];
extern char lbl_8808029C[];
extern char lbl_8808122C[];
extern char lbl_88081250[];
ts4_word fn_8843C308();
ts4_word ts4_get_u32_lbl_88CACF08_8841B228();

/* Swing_DLL.xex 0x8841B2F0: if_call_seq u32@0x8, lbl_8803DA00, u16@0x6, u32@0x0, ts4_get_u32_lbl_88CACF08_8841B228, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_8841B2F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803DA00;
    ts4_get_u32_lbl_88CACF08_8841B228((ts4_word)(a0 + 12), (ts4_word)a2);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(unsigned short *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t3 != 0) {
        *(short *)((char *)(ts4_word)(t2) + 6) = (short)((*(short *)((char *)(ts4_word)(t2) + 6)) + 1);
    }
    return a0;
}

/* Swing_DLL.xex 0x8843CA68: if_call_seq fn_8843C308, u32@0x1c, lbl_8808029C, u32@0x18, lbl_88080278, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8843C308_8843CA68(ts4_word a0, ts4_word a1, ts4_word a2, float f1)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    fn_8843C308((ts4_word)a0, (ts4_word)8);
    *(float *)((char *)(ts4_word)(a0) + 32) = f1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808029C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88080278;
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t2 != 0) {
        *(short *)((char *)(ts4_word)(a1) + 6) = (short)((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t5 = *(unsigned short *)((char *)(ts4_word)(t4) + 4);
    if ((ts4_word)t5 != 0) {
        *(short *)((char *)(ts4_word)(t4) + 6) = (short)((*(short *)((char *)(ts4_word)(t4) + 6)) + 1);
    }
    return a0;
}

/* Swing_DLL.xex 0x8844BAA8: if_call_seq fn_8843C308, lbl_88081250, u32@0x18, lbl_8808122C, u32@0x0, u32@0x10 */
ts4_word ts4_if_call_seq_fn_8843C308_8844BAA8(ts4_word a0, ts4_word a1, float f1)
{
    ts4_word t2;

    fn_8843C308((ts4_word)a0, (ts4_word)8);
    *(float *)((char *)(ts4_word)(a0) + 32) = f1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081250;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_8808122C;
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t2 != 0) {
        *(short *)((char *)(ts4_word)(a1) + 6) = (short)((*(short *)((char *)(ts4_word)(a1) + 6)) + 1);
    }
    return a0;
}
