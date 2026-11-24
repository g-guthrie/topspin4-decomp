/* Loader_DLL.xex 0x8319E778-0x832341A0, executable version 0.0.0.3.
   Small accessor / call-sequence functions; parameters are untyped words
   (a0 = this/first argument), field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
typedef __int64 ts4l_s64;
#else
typedef unsigned long long ts4l_u64;
typedef long long ts4l_s64;
#endif
typedef unsigned long ts4l_word;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif

ts4l_word RtlEnterCriticalSection();
ts4l_word RtlLeaveCriticalSection();
ts4l_word fn_8319E408();
ts4l_word ts4l_call_seq_u32_off0_83233D68();

/* Loader_DLL.xex 0x8319E778: get RtlEnterCriticalSection, u32@0x20, fn_8319E408, interlocked_inc, u32@0x20, RtlLeaveCriticalSection */
ts4l_word ts4l_get_RtlEnterCriticalSection_8319E778(ts4l_word a0, ts4l_word a1)
{
    ts4l_word t5;

    RtlEnterCriticalSection((ts4l_word)(a0 + 36));
    fn_8319E408((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 32)));
    _InterlockedIncrement((volatile long *)(ts4l_word)((a1 + 16)));
    *(ts4l_word *)((char *)(ts4l_word)(a0) + 32) = (ts4l_word)a1;
    t5 = RtlLeaveCriticalSection((ts4l_word)(a0 + 36));
    return t5;
}

/* Loader_DLL.xex 0x83234120: if_get u32@0x208, u32@0x20c, vcall, u32@0x1fc, ts4l_call_seq_u32_off0_83233D68, u32@0x0 */
ts4l_word ts4l_if_get_u32_off208_83234120(ts4l_word a0, ts4l_word a1, ts4l_word a2, ts4l_word a3, ts4l_word a4, ts4l_word a5, ts4l_word a6, ts4l_word a7)
{
    ts4l_word t1;
    ts4l_word t2;
    int t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 520);
    if ((ts4l_word)t1 != 0) {
        t2 = *(ts4l_word *)((char *)(ts4l_word)(a0) + 524);
        ((ts4l_word (*)(ts4l_word, ts4l_word, ts4l_word, ts4l_word))(t1))((ts4l_word)a0, (ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(((a1 & 0xff) << 2)) + a0)), (ts4l_word)a1, (ts4l_word)t2);
    }
    t7 = ts4l_call_seq_u32_off0_83233D68((ts4l_word)(*(ts4l_word *)((char *)(ts4l_word)(a0) + 508)), (ts4l_word)2, (ts4l_word)(((a1 & 0xff) << 2) + a0));
    if ((int)t7 >= 0) {
        *(ts4l_word *)((char *)(ts4l_word)((((a1 & 0xff) << 2) + a0)) + 0) = (ts4l_word)0;
    }
    return t7;
}
