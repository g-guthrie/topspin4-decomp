/* Loader_DLL.xex 0x831A4D98-0x831A4E1C, executable version 0.0.0.3. */
/* Pick a minimum-40-byte request size from a record kind/length and fill it via a helper. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;

ts4_word fn_831A4CF0();
ts4_word fn_833E0AB0();

/* 0x831A4D98: if_call_seq u16@0x0, u16@0x10, fn_833E0AB0, fn_831A4CF0 */
ts4_word ts4_if_call_seq_u16_off0_831A4D98(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word p5;
    ts4_word loc50[4];
    unsigned short t1;
    ts4_word t6;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 357) {
        p4 = (ts4_word)32;
    } else {
        if ((ts4_word)t1 == 1) {
            p3 = (ts4_word)18;
        } else {
            p3 = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(a0) + 16)) + 18);
        }
        p4 = (ts4_word)p3;
    }
    p5 = (ts4_word)p4;
    loc50[0] = (ts4_word)p4;
    if ((ts4_word)p4 < 40) {
        loc50[0] = (ts4_word)40;
        p5 = (ts4_word)40;
    }
    t6 = fn_833E0AB0((ts4_word)p5);
    if ((int)t6 != 0) {
        fn_831A4CF0((ts4_word)a0, (ts4_word)t6, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    }
    return t6;
}
