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

extern char g_ts4_script_constants[];
extern char lbl_8814B440[];
float ts4_rng_range_8861E598(ts4_word, float, float);
ts4_word ts4_loop_call_seq_u32_off2c_8890E988();

/* Swing_DLL.xex 0x8867E968: call_seq u32@0x4, u32@0x44, ts4_rng_range_8861E598, ts4_rng_range_8861E598, u32@0x4, u32@0x50 */
ts4_word ts4_call_seq_u32_off4_8867E968(ts4_word a0)
{
    ts4_word t2;
    float t3;
    float t4;
    float t5;
    float t6;
    ts4_word t9;
    ts4_word t10;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 68);
    t3 = *(float *)g_ts4_script_constants;
    t4 = *(float *)lbl_8814B440;
    t5 = ts4_rng_range_8861E598((ts4_word)(t2 + 180), t4, t3);
    t6 = ts4_rng_range_8861E598((ts4_word)(t2 + 180), t4, t3);
    t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 80))) + 40);
    *(float *)((char *)(ts4_word)(t9) + 196) = t5;
    *(float *)((char *)(ts4_word)(t9) + 200) = t6;
    t10 = ts4_loop_call_seq_u32_off2c_8890E988((ts4_word)(a0 + 32));
    return t10;
}
