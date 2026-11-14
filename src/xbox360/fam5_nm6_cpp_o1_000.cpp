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

extern "C" {
ts4_word lib3_lua_type_88822738(ts4_word, ts4_word);

}
/* Swing_DLL.xex 0x881B1CF0: if_call_seq u32@0x0, u32@0x4, u32@0x0, fn_88822738 */
struct ts4_obj_881B1CF0 { ts4_word ts4_if_call_seq_u32_off0_881B1CF0(); };
ts4_word ts4_obj_881B1CF0::ts4_if_call_seq_u32_off0_881B1CF0()
{
    ts4_word a0 = (ts4_word)this;
    ts4_word b70;
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    int t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = lib3_lua_type_88822738((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0)), (ts4_word)t2);
    b70 = ((int)t4 == 4 || (int)t4 == 3) || ((int)t4 == 9);
    p6 = (ts4_word)b70;
    return (p6 != 0);
}

/* Swing_DLL.xex 0x88884018: if_get u8@0x1 */
struct ts4_obj_88884018 { ts4_word ts4_if_get_u8_off1_88884018(); };
ts4_word ts4_obj_88884018::ts4_if_get_u8_off1_88884018()
{
    ts4_word a0 = (ts4_word)this;
    unsigned char b70;
    ts4_word p3;
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1);
    b70 = ((ts4_word)t1 == 130) || ((ts4_word)t1 == 151);
    p3 = (ts4_word)b70;
    return (p3 & 0xff);
}
