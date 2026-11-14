/* Loader_DLL.xex 0x832DC860-0x832DC860, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef unsigned long ts4l_word;

ts4l_word fn_832863B0();
ts4l_word fn_832DBAD0();
ts4l_word fn_832DBE78();

/* Loader_DLL.xex 0x832DC860: if_call_seq u32@0x128, u32@0x128, fn_832DBAD0, fn_832863B0, fn_832DBE78 */
ts4l_word ts4l_if_call_seq_u32_off128_832DC860(ts4l_word a0)
{
    int t2;
    ts4l_word t5;

    if ((ts4l_word)a0 == 0) {
        return 1;
    }
    t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 296);
    if ((int)t2 == 0) {
        t5 = fn_832DBE78((ts4l_word)a0);
        return t5;
    }
    fn_832DBAD0((ts4l_word)a0);
    fn_832863B0((ts4l_word)a0);
    return 0;
}
