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
#include "ts4_vector.h"

extern "C" {
extern char g_ts4_script_constants[];
ts4_word ts4_member_field_addr_8883B318(ts4_word, ts4_word);

}
/* Swing_DLL.xex 0x886C37B0: if_get u32@0x4, u32@0x20, u8@0x20 */
struct ts4_obj_886C37B0 { void ts4_if_get_u32_off4_886C37B0(ts4_word a1, ts4_word a2); };
void ts4_obj_886C37B0::ts4_if_get_u32_off4_886C37B0(ts4_word a1, ts4_word a2)
{
    ts4_word a0 = (ts4_word)this;
    float pf6;
    __vector4 vv8;
    __vector4 vv9;
    ts4_word locm10[4];
    ts4_word t2;
    float t3;
    unsigned char t4;
    float t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 32);
    t3 = *(float *)g_ts4_script_constants;
    t4 = *(unsigned char *)((char *)(ts4_word)(t2) + 32);
    if ((ts4_word)t4 != 0) {
        pf6 = (*(float *)((char *)(ts4_word)(t2) + 36));
    } else {
        pf6 = t3;
    }
    t7 = *(float *)((char *)(ts4_word)(t2) + 28);
    *(float *)((char *)locm10 + 0) = t3;
    *(float *)((char *)locm10 + 4) = t3;
    *(float *)((char *)locm10 + 8) = t7;
    *(float *)((char *)locm10 + 12) = t3;
    vv8 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    *(float *)((char *)locm10 + 0) = pf6;
    *(float *)((char *)locm10 + 4) = t3;
    *(float *)((char *)locm10 + 8) = (t7 * pf6);
    *(float *)((char *)locm10 + 12) = t3;
    vv9 = *(__vector4 *)((ts4_word)((ts4_word)&locm10[0]));
    *(__vector4 *)((ts4_word)(a1)) = vv8;
    *(__vector4 *)((ts4_word)(a2)) = vv9;
    return;
}

/* Swing_DLL.xex 0x88842598: if_call_seq u32@0x6c, u32@0x68, ts4_member_field_addr_8883B318, u32@0x60, u32@0x68, u32@0x68 */
struct ts4_obj_88842598 { void ts4_if_call_seq_u32_off6c_88842598(ts4_word a1, ts4_word a2); };
void ts4_obj_88842598::ts4_if_call_seq_u32_off6c_88842598(ts4_word a1, ts4_word a2)
{
    ts4_word a0 = (ts4_word)this;
    ts4_word t3;
    ts4_word t4;

    if ((int)a1 > -1 && (ts4_word)a1 < (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(a0) + 108)) - (*(ts4_word *)((char *)(ts4_word)(a0) + 104))) / (int)20)) {
        t3 = ts4_member_field_addr_8883B318((ts4_word)a0, (ts4_word)a1);
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 96);
        if ((ts4_word)t4 != (ts4_word)((3751936000) | 45041)) {
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 104))) + ((a1 + (a1 << 2)) << 2)) = (ts4_word)a2;
            *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 104)) + ((a1 + (a1 << 2)) << 2))) + 4) = (ts4_word)t4;
        }
    }
    return;
}
