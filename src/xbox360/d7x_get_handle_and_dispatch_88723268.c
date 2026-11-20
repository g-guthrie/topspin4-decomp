/* Swing_DLL.xex 0x88723268-0x887232F0, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

ts4_word ts4_small_string256_from_cstr_881A5020(ts4_word);
ts4_word ts4_loop_get_u32_off0_886F5AE0(ts4_word, ts4_word);
ts4_word fn_88719330(ts4_word);
ts4_word fn_887230E8(ts4_word, ts4_word);

ts4_word ts4_get_handle_and_dispatch_88723268(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc60[68];
    ts4_word loc54;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    ts4_small_string256_from_cstr_881A5020((ts4_word)(ts4_word)&loc60[0]);
    t2 = ts4_loop_get_u32_off0_886F5AE0((ts4_word)(ts4_word)&loc54, (ts4_word)(ts4_word)&loc60[0]);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    loc50[0] = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        return ((2147483648) | 16389);
    }
    t4 = fn_887230E8((ts4_word)a0, (ts4_word)t3);
    fn_88719330((ts4_word)(ts4_word)&loc50[0]);
    return t4;
}
