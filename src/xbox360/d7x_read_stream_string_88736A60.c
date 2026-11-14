/* Swing_DLL.xex 0x88736A60-0x88736B28, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

extern char lbl_88D45B38[];
ts4_word fn_8816CAA0(ts4_word, ts4_word);
ts4_word ts4_small_string256_from_cstr_881A5020(ts4_word);
ts4_word fn_88613268(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word ts4_loop_get_u32_off0_886F5AE0(ts4_word, ts4_word);
ts4_word fn_88719330(ts4_word);
ts4_word ts4_registry_dispatch_888860A0(ts4_word);

ts4_word ts4_read_stream_string_88736A60(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc60[68];
    ts4_word loc54;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;

    loc50[0] = (ts4_word)0;
    ts4_small_string256_from_cstr_881A5020((ts4_word)(ts4_word)&loc60[0]);
    t2 = ts4_loop_get_u32_off0_886F5AE0((ts4_word)(ts4_word)&loc54, (ts4_word)(ts4_word)&loc60[0]);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    loc50[0] = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        return 0;
    }
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 20))))((ts4_word)t3);
    t8 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)(t6 + 1), (ts4_word)1, (ts4_word)0, (ts4_word)0);
    t9 = loc50[0];
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 4))))((ts4_word)t9, (ts4_word)t8, (ts4_word)t6);
    *(unsigned char *)((char *)(ts4_word)(t8) + t6) = (unsigned char)0;
    fn_8816CAA0((ts4_word)a0, (ts4_word)t8);
    ts4_registry_dispatch_888860A0((ts4_word)t8);
    fn_88719330((ts4_word)(ts4_word)&loc50[0]);
    return 1;
}
