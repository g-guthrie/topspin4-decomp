/* Swing_DLL.xex 0x8856C298-0x8856C2FC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: allocation wrapper that propagates the failure code to errno. */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void *fn_88577518(u32 num, u32 size, int *perr);

void *ts4_crt_calloc_crt_8856C298(u32 num, u32 size)
{
    int err = 0;
    void *res = fn_88577518(num, size, &err);
    if (res == 0 && err != 0 && ts4_if_call_seq_fn_8856CD88_88567ED8() != 0)
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = err;
    return res;
}
