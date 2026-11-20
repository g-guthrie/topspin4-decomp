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

ts4_word lib3_lua_type_88822738();

/* Swing_DLL.xex 0x881B1CF0: if_call_seq u32@0x0, u32@0x4, u32@0x0, lib3_lua_type_88822738 */
ts4_word ts4_if_call_seq_u32_off0_881B1CF0(ts4_word a0)
{
    int b80;
    ts4_word t104;
    ts4_word p6;
    int t2;
    int t1;
    int t4;

    t1 = *(ts4_word *)(0 + (char *)(ts4_word)(a0));
    t2 = *(ts4_word *)(4 + (char *)(ts4_word)(a0));
    t104 = (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    t4 = lib3_lua_type_88822738((ts4_word)(t104), (ts4_word)t2);
    b80 = (int)(((int)t4 == 4 || (int)t4 == 3) || ((int)t4 == 9));
    p6 = (ts4_word)b80;
    return (p6 != 0);
}

/* Swing_DLL.xex 0x8858E658: loop_get u8@0x554, u32@0x868, u8@0x0, u32@0x868 */
void ts4_loop_get_u8_off554_8858E658(ts4_word a0)
{
    ts4_word lv3;
    ts4_word lv4;
    ts4_word p6;
    ts4_word p7;
    unsigned char t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1364);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 2152);
    if ((ts4_word)(t1 + 18) < (ts4_word)t2) {
        lv4 = (ts4_word)(t1 + 18);
        lv3 = (ts4_word)((((lv4) + 1221) << 3) + a0);
        do {
            *(unsigned char *)((char *)(ts4_word)((lv3 + 8)) + 0) = (unsigned char)100;
            t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 2152);
            p6 = (ts4_word)(lv3 + 8);
            p7 = (ts4_word)(lv4 + 1);
            lv3 = p6;
            lv4 = p7;
        } while ((ts4_word)p7 < (ts4_word)t5);
        return;
    }
    return;
}
