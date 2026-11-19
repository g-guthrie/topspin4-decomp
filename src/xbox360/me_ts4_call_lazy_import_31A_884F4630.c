/* 0x884F4630: calls the module export with ordinal 0x31A through a cached pointer (lbl_88D2704C), resolving it first with ts4_if_call_seq_u32_off0_884F4560 (XexGetProcedureAddress); E_FAIL when it cannot be resolved. */
/* Matched on /O1 (agAF). Plain C; the cache is re-read after the resolve; sibling 0x884F7D18 (ordinal 0x48C). */
typedef long (*Fn)(void *a, void *b);
extern Fn lbl_88D2704C;
extern int ts4_if_call_seq_u32_off0_884F4560(int ordinal, Fn *slot);
long fn_884F4630(void *a, void *b)
{
    if (!lbl_88D2704C)
        ts4_if_call_seq_u32_off0_884F4560(0x31a, &lbl_88D2704C);
    if (lbl_88D2704C)
        return lbl_88D2704C(a, b);
    return 0x80004005;
}
